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
# The translation scaffold (tools/recompile.py: konami_cpu/translate.py), with frame timing
# (runtime/include/simpsons/frame.h): where the program waits for its next frame (the main loop with no job, the boot
# waiting for the FIRQ, then for the test switch to be let go), and where the IRQ handler takes the DMA's FIRQ
TRANSLATOR = "konami_cpu.translate"
FRAME_WAITS = (0x0789D1, 0x078817, 0x078882)
FIRQ_POINT = 0x078F7A
# The game's code the board puts its own in place of (runtime/src/board_code.c): where it starts, the board's function,
# and where the game's code goes on after it. The boot's ROM test adds up the program's chips, which the game does not
# have: the board gives the sums the program keeps for good chips.
REPLACED_CODE = {0x078E68: ("sum_rom_bytes", 0x078E7A)}

# The Z80 sound program (072-e03.6g: 0000-7FFF fixed, 16 KB banks at 8000-BFFF by FE00, which the Z80 only reads as
# data; its RAM at F000): the reset (IM 1, then 0923), the interrupt (0038, from the 053248's read of 1FC4) and the
# NMI (0066, a RETN: the K053260's, which only wakes it), and the jumps through registers followed by what the
# registers hold
SOUND_ENTRIES = {0x0000: "func", 0x0038: "func", 0x0066: "func"}
SOUND_CODE_END = 0x8000
SOUND_FOLLOW_VALUES = True
SOUND_DATA_WALK = "sound_data_walk"             # the music the driver reads, walked (tools/sound_data_walk.py)
# The decompiled sound program (tools/decompile_sound.py; it runs on runtime/src/sound_cpu.c and sound_board.c): the
# Z80's own RAM (F000-F7FF) holds its variables and its 12 channel records, the program ROM (0000-7FFF) its tables,
# which the game loads by name from its assets; the board's chips are registers on the Z80's bus: the YM2151 (F800-
# F801), FA00 (a write arms the NMI), the K053260 (FC00-FC2F, its first four the ports with the 053248) and the bank
# of 8000-BFFF (FE00)
SOUND_RAM_AREA = (0xF000, 0xF800)
SOUND_ROM_AREA = (0x0000, 0x8000)
SOUND_HARDWARE = [(0xF800, 0xF802, "FM"), (0xFA00, 0xFA01, "NMI_ARM"), (0xFC00, 0xFC30, "PCM"),
                  (0xFE00, 0xFE01, "SOUND_BANK")]
SOUND_NOTES = {
    "variables": ["/* the sound program's variables and channel records, in the Z80's RAM (F000-F7FF) */"],
    "scoped": ["/* RAM as one family of functions uses it */"],
    "tables": ["/* data in the program ROM the code reads, which the game loads from its assets */"],
    "hardware": ["/* the board's registers on the Z80's bus: the YM2151, FA00 (the NMI's arming), the K053260 with",
                 "   the ports between the two CPUs, and the bank of 8000-BFFF (read and written through the bus) */"],
}
SOUND_BLOCK_FETCHES = False                     # no LD A,R: the refresh register is never read
SOUND_INTERRUPT_WINDOWS = True                  # the main loop lets the 053248's command in for four NOPs only (EI ... DI)
SOUND_STACK_RESTARTS = True                     # the failed self test loops back to its own LD SP (0B28)
SOUND_CREATED = "06-11-2026"                    # when src/sound/ was first written (its files' headers)
# the registers the whole program keeps (global variables in C, by sound_symbols.txt's register lines): the self test
# leaves its results in the other bank's AF', BC', DE' and HL' (09E6-09FA, 0771-0785, 081F-0833), which the commands
# F1-F7 hand back to the 053248 (04BE-0533)
SOUND_CONTEXT = ("a_alt", "bc_alt", "de_alt", "hl_alt")
SOUND_LOADED_TABLES = True                      # the tables the C reads by name, which the board sets (src/sound/tables.c)
SOUND_COUNTED_FROM_ONE = True                   # tables read from an element before them: effect_priorities[i - 1]
SOUND_NAMES_BEFORE_TABLES = 2                   # the base of a table indexed from past its start: effect_levels from level 1
# the handlers the program stores in its channel records (+43) and switches on (run_channel's JP (HL)), by name
SOUND_CODE_VALUES = True
