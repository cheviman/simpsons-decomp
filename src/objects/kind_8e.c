/**
 *    Name:        objects/kind_8e.c
 *    Description: the kind 8E figures (types 24, 5280 20) and the shot type 24 throws (4D40 type 11)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The shot that has hit (steps FE, FF), by field 29: it stops, bursts and goes. */
uint16_t spark_shot_burst(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = spark_shot_burst_steps_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			spark_shot_burst_start(object);
			return step_handlers;
		case 2:
			break;
		case -8:
		case -6:
			continue;
		case -4:
			return spark_shot_setup(object);
		case -2:
			spark_shot_fly();
			return step_handlers;
		}
		break;
	}
	spark_shot_remove(object);
	return step_handlers;
}

/* Stops the shot and plays its burst. */
void spark_shot_burst_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->animation = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Frees the shot's slot when its burst ends. */
void spark_shot_remove(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Sets the shot up flying left fast, able to hurt. */
uint16_t spark_shot_setup(uint16_t object)
{
	uint16_t setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = spark_shot_object_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->attack = 1u;
	OBJECT(object)->flags = 0xC8u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->x_speed = -0x300;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	spark_shot_fly();
	return setup;
}

/* The shot's flight: nothing to do, it moves by its speed. */
void spark_shot_fly(void)
{
}

/* Sends the thrower into its hit step (FF) when it is hit. */
void kind_8e_thrower_check_hit(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	if ((int8_t)state >= 0 && (OBJECT(object)->flags & 0x20u) != 0u)
		OBJECT(object)->state = 0xFFu;
}

/* The thrower when hit (step FF), by field 29: it runs off. */
uint16_t kind_8e_thrower_hurt(uint16_t object, uint16_t y)
{
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			kind_8e_thrower_run_off(object);
			return y;
		case 2:
			kind_8e_thrower_running();
			return y;
		case 4:
			kind_8e_thrower_stagger(object);
			return y;
		case 6:
			break;
		case -14:
			continue;
		case -12:
			return kind_8e_thrower_setup(object);
		case -10:
			kind_8e_thrower_wait(object);
			return y;
		case -8:
			kind_8e_thrower_wind_up(object);
			return y;
		case -6:
			return kind_8e_thrower_throw(object, y);
		case -4:
			kind_8e_thrower_follow_through(object);
			return y;
		case -2:
			kind_8e_thrower_repeat(object);
			return y;
		}
		break;
	}
	kind_8e_thrower_recover(object);
	return y;
}

/* Sends the hit thrower running off to the right. */
void kind_8e_thrower_run_off(uint16_t object)
{
	uint8_t attributes = 0, action_step = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->animation = 0x82u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* The thrower running off: nothing to do until it leaves the screen. */
void kind_8e_thrower_running(void)
{
}

/* Unused: runs the kind 8E thrower by its step: stagger or recover, the negative steps its other
   handlers. */
void unused_kind_8e_thrower_run_step(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		kind_8e_thrower_stagger(object);
		return;
	case 2:
		kind_8e_thrower_recover(object);
		return;
	case -18:
		kind_8e_thrower_hurt(object, 0u);
		return;
	case -16:
		kind_8e_thrower_setup(object);
		return;
	case -14:
		kind_8e_thrower_wait(object);
		return;
	case -12:
		kind_8e_thrower_wind_up(object);
		return;
	case -10:
		kind_8e_thrower_throw(object, 0u);
		return;
	case -8:
		kind_8e_thrower_follow_through(object);
		return;
	case -6:
		kind_8e_thrower_repeat(object);
		return;
	case -4:
		kind_8e_thrower_run_off(object);
		return;
	case -2:
		kind_8e_thrower_running();
		return;
	}
}

/* Plays the thrower's animation 84. */
void kind_8e_thrower_stagger(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* When that animation ends, makes the thrower hittable and starts it throwing again. */
void kind_8e_thrower_recover(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->state = 2u;
	}
}

/* Sets the thrower up facing left. */
uint16_t kind_8e_thrower_setup(uint16_t object)
{
	uint16_t box = 0, setup = 0;
	uint8_t attributes = 0, state = 0;

	setup = kind_8e_thrower_object_setup_ADDRESS;
	box = vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
}

/* Waits for the scroll to bring the thrower on the screen. */
void kind_8e_thrower_wait(uint16_t object)
{
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = OBJECT(object)->x;
	if (t1 < 0x150u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Starts the thrower's throw. */
void kind_8e_thrower_wind_up(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->animation = 0x83u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* On the throw's marked frame, puts in the shot. */
uint16_t kind_8e_thrower_throw(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, shot_record = 0;
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return y;
	shot_record = kind_8e_thrower_throw_child_ADDRESS;
	spawn_list_2_child(object, shot_record, &ignored16, &carry);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	kind_8e_thrower_follow_through(object);
	return shot_record;
}

/* When the throw ends, plays the thrower's animation 81. */
void kind_8e_thrower_follow_through(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x81u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* When that animation ends, starts another throw. */
void kind_8e_thrower_repeat(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->state = 2u;
}
