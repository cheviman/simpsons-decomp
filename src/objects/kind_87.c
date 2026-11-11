/**
 *    Name:        objects/kind_87.c
 *    Description: the kind 87 character of stage 1 and its device
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the device. */
uint16_t kind_87_device_start(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t state = 0;

	setup = kind_87_device_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attributes = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return setup;
}

/* Checks every 16 frames whether a player hit the device, and then calls its keeper over. */
uint16_t kind_87_device_wait_hit(uint16_t object, uint16_t states)
{
	uint16_t keeper = 0;
	uint8_t state = 0;
	uint16_t keeper_2 = 0;

	if ((frame_count & 0xFu) != 0u || (OBJECT(object)->flags & 0x20u) == 0u)
	{
		kind_87_device_idle();
		return states;
	}
	keeper_2 = OBJECT(object)->kind_87_device.keeper;
	keeper = keeper_2;
	OBJECT(keeper)->state = 3u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_87_device_idle();
	return keeper;
}

/* Does nothing. */
void kind_87_device_idle(void)
{
}

/* Worked by its keeper: strikes (sound 6000), harder every other time. */
void kind_87_device_strike(uint16_t object)
{
	uint16_t command = 0;
	uint8_t strike_frames = 0, strike_frames_2 = 0, state = 0;

	leftover_y = kind_87_device_strike_box_ADDRESS;
	vector_set_hit_box(object);
	strike_frames = OBJECT(object)->kind_87_device.strike_frames;
	OBJECT(object)->kind_87_device.strike_frames = strike_frames - 1u;
	strike_frames_2 = OBJECT(object)->kind_87_device.strike_frames;
	if (strike_frames_2 & 1u)
		OBJECT(object)->attack = 8u;
	command = 0x6000u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x87u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* When the strike's animation ends, takes its standing hit box back. */
void kind_87_device_strike_end(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	leftover_y = kind_87_body_box_ADDRESS;
	vector_set_hit_box(object);
	OBJECT(object)->timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After 32 frames, starts its reset animation. */
void kind_87_device_reset(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->animation = 0x88u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When the reset ends, waits 64 frames. */
void kind_87_device_reset_end(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->timer = 0x40u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After its rest, waits for the next hit. */
void kind_87_device_rest(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->state = 1u;
}

/* Sets up the kind 87 character with its device, walking in from the right edge. */
uint16_t kind_87_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t device = 0, ignored16 = 0, ignored16_2 = 0, setup = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t screen_x = 0, world_x = 0, home_place = 0, old_y = 0, new_y = 0;

	setup = kind_87_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	screen_x = OBJECT(object)->x;
	world_x = screen_x + camera_x;
	home_place = world_x - 0x30u;
	OBJECT(object)->kind_87.home_x = home_place;
	leftover_y = kind_87_child_ADDRESS;
	vector_spawn_child(object, &ignored16, &device, &ignored16_2, &carry);
	OBJECT(object)->kind_87.device = device;
	OBJECT(object)->x = 0x18Eu;
	old_y = OBJECT(object)->y;
	new_y = old_y - 6u;
	OBJECT(object)->y = new_y;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return device;
}

/* After 64 frames stops. */
void kind_87_stop(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x20u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After a random wait, walks a random way, or back towards its home. */
void kind_87_wander(uint16_t object)
{
	uint8_t timer = 0, blocked = 0, state = 0;
	uint16_t x_speed = 0, screen_x = 0, world_x = 0, home_x = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->timer = (random_number & 0x3Fu) + 0x10u;
	blocked = OBJECT(object)->blocked;
	if (blocked == 0u)
	{
		OBJECT(object)->x_speed = -0x100;
		if ((int8_t)random_number >= 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
	{
		screen_x = OBJECT(object)->x;
		world_x = screen_x + camera_x;
		home_x = OBJECT(object)->kind_87.home_x;
		if (home_x <= world_x)
			OBJECT(object)->x_speed = -0x100;
		else
			OBJECT(object)->x_speed = 0x100;
	}
	OBJECT(object)->animation = 0x81u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
	face_movement(object);
}

/* Runs to its device. */
uint16_t kind_87_run_to_device(uint16_t object)
{
	uint16_t device = 0;
	uint8_t blocked = 0, state = 0;
	uint16_t device_2 = 0, own_x = 0, device_x = 0, x_speed = 0;

	OBJECT(object)->x_speed = 0x400;
	device_2 = OBJECT(object)->kind_87.device;
	device = device_2;
	own_x = OBJECT(object)->x;
	device_x = OBJECT(device)->x;
	if (device_x <= own_x)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
		blocked = OBJECT(object)->blocked;
		OBJECT(object)->blocked = blocked + 1u;
	}
	OBJECT(object)->animation = 0x81u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return device;
}

/* At the device, steps behind it and works it. */
uint16_t kind_87_reach_device(uint16_t object)
{
	uint16_t device = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t device_2 = 0, own_x = 0, device_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, device_3 = 0;

	device_2 = OBJECT(object)->kind_87.device;
	device = device_2;
	own_x = OBJECT(object)->x;
	device_x = OBJECT(device)->x;
	x_difference = own_x - device_x;
	signed_x_difference = x_difference;
	x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
	if (x_distance < 4u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->timer = 8u;
		device_3 = OBJECT(object)->kind_87.device;
		device = device_3;
		OBJECT(device)->state = 3u;
		OBJECT(object)->animation = 0x81u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	return device;
}

/* Stands behind the device for 32 frames. */
void kind_87_behind_device(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 0x20u;
		OBJECT(object)->animation = 0x80u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Steps back out from behind the device. */
void kind_87_come_back(uint16_t object)
{
	uint8_t timer = 0, attributes = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0x100;
		OBJECT(object)->timer = 8u;
		OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Back in front of the device: wanders again. */
void kind_87_back(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->state = 1u;
		OBJECT(object)->timer = 1u;
	}
}
