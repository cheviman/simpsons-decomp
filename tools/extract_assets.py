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
  sound_data/  the Z80 sound program's data and its banks' music, every piece by name, as text by subject
            (tools/sound_data_assets.py: the songs' tracks a command a line, the patches, the driver's tables)
  sounds/   the K053260's samples as WAV files, by the Z80 driver's sample table (tools/sound_assets.py), and the
            bytes no sample plays; samples.txt says where each goes.
With --check, the tile, sprite and sample ROM files are rebuilt from the assets and compared with the set's, byte for byte,
and the program's data bytes with the program's (nothing is written).
"""
import sys
from collections import Counter
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
             0x81: "fat_goon", 0x83: "goon_with_shovel", 0x84: "goon_with_hat", 0x86: "dog", 0x89: "squirrel",
             0x8B: "bird", 0x8D: "lumberjack", 0x8F: "robot", 0x92: "football_player", 0x94: "wrestler",
             0x96: "clown_on_ball", 0x99: "clown_on_ball_2", 0x9B: "ghost", 0x9D: "krusty_balloon", 0x9F: "gorilla",
             0xA2: "bear", 0xAE: "hurry_up", 0xAF: "boulder", 0xB0: "speech_balloons", 0xB1: "speech_balloons_2",
             0xB4: "octopus", 0xBA: "bubbles", 0xBB: "bubbles_2", 0xBC: "knight", 0xBD: "knight_2",
             0xBE: "knight_3", 0xBF: "knight_4", 0xC0: "knight_5", 0xC1: "knight_6", 0xC2: "grim_reaper",
             0xC5: "dog_2", 0xC8: "pointing_hand", 0xCC: "burns_robot", 0xCD: "burns_robot_2", 0xCE: "burns_robot_3",
             0xD0: "bubbles_3", 0xD2: "burns_robot_4", 0xD3: "mr_burns", 0xD4: "burns_robot_5", 0xD5: "numbers"}
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


def sprite_subjects(walk, image):
    """[(sheet name, [cells], palette)]: by animation set, then what nothing shows"""
    names = {}
    for name, high in (("animation_sets", False), ("animation_sets_high", True)):
        table, count, _ = walk.tables_named[name]
        for index in range(count):
            bank, offset = image[table + 2 * index] & 0x3F, image[table + 2 * index + 1]
            kind = index | (0x80 if high else 0)
            names.setdefault((bank, offset), SET_NAMES.get(kind, f"kind_{kind:02X}"))
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
                subjects.append((f"scene_{number:02X}_area_{area}_layer_{layer}", codes,
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
        region = sound_assets.read(out / "sounds", len(rom.build_samples(found_set)))
        at = 0
        for name in SAMPLE_FILES:
            same = region[at:at + len(found_set[name])] == found_set[name]
            at += len(found_set[name])
            failures += not same
            print(f"{name}: {'the same' if same else 'DIFFERENT'}")
        return 1 if failures else 0
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
    count, families = data_assets.export(image, set(analysis.owner), walk.spans,
                                         {place for place, kind in classes.items() if kind == coverage.DESCRIBED},
                                         {place for place, kind in classes.items() if kind == coverage.FILL}, names,
                                         out / "data", set(analysis.instructions))
    print(f"data: {count} pieces in {len(families)} files")
    sound = rom.build_sound(found_set)
    program = z80_analysis.load_program(sound, ROOT / "sound_symbols.txt")
    code = {byte for address, instruction in program.analysis.instructions.items()
            for byte in range(address, address + instruction.length)}
    count = sound_data_assets.export(sound, code, ROOT / "sound_symbols.txt", out / "sound_data")
    print(f"sound data: {count} pieces")
    samples, rest = sound_assets.write(rom.build_sound(found_set), rom.build_samples(found_set), out / "sounds")
    print(f"sounds: {samples} samples, {rest} pieces no sample plays")
    return 0


if __name__ == "__main__":
    sys.exit(main())
