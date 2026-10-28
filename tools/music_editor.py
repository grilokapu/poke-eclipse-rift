#!/usr/bin/env python3
"""Editor visual da tabela de músicas do pokeemerald-expansion."""

from __future__ import annotations

import argparse
import datetime as dt
import os
import re
import shlex
import shutil
import subprocess
import sys
import threading
import tkinter as tk
from dataclasses import dataclass
from pathlib import Path
from tkinter import filedialog, messagebox, ttk


SONG_RE = re.compile(
    r"^(?P<indent>\s*)song\s+(?P<label>[A-Za-z_]\w*)\s*,\s*"
    r"(?P<player>[A-Za-z_]\w*|\d+)\s*,\s*(?P<flags>[^@\n]+?)"
    r"(?P<comment>\s*(?:@.*)?)$"
)
DEFINE_RE = re.compile(r"^\s*#define\s+((?:MUS|SE)_[A-Za-z0-9_]+)\s+([0-9]+)\b")
CFG_RE = re.compile(r"^(?P<prefix>\s*)(?P<file>[^:#]+\.mid)\s*:\s*(?P<flags>.*?)(?P<comment>\s+#.*)?$")


@dataclass
class Song:
    index: int
    line_index: int
    label: str
    player: str
    table_flags: str
    comment: str
    constant: str = ""
    cfg_flags: str = ""


class ProjectData:
    def __init__(self, root: Path):
        self.root = root.resolve()
        self.table_path = self.root / "sound/song_table.inc"
        self.constants_path = self.root / "include/constants/songs.h"
        self.cfg_path = self.root / "sound/songs/midi/midi.cfg"
        self.midi_dir = self.root / "sound/songs/midi"
        self.backup_dir = self.root / "tools/music_editor_backups"
        self.table_lines: list[str] = []
        self.cfg_lines: list[str] = []
        self.songs: list[Song] = []
        self.cfg_indices: dict[str, int] = {}
        self.load()

    def load(self) -> None:
        for path in (self.table_path, self.constants_path, self.cfg_path):
            if not path.is_file():
                raise FileNotFoundError(f"Arquivo obrigatório não encontrado: {path}")

        self.table_lines = self.table_path.read_text(encoding="utf-8").splitlines(keepends=True)
        constants: dict[int, str] = {}
        for line in self.constants_path.read_text(encoding="utf-8").splitlines():
            match = DEFINE_RE.match(line)
            if match:
                constants[int(match.group(2))] = match.group(1)

        self.cfg_lines = self.cfg_path.read_text(encoding="utf-8").splitlines(keepends=True)
        cfg: dict[str, str] = {}
        self.cfg_indices = {}
        for index, line in enumerate(self.cfg_lines):
            match = CFG_RE.match(line.rstrip("\n"))
            if match:
                name = match.group("file").strip()
                cfg[name] = match.group("flags").strip()
                self.cfg_indices[name] = index

        self.songs = []
        song_index = 0
        for line_index, line in enumerate(self.table_lines):
            match = SONG_RE.match(line.rstrip("\n"))
            if not match:
                continue
            label = match.group("label")
            filename = f"{label}.mid"
            self.songs.append(Song(
                index=song_index,
                line_index=line_index,
                label=label,
                player=match.group("player"),
                table_flags=match.group("flags").strip(),
                comment=match.group("comment") or "",
                constant=constants.get(song_index, ""),
                cfg_flags=cfg.get(filename, ""),
            ))
            song_index += 1

    def midi_path(self, song: Song) -> Path:
        return self.midi_dir / f"{song.label}.mid"

    def make_backup(self, paths: list[Path]) -> Path:
        stamp = dt.datetime.now().strftime("%Y%m%d-%H%M%S-%f")
        target = self.backup_dir / stamp
        target.mkdir(parents=True, exist_ok=False)
        for path in paths:
            if path.exists():
                relative = path.relative_to(self.root)
                destination = target / relative
                destination.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(path, destination)
        return target

    @staticmethod
    def atomic_write(path: Path, text: str) -> None:
        temporary = path.with_name(f".{path.name}.music-editor-{os.getpid()}.tmp")
        temporary.write_text(text, encoding="utf-8")
        os.replace(temporary, path)

    def save_song(self, song: Song, player: str, table_flags: str, cfg_flags: str) -> Path:
        if not re.fullmatch(r"[A-Za-z_]\w*|\d+", player):
            raise ValueError("Music player inválido.")
        if not table_flags or "\n" in table_flags:
            raise ValueError("As flags da tabela não podem ficar vazias.")
        try:
            shlex.split(cfg_flags)
        except ValueError as error:
            raise ValueError(f"Flags do mid2agb inválidas: {error}") from error

        backup = self.make_backup([self.table_path, self.cfg_path])
        newline = "\n" if self.table_lines[song.line_index].endswith("\n") else ""
        self.table_lines[song.line_index] = (
            f"\tsong {song.label}, {player}, {table_flags}{song.comment}{newline}"
        )

        filename = f"{song.label}.mid"
        cfg_line = f"{filename + ':':<34} {cfg_flags.rstrip()}\n"
        if filename in self.cfg_indices:
            self.cfg_lines[self.cfg_indices[filename]] = cfg_line
        else:
            if self.cfg_lines and not self.cfg_lines[-1].endswith("\n"):
                self.cfg_lines[-1] += "\n"
            self.cfg_indices[filename] = len(self.cfg_lines)
            self.cfg_lines.append(cfg_line)

        self.atomic_write(self.table_path, "".join(self.table_lines))
        self.atomic_write(self.cfg_path, "".join(self.cfg_lines))
        song.player = player
        song.table_flags = table_flags
        song.cfg_flags = cfg_flags.rstrip()
        return backup

    def replace_midi(self, song: Song, source: Path) -> tuple[Path, Path]:
        with source.open("rb") as stream:
            if stream.read(4) != b"MThd":
                raise ValueError("O arquivo escolhido não possui um cabeçalho MIDI válido (MThd).")
        destination = self.midi_path(song)
        backup = self.make_backup([destination])
        temporary = destination.with_name(f".{destination.name}.music-editor-{os.getpid()}.tmp")
        shutil.copy2(source, temporary)
        os.replace(temporary, destination)
        return destination, backup


class MusicEditor(tk.Tk):
    def __init__(self, data: ProjectData):
        super().__init__()
        self.data = data
        self.selected: Song | None = None
        self.player_process: subprocess.Popen | None = None
        self.title("Editor de BGM — Eclipse Rift")
        self.geometry("1180x720")
        self.minsize(920, 580)
        self.protocol("WM_DELETE_WINDOW", self.close)

        self.search_var = tk.StringVar()
        self.music_only_var = tk.BooleanVar(value=True)
        self.player_var = tk.StringVar()
        self.table_flags_var = tk.StringVar()
        self.cfg_flags_var = tk.StringVar()
        self.path_var = tk.StringVar()
        self.status_var = tk.StringVar(value=f"Projeto: {data.root}")
        self._build_ui()
        self.refresh_table()

    def _build_ui(self) -> None:
        toolbar = ttk.Frame(self, padding=8)
        toolbar.pack(fill="x")
        ttk.Label(toolbar, text="Buscar:").pack(side="left")
        search = ttk.Entry(toolbar, textvariable=self.search_var, width=32)
        search.pack(side="left", padx=(6, 14))
        self.search_var.trace_add("write", lambda *_: self.refresh_table())
        ttk.Checkbutton(
            toolbar, text="Somente músicas (mus_)", variable=self.music_only_var,
            command=self.refresh_table,
        ).pack(side="left")
        ttk.Button(toolbar, text="Recarregar arquivos", command=self.reload).pack(side="right")

        body = ttk.Panedwindow(self, orient="horizontal")
        body.pack(fill="both", expand=True, padx=8)
        left = ttk.Frame(body)
        right = ttk.Frame(body, padding=(12, 4))
        body.add(left, weight=3)
        body.add(right, weight=2)

        columns = ("id", "constant", "label", "player", "flags", "midi")
        self.tree = ttk.Treeview(left, columns=columns, show="headings", selectmode="browse")
        widths = {"id": 50, "constant": 155, "label": 180, "player": 130, "flags": 65, "midi": 55}
        titles = {"id": "ID", "constant": "Constante", "label": "Label", "player": "Player", "flags": "Flags", "midi": "MIDI"}
        for column in columns:
            self.tree.heading(column, text=titles[column])
            self.tree.column(column, width=widths[column], anchor="w", stretch=column in ("constant", "label"))
        scroll = ttk.Scrollbar(left, orient="vertical", command=self.tree.yview)
        self.tree.configure(yscrollcommand=scroll.set)
        self.tree.pack(side="left", fill="both", expand=True)
        scroll.pack(side="right", fill="y")
        self.tree.bind("<<TreeviewSelect>>", self.on_select)

        ttk.Label(right, text="Música selecionada", font=("TkDefaultFont", 11, "bold")).grid(row=0, column=0, columnspan=2, sticky="w", pady=(0, 10))
        ttk.Label(right, text="Arquivo MIDI:").grid(row=1, column=0, sticky="nw", pady=4)
        ttk.Entry(right, textvariable=self.path_var, state="readonly").grid(row=1, column=1, sticky="ew", pady=4)
        ttk.Label(right, text="Music player:").grid(row=2, column=0, sticky="w", pady=4)
        ttk.Combobox(right, textvariable=self.player_var, values=(
            "MUSIC_PLAYER_BGM", "MUSIC_PLAYER_SE1", "MUSIC_PLAYER_SE2", "MUSIC_PLAYER_SE3"
        )).grid(row=2, column=1, sticky="ew", pady=4)
        ttk.Label(right, text="Flags da tabela:").grid(row=3, column=0, sticky="w", pady=4)
        ttk.Entry(right, textvariable=self.table_flags_var).grid(row=3, column=1, sticky="ew", pady=4)
        ttk.Label(right, text="Flags do mid2agb:").grid(row=4, column=0, sticky="nw", pady=4)
        ttk.Entry(right, textvariable=self.cfg_flags_var).grid(row=4, column=1, sticky="ew", pady=4)
        help_text = "Ex.: -E -R0 -G_voicegroup -V127  |  Opções: -E -X -N -R -G -V -P"
        ttk.Label(right, text=help_text, foreground="#666").grid(row=5, column=0, columnspan=2, sticky="w", pady=(0, 12))

        playback = ttk.Frame(right)
        playback.grid(row=6, column=0, columnspan=2, sticky="ew", pady=4)
        ttk.Button(playback, text="▶ Reproduzir", command=self.play).pack(side="left")
        ttk.Button(playback, text="■ Parar", command=self.stop).pack(side="left", padx=6)
        ttk.Button(playback, text="Substituir MIDI…", command=self.replace).pack(side="left", padx=6)

        actions = ttk.Frame(right)
        actions.grid(row=7, column=0, columnspan=2, sticky="ew", pady=(12, 4))
        ttk.Button(actions, text="Salvar flags e player", command=self.save).pack(side="left")
        ttk.Button(actions, text="Compilar música", command=self.compile_selected).pack(side="left", padx=6)

        ttk.Label(right, text="Saída", font=("TkDefaultFont", 10, "bold")).grid(row=8, column=0, columnspan=2, sticky="w", pady=(16, 4))
        self.output = tk.Text(right, height=14, wrap="word", state="disabled")
        self.output.grid(row=9, column=0, columnspan=2, sticky="nsew")
        right.columnconfigure(1, weight=1)
        right.rowconfigure(9, weight=1)

        ttk.Label(self, textvariable=self.status_var, relief="sunken", anchor="w", padding=4).pack(fill="x", padx=8, pady=(4, 8))

    def refresh_table(self) -> None:
        query = self.search_var.get().casefold()
        selected_label = self.selected.label if self.selected else None
        self.tree.delete(*self.tree.get_children())
        for song in self.data.songs:
            if self.music_only_var.get() and not song.label.startswith("mus_"):
                continue
            haystack = f"{song.index} {song.constant} {song.label} {song.player}".casefold()
            if query and query not in haystack:
                continue
            midi = "sim" if self.data.midi_path(song).is_file() else "não"
            self.tree.insert("", "end", iid=str(song.index), values=(
                song.index, song.constant, song.label, song.player, song.table_flags, midi
            ))
        if selected_label:
            for item in self.tree.get_children():
                if self.data.songs[int(item)].label == selected_label:
                    self.tree.selection_set(item)
                    self.tree.see(item)
                    break

    def on_select(self, _event=None) -> None:
        selection = self.tree.selection()
        if not selection:
            return
        self.selected = self.data.songs[int(selection[0])]
        song = self.selected
        self.player_var.set(song.player)
        self.table_flags_var.set(song.table_flags)
        self.cfg_flags_var.set(song.cfg_flags)
        self.path_var.set(str(self.data.midi_path(song).relative_to(self.data.root)))
        self.status_var.set(f"ID {song.index} — {song.constant or song.label}")

    def require_selection(self) -> Song | None:
        if self.selected is None:
            messagebox.showinfo("Editor de BGM", "Escolha uma música na tabela primeiro.")
        return self.selected

    def log(self, message: str) -> None:
        self.output.configure(state="normal")
        self.output.insert("end", message.rstrip() + "\n")
        self.output.see("end")
        self.output.configure(state="disabled")

    def playback_command(self, midi: Path) -> list[str] | None:
        if shutil.which("timidity"):
            return ["timidity", str(midi)]
        if shutil.which("fluidsynth"):
            for soundfont in (Path("/usr/share/sounds/sf2/TimGM6mb.sf2"), Path("/usr/share/sounds/sf2/FluidR3_GM.sf2")):
                if soundfont.is_file():
                    return ["fluidsynth", "-i", str(soundfont), str(midi)]
        if shutil.which("aplaymidi"):
            return ["aplaymidi", str(midi)]
        if shutil.which("xdg-open"):
            return ["xdg-open", str(midi)]
        return None

    def play(self) -> None:
        song = self.require_selection()
        if not song:
            return
        midi = self.data.midi_path(song)
        if not midi.is_file():
            messagebox.showerror("Reprodução", f"MIDI não encontrado:\n{midi}")
            return
        command = self.playback_command(midi)
        if not command:
            messagebox.showerror("Reprodução", "Instale TiMidity++, FluidSynth ou aplaymidi para reproduzir.")
            return
        self.stop()
        try:
            self.player_process = subprocess.Popen(command, cwd=self.data.root)
            self.status_var.set(f"Reproduzindo {song.label}.mid")
        except OSError as error:
            messagebox.showerror("Reprodução", str(error))

    def stop(self) -> None:
        if self.player_process and self.player_process.poll() is None:
            self.player_process.terminate()
            try:
                self.player_process.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self.player_process.kill()
        self.player_process = None

    def replace(self) -> None:
        song = self.require_selection()
        if not song:
            return
        filename = filedialog.askopenfilename(title="Escolher novo MIDI", filetypes=(("Arquivos MIDI", "*.mid *.midi"), ("Todos", "*")))
        if not filename:
            return
        try:
            destination, backup = self.data.replace_midi(song, Path(filename))
        except (OSError, ValueError) as error:
            messagebox.showerror("Substituir MIDI", str(error))
            return
        self.refresh_table()
        self.log(f"MIDI substituído: {destination.relative_to(self.data.root)}\nBackup: {backup.relative_to(self.data.root)}")
        messagebox.showinfo("Substituir MIDI", "MIDI substituído com sucesso. O arquivo anterior foi salvo no backup.")

    def save(self) -> None:
        song = self.require_selection()
        if not song:
            return
        try:
            backup = self.data.save_song(song, self.player_var.get().strip(), self.table_flags_var.get().strip(), self.cfg_flags_var.get().strip())
        except (OSError, ValueError) as error:
            messagebox.showerror("Salvar", str(error))
            return
        self.refresh_table()
        self.log(f"Metadados salvos para {song.label}. Backup: {backup.relative_to(self.data.root)}")
        self.status_var.set(f"Alterações de {song.label} salvas")

    def compile_selected(self) -> None:
        song = self.require_selection()
        if not song:
            return
        midi = self.data.midi_path(song)
        if not midi.is_file():
            messagebox.showerror("Compilar", f"MIDI não encontrado: {midi}")
            return
        self.log(f"Compilando {song.label}…")
        self.status_var.set(f"Compilando {song.label}…")

        def worker() -> None:
            result = subprocess.run(
                ["make", f"sound/songs/midi/{song.label}.s"], cwd=self.data.root,
                text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
            )
            self.after(0, lambda: self._compile_done(song, result.returncode, result.stdout))

        threading.Thread(target=worker, daemon=True).start()

    def _compile_done(self, song: Song, returncode: int, output: str) -> None:
        self.log(output or "(sem saída)")
        if returncode == 0:
            self.status_var.set(f"{song.label} compilada com sucesso")
        else:
            self.status_var.set(f"Falha ao compilar {song.label} (código {returncode})")
            messagebox.showerror("Compilar", "A compilação falhou. Consulte a caixa de saída.")

    def reload(self) -> None:
        self.stop()
        try:
            self.data.load()
        except OSError as error:
            messagebox.showerror("Recarregar", str(error))
            return
        self.selected = None
        self.refresh_table()
        self.status_var.set(f"Arquivos recarregados — {len(self.data.songs)} entradas")

    def close(self) -> None:
        self.stop()
        self.destroy()


def find_project_root(explicit: str | None) -> Path:
    if explicit:
        return Path(explicit)
    candidate = Path(__file__).resolve().parent.parent
    if (candidate / "sound/song_table.inc").is_file():
        return candidate
    return Path.cwd()


def main() -> int:
    parser = argparse.ArgumentParser(description="Editor de músicas do pokeemerald-expansion")
    parser.add_argument("--root", help="diretório raiz do projeto")
    parser.add_argument("--check", action="store_true", help="valida os arquivos sem abrir a interface")
    args = parser.parse_args()
    try:
        data = ProjectData(find_project_root(args.root))
    except (OSError, ValueError) as error:
        print(f"Erro: {error}", file=sys.stderr)
        return 1
    if args.check:
        midi_count = sum(data.midi_path(song).is_file() for song in data.songs)
        cfg_count = sum(bool(song.cfg_flags) for song in data.songs)
        print(f"OK: {len(data.songs)} entradas, {midi_count} MIDIs, {cfg_count} configurações mid2agb")
        return 0
    app = MusicEditor(data)
    app.mainloop()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
