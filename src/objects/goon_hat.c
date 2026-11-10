/**
 *    Name:        objects/goon_hat.c
 *    Description: the hat a goon with a hat throws
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* When the burst's animation ends, the hat goes away. */
void goon_hat_burst_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Runs the hat's burst after a hit, by its substep. */
uint16_t goon_hat_burst_steps(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		steps = 0x7F2Fu;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			goon_hat_burst(object);
			return steps;
		case 2:
			goon_hat_burst_end(object);
			return steps;
		case 4:
		case 6:
			continue;
		case 8:
			return goon_hat_throw_start(object);
		case 10:
			goon_hat_turn_back(object);
			return steps;
		case 12:
			return goon_hat_return(object, steps);
		case 14:
			break;
		}
		break;
	}
	goon_hat_done();
	return steps;
}

/* Turns the hat into a burst of hit sparks and stops it. */
void goon_hat_burst(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->x_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Gives the hat the priority of the floor under it. */
void goon_hat_floor_priority(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t cell = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell >= 0)
	{
		priority_bits = cell;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFFu) | (((((cell & 0xFu) << 1) << 1) << 1 & 0xFFu) << 8u);
		priority_bits &= 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
	}
}

/* Sets the hat flying fast the way its thrower faces, at the thrower's floor. */
uint16_t goon_hat_throw_start(uint16_t object)
{
	uint16_t setup = 0, thrower = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t parent = 0, floor_z = 0, x_speed = 0;

	setup = goon_hat_throw_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->goon_hat.flight = 0x20u;
	parent = OBJECT(object)->parent;
	thrower = parent;
	floor_z = OBJECT(thrower)->floor_z;
	OBJECT(object)->floor_z = floor_z;
	OBJECT(object)->x_speed = 0x480;
	attributes = OBJECT(thrower)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return thrower;
}

/* Does nothing once the hat's flight has ended. */
void goon_hat_done(void)
{
}

/* After 32 frames turns the hat back towards its thrower. */
void goon_hat_turn_back(uint16_t object)
{
	uint8_t timer = 0, flight = 0, state = 0;
	uint16_t x_speed = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->timer = 0x20u;
	flight = OBJECT(object)->goon_hat.flight;
	if (flight == 0u)
	{
		OBJECT(object)->state = 3u;
		return;
	}
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Flies back; when its time runs out it goes away unless its thrower still throws. */
uint16_t goon_hat_return(uint16_t object, uint16_t thrower)
{
	uint8_t flight = 0, timer = 0, state = 0, state_2 = 0;
	uint16_t parent = 0;

	flight = OBJECT(object)->goon_hat.flight;
	if (flight == 0u)
	{
		OBJECT(object)->state = 3u;
		return thrower;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return thrower;
	parent = OBJECT(object)->parent;
	thrower = parent;
	state = OBJECT(thrower)->state;
	if (state != 4u)
	{
		OBJECT(object)->flags = 0u;
		return thrower;
	}
	state_2 = OBJECT(object)->state;
	OBJECT(object)->state = state_2 + 1u;
	return thrower;
}

/* Ends the hat's flight once its thrower is back at its throwing step. */
uint16_t goon_hat_check_thrower(uint16_t object, uint16_t thrower)
{
	uint8_t flight = 0, state = 0;
	uint16_t parent = 0;

	flight = OBJECT(object)->goon_hat.flight;
	if (flight != 0u)
	{
		parent = OBJECT(object)->parent;
		thrower = parent;
		state = OBJECT(thrower)->state;
		if (state == 4u)
			OBJECT(object)->goon_hat.flight = 0u;
	}
	return thrower;
}
