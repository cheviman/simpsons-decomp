/**
 *    Name:        objects/object_lists.c
 *    Description: the four object lists' dispatchers and the share of attackers per player
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the enemies' list by type through enemy_banks and their handlers, after sharing out the attackers
   per player, counting the enemies again (last frame's count kept) and those of them in play (no
   entrance still to come), the count that holds off the HURRY UP. */
uint32_t run_enemies(uint32_t left_caller)
{
	uint8_t object_type = 0, state = 0;
	uint16_t enemy_handlers = 0, object = 0;
	uint8_t stack = 0;
	uint8_t enemies_last_frame = 0, old_enemy_count = 0, old_entered_count = 0, old_walk_delays = 0, enemy_class = 0, enemies_so_far = 0, entrance_pending = 0, entered_so_far = 0;
	uint16_t type = 0;

	window_bank = 0x1Au;
	set_lines(window_bank);
	empty_object_handler_1a();
	share_out_attackers();
	enemies_last_frame = io_read8(enemies_present);
	io_write8(enemies_present_last_frame, enemies_last_frame);
	old_enemy_count = io_read8(enemies_present);
	io_write8(enemies_present, 0u);
	old_entered_count = io_read8(enemies_entered);
	io_write8(enemies_entered, 0u);
	old_walk_delays = io_read8(walk_delay_turn);
	io_write8(walk_delay_turn, 0u);
	object = OBJECT_ADDRESS(14);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			type = (((uint32_t)(uint8_t)OBJECT(object)->type << 8u) | OBJECT(object)->state);
			object_type = (uint8_t)(type >> 8);
			stack = type;
			window_bank = enemy_banks[(int8_t)object_type];
			set_lines(window_bank);
			enemy_handlers = enemy_type_handlers_ADDRESS;
			object_type = (uint32_t)object_type << 1;
			state = stack;
			switch ((int8_t)object_type)
			{
			case 0:
				left_caller = enemy_goon_run(object, state);
				break;
			case 2:
				left_caller = hat_goon(object, state);
				break;
			case 4:
				left_caller = kind_90_update(object, state);
				break;
			case 6:
				left_caller = goon_close_grabber(object, state);
				break;
			case 8:
				object_does_nothing();
				break;
			case 10:
				object = krusty_balloon(object);
				break;
			case 12:
				left_caller = hat_goon_waiting(object, state);
				break;
			case 14:
				left_caller = kind_98_update(object, state);
				break;
			case 16:
				left_caller = umbrella_goon_float_down(object, state);
				break;
			case 18:
				left_caller = clown_on_ball_update(object, state);
				break;
			case 20:
				left_caller = umbrella_goon(object, state);
				break;
			case 22:
				bear_part(object);
				break;
			case 24:
				left_caller = goon_striker(object, state);
				break;
			case 26:
				left_caller = shovel_goon(object, state);
				break;
			case 28:
				left_caller = fat_goon_update(object, state);
				break;
			case 30:
				left_caller = kind_85_update(object, state);
				break;
			case 32:
				left_caller = zombie_update(object, state);
				break;
			case 34:
				kind_9a_dropper_update(object, state);
				break;
			case 36:
				left_caller = fat_goon_thrower_update(object, state);
				break;
			case 38:
				left_caller = fat_goon_drop_update(object, state);
				break;
			case 40:
				left_caller = grabbing_zombie_update(object, state);
				break;
			case 42:
				left_caller = goon_walk_in(object, state);
				break;
			case 44:
				left_caller = goon_step_out(object, state);
				break;
			case 46:
				left_caller = goon_run_in(object, state);
				break;
			case 48:
				left_caller = hat_goon_jump_in(object, state);
				break;
			case 50:
				football_player(object, enemy_handlers);
				break;
			case 52:
				left_caller = kind_88_update(object, state, left_caller);
				break;
			case 54:
				left_caller = shovel_goon_step_out(object, state);
				break;
			case 56:
				left_caller = goon_from_timed_list(object, state);
				break;
			case 58:
				left_caller = goon_delayed(object, state);
				break;
			case 60:
				left_caller = goon_drop(object, state);
				break;
			case 62:
				wrestler_update(object, state);
				break;
			case 64:
				object = bear(object, enemy_handlers);
				break;
			case 66:
				kind_8a_carrier_update(object, state);
				break;
			case 68:
				kind_8c_bystander_update(object, state);
				break;
			case 70:
				wandering_zombie_update(object, state);
				break;
			case 72:
				kind_8e_thrower_update(object, state);
				break;
			case 74:
				left_caller = goon_rush_in(object, state);
				break;
			case 76:
				left_caller = goon_from_back(object, state);
				break;
			case 78:
				left_caller = hat_goon_run_across(object, state);
				break;
			case 80:
				left_caller = fat_goon_walk_in_update(object, state);
				break;
			case 82:
				left_caller = shovel_goon_rush_in(object, state);
				break;
			case 84:
				left_caller = umbrella_goon_rush_in(object, state);
				break;
			case 86:
				left_caller = goon_descent(object, state);
				break;
			case 88:
				left_caller = fat_goon_delayed_update(object, state);
				break;
			case 90:
				left_caller = fat_goon_from_back_update(object, state);
				break;
			case 92:
				left_caller = goon_bomb_run_in(object, state);
				break;
			case 94:
				left_caller = lumberjack_update(object, state);
				break;
			case 96:
				left_caller = robot_update(object, state);
				break;
			case 98:
				left_caller = gorilla_update(object, state);
				break;
			case 100:
				left_caller = ninja_update(object, state);
				break;
			case 102:
				left_caller = ninja_fighter_update(object, state);
				break;
			case 104:
				left_caller = goon_striker_rush_in(object, state);
				break;
			case 106:
				left_caller = fat_goon_descent_update(object, state);
				break;
			case 108:
				left_caller = fat_goon_entrance_update(object, state);
				break;
			case 110:
				stage_7_boss_update(object);
				break;
			case 112:
				left_caller = fat_goon_entrance_to_floor_update(object, state);
				break;
			case 114:
				left_caller = goon_walk_up(object, state);
				break;
			case 116:
				left_caller = fat_goon_waiting_update(object, state);
				break;
			case 118:
				left_caller = bomb_goon(object, state);
				break;
			case 120:
				left_caller = hat_goon_step_out(object, state);
				break;
			case 122:
				left_caller = ninja_thrower_update(object, state);
				break;
			case 124:
				stage_3_boss(object);
				break;
			case 126:
				left_caller = goon_from_side(object, state);
				break;
			case -54:
				unused_kind_b7_update(object, state);
				break;
			case -52:
				left_caller = fat_goon_jumper_update(object, state);
				break;
			case -50:
				left_caller = hat_goon_brawler(object, state);
				break;
			case -48:
				scripted_object(object, enemy_handlers);
				break;
			case -46:
				police_car_update(object, state);
				break;
			case -44:
				burns_held_part_run(object);
				break;
			case -42:
				left_caller = goon_keeps_away(object, state);
				break;
			case -40:
				burns_robot_run(object);
				break;
			case -38:
				left_caller = cemetery_umbrella_goon(object, state);
				break;
			case -36:
				left_caller = goon_striker_jump_in(object, state);
				break;
			case -34:
				left_caller = fat_goon_jump_in_update(object, state);
				break;
			case -32:
				left_caller = fat_goon_from_below_update(object, state);
				break;
			case -30:
				left_caller = goon_from_below(object, state);
				break;
			case -28:
				cloud_devil_update(object, state);
				break;
			case -26:
				left_caller = goon_jump_in(object, state);
				break;
			case -24:
				left_caller = goon_striker_from_side(object, state);
				break;
			case -22:
				left_caller = knight_update(object, state, left_caller);
				break;
			case -20:
				stage_8_boss_run(object, enemy_handlers);
				break;
			case -18:
				chain_holder_update(object, state);
				break;
			case -16:
				dreamland_boss_update(object, state);
				break;
			case -14:
				object_f9(object);
				break;
			case -12:
				left_caller = fat_goon_puncher_update(object, state);
				break;
			case -10:
				left_caller = fat_goon_grabber_update(object, state);
				break;
			case -8:
				kind_b8_flyer_update(object, state);
				break;
			case -6:
				left_caller = donut_update(object, state);
				break;
			case -4:
				dreamland_boss_chain_head_update(object, state);
				break;
			case -2:
				dreamland_boss_chain_update(object, state);
				break;
			}
			enemy_class = OBJECT(object)->enemy_class;
			if ((int8_t)enemy_class >= 0)
			{
				enemies_so_far = io_read8(enemies_present);
				io_write8(enemies_present, enemies_so_far + 1u);
			}
			entrance_pending = OBJECT(object)->entrance_pending;
			if (entrance_pending == 0u)
			{
				entered_so_far = io_read8(enemies_entered);
				io_write8(enemies_entered, entered_so_far + 1u);
			}
		}
		object += 0x60u;
	} while (object < OBJECT_ADDRESS(22));
	return left_caller;
}

/* Runs list 1's objects by type through object_list_1_banks and their handlers, counting them. */
void run_list_1_objects(uint16_t *p_list_1_handlers, uint32_t *p_left_caller)
{
	uint16_t list_1_handlers = (uint16_t)*p_list_1_handlers;
	uint32_t carry = 0;
	uint8_t object_type = 0, state = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t old_list_1_count = 0, list_1_count = 0;
	uint16_t type = 0;

	old_list_1_count = io_read8(list_1_objects_in_play);
	io_write8(list_1_objects_in_play, 0u);
	object = OBJECT_ADDRESS(22);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			type = (((uint32_t)(uint8_t)OBJECT(object)->type << 8u) | OBJECT(object)->state);
			object_type = (uint8_t)(type >> 8);
			stack = type;
			window_bank = object_list_1_banks[(int8_t)object_type];
			set_lines(window_bank);
			list_1_handlers = object_list_1_type_handlers_ADDRESS;
			carry = (int8_t)object_type < 0;
			object_type = (uint32_t)object_type << 1;
			state = stack;
			switch ((int8_t)object_type)
			{
			case 0:
				obstacle_update(object, carry, &list_1_handlers, p_left_caller);
				break;
			case 2:
				list_1_handlers = throwable_update(object, list_1_handlers, carry);
				break;
			case 4:
				list_1_handlers = unused_homer_object_update(object, state);
				break;
			case 6:
				list_1_handlers = running_animal_update(object, state);
				break;
			case 8:
				list_1_handlers = kind_90_effect(object, state);
				break;
			case 10:
				list_1_handlers = platform_scenery_update(object, state);
				break;
			case 12:
				list_1_handlers = shaking_scenery_update(object, state);
				break;
			case 14:
				list_1_handlers = floor_blocker_update(object, state);
				break;
			case 16:
				list_1_handlers = kind_87_update(object, state);
				break;
			case 18:
				list_1_handlers = kind_95_update(object, state);
				break;
			case 20:
				empty_object_type_0a_handler();
				break;
			case 22:
				list_1_handlers = door_kind_10_run(object, state);
				break;
			case 24:
				list_1_handlers = door_kind_0f_run(object, state);
				break;
			case 26:
				list_1_handlers = goon_balloon(object, state);
				break;
			case 28:
				bear_part(object);
				break;
			case 30:
				list_1_handlers = kind_88_ride_update(object, state);
				break;
			case 34:
				list_1_handlers = solid_scenery_update(object, state);
				break;
			case 36:
				list_1_handlers = car_doors_run(object, state);
				break;
			case 38:
				empty_object_type_13_handler();
				break;
			case 40:
				empty_object_type_14_handler();
				break;
			case 42:
				list_1_handlers = random_pose_figure_update(object, state);
				break;
			case 44:
				list_1_handlers = rising_scenery_update(object, state);
				break;
			case 46:
				list_1_handlers = tossed_obstacle_update(object, state);
				break;
			case 48:
				list_1_handlers = rising_zombie_update(object, state);
				break;
			case 50:
				empty_object_type_19();
				break;
			case 52:
				list_1_handlers = police_car_door_update(object, state);
				break;
			case 54:
				list_1_handlers = charging_scenery_update(object, state);
				break;
			case 56:
				list_1_handlers = kind_a0_update(object, state);
				break;
			case 58:
				list_1_handlers = walking_kind_87_update(object, state);
				break;
			case 60:
				story_marker();
				break;
			case 62:
				list_1_handlers = kind_10_dropper_update(object, state);
				break;
			case 64:
				list_1_handlers = kind_8e_watcher_update(object, state);
				break;
			case 66:
				kind_10_riser_update(object, state, &list_1_handlers, p_left_caller);
				break;
			case 68:
				list_1_handlers = kind_9e_update(object, state);
				break;
			case 70:
				list_1_handlers = shaken_bit_update(object, state);
				break;
			case 72:
				empty_object_type_24_handler();
				break;
			case 74:
				list_1_handlers = looping_scenery_update(object, state);
				break;
			case 76:
				list_1_handlers = kind_87_device_update(object, state);
				break;
			case 78:
				list_1_handlers = food_update(object, state);
				break;
			case 80:
				list_1_handlers = carried_obstacle_update(object, state);
				break;
			case 82:
				list_1_handlers = bystander_update(object, state);
				break;
			case 84:
				list_1_handlers = kind_93_run(object, state);
				break;
			case 86:
				list_1_handlers = gorge_rock_update(object, state);
				break;
			case 88:
				list_1_handlers = boulder_update(object, state);
				break;
			case 90:
				list_1_handlers = bouncing_throwable_update(object, state);
				break;
			case 92:
				list_1_handlers = bird_item_update(object, state);
				break;
			case 94:
				list_1_handlers = shaken_object_update(object, state);
				break;
			case 96:
				list_1_handlers = kind_a5_update(object, state);
				break;
			case 98:
				krusty_balloon_shot(&object, &list_1_handlers);
				break;
			case 100:
				list_1_handlers = kind_b3_update(object, state);
				break;
			case 102:
				list_1_handlers = robot_piece_update(object, state);
				break;
			case 104:
				list_1_handlers = descent_balloon_update(object, state);
				break;
			case 106:
				list_1_handlers = bear_boulder(object, list_1_handlers);
				break;
			case 108:
				bear_change_effect(object);
				break;
			case 110:
				list_1_handlers = stage_7_boss_helper_update(object);
				break;
			case 112:
				list_1_handlers = door_kind_12_run(object, state);
				break;
			case 114:
				goon_lift_update(state, &object, &list_1_handlers, p_left_caller);
				break;
			case 116:
				list_1_handlers = goon_lift_part_update(object, state);
				break;
			case 118:
				unused_goon_update(object, state, &list_1_handlers, p_left_caller);
				break;
			case 120:
				list_1_handlers = kind_b2_update(object, state);
				break;
			case 122:
				list_1_handlers = prop_update(object, state);
				break;
			case 124:
				list_1_handlers = kind_b2_leaper_update(object, state);
				break;
			case 126:
				list_1_handlers = krustyland_bear_update(object, state);
				break;
			case -70:
				list_1_handlers = kind_9e_spawner_update(object, state);
				break;
			case -68:
				list_1_handlers = donut_shot_update(object, state);
				break;
			case -66:
				cemetery_obstacle_update(object, state, &list_1_handlers, p_left_caller);
				break;
			case -64:
				heavy_obstacle_update(object, carry, &list_1_handlers, p_left_caller);
				break;
			case -62:
				timed_throwable_update(object, state, &list_1_handlers, p_left_caller);
				break;
			case -60:
				list_1_handlers = mr_burns_run(object, state);
				break;
			case -58:
				list_1_handlers = dreamland_boss_shadow_update(object, state);
				break;
			case -56:
				list_1_handlers = burns_tossed_part_run(object, state);
				break;
			case -54:
				list_1_handlers = burns_debris_run(object, state);
				break;
			case -52:
				list_1_handlers = burns_debris_run_e6(object, state);
				break;
			case -50:
				list_1_handlers = rescued_maggie_run(object, state);
				break;
			case -48:
				list_1_handlers = looping_scenery_leaving_update(object, state);
				break;
			case -46:
				list_1_handlers = scripted_object(object, list_1_handlers);
				break;
			case -44:
				list_1_handlers = boss_ball_trail_update(object, state);
				break;
			case -42:
				list_1_handlers = kind_cb_update(object, state);
				break;
			case -40:
				list_1_handlers = police_car_update(object, state);
				break;
			case -38:
				list_1_handlers = boss_door(object);
				break;
			case -36:
				list_1_handlers = kind_aa_pair_update(object, state);
				break;
			case -34:
				list_1_handlers = kind_aa_update(object, state);
				break;
			case -32:
				list_1_handlers = cemetery_piece_update(object, state);
				break;
			case -30:
				list_1_handlers = stage_8_boss_bomb_run(object, list_1_handlers);
				break;
			case -28:
				list_1_handlers = dreamland_obstacle_update(object, state);
				break;
			case -26:
				list_1_handlers = kind_b8_shot_update(object, state);
				break;
			case -24:
				object_does_nothing();
				break;
			case -22:
				list_1_handlers = robot_scrap_update(object, state);
				break;
			case -20:
				list_1_handlers = robot_spark_update(object, state);
				break;
			case -18:
				list_1_handlers = kind_ac_update(object, state);
				break;
			case -16:
				list_1_handlers = kind_ab_update(object, state);
				break;
			case -14:
				list_1_handlers = item_carrier_update(object, state);
				break;
			case -12:
				list_1_handlers = kind_a9_update(object, state);
				break;
			case -10:
				list_1_handlers = bouncing_prop_update(object, state);
				break;
			case -8:
				list_1_handlers = item_update(object, state);
				break;
			case -6:
				list_1_handlers = krustyland_door_update(object, state);
				break;
			case -4:
				list_1_handlers = dreamland_boss_chain_head_update(object, state);
				break;
			case -2:
				list_1_handlers = dreamland_boss_chain_update(object, state);
				break;
			}
			list_1_count = io_read8(list_1_objects_in_play);
			io_write8(list_1_objects_in_play, list_1_count + 1u);
		}
		object += 0x60u;
	} while (object < OBJECT_ADDRESS(32));
	*p_list_1_handlers = list_1_handlers;
}

/* Runs the child objects' list by type through child_object_banks and their handlers, counting them. */
uint16_t run_child_objects(uint16_t child_handlers)
{
	uint8_t object_type = 0, state = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t old_child_count = 0, child_count = 0;
	uint16_t type = 0;

	old_child_count = io_read8(child_objects_in_play);
	io_write8(child_objects_in_play, 0u);
	object = OBJECT_ADDRESS(8);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			type = (((uint32_t)(uint8_t)OBJECT(object)->type << 8u) | OBJECT(object)->state);
			object_type = (uint8_t)(type >> 8);
			stack = type;
			window_bank = child_object_banks[(int8_t)object_type];
			set_lines(window_bank);
			child_handlers = child_object_type_handlers_ADDRESS;
			object_type = (uint32_t)object_type << 1;
			state = stack;
			switch ((int8_t)object_type)
			{
			case 0:
			case 68:
			case 70:
			case 72:
				object_does_nothing();
				break;
			case 2:
				bear_part(object);
				break;
			case 4:
				child_handlers = goon_hat_update(object, state);
				break;
			case 6:
				empty_child_type_03_handler();
				break;
			case 8:
				empty_child_type_04_handler();
				break;
			case 10:
				football_thrown(object);
				break;
			case 12:
				child_handlers = football_line_piece(object, child_handlers);
				break;
			case 14:
				story_extra_actor(&object, &child_handlers);
				break;
			case 16:
				child_handlers = hurry_up(object, child_handlers);
				break;
			case 18:
				child_handlers = clown_ball_update(object, state);
				break;
			case 20:
				child_handlers = kind_90_missile_update(object, state);
				break;
			case 22:
				child_handlers = kind_88_piece_update(object, state);
				break;
			case 24:
				story_noted_actor(&object, &child_handlers);
				break;
			case 26:
				child_handlers = scenery_debris_update(object, state);
				break;
			case 28:
				child_handlers = food_jump_out_update(object, state);
				break;
			case 30:
				story_follower(&object, &child_handlers);
				break;
			case 32:
				krusty_balloon_shot(&object, &child_handlers);
				break;
			case 34:
				child_handlers = spark_shot_update(object, state);
				break;
			case 36:
				child_handlers = dropped_food_update(object, state);
				break;
			case 38:
				child_handlers = kind_90_effect(object, state);
				break;
			case 40:
				story_extra_actor_2(&object, &child_handlers);
				break;
			case 42:
				story_extra_actor_3(&object, &child_handlers);
				break;
			case 44:
				child_handlers = goon_bomb(object, state);
				break;
			case 46:
				child_handlers = robot_part_update(object, state);
				break;
			case 48:
				child_handlers = buzzing_chaser_update(object, state);
				break;
			case 50:
				child_handlers = ninja_star_update(object, state);
				break;
			case 52:
				child_handlers = carried_item_update(object, state);
				break;
			case 56:
				child_handlers = boss_speech_balloon_run(object, child_handlers);
				break;
			case 58:
				child_handlers = stage_8_boss_bomb_run(object, child_handlers);
				break;
			case 60:
				child_handlers = kind_88_ride_arm_update(object, state);
				break;
			case 62:
				child_handlers = boss_door_stage_8(object);
				break;
			case 64:
				child_handlers = boss_ball_update(object, state);
				break;
			case 66:
				child_handlers = burns_breakout_run(object, state);
				break;
			case 74:
				child_handlers = burns_shot_run(object, state);
				break;
			case 76:
				child_handlers = burns_bomb_run(object);
				break;
			case 78:
				child_handlers = kind_d1_fling_update(object, state);
				break;
			case 80:
				child_handlers = lightning_bolt_update(object, state);
				break;
			case 82:
				child_handlers = speech_balloon_update(object);
				break;
			case 84:
				child_handlers = scripted_object(object, child_handlers);
				break;
			case -4:
				child_handlers = dreamland_boss_chain_head_update(object, state);
				break;
			case -2:
				child_handlers = dreamland_boss_chain_update(object, state);
				break;
			}
			child_count = io_read8(child_objects_in_play);
			io_write8(child_objects_in_play, child_count + 1u);
		}
		object += 0x60u;
	} while (object < OBJECT_ADDRESS(14));
	return child_handlers;
}

/* Runs the stage's event object by type through stage_event_banks and its handlers. */
void run_stage_event(void)
{
	uint8_t object_type = 0, state = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint16_t type = 0;

	object = OBJECT_ADDRESS(32);
	do
	{
		if (OBJECT(object)->flags > 1u)
		{
			type = (((uint32_t)(uint8_t)OBJECT(object)->type << 8u) | OBJECT(object)->state);
			object_type = (uint8_t)(type >> 8);
			stack = type;
			window_bank = stage_event_banks[(int8_t)object_type];
			set_lines(window_bank);
			object_type = (uint32_t)object_type << 1;
			state = stack;
			switch ((int8_t)object_type)
			{
			case 0:
				scroll_lock_update(object, state);
				break;
			case 2:
				enemy_waves_update(object, state);
				break;
			case 4:
				empty_stage_event_02();
				break;
			case 6:
				object = stage_event_actor(object);
				break;
			case 8:
				cleared_wave_update(object, state);
				break;
			}
		}
		object += 0x60u;
	} while (object < 0x56A0u);
}

/* Unused: notes the number of players in a scene variable. */
void unused_note_player_count(void)
{
	io_write8(stage_player_count, player_count);
}

/* Finds the player in play the fewest enemies go after (its attackers' count) and keeps it for
   enemy_think. */
void find_least_attacked_player(void)
{
	uint8_t attackers = 0, players_left = 0;
	uint16_t player = 0;
	uint8_t stack = 0;
	uint8_t attackers_2 = 0, players_to_check = 0;

	players_left = 4u;
	stack = 0x7Fu;
	player = OBJECT_ADDRESS(0);
	do
	{
		if (OBJECT(player)->flags != 0u)
		{
			attackers_2 = OBJECT(player)->player.attackers;
			attackers = attackers_2;
			if (attackers < stack)
			{
				stack = attackers;
				io_write16(least_attacked_player, player);
			}
		}
		player += 0xC0u;
		players_to_check = players_left;
		players_left = players_to_check - 1u;
	} while (players_to_check != 1u);
}

/* Works out how many enemies may go after one player: by the enemies in play shared out between the
   players in the game (attackers_per_player), all of them with one player, 4 from 16 enemies. */
void share_out_attackers(void)
{
	uint8_t enemies = 0, other_players = 0, players = 0;
	uint8_t enemy_count = 0, enemies_now = 0, players_now = 0, players_counted = 0;

	enemy_count = io_read8(enemies_present);
	if (enemy_count >= 0x10u)
	{
		io_write8(attackers_per_player_limit, 4u);
		return;
	}
	enemies_now = io_read8(enemies_present);
	enemies = enemies_now;
	players_now = io_read8(stage_player_count);
	players = players_now;
	if (players_now == 0u)
		return;
	players_counted = players;
	other_players = players_counted - 1u;
	if (players_counted != 1u)
	{
		io_write8(attackers_per_player_limit, TABLE8(attackers_per_player, (uint16_t)((int8_t)(((((other_players - 1u) << 1) << 1) << 1) << 1) + (int8_t)enemies)));
		return;
	}
	io_write8(attackers_per_player_limit, enemies);
}

/* The handler of an object type that does nothing. */
void object_does_nothing(void)
{
}
