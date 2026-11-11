/**
 *    Name:        enemies/enemy_states.c
 *    Description: an enemy's states: thinking, attacking, the hit reactions, climbing
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Unused: an enemy's action run through tables that hold no code. */
void unused_enemy_run_action(uint16_t object)
{
	uint8_t action = 0;
	uint16_t action_handlers = 0, action_offset = 0, target = 0;
	uint16_t target_2 = 0, action_2 = 0;

	target_2 = OBJECT(object)->target;
	target = target_2;
	enemy_look_at_target(object, target);
	action_2 = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	action = (uint8_t)(action_2 >> 8);
	window_bank = unused_object_banks[(int8_t)action];
	set_lines(window_bank);
	action_handlers = unused_object_handlers_ADDRESS;
	action_offset = (uint32_t)(uint8_t)((uint32_t)action << 1) << 8;
	unused_enemy_run_action_jump(action_handlers, action_offset);
}

/* Unused: jumps to the action's handler through a table that holds no code, so it stops the game. */
void unused_enemy_run_action_jump(uint16_t u, uint16_t action_offset)
{
	invalid_jump(mem_read16(u + (int8_t)(action_offset >> 8)));
}

/* An enemy's thinking state: looks at its target (every 16 frames the nearest player again, or the one
   the fewest go after when the nearest has its share), takes or gives back a side of it, and, on the
   screen with the target in one of its behaviour's ranges, may start an attack by the range's chance;
   otherwise runs a move its behaviour picks by chance, then checks the floor and any step to climb. */
void enemy_think(uint16_t object, uint16_t *p_object_2, uint32_t *p_left_caller)
{
	bool L_07D53B = false, L_07D59B = false;
	uint32_t carry = 0;
	uint8_t action_offset = 0, attack_chance = 0, choice = 0, roll = 0, sides = 0, step = 0;
	uint16_t action_handlers = 0, d = 0, range = 0, state_record = 0, target = 0, target_player = 0;
	uint8_t attack_odds = 0;
	uint8_t retarget_time = 0, attackers = 0, attackers_left = 0, nearest_attackers = 0, attackers_limit = 0, old_attackers = 0, parameter = 0, parameter_2 = 0, parameter_3 = 0, taken_sides = 0, sides_taken = 0, target_direction = 0, sides_taken_2 = 0, sides_taken_3 = 0, side = 0, side_2 = 0, target_state = 0, parameter_4 = 0, timer = 0, timer_2 = 0, state = 0, action_chance = 0, remaining_roll = 0, choices_left = 0, parameter_5 = 0, behaviour_chance = 0, roll_before = 0, choice_before = 0;
	uint16_t target_2 = 0, least_attacked = 0, target_3 = 0, z = 0, floor_z = 0, target_dx = 0, target_dy = 0, target_dx_2 = 0, target_dy_2 = 0, action = 0, target_floor = 0, floor_z_2 = 0, floor_difference = 0, floor_gap = 0, floor_distance = 0, z_2 = 0, floor_z_3 = 0, behaviour = 0, behaviour_2 = 0;

	target_2 = OBJECT(object)->target;
	target_player = target_2;
	enemy_look_at_target(object, target_player);
	retarget_time = OBJECT(object)->retarget_time;
	OBJECT(object)->retarget_time = retarget_time - 1u;
	if (retarget_time == 1u)
	{
		OBJECT(object)->retarget_time = 0x10u;
		previous_target = target_player;
		attackers = OBJECT(target_player)->player.attackers;
		attackers_left = attackers - 1u;
		OBJECT(target_player)->player.attackers = attackers_left;
		if ((int8_t)attackers_left < 0)
			OBJECT(target_player)->player.attackers = 0u;
		target_player = enemy_target_nearest_player(object);
		nearest_attackers = OBJECT(target_player)->player.attackers;
		attackers_limit = io_read8(attackers_per_player_limit);
		if (attackers_limit <= nearest_attackers)
		{
			find_least_attacked_player();
			least_attacked = io_read16(least_attacked_player);
			target_player = least_attacked;
			OBJECT(object)->target = target_player;
		}
		old_attackers = OBJECT(target_player)->player.attackers;
		OBJECT(target_player)->player.attackers = old_attackers + 1u;
		if (target_player != previous_target)
		{
			target = previous_target;
			enemy_leave_side_if_holding(object, target);
			target_3 = OBJECT(object)->target;
			target_player = target_3;
		}
	}
	if (boss_beaten != 0u)
	{
		OBJECT(object)->flags = 0u;
		*p_object_2 = target_player;
		return;
	}
	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		apply_gravity(object, &d, &carry);
	parameter = OBJECT(object)->parameter;
	if (parameter != 0u)
	{
		parameter_2 = OBJECT(object)->parameter;
		if (parameter_2 != 1u)
		{
			parameter_3 = OBJECT(object)->parameter;
			if (parameter_3 == 2u)
			{
				taken_sides = OBJECT(target_player)->player.sides_taken;
				if (taken_sides < 0xC0u)
				{
					OBJECT(object)->parameter = 0u;
					OBJECT(object)->timer = 0u;
				}
			}
		}
		else
		{
			target_dx = OBJECT(object)->target_dx;
			if (target_dx >= 0x50u)
				enemy_leave_side(object, target_player);
			else
			{
				target_dy = OBJECT(object)->target_dy;
				if (target_dy >= 0x50u)
					enemy_leave_side(object, target_player);
			}
		}
	}
	else
	{
		sides_taken = OBJECT(target_player)->player.sides_taken;
		if (sides_taken < 0xC0u)
		{
			target_dx_2 = OBJECT(object)->target_dx;
			if (target_dx_2 < 0x40u)
			{
				target_dy_2 = OBJECT(object)->target_dy;
				if (target_dy_2 < 0x40u)
				{
					OBJECT(object)->parameter = 1u;
					OBJECT(object)->timer = 0u;
					target_direction = OBJECT(object)->target_direction;
					do
					{
						if (L_07D53B || target_direction <= 0x40u)
						{
							for (;;)
							{
								L_07D53B = false;
								sides_taken_2 = OBJECT(target_player)->player.sides_taken;
								sides = sides_taken_2;
								if ((sides & 0x40u) != 0u)
								{
									sides_taken_3 = OBJECT(target_player)->player.sides_taken;
									sides = sides_taken_3;
									if ((int8_t)sides_taken_3 < 0)
										continue;
									OBJECT(target_player)->player.sides_taken = sides | 0x80u;
									side = OBJECT(object)->enemy.side;
									OBJECT(object)->enemy.side = side & 0x7Fu;
									break;
								}
								OBJECT(target_player)->player.sides_taken = sides | 0x40u;
								side_2 = OBJECT(object)->enemy.side;
								OBJECT(object)->enemy.side = side_2 | 0x80u;
								break;
							}
						}
						else
						{
							sides_taken_3 = OBJECT(target_player)->player.sides_taken;
							sides = sides_taken_3;
							L_07D53B = (int8_t)sides_taken_3 < 0;
							if (!L_07D53B)
							{
								OBJECT(target_player)->player.sides_taken = sides | 0x80u;
								side = OBJECT(object)->enemy.side;
								OBJECT(object)->enemy.side = side & 0x7Fu;
							}
						}
					} while (L_07D53B);
				}
			}
		}
		else
		{
			OBJECT(object)->parameter = 2u;
			OBJECT(object)->timer = 0u;
		}
	}
	target_state = OBJECT(target_player)->state;
	L_07D59B = (int8_t)target_state >= 0;
	if (!L_07D59B)
	{
		parameter_4 = OBJECT(object)->parameter;
		L_07D59B = parameter_4 != 1u;
		if (!L_07D59B)
		{
			enemy_leave_side(object, target_player);
			OBJECT(object)->parameter = 3u;
			OBJECT(object)->timer = 0u;
			timer = OBJECT(object)->timer;
			if (timer != 0u)
			{
				action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
				action_handlers = enemy_think_actions_ADDRESS;
				action_offset = (uint32_t)(action >> 8) << 1;
				step = (uint8_t)action;
				switch ((int8_t)action_offset)
				{
				case 0:
					enemy_walk_to_target(object, step, &action_handlers, p_left_caller);
					break;
				case 2:
					enemy_line_up_with_target(object, step, &action_handlers, p_left_caller);
					break;
				case 4:
					enemy_keep_distance(object, step, &action_handlers, p_left_caller);
					break;
				case 6:
					enemy_back_off(object, step, &action_handlers, p_left_caller);
					break;
				case 8:
					enemy_stand_still();
					break;
				case 10:
					enemy_step_toward_target(object, step, &action_handlers, p_left_caller);
					break;
				case 12:
					enemy_circle_target(object, step, &action_handlers, p_left_caller);
					break;
				case 14:
					enemy_rush_at_target(object, step, &action_handlers, p_left_caller);
					break;
				case 16:
					enemy_line_up_and_pace(object, step, &action_handlers, p_left_caller);
					break;
				case 18:
					enemy_wait_while_target_down(object, step, &action_handlers, p_left_caller);
					break;
				case 20:
					enemy_line_up_near_target(object, step, &action_handlers, p_left_caller);
					break;
				case 22:
					enemy_wander(object, step, &action_handlers, p_left_caller);
					break;
				case 24:
					enemy_walk_to_target_side(object, step, &action_handlers, p_left_caller);
					break;
				case 26:
					enemy_get_around(object, step, &action_handlers, p_left_caller);
					break;
				}
				action_handlers = check_floor(object, action_handlers);
				enemy_start_climbing(object);
				*p_object_2 = action_handlers;
				return;
			}
		}
	}
	if (L_07D59B)
	{
		timer_2 = OBJECT(object)->timer;
		if (timer_2 != 0u)
		{
			carry = enemy_on_screen(object);
			if (carry)
			{
				state = OBJECT(target_player)->state;
				if ((int8_t)state >= 0)
				{
					target_floor = OBJECT(target_player)->floor_z;
					floor_z_2 = OBJECT(object)->floor_z;
					floor_difference = target_floor - floor_z_2;
					floor_gap = floor_difference;
					floor_distance = floor_gap >> 15 ? 0u - floor_gap : floor_gap;
					if (floor_distance <= 0x20u)
					{
						z_2 = OBJECT(object)->z;
						floor_z_3 = OBJECT(object)->floor_z;
						if (z_2 == floor_z_3)
						{
							behaviour = OBJECT(object)->behaviour;
							range = behaviour + 0x28u;
							enemy_find_attack_range(object, &range, &d, &carry);
							attack_chance = (uint8_t)(d >> 8);
							if (carry)
							{
								attack_odds = attack_chance;
								d = enemy_random((uint8_t)d);
								roll = (uint8_t)(d >> 8);
								if (roll < attack_odds)
								{
									d = enemy_random((uint8_t)d);
									roll = (uint8_t)(d >> 8);
									choice = 4u;
									range += 7u;
									do
									{
										action_chance = BEHAVIOUR_CHANCE(range + (int8_t)choice);
										remaining_roll = roll;
										roll = remaining_roll - action_chance;
										if (remaining_roll < action_chance)
										{
											range -= 4u;
											OBJECT(object)->action = BEHAVIOUR_ACTION(range + (int8_t)choice);
											OBJECT(object)->state = 3u;
											OBJECT(object)->action_step = 0u;
											OBJECT(object)->x_speed = 0;
											OBJECT(object)->y_speed = 0;
											OBJECT(object)->z_speed = 0;
											*p_object_2 = range;
											return;
										}
										choices_left = choice;
										choice = choices_left - 1u;
									} while (choices_left != 1u);
								}
							}
						}
					}
				}
			}
			timer = OBJECT(object)->timer;
			if (timer != 0u)
			{
				action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
				action_handlers = enemy_think_actions_ADDRESS;
				action_offset = (uint32_t)(action >> 8) << 1;
				step = (uint8_t)action;
				switch ((int8_t)action_offset)
				{
				case 0:
					enemy_walk_to_target(object, step, &action_handlers, p_left_caller);
					break;
				case 2:
					enemy_line_up_with_target(object, step, &action_handlers, p_left_caller);
					break;
				case 4:
					enemy_keep_distance(object, step, &action_handlers, p_left_caller);
					break;
				case 6:
					enemy_back_off(object, step, &action_handlers, p_left_caller);
					break;
				case 8:
					enemy_stand_still();
					break;
				case 10:
					enemy_step_toward_target(object, step, &action_handlers, p_left_caller);
					break;
				case 12:
					enemy_circle_target(object, step, &action_handlers, p_left_caller);
					break;
				case 14:
					enemy_rush_at_target(object, step, &action_handlers, p_left_caller);
					break;
				case 16:
					enemy_line_up_and_pace(object, step, &action_handlers, p_left_caller);
					break;
				case 18:
					enemy_wait_while_target_down(object, step, &action_handlers, p_left_caller);
					break;
				case 20:
					enemy_line_up_near_target(object, step, &action_handlers, p_left_caller);
					break;
				case 22:
					enemy_wander(object, step, &action_handlers, p_left_caller);
					break;
				case 24:
					enemy_walk_to_target_side(object, step, &action_handlers, p_left_caller);
					break;
				case 26:
					enemy_get_around(object, step, &action_handlers, p_left_caller);
					break;
				}
				action_handlers = check_floor(object, action_handlers);
				enemy_start_climbing(object);
				*p_object_2 = action_handlers;
				return;
			}
		}
	}
	behaviour_2 = OBJECT(object)->behaviour;
	parameter_5 = OBJECT(object)->parameter;
	state_record = behaviour_2 + (int8_t)((((uint32_t)parameter_5 << 1) << 1) << 1);
	d = enemy_random((uint8_t)d);
	roll = (uint8_t)(d >> 8);
	choice = 4u;
	state_record += 3u;
	do
	{
		behaviour_chance = BEHAVIOUR_CHANCE(state_record + (int8_t)choice);
		roll_before = roll;
		roll = roll_before - behaviour_chance;
		if (roll_before < behaviour_chance)
		{
			choice--;
			break;
		}
		choice_before = choice;
		choice = choice_before - 1u;
	} while (choice_before != 1u);
	state_record -= 3u;
	OBJECT(object)->action = BEHAVIOUR_ACTION(state_record + (int8_t)choice);
	OBJECT(object)->action_step = 0u;
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	action_handlers = enemy_think_actions_ADDRESS;
	action_offset = (uint32_t)(action >> 8) << 1;
	step = (uint8_t)action;
	switch ((int8_t)action_offset)
	{
	case 0:
		enemy_walk_to_target(object, step, &action_handlers, p_left_caller);
		break;
	case 2:
		enemy_line_up_with_target(object, step, &action_handlers, p_left_caller);
		break;
	case 4:
		enemy_keep_distance(object, step, &action_handlers, p_left_caller);
		break;
	case 6:
		enemy_back_off(object, step, &action_handlers, p_left_caller);
		break;
	case 8:
		enemy_stand_still();
		break;
	case 10:
		enemy_step_toward_target(object, step, &action_handlers, p_left_caller);
		break;
	case 12:
		enemy_circle_target(object, step, &action_handlers, p_left_caller);
		break;
	case 14:
		enemy_rush_at_target(object, step, &action_handlers, p_left_caller);
		break;
	case 16:
		enemy_line_up_and_pace(object, step, &action_handlers, p_left_caller);
		break;
	case 18:
		enemy_wait_while_target_down(object, step, &action_handlers, p_left_caller);
		break;
	case 20:
		enemy_line_up_near_target(object, step, &action_handlers, p_left_caller);
		break;
	case 22:
		enemy_wander(object, step, &action_handlers, p_left_caller);
		break;
	case 24:
		enemy_walk_to_target_side(object, step, &action_handlers, p_left_caller);
		break;
	case 26:
		enemy_get_around(object, step, &action_handlers, p_left_caller);
		break;
	}
	action_handlers = check_floor(object, action_handlers);
	enemy_start_climbing(object);
	*p_object_2 = action_handlers;
}

/* An enemy's attacking state: lands it if it falls, looks at its target, runs the attack in its bank
   (action_banks and the handlers after them) and checks the floor. */
void enemy_attack(uint16_t object, uint16_t *p_attack_handlers, uint32_t *p_left_caller)
{
	uint8_t attack = 0, step = 0;
	uint16_t attack_handlers = 0, target = 0;
	uint8_t saved_action_step = 0;
	uint16_t z = 0, floor_z = 0, target_2 = 0, action = 0;

	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		land_if_falling(object);
	target_2 = OBJECT(object)->target;
	target = target_2;
	enemy_look_at_target(object, target);
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	attack = (uint8_t)(action >> 8);
	saved_action_step = action;
	window_bank = action_banks[(int8_t)attack];
	set_lines(window_bank);
	attack_handlers = enemy_action_handlers_ADDRESS;
	attack = (uint32_t)attack << 1;
	step = saved_action_step;
	switch ((int8_t)attack)
	{
	case 0:
		attack_handlers = goon_wait_then_strike(object, step);
		break;
	case 2:
		attack_handlers = goon_wait_then_strike_2(object, step);
		break;
	case 4:
		attack_handlers = goon_quick_strike(object, step);
		break;
	case 6:
		attack_handlers = goon_quick_strike_2(object, step);
		break;
	case 8:
		attack_handlers = goon_jump_attack(object, step);
		break;
	case 10:
		goon_jump_up_or_grab(object, step, &attack_handlers, p_left_caller);
		break;
	case 12:
		attack_handlers = hat_goon_throw_hat(object, step);
		break;
	case 14:
		attack_handlers = goon_strike_and_run(object, step);
		break;
	case 16:
		attack_handlers = kind_90_throw_update(object, step);
		break;
	case 18:
		attack_handlers = fat_goon_walk_up_strike_update(object, step);
		break;
	case 20:
		attack_handlers = fat_goon_body_slam_update(object, step);
		break;
	case 22:
		attack_handlers = fat_goon_strike_update(object, step);
		break;
	case 24:
		attack_handlers = fat_goon_reach_strike_update(object, step);
		break;
	case 26:
		attack_handlers = fat_goon_idle_action_update(object, step);
		break;
	case 28:
		attack_handlers = fat_goon_heavy_strike_update(object, step);
		break;
	case 30:
		goon_grab(object, step, &attack_handlers, p_left_caller);
		break;
	case 32:
		attack_handlers = kind_98_strike_update(object, step);
		break;
	case 34:
		attack_handlers = umbrella_goon_strike(object, step);
		break;
	case 36:
		attack_handlers = umbrella_goon_charge(object, step);
		break;
	case 38:
		attack_handlers = umbrella_goon_long_strike(object, step);
		break;
	case 40:
		attack_handlers = shovel_goon_strike(object, step);
		break;
	case 42:
		attack_handlers = shovel_goon_far_strike(object, step);
		break;
	case 44:
		attack_handlers = umbrella_goon_quick_strike(object, step);
		break;
	case 46:
		attack_handlers = goon_dash_strike(object, step);
		break;
	case 48:
		attack_handlers = goon_keep_distance(object, step);
		break;
	case 50:
		empty_action_19();
		break;
	case 52:
		attack_handlers = zombie_swipe_action(object, step);
		break;
	case 54:
		attack_handlers = bomb_goon_throw(object, step);
		break;
	case 56:
		attack_handlers = clown_on_ball_strike_update(object, step);
		break;
	case 58:
		attack_handlers = zombie_burrow_action(object, step);
		break;
	case 60:
		attack_handlers = clown_on_ball_jump_update(object, step);
		break;
	case 62:
		attack_handlers = clown_on_ball_charge_update(object, step);
		break;
	case 64:
		attack_handlers = clown_on_ball_pause_update(object, step);
		break;
	case 66:
		attack_handlers = zombie_leap_action(object, step);
		break;
	case 68:
		attack_handlers = lumberjack_axe_action(object, step);
		break;
	case 70:
		attack_handlers = robot_shock_92_action(object, step);
		break;
	case 72:
		attack_handlers = robot_shock_91_action(object, step);
		break;
	case 74:
		attack_handlers = robot_punch_action(object, step);
		break;
	case 76:
		attack_handlers = gorilla_punch_action(object, step);
		break;
	case 78:
		attack_handlers = goon_approach_strike(object, step);
		break;
	case 80:
		attack_handlers = robot_combo_action(object, step);
		break;
	case 82:
		attack_handlers = fat_goon_bump_update(object, step);
		break;
	case 84:
		attack_handlers = robot_launch_part_action(object, step);
		break;
	case 86:
		attack_handlers = ninja_slash_action(object, step);
		break;
	case 88:
		attack_handlers = gorilla_leap_action(object, step);
		break;
	case 90:
		attack_handlers = ninja_throw_action(object, step);
		break;
	case 92:
		attack_handlers = ninja_jump_attack_action(object, step);
		break;
	case 94:
		attack_handlers = ninja_rush_action(object, step);
		break;
	case 96:
		attack_handlers = ninja_hop_strike_action(object, step);
		break;
	case 98:
		attack_handlers = zombie_grab_action(object, step);
		break;
	case 100:
		attack_handlers = ninja_vanish_action(object, step);
		break;
	case 102:
		attack_handlers = shovel_goon_close_strike(object, step);
		break;
	case 104:
		attack_handlers = clown_on_ball_hop_update(object, step);
		break;
	case 106:
		attack_handlers = gorilla_back_off_action(object, step);
		break;
	case 108:
		attack_handlers = kind_98_step_back_update(object, step);
		break;
	case 110:
		attack_handlers = ninja_crouch_strike_action(object, step);
		break;
	case 112:
		attack_handlers = fat_goon_grab_update(object, step);
		break;
	case 114:
		attack_handlers = robot_advance_shock_action(object, step);
		break;
	case 116:
		attack_handlers = donut_roll_action(object, step);
		break;
	case 118:
		attack_handlers = donut_throw_action(object, step);
		break;
	case 120:
		attack_handlers = knight_strike_action(object, step);
		break;
	case 122:
		attack_handlers = goon_back_off(object, step);
		break;
	case 124:
		attack_handlers = fat_goon_back_off_update(object, step);
		break;
	case -28:
		enemy_walk_to_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -26:
		enemy_line_up_with_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -24:
		enemy_keep_distance(object, step, &attack_handlers, p_left_caller);
		break;
	case -22:
		enemy_back_off(object, step, &attack_handlers, p_left_caller);
		break;
	case -20:
		enemy_stand_still();
		break;
	case -18:
		enemy_step_toward_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -16:
		enemy_circle_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -14:
		enemy_rush_at_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -12:
		enemy_line_up_and_pace(object, step, &attack_handlers, p_left_caller);
		break;
	case -10:
		enemy_wait_while_target_down(object, step, &attack_handlers, p_left_caller);
		break;
	case -8:
		enemy_line_up_near_target(object, step, &attack_handlers, p_left_caller);
		break;
	case -6:
		enemy_wander(object, step, &attack_handlers, p_left_caller);
		break;
	case -4:
		enemy_walk_to_target_side(object, step, &attack_handlers, p_left_caller);
		break;
	case -2:
		enemy_get_around(object, step, &attack_handlers, p_left_caller);
		break;
	}
	attack_handlers = check_floor(object, attack_handlers);
	*p_attack_handlers = attack_handlers;
}

/* An enemy's hit reaction state: runs the reaction it is in (flinching, knocked down, getting up,
   dying...) and, unless it is gone, checks the floor. */
void enemy_hit_reaction(uint16_t object, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step = 0;
	uint16_t step_handlers = 0;
	uint16_t action = 0;

	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_flinch_from_behind(object, step, &step_handlers, p_left_caller);
		break;
	case 2:
		enemy_flinch_kind_12(object, step, &step_handlers, p_left_caller);
		break;
	case 4:
		enemy_knocked_forward(object, step, &step_handlers, p_left_caller);
		break;
	case 6:
		enemy_knocked_back(object, step, &step_handlers, p_left_caller);
		break;
	case 8:
		enemy_get_up(object, step, &step_handlers, p_left_caller);
		break;
	case 10:
		enemy_die(object, step, &step_handlers, p_left_caller);
		break;
	case 12:
		enemy_drop(object, step, &step_handlers, p_left_caller);
		break;
	case 14:
		enemy_sent_flying(object, step, &step_handlers, p_left_caller);
		break;
	case 16:
		enemy_spin_backward(object, step, &step_handlers, p_left_caller);
		break;
	case 18:
		enemy_flinch_kind_11(object, step, &step_handlers, p_left_caller);
		break;
	case 20:
		enemy_defeated_forward(object, step, &step_handlers, p_left_caller);
		break;
	case 22:
		enemy_defeated_backward(object, step, &step_handlers, p_left_caller);
		break;
	case 24:
		enemy_pit(object, step, &step_handlers, p_left_caller);
		break;
	}
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else if (OBJECT(object)->flags != 0u)
		step_handlers = check_floor(object, step_handlers);
	*p_step_handlers = step_handlers;
}

/* An enemy's climbing state: runs the climb up or the hop down a step the floor check started, the way
   it met the step, and checks the floor. */
void enemy_climb(uint16_t object, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint8_t step = 0;
	uint16_t step_handlers = 0;
	uint16_t action = 0;

	step_handlers = enemy_climb_actions_ADDRESS;
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_climb_up_front(object, step, &step_handlers, p_left_caller);
		break;
	case 2:
		enemy_climb_up_back(object, step, &step_handlers, p_left_caller);
		break;
	case 4:
		enemy_climb_up_left(object, step, &step_handlers, p_left_caller);
		break;
	case 6:
		enemy_climb_up_right(object, step, &step_handlers, p_left_caller);
		break;
	case 8:
		enemy_hop_down_front(object, step, &step_handlers, p_left_caller);
		break;
	case 10:
		enemy_hop_down_back(object, step, &step_handlers, p_left_caller);
		break;
	case 12:
		enemy_hop_down_left(object, step, &step_handlers, p_left_caller);
		break;
	case 14:
		enemy_hop_down_right(object, step, &step_handlers, p_left_caller);
		break;
	case 16:
		step_handlers = enemy_climb_up_front_start(object);
		break;
	case 18:
	case 42:
		enemy_move_front_until_landed(object);
		break;
	case 20:
	case 26:
	case 32:
	case 38:
	case 44:
	case 50:
	case 56:
	case 62:
		enemy_back_to_thinking_after_wait(object);
		break;
	case 22:
		step_handlers = enemy_climb_up_back_start(object);
		break;
	case 24:
	case 48:
		enemy_move_back_until_landed(object);
		break;
	case 28:
		step_handlers = enemy_climb_up_left_start(object);
		break;
	case 30:
	case 54:
		enemy_move_left_until_landed(object);
		break;
	case 34:
		step_handlers = enemy_climb_up_right_start(object);
		break;
	case 36:
	case 60:
		enemy_move_right_until_landed(object);
		break;
	case 40:
	case 52:
	case 58:
		enemy_hop_start(object);
		break;
	case 46:
		enemy_hop_back_start(object);
		break;
	case 64:
		step_handlers = enemy_get_around_start(object, step_handlers);
		break;
	case 66:
		step_handlers = enemy_get_around_step(object, step_handlers);
		break;
	case 68:
		enemy_go_straight(object);
		break;
	case 70:
	case 80:
		enemy_walk_start_in_turn(object);
		break;
	case 72:
		step_handlers = enemy_walk_to_target_side_step(object);
		break;
	case 74:
		enemy_line_up_near_start(object);
		break;
	case 76:
		enemy_line_up_near_in_depth(object);
		break;
	case 78:
		step_handlers = enemy_line_up_near_in_x(object, step_handlers);
		break;
	case 82:
		step_handlers = enemy_walk_to_target_step(object);
		break;
	case 84:
		enemy_line_up_start(object);
		break;
	case 86:
		enemy_line_up_in_depth(object);
		break;
	case 88:
		step_handlers = enemy_line_up_in_x(object, step_handlers);
		break;
	case 90:
		enemy_keep_distance_start(object);
		break;
	case 92:
		step_handlers = enemy_keep_distance_step(object, step_handlers);
		break;
	case 94:
		enemy_keep_distance_back_off(object);
		break;
	case 96:
		step_handlers = enemy_keep_distance_close_in(object, step_handlers);
		break;
	case 98:
		enemy_wait_start(object);
		break;
	case 100:
	case 106:
		step_handlers = enemy_wait_for_target_to_stand(object);
		break;
	case 102:
		enemy_back_off_start(object);
		break;
	case 104:
		step_handlers = enemy_back_off_step(object, step_handlers);
		break;
	case 108:
		enemy_step_toward_target_start(object);
		break;
	case 110:
		enemy_step_toward_target_step(object);
		break;
	case 112:
		step_handlers = enemy_circle_target_start(object, step_handlers);
		break;
	case 114:
		step_handlers = enemy_circle_target_step(object, step_handlers);
		break;
	case 116:
		step_handlers = enemy_wander_start(object, step_handlers);
		break;
	case 118:
		step_handlers = enemy_wander_walk(object, step_handlers);
		break;
	case 120:
		step_handlers = enemy_wander_rest(object, step_handlers);
		break;
	case 122:
		enemy_rush_start(object);
		break;
	case 124:
		enemy_rush_step(object);
		break;
	case 126:
		enemy_rush_slow_down(object);
		break;
	}
	step_handlers = check_floor(object, step_handlers);
	*p_step_handlers = step_handlers;
}
