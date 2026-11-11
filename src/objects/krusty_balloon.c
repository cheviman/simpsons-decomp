/**
 *    Name:        objects/krusty_balloon.c
 *    Description: the krusty balloon (stage 2's boss) and what it throws
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The krusty balloon, stage 2's boss: checks its hits (krusty_balloon_check_hit), runs its state (field
   02: -3 beaten, -2 knocked up, -1 flinching, 0 coming in, 1 chasing, 2 attacking, 3 throwing, 4
   stomping, 5 waiting for a target), keeps itself inside the arena and draws its 5-piece health gauge. */
uint16_t krusty_balloon(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t state_index = 0;
	uint16_t shade_step_and_row = 0, state_handlers = 0;
	uint8_t state = 0;

	OBJECT(object)->flags |= 0x10u;
	krusty_balloon_check_hit(object);
	state_handlers = krusty_balloon_states_ADDRESS;
	state = OBJECT(object)->state;
	state_index = state;
	carry = (int8_t)state_index < 0;
	switch ((int8_t)(uint8_t)((uint32_t)state_index << 1))
	{
	case 0:
		object = krusty_balloon_come_in(object);
		break;
	case 2:
		krusty_balloon_chase(object);
		break;
	case 4:
		object = krusty_balloon_attack(object);
		break;
	case 6:
		object = krusty_balloon_volley(object);
		break;
	case 8:
		object = krusty_balloon_stomping(object);
		break;
	case 10:
		krusty_balloon_wait_for_target(object);
		break;
	case 12:
		krusty_balloon_deflate(object);
		break;
	case 14:
		krusty_balloon_beaten_wait(object);
		break;
	case 16:
		krusty_balloon_wait_for_players(object);
		break;
	case 18:
		krusty_balloon_fall_and_land(object);
		break;
	case 20:
		krusty_balloon_fly_up(object);
		break;
	case 22:
		krusty_balloon_knocked_up_stomp(object, state_handlers);
		break;
	case 24:
		krusty_balloon_appear(object, state_handlers);
		break;
	case 26:
		krusty_balloon_rise(object);
		break;
	case 28:
		krusty_balloon_drift_away(object);
		break;
	case 30:
		krusty_balloon_drift_back(object);
		break;
	case 32:
		krusty_balloon_land(object);
		break;
	case 34:
		object = krusty_balloon_bounce_up(object);
		break;
	case 36:
		krusty_balloon_attack_start(object);
		break;
	case 38:
		krusty_balloon_attack_hit(object);
		break;
	case 40:
		krusty_balloon_attack_end(object, state_handlers);
		break;
	case 42:
		krusty_balloon_volley_take_position(object);
		break;
	case 44:
		object = krusty_balloon_volley_throw(object);
		break;
	case 46:
		krusty_balloon_volley_pause(object);
		break;
	case 48:
		krusty_balloon_volley_wait(object);
		break;
	case 50:
		krusty_balloon_volley_shrink(object, state_handlers);
		break;
	case 52:
		krusty_balloon_stomp_land(object);
		break;
	case 54:
		object = krusty_balloon_stomp_bounce(object);
		break;
	case 56:
		krusty_balloon_throw_right(state_handlers, carry);
		break;
	case 58:
		krusty_balloon_throw_spread(state_handlers, carry);
		break;
	case 60:
		krusty_balloon_throw_left(state_handlers, carry);
		break;
	case 62:
		krusty_balloon_wobble_widen(object);
		break;
	case 64:
		krusty_balloon_wobble_narrow(object);
		break;
	case 66:
		krusty_balloon_wobble_stretch(object);
		break;
	case 68:
		krusty_balloon_wobble_restore(object);
		break;
	case 70:
		krusty_balloon_rebound(object);
		break;
	case 72:
		krusty_balloon_rebound_end(object, state_handlers);
		break;
	case -6:
		object = krusty_balloon_beaten(object);
		break;
	case -4:
		object = krusty_balloon_knocked_up(object);
		break;
	case -2:
		object = krusty_balloon_flinch(object);
		break;
	}
	krusty_balloon_keep_in_arena_x(object);
	krusty_balloon_keep_in_arena_y(object);
	shade_step_and_row = ((uint32_t)krusty_balloon_gauge_piece_health_by_players[(int8_t)((uint8_t)(player_count - 1u))] << 8) | 1u;
	boss_shade_by_vitality(object, shade_step_and_row);
	return object;
}

/* What the krusty balloon throws: when hit stops and bursts; runs its state (field 02: -1 burst, 0
   flying, 1 drifting, 2 opening, 3 falling). */
void krusty_balloon_shot(uint16_t *p_object, uint16_t *p_state_handlers)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t state_handlers = 0;
	uint8_t state = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		krusty_balloon_shot_burst(object);
	}
	state_handlers = krusty_balloon_shot_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		krusty_balloon_shot_fly(object);
		break;
	case 2:
		krusty_balloon_shot_drift(object);
		break;
	case 4:
		krusty_balloon_shot_open(object);
		break;
	case 6:
		krusty_balloon_shot_fall(object);
		break;
	case 8:
		stage_1_title_card(&object, &state_handlers);
		break;
	case 10:
		stage_2_title_card(&object, &state_handlers);
		break;
	case 12:
	case 16:
	case 22:
	case 28:
		state_handlers = title_card_none(state_handlers);
		break;
	case 14:
		stage_3_title_card(&object, &state_handlers);
		break;
	case 18:
		stage_4_title_card(&object, &state_handlers);
		break;
	case 20:
		stage_5_title_card(&object, &state_handlers);
		break;
	case 24:
		stage_6_title_card(&object, &state_handlers);
		break;
	case 26:
		stage_7_title_card(&object, &state_handlers);
		break;
	case 30:
		stage_8_title_card(&object, &state_handlers);
		break;
	case 32:
		stage_1_title_sound();
		break;
	case 34:
		stage_1_title_show(&object, &state_handlers);
		break;
	case 36:
	case 60:
	case 66:
	case 74:
	case 80:
		object = title_card_count_frames();
		break;
	case 38:
	case 50:
		title_card_ready_screen();
		break;
	case 40:
		stage_2_title_show(&object, &state_handlers);
		break;
	case 42:
		object = stage_2_title_picture_sound();
		break;
	case 44:
		stage_3_title_ready_screen();
		break;
	case 46:
		stage_3_title_show(&object, &state_handlers);
		break;
	case 48:
		object = stage_3_title_picture_sound();
		break;
	case 52:
		stage_4_title_show(&object, &state_handlers);
		break;
	case 54:
		object = stage_4_title_picture_sound();
		break;
	case 56:
		stage_5_title_ready_screen();
		break;
	case 58:
		stage_5_title_show(&object, &state_handlers);
		break;
	case 62:
		stage_6_title_sound();
		break;
	case 64:
		stage_6_title_show(&object, &state_handlers);
		break;
	case 68:
		stage_7_title_sound();
		break;
	case 70:
		stage_7_title_show(&object, &state_handlers);
		break;
	case 72:
		object = stage_7_title_second_picture();
		break;
	case 76:
		stage_8_title_sound();
		break;
	case 78:
		stage_8_title_show(&object, &state_handlers);
		break;
	case -2:
		krusty_balloon_shot_vanish(object);
		break;
	}
	*p_object = object;
	*p_state_handlers = state_handlers;
}

/* Beaten (state -3): runs its step (field 28) while it drifts toward the middle of the screen at 4
   pixels a frame. */
uint16_t krusty_balloon_beaten(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;
	uint16_t screen_x = 0, x_speed = 0;

	step_handlers = krusty_balloon_beaten_actions_ADDRESS;
	step = OBJECT(object)->krusty_balloon.step;
	step_index = step;
	carry = (int8_t)step_index < 0;
	switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
	{
	case 0:
		krusty_balloon_deflate(object);
		break;
	case 2:
		krusty_balloon_beaten_wait(object);
		break;
	case 4:
		krusty_balloon_wait_for_players(object);
		break;
	case 6:
		krusty_balloon_fall_and_land(object);
		break;
	case 8:
		krusty_balloon_fly_up(object);
		break;
	case 10:
		krusty_balloon_knocked_up_stomp(object, step_handlers);
		break;
	case 12:
		krusty_balloon_appear(object, step_handlers);
		break;
	case 14:
		krusty_balloon_rise(object);
		break;
	case 16:
		krusty_balloon_drift_away(object);
		break;
	case 18:
		krusty_balloon_drift_back(object);
		break;
	case 20:
		krusty_balloon_land(object);
		break;
	case 22:
		object = krusty_balloon_bounce_up(object);
		break;
	case 24:
		krusty_balloon_attack_start(object);
		break;
	case 26:
		krusty_balloon_attack_hit(object);
		break;
	case 28:
		krusty_balloon_attack_end(object, step_handlers);
		break;
	case 30:
		krusty_balloon_volley_take_position(object);
		break;
	case 32:
		object = krusty_balloon_volley_throw(object);
		break;
	case 34:
		krusty_balloon_volley_pause(object);
		break;
	case 36:
		krusty_balloon_volley_wait(object);
		break;
	case 38:
		krusty_balloon_volley_shrink(object, step_handlers);
		break;
	case 40:
		krusty_balloon_stomp_land(object);
		break;
	case 42:
		object = krusty_balloon_stomp_bounce(object);
		break;
	case 44:
		krusty_balloon_throw_right(step_handlers, carry);
		break;
	case 46:
		krusty_balloon_throw_spread(step_handlers, carry);
		break;
	case 48:
		krusty_balloon_throw_left(step_handlers, carry);
		break;
	case 50:
		krusty_balloon_wobble_widen(object);
		break;
	case 52:
		krusty_balloon_wobble_narrow(object);
		break;
	case 54:
		krusty_balloon_wobble_stretch(object);
		break;
	case 56:
		krusty_balloon_wobble_restore(object);
		break;
	case 58:
		krusty_balloon_rebound(object);
		break;
	case 60:
		krusty_balloon_rebound_end(object, step_handlers);
		break;
	case -18:
		object = krusty_balloon_beaten(object);
		break;
	case -16:
		object = krusty_balloon_knocked_up(object);
		break;
	case -14:
		object = krusty_balloon_flinch(object);
		break;
	case -12:
		object = krusty_balloon_come_in(object);
		break;
	case -10:
		krusty_balloon_chase(object);
		break;
	case -8:
		object = krusty_balloon_attack(object);
		break;
	case -6:
		object = krusty_balloon_volley(object);
		break;
	case -4:
		object = krusty_balloon_stomping(object);
		break;
	case -2:
		krusty_balloon_wait_for_target(object);
		break;
	}
	OBJECT(object)->x_speed = 0x400;
	screen_x = OBJECT(object)->x;
	if ((int16_t)screen_x > 0xD0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	return object;
}

/* Beaten, step 0: shrinks a step a frame (its zoom, fields 0A-0B) down to 20, then waits 20 frames. */
void krusty_balloon_deflate(uint16_t object)
{
	uint8_t zoom_x = 0, step = 0, zoom_x_2 = 0, zoom_y = 0;

	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x < 0x20u)
	{
		OBJECT(object)->krusty_balloon.balloon_timer = 0x20u;
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
		return;
	}
	zoom_x_2 = OBJECT(object)->zoom_x;
	OBJECT(object)->zoom_x = zoom_x_2 - 1u;
	zoom_y = OBJECT(object)->zoom_y;
	OBJECT(object)->zoom_y = zoom_y - 1u;
}

/* Beaten, step 1: after its wait sets 184B and goes on. */
void krusty_balloon_beaten_wait(uint16_t object)
{
	uint8_t balloon_timer = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer == 1u)
	{
		io_write8(players_stop_request, 1u);
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
	}
}

/* Beaten, step 2: waits until every player stands idle, then keeps the players present (direct page 50)
   in direct page 85 and goes on. */
void krusty_balloon_wait_for_players(uint16_t object)
{
	uint8_t players_idle = 0, step = 0;

	players_idle = io_read8(players_all_idle);
	if (players_idle != 0u)
	{
		players_present = players_playing;
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
	}
}

/* Beaten, step 3: falls with gravity; landing, stops the music, plays sound 6C00, shakes the screen,
   keeps itself in 1852 and ends the stage step's substep (the stage is cleared). */
void krusty_balloon_fall_and_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t points = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	points = OBJECT(object)->points;
	OBJECT(object)->points = points | 0x81u;
	command = 0u;
	vector_queue_sound(command);
	command = 0x6C00u;
	vector_queue_sound(command);
	screen_shake_on = 1u;
	screen_shake_kind = 0u;
	io_write16(stage_kept_object, object);
	boss_beaten = 1u;
	step_phase++;
	step_subphase = 1u;
	step_countdown = 0u;
}

/* Knocked up (state -2): runs its step (field 28). */
uint16_t krusty_balloon_knocked_up(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;

	for (;;)
	{
		step_handlers = krusty_balloon_knocked_up_actions_ADDRESS;
		step = OBJECT(object)->krusty_balloon.step;
		step_index = step;
		carry = (int8_t)step_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
		{
		case 0:
			krusty_balloon_fly_up(object);
			return object;
		case 2:
			krusty_balloon_knocked_up_stomp(object, step_handlers);
			return object;
		case 4:
			krusty_balloon_appear(object, step_handlers);
			return object;
		case 6:
			krusty_balloon_rise(object);
			return object;
		case 8:
			krusty_balloon_drift_away(object);
			return object;
		case 10:
			krusty_balloon_drift_back(object);
			return object;
		case 12:
			krusty_balloon_land(object);
			return object;
		case 14:
			return krusty_balloon_bounce_up(object);
		case 16:
			krusty_balloon_attack_start(object);
			return object;
		case 18:
			krusty_balloon_attack_hit(object);
			return object;
		case 20:
			krusty_balloon_attack_end(object, step_handlers);
			return object;
		case 22:
			krusty_balloon_volley_take_position(object);
			return object;
		case 24:
			return krusty_balloon_volley_throw(object);
		case 26:
			krusty_balloon_volley_pause(object);
			return object;
		case 28:
			krusty_balloon_volley_wait(object);
			return object;
		case 30:
			krusty_balloon_volley_shrink(object, step_handlers);
			return object;
		case 32:
			krusty_balloon_stomp_land(object);
			return object;
		case 34:
			return krusty_balloon_stomp_bounce(object);
		case 36:
			krusty_balloon_throw_right(step_handlers, carry);
			return object;
		case 38:
			krusty_balloon_throw_spread(step_handlers, carry);
			return object;
		case 40:
			krusty_balloon_throw_left(step_handlers, carry);
			return object;
		case 42:
			krusty_balloon_wobble_widen(object);
			return object;
		case 44:
			krusty_balloon_wobble_narrow(object);
			return object;
		case 46:
			krusty_balloon_wobble_stretch(object);
			return object;
		case 48:
			krusty_balloon_wobble_restore(object);
			return object;
		case 50:
			krusty_balloon_rebound(object);
			return object;
		case 52:
			break;
		case -26:
			return krusty_balloon_beaten(object);
		case -24:
			continue;
		case -22:
			return krusty_balloon_flinch(object);
		case -20:
			return krusty_balloon_come_in(object);
		case -18:
			krusty_balloon_chase(object);
			return object;
		case -16:
			return krusty_balloon_attack(object);
		case -14:
			return krusty_balloon_volley(object);
		case -12:
			return krusty_balloon_stomping(object);
		case -10:
			krusty_balloon_wait_for_target(object);
			return object;
		case -8:
			krusty_balloon_deflate(object);
			return object;
		case -6:
			krusty_balloon_beaten_wait(object);
			return object;
		case -4:
			krusty_balloon_wait_for_players(object);
			return object;
		case -2:
			krusty_balloon_fall_and_land(object);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, step_handlers);
	return object;
}

/* Knocked up, step 0: bounces off the screen's sides until it is 80 high; there it stops and is beaten
   when its health is at krusty_balloon_beaten_health_by_players or below, else goes on. */
void krusty_balloon_fly_up(uint16_t object)
{
	uint8_t x_high = 0, x_low = 0;
	uint8_t vitality = 0, step = 0, shadow_player = 0;
	uint16_t z = 0, screen_x = 0, x_speed = 0, reversed_x_speed = 0, hit_by = 0;

	z = OBJECT(object)->z;
	if ((int16_t)z < 0x80)
	{
		screen_x = OBJECT(object)->x;
		x_high = (uint8_t)(screen_x >> 8);
		x_low = (uint8_t)screen_x;
		if ((int16_t)(((uint32_t)x_high << 8) | x_low) < 0x40 || (int16_t)(((uint32_t)x_high << 8) | x_low) > 0x17F)
		{
			x_speed = OBJECT(object)->x_speed;
			reversed_x_speed = 0u - x_speed;
			OBJECT(object)->x_speed = reversed_x_speed;
			return;
		}
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	vitality = OBJECT(object)->vitality;
	if (krusty_balloon_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))] < vitality)
	{
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
		screen_x = OBJECT(object)->x;
		x_high = (uint8_t)(screen_x >> 8);
		x_low = (uint8_t)screen_x;
		if ((int16_t)(((uint32_t)x_high << 8) | x_low) < 0x40 || (int16_t)(((uint32_t)x_high << 8) | x_low) > 0x17F)
		{
			x_speed = OBJECT(object)->x_speed;
			reversed_x_speed = 0u - x_speed;
			OBJECT(object)->x_speed = reversed_x_speed;
			return;
		}
		return;
	}
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	hit_by = OBJECT(object)->hit_by;
	shadow_player = OBJECT(hit_by)->shadow_player;
	OBJECT(object)->points = shadow_player & ~0xFu;
	OBJECT(object)->vitality = 0u;
	OBJECT(object)->state = 0xFDu;
	OBJECT(object)->krusty_balloon.step = 0u;
	OBJECT(object)->krusty_balloon.squash_step = 0u;
}

/* Knocked up, step 1: drops onto its target (krusty_balloon_stomp). */
void krusty_balloon_knocked_up_stomp(uint16_t object, uint16_t object_2)
{
	krusty_balloon_stomp(object, object_2);
}

/* Flinching (state -1): wobbles through its four squash steps, then goes back to chasing. */
uint16_t krusty_balloon_flinch(uint16_t balloon)
{
	uint32_t carry = 0;

	krusty_balloon_wobble(&balloon, &carry);
	if (carry)
	{
		krusty_balloon_start_chase(balloon);
		return balloon;
	}
	return balloon;
}

/* Coming in (state 0): runs its step (field 28). */
uint16_t krusty_balloon_come_in(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;

	for (;;)
	{
		step_handlers = krusty_balloon_come_in_actions_ADDRESS;
		step = OBJECT(object)->krusty_balloon.step;
		step_index = step;
		carry = (int8_t)step_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
		{
		case 0:
			krusty_balloon_appear(object, step_handlers);
			return object;
		case 2:
			krusty_balloon_rise(object);
			return object;
		case 4:
			krusty_balloon_drift_away(object);
			return object;
		case 6:
			krusty_balloon_drift_back(object);
			return object;
		case 8:
			krusty_balloon_land(object);
			return object;
		case 10:
			return krusty_balloon_bounce_up(object);
		case 12:
			krusty_balloon_attack_start(object);
			return object;
		case 14:
			krusty_balloon_attack_hit(object);
			return object;
		case 16:
			krusty_balloon_attack_end(object, step_handlers);
			return object;
		case 18:
			krusty_balloon_volley_take_position(object);
			return object;
		case 20:
			return krusty_balloon_volley_throw(object);
		case 22:
			krusty_balloon_volley_pause(object);
			return object;
		case 24:
			krusty_balloon_volley_wait(object);
			return object;
		case 26:
			krusty_balloon_volley_shrink(object, step_handlers);
			return object;
		case 28:
			krusty_balloon_stomp_land(object);
			return object;
		case 30:
			return krusty_balloon_stomp_bounce(object);
		case 32:
			krusty_balloon_throw_right(step_handlers, carry);
			return object;
		case 34:
			krusty_balloon_throw_spread(step_handlers, carry);
			return object;
		case 36:
			krusty_balloon_throw_left(step_handlers, carry);
			return object;
		case 38:
			krusty_balloon_wobble_widen(object);
			return object;
		case 40:
			krusty_balloon_wobble_narrow(object);
			return object;
		case 42:
			krusty_balloon_wobble_stretch(object);
			return object;
		case 44:
			krusty_balloon_wobble_restore(object);
			return object;
		case 46:
			krusty_balloon_rebound(object);
			return object;
		case 48:
			break;
		case -30:
			return krusty_balloon_beaten(object);
		case -28:
			return krusty_balloon_knocked_up(object);
		case -26:
			return krusty_balloon_flinch(object);
		case -24:
			continue;
		case -22:
			krusty_balloon_chase(object);
			return object;
		case -20:
			return krusty_balloon_attack(object);
		case -18:
			return krusty_balloon_volley(object);
		case -16:
			return krusty_balloon_stomping(object);
		case -14:
			krusty_balloon_wait_for_target(object);
			return object;
		case -12:
			krusty_balloon_deflate(object);
			return object;
		case -10:
			krusty_balloon_beaten_wait(object);
			return object;
		case -8:
			krusty_balloon_wait_for_players(object);
			return object;
		case -6:
			krusty_balloon_fall_and_land(object);
			return object;
		case -4:
			krusty_balloon_fly_up(object);
			return object;
		case -2:
			krusty_balloon_knocked_up_stomp(object, step_handlers);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, step_handlers);
	return object;
}

/* Coming in, step 0: once direct page 92 is clear, appears below the floor at x C0 rising, zoomed to 60,
   with health A0, starts palette effects 18-1A and sets direct page 7C. */
void krusty_balloon_appear(uint16_t object, uint16_t palette_job)
{
	uint16_t animation_number = 0, box_number = 0, palette_effect_number = 0;
	uint8_t step = 0;
	uint16_t appear_y = 0;

	OBJECT(object)->entrance_pending = 1u;
	if (stage_scrolls_on != 0u)
		return;
	OBJECT(object)->flags = 0x98u;
	OBJECT(object)->shadow_player = 1u;
	animation_number = 0u;
	krusty_balloon_set_animation(object, animation_number);
	box_number = 0u;
	krusty_balloon_set_hit_box(object, box_number);
	OBJECT(object)->x = 0xC0u;
	appear_y = 0x100u + camera_y;
	OBJECT(object)->y = appear_y;
	OBJECT(object)->z = 0xFFC0u;
	OBJECT(object)->z_speed = 0x100;
	OBJECT(object)->zoom_x = 0x60u;
	OBJECT(object)->zoom_y = 0x60u;
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->krusty_balloon.balloon_timer = 0x80u;
	OBJECT(object)->shadow_player = 1u;
	OBJECT(object)->vitality = 0xA0u;
	OBJECT(object)->krusty_balloon.last_attack_health = 0xA0u;
	OBJECT(object)->entrance_pending = 0u;
	palette_request_kind = 2u;
	palette_effect_number = 0x18u;
	palette_job = vector_palette_request(palette_job, palette_effect_number);
	palette_request_kind = 2u;
	palette_effect_number = 0x19u;
	palette_job = vector_palette_request(palette_job, palette_effect_number);
	palette_request_kind = 2u;
	palette_effect_number = 0x1Au;
	vector_palette_request(palette_job, palette_effect_number);
	boss_arrived++;
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
}

/* Coming in, step 1: rises for 80 frames, then plays sound 7900 and starts drifting back (y speed FF80)
   for C0 frames. */
void krusty_balloon_rise(uint16_t object)
{
	uint16_t command = 0;
	uint8_t balloon_timer = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer != 1u)
		return;
	command = 0x7900u;
	vector_queue_sound_unless_attract(command);
	OBJECT(object)->y_speed = -0x80;
	OBJECT(object)->krusty_balloon.balloon_timer = 0xC0u;
	OBJECT(object)->attributes = 0u;
	OBJECT(object)->z_speed = 0;
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
}

/* Coming in, step 2: shrinks a step every 4 frames as it goes back; then comes forward (y speed 0080)
   for 50 frames. */
void krusty_balloon_drift_away(uint16_t object)
{
	uint8_t zoom = 0;
	uint8_t balloon_timer = 0, step = 0, zoom_x = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer == 1u)
	{
		OBJECT(object)->y_speed = 0x80;
		OBJECT(object)->krusty_balloon.balloon_timer = 0x50u;
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
		return;
	}
	if ((frame_count & 3u) == 0u)
	{
		zoom_x = OBJECT(object)->zoom_x;
		zoom = zoom_x - 1u;
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
	}
}

/* Coming in, step 3: grows a step every 4 frames as it comes forward; then stops at zoom 40. */
void krusty_balloon_drift_back(uint16_t object)
{
	uint8_t zoom = 0;
	uint8_t balloon_timer = 0, zoom_x = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer != 1u)
	{
		if ((frame_count & 3u) == 0u)
		{
			zoom_x = OBJECT(object)->zoom_x;
			zoom = zoom_x + 1u;
			OBJECT(object)->zoom_x = zoom;
			OBJECT(object)->zoom_y = zoom;
		}
		return;
	}
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	OBJECT(object)->y_speed = 0;
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
}

/* Coming in, step 4: falls with gravity; landing, plays sound 6500, shakes the screen and takes its
   body's hit box. */
void krusty_balloon_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box_number = 0, command = 0, ignored16 = 0;
	uint8_t step = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	command = 0x6500u;
	vector_queue_sound(command);
	screen_shake_on = 1u;
	OBJECT(object)->flags |= 0x48u;
	box_number = 0x100u;
	krusty_balloon_set_hit_box(object, box_number);
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
}

/* Coming in, step 5: bounces up off the floor (krusty_balloon_rebound), and from there chases. */
uint16_t krusty_balloon_bounce_up(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t squash_index = 0;
	uint16_t squash_handlers = 0;
	uint8_t squash_step = 0;

	for (;;)
	{
		OBJECT(object)->flags &= 0xBFu;
		squash_handlers = krusty_balloon_rebound_steps_ADDRESS;
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		squash_index = squash_step;
		carry = (int8_t)squash_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)squash_index << 1))
		{
		case 0:
			krusty_balloon_rebound(object);
			return object;
		case 2:
			break;
		case -76:
			return krusty_balloon_beaten(object);
		case -74:
			return krusty_balloon_knocked_up(object);
		case -72:
			return krusty_balloon_flinch(object);
		case -70:
			return krusty_balloon_come_in(object);
		case -68:
			krusty_balloon_chase(object);
			return object;
		case -66:
			return krusty_balloon_attack(object);
		case -64:
			return krusty_balloon_volley(object);
		case -62:
			return krusty_balloon_stomping(object);
		case -60:
			krusty_balloon_wait_for_target(object);
			return object;
		case -58:
			krusty_balloon_deflate(object);
			return object;
		case -56:
			krusty_balloon_beaten_wait(object);
			return object;
		case -54:
			krusty_balloon_wait_for_players(object);
			return object;
		case -52:
			krusty_balloon_fall_and_land(object);
			return object;
		case -50:
			krusty_balloon_fly_up(object);
			return object;
		case -48:
			krusty_balloon_knocked_up_stomp(object, squash_handlers);
			return object;
		case -46:
			krusty_balloon_appear(object, squash_handlers);
			return object;
		case -44:
			krusty_balloon_rise(object);
			return object;
		case -42:
			krusty_balloon_drift_away(object);
			return object;
		case -40:
			krusty_balloon_drift_back(object);
			return object;
		case -38:
			krusty_balloon_land(object);
			return object;
		case -36:
			continue;
		case -34:
			krusty_balloon_attack_start(object);
			return object;
		case -32:
			krusty_balloon_attack_hit(object);
			return object;
		case -30:
			krusty_balloon_attack_end(object, squash_handlers);
			return object;
		case -28:
			krusty_balloon_volley_take_position(object);
			return object;
		case -26:
			return krusty_balloon_volley_throw(object);
		case -24:
			krusty_balloon_volley_pause(object);
			return object;
		case -22:
			krusty_balloon_volley_wait(object);
			return object;
		case -20:
			krusty_balloon_volley_shrink(object, squash_handlers);
			return object;
		case -18:
			krusty_balloon_stomp_land(object);
			return object;
		case -16:
			return krusty_balloon_stomp_bounce(object);
		case -14:
			krusty_balloon_throw_right(squash_handlers, carry);
			return object;
		case -12:
			krusty_balloon_throw_spread(squash_handlers, carry);
			return object;
		case -10:
			krusty_balloon_throw_left(squash_handlers, carry);
			return object;
		case -8:
			krusty_balloon_wobble_widen(object);
			return object;
		case -6:
			krusty_balloon_wobble_narrow(object);
			return object;
		case -4:
			krusty_balloon_wobble_stretch(object);
			return object;
		case -2:
			krusty_balloon_wobble_restore(object);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, squash_handlers);
	return object;
}

/* Chasing (state 1): attacks when over its target, else keeps its target, faces it and flies toward it
   at the speed the game's rank gives. */
void krusty_balloon_chase(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t animation_number = 0, heading = 0, target = 0;
	uint8_t animation = 0, direction = 0;

	krusty_balloon_check_over_target(object, &target, &carry);
	if (carry)
		return;
	krusty_balloon_keep_target(object, target);
	animation = OBJECT(object)->animation;
	if (animation != 1u)
	{
		animation_number = 0x100u;
		krusty_balloon_set_animation(object, animation_number);
	}
	krusty_balloon_aim(object);
	direction = OBJECT(object)->krusty_balloon.direction;
	leftover_y = krusty_balloon_speeds_by_rank_ADDRESS;
	heading = ((uint32_t)direction << 8) | krusty_balloon_speeds_by_rank[rank >> 1];
	vector_set_speed_by_direction(object, heading);
}

/* Attacking (state 2): runs its step (field 28). */
uint16_t krusty_balloon_attack(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;

	for (;;)
	{
		step_handlers = krusty_balloon_attack_actions_ADDRESS;
		step = OBJECT(object)->krusty_balloon.step;
		step_index = step;
		carry = (int8_t)step_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
		{
		case 0:
			krusty_balloon_attack_start(object);
			return object;
		case 2:
			krusty_balloon_attack_hit(object);
			return object;
		case 4:
			krusty_balloon_attack_end(object, step_handlers);
			return object;
		case 6:
			krusty_balloon_volley_take_position(object);
			return object;
		case 8:
			return krusty_balloon_volley_throw(object);
		case 10:
			krusty_balloon_volley_pause(object);
			return object;
		case 12:
			krusty_balloon_volley_wait(object);
			return object;
		case 14:
			krusty_balloon_volley_shrink(object, step_handlers);
			return object;
		case 16:
			krusty_balloon_stomp_land(object);
			return object;
		case 18:
			return krusty_balloon_stomp_bounce(object);
		case 20:
			krusty_balloon_throw_right(step_handlers, carry);
			return object;
		case 22:
			krusty_balloon_throw_spread(step_handlers, carry);
			return object;
		case 24:
			krusty_balloon_throw_left(step_handlers, carry);
			return object;
		case 26:
			krusty_balloon_wobble_widen(object);
			return object;
		case 28:
			krusty_balloon_wobble_narrow(object);
			return object;
		case 30:
			krusty_balloon_wobble_stretch(object);
			return object;
		case 32:
			krusty_balloon_wobble_restore(object);
			return object;
		case 34:
			krusty_balloon_rebound(object);
			return object;
		case 36:
			break;
		case -42:
			return krusty_balloon_beaten(object);
		case -40:
			return krusty_balloon_knocked_up(object);
		case -38:
			return krusty_balloon_flinch(object);
		case -36:
			return krusty_balloon_come_in(object);
		case -34:
			krusty_balloon_chase(object);
			return object;
		case -32:
			continue;
		case -30:
			return krusty_balloon_volley(object);
		case -28:
			return krusty_balloon_stomping(object);
		case -26:
			krusty_balloon_wait_for_target(object);
			return object;
		case -24:
			krusty_balloon_deflate(object);
			return object;
		case -22:
			krusty_balloon_beaten_wait(object);
			return object;
		case -20:
			krusty_balloon_wait_for_players(object);
			return object;
		case -18:
			krusty_balloon_fall_and_land(object);
			return object;
		case -16:
			krusty_balloon_fly_up(object);
			return object;
		case -14:
			krusty_balloon_knocked_up_stomp(object, step_handlers);
			return object;
		case -12:
			krusty_balloon_appear(object, step_handlers);
			return object;
		case -10:
			krusty_balloon_rise(object);
			return object;
		case -8:
			krusty_balloon_drift_away(object);
			return object;
		case -6:
			krusty_balloon_drift_back(object);
			return object;
		case -4:
			krusty_balloon_land(object);
			return object;
		case -2:
			return krusty_balloon_bounce_up(object);
		}
		break;
	}
	krusty_balloon_rebound_end(object, step_handlers);
	return object;
}

/* Attacking, step 0: after its wait shows animation 2 and can not be hurt (flags bit 2). */
void krusty_balloon_attack_start(uint16_t object)
{
	uint16_t animation_number = 0;
	uint8_t balloon_timer = 0, balloon_timer_2 = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	if (balloon_timer != 0u)
	{
		balloon_timer_2 = OBJECT(object)->krusty_balloon.balloon_timer;
		OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer_2 - 1u;
		return;
	}
	animation_number = 0x200u;
	krusty_balloon_set_animation(object, animation_number);
	OBJECT(object)->flags |= 4u;
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
}

/* Attacking, step 1: at the animation's event gives its attack object (field 38, list 0 type 04, which
   has no handler) hit box 4; at its end takes back its body's hit box and waits 20 frames. */
void krusty_balloon_attack_hit(uint16_t object)
{
	uint8_t own_box = 0;
	uint16_t attack = 0, box_number = 0;
	uint16_t stack = 0;
	uint8_t animation_flags = 0, animation_flags_2 = 0, action = 0;
	uint16_t attack_object = 0;

	attack_object = OBJECT(object)->krusty_balloon.attack_object;
	attack = attack_object;
	OBJECT(attack)->flags &= 0xBFu;
	own_box = 0u;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) != 0u)
	{
		OBJECT(attack)->flags |= 0x40u;
		stack = object;
		object = attack;
		box_number = 0x400u;
		krusty_balloon_set_hit_box(object, box_number);
		object = stack;
		own_box = 1u;
	}
	box_number = (uint32_t)own_box << 8;
	krusty_balloon_set_hit_box(object, box_number);
	animation_flags_2 = OBJECT(object)->animation_flags;
	if ((animation_flags_2 & 1u) == 0u)
		return;
	box_number = 0u;
	krusty_balloon_set_hit_box(object, box_number);
	OBJECT(object)->action_step = 0x20u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action + 1u;
}

/* Attacking, step 2: after its wait removes the attack object and goes back to chasing. */
void krusty_balloon_attack_end(uint16_t object, uint16_t target)
{
	uint8_t balloon_timer = 0;
	uint16_t attack_object = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer != 1u)
		return;
	attack_object = OBJECT(object)->krusty_balloon.attack_object;
	OBJECT(attack_object)->flags = 0u;
	OBJECT(object)->krusty_balloon.attack_object = 0u;
	krusty_balloon_start_chase(object);
	krusty_balloon_keep_target(object, target);
}

/* Throwing (state 3): runs its step (field 28). */
uint16_t krusty_balloon_volley(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;

	for (;;)
	{
		step_handlers = krusty_balloon_volley_actions_ADDRESS;
		step = OBJECT(object)->krusty_balloon.step;
		step_index = step;
		carry = (int8_t)step_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
		{
		case 0:
			krusty_balloon_volley_take_position(object);
			return object;
		case 2:
			return krusty_balloon_volley_throw(object);
		case 4:
			krusty_balloon_volley_pause(object);
			return object;
		case 6:
			krusty_balloon_volley_wait(object);
			return object;
		case 8:
			krusty_balloon_volley_shrink(object, step_handlers);
			return object;
		case 10:
			krusty_balloon_stomp_land(object);
			return object;
		case 12:
			return krusty_balloon_stomp_bounce(object);
		case 14:
			krusty_balloon_throw_right(step_handlers, carry);
			return object;
		case 16:
			krusty_balloon_throw_spread(step_handlers, carry);
			return object;
		case 18:
			krusty_balloon_throw_left(step_handlers, carry);
			return object;
		case 20:
			krusty_balloon_wobble_widen(object);
			return object;
		case 22:
			krusty_balloon_wobble_narrow(object);
			return object;
		case 24:
			krusty_balloon_wobble_stretch(object);
			return object;
		case 26:
			krusty_balloon_wobble_restore(object);
			return object;
		case 28:
			krusty_balloon_rebound(object);
			return object;
		case 30:
			break;
		case -48:
			return krusty_balloon_beaten(object);
		case -46:
			return krusty_balloon_knocked_up(object);
		case -44:
			return krusty_balloon_flinch(object);
		case -42:
			return krusty_balloon_come_in(object);
		case -40:
			krusty_balloon_chase(object);
			return object;
		case -38:
			return krusty_balloon_attack(object);
		case -36:
			continue;
		case -34:
			return krusty_balloon_stomping(object);
		case -32:
			krusty_balloon_wait_for_target(object);
			return object;
		case -30:
			krusty_balloon_deflate(object);
			return object;
		case -28:
			krusty_balloon_beaten_wait(object);
			return object;
		case -26:
			krusty_balloon_wait_for_players(object);
			return object;
		case -24:
			krusty_balloon_fall_and_land(object);
			return object;
		case -22:
			krusty_balloon_fly_up(object);
			return object;
		case -20:
			krusty_balloon_knocked_up_stomp(object, step_handlers);
			return object;
		case -18:
			krusty_balloon_appear(object, step_handlers);
			return object;
		case -16:
			krusty_balloon_rise(object);
			return object;
		case -14:
			krusty_balloon_drift_away(object);
			return object;
		case -12:
			krusty_balloon_drift_back(object);
			return object;
		case -10:
			krusty_balloon_land(object);
			return object;
		case -8:
			return krusty_balloon_bounce_up(object);
		case -6:
			krusty_balloon_attack_start(object);
			return object;
		case -4:
			krusty_balloon_attack_hit(object);
			return object;
		case -2:
			krusty_balloon_attack_end(object, step_handlers);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, step_handlers);
	return object;
}

/* Throwing, step 0: flies to x E0, y 100 below the camera, 38 high, growing to zoom 60; there plays
   sound 7900 and readies its throws. */
void krusty_balloon_volley_take_position(uint16_t object)
{
	uint8_t zoom = 0;
	uint16_t command = 0;
	uint8_t zoom_x = 0, zoom_x_2 = 0, step = 0;
	uint16_t screen_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, volley_y = 0, own_y = 0, z = 0, x_speed = 0, y_speed = 0, z_speed = 0;

	OBJECT(object)->krusty_balloon.volleys = 0u;
	screen_x = OBJECT(object)->x;
	x_difference = screen_x - 0xE0u;
	signed_x_difference = x_difference;
	x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
	if ((int16_t)x_distance > 0x10)
		OBJECT(object)->x_speed = 0;
	volley_y = 0x100u + camera_y;
	own_y = OBJECT(object)->y;
	if ((int16_t)volley_y <= (int16_t)own_y)
		OBJECT(object)->y_speed = 0;
	z = OBJECT(object)->z;
	if ((int16_t)z >= 0x38)
		OBJECT(object)->z_speed = 0;
	zoom_x = OBJECT(object)->zoom_x;
	zoom = zoom_x;
	if (zoom <= 0x60u)
	{
		zoom++;
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
	}
	x_speed = OBJECT(object)->x_speed;
	if (x_speed == 0u)
	{
		y_speed = OBJECT(object)->y_speed;
		if (y_speed == 0u)
		{
			z_speed = OBJECT(object)->z_speed;
			if (z_speed == 0u)
			{
				zoom_x_2 = OBJECT(object)->zoom_x;
				if (zoom_x_2 > 0x60u)
				{
					command = 0x7900u;
					vector_queue_sound(command);
					OBJECT(object)->flags &= ~8u;
					OBJECT(object)->krusty_balloon.throws = 0u;
					OBJECT(object)->krusty_balloon.balloon_timer = 4u;
					OBJECT(object)->krusty_balloon.throw_side = 0u;
					step = OBJECT(object)->krusty_balloon.step;
					OBJECT(object)->krusty_balloon.step = step + 1u;
				}
			}
		}
	}
}

/* Throwing, step 1: every 4 to 11 frames throws a shot, right, at random and left in turn (field 32),
   with that throw's animation; after 12 throws, or when there is no room for a shot, goes on. */
uint16_t krusty_balloon_volley_throw(uint16_t balloon)
{
	uint32_t carry = 0;
	uint8_t next_throw_side = 0;
	uint16_t animation_number = 0, side = 0;
	uint8_t balloon_timer = 0, throws = 0, throws_2 = 0, action = 0, throw_side = 0, throw_side_2 = 0, throw_side_3 = 0;

	balloon_timer = OBJECT(balloon)->krusty_balloon.balloon_timer;
	OBJECT(balloon)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer != 1u)
		return balloon;
	throws = OBJECT(balloon)->krusty_balloon.throws;
	OBJECT(balloon)->krusty_balloon.throws = throws + 1u;
	throws_2 = OBJECT(balloon)->krusty_balloon.throws;
	if (throws_2 == 0xCu)
	{
		animation_number = 0u;
		krusty_balloon_set_animation(balloon, animation_number);
		OBJECT(balloon)->action_step = 1u;
		action = OBJECT(balloon)->action;
		OBJECT(balloon)->action = action + 1u;
		return balloon;
	}
	throw_side = OBJECT(balloon)->krusty_balloon.throw_side;
	side = (uint32_t)throw_side << 8;
	krusty_balloon_throw(side, &balloon, &carry);
	if (carry)
	{
		animation_number = 0u;
		krusty_balloon_set_animation(balloon, animation_number);
		OBJECT(balloon)->action_step = 1u;
		action = OBJECT(balloon)->action;
		OBJECT(balloon)->action = action + 1u;
		return balloon;
	}
	throw_side_2 = OBJECT(balloon)->krusty_balloon.throw_side;
	animation_number = (uint32_t)(uint8_t)(4u + throw_side_2) << 8;
	krusty_balloon_set_animation(balloon, animation_number);
	throw_side_3 = OBJECT(balloon)->krusty_balloon.throw_side;
	next_throw_side = throw_side_3 + 1u;
	if (next_throw_side == 3u)
		next_throw_side = 0u;
	OBJECT(balloon)->krusty_balloon.throw_side = next_throw_side;
	OBJECT(balloon)->krusty_balloon.balloon_timer = (random_number & 7u) + 4u;
	return balloon;
}

/* Throwing, step 2: after a frame waits 40 more and counts the volley in field 36. */
void krusty_balloon_volley_pause(uint16_t object)
{
	uint8_t balloon_timer = 0, volleys = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer == 1u)
	{
		OBJECT(object)->krusty_balloon.balloon_timer = 0x40u;
		volleys = OBJECT(object)->krusty_balloon.volleys;
		OBJECT(object)->krusty_balloon.volleys = volleys + 1u;
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
	}
}

/* Throwing, step 3: waits. */
void krusty_balloon_volley_wait(uint16_t object)
{
	uint8_t balloon_timer = 0, step = 0;

	balloon_timer = OBJECT(object)->krusty_balloon.balloon_timer;
	OBJECT(object)->krusty_balloon.balloon_timer = balloon_timer - 1u;
	if (balloon_timer == 1u)
	{
		step = OBJECT(object)->krusty_balloon.step;
		OBJECT(object)->krusty_balloon.step = step + 1u;
	}
}

/* Throwing, step 4: shrinks a step a frame back to zoom 40, then drops onto its target. */
void krusty_balloon_volley_shrink(uint16_t object, uint16_t object_2)
{
	uint8_t zoom = 0;
	uint8_t zoom_x = 0;
	uint16_t stomp_y = 0;

	zoom_x = OBJECT(object)->zoom_x;
	zoom = zoom_x - 1u;
	if (zoom > 0x40u)
	{
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		return;
	}
	stomp_y = 0xFFu - camera_y;
	OBJECT(object)->y = stomp_y;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	krusty_balloon_stomp(object, object_2);
}

/* Stomping (state 4): runs its step (field 28). */
uint16_t krusty_balloon_stomping(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t step_index = 0;
	uint16_t step_handlers = 0;
	uint8_t step = 0;

	for (;;)
	{
		step_handlers = krusty_balloon_stomping_actions_ADDRESS;
		step = OBJECT(object)->krusty_balloon.step;
		step_index = step;
		carry = (int8_t)step_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)step_index << 1))
		{
		case 0:
			krusty_balloon_stomp_land(object);
			return object;
		case 2:
			return krusty_balloon_stomp_bounce(object);
		case 4:
			krusty_balloon_throw_right(step_handlers, carry);
			return object;
		case 6:
			krusty_balloon_throw_spread(step_handlers, carry);
			return object;
		case 8:
			krusty_balloon_throw_left(step_handlers, carry);
			return object;
		case 10:
			krusty_balloon_wobble_widen(object);
			return object;
		case 12:
			krusty_balloon_wobble_narrow(object);
			return object;
		case 14:
			krusty_balloon_wobble_stretch(object);
			return object;
		case 16:
			krusty_balloon_wobble_restore(object);
			return object;
		case 18:
			krusty_balloon_rebound(object);
			return object;
		case 20:
			break;
		case -58:
			return krusty_balloon_beaten(object);
		case -56:
			return krusty_balloon_knocked_up(object);
		case -54:
			return krusty_balloon_flinch(object);
		case -52:
			return krusty_balloon_come_in(object);
		case -50:
			krusty_balloon_chase(object);
			return object;
		case -48:
			return krusty_balloon_attack(object);
		case -46:
			return krusty_balloon_volley(object);
		case -44:
			continue;
		case -42:
			krusty_balloon_wait_for_target(object);
			return object;
		case -40:
			krusty_balloon_deflate(object);
			return object;
		case -38:
			krusty_balloon_beaten_wait(object);
			return object;
		case -36:
			krusty_balloon_wait_for_players(object);
			return object;
		case -34:
			krusty_balloon_fall_and_land(object);
			return object;
		case -32:
			krusty_balloon_fly_up(object);
			return object;
		case -30:
			krusty_balloon_knocked_up_stomp(object, step_handlers);
			return object;
		case -28:
			krusty_balloon_appear(object, step_handlers);
			return object;
		case -26:
			krusty_balloon_rise(object);
			return object;
		case -24:
			krusty_balloon_drift_away(object);
			return object;
		case -22:
			krusty_balloon_drift_back(object);
			return object;
		case -20:
			krusty_balloon_land(object);
			return object;
		case -18:
			return krusty_balloon_bounce_up(object);
		case -16:
			krusty_balloon_attack_start(object);
			return object;
		case -14:
			krusty_balloon_attack_hit(object);
			return object;
		case -12:
			krusty_balloon_attack_end(object, step_handlers);
			return object;
		case -10:
			krusty_balloon_volley_take_position(object);
			return object;
		case -8:
			return krusty_balloon_volley_throw(object);
		case -6:
			krusty_balloon_volley_pause(object);
			return object;
		case -4:
			krusty_balloon_volley_wait(object);
			return object;
		case -2:
			krusty_balloon_volley_shrink(object, step_handlers);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, step_handlers);
	return object;
}

/* Stomping, step 0: falls with gravity, not above y 90; landing, plays sound 6500, shakes the screen and
   takes its body's hit box. */
void krusty_balloon_stomp_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t box_number = 0, command = 0, ignored16 = 0;
	uint8_t step = 0;
	uint16_t own_y = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
	{
		own_y = OBJECT(object)->y;
		if ((int16_t)own_y < 0x90)
			OBJECT(object)->y = 0x90u;
		return;
	}
	command = 0x6500u;
	vector_queue_sound(command);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	screen_shake_on = 1u;
	OBJECT(object)->flags |= 0x48u;
	box_number = 0x100u;
	krusty_balloon_set_hit_box(object, box_number);
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.step = step + 1u;
	own_y = OBJECT(object)->y;
	if ((int16_t)own_y < 0x90)
		OBJECT(object)->y = 0x90u;
}

/* Stomping, step 1: bounces up off the floor (krusty_balloon_rebound), and from there chases. */
uint16_t krusty_balloon_stomp_bounce(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t squash_index = 0;
	uint16_t squash_handlers = 0;
	uint8_t squash_step = 0;

	for (;;)
	{
		squash_handlers = krusty_balloon_rebound_steps_ADDRESS;
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		squash_index = squash_step;
		carry = (int8_t)squash_index < 0;
		switch ((int8_t)(uint8_t)((uint32_t)squash_index << 1))
		{
		case 0:
			krusty_balloon_rebound(object);
			return object;
		case 2:
			break;
		case -76:
			return krusty_balloon_beaten(object);
		case -74:
			return krusty_balloon_knocked_up(object);
		case -72:
			return krusty_balloon_flinch(object);
		case -70:
			return krusty_balloon_come_in(object);
		case -68:
			krusty_balloon_chase(object);
			return object;
		case -66:
			return krusty_balloon_attack(object);
		case -64:
			return krusty_balloon_volley(object);
		case -62:
			return krusty_balloon_stomping(object);
		case -60:
			krusty_balloon_wait_for_target(object);
			return object;
		case -58:
			krusty_balloon_deflate(object);
			return object;
		case -56:
			krusty_balloon_beaten_wait(object);
			return object;
		case -54:
			krusty_balloon_wait_for_players(object);
			return object;
		case -52:
			krusty_balloon_fall_and_land(object);
			return object;
		case -50:
			krusty_balloon_fly_up(object);
			return object;
		case -48:
			krusty_balloon_knocked_up_stomp(object, squash_handlers);
			return object;
		case -46:
			krusty_balloon_appear(object, squash_handlers);
			return object;
		case -44:
			krusty_balloon_rise(object);
			return object;
		case -42:
			krusty_balloon_drift_away(object);
			return object;
		case -40:
			krusty_balloon_drift_back(object);
			return object;
		case -38:
			krusty_balloon_land(object);
			return object;
		case -36:
			return krusty_balloon_bounce_up(object);
		case -34:
			krusty_balloon_attack_start(object);
			return object;
		case -32:
			krusty_balloon_attack_hit(object);
			return object;
		case -30:
			krusty_balloon_attack_end(object, squash_handlers);
			return object;
		case -28:
			krusty_balloon_volley_take_position(object);
			return object;
		case -26:
			return krusty_balloon_volley_throw(object);
		case -24:
			krusty_balloon_volley_pause(object);
			return object;
		case -22:
			krusty_balloon_volley_wait(object);
			return object;
		case -20:
			krusty_balloon_volley_shrink(object, squash_handlers);
			return object;
		case -18:
			krusty_balloon_stomp_land(object);
			return object;
		case -16:
			continue;
		case -14:
			krusty_balloon_throw_right(squash_handlers, carry);
			return object;
		case -12:
			krusty_balloon_throw_spread(squash_handlers, carry);
			return object;
		case -10:
			krusty_balloon_throw_left(squash_handlers, carry);
			return object;
		case -8:
			krusty_balloon_wobble_widen(object);
			return object;
		case -6:
			krusty_balloon_wobble_narrow(object);
			return object;
		case -4:
			krusty_balloon_wobble_stretch(object);
			return object;
		case -2:
			krusty_balloon_wobble_restore(object);
			return object;
		}
		break;
	}
	krusty_balloon_rebound_end(object, squash_handlers);
	return object;
}

/* Without a target (state 5): while its target is in play and not down, waits; else goes back to the
   stomp it was in (fields 33-34) or to chasing. */
void krusty_balloon_wait_for_target(uint16_t object)
{
	uint8_t state = 0;
	uint16_t target_player = 0;
	uint8_t state_2 = 0, saved_state = 0, saved_step = 0;
	uint16_t target = 0;

	target = OBJECT(object)->krusty_balloon.target;
	target_player = target;
	if (OBJECT(target_player)->flags != 0u)
	{
		state_2 = OBJECT(target_player)->state;
		if ((int8_t)state_2 < 0)
			return;
	}
	saved_state = OBJECT(object)->krusty_balloon.saved_state;
	state = saved_state;
	if (state != 4u)
	{
		krusty_balloon_start_chase(object);
		krusty_balloon_keep_target(object, target_player);
		return;
	}
	OBJECT(object)->state = state;
	saved_step = OBJECT(object)->krusty_balloon.saved_step;
	OBJECT(object)->krusty_balloon.step = saved_step;
}

/* Hit by a player's strike (flags bit 5 and a hit kind in field 1E): removes its attack object and
   reacts (krusty_balloon_hit). */
void krusty_balloon_check_hit(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t hit = 0;
	uint16_t attack_object = 0, attack_object_2 = 0;

	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		hit = OBJECT(object)->hit;
		negative = hit >> 7;
		if (hit != 0u && negative == 0u)
		{
			attack_object = OBJECT(object)->krusty_balloon.attack_object;
			if (attack_object != 0u)
			{
				attack_object_2 = OBJECT(object)->krusty_balloon.attack_object;
				OBJECT(attack_object_2)->flags = 0u;
				OBJECT(object)->krusty_balloon.attack_object = 0u;
			}
			krusty_balloon_hit(object);
		}
	}
}

/* Starts an attack when its target is just in front of it (up to 10 in y) and 10 to 40 away in x;
   without a target in play waits for one. */
void krusty_balloon_check_over_target(uint16_t object, uint16_t *p_other_object, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t distance_high = 0, distance_low = 0, slot_list = 0;
	uint16_t animation_number = 0, other_object = 0;
	uint8_t target_state = 0, vitality = 0, last_attack_health = 0, vitality_2 = 0;
	uint16_t target = 0, own_y = 0, target_y = 0, y_difference = 0, own_x = 0, target_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, attack_x = 0, attack_y = 0, z = 0;

	target = OBJECT(object)->krusty_balloon.target;
	other_object = target;
	if (OBJECT(other_object)->flags == 0u)
		carry = krusty_balloon_lose_target(object);
	else
	{
		target_state = OBJECT(other_object)->state;
		if ((int8_t)target_state < 0)
			carry = krusty_balloon_lose_target(object);
		else
		{
			own_y = OBJECT(object)->y;
			target_y = OBJECT(other_object)->y;
			y_difference = own_y - target_y;
			distance_high = (uint8_t)(y_difference >> 8);
			distance_low = (uint8_t)y_difference;
			if ((int16_t)y_difference < 0 || (int16_t)(((uint32_t)distance_high << 8) | distance_low) > 0x10)
				carry = 0u;
			else
			{
				own_x = OBJECT(object)->x;
				target_x = OBJECT(other_object)->x;
				x_difference = own_x - target_x;
				signed_x_difference = x_difference;
				x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
				distance_high = (uint8_t)(x_distance >> 8);
				distance_low = (uint8_t)x_distance;
				if ((int16_t)(((uint32_t)distance_high << 8) | distance_low) > 0x40 || (int16_t)(((uint32_t)distance_high << 8) | distance_low) < 0x10)
					carry = 0u;
				else
				{
					OBJECT(object)->x_speed = 0;
					OBJECT(object)->y_speed = 0;
					slot_list = 0u;
					vector_find_free_slot(slot_list, &other_object, &carry);
					if (carry)
					{
						OBJECT(other_object)->type = 4;
						attack_x = OBJECT(object)->x;
						OBJECT(other_object)->x = attack_x;
						attack_y = OBJECT(object)->y;
						OBJECT(other_object)->y = attack_y;
						z = OBJECT(object)->z;
						OBJECT(other_object)->z = z;
						OBJECT(object)->krusty_balloon.attack_object = other_object;
						OBJECT(object)->krusty_balloon.balloon_timer = 0u;
						OBJECT(object)->state = 2u;
						OBJECT(object)->krusty_balloon.step = 0u;
						OBJECT(object)->krusty_balloon.squash_step = 0u;
						animation_number = 0u;
						krusty_balloon_set_animation(object, animation_number);
						other_object = krusty_balloon_quick_attack_chances_by_players_ADDRESS;
						if (random_number < krusty_balloon_quick_attack_chances_by_players[(int8_t)((uint8_t)(player_count - 1u))])
						{
							vitality = OBJECT(object)->vitality;
							OBJECT(object)->krusty_balloon.last_attack_health = vitality;
							carry = 1u;
						}
						else
						{
							last_attack_health = OBJECT(object)->krusty_balloon.last_attack_health;
							vitality_2 = OBJECT(object)->vitality;
							if ((uint8_t)(last_attack_health - vitality_2) >= 0xCu)
							{
								vitality = OBJECT(object)->vitality;
								OBJECT(object)->krusty_balloon.last_attack_health = vitality;
								carry = 1u;
							}
							else
							{
								OBJECT(object)->krusty_balloon.balloon_timer = 0x20u;
								carry = 1u;
							}
						}
					}
				}
			}
		}
	}
	*p_other_object = other_object;
	*p_carry = carry;
}

/* Starts animation A of krusty_balloon_animations (its kind and animation) on X's object. */
void krusty_balloon_set_animation(uint16_t object, uint16_t animation_number)
{
	uint16_t kind_with_animation = 0;
	uint32_t kind_halfword = 0;

	kind_with_animation = krusty_balloon_animations[(int8_t)((uint8_t)((uint32_t)(animation_number >> 8) << 1)) / 2];
	kind_halfword = ((uint32_t)(kind_with_animation >> 8) << 8) | (uint8_t)(kind_with_animation | 0x80u);
	OBJECT(object)->kind = (uint8_t)(kind_halfword >> 8u);
	OBJECT(object)->animation = (uint8_t)kind_halfword;
}

/* Gives X's object hit box A of krusty_balloon_hit_boxes. */
void krusty_balloon_set_hit_box(uint16_t object, uint16_t box_number)
{
	uint16_t box_record = 0, damage_attack = 0, box_cursor = 0, width_depth = 0, box_cursor_2 = 0, height_dx = 0, dy_dz = 0;

	box_record = krusty_balloon_hit_boxes_ADDRESS + (uint8_t)((((uint32_t)(box_number >> 8) << 1) << 1) << 1);
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
	dy_dz = HIT_BOX(box_cursor_2 - 0x4u)->dy_dz;
	OBJECT(object)->box_dy = (uint8_t)(dy_dz >> 8u);
	OBJECT(object)->box_dz = (uint8_t)dy_dz;
}

/* Takes the direction toward its target into fields 2D and 2E. */
void krusty_balloon_aim(uint16_t object)
{
	uint8_t side_offset = 0;
	uint16_t aim_direction = 0, direction = 0, target_player = 0;
	uint16_t target = 0, own_x = 0, target_x = 0;

	target = OBJECT(object)->krusty_balloon.target;
	target_player = target;
	own_x = OBJECT(object)->x;
	target_x = OBJECT(target_player)->x;
	if ((int16_t)target_x < (int16_t)own_x)
		side_offset = 0x40u;
	else
		side_offset = 0xC0u;
	aim_direction = side_offset;
	aim_direction = vector_direction_to_offset(object, target_player, aim_direction);
	OBJECT(object)->krusty_balloon.direction = ((aim_direction & ~0xFFu) | side_offset) >> 8;
	direction = vector_direction_to(object, target_player);
	OBJECT(object)->target_dy = (OBJECT(object)->target_dy & 0xFFu) | (((direction | side_offset) >> 8 & 0xFFu) << 8u);
}

/* Keeps its target (field 2B) for 40 frames, then takes the one the search gives; without one in play
   waits for one. */
void krusty_balloon_keep_target(uint16_t object, uint16_t target)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, target_player = 0;
	uint8_t state = 0, target_time = 0, target_time_2 = 0;
	uint16_t target_2 = 0;

	find_nearest_player(object, &target, &ignored16, &carry);
	if (carry == 0u)
	{
		krusty_balloon_lose_target(object);
		return;
	}
	target_2 = OBJECT(object)->krusty_balloon.target;
	target_player = target_2;
	if (OBJECT(target_player)->flags != 0u)
	{
		state = OBJECT(target_player)->state;
		if ((int8_t)state >= 0)
		{
			target_time = OBJECT(object)->krusty_balloon.target_time;
			if (target_time != 0u)
			{
				target_time_2 = OBJECT(object)->krusty_balloon.target_time;
				OBJECT(object)->krusty_balloon.target_time = target_time_2 - 1u;
				leftover_y = target_player;
				return;
			}
		}
	}
	OBJECT(object)->krusty_balloon.target_time = 0x40u;
	OBJECT(object)->krusty_balloon.target = target;
	leftover_y = target_player;
}

/* Throws a shot (list 1 type 31, or list 2 type 10 when list 1 is full) from its place, rising, with
   animation 8 and hit box 2, sideways by A (0 right, 1 at random, 2 left), and plays sound 2600; carry
   set when there was no room. */
void krusty_balloon_throw(uint16_t side, uint16_t *p_balloon, uint32_t *p_carry)
{
	uint16_t balloon = (uint16_t)*p_balloon;
	uint32_t carry = *p_carry;
	uint8_t side_index = 0, type = 0;
	uint16_t box_number = 0, command = 0, object = 0, object_2 = 0, shot = 0, slot_list = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0, stack_5 = 0;
	uint16_t balloon_x = 0, balloon_y = 0, z = 0;

	stack = side >> 8;
	slot_list = 1u;
	vector_find_free_slot(slot_list, &shot, &carry);
	if (carry)
		type = 0x31u;
	else
	{
		slot_list = 2u;
		vector_find_free_slot(slot_list, &shot, &carry);
		if (carry == 0u)
		{
			carry = 1u;
			*p_carry = carry;
			return;
		}
		type = 0x10u;
	}
	OBJECT(shot)->type = type;
	OBJECT(shot)->flags = 0xC8u;
	balloon_x = OBJECT(balloon)->x;
	OBJECT(shot)->x = balloon_x;
	balloon_y = OBJECT(balloon)->y;
	OBJECT(shot)->y = balloon_y;
	z = OBJECT(balloon)->z;
	OBJECT(shot)->z = z;
	OBJECT(shot)->action_step = (uint8_t)(balloon >> 8u);
	OBJECT(shot)->behaviour = (OBJECT(shot)->behaviour & 0xFFu) | ((balloon & 0xFFu) << 8u);
	OBJECT(shot)->shadow_player = 2u;
	stack_3 = shot;
	stack_5 = balloon;
	object_2 = shot;
	slot_list |= 0x800u;
	krusty_balloon_set_animation(object_2, slot_list);
	box_number = (slot_list & 0xFFu) | 0x200u;
	krusty_balloon_set_hit_box(object_2, box_number);
	balloon = stack_5;
	object = stack_3;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0x280;
	leftover_y = krusty_balloon_throw_directions_ADDRESS;
	side_index = stack;
	carry = (int8_t)side_index < 0;
	switch ((int8_t)(uint8_t)((uint32_t)side_index << 1))
	{
	case 0:
		krusty_balloon_throw_right(object, carry);
		break;
	case 2:
		krusty_balloon_throw_spread(object, carry);
		break;
	case 4:
		krusty_balloon_throw_left(object, carry);
		break;
	case 6:
		krusty_balloon_wobble_widen(balloon);
		break;
	case 8:
		krusty_balloon_wobble_narrow(balloon);
		break;
	case 10:
		krusty_balloon_wobble_stretch(balloon);
		break;
	case 12:
		krusty_balloon_wobble_restore(balloon);
		break;
	case 14:
		krusty_balloon_rebound(balloon);
		break;
	case 16:
		krusty_balloon_rebound_end(balloon, object);
		break;
	case -62:
		balloon = krusty_balloon_beaten(balloon);
		break;
	case -60:
		balloon = krusty_balloon_knocked_up(balloon);
		break;
	case -58:
		balloon = krusty_balloon_flinch(balloon);
		break;
	case -56:
		balloon = krusty_balloon_come_in(balloon);
		break;
	case -54:
		krusty_balloon_chase(balloon);
		break;
	case -52:
		balloon = krusty_balloon_attack(balloon);
		break;
	case -50:
		balloon = krusty_balloon_volley(balloon);
		break;
	case -48:
		balloon = krusty_balloon_stomping(balloon);
		break;
	case -46:
		krusty_balloon_wait_for_target(balloon);
		break;
	case -44:
		krusty_balloon_deflate(balloon);
		break;
	case -42:
		krusty_balloon_beaten_wait(balloon);
		break;
	case -40:
		krusty_balloon_wait_for_players(balloon);
		break;
	case -38:
		krusty_balloon_fall_and_land(balloon);
		break;
	case -36:
		krusty_balloon_fly_up(balloon);
		break;
	case -34:
		krusty_balloon_knocked_up_stomp(balloon, object);
		break;
	case -32:
		krusty_balloon_appear(balloon, object);
		break;
	case -30:
		krusty_balloon_rise(balloon);
		break;
	case -28:
		krusty_balloon_drift_away(balloon);
		break;
	case -26:
		krusty_balloon_drift_back(balloon);
		break;
	case -24:
		krusty_balloon_land(balloon);
		break;
	case -22:
		balloon = krusty_balloon_bounce_up(balloon);
		break;
	case -20:
		krusty_balloon_attack_start(balloon);
		break;
	case -18:
		krusty_balloon_attack_hit(balloon);
		break;
	case -16:
		krusty_balloon_attack_end(balloon, object);
		break;
	case -14:
		krusty_balloon_volley_take_position(balloon);
		break;
	case -12:
		balloon = krusty_balloon_volley_throw(balloon);
		break;
	case -10:
		krusty_balloon_volley_pause(balloon);
		break;
	case -8:
		krusty_balloon_volley_wait(balloon);
		break;
	case -6:
		krusty_balloon_volley_shrink(balloon, object);
		break;
	case -4:
		krusty_balloon_stomp_land(balloon);
		break;
	case -2:
		balloon = krusty_balloon_stomp_bounce(balloon);
		break;
	}
	command = 0x2600u;
	vector_queue_sound_unless_attract(command);
	carry = 0u;
	*p_balloon = balloon;
	*p_carry = carry;
}

/* The shot's x speed 0280 plus a random part and its y speed (krusty_balloon_throw_spread). */
void krusty_balloon_throw_right(uint16_t object, uint32_t carry)
{
	OBJECT(object)->x_speed = 0x280;
	krusty_balloon_throw_spread(object, carry);
}

/* The shot's x speed -0280 plus a random part and its y speed (krusty_balloon_throw_spread). */
void krusty_balloon_throw_left(uint16_t object, uint32_t carry)
{
	OBJECT(object)->x_speed = -0x280;
	krusty_balloon_throw_spread(object, carry);
}

/* Adds a random part to the shot's x speed and gives it a random y speed toward the back (field 14, from
   krusty_balloon_throw_z_speeds). */
void krusty_balloon_throw_spread(uint16_t object, uint32_t carry)
{
	uint16_t signed_random = 0, x_speed = 0, spread_x_speed = 0, spread_y_speed = 0;

	signed_random = (int8_t)random_number;
	x_speed = OBJECT(object)->x_speed;
	spread_x_speed = (((uint32_t)(uint8_t)((uint32_t)(signed_random >> 8) << 1) << 8) | (uint8_t)(((uint32_t)(uint8_t)signed_random << 1) | carry)) + x_speed;
	OBJECT(object)->x_speed = spread_x_speed;
	spread_y_speed = 0u - (((uint32_t)(krusty_balloon_throw_z_speeds[random_number & 7u] >> 8) << 8) | random_number);
	OBJECT(object)->y_speed = spread_y_speed;
	leftover_y = krusty_balloon_throw_z_speeds_ADDRESS;
}

/* Runs its squash step (field 35); carry set once the four steps are done. */
void krusty_balloon_wobble(uint16_t *p_balloon, uint32_t *p_carry)
{
	uint16_t balloon = (uint16_t)*p_balloon;
	uint32_t carry = *p_carry;
	uint8_t squash_index = 0;
	uint16_t squash_handlers = 0;
	uint8_t squash_step = 0, wobble_step = 0;

	squash_handlers = krusty_balloon_wobble_steps_ADDRESS;
	squash_step = OBJECT(balloon)->krusty_balloon.squash_step;
	squash_index = squash_step;
	carry = (int8_t)squash_index < 0;
	switch ((int8_t)(uint8_t)((uint32_t)squash_index << 1))
	{
	case 0:
		krusty_balloon_wobble_widen(balloon);
		break;
	case 2:
		krusty_balloon_wobble_narrow(balloon);
		break;
	case 4:
		krusty_balloon_wobble_stretch(balloon);
		break;
	case 6:
		krusty_balloon_wobble_restore(balloon);
		break;
	case 8:
		krusty_balloon_rebound(balloon);
		break;
	case 10:
		krusty_balloon_rebound_end(balloon, squash_handlers);
		break;
	case -68:
		balloon = krusty_balloon_beaten(balloon);
		break;
	case -66:
		balloon = krusty_balloon_knocked_up(balloon);
		break;
	case -64:
		balloon = krusty_balloon_flinch(balloon);
		break;
	case -62:
		balloon = krusty_balloon_come_in(balloon);
		break;
	case -60:
		krusty_balloon_chase(balloon);
		break;
	case -58:
		balloon = krusty_balloon_attack(balloon);
		break;
	case -56:
		balloon = krusty_balloon_volley(balloon);
		break;
	case -54:
		balloon = krusty_balloon_stomping(balloon);
		break;
	case -52:
		krusty_balloon_wait_for_target(balloon);
		break;
	case -50:
		krusty_balloon_deflate(balloon);
		break;
	case -48:
		krusty_balloon_beaten_wait(balloon);
		break;
	case -46:
		krusty_balloon_wait_for_players(balloon);
		break;
	case -44:
		krusty_balloon_fall_and_land(balloon);
		break;
	case -42:
		krusty_balloon_fly_up(balloon);
		break;
	case -40:
		krusty_balloon_knocked_up_stomp(balloon, squash_handlers);
		break;
	case -38:
		krusty_balloon_appear(balloon, squash_handlers);
		break;
	case -36:
		krusty_balloon_rise(balloon);
		break;
	case -34:
		krusty_balloon_drift_away(balloon);
		break;
	case -32:
		krusty_balloon_drift_back(balloon);
		break;
	case -30:
		krusty_balloon_land(balloon);
		break;
	case -28:
		balloon = krusty_balloon_bounce_up(balloon);
		break;
	case -26:
		krusty_balloon_attack_start(balloon);
		break;
	case -24:
		krusty_balloon_attack_hit(balloon);
		break;
	case -22:
		krusty_balloon_attack_end(balloon, squash_handlers);
		break;
	case -20:
		krusty_balloon_volley_take_position(balloon);
		break;
	case -18:
		balloon = krusty_balloon_volley_throw(balloon);
		break;
	case -16:
		krusty_balloon_volley_pause(balloon);
		break;
	case -14:
		krusty_balloon_volley_wait(balloon);
		break;
	case -12:
		krusty_balloon_volley_shrink(balloon, squash_handlers);
		break;
	case -10:
		krusty_balloon_stomp_land(balloon);
		break;
	case -8:
		balloon = krusty_balloon_stomp_bounce(balloon);
		break;
	case -6:
		krusty_balloon_throw_right(squash_handlers, carry);
		break;
	case -4:
		krusty_balloon_throw_spread(squash_handlers, carry);
		break;
	case -2:
		krusty_balloon_throw_left(squash_handlers, carry);
		break;
	}
	wobble_step = OBJECT(balloon)->krusty_balloon.squash_step;
	if (wobble_step != 4u)
		carry = 0u;
	else
	{
		OBJECT(balloon)->krusty_balloon.squash_step = 0u;
		carry = 1u;
	}
	*p_balloon = balloon;
	*p_carry = carry;
}

/* Squash step 0: widens (field 0A) by 4 a frame up to 60. */
void krusty_balloon_wobble_widen(uint16_t object)
{
	uint8_t zoom_x = 0, squash_step = 0, zoom_x_2 = 0;

	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x >= 0x60u)
	{
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		OBJECT(object)->krusty_balloon.squash_step = squash_step + 1u;
		return;
	}
	zoom_x_2 = OBJECT(object)->zoom_x;
	OBJECT(object)->zoom_x = zoom_x_2 + 4u;
}

/* Squash step 1: narrows back by 4 a frame to 40. */
void krusty_balloon_wobble_narrow(uint16_t object)
{
	uint8_t zoom_x = 0, squash_step = 0, zoom_x_2 = 0;

	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x <= 0x40u)
	{
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		OBJECT(object)->krusty_balloon.squash_step = squash_step + 1u;
		return;
	}
	zoom_x_2 = OBJECT(object)->zoom_x;
	OBJECT(object)->zoom_x = zoom_x_2 - 4u;
}

/* Squash step 2: narrows to 20 while it grows taller (field 0B). */
void krusty_balloon_wobble_stretch(uint16_t object)
{
	uint8_t zoom_x = 0, squash_step = 0, zoom_x_2 = 0, zoom_y = 0;

	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x <= 0x20u)
	{
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		OBJECT(object)->krusty_balloon.squash_step = squash_step + 1u;
		return;
	}
	zoom_x_2 = OBJECT(object)->zoom_x;
	OBJECT(object)->zoom_x = zoom_x_2 - 4u;
	zoom_y = OBJECT(object)->zoom_y;
	OBJECT(object)->zoom_y = zoom_y + 4u;
}

/* Squash step 3: back to zoom 40 both ways. */
void krusty_balloon_wobble_restore(uint16_t object)
{
	uint8_t zoom_x = 0, squash_step = 0, zoom_x_2 = 0, zoom_y = 0;

	zoom_x = OBJECT(object)->zoom_x;
	if (zoom_x >= 0x40u)
	{
		OBJECT(object)->zoom_x = 0x40u;
		OBJECT(object)->zoom_y = 0x40u;
		squash_step = OBJECT(object)->krusty_balloon.squash_step;
		OBJECT(object)->krusty_balloon.squash_step = squash_step + 1u;
		return;
	}
	zoom_x_2 = OBJECT(object)->zoom_x;
	OBJECT(object)->zoom_x = zoom_x_2 + 4u;
	zoom_y = OBJECT(object)->zoom_y;
	OBJECT(object)->zoom_y = zoom_y - 4u;
}

/* Rebound step 0: can be hurt again, takes its body's hit box and rises. */
void krusty_balloon_rebound(uint16_t object)
{
	uint16_t box_number = 0;
	uint8_t squash_step = 0;

	OBJECT(object)->flags &= 0xBBu;
	box_number = 0u;
	krusty_balloon_set_hit_box(object, box_number);
	OBJECT(object)->z_speed = 0x80;
	squash_step = OBJECT(object)->krusty_balloon.squash_step;
	OBJECT(object)->krusty_balloon.squash_step = squash_step + 1u;
}

/* Rebound step 1: at 20 high stops, keeps its target and goes back to chasing. */
void krusty_balloon_rebound_end(uint16_t object, uint16_t target)
{
	uint16_t z = 0;

	z = OBJECT(object)->z;
	if ((int16_t)z < 0x20)
		return;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->z = 0x20u;
	OBJECT(object)->flags |= 0x40u;
	krusty_balloon_keep_target(object, target);
	krusty_balloon_start_chase(object);
}

/* Back to chasing (state 1) with animation 1 and its body's hit box. */
void krusty_balloon_start_chase(uint16_t object)
{
	uint16_t animation_number = 0, box_number = 0;

	animation_number = 0x100u;
	krusty_balloon_set_animation(object, animation_number);
	box_number = 0u;
	krusty_balloon_set_hit_box(object, box_number);
	OBJECT(object)->flags = (OBJECT(object)->flags | 0x40u) & ~4u;
	OBJECT(object)->state = 1u;
	OBJECT(object)->krusty_balloon.step = 0u;
	OBJECT(object)->krusty_balloon.squash_step = 0u;
	OBJECT(object)->krusty_balloon.balloon_timer = 0u;
}

/* Its reaction to a strike: tells the striker (fields 2A, 49), plays sound 6501 and animation 7; at low
   health it is knocked up, else it flashes (palette effect 0D) and flinches until it has taken
   krusty_balloon_hit_limits_by_players hits (or one of kind 13), then flies off to throw (by
   krusty_balloon_fly_off_chances_by_rank) or is knocked up. */
void krusty_balloon_hit(uint16_t object)
{
	uint16_t command = 0, look_numbers = 0, object_2 = 0, palette_effect_number = 0, palette_job = 0;
	uint8_t vitality = 0, hit = 0, hits = 0, hits_2 = 0;
	uint16_t hit_by = 0, hit_by_2 = 0, own_x = 0, hitter_x = 0, screen_x = 0, x_speed = 0;

	hit_by = OBJECT(object)->hit_by;
	object_2 = hit_by;
	OBJECT(object_2)->behaviour = (OBJECT(object_2)->behaviour & 0xFFu) | 0x100u;
	AT16(OBJECT(object_2)->hit_box, -1) = object;
	command = 0x6501u;
	vector_queue_sound(command);
	OBJECT(object)->flags &= 0xBBu;
	look_numbers = 0x701u;
	krusty_balloon_set_animation(object, look_numbers);
	look_numbers &= 0xFFu;
	krusty_balloon_set_hit_box(object, look_numbers);
	palette_job = krusty_balloon_beaten_health_by_players_ADDRESS;
	vitality = OBJECT(object)->vitality;
	if (vitality <= krusty_balloon_beaten_health_by_players[(int8_t)((uint8_t)(player_count - 1u))])
	{
		OBJECT(object)->z_speed = 0x300;
		hit_by_2 = OBJECT(object)->hit_by;
		own_x = OBJECT(object)->x;
		hitter_x = OBJECT(hit_by_2)->x;
		if ((int16_t)hitter_x < (int16_t)own_x)
			OBJECT(object)->x_speed = 0x600;
		else
			OBJECT(object)->x_speed = -0x600;
		OBJECT(object)->state = 0xFEu;
		OBJECT(object)->krusty_balloon.step = 0u;
		OBJECT(object)->krusty_balloon.squash_step = 0u;
		return;
	}
	palette_request_kind = 2u;
	palette_effect_number = 0xDu;
	vector_palette_request(palette_job, palette_effect_number);
	hit = OBJECT(object)->hit;
	if (hit != 0x13u)
	{
		hits = OBJECT(object)->krusty_balloon.hits;
		OBJECT(object)->krusty_balloon.hits = hits + 1u;
		hits_2 = OBJECT(object)->krusty_balloon.hits;
		if (hits_2 < krusty_balloon_hit_limits_by_players[(int8_t)((uint8_t)(player_count - 1u))])
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->state = 0xFFu;
			OBJECT(object)->krusty_balloon.step = 0u;
			OBJECT(object)->krusty_balloon.squash_step = 0u;
			return;
		}
	}
	OBJECT(object)->krusty_balloon.hits = 0u;
	leftover_y = krusty_balloon_fly_off_chances_by_rank_ADDRESS;
	if (random_number <= krusty_balloon_fly_off_chances_by_rank[rank >> 1])
	{
		krusty_balloon_set_animation(object, palette_effect_number);
		OBJECT(object)->x_speed = 0x600;
		screen_x = OBJECT(object)->x;
		if ((int16_t)screen_x > 0xE0)
		{
			x_speed = OBJECT(object)->x_speed;
			OBJECT(object)->x_speed = 0u - x_speed;
		}
		OBJECT(object)->y_speed = 0x600;
		OBJECT(object)->z_speed = 0x600;
		OBJECT(object)->state = 3u;
		OBJECT(object)->krusty_balloon.step = 0u;
		OBJECT(object)->krusty_balloon.squash_step = 0u;
		return;
	}
	OBJECT(object)->z_speed = 0x300;
	hit_by_2 = OBJECT(object)->hit_by;
	own_x = OBJECT(object)->x;
	hitter_x = OBJECT(hit_by_2)->x;
	if ((int16_t)hitter_x < (int16_t)own_x)
		OBJECT(object)->x_speed = 0x600;
	else
		OBJECT(object)->x_speed = -0x600;
	OBJECT(object)->state = 0xFEu;
	OBJECT(object)->krusty_balloon.step = 0u;
	OBJECT(object)->krusty_balloon.squash_step = 0u;
}

/* Drops onto its target (state 4): can not be hurt, hit box 5, flies toward the target falling fast with
   animation 1. */
void krusty_balloon_stomp(uint16_t object, uint16_t object_2)
{
	uint32_t carry = 0;
	uint8_t angle = 0;
	uint16_t animation_number = 0, box_number = 0, direction = 0, direction_and_speed = 0, ignored16 = 0;

	OBJECT(object)->flags |= 0x4Cu;
	box_number = 0x500u;
	krusty_balloon_set_hit_box(object, box_number);
	find_nearest_player(object, &object_2, &ignored16, &carry);
	direction = vector_direction_to(object, object_2);
	angle = (uint8_t)(direction >> 8);
	direction_and_speed = ((uint32_t)angle << 8) | 0xC0u;
	vector_set_speed_by_direction(object, direction_and_speed);
	OBJECT(object)->z_speed = -0x400;
	OBJECT(object)->state = 4u;
	OBJECT(object)->krusty_balloon.step = 0u;
	OBJECT(object)->krusty_balloon.squash_step = 0u;
	animation_number = (direction_and_speed & 0xFFu) | 0x100u;
	krusty_balloon_set_animation(object, animation_number);
}

/* Keeps its state and step (fields 33-34), stops and waits for a target (state 5). */
uint32_t krusty_balloon_lose_target(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t zero_speed = 0;
	uint16_t animation_number = 0;
	uint8_t state = 0, step = 0, animation = 0;

	state = OBJECT(object)->state;
	OBJECT(object)->krusty_balloon.saved_state = state;
	step = OBJECT(object)->krusty_balloon.step;
	OBJECT(object)->krusty_balloon.saved_step = step;
	zero_speed = 0u;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->state = 5u;
	OBJECT(object)->krusty_balloon.step = 0u;
	OBJECT(object)->krusty_balloon.squash_step = 0u;
	animation = OBJECT(object)->animation;
	if (animation != 0u)
	{
		animation_number = 0u;
		krusty_balloon_set_animation(object, animation_number);
	}
	carry = 1u;
	return carry;
}

/* Stops its x speed when its next place in the stage would leave 076F-08E0. */
void krusty_balloon_keep_in_arena_x(uint16_t object)
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
	if ((int16_t)next_stage_x <= 0x76F || (int16_t)next_stage_x >= 0x8E0)
		OBJECT(object)->x_speed = 0;
}

/* Out of states 0 and 3, stops its y speed when its next place from the camera's would leave 0060-0100. */
void krusty_balloon_keep_in_arena_y(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t current_state = 0, next_y_high = 0, next_y_low = 0;
	uint8_t state = 0, y_speed_2 = 0, y_high = 0;
	uint16_t y_low_and_fraction = 0, y_speed = 0, old_y_low_and_fraction = 0, next_y_low_and_fraction = 0, stage_y_low_and_fraction = 0, camera_y_low_and_fraction = 0, next_stage_y_low = 0, screen_y_low_and_fraction = 0;

	state = OBJECT(object)->state;
	current_state = state;
	if (state != 0u && current_state != 3u)
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
		next_y_high = area_next_y_high - (uint8_t)(camera_y >> 8u) - carry;
		next_y_low = area_next_y_pixels;
		if ((int16_t)(((uint32_t)next_y_high << 8) | next_y_low) <= 0x60 || (int16_t)(((uint32_t)next_y_high << 8) | next_y_low) >= 0x100)
			OBJECT(object)->y_speed = 0;
	}
}

/* Bursts: plays sound 6F00 and the burst's animation (hit sparks, or krusty_balloon_animations' entry 12
   once it has fallen), state -1. */
void krusty_balloon_shot_burst(uint16_t object)
{
	uint8_t burst_animation = 0;
	uint16_t animation_number = 0, command = 0;
	uint8_t state = 0;

	command = 0x6F00u;
	vector_queue_sound(command);
	burst_animation = 0xBu;
	state = OBJECT(object)->state;
	if (state >= 3u)
		burst_animation++;
	animation_number = (uint32_t)burst_animation << 8;
	krusty_balloon_set_animation(object, animation_number);
	OBJECT(object)->state = 0xFFu;
}

/* Burst (state -1): gone at its animation's end. */
void krusty_balloon_shot_vanish(uint16_t object)
{
	uint8_t animation_flags = 0;

	OBJECT(object)->flags &= 0xBFu;
	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		OBJECT(object)->flags = 0u;
}

/* Flying (state 0): at its animation's end stops, shows animation 9 and drifts for 20 frames. */
void krusty_balloon_shot_fly(uint16_t object)
{
	uint16_t animation_number = 0;
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	animation_number = 0x900u;
	krusty_balloon_set_animation(object, animation_number);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->krusty_balloon_shot.shot_timer = 0x20u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	krusty_balloon_shot_drift(object);
}

/* Drifting (state 1): sways sideways every 32 frames as it sinks; after its time bursts open (state 2). */
void krusty_balloon_shot_drift(uint16_t object)
{
	uint16_t stack = 0;
	uint8_t shot_timer = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->x_speed = 0x80;
	stack = object;
	if (((stack + (uint8_t)frame_count) & 0x20u) == 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->z_speed = -0x40;
	shot_timer = OBJECT(object)->krusty_balloon_shot.shot_timer;
	OBJECT(object)->krusty_balloon_shot.shot_timer = shot_timer - 1u;
	if (shot_timer != 1u)
		return;
	krusty_balloon_shot_burst(object);
	OBJECT(object)->state = 2u;
}

/* Opening (state 2): at the burst's end stops, takes hit box 3 and animation 0A, and falls. */
void krusty_balloon_shot_open(uint16_t object)
{
	uint16_t animation_number = 0, box_number = 0;
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->z_speed = 0;
	box_number = 0x300u;
	krusty_balloon_set_hit_box(object, box_number);
	animation_number = 0xA00u;
	krusty_balloon_set_animation(object, animation_number);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Falling (state 3): falls with gravity and bursts on landing. */
void krusty_balloon_shot_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		krusty_balloon_shot_burst(object);
		return;
	}
}
