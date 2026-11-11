/**
 *    Name:        stages/bonus_1.c
 *    Description: bonus stage 1
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 3, bonus stage 1, by step_phase, the gauges hidden */
uint32_t step_bonus_1(uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		gauges_shown = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
		{
		case 0:
			left_caller = 0u;
			bonus_1_setup();
			return left_caller;
		case 2:
			left_caller = 0u;
			bonus_1_draw();
			return left_caller;
		case 4:
			left_caller = 0u;
			bonus_1_intro_phase();
			return left_caller;
		case 6:
			left_caller = 0u;
			bonus_1_run();
			return left_caller;
		case 8:
			left_caller = 0u;
			bonus_1_end_phase();
			return left_caller;
		case 10:
			left_caller = 0u;
			stage_2_setup();
			return left_caller;
		case 12:
			left_caller = 0u;
			stage_2_title(u);
			return left_caller;
		case 14:
			left_caller = 0u;
			return stage_2_begin(u, left_caller);
		case 16:
			left_caller = 0u;
			stage_2_opening();
			return left_caller;
		case 18:
			left_caller = 0u;
			return stage_2_play(left_caller);
		case 20:
			left_caller = 0u;
			stage_2_after_boss();
			return left_caller;
		case 22:
			left_caller = 0u;
			stage_2_closing_scene();
			return left_caller;
		case 24:
			left_caller = 0u;
			stage_2_end_phase(u);
			return left_caller;
		case 26:
			left_caller = 0u;
			stage_3_forest_setup();
			return left_caller;
		case 28:
			left_caller = 0u;
			stage_3_forest_title(u);
			return left_caller;
		case 30:
			left_caller = 0u;
			return stage_3_forest_begin(u, left_caller);
		case 32:
			left_caller = 0u;
			stage_3_forest_opening();
			return left_caller;
		case 34:
			left_caller = 0u;
			return stage_3_forest_play(left_caller);
		case 36:
			left_caller = 0u;
			return stage_3_forest_cleared(left_caller);
		case 38:
			left_caller = 0u;
			stage_3_forest_over();
			return left_caller;
		case 40:
			left_caller = 0u;
			return stage_3_forest_exit(left_caller);
		case 42:
			return stage_3_forest_end_phase();
		case 44:
			left_caller = 0u;
			stage_3_cemetery_setup();
			return left_caller;
		case 46:
			left_caller = 0u;
			return stage_3_cemetery_begin(u, left_caller);
		case 48:
			left_caller = 0u;
			stage_3_cemetery_opening();
			return left_caller;
		case 50:
			left_caller = 0u;
			return stage_3_cemetery_play(left_caller);
		case 52:
			left_caller = 0u;
			stage_3_cemetery_over();
			return left_caller;
		case 54:
			left_caller = 0u;
			return stage_3_cemetery_exit(left_caller);
		case 56:
			left_caller = 0u;
			return stage_3_cemetery_end_phase(u, left_caller);
		case 58:
			left_caller = 0u;
			stage_4_setup();
			return left_caller;
		case 60:
			left_caller = 0u;
			stage_4_title(u);
			return left_caller;
		case 62:
			left_caller = 0u;
			return stage_4_begin(u, left_caller);
		case 64:
			left_caller = 0u;
			stage_4_opening();
			return left_caller;
		case 66:
			left_caller = 0u;
			return stage_4_play(left_caller);
		case 68:
			left_caller = 0u;
			stage_4_over();
			return left_caller;
		case 70:
			left_caller = 0u;
			return stage_4_exit(left_caller);
		case 72:
			left_caller = 0u;
			return stage_4_end_phase(left_caller);
		case 74:
			left_caller = 0u;
			stage_5_setup();
			return left_caller;
		case 76:
			left_caller = 0u;
			stage_5_title(u);
			return left_caller;
		case 78:
			left_caller = 0u;
			return stage_5_begin(u, left_caller);
		case 80:
			left_caller = 0u;
			stage_5_opening();
			return left_caller;
		case 82:
			left_caller = 0u;
			return stage_5_play(left_caller);
		case 84:
			left_caller = 0u;
			stage_5_over();
			return left_caller;
		case 86:
			left_caller = 0u;
			return stage_5_exit(left_caller);
		case 88:
			left_caller = 0u;
			stage_5_closing_scene(u);
			return left_caller;
		case 90:
			left_caller = 0u;
			stage_5_end_phase(u);
			return left_caller;
		case 92:
			left_caller = 0u;
			stage_6_setup();
			return left_caller;
		case 94:
			left_caller = 0u;
			stage_6_title(u);
			return left_caller;
		case 96:
			left_caller = 0u;
			return stage_6_begin(u, left_caller);
		case 98:
			left_caller = 0u;
			stage_6_opening();
			return left_caller;
		case 100:
			left_caller = 0u;
			return stage_6_play(left_caller);
		case 102:
			left_caller = 0u;
			stage_6_over();
			return left_caller;
		case 104:
			left_caller = 0u;
			return stage_6_exit(left_caller);
		case 106:
			left_caller = 0u;
			stage_6_closing_scene(u);
			return left_caller;
		case 108:
			left_caller = 0u;
			stage_6_end_phase(u);
			return left_caller;
		case 110:
			left_caller = 0u;
			bonus_2_setup();
			return left_caller;
		case 112:
			left_caller = 0u;
			bonus_2_draw();
			return left_caller;
		case 114:
			left_caller = 0u;
			bonus_2_intro_phase();
			return left_caller;
		case 116:
			left_caller = 0u;
			bonus_2_run();
			return left_caller;
		case 118:
			left_caller = 0u;
			bonus_2_wait();
			return left_caller;
		case 120:
			left_caller = 0u;
			bonus_2_end_phase(u);
			return left_caller;
		case 122:
			left_caller = 0u;
			stage_7_setup();
			return left_caller;
		case 124:
			left_caller = 0u;
			stage_7_title(u);
			return left_caller;
		case 126:
			break;
		case -76:
			return game_start_phase(u);
		case -74:
			return game_run_step(u);
		case -72:
			left_caller = 0u;
			game_continue_phase();
			return left_caller;
		case -70:
			left_caller = 0u;
			return game_over_phase(u, left_caller);
		case -68:
			left_caller = 0u;
			return name_entry_phase(u, left_caller);
		case -66:
			left_caller = 0u;
			game_start_clear();
			return left_caller;
		case -64:
			left_caller = 0u;
			game_start_palettes(u);
			return left_caller;
		case -62:
			return step_portraits(u);
		case -60:
			return step_story_1(u);
		case -58:
			return step_stage_1(u);
		case -56:
			continue;
		case -54:
			return step_stage_2(u);
		case -52:
			left_caller = 0u;
			step_story_2();
			return left_caller;
		case -50:
			return step_stage_3_forest(u);
		case -48:
			return step_stage_3_cemetery(u);
		case -46:
			return step_stage_4(u);
		case -44:
			return step_stage_5(u);
		case -42:
			left_caller = 0u;
			step_story_3();
			return left_caller;
		case -40:
			return step_stage_6(u);
		case -38:
			return step_bonus_2(u);
		case -36:
			return step_stage_7(u);
		case -34:
			left_caller = 0u;
			step_story_4();
			return left_caller;
		case -32:
			return step_stage_8(u);
		case -30:
			return step_ending(u);
		case -28:
			left_caller = 0u;
			portraits_start(u);
			return left_caller;
		case -26:
			left_caller = 0u;
			portraits_run(u);
			return left_caller;
		case -24:
			left_caller = 0u;
			portraits_wait(u);
			return left_caller;
		case -22:
			left_caller = 0u;
			story_1_start();
			return left_caller;
		case -20:
			left_caller = 0u;
			story_1_wait_layers();
			return left_caller;
		case -18:
			left_caller = 0u;
			story_1_run(u);
			return left_caller;
		case -16:
			left_caller = 0u;
			stage_1_setup();
			return left_caller;
		case -14:
			left_caller = 0u;
			stage_1_title(u);
			return left_caller;
		case -12:
			left_caller = 0u;
			return stage_1_begin(u, left_caller);
		case -10:
			left_caller = 0u;
			stage_1_opening();
			return left_caller;
		case -8:
			left_caller = 0u;
			return stage_1_play(left_caller);
		case -6:
			left_caller = 0u;
			stage_1_over();
			return left_caller;
		case -4:
			left_caller = 0u;
			return stage_1_exit(left_caller);
		case -2:
			left_caller = 0u;
			return stage_1_end_phase(u, left_caller);
		}
		break;
	}
	left_caller = 0u;
	return stage_7_begin(u, left_caller);
}

/* Bonus stage 1's setup: the sprites, the scene's variables, the palettes and the scroll, the tile
   layers' clear queued */
void bonus_1_setup(void)
{
	uint16_t job = 0, request = 0, scroll_x = 0, scroll_y = 0, u = 0;

	clear_sprites();
	job = 0u;
	queue_job(job);
	u = reset_for_stage();
	palette_request_kind = 1u;
	request = 0xF82u;
	palette_request(u, request);
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	step_phase++;
}

/* Once the layers are clear: the bonus start's music, map scene 83 on both layers and scene_timer set to
   384 frames */
void bonus_1_draw(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0;

	if (layer_clear_pending != 0u)
		return;
	command = 0x8700u;
	carry = queue_sound_unless_attract(command);
	map_scene = 0x83u;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_a_scroll_y = 0xFF30u;
	scene_timer = 0x180u;
	step_phase++;
}

/* A frame of bonus stage 1's instructions (bank 10); when scene_timer runs out or a button skips them,
   the objects are cleared and the bonus stage's area 1 is drawn */
void bonus_1_intro_phase(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, scroll_x = 0, scroll_y = 0, wait = 0;
	uint8_t discarded_read = 0;
	uint16_t intro_wait = 0;

	wait = 0xD000u | b;
	check_skip(wait, &ignored16, &carry);
	if (carry == 0u)
	{
		io_write8(0x1FB9u, 0x13u);
		io_write8(0x1FBAu, 0x2Cu);
		intro_wait = scene_timer;
		scene_timer = intro_wait - 1u;
		if (intro_wait != 1u)
		{
			window_bank = 0x10u;
			set_lines(window_bank);
			bonus_1_intro();
			update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
			return;
		}
	}
	clear_objects(&ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	clear_layer_b();
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	map_area = 1u;
	set_area_tile_banks();
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	discarded_read = io_read8(scene_state);
	io_write8(scene_state, 0u);
	command = 0u;
	carry = queue_sound_always(command);
	step_phase++;
}

/* A frame of bonus stage 1's game, run by bank 10 */
void bonus_1_run(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	window_bank = 0x10u;
	set_lines(window_bank);
	bonus_1_contest();
	update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
}

/* Ends bonus stage 1: the sprites cleared and the next step */
void bonus_1_end_phase(void)
{
	clear_sprites();
	game_step++;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}
