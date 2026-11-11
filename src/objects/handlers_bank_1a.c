/**
 *    Name:        objects/handlers_bank_1a.c
 *    Description: bank 1A's jump table: the Dreamland boss's objects' handlers
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The handler of the stage events' type 02: does nothing. */
void empty_stage_event_02(void)
{
}

/* An object handler of bank 1A that does nothing. */
void empty_object_handler_1a(void)
{
}

/* Runs the Dreamland boss's shadow by its step. */
uint16_t dreamland_boss_shadow_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return dreamland_boss_shadow_setup(object);
	case 2:
		return dreamland_boss_shadow_follow(object);
	}
	unreachable();
}

/* Runs the Dreamland boss (stage 6) by its step. */
void dreamland_boss_update(uint16_t object, uint8_t step)
{
	dreamland_boss_run_step(object, step);
}

/* Runs a piece of the boss's chain of balls by its step (the base, a link), then keeps it facing as its
   holder does. */
uint16_t dreamland_boss_chain_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		dreamland_boss_chain_setup(object);
		break;
	case 2:
		dreamland_boss_chain_lead(object);
		break;
	case 4:
		dreamland_boss_chain_link_setup(object);
		break;
	case 6:
		dreamland_boss_chain_link_order(object);
		break;
	case 8:
		dreamland_boss_chain_link_follow(object);
		break;
	case 10:
		dreamland_boss_chain_pop_start(object);
		break;
	case 12:
		dreamland_boss_chain_pop_next(object);
		break;
	case 14:
		dreamland_boss_chain_pop_end(object);
		break;
	case -4:
	case -2:
		dreamland_boss_chain_pop(object);
		break;
	}
	return dreamland_boss_chain_follow_facing(object);
}

/* Runs the head of the boss's chain by its step: it follows its paths and lashes out. */
uint16_t dreamland_boss_chain_head_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		dreamland_boss_chain_head_setup(object);
		break;
	case 2:
		dreamland_boss_chain_head_follow_path(object);
		break;
	case 4:
		dreamland_boss_chain_head_choose_lash(object);
		break;
	case 6:
		dreamland_boss_chain_head_lash(object);
		break;
	case 8:
		dreamland_boss_chain_head_withdraw(object);
		break;
	case 10:
		dreamland_boss_chain_head_retract(object);
		break;
	case -4:
	case -2:
		dreamland_boss_chain_pop(object);
		break;
	}
	return dreamland_boss_chain_follow_facing(object);
}

/* Runs a kind BB object that puts out a chain of balls and keeps facing the nearest player, by its step. */
void chain_holder_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		chain_holder_setup(object);
		return;
	case 2:
		chain_holder_put_out_chain(object);
		return;
	case 4:
		chain_holder_watch(object);
		return;
	}
}

/* Runs a ball the Dreamland boss spits by its step; it bursts when it hits something, and stretches with
   its speed in depth. */
uint16_t boss_ball_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t y_speed = 0, signed_y_speed = 0, y_speed_size = 0;

	state_2 = (uint8_t)state;
	states = boss_ball_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = boss_ball_setup(object);
		break;
	case 2:
		states = boss_ball_fly_out(object, states);
		break;
	case 4:
		states = boss_ball_home_in(object, states);
		break;
	case 6:
		states = boss_ball_land(object, states);
		break;
	case 8:
	case 14:
		boss_ball_burst_out(object);
		break;
	case 10:
	case 16:
		boss_ball_remove(object);
		break;
	case 12:
		boss_ball_burst(object);
		break;
	}
	if ((OBJECT(object)->flags & 0x20u) != 0u)
		OBJECT(object)->state = 6u;
	y_speed = OBJECT(object)->y_speed;
	signed_y_speed = y_speed;
	y_speed_size = signed_y_speed >> 15 ? 0u - signed_y_speed : signed_y_speed;
	OBJECT(object)->zoom_x = (y_speed_size >> 3) + 0x40u;
	OBJECT(object)->flags |= 0x10u;
	face_movement(object);
	return states;
}

/* Runs a puff of the trail the boss's balls leave, by its step. */
uint16_t boss_ball_trail_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = boss_ball_trail_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return boss_ball_trail_setup(object);
	case 2:
		boss_ball_trail_fade(object);
		return states;
	}
	unreachable();
}

/* Unused: prints in hex the first enemy's vitality, a scene variable, the camera's x and the cemetery's
   scroll (a debug display). */
void unused_show_debug_values(void)
{
	uint16_t place = 0, value = 0;
	uint8_t object_1a_level_shown = 0;
	uint16_t camera_x_now = 0, shown_scroll_x = 0, shown_cemetery_scroll = 0;

	place = unused_debug_tile_places[0];
	value = (uint32_t)OBJECT(OBJECT_ADDRESS(14))->vitality << 8;
	unused_vector_print_hex_byte(place, value);
	object_1a_level_shown = io_read8(dreamland_boss_phase_vitality);
	place = unused_debug_tile_places[1];
	value = (uint32_t)object_1a_level_shown << 8;
	unused_vector_print_hex_byte(place, value);
	camera_x_now = camera_x;
	shown_scroll_x = camera_x_now + 0x150u;
	debug_value = shown_scroll_x;
	place = unused_debug_tile_places[6];
	value = (uint32_t)debug_value_high << 8;
	unused_vector_print_hex_byte(place, value);
	place = unused_debug_tile_places[7];
	value = (uint32_t)debug_value_low << 8;
	unused_vector_print_hex_byte(place, value);
	shown_cemetery_scroll = cemetery_scroll;
	debug_value = shown_cemetery_scroll;
	place = unused_debug_tile_places[8];
	value = (uint32_t)debug_value_high << 8;
	unused_vector_print_hex_byte(place, value);
	place = unused_debug_tile_places[9];
	value = (uint32_t)debug_value_low << 8;
	unused_vector_print_hex_byte(place, value);
}
