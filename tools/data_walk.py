"""
Name:        data_walk.py
Description: the program's data the code hands to its engines, walked as they read it: the objects' animations,
             their frames and sprite lists
Version:     0.1.0
Created:     05-11-2026
Modified:    05-11-2026
Author:      Sebastian Toyos

Usage: python tools/data_walk.py [rom folder or .zip] [--reads FOLDER]
Writes build/listing/data_walk.txt.

Places are the program region's offsets (tools/simpsons_rom.py), as symbols.txt and kref give them. The walk
starts from the tables symbols.txt names and reads what they lead to as the engine does (no traces: they only
measure the walk):
  animation sets   2-byte records by an object's kind (its field 04; the sprite engine, 079B02): animation_sets
                   for kinds 00-7F, animation_sets_high for 80-FF (bit 7 dropped); the bank the set's animations
                   are in, and the offset of the set's entry in the bank's set index
  set index        the words at 6000 in such a bank (079B3E "LDU #$6000; LDU D,U"): an animation table per set; it
                   ends where the first of them starts
  animation table  the addresses of a set's animations, by an object's animation (its field 05; 079B69): up to
                   the first entry that is no animation, the first place something else starts at, or the first
                   animation it holds past it
  animation        4-byte frames (079B74): the sprite count less one (bits 0-3) and a flip (bit 4), how many
                   frames to show it, its sprite list; or, bit 7 set, the animation's end: bit 0 clear, the
                   animation it goes on with (its number, a byte, and its address), set, the frame it goes back
                   to (its index, and the address of the animation it is in)
  sprite list      6 bytes a sprite (079C05, and 079CD4 when the object is zoomed): its code (bit 15: flipped
                   across), its colour, its attributes, its x and y from the object
  scene tables     the background maps of the K052109's layers A and B, by scene (direct page 75, which picks the
                   high tables from 80; the map engine, 07C5A2-07C930): the address of a list of records by the
                   scene's area (direct page 76): map_scenes_* (07C5B2 "LDY #$06,X", the layer's descriptor at EC9D)
                   and block_scenes_* (07C8BD, 07C8F7), side by side; and the layers' registers, layer_modes_*
                   (07C931: 1D80 and 1F00 of the K052109)
  scene list       4-byte records (07C5C0-07C5DC): an address, its bank, a zero; up to the next list or table,
                   or the next place the code names
  map              a word a strip of 256 pixels (07C5E5 "LDY A,Y", A the scroll's high byte twice): the strip's
                   address; the first is right after the words
  map strip        rows of 16 bytes, 8 cells of 32 pixels (07C759 "LDD ,Y", the next row 16 on): a cell's tile
                   block (bits 0-9: 07C75B "ANDA #$03") and its flips; as high as the strips are apart (07C67E-07C68D
                   take it from the next one), a screen (8 rows) when the map has one strip
  tile blocks      18 bytes a block (07C8B1: the scene's blocks plus 18 times the cell's block): the colour of its
                   tiles (07C6C2 "LDB ,X++" into the attribute RAM), the record of block_tile_flags it takes (07C6F4
                   "LDB #$01,X"), and its 4 x 4 tiles (07C6C6, a column; 07C6E3, a row)
  block tile flags 16 bytes a record (07C6FA "LDX #$F67C", 07C700 "LDB #$10; MUL"), up to the last one a block
                   takes
  palette sets     the palettes a request loads (the palette engine, 07BCBA: its byte 2 the set, from 80 in
                   palette_sets_high; byte 1 which of the 4 loads): 4 loads of 5 bytes, a palette's address in
                   bank 2D, where in the palette RAM it goes and how many palettes of 16 colours (07BCEA-07BCEF,
                   copied by 07BF51)
  palettes         32 bytes a palette, 16 colours (xBGR 555), in bank 2D
  palette effects  the words at 6000 in bank 2E (07BB45 "LDX #$6000; ... LDX D,X"): a script each, up to the first
                   of them
  palette effect   a script (07BB4F-07BB5F, then 07BD01): 2 bytes, the number of colours a step sets less one,
                   the frames to show a step; then the steps, a colour's place in the palette RAM and the colour
                   (07BD57 "LDY ,X++; LDD ,X++; STD ,Y"), up to a command, a byte with bit 7 set where a step would
                   start (07BDA8, by E975): 80 ends it, 81 plays it back to its start and on again, 82 repeats from
                   an address (its byte 1 the times, FF for ever; 4 bytes) and goes on past it
  spawn lists      by scene (direct page 67), the objects a stage puts in as its scroll reaches them (07C954, in bank
                   1B: spawn_lists): 8-byte records (07C9B5-07CA35), up to one of FF (07C9B5 "LDA #$00,X; CMPA
                   #$FF"); and the same lists of the objects bank 15's object puts in (object_15_spawn_lists)
  named table      every other table symbols.txt gives the length of (its table lines: NAME[COUNT] TYPE, a number's
                   type or a structure's)
  tile picture     a picture of tiles drawn into a layer (07C51C, by tile_pictures: a place record, its bank, where
                   in the tile RAM, the picture's address): its width and height in tiles, their colour, and a
                   tile code each, a row at a time (07C53A-07C556)
  test mode text   a text of the test mode (05E650, in bank 2F: by test_mode_texts, and the words they put in by
                   test_mode_words): a byte a character, 30-BF the tile 30 below it (05E65C, '@' a space); 00-2F
                   and the byte after it, the place in the fixed layer it goes on at (05E66E: 208C plus 64 times
                   the first plus the second); C1-C6 a new line (05E68B, by 6691); C7 and on a word, the one C7 below
                   it (05E6E6, by test_mode_words), which ends the text when it is the first; C0 its end. A
                   page's text (test_mode_texts, printed by 05E62A) is followed by its menu: 3 times the number of
                   its lines (05E636 "LDA ,U+" into 590A), the variable its cursor is in (05E63C "LDD ,U++"), and
                   3 bytes a line (05E646 "STU $590D"): the cursor's place in the tile RAM (05E539 "LDX ,X") and
                   what the line does (05E577 "LDA A,X", 20 nothing)
  object path      the steps an object of bank 1A flies (035364-0353A1, its field 2C the place it is at): 2 bytes
                   a step, a direction and a speed (035367 "LDD ,Y++"), up to FFFF; then where it starts again
                   (035369-03537E: the step after FFFF), the path it goes on with when its field 33 runs out, and
                   how many times the next one goes round (035373 "LDA #$04,Y"): 7 bytes. From the paths symbols.txt
                   names (data lines in PATHS) and the first field of the records of PATH_STARTS, and from where
                   each goes on
  demo             the attract mode's games (07A0A4, by direct page 5E: demos): who plays, how many frames, and the
                   inputs of each of the 4 players, in bank 2C (07A0C8 "LDB #$2C")
  demo inputs      2 bytes a step, the player's controls and the frames they are held (07A17C "LDA ,U", 07A192
                   "LDA #$01,U", 0 for 256), as recorded: past the frames the demo plays, up to the next player's
                   (the last, up to the zeros the recording ends with)
  story script     what an actor of the stories does (bank 1F: 03E273 "LDA ,Y+; CMPA #$FF; ...; LDU #$7000; JMP
                   [A,U]", the script in its field 2E, from story_scripts by its field 30: 03E09D "LDY #$7078; LDY
                   D,Y"): an operation and its arguments, up to FF, or up to where something else starts or a
                   byte that is no operation (the story ends with the actor on its last one: 03E8D8's 0C, code
                   right after it). How long each operation's arguments are is its
                   handler's to say, worked out from the code: what it takes with ,Y+ and ,Y++ and moves Y on with
                   LEAY n,Y on its way back to the loop (03E67C, 03E67F)
  unreached animation  in a bank of animations, an animation no table leads to (left from the game's making): frames
                   as above, every sprite list in the bank, its end going back to itself or to an animation walked
                   (a frame of it, or its start), with its sprite lists
  enemy behaviour  88 bytes (the fixed program's enemy routines, 07D3D7-07D662, read it from the object's field 2A:
                   07D5C0 "LDU #$2A,X; LEAU #$28,U", 07D604 "LDU #$2A,X", by the object's state 8 bytes a state, and
                   4 ranges of 12 bytes from 28 on, 07D3E9-07D3FD), at every place the code stores in the field
                   (029808 "LDU #$7808; STU #$2A,X"...), and every one the tables in BEHAVIOUR_TABLES hold, a
                   record's word at 2 (030137 "LDU #$79DA", 030154 "LDD #$02,U; STD #$2A,X")
  text             a text the fixed program's printer takes in U (07936D, 079384, 07939B; through 0785A5, 0786B6,
                   0786C8), at every place a call hands it: a place in the tile RAM (a word), a character a byte
                   (the tile 30 below it: '@' a space), '/' and the next place, '#' its end (079371-079377)
  argument record  a record a routine takes in a register (ARGUMENT_RECORDS), at every place a call hands it (the
                   register's constants where the call is, the call made straight or through the fixed program's
                   jumps, 0785AB "LBRA $D132"), and the records its fields point at
  unreached map    in a bank of maps, a map no scene leads to: its strips' addresses right after them, the
                   strips as far apart as the first two, up to what starts next
  more sprites     after a sprite list, up to 8 whole sprites that fill the gap to what starts next (lists no
                   frame shows)
  unused blocks    after an array of tile blocks, the whole blocks up to what starts next (no map takes them), or to
                   the assembler's leftovers at the bank's end
  more hit boxes   right after a hit box, up to 8 whole boxes up to what starts next
  unused palettes  in the palettes' bank, the whole palettes between the ones the sets load (as far)
and then what the code reads that none of these is, by what its instruction reads (the registers' values where it
runs, as the static analysis follows them: konami_cpu/analysis.py):
  value            a place an instruction reads at its address ($xxxx, n,PC), as wide as the read (LDA a byte,
                   LDD a word; [$xxxx] a word, the address it goes through)
  record           a place a register holds that an instruction reads fields of (n,X; ,X): from it to the end of
                   the furthest field read
  indexed table    a place a register holds that an instruction reads by an index (A,X; B,U; D,Y) or one entry
                   after another (,X+; ,U++): from it to the next place something else starts at, the code names,
                   or another such table starts at, in entries as wide as the read
  loaded table     a place an instruction loads into X, Y or U (LDX #, LDY #, LDU #) that nothing above walked: from
                   it to the next place something starts at or the code names; its shape is its reader's to tell
                   (the decompiler's pointer types), the walk says whose it is; it stops where the rest of the bank
                   repeats at the same offsets another bank's code or walked data (the assembler's leftovers)
The walk is right when every byte the engine's instructions read in the scenarios is in what it walked: with
--reads (the reference's rom_reads.txt, kref --rom-reads) the report lists the ones that are not.
"""
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
import game_profile  # noqa: E402  (the game's: its root, its ROM set)
from konami_cpu import analysis as konami_analysis  # noqa: E402

ROOT = game_profile.ROOT
place_of = konami_analysis.place_of
bank_of = konami_analysis.bank_of
cpu_of = konami_analysis.cpu_of
WINDOW, FIXED_CPU = konami_analysis.WINDOW, konami_analysis.FIXED_CPU

SET_TABLES = ("animation_sets", "animation_sets_high")
FRAME = 4
SPRITE = 6
END = 0x80                      # a frame's first byte with bit 7 set: the animation's end
BACK = 0x01                     # ... going back to a frame of its own (or of an animation it names)
MAX_TABLE = 256
MAX_FRAMES = 256
TABLE = re.compile(r"([0-9A-Fa-f]{6})\s+table\s+(\w+)\[(\d+)\]\s+(\w+)")
STRUCT = re.compile(r"struct\s+(\w+)\s+([0-9A-Fa-f]+)\b")
SIZES = {"u8": 1, "s8": 1, "u16": 2, "s16": 2, "u32": 4, "s32": 4}
# the engines' instructions that read what the walk reads, what --reads checks the walk against: the sprite engine
# (079B02-079E38), the map engine (07C5A2-07C930)
ENGINES = ((0x079B00, 0x079E39), (0x07C5A2, 0x07C931), (0x07BB12, 0x07BDE6), (0x07BF51, 0x07BF94),
           (0x07C954, 0x07CA50))
# the scene tables, each pair side by side (a scene's maps and its blocks, area by area), and the layers' registers
MAP_TABLES = (("map_scenes_a", "block_scenes_a"), ("map_scenes_a_high", "block_scenes_a_high"),
              ("map_scenes_b", "block_scenes_b"), ("map_scenes_b_high", "block_scenes_b_high"))
MODE_TABLES = ("layer_modes", "layer_modes_high")
SCENE_RECORD = 4
MODE_RECORD = 2
MAX_AREAS = 16
STRIP_ROW = 16
SCREEN_STRIP = 8 * STRIP_ROW
MAX_STRIPS = 64
BLOCK = 18
BLOCK_INDEX = 0x3FF
BLOCK_FLAGS = "block_tile_flags"
BLOCK_FLAGS_RECORD = 16
# the palettes: the sets of loads by request (palette_sets, palette_sets_high), the palettes in their bank (07BCBC "LDB
# #$2D"), the effects' scripts in theirs (07BB35 "LDB #$2E")
PALETTE_SETS = ("palette_sets", "palette_sets_high")
PALETTE_LOADS = 4
PALETTE_LOAD = 5
PALETTE = 32
PALETTE_BANK = 0x2D
EFFECT_BANK = 0x2E
EFFECT_HEADER = 4
EFFECT_STEP = 4
EFFECT_END, EFFECT_BACK, EFFECT_REPEAT = 0x80, 0x81, 0x82
FOREVER = 0xFF
MAX_EFFECTS = 256
MAX_EFFECT = 0x800
# the spawn lists, in bank 1B (07C961 "LDB #$1B")
# (and the ones a bank 15 object puts in by its stage: 02AD9A "LDY #$79FE", read at 02ADBB "LDA #$0000,Y; CMPA #$FF")
SPAWN_LISTS = ("spawn_lists", "object_15_spawn_lists")
SPAWN = 8
SPAWN_END = 0xFF
MAX_SPAWNS = 512
# the pictures of tiles (07C51C "LDU #$EFB5"), by their place records
TILE_PICTURES = "tile_pictures"
PICTURE_PLACE = 5
PICTURE_HEADER = 3
# the test mode's texts and the words they put in (05E62E "LDU #$75BE", 05E6E8 "LDU #$78F7"), in bank 2F
TEXT_TABLES = ("test_mode_texts", "test_mode_words")
TEXT_PLACE, TEXT_END, TEXT_WORD = 0x30, 0xC0, 0xC7
MAX_TEXT = 512
# the fixed program's printer (07936D prints, 079384 clears, 07939B by a colour; U the text) and its characters
FIXED_PRINTER = (0x07936D, 0x079384, 0x07939B)
FIXED_TEXT_END, FIXED_TEXT_LINE = 0x23, 0x2F
FIXED_TEXT_TABLES = ("game_texts",)
MENU_HEADER = 3
# the paths of bank 1A's objects: the ones the code loads (0353BE "LDD ,U" from object_1a_path_starts, 03532B "LDY
# #$79F3", 035434 "LDD #$7D72")
PATHS = ("object_1a_path", "object_1a_dive_path")
PATH_STARTS = ("object_1a_path_starts",)
PATH_END = 0xFFFF
PATH_STEP = 2
PATH_TAIL = 7
MAX_PATH = 0x400
# the attract mode's demos (07A0A4 "LDX #$E6A1"), their inputs in bank 2C (07A0C8 "LDB #$2C")
DEMOS = "demos"
DEMO = 12
DEMO_PLAYERS = 4
DEMO_BANK = 0x2C
DEMO_STEP = 2
DEMO_PADDING = 4                # the zeros a recording ends with, at least
# the stories' scripts in bank 1F: the table of operations (03E27B "LDU #$7000"), where a handler goes back to the loop
# (03E67C "LBRA $6273", 03E67F after it stores Y: the next frame), and the end
STORY_SCRIPTS = "story_scripts"
STORY_OPERATIONS = 0x7000
STORY_LOOP = (0x667C, 0x667F)
STORY_END = 0xFF
MAX_SCRIPT = 0x400
MAX_HANDLER = 400               # the instructions a handler is followed through, at most
# an enemy's behaviour, the object field it is in (the fixed program's enemy routines read it from there)
BEHAVIOUR = 88
BEHAVIOUR_FIELD = 0x2A
BEHAVIOUR_TABLES = ("object_18_behaviours",)
STORES = {"stu": "U", "sty": "Y", "std": "D", "stx": "X"}
# the routines that take a record in a register: (routine, register, bytes, kind, ((field, the routine whose record it
# points at), ...)): an object's setup (07D132-07D14D: its kind and animation, its hit box, fields 1B and 27) and a hit
# box (07D1B7-07D1C8: 4 words into fields 1C, 1F, 21, 23)
ARGUMENT_RECORDS = ((0x07D132, "U", 6, "object setup", ((2, 0x07D1B7),)),
                    (0x07D1B7, "Y", 8, "hit box", ()))
# what an instruction reads from memory, by its mnemonic: a byte or a word (BMOVE copies bytes from Y: an indexed table)
READS_8 = {"lda", "ldb", "cmpa", "cmpb", "adda", "addb", "suba", "subb", "anda", "andb", "ora", "orb", "eora", "eorb",
           "bita", "bitb", "adca", "adcb", "sbca", "sbcb", "tst"}
READS_16 = {"ldd", "ldx", "ldy", "ldu", "lds", "cmpd", "cmpx", "cmpy", "cmpu", "cmps", "addd", "subd", "tstw"}
MAX_GENERIC = 0x1000            # an indexed table runs no further than this
LOADS = ("ldx", "ldy", "ldu")
BOX = 8
MAX_MORE_BOXES = 8
MAX_MORE_SPRITES = 8
RESIDUE = 16                    # the bytes that must repeat another bank's for a loaded table to stop there
FIXED_START_PLACE = konami_analysis.FIXED_START


def table_places():
    """{name: (place, count, bytes an element)} of symbols.txt's table lines ('PLACE table NAME[COUNT] TYPE', TYPE a
    number's or a structure's: 'struct NAME SIZE'), which the analysis does not read"""
    lines = [line.split("#", 1)[0].strip() for line in (ROOT / "symbols.txt").read_text(encoding="utf-8").splitlines()]
    sizes = dict(SIZES)
    for line in lines:
        match = STRUCT.match(line)
        if match:
            sizes[match.group(1)] = int(match.group(2), 16)
    places = {}
    for line in lines:
        match = TABLE.match(line)
        if match:
            if match.group(4) not in sizes:
                raise SystemExit(f"data_walk: {match.group(2)}: no size for {match.group(4)}")
            places[match.group(2)] = (int(match.group(1), 16), int(match.group(3)), sizes[match.group(4)])
    return places


# what the walk reads from symbols.txt's table lines (the others it only claims)
WALKED = SET_TABLES + tuple(name for pair in MAP_TABLES for name in pair) + MODE_TABLES + (BLOCK_FLAGS,) + PALETTE_SETS \
    + SPAWN_LISTS + (TILE_PICTURES,) + TEXT_TABLES + FIXED_TEXT_TABLES + PATH_STARTS + (DEMOS, STORY_SCRIPTS) + BEHAVIOUR_TABLES


class Walk:
    """What the walk found: spans {first: (stop, kind)}, and the problems it ran into"""

    def __init__(self, analysis):
        self.analysis = analysis
        self.mem = analysis.mem
        self.spans = {}
        self.owner = {}             # every byte walked -> where its span starts
        self.problems = []
        self.notes = []             # what the walk found that the game does on purpose or by mistake, no problem
        self.sets = {}              # {(bank, offset): animation table place}
        self.tables = {}            # {animation table place: [animation places]}
        self.animations = set()
        self.lists = {}             # {sprite list place: sprites}
        self.maps = {}              # {map place: strips}
        self.scene_records = {}     # {scene list place: its records (areas)}
        self.blocks = {}            # {tile blocks place: blocks}
        self.palette_sets = set()
        self.palette_list = set()
        self.effects = set()
        self.spawns = {}            # {spawn list place: records}
        self.unreached = set()      # the animations no table leads to
        self.pictures = set()
        self.texts = set()
        self.paths = {}             # {object path place: its stop}
        self.demo_inputs = set()
        self.loaded = {}            # {loaded table place: the instruction that loads it}
        self.scripts = set()
        self.arguments = set()
        self.behaviours = set()
        self.residues = {}          # {place: whether the rest of its bank is the assembler's leftovers}
        self.tables_named = table_places()
        wanted = WALKED
        missing = [name for name in wanted if name not in self.tables_named]
        if missing:
            raise SystemExit("data_walk: symbols.txt names no " + ", ".join(missing))

    def claim(self, first, stop, kind):
        """The bytes first..stop are a 'kind'; False if they are code or something else already"""
        for place in range(first, stop):
            if place in self.analysis.owner:
                self.problems.append(f"{kind} at {first:06X} runs into code at {place:06X}")
                return False
        here = self.spans.get(first)
        if here == (stop, kind):
            return True
        taken = {self.owner[place] for place in range(first, stop) if place in self.owner}
        if here is not None:
            taken.add(first)
        if taken and all(self.spans[start][1] == kind for start in taken):
            # two of a kind that share bytes (a sprite list that starts inside another): one span
            first = min([first] + list(taken))
            stop = max([stop] + [self.spans[start][0] for start in taken])
            for start in taken:
                del self.spans[start]
            self.spans[first] = (stop, kind)
            for place in range(first, stop):
                self.owner[place] = first
            return True
        if taken:
            start = min(taken)
            other_stop, other_kind = self.spans[start]
            self.problems.append(f"{kind} at {first:06X}-{stop - 1:06X} runs over a {other_kind} at "
                                 f"{start:06X}-{other_stop - 1:06X}")
            return False
        self.spans[first] = (stop, kind)
        for place in range(first, stop):
            self.owner[place] = first
        return True

    # ---- reading ----

    def word(self, bank, cpu):
        return self.analysis.view(bank).r16(cpu)

    def byte(self, bank, cpu):
        return self.analysis.view(bank).r8(cpu)

    def in_bank(self, bank, cpu):
        """A place the bank's code or data can be at: the window, or the fixed program"""
        return WINDOW <= cpu < 0x10000 and place_of(bank, cpu) is not None

    def frames(self, bank, cpu):
        """The frames of the animation at 'cpu': [(cpu, sprite list or None)], the animation it goes on with
        ((cpu) or None); None if it is no animation"""
        frames = []
        for index in range(MAX_FRAMES):
            at = (cpu + FRAME * index) & 0xFFFF
            if not self.in_bank(bank, at) or not self.in_bank(bank, at + FRAME - 1):
                return None
            flags, pointer = self.byte(bank, at), self.word(bank, at + 2)
            if flags & END:
                if flags & ~(END | BACK) or not self.in_bank(bank, pointer):
                    return None
                frames.append((at, None))
                return frames, pointer
            if flags & 0x60 or not self.in_bank(bank, pointer):
                return None
            frames.append((at, pointer))
        return None

    # ---- walking ----

    def walk_sets(self):
        for name in SET_TABLES:
            table, count, _ = self.tables_named[name]
            self.claim(table, table + 2 * count, "animation sets")
            for index in range(count):
                bank, offset = self.mem.r8(table + 2 * index), self.mem.r8(table + 2 * index + 1)
                self.set_index(bank & 0x3F)
                self.sets[(bank & 0x3F, offset)] = place_of(bank & 0x3F, self.word(bank & 0x3F, WINDOW + offset))

    def set_index(self, bank):
        """The words at 6000: each an animation table, up to the first of them"""
        start = place_of(bank, WINDOW)
        if start in self.spans:
            return
        first = self.word(bank, WINDOW)
        if not WINDOW < first < FIXED_CPU or first % 2:
            self.problems.append(f"bank {bank:02X}: no set index at 6000 ({first:04X})")
            return
        stop = WINDOW
        tables = []
        while stop < first:
            tables.append(self.word(bank, stop))
            stop += 2
            first = min(first, *tables)
        self.claim(start, place_of(bank, stop), "set index")
        for cpu in tables:
            self.animation_table(bank, cpu, set(tables))

    def animation_table(self, bank, cpu, ends):
        table = place_of(bank, cpu)
        if table in self.tables:
            return
        entries = []
        bound = FIXED_CPU
        at = cpu
        while at < bound and len(entries) < MAX_TABLE:
            if at != cpu and (at in ends or place_of(bank, at) in self.owner):
                break
            value = self.word(bank, at)
            if not self.in_bank(bank, value) or self.frames(bank, value) is None:
                break
            entries.append(value)
            if at < value < FIXED_CPU:
                bound = min(bound, value)
            at += 2
        if not entries:
            self.problems.append(f"animation table at {table:06X}: no animation")
            return
        self.tables[table] = [place_of(bank, value) for value in entries]
        self.claim(table, table + 2 * len(entries), "animation table")
        for value in entries:
            self.animation(bank, value)

    def animation(self, bank, cpu):
        work = [cpu]
        while work:
            cpu = work.pop()
            place = place_of(bank, cpu)
            if place in self.animations:
                continue
            walked = self.frames(bank, cpu)
            if walked is None:
                self.problems.append(f"animation at {place:06X}: no frames")
                continue
            self.animations.add(place)
            frames, after = walked
            if not self.claim(place, place + FRAME * len(frames), "animation"):
                continue
            for at, sprites in frames:
                if sprites is None:
                    continue
                count = (self.byte(bank, at) & 0x0F) + 1
                self.sprite_list(bank, sprites, count)
            work.append(after)

    def sprite_list(self, bank, cpu, count):
        place = place_of(bank, cpu)
        if self.claim(place, place + SPRITE * count, "sprite list"):
            self.lists[place] = max(count, self.lists.get(place, 0))

    # ---- the background maps ----

    def scene_lists(self):
        """{table name: [the place of each scene's list]}, and {list place: records}: a list runs up to the next list
        or table, or the next place the code names as data"""
        lists = {}
        names = [name for pair in MAP_TABLES for name in pair] + list(MODE_TABLES)
        for name in names:
            table, count, _ = self.tables_named[name]
            self.claim(table, table + 2 * count, "scene table")
            lists[name] = [place_of(None, self.mem.r16(table + 2 * index)) for index in range(count)]
        starts = sorted({place for places in lists.values() for place in places}
                        | {self.tables_named[name][0] for name in names} | self.analysis.named)
        records = {}
        for name in names:
            record = MODE_RECORD if name in MODE_TABLES else SCENE_RECORD
            for place in lists[name]:
                following = next(start for start in starts if start > place)
                count = 0
                while count < MAX_AREAS and place + record * (count + 1) <= following \
                        and place + record * count not in self.analysis.owner:
                    count += 1
                records[place] = count
                self.claim(place, place + record * count, "scene list")
        return lists, records

    def map(self, bank, cpu):
        """The cells of the map at 'cpu' in 'bank' (claimed), or None if it is none"""
        place = place_of(bank, cpu)
        first = self.word(bank, cpu)
        count = (first - cpu) // 2
        if not WINDOW <= first < FIXED_CPU or (first - cpu) % 2 or not 0 < count <= MAX_STRIPS:
            self.problems.append(f"map at {place:06X}: its first strip is at {first:04X}")
            return None
        strips = [self.word(bank, cpu + 2 * index) for index in range(count)]
        distinct = sorted(set(strips))
        apart = sorted({b - a for a, b in zip(distinct, distinct[1:])})
        height = apart[0] if apart else SCREEN_STRIP
        if len(apart) > 1 or height % STRIP_ROW:
            self.problems.append(f"map at {place:06X}: strips {' '.join(f'{strip:04X}' for strip in strips)}")
        self.maps[place] = len(strips)
        self.claim(place, place + 2 * count, "map")
        cells = set()
        for strip in distinct:
            first_place = place_of(bank, strip)
            if self.claim(first_place, first_place + height, "map strip"):
                cells.update(self.word(bank, strip + offset) for offset in range(0, height, 2))
        return cells

    def background(self):
        lists, records = self.scene_lists()
        self.scene_records = records
        wanted = {}                 # {(bank, cpu) of tile blocks: the blocks the maps take}
        for maps_name, blocks_name in MAP_TABLES:
            for maps_list, blocks_list in zip(lists[maps_name], lists[blocks_name]):
                for area in range(min(records[maps_list], records[blocks_list])):
                    map_record, blocks_record = maps_list + SCENE_RECORD * area, blocks_list + SCENE_RECORD * area
                    cells = self.map(self.mem.r8(map_record + 2) & 0x3F, self.mem.r16(map_record))
                    if cells is None:
                        continue
                    blocks = (self.mem.r8(blocks_record + 2) & 0x3F, self.mem.r16(blocks_record))
                    wanted[blocks] = max([wanted.get(blocks, 0)] + [(cell & BLOCK_INDEX) + 1 for cell in cells])
        flags = 0
        for (bank, cpu), count in sorted(wanted.items()):
            place = place_of(bank, cpu)
            stop = cpu + BLOCK * count
            if stop > FIXED_CPU:
                # (the blocks past the window's end are the fixed program's bytes: the game reads its code as tiles,
                # bank 0E's 753C blocks 153 on, 07C6C6 reading 078593 on)
                self.notes.append(f"tile blocks at {place:06X}: {count} blocks, past 7FFF from block "
                                  f"{(FIXED_CPU - cpu) // BLOCK}: the fixed program's code read as tiles")
                count = -(-(FIXED_CPU - cpu) // BLOCK)
                stop = FIXED_CPU
            if self.claim(place, place + stop - cpu, "tile blocks"):
                self.blocks[place] = count
                flags = max([flags] + [self.byte(bank, cpu + BLOCK * index + 1) + 1 for index in range(count)])
        table, _, _ = self.tables_named[BLOCK_FLAGS]
        self.claim(table, table + BLOCK_FLAGS_RECORD * flags, "block tile flags")

    # ---- the palettes ----

    def palettes(self):
        for name in PALETTE_SETS:
            table, count, _ = self.tables_named[name]
            self.claim(table, table + 2 * count, "palette set table")
            for index in range(count):
                cpu = self.mem.r16(table + 2 * index)
                place = place_of(None, cpu)
                if place is None or not self.claim(place, place + PALETTE_LOADS * PALETTE_LOAD, "palette sets"):
                    continue
                self.palette_sets.add(place)
                for load in range(PALETTE_LOADS):
                    source = self.mem.r16(place + PALETTE_LOAD * load)
                    palettes = self.mem.r8(place + PALETTE_LOAD * load + 4)
                    first = place_of(PALETTE_BANK, source)
                    if first is None or not WINDOW <= source + PALETTE * palettes <= FIXED_CPU:
                        self.problems.append(f"palette set at {place:06X}: load {load} from {source:04X}")
                        continue
                    for number in range(palettes):
                        self.claim(first + PALETTE * number, first + PALETTE * (number + 1), "palettes")
                        self.palette_list.add(first + PALETTE * number)

    def palette_effects(self):
        """The scripts at 6000 in the effects' bank, up to the first"""
        first = self.word(EFFECT_BANK, WINDOW)
        count = (first - WINDOW) // 2
        if not 0 < count <= MAX_EFFECTS:
            self.problems.append(f"no palette effects at 6000 in bank {EFFECT_BANK:02X} ({first:04X})")
            return
        scripts = [self.word(EFFECT_BANK, WINDOW + 2 * index) for index in range(count)]
        self.claim(place_of(EFFECT_BANK, WINDOW), place_of(EFFECT_BANK, WINDOW + 2 * count), "palette effects")
        for cpu in sorted(set(scripts)):
            colours = self.byte(EFFECT_BANK, cpu + 2) + 1
            at = cpu + EFFECT_HEADER
            while at < FIXED_CPU and at - cpu < MAX_EFFECT:
                command = self.byte(EFFECT_BANK, at)
                if command & 0x80:
                    if command == EFFECT_REPEAT:
                        at += 4
                        if self.byte(EFFECT_BANK, at - 3) != FOREVER:
                            continue
                    elif command in (EFFECT_END, EFFECT_BACK):
                        at += 1
                    else:
                        self.problems.append(f"palette effect at {place_of(EFFECT_BANK, cpu):06X}: command {command:02X}")
                    break
                at += EFFECT_STEP * colours
            place = place_of(EFFECT_BANK, cpu)
            if self.claim(place, place + at - cpu, "palette effect"):
                self.effects.add(place)

    # ---- the stages' objects ----

    def spawn_lists(self):
        """The lists of 8-byte records up to one of FF the tables in SPAWN_LISTS lead to, in the table's bank"""
        for name in SPAWN_LISTS:
            table, count, _ = self.tables_named[name]
            bank = bank_of(table)
            self.claim(table, table + 2 * count, "spawn list table")
            for index in range(count):
                cpu = self.mem.r16(table + 2 * index)
                place = place_of(bank, cpu)
                records = 0
                while records < MAX_SPAWNS and self.byte(bank, cpu + SPAWN * records) != SPAWN_END:
                    records += 1
                if self.claim(place, place + SPAWN * (records + 1), "spawn list"):
                    self.spawns[place] = records

    def tile_pictures(self):
        table, count, _ = self.tables_named[TILE_PICTURES]
        self.claim(table, table + 2 * count, "tile picture table")
        for index in range(count):
            record = place_of(None, self.mem.r16(table + 2 * index))
            if record is None or not self.claim(record, record + PICTURE_PLACE, "tile picture place"):
                continue
            bank, cpu = self.mem.r8(record) & 0x3F, self.mem.r16(record + 3)
            place = place_of(bank, cpu)
            size = PICTURE_HEADER + self.byte(bank, cpu) * self.byte(bank, cpu + 1)
            if place is not None and self.claim(place, place + size, "tile picture"):
                self.pictures.add(place)

    def test_mode_texts(self):
        for name in TEXT_TABLES:
            table, count, _ = self.tables_named[name]
            bank = bank_of(table)
            self.claim(table, table + 2 * count, "text table")
            for index in range(count):
                cpu = self.mem.r16(table + 2 * index)
                at = cpu
                while at - cpu < MAX_TEXT:
                    code = self.byte(bank, at)
                    at += 2 if code < TEXT_PLACE else 1
                    if code in (TEXT_END, TEXT_WORD):
                        break
                kind = "test mode text"
                if name == TEXT_TABLES[0]:
                    at += MENU_HEADER + self.byte(bank, at)
                    kind = "test mode page"
                place = place_of(bank, cpu)
                if self.claim(place, place + at - cpu, kind):
                    self.texts.add(place)

    def object_paths(self):
        names = {symbol.name: place for place, symbol in self.analysis.symbols.items()}
        missing = [name for name in PATHS if name not in names]
        if missing:
            raise SystemExit("data_walk: symbols.txt names no " + ", ".join(missing))
        work = [names[name] for name in PATHS]
        for name in PATH_STARTS:
            table, count, size = self.tables_named[name]
            self.claim(table, table + count * size, "path starts")
            work += [place_of(bank_of(table), self.mem.r16(table + size * index)) for index in range(count)]
        while work:
            place = work.pop()
            if place is None or place in self.paths or any(first <= place < stop for first, stop in self.paths.items()):
                continue
            bank, cpu = bank_of(place), cpu_of(place)
            at = cpu
            while at - cpu < MAX_PATH and self.word(bank, at) != PATH_END:
                at += PATH_STEP
            if self.word(bank, at) != PATH_END:
                self.problems.append(f"object path at {place:06X}: no end")
                continue
            stop = place + at - cpu + PATH_TAIL
            if self.claim(place, stop, "object path"):
                self.paths[place] = stop
                work += [place_of(bank, self.word(bank, at + 2)), place_of(bank, self.word(bank, at + 4))]

    def demos(self):
        table, count, _ = self.tables_named[DEMOS]
        self.claim(table, table + 2 * count, "demo table")
        streams = {}                # {cpu: the frames its demo plays}
        for index in range(count):
            demo = place_of(None, self.mem.r16(table + 2 * index))
            if demo is None or not self.claim(demo, demo + DEMO, "demo"):
                continue
            for player in range(DEMO_PLAYERS):
                cpu = self.mem.r16(demo + 4 + 2 * player)
                streams[cpu] = max(streams.get(cpu, 0), self.mem.r16(demo + 1))
        starts = sorted(streams)
        for position, cpu in enumerate(starts):
            if position + 1 < len(starts):
                stop = starts[position + 1]
            else:
                # (the frames the demo plays, then the recording's end, up to its zeros and past them)
                stop, frames = cpu, 0
                while frames < streams[cpu] and stop < FIXED_CPU:
                    frames += self.byte(DEMO_BANK, stop + 1) or 256
                    stop += DEMO_STEP
                while stop < FIXED_CPU and any(self.byte(DEMO_BANK, stop + offset) for offset in range(DEMO_PADDING)):
                    stop += DEMO_STEP
                while stop < FIXED_CPU and self.byte(DEMO_BANK, stop) == 0:
                    stop += 1
            place = place_of(DEMO_BANK, cpu)
            if self.claim(place, place + stop - cpu, "demo inputs"):
                self.demo_inputs.add(place)

    def operation_lengths(self, bank, table, loop):
        """{operation: the bytes of arguments it takes}, by the handlers of the table of code at 'table' (the
        analysis reads it): what each takes from Y (,Y+ and ,Y++) and moves Y on (LEAY n,Y) on every way back to
        'loop'; None for one whose ways disagree"""
        dis = konami_analysis.dis
        place = place_of(bank, table)
        entries = next((entries for key, entries in self.analysis.code_tables.items() if key[0] == place), [])
        lengths = {}
        for operation, (cpu, handler_bank) in enumerate(entries):
            found = set()
            work, seen = [(cpu, 0)], set()
            while work and len(seen) < MAX_HANDLER:
                at, taken = work.pop()
                if (at, taken) in seen:
                    continue
                seen.add((at, taken))
                instruction = self.analysis.decode(handler_bank if at < FIXED_CPU else None, at)
                for operand in instruction.operands:
                    if operand.mode == "indexed" and operand.reg == "Y" and operand.kind in ("postinc", "postinc2"):
                        taken += 1 if operand.kind == "postinc" else 2
                if instruction.mnemonic == "leay":
                    operand = instruction.operands[0]
                    if operand.kind != "offset" or operand.reg != "Y":
                        found.add(None)
                        continue
                    taken += operand.disp
                if instruction.flow in (dis.FLOW_RETURN, dis.FLOW_INVALID):
                    found.add(None)
                    continue
                if instruction.flow in (dis.FLOW_JUMP, dis.FLOW_BRANCH):
                    if instruction.target in loop:
                        found.add(taken)
                    elif instruction.target is not None:
                        work.append((instruction.target, taken))
                    else:
                        found.add(None)
                    if instruction.flow == dis.FLOW_JUMP:
                        continue
                work.append(((at + instruction.length) & 0xFFFF, taken))
            lengths[operation] = found.pop() if len(found) == 1 else None
        return lengths

    def story_scripts(self):
        table, count, _ = self.tables_named[STORY_SCRIPTS]
        bank = bank_of(table)
        lengths = self.operation_lengths(bank, STORY_OPERATIONS, STORY_LOOP)
        bad = sorted(operation for operation, length in lengths.items() if length is None)
        if bad or not lengths:
            self.problems.append(f"story operations without a length: {bad or 'no table'}")
        self.claim(table, table + 2 * count, "story script table")
        for cpu in sorted({self.mem.r16(table + 2 * index) for index in range(count)}):
            at = cpu
            while at - cpu < MAX_SCRIPT:
                here = place_of(bank, at)
                if here in self.analysis.owner or at != cpu and (here in self.owner or here == table):
                    break           # (the story ends with the actor still on its last operation: 03E8D8's 0C)
                operation = self.byte(bank, at)
                if lengths.get(operation) is None and operation != STORY_END:
                    self.notes.append(f"story script at {place_of(bank, cpu):06X}: ends before {operation:02X} at "
                                      f"{at:04X}, no operation")
                    break
                at += 1
                if operation == STORY_END:
                    break
                at += lengths[operation]
            place = place_of(bank, cpu)
            if self.claim(place, place + at - cpu, "story script"):
                self.scripts.add(place)

    # ---- what nothing leads to ----

    def unreached_animations(self):
        """Animations in the banks of animations that no table leads to, left to right through what nothing claims;
        each must end going back to itself or to an animation walked, and show sprite lists in the bank"""
        banks = sorted({bank_of(place) for place in self.animations})
        starts = set(self.animations)
        for bank in banks:
            cpu = WINDOW
            while cpu < FIXED_CPU - FRAME:
                place = place_of(bank, cpu)
                if place in self.owner or place in self.analysis.owner:
                    cpu += 1
                    continue
                found = self.unreached_animation(bank, cpu, starts)
                if found is None:
                    cpu += 1
                    continue
                frames, after = found
                self.claim(place, place + FRAME * len(frames), "unreached animation")
                self.animations.add(place)
                starts.add(place)
                self.unreached.add(place)
                for at, sprites in frames:
                    if sprites is not None:
                        self.sprite_list(bank, sprites, (self.byte(bank, at) & 0x0F) + 1)
                cpu += FRAME * len(frames)

    def unreached_animation(self, bank, cpu, starts):
        walked = self.frames(bank, cpu)
        if walked is None:
            return None
        frames, after = walked
        if len(frames) < 2:
            return None
        end = place_of(bank, after)
        if not (cpu <= after < cpu + FRAME * len(frames) and (after - cpu) % FRAME == 0) and end not in starts:
            return None
        for at, sprites in frames:
            if sprites is None:
                continue
            first = place_of(bank, sprites)
            stop = first + SPRITE * ((self.byte(bank, at) & 0x0F) + 1)
            if not WINDOW <= sprites or sprites + (stop - first) > FIXED_CPU or self.byte(bank, at + 1) == 0:
                return None
            # (a sprite list walked already, or bytes nothing claims)
            for byte in range(first, stop):
                owner = self.owner.get(byte)
                if byte in self.analysis.owner or owner is not None and self.spans[owner][1] != "sprite list":
                    return None
        return frames, after

    # ---- the enemies' behaviours ----

    def enemy_behaviours(self):
        states = self.instruction_states()
        found = set()
        for place, instruction in self.analysis.instructions.items():
            register = STORES.get(instruction.mnemonic)
            operand = instruction.operands[0] if instruction.operands else None
            if register is None or operand.mode != "indexed" or operand.kind != "offset" or operand.reg != "X" \
                    or operand.disp != BEHAVIOUR_FIELD:
                continue
            state = states.get(place, {})
            for kind, value in konami_analysis.known(state.get(register)):
                if kind == konami_analysis.CONSTANT:
                    for bank in konami_analysis.banks_in(state):
                        behaviour = place_of(bank, value)
                        if behaviour is not None and behaviour not in self.analysis.owner:
                            found.add(behaviour)
        # (and the ones tables of records hold, by the records' word at 2: the field means something else to some
        # objects, bank 15's spawner and bank 17's, so the tables are symbols.txt's)
        for name in BEHAVIOUR_TABLES:
            table, count, size = self.tables_named[name]
            for index in range(count):
                behaviour = place_of(bank_of(table), self.mem.r16(table + size * index + 2))
                if behaviour is not None:
                    found.add(behaviour)
        for behaviour in sorted(found):
            if self.claim(behaviour, behaviour + BEHAVIOUR, "enemy behaviour"):
                self.behaviours.add(behaviour)

    # ---- the records routines take ----

    def call_arguments(self, registers):
        """{routine: {(bank, cpu)}}: the constants the register 'registers' ({routine: register}) gives each routine
        holds where a call or jump goes to it, straight or through the fixed program's jumps that only go on to it
        (0785AB "LBRA $D132")"""
        dis = konami_analysis.dis
        states = self.instruction_states()
        through = {}
        for place, instruction in self.analysis.instructions.items():
            if instruction.flow == dis.FLOW_JUMP and instruction.target is not None:
                target = place_of(bank_of(place), instruction.target)
                if target in registers:
                    through[place] = target
        found = defaultdict(set)
        for place, instruction in self.analysis.instructions.items():
            if instruction.flow not in (dis.FLOW_CALL, dis.FLOW_JUMP) or instruction.target is None:
                continue
            target = place_of(bank_of(place), instruction.target)
            routine = through.get(target, target)
            if routine not in registers or place in through:
                continue
            state = states.get(place, {})
            for kind, value in konami_analysis.known(state.get(registers[routine])):
                if kind == konami_analysis.CONSTANT:
                    for bank in konami_analysis.banks_in(state):
                        found[routine].add((bank, value))
        return found

    def argument_records(self):
        specs = {routine: (register, size, kind, pointers) for routine, register, size, kind, pointers in ARGUMENT_RECORDS}
        records = self.call_arguments({routine: spec[0] for routine, spec in specs.items()})
        work = [(routine, bank, cpu) for routine, held in records.items() for bank, cpu in held]
        done = set()
        while work:
            routine, bank, cpu = work.pop()
            if (routine, bank, cpu) in done:
                continue
            done.add((routine, bank, cpu))
            register, size, kind, pointers = specs[routine]
            place = place_of(bank, cpu)
            if place is None or place_of(bank, cpu + size - 1) is None:
                continue
            if self.claim(place, place + size, kind):
                self.arguments.add(place)
                for field, pointed in pointers:
                    work.append((pointed, bank, self.word(bank, cpu + field)))

    def fixed_texts(self):
        """The texts the fixed program's printer takes in U (079384, 07936D, 07939B): a place in the tile RAM (a word),
        its characters (the tile 30 below each), '/' and the next place, '#' its end"""
        texts = {text for held in self.call_arguments({routine: "U" for routine in FIXED_PRINTER}).values()
                 for text in held}
        # (and the game's texts by number, 079311: "LDX $6021" in bank 12, "LDU B,X")
        for name in FIXED_TEXT_TABLES:
            table, count, _ = self.tables_named[name]
            self.claim(table, table + 2 * count, "text table")
            texts.update((bank_of(table), self.mem.r16(table + 2 * index)) for index in range(count))
        for bank, cpu in sorted(texts):
            at = cpu + 2
            while at - cpu < MAX_TEXT:
                code = self.byte(bank, at)
                at += 1
                if code == FIXED_TEXT_END:
                    break
                if code == FIXED_TEXT_LINE:
                    at += 2
            place = place_of(bank, cpu)
            if place is not None and self.claim(place, place + at - cpu, "text"):
                self.texts.add(place)

    def next_start(self, place, limit):
        """The first byte after 'place' that is claimed or code, or 'limit'"""
        stop = place + 1
        while stop < limit and stop not in self.owner and stop not in self.analysis.owner:
            stop += 1
        return stop

    def more_sprite_lists(self):
        """After a sprite list in a bank of animations, whole sprites up to what starts next (lists no frame shows)"""
        for place, (stop, kind) in sorted(self.spans.items()):
            if kind != "sprite list" or stop in self.owner or stop in self.analysis.owner:
                continue
            end = self.next_start(stop, (stop // 0x2000 + 1) * 0x2000)
            # (a few, filling the gap to what starts next: a longer run is the assembler's leftovers as often)
            if 0 < end - stop <= MAX_MORE_SPRITES * SPRITE and (end - stop) % SPRITE == 0                     and not self.same_elsewhere(stop, end):
                self.claim(stop, end, "sprite list")

    def unreached_maps(self):
        banks = sorted({bank_of(place) for place in self.maps})
        for bank in banks:
            cpu = WINDOW
            while cpu < FIXED_CPU - 4:
                place = place_of(bank, cpu)
                if place in self.owner or place in self.analysis.owner:
                    cpu += 1
                    continue
                first = self.word(bank, cpu)
                count = (first - cpu) // 2
                strips = [self.word(bank, cpu + 2 * index) for index in range(count)] if 0 < count <= 8 else []
                apart = {b - a for a, b in zip(strips, strips[1:])}
                height = apart.pop() if len(apart) == 1 else SCREEN_STRIP if len(strips) == 1 else 0
                stop = place + 2 * count + height * len(strips)
                if (first - cpu) % 2 == 0 and strips and height and height % STRIP_ROW == 0 \
                        and self.next_start(place, stop) == stop:
                    self.claim(place, place + 2 * count, "unreached map")
                    self.claim(place + 2 * count, stop, "map strip")
                    self.maps[place] = len(strips)
                    cpu += stop - place
                else:
                    cpu += 1

    def unused_blocks(self):
        for place, count in sorted(self.blocks.items()):
            stop = place + BLOCK * count
            if stop in self.owner or stop in self.analysis.owner or bank_of(stop) != bank_of(place):
                continue
            end = self.next_start(stop, (bank_of(place) + 1) * 0x2000)
            whole = 0
            # (up to the assembler's leftovers at the bank's end, if they come first)
            while stop + whole + BLOCK <= end and not self.residue_at(stop + whole):
                whole += BLOCK
            if whole and self.claim(stop, stop + whole, "unused blocks"):
                self.notes.append(f"tile blocks at {place:06X}: {whole // BLOCK} more blocks after the {count} the maps take")

    def more_boxes(self):
        """After a hit box, whole boxes up to what starts next (boxes kept together, which no call hands over)"""
        for place, (stop, kind) in sorted(self.spans.items()):
            if kind != "hit box" or stop in self.owner or stop in self.analysis.owner:
                continue
            end = self.next_start(stop, (stop // 0x2000 + 1) * 0x2000)
            if (end - stop) % BOX == 0 and 0 < end - stop <= MAX_MORE_BOXES * BOX and not self.residue_at(stop):
                self.claim(stop, end, "hit box")

    def unused_palettes(self):
        start = PALETTE_BANK * 0x2000
        place = start
        while place < start + 0x2000:
            if place in self.owner or self.mem.r8(place) == 0xFF and self.mem.r8(place + 1) == 0xFF:
                place += 1
                continue
            stop = self.next_start(place, start + 0x2000)
            whole = 0
            while place + whole + PALETTE <= stop and not self.residue_at(place + whole):
                whole += PALETTE
            if whole:
                self.claim(place, place + whole, "unused palettes")
            place = stop

    # ---- what the code reads, by its instructions ----

    def instruction_states(self):
        """{place: what the registers and the bank hold before the instruction there runs}: each block from the state
        the analysis gives where it starts, stepped as the analysis steps it"""
        analysis = self.analysis
        dis = konami_analysis.dis
        states = {}
        for start, entry in analysis.entry_states.items():
            state = dict(entry)
            place = start
            bank = bank_of(start)
            while place in analysis.instructions and (place == start or place not in analysis.entry_states):
                instruction = analysis.instructions[place]
                states[place] = state
                if instruction.flow == dis.FLOW_CALL:
                    state = {key: values for key, values in state.items() if key in ("bank", "shadow")}
                elif instruction.flow in (dis.FLOW_JUMP, dis.FLOW_RETURN, dis.FLOW_INVALID):
                    break
                elif instruction.flow == dis.FLOW_NORMAL:
                    state = dict(state)
                    analysis.step(instruction, state)
                    if instruction.mnemonic == "setln" and bank is not None:
                        break
                cpu = cpu_of(place)
                following = place_of(bank, (cpu + instruction.length) & 0xFFFF)
                if following is None or following != place + instruction.length and bank is not None:
                    break
                place = following
        return states

    def generic(self):
        known_kinds = konami_analysis.known
        CONSTANT = konami_analysis.CONSTANT
        states = self.instruction_states()
        absolute = {}               # {place: width}
        fields = defaultdict(dict)  # {record place: {offset: width}}
        indexed = {}                # {table place: entry width}
        for place, instruction in sorted(self.analysis.instructions.items()):
            if instruction.flow != konami_analysis.dis.FLOW_NORMAL:
                continue
            mnemonic = instruction.mnemonic
            width = 1 if mnemonic in READS_8 else 2 if mnemonic in READS_16 else 0
            state = states.get(place)
            if state is None:
                continue
            banks = konami_analysis.banks_in(state)
            if mnemonic == "bmove":
                for kind, value in known_kinds(state.get("Y")):
                    if kind == CONSTANT:
                        for bank in banks:
                            table = place_of(bank, value)
                            if table is not None:
                                indexed[table] = 1
                continue
            for operand in instruction.operands:
                if operand.mode != "indexed" or operand.kind in ("direct", "invalid"):
                    continue
                read = 2 if operand.indirect else width
                if not read:
                    continue
                if operand.kind == "extended" or operand.kind == "offset" and operand.reg == "PC":
                    value = operand.value if operand.kind == "extended" else operand.target
                    for bank in banks:
                        at = place_of(bank, value)
                        if at is not None:
                            absolute[at] = max(read, absolute.get(at, 0))
                    continue
                if operand.reg not in konami_analysis.REGISTERS:
                    continue
                for kind, value in known_kinds(state.get(operand.reg)):
                    if kind != CONSTANT:
                        continue
                    for bank in banks:
                        base = place_of(bank, value)
                        if base is None:
                            continue
                        if operand.kind == "accumulator":
                            offsets = [amount for option, amount in self.analysis.index_options(operand.accumulator, state)
                                       if option == "offset"]
                            if offsets and len(offsets) == len(self.analysis.index_options(operand.accumulator, state)):
                                for amount in offsets:
                                    at = place_of(bank, (value + amount) & 0xFFFF)
                                    if at is not None:
                                        absolute[at] = max(read, absolute.get(at, 0))
                            else:
                                indexed[base] = max(read, indexed.get(base, 0))
                        elif operand.kind in ("offset", "register"):
                            disp = operand.disp if operand.kind == "offset" else 0
                            if disp >= 0:
                                fields[base][disp] = max(read, fields[base].get(disp, 0))
                        elif operand.kind in ("postinc", "postinc2", "predec", "predec2"):
                            indexed[base] = max(read, indexed.get(base, 0))
        for at, size in sorted(absolute.items()):
            if self.free(at, at + size):
                self.claim(at, at + size, "value")
        for base, read in sorted(fields.items()):
            stop = base + max(offset + size for offset, size in read.items())
            if self.free(base, stop):
                self.claim(base, stop, "record")
        starts = sorted(set(indexed) | self.analysis.named | set(self.spans))
        for base, size in sorted(indexed.items()):
            if base in self.owner or base in self.analysis.owner:
                continue
            following = next((start for start in starts if start > base), base + MAX_GENERIC)
            stop = base
            limit = min(following, base + MAX_GENERIC, (base // 0x2000 + 1) * 0x2000)
            while stop < limit and stop not in self.owner and stop not in self.analysis.owner:
                stop += 1
            length = (stop - base) // size * size
            if length:
                self.claim(base, base + length, "indexed table")

    def loaded_tables(self):
        loads = {}
        for place, instruction in sorted(self.analysis.instructions.items()):
            if instruction.mnemonic not in LOADS or not instruction.operands \
                    or instruction.operands[0].mode != "immediate":
                continue
            for named in self.analysis.named_by.get(place, ()):
                loads.setdefault(named, place)
        starts = sorted(set(loads) | self.analysis.named | set(self.spans))
        for place, loader in sorted(loads.items()):
            if place in self.owner or place in self.analysis.owner:
                continue
            limit = FIXED_START_PLACE + 0x8000 if place >= FIXED_START_PLACE else (place // 0x2000 + 1) * 0x2000
            following = next((start for start in starts if start > place), limit)
            stop = place + 1
            while stop < min(following, limit) and stop not in self.owner and stop not in self.analysis.owner                     and not self.residue_at(stop):
                stop += 1
            if self.claim(place, stop, "loaded table"):
                self.loaded[place] = loader

    def same_elsewhere(self, first, stop):
        """Are the bytes first..stop another bank's at the same offsets, where they are code or walked? (the
        assembler's leftovers, which the coverage counts as fill)"""
        image = self.analysis.image
        offset = first % 0x2000
        if offset + stop - first > 0x2000:
            return False
        for bank in range(len(image) // 0x2000):
            other = bank * 0x2000 + offset
            if other != first and image[other:other + stop - first] == image[first:stop]                     and any(byte in self.analysis.owner or byte in self.owner for byte in range(other, other + stop - first)):
                return True
        return False

    def residue_at(self, place):
        """Does the rest of the bank from 'place' (up to the 0xFF it ends with) repeat, at the same offsets, another
        bank's code or walked data? What the assembler's buffer kept from that bank (the coverage's residue), where no
        table runs on"""
        image = self.analysis.image
        end = (place // 0x2000 + 1) * 0x2000
        if place not in self.residues:
            while end > place and image[end - 1] == 0xFF:
                end -= 1
            found = False
            if end - place >= RESIDUE:
                offset = place % 0x2000
                for bank in range(len(image) // 0x2000):
                    other = bank * 0x2000 + offset
                    if other != place and image[other:other + end - place] == image[place:end]                             and any(byte in self.analysis.owner or byte in self.owner for byte in range(other, other + end - place)):
                        found = True
                        break
            self.residues[place] = found
        return self.residues[place]

    def free(self, first, stop):
        """No byte of first..stop walked yet, nor code"""
        return not any(place in self.owner or place in self.analysis.owner for place in range(first, stop))

    def named_tables(self):
        """The tables symbols.txt gives the length of that nothing else walks"""
        for name, (place, count, size) in sorted(self.tables_named.items()):
            if name not in WALKED:
                self.claim(place, place + count * size, "named table")

    def run(self):
        self.walk_sets()
        self.background()
        self.palettes()
        self.palette_effects()
        self.spawn_lists()
        self.tile_pictures()
        self.test_mode_texts()
        self.object_paths()
        self.demos()
        self.story_scripts()
        self.named_tables()
        self.argument_records()
        self.fixed_texts()
        self.enemy_behaviours()
        self.generic()
        self.unreached_animations()
        self.more_sprite_lists()
        self.unreached_maps()
        self.unused_blocks()
        self.unused_palettes()
        self.more_boxes()
        self.loaded_tables()


def spans(analysis):
    """For the coverage (the profile's DATA_WALK): {first: (stop, kind)} of what the walk reads"""
    walk = Walk(analysis)
    walk.run()
    return walk.spans


def load_reads(folder):
    """{pc: places it read} from every rom_reads.txt under 'folder'"""
    reads = defaultdict(set)
    for path in sorted(Path(folder).rglob("rom_reads.txt")):
        for line in path.read_text(encoding="ascii").splitlines():
            if not line.strip() or line.startswith("#"):
                continue
            pc, span = line.split()
            first, last = (int(value, 16) for value in span.split("-"))
            reads[int(pc, 16)].update(range(first, last + 1))
    return reads


def report(walk, reads=None):
    kinds = Counter()
    for first, (stop, kind) in walk.spans.items():
        kinds[kind] += stop - first
    lines = ["Data walk", "=========", "",
             f"animation sets: {len(walk.sets)}, animation tables: {len(walk.tables)} "
             f"({sum(map(len, walk.tables.values()))} entries), animations: {len(walk.animations)}, "
             f"sprite lists: {len(walk.lists)}",
             f"maps: {len(walk.maps)} ({sum(walk.maps.values())} strips), tile blocks: {len(walk.blocks)} arrays "
             f"({sum(walk.blocks.values())} blocks)",
             f"palette sets: {len(walk.palette_sets)}, palettes: {len(walk.palette_list)}, palette effects: "
             f"{len(walk.effects)}",
             f"spawn lists: {len(walk.spawns)} ({sum(walk.spawns.values())} objects), animations no table leads to: "
             f"{len(walk.unreached)}"]
    lines += [f"  {kind:<16} {count:7d} bytes" for kind, count in sorted(kinds.items())]
    lines.append(f"  {'total':<16} {sum(kinds.values()):7d} bytes")
    if reads is not None:
        # (what the analysis describes, its tables of code, is no miss; the code the engines read, past a map's or
        # a block array's end into the fixed program, is the coverage's to list)
        walked = set(walk.owner) | set(walk.analysis.owner)
        for low, high in walk.analysis.table_spans.values():
            walked.update(range(low, high))
        missed = defaultdict(set)
        for pc, read in reads.items():
            if any(first <= pc < stop for first, stop in ENGINES):
                for place in read - walked:
                    missed[pc].add(place)
        total = set().union(*missed.values()) if missed else set()
        lines += ["", f"bytes the engines read in the scenarios that the walk did not reach: {len(total)}"]
        for pc, places in sorted(missed.items()):
            ordered = sorted(places)
            lines.append(f"  {pc:06X}  {len(ordered):6d}  {ordered[0]:06X}-{ordered[-1]:06X}")
    lines += ["", f"problems: {len(walk.problems)}"] + [f"  {problem}" for problem in walk.problems]
    lines += ["", f"notes: {len(walk.notes)}"] + [f"  {note}" for note in walk.notes]
    return lines


def main():
    arguments = sys.argv[1:]
    reads_folder = None
    if "--reads" in arguments:
        position = arguments.index("--reads")
        if position + 1 >= len(arguments):
            raise SystemExit("Usage: python tools/data_walk.py [rom folder or .zip] [--reads FOLDER]")
        reads_folder = arguments[position + 1]
        del arguments[position:position + 2]
    source = Path(arguments[0]) if arguments else ROOT / "rom"
    image = game_profile.rom.build_program(game_profile.rom.load_set(source))
    analysis = konami_analysis.Analysis(image, konami_analysis.load_symbols(ROOT / "symbols.txt"))
    analysis.run()
    walk = Walk(analysis)
    walk.run()
    lines = report(walk, load_reads(reads_folder) if reads_folder else None)
    out = ROOT / "build" / "listing"
    out.mkdir(parents=True, exist_ok=True)
    (out / "data_walk.txt").write_text("\n".join(lines) + "\n", encoding="ascii")
    print("\n".join(lines[:60]))


if __name__ == "__main__":
    main()
