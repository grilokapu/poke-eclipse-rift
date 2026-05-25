#!/usr/bin/env python3
from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
import re
import sys
import textwrap
import urllib.parse
import urllib.request
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MOVES_INFO_PATH = ROOT / "src/data/moves_info.h"
CACHE_PATH = ROOT / "tools/.move_localization_cache.json"
USER_AGENT = "Mozilla/5.0"
LINE_LIMIT = 28
MAX_LINES = 2


VERSION_GROUP_PRIORITY = [
    "scarlet-violet",
    "sword-shield",
    "ultra-sun-ultra-moon",
    "sun-moon",
    "omega-ruby-alpha-sapphire",
    "x-y",
    "black-2-white-2",
    "black-white",
    "heartgold-soulsilver",
    "platinum",
    "diamond-pearl",
    "firered-leafgreen",
    "emerald",
    "ruby-sapphire",
    "crystal",
    "gold-silver",
]


PT_SHORTENINGS = [
    (" o inimigo ", " inimigo "),
    (" o alvo ", " alvo "),
    (" o usuário ", " usuário "),
    (" ao alvo ", " ao rival "),
    (" do inimigo ", " do rival "),
    (" do alvo ", " do rival "),
    (" os inimigos ", " inimigos "),
    (" os alvos ", " alvos "),
    (" as estatísticas ", " os stats "),
    (" estatísticas ", " stats "),
    (" drasticamente ", " muito "),
    (" severamente ", " muito "),
    (" ligeiramente ", " levemente "),
    (" repetidamente ", " várias vezes "),
    (" continuamente ", " sem parar "),
    (" fisicamente ", " com força "),
    (" imediatamente ", " na hora "),
    (" enquanto ", " se "),
    (" durante ", " por "),
    (" também ", " e "),
    (" e então ", " e "),
    (" em batalha", ""),
    (" o HP ", " HP "),
    (" os PP ", " PP "),
    (" de HP", " de HP"),
    (" probabilidade de ", " chance de "),
    (" chance de causar ", " pode causar "),
    (" chance de deixar ", " pode deixar "),
    (" chance de reduzir ", " pode reduzir "),
    (" chance de aumentar ", " pode aumentar "),
    (" chance de ", " pode "),
    (" reduz a Velocidade ", " baixa a Velocidade "),
    (" reduz o Ataque ", " baixa o Ataque "),
    (" reduz a Defesa ", " baixa a Defesa "),
    (" reduz o Atq. Esp. ", " baixa o Atq. Esp. "),
    (" reduz a Def. Esp. ", " baixa a Def. Esp. "),
    (" aumenta a Velocidade ", " sobe a Velocidade "),
    (" aumenta o Ataque ", " sobe o Ataque "),
    (" aumenta a Defesa ", " sobe a Defesa "),
    (" aumenta o Atq. Esp. ", " sobe o Atq. Esp. "),
    (" aumenta a Def. Esp. ", " sobe a Def. Esp. "),
    (" aumenta muito ", " sobe muito "),
]


ES_SHORTENINGS = [
    (" el enemigo ", " enemigo "),
    (" el objetivo ", " rival "),
    (" el usuario ", " usuario "),
    (" del enemigo ", " del rival "),
    (" del objetivo ", " del rival "),
    (" los enemigos ", " enemigos "),
    (" los objetivos ", " rivales "),
    (" las estadísticas ", " los stats "),
    (" estadísticas ", " stats "),
    (" drásticamente ", " mucho "),
    (" severamente ", " mucho "),
    (" levemente ", " un poco "),
    (" repetidamente ", " varias veces "),
    (" continuamente ", " sin parar "),
    (" físicamente ", " con fuerza "),
    (" inmediatamente ", " al instante "),
    (" mientras ", " si "),
    (" durante ", " por "),
    (" también ", " y "),
    (" y luego ", " y "),
    (" en combate", ""),
    (" los PS ", " PS "),
    (" los PP ", " PP "),
    (" probabilidad de ", " posibilidad de "),
    (" posibilidad de causar ", " puede causar "),
    (" posibilidad de dejar ", " puede dejar "),
    (" posibilidad de reducir ", " puede bajar "),
    (" posibilidad de aumentar ", " puede subir "),
    (" posibilidad de ", " puede "),
    (" reduce la Velocidad ", " baja la Velocidad "),
    (" reduce el Ataque ", " baja el Ataque "),
    (" reduce la Defensa ", " baja la Defensa "),
    (" reduce el At. Esp. ", " baja el At. Esp. "),
    (" reduce la Def. Esp. ", " baja la Def. Esp. "),
    (" aumenta la Velocidad ", " sube la Velocidad "),
    (" aumenta el Ataque ", " sube el Ataque "),
    (" aumenta la Defensa ", " sube la Defensa "),
    (" aumenta el At. Esp. ", " sube el At. Esp. "),
    (" aumenta la Def. Esp. ", " sube la Def. Esp. "),
    (" aumenta mucho ", " sube mucho "),
]


TOKEN_FIXES = {
    "{PKMN} S": "{PKMN}S",
    "{PKMN} s": "{PKMN}s",
}


@dataclass
class MoveBlock:
    enum_name: str
    body: str
    start: int
    end: int


def load_cache() -> dict:
    if CACHE_PATH.exists():
        return json.loads(CACHE_PATH.read_text(encoding="utf-8"))
    return {"translations": {}, "pokeapi_moves": None}


def save_cache(cache: dict) -> None:
    CACHE_PATH.write_text(json.dumps(cache, ensure_ascii=False, indent=2), encoding="utf-8")


def http_get_json(url: str) -> dict:
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=30) as response:
        return json.load(response)


def http_get_text(url: str) -> str:
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=30) as response:
        return response.read().decode("utf-8")


def normalize_name(name: str) -> str:
    normalized = name.lower()
    replacements = {
        "é": "e",
        "’": "'",
        "‘": "'",
        "—": "-",
        "–": "-",
        ":": "",
        ".": "",
        ",": "",
        "%": " percent",
        " ": "",
        "-": "",
        "'": "",
    }
    for old, new in replacements.items():
        normalized = normalized.replace(old, new)
    return normalized


def slugify_name(name: str) -> str:
    slug = name.lower()
    replacements = {
        "é": "e",
        "♀": "-f",
        "♂": "-m",
        " ": "-",
        "’": "",
        "‘": "",
        "'": "",
        ".": "",
        ",": "",
        ":": "",
        ";": "",
        "!": "",
        "?": "",
        "(": "",
        ")": "",
        "/": "-",
        "—": "-",
        "–": "-",
        "%": "-percent",
    }
    for old, new in replacements.items():
        slug = slug.replace(old, new)
    slug = re.sub(r"-+", "-", slug).strip("-")
    return slug


def parse_c_string(arg_text: str) -> str:
    parts = re.findall(r'"((?:[^"\\]|\\.)*)"', arg_text, flags=re.S)
    value = "".join(parts)
    value = value.replace(r"\\", "\\")
    value = value.replace(r"\"", '"')
    value = value.replace(r"\n", "\n")
    value = value.replace(r"\t", "\t")
    return value


def load_shared_descriptions(text: str) -> dict[str, str]:
    consts: dict[str, str] = {}
    pattern = re.compile(r"static const u8 (s\w+Description)\[\] = _\((.*?)\);", re.S)
    for match in pattern.finditer(text):
        const_name = match.group(1)
        consts.setdefault(const_name, parse_c_string(match.group(2)).replace("\n", " "))
    return consts


def iter_move_blocks(text: str) -> list[MoveBlock]:
    pattern = re.compile(r"^    \[(MOVE_[A-Z0-9_]+)\]\s*=\n    \{(.*?)^    \},", re.S | re.M)
    return [MoveBlock(m.group(1), m.group(2), m.start(2), m.end(2)) for m in pattern.finditer(text)]


def extract_name(body: str) -> str | None:
    match = re.search(r"\.name = (?:COMPOUND_STRING|_)\((.*?)\),", body, re.S)
    return parse_c_string(match.group(1)) if match else None


def extract_description(body: str, shared_descs: dict[str, str]) -> str | None:
    match = re.search(r"\.description = COMPOUND_STRING\((.*?)\),", body, re.S)
    if match:
        return parse_c_string(match.group(1)).replace("\n", " ")
    match = re.search(r"\.description = (s\w+Description),", body)
    if match:
        return shared_descs.get(match.group(1))
    match = re.search(r"\.description = (?:COMPOUND_STRING|_)\((.*?)\),", body, re.S)
    if match:
        return parse_c_string(match.group(1)).replace("\n", " ")
    return None


def extract_localized_field(body: str, field_name: str) -> str | None:
    match = re.search(rf"\.{field_name} = COMPOUND_STRING\((.*?)\),", body, re.S)
    if not match:
        return None
    return parse_c_string(match.group(1)).replace("\n", " ")


def fix_tokens(text: str) -> str:
    text = text.replace("\\n", " ")
    text = re.sub(r"\s+", " ", text).strip()
    for old, new in TOKEN_FIXES.items():
        text = text.replace(old, new)
    return text


def translate_text(cache: dict, text: str, target_lang: str) -> str:
    text = fix_tokens(text)
    if text == "":
        return ""

    key = f"{target_lang}::{text}"
    if key in cache["translations"]:
        return cache["translations"][key]

    url = (
        "https://translate.googleapis.com/translate_a/single"
        f"?client=gtx&sl=en&tl={target_lang}&dt=t&q={urllib.parse.quote(text)}"
    )
    raw = http_get_text(url)
    payload = json.loads(raw)
    translated = "".join(chunk[0] for chunk in payload[0] if chunk and chunk[0])
    translated = fix_tokens(translated)
    cache["translations"][key] = translated
    return translated


def build_translation_map(cache: dict, texts: list[str], target_lang: str) -> dict[str, str]:
    normalized_texts = [fix_tokens(text) for text in texts if fix_tokens(text) != ""]
    unique_texts = list(dict.fromkeys(normalized_texts))
    result = {text: cache["translations"][f"{target_lang}::{text}"] for text in unique_texts if f"{target_lang}::{text}" in cache["translations"]}
    missing = [text for text in unique_texts if text not in result]

    if missing:
        def worker(text: str) -> tuple[str, str]:
            return text, translate_text(cache, text, target_lang)

        with concurrent.futures.ThreadPoolExecutor(max_workers=12) as executor:
            for text, translated in executor.map(worker, missing):
                result[text] = translated

    return result


def wrap_text(text: str) -> list[str]:
    words = text.split()
    if not words:
        return [""]

    lines: list[str] = []
    current = words[0]
    for word in words[1:]:
        candidate = f"{current} {word}"
        if len(candidate) <= LINE_LIMIT:
            current = candidate
        else:
            lines.append(current)
            current = word
    lines.append(current)
    return lines


def apply_shortenings(text: str, replacements: list[tuple[str, str]]) -> str:
    padded = f" {text} "
    for old, new in replacements:
        padded = padded.replace(old, new)
    return fix_tokens(padded)


def compress_text(text: str, lang: str) -> str:
    replacements = PT_SHORTENINGS if lang == "pt" else ES_SHORTENINGS
    text = fix_tokens(text)

    if len(wrap_text(text)) <= MAX_LINES:
        return text

    for _ in range(8):
        new_text = apply_shortenings(text, replacements)
        new_text = re.sub(r"\b(de|do|da|dos|das|del|la|el|los|las|um|uma|unos|unas)\b", "", new_text)
        new_text = fix_tokens(new_text)
        if new_text == text:
            break
        text = new_text
        if len(wrap_text(text)) <= MAX_LINES:
            return text

    words = text.split()
    guard = 0
    while len(wrap_text(" ".join(words))) > MAX_LINES and len(words) > 2 and guard < 64:
        guard += 1
        longest_index = max(range(len(words)), key=lambda i: len(words[i]))
        word = words[longest_index]
        if len(word) > 8:
            truncated_len = min(len(word) - 2, 6)
            words[longest_index] = word[:truncated_len] + "."
        else:
            del words[longest_index]

    return fix_tokens(" ".join(words))


def format_compound_string(value: str, indent: str) -> str:
    value = fix_tokens(value)
    lines = wrap_text(value)
    if len(lines) > MAX_LINES:
        compact = value[: LINE_LIMIT * MAX_LINES].strip()
        if len(compact) == LINE_LIMIT * MAX_LINES:
            compact = compact[:-1].rstrip(" ,;:.") + "."
        lines = textwrap.wrap(compact, width=LINE_LIMIT, break_long_words=True, break_on_hyphens=False)[:MAX_LINES]

    escaped = [line.replace("\\", "\\\\").replace('"', '\\"') for line in lines]
    if escaped == [""]:
        return 'COMPOUND_STRING("")'
    if len(escaped) == 1:
        return f'COMPOUND_STRING("{escaped[0]}")'

    return "COMPOUND_STRING(\n" + "".join(f'{indent}"{line}\\n"\n' for line in escaped[:-1]) + f'{indent}"{escaped[-1]}")'


def format_name_string(value: str) -> str:
    value = value.replace("\\", "\\\\").replace('"', '\\"')
    return f'COMPOUND_STRING("{value}")'


def fetch_spanish_name(entry: tuple[str, str]) -> tuple[str, str | None]:
    key, english_name = entry
    if english_name in ("", "-"):
        return key, None
    slug = slugify_name(english_name)
    url = f"https://pokeapi.co/api/v2/move/{slug}"
    try:
        detail = http_get_json(url)
    except Exception:
        return key, None

    if not isinstance(detail, dict) or "names" not in detail:
        return key, None

    es_name = next((name["name"] for name in detail["names"] if name["language"]["name"] == "es"), None)
    return key, es_name


def build_pokeapi_name_map(cache: dict, desired_names: dict[str, str]) -> dict[str, str]:
    cached = cache.get("pokeapi_moves")
    if cached and all(key in cached for key in desired_names):
        return cached

    mapping: dict[str, str] = cached or {}
    missing = {key: name for key, name in desired_names.items() if key not in mapping}
    if not missing:
        cache["pokeapi_moves"] = mapping
        return cache["pokeapi_moves"]

    with concurrent.futures.ThreadPoolExecutor(max_workers=16) as executor:
        for key, es_name in executor.map(fetch_spanish_name, missing.items()):
            if es_name:
                mapping[key] = es_name

    cache["pokeapi_moves"] = mapping
    return mapping


def update_block(body: str, name_es: str | None, desc_pt: str, desc_es: str) -> str:
    indent = "            "
    prefix = "\n" if body.startswith("\n") else ""
    stripped_body = body[1:] if prefix else body
    lines = stripped_body.splitlines(keepends=True)

    fields: list[str] = []
    current: list[str] = []
    for line in lines:
        if re.match(r"\s*\.", line):
            if current:
                fields.append("".join(current))
            current = [line]
        else:
            current.append(line)
    if current:
        fields.append("".join(current))

    rebuilt: list[str] = []
    for field in fields:
        stripped = field.lstrip()
        if stripped.startswith(".nameEs =") or stripped.startswith(".descriptionPt =") or stripped.startswith(".descriptionEs ="):
            continue

        rebuilt.append(field)

        if stripped.startswith(".name =") and name_es:
            rebuilt.append(f'        .nameEs = {format_name_string(name_es)},\n')
        elif stripped.startswith(".description ="):
            rebuilt.append(f'        .descriptionPt = {format_compound_string(desc_pt, indent)},\n')
            rebuilt.append(f'        .descriptionEs = {format_compound_string(desc_es, indent)},\n')

    return prefix + "".join(rebuilt)


def process(limit: int | None, dry_run: bool) -> None:
    debug = os.environ.get("DEBUG_MOVE_LOCALIZATION") == "1"
    text = MOVES_INFO_PATH.read_text(encoding="utf-8")
    if debug:
        print("loaded file", flush=True)
    shared_descs = load_shared_descriptions(text)
    if debug:
        print("loaded shared descriptions", flush=True)
    blocks = iter_move_blocks(text)
    if debug:
        print(f"loaded blocks: {len(blocks)}", flush=True)
    cache = load_cache()
    if debug:
        print("loaded cache", flush=True)
    desired_names = {}
    source_descriptions = []
    for index, block in enumerate(blocks):
        if limit is not None and index >= limit:
            break
        name_en = extract_name(block.body)
        if name_en and name_en != "-":
            desired_names[normalize_name(name_en)] = name_en
        desc_en = extract_description(block.body, shared_descs)
        if desc_en:
            source_descriptions.append(desc_en)
    if debug:
        print(f"desired names: {len(desired_names)}", flush=True)
    pokeapi_names = build_pokeapi_name_map(cache, desired_names)
    if debug:
        print(f"fetched pokeapi names: {len(pokeapi_names)}", flush=True)
    pt_translations = build_translation_map(cache, source_descriptions, "pt")
    es_translations = build_translation_map(cache, source_descriptions, "es")
    if debug:
        print(f"pt translations: {len(pt_translations)} / es translations: {len(es_translations)}", flush=True)

    rebuilt: list[str] = []
    cursor = 0
    processed = 0
    localized_names = 0
    exact_fallbacks = 0
    samples: list[tuple[str, str]] = []

    for block in blocks:
        rebuilt.append(text[cursor:block.start])
        body = block.body

        if limit is not None and processed >= limit:
            rebuilt.append(body)
            cursor = block.end
            continue

        name_en = extract_name(body)
        desc_en = extract_description(body, shared_descs)
        if name_en is None or desc_en is None:
            rebuilt.append(body)
            cursor = block.end
            continue

        existing_name_es = extract_localized_field(body, "nameEs")
        existing_desc_pt = extract_localized_field(body, "descriptionPt")
        existing_desc_es = extract_localized_field(body, "descriptionEs")

        es_name = pokeapi_names.get(normalize_name(name_en))
        if es_name and len(es_name) <= 12:
            localized_names += 1
        elif existing_name_es and len(existing_name_es) <= 12:
            es_name = existing_name_es
        else:
            es_name = None

        try:
            desc_pt = existing_desc_pt or compress_text(pt_translations.get(fix_tokens(desc_en), ""), "pt")
            desc_es = existing_desc_es or compress_text(es_translations.get(fix_tokens(desc_en), ""), "es")
        except Exception as exc:
            print(f"[warn] Falha ao traduzir {block.enum_name} ({name_en}): {exc}", file=sys.stderr)
            exact_fallbacks += 1
            rebuilt.append(body)
            cursor = block.end
            continue

        rebuilt.append(update_block(body, es_name, desc_pt, desc_es))
        if debug:
            print(f"processed {block.enum_name}", flush=True)
        if len(samples) < 5:
            samples.append((block.enum_name, rebuilt[-1]))
        cursor = block.end
        processed += 1

    rebuilt.append(text[cursor:])
    new_text = "".join(rebuilt)
    if debug:
        print("rebuilt text", flush=True)

    save_cache(cache)
    if debug:
        print("saved cache", flush=True)

    if dry_run:
        print(f"moves processados: {processed}")
        print(f"nameEs adicionados: {localized_names}")
        print(f"blocos mantidos por falha: {exact_fallbacks}")
        for enum_name, sample_body in samples:
            print("=" * 60)
            print(enum_name)
            print("\n".join(sample_body.splitlines()[:14]))
    else:
        MOVES_INFO_PATH.write_text(new_text, encoding="utf-8")
        print(f"moves processados: {processed}")
        print(f"nameEs adicionados: {localized_names}")
        print(f"blocos mantidos por falha: {exact_fallbacks}")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=None)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    process(limit=args.limit, dry_run=args.dry_run)


if __name__ == "__main__":
    main()
