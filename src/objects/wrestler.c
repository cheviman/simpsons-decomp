/**
 *    Name:        objects/wrestler.c
 *    Description: stage 1's boss, the wrestler
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The wrestler beaten (state FD), by its step: a wait, then it blinks out. */
uint16_t wrestler_beaten(uint16_t object, uint16_t y, uint8_t d)
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
			return wrestler_beaten_wait(object, y, action_handlers);
		case 2:
			wrestler_blink_out(object, d, carry);
			return y;
		case 4:
			wrestler_fall(object);
			return y;
		case 6:
			wrestler_lie(object);
			return y;
		case 8:
			return wrestler_get_up(object, y);
		case 10:
			wrestler_flinch_wait(object);
			return y;
		case 12:
			return wrestler_flinch_land(object, y);
		case 14:
			return wrestler_put_in(object, y);
		case 16:
			wrestler_entrance_drop(object);
			return y;
		case 18:
			return wrestler_entrance_pose(object, y, action_handlers);
		case 20:
			wrestler_entrance_step_out(object);
			return y;
		case 22:
			return wrestler_entrance_land(object, y, action_handlers);
		case 24:
			wrestler_entrance_stand(object);
			return y;
		case 26:
			wrestler_entrance_shout(object);
			return y;
		case 28:
			wrestler_entrance_end(object);
			return y;
		case 30:
			wrestler_punch_wind_up(object);
			return y;
		case 32:
			wrestler_punch_strike(object);
			return y;
		case 34:
			return wrestler_punch_recover(object, y);
		case 36:
			return wrestler_guarding(object, y);
		case 38:
			wrestler_jump_rise(object);
			return y;
		case 40:
			wrestler_jump_land(object);
			return y;
		case 42:
			wrestler_jump_recover(object);
			return y;
		case 44:
			return wrestler_jump_end(object, y, action_handlers);
		case 46:
			wrestler_idle_look(object);
			return y;
		case 48:
			break;
		case -22:
			continue;
		case -20:
			return wrestler_knocked_down(object, y, d);
		case -18:
			return wrestler_flinch(object, y, d);
		case -16:
			return wrestler_entrance(object, y, d);
		case -14:
			return wrestler_walk(object, y);
		case -12:
			return wrestler_punch(object, y, d);
		case -10:
			return wrestler_guard(object, y, d);
		case -8:
		case -6:
			return wrestler_jump(object, y, d);
		case -4:
			return wrestler_idle(object, y, d);
		case -2:
			return wrestler_wait_target_up(object, y);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
}

/* The wrestler beaten: waits, then a palette flash and a sound (6700). */
uint16_t wrestler_beaten_wait(uint16_t object, uint16_t y, uint16_t palette_job)
{
	uint32_t carry = 0;
	uint16_t command = 0, palette_effect_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return y;
	palette_request_kind = 2u;
	palette_effect_number = 0x20u;
	vector_palette_request(palette_effect_number, &y, &palette_job);
	command = 0x6700u;
	carry = vector_queue_sound(command);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
}

/* The wrestler beaten: blinks for 64 frames, then it and its partner are gone, the boss counts as beaten
   and the step goes on. */
void wrestler_blink_out(uint16_t object, uint8_t d, uint32_t carry)
{
	uint8_t frame_bit = 0;
	uint8_t t1 = 0, action_step = 0, action_step_2 = 0, points = 0;
	uint16_t partner = 0;
	uint32_t step_subphase_halfword = 0;

	OBJECT(object)->flags &= 0x7Fu;
	frame_bit = (uint8_t)frame_count & 1u;
	t1 = (frame_bit >> 1) | (carry << 7);
	carry = frame_bit;
	OBJECT(object)->flags |= (t1 >> 1) | (carry << 7);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	action_step_2 = OBJECT(object)->action_step;
	if (action_step_2 == 0x40u)
	{
		points = OBJECT(object)->points;
		OBJECT(object)->points = points | 0x81u;
		OBJECT(object)->flags = 0u;
		partner = OBJECT(object)->wrestler.partner;
		mem_write8(partner, 0u);
		boss_beaten = 1u;
		step_phase++;
		step_subphase_halfword = 0x100u | (d & 0xFFu);
		step_subphase = (uint8_t)(step_subphase_halfword >> 8u);
		step_countdown = (uint8_t)step_subphase_halfword;
	}
}

/* The wrestler knocked down (state FE), by its step: falls, lies, gets up. */
uint16_t wrestler_knocked_down(uint16_t object, uint16_t y, uint8_t d)
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
			return y;
		case 2:
			wrestler_lie(object);
			return y;
		case 4:
			return wrestler_get_up(object, y);
		case 6:
			wrestler_flinch_wait(object);
			return y;
		case 8:
			return wrestler_flinch_land(object, y);
		case 10:
			return wrestler_put_in(object, y);
		case 12:
			wrestler_entrance_drop(object);
			return y;
		case 14:
			return wrestler_entrance_pose(object, y, action_handlers);
		case 16:
			wrestler_entrance_step_out(object);
			return y;
		case 18:
			return wrestler_entrance_land(object, y, action_handlers);
		case 20:
			wrestler_entrance_stand(object);
			return y;
		case 22:
			wrestler_entrance_shout(object);
			return y;
		case 24:
			wrestler_entrance_end(object);
			return y;
		case 26:
			wrestler_punch_wind_up(object);
			return y;
		case 28:
			wrestler_punch_strike(object);
			return y;
		case 30:
			return wrestler_punch_recover(object, y);
		case 32:
			return wrestler_guarding(object, y);
		case 34:
			wrestler_jump_rise(object);
			return y;
		case 36:
			wrestler_jump_land(object);
			return y;
		case 38:
			wrestler_jump_recover(object);
			return y;
		case 40:
			return wrestler_jump_end(object, y, action_handlers);
		case 42:
			wrestler_idle_look(object);
			return y;
		case 44:
			break;
		case -26:
			return wrestler_beaten(object, y, d);
		case -24:
			continue;
		case -22:
			return wrestler_flinch(object, y, d);
		case -20:
			return wrestler_entrance(object, y, d);
		case -18:
			return wrestler_walk(object, y);
		case -16:
			return wrestler_punch(object, y, d);
		case -14:
			return wrestler_guard(object, y, d);
		case -12:
		case -10:
			return wrestler_jump(object, y, d);
		case -8:
			return wrestler_idle(object, y, d);
		case -6:
			return wrestler_wait_target_up(object, y);
		case -4:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -2:
			wrestler_blink_out(object, d, carry);
			return y;
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
}

/* The wrestler knocked down: falls; landing with too little health it is beaten, else it lies. */
void wrestler_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, ignored16 = 0;
	uint8_t vitality = 0, shadow_player = 0, action = 0;
	uint16_t partner = 0, hit_by = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (vitality <= wrestler_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))])
	{
		command = 0x9800u;
		carry = vector_queue_sound_unless_attract(command);
		OBJECT(object)->flags = (OBJECT(object)->flags & 0xBFu) | 4u;
		partner = OBJECT(object)->wrestler.partner;
		mem_write16(partner + 0x19u, 0x100u);
		animation_number = 0x600u;
		wrestler_set_animation(object, &animation_number, &carry);
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
	wrestler_set_animation(object, &animation_number, &carry);
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
uint16_t wrestler_get_up(uint16_t object, uint16_t y)
{
	uint16_t u = 0;
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return y;
	u = wrestler_stand(object);
	return wrestler_pick_target(object, y, u);
}

/* The wrestler hit (state FF), by its step. */
uint16_t wrestler_flinch(uint16_t object, uint16_t y, uint8_t d)
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
			return y;
		case 2:
			return wrestler_flinch_land(object, y);
		case 4:
			return wrestler_put_in(object, y);
		case 6:
			wrestler_entrance_drop(object);
			return y;
		case 8:
			return wrestler_entrance_pose(object, y, action_handlers);
		case 10:
			wrestler_entrance_step_out(object);
			return y;
		case 12:
			return wrestler_entrance_land(object, y, action_handlers);
		case 14:
			wrestler_entrance_stand(object);
			return y;
		case 16:
			wrestler_entrance_shout(object);
			return y;
		case 18:
			wrestler_entrance_end(object);
			return y;
		case 20:
			wrestler_punch_wind_up(object);
			return y;
		case 22:
			wrestler_punch_strike(object);
			return y;
		case 24:
			return wrestler_punch_recover(object, y);
		case 26:
			return wrestler_guarding(object, y);
		case 28:
			wrestler_jump_rise(object);
			return y;
		case 30:
			wrestler_jump_land(object);
			return y;
		case 32:
			wrestler_jump_recover(object);
			return y;
		case 34:
			return wrestler_jump_end(object, y, action_handlers);
		case 36:
			wrestler_idle_look(object);
			return y;
		case 38:
			break;
		case -32:
			return wrestler_beaten(object, y, d);
		case -30:
			return wrestler_knocked_down(object, y, d);
		case -28:
			continue;
		case -26:
			return wrestler_entrance(object, y, d);
		case -24:
			return wrestler_walk(object, y);
		case -22:
			return wrestler_punch(object, y, d);
		case -20:
			return wrestler_guard(object, y, d);
		case -18:
		case -16:
			return wrestler_jump(object, y, d);
		case -14:
			return wrestler_idle(object, y, d);
		case -12:
			return wrestler_wait_target_up(object, y);
		case -10:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -8:
			wrestler_blink_out(object, d, carry);
			return y;
		case -6:
			wrestler_fall(object);
			return y;
		case -4:
			wrestler_lie(object);
			return y;
		case -2:
			return wrestler_get_up(object, y);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
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
uint16_t wrestler_flinch_land(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return y;
	u = wrestler_stand(object);
	y = wrestler_pick_target(object, y, u);
	return y;
}

/* The wrestler's entrance (state 0), by its step. */
uint16_t wrestler_entrance(uint16_t object, uint16_t y, uint8_t d)
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
			return wrestler_put_in(object, y);
		case 2:
			wrestler_entrance_drop(object);
			return y;
		case 4:
			return wrestler_entrance_pose(object, y, action_handlers);
		case 6:
			wrestler_entrance_step_out(object);
			return y;
		case 8:
			return wrestler_entrance_land(object, y, action_handlers);
		case 10:
			wrestler_entrance_stand(object);
			return y;
		case 12:
			wrestler_entrance_shout(object);
			return y;
		case 14:
			wrestler_entrance_end(object);
			return y;
		case 16:
			wrestler_punch_wind_up(object);
			return y;
		case 18:
			wrestler_punch_strike(object);
			return y;
		case 20:
			return wrestler_punch_recover(object, y);
		case 22:
			return wrestler_guarding(object, y);
		case 24:
			wrestler_jump_rise(object);
			return y;
		case 26:
			wrestler_jump_land(object);
			return y;
		case 28:
			wrestler_jump_recover(object);
			return y;
		case 30:
			return wrestler_jump_end(object, y, action_handlers);
		case 32:
			wrestler_idle_look(object);
			return y;
		case 34:
			break;
		case -36:
			return wrestler_beaten(object, y, d);
		case -34:
			return wrestler_knocked_down(object, y, d);
		case -32:
			return wrestler_flinch(object, y, d);
		case -30:
			continue;
		case -28:
			return wrestler_walk(object, y);
		case -26:
			return wrestler_punch(object, y, d);
		case -24:
			return wrestler_guard(object, y, d);
		case -22:
		case -20:
			return wrestler_jump(object, y, d);
		case -18:
			return wrestler_idle(object, y, d);
		case -16:
			return wrestler_wait_target_up(object, y);
		case -14:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -12:
			wrestler_blink_out(object, d, carry);
			return y;
		case -10:
			wrestler_fall(object);
			return y;
		case -8:
			wrestler_lie(object);
			return y;
		case -6:
			return wrestler_get_up(object, y);
		case -4:
			wrestler_flinch_wait(object);
			return y;
		case -2:
			return wrestler_flinch_land(object, y);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
}

/* The wrestler's entrance: once the camera's flag from the stage record clears, drops it in from above
   with its partner object, sets its health and says a boss is in. */
uint16_t wrestler_put_in(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t slot_list = 0;
	uint16_t d = 0, palette_effect_number = 0, partner = 0;
	uint8_t action = 0;
	uint16_t t1 = 0, t2 = 0;

	OBJECT(object)->entrance_pending = 1u;
	if (stage_scrolls_on != 0u)
		return y;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->shadow_player = 1u;
	d = 0xE00u;
	wrestler_set_animation(object, &d, &carry);
	d &= 0xFFu;
	wrestler_set_hit_box(object, d);
	OBJECT(object)->x = 0xE0u;
	OBJECT(object)->y = 0x82u;
	t1 = 0x100u - camera_y;
	OBJECT(object)->z = t1;
	OBJECT(object)->z_speed = -0x100;
	OBJECT(object)->vitality = 0xC0u;
	OBJECT(object)->wrestler.last_health = 0xC0u;
	boss_arrived++;
	slot_list = 2u;
	vector_find_free_slot(slot_list, &partner, &carry);
	mem_write8(partner, 0x80u);
	mem_write8(partner + 6u, 0x80u);
	mem_write8(partner + 1u, 0u);
	mem_write16(partner + 4u, 0xF91u);
	mem_write16(partner + 0xCu, 0xE0u);
	mem_write16(partner + 0x11u, 0x80u);
	t2 = 0x158u - camera_y;
	mem_write16(partner + 0x16u, t2);
	mem_write16(partner + 0x19u, 0xFF00u);
	OBJECT(object)->wrestler.partner = partner;
	OBJECT(object)->entrance_pending = 0u;
	palette_request_kind = 2u;
	palette_effect_number = 0x16u;
	vector_palette_request(palette_effect_number, &y, &partner);
	palette_request_kind = 2u;
	palette_effect_number = 0x17u;
	vector_palette_request(palette_effect_number, &y, &partner);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
}

/* The wrestler's entrance: the two fall until the partner is down, then hold. */
void wrestler_entrance_drop(uint16_t object)
{
	uint16_t u = 0;
	uint8_t action = 0;
	uint16_t partner = 0, t1 = 0, t2 = 0, t3 = 0;

	partner = OBJECT(object)->wrestler.partner;
	u = partner;
	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x11u);
	if ((uint16_t)(t1 + t2 - camera_y) <= 0x130u)
	{
		t3 = mem_read16(u + 0x11u);
		mem_write16(u + 0x16u, 0x130u + camera_y - t3);
		OBJECT(object)->action_step = 0x20u;
		OBJECT(object)->z_speed = 0;
		mem_write16(u + 0x19u, 0u);
		action = OBJECT(object)->action;
		OBJECT(object)->action = action + 1u;
	}
}

/* The wrestler's entrance: a palette flash, a sound (6700) and a pose. */
uint16_t wrestler_entrance_pose(uint16_t object, uint16_t y, uint16_t palette_job)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, palette_effect_number = 0;
	uint8_t action_step = 0, action = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return y;
	palette_request_kind = 2u;
	palette_effect_number = 0xCu;
	vector_palette_request(palette_effect_number, &y, &palette_job);
	command = 0x6700u;
	carry = vector_queue_sound(command);
	animation_number = 0xF00u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
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
uint16_t wrestler_entrance_land(uint16_t object, uint16_t y, uint16_t palette_job)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0, ignored16 = 0, palette_effect_number = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return y;
	palette_request_kind = 2u;
	palette_effect_number = 0x21u;
	vector_palette_request(palette_effect_number, &y, &palette_job);
	palette_request_kind = 2u;
	palette_effect_number = 0x26u;
	vector_palette_request(palette_effect_number, &y, &palette_job);
	screen_shake_on = 1u;
	command = 0x6400u;
	carry = vector_queue_sound(command);
	OBJECT(object)->y_speed = 0;
	animation_number = 0xB00u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->action_step = 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
	return y;
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
	carry = vector_queue_sound(command);
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
uint16_t wrestler_walk(uint16_t object, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, heading = 0, u = 0;
	uint8_t animation = 0, side_direction = 0;

	wrestler_approach(object, &u, &carry);
	if (carry)
		return y;
	wrestler_pick_target(object, y, u);
	animation = OBJECT(object)->animation;
	if (animation != 0u)
	{
		animation_number = 0x100u;
		wrestler_set_animation(object, &animation_number, &carry);
	}
	wrestler_aim(object);
	side_direction = OBJECT(object)->wrestler.side_direction;
	y = wrestler_speeds_by_rank_ADDRESS;
	heading = ((uint32_t)side_direction << 8) | wrestler_speeds_by_rank[rank >> 1];
	vector_set_speed_by_direction(object, heading);
	wrestler_face_target(object);
	return y;
}

/* The wrestler punches (state 2), by its step. */
uint16_t wrestler_punch(uint16_t object, uint16_t y, uint8_t d)
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
			return y;
		case 2:
			wrestler_punch_strike(object);
			return y;
		case 4:
			return wrestler_punch_recover(object, y);
		case 6:
			return wrestler_guarding(object, y);
		case 8:
			wrestler_jump_rise(object);
			return y;
		case 10:
			wrestler_jump_land(object);
			return y;
		case 12:
			wrestler_jump_recover(object);
			return y;
		case 14:
			return wrestler_jump_end(object, y, action_handlers);
		case 16:
			wrestler_idle_look(object);
			return y;
		case 18:
			break;
		case -52:
			return wrestler_beaten(object, y, d);
		case -50:
			return wrestler_knocked_down(object, y, d);
		case -48:
			return wrestler_flinch(object, y, d);
		case -46:
			return wrestler_entrance(object, y, d);
		case -44:
			return wrestler_walk(object, y);
		case -42:
			continue;
		case -40:
			return wrestler_guard(object, y, d);
		case -38:
		case -36:
			return wrestler_jump(object, y, d);
		case -34:
			return wrestler_idle(object, y, d);
		case -32:
			return wrestler_wait_target_up(object, y);
		case -30:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -28:
			wrestler_blink_out(object, d, carry);
			return y;
		case -26:
			wrestler_fall(object);
			return y;
		case -24:
			wrestler_lie(object);
			return y;
		case -22:
			return wrestler_get_up(object, y);
		case -20:
			wrestler_flinch_wait(object);
			return y;
		case -18:
			return wrestler_flinch_land(object, y);
		case -16:
			return wrestler_put_in(object, y);
		case -14:
			wrestler_entrance_drop(object);
			return y;
		case -12:
			return wrestler_entrance_pose(object, y, action_handlers);
		case -10:
			wrestler_entrance_step_out(object);
			return y;
		case -8:
			return wrestler_entrance_land(object, y, action_handlers);
		case -6:
			wrestler_entrance_stand(object);
			return y;
		case -4:
			wrestler_entrance_shout(object);
			return y;
		case -2:
			wrestler_entrance_end(object);
			return y;
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
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
	uint16_t box_number = 0, d = 0;
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
	d = 0u;
	wrestler_set_animation(object, &d, &carry);
	d &= 0xFFu;
	wrestler_set_hit_box(object, d);
	OBJECT(object)->action_step = 0x10u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler punches: after 16 frames, stands and picks its target again. */
uint16_t wrestler_punch_recover(uint16_t object, uint16_t y)
{
	uint16_t u = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step != 1u)
		return y;
	u = wrestler_stand(object);
	y = wrestler_pick_target(object, y, u);
	return y;
}

/* The wrestler guards (state 3). */
uint16_t wrestler_guard(uint16_t object, uint16_t y, uint8_t d)
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
			return wrestler_guarding(object, y);
		case 2:
			wrestler_jump_rise(object);
			return y;
		case 4:
			wrestler_jump_land(object);
			return y;
		case 6:
			wrestler_jump_recover(object);
			return y;
		case 8:
			return wrestler_jump_end(object, y, action_handlers);
		case 10:
			wrestler_idle_look(object);
			return y;
		case 12:
			break;
		case -58:
			return wrestler_beaten(object, y, d);
		case -56:
			return wrestler_knocked_down(object, y, d);
		case -54:
			return wrestler_flinch(object, y, d);
		case -52:
			return wrestler_entrance(object, y, d);
		case -50:
			return wrestler_walk(object, y);
		case -48:
			return wrestler_punch(object, y, d);
		case -46:
			continue;
		case -44:
		case -42:
			return wrestler_jump(object, y, d);
		case -40:
			return wrestler_idle(object, y, d);
		case -38:
			return wrestler_wait_target_up(object, y);
		case -36:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -34:
			wrestler_blink_out(object, d, carry);
			return y;
		case -32:
			wrestler_fall(object);
			return y;
		case -30:
			wrestler_lie(object);
			return y;
		case -28:
			return wrestler_get_up(object, y);
		case -26:
			wrestler_flinch_wait(object);
			return y;
		case -24:
			return wrestler_flinch_land(object, y);
		case -22:
			return wrestler_put_in(object, y);
		case -20:
			wrestler_entrance_drop(object);
			return y;
		case -18:
			return wrestler_entrance_pose(object, y, action_handlers);
		case -16:
			wrestler_entrance_step_out(object);
			return y;
		case -14:
			return wrestler_entrance_land(object, y, action_handlers);
		case -12:
			wrestler_entrance_stand(object);
			return y;
		case -10:
			wrestler_entrance_shout(object);
			return y;
		case -8:
			wrestler_entrance_end(object);
			return y;
		case -6:
			wrestler_punch_wind_up(object);
			return y;
		case -4:
			wrestler_punch_strike(object);
			return y;
		case -2:
			return wrestler_punch_recover(object, y);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
}

/* The wrestler guards for 64 frames, hitting back on the marked frame, then stands. */
uint16_t wrestler_guarding(uint16_t object, uint16_t y)
{
	uint8_t own_box = 0;
	uint16_t box_number = 0, u = 0;
	uint8_t action_step = 0, animation_flags = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		u = wrestler_stand(object);
		return wrestler_pick_target(object, y, u);
	}
	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
		own_box = 2u;
	box_number = (uint32_t)own_box << 8;
	wrestler_set_hit_box(object, box_number);
	return y;
}

/* The wrestler jumps at a player (states 4 and 5), by its step. */
uint16_t wrestler_jump(uint16_t object, uint16_t y, uint8_t d)
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
			return y;
		case 2:
			wrestler_jump_land(object);
			return y;
		case 4:
			wrestler_jump_recover(object);
			return y;
		case 6:
			return wrestler_jump_end(object, y, action_handlers);
		case 8:
			wrestler_idle_look(object);
			return y;
		case 10:
			break;
		case -60:
			return wrestler_beaten(object, y, d);
		case -58:
			return wrestler_knocked_down(object, y, d);
		case -56:
			return wrestler_flinch(object, y, d);
		case -54:
			return wrestler_entrance(object, y, d);
		case -52:
			return wrestler_walk(object, y);
		case -50:
			return wrestler_punch(object, y, d);
		case -48:
			return wrestler_guard(object, y, d);
		case -46:
		case -44:
			continue;
		case -42:
			return wrestler_idle(object, y, d);
		case -40:
			return wrestler_wait_target_up(object, y);
		case -38:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -36:
			wrestler_blink_out(object, d, carry);
			return y;
		case -34:
			wrestler_fall(object);
			return y;
		case -32:
			wrestler_lie(object);
			return y;
		case -30:
			return wrestler_get_up(object, y);
		case -28:
			wrestler_flinch_wait(object);
			return y;
		case -26:
			return wrestler_flinch_land(object, y);
		case -24:
			return wrestler_put_in(object, y);
		case -22:
			wrestler_entrance_drop(object);
			return y;
		case -20:
			return wrestler_entrance_pose(object, y, action_handlers);
		case -18:
			wrestler_entrance_step_out(object);
			return y;
		case -16:
			return wrestler_entrance_land(object, y, action_handlers);
		case -14:
			wrestler_entrance_stand(object);
			return y;
		case -12:
			wrestler_entrance_shout(object);
			return y;
		case -10:
			wrestler_entrance_end(object);
			return y;
		case -8:
			wrestler_punch_wind_up(object);
			return y;
		case -6:
			wrestler_punch_strike(object);
			return y;
		case -4:
			return wrestler_punch_recover(object, y);
		case -2:
			return wrestler_guarding(object, y);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
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
	uint32_t carry = 0;
	uint16_t box_number = 0, command = 0, ignored16 = 0;
	uint8_t action = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->flags |= 0x40u;
	screen_shake_on = 1u;
	command = 0x6400u;
	carry = vector_queue_sound(command);
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
uint16_t wrestler_jump_end(uint16_t object, uint16_t y, uint16_t nearest)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->flags |= 0x40u;
		OBJECT(object)->state = 1u;
		OBJECT(object)->action = 0u;
		y = wrestler_pick_target(object, y, nearest);
	}
	return y;
}

/* The wrestler with no target (state 6), by its step. */
uint16_t wrestler_idle(uint16_t object, uint16_t y, uint8_t d)
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
			return y;
		case 2:
			break;
		case -68:
			return wrestler_beaten(object, y, d);
		case -66:
			return wrestler_knocked_down(object, y, d);
		case -64:
			return wrestler_flinch(object, y, d);
		case -62:
			return wrestler_entrance(object, y, d);
		case -60:
			return wrestler_walk(object, y);
		case -58:
			return wrestler_punch(object, y, d);
		case -56:
			return wrestler_guard(object, y, d);
		case -54:
		case -52:
			return wrestler_jump(object, y, d);
		case -50:
			continue;
		case -48:
			return wrestler_wait_target_up(object, y);
		case -46:
			return wrestler_beaten_wait(object, y, action_handlers);
		case -44:
			wrestler_blink_out(object, d, carry);
			return y;
		case -42:
			wrestler_fall(object);
			return y;
		case -40:
			wrestler_lie(object);
			return y;
		case -38:
			return wrestler_get_up(object, y);
		case -36:
			wrestler_flinch_wait(object);
			return y;
		case -34:
			return wrestler_flinch_land(object, y);
		case -32:
			return wrestler_put_in(object, y);
		case -30:
			wrestler_entrance_drop(object);
			return y;
		case -28:
			return wrestler_entrance_pose(object, y, action_handlers);
		case -26:
			wrestler_entrance_step_out(object);
			return y;
		case -24:
			return wrestler_entrance_land(object, y, action_handlers);
		case -22:
			wrestler_entrance_stand(object);
			return y;
		case -20:
			wrestler_entrance_shout(object);
			return y;
		case -18:
			wrestler_entrance_end(object);
			return y;
		case -16:
			wrestler_punch_wind_up(object);
			return y;
		case -14:
			wrestler_punch_strike(object);
			return y;
		case -12:
			return wrestler_punch_recover(object, y);
		case -10:
			return wrestler_guarding(object, y);
		case -8:
			wrestler_jump_rise(object);
			return y;
		case -6:
			wrestler_jump_land(object);
			return y;
		case -4:
			wrestler_jump_recover(object);
			return y;
		case -2:
			return wrestler_jump_end(object, y, action_handlers);
		}
		break;
	}
	return wrestler_idle_end(object, y, action_handlers);
}

/* The wrestler with no target: waits for a player; one there, taunts. */
void wrestler_idle_look(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t action = 0;

	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	find_nearest_player(object, &ignored16, &ignored16_2, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->flags |= 0x40u;
	OBJECT(object)->action_step = 0x60u;
	animation_number = 0xA00u;
	wrestler_set_animation(object, &animation_number, &carry);
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* The wrestler with no target: after the taunt, walks again. */
uint16_t wrestler_idle_end(uint16_t object, uint16_t y, uint16_t nearest)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step - 1u;
	if (action_step == 1u)
	{
		OBJECT(object)->state = 1u;
		OBJECT(object)->action = 0u;
		y = wrestler_pick_target(object, y, nearest);
	}
	return y;
}

/* The wrestler waits while its target is down, then stands (no scenario reaches it). */
uint16_t wrestler_wait_target_up(uint16_t object, uint16_t y)
{
	uint16_t target_player = 0;
	uint8_t state = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(y + 0x2Bu);
	target_player = t1;
	state = OBJECT(target_player)->state;
	if ((int8_t)state >= 0)
	{
		wrestler_stand(object);
		return target_player;
	}
	return target_player;
}

/* The wrestler: when hit, takes the hit. */
void wrestler_check_hit(uint16_t object, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t hit = 0;

	b = (uint8_t)d;
	a = OBJECT(object)->flags;
	if ((a & 0x20u) != 0u)
	{
		hit = OBJECT(object)->hit;
		negative = hit >> 7;
		b = hit;
		if (hit != 0u && negative == 0u)
		{
			wrestler_take_hit(object, &y, &d_2);
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
		}
	}
	d_2 = ((uint32_t)a << 8) | b;
	*p_y = y;
	*p_d = d_2;
}

/* The wrestler walking: when facing its target and within reach, decides how to attack (carry: it did). */
void wrestler_approach(uint16_t object, uint16_t *p_object_2, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t jump_chance = 0, leap_speed_high = 0, leap_speed_low = 0;
	uint16_t animation_number = 0, chance_table = 0, target = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0, last_health = 0, vitality = 0, vitality_2 = 0, attributes_3 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target = t1;
	t2 = OBJECT(object)->x;
	t3 = OBJECT(target)->x;
	if ((int16_t)t2 < (int16_t)t3)
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
	t4 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target = t4;
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
uint16_t wrestler_pick_target(uint16_t object, uint16_t y, uint16_t nearest)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, target_player = 0;
	uint8_t state = 0, target_wait = 0, target_wait_2 = 0;
	uint16_t t1 = 0;

	find_nearest_player(object, &nearest, &ignored16, &carry);
	if (carry == 0u)
	{
		carry = wrestler_go_idle(object);
		return y;
	}
	t1 = (((uint32_t)(OBJECT(object)->behaviour & 0xFFu) << 8u) | (OBJECT(object)->target_dx >> 8u));
	target_player = t1;
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
				return target_player;
			}
		}
	}
	OBJECT(object)->wrestler.target_wait = 0x40u;
	OBJECT(object)->behaviour = (OBJECT(object)->behaviour & 0xFF00u) | ((nearest >> 8u) & 0xFFu);
	OBJECT(object)->target_dx = (OBJECT(object)->target_dx & 0xFFu) | ((nearest & 0xFFu) << 8u);
	return target_player;
}

/* The wrestler: the direction to the side of its target (field 2D) and to the target itself (2E). */
void wrestler_aim(uint16_t object)
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
	uint8_t a = 0, new_animation = 0, new_kind = 0;
	uint16_t kind_and_animation = 0;
	uint16_t t1 = 0;
	uint32_t kind_halfword = 0;

	a = (uint8_t)(animation_number >> 8);
	carry = (int8_t)a < 0;
	t1 = wrestler_animations[a & 0x7Fu];
	new_kind = (uint8_t)(t1 >> 8);
	new_animation = t1 | 0x80u;
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
	uint16_t t1 = 0, field_1c = 0, t2 = 0, field_1f = 0, t3 = 0, field = 0, t4 = 0, field_23 = 0;

	t1 = wrestler_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(box_number >> 8) << 1) << 1) << 1);
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
	OBJECT(object)->box_dy = (uint8_t)(field_23 >> 8u);
	OBJECT(object)->box_dz = (uint8_t)field_23;
	return box_end;
}

/* The wrestler: stops it at the edges of its fighting area. */
void wrestler_keep_in_area(uint16_t object)
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
	if ((int16_t)next_stage_x <= 0x57F || (int16_t)next_stage_x >= 0x69F)
		OBJECT(object)->x_speed = 0;
}

/* The wrestler: whether the given object is within its reach (carry). */
uint32_t wrestler_within_reach(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint16_t distance = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = OBJECT(object)->x;
	t2 = OBJECT(object_2)->x;
	distance = t1 - t2;
	if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 0x40)
	{
		t3 = OBJECT(object)->y;
		t4 = OBJECT(object_2)->y;
		distance = t3 - t4;
		if ((int16_t)(distance >> 15 ? 0u - distance : distance) <= 4)
		{
			carry = 1u;
			return carry;
		}
	}
	carry = 0u;
	return carry;
}

/* The wrestler: whether it should guard: alone with one player, or with two or more players within reach
   (carry). */
uint32_t wrestler_surrounded(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t object_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t state = 0, t1 = 0;

	if (player_count == 1u)
	{
		carry = 1u;
		return carry;
	}
	object_2 = OBJECT_ADDRESS(0);
	stack = 0u;
	stack_2 = 4u;
	do
	{
		if (OBJECT(object_2)->flags != 0u)
		{
			state = OBJECT(object_2)->state;
			if ((int8_t)state >= 0)
			{
				carry = wrestler_within_reach(object, object_2);
				if (carry)
					stack = stack + 1u;
			}
		}
		object_2 += 0xC0u;
		t1 = stack_2;
		stack_2 = t1 - 1u;
	} while (t1 != 1u);
	if (stack < 2u)
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
	uint16_t d = 0, u = 0;

	d = 0x100u;
	wrestler_set_animation(object, &d, &carry);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0x40u) & ~4u;
	d &= 0xFFu;
	u = wrestler_set_hit_box(object, d);
	OBJECT(object)->state = 1u;
	OBJECT(object)->action = 0u;
	OBJECT(object)->action_step = 0u;
	return u;
}

/* The wrestler has no target left: laughs (6800) and waits. */
uint32_t wrestler_go_idle(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, command = 0;

	command = 0x6800u;
	carry = vector_queue_sound(command);
	OBJECT(object)->state = 6u;
	OBJECT(object)->action = 0u;
	animation_number = 0x100u;
	wrestler_set_animation(object, &animation_number, &carry);
	OBJECT(object)->flags &= 0xBFu;
	return carry;
}

/* The wrestler takes a hit: flashes; with no health left or on a heavy hit (or every fifth) it is
   knocked down, else it flinches. */
void wrestler_take_hit(uint16_t object, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint16_t animation_number = 0, box_number = 0, command = 0, d = 0, object_2 = 0, palette_effect_number = 0;
	uint8_t vitality = 0, direction = 0, hit = 0, hits = 0, hits_2 = 0;
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
	vector_palette_request(palette_effect_number, &y, &object_2);
	command = 0x6600u;
	carry = vector_queue_sound(command);
	box_number = 0u;
	wrestler_set_hit_box(object, box_number);
	vitality = OBJECT(object)->vitality;
	if (vitality == 0u)
	{
		command = 0x6600u;
		carry = vector_queue_sound_unless_attract(command);
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
		}
		else
		{
			d = 0x300u;
			OBJECT(object)->x_speed = 0x300;
		}
	}
	else
	{
		hit = OBJECT(object)->hit;
		if (hit == 0x13u)
		{
			command = 0x6900u;
			carry = vector_queue_sound(command);
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
			}
			else
			{
				d = 0x300u;
				OBJECT(object)->x_speed = 0x300;
			}
		}
		else
		{
			hits = OBJECT(object)->wrestler.hits;
			if (hits == 4u)
			{
				command = 0x6900u;
				carry = vector_queue_sound(command);
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
				}
				else
				{
					d = 0x300u;
					OBJECT(object)->x_speed = 0x300;
				}
			}
			else
			{
				hits_2 = OBJECT(object)->wrestler.hits;
				OBJECT(object)->wrestler.hits = hits_2 + 1u;
				d = 0x300u;
				wrestler_set_animation(object, &d, &carry);
				OBJECT(object)->state = 0xFFu;
				OBJECT(object)->action = 0u;
				d = (d & 0xFFu) | 0xFF00u;
			}
		}
	}
	*p_y = y;
	*p_d = d;
}
