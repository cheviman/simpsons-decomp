/**
 *    Name:        objects/hurry_up.c
 *    Description: the HURRY UP that comes for idle players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the HURRY UP: set up on its first frame, then by its step */
uint16_t hurry_up(uint16_t object, uint16_t child_handlers)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint8_t step = 0;
	uint16_t player_offset = 0, player_object = 0, camera_x_now = 0;

	if (OBJECT(object)->flags == 4u)
	{
		OBJECT(object)->hurry_up.step = 0u;
		OBJECT(object)->hurry_up.time &= 0xFFu;
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->kind = 0xAEu;
		OBJECT(object)->animation = 0x80u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->box_width = 0x24u;
		OBJECT(object)->box_depth = 0x24u;
		OBJECT(object)->box_height = 0x24u;
		OBJECT(object)->box_dz = 0x24u;
		OBJECT(object)->hurry_up.time = 0x200u;
		player_offset = (random_number & 3u) * 0xC0u;
		player_object = player_offset + OBJECT_ADDRESS(0);
		OBJECT(object)->hurry_up.player = player_object;
		OBJECT(object)->hurry_up.tries = 0u;
		camera_x_now = camera_x;
		OBJECT(object)->hurry_up.scroll_x = camera_x_now;
	}
	step = OBJECT(object)->hurry_up.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
	case 2:
	case 4:
		hurry_up_enter(object);
		return child_handlers;
	case 6:
	case 8:
		return hurry_up_next_player(object);
	case 10:
		return hurry_up_go_to_player(object);
	case 12:
		hurry_up_hit(object);
		return child_handlers;
	case 14:
		hurry_up_vanish(object);
		return child_handlers;
	case 16:
		return stage_3_boss_start(object, child_handlers);
	case 18:
		stage_3_boss_enter(object);
		return child_handlers;
	case 20:
		return stage_3_boss_arrive(object, child_handlers);
	case 22:
		return stage_3_boss_wait(object, child_handlers);
	case 24:
		return stage_3_boss_walk(object, child_handlers);
	case 26:
		return stage_3_boss_leap(object, child_handlers);
	case 28:
		return stage_3_boss_attack(object, child_handlers);
	case 30:
	case 44:
		return stage_3_boss_strike(object, child_handlers);
	case 32:
		return stage_3_boss_follow_up(object, child_handlers);
	case 34:
		return stage_3_boss_reach_partner(object);
	case 36:
		return stage_3_boss_follow_partner(object);
	case 38:
		return stage_3_boss_join(object, child_handlers);
	case 40:
		stage_3_boss_jump_on(object);
		return child_handlers;
	case 42:
		return stage_3_boss_together(object, child_handlers);
	case 46:
		stage_3_boss_partner_ready(object, &u, &carry);
		return u;
	case 48:
		return stage_3_boss_pause(object, child_handlers);
	case 50:
		return stage_3_boss_flinch(object, child_handlers);
	case 52:
		return stage_3_boss_knocked(object, child_handlers);
	case 54:
		stage_3_boss_down(object);
		return child_handlers;
	case 56:
		stage_3_boss_defeated(object);
		return child_handlers;
	case 58:
		return stage_3_boss_push(object, child_handlers);
	}
	unreachable();
}

/* Comes in with its sound, keeping pace with the camera */
void hurry_up_enter(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, step = 0, animation = 0;
	uint16_t camera_speed = 0, against_camera = 0, time = 0;

	OBJECT(object)->x = 0x148u;
	OBJECT(object)->y = 0x80u;
	OBJECT(object)->z = 0x80u;
	camera_speed = camera_y_speed;
	against_camera = 0u - camera_speed;
	OBJECT(object)->y_speed = against_camera;
	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags == 2u)
	{
		command = 0x1F00u;
		carry = vector_queue_sound(command);
	}
	time = OBJECT(object)->hurry_up.time;
	OBJECT(object)->hurry_up.time = time - 1u;
	if (time == 1u)
	{
		step = OBJECT(object)->hurry_up.step;
		OBJECT(object)->hurry_up.step = step + 1u;
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = (animation + 1u) | 0x80u;
		OBJECT(object)->hurry_up.time = 0x140u;
	}
	hurry_up_check_scroll(object);
}

/* Picks the next player in use to go to; leaves after 5 */
uint16_t hurry_up_next_player(uint16_t object)
{
	uint16_t candidate = 0;
	uint8_t tries = 0, tries_2 = 0;
	uint16_t player = 0;

	OBJECT(object)->hurry_up.step = 5u;
	player = OBJECT(object)->hurry_up.player;
	candidate = player;
	do
	{
		tries = OBJECT(object)->hurry_up.tries;
		OBJECT(object)->hurry_up.tries = tries + 1u;
		tries_2 = OBJECT(object)->hurry_up.tries;
		if (tries_2 == 5u)
		{
			OBJECT(object)->hurry_up.step = 7u;
			OBJECT(object)->kind = 4u;
			OBJECT(object)->animation = 0x80u;
			return candidate;
		}
		candidate += 0xC0u;
		if (candidate == OBJECT_ADDRESS(8))
			candidate = OBJECT_ADDRESS(0);
	} while (OBJECT(candidate)->flags == 0u);
	OBJECT(object)->hurry_up.player = candidate;
	OBJECT(object)->hurry_up.time = 0xC8u;
	return hurry_up_go_to_player(object);
}

/* Flies to its player and hits it on reaching it */
uint16_t hurry_up_go_to_player(uint16_t object)
{
	uint16_t edge_or_direction = 0, heading = 0, player_height = 0, player_y = 0, target = 0;
	uint8_t step = 0;
	uint16_t player = 0, time = 0, target_y = 0, z = 0, hurry_x = 0, target_x = 0, player_2 = 0, raised_target_y_2nd = 0, z_2 = 0, target_x_2nd = 0, hurry_y = 0, raised_y_checked = 0, raised_y_checked_2nd = 0, raised_target_y = 0, z_3 = 0, player_3 = 0, hurry_y_now = 0, z_4 = 0, z_5 = 0, z_6 = 0;

	player = OBJECT(object)->hurry_up.player;
	target = player;
	if (OBJECT(target)->flags == 0u)
	{
		hurry_up_after_hit(object);
		return target;
	}
	time = OBJECT(object)->hurry_up.time;
	OBJECT(object)->hurry_up.time = time - 1u;
	if (time == 1u)
	{
		hurry_up_after_hit(object);
		return target;
	}
	target_y = OBJECT(target)->y;
	z = OBJECT(target)->z;
	OBJECT(target)->y = target_y + z - 0x80u;
	hurry_x = OBJECT(object)->x;
	edge_or_direction = hurry_x + 0x18u;
	target_x = OBJECT(target)->x;
	if ((int16_t)edge_or_direction <= (int16_t)target_x)
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		edge_or_direction = 0xF6u;
		edge_or_direction = vector_direction_to_offset(object, target, edge_or_direction);
		heading = (edge_or_direction & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		raised_target_y_2nd = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = raised_target_y_2nd - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	target_x_2nd = OBJECT(target)->x;
	if ((int16_t)target_x_2nd <= (int16_t)(edge_or_direction - 0x30u))
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		edge_or_direction = 0xF6u;
		edge_or_direction = vector_direction_to_offset(object, target, edge_or_direction);
		heading = (edge_or_direction & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		raised_target_y_2nd = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = raised_target_y_2nd - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	hurry_y = OBJECT(object)->y;
	edge_or_direction = hurry_y + 0x10u;
	raised_y_checked = OBJECT(target)->y;
	if ((int16_t)edge_or_direction <= (int16_t)raised_y_checked)
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		edge_or_direction = 0xF6u;
		edge_or_direction = vector_direction_to_offset(object, target, edge_or_direction);
		heading = (edge_or_direction & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		raised_target_y_2nd = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = raised_target_y_2nd - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	raised_y_checked_2nd = OBJECT(target)->y;
	if ((int16_t)raised_y_checked_2nd <= (int16_t)(edge_or_direction - 0x20u))
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		edge_or_direction = 0xF6u;
		edge_or_direction = vector_direction_to_offset(object, target, edge_or_direction);
		heading = (edge_or_direction & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		raised_target_y_2nd = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = raised_target_y_2nd - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	raised_target_y = OBJECT(target)->y;
	z_3 = OBJECT(target)->z;
	OBJECT(target)->y = raised_target_y - z_3 + 0x80u;
	OBJECT(object)->animation = 0x84u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->flags = 0xC0u;
	player_3 = OBJECT(object)->hurry_up.player;
	target = player_3;
	hurry_y_now = OBJECT(object)->y;
	player_y = hurry_y_now;
	OBJECT(object)->hurry_up.player_y = player_y;
	z_4 = OBJECT(target)->z;
	OBJECT(object)->y = player_y - z_4 + 0x80u;
	z_5 = OBJECT(object)->z;
	player_height = z_5;
	OBJECT(object)->hurry_up.player_height = player_height;
	z_6 = OBJECT(target)->z;
	OBJECT(object)->z = player_height + z_6 - 0x80u;
	OBJECT(object)->damage = 0x14u;
	OBJECT(object)->attack = 6u;
	step = OBJECT(object)->hurry_up.step;
	OBJECT(object)->hurry_up.step = step + 1u;
	return target;
}

/* Waits for its hit's animation to end */
void hurry_up_hit(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		hurry_up_after_hit(object);
		return;
	}
}

/* After its hit, goes back to its place and on to the next player */
void hurry_up_after_hit(uint16_t object)
{
	uint16_t player_y = 0, player_height = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->hurry_up.step = 4u;
	OBJECT(object)->z = 0u;
	OBJECT(object)->damage = 0u;
	OBJECT(object)->attack = 0u;
	player_y = OBJECT(object)->hurry_up.player_y;
	OBJECT(object)->y = player_y;
	player_height = OBJECT(object)->hurry_up.player_height;
	OBJECT(object)->z = player_height;
	OBJECT(object)->animation_flags = 0x80u;
}

/* Vanishes in a puff when the camera moves on */
void hurry_up_check_scroll(uint16_t object)
{
	uint16_t scroll_x = 0;
	uint16_t scroll_x_2 = 0;

	scroll_x = camera_x;
	scroll_x_2 = OBJECT(object)->hurry_up.scroll_x;
	if (scroll_x == scroll_x_2)
	{
		OBJECT(object)->hurry_up.scroll_x = scroll_x;
		return;
	}
	OBJECT(object)->hurry_up.step = 7u;
	OBJECT(object)->kind = 4u;
	OBJECT(object)->animation = 0x80u;
}

/* Gone at its puff's end, letting the timer start again */
void hurry_up_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((((uint16_t)((uint32_t)animation_flags << 8) >> 8) & 1u) != 0u)
	{
		OBJECT(object)->flags = 0u;
		hurry_up_out = 0u;
	}
	OBJECT(object)->x_speed = camera_x_speed;
	OBJECT(object)->y_speed = 0u - camera_y_speed;
}

/* Unused: does nothing. */
void unused_hurry_up_no_op(void)
{
}
