/**
 *    Name:        objects/handlers_bank_18.c
 *    Description: bank 18's jump table: its object types' and enemy actions' handlers
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs stage 4's kind 8C bystander by its step: it stands changing poses, walks off when the scroll gets
   far enough or when hit; it can be hit and is removed off screen. */
void kind_8c_bystander_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_8c_bystander_setup(object);
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
		kind_8c_bystander_leave(object);
		break;
	case -4:
	case -2:
		kind_8c_bystander_hurt(object);
		break;
	}
	object_take_special_hit(object, 0u);
	carry = remove_off_screen(object, carry);
}

/* Action 19 of the enemies: does nothing. */
void empty_action_19(void)
{
}

/* Runs stage 4's kind 8A object by its step: it brings in a goon on its back, sets it down and runs off;
   it can be hit and is removed off screen. */
void kind_8a_carrier_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_8a_carrier_setup(object);
		break;
	case 2:
		kind_8a_carrier_pick_up(object);
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
		kind_8a_carrier_hurt(object);
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
void kind_9a_dropper_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t ignored16 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_9a_dropper_setup(object);
		break;
	case 2:
		kind_9a_dropper_wait_mode(object);
		break;
	case 4:
		kind_9a_dropper_watch(object, 0u);
		break;
	case 6:
		kind_9a_dropper_drop(object, 0u);
		break;
	case 8:
		kind_9a_dropper_hang(object);
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
		kind_9a_dropper_fall(object, 0u);
		break;
	case -2:
		kind_9a_dropper_hurt(object);
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
		return kind_9a_dropper_fall(object, steps);
	case 12:
		return kind_9a_dropper_hurt(object);
	case 14:
		return kind_9a_dropper_setup(object);
	case 16:
		kind_9a_dropper_wait_mode(object);
		return steps;
	case 18:
		return kind_9a_dropper_watch(object, steps);
	case 20:
		return kind_9a_dropper_drop(object, steps);
	case 22:
		kind_9a_dropper_hang(object);
		return steps;
	case 24:
		kind_9a_dropper_climb(object);
		return steps;
	case 26:
		kind_9a_dropper_hurt_start(object);
		return steps;
	case 28:
		kind_9a_dropper_hurt_flash(object);
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
	carry = remove_off_screen(object, carry);
	return states;
}

/* Runs the kind 8E figure of stages 4 and 5 that stands in a pose by its step; the one of state 0 can be
   hit once work RAM 187F is set; removed off screen. */
uint16_t kind_8e_watcher_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_8e_watcher_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_8e_watcher_setup(object);
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
	return states;
}

/* Runs the kind 9E figure bank 15's object lets out (stage 4) by its step: it walks in, hides the object
   that let it out while it stands, shows it again, walks to and fro until the scroll moves on and
   leaves; removed off screen. */
uint16_t kind_9e_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_9e_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		states = kind_9e_setup(object);
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
		return kind_9a_dropper_fall(object, steps);
	case 32:
		return kind_9a_dropper_hurt(object);
	case 34:
		return kind_9a_dropper_setup(object);
	case 36:
		kind_9a_dropper_wait_mode(object);
		return steps;
	case 38:
		return kind_9a_dropper_watch(object, steps);
	case 40:
		return kind_9a_dropper_drop(object, steps);
	case 42:
		kind_9a_dropper_hang(object);
		return steps;
	case 44:
		kind_9a_dropper_climb(object);
		return steps;
	case 46:
		kind_9a_dropper_hurt_start(object);
		return steps;
	case 48:
		kind_9a_dropper_hurt_flash(object);
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
void kind_8e_thrower_update(uint16_t object, uint8_t state)
{
	uint32_t carry = 0;
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_8e_thrower_setup(object);
		break;
	case 2:
		kind_8e_thrower_wait(object);
		break;
	case 4:
		kind_8e_thrower_wind_up(object);
		break;
	case 6:
		kind_8e_thrower_throw(object);
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
		kind_8e_thrower_hurt(object);
		break;
	}
	kind_8e_thrower_check_hit(object);
	carry = remove_off_screen(object, carry);
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
		return kind_9a_dropper_fall(object, steps);
	case 24:
		return kind_9a_dropper_hurt(object);
	case 26:
		return kind_9a_dropper_setup(object);
	case 28:
		kind_9a_dropper_wait_mode(object);
		return steps;
	case 30:
		return kind_9a_dropper_watch(object, steps);
	case 32:
		return kind_9a_dropper_drop(object, steps);
	case 34:
		kind_9a_dropper_hang(object);
		return steps;
	case 36:
		kind_9a_dropper_climb(object);
		return steps;
	case 38:
		kind_9a_dropper_hurt_start(object);
		return steps;
	case 40:
		kind_9a_dropper_hurt_flash(object);
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
	uint32_t carry = 0;
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
		carry = vector_queue_sound(command);
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
