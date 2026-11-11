/**
 *    Name:        table.c
 *    Description: the code the board runs by itself (the reset's, the interrupts' handlers) and the tables the game loads by name
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* what the code carries in its registers (game.h) */
uint16_t leftover_y = 0u;

/* the same, for the runtime to put back what an interrupt's handler found there when it returns, as the
   CPU does */
uint16_t *const game_context[] = { &leftover_y };
const size_t game_context_count = 1;

/* the code at the reset vector */
void game_entry(void)
{
	boot();
}

/* the IRQ's handler (the K052109's, at VBLANK) */
void game_irq(void)
{
	irq_handler();
}

/* the FIRQ's handler (the sprite DMA's) */
void game_firq(void)
{
	firq_handler();
}

const void *bonus_intro_sounds_data;
const void *bonus_1_player_records_data;
const void *bonus_placements_data;
const void *bonus_2_side_object_x_offsets_data;
const void *bonus_2_shake_x_offsets_data;
const void *bonus_2_squash_zooms_x_data;
const void *bonus_2_squash_zooms_y_data;
const void *bonus_2_level_object_x_moves_data;
const void *bonus_2_player_x_data;
const void *bonus_results_hop_speeds_data;
const void *wrestler_beaten_health_by_players_data;
const void *wrestler_gauge_piece_health_by_players_data;
const void *wrestler_animations_data;
const void *wrestler_hit_boxes_data;
const void *wrestler_jump_chances_by_rank_data;
const void *wrestler_quick_attack_chances_by_players_data;
const void *wrestler_guard_chances_by_players_data;
const void *wrestler_speeds_by_rank_data;
const void *name_entry_player_records_data;
const void *name_entry_cursor_zooms_data;
const void *name_entry_pictures_data;
const void *sprite_font_code_high_data;
const void *sprite_font_codes_data;
const void *ending_family_waits_data;
const void *ending_placements_data;
const void *staff_roll_titles_data;
const void *staff_roll_names_data;
const void *stage_7_boss_beaten_health_by_players_data;
const void *stage_7_boss_gauge_piece_health_by_players_data;
const void *stage_7_boss_animations_data;
const void *stage_7_boss_hit_boxes_data;
const void *stage_7_boss_quick_attack_chances_by_players_data;
const void *stage_7_boss_jump_away_chances_by_players_data;
const void *stage_7_boss_speeds_by_rank_data;
const void *stage_7_boss_helper_attack_times_by_rank_data;
const void *stage_7_boss_helper_speeds_data;
const void *game_texts_address_data;
const void *object_12_placements_data;
const void *absent_player_blanks_data;
const void *wave_cosines_data;
const void *game_texts_data;
const void *stage_slots_data;
const void *screen_shake_steps_data;
const void *screen_shake_lengths_data;
const void *stage_3_part_2_layer_offsets_data;
const void *krusty_balloon_beaten_health_by_players_data;
const void *krusty_balloon_gauge_piece_health_by_players_data;
const void *krusty_balloon_animations_data;
const void *krusty_balloon_hit_boxes_data;
const void *krusty_balloon_hit_limits_by_players_data;
const void *krusty_balloon_quick_attack_chances_by_players_data;
const void *krusty_balloon_fly_off_chances_by_rank_data;
const void *krusty_balloon_speeds_by_rank_data;
const void *krusty_balloon_throw_z_speeds_data;
const void *stage_title_placements_data;
const void *goon_descent_starts_data;
const void *goon_from_back_xs_data;
const void *waiting_hat_goon_starts_data;
const void *goon_walk_in_starts_data;
const void *delayed_goon_starts_data;
const void *goon_entrances_data;
const void *goon_side_entries_data;
const void *goon_run_in_starts_data;
const void *hat_goon_jump_in_starts_data;
const void *goon_drop_xs_data;
const void *umbrella_goon_xs_data;
const void *unused_goon_waits_by_rank_data;
const void *goon_strike_waits_by_players_data;
const void *goon_jump_attack_chances_by_rank_data;
const void *goon_hold_animations_data;
const void *shovel_goon_close_strike_waits_by_players_data;
const void *shovel_goon_far_strike_waits_by_players_data;
const void *goon_jump_in_xs_data;
const void *goon_from_below_xs_data;
const void *cemetery_umbrella_goon_xs_data;
const void *fat_goon_from_back_xs_data;
const void *fat_goon_strike_waits_by_players_data;
const void *fat_goon_hold_animations_data;
const void *fat_goon_jump_in_xs_data;
const void *fat_goon_from_below_xs_data;
const void *enemy_waves_end_enemies_data;
const void *object_15_spawn_lists_data;
const void *enemy_waves_next_wave_enemies_data;
const void *cemetery_obstacle_xs_data;
const void *cemetery_obstacle_food_data;
const void *kind_10_floor_edge_flags_data;
const void *police_car_door_lists_data;
const void *player_objects_data;
const void *obstacle_heights_data;
const void *object_16_flags_data;
const void *rising_scenery_camera_xs_data;
const void *item_setups_data;
const void *food_hit_kinds_data;
const void *kind_a5_partners_data;
const void *kind_a5_food_drops_data;
const void *item_carrier_setups_data;
const void *item_carrier_items_data;
const void *carried_item_kinds_data;
const void *bystanders_data;
const void *kind_b3_damage_animations_data;
const void *krustyland_child_limits_by_players_data;
const void *clown_on_ball_pause_waits_by_rank_data;
const void *orbit_cosines_data;
const void *kind_b2_idle_animations_data;
const void *kind_97_timed_moves_data;
const void *object_18_behaviours_data;
const void *kind_9a_drop_starts_data;
const void *kind_91_appearances_data;
const void *kind_97_entrances_data;
const void *kind_97_hold_animations_data;
const void *lumberjack_pause_loops_by_players_data;
const void *gorilla_entrances_data;
const void *gorilla_leap_speeds_data;
const void *knight_entrances_data;
const void *knight_entrance_styles_data;
const void *kind_c7_sweep_ways_data;
const void *kind_c7_headings_data;
const void *kind_c7_sweep_rates_data;
const void *kind_c7_start_x_data;
const void *kind_c7_hurt_shakes_data;
const void *kind_c7_bob_up_data;
const void *kind_c7_bob_down_data;
const void *kind_c7_shot_waits_data;
const void *kind_8e_poses_data;
const void *kind_8c_animations_data;
const void *kind_a1_entrance_steps_data;
const void *kind_a1_attack_delays_by_players_data;
const void *robot_pieces_data;
const void *hit_spark_times_data;
const void *robot_sparks_by_frame_9d_data;
const void *robot_sparks_by_frame_92_data;
const void *robot_sparks_by_frame_91_data;
const void *robot_actions_after_hit_data;
const void *robot_status_after_hit_data;
const void *robot_part_zooms_data;
const void *kind_12_parts_data;
const void *kind_b7_entrances_data;
const void *kind_b8_sweep_ways_data;
const void *kind_b8_headings_data;
const void *kind_b8_sweep_rates_data;
const void *kind_b8_descent_slowdowns_data;
const void *kind_b8_descent_y_speeds_data;
const void *kind_b8_volley_shots_data;
const void *kind_b8_single_shots_data;
const void *kind_b8_hurt_shakes_data;
const void *kind_b8_bob_up_data;
const void *kind_b8_bob_down_data;
const void *kind_b8_shot_waits_data;
const void *kind_b8_velocities_data;
const void *kind_b8_shot_animations_data;
const void *kind_b8_shot_speeds_data;
const void *unused_debug_tile_places_data;
const void *object_1a_next_states_data;
const void *object_1a_states_after_data;
const void *object_1a_level_rows_data;
const void *object_1a_chase_leg_times_data;
const void *object_1a_bounce_animations_data;
const void *object_1a_pose_times_data;
const void *object_1a_pose_animations_data;
const void *object_1a_leap_speeds_data;
const void *object_1a_leap_heights_data;
const void *object_1a_repeat_animations_data;
const void *object_1a_approach_times_data;
const void *object_1a_released_objects_data;
const void *object_1a_launches_data;
const void *object_1a_chain_links_data;
const void *object_1a_path_choices_data;
const void *object_1a_path_starts_data;
const void *object_1a_path_times_data;
const void *object_1a_sines_data;
const void *door_spawn_lists_data;
const void *door_spawns_data;
const void *kind_12_door_openings_data;
const void *kind_10_door_openings_data;
const void *kind_0f_door_openings_data;
const void *team_move_attack_states_data;
const void *object_1c_move_steps_data;
const void *object_1c_moves_data;
const void *team_move_animation_offsets_data;
const void *pickup_vitality_data;
const void *player_walk_velocities_data;
const void *player_attack_boxes_data;
const void *team_move_box_widths_data;
const void *zoom_steps_address_data;
const void *stage_8_boss_state_starts_data;
const void *stage_8_boss_stop_throwing_chances_by_players_data;
const void *stage_8_boss_bombs_by_players_data;
const void *stage_8_boss_run_speeds_by_players_data;
const void *stage_8_boss_hit_limits_address_data;
const void *stage_8_boss_invulnerable_times_by_players_data;
const void *stage_8_boss_run_skip_attack_chances_by_players_data;
const void *stage_8_boss_retreat_speeds_by_players_data;
const void *stage_8_boss_walk_speeds_by_players_data;
const void *stage_8_boss_jump_speeds_by_players_data;
const void *stage_8_boss_dash_speeds_by_players_data;
const void *stage_8_boss_jump_bomb_player_limits_data;
const void *burns_robot_volleys_by_players_data;
const void *burns_robot_shot_y_speeds_data;
const void *burns_robot_healths_data;
const void *burns_robot_beaten_healths_data;
const void *burns_robot_second_attack_chances_by_players_data;
const void *burns_robot_shot_times_data;
const void *burns_robot_held_part_times_data;
const void *burns_robot_quick_attack_chances_data;
const void *burns_robot_animations_data;
const void *burns_robot_hit_boxes_data;
const void *burns_robot_walk_speeds_data;
const void *object_1d_parts_data;
const void *scripted_object_scripts_data;
const void *football_player_attack_delays_by_players_data;
const void *football_player_speed_ranges_by_rank_data;
const void *bear_attack_delays_by_players_data;
const void *bear_charge_speeds_by_rank_data;
const void *stage_3_boss_slow_attack_chances_by_players_data;
const void *stage_3_boss_follow_up_chances_by_players_data;
const void *story_scripts_data;
const void *player_overhead_heights_data;
const void *player_throw_heights_data;
const void *player_balloon_animations_data;
const void *pair_balloon_players_data;
const void *player_state_classes_data;
const void *profile_moves_data;
const void *profile_texts_data;
const void *gauge_player_records_data;
const void *gauge_pictures_data;
const void *continue_digit_pictures_data;
const void *rank_by_players_data;
const void *rank_by_scene_data;
const void *rank_step_times_data;
const void *palette_effects_data;
const void *test_menu_cursor_steps_data;
const void *test_mode_hex_digit_tiles_data;
const void *test_mode_texts_data;
const void *test_mode_words_data;
const void *coin_setting_coin_digits_data;
const void *coin_setting_credit_digits_data;
const void *eeprom_address_signals_data;
const void *eeprom_data_signals_data;
const void *eeprom_wait_signal_data;
const void *graphics_rom_sums_data;
const void *graphics_rom_result_places_data;
const void *sprite_rom_read_banks_data;
const void *test_player_records_data;
const void *palette_request_handlers_data;
const void *coinages_data;
const void *rom_13c_sum_data;
const void *rom_15c_sum_data;
const void *rom_16c_sum_data;
const void *rom_17c_sum_data;
const void *hex_digit_tiles_data;
const void *score_additions_data;
const void *player_presses_data;
const void *hurt_effect_rows_data;
const void *step_sprite_priorities_data;
const void *shadow_sprites_data;
const void *demos_data;
const void *scene_routines_data;
const void *player_records_data;
const void *step_scenes_data;
const void *layer_maps_data;
const void *layers_data;
const void *block_scenes_a_data;
const void *block_scenes_b_data;
const void *layer_modes_data;
const void *tile_pictures_data;
const void *spawn_list_places_data;
const void *enemy_speeds_by_rank_data;
const void *object_list_sizes_data;
const void *object_lists_data;
const void *enemy_limits_by_difficulty_data;
const void *extra_enemies_by_scene_data;
const void *cemetery_enemy_limits_by_players_data;
const void *attackers_per_player_data;
const void *sines_data;
const void *sines_20_data;
const void *arctangents_data;
const void *climb_speeds_data;
const void *enemy_banks_data;
const void *object_list_1_banks_data;
const void *child_object_banks_data;
const void *stage_event_banks_data;
const void *action_banks_data;
const void *unused_object_banks_data;
const void *block_tile_flags_data;
const void *reset_vector_data;

/* the tables the game loads from its assets: their names, places, pointers and the bytes of their
   elements (the loader puts each element in the host's byte order) */
const game_table game_tables[] =
{
	{ "bonus_intro_sounds", 0x021BC4u, &bonus_intro_sounds_data, 2 },
	{ "bonus_1_player_records", 0x021BC8u, &bonus_1_player_records_data, 2 },
	{ "bonus_placements", 0x021C00u, &bonus_placements_data, 2 },
	{ "bonus_2_side_object_x_offsets", 0x021D28u, &bonus_2_side_object_x_offsets_data, 1 },
	{ "bonus_2_shake_x_offsets", 0x021D44u, &bonus_2_shake_x_offsets_data, 1 },
	{ "bonus_2_squash_zooms_x", 0x021D4Du, &bonus_2_squash_zooms_x_data, 1 },
	{ "bonus_2_squash_zooms_y", 0x021D55u, &bonus_2_squash_zooms_y_data, 1 },
	{ "bonus_2_level_object_x_moves", 0x021D5Du, &bonus_2_level_object_x_moves_data, 1 },
	{ "bonus_2_player_x", 0x021D7Du, &bonus_2_player_x_data, 2 },
	{ "bonus_results_hop_speeds", 0x021D9Cu, &bonus_results_hop_speeds_data, 1 },
	{ "wrestler_beaten_health_by_players", 0x021E71u, &wrestler_beaten_health_by_players_data, 1 },
	{ "wrestler_gauge_piece_health_by_players", 0x021E75u, &wrestler_gauge_piece_health_by_players_data, 1 },
	{ "wrestler_animations", 0x021E79u, &wrestler_animations_data, 2 },
	{ "wrestler_hit_boxes", 0x021E99u, &wrestler_hit_boxes_data, 8 },
	{ "wrestler_jump_chances_by_rank", 0x021EB9u, &wrestler_jump_chances_by_rank_data, 1 },
	{ "wrestler_quick_attack_chances_by_players", 0x021EC9u, &wrestler_quick_attack_chances_by_players_data, 1 },
	{ "wrestler_guard_chances_by_players", 0x021ECDu, &wrestler_guard_chances_by_players_data, 1 },
	{ "wrestler_speeds_by_rank", 0x021ED1u, &wrestler_speeds_by_rank_data, 1 },
	{ "name_entry_player_records", 0x023532u, &name_entry_player_records_data, 2 },
	{ "name_entry_cursor_zooms", 0x02359Eu, &name_entry_cursor_zooms_data, 1 },
	{ "name_entry_pictures", 0x0235AEu, &name_entry_pictures_data, 2 },
	{ "sprite_font_code_high", 0x023694u, &sprite_font_code_high_data, 1 },
	{ "sprite_font_codes", 0x023695u, &sprite_font_codes_data, 1 },
	{ "ending_family_waits", 0x0236F8u, &ending_family_waits_data, 2 },
	{ "ending_placements", 0x023706u, &ending_placements_data, 8 },
	{ "staff_roll_titles", 0x023736u, &staff_roll_titles_data, 2 },
	{ "staff_roll_names", 0x0238B2u, &staff_roll_names_data, 2 },
	{ "stage_7_boss_beaten_health_by_players", 0x023A4Du, &stage_7_boss_beaten_health_by_players_data, 1 },
	{ "stage_7_boss_gauge_piece_health_by_players", 0x023A51u, &stage_7_boss_gauge_piece_health_by_players_data, 1 },
	{ "stage_7_boss_animations", 0x023A55u, &stage_7_boss_animations_data, 2 },
	{ "stage_7_boss_hit_boxes", 0x023A71u, &stage_7_boss_hit_boxes_data, 8 },
	{ "stage_7_boss_quick_attack_chances_by_players", 0x023AA1u, &stage_7_boss_quick_attack_chances_by_players_data, 1 },
	{ "stage_7_boss_jump_away_chances_by_players", 0x023AA5u, &stage_7_boss_jump_away_chances_by_players_data, 1 },
	{ "stage_7_boss_speeds_by_rank", 0x023AA9u, &stage_7_boss_speeds_by_rank_data, 1 },
	{ "stage_7_boss_helper_attack_times_by_rank", 0x023AB9u, &stage_7_boss_helper_attack_times_by_rank_data, 2 },
	{ "stage_7_boss_helper_speeds", 0x023B09u, &stage_7_boss_helper_speeds_data, 2 },
	{ "game_texts_address", 0x024021u, &game_texts_address_data, 2 },
	{ "object_12_placements", 0x0257BAu, &object_12_placements_data, 8 },
	{ "absent_player_blanks", 0x02597Au, &absent_player_blanks_data, 2 },
	{ "wave_cosines", 0x0259A4u, &wave_cosines_data, 1 },
	{ "game_texts", 0x0259E4u, &game_texts_data, 2 },
	{ "stage_slots", 0x02600Cu, &stage_slots_data, 3 },
	{ "screen_shake_steps", 0x027A00u, &screen_shake_steps_data, 2 },
	{ "screen_shake_lengths", 0x027A10u, &screen_shake_lengths_data, 1 },
	{ "stage_3_part_2_layer_offsets", 0x027A5Bu, &stage_3_part_2_layer_offsets_data, 4 },
	{ "krusty_balloon_beaten_health_by_players", 0x027CAEu, &krusty_balloon_beaten_health_by_players_data, 1 },
	{ "krusty_balloon_gauge_piece_health_by_players", 0x027CB2u, &krusty_balloon_gauge_piece_health_by_players_data, 1 },
	{ "krusty_balloon_animations", 0x027CB6u, &krusty_balloon_animations_data, 2 },
	{ "krusty_balloon_hit_boxes", 0x027CD0u, &krusty_balloon_hit_boxes_data, 8 },
	{ "krusty_balloon_hit_limits_by_players", 0x027D00u, &krusty_balloon_hit_limits_by_players_data, 1 },
	{ "krusty_balloon_quick_attack_chances_by_players", 0x027D04u, &krusty_balloon_quick_attack_chances_by_players_data, 1 },
	{ "krusty_balloon_fly_off_chances_by_rank", 0x027D08u, &krusty_balloon_fly_off_chances_by_rank_data, 1 },
	{ "krusty_balloon_speeds_by_rank", 0x027D18u, &krusty_balloon_speeds_by_rank_data, 1 },
	{ "krusty_balloon_throw_z_speeds", 0x027D28u, &krusty_balloon_throw_z_speeds_data, 2 },
	{ "stage_title_placements", 0x027E81u, &stage_title_placements_data, 8 },
	{ "goon_descent_starts", 0x0299F4u, &goon_descent_starts_data, 4 },
	{ "goon_from_back_xs", 0x029A72u, &goon_from_back_xs_data, 2 },
	{ "waiting_hat_goon_starts", 0x029A86u, &waiting_hat_goon_starts_data, 4 },
	{ "goon_walk_in_starts", 0x029AAEu, &goon_walk_in_starts_data, 4 },
	{ "delayed_goon_starts", 0x029AD2u, &delayed_goon_starts_data, 4 },
	{ "goon_entrances", 0x029B16u, &goon_entrances_data, 2 },
	{ "goon_side_entries", 0x029B68u, &goon_side_entries_data, 2 },
	{ "goon_run_in_starts", 0x029B7Eu, &goon_run_in_starts_data, 2 },
	{ "hat_goon_jump_in_starts", 0x029B98u, &hat_goon_jump_in_starts_data, 4 },
	{ "goon_drop_xs", 0x029BC8u, &goon_drop_xs_data, 2 },
	{ "umbrella_goon_xs", 0x029BE0u, &umbrella_goon_xs_data, 2 },
	{ "unused_goon_waits_by_rank", 0x029C2Eu, &unused_goon_waits_by_rank_data, 1 },
	{ "goon_strike_waits_by_players", 0x029C7Au, &goon_strike_waits_by_players_data, 1 },
	{ "goon_jump_attack_chances_by_rank", 0x029CA3u, &goon_jump_attack_chances_by_rank_data, 1 },
	{ "goon_hold_animations", 0x029CD3u, &goon_hold_animations_data, 1 },
	{ "shovel_goon_close_strike_waits_by_players", 0x029EE5u, &shovel_goon_close_strike_waits_by_players_data, 1 },
	{ "shovel_goon_far_strike_waits_by_players", 0x029EF4u, &shovel_goon_far_strike_waits_by_players_data, 1 },
	{ "goon_jump_in_xs", 0x029F9Bu, &goon_jump_in_xs_data, 2 },
	{ "goon_from_below_xs", 0x029FAFu, &goon_from_below_xs_data, 2 },
	{ "cemetery_umbrella_goon_xs", 0x029FC3u, &cemetery_umbrella_goon_xs_data, 2 },
	{ "fat_goon_from_back_xs", 0x02B890u, &fat_goon_from_back_xs_data, 2 },
	{ "fat_goon_strike_waits_by_players", 0x02B974u, &fat_goon_strike_waits_by_players_data, 1 },
	{ "fat_goon_hold_animations", 0x02B995u, &fat_goon_hold_animations_data, 1 },
	{ "fat_goon_jump_in_xs", 0x02B9A5u, &fat_goon_jump_in_xs_data, 2 },
	{ "fat_goon_from_below_xs", 0x02B9B9u, &fat_goon_from_below_xs_data, 2 },
	{ "enemy_waves_end_enemies", 0x02B9F1u, &enemy_waves_end_enemies_data, 1 },
	{ "object_15_spawn_lists", 0x02B9FEu, &object_15_spawn_lists_data, 2 },
	{ "enemy_waves_next_wave_enemies", 0x02BA18u, &enemy_waves_next_wave_enemies_data, 1 },
	{ "cemetery_obstacle_xs", 0x02DB58u, &cemetery_obstacle_xs_data, 2 },
	{ "cemetery_obstacle_food", 0x02DB68u, &cemetery_obstacle_food_data, 1 },
	{ "kind_10_floor_edge_flags", 0x02DBF2u, &kind_10_floor_edge_flags_data, 1 },
	{ "police_car_door_lists", 0x02DC3Eu, &police_car_door_lists_data, 2 },
	{ "player_objects", 0x02DD83u, &player_objects_data, 2 },
	{ "obstacle_heights", 0x02DDB1u, &obstacle_heights_data, 1 },
	{ "object_16_flags", 0x02DE39u, &object_16_flags_data, 1 },
	{ "rising_scenery_camera_xs", 0x02DFA1u, &rising_scenery_camera_xs_data, 2 },
	{ "item_setups", 0x02FA70u, &item_setups_data, 2 },
	{ "food_hit_kinds", 0x02FACEu, &food_hit_kinds_data, 1 },
	{ "kind_a5_partners", 0x02FB00u, &kind_a5_partners_data, 2 },
	{ "kind_a5_food_drops", 0x02FB28u, &kind_a5_food_drops_data, 2 },
	{ "item_carrier_setups", 0x02FB7Au, &item_carrier_setups_data, 2 },
	{ "item_carrier_items", 0x02FB92u, &item_carrier_items_data, 2 },
	{ "carried_item_kinds", 0x02FBB8u, &carried_item_kinds_data, 1 },
	{ "bystanders", 0x02FBCBu, &bystanders_data, 4 },
	{ "kind_b3_damage_animations", 0x02FC9Fu, &kind_b3_damage_animations_data, 1 },
	{ "krustyland_child_limits_by_players", 0x02FDA2u, &krustyland_child_limits_by_players_data, 1 },
	{ "clown_on_ball_pause_waits_by_rank", 0x02FE87u, &clown_on_ball_pause_waits_by_rank_data, 1 },
	{ "orbit_cosines", 0x02FE8Fu, &orbit_cosines_data, 1 },
	{ "kind_b2_idle_animations", 0x02FF3Bu, &kind_b2_idle_animations_data, 1 },
	{ "kind_97_timed_moves", 0x031988u, &kind_97_timed_moves_data, 4 },
	{ "object_18_behaviours", 0x0319DAu, &object_18_behaviours_data, 4 },
	{ "kind_9a_drop_starts", 0x031A30u, &kind_9a_drop_starts_data, 4 },
	{ "kind_91_appearances", 0x031A56u, &kind_91_appearances_data, 4 },
	{ "kind_97_entrances", 0x031AF8u, &kind_97_entrances_data, 2 },
	{ "kind_97_hold_animations", 0x031B0Au, &kind_97_hold_animations_data, 1 },
	{ "lumberjack_pause_loops_by_players", 0x031C0Cu, &lumberjack_pause_loops_by_players_data, 1 },
	{ "gorilla_entrances", 0x031C3Bu, &gorilla_entrances_data, 4 },
	{ "gorilla_leap_speeds", 0x031C5Du, &gorilla_leap_speeds_data, 2 },
	{ "knight_entrances", 0x031CF7u, &knight_entrances_data, 4 },
	{ "knight_entrance_styles", 0x031D51u, &knight_entrance_styles_data, 2 },
	{ "kind_c7_sweep_ways", 0x031DA1u, &kind_c7_sweep_ways_data, 1 },
	{ "kind_c7_headings", 0x031DA8u, &kind_c7_headings_data, 1 },
	{ "kind_c7_sweep_rates", 0x031DAFu, &kind_c7_sweep_rates_data, 1 },
	{ "kind_c7_start_x", 0x031DB6u, &kind_c7_start_x_data, 2 },
	{ "kind_c7_hurt_shakes", 0x031DD8u, &kind_c7_hurt_shakes_data, 1 },
	{ "kind_c7_bob_up", 0x031DDCu, &kind_c7_bob_up_data, 1 },
	{ "kind_c7_bob_down", 0x031DFCu, &kind_c7_bob_down_data, 1 },
	{ "kind_c7_shot_waits", 0x031E1Cu, &kind_c7_shot_waits_data, 1 },
	{ "kind_8e_poses", 0x031F52u, &kind_8e_poses_data, 2 },
	{ "kind_8c_animations", 0x031F7Au, &kind_8c_animations_data, 1 },
	{ "kind_a1_entrance_steps", 0x033A72u, &kind_a1_entrance_steps_data, 1 },
	{ "kind_a1_attack_delays_by_players", 0x033AB5u, &kind_a1_attack_delays_by_players_data, 1 },
	{ "robot_pieces", 0x033B10u, &robot_pieces_data, 4 },
	{ "hit_spark_times", 0x033BCCu, &hit_spark_times_data, 1 },
	{ "robot_sparks_by_frame_9d", 0x033C16u, &robot_sparks_by_frame_9d_data, 2 },
	{ "robot_sparks_by_frame_92", 0x033C3Cu, &robot_sparks_by_frame_92_data, 2 },
	{ "robot_sparks_by_frame_91", 0x033C76u, &robot_sparks_by_frame_91_data, 2 },
	{ "robot_actions_after_hit", 0x033CB8u, &robot_actions_after_hit_data, 1 },
	{ "robot_status_after_hit", 0x033CC0u, &robot_status_after_hit_data, 1 },
	{ "robot_part_zooms", 0x033D22u, &robot_part_zooms_data, 1 },
	{ "kind_12_parts", 0x033D96u, &kind_12_parts_data, 4 },
	{ "kind_b7_entrances", 0x033E32u, &kind_b7_entrances_data, 2 },
	{ "kind_b8_sweep_ways", 0x033E86u, &kind_b8_sweep_ways_data, 1 },
	{ "kind_b8_headings", 0x033E8Du, &kind_b8_headings_data, 1 },
	{ "kind_b8_sweep_rates", 0x033E94u, &kind_b8_sweep_rates_data, 1 },
	{ "kind_b8_descent_slowdowns", 0x033E9Bu, &kind_b8_descent_slowdowns_data, 2 },
	{ "kind_b8_descent_y_speeds", 0x033EA9u, &kind_b8_descent_y_speeds_data, 2 },
	{ "kind_b8_volley_shots", 0x033EC7u, &kind_b8_volley_shots_data, 2 },
	{ "kind_b8_single_shots", 0x033EEFu, &kind_b8_single_shots_data, 2 },
	{ "kind_b8_hurt_shakes", 0x033F0Du, &kind_b8_hurt_shakes_data, 1 },
	{ "kind_b8_bob_up", 0x033F11u, &kind_b8_bob_up_data, 1 },
	{ "kind_b8_bob_down", 0x033F31u, &kind_b8_bob_down_data, 1 },
	{ "kind_b8_shot_waits", 0x033F51u, &kind_b8_shot_waits_data, 1 },
	{ "kind_b8_velocities", 0x033F55u, &kind_b8_velocities_data, 4 },
	{ "kind_b8_shot_animations", 0x033FE3u, &kind_b8_shot_animations_data, 1 },
	{ "kind_b8_shot_speeds", 0x033FE9u, &kind_b8_shot_speeds_data, 2 },
	{ "unused_debug_tile_places", 0x0356E0u, &unused_debug_tile_places_data, 2 },
	{ "object_1a_next_states", 0x0357BCu, &object_1a_next_states_data, 1 },
	{ "object_1a_states_after", 0x0357C1u, &object_1a_states_after_data, 1 },
	{ "object_1a_level_rows", 0x0357C6u, &object_1a_level_rows_data, 2 },
	{ "object_1a_chase_leg_times", 0x0357FEu, &object_1a_chase_leg_times_data, 1 },
	{ "object_1a_bounce_animations", 0x03582Au, &object_1a_bounce_animations_data, 1 },
	{ "object_1a_pose_times", 0x035832u, &object_1a_pose_times_data, 1 },
	{ "object_1a_pose_animations", 0x03583Au, &object_1a_pose_animations_data, 1 },
	{ "object_1a_leap_speeds", 0x03584Eu, &object_1a_leap_speeds_data, 1 },
	{ "object_1a_leap_heights", 0x03585Eu, &object_1a_leap_heights_data, 1 },
	{ "object_1a_repeat_animations", 0x0358A0u, &object_1a_repeat_animations_data, 1 },
	{ "object_1a_approach_times", 0x0358C8u, &object_1a_approach_times_data, 1 },
	{ "object_1a_released_objects", 0x0358ECu, &object_1a_released_objects_data, 2 },
	{ "object_1a_launches", 0x035926u, &object_1a_launches_data, 2 },
	{ "object_1a_chain_links", 0x0359A6u, &object_1a_chain_links_data, 2 },
	{ "object_1a_path_choices", 0x0359DCu, &object_1a_path_choices_data, 1 },
	{ "object_1a_path_starts", 0x0359E4u, &object_1a_path_starts_data, 4 },
	{ "object_1a_path_times", 0x0359F0u, &object_1a_path_times_data, 1 },
	{ "object_1a_sines", 0x035FA3u, &object_1a_sines_data, 1 },
	{ "door_spawn_lists", 0x036454u, &door_spawn_lists_data, 2 },
	{ "door_spawns", 0x036458u, &door_spawns_data, 9 },
	{ "kind_12_door_openings", 0x036488u, &kind_12_door_openings_data, 4 },
	{ "kind_10_door_openings", 0x0364FEu, &kind_10_door_openings_data, 4 },
	{ "kind_0f_door_openings", 0x03654Du, &kind_0f_door_openings_data, 4 },
	{ "team_move_attack_states", 0x039DD5u, &team_move_attack_states_data, 1 },
	{ "object_1c_move_steps", 0x039DEBu, &object_1c_move_steps_data, 1 },
	{ "object_1c_moves", 0x039DF7u, &object_1c_moves_data, 4 },
	{ "team_move_animation_offsets", 0x039E3Du, &team_move_animation_offsets_data, 1 },
	{ "pickup_vitality", 0x039EADu, &pickup_vitality_data, 1 },
	{ "player_walk_velocities", 0x039F21u, &player_walk_velocities_data, 4 },
	{ "player_attack_boxes", 0x039F99u, &player_attack_boxes_data, 2 },
	{ "team_move_box_widths", 0x039FD1u, &team_move_box_widths_data, 1 },
	{ "zoom_steps_address", 0x03A02Au, &zoom_steps_address_data, 2 },
	{ "stage_8_boss_state_starts", 0x03BA3Au, &stage_8_boss_state_starts_data, 2 },
	{ "stage_8_boss_stop_throwing_chances_by_players", 0x03BAA5u, &stage_8_boss_stop_throwing_chances_by_players_data, 1 },
	{ "stage_8_boss_bombs_by_players", 0x03BAA9u, &stage_8_boss_bombs_by_players_data, 1 },
	{ "stage_8_boss_run_speeds_by_players", 0x03BAADu, &stage_8_boss_run_speeds_by_players_data, 1 },
	{ "stage_8_boss_hit_limits_address", 0x03BAB1u, &stage_8_boss_hit_limits_address_data, 2 },
	{ "stage_8_boss_invulnerable_times_by_players", 0x03BAB5u, &stage_8_boss_invulnerable_times_by_players_data, 1 },
	{ "stage_8_boss_run_skip_attack_chances_by_players", 0x03BAB9u, &stage_8_boss_run_skip_attack_chances_by_players_data, 1 },
	{ "stage_8_boss_retreat_speeds_by_players", 0x03BAC1u, &stage_8_boss_retreat_speeds_by_players_data, 1 },
	{ "stage_8_boss_walk_speeds_by_players", 0x03BAC5u, &stage_8_boss_walk_speeds_by_players_data, 1 },
	{ "stage_8_boss_jump_speeds_by_players", 0x03BAC9u, &stage_8_boss_jump_speeds_by_players_data, 1 },
	{ "stage_8_boss_dash_speeds_by_players", 0x03BACDu, &stage_8_boss_dash_speeds_by_players_data, 1 },
	{ "stage_8_boss_jump_bomb_player_limits", 0x03BAD1u, &stage_8_boss_jump_bomb_player_limits_data, 1 },
	{ "burns_robot_volleys_by_players", 0x03BB5Au, &burns_robot_volleys_by_players_data, 1 },
	{ "burns_robot_shot_y_speeds", 0x03BB76u, &burns_robot_shot_y_speeds_data, 2 },
	{ "burns_robot_healths", 0x03BB80u, &burns_robot_healths_data, 1 },
	{ "burns_robot_beaten_healths", 0x03BB85u, &burns_robot_beaten_healths_data, 2 },
	{ "burns_robot_second_attack_chances_by_players", 0x03BBA3u, &burns_robot_second_attack_chances_by_players_data, 1 },
	{ "burns_robot_shot_times", 0x03BBA7u, &burns_robot_shot_times_data, 2 },
	{ "burns_robot_held_part_times", 0x03BBC7u, &burns_robot_held_part_times_data, 2 },
	{ "burns_robot_quick_attack_chances", 0x03BBE7u, &burns_robot_quick_attack_chances_data, 2 },
	{ "burns_robot_animations", 0x03BBF9u, &burns_robot_animations_data, 2 },
	{ "burns_robot_hit_boxes", 0x03BC65u, &burns_robot_hit_boxes_data, 2 },
	{ "burns_robot_walk_speeds", 0x03BCD7u, &burns_robot_walk_speeds_data, 2 },
	{ "object_1d_parts", 0x03BD21u, &object_1d_parts_data, 8 },
	{ "scripted_object_scripts", 0x03D8B5u, &scripted_object_scripts_data, 2 },
	{ "football_player_attack_delays_by_players", 0x03DDA6u, &football_player_attack_delays_by_players_data, 1 },
	{ "football_player_speed_ranges_by_rank", 0x03DDAAu, &football_player_speed_ranges_by_rank_data, 1 },
	{ "bear_attack_delays_by_players", 0x03DE64u, &bear_attack_delays_by_players_data, 1 },
	{ "bear_charge_speeds_by_rank", 0x03DE80u, &bear_charge_speeds_by_rank_data, 2 },
	{ "stage_3_boss_slow_attack_chances_by_players", 0x03DF36u, &stage_3_boss_slow_attack_chances_by_players_data, 1 },
	{ "stage_3_boss_follow_up_chances_by_players", 0x03DF39u, &stage_3_boss_follow_up_chances_by_players_data, 1 },
	{ "story_scripts", 0x03F078u, &story_scripts_data, 2 },
	{ "player_overhead_heights", 0x03FE77u, &player_overhead_heights_data, 1 },
	{ "player_throw_heights", 0x03FE7Bu, &player_throw_heights_data, 1 },
	{ "player_balloon_animations", 0x03FE7Fu, &player_balloon_animations_data, 1 },
	{ "pair_balloon_players", 0x03FE84u, &pair_balloon_players_data, 1 },
	{ "player_state_classes", 0x03FE94u, &player_state_classes_data, 1 },
	{ "profile_moves", 0x0410E3u, &profile_moves_data, 2 },
	{ "profile_texts", 0x041106u, &profile_texts_data, 2 },
	{ "gauge_player_records", 0x041294u, &gauge_player_records_data, 2 },
	{ "gauge_pictures", 0x041316u, &gauge_pictures_data, 2 },
	{ "continue_digit_pictures", 0x0413F1u, &continue_digit_pictures_data, 2 },
	{ "rank_by_players", 0x041786u, &rank_by_players_data, 1 },
	{ "rank_by_scene", 0x04178Au, &rank_by_scene_data, 1 },
	{ "rank_step_times", 0x041796u, &rank_step_times_data, 2 },
	{ "palette_effects", 0x05C000u, &palette_effects_data, 2 },
	{ "test_menu_cursor_steps", 0x05E502u, &test_menu_cursor_steps_data, 1 },
	{ "test_mode_hex_digit_tiles", 0x05F5AEu, &test_mode_hex_digit_tiles_data, 1 },
	{ "test_mode_texts", 0x05F5BEu, &test_mode_texts_data, 2 },
	{ "test_mode_words", 0x05F8F7u, &test_mode_words_data, 2 },
	{ "coin_setting_coin_digits", 0x05FA5Cu, &coin_setting_coin_digits_data, 1 },
	{ "coin_setting_credit_digits", 0x05FA6Eu, &coin_setting_credit_digits_data, 1 },
	{ "eeprom_address_signals", 0x05FCA7u, &eeprom_address_signals_data, 1 },
	{ "eeprom_data_signals", 0x05FCB6u, &eeprom_data_signals_data, 1 },
	{ "eeprom_wait_signal", 0x05FCCBu, &eeprom_wait_signal_data, 1 },
	{ "graphics_rom_sums", 0x05FD5Cu, &graphics_rom_sums_data, 2 },
	{ "graphics_rom_result_places", 0x05FD68u, &graphics_rom_result_places_data, 2 },
	{ "sprite_rom_read_banks", 0x05FD74u, &sprite_rom_read_banks_data, 1 },
	{ "test_player_records", 0x05FD88u, &test_player_records_data, 2 },
	{ "palette_request_handlers", 0x07BADAu, &palette_request_handlers_data, 2 },
	{ "coinages", 0x07E3EBu, &coinages_data, 1 },
	{ "rom_13c_sum", 0x07E423u, &rom_13c_sum_data, 2 },
	{ "rom_15c_sum", 0x07E425u, &rom_15c_sum_data, 2 },
	{ "rom_16c_sum", 0x07E427u, &rom_16c_sum_data, 2 },
	{ "rom_17c_sum", 0x07E429u, &rom_17c_sum_data, 2 },
	{ "hex_digit_tiles", 0x07E435u, &hex_digit_tiles_data, 1 },
	{ "score_additions", 0x07E445u, &score_additions_data, 2 },
	{ "player_presses", 0x07E449u, &player_presses_data, 2 },
	{ "hurt_effect_rows", 0x07E526u, &hurt_effect_rows_data, 2 },
	{ "step_sprite_priorities", 0x07E574u, &step_sprite_priorities_data, 1 },
	{ "shadow_sprites", 0x07E585u, &shadow_sprites_data, 4 },
	{ "demos", 0x07E6A1u, &demos_data, 2 },
	{ "scene_routines", 0x07E7D3u, &scene_routines_data, 4 },
	{ "player_records", 0x07E819u, &player_records_data, 2 },
	{ "step_scenes", 0x07E88Du, &step_scenes_data, 1 },
	{ "layer_maps", 0x07EC9Du, &layer_maps_data, 2 },
	{ "layers", 0x07ECA1u, &layers_data, 18 },
	{ "block_scenes_a", 0x07ECC9u, &block_scenes_a_data, 2 },
	{ "block_scenes_b", 0x07ECE9u, &block_scenes_b_data, 2 },
	{ "layer_modes", 0x07EF55u, &layer_modes_data, 2 },
	{ "tile_pictures", 0x07EFB5u, &tile_pictures_data, 2 },
	{ "spawn_list_places", 0x07EFBCu, &spawn_list_places_data, 2 },
	{ "enemy_speeds_by_rank", 0x07EFD4u, &enemy_speeds_by_rank_data, 1 },
	{ "object_list_sizes", 0x07EFF4u, &object_list_sizes_data, 1 },
	{ "object_lists", 0x07EFF8u, &object_lists_data, 2 },
	{ "enemy_limits_by_difficulty", 0x07F000u, &enemy_limits_by_difficulty_data, 1 },
	{ "extra_enemies_by_scene", 0x07F008u, &extra_enemies_by_scene_data, 1 },
	{ "cemetery_enemy_limits_by_players", 0x07F014u, &cemetery_enemy_limits_by_players_data, 1 },
	{ "attackers_per_player", 0x07F031u, &attackers_per_player_data, 1 },
	{ "sines", 0x07F061u, &sines_data, 1 },
	{ "sines_20", 0x07F0A2u, &sines_20_data, 1 },
	{ "arctangents", 0x07F0E3u, &arctangents_data, 1 },
	{ "climb_speeds", 0x07F124u, &climb_speeds_data, 1 },
	{ "enemy_banks", 0x07F387u, &enemy_banks_data, 1 },
	{ "object_list_1_banks", 0x07F4B0u, &object_list_1_banks_data, 1 },
	{ "child_object_banks", 0x07F54Cu, &child_object_banks_data, 1 },
	{ "stage_event_banks", 0x07F581u, &stage_event_banks_data, 1 },
	{ "action_banks", 0x07F620u, &action_banks_data, 1 },
	{ "unused_object_banks", 0x07F661u, &unused_object_banks_data, 1 },
	{ "block_tile_flags", 0x07F67Cu, &block_tile_flags_data, 1 },
	{ "reset_vector", 0x07FFFEu, &reset_vector_data, 2 },
};

const size_t game_table_count = 285;
