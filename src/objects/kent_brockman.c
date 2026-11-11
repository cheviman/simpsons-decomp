/**
 *    Name:        objects/kent_brockman.c
 *    Description: stage 7's kind B3 object that takes six hits
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind B3 object, good for six hits. */
uint16_t kent_brockman_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = kent_brockman_setup_ADDRESS;
	vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->kent_brockman.hits_left = 6u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Takes a hit, showing the animation of the hits left; the sixth breaks it for good. */
uint16_t kent_brockman_wait_hit(uint16_t object, uint16_t states)
{
	uint8_t hits_left = 0, hits_left_2 = 0, state = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
		return states;
	hits_left = OBJECT(object)->kent_brockman.hits_left;
	OBJECT(object)->kent_brockman.hits_left = hits_left - 1u;
	if (hits_left == 1u)
	{
		OBJECT(object)->animation = 0x83u;
		OBJECT(object)->state = 4u;
		return states;
	}
	states = kent_brockman_damage_animations_ADDRESS;
	hits_left_2 = OBJECT(object)->kent_brockman.hits_left;
	OBJECT(object)->animation = kent_brockman_damage_animations[(int8_t)hits_left_2];
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return states;
}

/* After 32 frames goes back to its standing animation. */
void kent_brockman_hit_end(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After 64 frames waits for the next hit. */
void kent_brockman_rest(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		kent_brockman_broken();
		return;
	}
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->state = 1u;
	kent_brockman_broken();
}

/* Does nothing once broken. */
void kent_brockman_broken(void)
{
}
