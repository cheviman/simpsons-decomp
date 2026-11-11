/**
 *    Name:        objects/stage_7_boss.c
 *    Description: stage 7's boss (Channel 6)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 7's boss beaten (state FD), by its step. */
void stage_7_boss_beaten(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_blink_out(object, carry);
			return;
		case 4:
			stage_7_boss_fall(object);
			return;
		case 6:
			stage_7_boss_lie(object);
			return;
		case 8:
			stage_7_boss_get_up(object);
			return;
		case 10:
			stage_7_boss_flinch_wait(object);
			return;
		case 12:
			stage_7_boss_flinch_land(object);
			return;
		case 14:
			stage_7_boss_put_in(object);
			return;
		case 16:
			stage_7_boss_start_entrance(object);
			return;
		case 18:
			stage_7_boss_move_helpers(object);
			return;
		case 20:
			stage_7_boss_step_forward(object);
			return;
		case 22:
			stage_7_boss_arrive(object);
			return;
		case 24:
			stage_7_boss_entrance_pose(object);
			return;
		case 26:
			stage_7_boss_entrance_end(object);
			return;
		case 28:
			stage_7_boss_wind_up(object);
			return;
		case 30:
			stage_7_boss_strike(object);
			return;
		case 32:
			stage_7_boss_recover(object);
			return;
		case 34:
			stage_7_boss_charging(object);
			return;
		case 36:
			stage_7_boss_charge_end(object);
			return;
		case 38:
			stage_7_boss_jump_rise(object);
			return;
		case 40:
			stage_7_boss_jump_land(object);
			return;
		case 42:
			break;
		case -20:
			continue;
		case -18:
			stage_7_boss_knocked_down(object);
			return;
		case -16:
			stage_7_boss_flinch(object);
			return;
		case -14:
			stage_7_boss_entrance(object);
			return;
		case -12:
			stage_7_boss_walk(object);
			return;
		case -10:
			stage_7_boss_attack(object);
			return;
		case -8:
			stage_7_boss_charge(object);
			return;
		case -6:
			stage_7_boss_jump_away(object);
			return;
		case -4:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -2:
			stage_7_boss_wait_target_up(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss beaten: waits, then cries out (3F3B). */
void stage_7_boss_beaten_wait(uint16_t object)
{
	uint16_t command = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	command = 0x3F3Bu;
	vector_queue_sound(command);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss beaten: blinks for 192 frames, then it is gone (sound 9600), the boss counts as beaten
   and the step goes on. */
void stage_7_boss_blink_out(uint16_t object, uint32_t carry)
{
	uint8_t frame_bit = 0;
	uint16_t command = 0;
	uint8_t rotated_once = 0, action_step = 0, action_step_2 = 0, points = 0;

	OBJECT(object)->flags &= 0x7Fu;
	frame_bit = (uint8_t)frame_count & 1u;
	rotated_once = (frame_bit >> 1) | (carry << 7);
	carry = frame_bit;
	OBJECT(object)->flags |= (rotated_once >> 1) | (carry << 7);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	action_step_2 = OBJECT(object)->action_step;
	if (action_step_2 != 0xC0u)
		return;
	command = 0x9600u;
	vector_queue_sound(command);
	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x81u;
	OBJECT(object)->flags = 0u;
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
}

/* Stage 7's boss knocked down (state FE), by its step. */
void stage_7_boss_knocked_down(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_lie(object);
			return;
		case 4:
			stage_7_boss_get_up(object);
			return;
		case 6:
			stage_7_boss_flinch_wait(object);
			return;
		case 8:
			stage_7_boss_flinch_land(object);
			return;
		case 10:
			stage_7_boss_put_in(object);
			return;
		case 12:
			stage_7_boss_start_entrance(object);
			return;
		case 14:
			stage_7_boss_move_helpers(object);
			return;
		case 16:
			stage_7_boss_step_forward(object);
			return;
		case 18:
			stage_7_boss_arrive(object);
			return;
		case 20:
			stage_7_boss_entrance_pose(object);
			return;
		case 22:
			stage_7_boss_entrance_end(object);
			return;
		case 24:
			stage_7_boss_wind_up(object);
			return;
		case 26:
			stage_7_boss_strike(object);
			return;
		case 28:
			stage_7_boss_recover(object);
			return;
		case 30:
			stage_7_boss_charging(object);
			return;
		case 32:
			stage_7_boss_charge_end(object);
			return;
		case 34:
			stage_7_boss_jump_rise(object);
			return;
		case 36:
			stage_7_boss_jump_land(object);
			return;
		case 38:
			break;
		case -24:
			stage_7_boss_beaten(object);
			return;
		case -22:
			continue;
		case -20:
			stage_7_boss_flinch(object);
			return;
		case -18:
			stage_7_boss_entrance(object);
			return;
		case -16:
			stage_7_boss_walk(object);
			return;
		case -14:
			stage_7_boss_attack(object);
			return;
		case -12:
			stage_7_boss_charge(object);
			return;
		case -10:
			stage_7_boss_jump_away(object);
			return;
		case -8:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -6:
			stage_7_boss_wait_target_up(object);
			return;
		case -4:
			stage_7_boss_beaten_wait(object);
			return;
		case -2:
			stage_7_boss_blink_out(object, carry);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss knocked down: falls; landing with too little health it is beaten, else it lies. */
void stage_7_boss_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, landing_result = 0;
	uint8_t vitality = 0, ninja_vanish_signal = 0, shadow_player = 0, action = 0;
	uint16_t hit_by = 0;

	vector_apply_gravity(object, &landing_result, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (vitality <= stage_7_boss_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))])
	{
		OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 4u;
		animation_number = (landing_result & 0xFFu) | 0x800u;
		stage_7_boss_set_animation(object, animation_number);
		ninja_vanish_signal = io_read8(ninjas_dismissed);
		io_write8(ninjas_dismissed, ninja_vanish_signal + 1u);
		command = 0x9800u;
		vector_queue_sound(command);
		hit_by = OBJECT(object)->hit_by;
		shadow_player = OBJECT(hit_by)->shadow_player;
		OBJECT(object)->points = shadow_player & ~0xFu;
		OBJECT(object)->action_step = 0xC0u;
		OBJECT(object)->vitality = 0u;
		OBJECT(object)->state = 0xFDu;
		OBJECT(object)->action = 0u;
		return;
	}
	animation_number = (landing_result & 0xFFu) | 0xB00u;
	stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss knocked down: lies for 64 frames, then starts getting up. */
void stage_7_boss_lie(uint16_t object)
{
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	animation_number = 0x700u;
	stage_7_boss_set_animation(object, animation_number);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss knocked down: once up, stands and picks its target again. */
void stage_7_boss_get_up(uint16_t object)
{
	uint16_t box_end = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	box_end = stage_7_boss_stand(object);
	stage_7_boss_pick_target(object, box_end);
}

/* Stage 7's boss hit (state FF), by its step. */
void stage_7_boss_flinch(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_flinch_land(object);
			return;
		case 4:
			stage_7_boss_put_in(object);
			return;
		case 6:
			stage_7_boss_start_entrance(object);
			return;
		case 8:
			stage_7_boss_move_helpers(object);
			return;
		case 10:
			stage_7_boss_step_forward(object);
			return;
		case 12:
			stage_7_boss_arrive(object);
			return;
		case 14:
			stage_7_boss_entrance_pose(object);
			return;
		case 16:
			stage_7_boss_entrance_end(object);
			return;
		case 18:
			stage_7_boss_wind_up(object);
			return;
		case 20:
			stage_7_boss_strike(object);
			return;
		case 22:
			stage_7_boss_recover(object);
			return;
		case 24:
			stage_7_boss_charging(object);
			return;
		case 26:
			stage_7_boss_charge_end(object);
			return;
		case 28:
			stage_7_boss_jump_rise(object);
			return;
		case 30:
			stage_7_boss_jump_land(object);
			return;
		case 32:
			break;
		case -30:
			stage_7_boss_beaten(object);
			return;
		case -28:
			stage_7_boss_knocked_down(object);
			return;
		case -26:
			continue;
		case -24:
			stage_7_boss_entrance(object);
			return;
		case -22:
			stage_7_boss_walk(object);
			return;
		case -20:
			stage_7_boss_attack(object);
			return;
		case -18:
			stage_7_boss_charge(object);
			return;
		case -16:
			stage_7_boss_jump_away(object);
			return;
		case -14:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -12:
			stage_7_boss_wait_target_up(object);
			return;
		case -10:
			stage_7_boss_beaten_wait(object);
			return;
		case -8:
			stage_7_boss_blink_out(object, carry);
			return;
		case -6:
			stage_7_boss_fall(object);
			return;
		case -4:
			stage_7_boss_lie(object);
			return;
		case -2:
			stage_7_boss_get_up(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
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
void stage_7_boss_flinch_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box_end = 0, ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	box_end = stage_7_boss_stand(object);
	stage_7_boss_pick_target(object, box_end);
}

/* Stage 7's boss' entrance (state 0), by its step. */
void stage_7_boss_entrance(uint16_t object)
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
			stage_7_boss_put_in(object);
			return;
		case 2:
			stage_7_boss_start_entrance(object);
			return;
		case 4:
			stage_7_boss_move_helpers(object);
			return;
		case 6:
			stage_7_boss_step_forward(object);
			return;
		case 8:
			stage_7_boss_arrive(object);
			return;
		case 10:
			stage_7_boss_entrance_pose(object);
			return;
		case 12:
			stage_7_boss_entrance_end(object);
			return;
		case 14:
			stage_7_boss_wind_up(object);
			return;
		case 16:
			stage_7_boss_strike(object);
			return;
		case 18:
			stage_7_boss_recover(object);
			return;
		case 20:
			stage_7_boss_charging(object);
			return;
		case 22:
			stage_7_boss_charge_end(object);
			return;
		case 24:
			stage_7_boss_jump_rise(object);
			return;
		case 26:
			stage_7_boss_jump_land(object);
			return;
		case 28:
			break;
		case -34:
			stage_7_boss_beaten(object);
			return;
		case -32:
			stage_7_boss_knocked_down(object);
			return;
		case -30:
			stage_7_boss_flinch(object);
			return;
		case -28:
			continue;
		case -26:
			stage_7_boss_walk(object);
			return;
		case -24:
			stage_7_boss_attack(object);
			return;
		case -22:
			stage_7_boss_charge(object);
			return;
		case -20:
			stage_7_boss_jump_away(object);
			return;
		case -18:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -16:
			stage_7_boss_wait_target_up(object);
			return;
		case -14:
			stage_7_boss_beaten_wait(object);
			return;
		case -12:
			stage_7_boss_blink_out(object, carry);
			return;
		case -10:
			stage_7_boss_fall(object);
			return;
		case -8:
			stage_7_boss_lie(object);
			return;
		case -6:
			stage_7_boss_get_up(object);
			return;
		case -4:
			stage_7_boss_flinch_wait(object);
			return;
		case -2:
			stage_7_boss_flinch_land(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss' entrance: puts its four helpers in their places and itself, with its health. */
void stage_7_boss_put_in(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t slot_list = 0;
	uint16_t animation_number = 0, helper = 0, helper_start = 0;
	uint8_t action = 0;
	uint16_t helper_start_record = 0, start_cursor = 0, start_offset_x = 0, helper_stage_x = 0, helper_screen_x = 0, helper_y = 0, boss_screen_x = 0;

	boss_helper_number = 0u;
	do
	{
		slot_list = 1u;
		vector_find_free_slot(slot_list, &helper, &carry);
		OBJECT(helper)->flags = 0x80u;
		OBJECT(helper)->kind = 0x12u;
		helper_start_record = stage_7_boss_helper_starts_ADDRESS + (int8_t)(((uint32_t)boss_helper_number << 1) << 1);
		OBJECT(helper)->animation = HELPER_START(helper_start_record)->animation;
		OBJECT(helper)->attributes = 0x20u;
		start_cursor = helper_start_record + 1u;
		helper_start = start_cursor + 2u;
		start_offset_x = HELPER_START(start_cursor - 0x1u)->x;
		helper_stage_x = start_offset_x + 0x91Fu;
		helper_screen_x = helper_stage_x - camera_x;
		OBJECT(helper)->x = helper_screen_x;
		helper_y = 0xC8u + camera_y;
		OBJECT(helper)->y = helper_y;
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
	stage_7_boss_set_animation(object, animation_number);
	boss_screen_x = 0x96Fu - camera_x;
	OBJECT(object)->x = boss_screen_x;
	OBJECT(object)->vitality = 0xE0u;
	OBJECT(object)->stage_7_boss.last_health = 0xE0u;
	OBJECT(object)->floor_z = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	leftover_y = helper_start;
}

/* Stage 7's boss' entrance: once the camera's flag from the stage record clears, says a boss is in and
   sets two helpers moving. */
void stage_7_boss_start_entrance(uint16_t object)
{
	uint16_t first_helper = 0, second_helper = 0;
	uint8_t action = 0;
	uint16_t helper = 0, helper_2 = 0;

	if (stage_scrolls_on == 0u)
	{
		OBJECT(object)->entrance_pending = 0u;
		boss_arrived++;
		helper = OBJECT(object)->stage_7_boss.helper_1;
		first_helper = helper;
		OBJECT(first_helper)->state = 3u;
		helper_2 = OBJECT(object)->stage_7_boss.helper_2;
		second_helper = helper_2;
		OBJECT(second_helper)->state = 1u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: when the first helper is done, sets all four moving. */
void stage_7_boss_move_helpers(uint16_t object)
{
	uint16_t fourth_helper = 0, helper = 0, second_helper = 0, third_helper = 0;
	uint8_t state = 0, action = 0;
	uint16_t helper_1 = 0, helper_2 = 0, helper_3 = 0, helper_4 = 0;

	helper_1 = OBJECT(object)->stage_7_boss.helper_1;
	helper = helper_1;
	state = OBJECT(helper)->state;
	if (state == 0u)
	{
		OBJECT(helper)->state = 3u;
		helper_2 = OBJECT(object)->stage_7_boss.helper_2;
		second_helper = helper_2;
		OBJECT(second_helper)->state = 1u;
		helper_3 = OBJECT(object)->stage_7_boss.helper_3;
		third_helper = helper_3;
		OBJECT(third_helper)->state = 3u;
		helper_4 = OBJECT(object)->stage_7_boss.helper_4;
		fourth_helper = helper_4;
		OBJECT(fourth_helper)->state = 1u;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: when the helpers are done, comes forward. */
void stage_7_boss_step_forward(uint16_t object)
{
	uint16_t first_helper = 0;
	uint8_t first_helper_state = 0, action = 0;
	uint16_t helper = 0;

	helper = OBJECT(object)->stage_7_boss.helper_1;
	first_helper = helper;
	first_helper_state = OBJECT(first_helper)->state;
	if (first_helper_state == 0u)
	{
		OBJECT(object)->y_speed = -0x40;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* Stage 7's boss' entrance: stops in its place, poses and sends the helpers to theirs. */
void stage_7_boss_arrive(uint16_t object)
{
	uint16_t animation_number = 0, first_helper = 0, fourth_helper = 0, second_helper = 0, third_helper = 0;
	uint8_t action = 0;
	uint16_t own_y = 0, screen_y = 0, helper = 0, helper_2 = 0, helper_3 = 0, helper_4 = 0;

	own_y = OBJECT(object)->y;
	screen_y = own_y - camera_y;
	if ((int16_t)screen_y > 0xC8)
		return;
	OBJECT(object)->attributes = 0u;
	OBJECT(object)->y_speed = 0;
	animation_number = 0xD00u;
	stage_7_boss_set_animation(object, animation_number);
	helper = OBJECT(object)->stage_7_boss.helper_1;
	first_helper = helper;
	OBJECT(first_helper)->state = 6u;
	helper_2 = OBJECT(object)->stage_7_boss.helper_2;
	second_helper = helper_2;
	OBJECT(second_helper)->state = 5u;
	helper_3 = OBJECT(object)->stage_7_boss.helper_3;
	third_helper = helper_3;
	OBJECT(third_helper)->state = 4u;
	helper_4 = OBJECT(object)->stage_7_boss.helper_4;
	fourth_helper = helper_4;
	OBJECT(fourth_helper)->state = 2u;
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
void stage_7_boss_walk(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, heading = 0, u = 0;
	uint8_t animation = 0, side_direction = 0;

	stage_7_boss_approach(object, &u, &carry);
	if (carry)
		return;
	stage_7_boss_pick_target(object, u);
	animation = OBJECT(object)->animation;
	if (animation != 0u)
	{
		animation_number = 0x100u;
		stage_7_boss_set_animation(object, animation_number);
	}
	stage_7_boss_aim(object);
	side_direction = OBJECT(object)->stage_7_boss.side_direction;
	leftover_y = stage_7_boss_speeds_by_rank_ADDRESS;
	heading = ((uint32_t)side_direction << 8) | stage_7_boss_speeds_by_rank[rank >> 1];
	vector_set_speed_by_direction(object, heading);
	stage_7_boss_face_target(object);
}

/* Stage 7's boss attacks (state 2), by its step. */
void stage_7_boss_attack(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_strike(object);
			return;
		case 4:
			stage_7_boss_recover(object);
			return;
		case 6:
			stage_7_boss_charging(object);
			return;
		case 8:
			stage_7_boss_charge_end(object);
			return;
		case 10:
			stage_7_boss_jump_rise(object);
			return;
		case 12:
			stage_7_boss_jump_land(object);
			return;
		case 14:
			break;
		case -48:
			stage_7_boss_beaten(object);
			return;
		case -46:
			stage_7_boss_knocked_down(object);
			return;
		case -44:
			stage_7_boss_flinch(object);
			return;
		case -42:
			stage_7_boss_entrance(object);
			return;
		case -40:
			stage_7_boss_walk(object);
			return;
		case -38:
			continue;
		case -36:
			stage_7_boss_charge(object);
			return;
		case -34:
			stage_7_boss_jump_away(object);
			return;
		case -32:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -30:
			stage_7_boss_wait_target_up(object);
			return;
		case -28:
			stage_7_boss_beaten_wait(object);
			return;
		case -26:
			stage_7_boss_blink_out(object, carry);
			return;
		case -24:
			stage_7_boss_fall(object);
			return;
		case -22:
			stage_7_boss_lie(object);
			return;
		case -20:
			stage_7_boss_get_up(object);
			return;
		case -18:
			stage_7_boss_flinch_wait(object);
			return;
		case -16:
			stage_7_boss_flinch_land(object);
			return;
		case -14:
			stage_7_boss_put_in(object);
			return;
		case -12:
			stage_7_boss_start_entrance(object);
			return;
		case -10:
			stage_7_boss_move_helpers(object);
			return;
		case -8:
			stage_7_boss_step_forward(object);
			return;
		case -6:
			stage_7_boss_arrive(object);
			return;
		case -4:
			stage_7_boss_entrance_pose(object);
			return;
		case -2:
			stage_7_boss_entrance_end(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss attacks: after a wait, winds up (sound 6A00), not to be hurt meanwhile. */
void stage_7_boss_wind_up(uint16_t object)
{
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
	vector_queue_sound(command);
	animation_number = 0x200u;
	stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->flags |= 4u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss attacks: hits on the animation's marked frame. */
void stage_7_boss_strike(uint16_t object)
{
	uint8_t own_box = 0;
	uint16_t ignored16 = 0, look_numbers = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action = 0;

	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		own_box = 1u;
	look_numbers = (uint32_t)own_box << 8;
	stage_7_boss_set_hit_box(object, &ignored16, &look_numbers);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 1u) == 0u)
		return;
	look_numbers &= 0xFFu;
	stage_7_boss_set_animation(object, look_numbers);
	OBJECT(object)->action_step = 0x10u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Stage 7's boss attacks: after 16 frames, stands and picks its target again. */
void stage_7_boss_recover(uint16_t object)
{
	uint16_t box_end = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	box_end = stage_7_boss_stand(object);
	stage_7_boss_pick_target(object, box_end);
}

/* Stage 7's boss charges (state 3), by its step. */
void stage_7_boss_charge(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_charge_end(object);
			return;
		case 4:
			stage_7_boss_jump_rise(object);
			return;
		case 6:
			stage_7_boss_jump_land(object);
			return;
		case 8:
			break;
		case -54:
			stage_7_boss_beaten(object);
			return;
		case -52:
			stage_7_boss_knocked_down(object);
			return;
		case -50:
			stage_7_boss_flinch(object);
			return;
		case -48:
			stage_7_boss_entrance(object);
			return;
		case -46:
			stage_7_boss_walk(object);
			return;
		case -44:
			stage_7_boss_attack(object);
			return;
		case -42:
			continue;
		case -40:
			stage_7_boss_jump_away(object);
			return;
		case -38:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -36:
			stage_7_boss_wait_target_up(object);
			return;
		case -34:
			stage_7_boss_beaten_wait(object);
			return;
		case -32:
			stage_7_boss_blink_out(object, carry);
			return;
		case -30:
			stage_7_boss_fall(object);
			return;
		case -28:
			stage_7_boss_lie(object);
			return;
		case -26:
			stage_7_boss_get_up(object);
			return;
		case -24:
			stage_7_boss_flinch_wait(object);
			return;
		case -22:
			stage_7_boss_flinch_land(object);
			return;
		case -20:
			stage_7_boss_put_in(object);
			return;
		case -18:
			stage_7_boss_start_entrance(object);
			return;
		case -16:
			stage_7_boss_move_helpers(object);
			return;
		case -14:
			stage_7_boss_step_forward(object);
			return;
		case -12:
			stage_7_boss_arrive(object);
			return;
		case -10:
			stage_7_boss_entrance_pose(object);
			return;
		case -8:
			stage_7_boss_entrance_end(object);
			return;
		case -6:
			stage_7_boss_wind_up(object);
			return;
		case -4:
			stage_7_boss_strike(object);
			return;
		case -2:
			stage_7_boss_recover(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss charges at its target, turning toward it a little each frame, with a sound every 64
   frames, until its time runs out. */
void stage_7_boss_charging(uint16_t object)
{
	uint32_t negative = 0, carry = 0;
	uint8_t attributes = 0, charge_direction = 0;
	uint16_t box_number = 0, command = 0, heading = 0, ignored16 = 0, ignored16_2 = 0, target_or_box_end = 0, toward_target = 0;
	uint8_t action = 0, animation_flags = 0, charge_direction_2 = 0, charge_direction_3 = 0, attributes_2 = 0, charge_direction_4 = 0, charge_direction_5 = 0, charge_direction_6 = 0;
	uint16_t charge_time = 0;

	box_number = 0u;
	stage_7_boss_set_hit_box(object, &target_or_box_end, &box_number);
	if ((frame_count & 0x3Fu) == 0u)
	{
		command = 0x7600u;
		vector_queue_sound(command);
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
	find_nearest_player(object, &target_or_box_end, &ignored16, &carry);
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
		stage_7_boss_set_hit_box(object, &target_or_box_end, &box_number);
	}
	toward_target = vector_direction_to(object, target_or_box_end);
	charge_direction = (uint8_t)(toward_target >> 8);
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
void stage_7_boss_charge_end(uint16_t object)
{
	uint16_t box_end = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	box_end = stage_7_boss_stand(object);
	stage_7_boss_pick_target(object, box_end);
}

/* Stage 7's boss jumps away (state 4), by its step. */
void stage_7_boss_jump_away(uint16_t object)
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
			return;
		case 2:
			stage_7_boss_jump_land(object);
			return;
		case 4:
			break;
		case -58:
			stage_7_boss_beaten(object);
			return;
		case -56:
			stage_7_boss_knocked_down(object);
			return;
		case -54:
			stage_7_boss_flinch(object);
			return;
		case -52:
			stage_7_boss_entrance(object);
			return;
		case -50:
			stage_7_boss_walk(object);
			return;
		case -48:
			stage_7_boss_attack(object);
			return;
		case -46:
			stage_7_boss_charge(object);
			return;
		case -44:
			continue;
		case -42:
			stage_7_boss_idle(object, action_handlers);
			return;
		case -40:
			stage_7_boss_wait_target_up(object);
			return;
		case -38:
			stage_7_boss_beaten_wait(object);
			return;
		case -36:
			stage_7_boss_blink_out(object, carry);
			return;
		case -34:
			stage_7_boss_fall(object);
			return;
		case -32:
			stage_7_boss_lie(object);
			return;
		case -30:
			stage_7_boss_get_up(object);
			return;
		case -28:
			stage_7_boss_flinch_wait(object);
			return;
		case -26:
			stage_7_boss_flinch_land(object);
			return;
		case -24:
			stage_7_boss_put_in(object);
			return;
		case -22:
			stage_7_boss_start_entrance(object);
			return;
		case -20:
			stage_7_boss_move_helpers(object);
			return;
		case -18:
			stage_7_boss_step_forward(object);
			return;
		case -16:
			stage_7_boss_arrive(object);
			return;
		case -14:
			stage_7_boss_entrance_pose(object);
			return;
		case -12:
			stage_7_boss_entrance_end(object);
			return;
		case -10:
			stage_7_boss_wind_up(object);
			return;
		case -8:
			stage_7_boss_strike(object);
			return;
		case -6:
			stage_7_boss_recover(object);
			return;
		case -4:
			stage_7_boss_charging(object);
			return;
		case -2:
			stage_7_boss_charge_end(object);
			return;
		}
		break;
	}
	stage_7_boss_jump_end(object);
}

/* Stage 7's boss jumps away: in the air until its animation ends. */
void stage_7_boss_jump_rise(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, landing_result = 0;
	uint8_t animation_flags = 0, action = 0;

	vector_apply_gravity(object, &landing_result, &carry);
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	animation_number = (landing_result & 0xFFu) | 0xC00u;
	stage_7_boss_set_animation(object, animation_number);
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
	stage_7_boss_set_animation(object, animation_number);
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
void stage_7_boss_idle(uint16_t object, uint16_t nearest)
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
		stage_7_boss_pick_target(object, nearest);
	}
}

/* Stage 7's boss waits while its target is down, then stands (no scenario reaches it). */
void stage_7_boss_wait_target_up(uint16_t object)
{
	uint16_t target_player = 0;
	uint8_t state = 0;
	uint16_t read_target = 0;

	read_target = mem_read16(leftover_y + 0x2Bu);
	target_player = read_target;
	state = OBJECT(target_player)->state;
	if ((int8_t)state >= 0)
	{
		leftover_y = target_player;
		stage_7_boss_stand(object);
		return;
	}
	leftover_y = target_player;
}

/* Stage 7's boss: when hit, takes the hit. */
void stage_7_boss_check_hit(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t hit = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(object)->hit;
		negative = hit >> 7;
		if (hit != 0u && negative == 0u)
			stage_7_boss_take_hit(object);
	}
}

/* Stage 7's boss walking: at its target, decides how to attack; after walking too long without reaching
   it, charges (carry: it did either). */
void stage_7_boss_approach(uint16_t object, uint16_t *p_object_2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t charge_direction = 0;
	uint16_t animation_number = 0, direction = 0, heading = 0, target = 0, wait = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0, last_health = 0, vitality = 0, vitality_2 = 0;
	uint16_t walk_target = 0, own_x = 0, target_x = 0, walk_time = 0, boss_x = 0, target_place_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, walk_time_2 = 0, boss_y = 0, target_y = 0, y_difference = 0, signed_y_difference = 0, y_distance = 0, attack_target = 0;

	walk_target = OBJECT(object)->stage_7_boss.target;
	wait = walk_target;
	own_x = OBJECT(object)->x;
	target_x = mem_read16(wait + 0xCu);
	if ((int16_t)own_x < (int16_t)target_x)
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
	boss_x = OBJECT(object)->x;
	target_place_x = mem_read16(wait + 0xCu);
	x_difference = boss_x - target_place_x;
	signed_x_difference = x_difference;
	x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
	if ((int16_t)x_distance > 0x40)
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
		stage_7_boss_set_animation(object, animation_number);
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
	boss_y = OBJECT(object)->y;
	target_y = mem_read16(wait + 0x11u);
	y_difference = boss_y - target_y;
	signed_y_difference = y_difference;
	y_distance = signed_y_difference >> 15 ? 0u - signed_y_difference : signed_y_difference;
	if ((int16_t)y_distance > 8)
	{
		walk_time = OBJECT(object)->stage_7_boss.walk_time;
		OBJECT(object)->stage_7_boss.walk_time = walk_time + 1u;
		carry = 0u;
		*p_object_2 = wait;
		*p_carry = carry;
		return;
	}
	attack_target = OBJECT(object)->stage_7_boss.target;
	target = attack_target;
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
	stage_7_boss_set_animation(object, animation_number);
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
void stage_7_boss_pick_target(uint16_t object, uint16_t nearest)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, target_player = 0;
	uint8_t state = 0, target_wait = 0, target_wait_2 = 0;
	uint16_t kept_target = 0;

	find_nearest_player(object, &nearest, &ignored16, &carry);
	if (carry == 0u)
	{
		stage_7_boss_go_idle(object);
		return;
	}
	kept_target = OBJECT(object)->stage_7_boss.target;
	target_player = kept_target;
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
				leftover_y = target_player;
				return;
			}
		}
	}
	OBJECT(object)->stage_7_boss.target_wait = 0x40u;
	OBJECT(object)->stage_7_boss.target = nearest;
	leftover_y = target_player;
}

/* Stage 7's boss: the direction to the side of its target (field 2D) and to the target itself (2E). */
void stage_7_boss_aim(uint16_t object)
{
	uint8_t side_offset = 0;
	uint16_t aim_direction = 0, direction = 0, target_player = 0;
	uint16_t aim_target = 0, own_x = 0, target_x = 0;

	aim_target = OBJECT(object)->stage_7_boss.target;
	target_player = aim_target;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target_player)->x;
	if ((int16_t)target_x < (int16_t)own_x)
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
	uint16_t kind_with_animation = 0;
	uint32_t kind_halfword = 0;

	animation_index = (uint8_t)(animation_number >> 8);
	carry = (int8_t)animation_index < 0;
	kind_with_animation = stage_7_boss_animations[animation_index & 0x7Fu];
	kind_halfword = ((uint32_t)(kind_with_animation >> 8) << 8) | (uint8_t)(kind_with_animation | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	return carry;
}

/* Stage 7's boss: sets the given hit box (stage_7_boss_hit_boxes). */
void stage_7_boss_set_hit_box(uint16_t object, uint16_t *p_box_end, uint16_t *p_box_number)
{
	uint16_t box_number = (uint16_t)*p_box_number;
	uint16_t box_end = 0;
	uint16_t box_record = 0, damage_attack = 0, box_cursor = 0, width_depth = 0, box_cursor_2 = 0, height_dx = 0, box_cursor_3 = 0, dy_dz = 0;
	uint32_t box_dy_halfword = 0;

	box_record = stage_7_boss_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(box_number >> 8) << 1) << 1) << 1);
	damage_attack = HIT_BOX(box_record)->damage_attack;
	OBJECT(object)->damage = (uint8_t)(damage_attack >> 8u);
	OBJECT(object)->attack = (uint8_t)damage_attack;
	box_cursor = box_record + 2u;
	width_depth = HIT_BOX(box_cursor - 0x2u)->width_depth;
	OBJECT(object)->box_width = (uint8_t)(width_depth >> 8u);
	OBJECT(object)->box_depth = (uint8_t)width_depth;
	box_cursor_2 = box_cursor + 2u;
	height_dx = HIT_BOX(box_cursor_2 - 0x4u)->height_dx;
	OBJECT(object)->box_height = (uint8_t)(height_dx >> 8u);
	OBJECT(object)->box_dx = (uint8_t)height_dx;
	box_cursor_3 = box_cursor_2 + 2u;
	box_end = box_cursor_3 + 2u;
	dy_dz = HIT_BOX(box_cursor_3 - 0x6u)->dy_dz;
	box_number = dy_dz;
	box_dy_halfword = ((uint32_t)(dy_dz >> 8) << 8) | (box_number & 0xFFu);
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
	uint8_t x_speed_2 = 0, x_high = 0;
	uint16_t x_low_and_fraction = 0, x_speed = 0, camera_x_low_and_fraction = 0;

	x_low_and_fraction = (((uint32_t)(OBJECT(object)->x & 0xFFu) << 8u) | OBJECT(object)->x_fraction);
	x_and_fraction = x_low_and_fraction;
	x_speed = OBJECT(object)->x_speed;
	carry = (uint16_t)(x_and_fraction + x_speed) < x_and_fraction;
	area_next_x = x_and_fraction + x_speed;
	x_speed_2 = (uint8_t)(OBJECT(object)->x_speed >> 8u);
	x_high = (uint8_t)(OBJECT(object)->x >> 8u);
	area_next_x_high = (uint16_t)((uint32_t)(uint8_t)(((uint16_t)(int8_t)x_speed_2 >> 8) + x_high + carry) << 8) >> 8;
	next_x_and_fraction = area_next_x;
	camera_x_low_and_fraction = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	carry = (uint16_t)(next_x_and_fraction + camera_x_low_and_fraction) < next_x_and_fraction;
	area_next_x = next_x_and_fraction + camera_x_low_and_fraction;
	next_stage_x = ((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(camera_x >> 8u) << 8) >> 8) + area_next_x_high + carry) << 8) | area_next_x_pixels;
	if ((int16_t)next_stage_x <= 0x8B0 || (int16_t)next_stage_x >= 0xA0F)
		OBJECT(object)->x_speed = 0;
}

/* Stage 7's boss: stops it at the front and back edges of its area. */
void stage_7_boss_keep_in_y(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t next_y_high = 0, next_y_low = 0;
	uint8_t state = 0, y_speed_2 = 0, y_high = 0;
	uint16_t y_low_and_fraction = 0, y_speed = 0, old_y_low_and_fraction = 0, next_y_low_and_fraction = 0, stage_y_low_and_fraction = 0, camera_y_low_and_fraction = 0, next_stage_y_low = 0, screen_y_low_and_fraction = 0;

	state = OBJECT(object)->state;
	if (state != 0u)
	{
		y_low_and_fraction = (((uint32_t)(OBJECT(object)->y & 0xFFu) << 8u) | OBJECT(object)->y_fraction);
		y_speed = OBJECT(object)->y_speed;
		old_y_low_and_fraction = y_low_and_fraction;
		next_y_low_and_fraction = old_y_low_and_fraction + y_speed;
		carry = (uint16_t)(old_y_low_and_fraction + y_speed) < old_y_low_and_fraction;
		area_next_y = next_y_low_and_fraction;
		y_speed_2 = (uint8_t)(OBJECT(object)->y_speed >> 8u);
		y_high = (uint8_t)(OBJECT(object)->y >> 8u);
		area_next_y_high = ((uint16_t)(int8_t)y_speed_2 >> 8) + y_high + carry;
		stage_y_low_and_fraction = area_next_y;
		camera_y_low_and_fraction = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
		next_stage_y_low = stage_y_low_and_fraction;
		screen_y_low_and_fraction = next_stage_y_low - camera_y_low_and_fraction;
		carry = next_stage_y_low < camera_y_low_and_fraction;
		area_next_y = screen_y_low_and_fraction;
		next_y_high = (uint8_t)(camera_y >> 8u) + area_next_y_high + carry;
		next_y_low = area_next_y_pixels;
		if ((int16_t)(((uint32_t)next_y_high << 8) | next_y_low) <= 0x78 || (int16_t)(((uint32_t)next_y_high << 8) | next_y_low) >= 0xC8)
			OBJECT(object)->y_speed = 0;
	}
}

/* Stage 7's boss: every so often by the rank, sends some of its idle helpers to throw. */
void stage_7_boss_order_throws(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t other_enemies = 0, throws = 0;
	uint16_t helper_number = 0;
	uint8_t stack = 0;
	uint8_t state = 0, vitality = 0, enemies_last_frame = 0, throws_allowed = 0, throws_wanted = 0, throws_to_order = 0;
	uint16_t throw_wait = 0, new_throw_wait = 0, attack_time = 0, throw_wait_2 = 0;

	state = OBJECT(object)->state;
	if (state != 0u)
	{
		vitality = OBJECT(object)->vitality;
		if (vitality != 0u)
		{
			throw_wait = OBJECT(object)->stage_7_boss.throw_wait;
			new_throw_wait = throw_wait + 1u;
			OBJECT(object)->stage_7_boss.throw_wait = new_throw_wait;
			attack_time = stage_7_boss_helper_attack_times_by_rank[(int8_t)(rank & ~1u) / 2];
			throw_wait_2 = OBJECT(object)->stage_7_boss.throw_wait;
			if ((int16_t)attack_time <= (int16_t)throw_wait_2)
			{
				OBJECT(object)->stage_7_boss.throw_wait = 0u;
				throw_helper = random_number & 3u;
				enemies_last_frame = io_read8(enemies_present_last_frame);
				other_enemies = enemies_last_frame - 1u;
				stack = other_enemies;
				throws_allowed = ((uint8_t)(player_count - 1u) >> 1) + 1u;
				throws_wanted = throws_allowed - stack;
				negative = throws_wanted >> 7;
				throws = throws_wanted;
				if (throws_allowed != stack && negative == 0u)
				{
					helper_throws_left = throws;
					do
					{
						helper_number = ((throw_helper & 3u) << 8) | other_enemies;
						stage_7_boss_order_throw(object, helper_number);
						other_enemies = (uint8_t)helper_number;
						throw_helper++;
						throws_to_order = helper_throws_left;
						helper_throws_left = throws_to_order - 1u;
					} while (throws_to_order != 1u);
				}
			}
		}
	}
}

/* Stage 7's boss: the given helper, if idle, gets its missile and starts throwing. */
void stage_7_boss_order_throw(uint16_t object, uint16_t helper_number)
{
	uint32_t carry = 0;
	uint16_t helper = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t state = 0;

	helper = mem_read16(object + (uint8_t)(((uint32_t)(helper_number >> 8) << 1) + 0x33u));
	state = OBJECT(helper)->state;
	if (state != 0u)
		return;
	leftover_y = stage_7_boss_order_throw_child_ADDRESS;
	vector_spawn_child(helper, &ignored16, &ignored16_2, &ignored16_3, &carry);
	if (carry)
		OBJECT(helper)->state = 7u;
}

/* Stage 7's boss stands and goes back to walking. */
uint16_t stage_7_boss_stand(uint16_t object)
{
	uint16_t animation_number = 0, box_end = 0, box_number = 0;

	animation_number = 0x100u;
	stage_7_boss_set_animation(object, animation_number);
	box_number = 0u;
	stage_7_boss_set_hit_box(object, &box_end, &box_number);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0x40u) & ~4u;
	OBJECT(object)->state = 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return box_end;
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
void stage_7_boss_take_hit(uint16_t object)
{
	uint16_t animation_number = 0, command = 0, d = 0, ignored16 = 0, object_2 = 0, palette_effect_number = 0;
	uint8_t vitality = 0, direction = 0, hit = 0, hits = 0, hits_2 = 0, attributes = 0, attributes_2 = 0;
	uint16_t hit_by = 0, screen_x = 0;

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
	vector_palette_request(object_2, palette_effect_number);
	command = 0x6600u;
	vector_queue_sound(command);
	d = 0u;
	stage_7_boss_set_hit_box(object, &ignored16, &d);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		d = 0x6600u;
		vector_queue_sound_unless_attract(d);
		animation_number = (d & 0xFFu) | 0x500u;
		stage_7_boss_set_animation(object, animation_number);
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0x400;
		direction = OBJECT(object)->stage_7_boss.direction;
		if ((uint8_t)(direction + 0x40u) < 0x80u)
		{
			OBJECT(object)->x_speed = -0x300;
			return;
		}
		OBJECT(object)->x_speed = 0x300;
		return;
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
			stage_7_boss_set_animation(object, animation_number);
			OBJECT(object)->state = 0xFFu;
			OBJECT(object)->action = 0u;
			return;
		}
	}
	OBJECT(object)->stage_7_boss.hits = 0u;
	if (stage_7_boss_jump_away_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))] < random_number)
	{
		animation_number = (d & 0xFFu) | 0x500u;
		stage_7_boss_set_animation(object, animation_number);
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->action = 0u;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0x400;
		direction = OBJECT(object)->stage_7_boss.direction;
		if ((uint8_t)(direction + 0x40u) < 0x80u)
		{
			OBJECT(object)->x_speed = -0x300;
			return;
		}
		OBJECT(object)->x_speed = 0x300;
		return;
	}
	OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 8u;
	screen_x = OBJECT(object)->x;
	if ((int16_t)screen_x <= 0xE0)
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
	stage_7_boss_set_animation(object, animation_number);
	OBJECT(object)->state = 4u;
	OBJECT(object)->action = 0u;
}
