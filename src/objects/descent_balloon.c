/**
 *    Name:        objects/descent_balloon.c
 *    Description: the balloon a descending fat goon lets go of
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the balloon, hidden until the fat goon lets it go. */
uint16_t descent_balloon_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = descent_balloon_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 4u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	descent_balloon_wait();
	return setup;
}

/* Does nothing while the fat goon holds the balloon. */
void descent_balloon_wait(void)
{
}

/* Shows the balloon over the fat goon's place and starts it rising. */
uint16_t descent_balloon_release(uint16_t object)
{
	uint16_t carrier = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0;
	uint16_t parent = 0, carrier_x = 0, carrier_y = 0, z = 0, balloon_z = 0;

	OBJECT(object)->flags = 0x88u;
	parent = OBJECT(object)->parent;
	carrier = parent;
	attributes = OBJECT(carrier)->attributes;
	priority_bits = attributes & 0x30u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | priority_bits;
	carrier_x = OBJECT(carrier)->x;
	OBJECT(object)->x = carrier_x;
	carrier_y = OBJECT(carrier)->y;
	OBJECT(object)->y = carrier_y;
	z = OBJECT(carrier)->z;
	balloon_z = z + 0x3Cu;
	OBJECT(object)->z = balloon_z;
	OBJECT(object)->z_speed = 0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return carrier;
}

/* Rises ever faster, gone once high enough. */
void descent_balloon_fly_away(uint16_t object)
{
	uint16_t z_speed = 0, z = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed + 4u;
	z = OBJECT(object)->z;
	if (z >= 0xF0u)
		OBJECT(object)->flags = 0u;
}
