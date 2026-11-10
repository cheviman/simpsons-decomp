/**
 *    Name:        objects/object_lists.c
 *    Description: the four object lists' dispatchers and the share of attackers per player
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the enemies' list by type through enemy_banks and their handlers, after sharing out the attackers
   per player, counting the enemies again (last frame's count kept) and those of them in play (no
   entrance still to come), the count that holds off the HURRY UP. */
uint32_t run_enemies(uint16_t y, uint32_t left_caller)
{
	uint8_t object_type = 0, state = 0;
	uint16_t enemy_handlers = 0, object = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, enemy_class = 0, t5 = 0, entrance_pending = 0, t6 = 0;
	uint16_t type = 0;

	window_bank = 0x1Au;
	set_lines(window_bank);
	empty_object_handler_1a();
	share_out_attackers();
	t1 = io_read8(0x1876u);
	io_write8(0x1880u, t1);
	t2 = io_read8(0x1876u);
	io_write8(0x1876u, 0u);
	t3 = io_read8(0x1883u);
	io_write8(0x1883u, 0u);
	t4 = io_read8(0x1878u);
	io_write8(0x1878u, 0u);
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
				enemy_goon_run(object, state, &y, &left_caller);
				break;
			case 2:
				hat_goon(object, state, &y, &left_caller);
				break;
			case 4:
				kind_90_update(object, state, &y, &left_caller);
				break;
			case 6:
				goon_close_grabber(object, state, &y, &left_caller);
				break;
			case 8:
				object_does_nothing();
				break;
			case 10:
				krusty_balloon(&object, &y);
				break;
			case 12:
				hat_goon_waiting(object, state, &y, &left_caller);
				break;
			case 14:
				kind_98_update(object, state, &y, &left_caller);
				break;
			case 16:
				umbrella_goon_float_down(object, state, &y, &left_caller);
				break;
			case 18:
				clown_on_ball_update(object, state, &y, &left_caller);
				break;
			case 20:
				umbrella_goon(object, state, &y, &left_caller);
				break;
			case 22:
				y = bear_part(object, y);
				break;
			case 24:
				goon_striker(object, state, &y, &left_caller);
				break;
			case 26:
				shovel_goon(object, state, &y, &left_caller);
				break;
			case 28:
				fat_goon_update(object, state, &y, &left_caller);
				break;
			case 30:
				kind_85_update(object, state, &y, &left_caller);
				break;
			case 32:
				zombie_update(object, state, &y, &left_caller);
				break;
			case 34:
				y = kind_9a_dropper_update(object, y, state);
				break;
			case 36:
				fat_goon_thrower_update(object, state, &y, &left_caller);
				break;
			case 38:
				fat_goon_drop_update(object, state, &y, &left_caller);
				break;
			case 40:
				grabbing_zombie_update(object, state, &y, &left_caller);
				break;
			case 42:
				goon_walk_in(object, state, &y, &left_caller);
				break;
			case 44:
				goon_step_out(object, state, &y, &left_caller);
				break;
			case 46:
				goon_run_in(object, state, &y, &left_caller);
				break;
			case 48:
				hat_goon_jump_in(object, state, &y, &left_caller);
				break;
			case 50:
				y = football_player(object, enemy_handlers);
				break;
			case 52:
				kind_88_update(object, state, &y, &left_caller);
				break;
			case 54:
				shovel_goon_step_out(object, state, &y, &left_caller);
				break;
			case 56:
				goon_from_timed_list(object, state, &y, &left_caller);
				break;
			case 58:
				goon_delayed(object, state, &y, &left_caller);
				break;
			case 60:
				goon_drop(object, state, &y, &left_caller);
				break;
			case 62:
				y = wrestler_update(object, y, state);
				break;
			case 64:
				bear(enemy_handlers, &object, &y);
				break;
			case 66:
				y = kind_8a_carrier_update(object, y, state);
				break;
			case 68:
				y = kind_8c_bystander_update(object, y, state);
				break;
			case 70:
				y = wandering_zombie_update(object, y, state);
				break;
			case 72:
				y = kind_8e_thrower_update(object, y, state);
				break;
			case 74:
				goon_rush_in(object, state, &y, &left_caller);
				break;
			case 76:
				goon_from_back(object, state, &y, &left_caller);
				break;
			case 78:
				hat_goon_run_across(object, state, &y, &left_caller);
				break;
			case 80:
				fat_goon_walk_in_update(object, state, &y, &left_caller);
				break;
			case 82:
				shovel_goon_rush_in(object, state, &y, &left_caller);
				break;
			case 84:
				umbrella_goon_rush_in(object, state, &y, &left_caller);
				break;
			case 86:
				goon_descent(object, state, &y, &left_caller);
				break;
			case 88:
				fat_goon_delayed_update(object, state, &y, &left_caller);
				break;
			case 90:
				fat_goon_from_back_update(object, state, &y, &left_caller);
				break;
			case 92:
				goon_bomb_run_in(object, state, &y, &left_caller);
				break;
			case 94:
				lumberjack_update(object, state, &y, &left_caller);
				break;
			case 96:
				robot_update(object, state, &y, &left_caller);
				break;
			case 98:
				gorilla_update(object, state, &y, &left_caller);
				break;
			case 100:
				ninja_update(object, state, &y, &left_caller);
				break;
			case 102:
				ninja_fighter_update(object, state, &y, &left_caller);
				break;
			case 104:
				goon_striker_rush_in(object, state, &y, &left_caller);
				break;
			case 106:
				fat_goon_descent_update(object, state, &y, &left_caller);
				break;
			case 108:
				fat_goon_entrance_update(object, state, &y, &left_caller);
				break;
			case 110:
				y = stage_7_boss_update(object, y);
				break;
			case 112:
				fat_goon_entrance_to_floor_update(object, state, &y, &left_caller);
				break;
			case 114:
				goon_walk_up(object, state, &y, &left_caller);
				break;
			case 116:
				fat_goon_waiting_update(object, state, &y, &left_caller);
				break;
			case 118:
				bomb_goon(object, state, &y, &left_caller);
				break;
			case 120:
				hat_goon_step_out(object, state, &y, &left_caller);
				break;
			case 122:
				ninja_thrower_update(object, state, &y, &left_caller);
				break;
			case 124:
				y = stage_3_boss(object);
				break;
			case 126:
				goon_from_side(object, state, &y, &left_caller);
				break;
			case -54:
				y = unused_kind_b7_update(object, y, state);
				break;
			case -52:
				fat_goon_jumper_update(object, state, &y, &left_caller);
				break;
			case -50:
				hat_goon_brawler(object, state, &y, &left_caller);
				break;
			case -48:
				scripted_object(object, &y, &enemy_handlers);
				break;
			case -46:
				police_car_update(object, state, &y, &enemy_handlers);
				break;
			case -44:
				burns_held_part_run(object);
				break;
			case -42:
				goon_keeps_away(object, state, &y, &left_caller);
				break;
			case -40:
				y = burns_robot_run(object, y);
				break;
			case -38:
				cemetery_umbrella_goon(object, state, &y, &left_caller);
				break;
			case -36:
				goon_striker_jump_in(object, state, &y, &left_caller);
				break;
			case -34:
				fat_goon_jump_in_update(object, state, &y, &left_caller);
				break;
			case -32:
				fat_goon_from_below_update(object, state, &y, &left_caller);
				break;
			case -30:
				goon_from_below(object, state, &y, &left_caller);
				break;
			case -28:
				y = cloud_devil_update(object, y, state);
				break;
			case -26:
				goon_jump_in(object, state, &y, &left_caller);
				break;
			case -24:
				goon_striker_from_side(object, state, &y, &left_caller);
				break;
			case -22:
				knight_update(object, state, &y, &left_caller);
				break;
			case -20:
				y = stage_8_boss_run(object, enemy_handlers);
				break;
			case -18:
				y = chain_holder_update(object, y, state);
				break;
			case -16:
				y = dreamland_boss_update(object, y, state);
				break;
			case -14:
				y = object_f9(object, y);
				break;
			case -12:
				fat_goon_puncher_update(object, state, &y, &left_caller);
				break;
			case -10:
				fat_goon_grabber_update(object, state, &y, &left_caller);
				break;
			case -8:
				y = kind_b8_flyer_update(object, y, state);
				break;
			case -6:
				donut_update(object, state, &y, &left_caller);
				break;
			case -4:
				dreamland_boss_chain_head_update(object, state, &y, &enemy_handlers);
				break;
			case -2:
				dreamland_boss_chain_update(object, state, &y, &enemy_handlers);
				break;
			}
			enemy_class = OBJECT(object)->enemy_class;
			if ((int8_t)enemy_class >= 0)
			{
				t5 = io_read8(0x1876u);
				io_write8(0x1876u, t5 + 1u);
			}
			entrance_pending = OBJECT(object)->entrance_pending;
			if (entrance_pending == 0u)
			{
				t6 = io_read8(0x1883u);
				io_write8(0x1883u, t6 + 1u);
			}
		}
		object += 0x60u;
	} while (object < OBJECT_ADDRESS(22));
	return left_caller;
}

/* Runs list 1's objects by type through object_list_1_banks and their handlers, counting them. */
void run_list_1_objects(uint16_t *p_y, uint16_t *p_list_1_handlers, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t list_1_handlers = (uint16_t)*p_list_1_handlers;
	uint32_t carry = 0;
	uint8_t object_type = 0, state = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t type = 0;

	t1 = io_read8(0x1879u);
	io_write8(0x1879u, 0u);
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
				obstacle_update(object, carry, &y, &list_1_handlers, p_left_caller);
				break;
			case 2:
				throwable_update(object, carry, &y, &list_1_handlers);
				break;
			case 4:
				unused_homer_object_update(object, state, &y, &list_1_handlers);
				break;
			case 6:
				running_animal_update(object, state, &y, &list_1_handlers);
				break;
			case 8:
				kind_90_effect(object, state, &y, &list_1_handlers);
				break;
			case 10:
				platform_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 12:
				shaking_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 14:
				floor_blocker_update(object, state, &y, &list_1_handlers);
				break;
			case 16:
				kind_87_update(object, state, &y, &list_1_handlers);
				break;
			case 18:
				kind_95_update(object, state, &y, &list_1_handlers);
				break;
			case 20:
				empty_object_type_0a_handler();
				break;
			case 22:
				door_kind_10_run(object, state, &y, &list_1_handlers);
				break;
			case 24:
				door_kind_0f_run(object, state, &y, &list_1_handlers);
				break;
			case 26:
				goon_balloon(object, state, &y, &list_1_handlers);
				break;
			case 28:
				y = bear_part(object, y);
				break;
			case 30:
				kind_88_ride_update(object, state, &y, &list_1_handlers);
				break;
			case 34:
				solid_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 36:
				car_doors_run(object, state, &y, &list_1_handlers);
				break;
			case 38:
				empty_object_type_13_handler();
				break;
			case 40:
				empty_object_type_14_handler();
				break;
			case 42:
				random_pose_figure_update(object, state, &y, &list_1_handlers);
				break;
			case 44:
				rising_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 46:
				tossed_obstacle_update(object, state, &y, &list_1_handlers);
				break;
			case 48:
				rising_zombie_update(object, state, &y, &list_1_handlers);
				break;
			case 50:
				empty_object_type_19();
				break;
			case 52:
				police_car_door_update(object, state, &y, &list_1_handlers);
				break;
			case 54:
				charging_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 56:
				kind_a0_update(object, state, &y, &list_1_handlers);
				break;
			case 58:
				walking_kind_87_update(object, state, &y, &list_1_handlers);
				break;
			case 60:
				story_marker();
				break;
			case 62:
				kind_10_dropper_update(object, state, &y, &list_1_handlers);
				break;
			case 64:
				kind_8e_watcher_update(object, state, &y, &list_1_handlers);
				break;
			case 66:
				kind_10_riser_update(object, state, &y, &list_1_handlers, p_left_caller);
				break;
			case 68:
				kind_9e_update(object, state, &y, &list_1_handlers);
				break;
			case 70:
				shaken_bit_update(object, state, &y, &list_1_handlers);
				break;
			case 72:
				empty_object_type_24_handler();
				break;
			case 74:
				looping_scenery_update(object, state, &y, &list_1_handlers);
				break;
			case 76:
				kind_87_device_update(object, state, &y, &list_1_handlers);
				break;
			case 78:
				food_update(object, state, &y, &list_1_handlers);
				break;
			case 80:
				carried_obstacle_update(object, state, &y, &list_1_handlers);
				break;
			case 82:
				bystander_update(object, state, &y, &list_1_handlers);
				break;
			case 84:
				kind_93_run(object, state, &y, &list_1_handlers);
				break;
			case 86:
				gorge_rock_update(object, state, &y, &list_1_handlers);
				break;
			case 88:
				boulder_update(object, state, &y, &list_1_handlers);
				break;
			case 90:
				bouncing_throwable_update(object, state, &y, &list_1_handlers);
				break;
			case 92:
				bird_item_update(object, state, &y, &list_1_handlers);
				break;
			case 94:
				shaken_object_update(object, state, &y, &list_1_handlers);
				break;
			case 96:
				kind_a5_update(object, state, &y, &list_1_handlers);
				break;
			case 98:
				krusty_balloon_shot(&object, &y, &list_1_handlers);
				break;
			case 100:
				kind_b3_update(object, state, &y, &list_1_handlers);
				break;
			case 102:
				robot_piece_update(object, state, &y, &list_1_handlers);
				break;
			case 104:
				descent_balloon_update(object, state, &y, &list_1_handlers);
				break;
			case 106:
				bear_boulder(object, &y, &list_1_handlers);
				break;
			case 108:
				bear_change_effect(object);
				break;
			case 110:
				stage_7_boss_helper_update(object, &y, &list_1_handlers);
				break;
			case 112:
				door_kind_12_run(object, state, &y, &list_1_handlers);
				break;
			case 114:
				goon_lift_update(state, &object, &y, &list_1_handlers, p_left_caller);
				break;
			case 116:
				goon_lift_part_update(object, state, &y, &list_1_handlers);
				break;
			case 118:
				unused_goon_update(object, state, &y, &list_1_handlers, p_left_caller);
				break;
			case 120:
				kind_b2_update(object, state, &y, &list_1_handlers);
				break;
			case 122:
				prop_update(object, state, &y, &list_1_handlers);
				break;
			case 124:
				kind_b2_leaper_update(object, state, &y, &list_1_handlers);
				break;
			case 126:
				krustyland_bear_update(object, state, &y, &list_1_handlers);
				break;
			case -70:
				kind_9e_spawner_update(object, state, &y, &list_1_handlers);
				break;
			case -68:
				donut_shot_update(object, state, &y, &list_1_handlers);
				break;
			case -66:
				cemetery_obstacle_update(object, state, &y, &list_1_handlers, p_left_caller);
				break;
			case -64:
				heavy_obstacle_update(object, carry, &y, &list_1_handlers, p_left_caller);
				break;
			case -62:
				timed_throwable_update(object, state, &y, &list_1_handlers, p_left_caller);
				break;
			case -60:
				mr_burns_run(object, state, &y, &list_1_handlers);
				break;
			case -58:
				dreamland_boss_shadow_update(object, state, &y, &list_1_handlers);
				break;
			case -56:
				burns_tossed_part_run(object, state, &y, &list_1_handlers);
				break;
			case -54:
				burns_debris_run(object, state, &y, &list_1_handlers);
				break;
			case -52:
				burns_debris_run_e6(object, state, &y, &list_1_handlers);
				break;
			case -50:
				rescued_maggie_run(object, state, &y, &list_1_handlers);
				break;
			case -48:
				looping_scenery_leaving_update(object, state, &y, &list_1_handlers);
				break;
			case -46:
				scripted_object(object, &y, &list_1_handlers);
				break;
			case -44:
				boss_ball_trail_update(object, state, &y, &list_1_handlers);
				break;
			case -42:
				kind_cb_update(object, state, &y, &list_1_handlers);
				break;
			case -40:
				police_car_update(object, state, &y, &list_1_handlers);
				break;
			case -38:
				list_1_handlers = boss_door(object);
				break;
			case -36:
				kind_aa_pair_update(object, state, &y, &list_1_handlers);
				break;
			case -34:
				kind_aa_update(object, state, &y, &list_1_handlers);
				break;
			case -32:
				cemetery_piece_update(object, state, &y, &list_1_handlers);
				break;
			case -30:
				stage_8_boss_bomb_run(object, &y, &list_1_handlers);
				break;
			case -28:
				dreamland_obstacle_update(object, state, &y, &list_1_handlers);
				break;
			case -26:
				kind_b8_shot_update(object, state, &y, &list_1_handlers);
				break;
			case -24:
				object_does_nothing();
				break;
			case -22:
				robot_scrap_update(object, state, &y, &list_1_handlers);
				break;
			case -20:
				robot_spark_update(object, state, &y, &list_1_handlers);
				break;
			case -18:
				kind_ac_update(object, state, &y, &list_1_handlers);
				break;
			case -16:
				kind_ab_update(object, state, &y, &list_1_handlers);
				break;
			case -14:
				item_carrier_update(object, state, &y, &list_1_handlers);
				break;
			case -12:
				kind_a9_update(object, state, &y, &list_1_handlers);
				break;
			case -10:
				bouncing_prop_update(object, state, &y, &list_1_handlers);
				break;
			case -8:
				item_update(object, state, &y, &list_1_handlers);
				break;
			case -6:
				krustyland_door_update(object, state, &y, &list_1_handlers);
				break;
			case -4:
				dreamland_boss_chain_head_update(object, state, &y, &list_1_handlers);
				break;
			case -2:
				dreamland_boss_chain_update(object, state, &y, &list_1_handlers);
				break;
			}
			t2 = io_read8(0x1879u);
			io_write8(0x1879u, t2 + 1u);
		}
		object += 0x60u;
	} while (object < OBJECT_ADDRESS(32));
	*p_y = y;
	*p_list_1_handlers = list_1_handlers;
}

/* Runs the child objects' list by type through child_object_banks and their handlers, counting them. */
uint16_t run_child_objects(uint16_t child_handlers)
{
	uint8_t object_type = 0, state = 0;
	uint16_t ignored16 = 0, object = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t type = 0;

	t1 = io_read8(0x187Au);
	io_write8(0x187Au, 0u);
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
				bear_part(object, ignored16);
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
				krusty_balloon_shot(&object, &ignored16, &child_handlers);
				break;
			case 34:
				child_handlers = spark_shot_update(object, state);
				break;
			case 36:
				child_handlers = dropped_food_update(object, state);
				break;
			case 38:
				kind_90_effect(object, state, &ignored16, &child_handlers);
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
				stage_8_boss_bomb_run(object, &ignored16, &child_handlers);
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
				scripted_object(object, &ignored16, &child_handlers);
				break;
			case -4:
				dreamland_boss_chain_head_update(object, state, &ignored16, &child_handlers);
				break;
			case -2:
				dreamland_boss_chain_update(object, state, &ignored16, &child_handlers);
				break;
			}
			t2 = io_read8(0x187Au);
			io_write8(0x187Au, t2 + 1u);
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
	io_write8(0x1874u, player_count);
}

/* Finds the player in play the fewest enemies go after (its attackers' count) and keeps it for
   enemy_think. */
void find_least_attacked_player(void)
{
	uint8_t attackers = 0, players_left = 0;
	uint16_t player = 0;
	uint8_t stack = 0;
	uint8_t attackers_2 = 0, t1 = 0;

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
				io_write16(0x1870u, player);
			}
		}
		player += 0xC0u;
		t1 = players_left;
		players_left = t1 - 1u;
	} while (t1 != 1u);
}

/* Works out how many enemies may go after one player: by the enemies in play shared out between the
   players in the game (attackers_per_player), all of them with one player, 4 from 16 enemies. */
void share_out_attackers(void)
{
	uint8_t enemies = 0, other_players = 0, players = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = io_read8(0x1876u);
	if (t1 >= 0x10u)
	{
		io_write8(0x1877u, 4u);
		return;
	}
	t2 = io_read8(0x1876u);
	enemies = t2;
	t3 = io_read8(0x1874u);
	players = t3;
	if (t3 == 0u)
		return;
	t4 = players;
	other_players = t4 - 1u;
	if (t4 != 1u)
	{
		io_write8(0x1877u, TABLE8(attackers_per_player, (uint16_t)((int8_t)(((((other_players - 1u) << 1) << 1) << 1) << 1) + (int8_t)enemies)));
		return;
	}
	io_write8(0x1877u, enemies);
}

/* The handler of an object type that does nothing. */
void object_does_nothing(void)
{
}
