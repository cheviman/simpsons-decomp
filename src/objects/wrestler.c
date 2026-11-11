/**
 *    Name:        objects/wrestler.c
 *    Description: stage 1's boss, the wrestler
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The wrestler beaten (state FD), by its step: a wait, then it blinks out. */
void wrestler_beaten(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_beaten_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case 2:
			wrestler_blink_out(object, d, carry);
			return;
		case 4:
			wrestler_fall(object);
			return;
		case 6:
			wrestler_lie(object);
			return;
		case 8:
			wrestler_get_up(object);
			return;
		case 10:
			wrestler_flinch_wait(object);
			return;
		case 12:
			wrestler_flinch_land(object);
			return;
		case 14:
			wrestler_put_in(object);
			return;
		case 16:
			wrestler_entrance_drop(object);
			return;
		case 18:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case 20:
			wrestler_entrance_step_out(object);
			return;
		case 22:
			wrestler_entrance_land(object, action_handlers);
			return;
		case 24:
			wrestler_entrance_stand(object);
			return;
		case 26:
			wrestler_entrance_shout(object);
			return;
		case 28:
			wrestler_entrance_end(object);
			return;
		case 30:
			wrestler_punch_wind_up(object);
			return;
		case 32:
			wrestler_punch_strike(object);
			return;
		case 34:
			wrestler_punch_recover(object);
			return;
		case 36:
			wrestler_guarding(object);
			return;
		case 38:
			wrestler_jump_rise(object);
			return;
		case 40:
			wrestler_jump_land(object);
			return;
		case 42:
			wrestler_jump_recover(object);
			return;
		case 44:
			wrestler_jump_end(object, action_handlers);
			return;
		case 46:
			wrestler_idle_look(object);
			return;
		case 48:
			break;
		case -22:
			continue;
		case -20:
			wrestler_knocked_down(object, d);
			return;
		case -18:
			wrestler_flinch(object, d);
			return;
		case -16:
			wrestler_entrance(object, d);
			return;
		case -14:
			wrestler_walk(object);
			return;
		case -12:
			wrestler_punch(object, d);
			return;
		case -10:
			wrestler_guard(object, d);
			return;
		case -8:
		case -6:
			wrestler_jump(object, d);
			return;
		case -4:
			wrestler_idle(object, d);
			return;
		case -2:
			wrestler_wait_target_up(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler beaten: waits, then a palette flash and a sound (6700). */
void wrestler_beaten_wait(uint16_t object, uint16_t palette_job)
{
	uint16_t command = 0, palette_effect_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	palette_request_kind = 2u;
	palette_effect_number = 0x20u;
	vector_palette_request(palette_job, palette_effect_number);
	command = 0x6700u;
	vector_queue_sound(command);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler beaten: blinks for 64 frames, then it and its partner are gone, the boss counts as beaten
   and the step goes on. */
void wrestler_blink_out(uint16_t object, uint8_t d, uint32_t carry)
{
	uint8_t frame_bit = 0;
	uint16_t partner_object = 0;
	uint8_t rotated_once = 0, action_step = 0, action_step_2 = 0, points = 0;
	uint16_t partner = 0;
	uint32_t step_subphase_halfword = 0;

	OBJECT(object)->flags &= 0x7Fu;
	frame_bit = (uint8_t)frame_count & 1u;
	rotated_once = (frame_bit >> 1) | (carry << 7);
	carry = frame_bit;
	OBJECT(object)->flags |= (rotated_once >> 1) | (carry << 7);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	action_step_2 = OBJECT(object)->action_step;
	if (action_step_2 == 0x40u)
	{
		points = OBJECT(object)->points;
		OBJECT(object)->points = points | 0x81u;
		OBJECT(object)->flags = 0u;
		partner = OBJECT(object)->wrestler.partner;
		partner_object = partner;
		OBJECT(partner_object)->flags = 0u;
		boss_beaten = 1u;
		step_phase++;
		step_subphase_halfword = 0x100u | (d & 0xFFu);
		step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
		step_countdown = (uint8_t)step_subphase_halfword;
	}
}

/* The wrestler knocked down (state FE), by its step: falls, lies, gets up. */
void wrestler_knocked_down(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_knocked_down_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_fall(object);
			return;
		case 2:
			wrestler_lie(object);
			return;
		case 4:
			wrestler_get_up(object);
			return;
		case 6:
			wrestler_flinch_wait(object);
			return;
		case 8:
			wrestler_flinch_land(object);
			return;
		case 10:
			wrestler_put_in(object);
			return;
		case 12:
			wrestler_entrance_drop(object);
			return;
		case 14:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case 16:
			wrestler_entrance_step_out(object);
			return;
		case 18:
			wrestler_entrance_land(object, action_handlers);
			return;
		case 20:
			wrestler_entrance_stand(object);
			return;
		case 22:
			wrestler_entrance_shout(object);
			return;
		case 24:
			wrestler_entrance_end(object);
			return;
		case 26:
			wrestler_punch_wind_up(object);
			return;
		case 28:
			wrestler_punch_strike(object);
			return;
		case 30:
			wrestler_punch_recover(object);
			return;
		case 32:
			wrestler_guarding(object);
			return;
		case 34:
			wrestler_jump_rise(object);
			return;
		case 36:
			wrestler_jump_land(object);
			return;
		case 38:
			wrestler_jump_recover(object);
			return;
		case 40:
			wrestler_jump_end(object, action_handlers);
			return;
		case 42:
			wrestler_idle_look(object);
			return;
		case 44:
			break;
		case -26:
			wrestler_beaten(object, d);
			return;
		case -24:
			continue;
		case -22:
			wrestler_flinch(object, d);
			return;
		case -20:
			wrestler_entrance(object, d);
			return;
		case -18:
			wrestler_walk(object);
			return;
		case -16:
			wrestler_punch(object, d);
			return;
		case -14:
			wrestler_guard(object, d);
			return;
		case -12:
		case -10:
			wrestler_jump(object, d);
			return;
		case -8:
			wrestler_idle(object, d);
			return;
		case -6:
			wrestler_wait_target_up(object);
			return;
		case -4:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -2:
			wrestler_blink_out(object, d, carry);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler knocked down: falls; landing with too little health it is beaten, else it lies. */
void wrestler_fall(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t animation_number = 0, command = 0, ignored16 = 0, partner_object = 0;
	uint8_t vitality = 0, shadow_player = 0, action = 0;
	uint16_t partner = 0, hit_by = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (vitality <= wrestler_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))])
	{
		command = 0x9800u;
		vector_queue_sound_unless_attract(command);
		OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 4u;
		partner = OBJECT(object)->wrestler.partner;
		partner_object = partner;
		OBJECT(partner_object)->z_speed = 0x100;
		animation_number = 0x600u;
		wrestler_set_animation(object, &animation_number, &landed);
		hit_by = OBJECT(object)->hit_by;
		shadow_player = OBJECT(hit_by)->shadow_player;
		OBJECT(object)->points = shadow_player & ~0xFu;
		OBJECT(object)->action_step = 0x40u;
		OBJECT(object)->vitality = 0u;
		OBJECT(object)->state = 0xFDu;
		OBJECT(object)->action = 0u;
		return;
	}
	animation_number = 0xD00u;
	wrestler_set_animation(object, &animation_number, &landed);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler knocked down: lies for 64 frames, then starts getting up. */
void wrestler_lie(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	animation_number = 0x500u;
	wrestler_set_animation(object, &animation_number, &carry);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler knocked down: once up, stands and picks its target again. */
void wrestler_get_up(uint16_t object)
{
	uint16_t box_end = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	box_end = wrestler_stand(object);
	wrestler_pick_target(object, box_end);
}

/* The wrestler hit (state FF), by its step. */
void wrestler_flinch(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_flinch_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_flinch_wait(object);
			return;
		case 2:
			wrestler_flinch_land(object);
			return;
		case 4:
			wrestler_put_in(object);
			return;
		case 6:
			wrestler_entrance_drop(object);
			return;
		case 8:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case 10:
			wrestler_entrance_step_out(object);
			return;
		case 12:
			wrestler_entrance_land(object, action_handlers);
			return;
		case 14:
			wrestler_entrance_stand(object);
			return;
		case 16:
			wrestler_entrance_shout(object);
			return;
		case 18:
			wrestler_entrance_end(object);
			return;
		case 20:
			wrestler_punch_wind_up(object);
			return;
		case 22:
			wrestler_punch_strike(object);
			return;
		case 24:
			wrestler_punch_recover(object);
			return;
		case 26:
			wrestler_guarding(object);
			return;
		case 28:
			wrestler_jump_rise(object);
			return;
		case 30:
			wrestler_jump_land(object);
			return;
		case 32:
			wrestler_jump_recover(object);
			return;
		case 34:
			wrestler_jump_end(object, action_handlers);
			return;
		case 36:
			wrestler_idle_look(object);
			return;
		case 38:
			break;
		case -32:
			wrestler_beaten(object, d);
			return;
		case -30:
			wrestler_knocked_down(object, d);
			return;
		case -28:
			continue;
		case -26:
			wrestler_entrance(object, d);
			return;
		case -24:
			wrestler_walk(object);
			return;
		case -22:
			wrestler_punch(object, d);
			return;
		case -20:
			wrestler_guard(object, d);
			return;
		case -18:
		case -16:
			wrestler_jump(object, d);
			return;
		case -14:
			wrestler_idle(object, d);
			return;
		case -12:
			wrestler_wait_target_up(object);
			return;
		case -10:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -8:
			wrestler_blink_out(object, d, carry);
			return;
		case -6:
			wrestler_fall(object);
			return;
		case -4:
			wrestler_lie(object);
			return;
		case -2:
			wrestler_get_up(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler hit: waits for its flinch's animation to end. */
void wrestler_flinch_wait(uint16_t object)
{
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The wrestler hit: once back on the floor, stands and picks its target again. */
void wrestler_flinch_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t box_end = 0, ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	box_end = wrestler_stand(object);
	wrestler_pick_target(object, box_end);
}

/* The wrestler's entrance (state 0), by its step. */
void wrestler_entrance(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_entrance_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_put_in(object);
			return;
		case 2:
			wrestler_entrance_drop(object);
			return;
		case 4:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case 6:
			wrestler_entrance_step_out(object);
			return;
		case 8:
			wrestler_entrance_land(object, action_handlers);
			return;
		case 10:
			wrestler_entrance_stand(object);
			return;
		case 12:
			wrestler_entrance_shout(object);
			return;
		case 14:
			wrestler_entrance_end(object);
			return;
		case 16:
			wrestler_punch_wind_up(object);
			return;
		case 18:
			wrestler_punch_strike(object);
			return;
		case 20:
			wrestler_punch_recover(object);
			return;
		case 22:
			wrestler_guarding(object);
			return;
		case 24:
			wrestler_jump_rise(object);
			return;
		case 26:
			wrestler_jump_land(object);
			return;
		case 28:
			wrestler_jump_recover(object);
			return;
		case 30:
			wrestler_jump_end(object, action_handlers);
			return;
		case 32:
			wrestler_idle_look(object);
			return;
		case 34:
			break;
		case -36:
			wrestler_beaten(object, d);
			return;
		case -34:
			wrestler_knocked_down(object, d);
			return;
		case -32:
			wrestler_flinch(object, d);
			return;
		case -30:
			continue;
		case -28:
			wrestler_walk(object);
			return;
		case -26:
			wrestler_punch(object, d);
			return;
		case -24:
			wrestler_guard(object, d);
			return;
		case -22:
		case -20:
			wrestler_jump(object, d);
			return;
		case -18:
			wrestler_idle(object, d);
			return;
		case -16:
			wrestler_wait_target_up(object);
			return;
		case -14:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -12:
			wrestler_blink_out(object, d, carry);
			return;
		case -10:
			wrestler_fall(object);
			return;
		case -8:
			wrestler_lie(object);
			return;
		case -6:
			wrestler_get_up(object);
			return;
		case -4:
			wrestler_flinch_wait(object);
			return;
		case -2:
			wrestler_flinch_land(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler's entrance: once the camera's flag from the stage record clears, drops it in from above
   with its partner object, sets its health and says a boss is in. */
void wrestler_put_in(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t slot_list = 0;
	uint16_t look_numbers = 0, palette_effect_number = 0, partner_object = 0;
	uint8_t action = 0;
	uint16_t entrance_z = 0, partner_z = 0;

	OBJECT(object)->entrance_pending = 1u;
	if (stage_scrolls_on != 0u)
		return;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->shadow_player = 1u;
	look_numbers = 0xE00u;
	wrestler_set_animation(object, &look_numbers, &carry);
	look_numbers &= 0xFFu;
	wrestler_set_hit_box(object, look_numbers);
	OBJECT(object)->x = 0xE0u;
	OBJECT(object)->y = 0x82u;
	entrance_z = 0x100u - camera_y;
	OBJECT(object)->z = entrance_z;
	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->vitality = 0xC0u;
	OBJECT(object)->wrestler.last_health = 0xC0u;
	boss_arrived++;
	slot_list = 2u;
	vector_find_free_slot(slot_list, &partner_object, &carry);
	OBJECT(partner_object)->flags = 0x80u;
	OBJECT(partner_object)->animation_flags = 0x80u;
	OBJECT(partner_object)->type = 0;
	OBJECT(partner_object)->kind = 0xFu;
	OBJECT(partner_object)->animation = 0x91u;
	OBJECT(partner_object)->x = 0xE0u;
	OBJECT(partner_object)->y = 0x80u;
	partner_z = 0x158u - camera_y;
	OBJECT(partner_object)->z = partner_z;
	OBJECT(partner_object)->z_speed = -0x100;
	OBJECT(object)->wrestler.partner = partner_object;
	OBJECT(object)->entrance_pending = 0u;
	palette_request_kind = 2u;
	palette_effect_number = 0x16u;
	partner_object = vector_palette_request(partner_object, palette_effect_number);
	palette_request_kind = 2u;
	palette_effect_number = 0x17u;
	vector_palette_request(partner_object, palette_effect_number);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: the two fall until the partner is down, then hold. */
void wrestler_entrance_drop(uint16_t object)
{
	uint16_t partner_object = 0;
	uint8_t action = 0;
	uint16_t partner = 0, partner_z = 0, partner_y = 0, partner_y_2 = 0;

	partner = OBJECT(object)->wrestler.partner;
	partner_object = partner;
	partner_z = OBJECT(partner_object)->z;
	partner_y = OBJECT(partner_object)->y;
	if ((uint16_t)(partner_z + partner_y - camera_y) <= 0x130u)
	{
		partner_y_2 = OBJECT(partner_object)->y;
		OBJECT(partner_object)->z = 0x130u + camera_y - partner_y_2;
		OBJECT(object)->action_step = 0x20u;
		OBJECT(object)->z_speed = 0;
		OBJECT(partner_object)->z_speed = 0;
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The wrestler's entrance: a palette flash, a sound (6700) and a pose. */
void wrestler_entrance_pose(uint16_t object, uint16_t palette_job)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, palette_effect_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	palette_request_kind = 2u;
	palette_effect_number = 0xCu;
	vector_palette_request(palette_job, palette_effect_number);
	command = 0x6700u;
	vector_queue_sound(command);
	animation_number = 0xF00u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: after the pose, steps out. */
void wrestler_entrance_step_out(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	animation_number = 0x400u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->y_speed = 0x100;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: lands shaking the screen, with a thud (6400). */
void wrestler_entrance_land(uint16_t object, uint16_t palette_job)
{
	uint32_t landed = 0;
	uint16_t animation_number = 0, command = 0, ignored16 = 0, palette_effect_number = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	palette_request_kind = 2u;
	palette_effect_number = 0x21u;
	palette_job = vector_palette_request(palette_job, palette_effect_number);
	palette_request_kind = 2u;
	palette_effect_number = 0x26u;
	vector_palette_request(palette_job, palette_effect_number);
	screen_shake_on = 1u;
	command = 0x6400u;
	vector_queue_sound(command);
	OBJECT(object)->y_speed = 0;
	animation_number = 0xB00u;
	wrestler_set_animation(object, &animation_number, &landed);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: stands up. */
void wrestler_entrance_stand(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	animation_number = 0x500u;
	wrestler_set_animation(object, &animation_number, &carry);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: shouts (3F2D) with its taunt. */
void wrestler_entrance_shout(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;
	uint8_t animation_flags = 0, action = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	command = 0x3F2Du;
	vector_queue_sound(command);
	OBJECT(object)->flags = 0xC0u;
	animation_number = 0xA00u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler's entrance: after the taunt, starts walking. */
void wrestler_entrance_end(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->action = 0u;
		OBJECT(object)->state = 1u;
	}
}

/* The wrestler walks toward its target at its speed by rank, until it reaches it. */
void wrestler_walk(uint16_t object)
{
	uint32_t action_started = 0;
	uint16_t animation_number = 0, heading = 0, u = 0;
	uint8_t animation = 0, side_direction = 0;

	wrestler_approach(object, &u, &action_started);
	if (action_started)
		return;
	wrestler_pick_target(object, u);
	animation = OBJECT(object)->animation;
	if (animation != 0u)
	{
		animation_number = 0x100u;
		wrestler_set_animation(object, &animation_number, &action_started);
	}
	wrestler_aim(object);
	side_direction = OBJECT(object)->wrestler.side_direction;
	leftover_y = wrestler_speeds_by_rank_ADDRESS;
	heading = ((uint32_t)side_direction << 8) | wrestler_speeds_by_rank[rank >> 1];
	vector_set_speed_by_direction(object, heading);
	wrestler_face_target(object);
}

/* The wrestler punches (state 2), by its step. */
void wrestler_punch(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_punch_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_punch_wind_up(object);
			return;
		case 2:
			wrestler_punch_strike(object);
			return;
		case 4:
			wrestler_punch_recover(object);
			return;
		case 6:
			wrestler_guarding(object);
			return;
		case 8:
			wrestler_jump_rise(object);
			return;
		case 10:
			wrestler_jump_land(object);
			return;
		case 12:
			wrestler_jump_recover(object);
			return;
		case 14:
			wrestler_jump_end(object, action_handlers);
			return;
		case 16:
			wrestler_idle_look(object);
			return;
		case 18:
			break;
		case -52:
			wrestler_beaten(object, d);
			return;
		case -50:
			wrestler_knocked_down(object, d);
			return;
		case -48:
			wrestler_flinch(object, d);
			return;
		case -46:
			wrestler_entrance(object, d);
			return;
		case -44:
			wrestler_walk(object);
			return;
		case -42:
			continue;
		case -40:
			wrestler_guard(object, d);
			return;
		case -38:
		case -36:
			wrestler_jump(object, d);
			return;
		case -34:
			wrestler_idle(object, d);
			return;
		case -32:
			wrestler_wait_target_up(object);
			return;
		case -30:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -28:
			wrestler_blink_out(object, d, carry);
			return;
		case -26:
			wrestler_fall(object);
			return;
		case -24:
			wrestler_lie(object);
			return;
		case -22:
			wrestler_get_up(object);
			return;
		case -20:
			wrestler_flinch_wait(object);
			return;
		case -18:
			wrestler_flinch_land(object);
			return;
		case -16:
			wrestler_put_in(object);
			return;
		case -14:
			wrestler_entrance_drop(object);
			return;
		case -12:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case -10:
			wrestler_entrance_step_out(object);
			return;
		case -8:
			wrestler_entrance_land(object, action_handlers);
			return;
		case -6:
			wrestler_entrance_stand(object);
			return;
		case -4:
			wrestler_entrance_shout(object);
			return;
		case -2:
			wrestler_entrance_end(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler punches: after a wait, winds up, not to be hurt meanwhile. */
void wrestler_punch_wind_up(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0;
	uint8_t action_step = 0, action_step_2 = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	if (action_step != 0u)
	{
		action_step_2 = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step_2 - 1u;
		return;
	}
	animation_number = 0x200u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->flags |= 4u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler punches: hits on the animation's marked frame. */
void wrestler_punch_strike(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t own_box = 0;
	uint16_t box_number = 0, look_numbers = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action = 0;

	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		own_box = 1u;
	box_number = (uint32_t)own_box << 8;
	wrestler_set_hit_box(object, box_number);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 1u) == 0u)
		return;
	look_numbers = 0u;
	wrestler_set_animation(object, &look_numbers, &carry);
	look_numbers &= 0xFFu;
	wrestler_set_hit_box(object, look_numbers);
	OBJECT(object)->action_step = 0x10u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler punches: after 16 frames, stands and picks its target again. */
void wrestler_punch_recover(uint16_t object)
{
	uint16_t box_end = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return;
	box_end = wrestler_stand(object);
	wrestler_pick_target(object, box_end);
}

/* The wrestler guards (state 3). */
void wrestler_guard(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_guard_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_guarding(object);
			return;
		case 2:
			wrestler_jump_rise(object);
			return;
		case 4:
			wrestler_jump_land(object);
			return;
		case 6:
			wrestler_jump_recover(object);
			return;
		case 8:
			wrestler_jump_end(object, action_handlers);
			return;
		case 10:
			wrestler_idle_look(object);
			return;
		case 12:
			break;
		case -58:
			wrestler_beaten(object, d);
			return;
		case -56:
			wrestler_knocked_down(object, d);
			return;
		case -54:
			wrestler_flinch(object, d);
			return;
		case -52:
			wrestler_entrance(object, d);
			return;
		case -50:
			wrestler_walk(object);
			return;
		case -48:
			wrestler_punch(object, d);
			return;
		case -46:
			continue;
		case -44:
		case -42:
			wrestler_jump(object, d);
			return;
		case -40:
			wrestler_idle(object, d);
			return;
		case -38:
			wrestler_wait_target_up(object);
			return;
		case -36:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -34:
			wrestler_blink_out(object, d, carry);
			return;
		case -32:
			wrestler_fall(object);
			return;
		case -30:
			wrestler_lie(object);
			return;
		case -28:
			wrestler_get_up(object);
			return;
		case -26:
			wrestler_flinch_wait(object);
			return;
		case -24:
			wrestler_flinch_land(object);
			return;
		case -22:
			wrestler_put_in(object);
			return;
		case -20:
			wrestler_entrance_drop(object);
			return;
		case -18:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case -16:
			wrestler_entrance_step_out(object);
			return;
		case -14:
			wrestler_entrance_land(object, action_handlers);
			return;
		case -12:
			wrestler_entrance_stand(object);
			return;
		case -10:
			wrestler_entrance_shout(object);
			return;
		case -8:
			wrestler_entrance_end(object);
			return;
		case -6:
			wrestler_punch_wind_up(object);
			return;
		case -4:
			wrestler_punch_strike(object);
			return;
		case -2:
			wrestler_punch_recover(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler guards for 64 frames, hitting back on the marked frame, then stands. */
void wrestler_guarding(uint16_t object)
{
	uint8_t own_box = 0;
	uint16_t box_end = 0, box_number = 0;
	uint8_t action_step = 0, animation_flags = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		box_end = wrestler_stand(object);
		wrestler_pick_target(object, box_end);
		return;
	}
	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		own_box = 2u;
	box_number = (uint32_t)own_box << 8;
	wrestler_set_hit_box(object, box_number);
}

/* The wrestler jumps at a player (states 4 and 5), by its step. */
void wrestler_jump(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_jump_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_jump_rise(object);
			return;
		case 2:
			wrestler_jump_land(object);
			return;
		case 4:
			wrestler_jump_recover(object);
			return;
		case 6:
			wrestler_jump_end(object, action_handlers);
			return;
		case 8:
			wrestler_idle_look(object);
			return;
		case 10:
			break;
		case -60:
			wrestler_beaten(object, d);
			return;
		case -58:
			wrestler_knocked_down(object, d);
			return;
		case -56:
			wrestler_flinch(object, d);
			return;
		case -54:
			wrestler_entrance(object, d);
			return;
		case -52:
			wrestler_walk(object);
			return;
		case -50:
			wrestler_punch(object, d);
			return;
		case -48:
			wrestler_guard(object, d);
			return;
		case -46:
		case -44:
			continue;
		case -42:
			wrestler_idle(object, d);
			return;
		case -40:
			wrestler_wait_target_up(object);
			return;
		case -38:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -36:
			wrestler_blink_out(object, d, carry);
			return;
		case -34:
			wrestler_fall(object);
			return;
		case -32:
			wrestler_lie(object);
			return;
		case -30:
			wrestler_get_up(object);
			return;
		case -28:
			wrestler_flinch_wait(object);
			return;
		case -26:
			wrestler_flinch_land(object);
			return;
		case -24:
			wrestler_put_in(object);
			return;
		case -22:
			wrestler_entrance_drop(object);
			return;
		case -20:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case -18:
			wrestler_entrance_step_out(object);
			return;
		case -16:
			wrestler_entrance_land(object, action_handlers);
			return;
		case -14:
			wrestler_entrance_stand(object);
			return;
		case -12:
			wrestler_entrance_shout(object);
			return;
		case -10:
			wrestler_entrance_end(object);
			return;
		case -8:
			wrestler_punch_wind_up(object);
			return;
		case -6:
			wrestler_punch_strike(object);
			return;
		case -4:
			wrestler_punch_recover(object);
			return;
		case -2:
			wrestler_guarding(object);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler jumps: rises; at the top, turns to come down. */
void wrestler_jump_rise(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, ignored16 = 0;
	uint8_t z_speed = 0, action = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	z_speed = (uint8_t)(OBJECT(object)->z_speed >> 8u);
	if (z_speed != 0u)
		return;
	animation_number = 0x900u;
	wrestler_set_animation(object, &animation_number, &carry);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler jumps: lands shaking the screen (6400), hitting around it. */
void wrestler_jump_land(uint16_t object)
{
	uint32_t landed = 0;
	uint16_t box_number = 0, command = 0, ignored16 = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &landed);
	if (landed == 0u)
		return;
	OBJECT(object)->flags |= 0x40u;
	screen_shake_on = 1u;
	command = 0x6400u;
	vector_queue_sound(command);
	OBJECT(object)->flags |= 0x40u;
	box_number = 0x300u;
	wrestler_set_hit_box(object, box_number);
	OBJECT(object)->x_speed = 0;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler jumps: after landing, recovers. */
void wrestler_jump_recover(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t flags = 0;
	uint16_t animation_number = 0, box_number = 0;
	uint8_t action = 0, action_2 = 0;

	box_number = 0u;
	wrestler_set_hit_box(object, box_number);
	OBJECT(object)->action_step = 0x30u;
	flags = OBJECT(object)->flags & 0xBFu;
	OBJECT(object)->flags = flags;
	if ((flags & 0x20u) == 0u)
	{
		animation_number = 0xB00u;
		wrestler_set_animation(object, &animation_number, &carry);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
		return;
	}
	animation_number = 0xC00u;
	wrestler_set_animation(object, &animation_number, &carry);
	action_2 = OBJECT(object)->action;
	OBJECT(object)->action = action_2 + 1u;
}

/* The wrestler jumps: after 48 frames, walks again. */
void wrestler_jump_end(uint16_t object, uint16_t nearest)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->flags |= 0x40u;
		OBJECT(object)->state = 1u;
		OBJECT(object)->action = 0u;
		wrestler_pick_target(object, nearest);
	}
}

/* The wrestler with no target (state 6), by its step. */
void wrestler_idle(uint16_t object, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t action_index = 0;
	uint16_t action_handlers = 0;
	uint8_t action = 0;

	for (;;)
	{
		action_handlers = wrestler_idle_actions_ADDRESS;
		action = OBJECT(object)->action;
		action_index = action;
		carry = (int8_t)action_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)action_index << 1))
		{
		case 0:
			wrestler_idle_look(object);
			return;
		case 2:
			break;
		case -68:
			wrestler_beaten(object, d);
			return;
		case -66:
			wrestler_knocked_down(object, d);
			return;
		case -64:
			wrestler_flinch(object, d);
			return;
		case -62:
			wrestler_entrance(object, d);
			return;
		case -60:
			wrestler_walk(object);
			return;
		case -58:
			wrestler_punch(object, d);
			return;
		case -56:
			wrestler_guard(object, d);
			return;
		case -54:
		case -52:
			wrestler_jump(object, d);
			return;
		case -50:
			continue;
		case -48:
			wrestler_wait_target_up(object);
			return;
		case -46:
			wrestler_beaten_wait(object, action_handlers);
			return;
		case -44:
			wrestler_blink_out(object, d, carry);
			return;
		case -42:
			wrestler_fall(object);
			return;
		case -40:
			wrestler_lie(object);
			return;
		case -38:
			wrestler_get_up(object);
			return;
		case -36:
			wrestler_flinch_wait(object);
			return;
		case -34:
			wrestler_flinch_land(object);
			return;
		case -32:
			wrestler_put_in(object);
			return;
		case -30:
			wrestler_entrance_drop(object);
			return;
		case -28:
			wrestler_entrance_pose(object, action_handlers);
			return;
		case -26:
			wrestler_entrance_step_out(object);
			return;
		case -24:
			wrestler_entrance_land(object, action_handlers);
			return;
		case -22:
			wrestler_entrance_stand(object);
			return;
		case -20:
			wrestler_entrance_shout(object);
			return;
		case -18:
			wrestler_entrance_end(object);
			return;
		case -16:
			wrestler_punch_wind_up(object);
			return;
		case -14:
			wrestler_punch_strike(object);
			return;
		case -12:
			wrestler_punch_recover(object);
			return;
		case -10:
			wrestler_guarding(object);
			return;
		case -8:
			wrestler_jump_rise(object);
			return;
		case -6:
			wrestler_jump_land(object);
			return;
		case -4:
			wrestler_jump_recover(object);
			return;
		case -2:
			wrestler_jump_end(object, action_handlers);
			return;
		}
		break;
	}
	wrestler_idle_end(object, action_handlers);
}

/* The wrestler with no target: waits for a player; one there, taunts. */
void wrestler_idle_look(uint16_t object)
{
	uint32_t player_found = 0;
	uint16_t animation_number = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t action = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	find_nearest_player(object, &ignored16, &ignored16_2, &player_found);
	if (player_found == 0u)
		return;
	OBJECT(object)->flags |= 0x40u;
	OBJECT(object)->action_step = 0x60u;
	animation_number = 0xA00u;
	wrestler_set_animation(object, &animation_number, &player_found);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler with no target: after the taunt, walks again. */
void wrestler_idle_end(uint16_t object, uint16_t nearest)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->state = 1u;
		OBJECT(object)->action = 0u;
		wrestler_pick_target(object, nearest);
	}
}

/* The wrestler waits while its target is down, then stands (no scenario reaches it). */
void wrestler_wait_target_up(uint16_t object)
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
		wrestler_stand(object);
		return;
	}
	leftover_y = target_player;
}

/* The wrestler: when hit, takes the hit. */
uint16_t wrestler_check_hit(uint16_t object, uint8_t state)
{
	uint32_t negative_hit = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, d_2 = 0;
	uint8_t hit = 0;

	b = (uint8_t)state;
	a = OBJECT(object)->flags;
	if ((a & 0x20u) != 0u)
	{
		hit = OBJECT(object)->hit;
		negative_hit = hit >> 7;
		b = hit;
		if (hit != 0u && negative_hit == 0u)
		{
			d = wrestler_take_hit(object);
			a = (uint8_t)(d >> 8);
			b = (uint8_t)d;
		}
	}
	d_2 = ((uint32_t)a << 8) | b;
	return d_2;
}

/* The wrestler walking: when facing its target and within reach, decides how to attack (carry: it did). */
void wrestler_approach(uint16_t object, uint16_t *p_object_2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t jump_chance = 0, leap_speed_high = 0, leap_speed_low = 0;
	uint16_t animation_number = 0, chance_table = 0, target = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0, last_health = 0, vitality = 0, vitality_2 = 0, attributes_3 = 0;
	uint16_t walk_target = 0, own_x = 0, target_x = 0, attack_target = 0;

	walk_target = OBJECT(object)->wrestler.target;
	target = walk_target;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target)->x;
	if ((int16_t)own_x < (int16_t)target_x)
	{
		attributes = OBJECT(object)->attributes;
		if ((attributes & 0x40u) != 0u)
		{
			carry = 0u;
			*p_object_2 = target;
			*p_carry = carry;
			return;
		}
	}
	else
	{
		attributes_2 = OBJECT(object)->attributes;
		if ((attributes_2 & 0x40u) == 0u)
		{
			carry = 0u;
			*p_object_2 = target;
			*p_carry = carry;
			return;
		}
	}
	carry = wrestler_within_reach(object, target);
	if (carry == 0u)
	{
		carry = 0u;
		*p_object_2 = target;
		*p_carry = carry;
		return;
	}
	attack_target = OBJECT(object)->wrestler.target;
	target = attack_target;
	state = OBJECT(target)->state;
	if ((int8_t)state < 0)
	{
		carry = wrestler_go_idle(object);
		*p_object_2 = target;
		*p_carry = carry;
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	wrestler_face_target(object);
	OBJECT(object)->action_step = 0u;
	chance_table = wrestler_quick_attack_chances_by_players_ADDRESS;
	if (wrestler_quick_attack_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))] <= random_number)
	{
		last_health = OBJECT(object)->wrestler.last_health;
		vitality = OBJECT(object)->vitality;
		if ((uint8_t)(last_health - vitality) < 0xCu)
		{
			OBJECT(object)->state = 2u;
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0x20u;
			carry = 1u;
			*p_object_2 = chance_table;
			*p_carry = carry;
			return;
		}
	}
	vitality_2 = OBJECT(object)->vitality;
	OBJECT(object)->wrestler.last_health = vitality_2;
	carry = wrestler_surrounded(object);
	if (carry)
	{
		chance_table = wrestler_guard_chances_by_players_ADDRESS;
		if (random_number < wrestler_guard_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))])
		{
			OBJECT(object)->flags |= 4u;
			OBJECT(object)->action_step = 0x40u;
			OBJECT(object)->state = 3u;
			OBJECT(object)->action = 0u;
			animation_number = 0x800u;
			wrestler_set_animation(object, &animation_number, &carry);
			wrestler_face_target(object);
			carry = 1u;
			*p_object_2 = chance_table;
			*p_carry = carry;
			return;
		}
	}
	chance_table = wrestler_jump_chances_by_rank_ADDRESS;
	jump_chance = wrestler_jump_chances_by_rank[rank >> 1];
	attack_roll = random_number + (uint8_t)frame_count;
	if (jump_chance <= attack_roll)
	{
		OBJECT(object)->state = 2u;
		OBJECT(object)->action = 0u;
		carry = 1u;
		*p_object_2 = chance_table;
		*p_carry = carry;
		return;
	}
	OBJECT(object)->state = 4u;
	OBJECT(object)->action = 0u;
	animation_number = 0x700u;
	wrestler_set_animation(object, &animation_number, &carry);
	wrestler_face_target(object);
	attributes_3 = OBJECT(object)->attributes;
	if ((attributes_3 & 0x40u) == 0u)
	{
		leap_speed_high = 1u;
		leap_speed_low = 0x80u;
	}
	else
	{
		leap_speed_high = 0xFEu;
		leap_speed_low = 0x80u;
	}
	OBJECT(object)->x_speed = ((uint32_t)leap_speed_high << 8) | leap_speed_low;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0x700;
	OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 8u;
	carry = 1u;
	*p_object_2 = chance_table;
	*p_carry = carry;
}

/* The wrestler: keeps its target a while, then takes the nearest player; with none present, goes idle. */
void wrestler_pick_target(uint16_t object, uint16_t nearest)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, target_player = 0;
	uint8_t state = 0, target_wait = 0, target_wait_2 = 0;
	uint16_t kept_target = 0;

	find_nearest_player(object, &nearest, &ignored16, &carry);
	if (carry == 0u)
	{
		wrestler_go_idle(object);
		return;
	}
	kept_target = OBJECT(object)->wrestler.target;
	target_player = kept_target;
	if (OBJECT(target_player)->flags != 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state >= 0)
		{
			target_wait = OBJECT(object)->wrestler.target_wait;
			if (target_wait != 0u)
			{
				target_wait_2 = OBJECT(object)->wrestler.target_wait;
				OBJECT(object)->wrestler.target_wait = target_wait_2 - 1u;
				leftover_y = target_player;
				return;
			}
		}
	}
	OBJECT(object)->wrestler.target_wait = 0x40u;
	OBJECT(object)->wrestler.target = nearest;
	leftover_y = target_player;
}

/* The wrestler: the direction to the side of its target (field 2D) and to the target itself (2E). */
void wrestler_aim(uint16_t object)
{
	uint8_t side_offset = 0;
	uint16_t aim_direction = 0, direction = 0, target_player = 0;
	uint16_t aim_target = 0, own_x = 0, target_x = 0;

	aim_target = OBJECT(object)->wrestler.target;
	target_player = aim_target;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target_player)->x;
	if ((int16_t)target_x < (int16_t)own_x)
		side_offset = 0x20u;
	else
		side_offset = 0xE0u;
	aim_direction = side_offset;
	aim_direction = vector_direction_to_offset(object, target_player, aim_direction);
	OBJECT(object)->wrestler.side_direction = ((aim_direction & ~0xFFu) | side_offset) >> 8;
	direction = vector_direction_to(object, target_player);
	OBJECT(object)->wrestler.direction = (direction | side_offset) >> 8;
}

/* The wrestler: turns to face its target. */
void wrestler_face_target(uint16_t object)
{
	uint8_t direction = 0, attributes = 0, attributes_2 = 0;

	direction = OBJECT(object)->wrestler.direction;
	if ((uint8_t)(direction + 0x40u) >= 0x80u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
		return;
	}
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes_2 & 0xBFu;
}

/* The wrestler: sets the given animation (wrestler_animations). */
void wrestler_set_animation(uint16_t object, uint16_t *p_animation_number, uint32_t *p_carry)
{
	uint16_t animation_number = (uint16_t)*p_animation_number;
	uint32_t carry = *p_carry;
	uint8_t animation_index = 0, new_animation = 0, new_kind = 0;
	uint16_t kind_and_animation = 0;
	uint16_t kind_with_animation = 0;
	uint32_t kind_halfword = 0;

	animation_index = (uint8_t)(animation_number >> 8);
	carry = (int8_t)animation_index < 0;
	kind_with_animation = wrestler_animations[animation_index & 0x7Fu];
	new_kind = (uint8_t)(kind_with_animation >> 8);
	new_animation = kind_with_animation | 0x80u;
	kind_halfword = ((uint32_t)new_kind << 8) | new_animation;
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
	kind_and_animation = ((uint32_t)new_kind << 8) | new_animation;
	*p_animation_number = kind_and_animation;
	*p_carry = carry;
}

/* The wrestler: sets the given hit box (wrestler_hit_boxes). */
uint16_t wrestler_set_hit_box(uint16_t object, uint16_t box_number)
{
	uint16_t box_end = 0;
	uint16_t box_record = 0, damage_attack = 0, box_cursor = 0, width_depth = 0, box_cursor_2 = 0, height_dx = 0, box_cursor_3 = 0, dy_dz = 0;

	box_record = wrestler_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(box_number >> 8) << 1) << 1) << 1);
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
	OBJECT(object)->box_dy = (uint8_t)(dy_dz >> 8u);
	OBJECT(object)->box_dz = (uint8_t)dy_dz;
	return box_end;
}

/* The wrestler: stops it at the edges of its fighting area. */
void wrestler_keep_in_area(uint16_t object)
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
	if ((int16_t)next_stage_x <= 0x57F || (int16_t)next_stage_x >= 0x69F)
		OBJECT(object)->x_speed = 0;
}

/* The wrestler: whether the given object is within its reach (carry). */
uint32_t wrestler_within_reach(uint16_t object, uint16_t object_2)
{
	uint32_t in_reach = 0;
	uint16_t distance = 0;
	uint16_t own_x = 0, player_at_x = 0, own_y = 0, player_at_y = 0;

	own_x = OBJECT(object)->x;
	player_at_x = OBJECT(object_2)->x;
	distance = own_x - player_at_x;
	if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x40)
	{
		own_y = OBJECT(object)->y;
		player_at_y = OBJECT(object_2)->y;
		distance = own_y - player_at_y;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 4)
		{
			in_reach = 1u;
			return in_reach;
		}
	}
	in_reach = 0u;
	return in_reach;
}

/* The wrestler: whether it should guard: alone with one player, or with two or more players within reach
   (carry). */
uint32_t wrestler_surrounded(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t object_2 = 0;
	uint8_t players_in_reach = 0, slots_left = 0;
	uint8_t state = 0, players_to_check = 0;

	if (player_count == 1u)
	{
		carry = 1u;
		return carry;
	}
	object_2 = OBJECT_ADDRESS(0);
	players_in_reach = 0u;
	slots_left = 4u;
	do
	{
		if (OBJECT(object_2)->flags != 0u)
		{
			state = OBJECT(object_2)->state;
			if ((int8_t)state >= 0)
			{
				carry = wrestler_within_reach(object, object_2);
				if (carry)
					players_in_reach = players_in_reach + 1u;
			}
		}
		object_2 += 0xC0u;
		players_to_check = slots_left;
		slots_left = players_to_check - 1u;
	} while (players_to_check != 1u);
	if (players_in_reach < 2u)
	{
		carry = 0u;
		return carry;
	}
	carry = 1u;
	return carry;
}

/* The wrestler stands and goes back to walking. */
uint16_t wrestler_stand(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box_end = 0, look_numbers = 0;

	look_numbers = 0x100u;
	wrestler_set_animation(object, &look_numbers, &carry);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0x40u) & ~4u;
	look_numbers &= 0xFFu;
	box_end = wrestler_set_hit_box(object, look_numbers);
	OBJECT(object)->state = 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return box_end;
}

/* The wrestler has no target left: laughs (6800) and waits. */
uint32_t wrestler_go_idle(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;

	command = 0x6800u;
	vector_queue_sound(command);
	OBJECT(object)->state = 6u;
	OBJECT(object)->action = 0u;
	animation_number = 0x100u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->flags &= 0xBFu;
	return carry;
}

/* The wrestler takes a hit: flashes; with no health left or on a heavy hit (or every fifth) it is
   knocked down, else it flinches. */
uint16_t wrestler_take_hit(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, box_number = 0, command = 0, d = 0, object_2 = 0, palette_effect_number = 0;
	uint8_t vitality = 0, hit = 0, hits = 0, hits_2 = 0, direction = 0;
	uint16_t hit_by = 0;

	hit_by = OBJECT(object)->hit_by;
	object_2 = hit_by;
	OBJECT(object_2)->behaviour = (OBJECT(object_2)->behaviour & 0xFFu) | 0x100u;
	AT16(OBJECT(object_2)->hit_box, -1) = object;
	OBJECT(object)->flags &= 0xBBu;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	palette_request_kind = 2u;
	palette_effect_number = 2u;
	vector_palette_request(object_2, palette_effect_number);
	command = 0x6600u;
	vector_queue_sound(command);
	box_number = 0u;
	wrestler_set_hit_box(object, box_number);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		command = 0x6600u;
		vector_queue_sound_unless_attract(command);
	}
	else
	{
		hit = OBJECT(object)->hit;
		if (hit != 0x13u)
		{
			hits = OBJECT(object)->wrestler.hits;
			if (hits != 4u)
			{
				hits_2 = OBJECT(object)->wrestler.hits;
				OBJECT(object)->wrestler.hits = hits_2 + 1u;
				d = 0x300u;
				wrestler_set_animation(object, &d, &carry);
				OBJECT(object)->state = 0xFFu;
				OBJECT(object)->action = 0u;
				d = (d & 0xFFu) | 0xFF00u;
				return d;
			}
		}
		command = 0x6900u;
		vector_queue_sound(command);
	}
	OBJECT(object)->wrestler.hits = 0u;
	animation_number = 0x400u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->state = 0xFEu;
	OBJECT(object)->action = 0u;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0x400;
	direction = OBJECT(object)->wrestler.direction;
	if ((uint8_t)(direction + 0x40u) < 0x80u)
	{
		d = 0xFD00u;
		OBJECT(object)->x_speed = -0x300;
		return d;
	}
	d = 0x300u;
	OBJECT(object)->x_speed = 0x300;
	return d;
}
