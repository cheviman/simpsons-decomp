"""
Name:        data_assets.py
Description: the 053248 program's data as text by subject, every piece by name, and back byte for byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

For tools/extract_assets.py, which writes them into assets/data. Every byte of the program that is not code is in a
piece: what tools/data_walk.py walks (animations, sprite lists, maps, tile blocks, palettes, texts, scripts...), the
tables of code addresses the static analysis reads, the vectors, the fill, and what nothing explains yet. A piece is
one walked span, or a run of bytes of one class, named by the symbols.txt name it starts at, or by its kind and its
place (a name only: nothing reads the place back but --check). A piece is written as lines of typed items, which give
its bytes back in order:

    u8 0A 00 ...                      bytes, hex
    sprite CODE COLOUR ATTRIBUTES X Y  a sprite of a sprite list (CODE: 16 bits, bit 15 its flip)
    frame SPRITES TIME LIST           an animation's frame: its sprite count less one and flags, how long, its list
                                      (a ref, or its address in hex when no piece starts there)
    end FLAGS ARGUMENT ADDRESS        an animation's end (80: the next animation, 81: back to a frame), the address
                                      as a ref too
    colours #RRGGBB ...               palette entries, xBGR 555 (5 bits a component: the low 3 bits of each pair of
                                      hex digits are 0), '+' after one whose bit 15 is set
    text "..."                        characters 30-5A as they are ('@' a space), \\xNN any other byte
    ref NAME[+N]                      the 16-bit address of a piece (or of code: code_PLACE), in the tables of
                                      addresses (animation tables, set indexes, text tables, maps...): the CPU's
                                      address of the place, in the piece's bank or the fixed program
    u16 1234                          a word no piece or code starts at
    area REF BANK BYTE                a scene's map or tile blocks: their address in the bank the next byte gives
    load REF PLACE COUNT              a palette set's load: palettes from bank 2D, where in the palette RAM, how many
    setup KIND BOX 1B 27              an object's setup: its kind and animation, its hit box (in the setup's bank) and
                                      the bytes for its fields 1B and 27
    picture BANK PLACE REF            a tile picture's place: its bank, where in the tile RAM, the picture
    demo PLAYERS FRAMES STEP REF...   a demo: its players and frames, the step it plays, each player's inputs (bank 2C)
    s8 -3 +12 ... / s16 -300          signed bytes / words, decimal
    step DX DY / loop BACK NEXT TIMES  an object path's step (2 bytes), and its end: FFFF, where it goes back to, the
                                      path after it, how many times
    record STRUCT VALUE...            a record of one of symbols.txt's tables, its fields in order (the bytes no field
                                      names, u8): u8 and u16 in hex, s8 and s16 in decimal, a u16 that symbols.txt says
                                      points at a structure as a ref

files: data/<family>.txt, one a family of kinds, and data/layout.txt: each piece's name, place and length, for
--check only.
"""
import re
from collections import defaultdict
from pathlib import Path

FAMILIES = {
    "animation": "animations", "unreached animation": "animations", "animation table": "animations",
    "set index": "animations", "animation sets": "animations",
    "sprite list": "sprite_lists",
    "map": "maps", "map strip": "maps", "unreached map": "maps", "scene list": "maps", "scene table": "maps",
    "layer mode list": "maps",
    "tile blocks": "tile_blocks", "unused blocks": "tile_blocks", "block tile flags": "tile_blocks",
    "edge block": "tile_blocks", "map edge row": "maps",
    "palettes": "palettes", "unused palettes": "palettes", "palette sets": "palettes", "palette set table": "palettes",
    "palette effect": "palette_effects", "palette effects": "palette_effects",
    "text": "texts", "text table": "texts", "profile text": "texts", "test mode text": "texts",
    "test mode page": "texts",
    "tile picture": "screens", "tile picture place": "screens", "tile picture table": "screens",
    "spawn list": "spawns", "spawn list table": "spawns",
    "story script": "stories", "story script table": "stories",
    "object path": "objects", "path starts": "objects", "enemy behaviour": "objects", "object setup": "objects",
    "hit box": "objects", "object start": "objects", "child object": "objects",
    "demo": "demos", "demo inputs": "demos", "demo table": "demos",
}
COLOUR = re.compile(r"#([0-9A-Fa-f]{6})(\+?)")
STRUCT_LINE = re.compile(r"struct\s+(\w+)\s+([0-9A-Fa-f]+)\b")
FIELD_LINE = re.compile(r"field\s+(\w+)\s+([0-9A-Fa-f]+)\s+\w+\s+([us](?:8|16))(?:\[([0-9A-Fa-f]*)\])?(?:\s+(\w+))?")
TABLE_LINE = re.compile(r"([0-9A-Fa-f]{6})\s+table\s+\w+\[(\d+)\]\s+(\w+)(?:\s+(\w+))?")
TYPE_SIZES = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}
TEXT = re.compile(r'"((?:[^"\\]|\\.)*)"')


# ---- the typed lines ----

def hex_lines(data, label="u8", per_line=16):
    return [f"{label} " + " ".join(f"{byte:02X}" for byte in data[at:at + per_line]) for at in range(0, len(data), per_line)]


def sprite_lines(data):
    lines = []
    whole = len(data) // 6 * 6
    for at in range(0, whole, 6):
        lines.append(f"sprite {data[at] << 8 | data[at + 1]:04X} {data[at + 2]:02X} {data[at + 3]:02X} "
                     f"{data[at + 4]:02X} {data[at + 5]:02X}")
    return lines + hex_lines(data[whole:])


def animation_lines(data, place=None, resolve=None):
    lines = []
    whole = len(data) // 4 * 4
    for at in range(0, whole, 4):
        kind = "end" if data[at] & 0x80 else "frame"
        word = data[at + 2] << 8 | data[at + 3]
        name = resolve(target_of(word, place)) if resolve is not None and target_of(word, place) is not None else None
        lines.append(f"{kind} {data[at]:02X} {data[at + 1]:02X} {name or f'{word:04X}'}")
    return lines + hex_lines(data[whole:])


def target_of(word, place):
    """The place a CPU address in a piece at 'place' names: its bank's in the window, the fixed program's above"""
    if word >= 0x8000:
        return 0x78000 + word - 0x8000
    if word >= 0x6000 and place is not None and place < 0x78000:
        return place // 0x2000 * 0x2000 + word - 0x6000
    return None


def colour_lines(data):
    lines = []
    whole = len(data) // 2 * 2
    for at in range(0, whole, 32):
        items = []
        for word_at in range(at, min(at + 32, whole), 2):
            value = data[word_at] << 8 | data[word_at + 1]
            red, green, blue = value & 0x1F, value >> 5 & 0x1F, value >> 10 & 0x1F
            items.append(f"#{red << 3:02X}{green << 3:02X}{blue << 3:02X}" + ("+" if value & 0x8000 else ""))
        lines.append("colours " + " ".join(items))
    return lines + hex_lines(data[whole:])


def text_lines(data):
    out = []
    for byte in data:
        if 0x30 <= byte <= 0x5A and byte not in (0x5C,):
            out.append(chr(byte))
        else:
            out.append(f"\\x{byte:02X}")
    return [f'text "{"".join(out[at:at + 64])}"' for at in range(0, len(out), 64)]


# the kinds whose pieces are tables of CPU addresses, each in the piece's bank (or the fixed program)
POINTER_KINDS = {"animation table", "set index", "palette effects", "text table", "spawn list table",
                 "story script table", "map", "palette set table", "demo table", "tile picture table", "scene table"}

# the records whose fields name places: {kind: (line, record size, fields)}, a field "u8" or "u16" (hex) or ("ref",
# where): a CPU address, of a place in the piece's bank (None), in a bank (an int), or in the bank a byte of the record
# gives (("byte", offset))
RECORD_LINES = {
    "scene list": ("area", 4, (("ref", ("byte", 2)), "u8", "u8")),
    "palette sets": ("load", 5, (("ref", 0x2D), "u16", "u8")),
    "object setup": ("setup", 6, ("u16", ("ref", None), "u8", "u8")),
    "tile picture place": ("picture", 5, ("u8", "u16", ("ref", ("byte", 0)))),
    "demo": ("demo", 12, ("u8", "u16", "u8") + (("ref", 0x2C),) * 4),
}
LINE_FIELDS = {line: fields for line, _, fields in RECORD_LINES.values()}
LINE_FIELDS["loop"] = (("ref", None), ("ref", None), "u8")
# the walked kinds whose records are one of symbols.txt's structures
KIND_STRUCTS = {"spawn list": "spawn", "hit box": "hit_box"}
# the kinds the walk gives what it reads without knowing its shape: one of symbols.txt's tables there is written by
# its type
GENERIC_KINDS = {"named table", "loaded table", "indexed table", "value", "record", "constant table"}
PATH_END = 0xFFFF


def cpu_of(place):
    return 0x8000 + place - 0x78000 if place >= 0x78000 else 0x6000 + place % 0x2000


def pointer_lines(data, place, resolve):
    lines = []
    for at in range(0, len(data) - 1, 2):
        word = data[at] << 8 | data[at + 1]
        target = target_of(word, place)
        name = resolve(target) if target is not None else None
        lines.append(f"ref {name}" if name else f"u16 {word:04X}")
    return lines + (hex_lines(data[-1:]) if len(data) % 2 else [])


def in_bank(word, bank):
    """The place a CPU address names with 'bank' in the window (the fixed program's above 8000)"""
    if word >= 0x8000:
        return 0x78000 + word - 0x8000
    if 0x6000 <= word < 0x8000:
        return bank * 0x2000 + word - 0x6000
    return None


def record_lines(data, place, resolve, line, size, fields):
    lines = []
    whole = len(data) // size * size
    for at in range(0, whole, size):
        record, items, offset = data[at:at + size], [], 0
        for field in fields:
            if field == "u8":
                items.append(f"{record[offset]:02X}")
                offset += 1
                continue
            word = record[offset] << 8 | record[offset + 1]
            offset += 2
            name = None
            if field != "u16":
                where = field[1]
                if where is None:
                    target = target_of(word, place)
                elif isinstance(where, int):
                    target = in_bank(word, where)
                else:
                    target = in_bank(word, record[where[1]] & 0x3F)
                name = resolve(target) if target is not None else None
            items.append(name or f"{word:04X}")
        lines.append(f"{line} " + " ".join(items))
    return lines + hex_lines(data[whole:])


FORMATS = {"sprite list": sprite_lines, "animation": animation_lines, "unreached animation": animation_lines,
           "palettes": colour_lines, "unused palettes": colour_lines,
           "text": text_lines, "test mode text": text_lines, "profile text": text_lines, "test mode page": text_lines}


def word_of(item, places):
    """A word written as 4 hex digits, or as a ref (NAME[+N], code_PLACE): the CPU's address of the place"""
    if re.fullmatch(r"[0-9A-Fa-f]{4}", item):
        return int(item, 16)
    name, _, offset = item.partition("+")
    place = int(name[5:], 16) if name.startswith("code_") else places[name]
    return cpu_of(place + (int(offset, 16) if offset else 0))


def parse_lines(lines, places=None, layouts=None):
    """The bytes the typed lines give back ('places': {piece name: place}, for the refs; 'layouts': symbols.txt's
    structures, for the records)"""
    out = bytearray()
    for line in lines:
        kind, _, rest = line.partition(" ")
        if kind == "u8":
            out += bytes(int(item, 16) for item in rest.split())
        elif kind == "s8":
            out += bytes(int(item) & 0xFF for item in rest.split())
        elif kind == "s16":
            word = int(rest) & 0xFFFF
            out += bytes((word >> 8, word & 0xFF))
        elif kind == "record":
            struct, *items = rest.split()
            for item, (value, _) in zip(items, layouts.structs[struct]):
                if value == "u8":
                    out.append(int(item, 16))
                elif value == "s8":
                    out.append(int(item) & 0xFF)
                else:
                    word = int(item) & 0xFFFF if value == "s16" else word_of(item, places)
                    out += bytes((word >> 8, word & 0xFF))
        elif kind == "u16":
            word = int(rest, 16)
            out += bytes((word >> 8, word & 0xFF))
        elif kind == "ref":
            word = word_of(rest.strip(), places)
            out += bytes((word >> 8, word & 0xFF))
        elif kind == "sprite":
            code, colour, attributes, x, y = (int(item, 16) for item in rest.split())
            out += bytes((code >> 8, code & 0xFF, colour, attributes, x, y))
        elif kind in ("frame", "end"):
            flags, argument, address = rest.split()
            word = word_of(address, places)
            out += bytes((int(flags, 16), int(argument, 16), word >> 8, word & 0xFF))
        elif kind == "step":
            out += bytes(int(item, 16) for item in rest.split())
        elif kind in LINE_FIELDS:
            if kind == "loop":
                out += bytes((PATH_END >> 8, PATH_END & 0xFF))
            for item, field in zip(rest.split(), LINE_FIELDS[kind]):
                if field == "u8":
                    out.append(int(item, 16))
                else:
                    word = word_of(item, places)
                    out += bytes((word >> 8, word & 0xFF))
        elif kind == "colours":
            for match in COLOUR.finditer(rest):
                red, green, blue = (int(match.group(1)[at:at + 2], 16) >> 3 for at in (0, 2, 4))
                value = red | green << 5 | blue << 10 | (0x8000 if match.group(2) else 0)
                out += bytes((value >> 8, value & 0xFF))
        elif kind == "text":
            body = TEXT.search(rest).group(1)
            at = 0
            while at < len(body):
                if body[at] == "\\":
                    out.append(int(body[at + 2:at + 4], 16))
                    at += 4
                else:
                    out.append(ord(body[at]))
                    at += 1
        elif line.strip():
            raise SystemExit(f"data: a line no format reads: {line}")
    return bytes(out)


# ---- symbols.txt's tables, by their types ----

class Layouts:
    """symbols.txt's structures and tables: each structure's values in byte order, [(type, points)] (the bytes no
    field names, u8; a field at a place another field already covers, left out: it names the wider one's first
    bytes), and {table place: (element type, count, points)}"""

    def __init__(self, symbols_path):
        lines = [line.split("#", 1)[0].strip() for line in symbols_path.read_text(encoding="utf-8").splitlines()]
        sizes, fields = {}, {}
        for line in lines:
            match = STRUCT_LINE.match(line)
            if match:
                sizes[match.group(1)] = int(match.group(2), 16)
            match = FIELD_LINE.match(line)
            if match:
                struct, offset, kind, count, points = match.groups()
                count = int(count, 16) if count else 1
                fields.setdefault(struct, []).append((int(offset, 16), kind, count, points))
        self.structs = {}
        for struct, size in sizes.items():
            values, at = [], 0
            for offset, kind, count, points in sorted(fields.get(struct, [])):
                if offset < at:
                    continue
                values += [("u8", None)] * (offset - at)
                values += [(kind, points)] * count
                at = offset + TYPE_SIZES[kind] * count
            if at > size:
                continue    # (an array that goes on past the record's end: not one of these)
            self.structs[struct] = values + [("u8", None)] * (size - at)
        self.tables = {}
        for line in lines:
            match = TABLE_LINE.match(line)
            if match:
                place, count, kind, points = match.groups()
                if kind in TYPE_SIZES or kind in self.structs:
                    self.tables[int(place, 16)] = (kind, int(count), points)

    def size(self, kind):
        return TYPE_SIZES[kind] if kind in TYPE_SIZES else sum(TYPE_SIZES[value] for value, _ in self.structs[kind])


def value_text(kind, data, at, points, place, resolve):
    if kind == "u8":
        return f"{data[at]:02X}"
    if kind == "s8":
        return f"{data[at] - 256 * (data[at] >= 0x80):+d}"
    word = data[at] << 8 | data[at + 1]
    if kind == "s16":
        return f"{word - 0x10000 * (word >= 0x8000):+d}"
    target = target_of(word, place) if points else None
    return (resolve(target) if target is not None else None) or f"{word:04X}"


def struct_lines(data, place, resolve, layouts, struct):
    """Whole records of 'struct', then the rest in hex"""
    size = layouts.size(struct)
    whole = len(data) // size * size
    lines = []
    for first in range(0, whole, size):
        items, at = [], first
        for value, points in layouts.structs[struct]:
            items.append(value_text(value, data, at, points, place, resolve))
            at += TYPE_SIZES[value]
        lines.append(f"record {struct} " + " ".join(items))
    return lines + hex_lines(data[whole:])


def path_lines(data, place, resolve):
    """An object path: its steps, 2 bytes each, up to FFFF, then where it goes back to, the next path and how many
    times (data_walk's object_paths)"""
    lines, at = [], 0
    while at + 2 <= len(data) and (data[at] << 8 | data[at + 1]) != PATH_END:
        lines.append(f"step {data[at]:02X} {data[at + 1]:02X}")
        at += 2
    if at + 7 <= len(data):
        items = []
        for offset in (2, 4):
            word = data[at + offset] << 8 | data[at + offset + 1]
            target = target_of(word, place)
            items.append((resolve(target) if target is not None else None) or f"{word:04X}")
        lines.append(f"loop {items[0]} {items[1]} {data[at + 6]:02X}")
        at += 7
    return lines + hex_lines(data[at:])


def table_lines(data, place, resolve, layouts):
    """The lines of one of symbols.txt's tables, or None if the piece is not it whole"""
    kind, count, points = layouts.tables[place]
    if len(data) != layouts.size(kind) * count:
        return None
    if kind in ("u8", "s8"):
        return [f"{kind} " + " ".join(value_text(kind, data, at, None, place, resolve)
                                       for at in range(first, min(first + 16, len(data))))
                for first in range(0, len(data), 16)]
    if kind in ("u16", "s16"):
        lines = []
        for at in range(0, len(data), 2):
            word = data[at] << 8 | data[at + 1]
            target = target_of(word, place) if points and kind == "u16" else None
            name = resolve(target) if target is not None else None
            lines.append(f"ref {name}" if name else f"{kind} {value_text(kind, data, at, None, place, resolve)}")
        return lines
    lines, at = [], 0
    for _ in range(count):
        items = []
        for value, points in layouts.structs[kind]:
            items.append(value_text(value, data, at, points, place, resolve))
            at += TYPE_SIZES[value]
        lines.append(f"record {kind} " + " ".join(items))
    return lines


# ---- the pieces ----

def pieces(image, code, walked, described, fill, names):
    """[(name, place, length, kind)] of every byte of the program that is not code"""
    found = []
    place = 0
    while place < len(image):
        if place in code:
            place += 1
            continue
        if place in walked:
            first, stop, kind = walked[place]
            stop = min(stop, len(image))
            # (a walked span that code splits: its parts)
            end = place
            while end < stop and end not in code:
                end += 1
        else:
            kind = "described" if place in described else "fill" if place in fill else "unknown"
            end = place
            while end < len(image) and end not in code and end not in walked \
                    and ("described" if end in described else "fill" if end in fill else "unknown") == kind \
                    and (end == place or end not in names):
                end += 1
        name = names.get(place) or f"{kind.replace(' ', '_')}_{place:06X}"
        found.append((name, place, end - place, kind))
        place = end
    return found


def export(image, code, walk_spans, described, fill, names, folder, names_of_code=(), layouts=None):
    folder.mkdir(parents=True, exist_ok=True)
    walked = {}
    for first, (stop, kind) in walk_spans.items():
        for place in range(first, stop):
            walked[place] = (first, stop, kind)
    found = pieces(image, code, walked, described, fill, names)
    starts = sorted((place, name, length) for name, place, length, _ in found)
    firsts = [place for place, _, _ in starts]
    from bisect import bisect_right

    def resolve(target):
        """A piece's name (+ offset) or code_PLACE for a place, or None"""
        if target in code:
            return f"code_{target:06X}" if target in instruction_starts else None
        index = bisect_right(firsts, target) - 1
        if index < 0:
            return None
        place, name, length = starts[index]
        if not place <= target < place + length:
            return None
        return name if target == place else f"{name}+{target - place:X}"

    instruction_starts = set(names_of_code)
    by_family = defaultdict(list)
    layout = []
    for name, place, length, kind in found:
        data = image[place:place + length]
        typed = table_lines(data, place, resolve, layouts) \
            if layouts is not None and place in layouts.tables and kind in GENERIC_KINDS else None
        if typed is not None:
            lines = typed
        elif layouts is not None and kind in KIND_STRUCTS and KIND_STRUCTS[kind] in layouts.structs:
            lines = struct_lines(data, place, resolve, layouts, KIND_STRUCTS[kind])
        elif kind == "object path":
            lines = path_lines(data, place, resolve)
        elif kind in POINTER_KINDS:
            lines = pointer_lines(data, place, resolve)
        elif kind in RECORD_LINES:
            lines = record_lines(data, place, resolve, *RECORD_LINES[kind])
        elif kind in ("animation", "unreached animation"):
            lines = animation_lines(data, place, resolve)
        else:
            lines = FORMATS.get(kind, hex_lines)(data)
        family = FAMILIES.get(kind, "fill" if kind == "fill" else "unknown" if kind == "unknown" else "tables")
        by_family[family].append(f"[{name}] {kind}\n" + "\n".join(lines))
        layout.append(f"{name} {place:06X} {length} {family}")
    for family, sections in by_family.items():
        (folder / f"{family}.txt").write_text("\n\n".join(sections) + "\n", encoding="ascii")
    (folder / "layout.txt").write_text("\n".join(layout) + "\n", encoding="ascii")
    return len(found), {family: len(sections) for family, sections in by_family.items()}


def build(folder, size, layouts=None):
    """The program's data bytes the files give back: {place: byte}"""
    places = {}
    for line in (folder / "layout.txt").read_text(encoding="ascii").splitlines():
        name, place, _, _ = line.split()
        places[name] = int(place, 16)
    sections = {}
    for path in folder.glob("*.txt"):
        if path.name == "layout.txt":
            continue
        name, lines = None, []
        for line in path.read_text(encoding="ascii").splitlines() + ["[end]"]:
            if line.startswith("["):
                if name is not None:
                    sections[name] = parse_lines(lines, places, layouts)
                name, lines = line[1:line.index("]")], []
            elif line.strip():
                lines.append(line)
    found = {}
    for line in (folder / "layout.txt").read_text(encoding="ascii").splitlines():
        name, place, length, _ = line.split()
        place, length = int(place, 16), int(length)
        data = sections[name]
        if len(data) != length:
            raise SystemExit(f"data: {name} gives {len(data)} bytes, layout.txt says {length}")
        for offset, byte in enumerate(data):
            found[place + offset] = byte
    return found
