/**
 *    Name:        assets.c
 *    Description: the game's assets loaded back into the board's memories (game/assets.h)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The formats are the extractor's (tools/extract_assets.py and the modules it names), read back as its --check
 *    reads them:
 *      tiles/tiles.txt, sprites/sprites.txt   each sheet's codes in its order, the sheet a 4-bit indexed PNG of
 *                                             the cells, 32 tiles or 16 sprite cells a row; a tile is 8 x 8 pens,
 *                                             a sprite cell 16 x 16 (tools/simpsons_graphics.py's tile_bytes and
 *                                             sprite_bytes give their bytes)
 *      sounds/samples.txt                     each WAV and where its bytes go: a sample's levels (KADPCM: the
 *                                             steps between them; PCM: its bytes with their sign bit flipped), the
 *                                             bytes no sample plays as they are, and 'bytes PLACE HEX' lines
 *                                             (tools/sound_assets.py)
 *      data/                                  the 053248 program's data: layout.txt (each piece's name, place,
 *                                             length and file), the files' [NAME] sections of typed lines
 *                                             (tools/data_assets.py's parse_lines: u8, s8, s16, u16, ref, sprite,
 *                                             frame, end, step, area, load, setup, picture, demo, loop, colours,
 *                                             text, record STRUCT, the last by structures.txt)
 *      sound_data/                            the Z80 program's data: layout.txt, the files' sections of u8 lines,
 *                                             and the music (the songs' headers and tracks) from the songs' MIDI
 *                                             files in sound_data/music (tools/sound_data_assets.py,
 *                                             tools/sound_music.py; runtime/src/music.c reads them)
 *    A ref is a piece's name (+ a hex offset) or code_PLACE: the CPU's address of the place, in its bank's window
 *    (6000-7FFF) or the fixed program (8000-FFFF).
 */
#include "game/assets.h"

#include "game/data.h"
#include "music.h"
#include "png.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROBLEM_SIZE    512
#define TILE_COLUMNS    32
#define SPRITE_COLUMNS  16
#define TILE_BYTES      32
#define SPRITE_BYTES    128
#define FIXED_PLACE     0x78000u    /* the program's four banks the CPU sees at 8000-FFFF */
#define BANK_BYTES      0x2000u     /* a bank of the window 6000-7FFF */
#define MUSIC_FAMILY    "music"     /* the sound pieces the MIDI files give */

static char g_problem[PROBLEM_SIZE];

static const struct
{
	const char *name;
	size_t size;
} REGIONS[GAME_ASSETS_REGIONS] = {
	{ "program", GAME_PROGRAM_SIZE }, { "sound", GAME_SOUND_SIZE }, { "tiles", GAME_TILES_SIZE },
	{ "sprites", GAME_SPRITES_SIZE }, { "samples", GAME_SAMPLES_SIZE }, { "eeprom", GAME_EEPROM_SIZE } };

size_t game_assets_size(game_assets_region region)
{
	return region < GAME_ASSETS_REGIONS ? REGIONS[region].size : 0;
}

const char *game_assets_name(game_assets_region region)
{
	return region < GAME_ASSETS_REGIONS ? REGIONS[region].name : "";
}

static int fail(const char *format, ...)
{
	va_list arguments;

	va_start(arguments, format);
	vsnprintf(g_problem, sizeof(g_problem), format, arguments);
	va_end(arguments);
	return 0;
}

static void *grow(void *list, size_t *capacity, size_t needed, size_t unit)
{
	if (needed <= *capacity)
		return list;
	*capacity = needed * 2 + 16;
	return realloc(list, *capacity * unit);
}

static char *copy_text(const char *text, size_t length)
{
	char *copy = malloc(length + 1);

	if (copy)
	{
		memcpy(copy, text, length);
		copy[length] = 0;
	}
	return copy;
}

/* ---- the programs' data as the game keeps it: its pieces, by the places the programs know them by ---- */

/* A piece of a program's data: its bytes, at the place the program knows them by (the addresses it keeps in its
   state, resolved through its bank) */
typedef struct
{
	uint32_t place, size;
	uint8_t *data;
} kept_piece;

typedef struct
{
	kept_piece *pieces;
	size_t count, capacity;
} kept_data;

static kept_data g_kept[GAME_ASSETS_SOUND + 1];    /* the 053248 program's, the sound program's */

static void forget_kept(kept_data *kept)
{
	for (size_t index = 0; index < kept->count; index++)
		free(kept->pieces[index].data);
	free(kept->pieces);
	memset(kept, 0, sizeof(*kept));
}

static int keep(kept_data *kept, uint32_t place, const uint8_t *data, size_t length)
{
	kept_piece *added;

	if (!length)
		return 1;
	kept->pieces = grow(kept->pieces, &kept->capacity, kept->count + 1, sizeof(kept_piece));
	if (!kept->pieces)
		return fail("no memory for the programs' data");
	added = &kept->pieces[kept->count];
	added->place = place;
	added->size = (uint32_t)length;
	added->data = malloc(length);
	if (!added->data)
		return fail("no memory for the programs' data");
	memcpy(added->data, data, length);
	kept->count++;
	return 1;
}

static int by_kept_place(const void *first, const void *second)
{
	const uint32_t a = ((const kept_piece *)first)->place, b = ((const kept_piece *)second)->place;

	return a < b ? -1 : a > b;
}

/* The pieces in the order of their places, none over another */
static int order_kept(kept_data *kept, const char *what)
{
	qsort(kept->pieces, kept->count, sizeof(kept_piece), by_kept_place);
	for (size_t index = 1; index < kept->count; index++)
		if (kept->pieces[index - 1].place + kept->pieces[index - 1].size > kept->pieces[index].place)
			return fail("%s: two pieces at %05X", what, (unsigned)kept->pieces[index].place);
	return 1;
}

static const uint8_t *kept_at(const kept_data *kept, uint32_t place)
{
	size_t low = 0, high = kept->count;
	const kept_piece *found;

	while (low < high)
	{
		const size_t middle = (low + high) / 2;

		if (kept->pieces[middle].place <= place)
			low = middle + 1;
		else
			high = middle;
	}
	if (low == 0)
		return NULL;
	found = &kept->pieces[low - 1];
	return place < found->place + found->size ? found->data + (place - found->place) : NULL;
}

const uint8_t *game_assets_program_at(uint32_t place)
{
	return kept_at(&g_kept[GAME_ASSETS_PROGRAM], place);
}

const uint8_t *game_assets_sound_at(uint32_t place)
{
	return kept_at(&g_kept[GAME_ASSETS_SOUND], place);
}

/* 'data' at 'place' of a region, and its bytes given; a program's data is kept as a piece too */
static int give(const game_assets_memory *into, game_assets_region region, uint32_t place, const uint8_t *data,
	size_t length)
{
	if (place > REGIONS[region].size || length > REGIONS[region].size - place)
		return fail("a piece past the %s region's end (%X)", REGIONS[region].name, (unsigned)place);
	if ((region == GAME_ASSETS_PROGRAM || region == GAME_ASSETS_SOUND) && !keep(&g_kept[region], place, data, length))
		return 0;
	if (into[region].memory)
		memcpy(into[region].memory + place, data, length);
	if (into[region].given)
		memset(into[region].given + place, 1, length);
	return 1;
}

/* ---- files and their lines ---- */

static char *read_file(const char *path, size_t *size)
{
	FILE *file = fopen(path, "rb");
	char *data;
	long length;

	if (!file)
		return NULL;
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (length < 0)
		length = 0;
	data = malloc((size_t)length + 1);
	if (data && length && fread(data, 1, (size_t)length, file) != (size_t)length)
	{
		free(data);
		data = NULL;
	}
	fclose(file);
	if (data)
	{
		data[length] = 0;
		if (size)
			*size = (size_t)length;
	}
	return data;
}

static char *read_asset(const char *folder, const char *path)
{
	char full[1024];
	char *text;

	snprintf(full, sizeof(full), "%s/%s", folder, path);
	if (!(text = read_file(full, NULL)))
		fail("no %s in the assets", path);
	return text;
}

/* The next line of a text read whole, from '*cursor', ended in place (without its '\r'); NULL at its end */
static char *next_line(char **cursor)
{
	char *line = *cursor, *end;
	size_t length;

	if (!*line)
		return NULL;
	end = strchr(line, '\n');
	if (end)
	{
		*end = 0;
		*cursor = end + 1;
	}
	else
		*cursor = line + strlen(line);
	length = strlen(line);
	if (length && line[length - 1] == '\r')
		line[length - 1] = 0;
	return line;
}

static int space_char(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

static int word_char(char c)
{
	return isalnum((unsigned char)c) || c == '_';
}

static int hex_char(char c)
{
	return isxdigit((unsigned char)c) != 0;
}

/* The next word of a line from '*cursor', ended in place; NULL when there is none */
static char *next_token(char **cursor)
{
	char *at = *cursor, *start;

	while (space_char(*at))
		at++;
	if (!*at)
	{
		*cursor = at;
		return NULL;
	}
	start = at;
	while (*at && !space_char(*at))
		at++;
	if (*at)
		*at++ = 0;
	*cursor = at;
	return start;
}

static int blank(const char *line)
{
	while (space_char(*line))
		line++;
	return !*line;
}

static int hex_number(const char *text, uint32_t *value)
{
	char *end;
	unsigned long parsed;

	if (!text || !*text)
		return 0;
	parsed = strtoul(text, &end, 16);
	if (*end)
		return 0;
	*value = (uint32_t)parsed;
	return 1;
}

static int decimal_number(const char *text, int32_t *value)
{
	char *end;
	long parsed;

	if (!text || !*text)
		return 0;
	parsed = strtol(text, &end, 10);
	if (*end)
		return 0;
	*value = (int32_t)parsed;
	return 1;
}

/* ---- the tiles and the sprites ---- */

/* An 8 x 8 tile at (left, top) of a sheet into its 32 bytes: a row is 4 bytes, the pens' bit 0 in the first, bit
   3 in the 4th, the leftmost pixel in each byte's top bit */
static void tile_bytes(const png_image *image, uint32_t left, uint32_t top, uint8_t *out)
{
	for (uint32_t row = 0; row < 8; row++)
		for (int lane = 0; lane < 4; lane++)
		{
			uint8_t value = 0;

			for (uint32_t x = 0; x < 8; x++)
				value |= (uint8_t)(((image->pixels[(top + row) * image->width + left + x] >> lane) & 1) << (7 - x));
			out[row * 4 + (uint32_t)lane] = value;
		}
}

/* a sprite row's 16 pixels: the byte of the row's 8 and the nibble (4: the high one) of each */
static const uint8_t SPRITE_ROW[16][2] = {
	{ 1, 4 }, { 1, 0 }, { 0, 4 }, { 0, 0 }, { 3, 4 }, { 3, 0 }, { 2, 4 }, { 2, 0 },
	{ 5, 4 }, { 5, 0 }, { 4, 4 }, { 4, 0 }, { 7, 4 }, { 7, 0 }, { 6, 4 }, { 6, 0 } };

/* A 16 x 16 sprite cell at (left, top) of a sheet into its 128 bytes: a row is 8 bytes, a pixel a nibble, the
   bytes of each 16-bit word swapped */
static void sprite_bytes(const png_image *image, uint32_t left, uint32_t top, uint8_t *out)
{
	memset(out, 0, SPRITE_BYTES);
	for (uint32_t row = 0; row < 16; row++)
		for (uint32_t x = 0; x < 16; x++)
			out[8 * row + SPRITE_ROW[x][0]] |= (uint8_t)((image->pixels[(top + row) * image->width + left + x] & 0x0F)
				<< SPRITE_ROW[x][1]);
}

/* The sheets 'sub'/'sub'.txt lists ("NAME CODE ..."): each sheet's cells into the region, 'columns' a row */
static int read_sheets(const char *folder, const char *sub, game_assets_region region, uint32_t size,
	uint32_t columns, uint32_t cell_bytes, const game_assets_memory *into)
{
	char path[1024], *text, *cursor, *line;
	const uint32_t codes = (uint32_t)(REGIONS[region].size / cell_bytes);
	int ok = 1;

	snprintf(path, sizeof(path), "%s/%s.txt", sub, sub);
	if (!(text = read_asset(folder, path)))
		return 0;
	cursor = text;
	while (ok && (line = next_line(&cursor)) != NULL)
	{
		char *at = line, *sheet = next_token(&at), *item;
		png_image image;
		const char *problem;
		uint32_t cell = 0;

		if (!sheet || sheet[0] == '#')
			continue;
		snprintf(path, sizeof(path), "%s/%s/%s.png", folder, sub, sheet);
		if ((problem = png_read(path, &image)) != NULL)
		{
			ok = fail("%s/%s.png %s", sub, sheet, problem);
			break;
		}
		while (ok && (item = next_token(&at)) != NULL)
		{
			uint32_t code;
			uint8_t bytes[SPRITE_BYTES];
			const uint32_t left = (cell % columns) * size, top = (cell / columns) * size;

			if (!hex_number(item, &code) || code >= codes)
				ok = fail("%s/%s.txt: %s, %s is no code of the %s", sub, sub, sheet, item, REGIONS[region].name);
			else if (left + size > image.width || top + size > image.height)
				ok = fail("%s/%s.png is smaller than its codes", sub, sheet);
			else
			{
				if (size == 8)
					tile_bytes(&image, left, top, bytes);
				else
					sprite_bytes(&image, left, top, bytes);
				ok = give(into, region, code * cell_bytes, bytes, cell_bytes);
			}
			cell++;
		}
		png_free(&image);
	}
	free(text);
	return ok;
}

/* ---- the samples ---- */

/* A mono PCM WAV's samples as 8-bit unsigned (a 16-bit one's high byte): asset_formats.py's read_wav_unsigned */
static int read_wav(const char *folder, const char *name, uint8_t **samples, size_t *count)
{
	char path[1024];
	size_t size, at = 12;
	uint8_t *file;
	const uint8_t *data = NULL;
	size_t data_size = 0;
	int bits = 0, channels = 0, ok = 1;

	snprintf(path, sizeof(path), "%s/sounds/%s.wav", folder, name);
	if (!(file = (uint8_t *)read_file(path, &size)))
		return fail("no sounds/%s.wav in the assets", name);
	if (size < 12 || memcmp(file, "RIFF", 4) || memcmp(file + 8, "WAVE", 4))
		ok = fail("sounds/%s.wav is not a WAV file", name);
	while (ok && at + 8 <= size)
	{
		size_t chunk = (size_t)file[at + 4] | (size_t)file[at + 5] << 8 | (size_t)file[at + 6] << 16
			| (size_t)file[at + 7] << 24;
		const uint8_t *body = file + at + 8;
		const size_t length = chunk <= size - at - 8 ? chunk : size - at - 8;

		if (!memcmp(file + at, "fmt ", 4) && length >= 16)
		{
			if ((body[0] | body[1] << 8) != 1)
				ok = fail("sounds/%s.wav is not PCM", name);
			channels = body[2] | body[3] << 8;
			bits = body[14] | body[15] << 8;
		}
		else if (!memcmp(file + at, "data", 4))
		{
			data = body;
			data_size = length;
		}
		at += 8 + chunk + (chunk & 1);
	}
	if (ok && (!data || (bits != 8 && bits != 16) || channels != 1))
		ok = fail("sounds/%s.wav is not a mono 8 or 16-bit PCM WAV", name);
	if (ok)
	{
		*count = bits == 8 ? data_size : data_size / 2;
		if (!(*samples = malloc(*count ? *count : 1u)))
			ok = fail("no memory for sounds/%s.wav", name);
		else if (bits == 8)
			memcpy(*samples, data, *count);
		else
			for (size_t index = 0; index < *count; index++)
				(*samples)[index] = (uint8_t)(data[2 * index + 1] ^ 0x80);
	}
	free(file);
	return ok;
}

/* the K053260's KADPCM steps, a nibble each */
static const int KADPCM_STEPS[16] = { 0, 1, 2, 4, 8, 16, 32, 64, -128, -64, -32, -16, -8, -4, -2, -1 };

static int read_samples(const char *folder, const game_assets_memory *into)
{
	char *text, *cursor, *line;
	int step_of[256];
	int ok = 1;

	for (int index = 0; index < 256; index++)
		step_of[index] = -1;
	for (int nibble = 0; nibble < 16; nibble++)
		step_of[KADPCM_STEPS[nibble] & 0xFF] = nibble;
	if (!(text = read_asset(folder, "sounds/samples.txt")))
		return 0;
	cursor = text;
	while (ok && (line = next_line(&cursor)) != NULL)
	{
		char *at = line, *name = next_token(&at), *first_text = next_token(&at), *third = next_token(&at);
		char *fourth = next_token(&at);
		uint32_t first, length;
		uint8_t *samples = NULL, *data = NULL;
		size_t count = 0, size = 0;

		if (!name)
			continue;
		if (!strcmp(name, "bytes"))
		{
			/* bytes PLACE HEX */
			size_t digits = third ? strlen(third) : 0;

			if (!hex_number(first_text, &first) || !third || fourth || digits % 2)
			{
				ok = fail("sounds/samples.txt: a line it does not read (bytes %s)", first_text ? first_text : "");
				break;
			}
			if (!(data = malloc(digits / 2 + 1)))
			{
				ok = fail("no memory for the samples");
				break;
			}
			for (size_t index = 0; index < digits / 2 && ok; index++)
			{
				const char pair[3] = { third[2 * index], third[2 * index + 1], 0 };
				uint32_t value;

				if (!hex_number(pair, &value))
					ok = fail("sounds/samples.txt: bytes %s are not hex", first_text);
				data[index] = (uint8_t)value;
			}
			if (ok)
				ok = give(into, GAME_ASSETS_SAMPLES, first, data, digits / 2);
			free(data);
			continue;
		}
		/* NAME FIRST LENGTH KIND */
		{
			int32_t signed_length;

			if (!hex_number(first_text, &first) || !decimal_number(third, &signed_length) || signed_length < 0
				|| !fourth || next_token(&at))
			{
				ok = fail("sounds/samples.txt: a line it does not read (%s)", name);
				break;
			}
			length = (uint32_t)signed_length;
		}
		if (!read_wav(folder, name, &samples, &count))
		{
			ok = 0;
			break;
		}
		if (!strcmp(fourth, "kadpcm"))
		{
			/* the steps between the levels, two a byte, the low nibble first */
			int previous = 0, low = -1;

			if (!(data = malloc(count / 2 + 1)))
				ok = fail("no memory for the samples");
			for (size_t index = 0; index < count && ok; index++)
			{
				const int level = samples[index] ^ 0x80, nibble = step_of[(level - previous) & 0xFF];

				if (nibble < 0)
					ok = fail("sounds/%s.wav: the level %zu is no KADPCM step from the one before", name, index);
				previous = level;
				if (low < 0)
					low = nibble;
				else
				{
					data[size++] = (uint8_t)(low | nibble << 4);
					low = -1;
				}
			}
		}
		else if (!strcmp(fourth, "pcm"))
		{
			if (!(data = malloc(count + 1)))
				ok = fail("no memory for the samples");
			for (size_t index = 0; index < count && ok; index++)
				data[size++] = (uint8_t)(samples[index] ^ 0x80);
		}
		else
		{
			data = samples;
			samples = NULL;
			size = count;
		}
		if (ok && size != length)
			ok = fail("sounds/%s.wav: %zu bytes, samples.txt says %u", name, size, (unsigned)length);
		if (ok)
			ok = give(into, GAME_ASSETS_SAMPLES, first, data, size);
		free(samples);
		free(data);
	}
	free(text);
	return ok;
}

/* ---- the record lines' structures (data/structures.txt, tools/data_assets.py's write_structures) ---- */

enum { VALUE_S16, VALUE_S8, VALUE_U16, VALUE_U8 };

typedef struct
{
	char *name;
	uint8_t *values;            /* its values' types in byte order */
	size_t value_count;
} structure;

typedef struct
{
	structure *list;
	size_t count, capacity;
} structures;

static void free_structures(structures *all)
{
	for (size_t index = 0; index < all->count; index++)
	{
		free(all->list[index].name);
		free(all->list[index].values);
	}
	free(all->list);
	memset(all, 0, sizeof(*all));
}

static structure *structure_named(const structures *all, const char *name)
{
	for (size_t index = 0; index < all->count; index++)
		if (!strcmp(all->list[index].name, name))
			return &all->list[index];
	return NULL;
}

static int value_type(const char *name, uint8_t *type)
{
	static const char *const NAMES[4] = { "s16", "s8", "u16", "u8" };

	for (int index = 0; index < 4; index++)
		if (!strcmp(name, NAMES[index]))
		{
			*type = (uint8_t)index;
			return 1;
		}
	return 0;
}

/* data/structures.txt: a structure a line, its name and its values' types (u8 s8 u16 s16); '#' a comment */
static int read_structures(const char *folder, structures *all)
{
	char *text = read_asset(folder, "data/structures.txt"), *cursor = text, *line;
	int ok = text != NULL;

	memset(all, 0, sizeof(*all));
	while (ok && (line = next_line(&cursor)) != NULL)
	{
		char *comment = strchr(line, '#'), *at = line, *name, *item;
		structure *added;

		if (comment)
			*comment = 0;
		if (!(name = next_token(&at)))
			continue;
		if (structure_named(all, name))
		{
			ok = fail("data/structures.txt: %s twice", name);
			break;
		}
		all->list = grow(all->list, &all->capacity, all->count + 1, sizeof(structure));
		if (!all->list)
		{
			ok = fail("no memory for the record structures");
			break;
		}
		added = &all->list[all->count++];
		memset(added, 0, sizeof(*added));
		added->name = copy_text(name, strlen(name));
		added->values = malloc(strlen(at) / 2 + 1);
		if (!added->name || !added->values)
		{
			ok = fail("no memory for the record structures");
			break;
		}
		while (ok && (item = next_token(&at)) != NULL)
			if (!value_type(item, &added->values[added->value_count++]))
				ok = fail("data/structures.txt: %s: %s is no type", name, item);
	}
	free(text);
	return ok;
}

/* ---- a data folder's layout ---- */

typedef struct
{
	char *name;
	uint32_t place, length;
	char *family;
	uint8_t *data;              /* the bytes its section gives (the sound program's text pieces) */
	size_t size;
	int given;
} piece;

typedef struct
{
	piece *pieces;
	size_t count, capacity;
	piece **by_name;
	piece **by_place;
} layout;

static void free_layout(layout *all)
{
	for (size_t index = 0; index < all->count; index++)
	{
		free(all->pieces[index].name);
		free(all->pieces[index].family);
		free(all->pieces[index].data);
	}
	free(all->pieces);
	free(all->by_name);
	free(all->by_place);
	memset(all, 0, sizeof(*all));
}

static int by_name(const void *first, const void *second)
{
	return strcmp((*(piece *const *)first)->name, (*(piece *const *)second)->name);
}

static int by_place(const void *first, const void *second)
{
	const uint32_t a = (*(piece *const *)first)->place, b = (*(piece *const *)second)->place;

	return a < b ? -1 : a > b;
}

static piece *piece_named(const layout *all, const char *name)
{
	piece key, *pointer = &key, **found;

	key.name = (char *)name;
	found = bsearch(&pointer, all->by_name, all->count, sizeof(piece *), by_name);
	return found ? *found : NULL;
}

/* 'data_folder'/layout.txt: "NAME PLACE LENGTH FAMILY" a piece */
static int read_layout(const char *folder, const char *data_folder, layout *all)
{
	char path[256], *text, *cursor, *line;
	int ok = 1;

	memset(all, 0, sizeof(*all));
	snprintf(path, sizeof(path), "%s/layout.txt", data_folder);
	if (!(text = read_asset(folder, path)))
		return 0;
	cursor = text;
	while (ok && (line = next_line(&cursor)) != NULL)
	{
		char *at = line, *name = next_token(&at), *place = next_token(&at), *length = next_token(&at);
		char *family = next_token(&at);
		piece *added;
		int32_t count;

		if (!name)
			continue;
		all->pieces = grow(all->pieces, &all->capacity, all->count + 1, sizeof(piece));
		if (!all->pieces)
		{
			ok = fail("no memory for %s", path);
			break;
		}
		added = &all->pieces[all->count];
		memset(added, 0, sizeof(*added));
		if (!family || next_token(&at) || !hex_number(place, &added->place) || !decimal_number(length, &count)
			|| count < 0)
		{
			ok = fail("%s: a line it does not read (%s)", path, name);
			break;
		}
		added->length = (uint32_t)count;
		added->name = copy_text(name, strlen(name));
		added->family = copy_text(family, strlen(family));
		all->count++;
		if (!added->name || !added->family)
			ok = fail("no memory for %s", path);
	}
	free(text);
	if (ok)
	{
		all->by_name = malloc((all->count + 1) * sizeof(piece *));
		all->by_place = malloc((all->count + 1) * sizeof(piece *));
		if (!all->by_name || !all->by_place)
			return fail("no memory for %s", path);
		for (size_t index = 0; index < all->count; index++)
			all->by_name[index] = all->by_place[index] = &all->pieces[index];
		qsort(all->by_name, all->count, sizeof(piece *), by_name);
		qsort(all->by_place, all->count, sizeof(piece *), by_place);
	}
	return ok;
}

/* The files of 'family' sections ([NAME] a piece, then its lines): each line through 'parse', each section's bytes
   to 'done' (its piece, or NULL for a section no layout has) */
typedef struct
{
	uint8_t *data;
	size_t size, capacity;
} writer;

static int put(writer *into, uint32_t value, int bytes)
{
	if (into->size + (size_t)bytes > into->capacity)
	{
		uint8_t *grown;

		into->capacity = (into->capacity + (size_t)bytes) * 2 + 64;
		if (!(grown = realloc(into->data, into->capacity)))
			return fail("no memory for the data");
		into->data = grown;
	}
	for (int index = bytes - 1; index >= 0; index--)
		into->data[into->size++] = (uint8_t)(value >> (8 * index));
	return 1;
}

typedef int (*line_parser)(void *context, writer *into, char *line, const char *where);
typedef int (*section_done)(void *context, piece *owner, writer *from, const char *file);

static int read_sections(const char *folder, const char *data_folder, layout *all, void *context,
	line_parser parse, section_done done)
{
	int ok = 1;

	for (size_t index = 0; index < all->count && ok; index++)
	{
		const char *family = all->pieces[index].family;
		char path[256], where[512], *text, *cursor, *line;
		piece *current = NULL;
		int in_section = 0, seen = 0;
		writer into = { NULL, 0, 0 };

		for (size_t before = 0; before < index && !seen; before++)
			seen = !strcmp(all->pieces[before].family, family);
		if (seen || !strcmp(family, MUSIC_FAMILY))
			continue;
		snprintf(path, sizeof(path), "%s/%s.txt", data_folder, family);
		if (!(text = read_asset(folder, path)))
			return 0;
		cursor = text;
		while (ok)
		{
			line = next_line(&cursor);
			if (!line || line[0] == '[')
			{
				if (in_section)
				{
					ok = done(context, current, &into, path);
					into.size = 0;
				}
				if (!line || !ok)
					break;
				{
					char *close = strchr(line, ']');

					if (!close)
					{
						ok = fail("%s: a section's name is not closed", path);
						break;
					}
					*close = 0;
					current = piece_named(all, line + 1);
					in_section = 1;
				}
				continue;
			}
			if (!in_section || blank(line))
				continue;
			snprintf(where, sizeof(where), "%s [%s]", path, current ? current->name : "?");
			ok = parse(context, &into, line, where);
		}
		free(into.data);
		free(text);
	}
	for (size_t index = 0; index < all->count && ok; index++)
		if (!all->pieces[index].given && strcmp(all->pieces[index].family, MUSIC_FAMILY))
			ok = fail("%s: no file gives %s (layout.txt)", data_folder, all->pieces[index].name);
	return ok;
}

/* ---- the 053248 program's data ---- */

typedef struct
{
	const layout *pieces;
	const structures *records;
	const game_assets_memory *into;
} program_context;

/* A word item: 4 hex digits, or a ref (NAME[+N], code_PLACE): the CPU's address of the place */
static int word_of(const program_context *context, const char *item, uint32_t *word, const char *where)
{
	const char *plus = strchr(item, '+');
	const size_t length = plus ? (size_t)(plus - item) : strlen(item);
	char name[256];
	uint32_t place, offset = 0;

	if (strlen(item) == 4 && hex_char(item[0]) && hex_char(item[1]) && hex_char(item[2]) && hex_char(item[3]))
		return hex_number(item, word);
	if (length >= sizeof(name))
		return fail("%s: a name too long (%s)", where, item);
	memcpy(name, item, length);
	name[length] = 0;
	if (!strncmp(name, "code_", 5))
	{
		if (!hex_number(name + 5, &place))
			return fail("%s: %s is no place of code", where, item);
	}
	else
	{
		const piece *found = piece_named(context->pieces, name);

		if (!found)
			return fail("%s: %s is the name of no piece", where, item);
		place = found->place;
	}
	if (plus && plus[1] && !hex_number(plus + 1, &offset))
		return fail("%s: %s has an offset that is not hex", where, item);
	place += offset;
	*word = place >= FIXED_PLACE ? 0x8000u + place - FIXED_PLACE : 0x6000u + place % BANK_BYTES;
	if (*word > 0xFFFF)
		return fail("%s: %s is past the CPU's addresses", where, item);
	return 1;
}

static int put_hex(writer *into, const char *item, uint32_t most, int bytes, const char *where)
{
	uint32_t value;

	if (!hex_number(item, &value) || value > most)
		return fail("%s: %s is no value of %d byte%s", where, item, bytes, bytes > 1 ? "s" : "");
	return put(into, value, bytes);
}

static int put_word(const program_context *context, writer *into, const char *item, const char *where)
{
	uint32_t word;

	return word_of(context, item, &word, where) && put(into, word, 2);
}

/* the lines whose items are fields of a record: 'w' a word (4 hex digits or a ref), 'b' a byte; 'loop' after FFFF */
static const struct
{
	const char *kind, *fields;
} LINE_FIELDS[] = {
	{ "area", "wbb" }, { "load", "wwb" }, { "setup", "wwbb" }, { "picture", "bww" }, { "demo", "bwbwwww" },
	{ "loop", "wwb" } };

#define PATH_END 0xFFFFu

/* One typed line of a piece into its bytes (tools/data_assets.py's parse_lines) */
static int program_line(void *data, writer *into, char *line, const char *where)
{
	const program_context *context = data;
	char *rest = line, *kind = next_token(&rest), *item, *items[8];
	int count = 0;

	if (!kind)
		return 1;
	if (!strcmp(kind, "u8") || !strcmp(kind, "step"))
	{
		while ((item = next_token(&rest)) != NULL)
			if (!put_hex(into, item, 0xFF, 1, where))
				return 0;
		return 1;
	}
	if (!strcmp(kind, "s8"))
	{
		while ((item = next_token(&rest)) != NULL)
		{
			int32_t value;

			if (!decimal_number(item, &value))
				return fail("%s: %s is no number", where, item);
			if (!put(into, (uint32_t)value & 0xFF, 1))
				return 0;
		}
		return 1;
	}
	if (!strcmp(kind, "s16") || !strcmp(kind, "u16") || !strcmp(kind, "ref"))
	{
		int32_t value;

		item = next_token(&rest);
		if (!item || next_token(&rest))
			return fail("%s: a %s line holds one item", where, kind);
		if (kind[0] == 's')
		{
			if (!decimal_number(item, &value))
				return fail("%s: %s is no number", where, item);
			return put(into, (uint32_t)value & 0xFFFF, 2);
		}
		if (kind[0] == 'u')
			return put_hex(into, item, 0xFFFF, 2, where);
		return put_word(context, into, item, where);
	}
	if (!strcmp(kind, "sprite"))
	{
		while (count < 6 && (items[count] = next_token(&rest)) != NULL)
			count++;
		if (count != 5)
			return fail("%s: a sprite is 5 items", where);
		return put_hex(into, items[0], 0xFFFF, 2, where) && put_hex(into, items[1], 0xFF, 1, where)
			&& put_hex(into, items[2], 0xFF, 1, where) && put_hex(into, items[3], 0xFF, 1, where)
			&& put_hex(into, items[4], 0xFF, 1, where);
	}
	if (!strcmp(kind, "frame") || !strcmp(kind, "end"))
	{
		while (count < 4 && (items[count] = next_token(&rest)) != NULL)
			count++;
		if (count != 3)
			return fail("%s: a %s is 3 items", where, kind);
		return put_hex(into, items[0], 0xFF, 1, where) && put_hex(into, items[1], 0xFF, 1, where)
			&& put_word(context, into, items[2], where);
	}
	if (!strcmp(kind, "record"))
	{
		const char *name = next_token(&rest);
		const structure *shape = name ? structure_named(context->records, name) : NULL;

		if (!shape)
			return fail("%s: record %s is none of data/structures.txt's", where, name ? name : "");
		/* (its values and the items in turn, as far as both go) */
		for (size_t value = 0; value < shape->value_count && (item = next_token(&rest)) != NULL; value++)
		{
			int32_t number;

			switch (shape->values[value])
			{
			case VALUE_U8:
				if (!put_hex(into, item, 0xFF, 1, where))
					return 0;
				break;
			case VALUE_S8:
			case VALUE_S16:
				if (!decimal_number(item, &number))
					return fail("%s: %s is no number", where, item);
				if (!put(into, (uint32_t)number & (shape->values[value] == VALUE_S8 ? 0xFFu : 0xFFFFu),
					shape->values[value] == VALUE_S8 ? 1 : 2))
					return 0;
				break;
			default:
				if (!put_word(context, into, item, where))
					return 0;
				break;
			}
		}
		return 1;
	}
	for (size_t index = 0; index < sizeof(LINE_FIELDS) / sizeof(LINE_FIELDS[0]); index++)
	{
		const char *field;

		if (strcmp(kind, LINE_FIELDS[index].kind))
			continue;
		if (!strcmp(kind, "loop") && !put(into, PATH_END, 2))
			return 0;
		for (field = LINE_FIELDS[index].fields; *field && (item = next_token(&rest)) != NULL; field++)
			if (*field == 'b' ? !put_hex(into, item, 0xFF, 1, where) : !put_word(context, into, item, where))
				return 0;
		return 1;
	}
	if (!strcmp(kind, "colours"))
	{
		/* each #RRGGBB[+]: 5 bits a component, '+' bit 15 */
		for (const char *at = rest; *at; at++)
		{
			uint32_t value = 0;
			int digits = 0;

			if (*at != '#')
				continue;
			while (digits < 6 && hex_char(at[1 + digits]))
				digits++;
			if (digits < 6)
				continue;
			for (int component = 0; component < 3; component++)
			{
				const char pair[3] = { at[1 + 2 * component], at[2 + 2 * component], 0 };

				value |= (uint32_t)(strtoul(pair, NULL, 16) >> 3) << (5 * component);
			}
			at += 6;
			if (at[1] == '+')
			{
				value |= 0x8000;
				at++;
			}
			if (!put(into, value, 2))
				return 0;
		}
		return 1;
	}
	if (!strcmp(kind, "text"))
	{
		/* between the first quote that has a closing one (a backslash takes the character after it) */
		for (const char *open = strchr(rest, '"'); open; open = strchr(open + 1, '"'))
		{
			const char *at = open + 1;

			while (*at && *at != '"')
				at += (*at == '\\' && at[1]) ? 2 : 1;
			if (*at != '"')
				continue;
			for (const char *body = open + 1; body < at;)
			{
				if (*body == '\\')
				{
					const char pair[3] = { body + 2 < at ? body[2] : 0, body + 3 < at ? body[3] : 0, 0 };
					uint32_t value;

					if (!hex_number(pair, &value))
						return fail("%s: an escape of the text that is not \\xNN", where);
					if (!put(into, value, 1))
						return 0;
					body += 4;
				}
				else
				{
					if (!put(into, (uint8_t)*body, 1))
						return 0;
					body++;
				}
			}
			return 1;
		}
		return fail("%s: a text that is not between quotes", where);
	}
	return fail("%s: a line no format reads (%s)", where, kind);
}

static int program_section(void *data, piece *owner, writer *from, const char *file)
{
	const program_context *context = data;

	if (!owner)
		return 1;
	if (from->size != owner->length)
		return fail("%s: %s gives %zu bytes, layout.txt says %u", file, owner->name, from->size,
			(unsigned)owner->length);
	owner->given = 1;
	return give(context->into, GAME_ASSETS_PROGRAM, owner->place, from->data, from->size);
}

static int read_program_data(const char *folder, const game_assets_memory *into)
{
	layout pieces;
	structures records;
	program_context context;
	int ok;

	memset(&pieces, 0, sizeof(pieces));
	ok = read_structures(folder, &records) && read_layout(folder, "data", &pieces);
	if (ok)
	{
		context.pieces = &pieces;
		context.records = &records;
		context.into = into;
		ok = read_sections(folder, "data", &pieces, &context, program_line, program_section);
	}
	free_layout(&pieces);
	free_structures(&records);
	return ok;
}

/* ---- the Z80 program's data ---- */

static int sound_line(void *data, writer *into, char *line, const char *where)
{
	char *rest = line, *item;

	(void)data;
	if (!next_token(&rest))
		return 1;
	while ((item = next_token(&rest)) != NULL)
		if (!put_hex(into, item, 0xFF, 1, where))
			return 0;
	return 1;
}

static int sound_section(void *data, piece *owner, writer *from, const char *file)
{
	const game_assets_memory *into = data;

	if (!owner)
		return 1;
	if (from->size != owner->length)
		return fail("%s: %s gives %zu bytes, layout.txt says %u", file, owner->name, from->size,
			(unsigned)owner->length);
	free(owner->data);
	if (!(owner->data = malloc(from->size + 1)))
		return fail("no memory for the sound data");
	memcpy(owner->data, from->data, from->size);
	owner->size = from->size;
	owner->given = 1;
	return give(into, GAME_ASSETS_SOUND, owner->place, from->data, from->size);
}

/* the music's places: the layout's music pieces, by name and by place */
typedef struct
{
	piece **by_name, **by_place;
	size_t count;
} music_names;

static int music_place_of(void *host, const char *text, uint32_t *place)
{
	const music_names *names = host;
	const char *plus = strchr(text, '+');
	const size_t length = plus ? (size_t)(plus - text) : strlen(text);
	char base[256];
	uint32_t offset = 0;
	piece key, *pointer = &key, **found;

	if (length >= sizeof(base))
		return 0;
	if (plus)
	{
		/* +0xNN */
		const char *digits = plus + 3;

		if (plus[1] != '0' || plus[2] != 'x' || !*digits)
			return 0;
		for (const char *at = digits; *at; at++)
			if (!hex_char(*at))
				return 0;
		offset = (uint32_t)strtoul(digits, NULL, 16);
	}
	memcpy(base, text, length);
	base[length] = 0;
	key.name = base;
	found = bsearch(&pointer, names->by_name, names->count, sizeof(piece *), by_name);
	if (!found)
		return 0;
	*place = (*found)->place + offset;
	return 1;
}

static void music_name_of(void *host, uint32_t place, char *text, size_t size)
{
	const music_names *names = host;
	size_t low = 0, high = names->count;

	while (low < high)
	{
		const size_t middle = (low + high) / 2;

		if (names->by_place[middle]->place <= place)
			low = middle + 1;
		else
			high = middle;
	}
	if (low && place < names->by_place[low - 1]->place + names->by_place[low - 1]->length)
	{
		const piece *found = names->by_place[low - 1];

		if (found->place == place)
			snprintf(text, size, "%s", found->name);
		else
			snprintf(text, size, "%s+0x%X", found->name, (unsigned)(place - found->place));
	}
	else
		snprintf(text, size, "%05X", (unsigned)place);
}

/* The music from the songs' MIDI files: every byte of the music pieces, none outside them */
static int read_music(const char *folder, layout *pieces, const game_assets_memory *into)
{
	const piece *lengths_piece = piece_named(pieces, "note_lengths");
	const piece *transpositions_piece = piece_named(pieces, "music_pcm_transpositions");
	music_names names = { NULL, NULL, 0 };
	music_places places;
	uint32_t *lengths = NULL;
	int32_t *transpositions = NULL;
	uint8_t *image = calloc(MUSIC_SPACE, 1), *given = calloc(MUSIC_SPACE, 1), *inside = calloc(MUSIC_SPACE, 1);
	char path[1024];
	const char *problem;
	int ok = 1;

	if (!image || !given || !inside)
		ok = fail("no memory for the music");
	else if (!lengths_piece || !lengths_piece->data || !transpositions_piece || !transpositions_piece->data)
		ok = fail("sound_data: no file gives note_lengths or music_pcm_transpositions");
	if (ok)
	{
		names.by_name = malloc((pieces->count + 1) * sizeof(piece *));
		names.by_place = malloc((pieces->count + 1) * sizeof(piece *));
		lengths = malloc((lengths_piece->size / 2 + 1) * sizeof(*lengths));
		transpositions = malloc((transpositions_piece->size / 2 + 1) * sizeof(*transpositions));
		if (!names.by_name || !names.by_place || !lengths || !transpositions)
			ok = fail("no memory for the music");
	}
	if (ok)
	{
		for (size_t index = 0; index < pieces->count; index++)
			if (!strcmp(pieces->by_place[index]->family, MUSIC_FAMILY))
			{
				names.by_place[names.count] = pieces->by_place[index];
				names.by_name[names.count++] = pieces->by_place[index];
			}
		qsort(names.by_name, names.count, sizeof(piece *), by_name);
		for (size_t index = 0; index < lengths_piece->size / 2; index++)
			lengths[index] = 0x10000u - (uint32_t)(lengths_piece->data[2 * index] | lengths_piece->data[2 * index + 1] << 8);
		for (size_t index = 0; index < transpositions_piece->size / 2; index++)
			transpositions[index] = (int16_t)(transpositions_piece->data[2 * index]
				| transpositions_piece->data[2 * index + 1] << 8);
		places.place_of = music_place_of;
		places.name_of = music_name_of;
		places.host = &names;
		places.lengths = lengths;
		places.length_count = lengths_piece->size / 2;
		places.transpositions = transpositions;
		places.transposition_count = transpositions_piece->size / 2;
		snprintf(path, sizeof(path), "%s/sound_data/music", folder);
		if ((problem = music_read(path, &places, image, given)) != NULL)
			ok = fail("sound_data/music: %s", problem);
	}
	for (size_t index = 0; index < names.count && ok; index++)
	{
		const piece *each = names.by_place[index];
		uint32_t missing = 0, first = 0;

		if (each->place > MUSIC_SPACE || each->length > MUSIC_SPACE - each->place)
		{
			ok = fail("sound_data: %s is past the sound region", each->name);
			break;
		}
		for (uint32_t at = each->place; at < each->place + each->length; at++)
		{
			inside[at] = 1;
			if (!given[at] && missing++ == 0)
				first = at;
		}
		if (missing)
		{
			char name[256];

			music_name_of(&names, first, name, sizeof(name));
			ok = fail("sound data: no MIDI file gives %s (%u bytes of %s)", name, (unsigned)missing, each->name);
		}
		else
			ok = give(into, GAME_ASSETS_SOUND, each->place, image + each->place, each->length);
	}
	for (uint32_t at = 0; at < MUSIC_SPACE && ok; at++)
		if (given[at] && !inside[at])
			ok = fail("sound data: the MIDI files give bytes outside the music, the first at %05X", (unsigned)at);
	free(names.by_name);
	free(names.by_place);
	free(lengths);
	free(transpositions);
	free(image);
	free(given);
	free(inside);
	return ok;
}

static int read_sound_data(const char *folder, const game_assets_memory *into)
{
	layout pieces;
	int ok = read_layout(folder, "sound_data", &pieces)
		&& read_sections(folder, "sound_data", &pieces, (void *)into, sound_line, sound_section)
		&& read_music(folder, &pieces, into);

	free_layout(&pieces);
	return ok;
}

/* ---- the factory EEPROM: eeprom.txt, u8 lines in hex ('#' a comment) ---- */

static int read_eeprom(const char *folder, const game_assets_memory *into)
{
	char *text = read_asset(folder, "eeprom.txt"), *cursor = text, *line;
	uint8_t data[GAME_EEPROM_SIZE];
	size_t count = 0;
	int ok = text != NULL;

	while (ok && (line = next_line(&cursor)) != NULL)
	{
		char *comment = strchr(line, '#'), *at = line, *kind, *item;

		if (comment)
			*comment = 0;
		if (!(kind = next_token(&at)))
			continue;
		if (strcmp(kind, "u8"))
			ok = fail("eeprom.txt: a line no format reads: %s", kind);
		while (ok && (item = next_token(&at)) != NULL)
		{
			uint32_t value;

			if (count >= GAME_EEPROM_SIZE || !hex_number(item, &value) || value > 0xFFu)
				ok = fail("eeprom.txt: %s is no byte of the EEPROM's %d", item, GAME_EEPROM_SIZE);
			else
				data[count++] = (uint8_t)value;
		}
	}
	free(text);
	if (ok && count != GAME_EEPROM_SIZE)
		ok = fail("eeprom.txt gives %u bytes, the EEPROM has %d", (unsigned)count, GAME_EEPROM_SIZE);
	return ok && give(into, GAME_ASSETS_EEPROM, 0, data, count);
}

/* ---- all of them ---- */

const char *game_assets_load_into(const char *folder, const game_assets_memory into[GAME_ASSETS_REGIONS])
{
	g_problem[0] = 0;
	for (int region = 0; region < GAME_ASSETS_REGIONS; region++)
	{
		if (!into[region].memory)
		{
			/* (the programs' data may be kept as pieces only: game_assets_program_at, game_assets_sound_at) */
			if (region != GAME_ASSETS_PROGRAM && region != GAME_ASSETS_SOUND)
				return "a region has no memory to load into";
			continue;
		}
		memset(into[region].memory, 0, REGIONS[region].size);
		if (into[region].given)
			memset(into[region].given, 0, REGIONS[region].size);
	}
	forget_kept(&g_kept[GAME_ASSETS_PROGRAM]);
	forget_kept(&g_kept[GAME_ASSETS_SOUND]);
	if (!read_sheets(folder, "tiles", GAME_ASSETS_TILES, 8, TILE_COLUMNS, TILE_BYTES, into)
		|| !read_sheets(folder, "sprites", GAME_ASSETS_SPRITES, 16, SPRITE_COLUMNS, SPRITE_BYTES, into)
		|| !read_samples(folder, into) || !read_program_data(folder, into) || !read_sound_data(folder, into)
		|| !read_eeprom(folder, into) || !order_kept(&g_kept[GAME_ASSETS_PROGRAM], "data")
		|| !order_kept(&g_kept[GAME_ASSETS_SOUND], "sound_data"))
		return g_problem[0] ? g_problem : "the assets do not load";
	return NULL;
}

const char *game_assets_load(const char *folder)
{
	const game_assets_memory into[GAME_ASSETS_REGIONS] = {
		{ game_program, NULL }, { game_sound, NULL }, { game_tiles, NULL }, { game_sprites, NULL },
		{ game_samples, NULL }, { game_eeprom, NULL } };

	return game_assets_load_into(folder, into);
}
