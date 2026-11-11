"""
Name:        rom_in_executables.py
Description: looks for the ROM set's content in the built executables: none of the game's may hold any
Version:     0.1.0
Created:     06-11-2026
Modified:    11-11-2026
Author:      Sebastian Toyos

Usage: python tools/rom_in_executables.py [EXECUTABLE ...]   (default: the game's in build/bin)

Every 32-byte stretch of the ROM set (rom/), at every 32nd byte, is looked for in the executables, as the files
have it (each chip) and as the board lays it out (the regions: the 053248's program, the Z80's, the tiles, the
sprites, the samples, the EEPROM); a stretch any binary could hold (almost all one byte, up to three runs of two
bytes, or bytes or 16-bit words in an arithmetic progression) is left out. Prints, for each executable, how many
stretches of each it holds; the game's must hold none. An executable that is not there is said so and left out
(the game's window is built only with SDL2, the translation scaffold only after tools/recompile.py); when none of
them is there, nothing is checked and the check fails. (The tools that run the original program, kref and its
oracles, read the ROM set when they start: they are not the game's.)
"""
import struct
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
import game_profile  # noqa: E402  (the game's: its root, its ROM set)

ROOT = game_profile.ROOT
rom = game_profile.rom
SPAN = 32
EXTENSION = ".exe" if sys.platform == "win32" else ""
GAME = [name + EXTENSION for name in ("simpsons_game_headless", "simpsons_headless", "simpsons")]


def trivial(chunk):
    """Almost one byte over and over (all but 4 of them: a run of padding with a value at an edge), up to three
    runs of two bytes (zeros, ones, zeros), or bytes or 16-bit words in an arithmetic progression."""
    if max(chunk.count(value) for value in set(chunk)) >= len(chunk) - 4:
        return True
    if len(set(chunk)) == 2 and sum(1 for index in range(1, len(chunk)) if chunk[index] != chunk[index - 1]) <= 2:
        return True
    steps = {(chunk[index + 1] - chunk[index]) & 0xFF for index in range(len(chunk) - 1)}
    if len(steps) == 1:
        return True
    for order in "<>":
        words = struct.unpack(f"{order}{len(chunk) // 2}H", chunk)
        if len({(words[index + 1] - words[index]) & 0xFFFF for index in range(len(words) - 1)}) == 1:
            return True
    return False


def main():
    paths = [Path(argument) for argument in sys.argv[1:]] or [ROOT / "build" / "bin" / name for name in GAME]
    for path in paths:
        if not path.is_file():
            print(f"{path}: not there")
    paths = [path for path in paths if path.is_file()]
    if not paths:
        print("none of the executables is there: nothing checked")
        return 1
    found_set = rom.load_set(ROOT / "rom")
    regions = {"program": rom.build_program(found_set), "sound": rom.build_sound(found_set),
               "tiles": rom.build_tiles(found_set), "sprites": rom.build_sprites(found_set),
               "samples": rom.build_samples(found_set), "eeprom": rom.build_eeprom(found_set)}
    regions.update({name: data for name, data in sorted(found_set.items())})
    chunks = {name: [bytes(region[at:at + SPAN]) for at in range(0, len(region) - SPAN + 1, SPAN)]
              for name, region in regions.items()}
    chunks = {name: [chunk for chunk in found if not trivial(chunk)] for name, found in chunks.items()}
    failed = False
    for path in paths:
        data = path.read_bytes()
        windows = {data[at:at + SPAN] for at in range(len(data) - SPAN + 1)}
        found = {name: sum(1 for chunk in region if chunk in windows) for name, region in chunks.items()}
        failed |= any(found.values())
        held = [f"{name} {count}" for name, count in found.items() if count]
        print(f"{path.name}: " + (", ".join(held) if held else "none") + f" of the ROM set's "
              f"{sum(map(len, chunks.values()))} stretches")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
