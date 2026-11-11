/**
 *    Name:        ram.h
 *    Description: the game's variables, tables, board registers and structures
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#ifndef SIMPSONS_RAM_H
#define SIMPSONS_RAM_H

/* the game's variables in work RAM (4000-5FFF), which the board keeps the other way round */
#define floor_map_ADDRESS 0x4000u
#define floor_map RAM8(floor_map_ADDRESS)
#define game_mode_ADDRESS 0x4800u
#define game_mode RAM8(game_mode_ADDRESS)
#define mode_step_ADDRESS 0x4801u
#define mode_step RAM8(mode_step_ADDRESS)
#define mode_phase_ADDRESS 0x4802u
#define mode_phase RAM8(mode_phase_ADDRESS)
#define game_step_ADDRESS 0x4803u
#define game_step RAM8(game_step_ADDRESS)
#define step_phase_ADDRESS 0x4804u
#define step_phase RAM8(step_phase_ADDRESS)
#define step_subphase_ADDRESS 0x4805u
#define step_subphase RAM8(step_subphase_ADDRESS)
#define step_countdown_ADDRESS 0x4806u
#define step_countdown RAM8(step_countdown_ADDRESS)
#define unused_mode_word_ADDRESS 0x4807u
#define unused_mode_word RAM16(unused_mode_word_ADDRESS)
#define attract_timer_ADDRESS 0x4809u
#define attract_timer RAM8(attract_timer_ADDRESS)
#define scene_timer_ADDRESS 0x480Au
#define scene_timer RAM16(scene_timer_ADDRESS)
#define step_timer_ADDRESS 0x480Bu
#define step_timer RAM16(step_timer_ADDRESS)
#define unused_mode_byte_ADDRESS 0x480Du
#define unused_mode_byte RAM8(unused_mode_byte_ADDRESS)
#define window_bank_ADDRESS 0x480Eu
#define window_bank RAM8(window_bank_ADDRESS)
#define board_control_ADDRESS 0x480Fu
#define board_control RAM8(board_control_ADDRESS)
#define board_output_ADDRESS 0x4810u
#define board_output RAM8(board_output_ADDRESS)
#define in_attract_ADDRESS 0x4811u
#define in_attract RAM8(in_attract_ADDRESS)
#define irq_busy_ADDRESS 0x4812u
#define irq_busy RAM8(irq_busy_ADDRESS)
#define attract_sound_ADDRESS 0x4813u
#define attract_sound RAM8(attract_sound_ADDRESS)
#define difficulty_setting_ADDRESS 0x4814u
#define difficulty_setting RAM8(difficulty_setting_ADDRESS)
#define frame_count_ADDRESS 0x4815u
#define frame_count RAM16(frame_count_ADDRESS)
#define slot_credits_ADDRESS 0x4817u
#define slot_credits RAM16(slot_credits_ADDRESS)
#define slot_1_coins_ADDRESS 0x4819u
#define slot_1_coins RAM8(slot_1_coins_ADDRESS)
#define slot_1_counter_pulses_ADDRESS 0x481Au
#define slot_1_counter_pulses RAM8(slot_1_counter_pulses_ADDRESS)
#define slot_1_counter_time_ADDRESS 0x481Bu
#define slot_1_counter_time RAM8(slot_1_counter_time_ADDRESS)
#define slot_1_coins_per_credit_ADDRESS 0x481Cu
#define slot_1_coins_per_credit RAM8(slot_1_coins_per_credit_ADDRESS)
#define slot_1_credits_per_coins_ADDRESS 0x481Du
#define slot_1_credits_per_coins RAM8(slot_1_credits_per_coins_ADDRESS)
#define slot_1_credit_given_ADDRESS 0x481Eu
#define slot_1_credit_given RAM8(slot_1_credit_given_ADDRESS)
#define slot_2_credits_ADDRESS 0x481Fu
#define slot_2_credits RAM16(slot_2_credits_ADDRESS)
#define slot_2_counter_pulses_ADDRESS 0x4822u
#define slot_2_counter_pulses RAM8(slot_2_counter_pulses_ADDRESS)
#define slot_2_counter_time_ADDRESS 0x4823u
#define slot_2_counter_time RAM8(slot_2_counter_time_ADDRESS)
#define slot_2_coins_per_credit_ADDRESS 0x4824u
#define slot_2_coins_per_credit RAM8(slot_2_coins_per_credit_ADDRESS)
#define slot_2_credits_per_coins_ADDRESS 0x4825u
#define slot_2_credits_per_coins RAM8(slot_2_credits_per_coins_ADDRESS)
#define slot_3_credits_ADDRESS 0x4827u
#define slot_3_credits RAM16(slot_3_credits_ADDRESS)
#define slot_4_credits_ADDRESS 0x482Fu
#define slot_4_credits RAM16(slot_4_credits_ADDRESS)
#define credits_ADDRESS 0x4837u
#define credits RAM16(credits_ADDRESS)
#define four_coin_slots_ADDRESS 0x4839u
#define four_coin_slots RAM8(four_coin_slots_ADDRESS)
#define first_credit_extra_coins_ADDRESS 0x483Au
#define first_credit_extra_coins RAM8(first_credit_extra_coins_ADDRESS)
#define separate_coin_slots_ADDRESS 0x483Bu
#define separate_coin_slots RAM8(separate_coin_slots_ADDRESS)
#define coin_inputs_ADDRESS 0x483Du
#define coin_inputs RAM8(coin_inputs_ADDRESS)
#define coin_inputs_last_ADDRESS 0x483Eu
#define coin_inputs_last RAM8(coin_inputs_last_ADDRESS)
#define coin_inputs_before_ADDRESS 0x483Fu
#define coin_inputs_before RAM8(coin_inputs_before_ADDRESS)
#define player_controls_ADDRESS 0x4840u
#define player_controls(index) RAM8(player_controls_ADDRESS + (index))
#define players_playing_ADDRESS 0x4850u
#define players_playing RAM8(players_playing_ADDRESS)
#define coins_inserted_ADDRESS 0x4851u
#define coins_inserted RAM8(coins_inserted_ADDRESS)
#define sprite_chip_control_ADDRESS 0x4855u
#define sprite_chip_control RAM8(sprite_chip_control_ADDRESS)
#define dma_pending_ADDRESS 0x4856u
#define dma_pending RAM8(dma_pending_ADDRESS)
#define player_count_ADDRESS 0x4857u
#define player_count RAM8(player_count_ADDRESS)
#define random_number_ADDRESS 0x4858u
#define random_number RAM8(random_number_ADDRESS)
#define lives_per_credit_ADDRESS 0x485Au
#define lives_per_credit RAM8(lives_per_credit_ADDRESS)
#define players_joined_ADDRESS 0x485Bu
#define players_joined RAM8(players_joined_ADDRESS)
#define layer_clear_pending_ADDRESS 0x485Du
#define layer_clear_pending RAM8(layer_clear_pending_ADDRESS)
#define demo_number_ADDRESS 0x485Eu
#define demo_number RAM8(demo_number_ADDRESS)
#define flip_screen_ADDRESS 0x485Fu
#define flip_screen RAM8(flip_screen_ADDRESS)
#define play_variables_ADDRESS 0x4860u
#define play_variables RAM8(play_variables_ADDRESS)
#define rank_ADDRESS 0x4861u
#define rank RAM8(rank_ADDRESS)
#define rank_time_step_ADDRESS 0x4862u
#define rank_time_step RAM8(rank_time_step_ADDRESS)
#define rank_frames_ADDRESS 0x4863u
#define rank_frames RAM16(rank_frames_ADDRESS)
#define camera_wait_frames_ADDRESS 0x4865u
#define camera_wait_frames RAM16(camera_wait_frames_ADDRESS)
#define scene_ADDRESS 0x4867u
#define scene RAM8(scene_ADDRESS)
#define gauges_shown_ADDRESS 0x486Au
#define gauges_shown RAM8(gauges_shown_ADDRESS)
#define difficulty_ADDRESS 0x486Bu
#define difficulty RAM8(difficulty_ADDRESS)
#define stage_variables_ADDRESS 0x4870u
#define stage_variables RAM8(stage_variables_ADDRESS)
#define text_colour_ADDRESS 0x4871u
#define text_colour RAM8(text_colour_ADDRESS)
#define scene_running_ADDRESS 0x4872u
#define scene_running RAM8(scene_running_ADDRESS)
#define spawn_next_ADDRESS 0x4873u
#define spawn_next RAM16(spawn_next_ADDRESS)
#define map_scene_ADDRESS 0x4875u
#define map_scene RAM8(map_scene_ADDRESS)
#define map_area_ADDRESS 0x4876u
#define map_area RAM8(map_area_ADDRESS)
#define title_card_step_ADDRESS 0x4877u
#define title_card_step RAM8(title_card_step_ADDRESS)
#define skip_wait_ADDRESS 0x4878u
#define skip_wait RAM8(skip_wait_ADDRESS)
#define objects_frozen_ADDRESS 0x4879u
#define objects_frozen RAM8(objects_frozen_ADDRESS)
#define bonus_seconds_ADDRESS 0x487Au
#define bonus_seconds RAM8(bonus_seconds_ADDRESS)
#define bonus_frames_ADDRESS 0x487Bu
#define bonus_frames RAM8(bonus_frames_ADDRESS)
#define boss_arrived_ADDRESS 0x487Cu
#define boss_arrived RAM8(boss_arrived_ADDRESS)
#define boss_beaten_ADDRESS 0x487Du
#define boss_beaten RAM8(boss_beaten_ADDRESS)
#define palette_request_kind_ADDRESS 0x487Eu
#define palette_request_kind RAM8(palette_request_kind_ADDRESS)
#define palette_jobs_left_ADDRESS 0x487Fu
#define palette_jobs_left RAM8(palette_jobs_left_ADDRESS)
#define stage_part_ADDRESS 0x4880u
#define stage_part RAM8(stage_part_ADDRESS)
#define stage_cue_ADDRESS 0x4881u
#define stage_cue RAM8(stage_cue_ADDRESS)
#define stage_cue_timer_ADDRESS 0x4882u
#define stage_cue_timer RAM8(stage_cue_timer_ADDRESS)
#define profile_typed_ADDRESS 0x4883u
#define profile_typed RAM8(profile_typed_ADDRESS)
#define profile_alias_typed_ADDRESS 0x4884u
#define profile_alias_typed RAM8(profile_alias_typed_ADDRESS)
#define players_present_ADDRESS 0x4885u
#define players_present RAM8(players_present_ADDRESS)
#define sprite_scroll_x_ADDRESS 0x4886u
#define sprite_scroll_x RAM16(sprite_scroll_x_ADDRESS)
#define sprite_scroll_x_pad_ADDRESS 0x4888u
#define sprite_scroll_x_pad RAM8(sprite_scroll_x_pad_ADDRESS)
#define sprite_scroll_y_ADDRESS 0x4889u
#define sprite_scroll_y RAM16(sprite_scroll_y_ADDRESS)
#define sprite_scroll_y_pad_ADDRESS 0x488Bu
#define sprite_scroll_y_pad RAM8(sprite_scroll_y_pad_ADDRESS)
#define in_cemetery_ADDRESS 0x488Du
#define in_cemetery RAM8(in_cemetery_ADDRESS)
#define cemetery_layer_offset_step_ADDRESS 0x488Eu
#define cemetery_layer_offset_step RAM8(cemetery_layer_offset_step_ADDRESS)
#define hurry_up_out_ADDRESS 0x488Fu
#define hurry_up_out RAM8(hurry_up_out_ADDRESS)
#define hurry_up_object_ADDRESS 0x4890u
#define hurry_up_object RAM16(hurry_up_object_ADDRESS)
#define stage_scrolls_on_ADDRESS 0x4892u
#define stage_scrolls_on RAM8(stage_scrolls_on_ADDRESS)
#define hurry_up_frames_ADDRESS 0x4893u
#define hurry_up_frames RAM16(hurry_up_frames_ADDRESS)
#define screen_shake_frame_ADDRESS 0x4895u
#define screen_shake_frame RAM8(screen_shake_frame_ADDRESS)
#define screen_shake_step_ADDRESS 0x4896u
#define screen_shake_step RAM8(screen_shake_step_ADDRESS)
#define screen_shake_on_ADDRESS 0x4897u
#define screen_shake_on RAM8(screen_shake_on_ADDRESS)
#define screen_shake_kind_ADDRESS 0x4898u
#define screen_shake_kind RAM8(screen_shake_kind_ADDRESS)
#define draw_all_layer_edges_ADDRESS 0x4899u
#define draw_all_layer_edges RAM8(draw_all_layer_edges_ADDRESS)
#define layer_columns_to_draw_ADDRESS 0x489Au
#define layer_columns_to_draw RAM8(layer_columns_to_draw_ADDRESS)
#define layer_rows_to_draw_ADDRESS 0x489Bu
#define layer_rows_to_draw RAM8(layer_rows_to_draw_ADDRESS)
#define layer_columns_on_ADDRESS 0x489Cu
#define layer_columns_on RAM8(layer_columns_on_ADDRESS)
#define layer_rows_on_ADDRESS 0x489Du
#define layer_rows_on RAM8(layer_rows_on_ADDRESS)
#define map_bank_ADDRESS 0x489Eu
#define map_bank RAM8(map_bank_ADDRESS)
#define entry_start_camera_y_ADDRESS 0x489Fu
#define entry_start_camera_y RAM16(entry_start_camera_y_ADDRESS)
#define floor_pattern_offset_ADDRESS 0x48A1u
#define floor_pattern_offset RAM8(floor_pattern_offset_ADDRESS)
#define floor_pattern_ADDRESS 0x48A2u
#define floor_pattern RAM8(floor_pattern_ADDRESS)
#define block_cells_left_ADDRESS 0x48A3u
#define block_cells_left RAM8(block_cells_left_ADDRESS)
#define stage_record_entry_ADDRESS 0x48A4u
#define stage_record_entry RAM16(stage_record_entry_ADDRESS)
#define camera_main_layer_ADDRESS 0x48A6u
#define camera_main_layer RAM8(camera_main_layer_ADDRESS)
#define camera_x_held_ADDRESS 0x48A7u
#define camera_x_held RAM8(camera_x_held_ADDRESS)
#define camera_y_held_ADDRESS 0x48A8u
#define camera_y_held RAM8(camera_y_held_ADDRESS)
#define layer_a_edges_on_ADDRESS 0x48A9u
#define layer_a_edges_on RAM8(layer_a_edges_on_ADDRESS)
#define layer_b_edges_on_ADDRESS 0x48AAu
#define layer_b_edges_on RAM8(layer_b_edges_on_ADDRESS)
#define stage_scroll_step_ADDRESS 0x48ABu
#define stage_scroll_step RAM8(stage_scroll_step_ADDRESS)
#define camera_x_ADDRESS 0x48ACu
#define camera_x RAM16(camera_x_ADDRESS)
#define camera_x_fraction_ADDRESS 0x48AEu
#define camera_x_fraction RAM8(camera_x_fraction_ADDRESS)
#define last_stage_scroll_x_ADDRESS 0x48AFu
#define last_stage_scroll_x RAM16(last_stage_scroll_x_ADDRESS)
#define camera_y_ADDRESS 0x48B2u
#define camera_y RAM16(camera_y_ADDRESS)
#define camera_y_fraction_ADDRESS 0x48B4u
#define camera_y_fraction RAM8(camera_y_fraction_ADDRESS)
#define last_stage_scroll_y_ADDRESS 0x48B5u
#define last_stage_scroll_y RAM16(last_stage_scroll_y_ADDRESS)
#define cemetery_scroll_ADDRESS 0x48B8u
#define cemetery_scroll RAM16(cemetery_scroll_ADDRESS)
#define cemetery_scroll_fraction_ADDRESS 0x48BAu
#define cemetery_scroll_fraction RAM8(cemetery_scroll_fraction_ADDRESS)
#define last_cemetery_scroll_high_ADDRESS 0x48BBu
#define last_cemetery_scroll_high RAM8(last_cemetery_scroll_high_ADDRESS)
#define last_cemetery_scroll_low_ADDRESS 0x48BCu
#define last_cemetery_scroll_low RAM16(last_cemetery_scroll_low_ADDRESS)
#define layer_a_scroll_x_ADDRESS 0x48BEu
#define layer_a_scroll_x RAM16(layer_a_scroll_x_ADDRESS)
#define layer_a_last_scroll_x_ADDRESS 0x48C1u
#define layer_a_last_scroll_x RAM16(layer_a_last_scroll_x_ADDRESS)
#define layer_a_offset_x_ADDRESS 0x48C3u
#define layer_a_offset_x RAM16(layer_a_offset_x_ADDRESS)
#define layer_a_scroll_y_ADDRESS 0x48C5u
#define layer_a_scroll_y RAM16(layer_a_scroll_y_ADDRESS)
#define layer_a_last_scroll_y_ADDRESS 0x48C8u
#define layer_a_last_scroll_y RAM16(layer_a_last_scroll_y_ADDRESS)
#define layer_a_offset_y_ADDRESS 0x48CAu
#define layer_a_offset_y RAM16(layer_a_offset_y_ADDRESS)
#define layer_a_offset_y2_ADDRESS 0x48CCu
#define layer_a_offset_y2 RAM16(layer_a_offset_y2_ADDRESS)
#define layer_b_scroll_x_ADDRESS 0x48CEu
#define layer_b_scroll_x RAM16(layer_b_scroll_x_ADDRESS)
#define layer_b_last_scroll_x_ADDRESS 0x48D1u
#define layer_b_last_scroll_x RAM16(layer_b_last_scroll_x_ADDRESS)
#define layer_b_offset_x_ADDRESS 0x48D3u
#define layer_b_offset_x RAM16(layer_b_offset_x_ADDRESS)
#define layer_b_scroll_y_ADDRESS 0x48D5u
#define layer_b_scroll_y RAM16(layer_b_scroll_y_ADDRESS)
#define layer_b_scroll_y_fraction_ADDRESS 0x48D7u
#define layer_b_scroll_y_fraction RAM8(layer_b_scroll_y_fraction_ADDRESS)
#define layer_b_last_scroll_y_ADDRESS 0x48D8u
#define layer_b_last_scroll_y RAM16(layer_b_last_scroll_y_ADDRESS)
#define layer_b_offset_y_ADDRESS 0x48DAu
#define layer_b_offset_y RAM16(layer_b_offset_y_ADDRESS)
#define camera_x_speed_ADDRESS 0x48DEu
#define camera_x_speed RAM16S(camera_x_speed_ADDRESS)
#define camera_y_speed_ADDRESS 0x48E0u
#define camera_y_speed RAM16S(camera_y_speed_ADDRESS)
#define cemetery_scroll_speed_ADDRESS 0x48E2u
#define cemetery_scroll_speed RAM16(cemetery_scroll_speed_ADDRESS)
#define players_push_x_ADDRESS 0x48E4u
#define players_push_x RAM16S(players_push_x_ADDRESS)
#define players_push_y_ADDRESS 0x48E6u
#define players_push_y RAM16S(players_push_y_ADDRESS)
#define sound_queue_write_ADDRESS 0x4900u
#define sound_queue_write RAM16(sound_queue_write_ADDRESS)
#define sound_queue_read_ADDRESS 0x4902u
#define sound_queue_read RAM16(sound_queue_read_ADDRESS)
#define sound_queue_ADDRESS 0x4904u
#define sound_queue(index) RAM16(sound_queue_ADDRESS + (index) * 2u)
#define job_queue_write_ADDRESS 0x4940u
#define job_queue_write RAM16(job_queue_write_ADDRESS)
#define job_queue_read_ADDRESS 0x4942u
#define job_queue_read RAM16(job_queue_read_ADDRESS)
#define job_queue_ADDRESS 0x4944u
#define job_queue(index) RAM16(job_queue_ADDRESS + (index) * 2u)
#define high_scores_ADDRESS 0x4980u
#define high_scores(index) RAM8(high_scores_ADDRESS + (index))
#define player_variables_ADDRESS 0x49D0u
#define player_variables RAM8(player_variables_ADDRESS)
#define marge_entry_status_ADDRESS 0x49D3u
#define marge_entry_status RAM8(marge_entry_status_ADDRESS)
#define marge_score_ADDRESS 0x49D4u
#define marge_score RAM16(marge_score_ADDRESS)
#define marge_grab_hints_ADDRESS 0x49D6u
#define marge_grab_hints RAM8(marge_grab_hints_ADDRESS)
#define marge_state_ADDRESS 0x49D7u
#define marge_state RAM8(marge_state_ADDRESS)
#define homer_lives_ADDRESS 0x49D8u
#define homer_lives RAM16(homer_lives_ADDRESS)
#define homer_entry_status_ADDRESS 0x49DBu
#define homer_entry_status RAM8(homer_entry_status_ADDRESS)
#define homer_score_ADDRESS 0x49DCu
#define homer_score RAM16(homer_score_ADDRESS)
#define homer_grab_hints_ADDRESS 0x49DEu
#define homer_grab_hints RAM8(homer_grab_hints_ADDRESS)
#define homer_state_ADDRESS 0x49DFu
#define homer_state RAM8(homer_state_ADDRESS)
#define bart_lives_ADDRESS 0x49E0u
#define bart_lives RAM16(bart_lives_ADDRESS)
#define bart_entry_status_ADDRESS 0x49E3u
#define bart_entry_status RAM8(bart_entry_status_ADDRESS)
#define bart_score_ADDRESS 0x49E4u
#define bart_score RAM16(bart_score_ADDRESS)
#define bart_grab_hints_ADDRESS 0x49E6u
#define bart_grab_hints RAM8(bart_grab_hints_ADDRESS)
#define bart_state_ADDRESS 0x49E7u
#define bart_state RAM8(bart_state_ADDRESS)
#define lisa_lives_ADDRESS 0x49E8u
#define lisa_lives RAM16(lisa_lives_ADDRESS)
#define lisa_entry_status_ADDRESS 0x49EBu
#define lisa_entry_status RAM8(lisa_entry_status_ADDRESS)
#define lisa_score_ADDRESS 0x49ECu
#define lisa_score RAM16(lisa_score_ADDRESS)
#define lisa_grab_hints_ADDRESS 0x49EEu
#define lisa_grab_hints RAM8(lisa_grab_hints_ADDRESS)
#define lisa_state_ADDRESS 0x49EFu
#define lisa_state RAM8(lisa_state_ADDRESS)
#define marge_play_status_ADDRESS 0x49F0u
#define marge_play_status RAM8(marge_play_status_ADDRESS)
#define homer_play_status_ADDRESS 0x49F1u
#define homer_play_status RAM8(homer_play_status_ADDRESS)
#define bart_play_status_ADDRESS 0x49F2u
#define bart_play_status RAM8(bart_play_status_ADDRESS)
#define lisa_play_status_ADDRESS 0x49F3u
#define lisa_play_status RAM8(lisa_play_status_ADDRESS)
#define marge_gauge_step_ADDRESS 0x4A02u
#define marge_gauge_step RAM8(marge_gauge_step_ADDRESS)
#define marge_gauge_delay_ADDRESS 0x4A03u
#define marge_gauge_delay RAM8(marge_gauge_delay_ADDRESS)
#define unused_marge_word_2_ADDRESS 0x4A04u
#define unused_marge_word_2 RAM16(unused_marge_word_2_ADDRESS)
#define unused_marge_byte_ADDRESS 0x4A06u
#define unused_marge_byte RAM8(unused_marge_byte_ADDRESS)
#define homer_gauge_step_ADDRESS 0x4A09u
#define homer_gauge_step RAM8(homer_gauge_step_ADDRESS)
#define homer_gauge_delay_ADDRESS 0x4A0Au
#define homer_gauge_delay RAM8(homer_gauge_delay_ADDRESS)
#define unused_homer_word_2_ADDRESS 0x4A0Bu
#define unused_homer_word_2 RAM16(unused_homer_word_2_ADDRESS)
#define unused_homer_byte_ADDRESS 0x4A0Du
#define unused_homer_byte RAM8(unused_homer_byte_ADDRESS)
#define bart_gauge_step_ADDRESS 0x4A10u
#define bart_gauge_step RAM8(bart_gauge_step_ADDRESS)
#define bart_gauge_delay_ADDRESS 0x4A11u
#define bart_gauge_delay RAM8(bart_gauge_delay_ADDRESS)
#define unused_bart_word_2_ADDRESS 0x4A12u
#define unused_bart_word_2 RAM16(unused_bart_word_2_ADDRESS)
#define unused_bart_byte_ADDRESS 0x4A14u
#define unused_bart_byte RAM8(unused_bart_byte_ADDRESS)
#define lisa_gauge_step_ADDRESS 0x4A17u
#define lisa_gauge_step RAM8(lisa_gauge_step_ADDRESS)
#define lisa_gauge_delay_ADDRESS 0x4A18u
#define lisa_gauge_delay RAM8(lisa_gauge_delay_ADDRESS)
#define unused_lisa_word_2_ADDRESS 0x4A19u
#define unused_lisa_word_2 RAM16(unused_lisa_word_2_ADDRESS)
#define unused_lisa_byte_ADDRESS 0x4A1Bu
#define unused_lisa_byte RAM8(unused_lisa_byte_ADDRESS)
#define continue_seconds_ADDRESS 0x4A1Cu
#define continue_seconds RAM8(continue_seconds_ADDRESS)
#define continue_player_ADDRESS 0x4A1Du
#define continue_player RAM8(continue_player_ADDRESS)
#define continue_seconds_heard_ADDRESS 0x4A21u
#define continue_seconds_heard RAM8(continue_seconds_heard_ADDRESS)
#define continue_frames_ADDRESS 0x4A22u
#define continue_frames RAM8(continue_frames_ADDRESS)
#define demo_frames_ADDRESS 0x5800u
#define demo_frames RAM16(demo_frames_ADDRESS)
#define marge_demo_controls_ADDRESS 0x5813u
#define marge_demo_controls RAM8(marge_demo_controls_ADDRESS)
#define homer_demo_controls_ADDRESS 0x5823u
#define homer_demo_controls RAM8(homer_demo_controls_ADDRESS)
#define bart_demo_controls_ADDRESS 0x5833u
#define bart_demo_controls RAM8(bart_demo_controls_ADDRESS)
#define lisa_demo_controls_ADDRESS 0x5843u
#define lisa_demo_controls RAM8(lisa_demo_controls_ADDRESS)
#define test_mode_variables_ADDRESS 0x5900u
#define test_mode_variables RAM8(test_mode_variables_ADDRESS)
#define test_page_ADDRESS 0x5908u
#define test_page RAM8(test_page_ADDRESS)
#define test_page_step_ADDRESS 0x5909u
#define test_page_step RAM8(test_page_step_ADDRESS)
#define test_menu_length_ADDRESS 0x590Au
#define test_menu_length RAM8(test_menu_length_ADDRESS)
#define test_menu_cursor_variable_ADDRESS 0x590Bu
#define test_menu_cursor_variable RAM16(test_menu_cursor_variable_ADDRESS)
#define test_menu_lines_ADDRESS 0x590Du
#define test_menu_lines RAM16(test_menu_lines_ADDRESS)
#define test_check_cursor_ADDRESS 0x5912u
#define test_check_cursor RAM8(test_check_cursor_ADDRESS)
#define test_cursor_ADDRESS 0x5913u
#define test_cursor RAM8(test_cursor_ADDRESS)
#define test_cursor_repeat_ADDRESS 0x5914u
#define test_cursor_repeat RAM8(test_cursor_repeat_ADDRESS)
#define test_music_number_ADDRESS 0x5915u
#define test_music_number RAM8(test_music_number_ADDRESS)
#define test_sound_number_ADDRESS 0x5916u
#define test_sound_number RAM8(test_sound_number_ADDRESS)
#define test_sound_timer_ADDRESS 0x5917u
#define test_sound_timer RAM8(test_sound_timer_ADDRESS)
#define test_print_down_ADDRESS 0x591Au
#define test_print_down RAM8(test_print_down_ADDRESS)
#define test_premium_start_ADDRESS 0x591Bu
#define test_premium_start RAM8(test_premium_start_ADDRESS)
#define test_premium_coins_ADDRESS 0x591Cu
#define test_premium_coins RAM8(test_premium_coins_ADDRESS)
#define coin_setting_ADDRESS 0x59F1u
#define coin_setting RAM8(coin_setting_ADDRESS)
#define difficulty_option_ADDRESS 0x59F4u
#define difficulty_option RAM8(difficulty_option_ADDRESS)
#define lives_option_ADDRESS 0x59F5u
#define lives_option RAM8(lives_option_ADDRESS)
#define attract_sound_option_ADDRESS 0x59F6u
#define attract_sound_option RAM8(attract_sound_option_ADDRESS)
#define screen_flip_option_ADDRESS 0x59F7u
#define screen_flip_option RAM8(screen_flip_option_ADDRESS)
#define coin_slots_setting_ADDRESS 0x59F8u
#define coin_slots_setting RAM8(coin_slots_setting_ADDRESS)
#define sound_output_option_ADDRESS 0x59F9u
#define sound_output_option RAM8(sound_output_option_ADDRESS)
#define first_credit_coins_option_ADDRESS 0x59FAu
#define first_credit_coins_option RAM8(first_credit_coins_option_ADDRESS)
#define eeprom_address_ADDRESS 0x5A00u
#define eeprom_address RAM8(eeprom_address_ADDRESS)
#define eeprom_data_ADDRESS 0x5A01u
#define eeprom_data RAM8(eeprom_data_ADDRESS)
#define eeprom_read_data_ADDRESS 0x5A02u
#define eeprom_read_data RAM8(eeprom_read_data_ADDRESS)
#define rom_check_step_ADDRESS 0x5A10u
#define rom_check_step RAM8(rom_check_step_ADDRESS)
#define rom_check_chip_ADDRESS 0x5A11u
#define rom_check_chip RAM8(rom_check_chip_ADDRESS)
#define rom_check_tile_sums_ADDRESS 0x5A12u
#define rom_check_tile_sums(index) RAM16(rom_check_tile_sums_ADDRESS + (index) * 2u)
#define rom_check_line_ADDRESS 0x5A1Au
#define rom_check_line RAM8(rom_check_line_ADDRESS)
#define rom_check_no_sound_cpu_ADDRESS 0x5A1Bu
#define rom_check_no_sound_cpu RAM8(rom_check_no_sound_cpu_ADDRESS)
#define ram_test_start_ADDRESS 0x5D00u
#define ram_test_start RAM16(ram_test_start_ADDRESS)
#define check_failed_ADDRESS 0x5D02u
#define check_failed RAM8(check_failed_ADDRESS)
#define check_11f_ADDRESS 0x5D03u
#define check_11f RAM8(check_11f_ADDRESS)
#define check_1j_ADDRESS 0x5D04u
#define check_1j RAM8(check_1j_ADDRESS)
#define check_16g_ADDRESS 0x5D05u
#define check_16g RAM8(check_16g_ADDRESS)
#define check_16f_ADDRESS 0x5D06u
#define check_16f RAM8(check_16f_ADDRESS)
#define check_9g_ADDRESS 0x5D07u
#define check_9g RAM8(check_9g_ADDRESS)
#define check_8g_ADDRESS 0x5D08u
#define check_8g RAM8(check_8g_ADDRESS)
#define check_12c_ADDRESS 0x5D09u
#define check_12c RAM8(check_12c_ADDRESS)

/* work RAM as one family of functions uses it */
#define rom_sum_ADDRESS 0x48FAu
#define rom_sum RAM16(rom_sum_ADDRESS)
#define rom_sum_ADDRESS 0x48FAu
#define rom_sum RAM16(rom_sum_ADDRESS)
#define profile_letter_colour_ADDRESS 0x48F0u
#define profile_letter_colour RAM8(profile_letter_colour_ADDRESS)
#define profile_letter_place_ADDRESS 0x48F1u
#define profile_letter_place RAM16(profile_letter_place_ADDRESS)
#define profile_count_address_ADDRESS 0x48F3u
#define profile_count_address RAM16(profile_count_address_ADDRESS)
#define points_objects_left_ADDRESS 0x48F0u
#define points_objects_left RAM8(points_objects_left_ADDRESS)
#define enemy_points_ADDRESS 0x48F1u
#define enemy_points RAM8(enemy_points_ADDRESS)
#define boulder_bounce_speed_ADDRESS 0x48F3u
#define boulder_bounce_speed RAM16S(boulder_bounce_speed_ADDRESS)
#define cage_parts_left_ADDRESS 0x48F0u
#define cage_parts_left RAM8(cage_parts_left_ADDRESS)
#define cage_part_number_ADDRESS 0x48F1u
#define cage_part_number RAM8(cage_part_number_ADDRESS)
#define cage_part_offsets_ADDRESS 0x48F8u
#define cage_part_offsets RAM16(cage_part_offsets_ADDRESS)
#define cage_parts_left_ADDRESS 0x48F0u
#define cage_parts_left RAM8(cage_parts_left_ADDRESS)
#define cage_part_number_ADDRESS 0x48F1u
#define cage_part_number RAM8(cage_part_number_ADDRESS)
#define cage_part_offsets_ADDRESS 0x48F8u
#define cage_part_offsets RAM16(cage_part_offsets_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define blank_width_ADDRESS 0x48E8u
#define blank_width RAM8(blank_width_ADDRESS)
#define blank_columns_left_ADDRESS 0x48E9u
#define blank_columns_left RAM8(blank_columns_left_ADDRESS)
#define blank_rows_left_ADDRESS 0x48EAu
#define blank_rows_left RAM8(blank_rows_left_ADDRESS)
#define blank_player_ADDRESS 0x48EBu
#define blank_player RAM8(blank_player_ADDRESS)
#define balloon_growing_ADDRESS 0x48F2u
#define balloon_growing RAM8(balloon_growing_ADDRESS)
#define blowing_player_ADDRESS 0x48F3u
#define blowing_player RAM8(blowing_player_ADDRESS)
#define blowing_player_number_ADDRESS 0x48F1u
#define blowing_player_number RAM8(blowing_player_number_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define portrait_animation_ADDRESS 0x48F0u
#define portrait_animation RAM8(portrait_animation_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define intro_player_number_ADDRESS 0x48F1u
#define intro_player_number RAM8(intro_player_number_ADDRESS)
#define intro_player_shown_ADDRESS 0x48F2u
#define intro_player_shown RAM8(intro_player_shown_ADDRESS)
#define balloon_player_number_ADDRESS 0x48F0u
#define balloon_player_number RAM8(balloon_player_number_ADDRESS)
#define balloon_part_ADDRESS 0x48F1u
#define balloon_part RAM8(balloon_part_ADDRESS)
#define results_places_ADDRESS 0x48F0u
#define results_places RAM8(results_places_ADDRESS)
#define absent_player_seen_ADDRESS 0x48F0u
#define absent_player_seen RAM8(absent_player_seen_ADDRESS)
#define balloon_growing_ADDRESS 0x48F2u
#define balloon_growing RAM8(balloon_growing_ADDRESS)
#define balloons_growing_ADDRESS 0x48F0u
#define balloons_growing RAM8(balloons_growing_ADDRESS)
#define bonus_2_player_number_ADDRESS 0x48F0u
#define bonus_2_player_number RAM8(bonus_2_player_number_ADDRESS)
#define bonus_2_player_bits_ADDRESS 0x48F1u
#define bonus_2_player_bits RAM8(bonus_2_player_bits_ADDRESS)
#define bonus_2_meter_offset_ADDRESS 0x48F2u
#define bonus_2_meter_offset RAM8S(bonus_2_meter_offset_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define bonus_2_move_amount_ADDRESS 0x48F8u
#define bonus_2_move_amount RAM16(bonus_2_move_amount_ADDRESS)
#define bonus_2_player_number_ADDRESS 0x48F0u
#define bonus_2_player_number RAM8(bonus_2_player_number_ADDRESS)
#define bonus_2_player_bit_ADDRESS 0x48F1u
#define bonus_2_player_bit RAM8(bonus_2_player_bit_ADDRESS)
#define bonus_2_meter_offset_ADDRESS 0x48F2u
#define bonus_2_meter_offset RAM8S(bonus_2_meter_offset_ADDRESS)
#define bonus_2_player_variables_ADDRESS 0x48F8u
#define bonus_2_player_variables RAM16(bonus_2_player_variables_ADDRESS)
#define portrait_animation_ADDRESS 0x48F0u
#define portrait_animation RAM8(portrait_animation_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define first_player_slots_left_ADDRESS 0x48F0u
#define first_player_slots_left RAM8(first_player_slots_left_ADDRESS)
#define results_number_ADDRESS 0x48F0u
#define results_number RAM8(results_number_ADDRESS)
#define results_typed_boxes_left_ADDRESS 0x48F1u
#define results_typed_boxes_left RAM8(results_typed_boxes_left_ADDRESS)
#define results_boxes_left_ADDRESS 0x48F0u
#define results_boxes_left RAM8(results_boxes_left_ADDRESS)
#define results_counts_done_ADDRESS 0x48F1u
#define results_counts_done RAM8(results_counts_done_ADDRESS)
#define results_print_place_ADDRESS 0x48F8u
#define results_print_place RAM16(results_print_place_ADDRESS)
#define placed_count_ADDRESS 0x48F0u
#define placed_count RAM8(placed_count_ADDRESS)
#define placed_result_ADDRESS 0x48F1u
#define placed_result RAM8(placed_result_ADDRESS)
#define placed_sign_ADDRESS 0x48F8u
#define placed_sign RAM16(placed_sign_ADDRESS)
#define results_print_place_ADDRESS 0x48F8u
#define results_print_place RAM16(results_print_place_ADDRESS)
#define results_marge_place_ADDRESS 0x48F0u
#define results_marge_place RAM8(results_marge_place_ADDRESS)
#define results_homer_place_ADDRESS 0x48F1u
#define results_homer_place RAM8(results_homer_place_ADDRESS)
#define results_bart_place_ADDRESS 0x48F2u
#define results_bart_place RAM8(results_bart_place_ADDRESS)
#define results_lisa_place_ADDRESS 0x48F3u
#define results_lisa_place RAM8(results_lisa_place_ADDRESS)
#define results_boxes_left_ADDRESS 0x48F0u
#define results_boxes_left RAM8(results_boxes_left_ADDRESS)
#define results_print_place_ADDRESS 0x48F8u
#define results_print_place RAM16(results_print_place_ADDRESS)
#define results_number_ADDRESS 0x48F0u
#define results_number RAM8(results_number_ADDRESS)
#define results_print_place_ADDRESS 0x48F8u
#define results_print_place RAM16(results_print_place_ADDRESS)
#define portrait_animation_ADDRESS 0x48F0u
#define portrait_animation RAM8(portrait_animation_ADDRESS)
#define bonus_portrait_player_ADDRESS 0x48F1u
#define bonus_portrait_player RAM8(bonus_portrait_player_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define shade_arguments_ADDRESS 0x48E8u
#define shade_arguments RAM16(shade_arguments_ADDRESS)
#define shade_vitality_step_ADDRESS 0x48E8u
#define shade_vitality_step RAM8(shade_vitality_step_ADDRESS)
#define shade_effect_row_ADDRESS 0x48E9u
#define shade_effect_row RAM8(shade_effect_row_ADDRESS)
#define shade_new_level_ADDRESS 0x48EAu
#define shade_new_level RAM8(shade_new_level_ADDRESS)
#define shade_vitality_over_ADDRESS 0x48EEu
#define shade_vitality_over RAM8(shade_vitality_over_ADDRESS)
#define box_x_offset_ADDRESS 0x48F4u
#define box_x_offset RAM16S(box_x_offset_ADDRESS)
#define box_distance_ADDRESS 0x48F6u
#define box_distance RAM16(box_distance_ADDRESS)
#define fade_steps_ADDRESS 0x48E8u
#define fade_steps RAM16(fade_steps_ADDRESS)
#define fade_steps_high_ADDRESS 0x48E8u
#define fade_steps_high RAM8(fade_steps_high_ADDRESS)
#define fade_steps_low_ADDRESS 0x48E9u
#define fade_steps_low RAM8(fade_steps_low_ADDRESS)
#define fade_colour_ADDRESS 0x48EAu
#define fade_colour RAM16(fade_colour_ADDRESS)
#define fade_colour_high_ADDRESS 0x48EAu
#define fade_colour_high RAM8(fade_colour_high_ADDRESS)
#define fade_colour_low_ADDRESS 0x48EBu
#define fade_colour_low RAM8(fade_colour_low_ADDRESS)
#define wall_rows_left_ADDRESS 0x48F0u
#define wall_rows_left RAM8(wall_rows_left_ADDRESS)
#define wall_tiles_left_ADDRESS 0x48F1u
#define wall_tiles_left RAM8(wall_tiles_left_ADDRESS)
#define held_part_dx_ADDRESS 0x48F0u
#define held_part_dx RAM16S(held_part_dx_ADDRESS)
#define chosen_attack_ADDRESS 0x48F0u
#define chosen_attack RAM8(chosen_attack_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define shot_speed_ADDRESS 0x48F0u
#define shot_speed RAM16S(shot_speed_ADDRESS)
#define lob_speed_ADDRESS 0x48F2u
#define lob_speed RAM16S(lob_speed_ADDRESS)
#define placed_part_number_ADDRESS 0x48E8u
#define placed_part_number RAM8(placed_part_number_ADDRESS)
#define part_dx_ADDRESS 0x48EAu
#define part_dx RAM16S(part_dx_ADDRESS)
#define part_dx_low_ADDRESS 0x48EBu
#define part_dx_low RAM8(part_dx_low_ADDRESS)
#define wall_probe_dx_ADDRESS 0x48F0u
#define wall_probe_dx RAM16S(wall_probe_dx_ADDRESS)
#define floor_probe_dx_ADDRESS 0x48F8u
#define floor_probe_dx RAM16S(floor_probe_dx_ADDRESS)
#define floor_probe_dy_ADDRESS 0x48FAu
#define floor_probe_dy RAM16S(floor_probe_dy_ADDRESS)
#define chosen_attack_ADDRESS 0x48F0u
#define chosen_attack RAM8(chosen_attack_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define stagger_speed_ADDRESS 0x48F0u
#define stagger_speed RAM16S(stagger_speed_ADDRESS)
#define camera_scaled_move_ADDRESS 0x48F0u
#define camera_scaled_move RAM16S(camera_scaled_move_ADDRESS)
#define layer_move_x_ADDRESS 0x48F2u
#define layer_move_x RAM16S(layer_move_x_ADDRESS)
#define layer_move_y_ADDRESS 0x48F4u
#define layer_move_y RAM16S(layer_move_y_ADDRESS)
#define camera_entry_advance_ADDRESS 0x48FEu
#define camera_entry_advance RAM8(camera_entry_advance_ADDRESS)
#define land_at_height_ADDRESS 0x48E8u
#define land_at_height RAM16(land_at_height_ADDRESS)
#define thrown_cell_here_ADDRESS 0x48F0u
#define thrown_cell_here RAM8(thrown_cell_here_ADDRESS)
#define thrown_cell_ahead_ADDRESS 0x48F1u
#define thrown_cell_ahead RAM8(thrown_cell_ahead_ADDRESS)
#define thrown_cell_priority_ADDRESS 0x48F2u
#define thrown_cell_priority RAM8(thrown_cell_priority_ADDRESS)
#define cemetery_floor_rows_left_ADDRESS 0x48F0u
#define cemetery_floor_rows_left RAM8(cemetery_floor_rows_left_ADDRESS)
#define cemetery_floor_cells_left_ADDRESS 0x48F1u
#define cemetery_floor_cells_left RAM8(cemetery_floor_cells_left_ADDRESS)
#define chain_link_dx_ADDRESS 0x48E8u
#define chain_link_dx RAM16S(chain_link_dx_ADDRESS)
#define chain_link_dx_high_ADDRESS 0x48E8u
#define chain_link_dx_high RAM8(chain_link_dx_high_ADDRESS)
#define chain_link_dx_low_ADDRESS 0x48E9u
#define chain_link_dx_low RAM8(chain_link_dx_low_ADDRESS)
#define chain_link_dz_ADDRESS 0x48EAu
#define chain_link_dz RAM16S(chain_link_dz_ADDRESS)
#define chain_link_dz_high_ADDRESS 0x48EAu
#define chain_link_dz_high RAM8(chain_link_dz_high_ADDRESS)
#define chain_link_dz_low_ADDRESS 0x48EBu
#define chain_link_dz_low RAM8(chain_link_dz_low_ADDRESS)
#define chain_direction_and_distance_ADDRESS 0x48ECu
#define chain_direction_and_distance RAM16(chain_direction_and_distance_ADDRESS)
#define chain_direction_ADDRESS 0x48ECu
#define chain_direction RAM8(chain_direction_ADDRESS)
#define chain_distance_ADDRESS 0x48EDu
#define chain_distance RAM8(chain_distance_ADDRESS)
#define chain_quarter_direction_ADDRESS 0x48EFu
#define chain_quarter_direction RAM8(chain_quarter_direction_ADDRESS)
#define scenery_floor_column_ADDRESS 0x48F0u
#define scenery_floor_column RAM8(scenery_floor_column_ADDRESS)
#define floor_cell_here_ADDRESS 0x48F0u
#define floor_cell_here RAM8(floor_cell_here_ADDRESS)
#define floor_cell_ahead_ADDRESS 0x48F1u
#define floor_cell_ahead RAM8(floor_cell_ahead_ADDRESS)
#define floor_cell_probe_ADDRESS 0x48F2u
#define floor_cell_probe RAM8(floor_cell_probe_ADDRESS)
#define hit_check_enemies_left_ADDRESS 0x48F1u
#define hit_check_enemies_left RAM8(hit_check_enemies_left_ADDRESS)
#define skip_player_ADDRESS 0x48F0u
#define skip_player RAM8(skip_player_ADDRESS)
#define cleared_objects_left_ADDRESS 0x48E8u
#define cleared_objects_left RAM8(cleared_objects_left_ADDRESS)
#define cleared_object_words_left_ADDRESS 0x48E9u
#define cleared_object_words_left RAM8(cleared_object_words_left_ADDRESS)
#define cleared_objects_left_ADDRESS 0x48E8u
#define cleared_objects_left RAM8(cleared_objects_left_ADDRESS)
#define cleared_object_words_left_ADDRESS 0x48E9u
#define cleared_object_words_left RAM8(cleared_object_words_left_ADDRESS)
#define cleared_objects_left_ADDRESS 0x48E8u
#define cleared_objects_left RAM8(cleared_objects_left_ADDRESS)
#define cleared_object_words_left_ADDRESS 0x48E9u
#define cleared_object_words_left RAM8(cleared_object_words_left_ADDRESS)
#define clear_slots_left_ADDRESS 0x48E8u
#define clear_slots_left RAM8(clear_slots_left_ADDRESS)
#define cleared_words_left_ADDRESS 0x48E8u
#define cleared_words_left RAM8(cleared_words_left_ADDRESS)
#define steer_dy_high_ADDRESS 0x48F0u
#define steer_dy_high RAM8S(steer_dy_high_ADDRESS)
#define hit_check_players_left_ADDRESS 0x48F0u
#define hit_check_players_left RAM8(hit_check_players_left_ADDRESS)
#define hit_check_children_left_ADDRESS 0x48F3u
#define hit_check_children_left RAM8(hit_check_children_left_ADDRESS)
#define hit_check_players_left_ADDRESS 0x48F0u
#define hit_check_players_left RAM8(hit_check_players_left_ADDRESS)
#define hit_check_enemies_left_ADDRESS 0x48F1u
#define hit_check_enemies_left RAM8(hit_check_enemies_left_ADDRESS)
#define hit_check_players_left_ADDRESS 0x48F0u
#define hit_check_players_left RAM8(hit_check_players_left_ADDRESS)
#define hit_check_list_1_left_ADDRESS 0x48F2u
#define hit_check_list_1_left RAM8(hit_check_list_1_left_ADDRESS)
#define hit_check_players_left_ADDRESS 0x48F0u
#define hit_check_players_left RAM8(hit_check_players_left_ADDRESS)
#define fade_steps_ADDRESS 0x48E8u
#define fade_steps RAM16(fade_steps_ADDRESS)
#define fade_steps_high_ADDRESS 0x48E8u
#define fade_steps_high RAM8(fade_steps_high_ADDRESS)
#define fade_steps_low_ADDRESS 0x48E9u
#define fade_steps_low RAM8(fade_steps_low_ADDRESS)
#define fade_colour_ADDRESS 0x48EAu
#define fade_colour RAM16(fade_colour_ADDRESS)
#define fade_colour_high_ADDRESS 0x48EAu
#define fade_colour_high RAM8(fade_colour_high_ADDRESS)
#define fade_colour_low_ADDRESS 0x48EBu
#define fade_colour_low RAM8(fade_colour_low_ADDRESS)
#define demo_player_ADDRESS 0x48F0u
#define demo_player RAM8(demo_player_ADDRESS)
#define demo_player_bits_ADDRESS 0x48F1u
#define demo_player_bits RAM8(demo_player_bits_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define direction_dx_ADDRESS 0x48E8u
#define direction_dx RAM16(direction_dx_ADDRESS)
#define direction_dx_high_ADDRESS 0x48E8u
#define direction_dx_high RAM8(direction_dx_high_ADDRESS)
#define direction_dx_low_ADDRESS 0x48E9u
#define direction_dx_low RAM8(direction_dx_low_ADDRESS)
#define direction_dy_ADDRESS 0x48EAu
#define direction_dy RAM16(direction_dy_ADDRESS)
#define direction_dy_high_ADDRESS 0x48EAu
#define direction_dy_high RAM8(direction_dy_high_ADDRESS)
#define direction_dy_low_ADDRESS 0x48EBu
#define direction_dy_low RAM8(direction_dy_low_ADDRESS)
#define direction_dx_sign_ADDRESS 0x48ECu
#define direction_dx_sign RAM8S(direction_dx_sign_ADDRESS)
#define direction_dy_sign_ADDRESS 0x48EDu
#define direction_dy_sign RAM8S(direction_dy_sign_ADDRESS)
#define map_column_blocks_left_ADDRESS 0x48F0u
#define map_column_blocks_left RAM8(map_column_blocks_left_ADDRESS)
#define block_tile_column_ADDRESS 0x48F1u
#define block_tile_column RAM8(block_tile_column_ADDRESS)
#define column_map_cell_ADDRESS 0x48F2u
#define column_map_cell RAM16(column_map_cell_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define block_tile_row_ADDRESS 0x48F0u
#define block_tile_row RAM8(block_tile_row_ADDRESS)
#define map_row_blocks_left_ADDRESS 0x48F1u
#define map_row_blocks_left RAM8(map_row_blocks_left_ADDRESS)
#define map_next_scroll_ADDRESS 0x48F4u
#define map_next_scroll RAM16(map_next_scroll_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define map_strip_step_ADDRESS 0x48FCu
#define map_strip_step RAM16(map_strip_step_ADDRESS)
#define frame_marked_ADDRESS 0x48F1u
#define frame_marked RAM8(frame_marked_ADDRESS)
#define frame_sprites_left_ADDRESS 0x48F2u
#define frame_sprites_left RAM8(frame_sprites_left_ADDRESS)
#define sprite_slot_ADDRESS 0x48F3u
#define sprite_slot RAM8(sprite_slot_ADDRESS)
#define frame_attributes_ADDRESS 0x48F4u
#define frame_attributes RAM8(frame_attributes_ADDRESS)
#define drawn_animation_flags_ADDRESS 0x48F6u
#define drawn_animation_flags RAM8(drawn_animation_flags_ADDRESS)
#define draw_shadow_sprite_ADDRESS 0x48F7u
#define draw_shadow_sprite RAM8(draw_shadow_sprite_ADDRESS)
#define picture_width_ADDRESS 0x48F0u
#define picture_width RAM8(picture_width_ADDRESS)
#define picture_columns_left_ADDRESS 0x48F1u
#define picture_columns_left RAM8(picture_columns_left_ADDRESS)
#define picture_rows_left_ADDRESS 0x48F2u
#define picture_rows_left RAM8(picture_rows_left_ADDRESS)
#define picture_colour_ADDRESS 0x48F3u
#define picture_colour RAM8(picture_colour_ADDRESS)
#define picture_blank_ADDRESS 0x48F4u
#define picture_blank RAM8(picture_blank_ADDRESS)
#define lash_number_ADDRESS 0x48F0u
#define lash_number RAM8(lash_number_ADDRESS)
#define path_distance_ADDRESS 0x48F1u
#define path_distance RAM8(path_distance_ADDRESS)
#define chain_link_dx_ADDRESS 0x48E8u
#define chain_link_dx RAM16S(chain_link_dx_ADDRESS)
#define chain_link_dz_ADDRESS 0x48EAu
#define chain_link_dz RAM16S(chain_link_dz_ADDRESS)
#define chain_head_link_ADDRESS 0x48F2u
#define chain_head_link RAM16(chain_head_link_ADDRESS)
#define chain_pieces_left_ADDRESS 0x48F4u
#define chain_pieces_left RAM8(chain_pieces_left_ADDRESS)
#define chain_offset_biased_ADDRESS 0x48F0u
#define chain_offset_biased RAM16(chain_offset_biased_ADDRESS)
#define land_at_height_ADDRESS 0x48E8u
#define land_at_height RAM16(land_at_height_ADDRESS)
#define eeprom_total_ADDRESS 0x48F0u
#define eeprom_total RAM16(eeprom_total_ADDRESS)
#define eeprom_total_high_ADDRESS 0x48F0u
#define eeprom_total_high RAM8(eeprom_total_high_ADDRESS)
#define eeprom_total_low_ADDRESS 0x48F1u
#define eeprom_total_low RAM8(eeprom_total_low_ADDRESS)
#define eeprom_sum_address_ADDRESS 0x48F2u
#define eeprom_sum_address RAM8(eeprom_sum_address_ADDRESS)
#define eeprom_test_address_ADDRESS 0x48F0u
#define eeprom_test_address RAM8(eeprom_test_address_ADDRESS)
#define players_going_on_ADDRESS 0x48F0u
#define players_going_on RAM8(players_going_on_ADDRESS)
#define target_left_bit_ADDRESS 0x48F0u
#define target_left_bit RAM8(target_left_bit_ADDRESS)
#define nearest_player_distance_ADDRESS 0x48ECu
#define nearest_player_distance RAM16(nearest_player_distance_ADDRESS)
#define previous_target_ADDRESS 0x48F0u
#define previous_target RAM16(previous_target_ADDRESS)
#define grab_facing_ADDRESS 0x48F0u
#define grab_facing RAM8(grab_facing_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define cell_seen_ADDRESS 0x48F1u
#define cell_seen RAM8(cell_seen_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define cell_seen_ADDRESS 0x48F1u
#define cell_seen RAM8(cell_seen_ADDRESS)
#define map_column_blocks_left_ADDRESS 0x48F0u
#define map_column_blocks_left RAM8(map_column_blocks_left_ADDRESS)
#define block_tile_column_ADDRESS 0x48F1u
#define block_tile_column RAM8(block_tile_column_ADDRESS)
#define column_map_cell_ADDRESS 0x48F2u
#define column_map_cell RAM16(column_map_cell_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define floor_map_place_ADDRESS 0x48FAu
#define floor_map_place RAM16(floor_map_place_ADDRESS)
#define block_tile_row_ADDRESS 0x48F0u
#define block_tile_row RAM8(block_tile_row_ADDRESS)
#define map_row_blocks_left_ADDRESS 0x48F1u
#define map_row_blocks_left RAM8(map_row_blocks_left_ADDRESS)
#define map_next_scroll_ADDRESS 0x48F4u
#define map_next_scroll RAM16(map_next_scroll_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define floor_map_place_ADDRESS 0x48FAu
#define floor_map_place RAM16(floor_map_place_ADDRESS)
#define map_strip_step_ADDRESS 0x48FCu
#define map_strip_step RAM16(map_strip_step_ADDRESS)
#define free_slot_sprites_ADDRESS 0x48E8u
#define free_slot_sprites RAM16(free_slot_sprites_ADDRESS)
#define map_block_ADDRESS 0x48FEu
#define map_block RAM16(map_block_ADDRESS)
#define map_block_ADDRESS 0x48FEu
#define map_block RAM16(map_block_ADDRESS)
#define map_layer_ADDRESS 0x48E8u
#define map_layer RAM8(map_layer_ADDRESS)
#define map_place_offset_ADDRESS 0x48F0u
#define map_place_offset RAM16(map_place_offset_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define floor_map_place_ADDRESS 0x48FAu
#define floor_map_place RAM16(floor_map_place_ADDRESS)
#define map_column_cell_ADDRESS 0x48FCu
#define map_column_cell RAM16(map_column_cell_ADDRESS)
#define map_layer_ADDRESS 0x48E8u
#define map_layer RAM8(map_layer_ADDRESS)
#define map_place_offset_ADDRESS 0x48F0u
#define map_place_offset RAM16(map_place_offset_ADDRESS)
#define map_draw_scroll_ADDRESS 0x48F8u
#define map_draw_scroll RAM16(map_draw_scroll_ADDRESS)
#define floor_map_place_ADDRESS 0x48FAu
#define floor_map_place RAM16(floor_map_place_ADDRESS)
#define map_strip_step_ADDRESS 0x48FCu
#define map_strip_step RAM16(map_strip_step_ADDRESS)
#define map_layer_ADDRESS 0x48E8u
#define map_layer RAM8(map_layer_ADDRESS)
#define map_block_ADDRESS 0x48FEu
#define map_block RAM16(map_block_ADDRESS)
#define nearest_player_distance_ADDRESS 0x48ECu
#define nearest_player_distance RAM16(nearest_player_distance_ADDRESS)
#define nearest_player_distance_high_ADDRESS 0x48ECu
#define nearest_player_distance_high RAM8(nearest_player_distance_high_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define floor_offset_x_ADDRESS 0x48E9u
#define floor_offset_x RAM16S(floor_offset_x_ADDRESS)
#define floor_offset_x_pixels_ADDRESS 0x48E9u
#define floor_offset_x_pixels RAM8S(floor_offset_x_pixels_ADDRESS)
#define floor_offset_x_fraction_ADDRESS 0x48EAu
#define floor_offset_x_fraction RAM8(floor_offset_x_fraction_ADDRESS)
#define floor_offset_y_ADDRESS 0x48EDu
#define floor_offset_y RAM16S(floor_offset_y_ADDRESS)
#define floor_offset_y_pixels_ADDRESS 0x48EDu
#define floor_offset_y_pixels RAM8S(floor_offset_y_pixels_ADDRESS)
#define floor_offset_y_fraction_ADDRESS 0x48EEu
#define floor_offset_y_fraction RAM8(floor_offset_y_fraction_ADDRESS)
#define floor_probe_dx_ADDRESS 0x48F8u
#define floor_probe_dx RAM16S(floor_probe_dx_ADDRESS)
#define floor_probe_dy_ADDRESS 0x48FAu
#define floor_probe_dy RAM16S(floor_probe_dy_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define floor_cell_column_ADDRESS 0x48E8u
#define floor_cell_column RAM16(floor_cell_column_ADDRESS)
#define floor_offset_x_sign_ADDRESS 0x48E8u
#define floor_offset_x_sign RAM8(floor_offset_x_sign_ADDRESS)
#define floor_offset_x_ADDRESS 0x48E9u
#define floor_offset_x RAM16S(floor_offset_x_ADDRESS)
#define floor_cell_column_low_ADDRESS 0x48E9u
#define floor_cell_column_low RAM8(floor_cell_column_low_ADDRESS)
#define floor_place_y_ADDRESS 0x48ECu
#define floor_place_y RAM16(floor_place_y_ADDRESS)
#define floor_offset_y_sign_ADDRESS 0x48ECu
#define floor_offset_y_sign RAM8(floor_offset_y_sign_ADDRESS)
#define floor_offset_y_ADDRESS 0x48EDu
#define floor_offset_y RAM16S(floor_offset_y_ADDRESS)
#define steer_dy_high_ADDRESS 0x48F0u
#define steer_dy_high RAM8S(steer_dy_high_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define players_share_ADDRESS 0x48F0u
#define players_share RAM8(players_share_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define players_share_ADDRESS 0x48F0u
#define players_share RAM8(players_share_ADDRESS)
#define finish_scores_left_ADDRESS 0x48F0u
#define finish_scores_left RAM8(finish_scores_left_ADDRESS)
#define portrait_number_ADDRESS 0x48F0u
#define portrait_number RAM8(portrait_number_ADDRESS)
#define portrait_columns_left_ADDRESS 0x48F1u
#define portrait_columns_left RAM8(portrait_columns_left_ADDRESS)
#define portrait_rows_left_ADDRESS 0x48F2u
#define portrait_rows_left RAM8(portrait_rows_left_ADDRESS)
#define join_bit_or_slots_ADDRESS 0x48F0u
#define join_bit_or_slots RAM8(join_bit_or_slots_ADDRESS)
#define join_slot_bit_ADDRESS 0x48F1u
#define join_slot_bit RAM8(join_slot_bit_ADDRESS)
#define portrait_player_bit_ADDRESS 0x48F0u
#define portrait_player_bit RAM8(portrait_player_bit_ADDRESS)
#define portrait_players_left_ADDRESS 0x48F1u
#define portrait_players_left RAM8(portrait_players_left_ADDRESS)
#define portrait_player_bit_ADDRESS 0x48F0u
#define portrait_player_bit RAM8(portrait_player_bit_ADDRESS)
#define hit_damage_ADDRESS 0x48E8u
#define hit_damage RAM8(hit_damage_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define cell_seen_ADDRESS 0x48F1u
#define cell_seen RAM8(cell_seen_ADDRESS)
#define grab_facing_ADDRESS 0x48F0u
#define grab_facing RAM8(grab_facing_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define cell_seen_ADDRESS 0x48F1u
#define cell_seen RAM8(cell_seen_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define cell_seen_ADDRESS 0x48F1u
#define cell_seen RAM8(cell_seen_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define points_player_bits_ADDRESS 0x48F0u
#define points_player_bits RAM8(points_player_bits_ADDRESS)
#define ranked_score_ADDRESS 0x48E8u
#define ranked_score RAM16(ranked_score_ADDRESS)
#define high_score_place_found_ADDRESS 0x48EAu
#define high_score_place_found RAM8(high_score_place_found_ADDRESS)
#define table_place_ADDRESS 0x48F0u
#define table_place RAM8(table_place_ADDRESS)
#define table_entries_left_ADDRESS 0x48F1u
#define table_entries_left RAM8(table_entries_left_ADDRESS)
#define table_characters_left_ADDRESS 0x48F2u
#define table_characters_left RAM8(table_characters_left_ADDRESS)
#define table_digit_shown_ADDRESS 0x48F3u
#define table_digit_shown RAM8(table_digit_shown_ADDRESS)
#define sprite_text_x_ADDRESS 0x48F8u
#define sprite_text_x RAM16(sprite_text_x_ADDRESS)
#define sprite_text_y_ADDRESS 0x48FAu
#define sprite_text_y RAM16(sprite_text_y_ADDRESS)
#define wave_lines_left_ADDRESS 0x48F0u
#define wave_lines_left RAM8(wave_lines_left_ADDRESS)
#define table_wave_offset_ADDRESS 0x48F1u
#define table_wave_offset RAM8(table_wave_offset_ADDRESS)
#define new_high_score_place_ADDRESS 0x48E8u
#define new_high_score_place RAM8(new_high_score_place_ADDRESS)
#define high_score_moved_place_ADDRESS 0x48E9u
#define high_score_moved_place RAM8(high_score_moved_place_ADDRESS)
#define high_score_words_left_ADDRESS 0x48EAu
#define high_score_words_left RAM8(high_score_words_left_ADDRESS)
#define new_high_score_ADDRESS 0x48F0u
#define new_high_score RAM16(new_high_score_ADDRESS)
#define area_next_x_high_ADDRESS 0x48F0u
#define area_next_x_high RAM8(area_next_x_high_ADDRESS)
#define area_next_x_ADDRESS 0x48F1u
#define area_next_x RAM16(area_next_x_ADDRESS)
#define area_next_x_pixels_ADDRESS 0x48F1u
#define area_next_x_pixels RAM8(area_next_x_pixels_ADDRESS)
#define area_next_y_high_ADDRESS 0x48F0u
#define area_next_y_high RAM8(area_next_y_high_ADDRESS)
#define area_next_y_ADDRESS 0x48F1u
#define area_next_y RAM16(area_next_y_ADDRESS)
#define area_next_y_pixels_ADDRESS 0x48F1u
#define area_next_y_pixels RAM8(area_next_y_pixels_ADDRESS)
#define layer_move_x_ADDRESS 0x48F2u
#define layer_move_x RAM16S(layer_move_x_ADDRESS)
#define layer_move_x_high_ADDRESS 0x48F2u
#define layer_move_x_high RAM8S(layer_move_x_high_ADDRESS)
#define layer_move_y_ADDRESS 0x48F4u
#define layer_move_y RAM16S(layer_move_y_ADDRESS)
#define layer_move_y_high_ADDRESS 0x48F4u
#define layer_move_y_high RAM8S(layer_move_y_high_ADDRESS)
#define palettes_to_load_ADDRESS 0x48E8u
#define palettes_to_load RAM8(palettes_to_load_ADDRESS)
#define palette_colours_left_ADDRESS 0x48E9u
#define palette_colours_left RAM8(palette_colours_left_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define scenery_floor_column_ADDRESS 0x48F0u
#define scenery_floor_column RAM8(scenery_floor_column_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define camera_move_x_ADDRESS 0x48F0u
#define camera_move_x RAM16S(camera_move_x_ADDRESS)
#define camera_move_y_ADDRESS 0x48F2u
#define camera_move_y RAM16S(camera_move_y_ADDRESS)
#define move_slots_left_ADDRESS 0x48F6u
#define move_slots_left RAM8(move_slots_left_ADDRESS)
#define sprite_move_ADDRESS 0x48FCu
#define sprite_move RAM16S(sprite_move_ADDRESS)
#define shadow_move_y_ADDRESS 0x48FEu
#define shadow_move_y RAM16S(shadow_move_y_ADDRESS)
#define initials_left_ADDRESS 0x48F1u
#define initials_left RAM8(initials_left_ADDRESS)
#define sprite_text_x_ADDRESS 0x48F8u
#define sprite_text_x RAM16(sprite_text_x_ADDRESS)
#define entry_player_record_ADDRESS 0x48FCu
#define entry_player_record RAM16(entry_player_record_ADDRESS)
#define rank_place_ADDRESS 0x48E8u
#define rank_place RAM8(rank_place_ADDRESS)
#define rank_other_place_ADDRESS 0x48E9u
#define rank_other_place RAM8(rank_other_place_ADDRESS)
#define rank_other_score_ADDRESS 0x48EAu
#define rank_other_score RAM16(rank_other_score_ADDRESS)
#define new_high_score_ADDRESS 0x48F0u
#define new_high_score RAM16(new_high_score_ADDRESS)
#define new_high_score_initial_1_ADDRESS 0x48F0u
#define new_high_score_initial_1 RAM8(new_high_score_initial_1_ADDRESS)
#define new_high_score_initial_2_ADDRESS 0x48F1u
#define new_high_score_initial_2 RAM8(new_high_score_initial_2_ADDRESS)
#define new_high_score_initial_3_ADDRESS 0x48F2u
#define new_high_score_initial_3 RAM8(new_high_score_initial_3_ADDRESS)
#define new_high_score_points_ADDRESS 0x48F3u
#define new_high_score_points RAM16(new_high_score_points_ADDRESS)
#define new_high_score_player_ADDRESS 0x48F5u
#define new_high_score_player RAM8(new_high_score_player_ADDRESS)
#define entry_player_ADDRESS 0x48F0u
#define entry_player RAM8(entry_player_ADDRESS)
#define entry_digit_state_ADDRESS 0x48F1u
#define entry_digit_state RAM8(entry_digit_state_ADDRESS)
#define maggie_x_offset_ADDRESS 0x48F2u
#define maggie_x_offset RAM16(maggie_x_offset_ADDRESS)
#define players_ranked_ADDRESS 0x48F4u
#define players_ranked RAM8(players_ranked_ADDRESS)
#define sprite_text_x_ADDRESS 0x48F8u
#define sprite_text_x RAM16(sprite_text_x_ADDRESS)
#define sprite_text_y_ADDRESS 0x48FAu
#define sprite_text_y RAM16(sprite_text_y_ADDRESS)
#define entry_player_record_ADDRESS 0x48FCu
#define entry_player_record RAM16(entry_player_record_ADDRESS)
#define entry_score_ADDRESS 0x48FEu
#define entry_score RAM16(entry_score_ADDRESS)
#define entry_player_ADDRESS 0x48F0u
#define entry_player RAM8(entry_player_ADDRESS)
#define sprite_text_x_ADDRESS 0x48F8u
#define sprite_text_x RAM16(sprite_text_x_ADDRESS)
#define sprite_text_y_ADDRESS 0x48FAu
#define sprite_text_y RAM16(sprite_text_y_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define floor_raise_steps_ADDRESS 0x48F5u
#define floor_raise_steps RAM8(floor_raise_steps_ADDRESS)
#define rebound_x_speed_high_ADDRESS 0x48F0u
#define rebound_x_speed_high RAM8S(rebound_x_speed_high_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define points_player_bits_ADDRESS 0x48F0u
#define points_player_bits RAM8(points_player_bits_ADDRESS)
#define orbit_x_offset_ADDRESS 0x48E8u
#define orbit_x_offset RAM16S(orbit_x_offset_ADDRESS)
#define orbit_x_offset_high_ADDRESS 0x48E8u
#define orbit_x_offset_high RAM8(orbit_x_offset_high_ADDRESS)
#define orbit_x_offset_low_ADDRESS 0x48E9u
#define orbit_x_offset_low RAM8(orbit_x_offset_low_ADDRESS)
#define orbit_y_offset_ADDRESS 0x48EAu
#define orbit_y_offset RAM16S(orbit_y_offset_ADDRESS)
#define orbit_y_offset_high_ADDRESS 0x48EAu
#define orbit_y_offset_high RAM8(orbit_y_offset_high_ADDRESS)
#define orbit_y_offset_low_ADDRESS 0x48EBu
#define orbit_y_offset_low RAM8(orbit_y_offset_low_ADDRESS)
#define orbit_angle_and_radius_ADDRESS 0x48ECu
#define orbit_angle_and_radius RAM16(orbit_angle_and_radius_ADDRESS)
#define orbit_angle_ADDRESS 0x48ECu
#define orbit_angle RAM8(orbit_angle_ADDRESS)
#define orbit_radius_ADDRESS 0x48EDu
#define orbit_radius RAM8(orbit_radius_ADDRESS)
#define orbit_quarter_angle_ADDRESS 0x48EFu
#define orbit_quarter_angle RAM8(orbit_quarter_angle_ADDRESS)
#define palette_effect_colours_left_ADDRESS 0x48F0u
#define palette_effect_colours_left RAM8(palette_effect_colours_left_ADDRESS)
#define palette_fade_brightens_ADDRESS 0x48F0u
#define palette_fade_brightens RAM8(palette_fade_brightens_ADDRESS)
#define palette_fade_colours_left_ADDRESS 0x48F1u
#define palette_fade_colours_left RAM8(palette_fade_colours_left_ADDRESS)
#define palette_clear_range_ADDRESS 0x48F0u
#define palette_clear_range RAM8(palette_clear_range_ADDRESS)
#define palette_clear_bits_ADDRESS 0x48F1u
#define palette_clear_bits RAM8(palette_clear_bits_ADDRESS)
#define palette_loads_wanted_ADDRESS 0x48F0u
#define palette_loads_wanted RAM8(palette_loads_wanted_ADDRESS)
#define palette_loads_left_ADDRESS 0x48F1u
#define palette_loads_left RAM8(palette_loads_left_ADDRESS)
#define child_dx_ADDRESS 0x48E8u
#define child_dx RAM16S(child_dx_ADDRESS)
#define scenery_floor_column_ADDRESS 0x48F0u
#define scenery_floor_column RAM8(scenery_floor_column_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define team_animation_base_ADDRESS 0x48F2u
#define team_animation_base RAM8(team_animation_base_ADDRESS)
#define player_floor_priority_ADDRESS 0x48F2u
#define player_floor_priority RAM8(player_floor_priority_ADDRESS)
#define player_x_limit_ADDRESS 0x48F8u
#define player_x_limit RAM16(player_x_limit_ADDRESS)
#define edge_floor_priority_ADDRESS 0x48F0u
#define edge_floor_priority RAM8(edge_floor_priority_ADDRESS)
#define screen_left_edge_ADDRESS 0x48F8u
#define screen_left_edge RAM16(screen_left_edge_ADDRESS)
#define screen_right_edge_ADDRESS 0x48FAu
#define screen_right_edge RAM16(screen_right_edge_ADDRESS)
#define entry_places_left_ADDRESS 0x48F2u
#define entry_places_left RAM8(entry_places_left_ADDRESS)
#define entry_floor_height_ADDRESS 0x48F3u
#define entry_floor_height RAM8S(entry_floor_height_ADDRESS)
#define player_floor_priority_ADDRESS 0x48F2u
#define player_floor_priority RAM8(player_floor_priority_ADDRESS)
#define new_high_score_ADDRESS 0x48F0u
#define new_high_score RAM16(new_high_score_ADDRESS)
#define new_high_score_initial_1_ADDRESS 0x48F0u
#define new_high_score_initial_1 RAM8(new_high_score_initial_1_ADDRESS)
#define new_high_score_initial_2_ADDRESS 0x48F1u
#define new_high_score_initial_2 RAM8(new_high_score_initial_2_ADDRESS)
#define new_high_score_initial_3_ADDRESS 0x48F2u
#define new_high_score_initial_3 RAM8(new_high_score_initial_3_ADDRESS)
#define new_high_score_points_ADDRESS 0x48F3u
#define new_high_score_points RAM16(new_high_score_points_ADDRESS)
#define new_high_score_player_ADDRESS 0x48F5u
#define new_high_score_player RAM8(new_high_score_player_ADDRESS)
#define z_speed_sign_ADDRESS 0x48F2u
#define z_speed_sign RAM8S(z_speed_sign_ADDRESS)
#define entry_tries_left_ADDRESS 0x48F1u
#define entry_tries_left RAM8(entry_tries_left_ADDRESS)
#define entry_floor_height_ADDRESS 0x48F3u
#define entry_floor_height RAM8S(entry_floor_height_ADDRESS)
#define team_animation_base_ADDRESS 0x48F2u
#define team_animation_base RAM8(team_animation_base_ADDRESS)
#define team_attack_pressed_ADDRESS 0x48F0u
#define team_attack_pressed RAM8(team_attack_pressed_ADDRESS)
#define team_animation_base_ADDRESS 0x48F2u
#define team_animation_base RAM8(team_animation_base_ADDRESS)
#define team_animation_base_ADDRESS 0x48F2u
#define team_animation_base RAM8(team_animation_base_ADDRESS)
#define walk_facing_ADDRESS 0x48F3u
#define walk_facing RAM8(walk_facing_ADDRESS)
#define second_sprites_left_ADDRESS 0x48F0u
#define second_sprites_left RAM8(second_sprites_left_ADDRESS)
#define shown_player_ADDRESS 0x48F0u
#define shown_player RAM8(shown_player_ADDRESS)
#define shown_player_bit_ADDRESS 0x48F1u
#define shown_player_bit RAM8(shown_player_bit_ADDRESS)
#define result_letters_left_ADDRESS 0x48F0u
#define result_letters_left RAM8(result_letters_left_ADDRESS)
#define game_text_colour_ADDRESS 0x48E8u
#define game_text_colour RAM8(game_text_colour_ADDRESS)
#define hex_colour_ADDRESS 0x48F0u
#define hex_colour RAM8(hex_colour_ADDRESS)
#define hex_colour_ADDRESS 0x48F0u
#define hex_colour RAM8(hex_colour_ADDRESS)
#define rom_sum_ADDRESS 0x48FAu
#define rom_sum RAM16(rom_sum_ADDRESS)
#define sprite_text_code_ADDRESS 0x48E8u
#define sprite_text_code RAM16(sprite_text_code_ADDRESS)
#define sprite_text_code_ADDRESS 0x48E8u
#define sprite_text_code RAM16(sprite_text_code_ADDRESS)
#define sprite_text_x_ADDRESS 0x48F8u
#define sprite_text_x RAM16(sprite_text_x_ADDRESS)
#define sprite_text_y_ADDRESS 0x48FAu
#define sprite_text_y RAM16(sprite_text_y_ADDRESS)
#define check_wait_loops_ADDRESS 0x48F2u
#define check_wait_loops RAM8(check_wait_loops_ADDRESS)
#define rom_sum_ADDRESS 0x48FAu
#define rom_sum RAM16(rom_sum_ADDRESS)
#define palette_request_word_ADDRESS 0x48E8u
#define palette_request_word RAM16(palette_request_word_ADDRESS)
#define palette_request_bits_ADDRESS 0x48E8u
#define palette_request_bits RAM8(palette_request_bits_ADDRESS)
#define palette_request_argument_ADDRESS 0x48E9u
#define palette_request_argument RAM8(palette_request_argument_ADDRESS)
#define palette_request_saved_bank_ADDRESS 0x48EAu
#define palette_request_saved_bank RAM8(palette_request_saved_bank_ADDRESS)
#define palette_request_word_ADDRESS 0x48E8u
#define palette_request_word RAM16(palette_request_word_ADDRESS)
#define palette_request_bits_ADDRESS 0x48E8u
#define palette_request_bits RAM8(palette_request_bits_ADDRESS)
#define palette_request_argument_ADDRESS 0x48E9u
#define palette_request_argument RAM8(palette_request_argument_ADDRESS)
#define palette_fade_ranges_ADDRESS 0x48EAu
#define palette_fade_ranges RAM16(palette_fade_ranges_ADDRESS)
#define palette_fade_ranges_high_ADDRESS 0x48EAu
#define palette_fade_ranges_high RAM8(palette_fade_ranges_high_ADDRESS)
#define palette_fade_ranges_low_ADDRESS 0x48EBu
#define palette_fade_ranges_low RAM8(palette_fade_ranges_low_ADDRESS)
#define palette_request_word_ADDRESS 0x48E8u
#define palette_request_word RAM16(palette_request_word_ADDRESS)
#define palette_request_bits_ADDRESS 0x48E8u
#define palette_request_bits RAM8(palette_request_bits_ADDRESS)
#define palette_request_argument_ADDRESS 0x48E9u
#define palette_request_argument RAM8(palette_request_argument_ADDRESS)
#define white_flash_priorities_ADDRESS 0x48EAu
#define white_flash_priorities RAM16(white_flash_priorities_ADDRESS)
#define white_flash_priorities_high_ADDRESS 0x48EAu
#define white_flash_priorities_high RAM8(white_flash_priorities_high_ADDRESS)
#define white_flash_priorities_low_ADDRESS 0x48EBu
#define white_flash_priorities_low RAM8(white_flash_priorities_low_ADDRESS)
#define robot_pieces_left_ADDRESS 0x48F4u
#define robot_pieces_left RAM8(robot_pieces_left_ADDRESS)
#define thrown_cell_here_ADDRESS 0x48F0u
#define thrown_cell_here RAM8(thrown_cell_here_ADDRESS)
#define thrown_cell_ahead_ADDRESS 0x48F1u
#define thrown_cell_ahead RAM8(thrown_cell_ahead_ADDRESS)
#define thrown_cell_priority_ADDRESS 0x48F2u
#define thrown_cell_priority RAM8(thrown_cell_priority_ADDRESS)
#define sine_direction_ADDRESS 0x48ECu
#define sine_direction RAM8(sine_direction_ADDRESS)
#define floor_columns_left_ADDRESS 0x48F4u
#define floor_columns_left RAM8(floor_columns_left_ADDRESS)
#define step_sprite_priority_ADDRESS 0x48FAu
#define step_sprite_priority RAM8(step_sprite_priority_ADDRESS)
#define object_sprite_priority_ADDRESS 0x48FBu
#define object_sprite_priority RAM8(object_sprite_priority_ADDRESS)
#define step_sprite_priority_ADDRESS 0x48FAu
#define step_sprite_priority RAM8(step_sprite_priority_ADDRESS)
#define food_state_ADDRESS 0x48F0u
#define food_state RAM8(food_state_ADDRESS)
#define depth_rows_left_ADDRESS 0x48F0u
#define depth_rows_left RAM8(depth_rows_left_ADDRESS)
#define next_sprite_number_ADDRESS 0x48F1u
#define next_sprite_number RAM8(next_sprite_number_ADDRESS)
#define sort_slots_left_ADDRESS 0x48F2u
#define sort_slots_left RAM8(sort_slots_left_ADDRESS)
#define scene_player_bit_ADDRESS 0x48F0u
#define scene_player_bit RAM8(scene_player_bit_ADDRESS)
#define scene_player_ADDRESS 0x48F1u
#define scene_player RAM8(scene_player_ADDRESS)
#define scene_player_bit_ADDRESS 0x48F0u
#define scene_player_bit RAM8(scene_player_bit_ADDRESS)
#define scene_player_ADDRESS 0x48F1u
#define scene_player RAM8(scene_player_ADDRESS)
#define turning_direction_ADDRESS 0x48F0u
#define turning_direction RAM8(turning_direction_ADDRESS)
#define area_next_x_high_ADDRESS 0x48F0u
#define area_next_x_high RAM8(area_next_x_high_ADDRESS)
#define area_next_x_ADDRESS 0x48F1u
#define area_next_x RAM16(area_next_x_ADDRESS)
#define area_next_x_pixels_ADDRESS 0x48F1u
#define area_next_x_pixels RAM8(area_next_x_pixels_ADDRESS)
#define area_next_y_high_ADDRESS 0x48F0u
#define area_next_y_high RAM8(area_next_y_high_ADDRESS)
#define area_next_y_ADDRESS 0x48F1u
#define area_next_y RAM16(area_next_y_ADDRESS)
#define area_next_y_pixels_ADDRESS 0x48F1u
#define area_next_y_pixels RAM8(area_next_y_pixels_ADDRESS)
#define throw_helper_ADDRESS 0x48F0u
#define throw_helper RAM8(throw_helper_ADDRESS)
#define helper_throws_left_ADDRESS 0x48F1u
#define helper_throws_left RAM8(helper_throws_left_ADDRESS)
#define boss_helper_number_ADDRESS 0x48F0u
#define boss_helper_number RAM8(boss_helper_number_ADDRESS)
#define scene_riders_left_ADDRESS 0x48F0u
#define scene_riders_left RAM8(scene_riders_left_ADDRESS)
#define rider_bits_ADDRESS 0x48F1u
#define rider_bits RAM8(rider_bits_ADDRESS)
#define scene_objects_left_ADDRESS 0x48F0u
#define scene_objects_left RAM8(scene_objects_left_ADDRESS)
#define scene_riders_left_ADDRESS 0x48F0u
#define scene_riders_left RAM8(scene_riders_left_ADDRESS)
#define rider_bits_ADDRESS 0x48F1u
#define rider_bits RAM8(rider_bits_ADDRESS)
#define scene_objects_left_ADDRESS 0x48F0u
#define scene_objects_left RAM8(scene_objects_left_ADDRESS)
#define lift_items_left_ADDRESS 0x48F0u
#define lift_items_left RAM8(lift_items_left_ADDRESS)
#define chain_links_left_ADDRESS 0x48F0u
#define chain_links_left RAM8(chain_links_left_ADDRESS)
#define chain_links_left_ADDRESS 0x48F0u
#define chain_links_left RAM8(chain_links_left_ADDRESS)
#define chain_last_link_ADDRESS 0x48FAu
#define chain_last_link RAM16(chain_last_link_ADDRESS)
#define scene_x_offset_ADDRESS 0x48F0u
#define scene_x_offset RAM16S(scene_x_offset_ADDRESS)
#define bomb_spread_ADDRESS 0x48F0u
#define bomb_spread RAM8S(bomb_spread_ADDRESS)
#define bomb_distance_ADDRESS 0x48F8u
#define bomb_distance RAM16(bomb_distance_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define bombs_left_ADDRESS 0x48F0u
#define bombs_left RAM8(bombs_left_ADDRESS)
#define bombs_left_ADDRESS 0x48F0u
#define bombs_left RAM8(bombs_left_ADDRESS)
#define reunion_player_ADDRESS 0x48F0u
#define reunion_player RAM8(reunion_player_ADDRESS)
#define reunion_player_bits_ADDRESS 0x48F1u
#define reunion_player_bits RAM8(reunion_player_bits_ADDRESS)
#define reunion_standing_x_ADDRESS 0x48F8u
#define reunion_standing_x RAM16(reunion_standing_x_ADDRESS)
#define reunion_walker_x_ADDRESS 0x48FAu
#define reunion_walker_x RAM16(reunion_walker_x_ADDRESS)
#define reunion_walker_stop_offset_ADDRESS 0x48FCu
#define reunion_walker_stop_offset RAM16(reunion_walker_stop_offset_ADDRESS)
#define scene_objects_left_ADDRESS 0x48F0u
#define scene_objects_left RAM8(scene_objects_left_ADDRESS)
#define scene_riders_left_ADDRESS 0x48F0u
#define scene_riders_left RAM8(scene_riders_left_ADDRESS)
#define rider_bits_ADDRESS 0x48F1u
#define rider_bits RAM8(rider_bits_ADDRESS)
#define rider_kind_ADDRESS 0x48F2u
#define rider_kind RAM8(rider_kind_ADDRESS)
#define scene_objects_left_ADDRESS 0x48F0u
#define scene_objects_left RAM8(scene_objects_left_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define reach_x_ADDRESS 0x48F8u
#define reach_x RAM16S(reach_x_ADDRESS)
#define reach_y_ADDRESS 0x48FAu
#define reach_y RAM16S(reach_y_ADDRESS)
#define turning_direction_ADDRESS 0x48F0u
#define turning_direction RAM8(turning_direction_ADDRESS)
#define scene_player_bit_ADDRESS 0x48F0u
#define scene_player_bit RAM8(scene_player_bit_ADDRESS)
#define scene_player_ADDRESS 0x48F1u
#define scene_player RAM8(scene_player_ADDRESS)
#define jumper_order_ADDRESS 0x48F2u
#define jumper_order RAM8(jumper_order_ADDRESS)
#define shown_player_ADDRESS 0x48F0u
#define shown_player RAM8(shown_player_ADDRESS)
#define shown_player_bit_ADDRESS 0x48F1u
#define shown_player_bit RAM8(shown_player_bit_ADDRESS)
#define setup_attributes_ADDRESS 0x48F0u
#define setup_attributes RAM8(setup_attributes_ADDRESS)
#define story_players_left_ADDRESS 0x48F0u
#define story_players_left RAM8(story_players_left_ADDRESS)
#define story_player_bits_ADDRESS 0x48F1u
#define story_player_bits RAM8(story_player_bits_ADDRESS)
#define place_players_x_ADDRESS 0x48F8u
#define place_players_x RAM16(place_players_x_ADDRESS)
#define place_players_y_ADDRESS 0x48FAu
#define place_players_y RAM16(place_players_y_ADDRESS)
#define actor_reach_ADDRESS 0x48F8u
#define actor_reach RAM16(actor_reach_ADDRESS)
#define actor_reach_centre_x_ADDRESS 0x48FAu
#define actor_reach_centre_x RAM16(actor_reach_centre_x_ADDRESS)
#define free_slot_sprites_ADDRESS 0x48E8u
#define free_slot_sprites RAM16(free_slot_sprites_ADDRESS)
#define orbit_x_offset_ADDRESS 0x48E8u
#define orbit_x_offset RAM16S(orbit_x_offset_ADDRESS)
#define orbit_y_offset_ADDRESS 0x48EAu
#define orbit_y_offset RAM16S(orbit_y_offset_ADDRESS)
#define ride_parts_left_ADDRESS 0x48F0u
#define ride_parts_left RAM8(ride_parts_left_ADDRESS)
#define ride_part_angle_ADDRESS 0x48F1u
#define ride_part_angle RAM8(ride_part_angle_ADDRESS)
#define colour_blocks_left_ADDRESS 0x48F0u
#define colour_blocks_left RAM8(colour_blocks_left_ADDRESS)
#define colour_block_rows_left_ADDRESS 0x48F1u
#define colour_block_rows_left RAM8(colour_block_rows_left_ADDRESS)
#define colour_block_tiles_left_ADDRESS 0x48F2u
#define colour_block_tiles_left RAM8(colour_block_tiles_left_ADDRESS)
#define ramp_colours_left_ADDRESS 0x48F0u
#define ramp_colours_left RAM8(ramp_colours_left_ADDRESS)
#define ramp_rows_left_ADDRESS 0x48F1u
#define ramp_rows_left RAM8(ramp_rows_left_ADDRESS)
#define test_io_unread_byte_ADDRESS 0x48F1u
#define test_io_unread_byte RAM8(test_io_unread_byte_ADDRESS)
#define test_coin_bits_ADDRESS 0x48F0u
#define test_coin_bits RAM8(test_coin_bits_ADDRESS)
#define test_coinage_line_ADDRESS 0x48F0u
#define test_coinage_line RAM8(test_coinage_line_ADDRESS)
#define test_coinage_line_ADDRESS 0x48F0u
#define test_coinage_line RAM8(test_coinage_line_ADDRESS)
#define hex_colour_ADDRESS 0x48F0u
#define hex_colour RAM8(hex_colour_ADDRESS)
#define sprite_rom_passes_left_ADDRESS 0x48F0u
#define sprite_rom_passes_left RAM8(sprite_rom_passes_left_ADDRESS)
#define sprite_rom_address_ADDRESS 0x48F4u
#define sprite_rom_address RAM16(sprite_rom_address_ADDRESS)
#define sprite_rom_address_bottom_ADDRESS 0x48F6u
#define sprite_rom_address_bottom RAM8(sprite_rom_address_bottom_ADDRESS)
#define tile_rom_address_ADDRESS 0x48F8u
#define tile_rom_address RAM16(tile_rom_address_ADDRESS)
#define sprite_rom_address_ADDRESS 0x48F4u
#define sprite_rom_address RAM16(sprite_rom_address_ADDRESS)
#define sprite_rom_address_high_ADDRESS 0x48F4u
#define sprite_rom_address_high RAM8(sprite_rom_address_high_ADDRESS)
#define sprite_rom_address_low_ADDRESS 0x48F5u
#define sprite_rom_address_low RAM16(sprite_rom_address_low_ADDRESS)
#define sprite_rom_address_middle_ADDRESS 0x48F5u
#define sprite_rom_address_middle RAM8(sprite_rom_address_middle_ADDRESS)
#define sprite_rom_address_bottom_ADDRESS 0x48F6u
#define sprite_rom_address_bottom RAM8(sprite_rom_address_bottom_ADDRESS)
#define tile_rom_pages_left_ADDRESS 0x48E8u
#define tile_rom_pages_left RAM8(tile_rom_pages_left_ADDRESS)
#define tile_rom_address_ADDRESS 0x48F8u
#define tile_rom_address RAM16(tile_rom_address_ADDRESS)
#define tile_rom_page_ADDRESS 0x48F8u
#define tile_rom_page RAM8(tile_rom_page_ADDRESS)
#define thrown_cell_here_ADDRESS 0x48F0u
#define thrown_cell_here RAM8(thrown_cell_here_ADDRESS)
#define thrown_cell_ahead_ADDRESS 0x48F1u
#define thrown_cell_ahead RAM8(thrown_cell_ahead_ADDRESS)
#define thrown_cell_priority_ADDRESS 0x48F2u
#define thrown_cell_priority RAM8(thrown_cell_priority_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)
#define bonus_draw_x_ADDRESS 0x48F8u
#define bonus_draw_x RAM16(bonus_draw_x_ADDRESS)
#define bonus_draw_y_ADDRESS 0x48FAu
#define bonus_draw_y RAM16(bonus_draw_y_ADDRESS)
#define hit_check_list_1_left_ADDRESS 0x48F2u
#define hit_check_list_1_left RAM8(hit_check_list_1_left_ADDRESS)
#define sprite_text_code_ADDRESS 0x48E8u
#define sprite_text_code RAM16(sprite_text_code_ADDRESS)
#define sprite_code_index_ADDRESS 0x48EAu
#define sprite_code_index RAM8(sprite_code_index_ADDRESS)
#define debug_value_ADDRESS 0x48F0u
#define debug_value RAM16(debug_value_ADDRESS)
#define debug_value_high_ADDRESS 0x48F0u
#define debug_value_high RAM8(debug_value_high_ADDRESS)
#define debug_value_low_ADDRESS 0x48F1u
#define debug_value_low RAM8(debug_value_low_ADDRESS)
#define floor_priority_bits_ADDRESS 0x48E8u
#define floor_priority_bits RAM8(floor_priority_bits_ADDRESS)
#define floor_priority_bits_ADDRESS 0x48E8u
#define floor_priority_bits RAM8(floor_priority_bits_ADDRESS)
#define sine_direction_ADDRESS 0x48ECu
#define sine_direction RAM8(sine_direction_ADDRESS)
#define wave_sine_angle_ADDRESS 0x48E8u
#define wave_sine_angle RAM8(wave_sine_angle_ADDRESS)
#define wave_sine_size_ADDRESS 0x48E9u
#define wave_sine_size RAM8(wave_sine_size_ADDRESS)
#define wave_sine_quarter_ADDRESS 0x48EAu
#define wave_sine_quarter RAM8(wave_sine_quarter_ADDRESS)
#define wave_sine_value_ADDRESS 0x48ECu
#define wave_sine_value RAM16S(wave_sine_value_ADDRESS)
#define wave_sine_high_ADDRESS 0x48ECu
#define wave_sine_high RAM8(wave_sine_high_ADDRESS)
#define wave_sine_low_ADDRESS 0x48EDu
#define wave_sine_low RAM8(wave_sine_low_ADDRESS)
#define attack_roll_ADDRESS 0x48F0u
#define attack_roll RAM8(attack_roll_ADDRESS)
#define area_next_x_high_ADDRESS 0x48F0u
#define area_next_x_high RAM8(area_next_x_high_ADDRESS)
#define area_next_x_ADDRESS 0x48F1u
#define area_next_x RAM16(area_next_x_ADDRESS)
#define area_next_x_pixels_ADDRESS 0x48F1u
#define area_next_x_pixels RAM8(area_next_x_pixels_ADDRESS)
#define zoomed_object_ADDRESS 0x48E9u
#define zoomed_object RAM16(zoomed_object_ADDRESS)
#define zoom_offset_ADDRESS 0x48EBu
#define zoom_offset RAM8(zoom_offset_ADDRESS)
#define zoom_offset_negative_ADDRESS 0x48F0u
#define zoom_offset_negative RAM8(zoom_offset_negative_ADDRESS)
#define frame_sprites_left_ADDRESS 0x48F2u
#define frame_sprites_left RAM8(frame_sprites_left_ADDRESS)
#define sprite_slot_ADDRESS 0x48F3u
#define sprite_slot RAM8(sprite_slot_ADDRESS)
#define frame_attributes_ADDRESS 0x48F4u
#define frame_attributes RAM8(frame_attributes_ADDRESS)
#define sprite_flipped_ADDRESS 0x48F5u
#define sprite_flipped RAM8(sprite_flipped_ADDRESS)
#define draw_shadow_sprite_ADDRESS 0x48F7u
#define draw_shadow_sprite RAM8(draw_shadow_sprite_ADDRESS)
#define object_sprite_priority_ADDRESS 0x48FBu
#define object_sprite_priority RAM8(object_sprite_priority_ADDRESS)
#define zoomed_offset_ADDRESS 0x48FEu
#define zoomed_offset RAM16(zoomed_offset_ADDRESS)
#define object_sprite_priority_ADDRESS 0x48FBu
#define object_sprite_priority RAM8(object_sprite_priority_ADDRESS)
#define grab_facing_ADDRESS 0x48F0u
#define grab_facing RAM8(grab_facing_ADDRESS)
#define priority_bits_ADDRESS 0x48F0u
#define priority_bits RAM8(priority_bits_ADDRESS)

/* the program's data the code reads by name, which the game loads from its assets (src/table.c) */
#define bonus_intro_sounds_ADDRESS 0x7BC4u    /* 021BC4: bank 10 */
extern const void *bonus_intro_sounds_data;
#define bonus_intro_sounds ((const uint16_t *)bonus_intro_sounds_data)
#define bonus_1_player_records_ADDRESS 0x7BC8u    /* 021BC8: bank 10 */
extern const void *bonus_1_player_records_data;
#define bonus_1_player_records ((const uint16_t *)bonus_1_player_records_data)
#define unused_effect_78_commands_ADDRESS 0x7BECu    /* 021BEC: bank 10 */
extern const void *unused_effect_78_commands_data;
#define unused_effect_78_commands ((const uint16_t *)unused_effect_78_commands_data)
#define bonus_placements_ADDRESS 0x7C00u    /* 021C00: bank 10 */
extern const void *bonus_placements_data;
#define bonus_placements ((const uint16_t *)bonus_placements_data)
#define bonus_2_side_object_x_offsets_ADDRESS 0x7D28u    /* 021D28: bank 10 */
extern const void *bonus_2_side_object_x_offsets_data;
#define bonus_2_side_object_x_offsets ((const int8_t *)bonus_2_side_object_x_offsets_data)
#define bonus_2_shake_x_offsets_ADDRESS 0x7D44u    /* 021D44: bank 10 */
extern const void *bonus_2_shake_x_offsets_data;
#define bonus_2_shake_x_offsets ((const int8_t *)bonus_2_shake_x_offsets_data)
#define bonus_2_squash_zooms_x_ADDRESS 0x7D4Du    /* 021D4D: bank 10 */
extern const void *bonus_2_squash_zooms_x_data;
#define bonus_2_squash_zooms_x ((const uint8_t *)bonus_2_squash_zooms_x_data)
#define bonus_2_squash_zooms_y_ADDRESS 0x7D55u    /* 021D55: bank 10 */
extern const void *bonus_2_squash_zooms_y_data;
#define bonus_2_squash_zooms_y ((const uint8_t *)bonus_2_squash_zooms_y_data)
#define bonus_2_level_object_x_moves_ADDRESS 0x7D5Du    /* 021D5D: bank 10 */
extern const void *bonus_2_level_object_x_moves_data;
#define bonus_2_level_object_x_moves ((const int8_t *)bonus_2_level_object_x_moves_data)
#define bonus_2_player_x_ADDRESS 0x7D7Du    /* 021D7D: bank 10 */
extern const void *bonus_2_player_x_data;
#define bonus_2_player_x ((const uint16_t *)bonus_2_player_x_data)
#define bonus_results_hop_speeds_ADDRESS 0x7D9Cu    /* 021D9C: bank 10 */
extern const void *bonus_results_hop_speeds_data;
#define bonus_results_hop_speeds ((const int8_t *)bonus_results_hop_speeds_data)
#define wrestler_beaten_health_by_players_ADDRESS 0x7E71u    /* 021E71: bank 10 */
extern const void *wrestler_beaten_health_by_players_data;
#define wrestler_beaten_health_by_players ((const uint8_t *)wrestler_beaten_health_by_players_data)
#define wrestler_gauge_piece_health_by_players_ADDRESS 0x7E75u    /* 021E75: bank 10 */
extern const void *wrestler_gauge_piece_health_by_players_data;
#define wrestler_gauge_piece_health_by_players ((const uint8_t *)wrestler_gauge_piece_health_by_players_data)
#define wrestler_animations_ADDRESS 0x7E79u    /* 021E79: bank 10 */
extern const void *wrestler_animations_data;
#define wrestler_animations ((const uint16_t *)wrestler_animations_data)
#define wrestler_jump_chances_by_rank_ADDRESS 0x7EB9u    /* 021EB9: bank 10 */
extern const void *wrestler_jump_chances_by_rank_data;
#define wrestler_jump_chances_by_rank ((const uint8_t *)wrestler_jump_chances_by_rank_data)
#define wrestler_quick_attack_chances_by_players_ADDRESS 0x7EC9u    /* 021EC9: bank 10 */
extern const void *wrestler_quick_attack_chances_by_players_data;
#define wrestler_quick_attack_chances_by_players ((const uint8_t *)wrestler_quick_attack_chances_by_players_data)
#define wrestler_guard_chances_by_players_ADDRESS 0x7ECDu    /* 021ECD: bank 10 */
extern const void *wrestler_guard_chances_by_players_data;
#define wrestler_guard_chances_by_players ((const uint8_t *)wrestler_guard_chances_by_players_data)
#define wrestler_speeds_by_rank_ADDRESS 0x7ED1u    /* 021ED1: bank 10 */
extern const void *wrestler_speeds_by_rank_data;
#define wrestler_speeds_by_rank ((const uint8_t *)wrestler_speeds_by_rank_data)
#define player_score_addresses_ADDRESS 0x7516u    /* 023516: bank 11 */
extern const void *player_score_addresses_data;
#define player_score_addresses ((const uint16_t *)player_score_addresses_data)
#define name_entry_player_records_ADDRESS 0x7532u    /* 023532: bank 11 */
extern const void *name_entry_player_records_data;
#define name_entry_player_records ((const uint16_t *)name_entry_player_records_data)
#define name_entry_cursor_zooms_ADDRESS 0x759Eu    /* 02359E: bank 11 */
extern const void *name_entry_cursor_zooms_data;
#define name_entry_cursor_zooms ((const uint8_t *)name_entry_cursor_zooms_data)
#define name_entry_pictures_ADDRESS 0x75AEu    /* 0235AE: bank 11 */
extern const void *name_entry_pictures_data;
#define name_entry_pictures ((const uint16_t *)name_entry_pictures_data)
#define name_entry_picture_blocks_ADDRESS 0x75BEu    /* 0235BE: bank 11 */
extern const void *name_entry_picture_blocks_data;
#define name_entry_picture_blocks ((const uint8_t *)name_entry_picture_blocks_data)
#define sprite_font_code_high_ADDRESS 0x7694u    /* 023694: bank 11 */
extern const void *sprite_font_code_high_data;
#define sprite_font_code_high ((const uint8_t *)sprite_font_code_high_data)
#define sprite_font_codes_ADDRESS 0x7695u    /* 023695: bank 11 */
extern const void *sprite_font_codes_data;
#define sprite_font_codes ((const uint8_t *)sprite_font_codes_data)
#define high_score_icons_ADDRESS 0x76E6u    /* 0236E6: bank 11 */
extern const void *high_score_icons_data;
#define high_score_icons ((const uint8_t *)high_score_icons_data)
#define ending_family_waits_ADDRESS 0x76F8u    /* 0236F8: bank 11 */
extern const void *ending_family_waits_data;
#define ending_family_waits ((const uint16_t *)ending_family_waits_data)
#define staff_roll_titles_ADDRESS 0x7736u    /* 023736: bank 11 */
extern const void *staff_roll_titles_data;
#define staff_roll_titles ((const uint16_t *)staff_roll_titles_data)
#define staff_roll_names_ADDRESS 0x78B2u    /* 0238B2: bank 11 */
extern const void *staff_roll_names_data;
#define staff_roll_names ((const uint16_t *)staff_roll_names_data)
#define stage_7_boss_beaten_health_by_players_ADDRESS 0x7A4Du    /* 023A4D: bank 11 */
extern const void *stage_7_boss_beaten_health_by_players_data;
#define stage_7_boss_beaten_health_by_players ((const uint8_t *)stage_7_boss_beaten_health_by_players_data)
#define stage_7_boss_gauge_piece_health_by_players_ADDRESS 0x7A51u    /* 023A51: bank 11 */
extern const void *stage_7_boss_gauge_piece_health_by_players_data;
#define stage_7_boss_gauge_piece_health_by_players ((const uint8_t *)stage_7_boss_gauge_piece_health_by_players_data)
#define stage_7_boss_animations_ADDRESS 0x7A55u    /* 023A55: bank 11 */
extern const void *stage_7_boss_animations_data;
#define stage_7_boss_animations ((const uint16_t *)stage_7_boss_animations_data)
#define stage_7_boss_charge_waits_by_players_ADDRESS 0x7A99u    /* 023A99: bank 11 */
extern const void *stage_7_boss_charge_waits_by_players_data;
#define stage_7_boss_charge_waits_by_players ((const uint16_t *)stage_7_boss_charge_waits_by_players_data)
#define stage_7_boss_quick_attack_chances_by_players_ADDRESS 0x7AA1u    /* 023AA1: bank 11 */
extern const void *stage_7_boss_quick_attack_chances_by_players_data;
#define stage_7_boss_quick_attack_chances_by_players ((const uint8_t *)stage_7_boss_quick_attack_chances_by_players_data)
#define stage_7_boss_jump_away_chances_by_players_ADDRESS 0x7AA5u    /* 023AA5: bank 11 */
extern const void *stage_7_boss_jump_away_chances_by_players_data;
#define stage_7_boss_jump_away_chances_by_players ((const uint8_t *)stage_7_boss_jump_away_chances_by_players_data)
#define stage_7_boss_speeds_by_rank_ADDRESS 0x7AA9u    /* 023AA9: bank 11 */
extern const void *stage_7_boss_speeds_by_rank_data;
#define stage_7_boss_speeds_by_rank ((const uint8_t *)stage_7_boss_speeds_by_rank_data)
#define stage_7_boss_helper_attack_times_by_rank_ADDRESS 0x7AB9u    /* 023AB9: bank 11 */
extern const void *stage_7_boss_helper_attack_times_by_rank_data;
#define stage_7_boss_helper_attack_times_by_rank ((const uint16_t *)stage_7_boss_helper_attack_times_by_rank_data)
#define stage_7_boss_helper_speeds_ADDRESS 0x7B09u    /* 023B09: bank 11 */
extern const void *stage_7_boss_helper_speeds_data;
#define stage_7_boss_helper_speeds ((const uint16_t *)stage_7_boss_helper_speeds_data)
#define stage_7_boss_helper_distances_ADDRESS 0x7B15u    /* 023B15: bank 11 */
extern const void *stage_7_boss_helper_distances_data;
#define stage_7_boss_helper_distances ((const uint16_t *)stage_7_boss_helper_distances_data)
#define game_texts_address_ADDRESS 0x6021u    /* 024021: bank 12 */
extern const void *game_texts_address_data;
#define game_texts_address ((const uint16_t *)game_texts_address_data)
#define stage_end_exit_waits_ADDRESS 0x7962u    /* 025962: bank 12 */
extern const void *stage_end_exit_waits_data;
#define stage_end_exit_waits ((const uint8_t *)stage_end_exit_waits_data)
#define absent_player_blanks_ADDRESS 0x797Au    /* 02597A: bank 12 */
extern const void *absent_player_blanks_data;
#define absent_player_blanks ((const uint16_t *)absent_player_blanks_data)
#define wave_cosines_ADDRESS 0x79A4u    /* 0259A4: bank 12 */
extern const void *wave_cosines_data;
#define wave_cosines ((const uint8_t *)wave_cosines_data)
#define game_texts_ADDRESS 0x79E4u    /* 0259E4: bank 12 */
extern const void *game_texts_data;
#define game_texts ((const uint16_t *)game_texts_data)
#define screen_shake_lengths_ADDRESS 0x7A10u    /* 027A10: bank 13 */
extern const void *screen_shake_lengths_data;
#define screen_shake_lengths ((const uint8_t *)screen_shake_lengths_data)
#define layer_scroll_records_ADDRESS 0x7A37u    /* 027A37: bank 13 */
extern const void *layer_scroll_records_data;
#define layer_scroll_records ((const uint16_t *)layer_scroll_records_data)
#define stage_records_ADDRESS 0x7A7Bu    /* 027A7B: bank 13 */
extern const void *stage_records_data;
#define stage_records ((const uint8_t *)stage_records_data)
#define krusty_balloon_beaten_health_by_players_ADDRESS 0x7CAEu    /* 027CAE: bank 13 */
extern const void *krusty_balloon_beaten_health_by_players_data;
#define krusty_balloon_beaten_health_by_players ((const uint8_t *)krusty_balloon_beaten_health_by_players_data)
#define krusty_balloon_gauge_piece_health_by_players_ADDRESS 0x7CB2u    /* 027CB2: bank 13 */
extern const void *krusty_balloon_gauge_piece_health_by_players_data;
#define krusty_balloon_gauge_piece_health_by_players ((const uint8_t *)krusty_balloon_gauge_piece_health_by_players_data)
#define krusty_balloon_animations_ADDRESS 0x7CB6u    /* 027CB6: bank 13 */
extern const void *krusty_balloon_animations_data;
#define krusty_balloon_animations ((const uint16_t *)krusty_balloon_animations_data)
#define krusty_balloon_hit_limits_by_players_ADDRESS 0x7D00u    /* 027D00: bank 13 */
extern const void *krusty_balloon_hit_limits_by_players_data;
#define krusty_balloon_hit_limits_by_players ((const uint8_t *)krusty_balloon_hit_limits_by_players_data)
#define krusty_balloon_quick_attack_chances_by_players_ADDRESS 0x7D04u    /* 027D04: bank 13 */
extern const void *krusty_balloon_quick_attack_chances_by_players_data;
#define krusty_balloon_quick_attack_chances_by_players ((const uint8_t *)krusty_balloon_quick_attack_chances_by_players_data)
#define krusty_balloon_fly_off_chances_by_rank_ADDRESS 0x7D08u    /* 027D08: bank 13 */
extern const void *krusty_balloon_fly_off_chances_by_rank_data;
#define krusty_balloon_fly_off_chances_by_rank ((const uint8_t *)krusty_balloon_fly_off_chances_by_rank_data)
#define krusty_balloon_speeds_by_rank_ADDRESS 0x7D18u    /* 027D18: bank 13 */
extern const void *krusty_balloon_speeds_by_rank_data;
#define krusty_balloon_speeds_by_rank ((const uint8_t *)krusty_balloon_speeds_by_rank_data)
#define krusty_balloon_throw_z_speeds_ADDRESS 0x7D28u    /* 027D28: bank 13 */
extern const void *krusty_balloon_throw_z_speeds_data;
#define krusty_balloon_throw_z_speeds ((const uint16_t *)krusty_balloon_throw_z_speeds_data)
#define goon_from_back_xs_ADDRESS 0x7A72u    /* 029A72: bank 14 */
extern const void *goon_from_back_xs_data;
#define goon_from_back_xs ((const uint16_t *)goon_from_back_xs_data)
#define goon_drop_xs_ADDRESS 0x7BC8u    /* 029BC8: bank 14 */
extern const void *goon_drop_xs_data;
#define goon_drop_xs ((const uint16_t *)goon_drop_xs_data)
#define umbrella_goon_xs_ADDRESS 0x7BE0u    /* 029BE0: bank 14 */
extern const void *umbrella_goon_xs_data;
#define umbrella_goon_xs ((const uint16_t *)umbrella_goon_xs_data)
#define unused_goon_waits_by_rank_ADDRESS 0x7C2Eu    /* 029C2E: bank 14 */
extern const void *unused_goon_waits_by_rank_data;
#define unused_goon_waits_by_rank ((const uint8_t *)unused_goon_waits_by_rank_data)
#define goon_strike_waits_by_players_ADDRESS 0x7C7Au    /* 029C7A: bank 14 */
extern const void *goon_strike_waits_by_players_data;
#define goon_strike_waits_by_players ((const uint8_t *)goon_strike_waits_by_players_data)
#define goon_jump_attack_chances_by_rank_ADDRESS 0x7CA3u    /* 029CA3: bank 14 */
extern const void *goon_jump_attack_chances_by_rank_data;
#define goon_jump_attack_chances_by_rank ((const uint8_t *)goon_jump_attack_chances_by_rank_data)
#define goon_hold_animations_ADDRESS 0x7CD3u    /* 029CD3: bank 14 */
extern const void *goon_hold_animations_data;
#define goon_hold_animations ((const uint8_t *)goon_hold_animations_data)
#define shovel_goon_close_strike_waits_by_players_ADDRESS 0x7EE5u    /* 029EE5: bank 14 */
extern const void *shovel_goon_close_strike_waits_by_players_data;
#define shovel_goon_close_strike_waits_by_players ((const uint8_t *)shovel_goon_close_strike_waits_by_players_data)
#define shovel_goon_far_strike_waits_by_players_ADDRESS 0x7EF4u    /* 029EF4: bank 14 */
extern const void *shovel_goon_far_strike_waits_by_players_data;
#define shovel_goon_far_strike_waits_by_players ((const uint8_t *)shovel_goon_far_strike_waits_by_players_data)
#define goon_jump_in_xs_ADDRESS 0x7F9Bu    /* 029F9B: bank 14 */
extern const void *goon_jump_in_xs_data;
#define goon_jump_in_xs ((const uint16_t *)goon_jump_in_xs_data)
#define goon_from_below_xs_ADDRESS 0x7FAFu    /* 029FAF: bank 14 */
extern const void *goon_from_below_xs_data;
#define goon_from_below_xs ((const uint16_t *)goon_from_below_xs_data)
#define cemetery_umbrella_goon_xs_ADDRESS 0x7FC3u    /* 029FC3: bank 14 */
extern const void *cemetery_umbrella_goon_xs_data;
#define cemetery_umbrella_goon_xs ((const uint16_t *)cemetery_umbrella_goon_xs_data)
#define fat_goon_from_back_xs_ADDRESS 0x7890u    /* 02B890: bank 15 */
extern const void *fat_goon_from_back_xs_data;
#define fat_goon_from_back_xs ((const uint16_t *)fat_goon_from_back_xs_data)
#define fat_goon_strike_waits_by_players_ADDRESS 0x7974u    /* 02B974: bank 15 */
extern const void *fat_goon_strike_waits_by_players_data;
#define fat_goon_strike_waits_by_players ((const uint8_t *)fat_goon_strike_waits_by_players_data)
#define fat_goon_hold_animations_ADDRESS 0x7995u    /* 02B995: bank 15 */
extern const void *fat_goon_hold_animations_data;
#define fat_goon_hold_animations ((const uint8_t *)fat_goon_hold_animations_data)
#define fat_goon_jump_in_xs_ADDRESS 0x79A5u    /* 02B9A5: bank 15 */
extern const void *fat_goon_jump_in_xs_data;
#define fat_goon_jump_in_xs ((const uint16_t *)fat_goon_jump_in_xs_data)
#define fat_goon_from_below_xs_ADDRESS 0x79B9u    /* 02B9B9: bank 15 */
extern const void *fat_goon_from_below_xs_data;
#define fat_goon_from_below_xs ((const uint16_t *)fat_goon_from_below_xs_data)
#define enemy_waves_end_enemies_ADDRESS 0x79F1u    /* 02B9F1: bank 15 */
extern const void *enemy_waves_end_enemies_data;
#define enemy_waves_end_enemies ((const uint8_t *)enemy_waves_end_enemies_data)
#define object_15_spawn_lists_ADDRESS 0x79FEu    /* 02B9FE: bank 15 */
extern const void *object_15_spawn_lists_data;
#define object_15_spawn_lists ((const uint16_t *)object_15_spawn_lists_data)
#define enemy_waves_next_wave_enemies_ADDRESS 0x7A18u    /* 02BA18: bank 15 */
extern const void *enemy_waves_next_wave_enemies_data;
#define enemy_waves_next_wave_enemies ((const uint8_t *)enemy_waves_next_wave_enemies_data)
#define krustyland_door_releases_ADDRESS 0x7DCEu    /* 02BDCE: bank 15 */
extern const void *krustyland_door_releases_data;
#define krustyland_door_releases ((const uint8_t *)krustyland_door_releases_data)
#define cemetery_obstacle_xs_ADDRESS 0x7B58u    /* 02DB58: bank 16 */
extern const void *cemetery_obstacle_xs_data;
#define cemetery_obstacle_xs ((const uint16_t *)cemetery_obstacle_xs_data)
#define cemetery_obstacle_food_ADDRESS 0x7B68u    /* 02DB68: bank 16 */
extern const void *cemetery_obstacle_food_data;
#define cemetery_obstacle_food ((const uint8_t *)cemetery_obstacle_food_data)
#define moes_street_scenery_floor_edge_flags_ADDRESS 0x7BF2u    /* 02DBF2: bank 16 */
extern const void *moes_street_scenery_floor_edge_flags_data;
#define moes_street_scenery_floor_edge_flags ((const uint8_t *)moes_street_scenery_floor_edge_flags_data)
#define police_car_door_lists_ADDRESS 0x7C3Eu    /* 02DC3E: bank 16 */
extern const void *police_car_door_lists_data;
#define police_car_door_lists ((const uint16_t *)police_car_door_lists_data)
#define police_car_door_releases_ADDRESS 0x7C46u    /* 02DC46: bank 16 */
extern const void *police_car_door_releases_data;
#define police_car_door_releases ((const uint8_t *)police_car_door_releases_data)
#define player_objects_ADDRESS 0x7D83u    /* 02DD83: bank 16 */
extern const void *player_objects_data;
#define player_objects ((const uint16_t *)player_objects_data)
#define obstacle_heights_ADDRESS 0x7DB1u    /* 02DDB1: bank 16 */
extern const void *obstacle_heights_data;
#define obstacle_heights ((const uint8_t *)obstacle_heights_data)
#define object_16_flags_ADDRESS 0x7E39u    /* 02DE39: bank 16 */
extern const void *object_16_flags_data;
#define object_16_flags ((const uint8_t *)object_16_flags_data)
#define object_16_patterns_ADDRESS 0x7E57u    /* 02DE57: bank 16 */
extern const void *object_16_patterns_data;
#define object_16_patterns ((const uint8_t *)object_16_patterns_data)
#define rising_scenery_camera_xs_ADDRESS 0x7FA1u    /* 02DFA1: bank 16 */
extern const void *rising_scenery_camera_xs_data;
#define rising_scenery_camera_xs ((const uint16_t *)rising_scenery_camera_xs_data)
#define item_setups_ADDRESS 0x7A70u    /* 02FA70: bank 17 */
extern const void *item_setups_data;
#define item_setups ((const uint16_t *)item_setups_data)
#define food_move_choices_ADDRESS 0x7A9Cu    /* 02FA9C: bank 17 */
extern const void *food_move_choices_data;
#define food_move_choices ((const uint16_t *)food_move_choices_data)
#define food_hit_kinds_ADDRESS 0x7ACEu    /* 02FACE: bank 17 */
extern const void *food_hit_kinds_data;
#define food_hit_kinds ((const uint8_t *)food_hit_kinds_data)
#define girl_with_food_partners_ADDRESS 0x7B00u    /* 02FB00: bank 17 */
extern const void *girl_with_food_partners_data;
#define girl_with_food_partners ((const uint16_t *)girl_with_food_partners_data)
#define girl_with_food_food_drops_ADDRESS 0x7B28u    /* 02FB28: bank 17 */
extern const void *girl_with_food_food_drops_data;
#define girl_with_food_food_drops ((const uint16_t *)girl_with_food_food_drops_data)
#define item_carrier_setups_ADDRESS 0x7B7Au    /* 02FB7A: bank 17 */
extern const void *item_carrier_setups_data;
#define item_carrier_setups ((const uint16_t *)item_carrier_setups_data)
#define item_carrier_items_ADDRESS 0x7B92u    /* 02FB92: bank 17 */
extern const void *item_carrier_items_data;
#define item_carrier_items ((const uint16_t *)item_carrier_items_data)
#define carried_item_kinds_ADDRESS 0x7BB8u    /* 02FBB8: bank 17 */
extern const void *carried_item_kinds_data;
#define carried_item_kinds ((const uint8_t *)carried_item_kinds_data)
#define kent_brockman_damage_animations_ADDRESS 0x7C9Fu    /* 02FC9F: bank 17 */
extern const void *kent_brockman_damage_animations_data;
#define kent_brockman_damage_animations ((const uint8_t *)kent_brockman_damage_animations_data)
#define krustyland_child_limits_by_players_ADDRESS 0x7DA2u    /* 02FDA2: bank 17 */
extern const void *krustyland_child_limits_by_players_data;
#define krustyland_child_limits_by_players ((const uint8_t *)krustyland_child_limits_by_players_data)
#define teacup_goon_attributes_by_health_ADDRESS 0x7DFFu    /* 02FDFF: bank 17 */
extern const void *teacup_goon_attributes_by_health_data;
#define teacup_goon_attributes_by_health ((const uint8_t *)teacup_goon_attributes_by_health_data)
#define clown_on_ball_pause_waits_by_rank_ADDRESS 0x7E87u    /* 02FE87: bank 17 */
extern const void *clown_on_ball_pause_waits_by_rank_data;
#define clown_on_ball_pause_waits_by_rank ((const uint8_t *)clown_on_ball_pause_waits_by_rank_data)
#define orbit_cosines_ADDRESS 0x7E8Fu    /* 02FE8F: bank 17 */
extern const void *orbit_cosines_data;
#define orbit_cosines ((const uint8_t *)orbit_cosines_data)
#define caged_gorilla_idle_animations_ADDRESS 0x7F3Bu    /* 02FF3B: bank 17 */
extern const void *caged_gorilla_idle_animations_data;
#define caged_gorilla_idle_animations ((const uint8_t *)caged_gorilla_idle_animations_data)
#define random_figure_poses_ADDRESS 0x7FB9u    /* 02FFB9: bank 17 */
extern const void *random_figure_poses_data;
#define random_figure_poses ((const uint8_t *)random_figure_poses_data)
#define kind_97_hold_animations_ADDRESS 0x7B0Au    /* 031B0A: bank 18 */
extern const void *kind_97_hold_animations_data;
#define kind_97_hold_animations ((const uint8_t *)kind_97_hold_animations_data)
#define lumberjack_pause_loops_by_players_ADDRESS 0x7C0Cu    /* 031C0C: bank 18 */
extern const void *lumberjack_pause_loops_by_players_data;
#define lumberjack_pause_loops_by_players ((const uint8_t *)lumberjack_pause_loops_by_players_data)
#define gorilla_leap_speeds_ADDRESS 0x7C5Du    /* 031C5D: bank 18 */
extern const void *gorilla_leap_speeds_data;
#define gorilla_leap_speeds ((const uint16_t *)gorilla_leap_speeds_data)
#define kind_c7_sweep_ways_ADDRESS 0x7DA1u    /* 031DA1: bank 18 */
extern const void *kind_c7_sweep_ways_data;
#define kind_c7_sweep_ways ((const uint8_t *)kind_c7_sweep_ways_data)
#define kind_c7_headings_ADDRESS 0x7DA8u    /* 031DA8: bank 18 */
extern const void *kind_c7_headings_data;
#define kind_c7_headings ((const uint8_t *)kind_c7_headings_data)
#define kind_c7_sweep_rates_ADDRESS 0x7DAFu    /* 031DAF: bank 18 */
extern const void *kind_c7_sweep_rates_data;
#define kind_c7_sweep_rates ((const uint8_t *)kind_c7_sweep_rates_data)
#define kind_c7_start_x_ADDRESS 0x7DB6u    /* 031DB6: bank 18 */
extern const void *kind_c7_start_x_data;
#define kind_c7_start_x ((const uint16_t *)kind_c7_start_x_data)
#define kind_c7_hurt_shakes_ADDRESS 0x7DD8u    /* 031DD8: bank 18 */
extern const void *kind_c7_hurt_shakes_data;
#define kind_c7_hurt_shakes ((const uint8_t *)kind_c7_hurt_shakes_data)
#define kind_c7_bob_up_ADDRESS 0x7DDCu    /* 031DDC: bank 18 */
extern const void *kind_c7_bob_up_data;
#define kind_c7_bob_up ((const uint8_t *)kind_c7_bob_up_data)
#define kind_c7_bob_down_ADDRESS 0x7DFCu    /* 031DFC: bank 18 */
extern const void *kind_c7_bob_down_data;
#define kind_c7_bob_down ((const int8_t *)kind_c7_bob_down_data)
#define kind_c7_shot_waits_ADDRESS 0x7E1Cu    /* 031E1C: bank 18 */
extern const void *kind_c7_shot_waits_data;
#define kind_c7_shot_waits ((const uint8_t *)kind_c7_shot_waits_data)
#define barney_animations_ADDRESS 0x7F7Au    /* 031F7A: bank 18 */
extern const void *barney_animations_data;
#define barney_animations ((const uint8_t *)barney_animations_data)
#define kind_a1_entrance_steps_ADDRESS 0x7A72u    /* 033A72: bank 19 */
extern const void *kind_a1_entrance_steps_data;
#define kind_a1_entrance_steps ((const uint8_t *)kind_a1_entrance_steps_data)
#define kind_a1_attack_delays_by_players_ADDRESS 0x7AB5u    /* 033AB5: bank 19 */
extern const void *kind_a1_attack_delays_by_players_data;
#define kind_a1_attack_delays_by_players ((const uint8_t *)kind_a1_attack_delays_by_players_data)
#define hit_spark_times_ADDRESS 0x7BCCu    /* 033BCC: bank 19 */
extern const void *hit_spark_times_data;
#define hit_spark_times ((const uint8_t *)hit_spark_times_data)
#define robot_sparks_by_frame_9d_ADDRESS 0x7C16u    /* 033C16: bank 19 */
extern const void *robot_sparks_by_frame_9d_data;
#define robot_sparks_by_frame_9d ((const uint16_t *)robot_sparks_by_frame_9d_data)
#define robot_sparks_by_frame_92_ADDRESS 0x7C3Cu    /* 033C3C: bank 19 */
extern const void *robot_sparks_by_frame_92_data;
#define robot_sparks_by_frame_92 ((const uint16_t *)robot_sparks_by_frame_92_data)
#define robot_sparks_by_frame_91_ADDRESS 0x7C76u    /* 033C76: bank 19 */
extern const void *robot_sparks_by_frame_91_data;
#define robot_sparks_by_frame_91 ((const uint16_t *)robot_sparks_by_frame_91_data)
#define robot_actions_after_hit_ADDRESS 0x7CB8u    /* 033CB8: bank 19 */
extern const void *robot_actions_after_hit_data;
#define robot_actions_after_hit ((const uint8_t *)robot_actions_after_hit_data)
#define robot_status_after_hit_ADDRESS 0x7CC0u    /* 033CC0: bank 19 */
extern const void *robot_status_after_hit_data;
#define robot_status_after_hit ((const uint8_t *)robot_status_after_hit_data)
#define robot_part_zooms_ADDRESS 0x7D22u    /* 033D22: bank 19 */
extern const void *robot_part_zooms_data;
#define robot_part_zooms ((const uint8_t *)robot_part_zooms_data)
#define flying_saxophone_sweep_ways_ADDRESS 0x7E86u    /* 033E86: bank 19 */
extern const void *flying_saxophone_sweep_ways_data;
#define flying_saxophone_sweep_ways ((const uint8_t *)flying_saxophone_sweep_ways_data)
#define flying_saxophone_headings_ADDRESS 0x7E8Du    /* 033E8D: bank 19 */
extern const void *flying_saxophone_headings_data;
#define flying_saxophone_headings ((const uint8_t *)flying_saxophone_headings_data)
#define flying_saxophone_sweep_rates_ADDRESS 0x7E94u    /* 033E94: bank 19 */
extern const void *flying_saxophone_sweep_rates_data;
#define flying_saxophone_sweep_rates ((const uint8_t *)flying_saxophone_sweep_rates_data)
#define flying_saxophone_descent_slowdowns_ADDRESS 0x7E9Bu    /* 033E9B: bank 19 */
extern const void *flying_saxophone_descent_slowdowns_data;
#define flying_saxophone_descent_slowdowns ((const uint16_t *)flying_saxophone_descent_slowdowns_data)
#define flying_saxophone_descent_y_speeds_ADDRESS 0x7EA9u    /* 033EA9: bank 19 */
extern const void *flying_saxophone_descent_y_speeds_data;
#define flying_saxophone_descent_y_speeds ((const int16_t *)flying_saxophone_descent_y_speeds_data)
#define flying_saxophone_volley_shots_ADDRESS 0x7EC7u    /* 033EC7: bank 19 */
extern const void *flying_saxophone_volley_shots_data;
#define flying_saxophone_volley_shots ((const uint16_t *)flying_saxophone_volley_shots_data)
#define flying_saxophone_single_shots_ADDRESS 0x7EEFu    /* 033EEF: bank 19 */
extern const void *flying_saxophone_single_shots_data;
#define flying_saxophone_single_shots ((const uint16_t *)flying_saxophone_single_shots_data)
#define flying_saxophone_hurt_shakes_ADDRESS 0x7F0Du    /* 033F0D: bank 19 */
extern const void *flying_saxophone_hurt_shakes_data;
#define flying_saxophone_hurt_shakes ((const uint8_t *)flying_saxophone_hurt_shakes_data)
#define flying_saxophone_bob_up_ADDRESS 0x7F11u    /* 033F11: bank 19 */
extern const void *flying_saxophone_bob_up_data;
#define flying_saxophone_bob_up ((const uint8_t *)flying_saxophone_bob_up_data)
#define flying_saxophone_bob_down_ADDRESS 0x7F31u    /* 033F31: bank 19 */
extern const void *flying_saxophone_bob_down_data;
#define flying_saxophone_bob_down ((const int8_t *)flying_saxophone_bob_down_data)
#define flying_saxophone_shot_waits_ADDRESS 0x7F51u    /* 033F51: bank 19 */
extern const void *flying_saxophone_shot_waits_data;
#define flying_saxophone_shot_waits ((const uint8_t *)flying_saxophone_shot_waits_data)
#define flying_saxophone_shot_animations_ADDRESS 0x7FE3u    /* 033FE3: bank 19 */
extern const void *flying_saxophone_shot_animations_data;
#define flying_saxophone_shot_animations ((const uint8_t *)flying_saxophone_shot_animations_data)
#define flying_saxophone_shot_speeds_ADDRESS 0x7FE9u    /* 033FE9: bank 19 */
extern const void *flying_saxophone_shot_speeds_data;
#define flying_saxophone_shot_speeds ((const uint16_t *)flying_saxophone_shot_speeds_data)
#define unused_spawn_tail_ADDRESS 0x76DDu    /* 0356DD: bank 1A */
extern const void *unused_spawn_tail_data;
#define unused_spawn_tail ((const uint8_t *)unused_spawn_tail_data)
#define unused_debug_tile_places_ADDRESS 0x76E0u    /* 0356E0: bank 1A */
extern const void *unused_debug_tile_places_data;
#define unused_debug_tile_places ((const uint16_t *)unused_debug_tile_places_data)
#define unused_blank_lines_text_ADDRESS 0x76FEu    /* 0356FE: bank 1A */
extern const void *unused_blank_lines_text_data;
#define unused_blank_lines_text ((const uint8_t *)unused_blank_lines_text_data)
#define unused_tfvo_text_ADDRESS 0x7744u    /* 035744: bank 1A */
extern const void *unused_tfvo_text_data;
#define unused_tfvo_text ((const uint8_t *)unused_tfvo_text_data)
#define object_1a_levels_ADDRESS 0x7754u    /* 035754: bank 1A */
extern const void *object_1a_levels_data;
#define object_1a_levels ((const uint8_t *)object_1a_levels_data)
#define object_1a_next_states_ADDRESS 0x77BCu    /* 0357BC: bank 1A */
extern const void *object_1a_next_states_data;
#define object_1a_next_states ((const uint8_t *)object_1a_next_states_data)
#define object_1a_states_after_ADDRESS 0x77C1u    /* 0357C1: bank 1A */
extern const void *object_1a_states_after_data;
#define object_1a_states_after ((const uint8_t *)object_1a_states_after_data)
#define object_1a_level_rows_ADDRESS 0x77C6u    /* 0357C6: bank 1A */
extern const void *object_1a_level_rows_data;
#define object_1a_level_rows ((const uint16_t *)object_1a_level_rows_data)
#define object_1a_chase_leg_times_ADDRESS 0x77FEu    /* 0357FE: bank 1A */
extern const void *object_1a_chase_leg_times_data;
#define object_1a_chase_leg_times ((const uint8_t *)object_1a_chase_leg_times_data)
#define object_1a_bounce_animations_ADDRESS 0x782Au    /* 03582A: bank 1A */
extern const void *object_1a_bounce_animations_data;
#define object_1a_bounce_animations ((const uint8_t *)object_1a_bounce_animations_data)
#define object_1a_pose_times_ADDRESS 0x7832u    /* 035832: bank 1A */
extern const void *object_1a_pose_times_data;
#define object_1a_pose_times ((const uint8_t *)object_1a_pose_times_data)
#define object_1a_pose_animations_ADDRESS 0x783Au    /* 03583A: bank 1A */
extern const void *object_1a_pose_animations_data;
#define object_1a_pose_animations ((const uint8_t *)object_1a_pose_animations_data)
#define object_1a_leap_speeds_ADDRESS 0x784Eu    /* 03584E: bank 1A */
extern const void *object_1a_leap_speeds_data;
#define object_1a_leap_speeds ((const uint8_t *)object_1a_leap_speeds_data)
#define object_1a_leap_heights_ADDRESS 0x785Eu    /* 03585E: bank 1A */
extern const void *object_1a_leap_heights_data;
#define object_1a_leap_heights ((const uint8_t *)object_1a_leap_heights_data)
#define object_1a_repeat_animations_ADDRESS 0x78A0u    /* 0358A0: bank 1A */
extern const void *object_1a_repeat_animations_data;
#define object_1a_repeat_animations ((const uint8_t *)object_1a_repeat_animations_data)
#define object_1a_approach_times_ADDRESS 0x78C8u    /* 0358C8: bank 1A */
extern const void *object_1a_approach_times_data;
#define object_1a_approach_times ((const uint8_t *)object_1a_approach_times_data)
#define object_1a_released_objects_ADDRESS 0x78ECu    /* 0358EC: bank 1A */
extern const void *object_1a_released_objects_data;
#define object_1a_released_objects ((const uint16_t *)object_1a_released_objects_data)
#define unused_speed_words_ADDRESS 0x7934u    /* 035934: bank 1A */
extern const void *unused_speed_words_data;
#define unused_speed_words ((const uint16_t *)unused_speed_words_data)
#define object_1a_path_choices_ADDRESS 0x79DCu    /* 0359DC: bank 1A */
extern const void *object_1a_path_choices_data;
#define object_1a_path_choices ((const uint8_t *)object_1a_path_choices_data)
#define object_1a_path_times_ADDRESS 0x79F0u    /* 0359F0: bank 1A */
extern const void *object_1a_path_times_data;
#define object_1a_path_times ((const uint8_t *)object_1a_path_times_data)
#define object_1a_sines_ADDRESS 0x7FA3u    /* 035FA3: bank 1A */
extern const void *object_1a_sines_data;
#define object_1a_sines ((const uint8_t *)object_1a_sines_data)
#define spawn_lists_ADDRESS 0x6000u    /* 036000: bank 1B */
extern const void *spawn_lists_data;
#define spawn_lists ((const uint16_t *)spawn_lists_data)
#define door_spawn_lists_ADDRESS 0x6454u    /* 036454: bank 1B */
extern const void *door_spawn_lists_data;
#define door_spawn_lists ((const uint16_t *)door_spawn_lists_data)
#define door_spawns_end_ADDRESS 0x6473u    /* 036473: bank 1B */
extern const void *door_spawns_end_data;
#define door_spawns_end ((const uint8_t *)door_spawns_end_data)
#define team_move_attack_states_ADDRESS 0x7DD5u    /* 039DD5: bank 1C */
extern const void *team_move_attack_states_data;
#define team_move_attack_states ((const uint8_t *)team_move_attack_states_data)
#define object_1c_move_steps_ADDRESS 0x7DEBu    /* 039DEB: bank 1C */
extern const void *object_1c_move_steps_data;
#define object_1c_move_steps ((const uint8_t *)object_1c_move_steps_data)
#define team_move_animation_offsets_ADDRESS 0x7E3Du    /* 039E3D: bank 1C */
extern const void *team_move_animation_offsets_data;
#define team_move_animation_offsets ((const uint8_t *)team_move_animation_offsets_data)
#define pickup_vitality_ADDRESS 0x7EADu    /* 039EAD: bank 1C */
extern const void *pickup_vitality_data;
#define pickup_vitality ((const uint8_t *)pickup_vitality_data)
#define team_move_box_widths_ADDRESS 0x7FD1u    /* 039FD1: bank 1C */
extern const void *team_move_box_widths_data;
#define team_move_box_widths ((const uint8_t *)team_move_box_widths_data)
#define zoom_steps_address_ADDRESS 0x602Au    /* 03A02A: bank 1D */
extern const void *zoom_steps_address_data;
#define zoom_steps_address ((const uint16_t *)zoom_steps_address_data)
#define stage_8_boss_stop_throwing_chances_by_players_ADDRESS 0x7AA5u    /* 03BAA5: bank 1D */
extern const void *stage_8_boss_stop_throwing_chances_by_players_data;
#define stage_8_boss_stop_throwing_chances_by_players ((const uint8_t *)stage_8_boss_stop_throwing_chances_by_players_data)
#define stage_8_boss_bombs_by_players_ADDRESS 0x7AA9u    /* 03BAA9: bank 1D */
extern const void *stage_8_boss_bombs_by_players_data;
#define stage_8_boss_bombs_by_players ((const uint8_t *)stage_8_boss_bombs_by_players_data)
#define stage_8_boss_run_speeds_by_players_ADDRESS 0x7AADu    /* 03BAAD: bank 1D */
extern const void *stage_8_boss_run_speeds_by_players_data;
#define stage_8_boss_run_speeds_by_players ((const uint8_t *)stage_8_boss_run_speeds_by_players_data)
#define stage_8_boss_hit_limits_address_ADDRESS 0x7AB1u    /* 03BAB1: bank 1D */
extern const void *stage_8_boss_hit_limits_address_data;
#define stage_8_boss_hit_limits_address ((const uint16_t *)stage_8_boss_hit_limits_address_data)
#define stage_8_boss_invulnerable_times_by_players_ADDRESS 0x7AB5u    /* 03BAB5: bank 1D */
extern const void *stage_8_boss_invulnerable_times_by_players_data;
#define stage_8_boss_invulnerable_times_by_players ((const uint8_t *)stage_8_boss_invulnerable_times_by_players_data)
#define stage_8_boss_run_skip_attack_chances_by_players_ADDRESS 0x7AB9u    /* 03BAB9: bank 1D */
extern const void *stage_8_boss_run_skip_attack_chances_by_players_data;
#define stage_8_boss_run_skip_attack_chances_by_players ((const uint8_t *)stage_8_boss_run_skip_attack_chances_by_players_data)
#define stage_8_boss_beaten_healths_by_players_ADDRESS 0x7ABDu    /* 03BABD: bank 1D */
extern const void *stage_8_boss_beaten_healths_by_players_data;
#define stage_8_boss_beaten_healths_by_players ((const uint8_t *)stage_8_boss_beaten_healths_by_players_data)
#define stage_8_boss_retreat_speeds_by_players_ADDRESS 0x7AC1u    /* 03BAC1: bank 1D */
extern const void *stage_8_boss_retreat_speeds_by_players_data;
#define stage_8_boss_retreat_speeds_by_players ((const uint8_t *)stage_8_boss_retreat_speeds_by_players_data)
#define stage_8_boss_walk_speeds_by_players_ADDRESS 0x7AC5u    /* 03BAC5: bank 1D */
extern const void *stage_8_boss_walk_speeds_by_players_data;
#define stage_8_boss_walk_speeds_by_players ((const uint8_t *)stage_8_boss_walk_speeds_by_players_data)
#define stage_8_boss_jump_speeds_by_players_ADDRESS 0x7AC9u    /* 03BAC9: bank 1D */
extern const void *stage_8_boss_jump_speeds_by_players_data;
#define stage_8_boss_jump_speeds_by_players ((const uint8_t *)stage_8_boss_jump_speeds_by_players_data)
#define stage_8_boss_dash_speeds_by_players_ADDRESS 0x7ACDu    /* 03BACD: bank 1D */
extern const void *stage_8_boss_dash_speeds_by_players_data;
#define stage_8_boss_dash_speeds_by_players ((const uint8_t *)stage_8_boss_dash_speeds_by_players_data)
#define stage_8_boss_jump_bomb_player_limits_ADDRESS 0x7AD1u    /* 03BAD1: bank 1D */
extern const void *stage_8_boss_jump_bomb_player_limits_data;
#define stage_8_boss_jump_bomb_player_limits ((const uint8_t *)stage_8_boss_jump_bomb_player_limits_data)
#define burns_robot_volleys_by_players_ADDRESS 0x7B5Au    /* 03BB5A: bank 1D */
extern const void *burns_robot_volleys_by_players_data;
#define burns_robot_volleys_by_players ((const uint8_t *)burns_robot_volleys_by_players_data)
#define burns_robot_shot_y_speeds_ADDRESS 0x7B76u    /* 03BB76: bank 1D */
extern const void *burns_robot_shot_y_speeds_data;
#define burns_robot_shot_y_speeds ((const int16_t *)burns_robot_shot_y_speeds_data)
#define burns_robot_healths_ADDRESS 0x7B80u    /* 03BB80: bank 1D */
extern const void *burns_robot_healths_data;
#define burns_robot_healths ((const uint8_t *)burns_robot_healths_data)
#define burns_robot_beaten_healths_ADDRESS 0x7B85u    /* 03BB85: bank 1D */
extern const void *burns_robot_beaten_healths_data;
#define burns_robot_beaten_healths ((const uint16_t *)burns_robot_beaten_healths_data)
#define burns_robot_form_0_beaten_healths_ADDRESS 0x7B8Fu    /* 03BB8F: bank 1D */
extern const void *burns_robot_form_0_beaten_healths_data;
#define burns_robot_form_0_beaten_healths ((const uint8_t *)burns_robot_form_0_beaten_healths_data)
#define burns_robot_form_1_beaten_healths_ADDRESS 0x7B93u    /* 03BB93: bank 1D */
extern const void *burns_robot_form_1_beaten_healths_data;
#define burns_robot_form_1_beaten_healths ((const uint8_t *)burns_robot_form_1_beaten_healths_data)
#define burns_robot_form_2_beaten_healths_ADDRESS 0x7B97u    /* 03BB97: bank 1D */
extern const void *burns_robot_form_2_beaten_healths_data;
#define burns_robot_form_2_beaten_healths ((const uint8_t *)burns_robot_form_2_beaten_healths_data)
#define burns_robot_form_3_beaten_healths_ADDRESS 0x7B9Bu    /* 03BB9B: bank 1D */
extern const void *burns_robot_form_3_beaten_healths_data;
#define burns_robot_form_3_beaten_healths ((const uint8_t *)burns_robot_form_3_beaten_healths_data)
#define burns_robot_form_4_beaten_healths_ADDRESS 0x7B9Fu    /* 03BB9F: bank 1D */
extern const void *burns_robot_form_4_beaten_healths_data;
#define burns_robot_form_4_beaten_healths ((const uint8_t *)burns_robot_form_4_beaten_healths_data)
#define burns_robot_second_attack_chances_by_players_ADDRESS 0x7BA3u    /* 03BBA3: bank 1D */
extern const void *burns_robot_second_attack_chances_by_players_data;
#define burns_robot_second_attack_chances_by_players ((const uint8_t *)burns_robot_second_attack_chances_by_players_data)
#define burns_robot_shot_times_ADDRESS 0x7BA7u    /* 03BBA7: bank 1D */
extern const void *burns_robot_shot_times_data;
#define burns_robot_shot_times ((const uint16_t *)burns_robot_shot_times_data)
#define burns_robot_held_part_times_ADDRESS 0x7BC7u    /* 03BBC7: bank 1D */
extern const void *burns_robot_held_part_times_data;
#define burns_robot_held_part_times ((const uint16_t *)burns_robot_held_part_times_data)
#define burns_robot_quick_attack_chances_ADDRESS 0x7BE7u    /* 03BBE7: bank 1D */
extern const void *burns_robot_quick_attack_chances_data;
#define burns_robot_quick_attack_chances ((const uint16_t *)burns_robot_quick_attack_chances_data)
#define burns_robot_quick_attack_chances_forms_0_to_3_ADDRESS 0x7BF1u    /* 03BBF1: bank 1D */
extern const void *burns_robot_quick_attack_chances_forms_0_to_3_data;
#define burns_robot_quick_attack_chances_forms_0_to_3 ((const uint8_t *)burns_robot_quick_attack_chances_forms_0_to_3_data)
#define burns_robot_quick_attack_chances_form_4_ADDRESS 0x7BF5u    /* 03BBF5: bank 1D */
extern const void *burns_robot_quick_attack_chances_form_4_data;
#define burns_robot_quick_attack_chances_form_4 ((const uint8_t *)burns_robot_quick_attack_chances_form_4_data)
#define burns_robot_animations_ADDRESS 0x7BF9u    /* 03BBF9: bank 1D */
extern const void *burns_robot_animations_data;
#define burns_robot_animations ((const uint16_t *)burns_robot_animations_data)
#define burns_robot_hit_boxes_ADDRESS 0x7C65u    /* 03BC65: bank 1D */
extern const void *burns_robot_hit_boxes_data;
#define burns_robot_hit_boxes ((const uint16_t *)burns_robot_hit_boxes_data)
#define burns_robot_walk_speeds_ADDRESS 0x7CD7u    /* 03BCD7: bank 1D */
extern const void *burns_robot_walk_speeds_data;
#define burns_robot_walk_speeds ((const uint16_t *)burns_robot_walk_speeds_data)
#define burns_robot_walk_speeds_form_0_ADDRESS 0x7CE1u    /* 03BCE1: bank 1D */
extern const void *burns_robot_walk_speeds_form_0_data;
#define burns_robot_walk_speeds_form_0 ((const uint8_t *)burns_robot_walk_speeds_form_0_data)
#define burns_robot_walk_speeds_form_1_ADDRESS 0x7CF1u    /* 03BCF1: bank 1D */
extern const void *burns_robot_walk_speeds_form_1_data;
#define burns_robot_walk_speeds_form_1 ((const uint8_t *)burns_robot_walk_speeds_form_1_data)
#define burns_robot_walk_speeds_forms_2_3_ADDRESS 0x7D01u    /* 03BD01: bank 1D */
extern const void *burns_robot_walk_speeds_forms_2_3_data;
#define burns_robot_walk_speeds_forms_2_3 ((const uint8_t *)burns_robot_walk_speeds_forms_2_3_data)
#define burns_robot_walk_speeds_form_4_ADDRESS 0x7D11u    /* 03BD11: bank 1D */
extern const void *burns_robot_walk_speeds_form_4_data;
#define burns_robot_walk_speeds_form_4 ((const uint8_t *)burns_robot_walk_speeds_form_4_data)
#define zoom_steps_ADDRESS 0x7DE7u    /* 03BDE7: bank 1D */
extern const void *zoom_steps_data;
#define zoom_steps ((const uint16_t *)zoom_steps_data)
#define scripted_object_scripts_ADDRESS 0x78B5u    /* 03D8B5: bank 1E */
extern const void *scripted_object_scripts_data;
#define scripted_object_scripts ((const uint16_t *)scripted_object_scripts_data)
#define scripted_object_script_bytes_ADDRESS 0x78C9u    /* 03D8C9: bank 1E */
extern const void *scripted_object_script_bytes_data;
#define scripted_object_script_bytes ((const uint8_t *)scripted_object_script_bytes_data)
#define football_player_attack_delays_by_players_ADDRESS 0x7DA6u    /* 03DDA6: bank 1E */
extern const void *football_player_attack_delays_by_players_data;
#define football_player_attack_delays_by_players ((const uint8_t *)football_player_attack_delays_by_players_data)
#define football_player_speed_ranges_by_rank_ADDRESS 0x7DAAu    /* 03DDAA: bank 1E */
extern const void *football_player_speed_ranges_by_rank_data;
#define football_player_speed_ranges_by_rank ((const int8_t *)football_player_speed_ranges_by_rank_data)
#define bear_attack_delays_by_players_ADDRESS 0x7E64u    /* 03DE64: bank 1E */
extern const void *bear_attack_delays_by_players_data;
#define bear_attack_delays_by_players ((const uint8_t *)bear_attack_delays_by_players_data)
#define bear_charge_speeds_by_rank_ADDRESS 0x7E80u    /* 03DE80: bank 1E */
extern const void *bear_charge_speeds_by_rank_data;
#define bear_charge_speeds_by_rank ((const uint16_t *)bear_charge_speeds_by_rank_data)
#define stage_3_boss_slow_attack_chances_by_players_ADDRESS 0x7F36u    /* 03DF36: bank 1E */
extern const void *stage_3_boss_slow_attack_chances_by_players_data;
#define stage_3_boss_slow_attack_chances_by_players ((const uint8_t *)stage_3_boss_slow_attack_chances_by_players_data)
#define stage_3_boss_follow_up_chances_by_players_ADDRESS 0x7F39u    /* 03DF39: bank 1E */
extern const void *stage_3_boss_follow_up_chances_by_players_data;
#define stage_3_boss_follow_up_chances_by_players ((const uint8_t *)stage_3_boss_follow_up_chances_by_players_data)
#define story_scripts_ADDRESS 0x7078u    /* 03F078: bank 1F */
extern const void *story_scripts_data;
#define story_scripts ((const uint16_t *)story_scripts_data)
#define player_overhead_heights_ADDRESS 0x7E77u    /* 03FE77: bank 1F */
extern const void *player_overhead_heights_data;
#define player_overhead_heights ((const uint8_t *)player_overhead_heights_data)
#define player_throw_heights_ADDRESS 0x7E7Bu    /* 03FE7B: bank 1F */
extern const void *player_throw_heights_data;
#define player_throw_heights ((const uint8_t *)player_throw_heights_data)
#define player_balloon_animations_ADDRESS 0x7E7Fu    /* 03FE7F: bank 1F */
extern const void *player_balloon_animations_data;
#define player_balloon_animations ((const uint8_t *)player_balloon_animations_data)
#define pair_balloon_players_ADDRESS 0x7E84u    /* 03FE84: bank 1F */
extern const void *pair_balloon_players_data;
#define pair_balloon_players ((const uint8_t *)pair_balloon_players_data)
#define player_state_classes_ADDRESS 0x7E94u    /* 03FE94: bank 1F */
extern const void *player_state_classes_data;
#define player_state_classes ((const int8_t *)player_state_classes_data)
#define profile_moves_ADDRESS 0x70E3u    /* 0410E3: bank 20 */
extern const void *profile_moves_data;
#define profile_moves ((const uint16_t *)profile_moves_data)
#define profile_texts_ADDRESS 0x7106u    /* 041106: bank 20 */
extern const void *profile_texts_data;
#define profile_texts ((const uint16_t *)profile_texts_data)
#define gauge_player_records_ADDRESS 0x7294u    /* 041294: bank 20 */
extern const void *gauge_player_records_data;
#define gauge_player_records ((const uint16_t *)gauge_player_records_data)
#define gauge_pictures_ADDRESS 0x7316u    /* 041316: bank 20 */
extern const void *gauge_pictures_data;
#define gauge_pictures ((const uint16_t *)gauge_pictures_data)
#define continue_digit_pictures_ADDRESS 0x73F1u    /* 0413F1: bank 20 */
extern const void *continue_digit_pictures_data;
#define continue_digit_pictures ((const uint16_t *)continue_digit_pictures_data)
#define rank_base_ADDRESS 0x7782u    /* 041782: bank 20 */
extern const void *rank_base_data;
#define rank_base ((const uint8_t *)rank_base_data)
#define rank_by_players_ADDRESS 0x7786u    /* 041786: bank 20 */
extern const void *rank_by_players_data;
#define rank_by_players ((const uint8_t *)rank_by_players_data)
#define rank_by_scene_ADDRESS 0x778Au    /* 04178A: bank 20 */
extern const void *rank_by_scene_data;
#define rank_by_scene ((const uint8_t *)rank_by_scene_data)
#define rank_step_times_ADDRESS 0x7796u    /* 041796: bank 20 */
extern const void *rank_step_times_data;
#define rank_step_times ((const uint16_t *)rank_step_times_data)
#define rank_frame_limits_ADDRESS 0x77ACu    /* 0417AC: bank 20 */
extern const void *rank_frame_limits_data;
#define rank_frame_limits ((const uint16_t *)rank_frame_limits_data)
#define palette_effects_ADDRESS 0x6000u    /* 05C000: bank 2E */
extern const void *palette_effects_data;
#define palette_effects ((const uint16_t *)palette_effects_data)
#define test_menu_cursor_steps_ADDRESS 0x6502u    /* 05E502: bank 2F */
extern const void *test_menu_cursor_steps_data;
#define test_menu_cursor_steps ((const int8_t *)test_menu_cursor_steps_data)
#define sound_test_effects_ADDRESS 0x6739u    /* 05E739: bank 2F */
extern const void *sound_test_effects_data;
#define sound_test_effects ((const uint16_t *)sound_test_effects_data)
#define sound_test_music_ADDRESS 0x688Fu    /* 05E88F: bank 2F */
extern const void *sound_test_music_data;
#define sound_test_music ((const uint16_t *)sound_test_music_data)
#define test_mode_hex_digit_tiles_ADDRESS 0x75AEu    /* 05F5AE: bank 2F */
extern const void *test_mode_hex_digit_tiles_data;
#define test_mode_hex_digit_tiles ((const uint8_t *)test_mode_hex_digit_tiles_data)
#define test_mode_texts_ADDRESS 0x75BEu    /* 05F5BE: bank 2F */
extern const void *test_mode_texts_data;
#define test_mode_texts ((const uint16_t *)test_mode_texts_data)
#define test_mode_words_ADDRESS 0x78F7u    /* 05F8F7: bank 2F */
extern const void *test_mode_words_data;
#define test_mode_words ((const uint16_t *)test_mode_words_data)
#define coin_setting_coin_digits_ADDRESS 0x7A5Cu    /* 05FA5C: bank 2F */
extern const void *coin_setting_coin_digits_data;
#define coin_setting_coin_digits ((const uint8_t *)coin_setting_coin_digits_data)
#define coin_setting_credit_digits_ADDRESS 0x7A6Eu    /* 05FA6E: bank 2F */
extern const void *coin_setting_credit_digits_data;
#define coin_setting_credit_digits ((const uint8_t *)coin_setting_credit_digits_data)
#define eeprom_address_signals_ADDRESS 0x7CA7u    /* 05FCA7: bank 2F */
extern const void *eeprom_address_signals_data;
#define eeprom_address_signals ((const uint8_t *)eeprom_address_signals_data)
#define eeprom_data_signals_ADDRESS 0x7CB6u    /* 05FCB6: bank 2F */
extern const void *eeprom_data_signals_data;
#define eeprom_data_signals ((const uint8_t *)eeprom_data_signals_data)
#define eeprom_wait_signal_ADDRESS 0x7CCBu    /* 05FCCB: bank 2F */
extern const void *eeprom_wait_signal_data;
#define eeprom_wait_signal ((const uint8_t *)eeprom_wait_signal_data)
#define graphics_rom_sums_ADDRESS 0x7D5Cu    /* 05FD5C: bank 2F */
extern const void *graphics_rom_sums_data;
#define graphics_rom_sums ((const uint16_t *)graphics_rom_sums_data)
#define graphics_rom_result_places_ADDRESS 0x7D68u    /* 05FD68: bank 2F */
extern const void *graphics_rom_result_places_data;
#define graphics_rom_result_places ((const uint16_t *)graphics_rom_result_places_data)
#define sprite_rom_read_banks_ADDRESS 0x7D74u    /* 05FD74: bank 2F */
extern const void *sprite_rom_read_banks_data;
#define sprite_rom_read_banks ((const uint8_t *)sprite_rom_read_banks_data)
#define test_player_records_ADDRESS 0x7D88u    /* 05FD88: bank 2F */
extern const void *test_player_records_data;
#define test_player_records ((const uint16_t *)test_player_records_data)
#define palette_request_handlers_ADDRESS 0xBADAu    /* 07BADA: the fixed program */
extern const void *palette_request_handlers_data;
#define palette_request_handlers ((const uint16_t *)palette_request_handlers_data)
#define rom_07E000_ADDRESS 0xE000u    /* 07E000: the fixed program */
extern const void *rom_07E000_data;
#define rom_07E000 ((const uint8_t *)rom_07E000_data)
#define rom_07E001_ADDRESS 0xE001u    /* 07E001: the fixed program */
extern const void *rom_07E001_data;
#define rom_07E001 ((const uint8_t *)rom_07E001_data)
#define rom_07E026_ADDRESS 0xE026u    /* 07E026: the fixed program */
extern const void *rom_07E026_data;
#define rom_07E026 ((const uint16_t *)rom_07E026_data)
#define rom_07E040_ADDRESS 0xE040u    /* 07E040: the fixed program */
extern const void *rom_07E040_data;
#define rom_07E040 ((const uint8_t *)rom_07E040_data)
#define rom_07E041_ADDRESS 0xE041u    /* 07E041: the fixed program */
extern const void *rom_07E041_data;
#define rom_07E041 ((const uint8_t *)rom_07E041_data)
#define coinages_ADDRESS 0xE3EBu    /* 07E3EB: the fixed program */
extern const void *coinages_data;
#define coinages ((const uint8_t *)coinages_data)
#define rom_13c_sum_ADDRESS 0xE423u    /* 07E423: the fixed program */
extern const void *rom_13c_sum_data;
#define rom_13c_sum ((const uint16_t *)rom_13c_sum_data)
#define rom_15c_sum_ADDRESS 0xE425u    /* 07E425: the fixed program */
extern const void *rom_15c_sum_data;
#define rom_15c_sum ((const uint16_t *)rom_15c_sum_data)
#define rom_16c_sum_ADDRESS 0xE427u    /* 07E427: the fixed program */
extern const void *rom_16c_sum_data;
#define rom_16c_sum ((const uint16_t *)rom_16c_sum_data)
#define rom_17c_sum_ADDRESS 0xE429u    /* 07E429: the fixed program */
extern const void *rom_17c_sum_data;
#define rom_17c_sum ((const uint16_t *)rom_17c_sum_data)
#define hex_digit_tiles_ADDRESS 0xE435u    /* 07E435: the fixed program */
extern const void *hex_digit_tiles_data;
#define hex_digit_tiles ((const uint8_t *)hex_digit_tiles_data)
#define player_presses_ADDRESS 0xE449u    /* 07E449: the fixed program */
extern const void *player_presses_data;
#define player_presses ((const uint16_t *)player_presses_data)
#define hurt_effect_rows_ADDRESS 0xE526u    /* 07E526: the fixed program */
extern const void *hurt_effect_rows_data;
#define hurt_effect_rows ((const uint16_t *)hurt_effect_rows_data)
#define step_sprite_priorities_ADDRESS 0xE574u    /* 07E574: the fixed program */
extern const void *step_sprite_priorities_data;
#define step_sprite_priorities ((const uint8_t *)step_sprite_priorities_data)
#define demos_ADDRESS 0xE6A1u    /* 07E6A1: the fixed program */
extern const void *demos_data;
#define demos ((const uint16_t *)demos_data)
#define player_records_ADDRESS 0xE819u    /* 07E819: the fixed program */
extern const void *player_records_data;
#define player_records ((const uint16_t *)player_records_data)
#define step_scenes_ADDRESS 0xE88Du    /* 07E88D: the fixed program */
extern const void *step_scenes_data;
#define step_scenes ((const uint8_t *)step_scenes_data)
#define palette_sets_ADDRESS 0xE9CBu    /* 07E9CB: the fixed program */
extern const void *palette_sets_data;
#define palette_sets ((const uint16_t *)palette_sets_data)
#define palette_sets_high_ADDRESS 0xEAEBu    /* 07EAEB: the fixed program */
extern const void *palette_sets_high_data;
#define palette_sets_high ((const uint16_t *)palette_sets_high_data)
#define layer_maps_ADDRESS 0xEC9Du    /* 07EC9D: the fixed program */
extern const void *layer_maps_data;
#define layer_maps ((const uint16_t *)layer_maps_data)
#define block_scenes_a_ADDRESS 0xECC9u    /* 07ECC9: the fixed program */
extern const void *block_scenes_a_data;
#define block_scenes_a ((const uint16_t *)block_scenes_a_data)
#define block_scenes_b_ADDRESS 0xECE9u    /* 07ECE9: the fixed program */
extern const void *block_scenes_b_data;
#define block_scenes_b ((const uint16_t *)block_scenes_b_data)
#define map_scenes_a_ADDRESS 0xECF9u    /* 07ECF9: the fixed program */
extern const void *map_scenes_a_data;
#define map_scenes_a ((const uint16_t *)map_scenes_a_data)
#define map_scenes_b_ADDRESS 0xED19u    /* 07ED19: the fixed program */
extern const void *map_scenes_b_data;
#define map_scenes_b ((const uint16_t *)map_scenes_b_data)
#define block_scenes_a_high_ADDRESS 0xED29u    /* 07ED29: the fixed program */
extern const void *block_scenes_a_high_data;
#define block_scenes_a_high ((const uint16_t *)block_scenes_a_high_data)
#define block_scenes_b_high_ADDRESS 0xEDBBu    /* 07EDBB: the fixed program */
extern const void *block_scenes_b_high_data;
#define block_scenes_b_high ((const uint16_t *)block_scenes_b_high_data)
#define map_scenes_a_high_ADDRESS 0xEE41u    /* 07EE41: the fixed program */
extern const void *map_scenes_a_high_data;
#define map_scenes_a_high ((const uint16_t *)map_scenes_a_high_data)
#define map_scenes_b_high_ADDRESS 0xEED3u    /* 07EED3: the fixed program */
extern const void *map_scenes_b_high_data;
#define map_scenes_b_high ((const uint16_t *)map_scenes_b_high_data)
#define layer_modes_ADDRESS 0xEF55u    /* 07EF55: the fixed program */
extern const void *layer_modes_data;
#define layer_modes ((const uint16_t *)layer_modes_data)
#define layer_modes_high_ADDRESS 0xEF63u    /* 07EF63: the fixed program */
extern const void *layer_modes_high_data;
#define layer_modes_high ((const uint16_t *)layer_modes_high_data)
#define tile_pictures_ADDRESS 0xEFB5u    /* 07EFB5: the fixed program */
extern const void *tile_pictures_data;
#define tile_pictures ((const uint16_t *)tile_pictures_data)
#define spawn_list_places_ADDRESS 0xEFBCu    /* 07EFBC: the fixed program */
extern const void *spawn_list_places_data;
#define spawn_list_places ((const uint16_t *)spawn_list_places_data)
#define enemy_speeds_by_rank_ADDRESS 0xEFD4u    /* 07EFD4: the fixed program */
extern const void *enemy_speeds_by_rank_data;
#define enemy_speeds_by_rank ((const uint8_t *)enemy_speeds_by_rank_data)
#define object_list_sizes_ADDRESS 0xEFF4u    /* 07EFF4: the fixed program */
extern const void *object_list_sizes_data;
#define object_list_sizes ((const uint8_t *)object_list_sizes_data)
#define object_lists_ADDRESS 0xEFF8u    /* 07EFF8: the fixed program */
extern const void *object_lists_data;
#define object_lists ((const uint16_t *)object_lists_data)
#define enemy_limits_by_difficulty_ADDRESS 0xF000u    /* 07F000: the fixed program */
extern const void *enemy_limits_by_difficulty_data;
#define enemy_limits_by_difficulty ((const uint8_t *)enemy_limits_by_difficulty_data)
#define extra_enemies_by_scene_ADDRESS 0xF008u    /* 07F008: the fixed program */
extern const void *extra_enemies_by_scene_data;
#define extra_enemies_by_scene ((const uint8_t *)extra_enemies_by_scene_data)
#define cemetery_enemy_limits_by_players_ADDRESS 0xF014u    /* 07F014: the fixed program */
extern const void *cemetery_enemy_limits_by_players_data;
#define cemetery_enemy_limits_by_players ((const uint8_t *)cemetery_enemy_limits_by_players_data)
#define attackers_per_player_ADDRESS 0xF031u    /* 07F031: the fixed program */
extern const void *attackers_per_player_data;
#define attackers_per_player ((const uint8_t *)attackers_per_player_data)
#define sines_ADDRESS 0xF061u    /* 07F061: the fixed program */
extern const void *sines_data;
#define sines ((const uint8_t *)sines_data)
#define sines_20_ADDRESS 0xF0A2u    /* 07F0A2: the fixed program */
extern const void *sines_20_data;
#define sines_20 ((const uint8_t *)sines_20_data)
#define arctangents_ADDRESS 0xF0E3u    /* 07F0E3: the fixed program */
extern const void *arctangents_data;
#define arctangents ((const uint8_t *)arctangents_data)
#define climb_speeds_ADDRESS 0xF124u    /* 07F124: the fixed program */
extern const void *climb_speeds_data;
#define climb_speeds ((const uint8_t *)climb_speeds_data)
#define hit_animations_ADDRESS 0xF2ACu    /* 07F2AC: the fixed program */
extern const void *hit_animations_data;
#define hit_animations ((const uint8_t *)hit_animations_data)
#define enemy_banks_ADDRESS 0xF387u    /* 07F387: the fixed program */
extern const void *enemy_banks_data;
#define enemy_banks ((const uint8_t *)enemy_banks_data)
#define object_list_1_banks_ADDRESS 0xF4B0u    /* 07F4B0: the fixed program */
extern const void *object_list_1_banks_data;
#define object_list_1_banks ((const uint8_t *)object_list_1_banks_data)
#define child_object_banks_ADDRESS 0xF54Cu    /* 07F54C: the fixed program */
extern const void *child_object_banks_data;
#define child_object_banks ((const uint8_t *)child_object_banks_data)
#define stage_event_banks_ADDRESS 0xF581u    /* 07F581: the fixed program */
extern const void *stage_event_banks_data;
#define stage_event_banks ((const uint8_t *)stage_event_banks_data)
#define action_banks_ADDRESS 0xF620u    /* 07F620: the fixed program */
extern const void *action_banks_data;
#define action_banks ((const uint8_t *)action_banks_data)
#define unused_object_banks_ADDRESS 0xF661u    /* 07F661: the fixed program */
extern const void *unused_object_banks_data;
#define unused_object_banks ((const uint8_t *)unused_object_banks_data)
#define block_tile_flags_ADDRESS 0xF67Cu    /* 07F67C: the fixed program */
extern const void *block_tile_flags_data;
#define block_tile_flags ((const uint8_t *)block_tile_flags_data)
#define rom_07FAC1_ADDRESS 0xFAC1u    /* 07FAC1: the fixed program */
extern const void *rom_07FAC1_data;
#define rom_07FAC1 ((const uint8_t *)rom_07FAC1_data)
#define rom_07FFA0_ADDRESS 0xFFA0u    /* 07FFA0: the fixed program */
extern const void *rom_07FFA0_data;
#define rom_07FFA0 ((const uint8_t *)rom_07FFA0_data)
#define rom_07FFA4_ADDRESS 0xFFA4u    /* 07FFA4: the fixed program */
extern const void *rom_07FFA4_data;
#define rom_07FFA4 ((const uint8_t *)rom_07FFA4_data)
#define rom_07FFC0_ADDRESS 0xFFC0u    /* 07FFC0: the fixed program */
extern const void *rom_07FFC0_data;
#define rom_07FFC0 ((const uint8_t *)rom_07FFC0_data)
#define rom_07FFF8_ADDRESS 0xFFF8u    /* 07FFF8: the fixed program */
extern const void *rom_07FFF8_data;
#define rom_07FFF8 ((const uint16_t *)rom_07FFF8_data)
#define rom_07FFFD_ADDRESS 0xFFFDu    /* 07FFFD: the fixed program */
extern const void *rom_07FFFD_data;
#define rom_07FFFD ((const uint8_t *)rom_07FFFD_data)
#define reset_vector_ADDRESS 0xFFFEu    /* 07FFFE: the fixed program */
extern const void *reset_vector_data;
#define reset_vector ((const uint16_t *)reset_vector_data)

/* the board's registers (read and written through the bus) */
#define VIDEO_0000 0x0000u
#define VIDEO_002F 0x002Fu
#define VIDEO_0031 0x0031u
#define VIDEO_003C 0x003Cu
#define VIDEO_00A0 0x00A0u
#define VIDEO_00C0 0x00C0u
#define VIDEO_0C00 0x0C00u
#define tile_chip_layer_a_y 0x180Cu
#define bonus_2_state 0x1840u
#define bonus_2_timer 0x1841u
#define bonus_results_state 0x1842u
#define bonus_results_timer 0x1843u
#define results_last_result 0x1844u
#define results_boxes_placed 0x1845u
#define results_place 0x1846u
#define running_player_values 0x1848u
#define object_group_count 0x184Au
#define players_stop_request 0x184Bu
#define players_idle_count 0x184Cu
#define heavy_object_workers 0x184Du
#define players_all_idle 0x184Eu
#define VIDEO_1850 0x1850u
#define stage_kept_object 0x1852u
#define stage_kept_object_2 0x1854u
#define unread_kept_word 0x1856u
#define player_drop_x 0x1858u
#define player_balloons_off 0x185Au
#define VIDEO_1860 0x1860u
#define least_attacked_player 0x1870u
#define nearest_player_found 0x1872u
#define stage_player_count 0x1874u
#define enemies_present 0x1876u
#define attackers_per_player_limit 0x1877u
#define walk_delay_turn 0x1878u
#define list_1_objects_in_play 0x1879u
#define child_objects_in_play 0x187Au
#define knockdown_turn 0x187Bu
#define girl_with_food_drop_count 0x187Cu
#define girl_with_food_leave_count 0x187Du
#define ninjas_dismissed 0x187Eu
#define rising_scenery_cue 0x187Fu
#define enemies_present_last_frame 0x1880u
#define VIDEO_1881 0x1881u
#define enemies_entered 0x1883u
#define police_car_stop_signal 0x1884u
#define enemies_allowed 0x1885u
#define enemy_walk_speed 0x1886u
#define dreamland_chain_x_offset 0x1888u
#define floor_raise_height 0x188Bu
#define dreamland_boss_phase_vitality 0x188Cu
#define hold_both_scrolls 0x189Cu
#define enemy_random_number 0x189Eu
#define scene_state 0x18E0u
#define scene_substate 0x18E1u
#define scene_wait 0x18E2u
#define scene_short_wait 0x18E3u
#define scene_palette_effect 0x18E4u
#define scene_layer_a_speed 0x18E5u
#define staff_roll_line 0x18E6u
#define scene_second_wait 0x18E7u
#define bonus_1_presses 0x18E8u
#define ending_family_step 0x18E9u
#define dream_wave_line 0x18EAu
#define scene_layer_b_speed 0x18EBu
#define dream_wave_step 0x18ECu
#define dream_wave_size 0x18EDu
#define scene_shared_value 0x18EEu
#define bonus_title_frames 0x18EFu
#define chain_lead_link 0x18F0u
#define bonus_title_step 0x18F1u
#define chain_end_link 0x18F2u
#define dream_wave_hold_frames 0x18F3u
#define reunion_spot_x 0x18F4u
#define reunion_spot_y 0x18F6u
#define reunion_camera_x 0x18F8u
#define reunion_camera_y 0x18FAu
#define maggie_rescuer 0x18FCu
#define tile_chip_layer_a_x 0x1A00u
#define tile_chip_scroll_control 0x1C80u
#define tile_chip_irq_control 0x1D00u
#define tile_chip_banks_0_1 0x1D80u
#define VIDEO_1E00 0x1E00u
#define tile_chip_flip 0x1E80u
#define tile_chip_banks_2_3 0x1F00u
#define coin_switch_port 0x1F80u
#define test_eeprom_port 0x1F81u
#define player_1_input_port 0x1F90u
#define player_2_input_port 0x1F91u
#define player_3_input_port 0x1F92u
#define player_4_input_port 0x1F93u
#define sprite_chip_scroll_x 0x1FA0u
#define sprite_chip_scroll_y 0x1FA2u
#define sprite_chip_rom_bottom 0x1FA4u
#define sprite_chip_control_register 0x1FA5u
#define sprite_chip_rom_high 0x1FA6u
#define sprite_chip_rom_middle 0x1FA7u
#define background_priority 0x1FB0u
#define fixed_layer_priority 0x1FB2u
#define layer_a_priority 0x1FB3u
#define layer_b_priority 0x1FB4u
#define IO_1FB6 0x1FB6u
#define IO_1FB7 0x1FB7u
#define IO_1FB8 0x1FB8u
#define colour_bases_back_sprites_fixed 0x1FB9u
#define colour_bases_layers_a_b 0x1FBAu
#define IO_1FBB 0x1FBBu
#define IO_1FBC 0x1FBCu
#define board_output_register 0x1FC0u
#define board_control_register 0x1FC2u
#define sound_irq_port 0x1FC4u
#define sound_command_port 0x1FC6u
#define sound_echo_port 0x1FC7u
#define sprite_chip_rom_first_byte 0x1FC8u
#define sprite_chip_rom_second_byte 0x1FC9u
#define watchdog_port 0x1FCAu
#define VIDEO_2000 0x2000u
#define VIDEO_24E2 0x24E2u
#define VIDEO_26DD 0x26DDu
#define tile_chip_layer_b_y 0x380Cu
#define name_entry_state 0x3840u
#define name_entry_records 0x3842u
#define name_entry_time 0x385Eu
#define name_entry_ranking 0x3860u
#define VIDEO_3862 0x3862u
#define VIDEO_3864 0x3864u
#define VIDEO_3866 0x3866u
#define tile_chip_layer_b_x 0x3A00u
#define palette_jobs 0x3C00u

/* data of the program symbols.txt and the assets label (their CPU addresses) */
#define map_scenes_a_high_3_1_ADDRESS 0x6000u    /* 000000 */
#define map_scenes_a_high_3_1_0_ADDRESS 0x6004u    /* 000004 */
#define map_scenes_a_high_3_1_1_ADDRESS 0x6084u    /* 000084 */
#define map_scenes_a_high_11_1_ADDRESS 0x6104u    /* 000104 */
#define map_scenes_a_high_11_1_0_ADDRESS 0x6108u    /* 000108 */
#define map_scenes_a_high_11_1_1_ADDRESS 0x6188u    /* 000188 */
#define map_scenes_a_high_11_1_1_rest_ADDRESS 0x6208u    /* 000208 */
#define map_scenes_a_high_11_1_1_rest_2_ADDRESS 0x620Cu    /* 00020C */
#define map_scenes_a_0_0_ADDRESS 0x630Cu    /* 00030C */
#define map_scenes_a_0_0_0_ADDRESS 0x631Cu    /* 00031C */
#define map_scenes_a_0_0_1_ADDRESS 0x639Cu    /* 00039C */
#define map_scenes_a_0_0_2_ADDRESS 0x641Cu    /* 00041C */
#define map_scenes_a_0_0_3_ADDRESS 0x649Cu    /* 00049C */
#define map_scenes_a_0_0_4_ADDRESS 0x651Cu    /* 00051C */
#define map_scenes_a_0_0_5_ADDRESS 0x659Cu    /* 00059C */
#define map_scenes_a_0_0_6_ADDRESS 0x661Cu    /* 00061C */
#define map_scenes_a_0_0_7_ADDRESS 0x669Cu    /* 00069C */
#define map_scenes_a_0_1_ADDRESS 0x671Cu    /* 00071C */
#define map_scenes_a_0_1_0_ADDRESS 0x672Cu    /* 00072C */
#define map_scenes_a_0_1_1_ADDRESS 0x67ACu    /* 0007AC */
#define map_scenes_a_0_1_2_ADDRESS 0x682Cu    /* 00082C */
#define map_scenes_a_0_1_3_ADDRESS 0x68ACu    /* 0008AC */
#define map_scenes_a_0_1_4_ADDRESS 0x692Cu    /* 00092C */
#define map_scenes_a_0_1_5_ADDRESS 0x69ACu    /* 0009AC */
#define map_scenes_a_0_1_6_ADDRESS 0x6A2Cu    /* 000A2C */
#define map_scenes_a_0_1_7_ADDRESS 0x6AACu    /* 000AAC */
#define map_scenes_a_0_2_ADDRESS 0x6B2Cu    /* 000B2C */
#define map_scenes_a_0_2_0_ADDRESS 0x6B3Cu    /* 000B3C */
#define map_scenes_a_0_2_1_ADDRESS 0x6BBCu    /* 000BBC */
#define map_scenes_a_0_2_2_ADDRESS 0x6C3Cu    /* 000C3C */
#define map_scenes_a_0_2_3_ADDRESS 0x6CBCu    /* 000CBC */
#define map_scenes_a_0_2_4_ADDRESS 0x6D3Cu    /* 000D3C */
#define map_scenes_a_0_2_5_ADDRESS 0x6DBCu    /* 000DBC */
#define map_scenes_a_0_2_6_ADDRESS 0x6E3Cu    /* 000E3C */
#define map_scenes_a_0_2_7_ADDRESS 0x6EBCu    /* 000EBC */
#define map_scenes_b_0_0_ADDRESS 0x6F3Cu    /* 000F3C */
#define map_scenes_b_0_0_0_ADDRESS 0x6F48u    /* 000F48 */
#define map_scenes_b_0_0_1_ADDRESS 0x6FC8u    /* 000FC8 */
#define map_scenes_b_0_0_2_ADDRESS 0x7048u    /* 001048 */
#define map_scenes_b_0_0_3_ADDRESS 0x70C8u    /* 0010C8 */
#define map_scenes_b_0_0_4_ADDRESS 0x7148u    /* 001148 */
#define map_scenes_b_0_0_5_ADDRESS 0x71C8u    /* 0011C8 */
#define map_scenes_a_high_1_0_ADDRESS 0x7248u    /* 001248 */
#define map_scenes_a_high_1_0_0_ADDRESS 0x724Eu    /* 00124E */
#define map_scenes_a_high_1_0_1_ADDRESS 0x72CEu    /* 0012CE */
#define map_scenes_a_high_1_0_2_ADDRESS 0x734Eu    /* 00134E */
#define map_scenes_a_high_1_1_ADDRESS 0x73CEu    /* 0013CE */
#define map_scenes_a_high_1_1_0_ADDRESS 0x73D2u    /* 0013D2 */
#define map_scenes_a_high_1_1_1_ADDRESS 0x7552u    /* 001552 */
#define map_scenes_b_high_1_0_ADDRESS 0x76D2u    /* 0016D2 */
#define map_scenes_b_high_1_0_0_ADDRESS 0x76D8u    /* 0016D8 */
#define map_scenes_b_high_1_0_1_ADDRESS 0x7758u    /* 001758 */
#define map_scenes_b_high_1_0_2_ADDRESS 0x77D8u    /* 0017D8 */
#define map_scenes_a_high_4_2_ADDRESS 0x7858u    /* 001858 */
#define map_scenes_a_high_4_2_0_ADDRESS 0x785Cu    /* 00185C */
#define map_scenes_a_high_4_2_1_ADDRESS 0x78DCu    /* 0018DC */
#define map_scenes_a_high_9_1_ADDRESS 0x795Cu    /* 00195C */
#define map_scenes_a_high_9_1_0_ADDRESS 0x7960u    /* 001960 */
#define map_scenes_a_high_9_1_1_ADDRESS 0x79E0u    /* 0019E0 */
#define map_scenes_a_high_9_3_ADDRESS 0x7A60u    /* 001A60 */
#define map_scenes_a_high_9_3_0_ADDRESS 0x7A64u    /* 001A64 */
#define map_scenes_a_high_9_3_1_ADDRESS 0x7AE4u    /* 001AE4 */
#define map_scenes_b_high_9_1_ADDRESS 0x7B64u    /* 001B64 */
#define map_scenes_b_high_9_1_0_ADDRESS 0x7B68u    /* 001B68 */
#define map_scenes_b_high_9_1_1_ADDRESS 0x7BE8u    /* 001BE8 */
#define map_scenes_b_high_9_3_ADDRESS 0x7C68u    /* 001C68 */
#define map_scenes_b_high_9_3_0_ADDRESS 0x7C6Cu    /* 001C6C */
#define map_scenes_b_high_9_3_1_ADDRESS 0x7CECu    /* 001CEC */
#define map_scenes_b_high_4_1_ADDRESS 0x7D6Cu    /* 001D6C */
#define map_scenes_b_high_4_1_0_ADDRESS 0x7D7Eu    /* 001D7E */
#define map_scenes_b_high_4_1_8_ADDRESS 0x7DFEu    /* 001DFE */
#define map_scenes_b_high_13_3_ADDRESS 0x7E7Eu    /* 001E7E */
#define map_scenes_b_high_13_3_0_ADDRESS 0x7E82u    /* 001E82 */
#define map_scenes_b_high_13_3_1_ADDRESS 0x7F02u    /* 001F02 */
#define map_scenes_b_high_13_3_1_rest_ADDRESS 0x7F82u    /* 001F82 */
#define map_scenes_b_high_13_3_1_fill_ADDRESS 0x7F92u    /* 001F92 */
#define map_scenes_a_high_2_0_ADDRESS 0x6000u    /* 002000 */
#define map_scenes_a_high_2_0_0_ADDRESS 0x600Eu    /* 00200E */
#define map_scenes_a_high_2_0_1_ADDRESS 0x608Eu    /* 00208E */
#define map_scenes_a_high_2_0_2_ADDRESS 0x610Eu    /* 00210E */
#define map_scenes_a_high_2_0_3_ADDRESS 0x618Eu    /* 00218E */
#define map_scenes_a_high_2_0_4_ADDRESS 0x620Eu    /* 00220E */
#define map_scenes_a_high_2_0_5_ADDRESS 0x628Eu    /* 00228E */
#define map_scenes_a_high_2_0_6_ADDRESS 0x630Eu    /* 00230E */
#define map_scenes_b_high_2_0_ADDRESS 0x638Eu    /* 00238E */
#define map_scenes_b_high_2_0_0_ADDRESS 0x639Cu    /* 00239C */
#define map_scenes_b_high_2_0_1_ADDRESS 0x641Cu    /* 00241C */
#define map_scenes_b_high_2_0_2_ADDRESS 0x649Cu    /* 00249C */
#define map_scenes_b_high_2_0_3_ADDRESS 0x651Cu    /* 00251C */
#define map_scenes_b_high_2_0_4_ADDRESS 0x659Cu    /* 00259C */
#define map_scenes_b_high_2_0_5_ADDRESS 0x661Cu    /* 00261C */
#define map_scenes_b_high_2_0_6_ADDRESS 0x669Cu    /* 00269C */
#define map_scenes_a_high_4_0_ADDRESS 0x671Cu    /* 00271C */
#define map_scenes_a_high_4_0_0_ADDRESS 0x672Eu    /* 00272E */
#define map_scenes_a_high_4_0_1_ADDRESS 0x67AEu    /* 0027AE */
#define map_scenes_a_high_4_0_2_ADDRESS 0x682Eu    /* 00282E */
#define map_scenes_a_high_4_0_3_ADDRESS 0x68AEu    /* 0028AE */
#define map_scenes_a_high_4_0_4_ADDRESS 0x692Eu    /* 00292E */
#define map_scenes_a_high_4_0_5_ADDRESS 0x69AEu    /* 0029AE */
#define map_scenes_a_high_4_0_6_ADDRESS 0x6A2Eu    /* 002A2E */
#define map_scenes_a_high_4_0_7_ADDRESS 0x6AAEu    /* 002AAE */
#define map_scenes_a_high_4_0_8_ADDRESS 0x6B2Eu    /* 002B2E */
#define map_scenes_b_high_4_0_ADDRESS 0x6BAEu    /* 002BAE */
#define map_scenes_b_high_4_0_0_ADDRESS 0x6BC0u    /* 002BC0 */
#define map_scenes_b_high_4_0_1_ADDRESS 0x6C40u    /* 002C40 */
#define map_scenes_b_high_4_0_2_ADDRESS 0x6CC0u    /* 002CC0 */
#define map_scenes_b_high_4_0_3_ADDRESS 0x6D40u    /* 002D40 */
#define map_scenes_b_high_4_0_4_ADDRESS 0x6DC0u    /* 002DC0 */
#define map_scenes_b_high_4_0_5_ADDRESS 0x6E40u    /* 002E40 */
#define map_scenes_b_high_4_0_6_ADDRESS 0x6EC0u    /* 002EC0 */
#define map_scenes_b_high_4_0_7_ADDRESS 0x6F40u    /* 002F40 */
#define map_scenes_b_high_4_0_8_ADDRESS 0x6FC0u    /* 002FC0 */
#define map_scenes_a_high_4_3_ADDRESS 0x7040u    /* 003040 */
#define map_scenes_a_high_4_3_0_ADDRESS 0x7044u    /* 003044 */
#define map_scenes_a_high_4_3_1_ADDRESS 0x70C4u    /* 0030C4 */
#define map_scenes_a_high_5_0_ADDRESS 0x7144u    /* 003144 */
#define map_scenes_a_high_5_0_0_ADDRESS 0x7156u    /* 003156 */
#define map_scenes_a_high_5_0_1_ADDRESS 0x71D6u    /* 0031D6 */
#define map_scenes_a_high_5_0_2_ADDRESS 0x7256u    /* 003256 */
#define map_scenes_a_high_5_0_3_ADDRESS 0x72D6u    /* 0032D6 */
#define map_scenes_a_high_5_0_4_ADDRESS 0x7356u    /* 003356 */
#define map_scenes_a_high_5_0_5_ADDRESS 0x73D6u    /* 0033D6 */
#define map_scenes_a_high_5_0_6_ADDRESS 0x7456u    /* 003456 */
#define map_scenes_a_high_5_0_7_ADDRESS 0x74D6u    /* 0034D6 */
#define map_scenes_a_high_5_0_8_ADDRESS 0x7556u    /* 003556 */
#define map_scenes_b_high_5_0_ADDRESS 0x75D6u    /* 0035D6 */
#define map_scenes_b_high_5_0_0_ADDRESS 0x75E8u    /* 0035E8 */
#define map_scenes_b_high_5_0_1_ADDRESS 0x7668u    /* 003668 */
#define map_scenes_b_high_5_0_2_ADDRESS 0x76E8u    /* 0036E8 */
#define map_scenes_b_high_5_0_3_ADDRESS 0x7768u    /* 003768 */
#define map_scenes_b_high_5_0_4_ADDRESS 0x77E8u    /* 0037E8 */
#define map_scenes_b_high_5_0_5_ADDRESS 0x7868u    /* 003868 */
#define map_scenes_b_high_5_0_6_ADDRESS 0x78E8u    /* 0038E8 */
#define map_scenes_b_high_5_0_7_ADDRESS 0x7968u    /* 003968 */
#define map_scenes_b_high_5_0_8_ADDRESS 0x79E8u    /* 0039E8 */
#define map_scenes_a_high_9_2_ADDRESS 0x7A68u    /* 003A68 */
#define map_scenes_a_high_9_2_0_ADDRESS 0x7A6Cu    /* 003A6C */
#define map_scenes_a_high_9_2_1_ADDRESS 0x7AECu    /* 003AEC */
#define map_scenes_b_high_12_1_ADDRESS 0x7B6Cu    /* 003B6C */
#define map_scenes_b_high_12_1_0_ADDRESS 0x7B70u    /* 003B70 */
#define map_scenes_b_high_12_1_1_ADDRESS 0x7BF0u    /* 003BF0 */
#define map_scenes_a_high_0_0_ADDRESS 0x7C70u    /* 003C70 */
#define map_scenes_a_high_0_0_0_ADDRESS 0x7C74u    /* 003C74 */
#define map_scenes_a_high_0_0_1_ADDRESS 0x7CF4u    /* 003CF4 */
#define map_scenes_b_high_0_0_ADDRESS 0x7D74u    /* 003D74 */
#define map_scenes_b_high_0_0_0_ADDRESS 0x7D78u    /* 003D78 */
#define map_scenes_b_high_0_0_1_ADDRESS 0x7DF8u    /* 003DF8 */
#define map_scenes_b_high_11_1_ADDRESS 0x7E78u    /* 003E78 */
#define map_scenes_b_high_11_1_0_ADDRESS 0x7E7Cu    /* 003E7C */
#define map_scenes_b_high_11_1_1_ADDRESS 0x7EFCu    /* 003EFC */
#define map_scenes_b_high_11_1_1_rest_ADDRESS 0x7F7Cu    /* 003F7C */
#define map_scenes_b_high_11_1_1_fill_ADDRESS 0x7F8Cu    /* 003F8C */
#define map_scenes_a_high_8_0_ADDRESS 0x6000u    /* 004000 */
#define map_scenes_a_high_8_0_0_ADDRESS 0x6014u    /* 004014 */
#define map_scenes_a_high_8_0_1_ADDRESS 0x6094u    /* 004094 */
#define map_scenes_a_high_8_0_2_ADDRESS 0x6114u    /* 004114 */
#define map_scenes_a_high_8_0_3_ADDRESS 0x6194u    /* 004194 */
#define map_scenes_a_high_8_0_4_ADDRESS 0x6214u    /* 004214 */
#define map_scenes_a_high_8_0_5_ADDRESS 0x6294u    /* 004294 */
#define map_scenes_a_high_8_0_6_ADDRESS 0x6314u    /* 004314 */
#define map_scenes_a_high_8_0_7_ADDRESS 0x6394u    /* 004394 */
#define map_scenes_a_high_8_0_8_ADDRESS 0x6414u    /* 004414 */
#define map_scenes_a_high_8_0_9_ADDRESS 0x6494u    /* 004494 */
#define map_scenes_b_high_8_0_ADDRESS 0x6514u    /* 004514 */
#define map_scenes_b_high_8_0_0_ADDRESS 0x6528u    /* 004528 */
#define map_scenes_b_high_8_0_1_ADDRESS 0x65A8u    /* 0045A8 */
#define map_scenes_b_high_8_0_2_ADDRESS 0x6628u    /* 004628 */
#define map_scenes_b_high_8_0_3_ADDRESS 0x66A8u    /* 0046A8 */
#define map_scenes_b_high_8_0_4_ADDRESS 0x6728u    /* 004728 */
#define map_scenes_b_high_8_0_5_ADDRESS 0x67A8u    /* 0047A8 */
#define map_scenes_b_high_8_0_6_ADDRESS 0x6828u    /* 004828 */
#define map_scenes_b_high_8_0_7_ADDRESS 0x68A8u    /* 0048A8 */
#define map_scenes_b_high_8_0_8_ADDRESS 0x6928u    /* 004928 */
#define map_scenes_b_high_8_0_9_ADDRESS 0x69A8u    /* 0049A8 */
#define map_scenes_a_high_9_0_ADDRESS 0x6A28u    /* 004A28 */
#define map_scenes_a_high_9_0_0_ADDRESS 0x6A40u    /* 004A40 */
#define map_scenes_a_high_9_0_1_ADDRESS 0x6AC0u    /* 004AC0 */
#define map_scenes_a_high_9_0_2_ADDRESS 0x6B40u    /* 004B40 */
#define map_scenes_a_high_9_0_3_ADDRESS 0x6BC0u    /* 004BC0 */
#define map_scenes_a_high_9_0_4_ADDRESS 0x6C40u    /* 004C40 */
#define map_scenes_a_high_9_0_5_ADDRESS 0x6CC0u    /* 004CC0 */
#define map_scenes_a_high_9_0_6_ADDRESS 0x6D40u    /* 004D40 */
#define map_scenes_a_high_9_0_7_ADDRESS 0x6DC0u    /* 004DC0 */
#define map_scenes_a_high_9_0_8_ADDRESS 0x6E40u    /* 004E40 */
#define map_scenes_a_high_9_0_9_ADDRESS 0x6EC0u    /* 004EC0 */
#define map_scenes_a_high_9_0_10_ADDRESS 0x6F40u    /* 004F40 */
#define map_scenes_a_high_9_0_11_ADDRESS 0x6FC0u    /* 004FC0 */
#define map_scenes_b_high_9_0_ADDRESS 0x7040u    /* 005040 */
#define map_scenes_b_high_9_0_0_ADDRESS 0x7058u    /* 005058 */
#define map_scenes_b_high_9_0_1_ADDRESS 0x70D8u    /* 0050D8 */
#define map_scenes_b_high_9_0_2_ADDRESS 0x7158u    /* 005158 */
#define map_scenes_b_high_9_0_3_ADDRESS 0x71D8u    /* 0051D8 */
#define map_scenes_b_high_9_0_4_ADDRESS 0x7258u    /* 005258 */
#define map_scenes_b_high_9_0_5_ADDRESS 0x72D8u    /* 0052D8 */
#define map_scenes_b_high_9_0_6_ADDRESS 0x7358u    /* 005358 */
#define map_scenes_b_high_9_0_7_ADDRESS 0x73D8u    /* 0053D8 */
#define map_scenes_b_high_9_0_8_ADDRESS 0x7458u    /* 005458 */
#define map_scenes_b_high_9_0_9_ADDRESS 0x74D8u    /* 0054D8 */
#define map_scenes_b_high_9_0_10_ADDRESS 0x7558u    /* 005558 */
#define map_scenes_b_high_9_0_11_ADDRESS 0x75D8u    /* 0055D8 */
#define map_scenes_a_high_12_0_ADDRESS 0x7658u    /* 005658 */
#define map_scenes_a_high_12_0_0_ADDRESS 0x7670u    /* 005670 */
#define map_scenes_a_high_12_0_1_ADDRESS 0x76F0u    /* 0056F0 */
#define map_scenes_a_high_12_0_2_ADDRESS 0x7770u    /* 005770 */
#define map_scenes_a_high_12_0_3_ADDRESS 0x77F0u    /* 0057F0 */
#define map_scenes_a_high_12_0_4_ADDRESS 0x7870u    /* 005870 */
#define map_scenes_a_high_12_0_5_ADDRESS 0x78F0u    /* 0058F0 */
#define map_scenes_a_high_12_0_6_ADDRESS 0x7970u    /* 005970 */
#define map_scenes_a_high_12_0_7_ADDRESS 0x79F0u    /* 0059F0 */
#define map_scenes_a_high_12_0_8_ADDRESS 0x7A70u    /* 005A70 */
#define map_scenes_a_high_12_0_9_ADDRESS 0x7AF0u    /* 005AF0 */
#define map_scenes_a_high_12_0_10_ADDRESS 0x7B70u    /* 005B70 */
#define map_scenes_a_high_12_0_11_ADDRESS 0x7BF0u    /* 005BF0 */
#define map_scenes_b_high_13_2_ADDRESS 0x7C70u    /* 005C70 */
#define map_scenes_b_high_13_2_0_ADDRESS 0x7C76u    /* 005C76 */
#define map_scenes_b_high_13_2_1_ADDRESS 0x7CF6u    /* 005CF6 */
#define map_scenes_b_high_13_2_2_ADDRESS 0x7D76u    /* 005D76 */
#define map_scenes_a_high_11_2_ADDRESS 0x7DF6u    /* 005DF6 */
#define map_scenes_a_high_11_2_0_ADDRESS 0x7DFAu    /* 005DFA */
#define map_scenes_a_high_11_2_1_ADDRESS 0x7EFAu    /* 005EFA */
#define map_scenes_a_high_11_2_1_rest_ADDRESS 0x7FFAu    /* 005FFA */
#define map_scenes_b_high_12_0_ADDRESS 0x6000u    /* 006000 */
#define map_scenes_b_high_12_0_0_ADDRESS 0x6018u    /* 006018 */
#define map_scenes_b_high_12_0_1_ADDRESS 0x6098u    /* 006098 */
#define map_scenes_b_high_12_0_2_ADDRESS 0x6118u    /* 006118 */
#define map_scenes_b_high_12_0_3_ADDRESS 0x6198u    /* 006198 */
#define map_scenes_b_high_12_0_4_ADDRESS 0x6218u    /* 006218 */
#define map_scenes_b_high_12_0_5_ADDRESS 0x6298u    /* 006298 */
#define map_scenes_b_high_12_0_6_ADDRESS 0x6318u    /* 006318 */
#define map_scenes_b_high_12_0_7_ADDRESS 0x6398u    /* 006398 */
#define map_scenes_b_high_12_0_8_ADDRESS 0x6418u    /* 006418 */
#define map_scenes_b_high_12_0_9_ADDRESS 0x6498u    /* 006498 */
#define map_scenes_b_high_12_0_10_ADDRESS 0x6518u    /* 006518 */
#define map_scenes_b_high_12_0_11_ADDRESS 0x6598u    /* 006598 */
#define map_scenes_a_high_7_0_ADDRESS 0x6618u    /* 006618 */
#define map_scenes_a_high_7_0_0_ADDRESS 0x661Eu    /* 00661E */
#define map_scenes_a_high_7_0_1_ADDRESS 0x6A1Eu    /* 006A1E */
#define map_scenes_a_high_7_0_2_ADDRESS 0x6E1Eu    /* 006E1E */
#define map_scenes_b_high_7_0_ADDRESS 0x721Eu    /* 00721E */
#define map_scenes_b_high_7_0_0_ADDRESS 0x7224u    /* 007224 */
#define map_scenes_b_high_7_0_1_ADDRESS 0x72A4u    /* 0072A4 */
#define map_scenes_b_high_7_0_2_ADDRESS 0x7324u    /* 007324 */
#define map_scenes_b_high_10_0_ADDRESS 0x73A4u    /* 0073A4 */
#define map_scenes_b_high_10_0_0_ADDRESS 0x73B6u    /* 0073B6 */
#define map_scenes_b_high_10_0_1_ADDRESS 0x7436u    /* 007436 */
#define map_scenes_b_high_10_0_2_ADDRESS 0x74B6u    /* 0074B6 */
#define map_scenes_b_high_10_0_3_ADDRESS 0x7536u    /* 007536 */
#define map_scenes_b_high_10_0_4_ADDRESS 0x75B6u    /* 0075B6 */
#define map_scenes_b_high_10_0_5_ADDRESS 0x7636u    /* 007636 */
#define map_scenes_b_high_10_0_6_ADDRESS 0x76B6u    /* 0076B6 */
#define map_scenes_b_high_10_0_7_ADDRESS 0x7736u    /* 007736 */
#define map_scenes_b_high_10_0_8_ADDRESS 0x77B6u    /* 0077B6 */
#define map_scenes_a_high_5_1_ADDRESS 0x7836u    /* 007836 */
#define map_scenes_a_high_5_1_0_ADDRESS 0x783Au    /* 00783A */
#define map_scenes_a_high_5_1_1_ADDRESS 0x78BAu    /* 0078BA */
#define map_scenes_a_high_9_4_ADDRESS 0x793Au    /* 00793A */
#define map_scenes_a_high_9_4_0_ADDRESS 0x793Eu    /* 00793E */
#define map_scenes_a_high_9_4_1_ADDRESS 0x79BEu    /* 0079BE */
#define map_scenes_a_high_13_1_ADDRESS 0x7A3Eu    /* 007A3E */
#define map_scenes_a_high_13_1_0_ADDRESS 0x7A4Eu    /* 007A4E */
#define map_scenes_a_high_13_1_1_ADDRESS 0x7ACEu    /* 007ACE */
#define map_scenes_a_high_13_1_2_ADDRESS 0x7B4Eu    /* 007B4E */
#define map_scenes_a_high_13_1_3_ADDRESS 0x7BCEu    /* 007BCE */
#define map_scenes_a_high_13_1_4_ADDRESS 0x7C4Eu    /* 007C4E */
#define map_scenes_a_high_13_1_5_ADDRESS 0x7CCEu    /* 007CCE */
#define map_scenes_a_high_13_1_6_ADDRESS 0x7D4Eu    /* 007D4E */
#define map_scenes_a_high_13_1_7_ADDRESS 0x7DCEu    /* 007DCE */
#define map_scenes_a_high_13_3_ADDRESS 0x7E4Eu    /* 007E4E */
#define map_scenes_a_high_13_3_0_ADDRESS 0x7E52u    /* 007E52 */
#define map_scenes_a_high_13_3_1_ADDRESS 0x7ED2u    /* 007ED2 */
#define map_scenes_a_high_13_3_1_rest_ADDRESS 0x7F52u    /* 007F52 */
#define map_scenes_a_high_13_3_1_fill_ADDRESS 0x7F62u    /* 007F62 */
#define map_scenes_a_high_10_0_ADDRESS 0x6000u    /* 008000 */
#define map_scenes_a_high_10_0_0_ADDRESS 0x6004u    /* 008004 */
#define map_scenes_a_high_10_0_1_ADDRESS 0x6084u    /* 008084 */
#define block_scenes_b_high_7_0_ADDRESS 0x6104u    /* 008104 */
#define block_scenes_b_high_7_0_rest_ADDRESS 0x642Eu    /* 00842E */
#define block_scenes_a_high_13_1_ADDRESS 0x6464u    /* 008464 */
#define block_scenes_a_high_13_1_rest_ADDRESS 0x7298u    /* 009298 */
#define map_scenes_a_high_13_0_ADDRESS 0x72BCu    /* 0092BC */
#define map_scenes_a_high_13_0_0_ADDRESS 0x72C0u    /* 0092C0 */
#define map_scenes_a_high_13_0_1_ADDRESS 0x7340u    /* 009340 */
#define map_scenes_b_high_13_0_ADDRESS 0x73C0u    /* 0093C0 */
#define map_scenes_b_high_13_0_0_ADDRESS 0x73C4u    /* 0093C4 */
#define map_scenes_b_high_13_0_1_ADDRESS 0x74C4u    /* 0094C4 */
#define block_scenes_a_high_13_0_ADDRESS 0x75C4u    /* 0095C4 */
#define map_scenes_a_0_3_ADDRESS 0x79A2u    /* 0099A2 */
#define map_scenes_a_0_3_0_ADDRESS 0x79A6u    /* 0099A6 */
#define map_scenes_a_0_3_1_ADDRESS 0x7A26u    /* 009A26 */
#define block_scenes_a_0_3_ADDRESS 0x7AA6u    /* 009AA6 */
#define block_scenes_a_0_3_rest_ADDRESS 0x7C20u    /* 009C20 */
#define map_scenes_a_high_3_0_ADDRESS 0x7C32u    /* 009C32 */
#define map_scenes_a_high_3_0_0_ADDRESS 0x7C36u    /* 009C36 */
#define map_scenes_a_high_3_0_1_ADDRESS 0x7CB6u    /* 009CB6 */
#define block_scenes_a_high_3_0_ADDRESS 0x7D36u    /* 009D36 */
#define map_scenes_a_high_14_0_ADDRESS 0x7E44u    /* 009E44 */
#define map_scenes_a_high_14_0_0_ADDRESS 0x7E48u    /* 009E48 */
#define map_scenes_a_high_14_0_1_ADDRESS 0x7EC8u    /* 009EC8 */
#define map_scenes_a_high_14_0_1_rest_ADDRESS 0x7F48u    /* 009F48 */
#define map_scenes_a_high_14_0_1_fill_ADDRESS 0x7F58u    /* 009F58 */
#define map_scenes_a_high_14_0_1_rest_2_ADDRESS 0x7FA4u    /* 009FA4 */
#define map_scenes_a_high_14_0_1_fill_2_ADDRESS 0x7FB6u    /* 009FB6 */
#define map_scenes_a_high_14_0_1_rest_3_ADDRESS 0x7FD0u    /* 009FD0 */
#define map_scenes_a_high_14_0_1_fill_3_ADDRESS 0x7FE2u    /* 009FE2 */
#define block_scenes_a_high_10_0_ADDRESS 0x6000u    /* 00A000 */
#define block_scenes_a_high_10_0_rest_ADDRESS 0x64B6u    /* 00A4B6 */
#define block_scenes_b_high_10_0_ADDRESS 0x64C8u    /* 00A4C8 */
#define block_scenes_a_high_13_3_ADDRESS 0x77A0u    /* 00B7A0 */
#define map_scenes_a_high_13_2_ADDRESS 0x7998u    /* 00B998 */
#define map_scenes_a_high_13_2_0_ADDRESS 0x799Cu    /* 00B99C */
#define map_scenes_a_high_13_2_1_ADDRESS 0x7A1Cu    /* 00BA1C */
#define block_scenes_a_high_13_2_ADDRESS 0x7A9Cu    /* 00BA9C */
#define block_scenes_b_high_13_1_ADDRESS 0x7C04u    /* 00BC04 */
#define block_scenes_b_high_13_1_fill_ADDRESS 0x7F64u    /* 00BF64 */
#define block_scenes_a_high_9_0_ADDRESS 0x6000u    /* 00C000 */
#define block_scenes_b_high_13_2_ADDRESS 0x6DDAu    /* 00CDDA */
#define block_scenes_b_high_13_3_ADDRESS 0x72C6u    /* 00D2C6 */
#define block_scenes_a_high_14_0_ADDRESS 0x75CCu    /* 00D5CC */
#define block_scenes_b_high_14_0_ADDRESS 0x7A3Au    /* 00DA3A */
#define map_scenes_b_high_13_1_ADDRESS 0x7B00u    /* 00DB00 */
#define map_scenes_b_high_13_1_0_ADDRESS 0x7B10u    /* 00DB10 */
#define map_scenes_b_high_13_1_1_ADDRESS 0x7B90u    /* 00DB90 */
#define map_scenes_b_high_13_1_2_ADDRESS 0x7C10u    /* 00DC10 */
#define map_scenes_b_high_13_1_3_ADDRESS 0x7C90u    /* 00DC90 */
#define map_scenes_b_high_13_1_4_ADDRESS 0x7D10u    /* 00DD10 */
#define map_scenes_b_high_13_1_5_ADDRESS 0x7D90u    /* 00DD90 */
#define map_scenes_b_high_13_1_6_ADDRESS 0x7E10u    /* 00DE10 */
#define map_scenes_b_high_13_1_7_ADDRESS 0x7E90u    /* 00DE90 */
#define map_scenes_b_high_13_1_7_rest_ADDRESS 0x7F10u    /* 00DF10 */
#define map_scenes_b_high_13_1_7_fill_ADDRESS 0x7F20u    /* 00DF20 */
#define map_scenes_b_high_13_1_7_rest_2_ADDRESS 0x7F5Cu    /* 00DF5C */
#define map_scenes_b_high_13_1_7_rest_3_ADDRESS 0x7F5Eu    /* 00DF5E */
#define map_scenes_b_high_13_1_7_fill_2_ADDRESS 0x7FDEu    /* 00DFDE */
#define block_scenes_b_high_12_0_ADDRESS 0x6000u    /* 00E000 */
#define block_scenes_a_high_4_3_ADDRESS 0x72EAu    /* 00F2EA */
#define block_scenes_a_high_9_2_ADDRESS 0x76C8u    /* 00F6C8 */
#define block_scenes_b_high_9_3_ADDRESS 0x79CEu    /* 00F9CE */
#define block_scenes_a_high_9_3_ADDRESS 0x7D88u    /* 00FD88 */
#define map_scenes_a_2_0_ADDRESS 0x7F5Cu    /* 00FF5C */
#define map_scenes_a_2_0_0_ADDRESS 0x7F5Eu    /* 00FF5E */
#define map_scenes_a_2_0_0_rest_ADDRESS 0x7FDEu    /* 00FFDE */
#define map_scenes_a_2_0_0_fill_ADDRESS 0x7FEEu    /* 00FFEE */
#define block_scenes_a_high_12_0_ADDRESS 0x6000u    /* 010000 */
#define block_scenes_a_high_11_2_ADDRESS 0x7476u    /* 011476 */
#define block_scenes_a_high_11_2_rest_ADDRESS 0x76C8u    /* 0116C8 */
#define block_scenes_b_high_11_1_ADDRESS 0x778Eu    /* 01178E */
#define block_scenes_a_high_4_2_ADDRESS 0x7A94u    /* 011A94 */
#define map_scenes_b_1_0_ADDRESS 0x7F14u    /* 011F14 */
#define map_scenes_b_1_0_0_ADDRESS 0x7F16u    /* 011F16 */
#define map_scenes_b_1_0_0_rest_ADDRESS 0x7F96u    /* 011F96 */
#define map_scenes_b_1_0_0_fill_ADDRESS 0x7FA6u    /* 011FA6 */
#define block_scenes_b_high_9_0_ADDRESS 0x6000u    /* 012000 */
#define block_scenes_b_high_0_0_ADDRESS 0x7D40u    /* 013D40 */
#define block_scenes_a_high_5_1_ADDRESS 0x7DF4u    /* 013DF4 */
#define block_scenes_a_high_9_4_ADDRESS 0x7EF0u    /* 013EF0 */
#define block_scenes_a_high_9_4_rest_ADDRESS 0x7FECu    /* 013FEC */
#define block_scenes_a_high_9_4_fill_ADDRESS 0x7FFEu    /* 013FFE */
#define block_scenes_a_high_4_0_ADDRESS 0x6000u    /* 014000 */
#define block_scenes_a_high_4_0_rest_ADDRESS 0x6C06u    /* 014C06 */
#define block_scenes_b_high_4_0_ADDRESS 0x6C18u    /* 014C18 */
#define tile_pictures_0_tile_picture_ADDRESS 0x7A94u    /* 015A94 */
#define block_scenes_b_high_12_1_ADDRESS 0x7C8Bu    /* 015C8B */
#define block_scenes_b_high_12_1_rest_ADDRESS 0x7FEBu    /* 015FEB */
#define block_scenes_b_high_12_1_fill_ADDRESS 0x7FFDu    /* 015FFD */
#define block_scenes_a_high_8_0_ADDRESS 0x6000u    /* 016000 */
#define block_scenes_b_high_8_0_ADDRESS 0x6A32u    /* 016A32 */
#define block_scenes_a_high_5_0_ADDRESS 0x7626u    /* 017626 */
#define block_scenes_a_high_5_0_fill_ADDRESS 0x7F5Cu    /* 017F5C */
#define block_scenes_a_high_2_0_ADDRESS 0x6000u    /* 018000 */
#define block_scenes_b_high_2_0_ADDRESS 0x6AC2u    /* 018AC2 */
#define block_scenes_b_high_1_0_ADDRESS 0x7596u    /* 019596 */
#define block_scenes_b_high_9_1_ADDRESS 0x7BD8u    /* 019BD8 */
#define map_scenes_b_high_14_0_ADDRESS 0x7ECCu    /* 019ECC */
#define map_scenes_b_high_14_0_0_ADDRESS 0x7ED0u    /* 019ED0 */
#define map_scenes_b_high_14_0_1_ADDRESS 0x7F50u    /* 019F50 */
#define map_scenes_b_high_14_0_1_rest_ADDRESS 0x7FD0u    /* 019FD0 */
#define map_scenes_b_high_14_0_1_fill_ADDRESS 0x7FE0u    /* 019FE0 */
#define block_scenes_a_0_2_ADDRESS 0x6000u    /* 01A000 */
#define block_scenes_a_high_11_1_ADDRESS 0x69B4u    /* 01A9B4 */
#define block_scenes_b_high_5_0_ADDRESS 0x6D5Cu    /* 01AD5C */
#define block_scenes_a_high_1_1_ADDRESS 0x7452u    /* 01B452 */
#define block_scenes_a_high_1_1_rest_ADDRESS 0x7C7Au    /* 01BC7A */
#define block_scenes_a_high_9_1_ADDRESS 0x7C8Cu    /* 01BC8C */
#define block_scenes_a_high_9_1_fill_ADDRESS 0x7F26u    /* 01BF26 */
#define block_scenes_a_0_1_ADDRESS 0x6000u    /* 01C000 */
#define block_scenes_a_1_0_ADDRESS 0x753Cu    /* 01D53C */
#define block_scenes_a_0_0_ADDRESS 0x6000u    /* 01E000 */
#define block_scenes_b_0_0_ADDRESS 0x71B8u    /* 01F1B8 */
#define block_scenes_a_high_0_0_ADDRESS 0x7C0Eu    /* 01FC0E */
#define block_scenes_a_high_0_0_rest_ADDRESS 0x7FC8u    /* 01FFC8 */
#define block_scenes_a_high_0_0_fill_ADDRESS 0x7FFEu    /* 01FFFE */
#define speech_balloon_follow_fill_ADDRESS 0x7A34u    /* 021A34 */
#define bonus_1_intro_states_ADDRESS 0x7B80u    /* 021B80 */
#define bonus_1_contest_states_ADDRESS 0x7B86u    /* 021B86 */
#define bonus_1_contest_start_steps_ADDRESS 0x7B8Cu    /* 021B8C */
#define bonus_1_contest_play_steps_ADDRESS 0x7B90u    /* 021B90 */
#define bonus_1_finish_steps_ADDRESS 0x7B94u    /* 021B94 */
#define bonus_1_flight_table_ADDRESS 0x7B9Eu    /* 021B9E */
#define bonus_1_fly_table_ADDRESS 0x7BA2u    /* 021BA2 */
#define bonus_1_popped_table_ADDRESS 0x7BAAu    /* 021BAA */
#define bonus_pan_steps_ADDRESS 0x7BB2u    /* 021BB2 */
#define bonus_hint_blink_steps_ADDRESS 0x7BB6u    /* 021BB6 */
#define bonus_title_steps_ADDRESS 0x7BBEu    /* 021BBE */
#define bonus_2_intro_try_table_ADDRESS 0x7D18u    /* 021D18 */
#define bonus_2_player_table_ADDRESS 0x7D2Cu    /* 021D2C */
#define bonus_results_states_ADDRESS 0x7D8Du    /* 021D8D */
#define bonus_result_text_ADDRESS 0x7DBCu    /* 021DBC */
#define bonus_result_player_text_ADDRESS 0x7DCFu    /* 021DCF */
#define bonus_result_absent_text_ADDRESS 0x7DE3u    /* 021DE3 */
#define bonus_result_box_tiles_ADDRESS 0x7DF1u    /* 021DF1 */
#define wrestler_states_ADDRESS 0x7E2Fu    /* 021E2F */
#define wrestler_beaten_actions_ADDRESS 0x7E3Fu    /* 021E3F */
#define wrestler_knocked_down_actions_ADDRESS 0x7E43u    /* 021E43 */
#define wrestler_flinch_actions_ADDRESS 0x7E49u    /* 021E49 */
#define wrestler_entrance_actions_ADDRESS 0x7E4Du    /* 021E4D */
#define wrestler_punch_actions_ADDRESS 0x7E5Du    /* 021E5D */
#define wrestler_guard_actions_ADDRESS 0x7E63u    /* 021E63 */
#define wrestler_jump_actions_ADDRESS 0x7E65u    /* 021E65 */
#define wrestler_idle_actions_ADDRESS 0x7E6Du    /* 021E6D */
#define wrestler_take_hit_table_ADDRESS 0x7EE1u    /* 021EE1 */
#define wrestler_take_hit_table_fill_ADDRESS 0x7EE5u    /* 021EE5 */
#define stage_7_boss_helper_throw_end_fill_ADDRESS 0x71FFu    /* 0231FF */
#define stage_7_boss_helper_update_table_ADDRESS 0x7510u    /* 023510 */
#define name_entry_picture_blocks_fill_ADDRESS 0x767Au    /* 02367A */
#define name_entry_draw_picture_table_ADDRESS 0x7683u    /* 023683 */
#define put_sprite_table_ADDRESS 0x76EAu    /* 0236EA */
#define staff_roll_titles_rest_ADDRESS 0x7766u    /* 023766 */
#define staff_roll_titles_rest_2_ADDRESS 0x7769u    /* 023769 */
#define staff_roll_titles_rest_3_ADDRESS 0x7779u    /* 023779 */
#define staff_roll_titles_rest_4_ADDRESS 0x778Bu    /* 02378B */
#define staff_roll_titles_rest_5_ADDRESS 0x779Cu    /* 02379C */
#define staff_roll_titles_rest_6_ADDRESS 0x77B4u    /* 0237B4 */
#define staff_roll_titles_rest_7_ADDRESS 0x77C7u    /* 0237C7 */
#define staff_roll_titles_rest_8_ADDRESS 0x77E0u    /* 0237E0 */
#define staff_roll_titles_rest_9_ADDRESS 0x77EBu    /* 0237EB */
#define staff_roll_titles_rest_10_ADDRESS 0x77FDu    /* 0237FD */
#define staff_roll_titles_rest_11_ADDRESS 0x780Eu    /* 02380E */
#define staff_roll_titles_rest_12_ADDRESS 0x781Eu    /* 02381E */
#define staff_roll_titles_rest_13_ADDRESS 0x782Fu    /* 02382F */
#define staff_roll_titles_rest_14_ADDRESS 0x7840u    /* 023840 */
#define staff_roll_titles_rest_15_ADDRESS 0x7851u    /* 023851 */
#define staff_roll_titles_rest_16_ADDRESS 0x7862u    /* 023862 */
#define staff_roll_titles_rest_17_ADDRESS 0x786Fu    /* 02386F */
#define staff_roll_titles_rest_18_ADDRESS 0x787Cu    /* 02387C */
#define staff_roll_titles_rest_19_ADDRESS 0x7889u    /* 023889 */
#define staff_roll_titles_rest_20_ADDRESS 0x788Cu    /* 02388C */
#define staff_roll_names_rest_ADDRESS 0x78E2u    /* 0238E2 */
#define staff_roll_names_rest_2_ADDRESS 0x78E5u    /* 0238E5 */
#define staff_roll_names_rest_3_ADDRESS 0x78FCu    /* 0238FC */
#define staff_roll_names_rest_4_ADDRESS 0x7907u    /* 023907 */
#define staff_roll_names_rest_5_ADDRESS 0x791Au    /* 02391A */
#define staff_roll_names_rest_6_ADDRESS 0x7927u    /* 023927 */
#define staff_roll_names_rest_7_ADDRESS 0x7932u    /* 023932 */
#define staff_roll_names_rest_8_ADDRESS 0x794Au    /* 02394A */
#define staff_roll_names_rest_9_ADDRESS 0x7956u    /* 023956 */
#define staff_roll_names_rest_10_ADDRESS 0x7962u    /* 023962 */
#define staff_roll_names_rest_11_ADDRESS 0x796Fu    /* 02396F */
#define staff_roll_names_rest_12_ADDRESS 0x7984u    /* 023984 */
#define staff_roll_names_rest_13_ADDRESS 0x799Du    /* 02399D */
#define staff_roll_names_rest_14_ADDRESS 0x79A7u    /* 0239A7 */
#define staff_roll_names_rest_15_ADDRESS 0x79B2u    /* 0239B2 */
#define staff_roll_names_rest_16_ADDRESS 0x79BFu    /* 0239BF */
#define staff_roll_names_rest_17_ADDRESS 0x79C8u    /* 0239C8 */
#define staff_roll_names_rest_18_ADDRESS 0x79D1u    /* 0239D1 */
#define staff_roll_names_rest_19_ADDRESS 0x79DEu    /* 0239DE */
#define staff_roll_names_rest_20_ADDRESS 0x79EEu    /* 0239EE */
#define staff_roll_names_rest_21_ADDRESS 0x7A0Au    /* 023A0A */
#define staff_roll_names_rest_22_ADDRESS 0x7A0Du    /* 023A0D */
#define stage_7_boss_states_ADDRESS 0x7A13u    /* 023A13 */
#define stage_7_boss_beaten_actions_ADDRESS 0x7A21u    /* 023A21 */
#define stage_7_boss_knocked_down_actions_ADDRESS 0x7A25u    /* 023A25 */
#define stage_7_boss_flinch_actions_ADDRESS 0x7A2Bu    /* 023A2B */
#define stage_7_boss_entrance_actions_ADDRESS 0x7A2Fu    /* 023A2F */
#define stage_7_boss_attack_actions_ADDRESS 0x7A3Du    /* 023A3D */
#define stage_7_boss_charge_actions_ADDRESS 0x7A43u    /* 023A43 */
#define stage_7_boss_jump_away_actions_ADDRESS 0x7A47u    /* 023A47 */
#define stage_7_boss_order_throw_child_ADDRESS 0x7AE9u    /* 023AE9 */
#define stage_7_boss_helper_states_ADDRESS 0x7AF1u    /* 023AF1 */
#define stage_7_boss_helper_move_actions_ADDRESS 0x7B01u    /* 023B01 */
#define stage_7_boss_helper_attack_actions_ADDRESS 0x7B05u    /* 023B05 */
#define stage_7_boss_helper_distances_fill_ADDRESS 0x7B21u    /* 023B21 */
#define game_texts_address_fill_ADDRESS 0x6023u    /* 024023 */
#define wave_sine_fill_ADDRESS 0x7558u    /* 025558 */
#define stage_1_end_states_ADDRESS 0x7700u    /* 025700 */
#define stage_2_end_states_ADDRESS 0x770Au    /* 02570A */
#define stage_end_jump_away_steps_ADDRESS 0x771Au    /* 02571A */
#define stage_end_jumper_steps_ADDRESS 0x771Eu    /* 02571E */
#define stage_5_end_states_ADDRESS 0x7726u    /* 025726 */
#define stage_6_end_states_ADDRESS 0x7732u    /* 025732 */
#define stage_6_wake_states_ADDRESS 0x7738u    /* 025738 */
#define post_bonus_2_scene_states_ADDRESS 0x7740u    /* 025740 */
#define stage_7_scene_states_ADDRESS 0x774Au    /* 02574A */
#define stage_7_scene_steps_ADDRESS 0x7752u    /* 025752 */
#define stage_7_end_states_ADDRESS 0x775Au    /* 02575A */
#define stage_8_start_states_ADDRESS 0x7766u    /* 025766 */
#define stage_8_start_run_players_states_ADDRESS 0x7774u    /* 025774 */
#define stage_8_end_states_ADDRESS 0x7780u    /* 025780 */
#define stage_8_end_run_family_states_ADDRESS 0x7790u    /* 025790 */
#define stage_8_end_walker_actions_ADDRESS 0x779Au    /* 02579A */
#define stage_8_end_extra_actions_ADDRESS 0x77A2u    /* 0257A2 */
#define stage_8_end_slow_extra_actions_ADDRESS 0x77AAu    /* 0257AA */
#define stage_8_end_maggie_taker_actions_ADDRESS 0x77B2u    /* 0257B2 */
#define absent_player_blanks_table_ADDRESS 0x797Eu    /* 02597E */
#define absent_player_blanks_table_2_ADDRESS 0x798Au    /* 02598A */
#define dream_wave_grow_steps_ADDRESS 0x7996u    /* 025996 */
#define dream_wave_fade_out_steps_ADDRESS 0x799Cu    /* 02599C */
#define game_texts_0_ADDRESS 0x7A0Au    /* 025A0A */
#define game_texts_2_ADDRESS 0x7A30u    /* 025A30 */
#define game_texts_3_ADDRESS 0x7B05u    /* 025B05 */
#define game_texts_4_ADDRESS 0x7B0Fu    /* 025B0F */
#define game_texts_5_ADDRESS 0x7B14u    /* 025B14 */
#define game_texts_6_ADDRESS 0x7B24u    /* 025B24 */
#define game_texts_7_ADDRESS 0x7B33u    /* 025B33 */
#define game_texts_8_ADDRESS 0x7B38u    /* 025B38 */
#define game_texts_9_ADDRESS 0x7B3Eu    /* 025B3E */
#define game_texts_10_ADDRESS 0x7B4Eu    /* 025B4E */
#define game_texts_11_ADDRESS 0x7B59u    /* 025B59 */
#define game_texts_12_ADDRESS 0x7BB2u    /* 025BB2 */
#define game_texts_13_ADDRESS 0x7BDEu    /* 025BDE */
#define game_texts_14_ADDRESS 0x7BE8u    /* 025BE8 */
#define game_texts_15_ADDRESS 0x7CB7u    /* 025CB7 */
#define game_texts_16_ADDRESS 0x7D7Du    /* 025D7D */
#define game_texts_17_ADDRESS 0x7DD9u    /* 025DD9 */
#define game_texts_18_ADDRESS 0x7E35u    /* 025E35 */
#define game_texts_18_fill_ADDRESS 0x7E43u    /* 025E43 */
#define camera_y_free_up_fill_ADDRESS 0x63C5u    /* 0263C5 */
#define title_card_count_frames_fill_ADDRESS 0x6F1Du    /* 026F1D */
#define boss_door_stage_8_set_up_fill_ADDRESS 0x7903u    /* 027903 */
#define boss_door_stage_8_table_ADDRESS 0x7908u    /* 027908 */
#define cemetery_scroll_update_table_ADDRESS 0x792Au    /* 02792A */
#define stage_5_scroll_table_ADDRESS 0x7936u    /* 027936 */
#define stage_5_scroll_parts_ADDRESS 0x7948u    /* 027948 */
#define stage_7_scroll_table_ADDRESS 0x79F2u    /* 0279F2 */
#define screen_shake_table_ADDRESS 0x79F6u    /* 0279F6 */
#define screen_shake_by_kind_table_ADDRESS 0x79FAu    /* 0279FA */
#define camera_check_x_table_ADDRESS 0x7A13u    /* 027A13 */
#define camera_check_x_table_2_ADDRESS 0x7A1Du    /* 027A1D */
#define camera_check_y_table_ADDRESS 0x7A27u    /* 027A27 */
#define camera_check_y_table_2_ADDRESS 0x7A2Fu    /* 027A2F */
#define camera_next_entry_table_ADDRESS 0x7A43u    /* 027A43 */
#define camera_scale_move_table_ADDRESS 0x7A53u    /* 027A53 */
#define krusty_balloon_states_ADDRESS 0x7C64u    /* 027C64 */
#define krusty_balloon_beaten_actions_ADDRESS 0x7C70u    /* 027C70 */
#define krusty_balloon_knocked_up_actions_ADDRESS 0x7C78u    /* 027C78 */
#define krusty_balloon_come_in_actions_ADDRESS 0x7C7Cu    /* 027C7C */
#define krusty_balloon_attack_actions_ADDRESS 0x7C88u    /* 027C88 */
#define krusty_balloon_volley_actions_ADDRESS 0x7C8Eu    /* 027C8E */
#define krusty_balloon_stomping_actions_ADDRESS 0x7C98u    /* 027C98 */
#define krusty_balloon_throw_directions_ADDRESS 0x7C9Cu    /* 027C9C */
#define krusty_balloon_wobble_steps_ADDRESS 0x7CA2u    /* 027CA2 */
#define krusty_balloon_rebound_steps_ADDRESS 0x7CAAu    /* 027CAA */
#define krusty_balloon_throw_z_speeds_rest_ADDRESS 0x7D38u    /* 027D38 */
#define krusty_balloon_shot_states_ADDRESS 0x7D3Au    /* 027D3A */
#define title_cards_by_scene_ADDRESS 0x7D42u    /* 027D42 */
#define stage_1_title_card_steps_ADDRESS 0x7D5Au    /* 027D5A */
#define stage_2_title_card_steps_ADDRESS 0x7D60u    /* 027D60 */
#define stage_3_title_card_steps_ADDRESS 0x7D66u    /* 027D66 */
#define stage_4_title_card_steps_ADDRESS 0x7D6Cu    /* 027D6C */
#define stage_5_title_card_steps_ADDRESS 0x7D72u    /* 027D72 */
#define stage_6_title_card_steps_ADDRESS 0x7D78u    /* 027D78 */
#define stage_7_title_card_steps_ADDRESS 0x7D7Eu    /* 027D7E */
#define stage_8_title_card_steps_ADDRESS 0x7D86u    /* 027D86 */
#define stage_1_title_text_ADDRESS 0x7D8Cu    /* 027D8C */
#define stage_2_title_text_ADDRESS 0x7DADu    /* 027DAD */
#define stage_3_title_text_ADDRESS 0x7DC4u    /* 027DC4 */
#define stage_4_title_text_ADDRESS 0x7DF0u    /* 027DF0 */
#define stage_5_title_text_ADDRESS 0x7E09u    /* 027E09 */
#define stage_6_title_text_ADDRESS 0x7E27u    /* 027E27 */
#define stage_7_title_text_ADDRESS 0x7E3Du    /* 027E3D */
#define stage_8_title_text_ADDRESS 0x7E53u    /* 027E53 */
#define story_1_states_ADDRESS 0x7ED1u    /* 027ED1 */
#define story_1_rise_steps_ADDRESS 0x7EDDu    /* 027EDD */
#define story_1_pan_steps_ADDRESS 0x7EE3u    /* 027EE3 */
#define story_1_end_steps_ADDRESS 0x7EE7u    /* 027EE7 */
#define story_1_family_scripts_ADDRESS 0x7EFDu    /* 027EFD */
#define story_1_marge_steps_ADDRESS 0x7F05u    /* 027F05 */
#define story_1_homer_steps_ADDRESS 0x7F09u    /* 027F09 */
#define story_1_bart_steps_ADDRESS 0x7F0Fu    /* 027F0F */
#define story_1_bart_steps_rest_ADDRESS 0x7F11u    /* 027F11 */
#define story_1_bart_steps_rest_2_ADDRESS 0x7F12u    /* 027F12 */
#define story_1_lisa_steps_ADDRESS 0x7F13u    /* 027F13 */
#define story_1_lisa_steps_rest_ADDRESS 0x7F14u    /* 027F14 */
#define story_1_runner_scripts_ADDRESS 0x7F17u    /* 027F17 */
#define story_1_runner_scripts_rest_ADDRESS 0x7F18u    /* 027F18 */
#define story_1_runner_scripts_rest_2_ADDRESS 0x7F19u    /* 027F19 */
#define story_1_runner_scripts_rest_3_ADDRESS 0x7F1Au    /* 027F1A */
#define story_1_smithers_steps_ADDRESS 0x7F1Du    /* 027F1D */
#define story_1_smithers_steps_rest_ADDRESS 0x7F1Eu    /* 027F1E */
#define story_1_smithers_steps_rest_2_ADDRESS 0x7F1Fu    /* 027F1F */
#define story_1_smithers_steps_rest_3_ADDRESS 0x7F20u    /* 027F20 */
#define story_1_smithers_steps_rest_4_ADDRESS 0x7F23u    /* 027F23 */
#define story_1_smithers_steps_rest_5_ADDRESS 0x7F24u    /* 027F24 */
#define story_1_smithers_steps_rest_6_ADDRESS 0x7F25u    /* 027F25 */
#define story_1_smithers_steps_rest_7_ADDRESS 0x7F26u    /* 027F26 */
#define story_1_first_goon_steps_ADDRESS 0x7F27u    /* 027F27 */
#define story_1_first_goon_steps_rest_ADDRESS 0x7F29u    /* 027F29 */
#define story_1_first_goon_steps_rest_2_ADDRESS 0x7F2Au    /* 027F2A */
#define story_1_first_goon_steps_rest_3_ADDRESS 0x7F2Bu    /* 027F2B */
#define story_1_first_goon_steps_rest_4_ADDRESS 0x7F2Cu    /* 027F2C */
#define story_1_second_goon_steps_ADDRESS 0x7F2Fu    /* 027F2F */
#define story_1_second_goon_steps_rest_ADDRESS 0x7F30u    /* 027F30 */
#define story_1_second_goon_steps_rest_2_ADDRESS 0x7F31u    /* 027F31 */
#define story_1_second_goon_steps_rest_3_ADDRESS 0x7F32u    /* 027F32 */
#define story_1_second_goon_steps_rest_4_ADDRESS 0x7F35u    /* 027F35 */
#define story_1_second_goon_steps_rest_5_ADDRESS 0x7F36u    /* 027F36 */
#define story_1_text_steps_ADDRESS 0x7F37u    /* 027F37 */
#define story_1_text_steps_rest_ADDRESS 0x7F38u    /* 027F38 */
#define story_1_text_steps_rest_2_ADDRESS 0x7F3Bu    /* 027F3B */
#define story_1_text_steps_rest_3_ADDRESS 0x7F3Cu    /* 027F3C */
#define story_1_text_steps_rest_4_ADDRESS 0x7F3Du    /* 027F3D */
#define story_1_text_steps_rest_5_ADDRESS 0x7F3Eu    /* 027F3E */
#define story_1_dropped_object_steps_ADDRESS 0x7F3Fu    /* 027F3F */
#define story_1_dropped_object_steps_rest_ADDRESS 0x7F41u    /* 027F41 */
#define story_1_dropped_object_steps_rest_2_ADDRESS 0x7F42u    /* 027F42 */
#define story_1_marge_start_ADDRESS 0x7F43u    /* 027F43 */
#define story_1_homer_start_ADDRESS 0x7F4Du    /* 027F4D */
#define story_1_bart_start_ADDRESS 0x7F57u    /* 027F57 */
#define story_1_lisa_start_ADDRESS 0x7F61u    /* 027F61 */
#define story_1_text_start_ADDRESS 0x7F6Bu    /* 027F6B */
#define story_1_smithers_start_ADDRESS 0x7F75u    /* 027F75 */
#define story_1_first_goon_start_ADDRESS 0x7F7Fu    /* 027F7F */
#define story_1_second_goon_start_ADDRESS 0x7F89u    /* 027F89 */
#define story_1_second_goon_start_rest_ADDRESS 0x7F93u    /* 027F93 */
#define story_1_street_object_start_1_ADDRESS 0x7F9Du    /* 027F9D */
#define story_1_street_object_start_1_rest_ADDRESS 0x7FA7u    /* 027FA7 */
#define story_1_street_object_start_2_ADDRESS 0x7FB1u    /* 027FB1 */
#define story_1_street_text_start_ADDRESS 0x7FBBu    /* 027FBB */
#define story_1_redraw_text_start_ADDRESS 0x7FC5u    /* 027FC5 */
#define story_1_pan_text_start_ADDRESS 0x7FCFu    /* 027FCF */
#define story_1_last_view_text_start_ADDRESS 0x7FD9u    /* 027FD9 */
#define story_1_smithers_drop_start_ADDRESS 0x7FE3u    /* 027FE3 */
#define boss_door_states_ADDRESS 0x7FEDu    /* 027FED */
#define boss_door_stage_8_states_ADDRESS 0x7FF3u    /* 027FF3 */
#define cemetery_umbrella_goon_float_down_fill_ADDRESS 0x75C1u    /* 0295C1 */
#define goon_base_object_setup_box_ADDRESS 0x7800u    /* 029800 */
#define goon_close_grabber_set_up_enemy_behaviour_ADDRESS 0x7808u    /* 029808 */
#define goon_striker_set_up_enemy_behaviour_ADDRESS 0x7860u    /* 029860 */
#define goon_keeps_away_set_up_enemy_behaviour_ADDRESS 0x78B8u    /* 0298B8 */
#define hat_goon_brawler_set_up_enemy_behaviour_ADDRESS 0x7910u    /* 029910 */
#define cemetery_umbrella_goon_float_down_table_ADDRESS 0x7974u    /* 029974 */
#define hat_goon_brawler_start_table_ADDRESS 0x7980u    /* 029980 */
#define hat_goon_brawler_start_table_2_ADDRESS 0x798Cu    /* 02998C */
#define goon_keeps_away_start_table_ADDRESS 0x7998u    /* 029998 */
#define goon_weaken_if_marked_table_ADDRESS 0x79A4u    /* 0299A4 */
#define goon_base_object_setup_ADDRESS 0x79B0u    /* 0299B0 */
#define goon_entrance_body_box_ADDRESS 0x79B6u    /* 0299B6 */
#define hat_goon_entrance_box_ADDRESS 0x79BEu    /* 0299BE */
#define shovel_goon_rush_in_swing_box_ADDRESS 0x79C6u    /* 0299C6 */
#define goon_balloon_states_ADDRESS 0x79CEu    /* 0299CE */
#define goon_balloon_setup_ADDRESS 0x79D6u    /* 0299D6 */
#define goon_balloon_rise_table_ADDRESS 0x79DCu    /* 0299DC */
#define goon_descent_steps_ADDRESS 0x79E8u    /* 0299E8 */
#define goon_descent_child_ADDRESS 0x79ECu    /* 0299EC */
#define goon_descent_land_table_ADDRESS 0x7A14u    /* 029A14 */
#define hat_goon_run_across_steps_ADDRESS 0x7A20u    /* 029A20 */
#define hat_goon_run_across_running_table_ADDRESS 0x7A28u    /* 029A28 */
#define umbrella_goon_rush_in_set_up_table_ADDRESS 0x7A34u    /* 029A34 */
#define shovel_goon_rush_in_steps_ADDRESS 0x7A40u    /* 029A40 */
#define shovel_goon_rush_in_swing_table_ADDRESS 0x7A44u    /* 029A44 */
#define goon_striker_rush_in_set_up_table_ADDRESS 0x7A50u    /* 029A50 */
#define goon_rush_in_steps_ADDRESS 0x7A5Cu    /* 029A5C */
#define goon_rush_in_run_table_ADDRESS 0x7A60u    /* 029A60 */
#define goon_from_back_steps_ADDRESS 0x7A6Cu    /* 029A6C */
#define goon_from_back_wait_table_ADDRESS 0x7A7Au    /* 029A7A */
#define hat_goon_waiting_step_table_ADDRESS 0x7A92u    /* 029A92 */
#define hat_goon_waiting_step_forward_table_ADDRESS 0x7A9Cu    /* 029A9C */
#define goon_walk_in_setup_ADDRESS 0x7AA8u    /* 029AA8 */
#define goon_walk_in_step_table_ADDRESS 0x7ABEu    /* 029ABE */
#define goon_entrance_end_table_ADDRESS 0x7AC6u    /* 029AC6 */
#define goon_delayed_steps_ADDRESS 0x7AE2u    /* 029AE2 */
#define shovel_goon_step_out_states_ADDRESS 0x7AE8u    /* 029AE8 */
#define shovel_goon_step_out_steps_ADDRESS 0x7AF4u    /* 029AF4 */
#define hat_goon_step_out_states_ADDRESS 0x7AFEu    /* 029AFE */
#define goon_step_out_states_ADDRESS 0x7B0Au    /* 029B0A */
#define goon_step_out_step_table_ADDRESS 0x7B30u    /* 029B30 */
#define goon_walk_up_start_table_ADDRESS 0x7B3Cu    /* 029B3C */
#define goon_walk_up_step_table_ADDRESS 0x7B48u    /* 029B48 */
#define goon_walk_up_reach_floor_table_ADDRESS 0x7B50u    /* 029B50 */
#define goon_striker_from_side_set_up_table_ADDRESS 0x7B5Cu    /* 029B5C */
#define goon_from_side_step_table_ADDRESS 0x7B6Cu    /* 029B6C */
#define goon_from_side_walk_table_ADDRESS 0x7B72u    /* 029B72 */
#define goon_run_in_step_table_ADDRESS 0x7B86u    /* 029B86 */
#define goon_wait_on_floor_table_ADDRESS 0x7B8Cu    /* 029B8C */
#define hat_goon_jump_in_step_table_ADDRESS 0x7BB0u    /* 029BB0 */
#define goon_fall_to_floor_table_ADDRESS 0x7BBCu    /* 029BBC */
#define goon_drop_step_table_ADDRESS 0x7BCCu    /* 029BCC */
#define goon_drop_show_table_ADDRESS 0x7BD4u    /* 029BD4 */
#define umbrella_goon_float_down_step_table_ADDRESS 0x7BE8u    /* 029BE8 */
#define goon_strike_hit_box_ADDRESS 0x7BEEu    /* 029BEE */
#define goon_action_body_box_ADDRESS 0x7BF6u    /* 029BF6 */
#define goon_quick_strike_hit_box_ADDRESS 0x7BFEu    /* 029BFE */
#define goon_quick_strike_2_hit_box_ADDRESS 0x7C06u    /* 029C06 */
#define goon_jump_attack_fall_box_ADDRESS 0x7C0Eu    /* 029C0E */
#define goon_dash_strike_hit_box_ADDRESS 0x7C16u    /* 029C16 */
#define goon_approach_strike_hit_box_ADDRESS 0x7C1Eu    /* 029C1E */
#define goon_approach_strike_hit_box_rest_ADDRESS 0x7C26u    /* 029C26 */
#define goon_approach_strike_steps_ADDRESS 0x7C4Eu    /* 029C4E */
#define goon_back_off_steps_ADDRESS 0x7C5Au    /* 029C5A */
#define goon_dash_strike_steps_ADDRESS 0x7C5Eu    /* 029C5E */
#define goon_keep_distance_steps_ADDRESS 0x7C68u    /* 029C68 */
#define goon_wait_then_strike_steps_ADDRESS 0x7C70u    /* 029C70 */
#define goon_wait_then_strike_2_steps_ADDRESS 0x7C7Fu    /* 029C7F */
#define goon_quick_strike_steps_ADDRESS 0x7C89u    /* 029C89 */
#define goon_quick_strike_2_steps_ADDRESS 0x7C91u    /* 029C91 */
#define goon_jump_attack_steps_ADDRESS 0x7C99u    /* 029C99 */
#define goon_jump_up_or_grab_steps_ADDRESS 0x7CC3u    /* 029CC3 */
#define goon_grab_steps_ADDRESS 0x7CCBu    /* 029CCB */
#define bomb_goon_setup_box_ADDRESS 0x7CD7u    /* 029CD7 */
#define bomb_goon_set_up_enemy_behaviour_ADDRESS 0x7CDFu    /* 029CDF */
#define hat_goon_set_up_enemy_behaviour_ADDRESS 0x7D37u    /* 029D37 */
#define umbrella_goon_set_up_enemy_behaviour_ADDRESS 0x7D8Fu    /* 029D8F */
#define shovel_goon_set_up_enemy_behaviour_ADDRESS 0x7DE7u    /* 029DE7 */
#define goon_grab_squeeze_table_ADDRESS 0x7E3Fu    /* 029E3F */
#define bomb_goon_setup_ADDRESS 0x7E4Bu    /* 029E4B */
#define bomb_goon_start_table_ADDRESS 0x7E51u    /* 029E51 */
#define hat_goon_setup_ADDRESS 0x7E5Du    /* 029E5D */
#define hat_goon_start_table_ADDRESS 0x7E63u    /* 029E63 */
#define umbrella_goon_setup_ADDRESS 0x7E6Fu    /* 029E6F */
#define umbrella_goon_start_table_ADDRESS 0x7E75u    /* 029E75 */
#define shovel_goon_setup_ADDRESS 0x7E81u    /* 029E81 */
#define armed_goon_body_box_ADDRESS 0x7E87u    /* 029E87 */
#define shovel_goon_close_hit_box_ADDRESS 0x7E8Fu    /* 029E8F */
#define shovel_goon_hit_box_ADDRESS 0x7E97u    /* 029E97 */
#define shovel_goon_far_hit_box_ADDRESS 0x7E9Fu    /* 029E9F */
#define goon_strike_and_run_hit_box_ADDRESS 0x7EA7u    /* 029EA7 */
#define umbrella_goon_hit_box_ADDRESS 0x7EAFu    /* 029EAF */
#define umbrella_goon_charge_hit_box_ADDRESS 0x7EB7u    /* 029EB7 */
#define umbrella_goon_quick_hit_box_ADDRESS 0x7EBFu    /* 029EBF */
#define umbrella_goon_long_hit_box_ADDRESS 0x7EC7u    /* 029EC7 */
#define bomb_goon_throw_steps_ADDRESS 0x7ECFu    /* 029ECF */
#define bomb_goon_throw_release_child_ADDRESS 0x7ED5u    /* 029ED5 */
#define shovel_goon_close_strike_steps_ADDRESS 0x7EDBu    /* 029EDB */
#define shovel_goon_far_strike_steps_ADDRESS 0x7EEAu    /* 029EEA */
#define shovel_goon_strike_steps_ADDRESS 0x7EF9u    /* 029EF9 */
#define umbrella_goon_quick_strike_steps_ADDRESS 0x7F03u    /* 029F03 */
#define umbrella_goon_long_strike_steps_ADDRESS 0x7F0Bu    /* 029F0B */
#define umbrella_goon_strike_steps_ADDRESS 0x7F13u    /* 029F13 */
#define umbrella_goon_charge_steps_ADDRESS 0x7F1Bu    /* 029F1B */
#define goon_strike_and_run_steps_ADDRESS 0x7F21u    /* 029F21 */
#define hat_goon_throw_hat_steps_ADDRESS 0x7F27u    /* 029F27 */
#define hat_goon_throw_release_child_ADDRESS 0x7F2Fu    /* 029F2F */
#define goon_bomb_setup_box_ADDRESS 0x7F35u    /* 029F35 */
#define goon_bomb_fly_box_ADDRESS 0x7F3Du    /* 029F3D */
#define goon_bomb_fly_box_rest_ADDRESS 0x7F45u    /* 029F45 */
#define goon_bomb_setup_ADDRESS 0x7F55u    /* 029F55 */
#define goon_bomb_explosion_end_table_ADDRESS 0x7F5Bu    /* 029F5B */
#define goon_bomb_run_in_step_table_ADDRESS 0x7F67u    /* 029F67 */
#define goon_bomb_run_in_throw_child_ADDRESS 0x7F6Du    /* 029F6D */
#define goon_from_below_body_box_ADDRESS 0x7F73u    /* 029F73 */
#define goon_from_below_entrance_box_ADDRESS 0x7F7Bu    /* 029F7B */
#define goon_bomb_run_in_end_box_ADDRESS 0x7F83u    /* 029F83 */
#define goon_jump_in_step_table_ADDRESS 0x7F9Fu    /* 029F9F */
#define goon_jump_in_land_table_ADDRESS 0x7FA3u    /* 029FA3 */
#define goon_from_below_step_table_ADDRESS 0x7FB3u    /* 029FB3 */
#define goon_from_below_land_table_ADDRESS 0x7FB7u    /* 029FB7 */
#define cemetery_umbrella_goon_xs_fill_ADDRESS 0x7FFFu    /* 029FFF */
#define fat_goon_drop_route_update_fill_ADDRESS 0x6224u    /* 02A224 */
#define police_car_driving_off_fill_ADDRESS 0x7518u    /* 02B518 */
#define fat_goon_object_setup_box_ADDRESS 0x75E0u    /* 02B5E0 */
#define fat_goon_behaviour_ADDRESS 0x75E8u    /* 02B5E8 */
#define moe_spawner_update_table_ADDRESS 0x7640u    /* 02B640 */
#define fat_goon_object_setup_ADDRESS 0x764Cu    /* 02B64C */
#define fat_goon_base_object_setup_box_ADDRESS 0x7652u    /* 02B652 */
#define fat_goon_grabber_setup_enemy_behaviour_ADDRESS 0x765Au    /* 02B65A */
#define fat_goon_puncher_setup_enemy_behaviour_ADDRESS 0x76B2u    /* 02B6B2 */
#define fat_goon_jumper_setup_enemy_behaviour_ADDRESS 0x770Au    /* 02B70A */
#define kind_85_setup_enemy_behaviour_ADDRESS 0x7762u    /* 02B762 */
#define unused_become_fat_goon_table_ADDRESS 0x77BAu    /* 02B7BA */
#define fat_goon_base_object_setup_ADDRESS 0x77C6u    /* 02B7C6 */
#define fat_goon_grabber_start_table_ADDRESS 0x77CCu    /* 02B7CC */
#define fat_goon_weaken_table_ADDRESS 0x77D8u    /* 02B7D8 */
#define fat_goon_jumper_start_table_ADDRESS 0x77E4u    /* 02B7E4 */
#define descent_balloon_setup_box_ADDRESS 0x77F0u    /* 02B7F0 */
#define kind_85_start_table_ADDRESS 0x77F8u    /* 02B7F8 */
#define fat_goon_waiting_table_ADDRESS 0x7804u    /* 02B804 */
#define fat_goon_drop_route_update_table_ADDRESS 0x7810u    /* 02B810 */
#define fat_goon_drop_walk_up_table_ADDRESS 0x782Au    /* 02B82A */
#define fat_goon_entrance_to_floor_steps_table_ADDRESS 0x7836u    /* 02B836 */
#define fat_goon_reach_any_floor_table_ADDRESS 0x783Eu    /* 02B83E */
#define fat_goon_entrance_steps_table_ADDRESS 0x7862u    /* 02B862 */
#define fat_goon_entrance_walk_out_table_ADDRESS 0x786Eu    /* 02B86E */
#define fat_goon_walk_in_step_handlers_ADDRESS 0x787Au    /* 02B87A */
#define fat_goon_walk_in_end_table_ADDRESS 0x787Eu    /* 02B87E */
#define fat_goon_from_back_step_handlers_ADDRESS 0x788Au    /* 02B88A */
#define fat_goon_from_back_wait_table_ADDRESS 0x7898u    /* 02B898 */
#define fat_goon_thrower_step_handlers_ADDRESS 0x78A4u    /* 02B8A4 */
#define fat_goon_thrower_pick_up_child_ADDRESS 0x78ACu    /* 02B8AC */
#define fat_goon_entrance_end_table_ADDRESS 0x78B4u    /* 02B8B4 */
#define fat_goon_delayed_step_handlers_ADDRESS 0x78D0u    /* 02B8D0 */
#define fat_goon_descent_states_ADDRESS 0x78D6u    /* 02B8D6 */
#define fat_goon_descent_step_handlers_ADDRESS 0x78E2u    /* 02B8E2 */
#define fat_goon_descent_child_ADDRESS 0x78E6u    /* 02B8E6 */
#define descent_balloon_states_ADDRESS 0x78F6u    /* 02B8F6 */
#define descent_balloon_setup_ADDRESS 0x78FEu    /* 02B8FE */
#define fat_goon_body_box_ADDRESS 0x7904u    /* 02B904 */
#define fat_goon_bump_move_box_ADDRESS 0x790Cu    /* 02B90C */
#define fat_goon_walk_up_hit_box_ADDRESS 0x7914u    /* 02B914 */
#define fat_goon_body_slam_fall_box_ADDRESS 0x791Cu    /* 02B91C */
#define fat_goon_strike_hit_box_ADDRESS 0x7924u    /* 02B924 */
#define fat_goon_reach_strike_hit_box_ADDRESS 0x792Cu    /* 02B92C */
#define fat_goon_heavy_strike_hit_box_ADDRESS 0x7934u    /* 02B934 */
#define fat_goon_heavy_strike_hit_box_rest_ADDRESS 0x793Cu    /* 02B93C */
#define fat_goon_reach_strike_steps_ADDRESS 0x7979u    /* 02B979 */
#define fat_goon_idle_action_steps_ADDRESS 0x7983u    /* 02B983 */
#define fat_goon_heavy_strike_steps_ADDRESS 0x7985u    /* 02B985 */
#define fat_goon_grab_steps_ADDRESS 0x798Du    /* 02B98D */
#define fat_goon_squeeze_again_table_ADDRESS 0x7999u    /* 02B999 */
#define fat_goon_jump_in_steps_table_ADDRESS 0x79A9u    /* 02B9A9 */
#define fat_goon_jump_in_land_table_ADDRESS 0x79ADu    /* 02B9AD */
#define fat_goon_from_below_steps_table_ADDRESS 0x79BDu    /* 02B9BD */
#define fat_goon_from_below_land_table_ADDRESS 0x79C1u    /* 02B9C1 */
#define cleared_wave_child_1_ADDRESS 0x79C5u    /* 02B9C5 */
#define cleared_wave_child_2_ADDRESS 0x79CDu    /* 02B9CD */
#define cleared_wave_child_3_ADDRESS 0x79D5u    /* 02B9D5 */
#define cleared_wave_child_4_ADDRESS 0x79DDu    /* 02B9DD */
#define cleared_wave_wait_table_ADDRESS 0x79E5u    /* 02B9E5 */
#define scroll_lock_table_ADDRESS 0x79E9u    /* 02B9E9 */
#define object_15_spawn_lists_3_ADDRESS 0x7A4Cu    /* 02BA4C */
#define object_15_spawn_lists_9_ADDRESS 0x7A84u    /* 02BA84 */
#define object_15_spawn_lists_4_ADDRESS 0x7A9Cu    /* 02BA9C */
#define object_15_spawn_lists_5_ADDRESS 0x7AD4u    /* 02BAD4 */
#define object_15_spawn_lists_0_ADDRESS 0x7AF4u    /* 02BAF4 */
#define object_15_spawn_lists_1_ADDRESS 0x7B34u    /* 02BB34 */
#define object_15_spawn_lists_2_ADDRESS 0x7B6Cu    /* 02BB6C */
#define object_15_spawn_lists_10_ADDRESS 0x7B9Cu    /* 02BB9C */
#define object_15_spawn_lists_6_ADDRESS 0x7BDCu    /* 02BBDC */
#define object_15_spawn_lists_7_ADDRESS 0x7C64u    /* 02BC64 */
#define object_15_spawn_lists_8_ADDRESS 0x7CCCu    /* 02BCCC */
#define object_15_spawn_lists_11_ADDRESS 0x7CF4u    /* 02BCF4 */
#define object_15_spawn_lists_12_ADDRESS 0x7D2Cu    /* 02BD2C */
#define moe_spawner_setup_box_ADDRESS 0x7D4Cu    /* 02BD4C */
#define burger_eater_setup_box_ADDRESS 0x7D54u    /* 02BD54 */
#define bleeding_gums_murphy_setup_box_ADDRESS 0x7D5Cu    /* 02BD5C */
#define caged_gorilla_leaper_setup_box_ADDRESS 0x7D64u    /* 02BD64 */
#define moe_spawner_states_ADDRESS 0x7D6Cu    /* 02BD6C */
#define moe_spawner_setup_ADDRESS 0x7D72u    /* 02BD72 */
#define moe_spawner_object_child_ADDRESS 0x7D78u    /* 02BD78 */
#define burger_eater_states_ADDRESS 0x7D80u    /* 02BD80 */
#define burger_eater_setup_ADDRESS 0x7D88u    /* 02BD88 */
#define burger_eater_drop_food_child_ADDRESS 0x7D8Eu    /* 02BD8E */
#define drink_vendor_states_ADDRESS 0x7D96u    /* 02BD96 */
#define drink_vendor_setup_ADDRESS 0x7DA2u    /* 02BDA2 */
#define drink_vendor_let_out_child_ADDRESS 0x7DA8u    /* 02BDA8 */
#define krustyland_door_states_ADDRESS 0x7DB0u    /* 02BDB0 */
#define krustyland_door_setup_ADDRESS 0x7DBCu    /* 02BDBC */
#define caged_gorilla_leaper_states_ADDRESS 0x7DFDu    /* 02BDFD */
#define caged_gorilla_leaper_child_ADDRESS 0x7E0Bu    /* 02BE0B */
#define caged_gorilla_leaper_setup_ADDRESS 0x7E13u    /* 02BE13 */
#define prop_states_ADDRESS 0x7E19u    /* 02BE19 */
#define prop_setup_ADDRESS 0x7E1Du    /* 02BE1D */
#define poster_states_ADDRESS 0x7E53u    /* 02BE53 */
#define poster_setup_ADDRESS 0x7E57u    /* 02BE57 */
#define poster_pair_states_ADDRESS 0x7E5Du    /* 02BE5D */
#define poster_pair_setup_ADDRESS 0x7E61u    /* 02BE61 */
#define poster_pair_child_ADDRESS 0x7E67u    /* 02BE67 */
#define bleeding_gums_murphy_states_ADDRESS 0x7E6Fu    /* 02BE6F */
#define bleeding_gums_murphy_setup_ADDRESS 0x7E79u    /* 02BE79 */
#define dream_ball_fling_states_ADDRESS 0x7E7Fu    /* 02BE7F */
#define dream_ball_fling_setup_ADDRESS 0x7E83u    /* 02BE83 */
#define cemetery_piece_setup_box_ADDRESS 0x7E99u    /* 02BE99 */
#define cemetery_piece_states_ADDRESS 0x7EA1u    /* 02BEA1 */
#define cemetery_piece_setup_ADDRESS 0x7ED1u    /* 02BED1 */
#define floor_blocker_setup_box_ADDRESS 0x7ED7u    /* 02BED7 */
#define floor_blocker_states_ADDRESS 0x7EDFu    /* 02BEDF */
#define floor_blocker_setup_ADDRESS 0x7EE5u    /* 02BEE5 */
#define floor_blocker_parts_ADDRESS 0x7EEBu    /* 02BEEB */
#define floor_blocker_shape_1_ADDRESS 0x7EF3u    /* 02BEF3 */
#define floor_blocker_shape_2_ADDRESS 0x7EFFu    /* 02BEFF */
#define floor_blocker_shape_3_ADDRESS 0x7F0Bu    /* 02BF0B */
#define goon_hat_throw_setup_box_ADDRESS 0x7F17u    /* 02BF17 */
#define goon_hat_throw_setup_box_rest_ADDRESS 0x7F1Fu    /* 02BF1F */
#define goon_hat_throw_setup_ADDRESS 0x7F3Fu    /* 02BF3F */
#define police_car_setup_box_ADDRESS 0x7F45u    /* 02BF45 */
#define police_car_setup_box_rest_ADDRESS 0x7F4Du    /* 02BF4D */
#define police_car_states_ADDRESS 0x7F51u    /* 02BF51 */
#define police_car_hit_step_handlers_ADDRESS 0x7F5Du    /* 02BF5D */
#define police_car_setup_ADDRESS 0x7F63u    /* 02BF63 */
#define police_car_arrivals_fill_ADDRESS 0x7F71u    /* 02BF71 */
#define rabbit_stand_fill_ADDRESS 0x7A14u    /* 02DA14 */
#define obstacle_settle_box_ADDRESS 0x7A98u    /* 02DA98 */
#define obstacle_knocked_box_ADDRESS 0x7AA0u    /* 02DAA0 */
#define carried_obstacle_fly_box_ADDRESS 0x7AA8u    /* 02DAA8 */
#define throwable_setup_box_ADDRESS 0x7AB0u    /* 02DAB0 */
#define throwable_throw_box_ADDRESS 0x7AB8u    /* 02DAB8 */
#define throwable_rebound_box_ADDRESS 0x7AC0u    /* 02DAC0 */
#define cemetery_obstacle_setup_box_ADDRESS 0x7AC8u    /* 02DAC8 */
#define timed_throwable_throw_box_ADDRESS 0x7AD0u    /* 02DAD0 */
#define obstacle_smash_box_ADDRESS 0x7AD8u    /* 02DAD8 */
#define obstacle_smash_box_rest_ADDRESS 0x7AE0u    /* 02DAE0 */
#define shaking_scenery_setup_box_ADDRESS 0x7AE8u    /* 02DAE8 */
#define boulder_setup_box_ADDRESS 0x7AF0u    /* 02DAF0 */
#define gorge_rock_setup_box_ADDRESS 0x7AF8u    /* 02DAF8 */
#define charging_scenery_setup_box_ADDRESS 0x7B00u    /* 02DB00 */
#define platform_scenery_setup_box_ADDRESS 0x7B08u    /* 02DB08 */
#define platform_scenery_launch_box_ADDRESS 0x7B10u    /* 02DB10 */
#define moes_street_scenery_riser_setup_box_ADDRESS 0x7B18u    /* 02DB18 */
#define running_animal_thrown_box_ADDRESS 0x7B20u    /* 02DB20 */
#define bouncing_throwable_setup_box_ADDRESS 0x7B28u    /* 02DB28 */
#define bouncing_throwable_throw_box_ADDRESS 0x7B30u    /* 02DB30 */
#define dreamland_obstacle_setup_box_ADDRESS 0x7B38u    /* 02DB38 */
#define dreamland_obstacle_setup_box_rest_ADDRESS 0x7B40u    /* 02DB40 */
#define cemetery_obstacle_states_ADDRESS 0x7B44u    /* 02DB44 */
#define cemetery_obstacle_broken_step_handlers_ADDRESS 0x7B4Cu    /* 02DB4C */
#define cemetery_obstacle_break_child_ADDRESS 0x7B52u    /* 02DB52 */
#define cemetery_obstacle_setup_ADDRESS 0x7BA8u    /* 02DBA8 */
#define cemetery_obstacle_setup_rest_ADDRESS 0x7BAEu    /* 02DBAE */
#define heavy_obstacle_states_ADDRESS 0x7BB2u    /* 02DBB2 */
#define timed_throwable_states_ADDRESS 0x7BBAu    /* 02DBBA */
#define heavy_obstacle_hit_actions_ADDRESS 0x7BCCu    /* 02DBCC */
#define moes_street_scenery_riser_states_ADDRESS 0x7BD0u    /* 02DBD0 */
#define moes_street_scenery_riser_setup_ADDRESS 0x7BDCu    /* 02DBDC */
#define moes_street_scenery_dropper_states_ADDRESS 0x7BE2u    /* 02DBE2 */
#define moes_street_scenery_dropper_setup_ADDRESS 0x7BECu    /* 02DBEC */
#define police_car_door_states_ADDRESS 0x7C1Eu    /* 02DC1E */
#define police_car_door_setup_ADDRESS 0x7C28u    /* 02DC28 */
#define police_car_door_releases_rest_ADDRESS 0x7C6Du    /* 02DC6D */
#define carried_obstacle_states_ADDRESS 0x7C71u    /* 02DC71 */
#define tossed_obstacle_states_ADDRESS 0x7C83u    /* 02DC83 */
#define carried_obstacle_setup_ADDRESS 0x7C91u    /* 02DC91 */
#define carried_obstacle_break_actions_ADDRESS 0x7C97u    /* 02DC97 */
#define carried_obstacle_drop_actions_ADDRESS 0x7C9Bu    /* 02DC9B */
#define throwable_states_ADDRESS 0x7CA5u    /* 02DCA5 */
#define throwable_stop_actions_ADDRESS 0x7CB5u    /* 02DCB5 */
#define throwable_setup_ADDRESS 0x7CB9u    /* 02DCB9 */
#define throwable_fall_table_ADDRESS 0x7CBFu    /* 02DCBF */
#define platform_scenery_parts_ADDRESS 0x7CD1u    /* 02DCD1 */
#define platform_scenery_setup_ADDRESS 0x7CDBu    /* 02DCDB */
#define platform_scenery_shape_1_ADDRESS 0x7CE1u    /* 02DCE1 */
#define platform_scenery_shape_2_ADDRESS 0x7CEDu    /* 02DCED */
#define platform_scenery_shape_3_ADDRESS 0x7CF9u    /* 02DCF9 */
#define platform_scenery_shape_4_ADDRESS 0x7D05u    /* 02DD05 */
#define platform_scenery_shape_5_ADDRESS 0x7D11u    /* 02DD11 */
#define platform_scenery_react_actions_ADDRESS 0x7D1Du    /* 02DD1D */
#define platform_scenery_crash_debris_1_ADDRESS 0x7D23u    /* 02DD23 */
#define platform_scenery_crash_debris_2_ADDRESS 0x7D29u    /* 02DD29 */
#define scenery_debris_states_ADDRESS 0x7D2Fu    /* 02DD2F */
#define scenery_debris_setup_ADDRESS 0x7D37u    /* 02DD37 */
#define scenery_debris_idle_table_ADDRESS 0x7D3Du    /* 02DD3D */
#define charging_scenery_parts_ADDRESS 0x7D45u    /* 02DD45 */
#define charging_scenery_shape_1_ADDRESS 0x7D4Du    /* 02DD4D */
#define charging_scenery_shape_2_ADDRESS 0x7D59u    /* 02DD59 */
#define charging_scenery_shape_3_ADDRESS 0x7D65u    /* 02DD65 */
#define plain_floor_shape_ADDRESS 0x7D71u    /* 02DD71 */
#define charging_scenery_setup_ADDRESS 0x7D7Du    /* 02DD7D */
#define charging_scenery_goon_left_ADDRESS 0x7D8Bu    /* 02DD8B */
#define charging_scenery_goon_right_ADDRESS 0x7D93u    /* 02DD93 */
#define charging_scenery_goon_right_rest_ADDRESS 0x7D9Bu    /* 02DD9B */
#define obstacle_states_ADDRESS 0x7D9Fu    /* 02DD9F */
#define heavy_obstacle_setup_ADDRESS 0x7DCDu    /* 02DDCD */
#define obstacle_smashed_step_handlers_ADDRESS 0x7DD3u    /* 02DDD3 */
#define obstacle_knocked_actions_ADDRESS 0x7DD7u    /* 02DDD7 */
#define solid_scenery_states_ADDRESS 0x7DDBu    /* 02DDDB */
#define solid_scenery_setup_ADDRESS 0x7DDFu    /* 02DDDF */
#define boulder_states_ADDRESS 0x7DE5u    /* 02DDE5 */
#define boulder_setup_ADDRESS 0x7DEFu    /* 02DDEF */
#define gorge_rock_states_ADDRESS 0x7E05u    /* 02DE05 */
#define gorge_rock_setup_ADDRESS 0x7E0Bu    /* 02DE0B */
#define shaken_bit_states_ADDRESS 0x7E11u    /* 02DE11 */
#define shaken_bit_setup_ADDRESS 0x7E15u    /* 02DE15 */
#define shaken_object_states_ADDRESS 0x7E1Bu    /* 02DE1B */
#define shaken_object_setup_ADDRESS 0x7E23u    /* 02DE23 */
#define shaken_object_land_child_ADDRESS 0x7E29u    /* 02DE29 */
#define shaken_object_land_child_rest_ADDRESS 0x7E2Fu    /* 02DE2F */
#define shaking_scenery_states_ADDRESS 0x7E35u    /* 02DE35 */
#define shaking_scenery_child_1_ADDRESS 0x7E75u    /* 02DE75 */
#define shaking_scenery_child_2_ADDRESS 0x7E7Du    /* 02DE7D */
#define shaking_scenery_child_3_ADDRESS 0x7E85u    /* 02DE85 */
#define shaking_scenery_child_4_ADDRESS 0x7E8Du    /* 02DE8D */
#define shaking_scenery_setup_ADDRESS 0x7EADu    /* 02DEAD */
#define shaking_scenery_shake_step_handlers_ADDRESS 0x7EB3u    /* 02DEB3 */
#define shaking_scenery_hit_from_above_actions_ADDRESS 0x7EBDu    /* 02DEBD */
#define shaking_scenery_bit_1_ADDRESS 0x7EC1u    /* 02DEC1 */
#define shaking_scenery_bit_2_ADDRESS 0x7EC9u    /* 02DEC9 */
#define shaking_scenery_hit_actions_ADDRESS 0x7ED1u    /* 02DED1 */
#define shaking_scenery_drop_food_child_ADDRESS 0x7ED5u    /* 02DED5 */
#define shaking_scenery_drop_food_child_rest_ADDRESS 0x7EDDu    /* 02DEDD */
#define running_animal_states_ADDRESS 0x7EE1u    /* 02DEE1 */
#define running_animal_hit_step_handlers_ADDRESS 0x7EF1u    /* 02DEF1 */
#define running_animal_setup_ADDRESS 0x7F0Bu    /* 02DF0B */
#define running_animal_setup_rest_ADDRESS 0x7F11u    /* 02DF11 */
#define bouncing_throwable_states_ADDRESS 0x7F15u    /* 02DF15 */
#define bouncing_throwable_setup_ADDRESS 0x7F25u    /* 02DF25 */
#define bouncing_throwable_setup_rest_ADDRESS 0x7F2Bu    /* 02DF2B */
#define dreamland_obstacle_states_ADDRESS 0x7F2Fu    /* 02DF2F */
#define dreamland_obstacle_setup_ADDRESS 0x7F41u    /* 02DF41 */
#define dreamland_obstacle_drop_step_handlers_ADDRESS 0x7F67u    /* 02DF67 */
#define bird_item_setup_box_ADDRESS 0x7F6Du    /* 02DF6D */
#define bird_item_states_ADDRESS 0x7F75u    /* 02DF75 */
#define bird_item_setup_ADDRESS 0x7F7Du    /* 02DF7D */
#define woman_in_apron_body_box_ADDRESS 0x7F83u    /* 02DF83 */
#define woman_in_apron_device_strike_box_ADDRESS 0x7F8Bu    /* 02DF8B */
#define woman_in_apron_device_strike_box_rest_ADDRESS 0x7F93u    /* 02DF93 */
#define rising_scenery_steps_ADDRESS 0x7F9Bu    /* 02DF9B */
#define rising_scenery_steps_rest_ADDRESS 0x7FA3u    /* 02DFA3 */
#define rising_scenery_setup_ADDRESS 0x7FA5u    /* 02DFA5 */
#define woman_in_apron_device_states_ADDRESS 0x7FABu    /* 02DFAB */
#define woman_in_apron_device_setup_ADDRESS 0x7FBBu    /* 02DFBB */
#define woman_in_apron_states_ADDRESS 0x7FC1u    /* 02DFC1 */
#define woman_in_apron_states_rest_ADDRESS 0x7FCDu    /* 02DFCD */
#define woman_in_apron_child_ADDRESS 0x7FD1u    /* 02DFD1 */
#define woman_in_apron_setup_ADDRESS 0x7FD9u    /* 02DFD9 */
#define woman_in_apron_setup_rest_ADDRESS 0x7FDFu    /* 02DFDF */
#define rabbit_states_ADDRESS 0x7FE5u    /* 02DFE5 */
#define rabbit_hit_step_handlers_ADDRESS 0x7FE9u    /* 02DFE9 */
#define rabbit_setup_ADDRESS 0x7FEDu    /* 02DFED */
#define rabbit_setup_fill_ADDRESS 0x7FF3u    /* 02DFF3 */
#define unused_obstacle_setup_box_ADDRESS 0x6151u    /* 02E151 */
#define unused_obstacle_setup_box_rest_ADDRESS 0x6159u    /* 02E159 */
#define unused_obstacle_setup_box_rest_2_ADDRESS 0x6161u    /* 02E161 */
#define unused_obstacle_setup_box_rest_3_ADDRESS 0x6169u    /* 02E169 */
#define sideshow_bob_setup_box_ADDRESS 0x6171u    /* 02E171 */
#define girl_with_food_setup_box_ADDRESS 0x6179u    /* 02E179 */
#define food_setup_box_ADDRESS 0x6181u    /* 02E181 */
#define food_jump_out_setup_box_ADDRESS 0x6189u    /* 02E189 */
#define carried_item_setup_box_ADDRESS 0x6191u    /* 02E191 */
#define carried_item_setup_box_rest_ADDRESS 0x6199u    /* 02E199 */
#define carried_item_setup_box_rest_2_ADDRESS 0x61A1u    /* 02E1A1 */
#define unused_homer_object_rest_fill_ADDRESS 0x785Fu    /* 02F85F */
#define looping_scenery_setup_box_ADDRESS 0x7A00u    /* 02FA00 */
#define looping_scenery_states_ADDRESS 0x7A08u    /* 02FA08 */
#define looping_scenery_setup_ADDRESS 0x7A0Cu    /* 02FA0C */
#define looping_scenery_leaving_states_ADDRESS 0x7A3Au    /* 02FA3A */
#define unused_kind_b7_setup_box_ADDRESS 0x7A40u    /* 02FA40 */
#define looping_scenery_leave_box_ADDRESS 0x7A48u    /* 02FA48 */
#define unused_kind_b7_setup_ADDRESS 0x7A50u    /* 02FA50 */
#define unused_kind_b7_setup_rest_ADDRESS 0x7A56u    /* 02FA56 */
#define unused_obstacle_update_table_ADDRESS 0x7A5Au    /* 02FA5A */
#define unused_obstacle_break_steps_table_ADDRESS 0x7A5Eu    /* 02FA5E */
#define unused_obstacle_setup_ADDRESS 0x7A62u    /* 02FA62 */
#define item_states_ADDRESS 0x7A68u    /* 02FA68 */
#define item_setups_rest_ADDRESS 0x7A76u    /* 02FA76 */
#define item_setups_rest_2_ADDRESS 0x7A7Cu    /* 02FA7C */
#define item_setups_rest_3_ADDRESS 0x7A82u    /* 02FA82 */
#define food_jump_out_states_ADDRESS 0x7A88u    /* 02FA88 */
#define food_jump_out_setup_ADDRESS 0x7A96u    /* 02FA96 */
#define food_states_ADDRESS 0x7AC4u    /* 02FAC4 */
#define food_setup_ADDRESS 0x7ADEu    /* 02FADE */
#define dropped_food_states_ADDRESS 0x7AE4u    /* 02FAE4 */
#define girl_with_food_states_ADDRESS 0x7AECu    /* 02FAEC */
#define girl_with_food_setup_ADDRESS 0x7AFAu    /* 02FAFA */
#define girl_with_food_partners_rest_ADDRESS 0x7B08u    /* 02FB08 */
#define girl_with_food_partners_rest_2_ADDRESS 0x7B10u    /* 02FB10 */
#define girl_with_food_partners_rest_3_ADDRESS 0x7B18u    /* 02FB18 */
#define girl_with_food_partners_rest_4_ADDRESS 0x7B20u    /* 02FB20 */
#define girl_with_food_food_drops_rest_ADDRESS 0x7B30u    /* 02FB30 */
#define girl_with_food_food_drops_rest_2_ADDRESS 0x7B38u    /* 02FB38 */
#define girl_with_food_food_drops_rest_3_ADDRESS 0x7B40u    /* 02FB40 */
#define girl_with_food_food_drops_rest_4_ADDRESS 0x7B48u    /* 02FB48 */
#define sideshow_bob_states_ADDRESS 0x7B50u    /* 02FB50 */
#define sideshow_bob_setup_ADDRESS 0x7B5Eu    /* 02FB5E */
#define sideshow_bob_drop_food_child_ADDRESS 0x7B64u    /* 02FB64 */
#define item_carrier_states_ADDRESS 0x7B6Cu    /* 02FB6C */
#define carried_item_setup_ADDRESS 0x7B80u    /* 02FB80 */
#define carried_item_setup_rest_ADDRESS 0x7B86u    /* 02FB86 */
#define carried_item_setup_rest_2_ADDRESS 0x7B8Cu    /* 02FB8C */
#define item_carrier_items_rest_ADDRESS 0x7B98u    /* 02FB98 */
#define item_carrier_items_rest_2_ADDRESS 0x7BA0u    /* 02FBA0 */
#define item_carrier_items_rest_3_ADDRESS 0x7BA8u    /* 02FBA8 */
#define carried_item_states_ADDRESS 0x7BB0u    /* 02FBB0 */
#define bystander_setup_box_ADDRESS 0x7BBBu    /* 02FBBB */
#define bystander_states_ADDRESS 0x7BC3u    /* 02FBC3 */
#define bystander_setup_ADDRESS 0x7BD9u    /* 02FBD9 */
#define fireman_goon_object_setup_box_ADDRESS 0x7BDFu    /* 02FBDF */
#define fireman_goon_missile_setup_box_ADDRESS 0x7BE7u    /* 02FBE7 */
#define fireman_goon_setup_enemy_behaviour_ADDRESS 0x7BEFu    /* 02FBEF */
#define bystander_gone_table_ADDRESS 0x7C47u    /* 02FC47 */
#define fireman_goon_object_setup_ADDRESS 0x7C53u    /* 02FC53 */
#define fireman_goon_entrance_steps_table_ADDRESS 0x7C65u    /* 02FC65 */
#define fireman_goon_throw_steps_ADDRESS 0x7C6Du    /* 02FC6D */
#define fireman_goon_put_in_missile_child_ADDRESS 0x7C73u    /* 02FC73 */
#define fireman_goon_missile_states_ADDRESS 0x7C79u    /* 02FC79 */
#define fireman_goon_missile_setup_ADDRESS 0x7C81u    /* 02FC81 */
#define kent_brockman_setup_box_ADDRESS 0x7C87u    /* 02FC87 */
#define kent_brockman_states_ADDRESS 0x7C8Fu    /* 02FC8F */
#define kent_brockman_setup_ADDRESS 0x7C99u    /* 02FC99 */
#define one_eared_rabbit_body_box_ADDRESS 0x7CA6u    /* 02FCA6 */
#define clown_ball_setup_box_ADDRESS 0x7CAEu    /* 02FCAE */
#define one_eared_rabbit_strike_hit_box_ADDRESS 0x7CB6u    /* 02FCB6 */
#define clown_on_ball_body_box_ADDRESS 0x7CBEu    /* 02FCBE */
#define clown_on_ball_strike_box_ADDRESS 0x7CC6u    /* 02FCC6 */
#define teacup_goon_body_box_ADDRESS 0x7CCEu    /* 02FCCE */
#define teacup_goon_leap_off_box_ADDRESS 0x7CD6u    /* 02FCD6 */
#define teacup_goon_piece_setup_box_ADDRESS 0x7CDEu    /* 02FCDE */
#define one_eared_rabbit_start_enemy_behaviour_ADDRESS 0x7CE6u    /* 02FCE6 */
#define clown_on_ball_start_enemy_behaviour_ADDRESS 0x7D3Eu    /* 02FD3E */
#define teacup_goon_ride_states_ADDRESS 0x7D96u    /* 02FD96 */
#define teacup_goon_ride_put_in_arms_child_ADDRESS 0x7DA7u    /* 02FDA7 */
#define teacup_goon_ride_end_child_ADDRESS 0x7DADu    /* 02FDAD */
#define teacup_goon_ride_arm_states_ADDRESS 0x7DB5u    /* 02FDB5 */
#define teacup_goon_ride_setup_ADDRESS 0x7DBFu    /* 02FDBF */
#define teacup_goon_ride_arm_put_in_riders_child_ADDRESS 0x7DC5u    /* 02FDC5 */
#define teacup_goon_piece_states_ADDRESS 0x7DCDu    /* 02FDCD */
#define teacup_goon_piece_setup_ADDRESS 0x7DD3u    /* 02FDD3 */
#define teacup_goon_piece_setup_rest_ADDRESS 0x7DD9u    /* 02FDD9 */
#define teacup_goon_piece_blink_table_ADDRESS 0x7DDDu    /* 02FDDD */
#define teacup_goon_beaten_child_ADDRESS 0x7DF3u    /* 02FDF3 */
#define teacup_goon_hit_steps_table_ADDRESS 0x7DF9u    /* 02FDF9 */
#define teacup_goon_setup_ADDRESS 0x7E01u    /* 02FE01 */
#define teacup_goon_fight_steps_table_ADDRESS 0x7E07u    /* 02FE07 */
#define unused_goon_states_ADDRESS 0x7E0Fu    /* 02FE0F */
#define teacup_goon_hop_wait_table_ADDRESS 0x7E1Bu    /* 02FE1B */
#define one_eared_rabbit_setup_ADDRESS 0x7E27u    /* 02FE27 */
#define one_eared_rabbit_entrance_step_handlers_ADDRESS 0x7E2Du    /* 02FE2D */
#define one_eared_rabbit_step_back_steps_ADDRESS 0x7E37u    /* 02FE37 */
#define one_eared_rabbit_strike_steps_ADDRESS 0x7E3Bu    /* 02FE3B */
#define clown_ball_states_ADDRESS 0x7E47u    /* 02FE47 */
#define clown_ball_burst_actions_ADDRESS 0x7E4Fu    /* 02FE4F */
#define clown_ball_setup_ADDRESS 0x7E53u    /* 02FE53 */
#define clown_ball_vanish_table_ADDRESS 0x7E59u    /* 02FE59 */
#define clown_on_ball_setup_ADDRESS 0x7E65u    /* 02FE65 */
#define clown_on_ball_strike_steps_ADDRESS 0x7E73u    /* 02FE73 */
#define clown_on_ball_jump_steps_ADDRESS 0x7E77u    /* 02FE77 */
#define clown_on_ball_charge_steps_ADDRESS 0x7E7Bu    /* 02FE7B */
#define clown_on_ball_pause_steps_ADDRESS 0x7E83u    /* 02FE83 */
#define clown_on_ball_hop_steps_ADDRESS 0x7E8Bu    /* 02FE8B */
#define krustyland_bear_setup_box_ADDRESS 0x7ECFu    /* 02FECF */
#define caged_gorilla_body_box_ADDRESS 0x7ED7u    /* 02FED7 */
#define caged_gorilla_hit_box_ADDRESS 0x7EDFu    /* 02FEDF */
#define buzzing_chaser_setup_box_ADDRESS 0x7EE7u    /* 02FEE7 */
#define bluebird_setup_box_ADDRESS 0x7EEFu    /* 02FEEF */
#define random_pose_figure_setup_box_ADDRESS 0x7EF7u    /* 02FEF7 */
#define random_pose_figure_setup_box_rest_ADDRESS 0x7EFFu    /* 02FEFF */
#define unused_homer_object_setup_box_ADDRESS 0x7F0Fu    /* 02FF0F */
#define krustyland_bear_states_ADDRESS 0x7F17u    /* 02FF17 */
#define krustyland_bear_setup_ADDRESS 0x7F23u    /* 02FF23 */
#define caged_gorilla_states_ADDRESS 0x7F29u    /* 02FF29 */
#define caged_gorilla_setup_ADDRESS 0x7F35u    /* 02FF35 */
#define buzzing_chaser_states_ADDRESS 0x7F3Du    /* 02FF3D */
#define buzzing_chaser_setup_ADDRESS 0x7F49u    /* 02FF49 */
#define bluebird_states_ADDRESS 0x7F4Fu    /* 02FF4F */
#define bluebird_setup_ADDRESS 0x7F65u    /* 02FF65 */
#define random_pose_figure_states_ADDRESS 0x7FA3u    /* 02FFA3 */
#define random_pose_figure_setup_ADDRESS 0x7FA7u    /* 02FFA7 */
#define random_figure_poses_rest_ADDRESS 0x7FC5u    /* 02FFC5 */
#define unused_homer_object_states_ADDRESS 0x7FC9u    /* 02FFC9 */
#define unused_homer_object_setup_ADDRESS 0x7FD5u    /* 02FFD5 */
#define unused_homer_object_setup_fill_ADDRESS 0x7FDBu    /* 02FFDB */
#define cloud_devil_drop_bolt_child_ADDRESS 0x6FAEu    /* 030FAE */
#define woman_in_green_carrier_done_fill_ADDRESS 0x76C3u    /* 0316C3 */
#define rising_zombie_object_setup_box_ADDRESS 0x7880u    /* 031880 */
#define rising_zombie_object_setup_box_rest_ADDRESS 0x7888u    /* 031888 */
#define zombie_body_box_ADDRESS 0x7890u    /* 031890 */
#define zombie_swipe_hit_box_ADDRESS 0x7898u    /* 031898 */
#define zombie_leap_rise_box_ADDRESS 0x78A0u    /* 0318A0 */
#define ghost_on_rope_body_box_ADDRESS 0x78A8u    /* 0318A8 */
#define ghost_on_rope_drop_box_ADDRESS 0x78B0u    /* 0318B0 */
#define wandering_zombie_object_setup_box_ADDRESS 0x78B8u    /* 0318B8 */
#define zombie_behaviour_ADDRESS 0x78C0u    /* 0318C0 */
#define object_18_behaviours_3_ADDRESS 0x7918u    /* 031918 */
#define object_18_behaviours_3_rest_ADDRESS 0x7970u    /* 031970 */
#define lightning_bolt_update_table_ADDRESS 0x7974u    /* 031974 */
#define wandering_zombie_hit_table_ADDRESS 0x797Eu    /* 03197E */
#define wandering_zombie_object_setup_ADDRESS 0x7982u    /* 031982 */
#define wandering_zombie_remove_when_gone_table_ADDRESS 0x79C8u    /* 0319C8 */
#define zombie_object_setup_ADDRESS 0x79D4u    /* 0319D4 */
#define zombie_come_out_table_ADDRESS 0x79EEu    /* 0319EE */
#define zombie_burrow_steps_ADDRESS 0x79F8u    /* 0319F8 */
#define zombie_leap_steps_ADDRESS 0x7A00u    /* 031A00 */
#define zombie_swipe_steps_ADDRESS 0x7A0Cu    /* 031A0C */
#define unused_zombie_restart_at_animation_end_table_ADDRESS 0x7A1Au    /* 031A1A */
#define ghost_on_rope_hurt_steps_ADDRESS 0x7A26u    /* 031A26 */
#define ghost_on_rope_object_setup_ADDRESS 0x7A2Au    /* 031A2A */
#define rising_zombie_states_ADDRESS 0x7A38u    /* 031A38 */
#define rising_zombie_object_setup_ADDRESS 0x7A72u    /* 031A72 */
#define grabbing_zombie_object_setup_box_ADDRESS 0x7A78u    /* 031A78 */
#define grabbing_zombie_object_setup_box_rest_ADDRESS 0x7A80u    /* 031A80 */
#define grabbing_zombie_behaviour_ADDRESS 0x7A88u    /* 031A88 */
#define rising_zombie_walk_off_table_ADDRESS 0x7AE0u    /* 031AE0 */
#define grabbing_zombie_object_setup_ADDRESS 0x7AECu    /* 031AEC */
#define grabbing_zombie_come_out_table_ADDRESS 0x7AF2u    /* 031AF2 */
#define grabbing_zombie_join_fight_table_ADDRESS 0x7B02u    /* 031B02 */
#define lumberjack_body_box_ADDRESS 0x7B0Eu    /* 031B0E */
#define lumberjack_axe_swing_box_ADDRESS 0x7B16u    /* 031B16 */
#define gorilla_body_box_ADDRESS 0x7B1Eu    /* 031B1E */
#define gorilla_punch_hit_box_ADDRESS 0x7B26u    /* 031B26 */
#define gorilla_leap_rise_box_ADDRESS 0x7B2Eu    /* 031B2E */
#define lumberjack_behaviour_ADDRESS 0x7B36u    /* 031B36 */
#define gorilla_behaviour_ADDRESS 0x7B8Eu    /* 031B8E */
#define zombie_grab_hold_loop_table_ADDRESS 0x7BE6u    /* 031BE6 */
#define lumberjack_object_setup_ADDRESS 0x7BF2u    /* 031BF2 */
#define lumberjack_jump_in_table_ADDRESS 0x7BF8u    /* 031BF8 */
#define lumberjack_axe_steps_ADDRESS 0x7BFEu    /* 031BFE */
#define lumberjack_axe_wait_table_ADDRESS 0x7C11u    /* 031C11 */
#define gorilla_object_setup_ADDRESS 0x7C1Du    /* 031C1D */
#define gorilla_come_in_table_ADDRESS 0x7C23u    /* 031C23 */
#define gorilla_punch_steps_ADDRESS 0x7C4Fu    /* 031C4F */
#define gorilla_leap_steps_ADDRESS 0x7C57u    /* 031C57 */
#define gorilla_back_off_steps_ADDRESS 0x7C6Bu    /* 031C6B */
#define knight_body_box_ADDRESS 0x7C6Fu    /* 031C6F */
#define knight_strike_hit_box_ADDRESS 0x7C77u    /* 031C77 */
#define knight_behaviour_ADDRESS 0x7C7Fu    /* 031C7F */
#define knight_behaviour_rest_ADDRESS 0x7CD7u    /* 031CD7 */
#define gorilla_back_off_end_table_ADDRESS 0x7CD9u    /* 031CD9 */
#define knight_lose_first_form_table_ADDRESS 0x7CE5u    /* 031CE5 */
#define knight_fall_child_ADDRESS 0x7CE9u    /* 031CE9 */
#define knight_object_setup_ADDRESS 0x7CF1u    /* 031CF1 */
#define knight_come_in_table_ADDRESS 0x7D37u    /* 031D37 */
#define knight_strike_steps_ADDRESS 0x7D71u    /* 031D71 */
#define cloud_devil_object_setup_box_ADDRESS 0x7D77u    /* 031D77 */
#define lightning_bolt_object_setup_box_ADDRESS 0x7D7Fu    /* 031D7F */
#define lightning_bolt_states_ADDRESS 0x7D87u    /* 031D87 */
#define lightning_bolt_object_setup_ADDRESS 0x7D8Bu    /* 031D8B */
#define lightning_bolt_object_setup_rest_ADDRESS 0x7D91u    /* 031D91 */
#define lightning_bolt_end_table_ADDRESS 0x7D95u    /* 031D95 */
#define cloud_devil_object_setup_ADDRESS 0x7DC2u    /* 031DC2 */
#define cloud_devil_come_in_table_ADDRESS 0x7DC8u    /* 031DC8 */
#define cloud_devil_hurt_table_ADDRESS 0x7DCEu    /* 031DCE */
#define cloud_devil_die_table_ADDRESS 0x7DD2u    /* 031DD2 */
#define woman_in_green_carrier_object_setup_box_ADDRESS 0x7EA0u    /* 031EA0 */
#define belly_dancer_watcher_object_setup_box_ADDRESS 0x7EA8u    /* 031EA8 */
#define moe_object_setup_box_ADDRESS 0x7EB0u    /* 031EB0 */
#define walking_kind_87_object_setup_box_ADDRESS 0x7EB8u    /* 031EB8 */
#define belly_dancer_thrower_object_setup_box_ADDRESS 0x7EC0u    /* 031EC0 */
#define spark_shot_object_setup_box_ADDRESS 0x7EC8u    /* 031EC8 */
#define barney_bystander_object_setup_box_ADDRESS 0x7ED0u    /* 031ED0 */
#define unused_figure_hit_box_fill_ADDRESS 0x7EE0u    /* 031EE0 */
#define unused_figure_hit_box_rest_ADDRESS 0x7EE8u    /* 031EE8 */
#define spark_shot_states_ADDRESS 0x7EECu    /* 031EEC */
#define spark_shot_burst_steps_ADDRESS 0x7EF0u    /* 031EF0 */
#define spark_shot_object_setup_ADDRESS 0x7EF4u    /* 031EF4 */
#define spark_shot_object_setup_rest_ADDRESS 0x7EFAu    /* 031EFA */
#define spark_shot_fly_table_ADDRESS 0x7EFCu    /* 031EFC */
#define belly_dancer_thrower_hurt_table_ADDRESS 0x7F08u    /* 031F08 */
#define unused_kind_8e_thrower_run_step_table_ADDRESS 0x7F0Cu    /* 031F0C */
#define belly_dancer_thrower_object_setup_ADDRESS 0x7F10u    /* 031F10 */
#define belly_dancer_thrower_throw_child_ADDRESS 0x7F16u    /* 031F16 */
#define walking_kind_87_states_ADDRESS 0x7F1Cu    /* 031F1C */
#define walking_kind_87_object_setup_ADDRESS 0x7F2Au    /* 031F2A */
#define moe_states_ADDRESS 0x7F30u    /* 031F30 */
#define moe_object_setup_ADDRESS 0x7F44u    /* 031F44 */
#define belly_dancer_watcher_states_ADDRESS 0x7F4Au    /* 031F4A */
#define belly_dancer_watcher_object_setup_ADDRESS 0x7F58u    /* 031F58 */
#define belly_dancer_watcher_object_setup_rest_ADDRESS 0x7F5Eu    /* 031F5E */
#define unused_kind_8e_watcher_no_op_table_ADDRESS 0x7F64u    /* 031F64 */
#define barney_bystander_leave_table_ADDRESS 0x7F68u    /* 031F68 */
#define barney_bystander_hurt_table_ADDRESS 0x7F6Eu    /* 031F6E */
#define barney_bystander_object_setup_ADDRESS 0x7F74u    /* 031F74 */
#define barney_bystander_pose_table_ADDRESS 0x7F82u    /* 031F82 */
#define woman_in_green_carrier_hurt_table_ADDRESS 0x7F8Eu    /* 031F8E */
#define woman_in_green_carrier_object_setup_ADDRESS 0x7F92u    /* 031F92 */
#define woman_in_green_carrier_pick_up_child_ADDRESS 0x7F98u    /* 031F98 */
#define woman_in_green_carrier_pick_up_child_fill_ADDRESS 0x7FA0u    /* 031FA0 */
#define flying_saxophone_shot_remove_fill_ADDRESS 0x76B2u    /* 0336B2 */
#define bouncing_prop_bounce_off_edge_box_ADDRESS 0x78A4u    /* 0338A4 */
#define bouncing_prop_bounce_start_box_ADDRESS 0x78ACu    /* 0338AC */
#define bouncing_prop_bounce_start_box_rest_ADDRESS 0x78B4u    /* 0338B4 */
#define bouncing_prop_states_ADDRESS 0x78B8u    /* 0338B8 */
#define bouncing_prop_leave_steps_ADDRESS 0x78C6u    /* 0338C6 */
#define bouncing_prop_object_setup_ADDRESS 0x78CEu    /* 0338CE */
#define bouncing_prop_bounce_steps_ADDRESS 0x78D4u    /* 0338D4 */
#define ninja_body_box_ADDRESS 0x78D8u    /* 0338D8 */
#define ninja_star_object_setup_box_ADDRESS 0x78E0u    /* 0338E0 */
#define ninja_hop_strike_hit_box_ADDRESS 0x78E8u    /* 0338E8 */
#define ninja_jump_attack_dive_box_ADDRESS 0x78F0u    /* 0338F0 */
#define ninja_crouch_strike_hit_box_ADDRESS 0x78F8u    /* 0338F8 */
#define ninja_fighter_behaviour_ADDRESS 0x7900u    /* 033900 */
#define ninja_behaviour_ADDRESS 0x7958u    /* 033958 */
#define ninja_thrower_behaviour_ADDRESS 0x79B0u    /* 0339B0 */
#define bouncing_prop_land_table_ADDRESS 0x7A08u    /* 033A08 */
#define ninja_thrower_setup_table_ADDRESS 0x7A14u    /* 033A14 */
#define ninja_fighter_setup_table_ADDRESS 0x7A20u    /* 033A20 */
#define ninja_leave_table_ADDRESS 0x7A2Eu    /* 033A2E */
#define ninja_object_setup_ADDRESS 0x7A32u    /* 033A32 */
#define ninja_come_in_table_ADDRESS 0x7A38u    /* 033A38 */
#define ninja_split_child_ADDRESS 0x7A7Du    /* 033A7D */
#define ninja_hop_strike_steps_ADDRESS 0x7A85u    /* 033A85 */
#define ninja_throw_steps_ADDRESS 0x7A8Du    /* 033A8D */
#define ninja_throw_release_child_ADDRESS 0x7A93u    /* 033A93 */
#define ninja_star_states_ADDRESS 0x7A99u    /* 033A99 */
#define ninja_star_object_setup_ADDRESS 0x7A9Du    /* 033A9D */
#define ninja_slash_steps_ADDRESS 0x7AA3u    /* 033AA3 */
#define ninja_crouch_strike_steps_ADDRESS 0x7AABu    /* 033AAB */
#define ninja_jump_attack_steps_ADDRESS 0x7ABAu    /* 033ABA */
#define ninja_rush_steps_ADDRESS 0x7AC4u    /* 033AC4 */
#define ninja_vanish_steps_ADDRESS 0x7ACCu    /* 033ACC */
#define robot_piece_object_setup_box_ADDRESS 0x7AD8u    /* 033AD8 */
#define robot_scrap_throw_box_ADDRESS 0x7AE0u    /* 033AE0 */
#define robot_scrap_throw_box_rest_ADDRESS 0x7AE8u    /* 033AE8 */
#define robot_piece_object_setup_ADDRESS 0x7B00u    /* 033B00 */
#define robot_piece_states_ADDRESS 0x7B06u    /* 033B06 */
#define robot_spark_object_setup_box_ADDRESS 0x7B30u    /* 033B30 */
#define robot_body_box_ADDRESS 0x7B38u    /* 033B38 */
#define robot_punch_first_hit_box_ADDRESS 0x7B40u    /* 033B40 */
#define robot_punch_second_hit_box_ADDRESS 0x7B48u    /* 033B48 */
#define robot_punch_second_hit_box_rest_ADDRESS 0x7B50u    /* 033B50 */
#define goon_lift_object_setup_box_ADDRESS 0x7B60u    /* 033B60 */
#define goon_lift_part_object_setup_box_ADDRESS 0x7B68u    /* 033B68 */
#define robot_behaviour_ADDRESS 0x7B70u    /* 033B70 */
#define robot_spark_states_ADDRESS 0x7BC8u    /* 033BC8 */
#define robot_spark_object_setup_ADDRESS 0x7BD0u    /* 033BD0 */
#define robot_spark_fade_table_ADDRESS 0x7BD6u    /* 033BD6 */
#define robot_object_setup_ADDRESS 0x7BE2u    /* 033BE2 */
#define robot_combo_steps_ADDRESS 0x7BE8u    /* 033BE8 */
#define robot_punch_steps_ADDRESS 0x7C04u    /* 033C04 */
#define robot_advance_shock_steps_ADDRESS 0x7C10u    /* 033C10 */
#define robot_shock_92_steps_ADDRESS 0x7C36u    /* 033C36 */
#define robot_sparks_by_frame_9d_child_object_ADDRESS 0x7C50u    /* 033C50 */
#define robot_sparks_by_frame_9d_child_object_2_ADDRESS 0x7C58u    /* 033C58 */
#define robot_sparks_by_frame_9d_child_object_3_ADDRESS 0x7C60u    /* 033C60 */
#define robot_sparks_by_frame_9d_child_object_4_ADDRESS 0x7C68u    /* 033C68 */
#define robot_shock_91_steps_ADDRESS 0x7C70u    /* 033C70 */
#define robot_sparks_by_frame_9d_child_object_5_ADDRESS 0x7C8Au    /* 033C8A */
#define robot_sparks_by_frame_9d_child_object_6_ADDRESS 0x7C92u    /* 033C92 */
#define robot_sparks_by_frame_9d_child_object_7_ADDRESS 0x7C9Au    /* 033C9A */
#define robot_sparks_by_frame_9d_child_object_8_ADDRESS 0x7CA2u    /* 033CA2 */
#define robot_hit_reaction_table_ADDRESS 0x7CAAu    /* 033CAA */
#define robot_launch_part_steps_ADDRESS 0x7D08u    /* 033D08 */
#define robot_launch_part_release_child_ADDRESS 0x7D10u    /* 033D10 */
#define robot_part_states_ADDRESS 0x7D16u    /* 033D16 */
#define robot_part_object_setup_ADDRESS 0x7D1Cu    /* 033D1C */
#define goon_lift_states_ADDRESS 0x7D52u    /* 033D52 */
#define goon_lift_object_setup_ADDRESS 0x7D62u    /* 033D62 */
#define goon_lift_part_child_1_ADDRESS 0x7D68u    /* 033D68 */
#define goon_lift_part_child_2_ADDRESS 0x7D70u    /* 033D70 */
#define goon_lift_goon_1_ADDRESS 0x7D78u    /* 033D78 */
#define goon_lift_goon_2_ADDRESS 0x7D80u    /* 033D80 */
#define goon_lift_part_states_ADDRESS 0x7D88u    /* 033D88 */
#define goon_lift_part_object_setup_ADDRESS 0x7D90u    /* 033D90 */
#define donut_body_box_ADDRESS 0x7D9Eu    /* 033D9E */
#define donut_roll_go_box_ADDRESS 0x7DA6u    /* 033DA6 */
#define donut_shot_object_setup_box_ADDRESS 0x7DAEu    /* 033DAE */
#define donut_behaviour_ADDRESS 0x7DB6u    /* 033DB6 */
#define goon_lift_part_idle_table_ADDRESS 0x7E0Eu    /* 033E0E */
#define donut_object_setup_ADDRESS 0x7E1Au    /* 033E1A */
#define donut_come_in_table_ADDRESS 0x7E20u    /* 033E20 */
#define donut_roll_steps_ADDRESS 0x7E4Au    /* 033E4A */
#define donut_throw_steps_ADDRESS 0x7E50u    /* 033E50 */
#define donut_throw_release_child_ADDRESS 0x7E56u    /* 033E56 */
#define donut_shot_states_ADDRESS 0x7E5Eu    /* 033E5E */
#define donut_shot_object_setup_ADDRESS 0x7E62u    /* 033E62 */
#define flying_saxophone_object_setup_box_ADDRESS 0x7E68u    /* 033E68 */
#define flying_saxophone_shot_object_setup_box_ADDRESS 0x7E70u    /* 033E70 */
#define flying_saxophone_shot_object_setup_box_rest_ADDRESS 0x7E78u    /* 033E78 */
#define donut_shot_fly_table_ADDRESS 0x7E7Cu    /* 033E7C */
#define flying_saxophone_object_setup_ADDRESS 0x7EB7u    /* 033EB7 */
#define flying_saxophone_come_in_table_ADDRESS 0x7EBDu    /* 033EBD */
#define flying_saxophone_volley_shots_child_object_ADDRESS 0x7ECFu    /* 033ECF */
#define flying_saxophone_volley_shots_child_object_2_ADDRESS 0x7ED7u    /* 033ED7 */
#define flying_saxophone_volley_shots_child_object_3_ADDRESS 0x7EDFu    /* 033EDF */
#define flying_saxophone_volley_shots_child_object_4_ADDRESS 0x7EE7u    /* 033EE7 */
#define flying_saxophone_single_shots_child_object_ADDRESS 0x7EF3u    /* 033EF3 */
#define flying_saxophone_single_shots_child_object_2_ADDRESS 0x7EFBu    /* 033EFB */
#define flying_saxophone_hurt_table_ADDRESS 0x7F03u    /* 033F03 */
#define flying_saxophone_die_table_ADDRESS 0x7F07u    /* 033F07 */
#define flying_saxophone_shot_states_ADDRESS 0x7FD5u    /* 033FD5 */
#define flying_saxophone_shot_object_setup_ADDRESS 0x7FDDu    /* 033FDD */
#define flying_saxophone_shot_speeds_fill_ADDRESS 0x7FFFu    /* 033FFF */
#define dreamland_boss_lash_end_fill_ADDRESS 0x6C82u    /* 034C82 */
#define dreamland_boss_chain_link_follow_data_ADDRESS 0x72FCu    /* 0352FC */
#define dreamland_boss_chain_link_follow_table_ADDRESS 0x7300u    /* 035300 */
#define dreamland_boss_body_box_ADDRESS 0x7768u    /* 035768 */
#define dreamland_boss_attack_box_ADDRESS 0x7770u    /* 035770 */
#define dreamland_boss_defeat_burst_box_ADDRESS 0x7778u    /* 035778 */
#define boss_ball_object_setup_box_ADDRESS 0x7780u    /* 035780 */
#define boss_ball_land_box_ADDRESS 0x7788u    /* 035788 */
#define boss_ball_land_box_rest_ADDRESS 0x7790u    /* 035790 */
#define dreamland_boss_run_step_table_ADDRESS 0x7794u    /* 035794 */
#define dreamland_boss_object_setup_ADDRESS 0x77D0u    /* 0357D0 */
#define dreamland_boss_entrance_table_ADDRESS 0x77D6u    /* 0357D6 */
#define dreamland_boss_flinch_table_ADDRESS 0x77E6u    /* 0357E6 */
#define dreamland_boss_chase_table_ADDRESS 0x77EAu    /* 0357EA */
#define dreamland_boss_charge_table_ADDRESS 0x7806u    /* 035806 */
#define dreamland_boss_change_to_second_form_table_ADDRESS 0x780Cu    /* 03580C */
#define dreamland_boss_second_change_flash_child_ADDRESS 0x7812u    /* 035812 */
#define dreamland_boss_second_change_flash_child_rest_ADDRESS 0x781Au    /* 03581A */
#define dreamland_boss_first_form_hit_table_ADDRESS 0x781Eu    /* 03581E */
#define dreamland_boss_pose_round_table_ADDRESS 0x782Eu    /* 03582E */
#define dreamland_boss_leap_table_ADDRESS 0x7842u    /* 035842 */
#define dreamland_boss_second_form_hit_table_ADDRESS 0x7870u    /* 035870 */
#define dreamland_boss_change_to_third_form_table_ADDRESS 0x7876u    /* 035876 */
#define dreamland_boss_third_form_walk_table_ADDRESS 0x7880u    /* 035880 */
#define dreamland_boss_spit_table_ADDRESS 0x7886u    /* 035886 */
#define dreamland_boss_spit_ball_child_ADDRESS 0x788Cu    /* 03588C */
#define dreamland_boss_spit_ball_child_rest_ADDRESS 0x7892u    /* 035892 */
#define dreamland_boss_third_form_hit_table_ADDRESS 0x7896u    /* 035896 */
#define dreamland_boss_change_to_last_form_table_ADDRESS 0x78A4u    /* 0358A4 */
#define dreamland_boss_wobble_table_ADDRESS 0x78ACu    /* 0358AC */
#define dreamland_boss_put_out_chain_child_ADDRESS 0x78BCu    /* 0358BC */
#define dreamland_boss_creep_table_ADDRESS 0x78C4u    /* 0358C4 */
#define dreamland_boss_lash_table_ADDRESS 0x78D8u    /* 0358D8 */
#define dreamland_boss_defeat_table_ADDRESS 0x78DCu    /* 0358DC */
#define object_1a_released_objects_child_object_ADDRESS 0x78F4u    /* 0358F4 */
#define object_1a_released_objects_child_object_2_ADDRESS 0x78FCu    /* 0358FC */
#define object_1a_released_objects_child_object_3_ADDRESS 0x7904u    /* 035904 */
#define object_1a_released_objects_child_object_4_ADDRESS 0x790Cu    /* 03590C */
#define boss_ball_states_ADDRESS 0x7914u    /* 035914 */
#define boss_ball_object_setup_ADDRESS 0x792Eu    /* 03592E */
#define boss_ball_fly_out_child_ADDRESS 0x793Cu    /* 03593C */
#define boss_ball_trail_states_ADDRESS 0x7944u    /* 035944 */
#define boss_ball_trail_object_setup_ADDRESS 0x7948u    /* 035948 */
#define boss_ball_trail_fade_table_ADDRESS 0x794Eu    /* 03594E */
#define dreamland_boss_shadow_object_setup_ADDRESS 0x7952u    /* 035952 */
#define chain_holder_object_setup_box_ADDRESS 0x7958u    /* 035958 */
#define dreamland_boss_shadow_follow_table_ADDRESS 0x7960u    /* 035960 */
#define chain_holder_put_out_chain_child_ADDRESS 0x7966u    /* 035966 */
#define chain_holder_object_setup_ADDRESS 0x796Eu    /* 03596E */
#define chain_holder_object_setup_rest_ADDRESS 0x7974u    /* 035974 */
#define chain_holder_watch_table_ADDRESS 0x7978u    /* 035978 */
#define dreamland_boss_chain_pop_table_ADDRESS 0x7982u    /* 035982 */
#define dreamland_boss_chain_object_setup_ADDRESS 0x7988u    /* 035988 */
#define dreamland_boss_chain_link_parameters_ADDRESS 0x798Eu    /* 03598E */
#define dreamland_boss_chain_head_object_setup_ADDRESS 0x79D6u    /* 0359D6 */
#define object_1a_path_ADDRESS 0x79F3u    /* 0359F3 */
#define object_1a_path_object_path_ADDRESS 0x7A5Au    /* 035A5A */
#define object_1a_path_object_path_object_path_ADDRESS 0x7A81u    /* 035A81 */
#define object_1a_path_object_path_object_path_object_path_ADDRESS 0x7B08u    /* 035B08 */
#define object_1a_path_object_path_object_path_object_path_object_path_ADDRESS 0x7C0Fu    /* 035C0F */
#define object_1a_path_object_path_object_path_object_path_object_path_object_path_ADDRESS 0x7C66u    /* 035C66 */
#define object_1a_path_object_path_object_path_object_path_object_path_object_path_rest_ADDRESS 0x7C9Du    /* 035C9D */
#define object_1a_path_object_path_object_path_object_path_object_path_object_path_rest_2_ADDRESS 0x7CE4u    /* 035CE4 */
#define object_1a_path_object_path_object_path_object_path_object_path_object_path_rest_3_ADDRESS 0x7D2Bu    /* 035D2B */
#define object_1a_dive_path_ADDRESS 0x7D72u    /* 035D72 */
#define object_1a_dive_path_rest_ADDRESS 0x7DD9u    /* 035DD9 */
#define object_1a_dive_path_rest_2_ADDRESS 0x7E80u    /* 035E80 */
#define object_1a_dive_path_rest_3_ADDRESS 0x7E97u    /* 035E97 */
#define object_1a_dive_path_rest_4_ADDRESS 0x7EAEu    /* 035EAE */
#define object_1a_dive_path_rest_5_ADDRESS 0x7F35u    /* 035F35 */
#define object_1a_dive_path_rest_6_ADDRESS 0x7F5Cu    /* 035F5C */
#define kid_in_sunglasses_walk_down_fill_ADDRESS 0x60B4u    /* 0360B4 */
#define door_idle_fill_ADDRESS 0x63C6u    /* 0363C6 */
#define kid_in_sunglasses_setup_box_ADDRESS 0x6400u    /* 036400 */
#define kid_in_sunglasses_setup_box_rest_ADDRESS 0x6408u    /* 036408 */
#define door_kind_12_setup_box_ADDRESS 0x6410u    /* 036410 */
#define kid_in_sunglasses_states_ADDRESS 0x6418u    /* 036418 */
#define kid_in_sunglasses_setup_ADDRESS 0x6430u    /* 036430 */
#define car_doors_states_ADDRESS 0x6436u    /* 036436 */
#define car_doors_setup_ADDRESS 0x644Eu    /* 03644E */
#define door_kind_12_states_ADDRESS 0x6474u    /* 036474 */
#define door_kind_12_setup_ADDRESS 0x6482u    /* 036482 */
#define door_kind_12_enemy_lists_ADDRESS 0x6498u    /* 036498 */
#define door_kind_12_enemy_lists_rest_ADDRESS 0x64A0u    /* 0364A0 */
#define door_kind_12_enemy_lists_rest_2_ADDRESS 0x64B3u    /* 0364B3 */
#define door_kind_12_enemy_lists_rest_3_ADDRESS 0x64C6u    /* 0364C6 */
#define door_kind_12_enemy_lists_rest_4_ADDRESS 0x64D9u    /* 0364D9 */
#define door_kind_10_states_ADDRESS 0x64ECu    /* 0364EC */
#define door_kind_10_setup_ADDRESS 0x64F8u    /* 0364F8 */
#define door_kind_10_enemy_lists_ADDRESS 0x650Au    /* 03650A */
#define door_kind_10_enemy_lists_rest_ADDRESS 0x6512u    /* 036512 */
#define door_kind_10_enemy_lists_rest_2_ADDRESS 0x651Cu    /* 03651C */
#define door_kind_10_enemy_lists_rest_3_ADDRESS 0x6526u    /* 036526 */
#define door_kind_0f_states_ADDRESS 0x6539u    /* 036539 */
#define door_kind_0f_setup_ADDRESS 0x6547u    /* 036547 */
#define door_kind_0f_enemy_lists_ADDRESS 0x655Du    /* 03655D */
#define door_kind_0f_enemy_lists_rest_ADDRESS 0x6565u    /* 036565 */
#define door_kind_0f_enemy_lists_rest_2_ADDRESS 0x6577u    /* 036577 */
#define door_kind_0f_enemy_lists_rest_3_ADDRESS 0x6578u    /* 036578 */
#define spawn_lists_0_ADDRESS 0x659Du    /* 03659D */
#define spawn_lists_1_ADDRESS 0x685Du    /* 03685D */
#define spawn_lists_2_ADDRESS 0x6B8Du    /* 036B8D */
#define spawn_lists_3_ADDRESS 0x6B95u    /* 036B95 */
#define spawn_lists_4_ADDRESS 0x6F15u    /* 036F15 */
#define spawn_lists_5_ADDRESS 0x70C5u    /* 0370C5 */
#define spawn_lists_6_ADDRESS 0x74B5u    /* 0374B5 */
#define spawn_lists_7_ADDRESS 0x77EDu    /* 0377ED */
#define spawn_lists_8_ADDRESS 0x77F5u    /* 0377F5 */
#define spawn_lists_9_ADDRESS 0x7A1Du    /* 037A1D */
#define spawn_lists_10_ADDRESS 0x7E95u    /* 037E95 */
#define spawn_lists_11_ADDRESS 0x7E9Du    /* 037E9D */
#define spawn_lists_11_fill_ADDRESS 0x7ECDu    /* 037ECD */
#define unused_player_play_character_sound_fill_ADDRESS 0x7C5Cu    /* 039C5C */
#define player_state_handlers_ADDRESS 0x7D51u    /* 039D51 */
#define carry_offsets_picking_up_ADDRESS 0x7DD9u    /* 039DD9 */
#define player_use_held_by_kind_ADDRESS 0x7DE1u    /* 039DE1 */
#define player_jump_attack_settings_ADDRESS 0x7E07u    /* 039E07 */
#define player_jump_attack_settings_rest_ADDRESS 0x7E09u    /* 039E09 */
#define player_jump_attack_settings_rest_2_ADDRESS 0x7E0Bu    /* 039E0B */
#define player_jump_attack_settings_rest_3_ADDRESS 0x7E0Du    /* 039E0D */
#define player_jump_attack_settings_rest_4_ADDRESS 0x7E0Fu    /* 039E0F */
#define player_jump_attack_settings_rest_5_ADDRESS 0x7E11u    /* 039E11 */
#define player_jump_attack_settings_rest_6_ADDRESS 0x7E13u    /* 039E13 */
#define player_jump_attack_settings_rest_7_ADDRESS 0x7E15u    /* 039E15 */
#define player_jump_attack_settings_rest_8_ADDRESS 0x7E17u    /* 039E17 */
#define player_jump_attack_settings_rest_9_ADDRESS 0x7E19u    /* 039E19 */
#define carry_offsets_throwing_ADDRESS 0x7E1Bu    /* 039E1B */
#define throw_release_offsets_ADDRESS 0x7E23u    /* 039E23 */
#define hit_spark_height_ADDRESS 0x7E3Bu    /* 039E3B */
#define hit_spark_height_in_air_ADDRESS 0x7E3Cu    /* 039E3C */
#define carry_offsets_still_ADDRESS 0x7E45u    /* 039E45 */
#define carry_offsets_walking_ADDRESS 0x7E55u    /* 039E55 */
#define player_take_touches_table_ADDRESS 0x7E8Du    /* 039E8D */
#define team_moves_by_characters_ADDRESS 0x7EA9u    /* 039EA9 */
#define team_walk_velocities_ADDRESS 0x7F5Du    /* 039F5D */
#define burns_robot_run_fill_ADDRESS 0x600Cu    /* 03A00C */
#define zoom_steps_address_fill_ADDRESS 0x602Cu    /* 03A02C */
#define stage_8_boss_bomb_blast_fill_ADDRESS 0x6924u    /* 03A924 */
#define mr_burns_done_fill_ADDRESS 0x79E3u    /* 03B9E3 */
#define bank_1d_states_ADDRESS 0x7A00u    /* 03BA00 */
#define stage_8_boss_speak_child_ADDRESS 0x7A78u    /* 03BA78 */
#define stage_8_boss_throw_child_1_ADDRESS 0x7A7Eu    /* 03BA7E */
#define stage_8_boss_throw_child_2_ADDRESS 0x7A84u    /* 03BA84 */
#define stage_8_boss_throw_child_3_ADDRESS 0x7A8Cu    /* 03BA8C */
#define stage_8_boss_box_ADDRESS 0x7A94u    /* 03BA94 */
#define stage_8_boss_box_rest_ADDRESS 0x7A96u    /* 03BA96 */
#define stage_8_boss_wind_up_box_ADDRESS 0x7A98u    /* 03BA98 */
#define stage_8_boss_wind_up_box_rest_ADDRESS 0x7A9Au    /* 03BA9A */
#define stage_8_boss_fight_table_ADDRESS 0x7A9Cu    /* 03BA9C */
#define stage_8_boss_hit_limits_address_fill_ADDRESS 0x7AB3u    /* 03BAB3 */
#define stage_8_boss_bomb_states_ADDRESS 0x7AD6u    /* 03BAD6 */
#define stage_8_boss_bomb_blast_box_ADDRESS 0x7ADEu    /* 03BADE */
#define stage_8_boss_bomb_blast_box_rest_ADDRESS 0x7AE0u    /* 03BAE0 */
#define stage_8_boss_bomb_blast_box_rest_2_ADDRESS 0x7AE2u    /* 03BAE2 */
#define burns_robot_states_ADDRESS 0x7AEEu    /* 03BAEE */
#define burns_robot_final_defeat_actions_ADDRESS 0x7B0Au    /* 03BB0A */
#define burns_robot_form_3_broken_actions_ADDRESS 0x7B14u    /* 03BB14 */
#define burns_robot_form_2_broken_actions_ADDRESS 0x7B18u    /* 03BB18 */
#define burns_robot_form_1_broken_actions_ADDRESS 0x7B1Cu    /* 03BB1C */
#define burns_robot_form_0_broken_actions_ADDRESS 0x7B2Au    /* 03BB2A */
#define burns_robot_hurt_actions_ADDRESS 0x7B38u    /* 03BB38 */
#define burns_robot_entrance_actions_ADDRESS 0x7B3Cu    /* 03BB3C */
#define burns_robot_swing_actions_ADDRESS 0x7B4Cu    /* 03BB4C */
#define burns_robot_volley_actions_ADDRESS 0x7B52u    /* 03BB52 */
#define burns_robot_lunge_table_ADDRESS 0x7B5Eu    /* 03BB5E */
#define burns_robot_part_attack_table_ADDRESS 0x7B66u    /* 03BB66 */
#define burns_robot_lob_bombs_table_ADDRESS 0x7B6Eu    /* 03BB6E */
#define burns_robot_gloat_table_ADDRESS 0x7B7Cu    /* 03BB7C */
#define burns_breakout_states_ADDRESS 0x7D99u    /* 03BD99 */
#define burns_tossed_part_states_ADDRESS 0x7DA1u    /* 03BDA1 */
#define burns_debris_steps_ADDRESS 0x7DA5u    /* 03BDA5 */
#define rescued_maggie_states_ADDRESS 0x7DADu    /* 03BDAD */
#define burns_bomb_states_ADDRESS 0x7DCFu    /* 03BDCF */
#define burns_shot_states_ADDRESS 0x7DD7u    /* 03BDD7 */
#define mr_burns_states_ADDRESS 0x7DDBu    /* 03BDDB */
#define zoom_steps_fill_ADDRESS 0x7FC7u    /* 03BFC7 */
#define football_player_run_fill_ADDRESS 0x661Au    /* 03C61A */
#define scripted_object_wait_x_fill_ADDRESS 0x7CE7u    /* 03DCE7 */
#define football_player_states_ADDRESS 0x7D70u    /* 03DD70 */
#define football_player_child_ADDRESS 0x7D9Au    /* 03DD9A */
#define football_player_box_ADDRESS 0x7DA2u    /* 03DDA2 */
#define football_player_box_rest_ADDRESS 0x7DA4u    /* 03DDA4 */
#define football_player_beaten_vitality_ADDRESS 0x7DB9u    /* 03DDB9 */
#define football_player_gauge_healths_ADDRESS 0x7DBDu    /* 03DDBD */
#define football_player_throw_child_ADDRESS 0x7DC2u    /* 03DDC2 */
#define football_player_charge_child_ADDRESS 0x7DC8u    /* 03DDC8 */
#define football_box_ADDRESS 0x7DCEu    /* 03DDCE */
#define football_box_rest_ADDRESS 0x7DD0u    /* 03DDD0 */
#define football_line_piece_box_ADDRESS 0x7DD2u    /* 03DDD2 */
#define football_line_piece_box_rest_ADDRESS 0x7DD4u    /* 03DDD4 */
#define football_line_piece_child_ADDRESS 0x7DE6u    /* 03DDE6 */
#define bear_states_ADDRESS 0x7DECu    /* 03DDEC */
#define bear_start_child_1_ADDRESS 0x7E14u    /* 03DE14 */
#define bear_start_child_2_ADDRESS 0x7E1Cu    /* 03DE1C */
#define bear_start_child_3_ADDRESS 0x7E24u    /* 03DE24 */
#define bear_box_ADDRESS 0x7E50u    /* 03DE50 */
#define bear_box_rest_ADDRESS 0x7E52u    /* 03DE52 */
#define bear_boulder_child_1_ADDRESS 0x7E54u    /* 03DE54 */
#define bear_boulder_child_2_ADDRESS 0x7E5Cu    /* 03DE5C */
#define bear_beaten_vitality_ADDRESS 0x7E67u    /* 03DE67 */
#define bear_gauge_healths_ADDRESS 0x7E6Bu    /* 03DE6B */
#define bear_walk_speeds_ADDRESS 0x7E70u    /* 03DE70 */
#define bear_charge_box_ADDRESS 0x7E90u    /* 03DE90 */
#define bear_charge_box_rest_ADDRESS 0x7E92u    /* 03DE92 */
#define bear_change_child_ADDRESS 0x7E94u    /* 03DE94 */
#define bear_knocked_away_table_ADDRESS 0x7ECCu    /* 03DECC */
#define stage_3_boss_states_ADDRESS 0x7EDCu    /* 03DEDC */
#define stage_3_boss_child_ADDRESS 0x7F08u    /* 03DF08 */
#define stage_3_boss_arrive_child_ADDRESS 0x7F10u    /* 03DF10 */
#define stage_3_boss_box_ADDRESS 0x7F16u    /* 03DF16 */
#define stage_3_boss_box_rest_ADDRESS 0x7F18u    /* 03DF18 */
#define stage_3_boss_box_rest_2_ADDRESS 0x7F1Au    /* 03DF1A */
#define stage_3_boss_box_rest_3_ADDRESS 0x7F1Cu    /* 03DF1C */
#define stage_3_boss_box_rest_4_ADDRESS 0x7F1Eu    /* 03DF1E */
#define stage_3_boss_box_rest_5_ADDRESS 0x7F20u    /* 03DF20 */
#define stage_3_boss_attack_box_ADDRESS 0x7F22u    /* 03DF22 */
#define stage_3_boss_attack_box_rest_ADDRESS 0x7F24u    /* 03DF24 */
#define stage_3_boss_attack_box_rest_2_ADDRESS 0x7F26u    /* 03DF26 */
#define stage_3_boss_attack_box_rest_3_ADDRESS 0x7F28u    /* 03DF28 */
#define stage_3_boss_attack_box_rest_4_ADDRESS 0x7F2Au    /* 03DF2A */
#define stage_3_boss_attack_box_rest_5_ADDRESS 0x7F2Cu    /* 03DF2C */
#define stage_3_bosses_joined_box_ADDRESS 0x7F2Eu    /* 03DF2E */
#define stage_3_bosses_joined_box_rest_ADDRESS 0x7F30u    /* 03DF30 */
#define stage_3_boss_strike_box_ADDRESS 0x7F32u    /* 03DF32 */
#define stage_3_boss_strike_box_rest_ADDRESS 0x7F34u    /* 03DF34 */
#define stage_3_boss_beaten_vitality_ADDRESS 0x7F3Du    /* 03DF3D */
#define stage_3_boss_walk_speeds_1_ADDRESS 0x7F42u    /* 03DF42 */
#define stage_3_boss_walk_speeds_2_ADDRESS 0x7F52u    /* 03DF52 */
#define bank_1e_states_ADDRESS 0x7F62u    /* 03DF62 */
#define marge_cloud_box_ADDRESS 0x7F9Au    /* 03DF9A */
#define marge_cloud_box_rest_ADDRESS 0x7F9Cu    /* 03DF9C */
#define marge_cloud_windup_box_ADDRESS 0x7F9Eu    /* 03DF9E */
#define marge_cloud_windup_box_rest_ADDRESS 0x7FA0u    /* 03DFA0 */
#define marge_cloud_windup_box_rest_2_ADDRESS 0x7FA2u    /* 03DFA2 */
#define scripted_object_commands_ADDRESS 0x7FAAu    /* 03DFAA */
#define story_scripts_19_ADDRESS 0x662Eu    /* 03E62E */
#define story_scripts_84_ADDRESS 0x68A7u    /* 03E8A7 */
#define story_scripts_85_ADDRESS 0x68C0u    /* 03E8C0 */
#define story_scripts_88_ADDRESS 0x68E4u    /* 03E8E4 */
#define story_scripts_89_ADDRESS 0x690Du    /* 03E90D */
#define story_scripts_76_ADDRESS 0x6978u    /* 03E978 */
#define story_scripts_77_ADDRESS 0x6993u    /* 03E993 */
#define story_next_player_fill_ADDRESS 0x69BAu    /* 03E9BA */
#define player_update_class_fill_ADDRESS 0x6D54u    /* 03ED54 */
#define story_actor_operations_ADDRESS 0x7000u    /* 03F000 */
#define player_line_up_orders_ADDRESS 0x704Cu    /* 03F04C */
#define story_player_place_offsets_ADDRESS 0x705Cu    /* 03F05C */
#define story_scripts_64_ADDRESS 0x706Cu    /* 03F06C */
#define story_scripts_11_ADDRESS 0x7150u    /* 03F150 */
#define story_scripts_57_ADDRESS 0x71BDu    /* 03F1BD */
#define story_scripts_17_ADDRESS 0x725Fu    /* 03F25F */
#define story_scripts_21_ADDRESS 0x72D7u    /* 03F2D7 */
#define story_scripts_22_ADDRESS 0x72F6u    /* 03F2F6 */
#define story_scripts_23_ADDRESS 0x731Au    /* 03F31A */
#define story_scripts_25_ADDRESS 0x7376u    /* 03F376 */
#define story_scripts_45_ADDRESS 0x7403u    /* 03F403 */
#define story_scripts_68_ADDRESS 0x7489u    /* 03F489 */
#define story_scripts_29_ADDRESS 0x75E2u    /* 03F5E2 */
#define story_scripts_31_ADDRESS 0x7647u    /* 03F647 */
#define story_scripts_33_ADDRESS 0x76F6u    /* 03F6F6 */
#define story_scripts_13_ADDRESS 0x782Du    /* 03F82D */
#define story_scripts_14_ADDRESS 0x7846u    /* 03F846 */
#define story_scripts_1_ADDRESS 0x78F5u    /* 03F8F5 */
#define story_scripts_7_ADDRESS 0x7997u    /* 03F997 */
#define story_scripts_37_ADDRESS 0x7A56u    /* 03FA56 */
#define story_scripts_43_ADDRESS 0x7B84u    /* 03FB84 */
#define story_scripts_81_ADDRESS 0x7BA1u    /* 03FBA1 */
#define story_scripts_49_ADDRESS 0x7BC1u    /* 03FBC1 */
#define story_scripts_52_ADDRESS 0x7BDAu    /* 03FBDA */
#define story_scripts_53_ADDRESS 0x7CCCu    /* 03FCCC */
#define story_scripts_92_ADDRESS 0x7D67u    /* 03FD67 */
#define story_scripts_93_ADDRESS 0x7DAAu    /* 03FDAA */
#define story_scripts_100_ADDRESS 0x7E24u    /* 03FE24 */
#define story_scripts_101_ADDRESS 0x7E31u    /* 03FE31 */
#define story_scripts_97_ADDRESS 0x7E4Du    /* 03FE4D */
#define player_second_sprite_run_table_ADDRESS 0x7E5Bu    /* 03FE5B */
#define story_scene_settings_ADDRESS 0x7EDCu    /* 03FEDC */
#define set_spawn_level_fill_ADDRESS 0x6D4Cu    /* 040D4C */
#define attract_opening_scenes_ADDRESS 0x7000u    /* 041000 */
#define attract_opening_phases_ADDRESS 0x7010u    /* 041010 */
#define attract_opening_end_phases_ADDRESS 0x7014u    /* 041014 */
#define attract_bart_phases_ADDRESS 0x701Au    /* 04101A */
#define attract_homer_phases_ADDRESS 0x7026u    /* 041026 */
#define attract_lisa_phases_ADDRESS 0x7032u    /* 041032 */
#define attract_marge_phases_ADDRESS 0x703Eu    /* 04103E */
#define attract_leap_phases_ADDRESS 0x704Cu    /* 04104C */
#define attract_last_screen_phases_ADDRESS 0x7056u    /* 041056 */
#define attract_profile_move_steps_ADDRESS 0x705Au    /* 04105A */
#define attract_opening_picture_ADDRESS 0x7066u    /* 041066 */
#define attract_bart_scene_picture_ADDRESS 0x706Bu    /* 04106B */
#define attract_homer_scene_picture_ADDRESS 0x7070u    /* 041070 */
#define attract_lisa_scene_picture_1_ADDRESS 0x7075u    /* 041075 */
#define attract_lisa_scene_picture_2_ADDRESS 0x707Au    /* 04107A */
#define attract_marge_scene_picture_2_ADDRESS 0x7089u    /* 041089 */
#define attract_marge_scene_picture_1_ADDRESS 0x708Eu    /* 04108E */
#define attract_marge_scene_moving_picture_ADDRESS 0x7093u    /* 041093 */
#define attract_leap_picture_2_ADDRESS 0x7098u    /* 041098 */
#define attract_marge_scene_picture_3_ADDRESS 0x709Du    /* 04109D */
#define attract_marge_scene_picture_4_ADDRESS 0x70A2u    /* 0410A2 */
#define attract_leap_picture_1_ADDRESS 0x70A7u    /* 0410A7 */
#define attract_leap_picture_3_ADDRESS 0x70ACu    /* 0410AC */
#define attract_bart_profile_pictures_ADDRESS 0x70B1u    /* 0410B1 */
#define attract_homer_profile_pictures_ADDRESS 0x70BBu    /* 0410BB */
#define attract_lisa_profile_pictures_ADDRESS 0x70C5u    /* 0410C5 */
#define attract_marge_profile_pictures_ADDRESS 0x70CFu    /* 0410CF */
#define attract_maggie_profile_pictures_ADDRESS 0x70D9u    /* 0410D9 */
#define profile_texts_0_ADDRESS 0x7118u    /* 041118 */
#define profile_texts_1_ADDRESS 0x714Au    /* 04114A */
#define profile_texts_2_ADDRESS 0x7170u    /* 041170 */
#define profile_texts_3_ADDRESS 0x7199u    /* 041199 */
#define profile_texts_4_ADDRESS 0x71BDu    /* 0411BD */
#define profile_texts_5_ADDRESS 0x71EEu    /* 0411EE */
#define profile_texts_6_ADDRESS 0x7209u    /* 041209 */
#define profile_texts_7_ADDRESS 0x724Cu    /* 04124C */
#define profile_texts_8_ADDRESS 0x726Bu    /* 04126B */
#define gauge_pictures_rest_ADDRESS 0x732Cu    /* 04132C */
#define gauge_pictures_rest_2_ADDRESS 0x733Bu    /* 04133B */
#define gauge_pictures_rest_3_ADDRESS 0x7344u    /* 041344 */
#define gauge_pictures_rest_4_ADDRESS 0x7358u    /* 041358 */
#define gauge_pictures_rest_5_ADDRESS 0x7370u    /* 041370 */
#define gauge_pictures_rest_6_ADDRESS 0x7388u    /* 041388 */
#define gauge_pictures_rest_7_ADDRESS 0x73A6u    /* 0413A6 */
#define gauge_pictures_rest_8_ADDRESS 0x73B5u    /* 0413B5 */
#define gauge_pictures_rest_9_ADDRESS 0x73C4u    /* 0413C4 */
#define gauge_pictures_rest_10_ADDRESS 0x73D3u    /* 0413D3 */
#define gauge_pictures_rest_11_ADDRESS 0x73E2u    /* 0413E2 */
#define continue_count_blank_picture_ADDRESS 0x7405u    /* 041405 */
#define continue_count_blank_picture_rest_ADDRESS 0x7448u    /* 041448 */
#define continue_count_blank_picture_rest_2_ADDRESS 0x748Bu    /* 04148B */
#define continue_count_blank_picture_rest_3_ADDRESS 0x74CEu    /* 0414CE */
#define continue_count_blank_picture_rest_4_ADDRESS 0x7511u    /* 041511 */
#define continue_count_blank_picture_rest_5_ADDRESS 0x7554u    /* 041554 */
#define continue_count_blank_picture_rest_6_ADDRESS 0x7597u    /* 041597 */
#define continue_count_blank_picture_rest_7_ADDRESS 0x75DAu    /* 0415DA */
#define continue_count_blank_picture_rest_8_ADDRESS 0x761Du    /* 04161D */
#define continue_count_blank_picture_rest_9_ADDRESS 0x7660u    /* 041660 */
#define continue_picture_ADDRESS 0x76A3u    /* 0416A3 */
#define game_over_picture_ADDRESS 0x76F4u    /* 0416F4 */
#define credit_picture_ADDRESS 0x7745u    /* 041745 */
#define bcd_bit_values_ADDRESS 0x777Au    /* 04177A */
#define rank_frame_limits_fill_ADDRESS 0x77C4u    /* 0417C4 */
#define rank_frame_limits_rest_ADDRESS 0x6000u    /* 042000 */
#define speech_balloons_animations_ADDRESS 0x6016u    /* 042016 */
#define speech_balloons_animations_0_ADDRESS 0x6020u    /* 042020 */
#define speech_balloons_animations_0_sprites_ADDRESS 0x6028u    /* 042028 */
#define speech_balloons_animations_1_ADDRESS 0x604Cu    /* 04204C */
#define speech_balloons_animations_1_sprites_ADDRESS 0x6054u    /* 042054 */
#define speech_balloons_animations_2_ADDRESS 0x6078u    /* 042078 */
#define speech_balloons_animations_2_sprites_ADDRESS 0x6080u    /* 042080 */
#define speech_balloons_animations_3_ADDRESS 0x60B0u    /* 0420B0 */
#define speech_balloons_animations_3_sprites_ADDRESS 0x60B8u    /* 0420B8 */
#define speech_balloons_animations_4_ADDRESS 0x60E8u    /* 0420E8 */
#define speech_balloons_animations_4_sprites_ADDRESS 0x60F0u    /* 0420F0 */
#define speech_balloons_2_animations_ADDRESS 0x6120u    /* 042120 */
#define speech_balloons_2_animations_3_ADDRESS 0x6150u    /* 042150 */
#define speech_balloons_2_animations_3_sprites_ADDRESS 0x6158u    /* 042158 */
#define speech_balloons_2_animations_0_ADDRESS 0x6164u    /* 042164 */
#define speech_balloons_2_animations_0_sprites_ADDRESS 0x616Cu    /* 04216C */
#define speech_balloons_2_animations_1_ADDRESS 0x6196u    /* 042196 */
#define speech_balloons_2_animations_1_sprites_ADDRESS 0x619Eu    /* 04219E */
#define speech_balloons_2_animations_4_ADDRESS 0x61C8u    /* 0421C8 */
#define speech_balloons_2_animations_4_sprites_ADDRESS 0x61D0u    /* 0421D0 */
#define speech_balloons_2_animations_8_ADDRESS 0x61EEu    /* 0421EE */
#define speech_balloons_2_animations_8_sprites_ADDRESS 0x61F6u    /* 0421F6 */
#define speech_balloons_2_animations_12_ADDRESS 0x621Au    /* 04221A */
#define speech_balloons_2_animations_12_sprites_ADDRESS 0x6222u    /* 042222 */
#define speech_balloons_2_animations_16_ADDRESS 0x624Cu    /* 04224C */
#define speech_balloons_2_animations_16_sprites_ADDRESS 0x6254u    /* 042254 */
#define speech_balloons_2_animations_20_ADDRESS 0x627Eu    /* 04227E */
#define speech_balloons_2_animations_20_sprites_ADDRESS 0x6286u    /* 042286 */
#define speech_balloons_2_animations_5_ADDRESS 0x62AAu    /* 0422AA */
#define speech_balloons_2_animations_5_sprites_ADDRESS 0x62B2u    /* 0422B2 */
#define speech_balloons_2_animations_9_ADDRESS 0x62E2u    /* 0422E2 */
#define speech_balloons_2_animations_9_sprites_ADDRESS 0x62EAu    /* 0422EA */
#define speech_balloons_2_animations_13_ADDRESS 0x6314u    /* 042314 */
#define speech_balloons_2_animations_13_sprites_ADDRESS 0x631Cu    /* 04231C */
#define speech_balloons_2_animations_17_ADDRESS 0x633Au    /* 04233A */
#define speech_balloons_2_animations_17_sprites_ADDRESS 0x6342u    /* 042342 */
#define speech_balloons_2_animations_21_ADDRESS 0x636Cu    /* 04236C */
#define speech_balloons_2_animations_21_sprites_ADDRESS 0x6374u    /* 042374 */
#define speech_balloons_2_animations_6_ADDRESS 0x63A4u    /* 0423A4 */
#define speech_balloons_2_animations_6_sprites_ADDRESS 0x63ACu    /* 0423AC */
#define speech_balloons_2_animations_10_ADDRESS 0x63D0u    /* 0423D0 */
#define speech_balloons_2_animations_10_sprites_ADDRESS 0x63D8u    /* 0423D8 */
#define speech_balloons_2_animations_14_ADDRESS 0x6402u    /* 042402 */
#define speech_balloons_2_animations_14_sprites_ADDRESS 0x640Au    /* 04240A */
#define speech_balloons_2_animations_18_ADDRESS 0x642Eu    /* 04242E */
#define speech_balloons_2_animations_18_sprites_ADDRESS 0x6436u    /* 042436 */
#define speech_balloons_2_animations_22_ADDRESS 0x6454u    /* 042454 */
#define speech_balloons_2_animations_22_sprites_ADDRESS 0x645Cu    /* 04245C */
#define speech_balloons_2_animations_7_ADDRESS 0x6474u    /* 042474 */
#define speech_balloons_2_animations_7_sprites_ADDRESS 0x647Cu    /* 04247C */
#define speech_balloons_2_animations_11_ADDRESS 0x64A6u    /* 0424A6 */
#define speech_balloons_2_animations_11_sprites_ADDRESS 0x64AEu    /* 0424AE */
#define speech_balloons_2_animations_15_ADDRESS 0x64C6u    /* 0424C6 */
#define speech_balloons_2_animations_15_sprites_ADDRESS 0x64CEu    /* 0424CE */
#define speech_balloons_2_animations_19_ADDRESS 0x64FEu    /* 0424FE */
#define speech_balloons_2_animations_19_sprites_ADDRESS 0x6506u    /* 042506 */
#define speech_balloons_2_animations_23_ADDRESS 0x652Au    /* 04252A */
#define speech_balloons_2_animations_23_sprites_ADDRESS 0x6532u    /* 042532 */
#define speech_balloons_2_animations_2_ADDRESS 0x6562u    /* 042562 */
#define speech_balloons_2_animations_2_sprites_ADDRESS 0x656Au    /* 04256A */
#define caged_gorilla_animations_ADDRESS 0x65CAu    /* 0425CA */
#define caged_gorilla_animations_0_ADDRESS 0x65D6u    /* 0425D6 */
#define caged_gorilla_animations_0_sprites_ADDRESS 0x65E2u    /* 0425E2 */
#define caged_gorilla_animations_0_sprites_2_ADDRESS 0x65F4u    /* 0425F4 */
#define caged_gorilla_animations_1_ADDRESS 0x6606u    /* 042606 */
#define caged_gorilla_animations_1_sprites_ADDRESS 0x6612u    /* 042612 */
#define caged_gorilla_animations_1_sprites_2_ADDRESS 0x6630u    /* 042630 */
#define caged_gorilla_animations_2_ADDRESS 0x664Eu    /* 04264E */
#define caged_gorilla_animations_2_sprites_ADDRESS 0x6656u    /* 042656 */
#define caged_gorilla_animations_3_ADDRESS 0x6674u    /* 042674 */
#define caged_gorilla_animations_3_sprites_ADDRESS 0x667Cu    /* 04267C */
#define caged_gorilla_animations_4_ADDRESS 0x66A0u    /* 0426A0 */
#define caged_gorilla_animations_4_sprites_ADDRESS 0x66A8u    /* 0426A8 */
#define caged_gorilla_animations_5_ADDRESS 0x66CCu    /* 0426CC */
#define kent_brockman_animations_ADDRESS 0x66D8u    /* 0426D8 */
#define kent_brockman_animations_0_ADDRESS 0x66E0u    /* 0426E0 */
#define kent_brockman_animations_0_sprites_ADDRESS 0x66F4u    /* 0426F4 */
#define kent_brockman_animations_0_sprites_2_ADDRESS 0x6700u    /* 042700 */
#define kent_brockman_animations_0_sprites_3_ADDRESS 0x670Cu    /* 04270C */
#define kent_brockman_animations_1_ADDRESS 0x6718u    /* 042718 */
#define kent_brockman_animations_1_sprites_ADDRESS 0x6720u    /* 042720 */
#define kent_brockman_animations_2_ADDRESS 0x672Cu    /* 04272C */
#define kent_brockman_animations_2_sprites_ADDRESS 0x6738u    /* 042738 */
#define kent_brockman_animations_2_sprites_2_ADDRESS 0x674Au    /* 04274A */
#define kent_brockman_animations_3_ADDRESS 0x675Cu    /* 04275C */
#define kent_brockman_animations_3_sprites_ADDRESS 0x6764u    /* 042764 */
#define octopus_animations_ADDRESS 0x677Cu    /* 04277C */
#define octopus_animations_0_ADDRESS 0x6784u    /* 042784 */
#define octopus_animations_0_sprites_ADDRESS 0x6790u    /* 042790 */
#define octopus_animations_0_sprites_2_ADDRESS 0x6796u    /* 042796 */
#define octopus_animations_1_ADDRESS 0x679Cu    /* 04279C */
#define octopus_animations_1_sprites_ADDRESS 0x67ACu    /* 0427AC */
#define octopus_animations_1_sprites_2_ADDRESS 0x67B8u    /* 0427B8 */
#define octopus_animations_1_sprites_3_ADDRESS 0x67C4u    /* 0427C4 */
#define octopus_animations_2_ADDRESS 0x67D0u    /* 0427D0 */
#define octopus_animations_2_sprites_ADDRESS 0x67E4u    /* 0427E4 */
#define octopus_animations_2_sprites_2_ADDRESS 0x67EAu    /* 0427EA */
#define octopus_animations_2_sprites_3_ADDRESS 0x67F0u    /* 0427F0 */
#define octopus_animations_3_ADDRESS 0x6802u    /* 042802 */
#define octopus_animations_3_sprites_ADDRESS 0x6816u    /* 042816 */
#define octopus_animations_3_sprites_2_ADDRESS 0x6822u    /* 042822 */
#define octopus_animations_3_sprites_3_ADDRESS 0x682Eu    /* 04282E */
#define schoolboy_with_books_animations_ADDRESS 0x6846u    /* 042846 */
#define schoolboy_with_books_animations_0_ADDRESS 0x684Au    /* 04284A */
#define schoolboy_with_books_animations_0_sprites_ADDRESS 0x686Au    /* 04286A */
#define schoolboy_with_books_animations_0_sprites_2_ADDRESS 0x6876u    /* 042876 */
#define schoolboy_with_books_animations_0_sprites_3_ADDRESS 0x6882u    /* 042882 */
#define schoolboy_with_books_animations_1_ADDRESS 0x688Eu    /* 04288E */
#define schoolboy_with_books_animations_1_sprites_ADDRESS 0x68B2u    /* 0428B2 */
#define schoolboy_with_books_animations_1_sprites_2_ADDRESS 0x68C4u    /* 0428C4 */
#define schoolboy_with_books_animations_1_sprites_3_ADDRESS 0x68D6u    /* 0428D6 */
#define schoolboy_with_books_animations_1_sprites_4_ADDRESS 0x68E8u    /* 0428E8 */
#define schoolboy_with_books_animations_1_sprites_5_ADDRESS 0x68FAu    /* 0428FA */
#define bluebird_animations_ADDRESS 0x690Cu    /* 04290C */
#define bluebird_animations_0_ADDRESS 0x6916u    /* 042916 */
#define bluebird_animations_0_sprites_ADDRESS 0x691Eu    /* 04291E */
#define bluebird_animations_1_ADDRESS 0x6924u    /* 042924 */
#define bluebird_animations_1_sprites_ADDRESS 0x6930u    /* 042930 */
#define bluebird_animations_2_ADDRESS 0x6936u    /* 042936 */
#define bluebird_animations_2_sprites_ADDRESS 0x6942u    /* 042942 */
#define bluebird_animations_2_sprites_2_ADDRESS 0x6948u    /* 042948 */
#define bluebird_animations_3_ADDRESS 0x694Eu    /* 04294E */
#define bluebird_animations_3_sprites_ADDRESS 0x695Au    /* 04295A */
#define bluebird_animations_3_sprites_2_ADDRESS 0x6960u    /* 042960 */
#define bluebird_animations_4_ADDRESS 0x6966u    /* 042966 */
#define bluebird_animations_4_sprites_ADDRESS 0x6972u    /* 042972 */
#define bluebird_animations_4_sprites_2_ADDRESS 0x6978u    /* 042978 */
#define ninja_animations_ADDRESS 0x697Eu    /* 04297E */
#define ninja_animations_rest_ADDRESS 0x69CEu    /* 0429CE */
#define ninja_animations_rest_2_ADDRESS 0x69D6u    /* 0429D6 */
#define ninja_animations_0_ADDRESS 0x69E2u    /* 0429E2 */
#define ninja_animations_0_sprites_ADDRESS 0x6A06u    /* 042A06 */
#define ninja_animations_0_sprites_2_ADDRESS 0x6A12u    /* 042A12 */
#define ninja_animations_0_sprites_3_ADDRESS 0x6A1Eu    /* 042A1E */
#define ninja_animations_3_ADDRESS 0x6A2Au    /* 042A2A */
#define ninja_animations_3_sprites_ADDRESS 0x6A4Eu    /* 042A4E */
#define ninja_animations_3_sprites_2_ADDRESS 0x6A5Au    /* 042A5A */
#define ninja_animations_3_sprites_3_ADDRESS 0x6A66u    /* 042A66 */
#define ninja_animations_38_ADDRESS 0x6A72u    /* 042A72 */
#define ninja_animations_38_sprites_ADDRESS 0x6A96u    /* 042A96 */
#define ninja_animations_38_sprites_2_ADDRESS 0x6AA2u    /* 042AA2 */
#define ninja_animations_38_sprites_3_ADDRESS 0x6AB4u    /* 042AB4 */
#define ninja_animations_16_ADDRESS 0x6AC0u    /* 042AC0 */
#define ninja_animations_16_sprites_ADDRESS 0x6AE4u    /* 042AE4 */
#define ninja_animations_16_sprites_2_ADDRESS 0x6AF0u    /* 042AF0 */
#define ninja_animations_16_sprites_3_ADDRESS 0x6AFCu    /* 042AFC */
#define ninja_animations_16_sprites_4_ADDRESS 0x6B0Eu    /* 042B0E */
#define ninja_animations_16_sprites_5_ADDRESS 0x6B20u    /* 042B20 */
#define ninja_animations_16_sprites_6_ADDRESS 0x6B38u    /* 042B38 */
#define ninja_animations_17_ADDRESS 0x6B50u    /* 042B50 */
#define ninja_animations_17_sprites_ADDRESS 0x6B74u    /* 042B74 */
#define ninja_animations_17_sprites_2_ADDRESS 0x6B80u    /* 042B80 */
#define ninja_animations_17_sprites_3_ADDRESS 0x6B86u    /* 042B86 */
#define ninja_animations_17_sprites_4_ADDRESS 0x6B8Cu    /* 042B8C */
#define ninja_animations_17_sprites_5_ADDRESS 0x6B98u    /* 042B98 */
#define ninja_animations_17_sprites_6_ADDRESS 0x6BA4u    /* 042BA4 */
#define ninja_animations_18_ADDRESS 0x6BB0u    /* 042BB0 */
#define ninja_animations_18_sprites_ADDRESS 0x6BDCu    /* 042BDC */
#define ninja_animations_18_sprites_2_ADDRESS 0x6BE8u    /* 042BE8 */
#define ninja_animations_18_sprites_3_ADDRESS 0x6BF4u    /* 042BF4 */
#define ninja_animations_18_sprites_4_ADDRESS 0x6C06u    /* 042C06 */
#define ninja_animations_18_sprites_5_ADDRESS 0x6C12u    /* 042C12 */
#define ninja_animations_18_sprites_6_ADDRESS 0x6C24u    /* 042C24 */
#define ninja_animations_31_ADDRESS 0x6C30u    /* 042C30 */
#define ninja_animations_31_sprites_ADDRESS 0x6C44u    /* 042C44 */
#define ninja_animations_31_sprites_2_ADDRESS 0x6C4Au    /* 042C4A */
#define ninja_animations_31_sprites_3_ADDRESS 0x6C50u    /* 042C50 */
#define ninja_animations_31_sprites_4_ADDRESS 0x6C56u    /* 042C56 */
#define ninja_animations_19_ADDRESS 0x6C5Cu    /* 042C5C */
#define ninja_animations_19_sprites_ADDRESS 0x6C74u    /* 042C74 */
#define ninja_animations_19_sprites_2_ADDRESS 0x6C7Au    /* 042C7A */
#define ninja_animations_19_sprites_3_ADDRESS 0x6C80u    /* 042C80 */
#define ninja_animations_21_ADDRESS 0x6C86u    /* 042C86 */
#define ninja_animations_21_sprites_ADDRESS 0x6CBAu    /* 042CBA */
#define ninja_animations_21_sprites_2_ADDRESS 0x6CC0u    /* 042CC0 */
#define ninja_animations_21_sprites_3_ADDRESS 0x6CC6u    /* 042CC6 */
#define ninja_animations_21_sprites_4_ADDRESS 0x6CCCu    /* 042CCC */
#define ninja_animations_21_sprites_5_ADDRESS 0x6CD2u    /* 042CD2 */
#define ninja_animations_21_sprites_6_ADDRESS 0x6CD8u    /* 042CD8 */
#define ninja_animations_21_sprites_7_ADDRESS 0x6CDEu    /* 042CDE */
#define ninja_animations_21_sprites_8_ADDRESS 0x6CE4u    /* 042CE4 */
#define ninja_animations_21_sprites_9_ADDRESS 0x6CEAu    /* 042CEA */
#define ninja_animations_21_sprites_10_ADDRESS 0x6CF0u    /* 042CF0 */
#define ninja_animations_21_sprites_11_ADDRESS 0x6CFCu    /* 042CFC */
#define ninja_animations_22_ADDRESS 0x6D02u    /* 042D02 */
#define ninja_animations_23_ADDRESS 0x6D2Au    /* 042D2A */
#define ninja_animations_24_ADDRESS 0x6D32u    /* 042D32 */
#define ninja_animations_24_sprites_ADDRESS 0x6D46u    /* 042D46 */
#define ninja_animations_24_sprites_2_ADDRESS 0x6D52u    /* 042D52 */
#define ninja_animations_24_sprites_3_ADDRESS 0x6D5Eu    /* 042D5E */
#define ninja_animations_24_sprites_4_ADDRESS 0x6D6Au    /* 042D6A */
#define ninja_animations_25_ADDRESS 0x6D76u    /* 042D76 */
#define ninja_animations_25_sprites_ADDRESS 0x6DA2u    /* 042DA2 */
#define ninja_animations_25_sprites_2_ADDRESS 0x6DBAu    /* 042DBA */
#define ninja_animations_25_sprites_3_ADDRESS 0x6DC6u    /* 042DC6 */
#define ninja_animations_25_sprites_4_ADDRESS 0x6DD2u    /* 042DD2 */
#define ninja_animations_25_sprites_5_ADDRESS 0x6DE4u    /* 042DE4 */
#define ninja_animations_25_sprites_6_ADDRESS 0x6DF0u    /* 042DF0 */
#define ninja_animations_25_sprites_7_ADDRESS 0x6E02u    /* 042E02 */
#define ninja_animations_25_sprites_8_ADDRESS 0x6E0Eu    /* 042E0E */
#define ninja_animations_25_sprites_9_ADDRESS 0x6E1Au    /* 042E1A */
#define ninja_animations_26_ADDRESS 0x6E2Cu    /* 042E2C */
#define ninja_animations_26_sprites_ADDRESS 0x6E38u    /* 042E38 */
#define ninja_animations_27_ADDRESS 0x6E44u    /* 042E44 */
#define ninja_animations_27_sprites_ADDRESS 0x6E58u    /* 042E58 */
#define ninja_animations_27_sprites_2_ADDRESS 0x6E64u    /* 042E64 */
#define ninja_animations_27_sprites_3_ADDRESS 0x6E6Au    /* 042E6A */
#define ninja_animations_28_ADDRESS 0x6E70u    /* 042E70 */
#define ninja_animations_28_sprites_ADDRESS 0x6E80u    /* 042E80 */
#define ninja_animations_28_sprites_2_ADDRESS 0x6E8Cu    /* 042E8C */
#define ninja_animations_29_ADDRESS 0x6E92u    /* 042E92 */
#define ninja_animations_29_sprites_ADDRESS 0x6E9Eu    /* 042E9E */
#define ninja_animations_29_sprites_2_ADDRESS 0x6EA4u    /* 042EA4 */
#define ninja_animations_15_ADDRESS 0x6EB0u    /* 042EB0 */
#define ninja_animations_15_sprites_ADDRESS 0x6EB8u    /* 042EB8 */
#define ninja_animations_4_ADDRESS 0x6ED0u    /* 042ED0 */
#define ninja_animations_8_ADDRESS 0x6ED8u    /* 042ED8 */
#define ninja_animations_8_sprites_ADDRESS 0x6EF4u    /* 042EF4 */
#define ninja_animations_8_sprites_2_ADDRESS 0x6F00u    /* 042F00 */
#define ninja_animations_8_sprites_3_ADDRESS 0x6F12u    /* 042F12 */
#define ninja_animations_8_sprites_4_ADDRESS 0x6F1Eu    /* 042F1E */
#define ninja_animations_33_ADDRESS 0x6F2Au    /* 042F2A */
#define ninja_animations_34_ADDRESS 0x6F3Eu    /* 042F3E */
#define ninja_animations_34_sprites_ADDRESS 0x6F6Au    /* 042F6A */
#define ninja_animations_34_sprites_2_ADDRESS 0x6F82u    /* 042F82 */
#define ninja_animations_34_sprites_3_ADDRESS 0x6F8Eu    /* 042F8E */
#define ninja_animations_34_sprites_4_ADDRESS 0x6F9Au    /* 042F9A */
#define ninja_animations_34_sprites_5_ADDRESS 0x6FACu    /* 042FAC */
#define ninja_animations_34_sprites_6_ADDRESS 0x6FB8u    /* 042FB8 */
#define ninja_animations_34_sprites_7_ADDRESS 0x6FCAu    /* 042FCA */
#define ninja_animations_34_sprites_8_ADDRESS 0x6FD6u    /* 042FD6 */
#define ninja_animations_34_sprites_9_ADDRESS 0x6FE2u    /* 042FE2 */
#define ninja_animations_6_ADDRESS 0x6FF4u    /* 042FF4 */
#define ninja_animations_6_sprites_ADDRESS 0x7024u    /* 043024 */
#define ninja_animations_6_sprites_2_ADDRESS 0x7030u    /* 043030 */
#define ninja_animations_6_sprites_3_ADDRESS 0x7042u    /* 043042 */
#define ninja_animations_6_sprites_4_ADDRESS 0x7054u    /* 043054 */
#define ninja_animations_6_sprites_5_ADDRESS 0x7066u    /* 043066 */
#define ninja_animations_6_sprites_6_ADDRESS 0x707Eu    /* 04307E */
#define ninja_animations_6_sprites_7_ADDRESS 0x7090u    /* 043090 */
#define ninja_animations_6_sprites_8_ADDRESS 0x70A8u    /* 0430A8 */
#define ninja_animations_36_ADDRESS 0x70BAu    /* 0430BA */
#define ninja_animations_36_sprites_ADDRESS 0x70DAu    /* 0430DA */
#define ninja_animations_36_sprites_2_ADDRESS 0x70E6u    /* 0430E6 */
#define ninja_animations_36_sprites_3_ADDRESS 0x70F2u    /* 0430F2 */
#define ninja_animations_36_sprites_4_ADDRESS 0x7104u    /* 043104 */
#define ninja_animations_36_sprites_5_ADDRESS 0x711Cu    /* 04311C */
#define ninja_animations_37_ADDRESS 0x713Au    /* 04313A */
#define ninja_animations_37_sprites_ADDRESS 0x7166u    /* 043166 */
#define ninja_animations_9_ADDRESS 0x7178u    /* 043178 */
#define ninja_animations_9_sprites_ADDRESS 0x71A4u    /* 0431A4 */
#define ninja_animations_9_sprites_2_ADDRESS 0x71C2u    /* 0431C2 */
#define ninja_animations_9_sprites_3_ADDRESS 0x71DAu    /* 0431DA */
#define ninja_animations_9_sprites_4_ADDRESS 0x71ECu    /* 0431EC */
#define ninja_animations_9_sprites_5_ADDRESS 0x71FEu    /* 0431FE */
#define ninja_animations_9_sprites_6_ADDRESS 0x7210u    /* 043210 */
#define ninja_animations_9_sprites_7_ADDRESS 0x7222u    /* 043222 */
#define ninja_animations_39_ADDRESS 0x7234u    /* 043234 */
#define kabuki_warrior_animations_ADDRESS 0x723Cu    /* 04323C */
#define kabuki_warrior_animations_0_ADDRESS 0x7254u    /* 043254 */
#define kabuki_warrior_animations_0_sprites_ADDRESS 0x726Cu    /* 04326C */
#define kabuki_warrior_animations_0_sprites_2_ADDRESS 0x728Au    /* 04328A */
#define kabuki_warrior_animations_0_sprites_3_ADDRESS 0x72A8u    /* 0432A8 */
#define kabuki_warrior_animations_0_sprites_4_ADDRESS 0x72C6u    /* 0432C6 */
#define kabuki_warrior_animations_0_sprites_5_ADDRESS 0x72E4u    /* 0432E4 */
#define kabuki_warrior_animations_1_ADDRESS 0x7302u    /* 043302 */
#define kabuki_warrior_animations_1_sprites_ADDRESS 0x7316u    /* 043316 */
#define kabuki_warrior_animations_1_sprites_2_ADDRESS 0x7334u    /* 043334 */
#define kabuki_warrior_animations_1_sprites_3_ADDRESS 0x7364u    /* 043364 */
#define kabuki_warrior_animations_1_sprites_4_ADDRESS 0x7394u    /* 043394 */
#define kabuki_warrior_animations_2_ADDRESS 0x73C4u    /* 0433C4 */
#define kabuki_warrior_animations_2_sprites_ADDRESS 0x73E0u    /* 0433E0 */
#define kabuki_warrior_animations_2_sprites_2_ADDRESS 0x740Au    /* 04340A */
#define kabuki_warrior_animations_2_sprites_3_ADDRESS 0x742Eu    /* 04342E */
#define kabuki_warrior_animations_2_sprites_4_ADDRESS 0x7458u    /* 043458 */
#define kabuki_warrior_animations_2_sprites_5_ADDRESS 0x7482u    /* 043482 */
#define kabuki_warrior_animations_2_sprites_6_ADDRESS 0x74A6u    /* 0434A6 */
#define kabuki_warrior_animations_3_ADDRESS 0x74D0u    /* 0434D0 */
#define kabuki_warrior_animations_3_sprites_ADDRESS 0x74E4u    /* 0434E4 */
#define kabuki_warrior_animations_3_sprites_2_ADDRESS 0x7514u    /* 043514 */
#define kabuki_warrior_animations_3_sprites_3_ADDRESS 0x753Eu    /* 04353E */
#define kabuki_warrior_animations_4_ADDRESS 0x756Eu    /* 04356E */
#define kabuki_warrior_animations_4_sprites_ADDRESS 0x7576u    /* 043576 */
#define kabuki_warrior_animations_5_ADDRESS 0x75A6u    /* 0435A6 */
#define kabuki_warrior_animations_5_sprites_ADDRESS 0x75B2u    /* 0435B2 */
#define kabuki_warrior_animations_5_sprites_2_ADDRESS 0x75D6u    /* 0435D6 */
#define kabuki_warrior_animations_6_ADDRESS 0x75F4u    /* 0435F4 */
#define kabuki_warrior_animations_6_sprites_ADDRESS 0x7600u    /* 043600 */
#define kabuki_warrior_animations_6_sprites_2_ADDRESS 0x761Eu    /* 04361E */
#define kabuki_warrior_animations_7_ADDRESS 0x7642u    /* 043642 */
#define kabuki_warrior_animations_7_sprites_ADDRESS 0x7656u    /* 043656 */
#define kabuki_warrior_animations_7_sprites_2_ADDRESS 0x767Au    /* 04367A */
#define kabuki_warrior_animations_7_sprites_3_ADDRESS 0x76A4u    /* 0436A4 */
#define kabuki_warrior_animations_7_sprites_4_ADDRESS 0x76CEu    /* 0436CE */
#define kabuki_warrior_animations_8_ADDRESS 0x76FEu    /* 0436FE */
#define kabuki_warrior_animations_8_sprites_ADDRESS 0x770Eu    /* 04370E */
#define kabuki_warrior_animations_8_sprites_2_ADDRESS 0x7732u    /* 043732 */
#define kabuki_warrior_animations_8_sprites_3_ADDRESS 0x7756u    /* 043756 */
#define kabuki_warrior_animations_9_ADDRESS 0x7780u    /* 043780 */
#define kabuki_warrior_animations_10_ADDRESS 0x7788u    /* 043788 */
#define kabuki_warrior_animations_10_sprites_ADDRESS 0x779Cu    /* 04379C */
#define kabuki_warrior_animations_10_sprites_2_ADDRESS 0x77C6u    /* 0437C6 */
#define kabuki_warrior_animations_11_ADDRESS 0x77F0u    /* 0437F0 */
#define dog_2_animations_ADDRESS 0x7810u    /* 043810 */
#define dog_2_animations_1_ADDRESS 0x7814u    /* 043814 */
#define dog_2_animations_1_sprites_ADDRESS 0x7858u    /* 043858 */
#define dog_2_animations_1_sprites_2_ADDRESS 0x786Au    /* 04386A */
#define dog_2_animations_1_sprites_3_ADDRESS 0x787Cu    /* 04387C */
#define dog_2_animations_1_sprites_4_ADDRESS 0x7894u    /* 043894 */
#define dog_2_animations_1_sprites_5_ADDRESS 0x78ACu    /* 0438AC */
#define dog_2_animations_1_sprites_6_ADDRESS 0x78C4u    /* 0438C4 */
#define dog_2_animations_1_sprites_7_ADDRESS 0x78DCu    /* 0438DC */
#define dog_2_animations_1_sprites_8_ADDRESS 0x78FAu    /* 0438FA */
#define dog_2_animations_1_sprites_9_ADDRESS 0x7918u    /* 043918 */
#define dog_2_animations_1_sprites_10_ADDRESS 0x7930u    /* 043930 */
#define dog_2_animations_1_sprites_11_ADDRESS 0x794Eu    /* 04394E */
#define dog_2_animations_0_ADDRESS 0x796Cu    /* 04396C */
#define dog_2_animations_0_sprites_ADDRESS 0x7980u    /* 043980 */
#define dog_2_animations_0_sprites_2_ADDRESS 0x799Eu    /* 04399E */
#define dog_2_animations_0_sprites_3_ADDRESS 0x79B6u    /* 0439B6 */
#define dog_2_animations_0_sprites_4_ADDRESS 0x79D4u    /* 0439D4 */
#define crypt_slab_animations_ADDRESS 0x79ECu    /* 0439EC */
#define crypt_slab_animations_0_ADDRESS 0x7A14u    /* 043A14 */
#define crypt_slab_animations_0_sprites_ADDRESS 0x7A1Cu    /* 043A1C */
#define crypt_slab_animations_1_ADDRESS 0x7A2Eu    /* 043A2E */
#define crypt_slab_animations_1_sprites_ADDRESS 0x7A36u    /* 043A36 */
#define crypt_slab_animations_2_ADDRESS 0x7A48u    /* 043A48 */
#define crypt_slab_animations_2_sprites_ADDRESS 0x7A50u    /* 043A50 */
#define crypt_slab_animations_3_ADDRESS 0x7A62u    /* 043A62 */
#define crypt_slab_animations_3_sprites_ADDRESS 0x7A6Au    /* 043A6A */
#define crypt_slab_animations_4_ADDRESS 0x7A7Cu    /* 043A7C */
#define crypt_slab_animations_4_sprites_ADDRESS 0x7A84u    /* 043A84 */
#define crypt_slab_animations_5_ADDRESS 0x7A96u    /* 043A96 */
#define crypt_slab_animations_5_sprites_ADDRESS 0x7A9Eu    /* 043A9E */
#define crypt_slab_animations_6_ADDRESS 0x7AB0u    /* 043AB0 */
#define crypt_slab_animations_6_sprites_ADDRESS 0x7AB8u    /* 043AB8 */
#define crypt_slab_animations_7_ADDRESS 0x7ACAu    /* 043ACA */
#define crypt_slab_animations_7_sprites_ADDRESS 0x7AD2u    /* 043AD2 */
#define crypt_slab_animations_8_ADDRESS 0x7AE4u    /* 043AE4 */
#define crypt_slab_animations_8_sprites_ADDRESS 0x7AECu    /* 043AEC */
#define crypt_slab_animations_9_ADDRESS 0x7AFEu    /* 043AFE */
#define crypt_slab_animations_9_sprites_ADDRESS 0x7B06u    /* 043B06 */
#define crypt_slab_animations_10_ADDRESS 0x7B18u    /* 043B18 */
#define crypt_slab_animations_10_sprites_ADDRESS 0x7B20u    /* 043B20 */
#define crypt_slab_animations_11_ADDRESS 0x7B32u    /* 043B32 */
#define crypt_slab_animations_11_sprites_ADDRESS 0x7B3Au    /* 043B3A */
#define crypt_slab_animations_12_ADDRESS 0x7B4Cu    /* 043B4C */
#define crypt_slab_animations_12_sprites_ADDRESS 0x7B54u    /* 043B54 */
#define crypt_slab_animations_13_ADDRESS 0x7B66u    /* 043B66 */
#define crypt_slab_animations_13_sprites_ADDRESS 0x7B6Eu    /* 043B6E */
#define crypt_slab_animations_14_ADDRESS 0x7B80u    /* 043B80 */
#define crypt_slab_animations_14_sprites_ADDRESS 0x7B88u    /* 043B88 */
#define crypt_slab_animations_15_ADDRESS 0x7B9Au    /* 043B9A */
#define crypt_slab_animations_15_sprites_ADDRESS 0x7BA2u    /* 043BA2 */
#define crypt_slab_animations_16_ADDRESS 0x7BB4u    /* 043BB4 */
#define crypt_slab_animations_16_sprites_ADDRESS 0x7BBCu    /* 043BBC */
#define crypt_slab_animations_17_ADDRESS 0x7BCEu    /* 043BCE */
#define crypt_slab_animations_17_sprites_ADDRESS 0x7BD6u    /* 043BD6 */
#define crypt_slab_animations_18_ADDRESS 0x7BE8u    /* 043BE8 */
#define crypt_slab_animations_18_sprites_ADDRESS 0x7BF0u    /* 043BF0 */
#define crypt_slab_animations_19_ADDRESS 0x7C08u    /* 043C08 */
#define crypt_slab_animations_19_sprites_ADDRESS 0x7C10u    /* 043C10 */
#define crypt_slab_animations_19_sprites_fill_ADDRESS 0x7C28u    /* 043C28 */
#define crypt_slab_animations_19_sprites_rest_ADDRESS 0x7D48u    /* 043D48 */
#define crypt_slab_animations_19_sprites_rest_2_ADDRESS 0x7D64u    /* 043D64 */
#define crypt_slab_animations_19_sprites_rest_3_ADDRESS 0x7D8Eu    /* 043D8E */
#define crypt_slab_animations_19_sprites_rest_4_ADDRESS 0x7DBEu    /* 043DBE */
#define crypt_slab_animations_19_sprites_rest_5_ADDRESS 0x7DF4u    /* 043DF4 */
#define crypt_slab_animations_19_sprites_rest_6_ADDRESS 0x7E30u    /* 043E30 */
#define crypt_slab_animations_19_sprites_rest_7_ADDRESS 0x7E78u    /* 043E78 */
#define crypt_slab_animations_19_sprites_fill_2_ADDRESS 0x7ECCu    /* 043ECC */
#define crypt_slab_animations_19_sprites_rest_8_ADDRESS 0x6000u    /* 044000 */
#define boss_doors_and_rubble_animations_ADDRESS 0x600Au    /* 04400A */
#define boss_doors_and_rubble_animations_0_ADDRESS 0x601Eu    /* 04401E */
#define boss_doors_and_rubble_animations_0_sprites_ADDRESS 0x604Au    /* 04404A */
#define boss_doors_and_rubble_animations_0_sprites_2_ADDRESS 0x6056u    /* 044056 */
#define boss_doors_and_rubble_animations_0_sprites_3_ADDRESS 0x6062u    /* 044062 */
#define boss_doors_and_rubble_animations_0_sprites_4_ADDRESS 0x606Eu    /* 04406E */
#define boss_doors_and_rubble_animations_1_ADDRESS 0x6074u    /* 044074 */
#define boss_doors_and_rubble_animations_1_sprites_ADDRESS 0x6084u    /* 044084 */
#define boss_doors_and_rubble_animations_1_sprites_2_ADDRESS 0x609Cu    /* 04409C */
#define boss_doors_and_rubble_animations_1_sprites_3_ADDRESS 0x60AEu    /* 0440AE */
#define boss_doors_and_rubble_animations_2_ADDRESS 0x60BAu    /* 0440BA */
#define boss_doors_and_rubble_animations_2_sprites_ADDRESS 0x60C2u    /* 0440C2 */
#define boss_doors_and_rubble_animations_3_ADDRESS 0x60D4u    /* 0440D4 */
#define boss_doors_and_rubble_animations_3_sprites_ADDRESS 0x60DCu    /* 0440DC */
#define boss_doors_and_rubble_animations_4_ADDRESS 0x60E2u    /* 0440E2 */
#define boss_doors_and_rubble_animations_4_sprites_ADDRESS 0x60EAu    /* 0440EA */
#define boss_doors_and_rubble_animations_8_ADDRESS 0x60F6u    /* 0440F6 */
#define boss_doors_and_rubble_animations_8_sprites_ADDRESS 0x60FEu    /* 0440FE */
#define boss_doors_and_rubble_animations_9_ADDRESS 0x611Cu    /* 04411C */
#define boss_doors_and_rubble_animations_9_sprites_ADDRESS 0x613Cu    /* 04413C */
#define boss_doors_and_rubble_animations_9_sprites_2_ADDRESS 0x6142u    /* 044142 */
#define boss_doors_and_rubble_animations_9_sprites_3_ADDRESS 0x6148u    /* 044148 */
#define boss_doors_and_rubble_animations_9_sprites_4_ADDRESS 0x614Eu    /* 04414E */
#define boss_doors_and_rubble_animations_9_sprites_5_ADDRESS 0x6178u    /* 044178 */
#define boss_doors_and_rubble_animations_9_sprites_6_ADDRESS 0x61B4u    /* 0441B4 */
#define boss_doors_and_rubble_animations_9_sprites_7_ADDRESS 0x61F0u    /* 0441F0 */
#define boss_doors_and_rubble_animations_5_ADDRESS 0x6226u    /* 044226 */
#define boss_doors_and_rubble_animations_5_sprites_ADDRESS 0x622Eu    /* 04422E */
#define boss_doors_and_rubble_animations_6_ADDRESS 0x624Cu    /* 04424C */
#define boss_doors_and_rubble_animations_6_sprites_ADDRESS 0x6254u    /* 044254 */
#define boss_doors_and_rubble_animations_7_ADDRESS 0x626Cu    /* 04426C */
#define boss_doors_and_rubble_animations_7_sprites_ADDRESS 0x6274u    /* 044274 */
#define family_animations_ADDRESS 0x6280u    /* 044280 */
#define family_animations_0_ADDRESS 0x6290u    /* 044290 */
#define family_animations_0_sprites_ADDRESS 0x62B4u    /* 0442B4 */
#define family_animations_0_sprites_2_ADDRESS 0x62D8u    /* 0442D8 */
#define family_animations_0_sprites_3_ADDRESS 0x62F6u    /* 0442F6 */
#define family_animations_0_sprites_4_ADDRESS 0x6314u    /* 044314 */
#define family_animations_0_sprites_5_ADDRESS 0x6332u    /* 044332 */
#define family_animations_0_sprites_6_ADDRESS 0x6350u    /* 044350 */
#define family_animations_0_sprites_7_ADDRESS 0x636Eu    /* 04436E */
#define family_animations_0_sprites_8_ADDRESS 0x638Cu    /* 04438C */
#define family_animations_1_ADDRESS 0x63AAu    /* 0443AA */
#define family_animations_1_sprites_ADDRESS 0x63CEu    /* 0443CE */
#define family_animations_1_sprites_2_ADDRESS 0x63E6u    /* 0443E6 */
#define family_animations_1_sprites_3_ADDRESS 0x63FEu    /* 0443FE */
#define family_animations_1_sprites_4_ADDRESS 0x6416u    /* 044416 */
#define family_animations_1_sprites_5_ADDRESS 0x642Eu    /* 04442E */
#define family_animations_1_sprites_6_ADDRESS 0x6452u    /* 044452 */
#define family_animations_1_sprites_7_ADDRESS 0x6476u    /* 044476 */
#define family_animations_1_sprites_8_ADDRESS 0x649Au    /* 04449A */
#define family_animations_2_ADDRESS 0x64A6u    /* 0444A6 */
#define family_animations_2_sprites_ADDRESS 0x650Eu    /* 04450E */
#define family_animations_2_sprites_2_ADDRESS 0x6532u    /* 044532 */
#define family_animations_2_sprites_3_ADDRESS 0x6550u    /* 044550 */
#define family_animations_2_sprites_4_ADDRESS 0x656Eu    /* 04456E */
#define family_animations_2_sprites_5_ADDRESS 0x658Cu    /* 04458C */
#define family_animations_2_sprites_6_ADDRESS 0x65AAu    /* 0445AA */
#define family_animations_2_sprites_7_ADDRESS 0x65C8u    /* 0445C8 */
#define family_animations_2_sprites_8_ADDRESS 0x65E6u    /* 0445E6 */
#define family_animations_2_sprites_9_ADDRESS 0x6604u    /* 044604 */
#define family_animations_2_sprites_10_ADDRESS 0x6628u    /* 044628 */
#define family_animations_2_sprites_11_ADDRESS 0x6646u    /* 044646 */
#define family_animations_2_sprites_12_ADDRESS 0x6664u    /* 044664 */
#define family_animations_2_sprites_13_ADDRESS 0x6682u    /* 044682 */
#define family_animations_2_sprites_14_ADDRESS 0x66A0u    /* 0446A0 */
#define family_animations_2_sprites_15_ADDRESS 0x66BEu    /* 0446BE */
#define family_animations_2_sprites_16_ADDRESS 0x66DCu    /* 0446DC */
#define family_animations_2_sprites_17_ADDRESS 0x66FAu    /* 0446FA */
#define family_animations_2_sprites_18_ADDRESS 0x671Eu    /* 04471E */
#define family_animations_2_sprites_19_ADDRESS 0x673Cu    /* 04473C */
#define family_animations_2_sprites_20_ADDRESS 0x675Au    /* 04475A */
#define family_animations_2_sprites_21_ADDRESS 0x6778u    /* 044778 */
#define family_animations_2_sprites_22_ADDRESS 0x6796u    /* 044796 */
#define family_animations_2_sprites_23_ADDRESS 0x67B4u    /* 0447B4 */
#define family_animations_2_sprites_24_ADDRESS 0x67D2u    /* 0447D2 */
#define family_animations_2_sprites_25_ADDRESS 0x67F0u    /* 0447F0 */
#define family_animations_3_ADDRESS 0x6814u    /* 044814 */
#define family_animations_3_sprites_ADDRESS 0x6838u    /* 044838 */
#define family_animations_3_sprites_2_ADDRESS 0x6856u    /* 044856 */
#define family_animations_4_ADDRESS 0x6874u    /* 044874 */
#define family_animations_4_sprites_ADDRESS 0x68ACu    /* 0448AC */
#define family_animations_4_sprites_2_ADDRESS 0x68CAu    /* 0448CA */
#define family_animations_4_sprites_3_ADDRESS 0x68E8u    /* 0448E8 */
#define family_animations_4_sprites_4_ADDRESS 0x6906u    /* 044906 */
#define family_animations_4_sprites_5_ADDRESS 0x692Au    /* 04492A */
#define family_animations_4_sprites_6_ADDRESS 0x6954u    /* 044954 */
#define family_animations_4_sprites_7_ADDRESS 0x6984u    /* 044984 */
#define family_animations_5_ADDRESS 0x69B4u    /* 0449B4 */
#define family_animations_5_sprites_ADDRESS 0x69C8u    /* 0449C8 */
#define family_animations_5_sprites_2_ADDRESS 0x69CEu    /* 0449CE */
#define family_animations_5_sprites_3_ADDRESS 0x69D4u    /* 0449D4 */
#define family_animations_5_sprites_4_ADDRESS 0x69DAu    /* 0449DA */
#define family_animations_6_ADDRESS 0x69E0u    /* 0449E0 */
#define family_animations_6_sprites_ADDRESS 0x69F4u    /* 0449F4 */
#define family_animations_6_sprites_2_ADDRESS 0x69FAu    /* 0449FA */
#define family_animations_6_sprites_3_ADDRESS 0x6A00u    /* 044A00 */
#define family_animations_6_sprites_4_ADDRESS 0x6A06u    /* 044A06 */
#define family_animations_7_ADDRESS 0x6A0Cu    /* 044A0C */
#define family_animations_7_sprites_ADDRESS 0x6A20u    /* 044A20 */
#define family_animations_7_sprites_2_ADDRESS 0x6A2Cu    /* 044A2C */
#define family_animations_7_sprites_3_ADDRESS 0x6A38u    /* 044A38 */
#define family_animations_7_sprites_4_ADDRESS 0x6A44u    /* 044A44 */
#define walking_donut_animations_ADDRESS 0x6A50u    /* 044A50 */
#define walking_donut_animations_0_ADDRESS 0x6A80u    /* 044A80 */
#define walking_donut_animations_0_sprites_ADDRESS 0x6A88u    /* 044A88 */
#define walking_donut_animations_1_ADDRESS 0x6AA0u    /* 044AA0 */
#define walking_donut_animations_1_sprites_ADDRESS 0x6AC4u    /* 044AC4 */
#define walking_donut_animations_1_sprites_2_ADDRESS 0x6AD6u    /* 044AD6 */
#define walking_donut_animations_1_sprites_3_ADDRESS 0x6AE8u    /* 044AE8 */
#define walking_donut_animations_1_sprites_4_ADDRESS 0x6AFAu    /* 044AFA */
#define walking_donut_animations_1_sprites_5_ADDRESS 0x6B0Cu    /* 044B0C */
#define walking_donut_animations_1_sprites_6_ADDRESS 0x6B24u    /* 044B24 */
#define walking_donut_animations_16_ADDRESS 0x6B3Cu    /* 044B3C */
#define walking_donut_animations_16_sprites_ADDRESS 0x6B5Cu    /* 044B5C */
#define walking_donut_animations_16_sprites_2_ADDRESS 0x6B74u    /* 044B74 */
#define walking_donut_animations_16_sprites_3_ADDRESS 0x6B86u    /* 044B86 */
#define walking_donut_animations_16_sprites_4_ADDRESS 0x6B98u    /* 044B98 */
#define walking_donut_animations_16_sprites_5_ADDRESS 0x6BB0u    /* 044BB0 */
#define walking_donut_animations_16_sprites_6_ADDRESS 0x6BC8u    /* 044BC8 */
#define walking_donut_animations_16_sprites_7_ADDRESS 0x6BE0u    /* 044BE0 */
#define walking_donut_animations_4_ADDRESS 0x6BF2u    /* 044BF2 */
#define walking_donut_animations_4_sprites_ADDRESS 0x6C06u    /* 044C06 */
#define walking_donut_animations_4_sprites_2_ADDRESS 0x6C18u    /* 044C18 */
#define walking_donut_animations_4_sprites_3_ADDRESS 0x6C36u    /* 044C36 */
#define walking_donut_animations_17_ADDRESS 0x6C54u    /* 044C54 */
#define walking_donut_animations_17_sprites_ADDRESS 0x6C6Cu    /* 044C6C */
#define walking_donut_animations_17_sprites_2_ADDRESS 0x6C84u    /* 044C84 */
#define walking_donut_animations_17_sprites_3_ADDRESS 0x6C9Cu    /* 044C9C */
#define walking_donut_animations_17_sprites_4_ADDRESS 0x6CB4u    /* 044CB4 */
#define walking_donut_animations_17_sprites_5_ADDRESS 0x6CCCu    /* 044CCC */
#define walking_donut_animations_6_ADDRESS 0x6CEAu    /* 044CEA */
#define walking_donut_animations_6_sprites_ADDRESS 0x6D06u    /* 044D06 */
#define walking_donut_animations_7_ADDRESS 0x6D1Eu    /* 044D1E */
#define walking_donut_animations_9_ADDRESS 0x6D2Au    /* 044D2A */
#define walking_donut_animations_9_sprites_ADDRESS 0x6D3Eu    /* 044D3E */
#define walking_donut_animations_9_sprites_2_ADDRESS 0x6D5Cu    /* 044D5C */
#define walking_donut_animations_8_ADDRESS 0x6D74u    /* 044D74 */
#define walking_donut_animations_8_sprites_ADDRESS 0x6DA0u    /* 044DA0 */
#define walking_donut_animations_8_sprites_2_ADDRESS 0x6DB2u    /* 044DB2 */
#define walking_donut_animations_8_sprites_3_ADDRESS 0x6DCAu    /* 044DCA */
#define walking_donut_animations_8_sprites_4_ADDRESS 0x6DDCu    /* 044DDC */
#define walking_donut_animations_8_sprites_5_ADDRESS 0x6DE8u    /* 044DE8 */
#define walking_donut_animations_8_sprites_6_ADDRESS 0x6DF4u    /* 044DF4 */
#define walking_donut_animations_8_sprites_7_ADDRESS 0x6E06u    /* 044E06 */
#define walking_donut_animations_8_sprites_8_ADDRESS 0x6E18u    /* 044E18 */
#define walking_donut_animations_8_sprites_9_ADDRESS 0x6E24u    /* 044E24 */
#define walking_donut_animations_8_sprites_10_ADDRESS 0x6E2Au    /* 044E2A */
#define walking_donut_animations_18_ADDRESS 0x6E30u    /* 044E30 */
#define walking_donut_animations_18_sprites_ADDRESS 0x6E38u    /* 044E38 */
#define walking_donut_animations_19_ADDRESS 0x6E3Eu    /* 044E3E */
#define walking_donut_animations_19_sprites_ADDRESS 0x6E4Eu    /* 044E4E */
#define walking_donut_animations_19_sprites_2_ADDRESS 0x6E60u    /* 044E60 */
#define walking_donut_animations_19_sprites_3_ADDRESS 0x6E6Cu    /* 044E6C */
#define walking_donut_animations_20_ADDRESS 0x6E84u    /* 044E84 */
#define walking_donut_animations_20_sprites_ADDRESS 0x6E94u    /* 044E94 */
#define walking_donut_animations_20_sprites_2_ADDRESS 0x6EACu    /* 044EAC */
#define walking_donut_animations_21_ADDRESS 0x6EC4u    /* 044EC4 */
#define walking_donut_animations_21_sprites_ADDRESS 0x6EE4u    /* 044EE4 */
#define walking_donut_animations_21_sprites_2_ADDRESS 0x6EFCu    /* 044EFC */
#define walking_donut_animations_21_sprites_3_ADDRESS 0x6F0Eu    /* 044F0E */
#define walking_donut_animations_22_ADDRESS 0x6F26u    /* 044F26 */
#define walking_donut_animations_22_sprites_ADDRESS 0x6F46u    /* 044F46 */
#define walking_donut_animations_22_sprites_2_ADDRESS 0x6F4Cu    /* 044F4C */
#define walking_donut_animations_22_sprites_3_ADDRESS 0x6F52u    /* 044F52 */
#define walking_donut_animations_22_sprites_4_ADDRESS 0x6F58u    /* 044F58 */
#define walking_donut_animations_22_sprites_5_ADDRESS 0x6F64u    /* 044F64 */
#define walking_donut_animations_22_sprites_6_ADDRESS 0x6F6Au    /* 044F6A */
#define walking_donut_animations_22_sprites_7_ADDRESS 0x6F94u    /* 044F94 */
#define walking_donut_animations_15_ADDRESS 0x6FB8u    /* 044FB8 */
#define walking_donut_animations_23_ADDRESS 0x6FD8u    /* 044FD8 */
#define flying_saxophone_animations_ADDRESS 0x6FF0u    /* 044FF0 */
#define flying_saxophone_animations_0_ADDRESS 0x7024u    /* 045024 */
#define flying_saxophone_animations_0_sprites_ADDRESS 0x702Cu    /* 04502C */
#define flying_saxophone_animations_1_ADDRESS 0x7044u    /* 045044 */
#define flying_saxophone_animations_1_sprites_ADDRESS 0x7060u    /* 045060 */
#define flying_saxophone_animations_1_sprites_2_ADDRESS 0x7084u    /* 045084 */
#define flying_saxophone_animations_1_sprites_3_ADDRESS 0x70A2u    /* 0450A2 */
#define flying_saxophone_animations_1_sprites_4_ADDRESS 0x70C0u    /* 0450C0 */
#define flying_saxophone_animations_16_ADDRESS 0x70DEu    /* 0450DE */
#define flying_saxophone_animations_16_sprites_ADDRESS 0x7122u    /* 045122 */
#define flying_saxophone_animations_16_sprites_2_ADDRESS 0x7146u    /* 045146 */
#define flying_saxophone_animations_16_sprites_3_ADDRESS 0x716Au    /* 04516A */
#define flying_saxophone_animations_16_sprites_4_ADDRESS 0x718Eu    /* 04518E */
#define flying_saxophone_animations_16_sprites_5_ADDRESS 0x71B2u    /* 0451B2 */
#define flying_saxophone_animations_16_sprites_6_ADDRESS 0x71DCu    /* 0451DC */
#define flying_saxophone_animations_16_sprites_7_ADDRESS 0x7206u    /* 045206 */
#define flying_saxophone_animations_16_sprites_8_ADDRESS 0x7224u    /* 045224 */
#define flying_saxophone_animations_16_sprites_9_ADDRESS 0x7248u    /* 045248 */
#define flying_saxophone_animations_16_sprites_10_ADDRESS 0x726Cu    /* 04526C */
#define flying_saxophone_animations_6_ADDRESS 0x7290u    /* 045290 */
#define flying_saxophone_animations_6_sprites_ADDRESS 0x72B0u    /* 0452B0 */
#define flying_saxophone_animations_6_sprites_2_ADDRESS 0x72CEu    /* 0452CE */
#define flying_saxophone_animations_6_sprites_3_ADDRESS 0x72ECu    /* 0452EC */
#define flying_saxophone_animations_7_ADDRESS 0x730Au    /* 04530A */
#define flying_saxophone_animations_7_sprites_ADDRESS 0x731Eu    /* 04531E */
#define flying_saxophone_animations_7_sprites_2_ADDRESS 0x7330u    /* 045330 */
#define flying_saxophone_animations_7_sprites_3_ADDRESS 0x7354u    /* 045354 */
#define flying_saxophone_animations_9_ADDRESS 0x7372u    /* 045372 */
#define flying_saxophone_animations_9_sprites_ADDRESS 0x738Eu    /* 04538E */
#define flying_saxophone_animations_9_sprites_2_ADDRESS 0x73ACu    /* 0453AC */
#define flying_saxophone_animations_9_sprites_3_ADDRESS 0x73CAu    /* 0453CA */
#define flying_saxophone_animations_9_sprites_4_ADDRESS 0x73E8u    /* 0453E8 */
#define flying_saxophone_animations_8_ADDRESS 0x7406u    /* 045406 */
#define flying_saxophone_animations_8_sprites_ADDRESS 0x7442u    /* 045442 */
#define flying_saxophone_animations_8_sprites_2_ADDRESS 0x7460u    /* 045460 */
#define flying_saxophone_animations_8_sprites_3_ADDRESS 0x7478u    /* 045478 */
#define flying_saxophone_animations_8_sprites_4_ADDRESS 0x7490u    /* 045490 */
#define flying_saxophone_animations_8_sprites_5_ADDRESS 0x74A2u    /* 0454A2 */
#define flying_saxophone_animations_8_sprites_6_ADDRESS 0x74C0u    /* 0454C0 */
#define flying_saxophone_animations_8_sprites_7_ADDRESS 0x74DEu    /* 0454DE */
#define flying_saxophone_animations_8_sprites_8_ADDRESS 0x74FCu    /* 0454FC */
#define flying_saxophone_animations_8_sprites_9_ADDRESS 0x7514u    /* 045514 */
#define flying_saxophone_animations_8_sprites_10_ADDRESS 0x7532u    /* 045532 */
#define flying_saxophone_animations_17_ADDRESS 0x7544u    /* 045544 */
#define flying_saxophone_animations_17_sprites_ADDRESS 0x754Cu    /* 04554C */
#define flying_saxophone_animations_18_ADDRESS 0x7552u    /* 045552 */
#define flying_saxophone_animations_18_sprites_ADDRESS 0x755Au    /* 04555A */
#define flying_saxophone_animations_19_ADDRESS 0x7560u    /* 045560 */
#define flying_saxophone_animations_19_sprites_ADDRESS 0x7568u    /* 045568 */
#define flying_saxophone_animations_20_ADDRESS 0x756Eu    /* 04556E */
#define flying_saxophone_animations_20_sprites_ADDRESS 0x7576u    /* 045576 */
#define flying_saxophone_animations_21_ADDRESS 0x757Cu    /* 04557C */
#define flying_saxophone_animations_21_sprites_ADDRESS 0x75ACu    /* 0455AC */
#define flying_saxophone_animations_21_sprites_2_ADDRESS 0x75D0u    /* 0455D0 */
#define flying_saxophone_animations_21_sprites_3_ADDRESS 0x75E8u    /* 0455E8 */
#define flying_saxophone_animations_21_sprites_4_ADDRESS 0x760Cu    /* 04560C */
#define flying_saxophone_animations_21_sprites_5_ADDRESS 0x7630u    /* 045630 */
#define flying_saxophone_animations_21_sprites_6_ADDRESS 0x764Eu    /* 04564E */
#define flying_saxophone_animations_22_ADDRESS 0x766Cu    /* 04566C */
#define flying_saxophone_animations_22_sprites_ADDRESS 0x7680u    /* 045680 */
#define flying_saxophone_animations_22_sprites_2_ADDRESS 0x7698u    /* 045698 */
#define flying_saxophone_animations_22_sprites_3_ADDRESS 0x76B0u    /* 0456B0 */
#define flying_saxophone_animations_23_ADDRESS 0x76C8u    /* 0456C8 */
#define flying_saxophone_animations_23_sprites_ADDRESS 0x76E8u    /* 0456E8 */
#define flying_saxophone_animations_23_sprites_2_ADDRESS 0x76EEu    /* 0456EE */
#define flying_saxophone_animations_23_sprites_3_ADDRESS 0x76F4u    /* 0456F4 */
#define flying_saxophone_animations_23_sprites_4_ADDRESS 0x76FAu    /* 0456FA */
#define flying_saxophone_animations_23_sprites_5_ADDRESS 0x7706u    /* 045706 */
#define flying_saxophone_animations_23_sprites_6_ADDRESS 0x770Cu    /* 04570C */
#define flying_saxophone_animations_23_sprites_7_ADDRESS 0x7730u    /* 045730 */
#define flying_saxophone_animations_24_ADDRESS 0x7754u    /* 045754 */
#define flying_saxophone_animations_24_sprites_ADDRESS 0x775Cu    /* 04575C */
#define flying_saxophone_animations_25_ADDRESS 0x7762u    /* 045762 */
#define flying_saxophone_animations_25_sprites_ADDRESS 0x776Au    /* 04576A */
#define marge_cloud_animations_ADDRESS 0x7770u    /* 045770 */
#define marge_cloud_animations_0_ADDRESS 0x7780u    /* 045780 */
#define marge_cloud_animations_0_sprites_ADDRESS 0x7794u    /* 045794 */
#define marge_cloud_animations_0_sprites_2_ADDRESS 0x779Au    /* 04579A */
#define marge_cloud_animations_0_sprites_3_ADDRESS 0x77A0u    /* 0457A0 */
#define marge_cloud_animations_1_ADDRESS 0x77A6u    /* 0457A6 */
#define marge_cloud_animations_1_sprites_ADDRESS 0x77CAu    /* 0457CA */
#define marge_cloud_animations_1_sprites_2_ADDRESS 0x77D0u    /* 0457D0 */
#define marge_cloud_animations_1_sprites_3_ADDRESS 0x77DCu    /* 0457DC */
#define marge_cloud_animations_1_sprites_4_ADDRESS 0x77E8u    /* 0457E8 */
#define marge_cloud_animations_1_sprites_5_ADDRESS 0x77FAu    /* 0457FA */
#define marge_cloud_animations_2_ADDRESS 0x7806u    /* 045806 */
#define marge_cloud_animations_2_sprites_ADDRESS 0x781Au    /* 04581A */
#define marge_cloud_animations_2_sprites_2_ADDRESS 0x782Cu    /* 04582C */
#define marge_cloud_animations_3_ADDRESS 0x783Eu    /* 04583E */
#define marge_cloud_animations_3_sprites_ADDRESS 0x7872u    /* 045872 */
#define marge_cloud_animations_3_sprites_2_ADDRESS 0x7884u    /* 045884 */
#define marge_cloud_animations_3_sprites_3_ADDRESS 0x7896u    /* 045896 */
#define marge_cloud_animations_3_sprites_4_ADDRESS 0x78A2u    /* 0458A2 */
#define marge_cloud_animations_4_ADDRESS 0x78AEu    /* 0458AE */
#define marge_cloud_animations_4_sprites_ADDRESS 0x78D6u    /* 0458D6 */
#define marge_cloud_animations_4_sprites_2_ADDRESS 0x78E2u    /* 0458E2 */
#define marge_cloud_animations_4_sprites_3_ADDRESS 0x78F4u    /* 0458F4 */
#define marge_cloud_animations_4_sprites_4_ADDRESS 0x7906u    /* 045906 */
#define marge_cloud_animations_4_sprites_5_ADDRESS 0x7912u    /* 045912 */
#define marge_cloud_animations_4_sprites_6_ADDRESS 0x7924u    /* 045924 */
#define marge_cloud_animations_4_sprites_7_ADDRESS 0x7936u    /* 045936 */
#define marge_cloud_animations_5_ADDRESS 0x794Eu    /* 04594E */
#define marge_cloud_animations_5_sprites_ADDRESS 0x795Eu    /* 04595E */
#define marge_cloud_animations_5_sprites_2_ADDRESS 0x796Au    /* 04596A */
#define marge_cloud_animations_6_ADDRESS 0x7976u    /* 045976 */
#define marge_cloud_animations_6_sprites_ADDRESS 0x7992u    /* 045992 */
#define marge_cloud_animations_6_sprites_2_ADDRESS 0x7998u    /* 045998 */
#define marge_cloud_animations_6_sprites_3_ADDRESS 0x799Eu    /* 04599E */
#define marge_cloud_animations_7_ADDRESS 0x79B6u    /* 0459B6 */
#define marge_cloud_animations_7_fill_ADDRESS 0x79D6u    /* 0459D6 */
#define marge_cloud_animations_7_rest_ADDRESS 0x7A4Cu    /* 045A4C */
#define marge_cloud_animations_7_rest_2_ADDRESS 0x7A54u    /* 045A54 */
#define marge_cloud_animations_7_fill_2_ADDRESS 0x7A5Au    /* 045A5A */
#define marge_cloud_animations_7_rest_3_ADDRESS 0x7A9Au    /* 045A9A */
#define marge_cloud_animations_7_rest_4_ADDRESS 0x7AA2u    /* 045AA2 */
#define marge_cloud_animations_7_fill_3_ADDRESS 0x7AA8u    /* 045AA8 */
#define marge_cloud_animations_7_rest_5_ADDRESS 0x7AC0u    /* 045AC0 */
#define marge_cloud_animations_7_rest_6_ADDRESS 0x7AC8u    /* 045AC8 */
#define marge_cloud_animations_7_fill_4_ADDRESS 0x7ACEu    /* 045ACE */
#define marge_cloud_animations_7_rest_7_ADDRESS 0x7ADAu    /* 045ADA */
#define marge_cloud_animations_7_rest_8_ADDRESS 0x7AE2u    /* 045AE2 */
#define marge_cloud_animations_7_rest_9_ADDRESS 0x7AEEu    /* 045AEE */
#define marge_cloud_animations_7_rest_10_ADDRESS 0x7AF6u    /* 045AF6 */
#define marge_cloud_animations_7_rest_11_ADDRESS 0x7B02u    /* 045B02 */
#define marge_cloud_animations_7_rest_12_ADDRESS 0x7B0Au    /* 045B0A */
#define marge_cloud_animations_7_rest_13_ADDRESS 0x7B16u    /* 045B16 */
#define marge_cloud_animations_7_rest_14_ADDRESS 0x7B36u    /* 045B36 */
#define marge_cloud_animations_7_rest_15_ADDRESS 0x7B42u    /* 045B42 */
#define marge_cloud_animations_7_rest_16_ADDRESS 0x7B54u    /* 045B54 */
#define marge_cloud_animations_7_rest_17_ADDRESS 0x7B7Eu    /* 045B7E */
#define marge_cloud_animations_7_rest_18_ADDRESS 0x7BA8u    /* 045BA8 */
#define marge_cloud_animations_7_rest_19_ADDRESS 0x7BC6u    /* 045BC6 */
#define marge_cloud_animations_7_rest_20_ADDRESS 0x7BE4u    /* 045BE4 */
#define marge_cloud_animations_7_fill_5_ADDRESS 0x7BF0u    /* 045BF0 */
#define marge_cloud_animations_7_rest_21_ADDRESS 0x7BF2u    /* 045BF2 */
#define marge_cloud_animations_7_rest_22_ADDRESS 0x7C02u    /* 045C02 */
#define marge_cloud_animations_7_rest_23_ADDRESS 0x7C08u    /* 045C08 */
#define marge_cloud_animations_7_rest_24_ADDRESS 0x7C0Eu    /* 045C0E */
#define marge_cloud_animations_7_fill_6_ADDRESS 0x7C1Au    /* 045C1A */
#define marge_cloud_animations_7_rest_25_ADDRESS 0x7D48u    /* 045D48 */
#define marge_cloud_animations_7_rest_26_ADDRESS 0x7D64u    /* 045D64 */
#define marge_cloud_animations_7_rest_27_ADDRESS 0x7D8Eu    /* 045D8E */
#define marge_cloud_animations_7_rest_28_ADDRESS 0x7DBEu    /* 045DBE */
#define marge_cloud_animations_7_rest_29_ADDRESS 0x7DF4u    /* 045DF4 */
#define marge_cloud_animations_7_rest_30_ADDRESS 0x7E30u    /* 045E30 */
#define marge_cloud_animations_7_rest_31_ADDRESS 0x7E78u    /* 045E78 */
#define marge_cloud_animations_7_fill_7_ADDRESS 0x7ECCu    /* 045ECC */
#define marge_cloud_animations_7_rest_32_ADDRESS 0x6000u    /* 046000 */
#define fat_goon_animations_ADDRESS 0x6008u    /* 046008 */
#define fat_goon_animations_0_ADDRESS 0x6080u    /* 046080 */
#define fat_goon_animations_0_sprites_ADDRESS 0x6088u    /* 046088 */
#define fat_goon_animations_1_ADDRESS 0x608Eu    /* 04608E */
#define fat_goon_animations_1_sprites_ADDRESS 0x60B2u    /* 0460B2 */
#define fat_goon_animations_1_sprites_2_ADDRESS 0x60CAu    /* 0460CA */
#define fat_goon_animations_1_sprites_3_ADDRESS 0x60DCu    /* 0460DC */
#define fat_goon_animations_1_sprites_4_ADDRESS 0x60EEu    /* 0460EE */
#define fat_goon_animations_1_sprites_5_ADDRESS 0x6100u    /* 046100 */
#define fat_goon_animations_1_sprites_6_ADDRESS 0x6112u    /* 046112 */
#define fat_goon_animations_1_sprites_7_ADDRESS 0x6124u    /* 046124 */
#define fat_goon_animations_1_sprites_8_ADDRESS 0x6136u    /* 046136 */
#define fat_goon_animations_2_ADDRESS 0x6148u    /* 046148 */
#define fat_goon_animations_2_sprites_ADDRESS 0x616Cu    /* 04616C */
#define fat_goon_animations_2_sprites_2_ADDRESS 0x617Eu    /* 04617E */
#define fat_goon_animations_2_sprites_3_ADDRESS 0x618Au    /* 04618A */
#define fat_goon_animations_2_sprites_4_ADDRESS 0x619Cu    /* 04619C */
#define fat_goon_animations_2_sprites_5_ADDRESS 0x61A8u    /* 0461A8 */
#define fat_goon_animations_2_sprites_6_ADDRESS 0x61BAu    /* 0461BA */
#define fat_goon_animations_2_sprites_7_ADDRESS 0x61CCu    /* 0461CC */
#define fat_goon_animations_2_sprites_8_ADDRESS 0x61E4u    /* 0461E4 */
#define fat_goon_animations_3_ADDRESS 0x61F6u    /* 0461F6 */
#define fat_goon_animations_3_sprites_ADDRESS 0x621Au    /* 04621A */
#define fat_goon_animations_3_sprites_2_ADDRESS 0x622Cu    /* 04622C */
#define fat_goon_animations_3_sprites_3_ADDRESS 0x623Eu    /* 04623E */
#define fat_goon_animations_3_sprites_4_ADDRESS 0x6250u    /* 046250 */
#define fat_goon_animations_3_sprites_5_ADDRESS 0x6262u    /* 046262 */
#define fat_goon_animations_3_sprites_6_ADDRESS 0x6274u    /* 046274 */
#define fat_goon_animations_3_sprites_7_ADDRESS 0x6286u    /* 046286 */
#define fat_goon_animations_3_sprites_8_ADDRESS 0x6298u    /* 046298 */
#define fat_goon_animations_4_ADDRESS 0x62AAu    /* 0462AA */
#define fat_goon_animations_4_sprites_ADDRESS 0x62B6u    /* 0462B6 */
#define fat_goon_animations_4_sprites_2_ADDRESS 0x62BCu    /* 0462BC */
#define fat_goon_animations_5_ADDRESS 0x62C2u    /* 0462C2 */
#define fat_goon_animations_5_sprites_ADDRESS 0x62CEu    /* 0462CE */
#define fat_goon_animations_5_sprites_2_ADDRESS 0x62D4u    /* 0462D4 */
#define fat_goon_animations_6_ADDRESS 0x62DAu    /* 0462DA */
#define fat_goon_animations_6_sprites_ADDRESS 0x62E6u    /* 0462E6 */
#define fat_goon_animations_6_sprites_2_ADDRESS 0x62F8u    /* 0462F8 */
#define fat_goon_animations_7_ADDRESS 0x630Au    /* 04630A */
#define fat_goon_animations_7_sprites_ADDRESS 0x6316u    /* 046316 */
#define fat_goon_animations_7_sprites_2_ADDRESS 0x6328u    /* 046328 */
#define fat_goon_animations_8_ADDRESS 0x6340u    /* 046340 */
#define fat_goon_animations_8_sprites_ADDRESS 0x6358u    /* 046358 */
#define fat_goon_animations_8_sprites_2_ADDRESS 0x636Au    /* 04636A */
#define fat_goon_animations_8_sprites_3_ADDRESS 0x637Cu    /* 04637C */
#define fat_goon_animations_8_sprites_4_ADDRESS 0x638Eu    /* 04638E */
#define fat_goon_animations_8_sprites_5_ADDRESS 0x639Au    /* 04639A */
#define fat_goon_animations_9_ADDRESS 0x63A6u    /* 0463A6 */
#define fat_goon_animations_9_sprites_ADDRESS 0x63BAu    /* 0463BA */
#define fat_goon_animations_9_sprites_2_ADDRESS 0x63C0u    /* 0463C0 */
#define fat_goon_animations_9_sprites_3_ADDRESS 0x63C6u    /* 0463C6 */
#define fat_goon_animations_10_ADDRESS 0x63CCu    /* 0463CC */
#define fat_goon_animations_10_sprites_ADDRESS 0x63E4u    /* 0463E4 */
#define fat_goon_animations_10_sprites_2_ADDRESS 0x63F0u    /* 0463F0 */
#define fat_goon_animations_10_sprites_3_ADDRESS 0x6402u    /* 046402 */
#define fat_goon_animations_11_ADDRESS 0x641Au    /* 04641A */
#define fat_goon_animations_11_sprites_ADDRESS 0x642Eu    /* 04642E */
#define fat_goon_animations_11_sprites_2_ADDRESS 0x6434u    /* 046434 */
#define fat_goon_animations_11_sprites_3_ADDRESS 0x643Au    /* 04643A */
#define fat_goon_animations_11_sprites_4_ADDRESS 0x6440u    /* 046440 */
#define fat_goon_animations_12_ADDRESS 0x6446u    /* 046446 */
#define fat_goon_animations_12_sprites_ADDRESS 0x6462u    /* 046462 */
#define fat_goon_animations_12_sprites_2_ADDRESS 0x6474u    /* 046474 */
#define fat_goon_animations_12_sprites_3_ADDRESS 0x647Au    /* 04647A */
#define fat_goon_animations_12_sprites_4_ADDRESS 0x6480u    /* 046480 */
#define fat_goon_animations_12_sprites_5_ADDRESS 0x6486u    /* 046486 */
#define fat_goon_animations_12_sprites_6_ADDRESS 0x6498u    /* 046498 */
#define fat_goon_animations_13_ADDRESS 0x64B0u    /* 0464B0 */
#define fat_goon_animations_13_sprites_ADDRESS 0x64BCu    /* 0464BC */
#define fat_goon_animations_13_sprites_2_ADDRESS 0x64C2u    /* 0464C2 */
#define fat_goon_animations_14_ADDRESS 0x64CEu    /* 0464CE */
#define fat_goon_animations_14_sprites_ADDRESS 0x64EEu    /* 0464EE */
#define fat_goon_animations_14_sprites_2_ADDRESS 0x64F4u    /* 0464F4 */
#define fat_goon_animations_14_sprites_3_ADDRESS 0x64FAu    /* 0464FA */
#define fat_goon_animations_14_sprites_4_ADDRESS 0x6506u    /* 046506 */
#define fat_goon_animations_14_sprites_5_ADDRESS 0x650Cu    /* 04650C */
#define fat_goon_animations_15_ADDRESS 0x6512u    /* 046512 */
#define fat_goon_animations_15_sprites_ADDRESS 0x6526u    /* 046526 */
#define fat_goon_animations_15_sprites_2_ADDRESS 0x653Eu    /* 04653E */
#define fat_goon_animations_15_sprites_3_ADDRESS 0x6556u    /* 046556 */
#define fat_goon_animations_15_sprites_4_ADDRESS 0x6568u    /* 046568 */
#define fat_goon_animations_16_ADDRESS 0x657Au    /* 04657A */
#define fat_goon_animations_16_sprites_ADDRESS 0x659Eu    /* 04659E */
#define fat_goon_animations_16_sprites_2_ADDRESS 0x65B0u    /* 0465B0 */
#define fat_goon_animations_16_sprites_3_ADDRESS 0x65C2u    /* 0465C2 */
#define fat_goon_animations_16_sprites_4_ADDRESS 0x65D4u    /* 0465D4 */
#define fat_goon_animations_16_sprites_5_ADDRESS 0x65E0u    /* 0465E0 */
#define fat_goon_animations_16_sprites_6_ADDRESS 0x65F2u    /* 0465F2 */
#define fat_goon_animations_16_sprites_7_ADDRESS 0x6604u    /* 046604 */
#define fat_goon_animations_16_sprites_8_ADDRESS 0x661Cu    /* 04661C */
#define fat_goon_animations_17_ADDRESS 0x6634u    /* 046634 */
#define fat_goon_animations_17_sprites_ADDRESS 0x6658u    /* 046658 */
#define fat_goon_animations_17_sprites_2_ADDRESS 0x665Eu    /* 04665E */
#define fat_goon_animations_17_sprites_3_ADDRESS 0x6664u    /* 046664 */
#define fat_goon_animations_17_sprites_4_ADDRESS 0x666Au    /* 04666A */
#define fat_goon_animations_17_sprites_5_ADDRESS 0x6670u    /* 046670 */
#define fat_goon_animations_17_sprites_6_ADDRESS 0x6676u    /* 046676 */
#define fat_goon_animations_17_sprites_7_ADDRESS 0x667Cu    /* 04667C */
#define fat_goon_animations_17_sprites_8_ADDRESS 0x6682u    /* 046682 */
#define fat_goon_animations_18_ADDRESS 0x6688u    /* 046688 */
#define fat_goon_animations_18_sprites_ADDRESS 0x66A0u    /* 0466A0 */
#define fat_goon_animations_18_sprites_2_ADDRESS 0x66B2u    /* 0466B2 */
#define fat_goon_animations_18_sprites_3_ADDRESS 0x66CAu    /* 0466CA */
#define fat_goon_animations_19_ADDRESS 0x66DCu    /* 0466DC */
#define fat_goon_animations_19_sprites_ADDRESS 0x66F4u    /* 0466F4 */
#define fat_goon_animations_19_sprites_2_ADDRESS 0x6706u    /* 046706 */
#define fat_goon_animations_19_sprites_3_ADDRESS 0x6718u    /* 046718 */
#define fat_goon_animations_32_ADDRESS 0x672Au    /* 04672A */
#define fat_goon_animations_32_sprites_ADDRESS 0x673Eu    /* 04673E */
#define fat_goon_animations_33_ADDRESS 0x6750u    /* 046750 */
#define fat_goon_animations_33_sprites_ADDRESS 0x6760u    /* 046760 */
#define fat_goon_animations_33_sprites_2_ADDRESS 0x6766u    /* 046766 */
#define fat_goon_animations_34_ADDRESS 0x676Cu    /* 04676C */
#define fat_goon_animations_34_sprites_ADDRESS 0x677Cu    /* 04677C */
#define fat_goon_animations_34_sprites_2_ADDRESS 0x6782u    /* 046782 */
#define fat_goon_animations_34_sprites_3_ADDRESS 0x6788u    /* 046788 */
#define fat_goon_animations_35_ADDRESS 0x678Eu    /* 04678E */
#define fat_goon_animations_35_sprites_ADDRESS 0x67AAu    /* 0467AA */
#define fat_goon_animations_35_sprites_2_ADDRESS 0x67C2u    /* 0467C2 */
#define fat_goon_animations_35_sprites_3_ADDRESS 0x67D4u    /* 0467D4 */
#define fat_goon_animations_35_sprites_4_ADDRESS 0x67E0u    /* 0467E0 */
#define fat_goon_animations_35_sprites_5_ADDRESS 0x67F2u    /* 0467F2 */
#define fat_goon_animations_36_ADDRESS 0x6804u    /* 046804 */
#define fat_goon_animations_36_sprites_ADDRESS 0x6818u    /* 046818 */
#define fat_goon_animations_36_sprites_2_ADDRESS 0x681Eu    /* 04681E */
#define fat_goon_animations_36_sprites_3_ADDRESS 0x6830u    /* 046830 */
#define fat_goon_animations_37_ADDRESS 0x683Cu    /* 04683C */
#define fat_goon_animations_37_sprites_ADDRESS 0x6848u    /* 046848 */
#define fat_goon_animations_37_sprites_2_ADDRESS 0x6860u    /* 046860 */
#define fat_goon_animations_38_ADDRESS 0x6872u    /* 046872 */
#define fat_goon_animations_38_sprites_ADDRESS 0x6896u    /* 046896 */
#define fat_goon_animations_38_sprites_2_ADDRESS 0x68A8u    /* 0468A8 */
#define fat_goon_animations_38_sprites_3_ADDRESS 0x68BAu    /* 0468BA */
#define fat_goon_animations_38_sprites_4_ADDRESS 0x68D2u    /* 0468D2 */
#define fat_goon_animations_38_sprites_5_ADDRESS 0x68F0u    /* 0468F0 */
#define fat_goon_animations_38_sprites_6_ADDRESS 0x6908u    /* 046908 */
#define fat_goon_animations_38_sprites_7_ADDRESS 0x6920u    /* 046920 */
#define fat_goon_animations_38_sprites_8_ADDRESS 0x6938u    /* 046938 */
#define fat_goon_animations_39_ADDRESS 0x6950u    /* 046950 */
#define fat_goon_animations_39_sprites_ADDRESS 0x6960u    /* 046960 */
#define fat_goon_animations_39_sprites_2_ADDRESS 0x6978u    /* 046978 */
#define fat_goon_animations_39_sprites_3_ADDRESS 0x698Au    /* 04698A */
#define fat_goon_animations_40_ADDRESS 0x699Cu    /* 04699C */
#define fat_goon_animations_40_sprites_ADDRESS 0x69B0u    /* 0469B0 */
#define fat_goon_animations_40_sprites_2_ADDRESS 0x69C2u    /* 0469C2 */
#define fat_goon_animations_40_sprites_3_ADDRESS 0x69C8u    /* 0469C8 */
#define fat_goon_animations_41_ADDRESS 0x69D4u    /* 0469D4 */
#define fat_goon_animations_41_sprites_ADDRESS 0x69DCu    /* 0469DC */
#define fat_goon_animations_42_ADDRESS 0x69E2u    /* 0469E2 */
#define fat_goon_animations_42_sprites_ADDRESS 0x69F2u    /* 0469F2 */
#define fat_goon_animations_42_sprites_2_ADDRESS 0x69F8u    /* 0469F8 */
#define fat_goon_animations_43_ADDRESS 0x69FEu    /* 0469FE */
#define fat_goon_animations_43_sprites_ADDRESS 0x6A1Eu    /* 046A1E */
#define fat_goon_animations_43_sprites_2_ADDRESS 0x6A24u    /* 046A24 */
#define fat_goon_animations_43_sprites_3_ADDRESS 0x6A3Cu    /* 046A3C */
#define fat_goon_animations_43_sprites_4_ADDRESS 0x6A4Eu    /* 046A4E */
#define fat_goon_animations_43_sprites_5_ADDRESS 0x6A60u    /* 046A60 */
#define fat_goon_animations_43_sprites_6_ADDRESS 0x6A66u    /* 046A66 */
#define fat_goon_animations_54_ADDRESS 0x6A6Cu    /* 046A6C */
#define fat_goon_animations_54_sprites_ADDRESS 0x6A80u    /* 046A80 */
#define fat_goon_animations_54_sprites_2_ADDRESS 0x6AA4u    /* 046AA4 */
#define fat_goon_animations_54_sprites_3_ADDRESS 0x6AC8u    /* 046AC8 */
#define fat_goon_animations_45_ADDRESS 0x6AF8u    /* 046AF8 */
#define fat_goon_animations_45_sprites_ADDRESS 0x6B08u    /* 046B08 */
#define fat_goon_animations_45_sprites_2_ADDRESS 0x6B14u    /* 046B14 */
#define fat_goon_animations_45_sprites_3_ADDRESS 0x6B20u    /* 046B20 */
#define fat_goon_animations_46_ADDRESS 0x6B32u    /* 046B32 */
#define fat_goon_animations_46_sprites_ADDRESS 0x6B42u    /* 046B42 */
#define fat_goon_animations_46_sprites_2_ADDRESS 0x6B54u    /* 046B54 */
#define fat_goon_animations_56_ADDRESS 0x6B66u    /* 046B66 */
#define fat_goon_animations_56_sprites_ADDRESS 0x6B7Au    /* 046B7A */
#define fat_goon_animations_56_sprites_2_ADDRESS 0x6B86u    /* 046B86 */
#define fat_goon_animations_56_sprites_3_ADDRESS 0x6B92u    /* 046B92 */
#define fat_goon_animations_48_ADDRESS 0x6BA4u    /* 046BA4 */
#define fat_goon_animations_48_sprites_ADDRESS 0x6BB4u    /* 046BB4 */
#define fat_goon_animations_48_sprites_2_ADDRESS 0x6BBAu    /* 046BBA */
#define fat_goon_animations_48_sprites_3_ADDRESS 0x6BC0u    /* 046BC0 */
#define fat_goon_animations_49_ADDRESS 0x6BC6u    /* 046BC6 */
#define fat_goon_animations_49_sprites_ADDRESS 0x6BCEu    /* 046BCE */
#define fat_goon_animations_50_ADDRESS 0x6BD4u    /* 046BD4 */
#define fat_goon_animations_50_sprites_ADDRESS 0x6BFCu    /* 046BFC */
#define fat_goon_animations_50_sprites_2_ADDRESS 0x6C0Eu    /* 046C0E */
#define fat_goon_animations_50_sprites_3_ADDRESS 0x6C14u    /* 046C14 */
#define fat_goon_animations_50_sprites_4_ADDRESS 0x6C20u    /* 046C20 */
#define fat_goon_animations_50_sprites_5_ADDRESS 0x6C32u    /* 046C32 */
#define fat_goon_animations_50_sprites_6_ADDRESS 0x6C44u    /* 046C44 */
#define fat_goon_animations_50_sprites_7_ADDRESS 0x6C5Cu    /* 046C5C */
#define fat_goon_animations_50_sprites_8_ADDRESS 0x6C68u    /* 046C68 */
#define fat_goon_animations_51_ADDRESS 0x6C7Au    /* 046C7A */
#define fat_goon_animations_51_sprites_ADDRESS 0x6C9Au    /* 046C9A */
#define fat_goon_animations_51_sprites_2_ADDRESS 0x6CA0u    /* 046CA0 */
#define fat_goon_animations_51_sprites_3_ADDRESS 0x6CACu    /* 046CAC */
#define fat_goon_animations_55_ADDRESS 0x6CB8u    /* 046CB8 */
#define fat_goon_animations_55_sprites_ADDRESS 0x6CC8u    /* 046CC8 */
#define fat_goon_animations_55_sprites_2_ADDRESS 0x6CDAu    /* 046CDA */
#define fat_goon_animations_55_sprites_3_ADDRESS 0x6CF2u    /* 046CF2 */
#define fat_goon_animations_53_ADDRESS 0x6D0Au    /* 046D0A */
#define fat_goon_animations_53_sprites_ADDRESS 0x6D1Eu    /* 046D1E */
#define fat_goon_animations_53_sprites_2_ADDRESS 0x6D36u    /* 046D36 */
#define fat_goon_animations_53_sprites_3_ADDRESS 0x6D4Eu    /* 046D4E */
#define fat_goon_animations_52_ADDRESS 0x6D72u    /* 046D72 */
#define fat_goon_animations_52_sprites_ADDRESS 0x6D82u    /* 046D82 */
#define fat_goon_animations_52_sprites_2_ADDRESS 0x6D9Au    /* 046D9A */
#define fat_goon_animations_52_sprites_3_ADDRESS 0x6DBEu    /* 046DBE */
#define fat_goon_animations_21_ADDRESS 0x6DE8u    /* 046DE8 */
#define fat_goon_animations_21_sprites_ADDRESS 0x6DF8u    /* 046DF8 */
#define fat_goon_animations_21_sprites_2_ADDRESS 0x6E04u    /* 046E04 */
#define fat_goon_animations_21_sprites_3_ADDRESS 0x6E10u    /* 046E10 */
#define fat_goon_animations_22_ADDRESS 0x6E1Cu    /* 046E1C */
#define fat_goon_animations_22_sprites_ADDRESS 0x6E2Cu    /* 046E2C */
#define fat_goon_animations_22_sprites_2_ADDRESS 0x6E38u    /* 046E38 */
#define fat_goon_animations_22_sprites_3_ADDRESS 0x6E44u    /* 046E44 */
#define fat_goon_animations_47_ADDRESS 0x6E56u    /* 046E56 */
#define fat_goon_animations_47_sprites_ADDRESS 0x6E6Au    /* 046E6A */
#define fat_goon_animations_47_sprites_2_ADDRESS 0x6E88u    /* 046E88 */
#define fat_goon_animations_47_sprites_3_ADDRESS 0x6EB2u    /* 046EB2 */
#define fat_goon_animations_57_ADDRESS 0x6EE2u    /* 046EE2 */
#define fat_goon_animations_57_sprites_ADDRESS 0x6EFAu    /* 046EFA */
#define fat_goon_animations_57_sprites_2_ADDRESS 0x6F0Cu    /* 046F0C */
#define fat_goon_animations_57_sprites_3_ADDRESS 0x6F12u    /* 046F12 */
#define fat_goon_animations_57_sprites_4_ADDRESS 0x6F18u    /* 046F18 */
#define fat_goon_animations_57_sprites_5_ADDRESS 0x6F1Eu    /* 046F1E */
#define fat_goon_animations_58_ADDRESS 0x6F2Au    /* 046F2A */
#define fat_goon_animations_59_ADDRESS 0x6F36u    /* 046F36 */
#define fat_goon_with_mallet_animations_ADDRESS 0x6F42u    /* 046F42 */
#define fat_goon_with_mallet_animations_0_ADDRESS 0x6F8Cu    /* 046F8C */
#define fat_goon_with_mallet_animations_0_sprites_ADDRESS 0x6F94u    /* 046F94 */
#define fat_goon_with_mallet_animations_1_ADDRESS 0x6FACu    /* 046FAC */
#define fat_goon_with_mallet_animations_1_sprites_ADDRESS 0x6FD0u    /* 046FD0 */
#define fat_goon_with_mallet_animations_1_sprites_2_ADDRESS 0x6FE8u    /* 046FE8 */
#define fat_goon_with_mallet_animations_1_sprites_3_ADDRESS 0x7000u    /* 047000 */
#define fat_goon_with_mallet_animations_1_sprites_4_ADDRESS 0x7018u    /* 047018 */
#define fat_goon_with_mallet_animations_1_sprites_5_ADDRESS 0x7030u    /* 047030 */
#define fat_goon_with_mallet_animations_1_sprites_6_ADDRESS 0x704Eu    /* 04704E */
#define fat_goon_with_mallet_animations_1_sprites_7_ADDRESS 0x706Cu    /* 04706C */
#define fat_goon_with_mallet_animations_1_sprites_8_ADDRESS 0x708Au    /* 04708A */
#define fat_goon_with_mallet_animations_2_ADDRESS 0x70A8u    /* 0470A8 */
#define fat_goon_with_mallet_animations_2_sprites_ADDRESS 0x70CCu    /* 0470CC */
#define fat_goon_with_mallet_animations_2_sprites_2_ADDRESS 0x70E4u    /* 0470E4 */
#define fat_goon_with_mallet_animations_2_sprites_3_ADDRESS 0x70FCu    /* 0470FC */
#define fat_goon_with_mallet_animations_2_sprites_4_ADDRESS 0x7114u    /* 047114 */
#define fat_goon_with_mallet_animations_2_sprites_5_ADDRESS 0x712Cu    /* 04712C */
#define fat_goon_with_mallet_animations_2_sprites_6_ADDRESS 0x714Au    /* 04714A */
#define fat_goon_with_mallet_animations_2_sprites_7_ADDRESS 0x7168u    /* 047168 */
#define fat_goon_with_mallet_animations_2_sprites_8_ADDRESS 0x7186u    /* 047186 */
#define fat_goon_with_mallet_animations_3_ADDRESS 0x71A4u    /* 0471A4 */
#define fat_goon_with_mallet_animations_3_sprites_ADDRESS 0x71C8u    /* 0471C8 */
#define fat_goon_with_mallet_animations_3_sprites_2_ADDRESS 0x71DAu    /* 0471DA */
#define fat_goon_with_mallet_animations_3_sprites_3_ADDRESS 0x71ECu    /* 0471EC */
#define fat_goon_with_mallet_animations_3_sprites_4_ADDRESS 0x71FEu    /* 0471FE */
#define fat_goon_with_mallet_animations_3_sprites_5_ADDRESS 0x7210u    /* 047210 */
#define fat_goon_with_mallet_animations_3_sprites_6_ADDRESS 0x7222u    /* 047222 */
#define fat_goon_with_mallet_animations_3_sprites_7_ADDRESS 0x7234u    /* 047234 */
#define fat_goon_with_mallet_animations_3_sprites_8_ADDRESS 0x7246u    /* 047246 */
#define fat_goon_with_mallet_animations_4_ADDRESS 0x7258u    /* 047258 */
#define fat_goon_with_mallet_animations_4_sprites_ADDRESS 0x7268u    /* 047268 */
#define fat_goon_with_mallet_animations_4_sprites_2_ADDRESS 0x7274u    /* 047274 */
#define fat_goon_with_mallet_animations_4_sprites_3_ADDRESS 0x7280u    /* 047280 */
#define fat_goon_with_mallet_animations_5_ADDRESS 0x7292u    /* 047292 */
#define fat_goon_with_mallet_animations_5_sprites_ADDRESS 0x72A2u    /* 0472A2 */
#define fat_goon_with_mallet_animations_5_sprites_2_ADDRESS 0x72B4u    /* 0472B4 */
#define fat_goon_with_mallet_animations_5_sprites_3_ADDRESS 0x72C6u    /* 0472C6 */
#define fat_goon_with_mallet_animations_6_ADDRESS 0x72DEu    /* 0472DE */
#define fat_goon_with_mallet_animations_6_sprites_ADDRESS 0x72EAu    /* 0472EA */
#define fat_goon_with_mallet_animations_6_sprites_2_ADDRESS 0x7308u    /* 047308 */
#define fat_goon_with_mallet_animations_7_ADDRESS 0x7326u    /* 047326 */
#define fat_goon_with_mallet_animations_7_sprites_ADDRESS 0x7332u    /* 047332 */
#define fat_goon_with_mallet_animations_7_sprites_2_ADDRESS 0x7350u    /* 047350 */
#define fat_goon_with_mallet_animations_9_ADDRESS 0x7374u    /* 047374 */
#define fat_goon_with_mallet_animations_9_sprites_ADDRESS 0x7388u    /* 047388 */
#define fat_goon_with_mallet_animations_9_sprites_2_ADDRESS 0x739Au    /* 04739A */
#define fat_goon_with_mallet_animations_9_sprites_3_ADDRESS 0x73ACu    /* 0473AC */
#define fat_goon_with_mallet_animations_10_ADDRESS 0x73BEu    /* 0473BE */
#define fat_goon_with_mallet_animations_10_sprites_ADDRESS 0x73D6u    /* 0473D6 */
#define fat_goon_with_mallet_animations_10_sprites_2_ADDRESS 0x73EEu    /* 0473EE */
#define fat_goon_with_mallet_animations_10_sprites_3_ADDRESS 0x740Cu    /* 04740C */
#define fat_goon_with_mallet_animations_11_ADDRESS 0x742Au    /* 04742A */
#define fat_goon_with_mallet_animations_11_sprites_ADDRESS 0x743Eu    /* 04743E */
#define fat_goon_with_mallet_animations_11_sprites_2_ADDRESS 0x7450u    /* 047450 */
#define fat_goon_with_mallet_animations_11_sprites_3_ADDRESS 0x745Cu    /* 04745C */
#define fat_goon_with_mallet_animations_11_sprites_4_ADDRESS 0x7468u    /* 047468 */
#define fat_goon_with_mallet_animations_14_ADDRESS 0x747Au    /* 04747A */
#define fat_goon_with_mallet_animations_14_sprites_ADDRESS 0x749Au    /* 04749A */
#define fat_goon_with_mallet_animations_14_sprites_2_ADDRESS 0x74B2u    /* 0474B2 */
#define fat_goon_with_mallet_animations_14_sprites_3_ADDRESS 0x74BEu    /* 0474BE */
#define fat_goon_with_mallet_animations_14_sprites_4_ADDRESS 0x74CAu    /* 0474CA */
#define fat_goon_with_mallet_animations_14_sprites_5_ADDRESS 0x74DCu    /* 0474DC */
#define fat_goon_with_mallet_animations_14_sprites_6_ADDRESS 0x74E8u    /* 0474E8 */
#define fat_goon_with_mallet_animations_13_ADDRESS 0x74F4u    /* 0474F4 */
#define fat_goon_with_mallet_animations_13_sprites_ADDRESS 0x7500u    /* 047500 */
#define fat_goon_with_mallet_animations_13_sprites_2_ADDRESS 0x750Cu    /* 04750C */
#define fat_goon_with_mallet_animations_12_ADDRESS 0x751Eu    /* 04751E */
#define fat_goon_with_mallet_animations_12_sprites_ADDRESS 0x7536u    /* 047536 */
#define fat_goon_with_mallet_animations_12_sprites_2_ADDRESS 0x7542u    /* 047542 */
#define fat_goon_with_mallet_animations_12_sprites_3_ADDRESS 0x754Eu    /* 04754E */
#define fat_goon_with_mallet_animations_12_sprites_4_ADDRESS 0x755Au    /* 04755A */
#define fat_goon_with_mallet_animations_12_sprites_5_ADDRESS 0x7572u    /* 047572 */
#define fat_goon_with_mallet_animations_15_ADDRESS 0x7590u    /* 047590 */
#define fat_goon_with_mallet_animations_15_sprites_ADDRESS 0x75A4u    /* 0475A4 */
#define fat_goon_with_mallet_animations_15_sprites_2_ADDRESS 0x75C2u    /* 0475C2 */
#define fat_goon_with_mallet_animations_15_sprites_3_ADDRESS 0x75E0u    /* 0475E0 */
#define fat_goon_with_mallet_animations_15_sprites_4_ADDRESS 0x75F8u    /* 0475F8 */
#define fat_goon_with_mallet_animations_16_ADDRESS 0x7610u    /* 047610 */
#define fat_goon_with_mallet_animations_16_sprites_ADDRESS 0x7634u    /* 047634 */
#define fat_goon_with_mallet_animations_16_sprites_2_ADDRESS 0x7646u    /* 047646 */
#define fat_goon_with_mallet_animations_16_sprites_3_ADDRESS 0x7658u    /* 047658 */
#define fat_goon_with_mallet_animations_16_sprites_4_ADDRESS 0x766Au    /* 04766A */
#define fat_goon_with_mallet_animations_16_sprites_5_ADDRESS 0x767Cu    /* 04767C */
#define fat_goon_with_mallet_animations_16_sprites_6_ADDRESS 0x7694u    /* 047694 */
#define fat_goon_with_mallet_animations_16_sprites_7_ADDRESS 0x76ACu    /* 0476AC */
#define fat_goon_with_mallet_animations_16_sprites_8_ADDRESS 0x76C4u    /* 0476C4 */
#define fat_goon_with_mallet_animations_18_ADDRESS 0x76DCu    /* 0476DC */
#define fat_goon_with_mallet_animations_18_sprites_ADDRESS 0x76ECu    /* 0476EC */
#define fat_goon_with_mallet_animations_18_sprites_2_ADDRESS 0x770Au    /* 04770A */
#define fat_goon_with_mallet_animations_18_sprites_3_ADDRESS 0x7728u    /* 047728 */
#define fat_goon_with_mallet_animations_19_ADDRESS 0x7746u    /* 047746 */
#define fat_goon_with_mallet_animations_19_sprites_ADDRESS 0x775Au    /* 04775A */
#define fat_goon_with_mallet_animations_19_sprites_2_ADDRESS 0x7778u    /* 047778 */
#define fat_goon_with_mallet_animations_19_sprites_3_ADDRESS 0x7796u    /* 047796 */
#define fat_goon_with_mallet_animations_35_ADDRESS 0x77B4u    /* 0477B4 */
#define fat_goon_with_mallet_animations_35_sprites_ADDRESS 0x77E0u    /* 0477E0 */
#define fat_goon_with_mallet_animations_35_sprites_2_ADDRESS 0x77ECu    /* 0477EC */
#define fat_goon_with_mallet_animations_35_sprites_3_ADDRESS 0x77FEu    /* 0477FE */
#define fat_goon_with_mallet_animations_35_sprites_4_ADDRESS 0x7816u    /* 047816 */
#define fat_goon_with_mallet_animations_35_sprites_5_ADDRESS 0x782Eu    /* 04782E */
#define fat_goon_with_mallet_animations_35_sprites_6_ADDRESS 0x7840u    /* 047840 */
#define fat_goon_with_mallet_animations_35_sprites_7_ADDRESS 0x784Cu    /* 04784C */
#define fat_goon_with_mallet_animations_35_sprites_8_ADDRESS 0x7864u    /* 047864 */
#define fat_goon_with_mallet_animations_20_ADDRESS 0x7870u    /* 047870 */
#define fat_goon_with_mallet_animations_20_sprites_ADDRESS 0x7878u    /* 047878 */
#define crawling_man_animations_ADDRESS 0x788Au    /* 04788A */
#define crawling_man_animations_0_ADDRESS 0x7890u    /* 047890 */
#define crawling_man_animations_0_sprites_ADDRESS 0x789Cu    /* 04789C */
#define crawling_man_animations_0_sprites_2_ADDRESS 0x78A8u    /* 0478A8 */
#define crawling_man_animations_1_ADDRESS 0x78B4u    /* 0478B4 */
#define crawling_man_animations_1_sprites_ADDRESS 0x78C8u    /* 0478C8 */
#define crawling_man_animations_1_sprites_2_ADDRESS 0x78D4u    /* 0478D4 */
#define crawling_man_animations_2_ADDRESS 0x78E0u    /* 0478E0 */
#define crawling_man_animations_2_sprites_ADDRESS 0x78E8u    /* 0478E8 */
#define itchy_and_scratchy_heads_animations_ADDRESS 0x78FAu    /* 0478FA */
#define itchy_and_scratchy_heads_animations_0_ADDRESS 0x7900u    /* 047900 */
#define itchy_and_scratchy_heads_animations_0_sprites_ADDRESS 0x7908u    /* 047908 */
#define itchy_and_scratchy_heads_animations_1_ADDRESS 0x793Eu    /* 04793E */
#define itchy_and_scratchy_heads_animations_1_sprites_ADDRESS 0x7946u    /* 047946 */
#define itchy_and_scratchy_heads_animations_2_ADDRESS 0x794Cu    /* 04794C */
#define itchy_and_scratchy_heads_animations_2_sprites_ADDRESS 0x7954u    /* 047954 */
#define itchy_and_scratchy_heads_animations_2_sprites_fill_ADDRESS 0x795Au    /* 04795A */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_ADDRESS 0x796Cu    /* 04796C */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_2_ADDRESS 0x7980u    /* 047980 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_3_ADDRESS 0x799Eu    /* 04799E */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_4_ADDRESS 0x79B6u    /* 0479B6 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_5_ADDRESS 0x79D4u    /* 0479D4 */
#define itchy_and_scratchy_heads_animations_2_sprites_fill_2_ADDRESS 0x79ECu    /* 0479EC */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_6_ADDRESS 0x7A14u    /* 047A14 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_7_ADDRESS 0x7A1Cu    /* 047A1C */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_8_ADDRESS 0x7A2Eu    /* 047A2E */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_9_ADDRESS 0x7A36u    /* 047A36 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_10_ADDRESS 0x7A48u    /* 047A48 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_11_ADDRESS 0x7A50u    /* 047A50 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_12_ADDRESS 0x7A62u    /* 047A62 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_13_ADDRESS 0x7A6Au    /* 047A6A */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_14_ADDRESS 0x7A7Cu    /* 047A7C */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_15_ADDRESS 0x7A84u    /* 047A84 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_16_ADDRESS 0x7A96u    /* 047A96 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_17_ADDRESS 0x7A9Eu    /* 047A9E */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_18_ADDRESS 0x7AB0u    /* 047AB0 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_19_ADDRESS 0x7AB8u    /* 047AB8 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_20_ADDRESS 0x7ACAu    /* 047ACA */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_21_ADDRESS 0x7AD2u    /* 047AD2 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_22_ADDRESS 0x7AE4u    /* 047AE4 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_23_ADDRESS 0x7AECu    /* 047AEC */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_24_ADDRESS 0x7AFEu    /* 047AFE */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_25_ADDRESS 0x7B06u    /* 047B06 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_26_ADDRESS 0x7B18u    /* 047B18 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_27_ADDRESS 0x7B20u    /* 047B20 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_28_ADDRESS 0x7B32u    /* 047B32 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_29_ADDRESS 0x7B3Au    /* 047B3A */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_30_ADDRESS 0x7B4Cu    /* 047B4C */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_31_ADDRESS 0x7B54u    /* 047B54 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_32_ADDRESS 0x7B66u    /* 047B66 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_33_ADDRESS 0x7B6Eu    /* 047B6E */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_34_ADDRESS 0x7B80u    /* 047B80 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_35_ADDRESS 0x7B88u    /* 047B88 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_36_ADDRESS 0x7B9Au    /* 047B9A */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_37_ADDRESS 0x7BA2u    /* 047BA2 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_38_ADDRESS 0x7BB4u    /* 047BB4 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_39_ADDRESS 0x7BBCu    /* 047BBC */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_40_ADDRESS 0x7BCEu    /* 047BCE */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_41_ADDRESS 0x7BD6u    /* 047BD6 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_42_ADDRESS 0x7BE8u    /* 047BE8 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_43_ADDRESS 0x7BF0u    /* 047BF0 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_44_ADDRESS 0x7C08u    /* 047C08 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_45_ADDRESS 0x7C10u    /* 047C10 */
#define itchy_and_scratchy_heads_animations_2_sprites_fill_3_ADDRESS 0x7C28u    /* 047C28 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_46_ADDRESS 0x7D48u    /* 047D48 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_47_ADDRESS 0x7D64u    /* 047D64 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_48_ADDRESS 0x7D8Eu    /* 047D8E */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_49_ADDRESS 0x7DBEu    /* 047DBE */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_50_ADDRESS 0x7DF4u    /* 047DF4 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_51_ADDRESS 0x7E30u    /* 047E30 */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_52_ADDRESS 0x7E78u    /* 047E78 */
#define itchy_and_scratchy_heads_animations_2_sprites_fill_4_ADDRESS 0x7ECCu    /* 047ECC */
#define itchy_and_scratchy_heads_animations_2_sprites_rest_53_ADDRESS 0x6000u    /* 048000 */
#define bubbles_animations_ADDRESS 0x6008u    /* 048008 */
#define bubbles_animations_0_ADDRESS 0x6024u    /* 048024 */
#define bubbles_animations_0_sprites_ADDRESS 0x602Cu    /* 04802C */
#define bubbles_animations_1_ADDRESS 0x6056u    /* 048056 */
#define bubbles_animations_1_sprites_ADDRESS 0x6082u    /* 048082 */
#define bubbles_animations_1_sprites_2_ADDRESS 0x60ACu    /* 0480AC */
#define bubbles_animations_1_sprites_3_ADDRESS 0x60D6u    /* 0480D6 */
#define bubbles_animations_2_ADDRESS 0x6100u    /* 048100 */
#define bubbles_animations_2_sprites_ADDRESS 0x611Cu    /* 04811C */
#define bubbles_animations_2_sprites_2_ADDRESS 0x6146u    /* 048146 */
#define bubbles_animations_2_sprites_3_ADDRESS 0x6170u    /* 048170 */
#define bubbles_animations_2_sprites_4_ADDRESS 0x619Au    /* 04819A */
#define bubbles_animations_3_ADDRESS 0x61C4u    /* 0481C4 */
#define bubbles_animations_3_sprites_ADDRESS 0x61D4u    /* 0481D4 */
#define bubbles_animations_3_sprites_2_ADDRESS 0x61FEu    /* 0481FE */
#define bubbles_animations_4_ADDRESS 0x6228u    /* 048228 */
#define bubbles_animations_4_sprites_ADDRESS 0x6238u    /* 048238 */
#define bubbles_animations_5_ADDRESS 0x6262u    /* 048262 */
#define bubbles_animations_5_sprites_ADDRESS 0x6286u    /* 048286 */
#define bubbles_animations_5_sprites_2_ADDRESS 0x62B0u    /* 0482B0 */
#define bubbles_animations_5_sprites_3_ADDRESS 0x62DAu    /* 0482DA */
#define bubbles_animations_5_sprites_4_ADDRESS 0x6304u    /* 048304 */
#define bubbles_animations_5_sprites_5_ADDRESS 0x632Eu    /* 04832E */
#define bubbles_animations_6_ADDRESS 0x6358u    /* 048358 */
#define bubbles_animations_6_sprites_ADDRESS 0x636Cu    /* 04836C */
#define bubbles_animations_6_sprites_2_ADDRESS 0x6396u    /* 048396 */
#define bubbles_animations_6_sprites_3_ADDRESS 0x63C0u    /* 0483C0 */
#define bubbles_animations_7_ADDRESS 0x63EAu    /* 0483EA */
#define bubbles_animations_7_sprites_ADDRESS 0x6406u    /* 048406 */
#define bubbles_animations_7_sprites_2_ADDRESS 0x6430u    /* 048430 */
#define bubbles_animations_7_sprites_3_ADDRESS 0x6460u    /* 048460 */
#define bubbles_animations_7_sprites_4_ADDRESS 0x6490u    /* 048490 */
#define bubbles_animations_8_ADDRESS 0x64C0u    /* 0484C0 */
#define bubbles_animations_8_sprites_ADDRESS 0x64E4u    /* 0484E4 */
#define bubbles_animations_8_sprites_2_ADDRESS 0x650Eu    /* 04850E */
#define bubbles_animations_8_sprites_3_ADDRESS 0x6538u    /* 048538 */
#define bubbles_animations_8_sprites_4_ADDRESS 0x6568u    /* 048568 */
#define bubbles_animations_8_sprites_5_ADDRESS 0x6598u    /* 048598 */
#define bubbles_animations_9_ADDRESS 0x65CEu    /* 0485CE */
#define bubbles_animations_9_sprites_ADDRESS 0x65FEu    /* 0485FE */
#define bubbles_animations_9_sprites_2_ADDRESS 0x6628u    /* 048628 */
#define bubbles_animations_9_sprites_3_ADDRESS 0x6652u    /* 048652 */
#define bubbles_animations_9_sprites_4_ADDRESS 0x667Cu    /* 04867C */
#define bubbles_animations_9_sprites_5_ADDRESS 0x66A6u    /* 0486A6 */
#define bubbles_animations_10_ADDRESS 0x66D0u    /* 0486D0 */
#define bubbles_animations_10_sprites_ADDRESS 0x66E8u    /* 0486E8 */
#define bubbles_animations_10_sprites_2_ADDRESS 0x6712u    /* 048712 */
#define bubbles_animations_11_ADDRESS 0x673Cu    /* 04873C */
#define bubbles_animations_11_sprites_ADDRESS 0x6768u    /* 048768 */
#define bubbles_animations_11_sprites_2_ADDRESS 0x6792u    /* 048792 */
#define bubbles_animations_11_sprites_3_ADDRESS 0x67BCu    /* 0487BC */
#define bubbles_animations_11_sprites_4_ADDRESS 0x67E0u    /* 0487E0 */
#define bubbles_animations_11_sprites_5_ADDRESS 0x6804u    /* 048804 */
#define bubbles_animations_11_sprites_6_ADDRESS 0x683Au    /* 04883A */
#define bubbles_animations_12_ADDRESS 0x6864u    /* 048864 */
#define bubbles_animations_12_sprites_ADDRESS 0x6874u    /* 048874 */
#define bubbles_animations_12_sprites_2_ADDRESS 0x689Eu    /* 04889E */
#define bubbles_animations_12_sprites_3_ADDRESS 0x68C8u    /* 0488C8 */
#define bubbles_animations_13_ADDRESS 0x68F2u    /* 0488F2 */
#define bubbles_animations_13_sprites_ADDRESS 0x6906u    /* 048906 */
#define bubbles_animations_13_sprites_2_ADDRESS 0x6930u    /* 048930 */
#define bubbles_animations_13_sprites_3_ADDRESS 0x695Au    /* 04895A */
#define bubbles_animations_13_sprites_4_ADDRESS 0x6984u    /* 048984 */
#define bubbles_3_animations_ADDRESS 0x699Cu    /* 04899C */
#define bubbles_3_animations_0_ADDRESS 0x69B2u    /* 0489B2 */
#define bubbles_3_animations_0_sprites_ADDRESS 0x69DAu    /* 0489DA */
#define bubbles_3_animations_0_sprites_2_ADDRESS 0x6A2Eu    /* 048A2E */
#define bubbles_3_animations_0_sprites_3_ADDRESS 0x6A82u    /* 048A82 */
#define bubbles_3_animations_1_ADDRESS 0x6ADCu    /* 048ADC */
#define bubbles_3_animations_1_sprites_ADDRESS 0x6AF8u    /* 048AF8 */
#define bubbles_3_animations_1_sprites_2_ADDRESS 0x6B46u    /* 048B46 */
#define bubbles_3_animations_2_ADDRESS 0x6B94u    /* 048B94 */
#define bubbles_3_animations_2_sprites_ADDRESS 0x6BBCu    /* 048BBC */
#define bubbles_3_animations_2_sprites_2_ADDRESS 0x6C0Au    /* 048C0A */
#define bubbles_3_animations_2_sprites_3_ADDRESS 0x6C58u    /* 048C58 */
#define bubbles_3_animations_3_ADDRESS 0x6CA6u    /* 048CA6 */
#define bubbles_3_animations_3_sprites_ADDRESS 0x6CB6u    /* 048CB6 */
#define bubbles_3_animations_3_sprites_2_ADDRESS 0x6CFEu    /* 048CFE */
#define bubbles_3_animations_3_sprites_3_ADDRESS 0x6D4Cu    /* 048D4C */
#define bubbles_3_animations_4_ADDRESS 0x6D9Au    /* 048D9A */
#define bubbles_3_animations_4_sprites_ADDRESS 0x6DC2u    /* 048DC2 */
#define bubbles_3_animations_4_sprites_2_ADDRESS 0x6E0Au    /* 048E0A */
#define bubbles_3_animations_4_sprites_3_ADDRESS 0x6E52u    /* 048E52 */
#define bubbles_3_animations_5_ADDRESS 0x6EACu    /* 048EAC */
#define bubbles_3_animations_5_sprites_ADDRESS 0x6EC4u    /* 048EC4 */
#define bubbles_3_animations_5_sprites_2_ADDRESS 0x6EFAu    /* 048EFA */
#define bubbles_3_animations_5_sprites_3_ADDRESS 0x6F30u    /* 048F30 */
#define bubbles_3_animations_5_sprites_4_ADDRESS 0x6F66u    /* 048F66 */
#define bubbles_3_animations_5_sprites_5_ADDRESS 0x6FA8u    /* 048FA8 */
#define bubbles_3_animations_6_ADDRESS 0x6FF6u    /* 048FF6 */
#define bubbles_3_animations_6_sprites_ADDRESS 0x701Au    /* 04901A */
#define bubbles_3_animations_6_sprites_2_ADDRESS 0x7068u    /* 049068 */
#define bubbles_3_animations_6_sprites_3_ADDRESS 0x70B6u    /* 0490B6 */
#define bubbles_3_animations_6_sprites_4_ADDRESS 0x7104u    /* 049104 */
#define bubbles_3_animations_6_sprites_5_ADDRESS 0x7152u    /* 049152 */
#define bubbles_3_animations_6_sprites_6_ADDRESS 0x71A0u    /* 0491A0 */
#define bubbles_3_animations_6_sprites_7_ADDRESS 0x71EEu    /* 0491EE */
#define bubbles_3_animations_6_sprites_8_ADDRESS 0x723Cu    /* 04923C */
#define bubbles_3_animations_7_ADDRESS 0x728Au    /* 04928A */
#define bubbles_3_animations_7_sprites_ADDRESS 0x72BAu    /* 0492BA */
#define bubbles_3_animations_7_sprites_2_ADDRESS 0x7308u    /* 049308 */
#define bubbles_3_animations_7_sprites_3_ADDRESS 0x7356u    /* 049356 */
#define bubbles_3_animations_7_sprites_4_ADDRESS 0x73A4u    /* 0493A4 */
#define bubbles_3_animations_7_sprites_5_ADDRESS 0x73F2u    /* 0493F2 */
#define bubbles_3_animations_7_sprites_6_ADDRESS 0x7446u    /* 049446 */
#define bubbles_3_animations_7_sprites_7_ADDRESS 0x749Au    /* 04949A */
#define bubbles_3_animations_8_ADDRESS 0x74EEu    /* 0494EE */
#define bubbles_3_animations_9_ADDRESS 0x74F6u    /* 0494F6 */
#define bubbles_3_animations_9_sprites_ADDRESS 0x7512u    /* 049512 */
#define bubbles_3_animations_10_ADDRESS 0x753Cu    /* 04953C */
#define bubbles_3_animations_10_sprites_ADDRESS 0x7554u    /* 049554 */
#define bubbles_3_animations_10_sprites_2_ADDRESS 0x75A2u    /* 0495A2 */
#define bubbles_3_animations_10_sprites_3_ADDRESS 0x75E4u    /* 0495E4 */
#define bubbles_3_animations_10_sprites_4_ADDRESS 0x7626u    /* 049626 */
#define bubbles_3_animations_10_sprites_5_ADDRESS 0x7656u    /* 049656 */
#define dreamland_boss_balls_animations_ADDRESS 0x7680u    /* 049680 */
#define dreamland_boss_balls_animations_0_ADDRESS 0x76A6u    /* 0496A6 */
#define dreamland_boss_balls_animations_0_sprites_ADDRESS 0x76AEu    /* 0496AE */
#define dreamland_boss_balls_animations_1_ADDRESS 0x76B4u    /* 0496B4 */
#define dreamland_boss_balls_animations_1_sprites_ADDRESS 0x76BCu    /* 0496BC */
#define dreamland_boss_balls_animations_2_ADDRESS 0x76C2u    /* 0496C2 */
#define dreamland_boss_balls_animations_2_sprites_ADDRESS 0x76CAu    /* 0496CA */
#define dreamland_boss_balls_animations_3_ADDRESS 0x76E2u    /* 0496E2 */
#define dreamland_boss_balls_animations_3_sprites_ADDRESS 0x76EEu    /* 0496EE */
#define dreamland_boss_balls_animations_3_sprites_2_ADDRESS 0x76FAu    /* 0496FA */
#define dreamland_boss_balls_animations_4_ADDRESS 0x7706u    /* 049706 */
#define dreamland_boss_balls_animations_4_rest_ADDRESS 0x7716u    /* 049716 */
#define dreamland_boss_balls_animations_4_sprites_ADDRESS 0x7728u    /* 049728 */
#define dreamland_boss_balls_animations_4_sprites_2_ADDRESS 0x772Eu    /* 04972E */
#define dreamland_boss_balls_animations_4_sprites_3_ADDRESS 0x773Au    /* 04973A */
#define dreamland_boss_balls_animations_5_ADDRESS 0x7746u    /* 049746 */
#define dreamland_boss_balls_animations_5_sprites_ADDRESS 0x775Au    /* 04975A */
#define dreamland_boss_balls_animations_5_sprites_2_ADDRESS 0x7760u    /* 049760 */
#define dreamland_boss_balls_animations_5_sprites_3_ADDRESS 0x7766u    /* 049766 */
#define dreamland_boss_balls_animations_5_sprites_4_ADDRESS 0x7784u    /* 049784 */
#define dreamland_boss_balls_animations_6_ADDRESS 0x77A2u    /* 0497A2 */
#define dreamland_boss_balls_animations_6_sprites_ADDRESS 0x77AAu    /* 0497AA */
#define dreamland_boss_balls_animations_7_ADDRESS 0x77B6u    /* 0497B6 */
#define dreamland_boss_balls_animations_7_sprites_ADDRESS 0x77C2u    /* 0497C2 */
#define dreamland_boss_balls_animations_7_sprites_2_ADDRESS 0x77C8u    /* 0497C8 */
#define dreamland_boss_balls_animations_8_ADDRESS 0x77CEu    /* 0497CE */
#define dreamland_boss_balls_animations_8_sprites_ADDRESS 0x77FAu    /* 0497FA */
#define dreamland_boss_balls_animations_8_sprites_2_ADDRESS 0x781Eu    /* 04981E */
#define dreamland_boss_balls_animations_8_sprites_3_ADDRESS 0x784Eu    /* 04984E */
#define dreamland_boss_balls_animations_8_sprites_4_ADDRESS 0x7890u    /* 049890 */
#define dreamland_boss_balls_animations_8_sprites_5_ADDRESS 0x78D8u    /* 0498D8 */
#define dreamland_boss_balls_animations_8_sprites_6_ADDRESS 0x7938u    /* 049938 */
#define dreamland_boss_balls_animations_8_sprites_7_ADDRESS 0x798Cu    /* 04998C */
#define dreamland_boss_balls_animations_8_sprites_8_ADDRESS 0x79DAu    /* 0499DA */
#define dreamland_boss_balls_animations_8_sprites_9_ADDRESS 0x7A1Cu    /* 049A1C */
#define dreamland_boss_balls_animations_8_sprites_10_ADDRESS 0x7A3Au    /* 049A3A */
#define dreamland_boss_balls_animations_9_ADDRESS 0x7A4Cu    /* 049A4C */
#define dreamland_boss_balls_animations_9_sprites_ADDRESS 0x7A54u    /* 049A54 */
#define dreamland_boss_balls_animations_10_ADDRESS 0x7A5Au    /* 049A5A */
#define dreamland_boss_balls_animations_10_sprites_ADDRESS 0x7A76u    /* 049A76 */
#define dreamland_boss_balls_animations_10_sprites_2_ADDRESS 0x7A7Cu    /* 049A7C */
#define dreamland_boss_balls_animations_10_sprites_3_ADDRESS 0x7A82u    /* 049A82 */
#define dreamland_boss_balls_animations_10_sprites_4_ADDRESS 0x7A88u    /* 049A88 */
#define dreamland_boss_balls_animations_10_sprites_5_ADDRESS 0x7A8Eu    /* 049A8E */
#define dreamland_boss_balls_animations_10_sprites_6_ADDRESS 0x7A94u    /* 049A94 */
#define dreamland_boss_balls_animations_11_ADDRESS 0x7A9Au    /* 049A9A */
#define dreamland_boss_balls_animations_11_sprites_ADDRESS 0x7AA2u    /* 049AA2 */
#define dreamland_boss_balls_animations_12_ADDRESS 0x7AA8u    /* 049AA8 */
#define dreamland_boss_balls_animations_12_sprites_ADDRESS 0x7AB4u    /* 049AB4 */
#define dreamland_boss_balls_animations_12_sprites_2_ADDRESS 0x7ABAu    /* 049ABA */
#define dreamland_boss_balls_animations_13_ADDRESS 0x7AC0u    /* 049AC0 */
#define dreamland_boss_balls_animations_13_sprites_ADDRESS 0x7AC8u    /* 049AC8 */
#define dreamland_boss_balls_animations_14_ADDRESS 0x7ACEu    /* 049ACE */
#define dreamland_boss_balls_animations_15_ADDRESS 0x7ADAu    /* 049ADA */
#define dreamland_boss_balls_animations_15_sprites_ADDRESS 0x7AE2u    /* 049AE2 */
#define dreamland_boss_balls_animations_16_ADDRESS 0x7AEEu    /* 049AEE */
#define dreamland_boss_balls_animations_16_sprites_ADDRESS 0x7AF6u    /* 049AF6 */
#define dreamland_boss_balls_animations_17_ADDRESS 0x7B02u    /* 049B02 */
#define dreamland_boss_balls_animations_17_sprites_ADDRESS 0x7B0Au    /* 049B0A */
#define dreamland_boss_balls_animations_18_ADDRESS 0x7B16u    /* 049B16 */
#define dreamland_boss_balls_animations_18_sprites_ADDRESS 0x7B36u    /* 049B36 */
#define dreamland_boss_balls_animations_18_sprites_2_ADDRESS 0x7B42u    /* 049B42 */
#define dreamland_boss_balls_animations_18_sprites_3_ADDRESS 0x7B54u    /* 049B54 */
#define dreamland_boss_balls_animations_18_sprites_4_ADDRESS 0x7B7Eu    /* 049B7E */
#define dreamland_boss_balls_animations_18_sprites_5_ADDRESS 0x7BA8u    /* 049BA8 */
#define dreamland_boss_balls_animations_18_sprites_6_ADDRESS 0x7BC6u    /* 049BC6 */
#define dreamland_boss_balls_animations_18_sprites_7_ADDRESS 0x7BE4u    /* 049BE4 */
#define numbers_animations_ADDRESS 0x7BF0u    /* 049BF0 */
#define numbers_animations_0_ADDRESS 0x7BF2u    /* 049BF2 */
#define numbers_animations_0_sprites_ADDRESS 0x7C02u    /* 049C02 */
#define numbers_animations_0_sprites_2_ADDRESS 0x7C08u    /* 049C08 */
#define numbers_animations_0_sprites_3_ADDRESS 0x7C0Eu    /* 049C0E */
#define numbers_animations_0_sprites_3_fill_ADDRESS 0x7C1Au    /* 049C1A */
#define numbers_animations_0_sprites_3_rest_ADDRESS 0x7D48u    /* 049D48 */
#define numbers_animations_0_sprites_3_rest_2_ADDRESS 0x7D64u    /* 049D64 */
#define numbers_animations_0_sprites_3_rest_3_ADDRESS 0x7D8Eu    /* 049D8E */
#define numbers_animations_0_sprites_3_rest_4_ADDRESS 0x7DBEu    /* 049DBE */
#define numbers_animations_0_sprites_3_rest_5_ADDRESS 0x7DF4u    /* 049DF4 */
#define numbers_animations_0_sprites_3_rest_6_ADDRESS 0x7E30u    /* 049E30 */
#define numbers_animations_0_sprites_3_rest_7_ADDRESS 0x7E78u    /* 049E78 */
#define numbers_animations_0_sprites_3_fill_2_ADDRESS 0x7ECCu    /* 049ECC */
#define numbers_animations_0_sprites_3_rest_8_ADDRESS 0x6000u    /* 04A000 */
#define bubbles_2_animations_ADDRESS 0x6002u    /* 04A002 */
#define bubbles_2_animations_5_sprites_ADDRESS 0x6020u    /* 04A020 */
#define bubbles_2_animations_0_ADDRESS 0x604Au    /* 04A04A */
#define bubbles_2_animations_0_sprites_ADDRESS 0x60A2u    /* 04A0A2 */
#define bubbles_2_animations_0_sprites_2_ADDRESS 0x60D2u    /* 04A0D2 */
#define bubbles_2_animations_0_sprites_3_ADDRESS 0x6108u    /* 04A108 */
#define bubbles_2_animations_0_sprites_4_ADDRESS 0x6144u    /* 04A144 */
#define bubbles_2_animations_0_sprites_5_ADDRESS 0x6186u    /* 04A186 */
#define bubbles_2_animations_0_sprites_6_ADDRESS 0x61C8u    /* 04A1C8 */
#define bubbles_2_animations_0_sprites_7_ADDRESS 0x620Au    /* 04A20A */
#define bubbles_2_animations_0_sprites_8_ADDRESS 0x6258u    /* 04A258 */
#define bubbles_2_animations_0_sprites_9_ADDRESS 0x62ACu    /* 04A2AC */
#define bubbles_2_animations_0_sprites_10_ADDRESS 0x6306u    /* 04A306 */
#define bubbles_2_animations_0_sprites_11_ADDRESS 0x6366u    /* 04A366 */
#define bubbles_2_animations_0_sprites_12_ADDRESS 0x63C6u    /* 04A3C6 */
#define bubbles_2_animations_0_sprites_13_ADDRESS 0x6420u    /* 04A420 */
#define bubbles_2_animations_0_sprites_14_ADDRESS 0x6474u    /* 04A474 */
#define bubbles_2_animations_0_sprites_15_ADDRESS 0x64C2u    /* 04A4C2 */
#define bubbles_2_animations_0_sprites_16_ADDRESS 0x650Au    /* 04A50A */
#define bubbles_2_animations_0_sprites_17_ADDRESS 0x654Cu    /* 04A54C */
#define bubbles_2_animations_0_sprites_18_ADDRESS 0x6588u    /* 04A588 */
#define bubbles_2_animations_0_sprites_19_ADDRESS 0x65BEu    /* 04A5BE */
#define bubbles_2_animations_0_sprites_20_ADDRESS 0x65EEu    /* 04A5EE */
#define bubbles_2_animations_0_sprites_21_ADDRESS 0x6618u    /* 04A618 */
#define bubbles_2_animations_1_ADDRESS 0x663Cu    /* 04A63C */
#define bubbles_2_animations_1_sprites_ADDRESS 0x668Cu    /* 04A68C */
#define bubbles_2_animations_1_sprites_2_ADDRESS 0x66B6u    /* 04A6B6 */
#define bubbles_2_animations_1_sprites_3_ADDRESS 0x66E6u    /* 04A6E6 */
#define bubbles_2_animations_1_sprites_4_ADDRESS 0x671Cu    /* 04A71C */
#define bubbles_2_animations_1_sprites_5_ADDRESS 0x6758u    /* 04A758 */
#define bubbles_2_animations_1_sprites_6_ADDRESS 0x6794u    /* 04A794 */
#define bubbles_2_animations_1_sprites_7_ADDRESS 0x67D6u    /* 04A7D6 */
#define bubbles_2_animations_1_sprites_8_ADDRESS 0x681Eu    /* 04A81E */
#define bubbles_2_animations_1_sprites_9_ADDRESS 0x686Cu    /* 04A86C */
#define bubbles_2_animations_1_sprites_10_ADDRESS 0x68B4u    /* 04A8B4 */
#define bubbles_2_animations_1_sprites_11_ADDRESS 0x68F6u    /* 04A8F6 */
#define bubbles_2_animations_1_sprites_12_ADDRESS 0x6932u    /* 04A932 */
#define bubbles_2_animations_1_sprites_13_ADDRESS 0x6968u    /* 04A968 */
#define bubbles_2_animations_1_sprites_14_ADDRESS 0x6998u    /* 04A998 */
#define bubbles_2_animations_1_sprites_15_ADDRESS 0x69C2u    /* 04A9C2 */
#define bubbles_2_animations_1_sprites_16_ADDRESS 0x69E6u    /* 04A9E6 */
#define bubbles_2_animations_1_sprites_17_ADDRESS 0x6A04u    /* 04AA04 */
#define bubbles_2_animations_1_sprites_18_ADDRESS 0x6A2Eu    /* 04AA2E */
#define bubbles_2_animations_1_sprites_19_ADDRESS 0x6A58u    /* 04AA58 */
#define bubbles_2_animations_2_ADDRESS 0x6A82u    /* 04AA82 */
#define bubbles_2_animations_2_sprites_ADDRESS 0x6AD2u    /* 04AAD2 */
#define bubbles_2_animations_2_sprites_2_ADDRESS 0x6AFCu    /* 04AAFC */
#define bubbles_2_animations_2_sprites_3_ADDRESS 0x6B2Cu    /* 04AB2C */
#define bubbles_2_animations_2_sprites_4_ADDRESS 0x6B5Cu    /* 04AB5C */
#define bubbles_2_animations_2_sprites_5_ADDRESS 0x6B92u    /* 04AB92 */
#define bubbles_2_animations_2_sprites_6_ADDRESS 0x6BCEu    /* 04ABCE */
#define bubbles_2_animations_2_sprites_7_ADDRESS 0x6C10u    /* 04AC10 */
#define bubbles_2_animations_2_sprites_8_ADDRESS 0x6C58u    /* 04AC58 */
#define bubbles_2_animations_2_sprites_9_ADDRESS 0x6CA6u    /* 04ACA6 */
#define bubbles_2_animations_2_sprites_10_ADDRESS 0x6D00u    /* 04AD00 */
#define bubbles_2_animations_2_sprites_11_ADDRESS 0x6D60u    /* 04AD60 */
#define bubbles_2_animations_2_sprites_12_ADDRESS 0x6DBAu    /* 04ADBA */
#define bubbles_2_animations_2_sprites_13_ADDRESS 0x6E1Au    /* 04AE1A */
#define bubbles_2_animations_2_sprites_14_ADDRESS 0x6E7Au    /* 04AE7A */
#define bubbles_2_animations_2_sprites_15_ADDRESS 0x6EDAu    /* 04AEDA */
#define bubbles_2_animations_2_sprites_16_ADDRESS 0x6F3Au    /* 04AF3A */
#define bubbles_2_animations_2_sprites_17_ADDRESS 0x6F9Au    /* 04AF9A */
#define bubbles_2_animations_2_sprites_18_ADDRESS 0x6FFAu    /* 04AFFA */
#define bubbles_2_animations_2_sprites_19_ADDRESS 0x705Au    /* 04B05A */
#define bubbles_2_animations_3_ADDRESS 0x70BAu    /* 04B0BA */
#define bubbles_2_animations_4_ADDRESS 0x710Au    /* 04B10A */
#define bubbles_2_animations_4_sprites_ADDRESS 0x712Au    /* 04B12A */
#define bubbles_2_animations_4_sprites_2_ADDRESS 0x715Au    /* 04B15A */
#define bubbles_2_animations_4_sprites_3_ADDRESS 0x718Au    /* 04B18A */
#define bubbles_2_animations_4_sprites_4_ADDRESS 0x71C0u    /* 04B1C0 */
#define bubbles_2_animations_4_sprites_5_ADDRESS 0x7202u    /* 04B202 */
#define bubbles_2_animations_4_sprites_6_ADDRESS 0x7250u    /* 04B250 */
#define bubbles_2_animations_4_sprites_7_ADDRESS 0x72AAu    /* 04B2AA */
#define bubbles_2_animations_5_ADDRESS 0x730Au    /* 04B30A */
#define bubbles_2_animations_6_ADDRESS 0x732Eu    /* 04B32E */
#define bubbles_2_animations_6_sprites_ADDRESS 0x735Au    /* 04B35A */
#define bubbles_2_animations_6_sprites_2_ADDRESS 0x73BAu    /* 04B3BA */
#define bubbles_2_animations_6_sprites_3_ADDRESS 0x741Au    /* 04B41A */
#define bubbles_2_animations_7_ADDRESS 0x747Au    /* 04B47A */
#define bubbles_2_animations_7_sprites_ADDRESS 0x749Eu    /* 04B49E */
#define bubbles_2_animations_7_sprites_2_ADDRESS 0x74FEu    /* 04B4FE */
#define bubbles_2_animations_7_sprites_3_ADDRESS 0x755Eu    /* 04B55E */
#define bubbles_2_animations_7_sprites_4_ADDRESS 0x75BEu    /* 04B5BE */
#define bubbles_2_animations_8_ADDRESS 0x761Eu    /* 04B61E */
#define bubbles_2_animations_8_sprites_ADDRESS 0x7642u    /* 04B642 */
#define bubbles_2_animations_8_sprites_2_ADDRESS 0x76A2u    /* 04B6A2 */
#define bubbles_2_animations_8_sprites_3_ADDRESS 0x7702u    /* 04B702 */
#define bubbles_2_animations_9_ADDRESS 0x7762u    /* 04B762 */
#define bubbles_2_animations_9_sprites_ADDRESS 0x7786u    /* 04B786 */
#define bubbles_2_animations_9_sprites_2_ADDRESS 0x77E6u    /* 04B7E6 */
#define bubbles_2_animations_9_sprites_3_ADDRESS 0x7846u    /* 04B846 */
#define bubbles_2_animations_10_ADDRESS 0x78A6u    /* 04B8A6 */
#define bubbles_2_animations_10_sprites_ADDRESS 0x78C6u    /* 04B8C6 */
#define bubbles_2_animations_10_sprites_2_ADDRESS 0x7920u    /* 04B920 */
#define bubbles_2_animations_10_sprites_3_ADDRESS 0x797Au    /* 04B97A */
#define bubbles_2_animations_11_ADDRESS 0x79D4u    /* 04B9D4 */
#define bubbles_2_animations_11_sprites_ADDRESS 0x79F4u    /* 04B9F4 */
#define bubbles_2_animations_11_sprites_2_ADDRESS 0x7A24u    /* 04BA24 */
#define bubbles_2_animations_11_sprites_3_ADDRESS 0x7A54u    /* 04BA54 */
#define bubbles_2_animations_11_sprites_4_ADDRESS 0x7A8Au    /* 04BA8A */
#define bubbles_2_animations_11_sprites_5_ADDRESS 0x7AC6u    /* 04BAC6 */
#define bubbles_2_animations_11_sprites_6_ADDRESS 0x7B08u    /* 04BB08 */
#define bubbles_2_animations_11_sprites_7_ADDRESS 0x7B56u    /* 04BB56 */
#define bubbles_2_animations_12_ADDRESS 0x7BA4u    /* 04BBA4 */
#define bubbles_2_animations_13_ADDRESS 0x7BC4u    /* 04BBC4 */
#define bubbles_2_animations_13_sprites_ADDRESS 0x7BE0u    /* 04BBE0 */
#define bubbles_2_animations_13_sprites_2_ADDRESS 0x7C34u    /* 04BC34 */
#define bubbles_2_animations_13_sprites_3_ADDRESS 0x7C7Cu    /* 04BC7C */
#define bubbles_2_animations_13_sprites_4_ADDRESS 0x7CB8u    /* 04BCB8 */
#define bubbles_2_animations_13_sprites_5_ADDRESS 0x7CEEu    /* 04BCEE */
#define bubbles_2_animations_13_sprites_6_ADDRESS 0x7D1Eu    /* 04BD1E */
#define bubbles_2_animations_14_ADDRESS 0x7D48u    /* 04BD48 */
#define bubbles_2_animations_14_sprites_ADDRESS 0x7D64u    /* 04BD64 */
#define bubbles_2_animations_14_sprites_2_ADDRESS 0x7D8Eu    /* 04BD8E */
#define bubbles_2_animations_14_sprites_3_ADDRESS 0x7DBEu    /* 04BDBE */
#define bubbles_2_animations_14_sprites_4_ADDRESS 0x7DF4u    /* 04BDF4 */
#define bubbles_2_animations_14_sprites_5_ADDRESS 0x7E30u    /* 04BE30 */
#define bubbles_2_animations_14_sprites_6_ADDRESS 0x7E78u    /* 04BE78 */
#define bubbles_2_animations_14_sprites_6_fill_ADDRESS 0x7ECCu    /* 04BECC */
#define bubbles_2_animations_14_sprites_6_rest_ADDRESS 0x6000u    /* 04C000 */
#define knight_animations_ADDRESS 0x600Au    /* 04C00A */
#define knight_animations_0_ADDRESS 0x602Cu    /* 04C02C */
#define knight_animations_0_sprites_ADDRESS 0x6058u    /* 04C058 */
#define knight_animations_0_sprites_2_ADDRESS 0x606Au    /* 04C06A */
#define knight_animations_0_sprites_3_ADDRESS 0x6082u    /* 04C082 */
#define knight_animations_0_sprites_4_ADDRESS 0x609Au    /* 04C09A */
#define knight_animations_0_sprites_5_ADDRESS 0x60ACu    /* 04C0AC */
#define knight_animations_0_sprites_6_ADDRESS 0x60C4u    /* 04C0C4 */
#define knight_animations_1_ADDRESS 0x60DCu    /* 04C0DC */
#define knight_animations_1_sprites_ADDRESS 0x6118u    /* 04C118 */
#define knight_animations_1_sprites_2_ADDRESS 0x613Cu    /* 04C13C */
#define knight_animations_1_sprites_3_ADDRESS 0x6160u    /* 04C160 */
#define knight_animations_1_sprites_4_ADDRESS 0x617Eu    /* 04C17E */
#define knight_animations_1_sprites_5_ADDRESS 0x619Cu    /* 04C19C */
#define knight_animations_1_sprites_6_ADDRESS 0x61BAu    /* 04C1BA */
#define knight_animations_1_sprites_7_ADDRESS 0x61D8u    /* 04C1D8 */
#define knight_animations_1_sprites_8_ADDRESS 0x61FCu    /* 04C1FC */
#define knight_animations_16_ADDRESS 0x621Au    /* 04C21A */
#define knight_animations_16_sprites_ADDRESS 0x6236u    /* 04C236 */
#define knight_animations_16_sprites_2_ADDRESS 0x6248u    /* 04C248 */
#define knight_animations_16_sprites_3_ADDRESS 0x6260u    /* 04C260 */
#define knight_animations_16_sprites_4_ADDRESS 0x627Eu    /* 04C27E */
#define knight_animations_15_ADDRESS 0x629Cu    /* 04C29C */
#define knight_animations_15_sprites_ADDRESS 0x62C0u    /* 04C2C0 */
#define knight_animations_15_sprites_2_ADDRESS 0x62D8u    /* 04C2D8 */
#define knight_animations_15_sprites_3_ADDRESS 0x62F6u    /* 04C2F6 */
#define knight_animations_15_sprites_4_ADDRESS 0x630Eu    /* 04C30E */
#define knight_animations_15_sprites_5_ADDRESS 0x632Cu    /* 04C32C */
#define knight_animations_15_sprites_6_ADDRESS 0x6344u    /* 04C344 */
#define knight_animations_11_ADDRESS 0x6362u    /* 04C362 */
#define knight_animations_11_sprites_ADDRESS 0x638Eu    /* 04C38E */
#define knight_animations_11_sprites_2_ADDRESS 0x63B2u    /* 04C3B2 */
#define knight_animations_11_sprites_3_ADDRESS 0x63D6u    /* 04C3D6 */
#define knight_animations_11_sprites_4_ADDRESS 0x63FAu    /* 04C3FA */
#define knight_animations_11_sprites_5_ADDRESS 0x6418u    /* 04C418 */
#define knight_animations_11_sprites_6_ADDRESS 0x6436u    /* 04C436 */
#define knight_animations_6_ADDRESS 0x6454u    /* 04C454 */
#define knight_animations_6_sprites_ADDRESS 0x6478u    /* 04C478 */
#define knight_animations_6_sprites_2_ADDRESS 0x6496u    /* 04C496 */
#define knight_animations_6_sprites_3_ADDRESS 0x64B4u    /* 04C4B4 */
#define knight_animations_6_sprites_4_ADDRESS 0x64DEu    /* 04C4DE */
#define knight_animations_9_ADDRESS 0x6508u    /* 04C508 */
#define knight_animations_9_sprites_ADDRESS 0x6534u    /* 04C534 */
#define knight_animations_9_sprites_2_ADDRESS 0x6552u    /* 04C552 */
#define knight_animations_9_sprites_3_ADDRESS 0x6570u    /* 04C570 */
#define knight_2_animations_ADDRESS 0x658Eu    /* 04C58E */
#define knight_animations_8_ADDRESS 0x65B0u    /* 04C5B0 */
#define knight_animations_8_sprites_ADDRESS 0x65BCu    /* 04C5BC */
#define knight_animations_8_sprites_2_ADDRESS 0x65D4u    /* 04C5D4 */
#define knight_2_animations_1_ADDRESS 0x65ECu    /* 04C5EC */
#define knight_2_animations_1_sprites_ADDRESS 0x6628u    /* 04C628 */
#define knight_2_animations_1_sprites_2_ADDRESS 0x6646u    /* 04C646 */
#define knight_2_animations_1_sprites_3_ADDRESS 0x6664u    /* 04C664 */
#define knight_2_animations_1_sprites_4_ADDRESS 0x667Cu    /* 04C67C */
#define knight_2_animations_1_sprites_5_ADDRESS 0x6694u    /* 04C694 */
#define knight_2_animations_1_sprites_6_ADDRESS 0x66ACu    /* 04C6AC */
#define knight_2_animations_1_sprites_7_ADDRESS 0x66C4u    /* 04C6C4 */
#define knight_2_animations_1_sprites_8_ADDRESS 0x66E2u    /* 04C6E2 */
#define knight_2_animations_16_ADDRESS 0x66FAu    /* 04C6FA */
#define knight_2_animations_16_sprites_ADDRESS 0x6716u    /* 04C716 */
#define knight_2_animations_16_sprites_2_ADDRESS 0x6728u    /* 04C728 */
#define knight_2_animations_16_sprites_3_ADDRESS 0x6740u    /* 04C740 */
#define knight_2_animations_16_sprites_4_ADDRESS 0x6758u    /* 04C758 */
#define knight_2_animations_15_ADDRESS 0x6770u    /* 04C770 */
#define knight_2_animations_15_sprites_ADDRESS 0x6794u    /* 04C794 */
#define knight_2_animations_15_sprites_2_ADDRESS 0x67ACu    /* 04C7AC */
#define knight_2_animations_15_sprites_3_ADDRESS 0x67C4u    /* 04C7C4 */
#define knight_2_animations_15_sprites_4_ADDRESS 0x67DCu    /* 04C7DC */
#define knight_2_animations_15_sprites_5_ADDRESS 0x67F4u    /* 04C7F4 */
#define knight_2_animations_15_sprites_6_ADDRESS 0x680Cu    /* 04C80C */
#define knight_2_animations_11_ADDRESS 0x6824u    /* 04C824 */
#define knight_2_animations_11_sprites_ADDRESS 0x6850u    /* 04C850 */
#define knight_2_animations_11_sprites_2_ADDRESS 0x686Eu    /* 04C86E */
#define knight_2_animations_11_sprites_3_ADDRESS 0x688Cu    /* 04C88C */
#define knight_2_animations_11_sprites_4_ADDRESS 0x68AAu    /* 04C8AA */
#define knight_2_animations_11_sprites_5_ADDRESS 0x68C2u    /* 04C8C2 */
#define knight_2_animations_11_sprites_6_ADDRESS 0x68DAu    /* 04C8DA */
#define knight_2_animations_8_ADDRESS 0x68F2u    /* 04C8F2 */
#define knight_2_animations_8_sprites_ADDRESS 0x691Eu    /* 04C91E */
#define knight_2_animations_8_sprites_2_ADDRESS 0x6936u    /* 04C936 */
#define knight_2_animations_8_sprites_3_ADDRESS 0x6954u    /* 04C954 */
#define knight_2_animations_8_sprites_4_ADDRESS 0x6972u    /* 04C972 */
#define knight_2_animations_8_sprites_5_ADDRESS 0x6990u    /* 04C990 */
#define knight_2_animations_8_sprites_6_ADDRESS 0x69B4u    /* 04C9B4 */
#define knight_2_animations_8_sprites_7_ADDRESS 0x69D8u    /* 04C9D8 */
#define knight_2_animations_8_sprites_8_ADDRESS 0x69F6u    /* 04C9F6 */
#define knight_2_animations_8_sprites_9_ADDRESS 0x6A14u    /* 04CA14 */
#define knight_2_animations_8_sprites_10_ADDRESS 0x6A32u    /* 04CA32 */
#define knight_2_animations_6_ADDRESS 0x6A50u    /* 04CA50 */
#define knight_2_animations_6_sprites_ADDRESS 0x6A78u    /* 04CA78 */
#define knight_2_animations_6_sprites_2_ADDRESS 0x6A96u    /* 04CA96 */
#define knight_2_animations_6_sprites_3_ADDRESS 0x6AAEu    /* 04CAAE */
#define knight_2_animations_6_sprites_4_ADDRESS 0x6AD2u    /* 04CAD2 */
#define knight_2_animations_6_sprites_5_ADDRESS 0x6AF6u    /* 04CAF6 */
#define knight_2_animations_6_sprites_6_ADDRESS 0x6B1Au    /* 04CB1A */
#define knight_2_animations_9_ADDRESS 0x6B3Eu    /* 04CB3E */
#define knight_2_animations_9_sprites_ADDRESS 0x6B6Au    /* 04CB6A */
#define knight_2_animations_9_sprites_2_ADDRESS 0x6B82u    /* 04CB82 */
#define knight_2_animations_9_sprites_3_ADDRESS 0x6B9Au    /* 04CB9A */
#define knight_3_animations_ADDRESS 0x6BB2u    /* 04CBB2 */
#define knight_3_animations_0_ADDRESS 0x6BD4u    /* 04CBD4 */
#define knight_3_animations_0_sprites_ADDRESS 0x6C00u    /* 04CC00 */
#define knight_3_animations_0_sprites_2_ADDRESS 0x6C12u    /* 04CC12 */
#define knight_3_animations_0_sprites_3_ADDRESS 0x6C2Au    /* 04CC2A */
#define knight_3_animations_0_sprites_4_ADDRESS 0x6C42u    /* 04CC42 */
#define knight_3_animations_0_sprites_5_ADDRESS 0x6C5Au    /* 04CC5A */
#define knight_3_animations_0_sprites_6_ADDRESS 0x6C78u    /* 04CC78 */
#define knight_3_animations_1_ADDRESS 0x6C96u    /* 04CC96 */
#define knight_3_animations_1_sprites_ADDRESS 0x6CD2u    /* 04CCD2 */
#define knight_3_animations_1_sprites_2_ADDRESS 0x6CF6u    /* 04CCF6 */
#define knight_3_animations_1_sprites_3_ADDRESS 0x6D1Au    /* 04CD1A */
#define knight_3_animations_1_sprites_4_ADDRESS 0x6D38u    /* 04CD38 */
#define knight_3_animations_1_sprites_5_ADDRESS 0x6D56u    /* 04CD56 */
#define knight_3_animations_1_sprites_6_ADDRESS 0x6D74u    /* 04CD74 */
#define knight_3_animations_1_sprites_7_ADDRESS 0x6D92u    /* 04CD92 */
#define knight_3_animations_1_sprites_8_ADDRESS 0x6DB6u    /* 04CDB6 */
#define knight_3_animations_16_ADDRESS 0x6DD4u    /* 04CDD4 */
#define knight_3_animations_16_sprites_ADDRESS 0x6DF0u    /* 04CDF0 */
#define knight_3_animations_16_sprites_2_ADDRESS 0x6E08u    /* 04CE08 */
#define knight_3_animations_16_sprites_3_ADDRESS 0x6E20u    /* 04CE20 */
#define knight_3_animations_16_sprites_4_ADDRESS 0x6E44u    /* 04CE44 */
#define knight_3_animations_15_ADDRESS 0x6E68u    /* 04CE68 */
#define knight_3_animations_15_sprites_ADDRESS 0x6E8Cu    /* 04CE8C */
#define knight_3_animations_15_sprites_2_ADDRESS 0x6EAAu    /* 04CEAA */
#define knight_3_animations_15_sprites_3_ADDRESS 0x6ECEu    /* 04CECE */
#define knight_3_animations_15_sprites_4_ADDRESS 0x6EECu    /* 04CEEC */
#define knight_3_animations_15_sprites_5_ADDRESS 0x6F10u    /* 04CF10 */
#define knight_3_animations_15_sprites_6_ADDRESS 0x6F2Eu    /* 04CF2E */
#define knight_3_animations_6_ADDRESS 0x6F52u    /* 04CF52 */
#define knight_3_animations_6_sprites_ADDRESS 0x6F76u    /* 04CF76 */
#define knight_3_animations_6_sprites_2_ADDRESS 0x6F9Au    /* 04CF9A */
#define knight_3_animations_6_sprites_3_ADDRESS 0x6FBEu    /* 04CFBE */
#define knight_3_animations_6_sprites_4_ADDRESS 0x6FEEu    /* 04CFEE */
#define knight_3_animations_11_ADDRESS 0x701Eu    /* 04D01E */
#define knight_3_animations_11_sprites_ADDRESS 0x704Au    /* 04D04A */
#define knight_3_animations_11_sprites_2_ADDRESS 0x706Eu    /* 04D06E */
#define knight_3_animations_11_sprites_3_ADDRESS 0x7092u    /* 04D092 */
#define knight_3_animations_11_sprites_4_ADDRESS 0x70B6u    /* 04D0B6 */
#define knight_3_animations_11_sprites_5_ADDRESS 0x70DAu    /* 04D0DA */
#define knight_3_animations_11_sprites_6_ADDRESS 0x70FEu    /* 04D0FE */
#define knight_3_animations_9_ADDRESS 0x7122u    /* 04D122 */
#define knight_3_animations_9_sprites_ADDRESS 0x714Eu    /* 04D14E */
#define knight_3_animations_9_sprites_2_ADDRESS 0x7172u    /* 04D172 */
#define knight_3_animations_9_sprites_3_ADDRESS 0x7196u    /* 04D196 */
#define knight_4_animations_ADDRESS 0x71BAu    /* 04D1BA */
#define knight_3_animations_8_ADDRESS 0x71DCu    /* 04D1DC */
#define knight_3_animations_8_sprites_ADDRESS 0x7208u    /* 04D208 */
#define knight_3_animations_8_sprites_2_ADDRESS 0x7220u    /* 04D220 */
#define knight_3_animations_8_sprites_3_ADDRESS 0x7238u    /* 04D238 */
#define knight_3_animations_8_sprites_4_ADDRESS 0x7250u    /* 04D250 */
#define knight_3_animations_8_sprites_5_ADDRESS 0x726Eu    /* 04D26E */
#define knight_3_animations_8_sprites_6_ADDRESS 0x728Cu    /* 04D28C */
#define knight_4_animations_1_ADDRESS 0x72AAu    /* 04D2AA */
#define knight_4_animations_1_sprites_ADDRESS 0x72E6u    /* 04D2E6 */
#define knight_4_animations_1_sprites_2_ADDRESS 0x7304u    /* 04D304 */
#define knight_4_animations_1_sprites_3_ADDRESS 0x7322u    /* 04D322 */
#define knight_4_animations_1_sprites_4_ADDRESS 0x733Au    /* 04D33A */
#define knight_4_animations_1_sprites_5_ADDRESS 0x7352u    /* 04D352 */
#define knight_4_animations_1_sprites_6_ADDRESS 0x736Au    /* 04D36A */
#define knight_4_animations_1_sprites_7_ADDRESS 0x7382u    /* 04D382 */
#define knight_4_animations_1_sprites_8_ADDRESS 0x73A0u    /* 04D3A0 */
#define knight_4_animations_16_ADDRESS 0x73B8u    /* 04D3B8 */
#define knight_4_animations_16_sprites_ADDRESS 0x73D4u    /* 04D3D4 */
#define knight_4_animations_16_sprites_2_ADDRESS 0x73ECu    /* 04D3EC */
#define knight_4_animations_16_sprites_3_ADDRESS 0x7404u    /* 04D404 */
#define knight_4_animations_16_sprites_4_ADDRESS 0x7422u    /* 04D422 */
#define knight_4_animations_15_ADDRESS 0x7440u    /* 04D440 */
#define knight_4_animations_15_sprites_ADDRESS 0x7464u    /* 04D464 */
#define knight_4_animations_15_sprites_2_ADDRESS 0x7482u    /* 04D482 */
#define knight_4_animations_15_sprites_3_ADDRESS 0x74A0u    /* 04D4A0 */
#define knight_4_animations_15_sprites_4_ADDRESS 0x74BEu    /* 04D4BE */
#define knight_4_animations_15_sprites_5_ADDRESS 0x74DCu    /* 04D4DC */
#define knight_4_animations_15_sprites_6_ADDRESS 0x74FAu    /* 04D4FA */
#define knight_4_animations_6_ADDRESS 0x7518u    /* 04D518 */
#define knight_4_animations_6_sprites_ADDRESS 0x7540u    /* 04D540 */
#define knight_4_animations_6_sprites_2_ADDRESS 0x7564u    /* 04D564 */
#define knight_4_animations_6_sprites_3_ADDRESS 0x7582u    /* 04D582 */
#define knight_4_animations_6_sprites_4_ADDRESS 0x75ACu    /* 04D5AC */
#define knight_4_animations_6_sprites_5_ADDRESS 0x75D6u    /* 04D5D6 */
#define knight_4_animations_11_ADDRESS 0x7600u    /* 04D600 */
#define knight_4_animations_11_sprites_ADDRESS 0x762Cu    /* 04D62C */
#define knight_4_animations_11_sprites_2_ADDRESS 0x764Au    /* 04D64A */
#define knight_4_animations_11_sprites_3_ADDRESS 0x7668u    /* 04D668 */
#define knight_4_animations_11_sprites_4_ADDRESS 0x7686u    /* 04D686 */
#define knight_4_animations_11_sprites_5_ADDRESS 0x76A4u    /* 04D6A4 */
#define knight_4_animations_11_sprites_6_ADDRESS 0x76C2u    /* 04D6C2 */
#define knight_4_animations_9_ADDRESS 0x76E0u    /* 04D6E0 */
#define knight_4_animations_9_sprites_ADDRESS 0x770Cu    /* 04D70C */
#define knight_4_animations_9_sprites_2_ADDRESS 0x772Au    /* 04D72A */
#define knight_4_animations_9_sprites_3_ADDRESS 0x7748u    /* 04D748 */
#define knight_5_animations_ADDRESS 0x7766u    /* 04D766 */
#define knight_5_animations_8_ADDRESS 0x778Au    /* 04D78A */
#define knight_5_animations_8_sprites_ADDRESS 0x7796u    /* 04D796 */
#define knight_5_animations_8_sprites_2_ADDRESS 0x77A8u    /* 04D7A8 */
#define knight_5_animations_0_ADDRESS 0x77BAu    /* 04D7BA */
#define knight_5_animations_0_sprites_ADDRESS 0x77E6u    /* 04D7E6 */
#define knight_5_animations_0_sprites_2_ADDRESS 0x77FEu    /* 04D7FE */
#define knight_5_animations_0_sprites_3_ADDRESS 0x781Cu    /* 04D81C */
#define knight_5_animations_0_sprites_4_ADDRESS 0x783Au    /* 04D83A */
#define knight_5_animations_0_sprites_5_ADDRESS 0x7852u    /* 04D852 */
#define knight_5_animations_0_sprites_6_ADDRESS 0x7870u    /* 04D870 */
#define knight_5_animations_1_ADDRESS 0x788Eu    /* 04D88E */
#define knight_5_animations_1_sprites_ADDRESS 0x78CAu    /* 04D8CA */
#define knight_5_animations_1_sprites_2_ADDRESS 0x78EEu    /* 04D8EE */
#define knight_5_animations_1_sprites_3_ADDRESS 0x7912u    /* 04D912 */
#define knight_5_animations_1_sprites_4_ADDRESS 0x792Au    /* 04D92A */
#define knight_5_animations_1_sprites_5_ADDRESS 0x7942u    /* 04D942 */
#define knight_5_animations_1_sprites_6_ADDRESS 0x795Au    /* 04D95A */
#define knight_5_animations_1_sprites_7_ADDRESS 0x7972u    /* 04D972 */
#define knight_5_animations_1_sprites_8_ADDRESS 0x7990u    /* 04D990 */
#define knight_5_animations_16_ADDRESS 0x79A8u    /* 04D9A8 */
#define knight_5_animations_16_sprites_ADDRESS 0x79C4u    /* 04D9C4 */
#define knight_5_animations_16_sprites_2_ADDRESS 0x79DCu    /* 04D9DC */
#define knight_5_animations_16_sprites_3_ADDRESS 0x79EEu    /* 04D9EE */
#define knight_5_animations_16_sprites_4_ADDRESS 0x7A06u    /* 04DA06 */
#define knight_5_animations_15_ADDRESS 0x7A1Eu    /* 04DA1E */
#define knight_5_animations_15_sprites_ADDRESS 0x7A3Au    /* 04DA3A */
#define knight_5_animations_15_sprites_2_ADDRESS 0x7A52u    /* 04DA52 */
#define knight_5_animations_15_sprites_3_ADDRESS 0x7A6Au    /* 04DA6A */
#define knight_5_animations_15_sprites_4_ADDRESS 0x7A82u    /* 04DA82 */
#define knight_5_animations_15_sprites_5_ADDRESS 0x7A9Au    /* 04DA9A */
#define knight_5_animations_15_sprites_6_ADDRESS 0x7AB8u    /* 04DAB8 */
#define knight_5_animations_9_ADDRESS 0x7AD0u    /* 04DAD0 */
#define knight_5_animations_9_sprites_ADDRESS 0x7B24u    /* 04DB24 */
#define knight_5_animations_9_sprites_2_ADDRESS 0x7B3Cu    /* 04DB3C */
#define knight_5_animations_9_sprites_3_ADDRESS 0x7B54u    /* 04DB54 */
#define knight_5_animations_9_sprites_4_ADDRESS 0x7B6Cu    /* 04DB6C */
#define knight_5_animations_9_sprites_5_ADDRESS 0x7B84u    /* 04DB84 */
#define knight_5_animations_9_sprites_6_ADDRESS 0x7B9Cu    /* 04DB9C */
#define knight_5_animations_9_sprites_7_ADDRESS 0x7BB4u    /* 04DBB4 */
#define knight_5_animations_9_sprites_8_ADDRESS 0x7BCCu    /* 04DBCC */
#define knight_5_animations_9_sprites_9_ADDRESS 0x7BE4u    /* 04DBE4 */
#define knight_5_animations_6_ADDRESS 0x7BFCu    /* 04DBFC */
#define knight_5_animations_6_sprites_ADDRESS 0x7C20u    /* 04DC20 */
#define knight_5_animations_6_sprites_2_ADDRESS 0x7C38u    /* 04DC38 */
#define knight_5_animations_6_sprites_3_ADDRESS 0x7C50u    /* 04DC50 */
#define knight_5_animations_6_sprites_4_ADDRESS 0x7C74u    /* 04DC74 */
#define knight_5_animations_17_ADDRESS 0x7C98u    /* 04DC98 */
#define knight_5_animations_17_sprites_ADDRESS 0x7CA4u    /* 04DCA4 */
#define knight_5_animations_17_sprites_2_ADDRESS 0x7CAAu    /* 04DCAA */
#define knight_5_animations_17_sprites_2_fill_ADDRESS 0x7CB0u    /* 04DCB0 */
#define knight_5_animations_17_sprites_2_rest_ADDRESS 0x7CCCu    /* 04DCCC */
#define knight_5_animations_17_sprites_2_rest_2_ADDRESS 0x7CD8u    /* 04DCD8 */
#define knight_5_animations_17_sprites_2_rest_3_ADDRESS 0x7CEAu    /* 04DCEA */
#define knight_5_animations_17_sprites_2_rest_4_ADDRESS 0x7CFCu    /* 04DCFC */
#define knight_5_animations_17_sprites_2_rest_5_ADDRESS 0x7D08u    /* 04DD08 */
#define knight_5_animations_17_sprites_2_rest_6_ADDRESS 0x7D14u    /* 04DD14 */
#define knight_5_animations_17_sprites_2_fill_2_ADDRESS 0x7D20u    /* 04DD20 */
#define knight_5_animations_17_sprites_2_rest_7_ADDRESS 0x7D2Au    /* 04DD2A */
#define knight_5_animations_17_sprites_2_rest_8_ADDRESS 0x7D46u    /* 04DD46 */
#define knight_5_animations_17_sprites_2_rest_9_ADDRESS 0x7D52u    /* 04DD52 */
#define knight_5_animations_17_sprites_2_rest_10_ADDRESS 0x7D5Eu    /* 04DD5E */
#define knight_5_animations_17_sprites_2_rest_11_ADDRESS 0x7D6Au    /* 04DD6A */
#define knight_5_animations_17_sprites_2_rest_12_ADDRESS 0x7D76u    /* 04DD76 */
#define knight_5_animations_17_sprites_2_rest_13_ADDRESS 0x7D92u    /* 04DD92 */
#define knight_5_animations_17_sprites_2_rest_14_ADDRESS 0x7DAAu    /* 04DDAA */
#define knight_5_animations_17_sprites_2_rest_15_ADDRESS 0x7DC2u    /* 04DDC2 */
#define knight_5_animations_17_sprites_2_rest_16_ADDRESS 0x7DDAu    /* 04DDDA */
#define knight_5_animations_17_sprites_2_rest_17_ADDRESS 0x7DF2u    /* 04DDF2 */
#define knight_5_animations_17_sprites_2_rest_18_ADDRESS 0x7DFEu    /* 04DDFE */
#define knight_5_animations_17_sprites_2_rest_19_ADDRESS 0x7E16u    /* 04DE16 */
#define knight_5_animations_17_sprites_2_rest_20_ADDRESS 0x7E2Eu    /* 04DE2E */
#define knight_5_animations_17_sprites_2_rest_21_ADDRESS 0x7E3Au    /* 04DE3A */
#define knight_5_animations_17_sprites_2_rest_22_ADDRESS 0x7E46u    /* 04DE46 */
#define knight_5_animations_17_sprites_2_rest_23_ADDRESS 0x7E52u    /* 04DE52 */
#define knight_5_animations_17_sprites_2_rest_24_ADDRESS 0x7E5Eu    /* 04DE5E */
#define knight_5_animations_17_sprites_2_rest_25_ADDRESS 0x7E6Au    /* 04DE6A */
#define knight_5_animations_17_sprites_2_fill_3_ADDRESS 0x7E76u    /* 04DE76 */
#define knight_5_animations_17_sprites_2_rest_26_ADDRESS 0x6000u    /* 04E000 */
#define grim_reaper_animations_ADDRESS 0x600Cu    /* 04E00C */
#define grim_reaper_animations_0_ADDRESS 0x601Eu    /* 04E01E */
#define grim_reaper_animations_0_sprites_ADDRESS 0x6052u    /* 04E052 */
#define grim_reaper_animations_0_sprites_2_ADDRESS 0x607Cu    /* 04E07C */
#define grim_reaper_animations_0_sprites_3_ADDRESS 0x60B8u    /* 04E0B8 */
#define grim_reaper_animations_0_sprites_4_ADDRESS 0x60EEu    /* 04E0EE */
#define grim_reaper_animations_0_sprites_5_ADDRESS 0x6124u    /* 04E124 */
#define grim_reaper_animations_0_sprites_6_ADDRESS 0x614Eu    /* 04E14E */
#define grim_reaper_animations_0_sprites_7_ADDRESS 0x6184u    /* 04E184 */
#define grim_reaper_animations_0_sprites_8_ADDRESS 0x61BAu    /* 04E1BA */
#define grim_reaper_animations_0_sprites_9_ADDRESS 0x61F0u    /* 04E1F0 */
#define grim_reaper_animations_0_sprites_10_ADDRESS 0x6226u    /* 04E226 */
#define grim_reaper_animations_0_sprites_11_ADDRESS 0x625Cu    /* 04E25C */
#define grim_reaper_animations_0_sprites_12_ADDRESS 0x628Cu    /* 04E28C */
#define grim_reaper_animations_1_ADDRESS 0x62C8u    /* 04E2C8 */
#define grim_reaper_animations_1_sprites_ADDRESS 0x62E0u    /* 04E2E0 */
#define grim_reaper_animations_1_sprites_2_ADDRESS 0x6316u    /* 04E316 */
#define grim_reaper_animations_1_sprites_3_ADDRESS 0x634Cu    /* 04E34C */
#define grim_reaper_animations_1_sprites_4_ADDRESS 0x6388u    /* 04E388 */
#define grim_reaper_animations_1_sprites_5_ADDRESS 0x63C4u    /* 04E3C4 */
#define grim_reaper_animations_2_ADDRESS 0x63F4u    /* 04E3F4 */
#define grim_reaper_animations_2_sprites_ADDRESS 0x6444u    /* 04E444 */
#define grim_reaper_animations_2_sprites_2_ADDRESS 0x6456u    /* 04E456 */
#define grim_reaper_animations_2_sprites_3_ADDRESS 0x646Eu    /* 04E46E */
#define grim_reaper_animations_2_sprites_4_ADDRESS 0x6486u    /* 04E486 */
#define grim_reaper_animations_2_sprites_5_ADDRESS 0x649Eu    /* 04E49E */
#define grim_reaper_animations_2_sprites_6_ADDRESS 0x64B6u    /* 04E4B6 */
#define grim_reaper_animations_3_ADDRESS 0x64D4u    /* 04E4D4 */
#define grim_reaper_animations_3_sprites_ADDRESS 0x64F4u    /* 04E4F4 */
#define grim_reaper_animations_3_sprites_2_ADDRESS 0x6506u    /* 04E506 */
#define grim_reaper_animations_3_sprites_3_ADDRESS 0x6524u    /* 04E524 */
#define grim_reaper_animations_3_sprites_4_ADDRESS 0x6542u    /* 04E542 */
#define grim_reaper_animations_3_sprites_5_ADDRESS 0x6560u    /* 04E560 */
#define grim_reaper_animations_3_sprites_6_ADDRESS 0x658Au    /* 04E58A */
#define grim_reaper_animations_3_sprites_7_ADDRESS 0x65B4u    /* 04E5B4 */
#define grim_reaper_animations_4_ADDRESS 0x65DEu    /* 04E5DE */
#define grim_reaper_animations_4_sprites_ADDRESS 0x6606u    /* 04E606 */
#define grim_reaper_animations_4_sprites_2_ADDRESS 0x6618u    /* 04E618 */
#define grim_reaper_animations_4_sprites_3_ADDRESS 0x6636u    /* 04E636 */
#define grim_reaper_animations_4_sprites_4_ADDRESS 0x6660u    /* 04E660 */
#define grim_reaper_animations_4_sprites_5_ADDRESS 0x667Eu    /* 04E67E */
#define grim_reaper_animations_4_sprites_6_ADDRESS 0x669Cu    /* 04E69C */
#define grim_reaper_animations_4_sprites_7_ADDRESS 0x66C0u    /* 04E6C0 */
#define grim_reaper_animations_5_ADDRESS 0x66E4u    /* 04E6E4 */
#define grim_reaper_animations_5_sprites_ADDRESS 0x6700u    /* 04E700 */
#define grim_reaper_animations_5_sprites_2_ADDRESS 0x672Au    /* 04E72A */
#define grim_reaper_animations_5_sprites_3_ADDRESS 0x6754u    /* 04E754 */
#define grim_reaper_animations_5_sprites_4_ADDRESS 0x6784u    /* 04E784 */
#define grim_reaper_animations_5_sprites_5_ADDRESS 0x67A8u    /* 04E7A8 */
#define grim_reaper_animations_5_sprites_6_ADDRESS 0x67D2u    /* 04E7D2 */
#define grim_reaper_animations_6_ADDRESS 0x67FCu    /* 04E7FC */
#define grim_reaper_animations_6_sprites_ADDRESS 0x6804u    /* 04E804 */
#define grim_reaper_animations_7_ADDRESS 0x683Au    /* 04E83A */
#define grim_reaper_animations_7_sprites_ADDRESS 0x684Au    /* 04E84A */
#define grim_reaper_animations_7_sprites_2_ADDRESS 0x689Eu    /* 04E89E */
#define grim_reaper_animations_8_ADDRESS 0x68ECu    /* 04E8EC */
#define grim_reaper_animations_8_sprites_ADDRESS 0x6900u    /* 04E900 */
#define grim_reaper_animations_8_sprites_2_ADDRESS 0x6936u    /* 04E936 */
#define grim_reaper_animations_8_sprites_3_ADDRESS 0x694Eu    /* 04E94E */
#define grim_reaper_animations_8_sprites_4_ADDRESS 0x6966u    /* 04E966 */
#define hit_sparks_animations_ADDRESS 0x699Cu    /* 04E99C */
#define hit_sparks_animations_0_ADDRESS 0x69F4u    /* 04E9F4 */
#define hit_sparks_animations_0_sprites_ADDRESS 0x6A08u    /* 04EA08 */
#define hit_sparks_animations_0_sprites_2_ADDRESS 0x6A0Eu    /* 04EA0E */
#define hit_sparks_animations_0_sprites_3_ADDRESS 0x6A14u    /* 04EA14 */
#define hit_sparks_animations_0_sprites_4_ADDRESS 0x6A1Au    /* 04EA1A */
#define hit_sparks_animations_2_ADDRESS 0x6A20u    /* 04EA20 */
#define hit_sparks_animations_2_sprites_ADDRESS 0x6A28u    /* 04EA28 */
#define hit_sparks_animations_3_ADDRESS 0x6A2Eu    /* 04EA2E */
#define hit_sparks_animations_3_sprites_ADDRESS 0x6A42u    /* 04EA42 */
#define hit_sparks_animations_3_sprites_2_ADDRESS 0x6A48u    /* 04EA48 */
#define hit_sparks_animations_3_sprites_3_ADDRESS 0x6A4Eu    /* 04EA4E */
#define hit_sparks_animations_3_sprites_4_ADDRESS 0x6A54u    /* 04EA54 */
#define hit_sparks_animations_4_ADDRESS 0x6A5Au    /* 04EA5A */
#define hit_sparks_animations_4_sprites_ADDRESS 0x6A62u    /* 04EA62 */
#define hit_sparks_animations_5_ADDRESS 0x6A68u    /* 04EA68 */
#define hit_sparks_animations_5_sprites_ADDRESS 0x6A7Cu    /* 04EA7C */
#define hit_sparks_animations_5_sprites_2_ADDRESS 0x6A82u    /* 04EA82 */
#define hit_sparks_animations_5_sprites_3_ADDRESS 0x6A88u    /* 04EA88 */
#define hit_sparks_animations_5_sprites_4_ADDRESS 0x6A8Eu    /* 04EA8E */
#define hit_sparks_animations_6_ADDRESS 0x6A94u    /* 04EA94 */
#define hit_sparks_animations_6_sprites_ADDRESS 0x6A9Cu    /* 04EA9C */
#define hit_sparks_animations_7_ADDRESS 0x6AA2u    /* 04EAA2 */
#define hit_sparks_animations_7_sprites_ADDRESS 0x6AAEu    /* 04EAAE */
#define hit_sparks_animations_7_sprites_2_ADDRESS 0x6AB4u    /* 04EAB4 */
#define hit_sparks_animations_8_ADDRESS 0x6ABAu    /* 04EABA */
#define hit_sparks_animations_8_sprites_ADDRESS 0x6AC2u    /* 04EAC2 */
#define hit_sparks_animations_9_ADDRESS 0x6AC8u    /* 04EAC8 */
#define hit_sparks_animations_9_sprites_ADDRESS 0x6ADCu    /* 04EADC */
#define hit_sparks_animations_9_sprites_2_ADDRESS 0x6AE2u    /* 04EAE2 */
#define hit_sparks_animations_9_sprites_3_ADDRESS 0x6AE8u    /* 04EAE8 */
#define hit_sparks_animations_9_sprites_4_ADDRESS 0x6AEEu    /* 04EAEE */
#define hit_sparks_animations_10_ADDRESS 0x6AF4u    /* 04EAF4 */
#define hit_sparks_animations_10_sprites_ADDRESS 0x6AFCu    /* 04EAFC */
#define hit_sparks_animations_12_ADDRESS 0x6B02u    /* 04EB02 */
#define hit_sparks_animations_12_sprites_ADDRESS 0x6B0Au    /* 04EB0A */
#define hit_sparks_animations_14_ADDRESS 0x6B10u    /* 04EB10 */
#define hit_sparks_animations_14_sprites_ADDRESS 0x6B18u    /* 04EB18 */
#define hit_sparks_animations_16_ADDRESS 0x6B1Eu    /* 04EB1E */
#define hit_sparks_animations_16_sprites_ADDRESS 0x6B26u    /* 04EB26 */
#define hit_sparks_animations_18_ADDRESS 0x6B2Cu    /* 04EB2C */
#define hit_sparks_animations_18_sprites_ADDRESS 0x6B34u    /* 04EB34 */
#define hit_sparks_animations_20_ADDRESS 0x6B3Au    /* 04EB3A */
#define hit_sparks_animations_20_sprites_ADDRESS 0x6B42u    /* 04EB42 */
#define hit_sparks_animations_22_ADDRESS 0x6B48u    /* 04EB48 */
#define hit_sparks_animations_22_sprites_ADDRESS 0x6B50u    /* 04EB50 */
#define hit_sparks_animations_24_ADDRESS 0x6B56u    /* 04EB56 */
#define hit_sparks_animations_24_sprites_ADDRESS 0x6B66u    /* 04EB66 */
#define hit_sparks_animations_24_sprites_2_ADDRESS 0x6B7Eu    /* 04EB7E */
#define hit_sparks_animations_24_sprites_3_ADDRESS 0x6B96u    /* 04EB96 */
#define hit_sparks_animations_25_ADDRESS 0x6BAEu    /* 04EBAE */
#define hit_sparks_animations_25_sprites_ADDRESS 0x6BC2u    /* 04EBC2 */
#define hit_sparks_animations_25_sprites_2_ADDRESS 0x6BCEu    /* 04EBCE */
#define hit_sparks_animations_25_sprites_3_ADDRESS 0x6BDAu    /* 04EBDA */
#define hit_sparks_animations_25_sprites_4_ADDRESS 0x6BE6u    /* 04EBE6 */
#define hit_sparks_animations_26_ADDRESS 0x6BF2u    /* 04EBF2 */
#define hit_sparks_animations_26_sprites_ADDRESS 0x6BFAu    /* 04EBFA */
#define hit_sparks_animations_27_ADDRESS 0x6C00u    /* 04EC00 */
#define hit_sparks_animations_27_sprites_ADDRESS 0x6C0Cu    /* 04EC0C */
#define hit_sparks_animations_27_sprites_2_ADDRESS 0x6C12u    /* 04EC12 */
#define hit_sparks_animations_28_ADDRESS 0x6C18u    /* 04EC18 */
#define hit_sparks_animations_28_sprites_ADDRESS 0x6C20u    /* 04EC20 */
#define hit_sparks_animations_29_ADDRESS 0x6C26u    /* 04EC26 */
#define hit_sparks_animations_30_ADDRESS 0x6C2Eu    /* 04EC2E */
#define hit_sparks_animations_30_sprites_ADDRESS 0x6C36u    /* 04EC36 */
#define hit_sparks_animations_32_ADDRESS 0x6C3Cu    /* 04EC3C */
#define hit_sparks_animations_32_sprites_ADDRESS 0x6C44u    /* 04EC44 */
#define hit_sparks_animations_33_ADDRESS 0x6C4Au    /* 04EC4A */
#define hit_sparks_animations_33_sprites_ADDRESS 0x6C56u    /* 04EC56 */
#define hit_sparks_animations_33_sprites_2_ADDRESS 0x6C5Cu    /* 04EC5C */
#define hit_sparks_animations_34_ADDRESS 0x6C62u    /* 04EC62 */
#define hit_sparks_animations_34_sprites_ADDRESS 0x6C86u    /* 04EC86 */
#define hit_sparks_animations_34_sprites_2_ADDRESS 0x6C9Eu    /* 04EC9E */
#define hit_sparks_animations_34_sprites_3_ADDRESS 0x6CBCu    /* 04ECBC */
#define hit_sparks_animations_34_sprites_4_ADDRESS 0x6CDAu    /* 04ECDA */
#define hit_sparks_animations_34_sprites_5_ADDRESS 0x6CF8u    /* 04ECF8 */
#define hit_sparks_animations_35_ADDRESS 0x6D16u    /* 04ED16 */
#define hit_sparks_animations_35_sprites_ADDRESS 0x6D2Au    /* 04ED2A */
#define hit_sparks_animations_35_sprites_2_ADDRESS 0x6D36u    /* 04ED36 */
#define hit_sparks_animations_35_sprites_3_ADDRESS 0x6D42u    /* 04ED42 */
#define hit_sparks_animations_35_sprites_4_ADDRESS 0x6D4Eu    /* 04ED4E */
#define hit_sparks_animations_37_ADDRESS 0x6D5Au    /* 04ED5A */
#define hit_sparks_animations_37_sprites_ADDRESS 0x6D6Eu    /* 04ED6E */
#define hit_sparks_animations_37_sprites_2_ADDRESS 0x6D86u    /* 04ED86 */
#define hit_sparks_animations_37_sprites_3_ADDRESS 0x6DA4u    /* 04EDA4 */
#define hit_sparks_animations_36_ADDRESS 0x6DC2u    /* 04EDC2 */
#define hit_sparks_animations_36_sprites_ADDRESS 0x6DD2u    /* 04EDD2 */
#define hit_sparks_animations_36_sprites_2_ADDRESS 0x6DEAu    /* 04EDEA */
#define hit_sparks_animations_36_sprites_3_ADDRESS 0x6E02u    /* 04EE02 */
#define hit_sparks_animations_38_ADDRESS 0x6E20u    /* 04EE20 */
#define hit_sparks_animations_39_ADDRESS 0x6E28u    /* 04EE28 */
#define hit_sparks_animations_39_sprites_ADDRESS 0x6E4Cu    /* 04EE4C */
#define hit_sparks_animations_38_sprites_ADDRESS 0x6E52u    /* 04EE52 */
#define hit_sparks_animations_39_sprites_2_ADDRESS 0x6E58u    /* 04EE58 */
#define hit_sparks_animations_39_sprites_3_ADDRESS 0x6E5Eu    /* 04EE5E */
#define hit_sparks_animations_39_sprites_4_ADDRESS 0x6E64u    /* 04EE64 */
#define hit_sparks_animations_39_sprites_5_ADDRESS 0x6E6Au    /* 04EE6A */
#define hit_sparks_animations_39_sprites_6_ADDRESS 0x6E70u    /* 04EE70 */
#define hit_sparks_animations_39_sprites_7_ADDRESS 0x6E76u    /* 04EE76 */
#define hit_sparks_animations_40_ADDRESS 0x6E7Cu    /* 04EE7C */
#define hit_sparks_animations_41_ADDRESS 0x6E84u    /* 04EE84 */
#define hit_sparks_animations_41_sprites_ADDRESS 0x6E98u    /* 04EE98 */
#define hit_sparks_animations_41_sprites_2_ADDRESS 0x6E9Eu    /* 04EE9E */
#define hit_sparks_animations_40_sprites_ADDRESS 0x6EA4u    /* 04EEA4 */
#define hit_sparks_animations_41_sprites_3_ADDRESS 0x6EAAu    /* 04EEAA */
#define hit_sparks_animations_42_ADDRESS 0x6EB0u    /* 04EEB0 */
#define hit_sparks_animations_42_sprites_ADDRESS 0x6EB8u    /* 04EEB8 */
#define obstacles_animations_ADDRESS 0x6EBEu    /* 04EEBE */
#define obstacles_animations_0_ADDRESS 0x6F2Eu    /* 04EF2E */
#define obstacles_animations_0_sprites_ADDRESS 0x6F4Au    /* 04EF4A */
#define obstacles_animations_0_sprites_2_ADDRESS 0x6F50u    /* 04EF50 */
#define obstacles_animations_0_sprites_3_ADDRESS 0x6F56u    /* 04EF56 */
#define obstacles_animations_2_ADDRESS 0x6F5Cu    /* 04EF5C */
#define obstacles_animations_2_sprites_ADDRESS 0x6F64u    /* 04EF64 */
#define obstacles_animations_3_ADDRESS 0x6F70u    /* 04EF70 */
#define obstacles_animations_3_sprites_ADDRESS 0x6F78u    /* 04EF78 */
#define obstacles_animations_4_ADDRESS 0x6F84u    /* 04EF84 */
#define obstacles_animations_4_sprites_ADDRESS 0x6F8Cu    /* 04EF8C */
#define obstacles_animations_5_ADDRESS 0x6F98u    /* 04EF98 */
#define obstacles_animations_5_sprites_ADDRESS 0x6FA0u    /* 04EFA0 */
#define obstacles_animations_6_ADDRESS 0x6FACu    /* 04EFAC */
#define obstacles_animations_6_sprites_ADDRESS 0x6FB4u    /* 04EFB4 */
#define obstacles_animations_7_ADDRESS 0x6FBAu    /* 04EFBA */
#define obstacles_animations_7_sprites_ADDRESS 0x6FCEu    /* 04EFCE */
#define obstacles_animations_7_sprites_2_ADDRESS 0x6FD4u    /* 04EFD4 */
#define obstacles_animations_7_sprites_3_ADDRESS 0x6FDAu    /* 04EFDA */
#define obstacles_animations_7_sprites_4_ADDRESS 0x6FE0u    /* 04EFE0 */
#define obstacles_animations_8_ADDRESS 0x6FE6u    /* 04EFE6 */
#define obstacles_animations_8_sprites_ADDRESS 0x6FEEu    /* 04EFEE */
#define obstacles_animations_9_ADDRESS 0x6FFAu    /* 04EFFA */
#define obstacles_animations_9_sprites_ADDRESS 0x7002u    /* 04F002 */
#define obstacles_animations_10_ADDRESS 0x700Eu    /* 04F00E */
#define obstacles_animations_10_sprites_ADDRESS 0x7016u    /* 04F016 */
#define obstacles_animations_11_ADDRESS 0x701Cu    /* 04F01C */
#define obstacles_animations_12_ADDRESS 0x7024u    /* 04F024 */
#define obstacles_animations_12_sprites_ADDRESS 0x7038u    /* 04F038 */
#define obstacles_animations_12_sprites_2_ADDRESS 0x703Eu    /* 04F03E */
#define obstacles_animations_12_sprites_3_ADDRESS 0x7044u    /* 04F044 */
#define obstacles_animations_13_ADDRESS 0x704Au    /* 04F04A */
#define obstacles_animations_14_ADDRESS 0x705Eu    /* 04F05E */
#define obstacles_animations_14_sprites_ADDRESS 0x7066u    /* 04F066 */
#define obstacles_animations_15_ADDRESS 0x706Cu    /* 04F06C */
#define obstacles_animations_15_sprites_ADDRESS 0x7074u    /* 04F074 */
#define obstacles_animations_16_ADDRESS 0x707Au    /* 04F07A */
#define obstacles_animations_16_sprites_ADDRESS 0x7082u    /* 04F082 */
#define obstacles_animations_17_ADDRESS 0x7088u    /* 04F088 */
#define obstacles_animations_17_sprites_ADDRESS 0x7090u    /* 04F090 */
#define obstacles_animations_18_ADDRESS 0x7096u    /* 04F096 */
#define obstacles_animations_18_sprites_ADDRESS 0x70A2u    /* 04F0A2 */
#define obstacles_animations_18_sprites_2_ADDRESS 0x70A8u    /* 04F0A8 */
#define obstacles_animations_19_ADDRESS 0x70AEu    /* 04F0AE */
#define obstacles_animations_19_sprites_ADDRESS 0x70BEu    /* 04F0BE */
#define obstacles_animations_19_sprites_2_ADDRESS 0x70CAu    /* 04F0CA */
#define obstacles_animations_19_sprites_3_ADDRESS 0x70D6u    /* 04F0D6 */
#define obstacles_animations_20_ADDRESS 0x70E2u    /* 04F0E2 */
#define obstacles_animations_20_sprites_ADDRESS 0x70F6u    /* 04F0F6 */
#define obstacles_animations_20_sprites_2_ADDRESS 0x70FCu    /* 04F0FC */
#define obstacles_animations_20_sprites_3_ADDRESS 0x7102u    /* 04F102 */
#define obstacles_animations_21_ADDRESS 0x7114u    /* 04F114 */
#define obstacles_animations_21_sprites_ADDRESS 0x7128u    /* 04F128 */
#define obstacles_animations_21_sprites_2_ADDRESS 0x7134u    /* 04F134 */
#define obstacles_animations_21_sprites_3_ADDRESS 0x7140u    /* 04F140 */
#define obstacles_animations_22_ADDRESS 0x7158u    /* 04F158 */
#define obstacles_animations_22_sprites_ADDRESS 0x7160u    /* 04F160 */
#define obstacles_animations_23_ADDRESS 0x7166u    /* 04F166 */
#define obstacles_animations_23_sprites_ADDRESS 0x717Eu    /* 04F17E */
#define obstacles_animations_23_sprites_2_ADDRESS 0x718Au    /* 04F18A */
#define obstacles_animations_23_sprites_3_ADDRESS 0x7196u    /* 04F196 */
#define obstacles_animations_23_sprites_4_ADDRESS 0x71A2u    /* 04F1A2 */
#define obstacles_animations_23_sprites_5_ADDRESS 0x71AEu    /* 04F1AE */
#define obstacles_animations_24_ADDRESS 0x71C0u    /* 04F1C0 */
#define obstacles_animations_25_ADDRESS 0x71C8u    /* 04F1C8 */
#define obstacles_animations_26_ADDRESS 0x71D0u    /* 04F1D0 */
#define obstacles_animations_26_sprites_ADDRESS 0x71D8u    /* 04F1D8 */
#define obstacles_animations_27_ADDRESS 0x71DEu    /* 04F1DE */
#define obstacles_animations_27_sprites_ADDRESS 0x71F6u    /* 04F1F6 */
#define obstacles_animations_27_sprites_2_ADDRESS 0x7202u    /* 04F202 */
#define obstacles_animations_27_sprites_3_ADDRESS 0x720Eu    /* 04F20E */
#define obstacles_animations_27_sprites_4_ADDRESS 0x721Au    /* 04F21A */
#define obstacles_animations_27_sprites_5_ADDRESS 0x7226u    /* 04F226 */
#define obstacles_animations_28_ADDRESS 0x7238u    /* 04F238 */
#define obstacles_animations_29_ADDRESS 0x7240u    /* 04F240 */
#define obstacles_animations_30_ADDRESS 0x7248u    /* 04F248 */
#define obstacles_animations_30_sprites_ADDRESS 0x7250u    /* 04F250 */
#define obstacles_animations_31_ADDRESS 0x7256u    /* 04F256 */
#define obstacles_animations_31_sprites_ADDRESS 0x726Eu    /* 04F26E */
#define obstacles_animations_31_sprites_2_ADDRESS 0x727Au    /* 04F27A */
#define obstacles_animations_31_sprites_3_ADDRESS 0x7286u    /* 04F286 */
#define obstacles_animations_31_sprites_4_ADDRESS 0x7292u    /* 04F292 */
#define obstacles_animations_31_sprites_5_ADDRESS 0x729Eu    /* 04F29E */
#define obstacles_animations_32_ADDRESS 0x72B0u    /* 04F2B0 */
#define obstacles_animations_33_ADDRESS 0x72B8u    /* 04F2B8 */
#define obstacles_animations_34_ADDRESS 0x72C0u    /* 04F2C0 */
#define obstacles_animations_34_sprites_ADDRESS 0x72C8u    /* 04F2C8 */
#define obstacles_animations_35_ADDRESS 0x72CEu    /* 04F2CE */
#define obstacles_animations_35_sprites_ADDRESS 0x72E6u    /* 04F2E6 */
#define obstacles_animations_35_sprites_2_ADDRESS 0x72F2u    /* 04F2F2 */
#define obstacles_animations_35_sprites_3_ADDRESS 0x72FEu    /* 04F2FE */
#define obstacles_animations_35_sprites_4_ADDRESS 0x730Au    /* 04F30A */
#define obstacles_animations_35_sprites_5_ADDRESS 0x7316u    /* 04F316 */
#define obstacles_animations_36_ADDRESS 0x7328u    /* 04F328 */
#define obstacles_animations_37_ADDRESS 0x7330u    /* 04F330 */
#define obstacles_animations_38_ADDRESS 0x7338u    /* 04F338 */
#define obstacles_animations_38_sprites_ADDRESS 0x7340u    /* 04F340 */
#define obstacles_animations_39_ADDRESS 0x7346u    /* 04F346 */
#define obstacles_animations_39_sprites_ADDRESS 0x735Eu    /* 04F35E */
#define obstacles_animations_39_sprites_2_ADDRESS 0x736Au    /* 04F36A */
#define obstacles_animations_39_sprites_3_ADDRESS 0x7376u    /* 04F376 */
#define obstacles_animations_39_sprites_4_ADDRESS 0x7382u    /* 04F382 */
#define obstacles_animations_39_sprites_5_ADDRESS 0x738Eu    /* 04F38E */
#define obstacles_animations_40_ADDRESS 0x73A0u    /* 04F3A0 */
#define obstacles_animations_41_ADDRESS 0x73A8u    /* 04F3A8 */
#define obstacles_animations_42_ADDRESS 0x73B0u    /* 04F3B0 */
#define obstacles_animations_42_sprites_ADDRESS 0x73B8u    /* 04F3B8 */
#define obstacles_animations_43_ADDRESS 0x73BEu    /* 04F3BE */
#define obstacles_animations_43_sprites_ADDRESS 0x73D6u    /* 04F3D6 */
#define obstacles_animations_43_sprites_2_ADDRESS 0x73E2u    /* 04F3E2 */
#define obstacles_animations_43_sprites_3_ADDRESS 0x73EEu    /* 04F3EE */
#define obstacles_animations_43_sprites_4_ADDRESS 0x73FAu    /* 04F3FA */
#define obstacles_animations_43_sprites_5_ADDRESS 0x7406u    /* 04F406 */
#define obstacles_animations_44_ADDRESS 0x7418u    /* 04F418 */
#define obstacles_animations_45_ADDRESS 0x7420u    /* 04F420 */
#define obstacles_animations_46_ADDRESS 0x7428u    /* 04F428 */
#define obstacles_animations_46_sprites_ADDRESS 0x7430u    /* 04F430 */
#define obstacles_animations_47_ADDRESS 0x7436u    /* 04F436 */
#define obstacles_animations_47_sprites_ADDRESS 0x744Eu    /* 04F44E */
#define obstacles_animations_47_sprites_2_ADDRESS 0x745Au    /* 04F45A */
#define obstacles_animations_47_sprites_3_ADDRESS 0x7466u    /* 04F466 */
#define obstacles_animations_47_sprites_4_ADDRESS 0x7472u    /* 04F472 */
#define obstacles_animations_47_sprites_5_ADDRESS 0x747Eu    /* 04F47E */
#define obstacles_animations_48_ADDRESS 0x7490u    /* 04F490 */
#define obstacles_animations_49_ADDRESS 0x7498u    /* 04F498 */
#define obstacles_animations_50_ADDRESS 0x74A0u    /* 04F4A0 */
#define obstacles_animations_50_sprites_ADDRESS 0x74A8u    /* 04F4A8 */
#define obstacles_animations_52_ADDRESS 0x74AEu    /* 04F4AE */
#define obstacles_animations_52_sprites_ADDRESS 0x74B6u    /* 04F4B6 */
#define obstacles_animations_53_ADDRESS 0x74BCu    /* 04F4BC */
#define obstacles_animations_53_sprites_ADDRESS 0x74D0u    /* 04F4D0 */
#define obstacles_animations_53_sprites_2_ADDRESS 0x74D6u    /* 04F4D6 */
#define obstacles_animations_53_sprites_3_ADDRESS 0x74DCu    /* 04F4DC */
#define obstacles_animations_53_sprites_4_ADDRESS 0x74E2u    /* 04F4E2 */
#define obstacles_animations_54_ADDRESS 0x74E8u    /* 04F4E8 */
#define obstacles_animations_55_ADDRESS 0x74F0u    /* 04F4F0 */
#define obstacles_animations_54_sprites_ADDRESS 0x7504u    /* 04F504 */
#define obstacles_animations_55_sprites_ADDRESS 0x7516u    /* 04F516 */
#define obstacles_animations_55_sprites_2_ADDRESS 0x7528u    /* 04F528 */
#define obstacles_animations_55_sprites_3_ADDRESS 0x753Au    /* 04F53A */
#define broom_animations_ADDRESS 0x754Cu    /* 04F54C */
#define broom_animations_0_ADDRESS 0x7550u    /* 04F550 */
#define broom_animations_0_sprites_ADDRESS 0x7558u    /* 04F558 */
#define broom_animations_1_ADDRESS 0x7564u    /* 04F564 */
#define broom_animations_1_sprites_ADDRESS 0x756Cu    /* 04F56C */
#define cloud_devil_animations_ADDRESS 0x758Au    /* 04F58A */
#define cloud_devil_animations_0_ADDRESS 0x759Eu    /* 04F59E */
#define cloud_devil_animations_0_sprites_ADDRESS 0x75B2u    /* 04F5B2 */
#define cloud_devil_animations_0_sprites_2_ADDRESS 0x75CAu    /* 04F5CA */
#define cloud_devil_animations_0_sprites_3_ADDRESS 0x75E2u    /* 04F5E2 */
#define cloud_devil_animations_0_sprites_4_ADDRESS 0x75FAu    /* 04F5FA */
#define cloud_devil_animations_1_ADDRESS 0x7612u    /* 04F612 */
#define cloud_devil_animations_2_ADDRESS 0x7626u    /* 04F626 */
#define cloud_devil_animations_2_sprites_ADDRESS 0x763Au    /* 04F63A */
#define cloud_devil_animations_2_sprites_2_ADDRESS 0x764Cu    /* 04F64C */
#define cloud_devil_animations_2_sprites_3_ADDRESS 0x7664u    /* 04F664 */
#define cloud_devil_animations_3_ADDRESS 0x767Cu    /* 04F67C */
#define cloud_devil_animations_3_sprites_ADDRESS 0x76D0u    /* 04F6D0 */
#define cloud_devil_animations_3_sprites_2_ADDRESS 0x76E8u    /* 04F6E8 */
#define cloud_devil_animations_3_sprites_3_ADDRESS 0x7700u    /* 04F700 */
#define cloud_devil_animations_3_sprites_4_ADDRESS 0x7718u    /* 04F718 */
#define cloud_devil_animations_3_sprites_5_ADDRESS 0x7730u    /* 04F730 */
#define cloud_devil_animations_3_sprites_6_ADDRESS 0x7760u    /* 04F760 */
#define cloud_devil_animations_3_sprites_7_ADDRESS 0x7796u    /* 04F796 */
#define cloud_devil_animations_3_sprites_8_ADDRESS 0x77BAu    /* 04F7BA */
#define cloud_devil_animations_3_sprites_9_ADDRESS 0x77D8u    /* 04F7D8 */
#define cloud_devil_animations_3_sprites_10_ADDRESS 0x77F6u    /* 04F7F6 */
#define cloud_devil_animations_3_sprites_11_ADDRESS 0x7814u    /* 04F814 */
#define cloud_devil_animations_3_sprites_12_ADDRESS 0x7832u    /* 04F832 */
#define cloud_devil_animations_3_sprites_13_ADDRESS 0x7850u    /* 04F850 */
#define cloud_devil_animations_3_sprites_14_ADDRESS 0x786Eu    /* 04F86E */
#define cloud_devil_animations_3_sprites_15_ADDRESS 0x788Cu    /* 04F88C */
#define cloud_devil_animations_3_sprites_16_ADDRESS 0x78AAu    /* 04F8AA */
#define cloud_devil_animations_3_sprites_17_ADDRESS 0x78C8u    /* 04F8C8 */
#define cloud_devil_animations_4_ADDRESS 0x78E6u    /* 04F8E6 */
#define cloud_devil_animations_4_sprites_ADDRESS 0x7906u    /* 04F906 */
#define cloud_devil_animations_4_sprites_2_ADDRESS 0x790Cu    /* 04F90C */
#define cloud_devil_animations_4_sprites_3_ADDRESS 0x7912u    /* 04F912 */
#define cloud_devil_animations_4_sprites_4_ADDRESS 0x7918u    /* 04F918 */
#define cloud_devil_animations_4_sprites_5_ADDRESS 0x7924u    /* 04F924 */
#define cloud_devil_animations_4_sprites_6_ADDRESS 0x792Au    /* 04F92A */
#define cloud_devil_animations_4_sprites_7_ADDRESS 0x7954u    /* 04F954 */
#define cloud_devil_animations_5_ADDRESS 0x797Eu    /* 04F97E */
#define cloud_devil_animations_5_sprites_ADDRESS 0x799Eu    /* 04F99E */
#define cloud_devil_animations_5_sprites_2_ADDRESS 0x79C2u    /* 04F9C2 */
#define cloud_devil_animations_5_sprites_3_ADDRESS 0x79E0u    /* 04F9E0 */
#define cloud_devil_animations_5_sprites_4_ADDRESS 0x79FEu    /* 04F9FE */
#define cloud_devil_animations_5_sprites_5_ADDRESS 0x7A1Cu    /* 04FA1C */
#define cloud_devil_animations_5_sprites_6_ADDRESS 0x7A3Au    /* 04FA3A */
#define cloud_devil_animations_6_ADDRESS 0x7A58u    /* 04FA58 */
#define cloud_devil_animations_6_sprites_ADDRESS 0x7A7Cu    /* 04FA7C */
#define cloud_devil_animations_6_sprites_2_ADDRESS 0x7A8Eu    /* 04FA8E */
#define cloud_devil_animations_6_sprites_3_ADDRESS 0x7AA6u    /* 04FAA6 */
#define cloud_devil_animations_6_sprites_4_ADDRESS 0x7ABEu    /* 04FABE */
#define cloud_devil_animations_6_sprites_5_ADDRESS 0x7AD0u    /* 04FAD0 */
#define cloud_devil_animations_6_sprites_6_ADDRESS 0x7AE2u    /* 04FAE2 */
#define cloud_devil_animations_6_sprites_7_ADDRESS 0x7AFAu    /* 04FAFA */
#define cloud_devil_animations_7_ADDRESS 0x7B12u    /* 04FB12 */
#define cloud_devil_animations_7_sprites_ADDRESS 0x7B26u    /* 04FB26 */
#define cloud_devil_animations_7_sprites_2_ADDRESS 0x7B38u    /* 04FB38 */
#define cloud_devil_animations_7_sprites_3_ADDRESS 0x7B4Au    /* 04FB4A */
#define cloud_devil_animations_8_ADDRESS 0x7B62u    /* 04FB62 */
#define cloud_devil_animations_8_sprites_ADDRESS 0x7B7Eu    /* 04FB7E */
#define cloud_devil_animations_8_sprites_2_ADDRESS 0x7B9Cu    /* 04FB9C */
#define cloud_devil_animations_8_sprites_3_ADDRESS 0x7BBAu    /* 04FBBA */
#define cloud_devil_animations_8_sprites_4_ADDRESS 0x7BC6u    /* 04FBC6 */
#define cloud_devil_animations_8_sprites_5_ADDRESS 0x7BD2u    /* 04FBD2 */
#define cloud_devil_animations_8_sprites_6_ADDRESS 0x7BDEu    /* 04FBDE */
#define cloud_devil_animations_9_ADDRESS 0x7BF0u    /* 04FBF0 */
#define cloud_devil_animations_9_sprites_ADDRESS 0x7C28u    /* 04FC28 */
#define cloud_devil_animations_9_sprites_2_ADDRESS 0x7C2Eu    /* 04FC2E */
#define cloud_devil_animations_9_sprites_3_ADDRESS 0x7C34u    /* 04FC34 */
#define cloud_devil_animations_9_sprites_4_ADDRESS 0x7C40u    /* 04FC40 */
#define cloud_devil_animations_9_sprites_5_ADDRESS 0x7C46u    /* 04FC46 */
#define cloud_devil_animations_9_sprites_6_ADDRESS 0x7C52u    /* 04FC52 */
#define pointing_hand_animations_ADDRESS 0x7C5Eu    /* 04FC5E */
#define pointing_hand_animations_0_ADDRESS 0x7C66u    /* 04FC66 */
#define pointing_hand_animations_0_sprites_ADDRESS 0x7C6Eu    /* 04FC6E */
#define pointing_hand_animations_1_ADDRESS 0x7C7Au    /* 04FC7A */
#define pointing_hand_animations_1_sprites_ADDRESS 0x7C82u    /* 04FC82 */
#define pointing_hand_animations_2_ADDRESS 0x7C8Eu    /* 04FC8E */
#define pointing_hand_animations_2_sprites_ADDRESS 0x7C96u    /* 04FC96 */
#define pointing_hand_animations_3_ADDRESS 0x7CA2u    /* 04FCA2 */
#define pointing_hand_animations_3_sprites_ADDRESS 0x7CAAu    /* 04FCAA */
#define pointing_hand_animations_3_sprites_fill_ADDRESS 0x7CB6u    /* 04FCB6 */
#define pointing_hand_animations_3_sprites_rest_ADDRESS 0x7CCCu    /* 04FCCC */
#define pointing_hand_animations_3_sprites_rest_2_ADDRESS 0x7CD8u    /* 04FCD8 */
#define pointing_hand_animations_3_sprites_rest_3_ADDRESS 0x7CEAu    /* 04FCEA */
#define pointing_hand_animations_3_sprites_rest_4_ADDRESS 0x7CFCu    /* 04FCFC */
#define pointing_hand_animations_3_sprites_rest_5_ADDRESS 0x7D08u    /* 04FD08 */
#define pointing_hand_animations_3_sprites_rest_6_ADDRESS 0x7D14u    /* 04FD14 */
#define pointing_hand_animations_3_sprites_fill_2_ADDRESS 0x7D20u    /* 04FD20 */
#define pointing_hand_animations_3_sprites_rest_7_ADDRESS 0x7D2Au    /* 04FD2A */
#define pointing_hand_animations_3_sprites_rest_8_ADDRESS 0x7D46u    /* 04FD46 */
#define pointing_hand_animations_3_sprites_rest_9_ADDRESS 0x7D52u    /* 04FD52 */
#define pointing_hand_animations_3_sprites_rest_10_ADDRESS 0x7D5Eu    /* 04FD5E */
#define pointing_hand_animations_3_sprites_rest_11_ADDRESS 0x7D6Au    /* 04FD6A */
#define pointing_hand_animations_3_sprites_rest_12_ADDRESS 0x7D76u    /* 04FD76 */
#define pointing_hand_animations_3_sprites_rest_13_ADDRESS 0x7D92u    /* 04FD92 */
#define pointing_hand_animations_3_sprites_rest_14_ADDRESS 0x7DAAu    /* 04FDAA */
#define pointing_hand_animations_3_sprites_rest_15_ADDRESS 0x7DC2u    /* 04FDC2 */
#define pointing_hand_animations_3_sprites_rest_16_ADDRESS 0x7DDAu    /* 04FDDA */
#define pointing_hand_animations_3_sprites_rest_17_ADDRESS 0x7DF2u    /* 04FDF2 */
#define pointing_hand_animations_3_sprites_rest_18_ADDRESS 0x7DFEu    /* 04FDFE */
#define pointing_hand_animations_3_sprites_rest_19_ADDRESS 0x7E16u    /* 04FE16 */
#define pointing_hand_animations_3_sprites_rest_20_ADDRESS 0x7E2Eu    /* 04FE2E */
#define pointing_hand_animations_3_sprites_rest_21_ADDRESS 0x7E3Au    /* 04FE3A */
#define pointing_hand_animations_3_sprites_rest_22_ADDRESS 0x7E46u    /* 04FE46 */
#define pointing_hand_animations_3_sprites_rest_23_ADDRESS 0x7E52u    /* 04FE52 */
#define pointing_hand_animations_3_sprites_rest_24_ADDRESS 0x7E5Eu    /* 04FE5E */
#define pointing_hand_animations_3_sprites_rest_25_ADDRESS 0x7E6Au    /* 04FE6A */
#define pointing_hand_animations_3_sprites_fill_3_ADDRESS 0x7E76u    /* 04FE76 */
#define pointing_hand_animations_3_sprites_rest_26_ADDRESS 0x6000u    /* 050000 */
#define knight_6_animations_ADDRESS 0x600Cu    /* 05000C */
#define knight_6_animations_8_ADDRESS 0x602Eu    /* 05002E */
#define knight_6_animations_8_sprites_ADDRESS 0x605Au    /* 05005A */
#define knight_6_animations_8_sprites_2_ADDRESS 0x6072u    /* 050072 */
#define knight_6_animations_8_sprites_3_ADDRESS 0x6090u    /* 050090 */
#define knight_6_animations_8_sprites_4_ADDRESS 0x60AEu    /* 0500AE */
#define knight_6_animations_8_sprites_5_ADDRESS 0x60CCu    /* 0500CC */
#define knight_6_animations_8_sprites_6_ADDRESS 0x60F0u    /* 0500F0 */
#define knight_6_animations_8_sprites_7_ADDRESS 0x6114u    /* 050114 */
#define knight_6_animations_8_sprites_8_ADDRESS 0x6132u    /* 050132 */
#define knight_6_animations_8_sprites_9_ADDRESS 0x6150u    /* 050150 */
#define knight_6_animations_8_sprites_10_ADDRESS 0x616Eu    /* 05016E */
#define knight_6_animations_0_ADDRESS 0x618Cu    /* 05018C */
#define knight_6_animations_0_sprites_ADDRESS 0x6198u    /* 050198 */
#define knight_6_animations_0_sprites_2_ADDRESS 0x61AAu    /* 0501AA */
#define knight_6_animations_1_ADDRESS 0x61BCu    /* 0501BC */
#define knight_6_animations_1_sprites_ADDRESS 0x61F8u    /* 0501F8 */
#define knight_6_animations_1_sprites_2_ADDRESS 0x6216u    /* 050216 */
#define knight_6_animations_1_sprites_3_ADDRESS 0x6234u    /* 050234 */
#define knight_6_animations_1_sprites_4_ADDRESS 0x624Cu    /* 05024C */
#define knight_6_animations_1_sprites_5_ADDRESS 0x6264u    /* 050264 */
#define knight_6_animations_1_sprites_6_ADDRESS 0x627Cu    /* 05027C */
#define knight_6_animations_1_sprites_7_ADDRESS 0x628Eu    /* 05028E */
#define knight_6_animations_1_sprites_8_ADDRESS 0x62A6u    /* 0502A6 */
#define knight_6_animations_16_ADDRESS 0x62B8u    /* 0502B8 */
#define knight_6_animations_16_sprites_ADDRESS 0x62D4u    /* 0502D4 */
#define knight_6_animations_16_sprites_2_ADDRESS 0x62E6u    /* 0502E6 */
#define knight_6_animations_16_sprites_3_ADDRESS 0x62F8u    /* 0502F8 */
#define knight_6_animations_16_sprites_4_ADDRESS 0x6310u    /* 050310 */
#define knight_6_animations_15_ADDRESS 0x6328u    /* 050328 */
#define knight_6_animations_15_sprites_ADDRESS 0x6344u    /* 050344 */
#define knight_6_animations_15_sprites_2_ADDRESS 0x6356u    /* 050356 */
#define knight_6_animations_15_sprites_3_ADDRESS 0x6368u    /* 050368 */
#define knight_6_animations_15_sprites_4_ADDRESS 0x637Au    /* 05037A */
#define knight_6_animations_15_sprites_5_ADDRESS 0x638Cu    /* 05038C */
#define knight_6_animations_15_sprites_6_ADDRESS 0x639Eu    /* 05039E */
#define knight_6_animations_6_ADDRESS 0x63B0u    /* 0503B0 */
#define knight_6_animations_6_sprites_ADDRESS 0x63D8u    /* 0503D8 */
#define knight_6_animations_6_sprites_2_ADDRESS 0x63F0u    /* 0503F0 */
#define knight_6_animations_6_sprites_3_ADDRESS 0x6402u    /* 050402 */
#define knight_6_animations_6_sprites_4_ADDRESS 0x6420u    /* 050420 */
#define knight_6_animations_6_sprites_5_ADDRESS 0x643Eu    /* 05043E */
#define knight_6_animations_6_sprites_6_ADDRESS 0x645Cu    /* 05045C */
#define knight_6_animations_9_ADDRESS 0x647Au    /* 05047A */
#define knight_6_animations_9_sprites_ADDRESS 0x64CEu    /* 0504CE */
#define knight_6_animations_9_sprites_2_ADDRESS 0x64E0u    /* 0504E0 */
#define knight_6_animations_9_sprites_3_ADDRESS 0x64F2u    /* 0504F2 */
#define knight_6_animations_9_sprites_4_ADDRESS 0x6504u    /* 050504 */
#define knight_6_animations_9_sprites_5_ADDRESS 0x6516u    /* 050516 */
#define knight_6_animations_9_sprites_6_ADDRESS 0x6528u    /* 050528 */
#define knight_6_animations_9_sprites_7_ADDRESS 0x653Au    /* 05053A */
#define knight_6_animations_9_sprites_8_ADDRESS 0x654Cu    /* 05054C */
#define patty_and_selma_animations_ADDRESS 0x655Eu    /* 05055E */
#define patty_and_selma_animations_0_ADDRESS 0x6566u    /* 050566 */
#define patty_and_selma_animations_0_sprites_ADDRESS 0x6572u    /* 050572 */
#define patty_and_selma_animations_0_sprites_2_ADDRESS 0x6584u    /* 050584 */
#define patty_and_selma_animations_1_ADDRESS 0x6596u    /* 050596 */
#define patty_and_selma_animations_1_sprites_ADDRESS 0x65BAu    /* 0505BA */
#define patty_and_selma_animations_1_sprites_2_ADDRESS 0x65CCu    /* 0505CC */
#define patty_and_selma_animations_1_sprites_3_ADDRESS 0x65DEu    /* 0505DE */
#define patty_and_selma_animations_1_sprites_4_ADDRESS 0x65F0u    /* 0505F0 */
#define patty_and_selma_animations_1_sprites_5_ADDRESS 0x6602u    /* 050602 */
#define patty_and_selma_animations_2_ADDRESS 0x6614u    /* 050614 */
#define patty_and_selma_animations_2_sprites_ADDRESS 0x6620u    /* 050620 */
#define patty_and_selma_animations_2_sprites_2_ADDRESS 0x6632u    /* 050632 */
#define patty_and_selma_animations_3_ADDRESS 0x6644u    /* 050644 */
#define patty_and_selma_animations_3_sprites_ADDRESS 0x6668u    /* 050668 */
#define patty_and_selma_animations_3_sprites_2_ADDRESS 0x667Au    /* 05067A */
#define patty_and_selma_animations_3_sprites_3_ADDRESS 0x668Cu    /* 05068C */
#define patty_and_selma_animations_3_sprites_4_ADDRESS 0x669Eu    /* 05069E */
#define patty_and_selma_animations_3_sprites_5_ADDRESS 0x66B0u    /* 0506B0 */
#define grandpa_animations_ADDRESS 0x66C2u    /* 0506C2 */
#define grandpa_animations_0_ADDRESS 0x66C6u    /* 0506C6 */
#define grandpa_animations_0_sprites_ADDRESS 0x66D2u    /* 0506D2 */
#define grandpa_animations_0_sprites_2_ADDRESS 0x66EAu    /* 0506EA */
#define grandpa_animations_1_ADDRESS 0x6702u    /* 050702 */
#define grandpa_animations_1_sprites_ADDRESS 0x6726u    /* 050726 */
#define grandpa_animations_1_sprites_2_ADDRESS 0x673Eu    /* 05073E */
#define grandpa_animations_1_sprites_3_ADDRESS 0x6756u    /* 050756 */
#define grandpa_animations_1_sprites_4_ADDRESS 0x676Eu    /* 05076E */
#define grandpa_animations_1_sprites_5_ADDRESS 0x6786u    /* 050786 */
#define bleeding_gums_murphy_animations_ADDRESS 0x67AAu    /* 0507AA */
#define bleeding_gums_murphy_animations_0_ADDRESS 0x67AEu    /* 0507AE */
#define bleeding_gums_murphy_animations_0_sprites_ADDRESS 0x67C2u    /* 0507C2 */
#define bleeding_gums_murphy_animations_0_sprites_2_ADDRESS 0x67D4u    /* 0507D4 */
#define bleeding_gums_murphy_animations_0_sprites_3_ADDRESS 0x67E6u    /* 0507E6 */
#define bleeding_gums_murphy_animations_1_ADDRESS 0x6804u    /* 050804 */
#define bleeding_gums_murphy_animations_1_sprites_ADDRESS 0x6810u    /* 050810 */
#define burns_robot_3_animations_ADDRESS 0x683Au    /* 05083A */
#define burns_robot_3_animations_0_ADDRESS 0x685Eu    /* 05085E */
#define burns_robot_3_animations_0_sprites_ADDRESS 0x6872u    /* 050872 */
#define burns_robot_3_animations_0_sprites_2_ADDRESS 0x68B4u    /* 0508B4 */
#define burns_robot_3_animations_0_sprites_3_ADDRESS 0x68F6u    /* 0508F6 */
#define burns_robot_3_animations_0_sprites_4_ADDRESS 0x6938u    /* 050938 */
#define burns_robot_3_animations_1_ADDRESS 0x697Au    /* 05097A */
#define burns_robot_3_animations_2_ADDRESS 0x6986u    /* 050986 */
#define burns_robot_3_animations_2_sprites_ADDRESS 0x69A6u    /* 0509A6 */
#define burns_robot_3_animations_2_sprites_2_ADDRESS 0x69EEu    /* 0509EE */
#define burns_robot_3_animations_2_sprites_3_ADDRESS 0x6A30u    /* 050A30 */
#define burns_robot_3_animations_2_sprites_4_ADDRESS 0x6A78u    /* 050A78 */
#define burns_robot_3_animations_2_sprites_5_ADDRESS 0x6AC6u    /* 050AC6 */
#define burns_robot_3_animations_2_sprites_6_ADDRESS 0x6B1Au    /* 050B1A */
#define burns_robot_3_animations_2_sprites_7_ADDRESS 0x6B68u    /* 050B68 */
#define burns_robot_3_animations_3_ADDRESS 0x6BB6u    /* 050BB6 */
#define burns_robot_3_animations_3_sprites_ADDRESS 0x6BCAu    /* 050BCA */
#define burns_robot_3_animations_3_sprites_2_ADDRESS 0x6C18u    /* 050C18 */
#define burns_robot_3_animations_3_sprites_3_ADDRESS 0x6C66u    /* 050C66 */
#define burns_robot_3_animations_4_ADDRESS 0x6CBAu    /* 050CBA */
#define burns_robot_3_animations_4_sprites_ADDRESS 0x6CC6u    /* 050CC6 */
#define burns_robot_3_animations_4_sprites_2_ADDRESS 0x6D0Eu    /* 050D0E */
#define burns_robot_3_animations_5_ADDRESS 0x6D56u    /* 050D56 */
#define burns_robot_3_animations_5_sprites_ADDRESS 0x6D7Au    /* 050D7A */
#define burns_robot_3_animations_5_sprites_2_ADDRESS 0x6DC2u    /* 050DC2 */
#define burns_robot_3_animations_5_sprites_3_ADDRESS 0x6E04u    /* 050E04 */
#define burns_robot_3_animations_5_sprites_4_ADDRESS 0x6E5Eu    /* 050E5E */
#define burns_robot_3_animations_5_sprites_5_ADDRESS 0x6E8Eu    /* 050E8E */
#define burns_robot_3_animations_5_sprites_6_ADDRESS 0x6ECAu    /* 050ECA */
#define burns_robot_3_animations_5_sprites_7_ADDRESS 0x6F06u    /* 050F06 */
#define burns_robot_3_animations_6_ADDRESS 0x6F42u    /* 050F42 */
#define burns_robot_3_animations_6_sprites_ADDRESS 0x6F5Eu    /* 050F5E */
#define burns_robot_3_animations_6_sprites_2_ADDRESS 0x6FB2u    /* 050FB2 */
#define burns_robot_3_animations_6_sprites_3_ADDRESS 0x7006u    /* 051006 */
#define burns_robot_3_animations_6_sprites_4_ADDRESS 0x7060u    /* 051060 */
#define burns_robot_3_animations_6_sprites_5_ADDRESS 0x70BAu    /* 0510BA */
#define burns_robot_3_animations_7_ADDRESS 0x7114u    /* 051114 */
#define burns_robot_3_animations_7_sprites_ADDRESS 0x7150u    /* 051150 */
#define burns_robot_3_animations_7_sprites_2_ADDRESS 0x7192u    /* 051192 */
#define burns_robot_3_animations_7_sprites_3_ADDRESS 0x71DAu    /* 0511DA */
#define burns_robot_3_animations_7_sprites_4_ADDRESS 0x7222u    /* 051222 */
#define burns_robot_3_animations_7_sprites_5_ADDRESS 0x7276u    /* 051276 */
#define burns_robot_3_animations_7_sprites_6_ADDRESS 0x72CAu    /* 0512CA */
#define burns_robot_3_animations_7_sprites_7_ADDRESS 0x732Au    /* 05132A */
#define burns_robot_3_animations_7_sprites_8_ADDRESS 0x738Au    /* 05138A */
#define burns_robot_3_animations_8_ADDRESS 0x73EAu    /* 0513EA */
#define burns_robot_3_animations_8_sprites_ADDRESS 0x73FAu    /* 0513FA */
#define burns_robot_3_animations_8_sprites_2_ADDRESS 0x7400u    /* 051400 */
#define burns_robot_3_animations_8_sprites_3_ADDRESS 0x7406u    /* 051406 */
#define burns_robot_3_animations_9_ADDRESS 0x740Cu    /* 05140C */
#define burns_robot_3_animations_9_sprites_ADDRESS 0x7418u    /* 051418 */
#define burns_robot_3_animations_9_sprites_2_ADDRESS 0x745Au    /* 05145A */
#define burns_robot_3_animations_10_ADDRESS 0x749Cu    /* 05149C */
#define burns_robot_3_animations_10_sprites_ADDRESS 0x74ACu    /* 0514AC */
#define burns_robot_3_animations_10_sprites_2_ADDRESS 0x74F4u    /* 0514F4 */
#define burns_robot_3_animations_11_ADDRESS 0x7536u    /* 051536 */
#define burns_robot_3_animations_11_sprites_ADDRESS 0x7572u    /* 051572 */
#define burns_robot_3_animations_11_sprites_2_ADDRESS 0x75BAu    /* 0515BA */
#define burns_robot_3_animations_11_sprites_3_ADDRESS 0x75FCu    /* 0515FC */
#define burns_robot_3_animations_11_sprites_4_ADDRESS 0x764Au    /* 05164A */
#define burns_robot_3_animations_11_sprites_5_ADDRESS 0x7698u    /* 051698 */
#define burns_robot_3_animations_11_sprites_6_ADDRESS 0x76E6u    /* 0516E6 */
#define burns_robot_3_animations_11_sprites_7_ADDRESS 0x7734u    /* 051734 */
#define burns_robot_3_animations_12_ADDRESS 0x7782u    /* 051782 */
#define burns_robot_3_animations_12_sprites_ADDRESS 0x7796u    /* 051796 */
#define burns_robot_3_animations_12_sprites_2_ADDRESS 0x779Cu    /* 05179C */
#define burns_robot_3_animations_12_sprites_3_ADDRESS 0x77A2u    /* 0517A2 */
#define burns_robot_3_animations_13_ADDRESS 0x77A8u    /* 0517A8 */
#define burns_robot_3_animations_13_sprites_ADDRESS 0x77DCu    /* 0517DC */
#define burns_robot_3_animations_13_sprites_2_ADDRESS 0x780Cu    /* 05180C */
#define burns_robot_3_animations_13_sprites_3_ADDRESS 0x7848u    /* 051848 */
#define burns_robot_3_animations_13_sprites_4_ADDRESS 0x7884u    /* 051884 */
#define burns_robot_3_animations_13_sprites_5_ADDRESS 0x78C0u    /* 0518C0 */
#define burns_robot_3_animations_13_sprites_6_ADDRESS 0x78FCu    /* 0518FC */
#define burns_robot_3_animations_13_sprites_7_ADDRESS 0x7938u    /* 051938 */
#define burns_robot_3_animations_13_sprites_8_ADDRESS 0x7974u    /* 051974 */
#define burns_robot_3_animations_13_sprites_9_ADDRESS 0x79B0u    /* 0519B0 */
#define burns_robot_3_animations_14_ADDRESS 0x79ECu    /* 0519EC */
#define burns_robot_3_animations_14_sprites_ADDRESS 0x7A08u    /* 051A08 */
#define burns_robot_3_animations_14_sprites_2_ADDRESS 0x7A56u    /* 051A56 */
#define burns_robot_3_animations_14_sprites_3_ADDRESS 0x7AAAu    /* 051AAA */
#define burns_robot_3_animations_14_sprites_4_ADDRESS 0x7B0Au    /* 051B0A */
#define burns_robot_3_animations_15_ADDRESS 0x7B5Eu    /* 051B5E */
#define burns_robot_3_animations_15_sprites_ADDRESS 0x7B6Eu    /* 051B6E */
#define burns_robot_3_animations_15_sprites_2_ADDRESS 0x7B80u    /* 051B80 */
#define burns_robot_3_animations_15_sprites_3_ADDRESS 0x7B92u    /* 051B92 */
#define burns_robot_3_animations_16_ADDRESS 0x7BA4u    /* 051BA4 */
#define burns_robot_3_animations_16_sprites_ADDRESS 0x7BB8u    /* 051BB8 */
#define burns_robot_3_animations_16_sprites_2_ADDRESS 0x7BBEu    /* 051BBE */
#define burns_robot_3_animations_16_sprites_3_ADDRESS 0x7BC4u    /* 051BC4 */
#define burns_robot_3_animations_16_sprites_4_ADDRESS 0x7BCAu    /* 051BCA */
#define burns_robot_3_animations_17_ADDRESS 0x7BD0u    /* 051BD0 */
#define burns_robot_3_animations_17_sprites_ADDRESS 0x7BD8u    /* 051BD8 */
#define frog_animations_ADDRESS 0x7BDEu    /* 051BDE */
#define frog_animations_0_ADDRESS 0x7BE6u    /* 051BE6 */
#define frog_animations_0_sprites_ADDRESS 0x7BFAu    /* 051BFA */
#define frog_animations_0_sprites_2_ADDRESS 0x7C00u    /* 051C00 */
#define frog_animations_0_sprites_3_ADDRESS 0x7C0Cu    /* 051C0C */
#define frog_animations_1_ADDRESS 0x7C18u    /* 051C18 */
#define frog_animations_1_sprites_ADDRESS 0x7C38u    /* 051C38 */
#define frog_animations_1_sprites_2_ADDRESS 0x7C3Eu    /* 051C3E */
#define frog_animations_1_sprites_3_ADDRESS 0x7C4Au    /* 051C4A */
#define frog_animations_2_ADDRESS 0x7C50u    /* 051C50 */
#define frog_animations_3_ADDRESS 0x7C5Cu    /* 051C5C */
#define frog_animations_3_sprites_ADDRESS 0x7C64u    /* 051C64 */
#define frog_animations_3_sprites_fill_ADDRESS 0x7C6Au    /* 051C6A */
#define frog_animations_3_sprites_rest_ADDRESS 0x7C6Cu    /* 051C6C */
#define frog_animations_3_sprites_rest_2_ADDRESS 0x7C78u    /* 051C78 */
#define frog_animations_3_sprites_rest_3_ADDRESS 0x7C8Au    /* 051C8A */
#define frog_animations_3_sprites_rest_4_ADDRESS 0x7C9Cu    /* 051C9C */
#define frog_animations_3_sprites_rest_5_ADDRESS 0x7CA8u    /* 051CA8 */
#define frog_animations_3_sprites_rest_6_ADDRESS 0x7CBAu    /* 051CBA */
#define frog_animations_3_sprites_rest_7_ADDRESS 0x7CCCu    /* 051CCC */
#define frog_animations_3_sprites_rest_8_ADDRESS 0x7CD8u    /* 051CD8 */
#define frog_animations_3_sprites_rest_9_ADDRESS 0x7CEAu    /* 051CEA */
#define frog_animations_3_sprites_rest_10_ADDRESS 0x7CFCu    /* 051CFC */
#define frog_animations_3_sprites_rest_11_ADDRESS 0x7D08u    /* 051D08 */
#define frog_animations_3_sprites_rest_12_ADDRESS 0x7D14u    /* 051D14 */
#define frog_animations_3_sprites_fill_2_ADDRESS 0x7D20u    /* 051D20 */
#define frog_animations_3_sprites_rest_13_ADDRESS 0x7D2Au    /* 051D2A */
#define frog_animations_3_sprites_rest_14_ADDRESS 0x7D46u    /* 051D46 */
#define frog_animations_3_sprites_rest_15_ADDRESS 0x7D52u    /* 051D52 */
#define frog_animations_3_sprites_rest_16_ADDRESS 0x7D5Eu    /* 051D5E */
#define frog_animations_3_sprites_rest_17_ADDRESS 0x7D6Au    /* 051D6A */
#define frog_animations_3_sprites_rest_18_ADDRESS 0x7D76u    /* 051D76 */
#define frog_animations_3_sprites_rest_19_ADDRESS 0x7D92u    /* 051D92 */
#define frog_animations_3_sprites_rest_20_ADDRESS 0x7DAAu    /* 051DAA */
#define frog_animations_3_sprites_rest_21_ADDRESS 0x7DC2u    /* 051DC2 */
#define frog_animations_3_sprites_rest_22_ADDRESS 0x7DDAu    /* 051DDA */
#define frog_animations_3_sprites_rest_23_ADDRESS 0x7DF2u    /* 051DF2 */
#define frog_animations_3_sprites_rest_24_ADDRESS 0x7DFEu    /* 051DFE */
#define frog_animations_3_sprites_rest_25_ADDRESS 0x7E16u    /* 051E16 */
#define frog_animations_3_sprites_rest_26_ADDRESS 0x7E2Eu    /* 051E2E */
#define frog_animations_3_sprites_rest_27_ADDRESS 0x7E3Au    /* 051E3A */
#define frog_animations_3_sprites_rest_28_ADDRESS 0x7E46u    /* 051E46 */
#define frog_animations_3_sprites_rest_29_ADDRESS 0x7E52u    /* 051E52 */
#define frog_animations_3_sprites_rest_30_ADDRESS 0x7E5Eu    /* 051E5E */
#define frog_animations_3_sprites_rest_31_ADDRESS 0x7E6Au    /* 051E6A */
#define frog_animations_3_sprites_fill_3_ADDRESS 0x7E76u    /* 051E76 */
#define frog_animations_3_sprites_rest_32_ADDRESS 0x6000u    /* 052000 */
#define burns_robot_animations_2_ADDRESS 0x600Au    /* 05200A */
#define burns_robot_animations_2_0_ADDRESS 0x6032u    /* 052032 */
#define burns_robot_animations_2_0_sprites_ADDRESS 0x604Au    /* 05204A */
#define burns_robot_animations_2_0_sprites_2_ADDRESS 0x6092u    /* 052092 */
#define burns_robot_animations_2_0_sprites_3_ADDRESS 0x60ECu    /* 0520EC */
#define burns_robot_animations_2_1_ADDRESS 0x6146u    /* 052146 */
#define burns_robot_animations_2_1_sprites_ADDRESS 0x616Eu    /* 05216E */
#define burns_robot_animations_2_1_sprites_2_ADDRESS 0x61B6u    /* 0521B6 */
#define burns_robot_animations_2_1_sprites_3_ADDRESS 0x61FEu    /* 0521FE */
#define burns_robot_animations_2_2_ADDRESS 0x6246u    /* 052246 */
#define burns_robot_animations_2_2_sprites_ADDRESS 0x625Au    /* 05225A */
#define burns_robot_animations_2_2_sprites_2_ADDRESS 0x6260u    /* 052260 */
#define burns_robot_animations_2_2_sprites_3_ADDRESS 0x6266u    /* 052266 */
#define burns_robot_animations_2_2_sprites_4_ADDRESS 0x626Cu    /* 05226C */
#define burns_robot_animations_2_3_ADDRESS 0x6272u    /* 052272 */
#define burns_robot_animations_2_3_sprites_ADDRESS 0x6282u    /* 052282 */
#define burns_robot_animations_2_3_sprites_2_ADDRESS 0x62BEu    /* 0522BE */
#define burns_robot_animations_2_3_sprites_3_ADDRESS 0x6300u    /* 052300 */
#define burns_robot_animations_2_4_ADDRESS 0x6342u    /* 052342 */
#define burns_robot_animations_2_4_sprites_ADDRESS 0x6366u    /* 052366 */
#define burns_robot_animations_2_4_sprites_2_ADDRESS 0x63AEu    /* 0523AE */
#define burns_robot_animations_2_4_sprites_3_ADDRESS 0x63F6u    /* 0523F6 */
#define burns_robot_animations_2_4_sprites_4_ADDRESS 0x643Eu    /* 05243E */
#define burns_robot_animations_2_4_sprites_5_ADDRESS 0x648Cu    /* 05248C */
#define burns_robot_animations_2_4_sprites_6_ADDRESS 0x64DAu    /* 0524DA */
#define burns_robot_animations_2_4_sprites_7_ADDRESS 0x651Cu    /* 05251C */
#define burns_robot_animations_2_4_sprites_8_ADDRESS 0x6564u    /* 052564 */
#define burns_robot_animations_2_5_ADDRESS 0x65A6u    /* 0525A6 */
#define burns_robot_animations_2_5_sprites_ADDRESS 0x65C6u    /* 0525C6 */
#define burns_robot_animations_2_5_sprites_2_ADDRESS 0x660Eu    /* 05260E */
#define burns_robot_animations_2_5_sprites_3_ADDRESS 0x6650u    /* 052650 */
#define burns_robot_animations_2_5_sprites_4_ADDRESS 0x66AAu    /* 0526AA */
#define burns_robot_animations_2_5_sprites_5_ADDRESS 0x66FEu    /* 0526FE */
#define burns_robot_animations_2_6_ADDRESS 0x674Cu    /* 05274C */
#define burns_robot_animations_2_6_sprites_ADDRESS 0x6770u    /* 052770 */
#define burns_robot_animations_2_6_sprites_2_ADDRESS 0x67BEu    /* 0527BE */
#define burns_robot_animations_2_6_sprites_3_ADDRESS 0x680Cu    /* 05280C */
#define burns_robot_animations_2_6_sprites_4_ADDRESS 0x685Au    /* 05285A */
#define burns_robot_animations_2_6_sprites_5_ADDRESS 0x68AEu    /* 0528AE */
#define burns_robot_animations_2_7_ADDRESS 0x68F6u    /* 0528F6 */
#define burns_robot_animations_2_7_sprites_ADDRESS 0x690Au    /* 05290A */
#define burns_robot_animations_2_7_sprites_2_ADDRESS 0x6910u    /* 052910 */
#define burns_robot_animations_2_7_sprites_3_ADDRESS 0x6916u    /* 052916 */
#define burns_robot_animations_2_7_sprites_4_ADDRESS 0x691Cu    /* 05291C */
#define burns_robot_animations_2_8_ADDRESS 0x6922u    /* 052922 */
#define burns_robot_animations_2_9_ADDRESS 0x692Au    /* 05292A */
#define burns_robot_animations_2_9_sprites_ADDRESS 0x694Eu    /* 05294E */
#define burns_robot_animations_2_9_sprites_2_ADDRESS 0x695Au    /* 05295A */
#define burns_robot_animations_2_9_sprites_3_ADDRESS 0x6972u    /* 052972 */
#define burns_robot_animations_2_9_sprites_4_ADDRESS 0x6984u    /* 052984 */
#define burns_robot_animations_2_9_sprites_5_ADDRESS 0x69A2u    /* 0529A2 */
#define burns_robot_animations_2_9_sprites_6_ADDRESS 0x69CCu    /* 0529CC */
#define burns_robot_animations_2_9_sprites_7_ADDRESS 0x6A08u    /* 052A08 */
#define burns_robot_animations_2_9_sprites_8_ADDRESS 0x6A3Eu    /* 052A3E */
#define burns_robot_animations_2_10_ADDRESS 0x6A8Cu    /* 052A8C */
#define burns_robot_animations_2_10_sprites_ADDRESS 0x6AB8u    /* 052AB8 */
#define burns_robot_animations_2_10_sprites_2_ADDRESS 0x6B00u    /* 052B00 */
#define burns_robot_animations_2_10_sprites_3_ADDRESS 0x6B48u    /* 052B48 */
#define burns_robot_animations_2_10_sprites_4_ADDRESS 0x6B90u    /* 052B90 */
#define burns_robot_animations_2_10_sprites_5_ADDRESS 0x6BCCu    /* 052BCC */
#define burns_robot_animations_2_10_sprites_6_ADDRESS 0x6C14u    /* 052C14 */
#define burns_robot_animations_2_10_sprites_7_ADDRESS 0x6C5Cu    /* 052C5C */
#define burns_robot_animations_2_10_sprites_8_ADDRESS 0x6C98u    /* 052C98 */
#define burns_robot_animations_2_10_sprites_9_ADDRESS 0x6CD4u    /* 052CD4 */
#define burns_robot_animations_2_11_ADDRESS 0x6D10u    /* 052D10 */
#define burns_robot_animations_2_11_sprites_ADDRESS 0x6D1Cu    /* 052D1C */
#define burns_robot_animations_2_11_sprites_2_ADDRESS 0x6D6Au    /* 052D6A */
#define burns_robot_animations_2_12_ADDRESS 0x6DB8u    /* 052DB8 */
#define burns_robot_animations_2_12_sprites_ADDRESS 0x6DD4u    /* 052DD4 */
#define burns_robot_animations_2_12_sprites_2_ADDRESS 0x6E1Cu    /* 052E1C */
#define burns_robot_animations_2_12_sprites_3_ADDRESS 0x6E64u    /* 052E64 */
#define burns_robot_animations_2_12_sprites_4_ADDRESS 0x6EACu    /* 052EAC */
#define burns_robot_animations_2_12_sprites_5_ADDRESS 0x6EF4u    /* 052EF4 */
#define burns_robot_animations_2_12_sprites_6_ADDRESS 0x6F3Cu    /* 052F3C */
#define burns_robot_animations_2_13_ADDRESS 0x6F84u    /* 052F84 */
#define burns_robot_animations_2_13_sprites_ADDRESS 0x6FB0u    /* 052FB0 */
#define burns_robot_animations_2_13_sprites_2_ADDRESS 0x6FF8u    /* 052FF8 */
#define burns_robot_animations_2_13_sprites_3_ADDRESS 0x7040u    /* 053040 */
#define burns_robot_animations_2_13_sprites_4_ADDRESS 0x7088u    /* 053088 */
#define burns_robot_animations_2_13_sprites_5_ADDRESS 0x70D0u    /* 0530D0 */
#define burns_robot_animations_2_13_sprites_6_ADDRESS 0x7118u    /* 053118 */
#define burns_robot_animations_2_13_sprites_7_ADDRESS 0x7154u    /* 053154 */
#define burns_robot_animations_2_13_sprites_8_ADDRESS 0x719Cu    /* 05319C */
#define burns_robot_animations_2_13_sprites_9_ADDRESS 0x71E4u    /* 0531E4 */
#define burns_robot_animations_2_13_sprites_10_ADDRESS 0x7220u    /* 053220 */
#define burns_robot_animations_2_14_ADDRESS 0x725Cu    /* 05325C */
#define burns_robot_animations_2_14_sprites_ADDRESS 0x7280u    /* 053280 */
#define burns_robot_animations_2_14_sprites_2_ADDRESS 0x72CEu    /* 0532CE */
#define burns_robot_animations_2_14_sprites_3_ADDRESS 0x7316u    /* 053316 */
#define burns_robot_animations_2_14_sprites_4_ADDRESS 0x7370u    /* 053370 */
#define burns_robot_animations_2_15_ADDRESS 0x73CAu    /* 0533CA */
#define burns_robot_animations_2_16_ADDRESS 0x73D6u    /* 0533D6 */
#define burns_robot_animations_2_16_sprites_ADDRESS 0x73EAu    /* 0533EA */
#define burns_robot_animations_2_16_sprites_2_ADDRESS 0x73F0u    /* 0533F0 */
#define burns_robot_animations_2_16_sprites_3_ADDRESS 0x73F6u    /* 0533F6 */
#define burns_robot_animations_2_16_sprites_4_ADDRESS 0x73FCu    /* 0533FC */
#define burns_robot_animations_2_17_ADDRESS 0x7402u    /* 053402 */
#define burns_robot_animations_2_17_sprites_ADDRESS 0x740Au    /* 05340A */
#define burns_robot_animations_2_18_ADDRESS 0x7410u    /* 053410 */
#define burns_robot_animations_2_18_sprites_ADDRESS 0x741Cu    /* 05341C */
#define burns_robot_animations_2_18_sprites_2_ADDRESS 0x746Au    /* 05346A */
#define burns_robot_animations_2_19_ADDRESS 0x74B2u    /* 0534B2 */
#define burns_robot_animations_2_19_sprites_ADDRESS 0x74BEu    /* 0534BE */
#define mr_burns_animations_ADDRESS 0x74CAu    /* 0534CA */
#define mr_burns_animations_0_ADDRESS 0x74D2u    /* 0534D2 */
#define mr_burns_animations_0_sprites_ADDRESS 0x74F6u    /* 0534F6 */
#define mr_burns_animations_0_sprites_2_ADDRESS 0x750Eu    /* 05350E */
#define mr_burns_animations_0_sprites_3_ADDRESS 0x7526u    /* 053526 */
#define mr_burns_animations_0_sprites_4_ADDRESS 0x753Eu    /* 05353E */
#define mr_burns_animations_1_ADDRESS 0x7556u    /* 053556 */
#define mr_burns_animations_1_sprites_ADDRESS 0x7566u    /* 053566 */
#define mr_burns_animations_1_sprites_2_ADDRESS 0x757Eu    /* 05357E */
#define mr_burns_animations_1_sprites_3_ADDRESS 0x759Cu    /* 05359C */
#define mr_burns_animations_2_ADDRESS 0x75AEu    /* 0535AE */
#define mr_burns_animations_2_sprites_ADDRESS 0x75BAu    /* 0535BA */
#define mr_burns_animations_3_ADDRESS 0x75CCu    /* 0535CC */
#define mr_burns_animations_3_sprites_ADDRESS 0x75D4u    /* 0535D4 */
#define channel_6_scenery_animations_ADDRESS 0x75E6u    /* 0535E6 */
#define channel_6_scenery_animations_0_ADDRESS 0x7614u    /* 053614 */
#define channel_6_scenery_animations_0_sprites_ADDRESS 0x7620u    /* 053620 */
#define channel_6_scenery_animations_0_sprites_2_ADDRESS 0x7626u    /* 053626 */
#define channel_6_scenery_animations_1_ADDRESS 0x762Cu    /* 05362C */
#define channel_6_scenery_animations_1_sprites_ADDRESS 0x7634u    /* 053634 */
#define channel_6_scenery_animations_2_ADDRESS 0x7640u    /* 053640 */
#define channel_6_scenery_animations_2_sprites_ADDRESS 0x7654u    /* 053654 */
#define channel_6_scenery_animations_2_sprites_2_ADDRESS 0x7660u    /* 053660 */
#define channel_6_scenery_animations_2_sprites_3_ADDRESS 0x766Cu    /* 05366C */
#define channel_6_scenery_animations_2_sprites_4_ADDRESS 0x7678u    /* 053678 */
#define channel_6_scenery_animations_3_ADDRESS 0x7684u    /* 053684 */
#define channel_6_scenery_animations_3_sprites_ADDRESS 0x7698u    /* 053698 */
#define channel_6_scenery_animations_3_sprites_2_ADDRESS 0x76AAu    /* 0536AA */
#define channel_6_scenery_animations_3_sprites_3_ADDRESS 0x76C8u    /* 0536C8 */
#define channel_6_scenery_animations_3_sprites_4_ADDRESS 0x76E6u    /* 0536E6 */
#define channel_6_scenery_animations_4_ADDRESS 0x76F8u    /* 0536F8 */
#define channel_6_scenery_animations_4_sprites_ADDRESS 0x7708u    /* 053708 */
#define channel_6_scenery_animations_4_sprites_2_ADDRESS 0x7726u    /* 053726 */
#define channel_6_scenery_animations_5_ADDRESS 0x7750u    /* 053750 */
#define channel_6_scenery_animations_5_sprites_ADDRESS 0x7764u    /* 053764 */
#define channel_6_scenery_animations_5_sprites_2_ADDRESS 0x7776u    /* 053776 */
#define channel_6_scenery_animations_6_ADDRESS 0x7794u    /* 053794 */
#define channel_6_scenery_animations_6_sprites_ADDRESS 0x77A4u    /* 0537A4 */
#define channel_6_scenery_animations_7_ADDRESS 0x77CEu    /* 0537CE */
#define channel_6_scenery_animations_8_ADDRESS 0x77D6u    /* 0537D6 */
#define channel_6_scenery_animations_9_ADDRESS 0x77DEu    /* 0537DE */
#define channel_6_scenery_animations_9_sprites_ADDRESS 0x77E6u    /* 0537E6 */
#define channel_6_scenery_animations_10_ADDRESS 0x77F2u    /* 0537F2 */
#define channel_6_scenery_animations_10_sprites_ADDRESS 0x77FEu    /* 0537FE */
#define channel_6_scenery_animations_10_sprites_2_ADDRESS 0x7810u    /* 053810 */
#define channel_6_scenery_animations_11_ADDRESS 0x7822u    /* 053822 */
#define channel_6_scenery_animations_12_ADDRESS 0x782Eu    /* 05382E */
#define channel_6_scenery_animations_12_sprites_ADDRESS 0x7836u    /* 053836 */
#define channel_6_scenery_animations_13_ADDRESS 0x7842u    /* 053842 */
#define channel_6_scenery_animations_13_sprites_ADDRESS 0x784Au    /* 05384A */
#define channel_6_scenery_animations_14_ADDRESS 0x7862u    /* 053862 */
#define channel_6_scenery_animations_14_sprites_ADDRESS 0x786Au    /* 05386A */
#define channel_6_scenery_animations_15_ADDRESS 0x7882u    /* 053882 */
#define channel_6_scenery_animations_16_ADDRESS 0x789Au    /* 05389A */
#define channel_6_scenery_animations_16_sprites_ADDRESS 0x78A2u    /* 0538A2 */
#define channel_6_scenery_animations_17_ADDRESS 0x78B4u    /* 0538B4 */
#define channel_6_scenery_animations_17_sprites_ADDRESS 0x78C0u    /* 0538C0 */
#define channel_6_scenery_animations_18_ADDRESS 0x78D2u    /* 0538D2 */
#define channel_6_scenery_animations_18_sprites_ADDRESS 0x78E2u    /* 0538E2 */
#define channel_6_scenery_animations_18_sprites_2_ADDRESS 0x78E8u    /* 0538E8 */
#define channel_6_scenery_animations_18_sprites_3_ADDRESS 0x78EEu    /* 0538EE */
#define channel_6_scenery_animations_19_ADDRESS 0x78F4u    /* 0538F4 */
#define channel_6_scenery_animations_19_sprites_ADDRESS 0x7908u    /* 053908 */
#define channel_6_scenery_animations_19_sprites_2_ADDRESS 0x7920u    /* 053920 */
#define channel_6_scenery_animations_19_sprites_3_ADDRESS 0x7938u    /* 053938 */
#define channel_6_scenery_animations_19_sprites_4_ADDRESS 0x7950u    /* 053950 */
#define channel_6_scenery_animations_20_ADDRESS 0x797Au    /* 05397A */
#define channel_6_scenery_animations_20_sprites_ADDRESS 0x7986u    /* 053986 */
#define channel_6_scenery_animations_21_ADDRESS 0x79B0u    /* 0539B0 */
#define channel_6_scenery_animations_21_sprites_ADDRESS 0x79BCu    /* 0539BC */
#define channel_6_scenery_animations_21_sprites_2_ADDRESS 0x79E6u    /* 0539E6 */
#define channel_6_scenery_animations_22_ADDRESS 0x7A16u    /* 053A16 */
#define girl_with_food_animations_ADDRESS 0x7A26u    /* 053A26 */
#define girl_with_food_animations_8_ADDRESS 0x7A3Cu    /* 053A3C */
#define girl_with_food_animations_8_sprites_ADDRESS 0x7A58u    /* 053A58 */
#define girl_with_food_animations_8_sprites_2_ADDRESS 0x7A64u    /* 053A64 */
#define girl_with_food_animations_8_sprites_3_ADDRESS 0x7A70u    /* 053A70 */
#define girl_with_food_animations_8_sprites_4_ADDRESS 0x7A7Cu    /* 053A7C */
#define girl_with_food_animations_0_ADDRESS 0x7A88u    /* 053A88 */
#define girl_with_food_animations_0_sprites_ADDRESS 0x7AA4u    /* 053AA4 */
#define girl_with_food_animations_0_sprites_2_ADDRESS 0x7AB6u    /* 053AB6 */
#define girl_with_food_animations_0_sprites_3_ADDRESS 0x7AC8u    /* 053AC8 */
#define girl_with_food_animations_0_sprites_4_ADDRESS 0x7ADAu    /* 053ADA */
#define girl_with_food_animations_2_ADDRESS 0x7AECu    /* 053AEC */
#define girl_with_food_animations_2_sprites_ADDRESS 0x7B08u    /* 053B08 */
#define girl_with_food_animations_2_sprites_2_ADDRESS 0x7B1Au    /* 053B1A */
#define girl_with_food_animations_2_sprites_3_ADDRESS 0x7B2Cu    /* 053B2C */
#define girl_with_food_animations_2_sprites_4_ADDRESS 0x7B3Eu    /* 053B3E */
#define girl_with_food_animations_4_ADDRESS 0x7B50u    /* 053B50 */
#define girl_with_food_animations_4_sprites_ADDRESS 0x7B6Cu    /* 053B6C */
#define girl_with_food_animations_4_sprites_2_ADDRESS 0x7B7Eu    /* 053B7E */
#define girl_with_food_animations_4_sprites_3_ADDRESS 0x7B90u    /* 053B90 */
#define girl_with_food_animations_4_sprites_4_ADDRESS 0x7BA2u    /* 053BA2 */
#define girl_with_food_animations_6_ADDRESS 0x7BB4u    /* 053BB4 */
#define girl_with_food_animations_6_sprites_ADDRESS 0x7BD0u    /* 053BD0 */
#define girl_with_food_animations_6_sprites_2_ADDRESS 0x7BE2u    /* 053BE2 */
#define girl_with_food_animations_6_sprites_3_ADDRESS 0x7BF4u    /* 053BF4 */
#define girl_with_food_animations_6_sprites_4_ADDRESS 0x7C06u    /* 053C06 */
#define girl_with_food_animations_9_ADDRESS 0x7C18u    /* 053C18 */
#define girl_with_food_animations_9_sprites_ADDRESS 0x7C24u    /* 053C24 */
#define girl_with_food_animations_9_sprites_2_ADDRESS 0x7C30u    /* 053C30 */
#define girl_with_food_animations_1_ADDRESS 0x7C3Cu    /* 053C3C */
#define girl_with_food_animations_1_sprites_ADDRESS 0x7C48u    /* 053C48 */
#define girl_with_food_animations_1_sprites_2_ADDRESS 0x7C5Au    /* 053C5A */
#define girl_with_food_animations_3_ADDRESS 0x7C6Cu    /* 053C6C */
#define girl_with_food_animations_3_sprites_ADDRESS 0x7C78u    /* 053C78 */
#define girl_with_food_animations_3_sprites_2_ADDRESS 0x7C8Au    /* 053C8A */
#define girl_with_food_animations_5_ADDRESS 0x7C9Cu    /* 053C9C */
#define girl_with_food_animations_5_sprites_ADDRESS 0x7CA8u    /* 053CA8 */
#define girl_with_food_animations_5_sprites_2_ADDRESS 0x7CBAu    /* 053CBA */
#define girl_with_food_animations_7_ADDRESS 0x7CCCu    /* 053CCC */
#define girl_with_food_animations_7_sprites_ADDRESS 0x7CD8u    /* 053CD8 */
#define girl_with_food_animations_7_sprites_2_ADDRESS 0x7CEAu    /* 053CEA */
#define girl_with_food_animations_10_ADDRESS 0x7CFCu    /* 053CFC */
#define girl_with_food_animations_10_sprites_ADDRESS 0x7D08u    /* 053D08 */
#define girl_with_food_animations_10_sprites_2_ADDRESS 0x7D14u    /* 053D14 */
#define nelson_animations_ADDRESS 0x7D20u    /* 053D20 */
#define nelson_animations_0_ADDRESS 0x7D2Au    /* 053D2A */
#define nelson_animations_0_sprites_ADDRESS 0x7D46u    /* 053D46 */
#define nelson_animations_0_sprites_2_ADDRESS 0x7D52u    /* 053D52 */
#define nelson_animations_0_sprites_3_ADDRESS 0x7D5Eu    /* 053D5E */
#define nelson_animations_0_sprites_4_ADDRESS 0x7D6Au    /* 053D6A */
#define nelson_animations_1_ADDRESS 0x7D76u    /* 053D76 */
#define nelson_animations_1_sprites_ADDRESS 0x7D92u    /* 053D92 */
#define nelson_animations_1_sprites_2_ADDRESS 0x7DAAu    /* 053DAA */
#define nelson_animations_1_sprites_3_ADDRESS 0x7DC2u    /* 053DC2 */
#define nelson_animations_1_sprites_4_ADDRESS 0x7DDAu    /* 053DDA */
#define nelson_animations_2_ADDRESS 0x7DF2u    /* 053DF2 */
#define nelson_animations_2_sprites_ADDRESS 0x7DFEu    /* 053DFE */
#define nelson_animations_2_sprites_2_ADDRESS 0x7E16u    /* 053E16 */
#define nelson_animations_3_ADDRESS 0x7E2Eu    /* 053E2E */
#define nelson_animations_3_sprites_ADDRESS 0x7E3Au    /* 053E3A */
#define nelson_animations_3_sprites_2_ADDRESS 0x7E46u    /* 053E46 */
#define nelson_animations_4_ADDRESS 0x7E52u    /* 053E52 */
#define nelson_animations_4_sprites_ADDRESS 0x7E5Eu    /* 053E5E */
#define nelson_animations_4_sprites_2_ADDRESS 0x7E6Au    /* 053E6A */
#define nelson_animations_4_sprites_2_fill_ADDRESS 0x7E76u    /* 053E76 */
#define nelson_animations_4_sprites_2_rest_ADDRESS 0x6000u    /* 054000 */
#define burns_robot_2_animations_ADDRESS 0x6004u    /* 054004 */
#define burns_robot_2_animations_0_ADDRESS 0x6024u    /* 054024 */
#define burns_robot_2_animations_0_sprites_ADDRESS 0x6034u    /* 054034 */
#define burns_robot_2_animations_0_sprites_2_ADDRESS 0x6076u    /* 054076 */
#define burns_robot_2_animations_0_sprites_3_ADDRESS 0x60B8u    /* 0540B8 */
#define burns_robot_2_animations_1_ADDRESS 0x60FAu    /* 0540FA */
#define burns_robot_2_animations_1_sprites_ADDRESS 0x6106u    /* 054106 */
#define burns_robot_2_animations_1_sprites_2_ADDRESS 0x614Eu    /* 05414E */
#define burns_robot_2_animations_2_ADDRESS 0x6196u    /* 054196 */
#define burns_robot_2_animations_2_sprites_ADDRESS 0x61B2u    /* 0541B2 */
#define burns_robot_2_animations_2_sprites_2_ADDRESS 0x61EEu    /* 0541EE */
#define burns_robot_2_animations_2_sprites_3_ADDRESS 0x6230u    /* 054230 */
#define burns_robot_2_animations_2_sprites_4_ADDRESS 0x6272u    /* 054272 */
#define burns_robot_2_animations_2_sprites_5_ADDRESS 0x62B4u    /* 0542B4 */
#define burns_robot_2_animations_2_sprites_6_ADDRESS 0x62F6u    /* 0542F6 */
#define burns_robot_2_animations_3_ADDRESS 0x6338u    /* 054338 */
#define burns_robot_2_animations_3_sprites_ADDRESS 0x635Cu    /* 05435C */
#define burns_robot_2_animations_3_sprites_2_ADDRESS 0x63B6u    /* 0543B6 */
#define burns_robot_2_animations_3_sprites_3_ADDRESS 0x640Au    /* 05440A */
#define burns_robot_2_animations_3_sprites_4_ADDRESS 0x6464u    /* 054464 */
#define burns_robot_2_animations_3_sprites_5_ADDRESS 0x64B8u    /* 0544B8 */
#define burns_robot_2_animations_3_sprites_6_ADDRESS 0x6512u    /* 054512 */
#define burns_robot_2_animations_3_sprites_7_ADDRESS 0x6566u    /* 054566 */
#define burns_robot_2_animations_4_ADDRESS 0x65BAu    /* 0545BA */
#define burns_robot_2_animations_4_sprites_ADDRESS 0x65CEu    /* 0545CE */
#define burns_robot_2_animations_4_sprites_2_ADDRESS 0x65D4u    /* 0545D4 */
#define burns_robot_2_animations_4_sprites_3_ADDRESS 0x65DAu    /* 0545DA */
#define burns_robot_2_animations_4_sprites_4_ADDRESS 0x65E0u    /* 0545E0 */
#define burns_robot_2_animations_5_ADDRESS 0x65E6u    /* 0545E6 */
#define burns_robot_2_animations_5_sprites_ADDRESS 0x65F2u    /* 0545F2 */
#define burns_robot_2_animations_5_sprites_2_ADDRESS 0x663Au    /* 05463A */
#define burns_robot_2_animations_6_ADDRESS 0x667Cu    /* 05467C */
#define burns_robot_2_animations_6_sprites_ADDRESS 0x66A0u    /* 0546A0 */
#define burns_robot_2_animations_6_sprites_2_ADDRESS 0x66F4u    /* 0546F4 */
#define burns_robot_2_animations_7_ADDRESS 0x6754u    /* 054754 */
#define burns_robot_2_animations_7_sprites_ADDRESS 0x6768u    /* 054768 */
#define burns_robot_2_animations_7_sprites_2_ADDRESS 0x6780u    /* 054780 */
#define burns_robot_2_animations_7_sprites_3_ADDRESS 0x6798u    /* 054798 */
#define burns_robot_2_animations_7_sprites_4_ADDRESS 0x67B0u    /* 0547B0 */
#define burns_robot_2_animations_8_ADDRESS 0x67C8u    /* 0547C8 */
#define burns_robot_2_animations_8_sprites_ADDRESS 0x67E8u    /* 0547E8 */
#define burns_robot_2_animations_8_sprites_2_ADDRESS 0x682Au    /* 05482A */
#define burns_robot_2_animations_8_sprites_3_ADDRESS 0x6866u    /* 054866 */
#define burns_robot_2_animations_8_sprites_4_ADDRESS 0x68BAu    /* 0548BA */
#define burns_robot_2_animations_8_sprites_5_ADDRESS 0x6908u    /* 054908 */
#define burns_robot_2_animations_9_ADDRESS 0x6950u    /* 054950 */
#define burns_robot_2_animations_9_sprites_ADDRESS 0x6974u    /* 054974 */
#define burns_robot_2_animations_9_sprites_2_ADDRESS 0x69BCu    /* 0549BC */
#define burns_robot_2_animations_9_sprites_3_ADDRESS 0x6A04u    /* 054A04 */
#define burns_robot_2_animations_9_sprites_4_ADDRESS 0x6A4Cu    /* 054A4C */
#define burns_robot_2_animations_9_sprites_5_ADDRESS 0x6A9Au    /* 054A9A */
#define burns_robot_2_animations_10_ADDRESS 0x6AD6u    /* 054AD6 */
#define burns_robot_2_animations_10_sprites_ADDRESS 0x6AF6u    /* 054AF6 */
#define burns_robot_2_animations_10_sprites_2_ADDRESS 0x6B38u    /* 054B38 */
#define burns_robot_2_animations_10_sprites_3_ADDRESS 0x6B86u    /* 054B86 */
#define burns_robot_2_animations_10_sprites_4_ADDRESS 0x6BD4u    /* 054BD4 */
#define burns_robot_2_animations_10_sprites_5_ADDRESS 0x6C22u    /* 054C22 */
#define burns_robot_2_animations_11_ADDRESS 0x6C70u    /* 054C70 */
#define burns_robot_2_animations_11_sprites_ADDRESS 0x6C80u    /* 054C80 */
#define burns_robot_2_animations_11_sprites_2_ADDRESS 0x6CCEu    /* 054CCE */
#define burns_robot_2_animations_11_sprites_3_ADDRESS 0x6D1Cu    /* 054D1C */
#define burns_robot_2_animations_12_ADDRESS 0x6D64u    /* 054D64 */
#define burns_robot_2_animations_13_ADDRESS 0x6D74u    /* 054D74 */
#define burns_robot_2_animations_13_sprites_ADDRESS 0x6D80u    /* 054D80 */
#define burns_robot_2_animations_13_sprites_2_ADDRESS 0x6DC2u    /* 054DC2 */
#define burns_robot_2_animations_14_ADDRESS 0x6E04u    /* 054E04 */
#define burns_robot_2_animations_14_sprites_ADDRESS 0x6E20u    /* 054E20 */
#define burns_robot_2_animations_14_sprites_2_ADDRESS 0x6E74u    /* 054E74 */
#define burns_robot_2_animations_14_sprites_3_ADDRESS 0x6ECEu    /* 054ECE */
#define burns_robot_2_animations_14_sprites_4_ADDRESS 0x6F22u    /* 054F22 */
#define burns_robot_2_animations_14_sprites_5_ADDRESS 0x6F7Cu    /* 054F7C */
#define burns_robot_2_animations_14_sprites_6_ADDRESS 0x6FD0u    /* 054FD0 */
#define burns_robot_2_animations_15_ADDRESS 0x7024u    /* 055024 */
#define burns_robot_2_animations_15_sprites_ADDRESS 0x7030u    /* 055030 */
#define burns_robot_2_animations_15_sprites_2_ADDRESS 0x706Cu    /* 05506C */
#define burns_robot_5_animations_ADDRESS 0x70A8u    /* 0550A8 */
#define burns_robot_5_animations_0_ADDRESS 0x70BCu    /* 0550BC */
#define burns_robot_5_animations_0_sprites_ADDRESS 0x70D0u    /* 0550D0 */
#define burns_robot_5_animations_0_sprites_2_ADDRESS 0x710Cu    /* 05510C */
#define burns_robot_5_animations_0_sprites_3_ADDRESS 0x7148u    /* 055148 */
#define burns_robot_5_animations_0_sprites_4_ADDRESS 0x7184u    /* 055184 */
#define burns_robot_5_animations_1_ADDRESS 0x71C0u    /* 0551C0 */
#define burns_robot_5_animations_1_sprites_ADDRESS 0x71D4u    /* 0551D4 */
#define burns_robot_5_animations_1_sprites_2_ADDRESS 0x7210u    /* 055210 */
#define burns_robot_5_animations_1_sprites_3_ADDRESS 0x724Cu    /* 05524C */
#define burns_robot_5_animations_1_sprites_4_ADDRESS 0x7288u    /* 055288 */
#define burns_robot_5_animations_2_ADDRESS 0x72C4u    /* 0552C4 */
#define burns_robot_5_animations_2_sprites_ADDRESS 0x72D0u    /* 0552D0 */
#define burns_robot_5_animations_2_sprites_2_ADDRESS 0x730Cu    /* 05530C */
#define burns_robot_5_animations_3_ADDRESS 0x7348u    /* 055348 */
#define burns_robot_5_animations_3_sprites_ADDRESS 0x7354u    /* 055354 */
#define burns_robot_5_animations_3_sprites_2_ADDRESS 0x7390u    /* 055390 */
#define burns_robot_5_animations_4_ADDRESS 0x73CCu    /* 0553CC */
#define burns_robot_5_animations_4_sprites_ADDRESS 0x73E0u    /* 0553E0 */
#define burns_robot_5_animations_4_sprites_2_ADDRESS 0x741Cu    /* 05541C */
#define burns_robot_5_animations_4_sprites_3_ADDRESS 0x7458u    /* 055458 */
#define burns_robot_5_animations_4_sprites_4_ADDRESS 0x7494u    /* 055494 */
#define burns_robot_5_animations_5_ADDRESS 0x74D0u    /* 0554D0 */
#define burns_robot_5_animations_5_sprites_ADDRESS 0x74ECu    /* 0554EC */
#define burns_robot_5_animations_5_sprites_2_ADDRESS 0x7528u    /* 055528 */
#define burns_robot_5_animations_5_sprites_3_ADDRESS 0x7564u    /* 055564 */
#define burns_robot_5_animations_5_sprites_4_ADDRESS 0x75A0u    /* 0555A0 */
#define burns_robot_5_animations_5_sprites_5_ADDRESS 0x75DCu    /* 0555DC */
#define burns_robot_5_animations_5_sprites_6_ADDRESS 0x7618u    /* 055618 */
#define burns_robot_5_animations_6_ADDRESS 0x764Eu    /* 05564E */
#define burns_robot_5_animations_6_sprites_ADDRESS 0x7662u    /* 055662 */
#define burns_robot_5_animations_6_sprites_2_ADDRESS 0x769Eu    /* 05569E */
#define burns_robot_5_animations_6_sprites_3_ADDRESS 0x76DAu    /* 0556DA */
#define burns_robot_5_animations_7_ADDRESS 0x7716u    /* 055716 */
#define burns_robot_5_animations_7_sprites_ADDRESS 0x773Eu    /* 05573E */
#define burns_robot_5_animations_7_sprites_2_ADDRESS 0x777Au    /* 05577A */
#define burns_robot_5_animations_7_sprites_3_ADDRESS 0x77BCu    /* 0557BC */
#define burns_robot_5_animations_7_sprites_4_ADDRESS 0x780Au    /* 05580A */
#define burns_robot_5_animations_7_sprites_5_ADDRESS 0x7858u    /* 055858 */
#define burns_robot_5_animations_8_ADDRESS 0x78A6u    /* 0558A6 */
#define burns_robot_5_animations_8_sprites_ADDRESS 0x78D6u    /* 0558D6 */
#define burns_robot_5_animations_8_sprites_2_ADDRESS 0x7918u    /* 055918 */
#define burns_robot_5_animations_8_sprites_3_ADDRESS 0x7960u    /* 055960 */
#define burns_robot_5_animations_8_sprites_4_ADDRESS 0x79AEu    /* 0559AE */
#define burns_robot_5_animations_8_sprites_5_ADDRESS 0x7A02u    /* 055A02 */
#define burns_robot_5_animations_8_sprites_6_ADDRESS 0x7A56u    /* 055A56 */
#define burns_robot_5_animations_8_sprites_7_ADDRESS 0x7AA4u    /* 055AA4 */
#define burns_robot_5_animations_8_sprites_8_ADDRESS 0x7AFEu    /* 055AFE */
#define burns_robot_5_animations_8_sprites_9_ADDRESS 0x7B4Cu    /* 055B4C */
#define burns_robot_5_animations_9_ADDRESS 0x7BA0u    /* 055BA0 */
#define burns_robot_5_animations_9_sprites_ADDRESS 0x7BACu    /* 055BAC */
#define burns_robot_5_animations_9_sprites_2_ADDRESS 0x7BE2u    /* 055BE2 */
#define burns_robot_5_animations_9_sprites_2_fill_ADDRESS 0x7C30u    /* 055C30 */
#define burns_robot_5_animations_9_sprites_2_rest_ADDRESS 0x7C36u    /* 055C36 */
#define burns_robot_5_animations_9_sprites_2_rest_2_ADDRESS 0x7C4Au    /* 055C4A */
#define burns_robot_5_animations_9_sprites_2_rest_3_ADDRESS 0x7C52u    /* 055C52 */
#define burns_robot_5_animations_9_sprites_2_rest_4_ADDRESS 0x7C64u    /* 055C64 */
#define burns_robot_5_animations_9_sprites_2_rest_5_ADDRESS 0x7C6Au    /* 055C6A */
#define burns_robot_5_animations_9_sprites_2_rest_6_ADDRESS 0x7C70u    /* 055C70 */
#define burns_robot_5_animations_9_sprites_2_rest_7_ADDRESS 0x7C84u    /* 055C84 */
#define burns_robot_5_animations_9_sprites_2_rest_8_ADDRESS 0x7C8Au    /* 055C8A */
#define burns_robot_5_animations_9_sprites_2_rest_9_ADDRESS 0x7C9Cu    /* 055C9C */
#define burns_robot_5_animations_9_sprites_2_rest_10_ADDRESS 0x7CB4u    /* 055CB4 */
#define burns_robot_5_animations_9_sprites_2_fill_2_ADDRESS 0x7CCCu    /* 055CCC */
#define burns_robot_5_animations_9_sprites_2_rest_11_ADDRESS 0x7CDAu    /* 055CDA */
#define burns_robot_5_animations_9_sprites_2_rest_12_ADDRESS 0x7CE2u    /* 055CE2 */
#define burns_robot_5_animations_9_sprites_2_rest_13_ADDRESS 0x7CFAu    /* 055CFA */
#define burns_robot_5_animations_9_sprites_2_rest_14_ADDRESS 0x7D16u    /* 055D16 */
#define burns_robot_5_animations_9_sprites_2_rest_15_ADDRESS 0x7D1Cu    /* 055D1C */
#define burns_robot_5_animations_9_sprites_2_rest_16_ADDRESS 0x7D28u    /* 055D28 */
#define burns_robot_5_animations_9_sprites_2_rest_17_ADDRESS 0x7D40u    /* 055D40 */
#define burns_robot_5_animations_9_sprites_2_rest_18_ADDRESS 0x7D58u    /* 055D58 */
#define burns_robot_5_animations_9_sprites_2_rest_19_ADDRESS 0x7D6Au    /* 055D6A */
#define burns_robot_5_animations_9_sprites_2_rest_20_ADDRESS 0x7D70u    /* 055D70 */
#define burns_robot_5_animations_9_sprites_2_rest_21_ADDRESS 0x7D78u    /* 055D78 */
#define burns_robot_5_animations_9_sprites_2_rest_22_ADDRESS 0x7D8Cu    /* 055D8C */
#define burns_robot_5_animations_9_sprites_2_rest_23_ADDRESS 0x7D92u    /* 055D92 */
#define burns_robot_5_animations_9_sprites_2_rest_24_ADDRESS 0x7D98u    /* 055D98 */
#define burns_robot_5_animations_9_sprites_2_rest_25_ADDRESS 0x7D9Eu    /* 055D9E */
#define burns_robot_5_animations_9_sprites_2_rest_26_ADDRESS 0x7DA4u    /* 055DA4 */
#define burns_robot_5_animations_9_sprites_2_rest_27_ADDRESS 0x7DB8u    /* 055DB8 */
#define burns_robot_5_animations_9_sprites_2_rest_28_ADDRESS 0x7DCAu    /* 055DCA */
#define burns_robot_5_animations_9_sprites_2_rest_29_ADDRESS 0x7DDCu    /* 055DDC */
#define burns_robot_5_animations_9_sprites_2_rest_30_ADDRESS 0x7DEEu    /* 055DEE */
#define burns_robot_5_animations_9_sprites_2_rest_31_ADDRESS 0x7E00u    /* 055E00 */
#define burns_robot_5_animations_9_sprites_2_rest_32_ADDRESS 0x7E08u    /* 055E08 */
#define burns_robot_5_animations_9_sprites_2_rest_33_ADDRESS 0x7E0Eu    /* 055E0E */
#define burns_robot_5_animations_9_sprites_2_fill_3_ADDRESS 0x7E16u    /* 055E16 */
#define burns_robot_5_animations_9_sprites_2_rest_34_ADDRESS 0x6000u    /* 056000 */
#define burns_robot_4_animations_ADDRESS 0x6008u    /* 056008 */
#define burns_robot_4_animations_0_ADDRESS 0x602Au    /* 05602A */
#define burns_robot_4_animations_0_sprites_ADDRESS 0x603Eu    /* 05603E */
#define burns_robot_4_animations_0_sprites_2_ADDRESS 0x6086u    /* 056086 */
#define burns_robot_4_animations_0_sprites_3_ADDRESS 0x60D4u    /* 0560D4 */
#define burns_robot_4_animations_1_ADDRESS 0x611Cu    /* 05611C */
#define burns_robot_4_animations_1_sprites_ADDRESS 0x6130u    /* 056130 */
#define burns_robot_4_animations_1_sprites_2_ADDRESS 0x6178u    /* 056178 */
#define burns_robot_4_animations_1_sprites_3_ADDRESS 0x61C6u    /* 0561C6 */
#define burns_robot_4_animations_2_ADDRESS 0x620Eu    /* 05620E */
#define burns_robot_4_animations_2_sprites_ADDRESS 0x6242u    /* 056242 */
#define burns_robot_4_animations_2_sprites_2_ADDRESS 0x628Au    /* 05628A */
#define burns_robot_4_animations_2_sprites_3_ADDRESS 0x62D8u    /* 0562D8 */
#define burns_robot_4_animations_2_sprites_4_ADDRESS 0x6320u    /* 056320 */
#define burns_robot_4_animations_2_sprites_5_ADDRESS 0x6362u    /* 056362 */
#define burns_robot_4_animations_2_sprites_6_ADDRESS 0x639Eu    /* 05639E */
#define burns_robot_4_animations_2_sprites_7_ADDRESS 0x63DAu    /* 0563DA */
#define burns_robot_4_animations_3_ADDRESS 0x6416u    /* 056416 */
#define burns_robot_4_animations_3_sprites_ADDRESS 0x6422u    /* 056422 */
#define burns_robot_4_animations_3_sprites_2_ADDRESS 0x646Au    /* 05646A */
#define burns_robot_4_animations_4_ADDRESS 0x64B2u    /* 0564B2 */
#define burns_robot_4_animations_4_sprites_ADDRESS 0x64D6u    /* 0564D6 */
#define burns_robot_4_animations_4_sprites_2_ADDRESS 0x651Eu    /* 05651E */
#define burns_robot_4_animations_4_sprites_3_ADDRESS 0x6566u    /* 056566 */
#define burns_robot_4_animations_4_sprites_4_ADDRESS 0x65B4u    /* 0565B4 */
#define burns_robot_4_animations_4_sprites_5_ADDRESS 0x6602u    /* 056602 */
#define burns_robot_4_animations_4_sprites_6_ADDRESS 0x6656u    /* 056656 */
#define burns_robot_4_animations_4_sprites_7_ADDRESS 0x66B0u    /* 0566B0 */
#define burns_robot_4_animations_4_sprites_8_ADDRESS 0x670Au    /* 05670A */
#define burns_robot_4_animations_5_ADDRESS 0x675Eu    /* 05675E */
#define burns_robot_4_animations_5_sprites_ADDRESS 0x6776u    /* 056776 */
#define burns_robot_4_animations_5_sprites_2_ADDRESS 0x67C4u    /* 0567C4 */
#define burns_robot_4_animations_5_sprites_3_ADDRESS 0x6818u    /* 056818 */
#define burns_robot_4_animations_5_sprites_4_ADDRESS 0x686Cu    /* 05686C */
#define burns_robot_4_animations_6_ADDRESS 0x68C6u    /* 0568C6 */
#define burns_robot_4_animations_6_sprites_ADDRESS 0x6902u    /* 056902 */
#define burns_robot_4_animations_6_sprites_2_ADDRESS 0x6944u    /* 056944 */
#define burns_robot_4_animations_6_sprites_3_ADDRESS 0x6986u    /* 056986 */
#define burns_robot_4_animations_6_sprites_4_ADDRESS 0x69CEu    /* 0569CE */
#define burns_robot_4_animations_6_sprites_5_ADDRESS 0x6A22u    /* 056A22 */
#define burns_robot_4_animations_6_sprites_6_ADDRESS 0x6A76u    /* 056A76 */
#define burns_robot_4_animations_6_sprites_7_ADDRESS 0x6AD6u    /* 056AD6 */
#define burns_robot_4_animations_6_sprites_8_ADDRESS 0x6B36u    /* 056B36 */
#define burns_robot_4_animations_12_sprites_9_ADDRESS 0x6B90u    /* 056B90 */
#define burns_robot_4_animations_12_sprites_10_ADDRESS 0x6BD2u    /* 056BD2 */
#define burns_robot_4_animations_8_ADDRESS 0x6C20u    /* 056C20 */
#define burns_robot_4_animations_8_sprites_ADDRESS 0x6C44u    /* 056C44 */
#define burns_robot_4_animations_8_sprites_2_ADDRESS 0x6C86u    /* 056C86 */
#define burns_robot_4_animations_8_sprites_3_ADDRESS 0x6CC8u    /* 056CC8 */
#define burns_robot_4_animations_8_sprites_4_ADDRESS 0x6D1Cu    /* 056D1C */
#define burns_robot_4_animations_8_sprites_5_ADDRESS 0x6D52u    /* 056D52 */
#define burns_robot_4_animations_8_sprites_6_ADDRESS 0x6D8Eu    /* 056D8E */
#define burns_robot_4_animations_8_sprites_7_ADDRESS 0x6DD0u    /* 056DD0 */
#define burns_robot_4_animations_9_ADDRESS 0x6E0Cu    /* 056E0C */
#define burns_robot_4_animations_9_sprites_ADDRESS 0x6E2Cu    /* 056E2C */
#define burns_robot_4_animations_9_sprites_2_ADDRESS 0x6E86u    /* 056E86 */
#define burns_robot_4_animations_9_sprites_3_ADDRESS 0x6EDAu    /* 056EDA */
#define burns_robot_4_animations_9_sprites_4_ADDRESS 0x6F3Au    /* 056F3A */
#define burns_robot_4_animations_9_sprites_5_ADDRESS 0x6F94u    /* 056F94 */
#define burns_robot_4_animations_10_ADDRESS 0x6FF4u    /* 056FF4 */
#define burns_robot_4_animations_10_sprites_ADDRESS 0x7028u    /* 057028 */
#define burns_robot_4_animations_10_sprites_2_ADDRESS 0x705Eu    /* 05705E */
#define burns_robot_4_animations_10_sprites_3_ADDRESS 0x709Au    /* 05709A */
#define burns_robot_4_animations_10_sprites_4_ADDRESS 0x70DCu    /* 0570DC */
#define burns_robot_4_animations_10_sprites_5_ADDRESS 0x7118u    /* 057118 */
#define burns_robot_4_animations_10_sprites_6_ADDRESS 0x715Au    /* 05715A */
#define burns_robot_4_animations_10_sprites_7_ADDRESS 0x7196u    /* 057196 */
#define burns_robot_4_animations_10_sprites_8_ADDRESS 0x71D8u    /* 0571D8 */
#define burns_robot_4_animations_10_sprites_9_ADDRESS 0x7214u    /* 057214 */
#define burns_robot_4_animations_7_ADDRESS 0x7256u    /* 057256 */
#define burns_robot_4_animations_7_sprites_ADDRESS 0x726Au    /* 05726A */
#define burns_robot_4_animations_7_sprites_2_ADDRESS 0x72B2u    /* 0572B2 */
#define burns_robot_4_animations_7_sprites_3_ADDRESS 0x7300u    /* 057300 */
#define burns_robot_4_animations_12_ADDRESS 0x7348u    /* 057348 */
#define burns_robot_4_animations_12_sprites_ADDRESS 0x7378u    /* 057378 */
#define burns_robot_4_animations_12_sprites_2_ADDRESS 0x73C6u    /* 0573C6 */
#define burns_robot_4_animations_12_sprites_3_ADDRESS 0x7414u    /* 057414 */
#define burns_robot_4_animations_12_sprites_4_ADDRESS 0x7468u    /* 057468 */
#define burns_robot_4_animations_12_sprites_5_ADDRESS 0x74C8u    /* 0574C8 */
#define burns_robot_4_animations_12_sprites_6_ADDRESS 0x7528u    /* 057528 */
#define burns_robot_4_animations_12_sprites_7_ADDRESS 0x7588u    /* 057588 */
#define burns_robot_4_animations_12_sprites_8_ADDRESS 0x75E2u    /* 0575E2 */
#define burns_robot_4_animations_13_ADDRESS 0x761Eu    /* 05761E */
#define burns_robot_4_animations_13_sprites_ADDRESS 0x7642u    /* 057642 */
#define burns_robot_4_animations_13_sprites_2_ADDRESS 0x7648u    /* 057648 */
#define burns_robot_4_animations_13_sprites_3_ADDRESS 0x764Eu    /* 05764E */
#define burns_robot_4_animations_13_sprites_4_ADDRESS 0x7654u    /* 057654 */
#define burns_robot_4_animations_13_sprites_5_ADDRESS 0x765Au    /* 05765A */
#define burns_robot_4_animations_13_sprites_6_ADDRESS 0x7660u    /* 057660 */
#define burns_robot_4_animations_13_sprites_7_ADDRESS 0x7666u    /* 057666 */
#define burns_robot_4_animations_13_sprites_8_ADDRESS 0x766Cu    /* 05766C */
#define burns_robot_4_animations_14_ADDRESS 0x7672u    /* 057672 */
#define burns_robot_4_animations_14_sprites_ADDRESS 0x7696u    /* 057696 */
#define burns_robot_4_animations_14_sprites_2_ADDRESS 0x769Cu    /* 05769C */
#define burns_robot_4_animations_14_sprites_3_ADDRESS 0x76A2u    /* 0576A2 */
#define burns_robot_4_animations_14_sprites_4_ADDRESS 0x76A8u    /* 0576A8 */
#define burns_robot_4_animations_14_sprites_5_ADDRESS 0x76AEu    /* 0576AE */
#define burns_robot_4_animations_14_sprites_6_ADDRESS 0x76B4u    /* 0576B4 */
#define burns_robot_4_animations_14_sprites_7_ADDRESS 0x76BAu    /* 0576BA */
#define burns_robot_4_animations_14_sprites_8_ADDRESS 0x76C0u    /* 0576C0 */
#define burns_robot_4_animations_15_ADDRESS 0x76C6u    /* 0576C6 */
#define burns_robot_4_animations_15_sprites_ADDRESS 0x76EAu    /* 0576EA */
#define burns_robot_4_animations_15_sprites_2_ADDRESS 0x76F6u    /* 0576F6 */
#define burns_robot_4_animations_15_sprites_3_ADDRESS 0x7702u    /* 057702 */
#define burns_robot_4_animations_15_sprites_4_ADDRESS 0x770Eu    /* 05770E */
#define burns_robot_4_animations_15_sprites_5_ADDRESS 0x771Au    /* 05771A */
#define burns_robot_4_animations_15_sprites_6_ADDRESS 0x7726u    /* 057726 */
#define burns_robot_4_animations_15_sprites_7_ADDRESS 0x7732u    /* 057732 */
#define burns_robot_4_animations_15_sprites_8_ADDRESS 0x773Eu    /* 05773E */
#define burns_robot_4_animations_16_ADDRESS 0x774Au    /* 05774A */
#define burns_robot_4_animations_16_sprites_ADDRESS 0x776Eu    /* 05776E */
#define burns_robot_4_animations_16_sprites_2_ADDRESS 0x777Au    /* 05777A */
#define burns_robot_4_animations_16_sprites_3_ADDRESS 0x7786u    /* 057786 */
#define burns_robot_4_animations_16_sprites_4_ADDRESS 0x7792u    /* 057792 */
#define burns_robot_4_animations_16_sprites_5_ADDRESS 0x779Eu    /* 05779E */
#define burns_robot_4_animations_16_sprites_6_ADDRESS 0x77AAu    /* 0577AA */
#define burns_robot_4_animations_16_sprites_7_ADDRESS 0x77B6u    /* 0577B6 */
#define burns_robot_4_animations_16_sprites_8_ADDRESS 0x77C2u    /* 0577C2 */
#define kind_AD_animations_ADDRESS 0x77CEu    /* 0577CE */
#define kind_AD_animations_0_ADDRESS 0x77DCu    /* 0577DC */
#define kind_AD_animations_0_sprites_ADDRESS 0x77E4u    /* 0577E4 */
#define kind_AD_animations_1_ADDRESS 0x77FCu    /* 0577FC */
#define kind_AD_animations_1_sprites_ADDRESS 0x781Cu    /* 05781C */
#define kind_AD_animations_1_sprites_2_ADDRESS 0x7846u    /* 057846 */
#define kind_AD_animations_1_sprites_3_ADDRESS 0x7870u    /* 057870 */
#define kind_AD_animations_1_sprites_4_ADDRESS 0x7894u    /* 057894 */
#define kind_AD_animations_1_sprites_5_ADDRESS 0x78BEu    /* 0578BE */
#define kind_AD_animations_1_sprites_6_ADDRESS 0x78E8u    /* 0578E8 */
#define kind_AD_animations_2_ADDRESS 0x790Cu    /* 05790C */
#define kind_AD_animations_2_sprites_ADDRESS 0x7928u    /* 057928 */
#define kind_AD_animations_2_sprites_2_ADDRESS 0x7958u    /* 057958 */
#define kind_AD_animations_2_sprites_3_ADDRESS 0x7988u    /* 057988 */
#define kind_AD_animations_2_sprites_4_ADDRESS 0x79B8u    /* 0579B8 */
#define kind_AD_animations_2_sprites_5_ADDRESS 0x79E8u    /* 0579E8 */
#define kind_AD_animations_2_sprites_6_ADDRESS 0x7A18u    /* 057A18 */
#define kind_AD_animations_3_ADDRESS 0x7A48u    /* 057A48 */
#define kind_AD_animations_3_sprites_ADDRESS 0x7A78u    /* 057A78 */
#define kind_AD_animations_3_sprites_2_ADDRESS 0x7A9Cu    /* 057A9C */
#define kind_AD_animations_3_sprites_3_ADDRESS 0x7AC0u    /* 057AC0 */
#define kind_AD_animations_3_sprites_4_ADDRESS 0x7AE4u    /* 057AE4 */
#define kind_AD_animations_3_sprites_5_ADDRESS 0x7B08u    /* 057B08 */
#define kind_AD_animations_3_sprites_6_ADDRESS 0x7B26u    /* 057B26 */
#define kind_AD_animations_3_sprites_7_ADDRESS 0x7B3Eu    /* 057B3E */
#define kind_AD_animations_3_sprites_8_ADDRESS 0x7B56u    /* 057B56 */
#define kind_AD_animations_3_sprites_9_ADDRESS 0x7B6Eu    /* 057B6E */
#define kind_AD_animations_3_sprites_10_ADDRESS 0x7B86u    /* 057B86 */
#define kind_AD_animations_3_sprites_11_ADDRESS 0x7B92u    /* 057B92 */
#define kind_AD_animations_4_ADDRESS 0x7B98u    /* 057B98 */
#define kind_AD_animations_4_sprites_ADDRESS 0x7BA4u    /* 057BA4 */
#define kind_AD_animations_5_ADDRESS 0x7BBCu    /* 057BBC */
#define kind_AD_animations_5_sprites_ADDRESS 0x7BC8u    /* 057BC8 */
#define kind_AD_animations_5_sprites_2_ADDRESS 0x7BCEu    /* 057BCE */
#define kind_AD_animations_6_ADDRESS 0x7BD4u    /* 057BD4 */
#define kind_AD_animations_6_sprites_ADDRESS 0x7BE8u    /* 057BE8 */
#define kind_AD_animations_6_sprites_2_ADDRESS 0x7BEEu    /* 057BEE */
#define kind_AD_animations_6_sprites_3_ADDRESS 0x7BF4u    /* 057BF4 */
#define kind_AD_animations_6_sprites_4_ADDRESS 0x7BFAu    /* 057BFA */
#define hurry_up_animations_ADDRESS 0x7C00u    /* 057C00 */
#define hurry_up_animations_0_ADDRESS 0x7C0Au    /* 057C0A */
#define hurry_up_animations_1_ADDRESS 0x7C22u    /* 057C22 */
#define hurry_up_animations_2_ADDRESS 0x7C36u    /* 057C36 */
#define hurry_up_animations_3_ADDRESS 0x7C4Au    /* 057C4A */
#define hurry_up_animations_0_sprites_ADDRESS 0x7C52u    /* 057C52 */
#define hurry_up_animations_3_sprites_ADDRESS 0x7C64u    /* 057C64 */
#define hurry_up_animations_0_sprites_2_ADDRESS 0x7C6Au    /* 057C6A */
#define hurry_up_animations_4_ADDRESS 0x7C70u    /* 057C70 */
#define hurry_up_animations_4_sprites_ADDRESS 0x7C84u    /* 057C84 */
#define hurry_up_animations_4_sprites_2_ADDRESS 0x7C8Au    /* 057C8A */
#define hurry_up_animations_4_sprites_3_ADDRESS 0x7C9Cu    /* 057C9C */
#define hurry_up_animations_4_sprites_4_ADDRESS 0x7CB4u    /* 057CB4 */
#define boulder_animations_ADDRESS 0x7CCCu    /* 057CCC */
#define boulder_animations_0_ADDRESS 0x7CDAu    /* 057CDA */
#define boulder_animations_0_sprites_ADDRESS 0x7CE2u    /* 057CE2 */
#define boulder_animations_1_ADDRESS 0x7CFAu    /* 057CFA */
#define boulder_animations_1_sprites_ADDRESS 0x7D16u    /* 057D16 */
#define boulder_animations_1_sprites_2_ADDRESS 0x7D1Cu    /* 057D1C */
#define boulder_animations_1_sprites_3_ADDRESS 0x7D28u    /* 057D28 */
#define boulder_animations_1_sprites_4_ADDRESS 0x7D40u    /* 057D40 */
#define boulder_animations_1_sprites_5_ADDRESS 0x7D58u    /* 057D58 */
#define boulder_animations_1_sprites_6_ADDRESS 0x7D6Au    /* 057D6A */
#define boulder_animations_2_ADDRESS 0x7D70u    /* 057D70 */
#define boulder_animations_3_ADDRESS 0x7D78u    /* 057D78 */
#define boulder_animations_3_sprites_ADDRESS 0x7D8Cu    /* 057D8C */
#define boulder_animations_3_sprites_2_ADDRESS 0x7D92u    /* 057D92 */
#define boulder_animations_3_sprites_3_ADDRESS 0x7D98u    /* 057D98 */
#define boulder_animations_3_sprites_4_ADDRESS 0x7D9Eu    /* 057D9E */
#define boulder_animations_4_ADDRESS 0x7DA4u    /* 057DA4 */
#define boulder_animations_4_sprites_ADDRESS 0x7DB8u    /* 057DB8 */
#define boulder_animations_4_sprites_2_ADDRESS 0x7DCAu    /* 057DCA */
#define boulder_animations_4_sprites_3_ADDRESS 0x7DDCu    /* 057DDC */
#define boulder_animations_4_sprites_4_ADDRESS 0x7DEEu    /* 057DEE */
#define boulder_animations_5_ADDRESS 0x7E00u    /* 057E00 */
#define boulder_animations_5_sprites_ADDRESS 0x7E08u    /* 057E08 */
#define boulder_animations_6_ADDRESS 0x7E0Eu    /* 057E0E */
#define boulder_animations_6_fill_ADDRESS 0x7E16u    /* 057E16 */
#define block_scenes_a_high_7_0_ADDRESS 0x6000u    /* 058000 */
#define map_scenes_a_3_0_ADDRESS 0x6870u    /* 058870 */
#define map_scenes_a_3_0_0_ADDRESS 0x6874u    /* 058874 */
#define map_scenes_a_3_0_1_ADDRESS 0x68F4u    /* 0588F4 */
#define block_scenes_a_3_0_ADDRESS 0x6974u    /* 058974 */
#define block_scenes_a_3_0_rest_ADDRESS 0x6B6Cu    /* 058B6C */
#define demos_0_demo_inputs_ADDRESS 0x6B7Eu    /* 058B7E */
#define demos_0_demo_inputs_2_ADDRESS 0x6D5Eu    /* 058D5E */
#define demos_1_demo_inputs_ADDRESS 0x6F76u    /* 058F76 */
#define demos_1_demo_inputs_2_ADDRESS 0x7166u    /* 059166 */
#define demos_2_demo_inputs_ADDRESS 0x738Eu    /* 05938E */
#define demos_2_demo_inputs_2_ADDRESS 0x752Eu    /* 05952E */
#define demos_2_demo_inputs_2_fill_ADDRESS 0x7760u    /* 059760 */
#define demos_2_demo_inputs_2_rest_ADDRESS 0x7B1Au    /* 059B1A */
#define demos_2_demo_inputs_2_fill_2_ADDRESS 0x7B2Cu    /* 059B2C */
#define demos_2_demo_inputs_2_rest_2_ADDRESS 0x7B86u    /* 059B86 */
#define demos_2_demo_inputs_2_fill_3_ADDRESS 0x7B98u    /* 059B98 */
#define demos_2_demo_inputs_2_rest_3_ADDRESS 0x7C3Au    /* 059C3A */
#define demos_2_demo_inputs_2_fill_4_ADDRESS 0x7C4Cu    /* 059C4C */
#define demos_2_demo_inputs_2_rest_4_ADDRESS 0x7EE8u    /* 059EE8 */
#define demos_2_demo_inputs_2_rest_5_ADDRESS 0x7EEAu    /* 059EEA */
#define demos_2_demo_inputs_2_fill_5_ADDRESS 0x7F6Au    /* 059F6A */
#define palette_sets_0_1_ADDRESS 0x6000u    /* 05A000 */
#define palette_sets_0_1_rest_ADDRESS 0x6020u    /* 05A020 */
#define palette_sets_0_1_rest_2_ADDRESS 0x6040u    /* 05A040 */
#define palette_sets_0_1_rest_3_ADDRESS 0x6060u    /* 05A060 */
#define palette_sets_high_3_1_ADDRESS 0x6080u    /* 05A080 */
#define palette_sets_high_3_1_rest_ADDRESS 0x60A0u    /* 05A0A0 */
#define palette_sets_high_3_1_rest_2_ADDRESS 0x60C0u    /* 05A0C0 */
#define palette_sets_high_3_1_rest_3_ADDRESS 0x60E0u    /* 05A0E0 */
#define palette_sets_high_5_1_ADDRESS 0x6100u    /* 05A100 */
#define palette_sets_high_5_1_rest_ADDRESS 0x6120u    /* 05A120 */
#define palette_sets_high_5_1_rest_2_ADDRESS 0x6140u    /* 05A140 */
#define palette_sets_high_5_1_rest_3_ADDRESS 0x6160u    /* 05A160 */
#define palette_sets_high_6_1_ADDRESS 0x6180u    /* 05A180 */
#define palette_sets_high_6_1_rest_ADDRESS 0x61A0u    /* 05A1A0 */
#define palette_sets_high_6_1_rest_2_ADDRESS 0x61C0u    /* 05A1C0 */
#define palette_sets_high_6_1_rest_3_ADDRESS 0x61E0u    /* 05A1E0 */
#define palette_sets_high_7_1_ADDRESS 0x6200u    /* 05A200 */
#define palette_sets_high_7_1_rest_ADDRESS 0x6220u    /* 05A220 */
#define palette_sets_high_7_1_rest_2_ADDRESS 0x6240u    /* 05A240 */
#define palette_sets_high_7_1_rest_3_ADDRESS 0x6260u    /* 05A260 */
#define palette_sets_high_8_1_ADDRESS 0x6280u    /* 05A280 */
#define palette_sets_high_8_1_rest_ADDRESS 0x62A0u    /* 05A2A0 */
#define palette_sets_high_8_1_rest_2_ADDRESS 0x62C0u    /* 05A2C0 */
#define palette_sets_high_8_1_rest_3_ADDRESS 0x62E0u    /* 05A2E0 */
#define palette_sets_high_11_1_ADDRESS 0x6300u    /* 05A300 */
#define palette_sets_high_11_1_rest_ADDRESS 0x6320u    /* 05A320 */
#define palette_sets_high_11_1_rest_2_ADDRESS 0x6340u    /* 05A340 */
#define palette_sets_high_11_1_rest_3_ADDRESS 0x6360u    /* 05A360 */
#define palette_sets_high_13_1_ADDRESS 0x6380u    /* 05A380 */
#define palette_sets_high_13_1_rest_ADDRESS 0x63A0u    /* 05A3A0 */
#define palette_sets_high_13_1_rest_2_ADDRESS 0x63C0u    /* 05A3C0 */
#define palette_sets_high_13_1_rest_3_ADDRESS 0x63E0u    /* 05A3E0 */
#define palette_sets_high_14_1_ADDRESS 0x6400u    /* 05A400 */
#define palette_sets_high_14_1_rest_ADDRESS 0x6420u    /* 05A420 */
#define palette_sets_high_14_1_rest_2_ADDRESS 0x6440u    /* 05A440 */
#define palette_sets_high_14_1_rest_3_ADDRESS 0x6460u    /* 05A460 */
#define palette_sets_1_1_ADDRESS 0x6480u    /* 05A480 */
#define palette_sets_1_1_rest_ADDRESS 0x64A0u    /* 05A4A0 */
#define palette_sets_1_1_rest_2_ADDRESS 0x64C0u    /* 05A4C0 */
#define palette_sets_8_1_ADDRESS 0x64E0u    /* 05A4E0 */
#define palette_sets_9_1_ADDRESS 0x6500u    /* 05A500 */
#define palette_sets_10_1_ADDRESS 0x6520u    /* 05A520 */
#define palette_sets_11_1_ADDRESS 0x6540u    /* 05A540 */
#define palette_sets_12_1_ADDRESS 0x6560u    /* 05A560 */
#define palette_sets_12_1_rest_ADDRESS 0x6580u    /* 05A580 */
#define palette_sets_12_1_rest_2_ADDRESS 0x65A0u    /* 05A5A0 */
#define palette_sets_12_1_rest_3_ADDRESS 0x65C0u    /* 05A5C0 */
#define palette_sets_13_1_ADDRESS 0x65E0u    /* 05A5E0 */
#define palette_sets_13_1_rest_ADDRESS 0x6600u    /* 05A600 */
#define palette_sets_13_1_rest_2_ADDRESS 0x6620u    /* 05A620 */
#define palette_sets_13_1_rest_3_ADDRESS 0x6640u    /* 05A640 */
#define palette_sets_2_1_ADDRESS 0x6660u    /* 05A660 */
#define palette_sets_2_1_rest_ADDRESS 0x6680u    /* 05A680 */
#define palette_sets_2_1_rest_2_ADDRESS 0x66A0u    /* 05A6A0 */
#define palette_sets_2_1_rest_3_ADDRESS 0x66C0u    /* 05A6C0 */
#define palette_sets_3_1_ADDRESS 0x66E0u    /* 05A6E0 */
#define palette_sets_3_1_rest_ADDRESS 0x6700u    /* 05A700 */
#define palette_sets_3_1_rest_2_ADDRESS 0x6720u    /* 05A720 */
#define palette_sets_3_1_rest_3_ADDRESS 0x6740u    /* 05A740 */
#define palette_sets_4_1_ADDRESS 0x6760u    /* 05A760 */
#define palette_sets_4_1_rest_ADDRESS 0x6780u    /* 05A780 */
#define palette_sets_4_1_rest_2_ADDRESS 0x67A0u    /* 05A7A0 */
#define palette_sets_4_1_rest_3_ADDRESS 0x67C0u    /* 05A7C0 */
#define palette_sets_high_9_1_ADDRESS 0x67E0u    /* 05A7E0 */
#define palette_sets_high_9_1_rest_ADDRESS 0x6800u    /* 05A800 */
#define palette_sets_high_9_1_rest_2_ADDRESS 0x6820u    /* 05A820 */
#define palette_sets_high_16_1_ADDRESS 0x6840u    /* 05A840 */
#define palette_sets_0_2_ADDRESS 0x6860u    /* 05A860 */
#define palette_sets_0_2_rest_ADDRESS 0x6880u    /* 05A880 */
#define palette_sets_0_2_rest_2_ADDRESS 0x68A0u    /* 05A8A0 */
#define palette_sets_0_2_rest_3_ADDRESS 0x68C0u    /* 05A8C0 */
#define palette_sets_high_3_2_ADDRESS 0x68E0u    /* 05A8E0 */
#define palette_sets_high_3_2_rest_ADDRESS 0x6900u    /* 05A900 */
#define palette_sets_high_3_2_rest_2_ADDRESS 0x6920u    /* 05A920 */
#define palette_sets_high_3_2_rest_3_ADDRESS 0x6940u    /* 05A940 */
#define palette_sets_high_5_2_ADDRESS 0x6960u    /* 05A960 */
#define palette_sets_high_5_2_rest_ADDRESS 0x6980u    /* 05A980 */
#define palette_sets_high_5_2_rest_2_ADDRESS 0x69A0u    /* 05A9A0 */
#define palette_sets_high_5_2_rest_3_ADDRESS 0x69C0u    /* 05A9C0 */
#define palette_sets_high_6_2_ADDRESS 0x69E0u    /* 05A9E0 */
#define palette_sets_high_6_2_rest_ADDRESS 0x6A00u    /* 05AA00 */
#define palette_sets_high_6_2_rest_2_ADDRESS 0x6A20u    /* 05AA20 */
#define palette_sets_high_6_2_rest_3_ADDRESS 0x6A40u    /* 05AA40 */
#define palette_sets_high_7_2_ADDRESS 0x6A60u    /* 05AA60 */
#define palette_sets_high_7_2_rest_ADDRESS 0x6A80u    /* 05AA80 */
#define palette_sets_high_7_2_rest_2_ADDRESS 0x6AA0u    /* 05AAA0 */
#define palette_sets_high_7_2_rest_3_ADDRESS 0x6AC0u    /* 05AAC0 */
#define palette_sets_high_8_2_ADDRESS 0x6AE0u    /* 05AAE0 */
#define palette_sets_high_8_2_rest_ADDRESS 0x6B00u    /* 05AB00 */
#define palette_sets_high_8_2_rest_2_ADDRESS 0x6B20u    /* 05AB20 */
#define palette_sets_high_8_2_rest_3_ADDRESS 0x6B40u    /* 05AB40 */
#define palette_sets_high_11_2_ADDRESS 0x6B60u    /* 05AB60 */
#define palette_sets_high_11_2_rest_ADDRESS 0x6B80u    /* 05AB80 */
#define palette_sets_high_11_2_rest_2_ADDRESS 0x6BA0u    /* 05ABA0 */
#define palette_sets_high_11_2_rest_3_ADDRESS 0x6BC0u    /* 05ABC0 */
#define palette_sets_high_13_2_ADDRESS 0x6BE0u    /* 05ABE0 */
#define palette_sets_high_13_2_rest_ADDRESS 0x6C00u    /* 05AC00 */
#define palette_sets_high_13_2_rest_2_ADDRESS 0x6C20u    /* 05AC20 */
#define palette_sets_high_13_2_rest_3_ADDRESS 0x6C40u    /* 05AC40 */
#define palette_sets_high_14_2_ADDRESS 0x6C60u    /* 05AC60 */
#define palette_sets_high_14_2_rest_ADDRESS 0x6C80u    /* 05AC80 */
#define palette_sets_high_14_2_rest_2_ADDRESS 0x6CA0u    /* 05ACA0 */
#define palette_sets_high_14_2_rest_3_ADDRESS 0x6CC0u    /* 05ACC0 */
#define palette_sets_1_2_ADDRESS 0x6CE0u    /* 05ACE0 */
#define palette_sets_1_2_rest_ADDRESS 0x6D00u    /* 05AD00 */
#define palette_sets_1_2_rest_2_ADDRESS 0x6D20u    /* 05AD20 */
#define palette_sets_1_2_rest_3_ADDRESS 0x6D40u    /* 05AD40 */
#define palette_sets_12_2_ADDRESS 0x6D60u    /* 05AD60 */
#define palette_sets_high_17_2_ADDRESS 0x6D80u    /* 05AD80 */
#define palette_sets_2_2_ADDRESS 0x6DA0u    /* 05ADA0 */
#define palette_sets_2_2_rest_ADDRESS 0x6DC0u    /* 05ADC0 */
#define palette_sets_2_2_rest_2_ADDRESS 0x6DE0u    /* 05ADE0 */
#define palette_sets_2_2_rest_3_ADDRESS 0x6E00u    /* 05AE00 */
#define palette_sets_5_2_ADDRESS 0x6E20u    /* 05AE20 */
#define palette_sets_5_2_rest_ADDRESS 0x6E40u    /* 05AE40 */
#define palette_sets_high_9_2_ADDRESS 0x6E60u    /* 05AE60 */
#define palette_sets_high_9_2_rest_ADDRESS 0x6E80u    /* 05AE80 */
#define palette_sets_high_12_2_ADDRESS 0x6EA0u    /* 05AEA0 */
#define palette_sets_high_12_2_rest_ADDRESS 0x6EC0u    /* 05AEC0 */
#define palette_sets_high_16_2_ADDRESS 0x6EE0u    /* 05AEE0 */
#define palette_sets_0_0_ADDRESS 0x6F00u    /* 05AF00 */
#define palette_sets_0_0_rest_ADDRESS 0x6F20u    /* 05AF20 */
#define palette_sets_0_0_rest_2_ADDRESS 0x6F40u    /* 05AF40 */
#define palette_sets_0_0_rest_3_ADDRESS 0x6F60u    /* 05AF60 */
#define palette_sets_high_16_0_ADDRESS 0x6F80u    /* 05AF80 */
#define palette_sets_high_16_0_rest_ADDRESS 0x6FA0u    /* 05AFA0 */
#define palette_sets_high_16_0_rest_2_ADDRESS 0x6FC0u    /* 05AFC0 */
#define palette_sets_high_16_0_rest_3_ADDRESS 0x6FE0u    /* 05AFE0 */
#define palette_sets_1_0_ADDRESS 0x7000u    /* 05B000 */
#define palette_sets_1_0_rest_ADDRESS 0x7020u    /* 05B020 */
#define palette_sets_1_0_rest_2_ADDRESS 0x7040u    /* 05B040 */
#define palette_sets_1_0_rest_3_ADDRESS 0x7060u    /* 05B060 */
#define palette_sets_high_2_0_ADDRESS 0x7080u    /* 05B080 */
#define palette_sets_high_2_0_rest_ADDRESS 0x70A0u    /* 05B0A0 */
#define palette_sets_high_2_0_rest_2_ADDRESS 0x70C0u    /* 05B0C0 */
#define palette_sets_6_0_ADDRESS 0x7180u    /* 05B180 */
#define palette_sets_6_0_rest_ADDRESS 0x71A0u    /* 05B1A0 */
#define palette_sets_6_0_rest_2_ADDRESS 0x71C0u    /* 05B1C0 */
#define palette_sets_0_3_ADDRESS 0x71E0u    /* 05B1E0 */
#define palette_sets_0_3_rest_ADDRESS 0x7200u    /* 05B200 */
#define palette_sets_0_3_rest_2_ADDRESS 0x7220u    /* 05B220 */
#define palette_sets_0_3_rest_3_ADDRESS 0x7240u    /* 05B240 */
#define palette_sets_0_3_rest_4_ADDRESS 0x7260u    /* 05B260 */
#define palette_sets_0_3_rest_5_ADDRESS 0x7280u    /* 05B280 */
#define palette_sets_0_3_rest_6_ADDRESS 0x72A0u    /* 05B2A0 */
#define palette_sets_0_3_rest_7_ADDRESS 0x72C0u    /* 05B2C0 */
#define palette_sets_0_3_rest_8_ADDRESS 0x72E0u    /* 05B2E0 */
#define palette_sets_0_3_rest_9_ADDRESS 0x7300u    /* 05B300 */
#define palette_sets_0_3_rest_10_ADDRESS 0x7320u    /* 05B320 */
#define palette_sets_0_3_rest_11_ADDRESS 0x7340u    /* 05B340 */
#define palette_sets_0_3_rest_12_ADDRESS 0x7360u    /* 05B360 */
#define palette_sets_0_3_rest_13_ADDRESS 0x7380u    /* 05B380 */
#define palette_sets_0_3_rest_14_ADDRESS 0x73A0u    /* 05B3A0 */
#define palette_sets_0_3_rest_15_ADDRESS 0x73C0u    /* 05B3C0 */
#define palette_sets_high_1_3_ADDRESS 0x73E0u    /* 05B3E0 */
#define palette_sets_high_1_3_rest_ADDRESS 0x7400u    /* 05B400 */
#define palette_sets_high_1_3_rest_2_ADDRESS 0x7420u    /* 05B420 */
#define palette_sets_high_1_3_rest_3_ADDRESS 0x7440u    /* 05B440 */
#define palette_sets_high_1_3_rest_4_ADDRESS 0x7460u    /* 05B460 */
#define palette_sets_high_1_3_rest_5_ADDRESS 0x7480u    /* 05B480 */
#define palette_sets_high_1_3_rest_6_ADDRESS 0x74A0u    /* 05B4A0 */
#define palette_sets_high_3_3_ADDRESS 0x74C0u    /* 05B4C0 */
#define palette_sets_high_3_3_rest_ADDRESS 0x74E0u    /* 05B4E0 */
#define palette_sets_high_3_3_rest_2_ADDRESS 0x7500u    /* 05B500 */
#define palette_sets_high_3_3_rest_3_ADDRESS 0x7520u    /* 05B520 */
#define palette_sets_high_3_3_rest_4_ADDRESS 0x7540u    /* 05B540 */
#define palette_sets_high_3_3_rest_5_ADDRESS 0x7560u    /* 05B560 */
#define palette_sets_high_3_3_rest_6_ADDRESS 0x7580u    /* 05B580 */
#define palette_sets_high_5_3_ADDRESS 0x75A0u    /* 05B5A0 */
#define palette_sets_high_5_3_rest_ADDRESS 0x75C0u    /* 05B5C0 */
#define palette_sets_high_5_3_rest_2_ADDRESS 0x75E0u    /* 05B5E0 */
#define palette_sets_high_5_3_rest_3_ADDRESS 0x7600u    /* 05B600 */
#define palette_sets_high_5_3_rest_4_ADDRESS 0x7620u    /* 05B620 */
#define palette_sets_high_5_3_rest_5_ADDRESS 0x7640u    /* 05B640 */
#define palette_sets_high_5_3_rest_6_ADDRESS 0x7660u    /* 05B660 */
#define palette_sets_high_6_3_ADDRESS 0x7680u    /* 05B680 */
#define palette_sets_high_6_3_rest_ADDRESS 0x76A0u    /* 05B6A0 */
#define palette_sets_high_6_3_rest_2_ADDRESS 0x76C0u    /* 05B6C0 */
#define palette_sets_high_6_3_rest_3_ADDRESS 0x76E0u    /* 05B6E0 */
#define palette_sets_high_6_3_rest_4_ADDRESS 0x7700u    /* 05B700 */
#define palette_sets_high_6_3_rest_5_ADDRESS 0x7720u    /* 05B720 */
#define palette_sets_high_6_3_rest_6_ADDRESS 0x7740u    /* 05B740 */
#define palette_sets_high_7_3_ADDRESS 0x7760u    /* 05B760 */
#define palette_sets_high_7_3_rest_ADDRESS 0x7780u    /* 05B780 */
#define palette_sets_high_7_3_rest_2_ADDRESS 0x77A0u    /* 05B7A0 */
#define palette_sets_high_7_3_rest_3_ADDRESS 0x77C0u    /* 05B7C0 */
#define palette_sets_high_7_3_rest_4_ADDRESS 0x77E0u    /* 05B7E0 */
#define palette_sets_high_7_3_rest_5_ADDRESS 0x7800u    /* 05B800 */
#define palette_sets_high_7_3_rest_6_ADDRESS 0x7820u    /* 05B820 */
#define palette_sets_high_8_3_ADDRESS 0x7840u    /* 05B840 */
#define palette_sets_high_8_3_rest_ADDRESS 0x7860u    /* 05B860 */
#define palette_sets_high_8_3_rest_2_ADDRESS 0x7880u    /* 05B880 */
#define palette_sets_high_8_3_rest_3_ADDRESS 0x78A0u    /* 05B8A0 */
#define palette_sets_high_8_3_rest_4_ADDRESS 0x78C0u    /* 05B8C0 */
#define palette_sets_high_8_3_rest_5_ADDRESS 0x78E0u    /* 05B8E0 */
#define palette_sets_high_8_3_rest_6_ADDRESS 0x7900u    /* 05B900 */
#define palette_sets_high_11_3_ADDRESS 0x7920u    /* 05B920 */
#define palette_sets_high_11_3_rest_ADDRESS 0x7940u    /* 05B940 */
#define palette_sets_high_11_3_rest_2_ADDRESS 0x7960u    /* 05B960 */
#define palette_sets_high_11_3_rest_3_ADDRESS 0x7980u    /* 05B980 */
#define palette_sets_high_11_3_rest_4_ADDRESS 0x79A0u    /* 05B9A0 */
#define palette_sets_high_11_3_rest_5_ADDRESS 0x79C0u    /* 05B9C0 */
#define palette_sets_high_11_3_rest_6_ADDRESS 0x79E0u    /* 05B9E0 */
#define palette_sets_high_13_3_ADDRESS 0x7A00u    /* 05BA00 */
#define palette_sets_high_13_3_rest_ADDRESS 0x7A20u    /* 05BA20 */
#define palette_sets_high_13_3_rest_2_ADDRESS 0x7A40u    /* 05BA40 */
#define palette_sets_high_13_3_rest_3_ADDRESS 0x7A60u    /* 05BA60 */
#define palette_sets_high_13_3_rest_4_ADDRESS 0x7A80u    /* 05BA80 */
#define palette_sets_high_13_3_rest_5_ADDRESS 0x7AA0u    /* 05BAA0 */
#define palette_sets_high_13_3_rest_6_ADDRESS 0x7AC0u    /* 05BAC0 */
#define palette_sets_high_14_3_ADDRESS 0x7AE0u    /* 05BAE0 */
#define palette_sets_high_14_3_rest_ADDRESS 0x7B00u    /* 05BB00 */
#define palette_sets_high_14_3_rest_2_ADDRESS 0x7B20u    /* 05BB20 */
#define palette_sets_high_14_3_rest_3_ADDRESS 0x7B40u    /* 05BB40 */
#define palette_sets_high_14_3_rest_4_ADDRESS 0x7B60u    /* 05BB60 */
#define palette_sets_high_14_3_rest_5_ADDRESS 0x7B80u    /* 05BB80 */
#define palette_sets_high_14_3_rest_6_ADDRESS 0x7BA0u    /* 05BBA0 */
#define palette_sets_high_18_3_ADDRESS 0x7BC0u    /* 05BBC0 */
#define palette_sets_12_3_ADDRESS 0x7BE0u    /* 05BBE0 */
#define palette_sets_12_3_rest_ADDRESS 0x7C00u    /* 05BC00 */
#define palette_sets_12_3_rest_2_ADDRESS 0x7C20u    /* 05BC20 */
#define palette_sets_12_3_rest_3_ADDRESS 0x7C40u    /* 05BC40 */
#define palette_sets_12_3_rest_4_ADDRESS 0x7C60u    /* 05BC60 */
#define palette_sets_12_3_rest_5_ADDRESS 0x7C80u    /* 05BC80 */
#define palette_sets_12_3_rest_6_ADDRESS 0x7CA0u    /* 05BCA0 */
#define palette_sets_12_3_rest_7_ADDRESS 0x7CC0u    /* 05BCC0 */
#define palette_sets_12_3_rest_8_ADDRESS 0x7CE0u    /* 05BCE0 */
#define palette_sets_12_3_rest_9_ADDRESS 0x7D00u    /* 05BD00 */
#define palette_sets_12_3_rest_10_ADDRESS 0x7D20u    /* 05BD20 */
#define palette_sets_12_3_rest_11_ADDRESS 0x7D40u    /* 05BD40 */
#define palette_sets_12_3_rest_12_ADDRESS 0x7D60u    /* 05BD60 */
#define palette_sets_12_3_rest_13_ADDRESS 0x7D80u    /* 05BD80 */
#define palette_sets_12_3_rest_14_ADDRESS 0x7DA0u    /* 05BDA0 */
#define palette_sets_12_3_rest_15_ADDRESS 0x7DC0u    /* 05BDC0 */
#define palette_sets_2_3_ADDRESS 0x7DE0u    /* 05BDE0 */
#define palette_sets_2_3_rest_ADDRESS 0x7E00u    /* 05BE00 */
#define palette_sets_2_3_rest_2_ADDRESS 0x7E20u    /* 05BE20 */
#define palette_sets_2_3_rest_3_ADDRESS 0x7E40u    /* 05BE40 */
#define palette_sets_high_9_3_ADDRESS 0x7E60u    /* 05BE60 */
#define palette_sets_5_3_ADDRESS 0x7E80u    /* 05BE80 */
#define palette_sets_5_3_rest_ADDRESS 0x7EA0u    /* 05BEA0 */
#define palette_sets_5_3_rest_2_ADDRESS 0x7EC0u    /* 05BEC0 */
#define palette_sets_high_17_3_ADDRESS 0x7EE0u    /* 05BEE0 */
#define palette_sets_high_17_3_rest_ADDRESS 0x7F00u    /* 05BF00 */
#define palette_sets_high_17_3_rest_2_ADDRESS 0x7F20u    /* 05BF20 */
#define palette_sets_high_17_3_rest_3_ADDRESS 0x7F40u    /* 05BF40 */
#define palette_sets_high_17_3_rest_4_ADDRESS 0x7F60u    /* 05BF60 */
#define palette_sets_high_17_3_rest_5_ADDRESS 0x7F80u    /* 05BF80 */
#define palette_sets_high_17_3_rest_6_ADDRESS 0x7FA0u    /* 05BFA0 */
#define palette_sets_high_17_3_rest_7_ADDRESS 0x7FC0u    /* 05BFC0 */
#define palette_sets_high_17_3_fill_ADDRESS 0x7FE0u    /* 05BFE0 */
#define palette_effects_palette_effect_ADDRESS 0x6092u    /* 05C092 */
#define palette_effects_palette_effect_2_ADDRESS 0x60D7u    /* 05C0D7 */
#define palette_effects_palette_effect_3_ADDRESS 0x611Bu    /* 05C11B */
#define palette_effects_palette_effect_4_ADDRESS 0x6174u    /* 05C174 */
#define palette_effects_palette_effect_5_ADDRESS 0x618Cu    /* 05C18C */
#define palette_effects_palette_effect_6_ADDRESS 0x61F1u    /* 05C1F1 */
#define palette_effects_palette_effect_7_ADDRESS 0x621Au    /* 05C21A */
#define palette_effects_palette_effect_8_ADDRESS 0x6233u    /* 05C233 */
#define palette_effects_palette_effect_9_ADDRESS 0x6248u    /* 05C248 */
#define palette_effects_palette_effect_10_ADDRESS 0x625Du    /* 05C25D */
#define palette_effects_palette_effect_11_ADDRESS 0x6272u    /* 05C272 */
#define palette_effects_palette_effect_12_ADDRESS 0x6287u    /* 05C287 */
#define palette_effects_palette_effect_13_ADDRESS 0x62CCu    /* 05C2CC */
#define palette_effects_palette_effect_14_ADDRESS 0x62E1u    /* 05C2E1 */
#define palette_effects_palette_effect_15_ADDRESS 0x636Au    /* 05C36A */
#define palette_effects_palette_effect_16_ADDRESS 0x63D3u    /* 05C3D3 */
#define palette_effects_palette_effect_17_ADDRESS 0x64CBu    /* 05C4CB */
#define palette_effects_palette_effect_18_ADDRESS 0x6563u    /* 05C563 */
#define palette_effects_palette_effect_19_ADDRESS 0x658Fu    /* 05C58F */
#define palette_effects_palette_effect_20_ADDRESS 0x65D7u    /* 05C5D7 */
#define palette_effects_palette_effect_21_ADDRESS 0x661Fu    /* 05C61F */
#define palette_effects_palette_effect_22_ADDRESS 0x664Bu    /* 05C64B */
#define palette_effects_palette_effect_23_ADDRESS 0x666Bu    /* 05C66B */
#define palette_effects_palette_effect_24_ADDRESS 0x6718u    /* 05C718 */
#define palette_effects_palette_effect_25_ADDRESS 0x677Du    /* 05C77D */
#define palette_effects_palette_effect_26_ADDRESS 0x6862u    /* 05C862 */
#define palette_effects_palette_effect_27_ADDRESS 0x68F3u    /* 05C8F3 */
#define palette_effects_palette_effect_28_ADDRESS 0x6968u    /* 05C968 */
#define palette_effects_palette_effect_29_ADDRESS 0x697Du    /* 05C97D */
#define palette_effects_palette_effect_30_ADDRESS 0x6AC9u    /* 05CAC9 */
#define palette_effects_palette_effect_31_ADDRESS 0x6C15u    /* 05CC15 */
#define palette_effects_palette_effect_32_ADDRESS 0x6D61u    /* 05CD61 */
#define palette_effects_palette_effect_33_ADDRESS 0x6EADu    /* 05CEAD */
#define palette_effects_palette_effect_34_ADDRESS 0x6F5Au    /* 05CF5A */
#define palette_effects_palette_effect_35_ADDRESS 0x6FBFu    /* 05CFBF */
#define palette_effects_palette_effect_36_ADDRESS 0x6FD8u    /* 05CFD8 */
#define palette_effects_palette_effect_37_ADDRESS 0x6FF1u    /* 05CFF1 */
#define palette_effects_palette_effect_38_ADDRESS 0x700Au    /* 05D00A */
#define palette_effects_palette_effect_39_ADDRESS 0x7023u    /* 05D023 */
#define palette_effects_palette_effect_40_ADDRESS 0x706Bu    /* 05D06B */
#define palette_effects_palette_effect_41_ADDRESS 0x7094u    /* 05D094 */
#define palette_effects_palette_effect_42_ADDRESS 0x70FDu    /* 05D0FD */
#define palette_effects_palette_effect_43_ADDRESS 0x7141u    /* 05D141 */
#define palette_effects_palette_effect_44_ADDRESS 0x719Du    /* 05D19D */
#define palette_effects_palette_effect_45_ADDRESS 0x71B9u    /* 05D1B9 */
#define palette_effects_palette_effect_46_ADDRESS 0x723Du    /* 05D23D */
#define palette_effects_palette_effect_47_ADDRESS 0x72A9u    /* 05D2A9 */
#define palette_effects_palette_effect_48_ADDRESS 0x72C9u    /* 05D2C9 */
#define palette_effects_palette_effect_49_ADDRESS 0x7365u    /* 05D365 */
#define palette_effects_palette_effect_50_ADDRESS 0x7401u    /* 05D401 */
#define palette_effects_palette_effect_51_ADDRESS 0x7421u    /* 05D421 */
#define palette_effects_palette_effect_52_ADDRESS 0x748Du    /* 05D48D */
#define palette_effects_palette_effect_53_ADDRESS 0x74C9u    /* 05D4C9 */
#define palette_effects_palette_effect_54_ADDRESS 0x74D9u    /* 05D4D9 */
#define palette_effects_palette_effect_55_ADDRESS 0x750Du    /* 05D50D */
#define palette_effects_palette_effect_56_ADDRESS 0x75C1u    /* 05D5C1 */
#define palette_effects_palette_effect_57_ADDRESS 0x75E5u    /* 05D5E5 */
#define palette_effects_palette_effect_58_ADDRESS 0x7661u    /* 05D661 */
#define palette_effects_palette_effect_59_ADDRESS 0x79EDu    /* 05D9ED */
#define palette_effects_palette_effect_60_ADDRESS 0x7ABDu    /* 05DABD */
#define palette_effects_palette_effect_61_ADDRESS 0x7AD5u    /* 05DAD5 */
#define palette_effects_palette_effect_62_ADDRESS 0x7AF5u    /* 05DAF5 */
#define palette_effects_palette_effect_63_ADDRESS 0x7B15u    /* 05DB15 */
#define palette_effects_palette_effect_64_ADDRESS 0x7B4Du    /* 05DB4D */
#define palette_effects_palette_effect_65_ADDRESS 0x7BF2u    /* 05DBF2 */
#define palette_effects_palette_effect_66_ADDRESS 0x7C73u    /* 05DC73 */
#define palette_effects_palette_effect_67_ADDRESS 0x7CF4u    /* 05DCF4 */
#define palette_effects_palette_effect_68_ADDRESS 0x7D10u    /* 05DD10 */
#define palette_effects_palette_effect_69_ADDRESS 0x7D40u    /* 05DD40 */
#define palette_effects_palette_effect_70_ADDRESS 0x7D90u    /* 05DD90 */
#define palette_effects_palette_effect_71_ADDRESS 0x7DE0u    /* 05DDE0 */
#define palette_effects_palette_effect_72_ADDRESS 0x7E00u    /* 05DE00 */
#define palette_effects_palette_effect_73_ADDRESS 0x7E40u    /* 05DE40 */
#define palette_effects_palette_effect_73_fill_ADDRESS 0x7E6Du    /* 05DE6D */
#define test_menu_page_steps_ADDRESS 0x6047u    /* 05E047 */
#define test_rom_check_page_steps_ADDRESS 0x60A1u    /* 05E0A1 */
#define test_screen_check_page_steps_ADDRESS 0x60C9u    /* 05E0C9 */
#define test_color_check_page_steps_ADDRESS 0x60F2u    /* 05E0F2 */
#define test_io_check_page_steps_ADDRESS 0x617Du    /* 05E17D */
#define test_music_page_steps_ADDRESS 0x621Bu    /* 05E21B */
#define test_sound_page_steps_ADDRESS 0x6277u    /* 05E277 */
#define test_options_page_steps_ADDRESS 0x62C9u    /* 05E2C9 */
#define test_choose_setting_steps_ADDRESS 0x642Bu    /* 05E42B */
#define test_factory_setting_page_steps_ADDRESS 0x646Du    /* 05E46D */
#define test_print_table_ADDRESS 0x6691u    /* 05E691 */
#define portrait_wait_animation_fill_ADDRESS 0x6FA8u    /* 05EFA8 */
#define boot_table_ADDRESS 0x71E0u    /* 05F1E0 */
#define test_pages_ADDRESS 0x7580u    /* 05F580 */
#define test_mode_texts_0_ADDRESS 0x75EEu    /* 05F5EE */
#define test_mode_texts_1_ADDRESS 0x7634u    /* 05F634 */
#define test_mode_texts_2_ADDRESS 0x7640u    /* 05F640 */
#define test_mode_texts_3_ADDRESS 0x764Cu    /* 05F64C */
#define test_mode_texts_22_ADDRESS 0x7658u    /* 05F658 */
#define test_mode_texts_5_ADDRESS 0x768Cu    /* 05F68C */
#define test_mode_texts_6_ADDRESS 0x76AEu    /* 05F6AE */
#define test_mode_texts_7_ADDRESS 0x76D0u    /* 05F6D0 */
#define test_mode_texts_8_ADDRESS 0x76E8u    /* 05F6E8 */
#define test_mode_texts_10_ADDRESS 0x771Du    /* 05F71D */
#define test_mode_texts_11_ADDRESS 0x775Cu    /* 05F75C */
#define test_mode_texts_12_ADDRESS 0x776Du    /* 05F76D */
#define test_mode_texts_13_ADDRESS 0x77AAu    /* 05F7AA */
#define test_mode_texts_14_ADDRESS 0x77CEu    /* 05F7CE */
#define test_mode_texts_15_ADDRESS 0x77DFu    /* 05F7DF */
#define test_mode_texts_16_ADDRESS 0x77F7u    /* 05F7F7 */
#define test_mode_texts_17_ADDRESS 0x780Fu    /* 05F80F */
#define test_mode_texts_18_ADDRESS 0x7823u    /* 05F823 */
#define test_mode_texts_19_ADDRESS 0x7845u    /* 05F845 */
#define test_mode_texts_21_ADDRESS 0x7881u    /* 05F881 */
#define test_mode_texts_20_ADDRESS 0x78BDu    /* 05F8BD */
#define test_mode_words_0_ADDRESS 0x7965u    /* 05F965 */
#define test_mode_words_1_ADDRESS 0x796Bu    /* 05F96B */
#define test_mode_words_2_ADDRESS 0x7977u    /* 05F977 */
#define test_mode_words_3_ADDRESS 0x797Fu    /* 05F97F */
#define test_text_player_ADDRESS 0x7984u    /* 05F984 */
#define test_mode_words_5_ADDRESS 0x798Cu    /* 05F98C */
#define test_mode_words_6_ADDRESS 0x79BAu    /* 05F9BA */
#define test_mode_words_7_ADDRESS 0x79C2u    /* 05F9C2 */
#define test_mode_words_8_ADDRESS 0x79CDu    /* 05F9CD */
#define test_mode_words_9_ADDRESS 0x79D7u    /* 05F9D7 */
#define test_mode_words_10_ADDRESS 0x79DEu    /* 05F9DE */
#define test_mode_words_12_ADDRESS 0x79E4u    /* 05F9E4 */
#define test_mode_words_13_ADDRESS 0x79EAu    /* 05F9EA */
#define test_mode_words_14_ADDRESS 0x79FCu    /* 05F9FC */
#define test_mode_words_15_ADDRESS 0x7A04u    /* 05FA04 */
#define test_mode_words_17_ADDRESS 0x7A0Cu    /* 05FA0C */
#define test_mode_words_18_ADDRESS 0x7A14u    /* 05FA14 */
#define test_mode_words_19_ADDRESS 0x7A2Bu    /* 05FA2B */
#define test_mode_words_20_ADDRESS 0x7A42u    /* 05FA42 */
#define test_mode_words_21_ADDRESS 0x7A4Fu    /* 05FA4F */
#define test_mode_words_33_ADDRESS 0x7A80u    /* 05FA80 */
#define test_mode_words_24_ADDRESS 0x7A8Au    /* 05FA8A */
#define test_mode_words_25_ADDRESS 0x7A8Fu    /* 05FA8F */
#define test_mode_words_26_ADDRESS 0x7A95u    /* 05FA95 */
#define test_text_coin_ADDRESS 0x7A9Bu    /* 05FA9B */
#define test_text_credit_ADDRESS 0x7AA0u    /* 05FAA0 */
#define test_mode_words_29_ADDRESS 0x7AA8u    /* 05FAA8 */
#define test_mode_words_30_ADDRESS 0x7AB2u    /* 05FAB2 */
#define test_mode_words_31_ADDRESS 0x7AB5u    /* 05FAB5 */
#define test_text_normal_ADDRESS 0x7ABAu    /* 05FABA */
#define test_mode_words_34_ADDRESS 0x7AC1u    /* 05FAC1 */
#define test_mode_words_35_ADDRESS 0x7AC8u    /* 05FAC8 */
#define test_mode_words_36_ADDRESS 0x7ACEu    /* 05FACE */
#define test_mode_words_37_ADDRESS 0x7AD5u    /* 05FAD5 */
#define test_text_monaural_ADDRESS 0x7ADEu    /* 05FADE */
#define test_text_stereo_ADDRESS 0x7AE7u    /* 05FAE7 */
#define test_text_factory_setting_ADDRESS 0x7AEEu    /* 05FAEE */
#define test_mode_words_41_ADDRESS 0x7AF2u    /* 05FAF2 */
#define test_mode_words_42_ADDRESS 0x7AF7u    /* 05FAF7 */
#define test_mode_words_43_ADDRESS 0x7AFAu    /* 05FAFA */
#define test_mode_words_44_ADDRESS 0x7B03u    /* 05FB03 */
#define test_mode_words_45_ADDRESS 0x7B15u    /* 05FB15 */
#define test_mode_words_46_ADDRESS 0x7B1Du    /* 05FB1D */
#define test_mode_words_47_ADDRESS 0x7B25u    /* 05FB25 */
#define test_mode_words_48_ADDRESS 0x7B2Fu    /* 05FB2F */
#define test_mode_words_49_ADDRESS 0x7B35u    /* 05FB35 */
#define test_mode_words_50_ADDRESS 0x7B39u    /* 05FB39 */
#define test_text_upside_down_ADDRESS 0x7B3Du    /* 05FB3D */
#define test_mode_words_52_ADDRESS 0x7B49u    /* 05FB49 */
#define test_text_with_ADDRESS 0x7B52u    /* 05FB52 */
#define test_text_without_ADDRESS 0x7B5Au    /* 05FB5A */
#define test_text_on_ADDRESS 0x7B65u    /* 05FB65 */
#define test_text_off_ADDRESS 0x7B68u    /* 05FB68 */
#define eeprom_unlock_bits_ADDRESS 0x7C7Cu    /* 05FC7C */
#define eeprom_write_bits_ADDRESS 0x7C9Au    /* 05FC9A */
#define eeprom_deselect_bits_ADDRESS 0x7CC7u    /* 05FCC7 */
#define eeprom_lock_bits_ADDRESS 0x7CCCu    /* 05FCCC */
#define eeprom_ones_bits_ADDRESS 0x7CF7u    /* 05FCF7 */
#define eeprom_read_bits_ADDRESS 0x7D08u    /* 05FD08 */
#define eeprom_receive_bits_ADDRESS 0x7D23u    /* 05FD23 */
#define eeprom_factory_settings_ADDRESS 0x7D36u    /* 05FD36 */
#define test_rom_check_step_table_ADDRESS 0x7D42u    /* 05FD42 */
#define game_start_portraits_steps_ADDRESS 0x7D78u    /* 05FD78 */
#define portrait_run_table_ADDRESS 0x7D7Cu    /* 05FD7C */
#define portrait_areas_fill_ADDRESS 0x7DE8u    /* 05FDE8 */
#define portrait_areas_rest_ADDRESS 0x6000u    /* 060000 */
#define marge_animations_ADDRESS 0x6008u    /* 060008 */
#define marge_animations_7_ADDRESS 0x6108u    /* 060108 */
#define marge_animations_7_sprites_ADDRESS 0x6110u    /* 060110 */
#define marge_animations_63_ADDRESS 0x611Cu    /* 06011C */
#define marge_animations_63_sprites_ADDRESS 0x6124u    /* 060124 */
#define marge_animations_38_ADDRESS 0x612Au    /* 06012A */
#define marge_animations_38_sprites_ADDRESS 0x6132u    /* 060132 */
#define marge_animations_0_ADDRESS 0x613Eu    /* 06013E */
#define marge_animations_0_sprites_ADDRESS 0x6146u    /* 060146 */
#define marge_animations_1_ADDRESS 0x615Eu    /* 06015E */
#define marge_animations_1_sprites_ADDRESS 0x6182u    /* 060182 */
#define marge_animations_1_sprites_2_ADDRESS 0x619Au    /* 06019A */
#define marge_animations_1_sprites_3_ADDRESS 0x61B2u    /* 0601B2 */
#define marge_animations_1_sprites_4_ADDRESS 0x61CAu    /* 0601CA */
#define marge_animations_1_sprites_5_ADDRESS 0x61E2u    /* 0601E2 */
#define marge_animations_1_sprites_6_ADDRESS 0x61FAu    /* 0601FA */
#define marge_animations_1_sprites_7_ADDRESS 0x6212u    /* 060212 */
#define marge_animations_1_sprites_8_ADDRESS 0x622Au    /* 06022A */
#define marge_animations_2_ADDRESS 0x6242u    /* 060242 */
#define marge_animations_2_sprites_ADDRESS 0x6266u    /* 060266 */
#define marge_animations_2_sprites_2_ADDRESS 0x6272u    /* 060272 */
#define marge_animations_2_sprites_3_ADDRESS 0x627Eu    /* 06027E */
#define marge_animations_2_sprites_4_ADDRESS 0x628Au    /* 06028A */
#define marge_animations_2_sprites_5_ADDRESS 0x6296u    /* 060296 */
#define marge_animations_2_sprites_6_ADDRESS 0x62A2u    /* 0602A2 */
#define marge_animations_2_sprites_7_ADDRESS 0x62AEu    /* 0602AE */
#define marge_animations_2_sprites_8_ADDRESS 0x62BAu    /* 0602BA */
#define marge_animations_3_ADDRESS 0x62C6u    /* 0602C6 */
#define marge_animations_3_sprites_ADDRESS 0x62CEu    /* 0602CE */
#define marge_animations_4_ADDRESS 0x62E6u    /* 0602E6 */
#define marge_animations_4_sprites_ADDRESS 0x62EEu    /* 0602EE */
#define marge_animations_5_ADDRESS 0x6300u    /* 060300 */
#define marge_animations_5_sprites_ADDRESS 0x630Cu    /* 06030C */
#define marge_animations_5_sprites_2_ADDRESS 0x631Eu    /* 06031E */
#define marge_animations_8_ADDRESS 0x632Au    /* 06032A */
#define marge_animations_8_sprites_ADDRESS 0x6332u    /* 060332 */
#define marge_animations_9_ADDRESS 0x634Au    /* 06034A */
#define marge_animations_9_sprites_ADDRESS 0x636Eu    /* 06036E */
#define marge_animations_9_sprites_2_ADDRESS 0x6386u    /* 060386 */
#define marge_animations_9_sprites_3_ADDRESS 0x639Eu    /* 06039E */
#define marge_animations_9_sprites_4_ADDRESS 0x63B6u    /* 0603B6 */
#define marge_animations_9_sprites_5_ADDRESS 0x63CEu    /* 0603CE */
#define marge_animations_9_sprites_6_ADDRESS 0x63E6u    /* 0603E6 */
#define marge_animations_9_sprites_7_ADDRESS 0x63FEu    /* 0603FE */
#define marge_animations_9_sprites_8_ADDRESS 0x6416u    /* 060416 */
#define marge_animations_11_ADDRESS 0x642Eu    /* 06042E */
#define marge_animations_11_sprites_ADDRESS 0x6436u    /* 060436 */
#define marge_animations_12_ADDRESS 0x6448u    /* 060448 */
#define marge_animations_12_sprites_ADDRESS 0x6450u    /* 060450 */
#define marge_animations_13_ADDRESS 0x645Cu    /* 06045C */
#define marge_animations_16_ADDRESS 0x6464u    /* 060464 */
#define marge_animations_16_sprites_ADDRESS 0x646Cu    /* 06046C */
#define marge_animations_17_ADDRESS 0x6478u    /* 060478 */
#define marge_animations_17_sprites_ADDRESS 0x649Cu    /* 06049C */
#define marge_animations_17_sprites_2_ADDRESS 0x64A8u    /* 0604A8 */
#define marge_animations_17_sprites_3_ADDRESS 0x64B4u    /* 0604B4 */
#define marge_animations_17_sprites_4_ADDRESS 0x64C0u    /* 0604C0 */
#define marge_animations_17_sprites_5_ADDRESS 0x64CCu    /* 0604CC */
#define marge_animations_17_sprites_6_ADDRESS 0x64D8u    /* 0604D8 */
#define marge_animations_17_sprites_7_ADDRESS 0x64E4u    /* 0604E4 */
#define marge_animations_17_sprites_8_ADDRESS 0x64F0u    /* 0604F0 */
#define marge_animations_19_ADDRESS 0x64FCu    /* 0604FC */
#define marge_animations_19_sprites_ADDRESS 0x6504u    /* 060504 */
#define marge_animations_20_ADDRESS 0x6510u    /* 060510 */
#define marge_animations_20_sprites_ADDRESS 0x6518u    /* 060518 */
#define marge_animations_21_ADDRESS 0x6524u    /* 060524 */
#define marge_animations_21_sprites_ADDRESS 0x652Cu    /* 06052C */
#define marge_animations_78_ADDRESS 0x6538u    /* 060538 */
#define marge_animations_78_sprites_ADDRESS 0x6540u    /* 060540 */
#define marge_animations_95_ADDRESS 0x6558u    /* 060558 */
#define marge_animations_95_sprites_ADDRESS 0x656Cu    /* 06056C */
#define marge_animations_95_sprites_2_ADDRESS 0x6584u    /* 060584 */
#define marge_animations_95_sprites_3_ADDRESS 0x659Cu    /* 06059C */
#define marge_animations_95_sprites_4_ADDRESS 0x65B4u    /* 0605B4 */
#define marge_animations_47_ADDRESS 0x65CCu    /* 0605CC */
#define marge_animations_47_sprites_ADDRESS 0x65F8u    /* 0605F8 */
#define marge_animations_47_sprites_2_ADDRESS 0x6610u    /* 060610 */
#define marge_animations_47_sprites_3_ADDRESS 0x6628u    /* 060628 */
#define marge_animations_47_sprites_4_ADDRESS 0x6640u    /* 060640 */
#define marge_animations_47_sprites_5_ADDRESS 0x6652u    /* 060652 */
#define marge_animations_47_sprites_6_ADDRESS 0x666Au    /* 06066A */
#define marge_animations_47_sprites_7_ADDRESS 0x6682u    /* 060682 */
#define marge_animations_91_ADDRESS 0x669Au    /* 06069A */
#define marge_animations_91_sprites_ADDRESS 0x66AEu    /* 0606AE */
#define marge_animations_91_sprites_2_ADDRESS 0x66BAu    /* 0606BA */
#define marge_animations_91_sprites_3_ADDRESS 0x66C6u    /* 0606C6 */
#define marge_animations_91_sprites_4_ADDRESS 0x66CCu    /* 0606CC */
#define marge_animations_94_ADDRESS 0x66D2u    /* 0606D2 */
#define marge_animations_94_sprites_ADDRESS 0x66DEu    /* 0606DE */
#define marge_animations_94_sprites_2_ADDRESS 0x66EAu    /* 0606EA */
#define marge_animations_15_ADDRESS 0x66FCu    /* 0606FC */
#define marge_animations_15_sprites_ADDRESS 0x670Cu    /* 06070C */
#define marge_animations_15_sprites_2_ADDRESS 0x6718u    /* 060718 */
#define marge_animations_15_sprites_3_ADDRESS 0x6730u    /* 060730 */
#define marge_animations_31_ADDRESS 0x673Cu    /* 06073C */
#define marge_animations_31_sprites_ADDRESS 0x6748u    /* 060748 */
#define marge_animations_31_sprites_2_ADDRESS 0x6754u    /* 060754 */
#define marge_animations_23_ADDRESS 0x6766u    /* 060766 */
#define marge_animations_23_sprites_ADDRESS 0x6772u    /* 060772 */
#define marge_animations_23_sprites_2_ADDRESS 0x6784u    /* 060784 */
#define marge_animations_14_ADDRESS 0x6790u    /* 060790 */
#define marge_animations_14_sprites_ADDRESS 0x6798u    /* 060798 */
#define marge_animations_73_ADDRESS 0x67A4u    /* 0607A4 */
#define marge_animations_73_sprites_ADDRESS 0x67B0u    /* 0607B0 */
#define marge_animations_73_sprites_2_ADDRESS 0x67B6u    /* 0607B6 */
#define marge_animations_75_ADDRESS 0x67C2u    /* 0607C2 */
#define marge_animations_75_sprites_ADDRESS 0x67CAu    /* 0607CA */
#define marge_animations_77_ADDRESS 0x67E2u    /* 0607E2 */
#define marge_animations_77_sprites_ADDRESS 0x67EEu    /* 0607EE */
#define marge_animations_48_ADDRESS 0x6806u    /* 060806 */
#define marge_animations_48_sprites_ADDRESS 0x6812u    /* 060812 */
#define marge_animations_48_sprites_2_ADDRESS 0x682Au    /* 06082A */
#define marge_animations_49_ADDRESS 0x6842u    /* 060842 */
#define marge_animations_49_sprites_ADDRESS 0x684Eu    /* 06084E */
#define marge_animations_49_sprites_2_ADDRESS 0x685Au    /* 06085A */
#define marge_animations_53_ADDRESS 0x686Cu    /* 06086C */
#define marge_animations_53_sprites_ADDRESS 0x6884u    /* 060884 */
#define marge_animations_53_sprites_2_ADDRESS 0x6896u    /* 060896 */
#define marge_animations_53_sprites_3_ADDRESS 0x68A8u    /* 0608A8 */
#define marge_animations_53_sprites_4_ADDRESS 0x68BAu    /* 0608BA */
#define marge_animations_53_sprites_5_ADDRESS 0x68CCu    /* 0608CC */
#define marge_animations_54_ADDRESS 0x68DEu    /* 0608DE */
#define marge_animations_54_sprites_ADDRESS 0x68F2u    /* 0608F2 */
#define marge_animations_54_sprites_2_ADDRESS 0x6904u    /* 060904 */
#define marge_animations_54_sprites_3_ADDRESS 0x6916u    /* 060916 */
#define marge_animations_58_ADDRESS 0x6928u    /* 060928 */
#define marge_animations_58_sprites_ADDRESS 0x6934u    /* 060934 */
#define marge_animations_58_sprites_2_ADDRESS 0x693Au    /* 06093A */
#define marge_animations_59_ADDRESS 0x6940u    /* 060940 */
#define marge_animations_59_sprites_ADDRESS 0x694Cu    /* 06094C */
#define marge_animations_59_sprites_2_ADDRESS 0x6964u    /* 060964 */
#define marge_animations_61_ADDRESS 0x697Cu    /* 06097C */
#define marge_animations_61_sprites_ADDRESS 0x6984u    /* 060984 */
#define marge_animations_62_ADDRESS 0x6990u    /* 060990 */
#define marge_animations_62_sprites_ADDRESS 0x699Cu    /* 06099C */
#define marge_animations_62_sprites_2_ADDRESS 0x69A8u    /* 0609A8 */
#define marge_animations_64_ADDRESS 0x69BAu    /* 0609BA */
#define marge_animations_64_sprites_ADDRESS 0x69C6u    /* 0609C6 */
#define marge_animations_64_sprites_2_ADDRESS 0x69D8u    /* 0609D8 */
#define marge_animations_65_ADDRESS 0x69F0u    /* 0609F0 */
#define marge_animations_65_sprites_ADDRESS 0x69FCu    /* 0609FC */
#define marge_animations_65_sprites_2_ADDRESS 0x6A08u    /* 060A08 */
#define marge_animations_69_ADDRESS 0x6A1Au    /* 060A1A */
#define marge_animations_69_sprites_ADDRESS 0x6A32u    /* 060A32 */
#define marge_animations_69_sprites_2_ADDRESS 0x6A44u    /* 060A44 */
#define marge_animations_69_sprites_3_ADDRESS 0x6A56u    /* 060A56 */
#define marge_animations_69_sprites_4_ADDRESS 0x6A68u    /* 060A68 */
#define marge_animations_69_sprites_5_ADDRESS 0x6A7Au    /* 060A7A */
#define marge_animations_70_ADDRESS 0x6A8Cu    /* 060A8C */
#define marge_animations_70_sprites_ADDRESS 0x6A98u    /* 060A98 */
#define marge_animations_70_sprites_2_ADDRESS 0x6AB0u    /* 060AB0 */
#define marge_animations_80_ADDRESS 0x6AC2u    /* 060AC2 */
#define marge_animations_80_sprites_ADDRESS 0x6AD6u    /* 060AD6 */
#define marge_animations_80_sprites_2_ADDRESS 0x6AE2u    /* 060AE2 */
#define marge_animations_80_sprites_3_ADDRESS 0x6AF4u    /* 060AF4 */
#define marge_animations_80_sprites_4_ADDRESS 0x6B06u    /* 060B06 */
#define marge_animations_81_ADDRESS 0x6B12u    /* 060B12 */
#define marge_animations_81_sprites_ADDRESS 0x6B1Eu    /* 060B1E */
#define marge_animations_81_sprites_2_ADDRESS 0x6B30u    /* 060B30 */
#define marge_animations_82_ADDRESS 0x6B42u    /* 060B42 */
#define marge_animations_82_sprites_ADDRESS 0x6B4Eu    /* 060B4E */
#define marge_animations_82_sprites_2_ADDRESS 0x6B5Au    /* 060B5A */
#define marge_animations_83_ADDRESS 0x6B6Cu    /* 060B6C */
#define marge_animations_83_sprites_ADDRESS 0x6B80u    /* 060B80 */
#define marge_animations_83_sprites_2_ADDRESS 0x6B8Cu    /* 060B8C */
#define marge_animations_83_sprites_3_ADDRESS 0x6B98u    /* 060B98 */
#define marge_animations_83_sprites_4_ADDRESS 0x6BA4u    /* 060BA4 */
#define marge_animations_84_ADDRESS 0x6BB0u    /* 060BB0 */
#define marge_animations_84_sprites_ADDRESS 0x6BC4u    /* 060BC4 */
#define marge_animations_84_sprites_2_ADDRESS 0x6BD6u    /* 060BD6 */
#define marge_animations_84_sprites_3_ADDRESS 0x6BE2u    /* 060BE2 */
#define marge_animations_84_sprites_4_ADDRESS 0x6BF4u    /* 060BF4 */
#define marge_animations_92_ADDRESS 0x6C0Cu    /* 060C0C */
#define marge_animations_92_sprites_ADDRESS 0x6C1Cu    /* 060C1C */
#define marge_animations_92_sprites_2_ADDRESS 0x6C28u    /* 060C28 */
#define marge_animations_92_sprites_3_ADDRESS 0x6C3Au    /* 060C3A */
#define marge_animations_85_ADDRESS 0x6C40u    /* 060C40 */
#define marge_animations_85_sprites_ADDRESS 0x6C54u    /* 060C54 */
#define marge_animations_85_sprites_2_ADDRESS 0x6C60u    /* 060C60 */
#define marge_animations_85_sprites_3_ADDRESS 0x6C6Cu    /* 060C6C */
#define marge_animations_85_sprites_4_ADDRESS 0x6C78u    /* 060C78 */
#define marge_animations_93_ADDRESS 0x6C84u    /* 060C84 */
#define marge_animations_93_sprites_ADDRESS 0x6C94u    /* 060C94 */
#define marge_animations_93_sprites_2_ADDRESS 0x6CA0u    /* 060CA0 */
#define marge_animations_86_ADDRESS 0x6CACu    /* 060CAC */
#define marge_animations_86_sprites_ADDRESS 0x6CB8u    /* 060CB8 */
#define marge_animations_86_sprites_2_ADDRESS 0x6CC4u    /* 060CC4 */
#define marge_animations_87_ADDRESS 0x6CD0u    /* 060CD0 */
#define marge_animations_87_sprites_ADDRESS 0x6CD8u    /* 060CD8 */
#define marge_animations_88_ADDRESS 0x6CEAu    /* 060CEA */
#define marge_animations_88_sprites_ADDRESS 0x6D0Eu    /* 060D0E */
#define marge_animations_88_sprites_2_ADDRESS 0x6D20u    /* 060D20 */
#define marge_animations_88_sprites_3_ADDRESS 0x6D2Cu    /* 060D2C */
#define marge_animations_88_sprites_4_ADDRESS 0x6D3Eu    /* 060D3E */
#define marge_animations_88_sprites_5_ADDRESS 0x6D4Au    /* 060D4A */
#define marge_animations_88_sprites_6_ADDRESS 0x6D62u    /* 060D62 */
#define marge_animations_88_sprites_7_ADDRESS 0x6D7Au    /* 060D7A */
#define marge_animations_88_sprites_8_ADDRESS 0x6D92u    /* 060D92 */
#define marge_animations_89_ADDRESS 0x6DAAu    /* 060DAA */
#define marge_animations_89_sprites_ADDRESS 0x6DB6u    /* 060DB6 */
#define marge_animations_89_sprites_2_ADDRESS 0x6DC2u    /* 060DC2 */
#define marge_animations_96_ADDRESS 0x6DCEu    /* 060DCE */
#define marge_animations_96_sprites_ADDRESS 0x6DDEu    /* 060DDE */
#define marge_animations_96_sprites_2_ADDRESS 0x6DF0u    /* 060DF0 */
#define marge_animations_96_sprites_3_ADDRESS 0x6E02u    /* 060E02 */
#define marge_animations_100_ADDRESS 0x6E14u    /* 060E14 */
#define marge_animations_100_sprites_ADDRESS 0x6E38u    /* 060E38 */
#define marge_animations_100_sprites_2_ADDRESS 0x6E44u    /* 060E44 */
#define marge_animations_100_sprites_3_ADDRESS 0x6E50u    /* 060E50 */
#define marge_animations_100_sprites_4_ADDRESS 0x6E5Cu    /* 060E5C */
#define marge_animations_100_sprites_5_ADDRESS 0x6E68u    /* 060E68 */
#define marge_animations_100_sprites_6_ADDRESS 0x6E74u    /* 060E74 */
#define marge_animations_100_sprites_7_ADDRESS 0x6E80u    /* 060E80 */
#define marge_animations_100_sprites_8_ADDRESS 0x6E8Cu    /* 060E8C */
#define marge_animations_104_ADDRESS 0x6E98u    /* 060E98 */
#define marge_animations_108_ADDRESS 0x6EB8u    /* 060EB8 */
#define marge_animations_112_ADDRESS 0x6EDCu    /* 060EDC */
#define marge_animations_112_sprites_ADDRESS 0x6F00u    /* 060F00 */
#define marge_animations_112_sprites_2_ADDRESS 0x6F06u    /* 060F06 */
#define marge_animations_112_sprites_3_ADDRESS 0x6F0Cu    /* 060F0C */
#define marge_animations_112_sprites_4_ADDRESS 0x6F12u    /* 060F12 */
#define marge_animations_112_sprites_5_ADDRESS 0x6F18u    /* 060F18 */
#define marge_animations_112_sprites_6_ADDRESS 0x6F1Eu    /* 060F1E */
#define marge_animations_112_sprites_7_ADDRESS 0x6F24u    /* 060F24 */
#define marge_animations_112_sprites_8_ADDRESS 0x6F2Au    /* 060F2A */
#define marge_animations_116_ADDRESS 0x6F30u    /* 060F30 */
#define marge_animations_121_ADDRESS 0x6F54u    /* 060F54 */
#define marge_animations_121_sprites_ADDRESS 0x6F5Cu    /* 060F5C */
#define marge_animations_125_ADDRESS 0x6F6Eu    /* 060F6E */
#define marge_animations_125_sprites_ADDRESS 0x6F76u    /* 060F76 */
#define marge_animations_32_ADDRESS 0x6F88u    /* 060F88 */
#define marge_animations_32_sprites_ADDRESS 0x6F90u    /* 060F90 */
#define marge_animations_33_ADDRESS 0x6FA8u    /* 060FA8 */
#define marge_animations_33_sprites_ADDRESS 0x6FCCu    /* 060FCC */
#define marge_animations_33_sprites_2_ADDRESS 0x6FE4u    /* 060FE4 */
#define marge_animations_33_sprites_3_ADDRESS 0x6FFCu    /* 060FFC */
#define marge_animations_33_sprites_4_ADDRESS 0x7014u    /* 061014 */
#define marge_animations_33_sprites_5_ADDRESS 0x702Cu    /* 06102C */
#define marge_animations_33_sprites_6_ADDRESS 0x7044u    /* 061044 */
#define marge_animations_33_sprites_7_ADDRESS 0x705Cu    /* 06105C */
#define marge_animations_33_sprites_8_ADDRESS 0x7074u    /* 061074 */
#define marge_animations_35_ADDRESS 0x708Cu    /* 06108C */
#define marge_animations_35_sprites_ADDRESS 0x7094u    /* 061094 */
#define marge_animations_36_ADDRESS 0x70ACu    /* 0610AC */
#define marge_animations_36_sprites_ADDRESS 0x70B4u    /* 0610B4 */
#define marge_animations_37_ADDRESS 0x70CCu    /* 0610CC */
#define marge_animations_51_ADDRESS 0x70D4u    /* 0610D4 */
#define marge_animations_51_sprites_ADDRESS 0x70E4u    /* 0610E4 */
#define marge_animations_51_sprites_2_ADDRESS 0x70FCu    /* 0610FC */
#define marge_animations_51_sprites_3_ADDRESS 0x710Eu    /* 06110E */
#define marge_animations_67_ADDRESS 0x7126u    /* 061126 */
#define marge_animations_67_sprites_ADDRESS 0x7136u    /* 061136 */
#define marge_animations_67_sprites_2_ADDRESS 0x714Eu    /* 06114E */
#define marge_animations_67_sprites_3_ADDRESS 0x7160u    /* 061160 */
#define marge_animations_30_ADDRESS 0x7178u    /* 061178 */
#define marge_animations_30_sprites_ADDRESS 0x7184u    /* 061184 */
#define marge_animations_30_sprites_2_ADDRESS 0x719Cu    /* 06119C */
#define marge_animations_24_ADDRESS 0x71B4u    /* 0611B4 */
#define marge_animations_24_sprites_ADDRESS 0x71BCu    /* 0611BC */
#define marge_animations_25_ADDRESS 0x71CEu    /* 0611CE */
#define marge_animations_25_sprites_ADDRESS 0x71F2u    /* 0611F2 */
#define marge_animations_25_sprites_2_ADDRESS 0x7204u    /* 061204 */
#define marge_animations_25_sprites_3_ADDRESS 0x7216u    /* 061216 */
#define marge_animations_25_sprites_4_ADDRESS 0x7228u    /* 061228 */
#define marge_animations_25_sprites_5_ADDRESS 0x723Au    /* 06123A */
#define marge_animations_25_sprites_6_ADDRESS 0x724Cu    /* 06124C */
#define marge_animations_25_sprites_7_ADDRESS 0x725Eu    /* 06125E */
#define marge_animations_25_sprites_8_ADDRESS 0x7270u    /* 061270 */
#define marge_animations_27_ADDRESS 0x7282u    /* 061282 */
#define marge_animations_27_sprites_ADDRESS 0x728Au    /* 06128A */
#define marge_animations_28_ADDRESS 0x72A2u    /* 0612A2 */
#define marge_animations_28_sprites_ADDRESS 0x72AAu    /* 0612AA */
#define marge_animations_29_ADDRESS 0x72C2u    /* 0612C2 */
#define marge_animations_29_sprites_ADDRESS 0x72CEu    /* 0612CE */
#define marge_animations_50_ADDRESS 0x72E6u    /* 0612E6 */
#define marge_animations_50_sprites_ADDRESS 0x72FAu    /* 0612FA */
#define marge_animations_50_sprites_2_ADDRESS 0x7312u    /* 061312 */
#define marge_animations_50_sprites_3_ADDRESS 0x732Au    /* 06132A */
#define marge_animations_50_sprites_4_ADDRESS 0x7342u    /* 061342 */
#define marge_animations_66_ADDRESS 0x7360u    /* 061360 */
#define marge_animations_66_sprites_ADDRESS 0x7374u    /* 061374 */
#define marge_animations_66_sprites_2_ADDRESS 0x738Cu    /* 06138C */
#define marge_animations_66_sprites_3_ADDRESS 0x73A4u    /* 0613A4 */
#define marge_animations_66_sprites_4_ADDRESS 0x73BCu    /* 0613BC */
#define marge_animations_40_ADDRESS 0x73DAu    /* 0613DA */
#define marge_animations_40_sprites_ADDRESS 0x73E2u    /* 0613E2 */
#define marge_animations_41_ADDRESS 0x73EEu    /* 0613EE */
#define marge_animations_41_sprites_ADDRESS 0x7412u    /* 061412 */
#define marge_animations_41_sprites_2_ADDRESS 0x741Eu    /* 06141E */
#define marge_animations_41_sprites_3_ADDRESS 0x742Au    /* 06142A */
#define marge_animations_41_sprites_4_ADDRESS 0x7436u    /* 061436 */
#define marge_animations_41_sprites_5_ADDRESS 0x7442u    /* 061442 */
#define marge_animations_41_sprites_6_ADDRESS 0x744Eu    /* 06144E */
#define marge_animations_41_sprites_7_ADDRESS 0x745Au    /* 06145A */
#define marge_animations_41_sprites_8_ADDRESS 0x7466u    /* 061466 */
#define marge_animations_43_ADDRESS 0x7472u    /* 061472 */
#define marge_animations_43_sprites_ADDRESS 0x747Au    /* 06147A */
#define marge_animations_44_ADDRESS 0x7486u    /* 061486 */
#define marge_animations_44_sprites_ADDRESS 0x748Eu    /* 06148E */
#define marge_animations_45_ADDRESS 0x749Au    /* 06149A */
#define marge_animations_52_ADDRESS 0x74A2u    /* 0614A2 */
#define marge_animations_52_sprites_ADDRESS 0x74B2u    /* 0614B2 */
#define marge_animations_52_sprites_2_ADDRESS 0x74CAu    /* 0614CA */
#define marge_animations_68_ADDRESS 0x74E2u    /* 0614E2 */
#define marge_animations_68_sprites_ADDRESS 0x74F2u    /* 0614F2 */
#define marge_animations_68_sprites_2_ADDRESS 0x74FEu    /* 0614FE */
#define marge_animations_68_sprites_3_ADDRESS 0x7516u    /* 061516 */
#define marge_animations_6_ADDRESS 0x752Eu    /* 06152E */
#define marge_animations_6_sprites_ADDRESS 0x754Au    /* 06154A */
#define marge_animations_6_sprites_2_ADDRESS 0x755Cu    /* 06155C */
#define marge_animations_6_sprites_3_ADDRESS 0x7568u    /* 061568 */
#define marge_animations_6_sprites_4_ADDRESS 0x7574u    /* 061574 */
#define marge_animations_6_sprites_5_ADDRESS 0x7580u    /* 061580 */
#define marge_animations_6_sprites_6_ADDRESS 0x758Cu    /* 06158C */
#define marge_animations_22_ADDRESS 0x759Eu    /* 06159E */
#define marge_animations_22_sprites_ADDRESS 0x75CAu    /* 0615CA */
#define marge_animations_22_sprites_2_ADDRESS 0x75DCu    /* 0615DC */
#define marge_animations_22_sprites_3_ADDRESS 0x75EEu    /* 0615EE */
#define marge_animations_22_sprites_4_ADDRESS 0x75FAu    /* 0615FA */
#define marge_animations_22_sprites_5_ADDRESS 0x7606u    /* 061606 */
#define marge_animations_22_sprites_6_ADDRESS 0x7618u    /* 061618 */
#define marge_animations_22_sprites_7_ADDRESS 0x7624u    /* 061624 */
#define marge_animations_22_sprites_8_ADDRESS 0x7630u    /* 061630 */
#define marge_animations_22_sprites_9_ADDRESS 0x763Cu    /* 06163C */
#define marge_animations_22_sprites_10_ADDRESS 0x7648u    /* 061648 */
#define marge_animations_57_ADDRESS 0x765Au    /* 06165A */
#define marge_animations_57_sprites_ADDRESS 0x766Au    /* 06166A */
#define marge_animations_57_sprites_2_ADDRESS 0x767Cu    /* 06167C */
#define marge_animations_57_sprites_3_ADDRESS 0x7688u    /* 061688 */
#define marge_animations_55_ADDRESS 0x7694u    /* 061694 */
#define marge_animations_55_sprites_ADDRESS 0x76CCu    /* 0616CC */
#define marge_animations_55_sprites_2_ADDRESS 0x76DEu    /* 0616DE */
#define marge_animations_55_sprites_3_ADDRESS 0x76F6u    /* 0616F6 */
#define marge_animations_55_sprites_4_ADDRESS 0x770Eu    /* 06170E */
#define marge_animations_55_sprites_5_ADDRESS 0x7726u    /* 061726 */
#define marge_animations_55_sprites_6_ADDRESS 0x773Eu    /* 06173E */
#define marge_animations_55_sprites_7_ADDRESS 0x7750u    /* 061750 */
#define marge_animations_55_sprites_8_ADDRESS 0x7762u    /* 061762 */
#define marge_animations_55_sprites_9_ADDRESS 0x777Au    /* 06177A */
#define marge_animations_55_sprites_10_ADDRESS 0x7792u    /* 061792 */
#define marge_animations_55_sprites_11_ADDRESS 0x77AAu    /* 0617AA */
#define marge_animations_56_ADDRESS 0x77C8u    /* 0617C8 */
#define marge_animations_56_sprites_ADDRESS 0x7800u    /* 061800 */
#define marge_animations_56_sprites_2_ADDRESS 0x7818u    /* 061818 */
#define marge_animations_56_sprites_3_ADDRESS 0x782Au    /* 06182A */
#define marge_animations_39_ADDRESS 0x7842u    /* 061842 */
#define marge_animations_39_sprites_ADDRESS 0x784Eu    /* 06184E */
#define marge_animations_39_sprites_2_ADDRESS 0x7866u    /* 061866 */
#define marge_animations_46_ADDRESS 0x787Eu    /* 06187E */
#define marge_animations_46_sprites_ADDRESS 0x788Au    /* 06188A */
#define marge_animations_46_sprites_2_ADDRESS 0x7896u    /* 061896 */
#define milhouse_animations_ADDRESS 0x78A8u    /* 0618A8 */
#define milhouse_animations_0_ADDRESS 0x78B2u    /* 0618B2 */
#define milhouse_animations_0_sprites_ADDRESS 0x78CEu    /* 0618CE */
#define milhouse_animations_0_sprites_2_ADDRESS 0x78DAu    /* 0618DA */
#define milhouse_animations_0_sprites_3_ADDRESS 0x78E6u    /* 0618E6 */
#define milhouse_animations_0_sprites_4_ADDRESS 0x78F2u    /* 0618F2 */
#define milhouse_animations_1_ADDRESS 0x78FEu    /* 0618FE */
#define milhouse_animations_1_sprites_ADDRESS 0x791Au    /* 06191A */
#define milhouse_animations_1_sprites_2_ADDRESS 0x7932u    /* 061932 */
#define milhouse_animations_1_sprites_3_ADDRESS 0x794Au    /* 06194A */
#define milhouse_animations_1_sprites_4_ADDRESS 0x7962u    /* 061962 */
#define milhouse_animations_2_ADDRESS 0x797Au    /* 06197A */
#define milhouse_animations_2_sprites_ADDRESS 0x7986u    /* 061986 */
#define milhouse_animations_2_sprites_2_ADDRESS 0x799Eu    /* 06199E */
#define milhouse_animations_3_ADDRESS 0x79B6u    /* 0619B6 */
#define milhouse_animations_3_sprites_ADDRESS 0x79C2u    /* 0619C2 */
#define milhouse_animations_3_sprites_2_ADDRESS 0x79CEu    /* 0619CE */
#define milhouse_animations_4_ADDRESS 0x79DAu    /* 0619DA */
#define milhouse_animations_4_sprites_ADDRESS 0x79E6u    /* 0619E6 */
#define milhouse_animations_4_sprites_2_ADDRESS 0x79F2u    /* 0619F2 */
#define skinner_animations_ADDRESS 0x79FEu    /* 0619FE */
#define skinner_animations_0_ADDRESS 0x7A0Cu    /* 061A0C */
#define skinner_animations_0_sprites_ADDRESS 0x7A28u    /* 061A28 */
#define skinner_animations_0_sprites_2_ADDRESS 0x7A3Au    /* 061A3A */
#define skinner_animations_0_sprites_3_ADDRESS 0x7A4Cu    /* 061A4C */
#define skinner_animations_0_sprites_4_ADDRESS 0x7A5Eu    /* 061A5E */
#define skinner_animations_1_ADDRESS 0x7A70u    /* 061A70 */
#define skinner_animations_1_sprites_ADDRESS 0x7A8Cu    /* 061A8C */
#define skinner_animations_1_sprites_2_ADDRESS 0x7AAAu    /* 061AAA */
#define skinner_animations_1_sprites_3_ADDRESS 0x7AC8u    /* 061AC8 */
#define skinner_animations_1_sprites_4_ADDRESS 0x7AE6u    /* 061AE6 */
#define skinner_animations_2_ADDRESS 0x7B04u    /* 061B04 */
#define skinner_animations_2_sprites_ADDRESS 0x7B10u    /* 061B10 */
#define skinner_animations_2_sprites_2_ADDRESS 0x7B28u    /* 061B28 */
#define skinner_animations_3_ADDRESS 0x7B40u    /* 061B40 */
#define skinner_animations_3_sprites_ADDRESS 0x7B4Cu    /* 061B4C */
#define skinner_animations_3_sprites_2_ADDRESS 0x7B6Au    /* 061B6A */
#define skinner_animations_4_ADDRESS 0x7B82u    /* 061B82 */
#define skinner_animations_4_sprites_ADDRESS 0x7B8Eu    /* 061B8E */
#define skinner_animations_4_sprites_2_ADDRESS 0x7B94u    /* 061B94 */
#define skinner_animations_5_ADDRESS 0x7BA0u    /* 061BA0 */
#define skinner_animations_5_sprites_ADDRESS 0x7BC0u    /* 061BC0 */
#define skinner_animations_5_sprites_2_ADDRESS 0x7BCCu    /* 061BCC */
#define skinner_animations_5_sprites_3_ADDRESS 0x7BD8u    /* 061BD8 */
#define skinner_animations_6_ADDRESS 0x7BE4u    /* 061BE4 */
#define skinner_animations_6_sprites_ADDRESS 0x7C08u    /* 061C08 */
#define skinner_animations_6_sprites_2_ADDRESS 0x7C26u    /* 061C26 */
#define skinner_animations_6_sprites_3_ADDRESS 0x7C3Eu    /* 061C3E */
#define skinner_animations_6_sprites_4_ADDRESS 0x7C4Au    /* 061C4A */
#define skinner_animations_6_sprites_5_ADDRESS 0x7C62u    /* 061C62 */
#define sideshow_bob_animations_ADDRESS 0x7C86u    /* 061C86 */
#define sideshow_bob_animations_0_ADDRESS 0x7C8Eu    /* 061C8E */
#define sideshow_bob_animations_0_sprites_ADDRESS 0x7CB2u    /* 061CB2 */
#define sideshow_bob_animations_0_sprites_2_ADDRESS 0x7CCAu    /* 061CCA */
#define sideshow_bob_animations_0_sprites_3_ADDRESS 0x7CE2u    /* 061CE2 */
#define sideshow_bob_animations_0_sprites_4_ADDRESS 0x7CFAu    /* 061CFA */
#define sideshow_bob_animations_0_sprites_5_ADDRESS 0x7D12u    /* 061D12 */
#define sideshow_bob_animations_1_ADDRESS 0x7D2Au    /* 061D2A */
#define sideshow_bob_animations_1_sprites_ADDRESS 0x7D4Eu    /* 061D4E */
#define sideshow_bob_animations_1_sprites_2_ADDRESS 0x7D6Cu    /* 061D6C */
#define sideshow_bob_animations_1_sprites_3_ADDRESS 0x7D8Au    /* 061D8A */
#define sideshow_bob_animations_1_sprites_4_ADDRESS 0x7DA8u    /* 061DA8 */
#define sideshow_bob_animations_1_sprites_5_ADDRESS 0x7DC6u    /* 061DC6 */
#define sideshow_bob_animations_2_ADDRESS 0x7DE4u    /* 061DE4 */
#define sideshow_bob_animations_2_sprites_ADDRESS 0x7DFCu    /* 061DFC */
#define sideshow_bob_animations_2_sprites_2_ADDRESS 0x7E14u    /* 061E14 */
#define sideshow_bob_animations_3_ADDRESS 0x7E2Cu    /* 061E2C */
#define sideshow_bob_animations_3_sprites_ADDRESS 0x7E44u    /* 061E44 */
#define sideshow_bob_animations_3_sprites_2_ADDRESS 0x7E62u    /* 061E62 */
#define sideshow_bob_animations_3_sprites_2_fill_ADDRESS 0x7E80u    /* 061E80 */
#define sideshow_bob_animations_3_sprites_2_rest_ADDRESS 0x7EA4u    /* 061EA4 */
#define sideshow_bob_animations_3_sprites_2_rest_2_ADDRESS 0x7EB0u    /* 061EB0 */
#define sideshow_bob_animations_3_sprites_2_rest_3_ADDRESS 0x7EDAu    /* 061EDA */
#define sideshow_bob_animations_3_sprites_2_rest_4_ADDRESS 0x7F04u    /* 061F04 */
#define sideshow_bob_animations_3_sprites_2_rest_5_ADDRESS 0x7F0Cu    /* 061F0C */
#define sideshow_bob_animations_3_sprites_2_rest_6_ADDRESS 0x7F12u    /* 061F12 */
#define sideshow_bob_animations_3_sprites_2_rest_7_ADDRESS 0x7F1Au    /* 061F1A */
#define sideshow_bob_animations_3_sprites_2_rest_8_ADDRESS 0x7F38u    /* 061F38 */
#define sideshow_bob_animations_3_sprites_2_rest_9_ADDRESS 0x7F40u    /* 061F40 */
#define sideshow_bob_animations_3_sprites_2_rest_10_ADDRESS 0x7F58u    /* 061F58 */
#define sideshow_bob_animations_3_sprites_2_rest_11_ADDRESS 0x7F60u    /* 061F60 */
#define sideshow_bob_animations_3_sprites_2_fill_2_ADDRESS 0x7F6Cu    /* 061F6C */
#define sideshow_bob_animations_3_sprites_2_rest_12_ADDRESS 0x7F6Eu    /* 061F6E */
#define sideshow_bob_animations_3_sprites_2_rest_13_ADDRESS 0x7F76u    /* 061F76 */
#define sideshow_bob_animations_3_sprites_2_rest_14_ADDRESS 0x7F7Cu    /* 061F7C */
#define sideshow_bob_animations_3_sprites_2_rest_15_ADDRESS 0x7F84u    /* 061F84 */
#define sideshow_bob_animations_3_sprites_2_rest_16_ADDRESS 0x7F8Au    /* 061F8A */
#define sideshow_bob_animations_3_sprites_2_rest_17_ADDRESS 0x7F92u    /* 061F92 */
#define sideshow_bob_animations_3_sprites_2_rest_18_ADDRESS 0x7F9Eu    /* 061F9E */
#define sideshow_bob_animations_3_sprites_2_rest_19_ADDRESS 0x7FAAu    /* 061FAA */
#define sideshow_bob_animations_3_sprites_2_rest_20_ADDRESS 0x7FB0u    /* 061FB0 */
#define sideshow_bob_animations_3_sprites_2_rest_21_ADDRESS 0x7FB6u    /* 061FB6 */
#define sideshow_bob_animations_3_sprites_2_rest_22_ADDRESS 0x7FBEu    /* 061FBE */
#define sideshow_bob_animations_3_sprites_2_rest_23_ADDRESS 0x7FC4u    /* 061FC4 */
#define sideshow_bob_animations_3_sprites_2_rest_24_ADDRESS 0x7FCCu    /* 061FCC */
#define sideshow_bob_animations_3_sprites_2_rest_25_ADDRESS 0x7FD2u    /* 061FD2 */
#define sideshow_bob_animations_3_sprites_2_rest_26_ADDRESS 0x7FDAu    /* 061FDA */
#define sideshow_bob_animations_3_sprites_2_rest_27_ADDRESS 0x7FE0u    /* 061FE0 */
#define sideshow_bob_animations_3_sprites_2_rest_28_ADDRESS 0x7FE8u    /* 061FE8 */
#define sideshow_bob_animations_3_sprites_2_fill_3_ADDRESS 0x7FEEu    /* 061FEE */
#define sideshow_bob_animations_3_sprites_2_rest_29_ADDRESS 0x6000u    /* 062000 */
#define homer_animations_ADDRESS 0x600Au    /* 06200A */
#define homer_animations_7_ADDRESS 0x60ECu    /* 0620EC */
#define homer_animations_7_sprites_ADDRESS 0x60F4u    /* 0620F4 */
#define homer_animations_63_ADDRESS 0x6100u    /* 062100 */
#define homer_animations_63_sprites_ADDRESS 0x6108u    /* 062108 */
#define homer_animations_38_ADDRESS 0x610Eu    /* 06210E */
#define homer_animations_38_sprites_ADDRESS 0x6116u    /* 062116 */
#define homer_animations_0_ADDRESS 0x611Cu    /* 06211C */
#define homer_animations_0_sprites_ADDRESS 0x6124u    /* 062124 */
#define homer_animations_1_ADDRESS 0x6136u    /* 062136 */
#define homer_animations_1_sprites_ADDRESS 0x615Au    /* 06215A */
#define homer_animations_1_sprites_2_ADDRESS 0x616Cu    /* 06216C */
#define homer_animations_1_sprites_3_ADDRESS 0x617Eu    /* 06217E */
#define homer_animations_1_sprites_4_ADDRESS 0x6190u    /* 062190 */
#define homer_animations_1_sprites_5_ADDRESS 0x61A2u    /* 0621A2 */
#define homer_animations_1_sprites_6_ADDRESS 0x61B4u    /* 0621B4 */
#define homer_animations_1_sprites_7_ADDRESS 0x61C6u    /* 0621C6 */
#define homer_animations_1_sprites_8_ADDRESS 0x61D8u    /* 0621D8 */
#define homer_animations_2_ADDRESS 0x61EAu    /* 0621EA */
#define homer_animations_2_sprites_ADDRESS 0x620Eu    /* 06220E */
#define homer_animations_2_sprites_2_ADDRESS 0x621Au    /* 06221A */
#define homer_animations_2_sprites_3_ADDRESS 0x6220u    /* 062220 */
#define homer_animations_2_sprites_4_ADDRESS 0x6226u    /* 062226 */
#define homer_animations_2_sprites_5_ADDRESS 0x622Cu    /* 06222C */
#define homer_animations_2_sprites_6_ADDRESS 0x6238u    /* 062238 */
#define homer_animations_2_sprites_7_ADDRESS 0x623Eu    /* 06223E */
#define homer_animations_2_sprites_8_ADDRESS 0x6244u    /* 062244 */
#define homer_animations_3_ADDRESS 0x624Au    /* 06224A */
#define homer_animations_3_sprites_ADDRESS 0x6252u    /* 062252 */
#define homer_animations_4_ADDRESS 0x626Au    /* 06226A */
#define homer_animations_4_sprites_ADDRESS 0x6272u    /* 062272 */
#define homer_animations_5_ADDRESS 0x628Au    /* 06228A */
#define homer_animations_5_sprites_ADDRESS 0x6292u    /* 062292 */
#define homer_animations_8_ADDRESS 0x62AAu    /* 0622AA */
#define homer_animations_8_sprites_ADDRESS 0x62B2u    /* 0622B2 */
#define homer_animations_9_ADDRESS 0x62C4u    /* 0622C4 */
#define homer_animations_9_sprites_ADDRESS 0x62E8u    /* 0622E8 */
#define homer_animations_9_sprites_2_ADDRESS 0x62FAu    /* 0622FA */
#define homer_animations_9_sprites_3_ADDRESS 0x630Cu    /* 06230C */
#define homer_animations_9_sprites_4_ADDRESS 0x631Eu    /* 06231E */
#define homer_animations_9_sprites_5_ADDRESS 0x6330u    /* 062330 */
#define homer_animations_9_sprites_6_ADDRESS 0x6342u    /* 062342 */
#define homer_animations_9_sprites_7_ADDRESS 0x6354u    /* 062354 */
#define homer_animations_9_sprites_8_ADDRESS 0x6366u    /* 062366 */
#define homer_animations_11_ADDRESS 0x6378u    /* 062378 */
#define homer_animations_11_sprites_ADDRESS 0x6380u    /* 062380 */
#define homer_animations_12_ADDRESS 0x6392u    /* 062392 */
#define homer_animations_12_sprites_ADDRESS 0x639Au    /* 06239A */
#define homer_animations_13_ADDRESS 0x63ACu    /* 0623AC */
#define homer_animations_16_ADDRESS 0x63B4u    /* 0623B4 */
#define homer_animations_16_sprites_ADDRESS 0x63BCu    /* 0623BC */
#define homer_animations_17_ADDRESS 0x63C8u    /* 0623C8 */
#define homer_animations_17_sprites_ADDRESS 0x63ECu    /* 0623EC */
#define homer_animations_17_sprites_2_ADDRESS 0x63F8u    /* 0623F8 */
#define homer_animations_17_sprites_3_ADDRESS 0x6404u    /* 062404 */
#define homer_animations_17_sprites_4_ADDRESS 0x6410u    /* 062410 */
#define homer_animations_17_sprites_5_ADDRESS 0x641Cu    /* 06241C */
#define homer_animations_17_sprites_6_ADDRESS 0x6428u    /* 062428 */
#define homer_animations_17_sprites_7_ADDRESS 0x6434u    /* 062434 */
#define homer_animations_17_sprites_8_ADDRESS 0x6440u    /* 062440 */
#define homer_animations_19_ADDRESS 0x644Cu    /* 06244C */
#define homer_animations_19_sprites_ADDRESS 0x6454u    /* 062454 */
#define homer_animations_20_ADDRESS 0x6460u    /* 062460 */
#define homer_animations_20_sprites_ADDRESS 0x6468u    /* 062468 */
#define homer_animations_21_ADDRESS 0x6474u    /* 062474 */
#define homer_animations_47_ADDRESS 0x647Cu    /* 06247C */
#define homer_animations_47_sprites_ADDRESS 0x6498u    /* 062498 */
#define homer_animations_47_sprites_2_ADDRESS 0x64AAu    /* 0624AA */
#define homer_animations_47_sprites_3_ADDRESS 0x64BCu    /* 0624BC */
#define homer_animations_48_ADDRESS 0x64CEu    /* 0624CE */
#define homer_animations_55_sprites_5_ADDRESS 0x64DAu    /* 0624DA */
#define homer_animations_55_sprites_6_ADDRESS 0x64ECu    /* 0624EC */
#define homer_animations_48_sprites_ADDRESS 0x6504u    /* 062504 */
#define homer_animations_48_sprites_2_ADDRESS 0x6516u    /* 062516 */
#define homer_animations_49_ADDRESS 0x652Eu    /* 06252E */
#define homer_animations_49_sprites_ADDRESS 0x653Au    /* 06253A */
#define homer_animations_53_ADDRESS 0x6546u    /* 062546 */
#define homer_animations_53_sprites_ADDRESS 0x656Au    /* 06256A */
#define homer_animations_53_sprites_2_ADDRESS 0x657Cu    /* 06257C */
#define homer_animations_53_sprites_3_ADDRESS 0x658Eu    /* 06258E */
#define homer_animations_53_sprites_4_ADDRESS 0x65A0u    /* 0625A0 */
#define homer_animations_53_sprites_5_ADDRESS 0x65B2u    /* 0625B2 */
#define homer_animations_53_sprites_6_ADDRESS 0x65C4u    /* 0625C4 */
#define homer_animations_53_sprites_7_ADDRESS 0x65D6u    /* 0625D6 */
#define homer_animations_53_sprites_8_ADDRESS 0x65E8u    /* 0625E8 */
#define homer_animations_54_ADDRESS 0x65FAu    /* 0625FA */
#define homer_animations_54_sprites_ADDRESS 0x660Eu    /* 06260E */
#define homer_animations_54_sprites_2_ADDRESS 0x6620u    /* 062620 */
#define homer_animations_54_sprites_3_ADDRESS 0x6632u    /* 062632 */
#define homer_animations_54_sprites_4_ADDRESS 0x6644u    /* 062644 */
#define homer_animations_55_ADDRESS 0x6656u    /* 062656 */
#define homer_animations_55_sprites_ADDRESS 0x667Au    /* 06267A */
#define homer_animations_55_sprites_2_ADDRESS 0x668Cu    /* 06268C */
#define homer_animations_55_sprites_3_ADDRESS 0x669Eu    /* 06269E */
#define homer_animations_55_sprites_4_ADDRESS 0x66B0u    /* 0626B0 */
#define homer_animations_56_ADDRESS 0x66C2u    /* 0626C2 */
#define homer_animations_56_sprites_ADDRESS 0x66EAu    /* 0626EA */
#define homer_animations_56_sprites_2_ADDRESS 0x66FCu    /* 0626FC */
#define homer_animations_56_sprites_3_ADDRESS 0x670Eu    /* 06270E */
#define homer_animations_57_ADDRESS 0x6726u    /* 062726 */
#define homer_animations_57_sprites_ADDRESS 0x6756u    /* 062756 */
#define homer_animations_57_sprites_2_ADDRESS 0x675Cu    /* 06275C */
#define homer_animations_57_sprites_3_ADDRESS 0x6762u    /* 062762 */
#define homer_animations_57_sprites_4_ADDRESS 0x6768u    /* 062768 */
#define homer_animations_57_sprites_5_ADDRESS 0x676Eu    /* 06276E */
#define homer_animations_57_sprites_6_ADDRESS 0x6774u    /* 062774 */
#define homer_animations_57_sprites_7_ADDRESS 0x677Au    /* 06277A */
#define homer_animations_96_ADDRESS 0x6780u    /* 062780 */
#define homer_animations_96_sprites_ADDRESS 0x67A4u    /* 0627A4 */
#define homer_animations_96_sprites_2_ADDRESS 0x67BCu    /* 0627BC */
#define homer_animations_96_sprites_3_ADDRESS 0x67DAu    /* 0627DA */
#define homer_animations_96_sprites_4_ADDRESS 0x67F2u    /* 0627F2 */
#define homer_animations_96_sprites_5_ADDRESS 0x680Au    /* 06280A */
#define homer_animations_96_sprites_6_ADDRESS 0x681Cu    /* 06281C */
#define homer_animations_97_ADDRESS 0x6834u    /* 062834 */
#define homer_animations_97_sprites_ADDRESS 0x683Cu    /* 06283C */
#define homer_animations_98_ADDRESS 0x684Eu    /* 06284E */
#define homer_animations_98_sprites_ADDRESS 0x6872u    /* 062872 */
#define homer_animations_98_sprites_2_ADDRESS 0x6884u    /* 062884 */
#define homer_animations_98_sprites_3_ADDRESS 0x6896u    /* 062896 */
#define homer_animations_98_sprites_4_ADDRESS 0x68A8u    /* 0628A8 */
#define homer_animations_98_sprites_5_ADDRESS 0x68BAu    /* 0628BA */
#define homer_animations_98_sprites_6_ADDRESS 0x68CCu    /* 0628CC */
#define homer_animations_98_sprites_7_ADDRESS 0x68DEu    /* 0628DE */
#define homer_animations_98_sprites_8_ADDRESS 0x68F0u    /* 0628F0 */
#define homer_animations_100_ADDRESS 0x6902u    /* 062902 */
#define homer_animations_100_sprites_ADDRESS 0x690Au    /* 06290A */
#define homer_animations_101_ADDRESS 0x691Cu    /* 06291C */
#define homer_animations_101_sprites_ADDRESS 0x6924u    /* 062924 */
#define homer_animations_102_ADDRESS 0x6936u    /* 062936 */
#define homer_animations_102_sprites_ADDRESS 0x693Eu    /* 06293E */
#define homer_animations_112_ADDRESS 0x6950u    /* 062950 */
#define homer_animations_112_sprites_ADDRESS 0x6964u    /* 062964 */
#define homer_animations_112_sprites_2_ADDRESS 0x697Cu    /* 06297C */
#define homer_animations_112_sprites_3_ADDRESS 0x6994u    /* 062994 */
#define homer_animations_112_sprites_4_ADDRESS 0x69A6u    /* 0629A6 */
#define homer_animations_58_ADDRESS 0x69B8u    /* 0629B8 */
#define homer_animations_58_sprites_ADDRESS 0x69C4u    /* 0629C4 */
#define homer_animations_58_sprites_2_ADDRESS 0x69CAu    /* 0629CA */
#define homer_animations_59_ADDRESS 0x69D0u    /* 0629D0 */
#define homer_animations_59_sprites_ADDRESS 0x69DCu    /* 0629DC */
#define homer_animations_59_sprites_2_ADDRESS 0x69E8u    /* 0629E8 */
#define homer_animations_61_ADDRESS 0x69F4u    /* 0629F4 */
#define homer_animations_61_sprites_ADDRESS 0x69FCu    /* 0629FC */
#define homer_animations_62_ADDRESS 0x6A08u    /* 062A08 */
#define homer_animations_62_sprites_ADDRESS 0x6A14u    /* 062A14 */
#define homer_animations_62_sprites_2_ADDRESS 0x6A20u    /* 062A20 */
#define homer_animations_69_ADDRESS 0x6A38u    /* 062A38 */
#define homer_animations_69_sprites_ADDRESS 0x6A44u    /* 062A44 */
#define homer_animations_69_sprites_2_ADDRESS 0x6A50u    /* 062A50 */
#define homer_animations_70_ADDRESS 0x6A5Cu    /* 062A5C */
#define homer_animations_70_sprites_ADDRESS 0x6A68u    /* 062A68 */
#define homer_animations_70_sprites_2_ADDRESS 0x6A7Au    /* 062A7A */
#define homer_animations_89_ADDRESS 0x6A8Cu    /* 062A8C */
#define homer_animations_89_sprites_ADDRESS 0x6A98u    /* 062A98 */
#define homer_animations_89_sprites_2_ADDRESS 0x6AA4u    /* 062AA4 */
#define homer_animations_80_ADDRESS 0x6AB6u    /* 062AB6 */
#define homer_animations_80_sprites_ADDRESS 0x6AC2u    /* 062AC2 */
#define homer_animations_80_sprites_2_ADDRESS 0x6ACEu    /* 062ACE */
#define homer_animations_81_ADDRESS 0x6ADAu    /* 062ADA */
#define homer_animations_81_sprites_ADDRESS 0x6AE6u    /* 062AE6 */
#define homer_animations_81_sprites_2_ADDRESS 0x6AF2u    /* 062AF2 */
#define homer_animations_82_ADDRESS 0x6AF8u    /* 062AF8 */
#define homer_animations_82_sprites_ADDRESS 0x6B04u    /* 062B04 */
#define homer_animations_82_sprites_2_ADDRESS 0x6B0Au    /* 062B0A */
#define homer_animations_83_ADDRESS 0x6B16u    /* 062B16 */
#define homer_animations_83_sprites_ADDRESS 0x6B2Au    /* 062B2A */
#define homer_animations_83_sprites_2_ADDRESS 0x6B36u    /* 062B36 */
#define homer_animations_83_sprites_3_ADDRESS 0x6B42u    /* 062B42 */
#define homer_animations_83_sprites_4_ADDRESS 0x6B4Eu    /* 062B4E */
#define homer_animations_84_ADDRESS 0x6B5Au    /* 062B5A */
#define homer_animations_84_sprites_ADDRESS 0x6B6Eu    /* 062B6E */
#define homer_animations_84_sprites_2_ADDRESS 0x6B7Au    /* 062B7A */
#define homer_animations_84_sprites_3_ADDRESS 0x6B86u    /* 062B86 */
#define homer_animations_84_sprites_4_ADDRESS 0x6B92u    /* 062B92 */
#define homer_animations_85_ADDRESS 0x6B9Eu    /* 062B9E */
#define homer_animations_85_sprites_ADDRESS 0x6BB2u    /* 062BB2 */
#define homer_animations_85_sprites_2_ADDRESS 0x6BBEu    /* 062BBE */
#define homer_animations_85_sprites_3_ADDRESS 0x6BC4u    /* 062BC4 */
#define homer_animations_85_sprites_4_ADDRESS 0x6BCAu    /* 062BCA */
#define homer_animations_86_ADDRESS 0x6BD0u    /* 062BD0 */
#define homer_animations_86_sprites_ADDRESS 0x6BDCu    /* 062BDC */
#define homer_animations_86_sprites_2_ADDRESS 0x6BE8u    /* 062BE8 */
#define homer_animations_87_ADDRESS 0x6BFAu    /* 062BFA */
#define homer_animations_87_sprites_ADDRESS 0x6C02u    /* 062C02 */
#define homer_animations_88_ADDRESS 0x6C08u    /* 062C08 */
#define homer_animations_88_sprites_ADDRESS 0x6C28u    /* 062C28 */
#define homer_animations_88_sprites_2_ADDRESS 0x6C34u    /* 062C34 */
#define homer_animations_88_sprites_3_ADDRESS 0x6C40u    /* 062C40 */
#define homer_animations_88_sprites_4_ADDRESS 0x6C46u    /* 062C46 */
#define homer_animations_88_sprites_5_ADDRESS 0x6C64u    /* 062C64 */
#define homer_animations_88_sprites_6_ADDRESS 0x6C7Cu    /* 062C7C */
#define homer_animations_88_sprites_7_ADDRESS 0x6C8Eu    /* 062C8E */
#define homer_animations_91_ADDRESS 0x6C9Au    /* 062C9A */
#define homer_animations_91_sprites_ADDRESS 0x6CAEu    /* 062CAE */
#define homer_animations_91_sprites_2_ADDRESS 0x6CBAu    /* 062CBA */
#define homer_animations_91_sprites_3_ADDRESS 0x6CC6u    /* 062CC6 */
#define homer_animations_91_sprites_4_ADDRESS 0x6CD8u    /* 062CD8 */
#define homer_animations_94_ADDRESS 0x6CEAu    /* 062CEA */
#define homer_animations_94_sprites_ADDRESS 0x6CF6u    /* 062CF6 */
#define homer_animations_92_ADDRESS 0x6D08u    /* 062D08 */
#define homer_animations_92_sprites_ADDRESS 0x6D18u    /* 062D18 */
#define homer_animations_92_sprites_2_ADDRESS 0x6D24u    /* 062D24 */
#define homer_animations_92_sprites_3_ADDRESS 0x6D30u    /* 062D30 */
#define homer_animations_93_ADDRESS 0x6D36u    /* 062D36 */
#define homer_animations_93_sprites_ADDRESS 0x6D46u    /* 062D46 */
#define homer_animations_93_sprites_2_ADDRESS 0x6D52u    /* 062D52 */
#define homer_animations_95_ADDRESS 0x6D5Eu    /* 062D5E */
#define homer_animations_95_sprites_ADDRESS 0x6D72u    /* 062D72 */
#define homer_animations_95_sprites_2_ADDRESS 0x6D7Eu    /* 062D7E */
#define homer_animations_95_sprites_3_ADDRESS 0x6D8Au    /* 062D8A */
#define homer_animations_95_sprites_4_ADDRESS 0x6D96u    /* 062D96 */
#define homer_animations_15_ADDRESS 0x6DA2u    /* 062DA2 */
#define homer_animations_15_sprites_ADDRESS 0x6DAEu    /* 062DAE */
#define homer_animations_15_sprites_2_ADDRESS 0x6DC6u    /* 062DC6 */
#define homer_animations_23_ADDRESS 0x6DD2u    /* 062DD2 */
#define homer_animations_23_sprites_ADDRESS 0x6DDEu    /* 062DDE */
#define homer_animations_23_sprites_2_ADDRESS 0x6DF0u    /* 062DF0 */
#define homer_animations_31_ADDRESS 0x6E02u    /* 062E02 */
#define homer_animations_31_sprites_ADDRESS 0x6E26u    /* 062E26 */
#define homer_animations_31_sprites_2_ADDRESS 0x6E32u    /* 062E32 */
#define homer_animations_31_sprites_3_ADDRESS 0x6E3Eu    /* 062E3E */
#define homer_animations_31_sprites_4_ADDRESS 0x6E4Au    /* 062E4A */
#define homer_animations_78_ADDRESS 0x6E56u    /* 062E56 */
#define homer_animations_78_sprites_ADDRESS 0x6E5Eu    /* 062E5E */
#define homer_animations_64_ADDRESS 0x6E6Au    /* 062E6A */
#define homer_animations_64_sprites_ADDRESS 0x6E76u    /* 062E76 */
#define homer_animations_64_sprites_2_ADDRESS 0x6E88u    /* 062E88 */
#define homer_animations_65_ADDRESS 0x6E9Au    /* 062E9A */
#define homer_animations_65_sprites_ADDRESS 0x6EA6u    /* 062EA6 */
#define homer_animations_65_sprites_2_ADDRESS 0x6EB2u    /* 062EB2 */
#define homer_animations_32_ADDRESS 0x6EC4u    /* 062EC4 */
#define homer_animations_32_sprites_ADDRESS 0x6ECCu    /* 062ECC */
#define homer_animations_33_ADDRESS 0x6EEAu    /* 062EEA */
#define homer_animations_33_sprites_ADDRESS 0x6F0Eu    /* 062F0E */
#define homer_animations_33_sprites_2_ADDRESS 0x6F2Cu    /* 062F2C */
#define homer_animations_33_sprites_3_ADDRESS 0x6F4Au    /* 062F4A */
#define homer_animations_33_sprites_4_ADDRESS 0x6F68u    /* 062F68 */
#define homer_animations_33_sprites_5_ADDRESS 0x6F86u    /* 062F86 */
#define homer_animations_33_sprites_6_ADDRESS 0x6FA4u    /* 062FA4 */
#define homer_animations_33_sprites_7_ADDRESS 0x6FC2u    /* 062FC2 */
#define homer_animations_33_sprites_8_ADDRESS 0x6FE0u    /* 062FE0 */
#define homer_animations_35_ADDRESS 0x6FFEu    /* 062FFE */
#define homer_animations_35_sprites_ADDRESS 0x7006u    /* 063006 */
#define homer_animations_36_ADDRESS 0x7024u    /* 063024 */
#define homer_animations_36_sprites_ADDRESS 0x702Cu    /* 06302C */
#define homer_animations_37_ADDRESS 0x704Au    /* 06304A */
#define homer_animations_51_ADDRESS 0x7052u    /* 063052 */
#define homer_animations_51_sprites_ADDRESS 0x7062u    /* 063062 */
#define homer_animations_51_sprites_2_ADDRESS 0x7074u    /* 063074 */
#define homer_animations_51_sprites_3_ADDRESS 0x7086u    /* 063086 */
#define homer_animations_67_ADDRESS 0x709Eu    /* 06309E */
#define homer_animations_67_sprites_ADDRESS 0x70AEu    /* 0630AE */
#define homer_animations_67_sprites_2_ADDRESS 0x70C0u    /* 0630C0 */
#define homer_animations_67_sprites_3_ADDRESS 0x70D8u    /* 0630D8 */
#define homer_animations_24_ADDRESS 0x70F0u    /* 0630F0 */
#define homer_animations_24_sprites_ADDRESS 0x70F8u    /* 0630F8 */
#define homer_animations_25_ADDRESS 0x7110u    /* 063110 */
#define homer_animations_25_sprites_ADDRESS 0x7134u    /* 063134 */
#define homer_animations_25_sprites_2_ADDRESS 0x714Cu    /* 06314C */
#define homer_animations_25_sprites_3_ADDRESS 0x7164u    /* 063164 */
#define homer_animations_25_sprites_4_ADDRESS 0x717Cu    /* 06317C */
#define homer_animations_25_sprites_5_ADDRESS 0x7194u    /* 063194 */
#define homer_animations_25_sprites_6_ADDRESS 0x71ACu    /* 0631AC */
#define homer_animations_25_sprites_7_ADDRESS 0x71C4u    /* 0631C4 */
#define homer_animations_25_sprites_8_ADDRESS 0x71DCu    /* 0631DC */
#define homer_animations_27_ADDRESS 0x71F4u    /* 0631F4 */
#define homer_animations_27_sprites_ADDRESS 0x71FCu    /* 0631FC */
#define homer_animations_28_ADDRESS 0x721Au    /* 06321A */
#define homer_animations_28_sprites_ADDRESS 0x7222u    /* 063222 */
#define homer_animations_29_ADDRESS 0x7240u    /* 063240 */
#define homer_animations_29_sprites_ADDRESS 0x724Cu    /* 06324C */
#define homer_animations_29_sprites_2_ADDRESS 0x726Au    /* 06326A */
#define homer_animations_50_ADDRESS 0x7288u    /* 063288 */
#define homer_animations_50_sprites_ADDRESS 0x729Cu    /* 06329C */
#define homer_animations_50_sprites_2_ADDRESS 0x72B4u    /* 0632B4 */
#define homer_animations_50_sprites_3_ADDRESS 0x72CCu    /* 0632CC */
#define homer_animations_50_sprites_4_ADDRESS 0x72DEu    /* 0632DE */
#define homer_animations_66_ADDRESS 0x72F6u    /* 0632F6 */
#define homer_animations_66_sprites_ADDRESS 0x730Au    /* 06330A */
#define homer_animations_66_sprites_2_ADDRESS 0x7322u    /* 063322 */
#define homer_animations_66_sprites_3_ADDRESS 0x733Au    /* 06333A */
#define homer_animations_66_sprites_4_ADDRESS 0x734Cu    /* 06334C */
#define homer_animations_40_ADDRESS 0x7364u    /* 063364 */
#define homer_animations_40_sprites_ADDRESS 0x736Cu    /* 06336C */
#define homer_animations_41_ADDRESS 0x737Eu    /* 06337E */
#define homer_animations_41_sprites_ADDRESS 0x73A2u    /* 0633A2 */
#define homer_animations_41_sprites_2_ADDRESS 0x73B4u    /* 0633B4 */
#define homer_animations_41_sprites_3_ADDRESS 0x73C6u    /* 0633C6 */
#define homer_animations_41_sprites_4_ADDRESS 0x73D8u    /* 0633D8 */
#define homer_animations_41_sprites_5_ADDRESS 0x73EAu    /* 0633EA */
#define homer_animations_41_sprites_6_ADDRESS 0x73FCu    /* 0633FC */
#define homer_animations_41_sprites_7_ADDRESS 0x740Eu    /* 06340E */
#define homer_animations_41_sprites_8_ADDRESS 0x7420u    /* 063420 */
#define homer_animations_43_ADDRESS 0x7432u    /* 063432 */
#define homer_animations_43_sprites_ADDRESS 0x743Au    /* 06343A */
#define homer_animations_44_ADDRESS 0x744Cu    /* 06344C */
#define homer_animations_44_sprites_ADDRESS 0x7454u    /* 063454 */
#define homer_animations_45_ADDRESS 0x7466u    /* 063466 */
#define homer_animations_52_ADDRESS 0x746Eu    /* 06346E */
#define homer_animations_52_sprites_ADDRESS 0x747Eu    /* 06347E */
#define homer_animations_52_sprites_2_ADDRESS 0x7490u    /* 063490 */
#define homer_animations_52_sprites_3_ADDRESS 0x74A2u    /* 0634A2 */
#define homer_animations_68_ADDRESS 0x74B4u    /* 0634B4 */
#define homer_animations_68_sprites_ADDRESS 0x74C4u    /* 0634C4 */
#define homer_animations_68_sprites_2_ADDRESS 0x74D6u    /* 0634D6 */
#define homer_animations_68_sprites_3_ADDRESS 0x74E8u    /* 0634E8 */
#define homer_animations_73_ADDRESS 0x74FAu    /* 0634FA */
#define homer_animations_73_sprites_ADDRESS 0x7506u    /* 063506 */
#define homer_animations_73_sprites_2_ADDRESS 0x7512u    /* 063512 */
#define homer_animations_75_ADDRESS 0x751Eu    /* 06351E */
#define homer_animations_75_sprites_ADDRESS 0x7526u    /* 063526 */
#define homer_animations_77_ADDRESS 0x752Cu    /* 06352C */
#define homer_animations_77_sprites_ADDRESS 0x7538u    /* 063538 */
#define homer_animations_14_ADDRESS 0x754Au    /* 06354A */
#define homer_animations_14_sprites_ADDRESS 0x7552u    /* 063552 */
#define homer_animations_104_ADDRESS 0x7558u    /* 063558 */
#define homer_animations_104_sprites_ADDRESS 0x756Cu    /* 06356C */
#define homer_animations_104_sprites_2_ADDRESS 0x757Eu    /* 06357E */
#define homer_animations_104_sprites_3_ADDRESS 0x7590u    /* 063590 */
#define homer_animations_104_sprites_4_ADDRESS 0x75A2u    /* 0635A2 */
#define homer_animations_6_ADDRESS 0x75B4u    /* 0635B4 */
#define homer_animations_6_sprites_ADDRESS 0x75C8u    /* 0635C8 */
#define homer_animations_6_sprites_2_ADDRESS 0x75D4u    /* 0635D4 */
#define homer_animations_6_sprites_3_ADDRESS 0x75E6u    /* 0635E6 */
#define homer_animations_6_sprites_4_ADDRESS 0x75F8u    /* 0635F8 */
#define homer_animations_22_ADDRESS 0x760Au    /* 06360A */
#define homer_animations_22_sprites_ADDRESS 0x762Au    /* 06362A */
#define homer_animations_22_sprites_2_ADDRESS 0x7636u    /* 063636 */
#define homer_animations_22_sprites_3_ADDRESS 0x764Eu    /* 06364E */
#define homer_animations_22_sprites_4_ADDRESS 0x7666u    /* 063666 */
#define homer_animations_22_sprites_5_ADDRESS 0x7672u    /* 063672 */
#define homer_animations_22_sprites_6_ADDRESS 0x7684u    /* 063684 */
#define homer_animations_22_sprites_7_ADDRESS 0x7696u    /* 063696 */
#define homer_animations_30_ADDRESS 0x76A8u    /* 0636A8 */
#define homer_animations_30_sprites_ADDRESS 0x76B4u    /* 0636B4 */
#define homer_animations_30_sprites_2_ADDRESS 0x76C6u    /* 0636C6 */
#define homer_animations_39_ADDRESS 0x76D8u    /* 0636D8 */
#define homer_animations_39_sprites_ADDRESS 0x76E4u    /* 0636E4 */
#define homer_animations_39_sprites_2_ADDRESS 0x76F0u    /* 0636F0 */
#define homer_animations_46_ADDRESS 0x76FCu    /* 0636FC */
#define homer_animations_46_sprites_ADDRESS 0x7708u    /* 063708 */
#define homer_animations_46_sprites_2_ADDRESS 0x7714u    /* 063714 */
#define hammer_animations_ADDRESS 0x771Au    /* 06371A */
#define hammer_animations_0_ADDRESS 0x771Eu    /* 06371E */
#define hammer_animations_0_sprites_ADDRESS 0x7726u    /* 063726 */
#define hammer_animations_1_ADDRESS 0x772Cu    /* 06372C */
#define hammer_animations_1_sprites_ADDRESS 0x7734u    /* 063734 */
#define slingshot_animations_ADDRESS 0x7752u    /* 063752 */
#define slingshot_animations_0_ADDRESS 0x7758u    /* 063758 */
#define slingshot_animations_0_sprites_ADDRESS 0x7760u    /* 063760 */
#define slingshot_animations_1_ADDRESS 0x7766u    /* 063766 */
#define slingshot_animations_1_sprites_ADDRESS 0x776Eu    /* 06376E */
#define slingshot_animations_2_ADDRESS 0x778Cu    /* 06378C */
#define slingshot_animations_2_sprites_ADDRESS 0x7794u    /* 063794 */
#define food_animations_ADDRESS 0x779Au    /* 06379A */
#define food_animations_14_ADDRESS 0x77C2u    /* 0637C2 */
#define food_animations_14_sprites_ADDRESS 0x77D6u    /* 0637D6 */
#define food_animations_14_sprites_2_ADDRESS 0x77DCu    /* 0637DC */
#define food_animations_14_sprites_3_ADDRESS 0x77E2u    /* 0637E2 */
#define food_animations_16_ADDRESS 0x77E8u    /* 0637E8 */
#define food_animations_16_sprites_ADDRESS 0x77FCu    /* 0637FC */
#define food_animations_16_sprites_2_ADDRESS 0x7802u    /* 063802 */
#define food_animations_16_sprites_3_ADDRESS 0x7808u    /* 063808 */
#define food_animations_0_ADDRESS 0x780Eu    /* 06380E */
#define food_animations_0_sprites_ADDRESS 0x7816u    /* 063816 */
#define food_animations_1_ADDRESS 0x781Cu    /* 06381C */
#define food_animations_1_sprites_ADDRESS 0x7824u    /* 063824 */
#define food_animations_2_ADDRESS 0x7842u    /* 063842 */
#define food_animations_2_sprites_ADDRESS 0x784Au    /* 06384A */
#define food_animations_3_ADDRESS 0x7850u    /* 063850 */
#define food_animations_3_sprites_ADDRESS 0x7858u    /* 063858 */
#define food_animations_4_ADDRESS 0x7876u    /* 063876 */
#define food_animations_4_sprites_ADDRESS 0x787Eu    /* 06387E */
#define food_animations_5_ADDRESS 0x7884u    /* 063884 */
#define food_animations_5_sprites_ADDRESS 0x788Cu    /* 06388C */
#define food_animations_6_ADDRESS 0x78AAu    /* 0638AA */
#define food_animations_6_sprites_ADDRESS 0x78B2u    /* 0638B2 */
#define food_animations_7_ADDRESS 0x78B8u    /* 0638B8 */
#define food_animations_7_sprites_ADDRESS 0x78C0u    /* 0638C0 */
#define food_animations_10_ADDRESS 0x78DEu    /* 0638DE */
#define food_animations_10_sprites_ADDRESS 0x78E6u    /* 0638E6 */
#define food_animations_11_ADDRESS 0x78ECu    /* 0638EC */
#define food_animations_11_sprites_ADDRESS 0x78F4u    /* 0638F4 */
#define food_animations_12_ADDRESS 0x7912u    /* 063912 */
#define food_animations_12_sprites_ADDRESS 0x791Au    /* 06391A */
#define food_animations_13_ADDRESS 0x7920u    /* 063920 */
#define food_animations_13_sprites_ADDRESS 0x7928u    /* 063928 */
#define food_animations_8_ADDRESS 0x7946u    /* 063946 */
#define food_animations_8_sprites_ADDRESS 0x794Eu    /* 06394E */
#define food_animations_9_ADDRESS 0x7954u    /* 063954 */
#define food_animations_9_sprites_ADDRESS 0x795Cu    /* 06395C */
#define food_animations_18_ADDRESS 0x797Au    /* 06397A */
#define food_animations_18_sprites_ADDRESS 0x7982u    /* 063982 */
#define food_animations_19_ADDRESS 0x7988u    /* 063988 */
#define food_animations_19_sprites_ADDRESS 0x7990u    /* 063990 */
#define maggie_animations_ADDRESS 0x79AEu    /* 0639AE */
#define maggie_animations_0_ADDRESS 0x79C8u    /* 0639C8 */
#define maggie_animations_0_sprites_ADDRESS 0x79D4u    /* 0639D4 */
#define maggie_animations_0_sprites_2_ADDRESS 0x79DAu    /* 0639DA */
#define maggie_animations_1_ADDRESS 0x79E0u    /* 0639E0 */
#define maggie_animations_1_sprites_ADDRESS 0x79FCu    /* 0639FC */
#define maggie_animations_1_sprites_2_ADDRESS 0x7A08u    /* 063A08 */
#define maggie_animations_1_sprites_3_ADDRESS 0x7A14u    /* 063A14 */
#define maggie_animations_1_sprites_4_ADDRESS 0x7A20u    /* 063A20 */
#define maggie_animations_1_sprites_5_ADDRESS 0x7A2Cu    /* 063A2C */
#define maggie_animations_1_sprites_6_ADDRESS 0x7A38u    /* 063A38 */
#define maggie_animations_2_ADDRESS 0x7A44u    /* 063A44 */
#define maggie_animations_2_sprites_ADDRESS 0x7A68u    /* 063A68 */
#define maggie_animations_2_sprites_2_ADDRESS 0x7A7Au    /* 063A7A */
#define maggie_animations_2_sprites_3_ADDRESS 0x7A8Cu    /* 063A8C */
#define maggie_animations_2_sprites_4_ADDRESS 0x7A9Eu    /* 063A9E */
#define maggie_animations_2_sprites_5_ADDRESS 0x7AB0u    /* 063AB0 */
#define maggie_animations_2_sprites_6_ADDRESS 0x7AC2u    /* 063AC2 */
#define maggie_animations_2_sprites_7_ADDRESS 0x7AD4u    /* 063AD4 */
#define maggie_animations_2_sprites_8_ADDRESS 0x7AE6u    /* 063AE6 */
#define maggie_animations_3_ADDRESS 0x7AF8u    /* 063AF8 */
#define maggie_animations_3_sprites_ADDRESS 0x7B0Cu    /* 063B0C */
#define maggie_animations_3_sprites_2_ADDRESS 0x7B12u    /* 063B12 */
#define maggie_animations_3_sprites_3_ADDRESS 0x7B18u    /* 063B18 */
#define maggie_animations_3_sprites_4_ADDRESS 0x7B1Eu    /* 063B1E */
#define maggie_animations_4_ADDRESS 0x7B30u    /* 063B30 */
#define maggie_animations_4_sprites_ADDRESS 0x7B38u    /* 063B38 */
#define maggie_animations_5_ADDRESS 0x7B44u    /* 063B44 */
#define maggie_animations_5_sprites_ADDRESS 0x7B50u    /* 063B50 */
#define maggie_animations_5_sprites_2_ADDRESS 0x7B5Cu    /* 063B5C */
#define maggie_animations_6_ADDRESS 0x7B6Eu    /* 063B6E */
#define maggie_animations_6_sprites_ADDRESS 0x7B82u    /* 063B82 */
#define maggie_animations_6_sprites_2_ADDRESS 0x7B8Eu    /* 063B8E */
#define maggie_animations_6_sprites_3_ADDRESS 0x7B9Au    /* 063B9A */
#define maggie_animations_7_ADDRESS 0x7BA6u    /* 063BA6 */
#define maggie_animations_7_sprites_ADDRESS 0x7BBAu    /* 063BBA */
#define maggie_animations_7_sprites_2_ADDRESS 0x7BC6u    /* 063BC6 */
#define maggie_animations_7_sprites_3_ADDRESS 0x7BD2u    /* 063BD2 */
#define maggie_animations_8_ADDRESS 0x7BDEu    /* 063BDE */
#define maggie_animations_8_sprites_ADDRESS 0x7BF6u    /* 063BF6 */
#define maggie_animations_8_sprites_2_ADDRESS 0x7C02u    /* 063C02 */
#define maggie_animations_8_sprites_3_ADDRESS 0x7C0Eu    /* 063C0E */
#define maggie_animations_8_sprites_4_ADDRESS 0x7C1Au    /* 063C1A */
#define maggie_animations_8_sprites_5_ADDRESS 0x7C26u    /* 063C26 */
#define maggie_animations_9_ADDRESS 0x7C32u    /* 063C32 */
#define maggie_animations_9_sprites_ADDRESS 0x7C42u    /* 063C42 */
#define maggie_animations_9_sprites_2_ADDRESS 0x7C4Eu    /* 063C4E */
#define maggie_animations_10_ADDRESS 0x7C5Au    /* 063C5A */
#define maggie_animations_10_sprites_ADDRESS 0x7C72u    /* 063C72 */
#define maggie_animations_10_sprites_2_ADDRESS 0x7C84u    /* 063C84 */
#define maggie_animations_10_sprites_3_ADDRESS 0x7C96u    /* 063C96 */
#define maggie_animations_10_sprites_4_ADDRESS 0x7CA8u    /* 063CA8 */
#define maggie_animations_10_sprites_5_ADDRESS 0x7CC0u    /* 063CC0 */
#define maggie_animations_11_ADDRESS 0x7CE4u    /* 063CE4 */
#define maggie_animations_11_sprites_ADDRESS 0x7CF4u    /* 063CF4 */
#define maggie_animations_11_sprites_2_ADDRESS 0x7D12u    /* 063D12 */
#define maggie_animations_11_sprites_3_ADDRESS 0x7D30u    /* 063D30 */
#define maggie_animations_12_ADDRESS 0x7D48u    /* 063D48 */
#define maggie_animations_12_sprites_ADDRESS 0x7D50u    /* 063D50 */
#define maggie_animations_12_sprites_fill_ADDRESS 0x7D62u    /* 063D62 */
#define maggie_animations_12_sprites_rest_ADDRESS 0x7D8Eu    /* 063D8E */
#define maggie_animations_12_sprites_rest_2_ADDRESS 0x7D96u    /* 063D96 */
#define maggie_animations_12_sprites_rest_3_ADDRESS 0x7DA8u    /* 063DA8 */
#define maggie_animations_12_sprites_rest_4_ADDRESS 0x7DB0u    /* 063DB0 */
#define maggie_animations_12_sprites_rest_5_ADDRESS 0x7DB6u    /* 063DB6 */
#define maggie_animations_12_sprites_rest_6_ADDRESS 0x7DBEu    /* 063DBE */
#define maggie_animations_12_sprites_fill_2_ADDRESS 0x7DCAu    /* 063DCA */
#define maggie_animations_12_sprites_rest_7_ADDRESS 0x7DDAu    /* 063DDA */
#define maggie_animations_12_sprites_rest_8_ADDRESS 0x7DE2u    /* 063DE2 */
#define maggie_animations_12_sprites_rest_9_ADDRESS 0x7DE8u    /* 063DE8 */
#define maggie_animations_12_sprites_rest_10_ADDRESS 0x7DF0u    /* 063DF0 */
#define maggie_animations_12_sprites_rest_11_ADDRESS 0x7DF6u    /* 063DF6 */
#define maggie_animations_12_sprites_rest_12_ADDRESS 0x7DFEu    /* 063DFE */
#define maggie_animations_12_sprites_rest_13_ADDRESS 0x7E04u    /* 063E04 */
#define maggie_animations_12_sprites_rest_14_ADDRESS 0x7E0Cu    /* 063E0C */
#define maggie_animations_12_sprites_rest_15_ADDRESS 0x7E12u    /* 063E12 */
#define maggie_animations_12_sprites_rest_16_ADDRESS 0x7E2Au    /* 063E2A */
#define maggie_animations_12_sprites_rest_17_ADDRESS 0x7E30u    /* 063E30 */
#define maggie_animations_12_sprites_rest_18_ADDRESS 0x7E36u    /* 063E36 */
#define maggie_animations_12_sprites_rest_19_ADDRESS 0x7E3Cu    /* 063E3C */
#define maggie_animations_12_sprites_rest_20_ADDRESS 0x7E42u    /* 063E42 */
#define maggie_animations_12_sprites_rest_21_ADDRESS 0x7E48u    /* 063E48 */
#define maggie_animations_12_sprites_rest_22_ADDRESS 0x7E5Cu    /* 063E5C */
#define maggie_animations_12_sprites_rest_23_ADDRESS 0x7E62u    /* 063E62 */
#define maggie_animations_12_sprites_rest_24_ADDRESS 0x7E74u    /* 063E74 */
#define maggie_animations_12_sprites_rest_25_ADDRESS 0x7E8Cu    /* 063E8C */
#define maggie_animations_12_sprites_rest_26_ADDRESS 0x7EA4u    /* 063EA4 */
#define maggie_animations_12_sprites_rest_27_ADDRESS 0x7EB0u    /* 063EB0 */
#define maggie_animations_12_sprites_rest_28_ADDRESS 0x7EDAu    /* 063EDA */
#define maggie_animations_12_sprites_rest_29_ADDRESS 0x7F04u    /* 063F04 */
#define maggie_animations_12_sprites_rest_30_ADDRESS 0x7F0Cu    /* 063F0C */
#define maggie_animations_12_sprites_rest_31_ADDRESS 0x7F12u    /* 063F12 */
#define maggie_animations_12_sprites_rest_32_ADDRESS 0x7F1Au    /* 063F1A */
#define maggie_animations_12_sprites_rest_33_ADDRESS 0x7F38u    /* 063F38 */
#define maggie_animations_12_sprites_rest_34_ADDRESS 0x7F40u    /* 063F40 */
#define maggie_animations_12_sprites_rest_35_ADDRESS 0x7F58u    /* 063F58 */
#define maggie_animations_12_sprites_rest_36_ADDRESS 0x7F60u    /* 063F60 */
#define maggie_animations_12_sprites_fill_3_ADDRESS 0x7F6Cu    /* 063F6C */
#define maggie_animations_12_sprites_rest_37_ADDRESS 0x7F6Eu    /* 063F6E */
#define maggie_animations_12_sprites_rest_38_ADDRESS 0x7F76u    /* 063F76 */
#define maggie_animations_12_sprites_rest_39_ADDRESS 0x7F7Cu    /* 063F7C */
#define maggie_animations_12_sprites_rest_40_ADDRESS 0x7F84u    /* 063F84 */
#define maggie_animations_12_sprites_rest_41_ADDRESS 0x7F8Au    /* 063F8A */
#define maggie_animations_12_sprites_rest_42_ADDRESS 0x7F92u    /* 063F92 */
#define maggie_animations_12_sprites_rest_43_ADDRESS 0x7F9Eu    /* 063F9E */
#define maggie_animations_12_sprites_rest_44_ADDRESS 0x7FAAu    /* 063FAA */
#define maggie_animations_12_sprites_rest_45_ADDRESS 0x7FB0u    /* 063FB0 */
#define maggie_animations_12_sprites_rest_46_ADDRESS 0x7FB6u    /* 063FB6 */
#define maggie_animations_12_sprites_rest_47_ADDRESS 0x7FBEu    /* 063FBE */
#define maggie_animations_12_sprites_rest_48_ADDRESS 0x7FC4u    /* 063FC4 */
#define maggie_animations_12_sprites_rest_49_ADDRESS 0x7FCCu    /* 063FCC */
#define maggie_animations_12_sprites_rest_50_ADDRESS 0x7FD2u    /* 063FD2 */
#define maggie_animations_12_sprites_rest_51_ADDRESS 0x7FDAu    /* 063FDA */
#define maggie_animations_12_sprites_rest_52_ADDRESS 0x7FE0u    /* 063FE0 */
#define maggie_animations_12_sprites_rest_53_ADDRESS 0x7FE8u    /* 063FE8 */
#define maggie_animations_12_sprites_fill_4_ADDRESS 0x7FEEu    /* 063FEE */
#define maggie_animations_12_sprites_rest_54_ADDRESS 0x6000u    /* 064000 */
#define bart_animations_ADDRESS 0x6006u    /* 064006 */
#define bart_animations_7_ADDRESS 0x6106u    /* 064106 */
#define bart_animations_7_sprites_ADDRESS 0x610Eu    /* 06410E */
#define bart_animations_63_ADDRESS 0x611Au    /* 06411A */
#define bart_animations_63_sprites_ADDRESS 0x6122u    /* 064122 */
#define bart_animations_38_ADDRESS 0x6128u    /* 064128 */
#define bart_animations_38_sprites_ADDRESS 0x6130u    /* 064130 */
#define bart_animations_98_ADDRESS 0x6136u    /* 064136 */
#define bart_animations_98_sprites_ADDRESS 0x614Eu    /* 06414E */
#define bart_animations_98_sprites_2_ADDRESS 0x615Au    /* 06415A */
#define bart_animations_98_sprites_3_ADDRESS 0x6166u    /* 064166 */
#define bart_animations_98_sprites_4_ADDRESS 0x617Eu    /* 06417E */
#define bart_animations_98_sprites_5_ADDRESS 0x6190u    /* 064190 */
#define bart_animations_102_ADDRESS 0x61A8u    /* 0641A8 */
#define bart_animations_106_ADDRESS 0x61B0u    /* 0641B0 */
#define bart_animations_110_ADDRESS 0x61B8u    /* 0641B8 */
#define bart_animations_110_sprites_ADDRESS 0x61DCu    /* 0641DC */
#define bart_animations_110_sprites_2_ADDRESS 0x61F4u    /* 0641F4 */
#define bart_animations_110_sprites_3_ADDRESS 0x620Cu    /* 06420C */
#define bart_animations_110_sprites_4_ADDRESS 0x621Eu    /* 06421E */
#define bart_animations_110_sprites_5_ADDRESS 0x6236u    /* 064236 */
#define bart_animations_110_sprites_6_ADDRESS 0x624Eu    /* 06424E */
#define bart_animations_110_sprites_7_ADDRESS 0x6266u    /* 064266 */
#define bart_animations_110_sprites_8_ADDRESS 0x6278u    /* 064278 */
#define bart_animations_114_ADDRESS 0x6290u    /* 064290 */
#define bart_animations_114_sprites_ADDRESS 0x6298u    /* 064298 */
#define bart_animations_118_ADDRESS 0x62B0u    /* 0642B0 */
#define bart_animations_118_sprites_ADDRESS 0x62B8u    /* 0642B8 */
#define bart_animations_121_ADDRESS 0x62D0u    /* 0642D0 */
#define bart_animations_121_sprites_ADDRESS 0x62DCu    /* 0642DC */
#define bart_animations_121_sprites_2_ADDRESS 0x62E8u    /* 0642E8 */
#define bart_animations_122_ADDRESS 0x62F4u    /* 0642F4 */
#define bart_animations_122_sprites_ADDRESS 0x6300u    /* 064300 */
#define bart_animations_122_sprites_2_ADDRESS 0x6318u    /* 064318 */
#define bart_animations_125_ADDRESS 0x6336u    /* 064336 */
#define bart_animations_126_ADDRESS 0x6342u    /* 064342 */
#define bart_animations_99_ADDRESS 0x634Au    /* 06434A */
#define bart_animations_99_sprites_ADDRESS 0x6362u    /* 064362 */
#define bart_animations_99_sprites_2_ADDRESS 0x6374u    /* 064374 */
#define bart_animations_99_sprites_3_ADDRESS 0x6386u    /* 064386 */
#define bart_animations_99_sprites_4_ADDRESS 0x6398u    /* 064398 */
#define bart_animations_99_sprites_5_ADDRESS 0x63AAu    /* 0643AA */
#define bart_animations_103_ADDRESS 0x63C2u    /* 0643C2 */
#define bart_animations_103_sprites_ADDRESS 0x63E6u    /* 0643E6 */
#define bart_animations_103_sprites_2_ADDRESS 0x63FEu    /* 0643FE */
#define bart_animations_103_sprites_3_ADDRESS 0x6416u    /* 064416 */
#define bart_animations_103_sprites_4_ADDRESS 0x642Eu    /* 06442E */
#define bart_animations_103_sprites_5_ADDRESS 0x6446u    /* 064446 */
#define bart_animations_103_sprites_6_ADDRESS 0x645Eu    /* 06445E */
#define bart_animations_103_sprites_7_ADDRESS 0x6476u    /* 064476 */
#define bart_animations_103_sprites_8_ADDRESS 0x648Eu    /* 06448E */
#define bart_animations_107_ADDRESS 0x64A6u    /* 0644A6 */
#define bart_animations_111_ADDRESS 0x64AEu    /* 0644AE */
#define bart_animations_115_ADDRESS 0x64D2u    /* 0644D2 */
#define bart_animations_115_sprites_ADDRESS 0x64DAu    /* 0644DA */
#define bart_animations_119_ADDRESS 0x64F2u    /* 0644F2 */
#define bart_animations_119_sprites_ADDRESS 0x64FAu    /* 0644FA */
#define bart_animations_123_ADDRESS 0x6512u    /* 064512 */
#define bart_animations_123_sprites_ADDRESS 0x6526u    /* 064526 */
#define bart_animations_123_sprites_2_ADDRESS 0x6538u    /* 064538 */
#define bart_animations_123_sprites_3_ADDRESS 0x6550u    /* 064550 */
#define bart_animations_123_sprites_4_ADDRESS 0x6568u    /* 064568 */
#define bart_animations_127_ADDRESS 0x6580u    /* 064580 */
#define bart_animations_127_sprites_ADDRESS 0x658Cu    /* 06458C */
#define bart_animations_127_sprites_2_ADDRESS 0x65AAu    /* 0645AA */
#define bart_animations_0_ADDRESS 0x65C2u    /* 0645C2 */
#define bart_animations_0_sprites_ADDRESS 0x65CAu    /* 0645CA */
#define bart_animations_55_ADDRESS 0x65D6u    /* 0645D6 */
#define bart_animations_55_sprites_ADDRESS 0x6606u    /* 064606 */
#define bart_animations_55_sprites_2_ADDRESS 0x6612u    /* 064612 */
#define bart_animations_55_sprites_3_ADDRESS 0x661Eu    /* 06461E */
#define bart_animations_55_sprites_4_ADDRESS 0x662Au    /* 06462A */
#define bart_animations_55_sprites_5_ADDRESS 0x6636u    /* 064636 */
#define bart_animations_55_sprites_6_ADDRESS 0x6642u    /* 064642 */
#define bart_animations_55_sprites_7_ADDRESS 0x664Eu    /* 06464E */
#define bart_animations_55_sprites_8_ADDRESS 0x665Au    /* 06465A */
#define bart_animations_55_sprites_9_ADDRESS 0x6666u    /* 064666 */
#define bart_animations_55_sprites_10_ADDRESS 0x6672u    /* 064672 */
#define bart_animations_55_sprites_11_ADDRESS 0x667Eu    /* 06467E */
#define bart_animations_80_ADDRESS 0x668Au    /* 06468A */
#define bart_animations_80_sprites_ADDRESS 0x669Au    /* 06469A */
#define bart_animations_80_sprites_2_ADDRESS 0x66A6u    /* 0646A6 */
#define bart_animations_80_sprites_3_ADDRESS 0x66B8u    /* 0646B8 */
#define bart_animations_81_ADDRESS 0x66C4u    /* 0646C4 */
#define bart_animations_81_sprites_ADDRESS 0x66D4u    /* 0646D4 */
#define bart_animations_81_sprites_2_ADDRESS 0x66E0u    /* 0646E0 */
#define bart_animations_81_sprites_3_ADDRESS 0x66ECu    /* 0646EC */
#define bart_animations_82_ADDRESS 0x66F8u    /* 0646F8 */
#define bart_animations_82_sprites_ADDRESS 0x6708u    /* 064708 */
#define bart_animations_82_sprites_2_ADDRESS 0x6714u    /* 064714 */
#define bart_animations_82_sprites_3_ADDRESS 0x6720u    /* 064720 */
#define bart_animations_83_ADDRESS 0x672Cu    /* 06472C */
#define bart_animations_83_sprites_ADDRESS 0x6740u    /* 064740 */
#define bart_animations_83_sprites_2_ADDRESS 0x674Cu    /* 06474C */
#define bart_animations_83_sprites_3_ADDRESS 0x6758u    /* 064758 */
#define bart_animations_83_sprites_4_ADDRESS 0x6764u    /* 064764 */
#define bart_animations_84_ADDRESS 0x6770u    /* 064770 */
#define bart_animations_84_sprites_ADDRESS 0x6784u    /* 064784 */
#define bart_animations_84_sprites_2_ADDRESS 0x6790u    /* 064790 */
#define bart_animations_84_sprites_3_ADDRESS 0x6796u    /* 064796 */
#define bart_animations_84_sprites_4_ADDRESS 0x67A2u    /* 0647A2 */
#define bart_animations_85_ADDRESS 0x67A8u    /* 0647A8 */
#define bart_animations_85_sprites_ADDRESS 0x67BCu    /* 0647BC */
#define bart_animations_85_sprites_2_ADDRESS 0x67C8u    /* 0647C8 */
#define bart_animations_85_sprites_3_ADDRESS 0x67CEu    /* 0647CE */
#define bart_animations_85_sprites_4_ADDRESS 0x67DAu    /* 0647DA */
#define bart_animations_86_ADDRESS 0x67E0u    /* 0647E0 */
#define bart_animations_86_sprites_ADDRESS 0x67F0u    /* 0647F0 */
#define bart_animations_86_sprites_2_ADDRESS 0x67FCu    /* 0647FC */
#define bart_animations_86_sprites_3_ADDRESS 0x6808u    /* 064808 */
#define bart_animations_87_ADDRESS 0x680Eu    /* 06480E */
#define bart_animations_87_sprites_ADDRESS 0x6816u    /* 064816 */
#define bart_animations_92_ADDRESS 0x6822u    /* 064822 */
#define bart_animations_92_sprites_ADDRESS 0x6832u    /* 064832 */
#define bart_animations_92_sprites_2_ADDRESS 0x6838u    /* 064838 */
#define bart_animations_92_sprites_3_ADDRESS 0x6844u    /* 064844 */
#define bart_animations_95_ADDRESS 0x6850u    /* 064850 */
#define bart_animations_95_sprites_ADDRESS 0x6864u    /* 064864 */
#define bart_animations_95_sprites_2_ADDRESS 0x6870u    /* 064870 */
#define bart_animations_95_sprites_3_ADDRESS 0x687Cu    /* 06487C */
#define bart_animations_95_sprites_4_ADDRESS 0x6888u    /* 064888 */
#define bart_animations_47_ADDRESS 0x6894u    /* 064894 */
#define bart_animations_47_sprites_ADDRESS 0x68A8u    /* 0648A8 */
#define bart_animations_47_sprites_2_ADDRESS 0x68B4u    /* 0648B4 */
#define bart_animations_47_sprites_3_ADDRESS 0x68C0u    /* 0648C0 */
#define bart_animations_61_ADDRESS 0x68CCu    /* 0648CC */
#define bart_animations_61_sprites_ADDRESS 0x68D4u    /* 0648D4 */
#define bart_animations_93_ADDRESS 0x68E0u    /* 0648E0 */
#define bart_animations_93_sprites_ADDRESS 0x68F0u    /* 0648F0 */
#define bart_animations_93_sprites_2_ADDRESS 0x68F6u    /* 0648F6 */
#define bart_animations_93_sprites_3_ADDRESS 0x6902u    /* 064902 */
#define bart_animations_69_ADDRESS 0x690Eu    /* 06490E */
#define bart_animations_69_sprites_ADDRESS 0x691Au    /* 06491A */
#define bart_animations_69_sprites_2_ADDRESS 0x6926u    /* 064926 */
#define bart_animations_70_ADDRESS 0x6932u    /* 064932 */
#define bart_animations_70_sprites_ADDRESS 0x693Eu    /* 06493E */
#define bart_animations_70_sprites_2_ADDRESS 0x694Au    /* 06494A */
#define bart_animations_53_ADDRESS 0x6956u    /* 064956 */
#define bart_animations_53_sprites_ADDRESS 0x6966u    /* 064966 */
#define bart_animations_53_sprites_2_ADDRESS 0x6972u    /* 064972 */
#define bart_animations_53_sprites_3_ADDRESS 0x697Eu    /* 06497E */
#define bart_animations_54_ADDRESS 0x698Au    /* 06498A */
#define bart_animations_54_sprites_ADDRESS 0x699Eu    /* 06499E */
#define bart_animations_54_sprites_2_ADDRESS 0x69AAu    /* 0649AA */
#define bart_animations_54_sprites_3_ADDRESS 0x69BCu    /* 0649BC */
#define bart_animations_54_sprites_4_ADDRESS 0x69CEu    /* 0649CE */
#define bart_animations_57_ADDRESS 0x69E0u    /* 0649E0 */
#define bart_animations_57_sprites_ADDRESS 0x6A00u    /* 064A00 */
#define bart_animations_57_sprites_2_ADDRESS 0x6A06u    /* 064A06 */
#define bart_animations_57_sprites_3_ADDRESS 0x6A12u    /* 064A12 */
#define bart_animations_57_sprites_4_ADDRESS 0x6A24u    /* 064A24 */
#define bart_animations_57_sprites_5_ADDRESS 0x6A30u    /* 064A30 */
#define bart_animations_57_sprites_6_ADDRESS 0x6A3Cu    /* 064A3C */
#define bart_animations_57_sprites_7_ADDRESS 0x6A48u    /* 064A48 */
#define bart_animations_58_ADDRESS 0x6A54u    /* 064A54 */
#define bart_animations_58_sprites_ADDRESS 0x6A60u    /* 064A60 */
#define bart_animations_58_sprites_2_ADDRESS 0x6A66u    /* 064A66 */
#define bart_animations_59_ADDRESS 0x6A6Cu    /* 064A6C */
#define bart_animations_59_sprites_ADDRESS 0x6A78u    /* 064A78 */
#define bart_animations_59_sprites_2_ADDRESS 0x6A84u    /* 064A84 */
#define bart_animations_62_ADDRESS 0x6A90u    /* 064A90 */
#define bart_animations_62_sprites_ADDRESS 0x6A9Cu    /* 064A9C */
#define bart_animations_62_sprites_2_ADDRESS 0x6AA8u    /* 064AA8 */
#define bart_animations_56_ADDRESS 0x6AC0u    /* 064AC0 */
#define bart_animations_56_sprites_ADDRESS 0x6AF8u    /* 064AF8 */
#define bart_animations_56_sprites_2_ADDRESS 0x6B04u    /* 064B04 */
#define bart_animations_56_sprites_3_ADDRESS 0x6B10u    /* 064B10 */
#define bart_animations_56_sprites_4_ADDRESS 0x6B1Cu    /* 064B1C */
#define bart_animations_56_sprites_5_ADDRESS 0x6B28u    /* 064B28 */
#define bart_animations_56_sprites_6_ADDRESS 0x6B34u    /* 064B34 */
#define bart_animations_1_ADDRESS 0x6B40u    /* 064B40 */
#define bart_animations_1_sprites_ADDRESS 0x6B5Cu    /* 064B5C */
#define bart_animations_1_sprites_2_ADDRESS 0x6B6Eu    /* 064B6E */
#define bart_animations_1_sprites_3_ADDRESS 0x6B80u    /* 064B80 */
#define bart_animations_1_sprites_4_ADDRESS 0x6B92u    /* 064B92 */
#define bart_animations_1_sprites_5_ADDRESS 0x6BA4u    /* 064BA4 */
#define bart_animations_1_sprites_6_ADDRESS 0x6BB0u    /* 064BB0 */
#define bart_animations_2_ADDRESS 0x6BBCu    /* 064BBC */
#define bart_animations_2_sprites_ADDRESS 0x6BD8u    /* 064BD8 */
#define bart_animations_2_sprites_2_ADDRESS 0x6BE4u    /* 064BE4 */
#define bart_animations_2_sprites_3_ADDRESS 0x6BF0u    /* 064BF0 */
#define bart_animations_2_sprites_4_ADDRESS 0x6BFCu    /* 064BFC */
#define bart_animations_2_sprites_5_ADDRESS 0x6C08u    /* 064C08 */
#define bart_animations_2_sprites_6_ADDRESS 0x6C14u    /* 064C14 */
#define bart_animations_3_ADDRESS 0x6C20u    /* 064C20 */
#define bart_animations_3_sprites_ADDRESS 0x6C28u    /* 064C28 */
#define bart_animations_4_ADDRESS 0x6C3Au    /* 064C3A */
#define bart_animations_4_sprites_ADDRESS 0x6C42u    /* 064C42 */
#define bart_animations_5_ADDRESS 0x6C4Eu    /* 064C4E */
#define bart_animations_5_sprites_ADDRESS 0x6C56u    /* 064C56 */
#define bart_animations_8_ADDRESS 0x6C62u    /* 064C62 */
#define bart_animations_8_sprites_ADDRESS 0x6C6Au    /* 064C6A */
#define bart_animations_9_ADDRESS 0x6C7Cu    /* 064C7C */
#define bart_animations_9_sprites_ADDRESS 0x6C98u    /* 064C98 */
#define bart_animations_9_sprites_2_ADDRESS 0x6CAAu    /* 064CAA */
#define bart_animations_9_sprites_3_ADDRESS 0x6CBCu    /* 064CBC */
#define bart_animations_9_sprites_4_ADDRESS 0x6CCEu    /* 064CCE */
#define bart_animations_9_sprites_5_ADDRESS 0x6CE0u    /* 064CE0 */
#define bart_animations_9_sprites_6_ADDRESS 0x6CF2u    /* 064CF2 */
#define bart_animations_16_ADDRESS 0x6D04u    /* 064D04 */
#define bart_animations_16_sprites_ADDRESS 0x6D0Cu    /* 064D0C */
#define bart_animations_17_ADDRESS 0x6D18u    /* 064D18 */
#define bart_animations_17_sprites_ADDRESS 0x6D34u    /* 064D34 */
#define bart_animations_17_sprites_2_ADDRESS 0x6D46u    /* 064D46 */
#define bart_animations_17_sprites_3_ADDRESS 0x6D58u    /* 064D58 */
#define bart_animations_17_sprites_4_ADDRESS 0x6D6Au    /* 064D6A */
#define bart_animations_17_sprites_5_ADDRESS 0x6D7Cu    /* 064D7C */
#define bart_animations_17_sprites_6_ADDRESS 0x6D8Eu    /* 064D8E */
#define bart_animations_48_ADDRESS 0x6DA0u    /* 064DA0 */
#define bart_animations_48_sprites_ADDRESS 0x6DACu    /* 064DAC */
#define bart_animations_49_ADDRESS 0x6DBEu    /* 064DBE */
#define bart_animations_49_sprites_ADDRESS 0x6DCAu    /* 064DCA */
#define bart_animations_88_ADDRESS 0x6DD6u    /* 064DD6 */
#define bart_animations_88_sprites_ADDRESS 0x6DF2u    /* 064DF2 */
#define bart_animations_88_sprites_2_ADDRESS 0x6DFEu    /* 064DFE */
#define bart_animations_88_sprites_3_ADDRESS 0x6E0Au    /* 064E0A */
#define bart_animations_88_sprites_4_ADDRESS 0x6E16u    /* 064E16 */
#define bart_animations_88_sprites_5_ADDRESS 0x6E22u    /* 064E22 */
#define bart_animations_88_sprites_6_ADDRESS 0x6E2Eu    /* 064E2E */
#define bart_animations_89_ADDRESS 0x6E3Au    /* 064E3A */
#define bart_animations_89_sprites_ADDRESS 0x6E46u    /* 064E46 */
#define bart_animations_89_sprites_2_ADDRESS 0x6E4Cu    /* 064E4C */
#define bart_animations_31_ADDRESS 0x6E58u    /* 064E58 */
#define bart_animations_31_sprites_ADDRESS 0x6E6Cu    /* 064E6C */
#define bart_animations_31_sprites_2_ADDRESS 0x6E78u    /* 064E78 */
#define bart_animations_31_sprites_3_ADDRESS 0x6E84u    /* 064E84 */
#define bart_animations_91_ADDRESS 0x6E90u    /* 064E90 */
#define bart_animations_91_sprites_ADDRESS 0x6EA8u    /* 064EA8 */
#define bart_animations_91_sprites_2_ADDRESS 0x6EB4u    /* 064EB4 */
#define bart_animations_91_sprites_3_ADDRESS 0x6EC0u    /* 064EC0 */
#define bart_animations_91_sprites_4_ADDRESS 0x6ECCu    /* 064ECC */
#define bart_animations_91_sprites_5_ADDRESS 0x6ED8u    /* 064ED8 */
#define bart_animations_94_ADDRESS 0x6EE4u    /* 064EE4 */
#define bart_animations_94_sprites_ADDRESS 0x6EF0u    /* 064EF0 */
#define bart_animations_94_sprites_2_ADDRESS 0x6EFCu    /* 064EFC */
#define bart_animations_100_ADDRESS 0x6F08u    /* 064F08 */
#define bart_animations_100_sprites_ADDRESS 0x6F14u    /* 064F14 */
#define bart_animations_100_sprites_2_ADDRESS 0x6F20u    /* 064F20 */
#define bart_animations_14_ADDRESS 0x6F2Cu    /* 064F2C */
#define bart_animations_14_sprites_ADDRESS 0x6F34u    /* 064F34 */
#define bart_animations_101_ADDRESS 0x6F3Au    /* 064F3A */
#define bart_animations_101_sprites_ADDRESS 0x6F42u    /* 064F42 */
#define bart_animations_109_ADDRESS 0x6F48u    /* 064F48 */
#define bart_animations_109_sprites_ADDRESS 0x6F64u    /* 064F64 */
#define bart_animations_109_sprites_2_ADDRESS 0x6F70u    /* 064F70 */
#define bart_animations_109_sprites_3_ADDRESS 0x6F7Cu    /* 064F7C */
#define bart_animations_109_sprites_4_ADDRESS 0x6F88u    /* 064F88 */
#define bart_animations_109_sprites_5_ADDRESS 0x6F94u    /* 064F94 */
#define bart_animations_109_sprites_6_ADDRESS 0x6FA0u    /* 064FA0 */
#define bart_animations_113_ADDRESS 0x6FACu    /* 064FAC */
#define bart_animations_113_sprites_ADDRESS 0x6FB4u    /* 064FB4 */
#define bart_animations_117_ADDRESS 0x6FBAu    /* 064FBA */
#define bart_animations_117_sprites_ADDRESS 0x6FC2u    /* 064FC2 */
#define bart_animations_97_ADDRESS 0x6FC8u    /* 064FC8 */
#define bart_animations_97_sprites_ADDRESS 0x6FD4u    /* 064FD4 */
#define bart_animations_97_sprites_2_ADDRESS 0x6FDAu    /* 064FDA */
#define bart_animations_96_ADDRESS 0x6FE0u    /* 064FE0 */
#define bart_animations_96_sprites_ADDRESS 0x6FF4u    /* 064FF4 */
#define bart_animations_96_sprites_2_ADDRESS 0x6FFAu    /* 064FFA */
#define bart_animations_96_sprites_3_ADDRESS 0x7000u    /* 065000 */
#define bart_animations_96_sprites_4_ADDRESS 0x701Eu    /* 06501E */
#define bart_animations_104_ADDRESS 0x703Cu    /* 06503C */
#define bart_animations_104_sprites_ADDRESS 0x7050u    /* 065050 */
#define bart_animations_104_sprites_2_ADDRESS 0x7062u    /* 065062 */
#define bart_animations_104_sprites_3_ADDRESS 0x7074u    /* 065074 */
#define bart_animations_104_sprites_4_ADDRESS 0x7086u    /* 065086 */
#define bart_animations_15_ADDRESS 0x7098u    /* 065098 */
#define bart_animations_15_sprites_ADDRESS 0x70A4u    /* 0650A4 */
#define bart_animations_15_sprites_2_ADDRESS 0x70B6u    /* 0650B6 */
#define bart_animations_23_ADDRESS 0x70C2u    /* 0650C2 */
#define bart_animations_23_sprites_ADDRESS 0x70CEu    /* 0650CE */
#define bart_animations_23_sprites_2_ADDRESS 0x70DAu    /* 0650DA */
#define bart_animations_64_ADDRESS 0x70E6u    /* 0650E6 */
#define bart_animations_64_sprites_ADDRESS 0x70F2u    /* 0650F2 */
#define bart_animations_64_sprites_2_ADDRESS 0x70FEu    /* 0650FE */
#define bart_animations_65_ADDRESS 0x7110u    /* 065110 */
#define bart_animations_65_sprites_ADDRESS 0x711Cu    /* 06511C */
#define bart_animations_65_sprites_2_ADDRESS 0x7128u    /* 065128 */
#define bart_animations_78_ADDRESS 0x7134u    /* 065134 */
#define bart_animations_78_sprites_ADDRESS 0x713Cu    /* 06513C */
#define bart_animations_40_ADDRESS 0x7142u    /* 065142 */
#define bart_animations_40_sprites_ADDRESS 0x714Au    /* 06514A */
#define bart_animations_41_ADDRESS 0x715Cu    /* 06515C */
#define bart_animations_41_sprites_ADDRESS 0x7178u    /* 065178 */
#define bart_animations_41_sprites_2_ADDRESS 0x718Au    /* 06518A */
#define bart_animations_41_sprites_3_ADDRESS 0x719Cu    /* 06519C */
#define bart_animations_41_sprites_4_ADDRESS 0x71AEu    /* 0651AE */
#define bart_animations_41_sprites_5_ADDRESS 0x71C0u    /* 0651C0 */
#define bart_animations_41_sprites_6_ADDRESS 0x71D2u    /* 0651D2 */
#define bart_animations_43_ADDRESS 0x71E4u    /* 0651E4 */
#define bart_animations_43_sprites_ADDRESS 0x71ECu    /* 0651EC */
#define bart_animations_44_ADDRESS 0x71FEu    /* 0651FE */
#define bart_animations_44_sprites_ADDRESS 0x7206u    /* 065206 */
#define bart_animations_45_ADDRESS 0x7218u    /* 065218 */
#define bart_animations_45_sprites_ADDRESS 0x7220u    /* 065220 */
#define bart_animations_52_ADDRESS 0x7232u    /* 065232 */
#define bart_animations_52_sprites_ADDRESS 0x7242u    /* 065242 */
#define bart_animations_52_sprites_2_ADDRESS 0x7254u    /* 065254 */
#define bart_animations_52_sprites_3_ADDRESS 0x7266u    /* 065266 */
#define bart_animations_68_ADDRESS 0x727Eu    /* 06527E */
#define bart_animations_68_sprites_ADDRESS 0x728Eu    /* 06528E */
#define bart_animations_68_sprites_2_ADDRESS 0x72A0u    /* 0652A0 */
#define bart_animations_73_ADDRESS 0x72B8u    /* 0652B8 */
#define bart_animations_73_sprites_ADDRESS 0x72C4u    /* 0652C4 */
#define bart_animations_73_sprites_2_ADDRESS 0x72CAu    /* 0652CA */
#define bart_animations_75_ADDRESS 0x72D6u    /* 0652D6 */
#define bart_animations_75_sprites_ADDRESS 0x72DEu    /* 0652DE */
#define bart_animations_77_ADDRESS 0x72E4u    /* 0652E4 */
#define bart_animations_77_sprites_ADDRESS 0x72F0u    /* 0652F0 */
#define bart_animations_30_ADDRESS 0x72FCu    /* 0652FC */
#define bart_animations_30_sprites_ADDRESS 0x7308u    /* 065308 */
#define bart_animations_30_sprites_2_ADDRESS 0x731Au    /* 06531A */
#define bart_animations_6_ADDRESS 0x732Cu    /* 06532C */
#define bart_animations_6_sprites_ADDRESS 0x7340u    /* 065340 */
#define bart_animations_6_sprites_2_ADDRESS 0x734Cu    /* 06534C */
#define bart_animations_6_sprites_3_ADDRESS 0x7358u    /* 065358 */
#define bart_animations_6_sprites_4_ADDRESS 0x7364u    /* 065364 */
#define bart_animations_22_ADDRESS 0x736Au    /* 06536A */
#define bart_animations_22_sprites_ADDRESS 0x738Eu    /* 06538E */
#define bart_animations_22_sprites_2_ADDRESS 0x73A0u    /* 0653A0 */
#define bart_animations_22_sprites_3_ADDRESS 0x73ACu    /* 0653AC */
#define bart_animations_22_sprites_4_ADDRESS 0x73BEu    /* 0653BE */
#define bart_animations_22_sprites_5_ADDRESS 0x73D0u    /* 0653D0 */
#define bart_animations_22_sprites_6_ADDRESS 0x73DCu    /* 0653DC */
#define bart_animations_22_sprites_7_ADDRESS 0x73E8u    /* 0653E8 */
#define bart_animations_22_sprites_8_ADDRESS 0x73F4u    /* 0653F4 */
#define bart_animations_32_ADDRESS 0x73FAu    /* 0653FA */
#define bart_animations_32_sprites_ADDRESS 0x7402u    /* 065402 */
#define bart_animations_33_ADDRESS 0x741Au    /* 06541A */
#define bart_animations_33_sprites_ADDRESS 0x7436u    /* 065436 */
#define bart_animations_33_sprites_2_ADDRESS 0x744Eu    /* 06544E */
#define bart_animations_33_sprites_3_ADDRESS 0x7466u    /* 065466 */
#define bart_animations_33_sprites_4_ADDRESS 0x747Eu    /* 06547E */
#define bart_animations_33_sprites_5_ADDRESS 0x7496u    /* 065496 */
#define bart_animations_33_sprites_6_ADDRESS 0x74AEu    /* 0654AE */
#define bart_animations_35_ADDRESS 0x74C6u    /* 0654C6 */
#define bart_animations_35_sprites_ADDRESS 0x74CEu    /* 0654CE */
#define bart_animations_36_ADDRESS 0x74E6u    /* 0654E6 */
#define bart_animations_36_sprites_ADDRESS 0x74EEu    /* 0654EE */
#define bart_animations_37_ADDRESS 0x7506u    /* 065506 */
#define bart_animations_37_sprites_ADDRESS 0x750Eu    /* 06550E */
#define bart_animations_51_ADDRESS 0x7526u    /* 065526 */
#define bart_animations_51_sprites_ADDRESS 0x7536u    /* 065536 */
#define bart_animations_51_sprites_2_ADDRESS 0x7548u    /* 065548 */
#define bart_animations_51_sprites_3_ADDRESS 0x7560u    /* 065560 */
#define bart_animations_67_ADDRESS 0x7578u    /* 065578 */
#define bart_animations_67_sprites_ADDRESS 0x7588u    /* 065588 */
#define bart_animations_67_sprites_2_ADDRESS 0x759Au    /* 06559A */
#define bart_animations_67_sprites_3_ADDRESS 0x75B2u    /* 0655B2 */
#define bart_animations_24_ADDRESS 0x75CAu    /* 0655CA */
#define bart_animations_24_sprites_ADDRESS 0x75D2u    /* 0655D2 */
#define bart_animations_25_ADDRESS 0x75EAu    /* 0655EA */
#define bart_animations_25_sprites_ADDRESS 0x7606u    /* 065606 */
#define bart_animations_25_sprites_2_ADDRESS 0x761Eu    /* 06561E */
#define bart_animations_25_sprites_3_ADDRESS 0x7636u    /* 065636 */
#define bart_animations_25_sprites_4_ADDRESS 0x764Eu    /* 06564E */
#define bart_animations_25_sprites_5_ADDRESS 0x7666u    /* 065666 */
#define bart_animations_25_sprites_6_ADDRESS 0x767Eu    /* 06567E */
#define bart_animations_27_ADDRESS 0x7696u    /* 065696 */
#define bart_animations_27_sprites_ADDRESS 0x769Eu    /* 06569E */
#define bart_animations_28_ADDRESS 0x76B6u    /* 0656B6 */
#define bart_animations_28_sprites_ADDRESS 0x76BEu    /* 0656BE */
#define bart_animations_29_ADDRESS 0x76D6u    /* 0656D6 */
#define bart_animations_29_sprites_ADDRESS 0x76E2u    /* 0656E2 */
#define bart_animations_29_sprites_2_ADDRESS 0x7700u    /* 065700 */
#define bart_animations_50_ADDRESS 0x771Eu    /* 06571E */
#define bart_animations_50_sprites_ADDRESS 0x7732u    /* 065732 */
#define bart_animations_50_sprites_2_ADDRESS 0x774Au    /* 06574A */
#define bart_animations_50_sprites_3_ADDRESS 0x7762u    /* 065762 */
#define bart_animations_50_sprites_4_ADDRESS 0x7774u    /* 065774 */
#define bart_animations_66_ADDRESS 0x7786u    /* 065786 */
#define bart_animations_66_sprites_ADDRESS 0x779Au    /* 06579A */
#define bart_animations_66_sprites_2_ADDRESS 0x77B2u    /* 0657B2 */
#define bart_animations_66_sprites_3_ADDRESS 0x77C4u    /* 0657C4 */
#define bart_animations_66_sprites_4_ADDRESS 0x77D6u    /* 0657D6 */
#define bart_animations_11_ADDRESS 0x77E8u    /* 0657E8 */
#define bart_animations_11_sprites_ADDRESS 0x77F0u    /* 0657F0 */
#define bart_animations_12_ADDRESS 0x77FCu    /* 0657FC */
#define bart_animations_12_sprites_ADDRESS 0x7804u    /* 065804 */
#define bart_animations_13_ADDRESS 0x7810u    /* 065810 */
#define bart_animations_13_sprites_ADDRESS 0x7818u    /* 065818 */
#define bart_animations_19_ADDRESS 0x7824u    /* 065824 */
#define bart_animations_19_sprites_ADDRESS 0x782Cu    /* 06582C */
#define bart_animations_20_ADDRESS 0x7838u    /* 065838 */
#define bart_animations_20_sprites_ADDRESS 0x7840u    /* 065840 */
#define bart_animations_21_ADDRESS 0x784Cu    /* 06584C */
#define bart_animations_21_sprites_ADDRESS 0x7854u    /* 065854 */
#define bart_animations_39_ADDRESS 0x7860u    /* 065860 */
#define bart_animations_39_sprites_ADDRESS 0x786Cu    /* 06586C */
#define bart_animations_39_sprites_2_ADDRESS 0x7878u    /* 065878 */
#define bart_animations_46_ADDRESS 0x7884u    /* 065884 */
#define bart_animations_46_sprites_ADDRESS 0x7890u    /* 065890 */
#define bart_animations_46_sprites_2_ADDRESS 0x789Cu    /* 06589C */
#define marge_portrait_animations_ADDRESS 0x78A2u    /* 0658A2 */
#define marge_portrait_animations_0_ADDRESS 0x78D2u    /* 0658D2 */
#define marge_portrait_animations_0_sprites_ADDRESS 0x78DEu    /* 0658DE */
#define marge_portrait_animations_0_sprites_2_ADDRESS 0x78F6u    /* 0658F6 */
#define marge_portrait_animations_1_ADDRESS 0x790Eu    /* 06590E */
#define marge_portrait_animations_1_sprites_ADDRESS 0x7916u    /* 065916 */
#define marge_portrait_animations_2_ADDRESS 0x7928u    /* 065928 */
#define marge_portrait_animations_2_sprites_ADDRESS 0x7938u    /* 065938 */
#define marge_portrait_animations_2_sprites_2_ADDRESS 0x794Au    /* 06594A */
#define marge_portrait_animations_2_sprites_3_ADDRESS 0x795Cu    /* 06595C */
#define marge_portrait_animations_23_ADDRESS 0x796Eu    /* 06596E */
#define marge_portrait_animations_3_ADDRESS 0x7976u    /* 065976 */
#define marge_portrait_animations_3_sprites_ADDRESS 0x798Au    /* 06598A */
#define marge_portrait_animations_3_sprites_2_ADDRESS 0x799Cu    /* 06599C */
#define marge_portrait_animations_3_sprites_3_ADDRESS 0x79AEu    /* 0659AE */
#define marge_portrait_animations_23_sprites_ADDRESS 0x79C0u    /* 0659C0 */
#define marge_portrait_animations_23_sprites_rest_ADDRESS 0x79D2u    /* 0659D2 */
#define marge_portrait_animations_4_ADDRESS 0x79E4u    /* 0659E4 */
#define marge_portrait_animations_4_sprites_ADDRESS 0x79ECu    /* 0659EC */
#define marge_portrait_animations_5_ADDRESS 0x79F2u    /* 0659F2 */
#define marge_portrait_animations_5_sprites_ADDRESS 0x79FAu    /* 0659FA */
#define marge_portrait_animations_6_ADDRESS 0x7A06u    /* 065A06 */
#define marge_portrait_animations_6_sprites_ADDRESS 0x7A0Eu    /* 065A0E */
#define marge_portrait_animations_7_ADDRESS 0x7A1Au    /* 065A1A */
#define marge_portrait_animations_7_sprites_ADDRESS 0x7A22u    /* 065A22 */
#define marge_portrait_animations_8_ADDRESS 0x7A2Eu    /* 065A2E */
#define marge_portrait_animations_8_sprites_ADDRESS 0x7A36u    /* 065A36 */
#define marge_portrait_animations_9_ADDRESS 0x7A60u    /* 065A60 */
#define marge_portrait_animations_9_sprites_ADDRESS 0x7A68u    /* 065A68 */
#define marge_portrait_animations_10_ADDRESS 0x7A92u    /* 065A92 */
#define marge_portrait_animations_10_sprites_ADDRESS 0x7A9Au    /* 065A9A */
#define marge_portrait_animations_11_ADDRESS 0x7AB8u    /* 065AB8 */
#define marge_portrait_animations_11_sprites_ADDRESS 0x7AD0u    /* 065AD0 */
#define marge_portrait_animations_11_sprites_2_ADDRESS 0x7AD6u    /* 065AD6 */
#define marge_portrait_animations_11_sprites_3_ADDRESS 0x7ADCu    /* 065ADC */
#define marge_portrait_animations_11_sprites_4_ADDRESS 0x7AE2u    /* 065AE2 */
#define marge_portrait_animations_11_sprites_5_ADDRESS 0x7AE8u    /* 065AE8 */
#define marge_portrait_animations_15_ADDRESS 0x7AEEu    /* 065AEE */
#define marge_portrait_animations_15_sprites_ADDRESS 0x7AF6u    /* 065AF6 */
#define marge_portrait_animations_16_ADDRESS 0x7AFCu    /* 065AFC */
#define marge_portrait_animations_16_sprites_ADDRESS 0x7B04u    /* 065B04 */
#define marge_portrait_animations_12_ADDRESS 0x7B10u    /* 065B10 */
#define marge_portrait_animations_12_sprites_ADDRESS 0x7B18u    /* 065B18 */
#define marge_portrait_animations_18_ADDRESS 0x7B1Eu    /* 065B1E */
#define marge_portrait_animations_18_sprites_ADDRESS 0x7B26u    /* 065B26 */
#define marge_portrait_animations_19_ADDRESS 0x7B2Cu    /* 065B2C */
#define marge_portrait_animations_19_sprites_ADDRESS 0x7B34u    /* 065B34 */
#define marge_portrait_animations_20_ADDRESS 0x7B3Au    /* 065B3A */
#define marge_portrait_animations_20_sprites_ADDRESS 0x7B42u    /* 065B42 */
#define marge_portrait_animations_21_ADDRESS 0x7B48u    /* 065B48 */
#define marge_portrait_animations_21_sprites_ADDRESS 0x7B50u    /* 065B50 */
#define marge_portrait_animations_22_ADDRESS 0x7B56u    /* 065B56 */
#define marge_portrait_animations_22_sprites_ADDRESS 0x7B5Eu    /* 065B5E */
#define lisa_portrait_animations_ADDRESS 0x7B64u    /* 065B64 */
#define lisa_portrait_animations_0_ADDRESS 0x7B94u    /* 065B94 */
#define lisa_portrait_animations_0_sprites_ADDRESS 0x7BA0u    /* 065BA0 */
#define lisa_portrait_animations_0_sprites_2_ADDRESS 0x7BB2u    /* 065BB2 */
#define lisa_portrait_animations_1_ADDRESS 0x7BC4u    /* 065BC4 */
#define lisa_portrait_animations_1_sprites_ADDRESS 0x7BCCu    /* 065BCC */
#define lisa_portrait_animations_2_ADDRESS 0x7BD8u    /* 065BD8 */
#define lisa_portrait_animations_2_sprites_ADDRESS 0x7BE8u    /* 065BE8 */
#define lisa_portrait_animations_2_sprites_2_ADDRESS 0x7BF4u    /* 065BF4 */
#define lisa_portrait_animations_2_sprites_3_ADDRESS 0x7C00u    /* 065C00 */
#define lisa_portrait_animations_23_ADDRESS 0x7C0Cu    /* 065C0C */
#define lisa_portrait_animations_3_ADDRESS 0x7C14u    /* 065C14 */
#define lisa_portrait_animations_3_sprites_ADDRESS 0x7C2Cu    /* 065C2C */
#define lisa_portrait_animations_3_sprites_2_ADDRESS 0x7C44u    /* 065C44 */
#define lisa_portrait_animations_3_sprites_3_ADDRESS 0x7C5Cu    /* 065C5C */
#define lisa_portrait_animations_3_sprites_4_ADDRESS 0x7C74u    /* 065C74 */
#define lisa_portrait_animations_23_sprites_ADDRESS 0x7C8Cu    /* 065C8C */
#define lisa_portrait_animations_4_ADDRESS 0x7CA4u    /* 065CA4 */
#define lisa_portrait_animations_4_sprites_ADDRESS 0x7CACu    /* 065CAC */
#define lisa_portrait_animations_5_ADDRESS 0x7CB2u    /* 065CB2 */
#define lisa_portrait_animations_5_sprites_ADDRESS 0x7CBAu    /* 065CBA */
#define lisa_portrait_animations_6_ADDRESS 0x7CC0u    /* 065CC0 */
#define lisa_portrait_animations_6_sprites_ADDRESS 0x7CC8u    /* 065CC8 */
#define lisa_portrait_animations_7_ADDRESS 0x7CE6u    /* 065CE6 */
#define lisa_portrait_animations_7_sprites_ADDRESS 0x7CEEu    /* 065CEE */
#define lisa_portrait_animations_8_ADDRESS 0x7CFAu    /* 065CFA */
#define lisa_portrait_animations_8_sprites_ADDRESS 0x7D02u    /* 065D02 */
#define lisa_portrait_animations_9_ADDRESS 0x7D1Au    /* 065D1A */
#define lisa_portrait_animations_9_sprites_ADDRESS 0x7D2Eu    /* 065D2E */
#define lisa_portrait_animations_9_sprites_2_ADDRESS 0x7D46u    /* 065D46 */
#define lisa_portrait_animations_9_sprites_3_ADDRESS 0x7D5Eu    /* 065D5E */
#define lisa_portrait_animations_9_sprites_3_rest_ADDRESS 0x7D76u    /* 065D76 */
#define lisa_portrait_animations_10_ADDRESS 0x7D8Eu    /* 065D8E */
#define lisa_portrait_animations_10_sprites_ADDRESS 0x7D96u    /* 065D96 */
#define lisa_portrait_animations_15_ADDRESS 0x7DA8u    /* 065DA8 */
#define lisa_portrait_animations_15_sprites_ADDRESS 0x7DB0u    /* 065DB0 */
#define lisa_portrait_animations_16_ADDRESS 0x7DB6u    /* 065DB6 */
#define lisa_portrait_animations_16_sprites_ADDRESS 0x7DBEu    /* 065DBE */
#define lisa_portrait_animations_16_sprites_fill_ADDRESS 0x7DCAu    /* 065DCA */
#define lisa_portrait_animations_16_sprites_rest_ADDRESS 0x7DDAu    /* 065DDA */
#define lisa_portrait_animations_16_sprites_rest_2_ADDRESS 0x7DE2u    /* 065DE2 */
#define lisa_portrait_animations_16_sprites_rest_3_ADDRESS 0x7DE8u    /* 065DE8 */
#define lisa_portrait_animations_16_sprites_rest_4_ADDRESS 0x7DF0u    /* 065DF0 */
#define lisa_portrait_animations_16_sprites_rest_5_ADDRESS 0x7DF6u    /* 065DF6 */
#define lisa_portrait_animations_16_sprites_rest_6_ADDRESS 0x7DFEu    /* 065DFE */
#define lisa_portrait_animations_16_sprites_rest_7_ADDRESS 0x7E04u    /* 065E04 */
#define lisa_portrait_animations_16_sprites_rest_8_ADDRESS 0x7E0Cu    /* 065E0C */
#define lisa_portrait_animations_16_sprites_rest_9_ADDRESS 0x7E12u    /* 065E12 */
#define lisa_portrait_animations_16_sprites_rest_10_ADDRESS 0x7E2Au    /* 065E2A */
#define lisa_portrait_animations_16_sprites_rest_11_ADDRESS 0x7E30u    /* 065E30 */
#define lisa_portrait_animations_16_sprites_rest_12_ADDRESS 0x7E36u    /* 065E36 */
#define lisa_portrait_animations_16_sprites_rest_13_ADDRESS 0x7E3Cu    /* 065E3C */
#define lisa_portrait_animations_16_sprites_rest_14_ADDRESS 0x7E42u    /* 065E42 */
#define lisa_portrait_animations_16_sprites_rest_15_ADDRESS 0x7E48u    /* 065E48 */
#define lisa_portrait_animations_16_sprites_rest_16_ADDRESS 0x7E5Cu    /* 065E5C */
#define lisa_portrait_animations_16_sprites_rest_17_ADDRESS 0x7E62u    /* 065E62 */
#define lisa_portrait_animations_16_sprites_rest_18_ADDRESS 0x7E74u    /* 065E74 */
#define lisa_portrait_animations_16_sprites_rest_19_ADDRESS 0x7E8Cu    /* 065E8C */
#define lisa_portrait_animations_16_sprites_rest_20_ADDRESS 0x7EA4u    /* 065EA4 */
#define lisa_portrait_animations_16_sprites_rest_21_ADDRESS 0x7EB0u    /* 065EB0 */
#define lisa_portrait_animations_16_sprites_rest_22_ADDRESS 0x7EDAu    /* 065EDA */
#define lisa_portrait_animations_16_sprites_rest_23_ADDRESS 0x7F04u    /* 065F04 */
#define lisa_portrait_animations_16_sprites_rest_24_ADDRESS 0x7F0Cu    /* 065F0C */
#define lisa_portrait_animations_16_sprites_rest_25_ADDRESS 0x7F12u    /* 065F12 */
#define lisa_portrait_animations_16_sprites_rest_26_ADDRESS 0x7F1Au    /* 065F1A */
#define lisa_portrait_animations_16_sprites_rest_27_ADDRESS 0x7F38u    /* 065F38 */
#define lisa_portrait_animations_16_sprites_rest_28_ADDRESS 0x7F40u    /* 065F40 */
#define lisa_portrait_animations_16_sprites_rest_29_ADDRESS 0x7F58u    /* 065F58 */
#define lisa_portrait_animations_16_sprites_rest_30_ADDRESS 0x7F60u    /* 065F60 */
#define lisa_portrait_animations_16_sprites_fill_2_ADDRESS 0x7F6Cu    /* 065F6C */
#define lisa_portrait_animations_16_sprites_rest_31_ADDRESS 0x7F6Eu    /* 065F6E */
#define lisa_portrait_animations_16_sprites_rest_32_ADDRESS 0x7F76u    /* 065F76 */
#define lisa_portrait_animations_16_sprites_rest_33_ADDRESS 0x7F7Cu    /* 065F7C */
#define lisa_portrait_animations_16_sprites_rest_34_ADDRESS 0x7F84u    /* 065F84 */
#define lisa_portrait_animations_16_sprites_rest_35_ADDRESS 0x7F8Au    /* 065F8A */
#define lisa_portrait_animations_16_sprites_rest_36_ADDRESS 0x7F92u    /* 065F92 */
#define lisa_portrait_animations_16_sprites_rest_37_ADDRESS 0x7F9Eu    /* 065F9E */
#define lisa_portrait_animations_16_sprites_rest_38_ADDRESS 0x7FAAu    /* 065FAA */
#define lisa_portrait_animations_16_sprites_rest_39_ADDRESS 0x7FB0u    /* 065FB0 */
#define lisa_portrait_animations_16_sprites_rest_40_ADDRESS 0x7FB6u    /* 065FB6 */
#define lisa_portrait_animations_16_sprites_rest_41_ADDRESS 0x7FBEu    /* 065FBE */
#define lisa_portrait_animations_16_sprites_rest_42_ADDRESS 0x7FC4u    /* 065FC4 */
#define lisa_portrait_animations_16_sprites_rest_43_ADDRESS 0x7FCCu    /* 065FCC */
#define lisa_portrait_animations_16_sprites_rest_44_ADDRESS 0x7FD2u    /* 065FD2 */
#define lisa_portrait_animations_16_sprites_rest_45_ADDRESS 0x7FDAu    /* 065FDA */
#define lisa_portrait_animations_16_sprites_rest_46_ADDRESS 0x7FE0u    /* 065FE0 */
#define lisa_portrait_animations_16_sprites_rest_47_ADDRESS 0x7FE8u    /* 065FE8 */
#define lisa_portrait_animations_16_sprites_fill_3_ADDRESS 0x7FEEu    /* 065FEE */
#define lisa_portrait_animations_16_sprites_rest_48_ADDRESS 0x6000u    /* 066000 */
#define lisa_animations_ADDRESS 0x6006u    /* 066006 */
#define lisa_animations_7_ADDRESS 0x6106u    /* 066106 */
#define lisa_animations_7_sprites_ADDRESS 0x610Eu    /* 06610E */
#define lisa_animations_38_ADDRESS 0x611Au    /* 06611A */
#define lisa_animations_38_sprites_ADDRESS 0x6122u    /* 066122 */
#define lisa_animations_63_ADDRESS 0x6128u    /* 066128 */
#define lisa_animations_63_sprites_ADDRESS 0x6130u    /* 066130 */
#define lisa_animations_99_ADDRESS 0x6136u    /* 066136 */
#define lisa_animations_99_sprites_ADDRESS 0x614Eu    /* 06614E */
#define lisa_animations_99_sprites_2_ADDRESS 0x6160u    /* 066160 */
#define lisa_animations_99_sprites_3_ADDRESS 0x616Cu    /* 06616C */
#define lisa_animations_99_sprites_4_ADDRESS 0x617Eu    /* 06617E */
#define lisa_animations_99_sprites_5_ADDRESS 0x6190u    /* 066190 */
#define lisa_animations_103_ADDRESS 0x61A8u    /* 0661A8 */
#define lisa_animations_103_sprites_ADDRESS 0x61CCu    /* 0661CC */
#define lisa_animations_103_sprites_2_ADDRESS 0x61E4u    /* 0661E4 */
#define lisa_animations_103_sprites_3_ADDRESS 0x61FCu    /* 0661FC */
#define lisa_animations_103_sprites_4_ADDRESS 0x6214u    /* 066214 */
#define lisa_animations_103_sprites_5_ADDRESS 0x622Cu    /* 06622C */
#define lisa_animations_103_sprites_6_ADDRESS 0x6244u    /* 066244 */
#define lisa_animations_103_sprites_7_ADDRESS 0x625Cu    /* 06625C */
#define lisa_animations_103_sprites_8_ADDRESS 0x6274u    /* 066274 */
#define lisa_animations_107_ADDRESS 0x628Cu    /* 06628C */
#define lisa_animations_111_ADDRESS 0x6294u    /* 066294 */
#define lisa_animations_115_ADDRESS 0x62B8u    /* 0662B8 */
#define lisa_animations_115_sprites_ADDRESS 0x62C0u    /* 0662C0 */
#define lisa_animations_119_ADDRESS 0x62D8u    /* 0662D8 */
#define lisa_animations_119_sprites_ADDRESS 0x62E0u    /* 0662E0 */
#define lisa_animations_123_ADDRESS 0x62F8u    /* 0662F8 */
#define lisa_animations_123_sprites_ADDRESS 0x630Cu    /* 06630C */
#define lisa_animations_123_sprites_2_ADDRESS 0x631Eu    /* 06631E */
#define lisa_animations_123_sprites_3_ADDRESS 0x6330u    /* 066330 */
#define lisa_animations_123_sprites_4_ADDRESS 0x6348u    /* 066348 */
#define lisa_animations_127_ADDRESS 0x6360u    /* 066360 */
#define lisa_animations_127_sprites_ADDRESS 0x6374u    /* 066374 */
#define lisa_animations_127_sprites_2_ADDRESS 0x6386u    /* 066386 */
#define lisa_animations_127_sprites_3_ADDRESS 0x6398u    /* 066398 */
#define lisa_animations_127_sprites_4_ADDRESS 0x63B0u    /* 0663B0 */
#define lisa_animations_98_ADDRESS 0x63C8u    /* 0663C8 */
#define lisa_animations_98_sprites_ADDRESS 0x63E0u    /* 0663E0 */
#define lisa_animations_98_sprites_2_ADDRESS 0x63F2u    /* 0663F2 */
#define lisa_animations_98_sprites_3_ADDRESS 0x6404u    /* 066404 */
#define lisa_animations_98_sprites_4_ADDRESS 0x641Cu    /* 06641C */
#define lisa_animations_98_sprites_5_ADDRESS 0x642Eu    /* 06642E */
#define lisa_animations_102_ADDRESS 0x6446u    /* 066446 */
#define lisa_animations_106_ADDRESS 0x644Eu    /* 06644E */
#define lisa_animations_110_ADDRESS 0x6456u    /* 066456 */
#define lisa_animations_110_sprites_ADDRESS 0x647Au    /* 06647A */
#define lisa_animations_110_sprites_2_ADDRESS 0x6492u    /* 066492 */
#define lisa_animations_110_sprites_3_ADDRESS 0x64AAu    /* 0664AA */
#define lisa_animations_110_sprites_4_ADDRESS 0x64C2u    /* 0664C2 */
#define lisa_animations_110_sprites_5_ADDRESS 0x64DAu    /* 0664DA */
#define lisa_animations_110_sprites_6_ADDRESS 0x64F2u    /* 0664F2 */
#define lisa_animations_110_sprites_7_ADDRESS 0x650Au    /* 06650A */
#define lisa_animations_110_sprites_8_ADDRESS 0x6522u    /* 066522 */
#define lisa_animations_114_ADDRESS 0x653Au    /* 06653A */
#define lisa_animations_114_sprites_ADDRESS 0x6542u    /* 066542 */
#define lisa_animations_118_ADDRESS 0x655Au    /* 06655A */
#define lisa_animations_118_sprites_ADDRESS 0x6562u    /* 066562 */
#define lisa_animations_122_ADDRESS 0x657Au    /* 06657A */
#define lisa_animations_122_sprites_ADDRESS 0x6586u    /* 066586 */
#define lisa_animations_122_sprites_2_ADDRESS 0x659Eu    /* 06659E */
#define lisa_animations_121_ADDRESS 0x65BCu    /* 0665BC */
#define lisa_animations_121_sprites_ADDRESS 0x65C8u    /* 0665C8 */
#define lisa_animations_121_sprites_2_ADDRESS 0x65DAu    /* 0665DA */
#define lisa_animations_126_ADDRESS 0x65ECu    /* 0665EC */
#define lisa_animations_126_sprites_ADDRESS 0x65F8u    /* 0665F8 */
#define lisa_animations_125_ADDRESS 0x6610u    /* 066610 */
#define lisa_animations_0_ADDRESS 0x661Cu    /* 06661C */
#define lisa_animations_0_sprites_ADDRESS 0x6624u    /* 066624 */
#define lisa_animations_1_ADDRESS 0x6636u    /* 066636 */
#define lisa_animations_1_sprites_ADDRESS 0x665Au    /* 06665A */
#define lisa_animations_1_sprites_2_ADDRESS 0x666Cu    /* 06666C */
#define lisa_animations_1_sprites_3_ADDRESS 0x667Eu    /* 06667E */
#define lisa_animations_1_sprites_4_ADDRESS 0x6690u    /* 066690 */
#define lisa_animations_1_sprites_5_ADDRESS 0x66A2u    /* 0666A2 */
#define lisa_animations_1_sprites_6_ADDRESS 0x66B4u    /* 0666B4 */
#define lisa_animations_1_sprites_7_ADDRESS 0x66C6u    /* 0666C6 */
#define lisa_animations_1_sprites_8_ADDRESS 0x66D8u    /* 0666D8 */
#define lisa_animations_2_ADDRESS 0x66EAu    /* 0666EA */
#define lisa_animations_2_sprites_ADDRESS 0x670Eu    /* 06670E */
#define lisa_animations_2_sprites_2_ADDRESS 0x6714u    /* 066714 */
#define lisa_animations_2_sprites_3_ADDRESS 0x671Au    /* 06671A */
#define lisa_animations_2_sprites_4_ADDRESS 0x6720u    /* 066720 */
#define lisa_animations_2_sprites_5_ADDRESS 0x6726u    /* 066726 */
#define lisa_animations_2_sprites_6_ADDRESS 0x672Cu    /* 06672C */
#define lisa_animations_2_sprites_7_ADDRESS 0x6732u    /* 066732 */
#define lisa_animations_2_sprites_8_ADDRESS 0x6738u    /* 066738 */
#define lisa_animations_3_ADDRESS 0x673Eu    /* 06673E */
#define lisa_animations_3_sprites_ADDRESS 0x6746u    /* 066746 */
#define lisa_animations_4_ADDRESS 0x674Cu    /* 06674C */
#define lisa_animations_4_sprites_ADDRESS 0x6754u    /* 066754 */
#define lisa_animations_8_ADDRESS 0x6766u    /* 066766 */
#define lisa_animations_8_sprites_ADDRESS 0x676Eu    /* 06676E */
#define lisa_animations_9_ADDRESS 0x6780u    /* 066780 */
#define lisa_animations_9_sprites_ADDRESS 0x67A4u    /* 0667A4 */
#define lisa_animations_9_sprites_2_ADDRESS 0x67B6u    /* 0667B6 */
#define lisa_animations_9_sprites_3_ADDRESS 0x67C8u    /* 0667C8 */
#define lisa_animations_9_sprites_4_ADDRESS 0x67DAu    /* 0667DA */
#define lisa_animations_9_sprites_5_ADDRESS 0x67ECu    /* 0667EC */
#define lisa_animations_9_sprites_6_ADDRESS 0x67FEu    /* 0667FE */
#define lisa_animations_9_sprites_7_ADDRESS 0x6810u    /* 066810 */
#define lisa_animations_9_sprites_8_ADDRESS 0x6822u    /* 066822 */
#define lisa_animations_11_ADDRESS 0x6834u    /* 066834 */
#define lisa_animations_11_sprites_ADDRESS 0x683Cu    /* 06683C */
#define lisa_animations_12_ADDRESS 0x684Eu    /* 06684E */
#define lisa_animations_12_sprites_ADDRESS 0x6856u    /* 066856 */
#define lisa_animations_13_ADDRESS 0x6868u    /* 066868 */
#define lisa_animations_13_sprites_ADDRESS 0x6870u    /* 066870 */
#define lisa_animations_16_ADDRESS 0x6882u    /* 066882 */
#define lisa_animations_16_sprites_ADDRESS 0x688Au    /* 06688A */
#define lisa_animations_17_ADDRESS 0x689Cu    /* 06689C */
#define lisa_animations_17_sprites_ADDRESS 0x68C0u    /* 0668C0 */
#define lisa_animations_17_sprites_2_ADDRESS 0x68D2u    /* 0668D2 */
#define lisa_animations_17_sprites_3_ADDRESS 0x68E4u    /* 0668E4 */
#define lisa_animations_17_sprites_4_ADDRESS 0x68F6u    /* 0668F6 */
#define lisa_animations_17_sprites_5_ADDRESS 0x6908u    /* 066908 */
#define lisa_animations_17_sprites_6_ADDRESS 0x691Au    /* 06691A */
#define lisa_animations_17_sprites_7_ADDRESS 0x692Cu    /* 06692C */
#define lisa_animations_17_sprites_8_ADDRESS 0x693Eu    /* 06693E */
#define lisa_animations_19_ADDRESS 0x6950u    /* 066950 */
#define lisa_animations_19_sprites_ADDRESS 0x6958u    /* 066958 */
#define lisa_animations_20_ADDRESS 0x696Au    /* 06696A */
#define lisa_animations_20_sprites_ADDRESS 0x6972u    /* 066972 */
#define lisa_animations_21_ADDRESS 0x6984u    /* 066984 */
#define lisa_animations_21_sprites_ADDRESS 0x698Cu    /* 06698C */
#define lisa_animations_5_ADDRESS 0x699Eu    /* 06699E */
#define lisa_animations_5_sprites_ADDRESS 0x69AAu    /* 0669AA */
#define lisa_animations_5_sprites_2_ADDRESS 0x69BCu    /* 0669BC */
#define lisa_animations_65_ADDRESS 0x69CEu    /* 0669CE */
#define lisa_animations_65_sprites_ADDRESS 0x69DAu    /* 0669DA */
#define lisa_animations_64_ADDRESS 0x69ECu    /* 0669EC */
#define lisa_animations_64_sprites_ADDRESS 0x69F8u    /* 0669F8 */
#define lisa_animations_47_ADDRESS 0x6A0Au    /* 066A0A */
#define lisa_animations_47_sprites_ADDRESS 0x6A26u    /* 066A26 */
#define lisa_animations_47_sprites_2_ADDRESS 0x6A38u    /* 066A38 */
#define lisa_animations_47_sprites_3_ADDRESS 0x6A4Au    /* 066A4A */
#define lisa_animations_47_sprites_4_ADDRESS 0x6A56u    /* 066A56 */
#define lisa_animations_48_ADDRESS 0x6A62u    /* 066A62 */
#define lisa_animations_48_sprites_ADDRESS 0x6A6Eu    /* 066A6E */
#define lisa_animations_48_sprites_2_ADDRESS 0x6A80u    /* 066A80 */
#define lisa_animations_49_ADDRESS 0x6A92u    /* 066A92 */
#define lisa_animations_49_sprites_ADDRESS 0x6A9Eu    /* 066A9E */
#define lisa_animations_49_sprites_2_ADDRESS 0x6AB0u    /* 066AB0 */
#define lisa_animations_53_ADDRESS 0x6AC2u    /* 066AC2 */
#define lisa_animations_53_sprites_ADDRESS 0x6AD6u    /* 066AD6 */
#define lisa_animations_53_sprites_2_ADDRESS 0x6AE8u    /* 066AE8 */
#define lisa_animations_53_sprites_3_ADDRESS 0x6AFAu    /* 066AFA */
#define lisa_animations_53_sprites_4_ADDRESS 0x6B12u    /* 066B12 */
#define lisa_animations_54_ADDRESS 0x6B24u    /* 066B24 */
#define lisa_animations_54_sprites_ADDRESS 0x6B34u    /* 066B34 */
#define lisa_animations_54_sprites_2_ADDRESS 0x6B46u    /* 066B46 */
#define lisa_animations_54_sprites_3_ADDRESS 0x6B58u    /* 066B58 */
#define lisa_animations_61_ADDRESS 0x6B6Au    /* 066B6A */
#define lisa_animations_61_sprites_ADDRESS 0x6B72u    /* 066B72 */
#define lisa_animations_57_ADDRESS 0x6B84u    /* 066B84 */
#define lisa_animations_57_sprites_ADDRESS 0x6BA4u    /* 066BA4 */
#define lisa_animations_57_sprites_2_ADDRESS 0x6BB0u    /* 066BB0 */
#define lisa_animations_57_sprites_3_ADDRESS 0x6BBCu    /* 066BBC */
#define lisa_animations_57_sprites_4_ADDRESS 0x6BC8u    /* 066BC8 */
#define lisa_animations_57_sprites_5_ADDRESS 0x6BD4u    /* 066BD4 */
#define lisa_animations_57_sprites_6_ADDRESS 0x6BE0u    /* 066BE0 */
#define lisa_animations_57_sprites_7_ADDRESS 0x6BECu    /* 066BEC */
#define lisa_animations_55_ADDRESS 0x6BF8u    /* 066BF8 */
#define lisa_animations_55_sprites_ADDRESS 0x6C28u    /* 066C28 */
#define lisa_animations_55_sprites_2_ADDRESS 0x6C3Au    /* 066C3A */
#define lisa_animations_55_sprites_3_ADDRESS 0x6C4Cu    /* 066C4C */
#define lisa_animations_55_sprites_4_ADDRESS 0x6C5Eu    /* 066C5E */
#define lisa_animations_56_ADDRESS 0x6C70u    /* 066C70 */
#define lisa_animations_56_sprites_ADDRESS 0x6CACu    /* 066CAC */
#define lisa_animations_56_sprites_2_ADDRESS 0x6CBEu    /* 066CBE */
#define lisa_animations_56_sprites_3_ADDRESS 0x6CCAu    /* 066CCA */
#define lisa_animations_56_sprites_4_ADDRESS 0x6CD6u    /* 066CD6 */
#define lisa_animations_56_sprites_5_ADDRESS 0x6CE8u    /* 066CE8 */
#define lisa_animations_56_sprites_6_ADDRESS 0x6CFAu    /* 066CFA */
#define lisa_animations_56_sprites_7_ADDRESS 0x6D06u    /* 066D06 */
#define lisa_animations_56_sprites_8_ADDRESS 0x6D12u    /* 066D12 */
#define lisa_animations_56_sprites_9_ADDRESS 0x6D1Eu    /* 066D1E */
#define lisa_animations_56_sprites_10_ADDRESS 0x6D2Au    /* 066D2A */
#define lisa_animations_56_sprites_11_ADDRESS 0x6D36u    /* 066D36 */
#define lisa_animations_56_sprites_12_ADDRESS 0x6D42u    /* 066D42 */
#define lisa_animations_58_ADDRESS 0x6D4Eu    /* 066D4E */
#define lisa_animations_58_sprites_ADDRESS 0x6D5Au    /* 066D5A */
#define lisa_animations_58_sprites_2_ADDRESS 0x6D66u    /* 066D66 */
#define lisa_animations_59_ADDRESS 0x6D72u    /* 066D72 */
#define lisa_animations_59_sprites_ADDRESS 0x6D7Eu    /* 066D7E */
#define lisa_animations_59_sprites_2_ADDRESS 0x6D84u    /* 066D84 */
#define lisa_animations_69_ADDRESS 0x6D8Au    /* 066D8A */
#define lisa_animations_69_sprites_ADDRESS 0x6DA6u    /* 066DA6 */
#define lisa_animations_69_sprites_2_ADDRESS 0x6DACu    /* 066DAC */
#define lisa_animations_69_sprites_3_ADDRESS 0x6DB8u    /* 066DB8 */
#define lisa_animations_69_sprites_4_ADDRESS 0x6DC4u    /* 066DC4 */
#define lisa_animations_69_sprites_5_ADDRESS 0x6DCAu    /* 066DCA */
#define lisa_animations_69_sprites_6_ADDRESS 0x6DD6u    /* 066DD6 */
#define lisa_animations_70_ADDRESS 0x6DE2u    /* 066DE2 */
#define lisa_animations_70_sprites_ADDRESS 0x6DF2u    /* 066DF2 */
#define lisa_animations_70_sprites_2_ADDRESS 0x6E04u    /* 066E04 */
#define lisa_animations_70_sprites_3_ADDRESS 0x6E16u    /* 066E16 */
#define lisa_animations_80_ADDRESS 0x6E2Eu    /* 066E2E */
#define lisa_animations_80_sprites_ADDRESS 0x6E3Au    /* 066E3A */
#define lisa_animations_80_sprites_2_ADDRESS 0x6E4Cu    /* 066E4C */
#define lisa_animations_81_ADDRESS 0x6E5Eu    /* 066E5E */
#define lisa_animations_81_sprites_ADDRESS 0x6E6Au    /* 066E6A */
#define lisa_animations_81_sprites_2_ADDRESS 0x6E7Cu    /* 066E7C */
#define lisa_animations_82_ADDRESS 0x6E8Eu    /* 066E8E */
#define lisa_animations_82_sprites_ADDRESS 0x6E9Au    /* 066E9A */
#define lisa_animations_82_sprites_2_ADDRESS 0x6EACu    /* 066EAC */
#define lisa_animations_83_ADDRESS 0x6EB8u    /* 066EB8 */
#define lisa_animations_83_sprites_ADDRESS 0x6ECCu    /* 066ECC */
#define lisa_animations_83_sprites_2_ADDRESS 0x6EDEu    /* 066EDE */
#define lisa_animations_83_sprites_3_ADDRESS 0x6EF0u    /* 066EF0 */
#define lisa_animations_83_sprites_4_ADDRESS 0x6F02u    /* 066F02 */
#define lisa_animations_84_ADDRESS 0x6F14u    /* 066F14 */
#define lisa_animations_84_sprites_ADDRESS 0x6F28u    /* 066F28 */
#define lisa_animations_84_sprites_2_ADDRESS 0x6F3Au    /* 066F3A */
#define lisa_animations_84_sprites_3_ADDRESS 0x6F46u    /* 066F46 */
#define lisa_animations_84_sprites_4_ADDRESS 0x6F52u    /* 066F52 */
#define lisa_animations_85_ADDRESS 0x6F5Eu    /* 066F5E */
#define lisa_animations_85_sprites_ADDRESS 0x6F72u    /* 066F72 */
#define lisa_animations_85_sprites_2_ADDRESS 0x6F8Au    /* 066F8A */
#define lisa_animations_85_sprites_3_ADDRESS 0x6F9Cu    /* 066F9C */
#define lisa_animations_85_sprites_4_ADDRESS 0x6FA8u    /* 066FA8 */
#define lisa_animations_86_ADDRESS 0x6FB4u    /* 066FB4 */
#define lisa_animations_86_sprites_ADDRESS 0x6FC4u    /* 066FC4 */
#define lisa_animations_86_sprites_2_ADDRESS 0x6FD6u    /* 066FD6 */
#define lisa_animations_86_sprites_3_ADDRESS 0x6FE8u    /* 066FE8 */
#define lisa_animations_87_ADDRESS 0x6FF4u    /* 066FF4 */
#define lisa_animations_92_ADDRESS 0x6FFCu    /* 066FFC */
#define lisa_animations_92_sprites_ADDRESS 0x700Cu    /* 06700C */
#define lisa_animations_92_sprites_2_ADDRESS 0x7018u    /* 067018 */
#define lisa_animations_92_sprites_3_ADDRESS 0x702Au    /* 06702A */
#define lisa_animations_93_ADDRESS 0x703Cu    /* 06703C */
#define lisa_animations_93_sprites_ADDRESS 0x704Cu    /* 06704C */
#define lisa_animations_93_sprites_2_ADDRESS 0x7058u    /* 067058 */
#define lisa_animations_93_sprites_3_ADDRESS 0x7064u    /* 067064 */
#define lisa_animations_78_ADDRESS 0x7076u    /* 067076 */
#define lisa_animations_78_sprites_ADDRESS 0x707Eu    /* 06707E */
#define lisa_animations_88_ADDRESS 0x708Au    /* 06708A */
#define lisa_animations_88_sprites_ADDRESS 0x70AAu    /* 0670AA */
#define lisa_animations_88_sprites_2_ADDRESS 0x70BCu    /* 0670BC */
#define lisa_animations_88_sprites_3_ADDRESS 0x70C8u    /* 0670C8 */
#define lisa_animations_88_sprites_4_ADDRESS 0x70DAu    /* 0670DA */
#define lisa_animations_88_sprites_5_ADDRESS 0x70ECu    /* 0670EC */
#define lisa_animations_88_sprites_6_ADDRESS 0x70F8u    /* 0670F8 */
#define lisa_animations_88_sprites_7_ADDRESS 0x7104u    /* 067104 */
#define lisa_animations_91_ADDRESS 0x711Cu    /* 06711C */
#define lisa_animations_91_sprites_ADDRESS 0x7130u    /* 067130 */
#define lisa_animations_91_sprites_2_ADDRESS 0x713Cu    /* 06713C */
#define lisa_animations_91_sprites_3_ADDRESS 0x7148u    /* 067148 */
#define lisa_animations_91_sprites_4_ADDRESS 0x714Eu    /* 06714E */
#define lisa_animations_94_ADDRESS 0x7154u    /* 067154 */
#define lisa_animations_94_sprites_ADDRESS 0x7160u    /* 067160 */
#define lisa_animations_95_ADDRESS 0x716Cu    /* 06716C */
#define lisa_animations_95_sprites_ADDRESS 0x7180u    /* 067180 */
#define lisa_animations_95_sprites_2_ADDRESS 0x7192u    /* 067192 */
#define lisa_animations_95_sprites_3_ADDRESS 0x71A4u    /* 0671A4 */
#define lisa_animations_95_sprites_4_ADDRESS 0x71B6u    /* 0671B6 */
#define lisa_animations_89_ADDRESS 0x71C8u    /* 0671C8 */
#define lisa_animations_89_sprites_ADDRESS 0x71D4u    /* 0671D4 */
#define lisa_animations_89_sprites_2_ADDRESS 0x71DAu    /* 0671DA */
#define lisa_animations_15_ADDRESS 0x71E0u    /* 0671E0 */
#define lisa_animations_15_sprites_ADDRESS 0x71F0u    /* 0671F0 */
#define lisa_animations_15_sprites_2_ADDRESS 0x71FCu    /* 0671FC */
#define lisa_animations_15_sprites_3_ADDRESS 0x720Eu    /* 06720E */
#define lisa_animations_23_ADDRESS 0x721Au    /* 06721A */
#define lisa_animations_23_sprites_ADDRESS 0x7226u    /* 067226 */
#define lisa_animations_23_sprites_2_ADDRESS 0x7238u    /* 067238 */
#define lisa_animations_31_ADDRESS 0x724Au    /* 06724A */
#define lisa_animations_31_sprites_ADDRESS 0x7256u    /* 067256 */
#define lisa_animations_31_sprites_2_ADDRESS 0x7268u    /* 067268 */
#define lisa_animations_62_ADDRESS 0x7274u    /* 067274 */
#define lisa_animations_62_sprites_ADDRESS 0x7280u    /* 067280 */
#define lisa_animations_62_sprites_2_ADDRESS 0x7292u    /* 067292 */
#define lisa_animations_32_ADDRESS 0x72AAu    /* 0672AA */
#define lisa_animations_32_sprites_ADDRESS 0x72B6u    /* 0672B6 */
#define lisa_animations_32_sprites_2_ADDRESS 0x72C8u    /* 0672C8 */
#define lisa_animations_33_ADDRESS 0x72DAu    /* 0672DA */
#define lisa_animations_33_sprites_ADDRESS 0x72FEu    /* 0672FE */
#define lisa_animations_33_sprites_2_ADDRESS 0x7310u    /* 067310 */
#define lisa_animations_33_sprites_3_ADDRESS 0x7322u    /* 067322 */
#define lisa_animations_33_sprites_4_ADDRESS 0x7334u    /* 067334 */
#define lisa_animations_33_sprites_5_ADDRESS 0x7346u    /* 067346 */
#define lisa_animations_33_sprites_6_ADDRESS 0x7358u    /* 067358 */
#define lisa_animations_33_sprites_7_ADDRESS 0x736Au    /* 06736A */
#define lisa_animations_33_sprites_8_ADDRESS 0x737Cu    /* 06737C */
#define lisa_animations_35_ADDRESS 0x738Eu    /* 06738E */
#define lisa_animations_35_sprites_ADDRESS 0x7396u    /* 067396 */
#define lisa_animations_36_ADDRESS 0x73A8u    /* 0673A8 */
#define lisa_animations_36_sprites_ADDRESS 0x73B0u    /* 0673B0 */
#define lisa_animations_37_ADDRESS 0x73C2u    /* 0673C2 */
#define lisa_animations_51_ADDRESS 0x73CAu    /* 0673CA */
#define lisa_animations_51_sprites_ADDRESS 0x73DAu    /* 0673DA */
#define lisa_animations_51_sprites_2_ADDRESS 0x73ECu    /* 0673EC */
#define lisa_animations_51_sprites_3_ADDRESS 0x73FEu    /* 0673FE */
#define lisa_animations_67_ADDRESS 0x7410u    /* 067410 */
#define lisa_animations_67_sprites_ADDRESS 0x7420u    /* 067420 */
#define lisa_animations_67_sprites_2_ADDRESS 0x7432u    /* 067432 */
#define lisa_animations_24_ADDRESS 0x7444u    /* 067444 */
#define lisa_animations_24_sprites_ADDRESS 0x744Cu    /* 06744C */
#define lisa_animations_25_ADDRESS 0x745Eu    /* 06745E */
#define lisa_animations_25_sprites_ADDRESS 0x7482u    /* 067482 */
#define lisa_animations_25_sprites_2_ADDRESS 0x7494u    /* 067494 */
#define lisa_animations_25_sprites_3_ADDRESS 0x74ACu    /* 0674AC */
#define lisa_animations_25_sprites_4_ADDRESS 0x74C4u    /* 0674C4 */
#define lisa_animations_25_sprites_5_ADDRESS 0x74D6u    /* 0674D6 */
#define lisa_animations_25_sprites_6_ADDRESS 0x74E8u    /* 0674E8 */
#define lisa_animations_25_sprites_7_ADDRESS 0x7500u    /* 067500 */
#define lisa_animations_25_sprites_8_ADDRESS 0x7518u    /* 067518 */
#define lisa_animations_27_ADDRESS 0x752Au    /* 06752A */
#define lisa_animations_27_sprites_ADDRESS 0x7532u    /* 067532 */
#define lisa_animations_28_ADDRESS 0x7544u    /* 067544 */
#define lisa_animations_28_sprites_ADDRESS 0x754Cu    /* 06754C */
#define lisa_animations_29_ADDRESS 0x7564u    /* 067564 */
#define lisa_animations_29_sprites_ADDRESS 0x7570u    /* 067570 */
#define lisa_animations_50_ADDRESS 0x758Eu    /* 06758E */
#define lisa_animations_50_sprites_ADDRESS 0x75A2u    /* 0675A2 */
#define lisa_animations_50_sprites_2_ADDRESS 0x75BAu    /* 0675BA */
#define lisa_animations_50_sprites_3_ADDRESS 0x75CCu    /* 0675CC */
#define lisa_animations_50_sprites_4_ADDRESS 0x75DEu    /* 0675DE */
#define lisa_animations_66_ADDRESS 0x75F0u    /* 0675F0 */
#define lisa_animations_66_sprites_ADDRESS 0x7604u    /* 067604 */
#define lisa_animations_66_sprites_2_ADDRESS 0x761Cu    /* 06761C */
#define lisa_animations_66_sprites_3_ADDRESS 0x762Eu    /* 06762E */
#define lisa_animations_66_sprites_4_ADDRESS 0x7640u    /* 067640 */
#define lisa_animations_14_ADDRESS 0x7652u    /* 067652 */
#define lisa_animations_14_sprites_ADDRESS 0x765Au    /* 06765A */
#define lisa_animations_40_ADDRESS 0x7660u    /* 067660 */
#define lisa_animations_40_sprites_ADDRESS 0x7668u    /* 067668 */
#define lisa_animations_41_ADDRESS 0x7680u    /* 067680 */
#define lisa_animations_41_sprites_ADDRESS 0x76A4u    /* 0676A4 */
#define lisa_animations_41_sprites_2_ADDRESS 0x76BCu    /* 0676BC */
#define lisa_animations_41_sprites_3_ADDRESS 0x76D4u    /* 0676D4 */
#define lisa_animations_41_sprites_4_ADDRESS 0x76ECu    /* 0676EC */
#define lisa_animations_41_sprites_5_ADDRESS 0x7704u    /* 067704 */
#define lisa_animations_41_sprites_6_ADDRESS 0x771Cu    /* 06771C */
#define lisa_animations_41_sprites_7_ADDRESS 0x7734u    /* 067734 */
#define lisa_animations_41_sprites_8_ADDRESS 0x774Cu    /* 06774C */
#define lisa_animations_43_ADDRESS 0x7764u    /* 067764 */
#define lisa_animations_43_sprites_ADDRESS 0x776Cu    /* 06776C */
#define lisa_animations_44_ADDRESS 0x7784u    /* 067784 */
#define lisa_animations_44_sprites_ADDRESS 0x778Cu    /* 06778C */
#define lisa_animations_45_ADDRESS 0x77A4u    /* 0677A4 */
#define lisa_animations_52_ADDRESS 0x77ACu    /* 0677AC */
#define lisa_animations_52_sprites_ADDRESS 0x77BCu    /* 0677BC */
#define lisa_animations_52_sprites_2_ADDRESS 0x77D4u    /* 0677D4 */
#define lisa_animations_52_sprites_3_ADDRESS 0x77E6u    /* 0677E6 */
#define lisa_animations_68_ADDRESS 0x77F8u    /* 0677F8 */
#define lisa_animations_68_sprites_ADDRESS 0x7808u    /* 067808 */
#define lisa_animations_68_sprites_2_ADDRESS 0x7820u    /* 067820 */
#define lisa_animations_68_sprites_3_ADDRESS 0x7832u    /* 067832 */
#define lisa_animations_73_ADDRESS 0x7844u    /* 067844 */
#define lisa_animations_73_sprites_ADDRESS 0x7850u    /* 067850 */
#define lisa_animations_73_sprites_2_ADDRESS 0x785Cu    /* 06785C */
#define lisa_animations_75_ADDRESS 0x786Eu    /* 06786E */
#define lisa_animations_75_sprites_ADDRESS 0x7876u    /* 067876 */
#define lisa_animations_77_ADDRESS 0x787Cu    /* 06787C */
#define lisa_animations_77_sprites_ADDRESS 0x7888u    /* 067888 */
#define lisa_animations_30_ADDRESS 0x788Eu    /* 06788E */
#define lisa_animations_30_sprites_ADDRESS 0x789Au    /* 06789A */
#define lisa_animations_30_sprites_2_ADDRESS 0x78ACu    /* 0678AC */
#define lisa_animations_6_ADDRESS 0x78BEu    /* 0678BE */
#define lisa_animations_6_sprites_ADDRESS 0x78D2u    /* 0678D2 */
#define lisa_animations_6_sprites_2_ADDRESS 0x78EAu    /* 0678EA */
#define lisa_animations_6_sprites_3_ADDRESS 0x78FCu    /* 0678FC */
#define lisa_animations_6_sprites_4_ADDRESS 0x7914u    /* 067914 */
#define lisa_animations_22_ADDRESS 0x7932u    /* 067932 */
#define lisa_animations_22_sprites_ADDRESS 0x7956u    /* 067956 */
#define lisa_animations_22_sprites_2_ADDRESS 0x796Eu    /* 06796E */
#define lisa_animations_22_sprites_3_ADDRESS 0x7986u    /* 067986 */
#define lisa_animations_22_sprites_4_ADDRESS 0x7992u    /* 067992 */
#define lisa_animations_22_sprites_5_ADDRESS 0x799Eu    /* 06799E */
#define lisa_animations_22_sprites_6_ADDRESS 0x79B6u    /* 0679B6 */
#define lisa_animations_22_sprites_7_ADDRESS 0x79C8u    /* 0679C8 */
#define lisa_animations_22_sprites_8_ADDRESS 0x79E0u    /* 0679E0 */
#define lisa_animations_39_ADDRESS 0x79F8u    /* 0679F8 */
#define lisa_animations_39_sprites_ADDRESS 0x7A04u    /* 067A04 */
#define lisa_animations_39_sprites_2_ADDRESS 0x7A10u    /* 067A10 */
#define lisa_animations_46_ADDRESS 0x7A1Cu    /* 067A1C */
#define lisa_animations_46_sprites_ADDRESS 0x7A28u    /* 067A28 */
#define lisa_animations_46_sprites_2_ADDRESS 0x7A34u    /* 067A34 */
#define homer_portrait_animations_ADDRESS 0x7A3Au    /* 067A3A */
#define homer_portrait_animations_0_ADDRESS 0x7A6Au    /* 067A6A */
#define homer_portrait_animations_0_sprites_ADDRESS 0x7A76u    /* 067A76 */
#define homer_portrait_animations_0_sprites_2_ADDRESS 0x7A88u    /* 067A88 */
#define homer_portrait_animations_1_ADDRESS 0x7A9Au    /* 067A9A */
#define homer_portrait_animations_1_sprites_ADDRESS 0x7AA2u    /* 067AA2 */
#define homer_portrait_animations_2_ADDRESS 0x7AAEu    /* 067AAE */
#define homer_portrait_animations_2_sprites_ADDRESS 0x7ABEu    /* 067ABE */
#define homer_portrait_animations_2_sprites_2_ADDRESS 0x7ACAu    /* 067ACA */
#define homer_portrait_animations_2_sprites_3_ADDRESS 0x7AD6u    /* 067AD6 */
#define homer_portrait_animations_23_ADDRESS 0x7AE2u    /* 067AE2 */
#define homer_portrait_animations_3_ADDRESS 0x7AEAu    /* 067AEA */
#define homer_portrait_animations_3_sprites_ADDRESS 0x7AFEu    /* 067AFE */
#define homer_portrait_animations_3_sprites_2_ADDRESS 0x7B0Au    /* 067B0A */
#define homer_portrait_animations_3_sprites_3_ADDRESS 0x7B16u    /* 067B16 */
#define homer_portrait_animations_23_sprites_ADDRESS 0x7B22u    /* 067B22 */
#define homer_portrait_animations_4_ADDRESS 0x7B2Eu    /* 067B2E */
#define homer_portrait_animations_4_sprites_ADDRESS 0x7B36u    /* 067B36 */
#define homer_portrait_animations_5_ADDRESS 0x7B3Cu    /* 067B3C */
#define homer_portrait_animations_5_sprites_ADDRESS 0x7B44u    /* 067B44 */
#define homer_portrait_animations_6_ADDRESS 0x7B4Au    /* 067B4A */
#define homer_portrait_animations_6_sprites_ADDRESS 0x7B52u    /* 067B52 */
#define homer_portrait_animations_7_ADDRESS 0x7B5Eu    /* 067B5E */
#define homer_portrait_animations_7_sprites_ADDRESS 0x7B66u    /* 067B66 */
#define homer_portrait_animations_8_ADDRESS 0x7B72u    /* 067B72 */
#define homer_portrait_animations_8_sprites_ADDRESS 0x7B7Au    /* 067B7A */
#define homer_portrait_animations_9_ADDRESS 0x7B86u    /* 067B86 */
#define homer_portrait_animations_9_sprites_ADDRESS 0x7BA2u    /* 067BA2 */
#define homer_portrait_animations_9_sprites_2_ADDRESS 0x7BC6u    /* 067BC6 */
#define homer_portrait_animations_9_sprites_3_ADDRESS 0x7BEAu    /* 067BEA */
#define homer_portrait_animations_9_sprites_4_ADDRESS 0x7C0Eu    /* 067C0E */
#define homer_portrait_animations_9_sprites_5_ADDRESS 0x7C32u    /* 067C32 */
#define homer_portrait_animations_9_sprites_6_ADDRESS 0x7C56u    /* 067C56 */
#define homer_portrait_animations_10_ADDRESS 0x7C7Au    /* 067C7A */
#define homer_portrait_animations_10_sprites_ADDRESS 0x7C82u    /* 067C82 */
#define homer_portrait_animations_11_ADDRESS 0x7C8Eu    /* 067C8E */
#define homer_portrait_animations_11_sprites_ADDRESS 0x7CA6u    /* 067CA6 */
#define homer_portrait_animations_11_sprites_2_ADDRESS 0x7CB2u    /* 067CB2 */
#define homer_portrait_animations_11_sprites_3_ADDRESS 0x7CBEu    /* 067CBE */
#define homer_portrait_animations_11_sprites_4_ADDRESS 0x7CCAu    /* 067CCA */
#define homer_portrait_animations_11_sprites_5_ADDRESS 0x7CD6u    /* 067CD6 */
#define homer_portrait_animations_15_ADDRESS 0x7CE2u    /* 067CE2 */
#define homer_portrait_animations_15_sprites_ADDRESS 0x7CEAu    /* 067CEA */
#define homer_portrait_animations_16_ADDRESS 0x7CF0u    /* 067CF0 */
#define homer_portrait_animations_16_sprites_ADDRESS 0x7CF8u    /* 067CF8 */
#define homer_portrait_animations_12_ADDRESS 0x7D04u    /* 067D04 */
#define homer_portrait_animations_12_sprites_ADDRESS 0x7D0Cu    /* 067D0C */
#define homer_portrait_animations_18_ADDRESS 0x7D18u    /* 067D18 */
#define homer_portrait_animations_18_sprites_ADDRESS 0x7D20u    /* 067D20 */
#define homer_portrait_animations_19_ADDRESS 0x7D2Cu    /* 067D2C */
#define homer_portrait_animations_19_sprites_ADDRESS 0x7D34u    /* 067D34 */
#define homer_portrait_animations_20_ADDRESS 0x7D40u    /* 067D40 */
#define homer_portrait_animations_20_sprites_ADDRESS 0x7D48u    /* 067D48 */
#define homer_portrait_animations_21_ADDRESS 0x7D54u    /* 067D54 */
#define homer_portrait_animations_21_sprites_ADDRESS 0x7D5Cu    /* 067D5C */
#define homer_portrait_animations_22_ADDRESS 0x7D68u    /* 067D68 */
#define homer_portrait_animations_22_sprites_ADDRESS 0x7D70u    /* 067D70 */
#define bart_portrait_animations_ADDRESS 0x7D7Cu    /* 067D7C */
#define bart_portrait_animations_0_ADDRESS 0x7DACu    /* 067DAC */
#define bart_portrait_animations_0_sprites_ADDRESS 0x7DB8u    /* 067DB8 */
#define bart_portrait_animations_0_sprites_2_ADDRESS 0x7DD0u    /* 067DD0 */
#define bart_portrait_animations_1_ADDRESS 0x7DE8u    /* 067DE8 */
#define bart_portrait_animations_1_sprites_ADDRESS 0x7DF0u    /* 067DF0 */
#define bart_portrait_animations_2_ADDRESS 0x7DFCu    /* 067DFC */
#define bart_portrait_animations_2_sprites_ADDRESS 0x7E0Cu    /* 067E0C */
#define bart_portrait_animations_2_sprites_2_ADDRESS 0x7E18u    /* 067E18 */
#define bart_portrait_animations_2_sprites_3_ADDRESS 0x7E24u    /* 067E24 */
#define bart_portrait_animations_23_ADDRESS 0x7E30u    /* 067E30 */
#define bart_portrait_animations_3_ADDRESS 0x7E38u    /* 067E38 */
#define bart_portrait_animations_3_sprites_ADDRESS 0x7E4Cu    /* 067E4C */
#define bart_portrait_animations_3_sprites_2_ADDRESS 0x7E64u    /* 067E64 */
#define bart_portrait_animations_3_sprites_3_ADDRESS 0x7E7Cu    /* 067E7C */
#define bart_portrait_animations_23_sprites_ADDRESS 0x7E94u    /* 067E94 */
#define bart_portrait_animations_4_ADDRESS 0x7EACu    /* 067EAC */
#define bart_portrait_animations_4_sprites_ADDRESS 0x7EB4u    /* 067EB4 */
#define bart_portrait_animations_5_ADDRESS 0x7EBAu    /* 067EBA */
#define bart_portrait_animations_5_sprites_ADDRESS 0x7EC2u    /* 067EC2 */
#define bart_portrait_animations_6_ADDRESS 0x7EC8u    /* 067EC8 */
#define bart_portrait_animations_6_sprites_ADDRESS 0x7ED0u    /* 067ED0 */
#define bart_portrait_animations_7_ADDRESS 0x7EDCu    /* 067EDC */
#define bart_portrait_animations_7_sprites_ADDRESS 0x7EE4u    /* 067EE4 */
#define bart_portrait_animations_8_ADDRESS 0x7EF0u    /* 067EF0 */
#define bart_portrait_animations_8_sprites_ADDRESS 0x7EF8u    /* 067EF8 */
#define bart_portrait_animations_9_ADDRESS 0x7F04u    /* 067F04 */
#define bart_portrait_animations_9_sprites_ADDRESS 0x7F14u    /* 067F14 */
#define bart_portrait_animations_9_sprites_2_ADDRESS 0x7F20u    /* 067F20 */
#define bart_portrait_animations_9_sprites_3_ADDRESS 0x7F2Cu    /* 067F2C */
#define bart_portrait_animations_10_ADDRESS 0x7F38u    /* 067F38 */
#define bart_portrait_animations_10_sprites_ADDRESS 0x7F40u    /* 067F40 */
#define bart_portrait_animations_15_ADDRESS 0x7F4Cu    /* 067F4C */
#define bart_portrait_animations_15_sprites_ADDRESS 0x7F54u    /* 067F54 */
#define bart_portrait_animations_16_ADDRESS 0x7F5Au    /* 067F5A */
#define bart_portrait_animations_16_sprites_ADDRESS 0x7F62u    /* 067F62 */
#define bart_portrait_animations_16_sprites_rest_ADDRESS 0x7F6Eu    /* 067F6E */
#define bart_portrait_animations_16_sprites_rest_2_ADDRESS 0x7F76u    /* 067F76 */
#define bart_portrait_animations_16_sprites_rest_3_ADDRESS 0x7F7Cu    /* 067F7C */
#define bart_portrait_animations_16_sprites_rest_4_ADDRESS 0x7F84u    /* 067F84 */
#define bart_portrait_animations_16_sprites_rest_5_ADDRESS 0x7F8Au    /* 067F8A */
#define bart_portrait_animations_16_sprites_rest_6_ADDRESS 0x7F92u    /* 067F92 */
#define bart_portrait_animations_16_sprites_rest_7_ADDRESS 0x7F9Eu    /* 067F9E */
#define bart_portrait_animations_16_sprites_rest_8_ADDRESS 0x7FAAu    /* 067FAA */
#define bart_portrait_animations_16_sprites_rest_9_ADDRESS 0x7FB0u    /* 067FB0 */
#define bart_portrait_animations_16_sprites_rest_10_ADDRESS 0x7FB6u    /* 067FB6 */
#define bart_portrait_animations_16_sprites_rest_11_ADDRESS 0x7FBEu    /* 067FBE */
#define bart_portrait_animations_16_sprites_rest_12_ADDRESS 0x7FC4u    /* 067FC4 */
#define bart_portrait_animations_16_sprites_rest_13_ADDRESS 0x7FCCu    /* 067FCC */
#define bart_portrait_animations_16_sprites_rest_14_ADDRESS 0x7FD2u    /* 067FD2 */
#define bart_portrait_animations_16_sprites_rest_15_ADDRESS 0x7FDAu    /* 067FDA */
#define bart_portrait_animations_16_sprites_rest_16_ADDRESS 0x7FE0u    /* 067FE0 */
#define bart_portrait_animations_16_sprites_rest_17_ADDRESS 0x7FE8u    /* 067FE8 */
#define bart_portrait_animations_16_sprites_fill_ADDRESS 0x7FEEu    /* 067FEE */
#define bart_portrait_animations_16_sprites_rest_18_ADDRESS 0x6000u    /* 068000 */
#define screen_pieces_animations_ADDRESS 0x6006u    /* 068006 */
#define screen_pieces_animations_0_ADDRESS 0x609Cu    /* 06809C */
#define screen_pieces_animations_0_sprites_ADDRESS 0x60A4u    /* 0680A4 */
#define screen_pieces_animations_1_ADDRESS 0x60AAu    /* 0680AA */
#define screen_pieces_animations_1_sprites_ADDRESS 0x60B2u    /* 0680B2 */
#define screen_pieces_animations_2_ADDRESS 0x60C4u    /* 0680C4 */
#define screen_pieces_animations_2_sprites_ADDRESS 0x60D4u    /* 0680D4 */
#define screen_pieces_animations_2_sprites_2_ADDRESS 0x60E6u    /* 0680E6 */
#define screen_pieces_animations_2_sprites_3_ADDRESS 0x60F8u    /* 0680F8 */
#define screen_pieces_animations_3_ADDRESS 0x610Au    /* 06810A */
#define screen_pieces_animations_3_sprites_ADDRESS 0x6112u    /* 068112 */
#define screen_pieces_animations_4_ADDRESS 0x6124u    /* 068124 */
#define screen_pieces_animations_4_sprites_ADDRESS 0x612Cu    /* 06812C */
#define screen_pieces_animations_5_ADDRESS 0x6132u    /* 068132 */
#define screen_pieces_animations_5_sprites_ADDRESS 0x613Au    /* 06813A */
#define screen_pieces_animations_6_ADDRESS 0x6146u    /* 068146 */
#define screen_pieces_animations_6_sprites_ADDRESS 0x614Eu    /* 06814E */
#define screen_pieces_animations_7_ADDRESS 0x6160u    /* 068160 */
#define screen_pieces_animations_7_sprites_ADDRESS 0x6168u    /* 068168 */
#define screen_pieces_animations_8_ADDRESS 0x616Eu    /* 06816E */
#define screen_pieces_animations_8_sprites_ADDRESS 0x6176u    /* 068176 */
#define screen_pieces_animations_9_ADDRESS 0x617Cu    /* 06817C */
#define screen_pieces_animations_9_sprites_ADDRESS 0x619Cu    /* 06819C */
#define screen_pieces_animations_9_sprites_2_ADDRESS 0x61A2u    /* 0681A2 */
#define screen_pieces_animations_9_sprites_3_ADDRESS 0x61A8u    /* 0681A8 */
#define screen_pieces_animations_9_sprites_4_ADDRESS 0x61AEu    /* 0681AE */
#define screen_pieces_animations_9_sprites_5_ADDRESS 0x61BAu    /* 0681BA */
#define screen_pieces_animations_9_sprites_6_ADDRESS 0x61C6u    /* 0681C6 */
#define screen_pieces_animations_9_sprites_7_ADDRESS 0x61D2u    /* 0681D2 */
#define screen_pieces_animations_10_ADDRESS 0x61D8u    /* 0681D8 */
#define screen_pieces_animations_10_sprites_ADDRESS 0x61E0u    /* 0681E0 */
#define screen_pieces_animations_11_ADDRESS 0x61E6u    /* 0681E6 */
#define screen_pieces_animations_11_sprites_ADDRESS 0x61EEu    /* 0681EE */
#define screen_pieces_animations_12_ADDRESS 0x61FAu    /* 0681FA */
#define screen_pieces_animations_12_sprites_ADDRESS 0x6202u    /* 068202 */
#define screen_pieces_animations_13_ADDRESS 0x620Eu    /* 06820E */
#define screen_pieces_animations_13_sprites_ADDRESS 0x6216u    /* 068216 */
#define screen_pieces_animations_14_ADDRESS 0x6222u    /* 068222 */
#define screen_pieces_animations_14_sprites_ADDRESS 0x622Au    /* 06822A */
#define screen_pieces_animations_15_ADDRESS 0x6236u    /* 068236 */
#define screen_pieces_animations_15_sprites_ADDRESS 0x623Eu    /* 06823E */
#define screen_pieces_animations_16_ADDRESS 0x624Au    /* 06824A */
#define screen_pieces_animations_16_sprites_ADDRESS 0x6252u    /* 068252 */
#define screen_pieces_animations_20_ADDRESS 0x6282u    /* 068282 */
#define screen_pieces_animations_20_sprites_ADDRESS 0x628Au    /* 06828A */
#define screen_pieces_animations_21_ADDRESS 0x6290u    /* 068290 */
#define screen_pieces_animations_21_sprites_ADDRESS 0x629Cu    /* 06829C */
#define screen_pieces_animations_21_sprites_2_ADDRESS 0x62A8u    /* 0682A8 */
#define screen_pieces_animations_22_ADDRESS 0x62B4u    /* 0682B4 */
#define screen_pieces_animations_22_sprites_ADDRESS 0x62C8u    /* 0682C8 */
#define screen_pieces_animations_22_sprites_2_ADDRESS 0x62E6u    /* 0682E6 */
#define screen_pieces_animations_22_sprites_3_ADDRESS 0x62FEu    /* 0682FE */
#define screen_pieces_animations_22_sprites_4_ADDRESS 0x6316u    /* 068316 */
#define screen_pieces_animations_23_ADDRESS 0x6346u    /* 068346 */
#define screen_pieces_animations_23_sprites_ADDRESS 0x635Au    /* 06835A */
#define screen_pieces_animations_23_sprites_2_ADDRESS 0x6390u    /* 068390 */
#define screen_pieces_animations_23_sprites_3_ADDRESS 0x63C0u    /* 0683C0 */
#define screen_pieces_animations_23_sprites_4_ADDRESS 0x6408u    /* 068408 */
#define screen_pieces_animations_24_ADDRESS 0x6450u    /* 068450 */
#define screen_pieces_animations_24_sprites_ADDRESS 0x6460u    /* 068460 */
#define screen_pieces_animations_24_sprites_2_ADDRESS 0x6490u    /* 068490 */
#define screen_pieces_animations_26_ADDRESS 0x64C0u    /* 0684C0 */
#define screen_pieces_animations_27_ADDRESS 0x64C8u    /* 0684C8 */
#define screen_pieces_animations_28_ADDRESS 0x64D0u    /* 0684D0 */
#define screen_pieces_animations_29_ADDRESS 0x64D8u    /* 0684D8 */
#define screen_pieces_animations_26_sprites_ADDRESS 0x64E0u    /* 0684E0 */
#define screen_pieces_animations_28_sprites_ADDRESS 0x652Eu    /* 06852E */
#define screen_pieces_animations_27_sprites_ADDRESS 0x654Cu    /* 06854C */
#define screen_pieces_animations_29_sprites_ADDRESS 0x658Eu    /* 06858E */
#define screen_pieces_animations_33_ADDRESS 0x65B2u    /* 0685B2 */
#define screen_pieces_animations_33_sprites_ADDRESS 0x65BAu    /* 0685BA */
#define screen_pieces_animations_34_ADDRESS 0x65C0u    /* 0685C0 */
#define screen_pieces_animations_34_sprites_ADDRESS 0x65C8u    /* 0685C8 */
#define screen_pieces_animations_32_ADDRESS 0x65CEu    /* 0685CE */
#define screen_pieces_animations_32_sprites_ADDRESS 0x65D6u    /* 0685D6 */
#define screen_pieces_animations_31_ADDRESS 0x65DCu    /* 0685DC */
#define screen_pieces_animations_31_sprites_ADDRESS 0x65E4u    /* 0685E4 */
#define screen_pieces_animations_30_ADDRESS 0x6614u    /* 068614 */
#define screen_pieces_animations_30_sprites_ADDRESS 0x6624u    /* 068624 */
#define screen_pieces_animations_30_sprites_2_ADDRESS 0x663Cu    /* 06863C */
#define screen_pieces_animations_30_sprites_3_ADDRESS 0x6678u    /* 068678 */
#define screen_pieces_animations_35_ADDRESS 0x6696u    /* 068696 */
#define screen_pieces_animations_35_sprites_ADDRESS 0x669Eu    /* 06869E */
#define screen_pieces_animations_25_ADDRESS 0x66C2u    /* 0686C2 */
#define screen_pieces_animations_25_sprites_ADDRESS 0x66CAu    /* 0686CA */
#define screen_pieces_animations_36_ADDRESS 0x66D0u    /* 0686D0 */
#define screen_pieces_animations_36_sprites_ADDRESS 0x66D8u    /* 0686D8 */
#define screen_pieces_animations_37_ADDRESS 0x671Au    /* 06871A */
#define screen_pieces_animations_37_sprites_ADDRESS 0x673Eu    /* 06873E */
#define screen_pieces_animations_37_sprites_2_ADDRESS 0x6744u    /* 068744 */
#define screen_pieces_animations_37_sprites_3_ADDRESS 0x674Au    /* 06874A */
#define screen_pieces_animations_37_sprites_4_ADDRESS 0x6750u    /* 068750 */
#define screen_pieces_animations_37_sprites_5_ADDRESS 0x6756u    /* 068756 */
#define screen_pieces_animations_37_sprites_6_ADDRESS 0x6762u    /* 068762 */
#define screen_pieces_animations_37_sprites_7_ADDRESS 0x6768u    /* 068768 */
#define screen_pieces_animations_37_sprites_8_ADDRESS 0x676Eu    /* 06876E */
#define screen_pieces_animations_38_ADDRESS 0x6774u    /* 068774 */
#define screen_pieces_animations_38_sprites_ADDRESS 0x677Cu    /* 06877C */
#define screen_pieces_animations_39_ADDRESS 0x6788u    /* 068788 */
#define screen_pieces_animations_39_sprites_ADDRESS 0x6790u    /* 068790 */
#define screen_pieces_animations_40_ADDRESS 0x67A8u    /* 0687A8 */
#define screen_pieces_animations_40_sprites_ADDRESS 0x67D8u    /* 0687D8 */
#define screen_pieces_animations_40_sprites_2_ADDRESS 0x6814u    /* 068814 */
#define screen_pieces_animations_40_sprites_3_ADDRESS 0x684Au    /* 06884A */
#define screen_pieces_animations_40_sprites_4_ADDRESS 0x689Eu    /* 06889E */
#define screen_pieces_animations_40_sprites_5_ADDRESS 0x68F8u    /* 0688F8 */
#define screen_pieces_animations_40_sprites_6_ADDRESS 0x6952u    /* 068952 */
#define screen_pieces_animations_40_sprites_7_ADDRESS 0x69ACu    /* 0689AC */
#define screen_pieces_animations_40_sprites_8_ADDRESS 0x6A06u    /* 068A06 */
#define screen_pieces_animations_40_sprites_9_ADDRESS 0x6A60u    /* 068A60 */
#define screen_pieces_animations_41_ADDRESS 0x6A7Eu    /* 068A7E */
#define screen_pieces_animations_41_sprites_ADDRESS 0x6A86u    /* 068A86 */
#define screen_pieces_animations_42_ADDRESS 0x6A92u    /* 068A92 */
#define screen_pieces_animations_42_sprites_ADDRESS 0x6AA2u    /* 068AA2 */
#define screen_pieces_animations_42_sprites_2_ADDRESS 0x6AAEu    /* 068AAE */
#define screen_pieces_animations_42_sprites_3_ADDRESS 0x6ABAu    /* 068ABA */
#define screen_pieces_animations_43_ADDRESS 0x6ACCu    /* 068ACC */
#define screen_pieces_animations_43_sprites_ADDRESS 0x6AD8u    /* 068AD8 */
#define screen_pieces_animations_43_sprites_2_ADDRESS 0x6AF0u    /* 068AF0 */
#define screen_pieces_animations_44_ADDRESS 0x6B02u    /* 068B02 */
#define screen_pieces_animations_44_sprites_ADDRESS 0x6B0Au    /* 068B0A */
#define screen_pieces_animations_45_ADDRESS 0x6B2Eu    /* 068B2E */
#define screen_pieces_animations_45_sprites_ADDRESS 0x6B36u    /* 068B36 */
#define screen_pieces_animations_47_ADDRESS 0x6B48u    /* 068B48 */
#define screen_pieces_animations_47_sprites_ADDRESS 0x6B50u    /* 068B50 */
#define screen_pieces_animations_58_ADDRESS 0x6B5Cu    /* 068B5C */
#define screen_pieces_animations_58_sprites_ADDRESS 0x6B64u    /* 068B64 */
#define screen_pieces_animations_59_ADDRESS 0x6B7Cu    /* 068B7C */
#define screen_pieces_animations_59_sprites_ADDRESS 0x6B84u    /* 068B84 */
#define screen_pieces_animations_60_ADDRESS 0x6BA2u    /* 068BA2 */
#define screen_pieces_animations_60_sprites_ADDRESS 0x6BAAu    /* 068BAA */
#define screen_pieces_animations_61_ADDRESS 0x6BFEu    /* 068BFE */
#define screen_pieces_animations_61_sprites_ADDRESS 0x6C06u    /* 068C06 */
#define screen_pieces_animations_62_ADDRESS 0x6C1Eu    /* 068C1E */
#define screen_pieces_animations_62_sprites_ADDRESS 0x6C26u    /* 068C26 */
#define screen_pieces_animations_48_ADDRESS 0x6C7Au    /* 068C7A */
#define screen_pieces_animations_48_sprites_ADDRESS 0x6C82u    /* 068C82 */
#define screen_pieces_animations_49_ADDRESS 0x6C88u    /* 068C88 */
#define screen_pieces_animations_49_sprites_ADDRESS 0x6C90u    /* 068C90 */
#define screen_pieces_animations_50_ADDRESS 0x6C96u    /* 068C96 */
#define screen_pieces_animations_50_sprites_ADDRESS 0x6C9Eu    /* 068C9E */
#define screen_pieces_animations_51_ADDRESS 0x6CA4u    /* 068CA4 */
#define screen_pieces_animations_51_sprites_ADDRESS 0x6CACu    /* 068CAC */
#define screen_pieces_animations_52_ADDRESS 0x6CB2u    /* 068CB2 */
#define screen_pieces_animations_52_sprites_ADDRESS 0x6CBAu    /* 068CBA */
#define screen_pieces_animations_53_ADDRESS 0x6CC0u    /* 068CC0 */
#define screen_pieces_animations_53_sprites_ADDRESS 0x6CC8u    /* 068CC8 */
#define screen_pieces_animations_54_ADDRESS 0x6CCEu    /* 068CCE */
#define screen_pieces_animations_54_sprites_ADDRESS 0x6CD6u    /* 068CD6 */
#define screen_pieces_animations_55_ADDRESS 0x6CDCu    /* 068CDC */
#define screen_pieces_animations_55_sprites_ADDRESS 0x6CE4u    /* 068CE4 */
#define screen_pieces_animations_56_ADDRESS 0x6CEAu    /* 068CEA */
#define screen_pieces_animations_56_sprites_ADDRESS 0x6CF2u    /* 068CF2 */
#define screen_pieces_animations_57_ADDRESS 0x6CF8u    /* 068CF8 */
#define screen_pieces_animations_57_sprites_ADDRESS 0x6D00u    /* 068D00 */
#define screen_pieces_animations_63_ADDRESS 0x6D06u    /* 068D06 */
#define screen_pieces_animations_63_sprites_ADDRESS 0x6D12u    /* 068D12 */
#define screen_pieces_animations_63_sprites_2_ADDRESS 0x6D18u    /* 068D18 */
#define screen_pieces_animations_65_ADDRESS 0x6D1Eu    /* 068D1E */
#define screen_pieces_animations_65_sprites_ADDRESS 0x6D26u    /* 068D26 */
#define screen_pieces_animations_64_ADDRESS 0x6D2Cu    /* 068D2C */
#define screen_pieces_animations_64_sprites_ADDRESS 0x6D34u    /* 068D34 */
#define screen_pieces_animations_69_ADDRESS 0x6D46u    /* 068D46 */
#define screen_pieces_animations_69_sprites_ADDRESS 0x6D4Eu    /* 068D4E */
#define screen_pieces_animations_70_ADDRESS 0x6D54u    /* 068D54 */
#define screen_pieces_animations_70_sprites_ADDRESS 0x6D78u    /* 068D78 */
#define screen_pieces_animations_70_sprites_2_ADDRESS 0x6D7Eu    /* 068D7E */
#define screen_pieces_animations_70_sprites_3_ADDRESS 0x6D84u    /* 068D84 */
#define screen_pieces_animations_70_sprites_4_ADDRESS 0x6D8Au    /* 068D8A */
#define screen_pieces_animations_70_sprites_5_ADDRESS 0x6D96u    /* 068D96 */
#define screen_pieces_animations_70_sprites_6_ADDRESS 0x6DA2u    /* 068DA2 */
#define screen_pieces_animations_70_sprites_7_ADDRESS 0x6DAEu    /* 068DAE */
#define screen_pieces_animations_70_sprites_8_ADDRESS 0x6DB4u    /* 068DB4 */
#define screen_pieces_animations_71_ADDRESS 0x6DBAu    /* 068DBA */
#define screen_pieces_animations_71_sprites_ADDRESS 0x6DC2u    /* 068DC2 */
#define screen_pieces_animations_72_ADDRESS 0x6DC8u    /* 068DC8 */
#define screen_pieces_animations_72_sprites_ADDRESS 0x6E0Cu    /* 068E0C */
#define screen_pieces_animations_72_sprites_2_ADDRESS 0x6E1Eu    /* 068E1E */
#define screen_pieces_animations_72_sprites_3_ADDRESS 0x6E36u    /* 068E36 */
#define screen_pieces_animations_72_sprites_4_ADDRESS 0x6E48u    /* 068E48 */
#define screen_pieces_animations_72_sprites_5_ADDRESS 0x6E60u    /* 068E60 */
#define screen_pieces_animations_72_sprites_6_ADDRESS 0x6E78u    /* 068E78 */
#define screen_pieces_animations_72_sprites_7_ADDRESS 0x6E8Au    /* 068E8A */
#define screen_pieces_animations_72_sprites_8_ADDRESS 0x6EA2u    /* 068EA2 */
#define screen_pieces_animations_72_sprites_9_ADDRESS 0x6EBAu    /* 068EBA */
#define screen_pieces_animations_72_sprites_10_ADDRESS 0x6ECCu    /* 068ECC */
#define screen_pieces_animations_73_ADDRESS 0x6EE4u    /* 068EE4 */
#define screen_pieces_animations_73_sprites_ADDRESS 0x6EECu    /* 068EEC */
#define screen_pieces_animations_74_ADDRESS 0x6EF8u    /* 068EF8 */
#define screen_pieces_animations_74_sprites_ADDRESS 0x6F00u    /* 068F00 */
#define screen_pieces_animations_66_ADDRESS 0x6F12u    /* 068F12 */
#define screen_pieces_animations_66_sprites_ADDRESS 0x6F1Au    /* 068F1A */
#define police_car_and_doors_animations_ADDRESS 0x6F2Cu    /* 068F2C */
#define police_car_and_doors_animations_0_ADDRESS 0x6F82u    /* 068F82 */
#define police_car_and_doors_animations_0_sprites_ADDRESS 0x6F8Au    /* 068F8A */
#define police_car_and_doors_animations_1_ADDRESS 0x6FA8u    /* 068FA8 */
#define police_car_and_doors_animations_1_sprites_ADDRESS 0x6FB0u    /* 068FB0 */
#define police_car_and_doors_animations_2_ADDRESS 0x6FC2u    /* 068FC2 */
#define police_car_and_doors_animations_2_sprites_ADDRESS 0x6FCAu    /* 068FCA */
#define police_car_and_doors_animations_3_ADDRESS 0x6FD0u    /* 068FD0 */
#define police_car_and_doors_animations_3_sprites_ADDRESS 0x6FD8u    /* 068FD8 */
#define police_car_and_doors_animations_4_ADDRESS 0x6FE4u    /* 068FE4 */
#define police_car_and_doors_animations_4_sprites_ADDRESS 0x6FECu    /* 068FEC */
#define police_car_and_doors_animations_5_ADDRESS 0x6FFEu    /* 068FFE */
#define police_car_and_doors_animations_5_sprites_ADDRESS 0x700Au    /* 06900A */
#define police_car_and_doors_animations_5_sprites_2_ADDRESS 0x701Cu    /* 06901C */
#define police_car_and_doors_animations_6_ADDRESS 0x702Eu    /* 06902E */
#define police_car_and_doors_animations_6_sprites_ADDRESS 0x7036u    /* 069036 */
#define police_car_and_doors_animations_7_ADDRESS 0x7042u    /* 069042 */
#define police_car_and_doors_animations_7_sprites_ADDRESS 0x704Eu    /* 06904E */
#define police_car_and_doors_animations_7_sprites_2_ADDRESS 0x7066u    /* 069066 */
#define police_car_and_doors_animations_8_ADDRESS 0x707Eu    /* 06907E */
#define police_car_and_doors_animations_8_sprites_ADDRESS 0x708Au    /* 06908A */
#define police_car_and_doors_animations_8_sprites_2_ADDRESS 0x70A2u    /* 0690A2 */
#define police_car_and_doors_animations_9_ADDRESS 0x70BAu    /* 0690BA */
#define police_car_and_doors_animations_9_sprites_ADDRESS 0x70C2u    /* 0690C2 */
#define police_car_and_doors_animations_10_ADDRESS 0x70CEu    /* 0690CE */
#define police_car_and_doors_animations_10_sprites_ADDRESS 0x70DAu    /* 0690DA */
#define police_car_and_doors_animations_10_sprites_2_ADDRESS 0x70ECu    /* 0690EC */
#define police_car_and_doors_animations_11_ADDRESS 0x70FEu    /* 0690FE */
#define police_car_and_doors_animations_11_sprites_ADDRESS 0x710Au    /* 06910A */
#define police_car_and_doors_animations_11_sprites_2_ADDRESS 0x711Cu    /* 06911C */
#define police_car_and_doors_animations_12_ADDRESS 0x712Eu    /* 06912E */
#define police_car_and_doors_animations_12_sprites_ADDRESS 0x713Au    /* 06913A */
#define police_car_and_doors_animations_12_sprites_2_ADDRESS 0x7152u    /* 069152 */
#define police_car_and_doors_animations_13_ADDRESS 0x716Au    /* 06916A */
#define police_car_and_doors_animations_13_sprites_ADDRESS 0x7176u    /* 069176 */
#define police_car_and_doors_animations_13_sprites_2_ADDRESS 0x718Eu    /* 06918E */
#define police_car_and_doors_animations_14_ADDRESS 0x71A6u    /* 0691A6 */
#define police_car_and_doors_animations_14_sprites_ADDRESS 0x71AEu    /* 0691AE */
#define police_car_and_doors_animations_15_ADDRESS 0x71BAu    /* 0691BA */
#define police_car_and_doors_animations_15_sprites_ADDRESS 0x71C6u    /* 0691C6 */
#define police_car_and_doors_animations_15_sprites_2_ADDRESS 0x71D2u    /* 0691D2 */
#define police_car_and_doors_animations_16_ADDRESS 0x71DEu    /* 0691DE */
#define police_car_and_doors_animations_16_sprites_ADDRESS 0x71EAu    /* 0691EA */
#define police_car_and_doors_animations_16_sprites_2_ADDRESS 0x71F6u    /* 0691F6 */
#define police_car_and_doors_animations_17_ADDRESS 0x7202u    /* 069202 */
#define police_car_and_doors_animations_17_sprites_ADDRESS 0x720Au    /* 06920A */
#define police_car_and_doors_animations_18_ADDRESS 0x7252u    /* 069252 */
#define police_car_and_doors_animations_18_sprites_ADDRESS 0x725Au    /* 06925A */
#define police_car_and_doors_animations_19_ADDRESS 0x72A8u    /* 0692A8 */
#define police_car_and_doors_animations_19_sprites_ADDRESS 0x72B0u    /* 0692B0 */
#define police_car_and_doors_animations_20_ADDRESS 0x72E0u    /* 0692E0 */
#define police_car_and_doors_animations_20_sprites_ADDRESS 0x72E8u    /* 0692E8 */
#define police_car_and_doors_animations_21_ADDRESS 0x72F4u    /* 0692F4 */
#define police_car_and_doors_animations_21_sprites_ADDRESS 0x7308u    /* 069308 */
#define police_car_and_doors_animations_21_sprites_2_ADDRESS 0x7338u    /* 069338 */
#define police_car_and_doors_animations_21_sprites_3_ADDRESS 0x7368u    /* 069368 */
#define police_car_and_doors_animations_21_sprites_4_ADDRESS 0x7398u    /* 069398 */
#define police_car_and_doors_animations_22_ADDRESS 0x73BCu    /* 0693BC */
#define police_car_and_doors_animations_22_sprites_ADDRESS 0x73C4u    /* 0693C4 */
#define police_car_and_doors_animations_23_ADDRESS 0x73DCu    /* 0693DC */
#define police_car_and_doors_animations_23_sprites_ADDRESS 0x73E4u    /* 0693E4 */
#define police_car_and_doors_animations_24_ADDRESS 0x742Cu    /* 06942C */
#define police_car_and_doors_animations_24_sprites_ADDRESS 0x7434u    /* 069434 */
#define police_car_and_doors_animations_25_ADDRESS 0x743Au    /* 06943A */
#define police_car_and_doors_animations_25_sprites_ADDRESS 0x7442u    /* 069442 */
#define police_car_and_doors_animations_26_ADDRESS 0x744Eu    /* 06944E */
#define police_car_and_doors_animations_26_sprites_ADDRESS 0x7456u    /* 069456 */
#define police_car_and_doors_animations_27_ADDRESS 0x7462u    /* 069462 */
#define police_car_and_doors_animations_27_sprites_ADDRESS 0x746Au    /* 06946A */
#define police_car_and_doors_animations_28_ADDRESS 0x7476u    /* 069476 */
#define police_car_and_doors_animations_28_sprites_ADDRESS 0x747Eu    /* 06947E */
#define police_car_and_doors_animations_29_ADDRESS 0x7490u    /* 069490 */
#define police_car_and_doors_animations_29_sprites_ADDRESS 0x7498u    /* 069498 */
#define police_car_and_doors_animations_32_ADDRESS 0x74B0u    /* 0694B0 */
#define police_car_and_doors_animations_32_sprites_ADDRESS 0x74B8u    /* 0694B8 */
#define police_car_and_doors_animations_33_ADDRESS 0x74D6u    /* 0694D6 */
#define police_car_and_doors_animations_33_sprites_ADDRESS 0x74E2u    /* 0694E2 */
#define police_car_and_doors_animations_33_sprites_2_ADDRESS 0x74E8u    /* 0694E8 */
#define police_car_and_doors_animations_30_ADDRESS 0x74EEu    /* 0694EE */
#define police_car_and_doors_animations_30_sprites_ADDRESS 0x74FEu    /* 0694FE */
#define police_car_and_doors_animations_30_sprites_2_ADDRESS 0x750Au    /* 06950A */
#define police_car_and_doors_animations_30_sprites_3_ADDRESS 0x751Cu    /* 06951C */
#define police_car_and_doors_animations_31_ADDRESS 0x7534u    /* 069534 */
#define police_car_and_doors_animations_31_sprites_ADDRESS 0x7540u    /* 069540 */
#define police_car_and_doors_animations_34_ADDRESS 0x7558u    /* 069558 */
#define police_car_and_doors_animations_34_sprites_ADDRESS 0x7560u    /* 069560 */
#define police_car_and_doors_animations_35_ADDRESS 0x75A2u    /* 0695A2 */
#define police_car_and_doors_animations_35_sprites_ADDRESS 0x75C6u    /* 0695C6 */
#define police_car_and_doors_animations_35_sprites_2_ADDRESS 0x75D2u    /* 0695D2 */
#define police_car_and_doors_animations_35_sprites_3_ADDRESS 0x75DEu    /* 0695DE */
#define police_car_and_doors_animations_35_sprites_4_ADDRESS 0x75EAu    /* 0695EA */
#define police_car_and_doors_animations_35_sprites_5_ADDRESS 0x75F6u    /* 0695F6 */
#define police_car_and_doors_animations_35_sprites_6_ADDRESS 0x7602u    /* 069602 */
#define police_car_and_doors_animations_35_sprites_7_ADDRESS 0x761Au    /* 06961A */
#define police_car_and_doors_animations_35_sprites_8_ADDRESS 0x7626u    /* 069626 */
#define police_car_and_doors_animations_36_ADDRESS 0x7632u    /* 069632 */
#define police_car_and_doors_animations_37_ADDRESS 0x7656u    /* 069656 */
#define police_car_and_doors_animations_38_ADDRESS 0x765Eu    /* 06965E */
#define police_car_and_doors_animations_38_sprites_ADDRESS 0x7672u    /* 069672 */
#define police_car_and_doors_animations_38_sprites_2_ADDRESS 0x7678u    /* 069678 */
#define police_car_and_doors_animations_39_ADDRESS 0x767Eu    /* 06967E */
#define police_car_and_doors_animations_39_sprites_ADDRESS 0x7692u    /* 069692 */
#define police_car_and_doors_animations_39_sprites_2_ADDRESS 0x76AAu    /* 0696AA */
#define police_car_and_doors_animations_39_sprites_3_ADDRESS 0x76C2u    /* 0696C2 */
#define police_car_and_doors_animations_39_sprites_4_ADDRESS 0x76DAu    /* 0696DA */
#define police_car_and_doors_animations_40_ADDRESS 0x7704u    /* 069704 */
#define police_car_and_doors_animations_40_sprites_ADDRESS 0x7710u    /* 069710 */
#define police_car_and_doors_animations_41_ADDRESS 0x773Au    /* 06973A */
#define police_car_and_doors_animations_41_sprites_ADDRESS 0x7746u    /* 069746 */
#define police_car_and_doors_animations_41_sprites_2_ADDRESS 0x7770u    /* 069770 */
#define police_car_and_doors_animations_42_ADDRESS 0x77A0u    /* 0697A0 */
#define moes_and_gorge_scenery_animations_ADDRESS 0x77B0u    /* 0697B0 */
#define moes_and_gorge_scenery_animations_0_ADDRESS 0x77F6u    /* 0697F6 */
#define moes_and_gorge_scenery_animations_0_sprites_ADDRESS 0x77FEu    /* 0697FE */
#define moes_and_gorge_scenery_animations_1_ADDRESS 0x7828u    /* 069828 */
#define moes_and_gorge_scenery_animations_1_sprites_ADDRESS 0x7830u    /* 069830 */
#define moes_and_gorge_scenery_animations_2_ADDRESS 0x785Au    /* 06985A */
#define moes_and_gorge_scenery_animations_2_sprites_ADDRESS 0x7862u    /* 069862 */
#define moes_and_gorge_scenery_animations_3_ADDRESS 0x7892u    /* 069892 */
#define moes_and_gorge_scenery_animations_3_sprites_ADDRESS 0x789Au    /* 06989A */
#define moes_and_gorge_scenery_animations_4_ADDRESS 0x78CAu    /* 0698CA */
#define moes_and_gorge_scenery_animations_4_sprites_ADDRESS 0x78F2u    /* 0698F2 */
#define moes_and_gorge_scenery_animations_4_sprites_2_ADDRESS 0x7928u    /* 069928 */
#define moes_and_gorge_scenery_animations_4_sprites_3_ADDRESS 0x7952u    /* 069952 */
#define moes_and_gorge_scenery_animations_4_sprites_4_ADDRESS 0x798Eu    /* 06998E */
#define moes_and_gorge_scenery_animations_4_sprites_5_ADDRESS 0x79CAu    /* 0699CA */
#define moes_and_gorge_scenery_animations_4_sprites_6_ADDRESS 0x79E8u    /* 0699E8 */
#define moes_and_gorge_scenery_animations_4_sprites_7_ADDRESS 0x79FAu    /* 0699FA */
#define moes_and_gorge_scenery_animations_4_sprites_8_ADDRESS 0x7A0Cu    /* 069A0C */
#define moes_and_gorge_scenery_animations_4_sprites_9_ADDRESS 0x7A1Eu    /* 069A1E */
#define moes_and_gorge_scenery_animations_5_ADDRESS 0x7A30u    /* 069A30 */
#define moes_and_gorge_scenery_animations_5_sprites_ADDRESS 0x7A44u    /* 069A44 */
#define moes_and_gorge_scenery_animations_5_sprites_2_ADDRESS 0x7A68u    /* 069A68 */
#define moes_and_gorge_scenery_animations_5_sprites_3_ADDRESS 0x7A8Cu    /* 069A8C */
#define moes_and_gorge_scenery_animations_5_sprites_4_ADDRESS 0x7AB0u    /* 069AB0 */
#define moes_and_gorge_scenery_animations_6_ADDRESS 0x7AD4u    /* 069AD4 */
#define moes_and_gorge_scenery_animations_6_sprites_ADDRESS 0x7ADCu    /* 069ADC */
#define moes_and_gorge_scenery_animations_7_ADDRESS 0x7AE2u    /* 069AE2 */
#define moes_and_gorge_scenery_animations_7_sprites_ADDRESS 0x7AEAu    /* 069AEA */
#define moes_and_gorge_scenery_animations_8_ADDRESS 0x7B32u    /* 069B32 */
#define moes_and_gorge_scenery_animations_8_sprites_ADDRESS 0x7B3Au    /* 069B3A */
#define moes_and_gorge_scenery_animations_9_ADDRESS 0x7B64u    /* 069B64 */
#define moes_and_gorge_scenery_animations_9_sprites_ADDRESS 0x7B6Cu    /* 069B6C */
#define moes_and_gorge_scenery_animations_10_ADDRESS 0x7B72u    /* 069B72 */
#define moes_and_gorge_scenery_animations_10_sprites_ADDRESS 0x7B7Au    /* 069B7A */
#define moes_and_gorge_scenery_animations_11_ADDRESS 0x7B92u    /* 069B92 */
#define moes_and_gorge_scenery_animations_11_sprites_ADDRESS 0x7B9Au    /* 069B9A */
#define moes_and_gorge_scenery_animations_12_ADDRESS 0x7BEEu    /* 069BEE */
#define moes_and_gorge_scenery_animations_12_sprites_ADDRESS 0x7BF6u    /* 069BF6 */
#define moes_and_gorge_scenery_animations_13_ADDRESS 0x7C32u    /* 069C32 */
#define moes_and_gorge_scenery_animations_13_sprites_ADDRESS 0x7C3Au    /* 069C3A */
#define moes_and_gorge_scenery_animations_14_ADDRESS 0x7C6Au    /* 069C6A */
#define moes_and_gorge_scenery_animations_14_sprites_ADDRESS 0x7C72u    /* 069C72 */
#define moes_and_gorge_scenery_animations_15_ADDRESS 0x7C96u    /* 069C96 */
#define moes_and_gorge_scenery_animations_15_sprites_ADDRESS 0x7C9Eu    /* 069C9E */
#define moes_and_gorge_scenery_animations_16_ADDRESS 0x7CBCu    /* 069CBC */
#define moes_and_gorge_scenery_animations_16_sprites_ADDRESS 0x7CC4u    /* 069CC4 */
#define moes_and_gorge_scenery_animations_17_ADDRESS 0x7CEEu    /* 069CEE */
#define moes_and_gorge_scenery_animations_17_sprites_ADDRESS 0x7CF6u    /* 069CF6 */
#define moes_and_gorge_scenery_animations_18_ADDRESS 0x7CFCu    /* 069CFC */
#define moes_and_gorge_scenery_animations_18_sprites_ADDRESS 0x7D08u    /* 069D08 */
#define moes_and_gorge_scenery_animations_18_sprites_2_ADDRESS 0x7D1Au    /* 069D1A */
#define moes_and_gorge_scenery_animations_19_ADDRESS 0x7D2Cu    /* 069D2C */
#define moes_and_gorge_scenery_animations_19_sprites_ADDRESS 0x7D34u    /* 069D34 */
#define moes_and_gorge_scenery_animations_20_ADDRESS 0x7D40u    /* 069D40 */
#define moes_and_gorge_scenery_animations_20_sprites_ADDRESS 0x7D48u    /* 069D48 */
#define moes_and_gorge_scenery_animations_21_ADDRESS 0x7D4Eu    /* 069D4E */
#define moes_and_gorge_scenery_animations_21_sprites_ADDRESS 0x7D6Eu    /* 069D6E */
#define moes_and_gorge_scenery_animations_21_sprites_2_ADDRESS 0x7D7Au    /* 069D7A */
#define moes_and_gorge_scenery_animations_21_sprites_3_ADDRESS 0x7D8Cu    /* 069D8C */
#define moes_and_gorge_scenery_animations_21_sprites_4_ADDRESS 0x7D98u    /* 069D98 */
#define moes_and_gorge_scenery_animations_21_sprites_5_ADDRESS 0x7DB6u    /* 069DB6 */
#define moes_and_gorge_scenery_animations_21_sprites_6_ADDRESS 0x7DC8u    /* 069DC8 */
#define moes_and_gorge_scenery_animations_21_sprites_7_ADDRESS 0x7DCEu    /* 069DCE */
#define moes_and_gorge_scenery_animations_26_ADDRESS 0x7DDAu    /* 069DDA */
#define moes_and_gorge_scenery_animations_26_sprites_ADDRESS 0x7DE2u    /* 069DE2 */
#define moes_and_gorge_scenery_animations_25_ADDRESS 0x7DE8u    /* 069DE8 */
#define moes_and_gorge_scenery_animations_25_sprites_ADDRESS 0x7DF0u    /* 069DF0 */
#define moes_and_gorge_scenery_animations_24_ADDRESS 0x7DF6u    /* 069DF6 */
#define moes_and_gorge_scenery_animations_24_sprites_ADDRESS 0x7DFEu    /* 069DFE */
#define moes_and_gorge_scenery_animations_27_ADDRESS 0x7E04u    /* 069E04 */
#define moes_and_gorge_scenery_animations_27_sprites_ADDRESS 0x7E0Cu    /* 069E0C */
#define moes_and_gorge_scenery_animations_28_ADDRESS 0x7E12u    /* 069E12 */
#define moes_and_gorge_scenery_animations_28_sprites_ADDRESS 0x7E2Au    /* 069E2A */
#define moes_and_gorge_scenery_animations_28_sprites_2_ADDRESS 0x7E30u    /* 069E30 */
#define moes_and_gorge_scenery_animations_28_sprites_3_ADDRESS 0x7E36u    /* 069E36 */
#define moes_and_gorge_scenery_animations_28_sprites_4_ADDRESS 0x7E3Cu    /* 069E3C */
#define moes_and_gorge_scenery_animations_28_sprites_5_ADDRESS 0x7E42u    /* 069E42 */
#define moes_and_gorge_scenery_animations_29_ADDRESS 0x7E48u    /* 069E48 */
#define moes_and_gorge_scenery_animations_29_sprites_ADDRESS 0x7E5Cu    /* 069E5C */
#define moes_and_gorge_scenery_animations_29_sprites_2_ADDRESS 0x7E62u    /* 069E62 */
#define moes_and_gorge_scenery_animations_29_sprites_3_ADDRESS 0x7E74u    /* 069E74 */
#define moes_and_gorge_scenery_animations_29_sprites_4_ADDRESS 0x7E8Cu    /* 069E8C */
#define moes_and_gorge_scenery_animations_30_ADDRESS 0x7EA4u    /* 069EA4 */
#define moes_and_gorge_scenery_animations_30_sprites_ADDRESS 0x7EB0u    /* 069EB0 */
#define moes_and_gorge_scenery_animations_30_sprites_2_ADDRESS 0x7EDAu    /* 069EDA */
#define moes_and_gorge_scenery_animations_31_ADDRESS 0x7F04u    /* 069F04 */
#define moes_and_gorge_scenery_animations_31_sprites_ADDRESS 0x7F0Cu    /* 069F0C */
#define moes_and_gorge_scenery_animations_32_ADDRESS 0x7F12u    /* 069F12 */
#define moes_and_gorge_scenery_animations_32_sprites_ADDRESS 0x7F1Au    /* 069F1A */
#define moes_and_gorge_scenery_animations_33_ADDRESS 0x7F38u    /* 069F38 */
#define moes_and_gorge_scenery_animations_33_sprites_ADDRESS 0x7F40u    /* 069F40 */
#define moes_and_gorge_scenery_animations_34_ADDRESS 0x7F58u    /* 069F58 */
#define moes_and_gorge_scenery_animations_34_sprites_ADDRESS 0x7F60u    /* 069F60 */
#define moes_and_gorge_scenery_animations_34_sprites_fill_ADDRESS 0x7F6Cu    /* 069F6C */
#define moes_and_gorge_scenery_animations_34_sprites_rest_ADDRESS 0x7F6Eu    /* 069F6E */
#define moes_and_gorge_scenery_animations_34_sprites_rest_2_ADDRESS 0x7F76u    /* 069F76 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_3_ADDRESS 0x7F7Cu    /* 069F7C */
#define moes_and_gorge_scenery_animations_34_sprites_rest_4_ADDRESS 0x7F84u    /* 069F84 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_5_ADDRESS 0x7F8Au    /* 069F8A */
#define moes_and_gorge_scenery_animations_34_sprites_rest_6_ADDRESS 0x7F92u    /* 069F92 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_7_ADDRESS 0x7F9Eu    /* 069F9E */
#define moes_and_gorge_scenery_animations_34_sprites_rest_8_ADDRESS 0x7FAAu    /* 069FAA */
#define moes_and_gorge_scenery_animations_34_sprites_rest_9_ADDRESS 0x7FB0u    /* 069FB0 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_10_ADDRESS 0x7FB6u    /* 069FB6 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_11_ADDRESS 0x7FBEu    /* 069FBE */
#define moes_and_gorge_scenery_animations_34_sprites_rest_12_ADDRESS 0x7FC4u    /* 069FC4 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_13_ADDRESS 0x7FCCu    /* 069FCC */
#define moes_and_gorge_scenery_animations_34_sprites_rest_14_ADDRESS 0x7FD2u    /* 069FD2 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_15_ADDRESS 0x7FDAu    /* 069FDA */
#define moes_and_gorge_scenery_animations_34_sprites_rest_16_ADDRESS 0x7FE0u    /* 069FE0 */
#define moes_and_gorge_scenery_animations_34_sprites_rest_17_ADDRESS 0x7FE8u    /* 069FE8 */
#define moes_and_gorge_scenery_animations_34_sprites_fill_2_ADDRESS 0x7FEEu    /* 069FEE */
#define moes_and_gorge_scenery_animations_34_sprites_rest_18_ADDRESS 0x6000u    /* 06A000 */
#define smithers_animations_ADDRESS 0x6004u    /* 06A004 */
#define smithers_animations_14_ADDRESS 0x604Eu    /* 06A04E */
#define smithers_animations_14_sprites_ADDRESS 0x6056u    /* 06A056 */
#define smithers_animations_0_ADDRESS 0x6068u    /* 06A068 */
#define smithers_animations_0_sprites_ADDRESS 0x608Cu    /* 06A08C */
#define smithers_animations_0_sprites_2_ADDRESS 0x60AAu    /* 06A0AA */
#define smithers_animations_0_sprites_3_ADDRESS 0x60C8u    /* 06A0C8 */
#define smithers_animations_0_sprites_4_ADDRESS 0x60E6u    /* 06A0E6 */
#define smithers_animations_0_sprites_5_ADDRESS 0x610Au    /* 06A10A */
#define smithers_animations_0_sprites_6_ADDRESS 0x611Cu    /* 06A11C */
#define smithers_animations_0_sprites_7_ADDRESS 0x6146u    /* 06A146 */
#define smithers_animations_0_sprites_8_ADDRESS 0x616Au    /* 06A16A */
#define smithers_animations_1_ADDRESS 0x6188u    /* 06A188 */
#define smithers_animations_1_sprites_ADDRESS 0x61ACu    /* 06A1AC */
#define smithers_animations_1_sprites_2_ADDRESS 0x61CAu    /* 06A1CA */
#define smithers_animations_1_sprites_3_ADDRESS 0x61E8u    /* 06A1E8 */
#define smithers_animations_1_sprites_4_ADDRESS 0x6206u    /* 06A206 */
#define smithers_animations_1_sprites_5_ADDRESS 0x622Au    /* 06A22A */
#define smithers_animations_1_sprites_6_ADDRESS 0x623Cu    /* 06A23C */
#define smithers_animations_1_sprites_7_ADDRESS 0x6266u    /* 06A266 */
#define smithers_animations_1_sprites_8_ADDRESS 0x628Au    /* 06A28A */
#define smithers_animations_2_ADDRESS 0x62A8u    /* 06A2A8 */
#define smithers_animations_2_sprites_ADDRESS 0x62CCu    /* 06A2CC */
#define smithers_animations_2_sprites_2_ADDRESS 0x62EAu    /* 06A2EA */
#define smithers_animations_2_sprites_3_ADDRESS 0x6308u    /* 06A308 */
#define smithers_animations_2_sprites_4_ADDRESS 0x6320u    /* 06A320 */
#define smithers_animations_2_sprites_5_ADDRESS 0x6338u    /* 06A338 */
#define smithers_animations_3_ADDRESS 0x6350u    /* 06A350 */
#define smithers_animations_3_sprites_ADDRESS 0x6358u    /* 06A358 */
#define smithers_animations_4_ADDRESS 0x6370u    /* 06A370 */
#define smithers_animations_4_sprites_ADDRESS 0x637Cu    /* 06A37C */
#define smithers_animations_4_sprites_2_ADDRESS 0x639Au    /* 06A39A */
#define smithers_animations_5_ADDRESS 0x63ACu    /* 06A3AC */
#define smithers_animations_6_ADDRESS 0x63B4u    /* 06A3B4 */
#define smithers_animations_6_sprites_ADDRESS 0x63C0u    /* 06A3C0 */
#define smithers_animations_6_sprites_2_ADDRESS 0x63FCu    /* 06A3FC */
#define smithers_animations_7_ADDRESS 0x6432u    /* 06A432 */
#define smithers_animations_7_sprites_ADDRESS 0x6442u    /* 06A442 */
#define smithers_animations_7_sprites_2_ADDRESS 0x6454u    /* 06A454 */
#define smithers_animations_7_sprites_3_ADDRESS 0x6466u    /* 06A466 */
#define smithers_animations_8_ADDRESS 0x647Eu    /* 06A47E */
#define smithers_animations_8_sprites_ADDRESS 0x64A6u    /* 06A4A6 */
#define smithers_animations_8_sprites_2_ADDRESS 0x64C4u    /* 06A4C4 */
#define smithers_animations_8_sprites_3_ADDRESS 0x64E8u    /* 06A4E8 */
#define smithers_animations_8_sprites_4_ADDRESS 0x650Cu    /* 06A50C */
#define smithers_animations_8_sprites_5_ADDRESS 0x6536u    /* 06A536 */
#define smithers_animations_8_sprites_6_ADDRESS 0x6560u    /* 06A560 */
#define smithers_animations_8_sprites_7_ADDRESS 0x658Au    /* 06A58A */
#define smithers_animations_9_ADDRESS 0x65A8u    /* 06A5A8 */
#define smithers_animations_9_sprites_ADDRESS 0x65CCu    /* 06A5CC */
#define smithers_animations_9_sprites_2_ADDRESS 0x65D2u    /* 06A5D2 */
#define smithers_animations_9_sprites_3_ADDRESS 0x65D8u    /* 06A5D8 */
#define smithers_animations_9_sprites_4_ADDRESS 0x65DEu    /* 06A5DE */
#define smithers_animations_9_sprites_5_ADDRESS 0x65E4u    /* 06A5E4 */
#define smithers_animations_9_sprites_6_ADDRESS 0x65EAu    /* 06A5EA */
#define smithers_animations_9_sprites_7_ADDRESS 0x65F0u    /* 06A5F0 */
#define smithers_animations_9_sprites_8_ADDRESS 0x65F6u    /* 06A5F6 */
#define smithers_animations_10_ADDRESS 0x65FCu    /* 06A5FC */
#define smithers_animations_10_sprites_ADDRESS 0x6620u    /* 06A620 */
#define smithers_animations_10_sprites_2_ADDRESS 0x6626u    /* 06A626 */
#define smithers_animations_10_sprites_3_ADDRESS 0x6632u    /* 06A632 */
#define smithers_animations_10_sprites_4_ADDRESS 0x6638u    /* 06A638 */
#define smithers_animations_10_sprites_5_ADDRESS 0x663Eu    /* 06A63E */
#define smithers_animations_10_sprites_6_ADDRESS 0x6650u    /* 06A650 */
#define smithers_animations_10_sprites_7_ADDRESS 0x6656u    /* 06A656 */
#define smithers_animations_10_sprites_8_ADDRESS 0x665Cu    /* 06A65C */
#define smithers_animations_11_ADDRESS 0x6662u    /* 06A662 */
#define smithers_animations_11_sprites_ADDRESS 0x6686u    /* 06A686 */
#define smithers_animations_11_sprites_2_ADDRESS 0x66A4u    /* 06A6A4 */
#define smithers_animations_11_sprites_3_ADDRESS 0x66C8u    /* 06A6C8 */
#define smithers_animations_11_sprites_4_ADDRESS 0x66ECu    /* 06A6EC */
#define smithers_animations_11_sprites_5_ADDRESS 0x6710u    /* 06A710 */
#define smithers_animations_11_sprites_6_ADDRESS 0x6734u    /* 06A734 */
#define smithers_animations_11_sprites_7_ADDRESS 0x6746u    /* 06A746 */
#define smithers_animations_11_sprites_8_ADDRESS 0x6770u    /* 06A770 */
#define smithers_animations_12_ADDRESS 0x6794u    /* 06A794 */
#define smithers_animations_12_sprites_ADDRESS 0x67A8u    /* 06A7A8 */
#define smithers_animations_12_sprites_2_ADDRESS 0x67BAu    /* 06A7BA */
#define smithers_animations_12_sprites_3_ADDRESS 0x67D8u    /* 06A7D8 */
#define smithers_animations_12_sprites_4_ADDRESS 0x6802u    /* 06A802 */
#define smithers_animations_13_ADDRESS 0x6820u    /* 06A820 */
#define smithers_animations_13_sprites_ADDRESS 0x6848u    /* 06A848 */
#define smithers_animations_13_sprites_2_ADDRESS 0x6860u    /* 06A860 */
#define smithers_animations_13_sprites_3_ADDRESS 0x687Eu    /* 06A87E */
#define smithers_animations_13_sprites_4_ADDRESS 0x68A2u    /* 06A8A2 */
#define smithers_animations_13_sprites_5_ADDRESS 0x68C6u    /* 06A8C6 */
#define smithers_animations_13_sprites_6_ADDRESS 0x68F0u    /* 06A8F0 */
#define smithers_animations_13_sprites_7_ADDRESS 0x691Au    /* 06A91A */
#define smithers_animations_16_ADDRESS 0x693Eu    /* 06A93E */
#define smithers_animations_16_sprites_ADDRESS 0x6962u    /* 06A962 */
#define smithers_animations_16_sprites_2_ADDRESS 0x6980u    /* 06A980 */
#define smithers_animations_16_sprites_3_ADDRESS 0x69A4u    /* 06A9A4 */
#define smithers_animations_16_sprites_4_ADDRESS 0x69C8u    /* 06A9C8 */
#define smithers_animations_16_sprites_5_ADDRESS 0x69ECu    /* 06A9EC */
#define smithers_animations_16_sprites_6_ADDRESS 0x6A04u    /* 06AA04 */
#define smithers_animations_16_sprites_7_ADDRESS 0x6A2Eu    /* 06AA2E */
#define smithers_animations_16_sprites_8_ADDRESS 0x6A58u    /* 06AA58 */
#define smithers_animations_17_ADDRESS 0x6A7Cu    /* 06AA7C */
#define smithers_animations_17_sprites_ADDRESS 0x6AA0u    /* 06AAA0 */
#define smithers_animations_17_sprites_2_ADDRESS 0x6AC4u    /* 06AAC4 */
#define smithers_animations_17_sprites_3_ADDRESS 0x6AEEu    /* 06AAEE */
#define smithers_animations_17_sprites_4_ADDRESS 0x6B0Cu    /* 06AB0C */
#define smithers_animations_17_sprites_5_ADDRESS 0x6B36u    /* 06AB36 */
#define smithers_animations_18_ADDRESS 0x6B5Au    /* 06AB5A */
#define smithers_animations_18_sprites_ADDRESS 0x6B7Eu    /* 06AB7E */
#define smithers_animations_18_sprites_2_ADDRESS 0x6B96u    /* 06AB96 */
#define smithers_animations_18_sprites_3_ADDRESS 0x6BB4u    /* 06ABB4 */
#define smithers_animations_18_sprites_4_ADDRESS 0x6BD8u    /* 06ABD8 */
#define smithers_animations_18_sprites_5_ADDRESS 0x6BF6u    /* 06ABF6 */
#define smithers_animations_18_sprites_6_ADDRESS 0x6C20u    /* 06AC20 */
#define smithers_animations_18_sprites_7_ADDRESS 0x6C50u    /* 06AC50 */
#define smithers_animations_18_sprites_8_ADDRESS 0x6C7Au    /* 06AC7A */
#define smithers_animations_19_ADDRESS 0x6C9Eu    /* 06AC9E */
#define smithers_animations_19_sprites_ADDRESS 0x6CC2u    /* 06ACC2 */
#define smithers_animations_19_sprites_2_ADDRESS 0x6CE6u    /* 06ACE6 */
#define smithers_animations_19_sprites_3_ADDRESS 0x6D0Au    /* 06AD0A */
#define smithers_animations_19_sprites_4_ADDRESS 0x6D2Eu    /* 06AD2E */
#define smithers_animations_19_sprites_5_ADDRESS 0x6D58u    /* 06AD58 */
#define smithers_animations_19_sprites_6_ADDRESS 0x6D8Eu    /* 06AD8E */
#define smithers_animations_19_sprites_7_ADDRESS 0x6DB8u    /* 06ADB8 */
#define smithers_animations_19_sprites_8_ADDRESS 0x6DE8u    /* 06ADE8 */
#define smithers_animations_20_ADDRESS 0x6E00u    /* 06AE00 */
#define smithers_animations_20_sprites_ADDRESS 0x6E80u    /* 06AE80 */
#define smithers_animations_20_sprites_2_ADDRESS 0x6E98u    /* 06AE98 */
#define smithers_animations_20_sprites_3_ADDRESS 0x6EB6u    /* 06AEB6 */
#define smithers_animations_20_sprites_4_ADDRESS 0x6ED4u    /* 06AED4 */
#define smithers_animations_20_sprites_5_ADDRESS 0x6EF2u    /* 06AEF2 */
#define smithers_animations_20_sprites_6_ADDRESS 0x6F10u    /* 06AF10 */
#define smithers_animations_20_sprites_7_ADDRESS 0x6F28u    /* 06AF28 */
#define smithers_animations_21_ADDRESS 0x6F46u    /* 06AF46 */
#define smithers_animations_21_sprites_ADDRESS 0x6F4Eu    /* 06AF4E */
#define smithers_animations_22_ADDRESS 0x6F5Au    /* 06AF5A */
#define smithers_animations_22_sprites_ADDRESS 0x6F72u    /* 06AF72 */
#define smithers_animations_22_sprites_2_ADDRESS 0x6F8Au    /* 06AF8A */
#define smithers_animations_22_sprites_3_ADDRESS 0x6FA2u    /* 06AFA2 */
#define smithers_animations_22_sprites_4_ADDRESS 0x6FB4u    /* 06AFB4 */
#define smithers_animations_22_sprites_5_ADDRESS 0x6FC0u    /* 06AFC0 */
#define smithers_animations_23_ADDRESS 0x6FCCu    /* 06AFCC */
#define smithers_animations_23_sprites_ADDRESS 0x6FF0u    /* 06AFF0 */
#define smithers_animations_23_sprites_2_ADDRESS 0x7020u    /* 06B020 */
#define smithers_animations_23_sprites_3_ADDRESS 0x7038u    /* 06B038 */
#define smithers_animations_23_sprites_4_ADDRESS 0x7056u    /* 06B056 */
#define smithers_animations_23_sprites_5_ADDRESS 0x707Au    /* 06B07A */
#define smithers_animations_24_ADDRESS 0x7098u    /* 06B098 */
#define smithers_animations_24_sprites_ADDRESS 0x70A8u    /* 06B0A8 */
#define smithers_animations_24_sprites_2_ADDRESS 0x70B4u    /* 06B0B4 */
#define smithers_animations_24_sprites_3_ADDRESS 0x70C6u    /* 06B0C6 */
#define smithers_animations_25_ADDRESS 0x70D8u    /* 06B0D8 */
#define smithers_animations_25_sprites_ADDRESS 0x70F4u    /* 06B0F4 */
#define smithers_animations_25_sprites_2_ADDRESS 0x7112u    /* 06B112 */
#define smithers_animations_25_sprites_3_ADDRESS 0x712Au    /* 06B12A */
#define smithers_animations_25_sprites_4_ADDRESS 0x713Cu    /* 06B13C */
#define smithers_animations_26_ADDRESS 0x7154u    /* 06B154 */
#define smithers_animations_26_sprites_ADDRESS 0x7164u    /* 06B164 */
#define smithers_animations_26_sprites_2_ADDRESS 0x717Cu    /* 06B17C */
#define smithers_animations_26_sprites_3_ADDRESS 0x71A0u    /* 06B1A0 */
#define smithers_animations_27_ADDRESS 0x71BEu    /* 06B1BE */
#define smithers_animations_27_sprites_ADDRESS 0x71CAu    /* 06B1CA */
#define smithers_animations_27_sprites_2_ADDRESS 0x71EEu    /* 06B1EE */
#define smithers_animations_28_ADDRESS 0x720Cu    /* 06B20C */
#define smithers_animations_35_ADDRESS 0x7278u    /* 06B278 */
#define smithers_animations_28_sprites_ADDRESS 0x72B4u    /* 06B2B4 */
#define smithers_animations_28_sprites_2_ADDRESS 0x72DEu    /* 06B2DE */
#define smithers_animations_28_sprites_3_ADDRESS 0x7308u    /* 06B308 */
#define smithers_animations_28_sprites_4_ADDRESS 0x733Eu    /* 06B33E */
#define smithers_animations_28_sprites_5_ADDRESS 0x7374u    /* 06B374 */
#define smithers_animations_28_sprites_6_ADDRESS 0x73B0u    /* 06B3B0 */
#define smithers_animations_28_sprites_7_ADDRESS 0x73E0u    /* 06B3E0 */
#define smithers_animations_28_sprites_8_ADDRESS 0x7422u    /* 06B422 */
#define smithers_animations_28_sprites_9_ADDRESS 0x746Au    /* 06B46A */
#define smithers_animations_28_sprites_10_ADDRESS 0x74A6u    /* 06B4A6 */
#define smithers_animations_28_sprites_11_ADDRESS 0x74DCu    /* 06B4DC */
#define smithers_animations_28_sprites_12_ADDRESS 0x7512u    /* 06B512 */
#define smithers_animations_28_sprites_13_ADDRESS 0x7536u    /* 06B536 */
#define smithers_animations_35_sprites_ADDRESS 0x7560u    /* 06B560 */
#define smithers_animations_35_sprites_2_ADDRESS 0x758Au    /* 06B58A */
#define smithers_animations_35_sprites_3_ADDRESS 0x75C0u    /* 06B5C0 */
#define smithers_animations_35_sprites_4_ADDRESS 0x7608u    /* 06B608 */
#define smithers_animations_35_sprites_5_ADDRESS 0x7668u    /* 06B668 */
#define smithers_animations_35_sprites_6_ADDRESS 0x76C8u    /* 06B6C8 */
#define smithers_animations_35_sprites_7_ADDRESS 0x7728u    /* 06B728 */
#define smithers_animations_35_sprites_8_ADDRESS 0x7788u    /* 06B788 */
#define smithers_animations_35_sprites_9_ADDRESS 0x77D0u    /* 06B7D0 */
#define smithers_animations_35_sprites_10_ADDRESS 0x780Cu    /* 06B80C */
#define smithers_animations_35_sprites_11_ADDRESS 0x783Cu    /* 06B83C */
#define smithers_animations_35_sprites_12_ADDRESS 0x786Cu    /* 06B86C */
#define smithers_animations_29_sprites_2_ADDRESS 0x7890u    /* 06B890 */
#define smithers_animations_29_ADDRESS 0x78AEu    /* 06B8AE */
#define smithers_animations_29_sprites_ADDRESS 0x78CAu    /* 06B8CA */
#define smithers_animations_30_ADDRESS 0x78E8u    /* 06B8E8 */
#define smithers_animations_30_sprites_ADDRESS 0x7908u    /* 06B908 */
#define smithers_animations_30_sprites_2_ADDRESS 0x7926u    /* 06B926 */
#define smithers_animations_30_sprites_3_ADDRESS 0x7938u    /* 06B938 */
#define smithers_animations_30_sprites_4_ADDRESS 0x7950u    /* 06B950 */
#define smithers_animations_32_ADDRESS 0x7968u    /* 06B968 */
#define smithers_animations_32_sprites_ADDRESS 0x7978u    /* 06B978 */
#define smithers_animations_32_sprites_2_ADDRESS 0x7996u    /* 06B996 */
#define smithers_animations_32_sprites_3_ADDRESS 0x79AEu    /* 06B9AE */
#define smithers_animations_33_ADDRESS 0x79C0u    /* 06B9C0 */
#define smithers_animations_31_ADDRESS 0x79C8u    /* 06B9C8 */
#define smithers_animations_31_sprites_ADDRESS 0x79ECu    /* 06B9EC */
#define smithers_animations_31_sprites_2_ADDRESS 0x79F2u    /* 06B9F2 */
#define smithers_animations_31_sprites_3_ADDRESS 0x79F8u    /* 06B9F8 */
#define smithers_animations_31_sprites_4_ADDRESS 0x79FEu    /* 06B9FE */
#define smithers_animations_31_sprites_5_ADDRESS 0x7A04u    /* 06BA04 */
#define smithers_animations_31_sprites_6_ADDRESS 0x7A0Au    /* 06BA0A */
#define smithers_animations_31_sprites_7_ADDRESS 0x7A10u    /* 06BA10 */
#define smithers_animations_31_sprites_8_ADDRESS 0x7A16u    /* 06BA16 */
#define smithers_animations_34_ADDRESS 0x7A1Cu    /* 06BA1C */
#define smithers_animations_34_sprites_ADDRESS 0x7A44u    /* 06BA44 */
#define smithers_animations_34_sprites_2_ADDRESS 0x7A4Au    /* 06BA4A */
#define smithers_animations_34_sprites_3_ADDRESS 0x7A50u    /* 06BA50 */
#define smithers_animations_34_sprites_4_ADDRESS 0x7A56u    /* 06BA56 */
#define smithers_animations_34_sprites_5_ADDRESS 0x7A5Cu    /* 06BA5C */
#define smithers_animations_34_sprites_6_ADDRESS 0x7A62u    /* 06BA62 */
#define smithers_animations_34_sprites_7_ADDRESS 0x7A68u    /* 06BA68 */
#define smithers_animations_34_sprites_8_ADDRESS 0x7A6Eu    /* 06BA6E */
#define smithers_animations_34_sprites_9_ADDRESS 0x7A74u    /* 06BA74 */
#define smithers_animations_36_ADDRESS 0x7A7Au    /* 06BA7A */
#define smithers_animations_36_sprites_ADDRESS 0x7AAEu    /* 06BAAE */
#define smithers_animations_36_sprites_2_ADDRESS 0x7AB4u    /* 06BAB4 */
#define smithers_animations_36_sprites_3_ADDRESS 0x7AC0u    /* 06BAC0 */
#define smithers_animations_36_sprites_4_ADDRESS 0x7AD2u    /* 06BAD2 */
#define smithers_animations_36_sprites_5_ADDRESS 0x7AF6u    /* 06BAF6 */
#define smithers_animations_36_sprites_6_ADDRESS 0x7B26u    /* 06BB26 */
#define smithers_animations_36_sprites_7_ADDRESS 0x7B5Cu    /* 06BB5C */
#define smithers_animations_36_sprites_8_ADDRESS 0x7B98u    /* 06BB98 */
#define krusty_toys_helicopter_animations_ADDRESS 0x7B9Eu    /* 06BB9E */
#define krusty_toys_helicopter_animations_8_ADDRESS 0x7BC2u    /* 06BBC2 */
#define krusty_toys_helicopter_animations_8_sprites_ADDRESS 0x7BCEu    /* 06BBCE */
#define krusty_toys_helicopter_animations_8_sprites_2_ADDRESS 0x7BDAu    /* 06BBDA */
#define krusty_toys_helicopter_animations_0_ADDRESS 0x7BE6u    /* 06BBE6 */
#define krusty_toys_helicopter_animations_0_sprites_ADDRESS 0x7BF2u    /* 06BBF2 */
#define krusty_toys_helicopter_animations_0_sprites_2_ADDRESS 0x7C46u    /* 06BC46 */
#define krusty_toys_helicopter_animations_1_ADDRESS 0x7CA0u    /* 06BCA0 */
#define krusty_toys_helicopter_animations_1_sprites_ADDRESS 0x7CB8u    /* 06BCB8 */
#define krusty_toys_helicopter_animations_1_sprites_2_ADDRESS 0x7D0Cu    /* 06BD0C */
#define krusty_toys_helicopter_animations_1_sprites_3_ADDRESS 0x7D66u    /* 06BD66 */
#define krusty_toys_helicopter_animations_1_sprites_4_ADDRESS 0x7DBAu    /* 06BDBA */
#define krusty_toys_helicopter_animations_1_sprites_5_ADDRESS 0x7E14u    /* 06BE14 */
#define krusty_toys_helicopter_animations_2_ADDRESS 0x7E6Eu    /* 06BE6E */
#define krusty_toys_helicopter_animations_3_ADDRESS 0x7E7Au    /* 06BE7A */
#define krusty_toys_helicopter_animations_3_sprites_ADDRESS 0x7E86u    /* 06BE86 */
#define krusty_toys_helicopter_animations_3_sprites_2_ADDRESS 0x7E92u    /* 06BE92 */
#define krusty_toys_helicopter_animations_4_ADDRESS 0x7E9Eu    /* 06BE9E */
#define krusty_toys_helicopter_animations_4_sprites_ADDRESS 0x7EAAu    /* 06BEAA */
#define krusty_toys_helicopter_animations_4_sprites_2_ADDRESS 0x7EBCu    /* 06BEBC */
#define krusty_toys_helicopter_animations_5_ADDRESS 0x7ECEu    /* 06BECE */
#define krusty_toys_helicopter_animations_5_sprites_ADDRESS 0x7EDAu    /* 06BEDA */
#define krusty_toys_helicopter_animations_5_sprites_2_ADDRESS 0x7EECu    /* 06BEEC */
#define krusty_toys_helicopter_animations_6_ADDRESS 0x7EFEu    /* 06BEFE */
#define krusty_toys_helicopter_animations_6_sprites_ADDRESS 0x7F06u    /* 06BF06 */
#define krusty_toys_helicopter_animations_7_ADDRESS 0x7F24u    /* 06BF24 */
#define krusty_toys_helicopter_animations_7_sprites_ADDRESS 0x7F30u    /* 06BF30 */
#define krusty_toys_helicopter_animations_7_sprites_2_ADDRESS 0x7F48u    /* 06BF48 */
#define krusty_toys_helicopter_animations_10_ADDRESS 0x7F60u    /* 06BF60 */
#define krusty_toys_helicopter_animations_10_sprites_ADDRESS 0x7F68u    /* 06BF68 */
#define krusty_toys_helicopter_animations_11_ADDRESS 0x7F6Eu    /* 06BF6E */
#define krusty_toys_helicopter_animations_11_sprites_ADDRESS 0x7F76u    /* 06BF76 */
#define krusty_toys_helicopter_animations_12_ADDRESS 0x7F7Cu    /* 06BF7C */
#define krusty_toys_helicopter_animations_12_sprites_ADDRESS 0x7F84u    /* 06BF84 */
#define krusty_toys_helicopter_animations_9_ADDRESS 0x7F8Au    /* 06BF8A */
#define krusty_toys_helicopter_animations_9_sprites_ADDRESS 0x7F92u    /* 06BF92 */
#define krusty_toys_helicopter_animations_13_ADDRESS 0x7F9Eu    /* 06BF9E */
#define krusty_toys_helicopter_animations_13_sprites_ADDRESS 0x7FAAu    /* 06BFAA */
#define krusty_toys_helicopter_animations_13_sprites_2_ADDRESS 0x7FB0u    /* 06BFB0 */
#define krusty_toys_helicopter_animations_15_ADDRESS 0x7FB6u    /* 06BFB6 */
#define krusty_toys_helicopter_animations_15_sprites_ADDRESS 0x7FBEu    /* 06BFBE */
#define krusty_toys_helicopter_animations_14_ADDRESS 0x7FC4u    /* 06BFC4 */
#define krusty_toys_helicopter_animations_14_sprites_ADDRESS 0x7FCCu    /* 06BFCC */
#define krusty_toys_helicopter_animations_17_ADDRESS 0x7FD2u    /* 06BFD2 */
#define krusty_toys_helicopter_animations_17_sprites_ADDRESS 0x7FDAu    /* 06BFDA */
#define krusty_toys_helicopter_animations_16_ADDRESS 0x7FE0u    /* 06BFE0 */
#define krusty_toys_helicopter_animations_16_sprites_ADDRESS 0x7FE8u    /* 06BFE8 */
#define krusty_toys_helicopter_animations_16_sprites_fill_ADDRESS 0x7FEEu    /* 06BFEE */
#define krusty_toys_helicopter_animations_16_sprites_rest_ADDRESS 0x6000u    /* 06C000 */
#define goon_with_hat_animations_ADDRESS 0x600Cu    /* 06C00C */
#define goon_with_hat_animations_0_ADDRESS 0x6082u    /* 06C082 */
#define goon_with_hat_animations_0_sprites_ADDRESS 0x608Au    /* 06C08A */
#define goon_with_hat_animations_1_ADDRESS 0x6096u    /* 06C096 */
#define goon_with_hat_animations_1_sprites_ADDRESS 0x60BAu    /* 06C0BA */
#define goon_with_hat_animations_1_sprites_2_ADDRESS 0x60D2u    /* 06C0D2 */
#define goon_with_hat_animations_1_sprites_3_ADDRESS 0x60EAu    /* 06C0EA */
#define goon_with_hat_animations_1_sprites_4_ADDRESS 0x6102u    /* 06C102 */
#define goon_with_hat_animations_1_sprites_5_ADDRESS 0x611Au    /* 06C11A */
#define goon_with_hat_animations_1_sprites_6_ADDRESS 0x6132u    /* 06C132 */
#define goon_with_hat_animations_1_sprites_7_ADDRESS 0x614Au    /* 06C14A */
#define goon_with_hat_animations_1_sprites_8_ADDRESS 0x6162u    /* 06C162 */
#define goon_with_hat_animations_2_ADDRESS 0x617Au    /* 06C17A */
#define goon_with_hat_animations_2_sprites_ADDRESS 0x619Eu    /* 06C19E */
#define goon_with_hat_animations_2_sprites_2_ADDRESS 0x61BCu    /* 06C1BC */
#define goon_with_hat_animations_2_sprites_3_ADDRESS 0x61D4u    /* 06C1D4 */
#define goon_with_hat_animations_2_sprites_4_ADDRESS 0x61ECu    /* 06C1EC */
#define goon_with_hat_animations_2_sprites_5_ADDRESS 0x6204u    /* 06C204 */
#define goon_with_hat_animations_2_sprites_6_ADDRESS 0x621Cu    /* 06C21C */
#define goon_with_hat_animations_2_sprites_7_ADDRESS 0x6234u    /* 06C234 */
#define goon_with_hat_animations_2_sprites_8_ADDRESS 0x624Cu    /* 06C24C */
#define goon_with_hat_animations_3_ADDRESS 0x6264u    /* 06C264 */
#define goon_with_hat_animations_3_sprites_ADDRESS 0x6288u    /* 06C288 */
#define goon_with_hat_animations_3_sprites_2_ADDRESS 0x62A0u    /* 06C2A0 */
#define goon_with_hat_animations_3_sprites_3_ADDRESS 0x62B8u    /* 06C2B8 */
#define goon_with_hat_animations_3_sprites_4_ADDRESS 0x62D0u    /* 06C2D0 */
#define goon_with_hat_animations_3_sprites_5_ADDRESS 0x62E8u    /* 06C2E8 */
#define goon_with_hat_animations_3_sprites_6_ADDRESS 0x6300u    /* 06C300 */
#define goon_with_hat_animations_3_sprites_7_ADDRESS 0x6318u    /* 06C318 */
#define goon_with_hat_animations_3_sprites_8_ADDRESS 0x6330u    /* 06C330 */
#define goon_with_hat_animations_4_ADDRESS 0x6348u    /* 06C348 */
#define goon_with_hat_animations_4_sprites_ADDRESS 0x6354u    /* 06C354 */
#define goon_with_hat_animations_4_sprites_2_ADDRESS 0x6360u    /* 06C360 */
#define goon_with_hat_animations_5_ADDRESS 0x636Cu    /* 06C36C */
#define goon_with_hat_animations_5_sprites_ADDRESS 0x6378u    /* 06C378 */
#define goon_with_hat_animations_5_sprites_2_ADDRESS 0x6384u    /* 06C384 */
#define goon_with_hat_animations_6_ADDRESS 0x6390u    /* 06C390 */
#define goon_with_hat_animations_6_sprites_ADDRESS 0x639Cu    /* 06C39C */
#define goon_with_hat_animations_6_sprites_2_ADDRESS 0x63A8u    /* 06C3A8 */
#define goon_with_hat_animations_7_ADDRESS 0x63B4u    /* 06C3B4 */
#define goon_with_hat_animations_7_sprites_ADDRESS 0x63C0u    /* 06C3C0 */
#define goon_with_hat_animations_7_sprites_2_ADDRESS 0x63CCu    /* 06C3CC */
#define goon_with_hat_animations_8_ADDRESS 0x63DEu    /* 06C3DE */
#define goon_with_hat_animations_8_sprites_ADDRESS 0x63F6u    /* 06C3F6 */
#define goon_with_hat_animations_8_sprites_2_ADDRESS 0x6408u    /* 06C408 */
#define goon_with_hat_animations_8_sprites_3_ADDRESS 0x641Au    /* 06C41A */
#define goon_with_hat_animations_8_sprites_4_ADDRESS 0x642Cu    /* 06C42C */
#define goon_with_hat_animations_8_sprites_5_ADDRESS 0x6444u    /* 06C444 */
#define goon_with_hat_animations_9_ADDRESS 0x6450u    /* 06C450 */
#define goon_with_hat_animations_9_sprites_ADDRESS 0x646Cu    /* 06C46C */
#define goon_with_hat_animations_9_sprites_2_ADDRESS 0x647Eu    /* 06C47E */
#define goon_with_hat_animations_9_sprites_3_ADDRESS 0x648Au    /* 06C48A */
#define goon_with_hat_animations_9_sprites_4_ADDRESS 0x649Cu    /* 06C49C */
#define goon_with_hat_animations_10_ADDRESS 0x64AEu    /* 06C4AE */
#define goon_with_hat_animations_10_sprites_ADDRESS 0x64C2u    /* 06C4C2 */
#define goon_with_hat_animations_10_sprites_2_ADDRESS 0x64CEu    /* 06C4CE */
#define goon_with_hat_animations_10_sprites_3_ADDRESS 0x64E0u    /* 06C4E0 */
#define goon_with_hat_animations_10_sprites_4_ADDRESS 0x64F2u    /* 06C4F2 */
#define goon_with_hat_animations_11_ADDRESS 0x64FEu    /* 06C4FE */
#define goon_with_hat_animations_11_sprites_ADDRESS 0x6516u    /* 06C516 */
#define goon_with_hat_animations_11_sprites_2_ADDRESS 0x652Eu    /* 06C52E */
#define goon_with_hat_animations_11_sprites_3_ADDRESS 0x6546u    /* 06C546 */
#define goon_with_hat_animations_11_sprites_4_ADDRESS 0x6558u    /* 06C558 */
#define goon_with_hat_animations_11_sprites_5_ADDRESS 0x6570u    /* 06C570 */
#define goon_with_hat_animations_12_ADDRESS 0x6588u    /* 06C588 */
#define goon_with_hat_animations_12_sprites_ADDRESS 0x65A8u    /* 06C5A8 */
#define goon_with_hat_animations_12_sprites_2_ADDRESS 0x65BAu    /* 06C5BA */
#define goon_with_hat_animations_12_sprites_3_ADDRESS 0x65D2u    /* 06C5D2 */
#define goon_with_hat_animations_12_sprites_4_ADDRESS 0x65EAu    /* 06C5EA */
#define goon_with_hat_animations_12_sprites_5_ADDRESS 0x6602u    /* 06C602 */
#define goon_with_hat_animations_12_sprites_6_ADDRESS 0x6614u    /* 06C614 */
#define goon_with_hat_animations_13_ADDRESS 0x6626u    /* 06C626 */
#define goon_with_hat_animations_13_sprites_ADDRESS 0x6632u    /* 06C632 */
#define goon_with_hat_animations_13_sprites_2_ADDRESS 0x6644u    /* 06C644 */
#define goon_with_hat_animations_14_ADDRESS 0x6656u    /* 06C656 */
#define goon_with_hat_animations_14_sprites_ADDRESS 0x667Au    /* 06C67A */
#define goon_with_hat_animations_14_sprites_2_ADDRESS 0x6692u    /* 06C692 */
#define goon_with_hat_animations_14_sprites_3_ADDRESS 0x66A4u    /* 06C6A4 */
#define goon_with_hat_animations_14_sprites_4_ADDRESS 0x66BCu    /* 06C6BC */
#define goon_with_hat_animations_14_sprites_5_ADDRESS 0x66C8u    /* 06C6C8 */
#define goon_with_hat_animations_15_ADDRESS 0x66D4u    /* 06C6D4 */
#define goon_with_hat_animations_15_sprites_ADDRESS 0x66F0u    /* 06C6F0 */
#define goon_with_hat_animations_15_sprites_2_ADDRESS 0x6702u    /* 06C702 */
#define goon_with_hat_animations_15_sprites_3_ADDRESS 0x6714u    /* 06C714 */
#define goon_with_hat_animations_15_sprites_4_ADDRESS 0x6732u    /* 06C732 */
#define goon_with_hat_animations_16_ADDRESS 0x6750u    /* 06C750 */
#define goon_with_hat_animations_16_sprites_ADDRESS 0x6774u    /* 06C774 */
#define goon_with_hat_animations_16_sprites_2_ADDRESS 0x678Cu    /* 06C78C */
#define goon_with_hat_animations_16_sprites_3_ADDRESS 0x679Eu    /* 06C79E */
#define goon_with_hat_animations_16_sprites_4_ADDRESS 0x67B0u    /* 06C7B0 */
#define goon_with_hat_animations_16_sprites_5_ADDRESS 0x67C2u    /* 06C7C2 */
#define goon_with_hat_animations_16_sprites_6_ADDRESS 0x67D4u    /* 06C7D4 */
#define goon_with_hat_animations_16_sprites_7_ADDRESS 0x67E6u    /* 06C7E6 */
#define goon_with_hat_animations_16_sprites_8_ADDRESS 0x67F8u    /* 06C7F8 */
#define goon_with_hat_animations_17_ADDRESS 0x6810u    /* 06C810 */
#define goon_with_hat_animations_17_sprites_ADDRESS 0x6834u    /* 06C834 */
#define goon_with_hat_animations_17_sprites_2_ADDRESS 0x6840u    /* 06C840 */
#define goon_with_hat_animations_17_sprites_3_ADDRESS 0x684Cu    /* 06C84C */
#define goon_with_hat_animations_17_sprites_4_ADDRESS 0x6858u    /* 06C858 */
#define goon_with_hat_animations_17_sprites_5_ADDRESS 0x6864u    /* 06C864 */
#define goon_with_hat_animations_17_sprites_6_ADDRESS 0x6870u    /* 06C870 */
#define goon_with_hat_animations_17_sprites_7_ADDRESS 0x687Cu    /* 06C87C */
#define goon_with_hat_animations_17_sprites_8_ADDRESS 0x6888u    /* 06C888 */
#define goon_with_hat_animations_18_ADDRESS 0x6894u    /* 06C894 */
#define goon_with_hat_animations_18_sprites_ADDRESS 0x68ACu    /* 06C8AC */
#define goon_with_hat_animations_18_sprites_2_ADDRESS 0x68BEu    /* 06C8BE */
#define goon_with_hat_animations_18_sprites_3_ADDRESS 0x68D0u    /* 06C8D0 */
#define goon_with_hat_animations_18_sprites_4_ADDRESS 0x68DCu    /* 06C8DC */
#define goon_with_hat_animations_19_ADDRESS 0x68E8u    /* 06C8E8 */
#define goon_with_hat_animations_19_sprites_ADDRESS 0x68FCu    /* 06C8FC */
#define goon_with_hat_animations_19_sprites_2_ADDRESS 0x6908u    /* 06C908 */
#define goon_with_hat_animations_19_sprites_3_ADDRESS 0x6920u    /* 06C920 */
#define goon_with_hat_animations_56_ADDRESS 0x6938u    /* 06C938 */
#define goon_with_hat_animations_56_sprites_ADDRESS 0x6950u    /* 06C950 */
#define goon_with_hat_animations_56_sprites_2_ADDRESS 0x695Cu    /* 06C95C */
#define goon_with_hat_animations_56_sprites_3_ADDRESS 0x696Eu    /* 06C96E */
#define goon_with_hat_animations_33_ADDRESS 0x6980u    /* 06C980 */
#define goon_with_hat_animations_33_sprites_ADDRESS 0x698Cu    /* 06C98C */
#define goon_with_hat_animations_33_sprites_2_ADDRESS 0x6998u    /* 06C998 */
#define goon_with_hat_animations_34_ADDRESS 0x69A4u    /* 06C9A4 */
#define goon_with_hat_animations_34_sprites_ADDRESS 0x69B8u    /* 06C9B8 */
#define goon_with_hat_animations_34_sprites_2_ADDRESS 0x69BEu    /* 06C9BE */
#define goon_with_hat_animations_34_sprites_3_ADDRESS 0x69CAu    /* 06C9CA */
#define goon_with_hat_animations_34_sprites_4_ADDRESS 0x69D6u    /* 06C9D6 */
#define goon_with_hat_animations_35_ADDRESS 0x69DCu    /* 06C9DC */
#define goon_with_hat_animations_35_sprites_ADDRESS 0x69F4u    /* 06C9F4 */
#define goon_with_hat_animations_35_sprites_2_ADDRESS 0x6A00u    /* 06CA00 */
#define goon_with_hat_animations_35_sprites_3_ADDRESS 0x6A18u    /* 06CA18 */
#define goon_with_hat_animations_35_sprites_4_ADDRESS 0x6A30u    /* 06CA30 */
#define goon_with_hat_animations_36_ADDRESS 0x6A42u    /* 06CA42 */
#define goon_with_hat_animations_36_sprites_ADDRESS 0x6A66u    /* 06CA66 */
#define goon_with_hat_animations_36_sprites_2_ADDRESS 0x6A72u    /* 06CA72 */
#define goon_with_hat_animations_36_sprites_3_ADDRESS 0x6A84u    /* 06CA84 */
#define goon_with_hat_animations_37_ADDRESS 0x6A96u    /* 06CA96 */
#define goon_with_hat_animations_37_sprites_ADDRESS 0x6ABAu    /* 06CABA */
#define goon_with_hat_animations_37_sprites_2_ADDRESS 0x6AC6u    /* 06CAC6 */
#define goon_with_hat_animations_37_sprites_3_ADDRESS 0x6AD8u    /* 06CAD8 */
#define goon_with_hat_animations_37_sprites_4_ADDRESS 0x6AF0u    /* 06CAF0 */
#define goon_with_hat_animations_37_sprites_5_ADDRESS 0x6B08u    /* 06CB08 */
#define goon_with_hat_animations_37_sprites_6_ADDRESS 0x6B26u    /* 06CB26 */
#define goon_with_hat_animations_37_sprites_7_ADDRESS 0x6B3Eu    /* 06CB3E */
#define goon_with_hat_animations_37_sprites_8_ADDRESS 0x6B56u    /* 06CB56 */
#define goon_with_hat_animations_38_ADDRESS 0x6B68u    /* 06CB68 */
#define goon_with_hat_animations_38_sprites_ADDRESS 0x6B74u    /* 06CB74 */
#define goon_with_hat_animations_39_ADDRESS 0x6B86u    /* 06CB86 */
#define goon_with_hat_animations_39_sprites_ADDRESS 0x6B9Au    /* 06CB9A */
#define goon_with_hat_animations_39_sprites_2_ADDRESS 0x6BA6u    /* 06CBA6 */
#define goon_with_hat_animations_39_sprites_3_ADDRESS 0x6BB8u    /* 06CBB8 */
#define goon_with_hat_animations_39_sprites_4_ADDRESS 0x6BCAu    /* 06CBCA */
#define goon_with_hat_animations_40_ADDRESS 0x6BE8u    /* 06CBE8 */
#define goon_with_hat_animations_40_sprites_ADDRESS 0x6BF0u    /* 06CBF0 */
#define goon_with_hat_animations_41_ADDRESS 0x6BFCu    /* 06CBFC */
#define goon_with_hat_animations_41_sprites_ADDRESS 0x6C18u    /* 06CC18 */
#define goon_with_hat_animations_41_sprites_2_ADDRESS 0x6C24u    /* 06CC24 */
#define goon_with_hat_animations_41_sprites_3_ADDRESS 0x6C3Cu    /* 06CC3C */
#define goon_with_hat_animations_41_sprites_4_ADDRESS 0x6C54u    /* 06CC54 */
#define goon_with_hat_animations_41_sprites_5_ADDRESS 0x6C66u    /* 06CC66 */
#define goon_with_hat_animations_42_ADDRESS 0x6C7Eu    /* 06CC7E */
#define goon_with_hat_animations_42_sprites_ADDRESS 0x6C92u    /* 06CC92 */
#define goon_with_hat_animations_42_sprites_2_ADDRESS 0x6C98u    /* 06CC98 */
#define goon_with_hat_animations_42_sprites_3_ADDRESS 0x6C9Eu    /* 06CC9E */
#define goon_with_hat_animations_43_ADDRESS 0x6CA4u    /* 06CCA4 */
#define goon_with_hat_animations_43_sprites_ADDRESS 0x6CD4u    /* 06CCD4 */
#define goon_with_hat_animations_43_sprites_2_ADDRESS 0x6CDAu    /* 06CCDA */
#define goon_with_hat_animations_43_sprites_3_ADDRESS 0x6CECu    /* 06CCEC */
#define goon_with_hat_animations_43_sprites_4_ADDRESS 0x6CF8u    /* 06CCF8 */
#define goon_with_hat_animations_43_sprites_5_ADDRESS 0x6D04u    /* 06CD04 */
#define goon_with_hat_animations_43_sprites_6_ADDRESS 0x6D10u    /* 06CD10 */
#define goon_with_hat_animations_43_sprites_7_ADDRESS 0x6D1Cu    /* 06CD1C */
#define goon_with_hat_animations_43_sprites_8_ADDRESS 0x6D28u    /* 06CD28 */
#define goon_with_hat_animations_43_sprites_9_ADDRESS 0x6D34u    /* 06CD34 */
#define goon_with_hat_animations_43_sprites_10_ADDRESS 0x6D52u    /* 06CD52 */
#define goon_with_hat_animations_44_ADDRESS 0x6D6Au    /* 06CD6A */
#define goon_with_hat_animations_44_sprites_ADDRESS 0x6D86u    /* 06CD86 */
#define goon_with_hat_animations_44_sprites_2_ADDRESS 0x6D98u    /* 06CD98 */
#define goon_with_hat_animations_44_sprites_3_ADDRESS 0x6DAAu    /* 06CDAA */
#define goon_with_hat_animations_45_ADDRESS 0x6DBCu    /* 06CDBC */
#define goon_with_hat_animations_45_sprites_ADDRESS 0x6DC4u    /* 06CDC4 */
#define goon_with_hat_animations_49_ADDRESS 0x6DCAu    /* 06CDCA */
#define goon_with_hat_animations_49_sprites_ADDRESS 0x6DDEu    /* 06CDDE */
#define goon_with_hat_animations_49_sprites_2_ADDRESS 0x6DEAu    /* 06CDEA */
#define goon_with_hat_animations_49_sprites_3_ADDRESS 0x6DF6u    /* 06CDF6 */
#define goon_with_hat_animations_49_sprites_4_ADDRESS 0x6E02u    /* 06CE02 */
#define goon_with_hat_animations_50_ADDRESS 0x6E0Eu    /* 06CE0E */
#define goon_with_hat_animations_50_sprites_ADDRESS 0x6E26u    /* 06CE26 */
#define goon_with_hat_animations_50_sprites_2_ADDRESS 0x6E32u    /* 06CE32 */
#define goon_with_hat_animations_50_sprites_3_ADDRESS 0x6E3Eu    /* 06CE3E */
#define goon_with_hat_animations_50_sprites_4_ADDRESS 0x6E4Au    /* 06CE4A */
#define goon_with_hat_animations_20_ADDRESS 0x6E5Cu    /* 06CE5C */
#define goon_with_hat_animations_20_sprites_ADDRESS 0x6E64u    /* 06CE64 */
#define goon_with_hat_animations_51_ADDRESS 0x6E70u    /* 06CE70 */
#define goon_with_hat_animations_51_sprites_ADDRESS 0x6E94u    /* 06CE94 */
#define goon_with_hat_animations_51_sprites_2_ADDRESS 0x6EB2u    /* 06CEB2 */
#define goon_with_hat_animations_51_sprites_3_ADDRESS 0x6ED0u    /* 06CED0 */
#define goon_with_hat_animations_51_sprites_4_ADDRESS 0x6EEEu    /* 06CEEE */
#define goon_with_hat_animations_51_sprites_5_ADDRESS 0x6F0Cu    /* 06CF0C */
#define goon_with_hat_animations_51_sprites_6_ADDRESS 0x6F2Au    /* 06CF2A */
#define goon_with_hat_animations_51_sprites_7_ADDRESS 0x6F48u    /* 06CF48 */
#define goon_with_hat_animations_51_sprites_8_ADDRESS 0x6F66u    /* 06CF66 */
#define goon_with_hat_animations_52_ADDRESS 0x6F84u    /* 06CF84 */
#define goon_with_hat_animations_52_sprites_ADDRESS 0x6F98u    /* 06CF98 */
#define goon_with_hat_animations_52_sprites_2_ADDRESS 0x6F9Eu    /* 06CF9E */
#define goon_with_hat_animations_52_sprites_3_ADDRESS 0x6FA4u    /* 06CFA4 */
#define goon_with_hat_animations_52_sprites_4_ADDRESS 0x6FAAu    /* 06CFAA */
#define goon_with_hat_animations_21_ADDRESS 0x6FB0u    /* 06CFB0 */
#define goon_with_hat_animations_21_sprites_ADDRESS 0x6FC0u    /* 06CFC0 */
#define goon_with_hat_animations_21_sprites_2_ADDRESS 0x6FCCu    /* 06CFCC */
#define goon_with_hat_animations_21_sprites_3_ADDRESS 0x6FD8u    /* 06CFD8 */
#define goon_with_hat_animations_22_ADDRESS 0x6FE4u    /* 06CFE4 */
#define goon_with_hat_animations_22_sprites_ADDRESS 0x6FF4u    /* 06CFF4 */
#define goon_with_hat_animations_22_sprites_2_ADDRESS 0x7000u    /* 06D000 */
#define goon_with_hat_animations_22_sprites_3_ADDRESS 0x700Cu    /* 06D00C */
#define goon_with_hat_animations_53_ADDRESS 0x7018u    /* 06D018 */
#define goon_with_hat_animations_53_sprites_ADDRESS 0x703Cu    /* 06D03C */
#define goon_with_hat_animations_53_sprites_2_ADDRESS 0x705Au    /* 06D05A */
#define goon_with_hat_animations_53_sprites_3_ADDRESS 0x7078u    /* 06D078 */
#define goon_with_hat_animations_53_sprites_4_ADDRESS 0x7096u    /* 06D096 */
#define goon_with_hat_animations_53_sprites_5_ADDRESS 0x70B4u    /* 06D0B4 */
#define goon_with_hat_animations_53_sprites_6_ADDRESS 0x70D2u    /* 06D0D2 */
#define goon_with_hat_animations_53_sprites_7_ADDRESS 0x70F0u    /* 06D0F0 */
#define goon_with_hat_animations_53_sprites_8_ADDRESS 0x710Eu    /* 06D10E */
#define goon_with_hat_animations_55_ADDRESS 0x712Cu    /* 06D12C */
#define goon_with_hat_animations_55_sprites_ADDRESS 0x7138u    /* 06D138 */
#define goon_with_hat_animations_55_sprites_2_ADDRESS 0x713Eu    /* 06D13E */
#define goon_with_hat_animations_23_ADDRESS 0x7144u    /* 06D144 */
#define goon_with_hat_animations_23_sprites_ADDRESS 0x7158u    /* 06D158 */
#define goon_with_hat_animations_23_sprites_2_ADDRESS 0x7176u    /* 06D176 */
#define goon_with_hat_animations_23_sprites_3_ADDRESS 0x7194u    /* 06D194 */
#define goon_with_hat_animations_23_sprites_4_ADDRESS 0x71B2u    /* 06D1B2 */
#define goon_with_hat_animations_24_ADDRESS 0x71D0u    /* 06D1D0 */
#define goon_with_hat_animations_57_ADDRESS 0x71E4u    /* 06D1E4 */
#define goon_with_hat_animations_57_sprites_ADDRESS 0x71FCu    /* 06D1FC */
#define goon_with_hat_animations_57_sprites_2_ADDRESS 0x720Eu    /* 06D20E */
#define goon_with_hat_animations_57_sprites_3_ADDRESS 0x721Au    /* 06D21A */
#define goon_with_hat_animations_57_sprites_4_ADDRESS 0x722Cu    /* 06D22C */
#define goon_with_hat_animations_57_sprites_5_ADDRESS 0x7244u    /* 06D244 */
#define goon_with_hat_animations_58_ADDRESS 0x7256u    /* 06D256 */
#define goon_with_hat_animations_58_sprites_ADDRESS 0x7266u    /* 06D266 */
#define goon_with_hat_animations_58_sprites_2_ADDRESS 0x7278u    /* 06D278 */
#define bear_animations_ADDRESS 0x728Au    /* 06D28A */
#define bear_animations_0_ADDRESS 0x72AAu    /* 06D2AA */
#define bear_animations_0_sprites_ADDRESS 0x72C2u    /* 06D2C2 */
#define bear_animations_0_sprites_2_ADDRESS 0x72E0u    /* 06D2E0 */
#define bear_animations_0_sprites_3_ADDRESS 0x7304u    /* 06D304 */
#define bear_animations_0_sprites_4_ADDRESS 0x7328u    /* 06D328 */
#define bear_animations_0_sprites_5_ADDRESS 0x734Cu    /* 06D34C */
#define bear_animations_1_ADDRESS 0x736Au    /* 06D36A */
#define bear_animations_1_sprites_ADDRESS 0x737Eu    /* 06D37E */
#define bear_animations_1_sprites_2_ADDRESS 0x73A8u    /* 06D3A8 */
#define bear_animations_1_sprites_3_ADDRESS 0x73CCu    /* 06D3CC */
#define bear_animations_1_sprites_4_ADDRESS 0x73F6u    /* 06D3F6 */
#define bear_animations_2_ADDRESS 0x740Eu    /* 06D40E */
#define bear_animations_2_sprites_ADDRESS 0x741Au    /* 06D41A */
#define bear_animations_2_sprites_2_ADDRESS 0x7432u    /* 06D432 */
#define bear_animations_3_ADDRESS 0x7462u    /* 06D462 */
#define bear_animations_3_sprites_ADDRESS 0x746Eu    /* 06D46E */
#define bear_animations_3_sprites_2_ADDRESS 0x748Cu    /* 06D48C */
#define bear_animations_4_ADDRESS 0x74AAu    /* 06D4AA */
#define bear_animations_4_sprites_ADDRESS 0x74BEu    /* 06D4BE */
#define bear_animations_4_sprites_2_ADDRESS 0x74DCu    /* 06D4DC */
#define bear_animations_4_sprites_3_ADDRESS 0x74FAu    /* 06D4FA */
#define bear_animations_5_ADDRESS 0x751Eu    /* 06D51E */
#define bear_animations_5_sprites_ADDRESS 0x7526u    /* 06D526 */
#define bear_animations_6_ADDRESS 0x7556u    /* 06D556 */
#define bear_animations_6_sprites_ADDRESS 0x7562u    /* 06D562 */
#define bear_animations_6_sprites_2_ADDRESS 0x7580u    /* 06D580 */
#define bear_animations_7_ADDRESS 0x759Eu    /* 06D59E */
#define bear_animations_7_sprites_ADDRESS 0x75BEu    /* 06D5BE */
#define bear_animations_7_sprites_2_ADDRESS 0x75D6u    /* 06D5D6 */
#define bear_animations_7_sprites_3_ADDRESS 0x75EEu    /* 06D5EE */
#define bear_animations_7_sprites_4_ADDRESS 0x7606u    /* 06D606 */
#define bear_animations_8_ADDRESS 0x761Eu    /* 06D61E */
#define bear_animations_8_sprites_ADDRESS 0x762Au    /* 06D62A */
#define bear_animations_8_sprites_2_ADDRESS 0x7642u    /* 06D642 */
#define bear_animations_9_ADDRESS 0x7666u    /* 06D666 */
#define bear_animations_9_sprites_ADDRESS 0x7686u    /* 06D686 */
#define bear_animations_9_sprites_2_ADDRESS 0x76AAu    /* 06D6AA */
#define bear_animations_9_sprites_3_ADDRESS 0x76C8u    /* 06D6C8 */
#define bear_animations_10_ADDRESS 0x76E6u    /* 06D6E6 */
#define bear_animations_10_sprites_ADDRESS 0x7716u    /* 06D716 */
#define bear_animations_10_sprites_2_ADDRESS 0x7734u    /* 06D734 */
#define bear_animations_10_sprites_3_ADDRESS 0x7752u    /* 06D752 */
#define bear_animations_10_sprites_4_ADDRESS 0x7770u    /* 06D770 */
#define bear_animations_11_ADDRESS 0x778Eu    /* 06D78E */
#define bear_animations_11_sprites_ADDRESS 0x77AAu    /* 06D7AA */
#define bear_animations_11_sprites_2_ADDRESS 0x77C8u    /* 06D7C8 */
#define bear_animations_12_ADDRESS 0x77E0u    /* 06D7E0 */
#define bear_animations_12_sprites_ADDRESS 0x77F4u    /* 06D7F4 */
#define bear_animations_12_sprites_2_ADDRESS 0x7806u    /* 06D806 */
#define bear_animations_12_sprites_3_ADDRESS 0x7812u    /* 06D812 */
#define bear_animations_12_sprites_4_ADDRESS 0x781Eu    /* 06D81E */
#define bear_animations_13_ADDRESS 0x7830u    /* 06D830 */
#define bear_animations_13_sprites_ADDRESS 0x7844u    /* 06D844 */
#define bear_animations_13_sprites_2_ADDRESS 0x7862u    /* 06D862 */
#define bear_animations_13_sprites_3_ADDRESS 0x788Cu    /* 06D88C */
#define bear_animations_13_sprites_4_ADDRESS 0x78B0u    /* 06D8B0 */
#define bear_animations_14_ADDRESS 0x78DAu    /* 06D8DA */
#define bear_animations_14_sprites_ADDRESS 0x78E2u    /* 06D8E2 */
#define bear_animations_15_ADDRESS 0x7900u    /* 06D900 */
#define bear_animations_15_sprites_ADDRESS 0x7910u    /* 06D910 */
#define bear_animations_15_sprites_2_ADDRESS 0x791Cu    /* 06D91C */
#define bear_animations_15_sprites_3_ADDRESS 0x7928u    /* 06D928 */
#define kind_B6_animations_ADDRESS 0x7934u    /* 06D934 */
#define posters_animations_ADDRESS 0x79AAu    /* 06D9AA */
#define posters_animations_0_ADDRESS 0x79B6u    /* 06D9B6 */
#define posters_animations_0_sprites_ADDRESS 0x79FAu    /* 06D9FA */
#define posters_animations_0_sprites_2_ADDRESS 0x7A00u    /* 06DA00 */
#define posters_animations_0_sprites_3_ADDRESS 0x7A06u    /* 06DA06 */
#define posters_animations_0_sprites_4_ADDRESS 0x7A0Cu    /* 06DA0C */
#define posters_animations_0_sprites_5_ADDRESS 0x7A12u    /* 06DA12 */
#define posters_animations_0_sprites_6_ADDRESS 0x7A18u    /* 06DA18 */
#define posters_animations_0_sprites_7_ADDRESS 0x7A1Eu    /* 06DA1E */
#define posters_animations_0_sprites_8_ADDRESS 0x7A24u    /* 06DA24 */
#define posters_animations_1_ADDRESS 0x7A2Au    /* 06DA2A */
#define posters_animations_1_sprites_ADDRESS 0x7A6Eu    /* 06DA6E */
#define posters_animations_1_sprites_2_ADDRESS 0x7A74u    /* 06DA74 */
#define posters_animations_1_sprites_3_ADDRESS 0x7A7Au    /* 06DA7A */
#define posters_animations_1_sprites_4_ADDRESS 0x7A80u    /* 06DA80 */
#define posters_animations_1_sprites_5_ADDRESS 0x7A86u    /* 06DA86 */
#define posters_animations_1_sprites_6_ADDRESS 0x7A8Cu    /* 06DA8C */
#define posters_animations_1_sprites_7_ADDRESS 0x7A92u    /* 06DA92 */
#define posters_animations_1_sprites_8_ADDRESS 0x7A98u    /* 06DA98 */
#define posters_animations_1_sprites_9_ADDRESS 0x7A9Eu    /* 06DA9E */
#define posters_animations_1_sprites_10_ADDRESS 0x7AA4u    /* 06DAA4 */
#define posters_animations_1_sprites_11_ADDRESS 0x7AAAu    /* 06DAAA */
#define posters_animations_2_ADDRESS 0x7AB0u    /* 06DAB0 */
#define posters_animations_2_sprites_ADDRESS 0x7AD0u    /* 06DAD0 */
#define posters_animations_2_sprites_2_ADDRESS 0x7AD6u    /* 06DAD6 */
#define posters_animations_2_sprites_3_ADDRESS 0x7ADCu    /* 06DADC */
#define posters_animations_2_sprites_4_ADDRESS 0x7AE2u    /* 06DAE2 */
#define posters_animations_2_sprites_5_ADDRESS 0x7AE8u    /* 06DAE8 */
#define posters_animations_2_sprites_6_ADDRESS 0x7AEEu    /* 06DAEE */
#define posters_animations_2_sprites_7_ADDRESS 0x7AFAu    /* 06DAFA */
#define posters_animations_4_ADDRESS 0x7B00u    /* 06DB00 */
#define posters_animations_4_sprites_ADDRESS 0x7B24u    /* 06DB24 */
#define posters_animations_4_sprites_2_ADDRESS 0x7B36u    /* 06DB36 */
#define posters_animations_5_ADDRESS 0x7B48u    /* 06DB48 */
#define posters_animations_5_sprites_ADDRESS 0x7B60u    /* 06DB60 */
#define posters_animations_5_sprites_2_ADDRESS 0x7B72u    /* 06DB72 */
#define posters_animations_5_sprites_3_ADDRESS 0x7B84u    /* 06DB84 */
#define posters_animations_5_sprites_4_ADDRESS 0x7B96u    /* 06DB96 */
#define posters_animations_5_sprites_5_ADDRESS 0x7BA8u    /* 06DBA8 */
#define posters_animations_3_ADDRESS 0x7BBAu    /* 06DBBA */
#define posters_animations_3_sprites_ADDRESS 0x7BDEu    /* 06DBDE */
#define posters_animations_3_sprites_2_ADDRESS 0x7BEAu    /* 06DBEA */
#define posters_animations_3_sprites_3_ADDRESS 0x7BF6u    /* 06DBF6 */
#define drink_vendor_animations_ADDRESS 0x7C1Au    /* 06DC1A */
#define drink_vendor_animations_0_ADDRESS 0x7C20u    /* 06DC20 */
#define drink_vendor_animations_0_sprites_ADDRESS 0x7C30u    /* 06DC30 */
#define drink_vendor_animations_0_sprites_2_ADDRESS 0x7C48u    /* 06DC48 */
#define drink_vendor_animations_0_sprites_3_ADDRESS 0x7C60u    /* 06DC60 */
#define drink_vendor_animations_1_ADDRESS 0x7C78u    /* 06DC78 */
#define drink_vendor_animations_1_sprites_ADDRESS 0x7C8Cu    /* 06DC8C */
#define drink_vendor_animations_1_sprites_2_ADDRESS 0x7CAAu    /* 06DCAA */
#define drink_vendor_animations_2_ADDRESS 0x7CC8u    /* 06DCC8 */
#define drink_vendor_animations_2_sprites_ADDRESS 0x7CDCu    /* 06DCDC */
#define drink_vendor_animations_2_sprites_2_ADDRESS 0x7CEEu    /* 06DCEE */
#define drink_vendor_animations_2_sprites_3_ADDRESS 0x7D00u    /* 06DD00 */
#define drink_vendor_animations_2_sprites_4_ADDRESS 0x7D18u    /* 06DD18 */
#define burger_eater_animations_ADDRESS 0x7D2Au    /* 06DD2A */
#define burger_eater_animations_0_ADDRESS 0x7D30u    /* 06DD30 */
#define burger_eater_animations_0_sprites_ADDRESS 0x7D80u    /* 06DD80 */
#define burger_eater_animations_0_sprites_2_ADDRESS 0x7D98u    /* 06DD98 */
#define burger_eater_animations_0_sprites_3_ADDRESS 0x7DAAu    /* 06DDAA */
#define burger_eater_animations_0_sprites_4_ADDRESS 0x7DBCu    /* 06DDBC */
#define burger_eater_animations_0_sprites_5_ADDRESS 0x7DD4u    /* 06DDD4 */
#define burger_eater_animations_0_sprites_6_ADDRESS 0x7DF2u    /* 06DDF2 */
#define burger_eater_animations_0_sprites_7_ADDRESS 0x7E10u    /* 06DE10 */
#define burger_eater_animations_1_ADDRESS 0x7E28u    /* 06DE28 */
#define burger_eater_animations_1_sprites_ADDRESS 0x7E30u    /* 06DE30 */
#define burger_eater_animations_2_ADDRESS 0x7E36u    /* 06DE36 */
#define burger_eater_animations_2_sprites_ADDRESS 0x7E46u    /* 06DE46 */
#define burger_eater_animations_2_sprites_2_ADDRESS 0x7E58u    /* 06DE58 */
#define burger_eater_animations_2_sprites_3_ADDRESS 0x7E70u    /* 06DE70 */
#define burger_eater_animations_2_sprites_3_fill_ADDRESS 0x7E88u    /* 06DE88 */
#define burger_eater_animations_2_sprites_3_rest_ADDRESS 0x6000u    /* 06E000 */
#define krusty_balloon_animations_2_ADDRESS 0x6008u    /* 06E008 */
#define krusty_balloon_animations_2_0_ADDRESS 0x601Eu    /* 06E01E */
#define krusty_balloon_animations_2_0_sprites_ADDRESS 0x602Eu    /* 06E02E */
#define krusty_balloon_animations_2_0_sprites_2_ADDRESS 0x6064u    /* 06E064 */
#define krusty_balloon_animations_2_0_sprites_3_ADDRESS 0x609Au    /* 06E09A */
#define krusty_balloon_animations_2_1_ADDRESS 0x60D0u    /* 06E0D0 */
#define krusty_balloon_animations_2_1_sprites_ADDRESS 0x60E4u    /* 06E0E4 */
#define krusty_balloon_animations_2_1_sprites_2_ADDRESS 0x6132u    /* 06E132 */
#define krusty_balloon_animations_2_1_sprites_3_ADDRESS 0x6180u    /* 06E180 */
#define krusty_balloon_animations_2_2_ADDRESS 0x61CEu    /* 06E1CE */
#define krusty_balloon_animations_2_2_sprites_ADDRESS 0x61D6u    /* 06E1D6 */
#define krusty_balloon_animations_2_3_ADDRESS 0x6230u    /* 06E230 */
#define krusty_balloon_animations_2_3_sprites_ADDRESS 0x6238u    /* 06E238 */
#define krusty_balloon_animations_2_4_ADDRESS 0x6292u    /* 06E292 */
#define krusty_balloon_animations_2_4_sprites_ADDRESS 0x62C6u    /* 06E2C6 */
#define krusty_balloon_animations_2_4_sprites_2_ADDRESS 0x62FCu    /* 06E2FC */
#define krusty_balloon_animations_2_4_sprites_3_ADDRESS 0x6332u    /* 06E332 */
#define krusty_balloon_animations_2_4_sprites_4_ADDRESS 0x6368u    /* 06E368 */
#define krusty_balloon_animations_2_4_sprites_5_ADDRESS 0x639Eu    /* 06E39E */
#define krusty_balloon_animations_2_4_sprites_6_ADDRESS 0x63D4u    /* 06E3D4 */
#define krusty_balloon_animations_2_4_sprites_7_ADDRESS 0x640Au    /* 06E40A */
#define krusty_balloon_animations_2_5_ADDRESS 0x6446u    /* 06E446 */
#define krusty_balloon_animations_2_5_sprites_ADDRESS 0x6456u    /* 06E456 */
#define krusty_balloon_animations_2_5_sprites_2_ADDRESS 0x64A4u    /* 06E4A4 */
#define krusty_balloon_animations_2_6_ADDRESS 0x64F2u    /* 06E4F2 */
#define krusty_balloon_animations_2_6_sprites_ADDRESS 0x6502u    /* 06E502 */
#define krusty_balloon_animations_2_6_sprites_2_ADDRESS 0x6508u    /* 06E508 */
#define krusty_balloon_animations_2_6_sprites_3_ADDRESS 0x650Eu    /* 06E50E */
#define krusty_balloon_animations_2_7_ADDRESS 0x6514u    /* 06E514 */
#define krusty_balloon_animations_2_7_sprites_ADDRESS 0x6528u    /* 06E528 */
#define krusty_balloon_animations_2_8_ADDRESS 0x652Eu    /* 06E52E */
#define krusty_balloon_animations_2_8_sprites_ADDRESS 0x6536u    /* 06E536 */
#define krusty_balloon_animations_2_9_ADDRESS 0x6590u    /* 06E590 */
#define krusty_balloon_animations_2_9_sprites_ADDRESS 0x65C4u    /* 06E5C4 */
#define krusty_balloon_animations_2_9_sprites_2_ADDRESS 0x65FAu    /* 06E5FA */
#define krusty_balloon_animations_2_9_sprites_3_ADDRESS 0x6630u    /* 06E630 */
#define krusty_balloon_animations_2_9_sprites_4_ADDRESS 0x6666u    /* 06E666 */
#define krusty_balloon_animations_2_9_sprites_5_ADDRESS 0x669Cu    /* 06E69C */
#define krusty_balloon_animations_2_9_sprites_6_ADDRESS 0x66D2u    /* 06E6D2 */
#define krusty_balloon_animations_2_9_sprites_7_ADDRESS 0x6708u    /* 06E708 */
#define krusty_balloon_animations_2_10_ADDRESS 0x6744u    /* 06E744 */
#define krusty_balloon_animations_2_10_sprites_ADDRESS 0x676Cu    /* 06E76C */
#define krusty_balloon_animations_2_10_sprites_2_ADDRESS 0x67BAu    /* 06E7BA */
#define krusty_balloon_animations_2_10_sprites_3_ADDRESS 0x6808u    /* 06E808 */
#define krusty_balloon_animations_2_10_sprites_4_ADDRESS 0x6856u    /* 06E856 */
#define krusty_balloon_animations_2_10_sprites_5_ADDRESS 0x68A4u    /* 06E8A4 */
#define moe_animations_ADDRESS 0x68FEu    /* 06E8FE */
#define moe_animations_0_ADDRESS 0x690Cu    /* 06E90C */
#define moe_animations_0_sprites_ADDRESS 0x691Cu    /* 06E91C */
#define moe_animations_0_sprites_2_ADDRESS 0x692Eu    /* 06E92E */
#define moe_animations_0_sprites_3_ADDRESS 0x6946u    /* 06E946 */
#define moe_animations_1_ADDRESS 0x695Eu    /* 06E95E */
#define moe_animations_1_sprites_ADDRESS 0x696Au    /* 06E96A */
#define moe_animations_1_sprites_2_ADDRESS 0x697Cu    /* 06E97C */
#define moe_animations_2_ADDRESS 0x6988u    /* 06E988 */
#define moe_animations_2_sprites_ADDRESS 0x6998u    /* 06E998 */
#define moe_animations_2_sprites_2_ADDRESS 0x69B6u    /* 06E9B6 */
#define moe_animations_2_sprites_3_ADDRESS 0x69C8u    /* 06E9C8 */
#define moe_animations_3_ADDRESS 0x69DAu    /* 06E9DA */
#define moe_animations_3_sprites_ADDRESS 0x69EEu    /* 06E9EE */
#define moe_animations_4_ADDRESS 0x69FAu    /* 06E9FA */
#define moe_animations_5_ADDRESS 0x6A06u    /* 06EA06 */
#define moe_animations_5_sprites_ADDRESS 0x6A1Au    /* 06EA1A */
#define moe_animations_5_sprites_2_ADDRESS 0x6A4Au    /* 06EA4A */
#define moe_animations_6_ADDRESS 0x6A80u    /* 06EA80 */
#define moe_animations_6_sprites_ADDRESS 0x6A88u    /* 06EA88 */
#define robot_animations_ADDRESS 0x6A8Eu    /* 06EA8E */
#define robot_animations_0_ADDRESS 0x6ACCu    /* 06EACC */
#define robot_animations_0_sprites_ADDRESS 0x6B00u    /* 06EB00 */
#define robot_animations_0_sprites_2_ADDRESS 0x6B24u    /* 06EB24 */
#define robot_animations_0_sprites_3_ADDRESS 0x6B48u    /* 06EB48 */
#define robot_animations_0_sprites_4_ADDRESS 0x6B6Cu    /* 06EB6C */
#define robot_animations_0_sprites_5_ADDRESS 0x6B90u    /* 06EB90 */
#define robot_animations_0_sprites_6_ADDRESS 0x6BB4u    /* 06EBB4 */
#define robot_animations_0_sprites_7_ADDRESS 0x6BD8u    /* 06EBD8 */
#define robot_animations_0_sprites_8_ADDRESS 0x6BFCu    /* 06EBFC */
#define robot_animations_0_sprites_9_ADDRESS 0x6C20u    /* 06EC20 */
#define robot_animations_0_sprites_10_ADDRESS 0x6C44u    /* 06EC44 */
#define robot_animations_0_sprites_11_ADDRESS 0x6C68u    /* 06EC68 */
#define robot_animations_0_sprites_12_ADDRESS 0x6C8Cu    /* 06EC8C */
#define robot_animations_1_ADDRESS 0x6CB0u    /* 06ECB0 */
#define robot_animations_1_sprites_ADDRESS 0x6CD4u    /* 06ECD4 */
#define robot_animations_1_sprites_2_ADDRESS 0x6CF2u    /* 06ECF2 */
#define robot_animations_1_sprites_3_ADDRESS 0x6D16u    /* 06ED16 */
#define robot_animations_1_sprites_4_ADDRESS 0x6D3Au    /* 06ED3A */
#define robot_animations_1_sprites_5_ADDRESS 0x6D5Eu    /* 06ED5E */
#define robot_animations_1_sprites_6_ADDRESS 0x6D82u    /* 06ED82 */
#define robot_animations_1_sprites_7_ADDRESS 0x6DA6u    /* 06EDA6 */
#define robot_animations_1_sprites_8_ADDRESS 0x6DCAu    /* 06EDCA */
#define robot_animations_16_ADDRESS 0x6DEEu    /* 06EDEE */
#define robot_animations_16_sprites_ADDRESS 0x6E1Au    /* 06EE1A */
#define robot_animations_16_sprites_2_ADDRESS 0x6E3Eu    /* 06EE3E */
#define robot_animations_16_sprites_3_ADDRESS 0x6E62u    /* 06EE62 */
#define robot_animations_16_sprites_4_ADDRESS 0x6E86u    /* 06EE86 */
#define robot_animations_16_sprites_5_ADDRESS 0x6EAAu    /* 06EEAA */
#define robot_animations_16_sprites_6_ADDRESS 0x6ECEu    /* 06EECE */
#define robot_animations_16_sprites_7_ADDRESS 0x6EF2u    /* 06EEF2 */
#define robot_animations_16_sprites_8_ADDRESS 0x6F16u    /* 06EF16 */
#define robot_animations_16_sprites_9_ADDRESS 0x6F3Au    /* 06EF3A */
#define robot_animations_16_sprites_10_ADDRESS 0x6F5Eu    /* 06EF5E */
#define robot_animations_17_ADDRESS 0x6F82u    /* 06EF82 */
#define robot_animations_17_sprites_ADDRESS 0x6FAEu    /* 06EFAE */
#define robot_animations_17_sprites_2_ADDRESS 0x6FD8u    /* 06EFD8 */
#define robot_animations_17_sprites_3_ADDRESS 0x7002u    /* 06F002 */
#define robot_animations_17_sprites_4_ADDRESS 0x702Cu    /* 06F02C */
#define robot_animations_17_sprites_5_ADDRESS 0x7056u    /* 06F056 */
#define robot_animations_17_sprites_6_ADDRESS 0x7080u    /* 06F080 */
#define robot_animations_17_sprites_7_ADDRESS 0x70B0u    /* 06F0B0 */
#define robot_animations_18_ADDRESS 0x70E6u    /* 06F0E6 */
#define robot_animations_18_sprites_ADDRESS 0x7112u    /* 06F112 */
#define robot_animations_18_sprites_2_ADDRESS 0x713Cu    /* 06F13C */
#define robot_animations_18_sprites_3_ADDRESS 0x7166u    /* 06F166 */
#define robot_animations_18_sprites_4_ADDRESS 0x7190u    /* 06F190 */
#define robot_animations_18_sprites_5_ADDRESS 0x71BAu    /* 06F1BA */
#define robot_animations_18_sprites_6_ADDRESS 0x71E4u    /* 06F1E4 */
#define robot_animations_18_sprites_7_ADDRESS 0x7214u    /* 06F214 */
#define robot_animations_19_ADDRESS 0x724Au    /* 06F24A */
#define robot_animations_19_sprites_ADDRESS 0x7252u    /* 06F252 */
#define robot_animations_20_ADDRESS 0x7258u    /* 06F258 */
#define robot_animations_20_sprites_ADDRESS 0x7260u    /* 06F260 */
#define robot_animations_21_ADDRESS 0x7266u    /* 06F266 */
#define robot_animations_21_sprites_ADDRESS 0x726Eu    /* 06F26E */
#define robot_animations_22_ADDRESS 0x7274u    /* 06F274 */
#define robot_animations_22_sprites_ADDRESS 0x727Cu    /* 06F27C */
#define robot_animations_23_ADDRESS 0x72A0u    /* 06F2A0 */
#define robot_animations_25_ADDRESS 0x72D4u    /* 06F2D4 */
#define robot_animations_25_sprites_ADDRESS 0x72E0u    /* 06F2E0 */
#define robot_animations_25_sprites_2_ADDRESS 0x72ECu    /* 06F2EC */
#define robot_animations_24_ADDRESS 0x72F8u    /* 06F2F8 */
#define robot_animations_24_sprites_ADDRESS 0x7314u    /* 06F314 */
#define robot_animations_24_sprites_2_ADDRESS 0x7320u    /* 06F320 */
#define robot_animations_24_sprites_3_ADDRESS 0x732Cu    /* 06F32C */
#define robot_animations_24_sprites_4_ADDRESS 0x7338u    /* 06F338 */
#define robot_animations_26_ADDRESS 0x7344u    /* 06F344 */
#define robot_animations_26_sprites_ADDRESS 0x7350u    /* 06F350 */
#define robot_animations_26_sprites_2_ADDRESS 0x7356u    /* 06F356 */
#define robot_animations_27_ADDRESS 0x735Cu    /* 06F35C */
#define robot_animations_27_sprites_ADDRESS 0x7364u    /* 06F364 */
#define robot_animations_28_ADDRESS 0x736Au    /* 06F36A */
#define robot_animations_28_sprites_ADDRESS 0x7372u    /* 06F372 */
#define robot_animations_29_ADDRESS 0x7378u    /* 06F378 */
#define robot_animations_29_sprites_ADDRESS 0x73A8u    /* 06F3A8 */
#define robot_animations_29_sprites_2_ADDRESS 0x73CCu    /* 06F3CC */
#define robot_animations_29_sprites_3_ADDRESS 0x73F0u    /* 06F3F0 */
#define robot_animations_29_sprites_4_ADDRESS 0x741Au    /* 06F41A */
#define robot_animations_29_sprites_5_ADDRESS 0x7444u    /* 06F444 */
#define robot_animations_29_sprites_6_ADDRESS 0x746Eu    /* 06F46E */
#define robot_animations_29_sprites_7_ADDRESS 0x749Eu    /* 06F49E */
#define robot_animations_29_sprites_8_ADDRESS 0x74D4u    /* 06F4D4 */
#define robot_animations_29_sprites_9_ADDRESS 0x7504u    /* 06F504 */
#define robot_animations_29_sprites_10_ADDRESS 0x752Eu    /* 06F52E */
#define robot_animations_29_sprites_11_ADDRESS 0x7558u    /* 06F558 */
#define robot_animations_30_ADDRESS 0x757Cu    /* 06F57C */
#define robot_animations_30_sprites_ADDRESS 0x75ACu    /* 06F5AC */
#define robot_animations_30_sprites_2_ADDRESS 0x75D6u    /* 06F5D6 */
#define robot_animations_30_sprites_3_ADDRESS 0x7600u    /* 06F600 */
#define robot_animations_30_sprites_4_ADDRESS 0x762Au    /* 06F62A */
#define robot_animations_30_sprites_5_ADDRESS 0x7654u    /* 06F654 */
#define robot_animations_30_sprites_6_ADDRESS 0x767Eu    /* 06F67E */
#define robot_animations_30_sprites_7_ADDRESS 0x76AEu    /* 06F6AE */
#define robot_animations_30_sprites_8_ADDRESS 0x76E4u    /* 06F6E4 */
#define robot_animations_30_sprites_9_ADDRESS 0x7714u    /* 06F714 */
#define robot_animations_30_sprites_10_ADDRESS 0x773Eu    /* 06F73E */
#define robot_animations_30_sprites_11_ADDRESS 0x7768u    /* 06F768 */
#define gorilla_animations_ADDRESS 0x778Cu    /* 06F78C */
#define gorilla_animations_0_ADDRESS 0x77B4u    /* 06F7B4 */
#define gorilla_animations_0_sprites_ADDRESS 0x77D8u    /* 06F7D8 */
#define gorilla_animations_0_sprites_2_ADDRESS 0x77E4u    /* 06F7E4 */
#define gorilla_animations_0_sprites_3_ADDRESS 0x77F6u    /* 06F7F6 */
#define gorilla_animations_0_sprites_4_ADDRESS 0x780Eu    /* 06F80E */
#define gorilla_animations_0_sprites_5_ADDRESS 0x7820u    /* 06F820 */
#define gorilla_animations_0_sprites_6_ADDRESS 0x782Cu    /* 06F82C */
#define gorilla_animations_0_sprites_7_ADDRESS 0x783Eu    /* 06F83E */
#define gorilla_animations_0_sprites_8_ADDRESS 0x784Au    /* 06F84A */
#define gorilla_animations_16_ADDRESS 0x7856u    /* 06F856 */
#define gorilla_animations_16_sprites_ADDRESS 0x7876u    /* 06F876 */
#define gorilla_animations_16_sprites_2_ADDRESS 0x788Eu    /* 06F88E */
#define gorilla_animations_16_sprites_3_ADDRESS 0x78A0u    /* 06F8A0 */
#define gorilla_animations_16_sprites_4_ADDRESS 0x78B8u    /* 06F8B8 */
#define gorilla_animations_16_sprites_5_ADDRESS 0x78D6u    /* 06F8D6 */
#define gorilla_animations_16_sprites_6_ADDRESS 0x78EEu    /* 06F8EE */
#define gorilla_animations_16_sprites_7_ADDRESS 0x7906u    /* 06F906 */
#define gorilla_animations_6_ADDRESS 0x7918u    /* 06F918 */
#define gorilla_animations_6_sprites_ADDRESS 0x793Cu    /* 06F93C */
#define gorilla_animations_6_sprites_2_ADDRESS 0x7942u    /* 06F942 */
#define gorilla_animations_6_sprites_3_ADDRESS 0x794Eu    /* 06F94E */
#define gorilla_animations_6_sprites_4_ADDRESS 0x7960u    /* 06F960 */
#define gorilla_animations_9_ADDRESS 0x7972u    /* 06F972 */
#define gorilla_animations_9_sprites_ADDRESS 0x7982u    /* 06F982 */
#define gorilla_animations_9_sprites_2_ADDRESS 0x7994u    /* 06F994 */
#define gorilla_animations_9_sprites_3_ADDRESS 0x79A0u    /* 06F9A0 */
#define gorilla_animations_8_ADDRESS 0x79ACu    /* 06F9AC */
#define gorilla_animations_8_sprites_ADDRESS 0x79CCu    /* 06F9CC */
#define gorilla_animations_8_sprites_2_ADDRESS 0x79D8u    /* 06F9D8 */
#define gorilla_animations_8_sprites_3_ADDRESS 0x79E4u    /* 06F9E4 */
#define gorilla_animations_8_sprites_4_ADDRESS 0x79F0u    /* 06F9F0 */
#define gorilla_animations_17_ADDRESS 0x79FCu    /* 06F9FC */
#define gorilla_animations_17_sprites_ADDRESS 0x7A30u    /* 06FA30 */
#define gorilla_animations_17_sprites_2_ADDRESS 0x7A48u    /* 06FA48 */
#define gorilla_animations_17_sprites_3_ADDRESS 0x7A60u    /* 06FA60 */
#define gorilla_animations_17_sprites_4_ADDRESS 0x7A78u    /* 06FA78 */
#define gorilla_animations_17_sprites_5_ADDRESS 0x7A90u    /* 06FA90 */
#define gorilla_animations_17_sprites_6_ADDRESS 0x7AA8u    /* 06FAA8 */
#define gorilla_animations_17_sprites_7_ADDRESS 0x7ABAu    /* 06FABA */
#define gorilla_animations_18_ADDRESS 0x7ACCu    /* 06FACC */
#define gorilla_animations_18_sprites_ADDRESS 0x7ADCu    /* 06FADC */
#define gorilla_animations_18_sprites_2_ADDRESS 0x7AF4u    /* 06FAF4 */
#define gorilla_animations_18_sprites_3_ADDRESS 0x7B0Cu    /* 06FB0C */
#define gorilla_animations_19_ADDRESS 0x7B24u    /* 06FB24 */
#define gorilla_animations_19_sprites_ADDRESS 0x7B30u    /* 06FB30 */
#define gorilla_animations_19_sprites_fill_ADDRESS 0x7B48u    /* 06FB48 */
#define gorilla_animations_19_sprites_rest_ADDRESS 0x7C3Eu    /* 06FC3E */
#define gorilla_animations_19_sprites_rest_2_ADDRESS 0x7C5Au    /* 06FC5A */
#define gorilla_animations_19_sprites_rest_3_ADDRESS 0x7C78u    /* 06FC78 */
#define gorilla_animations_19_sprites_rest_4_ADDRESS 0x7C96u    /* 06FC96 */
#define gorilla_animations_19_sprites_rest_5_ADDRESS 0x7CB4u    /* 06FCB4 */
#define gorilla_animations_19_sprites_rest_6_ADDRESS 0x7CD2u    /* 06FCD2 */
#define gorilla_animations_19_sprites_rest_7_ADDRESS 0x7CF0u    /* 06FCF0 */
#define gorilla_animations_19_sprites_rest_8_ADDRESS 0x7D0Eu    /* 06FD0E */
#define gorilla_animations_19_sprites_rest_9_ADDRESS 0x7D16u    /* 06FD16 */
#define gorilla_animations_19_sprites_fill_2_ADDRESS 0x7D34u    /* 06FD34 */
#define gorilla_animations_19_sprites_rest_10_ADDRESS 0x7D38u    /* 06FD38 */
#define gorilla_animations_19_sprites_rest_11_ADDRESS 0x7D4Cu    /* 06FD4C */
#define gorilla_animations_19_sprites_rest_12_ADDRESS 0x7D5Eu    /* 06FD5E */
#define gorilla_animations_19_sprites_rest_13_ADDRESS 0x7D76u    /* 06FD76 */
#define gorilla_animations_19_sprites_rest_14_ADDRESS 0x7D8Eu    /* 06FD8E */
#define gorilla_animations_19_sprites_rest_15_ADDRESS 0x7DACu    /* 06FDAC */
#define gorilla_animations_19_sprites_rest_16_ADDRESS 0x7DC0u    /* 06FDC0 */
#define gorilla_animations_19_sprites_rest_17_ADDRESS 0x7DD2u    /* 06FDD2 */
#define gorilla_animations_19_sprites_rest_18_ADDRESS 0x7DE4u    /* 06FDE4 */
#define gorilla_animations_19_sprites_rest_19_ADDRESS 0x7DF6u    /* 06FDF6 */
#define gorilla_animations_19_sprites_fill_3_ADDRESS 0x7E08u    /* 06FE08 */
#define gorilla_animations_19_sprites_rest_20_ADDRESS 0x7E74u    /* 06FE74 */
#define gorilla_animations_19_sprites_rest_21_ADDRESS 0x7E84u    /* 06FE84 */
#define gorilla_animations_19_sprites_rest_22_ADDRESS 0x7E96u    /* 06FE96 */
#define gorilla_animations_19_sprites_rest_23_ADDRESS 0x7EBAu    /* 06FEBA */
#define gorilla_animations_19_sprites_fill_4_ADDRESS 0x7EE4u    /* 06FEE4 */
#define gorilla_animations_19_sprites_rest_24_ADDRESS 0x6000u    /* 070000 */
#define kid_in_sunglasses_animations_ADDRESS 0x6012u    /* 070012 */
#define kid_in_sunglasses_animations_0_ADDRESS 0x601Cu    /* 07001C */
#define kid_in_sunglasses_animations_1_ADDRESS 0x6024u    /* 070024 */
#define kid_in_sunglasses_animations_1_sprites_ADDRESS 0x6038u    /* 070038 */
#define kid_in_sunglasses_animations_0_sprites_ADDRESS 0x6044u    /* 070044 */
#define kid_in_sunglasses_animations_1_sprites_2_ADDRESS 0x6050u    /* 070050 */
#define kid_in_sunglasses_animations_1_sprites_3_ADDRESS 0x605Cu    /* 07005C */
#define kid_in_sunglasses_animations_2_ADDRESS 0x6068u    /* 070068 */
#define kid_in_sunglasses_animations_2_sprites_ADDRESS 0x607Cu    /* 07007C */
#define kid_in_sunglasses_animations_2_sprites_2_ADDRESS 0x6088u    /* 070088 */
#define kid_in_sunglasses_animations_2_sprites_3_ADDRESS 0x6094u    /* 070094 */
#define kid_in_sunglasses_animations_2_sprites_4_ADDRESS 0x60A0u    /* 0700A0 */
#define kid_in_sunglasses_animations_3_ADDRESS 0x60ACu    /* 0700AC */
#define kid_in_sunglasses_animations_3_sprites_ADDRESS 0x60B8u    /* 0700B8 */
#define kid_in_sunglasses_animations_3_sprites_2_ADDRESS 0x60CAu    /* 0700CA */
#define kid_in_sunglasses_animations_4_ADDRESS 0x60DCu    /* 0700DC */
#define kid_in_sunglasses_animations_4_sprites_ADDRESS 0x60E4u    /* 0700E4 */
#define wrestler_animations_2_ADDRESS 0x60F6u    /* 0700F6 */
#define wrestler_animations_2_0_ADDRESS 0x6116u    /* 070116 */
#define wrestler_animations_2_0_sprites_ADDRESS 0x6142u    /* 070142 */
#define wrestler_animations_2_0_sprites_2_ADDRESS 0x615Au    /* 07015A */
#define wrestler_animations_2_0_sprites_3_ADDRESS 0x617Eu    /* 07017E */
#define wrestler_animations_2_0_sprites_4_ADDRESS 0x61B4u    /* 0701B4 */
#define wrestler_animations_2_0_sprites_5_ADDRESS 0x61D8u    /* 0701D8 */
#define wrestler_animations_2_0_sprites_6_ADDRESS 0x6202u    /* 070202 */
#define wrestler_animations_2_0_sprites_7_ADDRESS 0x6226u    /* 070226 */
#define wrestler_animations_2_0_sprites_8_ADDRESS 0x6256u    /* 070256 */
#define wrestler_animations_2_0_sprites_9_ADDRESS 0x6286u    /* 070286 */
#define wrestler_animations_2_0_sprites_10_ADDRESS 0x62AAu    /* 0702AA */
#define wrestler_animations_2_1_ADDRESS 0x62CEu    /* 0702CE */
#define wrestler_animations_2_1_sprites_ADDRESS 0x62DEu    /* 0702DE */
#define wrestler_animations_2_1_sprites_2_ADDRESS 0x632Cu    /* 07032C */
#define wrestler_animations_2_2_ADDRESS 0x635Cu    /* 07035C */
#define wrestler_animations_2_2_sprites_ADDRESS 0x6378u    /* 070378 */
#define wrestler_animations_2_2_sprites_2_ADDRESS 0x639Cu    /* 07039C */
#define wrestler_animations_2_2_sprites_3_ADDRESS 0x63BAu    /* 0703BA */
#define wrestler_animations_2_2_sprites_4_ADDRESS 0x63DEu    /* 0703DE */
#define wrestler_animations_2_2_sprites_5_ADDRESS 0x6402u    /* 070402 */
#define wrestler_animations_2_2_sprites_6_ADDRESS 0x6420u    /* 070420 */
#define wrestler_animations_2_3_ADDRESS 0x6438u    /* 070438 */
#define wrestler_animations_2_3_sprites_ADDRESS 0x6448u    /* 070448 */
#define wrestler_animations_2_3_sprites_2_ADDRESS 0x6472u    /* 070472 */
#define wrestler_animations_2_3_sprites_3_ADDRESS 0x6496u    /* 070496 */
#define wrestler_animations_2_4_ADDRESS 0x64AEu    /* 0704AE */
#define wrestler_animations_2_4_sprites_ADDRESS 0x64BAu    /* 0704BA */
#define wrestler_animations_2_4_sprites_2_ADDRESS 0x64D8u    /* 0704D8 */
#define wrestler_animations_2_5_ADDRESS 0x64F6u    /* 0704F6 */
#define wrestler_animations_2_5_sprites_ADDRESS 0x6502u    /* 070502 */
#define wrestler_animations_2_5_sprites_2_ADDRESS 0x6526u    /* 070526 */
#define wrestler_animations_2_6_ADDRESS 0x6544u    /* 070544 */
#define wrestler_animations_2_6_sprites_ADDRESS 0x6550u    /* 070550 */
#define wrestler_animations_2_6_sprites_2_ADDRESS 0x6574u    /* 070574 */
#define wrestler_animations_2_7_ADDRESS 0x6598u    /* 070598 */
#define wrestler_animations_2_7_sprites_ADDRESS 0x65ACu    /* 0705AC */
#define wrestler_animations_2_7_sprites_2_ADDRESS 0x65C4u    /* 0705C4 */
#define wrestler_animations_2_7_sprites_3_ADDRESS 0x65D6u    /* 0705D6 */
#define wrestler_animations_2_8_ADDRESS 0x65EEu    /* 0705EE */
#define wrestler_animations_2_8_sprites_ADDRESS 0x65FAu    /* 0705FA */
#define wrestler_animations_2_8_sprites_2_ADDRESS 0x6618u    /* 070618 */
#define wrestler_animations_2_9_ADDRESS 0x663Cu    /* 07063C */
#define wrestler_animations_2_9_sprites_ADDRESS 0x6644u    /* 070644 */
#define wrestler_animations_2_10_ADDRESS 0x6680u    /* 070680 */
#define wrestler_animations_2_10_sprites_ADDRESS 0x6694u    /* 070694 */
#define wrestler_animations_2_10_sprites_2_ADDRESS 0x66DCu    /* 0706DC */
#define wrestler_animations_2_10_sprites_3_ADDRESS 0x671Eu    /* 07071E */
#define wrestler_animations_2_11_ADDRESS 0x6760u    /* 070760 */
#define wrestler_animations_2_11_sprites_ADDRESS 0x676Cu    /* 07076C */
#define wrestler_animations_2_11_sprites_2_ADDRESS 0x678Au    /* 07078A */
#define wrestler_animations_2_12_ADDRESS 0x67AEu    /* 0707AE */
#define wrestler_animations_2_12_sprites_ADDRESS 0x67BAu    /* 0707BA */
#define wrestler_animations_2_13_ADDRESS 0x67D8u    /* 0707D8 */
#define wrestler_animations_2_13_sprites_ADDRESS 0x67E4u    /* 0707E4 */
#define wrestler_animations_2_13_sprites_2_ADDRESS 0x6826u    /* 070826 */
#define wrestler_animations_2_14_ADDRESS 0x6868u    /* 070868 */
#define wrestler_animations_2_14_sprites_ADDRESS 0x6874u    /* 070874 */
#define wrestler_animations_2_15_ADDRESS 0x68B6u    /* 0708B6 */
#define wrestler_animations_2_15_sprites_ADDRESS 0x68C2u    /* 0708C2 */
#define wrestler_animations_2_15_sprites_2_ADDRESS 0x6904u    /* 070904 */
#define rabbit_animations_ADDRESS 0x6952u    /* 070952 */
#define rabbit_animations_0_ADDRESS 0x6958u    /* 070958 */
#define rabbit_animations_0_sprites_ADDRESS 0x6964u    /* 070964 */
#define rabbit_animations_0_sprites_2_ADDRESS 0x6976u    /* 070976 */
#define rabbit_animations_1_ADDRESS 0x698Eu    /* 07098E */
#define rabbit_animations_1_sprites_ADDRESS 0x69A2u    /* 0709A2 */
#define rabbit_animations_1_sprites_2_ADDRESS 0x69B4u    /* 0709B4 */
#define rabbit_animations_1_sprites_3_ADDRESS 0x69D2u    /* 0709D2 */
#define rabbit_animations_2_ADDRESS 0x69F0u    /* 0709F0 */
#define rabbit_animations_2_sprites_ADDRESS 0x69FCu    /* 0709FC */
#define clown_on_ball_animations_ADDRESS 0x6A0Eu    /* 070A0E */
#define clown_on_ball_animations_0_ADDRESS 0x6A3Au    /* 070A3A */
#define clown_on_ball_animations_0_sprites_ADDRESS 0x6A42u    /* 070A42 */
#define clown_on_ball_animations_1_ADDRESS 0x6A54u    /* 070A54 */
#define clown_on_ball_animations_1_sprites_ADDRESS 0x6A78u    /* 070A78 */
#define clown_on_ball_animations_1_sprites_2_ADDRESS 0x6A8Au    /* 070A8A */
#define clown_on_ball_animations_1_sprites_3_ADDRESS 0x6A96u    /* 070A96 */
#define clown_on_ball_animations_1_sprites_4_ADDRESS 0x6AA2u    /* 070AA2 */
#define clown_on_ball_animations_1_sprites_5_ADDRESS 0x6ABAu    /* 070ABA */
#define clown_on_ball_animations_1_sprites_6_ADDRESS 0x6ACCu    /* 070ACC */
#define clown_on_ball_animations_1_sprites_7_ADDRESS 0x6AD8u    /* 070AD8 */
#define clown_on_ball_animations_1_sprites_8_ADDRESS 0x6AF0u    /* 070AF0 */
#define clown_on_ball_animations_6_ADDRESS 0x6B08u    /* 070B08 */
#define clown_on_ball_animations_6_sprites_ADDRESS 0x6B14u    /* 070B14 */
#define clown_on_ball_animations_6_sprites_2_ADDRESS 0x6B26u    /* 070B26 */
#define clown_on_ball_animations_9_ADDRESS 0x6B38u    /* 070B38 */
#define clown_on_ball_animations_9_sprites_ADDRESS 0x6B58u    /* 070B58 */
#define clown_on_ball_animations_9_sprites_2_ADDRESS 0x6B70u    /* 070B70 */
#define clown_on_ball_animations_9_sprites_3_ADDRESS 0x6B82u    /* 070B82 */
#define clown_on_ball_animations_9_sprites_4_ADDRESS 0x6B9Au    /* 070B9A */
#define clown_on_ball_animations_20_ADDRESS 0x6BA6u    /* 070BA6 */
#define clown_on_ball_animations_20_sprites_ADDRESS 0x6BC6u    /* 070BC6 */
#define clown_on_ball_animations_20_sprites_2_ADDRESS 0x6BDEu    /* 070BDE */
#define clown_on_ball_animations_18_ADDRESS 0x6BF0u    /* 070BF0 */
#define clown_on_ball_animations_18_sprites_ADDRESS 0x6C28u    /* 070C28 */
#define clown_on_ball_animations_18_sprites_2_ADDRESS 0x6C40u    /* 070C40 */
#define clown_on_ball_animations_18_sprites_3_ADDRESS 0x6C52u    /* 070C52 */
#define clown_on_ball_animations_18_sprites_4_ADDRESS 0x6C64u    /* 070C64 */
#define clown_on_ball_animations_18_sprites_5_ADDRESS 0x6C76u    /* 070C76 */
#define clown_on_ball_animations_18_sprites_6_ADDRESS 0x6C8Eu    /* 070C8E */
#define clown_on_ball_animations_18_sprites_7_ADDRESS 0x6CA6u    /* 070CA6 */
#define clown_on_ball_animations_18_sprites_8_ADDRESS 0x6CB8u    /* 070CB8 */
#define clown_on_ball_animations_18_sprites_9_ADDRESS 0x6CD0u    /* 070CD0 */
#define clown_on_ball_animations_18_sprites_10_ADDRESS 0x6CE8u    /* 070CE8 */
#define clown_on_ball_animations_18_sprites_11_ADDRESS 0x6D00u    /* 070D00 */
#define clown_on_ball_animations_18_sprites_12_ADDRESS 0x6D12u    /* 070D12 */
#define clown_on_ball_animations_18_sprites_13_ADDRESS 0x6D2Au    /* 070D2A */
#define clown_on_ball_animations_17_ADDRESS 0x6D42u    /* 070D42 */
#define clown_on_ball_animations_17_sprites_ADDRESS 0x6D4Au    /* 070D4A */
#define clown_on_ball_animations_7_ADDRESS 0x6D50u    /* 070D50 */
#define clown_on_ball_animations_16_ADDRESS 0x6D68u    /* 070D68 */
#define clown_on_ball_animations_16_sprites_ADDRESS 0x6DB0u    /* 070DB0 */
#define clown_on_ball_animations_19_ADDRESS 0x6DCEu    /* 070DCE */
#define clown_on_ball_animations_19_sprites_ADDRESS 0x6DFEu    /* 070DFE */
#define clown_on_ball_animations_19_sprites_2_ADDRESS 0x6E10u    /* 070E10 */
#define clown_on_ball_animations_19_sprites_3_ADDRESS 0x6E28u    /* 070E28 */
#define clown_on_ball_animations_19_sprites_4_ADDRESS 0x6E40u    /* 070E40 */
#define clown_on_ball_animations_19_sprites_5_ADDRESS 0x6E58u    /* 070E58 */
#define clown_on_ball_animations_19_sprites_6_ADDRESS 0x6E6Au    /* 070E6A */
#define clown_on_ball_animations_19_sprites_7_ADDRESS 0x6E82u    /* 070E82 */
#define clown_on_ball_animations_19_sprites_8_ADDRESS 0x6E9Au    /* 070E9A */
#define clown_on_ball_animations_8_ADDRESS 0x6EB2u    /* 070EB2 */
#define clown_on_ball_animations_8_sprites_ADDRESS 0x6EE2u    /* 070EE2 */
#define clown_on_ball_animations_8_sprites_2_ADDRESS 0x6EFAu    /* 070EFA */
#define clown_on_ball_animations_8_sprites_3_ADDRESS 0x6F0Cu    /* 070F0C */
#define clown_on_ball_animations_8_sprites_4_ADDRESS 0x6F1Eu    /* 070F1E */
#define clown_on_ball_animations_21_ADDRESS 0x6F30u    /* 070F30 */
#define clown_on_ball_animations_21_sprites_ADDRESS 0x6F38u    /* 070F38 */
#define grabbing_zombie_animations_ADDRESS 0x6F44u    /* 070F44 */
#define grabbing_zombie_animations_16_ADDRESS 0x6F70u    /* 070F70 */
#define grabbing_zombie_animations_16_sprites_ADDRESS 0x6F7Cu    /* 070F7C */
#define grabbing_zombie_animations_16_sprites_2_ADDRESS 0x6F88u    /* 070F88 */
#define grabbing_zombie_animations_17_ADDRESS 0x6F8Eu    /* 070F8E */
#define grabbing_zombie_animations_17_sprites_ADDRESS 0x6FAAu    /* 070FAA */
#define grabbing_zombie_animations_17_sprites_2_ADDRESS 0x6FB0u    /* 070FB0 */
#define grabbing_zombie_animations_17_sprites_3_ADDRESS 0x6FC2u    /* 070FC2 */
#define grabbing_zombie_animations_17_sprites_4_ADDRESS 0x6FC8u    /* 070FC8 */
#define grabbing_zombie_animations_17_sprites_5_ADDRESS 0x6FCEu    /* 070FCE */
#define grabbing_zombie_animations_17_sprites_6_ADDRESS 0x6FD4u    /* 070FD4 */
#define grabbing_zombie_animations_0_ADDRESS 0x6FE6u    /* 070FE6 */
#define grabbing_zombie_animations_0_sprites_ADDRESS 0x700Au    /* 07100A */
#define grabbing_zombie_animations_0_sprites_2_ADDRESS 0x701Cu    /* 07101C */
#define grabbing_zombie_animations_0_sprites_3_ADDRESS 0x702Eu    /* 07102E */
#define grabbing_zombie_animations_0_sprites_4_ADDRESS 0x7046u    /* 071046 */
#define grabbing_zombie_animations_0_sprites_5_ADDRESS 0x7064u    /* 071064 */
#define grabbing_zombie_animations_0_sprites_6_ADDRESS 0x7076u    /* 071076 */
#define grabbing_zombie_animations_0_sprites_7_ADDRESS 0x7088u    /* 071088 */
#define grabbing_zombie_animations_0_sprites_8_ADDRESS 0x70A0u    /* 0710A0 */
#define grabbing_zombie_animations_20_ADDRESS 0x70BEu    /* 0710BE */
#define grabbing_zombie_animations_20_sprites_ADDRESS 0x70DAu    /* 0710DA */
#define grabbing_zombie_animations_20_sprites_2_ADDRESS 0x70FEu    /* 0710FE */
#define grabbing_zombie_animations_20_sprites_3_ADDRESS 0x711Cu    /* 07111C */
#define grabbing_zombie_animations_20_sprites_4_ADDRESS 0x7134u    /* 071134 */
#define grabbing_zombie_animations_20_sprites_5_ADDRESS 0x7152u    /* 071152 */
#define grabbing_zombie_animations_20_sprites_6_ADDRESS 0x7170u    /* 071170 */
#define grabbing_zombie_animations_19_ADDRESS 0x718Eu    /* 07118E */
#define grabbing_zombie_animations_19_sprites_ADDRESS 0x71AAu    /* 0711AA */
#define grabbing_zombie_animations_19_sprites_2_ADDRESS 0x71C8u    /* 0711C8 */
#define grabbing_zombie_animations_19_sprites_3_ADDRESS 0x71E6u    /* 0711E6 */
#define grabbing_zombie_animations_19_sprites_4_ADDRESS 0x720Au    /* 07120A */
#define grabbing_zombie_animations_19_sprites_5_ADDRESS 0x7234u    /* 071234 */
#define grabbing_zombie_animations_19_sprites_6_ADDRESS 0x7258u    /* 071258 */
#define grabbing_zombie_animations_21_ADDRESS 0x7282u    /* 071282 */
#define grabbing_zombie_animations_21_sprites_ADDRESS 0x729Eu    /* 07129E */
#define grabbing_zombie_animations_21_sprites_2_ADDRESS 0x72C2u    /* 0712C2 */
#define grabbing_zombie_animations_21_sprites_3_ADDRESS 0x72E0u    /* 0712E0 */
#define grabbing_zombie_animations_21_sprites_4_ADDRESS 0x7304u    /* 071304 */
#define grabbing_zombie_animations_21_sprites_5_ADDRESS 0x7328u    /* 071328 */
#define grabbing_zombie_animations_21_sprites_6_ADDRESS 0x734Cu    /* 07134C */
#define grabbing_zombie_animations_18_ADDRESS 0x7370u    /* 071370 */
#define grabbing_zombie_animations_18_sprites_ADDRESS 0x738Cu    /* 07138C */
#define grabbing_zombie_animations_18_sprites_2_ADDRESS 0x73B0u    /* 0713B0 */
#define grabbing_zombie_animations_18_sprites_3_ADDRESS 0x73D4u    /* 0713D4 */
#define grabbing_zombie_animations_18_sprites_4_ADDRESS 0x73FEu    /* 0713FE */
#define grabbing_zombie_animations_18_sprites_5_ADDRESS 0x742Eu    /* 07142E */
#define grabbing_zombie_animations_18_sprites_6_ADDRESS 0x745Eu    /* 07145E */
#define grabbing_zombie_animations_9_ADDRESS 0x7488u    /* 071488 */
#define grabbing_zombie_animations_9_sprites_ADDRESS 0x7494u    /* 071494 */
#define grabbing_zombie_animations_9_sprites_2_ADDRESS 0x74A6u    /* 0714A6 */
#define grabbing_zombie_animations_8_ADDRESS 0x74B8u    /* 0714B8 */
#define grabbing_zombie_animations_8_sprites_ADDRESS 0x74E8u    /* 0714E8 */
#define grabbing_zombie_animations_8_sprites_2_ADDRESS 0x7500u    /* 071500 */
#define grabbing_zombie_animations_8_sprites_3_ADDRESS 0x751Eu    /* 07151E */
#define grabbing_zombie_animations_8_sprites_4_ADDRESS 0x752Au    /* 07152A */
#define grabbing_zombie_animations_8_sprites_5_ADDRESS 0x753Cu    /* 07153C */
#define grabbing_zombie_animations_8_sprites_6_ADDRESS 0x7554u    /* 071554 */
#define grabbing_zombie_animations_8_sprites_7_ADDRESS 0x7560u    /* 071560 */
#define grabbing_zombie_animations_8_sprites_8_ADDRESS 0x756Cu    /* 07156C */
#define grabbing_zombie_animations_8_sprites_9_ADDRESS 0x7578u    /* 071578 */
#define grabbing_zombie_animations_8_sprites_10_ADDRESS 0x7584u    /* 071584 */
#define grabbing_zombie_animations_8_sprites_11_ADDRESS 0x7590u    /* 071590 */
#define one_eared_rabbit_animations_ADDRESS 0x759Cu    /* 07159C */
#define one_eared_rabbit_animations_0_ADDRESS 0x75C0u    /* 0715C0 */
#define one_eared_rabbit_animations_0_sprites_ADDRESS 0x75CCu    /* 0715CC */
#define one_eared_rabbit_animations_0_sprites_2_ADDRESS 0x75DEu    /* 0715DE */
#define one_eared_rabbit_animations_1_ADDRESS 0x75F6u    /* 0715F6 */
#define one_eared_rabbit_animations_1_sprites_ADDRESS 0x760Au    /* 07160A */
#define one_eared_rabbit_animations_1_sprites_2_ADDRESS 0x7622u    /* 071622 */
#define one_eared_rabbit_animations_1_sprites_3_ADDRESS 0x763Au    /* 07163A */
#define one_eared_rabbit_animations_6_ADDRESS 0x7652u    /* 071652 */
#define one_eared_rabbit_animations_6_sprites_ADDRESS 0x765Eu    /* 07165E */
#define one_eared_rabbit_animations_6_sprites_2_ADDRESS 0x767Cu    /* 07167C */
#define one_eared_rabbit_animations_16_ADDRESS 0x769Au    /* 07169A */
#define one_eared_rabbit_animations_16_sprites_ADDRESS 0x76B2u    /* 0716B2 */
#define one_eared_rabbit_animations_16_sprites_2_ADDRESS 0x76C4u    /* 0716C4 */
#define one_eared_rabbit_animations_16_sprites_3_ADDRESS 0x76DCu    /* 0716DC */
#define one_eared_rabbit_animations_16_sprites_4_ADDRESS 0x76E8u    /* 0716E8 */
#define one_eared_rabbit_animations_8_ADDRESS 0x7700u    /* 071700 */
#define one_eared_rabbit_animations_8_sprites_ADDRESS 0x7718u    /* 071718 */
#define one_eared_rabbit_animations_8_sprites_2_ADDRESS 0x7736u    /* 071736 */
#define one_eared_rabbit_animations_8_sprites_3_ADDRESS 0x7754u    /* 071754 */
#define one_eared_rabbit_animations_8_sprites_4_ADDRESS 0x7772u    /* 071772 */
#define one_eared_rabbit_animations_8_sprites_5_ADDRESS 0x778Au    /* 07178A */
#define one_eared_rabbit_animations_7_ADDRESS 0x77A2u    /* 0717A2 */
#define one_eared_rabbit_animations_7_sprites_ADDRESS 0x77B2u    /* 0717B2 */
#define one_eared_rabbit_animations_9_ADDRESS 0x77D0u    /* 0717D0 */
#define one_eared_rabbit_animations_9_sprites_ADDRESS 0x77ECu    /* 0717EC */
#define one_eared_rabbit_animations_9_sprites_2_ADDRESS 0x77FEu    /* 0717FE */
#define one_eared_rabbit_animations_9_sprites_3_ADDRESS 0x7810u    /* 071810 */
#define one_eared_rabbit_animations_9_sprites_4_ADDRESS 0x7828u    /* 071828 */
#define clown_on_ball_2_animations_ADDRESS 0x7840u    /* 071840 */
#define clown_on_ball_2_animations_0_ADDRESS 0x7866u    /* 071866 */
#define clown_on_ball_2_animations_0_sprites_ADDRESS 0x786Eu    /* 07186E */
#define clown_on_ball_2_animations_1_ADDRESS 0x7880u    /* 071880 */
#define clown_on_ball_2_animations_1_sprites_ADDRESS 0x78A4u    /* 0718A4 */
#define clown_on_ball_2_animations_1_sprites_2_ADDRESS 0x78B6u    /* 0718B6 */
#define clown_on_ball_2_animations_1_sprites_3_ADDRESS 0x78C2u    /* 0718C2 */
#define clown_on_ball_2_animations_1_sprites_4_ADDRESS 0x78D4u    /* 0718D4 */
#define clown_on_ball_2_animations_1_sprites_5_ADDRESS 0x78ECu    /* 0718EC */
#define clown_on_ball_2_animations_1_sprites_6_ADDRESS 0x78FEu    /* 0718FE */
#define clown_on_ball_2_animations_1_sprites_7_ADDRESS 0x790Au    /* 07190A */
#define clown_on_ball_2_animations_1_sprites_8_ADDRESS 0x7922u    /* 071922 */
#define clown_on_ball_2_animations_6_ADDRESS 0x793Au    /* 07193A */
#define clown_on_ball_2_animations_6_sprites_ADDRESS 0x7946u    /* 071946 */
#define clown_on_ball_2_animations_6_sprites_2_ADDRESS 0x7958u    /* 071958 */
#define clown_on_ball_2_animations_9_ADDRESS 0x796Au    /* 07196A */
#define clown_on_ball_2_animations_9_sprites_ADDRESS 0x798Au    /* 07198A */
#define clown_on_ball_2_animations_9_sprites_2_ADDRESS 0x79A2u    /* 0719A2 */
#define clown_on_ball_2_animations_9_sprites_3_ADDRESS 0x79BAu    /* 0719BA */
#define clown_on_ball_2_animations_9_sprites_4_ADDRESS 0x79D2u    /* 0719D2 */
#define clown_on_ball_2_animations_8_ADDRESS 0x79DEu    /* 0719DE */
#define clown_on_ball_2_animations_8_sprites_ADDRESS 0x7A16u    /* 071A16 */
#define clown_on_ball_2_animations_8_sprites_2_ADDRESS 0x7A2Eu    /* 071A2E */
#define clown_on_ball_2_animations_8_sprites_3_ADDRESS 0x7A40u    /* 071A40 */
#define clown_on_ball_2_animations_8_sprites_4_ADDRESS 0x7A52u    /* 071A52 */
#define clown_on_ball_2_animations_18_ADDRESS 0x7A64u    /* 071A64 */
#define clown_on_ball_2_animations_18_sprites_ADDRESS 0x7A9Cu    /* 071A9C */
#define clown_on_ball_2_animations_18_sprites_2_ADDRESS 0x7AB4u    /* 071AB4 */
#define clown_on_ball_2_animations_18_sprites_3_ADDRESS 0x7AC6u    /* 071AC6 */
#define clown_on_ball_2_animations_18_sprites_4_ADDRESS 0x7AD8u    /* 071AD8 */
#define clown_on_ball_2_animations_18_sprites_5_ADDRESS 0x7AEAu    /* 071AEA */
#define clown_on_ball_2_animations_18_sprites_6_ADDRESS 0x7AFCu    /* 071AFC */
#define clown_on_ball_2_animations_18_sprites_7_ADDRESS 0x7B0Eu    /* 071B0E */
#define clown_on_ball_2_animations_18_sprites_8_ADDRESS 0x7B26u    /* 071B26 */
#define clown_on_ball_2_animations_18_sprites_9_ADDRESS 0x7B38u    /* 071B38 */
#define clown_on_ball_2_animations_18_sprites_10_ADDRESS 0x7B50u    /* 071B50 */
#define clown_on_ball_2_animations_18_sprites_11_ADDRESS 0x7B6Eu    /* 071B6E */
#define clown_on_ball_2_animations_18_sprites_12_ADDRESS 0x7B86u    /* 071B86 */
#define clown_on_ball_2_animations_18_sprites_13_ADDRESS 0x7BA4u    /* 071BA4 */
#define clown_on_ball_2_animations_7_ADDRESS 0x7BBCu    /* 071BBC */
#define clown_on_ball_2_animations_16_ADDRESS 0x7BD4u    /* 071BD4 */
#define clown_on_ball_2_animations_16_sprites_ADDRESS 0x7C1Cu    /* 071C1C */
#define ghost_on_rope_animations_ADDRESS 0x7C3Au    /* 071C3A */
#define ghost_on_rope_animations_0_ADDRESS 0x7C3Eu    /* 071C3E */
#define ghost_on_rope_animations_0_sprites_ADDRESS 0x7C5Au    /* 071C5A */
#define ghost_on_rope_animations_0_sprites_2_ADDRESS 0x7C78u    /* 071C78 */
#define ghost_on_rope_animations_0_sprites_3_ADDRESS 0x7C96u    /* 071C96 */
#define ghost_on_rope_animations_0_sprites_4_ADDRESS 0x7CB4u    /* 071CB4 */
#define ghost_on_rope_animations_0_sprites_5_ADDRESS 0x7CD2u    /* 071CD2 */
#define ghost_on_rope_animations_0_sprites_6_ADDRESS 0x7CF0u    /* 071CF0 */
#define ghost_on_rope_animations_1_ADDRESS 0x7D0Eu    /* 071D0E */
#define ghost_on_rope_animations_1_sprites_ADDRESS 0x7D16u    /* 071D16 */
#define ghost_animations_ADDRESS 0x7D34u    /* 071D34 */
#define ghost_animations_0_ADDRESS 0x7D38u    /* 071D38 */
#define ghost_animations_0_sprites_ADDRESS 0x7D4Cu    /* 071D4C */
#define ghost_animations_0_sprites_2_ADDRESS 0x7D5Eu    /* 071D5E */
#define ghost_animations_0_sprites_3_ADDRESS 0x7D76u    /* 071D76 */
#define ghost_animations_0_sprites_4_ADDRESS 0x7D8Eu    /* 071D8E */
#define ghost_animations_1_ADDRESS 0x7DACu    /* 071DAC */
#define ghost_animations_1_sprites_ADDRESS 0x7DC0u    /* 071DC0 */
#define ghost_animations_1_sprites_2_ADDRESS 0x7DD2u    /* 071DD2 */
#define ghost_animations_1_sprites_3_ADDRESS 0x7DE4u    /* 071DE4 */
#define ghost_animations_1_sprites_4_ADDRESS 0x7DF6u    /* 071DF6 */
#define ghost_animations_1_sprites_4_fill_ADDRESS 0x7E08u    /* 071E08 */
#define ghost_animations_1_sprites_4_rest_ADDRESS 0x7E74u    /* 071E74 */
#define ghost_animations_1_sprites_4_rest_2_ADDRESS 0x7E84u    /* 071E84 */
#define ghost_animations_1_sprites_4_rest_3_ADDRESS 0x7E96u    /* 071E96 */
#define ghost_animations_1_sprites_4_rest_4_ADDRESS 0x7EBAu    /* 071EBA */
#define ghost_animations_1_sprites_4_fill_2_ADDRESS 0x7EE4u    /* 071EE4 */
#define ghost_animations_1_sprites_4_rest_5_ADDRESS 0x6000u    /* 072000 */
#define woman_in_green_animations_ADDRESS 0x6010u    /* 072010 */
#define woman_in_green_animations_0_ADDRESS 0x601Au    /* 07201A */
#define woman_in_green_animations_0_sprites_ADDRESS 0x6022u    /* 072022 */
#define woman_in_green_animations_1_ADDRESS 0x6034u    /* 072034 */
#define woman_in_green_animations_1_sprites_ADDRESS 0x6048u    /* 072048 */
#define woman_in_green_animations_1_sprites_2_ADDRESS 0x6060u    /* 072060 */
#define woman_in_green_animations_1_sprites_3_ADDRESS 0x6072u    /* 072072 */
#define woman_in_green_animations_1_sprites_4_ADDRESS 0x608Au    /* 07208A */
#define woman_in_green_animations_2_ADDRESS 0x609Cu    /* 07209C */
#define woman_in_green_animations_2_sprites_ADDRESS 0x60B0u    /* 0720B0 */
#define woman_in_green_animations_2_sprites_2_ADDRESS 0x60C2u    /* 0720C2 */
#define woman_in_green_animations_2_sprites_3_ADDRESS 0x60D4u    /* 0720D4 */
#define woman_in_green_animations_3_ADDRESS 0x60E6u    /* 0720E6 */
#define woman_in_green_animations_3_sprites_ADDRESS 0x60FAu    /* 0720FA */
#define woman_in_green_animations_3_sprites_2_ADDRESS 0x610Cu    /* 07210C */
#define woman_in_green_animations_3_sprites_3_ADDRESS 0x6124u    /* 072124 */
#define woman_in_green_animations_3_sprites_4_ADDRESS 0x613Cu    /* 07213C */
#define woman_in_green_animations_4_ADDRESS 0x6154u    /* 072154 */
#define woman_in_green_animations_4_sprites_ADDRESS 0x6164u    /* 072164 */
#define woman_in_green_animations_4_sprites_2_ADDRESS 0x617Cu    /* 07217C */
#define bird_animations_ADDRESS 0x618Eu    /* 07218E */
#define bird_animations_0_ADDRESS 0x6192u    /* 072192 */
#define bird_animations_0_sprites_ADDRESS 0x61A6u    /* 0721A6 */
#define bird_animations_0_sprites_2_ADDRESS 0x61ACu    /* 0721AC */
#define bird_animations_0_sprites_3_ADDRESS 0x61B2u    /* 0721B2 */
#define bird_animations_1_ADDRESS 0x61B8u    /* 0721B8 */
#define bird_animations_1_sprites_ADDRESS 0x61CCu    /* 0721CC */
#define bird_animations_1_sprites_2_ADDRESS 0x61D2u    /* 0721D2 */
#define bird_animations_1_sprites_3_ADDRESS 0x61D8u    /* 0721D8 */
#define barney_animations_2_ADDRESS 0x61DEu    /* 0721DE */
#define barney_animations_2_0_ADDRESS 0x6204u    /* 072204 */
#define barney_animations_2_0_sprites_ADDRESS 0x620Cu    /* 07220C */
#define barney_animations_2_1_ADDRESS 0x621Eu    /* 07221E */
#define barney_animations_2_1_sprites_ADDRESS 0x6242u    /* 072242 */
#define barney_animations_2_1_sprites_2_ADDRESS 0x6254u    /* 072254 */
#define barney_animations_2_1_sprites_3_ADDRESS 0x6266u    /* 072266 */
#define barney_animations_2_1_sprites_4_ADDRESS 0x6278u    /* 072278 */
#define barney_animations_2_1_sprites_5_ADDRESS 0x628Au    /* 07228A */
#define barney_animations_2_1_sprites_6_ADDRESS 0x629Cu    /* 07229C */
#define barney_animations_2_1_sprites_7_ADDRESS 0x62AEu    /* 0722AE */
#define barney_animations_2_1_sprites_8_ADDRESS 0x62C0u    /* 0722C0 */
#define barney_animations_2_6_ADDRESS 0x62D2u    /* 0722D2 */
#define barney_animations_2_6_sprites_ADDRESS 0x62DEu    /* 0722DE */
#define barney_animations_2_16_ADDRESS 0x62F0u    /* 0722F0 */
#define barney_animations_2_16_sprites_ADDRESS 0x6304u    /* 072304 */
#define barney_animations_2_16_sprites_2_ADDRESS 0x6316u    /* 072316 */
#define barney_animations_2_16_sprites_3_ADDRESS 0x632Eu    /* 07232E */
#define barney_animations_2_16_sprites_4_ADDRESS 0x6346u    /* 072346 */
#define barney_animations_2_9_ADDRESS 0x635Eu    /* 07235E */
#define barney_animations_2_9_sprites_ADDRESS 0x636Eu    /* 07236E */
#define barney_animations_2_9_sprites_2_ADDRESS 0x6386u    /* 072386 */
#define barney_animations_2_9_sprites_3_ADDRESS 0x639Eu    /* 07239E */
#define barney_animations_2_17_ADDRESS 0x63B6u    /* 0723B6 */
#define barney_animations_2_17_sprites_ADDRESS 0x63CAu    /* 0723CA */
#define barney_animations_2_17_sprites_2_ADDRESS 0x63E2u    /* 0723E2 */
#define barney_animations_2_17_sprites_3_ADDRESS 0x63FAu    /* 0723FA */
#define barney_animations_2_17_sprites_4_ADDRESS 0x6412u    /* 072412 */
#define barney_animations_2_18_ADDRESS 0x6424u    /* 072424 */
#define barney_animations_2_18_sprites_ADDRESS 0x6438u    /* 072438 */
#define barney_animations_2_18_sprites_2_ADDRESS 0x645Cu    /* 07245C */
#define lumberjack_animations_ADDRESS 0x6474u    /* 072474 */
#define lumberjack_animations_0_ADDRESS 0x6496u    /* 072496 */
#define lumberjack_animations_0_sprites_ADDRESS 0x64BAu    /* 0724BA */
#define lumberjack_animations_0_sprites_2_ADDRESS 0x64D2u    /* 0724D2 */
#define lumberjack_animations_0_sprites_3_ADDRESS 0x64EAu    /* 0724EA */
#define lumberjack_animations_0_sprites_4_ADDRESS 0x6502u    /* 072502 */
#define lumberjack_animations_0_sprites_5_ADDRESS 0x651Au    /* 07251A */
#define lumberjack_animations_0_sprites_6_ADDRESS 0x6532u    /* 072532 */
#define lumberjack_animations_0_sprites_7_ADDRESS 0x654Au    /* 07254A */
#define lumberjack_animations_0_sprites_8_ADDRESS 0x6562u    /* 072562 */
#define lumberjack_animations_16_ADDRESS 0x657Au    /* 07257A */
#define lumberjack_animations_16_sprites_ADDRESS 0x659Eu    /* 07259E */
#define lumberjack_animations_16_sprites_2_ADDRESS 0x65B6u    /* 0725B6 */
#define lumberjack_animations_16_sprites_3_ADDRESS 0x65CEu    /* 0725CE */
#define lumberjack_animations_16_sprites_4_ADDRESS 0x65E6u    /* 0725E6 */
#define lumberjack_animations_16_sprites_5_ADDRESS 0x65FEu    /* 0725FE */
#define lumberjack_animations_16_sprites_6_ADDRESS 0x6616u    /* 072616 */
#define lumberjack_animations_6_ADDRESS 0x6628u    /* 072628 */
#define lumberjack_animations_6_sprites_ADDRESS 0x663Cu    /* 07263C */
#define lumberjack_animations_6_sprites_2_ADDRESS 0x6654u    /* 072654 */
#define lumberjack_animations_6_sprites_3_ADDRESS 0x666Cu    /* 07266C */
#define lumberjack_animations_6_sprites_4_ADDRESS 0x6684u    /* 072684 */
#define lumberjack_animations_9_ADDRESS 0x669Cu    /* 07269C */
#define lumberjack_animations_9_sprites_ADDRESS 0x66A8u    /* 0726A8 */
#define lumberjack_animations_9_sprites_2_ADDRESS 0x66B4u    /* 0726B4 */
#define lumberjack_animations_8_ADDRESS 0x66C6u    /* 0726C6 */
#define lumberjack_animations_8_sprites_ADDRESS 0x66E6u    /* 0726E6 */
#define lumberjack_animations_8_sprites_2_ADDRESS 0x66F8u    /* 0726F8 */
#define lumberjack_animations_8_sprites_3_ADDRESS 0x66FEu    /* 0726FE */
#define lumberjack_animations_8_sprites_4_ADDRESS 0x6704u    /* 072704 */
#define lumberjack_animations_8_sprites_5_ADDRESS 0x671Cu    /* 07271C */
#define lumberjack_animations_8_sprites_6_ADDRESS 0x672Eu    /* 07272E */
#define lumberjack_animations_8_sprites_7_ADDRESS 0x6740u    /* 072740 */
#define belly_dancer_animations_ADDRESS 0x6758u    /* 072758 */
#define belly_dancer_animations_0_ADDRESS 0x6762u    /* 072762 */
#define belly_dancer_animations_0_sprites_ADDRESS 0x676Au    /* 07276A */
#define belly_dancer_animations_1_ADDRESS 0x6782u    /* 072782 */
#define belly_dancer_animations_1_sprites_ADDRESS 0x67AEu    /* 0727AE */
#define belly_dancer_animations_1_sprites_2_ADDRESS 0x67C6u    /* 0727C6 */
#define belly_dancer_animations_1_sprites_3_ADDRESS 0x67DEu    /* 0727DE */
#define belly_dancer_animations_1_sprites_4_ADDRESS 0x67F6u    /* 0727F6 */
#define belly_dancer_animations_2_ADDRESS 0x680Eu    /* 07280E */
#define belly_dancer_animations_2_sprites_ADDRESS 0x6832u    /* 072832 */
#define belly_dancer_animations_2_sprites_2_ADDRESS 0x684Au    /* 07284A */
#define belly_dancer_animations_2_sprites_3_ADDRESS 0x6862u    /* 072862 */
#define belly_dancer_animations_2_sprites_4_ADDRESS 0x6874u    /* 072874 */
#define belly_dancer_animations_2_sprites_5_ADDRESS 0x6886u    /* 072886 */
#define belly_dancer_animations_2_sprites_6_ADDRESS 0x689Eu    /* 07289E */
#define belly_dancer_animations_2_sprites_7_ADDRESS 0x68B0u    /* 0728B0 */
#define belly_dancer_animations_2_sprites_8_ADDRESS 0x68C2u    /* 0728C2 */
#define belly_dancer_animations_3_ADDRESS 0x68DAu    /* 0728DA */
#define belly_dancer_animations_3_sprites_ADDRESS 0x68F6u    /* 0728F6 */
#define belly_dancer_animations_3_sprites_2_ADDRESS 0x6902u    /* 072902 */
#define belly_dancer_animations_3_sprites_3_ADDRESS 0x690Eu    /* 07290E */
#define belly_dancer_animations_3_sprites_4_ADDRESS 0x6920u    /* 072920 */
#define belly_dancer_animations_3_sprites_5_ADDRESS 0x6932u    /* 072932 */
#define belly_dancer_animations_3_sprites_6_ADDRESS 0x694Au    /* 07294A */
#define belly_dancer_animations_4_ADDRESS 0x6962u    /* 072962 */
#define belly_dancer_animations_4_sprites_ADDRESS 0x696Eu    /* 07296E */
#define belly_dancer_animations_4_sprites_2_ADDRESS 0x6980u    /* 072980 */
#define fireman_goon_animations_ADDRESS 0x6998u    /* 072998 */
#define fireman_goon_animations_0_ADDRESS 0x69C0u    /* 0729C0 */
#define fireman_goon_animations_0_sprites_ADDRESS 0x69C8u    /* 0729C8 */
#define fireman_goon_animations_1_ADDRESS 0x69D4u    /* 0729D4 */
#define fireman_goon_animations_1_sprites_ADDRESS 0x69F8u    /* 0729F8 */
#define fireman_goon_animations_1_sprites_2_ADDRESS 0x6A04u    /* 072A04 */
#define fireman_goon_animations_1_sprites_3_ADDRESS 0x6A10u    /* 072A10 */
#define fireman_goon_animations_1_sprites_4_ADDRESS 0x6A1Cu    /* 072A1C */
#define fireman_goon_animations_1_sprites_5_ADDRESS 0x6A34u    /* 072A34 */
#define fireman_goon_animations_1_sprites_6_ADDRESS 0x6A52u    /* 072A52 */
#define fireman_goon_animations_1_sprites_7_ADDRESS 0x6A6Au    /* 072A6A */
#define fireman_goon_animations_1_sprites_8_ADDRESS 0x6A82u    /* 072A82 */
#define fireman_goon_animations_6_ADDRESS 0x6A9Au    /* 072A9A */
#define fireman_goon_animations_6_sprites_ADDRESS 0x6AA6u    /* 072AA6 */
#define fireman_goon_animations_6_sprites_2_ADDRESS 0x6AB8u    /* 072AB8 */
#define fireman_goon_animations_9_ADDRESS 0x6ACAu    /* 072ACA */
#define fireman_goon_animations_9_sprites_ADDRESS 0x6AD6u    /* 072AD6 */
#define fireman_goon_animations_9_sprites_2_ADDRESS 0x6AE8u    /* 072AE8 */
#define fireman_goon_animations_8_ADDRESS 0x6B00u    /* 072B00 */
#define fireman_goon_animations_8_sprites_ADDRESS 0x6B14u    /* 072B14 */
#define fireman_goon_animations_8_sprites_2_ADDRESS 0x6B26u    /* 072B26 */
#define fireman_goon_animations_16_ADDRESS 0x6B38u    /* 072B38 */
#define fireman_goon_animations_16_sprites_ADDRESS 0x6B48u    /* 072B48 */
#define fireman_goon_animations_16_sprites_2_ADDRESS 0x6B66u    /* 072B66 */
#define fireman_goon_animations_16_sprites_3_ADDRESS 0x6B8Au    /* 072B8A */
#define fireman_goon_animations_17_ADDRESS 0x6BA2u    /* 072BA2 */
#define fireman_goon_animations_17_sprites_ADDRESS 0x6BD2u    /* 072BD2 */
#define fireman_goon_animations_17_sprites_2_ADDRESS 0x6BD8u    /* 072BD8 */
#define fireman_goon_animations_17_sprites_3_ADDRESS 0x6BEAu    /* 072BEA */
#define fireman_goon_animations_17_sprites_4_ADDRESS 0x6C02u    /* 072C02 */
#define fireman_goon_animations_17_sprites_5_ADDRESS 0x6C26u    /* 072C26 */
#define fireman_goon_animations_17_sprites_6_ADDRESS 0x6C4Au    /* 072C4A */
#define fireman_goon_animations_17_sprites_7_ADDRESS 0x6C6Eu    /* 072C6E */
#define fireman_goon_animations_17_sprites_8_ADDRESS 0x6C92u    /* 072C92 */
#define fireman_goon_animations_17_sprites_9_ADDRESS 0x6CB6u    /* 072CB6 */
#define fireman_goon_animations_17_sprites_10_ADDRESS 0x6CD4u    /* 072CD4 */
#define fireman_goon_animations_17_sprites_11_ADDRESS 0x6CE6u    /* 072CE6 */
#define fireman_goon_animations_18_ADDRESS 0x6CF2u    /* 072CF2 */
#define fireman_goon_animations_18_sprites_ADDRESS 0x6D22u    /* 072D22 */
#define fireman_goon_animations_18_sprites_2_ADDRESS 0x6D28u    /* 072D28 */
#define fireman_goon_animations_18_sprites_3_ADDRESS 0x6D3Au    /* 072D3A */
#define fireman_goon_animations_18_sprites_4_ADDRESS 0x6D64u    /* 072D64 */
#define fireman_goon_animations_18_sprites_5_ADDRESS 0x6DA0u    /* 072DA0 */
#define fireman_goon_animations_18_sprites_6_ADDRESS 0x6DDCu    /* 072DDC */
#define fireman_goon_animations_18_sprites_7_ADDRESS 0x6E18u    /* 072E18 */
#define fireman_goon_animations_18_sprites_8_ADDRESS 0x6E54u    /* 072E54 */
#define fireman_goon_animations_18_sprites_9_ADDRESS 0x6E90u    /* 072E90 */
#define fireman_goon_animations_18_sprites_10_ADDRESS 0x6ECCu    /* 072ECC */
#define fireman_goon_animations_18_sprites_11_ADDRESS 0x6EF0u    /* 072EF0 */
#define fireman_goon_animations_2_ADDRESS 0x6EFCu    /* 072EFC */
#define fireman_goon_animations_2_sprites_ADDRESS 0x6F20u    /* 072F20 */
#define fireman_goon_animations_2_sprites_2_ADDRESS 0x6F32u    /* 072F32 */
#define fireman_goon_animations_2_sprites_3_ADDRESS 0x6F44u    /* 072F44 */
#define fireman_goon_animations_2_sprites_4_ADDRESS 0x6F5Cu    /* 072F5C */
#define fireman_goon_animations_2_sprites_5_ADDRESS 0x6F74u    /* 072F74 */
#define fireman_goon_animations_2_sprites_6_ADDRESS 0x6F92u    /* 072F92 */
#define fireman_goon_animations_2_sprites_7_ADDRESS 0x6FAAu    /* 072FAA */
#define fireman_goon_animations_2_sprites_8_ADDRESS 0x6FC2u    /* 072FC2 */
#define fireman_goon_animations_19_ADDRESS 0x6FDAu    /* 072FDA */
#define fireman_goon_animations_19_sprites_ADDRESS 0x700Au    /* 07300A */
#define fireman_goon_animations_19_sprites_2_ADDRESS 0x7010u    /* 073010 */
#define fireman_goon_animations_19_sprites_3_ADDRESS 0x7022u    /* 073022 */
#define fireman_goon_animations_19_sprites_4_ADDRESS 0x7034u    /* 073034 */
#define fireman_goon_animations_19_sprites_5_ADDRESS 0x7046u    /* 073046 */
#define fireman_goon_animations_19_sprites_6_ADDRESS 0x705Eu    /* 07305E */
#define fireman_goon_animations_19_sprites_7_ADDRESS 0x7076u    /* 073076 */
#define fireman_goon_animations_19_sprites_8_ADDRESS 0x708Eu    /* 07308E */
#define fireman_goon_animations_19_sprites_9_ADDRESS 0x70A6u    /* 0730A6 */
#define fireman_goon_animations_19_sprites_10_ADDRESS 0x70B8u    /* 0730B8 */
#define fireman_goon_animations_19_sprites_11_ADDRESS 0x70BEu    /* 0730BE */
#define zombie_animations_ADDRESS 0x70CAu    /* 0730CA */
#define zombie_animations_0_ADDRESS 0x7100u    /* 073100 */
#define zombie_animations_0_sprites_ADDRESS 0x7108u    /* 073108 */
#define zombie_animations_19_ADDRESS 0x7120u    /* 073120 */
#define zombie_animations_18_ADDRESS 0x713Cu    /* 07313C */
#define zombie_animations_19_sprites_ADDRESS 0x7158u    /* 073158 */
#define zombie_animations_19_sprites_2_ADDRESS 0x715Eu    /* 07315E */
#define zombie_animations_19_sprites_3_ADDRESS 0x716Au    /* 07316A */
#define zombie_animations_19_sprites_4_ADDRESS 0x7170u    /* 073170 */
#define zombie_animations_19_sprites_5_ADDRESS 0x7176u    /* 073176 */
#define zombie_animations_19_sprites_6_ADDRESS 0x717Cu    /* 07317C */
#define zombie_animations_17_ADDRESS 0x718Eu    /* 07318E */
#define zombie_animations_17_sprites_ADDRESS 0x71A2u    /* 0731A2 */
#define zombie_animations_17_sprites_2_ADDRESS 0x71B4u    /* 0731B4 */
#define zombie_animations_17_sprites_3_ADDRESS 0x71C6u    /* 0731C6 */
#define zombie_animations_17_sprites_4_ADDRESS 0x71E4u    /* 0731E4 */
#define zombie_animations_1_ADDRESS 0x71FCu    /* 0731FC */
#define zombie_animations_1_sprites_ADDRESS 0x7220u    /* 073220 */
#define zombie_animations_1_sprites_2_ADDRESS 0x7232u    /* 073232 */
#define zombie_animations_1_sprites_3_ADDRESS 0x724Au    /* 07324A */
#define zombie_animations_1_sprites_4_ADDRESS 0x725Cu    /* 07325C */
#define zombie_animations_1_sprites_5_ADDRESS 0x7274u    /* 073274 */
#define zombie_animations_1_sprites_6_ADDRESS 0x728Cu    /* 07328C */
#define zombie_animations_1_sprites_7_ADDRESS 0x72A4u    /* 0732A4 */
#define zombie_animations_1_sprites_8_ADDRESS 0x72B6u    /* 0732B6 */
#define zombie_animations_11_ADDRESS 0x72CEu    /* 0732CE */
#define zombie_animations_11_sprites_ADDRESS 0x72F2u    /* 0732F2 */
#define zombie_animations_11_sprites_2_ADDRESS 0x730Au    /* 07330A */
#define zombie_animations_11_sprites_3_ADDRESS 0x7322u    /* 073322 */
#define zombie_animations_11_sprites_4_ADDRESS 0x733Au    /* 07333A */
#define zombie_animations_9_ADDRESS 0x7346u    /* 073346 */
#define zombie_animations_9_sprites_ADDRESS 0x736Au    /* 07336A */
#define zombie_animations_9_sprites_2_ADDRESS 0x7382u    /* 073382 */
#define zombie_animations_8_ADDRESS 0x7394u    /* 073394 */
#define zombie_animations_8_sprites_ADDRESS 0x73B4u    /* 0733B4 */
#define zombie_animations_8_sprites_2_ADDRESS 0x73C6u    /* 0733C6 */
#define zombie_animations_8_sprites_3_ADDRESS 0x73D8u    /* 0733D8 */
#define zombie_animations_8_sprites_4_ADDRESS 0x73EAu    /* 0733EA */
#define zombie_animations_8_sprites_5_ADDRESS 0x7402u    /* 073402 */
#define zombie_animations_8_sprites_6_ADDRESS 0x7414u    /* 073414 */
#define zombie_animations_8_sprites_7_ADDRESS 0x7426u    /* 073426 */
#define zombie_animations_6_ADDRESS 0x7438u    /* 073438 */
#define zombie_animations_6_sprites_ADDRESS 0x747Cu    /* 07347C */
#define zombie_animations_6_sprites_2_ADDRESS 0x7494u    /* 073494 */
#define zombie_animations_6_sprites_3_ADDRESS 0x74ACu    /* 0734AC */
#define zombie_animations_6_sprites_4_ADDRESS 0x74C4u    /* 0734C4 */
#define zombie_animations_6_sprites_5_ADDRESS 0x74D6u    /* 0734D6 */
#define zombie_animations_6_sprites_6_ADDRESS 0x74EEu    /* 0734EE */
#define zombie_animations_6_sprites_7_ADDRESS 0x7500u    /* 073500 */
#define zombie_animations_6_sprites_8_ADDRESS 0x7512u    /* 073512 */
#define zombie_animations_6_sprites_9_ADDRESS 0x752Au    /* 07352A */
#define zombie_animations_6_sprites_10_ADDRESS 0x753Cu    /* 07353C */
#define zombie_animations_16_ADDRESS 0x754Eu    /* 07354E */
#define zombie_animations_16_sprites_ADDRESS 0x7572u    /* 073572 */
#define zombie_animations_16_sprites_2_ADDRESS 0x758Au    /* 07358A */
#define zombie_animations_16_sprites_3_ADDRESS 0x759Cu    /* 07359C */
#define zombie_animations_16_sprites_4_ADDRESS 0x75B4u    /* 0735B4 */
#define zombie_animations_20_ADDRESS 0x75C6u    /* 0735C6 */
#define zombie_animations_20_sprites_ADDRESS 0x75F2u    /* 0735F2 */
#define zombie_animations_20_sprites_2_ADDRESS 0x75FEu    /* 0735FE */
#define zombie_animations_20_sprites_3_ADDRESS 0x7610u    /* 073610 */
#define zombie_animations_20_sprites_4_ADDRESS 0x7622u    /* 073622 */
#define zombie_animations_20_sprites_5_ADDRESS 0x763Au    /* 07363A */
#define zombie_animations_22_ADDRESS 0x7652u    /* 073652 */
#define zombie_animations_22_sprites_ADDRESS 0x7676u    /* 073676 */
#define zombie_animations_22_sprites_2_ADDRESS 0x7682u    /* 073682 */
#define zombie_animations_22_sprites_3_ADDRESS 0x7694u    /* 073694 */
#define zombie_animations_22_sprites_4_ADDRESS 0x76A0u    /* 0736A0 */
#define zombie_animations_22_sprites_5_ADDRESS 0x76B2u    /* 0736B2 */
#define zombie_animations_22_sprites_6_ADDRESS 0x76C4u    /* 0736C4 */
#define zombie_animations_22_sprites_7_ADDRESS 0x76D6u    /* 0736D6 */
#define zombie_animations_22_sprites_8_ADDRESS 0x76E2u    /* 0736E2 */
#define zombie_animations_25_ADDRESS 0x76F4u    /* 0736F4 */
#define zombie_animations_25_sprites_ADDRESS 0x7700u    /* 073700 */
#define zombie_animations_26_ADDRESS 0x7718u    /* 073718 */
#define zombie_animations_26_sprites_ADDRESS 0x773Cu    /* 07373C */
#define zombie_animations_26_sprites_2_ADDRESS 0x774Eu    /* 07374E */
#define zombie_animations_26_sprites_3_ADDRESS 0x7766u    /* 073766 */
#define zombie_animations_26_sprites_4_ADDRESS 0x7778u    /* 073778 */
#define zombie_animations_26_sprites_5_ADDRESS 0x7790u    /* 073790 */
#define zombie_animations_26_sprites_6_ADDRESS 0x77A8u    /* 0737A8 */
#define zombie_animations_26_sprites_7_ADDRESS 0x77C0u    /* 0737C0 */
#define zombie_animations_26_sprites_8_ADDRESS 0x77D2u    /* 0737D2 */
#define football_player_animations_ADDRESS 0x77EAu    /* 0737EA */
#define football_player_animations_0_ADDRESS 0x7810u    /* 073810 */
#define football_player_animations_0_sprites_ADDRESS 0x7824u    /* 073824 */
#define football_player_animations_0_sprites_2_ADDRESS 0x7836u    /* 073836 */
#define football_player_animations_0_sprites_3_ADDRESS 0x7848u    /* 073848 */
#define football_player_animations_0_sprites_4_ADDRESS 0x785Au    /* 07385A */
#define football_player_animations_1_ADDRESS 0x786Cu    /* 07386C */
#define football_player_animations_1_sprites_ADDRESS 0x7884u    /* 073884 */
#define football_player_animations_1_sprites_2_ADDRESS 0x789Cu    /* 07389C */
#define football_player_animations_1_sprites_3_ADDRESS 0x78B4u    /* 0738B4 */
#define football_player_animations_1_sprites_4_ADDRESS 0x78CCu    /* 0738CC */
#define football_player_animations_1_sprites_5_ADDRESS 0x78F0u    /* 0738F0 */
#define football_player_animations_2_ADDRESS 0x791Au    /* 07391A */
#define football_player_animations_2_sprites_ADDRESS 0x7926u    /* 073926 */
#define football_player_animations_2_sprites_2_ADDRESS 0x7950u    /* 073950 */
#define football_player_animations_3_ADDRESS 0x797Au    /* 07397A */
#define football_player_animations_3_sprites_ADDRESS 0x799Eu    /* 07399E */
#define football_player_animations_3_sprites_2_ADDRESS 0x79C8u    /* 0739C8 */
#define football_player_animations_3_sprites_3_ADDRESS 0x79F2u    /* 0739F2 */
#define football_player_animations_3_sprites_4_ADDRESS 0x7A1Cu    /* 073A1C */
#define football_player_animations_4_ADDRESS 0x7A46u    /* 073A46 */
#define football_player_animations_4_sprites_ADDRESS 0x7A5Au    /* 073A5A */
#define football_player_animations_4_sprites_2_ADDRESS 0x7AA2u    /* 073AA2 */
#define football_player_animations_4_sprites_3_ADDRESS 0x7AC6u    /* 073AC6 */
#define football_player_animations_5_ADDRESS 0x7AF6u    /* 073AF6 */
#define football_player_animations_5_sprites_ADDRESS 0x7B06u    /* 073B06 */
#define football_player_animations_5_sprites_2_ADDRESS 0x7B18u    /* 073B18 */
#define football_player_animations_5_sprites_3_ADDRESS 0x7B36u    /* 073B36 */
#define football_player_animations_6_ADDRESS 0x7B48u    /* 073B48 */
#define football_player_animations_6_sprites_ADDRESS 0x7B54u    /* 073B54 */
#define football_player_animations_6_sprites_2_ADDRESS 0x7B8Au    /* 073B8A */
#define football_player_animations_7_ADDRESS 0x7BC0u    /* 073BC0 */
#define football_player_animations_7_sprites_ADDRESS 0x7BC8u    /* 073BC8 */
#define football_player_animations_8_ADDRESS 0x7BECu    /* 073BEC */
#define football_player_animations_8_sprites_ADDRESS 0x7C00u    /* 073C00 */
#define football_player_animations_8_sprites_2_ADDRESS 0x7C06u    /* 073C06 */
#define football_player_animations_8_sprites_3_ADDRESS 0x7C1Eu    /* 073C1E */
#define football_player_animations_8_sprites_4_ADDRESS 0x7C2Au    /* 073C2A */
#define football_player_animations_9_ADDRESS 0x7C36u    /* 073C36 */
#define football_player_animations_10_ADDRESS 0x7C3Eu    /* 073C3E */
#define football_player_animations_10_sprites_ADDRESS 0x7C4Au    /* 073C4A */
#define football_player_animations_10_sprites_2_ADDRESS 0x7C74u    /* 073C74 */
#define football_player_animations_11_ADDRESS 0x7C92u    /* 073C92 */
#define football_player_animations_11_sprites_ADDRESS 0x7C9Au    /* 073C9A */
#define football_player_animations_17_ADDRESS 0x7CA0u    /* 073CA0 */
#define football_player_animations_17_sprites_ADDRESS 0x7CA8u    /* 073CA8 */
#define football_player_animations_18_ADDRESS 0x7CAEu    /* 073CAE */
#define football_player_animations_18_sprites_ADDRESS 0x7CB6u    /* 073CB6 */
#define football_player_animations_12_ADDRESS 0x7CBCu    /* 073CBC */
#define football_player_animations_12_sprites_ADDRESS 0x7CC8u    /* 073CC8 */
#define football_player_animations_12_sprites_2_ADDRESS 0x7CF2u    /* 073CF2 */
#define football_player_animations_13_ADDRESS 0x7D1Cu    /* 073D1C */
#define football_player_animations_13_sprites_ADDRESS 0x7D30u    /* 073D30 */
#define football_player_animations_13_sprites_2_ADDRESS 0x7D4Eu    /* 073D4E */
#define football_player_animations_13_sprites_3_ADDRESS 0x7D6Cu    /* 073D6C */
#define football_player_animations_14_ADDRESS 0x7D9Cu    /* 073D9C */
#define football_player_animations_14_sprites_ADDRESS 0x7DA4u    /* 073DA4 */
#define football_player_animations_15_ADDRESS 0x7DD4u    /* 073DD4 */
#define football_player_animations_15_sprites_ADDRESS 0x7DE4u    /* 073DE4 */
#define football_player_animations_15_sprites_2_ADDRESS 0x7E08u    /* 073E08 */
#define football_player_animations_15_sprites_3_ADDRESS 0x7E38u    /* 073E38 */
#define football_player_animations_16_ADDRESS 0x7E74u    /* 073E74 */
#define football_player_animations_16_sprites_ADDRESS 0x7E84u    /* 073E84 */
#define football_player_animations_16_sprites_2_ADDRESS 0x7E96u    /* 073E96 */
#define football_player_animations_16_sprites_3_ADDRESS 0x7EBAu    /* 073EBA */
#define football_player_animations_16_sprites_3_fill_ADDRESS 0x7EE4u    /* 073EE4 */
#define football_player_animations_16_sprites_3_rest_ADDRESS 0x6000u    /* 074000 */
#define goon_with_shovel_animations_ADDRESS 0x600Eu    /* 07400E */
#define goon_with_shovel_animations_8_ADDRESS 0x6058u    /* 074058 */
#define goon_with_shovel_animations_8_sprites_ADDRESS 0x6070u    /* 074070 */
#define goon_with_shovel_animations_8_sprites_2_ADDRESS 0x607Cu    /* 07407C */
#define goon_with_shovel_animations_8_sprites_3_ADDRESS 0x6088u    /* 074088 */
#define goon_with_shovel_animations_8_sprites_4_ADDRESS 0x6094u    /* 074094 */
#define goon_with_shovel_animations_8_sprites_5_ADDRESS 0x60A6u    /* 0740A6 */
#define goon_with_shovel_animations_21_ADDRESS 0x60ACu    /* 0740AC */
#define goon_with_shovel_animations_21_sprites_ADDRESS 0x60BCu    /* 0740BC */
#define goon_with_shovel_animations_21_sprites_2_ADDRESS 0x60C2u    /* 0740C2 */
#define goon_with_shovel_animations_21_sprites_3_ADDRESS 0x60C8u    /* 0740C8 */
#define goon_with_shovel_animations_22_ADDRESS 0x60CEu    /* 0740CE */
#define goon_with_shovel_animations_22_sprites_ADDRESS 0x60DEu    /* 0740DE */
#define goon_with_shovel_animations_22_sprites_2_ADDRESS 0x60E4u    /* 0740E4 */
#define goon_with_shovel_animations_22_sprites_3_ADDRESS 0x60EAu    /* 0740EA */
#define goon_with_shovel_animations_23_ADDRESS 0x60F0u    /* 0740F0 */
#define goon_with_shovel_animations_23_sprites_ADDRESS 0x6104u    /* 074104 */
#define goon_with_shovel_animations_23_sprites_2_ADDRESS 0x611Cu    /* 07411C */
#define goon_with_shovel_animations_23_sprites_3_ADDRESS 0x6134u    /* 074134 */
#define goon_with_shovel_animations_23_sprites_4_ADDRESS 0x614Cu    /* 07414C */
#define goon_with_shovel_animations_24_ADDRESS 0x6164u    /* 074164 */
#define goon_with_shovel_animations_0_ADDRESS 0x6178u    /* 074178 */
#define goon_with_shovel_animations_0_sprites_ADDRESS 0x6180u    /* 074180 */
#define goon_with_shovel_animations_1_ADDRESS 0x6192u    /* 074192 */
#define goon_with_shovel_animations_1_sprites_ADDRESS 0x61B6u    /* 0741B6 */
#define goon_with_shovel_animations_1_sprites_2_ADDRESS 0x61CEu    /* 0741CE */
#define goon_with_shovel_animations_1_sprites_3_ADDRESS 0x61E6u    /* 0741E6 */
#define goon_with_shovel_animations_1_sprites_4_ADDRESS 0x61FEu    /* 0741FE */
#define goon_with_shovel_animations_1_sprites_5_ADDRESS 0x6216u    /* 074216 */
#define goon_with_shovel_animations_1_sprites_6_ADDRESS 0x622Eu    /* 07422E */
#define goon_with_shovel_animations_1_sprites_7_ADDRESS 0x6246u    /* 074246 */
#define goon_with_shovel_animations_1_sprites_8_ADDRESS 0x6258u    /* 074258 */
#define goon_with_shovel_animations_2_ADDRESS 0x6270u    /* 074270 */
#define goon_with_shovel_animations_2_sprites_ADDRESS 0x6294u    /* 074294 */
#define goon_with_shovel_animations_2_sprites_2_ADDRESS 0x62ACu    /* 0742AC */
#define goon_with_shovel_animations_2_sprites_3_ADDRESS 0x62C4u    /* 0742C4 */
#define goon_with_shovel_animations_2_sprites_4_ADDRESS 0x62DCu    /* 0742DC */
#define goon_with_shovel_animations_2_sprites_5_ADDRESS 0x62F4u    /* 0742F4 */
#define goon_with_shovel_animations_2_sprites_6_ADDRESS 0x630Cu    /* 07430C */
#define goon_with_shovel_animations_2_sprites_7_ADDRESS 0x6324u    /* 074324 */
#define goon_with_shovel_animations_2_sprites_8_ADDRESS 0x633Cu    /* 07433C */
#define goon_with_shovel_animations_3_ADDRESS 0x6354u    /* 074354 */
#define goon_with_shovel_animations_3_sprites_ADDRESS 0x6378u    /* 074378 */
#define goon_with_shovel_animations_3_sprites_2_ADDRESS 0x638Au    /* 07438A */
#define goon_with_shovel_animations_3_sprites_3_ADDRESS 0x639Cu    /* 07439C */
#define goon_with_shovel_animations_3_sprites_4_ADDRESS 0x63B4u    /* 0743B4 */
#define goon_with_shovel_animations_3_sprites_5_ADDRESS 0x63CCu    /* 0743CC */
#define goon_with_shovel_animations_3_sprites_6_ADDRESS 0x63DEu    /* 0743DE */
#define goon_with_shovel_animations_3_sprites_7_ADDRESS 0x63F0u    /* 0743F0 */
#define goon_with_shovel_animations_3_sprites_8_ADDRESS 0x6408u    /* 074408 */
#define goon_with_shovel_animations_4_ADDRESS 0x6420u    /* 074420 */
#define goon_with_shovel_animations_4_sprites_ADDRESS 0x642Cu    /* 07442C */
#define goon_with_shovel_animations_4_sprites_2_ADDRESS 0x6444u    /* 074444 */
#define goon_with_shovel_animations_5_ADDRESS 0x645Cu    /* 07445C */
#define goon_with_shovel_animations_5_sprites_ADDRESS 0x6468u    /* 074468 */
#define goon_with_shovel_animations_5_sprites_2_ADDRESS 0x6480u    /* 074480 */
#define goon_with_shovel_animations_6_ADDRESS 0x6498u    /* 074498 */
#define goon_with_shovel_animations_6_sprites_ADDRESS 0x64A4u    /* 0744A4 */
#define goon_with_shovel_animations_6_sprites_2_ADDRESS 0x64B6u    /* 0744B6 */
#define goon_with_shovel_animations_7_ADDRESS 0x64CEu    /* 0744CE */
#define goon_with_shovel_animations_7_sprites_ADDRESS 0x64DAu    /* 0744DA */
#define goon_with_shovel_animations_7_sprites_2_ADDRESS 0x64E6u    /* 0744E6 */
#define goon_with_shovel_animations_9_ADDRESS 0x64F2u    /* 0744F2 */
#define goon_with_shovel_animations_9_sprites_ADDRESS 0x650Eu    /* 07450E */
#define goon_with_shovel_animations_9_sprites_2_ADDRESS 0x6526u    /* 074526 */
#define goon_with_shovel_animations_9_sprites_3_ADDRESS 0x6538u    /* 074538 */
#define goon_with_shovel_animations_9_sprites_4_ADDRESS 0x6550u    /* 074550 */
#define goon_with_shovel_animations_10_ADDRESS 0x6568u    /* 074568 */
#define goon_with_shovel_animations_10_sprites_ADDRESS 0x657Cu    /* 07457C */
#define goon_with_shovel_animations_10_sprites_2_ADDRESS 0x658Eu    /* 07458E */
#define goon_with_shovel_animations_10_sprites_3_ADDRESS 0x65A6u    /* 0745A6 */
#define goon_with_shovel_animations_10_sprites_4_ADDRESS 0x65BEu    /* 0745BE */
#define goon_with_shovel_animations_11_ADDRESS 0x65D0u    /* 0745D0 */
#define goon_with_shovel_animations_11_sprites_ADDRESS 0x65E8u    /* 0745E8 */
#define goon_with_shovel_animations_11_sprites_2_ADDRESS 0x6606u    /* 074606 */
#define goon_with_shovel_animations_11_sprites_3_ADDRESS 0x6624u    /* 074624 */
#define goon_with_shovel_animations_11_sprites_4_ADDRESS 0x663Cu    /* 07463C */
#define goon_with_shovel_animations_11_sprites_5_ADDRESS 0x665Au    /* 07465A */
#define goon_with_shovel_animations_12_ADDRESS 0x6678u    /* 074678 */
#define goon_with_shovel_animations_12_sprites_ADDRESS 0x6698u    /* 074698 */
#define goon_with_shovel_animations_12_sprites_2_ADDRESS 0x66B0u    /* 0746B0 */
#define goon_with_shovel_animations_12_sprites_3_ADDRESS 0x66CEu    /* 0746CE */
#define goon_with_shovel_animations_12_sprites_4_ADDRESS 0x66ECu    /* 0746EC */
#define goon_with_shovel_animations_12_sprites_5_ADDRESS 0x670Au    /* 07470A */
#define goon_with_shovel_animations_12_sprites_6_ADDRESS 0x6722u    /* 074722 */
#define goon_with_shovel_animations_13_ADDRESS 0x673Au    /* 07473A */
#define goon_with_shovel_animations_13_sprites_ADDRESS 0x6746u    /* 074746 */
#define goon_with_shovel_animations_13_sprites_2_ADDRESS 0x675Eu    /* 07475E */
#define goon_with_shovel_animations_14_ADDRESS 0x6776u    /* 074776 */
#define goon_with_shovel_animations_14_sprites_ADDRESS 0x679Au    /* 07479A */
#define goon_with_shovel_animations_14_sprites_2_ADDRESS 0x67B2u    /* 0747B2 */
#define goon_with_shovel_animations_14_sprites_3_ADDRESS 0x67D0u    /* 0747D0 */
#define goon_with_shovel_animations_14_sprites_4_ADDRESS 0x67E8u    /* 0747E8 */
#define goon_with_shovel_animations_14_sprites_5_ADDRESS 0x6806u    /* 074806 */
#define goon_with_shovel_animations_14_sprites_6_ADDRESS 0x6818u    /* 074818 */
#define goon_with_shovel_animations_15_ADDRESS 0x682Au    /* 07482A */
#define goon_with_shovel_animations_15_sprites_ADDRESS 0x6846u    /* 074846 */
#define goon_with_shovel_animations_15_sprites_2_ADDRESS 0x685Eu    /* 07485E */
#define goon_with_shovel_animations_15_sprites_3_ADDRESS 0x6876u    /* 074876 */
#define goon_with_shovel_animations_15_sprites_4_ADDRESS 0x689Au    /* 07489A */
#define goon_with_shovel_animations_16_ADDRESS 0x68BEu    /* 0748BE */
#define goon_with_shovel_animations_16_sprites_ADDRESS 0x68E2u    /* 0748E2 */
#define goon_with_shovel_animations_16_sprites_2_ADDRESS 0x68F4u    /* 0748F4 */
#define goon_with_shovel_animations_16_sprites_3_ADDRESS 0x6906u    /* 074906 */
#define goon_with_shovel_animations_16_sprites_4_ADDRESS 0x6918u    /* 074918 */
#define goon_with_shovel_animations_16_sprites_5_ADDRESS 0x692Au    /* 07492A */
#define goon_with_shovel_animations_16_sprites_6_ADDRESS 0x693Cu    /* 07493C */
#define goon_with_shovel_animations_16_sprites_7_ADDRESS 0x694Eu    /* 07494E */
#define goon_with_shovel_animations_16_sprites_8_ADDRESS 0x6960u    /* 074960 */
#define goon_with_shovel_animations_17_ADDRESS 0x6978u    /* 074978 */
#define goon_with_shovel_animations_17_sprites_ADDRESS 0x6990u    /* 074990 */
#define goon_with_shovel_animations_17_sprites_2_ADDRESS 0x69A8u    /* 0749A8 */
#define goon_with_shovel_animations_17_sprites_3_ADDRESS 0x69BAu    /* 0749BA */
#define goon_with_shovel_animations_17_sprites_4_ADDRESS 0x69D2u    /* 0749D2 */
#define goon_with_shovel_animations_18_ADDRESS 0x69EAu    /* 0749EA */
#define goon_with_shovel_animations_18_sprites_ADDRESS 0x69FEu    /* 0749FE */
#define goon_with_shovel_animations_18_sprites_2_ADDRESS 0x6A16u    /* 074A16 */
#define goon_with_shovel_animations_19_ADDRESS 0x6A28u    /* 074A28 */
#define goon_with_shovel_animations_19_sprites_ADDRESS 0x6A38u    /* 074A38 */
#define goon_with_shovel_animations_19_sprites_2_ADDRESS 0x6A44u    /* 074A44 */
#define goon_with_shovel_animations_32_ADDRESS 0x6A56u    /* 074A56 */
#define goon_with_shovel_animations_32_sprites_ADDRESS 0x6A72u    /* 074A72 */
#define goon_with_shovel_animations_32_sprites_2_ADDRESS 0x6A7Eu    /* 074A7E */
#define goon_with_shovel_animations_32_sprites_3_ADDRESS 0x6A90u    /* 074A90 */
#define goon_with_shovel_animations_32_sprites_4_ADDRESS 0x6A9Cu    /* 074A9C */
#define goon_with_shovel_animations_32_sprites_5_ADDRESS 0x6AAEu    /* 074AAE */
#define goon_with_shovel_animations_33_ADDRESS 0x6AC0u    /* 074AC0 */
#define goon_with_shovel_animations_33_sprites_ADDRESS 0x6AD0u    /* 074AD0 */
#define goon_with_shovel_animations_20_ADDRESS 0x6AD6u    /* 074AD6 */
#define goon_with_shovel_animations_20_sprites_ADDRESS 0x6ADEu    /* 074ADE */
#define goon_with_shovel_animations_36_ADDRESS 0x6AEAu    /* 074AEA */
#define goon_with_shovel_animations_36_sprites_ADDRESS 0x6B0Eu    /* 074B0E */
#define goon_with_shovel_animations_36_sprites_2_ADDRESS 0x6B26u    /* 074B26 */
#define goon_with_shovel_animations_36_sprites_3_ADDRESS 0x6B3Eu    /* 074B3E */
#define goon_with_shovel_animations_36_sprites_4_ADDRESS 0x6B56u    /* 074B56 */
#define goon_with_shovel_animations_36_sprites_5_ADDRESS 0x6B6Eu    /* 074B6E */
#define goon_with_shovel_animations_36_sprites_6_ADDRESS 0x6B86u    /* 074B86 */
#define goon_with_shovel_animations_36_sprites_7_ADDRESS 0x6B9Eu    /* 074B9E */
#define goon_with_shovel_animations_36_sprites_8_ADDRESS 0x6BB6u    /* 074BB6 */
#define dog_animations_ADDRESS 0x6BD4u    /* 074BD4 */
#define dog_animations_0_ADDRESS 0x6BD8u    /* 074BD8 */
#define dog_animations_0_sprites_ADDRESS 0x6BECu    /* 074BEC */
#define dog_animations_0_sprites_2_ADDRESS 0x6BF8u    /* 074BF8 */
#define dog_animations_0_sprites_3_ADDRESS 0x6C04u    /* 074C04 */
#define dog_animations_0_sprites_4_ADDRESS 0x6C10u    /* 074C10 */
#define dog_animations_1_ADDRESS 0x6C1Cu    /* 074C1C */
#define dog_animations_1_sprites_ADDRESS 0x6C2Cu    /* 074C2C */
#define dog_animations_1_sprites_2_ADDRESS 0x6C38u    /* 074C38 */
#define woman_in_apron_animations_ADDRESS 0x6C44u    /* 074C44 */
#define woman_in_apron_animations_rest_ADDRESS 0x6C4Au    /* 074C4A */
#define woman_in_apron_animations_rest_2_ADDRESS 0x6C52u    /* 074C52 */
#define woman_in_apron_animations_0_ADDRESS 0x6C64u    /* 074C64 */
#define woman_in_apron_animations_0_sprites_ADDRESS 0x6C80u    /* 074C80 */
#define woman_in_apron_animations_0_sprites_2_ADDRESS 0x6C92u    /* 074C92 */
#define woman_in_apron_animations_0_sprites_3_ADDRESS 0x6CA4u    /* 074CA4 */
#define woman_in_apron_animations_0_sprites_4_ADDRESS 0x6CB6u    /* 074CB6 */
#define woman_in_apron_animations_0_sprites_5_ADDRESS 0x6CC8u    /* 074CC8 */
#define woman_in_apron_animations_0_sprites_6_ADDRESS 0x6CDAu    /* 074CDA */
#define woman_in_apron_animations_1_ADDRESS 0x6CECu    /* 074CEC */
#define woman_in_apron_animations_1_sprites_ADDRESS 0x6D20u    /* 074D20 */
#define woman_in_apron_animations_1_sprites_2_ADDRESS 0x6D32u    /* 074D32 */
#define woman_in_apron_animations_1_sprites_3_ADDRESS 0x6D44u    /* 074D44 */
#define woman_in_apron_animations_1_sprites_4_ADDRESS 0x6D56u    /* 074D56 */
#define woman_in_apron_animations_1_sprites_5_ADDRESS 0x6D6Eu    /* 074D6E */
#define woman_in_apron_animations_1_sprites_6_ADDRESS 0x6D8Cu    /* 074D8C */
#define woman_in_apron_animations_1_sprites_7_ADDRESS 0x6DA4u    /* 074DA4 */
#define woman_in_apron_animations_2_ADDRESS 0x6DC2u    /* 074DC2 */
#define woman_in_apron_animations_2_sprites_ADDRESS 0x6DDAu    /* 074DDA */
#define woman_in_apron_animations_2_sprites_2_ADDRESS 0x6DF2u    /* 074DF2 */
#define fat_goon_in_teacup_animations_ADDRESS 0x6E0Au    /* 074E0A */
#define fat_goon_in_teacup_animations_0_ADDRESS 0x6E14u    /* 074E14 */
#define fat_goon_in_teacup_animations_0_sprites_ADDRESS 0x6E1Cu    /* 074E1C */
#define fat_goon_in_teacup_animations_1_ADDRESS 0x6E22u    /* 074E22 */
#define fat_goon_in_teacup_animations_1_sprites_ADDRESS 0x6E46u    /* 074E46 */
#define fat_goon_in_teacup_animations_1_sprites_2_ADDRESS 0x6E58u    /* 074E58 */
#define fat_goon_in_teacup_animations_1_sprites_3_ADDRESS 0x6E6Au    /* 074E6A */
#define fat_goon_in_teacup_animations_1_sprites_4_ADDRESS 0x6E82u    /* 074E82 */
#define fat_goon_in_teacup_animations_1_sprites_5_ADDRESS 0x6E9Au    /* 074E9A */
#define fat_goon_in_teacup_animations_1_sprites_6_ADDRESS 0x6EB2u    /* 074EB2 */
#define fat_goon_in_teacup_animations_1_sprites_7_ADDRESS 0x6ECAu    /* 074ECA */
#define fat_goon_in_teacup_animations_1_sprites_8_ADDRESS 0x6EE2u    /* 074EE2 */
#define fat_goon_in_teacup_animations_2_ADDRESS 0x6EFAu    /* 074EFA */
#define fat_goon_in_teacup_animations_2_sprites_ADDRESS 0x6F1Eu    /* 074F1E */
#define fat_goon_in_teacup_animations_2_sprites_2_ADDRESS 0x6F36u    /* 074F36 */
#define fat_goon_in_teacup_animations_2_sprites_3_ADDRESS 0x6F4Eu    /* 074F4E */
#define fat_goon_in_teacup_animations_2_sprites_4_ADDRESS 0x6F66u    /* 074F66 */
#define fat_goon_in_teacup_animations_2_sprites_5_ADDRESS 0x6F7Eu    /* 074F7E */
#define fat_goon_in_teacup_animations_2_sprites_6_ADDRESS 0x6F96u    /* 074F96 */
#define fat_goon_in_teacup_animations_2_sprites_7_ADDRESS 0x6FAEu    /* 074FAE */
#define fat_goon_in_teacup_animations_3_ADDRESS 0x6FC6u    /* 074FC6 */
#define fat_goon_in_teacup_animations_3_sprites_ADDRESS 0x6FEAu    /* 074FEA */
#define fat_goon_in_teacup_animations_3_sprites_2_ADDRESS 0x6FFCu    /* 074FFC */
#define fat_goon_in_teacup_animations_3_sprites_3_ADDRESS 0x7014u    /* 075014 */
#define fat_goon_in_teacup_animations_3_sprites_4_ADDRESS 0x7032u    /* 075032 */
#define fat_goon_in_teacup_animations_3_sprites_5_ADDRESS 0x704Au    /* 07504A */
#define fat_goon_in_teacup_animations_3_sprites_6_ADDRESS 0x7062u    /* 075062 */
#define fat_goon_in_teacup_animations_3_sprites_7_ADDRESS 0x7080u    /* 075080 */
#define fat_goon_in_teacup_animations_3_sprites_8_ADDRESS 0x709Eu    /* 07509E */
#define fat_goon_in_teacup_animations_4_ADDRESS 0x70B6u    /* 0750B6 */
#define fat_goon_in_teacup_animations_4_sprites_ADDRESS 0x70C2u    /* 0750C2 */
#define squirrel_animations_ADDRESS 0x70D4u    /* 0750D4 */
#define squirrel_animations_1_ADDRESS 0x70D8u    /* 0750D8 */
#define squirrel_animations_1_sprites_ADDRESS 0x7114u    /* 075114 */
#define squirrel_animations_1_sprites_2_ADDRESS 0x7120u    /* 075120 */
#define squirrel_animations_1_sprites_3_ADDRESS 0x7132u    /* 075132 */
#define squirrel_animations_1_sprites_4_ADDRESS 0x7144u    /* 075144 */
#define squirrel_animations_1_sprites_5_ADDRESS 0x7156u    /* 075156 */
#define squirrel_animations_0_ADDRESS 0x7168u    /* 075168 */
#define squirrel_animations_0_sprites_ADDRESS 0x717Cu    /* 07517C */
#define squirrel_animations_0_sprites_2_ADDRESS 0x7182u    /* 075182 */
#define squirrel_animations_0_sprites_3_ADDRESS 0x7194u    /* 075194 */
#define squirrel_animations_0_sprites_4_ADDRESS 0x71A6u    /* 0751A6 */
#define gangster_animations_ADDRESS 0x71ACu    /* 0751AC */
#define gangster_animations_7_ADDRESS 0x71C2u    /* 0751C2 */
#define gangster_animations_7_sprites_ADDRESS 0x71CAu    /* 0751CA */
#define gangster_animations_10_ADDRESS 0x71D0u    /* 0751D0 */
#define gangster_animations_10_sprites_ADDRESS 0x71E4u    /* 0751E4 */
#define gangster_animations_10_sprites_2_ADDRESS 0x71FCu    /* 0751FC */
#define gangster_animations_10_sprites_3_ADDRESS 0x721Au    /* 07521A */
#define gangster_animations_0_ADDRESS 0x7238u    /* 075238 */
#define gangster_animations_0_sprites_ADDRESS 0x724Cu    /* 07524C */
#define gangster_animations_0_sprites_2_ADDRESS 0x7264u    /* 075264 */
#define gangster_animations_0_sprites_3_ADDRESS 0x7282u    /* 075282 */
#define gangster_animations_2_ADDRESS 0x72A0u    /* 0752A0 */
#define gangster_animations_2_sprites_ADDRESS 0x72ACu    /* 0752AC */
#define gangster_animations_2_sprites_2_ADDRESS 0x72C4u    /* 0752C4 */
#define gangster_animations_1_ADDRESS 0x72DCu    /* 0752DC */
#define gangster_animations_1_sprites_ADDRESS 0x7300u    /* 075300 */
#define gangster_animations_1_sprites_2_ADDRESS 0x7312u    /* 075312 */
#define gangster_animations_1_sprites_3_ADDRESS 0x732Au    /* 07532A */
#define gangster_animations_1_sprites_4_ADDRESS 0x7342u    /* 075342 */
#define gangster_animations_1_sprites_5_ADDRESS 0x735Au    /* 07535A */
#define gangster_animations_1_sprites_6_ADDRESS 0x7372u    /* 075372 */
#define gangster_animations_1_sprites_7_ADDRESS 0x738Au    /* 07538A */
#define gangster_animations_1_sprites_8_ADDRESS 0x739Cu    /* 07539C */
#define gangster_animations_3_ADDRESS 0x73B4u    /* 0753B4 */
#define gangster_animations_3_sprites_ADDRESS 0x73C4u    /* 0753C4 */
#define gangster_animations_3_sprites_2_ADDRESS 0x73E2u    /* 0753E2 */
#define gangster_animations_3_sprites_3_ADDRESS 0x7400u    /* 075400 */
#define gangster_animations_6_ADDRESS 0x741Eu    /* 07541E */
#define gangster_animations_6_sprites_ADDRESS 0x7436u    /* 075436 */
#define gangster_animations_6_sprites_2_ADDRESS 0x744Eu    /* 07544E */
#define gangster_animations_6_sprites_3_ADDRESS 0x7466u    /* 075466 */
#define gangster_animations_6_sprites_4_ADDRESS 0x7484u    /* 075484 */
#define gangster_animations_6_sprites_5_ADDRESS 0x74A2u    /* 0754A2 */
#define gangster_animations_5_ADDRESS 0x74BAu    /* 0754BA */
#define gangster_animations_5_sprites_ADDRESS 0x74C6u    /* 0754C6 */
#define gangster_animations_5_sprites_2_ADDRESS 0x74DEu    /* 0754DE */
#define gangster_animations_4_ADDRESS 0x74F6u    /* 0754F6 */
#define gangster_animations_9_ADDRESS 0x7506u    /* 075506 */
#define gangster_2_animations_ADDRESS 0x751Au    /* 07551A */
#define gangster_2_animations_9_ADDRESS 0x7532u    /* 075532 */
#define gangster_2_animations_9_sprites_ADDRESS 0x755Au    /* 07555A */
#define gangster_2_animations_9_sprites_2_ADDRESS 0x7584u    /* 075584 */
#define gangster_2_animations_9_sprites_3_ADDRESS 0x75B4u    /* 0755B4 */
#define gangster_2_animations_9_sprites_4_ADDRESS 0x75DEu    /* 0755DE */
#define gangster_2_animations_9_sprites_5_ADDRESS 0x7614u    /* 075614 */
#define gangster_2_animations_9_sprites_6_ADDRESS 0x763Eu    /* 07563E */
#define gangster_2_animations_9_sprites_7_ADDRESS 0x7668u    /* 075668 */
#define gangster_2_animations_10_ADDRESS 0x7692u    /* 075692 */
#define gangster_2_animations_10_sprites_ADDRESS 0x76A6u    /* 0756A6 */
#define gangster_2_animations_0_ADDRESS 0x76D0u    /* 0756D0 */
#define gangster_2_animations_1_ADDRESS 0x76E4u    /* 0756E4 */
#define gangster_2_animations_1_sprites_ADDRESS 0x7708u    /* 075708 */
#define gangster_2_animations_1_sprites_2_ADDRESS 0x771Au    /* 07571A */
#define gangster_2_animations_1_sprites_3_ADDRESS 0x7726u    /* 075726 */
#define gangster_2_animations_1_sprites_4_ADDRESS 0x7732u    /* 075732 */
#define gangster_2_animations_1_sprites_5_ADDRESS 0x773Eu    /* 07573E */
#define gangster_2_animations_1_sprites_6_ADDRESS 0x7750u    /* 075750 */
#define gangster_2_animations_1_sprites_7_ADDRESS 0x775Cu    /* 07575C */
#define gangster_2_animations_1_sprites_8_ADDRESS 0x7768u    /* 075768 */
#define gangster_2_animations_7_ADDRESS 0x777Au    /* 07577A */
#define gangster_2_animations_7_sprites_ADDRESS 0x779Eu    /* 07579E */
#define gangster_2_animations_7_sprites_2_ADDRESS 0x77B0u    /* 0757B0 */
#define gangster_2_animations_7_sprites_3_ADDRESS 0x77C2u    /* 0757C2 */
#define gangster_2_animations_7_sprites_4_ADDRESS 0x77D4u    /* 0757D4 */
#define gangster_2_animations_7_sprites_5_ADDRESS 0x77E6u    /* 0757E6 */
#define gangster_2_animations_7_sprites_6_ADDRESS 0x77F8u    /* 0757F8 */
#define gangster_2_animations_7_sprites_7_ADDRESS 0x780Au    /* 07580A */
#define gangster_2_animations_7_sprites_8_ADDRESS 0x781Cu    /* 07581C */
#define gangster_2_animations_3_ADDRESS 0x782Eu    /* 07582E */
#define gangster_2_animations_3_sprites_ADDRESS 0x7842u    /* 075842 */
#define gangster_2_animations_3_sprites_2_ADDRESS 0x786Cu    /* 07586C */
#define gangster_2_animations_3_sprites_3_ADDRESS 0x7896u    /* 075896 */
#define gangster_2_animations_3_sprites_4_ADDRESS 0x78B4u    /* 0758B4 */
#define gangster_2_animations_4_ADDRESS 0x78F0u    /* 0758F0 */
#define gangster_2_animations_4_sprites_ADDRESS 0x78FCu    /* 0758FC */
#define gangster_2_animations_4_sprites_2_ADDRESS 0x7926u    /* 075926 */
#define gangster_2_animations_6_ADDRESS 0x7950u    /* 075950 */
#define gangster_2_animations_6_sprites_ADDRESS 0x796Cu    /* 07596C */
#define gangster_2_animations_6_sprites_2_ADDRESS 0x7984u    /* 075984 */
#define gangster_2_animations_6_sprites_3_ADDRESS 0x79A8u    /* 0759A8 */
#define gangster_2_animations_6_sprites_4_ADDRESS 0x79D2u    /* 0759D2 */
#define gangster_2_animations_6_sprites_5_ADDRESS 0x79FCu    /* 0759FC */
#define gangster_2_animations_5_ADDRESS 0x7A20u    /* 075A20 */
#define gangster_2_animations_5_sprites_ADDRESS 0x7A2Cu    /* 075A2C */
#define gangster_2_animations_5_sprites_2_ADDRESS 0x7A50u    /* 075A50 */
#define gangster_animations_8_ADDRESS 0x7A7Au    /* 075A7A */
#define gangster_animations_8_sprites_ADDRESS 0x7AAEu    /* 075AAE */
#define gangster_animations_8_sprites_2_ADDRESS 0x7AE4u    /* 075AE4 */
#define gangster_animations_8_sprites_3_ADDRESS 0x7B26u    /* 075B26 */
#define gangster_animations_8_sprites_4_ADDRESS 0x7B62u    /* 075B62 */
#define gangster_animations_8_sprites_5_ADDRESS 0x7BBCu    /* 075BBC */
#define gangster_animations_8_sprites_6_ADDRESS 0x7C16u    /* 075C16 */
#define gangster_animations_8_sprites_7_ADDRESS 0x7C6Au    /* 075C6A */
#define gangster_animations_8_sprites_8_ADDRESS 0x7CCAu    /* 075CCA */
#define gangster_animations_8_sprites_9_ADDRESS 0x7D24u    /* 075D24 */
#define gangster_animations_8_sprites_10_ADDRESS 0x7D84u    /* 075D84 */
#define gangster_animations_8_sprites_11_ADDRESS 0x7DD8u    /* 075DD8 */
#define gangster_animations_8_sprites_12_ADDRESS 0x7E32u    /* 075E32 */
#define gangster_2_animations_2_ADDRESS 0x7E74u    /* 075E74 */
#define gangster_2_animations_11_ADDRESS 0x7E7Cu    /* 075E7C */
#define gangster_2_animations_11_sprites_ADDRESS 0x7E84u    /* 075E84 */
#define gangster_2_animations_11_sprites_fill_ADDRESS 0x7EB4u    /* 075EB4 */
#define gangster_2_animations_11_sprites_rest_ADDRESS 0x6000u    /* 076000 */
#define goon_animations_ADDRESS 0x6004u    /* 076004 */
#define goon_animations_0_ADDRESS 0x6094u    /* 076094 */
#define goon_animations_0_sprites_ADDRESS 0x609Cu    /* 07609C */
#define goon_animations_1_ADDRESS 0x60A2u    /* 0760A2 */
#define goon_animations_1_sprites_ADDRESS 0x60C6u    /* 0760C6 */
#define goon_animations_1_sprites_2_ADDRESS 0x60D8u    /* 0760D8 */
#define goon_animations_1_sprites_3_ADDRESS 0x60EAu    /* 0760EA */
#define goon_animations_1_sprites_4_ADDRESS 0x60FCu    /* 0760FC */
#define goon_animations_1_sprites_5_ADDRESS 0x610Eu    /* 07610E */
#define goon_animations_1_sprites_6_ADDRESS 0x6120u    /* 076120 */
#define goon_animations_1_sprites_7_ADDRESS 0x6132u    /* 076132 */
#define goon_animations_1_sprites_8_ADDRESS 0x6144u    /* 076144 */
#define goon_animations_2_ADDRESS 0x6156u    /* 076156 */
#define goon_animations_2_sprites_ADDRESS 0x617Au    /* 07617A */
#define goon_animations_2_sprites_2_ADDRESS 0x6192u    /* 076192 */
#define goon_animations_2_sprites_3_ADDRESS 0x61A4u    /* 0761A4 */
#define goon_animations_2_sprites_4_ADDRESS 0x61B6u    /* 0761B6 */
#define goon_animations_2_sprites_5_ADDRESS 0x61C8u    /* 0761C8 */
#define goon_animations_2_sprites_6_ADDRESS 0x61DAu    /* 0761DA */
#define goon_animations_2_sprites_7_ADDRESS 0x61ECu    /* 0761EC */
#define goon_animations_2_sprites_8_ADDRESS 0x61FEu    /* 0761FE */
#define goon_animations_3_ADDRESS 0x6210u    /* 076210 */
#define goon_animations_3_sprites_ADDRESS 0x6234u    /* 076234 */
#define goon_animations_3_sprites_2_ADDRESS 0x6246u    /* 076246 */
#define goon_animations_3_sprites_3_ADDRESS 0x6258u    /* 076258 */
#define goon_animations_3_sprites_4_ADDRESS 0x626Au    /* 07626A */
#define goon_animations_3_sprites_5_ADDRESS 0x627Cu    /* 07627C */
#define goon_animations_3_sprites_6_ADDRESS 0x628Eu    /* 07628E */
#define goon_animations_3_sprites_7_ADDRESS 0x62A0u    /* 0762A0 */
#define goon_animations_3_sprites_8_ADDRESS 0x62B2u    /* 0762B2 */
#define goon_animations_4_ADDRESS 0x62C4u    /* 0762C4 */
#define goon_animations_4_sprites_ADDRESS 0x62D0u    /* 0762D0 */
#define goon_animations_4_sprites_2_ADDRESS 0x62D6u    /* 0762D6 */
#define goon_animations_5_ADDRESS 0x62DCu    /* 0762DC */
#define goon_animations_5_sprites_ADDRESS 0x62E8u    /* 0762E8 */
#define goon_animations_5_sprites_2_ADDRESS 0x62EEu    /* 0762EE */
#define goon_animations_6_ADDRESS 0x62F4u    /* 0762F4 */
#define goon_animations_6_sprites_ADDRESS 0x6300u    /* 076300 */
#define goon_animations_6_sprites_2_ADDRESS 0x6306u    /* 076306 */
#define goon_animations_7_ADDRESS 0x630Cu    /* 07630C */
#define goon_animations_7_sprites_ADDRESS 0x6318u    /* 076318 */
#define goon_animations_7_sprites_2_ADDRESS 0x631Eu    /* 07631E */
#define goon_animations_8_ADDRESS 0x632Au    /* 07632A */
#define goon_animations_8_sprites_ADDRESS 0x6342u    /* 076342 */
#define goon_animations_8_sprites_2_ADDRESS 0x634Eu    /* 07634E */
#define goon_animations_8_sprites_3_ADDRESS 0x635Au    /* 07635A */
#define goon_animations_8_sprites_4_ADDRESS 0x6366u    /* 076366 */
#define goon_animations_8_sprites_5_ADDRESS 0x6378u    /* 076378 */
#define goon_animations_9_ADDRESS 0x637Eu    /* 07637E */
#define goon_animations_9_sprites_ADDRESS 0x639Au    /* 07639A */
#define goon_animations_9_sprites_2_ADDRESS 0x63A6u    /* 0763A6 */
#define goon_animations_9_sprites_3_ADDRESS 0x63ACu    /* 0763AC */
#define goon_animations_9_sprites_4_ADDRESS 0x63B8u    /* 0763B8 */
#define goon_animations_10_ADDRESS 0x63C4u    /* 0763C4 */
#define goon_animations_10_sprites_ADDRESS 0x63D8u    /* 0763D8 */
#define goon_animations_10_sprites_2_ADDRESS 0x63DEu    /* 0763DE */
#define goon_animations_10_sprites_3_ADDRESS 0x63EAu    /* 0763EA */
#define goon_animations_10_sprites_4_ADDRESS 0x63F6u    /* 0763F6 */
#define goon_animations_11_ADDRESS 0x63FCu    /* 0763FC */
#define goon_animations_11_sprites_ADDRESS 0x6414u    /* 076414 */
#define goon_animations_11_sprites_2_ADDRESS 0x6426u    /* 076426 */
#define goon_animations_11_sprites_3_ADDRESS 0x6438u    /* 076438 */
#define goon_animations_11_sprites_4_ADDRESS 0x6444u    /* 076444 */
#define goon_animations_11_sprites_5_ADDRESS 0x6456u    /* 076456 */
#define goon_animations_12_ADDRESS 0x6468u    /* 076468 */
#define goon_animations_12_sprites_ADDRESS 0x6488u    /* 076488 */
#define goon_animations_12_sprites_2_ADDRESS 0x6494u    /* 076494 */
#define goon_animations_12_sprites_3_ADDRESS 0x64A6u    /* 0764A6 */
#define goon_animations_12_sprites_4_ADDRESS 0x64B8u    /* 0764B8 */
#define goon_animations_12_sprites_5_ADDRESS 0x64CAu    /* 0764CA */
#define goon_animations_12_sprites_6_ADDRESS 0x64D6u    /* 0764D6 */
#define goon_animations_13_ADDRESS 0x64E2u    /* 0764E2 */
#define goon_animations_13_sprites_ADDRESS 0x64EEu    /* 0764EE */
#define goon_animations_13_sprites_2_ADDRESS 0x64FAu    /* 0764FA */
#define goon_animations_14_ADDRESS 0x6506u    /* 076506 */
#define goon_animations_14_sprites_ADDRESS 0x652Au    /* 07652A */
#define goon_animations_14_sprites_2_ADDRESS 0x653Cu    /* 07653C */
#define goon_animations_14_sprites_3_ADDRESS 0x6548u    /* 076548 */
#define goon_animations_14_sprites_4_ADDRESS 0x655Au    /* 07655A */
#define goon_animations_14_sprites_5_ADDRESS 0x6560u    /* 076560 */
#define goon_animations_15_ADDRESS 0x6566u    /* 076566 */
#define goon_animations_15_sprites_ADDRESS 0x6582u    /* 076582 */
#define goon_animations_15_sprites_2_ADDRESS 0x658Eu    /* 07658E */
#define goon_animations_15_sprites_3_ADDRESS 0x659Au    /* 07659A */
#define goon_animations_15_sprites_4_ADDRESS 0x65B2u    /* 0765B2 */
#define goon_animations_16_ADDRESS 0x65CAu    /* 0765CA */
#define goon_animations_16_sprites_ADDRESS 0x65EEu    /* 0765EE */
#define goon_animations_16_sprites_2_ADDRESS 0x6600u    /* 076600 */
#define goon_animations_16_sprites_3_ADDRESS 0x660Cu    /* 07660C */
#define goon_animations_16_sprites_4_ADDRESS 0x6618u    /* 076618 */
#define goon_animations_16_sprites_5_ADDRESS 0x6624u    /* 076624 */
#define goon_animations_16_sprites_6_ADDRESS 0x6630u    /* 076630 */
#define goon_animations_16_sprites_7_ADDRESS 0x663Cu    /* 07663C */
#define goon_animations_16_sprites_8_ADDRESS 0x6648u    /* 076648 */
#define goon_animations_17_ADDRESS 0x665Au    /* 07665A */
#define goon_animations_17_sprites_ADDRESS 0x667Eu    /* 07667E */
#define goon_animations_17_sprites_2_ADDRESS 0x6684u    /* 076684 */
#define goon_animations_17_sprites_3_ADDRESS 0x668Au    /* 07668A */
#define goon_animations_17_sprites_4_ADDRESS 0x6690u    /* 076690 */
#define goon_animations_17_sprites_5_ADDRESS 0x6696u    /* 076696 */
#define goon_animations_17_sprites_6_ADDRESS 0x669Cu    /* 07669C */
#define goon_animations_17_sprites_7_ADDRESS 0x66A2u    /* 0766A2 */
#define goon_animations_17_sprites_8_ADDRESS 0x66A8u    /* 0766A8 */
#define goon_animations_18_ADDRESS 0x66AEu    /* 0766AE */
#define goon_animations_18_sprites_ADDRESS 0x66C6u    /* 0766C6 */
#define goon_animations_18_sprites_2_ADDRESS 0x66D2u    /* 0766D2 */
#define goon_animations_18_sprites_3_ADDRESS 0x66DEu    /* 0766DE */
#define goon_animations_18_sprites_4_ADDRESS 0x66E4u    /* 0766E4 */
#define goon_animations_19_ADDRESS 0x66EAu    /* 0766EA */
#define goon_animations_19_sprites_ADDRESS 0x66FEu    /* 0766FE */
#define goon_animations_19_sprites_2_ADDRESS 0x6704u    /* 076704 */
#define goon_animations_19_sprites_3_ADDRESS 0x6716u    /* 076716 */
#define goon_animations_56_ADDRESS 0x6728u    /* 076728 */
#define goon_animations_56_sprites_ADDRESS 0x673Cu    /* 07673C */
#define goon_animations_56_sprites_2_ADDRESS 0x6742u    /* 076742 */
#define goon_animations_56_sprites_3_ADDRESS 0x674Eu    /* 07674E */
#define goon_animations_33_ADDRESS 0x675Au    /* 07675A */
#define goon_animations_33_sprites_ADDRESS 0x6766u    /* 076766 */
#define goon_animations_33_sprites_2_ADDRESS 0x676Cu    /* 07676C */
#define goon_animations_34_ADDRESS 0x6772u    /* 076772 */
#define goon_animations_34_sprites_ADDRESS 0x6786u    /* 076786 */
#define goon_animations_34_sprites_2_ADDRESS 0x678Cu    /* 07678C */
#define goon_animations_34_sprites_3_ADDRESS 0x6798u    /* 076798 */
#define goon_animations_34_sprites_4_ADDRESS 0x67A4u    /* 0767A4 */
#define goon_animations_35_ADDRESS 0x67AAu    /* 0767AA */
#define goon_animations_35_sprites_ADDRESS 0x67C2u    /* 0767C2 */
#define goon_animations_35_sprites_2_ADDRESS 0x67C8u    /* 0767C8 */
#define goon_animations_35_sprites_3_ADDRESS 0x67DAu    /* 0767DA */
#define goon_animations_35_sprites_4_ADDRESS 0x67ECu    /* 0767EC */
#define goon_animations_36_ADDRESS 0x67F8u    /* 0767F8 */
#define goon_animations_36_sprites_ADDRESS 0x681Cu    /* 07681C */
#define goon_animations_36_sprites_2_ADDRESS 0x6822u    /* 076822 */
#define goon_animations_36_sprites_3_ADDRESS 0x682Eu    /* 07682E */
#define goon_animations_37_ADDRESS 0x683Au    /* 07683A */
#define goon_animations_37_sprites_ADDRESS 0x685Eu    /* 07685E */
#define goon_animations_37_sprites_2_ADDRESS 0x6864u    /* 076864 */
#define goon_animations_37_sprites_3_ADDRESS 0x6870u    /* 076870 */
#define goon_animations_37_sprites_4_ADDRESS 0x6882u    /* 076882 */
#define goon_animations_37_sprites_5_ADDRESS 0x6894u    /* 076894 */
#define goon_animations_37_sprites_6_ADDRESS 0x68ACu    /* 0768AC */
#define goon_animations_37_sprites_7_ADDRESS 0x68BEu    /* 0768BE */
#define goon_animations_37_sprites_8_ADDRESS 0x68D0u    /* 0768D0 */
#define goon_animations_38_ADDRESS 0x68DCu    /* 0768DC */
#define goon_animations_38_sprites_ADDRESS 0x68E8u    /* 0768E8 */
#define goon_animations_39_ADDRESS 0x68F4u    /* 0768F4 */
#define goon_animations_39_sprites_ADDRESS 0x6908u    /* 076908 */
#define goon_animations_39_sprites_2_ADDRESS 0x690Eu    /* 07690E */
#define goon_animations_39_sprites_3_ADDRESS 0x691Au    /* 07691A */
#define goon_animations_39_sprites_4_ADDRESS 0x6926u    /* 076926 */
#define goon_animations_40_ADDRESS 0x693Eu    /* 07693E */
#define goon_animations_40_sprites_ADDRESS 0x6946u    /* 076946 */
#define goon_animations_41_ADDRESS 0x694Cu    /* 07694C */
#define goon_animations_41_sprites_ADDRESS 0x6968u    /* 076968 */
#define goon_animations_41_sprites_2_ADDRESS 0x696Eu    /* 07696E */
#define goon_animations_41_sprites_3_ADDRESS 0x6980u    /* 076980 */
#define goon_animations_41_sprites_4_ADDRESS 0x6992u    /* 076992 */
#define goon_animations_41_sprites_5_ADDRESS 0x699Eu    /* 07699E */
#define goon_animations_43_ADDRESS 0x69B0u    /* 0769B0 */
#define goon_animations_43_sprites_ADDRESS 0x69DCu    /* 0769DC */
#define goon_animations_43_sprites_2_ADDRESS 0x69E2u    /* 0769E2 */
#define goon_animations_43_sprites_3_ADDRESS 0x69F4u    /* 0769F4 */
#define goon_animations_43_sprites_4_ADDRESS 0x6A00u    /* 076A00 */
#define goon_animations_43_sprites_5_ADDRESS 0x6A0Cu    /* 076A0C */
#define goon_animations_43_sprites_6_ADDRESS 0x6A18u    /* 076A18 */
#define goon_animations_43_sprites_7_ADDRESS 0x6A24u    /* 076A24 */
#define goon_animations_43_sprites_8_ADDRESS 0x6A30u    /* 076A30 */
#define goon_animations_43_sprites_9_ADDRESS 0x6A3Cu    /* 076A3C */
#define goon_animations_44_ADDRESS 0x6A42u    /* 076A42 */
#define goon_animations_44_sprites_ADDRESS 0x6A5Eu    /* 076A5E */
#define goon_animations_44_sprites_2_ADDRESS 0x6A70u    /* 076A70 */
#define goon_animations_44_sprites_3_ADDRESS 0x6A7Cu    /* 076A7C */
#define goon_animations_45_ADDRESS 0x6A8Eu    /* 076A8E */
#define goon_animations_45_sprites_ADDRESS 0x6A96u    /* 076A96 */
#define goon_animations_46_ADDRESS 0x6A9Cu    /* 076A9C */
#define goon_animations_46_sprites_ADDRESS 0x6AB8u    /* 076AB8 */
#define goon_animations_46_sprites_2_ADDRESS 0x6ACAu    /* 076ACA */
#define goon_animations_46_sprites_3_ADDRESS 0x6ADCu    /* 076ADC */
#define goon_animations_47_ADDRESS 0x6AE8u    /* 076AE8 */
#define goon_animations_47_sprites_ADDRESS 0x6B00u    /* 076B00 */
#define goon_animations_48_ADDRESS 0x6B0Cu    /* 076B0C */
#define goon_animations_48_sprites_ADDRESS 0x6B28u    /* 076B28 */
#define goon_animations_48_sprites_2_ADDRESS 0x6B34u    /* 076B34 */
#define goon_animations_48_sprites_3_ADDRESS 0x6B3Au    /* 076B3A */
#define goon_animations_48_sprites_4_ADDRESS 0x6B46u    /* 076B46 */
#define goon_animations_49_ADDRESS 0x6B4Cu    /* 076B4C */
#define goon_animations_49_sprites_ADDRESS 0x6B60u    /* 076B60 */
#define goon_animations_49_sprites_2_ADDRESS 0x6B66u    /* 076B66 */
#define goon_animations_49_sprites_3_ADDRESS 0x6B6Cu    /* 076B6C */
#define goon_animations_49_sprites_4_ADDRESS 0x6B72u    /* 076B72 */
#define goon_animations_50_ADDRESS 0x6B78u    /* 076B78 */
#define goon_animations_50_sprites_ADDRESS 0x6B90u    /* 076B90 */
#define goon_animations_50_sprites_2_ADDRESS 0x6B96u    /* 076B96 */
#define goon_animations_50_sprites_3_ADDRESS 0x6B9Cu    /* 076B9C */
#define goon_animations_50_sprites_4_ADDRESS 0x6BA2u    /* 076BA2 */
#define goon_animations_20_ADDRESS 0x6BAEu    /* 076BAE */
#define goon_animations_20_sprites_ADDRESS 0x6BB6u    /* 076BB6 */
#define goon_animations_51_ADDRESS 0x6BBCu    /* 076BBC */
#define goon_animations_51_sprites_ADDRESS 0x6BE0u    /* 076BE0 */
#define goon_animations_51_sprites_2_ADDRESS 0x6BF8u    /* 076BF8 */
#define goon_animations_51_sprites_3_ADDRESS 0x6C10u    /* 076C10 */
#define goon_animations_51_sprites_4_ADDRESS 0x6C28u    /* 076C28 */
#define goon_animations_51_sprites_5_ADDRESS 0x6C40u    /* 076C40 */
#define goon_animations_51_sprites_6_ADDRESS 0x6C58u    /* 076C58 */
#define goon_animations_51_sprites_7_ADDRESS 0x6C70u    /* 076C70 */
#define goon_animations_51_sprites_8_ADDRESS 0x6C88u    /* 076C88 */
#define goon_animations_52_ADDRESS 0x6CA0u    /* 076CA0 */
#define goon_animations_52_sprites_ADDRESS 0x6CB4u    /* 076CB4 */
#define goon_animations_52_sprites_2_ADDRESS 0x6CBAu    /* 076CBA */
#define goon_animations_52_sprites_3_ADDRESS 0x6CC0u    /* 076CC0 */
#define goon_animations_52_sprites_4_ADDRESS 0x6CC6u    /* 076CC6 */
#define goon_animations_21_ADDRESS 0x6CCCu    /* 076CCC */
#define goon_animations_21_sprites_ADDRESS 0x6CDCu    /* 076CDC */
#define goon_animations_21_sprites_2_ADDRESS 0x6CE2u    /* 076CE2 */
#define goon_animations_21_sprites_3_ADDRESS 0x6CE8u    /* 076CE8 */
#define goon_animations_22_ADDRESS 0x6CEEu    /* 076CEE */
#define goon_animations_22_sprites_ADDRESS 0x6CFEu    /* 076CFE */
#define goon_animations_22_sprites_2_ADDRESS 0x6D04u    /* 076D04 */
#define goon_animations_22_sprites_3_ADDRESS 0x6D0Au    /* 076D0A */
#define goon_animations_53_ADDRESS 0x6D10u    /* 076D10 */
#define goon_animations_53_sprites_ADDRESS 0x6D34u    /* 076D34 */
#define goon_animations_53_sprites_2_ADDRESS 0x6D4Cu    /* 076D4C */
#define goon_animations_53_sprites_3_ADDRESS 0x6D64u    /* 076D64 */
#define goon_animations_53_sprites_4_ADDRESS 0x6D7Cu    /* 076D7C */
#define goon_animations_53_sprites_5_ADDRESS 0x6D94u    /* 076D94 */
#define goon_animations_53_sprites_6_ADDRESS 0x6DACu    /* 076DAC */
#define goon_animations_53_sprites_7_ADDRESS 0x6DC4u    /* 076DC4 */
#define goon_animations_53_sprites_8_ADDRESS 0x6DDCu    /* 076DDC */
#define goon_animations_54_ADDRESS 0x6DF4u    /* 076DF4 */
#define goon_animations_54_sprites_ADDRESS 0x6DFCu    /* 076DFC */
#define goon_animations_55_ADDRESS 0x6E0Eu    /* 076E0E */
#define goon_animations_55_sprites_ADDRESS 0x6E1Au    /* 076E1A */
#define goon_animations_55_sprites_2_ADDRESS 0x6E20u    /* 076E20 */
#define goon_animations_23_ADDRESS 0x6E26u    /* 076E26 */
#define goon_animations_23_sprites_ADDRESS 0x6E3Au    /* 076E3A */
#define goon_animations_23_sprites_2_ADDRESS 0x6E52u    /* 076E52 */
#define goon_animations_23_sprites_3_ADDRESS 0x6E6Au    /* 076E6A */
#define goon_animations_23_sprites_4_ADDRESS 0x6E82u    /* 076E82 */
#define goon_animations_24_ADDRESS 0x6E9Au    /* 076E9A */
#define goon_animations_66_ADDRESS 0x6EAEu    /* 076EAE */
#define goon_animations_66_sprites_ADDRESS 0x6ECAu    /* 076ECA */
#define goon_animations_66_sprites_2_ADDRESS 0x6EE2u    /* 076EE2 */
#define goon_animations_66_sprites_3_ADDRESS 0x6EFAu    /* 076EFA */
#define goon_animations_66_sprites_4_ADDRESS 0x6F12u    /* 076F12 */
#define goon_animations_66_sprites_5_ADDRESS 0x6F2Au    /* 076F2A */
#define goon_animations_67_ADDRESS 0x6F42u    /* 076F42 */
#define goon_animations_67_sprites_ADDRESS 0x6F5Au    /* 076F5A */
#define goon_animations_70_ADDRESS 0x6F78u    /* 076F78 */
#define goon_animations_70_sprites_ADDRESS 0x6F94u    /* 076F94 */
#define goon_animations_70_sprites_2_ADDRESS 0x6FB2u    /* 076FB2 */
#define goon_animations_70_sprites_3_ADDRESS 0x6FCAu    /* 076FCA */
#define goon_animations_70_sprites_4_ADDRESS 0x6FE2u    /* 076FE2 */
#define goon_animations_70_sprites_5_ADDRESS 0x6FFAu    /* 076FFA */
#define goon_animations_71_ADDRESS 0x7012u    /* 077012 */
#define goon_animations_71_sprites_ADDRESS 0x702Au    /* 07702A */
#define goon_animations_64_ADDRESS 0x7042u    /* 077042 */
#define goon_animations_64_sprites_ADDRESS 0x705Eu    /* 07705E */
#define goon_animations_64_sprites_2_ADDRESS 0x707Cu    /* 07707C */
#define goon_animations_64_sprites_3_ADDRESS 0x7094u    /* 077094 */
#define goon_animations_64_sprites_4_ADDRESS 0x70B2u    /* 0770B2 */
#define goon_animations_64_sprites_5_ADDRESS 0x70D0u    /* 0770D0 */
#define goon_animations_65_ADDRESS 0x70EEu    /* 0770EE */
#define goon_animations_65_sprites_ADDRESS 0x7106u    /* 077106 */
#define goon_animations_68_ADDRESS 0x711Eu    /* 07711E */
#define goon_animations_68_sprites_ADDRESS 0x713Au    /* 07713A */
#define goon_animations_68_sprites_2_ADDRESS 0x7158u    /* 077158 */
#define goon_animations_68_sprites_3_ADDRESS 0x7170u    /* 077170 */
#define goon_animations_68_sprites_4_ADDRESS 0x718Eu    /* 07718E */
#define goon_animations_68_sprites_5_ADDRESS 0x71ACu    /* 0771AC */
#define goon_animations_69_ADDRESS 0x71CAu    /* 0771CA */
#define goon_animations_69_sprites_ADDRESS 0x71E2u    /* 0771E2 */
#define goon_animations_57_ADDRESS 0x71FAu    /* 0771FA */
#define goon_animations_57_sprites_ADDRESS 0x7212u    /* 077212 */
#define goon_animations_57_sprites_2_ADDRESS 0x721Eu    /* 07721E */
#define goon_animations_57_sprites_3_ADDRESS 0x7224u    /* 077224 */
#define goon_animations_57_sprites_4_ADDRESS 0x7230u    /* 077230 */
#define goon_animations_57_sprites_5_ADDRESS 0x7242u    /* 077242 */
#define goon_animations_58_ADDRESS 0x724Eu    /* 07724E */
#define goon_animations_58_sprites_ADDRESS 0x725Eu    /* 07725E */
#define goon_animations_58_sprites_2_ADDRESS 0x726Au    /* 07726A */
#define goon_animations_59_ADDRESS 0x7276u    /* 077276 */
#define goon_animations_59_sprites_ADDRESS 0x72A2u    /* 0772A2 */
#define goon_animations_59_sprites_2_ADDRESS 0x72A8u    /* 0772A8 */
#define goon_animations_59_sprites_3_ADDRESS 0x72AEu    /* 0772AE */
#define goon_animations_59_sprites_4_ADDRESS 0x72BAu    /* 0772BA */
#define goon_animations_59_sprites_5_ADDRESS 0x72C6u    /* 0772C6 */
#define goon_animations_59_sprites_6_ADDRESS 0x72CCu    /* 0772CC */
#define goon_animations_59_sprites_7_ADDRESS 0x72D2u    /* 0772D2 */
#define goon_animations_59_sprites_8_ADDRESS 0x72D8u    /* 0772D8 */
#define goon_animations_59_sprites_9_ADDRESS 0x72DEu    /* 0772DE */
#define goon_animations_59_sprites_10_ADDRESS 0x72E4u    /* 0772E4 */
#define goon_with_umbrella_animations_ADDRESS 0x72EAu    /* 0772EA */
#define goon_with_umbrella_animations_0_ADDRESS 0x733Au    /* 07733A */
#define goon_with_umbrella_animations_0_sprites_ADDRESS 0x7342u    /* 077342 */
#define goon_with_umbrella_animations_1_ADDRESS 0x7354u    /* 077354 */
#define goon_with_umbrella_animations_1_sprites_ADDRESS 0x7378u    /* 077378 */
#define goon_with_umbrella_animations_1_sprites_2_ADDRESS 0x738Au    /* 07738A */
#define goon_with_umbrella_animations_1_sprites_3_ADDRESS 0x739Cu    /* 07739C */
#define goon_with_umbrella_animations_1_sprites_4_ADDRESS 0x73AEu    /* 0773AE */
#define goon_with_umbrella_animations_1_sprites_5_ADDRESS 0x73C0u    /* 0773C0 */
#define goon_with_umbrella_animations_1_sprites_6_ADDRESS 0x73D2u    /* 0773D2 */
#define goon_with_umbrella_animations_1_sprites_7_ADDRESS 0x73E4u    /* 0773E4 */
#define goon_with_umbrella_animations_1_sprites_8_ADDRESS 0x73F6u    /* 0773F6 */
#define goon_with_umbrella_animations_2_ADDRESS 0x7408u    /* 077408 */
#define goon_with_umbrella_animations_2_sprites_ADDRESS 0x742Cu    /* 07742C */
#define goon_with_umbrella_animations_2_sprites_2_ADDRESS 0x743Eu    /* 07743E */
#define goon_with_umbrella_animations_2_sprites_3_ADDRESS 0x7450u    /* 077450 */
#define goon_with_umbrella_animations_2_sprites_4_ADDRESS 0x7462u    /* 077462 */
#define goon_with_umbrella_animations_2_sprites_5_ADDRESS 0x7474u    /* 077474 */
#define goon_with_umbrella_animations_2_sprites_6_ADDRESS 0x7486u    /* 077486 */
#define goon_with_umbrella_animations_2_sprites_7_ADDRESS 0x7498u    /* 077498 */
#define goon_with_umbrella_animations_2_sprites_8_ADDRESS 0x74AAu    /* 0774AA */
#define goon_with_umbrella_animations_3_ADDRESS 0x74BCu    /* 0774BC */
#define goon_with_umbrella_animations_3_sprites_ADDRESS 0x74E0u    /* 0774E0 */
#define goon_with_umbrella_animations_3_sprites_2_ADDRESS 0x74F2u    /* 0774F2 */
#define goon_with_umbrella_animations_3_sprites_3_ADDRESS 0x7504u    /* 077504 */
#define goon_with_umbrella_animations_3_sprites_4_ADDRESS 0x7516u    /* 077516 */
#define goon_with_umbrella_animations_3_sprites_5_ADDRESS 0x7528u    /* 077528 */
#define goon_with_umbrella_animations_3_sprites_6_ADDRESS 0x753Au    /* 07753A */
#define goon_with_umbrella_animations_3_sprites_7_ADDRESS 0x754Cu    /* 07754C */
#define goon_with_umbrella_animations_3_sprites_8_ADDRESS 0x755Eu    /* 07755E */
#define goon_with_umbrella_animations_4_ADDRESS 0x7570u    /* 077570 */
#define goon_with_umbrella_animations_4_sprites_ADDRESS 0x757Cu    /* 07757C */
#define goon_with_umbrella_animations_4_sprites_2_ADDRESS 0x758Eu    /* 07758E */
#define goon_with_umbrella_animations_5_ADDRESS 0x75A0u    /* 0775A0 */
#define goon_with_umbrella_animations_5_sprites_ADDRESS 0x75ACu    /* 0775AC */
#define goon_with_umbrella_animations_5_sprites_2_ADDRESS 0x75BEu    /* 0775BE */
#define goon_with_umbrella_animations_6_ADDRESS 0x75D0u    /* 0775D0 */
#define goon_with_umbrella_animations_6_sprites_ADDRESS 0x75DCu    /* 0775DC */
#define goon_with_umbrella_animations_6_sprites_2_ADDRESS 0x75EEu    /* 0775EE */
#define goon_with_umbrella_animations_7_ADDRESS 0x7600u    /* 077600 */
#define goon_with_umbrella_animations_7_sprites_ADDRESS 0x760Cu    /* 07760C */
#define goon_with_umbrella_animations_7_sprites_2_ADDRESS 0x7624u    /* 077624 */
#define goon_with_umbrella_animations_9_ADDRESS 0x763Cu    /* 07763C */
#define goon_with_umbrella_animations_9_sprites_ADDRESS 0x7658u    /* 077658 */
#define goon_with_umbrella_animations_9_sprites_2_ADDRESS 0x7670u    /* 077670 */
#define goon_with_umbrella_animations_9_sprites_3_ADDRESS 0x7682u    /* 077682 */
#define goon_with_umbrella_animations_9_sprites_4_ADDRESS 0x769Au    /* 07769A */
#define goon_with_umbrella_animations_10_ADDRESS 0x76B2u    /* 0776B2 */
#define goon_with_umbrella_animations_10_sprites_ADDRESS 0x76C6u    /* 0776C6 */
#define goon_with_umbrella_animations_10_sprites_2_ADDRESS 0x76D8u    /* 0776D8 */
#define goon_with_umbrella_animations_10_sprites_3_ADDRESS 0x76F0u    /* 0776F0 */
#define goon_with_umbrella_animations_10_sprites_4_ADDRESS 0x7708u    /* 077708 */
#define goon_with_umbrella_animations_11_ADDRESS 0x771Au    /* 07771A */
#define goon_with_umbrella_animations_11_sprites_ADDRESS 0x7732u    /* 077732 */
#define goon_with_umbrella_animations_11_sprites_2_ADDRESS 0x7750u    /* 077750 */
#define goon_with_umbrella_animations_11_sprites_3_ADDRESS 0x776Eu    /* 07776E */
#define goon_with_umbrella_animations_11_sprites_4_ADDRESS 0x7786u    /* 077786 */
#define goon_with_umbrella_animations_11_sprites_5_ADDRESS 0x77A4u    /* 0777A4 */
#define goon_with_umbrella_animations_12_ADDRESS 0x77C2u    /* 0777C2 */
#define goon_with_umbrella_animations_12_sprites_ADDRESS 0x77E2u    /* 0777E2 */
#define goon_with_umbrella_animations_12_sprites_2_ADDRESS 0x7800u    /* 077800 */
#define goon_with_umbrella_animations_12_sprites_3_ADDRESS 0x781Eu    /* 07781E */
#define goon_with_umbrella_animations_12_sprites_4_ADDRESS 0x7836u    /* 077836 */
#define goon_with_umbrella_animations_13_ADDRESS 0x784Eu    /* 07784E */
#define goon_with_umbrella_animations_13_sprites_ADDRESS 0x785Au    /* 07785A */
#define goon_with_umbrella_animations_13_sprites_2_ADDRESS 0x7872u    /* 077872 */
#define goon_with_umbrella_animations_14_ADDRESS 0x788Au    /* 07788A */
#define goon_with_umbrella_animations_14_sprites_ADDRESS 0x78AEu    /* 0778AE */
#define goon_with_umbrella_animations_14_sprites_2_ADDRESS 0x78CCu    /* 0778CC */
#define goon_with_umbrella_animations_14_sprites_3_ADDRESS 0x78E4u    /* 0778E4 */
#define goon_with_umbrella_animations_14_sprites_4_ADDRESS 0x7902u    /* 077902 */
#define goon_with_umbrella_animations_14_sprites_5_ADDRESS 0x7914u    /* 077914 */
#define goon_with_umbrella_animations_15_ADDRESS 0x7926u    /* 077926 */
#define goon_with_umbrella_animations_15_sprites_ADDRESS 0x7942u    /* 077942 */
#define goon_with_umbrella_animations_15_sprites_2_ADDRESS 0x795Au    /* 07795A */
#define goon_with_umbrella_animations_15_sprites_3_ADDRESS 0x7972u    /* 077972 */
#define goon_with_umbrella_animations_15_sprites_4_ADDRESS 0x7996u    /* 077996 */
#define goon_with_umbrella_animations_16_ADDRESS 0x79BAu    /* 0779BA */
#define goon_with_umbrella_animations_16_sprites_ADDRESS 0x79DEu    /* 0779DE */
#define goon_with_umbrella_animations_16_sprites_2_ADDRESS 0x79EAu    /* 0779EA */
#define goon_with_umbrella_animations_16_sprites_3_ADDRESS 0x79F6u    /* 0779F6 */
#define goon_with_umbrella_animations_16_sprites_4_ADDRESS 0x7A02u    /* 077A02 */
#define goon_with_umbrella_animations_16_sprites_5_ADDRESS 0x7A0Eu    /* 077A0E */
#define goon_with_umbrella_animations_16_sprites_6_ADDRESS 0x7A1Au    /* 077A1A */
#define goon_with_umbrella_animations_16_sprites_7_ADDRESS 0x7A26u    /* 077A26 */
#define goon_with_umbrella_animations_16_sprites_8_ADDRESS 0x7A32u    /* 077A32 */
#define goon_with_umbrella_animations_17_ADDRESS 0x7A44u    /* 077A44 */
#define goon_with_umbrella_animations_17_sprites_ADDRESS 0x7A5Cu    /* 077A5C */
#define goon_with_umbrella_animations_17_sprites_2_ADDRESS 0x7A74u    /* 077A74 */
#define goon_with_umbrella_animations_17_sprites_3_ADDRESS 0x7A80u    /* 077A80 */
#define goon_with_umbrella_animations_18_ADDRESS 0x7A8Cu    /* 077A8C */
#define goon_with_umbrella_animations_18_sprites_ADDRESS 0x7AACu    /* 077AAC */
#define goon_with_umbrella_animations_18_sprites_2_ADDRESS 0x7AC4u    /* 077AC4 */
#define goon_with_umbrella_animations_18_sprites_3_ADDRESS 0x7AD0u    /* 077AD0 */
#define goon_with_umbrella_animations_18_sprites_4_ADDRESS 0x7AE2u    /* 077AE2 */
#define goon_with_umbrella_animations_18_sprites_5_ADDRESS 0x7AF4u    /* 077AF4 */
#define goon_with_umbrella_animations_18_sprites_6_ADDRESS 0x7B06u    /* 077B06 */
#define goon_with_umbrella_animations_19_ADDRESS 0x7B18u    /* 077B18 */
#define goon_with_umbrella_animations_19_sprites_ADDRESS 0x7B30u    /* 077B30 */
#define goon_with_umbrella_animations_19_sprites_2_ADDRESS 0x7B42u    /* 077B42 */
#define goon_with_umbrella_animations_19_sprites_3_ADDRESS 0x7B66u    /* 077B66 */
#define goon_with_umbrella_animations_19_sprites_4_ADDRESS 0x7B7Eu    /* 077B7E */
#define goon_with_umbrella_animations_32_ADDRESS 0x7B8Au    /* 077B8A */
#define goon_with_umbrella_animations_32_sprites_ADDRESS 0x7B9Eu    /* 077B9E */
#define goon_with_umbrella_animations_32_sprites_2_ADDRESS 0x7BB0u    /* 077BB0 */
#define goon_with_umbrella_animations_33_ADDRESS 0x7BC2u    /* 077BC2 */
#define goon_with_umbrella_animations_33_sprites_ADDRESS 0x7BDEu    /* 077BDE */
#define goon_with_umbrella_animations_33_sprites_2_ADDRESS 0x7BF6u    /* 077BF6 */
#define goon_with_umbrella_animations_33_sprites_3_ADDRESS 0x7C08u    /* 077C08 */
#define goon_with_umbrella_animations_33_sprites_4_ADDRESS 0x7C20u    /* 077C20 */
#define goon_with_umbrella_animations_34_ADDRESS 0x7C32u    /* 077C32 */
#define goon_with_umbrella_animations_34_sprites_ADDRESS 0x7C3Au    /* 077C3A */
#define goon_with_umbrella_animations_35_ADDRESS 0x7C46u    /* 077C46 */
#define goon_with_umbrella_animations_36_ADDRESS 0x7C5Au    /* 077C5A */
#define goon_with_umbrella_animations_37_ADDRESS 0x7C62u    /* 077C62 */
#define goon_with_umbrella_animations_38_ADDRESS 0x7C6Au    /* 077C6A */
#define goon_with_umbrella_animations_38_sprites_ADDRESS 0x7C72u    /* 077C72 */
#define goon_with_umbrella_animations_20_ADDRESS 0x7C7Eu    /* 077C7E */
#define goon_with_umbrella_animations_20_sprites_ADDRESS 0x7C86u    /* 077C86 */
#define goon_with_umbrella_animations_39_ADDRESS 0x7C92u    /* 077C92 */
#define goon_with_umbrella_animations_39_sprites_ADDRESS 0x7C9Au    /* 077C9A */
#define goon_with_umbrella_animations_39_sprites_fill_ADDRESS 0x7CA6u    /* 077CA6 */
#define fixed_program_start_ADDRESS 0x8000u    /* 078000 */
#define object_take_special_hit_as_code_read_as_tiles_ADDRESS 0x8593u    /* 078593 */
#define vector_enemy_think_as_code_read_as_tiles_ADDRESS 0x85DBu    /* 0785DB */
#define vector_goon_setup_as_code_read_as_tiles_ADDRESS 0x85F9u    /* 0785F9 */
#define vector_check_landing_as_code_read_as_tiles_ADDRESS 0x8662u    /* 078662 */
#define unused_vector_take_floor_priority_as_code_read_as_a_map_ADDRESS 0x8668u    /* 078668 */
#define request_palette_sets_as_code_read_as_tiles_ADDRESS 0xBAECu    /* 07BAEC */
#define run_palette_jobs_table_ADDRESS 0xBCAAu    /* 07BCAA */
#define palette_job_load_sets_as_code_read_as_tiles_ADDRESS 0xBCBAu    /* 07BCBA */
#define enemy_walk_to_target_side_step_fill_ADDRESS 0xD8B9u    /* 07D8B9 */
#define enemy_line_up_in_x_as_code_read_as_a_map_ADDRESS 0xDA7Bu    /* 07DA7B */
#define enemy_hurt_get_up_fill_ADDRESS 0xE2DBu    /* 07E2DB */
#define default_high_scores_ADDRESS 0xE380u    /* 07E380 */
#define ram_check_bad_texts_ADDRESS 0xE3D0u    /* 07E3D0 */
#define boot_table_2_ADDRESS 0xE3FBu    /* 07E3FB */
#define check_result_texts_ADDRESS 0xE41Bu    /* 07E41B */
#define irq_handler_table_ADDRESS 0xE42Bu    /* 07E42B */
#define test_mode_table_ADDRESS 0xE431u    /* 07E431 */
#define hurt_effect_rows_table_ADDRESS 0xE530u    /* 07E530 */
#define hurt_effect_rows_table_2_ADDRESS 0xE53Cu    /* 07E53C */
#define hurt_effect_rows_table_3_ADDRESS 0xE548u    /* 07E548 */
#define hurt_effect_rows_table_4_ADDRESS 0xE554u    /* 07E554 */
#define hurt_effect_rows_table_5_ADDRESS 0xE560u    /* 07E560 */
#define job_clear_screen_table_ADDRESS 0xE56Cu    /* 07E56C */
#define attract_table_ADDRESS 0xE66Bu    /* 07E66B */
#define attract_opening_scene_table_ADDRESS 0xE677u    /* 07E677 */
#define attract_title_table_ADDRESS 0xE67Fu    /* 07E67F */
#define attract_demo_table_ADDRESS 0xE687u    /* 07E687 */
#define attract_high_scores_table_ADDRESS 0xE68Bu    /* 07E68B */
#define attract_warning_table_ADDRESS 0xE693u    /* 07E693 */
#define attract_coin_title_table_ADDRESS 0xE69Bu    /* 07E69B */
#define demos_0_ADDRESS 0xE6A7u    /* 07E6A7 */
#define demos_1_ADDRESS 0xE6B3u    /* 07E6B3 */
#define demos_2_ADDRESS 0xE6BFu    /* 07E6BF */
#define game_mode_frame_table_ADDRESS 0xE6CBu    /* 07E6CB */
#define game_start_phase_table_ADDRESS 0xE6D5u    /* 07E6D5 */
#define game_run_step_table_ADDRESS 0xE6D9u    /* 07E6D9 */
#define step_portraits_table_ADDRESS 0xE6FBu    /* 07E6FB */
#define step_story_1_table_ADDRESS 0xE701u    /* 07E701 */
#define step_stage_1_table_ADDRESS 0xE707u    /* 07E707 */
#define step_bonus_1_table_ADDRESS 0xE717u    /* 07E717 */
#define step_stage_2_table_ADDRESS 0xE721u    /* 07E721 */
#define step_stage_3_forest_table_ADDRESS 0xE731u    /* 07E731 */
#define step_stage_3_cemetery_table_ADDRESS 0xE743u    /* 07E743 */
#define step_stage_4_table_ADDRESS 0xE751u    /* 07E751 */
#define step_stage_5_table_ADDRESS 0xE761u    /* 07E761 */
#define step_stage_6_table_ADDRESS 0xE773u    /* 07E773 */
#define step_bonus_2_table_ADDRESS 0xE785u    /* 07E785 */
#define step_stage_7_table_ADDRESS 0xE791u    /* 07E791 */
#define step_stage_8_table_ADDRESS 0xE7A3u    /* 07E7A3 */
#define step_ending_table_ADDRESS 0xE7C1u    /* 07E7C1 */
#define game_over_phase_table_ADDRESS 0xE7C7u    /* 07E7C7 */
#define name_entry_phase_table_ADDRESS 0xE7CDu    /* 07E7CD */
#define player_status_handlers_ADDRESS 0xE803u    /* 07E803 */
#define game_phase_checks_ADDRESS 0xE80Fu    /* 07E80F */
#define stage_music_lists_ADDRESS 0xE89Du    /* 07E89D */
#define resumed_stage_music_lists_ADDRESS 0xE8B5u    /* 07E8B5 */
#define palette_effect_directions_ADDRESS 0xE971u    /* 07E971 */
#define palette_effect_commands_ADDRESS 0xE975u    /* 07E975 */
#define palette_fade_directions_ADDRESS 0xE97Bu    /* 07E97B */
#define palette_sets_0_ADDRESS 0xE9E7u    /* 07E9E7 */
#define palette_sets_1_ADDRESS 0xE9FBu    /* 07E9FB */
#define palette_sets_2_ADDRESS 0xEA0Fu    /* 07EA0F */
#define palette_sets_3_ADDRESS 0xEA23u    /* 07EA23 */
#define palette_sets_4_ADDRESS 0xEA37u    /* 07EA37 */
#define palette_sets_5_ADDRESS 0xEA4Bu    /* 07EA4B */
#define palette_sets_6_ADDRESS 0xEA5Fu    /* 07EA5F */
#define palette_sets_8_ADDRESS 0xEA73u    /* 07EA73 */
#define palette_sets_9_ADDRESS 0xEA87u    /* 07EA87 */
#define palette_sets_10_ADDRESS 0xEA9Bu    /* 07EA9B */
#define palette_sets_11_ADDRESS 0xEAAFu    /* 07EAAF */
#define palette_sets_12_ADDRESS 0xEAC3u    /* 07EAC3 */
#define palette_sets_13_ADDRESS 0xEAD7u    /* 07EAD7 */
#define palette_sets_high_0_ADDRESS 0xEB11u    /* 07EB11 */
#define palette_sets_high_1_ADDRESS 0xEB25u    /* 07EB25 */
#define palette_sets_high_2_ADDRESS 0xEB39u    /* 07EB39 */
#define palette_sets_high_3_ADDRESS 0xEB4Du    /* 07EB4D */
#define palette_sets_high_4_ADDRESS 0xEB61u    /* 07EB61 */
#define palette_sets_high_5_ADDRESS 0xEB75u    /* 07EB75 */
#define palette_sets_high_6_ADDRESS 0xEB89u    /* 07EB89 */
#define palette_sets_high_7_ADDRESS 0xEB9Du    /* 07EB9D */
#define palette_sets_high_8_ADDRESS 0xEBB1u    /* 07EBB1 */
#define palette_sets_high_9_ADDRESS 0xEBC5u    /* 07EBC5 */
#define palette_sets_high_10_ADDRESS 0xEBD9u    /* 07EBD9 */
#define palette_sets_high_11_ADDRESS 0xEBEDu    /* 07EBED */
#define palette_sets_high_12_ADDRESS 0xEC01u    /* 07EC01 */
#define palette_sets_high_13_ADDRESS 0xEC15u    /* 07EC15 */
#define palette_sets_high_14_ADDRESS 0xEC29u    /* 07EC29 */
#define palette_sets_high_15_ADDRESS 0xEC3Du    /* 07EC3D */
#define palette_sets_high_16_ADDRESS 0xEC51u    /* 07EC51 */
#define palette_sets_high_17_ADDRESS 0xEC65u    /* 07EC65 */
#define palette_sets_high_18_ADDRESS 0xEC79u    /* 07EC79 */
#define draw_scrolled_layer_edges_table_ADDRESS 0xEC8Du    /* 07EC8D */
#define draw_scrolled_layer_edges_table_2_ADDRESS 0xEC95u    /* 07EC95 */
#define find_map_block_table_ADDRESS 0xECC5u    /* 07ECC5 */
#define block_scenes_a_0_ADDRESS 0xECD1u    /* 07ECD1 */
#define block_scenes_a_1_ADDRESS 0xECE1u    /* 07ECE1 */
#define block_scenes_a_3_ADDRESS 0xECE5u    /* 07ECE5 */
#define block_scenes_b_0_ADDRESS 0xECF1u    /* 07ECF1 */
#define block_scenes_b_1_ADDRESS 0xECF5u    /* 07ECF5 */
#define map_scenes_a_0_ADDRESS 0xED01u    /* 07ED01 */
#define map_scenes_a_2_ADDRESS 0xED11u    /* 07ED11 */
#define map_scenes_a_3_ADDRESS 0xED15u    /* 07ED15 */
#define map_scenes_b_0_ADDRESS 0xED21u    /* 07ED21 */
#define map_scenes_b_1_ADDRESS 0xED25u    /* 07ED25 */
#define block_scenes_a_high_0_ADDRESS 0xED47u    /* 07ED47 */
#define block_scenes_a_high_1_ADDRESS 0xED4Bu    /* 07ED4B */
#define block_scenes_a_high_2_ADDRESS 0xED53u    /* 07ED53 */
#define block_scenes_a_high_3_ADDRESS 0xED57u    /* 07ED57 */
#define block_scenes_a_high_4_ADDRESS 0xED5Fu    /* 07ED5F */
#define block_scenes_a_high_5_ADDRESS 0xED6Fu    /* 07ED6F */
#define block_scenes_a_high_7_ADDRESS 0xED77u    /* 07ED77 */
#define block_scenes_a_high_8_ADDRESS 0xED7Bu    /* 07ED7B */
#define block_scenes_a_high_9_ADDRESS 0xED7Fu    /* 07ED7F */
#define block_scenes_a_high_10_ADDRESS 0xED93u    /* 07ED93 */
#define block_scenes_a_high_11_ADDRESS 0xED97u    /* 07ED97 */
#define block_scenes_a_high_12_ADDRESS 0xEDA3u    /* 07EDA3 */
#define block_scenes_a_high_13_ADDRESS 0xEDA7u    /* 07EDA7 */
#define block_scenes_a_high_14_ADDRESS 0xEDB7u    /* 07EDB7 */
#define block_scenes_b_high_0_ADDRESS 0xEDD9u    /* 07EDD9 */
#define block_scenes_b_high_1_ADDRESS 0xEDDDu    /* 07EDDD */
#define block_scenes_b_high_2_ADDRESS 0xEDE1u    /* 07EDE1 */
#define block_scenes_b_high_3_ADDRESS 0xEDE5u    /* 07EDE5 */
#define block_scenes_b_high_4_ADDRESS 0xEDE9u    /* 07EDE9 */
#define block_scenes_b_high_5_ADDRESS 0xEDF9u    /* 07EDF9 */
#define block_scenes_b_high_7_ADDRESS 0xEDFDu    /* 07EDFD */
#define block_scenes_b_high_8_ADDRESS 0xEE01u    /* 07EE01 */
#define block_scenes_b_high_9_ADDRESS 0xEE05u    /* 07EE05 */
#define block_scenes_b_high_10_ADDRESS 0xEE15u    /* 07EE15 */
#define block_scenes_b_high_11_ADDRESS 0xEE19u    /* 07EE19 */
#define block_scenes_b_high_12_ADDRESS 0xEE25u    /* 07EE25 */
#define block_scenes_b_high_13_ADDRESS 0xEE2Du    /* 07EE2D */
#define block_scenes_b_high_14_ADDRESS 0xEE3Du    /* 07EE3D */
#define map_scenes_a_high_0_ADDRESS 0xEE5Fu    /* 07EE5F */
#define map_scenes_a_high_1_ADDRESS 0xEE63u    /* 07EE63 */
#define map_scenes_a_high_2_ADDRESS 0xEE6Bu    /* 07EE6B */
#define map_scenes_a_high_3_ADDRESS 0xEE6Fu    /* 07EE6F */
#define map_scenes_a_high_4_ADDRESS 0xEE77u    /* 07EE77 */
#define map_scenes_a_high_5_ADDRESS 0xEE87u    /* 07EE87 */
#define map_scenes_a_high_7_ADDRESS 0xEE8Fu    /* 07EE8F */
#define map_scenes_a_high_8_ADDRESS 0xEE93u    /* 07EE93 */
#define map_scenes_a_high_9_ADDRESS 0xEE97u    /* 07EE97 */
#define map_scenes_a_high_10_ADDRESS 0xEEABu    /* 07EEAB */
#define map_scenes_a_high_11_ADDRESS 0xEEAFu    /* 07EEAF */
#define map_scenes_a_high_12_ADDRESS 0xEEBBu    /* 07EEBB */
#define map_scenes_a_high_13_ADDRESS 0xEEBFu    /* 07EEBF */
#define map_scenes_a_high_14_ADDRESS 0xEECFu    /* 07EECF */
#define map_scenes_b_high_0_ADDRESS 0xEEF1u    /* 07EEF1 */
#define map_scenes_b_high_1_ADDRESS 0xEEF5u    /* 07EEF5 */
#define map_scenes_b_high_2_ADDRESS 0xEEF9u    /* 07EEF9 */
#define map_scenes_b_high_3_ADDRESS 0xEEFDu    /* 07EEFD */
#define map_scenes_b_high_4_ADDRESS 0xEF01u    /* 07EF01 */
#define map_scenes_b_high_5_ADDRESS 0xEF0Du    /* 07EF0D */
#define map_scenes_b_high_7_ADDRESS 0xEF11u    /* 07EF11 */
#define map_scenes_b_high_8_ADDRESS 0xEF15u    /* 07EF15 */
#define map_scenes_b_high_9_ADDRESS 0xEF19u    /* 07EF19 */
#define map_scenes_b_high_10_ADDRESS 0xEF29u    /* 07EF29 */
#define map_scenes_b_high_11_ADDRESS 0xEF2Du    /* 07EF2D */
#define map_scenes_b_high_12_ADDRESS 0xEF39u    /* 07EF39 */
#define map_scenes_b_high_13_ADDRESS 0xEF41u    /* 07EF41 */
#define map_scenes_b_high_14_ADDRESS 0xEF51u    /* 07EF51 */
#define layer_modes_0_ADDRESS 0xEF5Du    /* 07EF5D */
#define layer_modes_1_ADDRESS 0xEF5Fu    /* 07EF5F */
#define layer_modes_3_ADDRESS 0xEF61u    /* 07EF61 */
#define layer_modes_high_0_ADDRESS 0xEF81u    /* 07EF81 */
#define layer_modes_high_1_ADDRESS 0xEF83u    /* 07EF83 */
#define layer_modes_high_2_ADDRESS 0xEF85u    /* 07EF85 */
#define layer_modes_high_3_ADDRESS 0xEF87u    /* 07EF87 */
#define layer_modes_high_4_ADDRESS 0xEF8Bu    /* 07EF8B */
#define layer_modes_high_5_ADDRESS 0xEF8Du    /* 07EF8D */
#define layer_modes_high_6_ADDRESS 0xEF8Fu    /* 07EF8F */
#define layer_modes_high_7_ADDRESS 0xEF93u    /* 07EF93 */
#define layer_modes_high_8_ADDRESS 0xEF95u    /* 07EF95 */
#define layer_modes_high_9_ADDRESS 0xEF97u    /* 07EF97 */
#define layer_modes_high_10_ADDRESS 0xEF9Du    /* 07EF9D */
#define layer_modes_high_11_ADDRESS 0xEF9Fu    /* 07EF9F */
#define layer_modes_high_12_ADDRESS 0xEFA7u    /* 07EFA7 */
#define layer_modes_high_13_ADDRESS 0xEFABu    /* 07EFAB */
#define layer_modes_high_14_ADDRESS 0xEFB3u    /* 07EFB3 */
#define tile_pictures_0_ADDRESS 0xEFB7u    /* 07EFB7 */
#define check_enemy_limit_table_ADDRESS 0xF019u    /* 07F019 */
#define enemy_hit_kind_reactions_ADDRESS 0xF134u    /* 07F134 */
#define enemy_goon_run_table_ADDRESS 0xF19Cu    /* 07F19C */
#define enemy_climb_actions_ADDRESS 0xF1AEu    /* 07F1AE */
#define enemy_climb_up_front_steps_ADDRESS 0xF1BEu    /* 07F1BE */
#define enemy_climb_up_back_steps_ADDRESS 0xF1C4u    /* 07F1C4 */
#define enemy_climb_up_left_steps_ADDRESS 0xF1CAu    /* 07F1CA */
#define enemy_climb_up_right_steps_ADDRESS 0xF1D0u    /* 07F1D0 */
#define enemy_hop_down_front_steps_ADDRESS 0xF1D6u    /* 07F1D6 */
#define enemy_hop_down_back_steps_ADDRESS 0xF1DCu    /* 07F1DC */
#define enemy_hop_down_left_steps_ADDRESS 0xF1E2u    /* 07F1E2 */
#define enemy_hop_down_right_steps_ADDRESS 0xF1E8u    /* 07F1E8 */
#define enemy_get_around_steps_ADDRESS 0xF1EEu    /* 07F1EE */
#define enemy_walk_to_target_side_steps_ADDRESS 0xF1F4u    /* 07F1F4 */
#define enemy_line_up_near_target_steps_ADDRESS 0xF1F8u    /* 07F1F8 */
#define enemy_walk_to_target_steps_ADDRESS 0xF1FEu    /* 07F1FE */
#define enemy_line_up_with_target_steps_ADDRESS 0xF202u    /* 07F202 */
#define enemy_keep_distance_steps_ADDRESS 0xF208u    /* 07F208 */
#define enemy_wait_while_target_down_steps_ADDRESS 0xF210u    /* 07F210 */
#define enemy_back_off_steps_ADDRESS 0xF214u    /* 07F214 */
#define enemy_step_toward_target_steps_ADDRESS 0xF21Au    /* 07F21A */
#define enemy_circle_target_steps_ADDRESS 0xF21Eu    /* 07F21E */
#define enemy_wander_steps_ADDRESS 0xF222u    /* 07F222 */
#define enemy_rush_at_target_steps_ADDRESS 0xF228u    /* 07F228 */
#define enemy_line_up_and_pace_steps_ADDRESS 0xF22Eu    /* 07F22E */
#define enemy_flinch_from_behind_steps_ADDRESS 0xF248u    /* 07F248 */
#define enemy_flinch_kind_12_steps_ADDRESS 0xF24Cu    /* 07F24C */
#define enemy_flinch_kind_11_steps_ADDRESS 0xF250u    /* 07F250 */
#define enemy_knocked_forward_steps_ADDRESS 0xF254u    /* 07F254 */
#define enemy_knocked_back_steps_ADDRESS 0xF258u    /* 07F258 */
#define enemy_get_up_steps_ADDRESS 0xF25Eu    /* 07F25E */
#define enemy_die_steps_ADDRESS 0xF262u    /* 07F262 */
#define enemy_drop_steps_ADDRESS 0xF266u    /* 07F266 */
#define enemy_sent_flying_steps_ADDRESS 0xF268u    /* 07F268 */
#define enemy_spin_backward_steps_ADDRESS 0xF26Eu    /* 07F26E */
#define enemy_defeated_forward_steps_ADDRESS 0xF274u    /* 07F274 */
#define enemy_defeated_backward_steps_ADDRESS 0xF27Au    /* 07F27A */
#define enemy_pit_steps_ADDRESS 0xF280u    /* 07F280 */
#define fireman_goon_effect_setup_box_ADDRESS 0xF284u    /* 07F284 */
#define fireman_goon_effect_steps_ADDRESS 0xF28Cu    /* 07F28C */
#define fireman_goon_effect_setup_ADDRESS 0xF290u    /* 07F290 */
#define fireman_goon_effect_child_ADDRESS 0xF296u    /* 07F296 */
#define enemy_hurt_steps_ADDRESS 0xF29Eu    /* 07F29E */
#define enemy_type_handlers_ADDRESS 0xF2ECu    /* 07F2EC */
#define object_list_1_type_handlers_ADDRESS 0xF40Du    /* 07F40D */
#define child_object_type_handlers_ADDRESS 0xF4F4u    /* 07F4F4 */
#define run_stage_event_table_ADDRESS 0xF577u    /* 07F577 */
#define enemy_think_actions_ADDRESS 0xF586u    /* 07F586 */
#define enemy_action_handlers_ADDRESS 0xF5A2u    /* 07F5A2 */
#define unused_object_handlers_ADDRESS 0xF65Fu    /* 07F65F */
#define enemy_hit_reaction_table_ADDRESS 0xF662u    /* 07F662 */

/* numbers the code uses, by name (symbols.txt constant lines) */


/* the game's structures */
#pragma pack(push, 1)
struct animation_set
{
	uint8_t index;
	uint8_t bank;
};

struct shadow_sprite
{
	uint8_t pad_00[0x1];
	uint16_t code;
	uint8_t attributes;
};

struct layer_map
{
	uint16_t maps_high;
	uint16_t offset_y2;
	uint16_t offset_y;
	uint16_t offset_x;
	uint16_t last_scroll_y;
	uint16_t maps;
	uint16_t scroll_y;
	uint16_t scroll_x;
	uint16_t tiles;
};

struct palette_load
{
	uint8_t palettes;
	uint16_t destination;
	uint16_t source;
};

struct spawn
{
	uint8_t kind;
	uint8_t level;
	uint8_t state;
	uint8_t flags;
	uint8_t depth;
	int8_t y;
	uint16_t x;
};

struct tile_picture_place
{
	uint16_t picture;
	uint16_t tiles;
	uint8_t bank;
};

struct test_menu_line
{
	uint8_t action;
	uint16_t cursor;
};

struct path_step
{
	uint8_t speed;
	int8_t direction;
};

struct path_start
{
	uint8_t count_3a;
	uint8_t count_3b;
	uint16_t path;
};

struct demo_input
{
	uint8_t frames;
	uint8_t controls;
};

struct test_palette
{
	uint8_t pad_00[0x1E];
	uint16_t colours;
	uint16_t destination;
};

struct vector
{
	int16_t offset;
	uint8_t opcode;
};

struct enemy_behaviour
{
	uint8_t pad_00[0x2F];
	uint8_t ranges;
	uint8_t pad_30[0x27];
	uint8_t states;
};

struct behaviour_choice
{
	uint16_t behaviour;
	uint8_t flags;
	uint8_t state;
};

struct gauge_player
{
	union
	{
		uint16_t status;
		uint8_t unk_17;
	};
	uint16_t score_tiles;
	uint16_t score;
	uint8_t unused_11;
	uint8_t unused_10;
	uint16_t gauge_tiles;
	uint16_t health;
	uint16_t continue_tiles;
	uint16_t lives_tiles;
	uint16_t lives;
	uint16_t unused_04;
	uint16_t counters;
	uint8_t number;
	uint8_t bit;
};

struct test_player
{
	uint8_t button;
	uint16_t sound;
	uint16_t palette_effect;
	uint8_t palette_set;
	uint16_t shadow_x;
	uint16_t shadow_kind;
	uint16_t z;
	uint16_t x;
	uint8_t animation;
	uint8_t kind;
	uint16_t lives;
};

struct placement
{
	uint16_t z;
	uint16_t x;
	uint16_t kind;
	uint16_t object;
};

struct player_kind
{
	uint8_t unk_03;
	uint16_t kind;
	uint8_t bit;
};

struct stage_slot
{
	uint8_t unk_02;
	uint16_t record;
};

struct hit_box
{
	uint16_t dy_dz;
	uint16_t height_dx;
	uint16_t width_depth;
	uint16_t damage_attack;
};

struct part
{
	uint16_t unused;
	uint8_t animation;
	uint8_t kind;
	uint8_t type;
	int8_t dz;
	int8_t dy;
	uint8_t dx;
};

struct pattern_start
{
	uint8_t animation;
	uint8_t kind;
	uint16_t pattern;
};

struct part_offset
{
	int8_t dz;
	int8_t dy;
	int8_t dx;
};

struct bonus_player
{
	uint16_t object;
	uint16_t controls_pressed;
	uint8_t bit;
	uint16_t presses;
};

struct xz_offset
{
	int8_t dz;
	int8_t dx;
};

struct name_entry_player
{
	uint8_t colour;
	uint16_t score_y;
	uint16_t score_x;
	uint16_t place_y;
	uint16_t place_x;
	uint16_t repeat_wait;
	uint16_t tiles;
	uint16_t controls_held;
	uint16_t score;
	uint16_t initials;
	uint16_t controls_pressed;
	uint16_t high_score_entry;
	uint16_t sprites;
};

struct place_suffix
{
	uint8_t second;
	uint8_t first;
};

struct name_entry_block
{
	uint8_t colour;
	uint8_t height;
	uint8_t width;
	uint16_t tiles;
};

struct name_entry_column
{
	uint8_t palette;
	uint8_t column;
};

struct helper_start
{
	uint8_t slot;
	uint16_t x;
	uint8_t animation;
};

struct exit_speed
{
	uint16_t y_speed;
	uint16_t x_speed;
};

struct player_blank
{
	uint16_t lisa_place;
	uint16_t bart_place;
	uint16_t homer_place;
	uint16_t marge_place;
	uint8_t colour;
	uint8_t tile;
	uint8_t height;
	uint8_t width;
};

struct shake_step
{
	uint8_t fraction;
	int8_t pixels;
};

struct layer_scroll
{
	uint16_t y;
	uint16_t x;
};

struct layer_offset_step
{
	uint16_t offset_y;
	uint16_t until;
};

struct goon_entrance
{
	uint8_t attributes;
	uint8_t wait;
};

struct descent_start
{
	int16_t x_speed;
	uint16_t x;
};

struct waiting_hat_goon_start
{
	uint8_t flags;
	uint8_t attributes;
	uint16_t trigger_x;
};

struct goon_walk_in_start
{
	uint8_t floor_wait;
	uint8_t wait;
	uint8_t trigger_x;
	uint8_t flags;
};

struct delayed_start
{
	uint8_t speed;
	uint8_t direction;
	uint8_t floor_wait;
	uint8_t wait;
};

struct goon_side_entry
{
	uint8_t floor_wait;
	uint8_t attributes;
};

struct goon_run_in_start
{
	uint8_t floor_wait;
	uint8_t trigger_x;
};

struct hat_goon_jump_in_start
{
	uint8_t unused;
	uint8_t wait;
	uint16_t trigger_x;
};

struct fat_goon_drop_route
{
	uint8_t unused;
	uint8_t wait;
	uint8_t floor;
	uint8_t next_step;
};

struct timed_spawn
{
	uint8_t type;
	uint8_t state;
	uint8_t flags;
	uint8_t players;
	uint8_t z;
	uint8_t y;
	uint8_t x;
	uint8_t time;
};

struct door_release
{
	uint8_t wait;
	uint8_t players;
};

struct krustyland_door
{
	uint16_t releases;
	uint8_t trigger_x;
	uint8_t wait;
};

struct prop
{
	uint8_t leave_x;
	uint8_t attributes;
	uint8_t animation;
	uint8_t kind;
};

struct dream_ball_fling
{
	int16_t z_speed;
	int16_t x_speed;
};

struct cemetery_piece
{
	uint8_t unused;
	uint8_t animation;
	int16_t z;
};

struct police_car_arrival
{
	uint8_t kind;
	uint8_t frames;
	int16_t x_speed;
};

struct police_car_door
{
	uint8_t releases;
	uint8_t wait;
	uint8_t trigger_x;
	uint8_t players;
};

struct car_door_release
{
	uint8_t type;
	uint8_t state;
	uint8_t flags;
	uint8_t dz;
	int16_t dy;
	int16_t dx;
	uint8_t players;
};

struct floor_column
{
	uint8_t row_5;
	uint8_t row_4;
	uint8_t row_3;
	uint8_t row_2;
	uint8_t row_1;
	uint8_t row_0;
};

struct boulder_drop
{
	uint8_t unused;
	uint8_t wait;
	uint8_t floor;
	uint8_t bounces;
};

struct object_16_animation_run
{
	uint8_t fourth;
	uint8_t third;
	uint8_t second;
	uint8_t first;
};

struct running_animal
{
	uint8_t quiet;
	uint8_t attributes;
	uint8_t animation;
	uint8_t kind;
};

struct running_animal_timing
{
	uint8_t fast;
	uint8_t wait;
};

struct obstacle_drop
{
	uint16_t x;
	uint8_t wait;
	uint8_t animation;
};

struct looping_scenery_move
{
	uint8_t attributes;
	uint8_t animation;
	int16_t x_speed;
};

struct food_move
{
	int16_t z_speed;
	int16_t x_speed;
	uint16_t gravity;
	uint8_t hit_kind;
	uint8_t animation;
};

struct bystander_animation_set
{
	uint8_t fleeing;
	uint8_t startled;
	uint8_t waiting;
};

struct bystander
{
	uint16_t animations;
	uint8_t place;
	uint8_t kind;
};

struct fireman_goon_start
{
	uint8_t throws;
	uint8_t wait;
	uint16_t x;
};

struct clown_pose
{
	uint8_t attributes;
	uint8_t animation;
};

struct bluebird_entry
{
	uint8_t unused;
	uint8_t frames;
	uint16_t x;
	int16_t x_speed;
	int16_t z_speed;
};

struct bluebird_launch
{
	uint16_t parent_x;
	int16_t z_speed;
	int16_t y_speed;
	int16_t x_speed;
};

struct random_pose_figure
{
	uint16_t poses;
	uint8_t attributes;
	uint8_t kind;
};

struct child_object
{
	uint8_t type;
	uint8_t state;
	uint8_t list;
	uint8_t dz;
	int16_t dy;
	int16_t dx;
};

struct velocity
{
	int16_t y_speed;
	int16_t x_speed;
};

struct timed_move
{
	uint8_t animation;
	uint8_t direction;
	uint8_t travel;
	uint8_t delay;
};

struct drop_start
{
	uint8_t mode;
	uint8_t unused;
	int16_t x_offset;
};

struct appearance
{
	uint8_t unused;
	uint8_t step;
	uint8_t flags;
	uint8_t wait;
};

struct timed_spot
{
	uint8_t x;
	uint8_t wait;
};

struct gorilla_entrance
{
	uint8_t animation;
	uint8_t step;
	uint8_t x;
	uint8_t flags;
};

struct knight_entrance
{
	uint8_t x;
	uint8_t kind;
	uint8_t entrance_kind;
	uint8_t wait;
};

struct knight_entrance_style
{
	uint8_t slowdown;
	uint8_t step;
};

struct pose
{
	uint8_t animation;
	uint8_t flags;
};

struct robot_piece
{
	uint8_t direction;
	uint8_t animation;
	uint8_t wait;
	uint8_t rise;
};

struct channel_6_scenery_part
{
	uint8_t height;
	uint8_t unused;
	uint8_t wait;
	uint8_t parent_step;
};

struct timed_step
{
	uint8_t step;
	uint8_t wait;
};

struct launch
{
	uint8_t time;
	uint8_t speed;
};

struct chain_link
{
	int8_t box_y_offset;
	uint8_t animation;
};

struct door_spawn
{
	uint8_t type;
	uint8_t state;
	uint8_t list;
	uint8_t dz;
	int16_t dy;
	int16_t dx;
	uint8_t players;
};

struct door_opening
{
	uint8_t list;
	uint8_t wait;
	uint16_t x;
};

struct player_move
{
	uint16_t hit;
	uint8_t animation;
	uint8_t state;
};

struct attack_box
{
	int8_t x_offset;
	uint8_t width;
};

struct team_move
{
	uint8_t facing_second_left;
	uint8_t facing_second_right;
	uint16_t sound;
	uint8_t second_object;
	uint8_t direction;
	uint8_t first_object;
	uint8_t move;
};

struct state_start
{
	uint8_t animation;
	uint8_t wait;
};

struct line_piece
{
	int8_t dx;
	uint8_t animation;
};

struct part_flight
{
	uint8_t speed_z;
	int8_t speed_y;
	int16_t speed_x;
};

struct profile_move
{
	uint8_t frames;
	int16_t speed_y;
	int16_t speed_x;
};

struct gauge_column
{
	uint8_t colour;
	uint8_t column;
};

struct big_digit
{
	uint8_t unused;
	uint8_t bottom;
	uint8_t top;
	uint8_t attribute;
};

struct gauge_step
{
	uint8_t bottom;
	uint8_t top;
};

struct portrait_area
{
	uint8_t unused;
	uint8_t colour;
	uint16_t tiles;
};

struct player
{
	uint16_t play_status;
	uint16_t state;
	uint16_t object_kind;
	uint16_t object_life;
	uint16_t controls;
	uint16_t life;
	uint8_t number;
	uint8_t initial_3;
	uint8_t initial_2;
	uint8_t initial_1;
	uint16_t score;
	uint16_t countdown;
	uint8_t bit;
	uint16_t lives;
	uint16_t credit_given;
	uint16_t pressed;
};

struct score_addition
{
	uint8_t low;
	uint8_t high;
};

struct demo
{
	uint16_t lisa_inputs;
	uint16_t bart_inputs;
	uint16_t homer_inputs;
	uint16_t marge_inputs;
	uint8_t step;
	uint16_t frames;
	uint8_t players;
};

struct scene_routine
{
	uint8_t spare;
	uint16_t routine;
	uint8_t bank;
};

struct palette_effect
{
	uint8_t delay;
	uint8_t extra_colours;
	uint8_t spare;
	uint8_t stop;
};

struct palette_effect_step
{
	uint16_t colour;
	uint16_t address;
};

struct fade_range
{
	uint8_t spare;
	uint16_t address;
	uint8_t colours;
};

struct palette_clear
{
	uint16_t address;
	uint16_t extra_bytes;
};

struct hurt_effect_row
{
	uint16_t all_left;
	uint16_t four_fifths_left;
	uint16_t three_fifths_left;
	uint16_t two_fifths_left;
	uint16_t fifth_left;
	uint16_t normal;
};

struct scene_area
{
	uint8_t spare;
	uint8_t bank;
	uint16_t address;
};

struct layer_mode
{
	uint8_t tile_banks_23;
	uint8_t tile_banks_01;
};

struct tile_picture
{
	uint8_t colour;
	uint8_t height;
	uint8_t width;
};

struct object
{
	union
	{
		struct
		{
			uint16_t draw_next;
			uint16_t floor_z;
			uint8_t shadow_player;
			uint16_t sprites;
			uint8_t unk_58;
			uint8_t entrance_pending;
			uint8_t unk_56;
			uint16_t unk_54;
			uint8_t unk_53;
			uint8_t unk_52;
			uint8_t unk_51;
			uint8_t unk_50;
			uint8_t unk_4F;
			uint8_t unk_4E;
			uint8_t unk_4D;
			uint16_t unk_4B;
			uint8_t pad_15[0x1];
			uint16_t hit_box;
			uint8_t next_floor_cell;
			uint8_t floor_cell;
			uint8_t unk_45;
			uint8_t unk_44;
			uint8_t unk_43;
			int8_t enemy_class;
			uint16_t parent;
			uint8_t unk_3F;
			uint8_t unk_3E;
			uint8_t carried;
			uint8_t unk_3C;
			uint8_t timer;
			uint8_t retarget_time;
			uint16_t target;
			uint8_t unk_37;
			uint8_t target_direction;
			uint8_t unk_35;
			uint8_t unk_34;
			uint8_t hit_from_behind;
			uint8_t unk_32;
			uint8_t blocked;
			uint8_t parameter;
			uint16_t target_dy;
			uint16_t target_dx;
			uint16_t behaviour;
			uint8_t action_step;
			uint8_t action;
			uint8_t points;
			uint16_t hit_by;
			uint8_t box_dz;
			int8_t box_dy;
			int8_t box_dx;
			uint8_t box_height;
			uint8_t box_depth;
			uint8_t box_width;
			uint8_t hit;
			uint8_t attack;
			uint8_t damage;
			uint8_t vitality;
			int16_t z_speed;
			uint8_t z_fraction;
			uint16_t z;
			int16_t y_speed;
			uint8_t y_fraction;
			uint16_t y;
			int16_t x_speed;
			uint8_t x_fraction;
			uint16_t x;
			uint8_t zoom_y;
			uint8_t zoom_x;
			uint8_t attributes;
			uint8_t frame_time;
			uint8_t frame;
			uint8_t animation_flags;
			uint8_t animation;
			uint8_t kind;
			uint8_t pad_5C[0x1];
			uint8_t state;
			int8_t type;
		};
		struct
		{
			uint8_t pad_00[0x36];
			uint16_t zoom;
		} attract_opening;
		struct
		{
			uint8_t pad_00[0x37];
			uint8_t move_frames;
			uint8_t pad_38[0x26];
			uint8_t move_step;
		} attract_profile;
		struct
		{
			uint8_t pad_00[0x23];
			uint8_t pose;
		} barney_bystander;
		struct
		{
			uint8_t pad_00[0x18];
			uint8_t attack_health;
			uint8_t flinch_health;
			uint8_t pad_1A[0x6];
			uint8_t bounces;
			uint8_t pad_21[0x4];
			uint8_t charge_timer;
			uint8_t pad_26[0x3];
			uint8_t charged;
			uint16_t chase_target;
			uint8_t pad_2C[0x4];
			uint8_t wait;
			uint8_t phase;
		} bear;
		struct
		{
			uint8_t pad_00[0x18];
			uint8_t attack_health;
			uint8_t flinch_health;
			uint8_t pad_1A[0x6];
			uint8_t bounces;
			uint8_t pad_21[0x4];
			uint8_t charge_timer;
			uint8_t pad_26[0x3];
			uint8_t charged;
			uint16_t chase_target;
			uint8_t pad_2C[0x4];
			uint8_t wait;
			uint8_t landed;
		} bear_boulder;
		struct
		{
			uint8_t pad_00[0xA];
			uint16_t rest_height;
			uint16_t rest_y;
			uint16_t rest_x;
			uint8_t pad_10[0x8];
			uint8_t attack_health;
			uint8_t flinch_health;
			uint8_t pad_1A[0x6];
			uint8_t bounces;
			uint8_t pad_21[0x4];
			uint8_t charge_timer;
			uint8_t pad_26[0x3];
			uint8_t charged;
			uint16_t chase_target;
			uint8_t pad_2C[0x4];
			uint8_t wait;
			uint8_t phase;
			uint8_t number;
		} bear_part;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t carried;
		} bird_item;
		struct
		{
			uint8_t pad_00[0x23];
			uint8_t hits_left;
		} bleeding_gums_murphy;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t parent_x;
		} bluebird;
		struct
		{
			uint8_t pad_00[0x1B];
			uint8_t flight_step;
			uint8_t flight;
			uint8_t press_rate;
			uint8_t press_wait;
			uint8_t lie_time;
			uint8_t too_small;
			uint8_t in_game;
			uint8_t lift_time;
			uint8_t pad_23[0x4];
			uint16_t blower;
			uint16_t middle_part;
			uint16_t flyer;
			uint8_t growing;
			uint16_t size;
			uint8_t pad_30[0x1];
			int16_t growth;
			uint16_t height_zoom;
			uint16_t width_zoom;
		} bonus_1;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t result_place;
			uint8_t pad_1B[0x1];
			uint8_t sign_kept_animation;
			uint8_t pad_1D[0x3];
			uint8_t quiet_frames;
			uint8_t pad_21[0xD];
			uint8_t reaction_time;
			uint8_t reaction;
			uint8_t pad_30[0x2D];
			uint16_t level;
		} bonus_2;
		struct
		{
			uint8_t pad_00[0x17];
			uint8_t no_points;
			uint8_t hop;
			uint8_t points_shown;
			uint8_t place;
			uint16_t text;
			uint8_t text_wait;
			uint16_t text_cursor;
			uint8_t pad_20[0x10];
			uint8_t look;
		} bonus_results;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t turn;
			uint8_t heading;
		} boss_ball;
		struct
		{
			uint8_t pad_00[0x35];
			uint8_t open;
			uint16_t other_half;
		} boss_door;
		struct
		{
			uint8_t pad_00[0x9];
			uint8_t full_vitality;
			uint16_t shade_job;
			uint8_t shade_level;
		} boss_shade;
		struct
		{
			uint8_t pad_00[0x30];
			uint8_t frames_left;
		} boss_speech_balloon;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t wait_count;
		} boulder;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t carrier_kind;
			uint8_t pad_08[0x1B];
			uint8_t bounces_left;
			uint8_t pad_24[0x4];
			uint8_t done;
			uint8_t pad_29[0xB];
			uint16_t owner;
		} bouncing_prop;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t carrier_kind;
			uint8_t pad_08[0x1A];
			uint8_t carried;
			uint8_t flight_count;
		} bouncing_throwable;
		struct
		{
			uint8_t pad_00[0x24];
			uint8_t fuse;
		} burns_bomb;
		struct
		{
			uint8_t pad_00[0x36];
			uint16_t piece;
		} burns_breakout;
		struct
		{
			uint8_t pad_00[0x37];
			uint8_t blink_frames;
		} burns_debris;
		struct
		{
			uint8_t pad_00[0x35];
			uint16_t robot;
		} burns_held_part;
		struct
		{
			uint8_t pad_00[0x18];
			uint16_t walk_frames;
			uint16_t held_part;
			uint8_t holding_part;
			uint16_t part_frames;
			uint8_t shots_fired;
			uint16_t volley_frames;
			uint8_t bombs_lobbed;
			uint16_t lob_frames;
			uint8_t pad_25[0x1];
			uint16_t maggie;
			uint8_t pad_28[0x2];
			uint8_t attack_choice;
			uint8_t form_extra;
			uint8_t pad_2C[0x2];
			uint8_t walk_direction;
			uint8_t form_base;
			uint8_t health_mark;
			uint8_t target_heading;
			uint8_t aim;
			uint16_t target_player;
			uint8_t target_frames;
			uint8_t wait_frames;
			uint8_t step;
		} burns_robot;
		struct
		{
			uint8_t pad_00[0x36];
			uint8_t arm_frames;
		} burns_shot;
		struct
		{
			uint8_t pad_00[0x37];
			uint8_t flight_frames;
		} burns_tossed_part;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t turn;
			uint8_t direction;
			uint8_t speed;
			uint8_t chases_left;
		} buzzing_chaser;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
			uint8_t pad_22[0x12];
			uint16_t animations;
		} bystander;
		struct
		{
			uint8_t pad_00[0x1B];
			uint8_t idle_frames;
			uint8_t pad_1C[0x6];
			uint8_t idle_number;
		} caged_gorilla;
		struct
		{
			uint8_t pad_00[0x24];
			uint8_t timer;
			uint8_t spawned;
			uint8_t pad_26[0x9];
			uint8_t spawn_list;
		} car_doors;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t carried;
		} carried_obstacle;
		struct
		{
			uint8_t pad_00[0x1B];
			uint8_t holds_food;
			uint8_t pad_1C[0xA];
			uint16_t floor_row;
			uint8_t pad_28[0x3];
			uint8_t floor_column;
			uint8_t floor_cell;
		} cemetery_obstacle;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t floor_row;
			uint8_t part;
			uint8_t pad_29[0x2];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x7];
			uint16_t floor_start;
		} charging_scenery;
		struct
		{
			uint8_t pad_00[0xE];
			uint16_t kept_height;
			uint8_t pad_10[0x12];
			uint8_t sweep_way;
			uint8_t pad_23[0x2];
			uint8_t sweep_rate;
			uint8_t pad_26[0x2];
			uint8_t bob_phase;
			uint8_t pad_29[0x7];
			uint16_t heading;
			uint16_t stay_time;
		} cloud_devil;
		struct
		{
			uint8_t pad_00[0x1B];
			uint8_t setup_count;
			uint8_t vanishes;
			uint8_t pad_1D[0x6];
			uint8_t hops_left;
		} clown_on_ball;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
		} donut;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t open_x;
			uint8_t pad_22[0x2];
			uint8_t timer;
			uint8_t spawned;
			uint8_t pad_26[0x9];
			uint8_t spawn_list;
		} door;
		struct
		{
			uint8_t pad_00[0xC];
			uint8_t flash_time;
			uint8_t routine_step;
			uint8_t bounced_in_depth;
			uint8_t bounced_across;
			uint8_t hit_count;
			uint8_t change_step;
			uint8_t pad_12[0x8];
			uint8_t resume_step;
			uint8_t leap_distance;
			uint8_t keeps_acting;
			uint8_t pad_1D[0x1];
			uint16_t chain;
			uint8_t pad_20[0x3];
			uint8_t legs_left;
			uint8_t pad_24[0x4];
			uint8_t side_flip;
			uint8_t pad_29[0x5];
			uint8_t phase;
		} dreamland_boss;
		struct
		{
			uint8_t pad_00[0xC];
			int16_t next_dz;
			int16_t next_dx;
			uint8_t hit_count;
			uint8_t change_step;
			uint8_t pad_12[0x8];
			uint8_t resume_step;
			uint8_t leap_distance;
			uint8_t keeps_acting;
			uint8_t pad_1D[0x1];
			uint16_t chain_head;
			uint8_t next_distance;
			uint8_t next_direction;
			uint8_t pad_22[0x1];
			uint8_t path_wait;
			uint8_t pad_24[0x4];
			uint8_t direction;
			uint8_t pad_29[0x1];
			uint8_t queued_direction;
			uint8_t lead_attributes;
			uint8_t pad_2C[0x1];
			uint8_t link_index;
			uint8_t phase;
			uint8_t pad_2F[0x1];
			uint16_t previous_link;
			uint16_t next_link;
			uint16_t chain_base;
		} dreamland_boss_chain;
		struct
		{
			uint8_t pad_00[0xC];
			int16_t next_dz;
			uint8_t bounced_in_depth;
			uint8_t lash_index;
			uint8_t sound_time;
			uint8_t change_step;
			uint8_t pad_12[0x6];
			uint8_t holder_attributes;
			uint8_t pad_19[0x1];
			uint8_t resume_step;
			uint8_t leap_distance;
			uint8_t keeps_acting;
			uint8_t pad_1D[0x1];
			uint16_t chain_head;
			uint8_t next_distance;
			uint8_t next_direction;
			uint8_t pad_22[0x1];
			uint8_t path_wait;
			uint8_t pad_24[0x1];
			uint8_t lash_time;
			uint8_t pad_26[0x2];
			uint8_t direction;
			uint8_t pad_29[0x1];
			uint8_t queued_direction;
			uint8_t lead_attributes;
			uint8_t path_loops;
			uint8_t link_index;
			uint8_t phase;
			uint8_t pad_2F[0x1];
			uint16_t previous_link;
			uint16_t path;
			uint16_t chain_base;
		} dreamland_boss_chain_head;
		struct
		{
			uint8_t pad_00[0x2D];
			uint8_t drop_animation;
		} dreamland_obstacle;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t child_out;
			uint8_t let_outs_left;
		} drink_vendor;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x7];
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy;
		struct
		{
			uint8_t pad_00[0x12];
			uint16_t frame_sound;
			uint8_t pad_14[0x4];
			uint8_t kept_attributes;
			uint8_t pad_19[0x1];
			uint8_t step_level;
			uint8_t pad_1B[0x1];
			uint8_t vanishes;
			uint8_t pad_1D[0x5];
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy_hurt;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x5];
			int16_t slow_down;
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy_rush;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x5];
			int16_t flight_x_speed;
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy_sent_flying;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x5];
			int16_t spin_x_speed;
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy_spin;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x6];
			uint8_t wander_direction;
			uint8_t way_round;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
		} enemy_wander;
		struct
		{
			uint8_t pad_00[0x1A];
			uint8_t step_level;
			uint8_t pad_1B[0x7];
			uint8_t end_enemies;
			uint8_t count;
			uint8_t pad_24[0x4];
			uint8_t side;
			uint8_t pad_29[0x1];
			uint8_t aimed_direction;
			uint8_t walk_quarter;
			uint8_t pad_2C[0x1];
			uint8_t not_behind_target;
			uint8_t pad_2E[0x1];
			uint8_t next_wave_enemies;
			uint8_t pad_30[0x4];
			uint16_t spawns;
			uint8_t pad_36[0x1];
			uint8_t wave;
		} enemy_waves;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x16];
			uint16_t carried_object;
			uint8_t speed;
			uint8_t direction;
			uint8_t route_floor;
		} fat_goon;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x16];
			uint16_t carried_object;
			uint8_t speed;
			uint8_t direction;
			uint8_t route_floor;
			uint8_t appear_wait;
		} fat_goon_delayed;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x16];
			uint16_t carried_object;
			uint8_t speed;
			uint8_t direction;
			uint8_t route_floor;
			uint8_t route_wait;
		} fat_goon_drop;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x16];
			uint16_t carried_object;
			uint8_t speed;
			uint8_t direction;
			uint8_t route_floor;
			uint8_t entrance_wait;
		} fat_goon_entrance;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x12];
			uint8_t start_cell;
			uint8_t pad_1B[0x3];
			uint16_t carried_object;
			uint8_t speed;
			uint8_t direction;
			uint8_t route_floor;
			uint8_t carry_time;
		} fat_goon_thrower;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
			uint8_t pad_1D[0x3];
			uint16_t start_x;
			uint8_t pad_22[0x1];
			uint8_t throws_left;
		} fireman_goon;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t floor_row;
			uint8_t part;
			uint8_t pad_29[0x2];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x7];
			uint16_t floor_start;
		} floor_blocker;
		struct
		{
			uint8_t pad_00[0xC];
			int16_t descent_y_speed;
			uint16_t kept_height;
			uint8_t pad_10[0x10];
			uint16_t descent_slowdown;
			uint8_t sweep_way;
			uint8_t shots_left;
			uint8_t pad_24[0x1];
			uint8_t sweep_rate;
			uint8_t pad_26[0x2];
			uint8_t bob_phase;
			uint8_t pad_29[0x7];
			uint16_t heading;
			uint16_t stay_time;
		} flying_saxophone;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t bounce_speed;
			uint8_t pad_22[0x1];
			uint8_t bounces_left;
		} food_jump_out;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t life_frames;
		} football_line_piece;
		struct
		{
			uint8_t pad_00[0x19];
			uint8_t attack_health;
			uint8_t flinch_health;
			uint8_t pad_1B[0x3];
			uint8_t throw_wait;
			uint8_t pad_1F[0x1];
			uint8_t charge_wait;
			uint8_t hurt_pose;
			uint8_t pad_22[0x1];
			uint8_t runs_to_rest;
			uint8_t pad_24[0x4];
			uint8_t wrong_way;
			uint8_t speed;
			uint16_t chase_target;
			int8_t turn;
			uint8_t direction;
			uint8_t pad_2E[0x2];
			uint8_t wait;
			uint8_t phase;
		} football_player;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t flight_frames;
		} football_thrown;
		struct
		{
			uint8_t pad_00[0x20];
			int16_t drop_x_offset;
			uint8_t drop_unused;
			uint8_t pad_23[0x11];
			uint16_t stage_x;
		} ghost_on_rope;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t food_dropped;
		} girl_with_food;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x18];
			uint16_t trigger_x;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
			uint8_t pad_24[0x9];
			uint8_t not_behind_target;
		} goon;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x18];
			uint16_t heading;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
			uint8_t pad_24[0x9];
			uint8_t not_behind_target;
		} goon_delayed;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x16];
			uint16_t balloon;
			uint16_t trigger_x;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
			uint8_t pad_24[0x9];
			uint8_t not_behind_target;
		} goon_descent;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x18];
			uint16_t trigger_x;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
			uint8_t pad_24[0x9];
			uint8_t not_behind_target;
			uint8_t flight;
		} goon_hat;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x18];
			uint16_t trigger_x;
			uint8_t lift_step;
			uint8_t wait;
			uint8_t pad_24[0x9];
			uint8_t not_behind_target;
		} goon_lift_part;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
			uint8_t pad_1D[0x3];
			uint16_t entrance_x;
		} gorilla;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
		} grabber;
		struct
		{
			uint8_t pad_00[0x12];
			uint16_t frame_sound;
			uint8_t pad_14[0x8];
			uint8_t vanishes;
		} grabbing_zombie;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
		} hat_goon;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t hat;
			uint16_t trigger_x;
			uint8_t pad_22[0x1];
			uint8_t entrance_wait;
		} hat_goon_throw;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
			uint8_t start_flags;
			uint8_t entrance_wait;
		} hat_goon_waiting;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t floor_row;
			uint8_t pad_28[0x3];
			uint8_t floor_column;
			uint8_t floor_cell;
		} heavy_obstacle;
		struct
		{
			uint8_t pad_00[0x2A];
			uint16_t player_height;
			uint16_t player_y;
			uint8_t pad_2E[0x2];
			uint16_t time;
			uint8_t step;
			uint16_t player;
			uint16_t scroll_x;
			uint8_t tries;
		} hurry_up;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t food_dropped;
		} item_carrier;
		struct
		{
			uint8_t pad_00[0x23];
			uint8_t hits_left;
		} kent_brockman;
		struct
		{
			uint8_t pad_00[0x24];
			uint8_t timer;
		} kid_in_sunglasses;
		struct
		{
			uint8_t pad_00[0xF];
			uint8_t fighting_kind;
			uint8_t pad_10[0xB];
			uint8_t first_form;
			uint8_t vanishes;
			uint8_t pad_1D[0x3];
			uint16_t entrance_slowdown;
		} knight;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t attack_object;
			uint8_t pad_28[0x1];
			uint8_t volleys;
			uint8_t squash_step;
			uint8_t saved_step;
			uint8_t saved_state;
			uint8_t throw_side;
			uint8_t throws;
			uint8_t hits;
			uint8_t last_attack_health;
			uint8_t pad_31[0x1];
			uint8_t direction;
			uint16_t target;
			uint8_t target_time;
			uint8_t balloon_timer;
			uint8_t step;
		} krusty_balloon;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t attack_object;
			uint8_t pad_28[0x1];
			uint8_t volleys;
			uint8_t squash_step;
			uint8_t saved_step;
			uint8_t saved_state;
			uint8_t throw_side;
			uint8_t throws;
			uint8_t hits;
			uint8_t last_attack_health;
			uint8_t pad_31[0x1];
			uint8_t direction;
			uint16_t target;
			uint8_t target_time;
			uint8_t balloon_timer;
			uint8_t shot_timer;
		} krusty_balloon_shot;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
			uint8_t list_ended;
			uint8_t open_time;
			uint8_t pad_24[0x2];
			uint16_t released_object;
			uint8_t pad_28[0xC];
			uint16_t release;
		} krustyland_door;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
			uint8_t pad_1D[0x5];
			uint8_t swings;
			uint8_t pause_loops;
		} lumberjack;
		struct
		{
			uint8_t pad_00[0x2B];
			uint16_t wander_x;
			uint8_t actions;
			uint8_t pad_2E[0x2];
			uint8_t wait;
			uint8_t phase;
		} marge_cloud;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t stopped;
		} moe;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t floor_row;
			uint8_t pad_28[0x3];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x7];
			uint16_t floor_start;
		} moes_street_scenery_dropper;
		struct
		{
			uint8_t pad_00[0x23];
			uint8_t rise_steps;
		} moes_street_scenery_riser;
		struct
		{
			uint8_t pad_00[0x25];
			uint8_t maggie_landed;
			uint8_t pad_26[0xE];
			uint8_t wait_frames;
			uint16_t maggie;
		} mr_burns;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
			uint8_t pad_1D[0x5];
			uint8_t bounced;
			uint8_t loops;
			uint8_t pad_24[0x6];
			uint8_t jump_direction;
		} ninja;
		struct
		{
			uint8_t pad_00[0x18];
			uint8_t height;
			uint8_t pad_19[0x9];
			uint8_t carried;
			uint8_t pad_23[0x3];
			uint16_t floor_row;
			uint8_t pad_28[0x3];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x1];
			uint8_t floor_raised;
		} obstacle;
		struct
		{
			uint8_t pad_00[0x1B];
			uint8_t setup_count;
			uint8_t vanishes;
		} one_eared_rabbit;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t held_up;
			uint8_t pad_23[0x3];
			uint16_t floor_row;
			uint8_t part;
			uint8_t pad_29[0x2];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x7];
			uint16_t floor_start;
		} platform_scenery;
		struct
		{
			uint8_t pad_00[0xA];
			uint8_t voice_timer;
			uint16_t attack_gravity;
			uint8_t last_life;
			uint8_t pad_0E[0x1];
			uint8_t quick_presses;
			uint8_t frames_since_press;
			uint8_t jump_attack;
			uint8_t combo_step;
			uint16_t holder;
			uint16_t object_hit;
			uint8_t pad_17[0x2];
			uint8_t sides_taken;
			uint8_t attackers;
			uint8_t pose_animation;
			uint16_t move_hit;
			uint8_t heavy_object_presses;
			uint16_t held;
			uint8_t blink_frames;
			uint8_t hold_presses;
			uint8_t attack_started;
			uint8_t pad_24[0x2];
			uint8_t teamed;
			uint8_t state_frames;
			uint8_t team_spare;
			uint8_t team_direction;
			uint8_t team_move_number;
			uint8_t status;
			uint16_t partner;
			uint8_t state_timer;
			uint8_t player_state;
			uint8_t controls_pressed;
			uint8_t controls;
			uint8_t attack_facing;
			uint8_t blows_taken;
			uint8_t swings;
			uint8_t blow_landed;
		} player;
		struct
		{
			uint8_t pad_00[0xA];
			uint8_t voice_timer;
			uint16_t attack_gravity;
			uint8_t last_life;
			uint8_t pad_0E[0x1];
			uint8_t quick_presses;
			uint8_t frames_since_press;
			uint8_t jump_attack;
			uint8_t combo_step;
			uint16_t holder;
			uint16_t object_hit;
			uint8_t pad_17[0x2];
			uint8_t sides_taken;
			uint8_t attackers;
			uint8_t pose_animation;
			uint16_t move_hit;
			uint8_t heavy_object_presses;
			uint16_t held;
			uint8_t blink_frames;
			uint8_t prompt_frames;
			uint8_t attack_started;
			uint8_t pad_24[0x2];
			uint8_t teamed;
			uint8_t state_frames;
			uint8_t team_spare;
			uint8_t team_direction;
			uint8_t team_move_number;
			uint8_t status;
			uint16_t partner;
			uint8_t state_timer;
			uint8_t player_state;
			uint8_t controls_pressed;
			uint8_t controls;
			uint8_t attack_facing;
			uint8_t blows_taken;
			uint8_t swings;
			uint8_t blow_landed;
		} player_second_sprite;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
		} police_car_door;
		struct
		{
			uint8_t pad_00[0x2F];
			uint8_t wait;
			uint8_t pad_30[0x6];
			uint8_t portrait_frame;
			uint8_t frame_wait;
			uint8_t pad_38[0x26];
			uint8_t step;
		} portrait;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t leave_x;
		} prop;
		struct
		{
			uint8_t pad_00[0x34];
			uint16_t burns;
			uint8_t wait_frames;
		} rescued_maggie;
		struct
		{
			uint8_t pad_00[0x20];
			uint16_t trigger_x;
		} rising_scenery;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t drift_target;
			uint8_t pad_20[0x1];
			uint8_t direction;
		} rising_zombie;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t flashing;
			uint8_t pad_1D[0x5];
			uint8_t hit_round;
			uint8_t spare_count;
		} robot;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t flashing;
			uint8_t pad_1D[0x5];
			uint8_t carried;
			uint8_t spare_count;
			uint8_t pad_24[0xA];
			uint8_t lying;
		} robot_scrap;
		struct
		{
			uint8_t pad_00[0xE];
			uint8_t fast;
			uint8_t stop_frames;
			uint8_t pad_10[0xB];
			uint8_t quiet;
			uint8_t pad_1C[0x4];
			uint16_t run_speed;
			uint8_t carried;
			uint8_t stops_left;
			uint8_t pad_24[0xE];
			uint16_t look;
		} running_animal;
		struct
		{
			uint8_t pad_00[0x26];
			uint16_t floor_row;
			uint8_t pad_28[0x3];
			uint8_t floor_column;
			uint8_t floor_cell;
			uint8_t pad_2D[0x7];
			uint16_t floor_start;
		} scenery;
		struct
		{
			uint8_t pad_00[0x1C];
			uint16_t wait_x;
			uint8_t pad_1E[0x3];
			int8_t zoom_step;
			uint8_t zoom_flags;
			int8_t landing_floor;
			int16_t acceleration_z;
			int16_t acceleration_y;
			int16_t acceleration_x;
			uint8_t pad_2A[0x1];
			uint8_t wait;
			uint16_t script;
		} scripted_object;
		struct
		{
			uint8_t pad_00[0x2F];
			uint8_t enemies_left;
		} scroll_lock;
		struct
		{
			uint8_t pad_00[0xB];
			uint8_t kept_animation;
			uint8_t shake_animation_4;
			uint8_t shake_animation_3;
			uint8_t shake_animation_2;
			uint8_t shake_animation_1;
			uint8_t pad_10[0x8];
			uint8_t food_flags;
			uint8_t pad_19[0x7];
			uint16_t pattern;
			uint8_t standing_animation;
			uint8_t food_left;
		} shaking_scenery;
		struct
		{
			uint8_t pad_00[0x23];
			uint8_t entrance_wait;
		} shovel_goon;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t food_dropped;
		} sideshow_bob;
		struct
		{
			uint8_t pad_00[0x35];
			uint16_t speaker;
			uint8_t time;
		} speech_balloon;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t together;
			uint16_t partner;
			uint8_t join_wait;
			uint8_t pad_20[0x5];
			uint8_t apart_time;
			uint8_t pad_26[0x3];
			uint8_t walk_time;
			uint16_t chase_target;
			uint8_t pad_2C[0x1];
			uint8_t direction;
			uint8_t pad_2E[0x1];
			uint8_t second;
			uint8_t wait;
			uint8_t phase;
		} stage_3_boss;
		struct
		{
			uint8_t pad_00[0x1F];
			uint16_t charge_time;
			uint16_t walk_time;
			uint16_t throw_wait;
			uint16_t helper_4;
			uint16_t helper_2;
			uint16_t helper_1;
			uint16_t helper_3;
			uint8_t charge_direction;
			uint8_t pad_2E[0x1];
			uint8_t hits;
			uint8_t last_health;
			uint8_t direction;
			uint8_t side_direction;
			uint16_t target;
			uint8_t target_wait;
		} stage_7_boss;
		struct
		{
			uint8_t pad_00[0x1F];
			uint16_t charge_time;
			uint16_t walk_time;
			uint16_t throw_wait;
			uint16_t helper_4;
			uint16_t helper_2;
			uint16_t helper_1;
			uint16_t helper_3;
			uint8_t charge_direction;
			uint8_t pad_2E[0x1];
			uint8_t hits;
			uint8_t last_health;
			uint8_t direction;
			uint8_t side_direction;
			uint16_t target;
			uint16_t distance;
		} stage_7_boss_helper;
		struct
		{
			uint8_t pad_00[0x34];
			uint16_t next_link;
			uint16_t pair;
		} stage_7_link;
		struct
		{
			uint8_t pad_00[0x21];
			uint8_t steps;
			uint8_t health_mark;
			uint8_t laugh_frames;
			uint16_t marked_player;
			uint16_t random;
			uint8_t pad_28[0x1];
			uint8_t run_speed;
			uint8_t phase_1_hits;
			uint8_t steps_left;
			uint8_t count;
			uint8_t count_down;
			uint8_t pad_2E[0x2];
			uint8_t state_timer;
			uint8_t phase;
			uint8_t phases_left;
		} stage_8_boss;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t thrower;
			uint8_t pad_20[0x1];
			uint8_t steps;
			uint8_t health_mark;
			uint8_t laugh_frames;
			uint16_t marked_player;
			uint16_t random;
			uint8_t pad_28[0x1];
			uint8_t run_speed;
			uint8_t phase_1_hits;
			uint8_t steps_left;
			uint8_t count;
			uint8_t count_down;
			uint8_t pad_2E[0x2];
			uint8_t state_timer;
			uint8_t phase;
			uint8_t phases_left;
		} stage_8_boss_bomb;
		struct
		{
			uint8_t pad_00[0x32];
			uint8_t actor_player;
			uint16_t stop_offset;
			uint8_t actor_wait;
		} stage_8_end;
		struct
		{
			uint8_t pad_00[0x30];
			uint8_t wait;
			uint8_t phase;
		} stage_boss;
		struct
		{
			uint8_t pad_00[0x2C];
			uint8_t legs_flown;
			uint8_t jumper_player;
			uint8_t jump_wait;
		} stage_end_jumper;
		struct
		{
			uint8_t pad_00[0x7];
			uint16_t child_actor_11;
			uint16_t child_actor_10;
			uint16_t child_actor_9;
			uint16_t child_actor_8;
			uint16_t child_actor_7;
			uint16_t child_actor_6;
			uint16_t child_actor_5;
			uint16_t child_actor_4;
			uint16_t child_actor_3;
			uint16_t child_actor_2;
			uint16_t child_actor_1;
			uint8_t script_flags;
			uint8_t pad_1E[0x2];
			uint16_t x_wait;
			uint16_t camera_wait;
			uint8_t landing_height;
			uint8_t walk_speed;
			uint8_t target_margin;
			uint16_t script_target;
			int16_t acceleration_z;
			int16_t acceleration_y;
			int16_t acceleration_x;
			uint8_t script_number;
			uint16_t script;
			uint8_t wait;
		} story_actor;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t radius;
			uint8_t angle;
			uint8_t leave_turn;
			uint8_t pad_23[0x5];
			uint8_t approach_side;
			uint8_t pad_29[0x4];
			uint8_t frame_offset;
			uint8_t pad_2E[0x6];
			uint16_t hub;
		} teacup_goon;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t radius;
			uint8_t angle;
			uint8_t second_look;
			uint8_t pad_23[0x5];
			uint8_t approach_side;
			uint8_t pad_29[0x4];
			uint8_t frame_offset;
			uint8_t pad_2E[0x6];
			uint16_t hub;
		} teacup_goon_piece;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t radius;
			uint8_t angle;
			uint8_t too_many_out;
			uint8_t pad_23[0x2];
			uint8_t arms;
			uint8_t pad_26[0x2];
			uint8_t approach_side;
			uint8_t pad_29[0x4];
			uint8_t frame_offset;
			uint8_t riders_out;
			uint8_t pad_2F[0x5];
			uint16_t hub;
		} teacup_goon_ride;
		struct
		{
			uint8_t pad_00[0x20];
			uint8_t radius;
			uint8_t angle;
			uint8_t too_many_out;
			uint8_t turn_time;
			uint8_t pad_24[0x1];
			uint8_t riders;
			uint16_t ride_hub;
			uint8_t approach_side;
			uint8_t pad_29[0x4];
			uint8_t frame_offset;
			uint8_t riders_out;
			uint8_t riders_on;
			uint8_t pad_30[0x4];
			uint16_t hub;
		} teacup_goon_ride_arm;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t carrier_kind;
			uint8_t pad_08[0x1A];
			uint8_t carried;
		} throwable;
		struct
		{
			uint8_t pad_00[0x22];
			uint8_t carried;
		} timed_throwable;
		struct
		{
			uint8_t pad_00[0x21];
			uint8_t direction;
			uint8_t pad_22[0x1];
			uint8_t wait;
		} wandering_zombie;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t device;
			uint16_t home_x;
		} woman_in_apron;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t keeper;
			uint16_t home_x;
			uint8_t pad_22[0x1];
			uint8_t strike_frames;
		} woman_in_apron_device;
		struct
		{
			uint8_t pad_00[0x1E];
			uint16_t carried_goon;
		} woman_in_green_carrier;
		struct
		{
			uint8_t pad_00[0x2B];
			uint16_t partner;
			uint8_t pad_2D[0x2];
			uint8_t hits;
			uint8_t last_health;
			uint8_t direction;
			uint8_t side_direction;
			uint16_t target;
			uint8_t target_wait;
		} wrestler;
		struct
		{
			uint8_t pad_00[0x1C];
			uint8_t vanishes;
		} zombie;
		struct
		{
			uint8_t pad_00[0x7];
			uint8_t squeeze_step;
			uint8_t pad_08[0x14];
			uint8_t vanishes;
		} zombie_grab;
	};
	uint8_t flags;
};

struct object_setup
{
	uint8_t points;
	uint8_t life;
	uint16_t box;
	uint16_t kind_and_animation;
};

struct palette_job
{
	union
	{
		struct
		{
			uint8_t unk_07;
			uint16_t unk_05;
			uint8_t unk_04;
			uint16_t unk_02;
			uint8_t unk_01;
		};
		struct
		{
			uint8_t pad_00[0x5];
			uint16_t colour;
		} background;
		struct
		{
			uint8_t pad_00[0x6];
			uint8_t ranges;
		} clearing;
		struct
		{
			uint8_t repeats;
			uint8_t extra_colours;
			uint8_t delay;
			uint8_t frames_waited;
			uint16_t step;
			uint8_t direction;
		} effect;
		struct
		{
			uint8_t range;
			uint16_t ranges_left;
			uint16_t frames_left;
			uint16_t ranges;
		} fade;
		struct
		{
			uint8_t pad_00[0x3];
			uint8_t k053251_10;
			uint8_t k053251_9;
			uint8_t frames_left;
			uint8_t flash_layers;
		} flash;
		struct
		{
			uint8_t pad_00[0x5];
			uint8_t set;
			uint8_t loads;
		} sets;
	};
	uint8_t kind;
};

struct sprite_entry
{
	uint16_t borrowed_object;
	uint8_t colour;
	uint8_t priority;
	uint8_t zoom_x;
	uint8_t pad_05[0x1];
	uint8_t zoom_y;
	uint8_t pad_07[0x1];
	uint16_t x;
	uint16_t y;
	uint16_t code;
	uint8_t depth;
	uint8_t flags;
};

struct queued_job
{
	union
	{
		uint16_t job;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t kind;
		};
	};
};

struct player_input
{
	uint8_t held;
	uint8_t pressed;
	uint8_t last;
	uint8_t now;
};

struct shape_column
{
	uint8_t bottom_cell;
	uint8_t pad_01[0x3];
	uint8_t middle_cell;
	uint8_t pad_05[0x3];
	uint8_t top_cell;
};

struct boss_box
{
	int8_t dx;
	uint8_t height;
	uint8_t depth;
	uint8_t width;
};

struct attack_range
{
	uint8_t pad_00[0x3];
	uint8_t action_chances;
	uint8_t pad_04[0x3];
	uint8_t actions;
	uint8_t chance;
	uint8_t most_dx;
	uint8_t least_dx;
	uint8_t most_dy;
};

struct player_values
{
	uint8_t state;
	uint8_t grab_hints;
	uint16_t score;
	uint8_t entry_status;
	uint8_t kept_life;
	uint16_t lives;
};

struct coin_slot
{
	uint8_t credit_given;
	uint8_t credits_per_coins;
	uint8_t coins_per_credit;
	uint8_t counter_time;
	uint8_t counter_pulses;
	uint8_t coins;
	uint16_t own_credits;
};

struct player_counters
{
	uint8_t pad_00[0x3];
	uint8_t gauge_delay;
	uint8_t gauge_step;
	uint8_t frames;
	uint8_t seconds;
};

struct demo_playback
{
	uint8_t pad_00[0xB];
	uint8_t controls_inverted;
	uint8_t controls;
	uint8_t frames;
	uint16_t input;
};

struct attract_picture
{
	uint16_t y;
	uint16_t x;
	uint8_t animation;
};

struct story_object_start
{
	uint16_t z;
	uint16_t y;
	uint16_t x;
	uint8_t animation;
	uint8_t kind;
	uint16_t object;
};

struct camera_entry
{
	uint16_t data;
	uint16_t x;
};

struct camera_check
{
	union
	{
		uint16_t place;
		uint8_t place_low;
		struct
		{
			uint8_t pad_00[0x1];
			uint8_t ratio;
		};
	};
	uint8_t kind;
};

#pragma pack(pop)

_Static_assert(sizeof(struct animation_set) == 0x2, "struct animation_set has the size of the program ROM's records");
_Static_assert(sizeof(struct shadow_sprite) == 0x4, "struct shadow_sprite has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_map) == 0x12, "struct layer_map has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_load) == 0x5, "struct palette_load has the size of the program ROM's records");
_Static_assert(sizeof(struct spawn) == 0x8, "struct spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct tile_picture_place) == 0x5, "struct tile_picture_place has the size of the program ROM's records");
_Static_assert(sizeof(struct test_menu_line) == 0x3, "struct test_menu_line has the size of the program ROM's records");
_Static_assert(sizeof(struct path_step) == 0x2, "struct path_step has the size of the program ROM's records");
_Static_assert(sizeof(struct path_start) == 0x4, "struct path_start has the size of the program ROM's records");
_Static_assert(sizeof(struct demo_input) == 0x2, "struct demo_input has the size of the program ROM's records");
_Static_assert(sizeof(struct test_palette) == 0x22, "struct test_palette has the size of the program ROM's records");
_Static_assert(sizeof(struct vector) == 0x3, "struct vector has the size of the program ROM's records");
_Static_assert(sizeof(struct enemy_behaviour) == 0x58, "struct enemy_behaviour has the size of the program ROM's records");
_Static_assert(sizeof(struct behaviour_choice) == 0x4, "struct behaviour_choice has the size of the program ROM's records");
_Static_assert(sizeof(struct gauge_player) == 0x18, "struct gauge_player has the size of the program ROM's records");
_Static_assert(sizeof(struct test_player) == 0x12, "struct test_player has the size of the program ROM's records");
_Static_assert(sizeof(struct placement) == 0x8, "struct placement has the size of the program ROM's records");
_Static_assert(sizeof(struct player_kind) == 0x4, "struct player_kind has the size of the program ROM's records");
_Static_assert(sizeof(struct stage_slot) == 0x3, "struct stage_slot has the size of the program ROM's records");
_Static_assert(sizeof(struct hit_box) == 0x8, "struct hit_box has the size of the program ROM's records");
_Static_assert(sizeof(struct part) == 0x8, "struct part has the size of the program ROM's records");
_Static_assert(sizeof(struct pattern_start) == 0x4, "struct pattern_start has the size of the program ROM's records");
_Static_assert(sizeof(struct part_offset) == 0x3, "struct part_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct bonus_player) == 0x7, "struct bonus_player has the size of the program ROM's records");
_Static_assert(sizeof(struct xz_offset) == 0x2, "struct xz_offset has the size of the program ROM's records");
_Static_assert(sizeof(struct name_entry_player) == 0x19, "struct name_entry_player has the size of the program ROM's records");
_Static_assert(sizeof(struct place_suffix) == 0x2, "struct place_suffix has the size of the program ROM's records");
_Static_assert(sizeof(struct name_entry_block) == 0x5, "struct name_entry_block has the size of the program ROM's records");
_Static_assert(sizeof(struct name_entry_column) == 0x2, "struct name_entry_column has the size of the program ROM's records");
_Static_assert(sizeof(struct helper_start) == 0x4, "struct helper_start has the size of the program ROM's records");
_Static_assert(sizeof(struct exit_speed) == 0x4, "struct exit_speed has the size of the program ROM's records");
_Static_assert(sizeof(struct player_blank) == 0xC, "struct player_blank has the size of the program ROM's records");
_Static_assert(sizeof(struct shake_step) == 0x2, "struct shake_step has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_scroll) == 0x4, "struct layer_scroll has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_offset_step) == 0x4, "struct layer_offset_step has the size of the program ROM's records");
_Static_assert(sizeof(struct goon_entrance) == 0x2, "struct goon_entrance has the size of the program ROM's records");
_Static_assert(sizeof(struct descent_start) == 0x4, "struct descent_start has the size of the program ROM's records");
_Static_assert(sizeof(struct waiting_hat_goon_start) == 0x4, "struct waiting_hat_goon_start has the size of the program ROM's records");
_Static_assert(sizeof(struct goon_walk_in_start) == 0x4, "struct goon_walk_in_start has the size of the program ROM's records");
_Static_assert(sizeof(struct delayed_start) == 0x4, "struct delayed_start has the size of the program ROM's records");
_Static_assert(sizeof(struct goon_side_entry) == 0x2, "struct goon_side_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct goon_run_in_start) == 0x2, "struct goon_run_in_start has the size of the program ROM's records");
_Static_assert(sizeof(struct hat_goon_jump_in_start) == 0x4, "struct hat_goon_jump_in_start has the size of the program ROM's records");
_Static_assert(sizeof(struct fat_goon_drop_route) == 0x4, "struct fat_goon_drop_route has the size of the program ROM's records");
_Static_assert(sizeof(struct timed_spawn) == 0x8, "struct timed_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct door_release) == 0x2, "struct door_release has the size of the program ROM's records");
_Static_assert(sizeof(struct krustyland_door) == 0x4, "struct krustyland_door has the size of the program ROM's records");
_Static_assert(sizeof(struct prop) == 0x4, "struct prop has the size of the program ROM's records");
_Static_assert(sizeof(struct dream_ball_fling) == 0x4, "struct dream_ball_fling has the size of the program ROM's records");
_Static_assert(sizeof(struct cemetery_piece) == 0x4, "struct cemetery_piece has the size of the program ROM's records");
_Static_assert(sizeof(struct police_car_arrival) == 0x4, "struct police_car_arrival has the size of the program ROM's records");
_Static_assert(sizeof(struct police_car_door) == 0x4, "struct police_car_door has the size of the program ROM's records");
_Static_assert(sizeof(struct car_door_release) == 0x9, "struct car_door_release has the size of the program ROM's records");
_Static_assert(sizeof(struct floor_column) == 0x6, "struct floor_column has the size of the program ROM's records");
_Static_assert(sizeof(struct boulder_drop) == 0x4, "struct boulder_drop has the size of the program ROM's records");
_Static_assert(sizeof(struct object_16_animation_run) == 0x4, "struct object_16_animation_run has the size of the program ROM's records");
_Static_assert(sizeof(struct running_animal) == 0x4, "struct running_animal has the size of the program ROM's records");
_Static_assert(sizeof(struct running_animal_timing) == 0x2, "struct running_animal_timing has the size of the program ROM's records");
_Static_assert(sizeof(struct obstacle_drop) == 0x4, "struct obstacle_drop has the size of the program ROM's records");
_Static_assert(sizeof(struct looping_scenery_move) == 0x4, "struct looping_scenery_move has the size of the program ROM's records");
_Static_assert(sizeof(struct food_move) == 0x8, "struct food_move has the size of the program ROM's records");
_Static_assert(sizeof(struct bystander_animation_set) == 0x3, "struct bystander_animation_set has the size of the program ROM's records");
_Static_assert(sizeof(struct bystander) == 0x4, "struct bystander has the size of the program ROM's records");
_Static_assert(sizeof(struct fireman_goon_start) == 0x4, "struct fireman_goon_start has the size of the program ROM's records");
_Static_assert(sizeof(struct clown_pose) == 0x2, "struct clown_pose has the size of the program ROM's records");
_Static_assert(sizeof(struct bluebird_entry) == 0x8, "struct bluebird_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct bluebird_launch) == 0x8, "struct bluebird_launch has the size of the program ROM's records");
_Static_assert(sizeof(struct random_pose_figure) == 0x4, "struct random_pose_figure has the size of the program ROM's records");
_Static_assert(sizeof(struct child_object) == 0x8, "struct child_object has the size of the program ROM's records");
_Static_assert(sizeof(struct velocity) == 0x4, "struct velocity has the size of the program ROM's records");
_Static_assert(sizeof(struct timed_move) == 0x4, "struct timed_move has the size of the program ROM's records");
_Static_assert(sizeof(struct drop_start) == 0x4, "struct drop_start has the size of the program ROM's records");
_Static_assert(sizeof(struct appearance) == 0x4, "struct appearance has the size of the program ROM's records");
_Static_assert(sizeof(struct timed_spot) == 0x2, "struct timed_spot has the size of the program ROM's records");
_Static_assert(sizeof(struct gorilla_entrance) == 0x4, "struct gorilla_entrance has the size of the program ROM's records");
_Static_assert(sizeof(struct knight_entrance) == 0x4, "struct knight_entrance has the size of the program ROM's records");
_Static_assert(sizeof(struct knight_entrance_style) == 0x2, "struct knight_entrance_style has the size of the program ROM's records");
_Static_assert(sizeof(struct pose) == 0x2, "struct pose has the size of the program ROM's records");
_Static_assert(sizeof(struct robot_piece) == 0x4, "struct robot_piece has the size of the program ROM's records");
_Static_assert(sizeof(struct channel_6_scenery_part) == 0x4, "struct channel_6_scenery_part has the size of the program ROM's records");
_Static_assert(sizeof(struct timed_step) == 0x2, "struct timed_step has the size of the program ROM's records");
_Static_assert(sizeof(struct launch) == 0x2, "struct launch has the size of the program ROM's records");
_Static_assert(sizeof(struct chain_link) == 0x2, "struct chain_link has the size of the program ROM's records");
_Static_assert(sizeof(struct door_spawn) == 0x9, "struct door_spawn has the size of the program ROM's records");
_Static_assert(sizeof(struct door_opening) == 0x4, "struct door_opening has the size of the program ROM's records");
_Static_assert(sizeof(struct player_move) == 0x4, "struct player_move has the size of the program ROM's records");
_Static_assert(sizeof(struct attack_box) == 0x2, "struct attack_box has the size of the program ROM's records");
_Static_assert(sizeof(struct team_move) == 0x8, "struct team_move has the size of the program ROM's records");
_Static_assert(sizeof(struct state_start) == 0x2, "struct state_start has the size of the program ROM's records");
_Static_assert(sizeof(struct line_piece) == 0x2, "struct line_piece has the size of the program ROM's records");
_Static_assert(sizeof(struct part_flight) == 0x4, "struct part_flight has the size of the program ROM's records");
_Static_assert(sizeof(struct profile_move) == 0x5, "struct profile_move has the size of the program ROM's records");
_Static_assert(sizeof(struct gauge_column) == 0x2, "struct gauge_column has the size of the program ROM's records");
_Static_assert(sizeof(struct big_digit) == 0x4, "struct big_digit has the size of the program ROM's records");
_Static_assert(sizeof(struct gauge_step) == 0x2, "struct gauge_step has the size of the program ROM's records");
_Static_assert(sizeof(struct portrait_area) == 0x4, "struct portrait_area has the size of the program ROM's records");
_Static_assert(sizeof(struct player) == 0x1B, "struct player has the size of the program ROM's records");
_Static_assert(sizeof(struct score_addition) == 0x2, "struct score_addition has the size of the program ROM's records");
_Static_assert(sizeof(struct demo) == 0xC, "struct demo has the size of the program ROM's records");
_Static_assert(sizeof(struct scene_routine) == 0x4, "struct scene_routine has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_effect) == 0x4, "struct palette_effect has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_effect_step) == 0x4, "struct palette_effect_step has the size of the program ROM's records");
_Static_assert(sizeof(struct fade_range) == 0x4, "struct fade_range has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_clear) == 0x4, "struct palette_clear has the size of the program ROM's records");
_Static_assert(sizeof(struct hurt_effect_row) == 0xC, "struct hurt_effect_row has the size of the program ROM's records");
_Static_assert(sizeof(struct scene_area) == 0x4, "struct scene_area has the size of the program ROM's records");
_Static_assert(sizeof(struct layer_mode) == 0x2, "struct layer_mode has the size of the program ROM's records");
_Static_assert(sizeof(struct tile_picture) == 0x3, "struct tile_picture has the size of the program ROM's records");
_Static_assert(sizeof(struct object) == 0x60, "struct object has the size of the game's blocks");
_Static_assert(sizeof(struct object_setup) == 0x6, "struct object_setup has the size of the program ROM's records");
_Static_assert(sizeof(struct palette_job) == 0x8, "struct palette_job has the size of the game's blocks");
_Static_assert(sizeof(struct sprite_entry) == 0x10, "struct sprite_entry has the size of the game's blocks");
_Static_assert(sizeof(struct queued_job) == 0x2, "struct queued_job has the size of the game's blocks");
_Static_assert(sizeof(struct player_input) == 0x4, "struct player_input has the size of the game's blocks");
_Static_assert(sizeof(struct shape_column) == 0x9, "struct shape_column has the size of the program ROM's records");
_Static_assert(sizeof(struct boss_box) == 0x4, "struct boss_box has the size of the program ROM's records");
_Static_assert(sizeof(struct attack_range) == 0xC, "struct attack_range has the size of the program ROM's records");
_Static_assert(sizeof(struct player_values) == 0x8, "struct player_values has the size of the game's blocks");
_Static_assert(sizeof(struct coin_slot) == 0x8, "struct coin_slot has the size of the game's blocks");
_Static_assert(sizeof(struct player_counters) == 0x7, "struct player_counters has the size of the game's blocks");
_Static_assert(sizeof(struct demo_playback) == 0x10, "struct demo_playback has the size of the game's blocks");
_Static_assert(sizeof(struct attract_picture) == 0x5, "struct attract_picture has the size of the program ROM's records");
_Static_assert(sizeof(struct story_object_start) == 0xA, "struct story_object_start has the size of the program ROM's records");
_Static_assert(sizeof(struct camera_entry) == 0x4, "struct camera_entry has the size of the program ROM's records");
_Static_assert(sizeof(struct camera_check) == 0x3, "struct camera_check has the size of the program ROM's records");

#define ANIMATION_SET(address) ((const struct animation_set *)data_record((address), sizeof(struct animation_set)))
#define SHADOW_SPRITE(address) ((const struct shadow_sprite *)data_record((address), sizeof(struct shadow_sprite)))
#define LAYER_MAP(address) ((const struct layer_map *)data_record((address), sizeof(struct layer_map)))
#define PALETTE_LOAD(address) ((const struct palette_load *)data_record((address), sizeof(struct palette_load)))
#define SPAWN(address) ((const struct spawn *)data_record((address), sizeof(struct spawn)))
#define TILE_PICTURE_PLACE(address) ((const struct tile_picture_place *)data_record((address), sizeof(struct tile_picture_place)))
#define TEST_MENU_LINE(address) ((const struct test_menu_line *)data_record((address), sizeof(struct test_menu_line)))
#define PATH_STEP(address) ((const struct path_step *)data_record((address), sizeof(struct path_step)))
#define PATH_START(address) ((const struct path_start *)data_record((address), sizeof(struct path_start)))
#define DEMO_INPUT(address) ((const struct demo_input *)data_record((address), sizeof(struct demo_input)))
#define TEST_PALETTE(address) ((const struct test_palette *)data_record((address), sizeof(struct test_palette)))
#define VECTOR(address) ((const struct vector *)data_record((address), sizeof(struct vector)))
#define ENEMY_BEHAVIOUR(address) ((const struct enemy_behaviour *)data_record((address), sizeof(struct enemy_behaviour)))
#define BEHAVIOUR_CHOICE(address) ((const struct behaviour_choice *)data_record((address), sizeof(struct behaviour_choice)))
#define GAUGE_PLAYER(address) ((const struct gauge_player *)data_record((address), sizeof(struct gauge_player)))
#define TEST_PLAYER(address) ((const struct test_player *)data_record((address), sizeof(struct test_player)))
#define PLACEMENT(address) ((const struct placement *)data_record((address), sizeof(struct placement)))
#define PLAYER_KIND(address) ((const struct player_kind *)data_record((address), sizeof(struct player_kind)))
#define STAGE_SLOT(address) ((const struct stage_slot *)data_record((address), sizeof(struct stage_slot)))
#define HIT_BOX(address) ((const struct hit_box *)data_record((address), sizeof(struct hit_box)))
#define PART(address) ((const struct part *)data_record((address), sizeof(struct part)))
#define PATTERN_START(address) ((const struct pattern_start *)data_record((address), sizeof(struct pattern_start)))
#define PART_OFFSET(address) ((const struct part_offset *)data_record((address), sizeof(struct part_offset)))
#define BONUS_PLAYER(address) ((const struct bonus_player *)data_record((address), sizeof(struct bonus_player)))
#define XZ_OFFSET(address) ((const struct xz_offset *)data_record((address), sizeof(struct xz_offset)))
#define NAME_ENTRY_PLAYER(address) ((const struct name_entry_player *)data_record((address), sizeof(struct name_entry_player)))
#define SCORE_ADDRESS(address) (*(const uint16_t *)data_record((address), 2))
#define SCORE_ADDRESS_8(address) (*(const uint8_t *)data_record((address), 1))
#define SCORE_ADDRESS_32(address) (*(const uint32_t *)data_record((address), 4))
#define PLACE_SUFFIX(address) ((const struct place_suffix *)data_record((address), sizeof(struct place_suffix)))
#define NAME_ENTRY_BLOCK(address) ((const struct name_entry_block *)data_record((address), sizeof(struct name_entry_block)))
#define NAME_ENTRY_COLUMN(address) ((const struct name_entry_column *)data_record((address), sizeof(struct name_entry_column)))
#define HIGH_SCORE_ICON(address) (*(const uint8_t *)data_record((address), 1))
#define HIGH_SCORE_ICON_16(address) (*(const uint16_t *)data_record((address), 2))
#define HIGH_SCORE_ICON_32(address) (*(const uint32_t *)data_record((address), 4))
#define CHARGE_WAIT(address) (*(const uint16_t *)data_record((address), 2))
#define CHARGE_WAIT_8(address) (*(const uint8_t *)data_record((address), 1))
#define CHARGE_WAIT_32(address) (*(const uint32_t *)data_record((address), 4))
#define HELPER_START(address) ((const struct helper_start *)data_record((address), sizeof(struct helper_start)))
#define HELPER_DISTANCE(address) (*(const uint16_t *)data_record((address), 2))
#define HELPER_DISTANCE_8(address) (*(const uint8_t *)data_record((address), 1))
#define HELPER_DISTANCE_32(address) (*(const uint32_t *)data_record((address), 4))
#define GAME_TEXT_ENTRY(address) (*(const uint16_t *)data_record((address), 2))
#define GAME_TEXT_ENTRY_8(address) (*(const uint8_t *)data_record((address), 1))
#define GAME_TEXT_ENTRY_32(address) (*(const uint32_t *)data_record((address), 4))
#define EXIT_SPEED(address) ((const struct exit_speed *)data_record((address), sizeof(struct exit_speed)))
#define PLAYER_BLANK(address) ((const struct player_blank *)data_record((address), sizeof(struct player_blank)))
#define WAVE_COSINE(address) (*(const uint8_t *)data_record((address), 1))
#define WAVE_COSINE_16(address) (*(const uint16_t *)data_record((address), 2))
#define WAVE_COSINE_32(address) (*(const uint32_t *)data_record((address), 4))
#define SHAKE_STEP(address) ((const struct shake_step *)data_record((address), sizeof(struct shake_step)))
#define LAYER_SCROLL(address) ((const struct layer_scroll *)data_record((address), sizeof(struct layer_scroll)))
#define LAYER_OFFSET_STEP(address) ((const struct layer_offset_step *)data_record((address), sizeof(struct layer_offset_step)))
#define LAYER_STEP_WORD(address) (*(const uint16_t *)data_record((address), 2))
#define LAYER_STEP_WORD_8(address) (*(const uint8_t *)data_record((address), 1))
#define LAYER_STEP_WORD_32(address) (*(const uint32_t *)data_record((address), 4))
#define GOON_ENTRANCE(address) ((const struct goon_entrance *)data_record((address), sizeof(struct goon_entrance)))
#define DESCENT_START(address) ((const struct descent_start *)data_record((address), sizeof(struct descent_start)))
#define WAITING_HAT_GOON_START(address) ((const struct waiting_hat_goon_start *)data_record((address), sizeof(struct waiting_hat_goon_start)))
#define GOON_WALK_IN_START(address) ((const struct goon_walk_in_start *)data_record((address), sizeof(struct goon_walk_in_start)))
#define DELAYED_START(address) ((const struct delayed_start *)data_record((address), sizeof(struct delayed_start)))
#define GOON_SIDE_ENTRY(address) ((const struct goon_side_entry *)data_record((address), sizeof(struct goon_side_entry)))
#define GOON_RUN_IN_START(address) ((const struct goon_run_in_start *)data_record((address), sizeof(struct goon_run_in_start)))
#define HAT_GOON_JUMP_IN_START(address) ((const struct hat_goon_jump_in_start *)data_record((address), sizeof(struct hat_goon_jump_in_start)))
#define FAT_GOON_DROP_ROUTE(address) ((const struct fat_goon_drop_route *)data_record((address), sizeof(struct fat_goon_drop_route)))
#define TIMED_SPAWN(address) ((const struct timed_spawn *)data_record((address), sizeof(struct timed_spawn)))
#define DOOR_RELEASE(address) ((const struct door_release *)data_record((address), sizeof(struct door_release)))
#define KRUSTYLAND_DOOR(address) ((const struct krustyland_door *)data_record((address), sizeof(struct krustyland_door)))
#define PROP(address) ((const struct prop *)data_record((address), sizeof(struct prop)))
#define DREAM_BALL_FLING(address) ((const struct dream_ball_fling *)data_record((address), sizeof(struct dream_ball_fling)))
#define CEMETERY_PIECE(address) ((const struct cemetery_piece *)data_record((address), sizeof(struct cemetery_piece)))
#define POLICE_CAR_ARRIVAL(address) ((const struct police_car_arrival *)data_record((address), sizeof(struct police_car_arrival)))
#define POLICE_CAR_DOOR(address) ((const struct police_car_door *)data_record((address), sizeof(struct police_car_door)))
#define CAR_DOOR_RELEASE(address) ((const struct car_door_release *)data_record((address), sizeof(struct car_door_release)))
#define FLOOR_COLUMN(address) ((const struct floor_column *)data_record((address), sizeof(struct floor_column)))
#define BOULDER_DROP(address) ((const struct boulder_drop *)data_record((address), sizeof(struct boulder_drop)))
#define OBJECT_16_ANIMATION_RUN(address) ((const struct object_16_animation_run *)data_record((address), sizeof(struct object_16_animation_run)))
#define RUNNING_ANIMAL(address) ((const struct running_animal *)data_record((address), sizeof(struct running_animal)))
#define RUNNING_ANIMAL_TIMING(address) ((const struct running_animal_timing *)data_record((address), sizeof(struct running_animal_timing)))
#define OBSTACLE_DROP(address) ((const struct obstacle_drop *)data_record((address), sizeof(struct obstacle_drop)))
#define LOOPING_SCENERY_MOVE(address) ((const struct looping_scenery_move *)data_record((address), sizeof(struct looping_scenery_move)))
#define FOOD_MOVE(address) ((const struct food_move *)data_record((address), sizeof(struct food_move)))
#define BYSTANDER_ANIMATION_SET(address) ((const struct bystander_animation_set *)data_record((address), sizeof(struct bystander_animation_set)))
#define BYSTANDER(address) ((const struct bystander *)data_record((address), sizeof(struct bystander)))
#define FIREMAN_GOON_START(address) ((const struct fireman_goon_start *)data_record((address), sizeof(struct fireman_goon_start)))
#define TEACUP_GOON_ATTRIBUTES(address) (*(const uint8_t *)data_record((address), 1))
#define TEACUP_GOON_ATTRIBUTES_16(address) (*(const uint16_t *)data_record((address), 2))
#define TEACUP_GOON_ATTRIBUTES_32(address) (*(const uint32_t *)data_record((address), 4))
#define CLOWN_POSE(address) ((const struct clown_pose *)data_record((address), sizeof(struct clown_pose)))
#define BLUEBIRD_ENTRY(address) ((const struct bluebird_entry *)data_record((address), sizeof(struct bluebird_entry)))
#define BLUEBIRD_LAUNCH(address) ((const struct bluebird_launch *)data_record((address), sizeof(struct bluebird_launch)))
#define RANDOM_POSE_FIGURE(address) ((const struct random_pose_figure *)data_record((address), sizeof(struct random_pose_figure)))
#define CHILD_OBJECT(address) ((const struct child_object *)data_record((address), sizeof(struct child_object)))
#define VELOCITY(address) ((const struct velocity *)data_record((address), sizeof(struct velocity)))
#define BOB_HEIGHT(address) (*(const int8_t *)data_record((address), 1))
#define BOB_HEIGHT_16(address) (*(const uint16_t *)data_record((address), 2))
#define BOB_HEIGHT_32(address) (*(const uint32_t *)data_record((address), 4))
#define TIMED_MOVE(address) ((const struct timed_move *)data_record((address), sizeof(struct timed_move)))
#define DROP_START(address) ((const struct drop_start *)data_record((address), sizeof(struct drop_start)))
#define APPEARANCE(address) ((const struct appearance *)data_record((address), sizeof(struct appearance)))
#define TIMED_SPOT(address) ((const struct timed_spot *)data_record((address), sizeof(struct timed_spot)))
#define GORILLA_ENTRANCE(address) ((const struct gorilla_entrance *)data_record((address), sizeof(struct gorilla_entrance)))
#define KNIGHT_ENTRANCE(address) ((const struct knight_entrance *)data_record((address), sizeof(struct knight_entrance)))
#define KNIGHT_ENTRANCE_STYLE(address) ((const struct knight_entrance_style *)data_record((address), sizeof(struct knight_entrance_style)))
#define POSE(address) ((const struct pose *)data_record((address), sizeof(struct pose)))
#define ROBOT_PIECE(address) ((const struct robot_piece *)data_record((address), sizeof(struct robot_piece)))
#define CHANNEL_6_SCENERY_PART(address) ((const struct channel_6_scenery_part *)data_record((address), sizeof(struct channel_6_scenery_part)))
#define TIMED_STEP(address) ((const struct timed_step *)data_record((address), sizeof(struct timed_step)))
#define OBJECT_1A_LEVEL(address) (*(const uint8_t *)data_record((address), 1))
#define OBJECT_1A_LEVEL_16(address) (*(const uint16_t *)data_record((address), 2))
#define OBJECT_1A_LEVEL_32(address) (*(const uint32_t *)data_record((address), 4))
#define LAUNCH(address) ((const struct launch *)data_record((address), sizeof(struct launch)))
#define CHAIN_LINK(address) ((const struct chain_link *)data_record((address), sizeof(struct chain_link)))
#define DOOR_SPAWN(address) ((const struct door_spawn *)data_record((address), sizeof(struct door_spawn)))
#define DOOR_OPENING(address) ((const struct door_opening *)data_record((address), sizeof(struct door_opening)))
#define PLAYER_MOVE(address) ((const struct player_move *)data_record((address), sizeof(struct player_move)))
#define ATTACK_BOX(address) ((const struct attack_box *)data_record((address), sizeof(struct attack_box)))
#define TEAM_MOVE(address) ((const struct team_move *)data_record((address), sizeof(struct team_move)))
#define SECOND_OBJECT_FACING(address) (*(const uint8_t *)data_record((address), 1))
#define SECOND_OBJECT_FACING_16(address) (*(const uint16_t *)data_record((address), 2))
#define SECOND_OBJECT_FACING_32(address) (*(const uint32_t *)data_record((address), 4))
#define STATE_START(address) ((const struct state_start *)data_record((address), sizeof(struct state_start)))
#define BEATEN_HEALTH(address) (*(const uint8_t *)data_record((address), 1))
#define BEATEN_HEALTH_16(address) (*(const uint16_t *)data_record((address), 2))
#define BEATEN_HEALTH_32(address) (*(const uint32_t *)data_record((address), 4))
#define QUICK_ATTACK_CHANCE(address) (*(const uint8_t *)data_record((address), 1))
#define QUICK_ATTACK_CHANCE_16(address) (*(const uint16_t *)data_record((address), 2))
#define QUICK_ATTACK_CHANCE_32(address) (*(const uint32_t *)data_record((address), 4))
#define WALK_SPEED(address) (*(const uint8_t *)data_record((address), 1))
#define WALK_SPEED_16(address) (*(const uint16_t *)data_record((address), 2))
#define WALK_SPEED_32(address) (*(const uint32_t *)data_record((address), 4))
#define LINE_PIECE(address) ((const struct line_piece *)data_record((address), sizeof(struct line_piece)))
#define PART_FLIGHT(address) ((const struct part_flight *)data_record((address), sizeof(struct part_flight)))
#define PROFILE_MOVE(address) ((const struct profile_move *)data_record((address), sizeof(struct profile_move)))
#define GAUGE_COLUMN(address) ((const struct gauge_column *)data_record((address), sizeof(struct gauge_column)))
#define BIG_DIGIT(address) ((const struct big_digit *)data_record((address), sizeof(struct big_digit)))
#define GAUGE_STEP(address) ((const struct gauge_step *)data_record((address), sizeof(struct gauge_step)))
#define RANK_AMOUNT(address) (*(const uint8_t *)data_record((address), 1))
#define RANK_AMOUNT_16(address) (*(const uint16_t *)data_record((address), 2))
#define RANK_AMOUNT_32(address) (*(const uint32_t *)data_record((address), 4))
#define PORTRAIT_AREA(address) ((const struct portrait_area *)data_record((address), sizeof(struct portrait_area)))
#define SOUND_TEST_COMMAND(address) (*(const uint16_t *)data_record((address), 2))
#define SOUND_TEST_COMMAND_8(address) (*(const uint8_t *)data_record((address), 1))
#define SOUND_TEST_COMMAND_32(address) (*(const uint32_t *)data_record((address), 4))
#define PLAYER(address) ((const struct player *)data_record((address), sizeof(struct player)))
#define SCORE_ADDITION(address) ((const struct score_addition *)data_record((address), sizeof(struct score_addition)))
#define DEMO(address) ((const struct demo *)data_record((address), sizeof(struct demo)))
#define SCENE_ROUTINE(address) ((const struct scene_routine *)data_record((address), sizeof(struct scene_routine)))
#define PALETTE_EFFECT(address) ((const struct palette_effect *)data_record((address), sizeof(struct palette_effect)))
#define PALETTE_EFFECT_STEP(address) ((const struct palette_effect_step *)data_record((address), sizeof(struct palette_effect_step)))
#define PALETTE_SET(address) (*(const uint16_t *)data_record((address), 2))
#define PALETTE_SET_8(address) (*(const uint8_t *)data_record((address), 1))
#define PALETTE_SET_32(address) (*(const uint32_t *)data_record((address), 4))
#define FADE_RANGE(address) ((const struct fade_range *)data_record((address), sizeof(struct fade_range)))
#define PALETTE_CLEAR(address) ((const struct palette_clear *)data_record((address), sizeof(struct palette_clear)))
#define HURT_EFFECT_ROW(address) ((const struct hurt_effect_row *)data_record((address), sizeof(struct hurt_effect_row)))
#define ANIMATION_SET_INDEX(address) (*(const uint16_t *)data_record((address), 2))
#define ANIMATION_SET_INDEX_8(address) (*(const uint8_t *)data_record((address), 1))
#define ANIMATION_SET_INDEX_32(address) (*(const uint32_t *)data_record((address), 4))
#define ANIMATION_TABLE(address) (*(const uint16_t *)data_record((address), 2))
#define ANIMATION_TABLE_8(address) (*(const uint8_t *)data_record((address), 1))
#define ANIMATION_TABLE_32(address) (*(const uint32_t *)data_record((address), 4))
#define SCENE_AREA(address) ((const struct scene_area *)data_record((address), sizeof(struct scene_area)))
#define SCENE_AREA_LIST(address) (*(const uint16_t *)data_record((address), 2))
#define SCENE_AREA_LIST_8(address) (*(const uint8_t *)data_record((address), 1))
#define SCENE_AREA_LIST_32(address) (*(const uint32_t *)data_record((address), 4))
#define LAYER_MODE(address) ((const struct layer_mode *)data_record((address), sizeof(struct layer_mode)))
#define LAYER_MODE_LIST(address) (*(const uint16_t *)data_record((address), 2))
#define LAYER_MODE_LIST_8(address) (*(const uint8_t *)data_record((address), 1))
#define LAYER_MODE_LIST_32(address) (*(const uint32_t *)data_record((address), 4))
#define TILE_PICTURE(address) ((const struct tile_picture *)data_record((address), sizeof(struct tile_picture)))
#define TILE_PICTURE_ENTRY(address) (*(const uint16_t *)data_record((address), 2))
#define TILE_PICTURE_ENTRY_8(address) (*(const uint8_t *)data_record((address), 1))
#define TILE_PICTURE_ENTRY_32(address) (*(const uint32_t *)data_record((address), 4))
#define HIT_ANIMATION(address) (*(const uint8_t *)data_record((address), 1))
#define HIT_ANIMATION_16(address) (*(const uint16_t *)data_record((address), 2))
#define HIT_ANIMATION_32(address) (*(const uint32_t *)data_record((address), 4))
#define OBJECT(address) ((struct object *)ram((address), sizeof(struct object)))
#define OBJECT_SETUP(address) ((const struct object_setup *)data_record((address), sizeof(struct object_setup)))
#define PALETTE_JOB(address) ((struct palette_job *)ram((address), sizeof(struct palette_job)))
#define SPRITE_ENTRY(address) ((struct sprite_entry *)ram((address), sizeof(struct sprite_entry)))
#define QUEUED_JOB(address) ((struct queued_job *)ram((address), sizeof(struct queued_job)))
#define PLAYER_INPUT(address) ((struct player_input *)ram((address), sizeof(struct player_input)))
#define SHAPE_COLUMN(address) ((const struct shape_column *)data_record((address), sizeof(struct shape_column)))
#define FIGURE_POSE(address) (*(const uint8_t *)data_record((address), 1))
#define FIGURE_POSE_16(address) (*(const uint16_t *)data_record((address), 2))
#define FIGURE_POSE_32(address) (*(const uint32_t *)data_record((address), 4))
#define BOSS_BOX(address) ((const struct boss_box *)data_record((address), sizeof(struct boss_box)))
#define GAUGE_HEALTH(address) (*(const uint8_t *)data_record((address), 1))
#define GAUGE_HEALTH_16(address) (*(const uint16_t *)data_record((address), 2))
#define GAUGE_HEALTH_32(address) (*(const uint32_t *)data_record((address), 4))
#define ATTACK_RANGE(address) ((const struct attack_range *)data_record((address), sizeof(struct attack_range)))
#define PLAYER_VALUES(address) ((struct player_values *)ram((address), sizeof(struct player_values)))
#define COIN_SLOT(address) ((struct coin_slot *)ram((address), sizeof(struct coin_slot)))
#define PLAYER_COUNTERS(address) ((struct player_counters *)ram((address), sizeof(struct player_counters)))
#define DEMO_PLAYBACK(address) ((struct demo_playback *)ram((address), sizeof(struct demo_playback)))
#define ATTRACT_PICTURE(address) ((const struct attract_picture *)data_record((address), sizeof(struct attract_picture)))
#define STORY_OBJECT_START(address) ((const struct story_object_start *)data_record((address), sizeof(struct story_object_start)))
#define CAMERA_ENTRY(address) ((const struct camera_entry *)data_record((address), sizeof(struct camera_entry)))
#define CAMERA_CHECK(address) ((const struct camera_check *)data_record((address), sizeof(struct camera_check)))
#define BEHAVIOUR_CHANCE(address) (*(const uint8_t *)data_record((address), 1))
#define BEHAVIOUR_CHANCE_16(address) (*(const uint16_t *)data_record((address), 2))
#define BEHAVIOUR_CHANCE_32(address) (*(const uint32_t *)data_record((address), 4))
#define BEHAVIOUR_ACTION(address) (*(const uint8_t *)data_record((address), 1))
#define BEHAVIOUR_ACTION_16(address) (*(const uint16_t *)data_record((address), 2))
#define BEHAVIOUR_ACTION_32(address) (*(const uint32_t *)data_record((address), 4))

/* the program ROM's tables of records, by name: name[i].field */
#define bonus_1_players_ADDRESS 0x7BD0u    /* 021BD0 */
extern const void *bonus_1_players_data;
#define bonus_1_players ((const struct bonus_player *)(bonus_1_players_data))
#define bonus_placement_records_ADDRESS 0x7C38u    /* 021C38 */
extern const void *bonus_placement_records_data;
#define bonus_placement_records ((const struct placement *)(bonus_placement_records_data))
#define bonus_2_level_object_offsets_ADDRESS 0x7D71u    /* 021D71 */
extern const void *bonus_2_level_object_offsets_data;
#define bonus_2_level_object_offsets ((const struct xz_offset *)(bonus_2_level_object_offsets_data))
#define wrestler_hit_boxes_ADDRESS 0x7E99u    /* 021E99 */
extern const void *wrestler_hit_boxes_data;
#define wrestler_hit_boxes ((const struct hit_box *)(wrestler_hit_boxes_data))
#define place_suffixes_ADDRESS 0x751Eu    /* 02351E */
extern const void *place_suffixes_data;
#define place_suffixes ((const struct place_suffix *)(place_suffixes_data))
#define name_entry_players_ADDRESS 0x753Au    /* 02353A */
extern const void *name_entry_players_data;
#define name_entry_players ((const struct name_entry_player *)(name_entry_players_data))
#define name_entry_columns_ADDRESS 0x767Bu    /* 02367B */
extern const void *name_entry_columns_data;
#define name_entry_columns ((const struct name_entry_column *)(name_entry_columns_data))
#define ending_placements_ADDRESS 0x7706u    /* 023706 */
extern const void *ending_placements_data;
#define ending_placements ((const struct placement *)(ending_placements_data))
#define stage_7_boss_hit_boxes_ADDRESS 0x7A71u    /* 023A71 */
extern const void *stage_7_boss_hit_boxes_data;
#define stage_7_boss_hit_boxes ((const struct hit_box *)(stage_7_boss_hit_boxes_data))
#define stage_7_boss_helper_starts_ADDRESS 0x7AD9u    /* 023AD9 */
extern const void *stage_7_boss_helper_starts_data;
#define stage_7_boss_helper_starts ((const struct helper_start *)(stage_7_boss_helper_starts_data))
#define object_12_placements_ADDRESS 0x77BAu    /* 0257BA */
extern const void *object_12_placements_data;
#define object_12_placements ((const struct placement *)(object_12_placements_data))
#define unused_player_kind_list_ADDRESS 0x7952u    /* 025952 */
extern const void *unused_player_kind_list_data;
#define unused_player_kind_list ((const struct player_kind *)(unused_player_kind_list_data))
#define stage_end_exit_speeds_ADDRESS 0x7966u    /* 025966 */
extern const void *stage_end_exit_speeds_data;
#define stage_end_exit_speeds ((const struct exit_speed *)(stage_end_exit_speeds_data))
#define stage_slots_ADDRESS 0x600Cu    /* 02600C */
extern const void *stage_slots_data;
#define stage_slots ((const struct stage_slot *)(stage_slots_data))
#define screen_shake_steps_ADDRESS 0x7A00u    /* 027A00 */
extern const void *screen_shake_steps_data;
#define screen_shake_steps ((const struct shake_step *)(screen_shake_steps_data))
#define layer_scrolls_ADDRESS 0x7A3Bu    /* 027A3B */
extern const void *layer_scrolls_data;
#define layer_scrolls ((const struct layer_scroll *)(layer_scrolls_data))
#define stage_3_part_2_layer_offsets_ADDRESS 0x7A5Bu    /* 027A5B */
extern const void *stage_3_part_2_layer_offsets_data;
#define stage_3_part_2_layer_offsets ((const struct layer_offset_step *)(stage_3_part_2_layer_offsets_data))
#define krusty_balloon_hit_boxes_ADDRESS 0x7CD0u    /* 027CD0 */
extern const void *krusty_balloon_hit_boxes_data;
#define krusty_balloon_hit_boxes ((const struct hit_box *)(krusty_balloon_hit_boxes_data))
#define stage_title_placements_ADDRESS 0x7E81u    /* 027E81 */
extern const void *stage_title_placements_data;
#define stage_title_placements ((const struct placement *)(stage_title_placements_data))
#define goon_jump_table_spare_slots_ADDRESS 0x607Eu    /* 02807E */
extern const void *goon_jump_table_spare_slots_data;
#define goon_jump_table_spare_slots ((const struct vector *)(goon_jump_table_spare_slots_data))
#define goon_jump_table_spare_slot_ADDRESS 0x60B1u    /* 0280B1 */
extern const void *goon_jump_table_spare_slot_data;
#define goon_jump_table_spare_slot ((const struct vector *)(goon_jump_table_spare_slot_data))
#define goon_actions_jump_table_spare_slot_ADDRESS 0x60BDu    /* 0280BD */
extern const void *goon_actions_jump_table_spare_slot_data;
#define goon_actions_jump_table_spare_slot ((const struct vector *)(goon_actions_jump_table_spare_slot_data))
#define goon_descent_starts_ADDRESS 0x79F4u    /* 0299F4 */
extern const void *goon_descent_starts_data;
#define goon_descent_starts ((const struct descent_start *)(goon_descent_starts_data))
#define waiting_hat_goon_starts_ADDRESS 0x7A86u    /* 029A86 */
extern const void *waiting_hat_goon_starts_data;
#define waiting_hat_goon_starts ((const struct waiting_hat_goon_start *)(waiting_hat_goon_starts_data))
#define goon_walk_in_starts_ADDRESS 0x7AAEu    /* 029AAE */
extern const void *goon_walk_in_starts_data;
#define goon_walk_in_starts ((const struct goon_walk_in_start *)(goon_walk_in_starts_data))
#define delayed_goon_starts_ADDRESS 0x7AD2u    /* 029AD2 */
extern const void *delayed_goon_starts_data;
#define delayed_goon_starts ((const struct delayed_start *)(delayed_goon_starts_data))
#define goon_entrances_ADDRESS 0x7B16u    /* 029B16 */
extern const void *goon_entrances_data;
#define goon_entrances ((const struct goon_entrance *)(goon_entrances_data))
#define goon_side_entries_ADDRESS 0x7B68u    /* 029B68 */
extern const void *goon_side_entries_data;
#define goon_side_entries ((const struct goon_side_entry *)(goon_side_entries_data))
#define goon_run_in_starts_ADDRESS 0x7B7Eu    /* 029B7E */
extern const void *goon_run_in_starts_data;
#define goon_run_in_starts ((const struct goon_run_in_start *)(goon_run_in_starts_data))
#define hat_goon_jump_in_starts_ADDRESS 0x7B98u    /* 029B98 */
extern const void *hat_goon_jump_in_starts_data;
#define hat_goon_jump_in_starts ((const struct hat_goon_jump_in_start *)(hat_goon_jump_in_starts_data))
#define fat_goon_drop_routes_ADDRESS 0x7822u    /* 02B822 */
extern const void *fat_goon_drop_routes_data;
#define fat_goon_drop_routes ((const struct fat_goon_drop_route *)(fat_goon_drop_routes_data))
#define fat_goon_entrances_ADDRESS 0x784Au    /* 02B84A */
extern const void *fat_goon_entrances_data;
#define fat_goon_entrances ((const struct goon_entrance *)(fat_goon_entrances_data))
#define delayed_fat_goon_starts_ADDRESS 0x78C0u    /* 02B8C0 */
extern const void *delayed_fat_goon_starts_data;
#define delayed_fat_goon_starts ((const struct delayed_start *)(delayed_fat_goon_starts_data))
#define fat_goon_descent_starts_ADDRESS 0x78EEu    /* 02B8EE */
extern const void *fat_goon_descent_starts_data;
#define fat_goon_descent_starts ((const struct descent_start *)(fat_goon_descent_starts_data))
#define krustyland_doors_ADDRESS 0x7DC2u    /* 02BDC2 */
extern const void *krustyland_doors_data;
#define krustyland_doors ((const struct krustyland_door *)(krustyland_doors_data))
#define props_ADDRESS 0x7E23u    /* 02BE23 */
extern const void *props_data;
#define props ((const struct prop *)(props_data))
#define dream_ball_flings_ADDRESS 0x7E89u    /* 02BE89 */
extern const void *dream_ball_flings_data;
#define dream_ball_flings ((const struct dream_ball_fling *)(dream_ball_flings_data))
#define cemetery_pieces_ADDRESS 0x7EA5u    /* 02BEA5 */
extern const void *cemetery_pieces_data;
#define cemetery_pieces ((const struct cemetery_piece *)(cemetery_pieces_data))
#define police_car_arrivals_ADDRESS 0x7F69u    /* 02BF69 */
extern const void *police_car_arrivals_data;
#define police_car_arrivals ((const struct police_car_arrival *)(police_car_arrivals_data))
#define scenery_jump_table_spare_slots_ADDRESS 0x6030u    /* 02C030 */
extern const void *scenery_jump_table_spare_slots_data;
#define scenery_jump_table_spare_slots ((const struct vector *)(scenery_jump_table_spare_slots_data))
#define scenery_jump_table_spare_slot_ADDRESS 0x6057u    /* 02C057 */
extern const void *scenery_jump_table_spare_slot_data;
#define scenery_jump_table_spare_slot ((const struct vector *)(scenery_jump_table_spare_slot_data))
#define moes_street_scenery_edge_floor_cells_ADDRESS 0x7C12u    /* 02DC12 */
extern const void *moes_street_scenery_edge_floor_cells_data;
#define moes_street_scenery_edge_floor_cells ((const struct floor_column *)(moes_street_scenery_edge_floor_cells_data))
#define moes_street_scenery_floor_cells_ADDRESS 0x7C18u    /* 02DC18 */
extern const void *moes_street_scenery_floor_cells_data;
#define moes_street_scenery_floor_cells ((const struct floor_column *)(moes_street_scenery_floor_cells_data))
#define police_car_doors_ADDRESS 0x7C2Eu    /* 02DC2E */
extern const void *police_car_doors_data;
#define police_car_doors ((const struct police_car_door *)(police_car_doors_data))
#define boulder_drops_ADDRESS 0x7DF5u    /* 02DDF5 */
extern const void *boulder_drops_data;
#define boulder_drops ((const struct boulder_drop *)(boulder_drops_data))
#define object_16_kinds_ADDRESS 0x7E3Fu    /* 02DE3F */
extern const void *object_16_kinds_data;
#define object_16_kinds ((const struct pattern_start *)(object_16_kinds_data))
#define object_16_animation_runs_ADDRESS 0x7E95u    /* 02DE95 */
extern const void *object_16_animation_runs_data;
#define object_16_animation_runs ((const struct object_16_animation_run *)(object_16_animation_runs_data))
#define running_animals_ADDRESS 0x7EF9u    /* 02DEF9 */
extern const void *running_animals_data;
#define running_animals ((const struct running_animal *)(running_animals_data))
#define running_animal_timings_ADDRESS 0x7F05u    /* 02DF05 */
extern const void *running_animal_timings_data;
#define running_animal_timings ((const struct running_animal_timing *)(running_animal_timings_data))
#define dreamland_obstacle_drops_ADDRESS 0x7F47u    /* 02DF47 */
extern const void *dreamland_obstacle_drops_data;
#define dreamland_obstacle_drops ((const struct obstacle_drop *)(dreamland_obstacle_drops_data))
#define looping_scenery_moves_ADDRESS 0x7A12u    /* 02FA12 */
extern const void *looping_scenery_moves_data;
#define looping_scenery_moves ((const struct looping_scenery_move *)(looping_scenery_moves_data))
#define food_moves_ADDRESS 0x7AA4u    /* 02FAA4 */
extern const void *food_moves_data;
#define food_moves ((const struct food_move *)(food_moves_data))
#define bystanders_ADDRESS 0x7BCBu    /* 02FBCB */
extern const void *bystanders_data;
#define bystanders ((const struct bystander *)(bystanders_data))
#define bystander_animation_sets_ADDRESS 0x7BD3u    /* 02FBD3 */
extern const void *bystander_animation_sets_data;
#define bystander_animation_sets ((const struct bystander_animation_set *)(bystander_animation_sets_data))
#define fireman_goon_starts_ADDRESS 0x7C59u    /* 02FC59 */
extern const void *fireman_goon_starts_data;
#define fireman_goon_starts ((const struct fireman_goon_start *)(fireman_goon_starts_data))
#define clown_on_ball_poses_ADDRESS 0x7E6Bu    /* 02FE6B */
extern const void *clown_on_ball_poses_data;
#define clown_on_ball_poses ((const struct clown_pose *)(clown_on_ball_poses_data))
#define bluebird_entries_ADDRESS 0x7F6Bu    /* 02FF6B */
extern const void *bluebird_entries_data;
#define bluebird_entries ((const struct bluebird_entry *)(bluebird_entries_data))
#define bluebird_launches_ADDRESS 0x7F8Bu    /* 02FF8B */
extern const void *bluebird_launches_data;
#define bluebird_launches ((const struct bluebird_launch *)(bluebird_launches_data))
#define random_pose_figures_ADDRESS 0x7FADu    /* 02FFAD */
extern const void *random_pose_figures_data;
#define random_pose_figures ((const struct random_pose_figure *)(random_pose_figures_data))
#define kind_97_timed_moves_ADDRESS 0x7988u    /* 031988 */
extern const void *kind_97_timed_moves_data;
#define kind_97_timed_moves ((const struct timed_move *)(kind_97_timed_moves_data))
#define object_18_behaviours_ADDRESS 0x79DAu    /* 0319DA */
extern const void *object_18_behaviours_data;
#define object_18_behaviours ((const struct behaviour_choice *)(object_18_behaviours_data))
#define ghost_on_rope_drop_starts_ADDRESS 0x7A30u    /* 031A30 */
extern const void *ghost_on_rope_drop_starts_data;
#define ghost_on_rope_drop_starts ((const struct drop_start *)(ghost_on_rope_drop_starts_data))
#define kind_91_appearances_ADDRESS 0x7A56u    /* 031A56 */
extern const void *kind_91_appearances_data;
#define kind_91_appearances ((const struct appearance *)(kind_91_appearances_data))
#define kind_97_entrances_ADDRESS 0x7AF8u    /* 031AF8 */
extern const void *kind_97_entrances_data;
#define kind_97_entrances ((const struct timed_spot *)(kind_97_entrances_data))
#define gorilla_entrances_ADDRESS 0x7C3Bu    /* 031C3B */
extern const void *gorilla_entrances_data;
#define gorilla_entrances ((const struct gorilla_entrance *)(gorilla_entrances_data))
#define knight_entrances_ADDRESS 0x7CF7u    /* 031CF7 */
extern const void *knight_entrances_data;
#define knight_entrances ((const struct knight_entrance *)(knight_entrances_data))
#define knight_entrance_styles_ADDRESS 0x7D51u    /* 031D51 */
extern const void *knight_entrance_styles_data;
#define knight_entrance_styles ((const struct knight_entrance_style *)(knight_entrance_styles_data))
#define kind_c7_slow_velocities_ADDRESS 0x7E20u    /* 031E20 */
extern const void *kind_c7_slow_velocities_data;
#define kind_c7_slow_velocities ((const struct velocity *)(kind_c7_slow_velocities_data))
#define kind_c7_fast_velocities_ADDRESS 0x7E60u    /* 031E60 */
extern const void *kind_c7_fast_velocities_data;
#define kind_c7_fast_velocities ((const struct velocity *)(kind_c7_fast_velocities_data))
#define unused_figure_hit_box_ADDRESS 0x7ED8u    /* 031ED8 */
extern const void *unused_figure_hit_box_data;
#define unused_figure_hit_box ((const struct hit_box *)(unused_figure_hit_box_data))
#define belly_dancer_poses_ADDRESS 0x7F52u    /* 031F52 */
extern const void *belly_dancer_poses_data;
#define belly_dancer_poses ((const struct pose *)(belly_dancer_poses_data))
#define stage_7_objects_jump_table_spare_slot_ADDRESS 0x6024u    /* 032024 */
extern const void *stage_7_objects_jump_table_spare_slot_data;
#define stage_7_objects_jump_table_spare_slot ((const struct vector *)(stage_7_objects_jump_table_spare_slot_data))
#define robot_pieces_ADDRESS 0x7B10u    /* 033B10 */
extern const void *robot_pieces_data;
#define robot_pieces ((const struct robot_piece *)(robot_pieces_data))
#define robot_piece_children_ADDRESS 0x7CC8u    /* 033CC8 */
extern const void *robot_piece_children_data;
#define robot_piece_children ((const struct child_object *)(robot_piece_children_data))
#define channel_6_scenery_parts_ADDRESS 0x7D96u    /* 033D96 */
extern const void *channel_6_scenery_parts_data;
#define channel_6_scenery_parts ((const struct channel_6_scenery_part *)(channel_6_scenery_parts_data))
#define kind_b7_entrances_ADDRESS 0x7E32u    /* 033E32 */
extern const void *kind_b7_entrances_data;
#define kind_b7_entrances ((const struct timed_step *)(kind_b7_entrances_data))
#define flying_saxophone_velocities_ADDRESS 0x7F55u    /* 033F55 */
extern const void *flying_saxophone_velocities_data;
#define flying_saxophone_velocities ((const struct velocity *)(flying_saxophone_velocities_data))
#define dreamland_jump_table_spare_slots_ADDRESS 0x6000u    /* 034000 */
extern const void *dreamland_jump_table_spare_slots_data;
#define dreamland_jump_table_spare_slots ((const struct vector *)(dreamland_jump_table_spare_slots_data))
#define unused_dreamland_spawn_list_ADDRESS 0x74C5u    /* 0354C5 */
extern const void *unused_dreamland_spawn_list_data;
#define unused_dreamland_spawn_list ((const struct spawn *)(unused_dreamland_spawn_list_data))
#define object_1a_launches_ADDRESS 0x7926u    /* 035926 */
extern const void *object_1a_launches_data;
#define object_1a_launches ((const struct launch *)(object_1a_launches_data))
#define object_1a_chain_links_ADDRESS 0x79A6u    /* 0359A6 */
extern const void *object_1a_chain_links_data;
#define object_1a_chain_links ((const struct chain_link *)(object_1a_chain_links_data))
#define object_1a_path_starts_ADDRESS 0x79E4u    /* 0359E4 */
extern const void *object_1a_path_starts_data;
#define object_1a_path_starts ((const struct path_start *)(object_1a_path_starts_data))
#define door_spawns_ADDRESS 0x6458u    /* 036458 */
extern const void *door_spawns_data;
#define door_spawns ((const struct door_spawn *)(door_spawns_data))
#define channel_6_scenery_door_openings_ADDRESS 0x6488u    /* 036488 */
extern const void *channel_6_scenery_door_openings_data;
#define channel_6_scenery_door_openings ((const struct door_opening *)(channel_6_scenery_door_openings_data))
#define moes_street_scenery_door_openings_ADDRESS 0x64FEu    /* 0364FE */
extern const void *moes_street_scenery_door_openings_data;
#define moes_street_scenery_door_openings ((const struct door_opening *)(moes_street_scenery_door_openings_data))
#define kind_0f_door_openings_ADDRESS 0x654Du    /* 03654D */
extern const void *kind_0f_door_openings_data;
#define kind_0f_door_openings ((const struct door_opening *)(kind_0f_door_openings_data))
#define object_1c_moves_ADDRESS 0x7DF7u    /* 039DF7 */
extern const void *object_1c_moves_data;
#define object_1c_moves ((const struct player_move *)(object_1c_moves_data))
#define team_moves_ADDRESS 0x7EB1u    /* 039EB1 */
extern const void *team_moves_data;
#define team_moves ((const struct team_move *)(team_moves_data))
#define player_walk_velocities_ADDRESS 0x7F21u    /* 039F21 */
extern const void *player_walk_velocities_data;
#define player_walk_velocities ((const struct velocity *)(player_walk_velocities_data))
#define player_attack_boxes_ADDRESS 0x7F99u    /* 039F99 */
extern const void *player_attack_boxes_data;
#define player_attack_boxes ((const struct attack_box *)(player_attack_boxes_data))
#define stage_8_boss_state_starts_ADDRESS 0x7A3Au    /* 03BA3A */
extern const void *stage_8_boss_state_starts_data;
#define stage_8_boss_state_starts ((const struct state_start *)(stage_8_boss_state_starts_data))
#define burns_robot_boxes_ADDRESS 0x7C87u    /* 03BC87 */
extern const void *burns_robot_boxes_data;
#define burns_robot_boxes ((const struct hit_box *)(burns_robot_boxes_data))
#define object_1d_parts_ADDRESS 0x7D21u    /* 03BD21 */
extern const void *object_1d_parts_data;
#define object_1d_parts ((const struct part *)(object_1d_parts_data))
#define football_player_line_pieces_ADDRESS 0x7DD6u    /* 03DDD6 */
extern const void *football_player_line_pieces_data;
#define football_player_line_pieces ((const struct line_piece *)(football_player_line_pieces_data))
#define object_1e_part_offsets_ADDRESS 0x7E2Cu    /* 03DE2C */
extern const void *object_1e_part_offsets_data;
#define object_1e_part_offsets ((const struct part_offset *)(object_1e_part_offsets_data))
#define bear_part_flights_ADDRESS 0x7E9Cu    /* 03DE9C */
extern const void *bear_part_flights_data;
#define bear_part_flights ((const struct part_flight *)(bear_part_flights_data))
#define marge_cloud_state_starts_ADDRESS 0x7F7Cu    /* 03DF7C */
extern const void *marge_cloud_state_starts_data;
#define marge_cloud_state_starts ((const struct state_start *)(marge_cloud_state_starts_data))
#define profile_move_records_ADDRESS 0x70EDu    /* 0410ED */
extern const void *profile_move_records_data;
#define profile_move_records ((const struct profile_move *)(profile_move_records_data))
#define gauge_players_ADDRESS 0x729Cu    /* 04129C */
extern const void *gauge_players_data;
#define gauge_players ((const struct gauge_player *)(gauge_players_data))
#define gauge_step_tiles_ADDRESS 0x72FCu    /* 0412FC */
extern const void *gauge_step_tiles_data;
#define gauge_step_tiles ((const struct gauge_step *)(gauge_step_tiles_data))
#define gauge_player_columns_ADDRESS 0x730Eu    /* 04130E */
extern const void *gauge_player_columns_data;
#define gauge_player_columns ((const struct gauge_column *)(gauge_player_columns_data))
#define big_digits_ADDRESS 0x774Eu    /* 04174E */
extern const void *big_digits_data;
#define big_digits ((const struct big_digit *)(big_digits_data))
#define test_mode_palettes_ADDRESS 0x7B6Cu    /* 05FB6C */
extern const void *test_mode_palettes_data;
#define test_mode_palettes ((const struct test_palette *)(test_mode_palettes_data))
#define test_players_ADDRESS 0x7D90u    /* 05FD90 */
extern const void *test_players_data;
#define test_players ((const struct test_player *)(test_players_data))
#define portrait_areas_ADDRESS 0x7DD8u    /* 05FDD8 */
extern const void *portrait_areas_data;
#define portrait_areas ((const struct portrait_area *)(portrait_areas_data))
#define vector_to_dead_dispatch_ADDRESS 0x85D8u    /* 0785D8 */
extern const void *vector_to_dead_dispatch_data;
#define vector_to_dead_dispatch ((const struct vector *)(vector_to_dead_dispatch_data))
#define fixed_jump_table_spare_slot_ADDRESS 0x85F6u    /* 0785F6 */
extern const void *fixed_jump_table_spare_slot_data;
#define fixed_jump_table_spare_slot ((const struct vector *)(fixed_jump_table_spare_slot_data))
#define fixed_jump_table_spare_slot_2_ADDRESS 0x865Fu    /* 07865F */
extern const void *fixed_jump_table_spare_slot_2_data;
#define fixed_jump_table_spare_slot_2 ((const struct vector *)(fixed_jump_table_spare_slot_2_data))
#define fixed_jump_table_spare_slot_3_ADDRESS 0x8665u    /* 078665 */
extern const void *fixed_jump_table_spare_slot_3_data;
#define fixed_jump_table_spare_slot_3 ((const struct vector *)(fixed_jump_table_spare_slot_3_data))
#define score_additions_ADDRESS 0xE445u    /* 07E445 */
extern const void *score_additions_data;
#define score_additions ((const struct score_addition *)(score_additions_data))
#define shadow_sprites_ADDRESS 0xE585u    /* 07E585 */
extern const void *shadow_sprites_data;
#define shadow_sprites ((const struct shadow_sprite *)(shadow_sprites_data))
#define animation_sets_ADDRESS 0xE591u    /* 07E591 */
extern const void *animation_sets_data;
#define animation_sets ((const struct animation_set *)(animation_sets_data))
#define animation_sets_high_ADDRESS 0xE5BBu    /* 07E5BB */
extern const void *animation_sets_high_data;
#define animation_sets_high ((const struct animation_set *)(animation_sets_high_data))
#define scene_routines_ADDRESS 0xE7D3u    /* 07E7D3 */
extern const void *scene_routines_data;
#define scene_routines ((const struct scene_routine *)(scene_routines_data))
#define player_variable_records_ADDRESS 0xE821u    /* 07E821 */
extern const void *player_variable_records_data;
#define player_variable_records ((const struct player *)(player_variable_records_data))
#define fade_ranges_ADDRESS 0xE97Fu    /* 07E97F */
extern const void *fade_ranges_data;
#define fade_ranges ((const struct fade_range *)(fade_ranges_data))
#define palette_clears_ADDRESS 0xE9BBu    /* 07E9BB */
extern const void *palette_clears_data;
#define palette_clears ((const struct palette_clear *)(palette_clears_data))
#define layers_ADDRESS 0xECA1u    /* 07ECA1 */
extern const void *layers_data;
#define layers ((const struct layer_map *)(layers_data))
#define goon_hit_box_ADDRESS 0xF13Cu    /* 07F13C */
extern const void *goon_hit_box_data;
#define goon_hit_box ((const struct hit_box *)(goon_hit_box_data))
#define goon_behaviour_ADDRESS 0xF144u    /* 07F144 */
extern const void *goon_behaviour_data;
#define goon_behaviour ((const struct enemy_behaviour *)(goon_behaviour_data))
#define goon_setup_ADDRESS 0xF1A8u    /* 07F1A8 */
extern const void *goon_setup_data;
#define goon_setup ((const struct object_setup *)(goon_setup_data))
#define OBJECT_ADDRESS(n) (0x4A40u + (n) * 0x60u)    /* the 33 of them, from 0 */

#endif
