/**
 *    Name:        rom_set.c
 *    Description: the player's ROM set into the board's memory (game/data.h), from a .zip or a folder
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Each of the set's 14 files is known by its CRC32: in a .zip by its own, whatever its name (stored or
 *    deflated: inflate.c); in a folder by MAME's name, or in the folder's simpsons.zip. The regions are laid
 *    out after ROM_START( simpsons ) in MAME's src/mame/konami/simpsons.cpp (BSD-3-Clause), as
 *    tools/simpsons_rom.py lays them out. The reference runs the original code, so it reads the set when it
 *    starts, as MAME does.
 */
#include "game/extract.h"

#include "game/data.h"
#include "inflate.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZIP_END             0x06054B50u    /* the end of the central directory */
#define ZIP_ENTRY           0x02014B50u    /* a central directory entry */
#define ZIP_LOCAL           0x04034B50u    /* a local header */
#define ZIP_STORED          0
#define ZIP_DEFLATED        8
#define ZIP_COMMENT_MOST    0xFFFFu
#define SET_ZIP             "simpsons.zip"    /* MAME's name for the set's .zip */

typedef struct
{
	const char *name;
	uint32_t crc, size;
} rom_file;

enum
{
	G02, G01, J13, J12, E03, B07, B06, B08, B09, B10, B11, D05, D04, NV, FILES
};

static const rom_file files[FILES] = {
	{ "072-g02.16c", 0x580ce1d6u, 0x020000u },
	{ "072-g01.17c", 0x9f843defu, 0x020000u },
	{ "072-j13.13c", 0xaade2abdu, 0x020000u },
	{ "072-j12.15c", 0x479e12f2u, 0x020000u },
	{ "072-e03.6g", 0x866b7a35u, 0x020000u },
	{ "072-b07.18h", 0xba1ec910u, 0x080000u },
	{ "072-b06.16h", 0xcf2bbcabu, 0x080000u },
	{ "072-b08.3n", 0x7de500adu, 0x100000u },
	{ "072-b09.8n", 0xaa085093u, 0x100000u },
	{ "072-b10.12n", 0x577dbd53u, 0x100000u },
	{ "072-b11.16l", 0x55fab05du, 0x100000u },
	{ "072-d05.1f", 0x1397a73bu, 0x100000u },
	{ "072-d04.1d", 0x78778013u, 0x040000u },
	{ "simpsons.12c.nv", 0xec3f0449u, 0x000080u },
};

static uint32_t crc32_of(const uint8_t *data, uint32_t size)
{
	static uint32_t table[256];
	uint32_t crc = 0xFFFFFFFFu, index;
	int bit;

	if (table[1] == 0u)
		for (index = 0; index < 256u; index++)
		{
			table[index] = index;
			for (bit = 0; bit < 8; bit++)
				table[index] = (table[index] >> 1) ^ (0xEDB88320u & (0u - (table[index] & 1u)));
		}
	for (index = 0; index < size; index++)
		crc = (crc >> 8) ^ table[(crc ^ data[index]) & 0xFFu];
	return ~crc;
}

static uint32_t little16(const uint8_t *bytes)
{
	return (uint32_t)bytes[0] | (uint32_t)bytes[1] << 8;
}

static uint32_t little32(const uint8_t *bytes)
{
	return little16(bytes) | little16(bytes + 2) << 16;
}

/* A whole file into memory (the caller frees it), or NULL */
static uint8_t *read_whole(const char *path, size_t *size)
{
	FILE *input = fopen(path, "rb");
	uint8_t *data = NULL;
	long length;

	if (!input)
		return NULL;
	if (fseek(input, 0, SEEK_END) == 0 && (length = ftell(input)) > 0 && fseek(input, 0, SEEK_SET) == 0
		&& (data = malloc((size_t)length)) != NULL && fread(data, 1, (size_t)length, input) != (size_t)length)
	{
		free(data);
		data = NULL;
	}
	fclose(input);
	if (data)
		*size = (size_t)length;
	return data;
}

/* The set's files in the .zip 'zip' ('size' bytes) into 'chips', by their CRC32: 0 when it is no .zip */
static int read_zip(const uint8_t *zip, size_t size, uint8_t **chips)
{
	size_t end, entry, local;
	uint32_t entries, index;
	int file;

	if (size < 22)
		return 0;
	for (end = size - 22;; end--)
	{
		if (little32(zip + end) == ZIP_END)
			break;
		if (end == 0 || size - end > 22 + ZIP_COMMENT_MOST)
			return 0;
	}
	entries = little16(zip + end + 10);
	entry = little32(zip + end + 16);
	for (index = 0; index < entries; index++)
	{
		uint32_t method, crc, packed, unpacked;

		if (entry > size || size - entry < 46 || little32(zip + entry) != ZIP_ENTRY)
			return 0;
		method = little16(zip + entry + 10);
		crc = little32(zip + entry + 16);
		packed = little32(zip + entry + 20);
		unpacked = little32(zip + entry + 24);
		local = little32(zip + entry + 42);
		entry += 46 + little16(zip + entry + 28) + little16(zip + entry + 30) + little16(zip + entry + 32);
		for (file = 0; file < FILES; file++)
			if (!chips[file] && files[file].crc == crc && files[file].size == unpacked)
				break;
		if (file == FILES || local > size || size - local < 30 || little32(zip + local) != ZIP_LOCAL)
			continue;
		local += 30 + little16(zip + local + 26) + little16(zip + local + 28);
		if (local > size || packed > size - local || (method == ZIP_STORED && packed != unpacked)
			|| !(chips[file] = malloc(unpacked)))
			continue;    /* (what the entry says does not fit the file) */
		if ((method == ZIP_STORED ? (memcpy(chips[file], zip + local, unpacked), 1)
				: method == ZIP_DEFLATED && inflate_raw(zip + local, packed, chips[file], unpacked))
			&& crc32_of(chips[file], unpacked) == crc)
			continue;
		free(chips[file]);
		chips[file] = NULL;
	}
	return 1;
}

/* The set's files in the folder 'folder' into 'chips', by their MAME names and their CRC32 */
static void read_folder(const char *folder, uint8_t **chips)
{
	char path[1024];
	int file;

	for (file = 0; file < FILES; file++)
	{
		size_t size = 0;

		snprintf(path, sizeof(path), "%s/%s", folder, files[file].name);
		chips[file] = read_whole(path, &size);
		if (chips[file] && (size != files[file].size || crc32_of(chips[file], files[file].size) != files[file].crc))
		{
			free(chips[file]);
			chips[file] = NULL;
		}
	}
}

/* ROM_LOAD32_WORD / ROM_LOAD64_WORD: every group of 2 x 'lanes' bytes takes a 16-bit word of each chip, in
   the order given; 'size' is a chip's */
static void interleave_words(uint8_t *out, uint8_t *const *chips, int lanes, uint32_t size)
{
	uint32_t word;
	int lane;

	for (word = 0; word < size / 2u; word++)
		for (lane = 0; lane < lanes; lane++)
		{
			out[(word * (uint32_t)lanes + (uint32_t)lane) * 2u] = chips[lane][word * 2u];
			out[(word * (uint32_t)lanes + (uint32_t)lane) * 2u + 1u] = chips[lane][word * 2u + 1u];
		}
}

const char *game_rom_set_load(const char *source)
{
	static char problem[96];
	uint8_t *chips[FILES] = { NULL };
	size_t size = 0;
	uint8_t *whole = read_whole(source, &size);
	int file;

	if (whole)
	{
		const int zip = read_zip(whole, size, chips);

		free(whole);
		if (!zip)
			return "not a .zip";
	}
	else
	{
		char zip_path[1024];

		read_folder(source, chips);
		/* (a folder that holds the set's .zip, as MAME keeps it) */
		snprintf(zip_path, sizeof(zip_path), "%s/" SET_ZIP, source);
		if ((whole = read_whole(zip_path, &size)) != NULL)
		{
			read_zip(whole, size, chips);
			free(whole);
		}
	}
	problem[0] = '\0';
	for (file = 0; file < FILES && !problem[0]; file++)
		if (!chips[file])
			snprintf(problem, sizeof(problem), "no %s (or not this version of it)", files[file].name);
	if (!problem[0])
	{
		uint8_t *const tiles[2] = { chips[B07], chips[B06] };
		uint8_t *const sprites[4] = { chips[B08], chips[B09], chips[B10], chips[B11] };

		memcpy(game_program, chips[G02], 0x20000u);
		memcpy(game_program + 0x20000u, chips[G01], 0x20000u);
		memcpy(game_program + 0x40000u, chips[J13], 0x20000u);
		memcpy(game_program + 0x60000u, chips[J12], 0x20000u);
		/* the Z80's: its first 32 KB at 0000, the rest at 10000 (ROM_CONTINUE) */
		memset(game_sound, 0, GAME_SOUND_SIZE);
		memcpy(game_sound, chips[E03], 0x8000u);
		memcpy(game_sound + 0x10000u, chips[E03] + 0x8000u, 0x18000u);
		interleave_words(game_tiles, tiles, 2, 0x80000u);
		interleave_words(game_sprites, sprites, 4, 0x100000u);
		memcpy(game_samples, chips[D05], 0x100000u);
		memcpy(game_samples + 0x100000u, chips[D04], 0x40000u);
		memcpy(game_eeprom, chips[NV], GAME_EEPROM_SIZE);
	}
	for (file = 0; file < FILES; file++)
		free(chips[file]);
	return problem[0] ? problem : NULL;
}
