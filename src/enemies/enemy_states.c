/**
 *    Name:        enemies/enemy_states.c
 *    Description: an enemy's states: thinking, attacking, the hit reactions, climbing
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
void enemy_think(uint16_t object, uint16_t *p_y, uint16_t *p_target_player, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	bool L_07D53B = false, L_07D59B = false;
	uint32_t carry = 0;
	uint8_t a = 0, choice = 0, step = 0;
	uint16_t d = 0, target = 0, target_player = 0, u = 0;
	uint8_t stack = 0;
	uint8_t retarget_time = 0, attackers = 0, t1 = 0, t2 = 0, t3 = 0, t5 = 0, parameter = 0, parameter_2 = 0, parameter_3 = 0, t6 = 0, t7 = 0, target_direction = 0, t8 = 0, t9 = 0, side = 0, side_2 = 0, t10 = 0, parameter_4 = 0, timer = 0, timer_2 = 0, t11 = 0, t16 = 0, t17 = 0, t18 = 0, parameter_5 = 0, t19 = 0, t20 = 0, t21 = 0;
	uint16_t target_2 = 0, t4 = 0, target_3 = 0, z = 0, floor_z = 0, target_dx = 0, target_dy = 0, target_dx_2 = 0, target_dy_2 = 0, action = 0, t12 = 0, floor_z_2 = 0, t13 = 0, t14 = 0, t15 = 0, z_2 = 0, floor_z_3 = 0, behaviour = 0, behaviour_2 = 0;

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
		t1 = attackers - 1u;
		OBJECT(target_player)->player.attackers = t1;
		if ((int8_t)t1 < 0)
			OBJECT(target_player)->player.attackers = 0u;
		target_player = enemy_target_nearest_player(object);
		t2 = mem_read8(target_player + 0x45u);
		t3 = io_read8(0x1877u);
		if (t3 <= t2)
		{
			find_least_attacked_player();
			t4 = io_read16(0x1870u);
			target_player = t4;
			OBJECT(object)->target = target_player;
		}
		t5 = mem_read8(target_player + 0x45u);
		mem_write8(target_player + 0x45u, t5 + 1u);
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
		*p_target_player = target_player;
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
				t6 = mem_read8(target_player + 0x46u);
				if (t6 < 0xC0u)
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
		t7 = mem_read8(target_player + 0x46u);
		if (t7 < 0xC0u)
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
								t8 = mem_read8(target_player + 0x46u);
								a = t8;
								if ((a & 0x40u) != 0u)
								{
									t9 = mem_read8(target_player + 0x46u);
									a = t9;
									if ((int8_t)t9 < 0)
										continue;
									mem_write8(target_player + 0x46u, a | 0x80u);
									side = OBJECT(object)->enemy.side;
									OBJECT(object)->enemy.side = side & 0x7Fu;
									break;
								}
								mem_write8(target_player + 0x46u, a | 0x40u);
								side_2 = OBJECT(object)->enemy.side;
								OBJECT(object)->enemy.side = side_2 | 0x80u;
								break;
							}
						}
						else
						{
							t9 = mem_read8(target_player + 0x46u);
							a = t9;
							L_07D53B = (int8_t)t9 < 0;
							if (!L_07D53B)
							{
								mem_write8(target_player + 0x46u, a | 0x80u);
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
	t10 = mem_read8(target_player + 2u);
	L_07D59B = (int8_t)t10 >= 0;
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
				u = enemy_think_actions_ADDRESS;
				a = (uint32_t)(action >> 8) << 1;
				step = (uint8_t)action;
				switch ((int8_t)a)
				{
				case 0:
					enemy_walk_to_target(object, step, &y, &u, p_left_caller);
					break;
				case 2:
					enemy_line_up_with_target(object, step, &y, &u, p_left_caller);
					break;
				case 4:
					enemy_keep_distance(object, step, &y, &u, p_left_caller);
					break;
				case 6:
					enemy_back_off(object, step, &y, &u, p_left_caller);
					break;
				case 8:
					enemy_stand_still();
					break;
				case 10:
					enemy_step_toward_target(object, step, &y, &u, p_left_caller);
					break;
				case 12:
					enemy_circle_target(object, step, &y, &u, p_left_caller);
					break;
				case 14:
					enemy_rush_at_target(object, step, &y, &u, p_left_caller);
					break;
				case 16:
					enemy_line_up_and_pace(object, step, &y, &u, p_left_caller);
					break;
				case 18:
					enemy_wait_while_target_down(object, step, &y, &u, p_left_caller);
					break;
				case 20:
					enemy_line_up_near_target(object, step, &y, &u, p_left_caller);
					break;
				case 22:
					enemy_wander(object, step, &y, &u, p_left_caller);
					break;
				case 24:
					enemy_walk_to_target_side(object, step, &y, &u, p_left_caller);
					break;
				case 26:
					enemy_get_around(object, step, &y, &u, p_left_caller);
					break;
				}
				u = check_floor(object, u);
				enemy_start_climbing(object);
				*p_y = y;
				*p_target_player = u;
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
				t11 = mem_read8(target_player + 2u);
				if ((int8_t)t11 >= 0)
				{
					t12 = mem_read16(target_player + 0x5Cu);
					floor_z_2 = OBJECT(object)->floor_z;
					t13 = t12 - floor_z_2;
					t14 = t13;
					t15 = t14 >> 15 ? 0u - t14 : t14;
					if (t15 <= 0x20u)
					{
						z_2 = OBJECT(object)->z;
						floor_z_3 = OBJECT(object)->floor_z;
						if (z_2 == floor_z_3)
						{
							behaviour = OBJECT(object)->behaviour;
							target_player = behaviour + 0x28u;
							enemy_find_attack_range(object, &target_player, &d, &carry);
							a = (uint8_t)(d >> 8);
							if (carry)
							{
								stack = a;
								d = enemy_random((uint8_t)d);
								a = (uint8_t)(d >> 8);
								if (a < stack)
								{
									d = enemy_random((uint8_t)d);
									a = (uint8_t)(d >> 8);
									choice = 4u;
									target_player += 7u;
									do
									{
										t16 = mem_read8(target_player + (int8_t)choice);
										t17 = a;
										a = t17 - t16;
										if (t17 < t16)
										{
											target_player -= 4u;
											OBJECT(object)->action = mem_read8(target_player + (int8_t)choice);
											OBJECT(object)->state = 3u;
											OBJECT(object)->action_step = 0u;
											OBJECT(object)->x_speed = 0;
											OBJECT(object)->y_speed = 0;
											OBJECT(object)->z_speed = 0;
											*p_target_player = target_player;
											return;
										}
										t18 = choice;
										choice = t18 - 1u;
									} while (t18 != 1u);
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
				u = enemy_think_actions_ADDRESS;
				a = (uint32_t)(action >> 8) << 1;
				step = (uint8_t)action;
				switch ((int8_t)a)
				{
				case 0:
					enemy_walk_to_target(object, step, &y, &u, p_left_caller);
					break;
				case 2:
					enemy_line_up_with_target(object, step, &y, &u, p_left_caller);
					break;
				case 4:
					enemy_keep_distance(object, step, &y, &u, p_left_caller);
					break;
				case 6:
					enemy_back_off(object, step, &y, &u, p_left_caller);
					break;
				case 8:
					enemy_stand_still();
					break;
				case 10:
					enemy_step_toward_target(object, step, &y, &u, p_left_caller);
					break;
				case 12:
					enemy_circle_target(object, step, &y, &u, p_left_caller);
					break;
				case 14:
					enemy_rush_at_target(object, step, &y, &u, p_left_caller);
					break;
				case 16:
					enemy_line_up_and_pace(object, step, &y, &u, p_left_caller);
					break;
				case 18:
					enemy_wait_while_target_down(object, step, &y, &u, p_left_caller);
					break;
				case 20:
					enemy_line_up_near_target(object, step, &y, &u, p_left_caller);
					break;
				case 22:
					enemy_wander(object, step, &y, &u, p_left_caller);
					break;
				case 24:
					enemy_walk_to_target_side(object, step, &y, &u, p_left_caller);
					break;
				case 26:
					enemy_get_around(object, step, &y, &u, p_left_caller);
					break;
				}
				u = check_floor(object, u);
				enemy_start_climbing(object);
				*p_y = y;
				*p_target_player = u;
				return;
			}
		}
	}
	behaviour_2 = OBJECT(object)->behaviour;
	parameter_5 = OBJECT(object)->parameter;
	u = behaviour_2 + (int8_t)((((uint32_t)parameter_5 << 1) << 1) << 1);
	d = enemy_random((uint8_t)d);
	a = (uint8_t)(d >> 8);
	choice = 4u;
	u += 3u;
	do
	{
		t19 = mem_read8(u + (int8_t)choice);
		t20 = a;
		a = t20 - t19;
		if (t20 < t19)
		{
			choice--;
			break;
		}
		t21 = choice;
		choice = t21 - 1u;
	} while (t21 != 1u);
	OBJECT(object)->action = mem_read8(u - 3u + (int8_t)choice);
	OBJECT(object)->action_step = 0u;
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	u = enemy_think_actions_ADDRESS;
	a = (uint32_t)(action >> 8) << 1;
	step = (uint8_t)action;
	switch ((int8_t)a)
	{
	case 0:
		enemy_walk_to_target(object, step, &y, &u, p_left_caller);
		break;
	case 2:
		enemy_line_up_with_target(object, step, &y, &u, p_left_caller);
		break;
	case 4:
		enemy_keep_distance(object, step, &y, &u, p_left_caller);
		break;
	case 6:
		enemy_back_off(object, step, &y, &u, p_left_caller);
		break;
	case 8:
		enemy_stand_still();
		break;
	case 10:
		enemy_step_toward_target(object, step, &y, &u, p_left_caller);
		break;
	case 12:
		enemy_circle_target(object, step, &y, &u, p_left_caller);
		break;
	case 14:
		enemy_rush_at_target(object, step, &y, &u, p_left_caller);
		break;
	case 16:
		enemy_line_up_and_pace(object, step, &y, &u, p_left_caller);
		break;
	case 18:
		enemy_wait_while_target_down(object, step, &y, &u, p_left_caller);
		break;
	case 20:
		enemy_line_up_near_target(object, step, &y, &u, p_left_caller);
		break;
	case 22:
		enemy_wander(object, step, &y, &u, p_left_caller);
		break;
	case 24:
		enemy_walk_to_target_side(object, step, &y, &u, p_left_caller);
		break;
	case 26:
		enemy_get_around(object, step, &y, &u, p_left_caller);
		break;
	}
	u = check_floor(object, u);
	enemy_start_climbing(object);
	*p_y = y;
	*p_target_player = u;
}

/* An enemy's attacking state: lands it if it falls, looks at its target, runs the attack in its bank
   (action_banks and the handlers after them) and checks the floor. */
void enemy_attack(uint16_t object, uint16_t *p_y, uint16_t *p_attack_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t attack = 0, step = 0;
	uint16_t attack_handlers = 0, target = 0;
	uint8_t stack = 0;
	uint16_t z = 0, floor_z = 0, target_2 = 0, action = 0;

	z = OBJECT(object)->z;
	floor_z = OBJECT(object)->floor_z;
	if (z != floor_z)
		carry = land_if_falling(object);
	target_2 = OBJECT(object)->target;
	target = target_2;
	enemy_look_at_target(object, target);
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	attack = (uint8_t)(action >> 8);
	stack = action;
	window_bank = action_banks[(int8_t)attack];
	set_lines(window_bank);
	attack_handlers = enemy_action_handlers_ADDRESS;
	attack = (uint32_t)attack << 1;
	step = stack;
	switch ((int8_t)attack)
	{
	case 0:
		goon_wait_then_strike(object, step, &y, &attack_handlers);
		break;
	case 2:
		goon_wait_then_strike_2(object, step, &y, &attack_handlers);
		break;
	case 4:
		goon_quick_strike(object, step, &y, &attack_handlers);
		break;
	case 6:
		goon_quick_strike_2(object, step, &y, &attack_handlers);
		break;
	case 8:
		goon_jump_attack(object, step, &y, &attack_handlers);
		break;
	case 10:
		goon_jump_up_or_grab(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case 12:
		hat_goon_throw_hat(object, step, &y, &attack_handlers);
		break;
	case 14:
		goon_strike_and_run(object, step, &y, &attack_handlers);
		break;
	case 16:
		kind_90_throw_update(object, step, &y, &attack_handlers);
		break;
	case 18:
		fat_goon_walk_up_strike_update(object, step, &y, &attack_handlers);
		break;
	case 20:
		fat_goon_body_slam_update(object, step, &y, &attack_handlers);
		break;
	case 22:
		fat_goon_strike_update(object, step, &y, &attack_handlers);
		break;
	case 24:
		fat_goon_reach_strike_update(object, step, &y, &attack_handlers);
		break;
	case 26:
		fat_goon_idle_action_update(object, step, &y, &attack_handlers);
		break;
	case 28:
		fat_goon_heavy_strike_update(object, step, &y, &attack_handlers);
		break;
	case 30:
		goon_grab(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case 32:
		kind_98_strike_update(object, step, &y, &attack_handlers);
		break;
	case 34:
		umbrella_goon_strike(object, step, &y, &attack_handlers);
		break;
	case 36:
		umbrella_goon_charge(object, step, &y, &attack_handlers);
		break;
	case 38:
		umbrella_goon_long_strike(object, step, &y, &attack_handlers);
		break;
	case 40:
		shovel_goon_strike(object, step, &y, &attack_handlers);
		break;
	case 42:
		shovel_goon_far_strike(object, step, &y, &attack_handlers);
		break;
	case 44:
		umbrella_goon_quick_strike(object, step, &y, &attack_handlers);
		break;
	case 46:
		goon_dash_strike(object, step, &y, &attack_handlers);
		break;
	case 48:
		goon_keep_distance(object, step, &y, &attack_handlers);
		break;
	case 50:
		empty_action_19();
		break;
	case 52:
		zombie_swipe_action(object, step, &y, &attack_handlers);
		break;
	case 54:
		bomb_goon_throw(object, step, &y, &attack_handlers);
		break;
	case 56:
		clown_on_ball_strike_update(object, step, &y, &attack_handlers);
		break;
	case 58:
		zombie_burrow_action(object, step, &y, &attack_handlers);
		break;
	case 60:
		clown_on_ball_jump_update(object, step, &y, &attack_handlers);
		break;
	case 62:
		clown_on_ball_charge_update(object, step, &y, &attack_handlers);
		break;
	case 64:
		clown_on_ball_pause_update(object, step, &y, &attack_handlers);
		break;
	case 66:
		zombie_leap_action(object, step, &y, &attack_handlers);
		break;
	case 68:
		lumberjack_axe_action(object, step, &y, &attack_handlers);
		break;
	case 70:
		robot_shock_92_action(object, step, &y, &attack_handlers);
		break;
	case 72:
		robot_shock_91_action(object, step, &y, &attack_handlers);
		break;
	case 74:
		robot_punch_action(object, step, &y, &attack_handlers);
		break;
	case 76:
		gorilla_punch_action(object, step, &y, &attack_handlers);
		break;
	case 78:
		goon_approach_strike(object, step, &y, &attack_handlers);
		break;
	case 80:
		robot_combo_action(object, step, &y, &attack_handlers);
		break;
	case 82:
		fat_goon_bump_update(object, step, &y, &attack_handlers);
		break;
	case 84:
		robot_launch_part_action(object, step, &y, &attack_handlers);
		break;
	case 86:
		ninja_slash_action(object, step, &y, &attack_handlers);
		break;
	case 88:
		gorilla_leap_action(object, step, &y, &attack_handlers);
		break;
	case 90:
		ninja_throw_action(object, step, &y, &attack_handlers);
		break;
	case 92:
		ninja_jump_attack_action(object, step, &y, &attack_handlers);
		break;
	case 94:
		ninja_rush_action(object, step, &y, &attack_handlers);
		break;
	case 96:
		ninja_hop_strike_action(object, step, &y, &attack_handlers);
		break;
	case 98:
		zombie_grab_action(object, step, &y, &attack_handlers);
		break;
	case 100:
		ninja_vanish_action(object, step, &y, &attack_handlers);
		break;
	case 102:
		shovel_goon_close_strike(object, step, &y, &attack_handlers);
		break;
	case 104:
		attack_handlers = clown_on_ball_hop_update(object, step);
		break;
	case 106:
		attack_handlers = gorilla_back_off_action(object, step);
		break;
	case 108:
		kind_98_step_back_update(object, step, &y, &attack_handlers);
		break;
	case 110:
		ninja_crouch_strike_action(object, step, &y, &attack_handlers);
		break;
	case 112:
		fat_goon_grab_update(object, step, &y, &attack_handlers);
		break;
	case 114:
		robot_advance_shock_action(object, step, &y, &attack_handlers);
		break;
	case 116:
		donut_roll_action(object, step, &y, &attack_handlers);
		break;
	case 118:
		donut_throw_action(object, step, &y, &attack_handlers);
		break;
	case 120:
		knight_strike_action(object, step, &y, &attack_handlers);
		break;
	case 122:
		goon_back_off(object, step, &y, &attack_handlers);
		break;
	case 124:
		fat_goon_back_off_update(object, step, &y, &attack_handlers);
		break;
	case -28:
		enemy_walk_to_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -26:
		enemy_line_up_with_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -24:
		enemy_keep_distance(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -22:
		enemy_back_off(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -20:
		enemy_stand_still();
		break;
	case -18:
		enemy_step_toward_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -16:
		enemy_circle_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -14:
		enemy_rush_at_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -12:
		enemy_line_up_and_pace(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -10:
		enemy_wait_while_target_down(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -8:
		enemy_line_up_near_target(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -6:
		enemy_wander(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -4:
		enemy_walk_to_target_side(object, step, &y, &attack_handlers, p_left_caller);
		break;
	case -2:
		enemy_get_around(object, step, &y, &attack_handlers, p_left_caller);
		break;
	}
	attack_handlers = check_floor(object, attack_handlers);
	*p_y = y;
	*p_attack_handlers = attack_handlers;
}

/* An enemy's hit reaction state: runs the reaction it is in (flinching, knocked down, getting up,
   dying...) and, unless it is gone, checks the floor. */
void enemy_hit_reaction(uint16_t object, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step = 0;
	uint16_t u = 0;
	uint16_t action = 0;

	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_flinch_from_behind(object, step, &y, &u, p_left_caller);
		break;
	case 2:
		enemy_flinch_kind_12(object, step, &y, &u, p_left_caller);
		break;
	case 4:
		enemy_knocked_forward(object, step, &y, &u, p_left_caller);
		break;
	case 6:
		enemy_knocked_back(object, step, &y, &u, p_left_caller);
		break;
	case 8:
		enemy_get_up(object, step, &y, &u, p_left_caller);
		break;
	case 10:
		enemy_die(object, step, &y, &u, p_left_caller);
		break;
	case 12:
		enemy_drop(object, step, &y, &u, p_left_caller);
		break;
	case 14:
		enemy_sent_flying(object, step, &y, &u, p_left_caller);
		break;
	case 16:
		enemy_spin_backward(object, step, &y, &u, p_left_caller);
		break;
	case 18:
		enemy_flinch_kind_11(object, step, &y, &u, p_left_caller);
		break;
	case 20:
		enemy_defeated_forward(object, step, &y, &u, p_left_caller);
		break;
	case 22:
		enemy_defeated_backward(object, step, &y, &u, p_left_caller);
		break;
	case 24:
		enemy_pit(object, step, &y, &u, p_left_caller);
		break;
	}
	if (*p_left_caller != 0u)
		*p_left_caller = 0u;
	else if (OBJECT(object)->flags != 0u)
		u = check_floor(object, u);
	*p_y = y;
	*p_u = u;
}

/* An enemy's climbing state: runs the climb up or the hop down a step the floor check started, the way
   it met the step, and checks the floor. */
void enemy_climb(uint16_t object, uint16_t *p_y, uint16_t *p_step_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t step = 0;
	uint16_t step_handlers = 0;
	uint16_t action = 0;

	step_handlers = enemy_climb_actions_ADDRESS;
	action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
	step = (uint8_t)action;
	switch ((int8_t)(uint8_t)((uint32_t)(action >> 8) << 1))
	{
	case 0:
		enemy_climb_up_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 2:
		enemy_climb_up_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 4:
		enemy_climb_up_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 6:
		enemy_climb_up_right(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 8:
		enemy_hop_down_front(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 10:
		enemy_hop_down_back(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 12:
		enemy_hop_down_left(object, step, &y, &step_handlers, p_left_caller);
		break;
	case 14:
		enemy_hop_down_right(object, step, &y, &step_handlers, p_left_caller);
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
	*p_y = y;
	*p_step_handlers = step_handlers;
}
