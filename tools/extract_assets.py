"""
Name:        extract_assets.py
Description: The Simpsons' assets from the player's ROM set into common formats, by subject, and back byte for byte
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

Usage: python tools/extract_assets.py [rom folder or .zip] [--check] [--out FOLDER]   (assets/ by default)

Writes the assets the game loads (none of them goes into the repository):
  sprites/  the K053247's 16 x 16 cells in sheets by the objects whose animations show them (tools/data_walk.py: an
            animation set, by the object kinds that take it: the players' first), each cell in the first sheet that
            shows it; then the animations no table leads to, and the cells nothing shows, by code. 4-bit indexed
            PNGs, 16 cells a row, with the colours of the palette most of the sheet's sprites take (the palette
            sets' loads, sprites from palette 32: approximate, the pens are exact). sprites.txt lists each sheet's
            cell codes, in its order.
  tiles/    the K052109's 8 x 8 tiles in sheets by the scenes whose maps' blocks show them (the scene tables, with
            the character banks the scene's layer modes give), each tile in the first sheet that shows it; then
            the tiles nothing shows, by code. The same PNGs, 32 tiles a row. tiles.txt lists each sheet's codes.
  data/     the 053248 program's data, every piece by name, as text by subject (tools/data_assets.py)
  sound_data/  the Z80 sound program's data, every piece by name, as text by subject (tools/sound_data_assets.py:
            the patches, the driver's tables), and its music as Standard MIDI Files, a song a file, in
            sound_data/music (tools/sound_music.py; music.txt lists them)
  sounds/   the K053260's samples as WAV files, by the Z80 driver's sample table (tools/sound_assets.py), and the
            bytes no sample plays; samples.txt says where each goes.
  eeprom.txt  the ER5911's 128 bytes as the board leaves the factory (simpsons.12c.nv: the settings the game starts
            with; without them it boots upside down and reports the EEPROM bad), u8 lines in hex.
With --check, the tile, sprite and sample ROM files are rebuilt from the assets and compared with the set's, byte for byte,
and the programs' data bytes with the programs' (the sound program's music from the MIDI files; nothing is written),
and the EEPROM's with the set's.
"""
import bisect
import re
import shutil
import sys
from collections import Counter, defaultdict
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
sys.path[:0] = [str(TOOLS / "core"), str(TOOLS)]
import game_profile  # noqa: E402  (the game's: its root, its ROM set)
import asset_formats  # noqa: E402  (the core's PNG reader and writer)
import data_walk  # noqa: E402
import simpsons_graphics as graphics  # noqa: E402
import sound_assets  # noqa: E402
import data_assets  # noqa: E402
import sound_data_assets  # noqa: E402
from z80 import analysis as z80_analysis  # noqa: E402
import coverage  # noqa: E402  (the core's: the byte classes of the program)
from konami_cpu import analysis as konami_analysis  # noqa: E402

ROOT = game_profile.ROOT
rom = game_profile.rom
place_of, bank_of = konami_analysis.place_of, konami_analysis.bank_of
SPRITE_COLUMNS = 16
TILE_COLUMNS = 32
SHEET = 256                     # the cells or tiles of a sheet of what nothing shows
SPRITE_PALETTES = 32            # the sprites' first palette (the K053251's CI1, 32 for the players' 0400 loads)
LAYER_PALETTES = 64             # the layers' (0800 on)
# the animation sets' sheets by what they show, by the first kind that takes them (seen on contact sheets of their
# first frames); a set left out is kind_XX
SET_NAMES = {0x00: "marge", 0x01: "homer", 0x02: "bart", 0x03: "lisa", 0x04: "hit_sparks", 0x07: "hammer",
             0x09: "food", 0x0A: "marge_portrait", 0x0B: "homer_portrait", 0x0C: "bart_portrait",
             0x0D: "lisa_portrait", 0x0F: "police_car_and_doors", 0x11: "maggie", 0x14: "family", 0x80: "goon",
             0x81: "fat_goon", 0x82: "goon_with_umbrella", 0x83: "goon_with_shovel", 0x84: "goon_with_hat",
             0x86: "dog", 0x89: "squirrel",
             0x8B: "bird", 0x8D: "lumberjack", 0x8F: "robot", 0x92: "football_player", 0x94: "wrestler",
             0x96: "clown_on_ball", 0x99: "clown_on_ball_2", 0x9B: "ghost", 0x9D: "krusty_balloon", 0x9F: "gorilla",
             0xA2: "bear", 0xAE: "hurry_up", 0xAF: "boulder", 0xB0: "speech_balloons", 0xB1: "speech_balloons_2",
             0xB4: "octopus", 0xBA: "bubbles", 0xBB: "bubbles_2", 0xBC: "knight", 0xBD: "knight_2",
             0xBE: "knight_3", 0xBF: "knight_4", 0xC0: "knight_5", 0xC1: "knight_6", 0xC2: "grim_reaper",
             0xC5: "dog_2", 0xC8: "pointing_hand", 0xCC: "burns_robot", 0xCD: "burns_robot_2", 0xCE: "burns_robot_3",
             0xD0: "bubbles_3", 0xD2: "burns_robot_4", 0xD3: "mr_burns", 0xD4: "burns_robot_5", 0xD5: "numbers"}
# ... and the rest, by their sprites put back together from the animations with the palette of a frame where an
# object of the kind is on screen (the sheets of the first frames were black); kind AD, which nothing sets up or
# shows, stays kind_AD
SET_NAMES.update({0x05: "obstacles", 0x06: "broom", 0x08: "slingshot", 0x0E: "screen_pieces",
                  0x10: "moes_and_gorge_scenery", 0x12: "channel_6_scenery", 0x13: "boss_doors_and_rubble",
                  0x85: "fat_goon_with_mallet", 0x87: "woman_in_apron", 0x88: "fat_goon_in_teacup",
                  0x8A: "woman_in_green", 0x8C: "barney", 0x8E: "belly_dancer", 0x90: "fireman_goon", 0x91: "zombie",
                  0x93: "kid_in_sunglasses", 0x95: "rabbit", 0x97: "grabbing_zombie", 0x98: "one_eared_rabbit",
                  0x9A: "ghost_on_rope", 0x9C: "smithers", 0x9E: "moe", 0xA0: "bluebird", 0xA1: "ninja",
                  0xA3: "kabuki_warrior", 0xA4: "krusty_toys_helicopter", 0xA5: "girl_with_food", 0xA6: "nelson",
                  0xA7: "milhouse", 0xA8: "skinner", 0xA9: "sideshow_bob", 0xAA: "posters", 0xAB: "drink_vendor",
                  0xAC: "burger_eater", 0xB2: "caged_gorilla", 0xB3: "kent_brockman", 0xB5: "schoolboy_with_books",
                  0xB7: "walking_donut", 0xB8: "flying_saxophone", 0xB9: "marge_cloud", 0xC3: "gangster",
                  0xC4: "gangster_2", 0xC6: "crypt_slab", 0xC7: "cloud_devil", 0xC9: "patty_and_selma", 0xCA: "grandpa",
                  0xCB: "bleeding_gums_murphy", 0xCF: "frog", 0xD1: "dreamland_boss_balls", 0xD6: "crawling_man",
                  0xD7: "itchy_and_scratchy_heads"})
# the background scenes by their number (direct page 75, which the stage's script sets: 80-FF the high tables), as kref's
# RAM shows them with the step (4803) over the stage scenarios; 00-03 and 85 by their maps drawn: 00 the attract's
# opening, 02 the stage cards' TV and the score ranking, 03 the name entry (name_entry_start), 01 and 85 none
# the code selects (85: the forest's maps and blocks with other tile banks)
SCENE_NAMES = {0x80: "game_start", 0x81: "story_1", 0x82: "stage_1_downtown", 0x83: "bonus_1",
               0x84: "stage_2_krustyland", 0x86: "stage_3_forest", 0x87: "stage_3_cemetery",
               0x88: "stage_4_moes_street", 0x89: "stage_5_gorge", 0x8A: "stage_6_dreamland", 0x8B: "bonus_2",
               0x8C: "stage_7_channel_6", 0x8D: "stage_8_power_plant", 0x8E: "ending"}
SCENE_NAMES.update({0x00: "attract_intro", 0x01: "unused_title_card", 0x02: "title_card_and_high_scores",
                    0x03: "name_entry", 0x85: "unused_stage_3_forest"})
TILE_FILES = ("072-b07.18h", "072-b06.16h")
SPRITE_FILES = ("072-b08.3n", "072-b09.8n", "072-b10.12n", "072-b11.16l")
SAMPLE_FILES = ("072-d05.1f", "072-d04.1d")


def palette_ram(walk, image):
    """The palette RAM as the palette sets' loads leave it, one set after another (2048 xBGR 555 colours)"""
    ram = bytearray(0x1000)
    mem = walk.mem
    for name in data_walk.PALETTE_SETS:
        table, count, _ = walk.tables_named[name]
        for index in range(count):
            place = place_of(None, mem.r16(table + 2 * index))
            for load in range(data_walk.PALETTE_LOADS):
                record = place + data_walk.PALETTE_LOAD * load
                source, destination, palettes = mem.r16(record), mem.r16(record + 2), mem.r8(record + 4)
                first = place_of(data_walk.PALETTE_BANK, source)
                size = data_walk.PALETTE * palettes
                if first is not None and destination + size <= len(ram):
                    ram[destination:destination + size] = image[first:first + size]
    return ram


def colours(ram, palette):
    entries = []
    for pen in range(16):
        at = (palette * 16 + pen) * 2 % len(ram)
        entries.append(asset_formats.rgb555(ram[at] << 8 | ram[at + 1]))
    return entries


# ---- the sprites ----

def set_lists(walk, bank, table):
    """The sprite lists an animation set's animations show, [(place, sprites)], in the order they are met"""
    found = []
    seen = set()
    for animation in walk.tables.get(table, []):
        work = [konami_analysis.cpu_of(animation)]
        while work:
            cpu = work.pop()
            if (bank, cpu) in seen:
                continue
            seen.add((bank, cpu))
            walked = walk.frames(bank, cpu)
            if walked is None:
                continue
            frames, after = walked
            for at, sprites in frames:
                if sprites is not None:
                    found.append((place_of(bank, sprites), (walk.byte(bank, at) & 0x0F) + 1))
            work.append(after)
    return found


def list_cells(image, place, count):
    """The cells of a sprite list's sprites, and their colours"""
    cells, palettes = [], []
    for sprite in range(count):
        at = place + data_walk.SPRITE * sprite
        code = (image[at] << 8 | image[at + 1]) & 0x7FFF
        for cell in graphics.sprite_cells(code, image[at + 3] & 0x0F):
            cells.append(cell)
            palettes.append(image[at + 2] & 0x1F)
    return cells, palettes


def animation_set_names(walk, image):
    """{(bank, offset): the set's name}: each object kind's animation set (animation_sets, animation_sets_high), by
    what its animations show (SET_NAMES), the first kind's where two share one"""
    names = {}
    for name, high in (("animation_sets", False), ("animation_sets_high", True)):
        table, count, _ = walk.tables_named[name]
        for index in range(count):
            bank, offset = image[table + 2 * index] & 0x3F, image[table + 2 * index + 1]
            kind = index | (0x80 if high else 0)
            names.setdefault((bank, offset), SET_NAMES.get(kind, f"kind_{kind:02X}"))
    return names


def sprite_subjects(walk, image):
    """[(sheet name, [cells], palette)]: by animation set, then what nothing shows"""
    names = animation_set_names(walk, image)
    subjects = []
    for (bank, offset), name in names.items():
        table = walk.sets.get((bank, offset))
        cells, palettes = [], []
        for place, count in set_lists(walk, bank, table):
            more, used = list_cells(image, place, count)
            cells += more
            palettes += used
        subjects.append((name, cells, SPRITE_PALETTES + (Counter(palettes).most_common(1)[0][0] if palettes else 0)))
    # the sprite lists no set's animations show (the animations no table leads to)
    shown = {place for _, cells, _ in subjects for place in cells}
    cells, palettes = [], []
    for place, count in sorted(walk.lists.items()):
        more, used = list_cells(image, place, count)
        cells += [cell for cell in more if cell not in shown]
        palettes += used
    subjects.append(("unreached_animations", cells,
                     SPRITE_PALETTES + (Counter(palettes).most_common(1)[0][0] if palettes else 0)))
    return subjects


def tile_subjects(walk, image):
    """[(sheet name, [tile codes], palette)]: by scene and area, then what nothing shows"""
    mem = walk.mem
    subjects = []
    for maps_name, blocks_name in data_walk.MAP_TABLES:
        modes_name = data_walk.MODE_TABLES[1 if maps_name.endswith("_high") else 0]
        maps_table, count, _ = walk.tables_named[maps_name]
        blocks_table = walk.tables_named[blocks_name][0]
        modes_table = walk.tables_named[modes_name][0]
        layer = "a" if "_a" in maps_name else "b"
        for scene in range(count):
            maps = place_of(None, mem.r16(maps_table + 2 * scene))
            blocks = place_of(None, mem.r16(blocks_table + 2 * scene))
            modes = place_of(None, mem.r16(modes_table + 2 * scene))
            number = scene | (0x80 if maps_name.endswith("_high") else 0)
            for area in range(min(walk.scene_records.get(maps, 0), walk.scene_records.get(blocks, 0))):
                map_record, block_record = maps + 4 * area, blocks + 4 * area
                map_place = place_of(mem.r8(map_record + 2) & 0x3F, mem.r16(map_record))
                array = place_of(mem.r8(block_record + 2) & 0x3F, mem.r16(block_record))
                if map_place not in walk.maps or array not in walk.blocks:
                    continue
                mode = modes + 2 * area
                banks = (mem.r8(mode) & 0x0F, mem.r8(mode) >> 4, mem.r8(mode + 1) & 0x0F, mem.r8(mode + 1) >> 4)
                codes, palettes = [], []
                for block in range(walk.blocks[array]):
                    at = array + data_walk.BLOCK * block
                    colour = image[at]
                    for tile in range(16):
                        codes.append(graphics.tile_code(image[at + 2 + tile], colour, banks))
                        palettes.append(colour >> 6)
                scene_name = SCENE_NAMES.get(number, f"scene_{number:02X}")
                subjects.append((f"{scene_name}_area_{area}_layer_{layer}", codes,
                                 LAYER_PALETTES + (Counter(palettes).most_common(1)[0][0] if palettes else 0)))
    return subjects


def sheets(subjects, total):
    """Each code in the first subject that names it; the rest by code, SHEET a sheet: [(name, [codes], palette)]"""
    taken = set()
    found = []
    for name, codes, palette in subjects:
        own = []
        for code in codes:
            if code not in taken:
                taken.add(code)
                own.append(code)
        if own:
            found.append((name, own, palette))
    rest = [code for code in range(total) if code not in taken]
    for first in range(0, len(rest), SHEET):
        chunk = rest[first:first + SHEET]
        found.append((f"unused_{chunk[0]:05X}", chunk, 0))
    return found


def write_sheets(folder, found, pens_of, size, columns, ram, palette_base):
    folder.mkdir(parents=True, exist_ok=True)
    lines = []
    for name, codes, palette in found:
        rows = []
        for top in range(0, len(codes), columns):
            band = [pens_of(code) for code in codes[top:top + columns]]
            band += [[[0] * size for _ in range(size)]] * (columns - len(band))
            for row in range(size):
                rows.append([pen for cell in band for pen in cell[row]])
        asset_formats.write_png_indexed(folder / f"{name}.png", rows, colours(ram, palette or palette_base), 4)
        lines.append(f"{name} " + " ".join(f"{code:04X}" for code in codes))
    (folder / f"{folder.name}.txt").write_text("\n".join(lines) + "\n", encoding="ascii")


def read_sheets(folder, total, size, columns, to_bytes, cell_bytes):
    """The ROM region the sheets in 'folder' and their list give back"""
    region = bytearray(total * cell_bytes)
    for line in (folder / f"{folder.name}.txt").read_text(encoding="ascii").splitlines():
        name, *codes = line.split()
        rows, _ = asset_formats.read_png_indexed(folder / f"{name}.png")
        for index, code in enumerate(int(code, 16) for code in codes):
            top, left = index // columns * size, index % columns * size
            pens = [rows[top + row][left:left + size] for row in range(size)]
            region[code * cell_bytes:(code + 1) * cell_bytes] = to_bytes(pens)
    return bytes(region)


def split_words(region, lanes):
    """build_tiles' and build_sprites' interleaving undone: the chips' bytes"""
    return [bytes(b for pair in zip(region[lane * 2::lanes * 2], region[lane * 2 + 1::lanes * 2]) for b in pair)
            for lane in range(lanes)]


EEPROM_FILE = "eeprom.txt"


def write_eeprom(path, data):
    lines = ["# The ER5911 EEPROM's 128 bytes as the board leaves the factory (the game's settings at its first start)"]
    lines += ["u8 " + " ".join(f"{byte:02X}" for byte in data[at:at + 16]) for at in range(0, len(data), 16)]
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def read_eeprom(path):
    data = bytearray()
    for line in path.read_text(encoding="ascii").splitlines():
        line = line.split("#", 1)[0].split()
        if line and line[0] == "u8":
            data += bytes(int(item, 16) for item in line[1:])
    return bytes(data)


def main():
    arguments = sys.argv[1:]
    check = "--check" in arguments
    if check:
        arguments.remove("--check")
    out = ROOT / "assets"
    if "--out" in arguments:
        position = arguments.index("--out")
        out = Path(arguments[position + 1])
        del arguments[position:position + 2]
    source = Path(arguments[0]) if arguments else ROOT / "rom"
    found_set = rom.load_set(source)
    if check:
        failures = 0
        for folder, files, lanes, total, size, columns, to_bytes, cell_bytes in (
                (out / "tiles", TILE_FILES, 2, graphics.TILES, 8, TILE_COLUMNS, graphics.tile_bytes, graphics.TILE_BYTES),
                (out / "sprites", SPRITE_FILES, 4, graphics.SPRITES, 16, SPRITE_COLUMNS, graphics.sprite_bytes,
                 graphics.SPRITE_BYTES)):
            chips = split_words(read_sheets(folder, total, size, columns, to_bytes, cell_bytes), lanes)
            for name, data in zip(files, chips):
                same = data == found_set[name]
                failures += not same
                print(f"{name}: {'the same' if same else 'DIFFERENT'}")
        program = rom.build_program(found_set)
        data = data_assets.build(out / "data", len(program))
        wrong = sum(1 for place, byte in data.items() if program[place] != byte)
        failures += bool(wrong)
        print(f"the program's data: {len(data)} bytes, {'the same' if not wrong else f'{wrong} DIFFERENT'}")
        sound = rom.build_sound(found_set)
        data = sound_data_assets.build(out / "sound_data")
        wrong = sum(1 for place, byte in data.items() if sound[place] != byte)
        failures += bool(wrong)
        print(f"the sound program's data: {len(data)} bytes, {'the same' if not wrong else f'{wrong} DIFFERENT'}")
        same = read_eeprom(out / EEPROM_FILE) == rom.build_eeprom(found_set)
        failures += not same
        print(f"the EEPROM: {'the same' if same else 'DIFFERENT'}")
        region = sound_assets.read(out / "sounds", len(rom.build_samples(found_set)))
        at = 0
        for name in SAMPLE_FILES:
            same = region[at:at + len(found_set[name])] == found_set[name]
            at += len(found_set[name])
            failures += not same
            print(f"{name}: {'the same' if same else 'DIFFERENT'}")
        return 1 if failures else 0
    # (the folders this writes whole start empty: a sheet or a piece an earlier extraction named otherwise does not stay)
    for folder in ("sprites", "tiles", "data", "sound_data", "sounds"):
        if (out / folder).is_dir():
            shutil.rmtree(out / folder)
    image = rom.build_program(found_set)
    analysis = konami_analysis.Analysis(image, konami_analysis.load_symbols(ROOT / "symbols.txt"))
    analysis.run()
    walk = data_walk.Walk(analysis)
    walk.run()
    ram = palette_ram(walk, image)
    sprites, tiles = rom.build_sprites(found_set), rom.build_tiles(found_set)
    found = sheets(sprite_subjects(walk, image), graphics.SPRITES)
    write_sheets(out / "sprites", found, lambda code: graphics.sprite_pens(sprites, code), 16, SPRITE_COLUMNS, ram,
                 SPRITE_PALETTES)
    print(f"sprites: {len(found)} sheets, {sum(1 for name, _, _ in found if not name.startswith('unused_'))} by subject")
    found = sheets(tile_subjects(walk, image), graphics.TILES)
    write_sheets(out / "tiles", found, lambda code: graphics.tile_pens(tiles, code), 8, TILE_COLUMNS, ram,
                 LAYER_PALETTES)
    print(f"tiles: {len(found)} sheets, {sum(1 for name, _, _ in found if not name.startswith('unused_'))} by subject")
    # the program's data: every byte that is not code, by the coverage's classes and the walk's kinds
    reads, _ = coverage.load_reads([ROOT / "build" / "reads"]) if (ROOT / "build" / "reads").exists() else ({}, {})
    analysis.described.extend((first, stop) for first, (stop, _) in walk.spans.items())
    classes = coverage.classify(analysis, coverage.data_references(analysis, reads), reads)
    names = {place: symbol.name for place, symbol in analysis.symbols.items()}
    names.update({place: name for name, (place, _, _) in data_walk.table_places().items()})
    # what names a piece in the program: the functions whose instructions name its place, by the function an
    # instruction is in (the nearest function before it in its bank, or in the fixed program)
    functions = {place: symbol.name for place, symbol in analysis.symbols.items() if symbol.kind == "func"}
    entries = sorted(functions)

    def function_at(place):
        index = bisect.bisect_right(entries, place) - 1
        if index < 0:
            return None
        entry = entries[index]
        same = (entry >= 0x78000) == (place >= 0x78000) and (place >= 0x78000 or entry >> 13 == place >> 13)
        return functions[entry] if same else None

    readers = defaultdict(set)
    for at, places in analysis.named_by.items():
        function = function_at(at)
        if function is not None:
            for place in places:
                readers[place].add(function)
    taken = set(names.values()) | set(functions.values()) | set(re.findall(
        r"^[0-9A-Fa-f]{4,6}\s+(?:var|io|table|data|func|code)\s+(\w+)",
        (ROOT / "symbols.txt").read_text(encoding="utf-8"), re.M))
    # each object kind's animation table by its set's name (the fixed program reaches it through a bank and an offset,
    # which no ref line follows): its animations, their frames' sprite lists, take their names from it
    for (bank, offset), set_name in sorted(animation_set_names(walk, image).items()):
        table = walk.sets.get((bank, offset))
        if table is None or table in names:
            continue
        name, count = f"{set_name}_animations", 1
        while name in taken:
            count += 1
            name = f"{set_name}_animations_{count}"
        names[table] = name
        taken.add(name)
    count, families = data_assets.export(image, set(analysis.owner), walk.spans,
                                         {place for place, kind in classes.items() if kind == coverage.DESCRIBED},
                                         {place for place, kind in classes.items() if kind == coverage.FILL}, names,
                                         out / "data", set(analysis.instructions),
                                         data_assets.Layouts(ROOT / "symbols.txt"), walk.code_reads,
                                         readers=readers, taken=taken, function_at=function_at)
    print(f"data: {count} pieces in {len(families)} files")
    sound = rom.build_sound(found_set)
    program = z80_analysis.load_program(sound, ROOT / "sound_symbols.txt")
    code = {byte for address, instruction in program.analysis.instructions.items()
            for byte in range(address, address + instruction.length)}
    count = sound_data_assets.export(sound, code, ROOT / "sound_symbols.txt", out / "sound_data")
    print(f"sound data: {count} pieces")
    samples, rest = sound_assets.write(rom.build_sound(found_set), rom.build_samples(found_set), out / "sounds")
    print(f"sounds: {samples} samples, {rest} pieces no sample plays")
    write_eeprom(out / EEPROM_FILE, rom.build_eeprom(found_set))
    print("eeprom: the factory settings")
    return 0


if __name__ == "__main__":
    sys.exit(main())
