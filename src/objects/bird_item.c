/**
 *    Name:        objects/bird_item.c
 *    Description: the bird that rises, flutters and turns into an object to pick up
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the bird up under the floor, rising. */
uint16_t bird_item_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = bird_item_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->z = 0xFF80u;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->z_speed = 0xC0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Rises until 0070 over the floor. */
void bird_item_rise(uint16_t object)
{
	uint16_t height = 0;
	uint8_t state = 0;
	uint16_t z = 0;

	z = OBJECT(object)->z;
	height = z;
	if ((int16_t)z >= 0 && height >= 0x70u)
	{
		OBJECT(object)->z_speed = -0x100;
		OBJECT(object)->timer = 0x30u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Flutters in place for 48 frames, then flies up the screen. */
void bird_item_flutter(uint16_t object)
{
	uint8_t timer = 0, state = 0;
	uint16_t z_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		z_speed = OBJECT(object)->z_speed;
		OBJECT(object)->z_speed = 0u - z_speed;
		return;
	}
	OBJECT(object)->attributes = 0x10u;
	OBJECT(object)->y_speed = -0x100;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->floor_z = 0x50u;
	OBJECT(object)->animation = 0x81u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Comes down as a kind 05 object (animation 8C) lying as a throwable (list 1 type 01). */
void bird_item_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->kind = 5u;
		OBJECT(object)->animation = 0x8Cu;
		OBJECT(object)->type = 1;
		OBJECT(object)->state = 2u;
		OBJECT(object)->blocked = 1u;
		OBJECT(object)->carried = 0u;
	}
}
