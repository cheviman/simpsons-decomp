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
stand. The core has no frontend for Konami's 053248 yet; its reference, kref, runs the original program on
MAME's core against the board model (runtime/).
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
STATIC_ANALYSIS = False                         # no frontend for the 053248 in the core yet
