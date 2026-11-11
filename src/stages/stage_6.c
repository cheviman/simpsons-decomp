/**
 *    Name:        stages/stage_6.c
 *    Description: stage 6, Dreamland
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 11, stage 6 (Dreamland), by step_phase */
uint32_t step_stage_6(uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
	{
	case 0:
		left_caller = 0u;
		stage_6_setup();
		return left_caller;
	case 2:
		left_caller = 0u;
		stage_6_title(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return stage_6_begin(u, left_caller);
	case 6:
		left_caller = 0u;
		stage_6_opening();
		return left_caller;
	case 8:
		left_caller = 0u;
		return stage_6_play(left_caller);
	case 10:
		left_caller = 0u;
		stage_6_over();
		return left_caller;
	case 12:
		left_caller = 0u;
		return stage_6_exit(left_caller);
	case 14:
		left_caller = 0u;
		stage_6_closing_scene(u);
		return left_caller;
	case 16:
		left_caller = 0u;
		stage_6_end_phase(u);
		return left_caller;
	case 18:
		left_caller = 0u;
		bonus_2_setup();
		return left_caller;
	case 20:
		left_caller = 0u;
		bonus_2_draw();
		return left_caller;
	case 22:
		left_caller = 0u;
		bonus_2_intro_phase();
		return left_caller;
	case 24:
		left_caller = 0u;
		bonus_2_run();
		return left_caller;
	case 26:
		left_caller = 0u;
		bonus_2_wait();
		return left_caller;
	case 28:
		left_caller = 0u;
		bonus_2_end_phase(u);
		return left_caller;
	case 30:
		left_caller = 0u;
		stage_7_setup();
		return left_caller;
	case 32:
		left_caller = 0u;
		stage_7_title(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		return stage_7_begin(u, left_caller);
	case 36:
		left_caller = 0u;
		stage_7_opening();
		return left_caller;
	case 38:
		left_caller = 0u;
		return stage_7_play(left_caller);
	case 40:
		left_caller = 0u;
		stage_7_over();
		return left_caller;
	case 42:
		left_caller = 0u;
		return stage_7_exit(left_caller);
	case 44:
		left_caller = 0u;
		return stage_7_closing_scene(u, left_caller);
	case 46:
		left_caller = 0u;
		return stage_7_end_phase(u, left_caller);
	case 48:
		left_caller = 0u;
		stage_8_setup();
		return left_caller;
	case 50:
		left_caller = 0u;
		stage_8_title(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		stage_8_entrance(u);
		return left_caller;
	case 54:
		left_caller = 0u;
		return stage_8_begin(u, left_caller);
	case 56:
		left_caller = 0u;
		stage_8_opening();
		return left_caller;
	case 58:
		left_caller = 0u;
		return stage_8_play(left_caller);
	case 60:
		left_caller = 0u;
		return stage_8_first_part_exit(left_caller);
	case 62:
		left_caller = 0u;
		return stage_8_story(u, left_caller);
	case 64:
		left_caller = 0u;
		return stage_8_robot_entrance(left_caller);
	case 66:
		left_caller = 0u;
		return stage_8_final_fight(left_caller);
	case 68:
		left_caller = 0u;
		stage_8_over();
		return left_caller;
	case 70:
		left_caller = 0u;
		return stage_8_exit(left_caller);
	case 72:
		left_caller = 0u;
		return stage_8_closing_scene(left_caller);
	case 74:
		left_caller = 0u;
		return stage_8_objects_wait(left_caller);
	case 76:
		left_caller = 0u;
		return stage_8_end_phase(u, left_caller);
	case 78:
		left_caller = 0u;
		ending_setup();
		return left_caller;
	case 80:
		left_caller = 0u;
		ending_run(u);
		return left_caller;
	case 82:
		left_caller = 0u;
		ending_end();
		return left_caller;
	case 84:
		left_caller = 0u;
		game_over_start();
		return left_caller;
	case 86:
		left_caller = 0u;
		game_over_show();
		return left_caller;
	case 88:
		left_caller = 0u;
		game_over_wait();
		return left_caller;
	case 90:
		left_caller = 0u;
		name_entry_start(u);
		return left_caller;
	case 92:
		left_caller = 0u;
		name_entry_run();
		return left_caller;
	case 94:
		left_caller = 0u;
		name_entry_end();
		return left_caller;
	case -72:
		left_caller = 0u;
		stage_2_after_boss();
		return left_caller;
	case -70:
		left_caller = 0u;
		stage_2_closing_scene();
		return left_caller;
	case -68:
		left_caller = 0u;
		stage_2_end_phase(u);
		return left_caller;
	case -66:
		left_caller = 0u;
		stage_3_forest_setup();
		return left_caller;
	case -64:
		left_caller = 0u;
		stage_3_forest_title(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		return stage_3_forest_begin(u, left_caller);
	case -60:
		left_caller = 0u;
		stage_3_forest_opening();
		return left_caller;
	case -58:
		left_caller = 0u;
		return stage_3_forest_play(left_caller);
	case -56:
		left_caller = 0u;
		return stage_3_forest_cleared(left_caller);
	case -54:
		left_caller = 0u;
		stage_3_forest_over();
		return left_caller;
	case -52:
		left_caller = 0u;
		return stage_3_forest_exit(left_caller);
	case -50:
		return stage_3_forest_end_phase();
	case -48:
		left_caller = 0u;
		stage_3_cemetery_setup();
		return left_caller;
	case -46:
		left_caller = 0u;
		return stage_3_cemetery_begin(u, left_caller);
	case -44:
		left_caller = 0u;
		stage_3_cemetery_opening();
		return left_caller;
	case -42:
		left_caller = 0u;
		return stage_3_cemetery_play(left_caller);
	case -40:
		left_caller = 0u;
		stage_3_cemetery_over();
		return left_caller;
	case -38:
		left_caller = 0u;
		return stage_3_cemetery_exit(left_caller);
	case -36:
		left_caller = 0u;
		return stage_3_cemetery_end_phase(u, left_caller);
	case -34:
		left_caller = 0u;
		stage_4_setup();
		return left_caller;
	case -32:
		left_caller = 0u;
		stage_4_title(u);
		return left_caller;
	case -30:
		left_caller = 0u;
		return stage_4_begin(u, left_caller);
	case -28:
		left_caller = 0u;
		stage_4_opening();
		return left_caller;
	case -26:
		left_caller = 0u;
		return stage_4_play(left_caller);
	case -24:
		left_caller = 0u;
		stage_4_over();
		return left_caller;
	case -22:
		left_caller = 0u;
		return stage_4_exit(left_caller);
	case -20:
		left_caller = 0u;
		return stage_4_end_phase(left_caller);
	case -18:
		left_caller = 0u;
		stage_5_setup();
		return left_caller;
	case -16:
		left_caller = 0u;
		stage_5_title(u);
		return left_caller;
	case -14:
		left_caller = 0u;
		return stage_5_begin(u, left_caller);
	case -12:
		left_caller = 0u;
		stage_5_opening();
		return left_caller;
	case -10:
		left_caller = 0u;
		return stage_5_play(left_caller);
	case -8:
		left_caller = 0u;
		stage_5_over();
		return left_caller;
	case -6:
		left_caller = 0u;
		return stage_5_exit(left_caller);
	case -4:
		left_caller = 0u;
		stage_5_closing_scene(u);
		return left_caller;
	case -2:
		left_caller = 0u;
		stage_5_end_phase(u);
		return left_caller;
	}
	unreachable();
}

/* Stage 6's setup: the gauges hidden, the screen and the scene's variables cleared, the sound stopped,
   its stage entry and the step's scene */
void stage_6_setup(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t discarded_read = 0;

	gauges_shown = 0u;
	clear_sprites();
	clear_tile_layers();
	reset_for_stage();
	command = 0u;
	carry = queue_sound_always(command);
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_record_entry = stage_slots[9].record;
	set_step_scene();
	discarded_read = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	step_phase++;
}

/* Stage 6's title card, run by bank 13 */
void stage_6_title(uint16_t u)
{
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_title_card(u);
}

/* Stage 6's start: its palettes, scroll and music, map scene 8A on both layers, the K052109's 1C80 set
   to 3, bank 12's start, its spawns and objects, stage_players */
uint32_t stage_6_begin(uint16_t palette_job, uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, scroll_x = 0, scroll_y = 0;

	scroll_x = 0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	palette_request_kind = 1u;
	request = 0xF8Bu;
	palette_request(palette_job, request);
	play_stage_music();
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Au;
	map_area = 0u;
	set_area_tile_banks();
	layer_and_columns = 0x40u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x12Cu;
	draw_layer_columns_with_floor_map(layer_and_columns);
	left_caller = start_stage_objects(left_caller);
	window_bank = 0x1Fu;
	set_lines(window_bank);
	scene_load_story_settings(&ignored16, &ignored16_2);
	io_write8(0x1C80u, 3u);
	window_bank = 0x12u;
	set_lines(window_bank);
	dream_wave_draw();
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	players_present = players_playing;
	step_phase++;
	return left_caller;
}

/* Stage 6's opening, its scene's routine, with bank 13's frame work */
void stage_6_opening(void)
{
	uint16_t u = 0;

	u = stage_opening();
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_scroll(u);
}

/* A frame of stage 6's play; when boss_arrived is set the music moves to the stage's next part */
uint32_t stage_6_play(uint32_t left_caller)
{
	uint16_t ignored16 = 0;

	stage_play_frame(&ignored16, &left_caller);
	if (boss_arrived != 0u)
	{
		boss_arrived = 0u;
		stage_part++;
		play_stage_music();
	}
	return left_caller;
}

/* Stage 6 over: the enemies cleared */
void stage_6_over(void)
{
	uint16_t u = 0;

	u = stage_over();
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_scroll(u);
}

/* Stage 6's players leaving */
uint32_t stage_6_exit(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	stage_players_exit(&u, &left_caller, &carry);
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_scroll(u);
	return left_caller;
}

/* Stage 6's closing scene (bank 12) until it clears scene_running */
void stage_6_closing_scene(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u_2 = 0;

	scene_running = 1u;
	window_bank = 0x12u;
	set_lines(window_bank);
	stage_6_end(u);
	update_players(&ignored16, &u_2, &ignored16_2, &carry);
	if (scene_running == 0u)
	{
		step_phase++;
		return;
	}
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_scroll(u_2);
}

/* Stage 6's end (bank 12) until it clears scene_running; then the K052109's 1C80 cleared, the sound
   stopped and the next step */
void stage_6_end_phase(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t discarded_read = 0;

	scene_running = 1u;
	window_bank = 0x12u;
	set_lines(window_bank);
	stage_6_wake(u);
	if (scene_running != 0u)
		return;
	discarded_read = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	command = 0u;
	carry = queue_sound_always(command);
	game_step++;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}
