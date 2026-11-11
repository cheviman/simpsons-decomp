/**
 *    Name:        objects/handlers_bank_15.c
 *    Description: bank 15's object handlers by type, as the object lists' dispatchers reach them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
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
	carry = remove_off_screen(object, carry);
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
		fat_goon_thrower_throw(object, 0u);
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
		fat_goon_descent_fall(object, states);
		break;
	case 14:
		fat_goon_descent_land(object, states);
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
		fat_goon_walk_in_end(object, 0u);
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
		fat_goon_from_back_walk(object, 0u);
		break;
	case 32:
		fat_goon_from_back_wait(object, 0u);
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
		fat_goon_from_back_walk(object, 0u);
		break;
	case 16:
		fat_goon_from_back_wait(object, 0u);
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
		fat_goon_walk_in_end(object, 0u);
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
uint16_t kind_b2_leaper_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_b2_leaper_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_b2_leaper_start(object);
		break;
	case 2:
		states = kind_b2_leaper_jump(object);
		break;
	case 4:
		kind_b2_leaper_fall(object);
		break;
	case 6:
		kind_b2_leaper_crash(object);
		break;
	case 8:
		kind_b2_leaper_wait(object);
		break;
	case 10:
		kind_b2_leaper_vanish(object);
		break;
	case 12:
		kind_b2_leaper_idle();
		break;
	}
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
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
uint16_t kind_ab_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_ab_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_ab_start(object);
		break;
	case 2:
		kind_ab_wait_hit(object);
		break;
	case 4:
		states = kind_ab_let_out(object, states);
		break;
	case 6:
		states = kind_ab_wait_child(object, states);
		break;
	case 8:
		kind_ab_rest(object);
		break;
	case 10:
		kind_ab_done();
		break;
	}
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs the kind AC object that drops food, by its step. */
uint16_t kind_ac_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_ac_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_ac_start(object);
		break;
	case 2:
		kind_ac_wait();
		break;
	case 4:
		states = kind_ac_drop_food(object);
		break;
	case 6:
		kind_ac_done();
		break;
	}
	carry = remove_off_screen(object, carry);
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
uint16_t kind_aa_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_aa_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_aa_start(object);
	case 2:
		kind_aa_idle();
		return states;
	}
	unreachable();
}

/* Runs the kind AA objects of stage 7 that come in pairs, gone near the left edge. */
uint16_t kind_aa_pair_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_aa_pair_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_aa_pair_start(object);
	case 2:
		kind_aa_pair_leave(object);
		return states;
	}
	unreachable();
}

/* Runs the kind CB object that reacts to three hits, by its step. */
uint16_t kind_cb_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_cb_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_cb_start(object);
		break;
	case 2:
		kind_cb_wait_hit(object);
		break;
	case 4:
		kind_cb_hit_end(object);
		break;
	case 6:
		kind_cb_rest(object);
		break;
	case 8:
		kind_cb_done();
		break;
	}
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs the kind D1 piece flung off, shrinking until it vanishes. */
uint16_t kind_d1_fling_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_d1_fling_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_d1_fling_start(object);
	case 2:
		kind_d1_fling_shrink(object);
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
	carry = remove_off_screen(object, carry);
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
uint16_t kind_9e_spawner_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_9e_spawner_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_9e_spawner_start(object);
		break;
	case 2:
		states = kind_9e_spawner_put_in_object(object, states);
		break;
	case 4:
		kind_9e_spawner_wait();
		break;
	}
	carry = remove_off_screen(object, carry);
	return states;
}
