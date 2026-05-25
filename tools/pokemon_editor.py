#!/usr/bin/env python3
from __future__ import annotations

import re
import shutil
import subprocess
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog, ttk

try:
    from PIL import Image, ImageTk
except ImportError:
    Image = None
    ImageTk = None


ROOT = Path(__file__).resolve().parents[1]
SPECIES_CONSTANTS = ROOT / "include/constants/species.h"
POKEDEX_CONSTANTS = ROOT / "include/constants/pokedex.h"
SPECIES_INFO_MAIN = ROOT / "src/data/pokemon/species_info.h"
POKEMON_GRAPHICS = ROOT / "src/data/graphics/pokemon.h"
LEVEL_UP_GEN9 = ROOT / "src/data/pokemon/level_up_learnsets/gen_9.h"
FORM_SPECIES_TABLES = ROOT / "src/data/pokemon/form_species_tables.h"
FORM_CHANGE_TABLES = ROOT / "src/data/pokemon/form_change_tables.h"
DIRECT_SOUND_DATA = ROOT / "sound/direct_sound_data.inc"
CRIES_DIR = ROOT / "sound/direct_sound_samples/cries"
GRAPHICS_POKEMON = ROOT / "graphics/pokemon"
PREVIEW_BACKGROUND = ROOT / "tools/BattlePreviewBackground.png"
PREVIEW_SHADOW = ROOT / "tools/BattlePreviewShadow.png"

FIELD_ORDER = [
    "baseHP", "baseAttack", "baseDefense", "baseSpeed", "baseSpAttack", "baseSpDefense",
    "types", "catchRate", "expYield",
    "evYield_HP", "evYield_Attack", "evYield_Defense", "evYield_Speed", "evYield_SpAttack", "evYield_SpDefense",
    "itemCommon", "itemRare", "genderRatio", "eggCycles", "friendship", "growthRate", "eggGroups",
    "abilities", "bodyColor", "speciesName", "cryId", "natDexNum", "categoryName", "height", "weight",
    "description", "pokemonScale", "pokemonOffset", "trainerScale", "trainerOffset",
    "frontPic", "frontPicSize", "frontPicYOffset", "frontAnimFrames", "frontAnimId", "frontAnimDelay",
    "enemyMonElevation", "backPic", "backPicSize", "backPicYOffset", "backAnimId",
    "palette", "shinyPalette", "iconSprite", "iconPalIndex", "pokemonJumpType",
    "levelUpLearnset", "teachableLearnset", "eggMoveLearnset", "formSpeciesIdTable", "formChangeTable",
    "evolutions",
]

EDITABLE_FIELDS = [
    "speciesName", "baseHP", "baseAttack", "baseDefense", "baseSpeed", "baseSpAttack", "baseSpDefense",
    "types", "catchRate", "expYield",
    "evYield_HP", "evYield_Attack", "evYield_Defense", "evYield_Speed", "evYield_SpAttack", "evYield_SpDefense",
    "itemCommon", "itemRare", "genderRatio", "eggCycles", "friendship", "growthRate", "eggGroups",
    "abilities", "bodyColor", "cryId", "natDexNum", "categoryName", "height", "weight", "description",
    "pokemonScale", "pokemonOffset", "trainerScale", "trainerOffset",
    "frontPicSize", "frontPicYOffset", "frontAnimId", "frontAnimDelay", "enemyMonElevation",
    "backPicSize", "backPicYOffset", "backAnimId", "iconPalIndex", "levelUpLearnset", "teachableLearnset",
]

DEFAULT_FIELDS = {
    "baseHP": "1",
    "baseAttack": "1",
    "baseDefense": "1",
    "baseSpeed": "1",
    "baseSpAttack": "1",
    "baseSpDefense": "1",
    "types": "MON_TYPES(TYPE_NORMAL)",
    "catchRate": "255",
    "expYield": "67",
    "genderRatio": "PERCENT_FEMALE(50)",
    "eggCycles": "20",
    "friendship": "STANDARD_FRIENDSHIP",
    "growthRate": "GROWTH_MEDIUM_FAST",
    "eggGroups": "MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED)",
    "abilities": "{ ABILITY_NONE, ABILITY_NONE, ABILITY_NONE }",
    "bodyColor": "BODY_COLOR_BLACK",
    "cryId": "CRY_NONE",
    "categoryName": "_(\"Unknown\")",
    "height": "0",
    "weight": "0",
    "description": 'COMPOUND_STRING(\n            "This is a newly discovered Pokemon.\\n"\n            "It is currently under investigation.")',
    "pokemonScale": "256",
    "pokemonOffset": "0",
    "trainerScale": "256",
    "trainerOffset": "0",
    "frontPicSize": "MON_COORDS_SIZE(64, 64)",
    "frontPicYOffset": "0",
    "frontAnimFrames": "ANIM_FRAMES(\n            ANIMCMD_FRAME(0, 1),\n        )",
    "frontAnimId": "ANIM_V_SQUISH_AND_BOUNCE",
    "frontAnimDelay": "0",
    "enemyMonElevation": "0",
    "backPicSize": "MON_COORDS_SIZE(64, 64)",
    "backPicYOffset": "0",
    "backAnimId": "BACK_ANIM_NONE",
    "iconPalIndex": "0",
    "levelUpLearnset": "sNoneLevelUpLearnset",
    "teachableLearnset": "sNoneTeachableLearnset",
}

BASE_STAT_FIELDS = ["baseHP", "baseAttack", "baseDefense", "baseSpeed", "baseSpAttack", "baseSpDefense"]
EV_FIELDS = ["evYield_HP", "evYield_Attack", "evYield_Defense", "evYield_Speed", "evYield_SpAttack", "evYield_SpDefense"]
NUMERIC_FIELDS = set(BASE_STAT_FIELDS + EV_FIELDS + [
    "catchRate", "expYield", "eggCycles", "friendship", "height", "weight",
    "pokemonScale", "pokemonOffset", "trainerScale", "trainerOffset",
    "frontPicYOffset", "frontAnimDelay", "enemyMonElevation", "backPicYOffset", "iconPalIndex",
])

def parse_int(value):
    try:
        return int(str(value).strip(), 0)
    except (TypeError, ValueError):
        return None


def load_simple_defines() -> dict[str, int]:
    defines: dict[str, int] = {}
    paths = [
        ROOT / "include/config/general.h",
        ROOT / "include/config/pokemon.h",
        ROOT / "include/config/battle.h",
        ROOT / "include/constants/pokemon.h",
    ]
    raw_defines: dict[str, str] = {}
    for path in paths:
        if not path.exists():
            continue
        for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
            line = line.split("//", 1)[0].strip()
            match = re.match(r"#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+(.+)$", line)
            if not match:
                continue
            name, raw = match.groups()
            raw = raw.strip()
            raw_defines[name] = raw
            if raw == "TRUE":
                defines[name] = 1
            elif raw == "FALSE":
                defines[name] = 0
            elif raw in defines:
                defines[name] = defines[raw]
            else:
                value = parse_int(raw)
                if value is not None:
                    defines[name] = value
    changed = True
    while changed:
        changed = False
        for name, raw in raw_defines.items():
            if name in defines:
                continue
            resolved = resolve_numeric_define_expr(raw, defines)
            if resolved is not None:
                defines[name] = resolved
                changed = True
    return defines


def resolve_numeric_define_expr(raw: str, defines: dict[str, int]) -> int | None:
    value = raw.strip()
    while value.startswith("(") and value.endswith(")"):
        close = match_wrapped_parens(value)
        if close == len(value) - 1:
            value = value[1:-1].strip()
        else:
            break
    if value == "TRUE":
        return 1
    if value == "FALSE":
        return 0
    if value in defines:
        return defines[value]
    direct = parse_int(value)
    if direct is not None:
        return direct
    ternary = split_top_level_ternary(value)
    if ternary:
        condition, true_value, false_value = ternary
        result = evaluate_condition_with_defines(condition, defines)
        if result is None:
            return None
        return resolve_numeric_define_expr(true_value if result else false_value, defines)
    return None


def evaluate_condition_with_defines(condition: str, defines: dict[str, int]) -> bool | None:
    condition = condition.strip().strip("()")
    if re.match(r"^([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)$", condition):
        value = defines.get(condition, parse_int(condition))
        return None if value is None else bool(value)
    match = re.match(r"^([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)\s*(>=|<=|==|!=|>|<)\s*([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)$", condition)
    if not match:
        return None
    left_raw, op, right_raw = match.groups()
    left = defines.get(left_raw, parse_int(left_raw))
    right = defines.get(right_raw, parse_int(right_raw))
    if left is None or right is None:
        return None
    return {
        ">=": left >= right,
        "<=": left <= right,
        "==": left == right,
        "!=": left != right,
        ">": left > right,
        "<": left < right,
    }[op]


def evaluate_config_condition(condition: str) -> bool | None:
    condition = condition.strip().strip("()")
    if re.match(r"^([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)$", condition):
        value = CONFIG_DEFINES.get(condition, parse_int(condition))
        return None if value is None else bool(value)
    match = re.match(r"^([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)\s*(>=|<=|==|!=|>|<)\s*([A-Za-z_][A-Za-z0-9_]*|-?\d+|0x[0-9A-Fa-f]+)$", condition)
    if not match:
        return None
    left_raw, op, right_raw = match.groups()
    left = CONFIG_DEFINES.get(left_raw, parse_int(left_raw))
    right = CONFIG_DEFINES.get(right_raw, parse_int(right_raw))
    if left is None or right is None:
        return None
    if op == ">=":
        return left >= right
    if op == "<=":
        return left <= right
    if op == "==":
        return left == right
    if op == "!=":
        return left != right
    if op == ">":
        return left > right
    if op == "<":
        return left < right
    return None


def split_top_level_ternary(value: str) -> tuple[str, str, str] | None:
    text = value.strip()
    if text.startswith("("):
        close = match_wrapped_parens(text)
        if close is not None:
            condition = text[1:close]
            rest = text[close + 1:].strip()
            if rest.startswith("?"):
                parts = split_top_level_colon(rest[1:].strip())
                if parts:
                    return condition, parts[0], parts[1]
    question = find_top_level_char(text, "?")
    if question < 0:
        return None
    parts = split_top_level_colon(text[question + 1:].strip())
    if not parts:
        return None
    return text[:question].strip(), parts[0], parts[1]


def match_wrapped_parens(text: str) -> int | None:
    depth = 0
    for idx, ch in enumerate(text):
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
            if depth == 0:
                return idx
    return None


def find_top_level_char(text: str, target: str) -> int:
    paren = brace = bracket = 0
    in_string = in_char = escaped = False
    for idx, ch in enumerate(text):
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
        if ch == "(":
            paren += 1
        elif ch == ")":
            paren -= 1
        elif ch == "{":
            brace += 1
        elif ch == "}":
            brace -= 1
        elif ch == "[":
            bracket += 1
        elif ch == "]":
            bracket -= 1
        elif ch == target and paren == brace == bracket == 0:
            return idx
    return -1


def split_top_level_colon(text: str) -> tuple[str, str] | None:
    idx = find_top_level_char(text, ":")
    if idx < 0:
        return None
    return text[:idx].strip(), text[idx + 1:].strip()


CONFIG_DEFINES = load_simple_defines()


def effective_value(raw: str) -> str:
    value = str(raw).strip()
    if value in LOCAL_DEFINES:
        value = LOCAL_DEFINES[value]
    for _ in range(8):
        if value.startswith("("):
            close = match_wrapped_parens(value)
            if close == len(value) - 1:
                value = value[1:-1].strip()
        ternary = split_top_level_ternary(value)
        if not ternary:
            break
        condition, true_value, false_value = ternary
        result = evaluate_config_condition(condition)
        if result is None:
            break
        value = true_value if result else false_value
    if value in CONFIG_DEFINES:
        return str(CONFIG_DEFINES[value])
    if value in LOCAL_DEFINES and LOCAL_DEFINES[value] != value:
        return effective_value(LOCAL_DEFINES[value])
    return value


def preprocess_config_lines(text: str) -> str:
    output: list[str] = []
    stack: list[dict[str, bool]] = []

    def is_active() -> bool:
        return all(frame["active"] for frame in stack)

    for line in text.splitlines(keepends=True):
        stripped = line.strip()
        if stripped.startswith("#if "):
            cond = stripped[4:].strip()
            evaluated = evaluate_config_condition(cond)
            result = True if evaluated is None else bool(evaluated)
            stack.append({"parent": is_active(), "active": is_active() and result, "taken": result})
            continue
        if stripped.startswith("#elif ") and stack:
            frame = stack[-1]
            if frame["taken"]:
                frame["active"] = False
            else:
                evaluated = evaluate_config_condition(stripped[6:].strip())
                result = True if evaluated is None else bool(evaluated)
                frame["active"] = frame["parent"] and result
                frame["taken"] = result
            continue
        if stripped.startswith("#else") and stack:
            frame = stack[-1]
            frame["active"] = frame["parent"] and not frame["taken"]
            frame["taken"] = True
            continue
        if stripped.startswith("#endif") and stack:
            stack.pop()
            continue
        if is_active():
            output.append(line)
    return "".join(output)


def load_local_defines() -> dict[str, str]:
    defines: dict[str, str] = {}
    for path in species_info_files_unexpanded():
        if not path.exists():
            continue
        active_text = preprocess_config_lines(path.read_text(encoding="utf-8", errors="ignore"))
        for line in active_text.splitlines():
            line = line.split("//", 1)[0].strip()
            match = re.match(r"#define\s+([A-Z][A-Z0-9_]+)\s+(.+)$", line)
            if not match:
                continue
            name, value = match.groups()
            if "(" in name:
                continue
            defines[name] = value.strip()
    return defines


def species_info_files_unexpanded() -> list[Path]:
    files = [SPECIES_INFO_MAIN]
    if SPECIES_INFO_MAIN.exists():
        text = SPECIES_INFO_MAIN.read_text(encoding="utf-8", errors="ignore")
        for rel in re.findall(r'#include\s+"(species_info/[^"]+)"', text):
            files.append(SPECIES_INFO_MAIN.parent / rel)
    return files


LOCAL_DEFINES = load_local_defines()


@dataclass
class SpeciesBlock:
    species: str
    path: Path
    start: int
    end: int
    body: str
    fields: dict[str, str] = field(default_factory=dict)
    macros: list[str] = field(default_factory=list)

    @property
    def label(self) -> str:
        name = c_string_preview(self.fields.get("speciesName", ""))
        return f"{self.species} - {name or symbol_to_title(self.species, 'SPECIES_')}"


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="ignore")


def write_text(path: Path, text: str) -> None:
    backup(path)
    path.write_text(text, encoding="utf-8", newline="")


def backup(path: Path) -> None:
    if not path.exists():
        return
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    target = path.with_suffix(path.suffix + f".pokemon_editor_{stamp}.bak")
    if not target.exists():
        shutil.copy2(path, target)


def match_brace(text: str, open_pos: int) -> int:
    depth = 0
    in_string = False
    in_char = False
    escaped = False
    for idx in range(open_pos, len(text)):
        ch = text[idx]
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
                return idx
    raise ValueError("Nao foi possivel encontrar a chave de fechamento.")


def split_field_assignments(body: str) -> dict[str, str]:
    fields: dict[str, str] = {}
    pos = 0
    while True:
        m = re.search(r"\.([A-Za-z_][A-Za-z0-9_]*)\s*=", body[pos:])
        if not m:
            return fields
        key = m.group(1)
        start = pos + m.end()
        idx = start
        paren = bracket = brace = 0
        in_string = in_char = escaped = False
        while idx < len(body):
            ch = body[idx]
            if escaped:
                escaped = False
            elif ch == "\\" and (in_string or in_char):
                escaped = True
            elif ch == '"' and not in_char:
                in_string = not in_string
            elif ch == "'" and not in_string:
                in_char = not in_char
            elif not in_string and not in_char:
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
            idx += 1
        fields[key] = body[start:idx].strip()
        pos = idx + 1


def parse_species_blocks(path: Path) -> list[SpeciesBlock]:
    if not path.exists():
        return []
    text = read_text(path)
    blocks: list[SpeciesBlock] = []
    pos = 0
    pattern = re.compile(r"\[\s*(SPECIES_[A-Z0-9_]+)\s*\]\s*=\s*\{", re.M)
    while True:
        m = pattern.search(text, pos)
        if not m:
            break
        open_pos = m.end() - 1
        close_pos = match_brace(text, open_pos)
        end = close_pos + 1
        if end < len(text) and text[end] == ",":
            end += 1
        body = text[open_pos + 1:close_pos]
        active_body = preprocess_config_lines(body)
        macros = re.findall(r"^\s*(FOOTPRINT\([^)]+\)|SHADOW\([^)]+\)|NO_SHADOW)\s*$", active_body, re.M)
        blocks.append(SpeciesBlock(m.group(1), path, m.start(), end, body, split_field_assignments(active_body), macros))
        pos = end
    return blocks


def species_info_files() -> list[Path]:
    files = [SPECIES_INFO_MAIN]
    text = read_text(SPECIES_INFO_MAIN)
    for rel in re.findall(r'#include\s+"(species_info/[^"]+)"', text):
        files.append(SPECIES_INFO_MAIN.parent / rel)
    return files


def load_species_blocks() -> dict[str, SpeciesBlock]:
    blocks: dict[str, SpeciesBlock] = {}
    for path in species_info_files():
        for block in parse_species_blocks(path):
            blocks.setdefault(block.species, block)
    return blocks


def c_string_preview(expr: str) -> str:
    parts = re.findall(r'"((?:\\.|[^"\\])*)"', expr or "")
    return re.sub(r"\s+", " ", "".join(parts).replace("\\n", " ")).strip()


def escape_c(text: str) -> str:
    return text.replace("\\", "\\\\").replace('"', '\\"')


def normalize_species_name(text: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9]+", "_", text.strip()).strip("_").upper()
    if not cleaned:
        raise ValueError("Nome vazio.")
    return cleaned if cleaned.startswith("SPECIES_") else f"SPECIES_{cleaned}"


def symbol_to_title(symbol: str, prefix: str) -> str:
    return symbol.replace(prefix, "").replace("_", " ").title().replace(" ", "")


def symbol_to_folder(symbol: str) -> str:
    return symbol.replace("SPECIES_", "").lower()


def species_graphic_name(species: str) -> str:
    return symbol_to_title(species, "SPECIES_")


def natdex_for_species(species: str) -> str:
    return "NATIONAL_DEX_" + species.replace("SPECIES_", "")


def parse_symbol_names(path: Path, prefix: str) -> list[str]:
    if not path.exists():
        return []
    seen: set[str] = set()
    out: list[str] = []
    for m in re.finditer(rf"\b({re.escape(prefix)}[A-Z0-9_]+)\b", read_text(path)):
        value = m.group(1)
        if value not in seen:
            seen.add(value)
            out.append(value)
    return out


TYPE_OPTIONS = parse_symbol_names(ROOT / "include/constants/pokemon.h", "TYPE_")
ITEM_OPTIONS = parse_symbol_names(ROOT / "include/constants/items.h", "ITEM_")
ABILITY_OPTIONS = parse_symbol_names(ROOT / "include/constants/abilities.h", "ABILITY_")
MOVE_OPTIONS = [move for move in parse_symbol_names(ROOT / "include/constants/moves.h", "MOVE_") if not move.endswith("_COUNT")]
BODY_COLOR_OPTIONS = parse_symbol_names(ROOT / "include/constants/pokemon.h", "BODY_COLOR_")
EVO_METHOD_OPTIONS = parse_symbol_names(ROOT / "include/constants/pokemon.h", "EVO_")
GROWTH_OPTIONS = [
    "GROWTH_MEDIUM_FAST", "GROWTH_ERRATIC", "GROWTH_FLUCTUATING",
    "GROWTH_MEDIUM_SLOW", "GROWTH_FAST", "GROWTH_SLOW",
]


def parse_enum_options(path: Path, enum_name: str, skip_suffixes=()) -> list[str]:
    if not path.exists():
        return []
    text = path.read_text(encoding="utf-8", errors="ignore")
    match = re.search(rf"enum\s+{re.escape(enum_name)}\s*\{{(.*?)\}};", text, re.S)
    if not match:
        return []
    options = []
    for line in match.group(1).splitlines():
        line = line.split("//", 1)[0].strip().rstrip(",")
        if not line:
            continue
        name = re.split(r"\s*=", line, 1)[0].strip()
        if name and not any(name.endswith(suffix) for suffix in skip_suffixes):
            options.append(name)
    return options


EVOLUTION_CONDITION_OPTIONS = [""] + parse_enum_options(ROOT / "include/constants/pokemon.h", "EvolutionConditions", skip_suffixes=("END",))
FORM_CHANGE_TYPE_OPTIONS = parse_enum_options(ROOT / "include/constants/form_change_types.h", "FormChanges", skip_suffixes=("TERMINATOR",))


def species_constant_order() -> list[str]:
    if not SPECIES_CONSTANTS.exists():
        return []
    ordered: list[str] = []
    seen: set[str] = set()
    for line in SPECIES_CONSTANTS.read_text(encoding="utf-8", errors="ignore").splitlines():
        match = re.match(r"\s*#define\s+(SPECIES_[A-Z0-9_]+)\b", line)
        if not match:
            continue
        species = match.group(1)
        if species in {"SPECIES_SHINY_TAG"} or species in seen:
            continue
        seen.add(species)
        ordered.append(species)
    return ordered


def split_top_level_commas(text: str) -> list[str]:
    parts: list[str] = []
    start = 0
    paren = brace = bracket = 0
    in_string = in_char = escaped = False
    for idx, ch in enumerate(text):
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
        if ch == "(":
            paren += 1
        elif ch == ")":
            paren -= 1
        elif ch == "{":
            brace += 1
        elif ch == "}":
            brace -= 1
        elif ch == "[":
            bracket += 1
        elif ch == "]":
            bracket -= 1
        elif ch == "," and paren == brace == bracket == 0:
            parts.append(text[start:idx].strip())
            start = idx + 1
    tail = text[start:].strip()
    if tail:
        parts.append(tail)
    return parts


def parse_evolution_entries(raw: str) -> list[dict[str, str]]:
    value = raw.strip()
    if not value.startswith("EVOLUTION("):
        return []
    open_pos = value.find("(")
    close_pos = match_wrapped_parens(value[open_pos:])
    if close_pos is None:
        return []
    inner = value[open_pos + 1:open_pos + close_pos]
    entries = []
    for item in split_top_level_commas(inner):
        item = item.strip()
        if not item.startswith("{") or not item.endswith("}"):
            continue
        fields = split_top_level_commas(item[1:-1])
        if len(fields) < 3:
            continue
        extra = ", ".join(fields[3:])
        condition = ""
        condition_param = ""
        cond_match = re.match(r"^CONDITIONS\(\s*\{\s*(IF_[A-Z0-9_]+)\s*(?:,\s*(.*?))?\s*\}\s*\)\s*$", extra)
        if cond_match:
            condition = cond_match.group(1)
            condition_param = (cond_match.group(2) or "").strip()
        entries.append({
            "method": fields[0],
            "param": fields[1],
            "target": fields[2],
            "condition": condition,
            "condition_param": condition_param,
            "extra": "" if cond_match else extra,
        })
    return entries


def format_evolution_entries(entries: list[dict[str, str]]) -> str:
    cleaned = []
    for entry in entries:
        method = entry.get("method", "").strip()
        param = entry.get("param", "").strip()
        target = entry.get("target", "").strip()
        condition = entry.get("condition", "").strip()
        condition_param = entry.get("condition_param", "").strip()
        extra = entry.get("extra", "").strip()
        if not method or not param or not target:
            continue
        body = f"{method}, {param}, {target}"
        if condition:
            cond_body = condition
            if condition_param:
                cond_body += f", {condition_param}"
            body += f", CONDITIONS({{{cond_body}}})"
        if extra:
            body += f", {extra}"
        cleaned.append("{" + body + "}")
    if not cleaned:
        return ""
    if len(cleaned) == 1:
        return f"EVOLUTION({cleaned[0]})"
    return "EVOLUTION(\n            " + ",\n            ".join(cleaned) + "\n        )"
EGG_GROUP_OPTIONS = [
    "EGG_GROUP_MONSTER", "EGG_GROUP_WATER_1", "EGG_GROUP_BUG", "EGG_GROUP_FLYING",
    "EGG_GROUP_FIELD", "EGG_GROUP_FAIRY", "EGG_GROUP_GRASS", "EGG_GROUP_HUMAN_LIKE",
    "EGG_GROUP_WATER_3", "EGG_GROUP_MINERAL", "EGG_GROUP_AMORPHOUS", "EGG_GROUP_WATER_2",
    "EGG_GROUP_DITTO", "EGG_GROUP_DRAGON", "EGG_GROUP_NO_EGGS_DISCOVERED",
]


def format_field(key: str, value: str) -> list[str]:
    if "\n" not in value:
        return [f"        .{key} = {value},\n"]
    lines = value.splitlines()
    out = [f"        .{key} = {lines[0]}\n"]
    for line in lines[1:-1]:
        out.append(f"        {line}\n")
    out.append(f"        {lines[-1]},\n")
    return out


def format_species_block(species: str, fields: dict[str, str], macros: list[str] | None = None) -> str:
    out = [f"    [{species}] =\n", "    {\n"]
    written = set()
    for key in FIELD_ORDER:
        value = fields.get(key, "").strip()
        if not value:
            continue
        out.extend(format_field(key, value))
        written.add(key)
    for key in sorted(k for k in fields if k not in written and fields[k].strip()):
        out.extend(format_field(key, fields[key].strip()))
    for macro in macros or []:
        out.append(f"        {macro}\n")
    out.append("    },")
    return "".join(out)


def replace_block(block: SpeciesBlock, new_block: str) -> None:
    text = read_text(block.path)
    write_text(block.path, text[:block.start] + new_block + text[block.end:])


def insert_custom_species_block(species: str, fields: dict[str, str], macros: list[str]) -> None:
    text = read_text(SPECIES_INFO_MAIN)
    marker = "\n};\n\nconst struct EggData"
    idx = text.find(marker)
    if idx < 0:
        raise RuntimeError("Nao encontrei o fim de gSpeciesInfo em species_info.h.")
    block = "\n\n" + format_species_block(species, fields, macros) + "\n"
    write_text(SPECIES_INFO_MAIN, text[:idx] + block + text[idx:])


def add_species_constant(species: str) -> None:
    text = read_text(SPECIES_CONSTANTS)
    if re.search(rf"\b{re.escape(species)}\b", text):
        return
    nums = [int(m.group(2), 0) for m in re.finditer(r"^\s*#define\s+(SPECIES_[A-Z0-9_]+)\s+(\d+|0x[0-9A-Fa-f]+)\b", text, re.M)]
    next_value = max(nums) + 1
    line = f"#define {species:<48} {next_value}\n"
    egg = re.search(r"^#define\s+SPECIES_EGG\s+\(.+\)\s*$", text, re.M)
    if not egg:
        raise RuntimeError("Nao encontrei SPECIES_EGG em species.h.")
    text = text[:egg.start()] + line + text[egg.start():egg.end()] + f"\n#define SPECIES_EGG                                     ({species} + 1)" + text[egg.end():]
    text = re.sub(r"\n#define SPECIES_EGG\s+\([^)]+\)\n#define SPECIES_EGG\s+\([^)]+\)", f"\n#define SPECIES_EGG                                     ({species} + 1)", text)
    write_text(SPECIES_CONSTANTS, text)


def add_pokedex_constant(dex: str) -> None:
    text = read_text(POKEDEX_CONSTANTS)
    if re.search(rf"\b{re.escape(dex)}\b", text):
        return
    end = text.find("};", text.find("enum NationalDexOrder"))
    if end < 0:
        raise RuntimeError("Nao encontrei enum NationalDexOrder.")
    text = text[:end] + f"    {dex},\n" + text[end:]
    text = re.sub(r"#define NATIONAL_DEX_COUNT\s+NATIONAL_DEX_[A-Z0-9_]+", f"#define NATIONAL_DEX_COUNT  {dex}", text, count=1)
    write_text(POKEDEX_CONSTANTS, text)


def ensure_graphics_constants(species: str) -> None:
    name = species_graphic_name(species)
    folder = symbol_to_folder(species)
    if re.search(rf"\bgMonFrontPic_{re.escape(name)}\b", read_text(POKEMON_GRAPHICS)):
        return
    block = f"""
const u32 gMonFrontPic_{name}[] = INCBIN_U32("graphics/pokemon/{folder}/anim_front.4bpp.smol");
const u32 gMonBackPic_{name}[] = INCBIN_U32("graphics/pokemon/{folder}/back.4bpp.smol");
const u16 gMonPalette_{name}[] = INCBIN_U16("graphics/pokemon/{folder}/normal.gbapal");
const u16 gMonShinyPalette_{name}[] = INCBIN_U16("graphics/pokemon/{folder}/shiny.gbapal");
const u8 gMonIcon_{name}[] = INCBIN_U8("graphics/pokemon/{folder}/icon.4bpp");
#if P_FOOTPRINTS
const u8 gMonFootprint_{name}[] = INCBIN_U8("graphics/pokemon/{folder}/footprint.1bpp");
#endif //P_FOOTPRINTS
"""
    text = read_text(POKEMON_GRAPHICS)
    egg_pos = text.find("const u32 gMonFrontPic_Egg[]")
    if egg_pos < 0:
        write_text(POKEMON_GRAPHICS, text + "\n" + block)
    else:
        write_text(POKEMON_GRAPHICS, text[:egg_pos] + block + "\n" + text[egg_pos:])


def add_level_up_learnset(species: str) -> str:
    array = "s" + species_graphic_name(species) + "LevelUpLearnset"
    text = read_text(LEVEL_UP_GEN9)
    if re.search(rf"\b{re.escape(array)}\b", text):
        return array
    block = f"""
static const struct LevelUpMove {array}[] = {{
    LEVEL_UP_MOVE( 1, MOVE_POUND),
    LEVEL_UP_END
}};
"""
    write_text(LEVEL_UP_GEN9, text.rstrip() + "\n" + block)
    return array


def new_species_fields(species: str, display_name: str) -> tuple[dict[str, str], list[str]]:
    name = species_graphic_name(species)
    fields = dict(DEFAULT_FIELDS)
    fields["speciesName"] = f'_(\"{escape_c(display_name)}\")'
    fields["natDexNum"] = natdex_for_species(species)
    fields["frontPic"] = f"gMonFrontPic_{name}"
    fields["backPic"] = f"gMonBackPic_{name}"
    fields["palette"] = f"gMonPalette_{name}"
    fields["shinyPalette"] = f"gMonShinyPalette_{name}"
    fields["iconSprite"] = f"gMonIcon_{name}"
    fields["levelUpLearnset"] = add_level_up_learnset(species)
    return fields, [f"FOOTPRINT({name})", "SHADOW(0, 0, SHADOW_SIZE_M)"]


def ensure_graphics_folder(species: str, source_dir: Path | None = None) -> Path:
    target = GRAPHICS_POKEMON / symbol_to_folder(species)
    if target.exists():
        return target
    if source_dir and source_dir.exists():
        shutil.copytree(source_dir, target)
    else:
        shutil.copytree(GRAPHICS_POKEMON / "question_mark" / "circled", target)
        src_icon = GRAPHICS_POKEMON / "question_mark" / "icon.png"
        if src_icon.exists():
            shutil.copy2(src_icon, target / "icon.png")
        fp = GRAPHICS_POKEMON / "question_mark" / "footprint.png"
        if fp.exists():
            shutil.copy2(fp, target / "footprint.png")
    return target


def import_sprite_sheet(species: str, sheet_path: Path) -> Path:
    if Image is None:
        raise RuntimeError("Pillow nao esta instalado; importacao de sprite sheet indisponivel.")
    image = Image.open(sheet_path)
    if image.width < 192 or image.height < 64:
        raise ValueError("A sheet precisa ter ao menos 192x64: front, shiny e back em blocos 64x64.")
    target = ensure_graphics_folder(species)
    image.crop((0, 0, 64, 64)).save(target / "anim_front.png")
    image.crop((128, 0, 192, 64)).save(target / "back.png")
    if image.width >= 128:
        make_palettes_from_frames(image.crop((0, 0, 64, 64)), image.crop((64, 0, 128, 64)), target)
    return target


def make_palettes_from_frames(normal, shiny, target: Path) -> None:
    normal_colors = normal.convert("RGBA").getcolors(4096) or []
    shiny_colors = shiny.convert("RGBA").getcolors(4096) or []
    write_jasc_palette(target / "normal.pal", [rgba for _n, rgba in normal_colors[:16]])
    write_jasc_palette(target / "shiny.pal", [rgba for _n, rgba in shiny_colors[:16]])


def write_jasc_palette(path: Path, colors) -> None:
    rows = ["JASC-PAL\n", "0100\n", "16\n"]
    cleaned = list(colors)[:16]
    while len(cleaned) < 16:
        cleaned.append((0, 0, 0, 255))
    for r, g, b, *_ in cleaned:
        rows.append(f"{r} {g} {b}\n")
    path.write_text("".join(rows), encoding="ascii")


def load_preview_rgba(path: Path, box=None, transparent_index=0):
    image = Image.open(path)
    if box is not None:
        image = image.crop(box)
    if image.mode == "P":
        index_image = image.copy()
        rgba = image.convert("RGBA")
        if transparent_index is not None:
            alpha = Image.new("L", index_image.size)
            alpha.putdata([0 if index == transparent_index else 255 for index in index_image.getdata()])
            rgba.putalpha(alpha)
        return rgba
    return image.convert("RGBA")


def pad_to_size(image, size=(64, 64)):
    if image.size == size:
        return image
    padded = Image.new("RGBA", size, (0, 0, 0, 0))
    padded.alpha_composite(image.crop((0, 0, min(size[0], image.width), min(size[1], image.height))), (0, 0))
    return padded


def cry_id_to_label(cry_id: str) -> str:
    raw = cry_id.strip().replace("CRY_", "")
    return "Cry_" + raw.title().replace("_", "")


def direct_sound_cry_paths() -> dict[str, Path]:
    mapping: dict[str, Path] = {}
    if not DIRECT_SOUND_DATA.exists():
        return mapping
    text = DIRECT_SOUND_DATA.read_text(encoding="utf-8", errors="ignore")
    pattern = re.compile(r"^\s*(Cry_[A-Za-z0-9_]+)::\s*\n\s*\.incbin\s+\"([^\"]+)\"", re.M)
    for label, rel in pattern.findall(text):
        bin_path = ROOT / rel
        wav_path = bin_path.with_suffix(".wav")
        mapping[label] = wav_path if wav_path.exists() else bin_path
    return mapping


def cry_wav_path(cry_id: str) -> Path | None:
    if not cry_id or cry_id == "CRY_NONE":
        return None
    label = cry_id_to_label(cry_id)
    mapped = direct_sound_cry_paths().get(label)
    if mapped and mapped.exists():
        return mapped
    stem = cry_id.replace("CRY_", "").lower()
    for suffix in [".wav", ".bin", ".aif"]:
        candidate = CRIES_DIR / f"{stem}{suffix}"
        if candidate.exists():
            return candidate
    return None


def play_audio(path: Path) -> None:
    if not path or not path.exists():
        raise FileNotFoundError("Arquivo de cry nao encontrado.")
    if path.suffix.lower() != ".wav":
        raise RuntimeError(f"Encontrei {path.name}, mas nao um .wav tocavel.")
    players = [
        ["paplay", str(path)],
        ["aplay", str(path)],
        ["ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet", str(path)],
    ]
    for command in players:
        if shutil.which(command[0]):
            subprocess.Popen(command)
            return
    raise RuntimeError("Nenhum player encontrado (paplay, aplay ou ffplay).")


def parse_level_up_learnset(array_name: str) -> list[tuple[int, str]]:
    if not array_name or not LEVEL_UP_GEN9.exists():
        return []
    text = LEVEL_UP_GEN9.read_text(encoding="utf-8", errors="ignore")
    match = re.search(rf"static\s+const\s+struct\s+LevelUpMove\s+{re.escape(array_name)}\[\]\s*=\s*\{{", text)
    if not match:
        return []
    start = match.end() - 1
    end = match_brace(text, start)
    body = text[start + 1:end]
    entries = []
    for level, move in re.findall(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)", body):
        entries.append((int(level), move))
    return entries


def replace_level_up_learnset(array_name: str, entries: list[tuple[int, str]]) -> None:
    if not array_name:
        return
    text = LEVEL_UP_GEN9.read_text(encoding="utf-8", errors="ignore")
    match = re.search(rf"static\s+const\s+struct\s+LevelUpMove\s+{re.escape(array_name)}\[\]\s*=\s*\{{", text)
    if not match:
        raise RuntimeError(f"Learnset {array_name} nao encontrado em {LEVEL_UP_GEN9.relative_to(ROOT)}.")
    start = match.start()
    open_brace = match.end() - 1
    close_brace = match_brace(text, open_brace)
    end = close_brace + 1
    if end < len(text) and text[end] == ";":
        end += 1
    lines = [f"static const struct LevelUpMove {array_name}[] = {{\n"]
    for level, move in entries:
        lines.append(f"    LEVEL_UP_MOVE({int(level):2d}, {move}),\n")
    lines.append("    LEVEL_UP_END\n};")
    write_text(LEVEL_UP_GEN9, text[:start] + "".join(lines) + text[end:])


def parse_form_species_table(table_name: str) -> list[str]:
    if not table_name or not FORM_SPECIES_TABLES.exists():
        return []
    text = FORM_SPECIES_TABLES.read_text(encoding="utf-8", errors="ignore")
    match = re.search(rf"static\s+const\s+u16\s+{re.escape(table_name)}\[\]\s*=\s*\{{", text)
    if not match:
        return []
    start = match.end() - 1
    end = match_brace(text, start)
    body = preprocess_config_lines(text[start + 1:end])
    forms = []
    for species in re.findall(r"\b(SPECIES_[A-Z0-9_]+)\b\s*,", body):
        forms.append(species)
    return forms


def replace_form_species_table(table_name: str, forms: list[str]) -> None:
    if not table_name:
        return
    text = FORM_SPECIES_TABLES.read_text(encoding="utf-8", errors="ignore") if FORM_SPECIES_TABLES.exists() else ""
    block_lines = [f"static const u16 {table_name}[] = {{\n"]
    for species in forms:
        block_lines.append(f"    {species},\n")
    block_lines.append("    FORM_SPECIES_END,\n};")
    block = "".join(block_lines)
    match = re.search(rf"static\s+const\s+u16\s+{re.escape(table_name)}\[\]\s*=\s*\{{", text)
    if match:
        start = match.start()
        open_brace = match.end() - 1
        close_brace = match_brace(text, open_brace)
        end = close_brace + 1
        if end < len(text) and text[end] == ";":
            end += 1
        write_text(FORM_SPECIES_TABLES, text[:start] + block + text[end:])
        return
    insertion = ("\n\n" if text and not text.endswith("\n\n") else "") + block + "\n"
    write_text(FORM_SPECIES_TABLES, text.rstrip() + insertion)


def default_form_table_name(species: str) -> str:
    return "s" + species_graphic_name(species) + "FormSpeciesIdTable"


def parse_form_change_table(table_name: str) -> list[dict[str, str]]:
    if not table_name or not FORM_CHANGE_TABLES.exists():
        return []
    text = FORM_CHANGE_TABLES.read_text(encoding="utf-8", errors="ignore")
    match = re.search(rf"static\s+const\s+struct\s+FormChange\s+{re.escape(table_name)}\[\]\s*=\s*\{{", text)
    if not match:
        return []
    start = match.end() - 1
    end = match_brace(text, start)
    body = preprocess_config_lines(text[start + 1:end])
    entries = []
    for item in re.findall(r"\{([^{}]+)\}\s*,", body):
        parts = split_top_level_commas(item)
        if not parts or parts[0] == "FORM_CHANGE_TERMINATOR":
            continue
        entries.append({
            "type": parts[0],
            "target": parts[1] if len(parts) > 1 else "",
            "arg1": parts[2] if len(parts) > 2 else "",
            "arg2": parts[3] if len(parts) > 3 else "",
            "arg3": parts[4] if len(parts) > 4 else "",
        })
    return entries


def replace_form_change_table(table_name: str, entries: list[dict[str, str]]) -> None:
    if not table_name:
        return
    text = FORM_CHANGE_TABLES.read_text(encoding="utf-8", errors="ignore") if FORM_CHANGE_TABLES.exists() else ""
    lines = [f"static const struct FormChange {table_name}[] =\n{{\n"]
    for entry in entries:
        parts = [entry.get("type", "").strip()]
        for key in ["target", "arg1", "arg2", "arg3"]:
            value = entry.get(key, "").strip()
            if value:
                parts.append(value)
        if parts[0]:
            lines.append("    {" + ", ".join(parts) + "},\n")
    lines.append("    {FORM_CHANGE_TERMINATOR},\n};")
    block = "".join(lines)
    match = re.search(rf"static\s+const\s+struct\s+FormChange\s+{re.escape(table_name)}\[\]\s*=\s*\{{", text)
    if match:
        start = match.start()
        open_brace = match.end() - 1
        close_brace = match_brace(text, open_brace)
        end = close_brace + 1
        if end < len(text) and text[end] == ";":
            end += 1
        write_text(FORM_CHANGE_TABLES, text[:start] + block + text[end:])
        return
    insertion = ("\n\n" if text and not text.endswith("\n\n") else "") + block + "\n"
    write_text(FORM_CHANGE_TABLES, text.rstrip() + insertion)


def default_form_change_table_name(species: str) -> str:
    return "s" + species_graphic_name(species) + "FormChangeTable"


class ScrollableFrame(ttk.Frame):
    def __init__(self, parent):
        super().__init__(parent)
        self.canvas = tk.Canvas(self, borderwidth=0, highlightthickness=0)
        self.scrollbar = ttk.Scrollbar(self, orient="vertical", command=self.canvas.yview)
        self.inner = ttk.Frame(self.canvas)
        self.window = self.canvas.create_window((0, 0), window=self.inner, anchor="nw")
        self.canvas.configure(yscrollcommand=self.scrollbar.set)
        self.canvas.pack(side="left", fill="both", expand=True)
        self.scrollbar.pack(side="right", fill="y")
        self.inner.bind("<Configure>", lambda _event: self.canvas.configure(scrollregion=self.canvas.bbox("all")))
        self.canvas.bind("<Configure>", lambda event: self.canvas.itemconfigure(self.window, width=event.width))


class PokemonData:
    def __init__(self):
        self.reload()

    def reload(self):
        self.blocks = load_species_blocks()
        self.species_order = species_constant_order()

    def get_species_list(self):
        ordered = [species for species in self.species_order if species in self.blocks]
        remaining = [species for species in self.blocks if species not in set(ordered)]
        return ordered + remaining

    def get_block(self, species):
        return self.blocks[species]

    def get_values(self, species):
        raw_fields = dict(self.get_block(species).fields)
        fields = {key: effective_value(value) for key, value in raw_fields.items()}
        type_values = re.findall(r"TYPE_[A-Z0-9_]+", fields.get("types", ""))
        fields["type1"] = type_values[0] if type_values else ""
        fields["type2"] = type_values[1] if len(type_values) > 1 else fields["type1"]
        ability_values = re.findall(r"ABILITY_[A-Z0-9_]+", fields.get("abilities", ""))
        fields["ability1"] = ability_values[0] if ability_values else ""
        fields["ability2"] = ability_values[1] if len(ability_values) > 1 else "ABILITY_NONE"
        fields["hiddenAbility"] = ability_values[2] if len(ability_values) > 2 else "ABILITY_NONE"
        egg_values = re.findall(r"EGG_GROUP_[A-Z0-9_]+", fields.get("eggGroups", ""))
        fields["eggGroup1"] = egg_values[0] if egg_values else ""
        fields["eggGroup2"] = egg_values[1] if len(egg_values) > 1 else fields["eggGroup1"]
        return fields

    def save_values(self, species, values):
        block = self.get_block(species)
        fields = dict(block.fields)
        evolution_value = values.pop("evolutions", None)
        for key, value in values.items():
            if key in {"type1", "type2", "ability1", "ability2", "hiddenAbility", "eggGroup1", "eggGroup2"}:
                continue
            if value:
                fields[key] = value
            elif key in fields:
                del fields[key]
        type1 = values.get("type1") or "TYPE_NORMAL"
        type2 = values.get("type2") or type1
        fields["types"] = f"MON_TYPES({type1})" if type1 == type2 else f"MON_TYPES({type1}, {type2})"
        fields["abilities"] = "{ " + ", ".join([
            values.get("ability1") or "ABILITY_NONE",
            values.get("ability2") or "ABILITY_NONE",
            values.get("hiddenAbility") or "ABILITY_NONE",
        ]) + " }"
        egg1 = values.get("eggGroup1") or "EGG_GROUP_NO_EGGS_DISCOVERED"
        egg2 = values.get("eggGroup2") or egg1
        fields["eggGroups"] = f"MON_EGG_GROUPS({egg1})" if egg1 == egg2 else f"MON_EGG_GROUPS({egg1}, {egg2})"
        if evolution_value:
            fields["evolutions"] = evolution_value
        elif evolution_value == "":
            fields.pop("evolutions", None)
        replace_block(block, format_species_block(species, fields, block.macros))
        self.reload()

    def create_species(self, raw_name):
        species = normalize_species_name(raw_name)
        if species in self.blocks:
            raise ValueError(f"{species} ja existe.")
        display = species.replace("SPECIES_", "").replace("_", " ").title()
        add_species_constant(species)
        add_pokedex_constant(natdex_for_species(species))
        ensure_graphics_constants(species)
        ensure_graphics_folder(species)
        fields, macros = new_species_fields(species, display)
        insert_custom_species_block(species, fields, macros)
        self.reload()
        return species


class PokemonEditorApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Pokemon Editor - pokeemerald-expansion")
        self.root.geometry("1180x760")
        self.data = PokemonData()
        self.current_species = None
        self.entry_vars = {}
        self.learnset_rows = []
        self.photo_refs = {}
        self.show_guides = tk.BooleanVar(value=True)
        self.build_ui()
        self.load_species_list()

    def build_ui(self):
        self.root.columnconfigure(1, weight=1)
        self.root.rowconfigure(0, weight=1)
        left = ttk.Frame(self.root, padding=8)
        left.grid(row=0, column=0, sticky="ns")
        left.columnconfigure(0, weight=1)
        left.rowconfigure(2, weight=1)
        ttk.Label(left, text="Buscar Pokemon").grid(row=0, column=0, sticky="w")
        self.search_var = tk.StringVar()
        self.search_var.trace_add("write", self.filter_species)
        ttk.Entry(left, textvariable=self.search_var, width=30).grid(row=1, column=0, sticky="ew", pady=(2, 8))
        self.species_tree = ttk.Treeview(left, columns=("name",), show="tree headings", height=28, selectmode="browse")
        self.species_tree.heading("#0", text="Species")
        self.species_tree.heading("name", text="Nome")
        self.species_tree.column("#0", width=190, stretch=False)
        self.species_tree.column("name", width=120, stretch=True)
        self.species_tree.grid(row=2, column=0, sticky="nsew")
        self.species_tree.bind("<<TreeviewSelect>>", self.on_species_select)
        buttons = ttk.Frame(left)
        buttons.grid(row=3, column=0, sticky="ew", pady=(8, 0))
        ttk.Button(buttons, text="Novo", command=self.open_new_species_dialog).pack(side="left", fill="x", expand=True)
        ttk.Button(buttons, text="Recarregar", command=self.reload_data).pack(side="left", fill="x", expand=True, padx=4)
        ttk.Button(buttons, text="Salvar", command=self.save_all).pack(side="left", fill="x", expand=True)

        right = ttk.Frame(self.root, padding=(0, 8, 8, 8))
        right.grid(row=0, column=1, sticky="nsew")
        right.columnconfigure(0, weight=1)
        right.rowconfigure(1, weight=1)
        self.header_var = tk.StringVar(value="Selecione um Pokemon")
        ttk.Label(right, textvariable=self.header_var, font=("TkDefaultFont", 14, "bold")).grid(row=0, column=0, sticky="ew", pady=(0, 8))
        notebook = ttk.Notebook(right)
        notebook.grid(row=1, column=0, sticky="nsew")
        self.create_stats_info_tab(notebook)
        self.create_position_preview_tab(notebook)
        self.create_pokedex_tab(notebook)
        self.create_learnset_tab(notebook)
        self.create_evolutions_tab(notebook)
        self.create_form_species_tab(notebook)
        self.create_form_change_tab(notebook)
        self.create_files_tab(notebook)
        self.status_var = tk.StringVar(value="Pronto.")
        ttk.Label(self.root, textvariable=self.status_var, anchor="w").grid(row=1, column=0, columnspan=2, sticky="ew")

    def create_labeled_entry(self, parent, label, key, row, column, width=18, values=None):
        ttk.Label(parent, text=label).grid(row=row, column=column * 2, sticky="w", padx=(0, 8), pady=4)
        var = tk.StringVar()
        if values:
            entry = ttk.Combobox(parent, textvariable=var, values=values, width=width)
        else:
            entry = ttk.Entry(parent, textvariable=var, width=width)
        entry.grid(row=row, column=column * 2 + 1, sticky="ew", padx=(0, 18), pady=4)
        entry.bind("<FocusOut>", self.apply_current_edits)
        entry.bind("<Return>", self.apply_current_edits)
        parent.columnconfigure(column * 2 + 1, weight=1)
        self.entry_vars[key] = var
        return entry

    def create_labeled_entry_with_button(self, parent, label, key, row, column, button_text, command, width=18, values=None):
        ttk.Label(parent, text=label).grid(row=row, column=column * 2, sticky="w", padx=(0, 8), pady=4)
        var = tk.StringVar()
        holder = ttk.Frame(parent)
        holder.grid(row=row, column=column * 2 + 1, sticky="ew", padx=(0, 18), pady=4)
        if values:
            entry = ttk.Combobox(holder, textvariable=var, values=values, width=width)
        else:
            entry = ttk.Entry(holder, textvariable=var, width=width)
        entry.pack(side="left", fill="x", expand=True)
        ttk.Button(holder, text=button_text, command=command).pack(side="left", padx=(4, 0))
        entry.bind("<FocusOut>", self.apply_current_edits)
        entry.bind("<Return>", self.apply_current_edits)
        parent.columnconfigure(column * 2 + 1, weight=1)
        self.entry_vars[key] = var
        return entry

    def create_nudge_entry(self, parent, label, key, row, column, width=10):
        ttk.Label(parent, text=label).grid(row=row, column=column * 2, sticky="w", padx=(0, 8), pady=4)
        var = tk.StringVar()
        holder = ttk.Frame(parent)
        holder.grid(row=row, column=column * 2 + 1, sticky="ew", padx=(0, 18), pady=4)
        entry = ttk.Entry(holder, textvariable=var, width=width)
        entry.pack(side="left", fill="x", expand=True)
        ttk.Button(holder, text="▲", width=2, command=lambda: self.nudge_value(key, 1)).pack(side="left", padx=(4, 0))
        ttk.Button(holder, text="▼", width=2, command=lambda: self.nudge_value(key, -1)).pack(side="left", padx=(2, 0))
        entry.bind("<FocusOut>", self.apply_current_edits)
        entry.bind("<Return>", self.apply_current_edits)
        parent.columnconfigure(column * 2 + 1, weight=1)
        self.entry_vars[key] = var
        return entry

    def create_stats_info_tab(self, notebook):
        scroll = ScrollableFrame(notebook)
        notebook.add(scroll, text="Base Stats / Dados Gerais")
        tab = scroll.inner
        stats = ttk.LabelFrame(tab, text="Base Stats", padding=10)
        stats.grid(row=0, column=0, sticky="nsew", padx=(0, 8), pady=(0, 8))
        for idx, field in enumerate(BASE_STAT_FIELDS):
            self.create_labeled_entry(stats, field, field, idx // 2, idx % 2, width=10)
        self.bst_var = tk.StringVar(value="0")
        ttk.Label(stats, text="BST").grid(row=3, column=0, sticky="w", pady=(10, 4))
        ttk.Label(stats, textvariable=self.bst_var, font=("TkDefaultFont", 18, "bold")).grid(row=3, column=1, sticky="w", pady=(10, 4))

        battle = ttk.LabelFrame(tab, text="Tipos, captura e EXP", padding=10)
        battle.grid(row=0, column=1, sticky="nsew", padx=(8, 0), pady=(0, 8))
        self.create_labeled_entry(battle, "type1", "type1", 0, 0, width=22, values=TYPE_OPTIONS)
        self.create_labeled_entry(battle, "type2", "type2", 0, 1, width=22, values=TYPE_OPTIONS)
        self.create_labeled_entry(battle, "catchRate", "catchRate", 1, 0, width=10)
        self.create_labeled_entry(battle, "expYield", "expYield", 1, 1, width=10)
        self.create_labeled_entry(battle, "growthRate", "growthRate", 2, 0, width=24, values=GROWTH_OPTIONS)
        self.create_labeled_entry(battle, "genderRatio", "genderRatio", 2, 1, width=24)
        self.create_labeled_entry(battle, "eggCycles", "eggCycles", 3, 0, width=10)
        self.create_labeled_entry(battle, "friendship", "friendship", 3, 1, width=10)

        evs = ttk.LabelFrame(tab, text="EV Yield", padding=10)
        evs.grid(row=1, column=0, sticky="nsew", padx=(0, 8), pady=8)
        for idx, field in enumerate(EV_FIELDS):
            self.create_labeled_entry(evs, field, field, idx // 2, idx % 2, width=10)

        breeding = ttk.LabelFrame(tab, text="Egg Groups / Abilities", padding=10)
        breeding.grid(row=1, column=1, sticky="nsew", padx=(8, 0), pady=8)
        self.create_labeled_entry(breeding, "eggGroup1", "eggGroup1", 0, 0, width=28, values=EGG_GROUP_OPTIONS)
        self.create_labeled_entry(breeding, "eggGroup2", "eggGroup2", 0, 1, width=28, values=EGG_GROUP_OPTIONS)
        self.create_labeled_entry(breeding, "ability1", "ability1", 1, 0, width=30, values=ABILITY_OPTIONS)
        self.create_labeled_entry(breeding, "ability2", "ability2", 1, 1, width=30, values=ABILITY_OPTIONS)
        self.create_labeled_entry(breeding, "hiddenAbility", "hiddenAbility", 2, 0, width=30, values=ABILITY_OPTIONS)

        misc = ttk.LabelFrame(tab, text="Identidade", padding=10)
        misc.grid(row=2, column=0, columnspan=2, sticky="nsew", pady=(8, 0))
        self.create_labeled_entry(misc, "speciesName", "speciesName", 0, 0, width=24)
        self.create_labeled_entry_with_button(misc, "cryId", "cryId", 0, 1, "Play", self.play_current_cry, width=24)
        self.create_labeled_entry(misc, "bodyColor", "bodyColor", 1, 0, width=24, values=BODY_COLOR_OPTIONS)
        self.create_labeled_entry(misc, "itemCommon", "itemCommon", 1, 1, width=28, values=ITEM_OPTIONS)
        self.create_labeled_entry(misc, "itemRare", "itemRare", 2, 0, width=28, values=ITEM_OPTIONS)
        tab.columnconfigure(0, weight=1)
        tab.columnconfigure(1, weight=1)

    def create_position_preview_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=8)
        notebook.add(tab, text="Coords / Elevacao / Preview")
        tab.columnconfigure(1, weight=1)
        tab.rowconfigure(0, weight=1)
        controls = ttk.Frame(tab)
        controls.grid(row=0, column=0, sticky="ns", padx=(0, 8))
        front = ttk.LabelFrame(controls, text="Front sprite", padding=10)
        back = ttk.LabelFrame(controls, text="Back sprite", padding=10)
        front.pack(fill="x", pady=(0, 8))
        back.pack(fill="x", pady=8)
        self.create_labeled_entry(front, "frontPicSize", "frontPicSize", 0, 0, width=24)
        self.create_nudge_entry(front, "frontPicYOffset", "frontPicYOffset", 1, 0, width=10)
        self.create_labeled_entry(front, "frontAnimId", "frontAnimId", 2, 0, width=24)
        self.create_labeled_entry(front, "enemyMonElevation", "enemyMonElevation", 3, 0, width=10)
        self.create_labeled_entry(back, "backPicSize", "backPicSize", 0, 0, width=24)
        self.create_nudge_entry(back, "backPicYOffset", "backPicYOffset", 1, 0, width=10)
        self.create_labeled_entry(back, "backAnimId", "backAnimId", 2, 0, width=24)
        self.preview_canvas = tk.Canvas(tab, bg="#202020", highlightthickness=0)
        self.preview_canvas.grid(row=0, column=1, sticky="nsew")
        self.preview_canvas.bind("<Configure>", lambda _event: self.update_preview())
        toolbar = ttk.Frame(tab)
        toolbar.grid(row=1, column=1, sticky="ew", pady=(8, 0))
        ttk.Checkbutton(toolbar, text="Guias", variable=self.show_guides, command=self.update_preview).pack(side="left")
        ttk.Button(toolbar, text="Atualizar", command=self.update_preview).pack(side="right")

    def create_pokedex_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Pokedex")
        tab.columnconfigure(1, weight=1)
        for idx, key in enumerate(["natDexNum", "categoryName", "height", "weight", "pokemonScale", "pokemonOffset", "trainerScale", "trainerOffset"]):
            self.create_labeled_entry(tab, key, key, idx, 0, width=42)
        ttk.Label(tab, text="description").grid(row=8, column=0, sticky="nw", padx=(0, 8), pady=(8, 4))
        self.description_text = tk.Text(tab, height=8, wrap="word")
        self.description_text.grid(row=8, column=1, sticky="nsew", pady=(8, 4))
        self.description_text.bind("<FocusOut>", self.apply_current_edits)
        tab.rowconfigure(8, weight=1)

    def create_learnset_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Learnset")
        tab.columnconfigure(0, weight=1)
        tab.rowconfigure(2, weight=1)
        self.learnset_name_var = tk.StringVar()
        self.create_labeled_entry(tab, "levelUpLearnset", "levelUpLearnset", 0, 0, width=42)
        toolbar = ttk.Frame(tab)
        toolbar.grid(row=1, column=0, columnspan=2, sticky="ew", pady=(8, 4))
        ttk.Button(toolbar, text="Adicionar move", command=self.add_learnset_row).pack(side="left")
        ttk.Button(toolbar, text="Remover selecionado", command=self.remove_selected_learnset_row).pack(side="left", padx=(8, 0))
        self.learnset_canvas = tk.Canvas(tab, borderwidth=0, highlightthickness=0)
        self.learnset_rows_frame = ttk.Frame(self.learnset_canvas)
        self.learnset_scrollbar = ttk.Scrollbar(tab, orient="vertical", command=self.learnset_canvas.yview)
        self.learnset_canvas.configure(yscrollcommand=self.learnset_scrollbar.set)
        self.learnset_window = self.learnset_canvas.create_window((0, 0), window=self.learnset_rows_frame, anchor="nw")
        self.learnset_canvas.grid(row=2, column=0, sticky="nsew")
        self.learnset_scrollbar.grid(row=2, column=1, sticky="ns")
        self.learnset_rows_frame.bind("<Configure>", lambda _event: self.learnset_canvas.configure(scrollregion=self.learnset_canvas.bbox("all")))
        self.learnset_canvas.bind("<Configure>", lambda event: self.learnset_canvas.itemconfigure(self.learnset_window, width=event.width))
        header = ttk.Frame(self.learnset_rows_frame)
        header.grid(row=0, column=0, sticky="ew", pady=(0, 4))
        ttk.Label(header, text="Nivel", width=8).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Move").pack(side="left", fill="x", expand=True)
        ttk.Label(tab, text="Use Salvar para gravar o array em src/data/pokemon/level_up_learnsets/gen_9.h.").grid(row=3, column=0, columnspan=2, sticky="w", pady=(8, 0))

    def create_evolutions_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Evolution Chart")
        tab.columnconfigure(0, weight=1)
        tab.rowconfigure(1, weight=1)
        toolbar = ttk.Frame(tab)
        toolbar.grid(row=0, column=0, sticky="ew", pady=(0, 8))
        ttk.Button(toolbar, text="Adicionar evolução", command=self.add_evolution_row).pack(side="left")
        ttk.Button(toolbar, text="Remover selecionada", command=self.remove_selected_evolution_row).pack(side="left", padx=(8, 0))
        self.evolution_canvas = tk.Canvas(tab, borderwidth=0, highlightthickness=0)
        self.evolution_rows_frame = ttk.Frame(self.evolution_canvas)
        self.evolution_scrollbar = ttk.Scrollbar(tab, orient="vertical", command=self.evolution_canvas.yview)
        self.evolution_canvas.configure(yscrollcommand=self.evolution_scrollbar.set)
        self.evolution_window = self.evolution_canvas.create_window((0, 0), window=self.evolution_rows_frame, anchor="nw")
        self.evolution_canvas.grid(row=1, column=0, sticky="nsew")
        self.evolution_scrollbar.grid(row=1, column=1, sticky="ns")
        self.evolution_rows_frame.bind("<Configure>", lambda _event: self.evolution_canvas.configure(scrollregion=self.evolution_canvas.bbox("all")))
        self.evolution_canvas.bind("<Configure>", lambda event: self.evolution_canvas.itemconfigure(self.evolution_window, width=event.width))
        header = ttk.Frame(self.evolution_rows_frame)
        header.grid(row=0, column=0, sticky="ew", pady=(0, 4))
        ttk.Label(header, text="Metodo", width=24).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Parametro", width=22).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Destino", width=30).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Condition", width=28).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Condition Param").pack(side="left", fill="x", expand=True)
        ttk.Label(tab, text="Quando nao houver condicao, deixe Condition em branco. O parametro e opcional.").grid(row=2, column=0, columnspan=2, sticky="w", pady=(8, 0))

    def create_form_species_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Form Species")
        tab.columnconfigure(0, weight=1)
        tab.rowconfigure(2, weight=1)
        top = ttk.Frame(tab)
        top.grid(row=0, column=0, columnspan=2, sticky="ew", pady=(0, 8))
        top.columnconfigure(1, weight=1)
        ttk.Label(top, text="formSpeciesIdTable").grid(row=0, column=0, sticky="w", padx=(0, 8))
        self.form_table_var = tk.StringVar()
        ttk.Entry(top, textvariable=self.form_table_var).grid(row=0, column=1, sticky="ew")
        ttk.Button(top, text="Usar nome padrão", command=self.set_default_form_table_name).grid(row=0, column=2, padx=(8, 0))
        toolbar = ttk.Frame(tab)
        toolbar.grid(row=1, column=0, columnspan=2, sticky="ew", pady=(0, 4))
        ttk.Button(toolbar, text="Adicionar forma", command=self.add_form_species_row).pack(side="left")
        ttk.Button(toolbar, text="Remover selecionada", command=self.remove_selected_form_species_row).pack(side="left", padx=(8, 0))
        self.form_canvas = tk.Canvas(tab, borderwidth=0, highlightthickness=0)
        self.form_rows_frame = ttk.Frame(self.form_canvas)
        self.form_scrollbar = ttk.Scrollbar(tab, orient="vertical", command=self.form_canvas.yview)
        self.form_canvas.configure(yscrollcommand=self.form_scrollbar.set)
        self.form_window = self.form_canvas.create_window((0, 0), window=self.form_rows_frame, anchor="nw")
        self.form_canvas.grid(row=2, column=0, sticky="nsew")
        self.form_scrollbar.grid(row=2, column=1, sticky="ns")
        self.form_rows_frame.bind("<Configure>", lambda _event: self.form_canvas.configure(scrollregion=self.form_canvas.bbox("all")))
        self.form_canvas.bind("<Configure>", lambda event: self.form_canvas.itemconfigure(self.form_window, width=event.width))
        header = ttk.Frame(self.form_rows_frame)
        header.grid(row=0, column=0, sticky="ew", pady=(0, 4))
        ttk.Label(header, text="Species / Form").pack(side="left", fill="x", expand=True)
        ttk.Label(tab, text="Salva em src/data/pokemon/form_species_tables.h e atualiza .formSpeciesIdTable no SpeciesInfo.").grid(row=3, column=0, columnspan=2, sticky="w", pady=(8, 0))

    def create_form_change_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Form Change")
        tab.columnconfigure(0, weight=1)
        tab.rowconfigure(2, weight=1)
        top = ttk.Frame(tab)
        top.grid(row=0, column=0, columnspan=2, sticky="ew", pady=(0, 8))
        top.columnconfigure(1, weight=1)
        ttk.Label(top, text="formChangeTable").grid(row=0, column=0, sticky="w", padx=(0, 8))
        self.form_change_table_var = tk.StringVar()
        ttk.Entry(top, textvariable=self.form_change_table_var).grid(row=0, column=1, sticky="ew")
        ttk.Button(top, text="Usar nome padrão", command=self.set_default_form_change_table_name).grid(row=0, column=2, padx=(8, 0))
        toolbar = ttk.Frame(tab)
        toolbar.grid(row=1, column=0, columnspan=2, sticky="ew", pady=(0, 4))
        ttk.Button(toolbar, text="Adicionar mudança", command=self.add_form_change_row).pack(side="left")
        ttk.Button(toolbar, text="Adicionar Mega por item", command=self.add_mega_form_change_row).pack(side="left", padx=(8, 0))
        ttk.Button(toolbar, text="Remover selecionada", command=self.remove_selected_form_change_row).pack(side="left", padx=(8, 0))
        self.form_change_canvas = tk.Canvas(tab, borderwidth=0, highlightthickness=0)
        self.form_change_rows_frame = ttk.Frame(self.form_change_canvas)
        self.form_change_scrollbar = ttk.Scrollbar(tab, orient="vertical", command=self.form_change_canvas.yview)
        self.form_change_canvas.configure(yscrollcommand=self.form_change_scrollbar.set)
        self.form_change_window = self.form_change_canvas.create_window((0, 0), window=self.form_change_rows_frame, anchor="nw")
        self.form_change_canvas.grid(row=2, column=0, sticky="nsew")
        self.form_change_scrollbar.grid(row=2, column=1, sticky="ns")
        self.form_change_rows_frame.bind("<Configure>", lambda _event: self.form_change_canvas.configure(scrollregion=self.form_change_canvas.bbox("all")))
        self.form_change_canvas.bind("<Configure>", lambda event: self.form_change_canvas.itemconfigure(self.form_change_window, width=event.width))
        header = ttk.Frame(self.form_change_rows_frame)
        header.grid(row=0, column=0, sticky="ew", pady=(0, 4))
        ttk.Label(header, text="Tipo", width=40).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Specie alvo", width=30).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Item / Arg1", width=28).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Arg2", width=20).pack(side="left", padx=(0, 8))
        ttk.Label(header, text="Arg3").pack(side="left", fill="x", expand=True)
        ttk.Label(tab, text="Para FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM, use Specie alvo = forma Mega e Item / Arg1 = mega stone.").grid(row=3, column=0, columnspan=2, sticky="w", pady=(8, 0))

    def create_files_tab(self, notebook):
        tab = ttk.Frame(notebook, padding=12)
        notebook.add(tab, text="Sprites / Arquivos")
        tab.columnconfigure(1, weight=1)
        self.front_path_var = tk.StringVar()
        self.back_path_var = tk.StringVar()
        ttk.Label(tab, text="Front PNG").grid(row=0, column=0, sticky="w", pady=4)
        ttk.Entry(tab, textvariable=self.front_path_var, state="readonly").grid(row=0, column=1, sticky="ew", padx=8, pady=4)
        ttk.Label(tab, text="Back PNG").grid(row=1, column=0, sticky="w", pady=4)
        ttk.Entry(tab, textvariable=self.back_path_var, state="readonly").grid(row=1, column=1, sticky="ew", padx=8, pady=4)
        ttk.Button(tab, text="Criar pasta grafica padrao", command=self.create_graphics_folder).grid(row=2, column=1, sticky="w", padx=8, pady=(8, 4))
        ttk.Button(tab, text="Importar sheet 192x64", command=self.import_sprite_sheet).grid(row=3, column=1, sticky="w", padx=8, pady=4)
        ttk.Button(tab, text="Registrar graficos no codigo", command=self.register_graphics).grid(row=4, column=1, sticky="w", padx=8, pady=4)
        files = [SPECIES_CONSTANTS, POKEDEX_CONSTANTS, SPECIES_INFO_MAIN, POKEMON_GRAPHICS, LEVEL_UP_GEN9, FORM_SPECIES_TABLES, FORM_CHANGE_TABLES, PREVIEW_BACKGROUND, PREVIEW_SHADOW]
        ttk.Label(tab, text="Arquivos usados pela ferramenta").grid(row=5, column=0, columnspan=2, sticky="w", pady=(18, 4))
        for idx, path in enumerate(files, start=6):
            ttk.Label(tab, text=str(path.relative_to(ROOT))).grid(row=idx, column=0, columnspan=2, sticky="w", pady=2)

    def load_species_list(self):
        self.species = self.data.get_species_list()
        self.filtered_species = list(self.species)
        self.refresh_species_listbox()
        self.status_var.set(f"{len(self.species)} Pokemon carregados.")

    def refresh_species_listbox(self):
        self.species_tree.delete(*self.species_tree.get_children(""))
        for species in self.filtered_species:
            block = self.data.get_block(species)
            self.species_tree.insert("", tk.END, iid=species, text=species, values=(c_string_preview(block.fields.get("speciesName", "")),))

    def filter_species(self, *_args):
        term = self.search_var.get().strip().upper()
        self.filtered_species = [s for s in self.species if not term or term in s or term in c_string_preview(self.data.get_block(s).fields.get("speciesName", "")).upper()]
        self.refresh_species_listbox()

    def on_species_select(self, _event=None):
        selection = self.species_tree.selection()
        if selection:
            self.select_species(selection[0])

    def select_species(self, species):
        self.current_species = species
        values = self.data.get_values(species)
        for key, var in self.entry_vars.items():
            var.set(values.get(key, ""))
        if hasattr(self, "description_text"):
            self.description_text.delete("1.0", tk.END)
            self.description_text.insert("1.0", values.get("description", ""))
        self.header_var.set(f"{species} - {c_string_preview(values.get('speciesName', ''))}")
        self.update_bst()
        self.update_sprite_paths()
        self.update_learnset_rows()
        self.update_evolution_rows()
        self.update_form_species_rows()
        self.update_form_change_rows()
        self.update_preview()
        self.status_var.set(f"Editando {species}.")

    def collect_values(self):
        values = {key: var.get().strip() for key, var in self.entry_vars.items()}
        if hasattr(self, "description_text"):
            values["description"] = self.description_text.get("1.0", "end-1c").strip()
        return values

    def validate_values(self, values):
        for key, value in values.items():
            if value and key in NUMERIC_FIELDS and parse_int(effective_value(value)) is None:
                raise ValueError(f"Valor invalido em {key}: {value}")
        self.collect_learnset_entries()
        self.collect_evolution_entries()
        self.collect_form_species_entries()
        self.collect_form_change_entries()

    def apply_current_edits(self, _event=None, silent=False):
        if not self.current_species:
            return True
        values = self.collect_values()
        try:
            self.validate_values(values)
        except ValueError as exc:
            if not silent:
                messagebox.showerror("Entrada invalida", str(exc))
            self.status_var.set(str(exc))
            return False
        self.update_bst()
        self.update_preview()
        if not silent:
            self.status_var.set(f"Valores aplicados para {self.current_species}. Clique em Salvar para gravar.")
        return True

    def update_bst(self):
        total = sum(parse_int(effective_value(self.entry_vars[field].get())) or 0 for field in BASE_STAT_FIELDS if field in self.entry_vars)
        self.bst_var.set(str(total))

    def nudge_value(self, key, delta):
        if key not in self.entry_vars:
            return
        raw = self.entry_vars[key].get().strip() or "0"
        value = parse_int(effective_value(raw))
        if value is None:
            self.status_var.set(f"Valor invalido em {key}: {raw}")
            return
        self.entry_vars[key].set(str(value + delta))
        self.apply_current_edits()

    def clear_learnset_rows(self):
        for row in self.learnset_rows:
            row["frame"].destroy()
        self.learnset_rows = []
        self.selected_learnset_row = None

    def update_learnset_rows(self):
        if not hasattr(self, "learnset_rows_frame"):
            return
        self.clear_learnset_rows()
        array_name = self.entry_vars.get("levelUpLearnset", tk.StringVar()).get().strip()
        for level, move in parse_level_up_learnset(array_name):
            self.add_learnset_row(level, move)

    def add_learnset_row(self, level=1, move="MOVE_NONE"):
        if not hasattr(self, "learnset_rows_frame"):
            return
        row_index = len(self.learnset_rows) + 1
        frame = ttk.Frame(self.learnset_rows_frame, padding=(2, 2))
        frame.grid(row=row_index, column=0, sticky="ew")
        frame.columnconfigure(1, weight=1)
        level_var = tk.StringVar(value=str(level))
        move_var = tk.StringVar(value=move)
        level_entry = ttk.Entry(frame, textvariable=level_var, width=8)
        level_entry.grid(row=0, column=0, sticky="w", padx=(0, 8), pady=2)
        move_combo = ttk.Combobox(frame, textvariable=move_var, values=MOVE_OPTIONS, width=36)
        move_combo.grid(row=0, column=1, sticky="ew", pady=2)
        name_var = tk.StringVar(value=symbol_to_title(move, "MOVE_"))
        ttk.Label(frame, textvariable=name_var, width=24).grid(row=0, column=2, sticky="w", padx=(8, 0))
        row = {"frame": frame, "level": level_var, "move": move_var, "name": name_var}
        self.learnset_rows.append(row)

        def select_row(_event=None, selected=row):
            self.selected_learnset_row = selected

        def update_name(_event=None):
            name_var.set(symbol_to_title(move_var.get(), "MOVE_"))

        frame.bind("<Button-1>", select_row)
        level_entry.bind("<FocusIn>", select_row)
        move_combo.bind("<FocusIn>", select_row)
        move_combo.bind("<<ComboboxSelected>>", update_name)
        move_combo.bind("<FocusOut>", update_name)
        return row

    def remove_selected_learnset_row(self):
        if not getattr(self, "selected_learnset_row", None):
            return
        self.selected_learnset_row["frame"].destroy()
        self.learnset_rows.remove(self.selected_learnset_row)
        self.selected_learnset_row = None
        for idx, row in enumerate(self.learnset_rows, start=1):
            row["frame"].grid_configure(row=idx)

    def collect_learnset_entries(self):
        entries = []
        for row in getattr(self, "learnset_rows", []):
            level = parse_int(row["level"].get())
            move = row["move"].get().strip()
            if level is None:
                raise ValueError(f"Nivel invalido no learnset: {row['level'].get()}")
            if move not in MOVE_OPTIONS:
                raise ValueError(f"Move invalido no learnset: {move}")
            entries.append((level, move))
        return entries

    def clear_evolution_rows(self):
        for row in getattr(self, "evolution_rows", []):
            row["frame"].destroy()
        self.evolution_rows = []
        self.selected_evolution_row = None

    def update_evolution_rows(self):
        if not hasattr(self, "evolution_rows_frame"):
            return
        self.clear_evolution_rows()
        raw = self.data.get_block(self.current_species).fields.get("evolutions", "") if self.current_species else ""
        for entry in parse_evolution_entries(raw):
            self.add_evolution_row(entry)

    def add_evolution_row(self, entry=None):
        if not hasattr(self, "evolution_rows_frame"):
            return
        entry = entry or {"method": "EVO_LEVEL", "param": "16", "target": "SPECIES_NONE", "condition": "", "condition_param": "", "extra": ""}
        row_index = len(getattr(self, "evolution_rows", [])) + 1
        frame = ttk.Frame(self.evolution_rows_frame, padding=(2, 2))
        frame.grid(row=row_index, column=0, sticky="ew")
        frame.columnconfigure(3, weight=1)
        method_var = tk.StringVar(value=entry.get("method", "EVO_LEVEL"))
        param_var = tk.StringVar(value=entry.get("param", "16"))
        target_var = tk.StringVar(value=entry.get("target", "SPECIES_NONE"))
        condition_var = tk.StringVar(value=entry.get("condition", ""))
        condition_param_var = tk.StringVar(value=entry.get("condition_param", entry.get("extra", "")))
        method_combo = ttk.Combobox(frame, textvariable=method_var, values=EVO_METHOD_OPTIONS, width=22)
        method_combo.grid(row=0, column=0, sticky="ew", padx=(0, 8), pady=2)
        ttk.Entry(frame, textvariable=param_var, width=22).grid(row=0, column=1, sticky="ew", padx=(0, 8), pady=2)
        target_combo = ttk.Combobox(frame, textvariable=target_var, values=self.species, width=30)
        target_combo.grid(row=0, column=2, sticky="ew", padx=(0, 8), pady=2)
        condition_combo = ttk.Combobox(frame, textvariable=condition_var, values=EVOLUTION_CONDITION_OPTIONS, width=28)
        condition_combo.grid(row=0, column=3, sticky="ew", padx=(0, 8), pady=2)
        ttk.Entry(frame, textvariable=condition_param_var, width=36).grid(row=0, column=4, sticky="ew", pady=2)
        row = {"frame": frame, "method": method_var, "param": param_var, "target": target_var, "condition": condition_var, "condition_param": condition_param_var}
        self.evolution_rows.append(row)

        def select_row(_event=None, selected=row):
            self.selected_evolution_row = selected

        for child in frame.winfo_children():
            child.bind("<FocusIn>", select_row)
        frame.bind("<Button-1>", select_row)
        return row

    def remove_selected_evolution_row(self):
        if not getattr(self, "selected_evolution_row", None):
            return
        self.selected_evolution_row["frame"].destroy()
        self.evolution_rows.remove(self.selected_evolution_row)
        self.selected_evolution_row = None
        for idx, row in enumerate(self.evolution_rows, start=1):
            row["frame"].grid_configure(row=idx)

    def collect_evolution_entries(self):
        entries = []
        for row in getattr(self, "evolution_rows", []):
            method = row["method"].get().strip()
            param = row["param"].get().strip()
            target = row["target"].get().strip()
            condition = row["condition"].get().strip()
            condition_param = row["condition_param"].get().strip()
            if not method and not param and not target and not condition and not condition_param:
                continue
            if method not in EVO_METHOD_OPTIONS:
                raise ValueError(f"Metodo de evolucao invalido: {method}")
            if target not in self.species:
                raise ValueError(f"Species de evolucao invalida: {target}")
            if not param:
                raise ValueError("Parametro de evolucao vazio.")
            if condition and condition not in EVOLUTION_CONDITION_OPTIONS:
                raise ValueError(f"Condicao de evolucao invalida: {condition}")
            if condition_param and not condition:
                raise ValueError("Condition Param preenchido, mas Condition esta em branco.")
            entries.append({"method": method, "param": param, "target": target, "condition": condition, "condition_param": condition_param})
        return entries

    def set_default_form_table_name(self):
        if self.current_species:
            self.form_table_var.set(default_form_table_name(self.current_species))
            if not getattr(self, "form_rows", []):
                self.add_form_species_row(self.current_species)

    def clear_form_species_rows(self):
        for row in getattr(self, "form_rows", []):
            row["frame"].destroy()
        self.form_rows = []
        self.selected_form_row = None

    def update_form_species_rows(self):
        if not hasattr(self, "form_rows_frame"):
            return
        self.clear_form_species_rows()
        table_name = self.data.get_block(self.current_species).fields.get("formSpeciesIdTable", "") if self.current_species else ""
        self.form_table_var.set(table_name)
        for species in parse_form_species_table(table_name):
            self.add_form_species_row(species)

    def add_form_species_row(self, species=None):
        if not hasattr(self, "form_rows_frame"):
            return
        species = species or self.current_species or "SPECIES_NONE"
        row_index = len(getattr(self, "form_rows", [])) + 1
        frame = ttk.Frame(self.form_rows_frame, padding=(2, 2))
        frame.grid(row=row_index, column=0, sticky="ew")
        frame.columnconfigure(0, weight=1)
        species_var = tk.StringVar(value=species)
        combo = ttk.Combobox(frame, textvariable=species_var, values=self.species, width=48)
        combo.grid(row=0, column=0, sticky="ew", pady=2)
        row = {"frame": frame, "species": species_var}
        self.form_rows.append(row)

        def select_row(_event=None, selected=row):
            self.selected_form_row = selected

        frame.bind("<Button-1>", select_row)
        combo.bind("<FocusIn>", select_row)
        return row

    def remove_selected_form_species_row(self):
        if not getattr(self, "selected_form_row", None):
            return
        self.selected_form_row["frame"].destroy()
        self.form_rows.remove(self.selected_form_row)
        self.selected_form_row = None
        for idx, row in enumerate(self.form_rows, start=1):
            row["frame"].grid_configure(row=idx)

    def collect_form_species_entries(self):
        entries = []
        for row in getattr(self, "form_rows", []):
            species = row["species"].get().strip()
            if not species:
                continue
            if species not in self.species:
                raise ValueError(f"Species/form invalida em Form Species: {species}")
            entries.append(species)
        return entries

    def set_default_form_change_table_name(self):
        if self.current_species:
            self.form_change_table_var.set(default_form_change_table_name(self.current_species))

    def clear_form_change_rows(self):
        for row in getattr(self, "form_change_rows", []):
            row["frame"].destroy()
        self.form_change_rows = []
        self.selected_form_change_row = None

    def update_form_change_rows(self):
        if not hasattr(self, "form_change_rows_frame"):
            return
        self.clear_form_change_rows()
        table_name = self.data.get_block(self.current_species).fields.get("formChangeTable", "") if self.current_species else ""
        self.form_change_table_var.set(table_name)
        for entry in parse_form_change_table(table_name):
            self.add_form_change_row(entry)

    def add_mega_form_change_row(self):
        self.add_form_change_row({
            "type": "FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM",
            "target": "SPECIES_NONE",
            "arg1": "ITEM_NONE",
            "arg2": "",
            "arg3": "",
        })

    def add_form_change_row(self, entry=None):
        if not hasattr(self, "form_change_rows_frame"):
            return
        entry = entry or {"type": "FORM_CHANGE_BATTLE_GIGANTAMAX", "target": "SPECIES_NONE", "arg1": "", "arg2": "", "arg3": ""}
        row_index = len(getattr(self, "form_change_rows", [])) + 1
        frame = ttk.Frame(self.form_change_rows_frame, padding=(2, 2))
        frame.grid(row=row_index, column=0, sticky="ew")
        frame.columnconfigure(4, weight=1)
        type_var = tk.StringVar(value=entry.get("type", ""))
        target_var = tk.StringVar(value=entry.get("target", ""))
        arg1_var = tk.StringVar(value=entry.get("arg1", ""))
        arg2_var = tk.StringVar(value=entry.get("arg2", ""))
        arg3_var = tk.StringVar(value=entry.get("arg3", ""))
        ttk.Combobox(frame, textvariable=type_var, values=FORM_CHANGE_TYPE_OPTIONS, width=40).grid(row=0, column=0, sticky="ew", padx=(0, 8), pady=2)
        ttk.Combobox(frame, textvariable=target_var, values=self.species, width=30).grid(row=0, column=1, sticky="ew", padx=(0, 8), pady=2)
        ttk.Combobox(frame, textvariable=arg1_var, values=ITEM_OPTIONS, width=28).grid(row=0, column=2, sticky="ew", padx=(0, 8), pady=2)
        ttk.Entry(frame, textvariable=arg2_var, width=20).grid(row=0, column=3, sticky="ew", padx=(0, 8), pady=2)
        ttk.Entry(frame, textvariable=arg3_var, width=20).grid(row=0, column=4, sticky="ew", pady=2)
        row = {"frame": frame, "type": type_var, "target": target_var, "arg1": arg1_var, "arg2": arg2_var, "arg3": arg3_var}
        self.form_change_rows.append(row)

        def select_row(_event=None, selected=row):
            self.selected_form_change_row = selected

        for child in frame.winfo_children():
            child.bind("<FocusIn>", select_row)
        frame.bind("<Button-1>", select_row)
        return row

    def remove_selected_form_change_row(self):
        if not getattr(self, "selected_form_change_row", None):
            return
        self.selected_form_change_row["frame"].destroy()
        self.form_change_rows.remove(self.selected_form_change_row)
        self.selected_form_change_row = None
        for idx, row in enumerate(self.form_change_rows, start=1):
            row["frame"].grid_configure(row=idx)

    def collect_form_change_entries(self):
        entries = []
        for row in getattr(self, "form_change_rows", []):
            change_type = row["type"].get().strip()
            target = row["target"].get().strip()
            arg1 = row["arg1"].get().strip()
            arg2 = row["arg2"].get().strip()
            arg3 = row["arg3"].get().strip()
            if not change_type and not target and not arg1 and not arg2 and not arg3:
                continue
            if change_type not in FORM_CHANGE_TYPE_OPTIONS:
                raise ValueError(f"Tipo de form change invalido: {change_type}")
            if target and target not in self.species:
                raise ValueError(f"Specie alvo invalida em Form Change: {target}")
            if change_type == "FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM":
                if not target:
                    raise ValueError("Mega Evolution por item precisa de Specie alvo.")
                if not arg1 or not arg1.startswith("ITEM_"):
                    raise ValueError("Mega Evolution por item precisa do Item / Arg1 com ITEM_*.")
            entries.append({"type": change_type, "target": target, "arg1": arg1, "arg2": arg2, "arg3": arg3})
        return entries

    def sprite_folder(self):
        if not self.current_species:
            return None
        return GRAPHICS_POKEMON / symbol_to_folder(self.current_species)

    def update_sprite_paths(self):
        folder = self.sprite_folder()
        if not folder:
            return
        front = folder / "anim_front.png"
        back = folder / "back.png"
        self.front_path_var.set(str(front.relative_to(ROOT)) if front.exists() else "Nao encontrado")
        self.back_path_var.set(str(back.relative_to(ROOT)) if back.exists() else "Nao encontrado")

    def update_preview(self):
        if not hasattr(self, "preview_canvas"):
            return
        canvas = self.preview_canvas
        canvas.delete("all")
        width = max(canvas.winfo_width(), 240)
        height = max(canvas.winfo_height(), 160)
        if Image is None or ImageTk is None or not self.current_species:
            canvas.create_text(width // 2, height // 2, text="Preview requer Pillow e uma especie selecionada", fill="white")
            return
        bg_width = 240
        bg_height = 160
        if PREVIEW_BACKGROUND.exists():
            bg = Image.open(PREVIEW_BACKGROUND).convert("RGBA")
            bg_width, bg_height = bg.size
            canvas.configure(width=bg_width, height=bg_height, scrollregion=(0, 0, bg_width, bg_height))
            self.photo_refs["bg"] = ImageTk.PhotoImage(bg)
            canvas.create_image(0, 0, image=self.photo_refs["bg"], anchor="nw")
            width = bg_width
            height = bg_height
        folder = self.sprite_folder()
        front_yoff = parse_int(effective_value(self.entry_vars.get("frontPicYOffset", tk.StringVar(value="0")).get())) or 0
        front_elev = parse_int(effective_value(self.entry_vars.get("enemyMonElevation", tk.StringVar(value="0")).get())) or 0
        back_yoff = parse_int(effective_value(self.entry_vars.get("backPicYOffset", tk.StringVar(value="0")).get())) or 0
        front_x = 144
        front_y = 10 + front_yoff - front_elev
        back_x = 40
        back_y = 48 + back_yoff
        if PREVIEW_SHADOW.exists() and front_elev >= 1:
            shadow = load_preview_rgba(PREVIEW_SHADOW, transparent_index=None)
            self.photo_refs["shadow"] = ImageTk.PhotoImage(shadow)
            canvas.create_image(front_x + 16, front_y + 56, image=self.photo_refs["shadow"], anchor="center")
        sprite_path = folder / "anim_front.png" if folder else None
        if sprite_path and sprite_path.exists():
            sprite = pad_to_size(load_preview_rgba(sprite_path, (0, 0, 64, 64)))
            self.photo_refs["front"] = ImageTk.PhotoImage(sprite)
            canvas.create_image(front_x, front_y, image=self.photo_refs["front"], anchor="nw")
        else:
            canvas.create_text(width // 2, height // 2, text="Sem anim_front.png para esta especie", fill="white")
        back_path = folder / "back.png" if folder else None
        if back_path and back_path.exists():
            back_sprite = pad_to_size(load_preview_rgba(back_path, (0, 0, 64, 64)))
            self.photo_refs["back"] = ImageTk.PhotoImage(back_sprite)
            canvas.create_image(back_x, back_y, image=self.photo_refs["back"], anchor="nw")
        if self.show_guides.get():
            canvas.create_rectangle(0, 0, bg_width - 1, bg_height - 1, outline="#ffffff", dash=(4, 4))
            canvas.create_line(0, front_y, bg_width, front_y, fill="#ffffff", dash=(4, 4))
            canvas.create_line(0, back_y, bg_width, back_y, fill="#66ccff", dash=(4, 4))

    def create_graphics_folder(self):
        if not self.current_species:
            messagebox.showwarning("Nenhum Pokemon", "Selecione um Pokemon antes.")
            return
        try:
            path = ensure_graphics_folder(self.current_species)
            self.update_sprite_paths()
            self.status_var.set(f"Pasta pronta: {path.relative_to(ROOT)}")
        except Exception as exc:
            messagebox.showerror("Erro", str(exc))

    def register_graphics(self):
        if not self.current_species:
            messagebox.showwarning("Nenhum Pokemon", "Selecione um Pokemon antes.")
            return
        try:
            ensure_graphics_constants(self.current_species)
            self.status_var.set("Graficos registrados em src/data/graphics/pokemon.h.")
        except Exception as exc:
            messagebox.showerror("Erro", str(exc))

    def import_sprite_sheet(self):
        if not self.current_species:
            messagebox.showwarning("Nenhum Pokemon", "Selecione um Pokemon antes.")
            return
        source = filedialog.askopenfilename(title="Selecionar spritesheet", filetypes=[("PNG", "*.png"), ("Todos", "*.*")])
        if not source:
            return
        try:
            target = import_sprite_sheet(self.current_species, Path(source))
            self.update_sprite_paths()
            self.update_preview()
            self.status_var.set(f"Sprites importados para {target.relative_to(ROOT)}")
        except Exception as exc:
            messagebox.showerror("Erro ao importar spritesheet", str(exc))

    def play_current_cry(self):
        cry_id = self.entry_vars.get("cryId", tk.StringVar()).get().strip()
        try:
            path = cry_wav_path(cry_id)
            if not path:
                raise FileNotFoundError(f"Nao encontrei .wav para {cry_id}.")
            play_audio(path)
            self.status_var.set(f"Tocando {path.relative_to(ROOT)}")
        except Exception as exc:
            messagebox.showerror("Erro ao tocar cry", str(exc))

    def open_new_species_dialog(self):
        name = simpledialog.askstring("Adicionar novo Pokemon", "Nome / macro da especie:", parent=self.root)
        if not name:
            return
        try:
            species = self.data.create_species(name)
            self.load_species_list()
            self.search_var.set(species)
            self.species_tree.selection_set(species)
            self.species_tree.see(species)
            self.select_species(species)
        except Exception as exc:
            messagebox.showerror("Erro ao criar Pokemon", str(exc), parent=self.root)

    def save_all(self):
        if not self.current_species:
            messagebox.showwarning("Nada selecionado", "Selecione um Pokemon antes de salvar.")
            return
        if not self.apply_current_edits(silent=True):
            return
        try:
            values = self.collect_values()
            values["evolutions"] = format_evolution_entries(self.collect_evolution_entries())
            form_entries = self.collect_form_species_entries()
            form_table_name = self.form_table_var.get().strip() if hasattr(self, "form_table_var") else ""
            if form_entries:
                if not form_table_name:
                    form_table_name = default_form_table_name(self.current_species)
                    self.form_table_var.set(form_table_name)
                values["formSpeciesIdTable"] = form_table_name
                replace_form_species_table(form_table_name, form_entries)
            elif form_table_name:
                values["formSpeciesIdTable"] = form_table_name
            form_change_entries = self.collect_form_change_entries()
            form_change_table_name = self.form_change_table_var.get().strip() if hasattr(self, "form_change_table_var") else ""
            if form_change_entries:
                if not form_change_table_name:
                    form_change_table_name = default_form_change_table_name(self.current_species)
                    self.form_change_table_var.set(form_change_table_name)
                values["formChangeTable"] = form_change_table_name
                replace_form_change_table(form_change_table_name, form_change_entries)
            elif form_change_table_name:
                values["formChangeTable"] = form_change_table_name
            self.data.save_values(self.current_species, values)
            array_name = self.entry_vars.get("levelUpLearnset", tk.StringVar()).get().strip()
            if array_name:
                replace_level_up_learnset(array_name, self.collect_learnset_entries())
            self.data.reload()
            self.select_species(self.current_species)
        except Exception as exc:
            messagebox.showerror("Erro ao salvar", str(exc))
            self.status_var.set("Falha ao salvar.")
            return
        self.status_var.set("SpeciesInfo salvo com backup datado.")
        messagebox.showinfo("Salvo", "Arquivos salvos com sucesso.")

    def reload_data(self):
        selected = self.current_species
        try:
            self.data.reload()
            self.load_species_list()
            if selected in self.data.blocks:
                self.select_species(selected)
                self.species_tree.selection_set(selected)
        except Exception as exc:
            messagebox.showerror("Erro", f"Falha ao recarregar: {exc}")


def main() -> None:
    try:
        root = tk.Tk()
    except tk.TclError as exc:
        raise SystemExit(f"Erro ao iniciar Tkinter: {exc}") from exc
    PokemonEditorApp(root)
    root.mainloop()


if __name__ == "__main__":
    main()
