/**
 *    Name:        objects/handlers_bank_1a.c
 *    Description: bank 1A's jump table: the Dreamland boss's objects' handlers
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
void dreamland_boss_shadow_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t u = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		dreamland_boss_shadow_setup(object, &y, &u);
		break;
	case 2:
		u = dreamland_boss_shadow_follow(object);
		break;
	}
	*p_y = y;
	*p_u = u;
}

/* Runs the Dreamland boss (stage 6) by its step. */
uint16_t dreamland_boss_update(uint16_t object, uint16_t y, uint8_t step)
{
	return dreamland_boss_run_step(object, y, step);
}

/* Runs a piece of the boss's chain of balls by its step (the base, a link), then keeps it facing as its
   holder does. */
void dreamland_boss_chain_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t u = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = dreamland_boss_chain_setup(object);
		break;
	case 2:
		y = dreamland_boss_chain_lead(object);
		break;
	case 4:
		y = dreamland_boss_chain_link_setup(object);
		break;
	case 6:
		y = dreamland_boss_chain_link_order(object);
		break;
	case 8:
		y = dreamland_boss_chain_link_follow(object);
		break;
	case 10:
		dreamland_boss_chain_pop_start(object);
		break;
	case 12:
		y = dreamland_boss_chain_pop_next(object, y);
		break;
	case 14:
		dreamland_boss_chain_pop_end(object);
		break;
	case -4:
	case -2:
		y = dreamland_boss_chain_pop(object, y);
		break;
	}
	u = dreamland_boss_chain_follow_facing(object);
	*p_y = y;
	*p_u = u;
}

/* Runs the head of the boss's chain by its step: it follows its paths and lashes out. */
void dreamland_boss_chain_head_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t u = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = dreamland_boss_chain_head_setup(object);
		break;
	case 2:
		y = dreamland_boss_chain_head_follow_path(object, y);
		break;
	case 4:
		y = dreamland_boss_chain_head_choose_lash(object, y);
		break;
	case 6:
		y = dreamland_boss_chain_head_lash(object, y);
		break;
	case 8:
		y = dreamland_boss_chain_head_withdraw(object, y);
		break;
	case 10:
		y = dreamland_boss_chain_head_retract(object, y);
		break;
	case -4:
	case -2:
		y = dreamland_boss_chain_pop(object, y);
		break;
	}
	u = dreamland_boss_chain_follow_facing(object);
	*p_y = y;
	*p_u = u;
}

/* Runs a kind BB object that puts out a chain of balls and keeps facing the nearest player, by its step. */
uint16_t chain_holder_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return chain_holder_setup(object);
	case 2:
		return chain_holder_put_out_chain(object, y);
	case 4:
		chain_holder_watch(object);
		return y;
	}
	unreachable();
}

/* Runs a ball the Dreamland boss spits by its step; it bursts when it hits something, and stretches with
   its speed in depth. */
uint16_t boss_ball_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t y_speed = 0, t1 = 0, t2 = 0;

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
	t1 = y_speed;
	t2 = t1 >> 15 ? 0u - t1 : t1;
	OBJECT(object)->zoom_x = (t2 >> 3) + 0x40u;
	OBJECT(object)->flags |= 0x10u;
	face_movement(object);
	return states;
}

/* Runs a puff of the trail the boss's balls leave, by its step. */
void boss_ball_trail_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = boss_ball_trail_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		boss_ball_trail_setup(object, &y, &states);
		break;
	case 2:
		boss_ball_trail_fade(object);
		break;
	}
	*p_y = y;
	*p_states = states;
}

/* Unused: prints in hex the first enemy's vitality, a scene variable, the camera's x and the cemetery's
   scroll (a debug display). */
void unused_show_debug_values(void)
{
	uint16_t depth = 0, place = 0, state = 0, value = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	depth = (((uint32_t)unused_spawn_0356DD[0].depth << 8u) | unused_spawn_0356DD[0].flags);
	value = (uint32_t)OBJECT(OBJECT_ADDRESS(14))->vitality << 8;
	unused_vector_print_hex_byte(depth, value);
	t1 = io_read8(0x188Cu);
	state = (((uint32_t)unused_spawn_0356DD[0].state << 8u) | unused_spawn_0356DD[0].level);
	value = (uint32_t)t1 << 8;
	unused_vector_print_hex_byte(state, value);
	t2 = camera_x;
	t3 = t2 + 0x150u;
	debug_value = t3;
	place = AT16(unused_tile_places[7], -1);
	value = (uint32_t)debug_value_high << 8;
	unused_vector_print_hex_byte(place, value);
	place = AT16(unused_tile_places[9], -1);
	value = (uint32_t)debug_value_low << 8;
	unused_vector_print_hex_byte(place, value);
	t4 = cemetery_scroll;
	debug_value = t4;
	place = AT16(unused_tile_places[11], -1);
	value = (uint32_t)debug_value_high << 8;
	unused_vector_print_hex_byte(place, value);
	place = AT16(unused_tile_places[13], -1);
	value = (uint32_t)debug_value_low << 8;
	unused_vector_print_hex_byte(place, value);
}
