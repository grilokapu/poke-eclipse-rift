#!/usr/bin/env python3
"""Small Tkinter editor for region map section names."""

from __future__ import annotations

import json
import sys
import tkinter as tk
from pathlib import Path
from tkinter import messagebox, ttk


PROJECT_ROOT = Path(__file__).resolve().parent.parent
DEFAULT_JSON_PATH = PROJECT_ROOT / "src/data/region_map/region_map_sections.json"


class RegionMapNameEditor(tk.Tk):
    def __init__(self, json_path: Path) -> None:
        super().__init__()
        self.json_path = json_path
        self.data = self._load_json()
        self.sections = self.data.get("map_sections")
        if not isinstance(self.sections, list):
            raise ValueError("O JSON não contém uma lista 'map_sections'.")

        self.current_index: int | None = None
        self.loading_fields = False
        self.dirty = False

        self.title("Nomes do mapa regional")
        self.resizable(False, False)
        self.protocol("WM_DELETE_WINDOW", self._on_close)

        self.section_var = tk.StringVar()
        self.name_var = tk.StringVar()
        self.name_es_var = tk.StringVar()
        self.name_pt_var = tk.StringVar()
        self.status_var = tk.StringVar(value=f"{len(self.sections)} mapas carregados")

        self._build_ui()
        self._refresh_combobox()
        self.bind("<Control-s>", lambda _event: self.save_json())

        for variable in (self.name_var, self.name_es_var, self.name_pt_var):
            variable.trace_add("write", self._mark_dirty)

        if self.sections:
            self.section_combo.current(0)
            self._select_section()

    def _load_json(self) -> dict:
        try:
            with self.json_path.open("r", encoding="utf-8") as source:
                return json.load(source)
        except (OSError, json.JSONDecodeError) as error:
            messagebox.showerror("Erro ao abrir JSON", str(error))
            raise

    def _build_ui(self) -> None:
        frame = ttk.Frame(self, padding=12)
        frame.grid(row=0, column=0, sticky="nsew")
        frame.columnconfigure(1, weight=1)

        ttk.Label(frame, text="Mapa:").grid(row=0, column=0, padx=(0, 8), pady=(0, 10), sticky="w")
        self.section_combo = ttk.Combobox(
            frame,
            textvariable=self.section_var,
            state="readonly",
            width=48,
        )
        self.section_combo.grid(row=0, column=1, pady=(0, 10), sticky="ew")
        self.section_combo.bind("<<ComboboxSelected>>", self._select_section)

        fields = (
            ("name (EN):", self.name_var),
            ("nameEs:", self.name_es_var),
            ("namePt:", self.name_pt_var),
        )
        for row, (label, variable) in enumerate(fields, start=1):
            ttk.Label(frame, text=label).grid(row=row, column=0, padx=(0, 8), pady=4, sticky="w")
            ttk.Entry(frame, textvariable=variable, width=42).grid(row=row, column=1, pady=4, sticky="ew")

        button_frame = ttk.Frame(frame)
        button_frame.grid(row=4, column=0, columnspan=2, pady=(12, 4), sticky="e")
        ttk.Button(button_frame, text="Aplicar", command=self.apply_fields).grid(row=0, column=0, padx=(0, 8))
        ttk.Button(button_frame, text="Salvar JSON", command=self.save_json).grid(row=0, column=1)

        ttk.Label(frame, textvariable=self.status_var).grid(
            row=5, column=0, columnspan=2, pady=(6, 0), sticky="w"
        )

    def _section_label(self, section: dict) -> str:
        section_id = section.get("id", "SEM_ID")
        name = section.get("name", "")
        return f"{section_id} — {name}" if name else section_id

    def _refresh_combobox(self) -> None:
        self.section_combo["values"] = [self._section_label(section) for section in self.sections]

    def _select_section(self, _event=None) -> None:
        new_index = self.section_combo.current()
        if new_index < 0:
            return

        has_unsaved_changes = self.dirty
        if self.current_index is not None and self.dirty:
            if not self.apply_fields(refresh_selection=False):
                self.section_combo.current(self.current_index)
                return
            has_unsaved_changes = True

        self.current_index = new_index
        section = self.sections[new_index]
        self.loading_fields = True
        self.name_var.set(section.get("name", ""))
        self.name_es_var.set(section.get("nameEs", ""))
        self.name_pt_var.set(section.get("namePt", ""))
        self.loading_fields = False
        self.dirty = has_unsaved_changes
        if self.dirty:
            self.status_var.set("Alterações ainda não salvas")
        else:
            self.status_var.set(section.get("id", "Mapa selecionado"))

    def _mark_dirty(self, *_args) -> None:
        if not self.loading_fields:
            self.dirty = True
            self.status_var.set("Alterações ainda não salvas")

    def apply_fields(self, refresh_selection: bool = True) -> bool:
        if self.current_index is None:
            return False

        name = self.name_var.get().strip()
        if not name:
            messagebox.showwarning("Nome obrigatório", "O campo 'name' não pode ficar vazio.")
            return False

        section = self.sections[self.current_index]
        section["name"] = name
        self._set_optional_name(section, "nameEs", self.name_es_var.get())
        self._set_optional_name(section, "namePt", self.name_pt_var.get())
        self.dirty = True

        if refresh_selection:
            self._refresh_combobox()
            self.section_combo.current(self.current_index)
        self.status_var.set("Alterações aplicadas; use 'Salvar JSON'")
        return True

    @staticmethod
    def _set_optional_name(section: dict, key: str, value: str) -> None:
        value = value.strip()
        if value:
            section[key] = value
        else:
            section.pop(key, None)

    def save_json(self) -> None:
        if not self.apply_fields():
            return

        temporary_path = self.json_path.with_suffix(self.json_path.suffix + ".tmp")
        try:
            with temporary_path.open("w", encoding="utf-8", newline="\n") as output:
                json.dump(self.data, output, ensure_ascii=False, indent=2)
                output.write("\n")
            temporary_path.replace(self.json_path)
        except OSError as error:
            messagebox.showerror("Erro ao salvar JSON", str(error))
            return

        self.dirty = False
        self.status_var.set(f"Salvo em {self.json_path}")

    def _on_close(self) -> None:
        if self.dirty and not messagebox.askyesno(
            "Alterações não salvas",
            "Existem alterações que ainda não foram salvas. Deseja fechar mesmo assim?",
        ):
            return
        self.destroy()


def main() -> int:
    json_path = Path(sys.argv[1]).expanduser().resolve() if len(sys.argv) > 1 else DEFAULT_JSON_PATH
    try:
        app = RegionMapNameEditor(json_path)
    except (OSError, ValueError, json.JSONDecodeError):
        return 1
    app.mainloop()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
