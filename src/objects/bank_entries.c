/**
 *    Name:        objects/bank_entries.c
 *    Description: each object bank's jump table: the handlers the object lists' dispatchers and the enemies' actions reach
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a fat goon that grabs: its start, then the enemies' shared fight by its step. */
uint32_t fat_goon_grabber_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_grabber_start(object);
		break;
	case 4:
	case 22:
	case 34:
	case 46:
	case 66:
	case 78:
	case 116:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
	case 24:
	case 36:
	case 48:
	case 68:
	case 80:
	case 118:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
	case 26:
	case 38:
	case 50:
	case 70:
	case 82:
	case 120:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case 10:
	case 28:
	case 40:
	case 52:
	case 72:
	case 84:
	case 122:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the kind 85 fighter (set up like a fat goon): its start, then the enemies' shared fight by its
   step. */
uint32_t kind_85_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_85_start(object);
		break;
	case -38:
	case -20:
	case -8:
	case 4:
	case 24:
	case 36:
	case 74:
	case 94:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -36:
	case -18:
	case -6:
	case 6:
	case 26:
	case 38:
	case 76:
	case 96:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -34:
	case -16:
	case -4:
	case 8:
	case 28:
	case 40:
	case 78:
	case 98:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -32:
	case -14:
	case -2:
	case 10:
	case 30:
	case 42:
	case 80:
	case 100:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case -24:
		fat_goon_puncher_start(object);
		break;
	case -12:
		fat_goon_jumper_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the police car by its step: drives in, stops, then reacts to the players' hits. */
uint16_t police_car_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = police_car_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = police_car_start(object);
		break;
	case 2:
		police_car_drive_in(object);
		break;
	case 4:
		states = police_car_stopped(object, states);
		break;
	case 6:
		states = police_car_wait(object, states);
		break;
	case 8:
		states = police_car_leave(object, states);
		break;
	case 10:
		states = police_car_driving_off(object, states);
		break;
	case 12:
		police_car_hit(object);
		break;
	case 14:
		police_car_drive_off(object);
		break;
	case 16:
		police_car_hit_wait();
		break;
	case -4:
	case -2:
		states = police_car_hit_steps(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs enemy action 09: the fat goon walks up to its target and strikes. */
uint16_t fat_goon_walk_up_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = 0x7950u;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_walk_up(object);
		return steps;
	case 2:
		return fat_goon_walk_up_to_target(object, steps);
	case 4:
		fat_goon_walk_up_swing(object);
		return steps;
	case 6:
		fat_goon_walk_up_hit(object);
		return steps;
	case 8:
	case 32:
		fat_goon_strike_recover(object);
		return steps;
	case 10:
	case 34:
		fat_goon_strike_end(object);
		return steps;
	case 12:
		fat_goon_body_slam_wind_up(object);
		return steps;
	case 14:
		fat_goon_body_slam_jump(object);
		return steps;
	case 16:
		fat_goon_body_slam_fall(object);
		return steps;
	case 18:
		fat_goon_body_slam_bounce(object);
		return steps;
	case 20:
		fat_goon_body_slam_end(object);
		return steps;
	case -12:
		fat_goon_back_off(object);
		return steps;
	case -10:
		fat_goon_back_off_end(object);
		return steps;
	case -8:
		fat_goon_bump_wind_up(object);
		return steps;
	case -6:
		fat_goon_bump_move(object);
		return steps;
	case -4:
		fat_goon_bump_stop(object);
		return steps;
	case -2:
		fat_goon_bump_end(object);
		return steps;
	}
	unreachable();
}

/* Runs enemy action 0A: the fat goon jumps and lands on its target. */
uint16_t fat_goon_body_slam_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = 0x795Cu;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_body_slam_wind_up(object);
		return steps;
	case 2:
		fat_goon_body_slam_jump(object);
		return steps;
	case 4:
		fat_goon_body_slam_fall(object);
		return steps;
	case 6:
		fat_goon_body_slam_bounce(object);
		return steps;
	case 8:
		fat_goon_body_slam_end(object);
		return steps;
	case -4:
	case 20:
		fat_goon_strike_recover(object);
		return steps;
	case -2:
	case 22:
		fat_goon_strike_end(object);
		return steps;
	case -24:
		fat_goon_back_off(object);
		return steps;
	case -22:
		fat_goon_back_off_end(object);
		return steps;
	case -20:
		fat_goon_bump_wind_up(object);
		return steps;
	case -18:
		fat_goon_bump_move(object);
		return steps;
	case -16:
		fat_goon_bump_stop(object);
		return steps;
	case -14:
		fat_goon_bump_end(object);
		return steps;
	case -12:
		fat_goon_walk_up(object);
		return steps;
	case -10:
		return fat_goon_walk_up_to_target(object, steps);
	case -8:
		fat_goon_walk_up_swing(object);
		return steps;
	case -6:
		fat_goon_walk_up_hit(object);
		return steps;
	}
	unreachable();
}

/* Runs enemy action 0B: the fat goon winds up and strikes (animation AB). */
uint16_t fat_goon_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = 0x796Au;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return fat_goon_strike_wind_up(object);
	case 2:
		fat_goon_strike_swing(object);
		return steps;
	case 4:
		fat_goon_strike_hit(object);
		return steps;
	case -18:
	case 6:
		fat_goon_strike_recover(object);
		return steps;
	case -16:
	case 8:
		fat_goon_strike_end(object);
		return steps;
	}
	unreachable();
}

/* Runs enemy action 0C: the fat goon winds up and strikes further out (animation A3). */
uint16_t fat_goon_reach_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = fat_goon_reach_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return fat_goon_strike_wind_up(object);
	case 2:
		fat_goon_reach_strike_swing(object);
		return steps;
	case 4:
		fat_goon_reach_strike_hit(object);
		return steps;
	case 6:
	case 16:
		fat_goon_strike_recover(object);
		return steps;
	case 8:
	case 18:
		fat_goon_strike_end(object);
		return steps;
	case 10:
		fat_goon_action_wait();
		return steps;
	case 12:
		fat_goon_heavy_strike_swing(object);
		return steps;
	case 14:
		fat_goon_heavy_strike_hit(object);
		return steps;
	case 20:
		return fat_goon_grab_approach(object);
	case 22:
		return fat_goon_grab(object);
	case 24:
		return fat_goon_squeeze(object);
	case 26:
		return fat_goon_squeeze_again(object);
	}
	unreachable();
}

/* Runs the fat goon that carries an obstacle in and throws it, then fights. */
uint32_t fat_goon_thrower_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_thrower_start(object);
		break;
	case 2:
		fat_goon_thrower_steps(object);
		break;
	case -106:
	case -86:
	case -38:
	case -22:
	case 4:
	case 32:
	case 66:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -104:
	case -84:
	case -36:
	case -20:
	case 6:
	case 34:
	case 68:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -102:
	case -82:
	case -34:
	case -18:
	case 8:
	case 36:
	case 70:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -100:
	case -80:
	case -32:
	case -16:
	case 10:
	case 38:
	case 72:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_thrower_pick_up(object);
		break;
	case 14:
		fat_goon_thrower_carry(object);
		break;
	case 16:
		fat_goon_thrower_throw(object);
		break;
	case 18:
		fat_goon_thrower_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that comes down from far away under a balloon, then fights. */
uint32_t fat_goon_descent_update(uint16_t object, uint8_t state)
{
	uint32_t zero = 0, negative = 0;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0, states = 0;
	uint32_t ignored = 0, left_caller = 0;
	uint8_t state_offset = 0;

	state_2 = (uint8_t)state;
	states = fat_goon_descent_states_ADDRESS;
	state_offset = (uint32_t)state_2 << 1;
	negative = state_offset >> 7;
	zero = state_offset == 0u;
	switch ((int8_t)state_offset)
	{
	case 0:
		fat_goon_descent_start(object);
		break;
	case 2:
		fat_goon_descent_steps(object);
		break;
	case -100:
	case -84:
	case -58:
	case -30:
	case 4:
		vector_enemy_think(object, &states, &ignored);
		break;
	case -98:
	case -82:
	case -56:
	case -28:
	case 6:
		vector_enemy_act(object, &states, &ignored);
		break;
	case -96:
	case -80:
	case -54:
	case -26:
	case 8:
		vector_enemy_react(object, &states, &ignored);
		break;
	case -94:
	case -78:
	case -52:
	case -24:
	case 10:
		vector_enemy_climb(object, &states, &ignored);
		break;
	case 12:
		fat_goon_descent_fall(object);
		break;
	case 14:
		fat_goon_descent_land(object);
		break;
	case -108:
	case -4:
		fat_goon_reach_ground(object);
		break;
	case -106:
	case -2:
		fat_goon_entrance_end(object);
		break;
	case -20:
	case -16:
	case -12:
	case -8:
		enemy_set_knock_direction(object, states, zero, negative);
		break;
	case -6:
		fat_goon_delayed_appear(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the balloon a descending fat goon lets go of, by its step. */
uint16_t descent_balloon_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = descent_balloon_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return descent_balloon_start(object);
	case 2:
		descent_balloon_wait();
		return states;
	case 4:
		return descent_balloon_release(object);
	case 6:
		descent_balloon_fly_away(object);
		return states;
	}
	unreachable();
}

/* Runs the fat goon that walks in for a time and then fights. */
uint32_t fat_goon_walk_in_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_walk_in_start(object);
		break;
	case 2:
		fat_goon_walk_in_steps(object);
		break;
	case -114:
	case -102:
	case -64:
	case -44:
	case 4:
	case 20:
	case 46:
	case 74:
	case 108:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -112:
	case -100:
	case -62:
	case -42:
	case 6:
	case 22:
	case 48:
	case 76:
	case 110:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -110:
	case -98:
	case -60:
	case -40:
	case 8:
	case 24:
	case 50:
	case 78:
	case 112:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -96:
	case -58:
	case -38:
	case 10:
	case 26:
	case 52:
	case 80:
	case 114:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_walk_in_go(object);
		break;
	case 14:
		fat_goon_walk_in_end(object);
		break;
	case 16:
		fat_goon_from_back_start(object);
		break;
	case 18:
		fat_goon_from_back_steps(object);
		break;
	case 28:
		fat_goon_from_back_place(object);
		break;
	case 30:
		fat_goon_from_back_walk(object);
		break;
	case 32:
		fat_goon_from_back_wait(object);
		break;
	case -4:
	case 100:
		fat_goon_reach_ground(object);
		break;
	case -50:
	case -2:
	case 102:
		fat_goon_entrance_end(object);
		break;
	case -54:
	case -6:
		fat_goon_entrance_walk_out(object);
		break;
	case -12:
		fat_goon_entrance_appear(object);
		break;
	case -10:
		fat_goon_entrance_pose(object);
		break;
	case -8:
		fat_goon_entrance_pose_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that shows after a wait and moves onto the floor, then fights. */
uint32_t fat_goon_delayed_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_delayed_start(object);
		break;
	case 2:
		fat_goon_delayed_steps(object);
		break;
	case -114:
	case -66:
	case -50:
	case -24:
	case 4:
	case 38:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -112:
	case -64:
	case -48:
	case -22:
	case 6:
	case 40:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -110:
	case -62:
	case -46:
	case -20:
	case 8:
	case 42:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -128:
	case -108:
	case -60:
	case -44:
	case -18:
	case 10:
	case 44:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that comes from the back of the stage, then fights. */
uint32_t fat_goon_from_back_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_from_back_start(object);
		break;
	case 2:
		fat_goon_from_back_steps(object);
		break;
	case -118:
	case -80:
	case -60:
	case -12:
	case 4:
	case 30:
	case 58:
	case 92:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -128:
	case -116:
	case -78:
	case -58:
	case -10:
	case 6:
	case 32:
	case 60:
	case 94:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -126:
	case -114:
	case -76:
	case -56:
	case -8:
	case 8:
	case 34:
	case 62:
	case 96:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -124:
	case -112:
	case -74:
	case -54:
	case -6:
	case 10:
	case 36:
	case 64:
	case 98:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_from_back_place(object);
		break;
	case 14:
		fat_goon_from_back_walk(object);
		break;
	case 16:
		fat_goon_from_back_wait(object);
		break;
	case -20:
	case 84:
		fat_goon_reach_ground(object);
		break;
	case -66:
	case -18:
	case 86:
		fat_goon_entrance_end(object);
		break;
	case -70:
	case -22:
		fat_goon_entrance_walk_out(object);
		break;
	case -28:
		fat_goon_entrance_appear(object);
		break;
	case -26:
		fat_goon_entrance_pose(object);
		break;
	case -24:
		fat_goon_entrance_pose_end(object);
		break;
	case -16:
		fat_goon_walk_in_start(object);
		break;
	case -14:
		fat_goon_walk_in_steps(object);
		break;
	case -4:
		fat_goon_walk_in_go(object);
		break;
	case -2:
		fat_goon_walk_in_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs enemy action 29: the fat goon backs into its target. */
uint16_t fat_goon_bump_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = 0x7948u;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_bump_wind_up(object);
		return steps;
	case 2:
		fat_goon_bump_move(object);
		return steps;
	case 4:
		fat_goon_bump_stop(object);
		return steps;
	case 6:
		fat_goon_bump_end(object);
		return steps;
	case 8:
		fat_goon_walk_up(object);
		return steps;
	case 10:
		return fat_goon_walk_up_to_target(object, steps);
	case 12:
		fat_goon_walk_up_swing(object);
		return steps;
	case 14:
		fat_goon_walk_up_hit(object);
		return steps;
	case 16:
	case 40:
		fat_goon_strike_recover(object);
		return steps;
	case 18:
	case 42:
		fat_goon_strike_end(object);
		return steps;
	case 20:
		fat_goon_body_slam_wind_up(object);
		return steps;
	case 22:
		fat_goon_body_slam_jump(object);
		return steps;
	case 24:
		fat_goon_body_slam_fall(object);
		return steps;
	case 26:
		fat_goon_body_slam_bounce(object);
		return steps;
	case 28:
		fat_goon_body_slam_end(object);
		return steps;
	case -4:
		fat_goon_back_off(object);
		return steps;
	case -2:
		fat_goon_back_off_end(object);
		return steps;
	}
	unreachable();
}

/* Runs enemy action 0E: the strongest strike (hit box 7934), with sound 2000. */
uint16_t fat_goon_heavy_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = fat_goon_heavy_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_heavy_strike_swing(object);
		return steps;
	case 2:
		fat_goon_heavy_strike_hit(object);
		return steps;
	case -6:
	case 4:
		fat_goon_strike_recover(object);
		return steps;
	case -4:
	case 6:
		fat_goon_strike_end(object);
		return steps;
	case 8:
		return fat_goon_grab_approach(object);
	case 10:
		return fat_goon_grab(object);
	case 12:
		return fat_goon_squeeze(object);
	case 14:
		return fat_goon_squeeze_again(object);
	case -12:
		return fat_goon_strike_wind_up(object);
	case -10:
		fat_goon_reach_strike_swing(object);
		return steps;
	case -8:
		fat_goon_reach_strike_hit(object);
		return steps;
	case -2:
		fat_goon_action_wait();
		return steps;
	}
	unreachable();
}

/* Runs enemy action 0D, whose first step does nothing, so the action never ends. */
uint16_t fat_goon_idle_action_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = fat_goon_idle_action_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_action_wait();
		return steps;
	case 2:
		fat_goon_heavy_strike_swing(object);
		return steps;
	case 4:
		fat_goon_heavy_strike_hit(object);
		return steps;
	case -4:
	case 6:
		fat_goon_strike_recover(object);
		return steps;
	case -2:
	case 8:
		fat_goon_strike_end(object);
		return steps;
	case 10:
		return fat_goon_grab_approach(object);
	case 12:
		return fat_goon_grab(object);
	case 14:
		return fat_goon_squeeze(object);
	case 16:
		return fat_goon_squeeze_again(object);
	case -10:
		return fat_goon_strike_wind_up(object);
	case -8:
		fat_goon_reach_strike_swing(object);
		return steps;
	case -6:
		fat_goon_reach_strike_hit(object);
		return steps;
	}
	unreachable();
}

/* Runs the fat goon that walks up the screen into the stage, onto the ground, then fights. */
uint32_t fat_goon_entrance_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case -20:
	case 0:
		fat_goon_entrance_start(object);
		break;
	case 2:
		fat_goon_entrance_steps(object);
		break;
	case -128:
	case -110:
	case -98:
	case -86:
	case -66:
	case -54:
	case -16:
	case 4:
	case 52:
	case 68:
	case 94:
	case 122:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -126:
	case -108:
	case -96:
	case -84:
	case -64:
	case -52:
	case -14:
	case 6:
	case 54:
	case 70:
	case 96:
	case 124:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -124:
	case -106:
	case -94:
	case -82:
	case -62:
	case -50:
	case -12:
	case 8:
	case 56:
	case 72:
	case 98:
	case 126:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -122:
	case -104:
	case -92:
	case -80:
	case -60:
	case -48:
	case -10:
	case 10:
	case 58:
	case 74:
	case 100:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case -6:
	case 42:
		fat_goon_entrance_walk_out(object);
		break;
	case -2:
	case 46:
		fat_goon_entrance_end(object);
		break;
	case -18:
		fat_goon_entrance_to_floor_steps(object);
		break;
	case -8:
		fat_goon_entrance_show(object);
		break;
	case -4:
		fat_goon_reach_any_floor(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that drops in and walks a route to its floor, then fights. */
uint32_t fat_goon_drop_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_drop_start(object);
		break;
	case 2:
		fat_goon_drop_route_update(object);
		break;
	case -70:
	case -52:
	case -40:
	case -28:
	case -8:
	case 4:
	case 42:
	case 62:
	case 110:
	case 126:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -68:
	case -50:
	case -38:
	case -26:
	case -6:
	case 6:
	case 44:
	case 64:
	case 112:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -66:
	case -48:
	case -36:
	case -24:
	case -4:
	case 8:
	case 46:
	case 66:
	case 114:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -64:
	case -46:
	case -34:
	case -22:
	case -2:
	case 10:
	case 48:
	case 68:
	case 116:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_drop_fall(object);
		break;
	case 14:
		fat_goon_drop_take_route(object);
		break;
	case 16:
		fat_goon_drop_walk_up_left(object);
		break;
	case 18:
	case 28:
		fat_goon_drop_walk_to_floor(object);
		break;
	case 20:
		fat_goon_drop_walk_right(object);
		break;
	case 22:
		fat_goon_drop_stop(object);
		break;
	case 24:
		fat_goon_drop_fall_again(object);
		break;
	case 26:
		fat_goon_drop_walk_up(object);
		break;
	case -12:
		fat_goon_waiting_start(object);
		break;
	case -10:
		fat_goon_waiting(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs a prop standing in the stage until the scroll takes it away. */
uint16_t prop_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = prop_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return prop_start(object);
	case 2:
		prop_leave(object);
		return states;
	}
	unreachable();
}

/* Runs the kind B2 object that leaps off when its bear starts, by its step. */
uint16_t caged_gorilla_leaper_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = caged_gorilla_leaper_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = caged_gorilla_leaper_start(object);
		break;
	case 2:
		states = caged_gorilla_leaper_jump(object);
		break;
	case 4:
		caged_gorilla_leaper_fall(object);
		break;
	case 6:
		caged_gorilla_leaper_crash(object);
		break;
	case 8:
		caged_gorilla_leaper_wait(object);
		break;
	case 10:
		caged_gorilla_leaper_vanish(object);
		break;
	case 12:
		caged_gorilla_leaper_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a Krustyland door that opens to let out objects, by its step. */
uint16_t krustyland_door_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = krustyland_door_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = krustyland_door_start(object);
		break;
	case 2:
		krustyland_door_wait_camera(object);
		break;
	case 4:
		states = krustyland_door_open(object, states);
		break;
	case 6:
		krustyland_door_opened(object);
		break;
	case 8:
		krustyland_door_close(object);
		break;
	case 10:
		krustyland_door_closed(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the fat goon that walks up the screen into the stage, onto any floor, then fights. */
uint32_t fat_goon_entrance_to_floor_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 20:
		fat_goon_entrance_start(object);
		break;
	case 2:
		fat_goon_entrance_to_floor_steps(object);
		break;
	case -108:
	case -90:
	case -78:
	case -66:
	case -46:
	case -34:
	case 4:
	case 24:
	case 72:
	case 88:
	case 114:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -106:
	case -88:
	case -76:
	case -64:
	case -44:
	case -32:
	case 6:
	case 26:
	case 74:
	case 90:
	case 116:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -104:
	case -86:
	case -74:
	case -62:
	case -42:
	case -30:
	case 8:
	case 28:
	case 76:
	case 92:
	case 118:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -102:
	case -84:
	case -72:
	case -60:
	case -40:
	case -28:
	case 10:
	case 30:
	case 78:
	case 94:
	case 120:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_entrance_show(object);
		break;
	case 14:
	case 62:
		fat_goon_entrance_walk_out(object);
		break;
	case 16:
		fat_goon_reach_any_floor(object);
		break;
	case 18:
	case 66:
		fat_goon_entrance_end(object);
		break;
	case 22:
		fat_goon_entrance_steps(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the kind AB object that lets out an object each time it is hit, three times. */
uint16_t drink_vendor_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = drink_vendor_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = drink_vendor_start(object);
		break;
	case 2:
		drink_vendor_wait_hit(object);
		break;
	case 4:
		states = drink_vendor_let_out(object, states);
		break;
	case 6:
		states = drink_vendor_wait_child(object, states);
		break;
	case 8:
		drink_vendor_rest(object);
		break;
	case 10:
		drink_vendor_done();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind AC object that drops food, by its step. */
uint16_t burger_eater_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = burger_eater_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = burger_eater_start(object);
		break;
	case 2:
		burger_eater_wait();
		break;
	case 4:
		states = burger_eater_drop_food(object);
		break;
	case 6:
		burger_eater_done();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the fat goon that stands out of play until it comes on screen or is hit, then fights. */
uint32_t fat_goon_waiting_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_waiting_start(object);
		break;
	case 2:
		fat_goon_waiting(object);
		break;
	case -58:
	case -40:
	case -28:
	case -16:
	case 4:
	case 16:
	case 54:
	case 74:
	case 122:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -56:
	case -38:
	case -26:
	case -14:
	case 6:
	case 18:
	case 56:
	case 76:
	case 124:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -54:
	case -36:
	case -24:
	case -12:
	case 8:
	case 20:
	case 58:
	case 78:
	case 126:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -52:
	case -34:
	case -22:
	case -10:
	case 10:
	case 22:
	case 60:
	case 80:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_drop_start(object);
		break;
	case 14:
		fat_goon_drop_route_update(object);
		break;
	case 24:
		fat_goon_drop_fall(object);
		break;
	case 26:
		fat_goon_drop_take_route(object);
		break;
	case 28:
		fat_goon_drop_walk_up_left(object);
		break;
	case 30:
	case 40:
		fat_goon_drop_walk_to_floor(object);
		break;
	case 32:
		fat_goon_drop_walk_right(object);
		break;
	case 34:
		fat_goon_drop_stop(object);
		break;
	case 36:
		fat_goon_drop_fall_again(object);
		break;
	case 38:
		fat_goon_drop_walk_up(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs enemy action 38: the fat goon goes for its target, grabs it and squeezes. */
uint16_t fat_goon_grab_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = fat_goon_grab_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return fat_goon_grab_approach(object);
	case 2:
		return fat_goon_grab(object);
	case 4:
		return fat_goon_squeeze(object);
	case 6:
		return fat_goon_squeeze_again(object);
	case -20:
		return fat_goon_strike_wind_up(object);
	case -18:
		fat_goon_reach_strike_swing(object);
		return steps;
	case -16:
		fat_goon_reach_strike_hit(object);
		return steps;
	case -14:
	case -4:
		fat_goon_strike_recover(object);
		return steps;
	case -12:
	case -2:
		fat_goon_strike_end(object);
		return steps;
	case -10:
		fat_goon_action_wait();
		return steps;
	case -8:
		fat_goon_heavy_strike_swing(object);
		return steps;
	case -6:
		fat_goon_heavy_strike_hit(object);
		return steps;
	}
	unreachable();
}

/* Runs a fat goon that strikes: its start, then the enemies' shared fight. */
uint32_t fat_goon_puncher_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_puncher_start(object);
		break;
	case -14:
	case 4:
	case 16:
	case 28:
	case 48:
	case 60:
	case 98:
	case 118:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -12:
	case 6:
	case 18:
	case 30:
	case 50:
	case 62:
	case 100:
	case 120:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -10:
	case 8:
	case 20:
	case 32:
	case 52:
	case 64:
	case 102:
	case 122:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -8:
	case 10:
	case 22:
	case 34:
	case 54:
	case 66:
	case 104:
	case 124:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		fat_goon_jumper_start(object);
		break;
	case 24:
		kind_85_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the plain fat goon: its start, then the enemies' shared fight. */
uint32_t fat_goon_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_start(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that jumps in from a side of the cemetery, then fights. */
uint32_t fat_goon_jump_in_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_jump_in_start(object);
		break;
	case 2:
		fat_goon_jump_in_steps(object);
		break;
	case 4:
	case 24:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
	case 26:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
	case 28:
		enemy_react_with_pits(object);
		break;
	case 10:
	case 30:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the fat goon that comes up from below the cemetery's floor, then fights. */
uint32_t fat_goon_from_below_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_from_below_start(object);
		break;
	case 2:
		fat_goon_from_below_steps(object);
		break;
	case -16:
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -14:
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -12:
	case 8:
		enemy_react_with_pits(object);
		break;
	case -10:
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case -4:
		fat_goon_jump_in_jump(object);
		break;
	case -2:
		fat_goon_jump_in_land(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the stage event that holds the scroll while there are more enemies than its count. */
void scroll_lock_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		scroll_lock_start(object);
		return;
	case 2:
		scroll_lock(object);
		return;
	case 4:
		enemy_waves_start(object);
		return;
	case 6:
		enemy_waves_spawn(object);
		return;
	case 8:
		enemy_waves_next(object);
		return;
	case 10:
		enemy_waves_end(object);
		return;
	}
}

/* Runs the stage event that holds the scroll and puts in waves of enemies, by its step. */
void enemy_waves_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		enemy_waves_start(object);
		break;
	case 2:
		enemy_waves_spawn(object);
		break;
	case 4:
		enemy_waves_next(object);
		break;
	case 6:
		enemy_waves_end(object);
		break;
	case -4:
		scroll_lock_start(object);
		break;
	case -2:
		scroll_lock(object);
		break;
	}
	camera_x_held--;
}

/* Runs the stage event that puts in objects and, once no enemy is left, two more goons. */
void cleared_wave_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		cleared_wave_start(object);
		return;
	case 2:
		cleared_wave_wait(object);
		return;
	case -4:
		fat_goon_from_below_rise(object);
		return;
	case -2:
		fat_goon_from_below_land(object);
		return;
	}
}

/* Runs a cemetery piece bobbing with the stage, gone out of its height range. */
uint16_t cemetery_piece_update(uint16_t object, uint8_t state)
{
	uint16_t states = 0;
	uint16_t z = 0;

	states = cemetery_piece_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = cemetery_piece_start(object);
		break;
	case 2:
		cemetery_piece_bob(object);
		break;
	}
	z = OBJECT(object)->z;
	if ((uint16_t)(z + 0x80u) >= 0x120u)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Runs the kind AA object that stands still in stage 8. */
uint16_t poster_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = poster_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return poster_start(object);
	case 2:
		poster_idle();
		return states;
	}
	unreachable();
}

/* Runs the kind AA objects of stage 7 that come in pairs, gone near the left edge. */
uint16_t poster_pair_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = poster_pair_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return poster_pair_start(object);
	case 2:
		poster_pair_leave(object);
		return states;
	}
	unreachable();
}

/* Runs the kind CB object that reacts to three hits, by its step. */
uint16_t bleeding_gums_murphy_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bleeding_gums_murphy_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bleeding_gums_murphy_start(object);
		break;
	case 2:
		bleeding_gums_murphy_wait_hit(object);
		break;
	case 4:
		bleeding_gums_murphy_hit_end(object);
		break;
	case 6:
		bleeding_gums_murphy_rest(object);
		break;
	case 8:
		bleeding_gums_murphy_done();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind D1 piece flung off, shrinking until it vanishes. */
uint16_t dream_ball_fling_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = dream_ball_fling_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return dream_ball_fling_start(object);
	case 2:
		dream_ball_fling_shrink(object);
		return states;
	}
	unreachable();
}

/* Runs the kind 0F scenery that writes its shape into the floor map as the scroll brings it in; nothing
   puts one in. */
uint16_t floor_blocker_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = floor_blocker_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = floor_blocker_start(object);
		break;
	case 2:
		states = floor_blocker_steps(object);
		break;
	case 4:
		floor_blocker_wait();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the hat a goon with a hat throws: it flies out and back, hurting what it touches. */
uint16_t goon_hat_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0, timer = 0;
	uint16_t hat_x = 0;

	state_2 = (uint8_t)state;
	states = 0x7F37u;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = goon_hat_throw_start(object);
		break;
	case 2:
		goon_hat_turn_back(object);
		break;
	case 4:
		states = goon_hat_return(object, states);
		break;
	case 6:
		goon_hat_done();
		break;
	case -8:
		goon_hat_burst(object);
		break;
	case -6:
		goon_hat_burst_end(object);
		break;
	case -4:
	case -2:
		states = goon_hat_burst_steps(object);
		break;
	}
	states = goon_hat_check_thrower(object, states);
	goon_hat_floor_priority(object);
	states = object_take_special_hit(object, states);
	hat_x = OBJECT(object)->x;
	if (hat_x >= 0x1C0u)
		OBJECT(object)->flags = 0u;
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 < 0)
		return states;
	timer = OBJECT(object)->timer;
	if ((timer & 3u) != 0u)
	{
		OBJECT(object)->damage = 0u;
		OBJECT(object)->attack = 0u;
		return states;
	}
	OBJECT(object)->damage = 2u;
	OBJECT(object)->attack = 1u;
	return states;
}

/* Unused: the handler of list 2's type 03, which does nothing; no object of that type is put in. */
void empty_child_type_03_handler(void)
{
}

/* Unused: the handler of list 2's type 04, which does nothing; no object of that type is put in. */
void empty_child_type_04_handler(void)
{
}

/* Runs a fat goon that grabs and body-slams: its start, then the enemies' shared fight. */
uint32_t fat_goon_jumper_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fat_goon_jumper_start(object);
		break;
	case -26:
	case -8:
	case 4:
	case 16:
	case 36:
	case 48:
	case 86:
	case 106:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -24:
	case -6:
	case 6:
	case 18:
	case 38:
	case 50:
	case 88:
	case 108:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -22:
	case -4:
	case 8:
	case 20:
	case 40:
	case 52:
	case 90:
	case 110:
		vector_enemy_react(object, &ignored16, &ignored);
		break;
	case -20:
	case -2:
	case 10:
	case 22:
	case 42:
	case 54:
	case 92:
	case 112:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		kind_85_start(object);
		break;
	case -12:
		fat_goon_puncher_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs enemy action 3E: the fat goon walks away from its target for a while. */
uint16_t fat_goon_back_off_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = 0x7944u;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fat_goon_back_off(object);
		return steps;
	case 2:
		fat_goon_back_off_end(object);
		return steps;
	case 4:
		fat_goon_bump_wind_up(object);
		return steps;
	case 6:
		fat_goon_bump_move(object);
		return steps;
	case 8:
		fat_goon_bump_stop(object);
		return steps;
	case 10:
		fat_goon_bump_end(object);
		return steps;
	case 12:
		fat_goon_walk_up(object);
		return steps;
	case 14:
		return fat_goon_walk_up_to_target(object, steps);
	case 16:
		fat_goon_walk_up_swing(object);
		return steps;
	case 18:
		fat_goon_walk_up_hit(object);
		return steps;
	case 20:
	case 44:
		fat_goon_strike_recover(object);
		return steps;
	case 22:
	case 46:
		fat_goon_strike_end(object);
		return steps;
	case 24:
		fat_goon_body_slam_wind_up(object);
		return steps;
	case 26:
		fat_goon_body_slam_jump(object);
		return steps;
	case 28:
		fat_goon_body_slam_fall(object);
		return steps;
	case 30:
		fat_goon_body_slam_bounce(object);
		return steps;
	case 32:
		fat_goon_body_slam_end(object);
		return steps;
	}
	unreachable();
}

/* Runs the kind 9E object that puts in another object once the camera gets there. */
uint16_t moe_spawner_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = moe_spawner_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = moe_spawner_start(object);
		break;
	case 2:
		states = moe_spawner_put_in_object(object, states);
		break;
	case 4:
		moe_spawner_wait();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a piece of stage 1's scenery that no one can walk into, gone once off screen. */
uint16_t solid_scenery_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t scenery_x = 0;

	state_2 = (uint8_t)state;
	states = solid_scenery_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = solid_scenery_start(object);
		break;
	case 2:
		solid_scenery_idle();
		break;
	case -8:
		states = obstacle_smashed(object, states);
		break;
	case -6:
		obstacle_smashed_end(object);
		break;
	case -4:
		states = obstacle_knocked(object);
		break;
	case -2:
		obstacle_knocked_fall(object);
		break;
	}
	scenery_x = OBJECT(object)->x;
	if (scenery_x >= 0x1F0u)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Runs a door of the police car, which lets goons out once the car has stopped. */
uint16_t police_car_door_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = police_car_door_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = police_car_door_start(object);
		break;
	case 2:
		police_car_door_wait_car(object);
		break;
	case 4:
		states = police_car_door_open(object, states);
		break;
	case 6:
		police_car_door_vanish(object);
		break;
	case 8:
		police_car_door_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the obstacle a fat goon carries and throws: carried, thrown, bouncing and breaking. */
uint16_t carried_obstacle_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t obstacle_x = 0, screen_offset = 0;

	state_2 = (uint8_t)state;
	states = carried_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 18:
		states = carried_obstacle_start(object);
		break;
	case 2:
		states = carried_obstacle_held(object);
		break;
	case 4:
		carried_obstacle_thrown(object);
		break;
	case 6:
	case 24:
		carried_obstacle_fly(object);
		break;
	case 8:
	case 26:
		carried_obstacle_bounce(object);
		break;
	case 10:
	case 28:
		carried_obstacle_land(object);
		break;
	case 12:
	case 30:
		carried_obstacle_slide(object);
		break;
	case -4:
	case 14:
		states = carried_obstacle_break_steps(object);
		break;
	case -2:
	case 16:
		states = carried_obstacle_drop_steps(object);
		break;
	case 20:
		states = tossed_obstacle_held(object);
		break;
	case 22:
		tossed_obstacle_toss(object);
		break;
	}
	states = object_take_special_hit(object, states);
	carried_obstacle_check_floor(object);
	if (OBJECT(object)->flags != 0u)
	{
		obstacle_x = OBJECT(object)->x;
		screen_offset = obstacle_x - 0x10u;
		if (screen_offset >= 0x1A0u)
			OBJECT(object)->flags = 0u;
	}
	return states;
}

/* Runs the kind 0F scenery of stage 2 that sets its shape in the floor, then charges with two goons. */
uint16_t charging_scenery_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t steps = 0;
	uint8_t part = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		charging_scenery_start(object);
		break;
	case 2:
		charging_scenery_wait_shape(object);
		break;
	case 4:
		charging_scenery_wait_target(object, 0u);
		break;
	case 6:
		charging_scenery_charge(object);
		break;
	case 8:
		charging_scenery_first_part(object);
		break;
	case 10:
		charging_scenery_second_part(object, 0u);
		break;
	case 12:
		charging_scenery_last_part(object, 0u);
		break;
	case 14:
		charging_scenery_part_wait();
		break;
	}
	steps = charging_scenery_parts_ADDRESS;
	part = OBJECT(object)->charging_scenery.part;
	switch ((int8_t)(uint8_t)((uint32_t)part << 1))
	{
	case 0:
		return charging_scenery_first_part(object);
	case 2:
		return charging_scenery_second_part(object, steps);
	case 4:
		return charging_scenery_last_part(object, steps);
	case 6:
		charging_scenery_part_wait();
		return steps;
	case -8:
		return charging_scenery_start(object);
	case -6:
		charging_scenery_wait_shape(object);
		return steps;
	case -4:
		return charging_scenery_wait_target(object, steps);
	case -2:
		charging_scenery_charge(object);
		return steps;
	}
	unreachable();
}

/* Runs a piece flying off the platform scenery when it crashes. */
uint16_t scenery_debris_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = scenery_debris_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = scenery_debris_start(object);
		break;
	case 2:
		scenery_debris_bounce(object);
		break;
	case 4:
		scenery_debris_land(object);
		break;
	case 6:
		scenery_debris_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs an obstacle that raises the floor under it and can be picked up, thrown and broken. */
void obstacle_update(uint16_t object, uint32_t carry, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t states = (uint16_t)*p_states;
	uint8_t state_now = 0;
	uint8_t state = 0, state_2 = 0, state_3 = 0, points = 0, shadow_player = 0;

	carry = remove_off_screen(object, carry);
	if (carry)
	{
		states = obstacle_states_ADDRESS;
		state = OBJECT(object)->state;
		switch ((int8_t)(uint8_t)((uint32_t)state << 1))
		{
		case 0:
			obstacle_start(object, &states, p_left_caller);
			break;
		case 2:
			obstacle_settle(object, &states, p_left_caller);
			break;
		case 4:
			obstacle_lie();
			break;
		case 6:
			states = obstacle_pick_up(object);
			break;
		case 8:
			obstacle_throw(object);
			break;
		case 10:
			obstacle_fly(object);
			break;
		case 12:
			states = obstacle_rebound(object);
			break;
		case 14:
			obstacle_rebound_rise(object);
			break;
		case 16:
			obstacle_rebound_fall(object);
			break;
		case -4:
			states = obstacle_smashed_steps(object);
			break;
		case -2:
			states = obstacle_knocked_steps(object);
			break;
		}
		state_2 = OBJECT(object)->state;
		state_now = state_2;
		if ((int8_t)state_2 >= 0 && state_now < 4u)
		{
			states = object_take_special_hit(object, states);
			state_3 = OBJECT(object)->state;
			if ((int8_t)state_3 < 0)
			{
				points = OBJECT(object)->points;
				points_player_bits = points & 0x30u;
				shadow_player = OBJECT(object)->shadow_player;
				OBJECT(object)->shadow_player = (shadow_player & 0xCFu) | points_player_bits;
			}
		}
		states = throwable_follow_floor(object, states);
	}
	*p_states = states;
}

/* Runs a small object lying in the stage that a player can pick up and throw at the enemies. */
uint16_t throwable_update(uint16_t object, uint16_t list_1_handlers, uint32_t carry)
{
	uint16_t states = 0;
	uint8_t state = 0, state_2 = 0, state_3 = 0;

	carry = remove_off_screen(object, carry);
	if (carry == 0u)
		return list_1_handlers;
	states = throwable_states_ADDRESS;
	state = OBJECT(object)->state;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = throwable_start(object);
		break;
	case 2:
	case 4:
		throwable_lie();
		break;
	case 6:
		throwable_pick_up(object);
		break;
	case 8:
		throwable_throw(object);
		break;
	case 10:
		throwable_hurt_enemies(object);
		break;
	case 12:
		states = throwable_rebound(object);
		break;
	case 14:
		throwable_fall(object);
		break;
	case 16:
		throwable_stop(object);
		break;
	case 18:
		throwable_stop_end(object);
		break;
	case -14:
	case -8:
		obstacle_break(object);
		break;
	case -12:
	case -6:
		obstacle_break_end(object);
		break;
	case -10:
		obstacle_fall_and_break(object);
		break;
	case -4:
	case -2:
		states = throwable_stop_steps(object);
		break;
	}
	state_2 = OBJECT(object)->state;
	if ((int8_t)state_2 >= 0)
	{
		state_3 = OBJECT(object)->state;
		if (state_3 > 2u)
		{
			states = object_take_special_hit(object, states);
			throwable_check_hit(object);
		}
	}
	return throwable_follow_floor(object, states);
}

/* Runs the kind 0F scenery of stage 1 that sets its shape in the floor as it scrolls in. */
uint16_t platform_scenery_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t steps = 0;
	uint8_t part = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		platform_scenery_start(object);
		break;
	case 2:
	case 94:
		platform_scenery_idle();
		break;
	case 4:
		platform_scenery_react(object);
		break;
	case 6:
		platform_scenery_clear_floor(object, 0u);
		break;
	case 8:
		platform_scenery_launch(object);
		break;
	case 10:
		platform_scenery_crash(object, 0u);
		break;
	case 12:
		platform_scenery_crash_wait(object);
		break;
	case 14:
		platform_scenery_vanish(object);
		break;
	case 16:
		platform_scenery_first_part(object);
		break;
	case 18:
		platform_scenery_second_part(object, 0u);
		break;
	case 20:
		platform_scenery_third_part(object, 0u);
		break;
	case 22:
		platform_scenery_fourth_part(object, 0u);
		break;
	case 24:
		platform_scenery_last_part(object, 0u);
		break;
	case 26:
		platform_scenery_part_wait();
		break;
	}
	steps = platform_scenery_parts_ADDRESS;
	part = OBJECT(object)->platform_scenery.part;
	switch ((int8_t)(uint8_t)((uint32_t)part << 1))
	{
	case 0:
		return platform_scenery_second_part(object, steps);
	case 2:
		return platform_scenery_third_part(object, steps);
	case 4:
		return platform_scenery_fourth_part(object, steps);
	case 6:
		return platform_scenery_last_part(object, steps);
	case 8:
		platform_scenery_part_wait();
		return steps;
	case -16:
	case 76:
		platform_scenery_idle();
		return steps;
	case -18:
		return platform_scenery_start(object);
	case -14:
		return platform_scenery_react(object);
	case -12:
		return platform_scenery_clear_floor(object, steps);
	case -10:
		platform_scenery_launch(object);
		return steps;
	case -8:
		return platform_scenery_crash(object, steps);
	case -6:
		platform_scenery_crash_wait(object);
		return steps;
	case -4:
		platform_scenery_vanish(object);
		return steps;
	case -2:
		return platform_scenery_first_part(object);
	}
	unreachable();
}

/* Runs a small piece that falls off the shaking scenery when it is hit from above. */
uint16_t shaken_bit_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaken_bit_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return shaken_bit_start(object);
	case 2:
		shaken_bit_fall(object);
		return states;
	}
	unreachable();
}

/* Runs the scenery that shakes when a player hits it, dropping food five times. */
uint16_t shaking_scenery_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaking_scenery_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = shaking_scenery_start(object);
		break;
	case 2:
		shaking_scenery_idle();
		break;
	case -6:
		states = shaking_scenery_hit_from_above_steps(object);
		break;
	case -4:
		states = shaking_scenery_shake_steps(object);
		break;
	case -2:
		states = shaking_scenery_hit_steps(object);
		break;
	}
	states = object_take_special_hit(object, states);
	states = shaking_scenery_check_hit_from_above(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs an obstacle that raises the floor by 4 steps; nothing puts one in. */
void heavy_obstacle_update(uint16_t object, uint32_t carry, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t states = (uint16_t)*p_states;
	uint8_t state_now = 0;
	uint16_t command = 0;
	uint8_t state = 0, state_2 = 0, points = 0, shadow_player = 0;

	carry = remove_off_screen(object, carry);
	if (carry)
	{
		states = heavy_obstacle_states_ADDRESS;
		state = OBJECT(object)->state;
		switch ((int8_t)(uint8_t)((uint32_t)state << 1))
		{
		case 0:
			heavy_obstacle_start(object, &states, p_left_caller);
			break;
		case 2:
			heavy_obstacle_idle();
			break;
		case 4:
		case 6:
			heavy_obstacle_hit_steps(object, &states, p_left_caller);
			break;
		case 8:
			states = throwable_start(object);
			break;
		case 10:
			timed_throwable_wait(object);
			break;
		case 12:
			timed_throwable_idle();
			break;
		case 14:
			throwable_pick_up(object);
			break;
		case 16:
			timed_throwable_throw(object);
			break;
		case 18:
			throwable_hurt_enemies(object);
			break;
		case 20:
			states = throwable_rebound(object);
			break;
		case 22:
			timed_throwable_fall(object);
			break;
		case 24:
			timed_throwable_smash_end(object);
			break;
		case 26:
			obstacle_smash(object);
			break;
		case 28:
			obstacle_smash_end(object);
			break;
		case 30:
			states = moes_street_scenery_riser_start(object);
			break;
		case 32:
			moes_street_scenery_riser_wait_boss(object);
			break;
		case 34:
			moes_street_scenery_riser_rise_slowly(object);
			break;
		case 36:
			moes_street_scenery_riser_rise_faster(object);
			break;
		case 38:
			moes_street_scenery_riser_stop(object);
			break;
		case 40:
			moes_street_scenery_riser_idle();
			break;
		case -4:
			states = obstacle_smashed_steps(object);
			break;
		case -2:
			states = obstacle_knocked_steps(object);
			break;
		}
		states = object_take_special_hit(object, states);
		state_2 = OBJECT(object)->state;
		state_now = state_2;
		if ((int8_t)state_2 < 0)
		{
			if (state_now == 0xFFu && (frame_count & 0x1Fu) == 0u)
			{
				command = 0x6500u;
				vector_queue_sound(command);
			}
			points = OBJECT(object)->points;
			points_player_bits = points & 0x30u;
			shadow_player = OBJECT(object)->shadow_player;
			OBJECT(object)->shadow_player = (shadow_player & 0xCFu) | points_player_bits;
		}
		states = throwable_follow_floor(object, states);
	}
	*p_states = states;
}

/* Runs the kind 87 character that wanders near its device and runs to it when the device is hit. */
uint16_t woman_in_apron_update(uint16_t object, uint8_t state)
{
	uint16_t home_distance = 0, states = 0;
	uint8_t blocked = 0, blocked_2 = 0;
	uint16_t screen_x = 0, walker_x = 0, home_x = 0, x_speed = 0;

	states = woman_in_apron_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = woman_in_apron_start(object);
		break;
	case 2:
		woman_in_apron_stop(object);
		break;
	case 4:
		woman_in_apron_wander(object);
		break;
	case 6:
		states = woman_in_apron_run_to_device(object);
		break;
	case 8:
		states = woman_in_apron_reach_device(object);
		break;
	case 10:
		woman_in_apron_behind_device(object);
		break;
	case 12:
		woman_in_apron_come_back(object);
		break;
	case 14:
		woman_in_apron_back(object);
		break;
	}
	screen_x = OBJECT(object)->x;
	if (screen_x >= 0x1C0u)
	{
		OBJECT(object)->flags = 0u;
		return states;
	}
	walker_x = OBJECT(object)->x;
	home_x = OBJECT(object)->woman_in_apron.home_x;
	home_distance = walker_x + camera_x - home_x;
	if ((uint16_t)(home_distance >> 15 ? 0u - home_distance : home_distance) < 0x34u)
	{
		OBJECT(object)->blocked = 0u;
		return states;
	}
	blocked = OBJECT(object)->blocked;
	if (blocked != 0u)
		return states;
	blocked_2 = OBJECT(object)->blocked;
	OBJECT(object)->blocked = blocked_2 + 1u;
	x_speed = OBJECT(object)->x_speed;
	OBJECT(object)->x_speed = 0u - x_speed;
	face_movement(object);
	return states;
}

/* Runs the kind 95 character of stage 2 that flinches when hit and runs off when beaten. */
uint16_t rabbit_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = rabbit_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = rabbit_start(object);
		break;
	case 2:
		rabbit_stand();
		break;
	case 4:
		rabbit_hit(object);
		break;
	case 6:
		rabbit_hit_end(object);
		break;
	case -6:
		rabbit_wait();
		break;
	case -4:
		rabbit_beaten(object);
		break;
	case -2:
		states = rabbit_hit_steps(object);
		break;
	}
	states = object_take_special_hit(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 87 character's device, which strikes when its keeper works it. */
uint16_t woman_in_apron_device_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = woman_in_apron_device_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = woman_in_apron_device_start(object);
		break;
	case 2:
		states = woman_in_apron_device_wait_hit(object, states);
		break;
	case 4:
		woman_in_apron_device_idle();
		break;
	case 6:
		woman_in_apron_device_strike(object);
		break;
	case 8:
		woman_in_apron_device_strike_end(object);
		break;
	case 10:
		woman_in_apron_device_reset(object);
		break;
	case 12:
		woman_in_apron_device_reset_end(object);
		break;
	case 14:
		woman_in_apron_device_rest(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a throwable that smashes when it lands. */
void timed_throwable_update(uint16_t object, uint8_t state, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0, state_4 = 0;

	state_2 = (uint8_t)state;
	states = timed_throwable_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = throwable_start(object);
		break;
	case 2:
		timed_throwable_wait(object);
		break;
	case 4:
		timed_throwable_idle();
		break;
	case 6:
		throwable_pick_up(object);
		break;
	case 8:
		timed_throwable_throw(object);
		break;
	case 10:
		throwable_hurt_enemies(object);
		break;
	case 12:
		states = throwable_rebound(object);
		break;
	case 14:
		timed_throwable_fall(object);
		break;
	case 16:
		timed_throwable_smash_end(object);
		break;
	case 18:
		obstacle_smash(object);
		break;
	case 20:
		obstacle_smash_end(object);
		break;
	case 22:
		states = moes_street_scenery_riser_start(object);
		break;
	case 24:
		moes_street_scenery_riser_wait_boss(object);
		break;
	case 26:
		moes_street_scenery_riser_rise_slowly(object);
		break;
	case 28:
		moes_street_scenery_riser_rise_faster(object);
		break;
	case 30:
		moes_street_scenery_riser_stop(object);
		break;
	case 32:
		moes_street_scenery_riser_idle();
		break;
	case -12:
		states = obstacle_smashed_steps(object);
		break;
	case -10:
		states = obstacle_knocked_steps(object);
		break;
	case -8:
		heavy_obstacle_start(object, &states, p_left_caller);
		break;
	case -6:
		heavy_obstacle_idle();
		break;
	case -4:
	case -2:
		heavy_obstacle_hit_steps(object, &states, p_left_caller);
		break;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 >= 0)
	{
		state_4 = OBJECT(object)->state;
		if (state_4 > 2u)
		{
			states = object_take_special_hit(object, states);
			throwable_check_hit(object);
		}
	}
	states = throwable_follow_floor(object, states);
	*p_states = states;
}

/* Runs a cemetery obstacle that raises the floor and breaks when hit, some into food. */
void cemetery_obstacle_update(uint16_t object, uint8_t state, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = cemetery_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = cemetery_obstacle_start(object);
		break;
	case 2:
		cemetery_obstacle_raise_floor(object, &states, p_left_caller);
		break;
	case 4:
		states = cemetery_obstacle_wait_boss(object, states);
		break;
	case 6:
		cemetery_obstacle_idle();
		break;
	case 8:
		states = cemetery_obstacle_break(object);
		break;
	case 10:
		cemetery_obstacle_vanish(object);
		break;
	case 12:
		cemetery_obstacle_food_fall(object);
		break;
	case -4:
	case -2:
		cemetery_obstacle_broken_steps(object, &states, p_left_caller);
		break;
	}
	states = object_take_special_hit(object, states);
	check_hits_with_enemies(object);
	states = object_take_special_hit(object, states);
	*p_states = states;
}

/* Unused: the handler of list 1's type 13, which does nothing; no object of that type is put in. */
void empty_object_type_13_handler(void)
{
}

/* Unused: the handler of list 1's type 14, which does nothing; no object of that type is put in. */
void empty_object_type_14_handler(void)
{
}

/* Runs the bird that rises, flutters and comes down as an object to pick up. */
uint16_t bird_item_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bird_item_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bird_item_start(object);
		break;
	case 2:
		bird_item_rise(object);
		break;
	case 4:
		bird_item_flutter(object);
		break;
	case 6:
		bird_item_land(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the scenery that rises out of the stage once the camera reaches it. */
uint16_t rising_scenery_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = rising_scenery_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = rising_scenery_start(object);
		break;
	case 2:
		rising_scenery_wait_camera(object);
		break;
	case 4:
		rising_scenery_rise(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs an obstacle held by another object, dropped when the holder is hit or tossed after a moment. */
uint16_t tossed_obstacle_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = tossed_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case -18:
	case 0:
		states = carried_obstacle_start(object);
		break;
	case 2:
		states = tossed_obstacle_held(object);
		break;
	case 4:
		tossed_obstacle_toss(object);
		break;
	case -12:
	case 6:
		carried_obstacle_fly(object);
		break;
	case -10:
	case 8:
		carried_obstacle_bounce(object);
		break;
	case -8:
	case 10:
		carried_obstacle_land(object);
		break;
	case -6:
	case 12:
		carried_obstacle_slide(object);
		break;
	case -22:
	case -4:
		states = carried_obstacle_break_steps(object);
		break;
	case -20:
	case -2:
		states = carried_obstacle_drop_steps(object);
		break;
	case -16:
		states = carried_obstacle_held(object);
		break;
	case -14:
		carried_obstacle_thrown(object);
		break;
	}
	states = object_take_special_hit(object, states);
	carried_obstacle_check_floor(object);
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 10 scenery of stage 4 that comes down and rewrites the floor under it. */
uint16_t moes_street_scenery_dropper_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = moes_street_scenery_dropper_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return moes_street_scenery_dropper_start(object);
	case 2:
		moes_street_scenery_dropper_wait(object);
		return states;
	case 4:
		moes_street_scenery_dropper_come_down(object);
		return states;
	case 6:
		return moes_street_scenery_dropper_land(object, states);
	case 8:
		moes_street_scenery_dropper_idle();
		return states;
	}
	unreachable();
}

/* Runs the kind 10 scenery of stage 4 that rises away once the boss is beaten. */
void moes_street_scenery_riser_update(uint16_t object, uint8_t state, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = moes_street_scenery_riser_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = moes_street_scenery_riser_start(object);
		break;
	case 2:
		moes_street_scenery_riser_wait_boss(object);
		break;
	case 4:
		moes_street_scenery_riser_rise_slowly(object);
		break;
	case 6:
		moes_street_scenery_riser_rise_faster(object);
		break;
	case 8:
		moes_street_scenery_riser_stop(object);
		break;
	case 10:
		moes_street_scenery_riser_idle();
		break;
	case -34:
		states = obstacle_smashed_steps(object);
		break;
	case -32:
		states = obstacle_knocked_steps(object);
		break;
	case -30:
		heavy_obstacle_start(object, &states, p_left_caller);
		break;
	case -28:
		heavy_obstacle_idle();
		break;
	case -26:
	case -24:
		heavy_obstacle_hit_steps(object, &states, p_left_caller);
		break;
	case -22:
		states = throwable_start(object);
		break;
	case -20:
		timed_throwable_wait(object);
		break;
	case -18:
		timed_throwable_idle();
		break;
	case -16:
		throwable_pick_up(object);
		break;
	case -14:
		timed_throwable_throw(object);
		break;
	case -12:
		throwable_hurt_enemies(object);
		break;
	case -10:
		states = throwable_rebound(object);
		break;
	case -8:
		timed_throwable_fall(object);
		break;
	case -6:
		timed_throwable_smash_end(object);
		break;
	case -4:
		obstacle_smash(object);
		break;
	case -2:
		obstacle_smash_end(object);
		break;
	}
	*p_states = states;
}

/* Runs an animal that runs across the stage, which a player can pick up and throw. */
uint16_t running_animal_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0;

	state_2 = (uint8_t)state;
	states = running_animal_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = running_animal_start(object);
		break;
	case 2:
		running_animal_run(object);
		break;
	case 4:
		running_animal_stop(object);
		break;
	case 6:
		running_animal_picked_up(object);
		break;
	case 8:
		running_animal_thrown(object);
		break;
	case 10:
		running_animal_hurt_enemies(object);
		break;
	case 12:
		running_animal_land(object);
		break;
	case 14:
		running_animal_idle();
		break;
	case 16:
		running_animal_knocked(object);
		break;
	case 18:
		running_animal_knocked_away(object);
		break;
	case 20:
		running_animal_knocked_back(object);
		break;
	case 22:
		running_animal_gone();
		break;
	case -4:
	case -2:
		states = running_animal_hit_steps(object);
		break;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 < 0)
	{
		remove_off_screen(object, carry);
		return states;
	}
	face_movement(object);
	states = throwable_follow_floor(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs a rock of stage 5's gorge that breaks when hit. */
uint16_t gorge_rock_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = gorge_rock_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = gorge_rock_start(object);
		break;
	case 2:
		gorge_rock_wait_hit(object);
		break;
	case 4:
		gorge_rock_break_end(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a boulder of stage 5's gorge that falls and bounces through the stage. */
uint16_t boulder_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = boulder_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = boulder_start(object);
		break;
	case 2:
		boulder_wait(object);
		break;
	case 4:
		boulder_fall(object);
		break;
	case 6:
		boulder_bounce(object);
		break;
	case 8:
		boulder_fall_in_front(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a throwable that bounces once when it lands. */
uint16_t bouncing_throwable_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bouncing_throwable_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bouncing_throwable_start(object);
		break;
	case 2:
	case 4:
		bouncing_throwable_lie();
		break;
	case 6:
		bouncing_throwable_pick_up(object);
		break;
	case 8:
		bouncing_throwable_throw(object);
		break;
	case 10:
		bouncing_throwable_fly(object);
		break;
	case 12:
		states = throwable_rebound(object);
		break;
	case 14:
		throwable_fall(object);
		break;
	case -4:
	case -2:
		states = throwable_stop_steps(object);
		break;
	}
	states = throwable_follow_floor(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs the object on the shaking scenery that falls off it when shaken and lets out a chaser. */
uint16_t shaken_object_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = shaken_object_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = shaken_object_start(object);
		break;
	case 2:
		states = shaken_object_wait(object);
		break;
	case 4:
		shaken_object_fall(object);
		break;
	case 6:
		states = shaken_object_land(object, states);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs an obstacle thrown into Dreamland that then lies as an obstacle to pick up. */
uint16_t dreamland_obstacle_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t obstacle_x = 0, screen_offset = 0;

	state_2 = (uint8_t)state;
	states = dreamland_obstacle_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = dreamland_obstacle_start(object);
		break;
	case 2:
		states = dreamland_obstacle_drop_steps(object);
		break;
	case 4:
		dreamland_obstacle_idle();
		break;
	case 6:
		dreamland_obstacle_pick_up(object);
		break;
	case 8:
		obstacle_throw(object);
		break;
	case 10:
		obstacle_fly(object);
		break;
	case 12:
		states = obstacle_rebound(object);
		break;
	case 14:
		obstacle_rebound_rise(object);
		break;
	case 16:
		obstacle_rebound_fall(object);
		break;
	case -4:
		states = obstacle_smashed_steps(object);
		break;
	case -2:
		states = obstacle_knocked_steps(object);
		break;
	}
	states = throwable_follow_floor(object, states);
	if (OBJECT(object)->flags != 0u)
	{
		obstacle_x = OBJECT(object)->x;
		screen_offset = obstacle_x - 0x40u;
		if (screen_offset >= 0x1C0u)
			OBJECT(object)->flags = 0u;
	}
	return states;
}

/* Runs stage 1's scenery that moves across the screen and comes round again. */
uint16_t looping_scenery_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = looping_scenery_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
	case 50:
		return looping_scenery_start(object);
	case 2:
		looping_scenery_wrap(object);
		return states;
	}
	unreachable();
}

/* Runs a piece of food lying in the stage until a player eats it. */
uint16_t food_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = food_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = food_start(object);
		break;
	case 2:
		food_lie();
		break;
	case -56:
	case 4:
	case 34:
		food_eaten(object);
		break;
	case -54:
	case 6:
	case 36:
		food_eaten_shrink(object);
		break;
	case -52:
	case 8:
	case 38:
		food_eaten_vanish(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs food jumping out of the shaking scenery, then lying until eaten or gone. */
uint16_t food_jump_out_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = food_jump_out_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = food_jump_out_start(object);
		break;
	case 2:
		food_jump_out_bounce(object);
		break;
	case 4:
	case 64:
	case 94:
		food_eaten(object);
		break;
	case 6:
	case 66:
	case 96:
		food_eaten_shrink(object);
		break;
	case 8:
	case 68:
	case 98:
		food_eaten_vanish(object);
		break;
	case 10:
		food_jump_out_expire(object);
		break;
	case 12:
		food_jump_out_vanish(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 90 enemy of stage 1 that throws things: its entrance, then the enemies' shared fight. */
uint32_t fireman_goon_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		fireman_goon_setup(object);
		break;
	case 2:
		fireman_goon_entrance_steps(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs enemy action 08: the kind 90 enemy throws at its target. */
uint16_t fireman_goon_throw_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = fireman_goon_throw_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		fireman_goon_throw_wind_up(object);
		return steps;
	case 2:
		return fireman_goon_throw(object, steps);
	case 4:
		fireman_goon_throw_end(object);
		return steps;
	case -8:
		return fireman_goon_wait_camera(object, steps);
	case -6:
		fireman_goon_walk_out(object);
		return steps;
	case -4:
		fireman_goon_find_floor(object);
		return steps;
	case -2:
		fireman_goon_land(object);
		return steps;
	}
	unreachable();
}

/* Runs what the kind 90 enemy throws, gone when its animation ends. */
uint16_t fireman_goon_missile_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = fireman_goon_missile_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return fireman_goon_missile_start(object);
	case 2:
		fireman_goon_missile_fly(object);
		return states;
	case 4:
		fireman_goon_missile_spent(object);
		return states;
	case 6:
		fireman_goon_missile_end(object);
		return states;
	}
	unreachable();
}

/* Unused: the handler of list 1's type 24, which does nothing; no object of that type is put in. */
void empty_object_type_24_handler(void)
{
}

/* Runs the kind 98 enemy of Krustyland: its walk out of a door, then the enemies' shared fight. */
uint32_t one_eared_rabbit_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		one_eared_rabbit_start(object);
		break;
	case 2:
		one_eared_rabbit_entrance_steps(object);
		break;
	case -8:
	case 4:
	case 66:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 68:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 70:
		enemy_hurt(object);
		break;
	case -2:
	case 10:
	case 72:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case -20:
		teacup_goon_switch_side(object);
		break;
	case -18:
		teacup_goon_approach(object);
		break;
	case -16:
		teacup_goon_charge(object);
		break;
	case -14:
		teacup_goon_charge_hit(object);
		break;
	case -12:
		vector_goon_start(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs a bystander of stage 1 who flees when the police car stops. */
uint16_t bystander_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bystander_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bystander_start(object);
		break;
	case 2:
		states = bystander_wait_car(object, states);
		break;
	case 4:
		states = bystander_flee(object, states);
		break;
	case 6:
		bystander_gone();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Unused: would run a goon (the fixed program's setup) with the kind 98 enemy's steps; no list 1 type 3B
   is put in. */
void unused_goon_update(uint16_t object, uint8_t state, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	states = unused_goon_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = vector_goon_start(object);
		break;
	case 4:
	case 16:
	case 78:
		vector_enemy_think(object, &states, &ignored);
		break;
	case 6:
	case 18:
	case 80:
		vector_enemy_act(object, &states, &ignored);
		break;
	case 8:
	case 20:
	case 82:
		states = enemy_hurt(object);
		break;
	case 10:
	case 22:
	case 84:
		vector_enemy_climb(object, &states, &ignored);
		break;
	case 12:
		states = one_eared_rabbit_start(object);
		break;
	case 14:
		states = one_eared_rabbit_entrance_steps(object);
		break;
	case -8:
		teacup_goon_switch_side(object);
		break;
	case -6:
		teacup_goon_approach(object);
		break;
	case -4:
		teacup_goon_charge(object);
		break;
	case -2:
		teacup_goon_charge_hit(object);
		break;
	}
	vector_enemy_take_special_hit(object, &states, p_left_caller);
	states = vector_remove_past_right_edge(object, states);
	*p_states = states;
}

/* Runs enemy action 10: the kind 98 enemy strikes. */
uint16_t one_eared_rabbit_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = one_eared_rabbit_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		one_eared_rabbit_strike_swing(object);
		return steps;
	case 2:
		one_eared_rabbit_strike_hit(object);
		return steps;
	case 4:
		one_eared_rabbit_strike_recover(object);
		return steps;
	case 6:
		one_eared_rabbit_strike_end(object);
		return steps;
	case 8:
	case 10:
		return clown_ball_burst_steps(object);
	case 12:
		return clown_ball_start(object);
	case 14:
	case 16:
		clown_ball_fall(object);
		return steps;
	case 18:
		clown_ball_vanish(object);
		return steps;
	case 20:
		clown_ball_burst(object);
		return steps;
	case 22:
		clown_ball_burst_end(object);
		return steps;
	case -14:
		one_eared_rabbit_entrance_show(object);
		return steps;
	case -12:
		one_eared_rabbit_entrance_next(object);
		return steps;
	case -10:
		one_eared_rabbit_entrance_wait(object);
		return steps;
	case -8:
		one_eared_rabbit_entrance_walk(object);
		return steps;
	case -6:
		one_eared_rabbit_entrance_reach_floor(object);
		return steps;
	case -4:
		one_eared_rabbit_step_back(object);
		return steps;
	case -2:
		one_eared_rabbit_step_back_end(object);
		return steps;
	}
	unreachable();
}

/* Runs the clown on a ball: its pose until it comes on screen, then the enemies' shared fight. */
uint32_t clown_on_ball_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;
	uint8_t state_3 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		clown_on_ball_start(object);
		break;
	case 2:
		clown_on_ball_pose(object);
		break;
	case -70:
	case -58:
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -68:
	case -56:
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -66:
	case -54:
	case 8:
		enemy_hurt(object);
		break;
	case -64:
	case -52:
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	state_3 = OBJECT(object)->state;
	if (state_3 != 4u)
	{
		vector_remove_past_right_edge(object, ignored16);
		return left_caller;
	}
	OBJECT(object)->enemy_class = 0;
	OBJECT(object)->entrance_pending = 0u;
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs enemy action 1C: the clown on a ball strikes. */
uint16_t clown_on_ball_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = clown_on_ball_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		clown_on_ball_strike_swing(object);
		return steps;
	case 2:
		clown_on_ball_strike(object);
		return steps;
	case 4:
		clown_on_ball_jump(object);
		return steps;
	case 6:
		clown_on_ball_jump_fall(object);
		return steps;
	case 8:
		clown_on_ball_charge_wind_up(object);
		return steps;
	case 10:
		clown_on_ball_charge(object);
		return steps;
	case 12:
		clown_on_ball_charge_turn(object);
		return steps;
	case 14:
		clown_on_ball_charge_end(object);
		return steps;
	case 16:
		return clown_on_ball_pause(object);
	case 18:
		clown_on_ball_pause_end(object);
		return steps;
	}
	unreachable();
}

/* Runs a ball thrown off by a clown, which bursts on landing. */
uint16_t clown_ball_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = clown_ball_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = clown_ball_start(object);
		break;
	case 2:
	case 4:
		clown_ball_fall(object);
		break;
	case 6:
		clown_ball_vanish(object);
		break;
	case 8:
		clown_ball_burst(object);
		break;
	case 10:
		clown_ball_burst_end(object);
		break;
	case -26:
		one_eared_rabbit_entrance_show(object);
		break;
	case -24:
		one_eared_rabbit_entrance_next(object);
		break;
	case -22:
		one_eared_rabbit_entrance_wait(object);
		break;
	case -20:
		one_eared_rabbit_entrance_walk(object);
		break;
	case -18:
		one_eared_rabbit_entrance_reach_floor(object);
		break;
	case -16:
		one_eared_rabbit_step_back(object);
		break;
	case -14:
		one_eared_rabbit_step_back_end(object);
		break;
	case -12:
		one_eared_rabbit_strike_swing(object);
		break;
	case -10:
		one_eared_rabbit_strike_hit(object);
		break;
	case -8:
		one_eared_rabbit_strike_recover(object);
		break;
	case -6:
		one_eared_rabbit_strike_end(object);
		break;
	case -4:
	case -2:
		states = clown_ball_burst_steps(object);
		break;
	}
	states = object_take_special_hit(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Unused: runs an object with Homer's sprites that holds the player who hits it; nothing puts one in. */
uint16_t unused_homer_object_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = unused_homer_object_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = unused_homer_object_start(object);
		break;
	case 2:
		states = unused_homer_object_wait_near(object);
		break;
	case 4:
		states = unused_homer_object_wait_hit(object, states);
		break;
	case 6:
		unused_homer_object_release(object);
		break;
	case 8:
		unused_homer_object_rest(object);
		break;
	case 10:
		states = unused_homer_object_hold(object);
		break;
	case -4:
		unused_homer_object_idle();
		break;
	case -2:
		unused_homer_object_let_go(object);
		break;
	}
	states = object_take_special_hit(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs enemy action 1E: the clown on a ball jumps at its target. */
uint16_t clown_on_ball_jump_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = clown_on_ball_jump_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		clown_on_ball_jump(object);
		return steps;
	case 2:
		clown_on_ball_jump_fall(object);
		return steps;
	case 4:
		clown_on_ball_charge_wind_up(object);
		return steps;
	case 6:
		clown_on_ball_charge(object);
		return steps;
	case 8:
		clown_on_ball_charge_turn(object);
		return steps;
	case 10:
		clown_on_ball_charge_end(object);
		return steps;
	case 12:
		return clown_on_ball_pause(object);
	case 14:
		clown_on_ball_pause_end(object);
		return steps;
	case -4:
		clown_on_ball_strike_swing(object);
		return steps;
	case -2:
		clown_on_ball_strike(object);
		return steps;
	}
	unreachable();
}

/* Runs a figure of stage 1 that strikes a pose picked at random. */
uint16_t random_pose_figure_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = random_pose_figure_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = random_pose_figure_start(object);
		break;
	case 2:
		states = random_pose_figure_pose(object, states);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Unused: the handler of list 1's type 0A, which does nothing; no object of that type is put in. */
void empty_object_type_0a_handler(void)
{
}

/* Runs the kind 88 enemy of Krustyland: riding round, leaping off, then fighting. */
uint32_t teacup_goon_update(uint16_t object, uint8_t state, uint32_t left_caller)
{
	uint8_t state_2 = 0;
	uint16_t arm = 0;
	uint8_t state_3 = 0;
	uint16_t parent = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		teacup_goon_start(object);
		break;
	case 2:
		teacup_goon_wait_ride(object);
		break;
	case 4:
		teacup_goon_shown_on_ride(object);
		break;
	case 6:
		teacup_goon_riding(object);
		break;
	case 8:
		teacup_goon_leap_off(object);
		break;
	case 10:
		teacup_goon_leap_land(object);
		break;
	case 12:
		teacup_goon_ready(object);
		break;
	case 14:
		teacup_goon_ready_wait(object);
		break;
	case 16:
		left_caller = teacup_goon_fight_steps(object, left_caller);
		break;
	case 18:
		teacup_goon_hop_land(object);
		break;
	case 20:
		teacup_goon_hop_wait(object);
		break;
	case -4:
		teacup_goon_beaten(object);
		break;
	case -2:
		teacup_goon_hit_steps(object);
		break;
	}
	object_take_special_hit(object, 0u);
	state_3 = OBJECT(object)->state;
	if (state_3 < 3u)
	{
		parent = OBJECT(object)->parent;
		arm = parent;
		if (OBJECT(arm)->flags == 0u)
		{
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->state = 0xFFu;
		}
	}
	return left_caller;
}

/* Runs the unseen hub of the Krustyland ride whose arms carry kind 88 enemies. */
uint16_t teacup_goon_ride_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t players_counted = 0, riders_out = 0, too_many_out = 0;
	uint16_t hub_x = 0, hub_x_now = 0;

	state_2 = (uint8_t)state;
	states = teacup_goon_ride_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = teacup_goon_ride_start(object);
		break;
	case 2:
		states = teacup_goon_ride_put_in_arms(object, states);
		break;
	case 4:
		teacup_goon_ride_wait_signal(object);
		break;
	case 6:
		teacup_goon_ride_wait(object);
		break;
	case 8:
		teacup_goon_ride_wait_enemies(object);
		break;
	case 10:
		states = teacup_goon_ride_end(object, states);
		break;
	}
	if (OBJECT(object)->flags == 0u)
		return states;
	hub_x = OBJECT(object)->x;
	if (hub_x < 0xE0u)
		camera_x_held--;
	OBJECT(object)->teacup_goon_ride.too_many_out = 0u;
	states = krustyland_child_limits_by_players_ADDRESS;
	players_counted = io_read8(stage_player_count);
	riders_out = OBJECT(object)->teacup_goon_ride.riders_out;
	if (krustyland_child_limits_by_players[(int8_t)players_counted] < riders_out)
	{
		too_many_out = OBJECT(object)->teacup_goon_ride.too_many_out;
		OBJECT(object)->teacup_goon_ride.too_many_out = too_many_out + 1u;
	}
	hub_x_now = OBJECT(object)->x;
	if (hub_x_now >= 0x1E0u)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Runs an arm of the ride, turning round the hub with two kind 88 enemies. */
uint16_t teacup_goon_ride_arm_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = teacup_goon_ride_arm_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return teacup_goon_ride_arm_start(object);
	case 2:
		return teacup_goon_ride_arm_wait_start(object);
	case 4:
		return teacup_goon_ride_arm_turn(object);
	case 6:
		return teacup_goon_ride_arm_turn_for_time(object, states);
	case 8:
		return teacup_goon_ride_arm_turn_until_empty(object, states);
	}
	unreachable();
}

/* Runs enemy action 1F: the clown on a ball rolls at its target and back, within the screen. */
uint16_t clown_on_ball_charge_update(uint16_t object, uint8_t step)
{
	uint16_t steps = 0;
	uint16_t clown_x = 0;

	steps = clown_on_ball_charge_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		clown_on_ball_charge_wind_up(object);
		break;
	case 2:
		clown_on_ball_charge(object);
		break;
	case 4:
		clown_on_ball_charge_turn(object);
		break;
	case 6:
		clown_on_ball_charge_end(object);
		break;
	case 8:
		steps = clown_on_ball_pause(object);
		break;
	case 10:
		clown_on_ball_pause_end(object);
		break;
	case -8:
		clown_on_ball_strike_swing(object);
		break;
	case -6:
		clown_on_ball_strike(object);
		break;
	case -4:
		clown_on_ball_jump(object);
		break;
	case -2:
		clown_on_ball_jump_fall(object);
		break;
	}
	clown_x = OBJECT(object)->x;
	if (clown_x < 0x60 || clown_x > 0x15F)
		OBJECT(object)->x_speed = 0;
	return steps;
}

/* Runs enemy action 20: the clown on a ball pauses for a time by the game's rank. */
uint16_t clown_on_ball_pause_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = clown_on_ball_pause_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return clown_on_ball_pause(object);
	case 2:
		clown_on_ball_pause_end(object);
		return steps;
	case -16:
		clown_on_ball_strike_swing(object);
		return steps;
	case -14:
		clown_on_ball_strike(object);
		return steps;
	case -12:
		clown_on_ball_jump(object);
		return steps;
	case -10:
		clown_on_ball_jump_fall(object);
		return steps;
	case -8:
		clown_on_ball_charge_wind_up(object);
		return steps;
	case -6:
		clown_on_ball_charge(object);
		return steps;
	case -4:
		clown_on_ball_charge_turn(object);
		return steps;
	case -2:
		clown_on_ball_charge_end(object);
		return steps;
	}
	unreachable();
}

/* Runs the piece a beaten kind 88 enemy sheds, which bounces and blinks away. */
uint16_t teacup_goon_piece_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = teacup_goon_piece_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return teacup_goon_piece_start(object);
	case 2:
		teacup_goon_piece_fall(object);
		return states;
	case 4:
		teacup_goon_piece_blink(object);
		return states;
	}
	unreachable();
}

/* Runs the small kind A0 creature that comes in or is launched from the shaking scenery and runs off. */
uint16_t bluebird_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0;
	uint16_t creature_x = 0;

	state_2 = (uint8_t)state;
	states = bluebird_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bluebird_start(object);
		break;
	case 2:
		bluebird_enter(object);
		break;
	case 4:
		bluebird_land(object);
		break;
	case 6:
		bluebird_sit(object);
		break;
	case 8:
		bluebird_sit_for_time(object);
		break;
	case 10:
		bluebird_jump(object);
		break;
	case 12:
		bluebird_run_off(object);
		break;
	case 14:
		bluebird_speed_up(object);
		break;
	case 16:
		states = bluebird_wait_launch(object);
		break;
	case 18:
		states = bluebird_launch_fly(object, states);
		break;
	case 20:
		states = bluebird_sit_on_scenery(object);
		break;
	}
	state_3 = OBJECT(object)->state;
	if (state_3 == 7u && OBJECT(object)->flags != 0u)
	{
		creature_x = OBJECT(object)->x;
		if (creature_x >= 0x1C0u)
			OBJECT(object)->flags = 0u;
	}
	return states;
}

/* Runs the buzzing thing that spirals out and chases a player for a while. */
uint16_t buzzing_chaser_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = buzzing_chaser_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = buzzing_chaser_start(object);
		break;
	case 2:
		buzzing_chaser_rise(object);
		break;
	case 4:
		buzzing_chaser_spiral_end(object);
		break;
	case 6:
		states = buzzing_chaser_chase(object);
		break;
	case 8:
		buzzing_chaser_fly_off(object);
		break;
	case 10:
		buzzing_chaser_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs food dropped by a character, lying until eaten. */
uint16_t dropped_food_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = dropped_food_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return dropped_food_start(object);
	case -88:
	case -28:
	case 2:
		food_eaten(object);
		return states;
	case -86:
	case -26:
	case 4:
		food_eaten_shrink(object);
		return states;
	case -84:
	case -24:
	case 6:
		food_eaten_vanish(object);
		return states;
	case 8:
		return girl_with_food_start(object);
	case 10:
		girl_with_food_walk_in(object);
		return states;
	case 12:
		return girl_with_food_drop_food(object, states);
	case 14:
		girl_with_food_after_drop(object);
		return states;
	case 16:
		girl_with_food_walking();
		return states;
	case 18:
		girl_with_food_turn(object);
		return states;
	case 20:
		girl_with_food_wait(object);
		return states;
	}
	unreachable();
}

/* Runs the kind A5 character that walks in, maybe with a partner, and drops food. */
uint16_t girl_with_food_update(uint16_t object, uint8_t state)
{
	uint16_t states = 0;
	uint16_t walker_x = 0;

	states = girl_with_food_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = girl_with_food_start(object);
		break;
	case 2:
		girl_with_food_walk_in(object);
		break;
	case 4:
		states = girl_with_food_drop_food(object, states);
		break;
	case 6:
		girl_with_food_after_drop(object);
		break;
	case 8:
		girl_with_food_walking();
		break;
	case 10:
		girl_with_food_turn(object);
		break;
	case 12:
		girl_with_food_wait(object);
		break;
	case -96:
	case -36:
	case -6:
		food_eaten(object);
		break;
	case -94:
	case -34:
	case -4:
		food_eaten_shrink(object);
		break;
	case -92:
	case -32:
	case -2:
		food_eaten_vanish(object);
		break;
	case -8:
		states = dropped_food_start(object);
		break;
	}
	walker_x = OBJECT(object)->x;
	if (walker_x < 0x40 || walker_x > 0x1CF)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Runs the kind B2 object of Krustyland that idles, makes a sound when near and reacts to hits. */
uint16_t caged_gorilla_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = caged_gorilla_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = caged_gorilla_start(object);
		break;
	case 2:
		states = caged_gorilla_idle(object, states);
		break;
	case 4:
		caged_gorilla_hit(object);
		break;
	case 6:
		caged_gorilla_hit_wait(object);
		break;
	case 8:
		caged_gorilla_recover(object);
		break;
	case 10:
		caged_gorilla_recover_end(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the bear that wakes when the camera comes and rides across the stage. */
uint16_t krustyland_bear_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = krustyland_bear_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = krustyland_bear_start(object);
		break;
	case 2:
		krustyland_bear_wait_camera(object);
		break;
	case 4:
		krustyland_bear_wake(object);
		break;
	case 6:
		krustyland_bear_start_off(object);
		break;
	case 8:
		krustyland_bear_ride(object);
		break;
	case 10:
		krustyland_bear_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs an item lying in the stage until a player takes it. */
uint16_t item_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = item_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = item_start(object);
		break;
	case 2:
	case 4:
		item_lie();
		break;
	case 6:
		item_taken(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind A9 character of stage 5 that walks in, drops food and walks off. */
uint16_t sideshow_bob_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t walker_x = 0, screen_offset = 0;

	state_2 = (uint8_t)state;
	states = sideshow_bob_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = sideshow_bob_start(object);
		break;
	case 2:
		sideshow_bob_walk_in(object);
		break;
	case 4:
		states = sideshow_bob_drop_food(object, states);
		break;
	case 6:
		sideshow_bob_leave(object);
		break;
	case 8:
		sideshow_bob_walking();
		break;
	case 10:
		sideshow_bob_pause(object);
		break;
	case 12:
		sideshow_bob_pause_end(object);
		break;
	}
	if (OBJECT(object)->flags != 0u)
	{
		walker_x = OBJECT(object)->x;
		screen_offset = walker_x - 0x10u;
		if (screen_offset >= 0x1B0u)
			OBJECT(object)->flags = 0u;
	}
	return states;
}

/* Runs a character that walks in, puts down an item and walks off. */
uint16_t item_carrier_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = item_carrier_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = item_carrier_start(object);
		break;
	case 2:
		item_carrier_walk_in(object);
		break;
	case 4:
		states = item_carrier_put_down(object);
		break;
	case 6:
		item_carrier_leave(object);
		break;
	case 8:
		item_carrier_walking();
		break;
	case 10:
		item_carrier_pause(object);
		break;
	case 12:
		item_carrier_pause_end(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the item a carrier puts down, which pops up and vanishes. */
uint16_t carried_item_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = carried_item_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return carried_item_start(object);
	case 2:
		carried_item_pop(object);
		return states;
	case 4:
		food_eaten_shrink(object);
		return states;
	case 6:
		food_eaten_vanish(object);
		return states;
	}
	unreachable();
}

/* Runs enemy action 34: the clown on a ball hops away four times. */
uint16_t clown_on_ball_hop_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = clown_on_ball_hop_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		clown_on_ball_hop_away(object);
		return steps;
	case 2:
		clown_on_ball_hop(object);
		return steps;
	}
	unreachable();
}

/* Runs enemy action 36: the kind 98 enemy steps back from its target. */
uint16_t one_eared_rabbit_step_back_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = one_eared_rabbit_step_back_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		one_eared_rabbit_step_back(object);
		return steps;
	case 2:
		one_eared_rabbit_step_back_end(object);
		return steps;
	case 4:
		one_eared_rabbit_strike_swing(object);
		return steps;
	case 6:
		one_eared_rabbit_strike_hit(object);
		return steps;
	case 8:
		one_eared_rabbit_strike_recover(object);
		return steps;
	case 10:
		one_eared_rabbit_strike_end(object);
		return steps;
	case 12:
	case 14:
		return clown_ball_burst_steps(object);
	case 16:
		return clown_ball_start(object);
	case 18:
	case 20:
		clown_ball_fall(object);
		return steps;
	case 22:
		clown_ball_vanish(object);
		return steps;
	case 24:
		clown_ball_burst(object);
		return steps;
	case 26:
		clown_ball_burst_end(object);
		return steps;
	case -10:
		one_eared_rabbit_entrance_show(object);
		return steps;
	case -8:
		one_eared_rabbit_entrance_next(object);
		return steps;
	case -6:
		one_eared_rabbit_entrance_wait(object);
		return steps;
	case -4:
		one_eared_rabbit_entrance_walk(object);
		return steps;
	case -2:
		one_eared_rabbit_entrance_reach_floor(object);
		return steps;
	}
	unreachable();
}

/* Runs the forest's looping scenery, which leaves once the camera passes 06B0. */
uint16_t looping_scenery_leaving_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = looping_scenery_leaving_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case -50:
	case 0:
		return looping_scenery_start(object);
	case 2:
		looping_scenery_wrap_until_camera(object);
		return states;
	case 4:
		looping_scenery_leave(object);
		return states;
	}
	unreachable();
}

/* Unused: runs a kind B7 object that bounces in from the right; no list 0 type E5 is put in. */
void unused_kind_b7_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		unused_kind_b7_start(object);
		break;
	case 2:
		unused_kind_b7_bounce(object);
		break;
	case 4:
		unused_kind_b7_land(object);
		break;
	case 6:
		unused_kind_b7_speed_up(object);
		break;
	}
	remove_off_screen(object, carry);
}

/* Runs the kind B3 object of stage 7 that takes six hits. */
uint16_t kent_brockman_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kent_brockman_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kent_brockman_start(object);
		break;
	case 2:
		states = kent_brockman_wait_hit(object, states);
		break;
	case 4:
		kent_brockman_hit_end(object);
		break;
	case 6:
		kent_brockman_rest(object);
		break;
	case 8:
		kent_brockman_broken();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs stage 4's kind 8C bystander by its step: it stands changing poses, walks off when the scroll gets
   far enough or when hit; it can be hit and is removed off screen. */
void barney_bystander_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		barney_bystander_setup(object);
		break;
	case 2:
		barney_bystander_pose(object);
		break;
	case 4:
		barney_bystander_turn_away(object);
		break;
	case 6:
	case 12:
		barney_bystander_walk_off(object);
		break;
	case 8:
	case 14:
		barney_bystander_walking();
		break;
	case 10:
		barney_bystander_reel(object);
		break;
	case -6:
		barney_bystander_leave(object);
		break;
	case -4:
	case -2:
		barney_bystander_hurt(object);
		break;
	}
	object_take_special_hit(object, 0u);
	remove_off_screen(object, carry);
}

/* Action 19 of the enemies: does nothing. */
void empty_action_19(void)
{
}

/* Runs stage 4's kind 8A object by its step: it brings in a goon on its back, sets it down and runs off;
   it can be hit and is removed off screen. */
void woman_in_green_carrier_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		woman_in_green_carrier_setup(object);
		break;
	case 2:
		woman_in_green_carrier_pick_up(object);
		break;
	case 4:
		woman_in_green_carrier_carry(object);
		break;
	case 6:
		woman_in_green_carrier_set_down(object);
		break;
	case 8:
		woman_in_green_carrier_straighten(object);
		break;
	case 10:
		woman_in_green_carrier_done(object);
		break;
	case 12:
		woman_in_green_carrier_run_off(object);
		break;
	case 14:
		woman_in_green_carrier_running();
		break;
	case -4:
	case -2:
		woman_in_green_carrier_hurt(object);
		break;
	}
	object_take_special_hit(object, 0u);
	vector_remove_past_right_edge(object, ignored16);
}

/* Runs a zombie (stage 3) by its step: its setup, its way out of the ground, then the shared enemy steps
   (choosing and running an action, the hit reaction); checks its hits and removes it off screen. */
uint32_t zombie_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		zombie_setup(object);
		break;
	case 2:
		zombie_come_out(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs stage 3's kind 9A object by its step: it hangs out of sight, drops on a player who comes near and
   climbs back up; when hit it falls; removed off screen. */
void ghost_on_rope_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		ghost_on_rope_setup(object);
		break;
	case 2:
		ghost_on_rope_wait_mode(object);
		break;
	case 4:
		ghost_on_rope_watch(object, 0u);
		break;
	case 6:
		ghost_on_rope_drop(object, 0u);
		break;
	case 8:
		ghost_on_rope_hang(object);
		break;
	case 10:
		ghost_on_rope_climb(object);
		break;
	case 12:
		ghost_on_rope_hurt_start(object);
		break;
	case 14:
		ghost_on_rope_hurt_flash(object);
		break;
	case -44:
		zombie_start_coming_out(object);
		break;
	case -42:
		zombie_finish_rising(object);
		break;
	case -40:
		zombie_finish_climbing(object);
		break;
	case -38:
		zombie_remove_when_sunk(object);
		break;
	case -36:
		zombie_walk_in(object);
		break;
	case -34:
		zombie_burrow_start(object);
		break;
	case -32:
		zombie_burrow_move(object);
		break;
	case -30:
		zombie_burrow_surface(object);
		break;
	case -28:
		zombie_burrow_end(object);
		break;
	case -26:
		zombie_leap_start(object);
		break;
	case -24:
		zombie_leap_take_off(object);
		break;
	case -22:
		zombie_leap_rise(object);
		break;
	case -20:
		zombie_leap_fall(object);
		break;
	case -18:
		zombie_leap_turn(object);
		break;
	case -16:
		zombie_leap_end(object);
		break;
	case -14:
		zombie_swipe_start(object);
		break;
	case -12:
		zombie_swipe_hit(object);
		break;
	case -10:
		zombie_swipe_recover(object);
		break;
	case -8:
		zombie_swipe_step_back(object);
		break;
	case -6:
		zombie_swipe_end(object);
		break;
	case -4:
		ghost_on_rope_fall(object, 0u);
		break;
	case -2:
		ghost_on_rope_hurt(object);
		break;
	}
	object_take_special_hit(object, ignored16);
	vector_remove_past_right_edge(object, ignored16);
}

/* Runs a zombie of the list at 5280 by its step: it waits, rises out of the ground and drifts in the
   direction of the object kept at work RAM 1854. */
uint16_t rising_zombie_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = rising_zombie_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return rising_zombie_setup(object);
	case 2:
	case 20:
		rising_zombie_wait(object);
		return states;
	case 4:
	case 22:
		rising_zombie_climb_out(object);
		return states;
	case 6:
		return rising_zombie_aim(object, states);
	case 8:
		rising_zombie_stand(object);
		return states;
	case 10:
		rising_zombie_rise_up(object);
		return states;
	case 12:
		rising_zombie_set_off(object);
		return states;
	case 14:
		rising_zombie_drift(object);
		return states;
	case 16:
		rising_zombie_count_down(object);
		return states;
	case 18:
		rising_zombie_slow_down(object);
		return states;
	case 24:
		rising_zombie_climb_out_again(object);
		return states;
	case 26:
		rising_zombie_stand_again(object);
		return states;
	case 28:
		rising_zombie_walk_off(object);
		return states;
	}
	unreachable();
}

/* The handler of type 19 in the list at 5280: does nothing. */
void empty_object_type_19(void)
{
}

/* The zombies' close attack (action 1A) by its step: a swipe at the player, then a step back. */
uint16_t zombie_swipe_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_swipe_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_swipe_start(object);
		return steps;
	case 2:
		zombie_swipe_hit(object);
		return steps;
	case 4:
		zombie_swipe_recover(object);
		return steps;
	case 6:
		zombie_swipe_step_back(object);
		return steps;
	case 8:
		zombie_swipe_end(object);
		return steps;
	case 10:
		return ghost_on_rope_fall(object, steps);
	case 12:
		return ghost_on_rope_hurt(object);
	case 14:
		return ghost_on_rope_setup(object);
	case 16:
		ghost_on_rope_wait_mode(object);
		return steps;
	case 18:
		return ghost_on_rope_watch(object, steps);
	case 20:
		return ghost_on_rope_drop(object, steps);
	case 22:
		ghost_on_rope_hang(object);
		return steps;
	case 24:
		ghost_on_rope_climb(object);
		return steps;
	case 26:
		ghost_on_rope_hurt_start(object);
		return steps;
	case 28:
		ghost_on_rope_hurt_flash(object);
		return steps;
	case -30:
		return zombie_start_coming_out(object);
	case -28:
		zombie_finish_rising(object);
		return steps;
	case -26:
		zombie_finish_climbing(object);
		return steps;
	case -24:
		zombie_remove_when_sunk(object);
		return steps;
	case -22:
		zombie_walk_in(object);
		return steps;
	case -20:
		zombie_burrow_start(object);
		return steps;
	case -18:
		zombie_burrow_move(object);
		return steps;
	case -16:
		zombie_burrow_surface(object);
		return steps;
	case -14:
		zombie_burrow_end(object);
		return steps;
	case -12:
		zombie_leap_start(object);
		return steps;
	case -10:
		zombie_leap_take_off(object);
		return steps;
	case -8:
		zombie_leap_rise(object);
		return steps;
	case -6:
		zombie_leap_fall(object);
		return steps;
	case -4:
		zombie_leap_turn(object);
		return steps;
	case -2:
		zombie_leap_end(object);
		return steps;
	}
	unreachable();
}

/* Runs stage 4's kind 87 figure by its step: it waits for the scroll, walks up into the street, turns
   and walks off; removed off screen. */
uint16_t walking_kind_87_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = walking_kind_87_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = walking_kind_87_setup(object);
		break;
	case 2:
		walking_kind_87_wait(object);
		break;
	case 4:
		walking_kind_87_step_out(object);
		break;
	case 6:
		walking_kind_87_stop(object);
		break;
	case 8:
		walking_kind_87_walk_off(object);
		break;
	case 10:
		walking_kind_87_run_off(object);
		break;
	case 12:
		walking_kind_87_running();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 8E figure of stages 4 and 5 that stands in a pose by its step; the one of state 0 can be
   hit once work RAM 187F is set; removed off screen. */
uint16_t belly_dancer_watcher_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = belly_dancer_watcher_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = belly_dancer_watcher_setup(object);
		break;
	case 2:
		belly_dancer_watcher_stand();
		break;
	case 4:
		belly_dancer_watcher_wait_signal(object);
		break;
	case 6:
		belly_dancer_watcher_wait_hit(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 9E figure bank 15's object lets out (stage 4) by its step: it walks in, hides the object
   that let it out while it stands, shows it again, walks to and fro until the scroll moves on and
   leaves; removed off screen. */
uint16_t moe_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = moe_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = moe_setup(object);
		break;
	case 2:
		states = moe_stop(object, states);
		break;
	case 4:
		moe_wait_pose(object);
		break;
	case 6:
		moe_wait_for_scroll(object);
		break;
	case 8:
		states = moe_show_parent(object, states);
		break;
	case 10:
		moe_walk_right(object);
		break;
	case 12:
		moe_wander(object);
		break;
	case 14:
		moe_pace(object);
		break;
	case 16:
		moe_leave(object);
		break;
	case 18:
		moe_remove_at_edge(object);
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs a kind 97 zombie that rises after a wait, walks one way for a while and sinks back, by its step;
   when hit it sinks at once. */
void wandering_zombie_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		wandering_zombie_setup(object);
		break;
	case 2:
		wandering_zombie_wait(object);
		break;
	case 4:
		wandering_zombie_set_off(object);
		break;
	case 6:
		wandering_zombie_walk(object);
		break;
	case 8:
		wandering_zombie_remove_when_gone(object);
		break;
	case 10:
		wandering_zombie_start_sinking(object);
		break;
	case 12:
		wandering_zombie_remove_when_sunk(object);
		break;
	case -4:
	case -2:
		wandering_zombie_hit(object);
		break;
	}
	object_take_special_hit(object, 0u);
	vector_remove_past_right_edge(object, ignored16);
}

/* The zombies' action 1D by its step: it sinks into the ground, moves under it and comes up again
   elsewhere. */
uint16_t zombie_burrow_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_burrow_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_burrow_start(object);
		return steps;
	case 2:
		zombie_burrow_move(object);
		return steps;
	case 4:
		zombie_burrow_surface(object);
		return steps;
	case 6:
		zombie_burrow_end(object);
		return steps;
	case 8:
		zombie_leap_start(object);
		return steps;
	case 10:
		zombie_leap_take_off(object);
		return steps;
	case 12:
		zombie_leap_rise(object);
		return steps;
	case 14:
		zombie_leap_fall(object);
		return steps;
	case 16:
		zombie_leap_turn(object);
		return steps;
	case 18:
		zombie_leap_end(object);
		return steps;
	case 20:
		zombie_swipe_start(object);
		return steps;
	case 22:
		zombie_swipe_hit(object);
		return steps;
	case 24:
		zombie_swipe_recover(object);
		return steps;
	case 26:
		zombie_swipe_step_back(object);
		return steps;
	case 28:
		zombie_swipe_end(object);
		return steps;
	case 30:
		return ghost_on_rope_fall(object, steps);
	case 32:
		return ghost_on_rope_hurt(object);
	case 34:
		return ghost_on_rope_setup(object);
	case 36:
		ghost_on_rope_wait_mode(object);
		return steps;
	case 38:
		return ghost_on_rope_watch(object, steps);
	case 40:
		return ghost_on_rope_drop(object, steps);
	case 42:
		ghost_on_rope_hang(object);
		return steps;
	case 44:
		ghost_on_rope_climb(object);
		return steps;
	case 46:
		ghost_on_rope_hurt_start(object);
		return steps;
	case 48:
		ghost_on_rope_hurt_flash(object);
		return steps;
	case -10:
		return zombie_start_coming_out(object);
	case -8:
		zombie_finish_rising(object);
		return steps;
	case -6:
		zombie_finish_climbing(object);
		return steps;
	case -4:
		zombie_remove_when_sunk(object);
		return steps;
	case -2:
		zombie_walk_in(object);
		return steps;
	}
	unreachable();
}

/* Runs a kind 8E figure that waits for the screen, throws a shot again and again and runs off when hit,
   by its step; removed off screen. */
void belly_dancer_thrower_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		belly_dancer_thrower_setup(object);
		break;
	case 2:
		belly_dancer_thrower_wait(object);
		break;
	case 4:
		belly_dancer_thrower_wind_up(object);
		break;
	case 6:
		belly_dancer_thrower_throw(object);
		break;
	case 8:
		belly_dancer_thrower_follow_through(object);
		break;
	case 10:
		belly_dancer_thrower_repeat(object);
		break;
	case 12:
		belly_dancer_thrower_run_off(object);
		break;
	case 14:
		belly_dancer_thrower_running();
		break;
	case 16:
		belly_dancer_thrower_stagger(object);
		break;
	case 18:
		belly_dancer_thrower_recover(object);
		break;
	case -2:
		belly_dancer_thrower_hurt(object);
		break;
	}
	belly_dancer_thrower_check_hit(object);
	remove_off_screen(object, carry);
}

/* Runs the shot a kind 8E figure throws by its step: it flies left; when it hits something it bursts and
   goes; removed off screen. */
uint16_t spark_shot_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = spark_shot_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = spark_shot_setup(object);
		break;
	case 2:
		spark_shot_fly();
		break;
	case 4:
		spark_shot_burst_start(object);
		break;
	case 6:
		spark_shot_remove(object);
		break;
	case -4:
	case -2:
		states = spark_shot_burst(object);
		break;
	}
	if ((OBJECT(object)->flags & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->state = 0xFFu;
	}
	remove_off_screen(object, carry);
	return states;
}

/* The zombies' far attack (action 21) by its step: a leap at the player. */
uint16_t zombie_leap_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_leap_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_leap_start(object);
		return steps;
	case 2:
		zombie_leap_take_off(object);
		return steps;
	case 4:
		zombie_leap_rise(object);
		return steps;
	case 6:
		zombie_leap_fall(object);
		return steps;
	case 8:
		zombie_leap_turn(object);
		return steps;
	case 10:
		zombie_leap_end(object);
		return steps;
	case 12:
		zombie_swipe_start(object);
		return steps;
	case 14:
		zombie_swipe_hit(object);
		return steps;
	case 16:
		zombie_swipe_recover(object);
		return steps;
	case 18:
		zombie_swipe_step_back(object);
		return steps;
	case 20:
		zombie_swipe_end(object);
		return steps;
	case 22:
		return ghost_on_rope_fall(object, steps);
	case 24:
		return ghost_on_rope_hurt(object);
	case 26:
		return ghost_on_rope_setup(object);
	case 28:
		ghost_on_rope_wait_mode(object);
		return steps;
	case 30:
		return ghost_on_rope_watch(object, steps);
	case 32:
		return ghost_on_rope_drop(object, steps);
	case 34:
		ghost_on_rope_hang(object);
		return steps;
	case 36:
		ghost_on_rope_climb(object);
		return steps;
	case 38:
		ghost_on_rope_hurt_start(object);
		return steps;
	case 40:
		ghost_on_rope_hurt_flash(object);
		return steps;
	case -18:
		return zombie_start_coming_out(object);
	case -16:
		zombie_finish_rising(object);
		return steps;
	case -14:
		zombie_finish_climbing(object);
		return steps;
	case -12:
		zombie_remove_when_sunk(object);
		return steps;
	case -10:
		zombie_walk_in(object);
		return steps;
	case -8:
		zombie_burrow_start(object);
		return steps;
	case -6:
		zombie_burrow_move(object);
		return steps;
	case -4:
		zombie_burrow_surface(object);
		return steps;
	case -2:
		zombie_burrow_end(object);
		return steps;
	}
	unreachable();
}

/* Runs a lumberjack (stage 5) by its step: its setup, its jump in, then the shared enemy steps; checks
   its hits and removes it off screen. */
uint32_t lumberjack_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		lumberjack_setup(object);
		break;
	case 2:
		lumberjack_jump_in(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* The lumberjack's attack (action 22) by its step: swings of the axe, then a pause. */
uint16_t lumberjack_axe_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = lumberjack_axe_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		lumberjack_axe_start(object);
		return steps;
	case 2:
		lumberjack_axe_swing(object);
		return steps;
	case 4:
		lumberjack_axe_recover(object);
		return steps;
	case 6:
		enemy_end_action_with_animation(object);
		return steps;
	case 8:
		return lumberjack_axe_rest(object, steps);
	case 10:
		return lumberjack_axe_pause(object, steps);
	case 12:
		lumberjack_axe_wait(object);
		return steps;
	case -6:
		lumberjack_walk_in(object);
		return steps;
	case -4:
		lumberjack_jump_down(object);
		return steps;
	case -2:
		lumberjack_land(object);
		return steps;
	}
	unreachable();
}

/* Runs a gorilla (stage 5) by its step: its setup, its way in, then the shared enemy steps; checks its
   hits and removes it off screen. */
uint32_t gorilla_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		gorilla_setup(object);
		break;
	case 2:
		gorilla_come_in(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* The gorilla's close attack (action 26) by its step: a blow on the animation's marked frame. */
uint16_t gorilla_punch_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = gorilla_punch_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		gorilla_punch_start(object);
		return steps;
	case 2:
		gorilla_punch_hit(object);
		return steps;
	case 4:
		gorilla_punch_end(object);
		return steps;
	case 6:
		enemy_end_action_with_animation(object);
		return steps;
	case 8:
		return gorilla_leap_take_off(object);
	case 10:
		gorilla_leap_rise(object);
		return steps;
	case 12:
		gorilla_leap_fall(object);
		return steps;
	}
	unreachable();
}

/* Runs a zombie that comes out of the ground and takes hold of the players (stage 3) by its step; checks
   its hits and removes it off screen. */
uint32_t grabbing_zombie_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		grabbing_zombie_setup(object);
		break;
	case 2:
		grabbing_zombie_come_out(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* The grabbing zombie's action 31 by its step: it walks at its player, takes hold of him and holds on
   until he shakes it off. */
uint16_t zombie_grab_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;

	step_2 = (uint8_t)step;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return zombie_grab_start(object);
	case 2:
		return zombie_grab_reach(object);
	case 4:
		return zombie_grab_hold(object);
	case 6:
		return zombie_grab_hold_loop(object);
	}
	unreachable();
}

/* The gorilla's action 2C by its step: a leap at the player (gorilla_leap_speeds by the stage's
   difficulty). */
uint16_t gorilla_leap_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = gorilla_leap_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return gorilla_leap_take_off(object);
	case 2:
		gorilla_leap_rise(object);
		return steps;
	case 4:
		gorilla_leap_fall(object);
		return steps;
	case -8:
		gorilla_punch_start(object);
		return steps;
	case -6:
		gorilla_punch_hit(object);
		return steps;
	case -4:
		gorilla_punch_end(object);
		return steps;
	case -2:
		enemy_end_action_with_animation(object);
		return steps;
	}
	unreachable();
}

/* The gorilla's action 35 by its step: it backs away from the player for 32 frames. */
uint16_t gorilla_back_off_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = gorilla_back_off_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		gorilla_back_off_start(object);
		return steps;
	case 2:
		gorilla_back_off_end(object);
		return steps;
	}
	unreachable();
}

/* Runs a knight (stage 6) by its step: its setup, its way in, the shared enemy steps, its fall from the
   first form; beaten in its first form (field 44 set) it falls instead of dying. */
uint32_t knight_update(uint16_t object, uint8_t state, uint32_t left_caller)
{
	uint8_t state_2 = 0;
	uint16_t command = 0, ignored16 = 0;
	uint32_t left_caller_2 = 0;
	uint8_t first_form = 0, vitality = 0, state_3 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		knight_setup(object);
		break;
	case 2:
		knight_come_in(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &left_caller);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &left_caller);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &left_caller);
		break;
	case 12:
		knight_fall(object);
		break;
	case 14:
		knight_get_up(object);
		break;
	case -2:
		left_caller = knight_lose_first_form(object, left_caller);
		break;
	}
	first_form = OBJECT(object)->knight.first_form;
	if (first_form == 0u)
	{
		vector_enemy_take_special_hit(object, &ignored16, &left_caller_2);
		vector_remove_past_right_edge(object, ignored16);
		return left_caller_2;
	}
	vitality = OBJECT(object)->vitality;
	if (vitality != 0u)
	{
		vector_enemy_take_special_hit(object, &ignored16, &left_caller_2);
		vector_remove_past_right_edge(object, ignored16);
		return left_caller_2;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 >= 0)
	{
		leftover_y = knight_body_box_ADDRESS;
		vector_set_hit_box(object);
		command = 0x6300u;
		vector_queue_sound(command);
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->state = 0xFFu;
		OBJECT(object)->action_step = 0u;
		vector_remove_past_right_edge(object, ignored16);
		return left_caller;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller_2);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller_2;
}

/* The knight's attack (action 3C) by its step: a blow on the animation's marked frame. */
uint16_t knight_strike_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = knight_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		knight_strike_start(object);
		return steps;
	case 2:
		knight_strike_hit(object);
		return steps;
	case 4:
		knight_strike_end(object);
		return steps;
	}
	unreachable();
}

/* Runs the devil on a cloud (stage 6) by its step: it comes down, circles a player, stops to drop
   lightning and flies off when its time is up; checks its hits. */
void cloud_devil_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		cloud_devil_setup(object);
		break;
	case 2:
		cloud_devil_come_in(object);
		break;
	case 4:
		cloud_devil_fly(object);
		break;
	case 6:
		cloud_devil_stop_to_shoot(object);
		break;
	case 8:
		cloud_devil_drop_bolt(object);
		break;
	case 10:
		cloud_devil_resume(object);
		break;
	case -4:
		cloud_devil_die(object);
		break;
	case -2:
		cloud_devil_hurt(object);
		break;
	}
	object_take_special_hit(object, 0u);
}

/* Runs the devil's lightning bolt by its step: it strikes below the cloud with a sound and goes when its
   animation ends. */
uint16_t lightning_bolt_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = lightning_bolt_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return lightning_bolt_setup(object);
	case 2:
		lightning_bolt_end(object);
		return states;
	}
	unreachable();
}

/* Runs the robot (stage 7) by its step: its setup, the shared enemy steps and its own hit reaction;
   checks its hits, removes it off screen and plays its footsteps while it walks. */
uint32_t robot_update(uint16_t object, uint8_t state)
{
	uint8_t animation_now = 0, state_2 = 0;
	uint16_t command = 0, ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;
	uint8_t state_3 = 0, parameter = 0, animation = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		robot_setup(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		robot_hit_reaction(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	state_3 = OBJECT(object)->state;
	if (state_3 != 2u)
		return left_caller;
	parameter = OBJECT(object)->parameter;
	if (parameter != 3u)
		return left_caller;
	animation = OBJECT(object)->animation;
	animation_now = animation;
	if (animation_now == 0x87u)
	{
		command = 0x2700u;
		vector_queue_sound(command);
		return left_caller;
	}
	if (animation_now != 0x80u)
		return left_caller;
	command = 0x2700u;
	vector_queue_sound(command);
	return left_caller;
}

/* The robot's action 23 by its step: turned to its player, a shock (animation 92) that puts in sparks by
   robot_sparks_by_frame_92. */
uint16_t robot_shock_92_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = robot_shock_92_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_shock_92_start(object);
		return steps;
	case -72:
	case -58:
	case 2:
		return robot_shock_92_sparks(object, steps);
	case -34:
	case 4:
	case 62:
		robot_attack_end(object);
		return steps;
	}
	unreachable();
}

/* The robot's action 24 by its step: turned to its player, a shock (animation 91) that puts in sparks by
   robot_sparks_by_frame_91. */
uint16_t robot_shock_91_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = robot_shock_91_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_shock_91_start(object);
		return steps;
	case -126:
	case -112:
	case 2:
		return robot_shock_91_sparks(object, steps);
	case -92:
	case -54:
	case 4:
		robot_attack_end(object);
		return steps;
	}
	unreachable();
}

/* The robot's action 25 by its step: two blows on the animation's marked frames, flashing while it
   cannot be hurt. */
uint16_t robot_punch_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;
	uint8_t flashing = 0;

	step_2 = (uint8_t)step;
	steps = robot_punch_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_punch_start(object);
		break;
	case 2:
		robot_punch_first_hit(object);
		break;
	case 4:
		robot_punch_recover(object);
		break;
	case 6:
		robot_punch_second_hit(object);
		break;
	case 8:
		robot_punch_recover_again(object);
		break;
	case -2:
	case 10:
		robot_attack_end_with_animation(object);
		break;
	case 12:
		robot_advance_shock_start(object);
		break;
	case 14:
		steps = robot_advance_shock_sparks(object, steps);
		break;
	case 16:
	case 54:
	case 112:
		robot_attack_end(object);
		break;
	case -22:
	case -8:
	case 52:
		steps = robot_shock_92_sparks(object, steps);
		break;
	case -18:
	case -4:
	case 110:
		steps = robot_shock_91_sparks(object, steps);
		break;
	case -28:
		robot_combo_wind_up(object);
		break;
	case -26:
	case -14:
		robot_combo_ready(object);
		break;
	case -24:
	case -10:
		robot_shock_92_begin(object);
		break;
	case -20:
	case -6:
		robot_shock_91_begin(object);
		break;
	case -16:
		robot_combo_pause(object);
		break;
	case -12:
		robot_combo_turn(object);
		break;
	}
	flashing = OBJECT(object)->robot.flashing;
	if (flashing != 0u)
	{
		robot_flash(object);
		return steps;
	}
	return steps;
}

/* The robot's action 28 by its step: a pause, two shocks, another pause, a turn and two more shocks. */
uint16_t robot_combo_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = robot_combo_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_combo_wind_up(object);
		return steps;
	case 2:
	case 14:
		robot_combo_ready(object);
		return steps;
	case 4:
	case 18:
		robot_shock_92_begin(object);
		return steps;
	case 6:
	case 20:
	case 80:
		return robot_shock_92_sparks(object, steps);
	case 8:
	case 22:
		robot_shock_91_begin(object);
		return steps;
	case 10:
	case 24:
		return robot_shock_91_sparks(object, steps);
	case 12:
		robot_combo_pause(object);
		return steps;
	case 16:
		robot_combo_turn(object);
		return steps;
	case 26:
	case 38:
		robot_attack_end_with_animation(object);
		return steps;
	case 28:
		robot_punch_start(object);
		return steps;
	case 30:
		robot_punch_first_hit(object);
		return steps;
	case 32:
		robot_punch_recover(object);
		return steps;
	case 34:
		robot_punch_second_hit(object);
		return steps;
	case 36:
		robot_punch_recover_again(object);
		return steps;
	case 40:
		robot_advance_shock_start(object);
		return steps;
	case 42:
		return robot_advance_shock_sparks(object, steps);
	case 44:
	case 82:
		robot_attack_end(object);
		return steps;
	}
	unreachable();
}

/* The robot's action 2A by its step: it sends off one of its parts into the back of the screen. */
uint16_t robot_launch_part_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = robot_launch_part_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_launch_part_start(object);
		return steps;
	case 2:
		return robot_launch_part_release(object, steps);
	case 4:
		robot_launch_part_wait(object);
		return steps;
	case 6:
		robot_attack_end_with_animation(object);
		return steps;
	}
	unreachable();
}

/* Runs a ninja (stage 7) by its step: its setup, its way in, the shared enemy steps; when work RAM 187E
   is set it vanishes in smoke; checks its hits and removes it off screen. */
uint32_t ninja_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;
	uint8_t ninjas_vanish = 0, state_3 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		ninja_setup(object);
		break;
	case -22:
	case -10:
	case 2:
		ninja_come_in(object);
		break;
	case -20:
	case -8:
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -18:
	case -6:
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -16:
	case -4:
	case 8:
		enemy_hurt(object);
		break;
	case -14:
	case -2:
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		ninja_leave(object);
		break;
	case 14:
		ninja_leave_start(object);
		break;
	case 16:
		ninja_leave_end(object);
		break;
	case -24:
		ninja_thrower_setup(object);
		break;
	case -12:
		ninja_fighter_setup(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	ninjas_vanish = io_read8(ninjas_dismissed);
	if (ninjas_vanish != 0u && OBJECT(object)->flags != 0u)
	{
		state_3 = OBJECT(object)->state;
		if (state_3 != 6u)
		{
			OBJECT(object)->state = 6u;
			OBJECT(object)->action = 0u;
			OBJECT(object)->action_step = 0u;
			OBJECT(object)->x_speed = 0;
			OBJECT(object)->y_speed = 0;
			OBJECT(object)->z_speed = 0;
			OBJECT(object)->flags = 0x80u;
		}
	}
	return left_caller;
}

/* The ninjas' action 37 by its step: it crouches for a wait (kind_a1_attack_delays_by_players), then
   strikes. */
uint16_t ninja_crouch_strike_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_crouch_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return ninja_crouch(object);
	case 2:
		ninja_crouch_strike_start(object);
		return steps;
	case 4:
		ninja_crouch_strike_hit(object);
		return steps;
	case -34:
	case -4:
	case 6:
		ninja_attack_recover(object);
		return steps;
	case -32:
	case -26:
	case -2:
	case 8:
		ninja_attack_end(object);
		return steps;
	case -8:
		ninja_slash_start(object);
		return steps;
	case -6:
		ninja_slash_hit(object);
		return steps;
	}
	unreachable();
}

/* Runs the part the robot sends off by its step: it flies into the back of the screen, shrinking, and
   goes. */
uint16_t robot_part_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = robot_part_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return robot_part_setup(object);
	case 2:
		robot_part_launch(object);
		return states;
	case 4:
		return robot_part_fly_away(object, states);
	}
	unreachable();
}

/* The ninjas' action 2B by its step: a slash on the animation's marked frame. */
uint16_t ninja_slash_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_slash_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		ninja_slash_start(object);
		return steps;
	case 2:
		ninja_slash_hit(object);
		return steps;
	case -26:
	case 4:
	case 14:
		ninja_attack_recover(object);
		return steps;
	case -24:
	case -18:
	case 6:
	case 16:
		ninja_attack_end(object);
		return steps;
	case 8:
		return ninja_crouch(object);
	case 10:
		ninja_crouch_strike_start(object);
		return steps;
	case 12:
		ninja_crouch_strike_hit(object);
		return steps;
	}
	unreachable();
}

/* The ninjas' action 2D by its step: it throws a star (4D40 type 19) on the animation's marked frame. */
uint16_t ninja_throw_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_throw_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		ninja_throw_start(object);
		return steps;
	case 2:
		return ninja_throw_release(object, steps);
	case -2:
	case 4:
	case 28:
	case 38:
		ninja_attack_end(object);
		return steps;
	case -4:
	case 26:
	case 36:
		ninja_attack_recover(object);
		return steps;
	case -8:
		ninja_hop_strike_start(object);
		return steps;
	case -6:
		ninja_hop_strike_hit(object);
		return steps;
	}
	unreachable();
}

/* Runs a ninja's thrown star by its step; it goes when it hits something, leaves its floor or the
   screen. */
uint16_t ninja_star_update(uint16_t object, uint8_t state)
{
	uint32_t negative = 0, carry = 0;
	uint8_t cell = 0, flags_now = 0, state_2 = 0;
	uint16_t floor_cell = 0, states = 0;
	uint8_t flags = 0, star_floor_z = 0;

	state_2 = (uint8_t)state;
	states = ninja_star_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = ninja_star_setup(object);
		break;
	case 2:
		ninja_star_fly();
		break;
	}
	remove_off_screen(object, carry);
	flags = OBJECT(object)->flags;
	flags_now = flags;
	if (flags == 0u)
		return states;
	if ((flags_now & 0x20u) != 0u)
	{
		OBJECT(object)->flags = 0u;
		return states;
	}
	floor_cell = 0u;
	vector_floor_at_offset(object, &floor_cell, &negative);
	cell = (uint8_t)(floor_cell >> 8);
	if ((int8_t)cell < 0)
	{
		OBJECT(object)->flags = 0u;
		return states;
	}
	star_floor_z = (uint8_t)OBJECT(object)->floor_z;
	if ((uint8_t)((((cell & 0xFu) << 1) << 1) << 1) <= star_floor_z)
		return states;
	OBJECT(object)->flags = 0u;
	return states;
}

/* Runs a piece of the beaten robot by its step: it flies up, falls, bounces once and bursts into sparks. */
uint16_t robot_piece_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = robot_piece_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return robot_piece_setup(object);
	case 2:
		robot_piece_wait(object);
		return states;
	case 4:
		robot_piece_fall(object);
		return states;
	case 6:
		robot_piece_bounce(object);
		return states;
	case 8:
		robot_piece_burst(object);
		return states;
	}
	unreachable();
}

/* The ninjas' action 2E by its step: a high jump at the player that strikes on the way down. */
uint16_t ninja_jump_attack_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_jump_attack_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		return ninja_jump_attack_start(object);
	case 2:
		ninja_jump_attack_take_off(object);
		return steps;
	case 4:
		ninja_jump_attack_spin(object);
		return steps;
	case 6:
		ninja_jump_attack_dive(object);
		return steps;
	case 8:
		ninja_jump_attack_fall(object);
		return steps;
	case 10:
		ninja_rush_start(object);
		return steps;
	case 12:
		ninja_rush_run(object);
		return steps;
	case 14:
		ninja_rush_leap(object);
		return steps;
	case 16:
		ninja_rush_end(object);
		return steps;
	case 18:
		ninja_vanish_start(object);
		return steps;
	case 20:
		ninja_vanish_puff(object);
		return steps;
	case 22:
		ninja_vanish_move(object);
		return steps;
	case 24:
		ninja_vanish_reappear(object);
		return steps;
	case 26:
		ninja_vanish_solid(object);
		return steps;
	case 28:
		ninja_vanish_end(object);
		return steps;
	}
	unreachable();
}

/* The ninjas' action 2F by its step: it runs at the player and leaps into a slash, bouncing off the
   screen's edge. */
uint16_t ninja_rush_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_rush_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		ninja_rush_start(object);
		return steps;
	case 2:
		ninja_rush_run(object);
		return steps;
	case 4:
		ninja_rush_leap(object);
		return steps;
	case 6:
		ninja_rush_end(object);
		return steps;
	case 8:
		ninja_vanish_start(object);
		return steps;
	case 10:
		ninja_vanish_puff(object);
		return steps;
	case 12:
		ninja_vanish_move(object);
		return steps;
	case 14:
		ninja_vanish_reappear(object);
		return steps;
	case 16:
		ninja_vanish_solid(object);
		return steps;
	case 18:
		ninja_vanish_end(object);
		return steps;
	case -10:
		return ninja_jump_attack_start(object);
	case -8:
		ninja_jump_attack_take_off(object);
		return steps;
	case -6:
		ninja_jump_attack_spin(object);
		return steps;
	case -4:
		ninja_jump_attack_dive(object);
		return steps;
	case -2:
		ninja_jump_attack_fall(object);
		return steps;
	}
	unreachable();
}

/* The ninjas' action 30 by its step: a strike while it hops back. */
uint16_t ninja_hop_strike_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_hop_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		ninja_hop_strike_start(object);
		return steps;
	case 2:
		ninja_hop_strike_hit(object);
		return steps;
	case 4:
	case 34:
	case 44:
		ninja_attack_recover(object);
		return steps;
	case 6:
	case 12:
	case 36:
	case 46:
		ninja_attack_end(object);
		return steps;
	case 8:
		ninja_throw_start(object);
		return steps;
	case 10:
		return ninja_throw_release(object, steps);
	}
	unreachable();
}

/* Runs a ninja that only fights hand to hand (stage 7) by its step; checks its hits and removes it off
   screen. */
uint32_t ninja_fighter_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		ninja_fighter_setup(object);
		break;
	case -10:
	case 2:
	case 14:
		ninja_come_in(object);
		break;
	case -8:
	case 4:
	case 16:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case -6:
	case 6:
	case 18:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case -4:
	case 8:
	case 20:
		enemy_hurt(object);
		break;
	case -2:
	case 10:
	case 22:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		ninja_setup(object);
		break;
	case 24:
		ninja_leave(object);
		break;
	case 26:
		ninja_leave_start(object);
		break;
	case 28:
		ninja_leave_end(object);
		break;
	case -12:
		ninja_thrower_setup(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs stage 7's lift that brings two goons down by its step; removed off screen. */
void goon_lift_update(uint8_t state, uint16_t *p_x, uint16_t *p_states, uint32_t *p_left_caller)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = goon_lift_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = goon_lift_setup(x);
		break;
	case 2:
		states = goon_lift_arrive(x, states);
		break;
	case 4:
		goon_lift_stop(x);
		break;
	case 6:
		goon_lift_descend(x);
		break;
	case 8:
		goon_lift_settle(x);
		break;
	case 10:
		goon_lift_open(x);
		break;
	case 12:
		goon_lift_rise(x);
		break;
	case 14:
		goon_lift_remove(x);
		break;
	case -2:
		stage_7_begin_scene(&x, &states, p_left_caller);
		break;
	}
	remove_off_screen(x, carry);
	*p_x = x;
	*p_states = states;
}

/* Runs a part of stage 7's lift by its step: it changes its look at the lift's steps; removed off
   screen. */
uint16_t goon_lift_part_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = goon_lift_part_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = goon_lift_part_setup(object);
		break;
	case 2:
		states = goon_lift_part_wait_for_lift(object);
		break;
	case 4:
		goon_lift_part_change(object);
		break;
	case 6:
		goon_lift_part_idle();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* The ninjas' action 32 by its step: it vanishes in a puff of smoke, moves hidden toward the player and
   appears again. */
uint16_t ninja_vanish_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = ninja_vanish_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		ninja_vanish_start(object);
		return steps;
	case 2:
		ninja_vanish_puff(object);
		return steps;
	case 4:
		ninja_vanish_move(object);
		return steps;
	case 6:
		ninja_vanish_reappear(object);
		return steps;
	case 8:
		ninja_vanish_solid(object);
		return steps;
	case 10:
		ninja_vanish_end(object);
		return steps;
	case -18:
		return ninja_jump_attack_start(object);
	case -16:
		ninja_jump_attack_take_off(object);
		return steps;
	case -14:
		ninja_jump_attack_spin(object);
		return steps;
	case -12:
		ninja_jump_attack_dive(object);
		return steps;
	case -10:
		ninja_jump_attack_fall(object);
		return steps;
	case -8:
		ninja_rush_start(object);
		return steps;
	case -6:
		ninja_rush_run(object);
		return steps;
	case -4:
		ninja_rush_leap(object);
		return steps;
	case -2:
		ninja_rush_end(object);
		return steps;
	}
	unreachable();
}

/* Runs a kind 05 prop a stage event drops in by its step: it moves at the players, bounces away when hit
   and goes after its third landing; removed off screen. */
uint16_t bouncing_prop_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = bouncing_prop_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = bouncing_prop_setup(object);
		break;
	case 2:
	case 4:
		states = bouncing_prop_follow(object, states);
		break;
	case 6:
		bouncing_prop_stop(object);
		break;
	case 8:
		bouncing_prop_bounce_start(object);
		break;
	case 10:
		states = bouncing_prop_bounce(object);
		break;
	case 12:
		bouncing_prop_knocked(object);
		break;
	case 14:
		bouncing_prop_leave_start(object);
		break;
	case 16:
		bouncing_prop_fly_away(object);
		break;
	case 18:
		bouncing_prop_shrink_away(object);
		break;
	case 20:
		bouncing_prop_rise_out(object);
		break;
	case -4:
		states = bouncing_prop_leave(object);
		break;
	case -2:
		bouncing_prop_fall_in(object);
		break;
	}
	states = bouncing_prop_check_owner(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs a spark of the robot's shock by its step: it lasts the frames hit_spark_times gives by its state. */
uint16_t robot_spark_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = robot_spark_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return robot_spark_setup(object);
	case 2:
		robot_spark_fade(object);
		return states;
	}
	unreachable();
}

/* Runs the scrap the beaten robot leaves on the floor by its step: it lies there, can be carried, thrown
   or dropped, and bursts when it hits something or lands; removed off screen. */
uint16_t robot_scrap_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0, state_4 = 0;

	state_2 = (uint8_t)state;
	states = 0x7AECu;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = robot_scrap_setup(object);
		break;
	case 2:
	case 4:
		robot_scrap_lie();
		break;
	case 6:
		robot_scrap_pick_up(object);
		break;
	case 8:
		robot_scrap_throw(object);
		break;
	case 10:
		robot_scrap_fly(object);
		break;
	case 12:
		robot_scrap_drop(object);
		break;
	case 14:
		robot_scrap_drop_land(object);
		break;
	case 16:
		robot_scrap_burst_start(object);
		break;
	case 18:
		robot_scrap_remove(object);
		break;
	case -4:
	case -2:
		states = robot_scrap_burst(object);
		break;
	}
	state_3 = OBJECT(object)->state;
	if ((int8_t)state_3 >= 0)
	{
		state_4 = OBJECT(object)->state;
		if (state_4 > 2u)
		{
			states = object_take_special_hit(object, states);
			robot_scrap_check_hit(object);
		}
	}
	states = robot_scrap_keep_on_floor(object, states);
	remove_off_screen(object, carry);
	return states;
}

/* Runs a ninja that throws stars (stage 7) by its step; checks its hits and removes it off screen. */
uint32_t ninja_thrower_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		ninja_thrower_setup(object);
		break;
	case 2:
	case 14:
	case 26:
		ninja_come_in(object);
		break;
	case 4:
	case 16:
	case 28:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
	case 18:
	case 30:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
	case 20:
	case 32:
		enemy_hurt(object);
		break;
	case 10:
	case 22:
	case 34:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	case 12:
		ninja_fighter_setup(object);
		break;
	case 24:
		ninja_setup(object);
		break;
	case 36:
		ninja_leave(object);
		break;
	case 38:
		ninja_leave_start(object);
		break;
	case 40:
		ninja_leave_end(object);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs a walking donut (stage 6) by its step: its setup, its way in, the shared enemy steps; checks its
   hits and removes it off screen. */
uint32_t donut_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		donut_setup(object);
		break;
	case 2:
		donut_come_in(object);
		break;
	case 4:
		vector_enemy_think(object, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object);
		break;
	case 10:
		vector_enemy_climb(object, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, &left_caller);
	vector_remove_past_right_edge(object, ignored16);
	return left_caller;
}

/* Runs the flying kind B8 thrower (stage 6) by its step; checks its hits. */
void flying_saxophone_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		flying_saxophone_setup(object);
		break;
	case 2:
		flying_saxophone_come_in(object);
		break;
	case 4:
		flying_saxophone_fly(object);
		break;
	case 6:
		flying_saxophone_volley(object);
		break;
	case 8:
		flying_saxophone_single_throw(object);
		break;
	case -4:
		flying_saxophone_die(object);
		break;
	case -2:
		flying_saxophone_hurt(object);
		break;
	}
	object_take_special_hit(object, 0u);
}

/* The robot's action 39 by its step: it steps forward with a shock (animation 9D) that puts in sparks by
   robot_sparks_by_frame_9d. */
uint16_t robot_advance_shock_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = robot_advance_shock_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		robot_advance_shock_start(object);
		return steps;
	case 2:
		return robot_advance_shock_sparks(object, steps);
	case 4:
	case 42:
	case 100:
		robot_attack_end(object);
		return steps;
	case -34:
	case -20:
	case 40:
		return robot_shock_92_sparks(object, steps);
	case -30:
	case -16:
	case 98:
		return robot_shock_91_sparks(object, steps);
	case -40:
		robot_combo_wind_up(object);
		return steps;
	case -38:
	case -26:
		robot_combo_ready(object);
		return steps;
	case -36:
	case -22:
		robot_shock_92_begin(object);
		return steps;
	case -32:
	case -18:
		robot_shock_91_begin(object);
		return steps;
	case -28:
		robot_combo_pause(object);
		return steps;
	case -24:
		robot_combo_turn(object);
		return steps;
	case -14:
	case -2:
		robot_attack_end_with_animation(object);
		return steps;
	case -12:
		robot_punch_start(object);
		return steps;
	case -10:
		robot_punch_first_hit(object);
		return steps;
	case -8:
		robot_punch_recover(object);
		return steps;
	case -6:
		robot_punch_second_hit(object);
		return steps;
	case -4:
		robot_punch_recover_again(object);
		return steps;
	}
	unreachable();
}

/* The donut's action 3A by its step: it rolls at the player fast for 32 frames. */
uint16_t donut_roll_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = donut_roll_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		donut_roll_start(object);
		return steps;
	case 2:
		donut_roll_go(object);
		return steps;
	case 4:
		donut_roll_end(object);
		return steps;
	case 6:
		donut_throw_start(object);
		return steps;
	case 8:
		return donut_throw_release(object, steps);
	case 10:
		donut_throw_end(object);
		return steps;
	}
	unreachable();
}

/* The donut's action 3B by its step: it throws a small donut (5280 type DE) on the animation's marked
   frame. */
uint16_t donut_throw_action(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = donut_throw_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		donut_throw_start(object);
		return steps;
	case 2:
		return donut_throw_release(object, steps);
	case 4:
		donut_throw_end(object);
		return steps;
	case -6:
		donut_roll_start(object);
		return steps;
	case -4:
		donut_roll_go(object);
		return steps;
	case -2:
		donut_roll_end(object);
		return steps;
	}
	unreachable();
}

/* Runs what the donut throws by its step: it flies straight, fast; removed off screen. */
uint16_t donut_shot_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = donut_shot_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = donut_shot_setup(object);
		break;
	case 2:
		donut_shot_fly();
		break;
	}
	remove_off_screen(object, carry);
	return states;
}

/* Runs what the kind B8 flyer throws by its step: thrown up, it falls and bursts where it lands. */
uint16_t flying_saxophone_shot_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = flying_saxophone_shot_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return flying_saxophone_shot_setup(object);
	case 2:
		flying_saxophone_shot_fall(object);
		return states;
	case 4:
		flying_saxophone_shot_burst(object);
		return states;
	case 6:
		flying_saxophone_shot_remove(object);
		return states;
	}
	unreachable();
}

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
