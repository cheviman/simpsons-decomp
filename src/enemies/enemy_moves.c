/**
 *    Name:        enemies/enemy_moves.c
 *    Description: the moves an enemy's behaviour picks while it thinks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Faces the target; an enemy with walk animations by direction also keeps the direction and picks its
   walk animation. */
void enemy_face_noting_direction(uint16_t object)
{
	uint8_t enemy_class = 0;

	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_pick_walk_animation_noting_direction(object);
		return;
	}
	enemy_face_target(object);
}

/* Faces the target; an enemy with walk animations by direction also picks its walk animation. */
void enemy_face_with_animation(uint16_t object)
{
	uint8_t enemy_class = 0;

	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_pick_walk_animation(object);
		return;
	}
	enemy_face_target(object);
}

/* Unused: moves the enemy at an angle to its target's direction, slower in depth. */
void unused_enemy_move_aside(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t heading = 0;
	uint8_t target_direction = 0, t1 = 0;
	uint16_t y_speed = 0;

	target_direction = OBJECT(object)->target_direction;
	angle = target_direction;
	t1 = OBJECT(object)->unk_3D;
	if (t1 != 0u)
		angle += 0x60u;
	else
		angle -= 0x20u;
	heading = ((uint32_t)angle << 8) | 0x30u;
	set_speeds_from_direction(object, heading);
	y_speed = OBJECT(object)->y_speed;
	OBJECT(object)->y_speed = (int16_t)y_speed >> 1;
}

/* Move 13, taken before ground it cannot walk on: walks at an angle to its target, the other way round
   each time it is stopped, then a stretch straight on. */
void enemy_get_around(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = 0, step_offset = 0;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = enemy_get_around_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	d = step_offset;
	switch ((int8_t)step_offset)
	{
	case 0:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case 2:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case 4:
		enemy_go_straight(object);
		break;
	case 6:
	case 16:
		enemy_walk_start_in_turn(object);
		break;
	case 8:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case 10:
		enemy_line_up_near_start(object);
		break;
	case 12:
		enemy_line_up_near_in_depth(object);
		break;
	case 14:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case 18:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case 20:
	case 64:
		enemy_line_up_start(object);
		break;
	case 22:
	case 66:
		enemy_line_up_in_depth(object);
		break;
	case 24:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 26:
		enemy_keep_distance_start(object);
		break;
	case 28:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 30:
		enemy_keep_distance_back_off(object);
		break;
	case 32:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 34:
		enemy_wait_start(object);
		break;
	case 36:
	case 42:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 38:
		enemy_back_off_start(object);
		break;
	case 40:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 44:
		enemy_step_toward_target_start(object);
		break;
	case 46:
		enemy_step_toward_target_step(object);
		break;
	case 48:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 50:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 52:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 54:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 56:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 58:
		enemy_rush_start(object);
		break;
	case 60:
		enemy_rush_step(object);
		break;
	case 62:
		enemy_rush_slow_down(object);
		break;
	case 68:
		enemy_pace_start(object);
		break;
	case 70:
		enemy_pace_step(object);
		break;
	case 72:
		enemy_pace_end(object);
		break;
	case -64:
		enemy_climb_up_front(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -62:
		enemy_climb_up_back(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -60:
		enemy_climb_up_left(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -58:
		enemy_climb_up_right(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -56:
		enemy_hop_down_front(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -54:
		enemy_hop_down_back(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -52:
		enemy_hop_down_left(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -50:
		enemy_hop_down_right(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -48:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -46:
	case -22:
		enemy_move_front_until_landed(object);
		break;
	case -44:
	case -38:
	case -32:
	case -26:
	case -20:
	case -14:
	case -8:
	case -2:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -42:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -40:
	case -16:
		enemy_move_back_until_landed(object);
		break;
	case -36:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -34:
	case -10:
		enemy_move_left_until_landed(object);
		break;
	case -30:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -28:
	case -4:
		enemy_move_right_until_landed(object);
		break;
	case -24:
	case -12:
	case -6:
		enemy_hop_start(object);
		break;
	case -18:
		enemy_hop_back_start(object);
		break;
	}
	action_step = OBJECT(object)->action_step;
	if (action_step != 0u)
		enemy_face_noting_direction(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Walks for 96 frames, 3 tries, at an angle to its target to a random side. */
uint16_t enemy_get_around_start(uint16_t object, uint16_t step_handlers)
{
	uint8_t enemy_class = 0, action_step = 0;

	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class == 0u)
		OBJECT(object)->animation = 0x81u;
	else
		enemy_restart_walk_animation(object);
	OBJECT(object)->timer = 0x60u;
	OBJECT(object)->enemy.count = 3u;
	if ((int8_t)random_number >= 0)
		OBJECT(object)->enemy.way_round = 0xFFu;
	else
		OBJECT(object)->enemy.way_round = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return enemy_aim_beside_target(object, step_handlers);
}

/* Aims again at the angle when the direction to its target changes, the other way round when stopped;
   after 3 stops goes straight for 16 frames; out of time, gives the target's side back. */
uint16_t enemy_get_around_step(uint16_t object, uint16_t step_handlers)
{
	uint16_t target = 0;
	uint8_t timer = 0, blocked = 0, target_direction = 0, aimed_direction = 0, count = 0, way_round = 0, blocked_2 = 0, action_step = 0;
	uint16_t target_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		target_2 = OBJECT(object)->target;
		target = target_2;
		enemy_leave_side_if_holding(object, target);
		return target;
	}
	blocked = OBJECT(object)->blocked;
	if ((int8_t)blocked >= 0)
	{
		target_direction = OBJECT(object)->target_direction;
		aimed_direction = OBJECT(object)->enemy.aimed_direction;
		if (target_direction != aimed_direction)
			return enemy_aim_beside_target(object, step_handlers);
		return step_handlers;
	}
	count = OBJECT(object)->enemy.count;
	OBJECT(object)->enemy.count = count - 1u;
	if (count != 1u)
	{
		way_round = OBJECT(object)->enemy.way_round;
		OBJECT(object)->enemy.way_round = ~way_round;
		return enemy_aim_beside_target(object, step_handlers);
	}
	OBJECT(object)->timer = 0x10u;
	blocked_2 = OBJECT(object)->blocked;
	if ((blocked_2 & 2u) != 0u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = -0x100;
	}
	else
	{
		OBJECT(object)->x_speed = 0x100;
		OBJECT(object)->y_speed = 0;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return step_handlers;
}

/* Goes on as it is while its timer runs. */
void enemy_go_straight(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
}

/* Move 12: walks to a point 80 pixels to the side of its target, then at it once level with it in depth. */
void enemy_walk_to_target_side(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_walk_to_target_side_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
	case 10:
		enemy_walk_start_in_turn(object);
		break;
	case 2:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case 4:
		enemy_line_up_near_start(object);
		break;
	case 6:
		enemy_line_up_near_in_depth(object);
		break;
	case 8:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case 12:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case 14:
	case 58:
		enemy_line_up_start(object);
		break;
	case 16:
	case 60:
		enemy_line_up_in_depth(object);
		break;
	case 18:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 20:
		enemy_keep_distance_start(object);
		break;
	case 22:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 24:
		enemy_keep_distance_back_off(object);
		break;
	case 26:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 28:
		enemy_wait_start(object);
		break;
	case 30:
	case 36:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 32:
		enemy_back_off_start(object);
		break;
	case 34:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 38:
		enemy_step_toward_target_start(object);
		break;
	case 40:
		enemy_step_toward_target_step(object);
		break;
	case 42:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 44:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 46:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 48:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 50:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 52:
		enemy_rush_start(object);
		break;
	case 54:
		enemy_rush_step(object);
		break;
	case 56:
		enemy_rush_slow_down(object);
		break;
	case 62:
		enemy_pace_start(object);
		break;
	case 64:
		enemy_pace_step(object);
		break;
	case 66:
		enemy_pace_end(object);
		break;
	case -70:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -68:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -66:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -64:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -62:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -60:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -58:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -56:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -54:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -52:
	case -28:
		enemy_move_front_until_landed(object);
		break;
	case -50:
	case -44:
	case -38:
	case -32:
	case -26:
	case -20:
	case -14:
	case -8:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -48:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -46:
	case -22:
		enemy_move_back_until_landed(object);
		break;
	case -42:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -40:
	case -16:
		enemy_move_left_until_landed(object);
		break;
	case -36:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -34:
	case -10:
		enemy_move_right_until_landed(object);
		break;
	case -30:
	case -18:
	case -12:
		enemy_hop_start(object);
		break;
	case -24:
		enemy_hop_back_start(object);
		break;
	case -6:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -4:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -2:
		enemy_go_straight(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Every 8 frames aims at the point 80 pixels to the side of its target (at the target itself once level
   with it in depth); on another floor, walks its way and looks for a way up. */
uint16_t enemy_walk_to_target_side_step(uint16_t object)
{
	uint8_t angle = 0, side_offset = 0;
	uint16_t direction = 0, object_2 = 0;
	uint8_t timer = 0, blocked = 0, target_direction = 0, timer_2 = 0, blocked_2 = 0, target_direction_2 = 0;
	uint16_t target = 0, floor_z = 0, floor_z_2 = 0, target_dy = 0;

	enemy_face_with_animation(object);
	target = OBJECT(object)->target;
	object_2 = target;
	floor_z = OBJECT(object)->floor_z;
	floor_z_2 = OBJECT(object_2)->floor_z;
	if (floor_z == floor_z_2)
	{
		target_dy = OBJECT(object)->target_dy;
		if (target_dy >= 8u)
		{
			timer = OBJECT(object)->timer;
			OBJECT(object)->timer = timer - 1u;
			if (timer != 1u)
			{
				blocked = OBJECT(object)->blocked;
				if ((blocked & 8u) != 0u)
				{
					OBJECT(object)->action = 0xDu;
					OBJECT(object)->action_step = 0u;
				}
				return object_2;
			}
			OBJECT(object)->timer = 8u;
			side_offset = 0x50u;
			target_direction = OBJECT(object)->target_direction;
			if ((int8_t)(target_direction - 0x40u) < 0)
				side_offset = 0u - side_offset;
			direction = side_offset;
			direction = direction_to_beside(object, object_2, (uint8_t)direction);
			angle = (uint8_t)(direction >> 8);
			direction = (direction & 0xFFu) | ((uint32_t)angle << 8);
			object_2 = set_walk_speeds_from_direction(object, object_2, direction);
			blocked = OBJECT(object)->blocked;
			if ((blocked & 8u) != 0u)
			{
				OBJECT(object)->action = 0xDu;
				OBJECT(object)->action_step = 0u;
			}
			return object_2;
		}
		timer_2 = OBJECT(object)->timer;
		OBJECT(object)->timer = timer_2 - 1u;
		if (timer_2 != 1u)
		{
			blocked = OBJECT(object)->blocked;
			if ((blocked & 8u) != 0u)
			{
				OBJECT(object)->action = 0xDu;
				OBJECT(object)->action_step = 0u;
			}
			return object_2;
		}
		OBJECT(object)->timer = 8u;
		direction = direction_to(object, object_2);
		return set_walk_speeds_from_direction(object, object_2, direction);
	}
	blocked_2 = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked_2 | 0x10u;
	target_direction_2 = OBJECT(object)->target_direction;
	angle = target_direction_2;
	direction = (direction & 0xFFu) | ((uint32_t)angle << 8);
	object_2 = set_walk_speeds_from_direction(object, object_2, direction);
	blocked = OBJECT(object)->blocked;
	if ((blocked & 8u) != 0u)
	{
		OBJECT(object)->action = 0xDu;
		OBJECT(object)->action_step = 0u;
	}
	return object_2;
}

/* Move 10: walks level with its target in depth, then toward it in x, stopping 32 pixels short, at 1
   pixel a frame. */
void enemy_line_up_near_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_line_up_near_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		enemy_line_up_near_start(object);
		break;
	case 2:
		enemy_line_up_near_in_depth(object);
		break;
	case 4:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -4:
	case 6:
		enemy_walk_start_in_turn(object);
		break;
	case 8:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case 10:
	case 54:
		enemy_line_up_start(object);
		break;
	case 12:
	case 56:
		enemy_line_up_in_depth(object);
		break;
	case 14:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 16:
		enemy_keep_distance_start(object);
		break;
	case 18:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 20:
		enemy_keep_distance_back_off(object);
		break;
	case 22:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 24:
		enemy_wait_start(object);
		break;
	case 26:
	case 32:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 28:
		enemy_back_off_start(object);
		break;
	case 30:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 34:
		enemy_step_toward_target_start(object);
		break;
	case 36:
		enemy_step_toward_target_step(object);
		break;
	case 38:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 40:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 42:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 44:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 46:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 48:
		enemy_rush_start(object);
		break;
	case 50:
		enemy_rush_step(object);
		break;
	case 52:
		enemy_rush_slow_down(object);
		break;
	case 58:
		enemy_pace_start(object);
		break;
	case 60:
		enemy_pace_step(object);
		break;
	case 62:
		enemy_pace_end(object);
		break;
	case -74:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -72:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -70:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -68:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -66:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -64:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -62:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -60:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -58:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -56:
	case -32:
		enemy_move_front_until_landed(object);
		break;
	case -54:
	case -48:
	case -42:
	case -36:
	case -30:
	case -24:
	case -18:
	case -12:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -52:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -50:
	case -26:
		enemy_move_back_until_landed(object);
		break;
	case -46:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -44:
	case -20:
		enemy_move_left_until_landed(object);
		break;
	case -40:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -38:
	case -14:
		enemy_move_right_until_landed(object);
		break;
	case -34:
	case -22:
	case -16:
		enemy_hop_start(object);
		break;
	case -28:
		enemy_hop_back_start(object);
		break;
	case -10:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -8:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -6:
		enemy_go_straight(object);
		break;
	case -2:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* A long timer, the next step, and the walk animation. */
void enemy_line_up_near_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 0xFFu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_restart_walk_animation(object);
}

/* Walks to its target's depth at 1 pixel a frame (sideways first when close in x), on to the next step
   once within 3. */
void enemy_line_up_near_in_depth(uint16_t object)
{
	uint8_t timer = 0, side = 0, target_direction = 0, side_2 = 0, action_step = 0, blocked = 0, target_direction_2 = 0;
	uint16_t target_dx = 0, x_speed = 0, target_dy = 0, y_speed = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x40u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->x_speed = 0x100;
		side = OBJECT(object)->enemy.side;
		if ((int8_t)side < 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
	{
		target_direction = OBJECT(object)->target_direction;
		side_2 = OBJECT(object)->enemy.side;
		if ((int8_t)(target_direction - 0x40u - side_2) < 0)
		{
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->x_speed = 0x100;
			side = OBJECT(object)->enemy.side;
			if ((int8_t)side < 0)
			{
				x_speed = OBJECT(object)->x_speed;
				OBJECT(object)->x_speed = 0u - x_speed;
			}
			target_dy = OBJECT(object)->target_dy;
			if (target_dy < 3u)
			{
				action_step = OBJECT(object)->action_step;
				OBJECT(object)->action_step = action_step + 1u;
			}
			blocked = OBJECT(object)->blocked;
			if ((blocked & 8u) != 0u)
			{
				OBJECT(object)->action = 0xDu;
				OBJECT(object)->action_step = 0u;
			}
			return;
		}
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0x100;
		target_direction_2 = OBJECT(object)->target_direction;
		if ((int8_t)target_direction_2 < 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 3u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	blocked = OBJECT(object)->blocked;
	if ((blocked & 8u) != 0u)
	{
		OBJECT(object)->action = 0xDu;
		OBJECT(object)->action_step = 0u;
	}
}

/* Walks toward its target in x at 1 pixel a frame until 32 pixels short, back a step when out of line in
   depth; close but on another floor, it walks at the target instead. */
uint16_t enemy_line_up_near_in_x(uint16_t object, uint16_t object_2)
{
	uint8_t timer = 0, target_direction = 0, action_step = 0;
	uint16_t target_dx = 0, x_speed = 0, target_dy = 0, target_dx_2 = 0, target = 0, floor_z = 0, floor_z_2 = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x20u)
	{
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->x_speed = 0x100;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)(((uint16_t)((uint32_t)target_direction << 8) >> 8) - 0x40u) >= 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
		OBJECT(object)->x_speed = 0;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 3u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step - 1u;
		return object_2;
	}
	target_dx_2 = OBJECT(object)->target_dx;
	if (target_dx_2 < 0x20u)
	{
		target = OBJECT(object)->target;
		object_2 = target;
		floor_z = OBJECT(object)->floor_z;
		floor_z_2 = OBJECT(object_2)->floor_z;
		if (floor_z != floor_z_2)
		{
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
		}
	}
	return object_2;
}

/* Move 0: walks straight at its target, aiming again every 8 frames, after a delay each enemy gets in
   turn. */
void enemy_walk_to_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_walk_to_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case -10:
	case 0:
		enemy_walk_start_in_turn(object);
		break;
	case 2:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case 4:
	case 48:
		enemy_line_up_start(object);
		break;
	case 6:
	case 50:
		enemy_line_up_in_depth(object);
		break;
	case 8:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 10:
		enemy_keep_distance_start(object);
		break;
	case 12:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 14:
		enemy_keep_distance_back_off(object);
		break;
	case 16:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 18:
		enemy_wait_start(object);
		break;
	case 20:
	case 26:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 22:
		enemy_back_off_start(object);
		break;
	case 24:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 28:
		enemy_step_toward_target_start(object);
		break;
	case 30:
		enemy_step_toward_target_step(object);
		break;
	case 32:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 34:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 36:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 38:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 40:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 42:
		enemy_rush_start(object);
		break;
	case 44:
		enemy_rush_step(object);
		break;
	case 46:
		enemy_rush_slow_down(object);
		break;
	case 52:
		enemy_pace_start(object);
		break;
	case 54:
		enemy_pace_step(object);
		break;
	case 56:
		enemy_pace_end(object);
		break;
	case -80:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -78:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -76:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -74:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -72:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -70:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -68:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -66:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -64:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -62:
	case -38:
		enemy_move_front_until_landed(object);
		break;
	case -60:
	case -54:
	case -48:
	case -42:
	case -36:
	case -30:
	case -24:
	case -18:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -58:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -56:
	case -32:
		enemy_move_back_until_landed(object);
		break;
	case -52:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -50:
	case -26:
		enemy_move_left_until_landed(object);
		break;
	case -46:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -44:
	case -20:
		enemy_move_right_until_landed(object);
		break;
	case -40:
	case -28:
	case -22:
		enemy_hop_start(object);
		break;
	case -34:
		enemy_hop_back_start(object);
		break;
	case -16:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -14:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -12:
		enemy_go_straight(object);
		break;
	case -8:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -6:
		enemy_line_up_near_start(object);
		break;
	case -4:
		enemy_line_up_near_in_depth(object);
		break;
	case -2:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Takes the next of the delays the enemies take in turn this frame and starts the walk animation. */
void enemy_walk_start_in_turn(uint16_t object)
{
	uint8_t t1 = 0, t2 = 0, action_step = 0, enemy_class = 0;

	t1 = io_read8(0x1878u);
	io_write8(0x1878u, t1 + 1u);
	t2 = io_read8(0x1878u);
	OBJECT(object)->timer = t2;
	OBJECT(object)->animation = 0x81u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_restart_walk_animation(object);
		return;
	}
	OBJECT(object)->animation = 0x81u;
}

/* Every 8 frames aims at its target and walks that way, stopping within 32 pixels of it; on another
   floor, walks its way and looks for a way up. */
uint16_t enemy_walk_to_target_step(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t direction = 0, object_2 = 0;
	uint8_t timer = 0, blocked = 0, blocked_2 = 0, target_direction = 0;
	uint16_t target = 0, floor_z = 0, floor_z_2 = 0, target_dx = 0, target_dy = 0;

	enemy_face_with_animation(object);
	target = OBJECT(object)->target;
	object_2 = target;
	floor_z = OBJECT(object)->floor_z;
	direction = floor_z;
	floor_z_2 = OBJECT(object_2)->floor_z;
	if ((uint16_t)(((uint32_t)(floor_z >> 8) << 8) | (direction & 0xFFu)) == floor_z_2)
	{
		target_dx = OBJECT(object)->target_dx;
		if (target_dx < 0x20u)
		{
			target_dy = OBJECT(object)->target_dy;
			if (target_dy < 0x20u)
			{
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				return object_2;
			}
		}
		timer = OBJECT(object)->timer;
		OBJECT(object)->timer = timer - 1u;
		if (timer != 1u)
		{
			blocked = OBJECT(object)->blocked;
			if ((blocked & 8u) != 0u)
			{
				OBJECT(object)->action = 0xDu;
				OBJECT(object)->action_step = 0u;
			}
			return object_2;
		}
		OBJECT(object)->timer = 8u;
		direction = direction_to(object, object_2);
		angle = (uint8_t)(direction >> 8);
	}
	else
	{
		blocked_2 = OBJECT(object)->blocked;
		OBJECT(object)->blocked = blocked_2 | 0x10u;
		target_direction = OBJECT(object)->target_direction;
		angle = target_direction;
	}
	direction = (direction & 0xFFu) | ((uint32_t)angle << 8);
	object_2 = set_walk_speeds_from_direction(object, object_2, direction);
	blocked = OBJECT(object)->blocked;
	if ((blocked & 8u) != 0u)
	{
		OBJECT(object)->action = 0xDu;
		OBJECT(object)->action_step = 0u;
	}
	return object_2;
}

/* Move 1: walks level with its target in depth, then toward it in x until 16 pixels short, at the
   enemies' speed. */
void enemy_line_up_with_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_line_up_with_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
	case 44:
		enemy_line_up_start(object);
		break;
	case 2:
	case 46:
		enemy_line_up_in_depth(object);
		break;
	case 4:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 6:
		enemy_keep_distance_start(object);
		break;
	case 8:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 10:
		enemy_keep_distance_back_off(object);
		break;
	case 12:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 14:
		enemy_wait_start(object);
		break;
	case 16:
	case 22:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 18:
		enemy_back_off_start(object);
		break;
	case 20:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 24:
		enemy_step_toward_target_start(object);
		break;
	case 26:
		enemy_step_toward_target_step(object);
		break;
	case 28:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 30:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 32:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 34:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 36:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 38:
		enemy_rush_start(object);
		break;
	case 40:
		enemy_rush_step(object);
		break;
	case 42:
		enemy_rush_slow_down(object);
		break;
	case 48:
		enemy_pace_start(object);
		break;
	case 50:
		enemy_pace_step(object);
		break;
	case 52:
		enemy_pace_end(object);
		break;
	case -84:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -82:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -80:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -78:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -76:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -74:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -72:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -70:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -68:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -66:
	case -42:
		enemy_move_front_until_landed(object);
		break;
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
	case -34:
	case -28:
	case -22:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -62:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -60:
	case -36:
		enemy_move_back_until_landed(object);
		break;
	case -56:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -54:
	case -30:
		enemy_move_left_until_landed(object);
		break;
	case -50:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -48:
	case -24:
		enemy_move_right_until_landed(object);
		break;
	case -44:
	case -32:
	case -26:
		enemy_hop_start(object);
		break;
	case -38:
		enemy_hop_back_start(object);
		break;
	case -20:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -18:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -16:
		enemy_go_straight(object);
		break;
	case -14:
	case -4:
		enemy_walk_start_in_turn(object);
		break;
	case -12:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -10:
		enemy_line_up_near_start(object);
		break;
	case -8:
		enemy_line_up_near_in_depth(object);
		break;
	case -6:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -2:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* A long timer, the next step, and the walk animation. */
void enemy_line_up_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 0xFFu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_restart_walk_animation(object);
}

/* Walks to its target's depth at the enemies' speed (sideways first when close in x), on to the next
   step once within 3. */
void enemy_line_up_in_depth(uint16_t object)
{
	uint8_t timer = 0, side = 0, target_direction = 0, side_2 = 0, action_step = 0, blocked = 0, target_direction_2 = 0;
	uint16_t target_dx = 0, t1 = 0, x_speed = 0, target_dy = 0, t2 = 0, y_speed = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x20u)
	{
		OBJECT(object)->y_speed = 0;
		t1 = io_read16(0x1886u);
		OBJECT(object)->x_speed = t1;
		side = OBJECT(object)->enemy.side;
		if ((int8_t)side < 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
	{
		target_direction = OBJECT(object)->target_direction;
		side_2 = OBJECT(object)->enemy.side;
		if ((int8_t)(target_direction - 0x40u - side_2) < 0)
		{
			OBJECT(object)->y_speed = 0;
			t1 = io_read16(0x1886u);
			OBJECT(object)->x_speed = t1;
			side = OBJECT(object)->enemy.side;
			if ((int8_t)side < 0)
			{
				x_speed = OBJECT(object)->x_speed;
				OBJECT(object)->x_speed = 0u - x_speed;
			}
			target_dy = OBJECT(object)->target_dy;
			if (target_dy < 3u)
			{
				action_step = OBJECT(object)->action_step;
				OBJECT(object)->action_step = action_step + 1u;
			}
			blocked = OBJECT(object)->blocked;
			if ((blocked & 8u) != 0u)
			{
				OBJECT(object)->action = 0xDu;
				OBJECT(object)->action_step = 0u;
			}
			return;
		}
		OBJECT(object)->x_speed = 0;
		t2 = io_read16(0x1886u);
		OBJECT(object)->y_speed = t2;
		target_direction_2 = OBJECT(object)->target_direction;
		if ((int8_t)target_direction_2 < 0)
		{
			y_speed = OBJECT(object)->y_speed;
			OBJECT(object)->y_speed = 0u - y_speed;
		}
	}
	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 3u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	blocked = OBJECT(object)->blocked;
	if ((blocked & 8u) != 0u)
	{
		OBJECT(object)->action = 0xDu;
		OBJECT(object)->action_step = 0u;
	}
}

/* Walks toward its target in x at the enemies' speed until 16 pixels short, back a step when out of line
   in depth; close but on another floor, it walks at the target instead. */
uint16_t enemy_line_up_in_x(uint16_t object, uint16_t object_2)
{
	uint8_t timer = 0, target_direction = 0, action_step = 0;
	uint16_t target_dx = 0, t1 = 0, x_speed = 0, target_dy = 0, target_dx_2 = 0, target = 0, floor_z = 0, floor_z_2 = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx >= 0x10u)
	{
		OBJECT(object)->y_speed = 0;
		t1 = io_read16(0x1886u);
		OBJECT(object)->x_speed = t1;
		target_direction = OBJECT(object)->target_direction;
		if ((int8_t)(((uint16_t)((uint32_t)target_direction << 8) >> 8) - 0x40u) >= 0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
	}
	else
		OBJECT(object)->x_speed = 0;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy >= 3u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step - 1u;
		return object_2;
	}
	target_dx_2 = OBJECT(object)->target_dx;
	if (target_dx_2 < 0x10u)
	{
		target = OBJECT(object)->target;
		object_2 = target;
		floor_z = OBJECT(object)->floor_z;
		floor_z_2 = OBJECT(object_2)->floor_z;
		if (floor_z != floor_z_2)
		{
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
		}
	}
	return object_2;
}

/* Move 2: keeps its distance from its target: backs off when it is too close, comes closer when it is
   far, and stands facing it in between. */
void enemy_keep_distance(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_keep_distance_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		enemy_keep_distance_start(object);
		break;
	case 2:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 4:
		enemy_keep_distance_back_off(object);
		break;
	case 6:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 8:
		enemy_wait_start(object);
		break;
	case 10:
	case 16:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 12:
		enemy_back_off_start(object);
		break;
	case 14:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 18:
		enemy_step_toward_target_start(object);
		break;
	case 20:
		enemy_step_toward_target_step(object);
		break;
	case 22:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 24:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 26:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 28:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 30:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 32:
		enemy_rush_start(object);
		break;
	case 34:
		enemy_rush_step(object);
		break;
	case 36:
		enemy_rush_slow_down(object);
		break;
	case -6:
	case 38:
		enemy_line_up_start(object);
		break;
	case -4:
	case 40:
		enemy_line_up_in_depth(object);
		break;
	case 42:
		enemy_pace_start(object);
		break;
	case 44:
		enemy_pace_step(object);
		break;
	case 46:
		enemy_pace_end(object);
		break;
	case -90:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -88:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -86:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -84:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -82:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -80:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -78:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -76:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -74:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -72:
	case -48:
		enemy_move_front_until_landed(object);
		break;
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
	case -34:
	case -28:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -68:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -66:
	case -42:
		enemy_move_back_until_landed(object);
		break;
	case -62:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -60:
	case -36:
		enemy_move_left_until_landed(object);
		break;
	case -56:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -54:
	case -30:
		enemy_move_right_until_landed(object);
		break;
	case -50:
	case -38:
	case -32:
		enemy_hop_start(object);
		break;
	case -44:
		enemy_hop_back_start(object);
		break;
	case -26:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -24:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -22:
		enemy_go_straight(object);
		break;
	case -20:
	case -10:
		enemy_walk_start_in_turn(object);
		break;
	case -18:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -16:
		enemy_line_up_near_start(object);
		break;
	case -14:
		enemy_line_up_near_in_depth(object);
		break;
	case -12:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -8:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -2:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* A long timer, the next step, and the walk animation. */
void enemy_keep_distance_start(uint16_t object)
{
	uint8_t action_step = 0, enemy_class = 0;

	OBJECT(object)->timer = 0xFFu;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_restart_walk_animation(object);
		return;
	}
	OBJECT(object)->animation = 0x81u;
}

/* Within 80 pixels in x and 32 in depth of its target, walks away from it; beyond 112 and 64, walks at
   it; in between, stands facing it. */
uint16_t enemy_keep_distance_step(uint16_t object, uint16_t step_handlers)
{
	uint8_t angle = 0, animation = 0;
	uint16_t direction = 0;
	uint8_t timer = 0, target_direction = 0, action_step = 0, action_step_2 = 0, target_direction_2 = 0, enemy_class = 0, target_direction_3 = 0;
	uint16_t target_dx = 0, target_dy = 0, target_dx_2 = 0, target_dy_2 = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x50u)
	{
		target_dy = OBJECT(object)->target_dy;
		if (target_dy < 0x20u)
		{
			target_direction = OBJECT(object)->target_direction;
			angle = target_direction - 0x80u;
			direction = (uint32_t)angle << 8;
			step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
			OBJECT(object)->animation = 0x81u;
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
			return step_handlers;
		}
	}
	target_dx_2 = OBJECT(object)->target_dx;
	if (target_dx_2 >= 0x70u)
	{
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 + 1u;
		target_direction_2 = OBJECT(object)->target_direction;
		angle = target_direction_2;
		direction = (uint32_t)angle << 8;
		step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
		OBJECT(object)->animation = 0x81u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return step_handlers;
	}
	target_dy_2 = OBJECT(object)->target_dy;
	if (target_dy_2 >= 0x40u)
	{
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 + 1u;
		target_direction_2 = OBJECT(object)->target_direction;
		angle = target_direction_2;
		direction = (uint32_t)angle << 8;
		step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
		OBJECT(object)->animation = 0x81u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return step_handlers;
	}
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		target_direction_3 = OBJECT(object)->target_direction;
		if ((int8_t)target_direction_3 >= 0)
			animation = 0x94u;
		else
			animation = 0x86u;
	}
	else
		animation = 0x87u;
	OBJECT(object)->animation = animation;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	return step_handlers;
}

/* Walks away from its target until it is no longer too close, then looks again. */
void enemy_keep_distance_back_off(uint16_t object)
{
	uint16_t target_dx = 0, target_dy = 0;

	enemy_face_with_animation(object);
	target_dx = OBJECT(object)->target_dx;
	if (target_dx < 0x50u)
	{
		target_dy = OBJECT(object)->target_dy;
		if (target_dy >= 0x20u)
			OBJECT(object)->action_step = 0u;
		return;
	}
	OBJECT(object)->action_step = 0u;
}

/* Walks at its target, aiming again every 16 frames, until it is no longer far, then looks again. */
uint16_t enemy_keep_distance_close_in(uint16_t object, uint16_t step_handlers)
{
	uint8_t d = 0;
	uint16_t direction = 0;
	uint8_t target_direction = 0;
	uint16_t target_dx = 0, target_dy = 0;

	enemy_face_with_animation(object);
	target_dx = OBJECT(object)->target_dx;
	d = (uint8_t)target_dx;
	if ((uint16_t)(((uint32_t)(target_dx >> 8) << 8) | (d & 0xFFu)) >= 0x70u)
	{
		if ((frame_count & 0xFu) == 0u)
		{
			target_direction = OBJECT(object)->target_direction;
			direction = (d & 0xFFu) | ((uint32_t)target_direction << 8);
			step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
		}
		return step_handlers;
	}
	target_dy = OBJECT(object)->target_dy;
	d = (uint8_t)target_dy;
	if ((uint16_t)(((uint32_t)(target_dy >> 8) << 8) | (d & 0xFFu)) < 0x40u)
	{
		OBJECT(object)->action_step = 0u;
		return step_handlers;
	}
	if ((frame_count & 0xFu) == 0u)
	{
		target_direction = OBJECT(object)->target_direction;
		direction = (d & 0xFFu) | ((uint32_t)target_direction << 8);
		step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
	}
	return step_handlers;
}

/* Move 9: stands still while its target is down, stopped when off the screen. */
void enemy_wait_while_target_down(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint16_t t1 = 0;

	step_handlers = enemy_wait_while_target_down_steps_ADDRESS;
	step = (uint8_t)((uint32_t)step << 1);
	switch ((int8_t)step)
	{
	case 0:
		enemy_wait_start(object);
		break;
	case 2:
	case 8:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 4:
		enemy_back_off_start(object);
		break;
	case 6:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 10:
		enemy_step_toward_target_start(object);
		break;
	case 12:
		enemy_step_toward_target_step(object);
		break;
	case 14:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 16:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 18:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 20:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 22:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 24:
		enemy_rush_start(object);
		break;
	case 26:
		enemy_rush_step(object);
		break;
	case 28:
		enemy_rush_slow_down(object);
		break;
	case -14:
	case 30:
		enemy_line_up_start(object);
		break;
	case -12:
	case 32:
		enemy_line_up_in_depth(object);
		break;
	case 34:
		enemy_pace_start(object);
		break;
	case 36:
		enemy_pace_step(object);
		break;
	case 38:
		enemy_pace_end(object);
		break;
	case -98:
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -96:
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -94:
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -92:
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -90:
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -88:
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -86:
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -84:
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -82:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -80:
	case -56:
		enemy_move_front_until_landed(object);
		break;
	case -78:
	case -72:
	case -66:
	case -60:
	case -54:
	case -48:
	case -42:
	case -36:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -76:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -74:
	case -50:
		enemy_move_back_until_landed(object);
		break;
	case -70:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -68:
	case -44:
		enemy_move_left_until_landed(object);
		break;
	case -64:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -62:
	case -38:
		enemy_move_right_until_landed(object);
		break;
	case -58:
	case -46:
	case -40:
		enemy_hop_start(object);
		break;
	case -52:
		enemy_hop_back_start(object);
		break;
	case -34:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -32:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -30:
		enemy_go_straight(object);
		break;
	case -28:
	case -18:
		enemy_walk_start_in_turn(object);
		break;
	case -26:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -24:
		enemy_line_up_near_start(object);
		break;
	case -22:
		enemy_line_up_near_in_depth(object);
		break;
	case -20:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -16:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -10:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -8:
		enemy_keep_distance_start(object);
		break;
	case -6:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -4:
		enemy_keep_distance_back_off(object);
		break;
	case -2:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	}
	t1 = OBJECT(object)->x;
	if (t1 < 0x40 || t1 > 0x17F)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Move 3: backs away from its target for 32 frames, then stands while its target is down, stopped when
   off the screen. */
void enemy_back_off(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint16_t t1 = 0;

	step_handlers = enemy_back_off_steps_ADDRESS;
	step = (uint8_t)((uint32_t)step << 1);
	switch ((int8_t)step)
	{
	case 0:
		enemy_back_off_start(object);
		break;
	case 2:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case -2:
	case 4:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 6:
		enemy_step_toward_target_start(object);
		break;
	case 8:
		enemy_step_toward_target_step(object);
		break;
	case 10:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 12:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 14:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 16:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 18:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 20:
		enemy_rush_start(object);
		break;
	case 22:
		enemy_rush_step(object);
		break;
	case 24:
		enemy_rush_slow_down(object);
		break;
	case -18:
	case 26:
		enemy_line_up_start(object);
		break;
	case -16:
	case 28:
		enemy_line_up_in_depth(object);
		break;
	case 30:
		enemy_pace_start(object);
		break;
	case 32:
		enemy_pace_step(object);
		break;
	case 34:
		enemy_pace_end(object);
		break;
	case -102:
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -100:
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -98:
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -96:
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -94:
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -92:
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -90:
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -88:
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -86:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -84:
	case -60:
		enemy_move_front_until_landed(object);
		break;
	case -82:
	case -76:
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
	case -40:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -80:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -78:
	case -54:
		enemy_move_back_until_landed(object);
		break;
	case -74:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -72:
	case -48:
		enemy_move_left_until_landed(object);
		break;
	case -68:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -66:
	case -42:
		enemy_move_right_until_landed(object);
		break;
	case -62:
	case -50:
	case -44:
		enemy_hop_start(object);
		break;
	case -56:
		enemy_hop_back_start(object);
		break;
	case -38:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -36:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -34:
		enemy_go_straight(object);
		break;
	case -32:
	case -22:
		enemy_walk_start_in_turn(object);
		break;
	case -30:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -28:
		enemy_line_up_near_start(object);
		break;
	case -26:
		enemy_line_up_near_in_depth(object);
		break;
	case -24:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -20:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -14:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -12:
		enemy_keep_distance_start(object);
		break;
	case -10:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -8:
		enemy_keep_distance_back_off(object);
		break;
	case -6:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -4:
		enemy_wait_start(object);
		break;
	}
	t1 = OBJECT(object)->x;
	if (t1 < 0x40 || t1 > 0x17F)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Walks away from its target at 1 pixel a frame for 32 frames, with the walk animation. */
void enemy_back_off_start(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t target_direction = 0, action_step = 0, enemy_class = 0;

	OBJECT(object)->timer = 0x20u;
	target_direction = OBJECT(object)->target_direction;
	heading = ((uint32_t)(uint8_t)(target_direction - 0x80u) << 8) | 0x20u;
	set_speeds_from_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_restart_walk_animation(object);
		return;
	}
	OBJECT(object)->animation = 0x81u;
}

/* When the 32 frames are up: stops and stands for 64 frames, in a pose by whether its target has life
   left. */
uint16_t enemy_back_off_step(uint16_t object, uint16_t target)
{
	uint8_t timer = 0, vitality = 0, action_step = 0, enemy_class = 0;
	uint16_t target_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return target;
	target_2 = OBJECT(object)->target;
	target = target_2;
	vitality = OBJECT(target)->vitality;
	if (vitality != 0u)
	{
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 0x40u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return target;
	}
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class == 0u)
	{
		OBJECT(object)->animation = 0x87u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->timer = 0x40u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return target;
	}
	if ((int8_t)(uint8_t)frame_count < 0)
	{
		enemy_wait_start(object);
		return target;
	}
	OBJECT(object)->animation = 0x93u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return target;
}

/* Stops and stands for 64 frames. */
void enemy_wait_start(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0x87u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->timer = 0x40u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Once its target is no longer down, comes at it again and ends the move. */
uint16_t enemy_wait_for_target_to_stand(uint16_t object)
{
	uint16_t target = 0;
	uint8_t state = 0;
	uint16_t target_2 = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	state = OBJECT(target)->state;
	if ((int8_t)state >= 0)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->timer = 0u;
	}
	return target;
}

/* Move 4: does nothing while its timer runs. */
void enemy_stand_still(void)
{
}

/* Move 5: walks toward its target in x for 64 frames. */
void enemy_step_toward_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_step_toward_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		enemy_step_toward_target_start(object);
		break;
	case 2:
		enemy_step_toward_target_step(object);
		break;
	case 4:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 6:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 8:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 10:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 12:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 14:
		enemy_rush_start(object);
		break;
	case 16:
		enemy_rush_step(object);
		break;
	case 18:
		enemy_rush_slow_down(object);
		break;
	case -24:
	case 20:
		enemy_line_up_start(object);
		break;
	case -22:
	case 22:
		enemy_line_up_in_depth(object);
		break;
	case 24:
		enemy_pace_start(object);
		break;
	case 26:
		enemy_pace_step(object);
		break;
	case 28:
		enemy_pace_end(object);
		break;
	case -108:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -106:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -104:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -102:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -100:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -98:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -96:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -94:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -92:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -90:
	case -66:
		enemy_move_front_until_landed(object);
		break;
	case -88:
	case -82:
	case -76:
	case -70:
	case -64:
	case -58:
	case -52:
	case -46:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -86:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -84:
	case -60:
		enemy_move_back_until_landed(object);
		break;
	case -80:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -78:
	case -54:
		enemy_move_left_until_landed(object);
		break;
	case -74:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -72:
	case -48:
		enemy_move_right_until_landed(object);
		break;
	case -68:
	case -56:
	case -50:
		enemy_hop_start(object);
		break;
	case -62:
		enemy_hop_back_start(object);
		break;
	case -44:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -42:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -40:
		enemy_go_straight(object);
		break;
	case -38:
	case -28:
		enemy_walk_start_in_turn(object);
		break;
	case -36:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -34:
		enemy_line_up_near_start(object);
		break;
	case -32:
		enemy_line_up_near_in_depth(object);
		break;
	case -30:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -26:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -20:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -18:
		enemy_keep_distance_start(object);
		break;
	case -16:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -14:
		enemy_keep_distance_back_off(object);
		break;
	case -12:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -10:
		enemy_wait_start(object);
		break;
	case -8:
	case -2:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case -6:
		enemy_back_off_start(object);
		break;
	case -4:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Walks toward its target in x at 3/4 of a pixel a frame for 64 frames, with the walk animation. */
void enemy_step_toward_target_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0, enemy_class = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x87u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->x_speed = 0xC0;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->y_speed = 0;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class != 0u)
	{
		enemy_restart_walk_animation(object);
		return;
	}
	OBJECT(object)->animation = 0x81u;
}

/* Stops when the 64 frames are up. */
void enemy_step_toward_target_step(uint16_t object)
{
	uint8_t timer = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
		OBJECT(object)->x_speed = 0;
}

/* Move 6: walks round its target at an angle to it, to a random side, turning the other way when
   stopped. */
void enemy_circle_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = 0, step_offset = 0;
	uint16_t step_handlers = 0;
	uint8_t action_step = 0;

	step_handlers = enemy_circle_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	d = step_offset;
	switch ((int8_t)step_offset)
	{
	case 0:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 2:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 4:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 6:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 8:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 10:
		enemy_rush_start(object);
		break;
	case 12:
		enemy_rush_step(object);
		break;
	case 14:
		enemy_rush_slow_down(object);
		break;
	case -28:
	case 16:
		enemy_line_up_start(object);
		break;
	case -26:
	case 18:
		enemy_line_up_in_depth(object);
		break;
	case 20:
		enemy_pace_start(object);
		break;
	case 22:
		enemy_pace_step(object);
		break;
	case 24:
		enemy_pace_end(object);
		break;
	case -112:
		enemy_climb_up_front(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -110:
		enemy_climb_up_back(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -108:
		enemy_climb_up_left(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -106:
		enemy_climb_up_right(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -104:
		enemy_hop_down_front(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -102:
		enemy_hop_down_back(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -100:
		enemy_hop_down_left(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -98:
		enemy_hop_down_right(object, d, &y, &step_handlers, p_left_caller);
		break;
	case -96:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -94:
	case -70:
		enemy_move_front_until_landed(object);
		break;
	case -92:
	case -86:
	case -80:
	case -74:
	case -68:
	case -62:
	case -56:
	case -50:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -90:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -88:
	case -64:
		enemy_move_back_until_landed(object);
		break;
	case -84:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -82:
	case -58:
		enemy_move_left_until_landed(object);
		break;
	case -78:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -76:
	case -52:
		enemy_move_right_until_landed(object);
		break;
	case -72:
	case -60:
	case -54:
		enemy_hop_start(object);
		break;
	case -66:
		enemy_hop_back_start(object);
		break;
	case -48:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -46:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -44:
		enemy_go_straight(object);
		break;
	case -42:
	case -32:
		enemy_walk_start_in_turn(object);
		break;
	case -40:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -38:
		enemy_line_up_near_start(object);
		break;
	case -36:
		enemy_line_up_near_in_depth(object);
		break;
	case -34:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -30:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -24:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -22:
		enemy_keep_distance_start(object);
		break;
	case -20:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -18:
		enemy_keep_distance_back_off(object);
		break;
	case -16:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -14:
		enemy_wait_start(object);
		break;
	case -12:
	case -6:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case -10:
		enemy_back_off_start(object);
		break;
	case -8:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case -4:
		enemy_step_toward_target_start(object);
		break;
	case -2:
		enemy_step_toward_target_step(object);
		break;
	}
	action_step = OBJECT(object)->action_step;
	if (action_step != 0u)
		enemy_face_noting_direction(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* A long timer, a random side, the walk animation, and the walk at an angle to its target. */
uint16_t enemy_circle_target_start(uint16_t object, uint16_t step_handlers)
{
	uint8_t enemy_class = 0, action_step = 0;

	enemy_class = OBJECT(object)->enemy_class;
	if (enemy_class == 0u)
		OBJECT(object)->animation = 0x81u;
	else
		enemy_restart_walk_animation(object);
	OBJECT(object)->timer = 0xFFu;
	if ((int8_t)random_number >= 0)
		OBJECT(object)->enemy.way_round = 0xFFu;
	else
		OBJECT(object)->enemy.way_round = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return enemy_aim_beside_target(object, step_handlers);
}

/* Walks at an angle to its target, to one side or the other, at half speed in depth. */
uint16_t enemy_aim_beside_target(uint16_t object, uint16_t step_handlers)
{
	uint8_t angle = 0;
	uint16_t direction = 0;
	uint8_t target_direction = 0, way_round = 0;
	uint16_t y_speed = 0;

	target_direction = OBJECT(object)->target_direction;
	angle = target_direction;
	way_round = OBJECT(object)->enemy.way_round;
	if (way_round != 0u)
		angle += 0x50u;
	else
		angle -= 0x30u;
	direction = (uint32_t)angle << 8;
	step_handlers = set_walk_speeds_from_direction(object, step_handlers, direction);
	y_speed = OBJECT(object)->y_speed;
	OBJECT(object)->y_speed = (int16_t)y_speed >> 1;
	return step_handlers;
}

/* Aims again when the direction to its target changes, the other way round when stopped. */
uint16_t enemy_circle_target_step(uint16_t object, uint16_t step_handlers)
{
	uint8_t timer = 0, blocked = 0, way_round = 0, target_direction = 0, aimed_direction = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	blocked = OBJECT(object)->blocked;
	if ((int8_t)blocked < 0)
	{
		way_round = OBJECT(object)->enemy.way_round;
		OBJECT(object)->enemy.way_round = ~way_round;
		return enemy_aim_beside_target(object, step_handlers);
	}
	target_direction = OBJECT(object)->target_direction;
	aimed_direction = OBJECT(object)->enemy.aimed_direction;
	if (target_direction != aimed_direction)
		return enemy_aim_beside_target(object, step_handlers);
	return step_handlers;
}

/* Move 11: walks in short turning stretches, a random way round, resting a while after each run of them. */
void enemy_wander(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_wander_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 2:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 4:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 6:
		enemy_rush_start(object);
		break;
	case 8:
		enemy_rush_step(object);
		break;
	case 10:
		enemy_rush_slow_down(object);
		break;
	case -32:
	case 12:
		enemy_line_up_start(object);
		break;
	case -30:
	case 14:
		enemy_line_up_in_depth(object);
		break;
	case 16:
		enemy_pace_start(object);
		break;
	case 18:
		enemy_pace_step(object);
		break;
	case 20:
		enemy_pace_end(object);
		break;
	case -116:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -114:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -112:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -110:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -108:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -106:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -104:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -102:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -100:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -98:
	case -74:
		enemy_move_front_until_landed(object);
		break;
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
	case -60:
	case -54:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -94:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -92:
	case -68:
		enemy_move_back_until_landed(object);
		break;
	case -88:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -86:
	case -62:
		enemy_move_left_until_landed(object);
		break;
	case -82:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -80:
	case -56:
		enemy_move_right_until_landed(object);
		break;
	case -76:
	case -64:
	case -58:
		enemy_hop_start(object);
		break;
	case -70:
		enemy_hop_back_start(object);
		break;
	case -52:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -50:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -48:
		enemy_go_straight(object);
		break;
	case -46:
	case -36:
		enemy_walk_start_in_turn(object);
		break;
	case -44:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -42:
		enemy_line_up_near_start(object);
		break;
	case -40:
		enemy_line_up_near_in_depth(object);
		break;
	case -38:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -34:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -28:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -26:
		enemy_keep_distance_start(object);
		break;
	case -24:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -22:
		enemy_keep_distance_back_off(object);
		break;
	case -20:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -18:
		enemy_wait_start(object);
		break;
	case -16:
	case -10:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case -14:
		enemy_back_off_start(object);
		break;
	case -12:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case -8:
		enemy_step_toward_target_start(object);
		break;
	case -6:
		enemy_step_toward_target_step(object);
		break;
	case -4:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case -2:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Starts from the direction to its target, a random way round, 7 frames a stretch. */
uint16_t enemy_wander_start(uint16_t object, uint16_t step_handlers)
{
	uint8_t target_direction = 0, action_step = 0;

	OBJECT(object)->timer = 7u;
	target_direction = OBJECT(object)->target_direction;
	OBJECT(object)->enemy_wander.wander_direction = target_direction;
	if ((int8_t)random_number >= 0)
		OBJECT(object)->enemy_wander.way_round = 0xFFu;
	else
		OBJECT(object)->enemy_wander.way_round = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return enemy_wander_turn(object, step_handlers);
}

/* Turns its heading one way or the other and walks that way. */
uint16_t enemy_wander_turn(uint16_t object, uint16_t step_handlers)
{
	uint8_t angle = 0;
	uint16_t direction = 0;
	uint8_t wander_direction = 0, way_round = 0;

	OBJECT(object)->animation = 0x81u;
	wander_direction = OBJECT(object)->enemy_wander.wander_direction;
	angle = wander_direction;
	way_round = OBJECT(object)->enemy_wander.way_round;
	if (way_round != 0u)
		angle += 0x50u;
	else
		angle -= 0x30u;
	OBJECT(object)->enemy_wander.wander_direction = angle;
	direction = (uint32_t)angle << 8;
	return set_walk_speeds_from_direction(object, step_handlers, direction);
}

/* Walks its stretch (turning the other way when stopped), then stands for 72 frames. */
uint16_t enemy_wander_walk(uint16_t object, uint16_t step_handlers)
{
	uint8_t blocked = 0, way_round = 0, timer = 0, action_step = 0;

	blocked = OBJECT(object)->blocked;
	if ((int8_t)blocked < 0)
	{
		way_round = OBJECT(object)->enemy_wander.way_round;
		OBJECT(object)->enemy_wander.way_round = ~way_round;
		return enemy_wander_turn(object, step_handlers);
	}
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x48u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->animation = 0x86u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	return step_handlers;
}

/* Stands until its timer runs out, then turns and walks again. */
uint16_t enemy_wander_rest(uint16_t object, uint16_t step_handlers)
{
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return step_handlers;
	OBJECT(object)->timer = 7u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	return enemy_wander_turn(object, step_handlers);
}

/* Move 7: runs at its target in x and slows down to a stop near it. */
void enemy_rush_at_target(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_rush_at_target_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		enemy_rush_start(object);
		break;
	case 2:
		enemy_rush_step(object);
		break;
	case 4:
		enemy_rush_slow_down(object);
		break;
	case -38:
	case 6:
		enemy_line_up_start(object);
		break;
	case -36:
	case 8:
		enemy_line_up_in_depth(object);
		break;
	case 10:
		enemy_pace_start(object);
		break;
	case 12:
		enemy_pace_step(object);
		break;
	case 14:
		enemy_pace_end(object);
		break;
	case -122:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -120:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -118:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -116:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -114:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -112:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -110:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -108:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -106:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -104:
	case -80:
		enemy_move_front_until_landed(object);
		break;
	case -102:
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
	case -60:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -100:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -98:
	case -74:
		enemy_move_back_until_landed(object);
		break;
	case -94:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -92:
	case -68:
		enemy_move_left_until_landed(object);
		break;
	case -88:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -86:
	case -62:
		enemy_move_right_until_landed(object);
		break;
	case -82:
	case -70:
	case -64:
		enemy_hop_start(object);
		break;
	case -76:
		enemy_hop_back_start(object);
		break;
	case -58:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -56:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -54:
		enemy_go_straight(object);
		break;
	case -52:
	case -42:
		enemy_walk_start_in_turn(object);
		break;
	case -50:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -48:
		enemy_line_up_near_start(object);
		break;
	case -46:
		enemy_line_up_near_in_depth(object);
		break;
	case -44:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -40:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -34:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -32:
		enemy_keep_distance_start(object);
		break;
	case -30:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -28:
		enemy_keep_distance_back_off(object);
		break;
	case -26:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -24:
		enemy_wait_start(object);
		break;
	case -22:
	case -16:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case -20:
		enemy_back_off_start(object);
		break;
	case -18:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case -14:
		enemy_step_toward_target_start(object);
		break;
	case -12:
		enemy_step_toward_target_step(object);
		break;
	case -10:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case -8:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case -6:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case -4:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case -2:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* The run animation, 2 pixels a frame toward its target in x, and the slowing down kept for later,
   facing it. */
void enemy_rush_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0, slow_down = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->timer = 0x40u;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->enemy_rush.slow_down = -0x20;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
		slow_down = OBJECT(object)->enemy_rush.slow_down;
		OBJECT(object)->enemy_rush.slow_down = 0u - slow_down;
	}
	enemy_face_target(object);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Once within 64 pixels of its target in x, slows down over 8 frames (40 at times when out of line in
   depth). */
void enemy_rush_step(uint16_t object)
{
	uint8_t timer = 0;
	uint8_t timer_2 = 0, action_step = 0;
	uint16_t target_dx = 0, target_dy = 0;

	timer_2 = OBJECT(object)->timer;
	OBJECT(object)->timer = timer_2 - 1u;
	target_dx = OBJECT(object)->target_dx;
	if (target_dx > 0x40u)
		return;
	target_dy = OBJECT(object)->target_dy;
	if (target_dy < 0x10u || (int8_t)(uint8_t)frame_count >= 0)
		timer = 8u;
	else
		timer = 0x28u;
	OBJECT(object)->timer = timer;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Slows down in its last 8 frames. */
void enemy_rush_slow_down(uint16_t object)
{
	uint8_t timer = 0, timer_2 = 0;
	uint16_t x_speed = 0, slow_down = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	timer_2 = OBJECT(object)->timer;
	if ((uint16_t)((uint32_t)timer_2 << 8) >> 8 < 8u)
	{
		x_speed = OBJECT(object)->x_speed;
		slow_down = OBJECT(object)->enemy_rush.slow_down;
		OBJECT(object)->x_speed = x_speed + slow_down;
	}
}

/* Move 8: walks level with its target in depth, then paces back and forth 4 times in front of it. */
void enemy_line_up_and_pace(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_offset = 0;
	uint16_t step_handlers = 0;

	step_handlers = enemy_line_up_and_pace_steps_ADDRESS;
	step_offset = (uint32_t)step << 1;
	switch ((int8_t)step_offset)
	{
	case -44:
	case 0:
		enemy_line_up_start(object);
		break;
	case -42:
	case 2:
		enemy_line_up_in_depth(object);
		break;
	case 4:
		enemy_pace_start(object);
		break;
	case 6:
		enemy_pace_step(object);
		break;
	case 8:
		enemy_pace_end(object);
		break;
	case -128:
		step = step_offset;
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -126:
		step = step_offset;
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -124:
		step = step_offset;
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -122:
		step = step_offset;
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -120:
		step = step_offset;
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -118:
		step = step_offset;
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -116:
		step = step_offset;
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -114:
		step = step_offset;
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case -112:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case -110:
	case -86:
		enemy_move_front_until_landed(object);
		break;
	case -108:
	case -102:
	case -96:
	case -90:
	case -84:
	case -78:
	case -72:
	case -66:
		enemy_back_to_thinking_after_wait(object);
		break;
	case -106:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case -104:
	case -80:
		enemy_move_back_until_landed(object);
		break;
	case -100:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case -98:
	case -74:
		enemy_move_left_until_landed(object);
		break;
	case -94:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case -92:
	case -68:
		enemy_move_right_until_landed(object);
		break;
	case -88:
	case -76:
	case -70:
		enemy_hop_start(object);
		break;
	case -82:
		enemy_hop_back_start(object);
		break;
	case -64:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case -62:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case -60:
		enemy_go_straight(object);
		break;
	case -58:
	case -48:
		enemy_walk_start_in_turn(object);
		break;
	case -56:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case -54:
		enemy_line_up_near_start(object);
		break;
	case -52:
		enemy_line_up_near_in_depth(object);
		break;
	case -50:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case -46:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case -40:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case -38:
		enemy_keep_distance_start(object);
		break;
	case -36:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case -34:
		enemy_keep_distance_back_off(object);
		break;
	case -32:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case -30:
		enemy_wait_start(object);
		break;
	case -28:
	case -22:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case -26:
		enemy_back_off_start(object);
		break;
	case -24:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case -20:
		enemy_step_toward_target_start(object);
		break;
	case -18:
		enemy_step_toward_target_step(object);
		break;
	case -16:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case -14:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case -12:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case -10:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case -8:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case -6:
		enemy_rush_start(object);
		break;
	case -4:
		enemy_rush_step(object);
		break;
	case -2:
		enemy_rush_slow_down(object);
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Walks toward its target in x at 1 pixel a frame, 32 frames a way, 4 ways. */
void enemy_pace_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	enemy_face_with_animation(object);
	OBJECT(object)->timer = 0x20u;
	OBJECT(object)->enemy.count = 4u;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->x_speed = 0x100;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Turns round every 32 frames, 4 times. */
void enemy_pace_step(uint16_t object)
{
	uint8_t timer = 0, count = 0, action_step = 0;
	uint16_t x_speed = 0;

	enemy_face_with_animation(object);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->timer = 0x20u;
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
		count = OBJECT(object)->enemy.count;
		OBJECT(object)->enemy.count = count - 1u;
		if (count == 1u)
		{
			action_step = OBJECT(object)->action_step;
			OBJECT(object)->action_step = action_step + 1u;
		}
	}
}

/* Ends the move. */
void enemy_pace_end(uint16_t object)
{
	OBJECT(object)->timer = 0u;
}
