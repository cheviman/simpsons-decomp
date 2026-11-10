/**
 *    Name:        enemies/goons.c
 *    Description: the goons: their set-ups and their entrances by type
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* A goon of kind B6 that throws bombs (type 3B; stages 2, 3 and 4): set up, then the enemies' states. */
void bomb_goon(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = bomb_goon_start(object);
		break;
	case 4:
	case 22:
	case 40:
	case 58:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
	case 24:
	case 42:
	case 60:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
	case 26:
	case 44:
	case 62:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case 10:
	case 28:
	case 46:
	case 64:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that runs in, throws one bomb and then fights (type 2E; stage 3's forest). */
void goon_bomb_run_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_bomb_run_in_set_up(object);
		break;
	case 2:
		y = goon_bomb_run_in_step(object, y);
		break;
	case 4:
	case 44:
	case 56:
	case 76:
	case 96:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
	case 46:
	case 58:
	case 78:
	case 98:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case 10:
	case 50:
	case 62:
	case 82:
	case 102:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_bomb_run_in_stop(object);
		break;
	case 14:
		y = goon_bomb_run_in_throw(object, y);
		break;
	case 16:
		goon_bomb_run_in_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon whose behaviour (029808) grabs at close range most of the time (type 03; stages 1-3 and 5). */
void goon_close_grabber(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_close_grabber_start(object);
		break;
	case -44:
	case -32:
	case -20:
	case -8:
	case 4:
	case 60:
	case 116:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -42:
	case -30:
	case -18:
	case -6:
	case 6:
	case 62:
	case 118:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -40:
	case -16:
	case -4:
	case 8:
	case 64:
	case 120:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -38:
	case -26:
	case -14:
	case -2:
	case 10:
	case 66:
	case 122:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -48:
		y = hat_goon_brawler_start(object);
		break;
	case -36:
		vector_goon_start(object, &y, &ignored16);
		break;
	case -28:
		y = enemy_react_with_walls(object, y);
		break;
	case -24:
		y = goon_keeps_away_start(object);
		break;
	case -12:
		y = goon_striker_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon whose behaviour (029860) never grabs: strikes close, jumps or walks up to strike from afar
   (type 0C; most stages, and bank 15's timed lists). */
void goon_striker(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_striker_start(object);
		break;
	case -32:
	case -20:
	case -8:
	case 4:
	case 16:
	case 72:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -30:
	case -18:
	case -6:
	case 6:
	case 18:
	case 74:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -28:
	case -4:
	case 8:
	case 20:
	case 76:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -26:
	case -14:
	case -2:
	case 10:
	case 22:
	case 78:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		y = goon_close_grabber_start(object);
		break;
	case -36:
		y = hat_goon_brawler_start(object);
		break;
	case -24:
		vector_goon_start(object, &y, &ignored16);
		break;
	case -16:
		y = enemy_react_with_walls(object, y);
		break;
	case -12:
		y = goon_keeps_away_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A plain goon with its own hit reaction (type 1C), which only bank 15's timed spawn lists put in. */
void goon_from_timed_list(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		vector_goon_start(object, &y, &ignored16);
		break;
	case -8:
	case 4:
	case 16:
	case 28:
	case 40:
	case 96:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 18:
	case 30:
	case 42:
	case 98:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		y = enemy_react_with_walls(object, y);
		break;
	case -2:
	case 10:
	case 22:
	case 34:
	case 46:
	case 102:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		y = goon_keeps_away_start(object);
		break;
	case -4:
	case 20:
	case 32:
	case 44:
	case 100:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case 24:
		y = goon_striker_start(object);
		break;
	case 36:
		y = goon_close_grabber_start(object);
		break;
	case -12:
		y = hat_goon_brawler_start(object);
		break;
	}
	*p_left_caller = enemy_take_special_hit_or_fall(object);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that comes down hanging from a balloon (type 2B; stage 2, and bank 15's timed lists): set up,
   comes down, then fights. */
void goon_descent(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		goon_descent_set_up(object, &y, &ignored16);
		break;
	case 2:
		goon_descent_step(object, &y, &ignored16);
		break;
	case -100:
	case -88:
	case -76:
	case -64:
	case -52:
	case 4:
	case 60:
	case 80:
	case 92:
	case 108:
	case 120:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -98:
	case -86:
	case -74:
	case -62:
	case -50:
	case 6:
	case 62:
	case 82:
	case 94:
	case 110:
	case 122:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -96:
	case -72:
	case -60:
	case -48:
	case 8:
	case 64:
	case 84:
	case 96:
	case 112:
	case 124:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -94:
	case -82:
	case -70:
	case -58:
	case -46:
	case 10:
	case 66:
	case 86:
	case 98:
	case 114:
	case 126:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_descent_float(object, 0u);
		break;
	case 14:
		goon_descent_land(object, 0u);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that runs in toward its target for the frames its spawn gives (type 25), then fights. */
void goon_rush_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -38:
	case -10:
	case 2:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case -112:
	case -56:
	case -36:
	case -24:
	case -8:
	case 4:
	case 20:
	case 46:
	case 80:
	case 122:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -110:
	case -54:
	case -34:
	case -22:
	case -6:
	case 6:
	case 22:
	case 48:
	case 82:
	case 124:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -108:
	case -52:
	case -32:
	case -20:
	case -4:
	case 8:
	case 24:
	case 50:
	case 84:
	case 126:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -106:
	case -50:
	case -30:
	case -18:
	case -2:
	case 10:
	case 26:
	case 52:
	case 86:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_rush_in_start(object);
		break;
	case 14:
		goon_rush_in_run(object, 0u);
		break;
	case 16:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 18:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case 28:
		goon_from_back_place(object);
		break;
	case 30:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 32:
		goon_from_back_wait(object, 0u);
		break;
	case -60:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case -58:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -48:
		hat_goon_run_across_pose(object);
		break;
	case -46:
		hat_goon_run_across_wait(object);
		break;
	case -44:
		hat_goon_run_across_run(object);
		break;
	case -42:
		hat_goon_run_across_running();
		break;
	case -40:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -28:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -26:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case -16:
		shovel_goon_rush_in_start(object);
		break;
	case -14:
		y = shovel_goon_rush_in_swing(object);
		break;
	case -12:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that comes from the back of the stage down to the floor (type 26). */
void goon_from_back(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 2:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case -128:
	case -72:
	case -52:
	case -40:
	case -24:
	case -12:
	case 4:
	case 30:
	case 64:
	case 106:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -126:
	case -70:
	case -50:
	case -38:
	case -22:
	case -10:
	case 6:
	case 32:
	case 66:
	case 108:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -124:
	case -68:
	case -48:
	case -36:
	case -20:
	case -8:
	case 8:
	case 34:
	case 68:
	case 110:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -66:
	case -46:
	case -34:
	case -18:
	case -6:
	case 10:
	case 36:
	case 70:
	case 112:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_from_back_place(object);
		break;
	case 14:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 16:
		goon_from_back_wait(object, 0u);
		break;
	case -76:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case -74:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -64:
		hat_goon_run_across_pose(object);
		break;
	case -62:
		hat_goon_run_across_wait(object);
		break;
	case -60:
		hat_goon_run_across_run(object);
		break;
	case -58:
		hat_goon_run_across_running();
		break;
	case -56:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -54:
	case -26:
	case -14:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case -44:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -42:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case -32:
		shovel_goon_rush_in_start(object);
		break;
	case -30:
		y = shovel_goon_rush_in_swing(object);
		break;
	case -28:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	case -16:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -4:
		goon_rush_in_start(object);
		break;
	case -2:
		goon_rush_in_run(object, 0u);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat that strikes its entrance pose and walks up onto the floor (type 3C). */
void hat_goon_step_out(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, state_handlers = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	state_2 = (uint8_t)state;
	state_handlers = hat_goon_step_out_states_ADDRESS;
	t1 = (uint32_t)state_2 << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		y = hat_goon_step_out_set_up(object);
		break;
	case 2:
	case 14:
		y = goon_step_out_step(object, y);
		break;
	case -128:
	case -94:
	case -52:
	case -18:
	case 4:
	case 16:
	case 66:
	case 86:
	case 98:
	case 120:
		vector_enemy_think(object, &y, &state_handlers, &ignored);
		break;
	case -126:
	case -92:
	case -50:
	case -16:
	case 6:
	case 18:
	case 68:
	case 88:
	case 100:
	case 122:
		vector_enemy_act(object, &y, &state_handlers, &ignored);
		break;
	case -124:
	case -90:
	case -48:
	case -14:
	case 8:
	case 20:
	case 70:
	case 90:
	case 102:
	case 124:
		vector_enemy_react(object, &y, &state_handlers, &ignored);
		break;
	case -122:
	case -88:
	case -46:
	case -12:
	case 10:
	case 22:
	case 72:
	case 92:
	case 104:
	case 126:
		vector_enemy_climb(object, &y, &state_handlers, &ignored);
		break;
	case 12:
	case 62:
		y = goon_step_out_set_up(object);
		break;
	case -102:
	case -60:
	case -26:
	case -6:
	case 58:
		goon_reach_floor_level(object);
		break;
	case -100:
	case -58:
	case -24:
	case 60:
	case 80:
		goon_entrance_end(object);
		break;
	case -42:
	case -38:
	case -34:
	case -30:
		enemy_set_knock_direction(object, state_handlers, zero, negative);
		break;
	case -28:
		goon_delayed_start(object);
		break;
	case -22:
		y = shovel_goon_step_out_set_up(object);
		break;
	case -20:
		y = shovel_goon_step_out_step(object, y);
		break;
	case -10:
		shovel_goon_step_out_show(object);
		break;
	case -8:
		shovel_goon_step_out_walk(object);
		break;
	case -4:
		shovel_goon_step_out_pause(object);
		break;
	case -2:
		shovel_goon_step_out_arm(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that runs in from a side of the cemetery's moving ground and jumps up (type F3; stage 3's
   cemetery). */
void goon_jump_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_jump_in_set_up(object);
		break;
	case -10:
	case 2:
		y = goon_jump_in_step(object, y);
		break;
	case -48:
	case -8:
	case 4:
	case 24:
	case 44:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -46:
	case -6:
	case 6:
	case 26:
	case 46:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 28:
	case 48:
		y = enemy_react_with_pits(object, y);
		break;
	case -42:
	case -2:
	case 10:
	case 30:
	case 50:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -12:
		y = goon_striker_jump_in_set_up(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that comes up from below the cemetery's floor and jumps out (type F1; stage 3's cemetery). */
void goon_from_below(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_from_below_set_up(object);
		break;
	case 2:
		y = goon_from_below_step(object, y);
		break;
	case -68:
	case -28:
	case -16:
	case 4:
	case 24:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -66:
	case -26:
	case -14:
	case 6:
	case 26:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -24:
	case -12:
	case 8:
	case 28:
		y = enemy_react_with_pits(object, y);
		break;
	case -62:
	case -22:
	case -10:
	case 10:
	case 30:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -4:
		goon_jump_in_leap(object);
		break;
	case -2:
		goon_jump_in_land(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A striker goon (no grabs) that runs in from a side of the cemetery's moving ground and jumps up (type
   EE). */
void goon_striker_jump_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_striker_jump_in_set_up(object);
		break;
	case 2:
	case 14:
		y = goon_jump_in_step(object, y);
		break;
	case -36:
	case 4:
	case 16:
	case 36:
	case 56:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -34:
	case 6:
	case 18:
	case 38:
	case 58:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
	case 20:
	case 40:
	case 60:
		y = enemy_react_with_pits(object, y);
		break;
	case -30:
	case 10:
	case 22:
	case 42:
	case 62:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		y = goon_jump_in_set_up(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that walks up onto the floor (type 39). */
void goon_walk_up(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case -50:
	case 0:
		y = goon_step_out_set_up(object);
		break;
	case 2:
		y = goon_walk_up_step(object, y);
		break;
	case -114:
	case -80:
	case -58:
	case -46:
	case 4:
	case 24:
	case 36:
	case 58:
	case 84:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -112:
	case -78:
	case -56:
	case -44:
	case 6:
	case 26:
	case 38:
	case 60:
	case 86:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -110:
	case -76:
	case -54:
	case -42:
	case 8:
	case 28:
	case 40:
	case 62:
	case 88:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -108:
	case -74:
	case -52:
	case -40:
	case 10:
	case 30:
	case 42:
	case 64:
	case 90:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_walk_up_show(object);
		break;
	case -6:
	case 14:
		goon_walk_up_start(object);
		break;
	case 16:
		goon_walk_up_reach_floor(object);
		break;
	case -120:
	case -86:
	case -2:
	case 18:
		goon_entrance_end(object);
		break;
	case 20:
		y = goon_striker_from_side_set_up(object);
		break;
	case 22:
	case 34:
		y = goon_from_side_step(object, y);
		break;
	case 32:
		y = goon_from_side_set_up(object);
		break;
	case -122:
	case -88:
	case -68:
	case -4:
		goon_reach_floor_level(object);
		break;
	case -12:
		goon_step_out_check(object);
		break;
	case -10:
		goon_step_out_pose(object);
		break;
	case -8:
		goon_step_out_pose_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that shows when the scroll brings it in, then walks in at a slant onto the floor (type 15; no
   scenario puts it in). */
void goon_walk_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_walk_in_set_up(object);
		break;
	case 2:
		y = goon_walk_in_step(object, y);
		break;
	case -112:
	case -100:
	case -84:
	case -72:
	case -56:
	case -30:
	case 4:
	case 46:
	case 80:
	case 102:
	case 114:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -82:
	case -70:
	case -54:
	case -28:
	case 6:
	case 48:
	case 82:
	case 104:
	case 116:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -96:
	case -80:
	case -68:
	case -52:
	case -26:
	case 8:
	case 50:
	case 84:
	case 106:
	case 118:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -126:
	case -106:
	case -94:
	case -78:
	case -66:
	case -50:
	case -24:
	case 10:
	case 52:
	case 86:
	case 108:
	case 120:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -4:
	case 38:
	case 72:
	case 92:
		goon_reach_floor_level(object);
		break;
	case -2:
	case 40:
	case 74:
		goon_entrance_end(object);
		break;
	case -10:
		y = hat_goon_waiting_show(object, y);
		break;
	case -8:
		hat_goon_waiting_for_scroll(object);
		break;
	case -6:
		y = hat_goon_waiting_step_forward(object, y);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that strikes its entrance pose (getting out of the police car when its spawn's bit 7 is set)
   and walks up onto the floor (type 16). */
void goon_step_out(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, state_handlers = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	state_2 = (uint8_t)state;
	state_handlers = goon_step_out_states_ADDRESS;
	t1 = (uint32_t)state_2 << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
	case 50:
		y = goon_step_out_set_up(object);
		break;
	case -10:
	case 2:
		y = goon_step_out_step(object, y);
		break;
	case -106:
	case -64:
	case -30:
	case -8:
	case 4:
	case 54:
	case 74:
	case 86:
	case 108:
		vector_enemy_think(object, &y, &state_handlers, &ignored);
		break;
	case -104:
	case -62:
	case -28:
	case -6:
	case 6:
	case 56:
	case 76:
	case 88:
	case 110:
		vector_enemy_act(object, &y, &state_handlers, &ignored);
		break;
	case -102:
	case -60:
	case -26:
	case -4:
	case 8:
	case 58:
	case 78:
	case 90:
	case 112:
		vector_enemy_react(object, &y, &state_handlers, &ignored);
		break;
	case -100:
	case -58:
	case -24:
	case -2:
	case 10:
	case 60:
	case 80:
	case 92:
	case 114:
		vector_enemy_climb(object, &y, &state_handlers, &ignored);
		break;
	case -114:
	case -72:
	case -38:
	case -18:
	case 46:
		goon_reach_floor_level(object);
		break;
	case -112:
	case -70:
	case -36:
	case 48:
	case 68:
		goon_entrance_end(object);
		break;
	case -54:
	case -50:
	case -46:
	case -42:
		enemy_set_knock_direction(object, state_handlers, zero, negative);
		break;
	case -40:
		goon_delayed_start(object);
		break;
	case -34:
		y = shovel_goon_step_out_set_up(object);
		break;
	case -32:
		y = shovel_goon_step_out_step(object, y);
		break;
	case -22:
		shovel_goon_step_out_show(object);
		break;
	case -20:
		shovel_goon_step_out_walk(object);
		break;
	case -16:
		shovel_goon_step_out_pause(object);
		break;
	case -14:
		shovel_goon_step_out_arm(object);
		break;
	case -12:
		y = hat_goon_step_out_set_up(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* The balloon a descending goon hangs from (list 1 type 0D): runs its state (0 set up, 1 carried, 2 let
   go, 3 rising). */
void goon_balloon(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_state_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t state_handlers = 0;

	state_2 = (uint8_t)state;
	state_handlers = goon_balloon_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		goon_balloon_set_up(object, &y, &state_handlers);
		break;
	case 2:
		state_handlers = goon_balloon_carried(object);
		break;
	case 4:
		goon_balloon_let_go(object);
		break;
	case 6:
		goon_balloon_rise(object);
		break;
	}
	*p_y = y;
	*p_state_handlers = state_handlers;
}

/* A goon hidden until the scroll brings it in, that then runs in onto the floor (type 17; stage 4). */
void goon_run_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_run_in_set_up(object);
		break;
	case 2:
		y = goon_run_in_step(object, y);
		break;
	case -112:
	case -100:
	case -50:
	case -30:
	case -18:
	case 4:
	case 30:
	case 78:
	case 102:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -48:
	case -28:
	case -16:
	case 6:
	case 32:
	case 80:
	case 104:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -108:
	case -96:
	case -46:
	case -26:
	case -14:
	case 8:
	case 34:
	case 82:
	case 106:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -128:
	case -106:
	case -94:
	case -44:
	case -24:
	case -12:
	case 10:
	case 36:
	case 84:
	case 108:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -4:
	case 22:
		goon_reach_floor(object);
		break;
	case -2:
	case 24:
		goon_wait_on_floor(object);
		break;
	case -6:
		goon_from_side_walk(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat that waits for the scroll and jumps in (type 18; stage 4). */
void hat_goon_jump_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = hat_goon_jump_in_set_up(object);
		break;
	case 2:
		y = hat_goon_jump_in_step(object, y);
		break;
	case -126:
	case -76:
	case -56:
	case -44:
	case -22:
	case 4:
	case 52:
	case 76:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -124:
	case -74:
	case -54:
	case -42:
	case -20:
	case 6:
	case 54:
	case 78:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -72:
	case -52:
	case -40:
	case -18:
	case 8:
	case 56:
	case 80:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -120:
	case -70:
	case -50:
	case -38:
	case -16:
	case 10:
	case 58:
	case 82:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -30:
	case -4:
		goon_reach_floor(object);
		break;
	case -28:
	case -2:
		goon_wait_on_floor(object);
		break;
	case -6:
		goon_run_in_go(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat waiting where the scroll brings it in, that then steps forward (type 06; stage 4). */
void hat_goon_waiting(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = hat_goon_waiting_set_up(object);
		break;
	case 2:
		y = hat_goon_waiting_step(object, y);
		break;
	case -98:
	case -78:
	case -66:
	case -50:
	case -38:
	case -22:
	case 4:
	case 38:
	case 80:
	case 114:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -96:
	case -76:
	case -64:
	case -48:
	case -36:
	case -20:
	case 6:
	case 40:
	case 82:
	case 116:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -94:
	case -74:
	case -62:
	case -46:
	case -34:
	case -18:
	case 8:
	case 42:
	case 84:
	case 118:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -92:
	case -72:
	case -60:
	case -44:
	case -32:
	case -16:
	case 10:
	case 44:
	case 86:
	case 120:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon hidden for a while that then comes in by a direction and a speed onto the floor (type 1D). */
void goon_delayed(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_delayed_set_up(object);
		break;
	case 2:
		y = goon_delayed_step(object, y);
		break;
	case -126:
	case -114:
	case -98:
	case -72:
	case -38:
	case 4:
	case 38:
	case 60:
	case 72:
	case 122:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -96:
	case -70:
	case -36:
	case 6:
	case 40:
	case 62:
	case 74:
	case 124:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -110:
	case -94:
	case -68:
	case -34:
	case 8:
	case 42:
	case 64:
	case 76:
	case 126:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -120:
	case -108:
	case -92:
	case -66:
	case -32:
	case 10:
	case 44:
	case 66:
	case 78:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -46:
	case -4:
	case 30:
	case 50:
	case 114:
		goon_reach_floor_level(object);
		break;
	case -44:
	case -2:
	case 32:
	case 116:
		goon_entrance_end(object);
		break;
	case -8:
		goon_walk_in_wait_for_scroll(object);
		break;
	case -6:
		goon_walk_in_go(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that waits for the scroll and drops down (type 1E; no scenario puts it in). */
void goon_drop(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_drop_set_up(object);
		break;
	case 2:
		y = goon_drop_step(object, y);
		break;
	case -124:
	case -104:
	case -92:
	case -70:
	case -44:
	case 4:
	case 28:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -102:
	case -90:
	case -68:
	case -42:
	case 6:
	case 30:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -120:
	case -100:
	case -88:
	case -66:
	case -40:
	case 8:
	case 32:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -118:
	case -98:
	case -86:
	case -64:
	case -38:
	case 10:
	case 34:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -12:
	case 16:
		goon_wait_for_scroll(object);
		break;
	case -4:
	case 20:
		goon_stop_and_fall(object);
		break;
	case -2:
	case 22:
		goon_fall_to_floor(object);
		break;
	case -10:
		hat_goon_jump_in_show(object);
		break;
	case -8:
		hat_goon_jump_in_leap(object);
		break;
	case -6:
		hat_goon_jump_in_fly(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with an umbrella floating down into the cemetery (type ED; stage 3's cemetery). */
void cemetery_umbrella_goon(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = cemetery_umbrella_goon_set_up(object);
		break;
	case 2:
		cemetery_umbrella_goon_float_down(object);
		break;
	case -88:
	case -48:
	case -36:
	case -16:
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -86:
	case -46:
	case -34:
	case -14:
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -44:
	case -32:
	case -12:
	case 8:
		y = enemy_react_with_pits(object, y);
		break;
	case -82:
	case -42:
	case -30:
	case -10:
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -4:
		goon_from_below_leap(object);
		break;
	case -2:
		y = goon_from_below_land(object, y);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon whose behaviour (0298B8) grabs close but mostly keeps its distance further off (type EB; most
   stages). */
void goon_keeps_away(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_keeps_away_start(object);
		break;
	case -20:
	case -8:
	case 4:
	case 16:
	case 28:
	case 84:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -18:
	case -6:
	case 6:
	case 18:
	case 30:
	case 86:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -16:
	case 8:
	case 20:
	case 32:
	case 88:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -14:
	case -2:
	case 10:
	case 22:
	case 34:
	case 90:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		y = goon_striker_start(object);
		break;
	case 24:
		y = goon_close_grabber_start(object);
		break;
	case -24:
		y = hat_goon_brawler_start(object);
		break;
	case -12:
		vector_goon_start(object, &y, &ignored16);
		break;
	case -4:
		y = enemy_react_with_walls(object, y);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with an umbrella floating down from above (type 08). */
void umbrella_goon_float_down(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = umbrella_goon_float_down_set_up(object);
		break;
	case 2:
		umbrella_goon_float_down_step(object);
		break;
	case -128:
	case -116:
	case -94:
	case -68:
	case -20:
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -92:
	case -66:
	case -18:
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -90:
	case -64:
	case -16:
	case 8:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -110:
	case -88:
	case -62:
	case -14:
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -36:
	case -8:
		goon_wait_for_scroll(object);
		break;
	case -28:
	case -4:
		goon_stop_and_fall(object);
		break;
	case -26:
	case -2:
		goon_fall_to_floor(object);
		break;
	case -6:
		goon_drop_show(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat that runs across the screen once the scroll brings it in (type 27; no scenario puts
   it in). */
void hat_goon_run_across(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case 2:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -120:
	case -108:
	case -52:
	case 4:
	case 24:
	case 36:
	case 52:
	case 64:
	case 80:
	case 106:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -118:
	case -106:
	case -50:
	case 6:
	case 26:
	case 38:
	case 54:
	case 66:
	case 82:
	case 108:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -128:
	case -116:
	case -104:
	case -48:
	case 8:
	case 28:
	case 40:
	case 56:
	case 68:
	case 84:
	case 110:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -102:
	case -46:
	case 10:
	case 30:
	case 42:
	case 58:
	case 70:
	case 86:
	case 112:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		hat_goon_run_across_pose(object);
		break;
	case 14:
		hat_goon_run_across_wait(object);
		break;
	case 16:
		hat_goon_run_across_run(object);
		break;
	case 18:
		hat_goon_run_across_running();
		break;
	case 20:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 22:
	case 50:
	case 62:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case 32:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 34:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case 44:
		shovel_goon_rush_in_start(object);
		break;
	case 46:
		y = shovel_goon_rush_in_swing(object);
		break;
	case 48:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	case 60:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 72:
		goon_rush_in_start(object);
		break;
	case 74:
		goon_rush_in_run(object, 0u);
		break;
	case 76:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 78:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case 88:
		goon_from_back_place(object);
		break;
	case 90:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 92:
		goon_from_back_wait(object, 0u);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon that strikes its entrance pose, steps onto the floor and takes up a shovel (type 1B). */
void shovel_goon_step_out(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t zero = 0, negative = 0;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, state_handlers = 0;
	uint32_t ignored = 0;
	uint8_t t1 = 0;

	state_2 = (uint8_t)state;
	state_handlers = shovel_goon_step_out_states_ADDRESS;
	t1 = (uint32_t)state_2 << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		y = shovel_goon_step_out_set_up(object);
		break;
	case 2:
		y = shovel_goon_step_out_step(object, y);
		break;
	case -106:
	case -72:
	case -30:
	case 4:
	case 26:
	case 38:
	case 88:
	case 108:
	case 120:
		vector_enemy_think(object, &y, &state_handlers, &ignored);
		break;
	case -104:
	case -70:
	case -28:
	case 6:
	case 28:
	case 40:
	case 90:
	case 110:
	case 122:
		vector_enemy_act(object, &y, &state_handlers, &ignored);
		break;
	case -128:
	case -102:
	case -68:
	case -26:
	case 8:
	case 30:
	case 42:
	case 92:
	case 112:
	case 124:
		vector_enemy_react(object, &y, &state_handlers, &ignored);
		break;
	case -126:
	case -100:
	case -66:
	case -24:
	case 10:
	case 32:
	case 44:
	case 94:
	case 114:
	case 126:
		vector_enemy_climb(object, &y, &state_handlers, &ignored);
		break;
	case 12:
		shovel_goon_step_out_show(object);
		break;
	case 14:
		shovel_goon_step_out_walk(object);
		break;
	case -80:
	case -38:
	case -4:
	case 16:
	case 80:
		goon_reach_floor_level(object);
		break;
	case 18:
		shovel_goon_step_out_pause(object);
		break;
	case 20:
		shovel_goon_step_out_arm(object);
		break;
	case 22:
		y = hat_goon_step_out_set_up(object);
		break;
	case 24:
	case 36:
		y = goon_step_out_step(object, y);
		break;
	case 34:
	case 84:
		y = goon_step_out_set_up(object);
		break;
	case -78:
	case -36:
	case -2:
	case 82:
	case 102:
		goon_entrance_end(object);
		break;
	case -20:
	case -16:
	case -12:
	case -8:
		enemy_set_knock_direction(object, state_handlers, zero, negative);
		break;
	case -6:
		goon_delayed_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A striker goon (no grabs) that runs in toward its target for the frames its spawn gives (type 34),
   then fights. */
void goon_striker_rush_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	case -26:
	case 2:
	case 14:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case -100:
	case -44:
	case -24:
	case -12:
	case 4:
	case 16:
	case 32:
	case 58:
	case 92:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -98:
	case -42:
	case -22:
	case -10:
	case 6:
	case 18:
	case 34:
	case 60:
	case 94:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -96:
	case -40:
	case -20:
	case -8:
	case 8:
	case 20:
	case 36:
	case 62:
	case 96:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -94:
	case -38:
	case -18:
	case -6:
	case 10:
	case 22:
	case 38:
	case 64:
	case 98:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 24:
		goon_rush_in_start(object);
		break;
	case 26:
		goon_rush_in_run(object, 0u);
		break;
	case 28:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 30:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case 40:
		goon_from_back_place(object);
		break;
	case 42:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 44:
		goon_from_back_wait(object, 0u);
		break;
	case -48:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case -46:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -36:
		hat_goon_run_across_pose(object);
		break;
	case -34:
		hat_goon_run_across_wait(object);
		break;
	case -32:
		hat_goon_run_across_run(object);
		break;
	case -30:
		hat_goon_run_across_running();
		break;
	case -28:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -16:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case -14:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case -4:
		shovel_goon_rush_in_start(object);
		break;
	case -2:
		y = shovel_goon_rush_in_swing(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat (type 01): set up, then the enemies' states. */
void hat_goon(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = hat_goon_start(object);
		break;
	case -14:
	case 4:
	case 22:
	case 40:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -12:
	case 6:
	case 24:
	case 42:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -10:
	case 8:
	case 26:
	case 44:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -8:
	case 10:
	case 28:
	case 46:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with an umbrella (type 0A): set up, then the enemies' states. */
void umbrella_goon(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = umbrella_goon_start(object);
		break;
	case -32:
	case -14:
	case 4:
	case 22:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -30:
	case -12:
	case 6:
	case 24:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -28:
	case -10:
	case 8:
	case 26:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -26:
	case -8:
	case 10:
	case 28:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a shovel (type 0D): set up, then the enemies' states. */
void shovel_goon(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = shovel_goon_start(object);
		break;
	case -50:
	case -32:
	case -14:
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -48:
	case -30:
	case -12:
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -46:
	case -28:
	case -10:
	case 8:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -44:
	case -26:
	case -8:
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a hat whose behaviour (029910) never throws the hat: backs off at mid range and walks up
   to strike from afar (type E7; stages 3 and 7). */
void hat_goon_brawler(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = hat_goon_brawler_start(object);
		break;
	case 4:
	case 16:
	case 28:
	case 40:
	case 52:
	case 108:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
	case 18:
	case 30:
	case 42:
	case 54:
	case 110:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
	case 32:
	case 44:
	case 56:
	case 112:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case 10:
	case 22:
	case 34:
	case 46:
	case 58:
	case 114:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		vector_goon_start(object, &y, &ignored16);
		break;
	case 20:
		y = enemy_react_with_walls(object, y);
		break;
	case 24:
		y = goon_keeps_away_start(object);
		break;
	case 36:
		y = goon_striker_start(object);
		break;
	case 48:
		y = goon_close_grabber_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* Unused: a slot of the goons' bank that jumps to hat_goon_set_up. */
void unused_vector_hat_goon_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	hat_goon_set_up(object, &ignored16, &ignored16_2);
}

/* Unused: a slot of the goons' bank that jumps to umbrella_goon_set_up. */
void unused_vector_umbrella_goon_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	umbrella_goon_set_up(object, &ignored16, &ignored16_2);
}

/* Unused: a slot of the goons' bank that jumps to shovel_goon_set_up. */
void unused_vector_shovel_goon_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	shovel_goon_set_up(object, &ignored16, &ignored16_2);
}

/* A goon that walks in from the left onto the floor and waits there (type 3F). */
void goon_from_side(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_from_side_set_up(object);
		break;
	case -10:
	case 2:
		y = goon_from_side_step(object, y);
		break;
	case -112:
	case -90:
	case -78:
	case -28:
	case -8:
	case 4:
	case 26:
	case 52:
	case 100:
	case 124:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -110:
	case -88:
	case -76:
	case -26:
	case -6:
	case 6:
	case 28:
	case 54:
	case 102:
	case 126:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -108:
	case -86:
	case -74:
	case -24:
	case -4:
	case 8:
	case 30:
	case 56:
	case 104:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -106:
	case -84:
	case -72:
	case -22:
	case -2:
	case 10:
	case 32:
	case 58:
	case 106:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case -120:
	case -100:
	case -36:
		goon_reach_floor_level(object);
		break;
	case -118:
	case -34:
	case -14:
		goon_entrance_end(object);
		break;
	case -82:
	case -32:
		y = goon_step_out_set_up(object);
		break;
	case -44:
		goon_step_out_check(object);
		break;
	case -42:
		goon_step_out_pose(object);
		break;
	case -40:
		goon_step_out_pose_end(object);
		break;
	case -38:
	case -18:
		goon_walk_up_start(object);
		break;
	case -30:
		y = goon_walk_up_step(object, y);
		break;
	case -20:
		goon_walk_up_show(object);
		break;
	case -16:
		goon_walk_up_reach_floor(object);
		break;
	case -12:
		y = goon_striker_from_side_set_up(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with a shovel that charges in swinging it for the frames its spawn gives (type 29), then
   fights. */
void shovel_goon_rush_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 2:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case -84:
	case -28:
	case -8:
	case 4:
	case 20:
	case 32:
	case 48:
	case 74:
	case 108:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -82:
	case -26:
	case -6:
	case 6:
	case 22:
	case 34:
	case 50:
	case 76:
	case 110:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -80:
	case -24:
	case -4:
	case 8:
	case 24:
	case 36:
	case 52:
	case 78:
	case 112:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -78:
	case -22:
	case -2:
	case 10:
	case 26:
	case 38:
	case 54:
	case 80:
	case 114:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		shovel_goon_rush_in_start(object);
		break;
	case 14:
		y = shovel_goon_rush_in_swing(object);
		break;
	case 16:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	case -10:
	case 18:
	case 30:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case 28:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 40:
		goon_rush_in_start(object);
		break;
	case 42:
		goon_rush_in_run(object, 0u);
		break;
	case 44:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 46:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case 56:
		goon_from_back_place(object);
		break;
	case 58:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 60:
		goon_from_back_wait(object, 0u);
		break;
	case -32:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case -30:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -20:
		hat_goon_run_across_pose(object);
		break;
	case -18:
		hat_goon_run_across_wait(object);
		break;
	case -16:
		hat_goon_run_across_run(object);
		break;
	case -14:
		hat_goon_run_across_running();
		break;
	case -12:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A goon with an umbrella that runs in toward its target for the frames its spawn gives (type 2A), then
   fights. */
void umbrella_goon_rush_in(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		umbrella_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 2:
	case 30:
	case 42:
		goon_rush_in_step(object, &y, &ignored16);
		break;
	case -128:
	case -72:
	case -16:
	case 4:
	case 16:
	case 32:
	case 44:
	case 60:
	case 86:
	case 120:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -126:
	case -70:
	case -14:
	case 6:
	case 18:
	case 34:
	case 46:
	case 62:
	case 88:
	case 122:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -124:
	case -68:
	case -12:
	case 8:
	case 20:
	case 36:
	case 48:
	case 64:
	case 90:
	case 124:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -122:
	case -66:
	case -10:
	case 10:
	case 22:
	case 38:
	case 50:
	case 66:
	case 92:
	case 126:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		shovel_goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 14:
		shovel_goon_rush_in_step(object, &y, &ignored16);
		break;
	case 24:
		shovel_goon_rush_in_start(object);
		break;
	case 26:
		y = shovel_goon_rush_in_swing(object);
		break;
	case 28:
		goon_striker_rush_in_set_up(object, &y, &ignored16);
		break;
	case 40:
		goon_rush_in_set_up(object, &y, &ignored16);
		break;
	case 52:
		goon_rush_in_start(object);
		break;
	case 54:
		goon_rush_in_run(object, 0u);
		break;
	case 56:
		goon_from_back_set_up(object, &y, &ignored16);
		break;
	case 58:
		goon_from_back_step(object, &y, &ignored16);
		break;
	case 68:
		goon_from_back_place(object);
		break;
	case 70:
		goon_from_back_reach_floor(object, 0u);
		break;
	case 72:
		goon_from_back_wait(object, 0u);
		break;
	case -20:
		hat_goon_run_across_set_up(object, &y, &ignored16);
		break;
	case -18:
		hat_goon_run_across_step(object, &y, &ignored16);
		break;
	case -8:
		hat_goon_run_across_pose(object);
		break;
	case -6:
		hat_goon_run_across_wait(object);
		break;
	case -4:
		hat_goon_run_across_run(object);
		break;
	case -2:
		hat_goon_run_across_running();
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* A striker goon (no grabs) that walks in from the left onto the floor (type F4; no scenario puts it
   in). */
void goon_striker_from_side(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = goon_striker_from_side_set_up(object);
		break;
	case 2:
	case 14:
		y = goon_from_side_step(object, y);
		break;
	case -100:
	case -78:
	case -66:
	case -16:
	case 4:
	case 16:
	case 38:
	case 64:
	case 112:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case -98:
	case -76:
	case -64:
	case -14:
	case 6:
	case 18:
	case 40:
	case 66:
	case 114:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case -96:
	case -74:
	case -62:
	case -12:
	case 8:
	case 20:
	case 42:
	case 68:
	case 116:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		break;
	case -128:
	case -94:
	case -72:
	case -60:
	case -10:
	case 10:
	case 22:
	case 44:
	case 70:
	case 118:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	case 12:
		y = goon_from_side_set_up(object);
		break;
	case -108:
	case -88:
	case -24:
		goon_reach_floor_level(object);
		break;
	case -106:
	case -22:
	case -2:
		goon_entrance_end(object);
		break;
	case -70:
	case -20:
		y = goon_step_out_set_up(object);
		break;
	case -32:
		goon_step_out_check(object);
		break;
	case -30:
		goon_step_out_pose(object);
		break;
	case -28:
		goon_step_out_pose_end(object);
		break;
	case -26:
	case -6:
		goon_walk_up_start(object);
		break;
	case -18:
		y = goon_walk_up_step(object, y);
		break;
	case -8:
		goon_walk_up_show(object);
		break;
	case -4:
		goon_walk_up_reach_floor(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* Sets up a goon in the hat goon's set (kind 84) with behaviour 029910. */
uint16_t hat_goon_brawler_set_up(uint16_t object)
{
	uint16_t y = 0;
	uint8_t attributes = 0;

	y = goon_base_set_up(object);
	OBJECT(object)->kind = 0x84u;
	OBJECT(object)->behaviour = 0x7910u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & ~0xFu) | 0x86u;
	return y;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing (state 2). */
uint16_t hat_goon_brawler_start(uint16_t object)
{
	uint16_t y = 0;

	y = hat_goon_brawler_set_up(object);
	goon_weaken_if_marked(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Sets up a goon (kind 80, setup 79B0): its retarget time, facing, counted among the stage's enemies
   (field 42), its nearest player and the distances to it. */
uint16_t goon_base_set_up(uint16_t object)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	setup = goon_base_object_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->retarget_time = 0x10u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	return y;
}

/* Sets up a goon with behaviour 0298B8, standing (animation 86). */
uint16_t goon_keeps_away_set_up(uint16_t object)
{
	uint16_t y = 0;

	y = goon_base_set_up(object);
	OBJECT(object)->behaviour = 0x78B8u;
	OBJECT(object)->animation = 0x86u;
	return y;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t goon_keeps_away_start(uint16_t object)
{
	uint16_t y = 0;

	y = goon_keeps_away_set_up(object);
	goon_weaken_if_marked(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Sets up a goon with behaviour 029860 (no grabs). */
void goon_striker_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_behaviour)
{
	uint16_t behaviour = 0, y = 0;
	uint8_t attributes = 0;

	y = goon_base_set_up(object);
	behaviour = 0x7860u;
	OBJECT(object)->behaviour = 0x7860u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & ~0xFu) | 0x86u;
	*p_y = y;
	*p_behaviour = behaviour;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t goon_striker_start(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	goon_striker_set_up(object, &y, &ignored16);
	goon_weaken_if_marked(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* A goon whose spawn gave it a field 30 has 1 health. */
void goon_weaken_if_marked(uint16_t object)
{
	uint8_t parameter = 0;

	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
}

/* Sets up a goon with behaviour 029808. */
uint16_t goon_close_grabber_set_up(uint16_t object)
{
	uint16_t y = 0;

	y = goon_base_set_up(object);
	OBJECT(object)->behaviour = 0x7808u;
	return y;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t goon_close_grabber_start(uint16_t object)
{
	uint16_t y = 0;

	y = goon_close_grabber_set_up(object);
	goon_weaken_if_marked(object);
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Its state 0: shown with the goon's set's animation 36, at its goon's place 3C higher, moving with it. */
void goon_balloon_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_object_2)
{
	uint16_t object_3 = 0, setup = 0, y = 0;
	uint8_t attributes = 0, attributes_2 = 0, state = 0;
	uint16_t parent = 0, x_speed = 0, z_speed = 0, t1 = 0, t2 = 0, z = 0, t3 = 0;

	setup = goon_balloon_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 0x80u;
	parent = OBJECT(object)->parent;
	object_3 = parent;
	attributes = OBJECT(object_3)->attributes;
	priority_bits = attributes & 0x30u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | priority_bits;
	x_speed = OBJECT(object_3)->x_speed;
	OBJECT(object)->x_speed = x_speed;
	z_speed = OBJECT(object_3)->z_speed;
	OBJECT(object)->z_speed = z_speed;
	t1 = OBJECT(object_3)->x;
	OBJECT(object)->x = t1;
	t2 = OBJECT(object_3)->y;
	OBJECT(object)->y = t2;
	z = OBJECT(object_3)->z;
	t3 = z + 0x3Cu;
	OBJECT(object)->z = t3;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_object_2 = object_3;
}

/* Carried (state 1): lets go when its goon is hurt (state 4); the goon also lets go of it on its own. */
uint16_t goon_balloon_carried(uint16_t object)
{
	uint16_t object_2 = 0;
	uint8_t state = 0, state_2 = 0;
	uint16_t parent = 0;

	parent = OBJECT(object)->parent;
	object_2 = parent;
	state = OBJECT(object_2)->state;
	if (state == 4u)
	{
		state_2 = OBJECT(object)->state;
		OBJECT(object)->state = state_2 + 1u;
	}
	return object_2;
}

/* Let go (state 2): starts rising. */
void goon_balloon_let_go(uint16_t object)
{
	uint8_t state = 0;

	OBJECT(object)->z_speed = 0x100;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Rising (state 3), faster and faster, until gone at F0 high. */
void goon_balloon_rise(uint16_t object)
{
	uint16_t z_speed = 0, z = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed + 4u;
	z = OBJECT(object)->z;
	if (z >= 0xF0u)
		OBJECT(object)->flags = 0u;
}

/* Its state 0: a goon with its balloon (straight to choosing when there is no room for one), animation
   B0, at the x and x speed goon_descent_starts gives, coming down for 68 frames. */
void goon_descent_set_up(uint16_t object, uint16_t *p_child_record, uint16_t *p_balloon)
{
	uint32_t carry = 0;
	uint16_t balloon = 0, child_record = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t t1 = 0, x_speed = 0;

	vector_goon_setup(object, &ignored16, &ignored16_2);
	child_record = goon_descent_child_ADDRESS;
	vector_spawn_child(object, child_record, &balloon, &ignored16_3, &carry);
	if (carry)
	{
		OBJECT(object)->goon_descent.balloon = balloon;
		OBJECT(object)->animation = 0xB0u;
		OBJECT(object)->timer = 0x68u;
		parameter = OBJECT(object)->parameter;
		balloon = goon_descent_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
		t1 = DESCENT_START(balloon)->x;
		OBJECT(object)->x = t1;
		x_speed = DESCENT_START(balloon)->x_speed;
		OBJECT(object)->x_speed = x_speed;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->flags = 0xC8u;
		OBJECT(object)->z_speed = -0x200;
		OBJECT(object)->floor_z = 0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
	else
	{
		OBJECT(object)->timer = 0u;
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->state = 2u;
	}
	*p_child_record = child_record;
	*p_balloon = balloon;
}

/* Its entrance (state 1): runs its step (field 29) and faces the way it moves. */
void goon_descent_step(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	step_handlers = goon_descent_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		step_handlers = goon_descent_float(object, step_handlers);
		break;
	case 2:
		step_handlers = goon_descent_land(object, step_handlers);
		break;
	case -112:
	case -100:
	case -88:
	case -76:
	case -64:
	case -8:
	case 48:
	case 68:
	case 80:
	case 96:
	case 108:
	case 124:
		vector_enemy_think(object, &y, &step_handlers, &ignored);
		break;
	case -110:
	case -98:
	case -86:
	case -74:
	case -62:
	case -6:
	case 50:
	case 70:
	case 82:
	case 98:
	case 110:
	case 126:
		vector_enemy_act(object, &y, &step_handlers, &ignored);
		break;
	case -108:
	case -84:
	case -72:
	case -60:
	case -4:
	case 52:
	case 72:
	case 84:
	case 100:
	case 112:
		vector_enemy_react(object, &y, &step_handlers, &ignored);
		break;
	case -106:
	case -94:
	case -82:
	case -70:
	case -58:
	case -2:
	case 54:
	case 74:
	case 86:
	case 102:
	case 114:
		vector_enemy_climb(object, &y, &step_handlers, &ignored);
		break;
	case -12:
		goon_descent_set_up(object, &y, &step_handlers);
		break;
	case -10:
		goon_descent_step(object, &y, &step_handlers);
		break;
	}
	vector_face_direction(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Comes down with the floor's height under it kept; after its time lets go of the balloon (animation
   A8). */
uint16_t goon_descent_float(uint16_t object, uint16_t object_2)
{
	uint32_t negative = 0, carry = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t timer = 0, action_step = 0;
	uint16_t balloon = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		balloon = OBJECT(object)->goon_descent.balloon;
		object_2 = balloon;
		OBJECT(object_2)->state = 2u;
		OBJECT(object)->animation = 0xA8u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	carry = vector_check_landing(object);
	return object_2;
}

/* Falls with gravity; landing, takes its nearest player and goes to choosing. */
uint16_t goon_descent_land(uint16_t object, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t direction = 0, nearest_player = 0;
	uint8_t target_direction = 0;

	vector_apply_gravity(object, &direction, &carry);
	if (carry == 0u)
		return u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	target_direction = OBJECT(object)->target_direction;
	direction = (direction & 0xFFu) | ((uint32_t)target_direction << 8);
	nearest_player = vector_set_walk_speed_by_direction(object, nearest_player, direction);
	vector_face_direction(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return nearest_player;
}

/* Its state 0: a goon with a hat with hit box 79BE. */
void hat_goon_run_across_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t box = 0, ignored16 = 0, u = 0;
	uint8_t state = 0;

	hat_goon_set_up(object, &ignored16, &u);
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	box = hat_goon_entrance_box_ADDRESS;
	vector_set_hit_box(object, box);
	*p_y = box;
	*p_u = u;
}

/* Its entrance (state 1): runs its step and takes the floor's priority and height under it. */
void hat_goon_run_across_step(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	step_handlers = hat_goon_run_across_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		hat_goon_run_across_pose(object);
		break;
	case 2:
		hat_goon_run_across_wait(object);
		break;
	case 4:
		hat_goon_run_across_run(object);
		break;
	case 6:
		hat_goon_run_across_running();
		break;
	case 8:
		umbrella_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case 10:
	case 38:
	case 50:
		goon_rush_in_step(object, &y, &step_handlers);
		break;
	case -120:
	case -64:
	case -8:
	case 12:
	case 24:
	case 40:
	case 52:
	case 68:
	case 94:
		vector_enemy_think(object, &y, &step_handlers, &ignored);
		break;
	case -118:
	case -62:
	case -6:
	case 14:
	case 26:
	case 42:
	case 54:
	case 70:
	case 96:
		vector_enemy_act(object, &y, &step_handlers, &ignored);
		break;
	case -128:
	case -116:
	case -60:
	case -4:
	case 16:
	case 28:
	case 44:
	case 56:
	case 72:
	case 98:
		vector_enemy_react(object, &y, &step_handlers, &ignored);
		break;
	case -126:
	case -114:
	case -58:
	case -2:
	case 18:
	case 30:
	case 46:
	case 58:
	case 74:
	case 100:
		vector_enemy_climb(object, &y, &step_handlers, &ignored);
		break;
	case 20:
		shovel_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case 22:
		shovel_goon_rush_in_step(object, &y, &step_handlers);
		break;
	case 32:
		shovel_goon_rush_in_start(object);
		break;
	case 34:
		y = shovel_goon_rush_in_swing(object);
		break;
	case 36:
		goon_striker_rush_in_set_up(object, &y, &step_handlers);
		break;
	case 48:
		goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case 60:
		goon_rush_in_start(object);
		break;
	case 62:
		step_handlers = goon_rush_in_run(object, step_handlers);
		break;
	case 64:
		goon_from_back_set_up(object, &y, &step_handlers);
		break;
	case 66:
		goon_from_back_step(object, &y, &step_handlers);
		break;
	case 76:
		step_handlers = goon_from_back_place(object);
		break;
	case 78:
		step_handlers = goon_from_back_reach_floor(object, step_handlers);
		break;
	case 80:
		step_handlers = goon_from_back_wait(object, step_handlers);
		break;
	case -12:
		hat_goon_run_across_set_up(object, &y, &step_handlers);
		break;
	case -10:
		hat_goon_run_across_step(object, &y, &step_handlers);
		break;
	}
	goon_follow_floor(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Step 0: animation A2. */
void hat_goon_run_across_pose(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->animation = 0xA2u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 1: keeps its animation going until it is left of x 0100. */
void hat_goon_run_across_wait(uint16_t object)
{
	uint8_t animation = 0, action_step = 0;
	uint16_t t1 = 0;

	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = animation | 0x80u;
	t1 = OBJECT(object)->x;
	if (t1 < 0x100u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 2: at the animation's end runs right (animation 90). */
void hat_goon_run_across_run(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
	{
		hat_goon_run_across_running();
		return;
	}
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->animation = 0x90u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	face_movement(object);
}

/* Step 3: keeps running until it leaves the screen. */
void hat_goon_run_across_running(void)
{
}

/* Its state 0: a goon with an umbrella that will run the frames its spawn gives. */
void umbrella_goon_rush_in_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t parameter = 0, state = 0;

	umbrella_goon_set_up(object, &y, &u);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_u = u;
}

/* Its state 0: a goon with a shovel (animation A4) that will charge the frames its spawn gives. */
void shovel_goon_rush_in_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t parameter = 0, state = 0;

	shovel_goon_set_up(object, &y, &u);
	OBJECT(object)->animation = 0xA4u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_u = u;
}

/* Its entrance (state 1): runs its step and takes the floor's priority and height under it. */
void shovel_goon_rush_in_step(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	step_handlers = shovel_goon_rush_in_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		shovel_goon_rush_in_start(object);
		break;
	case 2:
		y = shovel_goon_rush_in_swing(object);
		break;
	case 4:
		goon_striker_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -22:
	case 6:
	case 18:
		goon_rush_in_step(object, &y, &step_handlers);
		break;
	case -96:
	case -40:
	case -20:
	case -8:
	case 8:
	case 20:
	case 36:
	case 62:
	case 96:
		vector_enemy_think(object, &y, &step_handlers, &ignored);
		break;
	case -94:
	case -38:
	case -18:
	case -6:
	case 10:
	case 22:
	case 38:
	case 64:
	case 98:
		vector_enemy_act(object, &y, &step_handlers, &ignored);
		break;
	case -92:
	case -36:
	case -16:
	case -4:
	case 12:
	case 24:
	case 40:
	case 66:
	case 100:
		vector_enemy_react(object, &y, &step_handlers, &ignored);
		break;
	case -90:
	case -34:
	case -14:
	case -2:
	case 14:
	case 26:
	case 42:
	case 68:
	case 102:
		vector_enemy_climb(object, &y, &step_handlers, &ignored);
		break;
	case 16:
		goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case 28:
		goon_rush_in_start(object);
		break;
	case 30:
		step_handlers = goon_rush_in_run(object, step_handlers);
		break;
	case 32:
		goon_from_back_set_up(object, &y, &step_handlers);
		break;
	case 34:
		goon_from_back_step(object, &y, &step_handlers);
		break;
	case 44:
		step_handlers = goon_from_back_place(object);
		break;
	case 46:
		step_handlers = goon_from_back_reach_floor(object, step_handlers);
		break;
	case 48:
		step_handlers = goon_from_back_wait(object, step_handlers);
		break;
	case -44:
		hat_goon_run_across_set_up(object, &y, &step_handlers);
		break;
	case -42:
		hat_goon_run_across_step(object, &y, &step_handlers);
		break;
	case -32:
		hat_goon_run_across_pose(object);
		break;
	case -30:
		hat_goon_run_across_wait(object);
		break;
	case -28:
		hat_goon_run_across_run(object);
		break;
	case -26:
		hat_goon_run_across_running();
		break;
	case -24:
		umbrella_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -12:
		shovel_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -10:
		shovel_goon_rush_in_step(object, &y, &step_handlers);
		break;
	}
	goon_follow_floor(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Step 0: runs toward its target. */
void shovel_goon_rush_in_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* Step 1: runs with its shovel's hit box (79C6) on one frame in four; after its time takes its body's
   hit box and goes to choosing. */
uint16_t shovel_goon_rush_in_swing(uint16_t object)
{
	uint16_t box = 0;
	uint8_t timer = 0, timer_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		timer_2 = OBJECT(object)->timer;
		if ((timer_2 & 3u) != 0u)
		{
			box = goon_entrance_body_box_ADDRESS;
			vector_set_hit_box(object, box);
			return box;
		}
		box = shovel_goon_rush_in_swing_box_ADDRESS;
		vector_set_hit_box(object, box);
		return box;
	}
	box = goon_entrance_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return box;
}

/* Its state 0: a striker goon that will run the frames its spawn gives. */
void goon_striker_rush_in_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_behaviour)
{
	uint16_t behaviour = 0, y = 0;
	uint8_t parameter = 0, state = 0;

	goon_striker_set_up(object, &y, &behaviour);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_behaviour = behaviour;
}

/* Its state 0: a goon that will run the frames its spawn gives. */
void goon_rush_in_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t parameter = 0, state = 0;

	vector_goon_setup(object, &y, &u);
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	*p_y = y;
	*p_u = u;
}

/* The rush in (state 1): runs its step and takes the floor's priority and height under it. */
void goon_rush_in_step(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	step_handlers = goon_rush_in_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_rush_in_start(object);
		break;
	case 2:
		step_handlers = goon_rush_in_run(object, step_handlers);
		break;
	case 4:
		goon_from_back_set_up(object, &y, &step_handlers);
		break;
	case 6:
		goon_from_back_step(object, &y, &step_handlers);
		break;
	case -124:
	case -68:
	case -48:
	case -36:
	case -20:
	case -8:
	case 8:
	case 34:
	case 68:
	case 110:
		vector_enemy_think(object, &y, &step_handlers, &ignored);
		break;
	case -122:
	case -66:
	case -46:
	case -34:
	case -18:
	case -6:
	case 10:
	case 36:
	case 70:
	case 112:
		vector_enemy_act(object, &y, &step_handlers, &ignored);
		break;
	case -120:
	case -64:
	case -44:
	case -32:
	case -16:
	case -4:
	case 12:
	case 38:
	case 72:
	case 114:
		vector_enemy_react(object, &y, &step_handlers, &ignored);
		break;
	case -118:
	case -62:
	case -42:
	case -30:
	case -14:
	case -2:
	case 14:
	case 40:
	case 74:
	case 116:
		vector_enemy_climb(object, &y, &step_handlers, &ignored);
		break;
	case 16:
		step_handlers = goon_from_back_place(object);
		break;
	case 18:
		step_handlers = goon_from_back_reach_floor(object, step_handlers);
		break;
	case 20:
		step_handlers = goon_from_back_wait(object, step_handlers);
		break;
	case -72:
		hat_goon_run_across_set_up(object, &y, &step_handlers);
		break;
	case -70:
		hat_goon_run_across_step(object, &y, &step_handlers);
		break;
	case -60:
		hat_goon_run_across_pose(object);
		break;
	case -58:
		hat_goon_run_across_wait(object);
		break;
	case -56:
		hat_goon_run_across_run(object);
		break;
	case -54:
		hat_goon_run_across_running();
		break;
	case -52:
		umbrella_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -50:
	case -22:
	case -10:
		goon_rush_in_step(object, &y, &step_handlers);
		break;
	case -40:
		shovel_goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -38:
		shovel_goon_rush_in_step(object, &y, &step_handlers);
		break;
	case -28:
		shovel_goon_rush_in_start(object);
		break;
	case -26:
		y = shovel_goon_rush_in_swing(object);
		break;
	case -24:
		goon_striker_rush_in_set_up(object, &y, &step_handlers);
		break;
	case -12:
		goon_rush_in_set_up(object, &y, &step_handlers);
		break;
	}
	goon_follow_floor(object);
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Step 0: runs (animation 90) toward its target. */
void goon_rush_in_start(uint16_t object)
{
	uint8_t target_direction = 0, action_step = 0;
	uint16_t x_speed = 0;

	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	target_direction = OBJECT(object)->target_direction;
	if ((int8_t)(target_direction - 0x40u) >= 0)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	vector_face_direction(object);
}

/* Step 1: after its time takes its nearest player and goes to choosing. */
uint16_t goon_rush_in_run(uint16_t object, uint16_t u)
{
	uint16_t direction = 0, nearest_player = 0;
	uint8_t timer = 0, target_direction = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return u;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	target_direction = OBJECT(object)->target_direction;
	direction = (uint32_t)target_direction << 8;
	nearest_player = vector_set_walk_speed_by_direction(object, nearest_player, direction);
	vector_face_direction(object);
	OBJECT(object)->state = 2u;
	OBJECT(object)->timer = 0u;
	return nearest_player;
}

/* Its state 0: a goon (animation 83), shown but not to be hit, behind the layers' front (priority 10),
   facing its nearest player. */
void goon_from_back_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t state = 0, attributes = 0;

	vector_goon_setup(object, &y, &ignored16);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->animation = 0x83u;
	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	vector_face_direction(object);
	*p_y = y;
	*p_u = u;
}

/* Its entrance (state 1): runs its step. */
void goon_from_back_step(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t step_handlers = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		step_handlers = goon_from_back_steps_ADDRESS;
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			step_handlers = goon_from_back_place(object);
			break;
		case 2:
			step_handlers = goon_from_back_reach_floor(object, step_handlers);
			break;
		case 4:
			step_handlers = goon_from_back_wait(object, step_handlers);
			break;
		case -84:
		case -64:
		case -52:
		case -36:
		case -24:
		case -8:
		case 18:
		case 52:
		case 94:
			vector_enemy_think(object, &y, &step_handlers, &ignored);
			break;
		case -82:
		case -62:
		case -50:
		case -34:
		case -22:
		case -6:
		case 20:
		case 54:
		case 96:
			vector_enemy_act(object, &y, &step_handlers, &ignored);
			break;
		case -80:
		case -60:
		case -48:
		case -32:
		case -20:
		case -4:
		case 22:
		case 56:
		case 98:
			vector_enemy_react(object, &y, &step_handlers, &ignored);
			break;
		case -78:
		case -58:
		case -46:
		case -30:
		case -18:
		case -2:
		case 24:
		case 58:
		case 100:
			vector_enemy_climb(object, &y, &step_handlers, &ignored);
			break;
		case -88:
			hat_goon_run_across_set_up(object, &y, &step_handlers);
			break;
		case -86:
			hat_goon_run_across_step(object, &y, &step_handlers);
			break;
		case -76:
			hat_goon_run_across_pose(object);
			break;
		case -74:
			hat_goon_run_across_wait(object);
			break;
		case -72:
			hat_goon_run_across_run(object);
			break;
		case -70:
			hat_goon_run_across_running();
			break;
		case -68:
			umbrella_goon_rush_in_set_up(object, &y, &step_handlers);
			break;
		case -66:
		case -38:
		case -26:
			goon_rush_in_step(object, &y, &step_handlers);
			break;
		case -56:
			shovel_goon_rush_in_set_up(object, &y, &step_handlers);
			break;
		case -54:
			shovel_goon_rush_in_step(object, &y, &step_handlers);
			break;
		case -44:
			shovel_goon_rush_in_start(object);
			break;
		case -42:
			y = shovel_goon_rush_in_swing(object);
			break;
		case -40:
			goon_striker_rush_in_set_up(object, &y, &step_handlers);
			break;
		case -28:
			goon_rush_in_set_up(object, &y, &step_handlers);
			break;
		case -16:
			goon_rush_in_start(object);
			break;
		case -14:
			step_handlers = goon_rush_in_run(object, step_handlers);
			break;
		case -12:
			goon_from_back_set_up(object, &y, &step_handlers);
			break;
		case -10:
			continue;
		}
		break;
	}
	*p_y = y;
	*p_step_handlers = step_handlers;
}

/* Step 0: at the x goon_from_back_xs gives, at the back (y 50), coming forward. */
uint16_t goon_from_back_place(uint16_t object)
{
	uint16_t start_xs = 0;
	uint8_t parameter = 0, action_step = 0;
	uint16_t t1 = 0;

	start_xs = goon_from_back_xs_ADDRESS;
	parameter = OBJECT(object)->parameter;
	t1 = goon_from_back_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = t1;
	OBJECT(object)->y = 0x50u;
	OBJECT(object)->y_speed = 0x100;
	OBJECT(object)->parameter = 0u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return start_xs;
}

/* Step 1: once there is floor under it, takes its height and can be hit; waits 40 frames. */
uint16_t goon_from_back_reach_floor(uint16_t object, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, target = 0;
	uint8_t action_step = 0;
	uint16_t target_2 = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->next_floor_cell = floor_value;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->timer = 0x40u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	if ((frame_count & 7u) != 0u)
		return u;
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	vector_face_direction(object);
	return target;
}

/* Step 2: waits facing its target (checked every 8 frames), then goes to choosing. */
uint16_t goon_from_back_wait(uint16_t object, uint16_t u)
{
	uint16_t target = 0;
	uint8_t timer = 0, state = 0;
	uint16_t target_2 = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
	{
		if ((frame_count & 7u) != 0u)
			return u;
		target_2 = OBJECT(object)->target;
		target = target_2;
		vector_measure_target(object, target);
		vector_face_direction(object);
		return target;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return u;
}

/* Its state 0: a goon with a hat (animation B7) with the x the scroll must bring it in at, its
   attributes and its flags from waiting_hat_goon_starts. */
uint16_t hat_goon_waiting_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, waiting_hat_goon_start = 0, y = 0;
	uint8_t parameter = 0, attributes = 0, parameter_2 = 0, flags = 0, state = 0;
	uint16_t trigger_x = 0;

	hat_goon_set_up(object, &y, &ignored16);
	OBJECT(object)->animation = 0xB7u;
	parameter = OBJECT(object)->parameter;
	waiting_hat_goon_start = waiting_hat_goon_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	trigger_x = WAITING_HAT_GOON_START(waiting_hat_goon_start)->trigger_x;
	OBJECT(object)->hat_goon_waiting.trigger_x = trigger_x;
	attributes = WAITING_HAT_GOON_START(waiting_hat_goon_start)->attributes;
	OBJECT(object)->attributes = attributes;
	parameter_2 = OBJECT(object)->parameter;
	flags = WAITING_HAT_GOON_START(waiting_hat_goon_start)->flags;
	OBJECT(object)->hat_goon_waiting.start_flags = (parameter_2 & 0x80u) | flags;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t hat_goon_waiting_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		return hat_goon_waiting_show(object, y);
	case 2:
		hat_goon_waiting_for_scroll(object);
		return y;
	case 4:
		return hat_goon_waiting_step_forward(object, y);
	case 6:
	case 48:
	case 82:
	case 102:
		goon_reach_floor_level(object);
		return y;
	case 8:
	case 50:
	case 84:
		goon_entrance_end(object);
		return y;
	case 10:
		return goon_walk_in_set_up(object);
	case 12:
		return goon_walk_in_step(object, y);
	case -122:
	case -102:
	case -90:
	case -74:
	case -62:
	case -46:
	case -20:
	case 14:
	case 56:
	case 90:
	case 112:
	case 124:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -120:
	case -100:
	case -88:
	case -72:
	case -60:
	case -44:
	case -18:
	case 16:
	case 58:
	case 92:
	case 114:
	case 126:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -118:
	case -98:
	case -86:
	case -70:
	case -58:
	case -42:
	case -16:
	case 18:
	case 60:
	case 94:
	case 116:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -116:
	case -96:
	case -84:
	case -68:
	case -56:
	case -40:
	case -14:
	case 20:
	case 62:
	case 96:
	case 118:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: shown at once when its flags' bit 7 says so; without bit 0, hit box 79BE and animation A2. */
uint16_t hat_goon_waiting_show(uint16_t object, uint16_t box)
{
	uint8_t entrance_flags = 0;
	uint8_t start_flags = 0, action_step = 0;

	start_flags = OBJECT(object)->hat_goon_waiting.start_flags;
	entrance_flags = start_flags;
	if ((int8_t)start_flags < 0)
		OBJECT(object)->flags = 0x80u;
	if (entrance_flags & 1u)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
		return box;
	}
	box = hat_goon_entrance_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->animation = 0xA2u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Step 1: waits until the scroll brings it left of its x; hit meanwhile, takes animation A0 and steps
   forward. */
void hat_goon_waiting_for_scroll(uint16_t object)
{
	uint8_t start_flags = 0, animation = 0, action_step = 0;
	uint16_t t1 = 0, trigger_x = 0;

	start_flags = OBJECT(object)->hat_goon_waiting.start_flags;
	if ((start_flags & 1u) == 0u)
	{
		animation = OBJECT(object)->animation;
		OBJECT(object)->animation = animation | 0x80u;
	}
	t1 = OBJECT(object)->x;
	trigger_x = OBJECT(object)->hat_goon_waiting.trigger_x;
	if (t1 < trigger_x)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->animation = 0xA0u;
		OBJECT(object)->action_step = 2u;
	}
}

/* Step 2: at the animation's end takes its body's hit box and walks (animation 91) right and up toward
   the floor. */
uint16_t hat_goon_waiting_step_forward(uint16_t object, uint16_t box)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return box;
	box = goon_entrance_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->animation = 0x91u;
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->y_speed = -0x100;
	OBJECT(object)->timer = 8u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return box;
}

/* Its state 0: a hidden goon (animation 02) with its priority, the way it will walk, the x the scroll
   must bring it in at and its two waits from goon_walk_in_starts. */
uint16_t goon_walk_in_set_up(uint16_t object)
{
	uint8_t attributes = 0, trigger_x_high = 0, trigger_x_low = 0;
	uint16_t goon_walk_in_start = 0, setup = 0, y = 0;
	uint8_t parameter = 0, attributes_2 = 0, attributes_3 = 0, attributes_4 = 0, state = 0;
	uint16_t flags = 0, t1 = 0, wait = 0;

	setup = goon_walk_in_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	OBJECT(object)->flags = 8u;
	OBJECT(object)->enemy_class = 1;
	parameter = OBJECT(object)->parameter;
	goon_walk_in_start = goon_walk_in_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	priority_bits = GOON_WALK_IN_START(goon_walk_in_start)->flags & 0x30u;
	attributes_2 = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes_2 & 0xCFu) | priority_bits;
	flags = (((uint32_t)GOON_WALK_IN_START(goon_walk_in_start)->flags << 8u) | GOON_WALK_IN_START(goon_walk_in_start)->trigger_x);
	OBJECT(object)->retarget_time = (flags >> 8) & 0x80u;
	t1 = (flags & 0xFFu) << 4;
	trigger_x_low = (uint8_t)t1;
	trigger_x_high = (uint8_t)(t1 >> 8);
	OBJECT(object)->goon.trigger_x = ((uint32_t)trigger_x_high << 8) | (trigger_x_low & 0xFFu);
	if ((uint16_t)(((uint32_t)trigger_x_high << 8) | (trigger_x_low & 0xFFu)) >= 0x100u)
	{
		attributes_3 = OBJECT(object)->attributes;
		attributes = attributes_3 | 0x40u;
	}
	else
	{
		attributes_4 = OBJECT(object)->attributes;
		attributes = attributes_4 & 0xBFu;
	}
	OBJECT(object)->attributes = attributes;
	wait = (((uint32_t)GOON_WALK_IN_START(goon_walk_in_start)->wait << 8u) | GOON_WALK_IN_START(goon_walk_in_start)->floor_wait);
	OBJECT(object)->goon.entrance_wait = wait >> 8;
	OBJECT(object)->timer = wait;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_walk_in_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_walk_in_wait_for_scroll(object);
		return y;
	case 2:
		goon_walk_in_go(object);
		return y;
	case -38:
	case 4:
	case 38:
	case 58:
	case 122:
		goon_reach_floor_level(object);
		return y;
	case -36:
	case 6:
	case 40:
	case 124:
		goon_entrance_end(object);
		return y;
	case 8:
		return goon_delayed_set_up(object);
	case 10:
		return goon_delayed_step(object, y);
	case -118:
	case -106:
	case -90:
	case -64:
	case -30:
	case 12:
	case 46:
	case 68:
	case 80:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -116:
	case -104:
	case -88:
	case -62:
	case -28:
	case 14:
	case 48:
	case 70:
	case 82:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -114:
	case -102:
	case -86:
	case -60:
	case -26:
	case 16:
	case 50:
	case 72:
	case 84:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -128:
	case -112:
	case -100:
	case -84:
	case -58:
	case -24:
	case 18:
	case 52:
	case 74:
	case 86:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: shown once the scroll brings it left of its x. */
void goon_walk_in_wait_for_scroll(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t t1 = 0, trigger_x = 0;

	t1 = OBJECT(object)->x;
	trigger_x = OBJECT(object)->goon.trigger_x;
	if (t1 < trigger_x)
	{
		OBJECT(object)->flags = 0x80u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 1: after its wait takes its nearest player and walks at a slant (direction 20, or E0 when its
   start's bit 7 says so). */
void goon_walk_in_go(uint16_t object)
{
	uint8_t angle = 0;
	uint16_t heading = 0, nearest_player = 0;
	uint8_t entrance_wait = 0, retarget_time = 0, action_step = 0;

	entrance_wait = OBJECT(object)->goon.entrance_wait;
	OBJECT(object)->goon.entrance_wait = entrance_wait - 1u;
	if (entrance_wait != 1u)
		return;
	nearest_player = vector_choose_nearest_player(object);
	vector_measure_target(object, nearest_player);
	retarget_time = OBJECT(object)->retarget_time;
	if ((int8_t)retarget_time >= 0)
		angle = 0x20u;
	else
		angle = 0xE0u;
	heading = ((uint32_t)angle << 8) | 0x40u;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* An entrance's step: once over floor at height 0, takes its floor cell, priority and height and goes
   on. */
void goon_reach_floor_level(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0 && (floor_value & 0xFu) == 0u)
	{
		cell_seen = floor_value;
		OBJECT(object)->next_floor_cell = floor_value;
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* An entrance's last step: after its wait can be hit, stops and goes to choosing (state 2). */
void goon_entrance_end(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Its state 0: a hidden goon (animation 82) with its wait, its wait on the floor, and the direction and
   speed it will come in by from delayed_goon_starts. */
uint16_t goon_delayed_set_up(uint16_t object)
{
	uint16_t delayed_start = 0, ignored16 = 0, y = 0;
	uint8_t state = 0, attributes = 0, parameter = 0;
	uint16_t wait = 0, direction = 0;

	vector_goon_setup(object, &y, &ignored16);
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->animation = 0x82u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->flags = 8u;
	parameter = OBJECT(object)->parameter;
	delayed_start = delayed_goon_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	wait = (((uint32_t)DELAYED_START(delayed_start)->wait << 8u) | DELAYED_START(delayed_start)->floor_wait);
	OBJECT(object)->goon_delayed.entrance_wait = wait >> 8;
	OBJECT(object)->timer = wait;
	direction = (((uint32_t)DELAYED_START(delayed_start)->direction << 8u) | DELAYED_START(delayed_start)->speed);
	OBJECT(object)->goon_delayed.heading = direction;
	OBJECT(object)->parameter = 0u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_delayed_step(uint16_t object, uint16_t y)
{
	uint32_t zero = 0, negative = 0;
	uint16_t hitter = 0, ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, t1 = 0;

	hitter = goon_delayed_steps_ADDRESS;
	action_step = OBJECT(object)->action_step;
	t1 = (uint32_t)action_step << 1;
	negative = t1 >> 7;
	zero = t1 == 0u;
	switch ((int8_t)t1)
	{
	case 0:
		goon_delayed_start(object);
		return y;
	case -74:
	case -32:
	case 2:
	case 22:
	case 86:
		goon_reach_floor_level(object);
		return y;
	case -72:
	case -30:
	case 4:
	case 88:
	case 108:
		goon_entrance_end(object);
		return y;
	case 6:
		return shovel_goon_step_out_set_up(object);
	case 8:
		return shovel_goon_step_out_step(object, y);
	case -126:
	case -100:
	case -66:
	case -24:
	case 10:
	case 32:
	case 44:
	case 94:
	case 114:
	case 126:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -124:
	case -98:
	case -64:
	case -22:
	case 12:
	case 34:
	case 46:
	case 96:
	case 116:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -122:
	case -96:
	case -62:
	case -20:
	case 14:
	case 36:
	case 48:
	case 98:
	case 118:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -120:
	case -94:
	case -60:
	case -18:
	case 16:
	case 38:
	case 50:
	case 100:
	case 120:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	case 18:
		shovel_goon_step_out_show(object);
		return y;
	case 20:
		shovel_goon_step_out_walk(object);
		return y;
	case 24:
		shovel_goon_step_out_pause(object);
		return y;
	case 26:
		shovel_goon_step_out_arm(object);
		return y;
	case 28:
		return hat_goon_step_out_set_up(object);
	case 30:
	case 42:
		return goon_step_out_step(object, y);
	case 40:
	case 90:
		return goon_step_out_set_up(object);
	case -14:
	case -10:
	case -6:
	case -2:
		enemy_set_knock_direction(object, hitter, zero, negative);
		return y;
	}
	unreachable();
}

/* Step 0: after its wait shown, moving by its direction and speed. */
void goon_delayed_start(uint16_t object)
{
	uint16_t heading = 0;
	uint8_t entrance_wait = 0, action_step = 0;
	uint16_t heading_2 = 0;

	entrance_wait = OBJECT(object)->goon_delayed.entrance_wait;
	OBJECT(object)->goon_delayed.entrance_wait = entrance_wait - 1u;
	if (entrance_wait != 1u)
		return;
	OBJECT(object)->flags = 0x80u;
	heading_2 = OBJECT(object)->goon_delayed.heading;
	heading = heading_2;
	vector_set_speed_by_direction(object, heading);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Its state 0: set up as a goon with a shovel but shown in the plain goon's set (animation A2), hidden,
   with its entrance pose's wait and attributes from goon_entrances. */
uint16_t shovel_goon_step_out_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t enemy_class = 0, parameter = 0, state = 0;
	uint16_t wait = 0;

	shovel_goon_set_up(object, &y, &ignored16);
	OBJECT(object)->kind = 0x80u;
	OBJECT(object)->animation = 0xA2u;
	OBJECT(object)->flags = 8u;
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class + 1u;
	parameter = OBJECT(object)->parameter;
	wait = (((uint32_t)GOON_ENTRANCE(goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->wait << 8u) | GOON_ENTRANCE(goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->attributes);
	OBJECT(object)->shovel_goon.entrance_wait = wait >> 8;
	OBJECT(object)->attributes = wait;
	OBJECT(object)->timer = 8u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t shovel_goon_step_out_step(uint16_t object, uint16_t y)
{
	uint32_t zero = 0, negative = 0;
	uint16_t hitter = 0, ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0, t1 = 0;

	for (;;)
	{
		hitter = shovel_goon_step_out_steps_ADDRESS;
		action_step = OBJECT(object)->action_step;
		t1 = (uint32_t)action_step << 1;
		negative = t1 >> 7;
		zero = t1 == 0u;
		switch ((int8_t)t1)
		{
		case 0:
			shovel_goon_step_out_show(object);
			return y;
		case 2:
			shovel_goon_step_out_walk(object);
			return y;
		case -92:
		case -50:
		case -16:
		case 4:
		case 68:
			goon_reach_floor_level(object);
			return y;
		case 6:
			shovel_goon_step_out_pause(object);
			return y;
		case 8:
			shovel_goon_step_out_arm(object);
			return y;
		case 10:
			return hat_goon_step_out_set_up(object);
		case 12:
		case 24:
			return goon_step_out_step(object, y);
		case -118:
		case -84:
		case -42:
		case -8:
		case 14:
		case 26:
		case 76:
		case 96:
		case 108:
			vector_enemy_think(object, &y, &ignored16, &ignored);
			return y;
		case -116:
		case -82:
		case -40:
		case -6:
		case 16:
		case 28:
		case 78:
		case 98:
		case 110:
			vector_enemy_act(object, &y, &ignored16, &ignored);
			return y;
		case -114:
		case -80:
		case -38:
		case -4:
		case 18:
		case 30:
		case 80:
		case 100:
		case 112:
			vector_enemy_react(object, &y, &ignored16, &ignored);
			return y;
		case -112:
		case -78:
		case -36:
		case -2:
		case 20:
		case 32:
		case 82:
		case 102:
		case 114:
			vector_enemy_climb(object, &y, &ignored16, &ignored);
			return y;
		case 22:
		case 72:
			break;
		case -90:
		case -48:
		case -14:
		case 70:
		case 90:
			goon_entrance_end(object);
			return y;
		case -32:
		case -28:
		case -24:
		case -20:
			enemy_set_knock_direction(object, hitter, zero, negative);
			return y;
		case -18:
			goon_delayed_start(object);
			return y;
		case -12:
			return shovel_goon_step_out_set_up(object);
		case -10:
			continue;
		}
		break;
	}
	return goon_step_out_set_up(object);
}

/* Step 0: takes its nearest player and is shown, its animation started again. */
void shovel_goon_step_out_show(uint16_t object)
{
	uint8_t animation = 0, action_step = 0;

	vector_choose_nearest_player(object);
	OBJECT(object)->flags = 0x80u;
	animation = OBJECT(object)->animation;
	OBJECT(object)->animation = animation | 0x80u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 1: after its wait walks right and up. */
void shovel_goon_step_out_walk(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->shovel_goon.entrance_wait;
	OBJECT(object)->shovel_goon.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->x_speed = 0x80;
		OBJECT(object)->y_speed = -0x80;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 3: a wait of 4 frames once on the floor. */
void shovel_goon_step_out_pause(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->timer = 4u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 4: after its wait takes the shovel goon's set (kind 83), can be hit, stops and goes to choosing. */
void shovel_goon_step_out_arm(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->kind = 0x83u;
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Its state 0: a goon with a hat in its entrance pose. */
uint16_t hat_goon_step_out_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	hat_goon_set_up(object, &y, &ignored16);
	goon_take_entrance_pose(object);
	return y;
}

/* Its state 0: a goon in its entrance pose. */
uint16_t goon_step_out_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	vector_goon_setup(object, &y, &ignored16);
	goon_take_entrance_pose(object);
	return y;
}

/* Shown (animation 91) with the wait and sprite attributes goon_entrances gives by its spawn's field 30,
   then its entrance (state 1). */
void goon_take_entrance_pose(uint16_t object)
{
	uint8_t parameter = 0, state = 0;
	uint16_t wait = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->animation = 0x91u;
	parameter = OBJECT(object)->parameter;
	wait = (((uint32_t)GOON_ENTRANCE(goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->wait << 8u) | GOON_ENTRANCE(goon_entrances_ADDRESS + (int8_t)((uint32_t)parameter << 1))->attributes);
	OBJECT(object)->goon.entrance_wait = wait >> 8;
	OBJECT(object)->attributes = wait;
	OBJECT(object)->timer = 8u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Takes the priority and the height of the floor under it, where there is floor. */
void goon_follow_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		cell_seen = floor_value;
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
	}
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_step_out_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_step_out_check(object);
		return y;
	case 2:
		goon_step_out_pose(object);
		return y;
	case 4:
		goon_step_out_pose_end(object);
		return y;
	case 6:
	case 26:
		goon_walk_up_start(object);
		return y;
	case -110:
	case -76:
	case -56:
	case 8:
		goon_reach_floor_level(object);
		return y;
	case -108:
	case -74:
	case 10:
	case 30:
		goon_entrance_end(object);
		return y;
	case -38:
	case 12:
		return goon_step_out_set_up(object);
	case 14:
		return goon_walk_up_step(object, y);
	case -102:
	case -68:
	case -46:
	case -34:
	case 16:
	case 36:
	case 48:
	case 70:
	case 96:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -100:
	case -66:
	case -44:
	case -32:
	case 18:
	case 38:
	case 50:
	case 72:
	case 98:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -98:
	case -64:
	case -42:
	case -30:
	case 20:
	case 40:
	case 52:
	case 74:
	case 100:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -96:
	case -62:
	case -40:
	case -28:
	case 22:
	case 42:
	case 54:
	case 76:
	case 102:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	case 24:
		goon_walk_up_show(object);
		return y;
	case 28:
		goon_walk_up_reach_floor(object);
		return y;
	case 32:
		return goon_striker_from_side_set_up(object);
	case 34:
	case 46:
		return goon_from_side_step(object, y);
	case 44:
		return goon_from_side_set_up(object);
	}
	unreachable();
}

/* Step 0: with its spawn's bit 7 (the police car's doors) it strikes the pose, else it walks up at once. */
void goon_step_out_check(uint16_t object)
{
	uint8_t parameter = 0, action_step = 0;

	parameter = OBJECT(object)->parameter;
	if ((int8_t)parameter >= 0)
	{
		OBJECT(object)->action_step = 3u;
		return;
	}
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 1: after its wait shows animation B1. */
void goon_step_out_pose(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->goon.entrance_wait;
	OBJECT(object)->goon.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->animation = 0xB1u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 2: at the animation's end back to animation 91. */
void goon_step_out_pose_end(uint16_t object)
{
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		OBJECT(object)->goon.entrance_wait = 1u;
		OBJECT(object)->animation = 0x91u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* After its wait walks up the screen. */
void goon_walk_up_start(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->goon.entrance_wait;
	OBJECT(object)->goon.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->parameter = 0u;
		OBJECT(object)->y_speed = -0x100;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_walk_up_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			goon_walk_up_show(object);
			return y;
		case -18:
		case 2:
			goon_walk_up_start(object);
			return y;
		case 4:
			goon_walk_up_reach_floor(object);
			return y;
		case -98:
		case -14:
		case 6:
			goon_entrance_end(object);
			return y;
		case 8:
			return goon_striker_from_side_set_up(object);
		case 10:
		case 22:
			return goon_from_side_step(object, y);
		case -126:
		case -92:
		case -70:
		case -58:
		case -8:
		case 12:
		case 24:
		case 46:
		case 72:
		case 120:
			vector_enemy_think(object, &y, &ignored16, &ignored);
			return y;
		case -124:
		case -90:
		case -68:
		case -56:
		case -6:
		case 14:
		case 26:
		case 48:
		case 74:
		case 122:
			vector_enemy_act(object, &y, &ignored16, &ignored);
			return y;
		case -122:
		case -88:
		case -66:
		case -54:
		case -4:
		case 16:
		case 28:
		case 50:
		case 76:
		case 124:
			vector_enemy_react(object, &y, &ignored16, &ignored);
			return y;
		case -120:
		case -86:
		case -64:
		case -52:
		case -2:
		case 18:
		case 30:
		case 52:
		case 78:
		case 126:
			vector_enemy_climb(object, &y, &ignored16, &ignored);
			return y;
		case 20:
			break;
		case -100:
		case -80:
		case -16:
			goon_reach_floor_level(object);
			return y;
		case -62:
		case -12:
			return goon_step_out_set_up(object);
		case -24:
			goon_step_out_check(object);
			return y;
		case -22:
			goon_step_out_pose(object);
			return y;
		case -20:
			goon_step_out_pose_end(object);
			return y;
		case -10:
			continue;
		}
		break;
	}
	return goon_from_side_set_up(object);
}

/* Step 0: shown, behind the layers' front (priority 10). */
void goon_walk_up_show(uint16_t object)
{
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->attributes = 0x10u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 2: once over floor, takes its floor cell, priority and height and goes on. */
void goon_walk_up_reach_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		cell_seen = floor_value;
		OBJECT(object)->next_floor_cell = floor_value;
		priority_bits = floor_value & 0x30u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
		OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((cell_seen & 0xFu) << 1) << 1) << 1 & 0xFFu);
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Its state 0: a striker goon entering from the side. */
uint16_t goon_striker_from_side_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	goon_striker_set_up(object, &y, &ignored16);
	goon_from_side_place(object);
	return y;
}

/* Its state 0: a goon entering from the side. */
uint16_t goon_from_side_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	vector_goon_setup(object, &y, &ignored16);
	goon_from_side_place(object);
	return y;
}

/* Shown with the attributes and the wait on the floor goon_side_entries gives, 1 health with its spawn's
   bit 7, facing its nearest player; then its entrance. */
void goon_from_side_place(uint16_t object)
{
	uint16_t goon_side_entry = 0;
	uint8_t parameter = 0, attributes = 0, floor_wait = 0, parameter_2 = 0, state = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->floor_z = 0u;
	parameter = OBJECT(object)->parameter;
	goon_side_entry = goon_side_entries_ADDRESS + (int8_t)((uint32_t)parameter << 1);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x8Fu) | GOON_SIDE_ENTRY(goon_side_entry)->attributes;
	floor_wait = GOON_SIDE_ENTRY(goon_side_entry)->floor_wait;
	OBJECT(object)->timer = floor_wait;
	parameter_2 = OBJECT(object)->parameter;
	if ((int8_t)parameter_2 < 0)
		OBJECT(object)->vitality = 1u;
	vector_choose_nearest_player(object);
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_from_side_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_from_side_walk(object);
		return y;
	case 2:
	case 28:
		goon_reach_floor(object);
		return y;
	case 4:
	case 30:
		goon_wait_on_floor(object);
		return y;
	case 6:
		return goon_run_in_set_up(object);
	case 8:
		return goon_run_in_step(object, y);
	case -128:
	case -106:
	case -94:
	case -44:
	case -24:
	case -12:
	case 10:
	case 36:
	case 84:
	case 108:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -126:
	case -104:
	case -92:
	case -42:
	case -22:
	case -10:
	case 12:
	case 38:
	case 86:
	case 110:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -124:
	case -102:
	case -90:
	case -40:
	case -20:
	case -8:
	case 14:
	case 40:
	case 88:
	case 112:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -122:
	case -100:
	case -88:
	case -38:
	case -18:
	case -6:
	case 16:
	case 42:
	case 90:
	case 114:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: walks right (animation 81). */
void goon_from_side_walk(uint16_t object)
{
	uint8_t action_step = 0;

	vector_choose_nearest_player(object);
	OBJECT(object)->x_speed = 0x100;
	OBJECT(object)->animation = 0x81u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Its state 0: a hidden goon, not counted among the stage's enemies yet, with the x the scroll must
   bring it in at and its wait on the floor from goon_run_in_starts. */
uint16_t goon_run_in_set_up(uint16_t object)
{
	uint16_t goon_run_in_start = 0, ignored16 = 0, y = 0;
	uint8_t parameter = 0, parameter_2 = 0, floor_wait = 0, attributes = 0, state = 0;
	uint16_t t1 = 0;

	vector_goon_setup(object, &y, &ignored16);
	OBJECT(object)->flags = 4u;
	OBJECT(object)->floor_z = 0u;
	parameter = OBJECT(object)->parameter;
	if ((parameter & 1u) == 0u)
		OBJECT(object)->vitality = 1u;
	parameter_2 = OBJECT(object)->parameter;
	goon_run_in_start = goon_run_in_starts_ADDRESS + (int8_t)((uint32_t)parameter_2 << 1);
	t1 = (uint32_t)GOON_RUN_IN_START(goon_run_in_start)->trigger_x << 4;
	OBJECT(object)->goon.trigger_x = t1;
	floor_wait = GOON_RUN_IN_START(goon_run_in_start)->floor_wait;
	OBJECT(object)->timer = floor_wait;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x8Fu) | 0x20u;
	OBJECT(object)->enemy_class = -1;
	OBJECT(object)->entrance_pending = 0xFFu;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_run_in_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_run_in_go(object);
		return y;
	case -24:
	case 2:
		goon_reach_floor(object);
		return y;
	case -22:
	case 4:
		goon_wait_on_floor(object);
		return y;
	case 6:
		return hat_goon_jump_in_set_up(object);
	case 8:
		return hat_goon_jump_in_step(object, y);
	case -120:
	case -70:
	case -50:
	case -38:
	case -16:
	case 10:
	case 58:
	case 82:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -118:
	case -68:
	case -48:
	case -36:
	case -14:
	case 12:
	case 60:
	case 84:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -128:
	case -116:
	case -66:
	case -46:
	case -34:
	case -12:
	case 14:
	case 62:
	case 86:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -126:
	case -114:
	case -64:
	case -44:
	case -32:
	case -10:
	case 16:
	case 64:
	case 88:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: once the scroll brings it left of its x, counted among the enemies, shown and running right
   (animation 82). */
void goon_run_in_go(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t t1 = 0, trigger_x = 0;

	t1 = OBJECT(object)->x;
	trigger_x = OBJECT(object)->goon.trigger_x;
	if (trigger_x <= t1)
		return;
	OBJECT(object)->enemy_class = 1;
	OBJECT(object)->entrance_pending = 0u;
	OBJECT(object)->flags = 0x80u;
	vector_choose_nearest_player(object);
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->animation = 0x82u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* An entrance's step: once over floor, can be hit, behind the layers' front (priority 10), and goes on. */
void goon_reach_floor(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;

	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	if ((int8_t)floor_value >= 0)
	{
		OBJECT(object)->flags = 0xC0u;
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* An entrance's last step: stops after its wait on the floor and goes to choosing. */
void goon_wait_on_floor(uint16_t object)
{
	uint8_t timer = 0, state = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer == 1u)
	{
		OBJECT(object)->x_speed = 0;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Its state 0: a hidden goon with a hat (animation A2) with the x the scroll must bring it in at and its
   wait from hat_goon_jump_in_starts. */
uint16_t hat_goon_jump_in_set_up(uint16_t object)
{
	uint16_t hat_goon_jump_in_start = 0, ignored16 = 0, y = 0;
	uint8_t attributes = 0, entrance_pending = 0, enemy_class = 0, parameter = 0, state = 0;
	uint16_t trigger_x = 0, wait = 0;

	hat_goon_set_up(object, &y, &ignored16);
	OBJECT(object)->animation = 0xA2u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->flags = 8u;
	entrance_pending = OBJECT(object)->entrance_pending;
	OBJECT(object)->entrance_pending = entrance_pending + 1u;
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class + 1u;
	parameter = OBJECT(object)->parameter;
	hat_goon_jump_in_start = hat_goon_jump_in_starts_ADDRESS + (int8_t)(((uint32_t)parameter << 1) << 1);
	trigger_x = HAT_GOON_JUMP_IN_START(hat_goon_jump_in_start)->trigger_x;
	OBJECT(object)->hat_goon.trigger_x = trigger_x;
	wait = (((uint32_t)HAT_GOON_JUMP_IN_START(hat_goon_jump_in_start)->wait << 8u) | HAT_GOON_JUMP_IN_START(hat_goon_jump_in_start)->unused);
	OBJECT(object)->hat_goon.entrance_wait = wait >> 8;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t hat_goon_jump_in_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
	case 28:
		goon_wait_for_scroll(object);
		return y;
	case 2:
		hat_goon_jump_in_show(object);
		return y;
	case 4:
		hat_goon_jump_in_leap(object);
		return y;
	case 6:
		hat_goon_jump_in_fly(object);
		return y;
	case 8:
	case 32:
		goon_stop_and_fall(object);
		return y;
	case 10:
	case 34:
		goon_fall_to_floor(object);
		return y;
	case 12:
		return goon_drop_set_up(object);
	case 14:
		return goon_drop_step(object, y);
	case -112:
	case -92:
	case -80:
	case -58:
	case -32:
	case 16:
	case 40:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -110:
	case -90:
	case -78:
	case -56:
	case -30:
	case 18:
	case 42:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -108:
	case -88:
	case -76:
	case -54:
	case -28:
	case 20:
	case 44:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -106:
	case -86:
	case -74:
	case -52:
	case -26:
	case 22:
	case 46:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* An entrance's step: waits until the scroll brings it left of its x. */
void goon_wait_for_scroll(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t t1 = 0, trigger_x = 0;

	t1 = OBJECT(object)->x;
	trigger_x = OBJECT(object)->goon.trigger_x;
	if (t1 < trigger_x)
	{
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 1: after its wait shown with animation A2. */
void hat_goon_jump_in_show(uint16_t object)
{
	uint8_t entrance_wait = 0, action_step = 0;

	entrance_wait = OBJECT(object)->hat_goon.entrance_wait;
	OBJECT(object)->hat_goon.entrance_wait = entrance_wait - 1u;
	if (entrance_wait == 1u)
	{
		OBJECT(object)->entrance_pending = 0u;
		OBJECT(object)->animation = 0xA2u;
		OBJECT(object)->flags = 0x88u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 2: at the animation's end leaps high (animation 84) toward its nearest player. */
void hat_goon_jump_in_leap(uint16_t object)
{
	uint16_t u = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->z_speed = 0x900;
	OBJECT(object)->animation = 0x84u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 3: flies up the screen until it is over floor lower than itself, then takes that floor's height
   and priority. */
void hat_goon_jump_in_fly(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0, z = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t z_2 = 0;

	OBJECT(object)->y_speed = -0x200;
	vector_floor_ahead(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	priority_bits = floor_value;
	if ((int8_t)floor_value < 0)
	{
		goon_fall_to_floor(object);
		return;
	}
	z = (((priority_bits & 0xFu) << 1) << 1) << 1;
	z_2 = OBJECT(object)->z;
	if (z_2 <= z)
	{
		goon_stop_and_fall(object);
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | (z & 0xFFu);
	priority_bits &= 0x30u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Stops moving up or down the screen and falls (goon_fall_to_floor). */
void goon_stop_and_fall(uint16_t object)
{
	OBJECT(object)->y_speed = 0;
	goon_fall_to_floor(object);
}

/* Falls with gravity; landing, stops, can be hit and goes to choosing. */
void goon_fall_to_floor(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t state = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->flags = 0xC0u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Its state 0: a goon with the floor's height under it and the x the scroll must bring it in at from
   goon_drop_xs. */
uint16_t goon_drop_set_up(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, ignored16 = 0, y = 0;
	uint8_t enemy_class = 0, parameter = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	vector_goon_setup(object, &y, &ignored16);
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	t1 = (floor_value & 0xFu) << 3;
	OBJECT(object)->floor_z = t1;
	OBJECT(object)->flags = 0x80u;
	enemy_class = OBJECT(object)->enemy_class;
	OBJECT(object)->enemy_class = enemy_class + 1u;
	parameter = OBJECT(object)->parameter;
	t2 = goon_drop_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->goon.trigger_x = t2;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_drop_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case -28:
	case 0:
		goon_wait_for_scroll(object);
		return y;
	case 2:
		goon_drop_show(object);
		return y;
	case -20:
	case 4:
		goon_stop_and_fall(object);
		return y;
	case -18:
	case 6:
		goon_fall_to_floor(object);
		return y;
	case 8:
		return umbrella_goon_float_down_set_up(object);
	case 10:
		umbrella_goon_float_down_step(object);
		return y;
	case -120:
	case -108:
	case -86:
	case -60:
	case -12:
	case 12:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -118:
	case -106:
	case -84:
	case -58:
	case -10:
	case 14:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -116:
	case -104:
	case -82:
	case -56:
	case -8:
	case 16:
		vector_enemy_react(object, &y, &ignored16, &ignored);
		return y;
	case -114:
	case -102:
	case -80:
	case -54:
	case -6:
	case 18:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 1: shown, facing its nearest player, then falls. */
void goon_drop_show(uint16_t object)
{
	uint16_t u = 0;
	uint8_t action_step = 0;

	OBJECT(object)->flags = 0xC8u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Its state 0: a goon with an umbrella (animation A1) at the x umbrella_goon_xs gives, with the floor's
   height and priority under it. */
uint16_t umbrella_goon_float_down_set_up(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0, ignored16 = 0, y = 0;
	uint8_t parameter = 0, attributes = 0, state = 0;
	uint16_t t1 = 0, t2 = 0;

	umbrella_goon_set_up(object, &y, &ignored16);
	OBJECT(object)->animation = 0xA1u;
	OBJECT(object)->flags = 0xC8u;
	OBJECT(object)->enemy_class = 1;
	parameter = OBJECT(object)->parameter;
	t1 = umbrella_goon_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = t1;
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	priority_bits = floor_value & 0x30u;
	t2 = (floor_value & 0xFu) << 3;
	OBJECT(object)->floor_z = t2;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | priority_bits;
	OBJECT(object)->timer = 1u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return y;
}

/* Its entrance (state 1): runs its step. */
void umbrella_goon_float_down_step(uint16_t object)
{
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		umbrella_goon_float_down_face(object);
		return;
	case 2:
		umbrella_goon_float_down_fall(object);
		return;
	case 4:
		umbrella_goon_float_down_land(object);
		return;
	}
}

/* Step 0: after a frame faces its nearest player. */
void umbrella_goon_float_down_face(uint16_t object)
{
	uint16_t u = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	vector_face_direction(object);
}

/* Step 1: floats down (a sixth of the gravity); landing, animation A2. */
void umbrella_goon_float_down_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t action_step = 0;
	uint16_t z_speed = 0;

	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0x10u;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->animation = 0xA2u;
		action_step = OBJECT(object)->action_step;
		OBJECT(object)->action_step = action_step + 1u;
	}
}

/* Step 2: goes to choosing. */
void umbrella_goon_float_down_land(uint16_t object)
{
	uint8_t state = 0;

	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
}

/* Sets up a goon of kind B6 with behaviour 029CDF, its nearest player and the distances to it. */
uint16_t bomb_goon_set_up(uint16_t object)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	setup = bomb_goon_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	OBJECT(object)->behaviour = 0x7CDFu;
	OBJECT(object)->retarget_time = 0x10u;
	return y;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t bomb_goon_start(uint16_t object)
{
	uint16_t y = 0;
	uint8_t parameter = 0;

	y = bomb_goon_set_up(object);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Sets up a goon with a hat (kind 84, behaviour 029D37: it throws its hat from afar). */
void hat_goon_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	setup = hat_goon_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	u = 0x7D37u;
	OBJECT(object)->behaviour = 0x7D37u;
	OBJECT(object)->retarget_time = 0x10u;
	*p_y = y;
	*p_u = u;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t hat_goon_start(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t parameter = 0;

	hat_goon_set_up(object, &y, &ignored16);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Sets the sprite attributes of the goons with an umbrella or a shovel: bit 7 and 6 in the low nibble,
   its priority and facing kept. */
void goon_set_armed_attributes(uint16_t object)
{
	uint8_t attributes = 0;

	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0x70u) | 0x86u;
}

/* Sets up a goon with an umbrella (kind 82, behaviour 029D8F). */
void umbrella_goon_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	setup = umbrella_goon_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	goon_set_armed_attributes(object);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	u = 0x7D8Fu;
	OBJECT(object)->behaviour = 0x7D8Fu;
	OBJECT(object)->retarget_time = 0x10u;
	*p_y = y;
	*p_u = u;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t umbrella_goon_start(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t parameter = 0;

	umbrella_goon_set_up(object, &y, &ignored16);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Sets up a goon with a shovel (kind 83, behaviour 029DE7). */
void shovel_goon_set_up(uint16_t object, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t setup = 0, u = 0, y = 0;
	uint8_t attributes = 0;

	setup = shovel_goon_setup_ADDRESS;
	y = vector_object_setup(object, setup);
	goon_set_armed_attributes(object);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = attributes | 0x40u;
	OBJECT(object)->enemy_class = 1;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	u = 0x7DE7u;
	OBJECT(object)->behaviour = 0x7DE7u;
	OBJECT(object)->retarget_time = 0x10u;
	*p_y = y;
	*p_u = u;
}

/* Its state 0: set up, weakened when its spawn says so, straight to choosing. */
uint16_t shovel_goon_start(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t parameter = 0;

	shovel_goon_set_up(object, &y, &ignored16);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->state = 2u;
	return y;
}

/* Its state 0: a goon with 1 health (animation B3) running in toward the middle for the frames its spawn
   gives. */
uint16_t goon_bomb_run_in_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t parameter = 0, state = 0;
	uint16_t t1 = 0, x_speed = 0;

	vector_goon_setup(object, &y, &ignored16);
	OBJECT(object)->vitality = 1u;
	OBJECT(object)->animation = 0xB3u;
	parameter = OBJECT(object)->parameter;
	OBJECT(object)->timer = parameter;
	OBJECT(object)->retarget_time = 0x10u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	OBJECT(object)->x_speed = 0x200;
	t1 = OBJECT(object)->x;
	if (t1 >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	face_movement(object);
	return y;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_bomb_run_in_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	for (;;)
	{
		action_step = OBJECT(object)->action_step;
		switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
		{
		case 0:
			goon_bomb_run_in_stop(object);
			return y;
		case 2:
			return goon_bomb_run_in_throw(object, y);
		case 4:
			break;
		case -8:
		case 32:
		case 44:
		case 64:
		case 84:
			vector_enemy_think(object, &y, &ignored16, &ignored);
			return y;
		case -6:
		case 34:
		case 46:
		case 66:
		case 86:
			vector_enemy_act(object, &y, &ignored16, &ignored);
			return y;
		case -2:
		case 38:
		case 50:
		case 70:
		case 90:
			vector_enemy_climb(object, &y, &ignored16, &ignored);
			return y;
		case -12:
			return goon_bomb_run_in_set_up(object);
		case -10:
			continue;
		case -4:
			vector_enemy_react(object, &y, &ignored16, &ignored);
			return y;
		}
		break;
	}
	goon_bomb_run_in_end(object);
	return y;
}

/* Step 0: after its run stops (animation A9) facing its nearest player. */
void goon_bomb_run_in_stop(uint16_t object)
{
	uint16_t u = 0;
	uint8_t timer = 0, action_step = 0;

	timer = OBJECT(object)->timer;
	OBJECT(object)->timer = timer - 1u;
	if (timer != 1u)
		return;
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->animation = 0xA9u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	u = vector_choose_nearest_player(object);
	vector_measure_target(object, u);
	face_target(object);
}

/* Step 1: at the animation's event throws a bomb. */
uint16_t goon_bomb_run_in_throw(uint16_t object, uint16_t child_record)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t animation_flags = 0, action_step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 2u) == 0u)
		return child_record;
	child_record = goon_bomb_run_in_throw_child_ADDRESS;
	spawn_list_2_child(object, child_record, &ignored16, &carry);
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
	return child_record;
}

/* Step 2: at the animation's end goes to choosing. */
void goon_bomb_run_in_end(uint16_t object)
{
	uint8_t animation_flags = 0, state = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if (animation_flags & 1u)
	{
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}

/* Its state 0: a striker goon at its place, running in. */
uint16_t goon_striker_jump_in_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	goon_jump_in_place(object);
	goon_striker_set_up(object, &y, &ignored16);
	goon_jump_in_run(object);
	return y;
}

/* Puts it at the x goon_jump_in_xs gives (by its spawn's field 30), with 1 health when its bit 7 is set. */
void goon_jump_in_place(uint16_t object)
{
	uint8_t parameter = 0, parameter_2 = 0;
	uint16_t t1 = 0;

	parameter = OBJECT(object)->parameter;
	t1 = goon_jump_in_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = t1;
	parameter_2 = OBJECT(object)->parameter;
	if ((int8_t)parameter_2 < 0)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
}

/* Its state 0: a goon at its place, running in. */
uint16_t goon_jump_in_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, y = 0;

	goon_jump_in_place(object);
	vector_goon_setup(object, &y, &ignored16);
	goon_jump_in_run(object);
	return y;
}

/* Shown running (animation 90) toward the middle, riding the cemetery's ground (z speed the scroll's
   speed); then its entrance. */
void goon_jump_in_run(uint16_t object)
{
	uint8_t attributes = 0, state = 0;
	uint16_t t1 = 0, x_speed = 0, t2 = 0;

	OBJECT(object)->flags = 0x80u;
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x20u;
	OBJECT(object)->animation = 0x90u;
	OBJECT(object)->x_speed = 0x200;
	t1 = OBJECT(object)->x;
	if (t1 >= 0xE0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	face_movement(object);
	t2 = cemetery_scroll_speed;
	OBJECT(object)->z_speed = t2;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_jump_in_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_jump_in_leap(object);
		return y;
	case 2:
		goon_jump_in_land(object);
		return y;
	case 4:
		return goon_from_below_set_up(object);
	case 6:
		return goon_from_below_step(object, y);
	case -64:
	case -24:
	case -12:
	case 8:
	case 28:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -62:
	case -22:
	case -10:
	case 10:
	case 30:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -20:
	case -8:
	case 12:
	case 32:
		return enemy_react_with_pits(object, y);
	case -58:
	case -18:
	case -6:
	case 14:
	case 34:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: rides the ground until there is floor in front of it, then leaps up (animation 84) onto it. */
void goon_jump_in_leap(uint16_t object)
{
	uint32_t negative = 0;
	uint8_t floor_value = 0;
	uint16_t floor_cell = 0;
	uint8_t attributes = 0, action_step = 0;
	uint16_t t1 = 0;

	vector_floor_ahead_x(object, &floor_cell, &negative);
	floor_value = (uint8_t)(floor_cell >> 8);
	OBJECT(object)->floor_cell = floor_value;
	if ((int8_t)floor_value < 0)
	{
		t1 = cemetery_scroll_speed;
		OBJECT(object)->z_speed = t1;
		return;
	}
	OBJECT(object)->floor_z = (OBJECT(object)->floor_z & 0xFF00u) | ((((floor_value & 0xFu) << 1) << 1) << 1 & 0xFFu);
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 1: falls with gravity; landing, can be hit, takes its nearest player and goes to choosing. */
void goon_jump_in_land(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	OBJECT(object)->flags = 0xC0u;
	vector_choose_nearest_player(object);
	OBJECT(object)->state = 2u;
}

/* Its state 0: a goon (hit box 7F7B, animation 86) at the x goon_from_below_xs gives, 80 under the
   floor, riding the cemetery's ground. */
uint16_t goon_from_below_set_up(uint16_t object)
{
	uint16_t box = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t parameter = 0, attributes = 0, state = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	parameter = OBJECT(object)->parameter;
	t1 = goon_from_below_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = t1;
	OBJECT(object)->parameter = 0u;
	OBJECT(object)->z = 0xFF80u;
	vector_goon_setup(object, &ignored16, &ignored16_2);
	box = goon_from_below_entrance_box_ADDRESS;
	vector_set_hit_box(object, box);
	OBJECT(object)->attributes = 0x20u;
	OBJECT(object)->animation = 0x86u;
	OBJECT(object)->floor_z = 0u;
	t2 = OBJECT(object)->x;
	if (t2 >= 0xE0u)
	{
		attributes = OBJECT(object)->attributes;
		OBJECT(object)->attributes = attributes | 0x40u;
	}
	t3 = cemetery_scroll_speed;
	OBJECT(object)->z_speed = t3;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	return box;
}

/* Its entrance (state 1): runs its step. */
uint16_t goon_from_below_step(uint16_t object, uint16_t y)
{
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;
	uint8_t action_step = 0;

	action_step = OBJECT(object)->action_step;
	switch ((int8_t)(uint8_t)((uint32_t)action_step << 1))
	{
	case 0:
		goon_from_below_leap(object);
		return y;
	case 2:
		return goon_from_below_land(object, y);
	case 4:
		return cemetery_umbrella_goon_set_up(object);
	case 6:
		cemetery_umbrella_goon_float_down(object);
		return y;
	case -84:
	case -44:
	case -32:
	case -12:
	case 8:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		return y;
	case -82:
	case -42:
	case -30:
	case -10:
	case 10:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		return y;
	case -40:
	case -28:
	case -8:
	case 12:
		return enemy_react_with_pits(object, y);
	case -78:
	case -38:
	case -26:
	case -6:
	case 14:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		return y;
	}
	unreachable();
}

/* Step 0: rides the ground until it is up through the floor, then leaps out (animation 84) forward. */
void goon_from_below_leap(uint16_t object)
{
	uint8_t a = 0, d = 0;
	uint8_t attributes = 0, attributes_2 = 0, action_step = 0;
	uint16_t z = 0, t1 = 0, x_speed = 0;

	z = OBJECT(object)->z;
	d = (uint8_t)z;
	a = (uint8_t)(z >> 8);
	if ((int16_t)z < 0 || (uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) < 0u)
	{
		t1 = cemetery_scroll_speed;
		OBJECT(object)->z_speed = t1;
		return;
	}
	attributes = OBJECT(object)->attributes;
	OBJECT(object)->attributes = (attributes & 0xCFu) | 0x10u;
	OBJECT(object)->z_speed = 0x400;
	OBJECT(object)->x_speed = 0x200;
	attributes_2 = OBJECT(object)->attributes;
	if ((attributes_2 & 0x40u) != 0u)
	{
		x_speed = OBJECT(object)->x_speed;
		OBJECT(object)->x_speed = 0u - x_speed;
	}
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->animation = 0x84u;
	action_step = OBJECT(object)->action_step;
	OBJECT(object)->action_step = action_step + 1u;
}

/* Step 1: falls with gravity; landing, can be hit with its body's hit box, takes its nearest player and
   goes to choosing. */
uint16_t goon_from_below_land(uint16_t object, uint16_t box)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return box;
	OBJECT(object)->flags = 0xC0u;
	box = goon_from_below_body_box_ADDRESS;
	vector_set_hit_box(object, box);
	vector_choose_nearest_player(object);
	OBJECT(object)->state = 2u;
	return box;
}

/* Its state 0: a goon with an umbrella (animation A1) at the x cemetery_umbrella_goon_xs gives, 1 health
   with its spawn's bit 7, facing its target. */
uint16_t cemetery_umbrella_goon_set_up(uint16_t object)
{
	uint16_t ignored16 = 0, target = 0, y = 0;
	uint8_t parameter = 0, parameter_2 = 0, state = 0;
	uint16_t t1 = 0, target_2 = 0;

	parameter = OBJECT(object)->parameter;
	t1 = cemetery_umbrella_goon_xs[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
	OBJECT(object)->x = t1;
	umbrella_goon_set_up(object, &y, &ignored16);
	OBJECT(object)->flags = 0x88u;
	OBJECT(object)->floor_z = 0u;
	OBJECT(object)->animation = 0xA1u;
	OBJECT(object)->timer = 1u;
	parameter_2 = OBJECT(object)->parameter;
	if ((int8_t)parameter_2 < 0)
		OBJECT(object)->vitality = 1u;
	OBJECT(object)->parameter = 0u;
	state = OBJECT(object)->state;
	OBJECT(object)->state = state + 1u;
	target_2 = OBJECT(object)->target;
	target = target_2;
	vector_measure_target(object, target);
	vector_face_direction(object);
	return y;
}

/* Its entrance (state 1): floats down (a sixth of the gravity); landing, can be hit, animation A2, and
   goes to choosing. */
void cemetery_umbrella_goon_float_down(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t state = 0;
	uint16_t z_speed = 0, t1 = 0;

	z_speed = OBJECT(object)->z_speed;
	t1 = z_speed - 0x10u;
	OBJECT(object)->z_speed = t1;
	carry = vector_check_landing(object);
	if (carry)
	{
		OBJECT(object)->flags = 0xC0u;
		OBJECT(object)->animation = 0xA2u;
		state = OBJECT(object)->state;
		OBJECT(object)->state = state + 1u;
	}
}
