#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path


OLD_SECONDARY_START = 0x200
NEW_SECONDARY_START = 0x280
TILE_ID_MASK = 0x03FF
TILE_FLAGS_MASK = 0xFC00
MAX_TILE_ID = 0x3FF


def iter_metatile_files(root: Path) -> list[Path]:
    if root.is_file():
        return [root]
    return sorted(root.glob("*/metatiles.bin"))


def convert_file(path: Path, *, write: bool, force: bool) -> tuple[int, int]:
    data = bytearray(path.read_bytes())
    if len(data) % 2 != 0:
        raise ValueError(f"{path}: odd byte count")

    changed = 0
    overflow = 0
    delta = NEW_SECONDARY_START - OLD_SECONDARY_START

    for offset in range(0, len(data), 2):
        entry = data[offset] | (data[offset + 1] << 8)
        tile_id = entry & TILE_ID_MASK
        tile_flags = entry & TILE_FLAGS_MASK

        if tile_id < OLD_SECONDARY_START:
            continue

        new_tile_id = tile_id + delta
        if new_tile_id > MAX_TILE_ID:
            overflow += 1
            if not force:
                continue
            new_tile_id &= TILE_ID_MASK

        new_entry = tile_flags | new_tile_id
        data[offset] = new_entry & 0xFF
        data[offset + 1] = new_entry >> 8
        changed += 1

    if write and changed and (force or overflow == 0):
        path.write_bytes(data)

    return changed, overflow


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Shift secondary tileset tile references in metatiles.bin from 0x200+ to 0x280+."
    )
    parser.add_argument(
        "paths",
        nargs="*",
        type=Path,
        default=[Path("data/tilesets/secondary")],
        help="metatiles.bin file(s) or directory containing secondary tileset folders",
    )
    parser.add_argument("--write", action="store_true", help="write converted files")
    parser.add_argument(
        "--force",
        action="store_true",
        help="wrap overflowing tile ids instead of refusing to write those files",
    )
    args = parser.parse_args()

    had_overflow = False
    for root in args.paths:
        for path in iter_metatile_files(root):
            changed, overflow = convert_file(path, write=args.write, force=args.force)
            if changed or overflow:
                status = "wrote" if args.write and (args.force or overflow == 0) else "would change"
                if overflow and not args.force:
                    status = "blocked"
                    had_overflow = True
                print(f"{status}: {path} changed={changed} overflow={overflow}")

    if had_overflow and not args.write:
        return 1
    if had_overflow and args.write:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
