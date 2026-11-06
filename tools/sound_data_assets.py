"""
Name:        sound_data_assets.py
Description: the Z80 sound program's data and its banks' music as text by name, and back byte for byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

For tools/extract_assets.py, which writes them into assets/sound_data. Every byte of the sound region that is not
code (the program at 0000-7FFF and the banks at 10000-27FFF: tools/sound_data_walk.py's places) is in a piece: the
songs' headers and tracks and the patches tools/sound_data_walk.py walks, what sound_symbols.txt's data lines
describe, and the rest (the 0xFF fill, what nothing plays). A piece is lines of items that give its bytes back:

    u8 0A 00 ...                    bytes, hex
    note 3C                         a track's note (00-DF: its length by the high nibble, its pitch by the low one)
    command E2 02                   a track's command and its arguments (E0-FF)

files: sound_data/music.txt (the songs' headers and tracks, a command a line), patches.txt, tables.txt, other.txt,
and layout.txt: each piece's name, place and length, for --check only.
"""
import re
from collections import defaultdict

import sound_data_walk

DATA = re.compile(r"([0-9A-Fa-f]{4})\s+data\s+(\w+)\s+(\w+)\[(\d+)\]")
STRUCT = re.compile(r"struct\s+(\w+)\s+([0-9A-Fa-f]+)\b")
FAMILIES = {"music track": "music", "song header": "music", "fm patch": "patches", "pcm patch": "patches",
            "table": "tables", "fill": "other", "other": "other"}


def symbols_tables(path):
    """[(name, address, bytes)] of sound_symbols.txt's data lines"""
    lines = [line.split("#", 1)[0].strip() for line in path.read_text(encoding="utf-8").splitlines()]
    sizes = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}
    for line in lines:
        match = STRUCT.match(line)
        if match:
            sizes[match.group(1)] = int(match.group(2), 16)
    found = []
    for line in lines:
        match = DATA.match(line)
        if match:
            found.append((match.group(2), int(match.group(1), 16), int(match.group(4)) * sizes.get(match.group(3), 1)))
    return found


def track_lines(walk, region, first, stop):
    """A track's commands, a line each, as the driver reads them (sound_data_walk's lengths)"""
    lines = []
    at = first
    while at < stop:
        command = region[at]
        if command < 0xE0:
            length = 1
        elif command in sound_data_walk.FIXED:
            length = sound_data_walk.FIXED[command]
        elif command == sound_data_walk.HELD:
            length = 2
            while at + length < stop:
                held = region[at + length]
                length += 1
                if held & 0xF0 == 0xF0 or held & 0x0F == sound_data_walk.NIBBLE_END:
                    break
        elif command in sound_data_walk.GOES_ON:
            length = sound_data_walk.GOES_ON[command][0]
        elif command in sound_data_walk.PLAYS:
            length = sound_data_walk.PLAYS[command][0]
        elif command in sound_data_walk.STOPS:
            length = sound_data_walk.STOPS[command][0]
        else:
            length = 1
        length = min(length, stop - at)
        label = "note" if command < 0xE0 and length == 1 else "command"
        lines.append(f"{label} " + " ".join(f"{byte:02X}" for byte in region[at:at + length]))
        at += length
    return lines


def hex_lines(data):
    return ["u8 " + " ".join(f"{byte:02X}" for byte in data[at:at + 16]) for at in range(0, len(data), 16)]


def export(region, code, symbols_path, folder):
    folder.mkdir(parents=True, exist_ok=True)
    walk = sound_data_walk.Walk(region, code)
    walk.run()
    kinds = {}                  # {place: (first, stop, kind, name)}
    for first, (stop, kind) in walk.spans.items():
        for place in range(first, stop):
            kinds[place] = (first, stop, kind, None)
    for name, address, size in symbols_tables(symbols_path):
        for place in range(address, address + size):
            if place not in kinds and place not in code:
                kinds[place] = (address, address + size, "table", name)
    by_family = defaultdict(list)
    layout = []
    place = 0
    while place < len(region):
        if place in code or sound_data_walk.WINDOW <= place < sound_data_walk.BANK_START:
            place += 1
            continue
        if place in kinds:
            first, stop, kind, name = kinds[place]
            end = place
            while end < stop and end not in code:
                end += 1
        else:
            kind = "fill" if region[place] == 0xFF else "other"
            end = place
            while end < len(region) and end not in code and end not in kinds \
                    and ("fill" if region[end] == 0xFF else "other") == kind \
                    and not (sound_data_walk.WINDOW <= end < sound_data_walk.BANK_START):
                end += 1
            name = None
        name = name if name and place == first else f"{kind.replace(' ', '_')}_{place:05X}"
        lines = track_lines(walk, region, place, end) if kind == "music track" else hex_lines(region[place:end])
        family = FAMILIES.get(kind, "other")
        by_family[family].append(f"[{name}] {kind}\n" + "\n".join(lines))
        layout.append(f"{name} {place:05X} {end - place} {family}")
        place = end
    for family, sections in by_family.items():
        (folder / f"{family}.txt").write_text("\n\n".join(sections) + "\n", encoding="ascii")
    (folder / "layout.txt").write_text("\n".join(layout) + "\n", encoding="ascii")
    return len(layout)


def build(folder):
    """{place: byte} the files give back"""
    sections = {}
    for path in folder.glob("*.txt"):
        if path.name == "layout.txt":
            continue
        name, data = None, bytearray()
        for line in path.read_text(encoding="ascii").splitlines() + ["[end]"]:
            if line.startswith("["):
                if name is not None:
                    sections[name] = bytes(data)
                name, data = line[1:line.index("]")], bytearray()
            elif line.strip():
                data += bytes(int(item, 16) for item in line.split()[1:])
    found = {}
    for line in (folder / "layout.txt").read_text(encoding="ascii").splitlines():
        name, place, length, _ = line.split()
        place, length = int(place, 16), int(length)
        if len(sections[name]) != length:
            raise SystemExit(f"sound data: {name} gives {len(sections[name])} bytes, layout.txt says {length}")
        for offset, byte in enumerate(sections[name]):
            found[place + offset] = byte
    return found
