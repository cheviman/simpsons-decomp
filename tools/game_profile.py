"""
Name:        game_profile.py
Description: what the shared decompiler core (tools/core) needs to know of The Simpsons: where the game is, its
             ROM set, and its settings
Version:     0.1.0
Created:     05-11-2026
Modified:    07-11-2026
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
# The direct page: the boot sets it to 48 at 07871B (LDA #$48; PUSHS A; PULLS DP), before any instruction reads through
# it, and nothing changes it after (an interrupt's RTI pulls the 48 it pushed): <$xx is the work RAM at 48xx
DIRECT_PAGE = 0x48
DIRECT_PAGE_SET = 0x07871B

# The decompiled program (tools/decompile.py: konami_cpu/decompile.py; it runs on runtime/src/game_program.c): the
# frame waits by name (simpsons/frame.h), and when src/ was first written
DECOMPILER = "konami_cpu.decompile"
FRAME_WAIT_NAMES = {0x89D1: "SIMPSONS_FRAME_WAIT", 0x8817: "SIMPSONS_BOOT_WAIT", 0x8882: "SIMPSONS_SWITCH_WAIT"}
DECOMPILED = "06-11-2026"
# The noise meter (tools/noise_report.py): the 053248's registers, which the C names its values after until a line
# names them (a, b, d, x, y, u), and the names made of an address (sub_078E68, unused_020686) counted as such
NOISE_REGISTERS = r"(?:[abdxyu]|r\d+)"
ADDRESS_NAMES = True
# The program's data read through the pointers the program keeps, by name (konami_cpu/emit.py): the values a pointer
# walks (symbols.txt elements lines) read one at a time at their address, NAME(p), and a record reached by a pointer
# moved any number of bytes, STRUCT(p + n)->field, as the records' copies are made from where they are read
ELEMENT_READS = True
# a table of records the code reads from one record before its start, its numbers counting from 1: bank 1C's team
# moves (0393xx: by the two players' characters, (first x 4 + second) x 8 from 7EA9, the table at 7EB1)
RECORDS_BEFORE = 1
# the data the fixed program reads in the window of a bank it chose by a table, whatever the bank: the sprite engine
# (079AE9) reads the animation set index at 6000 of the bank animation_sets gives the object's kind (079B11 "LDB ,U+;
# STB <$0E; SETLN <$0E", 079B3E "LDU #$6000; CLRA; LDU D,U")
WINDOW_ELEMENTS = {0x079AE9: {0x6000: "animation_set_index"}}
# The objects: 0x60 bytes each, 33 of them one after another from 4A40 (symbols.txt's struct object): the 4 players'
# (4A40 + C0 x player, each with its partner at +60: 07D30C "LDU #$4A40") and the 4 lists the objects' dispatchers run
# (object_lists, 07EFF8: 4D40 x 6, 4F80 x 8, 5280 x 10, 5640 x 1, each list right after the one before). The
# dispatchers hand each handler its object in X (07CB62 "LDX #$4F80" ... "JSR [A,U]")
STRUCT_ARRAYS = {"object": (0x4A40, 33)}
OBJECT_REGISTER = "x"
# an object at a fixed address that is of one family in some functions only: the list at 5640 (one object, the
# stage's events) is the story actor in the stories' routines (03E804 "LDX #$5640; LDA #$38; STA #$30,X; LBRA $605A":
# a scene's actor started on its script), whose fields an access by its address reads by the family's names (the
# players' objects at 4A40 + C0 n are not always the player family's: the bonus games' objects are there too)
INSTANCE_FAMILIES_BY_FUNCTION = {(0x5640, "story"): "story_actor"}
OWN_OBJECT_POINTERS = True     # (the object register is the family's object in the pointer analysis too)
NESTED_FAMILIES = True         # (a family's view takes the fields of the families its name extends)
# names by use, as TMNT's: a parameter or result takes the name of the structure read through it, or of the variable
# every caller hands it; a variable stored into, or compared with, one field only takes its name; a constant stored
# into a field typed as a number is a number
PARAMS_BY_USE = True
PARAMS_FROM_CALLERS = True
NAMES_BY_STORES = True
NAMES_BY_COMPARISONS = True
NUMBERS_BY_FIELD = True
# the data flow by part, as TMNT's (konami_cpu/decompile.py): what a function reads to hand back a register, part by
# part (D's bytes, X's); a register written with an operation that leaves some of its parts writes only the others;
# what a function hands back is only what its callers read, once everything is known; a web two local lines name
# takes the name of its definition first in the program (the same C whatever the order of a set)
PASSES_BY_PART = True
UNCHANGED_PARTS = True
NARROW_OUTPUTS = True
CHOSEN_IN_ORDER = True

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
SOUND_TABLES_USED_ONLY = True                   # only the ones the C reads: ld bc,$0007 (a count) names none
SOUND_COUNTED_FROM_ONE = True                   # tables read from an element before them: effect_priorities[i - 1]
SOUND_NAMES_BEFORE_TABLES = 2                   # the base of a table indexed from past its start: effect_levels from level 1
SOUND_TABLE_REGISTERS = True                    # a table read through HL ("ld hl,TABLE; add hl,bc; ld e,(hl)"), by its name
# the handlers the program stores in its channel records (+43) and switches on (run_channel's JP (HL)), by name
SOUND_CODE_VALUES = True
# ... those an "ld hl,HANDLER" hands set_channel_handler (0C33: "ld hl,$436A; jp $0C33", stop_channel 0C30 "ld
# hl,$0C39" runs into it): a function's address loaded for something else is a number (self_test_failed 0B28 "ld
# bc,$1000", a delay; fm_effect_33_retrigger "ld hl,$1208", a pitch)
SOUND_HANDLER_SETTERS = (0x0C33,)
# a pitch is a number, whatever data of the program ROM is at that address (fm_effect_0e "ld hl,$1400; ... call $0DE8"
# would read as a place in a patch): what set_pitch and pcm_set_pitch take in HL
SOUND_NUMBER_ARGUMENTS = {"set_pitch": ("hl",), "pcm_set_pitch": ("hl",)}
# the Z80 writes a record's words a byte at a time: two constant bytes stored at a field and the next are the field's
# word ("ld hl,$0600; ld (ix+$02),l; ld (ix+$03),h": pitch = 0x600; start_music_track 4255 "ld (ix+$3a),$FF; ld
# (ix+$3b),$FF": time = 0xFFFF), or the two fields' bytes (z80/pairs.py)
SOUND_JOIN_CONSTANT_STORES = True
# ... and a word of a record moved in HL ("ld l,(ix+$02); ld h,(ix+$03); add hl,de; ld (ix+$02),l; ld (ix+$03),h") is
# the word, not its two bytes (z80/pairs.py: the pair is not split into its bytes for that)
SOUND_WORDS_IN_MEMORY = True
# The 12 channel records (sound_symbols.txt's array line) are structures at a fixed address too: an access by the
# address of a field of one reads that field, by the name of its chip's channel (sound_main 0A4D-0AF4 gives each its
# own: "ld ix,$F003; ld (ix+$40),$00" up to "ld ix,$F373; ld (ix+$40),$0B"; F003-F233 the YM2151's 0-7, F283-F373 the
# K053260's voices 0-3)
SOUND_INSTANCES = True
SOUND_NAMED_BASES = {0xF003: "FM_0", 0xF053: "FM_1", 0xF0A3: "FM_2", 0xF0F3: "FM_3", 0xF143: "FM_4", 0xF193: "FM_5",
                     0xF1E3: "FM_6", 0xF233: "FM_7", 0xF283: "PCM_0", 0xF2D3: "PCM_1", 0xF323: "PCM_2",
                     0xF373: "PCM_3"}
# every handler runs on its record in IX (run_channel 0C1B-0C21 "ld l,(ix+$43); ld h,(ix+$44); jp (hl)"): what an
# effect or a drum keeps in +00-+07 means one thing to each (sound_symbols.txt's scoped lines, by the families of the
# handlers' names), and +46-+4F one thing to the YM2151's records and another to the K053260's (the pcm family)
SOUND_FAMILY_STRUCT = "channel"
SOUND_OBJECT_REGISTER = "ix"
SOUND_NESTED_FAMILIES = True
# sound_main sets up the K053260's records by their addresses (0A8D-0B0D "ld ix,$F283 ... ld (ix+$4a),l; ld
# (ix+$4b),h; ld (ix+$4c),$FE"...): what it writes there are the pcm family's fields
SOUND_INSTANCE_FAMILIES = {(0xF283, "sound_main"): "pcm", (0xF2D3, "sound_main"): "pcm",
                           (0xF323, "sound_main"): "pcm", (0xF373, "sound_main"): "pcm"}
# the names of what the code does with a value (decompiler/emit.py, as the 053248's PARAMS_BY_USE and the rest): the
# record a handler runs on is its channel, a value stored into one field only is what that field holds, a loop's DJNZ
# counts its count
SOUND_PARAMS_BY_USE = True
SOUND_NAMES_BY_STORES = True
SOUND_PARAMS_FROM_CALLERS = True
SOUND_NAMES_BY_COMPARISONS = True
SOUND_LOOP_COUNTERS = True
# a value a function keeps as it is and hands to a routine is what that routine calls it (fm_effect_01_move_pitch:
# "ld (ix+$02),l; ld (ix+$03),h; call $0DE8", the pitch)
SOUND_NAMES_PAST_STORES = True
