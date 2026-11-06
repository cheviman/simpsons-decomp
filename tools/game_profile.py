"""
Name:        game_profile.py
Description: what the shared decompiler core (tools/core) needs to know of The Simpsons: where the game is, its
             ROM set, and its settings
Version:     0.1.0
Created:     05-11-2026
Modified:    05-11-2026
Author:      Sebastian Toyos

The core (arcade-decomp: the decompiler, the CPU frontends, the analysis, the checks) is the same for every
game; this module gives it The Simpsons': the repository's root, the ROM set's module (simpsons_rom: the
regions as the board has them) and the names the generated files carry. The decompiler's settings for the
053248 program come here as the steps that need them are reached; until then the core's neutral defaults
stand. The core's frontend for Konami's 053248 is konami_cpu (its decoder; the static analysis is to come); its
reference, kref, runs the original program on MAME's core against the board model (runtime/).
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "core"))

import simpsons_rom as rom  # noqa: E402,F401

ROOT = Path(__file__).resolve().parents[1]
GAME = "The Simpsons (arcade, Konami 1991)"     # in the generated files' headers
ROM_SET_TITLE = "The Simpsons (simpsons, 4 Players World, set 1)"
CPU = "053248"                                  # Konami's 6809-derived CPU (MAME's konami_cpu_device)
BINARY = "simpsons"                             # its executables: simpsons_game_headless, simpsons_headless
GUARD = "SIMPSONS"                              # the generated headers' include guards: SIMPSONS_GAME_H...
REFERENCE = "kref"                              # the reference (tools/core/konami/reference, kref_053248.cpp)
DISASSEMBLER = "konami_cpu.disassembler"        # the 053248's decoder (checked against MAME's at every offset)
ANALYSIS = "konami_cpu.analysis"                # its static analysis, the banks followed
STATIC_ANALYSIS = True
DATA_WALK = "data_walk"                         # the data the engines read, walked (tools/data_walk.py)
RESET_BANK = 0                                  # the bank the board's reset selects (MAME's machine_reset)
# the direct page byte the program keeps the bank it chooses in (LDB #n; STB <$0E; SETLN <$0E: the CPU cannot read
# its own lines back)
BANK_SHADOW = 0x0E

# The Z80 sound program (072-e03.6g: 0000-7FFF fixed, 16 KB banks at 8000-BFFF by FE00, which the Z80 only reads as
# data; its RAM at F000): the reset (IM 1, then 0923), the interrupt (0038, from the 053248's read of 1FC4) and the
# NMI (0066, a RETN: the K053260's, which only wakes it), and the jumps through registers followed by what the
# registers hold
SOUND_ENTRIES = {0x0000: "func", 0x0038: "func", 0x0066: "func"}
SOUND_CODE_END = 0x8000
SOUND_FOLLOW_VALUES = True
SOUND_DATA_WALK = "sound_data_walk"             # the music the driver reads, walked (tools/sound_data_walk.py)
