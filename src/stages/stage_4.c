/**
 *    Name:        stages/stage_4.c
 *    Description: stage 4, Moe's Tavern
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 8, stage 4 (Moe's Tavern), by step_phase */
uint32_t step_stage_4(uint16_t u)
{
	uint32_t left_caller = 0;

	switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
	{
	case 0:
		left_caller = 0u;
		stage_4_setup();
		return left_caller;
	case 2:
		left_caller = 0u;
		stage_4_title(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		return stage_4_begin(u, left_caller);
	case 6:
		left_caller = 0u;
		stage_4_opening();
		return left_caller;
	case 8:
		left_caller = 0u;
		return stage_4_play(left_caller);
	case 10:
		left_caller = 0u;
		stage_4_over();
		return left_caller;
	case 12:
		left_caller = 0u;
		return stage_4_exit(left_caller);
	case 14:
		left_caller = 0u;
		return stage_4_end_phase(left_caller);
	case 16:
		left_caller = 0u;
		stage_5_setup();
		return left_caller;
	case 18:
		left_caller = 0u;
		stage_5_title(u);
		return left_caller;
	case 20:
		left_caller = 0u;
		return stage_5_begin(u, left_caller);
	case 22:
		left_caller = 0u;
		stage_5_opening();
		return left_caller;
	case 24:
		left_caller = 0u;
		return stage_5_play(left_caller);
	case 26:
		left_caller = 0u;
		stage_5_over();
		return left_caller;
	case 28:
		left_caller = 0u;
		return stage_5_exit(left_caller);
	case 30:
		left_caller = 0u;
		stage_5_closing_scene(u);
		return left_caller;
	case 32:
		left_caller = 0u;
		stage_5_end_phase(u);
		return left_caller;
	case 34:
		left_caller = 0u;
		stage_6_setup();
		return left_caller;
	case 36:
		left_caller = 0u;
		stage_6_title(u);
		return left_caller;
	case 38:
		left_caller = 0u;
		return stage_6_begin(u, left_caller);
	case 40:
		left_caller = 0u;
		stage_6_opening();
		return left_caller;
	case 42:
		left_caller = 0u;
		return stage_6_play(left_caller);
	case 44:
		left_caller = 0u;
		stage_6_over();
		return left_caller;
	case 46:
		left_caller = 0u;
		return stage_6_exit(left_caller);
	case 48:
		left_caller = 0u;
		stage_6_closing_scene(u);
		return left_caller;
	case 50:
		left_caller = 0u;
		stage_6_end_phase(u);
		return left_caller;
	case 52:
		left_caller = 0u;
		bonus_2_setup();
		return left_caller;
	case 54:
		left_caller = 0u;
		bonus_2_draw();
		return left_caller;
	case 56:
		left_caller = 0u;
		bonus_2_intro_phase();
		return left_caller;
	case 58:
		left_caller = 0u;
		bonus_2_run();
		return left_caller;
	case 60:
		left_caller = 0u;
		bonus_2_wait();
		return left_caller;
	case 62:
		left_caller = 0u;
		bonus_2_end_phase(u);
		return left_caller;
	case 64:
		left_caller = 0u;
		stage_7_setup();
		return left_caller;
	case 66:
		left_caller = 0u;
		stage_7_title(u);
		return left_caller;
	case 68:
		left_caller = 0u;
		return stage_7_begin(u, left_caller);
	case 70:
		left_caller = 0u;
		stage_7_opening();
		return left_caller;
	case 72:
		left_caller = 0u;
		return stage_7_play(left_caller);
	case 74:
		left_caller = 0u;
		stage_7_over();
		return left_caller;
	case 76:
		left_caller = 0u;
		return stage_7_exit(left_caller);
	case 78:
		left_caller = 0u;
		return stage_7_closing_scene(u, left_caller);
	case 80:
		left_caller = 0u;
		return stage_7_end_phase(u, left_caller);
	case 82:
		left_caller = 0u;
		stage_8_setup();
		return left_caller;
	case 84:
		left_caller = 0u;
		stage_8_title(u);
		return left_caller;
	case 86:
		left_caller = 0u;
		stage_8_entrance(u);
		return left_caller;
	case 88:
		left_caller = 0u;
		return stage_8_begin(u, left_caller);
	case 90:
		left_caller = 0u;
		stage_8_opening();
		return left_caller;
	case 92:
		left_caller = 0u;
		return stage_8_play(left_caller);
	case 94:
		left_caller = 0u;
		return stage_8_first_part_exit(left_caller);
	case 96:
		left_caller = 0u;
		return stage_8_story(u, left_caller);
	case 98:
		left_caller = 0u;
		return stage_8_robot_entrance(left_caller);
	case 100:
		left_caller = 0u;
		return stage_8_final_fight(left_caller);
	case 102:
		left_caller = 0u;
		stage_8_over();
		return left_caller;
	case 104:
		left_caller = 0u;
		return stage_8_exit(left_caller);
	case 106:
		left_caller = 0u;
		return stage_8_closing_scene(left_caller);
	case 108:
		left_caller = 0u;
		return stage_8_objects_wait(left_caller);
	case 110:
		left_caller = 0u;
		return stage_8_end_phase(u, left_caller);
	case 112:
		left_caller = 0u;
		ending_setup();
		return left_caller;
	case 114:
		left_caller = 0u;
		ending_run(u);
		return left_caller;
	case 116:
		left_caller = 0u;
		ending_end();
		return left_caller;
	case 118:
		left_caller = 0u;
		game_over_start();
		return left_caller;
	case 120:
		left_caller = 0u;
		game_over_show();
		return left_caller;
	case 122:
		left_caller = 0u;
		game_over_wait();
		return left_caller;
	case 124:
		left_caller = 0u;
		name_entry_start(u);
		return left_caller;
	case 126:
		left_caller = 0u;
		name_entry_run();
		return left_caller;
	case -38:
		left_caller = 0u;
		stage_2_after_boss();
		return left_caller;
	case -36:
		left_caller = 0u;
		stage_2_closing_scene();
		return left_caller;
	case -34:
		left_caller = 0u;
		stage_2_end_phase(u);
		return left_caller;
	case -32:
		left_caller = 0u;
		stage_3_forest_setup();
		return left_caller;
	case -30:
		left_caller = 0u;
		stage_3_forest_title(u);
		return left_caller;
	case -28:
		left_caller = 0u;
		return stage_3_forest_begin(u, left_caller);
	case -26:
		left_caller = 0u;
		stage_3_forest_opening();
		return left_caller;
	case -24:
		left_caller = 0u;
		return stage_3_forest_play(left_caller);
	case -22:
		left_caller = 0u;
		return stage_3_forest_cleared(left_caller);
	case -20:
		left_caller = 0u;
		stage_3_forest_over();
		return left_caller;
	case -18:
		left_caller = 0u;
		return stage_3_forest_exit(left_caller);
	case -16:
		return stage_3_forest_end_phase();
	case -14:
		left_caller = 0u;
		stage_3_cemetery_setup();
		return left_caller;
	case -12:
		left_caller = 0u;
		return stage_3_cemetery_begin(u, left_caller);
	case -10:
		left_caller = 0u;
		stage_3_cemetery_opening();
		return left_caller;
	case -8:
		left_caller = 0u;
		return stage_3_cemetery_play(left_caller);
	case -6:
		left_caller = 0u;
		stage_3_cemetery_over();
		return left_caller;
	case -4:
		left_caller = 0u;
		return stage_3_cemetery_exit(left_caller);
	case -2:
		left_caller = 0u;
		return stage_3_cemetery_end_phase(u, left_caller);
	}
	unreachable();
}

/* Stage 4's setup: the gauges hidden, the screen and the scene's variables cleared, the sound stopped,
   its stage entry and the step's scene */
void stage_4_setup(void)
{
	uint16_t command = 0;

	gauges_shown = 0u;
	clear_tile_layers();
	clear_sprites();
	reset_for_stage();
	command = 0u;
	queue_sound_always(command);
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_record_entry = stage_slots[5].record;
	set_step_scene();
	step_phase++;
}

/* Stage 4's title card, run by bank 13 */
void stage_4_title(uint16_t u)
{
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_title_card(u);
}

/* Stage 4's start: its palettes and palette effect, scroll and music, map scene 88 on both layers, its
   spawns and objects, stage_players */
uint32_t stage_4_begin(uint16_t palette_job, uint32_t left_caller)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, scroll_x = 0, scroll_y = 0;

	scroll_x = 0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	palette_request_kind = 1u;
	request = 0xE87u;
	palette_job = palette_request(palette_job, request);
	palette_request_kind = 2u;
	request = 0x3Cu;
	palette_request(palette_job, request);
	play_stage_music();
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x88u;
	map_area = 0u;
	set_area_tile_banks();
	layer_and_columns = 0x2Cu;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x12Cu;
	draw_layer_columns_with_floor_map(layer_and_columns);
	left_caller = start_stage_objects(left_caller);
	window_bank = 0x1Fu;
	set_lines(window_bank);
	scene_load_story_settings(&ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	players_present = players_playing;
	step_phase++;
	return left_caller;
}

/* Not code of its own: where an entry past the end of the palette effects' commands would lead, the
   middle of a stage 4 routine; the game never goes there. */
void palette_effects_overrun(void)
{
	lost_stack(0x07AC00u);
}

/* Stage 4's opening, its scene's routine */
void stage_4_opening(void)
{
	stage_opening();
}

/* A frame of stage 4's play; when boss_arrived is set the music moves to the stage's next part */
uint32_t stage_4_play(uint32_t left_caller)
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

/* Stage 4 over: the enemies cleared */
void stage_4_over(void)
{
	stage_over();
}

/* Stage 4's players leaving */
uint32_t stage_4_exit(uint32_t left_caller)
{
	uint32_t players_out = 0;
	uint16_t ignored16 = 0;

	stage_players_exit(&ignored16, &left_caller, &players_out);
	return left_caller;
}

/* Stage 4's closing story script for the actor (bank 1F) until it clears scene_running; then the sound
   stopped, the sprites cleared and the next step */
uint32_t stage_4_end_phase(uint32_t left_caller)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	scene_running = 1u;
	run_list_1_objects(&ignored16, &left_caller);
	run_child_objects(ignored16);
	window_bank = 0x1Fu;
	set_lines(window_bank);
	story_stage_4_end();
	check_collisions(&u, &ignored16_2);
	if (scene_running != 0u)
	{
		window_bank = 0x13u;
		set_lines(window_bank);
		stage_scroll(u);
		update_players(&ignored16_3, &ignored16, &ignored16_2, &carry);
		return left_caller;
	}
	command = 0u;
	queue_sound_always(command);
	clear_sprites();
	game_step++;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	return left_caller;
}
