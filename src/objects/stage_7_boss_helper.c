/**
 *    Name:        objects/stage_7_boss_helper.c
 *    Description: the four helpers of stage 7's boss
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs one of stage 7's boss' four helpers by its state: waits, moves as the boss says, or throws. */
uint16_t stage_7_boss_helper_update(uint16_t object)
{
	uint16_t helper_states = 0;
	uint8_t state = 0;

	helper_states = stage_7_boss_helper_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		stage_7_boss_helper_idle();
		return helper_states;
	case 2:
	case 4:
	case 6:
	case 8:
	case 10:
	case 12:
		return stage_7_boss_helper_move(object);
	case 14:
		return stage_7_boss_helper_attack(object);
	case 16:
		return stage_7_boss_helper_start_move(object);
	case 18:
		stage_7_boss_helper_moving(object);
		return helper_states;
	case 20:
		stage_7_boss_helper_throw_start(object);
		return helper_states;
	case 22:
		stage_7_boss_helper_throw_end(object);
		return helper_states;
	}
	unreachable();
}

/* Stage 7's boss' helper waiting (state 0): does nothing. */
void stage_7_boss_helper_idle(void)
{
}

/* Stage 7's boss' helper moving (states 1 to 6), by its step. */
uint16_t stage_7_boss_helper_move(uint16_t object)
{
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_helper_move_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			return stage_7_boss_helper_start_move(object);
		case 2:
			stage_7_boss_helper_moving(object);
			return action_handlers;
		case 4:
			stage_7_boss_helper_throw_start(object);
			return action_handlers;
		case 6:
			break;
		case -16:
			stage_7_boss_helper_idle();
			return action_handlers;
		case -14:
		case -12:
		case -10:
		case -8:
		case -6:
		case -4:
			continue;
		case -2:
			return stage_7_boss_helper_attack(object);
		}
		break;
	}
	stage_7_boss_helper_throw_end(object);
	return action_handlers;
}

/* Stage 7's boss' helper: starts its move at the state's speed. */
uint16_t stage_7_boss_helper_start_move(uint16_t object)
{
	uint16_t speed_table = 0;
	uint8_t state = 0, action = 0;
	uint16_t move_speed = 0;

	speed_table = stage_7_boss_helper_speeds_ADDRESS;
	state = OBJECT(object)->state;
	move_speed = stage_7_boss_helper_speeds[(int8_t)((uint8_t)((state - 1u) << 1)) / 2];
	OBJECT(object)->x_speed = move_speed;
	OBJECT(object)->stage_7_boss_helper.distance = 0u;
	OBJECT(object)->stage_7_boss_helper.target &= 0xFFu;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return speed_table;
}

/* Stage 7's boss' helper: moves until it has gone the state's distance, then waits. */
void stage_7_boss_helper_moving(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t distance = 0;
	uint8_t state = 0, x_speed_2 = 0, distance_high = 0;
	uint16_t behaviour = 0, x_speed = 0, old_distance_low = 0, new_distance_low = 0, distance_2 = 0, signed_distance = 0, distance_gone = 0;

	state = OBJECT(object)->state;
	distance = stage_7_boss_helper_distances_ADDRESS + (int8_t)((state - 1u) << 1);
	behaviour = OBJECT(object)->behaviour;
	x_speed = OBJECT(object)->x_speed;
	old_distance_low = behaviour;
	new_distance_low = old_distance_low + x_speed;
	carry = (uint16_t)(old_distance_low + x_speed) < old_distance_low;
	OBJECT(object)->behaviour = new_distance_low;
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	distance_high = (uint8_t)(OBJECT(object)->stage_7_boss_helper.distance >> 8u);
	OBJECT(object)->stage_7_boss_helper.distance = (OBJECT(object)->stage_7_boss_helper.distance & 0xFFu) | ((((uint16_t)(int8_t)x_speed_2 >> 8) + distance_high + carry & 0xFFu) << 8u);
	distance_2 = OBJECT(object)->stage_7_boss_helper.distance;
	signed_distance = distance_2;
	distance_gone = signed_distance >> 15 ? 0u - signed_distance : signed_distance;
	if (distance_gone == HELPER_DISTANCE(distance))
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->state = 0u;
		OBJECT(object)->action = 0u;
	}
	leftover_y = distance;
}

/* Stage 7's boss' helper throwing (state 7), by its step. */
uint16_t stage_7_boss_helper_attack(uint16_t object)
{
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_helper_attack_actions_ADDRESS;
		action = OBJECT(object)->action;
		switch ((int8_t)(uint8_t)((uint32_t)action << 1))
		{
		case 0:
			stage_7_boss_helper_throw_start(object);
			return action_handlers;
		case 2:
			break;
		case -20:
			stage_7_boss_helper_idle();
			return action_handlers;
		case -18:
		case -16:
		case -14:
		case -12:
		case -10:
		case -8:
			return stage_7_boss_helper_move(object);
		case -6:
			continue;
		case -4:
			return stage_7_boss_helper_start_move(object);
		case -2:
			stage_7_boss_helper_moving(object);
			return action_handlers;
		}
		break;
	}
	stage_7_boss_helper_throw_end(object);
	return action_handlers;
}

/* Stage 7's boss' helper: throws (sound 6000). */
void stage_7_boss_helper_throw_start(uint16_t object)
{
	uint16_t command = 0;
	uint8_t animation = 0, action = 0;

	command = 0x6000u;
	vector_queue_sound(command);
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = (animation - 3u) | 0x80u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss' helper: when the throw's animation ends, goes back to waiting. */
void stage_7_boss_helper_throw_end(uint16_t object)
{
	uint8_t animation_flags = 0, animation = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = animation - 0x7Du;
		OBJECT(object)->state = 0u;
		OBJECT(object)->action = 0u;
	}
}
