/**
 *    Name:        objects/handlers_bank_17.c
 *    Description: bank 17's object handlers by type, as the object lists' dispatchers reach them
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

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
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 90 enemy of stage 1 that throws things: its entrance, then the enemies' shared fight. */
uint32_t kind_90_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_90_setup(object);
		break;
	case 2:
		kind_90_entrance_steps(object);
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
uint16_t kind_90_throw_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = kind_90_throw_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		kind_90_throw_wind_up(object);
		return steps;
	case 2:
		return kind_90_throw(object, steps);
	case 4:
		kind_90_throw_end(object);
		return steps;
	case -8:
		return kind_90_wait_camera(object, steps);
	case -6:
		kind_90_walk_out(object);
		return steps;
	case -4:
		kind_90_find_floor(object);
		return steps;
	case -2:
		kind_90_land(object);
		return steps;
	}
	unreachable();
}

/* Runs what the kind 90 enemy throws, gone when its animation ends. */
uint16_t kind_90_missile_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_90_missile_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_90_missile_start(object);
	case 2:
		kind_90_missile_fly(object);
		return states;
	case 4:
		kind_90_missile_spent(object);
		return states;
	case 6:
		kind_90_missile_end(object);
		return states;
	}
	unreachable();
}

/* Unused: the handler of list 1's type 24, which does nothing; no object of that type is put in. */
void empty_object_type_24_handler(void)
{
}

/* Runs the kind 98 enemy of Krustyland: its walk out of a door, then the enemies' shared fight. */
uint32_t kind_98_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0, left_caller = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_98_start(object);
		break;
	case 2:
		kind_98_entrance_steps(object);
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
		kind_88_switch_side(object);
		break;
	case -18:
		kind_88_approach(object);
		break;
	case -16:
		kind_88_charge(object);
		break;
	case -14:
		kind_88_charge_hit(object);
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
	carry = remove_off_screen(object, carry);
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
		states = kind_98_start(object);
		break;
	case 14:
		states = kind_98_entrance_steps(object);
		break;
	case -8:
		kind_88_switch_side(object);
		break;
	case -6:
		kind_88_approach(object);
		break;
	case -4:
		kind_88_charge(object);
		break;
	case -2:
		kind_88_charge_hit(object);
		break;
	}
	vector_enemy_take_special_hit(object, &states, p_left_caller);
	states = vector_remove_past_right_edge(object, states);
	*p_states = states;
}

/* Runs enemy action 10: the kind 98 enemy strikes. */
uint16_t kind_98_strike_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = kind_98_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		kind_98_strike_swing(object);
		return steps;
	case 2:
		kind_98_strike_hit(object);
		return steps;
	case 4:
		kind_98_strike_recover(object);
		return steps;
	case 6:
		kind_98_strike_end(object);
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
		kind_98_entrance_show(object);
		return steps;
	case -12:
		kind_98_entrance_next(object);
		return steps;
	case -10:
		kind_98_entrance_wait(object);
		return steps;
	case -8:
		kind_98_entrance_walk(object);
		return steps;
	case -6:
		kind_98_entrance_reach_floor(object);
		return steps;
	case -4:
		kind_98_step_back(object);
		return steps;
	case -2:
		kind_98_step_back_end(object);
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
		kind_98_entrance_show(object);
		break;
	case -24:
		kind_98_entrance_next(object);
		break;
	case -22:
		kind_98_entrance_wait(object);
		break;
	case -20:
		kind_98_entrance_walk(object);
		break;
	case -18:
		kind_98_entrance_reach_floor(object);
		break;
	case -16:
		kind_98_step_back(object);
		break;
	case -14:
		kind_98_step_back_end(object);
		break;
	case -12:
		kind_98_strike_swing(object);
		break;
	case -10:
		kind_98_strike_hit(object);
		break;
	case -8:
		kind_98_strike_recover(object);
		break;
	case -6:
		kind_98_strike_end(object);
		break;
	case -4:
	case -2:
		states = clown_ball_burst_steps(object);
		break;
	}
	states = object_take_special_hit(object, states);
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
	return states;
}

/* Unused: the handler of list 1's type 0A, which does nothing; no object of that type is put in. */
void empty_object_type_0a_handler(void)
{
}

/* Runs the kind 88 enemy of Krustyland: riding round, leaping off, then fighting. */
uint32_t kind_88_update(uint16_t object, uint8_t state, uint32_t left_caller)
{
	uint8_t state_2 = 0;
	uint16_t arm = 0;
	uint8_t state_3 = 0;
	uint16_t parent = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_88_start(object);
		break;
	case 2:
		kind_88_wait_ride(object);
		break;
	case 4:
		kind_88_shown_on_ride(object);
		break;
	case 6:
		kind_88_riding(object);
		break;
	case 8:
		kind_88_leap_off(object);
		break;
	case 10:
		kind_88_leap_land(object);
		break;
	case 12:
		kind_88_ready(object);
		break;
	case 14:
		kind_88_ready_wait(object);
		break;
	case 16:
		left_caller = kind_88_fight_steps(object, left_caller);
		break;
	case 18:
		kind_88_hop_land(object);
		break;
	case 20:
		kind_88_hop_wait(object);
		break;
	case -4:
		kind_88_beaten(object);
		break;
	case -2:
		kind_88_hit_steps(object);
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
uint16_t kind_88_ride_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t players_counted = 0, riders_out = 0, too_many_out = 0;
	uint16_t hub_x = 0, hub_x_now = 0;

	state_2 = (uint8_t)state;
	states = kind_88_ride_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_88_ride_start(object);
		break;
	case 2:
		states = kind_88_ride_put_in_arms(object, states);
		break;
	case 4:
		kind_88_ride_wait_signal(object);
		break;
	case 6:
		kind_88_ride_wait(object);
		break;
	case 8:
		kind_88_ride_wait_enemies(object);
		break;
	case 10:
		states = kind_88_ride_end(object, states);
		break;
	}
	if (OBJECT(object)->flags == 0u)
		return states;
	hub_x = OBJECT(object)->x;
	if (hub_x < 0xE0u)
		camera_x_held--;
	OBJECT(object)->kind_88_ride.too_many_out = 0u;
	states = krustyland_child_limits_by_players_ADDRESS;
	players_counted = io_read8(0x1874u);
	riders_out = OBJECT(object)->kind_88_ride.riders_out;
	if (krustyland_child_limits_by_players[(int8_t)players_counted] < riders_out)
	{
		too_many_out = OBJECT(object)->kind_88_ride.too_many_out;
		OBJECT(object)->kind_88_ride.too_many_out = too_many_out + 1u;
	}
	hub_x_now = OBJECT(object)->x;
	if (hub_x_now >= 0x1E0u)
		OBJECT(object)->flags = 0u;
	return states;
}

/* Runs an arm of the ride, turning round the hub with two kind 88 enemies. */
uint16_t kind_88_ride_arm_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_88_ride_arm_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_88_ride_arm_start(object);
	case 2:
		return kind_88_ride_arm_wait_start(object);
	case 4:
		return kind_88_ride_arm_turn(object);
	case 6:
		return kind_88_ride_arm_turn_for_time(object, states);
	case 8:
		return kind_88_ride_arm_turn_until_empty(object, states);
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
uint16_t kind_88_piece_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_88_piece_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_88_piece_start(object);
	case 2:
		kind_88_piece_fall(object);
		return states;
	case 4:
		kind_88_piece_blink(object);
		return states;
	}
	unreachable();
}

/* Runs the small kind A0 creature that comes in or is launched from the shaking scenery and runs off. */
uint16_t kind_a0_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint8_t state_3 = 0;
	uint16_t creature_x = 0;

	state_2 = (uint8_t)state;
	states = kind_a0_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_a0_start(object);
		break;
	case 2:
		kind_a0_enter(object);
		break;
	case 4:
		kind_a0_land(object);
		break;
	case 6:
		kind_a0_sit(object);
		break;
	case 8:
		kind_a0_sit_for_time(object);
		break;
	case 10:
		kind_a0_jump(object);
		break;
	case 12:
		kind_a0_run_off(object);
		break;
	case 14:
		kind_a0_speed_up(object);
		break;
	case 16:
		states = kind_a0_wait_launch(object);
		break;
	case 18:
		states = kind_a0_launch_fly(object, states);
		break;
	case 20:
		states = kind_a0_sit_on_scenery(object);
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
	carry = remove_off_screen(object, carry);
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
		return kind_a5_start(object);
	case 10:
		kind_a5_walk_in(object);
		return states;
	case 12:
		return kind_a5_drop_food(object, states);
	case 14:
		kind_a5_after_drop(object);
		return states;
	case 16:
		kind_a5_walking();
		return states;
	case 18:
		kind_a5_turn(object);
		return states;
	case 20:
		kind_a5_wait(object);
		return states;
	}
	unreachable();
}

/* Runs the kind A5 character that walks in, maybe with a partner, and drops food. */
uint16_t kind_a5_update(uint16_t object, uint8_t state)
{
	uint16_t states = 0;
	uint16_t walker_x = 0;

	states = kind_a5_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state << 1))
	{
	case 0:
		states = kind_a5_start(object);
		break;
	case 2:
		kind_a5_walk_in(object);
		break;
	case 4:
		states = kind_a5_drop_food(object, states);
		break;
	case 6:
		kind_a5_after_drop(object);
		break;
	case 8:
		kind_a5_walking();
		break;
	case 10:
		kind_a5_turn(object);
		break;
	case 12:
		kind_a5_wait(object);
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
uint16_t kind_b2_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_b2_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_b2_start(object);
		break;
	case 2:
		states = kind_b2_idle(object, states);
		break;
	case 4:
		kind_b2_hit(object);
		break;
	case 6:
		kind_b2_hit_wait(object);
		break;
	case 8:
		kind_b2_recover(object);
		break;
	case 10:
		kind_b2_recover_end(object);
		break;
	}
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
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
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs the kind A9 character of stage 5 that walks in, drops food and walks off. */
uint16_t kind_a9_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;
	uint16_t walker_x = 0, screen_offset = 0;

	state_2 = (uint8_t)state;
	states = kind_a9_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_a9_start(object);
		break;
	case 2:
		kind_a9_walk_in(object);
		break;
	case 4:
		states = kind_a9_drop_food(object, states);
		break;
	case 6:
		kind_a9_leave(object);
		break;
	case 8:
		kind_a9_walking();
		break;
	case 10:
		kind_a9_pause(object);
		break;
	case 12:
		kind_a9_pause_end(object);
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
	carry = remove_off_screen(object, carry);
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
uint16_t kind_98_step_back_update(uint16_t object, uint8_t step)
{
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = kind_98_step_back_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		kind_98_step_back(object);
		return steps;
	case 2:
		kind_98_step_back_end(object);
		return steps;
	case 4:
		kind_98_strike_swing(object);
		return steps;
	case 6:
		kind_98_strike_hit(object);
		return steps;
	case 8:
		kind_98_strike_recover(object);
		return steps;
	case 10:
		kind_98_strike_end(object);
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
		kind_98_entrance_show(object);
		return steps;
	case -8:
		kind_98_entrance_next(object);
		return steps;
	case -6:
		kind_98_entrance_wait(object);
		return steps;
	case -4:
		kind_98_entrance_walk(object);
		return steps;
	case -2:
		kind_98_entrance_reach_floor(object);
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
	carry = remove_off_screen(object, carry);
}

/* Runs the kind B3 object of stage 7 that takes six hits. */
uint16_t kind_b3_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_b3_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_b3_start(object);
		break;
	case 2:
		states = kind_b3_wait_hit(object, states);
		break;
	case 4:
		kind_b3_hit_end(object);
		break;
	case 6:
		kind_b3_rest(object);
		break;
	case 8:
		kind_b3_broken();
		break;
	}
	carry = remove_off_screen(object, carry);
	return states;
}
