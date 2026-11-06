"""
Name:        simpsons_graphics.py
Description: The Simpsons' tile and sprite graphics: from the ROM files to pixels and back, as the board's chips see
             them
Version:     0.1.0
Created:     06-11-2026
Modified:    06-11-2026
Author:      Sebastian Toyos

The tile ROMs (K052109) and the sprite ROMs (K053246/K053247) as MAME's simpsons.cpp loads them (tools/simpsons_rom.py's
build_tiles and build_sprites, words of the files in turn), read as the chips read them, with no conversion between:
  a tile is 8 x 8 pixels of 4 bits, 32 bytes: a row is 4 bytes, the pen's bit 3 in the 4th, bit 0 in the 1st, the
  leftmost pixel in each byte's top bit (MAME's k052109 charlayout: planes 24, 16, 8, 0);
  a sprite cell is 16 x 16 pixels of 4 bits, 128 bytes: a row is 8 bytes, a pixel a nibble, the high one first, the
  bytes of each 16-bit word swapped (k053247's spritelayout: x offsets 8, 12, 0, 4, 24, 28, 16, 20...).
A sprite of the K053247 is cells by its size (bits 0-1 cells across, 2-3 down, as powers of 2), from its code's
block of 64 (k053246_k053247_k055673.h: the code's low 6 bits are where in the block it starts, each cell at
xoffset[x] + yoffset[y]).
A tile code is the K052109's (k052109.cpp's get_tile_info and simpsons.cpp's tile_callback): the tile's byte, its
colour's bits 0-1 and 4-5 at bits 8-9 and 12-13, and the character bank its colour's bits 2-3 pick (the K052109's
registers 1D80 and 1F00, a nibble each): that bank's bits 0-1 at bits 10-11, its bits 2-3 at bits 14-15.
"""
TILE_BYTES = 32
SPRITE_BYTES = 128
TILES = 0x100000 // TILE_BYTES
SPRITES = 0x400000 // SPRITE_BYTES
XOFFSET = (0, 1, 4, 5, 16, 17, 20, 21)
YOFFSET = (0, 2, 8, 10, 32, 34, 40, 42)
# a sprite row's 16 pixels: the byte and the nibble (4: the high one) of each
SPRITE_ROW = ((1, 4), (1, 0), (0, 4), (0, 0), (3, 4), (3, 0), (2, 4), (2, 0),
              (5, 4), (5, 0), (4, 4), (4, 0), (7, 4), (7, 0), (6, 4), (6, 0))


def tile_pens(data, code):
    """8 rows of 8 pens of the tile 'code'"""
    base = code * TILE_BYTES
    rows = []
    for row in range(8):
        at = base + 4 * row
        planes = (data[at + 3], data[at + 2], data[at + 1], data[at])
        rows.append([(planes[0] >> (7 - x) & 1) << 3 | (planes[1] >> (7 - x) & 1) << 2
                     | (planes[2] >> (7 - x) & 1) << 1 | (planes[3] >> (7 - x) & 1) for x in range(8)])
    return rows


def tile_bytes(pens):
    out = bytearray(TILE_BYTES)
    for row, line in enumerate(pens):
        for lane in range(4):
            value = 0
            for x in range(8):
                value |= (line[x] >> lane & 1) << (7 - x)
            out[4 * row + lane] = value
    return bytes(out)


def sprite_pens(data, code):
    """16 rows of 16 pens of the sprite cell 'code'"""
    base = code * SPRITE_BYTES
    return [[data[base + 8 * row + byte] >> shift & 0x0F for byte, shift in SPRITE_ROW] for row in range(16)]


def sprite_bytes(pens):
    out = bytearray(SPRITE_BYTES)
    for row, line in enumerate(pens):
        for pen, (byte, shift) in zip(line, SPRITE_ROW):
            out[8 * row + byte] |= (pen & 0x0F) << shift
    return bytes(out)


def sprite_cells(code, size):
    """The cells a sprite of 'code' and 'size' (bits 0-1 across, 2-3 down) shows, a row at a time"""
    width, height = 1 << (size & 3), 1 << (size >> 2 & 3)
    across, down = (code & 1) | (code >> 1 & 2) | (code >> 2 & 4), (code >> 1 & 1) | (code >> 2 & 2) | (code >> 3 & 4)
    block = code & ~0x3F
    return [(block + XOFFSET[(x + across) & 7] + YOFFSET[(y + down) & 7]) % SPRITES
            for y in range(height) for x in range(width)]


def tile_code(byte, colour, banks):
    """The K052109's tile code of a tile byte with its colour, 'banks' the 4 character banks (1D80's low and high
    nibble, 1F00's)"""
    bank = banks[colour >> 2 & 3]
    return (byte | (colour & 0x33) << 8 | (bank & 3) << 10 | (bank >> 2 & 3) << 14) % TILES
