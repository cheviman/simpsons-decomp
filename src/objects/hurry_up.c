/**
 *    Name:        objects/hurry_up.c
 *    Description: the HURRY UP that comes for idle players
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint16_t ignored16 = 0, u = 0;
	uint8_t step = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

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
		t1 = (random_number & 3u) * 0xC0u;
		t2 = t1 + OBJECT_ADDRESS(0);
		OBJECT(object)->hurry_up.player = t2;
		OBJECT(object)->hurry_up.tries = 0u;
		t3 = camera_x;
		OBJECT(object)->hurry_up.scroll_x = t3;
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
		stage_3_boss_start(object, &ignored16, &child_handlers);
		return child_handlers;
	case 18:
		stage_3_boss_enter(object, 0u);
		return child_handlers;
	case 20:
		stage_3_boss_arrive(object, &ignored16, &child_handlers);
		return child_handlers;
	case 22:
		stage_3_boss_wait(object, &ignored16, &child_handlers);
		return child_handlers;
	case 24:
		stage_3_boss_walk(object, &ignored16, &child_handlers);
		return child_handlers;
	case 26:
		stage_3_boss_leap(object, &ignored16, &child_handlers);
		return child_handlers;
	case 28:
		stage_3_boss_attack(object, &ignored16, &child_handlers);
		return child_handlers;
	case 30:
	case 44:
		stage_3_boss_strike(object, &ignored16, &child_handlers);
		return child_handlers;
	case 32:
		stage_3_boss_follow_up(object, &ignored16, &child_handlers);
		return child_handlers;
	case 34:
		stage_3_boss_reach_partner(object, &ignored16, &u);
		return u;
	case 36:
		stage_3_boss_follow_partner(object, &ignored16, &u);
		return u;
	case 38:
		stage_3_boss_join(object, &ignored16, &child_handlers);
		return child_handlers;
	case 40:
		stage_3_boss_jump_on(object, 0u);
		return child_handlers;
	case 42:
		stage_3_boss_together(object, &ignored16, &child_handlers);
		return child_handlers;
	case 46:
		stage_3_boss_partner_ready(object, &u, &carry);
		return u;
	case 48:
		stage_3_boss_pause(object, &ignored16, &child_handlers);
		return child_handlers;
	case 50:
		stage_3_boss_flinch(object, &ignored16, &child_handlers);
		return child_handlers;
	case 52:
		stage_3_boss_knocked(object, &ignored16, &child_handlers);
		return child_handlers;
	case 54:
		stage_3_boss_down(object, 0u);
		return child_handlers;
	case 56:
		stage_3_boss_defeated(object, 0u);
		return child_handlers;
	case 58:
		stage_3_boss_push(object, &ignored16, &child_handlers);
		return child_handlers;
	}
	unreachable();
}

/* Comes in with its sound, keeping pace with the camera */
void hurry_up_enter(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t animation_flags = 0, step = 0, animation = 0;
	uint16_t t1 = 0, t2 = 0, time = 0;

	OBJECT(object)->x = 0x148u;
	OBJECT(object)->y = 0x80u;
	OBJECT(object)->z = 0x80u;
	t1 = camera_y_speed;
	t2 = 0u - t1;
	OBJECT(object)->y_speed = t2;
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
	uint16_t player = 0;
	uint8_t tries = 0, tries_2 = 0;
	uint16_t player_2 = 0;

	OBJECT(object)->hurry_up.step = 5u;
	player_2 = OBJECT(object)->hurry_up.player;
	player = player_2;
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
			return player;
		}
		player += 0xC0u;
		if (player == OBJECT_ADDRESS(8))
			player = OBJECT_ADDRESS(0);
	} while (mem_read8(player) == 0u);
	OBJECT(object)->hurry_up.player = player;
	OBJECT(object)->hurry_up.time = 0xC8u;
	return hurry_up_go_to_player(object);
}

/* Flies to its player and hits it on reaching it */
uint16_t hurry_up_go_to_player(uint16_t object)
{
	uint16_t d = 0, heading = 0, player_height = 0, player_y = 0, target = 0;
	uint8_t step = 0;
	uint16_t player = 0, time = 0, t1 = 0, z = 0, t2 = 0, t3 = 0, player_2 = 0, t4 = 0, z_2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, z_3 = 0, player_3 = 0, t10 = 0, z_4 = 0, z_5 = 0, z_6 = 0;

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
	t1 = OBJECT(target)->y;
	z = OBJECT(target)->z;
	OBJECT(target)->y = t1 + z - 0x80u;
	t2 = OBJECT(object)->x;
	d = t2 + 0x18u;
	t3 = OBJECT(target)->x;
	if ((int16_t)d <= (int16_t)t3)
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		d = 0xF6u;
		d = vector_direction_to_offset(object, target, d);
		heading = (d & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		t4 = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = t4 - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	t5 = OBJECT(target)->x;
	if ((int16_t)t5 <= (int16_t)(d - 0x30u))
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		d = 0xF6u;
		d = vector_direction_to_offset(object, target, d);
		heading = (d & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		t4 = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = t4 - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	t6 = OBJECT(object)->y;
	d = t6 + 0x10u;
	t7 = OBJECT(target)->y;
	if ((int16_t)d <= (int16_t)t7)
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		d = 0xF6u;
		d = vector_direction_to_offset(object, target, d);
		heading = (d & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		t4 = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = t4 - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	t8 = OBJECT(target)->y;
	if ((int16_t)t8 <= (int16_t)(d - 0x20u))
	{
		player_2 = OBJECT(object)->hurry_up.player;
		target = player_2;
		d = 0xF6u;
		d = vector_direction_to_offset(object, target, d);
		heading = (d & ~0xFFu) | 0x80u;
		vector_set_speed_by_direction(object, heading);
		t4 = OBJECT(target)->y;
		z_2 = OBJECT(target)->z;
		OBJECT(target)->y = t4 - z_2 + 0x80u;
		OBJECT(target)->animation_flags = 0x80u;
		hurry_up_check_scroll(object);
		return target;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	t9 = OBJECT(target)->y;
	z_3 = OBJECT(target)->z;
	OBJECT(target)->y = t9 - z_3 + 0x80u;
	OBJECT(object)->animation = 0x84u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->flags = 0xC0u;
	player_3 = OBJECT(object)->hurry_up.player;
	target = player_3;
	t10 = OBJECT(object)->y;
	player_y = t10;
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
