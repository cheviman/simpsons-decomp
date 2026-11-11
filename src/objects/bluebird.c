/**
 *    Name:        objects/bluebird.c
 *    Description: the small kind A0 creature that comes in or is launched from the shaking scenery
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the creature up by its spawn's state: coming in, sitting still, or hidden on the shaking scenery. */
uint16_t bluebird_start(uint16_t object)
{
	uint8_t parameter_low = 0, spawn_parameter = 0;
	uint16_t bluebird_entry = 0, u = 0;
	uint8_t attributes = 0, parameter = 0, parameter_2 = 0, frames = 0, state = 0, masked_parameter = 0;
	uint16_t z_speed = 0, x_speed = 0, entry_x = 0;

	u = bluebird_setup_ADDRESS;
	vector_object_setup(object, u);
	OBJECT(object)->shadow_player = 2u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	parameter = OBJECT(object)->parameter;
	spawn_parameter = parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->flags = 0x88u;
		parameter_2 = OBJECT(object)->parameter;
		bluebird_entry = bluebird_entries_ADDRESS + (int8_t)((((uint32_t)parameter_2 << 1) << 1) << 1);
		z_speed = BLUEBIRD_ENTRY(bluebird_entry)->z_speed;
		OBJECT(object)->z_speed = z_speed;
		x_speed = BLUEBIRD_ENTRY(bluebird_entry)->x_speed;
		OBJECT(object)->x_speed = x_speed;
		entry_x = BLUEBIRD_ENTRY(bluebird_entry)->x;
		OBJECT(object)->x = entry_x;
		frames = BLUEBIRD_ENTRY(bluebird_entry)->frames;
		OBJECT(object)->timer = frames;
		bluebird_take_floor(object);
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		face_movement(object);
		return bluebird_entry;
	}
	masked_parameter = spawn_parameter & 0x7Fu;
	parameter_low = masked_parameter;
	if (masked_parameter == 0u)
	{
		OBJECT(object)->animation = 0x83u;
		OBJECT(object)->state = 3u;
		return u;
	}
	OBJECT(object)->parameter = parameter_low - 1u;
	OBJECT(object)->flags = 4u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->state = 8u;
	return u;
}

/* Moves in for its frames, then stops moving across. */
void bluebird_enter(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		bluebird_take_floor(object);
		return;
	}
	OBJECT(object)->x_speed = 0;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	bluebird_take_floor(object);
}

/* Takes the height of the floor under it. */
void bluebird_take_floor(uint16_t object)
{
	uint32_t no_floor = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &no_floor);
	floor_value = (uint8_t)(floor_cell >> 8);
	if (no_floor == 0u)
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
}

/* Falls and, on landing, sits. */
void bluebird_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t z_speed = 0, new_z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	new_z_speed = z_speed - 0x20u;
	OBJECT(object)->z_speed = new_z_speed;
	landed = vector_check_landing(object);
	if (landed)
	{
		OBJECT(object)->animation = 0x81u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->timer = 0x80u;
		OBJECT(object)->state = 4u;
	}
}

/* Sits, looking round, until it is hit; then jumps. */
void bluebird_sit(uint16_t object)
{
	uint8_t animation = 0, attributes = 0;
	uint16_t screen_x = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		screen_x = OBJECT(object)->x;
		if (screen_x >= 0xE0u)
		{
			if ((frame_count & 0x3Fu) == 0u)
			{
				animation = OBJECT(object)->animation;
				OBJECT(object)->animation = (animation ^ 2u) | 0x80u;
				attributes = OBJECT(object)->attributes;
				OBJECT(object)->attributes = attributes ^ 0x40u;
			}
			return;
		}
	}
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 0x10u;
	OBJECT(object)->state = 5u;
}

/* Sits for its time, or until hit, then jumps. */
void bluebird_sit_for_time(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			OBJECT(object)->flags = 0x88u;
			OBJECT(object)->animation = 0x82u;
			OBJECT(object)->z_speed = 0x200;
			OBJECT(object)->timer = 0x10u;
			state = OBJECT(object)->state;
			OBJECT(object)->state = state + 1u;
		}
		return;
	}
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 0x10u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* After its jump's 16 frames, levels off. */
void bluebird_jump(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->timer = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After 32 frames runs off to the right with a hop. */
void bluebird_run_off(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->z_speed = 0x80;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
}

/* Runs faster each frame up to 0200. */
void bluebird_speed_up(uint16_t object)
{
	uint16_t x_speed = 0;
	uint16_t x_speed_2 = 0;

	x_speed_2 = OBJECT(object)->x_speed;
	x_speed = x_speed_2 + 8u;
	if (x_speed >= 0x200u)
	{
		bluebird_take_floor(object);
		return;
	}
	OBJECT(object)->x_speed = x_speed;
	bluebird_take_floor(object);
}

/* Waits hidden until the shaking scenery comes left of x 0160, then is launched by its state. */
uint16_t bluebird_wait_launch(uint16_t object)
{
	uint16_t bluebird_launch = 0, scenery = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t parent = 0, scenery_x = 0, x_speed = 0, y_speed = 0, z_speed = 0, parent_x = 0;

	parent = OBJECT(object)->parent;
	scenery = parent;
	scenery_x = OBJECT(scenery)->x;
	if (scenery_x >= 0x160u)
		return scenery;
	OBJECT(object)->flags = 0x88u;
	parameter = OBJECT(object)->parameter;
	bluebird_launch = bluebird_launches_ADDRESS + (int8_t)((((uint32_t)parameter << 1) << 1) << 1);
	x_speed = BLUEBIRD_LAUNCH(bluebird_launch)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	y_speed = BLUEBIRD_LAUNCH(bluebird_launch)->y_speed;
	OBJECT(object)->y_speed = y_speed;
	z_speed = BLUEBIRD_LAUNCH(bluebird_launch)->z_speed;
	OBJECT(object)->z_speed = z_speed;
	parent_x = BLUEBIRD_LAUNCH(bluebird_launch)->parent_x;
	OBJECT(object)->bluebird.parent_x = parent_x;
	parameter_2 = OBJECT(object)->parameter;
	if (parameter_2 == 2u)
	{
		OBJECT(object)->animation = 0x84u;
		OBJECT(object)->zoom_x = 0x10u;
		OBJECT(object)->zoom_y = 0x10u;
	}
	OBJECT(object)->timer = 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	return bluebird_launch;
}

/* Flies out of the scenery (the third growing as it comes out), then lands on it, setting it shaking
   from above. */
uint16_t bluebird_launch_fly(uint16_t object, uint16_t states)
{
	uint8_t parameter_or_timer = 0;
	uint16_t scenery = 0;
	uint8_t timer = 0, parameter = 0, state = 0, parameter_2 = 0, timer_2 = 0;
	uint16_t parent = 0, zoom_x = 0, new_zoom = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->flags = 0xC0u;
		parent = OBJECT(object)->parent;
		scenery = parent;
		OBJECT(scenery)->state = 0xFDu;
		parameter = OBJECT(object)->parameter;
		if (parameter != 0u)
			OBJECT(object)->animation = 0x83u;
		else
			OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
		return scenery;
	}
	parameter_2 = OBJECT(object)->parameter;
	parameter_or_timer = parameter_2;
	if (parameter_or_timer != 2u)
	{
		if (parameter_or_timer == 8u)
			OBJECT(object)->animation = 0x82u;
		return states;
	}
	OBJECT(object)->flags = 0x98u;
	timer_2 = OBJECT(object)->timer;
	parameter_or_timer = timer_2;
	if (parameter_or_timer >= 0x30u)
	{
		zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
		new_zoom = zoom_x + 0x303u;
		OBJECT(object)->zoom_x = (uint8_t)(new_zoom >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)new_zoom;
		return states;
	}
	if (parameter_or_timer == 8u)
		OBJECT(object)->animation = 0x82u;
	return states;
}

/* Sits on the scenery, looking round, until it stops shaking, is hit, or comes left of its x; then jumps
   off. */
uint16_t bluebird_sit_on_scenery(uint16_t object)
{
	uint16_t scenery = 0;
	uint8_t parameter = 0, animation = 0, attributes = 0;
	uint16_t parent = 0, scenery_x = 0, parent_x = 0;

	parameter = OBJECT(object)->parameter;
	if (((random_number + parameter) & 0x3Fu) == 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation ^ 2u) | 0x80u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes ^ 0x40u;
	}
	parent = OBJECT(object)->parent;
	scenery = parent;
	if ((OBJECT(scenery)->flags & 0x40u) == 0u)
	{
		OBJECT(object)->flags = 0x88u;
		OBJECT(object)->animation = 0x82u;
		OBJECT(object)->z_speed = 0x200;
		OBJECT(object)->timer = 1u;
		OBJECT(object)->state = 6u;
		return scenery;
	}
	if ((OBJECT(object)->flags & 0x20u) == 0u)
	{
		scenery_x = OBJECT(scenery)->x;
		parent_x = OBJECT(object)->bluebird.parent_x;
		if (parent_x <= scenery_x)
			return scenery;
	}
	OBJECT(scenery)->state = 0xFDu;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x82u;
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->timer = 1u;
	OBJECT(object)->state = 6u;
	return scenery;
}
