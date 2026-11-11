/**
 *    Name:        objects/fireman_goon.c
 *    Description: stage 1's kind 90 enemy that throws, and what it throws
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the hidden kind 90 enemy, out of play: its x and facing, its wait and its throws by its
   spawn's state. */
void fireman_goon_setup(uint16_t object)
{
	uint8_t attributes = 0, start_x_high = 0, start_x_low = 0;
	uint16_t fireman_goon_start = 0, setup = 0;
	uint8_t attributes_2 = 0, parameter = 0, attributes_3 = 0, attributes_4 = 0, state = 0;
	uint16_t old_y = 0, new_y = 0, entry_x = 0, wait = 0;

	setup = fireman_goon_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	old_y = OBJECT(object)->y;
	new_y = old_y + 2u;
	OBJECT(object)->y = new_y;
	OBJECT(object)->floor_z = 0u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | 0x20u;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->flags = 4u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->fireman_goon.vanishes = 1u;
	OBJECT(object)->behaviour = 0x7BEFu;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	fireman_goon_start = fireman_goon_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	entry_x = FIREMAN_GOON_START(fireman_goon_start)->x;
	start_x_low = (uint8_t)entry_x;
	start_x_high = (uint8_t)(entry_x >> 8);
	OBJECT(object)->fireman_goon.start_x = ((uint32_t)start_x_high << 8) | (start_x_low & 0xFFu);
	if ((uint16_t)(((uint32_t)start_x_high << 8) | (start_x_low & 0xFFu)) >= 0x100u)
	{
		attributes_3 = OBJECT(object)->attributes;
		attributes = attributes_3 | 0x40u;
	}
	else
	{
		attributes_4 = OBJECT(object)->attributes;
		attributes = attributes_4 & 0xBFu;
	}
	OBJECT(object)->attributes = attributes;
	wait = (((uint32_t)FIREMAN_GOON_START(fireman_goon_start)->wait << 8u) | FIREMAN_GOON_START(fireman_goon_start)->throws);
	OBJECT(object)->timer = (uint8_t)(wait >> 8u);
	OBJECT(object)->fireman_goon.throws_left = (uint8_t)wait;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Runs the kind 90 enemy's entrance by its substep. */
void fireman_goon_entrance_steps(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		fireman_goon_wait_camera(object, 0u);
		return;
	case 2:
		fireman_goon_walk_out(object);
		return;
	case 4:
		fireman_goon_find_floor(object);
		return;
	case 6:
		fireman_goon_land(object);
		return;
	case 8:
		fireman_goon_throw_wind_up(object);
		return;
	case 10:
		fireman_goon_throw(object, 0u);
		return;
	case 12:
		fireman_goon_throw_end(object);
		return;
	}
}

/* Waits for the camera to reach 03D0, then shows the enemy in play facing the nearest player. */
uint16_t fireman_goon_wait_camera(uint16_t object, uint16_t target)
{
	uint8_t action_step = 0;
	uint16_t camera_position = 0;

	camera_position = camera_x;
	if (camera_position < 0x3D0u)
		return target;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->entrance_pending = 0u;
	target = vector_choose_nearest_player(object);
	vector_measure_target(object, target);
	OBJECT(object)->animation = 0x86u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return target;
}

/* After its wait, walks out diagonally (direction E0, speed 40). */
void fireman_goon_walk_out(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t timer = 0, attributes = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->enemy_class = 0;
	heading = 0xE040u;
	vector_set_speed_by_direction(object, heading);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->animation = 0x82u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Walks until there is floor under it. */
void fireman_goon_find_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint16_t floor_cell = 0;
	uint8_t action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	if ((int8_t)(floor_cell >> 8) >= 0)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Lands on the floor and starts fighting. */
void fireman_goon_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the throwing animation. */
void fireman_goon_throw_wind_up(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When the animation ends, throws (sound 6100): always from difficulty 3, else three times out of four. */
uint16_t fireman_goon_throw(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, action_step = 0, throws_left = 0, throws_left_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return u;
	if (difficulty >= 3u)
	{
		fireman_goon_put_in_missile(object, &u, &carry);
		if (carry == 0u)
		{
			fireman_goon_throw_end(object);
			return u;
		}
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		command = 0x6100u;
		vector_queue_sound(command);
		return u;
	}
	throws_left = OBJECT(object)->fireman_goon.throws_left;
	OBJECT(object)->fireman_goon.throws_left = throws_left - 1u;
	throws_left_2 = OBJECT(object)->fireman_goon.throws_left;
	if ((throws_left_2 & 3u) == 0u)
	{
		fireman_goon_throw_end(object);
		return u;
	}
	fireman_goon_put_in_missile(object, &u, &carry);
	if (carry == 0u)
	{
		fireman_goon_throw_end(object);
		return u;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6100u;
	vector_queue_sound(command);
	return u;
}

/* Ends the throw and goes back to the fight. */
void fireman_goon_throw_end(uint16_t object)
{
	OBJECT(object)->animation = 0x81u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Puts in what the kind 90 enemy throws. */
void fireman_goon_put_in_missile(uint16_t object, uint16_t *p_object_2, uint32_t *p_child_placed)
{
	uint32_t child_placed = *p_child_placed;
	uint16_t child_object = 0, ignored16 = 0, object_3 = 0;
	uint8_t attributes = 0, attributes_2 = 0;
	uint16_t parent = 0;

	leftover_y = fireman_goon_put_in_missile_child_ADDRESS;
	child_object = fireman_goon_put_in_missile_child_ADDRESS;
	spawn_list_2_child(object, child_object, &ignored16, &child_placed);
	parent = OBJECT(object)->parent;
	object_3 = parent;
	attributes = OBJECT(object_3)->attributes;
	priority_bits = attributes & 0x30u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | priority_bits;
	*p_object_2 = object_3;
	*p_child_placed = child_placed;
}

/* Sets up the thrown thing at its thrower's priority. */
uint16_t fireman_goon_missile_start(uint16_t object)
{
	uint16_t setup = 0, thrower = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0;
	uint16_t parent = 0;

	setup = fireman_goon_missile_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parent = OBJECT(object)->parent;
	thrower = parent;
	attributes = OBJECT(thrower)->attributes;
	priority_bits = attributes & 0x70u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0x8Fu) | priority_bits;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return thrower;
}

/* At its animation's mark, starts hitting. */
void fireman_goon_missile_fly(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Stops hitting and waits for its animation's end. */
void fireman_goon_missile_spent(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	fireman_goon_missile_end(object);
}

/* Goes away when its animation ends. */
void fireman_goon_missile_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}
