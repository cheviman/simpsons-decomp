/**
 *    Name:        objects/handlers_bank_18.c
 *    Description: bank 18's jump table: its object types' and enemy actions' handlers
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs stage 4's kind 8C bystander by its step: it stands changing poses, walks off when the scroll gets
   far enough or when hit; it can be hit and is removed off screen. */
uint16_t kind_8c_bystander_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = kind_8c_bystander_setup(object);
		break;
	case 2:
		kind_8c_bystander_pose(object);
		break;
	case 4:
		kind_8c_bystander_turn_away(object);
		break;
	case 6:
	case 12:
		kind_8c_bystander_walk_off(object);
		break;
	case 8:
	case 14:
		kind_8c_bystander_walking();
		break;
	case 10:
		kind_8c_bystander_reel(object);
		break;
	case -6:
		y = kind_8c_bystander_leave(object, y);
		break;
	case -4:
	case -2:
		y = kind_8c_bystander_hurt(object, y);
		break;
	}
	object_take_special_hit(object, 0u);
	carry = remove_off_screen(object, carry);
	return y;
}

/* Action 19 of the enemies: does nothing. */
void empty_action_19(void)
{
}

/* Runs stage 4's kind 8A object by its step: it brings in a goon on its back, sets it down and runs off;
   it can be hit and is removed off screen. */
uint16_t kind_8a_carrier_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = kind_8a_carrier_setup(object);
		break;
	case 2:
		y = kind_8a_carrier_pick_up(object);
		break;
	case 4:
		kind_8a_carrier_carry(object);
		break;
	case 6:
		kind_8a_carrier_set_down(object);
		break;
	case 8:
		kind_8a_carrier_straighten(object);
		break;
	case 10:
		kind_8a_carrier_done(object);
		break;
	case 12:
		kind_8a_carrier_run_off(object);
		break;
	case 14:
		kind_8a_carrier_running();
		break;
	case -4:
	case -2:
		y = kind_8a_carrier_hurt(object, y);
		break;
	}
	object_take_special_hit(object, 0u);
	vector_remove_past_right_edge(object, ignored16);
	return y;
}

/* Runs a zombie (stage 3) by its step: its setup, its way out of the ground, then the shared enemy steps
   (choosing and running an action, the hit reaction); checks its hits and removes it off screen. */
void zombie_update(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = zombie_setup(object);
		break;
	case 2:
		y = zombie_come_out(object, y);
		break;
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object, &y, &ignored16);
		break;
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* Runs stage 3's kind 9A object by its step: it hangs out of sight, drops on a player who comes near and
   climbs back up; when hit it falls; removed off screen. */
uint16_t kind_9a_dropper_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_9a_dropper_setup(object, &y, &ignored16);
		break;
	case 2:
		kind_9a_dropper_wait_mode(object);
		break;
	case 4:
		kind_9a_dropper_watch(object, 0u);
		break;
	case 6:
		kind_9a_dropper_drop(object, &y, &ignored16);
		break;
	case 8:
		y = kind_9a_dropper_hang(object, y);
		break;
	case 10:
		kind_9a_dropper_climb(object);
		break;
	case 12:
		kind_9a_dropper_hurt_start(object);
		break;
	case 14:
		kind_9a_dropper_hurt_flash(object);
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
		y = zombie_leap_rise(object, y);
		break;
	case -20:
		y = zombie_leap_fall(object, y);
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
		y = zombie_swipe_hit(object, y);
		break;
	case -10:
		y = zombie_swipe_recover(object);
		break;
	case -8:
		zombie_swipe_step_back(object);
		break;
	case -6:
		zombie_swipe_end(object);
		break;
	case -4:
		kind_9a_dropper_fall(object, &y, &ignored16);
		break;
	case -2:
		kind_9a_dropper_hurt(object, &y, &ignored16);
		break;
	}
	object_take_special_hit(object, ignored16);
	vector_remove_past_right_edge(object, ignored16);
	return y;
}

/* Runs a zombie of the list at 5280 by its step: it waits, rises out of the ground and drifts in the
   direction of the object kept at work RAM 1854. */
void rising_zombie_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = rising_zombie_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		rising_zombie_setup(object, &y, &states);
		break;
	case 2:
	case 20:
		rising_zombie_wait(object);
		break;
	case 4:
	case 22:
		rising_zombie_climb_out(object);
		break;
	case 6:
		states = rising_zombie_aim(object, states);
		break;
	case 8:
		rising_zombie_stand(object);
		break;
	case 10:
		rising_zombie_rise_up(object);
		break;
	case 12:
		rising_zombie_set_off(object);
		break;
	case 14:
		rising_zombie_drift(object);
		break;
	case 16:
		rising_zombie_count_down(object);
		break;
	case 18:
		rising_zombie_slow_down(object);
		break;
	case 24:
		rising_zombie_climb_out_again(object);
		break;
	case 26:
		rising_zombie_stand_again(object);
		break;
	case 28:
		rising_zombie_walk_off(object);
		break;
	}
	*p_y = y;
	*p_states = states;
}

/* The handler of type 19 in the list at 5280: does nothing. */
void empty_object_type_19(void)
{
}

/* The zombies' close attack (action 1A) by its step: a swipe at the player, then a step back. */
void zombie_swipe_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_swipe_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_swipe_start(object);
		break;
	case 2:
		y = zombie_swipe_hit(object, y);
		break;
	case 4:
		y = zombie_swipe_recover(object);
		break;
	case 6:
		zombie_swipe_step_back(object);
		break;
	case 8:
		zombie_swipe_end(object);
		break;
	case 10:
		kind_9a_dropper_fall(object, &y, &steps);
		break;
	case 12:
		kind_9a_dropper_hurt(object, &y, &steps);
		break;
	case 14:
		kind_9a_dropper_setup(object, &y, &steps);
		break;
	case 16:
		kind_9a_dropper_wait_mode(object);
		break;
	case 18:
		steps = kind_9a_dropper_watch(object, steps);
		break;
	case 20:
		kind_9a_dropper_drop(object, &y, &steps);
		break;
	case 22:
		y = kind_9a_dropper_hang(object, y);
		break;
	case 24:
		kind_9a_dropper_climb(object);
		break;
	case 26:
		kind_9a_dropper_hurt_start(object);
		break;
	case 28:
		kind_9a_dropper_hurt_flash(object);
		break;
	case -30:
		steps = zombie_start_coming_out(object);
		break;
	case -28:
		zombie_finish_rising(object);
		break;
	case -26:
		zombie_finish_climbing(object);
		break;
	case -24:
		zombie_remove_when_sunk(object);
		break;
	case -22:
		zombie_walk_in(object);
		break;
	case -20:
		zombie_burrow_start(object);
		break;
	case -18:
		zombie_burrow_move(object);
		break;
	case -16:
		zombie_burrow_surface(object);
		break;
	case -14:
		zombie_burrow_end(object);
		break;
	case -12:
		zombie_leap_start(object);
		break;
	case -10:
		zombie_leap_take_off(object);
		break;
	case -8:
		y = zombie_leap_rise(object, y);
		break;
	case -6:
		y = zombie_leap_fall(object, y);
		break;
	case -4:
		zombie_leap_turn(object);
		break;
	case -2:
		zombie_leap_end(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs stage 4's kind 87 figure by its step: it waits for the scroll, walks up into the street, turns
   and walks off; removed off screen. */
void walking_kind_87_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = walking_kind_87_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		walking_kind_87_setup(object, &y, &states);
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
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 8E figure of stages 4 and 5 that stands in a pose by its step; the one of state 0 can be
   hit once work RAM 187F is set; removed off screen. */
void kind_8e_watcher_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_8e_watcher_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_8e_watcher_setup(object, &y, &states);
		break;
	case 2:
		kind_8e_watcher_stand();
		break;
	case 4:
		kind_8e_watcher_wait_signal(object);
		break;
	case 6:
		kind_8e_watcher_wait_hit(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs the kind 9E figure bank 15's object lets out (stage 4) by its step: it walks in, hides the object
   that let it out while it stands, shows it again, walks to and fro until the scroll moves on and
   leaves; removed off screen. */
void kind_9e_update(uint16_t object, uint8_t state, uint16_t *p_y, uint16_t *p_states)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_9e_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_9e_setup(object, &y, &states);
		break;
	case 2:
		states = kind_9e_stop(object, states);
		break;
	case 4:
		kind_9e_wait_pose(object);
		break;
	case 6:
		kind_9e_wait_for_scroll(object);
		break;
	case 8:
		states = kind_9e_show_parent(object, states);
		break;
	case 10:
		kind_9e_walk_right(object);
		break;
	case 12:
		kind_9e_wander(object);
		break;
	case 14:
		kind_9e_pace(object);
		break;
	case 16:
		kind_9e_leave(object);
		break;
	case 18:
		kind_9e_remove_at_edge(object);
		break;
	}
	carry = remove_off_screen(object, carry);
	*p_y = y;
	*p_states = states;
}

/* Runs a kind 97 zombie that rises after a wait, walks one way for a while and sinks back, by its step;
   when hit it sinks at once. */
uint16_t wandering_zombie_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = wandering_zombie_setup(object);
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
		y = wandering_zombie_hit(object, y);
		break;
	}
	object_take_special_hit(object, 0u);
	vector_remove_past_right_edge(object, ignored16);
	return y;
}

/* The zombies' action 1D by its step: it sinks into the ground, moves under it and comes up again
   elsewhere. */
void zombie_burrow_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_burrow_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_burrow_start(object);
		break;
	case 2:
		zombie_burrow_move(object);
		break;
	case 4:
		zombie_burrow_surface(object);
		break;
	case 6:
		zombie_burrow_end(object);
		break;
	case 8:
		zombie_leap_start(object);
		break;
	case 10:
		zombie_leap_take_off(object);
		break;
	case 12:
		y = zombie_leap_rise(object, y);
		break;
	case 14:
		y = zombie_leap_fall(object, y);
		break;
	case 16:
		zombie_leap_turn(object);
		break;
	case 18:
		zombie_leap_end(object);
		break;
	case 20:
		zombie_swipe_start(object);
		break;
	case 22:
		y = zombie_swipe_hit(object, y);
		break;
	case 24:
		y = zombie_swipe_recover(object);
		break;
	case 26:
		zombie_swipe_step_back(object);
		break;
	case 28:
		zombie_swipe_end(object);
		break;
	case 30:
		kind_9a_dropper_fall(object, &y, &steps);
		break;
	case 32:
		kind_9a_dropper_hurt(object, &y, &steps);
		break;
	case 34:
		kind_9a_dropper_setup(object, &y, &steps);
		break;
	case 36:
		kind_9a_dropper_wait_mode(object);
		break;
	case 38:
		steps = kind_9a_dropper_watch(object, steps);
		break;
	case 40:
		kind_9a_dropper_drop(object, &y, &steps);
		break;
	case 42:
		y = kind_9a_dropper_hang(object, y);
		break;
	case 44:
		kind_9a_dropper_climb(object);
		break;
	case 46:
		kind_9a_dropper_hurt_start(object);
		break;
	case 48:
		kind_9a_dropper_hurt_flash(object);
		break;
	case -10:
		steps = zombie_start_coming_out(object);
		break;
	case -8:
		zombie_finish_rising(object);
		break;
	case -6:
		zombie_finish_climbing(object);
		break;
	case -4:
		zombie_remove_when_sunk(object);
		break;
	case -2:
		zombie_walk_in(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a kind 8E figure that waits for the screen, throws a shot again and again and runs off when hit,
   by its step; removed off screen. */
uint16_t kind_8e_thrower_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = kind_8e_thrower_setup(object);
		break;
	case 2:
		kind_8e_thrower_wait(object);
		break;
	case 4:
		kind_8e_thrower_wind_up(object);
		break;
	case 6:
		y = kind_8e_thrower_throw(object, y);
		break;
	case 8:
		kind_8e_thrower_follow_through(object);
		break;
	case 10:
		kind_8e_thrower_repeat(object);
		break;
	case 12:
		kind_8e_thrower_run_off(object);
		break;
	case 14:
		kind_8e_thrower_running();
		break;
	case 16:
		kind_8e_thrower_stagger(object);
		break;
	case 18:
		kind_8e_thrower_recover(object);
		break;
	case -2:
		y = kind_8e_thrower_hurt(object, y);
		break;
	}
	kind_8e_thrower_check_hit(object);
	carry = remove_off_screen(object, carry);
	return y;
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
	carry = remove_off_screen(object, carry);
	return states;
}

/* The zombies' far attack (action 21) by its step: a leap at the player. */
void zombie_leap_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = zombie_leap_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		zombie_leap_start(object);
		break;
	case 2:
		zombie_leap_take_off(object);
		break;
	case 4:
		y = zombie_leap_rise(object, y);
		break;
	case 6:
		y = zombie_leap_fall(object, y);
		break;
	case 8:
		zombie_leap_turn(object);
		break;
	case 10:
		zombie_leap_end(object);
		break;
	case 12:
		zombie_swipe_start(object);
		break;
	case 14:
		y = zombie_swipe_hit(object, y);
		break;
	case 16:
		y = zombie_swipe_recover(object);
		break;
	case 18:
		zombie_swipe_step_back(object);
		break;
	case 20:
		zombie_swipe_end(object);
		break;
	case 22:
		kind_9a_dropper_fall(object, &y, &steps);
		break;
	case 24:
		kind_9a_dropper_hurt(object, &y, &steps);
		break;
	case 26:
		kind_9a_dropper_setup(object, &y, &steps);
		break;
	case 28:
		kind_9a_dropper_wait_mode(object);
		break;
	case 30:
		steps = kind_9a_dropper_watch(object, steps);
		break;
	case 32:
		kind_9a_dropper_drop(object, &y, &steps);
		break;
	case 34:
		y = kind_9a_dropper_hang(object, y);
		break;
	case 36:
		kind_9a_dropper_climb(object);
		break;
	case 38:
		kind_9a_dropper_hurt_start(object);
		break;
	case 40:
		kind_9a_dropper_hurt_flash(object);
		break;
	case -18:
		steps = zombie_start_coming_out(object);
		break;
	case -16:
		zombie_finish_rising(object);
		break;
	case -14:
		zombie_finish_climbing(object);
		break;
	case -12:
		zombie_remove_when_sunk(object);
		break;
	case -10:
		zombie_walk_in(object);
		break;
	case -8:
		zombie_burrow_start(object);
		break;
	case -6:
		zombie_burrow_move(object);
		break;
	case -4:
		zombie_burrow_surface(object);
		break;
	case -2:
		zombie_burrow_end(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a lumberjack (stage 5) by its step: its setup, its jump in, then the shared enemy steps; checks
   its hits and removes it off screen. */
void lumberjack_update(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = lumberjack_setup(object);
		break;
	case 2:
		y = lumberjack_jump_in(object, y);
		break;
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object, &y, &ignored16);
		break;
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* The lumberjack's attack (action 22) by its step: swings of the axe, then a pause. */
void lumberjack_axe_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = lumberjack_axe_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		lumberjack_axe_start(object);
		break;
	case 2:
		y = lumberjack_axe_swing(object, y);
		break;
	case 4:
		y = lumberjack_axe_recover(object);
		break;
	case 6:
		enemy_end_action_with_animation(object);
		break;
	case 8:
		lumberjack_axe_rest(object, &y, &steps);
		break;
	case 10:
		steps = lumberjack_axe_pause(object, steps);
		break;
	case 12:
		lumberjack_axe_wait(object);
		break;
	case -6:
		lumberjack_walk_in(object);
		break;
	case -4:
		lumberjack_jump_down(object);
		break;
	case -2:
		lumberjack_land(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a gorilla (stage 5) by its step: its setup, its way in, then the shared enemy steps; checks its
   hits and removes it off screen. */
void gorilla_update(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = gorilla_setup(object);
		break;
	case 2:
		gorilla_come_in(object);
		break;
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object, &y, &ignored16);
		break;
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* The gorilla's close attack (action 26) by its step: a blow on the animation's marked frame. */
void gorilla_punch_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = gorilla_punch_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		gorilla_punch_start(object);
		break;
	case 2:
		y = gorilla_punch_hit(object, y);
		break;
	case 4:
		y = gorilla_punch_end(object);
		break;
	case 6:
		enemy_end_action_with_animation(object);
		break;
	case 8:
		steps = gorilla_leap_take_off(object);
		break;
	case 10:
		y = gorilla_leap_rise(object, y);
		break;
	case 12:
		y = gorilla_leap_fall(object, y);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs a zombie that comes out of the ground and takes hold of the players (stage 3) by its step; checks
   its hits and removes it off screen. */
void grabbing_zombie_update(uint16_t object, uint8_t state, uint16_t *p_y, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;
	uint32_t ignored = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = grabbing_zombie_setup(object);
		break;
	case 2:
		grabbing_zombie_come_out(object);
		break;
	case 4:
		vector_enemy_think(object, &y, &ignored16, &ignored);
		break;
	case 6:
		vector_enemy_act(object, &y, &ignored16, &ignored);
		break;
	case 8:
		enemy_hurt(object, &y, &ignored16);
		break;
	case 10:
		vector_enemy_climb(object, &y, &ignored16, &ignored);
		break;
	}
	vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
	vector_remove_past_right_edge(object, ignored16);
	*p_y = y;
}

/* The grabbing zombie's action 31 by its step: it walks at its player, takes hold of him and holds on
   until he shakes it off. */
void zombie_grab_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t u = 0;

	step_2 = (uint8_t)step;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		u = zombie_grab_start(object);
		break;
	case 2:
		zombie_grab_reach(object, &y, &u);
		break;
	case 4:
		u = zombie_grab_hold(object);
		break;
	case 6:
		u = zombie_grab_hold_loop(object);
		break;
	}
	*p_y = y;
	*p_u = u;
}

/* The gorilla's action 2C by its step: a leap at the player (gorilla_leap_speeds by the stage's
   difficulty). */
void gorilla_leap_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = gorilla_leap_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		steps = gorilla_leap_take_off(object);
		break;
	case 2:
		y = gorilla_leap_rise(object, y);
		break;
	case 4:
		y = gorilla_leap_fall(object, y);
		break;
	case -8:
		gorilla_punch_start(object);
		break;
	case -6:
		y = gorilla_punch_hit(object, y);
		break;
	case -4:
		y = gorilla_punch_end(object);
		break;
	case -2:
		enemy_end_action_with_animation(object);
		break;
	}
	*p_y = y;
	*p_steps = steps;
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
void knight_update(uint16_t object, uint8_t state, uint16_t *p_box, uint32_t *p_left_caller)
{
	uint16_t box = (uint16_t)*p_box;
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t first_form = 0, vitality = 0, state_3 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		box = knight_setup(object);
		break;
	case 2:
		knight_come_in(object);
		break;
	case 4:
		vector_enemy_think(object, &box, &ignored16, p_left_caller);
		break;
	case 6:
		vector_enemy_act(object, &box, &ignored16, p_left_caller);
		break;
	case 8:
		enemy_hurt(object, &box, &ignored16);
		break;
	case 10:
		vector_enemy_climb(object, &box, &ignored16, p_left_caller);
		break;
	case 12:
		box = knight_fall(object, box);
		break;
	case 14:
		knight_get_up(object);
		break;
	case -2:
		knight_lose_first_form(object, &box, p_left_caller);
		break;
	}
	first_form = OBJECT(object)->knight.first_form;
	if (first_form == 0u)
	{
		vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
		vector_remove_past_right_edge(object, ignored16);
	}
	else
	{
		vitality = OBJECT(object)->vitality;
		if (vitality != 0u)
		{
			vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
			vector_remove_past_right_edge(object, ignored16);
		}
		else
		{
			state_3 = OBJECT(object)->state;
			if ((int8_t)state_3 >= 0)
			{
				box = knight_body_box_ADDRESS;
				vector_set_hit_box(object, box);
				command = 0x6300u;
				carry = vector_queue_sound(command);
				OBJECT(object)->flags = 0x80u;
				OBJECT(object)->state = 0xFFu;
				OBJECT(object)->action_step = 0u;
				vector_remove_past_right_edge(object, ignored16);
			}
			else
			{
				vector_enemy_take_special_hit(object, &ignored16, p_left_caller);
				vector_remove_past_right_edge(object, ignored16);
			}
		}
	}
	*p_box = box;
}

/* The knight's attack (action 3C) by its step: a blow on the animation's marked frame. */
void knight_strike_action(uint16_t object, uint8_t step, uint16_t *p_y, uint16_t *p_steps)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step_2 = 0;
	uint16_t steps = 0;

	step_2 = (uint8_t)step;
	steps = knight_strike_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_2 << 1))
	{
	case 0:
		knight_strike_start(object);
		break;
	case 2:
		y = knight_strike_hit(object, y);
		break;
	case 4:
		y = knight_strike_end(object, y);
		break;
	}
	*p_y = y;
	*p_steps = steps;
}

/* Runs the devil on a cloud (stage 6) by its step: it comes down, circles a player, stops to drop
   lightning and flies off when its time is up; checks its hits. */
uint16_t cloud_devil_update(uint16_t object, uint16_t y, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		y = cloud_devil_setup(object);
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
		y = cloud_devil_drop_bolt(object, y);
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
	return y;
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
