/**
 *    Name:        enemies/goon_bomb.c
 *    Description: the bomb the goons throw
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The bomb a goon throws (list 2 type 16): runs its state; a strike breaks it. */
uint16_t goon_bomb(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t state_handlers = 0;

	state_2 = (uint8_t)state;
	state_handlers = 0x7F49u;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		state_handlers = goon_bomb_set_up(object);
		break;
	case 2:
		goon_bomb_fly(object);
		break;
	case 4:
		goon_bomb_explode(object);
		break;
	case 6:
		goon_bomb_explosion_end(object);
		break;
	case 8:
		goon_bomb_break(object);
		break;
	case 10:
		goon_bomb_break_end(object);
		break;
	case -4:
	case -2:
		state_handlers = goon_bomb_broken(object);
		break;
	}
	state_handlers = object_take_special_hit(object, state_handlers);
	return vector_remove_past_right_edge(object, state_handlers);
}

/* Struck (state -1): runs its step. */
uint16_t goon_bomb_broken(uint16_t object)
{
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = 0x7F51u;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			goon_bomb_break(object);
			return step_handlers;
		case 2:
			break;
		case -12:
		case -10:
			continue;
		case -8:
			return goon_bomb_set_up(object);
		case -6:
			goon_bomb_fly(object);
			return step_handlers;
		case -4:
			goon_bomb_explode(object);
			return step_handlers;
		case -2:
			goon_bomb_explosion_end(object);
			return step_handlers;
		}
		break;
	}
	goon_bomb_break_end(object);
	return step_handlers;
}

/* Stops and shows hit sparks. */
void goon_bomb_break(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Gone at the sparks' end. */
void goon_bomb_break_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}

/* Its state 0: a bomb (the goon set's animation 34) thrown up and forward the way its thrower faces. */
uint16_t goon_bomb_set_up(uint16_t object)
{
	uint16_t object_2 = 0, setup = 0;
	uint8_t attributes = 0, state = 0;
	uint16_t parent = 0, x_speed = 0;

	setup = goon_bomb_setup_ADDRESS;
	vector_object_setup(object, setup);
	OBJECT(object)->z_speed = 0x200;
	OBJECT(object)->x_speed = 0x200;
	parent = OBJECT(object)->parent;
	object_2 = parent;
	attributes = OBJECT(object_2)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->flags = 0xC8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return object_2;
}

/* Flying (state 1): falls with gravity; landing, explodes (kind 9C animation 8A) with a hit box and
   sound 6F00. */
void goon_bomb_fly(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box = 0, command = 0, ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->kind = 0x9Cu;
	OBJECT(object)->animation = 0x8Au;
	OBJECT(object)->flags = 0xC0u;
	box = goon_bomb_fly_box_ADDRESS;
	vector_set_hit_box(object, box);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	command = 0x6F00u;
	carry = vector_queue_sound(command);
}

/* Exploding (state 2): its flags back to 80, then waits for the explosion's end. */
void goon_bomb_explode(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->flags = 0x80u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	goon_bomb_explosion_end(object);
}

/* Gone at the explosion's end. */
void goon_bomb_explosion_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
		OBJECT(object)->flags = 0u;
}
