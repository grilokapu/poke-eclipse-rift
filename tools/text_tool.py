#!/usr/bin/env python3
import re
import textwrap
import tkinter as tk
from pathlib import Path
from tkinter import messagebox, scrolledtext, ttk


ROOT_DIR = Path(__file__).resolve().parents[1]
EVENT_MACROS = ROOT_DIR / "asm" / "macros" / "event.inc"
PSS_ICONS = ROOT_DIR / "include" / "constants" / "pssicons.h"
LANGUAGES = ("PT", "EN", "ES")
DEFAULT_WIDTH = 34


def read_msgbox_types():
    try:
        text = EVENT_MACROS.read_text(encoding="utf-8")
    except OSError:
        return ["MSGBOX_DEFAULT"]

    return re.findall(r"^\s*(MSGBOX_[A-Z0-9_]+)\s*=", text, flags=re.MULTILINE) or ["MSGBOX_DEFAULT"]


def read_pss_icons():
    try:
        text = PSS_ICONS.read_text(encoding="utf-8")
    except OSError:
        return ["PSS_NONE"]

    match = re.search(r"enum\s+pssicons\s*\{(?P<body>.*?)\};", text, flags=re.DOTALL)
    if not match:
        return ["PSS_NONE"]

    icons = []
    for line in match.group("body").splitlines():
        line = line.split("//", 1)[0].strip().rstrip(",")
        if not line:
            continue
        icons.append(line.split("=", 1)[0].strip())
    return icons or ["PSS_NONE"]


def format_dialog_text(raw_text, width=DEFAULT_WIDTH):
    raw_text = raw_text.strip()
    if not raw_text:
        return ""

    raw_text = raw_text.replace("...", "…").replace("[.]", "…")
    paragraphs = re.split(r"\n\s*\n", raw_text)
    formatted_paragraphs = []

    for paragraph in paragraphs:
        source_lines = [line.strip() for line in paragraph.strip().splitlines() if line.strip()]
        if not source_lines:
            continue

        wrapped_lines = []
        for line in source_lines:
            if len(line) > width:
                wrapped_lines.extend(textwrap.wrap(line, width=width, break_long_words=False))
            else:
                wrapped_lines.append(line)

        if not wrapped_lines:
            continue

        formatted = wrapped_lines[0]
        for index, line in enumerate(wrapped_lines[1:], start=1):
            formatted += ("\\n" if index == 1 else "\\l") + line
        formatted_paragraphs.append(formatted)

    return "\\p".join(formatted_paragraphs)


def escape_pory_string(text):
    return text.replace('"', r"\"")


class PoryMultilangTextTool:
    def __init__(self, root):
        self.root = root
        self.root.title("Pory Multilang Text Tool")
        self.root.geometry("940x720")
        self.root.minsize(760, 560)

        self.message_kind = tk.StringVar(value="msgbox")
        self.msgbox_type = tk.StringVar(value="MSGBOX_DEFAULT")
        self.pss_icon = tk.StringVar(value="PSS_NONE")
        self.speaker_name = tk.StringVar()
        self.wrap_width = tk.IntVar(value=DEFAULT_WIDTH)

        self.text_boxes = {}
        self.build_ui()
        self.update_message_options()

    def build_ui(self):
        main = ttk.Frame(self.root, padding=8)
        main.pack(fill=tk.BOTH, expand=True)

        options = ttk.Frame(main)
        options.pack(fill=tk.X, pady=(0, 8))

        ttk.Label(options, text="Mensagem").grid(row=0, column=0, sticky="w")
        kind_box = ttk.Combobox(
            options,
            textvariable=self.message_kind,
            values=("msgbox", "msgminibox"),
            state="readonly",
            width=14,
        )
        kind_box.grid(row=1, column=0, sticky="ew", padx=(0, 8))
        kind_box.bind("<<ComboboxSelected>>", lambda _event: self.update_message_options())

        ttk.Label(options, text="Tipo").grid(row=0, column=1, sticky="w")
        ttk.Combobox(
            options,
            textvariable=self.msgbox_type,
            values=read_msgbox_types(),
            state="readonly",
            width=20,
        ).grid(row=1, column=1, sticky="ew", padx=(0, 8))

        self.icon_label = ttk.Label(options, text="PSS icon")
        self.icon_label.grid(row=0, column=2, sticky="w")
        self.icon_box = ttk.Combobox(
            options,
            textvariable=self.pss_icon,
            values=read_pss_icons(),
            state="readonly",
            width=22,
        )
        self.icon_box.grid(row=1, column=2, sticky="ew", padx=(0, 8))

        self.name_label = ttk.Label(options, text="Nome")
        self.name_label.grid(row=0, column=3, sticky="w")
        self.name_entry = ttk.Entry(options, textvariable=self.speaker_name, width=22)
        self.name_entry.grid(row=1, column=3, sticky="ew", padx=(0, 8))

        ttk.Label(options, text="Largura").grid(row=0, column=4, sticky="w")
        ttk.Spinbox(options, from_=20, to=60, textvariable=self.wrap_width, width=6).grid(
            row=1, column=4, sticky="w"
        )

        options.columnconfigure(1, weight=1)
        options.columnconfigure(2, weight=1)
        options.columnconfigure(3, weight=1)

        texts = ttk.Frame(main)
        texts.pack(fill=tk.BOTH, expand=True)
        for column, language in enumerate(LANGUAGES):
            frame = ttk.LabelFrame(texts, text=language, padding=5)
            frame.grid(row=0, column=column, sticky="nsew", padx=(0 if column == 0 else 4, 0))
            box = scrolledtext.ScrolledText(frame, wrap=tk.WORD, undo=True, height=14)
            box.pack(fill=tk.BOTH, expand=True)
            box.bind("<Control-a>", self.select_all)
            box.bind("<Control-A>", self.select_all)
            self.text_boxes[language] = box
            texts.columnconfigure(column, weight=1)
        texts.rowconfigure(0, weight=1)

        buttons = ttk.Frame(main)
        buttons.pack(fill=tk.X, pady=8)
        ttk.Button(buttons, text="Formatar textos", command=self.format_all_texts).pack(
            side=tk.LEFT, padx=(0, 4)
        )
        ttk.Button(buttons, text="Gerar switch", command=self.generate_output).pack(
            side=tk.LEFT, padx=(0, 4)
        )
        ttk.Button(buttons, text="Copiar resultado", command=self.copy_output).pack(
            side=tk.LEFT, padx=(0, 4)
        )
        ttk.Button(buttons, text="Colar no PT", command=lambda: self.paste_into("PT")).pack(
            side=tk.LEFT, padx=(0, 4)
        )
        ttk.Button(buttons, text="Limpar", command=self.clear_all).pack(side=tk.LEFT)

        output_frame = ttk.LabelFrame(main, text="Resultado PoryScript", padding=5)
        output_frame.pack(fill=tk.BOTH, expand=True)
        self.output = scrolledtext.ScrolledText(output_frame, wrap=tk.NONE, undo=True, height=12)
        self.output.pack(fill=tk.BOTH, expand=True)
        self.output.bind("<Control-a>", self.select_all)
        self.output.bind("<Control-A>", self.select_all)

    def update_message_options(self):
        is_minibox = self.message_kind.get() == "msgminibox"
        state = "readonly" if is_minibox else "disabled"
        entry_state = "normal" if is_minibox else "disabled"
        self.icon_box.configure(state=state)
        self.name_entry.configure(state=entry_state)

    def get_text(self, language):
        return self.text_boxes[language].get("1.0", tk.END).strip()

    def set_text(self, language, text):
        box = self.text_boxes[language]
        box.delete("1.0", tk.END)
        box.insert("1.0", text)

    def format_all_texts(self):
        width = self.wrap_width.get()
        for language in LANGUAGES:
            formatted = format_dialog_text(self.get_text(language), width)
            self.set_text(language, formatted)

    def build_call(self, text):
        msg_type = self.msgbox_type.get()
        escaped_text = escape_pory_string(text)
        type_arg = "" if msg_type == "MSGBOX_DEFAULT" else f", {msg_type}"

        if self.message_kind.get() == "msgbox":
            return f'msgbox("{escaped_text}"{type_arg})'

        name = self.speaker_name.get().strip()
        if not name:
            raise ValueError("Informe o nome para msgminibox.")
        return f'msgminibox({self.pss_icon.get()}, "{escape_pory_string(name)}", "{escaped_text}"{type_arg})'

    def generate_output(self):
        try:
            lines = ["switch(var(VAR_LANGUAGE)) {"]
            for language in LANGUAGES:
                text = self.get_text(language)
                if not text:
                    raise ValueError(f"O texto {language} está vazio.")
                lines.append(f"    case {language}: {self.build_call(text)}")
            lines.append("}")
        except ValueError as error:
            messagebox.showwarning("Aviso", str(error))
            return

        self.output.delete("1.0", tk.END)
        self.output.insert("1.0", "\n".join(lines))

    def copy_output(self):
        text = self.output.get("1.0", tk.END).strip()
        if not text:
            messagebox.showwarning("Aviso", "Nenhum resultado para copiar.")
            return
        self.root.clipboard_clear()
        self.root.clipboard_append(text)
        messagebox.showinfo("Sucesso", "Resultado copiado para a área de transferência.")

    def paste_into(self, language):
        try:
            text = self.root.clipboard_get()
        except tk.TclError:
            messagebox.showwarning("Aviso", "Nenhum texto na área de transferência.")
            return
        self.set_text(language, text)

    def clear_all(self):
        for language in LANGUAGES:
            self.set_text(language, "")
        self.output.delete("1.0", tk.END)

    @staticmethod
    def select_all(event):
        event.widget.tag_add(tk.SEL, "1.0", tk.END)
        event.widget.mark_set(tk.INSERT, "1.0")
        event.widget.see(tk.INSERT)
        return "break"


def main():
    root = tk.Tk()
    PoryMultilangTextTool(root)
    root.mainloop()


if __name__ == "__main__":
    main()
