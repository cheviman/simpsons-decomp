/**
 *    Name:        objects/kind_98.c
 *    Description: Krustyland's kind 98 enemy, let out by the doors
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets up the kind 98 enemy: state 0 fights at once, the others walk out of a door first. */
void kind_98_start(uint16_t object, uint16_t *p_box, uint16_t *p_behaviour)
{
	uint16_t behaviour = 0, box = 0, setup = 0;
	uint8_t setup_count = 0, parameter = 0, state = 0;

	setup = kind_98_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	OBJECT(object)->kind_98.vanishes = 1u;
	setup_count = OBJECT(object)->kind_98.setup_count;
	OBJECT(object)->kind_98.setup_count = setup_count + 1u;
	behaviour = 0x7CE6u;
	OBJECT(object)->behaviour = 0x7CE6u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
	}
	else
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->attributes = 0x20u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	*p_box = box;
	*p_behaviour = behaviour;
}

/* Runs the kind 98 enemy's walk out of the door by its substep. */
void kind_98_entrance_steps(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = kind_98_entrance_step_handlers_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_98_entrance_show(object);
		break;
	case 2:
		kind_98_entrance_next(object);
		break;
	case 4:
		kind_98_entrance_wait(object);
		break;
	case 6:
		kind_98_entrance_walk(object);
		break;
	case 8:
		kind_98_entrance_reach_floor(object);
		break;
	case 10:
		kind_98_step_back(object);
		break;
	case 12:
		kind_98_step_back_end(object);
		break;
	case 14:
		kind_98_strike_swing(object);
		break;
	case 16:
		y = kind_98_strike_hit(object, y);
		break;
	case 18:
		y = kind_98_strike_recover(object);
		break;
	case 20:
		kind_98_strike_end(object);
		break;
	case 22:
	case 24:
		clown_ball_burst_steps(object, &y, &step_handlers);
		break;
	case 26:
		clown_ball_start(object, &y, &step_handlers);
		break;
	case 28:
	case 30:
		clown_ball_fall(object);
		break;
	case 32:
		clown_ball_vanish(object);
		break;
	case 34:
		clown_ball_burst(object);
		break;
	case 36:
		clown_ball_burst_end(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Shows the enemy in the doorway. */
void kind_98_entrance_show(uint16_t object)
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
void kind_98_entrance_next(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Waits 64 frames in the doorway. */
void kind_98_entrance_wait(uint16_t object)
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
void kind_98_entrance_walk(uint16_t object)
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
void kind_98_entrance_reach_floor(uint16_t object)
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
void kind_98_step_back(uint16_t object)
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
void kind_98_step_back_end(uint16_t object)
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
void kind_98_strike_swing(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* At the strike's mark, puts out its hit box. */
uint16_t kind_98_strike_hit(uint16_t object, uint16_t y)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	y = kind_98_strike_hit_box_ADDRESS;
	vector_set_hit_box(object, y);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return y;
}

/* Takes its body's hit box back and waits for the animation's end. */
uint16_t kind_98_strike_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = kind_98_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	kind_98_strike_end(object);
	return box;
}

/* When the animation ends, goes back to the fight. */
void kind_98_strike_end(uint16_t object)
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
