/**
 *    Name:        enemies/enemy_climbing.c
 *    Description: climbing up and hopping down the floor's steps
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Climbs a step toward the front: jumps up to it, moves forward until it lands, waits and thinks again. */
void enemy_climb_up_front(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_climb_up_front_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case 2:
		case 26:
			enemy_move_front_until_landed(object);
			break;
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
		case 40:
		case 46:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case 8:
		case 32:
			enemy_move_back_until_landed(object);
			break;
		case 12:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case 14:
		case 38:
			enemy_move_left_until_landed(object);
			break;
		case 18:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case 20:
		case 44:
			enemy_move_right_until_landed(object);
			break;
		case 24:
		case 36:
		case 42:
			enemy_hop_start(object);
			break;
		case 30:
			enemy_hop_back_start(object);
			break;
		case 48:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 50:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 52:
			enemy_go_straight(object);
			break;
		case 54:
		case 64:
			enemy_walk_start_in_turn(object);
			break;
		case 56:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 58:
			enemy_line_up_near_start(object);
			break;
		case 60:
			enemy_line_up_near_in_depth(object);
			break;
		case 62:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 66:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 68:
		case 112:
			enemy_line_up_start(object);
			break;
		case 70:
		case 114:
			enemy_line_up_in_depth(object);
			break;
		case 72:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 74:
			enemy_keep_distance_start(object);
			break;
		case 76:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 78:
			enemy_keep_distance_back_off(object);
			break;
		case 80:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 82:
			enemy_wait_start(object);
			break;
		case 84:
		case 90:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 86:
			enemy_back_off_start(object);
			break;
		case 88:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 92:
			enemy_step_toward_target_start(object);
			break;
		case 94:
			enemy_step_toward_target_step(object);
			break;
		case 96:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 98:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 100:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 102:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 104:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 106:
			enemy_rush_start(object);
			break;
		case 108:
			enemy_rush_step(object);
			break;
		case 110:
			enemy_rush_slow_down(object);
			break;
		case 116:
			enemy_pace_start(object);
			break;
		case 118:
			enemy_pace_step(object);
			break;
		case 120:
			enemy_pace_end(object);
			break;
		case -24:
			enemy_climb(object, &step_handlers, p_left_caller);
			break;
		case -16:
			continue;
		case -14:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -12:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -10:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -8:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -6:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -4:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -2:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation, the speed up to reach the step's floor, the x speed
   stopped. */
uint16_t enemy_climb_up_front_start(uint16_t object)
{
	uint16_t floor_level = 0, speeds_table = 0;
	uint8_t enemy_class = 0, step_level = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x84u;
	step_level = OBJECT(object)->enemy.step_level;
	floor_level = (uint32_t)step_level << 8;
	speeds_table = set_climb_speed(object, floor_level);
	OBJECT(object)->x_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return speeds_table;
}

/* Moves toward the front while it falls until it lands. */
void enemy_move_front_until_landed(uint16_t object)
{
	OBJECT(object)->y_speed = -0x40;
	enemy_fall_until_landed(object);
}

/* Once its timer runs out, back in the hit checks and thinking. */
void enemy_back_to_thinking_after_wait(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->flags = 0xC0u;
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
}

/* Climbs a step toward the back: jumps up to it, moves back until it lands, waits and thinks again. */
void enemy_climb_up_back(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_climb_up_back_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case 2:
		case 26:
			enemy_move_back_until_landed(object);
			break;
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
		case 40:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case 8:
		case 32:
			enemy_move_left_until_landed(object);
			break;
		case 12:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case 14:
		case 38:
			enemy_move_right_until_landed(object);
			break;
		case 18:
		case 30:
		case 36:
			enemy_hop_start(object);
			break;
		case -4:
		case 20:
			enemy_move_front_until_landed(object);
			break;
		case 24:
			enemy_hop_back_start(object);
			break;
		case 42:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 44:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 46:
			enemy_go_straight(object);
			break;
		case 48:
		case 58:
			enemy_walk_start_in_turn(object);
			break;
		case 50:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 52:
			enemy_line_up_near_start(object);
			break;
		case 54:
			enemy_line_up_near_in_depth(object);
			break;
		case 56:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 60:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 62:
		case 106:
			enemy_line_up_start(object);
			break;
		case 64:
		case 108:
			enemy_line_up_in_depth(object);
			break;
		case 66:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 68:
			enemy_keep_distance_start(object);
			break;
		case 70:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 72:
			enemy_keep_distance_back_off(object);
			break;
		case 74:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 76:
			enemy_wait_start(object);
			break;
		case 78:
		case 84:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 80:
			enemy_back_off_start(object);
			break;
		case 82:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 86:
			enemy_step_toward_target_start(object);
			break;
		case 88:
			enemy_step_toward_target_step(object);
			break;
		case 90:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 92:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 94:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 96:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 98:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 100:
			enemy_rush_start(object);
			break;
		case 102:
			enemy_rush_step(object);
			break;
		case 104:
			enemy_rush_slow_down(object);
			break;
		case 110:
			enemy_pace_start(object);
			break;
		case 112:
			enemy_pace_step(object);
			break;
		case 114:
			enemy_pace_end(object);
			break;
		case -32:
			enemy_hit_reaction(object, &step_handlers, p_left_caller);
			break;
		case -22:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -20:
			continue;
		case -18:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -16:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -14:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -12:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -10:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -8:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -6:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation facing the back, the speed up to reach the step's floor, the
   x speed stopped. */
uint16_t enemy_climb_up_back_start(uint16_t object)
{
	uint16_t floor_level = 0, speeds_table = 0;
	uint8_t enemy_class = 0, step_level = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x85u;
	step_level = OBJECT(object)->enemy.step_level;
	floor_level = (uint32_t)step_level << 8;
	speeds_table = set_climb_speed(object, floor_level);
	OBJECT(object)->x_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return speeds_table;
}

/* Moves toward the back while it falls until it lands. */
void enemy_move_back_until_landed(uint16_t object)
{
	OBJECT(object)->y_speed = 0x40;
	enemy_fall_until_landed(object);
}

/* Climbs a step to the left: jumps up to it, moves left until it lands, waits and thinks again. */
void enemy_climb_up_left(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_climb_up_left_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case 2:
		case 26:
			enemy_move_left_until_landed(object);
			break;
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
		case 34:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case 8:
		case 32:
			enemy_move_right_until_landed(object);
			break;
		case 12:
		case 24:
		case 30:
			enemy_hop_start(object);
			break;
		case -10:
		case 14:
			enemy_move_front_until_landed(object);
			break;
		case 18:
			enemy_hop_back_start(object);
			break;
		case -4:
		case 20:
			enemy_move_back_until_landed(object);
			break;
		case 36:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 38:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 40:
			enemy_go_straight(object);
			break;
		case 42:
		case 52:
			enemy_walk_start_in_turn(object);
			break;
		case 44:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 46:
			enemy_line_up_near_start(object);
			break;
		case 48:
			enemy_line_up_near_in_depth(object);
			break;
		case 50:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 54:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 56:
		case 100:
			enemy_line_up_start(object);
			break;
		case 58:
		case 102:
			enemy_line_up_in_depth(object);
			break;
		case 60:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 62:
			enemy_keep_distance_start(object);
			break;
		case 64:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 66:
			enemy_keep_distance_back_off(object);
			break;
		case 68:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 70:
			enemy_wait_start(object);
			break;
		case 72:
		case 78:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 74:
			enemy_back_off_start(object);
			break;
		case 76:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 80:
			enemy_step_toward_target_start(object);
			break;
		case 82:
			enemy_step_toward_target_step(object);
			break;
		case 84:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 86:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 88:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 90:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 92:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 94:
			enemy_rush_start(object);
			break;
		case 96:
			enemy_rush_step(object);
			break;
		case 98:
			enemy_rush_slow_down(object);
			break;
		case 104:
			enemy_pace_start(object);
			break;
		case 106:
			enemy_pace_step(object);
			break;
		case 108:
			enemy_pace_end(object);
			break;
		case -28:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -26:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -24:
			continue;
		case -22:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -20:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -18:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -16:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -14:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -12:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -6:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation, the speed up to reach the step's floor, the y speed
   stopped. */
uint16_t enemy_climb_up_left_start(uint16_t object)
{
	uint16_t floor_level = 0, speeds_table = 0;
	uint8_t enemy_class = 0, step_level = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x84u;
	step_level = OBJECT(object)->enemy.step_level;
	floor_level = (uint32_t)step_level << 8;
	speeds_table = set_climb_speed(object, floor_level);
	OBJECT(object)->y_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return speeds_table;
}

/* Moves left while it falls until it lands. */
void enemy_move_left_until_landed(uint16_t object)
{
	OBJECT(object)->x_speed = -0x80;
	enemy_fall_until_landed(object);
}

/* Climbs a step to the right: jumps up to it, moves right until it lands, waits and thinks again. */
void enemy_climb_up_right(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_climb_up_right_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case 2:
		case 26:
			enemy_move_right_until_landed(object);
			break;
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
		case 28:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
		case 18:
		case 24:
			enemy_hop_start(object);
			break;
		case -16:
		case 8:
			enemy_move_front_until_landed(object);
			break;
		case 12:
			enemy_hop_back_start(object);
			break;
		case -10:
		case 14:
			enemy_move_back_until_landed(object);
			break;
		case -4:
		case 20:
			enemy_move_left_until_landed(object);
			break;
		case 30:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 32:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 34:
			enemy_go_straight(object);
			break;
		case 36:
		case 46:
			enemy_walk_start_in_turn(object);
			break;
		case 38:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 40:
			enemy_line_up_near_start(object);
			break;
		case 42:
			enemy_line_up_near_in_depth(object);
			break;
		case 44:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 48:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 50:
		case 94:
			enemy_line_up_start(object);
			break;
		case 52:
		case 96:
			enemy_line_up_in_depth(object);
			break;
		case 54:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 56:
			enemy_keep_distance_start(object);
			break;
		case 58:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 60:
			enemy_keep_distance_back_off(object);
			break;
		case 62:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 64:
			enemy_wait_start(object);
			break;
		case 66:
		case 72:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 68:
			enemy_back_off_start(object);
			break;
		case 70:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 74:
			enemy_step_toward_target_start(object);
			break;
		case 76:
			enemy_step_toward_target_step(object);
			break;
		case 78:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 80:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 82:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 84:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 86:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 88:
			enemy_rush_start(object);
			break;
		case 90:
			enemy_rush_step(object);
			break;
		case 92:
			enemy_rush_slow_down(object);
			break;
		case 98:
			enemy_pace_start(object);
			break;
		case 100:
			enemy_pace_step(object);
			break;
		case 102:
			enemy_pace_end(object);
			break;
		case -48:
			enemy_think(object, &step_handlers, p_left_caller);
			break;
		case -34:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -32:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -30:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -28:
			continue;
		case -26:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -24:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -22:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -20:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -18:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -12:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case -6:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation, the speed up to reach the step's floor, the y speed stopped
   (the same as the left climb's start). */
uint16_t enemy_climb_up_right_start(uint16_t object)
{
	uint16_t floor_level = 0, speeds_table = 0;
	uint8_t enemy_class = 0, step_level = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x84u;
	step_level = OBJECT(object)->enemy.step_level;
	floor_level = (uint32_t)step_level << 8;
	speeds_table = set_climb_speed(object, floor_level);
	OBJECT(object)->y_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return speeds_table;
}

/* Moves right while it falls until it lands. */
void enemy_move_right_until_landed(uint16_t object)
{
	OBJECT(object)->x_speed = 0x80;
	enemy_fall_until_landed(object);
}

/* Falls with gravity; once it lands, stops and waits 4 frames. */
void enemy_fall_until_landed(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t ignored16 = 0;
	uint8_t action_step = 0;

	apply_gravity(object, &ignored16, &landed);
	if (landed)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 4u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Hops down a step toward the front: a hop, forward until it lands, waits and thinks again. */
void enemy_hop_down_front(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_hop_down_front_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
		case 12:
		case 18:
			enemy_hop_start(object);
			break;
		case -22:
		case 2:
			enemy_move_front_until_landed(object);
			break;
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
		case 22:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
			enemy_hop_back_start(object);
			break;
		case -16:
		case 8:
			enemy_move_back_until_landed(object);
			break;
		case -10:
		case 14:
			enemy_move_left_until_landed(object);
			break;
		case -4:
		case 20:
			enemy_move_right_until_landed(object);
			break;
		case 24:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 26:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 28:
			enemy_go_straight(object);
			break;
		case 30:
		case 40:
			enemy_walk_start_in_turn(object);
			break;
		case 32:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 34:
			enemy_line_up_near_start(object);
			break;
		case 36:
			enemy_line_up_near_in_depth(object);
			break;
		case 38:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 42:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 44:
		case 88:
			enemy_line_up_start(object);
			break;
		case 46:
		case 90:
			enemy_line_up_in_depth(object);
			break;
		case 48:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 50:
			enemy_keep_distance_start(object);
			break;
		case 52:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 54:
			enemy_keep_distance_back_off(object);
			break;
		case 56:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 58:
			enemy_wait_start(object);
			break;
		case 60:
		case 66:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 62:
			enemy_back_off_start(object);
			break;
		case 64:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 68:
			enemy_step_toward_target_start(object);
			break;
		case 70:
			enemy_step_toward_target_step(object);
			break;
		case 72:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 74:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 76:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 78:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 80:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 82:
			enemy_rush_start(object);
			break;
		case 84:
			enemy_rush_step(object);
			break;
		case 86:
			enemy_rush_slow_down(object);
			break;
		case 92:
			enemy_pace_start(object);
			break;
		case 94:
			enemy_pace_step(object);
			break;
		case 96:
			enemy_pace_end(object);
			break;
		case -48:
			enemy_climb(object, &step_handlers, p_left_caller);
			break;
		case -40:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -38:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -36:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -34:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -32:
			continue;
		case -30:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -28:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -26:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -24:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -18:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case -12:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case -6:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation and a hop up. */
void enemy_hop_start(uint16_t object)
{
	uint8_t enemy_class = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x84u;
	OBJECT(object)->z_speed = 0x600;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Hops down a step toward the back: a hop, back until it lands, waits and thinks again. */
void enemy_hop_down_back(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_hop_down_back_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case 0:
			enemy_hop_back_start(object);
			break;
		case -22:
		case 2:
			enemy_move_back_until_landed(object);
			break;
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
		case 16:
			enemy_back_to_thinking_after_wait(object);
			break;
		case -6:
		case 6:
		case 12:
			enemy_hop_start(object);
			break;
		case -16:
		case 8:
			enemy_move_left_until_landed(object);
			break;
		case -10:
		case 14:
			enemy_move_right_until_landed(object);
			break;
		case 18:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 20:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 22:
			enemy_go_straight(object);
			break;
		case 24:
		case 34:
			enemy_walk_start_in_turn(object);
			break;
		case 26:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 28:
			enemy_line_up_near_start(object);
			break;
		case 30:
			enemy_line_up_near_in_depth(object);
			break;
		case 32:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 36:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 38:
		case 82:
			enemy_line_up_start(object);
			break;
		case 40:
		case 84:
			enemy_line_up_in_depth(object);
			break;
		case 42:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 44:
			enemy_keep_distance_start(object);
			break;
		case 46:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 48:
			enemy_keep_distance_back_off(object);
			break;
		case 50:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 52:
			enemy_wait_start(object);
			break;
		case 54:
		case 60:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 56:
			enemy_back_off_start(object);
			break;
		case 58:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 62:
			enemy_step_toward_target_start(object);
			break;
		case 64:
			enemy_step_toward_target_step(object);
			break;
		case 66:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 68:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 70:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 72:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 74:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 76:
			enemy_rush_start(object);
			break;
		case 78:
			enemy_rush_step(object);
			break;
		case 80:
			enemy_rush_slow_down(object);
			break;
		case 86:
			enemy_pace_start(object);
			break;
		case 88:
			enemy_pace_step(object);
			break;
		case 90:
			enemy_pace_end(object);
			break;
		case -46:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -44:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -42:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -40:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -38:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -36:
			continue;
		case -34:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -32:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -30:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -28:
		case -4:
			enemy_move_front_until_landed(object);
			break;
		case -24:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case -18:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case -12:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Out of the hit checks, the jump animation facing the back and a hop up. */
void enemy_hop_back_start(uint16_t object)
{
	uint8_t enemy_class = 0, action_step = 0;

	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
		OBJECT(object)->animation = 0x85u;
	OBJECT(object)->z_speed = 0x600;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Hops down a step to the left: a hop, left until it lands, waits and thinks again. */
void enemy_hop_down_left(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_hop_down_left_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case -12:
		case 0:
		case 6:
			enemy_hop_start(object);
			break;
		case -22:
		case 2:
			enemy_move_left_until_landed(object);
			break;
		case -32:
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
		case 10:
			enemy_back_to_thinking_after_wait(object);
			break;
		case -16:
		case 8:
			enemy_move_right_until_landed(object);
			break;
		case 12:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 14:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 16:
			enemy_go_straight(object);
			break;
		case 18:
		case 28:
			enemy_walk_start_in_turn(object);
			break;
		case 20:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 22:
			enemy_line_up_near_start(object);
			break;
		case 24:
			enemy_line_up_near_in_depth(object);
			break;
		case 26:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 30:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 32:
		case 76:
			enemy_line_up_start(object);
			break;
		case 34:
		case 78:
			enemy_line_up_in_depth(object);
			break;
		case 36:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 38:
			enemy_keep_distance_start(object);
			break;
		case 40:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 42:
			enemy_keep_distance_back_off(object);
			break;
		case 44:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 46:
			enemy_wait_start(object);
			break;
		case 48:
		case 54:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 50:
			enemy_back_off_start(object);
			break;
		case 52:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 56:
			enemy_step_toward_target_start(object);
			break;
		case 58:
			enemy_step_toward_target_step(object);
			break;
		case 60:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 62:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 64:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 66:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 68:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 70:
			enemy_rush_start(object);
			break;
		case 72:
			enemy_rush_step(object);
			break;
		case 74:
			enemy_rush_slow_down(object);
			break;
		case 80:
			enemy_pace_start(object);
			break;
		case 82:
			enemy_pace_step(object);
			break;
		case 84:
			enemy_pace_end(object);
			break;
		case -64:
			enemy_attack(object, &step_handlers, p_left_caller);
			break;
		case -52:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -50:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -48:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -46:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -44:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -42:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -40:
			continue;
		case -38:
			step = step_offset;
			enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
			break;
		case -36:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -34:
		case -10:
			enemy_move_front_until_landed(object);
			break;
		case -30:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case -28:
		case -4:
			enemy_move_back_until_landed(object);
			break;
		case -24:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case -18:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case -6:
			enemy_hop_back_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}

/* Hops down a step to the right: a hop, right until it lands, waits and thinks again. */
void enemy_hop_down_right(uint16_t object, uint8_t step, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	for (;;)
	{
		step_handlers = enemy_hop_down_right_steps_ADDRESS;
		step_offset = (uint32_t)step << 1;
		switch ((int8_t)step_offset)
		{
		case -18:
		case -6:
		case 0:
			enemy_hop_start(object);
			break;
		case -22:
		case 2:
			enemy_move_right_until_landed(object);
			break;
		case -38:
		case -32:
		case -26:
		case -20:
		case -14:
		case -8:
		case -2:
		case 4:
			enemy_back_to_thinking_after_wait(object);
			break;
		case 6:
			step_handlers = enemy_get_around_start(object, step_handlers);
			break;
		case 8:
			step_handlers = enemy_get_around_step(object, step_handlers);
			break;
		case 10:
			enemy_go_straight(object);
			break;
		case 12:
		case 22:
			enemy_walk_start_in_turn(object);
			break;
		case 14:
			step_handlers = enemy_walk_to_target_side_step(object);
			break;
		case 16:
			enemy_line_up_near_start(object);
			break;
		case 18:
			enemy_line_up_near_in_depth(object);
			break;
		case 20:
			step_handlers = enemy_line_up_near_in_x(object, step_handlers);
			break;
		case 24:
			step_handlers = enemy_walk_to_target_step(object);
			break;
		case 26:
		case 70:
			enemy_line_up_start(object);
			break;
		case 28:
		case 72:
			enemy_line_up_in_depth(object);
			break;
		case 30:
			step_handlers = enemy_line_up_in_x(object, step_handlers);
			break;
		case 32:
			enemy_keep_distance_start(object);
			break;
		case 34:
			step_handlers = enemy_keep_distance_step(object, step_handlers);
			break;
		case 36:
			enemy_keep_distance_back_off(object);
			break;
		case 38:
			step_handlers = enemy_keep_distance_close_in(object, step_handlers);
			break;
		case 40:
			enemy_wait_start(object);
			break;
		case 42:
		case 48:
			step_handlers = enemy_wait_for_target_to_stand(object);
			break;
		case 44:
			enemy_back_off_start(object);
			break;
		case 46:
			step_handlers = enemy_back_off_step(object, step_handlers);
			break;
		case 50:
			enemy_step_toward_target_start(object);
			break;
		case 52:
			enemy_step_toward_target_step(object);
			break;
		case 54:
			step_handlers = enemy_circle_target_start(object, step_handlers);
			break;
		case 56:
			step_handlers = enemy_circle_target_step(object, step_handlers);
			break;
		case 58:
			step_handlers = enemy_wander_start(object, step_handlers);
			break;
		case 60:
			step_handlers = enemy_wander_walk(object, step_handlers);
			break;
		case 62:
			step_handlers = enemy_wander_rest(object, step_handlers);
			break;
		case 64:
			enemy_rush_start(object);
			break;
		case 66:
			enemy_rush_step(object);
			break;
		case 68:
			enemy_rush_slow_down(object);
			break;
		case 74:
			enemy_pace_start(object);
			break;
		case 76:
			enemy_pace_step(object);
			break;
		case 78:
			enemy_pace_end(object);
			break;
		case 96:
			enemy_flinch_from_behind_start(object);
			break;
		case 112:
			enemy_knocked_back_start(object);
			break;
		case -58:
			step = step_offset;
			enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
			break;
		case -56:
			step = step_offset;
			enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
			break;
		case -54:
			step = step_offset;
			enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
			break;
		case -52:
			step = step_offset;
			enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
			break;
		case -50:
			step = step_offset;
			enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
			break;
		case -48:
			step = step_offset;
			enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
			break;
		case -46:
			step = step_offset;
			enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
			break;
		case -44:
			continue;
		case -42:
			step_handlers = enemy_climb_up_front_start(object);
			break;
		case -40:
		case -16:
			enemy_move_front_until_landed(object);
			break;
		case -36:
			step_handlers = enemy_climb_up_back_start(object);
			break;
		case -34:
		case -10:
			enemy_move_back_until_landed(object);
			break;
		case -30:
			step_handlers = enemy_climb_up_left_start(object);
			break;
		case -28:
		case -4:
			enemy_move_left_until_landed(object);
			break;
		case -24:
			step_handlers = enemy_climb_up_right_start(object);
			break;
		case -12:
			enemy_hop_back_start(object);
			break;
		}
		break;
	}
	*p_step_handlers = step_handlers;
}
