/**
 *    Name:        enemies/lumberjack.c
 *    Description: stage 5's lumberjack (type 2F) and its axe (action 22)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the lumberjack up with its behaviour lumberjack_behaviour, turned to its player: state 0 joins
   the fight at once, the others jump in first. */
uint16_t lumberjack_setup(uint16_t object)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t parameter = 0, attributes = 0, state = 0;

	setup = lumberjack_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	OBJECT(object)->lumberjack.vanishes = 1u;
	OBJECT(object)->behaviour = 0x7B36u;
	OBJECT(object)->retarget_time = 0x10u;
	parameter = OBJECT(object)->parameter;
	if (parameter == 0u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
		return y;
	}
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* The lumberjack's way in, by field 29: a walk, then a jump down into the stage. */
uint16_t lumberjack_jump_in(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		lumberjack_walk_in(object);
		return y;
	case 2:
		lumberjack_jump_down(object);
		return y;
	case 4:
		lumberjack_land(object);
		return y;
	case 6:
		lumberjack_axe_start(object);
		return y;
	case 8:
		return lumberjack_axe_swing(object, y);
	case 10:
		return lumberjack_axe_recover(object);
	case 12:
		enemy_end_action_with_animation(object);
		return y;
	case 14:
		lumberjack_axe_rest(object, &y_2, &ignored16);
		return y_2;
	case 16:
		lumberjack_axe_pause(object, 0u);
		return y;
	case 18:
		lumberjack_axe_wait(object);
		return y;
	}
	unreachable();
}

/* Walks the lumberjack in toward its player for 96 frames. */
void lumberjack_walk_in(uint16_t object)
{
	uint8_t action_step = 0, attributes = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->timer = 0x60u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_target(object);
	attributes = OBJECT(object)->attributes;
	if ((attributes & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
}

/* When the walk is over, jumps the lumberjack down toward the front. */
void lumberjack_jump_down(uint16_t object)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = -0x80;
		OBJECT(object)->z_speed = 0x400;
		OBJECT(object)->timer = 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Pulls the lumberjack down until it lands, then makes it hittable and lets it fight. */
void lumberjack_land(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t timer = 0, attributes = 0;
	uint16_t z_speed = 0, t1 = 0;

	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x30u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry == 0u)
	{
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer == 1u)
		{
			attributes = OBJECT(object)->attributes;
			OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		}
		return;
	}
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Starts the lumberjack's swing with its sound, turned to its player. */
void lumberjack_axe_start(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6A00u;
	carry = vector_queue_sound(command);
	face_target(object);
}

/* On the swing's marked frame gives it the axe's hit box with the sound; every other swing goes on to
   the pause. */
uint16_t lumberjack_axe_swing(uint16_t object, uint16_t box)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, action_step = 0, swings = 0, swings_2 = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return box;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	command = 0x6A00u;
	carry = vector_queue_sound(command);
	box = lumberjack_axe_swing_box_ADDRESS;
	vector_set_hit_box(object, box);
	swings = OBJECT(object)->lumberjack.swings;
	OBJECT(object)->lumberjack.swings = swings - 1u;
	swings_2 = OBJECT(object)->lumberjack.swings;
	if (swings_2 & 1u)
		OBJECT(object)->action_step = 4u;
	return box;
}

/* Gives the lumberjack back its plain hit box and ends the action when the swing ends. */
uint16_t lumberjack_axe_recover(uint16_t object)
{
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = lumberjack_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_end_action_with_animation(object);
	return box;
}

/* Ends the enemy's action when its animation ends (shared by the lumberjack's and the gorilla's
   attacks). */
void enemy_end_action_with_animation(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Gives the lumberjack back its plain hit box and goes on to its pause. */
void lumberjack_axe_rest(uint16_t object, uint16_t *p_box, uint16_t *p_pause_loops)
{
	uint16_t pause_loops = (uint16_t)*p_pause_loops;
	uint16_t box = 0;
	uint8_t action_step = 0;

	box = lumberjack_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	pause_loops = lumberjack_axe_pause(object, pause_loops);
	*p_box = box;
	*p_pause_loops = pause_loops;
}

/* When the swing ends, starts the pause animation for as many times as lumberjack_pause_loops_by_players
   gives. */
uint16_t lumberjack_axe_pause(uint16_t object, uint16_t pause_loops)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->animation = 0x86u;
		pause_loops = lumberjack_pause_loops_by_players_ADDRESS;
		OBJECT(object)->lumberjack.pause_loops = lumberjack_pause_loops_by_players[(int8_t)player_count];
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return pause_loops;
}

/* Counts the pause's loops down and ends the action. */
void lumberjack_axe_wait(uint16_t object)
{
	uint8_t animation_flags = 0, pause_loops = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		pause_loops = OBJECT(object)->lumberjack.pause_loops;
		OBJECT(object)->lumberjack.pause_loops = pause_loops - 1u;
		if (pause_loops == 1u)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->timer = 0u;
			return;
		}
	}
}
