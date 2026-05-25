#!/usr/bin/env python3
"""Visual editor and desktop preview for data/battle_anim_scripts.s.

The game executes many animation callbacks in C.  This tool preserves the
assembly source exactly, validates commands against its macro file, and
previews the script commands that can be represented with repository PNGs.
"""
from __future__ import annotations

import argparse
import math
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
import tkinter as tk
from tkinter import messagebox, simpledialog, ttk

try:
    from PIL import Image, ImageTk
except ImportError:
    Image = None
    ImageTk = None


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_PATH = ROOT / "data/battle_anim_scripts.s"
MACRO_PATH = ROOT / "asm/macros/battle_anim_script.inc"
ANIM_TABLE_PATH = ROOT / "src/data/battle_anim.h"
GRAPHICS_C_PATH = ROOT / "src/graphics.c"
POKEMON_PATH = ROOT / "graphics/pokemon"
PREVIEW_BACKGROUND = ROOT / "tools/BattlePreviewBackground.png"
SONGS_HEADER_PATH = ROOT / "include/constants/songs.h"
MIDI_PATH = ROOT / "sound/songs/midi"

TOP_LABEL_RE = re.compile(r"^(gBattleAnim(?:Move|General)_[A-Za-z0-9_]+)::?\s*(?:@.*)?$", re.M)
ANY_LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):{1,2}\s*(?:@.*)?$", re.M)
MACRO_RE = re.compile(r"^\s*\.macro\s+([A-Za-z_][A-Za-z0-9_]*)\s*(.*)$")
COMMAND_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*)\b(.*)$")
BRANCH_ARGUMENTS = {
    "call": 0,
    "goto": 0,
    "jumpifcontest": 0,
    "jumprettrue": 0,
    "jumpretfalse": 0,
    "jumpifdoublebattle": 0,
    "jumpifmoveturn": 1,
    "jumpargeq": 2,
    "jumpreteq": 1,
    "jumpifmovetypeequal": 1,
    "choosetwoturnanim": 0,
}
TASK_BACKGROUNDS = {
    "AnimTask_HeartsBackground": "_TASK_HEARTS_BACKGROUND",
    "AnimTask_LoadSandstormBackground": "_TASK_SANDSTORM_BACKGROUND",
    "AnimTask_LoadWindstormBackground": "_TASK_WINDSTORM_BACKGROUND",
}
MODELED_CALLBACKS = {
    "AnimAbsorptionOrb", "AnimAirWaveCrescent", "AnimAssistPawprint", "AnimBasicFistOrFoot",
    "AnimBite",
    "AnimBlastBurnTargetPlume", "AnimBubbleEffect", "AnimDirtPlumeParticle",
    "AnimDirtScatter", "AnimDizzyPunchDuck", "AnimElectricity", "AnimElectricPuff",
    "AnimEndureEnergy", "AnimFireCross", "AnimFireSpread", "AnimFireSpiralOutward",
    "AnimFallingRock", "AnimFlyUpTarget", "AnimFlyingSandCrescent", "AnimGrantingStars",
    "AnimGrowingChargeOrb", "AnimGrowingShockWaveOrb", "AnimGrowingShockWaveOrbOnTarget",
    "AnimHitSplatBasic", "AnimHitSplatHandleInvert", "AnimHitSplatPersistent",
    "AnimHyperBeamOrb", "AnimJumpKick", "AnimMissileArc", "AnimNeedleArmSpike",
    "AnimIceEffectParticle", "AnimIcePunchSwirlingParticle", "AnimJaggedMusicNote", "AnimLightning", "AnimMoveParticleBeyondTarget",
    "AnimMoveTwisterParticle", "AnimMudSportDirt", "AnimOrbitFast", "AnimOrbitScatter",
    "AnimParticleInVortex",
    "AnimOverheatFlame", "AnimPowerAbsorptionOrb", "AnimRazorLeafParticle", "AnimShadowBall",
    "AnimRockFragment", "AnimSludgeBombHitParticle", "AnimSludgeProjectile", "AnimSmallBubblePair", "AnimSparkElectricity",
    "AnimSparkElectricityFlashing", "AnimSweetScentPetal", "AnimTearDrop", "AnimTeraStarstormBeam",
    "AnimTeraStarstormStars", "AnimUproarRing", "AnimSwirlingSnowball", "AnimSwirlingSnowball_Step1",
    "AnimSlideHandOrFootToTarget", "AnimSpinningKickOrPunch", "AnimSpriteOnMonPos",
    "AnimStompFoot", "AnimThrowProjectile", "AnimToTargetInSinWave", "SpriteCB_Geyser",
    "SpriteCB_FallingObject", "SpriteCB_GeyserTarget", "SpriteCB_RandomCentredHits",
    "SpriteCB_SurroundingRing",
    "AnimTranslateLinearSingleSineWave", "TranslateAnimSpriteToTargetMonLocation",
}

SNIPPETS = {
    "Impacto simples": """\tloadspritegfx ANIM_TAG_HIT
\tplaysewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET
\tcreate_basic_hitsplat_sprite ANIM_TARGET, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=0
\tcreatevisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
\twaitforvisualfinish
""",
    "Projetil de energia": """\tloadspritegfx ANIM_TAG_ENERGY_BALL
\tcreatesprite gEnergyBallSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 0, 0, 24
\tdelay 24
\tcreate_basic_hitsplat_sprite ANIM_TARGET, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=1
\twaitforvisualfinish
""",
    "Cura brilhante": """\tloadspritegfx ANIM_TAG_GREEN_SPARKLE
\tplaysewithpan SE_M_MOONLIGHT, SOUND_PAN_ATTACKER
\tcreatesprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 2, -12, 0
\tdelay 12
\tcreatesprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 2, 12, -8
\twaitforvisualfinish
""",
    "Escurecer fundo": """\tsimple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=8, color=RGB_BLACK
\twaitforvisualfinish
""",
    "Restaurar fundo": """\tsimple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=8, target_blend_y=0, color=RGB_BLACK
\twaitforvisualfinish
""",
    "Agitar alvo": """\tcreatevisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 12, 1
\twaitforvisualfinish
""",
    "Pausa": """\tdelay 12
""",
}


@dataclass
class MacroSpec:
    name: str
    required: set[str]
    parameters: list[str]


@dataclass
class AnimBlock:
    label: str
    start: int
    end: int
    text: str

    @property
    def kind(self) -> str:
        return "Movimentos" if self.label.startswith("gBattleAnimMove_") else "Gerais"

    @property
    def short_name(self) -> str:
        return self.label.split("_", 1)[1] if "_" in self.label else self.label


@dataclass
class ValidationIssue:
    line: int
    message: str
    error: bool = True


@dataclass
class PreviewEvent:
    frame: int
    kind: str
    values: tuple[str, ...] = ()
    duration: int = 16


@dataclass
class BackgroundAsset:
    image: Path | None
    palette: Path | None
    tilemap: Path | None


@dataclass
class SpriteFrame:
    tile_offset: int
    duration: int
    hflip: bool = False
    vflip: bool = False


@dataclass
class SpriteSequence:
    frames: list[SpriteFrame]
    loops: bool = False


def split_args(value: str) -> list[str]:
    value = value.strip()
    if not value:
        return []
    args: list[str] = []
    current: list[str] = []
    depth = 0
    for char in value:
        if char == "," and depth == 0:
            args.append("".join(current).strip())
            current = []
            continue
        current.append(char)
        if char == "(":
            depth += 1
        elif char == ")":
            depth = max(0, depth - 1)
    args.append("".join(current).strip())
    expanded: list[str] = []
    for arg in args:
        if not arg:
            continue
        # GAS macros in this file are invoked with commas, whitespace, or a
        # mixture of both. Named expressions must remain one argument.
        if "=" not in arg and " " in arg and not any(op in arg for op in (" | ", " + ", " - ", " * ")):
            expanded.extend(part for part in arg.split() if part)
        else:
            expanded.append(arg)
    return expanded


def no_comment(line: str) -> str:
    return line.split("@", 1)[0].rstrip()


def parse_number(text: str, default: int = 0) -> int:
    clean = text.strip()
    if "=" in clean:
        clean = clean.split("=", 1)[1].strip()
    clean = re.sub(r"\bTRUE\b", "1", clean)
    clean = re.sub(r"\bFALSE\b", "0", clean)
    try:
        return int(clean, 0)
    except ValueError:
        if re.fullmatch(r"[\d\sxa-fA-F()+*/|&<>~-]+", clean):
            try:
                return int(eval(clean, {"__builtins__": {}}, {}))
            except (ValueError, SyntaxError, TypeError, ZeroDivisionError):
                pass
        return default


def parse_signed_number(text: str, default: int = 0) -> int:
    value = parse_number(text, default)
    return value - 0x10000 if value >= 0x8000 else value


def argument_number(args: list[str], name: str, positional: int, default: int = 0) -> int:
    for arg in args:
        if arg.strip().startswith(f"{name}="):
            return parse_number(arg, default)
    unnamed = [arg for arg in args if "=" not in arg]
    return parse_number(unnamed[positional], default) if len(unnamed) > positional else default


def signed_argument(args: list[str] | tuple[str, ...], positional: int, default: int = 0) -> int:
    return parse_signed_number(args[positional], default) if len(args) > positional else default


def is_attacker_selector(value: str, default: bool = False) -> bool:
    selector = value.split("=", 1)[-1].strip()
    if "TARGET" in selector or "OPPONENT" in selector:
        return False
    if "ATTACKER" in selector or "PLAYER" in selector:
        return True
    if re.fullmatch(r"[\d\sxa-fA-F()+*/|&<>~-]+", selector):
        return parse_signed_number(selector) == 0
    return default


def macro_q8_velocity(args: list[str] | tuple[str, ...], positional: int, default: int = 0) -> int:
    if len(args) <= positional:
        return default
    value = args[positional].split("=", 1)[-1].strip()
    match = re.fullmatch(r"(.+?)\s*/\s*256", value)
    return parse_signed_number(match.group(1), default) if match else signed_argument(args, positional, default)


def read_macros() -> dict[str, MacroSpec]:
    specs: dict[str, MacroSpec] = {}
    text = MACRO_PATH.read_text(encoding="utf-8", errors="replace")
    for line in text.splitlines():
        match = MACRO_RE.match(line)
        if not match:
            continue
        name, raw_args = match.groups()
        params: list[str] = []
        required: set[str] = set()
        for arg in re.split(r"[\s,]+", raw_args.strip()):
            if not arg:
                continue
            param = arg.split(":", 1)[0].split("=", 1)[0]
            params.append(param)
            if ":req" in arg:
                required.add(param)
        specs[name] = MacroSpec(name, required, params)
    return specs


def parse_blocks(text: str) -> list[AnimBlock]:
    matches = list(TOP_LABEL_RE.finditer(text))
    blocks: list[AnimBlock] = []
    for index, match in enumerate(matches):
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        blocks.append(AnimBlock(match.group(1), match.start(), end, text[match.start():end]))
    return blocks


def collect_engine_symbols() -> tuple[set[str], set[str]]:
    symbols: set[str] = set()
    tags: set[str] = set()
    paths = list(ROOT.glob("src/battle_anim*.c"))
    paths.extend([ANIM_TABLE_PATH, ROOT / "include/battle_anim.h", ROOT / "include/battle_anim_internal.h",
                  ROOT / "include/constants/battle_anim.h"])
    for path in paths:
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        symbols.update(re.findall(r"\b[A-Za-z_][A-Za-z0-9_]*\b", text))
        tags.update(re.findall(r"\bANIM_TAG_[A-Z0-9_]+\b", text))
    return symbols, tags


def validate_source(
    text: str,
    macros: dict[str, MacroSpec],
    engine_symbols: set[str] | None = None,
    valid_tags: set[str] | None = None,
) -> list[ValidationIssue]:
    issues: list[ValidationIssue] = []
    labels = {match.group(1) for match in ANY_LABEL_RE.finditer(text)}
    blocks = parse_blocks(text)
    for number, raw_line in enumerate(text.splitlines(), start=1):
        line = no_comment(raw_line).strip()
        if not line or line.startswith("#") or line.startswith(".") or line.endswith(":"):
            continue
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*\s*=", line):
            continue
        match = COMMAND_RE.match(line)
        if not match:
            issues.append(ValidationIssue(number, "Linha nao reconhecida."))
            continue
        command, tail = match.groups()
        if command not in macros:
            issues.append(ValidationIssue(number, f"Macro/comando desconhecido: {command}"))
            continue
        args = split_args(tail)
        named = {arg.split("=", 1)[0].strip() for arg in args if "=" in arg}
        positional = [arg for arg in args if "=" not in arg]
        spec = macros[command]
        supplied = named | set(spec.parameters[:len(positional)])
        absent = sorted(spec.required - supplied)
        if absent:
            issues.append(ValidationIssue(number, f"{command}: faltando argumento(s) {', '.join(absent)}"))
        if command in {"loadspritegfx", "unloadspritegfx"} and args and valid_tags is not None:
            tag = args[0].strip()
            if tag.startswith("ANIM_TAG_") and tag not in valid_tags:
                issues.append(ValidationIssue(number, f"Tag de grafico inexistente: {tag}"))
        if command in {"createsprite", "createspriteontargets", "createspriteontargets_onpos"} and args and engine_symbols is not None:
            template = args[0].strip()
            if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", template) and template not in engine_symbols:
                issues.append(ValidationIssue(number, f"Sprite template inexistente: {template}"))
        if command in {"createvisualtask", "createvisualtaskontargets"} and args and engine_symbols is not None:
            task = args[0].strip()
            if task.startswith("AnimTask_") and task not in engine_symbols:
                issues.append(ValidationIssue(number, f"AnimTask inexistente: {task}"))
        if command in BRANCH_ARGUMENTS:
            offset = BRANCH_ARGUMENTS[command]
            targets = positional[offset:] if command == "choosetwoturnanim" else positional[offset:offset + 1]
            for target in targets:
                target = target.strip()
                if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", target) and target not in labels:
                    issues.append(ValidationIssue(number, f"Label de destino inexistente: {target}"))
    if not blocks:
        issues.append(ValidationIssue(1, "Nenhuma animacao gBattleAnimMove_ ou gBattleAnimGeneral_ encontrada."))
    return issues


def backup(path: Path) -> Path:
    stamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    destination = path.with_suffix(path.suffix + f".battle_anim_editor_{stamp}.bak")
    shutil.copy2(path, destination)
    return destination


def collect_species() -> dict[str, dict[str, Path]]:
    species: dict[str, dict[str, Path]] = {}
    if not POKEMON_PATH.exists():
        return species
    for folder in sorted(POKEMON_PATH.iterdir()):
        if not folder.is_dir():
            continue
        front = folder / "anim_front.png"
        if not front.exists():
            front = folder / "front.png"
        back = folder / "back.png"
        if front.exists() or back.exists():
            species[folder.name.replace("_", " ").title()] = {"front": front, "back": back}
    return species


def load_boolean_defines() -> dict[str, bool]:
    defines: dict[str, bool] = {"TRUE": True, "FALSE": False}
    for path in (ROOT / "include/config/battle.h", ROOT / "include/config/general.h"):
        if not path.exists():
            continue
        for name, value in re.findall(r"^\s*#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+(TRUE|FALSE)\b", path.read_text(), re.M):
            defines[name] = defines[value]
    return defines


def collect_animation_assets() -> tuple[dict[str, Path], dict[str, Path]]:
    symbol_paths: dict[str, Path] = {}
    palette_paths: dict[str, Path] = {}
    if GRAPHICS_C_PATH.exists():
        c_text = GRAPHICS_C_PATH.read_text(encoding="utf-8", errors="replace")
        pattern = re.compile(r"(gBattleAnimSpriteGfx_[A-Za-z0-9_]+).*?\"([^\"]+)\.4bpp(?:\.smol)?\"")
        for symbol, path in pattern.findall(c_text):
            png = ROOT / f"{path}.png"
            if png.exists():
                symbol_paths[symbol] = png
        palette_pattern = re.compile(r"(gBattleAnimSpritePal_[A-Za-z0-9_]+).*?\"([^\"]+)\.(?:gbapal|pal)\"")
        for symbol, path in palette_pattern.findall(c_text):
            for suffix in (".gbapal", ".pal"):
                palette = ROOT / f"{path}{suffix}"
                if palette.exists():
                    palette_paths[symbol] = palette
                    break
    tags: dict[str, Path] = {}
    palettes: dict[str, Path] = {}
    if ANIM_TABLE_PATH.exists():
        table = ANIM_TABLE_PATH.read_text(encoding="utf-8", errors="replace")
        config = load_boolean_defines()
        for line in table.splitlines():
            tag_match = re.search(r"BATTLE_ANIMATION\((ANIM_TAG_[A-Z0-9_]+),", line)
            if not tag_match:
                continue
            symbols = re.findall(r"gBattleAnimSpriteGfx_[A-Za-z0-9_]+", line)
            conditional = re.search(
                r"([A-Z][A-Z0-9_]+)\s*==\s*TRUE\s*\?\s*(gBattleAnimSpriteGfx_[A-Za-z0-9_]+)\s*:\s*(gBattleAnimSpriteGfx_[A-Za-z0-9_]+)",
                line,
            )
            if conditional and conditional.group(1) in config:
                selected = conditional.group(2) if config[conditional.group(1)] else conditional.group(3)
                symbols = [selected] + [symbol for symbol in symbols if symbol != selected]
            for symbol in symbols:
                if symbol in symbol_paths:
                    tags[tag_match.group(1)] = symbol_paths[symbol]
                    break
            pal_symbols = re.findall(r"gBattleAnimSpritePal_[A-Za-z0-9_]+", line)
            pal_conditional = re.search(
                r"([A-Z][A-Z0-9_]+)\s*==\s*TRUE\s*\?\s*(gBattleAnimSpritePal_[A-Za-z0-9_]+)\s*:\s*(gBattleAnimSpritePal_[A-Za-z0-9_]+)",
                line,
            )
            if pal_conditional and pal_conditional.group(1) in config:
                selected = pal_conditional.group(2) if config[pal_conditional.group(1)] else pal_conditional.group(3)
                pal_symbols = [selected] + [symbol for symbol in pal_symbols if symbol != selected]
            for symbol in pal_symbols:
                if symbol in palette_paths:
                    palettes[tag_match.group(1)] = palette_paths[symbol]
                    break
    return tags, palettes


def collect_animation_graphics() -> dict[str, Path]:
    return collect_animation_assets()[0]


def collect_template_metadata() -> tuple[
    dict[str, str],
    dict[str, tuple[int, int]],
    dict[str, str],
    dict[str, str],
    dict[str, str],
    dict[str, tuple[str, int]],
]:
    tags: dict[str, str] = {}
    sizes: dict[str, tuple[int, int]] = {}
    wrappers: dict[str, str] = {}
    palette_tags: dict[str, str] = {}
    callbacks: dict[str, str] = {}
    animations: dict[str, tuple[str, int]] = {}
    pattern = re.compile(r"const\s+struct\s+SpriteTemplate\s+([A-Za-z_][A-Za-z0-9_]*)\s*=\s*\{(.*?)\};", re.S)
    for path in ROOT.glob("src/battle_anim*.c"):
        text = path.read_text(encoding="utf-8", errors="replace")
        for template, body in pattern.findall(text):
            tag_match = re.search(r"\.tileTag\s*=\s*(ANIM_TAG_[A-Z0-9_]+)", body)
            palette_match = re.search(r"\.paletteTag\s*=\s*(ANIM_TAG_[A-Z0-9_]+)", body)
            size_match = re.search(r"\.oam\s*=\s*&[A-Za-z0-9_]*_(\d+)x(\d+)", body)
            callback_match = re.search(r"\.callback\s*=\s*([A-Za-z_][A-Za-z0-9_]*)", body)
            anim_match = re.search(r"\.anims\s*=\s*&?([A-Za-z_][A-Za-z0-9_]*)(?:\[(\d+)\])?", body)
            if tag_match:
                tags[template] = tag_match.group(1)
            if palette_match:
                palette_tags[template] = palette_match.group(1)
            if size_match:
                sizes[template] = (int(size_match.group(1)), int(size_match.group(2)))
            if callback_match:
                callbacks[template] = callback_match.group(1)
            if anim_match:
                animations[template] = (anim_match.group(1), int(anim_match.group(2) or 0))
    macro_text = MACRO_PATH.read_text(encoding="utf-8", errors="replace")
    blocks = re.finditer(r"^\s*\.macro\s+([A-Za-z_][A-Za-z0-9_]*).*?$(.*?)(?=^\s*\.endm)", macro_text, re.M | re.S)
    for match in blocks:
        template = re.search(r"\bcreatesprite\s+(g[A-Za-z0-9_]*SpriteTemplate)\b", match.group(2))
        if template:
            wrappers[match.group(1)] = template.group(1)
    return tags, sizes, wrappers, palette_tags, callbacks, animations


def collect_sprite_anim_tables() -> dict[str, list[SpriteSequence]]:
    frame_lists: dict[str, SpriteSequence] = {}
    table_lists: dict[str, list[SpriteSequence]] = {}
    source = "\n".join(
        path.read_text(encoding="utf-8", errors="replace")
        for path in ROOT.glob("src/battle_anim*.c")
    )
    frame_pattern = re.compile(
        r"(?:static\s+)?const\s+union\s+AnimCmd\s+([A-Za-z_][A-Za-z0-9_]*)\s*\[\]\s*=\s*\{(.*?)\};",
        re.S,
    )
    for name, body in frame_pattern.findall(source):
        frames = []
        for raw_args in re.findall(r"ANIMCMD_FRAME\s*\((.*?)\)", body):
            args = split_args(raw_args)
            if len(args) < 2:
                continue
            frames.append(SpriteFrame(
                parse_number(args[0]),
                max(1, parse_number(args[1], 1)),
                "hFlip" in raw_args and "TRUE" in raw_args,
                "vFlip" in raw_args and "TRUE" in raw_args,
            ))
        if frames:
            frame_lists[name] = SpriteSequence(frames, "ANIMCMD_JUMP" in body)
    table_pattern = re.compile(
        r"(?:static\s+)?const\s+union\s+AnimCmd\s*\*const\s+([A-Za-z_][A-Za-z0-9_]*)\s*\[\]\s*=\s*\{(.*?)\};",
        re.S,
    )
    for name, body in table_pattern.findall(source):
        refs = re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*(?:Anim|AnimCmd|Cmd)[A-Za-z0-9_]*)\b", body)
        resolved = [frame_lists[ref] for ref in refs if ref in frame_lists]
        if resolved:
            table_lists[name] = resolved
    return table_lists


def collect_callback_sprite_rules() -> tuple[dict[str, int], dict[str, str]]:
    animation_args: dict[str, int] = {}
    placements: dict[str, str] = {}
    function_pattern = re.compile(
        r"(?:static\s+)?void\s+([A-Za-z_][A-Za-z0-9_]*)\s*\(\s*struct\s+Sprite\s*\*\s*sprite\s*\)\s*\{"
    )
    for path in ROOT.glob("src/battle_anim*.c"):
        text = path.read_text(encoding="utf-8", errors="replace")
        for match in function_pattern.finditer(text):
            depth = 1
            cursor = match.end()
            while cursor < len(text) and depth:
                depth += (text[cursor] == "{") - (text[cursor] == "}")
                cursor += 1
            body = text[match.end():cursor - 1]
            callback = match.group(1)
            attacker = re.search(r"InitSpritePosToAnimAttacker|SetSpriteCoordsToAnimAttackerCoords", body)
            target = re.search(r"InitSpritePosToAnimTarget", body)
            if attacker and (not target or attacker.start() < target.start()):
                placements[callback] = "attacker"
            elif target:
                placements[callback] = "target"
            direct = re.search(r"StartSpriteAnim\s*\(\s*sprite\s*,\s*gBattleAnimArgs\[(\d+)\]", body)
            if direct:
                animation_args[callback] = int(direct.group(1))
                continue
            named = re.search(r"StartSpriteAnim\s*\(\s*sprite\s*,\s*cmd->([A-Za-z_][A-Za-z0-9_]*)", body)
            cmd_args = re.search(r"CMD_ARGS\s*\((.*?)\)", body, re.S)
            if named and cmd_args:
                parameters = [part.strip() for part in split_args(cmd_args.group(1))]
                if named.group(1) in parameters:
                    animation_args[callback] = parameters.index(named.group(1))
    return animation_args, placements


def collect_background_assets() -> dict[str, BackgroundAsset]:
    source = GRAPHICS_C_PATH.read_text(encoding="utf-8", errors="replace")
    table = ANIM_TABLE_PATH.read_text(encoding="utf-8", errors="replace")
    symbols: dict[str, Path] = {}
    bg_symbol = r"gBattleAnimB[gG](?:Image|Palette|Tilemap)_[A-Za-z0-9_]+"
    for symbol, path in re.findall(rf"({bg_symbol}).*?\"([^\"]+)\"", source):
        raw = ROOT / path
        if "Image" in symbol:
            raw = raw.with_name(raw.name.split(".4bpp", 1)[0] + ".png")
        elif "Tilemap" in symbol:
            raw = raw.with_name(raw.name.split(".bin", 1)[0] + ".bin")
        symbols[symbol] = raw if raw.exists() else None
    backgrounds: dict[str, BackgroundAsset] = {}
    pattern = re.compile(r"\[(BG_[A-Z0-9_]+)\]\s*=\s*\{([^}]+)\}")
    for bg, values in pattern.findall(table):
        refs = re.findall(bg_symbol, values)
        if len(refs) >= 3:
            backgrounds[bg] = BackgroundAsset(symbols.get(refs[0]), symbols.get(refs[1]), symbols.get(refs[2]))
    directory = ROOT / "graphics/battle_anims/backgrounds"
    backgrounds["_TASK_HEARTS_BACKGROUND"] = BackgroundAsset(
        directory / "attract.png", directory / "attract.gbapal", directory / "attract.bin"
    )
    backgrounds["_TASK_SANDSTORM_BACKGROUND"] = BackgroundAsset(
        directory / "sandstorm_brew.png",
        ROOT / "graphics/battle_anims/sprites/flying_dirt.gbapal",
        directory / "sandstorm_brew.bin",
    )
    backgrounds["_TASK_WINDSTORM_BACKGROUND"] = BackgroundAsset(
        directory / "sandstorm_brew.png", directory / "windstorm_brew.gbapal", directory / "sandstorm_brew.bin"
    )
    backgrounds["_TASK_SURF_BACKGROUND"] = BackgroundAsset(
        directory / "water.png",
        ROOT / "graphics/battle_anims/sprites/surf_new.gbapal",
        directory / "water_player.bin",
    )
    backgrounds["_TASK_MUDDY_WATER_BACKGROUND"] = BackgroundAsset(
        directory / "water.png", directory / "water_muddy.gbapal", directory / "water_player.bin"
    )
    backgrounds["_TASK_SLUDGE_WAVE_BACKGROUND"] = BackgroundAsset(
        directory / "water.png", directory / "sludge_wave.gbapal", directory / "water_player.bin"
    )
    return backgrounds


def collect_sound_midis() -> dict[str, Path]:
    paths: dict[str, Path] = {}
    if not SONGS_HEADER_PATH.exists():
        return paths
    for name in re.findall(r"^\s*#define\s+(SE_[A-Z0-9_]+)\b", SONGS_HEADER_PATH.read_text(), re.M):
        candidate = MIDI_PATH / f"{name.lower()}.mid"
        if candidate.exists():
            paths[name] = candidate
    return paths


def gba_colors(path: Path | None) -> list[tuple[int, int, int]]:
    if path is None or not path.exists():
        return []
    if path.suffix == ".pal":
        values = [int(value) for value in re.findall(r"\b\d+\b", path.read_text(errors="replace"))]
        if len(values) >= 3:
            return [tuple(values[index:index + 3]) for index in range(0, len(values) - 2, 3)]
        return []
    data = path.read_bytes()
    colors = []
    for index in range(0, len(data) - 1, 2):
        value = int.from_bytes(data[index:index + 2], "little")
        colors.append((
            (value & 0x1F) * 255 // 31,
            ((value >> 5) & 0x1F) * 255 // 31,
            ((value >> 10) & 0x1F) * 255 // 31,
        ))
    return colors


def transparent_crop(
    path: Path,
    box: tuple[int, int, int, int],
    palette_path: Path | None = None,
    transparent_zero: bool = True,
):
    if Image is None:
        return None
    original = Image.open(path)
    if original.mode == "P":
        source = original.crop(box)
        indexes = list(source.getdata())
        colors = gba_colors(palette_path)
        if colors:
            alpha = Image.new("RGBA", source.size)
            alpha.putdata([
                (*colors[index % len(colors)], 0 if transparent_zero and index % 16 == 0 else 255)
                for index in indexes
            ])
            return alpha
        alpha = source.convert("RGBA")
        pixels = list(alpha.getdata())
        alpha.putdata([
            (r, g, b, 0 if transparent_zero and index == 0 else a)
            for (r, g, b, a), index in zip(pixels, indexes)
        ])
        return alpha
    return original.crop(box).convert("RGBA")


def transparent_first_frame(path: Path, maximum: int = 64):
    if Image is None:
        return None
    original = Image.open(path)
    return transparent_crop(path, (0, 0, min(maximum, original.width), min(maximum, original.height)))


def particle_frame(
    path: Path,
    size: tuple[int, int] | None,
    age: int,
    palette_path: Path | None = None,
    sequence: SpriteSequence | None = None,
    tile_adjustment: int = 0,
):
    if Image is None:
        return None
    original = Image.open(path)
    width, height = size or (min(original.width, 32), min(original.height, 32))
    width = min(width, original.width)
    height = min(height, original.height)
    tile_columns = max(1, original.width // 8)
    if sequence and sequence.frames:
        elapsed = max(0, age)
        cycle = sum(frame.duration for frame in sequence.frames)
        elapsed = elapsed % max(1, cycle) if sequence.loops else min(elapsed, max(0, cycle - 1))
        selected = sequence.frames[-1]
        for frame in sequence.frames:
            if elapsed < frame.duration:
                selected = frame
                break
            elapsed -= frame.duration
        tile_offset = selected.tile_offset + tile_adjustment
        x = (tile_offset % tile_columns) * 8
        y = (tile_offset // tile_columns) * 8
        image = transparent_crop(path, (x, y, x + width, y + height), palette_path)
        if selected.hflip:
            image = image.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        if selected.vflip:
            image = image.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
        return image
    # Templates without .anims use gDummySpriteAnimTable in the engine:
    # they stay on tile 0 rather than walking through the sprite sheet.
    x = (tile_adjustment % tile_columns) * 8
    y = (tile_adjustment // tile_columns) * 8
    return transparent_crop(path, (x, y, x + width, y + height), palette_path)


def remap_segmented_ice_asset(sequence: SpriteSequence | None) -> tuple[Path | None, SpriteSequence | None]:
    if not sequence or not sequence.frames:
        fallback = ROOT / "graphics/battle_anims/sprites/ice_crystals_0.png"
        return (fallback if fallback.exists() else None), sequence
    first_tile = sequence.frames[0].tile_offset
    if first_tile < 4:
        filename, base_tile = "ice_crystals_0.png", 0
    elif first_tile < 6:
        filename, base_tile = "ice_crystals_1.png", 4
    elif first_tile < 8:
        filename, base_tile = "ice_crystals_2.png", 6
    elif first_tile < 12:
        filename, base_tile = "ice_crystals_3.png", 8
    else:
        filename, base_tile = "ice_crystals_4.png", 12
    path = ROOT / "graphics/battle_anims/sprites" / filename
    rebased = SpriteSequence([
        SpriteFrame(frame.tile_offset - base_tile, frame.duration, frame.hflip, frame.vflip)
        for frame in sequence.frames
    ], sequence.loops)
    return (path if path.exists() else None), rebased


def render_background(asset: BackgroundAsset):
    if Image is None or asset.image is None or not asset.image.exists():
        return None
    tiles = Image.open(asset.image)
    if tiles.mode != "P" or asset.tilemap is None or not asset.tilemap.exists():
        return tiles.convert("RGBA").resize((240, 160), Image.Resampling.NEAREST)
    tilemap = asset.tilemap.read_bytes()
    palette = gba_colors(asset.palette)
    columns = max(1, tiles.width // 8)
    output = Image.new("RGBA", (240, 160), (0, 0, 0, 0))
    for row in range(20):
        for column in range(30):
            offset = (row * 32 + column) * 2
            if offset + 2 > len(tilemap):
                continue
            entry = int.from_bytes(tilemap[offset:offset + 2], "little")
            tile_index = entry & 0x3FF
            x = (tile_index % columns) * 8
            y = (tile_index // columns) * 8
            if x >= tiles.width or y >= tiles.height:
                continue
            tile = tiles.crop((x, y, x + 8, y + 8))
            indexes = list(tile.getdata())
            rgba = Image.new("RGBA", (8, 8))
            bank = (entry >> 12) & 0xF
            if palette:
                rgba.putdata([
                    (*palette[(bank * 16 + index) % len(palette)], 0 if index == 0 else 255)
                    for index in indexes
                ])
            else:
                rgba = transparent_crop(asset.image, (x, y, x + 8, y + 8))
            if entry & (1 << 10):
                rgba = rgba.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            if entry & (1 << 11):
                rgba = rgba.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
            output.alpha_composite(rgba, (column * 8, row * 8))
    return output


def scroll_background_frame(image, offset_x: int, offset_y: int):
    output = Image.new("RGBA", image.size, (0, 0, 0, 0))
    width, height = image.size
    for x_pos in (-width + offset_x, offset_x):
        for y_pos in (-height + offset_y, offset_y):
            output.alpha_composite(image, (x_pos, y_pos))
    return output


def preview_sprite_duration(callback: str, args: tuple[str, ...]) -> int:
    duration_index = {
        "AnimNeedleArmSpike": 4,
        "AnimParticleInVortex": 3,
        "AnimFireSpread": 4,
        "TranslateAnimSpriteToTargetMonLocation": 4,
        "AnimThrowProjectile": 4,
        "AnimMissileArc": 4,
    }.get(callback)
    if duration_index is not None:
        return max(8, abs(signed_argument(args, duration_index, 18)) + 1)
    if callback == "AnimFlyingSandCrescent":
        return 60
    if callback == "AnimPowerAbsorptionOrb":
        return max(8, abs(signed_argument(args, 2, 30)))
    if callback == "AnimToTargetInSinWave":
        return 30
    if callback == "AnimTranslateLinearSingleSineWave":
        return max(16, abs(signed_argument(args, 4, 22)) + 28)
    if callback == "AnimShadowBall":
        return max(8, sum(max(0, signed_argument(args, index)) for index in range(3)))
    if callback == "AnimRazorLeafParticle":
        return max(24, abs(signed_argument(args, 2, 10)) + 81)
    if callback == "AnimEndureEnergy":
        return 32
    if callback in {"AnimOrbitFast", "AnimOrbitScatter", "AnimFireSpiralOutward"}:
        return max(32, abs(signed_argument(args, 0, 32)))
    if callback in {"AnimSlideHandOrFootToTarget", "AnimJumpKick"}:
        return max(8, abs(signed_argument(args, 4, 18)))
    if callback == "AnimSpinningKickOrPunch":
        return max(8, abs(signed_argument(args, 3, 18)) + 20)
    if callback == "AnimStompFoot":
        return max(24, abs(signed_argument(args, 2, 0)) + 22)
    if callback == "AnimHyperBeamOrb":
        return 48
    if callback in {"AnimSparkElectricity", "AnimSparkElectricityFlashing"}:
        return max(8, abs(signed_argument(args, 3, 18)))
    if callback in {"AnimDirtPlumeParticle"}:
        return max(8, abs(signed_argument(args, 5, 18)))
    if callback in {"AnimFireCross", "AnimSmallBubblePair"}:
        return max(8, abs(signed_argument(args, 2, 18)))
    if callback in {"AnimAirWaveCrescent", "AnimAssistPawprint"}:
        return max(8, abs(signed_argument(args, 4, 18)))
    if callback in {"AnimMudSportDirt", "SpriteCB_Geyser", "SpriteCB_GeyserTarget", "AnimFlyUpTarget",
                    "AnimDizzyPunchDuck", "AnimDirtScatter"}:
        return 40
    if callback in {"AnimAbsorptionOrb"}:
        return max(8, abs(signed_argument(args, 3, 24)))
    if callback in {"AnimBlastBurnTargetPlume", "AnimRockFragment"}:
        return max(8, abs(signed_argument(args, 2 if callback == "AnimBlastBurnTargetPlume" else 4, 24)))
    if callback in {"AnimMoveTwisterParticle"}:
        return max(8, abs(signed_argument(args, 0, 24)))
    if callback in {"AnimGrantingStars"}:
        return max(8, abs(signed_argument(args, 5, 24)))
    if callback in {"AnimFallingRock", "AnimSweetScentPetal", "AnimLightning", "SpriteCB_RandomCentredHits"}:
        return 32
    if callback in {"AnimSludgeBombHitParticle"}:
        return max(8, abs(signed_argument(args, 2, 18)))
    if callback in {"AnimOverheatFlame"}:
        return max(8, abs(signed_argument(args, 3, 18)) + 1)
    if callback in {"AnimTearDrop"}:
        return 32
    if callback in {"AnimTeraStarstormBeam"}:
        return max(8, abs(signed_argument(args, 4, 18)))
    if callback in {"AnimTeraStarstormStars"}:
        return max(8, abs(signed_argument(args, 4, 18)))
    if callback in {"AnimMoveParticleBeyondTarget"}:
        return 62
    if callback in {"AnimSwirlingSnowball", "AnimSwirlingSnowball_Step1"}:
        return 68
    if callback in {"AnimSludgeProjectile"}:
        return max(8, abs(signed_argument(args, 2, 18)))
    if callback in {"AnimBubbleEffect", "AnimIceEffectParticle"}:
        return 32
    if callback == "AnimIcePunchSwirlingParticle":
        return 30
    if callback in {"AnimGrowingShockWaveOrb", "AnimGrowingShockWaveOrbOnTarget"}:
        return 24
    if callback in {"AnimJaggedMusicNote"}:
        return 17
    if callback in {"SpriteCB_FallingObject"}:
        return max(18, (abs(signed_argument(args, 1, -32)) // max(1, abs(signed_argument(args, 2, 2)))) + 20)
    if callback in {"SpriteCB_SurroundingRing"}:
        return 13
    if callback in {"AnimBasicFistOrFoot", "AnimSpriteOnMonPos", "AnimUproarRing"}:
        return max(8, abs(signed_argument(args, 2, 18)))
    if callback == "AnimBite":
        return max(8, abs(signed_argument(args, 5, 10)) * 2)
    return 18


def sprite_animation_index(
    callback: str,
    args: list[str] | tuple[str, ...],
    parsed_indices: dict[str, int] | None = None,
) -> int:
    index_arg = {
        "AnimBasicFistOrFoot": 4,
        "AnimSlideHandOrFootToTarget": 6,
        "AnimJumpKick": 6,
        "AnimSpinningKickOrPunch": 2,
        "AnimSolarBeamBigOrb": 3,
        "AnimSporeParticle": 4,
        "AnimFallingRock": 1,
        "AnimRockFragment": 5,
        "AnimSweetScentPetal": 1,
    }.get(callback)
    if index_arg is None and parsed_indices is not None:
        index_arg = parsed_indices.get(callback)
    return max(0, signed_argument(args, index_arg)) if index_arg is not None else 0


def parse_preview_program(text: str) -> tuple[list[tuple[str, list[str]]], dict[str, int]]:
    commands: list[tuple[str, list[str]]] = []
    labels: dict[str, int] = {}
    for raw in text.splitlines():
        line = no_comment(raw).strip()
        label_match = re.match(r"^([A-Za-z_][A-Za-z0-9_]*):{1,2}$", line)
        if label_match:
            labels.setdefault(label_match.group(1), len(commands))
            continue
        match = COMMAND_RE.match(line)
        if match and not line.startswith("."):
            commands.append((match.group(1), split_args(match.group(2))))
    return commands, labels


def emit_water_rain_events(events: list[PreviewEvent], frame: int, count: int, wide: bool = False):
    offsets = (0, 27, 11, 36, 19, 4, 31, 15, 38, 8, 24, 2, 34, 17, 29, 6, 21, 39, 13, 33)
    initial_x = 136 if wide else 185
    x_range = 98 if wide else 40
    end_base = 40
    for index in range(count):
        x = initial_x + offsets[index % len(offsets)] * x_range // 40
        end_y = end_base + (0, 10, -4, 13, 3, 15, -2, 8, 12, 1)[index % 10]
        drop_frame = frame + (index + 1) * 3
        duration = max(1, (end_y + 7) // 8)
        events.append(PreviewEvent(
            drop_frame, "task_drop",
            ("ANIM_TAG_GLOWY_BLUE_ORB", "gSmallWaterOrbSpriteTemplate", str(x), "0", str(end_y)),
            duration,
        ))
        events.append(PreviewEvent(
            drop_frame + duration, "task_hit",
            ("ANIM_TAG_WATER_IMPACT", "gWaterHitSplatSpriteTemplate", str(x), str(end_y)),
            24,
        ))
    events.append(PreviewEvent(frame + 6, "shake", ("ANIM_TARGET",), 12))


def emit_raindrop_events(events: list[PreviewEvent], frame: int, duration: int, interval: int):
    coordinates = ((18, 3), (82, 21), (144, 8), (208, 31), (50, 47), (174, 16), (115, 38), (228, 5))
    spawn = 1
    index = 0
    while spawn <= duration:
        x, y = coordinates[index % len(coordinates)]
        events.append(PreviewEvent(
            frame + spawn, "task_raindrop",
            ("ANIM_TAG_RAIN_DROPS", "gRainDropSpriteTemplate", str(x), str(y)),
            18,
        ))
        spawn += max(1, interval)
        index += 1


def build_preview_events(
    block_text: str,
    template_tags: dict[str, str] | None = None,
    wrapper_templates: dict[str, str] | None = None,
    template_callbacks: dict[str, str] | None = None,
    library_text: str = "",
) -> tuple[list[PreviewEvent], set[str]]:
    events: list[PreviewEvent] = []
    unsupported: set[str] = set()
    template_tags = template_tags or {}
    wrapper_templates = wrapper_templates or {}
    template_callbacks = template_callbacks or {}
    loaded: list[str] = []
    frame = 0
    program, labels = parse_preview_program(block_text + ("\n" + library_text if library_text else ""))
    stack: list[int] = []
    pc = 0
    steps = 0
    while pc < len(program) and steps < 8000:
        command, args = program[pc]
        pc += 1
        steps += 1
        if command == "delay" and args:
            frame += max(0, parse_number(args[0]))
        elif command == "loadspritegfx" and args:
            loaded.append(args[0].strip())
        elif command in {"createsprite", "createspriteontargets", "createspriteontargets_onpos"}:
            target = args[1] if len(args) > 1 else "ANIM_TARGET"
            template = args[0] if args else ""
            tag = template_tags.get(template, "")
            sprite_args = tuple(args[3:])
            if tag:
                duration = preview_sprite_duration(template_callbacks.get(template, ""), sprite_args)
                events.append(PreviewEvent(frame, "sprite", (tag, target, template, *sprite_args), duration))
            callback = template_callbacks.get(template)
            if callback and callback not in MODELED_CALLBACKS:
                unsupported.add(f"callback {callback}")
        elif (
            command in wrapper_templates
            and command not in {"simple_palette_blend", "complex_palette_blend"}
        ) or (command.startswith("create_") and command.endswith("_sprite")):
            target = args[0] if args else "ANIM_TARGET"
            template = wrapper_templates.get(command, "")
            tag = template_tags.get(template, "")
            sprite_args = tuple(args[2:])
            if tag:
                duration = preview_sprite_duration(template_callbacks.get(template, ""), sprite_args)
                events.append(PreviewEvent(frame, "sprite", (tag, target, template, *sprite_args), duration))
            callback = template_callbacks.get(template)
            if callback and callback not in MODELED_CALLBACKS:
                unsupported.add(f"callback {callback}")
        elif command in {"simple_palette_blend", "complex_palette_blend", "blend_color_cycle"}:
            events.append(PreviewEvent(frame, "flash", tuple(args), 18))
        elif command in {"fadetobg", "changebg"}:
            if args:
                events.append(PreviewEvent(frame, "background", (args[0],), 1))
        elif command == "fadetobgfromset":
            if args:
                events.append(PreviewEvent(frame, "background", (args[0],), 1))
        elif command == "restorebg":
            events.append(PreviewEvent(frame, "restore_background", (), 1))
        elif command == "create_surf_wave":
            palette = " ".join(args)
            if "MUDDY_WATER" in palette:
                background = "_TASK_MUDDY_WATER_BACKGROUND"
            elif "SLUDGE_WAVE" in palette:
                background = "_TASK_SLUDGE_WAVE_BACKGROUND"
            else:
                background = "_TASK_SURF_BACKGROUND"
            events.append(PreviewEvent(frame, "background", (background,), 1))
        elif command in {"invisible", "visible"}:
            target = args[0] if args else "ANIM_TARGET"
            events.append(PreviewEvent(frame, command, (target,), 1))
        elif command == "createvisualtask":
            task = args[0] if args else ""
            if "Shake" in task or "Squish" in task:
                target = next((arg for arg in args if "ANIM_" in arg), "ANIM_TARGET")
                events.append(PreviewEvent(frame, "shake", (target,), 16))
            elif task == "AnimTask_BrineRain":
                emit_water_rain_events(events, frame, 10)
            elif task == "AnimTask_WaterSpoutRain":
                emit_water_rain_events(events, frame, 15, wide=True)
            elif task == "AnimTask_CreateRaindrops":
                interval = parse_number(args[3], 3) if len(args) > 3 else 3
                duration = parse_number(args[4], 60) if len(args) > 4 else 60
                emit_raindrop_events(events, frame, duration, interval)
            elif task in TASK_BACKGROUNDS:
                events.append(PreviewEvent(frame, "background", (TASK_BACKGROUNDS[task],), 1))
            elif task == "AnimTask_StartSlidingBg":
                events.append(PreviewEvent(frame, "background_scroll", tuple(args[2:4]), 1))
            else:
                unsupported.add(task or command)
        elif command in {"playse", "playsewithpan", "panse", "panse_adjustnone", "panse_adjustall"} and args:
            events.append(PreviewEvent(frame, "sound", (args[0].strip(),), 1))
        elif command == "waitplaysewithpan" and args:
            events.append(PreviewEvent(frame, "sound", (args[0].strip(),), 1))
            if len(args) >= 3:
                frame += max(0, parse_number(args[2]))
        elif command == "loopsewithpan" and args:
            wait = max(1, parse_number(args[2], 1)) if len(args) >= 3 else 1
            times = max(1, parse_number(args[3], 1)) if len(args) >= 4 else 1
            events.extend(PreviewEvent(frame + wait * index, "sound", (args[0].strip(),), 1) for index in range(times))
        elif command == "stopsound":
            events.append(PreviewEvent(frame, "stop_sound", (), 1))
        elif command in {"waitforvisualfinish", "waitbgfadein", "waitbgfadeout", "waitsound"}:
            frame += 16
        elif command == "call" and args:
            target = args[0].strip()
            if target in labels:
                stack.append(pc)
                pc = labels[target]
            else:
                unsupported.add(f"call {target}")
        elif command == "return":
            if stack:
                pc = stack.pop()
            else:
                break
        elif command == "goto" and args:
            target = args[0].strip()
            if target in labels:
                pc = labels[target]
            else:
                unsupported.add(f"goto {target}")
                break
        elif command == "end":
            break
        elif command in {"loadspritegfx", "setalpha", "blendoff", "monbg", "clearmonbg",
                         "monbg_static", "clearmonbg_static", "splitbgprio", "splitbgprio_all",
                         "setarg", "jumpargeq", "jumpreteq"}:
            pass
        else:
            unsupported.add(command)
    if steps >= 8000:
        unsupported.add("loop excedeu limite da previa")
    return events, unsupported


class BattlePreview(ttk.Frame):
    def __init__(
        self,
        master,
        species: dict[str, dict[str, Path]],
        tag_graphics: dict[str, Path],
        tag_palettes: dict[str, Path],
        template_tags: dict[str, str],
        template_sizes: dict[str, tuple[int, int]],
        wrapper_templates: dict[str, str],
        template_palette_tags: dict[str, str],
        template_callbacks: dict[str, str],
        template_animations: dict[str, tuple[str, int]],
        sprite_anim_tables: dict[str, list[SpriteSequence]],
        callback_animation_args: dict[str, int],
        callback_placements: dict[str, str],
        background_assets: dict[str, BackgroundAsset],
        sound_midis: dict[str, Path],
    ):
        super().__init__(master)
        self.species = species
        self.tag_graphics = tag_graphics
        self.tag_palettes = tag_palettes
        self.template_tags = template_tags
        self.template_sizes = template_sizes
        self.wrapper_templates = wrapper_templates
        self.template_palette_tags = template_palette_tags
        self.template_callbacks = template_callbacks
        self.template_animations = template_animations
        self.sprite_anim_tables = sprite_anim_tables
        self.callback_animation_args = callback_animation_args
        self.callback_placements = callback_placements
        self.background_assets = background_assets
        self.background_images: dict[str, object] = {}
        self.sound_midis = sound_midis
        self.events: list[PreviewEvent] = []
        self.frame = 0
        self.last_frame = 0
        self.play_job = None
        self.audio_processes: list[subprocess.Popen] = []
        self.played_sound_events: set[int] = set()
        self.photos: dict[str, object] = {}
        self.hidden: set[str] = set()
        self.sound_var = tk.BooleanVar(value=True)
        names = list(species)
        default_attacker = next((name for name in names if name.lower() == "pikachu"), names[0] if names else "")
        default_target = next((name for name in names if name.lower() == "bulbasaur"), names[0] if names else "")
        self.attacker_var = tk.StringVar(value=default_attacker)
        self.target_var = tk.StringVar(value=default_target)
        controls = ttk.Frame(self)
        controls.pack(fill="x", pady=(0, 4))
        ttk.Label(controls, text="Atacante:").pack(side="left")
        attacker = ttk.Combobox(controls, textvariable=self.attacker_var, values=names, width=19, state="readonly")
        attacker.pack(side="left", padx=(4, 12))
        ttk.Label(controls, text="Alvo:").pack(side="left")
        target = ttk.Combobox(controls, textvariable=self.target_var, values=names, width=19, state="readonly")
        target.pack(side="left", padx=4)
        ttk.Checkbutton(controls, text="Som", variable=self.sound_var).pack(side="left", padx=(10, 0))
        attacker.bind("<<ComboboxSelected>>", lambda _event: self.render())
        target.bind("<<ComboboxSelected>>", lambda _event: self.render())
        self.canvas = tk.Canvas(self, width=480, height=320, background="#101418", highlightthickness=0)
        self.canvas.pack(anchor="w", expand=False)
        self.status = ttk.Label(self, text="Selecione uma animacao e use Play Anim.")
        self.status.pack(fill="x", pady=(4, 0))

    def stop(self):
        if self.play_job is not None:
            self.after_cancel(self.play_job)
            self.play_job = None
        self.stop_sounds()

    def play(self, text: str, library_text: str = ""):
        self.stop()
        self.events, unsupported = build_preview_events(
            text, self.template_tags, self.wrapper_templates, self.template_callbacks, library_text
        )
        self.frame = 0
        self.hidden.clear()
        self.played_sound_events.clear()
        self.last_frame = max([event.frame + event.duration for event in self.events] + [30])
        missing_sounds = sorted({
            event.values[0] for event in self.events
            if event.kind == "sound" and event.values[0] not in self.sound_midis
        })
        note = ""
        if unsupported:
            sample = ", ".join(sorted(unsupported)[:4])
            note = f" | simulacao parcial: {sample}"
        if missing_sounds:
            note += f" | sem MIDI: {', '.join(missing_sounds[:3])}"
        self.status.configure(text=f"Reproduzindo {len(self.events)} eventos{note}")
        self.tick()

    def tick(self):
        for index, event in enumerate(self.events):
            if event.kind == "sound" and event.frame == self.frame and index not in self.played_sound_events:
                self.played_sound_events.add(index)
                self.play_sound(event.values[0])
            elif event.kind == "stop_sound" and event.frame == self.frame and index not in self.played_sound_events:
                self.played_sound_events.add(index)
                self.stop_sounds()
        self.render()
        self.frame += 1
        if self.frame <= self.last_frame:
            self.play_job = self.after(17, self.tick)
        else:
            self.play_job = None
            self.status.configure(text="Animacao concluida. Tarefas C complexas aparecem como simulacao parcial.")

    def play_sound(self, symbol: str):
        if not self.sound_var.get():
            return
        path = self.sound_midis.get(symbol)
        if not path:
            return
        if shutil.which("timidity"):
            command = ["timidity", "-idq", str(path)]
        elif shutil.which("ffplay"):
            command = ["ffplay", "-nodisp", "-autoexit", "-loglevel", "quiet", str(path)]
        else:
            return
        self.audio_processes = [process for process in self.audio_processes if process.poll() is None]
        self.audio_processes.append(subprocess.Popen(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL))

    def stop_sounds(self):
        for process in self.audio_processes:
            if process.poll() is None:
                process.terminate()
        self.audio_processes.clear()

    def image_photo(self, key: str, image):
        if ImageTk is None:
            return None
        image = image.resize((image.width * 2, image.height * 2), Image.Resampling.NEAREST)
        photo = ImageTk.PhotoImage(image)
        self.photos[key] = photo
        return photo

    def draw_mon(self, role: str, x: int, y: int, offset: int):
        if role in self.hidden or Image is None or ImageTk is None:
            return
        name = self.attacker_var.get() if role == "ANIM_ATTACKER" else self.target_var.get()
        paths = self.species.get(name, {})
        path = paths.get("back" if role == "ANIM_ATTACKER" else "front")
        if path and path.exists():
            image = transparent_first_frame(path)
            photo = self.image_photo(role, image)
            self.canvas.create_image((x + offset) * 2, y * 2, image=photo, anchor="nw")
        else:
            self.canvas.create_text(x * 2, y * 2, text=role, fill="white", anchor="nw")

    @staticmethod
    def battler_position(battler: str, attacker: tuple[int, int], target: tuple[int, int]) -> tuple[int, int]:
        if "ATTACKER" in battler or "PLAYER" in battler:
            return attacker
        return target

    def sprite_position(self, event: PreviewEvent) -> tuple[int, int]:
        _tag, anim_battler, template, *args = event.values
        callback = self.template_callbacks.get(template, "")
        age = max(0, self.frame - event.frame)
        progress = min(1.0, age / max(1, event.duration - 1))
        attacker = (88, 105)
        target_pos = (185, 55)
        # CreateSpriteAndAnimate initially creates battle anim sprites at the
        # target; callbacks may explicitly reposition them to the attacker.
        base = target_pos
        x = signed_argument(args, 0)
        y = signed_argument(args, 1)

        if callback in {"AnimHitSplatBasic", "AnimHitSplatHandleInvert", "AnimHitSplatPersistent"}:
            base = attacker if len(args) > 2 and is_attacker_selector(args[2]) else target_pos
            return (base[0] + x, base[1] + y)
        if callback == "AnimBasicFistOrFoot":
            base = attacker if len(args) > 3 and is_attacker_selector(args[3]) else target_pos
            return (base[0] + x, base[1] + y)
        if callback in {"AnimSpriteOnMonPos", "AnimUproarRing"}:
            base = attacker if len(args) > 2 and is_attacker_selector(args[2]) else target_pos
            return (base[0] + x, base[1] + y)
        if callback in {"AnimGrowingChargeOrb", "AnimElectricPuff"}:
            base = attacker if args and is_attacker_selector(args[0]) else target_pos
            return (base[0] + signed_argument(args, 1), base[1] + signed_argument(args, 2))
        if callback == "AnimGrowingShockWaveOrb":
            return attacker
        if callback == "AnimGrowingShockWaveOrbOnTarget":
            return target_pos
        if callback == "AnimBite":
            duration = max(1, abs(signed_argument(args, 5, 10)))
            elapsed = min(age, duration * 2)
            travel = elapsed if elapsed <= duration else duration * 2 - elapsed
            return (target_pos[0] + x + macro_q8_velocity(args, 3) * travel // 256,
                    target_pos[1] + y + macro_q8_velocity(args, 4) * travel // 256)
        if callback == "AnimIcePunchSwirlingParticle":
            angle = (signed_argument(args, 0) + age * 9) * math.pi / 128
            radius = max(0, 30 - age)
            return (target_pos[0] + int(math.sin(angle) * radius),
                    target_pos[1] + int(math.cos(angle) * radius))
        if callback == "AnimElectricity":
            base = attacker if len(args) > 4 and is_attacker_selector(args[4]) else target_pos
            return (base[0] + x, base[1] + y)
        if callback == "AnimSparkElectricity":
            base = attacker if len(args) > 4 and is_attacker_selector(args[4]) else target_pos
            angle = signed_argument(args, 0) * math.pi / 128
            radius = signed_argument(args, 1)
            return (base[0] + int(math.sin(angle) * radius),
                    base[1] + int(math.cos(angle) * radius))
        if callback == "AnimSparkElectricityFlashing":
            target_flag = signed_argument(args, 7) & 0x8000
            base = target_pos if target_flag else attacker
            angle = (signed_argument(args, 4) + age * signed_argument(args, 5)) * math.pi / 128
            radius = signed_argument(args, 2)
            return (base[0] + x + int(math.sin(angle) * radius),
                    base[1] + y + int(math.cos(angle) * radius))
        if callback == "AnimNeedleArmSpike":
            center = attacker if args and is_attacker_selector(args[0]) else target_pos
            end = (center[0] + signed_argument(args, 2), center[1] + signed_argument(args, 3))
            start, finish = (end, center) if signed_argument(args, 1) == 0 else (center, end)
            return (
                start[0] + int((finish[0] - start[0]) * progress),
                start[1] + int((finish[1] - start[1]) * progress),
            )
        if callback == "AnimParticleInVortex":
            center = attacker if len(args) > 6 and is_attacker_selector(args[6]) else target_pos
            angle = (signed_argument(args, 5) + age * signed_argument(args, 4, 8)) * math.pi / 128
            radius = abs(signed_argument(args, 5, 24)) or 24
            vertical = -(age * signed_argument(args, 2) // 256)
            return (center[0] + x + int(math.sin(angle) * radius), center[1] + y + vertical)
        if callback == "AnimFireSpread":
            return (
                target_pos[0] + x + signed_argument(args, 2) * age // 256,
                target_pos[1] + y + signed_argument(args, 3) * age // 256,
            )
        if callback == "AnimFireCross":
            return (target_pos[0] + x + signed_argument(args, 3) * age,
                    target_pos[1] + y + signed_argument(args, 4) * age)
        if callback == "AnimFlyingSandCrescent":
            return (
                -32 + signed_argument(args, 1) * age // 256,
                signed_argument(args, 0, 55) + signed_argument(args, 2) * age // 256,
            )
        if callback == "AnimPowerAbsorptionOrb":
            start = (attacker[0] + x, attacker[1] + y)
            return (
                start[0] + int((attacker[0] - start[0]) * progress),
                start[1] + int((attacker[1] - start[1]) * progress),
            )
        if callback in {"AnimSlideHandOrFootToTarget", "AnimJumpKick"}:
            start = (attacker[0] + x, attacker[1] + y)
            finish = (target_pos[0] + signed_argument(args, 2), target_pos[1] + signed_argument(args, 3))
            return (start[0] + int((finish[0] - start[0]) * progress),
                    start[1] + int((finish[1] - start[1]) * progress))
        if callback == "AnimSpinningKickOrPunch":
            return (target_pos[0] + x, target_pos[1] + y)
        if callback == "AnimStompFoot":
            wait = max(0, signed_argument(args, 2))
            drop = min(1.0, max(0, age - wait) / 6)
            return (target_pos[0] + x, target_pos[1] + y - int((1 - drop) * 20))
        if callback == "AnimRazorLeafParticle":
            climb = max(0, signed_argument(args, 2))
            if age <= climb:
                return (attacker[0] + signed_argument(args, 0) * age,
                        attacker[1] + signed_argument(args, 1) * age)
            later = age - climb
            initial = (attacker[0] + signed_argument(args, 0) * climb,
                       attacker[1] + signed_argument(args, 1) * climb)
            phase = (128 if signed_argument(args, 1) & 1 else 0) + later * 2
            return (initial[0] + int(math.sin(phase * math.pi / 128) * 25),
                    initial[1] + later // 2)
        if callback == "AnimFlyUpTarget":
            return (target_pos[0] + x, target_pos[1] + y + 24 - signed_argument(args, 3, 2) * age)
        if callback == "AnimTranslateLinearSingleSineWave":
            start = (attacker[0] + x, attacker[1] + y)
            duration = max(1, abs(signed_argument(args, 4, 22)))
            part = min(1.0, age / duration)
            finish = (target_pos[0] + signed_argument(args, 2), target_pos[1] + signed_argument(args, 3))
            return (start[0] + int((finish[0] - start[0]) * part),
                    start[1] + int((finish[1] - start[1]) * part)
                    - int(math.sin(part * math.pi) * signed_argument(args, 5)))
        if callback == "AnimAirWaveCrescent":
            start = (attacker[0] + x, attacker[1] + y)
            finish = (target_pos[0] + signed_argument(args, 2), target_pos[1] + signed_argument(args, 3))
            return (start[0] + int((finish[0] - start[0]) * progress),
                    start[1] + int((finish[1] - start[1]) * progress))
        if callback == "AnimAssistPawprint":
            return (signed_argument(args, 0) + int((signed_argument(args, 2) - signed_argument(args, 0)) * progress),
                    signed_argument(args, 1) + int((signed_argument(args, 3) - signed_argument(args, 1)) * progress))
        if callback == "AnimDirtPlumeParticle":
            center = attacker if args and is_attacker_selector(args[0]) else target_pos
            side = -24 if signed_argument(args, 1) == 1 else 24
            start = (center[0] + side, center[1] + 30)
            finish = (start[0] + signed_argument(args, 2), start[1] + signed_argument(args, 3))
            part = min(1.0, age / max(1, abs(signed_argument(args, 5, 18))))
            return (start[0] + int((finish[0] - start[0]) * part),
                    start[1] + int((finish[1] - start[1]) * part)
                    - int(math.sin(part * math.pi) * signed_argument(args, 4)))
        if callback == "AnimDirtScatter":
            duration = max(1, signed_argument(args, 2, 18))
            part = min(1.0, age / duration)
            start = (attacker[0] + x, attacker[1] + y)
            return (start[0] + int((target_pos[0] - start[0]) * part),
                    start[1] + int((target_pos[1] - start[1]) * part))
        if callback in {"AnimMudSportDirt", "SpriteCB_Geyser", "SpriteCB_GeyserTarget"}:
            center = target_pos if callback == "SpriteCB_GeyserTarget" else attacker
            arg_offset = 1 if callback.startswith("SpriteCB_") else 1
            start = (center[0] + signed_argument(args, arg_offset), center[1] + signed_argument(args, arg_offset + 1))
            direction = 1 if signed_argument(args, arg_offset) > 0 else -1
            return (start[0] + direction * age // 2, start[1] - age * 4)
        if callback == "AnimSmallBubblePair":
            center = attacker if len(args) > 3 and is_attacker_selector(args[3]) else target_pos
            return (center[0] + x + int(math.sin(age * 11 * math.pi / 128) * 4),
                    center[1] + y - age * 48 // 256)
        if callback == "AnimDizzyPunchDuck":
            return (target_pos[0] + x + signed_argument(args, 2) * age // 256,
                    target_pos[1] + y + int(math.sin(age * 3 * math.pi / 128) * signed_argument(args, 3)))
        if callback == "AnimAbsorptionOrb":
            start = (target_pos[0] + x, target_pos[1] + y)
            duration = max(1, abs(signed_argument(args, 3, 24)))
            part = min(1.0, age / duration)
            return (start[0] + int((attacker[0] - start[0]) * part),
                    start[1] + int((attacker[1] - start[1]) * part)
                    - int(math.sin(part * math.pi) * signed_argument(args, 2)))
        if callback == "AnimSludgeBombHitParticle":
            duration = max(1, abs(signed_argument(args, 2, 20)))
            part = min(1.0, age / duration)
            return (target_pos[0] + int(signed_argument(args, 0) * part),
                    target_pos[1] + int(signed_argument(args, 1) * part))
        if callback == "AnimSludgeProjectile":
            duration = max(1, abs(signed_argument(args, 2, 20)))
            part = min(1.0, age / duration)
            start = (attacker[0] + x, attacker[1] + y)
            return (start[0] + int((target_pos[0] - start[0]) * part),
                    start[1] + int((target_pos[1] - start[1]) * part)
                    - int(math.sin(part * math.pi) * 30))
        if callback == "AnimBubbleEffect":
            return (target_pos[0] + x + int(math.sin(age * 11 * math.pi / 128) * 4),
                    target_pos[1] + y - age * 48 // 256)
        if callback == "AnimIceEffectParticle":
            return (target_pos[0] + x, target_pos[1] + y)
        if callback == "AnimTearDrop":
            tear_type = signed_argument(args, 1)
            base = attacker if args and is_attacker_selector(args[0]) else target_pos
            is_left = tear_type in {2, 3}
            start_x = base[0] + (-14 if is_left else 14)
            start_y = base[1] - (8 if tear_type in {0, 2} else 0)
            part = min(1.0, age / 32)
            distance = -20 if is_left else 20
            return (start_x + int(distance * part),
                    start_y + int(12 * part) - int(math.sin(part * math.pi) * 12))
        if callback == "AnimOverheatFlame":
            speed = signed_argument(args, 0, 1)
            angle = signed_argument(args, 1) * math.pi / 128
            radius = signed_argument(args, 2, 30)
            dx = int(math.cos(angle) * radius)
            dy = int(math.sin(angle) * ((radius * 3) // 5))
            return (attacker[0] + dx * speed + dx * age // 10,
                    attacker[1] + signed_argument(args, 4) + dy * speed + dy * age // 10)
        if callback == "AnimMoveParticleBeyondTarget":
            start = (attacker[0] + x, attacker[1] + y)
            via = (target_pos[0] + signed_argument(args, 2),
                   target_pos[1] + signed_argument(args, 3))
            part = min(1.0, age / max(1, event.duration - 1))
            end = (start[0] + int((via[0] - start[0]) * 2.25),
                   start[1] + int((via[1] - start[1]) * 2.25))
            wave = int(math.sin(age * signed_argument(args, 6, 4) * math.pi / 128)
                       * signed_argument(args, 5))
            return (start[0] + int((end[0] - start[0]) * part),
                    start[1] + int((end[1] - start[1]) * part) + wave)
        if callback in {"AnimSwirlingSnowball", "AnimSwirlingSnowball_Step1"}:
            entrance = min(1.0, age / 18)
            center = (target_pos[0] + signed_argument(args, 2),
                      target_pos[1] + signed_argument(args, 3))
            start = (attacker[0] + x, attacker[1] + y)
            if age < 18:
                return (start[0] + int((center[0] - start[0]) * entrance),
                        start[1] + int((center[1] - start[1]) * entrance))
            angle = (128 + (age - 18) * 16) * math.pi / 128
            return (center[0] + int(math.sin(angle) * -20),
                    center[1] + int(math.cos(angle) * 15))
        if callback == "AnimJaggedMusicNote":
            center = attacker if args and is_attacker_selector(args[0]) else target_pos
            return (center[0] + signed_argument(args, 1) * (8 + age) // 8,
                    center[1] + signed_argument(args, 2) * (8 + age) // 8)
        if callback == "AnimTeraStarstormBeam":
            start = (attacker[0] + x + 4, attacker[1] + y - 30)
            finish = (target_pos[0], target_pos[1] - 70)
            return (start[0] + int((finish[0] - start[0]) * progress),
                    start[1] + int((finish[1] - start[1]) * progress))
        if callback == "AnimTeraStarstormStars":
            start = (attacker[0] + x + 4, attacker[1] + y - 100)
            finish = (target_pos[0] + signed_argument(args, 2),
                      target_pos[1] + signed_argument(args, 3))
            return (start[0] + int((finish[0] - start[0]) * progress),
                    start[1] + int((finish[1] - start[1]) * progress))
        if callback == "SpriteCB_FallingObject":
            center = attacker if len(args) > 3 and is_attacker_selector(args[3]) else target_pos
            fall_height = abs(signed_argument(args, 1, -32))
            speed = max(1, abs(signed_argument(args, 2, 2)))
            drop = min(fall_height, age * speed)
            return (center[0] + x, center[1] - fall_height + drop)
        if callback == "SpriteCB_SurroundingRing":
            part = min(1.0, age / 13)
            return (attacker[0], attacker[1] + 40 - int(72 * part))
        if callback == "AnimMoveTwisterParticle":
            angle = age * signed_argument(args, 2, 8) * math.pi / 128
            return (target_pos[0] + int(math.cos(angle) * signed_argument(args, 3, 16)),
                    target_pos[1] + 32 - min(age * 2, signed_argument(args, 1, 32))
                    + int(math.sin(angle) * 5))
        if callback == "AnimGrantingStars":
            center = attacker if len(args) > 2 and is_attacker_selector(args[2]) else target_pos
            return (center[0] + x + signed_argument(args, 3) * age // 256,
                    center[1] + y + signed_argument(args, 4) * age // 256)
        if callback == "AnimRockFragment":
            duration = max(1, signed_argument(args, 4, 18))
            part = min(1.0, age / duration)
            return (target_pos[0] + x + int(signed_argument(args, 2) * part),
                    target_pos[1] + y + int(signed_argument(args, 3) * part))
        if callback == "AnimFallingRock":
            angle = age * math.pi / 16
            return (target_pos[0] + x + int(math.sin(angle) * 16) + signed_argument(args, 2) * age // 16,
                    target_pos[1] + 14 - int(math.cos(angle) * 35))
        if callback == "AnimBlastBurnTargetPlume":
            return (target_pos[0] + x + signed_argument(args, 4) * age,
                    target_pos[1] + y + signed_argument(args, 5) * age)
        if callback == "AnimSweetScentPetal":
            return (age * 5, signed_argument(args, 0) - age + int(math.sin(age * 3 * math.pi / 128) * 16))
        if callback in {"AnimLightning", "SpriteCB_RandomCentredHits"}:
            center = attacker if args and is_attacker_selector(args[0]) else target_pos
            return (center[0] + x, center[1] + y)
        if callback == "AnimEndureEnergy":
            center = attacker if args and is_attacker_selector(args[0]) else target_pos
            return (center[0] + signed_argument(args, 1), center[1] + signed_argument(args, 2) - age // 2)
        if callback in {"AnimOrbitFast", "AnimOrbitScatter"}:
            angle = (signed_argument(args, 1 if callback == "AnimOrbitFast" else 0) + age * 9) * math.pi / 128
            radius = min(40, age * 3) if callback == "AnimOrbitFast" else 10 + age
            return (attacker[0] + int(math.sin(angle) * radius),
                    attacker[1] + int(math.cos(angle) * radius * 0.7))
        if callback == "AnimFireSpiralOutward":
            wait = max(0, signed_argument(args, 3))
            elapsed = max(0, age - wait)
            angle = elapsed * 10 * math.pi / 128
            radius = elapsed * 208 // 256
            return (attacker[0] + x + int(math.sin(angle) * radius),
                    attacker[1] + y + int(math.cos(angle) * radius))
        if callback in {"TranslateAnimSpriteToTargetMonLocation", "AnimThrowProjectile", "AnimMissileArc"}:
            start = (attacker[0] + x, attacker[1] + y)
            finish = (target_pos[0] + signed_argument(args, 2), target_pos[1] + signed_argument(args, 3))
            arc = signed_argument(args, 5) if callback in {"AnimThrowProjectile", "AnimMissileArc"} else 0
            return (
                start[0] + int((finish[0] - start[0]) * progress),
                start[1] + int((finish[1] - start[1]) * progress)
                - int(math.sin(progress * math.pi) * arc),
            )
        if callback == "AnimToTargetInSinWave":
            start = (attacker[0] + x, attacker[1] + y)
            wave = signed_argument(args, 3, 16)
            return (
                start[0] + int((target_pos[0] - start[0]) * progress),
                start[1] + int((target_pos[1] - start[1]) * progress)
                + int(math.sin(progress * math.pi * 4) * wave),
            )
        if callback == "AnimShadowBall":
            first = max(1, signed_argument(args, 0, 16))
            spin = max(0, signed_argument(args, 1, 16))
            last = max(1, signed_argument(args, 2, 8))
            midpoint = ((attacker[0] + target_pos[0]) // 2, (attacker[1] + target_pos[1]) // 2)
            if age < first:
                part = age / first
                return (attacker[0] + int((midpoint[0] - attacker[0]) * part),
                        attacker[1] + int((midpoint[1] - attacker[1]) * part))
            if age < first + spin:
                angle = (age - first) * math.pi / 8
                return (midpoint[0] + int(math.cos(angle) * 8), midpoint[1] + int(math.sin(angle) * 8))
            part = min(1.0, (age - first - spin) / last)
            return (midpoint[0] + int((target_pos[0] - midpoint[0]) * part),
                    midpoint[1] + int((target_pos[1] - midpoint[1]) * part))
        if callback == "AnimHyperBeamOrb":
            part = min(1.0, age / max(1, event.duration - 1))
            start = (attacker[0] + 20, attacker[1])
            return (start[0] + int((target_pos[0] - start[0]) * part),
                    start[1] + int((target_pos[1] - start[1]) * part)
                    + int(math.sin(age * math.pi / 6) * 12))
        if any(word in callback.lower() for word in ("translate", "projectile")):
            start = (attacker[0] + x, attacker[1] + y)
            return (start[0] + int((target_pos[0] - start[0]) * progress),
                    start[1] + int((target_pos[1] - start[1]) * progress))
        inferred = self.callback_placements.get(callback)
        if inferred == "attacker":
            base = attacker
        elif inferred == "target":
            base = target_pos
        return (base[0] + x, base[1] + y)

    def sprite_frames(self, template: str, args: tuple[str, ...]) -> SpriteSequence | None:
        animation = self.template_animations.get(template)
        if not animation:
            return None
        table_name, base_index = animation
        table = self.sprite_anim_tables.get(table_name)
        if not table:
            return None
        index = base_index + sprite_animation_index(
            self.template_callbacks.get(template, ""), args, self.callback_animation_args
        )
        return table[min(index, len(table) - 1)]

    def sprite_tile_adjustment(self, template: str, args: tuple[str, ...]) -> int:
        callback = self.template_callbacks.get(template, "")
        if callback == "AnimElectricity":
            return max(0, signed_argument(args, 3)) * 4
        if callback == "AnimSparkElectricityFlashing":
            return max(0, signed_argument(args, 6)) * 4
        if callback == "AnimMudSportDirt":
            return 1
        if callback == "AnimTearDrop":
            return 4
        if callback == "AnimJaggedMusicNote":
            return max(0, signed_argument(args, 3)) * 16
        return 0

    def sprite_affine_transform(self, template: str, args: tuple[str, ...], image):
        callback = self.template_callbacks.get(template, "")
        if callback == "AnimBite":
            # gAffineAnims_Bite rotates in 32/256-turn increments.
            animation = signed_argument(args, 2) & 7
            angle = animation * 45
            if angle:
                return image.rotate(angle, resample=Image.Resampling.NEAREST, expand=False)
        return image

    def render(self):
        self.canvas.delete("all")
        self.photos.clear()
        if Image is not None and PREVIEW_BACKGROUND.exists():
            image = Image.open(PREVIEW_BACKGROUND).convert("RGBA")
            photo = self.image_photo("background", image)
            self.canvas.create_image(0, 0, image=photo, anchor="nw")
        else:
            self.canvas.create_rectangle(0, 0, 480, 320, fill="#4978a5")
        active_background = None
        background_scroll = None
        for event in self.events:
            if event.frame <= self.frame and event.kind == "background":
                active_background = event.values[0]
                background_scroll = None
            elif event.frame <= self.frame and event.kind == "restore_background":
                active_background = None
                background_scroll = None
            elif event.frame <= self.frame and event.kind == "background_scroll":
                background_scroll = event
        if active_background in self.background_assets and ImageTk is not None:
            if active_background not in self.background_images:
                self.background_images[active_background] = render_background(self.background_assets[active_background])
            background_image = self.background_images[active_background]
            if background_image is not None:
                offset_x = 0
                offset_y = 0
                if background_scroll is not None:
                    elapsed = self.frame - background_scroll.frame
                    offset_x = (signed_argument(background_scroll.values, 0) * elapsed // 256) % 240
                    offset_y = (signed_argument(background_scroll.values, 1) * elapsed // 256) % 160
                displayed_background = scroll_background_frame(background_image, offset_x, offset_y)
                photo = self.image_photo(f"effect_bg_{active_background}", displayed_background)
                self.canvas.create_image(0, 0, image=photo, anchor="nw")
        current = [event for event in self.events if event.frame <= self.frame < event.frame + event.duration]
        for event in self.events:
            if event.frame <= self.frame and event.kind in {"invisible", "visible"}:
                if event.kind == "invisible":
                    self.hidden.add(event.values[0])
                else:
                    self.hidden.discard(event.values[0])
        shake_attacker = any(event.kind == "shake" and "ATTACKER" in event.values[0] for event in current)
        shake_target = any(event.kind == "shake" and "TARGET" in event.values[0] for event in current)
        attacker_shift = (3 if self.frame % 2 else -3) if shake_attacker else 0
        target_shift = (3 if self.frame % 2 else -3) if shake_target else 0
        self.draw_mon("ANIM_ATTACKER", 40, 62, attacker_shift)
        self.draw_mon("ANIM_TARGET", 144, 16, target_shift)
        for index, event in enumerate(current):
            if event.kind == "flash":
                self.canvas.create_rectangle(0, 0, 480, 320, fill="#ffffff", stipple="gray75")
            elif event.kind in {"sprite", "task_drop", "task_hit", "task_raindrop"}:
                if event.kind == "sprite":
                    tag, _target, template, *args = event.values
                    origin = self.sprite_position(event)
                else:
                    tag, template, raw_x, raw_y, *unused = event.values
                    age = self.frame - event.frame
                    x = parse_signed_number(raw_x)
                    y = parse_signed_number(raw_y)
                    if event.kind == "task_drop":
                        origin = (x, min(parse_signed_number(unused[0]), y + age * 8))
                    elif event.kind == "task_raindrop":
                        origin = (x + age, y + age * 4)
                    else:
                        origin = (x, y)
                    args = []
                image_path = self.tag_graphics.get(tag)
                sequence = self.sprite_frames(template, tuple(args))
                if tag == "ANIM_TAG_ICE_CRYSTALS":
                    image_path, sequence = remap_segmented_ice_asset(sequence)
                if image_path and Image is not None and ImageTk is not None:
                    palette_tag = self.template_palette_tags.get(template, tag)
                    image = particle_frame(
                        image_path,
                        self.template_sizes.get(template),
                        self.frame - event.frame,
                        self.tag_palettes.get(palette_tag),
                        sequence,
                        self.sprite_tile_adjustment(template, tuple(args)),
                    )
                    image = self.sprite_affine_transform(template, tuple(args), image)
                    photo = self.image_photo(f"effect{index}", image)
                    self.canvas.create_image(origin[0] * 2, origin[1] * 2, image=photo, anchor="center")
                else:
                    color = "#ffdd4a" if "hit" in template.lower() else "#7cefff"
                    x, y = origin[0] * 2, origin[1] * 2
                    self.canvas.create_oval(x - 12, y - 12, x + 12, y + 12, fill=color, outline="white")


class BattleAnimEditor(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Battle Animation Editor - darkworship2")
        self.geometry("1280x820")
        self.minsize(1050, 680)
        self.macros = read_macros()
        self.engine_symbols, self.valid_tags = collect_engine_symbols()
        self.source = ""
        self.blocks: list[AnimBlock] = []
        self.current_label: str | None = None
        self.species = collect_species()
        self.tag_graphics, self.tag_palettes = collect_animation_assets()
        (
            self.template_tags,
            self.template_sizes,
            self.wrapper_templates,
            self.template_palette_tags,
            self.template_callbacks,
            self.template_animations,
        ) = collect_template_metadata()
        self.sprite_anim_tables = collect_sprite_anim_tables()
        self.callback_animation_args, self.callback_placements = collect_callback_sprite_rules()
        self.background_assets = collect_background_assets()
        self.sound_midis = collect_sound_midis()
        self.search_var = tk.StringVar()
        self.status_var = tk.StringVar()
        self.setup_ui()
        self.load_source()

    def setup_ui(self):
        toolbar = ttk.Frame(self, padding=6)
        toolbar.pack(fill="x")
        ttk.Button(toolbar, text="Recarregar", command=self.load_source).pack(side="left")
        ttk.Button(toolbar, text="Nova animacao", command=self.new_animation).pack(side="left", padx=4)
        ttk.Button(toolbar, text="Salvar animacao", command=self.save_current).pack(side="left", padx=4)
        ttk.Button(toolbar, text="Validar", command=self.validate_editor).pack(side="left", padx=4)
        ttk.Button(toolbar, text="Play Anim", command=self.play_current).pack(side="left", padx=(20, 4))
        ttk.Button(toolbar, text="Parar", command=self.stop_preview).pack(side="left")
        ttk.Label(toolbar, textvariable=self.status_var).pack(side="right")

        outer = ttk.Panedwindow(self, orient="horizontal")
        outer.pack(fill="both", expand=True, padx=6, pady=(0, 6))
        left = ttk.Frame(outer, width=280)
        right = ttk.Panedwindow(outer, orient="vertical")
        outer.add(left, weight=1)
        outer.add(right, weight=4)

        ttk.Label(left, text="Buscar animacao:").pack(fill="x")
        search = ttk.Entry(left, textvariable=self.search_var)
        search.pack(fill="x", pady=(2, 6))
        search.bind("<KeyRelease>", lambda _event: self.populate_tree())
        self.tree = ttk.Treeview(left, show="tree", selectmode="browse")
        scroll = ttk.Scrollbar(left, orient="vertical", command=self.tree.yview)
        self.tree.configure(yscrollcommand=scroll.set)
        self.tree.pack(side="left", fill="both", expand=True)
        scroll.pack(side="right", fill="y")
        self.tree.bind("<<TreeviewSelect>>", self.select_animation)

        self.preview = BattlePreview(
            right,
            self.species,
            self.tag_graphics,
            self.tag_palettes,
            self.template_tags,
            self.template_sizes,
            self.wrapper_templates,
            self.template_palette_tags,
            self.template_callbacks,
            self.template_animations,
            self.sprite_anim_tables,
            self.callback_animation_args,
            self.callback_placements,
            self.background_assets,
            self.sound_midis,
        )
        right.add(self.preview, weight=2)
        notebook = ttk.Notebook(right)
        right.add(notebook, weight=4)
        edit_tab = ttk.Frame(notebook, padding=5)
        easy_tab = ttk.Frame(notebook, padding=8)
        macros_tab = ttk.Frame(notebook, padding=8)
        notebook.add(edit_tab, text="Script")
        notebook.add(easy_tab, text="Criacao facil")
        notebook.add(macros_tab, text="Macros disponiveis")

        self.editor = tk.Text(edit_tab, undo=True, wrap="none", font=("TkFixedFont", 10))
        yscroll = ttk.Scrollbar(edit_tab, orient="vertical", command=self.editor.yview)
        xscroll = ttk.Scrollbar(edit_tab, orient="horizontal", command=self.editor.xview)
        self.editor.configure(yscrollcommand=yscroll.set, xscrollcommand=xscroll.set)
        self.editor.grid(row=0, column=0, sticky="nsew")
        yscroll.grid(row=0, column=1, sticky="ns")
        xscroll.grid(row=1, column=0, sticky="ew")
        edit_tab.columnconfigure(0, weight=1)
        edit_tab.rowconfigure(0, weight=1)

        ttk.Label(easy_tab, text="Insira comandos prontos no cursor do editor. Eles usam macros validas deste projeto.").pack(anchor="w")
        snippets_frame = ttk.Frame(easy_tab)
        snippets_frame.pack(fill="x", pady=10)
        for index, (title, text) in enumerate(SNIPPETS.items()):
            button = ttk.Button(snippets_frame, text=title, command=lambda snippet=text: self.insert_snippet(snippet))
            button.grid(row=index // 3, column=index % 3, sticky="ew", padx=3, pady=3)
        for column in range(3):
            snippets_frame.columnconfigure(column, weight=1)
        ttk.Label(easy_tab, text="Modelo recomendado para uma animacao nova: carregue graficos, crie efeitos, aguarde e finalize com end.").pack(anchor="w", pady=(10, 0))
        ttk.Button(easy_tab, text="Inserir final end", command=lambda: self.insert_snippet("\twaitforvisualfinish\n\tend\n")).pack(anchor="w", pady=8)

        columns = ("args",)
        self.macro_tree = ttk.Treeview(macros_tab, columns=columns, show="tree headings")
        self.macro_tree.heading("#0", text="Macro")
        self.macro_tree.heading("args", text="Argumentos")
        self.macro_tree.column("#0", width=230)
        self.macro_tree.column("args", width=620)
        self.macro_tree.pack(fill="both", expand=True)
        for macro in self.macros.values():
            self.macro_tree.insert("", "end", text=macro.name, values=(", ".join(macro.parameters),))
        self.macro_tree.bind("<Double-1>", self.insert_selected_macro)

    def load_source(self):
        if not SCRIPT_PATH.exists():
            messagebox.showerror("Erro", f"Arquivo nao encontrado:\n{SCRIPT_PATH}")
            return
        self.source = SCRIPT_PATH.read_text(encoding="utf-8", errors="replace")
        self.blocks = parse_blocks(self.source)
        self.populate_tree()
        self.status_var.set(f"{len(self.blocks)} animacoes | {len(self.macros)} macros")
        if self.blocks and self.current_label is None:
            self.show_block(self.blocks[0].label)
        elif self.current_label:
            self.show_block(self.current_label)

    def populate_tree(self):
        selected = self.current_label
        self.tree.delete(*self.tree.get_children())
        roots = {
            "Movimentos": self.tree.insert("", "end", text="Movimentos", open=True),
            "Gerais": self.tree.insert("", "end", text="Gerais", open=True),
        }
        term = self.search_var.get().strip().lower()
        for block in self.blocks:
            if term and term not in block.label.lower():
                continue
            self.tree.insert(roots[block.kind], "end", iid=block.label, text=block.short_name)
        if selected and self.tree.exists(selected):
            self.tree.selection_set(selected)

    def block_for_label(self, label: str | None) -> AnimBlock | None:
        return next((block for block in self.blocks if block.label == label), None)

    def select_animation(self, _event=None):
        selected = self.tree.selection()
        if selected and selected[0] not in {"Movimentos", "Gerais"}:
            self.show_block(selected[0])

    def show_block(self, label: str):
        block = self.block_for_label(label)
        if not block:
            return
        self.current_label = label
        self.editor.delete("1.0", "end")
        self.editor.insert("1.0", block.text.rstrip() + "\n")
        self.editor.edit_reset()
        self.status_var.set(f"Editando {label}")

    def compose_source_with_editor(self) -> tuple[str, AnimBlock | None]:
        block = self.block_for_label(self.current_label)
        if not block:
            return self.source, None
        replacement = self.editor.get("1.0", "end-1c").rstrip() + "\n\n"
        return self.source[:block.start] + replacement + self.source[block.end:], block

    def report_issues(self, issues: list[ValidationIssue], title: str = "Validacao") -> bool:
        errors = [issue for issue in issues if issue.error]
        if not issues:
            messagebox.showinfo(title, "Nenhum problema estrutural encontrado nas macros e labels.")
            return True
        lines = [
            f"{'ERRO' if issue.error else 'Aviso'} linha {issue.line}: {issue.message}"
            for issue in issues[:30]
        ]
        if len(issues) > 30:
            lines.append(f"... e mais {len(issues) - 30} mensagens.")
        show = messagebox.showerror if errors else messagebox.showwarning
        show(title, "\n".join(lines))
        return not errors

    def validate_editor(self):
        text, _block = self.compose_source_with_editor()
        issues = validate_source(text, self.macros, self.engine_symbols, self.valid_tags)
        self.report_issues(issues)
        self.status_var.set(f"Validacao: {len([i for i in issues if i.error])} erros, {len(issues)} mensagens")

    def save_current(self):
        text, block = self.compose_source_with_editor()
        if not block:
            messagebox.showwarning("Salvar", "Selecione uma animacao.")
            return
        issues = validate_source(text, self.macros, self.engine_symbols, self.valid_tags)
        if not self.report_issues(issues, "Salvar - validacao"):
            return
        backup_path = backup(SCRIPT_PATH)
        SCRIPT_PATH.write_text(text, encoding="utf-8")
        old_label = self.current_label
        self.source = text
        self.blocks = parse_blocks(text)
        self.current_label = old_label if self.block_for_label(old_label) else None
        self.populate_tree()
        self.status_var.set(f"Salvo. Backup: {backup_path.name}")

    def new_animation(self):
        name = simpledialog.askstring("Nova animacao", "Nome do movimento (ex.: ShadowBloom):", parent=self)
        if not name:
            return
        clean = re.sub(r"[^A-Za-z0-9_]", "", name.strip().replace(" ", ""))
        if not clean:
            messagebox.showerror("Nova animacao", "Nome invalido.")
            return
        label = clean if clean.startswith("gBattleAnim") else f"gBattleAnimMove_{clean}"
        if self.block_for_label(label):
            messagebox.showerror("Nova animacao", f"{label} ja existe.")
            return
        block_text = (
            f"\n{label}::\n"
            "\t@ Criada pelo Battle Animation Editor\n"
            "\tloadspritegfx ANIM_TAG_HIT\n"
            "\tplaysewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET\n"
            "\tcreate_basic_hitsplat_sprite ANIM_TARGET, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=0\n"
            "\twaitforvisualfinish\n"
            "\tend\n"
        )
        new_source = self.source.rstrip() + "\n" + block_text
        issues = validate_source(new_source, self.macros, self.engine_symbols, self.valid_tags)
        if not self.report_issues(issues, "Nova animacao - validacao"):
            return
        backup_path = backup(SCRIPT_PATH)
        SCRIPT_PATH.write_text(new_source, encoding="utf-8")
        self.source = new_source
        self.blocks = parse_blocks(new_source)
        self.current_label = label
        self.search_var.set("")
        self.populate_tree()
        self.show_block(label)
        self.status_var.set(f"Nova animacao salva. Backup: {backup_path.name}")

    def insert_snippet(self, snippet: str):
        self.editor.insert("insert", snippet)
        self.editor.focus_set()

    def insert_selected_macro(self, _event=None):
        selection = self.macro_tree.selection()
        if selection:
            macro = self.macro_tree.item(selection[0], "text")
            self.insert_snippet(f"\t{macro} ")

    def play_current(self):
        if not self.current_label:
            messagebox.showwarning("Play Anim", "Selecione uma animacao.")
            return
        text, _block = self.compose_source_with_editor()
        issues = validate_source(text, self.macros, self.engine_symbols, self.valid_tags)
        if any(issue.error for issue in issues):
            self.report_issues(issues, "Play Anim - corrija o script")
            return
        self.preview.play(self.editor.get("1.0", "end-1c"), text)

    def stop_preview(self):
        self.preview.stop()
        self.preview.status.configure(text="Preview parado.")


def cli_validate() -> int:
    macros = read_macros()
    engine_symbols, valid_tags = collect_engine_symbols()
    text = SCRIPT_PATH.read_text(encoding="utf-8", errors="replace")
    blocks = parse_blocks(text)
    issues = validate_source(text, macros, engine_symbols, valid_tags)
    errors = [issue for issue in issues if issue.error]
    print(f"{SCRIPT_PATH}: {len(blocks)} animacoes, {len(macros)} macros, {len(errors)} erros")
    for issue in issues:
        print(f"{'error' if issue.error else 'warning'}:{issue.line}: {issue.message}")
    return 1 if errors else 0


def main() -> int:
    parser = argparse.ArgumentParser(description="Editor visual de data/battle_anim_scripts.s")
    parser.add_argument("--validate", action="store_true", help="valida scripts sem abrir a interface")
    args = parser.parse_args()
    if args.validate:
        return cli_validate()
    if Image is None:
        print("Aviso: Pillow nao instalado; a interface abre sem imagens de preview.", file=sys.stderr)
    app = BattleAnimEditor()
    app.mainloop()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
