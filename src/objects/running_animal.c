/**
 *    Name:        objects/running_animal.c
 *    Description: the dogs and squirrels running across the stages
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the animal's knock-away by its substep. */
uint16_t running_animal_hit_steps(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = running_animal_hit_step_handlers_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			running_animal_knocked(object);
			return step_handlers;
		case 2:
			running_animal_knocked_away(object);
			return step_handlers;
		case 4:
			running_animal_knocked_back(object);
			return step_handlers;
		case 6:
			break;
		case -20:
		case -18:
			continue;
		case -16:
			return running_animal_start(object);
		case -14:
			running_animal_run(object);
			return step_handlers;
		case -12:
			running_animal_stop(object);
			return step_handlers;
		case -10:
			running_animal_picked_up(object);
			return step_handlers;
		case -8:
			running_animal_thrown(object);
			return step_handlers;
		case -6:
			running_animal_hurt_enemies(object);
			return step_handlers;
		case -4:
			running_animal_land(object);
			return step_handlers;
		case -2:
			running_animal_idle();
			return step_handlers;
		}
		break;
	}
	running_animal_gone();
	return step_handlers;
}

/* Knocked away: shows its knocked look and flies up the screen. */
void running_animal_knocked(uint16_t object)
{
	uint8_t look_animation = 0, action_step = 0;

	OBJECT(object)->kind = 4u;
	look_animation = (uint8_t)OBJECT(object)->running_animal.look;
	OBJECT(object)->animation = look_animation + 1u;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->y_speed = -0x300;
	OBJECT(object)->z_speed = 0x80;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	running_animal_knocked_away(object);
}

/* Flies away shrinking until there is no floor ahead, then drops. */
void running_animal_knocked_away(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0, smaller_zoom_x = 0, smaller_zoom_y = 0, value_ahead = 0;
	uint16_t floor_cell = 0;
	uint8_t action_step = 0;
	uint16_t zoom_x = 0, smaller_zoom = 0;
	uint32_t zoom_x_halfword = 0;

	OBJECT(object)->flags = 0x98u;
	zoom_x = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	smaller_zoom = zoom_x - 0x101u;
	smaller_zoom_y = (uint8_t)smaller_zoom;
	smaller_zoom_x = (uint8_t)(smaller_zoom >> 8);
	if ((uint16_t)(((uint32_t)smaller_zoom_x << 8) | (smaller_zoom_y & 0xFFu)) >= 0x2020u)
	{
		zoom_x_halfword = ((uint32_t)smaller_zoom_x << 8) | (smaller_zoom_y & 0xFFu);
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x_halfword >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x_halfword;
	}
	vector_floor_ahead_y(object, &floor_cell, &negative);
	value_ahead = (uint8_t)(floor_cell >> 8);
	if ((int8_t)value_ahead >= 0)
		return;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = -0x80;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Grows back and, on landing at full size, runs off again. */
void running_animal_knocked_back(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t zoom_x = 0;
	uint8_t look_kind = 0, action_step = 0;
	uint16_t zoom_x_2 = 0, z_speed = 0, zoom_x_3 = 0, screen_x = 0, x_speed = 0;

	OBJECT(object)->flags = 0x98u;
	zoom_x_2 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	zoom_x = zoom_x_2 + 0x101u;
	if (zoom_x <= 0x4040u)
	{
		OBJECT(object)->zoom_x = (uint8_t)(zoom_x >> 8u);
		OBJECT(object)->zoom_y = (uint8_t)zoom_x;
	}
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x10u;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		running_animal_gone();
		return;
	}
	zoom_x_3 = (((uint32_t)OBJECT(object)->zoom_x << 8u) | OBJECT(object)->zoom_y);
	if (zoom_x_3 < 0x4040u)
	{
		running_animal_gone();
		return;
	}
	look_kind = (uint8_t)(OBJECT(object)->running_animal.look >> 8u);
	OBJECT(object)->kind = (uint16_t)((uint32_t)look_kind << 8) >> 8;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->x_speed = 0x200;
	screen_x = OBJECT(object)->x;
	if (screen_x < 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->flags = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Does nothing (after it ran off). */
void running_animal_gone(void)
{
}

/* Sets an animal up by its spawn's state: its kind, look, timings, and runs it in from its side. */
uint16_t running_animal_start(uint16_t object)
{
	uint8_t kind = 0;
	uint16_t running_animal = 0, setup = 0, timing_table = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t kind_2 = 0, attributes = 0, wait = 0, screen_x = 0, x_speed = 0, x_speed_2 = 0;

	setup = running_animal_setup_ADDRESS;
	vector_object_setup(object, setup);
	parameter = OBJECT(object)->parameter;
	running_animal = running_animals_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	kind_2 = (((uint32_t)RUNNING_ANIMAL(running_animal)->kind << 8u) | RUNNING_ANIMAL(running_animal)->animation);
	kind = (uint8_t)(kind_2 >> 8);
	OBJECT(object)->running_animal.look = ((uint32_t)kind << 8) | (kind_2 & 0xFFu);
	OBJECT(object)->kind = kind;
	attributes = (((uint32_t)RUNNING_ANIMAL(running_animal)->attributes << 8u) | RUNNING_ANIMAL(running_animal)->quiet);
	OBJECT(object)->attributes = attributes >> 8;
	OBJECT(object)->running_animal.quiet = attributes;
	timing_table = running_animal_timings_ADDRESS;
	parameter_2 = OBJECT(object)->parameter;
	wait = (((uint32_t)RUNNING_ANIMAL_TIMING(running_animal_timings_ADDRESS + (int8_t)((uint32_t)parameter_2 << 1))->wait << 8u) | RUNNING_ANIMAL_TIMING(running_animal_timings_ADDRESS + (int8_t)((uint32_t)parameter_2 << 1))->fast);
	OBJECT(object)->running_animal.stop_frames = (uint8_t)(wait >> 8u);
	OBJECT(object)->running_animal.fast = (uint8_t)wait;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->carried = 0u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->running_animal.stops_left = 2u;
	OBJECT(object)->x_speed = 0x100;
	screen_x = OBJECT(object)->x;
	if (screen_x >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	x_speed_2 = OBJECT(object)->x_speed;
	OBJECT(object)->running_animal.run_speed = x_speed_2;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return timing_table;
}

/* Runs for 64 frames, then stops for its stop time. */
void running_animal_run(uint16_t object)
{
	uint8_t timer = 0, stop_frames = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		stop_frames = OBJECT(object)->running_animal.stop_frames;
		OBJECT(object)->timer = stop_frames;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->attack = 0xFFu;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* After its stop, runs again; after its second run it runs off for good. */
void running_animal_stop(uint16_t object)
{
	uint8_t carried = 0, timer = 0, look_kind = 0, stops_left = 0, state = 0;
	uint16_t run_speed = 0;

	carried = OBJECT(object)->carried;
	if (carried != 0u)
	{
		running_animal_idle();
		return;
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		running_animal_idle();
		return;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->attack = 0u;
	look_kind = (uint8_t)(OBJECT(object)->running_animal.look >> 8u);
	OBJECT(object)->kind = look_kind;
	OBJECT(object)->animation = 0x80u;
	run_speed = OBJECT(object)->running_animal.run_speed;
	OBJECT(object)->x_speed = run_speed;
	stops_left = OBJECT(object)->running_animal.stops_left;
	OBJECT(object)->running_animal.stops_left = stops_left - 1u;
	if (stops_left != 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state - 1u;
		running_animal_idle();
		return;
	}
	OBJECT(object)->state = 7u;
}

/* Does nothing. */
void running_animal_idle(void)
{
}

/* Picked up: marked carried, with its carried look. */
void running_animal_picked_up(uint16_t object)
{
	uint8_t look_animation = 0, state = 0;

	OBJECT(object)->carried = 1u;
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->kind = 4u;
	look_animation = (uint8_t)OBJECT(object)->running_animal.look;
	OBJECT(object)->animation = look_animation;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state - 1u;
}

/* Thrown: yelps (sound 5F00) unless quiet, at half speed unless fast, with its hit box. */
void running_animal_thrown(uint16_t object)
{
	uint16_t command = 0;
	uint8_t quiet = 0, fast = 0, look_animation = 0, state = 0;
	uint16_t x_speed = 0;

	quiet = OBJECT(object)->running_animal.quiet;
	if (quiet == 0u)
	{
		command = 0x5F00u;
		vector_queue_sound(command);
	}
	fast = OBJECT(object)->running_animal.fast;
	if (fast == 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = (int16_t)x_speed >> 1;
	}
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->carried = 0u;
	look_animation = (uint8_t)OBJECT(object)->running_animal.look;
	OBJECT(object)->animation = look_animation + 1u;
	leftover_y = running_animal_thrown_box_ADDRESS;
	vector_set_hit_box(object);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	running_animal_hurt_enemies(object);
}

/* Hurts the enemies the thrown animal touches. */
void running_animal_hurt_enemies(uint16_t object)
{
	check_hits_with_enemies(object);
}

/* Lands from the throw back in its own look, and is knocked away. */
void running_animal_land(uint16_t object)
{
	uint8_t look_kind = 0;
	uint16_t old_y = 0, new_y = 0;

	look_kind = (uint8_t)(OBJECT(object)->running_animal.look >> 8u);
	OBJECT(object)->kind = look_kind;
	OBJECT(object)->animation = 0x80u;
	OBJECT(object)->state = 0xFEu;
	old_y = OBJECT(object)->y;
	new_y = old_y + 2u;
	OBJECT(object)->y = new_y;
	OBJECT(object)->animation_flags = 0x80u;
}
