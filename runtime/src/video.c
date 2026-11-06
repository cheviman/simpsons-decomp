/**
 *    Name:        video.c
 *    Description: The Simpsons' video: the K052109's three tile layers, the K053246/K053247's sprites, the
 *                 K053251's priorities and colour bases and the palette, drawn from the board's memories as the
 *                 board shows them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Behavior follows MAME 0.289 pixel for pixel: konami/simpsons.cpp's screen update and callbacks (Ernesto
 *    Corvi), the K052109's, the K053246/K053247's and the K053251's (konami/k052109.cpp,
 *    konami/k053246_k053247_k055673.cpp, konami/k053251.cpp), konami_helper's layer sort, and what they use of
 *    emu/tilemap.cpp and emu/drawgfx.cpp (Aaron Giles) and of the palette (util/palette.cpp).
 *    tools/core/konami/reference builds those files into kref, and kref --video-check compares its frames with
 *    these. MAME's terms are in tools/core/konami/reference/mame/LICENSE.
 *
 *    How a frame is made, in a 384 x 264 bitmap of palette pens and one of priorities (lines 16-239 and columns
 *    0-319 shown): the background colour, then the three tile layers in the K053251's order, the one of lowest
 *    priority first, each without its pen 0 and marking the priority bitmap with 1, 2 and 4, then the sprites,
 *    nearest first: a sprite's pixel is not drawn where a nearer sprite was, nor over the layers its priority
 *    puts it under. A layer is a 512 x 256 map of 8 x 8 tiles; the screen's pixel shows the map's pixel its
 *    scroll gives (one for the layer, or one a row, a column, or both, as the K052109's scroll control register
 *    says), all of it turned round when the screen is flipped. The K052109 keeps what each tile shows (its
 *    code, colour and flip) from when it was last marked changed, as MAME's tile maps do. A sprite is 1 to 8
 *    x 8 cells of 16 x 16 pixels, zoomed, flipped or mirrored; its pen 15 shades what is under it when it
 *    casts a shadow. The pens become colours through the palette RAM (xBGR 555); a shaded pen takes 0.6 of
 *    its colour.
 */
#include "simpsons/video.h"

#include "game/data.h"
#include "simpsons/machine.h"

#include <stdbool.h>
#include <string.h>

#define BITMAP_WIDTH    384
#define BITMAP_HEIGHT   264
#define CLIP_LEFT       0
#define CLIP_RIGHT      319
#define CLIP_TOP        16
#define CLIP_BOTTOM     239
#define MAP_WIDTH       512
#define MAP_HEIGHT      256
#define MAP_TILES       (64 * 32)
#define COLOURS         2048            /* the palette's; the shaded ones follow them, then the highlighted */
#define COLOUR_CODES    (COLOURS / 16)  /* the colour codes of a 4-bit tile or cell */
#define TILES           (GAME_TILES_SIZE / 32)
#define SPRITE_CELLS    (GAME_SPRITES_SIZE / 128)
#define SHADOW_FACTOR   0.6f            /* the palette's default (emu/dipalette.h) */
#define SCREEN_WIDTH    BITMAP_WIDTH    /* the screen's width, as the K053247 asks it */
/* tilemap.cpp's flip sums: the visible area's x0 + x1 + 1 and y0 + y1 + 1 */
#define X_EXTENT        (CLIP_RIGHT + CLIP_LEFT + 1)
#define Y_EXTENT        (CLIP_BOTTOM + CLIP_TOP + 1)

/* the K052109's RAM: colour (attribute), then code for the fixed layer, A and B, its registers among them */
#define COLOUR_RAM      0x0000
#define CODE_RAM        0x2000
#define CODE_RAM_2      0x4000
#define TILE_RAM_END    0x1800          /* (of each 8 KB) */
#define SCROLL_Y        0x1800
#define SCROLL_X        0x1A00
#define REG_ADDRESS_MAP 0x1C00
#define REG_SCROLL      0x1C80
#define REG_BANKS_01    0x1D80
#define REG_FLIP        0x1E80
#define REG_BANKS_23    0x1F00

/* drawgfx's draw modes for a pen */
#define DRAW_NONE       0
#define DRAW_SOURCE     1
#define DRAW_SHADOW     2
#define DRAW_SHADOW_PRI 3

/* What a tile of a map shows, as the tile map last read it */
typedef struct
{
	uint16_t code;
	uint8_t colour;
	bool flip_y;
} tile_info;

typedef struct
{
	int dx;                         /* set_scrolldx (the same flipped) */
	int rows, cols;                 /* its scroll: one, a row, a column... (set_scroll_rows, set_scroll_cols) */
	int rowscroll[MAP_HEIGHT];
	int colscroll[MAP_WIDTH / 8];
	bool flipped;                   /* the tile map's flip, X and Y together */
	bool all_dirty;
	bool dirty[MAP_TILES];
	tile_info tiles[MAP_TILES];
} layer;

/* the K052109: its RAM as the chip has it (the board's, at the last VBLANK edge) and the registers it keeps */
static uint8_t g_tile_ram[SIMPSONS_TILE_RAM_SIZE];
static uint8_t g_address_map;
static uint8_t g_scroll_control;
static uint8_t g_tile_flip;
static uint8_t g_char_rom_bank[4];
static layer g_layers[3];

/* simpsons.cpp's: the layers' colour bases (they last drew with), the sprites' and the layers' sorted
   priorities */
static int g_layer_colour_base[3];
static int g_sprite_colour_base;
static int g_layer_priority[3];

/* the K053247's RAM (as the DMA left it) and the K053246's registers */
static uint16_t g_sprite_ram[SIMPSONS_SPRITE_RAM_SIZE / 2];
static uint8_t g_sprite_registers[8];

static uint16_t g_bitmap[BITMAP_HEIGHT * BITMAP_WIDTH];
static uint8_t g_priority[BITMAP_HEIGHT * BITMAP_WIDTH];
static uint32_t g_pens[3 * COLOURS];

static void mark_tile(int map, int index)
{
	g_layers[map].dirty[index] = true;
}

static void mark_all(int map)
{
	g_layers[map].all_dirty = true;
}

/* k052109.cpp's tileflip_reset: the tile maps' flip (a change marks them all) */
static void flip_reset(void)
{
	const bool flipped = (g_tile_flip & 0x01) != 0;

	for (int map = 0; map < 3; map++)
		if (g_layers[map].flipped != flipped)
		{
			g_layers[map].flipped = flipped;
			mark_all(map);
		}
}

/* k052109.cpp's write, for what the drawing uses: the tiles a write changes, the address map, the scroll
   control, the ROM banks and the flips */
static void tile_chip_write(int offset, uint8_t data)
{
	g_tile_ram[offset] = data;
	if ((offset & 0x1FFF) < TILE_RAM_END)
		mark_tile((offset & 0x1800) >> 11, offset & 0x7FF);
	else if (offset == REG_ADDRESS_MAP)
		g_address_map = data;
	else if (offset == REG_SCROLL)
		g_scroll_control = data;
	else if (offset == REG_BANKS_01 || offset == REG_BANKS_23)
	{
		const int first = offset == REG_BANKS_01 ? 0 : 2;
		int dirty = 0;

		if (g_char_rom_bank[first] != (data & 0x0F))
			dirty |= 1;
		if (g_char_rom_bank[first + 1] != ((data >> 4) & 0x0F))
			dirty |= 2;
		if (dirty)
		{
			g_char_rom_bank[first] = data & 0x0F;
			g_char_rom_bank[first + 1] = (data >> 4) & 0x0F;
			/* the tiles whose colour picks a bank that changed */
			for (int index = 0; index < TILE_RAM_END; index++)
			{
				const int bank = (g_tile_ram[index] & 0x0C) >> 2;

				if ((bank == first && (dirty & 1)) || (bank == first + 1 && (dirty & 2)))
					mark_tile((index & 0x1800) >> 11, index & 0x7FF);
			}
		}
	}
	else if (offset == REG_FLIP)
	{
		if ((g_tile_flip & 0x06) != (data & 0x06))
			for (int map = 0; map < 3; map++)
				mark_all(map);
		g_tile_flip = data & 0x07;
		flip_reset();
	}
}

/* The board's memories and registers into the chips: what the program wrote since they last took them (kref's
   video takes them the same way) */
static void load_chips(void)
{
	for (int offset = 0; offset < SIMPSONS_TILE_RAM_SIZE; offset++)
		if (g_tile_ram[offset] != simpsons_board.tile_ram[offset])
			tile_chip_write(offset, simpsons_board.tile_ram[offset]);
	for (int word = 0; word < SIMPSONS_SPRITE_RAM_SIZE / 2; word++)
		g_sprite_ram[word] = (uint16_t)(simpsons_board.object_ram[word * 2] << 8 | simpsons_board.object_ram[word * 2 + 1]);
	memcpy(g_sprite_registers, simpsons_board.sprite_registers, sizeof(g_sprite_registers));
}

void simpsons_video_reset(void)
{
	memset(g_tile_ram, 0, sizeof(g_tile_ram));
	g_address_map = g_scroll_control = g_tile_flip = 0;
	memset(g_char_rom_bank, 0, sizeof(g_char_rom_bank));
	memset(g_layers, 0, sizeof(g_layers));
	g_layers[0].dx = -96;
	g_layers[1].dx = -90;
	g_layers[2].dx = -90;
	for (int map = 0; map < 3; map++)
	{
		g_layers[map].rows = g_layers[map].cols = 1;
		g_layers[map].all_dirty = true;
	}
	memset(g_layer_colour_base, 0, sizeof(g_layer_colour_base));
	g_sprite_colour_base = 0;
	memset(g_layer_priority, 0, sizeof(g_layer_priority));
	memset(g_sprite_ram, 0, sizeof(g_sprite_ram));
	memset(g_sprite_registers, 0, sizeof(g_sprite_registers));
}

/* k052109.cpp's update_scroll, for layers A and B */
static void update_scroll(void)
{
	static const int rows_table[4] = { 1, 1, 32, 256 };

	for (int map = 0; map < 2; map++)
	{
		const int control = (g_scroll_control >> (map * 3)) & 7;
		const int rows = rows_table[control & 3];
		const int cols = (control & 4) ? 64 : 1;
		const uint8_t *scroll_y = &g_tile_ram[SCROLL_Y | (map ? 0x2000 : 0)];
		const uint8_t *scroll_x = &g_tile_ram[SCROLL_X | (map ? 0x2000 : 0)];
		layer *target = &g_layers[map + 1];

		if (rows == 1 && cols == 1)
		{
			target->rows = target->cols = 1;
			target->rowscroll[0] = scroll_x[0] + 256 * scroll_x[1];
			target->colscroll[0] = scroll_y[12];
		}
		else if (cols == 1)
		{
			const int y = scroll_y[12];
			const int mask = rows == 256 ? 0xFF : 0xF8;

			target->rows = 256;
			target->cols = 1;
			target->colscroll[0] = y;
			for (int offset = 0; offset < 256; offset++)
				target->rowscroll[(offset + y) & 0xFF] = scroll_x[2 * (offset & mask)] + 256 * scroll_x[2 * (offset & mask) + 1];
		}
		else if (rows == 1)
		{
			const int x = scroll_x[0] + 256 * scroll_x[1];

			target->rows = 1;
			target->cols = 64;
			target->rowscroll[0] = x;
			for (int offset = 0; offset < 64; offset++)
				target->colscroll[(offset + x / 8) & 0x3F] = scroll_y[offset];
		}
		else
		{
			const int step = rows == 256 ? 2 : 16;

			target->rows = rows;
			target->cols = 64;
			for (int offset = 0; offset < rows; offset++)
				target->rowscroll[offset] = scroll_x[step * offset] + 256 * scroll_x[step * offset + 1];
			for (int offset = 0; offset < 64; offset++)
				target->colscroll[offset] = scroll_y[offset];
		}
	}
}

/* k052109.cpp's get_tile_info with simpsons.cpp's tile callback: what tile 'index' of map 'map' shows now */
static tile_info read_tile(int map, int index)
{
	const int place = map * 0x800 + index;
	int code = g_tile_ram[CODE_RAM + place] + 256 * g_tile_ram[CODE_RAM_2 + place];
	int colour = g_tile_ram[COLOUR_RAM + place];
	int bank = g_char_rom_bank[(colour & 0x0C) >> 2];
	tile_info info;

	if (!(g_address_map & 0x40))
		colour = (colour & 0xF3) | ((bank & 0x03) << 2);
	bank >>= 2;
	info.flip_y = (colour & 0x02) && (g_tile_flip & 0x04);
	code |= ((colour & 0x3F) << 8) | (bank << 14);
	colour = g_layer_colour_base[map] + ((colour & 0xC0) >> 6);
	info.code = (uint16_t)(code % TILES);
	info.colour = (uint8_t)(colour % COLOUR_CODES);
	return info;
}

/* tilemap.cpp's pixmap_update: the tiles marked changed read again */
static void update_tiles(int map)
{
	layer *target = &g_layers[map];

	if (target->all_dirty)
	{
		for (int index = 0; index < MAP_TILES; index++)
			target->dirty[index] = true;
		target->all_dirty = false;
	}
	for (int index = 0; index < MAP_TILES; index++)
		if (target->dirty[index])
		{
			target->tiles[index] = read_tile(map, index);
			target->dirty[index] = false;
		}
}

/* tilemap.cpp's effective_rowscroll and effective_colscroll: where the map's pixmap starts on the screen */
static int effective_rowscroll(const layer *map, int index, bool flipped)
{
	int value;

	if (flipped)
		index = map->rows - 1 - index;
	value = flipped ? X_EXTENT - MAP_WIDTH - (map->dx - map->rowscroll[index]) : map->dx - map->rowscroll[index];
	return value < 0 ? MAP_WIDTH - (-value) % MAP_WIDTH : value % MAP_WIDTH;
}

static int effective_colscroll(const layer *map, int index, bool flipped)
{
	int value;

	if (flipped)
		index = map->cols - 1 - index;
	value = flipped ? Y_EXTENT - MAP_HEIGHT - (0 - map->colscroll[index]) : 0 - map->colscroll[index];
	return value < 0 ? MAP_HEIGHT - (-value) % MAP_HEIGHT : value % MAP_HEIGHT;
}

static int wrap(int value, int size)
{
	value %= size;
	return value < 0 ? value + size : value;
}

/* The pen of a map pixel (0-511, 0-255) and its colour code, from the tile there */
static int tile_pixel(const layer *map, int x, int y, int *colour)
{
	const tile_info *info = &map->tiles[(y >> 3) * 64 + (x >> 3)];
	const int row = info->flip_y ? 7 - (y & 7) : y & 7;
	const int column = x & 7;
	const uint8_t *data = &game_tiles[(size_t)info->code * 32u + (size_t)row * 4u];

	*colour = info->colour;
	return ((data[3] >> (7 - column)) & 1) << 3 | ((data[2] >> (7 - column)) & 1) << 2
		| ((data[1] >> (7 - column)) & 1) << 1 | ((data[0] >> (7 - column)) & 1);
}

/* k052109's tilemap_draw as simpsons.cpp calls it: the map 'map' over the bitmap without its pen 0, its pixels
   marked 'priority' in the priority bitmap */
static void draw_layer(int map, uint8_t priority)
{
	const layer *scroll = &g_layers[map];
	const bool flipped = scroll->flipped;
	int rowscroll[MAP_HEIGHT], colscroll[MAP_WIDTH / 8];
	bool same_rows = true, same_cols = true;
	int rows, cols;

	update_tiles(map);
	for (int index = 0; index < scroll->rows; index++)
	{
		rowscroll[index] = effective_rowscroll(scroll, index, flipped);
		same_rows = same_rows && rowscroll[index] == rowscroll[0];
	}
	for (int index = 0; index < scroll->cols; index++)
	{
		colscroll[index] = effective_colscroll(scroll, index, flipped);
		same_cols = same_cols && colscroll[index] == colscroll[0];
	}
	/* (k052109's tile_blitter takes the scroll of both rows and columns; else tilemap.cpp, which treats a
	   scroll whose rows, or columns, are all the same as one) */
	const bool mixed = scroll->rows > 1 && scroll->cols > 1;
	rows = same_rows ? 1 : scroll->rows;
	cols = same_cols ? 1 : scroll->cols;

	for (int y = CLIP_TOP; y <= CLIP_BOTTOM; y++)
	{
		uint16_t *line = &g_bitmap[y * BITMAP_WIDTH];
		uint8_t *line_priority = &g_priority[y * BITMAP_WIDTH];

		for (int x = CLIP_LEFT; x <= CLIP_RIGHT; x++)
		{
			int px, py, colour, pen;

			if (mixed)
			{
				const int band = y / (MAP_HEIGHT / scroll->rows);
				int start_x = scroll->rowscroll[flipped ? scroll->rows - 1 - band : band] & ~7;

				px = wrap(x - rowscroll[band], MAP_WIDTH);
				if (!flipped)
					start_x = -start_x;
				py = wrap(y - colscroll[((start_x + (px & ~7)) >> 3) & 0x3F], MAP_HEIGHT);
			}
			else if (rows == 1 && cols == 1)
			{
				px = wrap(x - rowscroll[0], MAP_WIDTH);
				py = wrap(y - colscroll[0], MAP_HEIGHT);
			}
			else if (cols == 1)
			{
				py = wrap(y - colscroll[0], MAP_HEIGHT);
				px = wrap(x - rowscroll[py / (MAP_HEIGHT / rows)], MAP_WIDTH);
			}
			else
			{
				px = wrap(x - rowscroll[0], MAP_WIDTH);
				py = wrap(y - colscroll[px / (MAP_WIDTH / cols)], MAP_HEIGHT);
			}
			if (flipped)
			{
				px = MAP_WIDTH - 1 - px;
				py = MAP_HEIGHT - 1 - py;
			}
			pen = tile_pixel(scroll, px, py, &colour);
			if (pen)
			{
				line[x] = (uint16_t)(colour * 16 + pen);
				line_priority[x] |= priority;
			}
		}
	}
}

/* A 16 x 16 sprite cell's pen (the K053247's sprite layout: 8 bytes a row, two pixels a byte, the bytes of each
   word swapped) */
static int cell_pixel(int code, int x, int y)
{
	static const uint8_t k_nibble[16] = { 2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13 };
	const int nibble = k_nibble[x];
	const uint8_t data = game_sprites[(size_t)code * 128u + (size_t)y * 8u + (size_t)(nibble >> 1)];

	return (nibble & 1) ? data & 0x0F : data >> 4;
}

/* drawgfx's PIXEL_OP_REBASE_TRANSTABLE16_PRIORITY: a pixel of a cell over the bitmap, by the pen's draw mode,
   unless the priority bitmap says something nearer is there */
static void cell_pen(uint16_t *destination, uint8_t *priority, int pen, int colour, uint32_t mask, const uint8_t *modes)
{
	const int mode = modes[pen];
	const uint8_t under = *priority;

	if (mode == DRAW_NONE)
		return;
	if (mode == DRAW_SOURCE)
	{
		if (((1u << (under & 0x1F)) & mask) == 0)
		{
			const int value = colour + pen;

			if ((under & 0xC0) == (DRAW_SHADOW_PRI << 6))
				*destination = (uint16_t)((uint16_t)value < COLOURS ? value + COLOURS : value);
			else
				*destination = (uint16_t)value;
		}
		*priority = 31;
	}
	else if ((under & 0x80) == 0 && ((1u << (under & 0x1F)) & mask) == 0)
	{
		/* (the shadow table: a pen of the palette to its shaded one, the others kept) */
		if (*destination < COLOURS)
			*destination = (uint16_t)(*destination + COLOURS);
		*priority = (uint8_t)(under | (mode << 6));
	}
}

/* drawgfx's prio_transtable: a cell at its size */
static void draw_cell(int code, int colour, bool flip_x, bool flip_y, int left, int top, uint32_t mask, const uint8_t *modes)
{
	int right = left + 15, bottom = top + 15, source_x = 0, source_y = 0;

	if (left > CLIP_RIGHT || right < CLIP_LEFT || top > CLIP_BOTTOM || bottom < CLIP_TOP)
		return;
	if (left < CLIP_LEFT)
	{
		source_x = CLIP_LEFT - left;
		left = CLIP_LEFT;
	}
	if (right > CLIP_RIGHT)
		right = CLIP_RIGHT;
	if (top < CLIP_TOP)
	{
		source_y = CLIP_TOP - top;
		top = CLIP_TOP;
	}
	if (bottom > CLIP_BOTTOM)
		bottom = CLIP_BOTTOM;
	if (flip_x)
		source_x = 15 - source_x;
	if (flip_y)
		source_y = 15 - source_y;
	mask |= 1u << 31;
	colour = 16 * (colour % COLOUR_CODES);
	code %= SPRITE_CELLS;
	for (int y = top; y <= bottom; y++, source_y += flip_y ? -1 : 1)
		for (int x = left, sx = source_x; x <= right; x++, sx += flip_x ? -1 : 1)
			cell_pen(&g_bitmap[y * BITMAP_WIDTH + x], &g_priority[y * BITMAP_WIDTH + x], cell_pixel(code, sx, source_y),
				colour, mask, modes);
}

/* drawgfx's prio_zoom_transtable: a cell scaled (16.16 scales), at its size when they are 1 */
static void draw_cell_zoomed(int code, int colour, bool flip_x, bool flip_y, int left, int top, uint32_t scale_x,
	uint32_t scale_y, uint32_t mask, const uint8_t *modes)
{
	if (scale_x == 0x10000 && scale_y == 0x10000)
	{
		draw_cell(code, colour, flip_x, flip_y, left, top, mask, modes);
		return;
	}
	mask |= 1u << 31;
	colour = 16 * (colour % COLOUR_CODES);
	code %= SPRITE_CELLS;

	const uint32_t width = (scale_x * 16 + 0x8000) >> 16;
	const uint32_t height = (scale_y * 16 + 0x8000) >> 16;
	int32_t dx, dy, right, bottom, source_x = 0, source_y = 0;

	if (width < 1 || height < 1)
		return;
	dx = (16 << 16) / (int32_t)width;
	dy = (16 << 16) / (int32_t)height;
	right = left + (int32_t)width - 1;
	if (left > CLIP_RIGHT || right < CLIP_LEFT)
		return;
	if (left < CLIP_LEFT)
	{
		source_x = (CLIP_LEFT - left) * dx;
		left = CLIP_LEFT;
	}
	if (right > CLIP_RIGHT)
		right = CLIP_RIGHT;
	bottom = top + (int32_t)height - 1;
	if (top > CLIP_BOTTOM || bottom < CLIP_TOP)
		return;
	if (top < CLIP_TOP)
	{
		source_y = (CLIP_TOP - top) * dy;
		top = CLIP_TOP;
	}
	if (bottom > CLIP_BOTTOM)
		bottom = CLIP_BOTTOM;
	if (flip_x)
	{
		source_x = (int32_t)(width - 1) * dx - source_x;
		dx = -dx;
	}
	if (flip_y)
	{
		source_y = (int32_t)(height - 1) * dy - source_y;
		dy = -dy;
	}
	for (int y = top; y <= bottom; y++, source_y += dy)
	{
		int32_t sx = source_x;

		for (int x = left; x <= right; x++, sx += dx)
			cell_pen(&g_bitmap[y * BITMAP_WIDTH + x], &g_priority[y * BITMAP_WIDTH + x],
				cell_pixel(code, sx >> 16, source_y >> 16), colour, mask, modes);
	}
}

/* k053247_draw_yxloop_gx, the non-GX path: a sprite's cells */
static void draw_cells(int code, int colour, int height, int width, int zoom_x, int zoom_y, bool flip_x, bool flip_y,
	int ox, int oy, int xa, int ya, bool mirror_x, bool mirror_y, bool no_zoom, uint32_t mask, const uint8_t *modes)
{
	static const int x_offset[8] = { 0, 1, 4, 5, 16, 17, 20, 21 };
	static const int y_offset[8] = { 0, 2, 8, 10, 32, 34, 40, 42 };

	for (int y = 0; y < height; y++)
	{
		const int sy = oy + ((zoom_y * y + (1 << 11)) >> 12);
		const int zh = (oy + ((zoom_y * (y + 1) + (1 << 11)) >> 12)) - sy;

		for (int x = 0; x < width; x++)
		{
			const int sx = ox + ((zoom_x * x + (1 << 11)) >> 12);
			const int zw = (ox + ((zoom_x * (x + 1) + (1 << 11)) >> 12)) - sx;
			int cell = code;
			bool fx, fy;

			if (mirror_x)
			{
				if ((!flip_x) ^ ((x << 1) < width))
				{
					cell += x_offset[(width - 1 - x + xa) & 7];
					fx = true;
				}
				else
				{
					cell += x_offset[(x + xa) & 7];
					fx = false;
				}
			}
			else
			{
				cell += flip_x ? x_offset[(width - 1 - x + xa) & 7] : x_offset[(x + xa) & 7];
				fx = flip_x;
			}
			if (mirror_y)
			{
				if ((!flip_y) ^ ((y << 1) >= height))
				{
					cell += y_offset[(height - 1 - y + ya) & 7];
					fy = true;
				}
				else
				{
					cell += y_offset[(y + ya) & 7];
					fy = false;
				}
			}
			else
			{
				cell += flip_y ? y_offset[(height - 1 - y + ya) & 7] : y_offset[(y + ya) & 7];
				fy = flip_y;
			}

			if (no_zoom)
				draw_cell(cell, colour, fx, fy, sx, sy, mask, modes);
			else
				draw_cell_zoomed(cell, colour, fx, fy, sx, sy, (uint32_t)zw << 12, (uint32_t)zh << 12, mask, modes);
			/* The Simpsons' shadows: a mirrored sprite one cell high is drawn again upside down */
			if (mirror_y && height == 1)
			{
				if (no_zoom)
					draw_cell(cell, colour, fx, !fy, sx, sy, mask, modes);
				else
					draw_cell_zoomed(cell, colour, fx, !fy, sx, sy, (uint32_t)zw << 12, (uint32_t)zh << 12, mask, modes);
			}
		}
	}
}

/* k053247_draw_single_sprite_gxcore, the non-GX path: the sprite at word 'offset' of the sprite RAM */
static void draw_sprite(int code, int offset, int colour, uint32_t mask, int shadow, uint8_t *modes)
{
	const uint16_t *sprite = &g_sprite_ram[offset];
	const bool flip_screen_x = (g_sprite_registers[5] & 0x01) != 0;
	const bool flip_screen_y = (g_sprite_registers[5] & 0x02) != 0;
	const int attributes = sprite[0];
	int xa = 0, ya = 0, ox, oy, zoom_x, zoom_y, scale_x, scale_y, width, height, value;
	bool flip_x, flip_y, mirror_x, mirror_y, no_zoom;

	if (code & 0x01) xa += 1;
	if (code & 0x02) ya += 1;
	if (code & 0x04) xa += 2;
	if (code & 0x08) ya += 2;
	if (code & 0x10) xa += 4;
	if (code & 0x20) ya += 4;
	code &= ~0x3F;

	oy = sprite[2] & 0x3FF;
	ox = sprite[3] & 0x3FF;
	scale_y = zoom_y = sprite[4] & 0x3FF;
	zoom_y = zoom_y ? (0x400000 + (zoom_y >> 1)) / zoom_y : 0x800000;
	if (!(attributes & 0x4000))
	{
		scale_x = zoom_x = sprite[5] & 0x3FF;
		zoom_x = zoom_x ? (0x400000 + (zoom_x >> 1)) / zoom_x : 0x800000;
	}
	else
	{
		zoom_x = zoom_y;
		scale_x = scale_y;
	}
	no_zoom = scale_x == 0x40 && scale_y == 0x40;
	flip_x = (attributes & 0x1000) != 0;
	flip_y = (attributes & 0x2000) != 0;
	mirror_x = (sprite[6] & 0x4000) != 0;
	if (mirror_x)
		flip_x = false;
	mirror_y = (sprite[6] & 0x8000) != 0;

	/* (for Escape Kids: OBJSET1 bit 3 halves the sprites' width) */
	if (g_sprite_registers[5] & 0x08)
	{
		zoom_x >>= 1;
		ox = (ox >> 1) + 1;
		if (flip_screen_x)
			ox += SCREEN_WIDTH;
		no_zoom = false;
	}
	if (flip_screen_x)
	{
		ox = -ox;
		if (!mirror_x)
			flip_x = !flip_x;
	}
	if (flip_screen_y)
	{
		oy = -oy;
		if (!mirror_y)
			flip_y = !flip_y;
	}

	/* the display window's offsets and the wrap (the K053247's OPSET, never written here, is 0: 1024 wide) */
	const int window_x = (int16_t)((g_sprite_registers[0] << 8) | g_sprite_registers[1]);
	const int window_y = (int16_t)((g_sprite_registers[2] << 8) | g_sprite_registers[3]);

	ox = (ox - window_x) & 1023;
	oy = (-oy - window_y) & 1023;
	if (ox >= 1024 - 384)
		ox -= 1024;
	if (oy >= 1024 - 512)
		oy -= 1024;
	value = (attributes >> 8) & 0x0F;
	width = 1 << (value & 3);
	height = 1 << ((value >> 2) & 3);
	/* simpsons.cpp's set_config: the sprites' offsets */
	ox += -43;
	oy -= 23;
	/* the coordinates are the sprite's centre */
	ox -= (zoom_x * width) >> 13;
	oy -= (zoom_y * height) >> 13;

	shadow = (shadow >> 10) & 3;
	modes[15] = shadow ? DRAW_SHADOW : DRAW_SOURCE;
	draw_cells(code, colour, height, width, zoom_x, zoom_y, flip_x, flip_y, ox, oy, xa, ya, mirror_x, mirror_y, no_zoom,
		mask, modes);
}

/* k053247_sprites_draw: the sprites, sorted by their z code (the K053247's OPSET PRI clear: the biggest first),
   drawn from the end of the list (the nearest first) */
static void draw_sprites(void)
{
	int sorted[256], count = 0;
	uint8_t modes[16];

	memset(modes, DRAW_SOURCE, sizeof(modes));
	modes[0] = DRAW_NONE;
	for (int offset = 0; offset < 0x800; offset += 8)
		if (g_sprite_ram[offset] & 0x8000)
			sorted[count++] = offset;

	const int w = count;
	count--;
	const int h = count;

	for (int y = 0; y < h; y++)
	{
		int offset = sorted[y];
		int z = g_sprite_ram[offset] & 0xFF;

		for (int x = y + 1; x < w; x++)
		{
			const int other = sorted[x];
			const int code = g_sprite_ram[other] & 0xFF;

			if (z <= code)
			{
				z = code;
				sorted[x] = offset;
				sorted[y] = offset = other;
			}
		}
	}

	for (; count >= 0; count--)
	{
		const int offset = sorted[count];
		const int code = g_sprite_ram[offset + 1];
		const int attributes = g_sprite_ram[offset + 6];
		/* simpsons.cpp's sprite callback: the priority among the layers and the colour */
		const int priority = (attributes & 0x0F80) >> 6;
		uint32_t mask;

		if (priority <= g_layer_priority[2])
			mask = 0;
		else if (priority <= g_layer_priority[1])
			mask = 0xF0;
		else if (priority <= g_layer_priority[0])
			mask = 0xF0 | 0xCC;
		else
			mask = 0xF0 | 0xCC | 0xAA;
		draw_sprite(code, offset, g_sprite_colour_base + (attributes & 0x001F), mask, attributes, modes);
	}
}

/* The palette RAM's colours (2048, xBGR 555, big endian), and their shaded and highlighted pens */
static uint8_t pal5bit(int value)
{
	value &= 0x1F;
	return (uint8_t)((value << 3) | (value >> 2));
}

static uint8_t adjust(uint8_t component, float contrast)
{
	const int value = (int)((float)component * contrast + 0.0f);

	return (uint8_t)(value < 0 ? 0 : value > 255 ? 255 : value);
}

static void load_palette(void)
{
	const float highlight = 1.0f / SHADOW_FACTOR;

	for (int entry = 0; entry < COLOURS; entry++)
	{
		const int raw = simpsons_board.palette[entry * 2] << 8 | simpsons_board.palette[entry * 2 + 1];
		const uint8_t red = pal5bit(raw), green = pal5bit(raw >> 5), blue = pal5bit(raw >> 10);

		g_pens[entry] = (uint32_t)red << 16 | (uint32_t)green << 8 | blue;
		g_pens[COLOURS + entry] = (uint32_t)adjust(red, SHADOW_FACTOR) << 16 | (uint32_t)adjust(green, SHADOW_FACTOR) << 8
			| adjust(blue, SHADOW_FACTOR);
		g_pens[2 * COLOURS + entry] = (uint32_t)adjust(red, highlight) << 16 | (uint32_t)adjust(green, highlight) << 8
			| adjust(blue, highlight);
	}
}

/* simpsons.cpp's screen_update */
static void draw(simpsons_frame *frame)
{
	/* the K053251's colour bases (registers 9 and 10) and its priorities of CI2-CI4 (the fixed layer, A, B) */
	const uint8_t index_bases = simpsons_board.priority[9] & 0x3F, layer_bases = simpsons_board.priority[10] & 0x3F;
	const int background = 32 * (index_bases & 0x03);
	const int colour_bases[3] = { 32 * ((index_bases >> 4) & 0x03), 16 * (layer_bases & 0x07), 16 * ((layer_bases >> 3) & 0x07) };
	int order[3] = { 0, 1, 2 };

	g_sprite_colour_base = 32 * ((index_bases >> 2) & 0x03);
	for (int map = 0; map < 3; map++)
	{
		if (g_layer_colour_base[map] != colour_bases[map])
			mark_all(map);
		g_layer_colour_base[map] = colour_bases[map];
		g_layer_priority[map] = simpsons_board.priority[2 + map] & 0x3F;
	}
	/* konami_sortlayers3: the lowest priority (the biggest number) first */
	static const int pairs[3][2] = { { 0, 1 }, { 0, 2 }, { 1, 2 } };
	for (int pair = 0; pair < 3; pair++)
	{
		const int a = pairs[pair][0], b = pairs[pair][1];

		if (g_layer_priority[a] < g_layer_priority[b])
		{
			int swap = g_layer_priority[a];
			g_layer_priority[a] = g_layer_priority[b];
			g_layer_priority[b] = swap;
			swap = order[a];
			order[a] = order[b];
			order[b] = swap;
		}
	}

	for (int y = CLIP_TOP; y <= CLIP_BOTTOM; y++)
		for (int x = CLIP_LEFT; x <= CLIP_RIGHT; x++)
		{
			g_bitmap[y * BITMAP_WIDTH + x] = (uint16_t)(16 * background);
			g_priority[y * BITMAP_WIDTH + x] = 0;
		}
	draw_layer(order[0], 1);
	draw_layer(order[1], 2);
	draw_layer(order[2], 4);
	draw_sprites();

	load_palette();
	for (int y = 0; y < SIMPSONS_VIDEO_HEIGHT; y++)
		for (int x = 0; x < SIMPSONS_VIDEO_WIDTH; x++)
			frame->pixels[y * SIMPSONS_VIDEO_WIDTH + x] = g_pens[g_bitmap[(CLIP_TOP + y) * BITMAP_WIDTH + x] % (3 * COLOURS)];
}

void simpsons_video_vblank_end(simpsons_frame *frame)
{
	load_chips();
	update_scroll();
	if (frame)
		draw(frame);
}

void simpsons_video_vblank_start(void)
{
	load_chips();
}

uint64_t simpsons_video_hash(const simpsons_frame *frame)
{
	uint64_t hash = 0xcbf29ce484222325ull;

	for (int index = 0; index < SIMPSONS_VIDEO_WIDTH * SIMPSONS_VIDEO_HEIGHT; index++)
		for (int shift = 16; shift >= 0; shift -= 8)
			hash = (hash ^ ((frame->pixels[index] >> shift) & 0xFFu)) * 0x100000001b3ull;
	return hash;
}
