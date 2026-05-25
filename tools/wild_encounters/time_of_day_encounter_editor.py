#!/usr/bin/env python3
"""Tkinter editor for time-of-day wild encounter tables.

Run from the repository root with:
    python3 tools/wild_encounters/time_of_day_encounter_editor.py
"""

from __future__ import annotations

import copy
import json
import re
import shutil
from datetime import datetime
from pathlib import Path
import tkinter as tk
from tkinter import filedialog, messagebox, ttk


def project_root() -> Path:
    return Path(__file__).resolve().parents[2]


def parse_times_of_day(root: Path) -> list[str]:
    rtc_path = root / "include/constants/rtc.h"
    text = rtc_path.read_text(encoding="utf-8")
    match = re.search(r"enum\s+TimeOfDay\s*\{(?P<body>.*?)\}\s*;", text, re.S)
    if not match:
        return ["Morning", "Day", "Evening", "Night"]

    times: list[str] = []
    for ident in re.findall(r"\bTIME_[A-Z0-9_]+\b", match.group("body")):
        if ident == "TIMES_OF_DAY_COUNT":
            continue
        times.append(ident.removeprefix("TIME_").title().replace("_", ""))
    return times or ["Morning", "Day", "Evening", "Night"]


def load_species(root: Path) -> list[str]:
    path = root / "include/constants/species.h"
    if not path.exists():
        return []
    species: list[str] = []
    for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
        match = re.match(r"\s*#define\s+(SPECIES_[A-Z0-9_]+)\b", line)
        if match:
            species.append(match.group(1))
    return species


class EncounterEditor(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("Time of Day Wild Encounter Editor")
        self.geometry("1180x760")
        self.minsize(980, 620)

        self.root_dir = project_root()
        self.json_path = self.root_dir / "src/data/wild_encounters.json"
        self.times = parse_times_of_day(self.root_dir)
        self.species = load_species(self.root_dir)

        self.data: dict = self.read_json()
        self.group_index = tk.IntVar(value=0)
        self.selected_base = tk.StringVar()
        self.status = tk.StringVar(value="")
        self.current_tree: ttk.Treeview | None = None
        self.current_field: str | None = None
        self.widgets: dict[tuple[str, str], dict] = {}

        self._build_ui()
        self.populate_after_load()

    @property
    def group(self) -> dict:
        return self.data["wild_encounter_groups"][self.group_index.get()]

    def _build_ui(self) -> None:
        toolbar = ttk.Frame(self, padding=8)
        toolbar.pack(side=tk.TOP, fill=tk.X)

        ttk.Button(toolbar, text="Abrir JSON", command=self.open_json).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Recarregar", command=self.load_json).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Button(toolbar, text="Salvar", command=self.save_json).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Label(toolbar, text="Grupo:").pack(side=tk.LEFT, padx=(18, 4))
        self.group_combo = ttk.Combobox(toolbar, state="readonly", width=28)
        self.group_combo.pack(side=tk.LEFT)
        self.group_combo.bind("<<ComboboxSelected>>", self.on_group_changed)

        ttk.Label(toolbar, text="Mapa/Base:").pack(side=tk.LEFT, padx=(18, 4))
        self.base_combo = ttk.Combobox(toolbar, textvariable=self.selected_base, state="readonly", width=46)
        self.base_combo.pack(side=tk.LEFT, fill=tk.X, expand=True)
        self.base_combo.bind("<<ComboboxSelected>>", self.on_base_changed)

        body = ttk.PanedWindow(self, orient=tk.HORIZONTAL)
        body.pack(fill=tk.BOTH, expand=True, padx=8, pady=(0, 8))

        left = ttk.Frame(body, padding=(0, 0, 8, 0))
        body.add(left, weight=0)

        ttk.Label(left, text="Entradas do mapa").pack(anchor=tk.W)
        self.entry_list = tk.Listbox(left, width=42, exportselection=False)
        self.entry_list.pack(fill=tk.BOTH, expand=True, pady=(4, 8))
        self.entry_list.bind("<<ListboxSelect>>", self.on_entry_list_select)

        ttk.Button(left, text="Duplicar base para todos os horários", command=self.duplicate_all_times).pack(fill=tk.X)
        ttk.Button(left, text="Criar horário selecionado", command=self.create_current_time).pack(fill=tk.X, pady=(6, 0))
        ttk.Button(left, text="Remover horário selecionado", command=self.delete_current_time).pack(fill=tk.X, pady=(6, 0))

        right = ttk.Frame(body)
        body.add(right, weight=1)

        self.tabs = ttk.Notebook(right)
        self.tabs.pack(fill=tk.BOTH, expand=True)
        self.tabs.bind("<<NotebookTabChanged>>", lambda _event: self.refresh_current_tab())

        for time_name in self.times:
            frame = ttk.Frame(self.tabs, padding=8)
            self.tabs.add(frame, text=time_name)
            self._build_time_tab(frame, time_name)

        bottom = ttk.Frame(self, padding=(8, 0, 8, 8))
        bottom.pack(side=tk.BOTTOM, fill=tk.X)
        ttk.Label(bottom, textvariable=self.status).pack(anchor=tk.W)

    def _build_time_tab(self, parent: ttk.Frame, time_name: str) -> None:
        header = ttk.Frame(parent)
        header.pack(fill=tk.X)
        label = ttk.Label(header, text="")
        label.pack(side=tk.LEFT)
        ttk.Button(header, text="Copiar de...", command=self.copy_into_current_time).pack(side=tk.RIGHT)

        canvas = tk.Canvas(parent, highlightthickness=0)
        scrollbar = ttk.Scrollbar(parent, orient=tk.VERTICAL, command=canvas.yview)
        content = ttk.Frame(canvas)
        content.bind("<Configure>", lambda _event: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0, 0), window=content, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, pady=(8, 0))
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y, pady=(8, 0))

        self.widgets[(time_name, "_header")] = {"status": label}
        for field in self.fields_from_data():
            self._build_field_editor(content, time_name, field)

    def _build_field_editor(self, parent: ttk.Frame, time_name: str, field: dict) -> None:
        field_type = field["type"]
        frame = ttk.LabelFrame(parent, text=field_type, padding=8)
        frame.pack(fill=tk.X, expand=True, pady=(0, 10))

        top = ttk.Frame(frame)
        top.pack(fill=tk.X)
        enabled = tk.BooleanVar()
        rate = tk.StringVar()
        ttk.Checkbutton(top, text="Usar tabela", variable=enabled, command=self.apply_current_field).pack(side=tk.LEFT)
        ttk.Label(top, text="Encounter rate:").pack(side=tk.LEFT, padx=(16, 4))
        ttk.Entry(top, textvariable=rate, width=8).pack(side=tk.LEFT)
        ttk.Button(top, text="Aplicar rate", command=self.apply_current_field).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Button(top, text="Ajustar slots", command=lambda f=field_type: self.resize_field(f)).pack(side=tk.LEFT, padx=(6, 0))

        columns = ("slot", "min", "max", "species")
        tree = ttk.Treeview(frame, columns=columns, show="headings", height=min(12, max(4, len(field.get("encounter_rates", [])))))
        tree.heading("slot", text="Slot")
        tree.heading("min", text="Min")
        tree.heading("max", text="Max")
        tree.heading("species", text="Species")
        tree.column("slot", width=60, anchor=tk.CENTER, stretch=False)
        tree.column("min", width=70, anchor=tk.CENTER, stretch=False)
        tree.column("max", width=70, anchor=tk.CENTER, stretch=False)
        tree.column("species", width=280, stretch=True)
        tree.pack(fill=tk.X, expand=True, pady=(8, 6))
        tree.bind("<<TreeviewSelect>>", lambda _event, t=time_name, f=field_type: self.on_mon_select(t, f))
        tree.bind("<FocusIn>", lambda _event, f=field_type, tr=tree: self.set_current_field(f, tr))

        edit = ttk.Frame(frame)
        edit.pack(fill=tk.X)
        min_level = tk.StringVar(value="2")
        max_level = tk.StringVar(value="2")
        species = tk.StringVar(value="SPECIES_NONE")
        ttk.Label(edit, text="Min:").pack(side=tk.LEFT)
        ttk.Entry(edit, textvariable=min_level, width=6).pack(side=tk.LEFT, padx=(4, 10))
        ttk.Label(edit, text="Max:").pack(side=tk.LEFT)
        ttk.Entry(edit, textvariable=max_level, width=6).pack(side=tk.LEFT, padx=(4, 10))
        ttk.Label(edit, text="Species:").pack(side=tk.LEFT)
        species_combo = ttk.Combobox(edit, textvariable=species, values=self.species, width=34)
        species_combo.pack(side=tk.LEFT, padx=(4, 10), fill=tk.X, expand=True)
        ttk.Button(edit, text="Atualizar slot", command=lambda f=field_type: self.update_selected_mon(f)).pack(side=tk.LEFT)
        ttk.Button(edit, text="Adicionar slot", command=lambda f=field_type: self.add_mon(f)).pack(side=tk.LEFT, padx=(6, 0))
        ttk.Button(edit, text="Remover slot", command=lambda f=field_type: self.remove_selected_mon(f)).pack(side=tk.LEFT, padx=(6, 0))

        self.widgets[(time_name, field_type)] = {
            "enabled": enabled,
            "rate": rate,
            "tree": tree,
            "min": min_level,
            "max": max_level,
            "species": species,
            "expected": len(field.get("encounter_rates", [])),
        }

    def fields_from_data(self) -> list[dict]:
        if not self.data:
            return []
        groups = self.data.get("wild_encounter_groups", [])
        if not groups:
            return []
        return groups[self.group_index.get()].get("fields", [])

    def open_json(self) -> None:
        chosen = filedialog.askopenfilename(
            initialdir=self.root_dir / "src/data",
            title="Abrir wild_encounters.json",
            filetypes=[("JSON", "*.json"), ("Todos os arquivos", "*.*")],
        )
        if chosen:
            self.json_path = Path(chosen)
            self.load_json()

    def read_json(self) -> dict:
        with self.json_path.open(encoding="utf-8") as file:
            return json.load(file)

    def load_json(self) -> None:
        self.data = self.read_json()
        self.populate_after_load()

    def populate_after_load(self) -> None:
        group_labels = [
            f"{idx}: {group.get('label', '(sem label)')}"
            for idx, group in enumerate(self.data.get("wild_encounter_groups", []))
        ]
        self.group_combo["values"] = group_labels
        self.group_combo.current(min(self.group_index.get(), len(group_labels) - 1))
        self.refresh_bases()
        self.set_status(f"Carregado: {self.json_path}")

    def save_json(self) -> None:
        self.apply_current_field()
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        backup = self.json_path.with_suffix(self.json_path.suffix + f".tod_editor_{timestamp}.bak")
        shutil.copy2(self.json_path, backup)
        with self.json_path.open("w", encoding="utf-8") as file:
            json.dump(self.data, file, indent=2)
            file.write("\n")
        self.set_status(f"Salvo. Backup criado em {backup}")
        messagebox.showinfo("Salvo", f"wild_encounters.json salvo.\nBackup:\n{backup}")
        self.refresh_bases()

    def refresh_bases(self) -> None:
        bases = []
        for base_key, entries in self.base_entries().items():
            first = entries[0]
            bases.append(f"{first.get('map', '(sem map)')} | {base_key}")
        self.base_combo["values"] = bases
        if bases:
            if self.selected_base.get() not in bases:
                self.selected_base.set(bases[0])
            self.base_combo.set(self.selected_base.get())
        self.refresh_entry_list()
        self.refresh_current_tab()

    def base_entries(self) -> dict[str, list[dict]]:
        result: dict[str, list[dict]] = {}
        for entry in self.group.get("encounters", []):
            base_key, _time_name = self.split_label(entry.get("base_label", ""))
            result.setdefault(base_key, []).append(entry)
        return result

    def selected_base_key(self) -> str | None:
        value = self.selected_base.get()
        if " | " not in value:
            return None
        return value.split(" | ", 1)[1]

    def split_label(self, label: str) -> tuple[str, str | None]:
        for suffix in self.times:
            marker = "_" + suffix
            if label.endswith(marker):
                return label[: -len(marker)], suffix
        return label, self.times[0] if self.times else None

    def selected_time(self) -> str:
        return self.tabs.tab(self.tabs.select(), "text")

    def selected_entry(self, time_name: str | None = None) -> dict | None:
        base_key = self.selected_base_key()
        if not base_key:
            return None
        time_name = time_name or self.selected_time()
        for entry in self.base_entries().get(base_key, []):
            entry_base, entry_time = self.split_label(entry.get("base_label", ""))
            if entry_base == base_key and entry_time == time_name:
                return entry
        return None

    def on_group_changed(self, _event=None) -> None:
        self.group_index.set(self.group_combo.current())
        self.refresh_bases()

    def on_base_changed(self, _event=None) -> None:
        self.refresh_entry_list()
        self.refresh_current_tab()

    def refresh_entry_list(self) -> None:
        self.entry_list.delete(0, tk.END)
        base_key = self.selected_base_key()
        if not base_key:
            return
        for entry in self.base_entries().get(base_key, []):
            _base, time_name = self.split_label(entry.get("base_label", ""))
            self.entry_list.insert(tk.END, f"{time_name}: {entry.get('base_label')} ({entry.get('map', '')})")

    def on_entry_list_select(self, _event=None) -> None:
        selection = self.entry_list.curselection()
        if not selection:
            return
        text = self.entry_list.get(selection[0])
        time_name = text.split(":", 1)[0]
        if time_name in self.times:
            self.tabs.select(self.times.index(time_name))

    def refresh_current_tab(self) -> None:
        for time_name in self.times:
            entry = self.selected_entry(time_name)
            header = self.widgets.get((time_name, "_header"), {})
            label = header.get("status")
            if label:
                label.configure(text=self.entry_summary(entry, time_name))
            for field in self.fields_from_data():
                self.refresh_field(time_name, field["type"], entry)

    def entry_summary(self, entry: dict | None, time_name: str) -> str:
        if not entry:
            return f"{time_name}: sem entrada para este mapa. Use 'Criar horário selecionado'."
        return f"{time_name}: {entry.get('base_label')} em {entry.get('map', '(sem map)')}"

    def refresh_field(self, time_name: str, field_type: str, entry: dict | None) -> None:
        widgets = self.widgets.get((time_name, field_type))
        if not widgets:
            return
        tree: ttk.Treeview = widgets["tree"]
        tree.delete(*tree.get_children())
        table = entry.get(field_type) if entry else None
        widgets["enabled"].set(bool(table))
        widgets["rate"].set(str(table.get("encounter_rate", 0)) if table else "")
        mons = table.get("mons", []) if table else []
        for idx, mon in enumerate(mons):
            tree.insert("", tk.END, values=(idx, mon.get("min_level", 2), mon.get("max_level", 100), mon.get("species", "SPECIES_NONE")))

    def set_current_field(self, field_type: str, tree: ttk.Treeview) -> None:
        self.current_field = field_type
        self.current_tree = tree

    def current_widgets(self, field_type: str | None = None) -> dict | None:
        return self.widgets.get((self.selected_time(), field_type or self.current_field or ""))

    def ensure_current_entry(self) -> dict | None:
        entry = self.selected_entry()
        if entry:
            return entry
        self.create_current_time()
        return self.selected_entry()

    def apply_current_field(self) -> None:
        entry = self.selected_entry()
        if not entry:
            return
        for field in self.fields_from_data():
            field_type = field["type"]
            widgets = self.widgets.get((self.selected_time(), field_type))
            if not widgets:
                continue
            if not widgets["enabled"].get():
                entry.pop(field_type, None)
                continue
            table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
            table["encounter_rate"] = self.parse_int(widgets["rate"].get(), 0)

    def create_current_time(self) -> None:
        base_key = self.selected_base_key()
        if not base_key:
            return
        time_name = self.selected_time()
        if self.selected_entry(time_name):
            self.set_status(f"{time_name} ja existe para {base_key}.")
            return
        source = self.first_entry_for_base(base_key)
        if not source:
            return
        new_entry = copy.deepcopy(source)
        new_entry["base_label"] = base_key if time_name == self.times[0] else f"{base_key}_{time_name}"
        self.group["encounters"].append(new_entry)
        self.refresh_bases()
        self.set_status(f"Criado {new_entry['base_label']}.")

    def duplicate_all_times(self) -> None:
        base_key = self.selected_base_key()
        if not base_key:
            return
        source = self.first_entry_for_base(base_key)
        if not source:
            return
        existing = {self.split_label(entry.get("base_label", ""))[1] for entry in self.base_entries().get(base_key, [])}
        created = []
        for idx, time_name in enumerate(self.times):
            if time_name in existing:
                continue
            new_entry = copy.deepcopy(source)
            new_entry["base_label"] = base_key if idx == 0 else f"{base_key}_{time_name}"
            self.group["encounters"].append(new_entry)
            created.append(new_entry["base_label"])
        self.refresh_bases()
        self.set_status("Criados: " + ", ".join(created) if created else "Todos os horarios ja existiam.")

    def copy_into_current_time(self) -> None:
        entry = self.ensure_current_entry()
        base_key = self.selected_base_key()
        if not entry or not base_key:
            return
        options = [time for time in self.times if time != self.selected_time() and self.selected_entry(time)]
        if not options:
            messagebox.showinfo("Copiar", "Nao ha outro horario existente para copiar neste mapa.")
            return
        dialog = CopyDialog(self, options)
        self.wait_window(dialog)
        if not dialog.result:
            return
        source = self.selected_entry(dialog.result)
        keep_label = entry["base_label"]
        keep_map = entry.get("map")
        entry.clear()
        entry.update(copy.deepcopy(source))
        entry["base_label"] = keep_label
        if keep_map:
            entry["map"] = keep_map
        self.refresh_current_tab()
        self.set_status(f"{keep_label} recebeu os encontros de {dialog.result}.")

    def delete_current_time(self) -> None:
        entry = self.selected_entry()
        if not entry:
            return
        if not messagebox.askyesno("Remover", f"Remover {entry.get('base_label')}?"):
            return
        self.group["encounters"].remove(entry)
        self.refresh_bases()

    def first_entry_for_base(self, base_key: str) -> dict | None:
        entries = self.base_entries().get(base_key, [])
        return entries[0] if entries else None

    def on_mon_select(self, time_name: str, field_type: str) -> None:
        widgets = self.widgets[(time_name, field_type)]
        tree: ttk.Treeview = widgets["tree"]
        self.set_current_field(field_type, tree)
        selected = tree.selection()
        if not selected:
            return
        values = tree.item(selected[0], "values")
        widgets["min"].set(values[1])
        widgets["max"].set(values[2])
        widgets["species"].set(values[3])

    def update_selected_mon(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        tree: ttk.Treeview = widgets["tree"]
        selected = tree.selection()
        if not selected:
            messagebox.showinfo("Atualizar slot", "Selecione um slot primeiro.")
            return
        index = int(tree.item(selected[0], "values")[0])
        table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
        while len(table["mons"]) <= index:
            table["mons"].append(self.default_mon())
        table["mons"][index] = self.mon_from_widgets(widgets)
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()

    def add_mon(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        table = entry.setdefault(field_type, {"encounter_rate": 0, "mons": []})
        table["mons"].append(self.mon_from_widgets(widgets))
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()

    def remove_selected_mon(self, field_type: str) -> None:
        entry = self.selected_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets or field_type not in entry:
            return
        tree: ttk.Treeview = widgets["tree"]
        selected = tree.selection()
        if not selected:
            return
        index = int(tree.item(selected[0], "values")[0])
        mons = entry[field_type].setdefault("mons", [])
        if 0 <= index < len(mons):
            mons.pop(index)
        self.refresh_current_tab()

    def resize_field(self, field_type: str) -> None:
        entry = self.ensure_current_entry()
        widgets = self.current_widgets(field_type)
        if not entry or not widgets:
            return
        table = entry.setdefault(field_type, {"encounter_rate": self.parse_int(widgets["rate"].get(), 0), "mons": []})
        expected = widgets["expected"]
        while len(table["mons"]) < expected:
            table["mons"].append(self.default_mon())
        del table["mons"][expected:]
        widgets["enabled"].set(True)
        self.apply_current_field()
        self.refresh_current_tab()
        self.set_status(f"{field_type} ajustado para {expected} slots.")

    def mon_from_widgets(self, widgets: dict) -> dict:
        min_level = self.parse_int(widgets["min"].get(), 2)
        max_level = self.parse_int(widgets["max"].get(), min_level)
        if max_level < min_level:
            max_level = min_level
        species = widgets["species"].get().strip() or "SPECIES_NONE"
        if not species.startswith("SPECIES_"):
            species = "SPECIES_" + species.upper()
        return {"min_level": min_level, "max_level": max_level, "species": species}

    def default_mon(self) -> dict:
        return {"min_level": 2, "max_level": 2, "species": "SPECIES_NONE"}

    def parse_int(self, value: str, default: int) -> int:
        try:
            return int(value)
        except (TypeError, ValueError):
            return default

    def set_status(self, text: str) -> None:
        self.status.set(text)


class CopyDialog(tk.Toplevel):
    def __init__(self, parent: tk.Tk, options: list[str]) -> None:
        super().__init__(parent)
        self.title("Copiar encontros")
        self.resizable(False, False)
        self.result: str | None = None
        self.choice = tk.StringVar(value=options[0])
        self.transient(parent)
        self.grab_set()

        frame = ttk.Frame(self, padding=14)
        frame.pack(fill=tk.BOTH, expand=True)
        ttk.Label(frame, text="Copiar encontros de qual horario?").pack(anchor=tk.W)
        ttk.Combobox(frame, textvariable=self.choice, values=options, state="readonly", width=24).pack(fill=tk.X, pady=(8, 12))
        buttons = ttk.Frame(frame)
        buttons.pack(fill=tk.X)
        ttk.Button(buttons, text="Cancelar", command=self.destroy).pack(side=tk.RIGHT)
        ttk.Button(buttons, text="Copiar", command=self.accept).pack(side=tk.RIGHT, padx=(0, 8))

    def accept(self) -> None:
        self.result = self.choice.get()
        self.destroy()


if __name__ == "__main__":
    app = EncounterEditor()
    app.mainloop()
