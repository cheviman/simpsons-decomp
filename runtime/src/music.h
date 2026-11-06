/**
 *    Name:        music.h
 *    Description: the songs' Standard MIDI Files back into the sound program's music (runtime/src/music.c)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The way back of tools/sound_music.py: the songs' headers and tracks, and the tracks' bytes no song plays,
 *    by their places in the sound region (game/data.h's game_sound: 0000-7FFF the Z80's fixed program,
 *    10000-27FFF its banks).
 */
#ifndef GAME_MUSIC_H
#define GAME_MUSIC_H

#include <stddef.h>
#include <stdint.h>

/* the sound region's places */
#define MUSIC_SPACE 0x28000u

/* What the way back needs of the other assets: the music's places by name (the layout's music pieces),
   note_lengths' units and music_pcm_transpositions' bytes */
typedef struct
{
	int (*place_of)(void *host, const char *name, uint32_t *place);         /* NAME or NAME+0xNN; 0: none */
	void (*name_of)(void *host, uint32_t place, char *text, size_t size);   /* a place's name, for what fails */
	void *host;
	const uint32_t *lengths;            /* the units of each length's code */
	size_t length_count;
	const int32_t *transpositions;      /* each PCM instrument's, in the pitch table's bytes */
	size_t transposition_count;
} music_places;

/* The songs' MIDI files that 'folder'/music.txt lists, back into the music's bytes: 'image' and 'given'
   (MUSIC_SPACE each, by place) take them; NULL, or what failed */
const char *music_read(const char *folder, const music_places *places, uint8_t *image, uint8_t *given);

#endif
