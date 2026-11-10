/**
 *    Name:        objects/stage_7_boss.c
 *    Description: stage 7's boss (Channel 6)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 7's boss beaten (state FD), by its step. */
uint16_t stage_7_boss_beaten(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_beaten_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_beaten_wait(object);
			return y;
		case 2:
			stage_7_boss_blink_out(object, carry);
			return y;
		case 4:
			stage_7_boss_fall(object);
			return y;
		case 6:
			stage_7_boss_lie(object);
			return y;
		case 8:
			return stage_7_boss_get_up(object, y);
		case 10:
			stage_7_boss_flinch_wait(object);
			return y;
		case 12:
			return stage_7_boss_flinch_land(object, y);
		case 14:
			return stage_7_boss_put_in(object);
		case 16:
			stage_7_boss_start_entrance(object);
			return y;
		case 18:
			stage_7_boss_move_helpers(object);
			return y;
		case 20:
			stage_7_boss_step_forward(object);
			return y;
		case 22:
			stage_7_boss_arrive(object);
			return y;
		case 24:
			stage_7_boss_entrance_pose(object);
			return y;
		case 26:
			stage_7_boss_entrance_end(object);
			return y;
		case 28:
			stage_7_boss_wind_up(object);
			return y;
		case 30:
			stage_7_boss_strike(object);
			return y;
		case 32:
			return stage_7_boss_recover(object, y);
		case 34:
			stage_7_boss_charging(object);
			return y;
		case 36:
			return stage_7_boss_charge_end(object, y);
		case 38:
			stage_7_boss_jump_rise(object);
			return y;
		case 40:
			stage_7_boss_jump_land(object);
			return y;
		case 42:
			break;
		case -20:
			continue;
		case -18:
			return stage_7_boss_knocked_down(object, y);
		case -16:
			return stage_7_boss_flinch(object, y);
		case -14:
			return stage_7_boss_entrance(object, y);
		case -12:
			return stage_7_boss_walk(object, y);
		case -10:
			return stage_7_boss_attack(object, y);
		case -8:
			return stage_7_boss_charge(object, y);
		case -6:
			return stage_7_boss_jump_away(object, y);
		case -4:
			return stage_7_boss_idle(object, y, action_handlers);
		case -2:
			return stage_7_boss_wait_target_up(object, y);
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss beaten: waits, then cries out (3F3B). */
void stage_7_boss_beaten_wait(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	command = 0x3F3Bu;
	carry = vector_queue_sound(command);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss beaten: blinks for 192 frames, then it is gone (sound 9600), the boss counts as beaten
   and the step goes on. */
void stage_7_boss_blink_out(uint16_t object, uint32_t carry)
{
	uint8_t frame_bit = 0;
	uint16_t command = 0;
	uint8_t t1 = 0, action_step = 0, action_step_2 = 0, points = 0;

	OBJECT(object)->flags &= 0x7Fu;
	frame_bit = (uint8_t)frame_count & 1u;
	t1 = (frame_bit >> 1) | (carry << 7);
	carry = frame_bit;
	OBJECT(object)->flags |= (t1 >> 1) | (carry << 7);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	action_step_2 = OBJECT(object)->action_step;
	if (action_step_2 != 0xC0u)
		return;
	command = 0x9600u;
	carry = vector_queue_sound(command);
	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x81u;
	OBJECT(object)->flags = 0u;
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
}

/* Stage 7's boss knocked down (state FE), by its step. */
uint16_t stage_7_boss_knocked_down(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_knocked_down_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_fall(object);
			return y;
		case 2:
			stage_7_boss_lie(object);
			return y;
		case 4:
			return stage_7_boss_get_up(object, y);
		case 6:
			stage_7_boss_flinch_wait(object);
			return y;
		case 8:
			return stage_7_boss_flinch_land(object, y);
		case 10:
			return stage_7_boss_put_in(object);
		case 12:
			stage_7_boss_start_entrance(object);
			return y;
		case 14:
			stage_7_boss_move_helpers(object);
			return y;
		case 16:
			stage_7_boss_step_forward(object);
			return y;
		case 18:
			stage_7_boss_arrive(object);
			return y;
		case 20:
			stage_7_boss_entrance_pose(object);
			return y;
		case 22:
			stage_7_boss_entrance_end(object);
			return y;
		case 24:
			stage_7_boss_wind_up(object);
			return y;
		case 26:
			stage_7_boss_strike(object);
			return y;
		case 28:
			return stage_7_boss_recover(object, y);
		case 30:
			stage_7_boss_charging(object);
			return y;
		case 32:
			return stage_7_boss_charge_end(object, y);
		case 34:
			stage_7_boss_jump_rise(object);
			return y;
		case 36:
			stage_7_boss_jump_land(object);
			return y;
		case 38:
			break;
		case -24:
			return stage_7_boss_beaten(object, y);
		case -22:
			continue;
		case -20:
			return stage_7_boss_flinch(object, y);
		case -18:
			return stage_7_boss_entrance(object, y);
		case -16:
			return stage_7_boss_walk(object, y);
		case -14:
			return stage_7_boss_attack(object, y);
		case -12:
			return stage_7_boss_charge(object, y);
		case -10:
			return stage_7_boss_jump_away(object, y);
		case -8:
			return stage_7_boss_idle(object, y, action_handlers);
		case -6:
			return stage_7_boss_wait_target_up(object, y);
		case -4:
			stage_7_boss_beaten_wait(object);
			return y;
		case -2:
			stage_7_boss_blink_out(object, carry);
			return y;
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss knocked down: falls; landing with too little health it is beaten, else it lies. */
void stage_7_boss_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, d = 0;
	uint8_t vitality = 0, t1 = 0, shadow_player = 0, action = 0;
	uint16_t hit_by = 0;

	vector_apply_gravity(object, &d, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (vitality <= stage_7_boss_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))])
	{
		OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 4u;
		animation_number = (d & 0xFFu) | 0x800u;
		carry = stage_7_boss_set_animation(object, animation_number);
		t1 = io_read8(0x187Eu);
		io_write8(0x187Eu, t1 + 1u);
		command = 0x9800u;
		carry = vector_queue_sound(command);
		hit_by = OBJECT(object)->hit_by;
		shadow_player = OBJECT(hit_by)->shadow_player;
		OBJECT(object)->points = shadow_player & ~0xFu;
		OBJECT(object)->action_step = 0xC0u;
		OBJECT(object)->vitality = 0u;
		OBJECT(object)->state = 0xFDu;
		OBJECT(object)->action = 0u;
		return;
	}
	animation_number = (d & 0xFFu) | 0xB00u;
	carry = stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss knocked down: lies for 64 frames, then starts getting up. */
void stage_7_boss_lie(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	animation_number = 0x700u;
	carry = stage_7_boss_set_animation(object, animation_number);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss knocked down: once up, stands and picks its target again. */
uint16_t stage_7_boss_get_up(uint16_t object, uint16_t y)
{
	uint16_t u = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	u = stage_7_boss_stand(object);
	return stage_7_boss_pick_target(object, y, u);
}

/* Stage 7's boss hit (state FF), by its step. */
uint16_t stage_7_boss_flinch(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_flinch_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_flinch_wait(object);
			return y;
		case 2:
			return stage_7_boss_flinch_land(object, y);
		case 4:
			return stage_7_boss_put_in(object);
		case 6:
			stage_7_boss_start_entrance(object);
			return y;
		case 8:
			stage_7_boss_move_helpers(object);
			return y;
		case 10:
			stage_7_boss_step_forward(object);
			return y;
		case 12:
			stage_7_boss_arrive(object);
			return y;
		case 14:
			stage_7_boss_entrance_pose(object);
			return y;
		case 16:
			stage_7_boss_entrance_end(object);
			return y;
		case 18:
			stage_7_boss_wind_up(object);
			return y;
		case 20:
			stage_7_boss_strike(object);
			return y;
		case 22:
			return stage_7_boss_recover(object, y);
		case 24:
			stage_7_boss_charging(object);
			return y;
		case 26:
			return stage_7_boss_charge_end(object, y);
		case 28:
			stage_7_boss_jump_rise(object);
			return y;
		case 30:
			stage_7_boss_jump_land(object);
			return y;
		case 32:
			break;
		case -30:
			return stage_7_boss_beaten(object, y);
		case -28:
			return stage_7_boss_knocked_down(object, y);
		case -26:
			continue;
		case -24:
			return stage_7_boss_entrance(object, y);
		case -22:
			return stage_7_boss_walk(object, y);
		case -20:
			return stage_7_boss_attack(object, y);
		case -18:
			return stage_7_boss_charge(object, y);
		case -16:
			return stage_7_boss_jump_away(object, y);
		case -14:
			return stage_7_boss_idle(object, y, action_handlers);
		case -12:
			return stage_7_boss_wait_target_up(object, y);
		case -10:
			stage_7_boss_beaten_wait(object);
			return y;
		case -8:
			stage_7_boss_blink_out(object, carry);
			return y;
		case -6:
			stage_7_boss_fall(object);
			return y;
		case -4:
			stage_7_boss_lie(object);
			return y;
		case -2:
			return stage_7_boss_get_up(object, y);
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss hit: waits for its flinch's animation to end. */
void stage_7_boss_flinch_wait(uint16_t object)
{
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss hit: once back on the floor, stands and picks its target again. */
uint16_t stage_7_boss_flinch_land(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return y;
	u = stage_7_boss_stand(object);
	y = stage_7_boss_pick_target(object, y, u);
	return y;
}

/* Stage 7's boss' entrance (state 0), by its step. */
uint16_t stage_7_boss_entrance(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_entrance_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			return stage_7_boss_put_in(object);
		case 2:
			stage_7_boss_start_entrance(object);
			return y;
		case 4:
			stage_7_boss_move_helpers(object);
			return y;
		case 6:
			stage_7_boss_step_forward(object);
			return y;
		case 8:
			stage_7_boss_arrive(object);
			return y;
		case 10:
			stage_7_boss_entrance_pose(object);
			return y;
		case 12:
			stage_7_boss_entrance_end(object);
			return y;
		case 14:
			stage_7_boss_wind_up(object);
			return y;
		case 16:
			stage_7_boss_strike(object);
			return y;
		case 18:
			return stage_7_boss_recover(object, y);
		case 20:
			stage_7_boss_charging(object);
			return y;
		case 22:
			return stage_7_boss_charge_end(object, y);
		case 24:
			stage_7_boss_jump_rise(object);
			return y;
		case 26:
			stage_7_boss_jump_land(object);
			return y;
		case 28:
			break;
		case -34:
			return stage_7_boss_beaten(object, y);
		case -32:
			return stage_7_boss_knocked_down(object, y);
		case -30:
			return stage_7_boss_flinch(object, y);
		case -28:
			continue;
		case -26:
			return stage_7_boss_walk(object, y);
		case -24:
			return stage_7_boss_attack(object, y);
		case -22:
			return stage_7_boss_charge(object, y);
		case -20:
			return stage_7_boss_jump_away(object, y);
		case -18:
			return stage_7_boss_idle(object, y, action_handlers);
		case -16:
			return stage_7_boss_wait_target_up(object, y);
		case -14:
			stage_7_boss_beaten_wait(object);
			return y;
		case -12:
			stage_7_boss_blink_out(object, carry);
			return y;
		case -10:
			stage_7_boss_fall(object);
			return y;
		case -8:
			stage_7_boss_lie(object);
			return y;
		case -6:
			return stage_7_boss_get_up(object, y);
		case -4:
			stage_7_boss_flinch_wait(object);
			return y;
		case -2:
			return stage_7_boss_flinch_land(object, y);
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss' entrance: puts its four helpers in their places and itself, with its health. */
uint16_t stage_7_boss_put_in(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t slot_list = 0;
	uint16_t animation_number = 0, helper = 0, helper_start = 0;
	uint8_t action = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	boss_helper_number = 0u;
	do
	{
		slot_list = 1u;
		vector_find_free_slot(slot_list, &helper, &carry);
		OBJECT(helper)->flags = 0x80u;
		OBJECT(helper)->kind = 0x12u;
		t1 = stage_7_boss_helper_starts_ADDRESS + (int8_t)(((uint32_t)boss_helper_number << 1) << 1);
		OBJECT(helper)->animation = HELPER_START(t1)->animation;
		OBJECT(helper)->attributes = 0x20u;
		t2 = t1 + 1u;
		helper_start = t2 + 2u;
		t3 = HELPER_START(t2 - 0x1u)->x;
		t4 = t3 + 0x91Fu;
		t5 = t4 - camera_x;
		OBJECT(helper)->x = t5;
		t6 = 0xC8u + camera_y;
		OBJECT(helper)->y = t6;
		OBJECT(helper)->z = 0x20u;
		OBJECT(helper)->type = 0x37;
		mem_write16(object + (int8_t)HELPER_START(helper_start - 0x3u)->slot, helper);
		boss_helper_number++;
	} while (boss_helper_number != 4u);
	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->entrance_pending = 1u;
	OBJECT(object)->shadow_player = 1u;
	animation_number = 0x101u;
	carry = stage_7_boss_set_animation(object, animation_number);
	t7 = 0x96Fu - camera_x;
	OBJECT(object)->x = t7;
	OBJECT(object)->vitality = 0xE0u;
	OBJECT(object)->stage_7_boss.last_health = 0xE0u;
	OBJECT(object)->floor_z = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return helper_start;
}

/* Stage 7's boss' entrance: once the camera's flag from the stage record clears, says a boss is in and
   sets two helpers moving. */
void stage_7_boss_start_entrance(uint16_t object)
{
	uint8_t action = 0;
	uint16_t helper = 0, helper_2 = 0;

	if (stage_scrolls_on == 0u)
	{
		OBJECT(object)->entrance_pending = 0u;
		boss_arrived++;
		helper = OBJECT(object)->stage_7_boss.helper_1;
		mem_write8(helper + 2u, 3u);
		helper_2 = OBJECT(object)->stage_7_boss.helper_2;
		mem_write8(helper_2 + 2u, 1u);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: when the first helper is done, sets all four moving. */
void stage_7_boss_move_helpers(uint16_t object)
{
	uint16_t helper = 0;
	uint8_t state = 0, action = 0;
	uint16_t helper_1 = 0, helper_2 = 0, helper_3 = 0, helper_4 = 0;

	helper_1 = OBJECT(object)->stage_7_boss.helper_1;
	helper = helper_1;
	state = OBJECT(helper)->state;
	if (state == 0u)
	{
		OBJECT(helper)->state = 3u;
		helper_2 = OBJECT(object)->stage_7_boss.helper_2;
		mem_write8(helper_2 + 2u, 1u);
		helper_3 = OBJECT(object)->stage_7_boss.helper_3;
		mem_write8(helper_3 + 2u, 3u);
		helper_4 = OBJECT(object)->stage_7_boss.helper_4;
		mem_write8(helper_4 + 2u, 1u);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: when the helpers are done, comes forward. */
void stage_7_boss_step_forward(uint16_t object)
{
	uint8_t t1 = 0, action = 0;
	uint16_t helper = 0;

	helper = OBJECT(object)->stage_7_boss.helper_1;
	t1 = mem_read8(helper + 2u);
	if (t1 == 0u)
	{
		OBJECT(object)->y_speed = -0x40;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: stops in its place, poses and sends the helpers to theirs. */
void stage_7_boss_arrive(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action = 0;
	uint16_t t1 = 0, t2 = 0, helper = 0, helper_2 = 0, helper_3 = 0, helper_4 = 0;

	t1 = OBJECT(object)->y;
	t2 = t1 - camera_y;
	if ((int16_t)t2 > 0xC8)
		return;
	OBJECT(object)->attributes = 0u;
	OBJECT(object)->y_speed = 0;
	animation_number = 0xD00u;
	carry = stage_7_boss_set_animation(object, animation_number);
	helper = OBJECT(object)->stage_7_boss.helper_1;
	mem_write8(helper + 2u, 6u);
	helper_2 = OBJECT(object)->stage_7_boss.helper_2;
	mem_write8(helper_2 + 2u, 5u);
	helper_3 = OBJECT(object)->stage_7_boss.helper_3;
	mem_write8(helper_3 + 2u, 4u);
	helper_4 = OBJECT(object)->stage_7_boss.helper_4;
	mem_write8(helper_4 + 2u, 2u);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss' entrance: waits for its pose to end. */
void stage_7_boss_entrance_pose(uint16_t object)
{
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		OBJECT(object)->action_step = 0x40u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: after 64 frames, starts fighting. */
void stage_7_boss_entrance_end(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->action = 0u;
		OBJECT(object)->state = 1u;
	}
}

/* Stage 7's boss walks toward its target at its speed by rank. */
uint16_t stage_7_boss_walk(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, heading = 0, u = 0;
	uint8_t animation = 0, side_direction = 0;

	stage_7_boss_approach(object, &u, &carry);
	if (carry)
		return y;
	stage_7_boss_pick_target(object, y, u);
	animation = OBJECT(object)->animation;
	if (animation != 0u)
	{
		animation_number = 0x100u;
		carry = stage_7_boss_set_animation(object, animation_number);
	}
	stage_7_boss_aim(object);
	side_direction = OBJECT(object)->stage_7_boss.side_direction;
	y = stage_7_boss_speeds_by_rank_ADDRESS;
	heading = ((uint32_t)side_direction << 8) | stage_7_boss_speeds_by_rank[rank >> 1];
	vector_set_speed_by_direction(object, heading);
	stage_7_boss_face_target(object);
	return y;
}

/* Stage 7's boss attacks (state 2), by its step. */
uint16_t stage_7_boss_attack(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_attack_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_wind_up(object);
			return y;
		case 2:
			stage_7_boss_strike(object);
			return y;
		case 4:
			return stage_7_boss_recover(object, y);
		case 6:
			stage_7_boss_charging(object);
			return y;
		case 8:
			return stage_7_boss_charge_end(object, y);
		case 10:
			stage_7_boss_jump_rise(object);
			return y;
		case 12:
			stage_7_boss_jump_land(object);
			return y;
		case 14:
			break;
		case -48:
			return stage_7_boss_beaten(object, y);
		case -46:
			return stage_7_boss_knocked_down(object, y);
		case -44:
			return stage_7_boss_flinch(object, y);
		case -42:
			return stage_7_boss_entrance(object, y);
		case -40:
			return stage_7_boss_walk(object, y);
		case -38:
			continue;
		case -36:
			return stage_7_boss_charge(object, y);
		case -34:
			return stage_7_boss_jump_away(object, y);
		case -32:
			return stage_7_boss_idle(object, y, action_handlers);
		case -30:
			return stage_7_boss_wait_target_up(object, y);
		case -28:
			stage_7_boss_beaten_wait(object);
			return y;
		case -26:
			stage_7_boss_blink_out(object, carry);
			return y;
		case -24:
			stage_7_boss_fall(object);
			return y;
		case -22:
			stage_7_boss_lie(object);
			return y;
		case -20:
			return stage_7_boss_get_up(object, y);
		case -18:
			stage_7_boss_flinch_wait(object);
			return y;
		case -16:
			return stage_7_boss_flinch_land(object, y);
		case -14:
			return stage_7_boss_put_in(object);
		case -12:
			stage_7_boss_start_entrance(object);
			return y;
		case -10:
			stage_7_boss_move_helpers(object);
			return y;
		case -8:
			stage_7_boss_step_forward(object);
			return y;
		case -6:
			stage_7_boss_arrive(object);
			return y;
		case -4:
			stage_7_boss_entrance_pose(object);
			return y;
		case -2:
			stage_7_boss_entrance_end(object);
			return y;
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss attacks: after a wait, winds up (sound 6A00), not to be hurt meanwhile. */
void stage_7_boss_wind_up(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;
	uint8_t action_step = 0, action_step_2 = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	if (action_step != 0u)
	{
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 - 1u;
		return;
	}
	command = 0x6A00u;
	carry = vector_queue_sound(command);
	animation_number = 0x200u;
	carry = stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->flags |= 4u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss attacks: hits on the animation's marked frame. */
void stage_7_boss_strike(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t own_box = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action = 0;

	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		own_box = 1u;
	d = (uint32_t)own_box << 8;
	stage_7_boss_set_hit_box(object, &ignored16, &d);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 1u) == 0u)
		return;
	d &= 0xFFu;
	carry = stage_7_boss_set_animation(object, d);
	OBJECT(object)->action_step = 0x10u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss attacks: after 16 frames, stands and picks its target again. */
uint16_t stage_7_boss_recover(uint16_t object, uint16_t y)
{
	uint16_t u = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return y;
	u = stage_7_boss_stand(object);
	y = stage_7_boss_pick_target(object, y, u);
	return y;
}

/* Stage 7's boss charges (state 3), by its step. */
uint16_t stage_7_boss_charge(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_charge_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_charging(object);
			return y;
		case 2:
			return stage_7_boss_charge_end(object, y);
		case 4:
			stage_7_boss_jump_rise(object);
			return y;
		case 6:
			stage_7_boss_jump_land(object);
			return y;
		case 8:
			break;
		case -54:
			return stage_7_boss_beaten(object, y);
		case -52:
			return stage_7_boss_knocked_down(object, y);
		case -50:
			return stage_7_boss_flinch(object, y);
		case -48:
			return stage_7_boss_entrance(object, y);
		case -46:
			return stage_7_boss_walk(object, y);
		case -44:
			return stage_7_boss_attack(object, y);
		case -42:
			continue;
		case -40:
			return stage_7_boss_jump_away(object, y);
		case -38:
			return stage_7_boss_idle(object, y, action_handlers);
		case -36:
			return stage_7_boss_wait_target_up(object, y);
		case -34:
			stage_7_boss_beaten_wait(object);
			return y;
		case -32:
			stage_7_boss_blink_out(object, carry);
			return y;
		case -30:
			stage_7_boss_fall(object);
			return y;
		case -28:
			stage_7_boss_lie(object);
			return y;
		case -26:
			return stage_7_boss_get_up(object, y);
		case -24:
			stage_7_boss_flinch_wait(object);
			return y;
		case -22:
			return stage_7_boss_flinch_land(object, y);
		case -20:
			return stage_7_boss_put_in(object);
		case -18:
			stage_7_boss_start_entrance(object);
			return y;
		case -16:
			stage_7_boss_move_helpers(object);
			return y;
		case -14:
			stage_7_boss_step_forward(object);
			return y;
		case -12:
			stage_7_boss_arrive(object);
			return y;
		case -10:
			stage_7_boss_entrance_pose(object);
			return y;
		case -8:
			stage_7_boss_entrance_end(object);
			return y;
		case -6:
			stage_7_boss_wind_up(object);
			return y;
		case -4:
			stage_7_boss_strike(object);
			return y;
		case -2:
			return stage_7_boss_recover(object, y);
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss charges at its target, turning toward it a little each frame, with a sound every 64
   frames, until its time runs out. */
void stage_7_boss_charging(uint16_t object)
{
	uint32_t negative = 0, carry = 0;
	uint8_t attributes = 0, charge_direction = 0;
	uint16_t box_number = 0, command = 0, d = 0, heading = 0, ignored16 = 0, ignored16_2 = 0, u = 0;
	uint8_t action = 0, animation_flags = 0, charge_direction_2 = 0, charge_direction_3 = 0, attributes_2 = 0, charge_direction_4 = 0, charge_direction_5 = 0, charge_direction_6 = 0;
	uint16_t charge_time = 0;

	box_number = 0u;
	stage_7_boss_set_hit_box(object, &u, &box_number);
	if ((frame_count & 0x3Fu) == 0u)
	{
		command = 0x7600u;
		carry = vector_queue_sound(command);
	}
	charge_time = OBJECT(object)->stage_7_boss.charge_time;
	OBJECT(object)->stage_7_boss.charge_time = charge_time - 1u;
	if (charge_time == 1u)
	{
		OBJECT(object)->action_step = 0x20u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		box_number = 0u;
		stage_7_boss_set_hit_box(object, &ignored16_2, &box_number);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
		return;
	}
	find_nearest_player(object, &u, &ignored16, &carry);
	if (carry == 0u)
	{
		OBJECT(object)->action_step = 0x20u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		box_number = 0u;
		stage_7_boss_set_hit_box(object, &ignored16_2, &box_number);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
		return;
	}
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		box_number = 0x200u;
		stage_7_boss_set_hit_box(object, &u, &box_number);
	}
	d = vector_direction_to(object, u);
	charge_direction = (uint8_t)(d >> 8);
	charge_direction_2 = OBJECT(object)->stage_7_boss.charge_direction;
	negative = (uint8_t)(charge_direction - charge_direction_2) >> 7;
	if (charge_direction == charge_direction_2)
	{
		charge_direction_3 = OBJECT(object)->stage_7_boss.charge_direction;
		heading = ((uint32_t)charge_direction_3 << 8) | 0x40u;
		vector_set_speed_by_direction(object, heading);
		attributes_2 = OBJECT(object)->attributes;
		attributes = attributes_2 & 0xBFu;
		charge_direction_4 = OBJECT(object)->stage_7_boss.charge_direction;
		if ((int8_t)(charge_direction_4 + 0x40u) < 0)
			attributes |= 0x40u;
		OBJECT(object)->attributes = attributes;
		return;
	}
	if (negative == 0u)
	{
		charge_direction_5 = OBJECT(object)->stage_7_boss.charge_direction;
		OBJECT(object)->stage_7_boss.charge_direction = charge_direction_5 + 1u;
		charge_direction_3 = OBJECT(object)->stage_7_boss.charge_direction;
		heading = ((uint32_t)charge_direction_3 << 8) | 0x40u;
		vector_set_speed_by_direction(object, heading);
		attributes_2 = OBJECT(object)->attributes;
		attributes = attributes_2 & 0xBFu;
		charge_direction_4 = OBJECT(object)->stage_7_boss.charge_direction;
		if ((int8_t)(charge_direction_4 + 0x40u) < 0)
			attributes |= 0x40u;
		OBJECT(object)->attributes = attributes;
		return;
	}
	charge_direction_6 = OBJECT(object)->stage_7_boss.charge_direction;
	OBJECT(object)->stage_7_boss.charge_direction = charge_direction_6 - 1u;
	charge_direction_3 = OBJECT(object)->stage_7_boss.charge_direction;
	heading = ((uint32_t)charge_direction_3 << 8) | 0x40u;
	vector_set_speed_by_direction(object, heading);
	attributes_2 = OBJECT(object)->attributes;
	attributes = attributes_2 & 0xBFu;
	charge_direction_4 = OBJECT(object)->stage_7_boss.charge_direction;
	if ((int8_t)(charge_direction_4 + 0x40u) < 0)
		attributes |= 0x40u;
	OBJECT(object)->attributes = attributes;
}

/* Stage 7's boss charges: after a short stop, stands and picks its target again. */
uint16_t stage_7_boss_charge_end(uint16_t object, uint16_t y)
{
	uint16_t u = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return y;
	u = stage_7_boss_stand(object);
	y = stage_7_boss_pick_target(object, y, u);
	return y;
}

/* Stage 7's boss jumps away (state 4), by its step. */
uint16_t stage_7_boss_jump_away(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = stage_7_boss_jump_away_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			stage_7_boss_jump_rise(object);
			return y;
		case 2:
			stage_7_boss_jump_land(object);
			return y;
		case 4:
			break;
		case -58:
			return stage_7_boss_beaten(object, y);
		case -56:
			return stage_7_boss_knocked_down(object, y);
		case -54:
			return stage_7_boss_flinch(object, y);
		case -52:
			return stage_7_boss_entrance(object, y);
		case -50:
			return stage_7_boss_walk(object, y);
		case -48:
			return stage_7_boss_attack(object, y);
		case -46:
			return stage_7_boss_charge(object, y);
		case -44:
			continue;
		case -42:
			return stage_7_boss_idle(object, y, action_handlers);
		case -40:
			return stage_7_boss_wait_target_up(object, y);
		case -38:
			stage_7_boss_beaten_wait(object);
			return y;
		case -36:
			stage_7_boss_blink_out(object, carry);
			return y;
		case -34:
			stage_7_boss_fall(object);
			return y;
		case -32:
			stage_7_boss_lie(object);
			return y;
		case -30:
			return stage_7_boss_get_up(object, y);
		case -28:
			stage_7_boss_flinch_wait(object);
			return y;
		case -26:
			return stage_7_boss_flinch_land(object, y);
		case -24:
			return stage_7_boss_put_in(object);
		case -22:
			stage_7_boss_start_entrance(object);
			return y;
		case -20:
			stage_7_boss_move_helpers(object);
			return y;
		case -18:
			stage_7_boss_step_forward(object);
			return y;
		case -16:
			stage_7_boss_arrive(object);
			return y;
		case -14:
			stage_7_boss_entrance_pose(object);
			return y;
		case -12:
			stage_7_boss_entrance_end(object);
			return y;
		case -10:
			stage_7_boss_wind_up(object);
			return y;
		case -8:
			stage_7_boss_strike(object);
			return y;
		case -6:
			return stage_7_boss_recover(object, y);
		case -4:
			stage_7_boss_charging(object);
			return y;
		case -2:
			return stage_7_boss_charge_end(object, y);
		}
		break;
	}
	stage_7_boss_jump_end(object);
	return y;
}

/* Stage 7's boss jumps away: in the air until its animation ends. */
void stage_7_boss_jump_rise(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, d = 0;
	uint8_t animation_flags = 0, action = 0;

	vector_apply_gravity(object, &d, &carry);
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	animation_number = (d & 0xFFu) | 0xC00u;
	carry = stage_7_boss_set_animation(object, animation_number);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss jumps away: lands. */
void stage_7_boss_jump_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, ignored16 = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->flags &= ~8u;
	animation_number = 0xA00u;
	carry = stage_7_boss_set_animation(object, animation_number);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss jumps away: when the landing's animation ends, stands. */
void stage_7_boss_jump_end(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		stage_7_boss_stand(object);
		return;
	}
}

/* Stage 7's boss with no target (state 5): waits for a player. */
uint16_t stage_7_boss_idle(uint16_t object, uint16_t y, uint16_t nearest)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	find_nearest_player(object, &nearest, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->flags |= 0x40u;
		OBJECT(object)->state = 1u;
		OBJECT(object)->action = 0u;
		y = stage_7_boss_pick_target(object, y, nearest);
	}
	return y;
}

/* Stage 7's boss waits while its target is down, then stands (no scenario reaches it). */
uint16_t stage_7_boss_wait_target_up(uint16_t object, uint16_t y)
{
	uint16_t target_player = 0;
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(y + 0x2Bu);
	target_player = t1;
	state = OBJECT(target_player)->state;
	if ((int8_t)state >= 0)
	{
		stage_7_boss_stand(object);
		return target_player;
	}
	return target_player;
}

/* Stage 7's boss: when hit, takes the hit. */
uint16_t stage_7_boss_check_hit(uint16_t object, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t hit = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(object)->hit;
		negative = hit >> 7;
		if (hit != 0u && negative == 0u)
			y = stage_7_boss_take_hit(object, y);
	}
	return y;
}

/* Stage 7's boss walking: at its target, decides how to attack; after walking too long without reaching
   it, charges (carry: it did either). */
void stage_7_boss_approach(uint16_t object, uint16_t *p_object_2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t charge_direction = 0;
	uint16_t animation_number = 0, direction = 0, heading = 0, target = 0, wait = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0, last_health = 0, vitality = 0, vitality_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, walk_time = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, walk_time_2 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0;

	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	wait = t1;
	t2 = OBJECT(object)->x;
	t3 = mem_read16(wait + 0xCu);
	if ((int16_t)t2 < (int16_t)t3)
	{
		attributes = OBJECT(object)->attributes;
		if ((attributes & 0x40u) != 0u)
		{
			walk_time = OBJECT(object)->stage_7_boss.walk_time;
			OBJECT(object)->stage_7_boss.walk_time = walk_time + 1u;
			carry = 0u;
			*p_object_2 = wait;
			*p_carry = carry;
			return;
		}
	}
	else
	{
		attributes_2 = OBJECT(object)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
		{
			walk_time = OBJECT(object)->stage_7_boss.walk_time;
			OBJECT(object)->stage_7_boss.walk_time = walk_time + 1u;
			carry = 0u;
			*p_object_2 = wait;
			*p_carry = carry;
			return;
		}
	}
	t4 = OBJECT(object)->x;
	t5 = mem_read16(wait + 0xCu);
	t6 = t4 - t5;
	t7 = t6;
	t8 = t7 >> 15 ? 0u - t7 : t7;
	if ((int16_t)t8 > 0x40)
	{
		wait = stage_7_boss_charge_waits_by_players_ADDRESS + (int8_t)((player_count - 1u) << 1);
		walk_time_2 = OBJECT(object)->stage_7_boss.walk_time;
		if ((int16_t)walk_time_2 < (int16_t)CHARGE_WAIT(wait))
		{
			walk_time = OBJECT(object)->stage_7_boss.walk_time;
			OBJECT(object)->stage_7_boss.walk_time = walk_time + 1u;
			carry = 0u;
			*p_object_2 = wait;
			*p_carry = carry;
			return;
		}
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->stage_7_boss.walk_time = 0u;
		OBJECT(object)->state = 3u;
		OBJECT(object)->action = 0u;
		animation_number = 0x300u;
		carry = stage_7_boss_set_animation(object, animation_number);
		direction = 0x200u;
		stage_7_boss_set_hit_box(object, &wait, &direction);
		find_nearest_player(object, &wait, &direction, &carry);
		direction = vector_direction_to_offset(object, wait, direction);
		charge_direction = (uint8_t)(direction >> 8);
		OBJECT(object)->stage_7_boss.charge_direction = charge_direction;
		heading = ((uint32_t)charge_direction << 8) | 0x40u;
		vector_set_speed_by_direction(object, heading);
		OBJECT(object)->stage_7_boss.charge_time = 0xA0u;
		carry = 1u;
		*p_object_2 = wait;
		*p_carry = carry;
		return;
	}
	t9 = OBJECT(object)->y;
	t10 = mem_read16(wait + 0x11u);
	t11 = t9 - t10;
	t12 = t11;
	t13 = t12 >> 15 ? 0u - t12 : t12;
	if ((int16_t)t13 > 8)
	{
		walk_time = OBJECT(object)->stage_7_boss.walk_time;
		OBJECT(object)->stage_7_boss.walk_time = walk_time + 1u;
		carry = 0u;
		*p_object_2 = wait;
		*p_carry = carry;
		return;
	}
	t14 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target = t14;
	state = OBJECT(target)->state;
	if ((int8_t)state < 0)
	{
		carry = stage_7_boss_go_idle(object);
		*p_object_2 = target;
		*p_carry = carry;
		return;
	}
	OBJECT(object)->action_step = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 2u;
	OBJECT(object)->action = 0u;
	animation_number = 0x100u;
	carry = stage_7_boss_set_animation(object, animation_number);
	stage_7_boss_face_target(object);
	wait = stage_7_boss_quick_attack_chances_by_players_ADDRESS;
	if (stage_7_boss_quick_attack_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))] <= random_number)
	{
		last_health = OBJECT(object)->stage_7_boss.last_health;
		vitality = OBJECT(object)->vitality;
		if ((uint8_t)(last_health - vitality) < 0x14u)
		{
			OBJECT(object)->action_step = 0x20u;
			carry = 1u;
			*p_object_2 = wait;
			*p_carry = carry;
			return;
		}
	}
	vitality_2 = OBJECT(object)->vitality;
	OBJECT(object)->stage_7_boss.last_health = vitality_2;
	carry = 1u;
	*p_object_2 = wait;
	*p_carry = carry;
}

/* Stage 7's boss: keeps its target a while, then takes the nearest player; with none present, goes idle. */
uint16_t stage_7_boss_pick_target(uint16_t object, uint16_t y, uint16_t nearest)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, target_player = 0;
	uint8_t state = 0, target_wait = 0, target_wait_2 = 0;
	uint16_t t1 = 0;

	find_nearest_player(object, &nearest, &ignored16, &carry);
	if (carry == 0u)
	{
		carry = stage_7_boss_go_idle(object);
		return y;
	}
	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target_player = t1;
	if (OBJECT(target_player)->flags != 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state >= 0)
		{
			target_wait = OBJECT(object)->stage_7_boss.target_wait;
			if (target_wait != 0u)
			{
				target_wait_2 = OBJECT(object)->stage_7_boss.target_wait;
				OBJECT(object)->stage_7_boss.target_wait = target_wait_2 - 1u;
				return target_player;
			}
		}
	}
	OBJECT(object)->stage_7_boss.target_wait = 0x40u;
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((nearest >> 8u) & 0xFFu);
	OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((nearest & 0xFFu) << 8u);
	return target_player;
}

/* Stage 7's boss: the direction to the side of its target (field 2D) and to the target itself (2E). */
void stage_7_boss_aim(uint16_t object)
{
	uint8_t side_offset = 0;
	uint16_t aim_direction = 0, direction = 0, target_player = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target_player = t1;
	t2 = OBJECT(object)->x;
	t3 = OBJECT(target_player)->x;
	if ((int16_t)t3 < (int16_t)t2)
		side_offset = 0x20u;
	else
		side_offset = 0xE0u;
	aim_direction = side_offset;
	aim_direction = vector_direction_to_offset(object, target_player, aim_direction);
	OBJECT(object)->stage_7_boss.side_direction = ((aim_direction & ~0xFFu) | side_offset) >> 8;
	direction = vector_direction_to(object, target_player);
	OBJECT(object)->stage_7_boss.direction = (direction | side_offset) >> 8;
}

/* Stage 7's boss: turns to face its target. */
void stage_7_boss_face_target(uint16_t object)
{
	uint8_t direction = 0, attributes = 0, attributes_2 = 0;

	direction = OBJECT(object)->stage_7_boss.direction;
	if ((uint8_t)(direction + 0x40u) >= 0x80u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
		return;
	}
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes_2 & 0xBFu;
}

/* Stage 7's boss: sets the given animation (stage_7_boss_animations). */
uint32_t stage_7_boss_set_animation(uint16_t object, uint16_t animation_number)
{
	uint32_t carry = 0;
	uint8_t animation_index = 0;
	uint16_t t1 = 0;
	uint32_t kind_halfword = 0;

	animation_index = (uint8_t)(animation_number >> 8);
	carry = (int8_t)animation_index < 0;
	t1 = stage_7_boss_animations[animation_index & 0x7Fu];
	kind_halfword = ((uint32_t)(t1 >> 8) << 8) | (uint8_t)(t1 | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	return carry;
}

/* Stage 7's boss: sets the given hit box (stage_7_boss_hit_boxes). */
void stage_7_boss_set_hit_box(uint16_t object, uint16_t *p_box_end, uint16_t *p_box_number)
{
	uint16_t box_number = (uint16_t)*p_box_number;
	uint16_t box_end = 0;
	uint16_t t1 = 0, field_1c = 0, t2 = 0, field_1f = 0, t3 = 0, field = 0, t4 = 0, field_23 = 0;
	uint32_t box_dy_halfword = 0;

	t1 = stage_7_boss_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(box_number >> 8) << 1) << 1) << 1);
	field_1c = HIT_BOX(t1)->field_1c;
	OBJECT(object)->damage = (uint8_t)(field_1c >> 8u);
	OBJECT(object)->attack = (uint8_t)field_1c;
	t2 = t1 + 2u;
	field_1f = HIT_BOX(t2 - 0x2u)->field_1f;
	OBJECT(object)->box_width = (uint8_t)(field_1f >> 8u);
	OBJECT(object)->box_depth = (uint8_t)field_1f;
	t3 = t2 + 2u;
	field = HIT_BOX(t3 - 0x4u)->field_21;
	OBJECT(object)->box_height = (uint8_t)(field >> 8u);
	OBJECT(object)->box_dx = (uint8_t)field;
	t4 = t3 + 2u;
	box_end = t4 + 2u;
	field_23 = HIT_BOX(t4 - 0x6u)->field_23;
	box_number = field_23;
	box_dy_halfword = ((uint32_t)(field_23 >> 8) << 8) | (box_number & 0xFFu);
	OBJECT(object)->box_dy = (uint8_t)(box_dy_halfword >> 8u);
	OBJECT(object)->box_dz = (uint8_t)box_dy_halfword;
	*p_box_end = box_end;
	*p_box_number = box_number;
}

/* Stage 7's boss: stops it at the left and right edges of its area. */
void stage_7_boss_keep_in_x(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t next_stage_x = 0, next_x_and_fraction = 0, x_and_fraction = 0;
	uint8_t x_speed_2 = 0, t2 = 0;
	uint16_t t1 = 0, x_speed = 0, t3 = 0;

	t1 = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
	x_and_fraction = t1;
	x_speed = OBJECT(object)->x_speed;
	carry = (uint16_t)(x_and_fraction + x_speed) < x_and_fraction;
	area_next_x = x_and_fraction + x_speed;
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	t2 = (uint8_t)(OBJECT(object)->x >> 8u);
	area_next_x_high = (uint16_t)((uint32_t)(uint8_t)(((uint16_t)(int8_t)x_speed_2 >> 8) + t2 + carry) << 8) >> 8;
	next_x_and_fraction = area_next_x;
	t3 = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	carry = (uint16_t)(next_x_and_fraction + t3) < next_x_and_fraction;
	area_next_x = next_x_and_fraction + t3;
	next_stage_x = ((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(camera_x >> 8u) << 8) >> 8) + area_next_x_high + carry) << 8) | area_next_x_pixels;
	if ((int16_t)next_stage_x <= 0x8B0 || (int16_t)next_stage_x >= 0xA0F)
		OBJECT(object)->x_speed = 0;
}

/* Stage 7's boss: stops it at the front and back edges of its area. */
void stage_7_boss_keep_in_y(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t next_y_high = 0, next_y_low = 0;
	uint8_t state = 0, y_speed_2 = 0, t4 = 0;
	uint16_t t1 = 0, y_speed = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	state = OBJECT(object)->state;
	if (state != 0u)
	{
		t1 = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
		y_speed = OBJECT(object)->y_speed;
		t2 = t1;
		t3 = t2 + y_speed;
		carry = (uint16_t)(t2 + y_speed) < t2;
		area_next_y = t3;
		y_speed_2 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
		t4 = (uint8_t)(OBJECT(object)->y >> 8u);
		area_next_y_high = ((uint16_t)(int8_t)y_speed_2 >> 8) + t4 + carry;
		t5 = area_next_y;
		t6 = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
		t7 = t5;
		t8 = t7 - t6;
		carry = t7 < t6;
		area_next_y = t8;
		next_y_high = (uint8_t)(camera_y >> 8u) + area_next_y_high + carry;
		next_y_low = area_next_y_pixels;
		if ((int16_t)(((uint32_t)next_y_high << 8) | next_y_low) <= 0x78 || (int16_t)(((uint32_t)next_y_high << 8) | next_y_low) >= 0xC8)
			OBJECT(object)->y_speed = 0;
	}
}

/* Stage 7's boss: every so often by the rank, sends some of its idle helpers to throw. */
uint16_t stage_7_boss_order_throws(uint16_t object, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t other_enemies = 0, throws = 0;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint8_t state = 0, vitality = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t throw_wait = 0, t1 = 0, t2 = 0, throw_wait_2 = 0;

	state = OBJECT(object)->state;
	if (state != 0u)
	{
		vitality = OBJECT(object)->vitality;
		if (vitality != 0u)
		{
			throw_wait = OBJECT(object)->stage_7_boss.throw_wait;
			t1 = throw_wait + 1u;
			OBJECT(object)->stage_7_boss.throw_wait = t1;
			t2 = stage_7_boss_helper_attack_times_by_rank[(int8_t)(rank & ~1u) / 2];
			throw_wait_2 = OBJECT(object)->stage_7_boss.throw_wait;
			if ((int16_t)t2 <= (int16_t)throw_wait_2)
			{
				OBJECT(object)->stage_7_boss.throw_wait = 0u;
				throw_helper = random_number & 3u;
				t3 = io_read8(0x1880u);
				other_enemies = t3 - 1u;
				stack = other_enemies;
				t4 = ((uint8_t)(player_count - 1u) >> 1) + 1u;
				t5 = t4 - stack;
				negative = t5 >> 7;
				throws = t5;
				if (t4 != stack && negative == 0u)
				{
					helper_throws_left = throws;
					do
					{
						d = ((throw_helper & 3u) << 8) | other_enemies;
						y = stage_7_boss_order_throw(object, y, d);
						other_enemies = (uint8_t)d;
						throw_helper++;
						t6 = helper_throws_left;
						helper_throws_left = t6 - 1u;
					} while (t6 != 1u);
				}
			}
		}
	}
	return y;
}

/* Stage 7's boss: the given helper, if idle, gets its missile and starts throwing. */
uint16_t stage_7_boss_order_throw(uint16_t object, uint16_t y, uint16_t helper_number)
{
	uint32_t carry = 0;
	uint16_t helper = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t state = 0;

	helper = mem_read16(object + (uint8_t)(((uint32_t)(helper_number >> 8) << 1) + 0x33u));
	state = OBJECT(helper)->state;
	if (state != 0u)
		return y;
	y = stage_7_boss_order_throw_child_ADDRESS;
	vector_spawn_child(helper, y, &ignored16, &ignored16_2, &carry);
	if (carry)
		OBJECT(helper)->state = 7u;
	return y;
}

/* Stage 7's boss stands and goes back to walking. */
uint16_t stage_7_boss_stand(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box_number = 0, u = 0;

	animation_number = 0x100u;
	carry = stage_7_boss_set_animation(object, animation_number);
	box_number = 0u;
	stage_7_boss_set_hit_box(object, &u, &box_number);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0x40u) & ~4u;
	OBJECT(object)->state = 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return u;
}

/* Stage 7's boss has no target left: waits. */
uint32_t stage_7_boss_go_idle(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;

	OBJECT(object)->state = 5u;
	OBJECT(object)->action = 0u;
	animation_number = 0xA00u;
	carry = stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->flags &= 0xBFu;
	return carry;
}

/* Stage 7's boss takes a hit: flashes; with no health left it is knocked down; on a heavy hit (or every
   third) it jumps away to the middle or is knocked down, else it flinches. */
uint16_t stage_7_boss_take_hit(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, d = 0, ignored16 = 0, object_2 = 0, palette_effect_number = 0;
	uint8_t vitality = 0, direction = 0, hit = 0, hits = 0, hits_2 = 0, attributes = 0, attributes_2 = 0;
	uint16_t hit_by = 0, t1 = 0;

	hit_by = OBJECT(object)->hit_by;
	object_2 = hit_by;
	OBJECT(object_2)->behaviour = (OBJECT(object_2)->behaviour & 0xFFu) | 0x100u;
	AT16(OBJECT(object_2)->hit_box, -1) = object;
	OBJECT(object)->flags &= 0xBBu;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	palette_request_kind = 2u;
	palette_effect_number = 0x28u;
	vector_palette_request(palette_effect_number, &y, &object_2);
	command = 0x6600u;
	carry = vector_queue_sound(command);
	d = 0u;
	stage_7_boss_set_hit_box(object, &ignored16, &d);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		d = 0x6600u;
		carry = vector_queue_sound_unless_attract(d);
		animation_number = (d & 0xFFu) | 0x500u;
		carry = stage_7_boss_set_animation(object, animation_number);
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0x400;
		direction = OBJECT(object)->stage_7_boss.direction;
		if ((uint8_t)(direction + 0x40u) < 0x80u)
		{
			OBJECT(object)->x_speed = -0x300;
			return y;
		}
		OBJECT(object)->x_speed = 0x300;
		return y;
	}
	hit = OBJECT(object)->hit;
	if (hit != 0x13u)
	{
		hits = OBJECT(object)->stage_7_boss.hits;
		if (hits != 2u)
		{
			hits_2 = OBJECT(object)->stage_7_boss.hits;
			OBJECT(object)->stage_7_boss.hits = hits_2 + 1u;
			animation_number = (d & 0xFFu) | 0x400u;
			carry = stage_7_boss_set_animation(object, animation_number);
			OBJECT(object)->state = 0xFFu;
			OBJECT(object)->action = 0u;
			return y;
		}
	}
	OBJECT(object)->stage_7_boss.hits = 0u;
	if (stage_7_boss_jump_away_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))] < random_number)
	{
		animation_number = (d & 0xFFu) | 0x500u;
		carry = stage_7_boss_set_animation(object, animation_number);
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0x400;
		direction = OBJECT(object)->stage_7_boss.direction;
		if ((uint8_t)(direction + 0x40u) < 0x80u)
		{
			OBJECT(object)->x_speed = -0x300;
			return y;
		}
		OBJECT(object)->x_speed = 0x300;
		return y;
	}
	OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 8u;
	t1 = OBJECT(object)->x;
	if ((int16_t)t1 <= 0xE0)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
		OBJECT(object)->x_speed = 0x300;
	}
	else
	{
		attributes_2 = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes_2 & 0xBFu;
		OBJECT(object)->x_speed = -0x300;
	}
	OBJECT(object)->z_speed = 0x900;
	animation_number = 0x900u;
	carry = stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->state = 4u;
	OBJECT(object)->action = 0u;
	return y;
}
