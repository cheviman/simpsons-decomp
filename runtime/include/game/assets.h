/**
 *    Name:        assets.h
 *    Description: the game's assets (tools/extract_assets.py writes them from the player's ROM set) loaded back
 *                 into the board's memories
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    What the game reads at start instead of the ROM set (runtime/src/assets.c): the tiles and the sprites (PNG
 *    sheets) into the video chips' memories, as the chips read them; the samples (WAV) into the K053260's; and
 *    the data of both programs (text pieces by name, the sound program's music from the songs' MIDI files), kept
 *    as its pieces by the places the programs know them by; and the factory EEPROM (eeprom.txt). The programs'
 *    code is not in the assets (it is C): no piece is there (but the code the 053248's map engines read as tiles,
 *    which the data gives too).
 *    The data's 'record' lines are by the structures data/structures.txt gives (their values' types): the
 *    assets read back on their own.
 */
#ifndef GAME_ASSETS_H
#define GAME_ASSETS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The board's memories the assets fill (game/data.h's regions) */
typedef enum
{
	GAME_ASSETS_PROGRAM,        /* game_program: the 053248 program's data */
	GAME_ASSETS_SOUND,          /* game_sound: the Z80 program's data and music */
	GAME_ASSETS_TILES,          /* game_tiles: the K052109's tiles */
	GAME_ASSETS_SPRITES,        /* game_sprites: the K053246's sprite cells */
	GAME_ASSETS_SAMPLES,        /* game_samples: the K053260's samples */
	GAME_ASSETS_EEPROM,         /* game_eeprom: the ER5911's contents as the board leaves the factory */
	GAME_ASSETS_REGIONS
} game_assets_region;

/* Where a region's bytes go: 'memory', the region's size (game_assets_size), and 'given', the same size or
   NULL: a 1 at every byte an asset gives. The programs' data (GAME_ASSETS_PROGRAM, GAME_ASSETS_SOUND) may have no
   memory: the game keeps it as its pieces only (game_assets_program_at, game_assets_sound_at), never in an image of
   the ROM's regions; the tools that check the assets against the ROM set ask for the regions */
typedef struct
{
	uint8_t *memory;
	uint8_t *given;
} game_assets_memory;

/* A region's size (GAME_*_SIZE) and its name */
size_t game_assets_size(game_assets_region region);
const char *game_assets_name(game_assets_region region);

/* The assets under 'folder' (assets/) into 'into' (each region cleared first): NULL, or what is wrong */
const char *game_assets_load_into(const char *folder, const game_assets_memory into[GAME_ASSETS_REGIONS]);

/* The same into game/data.h's regions (game_program, game_sound, game_tiles, game_sprites, game_samples,
   game_eeprom) */
const char *game_assets_load(const char *folder);

/* The programs' data the last load gave, by the place a program knows it by (its region's offset: the 053248's
   000000-07FFFF, a bank's window resolved; the Z80's 00000-27FFF): the byte's piece from there on, or NULL where the
   assets give nothing (the program's code) */
const uint8_t *game_assets_program_at(uint32_t place);
const uint8_t *game_assets_sound_at(uint32_t place);

#ifdef __cplusplus
}
#endif

#endif
