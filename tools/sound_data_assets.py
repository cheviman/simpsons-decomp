"""
Name:        sound_data_assets.py
Description: the Z80 sound program's data as text by name, its banks' music as MIDI files, and back byte for
             byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

For tools/extract_assets.py, which writes them into assets/sound_data. Every byte of the sound region that is not
code (the program at 0000-7FFF and the banks at 10000-27FFF: tools/sound_data_walk.py's places) is in a piece: the
songs' headers and tracks and the patches tools/sound_data_walk.py walks, what sound_symbols.txt's data lines
describe, and the rest (the 0xFF fill, what nothing plays). The music (the songs' headers and tracks, and the
tracks no song plays) is the songs' Standard MIDI Files (tools/sound_music.py: sound_data/music, a file a song,
music/music.txt the files); every other piece is lines of bytes that give it back:

    u8 0A 00 ...                    bytes, hex

files: sound_data/patches.txt, tables.txt, other.txt, music/, and layout.txt: each piece's name, place, length and
file (music: the MIDI files'), which names the places the MIDI files point at, and which --check reads.
"""
import re
from collections import defaultdict

import sound_data_walk
import sound_music

DATA = re.compile(r"([0-9A-Fa-f]{4})\s+data\s+(\w+)\s+(\w+)\[(\d+)\]")
STRUCT = re.compile(r"struct\s+(\w+)\s+([0-9A-Fa-f]+)\b")
FAMILIES = {"music track": "music", "song header": "music", "fm patch": "patches", "pcm patch": "patches",
            "table": "tables", "fill": "other", "other": "other"}
MUSIC = "music"                 # the family the MIDI files give back


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


def hex_lines(data):
    return ["u8 " + " ".join(f"{byte:02X}" for byte in data[at:at + 16]) for at in range(0, len(data), 16)]


def export(region, code, symbols_path, folder):
    """The pieces' text files, layout.txt and the songs' MIDI files (sound_music.py) into 'folder': the pieces'
    count"""
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
    layout, pieces = [], []
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
        family = FAMILIES.get(kind, "other")
        if family != MUSIC:
            by_family[family].append(f"[{name}] {kind}\n" + "\n".join(hex_lines(region[place:end])))
        layout.append(f"{name} {place:05X} {end - place} {family}")
        pieces.append((name, kind, place, end))
        place = end
    for family, sections in by_family.items():
        (folder / f"{family}.txt").write_text("\n\n".join(sections) + "\n", encoding="ascii")
    (folder / "layout.txt").write_text("\n".join(layout) + "\n", encoding="ascii")
    if (folder / f"{MUSIC}.txt").exists():
        (folder / f"{MUSIC}.txt").unlink()        # the music as text, from before the MIDI files
    sound_music.write(region, pieces, folder / MUSIC)
    return len(layout)


def build(folder):
    """{place: byte} the files give back: the text's pieces, and the music from the MIDI files"""
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
    music = []
    for line in (folder / "layout.txt").read_text(encoding="ascii").splitlines():
        name, place, length, family = line.split()
        place, length = int(place, 16), int(length)
        if family == MUSIC:
            music.append((name, place, place + length))
            continue
        if name not in sections:
            raise SystemExit(f"sound data: no file gives {name} (layout.txt)")
        if len(sections[name]) != length:
            raise SystemExit(f"sound data: {name} gives {len(sections[name])} bytes, layout.txt says {length}")
        for offset, byte in enumerate(sections[name]):
            found[place + offset] = byte
    # the music: every byte of its pieces from the MIDI files, with the tables they need from the text's pieces
    names = sound_music.Names({first: (stop, name) for name, first, stop in music})
    data = sections["note_lengths"]
    lengths = [0x10000 - (data[at] | data[at + 1] << 8) for at in range(0, len(data), 2)]
    data = sections["music_pcm_transpositions"]
    transpositions = [word - 0x10000 if word & 0x8000 else word
                      for word in (data[at] | data[at + 1] << 8 for at in range(0, len(data), 2))]
    try:
        rebuilt = sound_music.read(folder / MUSIC, names, lengths, transpositions)
    except sound_music.MusicError as error:
        raise SystemExit(f"sound data, the music: {error}")
    for name, first, stop in music:
        missing = [place for place in range(first, stop) if place not in rebuilt.bytes]
        if missing:
            raise SystemExit(f"sound data: no MIDI file gives {names.name(missing[0])} ({len(missing)} bytes of "
                             f"{name})")
    inside = {place for _, first, stop in music for place in range(first, stop)}
    outside = sorted(set(rebuilt.bytes) - inside)
    if outside:
        raise SystemExit(f"sound data: the MIDI files give {len(outside)} bytes outside the music, the first at "
                         f"{outside[0]:05X} ({rebuilt.bytes[outside[0]][1]})")
    for place, (byte, _) in rebuilt.bytes.items():
        found[place] = byte
    return found
