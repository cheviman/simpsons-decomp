/**
 *    Name:        tables.c
 *    Description: the tables the sound program reads by name, which the board sets, and the registers it keeps
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

/* registers the whole program keeps */
uint16_t program_rom_sum;
uint16_t sample_rom_1_sum;
uint16_t sample_rom_2_sum;
uint8_t self_test_failures;

const void *carrier_masks_data;
const void *note_codes_data;
const void *effect_handlers_data;
const void *effect_priorities_data;
const void *unused_effect_handlers_by_sound_data;
const void *unused_effect_priorities_by_sound_data;
const void *effect_handlers_2_data;
const void *effect_priorities_2_data;
const void *effect_handlers_40_by_sound_data;
const void *effect_priorities_40_by_sound_data;
const void *note_lengths_data;
const void *song_banks_by_sound_data;
const void *music_pcm_transpositions_data;

/* the tables the game loads from its assets: their names, addresses and pointers */
const sound_table sound_tables[] =
{
	{ "carrier_masks", 0x0DB8u, &carrier_masks_data },
	{ "note_codes", 0x0E10u, &note_codes_data },
	{ "effect_handlers", 0x1016u, &effect_handlers_data },
	{ "effect_priorities", 0x1086u, &effect_priorities_data },
	{ "unused_effect_handlers_by_sound", 0x26FCu, &unused_effect_handlers_by_sound_data },
	{ "unused_effect_priorities_by_sound", 0x2740u, &unused_effect_priorities_by_sound_data },
	{ "effect_handlers_2", 0x2E01u, &effect_handlers_2_data },
	{ "effect_priorities_2", 0x2E79u, &effect_priorities_2_data },
	{ "effect_handlers_40_by_sound", 0x3570u, &effect_handlers_40_by_sound_data },
	{ "effect_priorities_40_by_sound", 0x3630u, &effect_priorities_40_by_sound_data },
	{ "note_lengths", 0x48FAu, &note_lengths_data },
	{ "song_banks_by_sound", 0x5D92u, &song_banks_by_sound_data },
	{ "music_pcm_transpositions", 0x642Cu, &music_pcm_transpositions_data },
};

const size_t sound_table_count = 13;
