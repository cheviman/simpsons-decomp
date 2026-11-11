/**
 *    Name:        objects/one_eared_rabbit.c
 *    Description: Krustyland's kind 98 enemy, let out by the doors
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind 98 enemy: state 0 fights at once, the others walk out of a door first. */
uint16_t one_eared_rabbit_start(uint16_t object)
{
	uint16_t behaviour = 0, setup = 0;
	uint8_t setup_count = 0, parameter = 0, state = 0;

	setup = one_eared_rabbit_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->one_eared_rabbit.vanishes = 1u;
	setup_count = OBJECT(object)->one_eared_rabbit.setup_count;
	OBJECT(object)->one_eared_rabbit.setup_count = setup_count + 1u;
	behaviour = 0x7CE6u;
	OBJECT(object)->behaviour = 0x7CE6u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return behaviour;
	}
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return behaviour;
}

/* Runs the kind 98 enemy's walk out of the door by its substep. */
uint16_t one_eared_rabbit_entrance_steps(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = one_eared_rabbit_entrance_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		one_eared_rabbit_entrance_show(object);
		return step_handlers;
	case 2:
		one_eared_rabbit_entrance_next(object);
		return step_handlers;
	case 4:
		one_eared_rabbit_entrance_wait(object);
		return step_handlers;
	case 6:
		one_eared_rabbit_entrance_walk(object);
		return step_handlers;
	case 8:
		one_eared_rabbit_entrance_reach_floor(object);
		return step_handlers;
	case 10:
		one_eared_rabbit_step_back(object);
		return step_handlers;
	case 12:
		one_eared_rabbit_step_back_end(object);
		return step_handlers;
	case 14:
		one_eared_rabbit_strike_swing(object);
		return step_handlers;
	case 16:
		one_eared_rabbit_strike_hit(object);
		return step_handlers;
	case 18:
		one_eared_rabbit_strike_recover(object);
		return step_handlers;
	case 20:
		one_eared_rabbit_strike_end(object);
		return step_handlers;
	case 22:
	case 24:
		return clown_ball_burst_steps(object);
	case 26:
		return clown_ball_start(object);
	case 28:
	case 30:
		clown_ball_fall(object);
		return step_handlers;
	case 32:
		clown_ball_vanish(object);
		return step_handlers;
	case 34:
		clown_ball_burst(object);
		return step_handlers;
	case 36:
		clown_ball_burst_end(object);
		return step_handlers;
	}
	unreachable();
}

/* Shows the enemy in the doorway. */
void one_eared_rabbit_entrance_show(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->z = 4u;
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->parameter = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Goes on to the next substep. */
void one_eared_rabbit_entrance_next(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Waits 64 frames in the doorway. */
void one_eared_rabbit_entrance_wait(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x20u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After 32 frames more, walks out. */
void one_eared_rabbit_entrance_walk(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->y_speed = -0x100;
		OBJECT(object)->animation = 0x81u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Walks until there is floor under it, then fights. */
void one_eared_rabbit_entrance_reach_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 2u;
	}
}

/* Steps back from its target for 32 frames. */
void one_eared_rabbit_step_back(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x87u;
	face_target(object);
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->x_speed = 0x80;
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Goes back to the fight. */
void one_eared_rabbit_step_back_end(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts its strike facing the target. */
void one_eared_rabbit_strike_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* At the strike's mark, puts out its hit box. */
void one_eared_rabbit_strike_hit(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return;
	leftover_y = one_eared_rabbit_strike_hit_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Takes its body's hit box back and waits for the animation's end. */
void one_eared_rabbit_strike_recover(uint16_t object)
{
	uint8_t action_step = 0;

	leftover_y = one_eared_rabbit_body_box_ADDRESS;
	vector_set_hit_box(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	one_eared_rabbit_strike_end(object);
}

/* When the animation ends, goes back to the fight. */
void one_eared_rabbit_strike_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->timer = 0u;
		return;
	}
}
