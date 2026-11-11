/**
 *    Name:        objects/speech_balloon.c
 *    Description: a speech balloon that follows its speaker
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* A speech balloon: puts it above its speaker and goes along with it. */
uint16_t speech_balloon_start(uint16_t object)
{
	uint16_t speaker = 0;
	uint8_t state = 0;
	uint16_t speaker_2 = 0, speaker_x = 0, speaker_y = 0, z = 0, x_speed = 0, y_speed = 0;

	OBJECT(object)->flags = 0x80u;
	speaker_2 = OBJECT(object)->speech_balloon.speaker;
	speaker = speaker_2;
	speaker_x = OBJECT(speaker)->x;
	OBJECT(object)->x = speaker_x - 0x20u;
	speaker_y = OBJECT(speaker)->y;
	OBJECT(object)->y = speaker_y - 2u;
	z = OBJECT(speaker)->z;
	OBJECT(object)->z = z + 0x6Cu;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	x_speed = OBJECT(speaker)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = OBJECT(speaker)->y_speed;
	OBJECT(object)->y_speed = y_speed;
	return speaker;
}

/* A speech balloon: moves with its speaker until its time (field 28) runs out. */
uint16_t speech_balloon_follow(uint16_t object)
{
	uint16_t speaker = 0;
	uint8_t time = 0;
	uint16_t speaker_2 = 0, x_speed = 0, y_speed = 0;

	speaker_2 = OBJECT(object)->speech_balloon.speaker;
	speaker = speaker_2;
	time = OBJECT(object)->speech_balloon.time;
	OBJECT(object)->speech_balloon.time = time - 1u;
	if (time != 1u)
	{
		x_speed = OBJECT(speaker)->x_speed;
		OBJECT(object)->x_speed = x_speed;
		y_speed = OBJECT(speaker)->y_speed;
		OBJECT(object)->y_speed = y_speed;
		return speaker;
	}
	OBJECT(object)->flags = 0u;
	return speaker;
}
