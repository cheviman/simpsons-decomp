/**
 *    Name:        objects/handlers_bank_19.c
 *    Description: bank 19's jump table: its object types' and enemy actions' handlers
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

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
void kind_b8_flyer_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;

	state_2 = (uint8_t)state;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		kind_b8_flyer_setup(object);
		break;
	case 2:
		kind_b8_flyer_come_in(object);
		break;
	case 4:
		kind_b8_flyer_fly(object);
		break;
	case 6:
		kind_b8_flyer_volley(object);
		break;
	case 8:
		kind_b8_flyer_single_throw(object);
		break;
	case -4:
		kind_b8_flyer_die(object);
		break;
	case -2:
		kind_b8_flyer_hurt(object);
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
uint16_t kind_b8_shot_update(uint16_t object, uint8_t state)
{
	uint8_t state_2 = 0;
	uint16_t states = 0;

	state_2 = (uint8_t)state;
	states = kind_b8_shot_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)state_2 << 1))
	{
	case 0:
		return kind_b8_shot_setup(object);
	case 2:
		kind_b8_shot_fall(object);
		return states;
	case 4:
		kind_b8_shot_burst(object);
		return states;
	case 6:
		kind_b8_shot_remove(object);
		return states;
	}
	unreachable();
}
