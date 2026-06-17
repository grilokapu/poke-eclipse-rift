#!/usr/bin/env python3
from __future__ import annotations

import re
import shutil
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog, ttk


ROOT = Path(__file__).resolve().parents[1]
ITEMS_DATA = ROOT / "src/data/items.h"
ITEM_CONSTANTS = ROOT / "include/constants/items.h"
ITEM_GRAPHICS = ROOT / "src/data/graphics/items.h"
ICON_DIR = ROOT / "graphics/items/icons"
PALETTE_DIR = ROOT / "graphics/items/icon_palettes"

FIELD_ORDER = [
    "name",
    "nombre",
    "pluralName",
    "price",
    "description",
    "descricao",
    "descricion",
    "pocket",
    "sortType",
    "type",
    "fieldUseFunc",
    "battleUsage",
    "secondaryId",
    "effect",
    "holdEffect",
    "holdEffectParam",
    "importance",
    "notConsumed",
    "flingPower",
    "iconPic",
    "iconPalette",
]

MULTILINE_FIELDS = {"description", "descricao", "descricion"}
LOCALIZED_FIELDS = {"nombre", "descricao", "descricion"}


@dataclass
class ItemBlock:
    item_id: str
    body: str
    start: int
    end: int
    fields: dict[str, str] = field(default_factory=dict)

    @property
    def label(self) -> str:
        name = c_string_preview(self.fields.get("name", ""))
        if not name:
            name = self.item_id
        return f"{self.item_id} - {name}"


def backup(path: Path) -> None:
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    shutil.copy2(path, path.with_suffix(path.suffix + f".item_editor_{stamp}.bak"))


def match_brace(text: str, open_pos: int) -> int:
    depth = 0
    in_string = False
    in_char = False
    escaped = False
    for i in range(open_pos, len(text)):
        ch = text[i]
        if escaped:
            escaped = False
            continue
        if ch == "\\" and (in_string or in_char):
            escaped = True
            continue
        if ch == '"' and not in_char:
            in_string = not in_string
            continue
        if ch == "'" and not in_string:
            in_char = not in_char
            continue
        if in_string or in_char:
            continue
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
    raise ValueError("Could not match brace")


def split_field_assignments(body: str) -> dict[str, str]:
    fields: dict[str, str] = {}
    i = 0
    while i < len(body):
        m = re.search(r"\.([A-Za-z_][A-Za-z0-9_]*)\s*=", body[i:])
        if not m:
            break
        field_name = m.group(1)
        value_start = i + m.end()
        j = value_start
        paren = bracket = brace = 0
        in_string = False
        in_char = False
        escaped = False
        while j < len(body):
            ch = body[j]
            if escaped:
                escaped = False
                j += 1
                continue
            if ch == "\\" and (in_string or in_char):
                escaped = True
                j += 1
                continue
            if ch == '"' and not in_char:
                in_string = not in_string
                j += 1
                continue
            if ch == "'" and not in_string:
                in_char = not in_char
                j += 1
                continue
            if not in_string and not in_char:
                if ch == "(":
                    paren += 1
                elif ch == ")":
                    paren -= 1
                elif ch == "[":
                    bracket += 1
                elif ch == "]":
                    bracket -= 1
                elif ch == "{":
                    brace += 1
                elif ch == "}":
                    brace -= 1
                elif ch == "," and paren == bracket == brace == 0:
                    break
            j += 1
        fields[field_name] = body[value_start:j].strip()
        i = j + 1
    return fields


def find_array_bounds(text: str) -> tuple[int, int]:
    marker = "const struct ItemInfo gItemsInfo[]"
    marker_pos = text.index(marker)
    open_pos = text.index("{", marker_pos)
    close_pos = match_brace(text, open_pos)
    return open_pos, close_pos


def parse_items(text: str) -> list[ItemBlock]:
    open_pos, close_pos = find_array_bounds(text)
    items: list[ItemBlock] = []
    pos = open_pos + 1
    pattern = re.compile(r"\[\s*(ITEM_[A-Za-z0-9_]+)\s*\]\s*=\s*\{", re.M)
    while True:
        m = pattern.search(text, pos, close_pos)
        if not m:
            break
        body_open = m.end() - 1
        body_close = match_brace(text, body_open)
        block_end = body_close + 1
        if block_end < len(text) and text[block_end] == ",":
            block_end += 1
        body = text[body_open + 1:body_close]
        items.append(ItemBlock(m.group(1), body, m.start(), block_end, split_field_assignments(body)))
        pos = block_end
    return items


def c_string_preview(value: str) -> str:
    parts = re.findall(r'"((?:\\.|[^"\\])*)"', value)
    if not parts:
        return ""
    text = "".join(parts).replace("\\n", " ").replace("\\p", " ")
    return re.sub(r"\s+", " ", text).strip()


def to_item_name_expr(text: str) -> str:
    return f'ITEM_NAME("{escape_c(text)}")'


def to_desc_expr(text: str) -> str:
    lines = [line.rstrip() for line in text.splitlines()] or [""]
    if len(lines) == 1:
        return f'COMPOUND_STRING("{escape_c(lines[0])}")'
    quoted = "\n".join(f'            "{escape_c(line)}\\n"' for line in lines[:-1])
    quoted += f'\n            "{escape_c(lines[-1])}")'
    return "COMPOUND_STRING(\n" + quoted + ")"


def escape_c(text: str) -> str:
    return text.replace("\\", "\\\\").replace('"', '\\"')


def format_block(item_id: str, fields: dict[str, str]) -> str:
    output = [f"    [{item_id}] =\n", "    {\n"]
    written = set()
    for key in FIELD_ORDER:
        value = fields.get(key, "").strip()
        if not value:
            continue
        output.extend(format_field(key, value))
        written.add(key)
    for key in sorted(k for k in fields if k not in written and fields[k].strip()):
        output.extend(format_field(key, fields[key].strip()))
    output.append("    },")
    return "".join(output)


def format_field(key: str, value: str) -> list[str]:
    if "\n" in value:
        indented = "\n".join("        " + line if line.strip() else line for line in value.splitlines())
        return [f"        .{key} = {indented.lstrip()},\n"]
    return [f"        .{key} = {value},\n"]


def next_item_number(text: str) -> int:
    enum_text = text[: text.index("ITEMS_COUNT")]
    values = [int(v) for v in re.findall(r"ITEM_[A-Za-z0-9_]+\s*=\s*(\d+)", enum_text)]
    return max(values) + 1 if values else 1


def nice_symbol_from_item(item_id: str) -> str:
    words = item_id.removeprefix("ITEM_").lower().split("_")
    return "".join(word.capitalize() for word in words)


class ItemRepository:
    def __init__(self) -> None:
        self.text = ""
        self.items: list[ItemBlock] = []
        self.load()

    def load(self) -> None:
        self.text = ITEMS_DATA.read_text()
        self.items = parse_items(self.text)

    def save_item(self, item: ItemBlock, fields: dict[str, str]) -> None:
        new_block = format_block(item.item_id, fields)
        backup(ITEMS_DATA)
        self.text = self.text[: item.start] + new_block + self.text[item.end :]
        ITEMS_DATA.write_text(self.text)
        self.load()

    def add_item(self, item_id: str, display_name: str) -> None:
        item_id = item_id.strip().upper()
        if not item_id.startswith("ITEM_"):
            item_id = "ITEM_" + item_id
        if not re.fullmatch(r"ITEM_[A-Z0-9_]+", item_id):
            raise ValueError("Use an id like ITEM_MY_ITEM")
        if any(item.item_id == item_id for item in self.items):
            raise ValueError(f"{item_id} already exists")

        constants = ITEM_CONSTANTS.read_text()
        number = next_item_number(constants)
        enum_line = f"    {item_id} = {number},\n"
        backup(ITEM_CONSTANTS)
        ITEM_CONSTANTS.write_text(constants.replace("    ITEMS_COUNT,", enum_line + "\n    ITEMS_COUNT,", 1))

        symbol = nice_symbol_from_item(item_id)
        fields = {
            "name": to_item_name_expr(display_name or symbol),
            "price": "0",
            "description": "sQuestionMarksDesc",
            "pocket": "POCKET_ITEMS",
            "type": "ITEM_USE_BAG_MENU",
            "fieldUseFunc": "ItemUseOutOfBattle_CannotUse",
            "iconPic": "gItemIcon_QuestionMark",
            "iconPalette": "gItemIconPalette_QuestionMark",
        }
        block = "\n\n" + format_block(item_id, fields) + "\n"
        open_pos, close_pos = find_array_bounds(self.text)
        backup(ITEMS_DATA)
        self.text = self.text[:close_pos] + block + self.text[close_pos:]
        ITEMS_DATA.write_text(self.text)
        self.load()


class ItemEditor(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("Item Editor")
        self.geometry("1120x720")
        self.repo = ItemRepository()
        self.current: ItemBlock | None = None
        self.vars: dict[str, tk.Variable] = {}
        self.text_widgets: dict[str, tk.Text] = {}
        self.icon_symbols = self.load_graphic_symbols("gItemIcon_")
        self.palette_symbols = self.load_graphic_symbols("gItemIconPalette_")
        self.icon_paths = self.load_graphic_paths("gItemIcon_")
        self.preview_image: tk.PhotoImage | None = None
        self.build_ui()
        self.refresh_list()

    def load_graphic_symbols(self, prefix: str) -> list[str]:
        if not ITEM_GRAPHICS.exists():
            return []
        text = ITEM_GRAPHICS.read_text()
        symbols = sorted(set(re.findall(rf"\b({prefix}[A-Za-z0-9_]+)\s*\[\]", text)))
        return symbols

    def load_graphic_paths(self, prefix: str) -> dict[str, Path]:
        if not ITEM_GRAPHICS.exists():
            return {}
        text = ITEM_GRAPHICS.read_text()
        pattern = re.compile(
            rf"\b({prefix}[A-Za-z0-9_]+)\s*\[\]\s*=\s*INCBIN_U(?:16|32)\(\"([^\"]+)\"\);"
        )
        return {symbol: ROOT / path for symbol, path in pattern.findall(text)}

    def build_ui(self) -> None:
        main = ttk.PanedWindow(self, orient=tk.HORIZONTAL)
        main.pack(fill=tk.BOTH, expand=True, padx=8, pady=8)

        left = ttk.Frame(main, width=310)
        main.add(left, weight=1)
        self.search = tk.StringVar()
        search_entry = ttk.Entry(left, textvariable=self.search)
        search_entry.pack(fill=tk.X, pady=(0, 6))
        search_entry.bind("<KeyRelease>", lambda _event: self.refresh_list())
        self.listbox = tk.Listbox(left, exportselection=False)
        self.listbox.pack(fill=tk.BOTH, expand=True)
        self.listbox.bind("<<ListboxSelect>>", self.on_select)
        left_buttons = ttk.Frame(left)
        left_buttons.pack(fill=tk.X, pady=(6, 0))
        ttk.Button(left_buttons, text="Novo item", command=self.add_item).pack(side=tk.LEFT)
        ttk.Button(left_buttons, text="Recarregar", command=self.reload).pack(side=tk.LEFT, padx=6)

        right = ttk.Frame(main)
        main.add(right, weight=4)
        toolbar = ttk.Frame(right)
        toolbar.pack(fill=tk.X, pady=(0, 8))
        ttk.Button(toolbar, text="Salvar item", command=self.save_current).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Nome -> ITEM_NAME", command=self.wrap_name).pack(side=tk.LEFT, padx=6)
        ttk.Button(toolbar, text="Texto -> COMPOUND_STRING", command=self.wrap_description).pack(side=tk.LEFT)
        ttk.Button(toolbar, text="Importar icone", command=self.import_icon).pack(side=tk.RIGHT)
        ttk.Button(toolbar, text="Importar paleta", command=self.import_palette).pack(side=tk.RIGHT, padx=6)

        preview = ttk.Frame(right)
        preview.pack(fill=tk.X, pady=(0, 8))
        ttk.Label(preview, text="Preview").pack(side=tk.LEFT, padx=(0, 8))
        self.preview_label = ttk.Label(preview, anchor=tk.CENTER, width=14)
        self.preview_label.pack(side=tk.LEFT)
        self.preview_path_label = ttk.Label(preview)
        self.preview_path_label.pack(side=tk.LEFT, padx=8)

        canvas = tk.Canvas(right, highlightthickness=0)
        scrollbar = ttk.Scrollbar(right, orient=tk.VERTICAL, command=canvas.yview)
        self.form = ttk.Frame(canvas)
        self.form.bind("<Configure>", lambda _event: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0, 0), window=self.form, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        for row, key in enumerate(FIELD_ORDER):
            ttk.Label(self.form, text=key).grid(row=row, column=0, sticky="nw", padx=(0, 8), pady=3)
            if key in MULTILINE_FIELDS:
                widget = tk.Text(self.form, height=4, width=78, wrap=tk.WORD)
                widget.grid(row=row, column=1, sticky="ew", pady=3)
                self.text_widgets[key] = widget
            elif key == "iconPic":
                var = tk.StringVar()
                widget = ttk.Combobox(self.form, textvariable=var, values=self.icon_symbols)
                widget.grid(row=row, column=1, sticky="ew", pady=3)
                widget.bind("<<ComboboxSelected>>", lambda _event: self.update_icon_preview())
                widget.bind("<FocusOut>", lambda _event: self.update_icon_preview())
                self.vars[key] = var
            elif key == "iconPalette":
                var = tk.StringVar()
                widget = ttk.Combobox(self.form, textvariable=var, values=self.palette_symbols)
                widget.grid(row=row, column=1, sticky="ew", pady=3)
                self.vars[key] = var
            else:
                var = tk.StringVar()
                ttk.Entry(self.form, textvariable=var).grid(row=row, column=1, sticky="ew", pady=3)
                self.vars[key] = var
        self.form.columnconfigure(1, weight=1)

    def refresh_list(self) -> None:
        query = self.search.get().lower()
        self.visible_items = [
            item for item in self.repo.items
            if query in item.item_id.lower() or query in c_string_preview(item.fields.get("name", "")).lower()
        ]
        self.listbox.delete(0, tk.END)
        for item in self.visible_items:
            self.listbox.insert(tk.END, item.label)

    def reload(self) -> None:
        self.repo.load()
        self.refresh_list()
        messagebox.showinfo("Item Editor", "Arquivos recarregados.")

    def on_select(self, _event: object | None = None) -> None:
        selection = self.listbox.curselection()
        if not selection:
            return
        self.current = self.visible_items[selection[0]]
        for key in FIELD_ORDER:
            value = self.current.fields.get(key, "")
            if key in self.text_widgets:
                self.text_widgets[key].delete("1.0", tk.END)
                self.text_widgets[key].insert("1.0", value)
            else:
                self.vars[key].set(value)
        self.update_icon_preview()

    def get_preview_png_path(self, icon_symbol: str) -> Path | None:
        source = self.icon_paths.get(icon_symbol)
        if source is None:
            return None
        if source.suffix == ".png" and source.exists():
            return source
        candidates = []
        without_suffix = source
        while without_suffix.suffix:
            without_suffix = without_suffix.with_suffix("")
            candidates.append(without_suffix.with_suffix(".png"))
        for candidate in candidates:
            if candidate.exists():
                return candidate
        return None

    def update_icon_preview(self) -> None:
        icon_symbol = self.vars.get("iconPic").get().strip() if "iconPic" in self.vars else ""
        png_path = self.get_preview_png_path(icon_symbol)
        if png_path is None:
            self.preview_image = None
            self.preview_label.configure(image="", text="Sem PNG")
            self.preview_path_label.configure(text=icon_symbol)
            return
        try:
            image = tk.PhotoImage(file=str(png_path))
            scale = max(1, min(5, 96 // max(image.width(), image.height(), 1)))
            if scale > 1:
                image = image.zoom(scale, scale)
        except tk.TclError as exc:
            self.preview_image = None
            self.preview_label.configure(image="", text="Erro")
            self.preview_path_label.configure(text=str(exc))
            return
        self.preview_image = image
        self.preview_label.configure(image=self.preview_image, text="")
        self.preview_path_label.configure(text=png_path.relative_to(ROOT).as_posix())

    def gather_fields(self) -> dict[str, str]:
        if self.current is None:
            return {}
        fields = dict(self.current.fields)
        for key in FIELD_ORDER:
            if key in self.text_widgets:
                value = self.text_widgets[key].get("1.0", tk.END).strip()
            else:
                value = self.vars[key].get().strip()
            if value:
                fields[key] = value
            elif key in fields and (key in LOCALIZED_FIELDS or key in FIELD_ORDER):
                fields.pop(key)
        return fields

    def save_current(self) -> None:
        if self.current is None:
            messagebox.showwarning("Item Editor", "Selecione um item primeiro.")
            return
        try:
            self.repo.save_item(self.current, self.gather_fields())
        except Exception as exc:
            messagebox.showerror("Erro ao salvar", str(exc))
            return
        item_id = self.current.item_id
        self.refresh_list()
        for index, item in enumerate(self.visible_items):
            if item.item_id == item_id:
                self.listbox.selection_set(index)
                self.listbox.see(index)
                self.on_select()
                break
        messagebox.showinfo("Item Editor", "Item salvo. Um backup foi criado ao lado do arquivo.")

    def add_item(self) -> None:
        item_id = simpledialog.askstring("Novo item", "ID do item (ex: ITEM_DARK_ORB):", parent=self)
        if not item_id:
            return
        name = simpledialog.askstring("Novo item", "Nome em ingles:", parent=self) or ""
        try:
            self.repo.add_item(item_id, name)
        except Exception as exc:
            messagebox.showerror("Erro ao criar item", str(exc))
            return
        self.refresh_list()
        messagebox.showinfo("Item Editor", "Item criado em constants/items.h e data/items.h.")

    def wrap_name(self) -> None:
        raw = self.vars["name"].get().strip()
        if raw and not raw.startswith("ITEM_NAME("):
            self.vars["name"].set(to_item_name_expr(raw.strip('"')))

    def wrap_description(self) -> None:
        widget = self.focus_get()
        key = None
        for field_name, text_widget in self.text_widgets.items():
            if widget is text_widget:
                key = field_name
                break
        if key is None:
            key = "description"
        raw = self.text_widgets[key].get("1.0", tk.END).strip()
        if raw and not raw.startswith("COMPOUND_STRING(") and not raw.startswith("s"):
            self.text_widgets[key].delete("1.0", tk.END)
            self.text_widgets[key].insert("1.0", to_desc_expr(raw))

    def import_icon(self) -> None:
        path = filedialog.askopenfilename(
            parent=self,
            title="Escolha um icone .4bpp ou .4bpp.smol",
            filetypes=[("GBA icon data", "*.4bpp *.smol"), ("All files", "*.*")],
        )
        if path:
            self.import_graphic(Path(path), "icon")

    def import_palette(self) -> None:
        path = filedialog.askopenfilename(
            parent=self,
            title="Escolha uma paleta .gbapal ou .pal",
            filetypes=[("GBA palette", "*.gbapal *.pal"), ("All files", "*.*")],
        )
        if path:
            self.import_graphic(Path(path), "palette")

    def import_graphic(self, source: Path, kind: str) -> None:
        if self.current is None:
            messagebox.showwarning("Item Editor", "Selecione um item primeiro.")
            return
        symbol_base = simpledialog.askstring(
            "Nome do simbolo",
            "Sufixo do simbolo C:",
            initialvalue=nice_symbol_from_item(self.current.item_id),
            parent=self,
        )
        if not symbol_base:
            return
        symbol_base = re.sub(r"[^A-Za-z0-9_]", "", symbol_base)
        if not symbol_base:
            messagebox.showerror("Erro", "Simbolo invalido.")
            return
        target_dir = ICON_DIR if kind == "icon" else PALETTE_DIR
        target_dir.mkdir(parents=True, exist_ok=True)
        target = target_dir / source.name
        if source.resolve() != target.resolve():
            shutil.copy2(source, target)
        rel = target.relative_to(ROOT).as_posix()
        graphics = ITEM_GRAPHICS.read_text()
        backup(ITEM_GRAPHICS)
        if kind == "icon":
            symbol = "gItemIcon_" + symbol_base
            if symbol not in graphics:
                with ITEM_GRAPHICS.open("a") as handle:
                    handle.write(f'\nconst u32 {symbol}[] = INCBIN_U32("{rel}");\n')
            self.vars["iconPic"].set(symbol)
            self.icon_symbols = self.load_graphic_symbols("gItemIcon_")
            self.icon_paths = self.load_graphic_paths("gItemIcon_")
            self.update_icon_preview()
        else:
            symbol = "gItemIconPalette_" + symbol_base
            if symbol not in graphics:
                with ITEM_GRAPHICS.open("a") as handle:
                    handle.write(f'\nconst u16 {symbol}[] = INCBIN_U16("{rel}");\n')
            self.vars["iconPalette"].set(symbol)
            self.palette_symbols = self.load_graphic_symbols("gItemIconPalette_")
        messagebox.showinfo("Item Editor", "Grafico importado. Clique em Salvar item para gravar o item.")


if __name__ == "__main__":
    try:
        ItemEditor().mainloop()
    except Exception as exc:
        messagebox.showerror("Item Editor", str(exc))
