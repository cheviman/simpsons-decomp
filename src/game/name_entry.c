/**
 *    Name:        game/name_entry.c
 *    Description: the name entry for a high score
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The name entry phase, by game_step, the gauges hidden */
uint32_t name_entry_phase(uint16_t u, uint32_t left_caller)
{
	gauges_shown = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
	{
	case 0:
		name_entry_start(u);
		return left_caller;
	case 2:
		name_entry_run();
		return left_caller;
	case 4:
		name_entry_end();
		return left_caller;
	case -128:
		return stage_3_cemetery_exit(left_caller);
	case -126:
		return stage_3_cemetery_end_phase(u, left_caller);
	case -124:
		stage_4_setup();
		return left_caller;
	case -122:
		stage_4_title(u);
		return left_caller;
	case -120:
		return stage_4_begin(u, left_caller);
	case -118:
		stage_4_opening();
		return left_caller;
	case -116:
		return stage_4_play(left_caller);
	case -114:
		stage_4_over();
		return left_caller;
	case -112:
		return stage_4_exit(left_caller);
	case -110:
		return stage_4_end_phase(left_caller);
	case -108:
		stage_5_setup();
		return left_caller;
	case -106:
		stage_5_title(u);
		return left_caller;
	case -104:
		return stage_5_begin(u, left_caller);
	case -102:
		stage_5_opening();
		return left_caller;
	case -100:
		return stage_5_play(left_caller);
	case -98:
		stage_5_over();
		return left_caller;
	case -96:
		return stage_5_exit(left_caller);
	case -94:
		stage_5_closing_scene(u);
		return left_caller;
	case -92:
		stage_5_end_phase(u);
		return left_caller;
	case -90:
		stage_6_setup();
		return left_caller;
	case -88:
		stage_6_title(u);
		return left_caller;
	case -86:
		return stage_6_begin(u, left_caller);
	case -84:
		stage_6_opening();
		return left_caller;
	case -82:
		return stage_6_play(left_caller);
	case -80:
		stage_6_over();
		return left_caller;
	case -78:
		return stage_6_exit(left_caller);
	case -76:
		stage_6_closing_scene(u);
		return left_caller;
	case -74:
		stage_6_end_phase(u);
		return left_caller;
	case -72:
		bonus_2_setup();
		return left_caller;
	case -70:
		bonus_2_draw();
		return left_caller;
	case -68:
		bonus_2_intro_phase();
		return left_caller;
	case -66:
		bonus_2_run();
		return left_caller;
	case -64:
		bonus_2_wait();
		return left_caller;
	case -62:
		bonus_2_end_phase(u);
		return left_caller;
	case -60:
		stage_7_setup();
		return left_caller;
	case -58:
		stage_7_title(u);
		return left_caller;
	case -56:
		return stage_7_begin(u, left_caller);
	case -54:
		stage_7_opening();
		return left_caller;
	case -52:
		return stage_7_play(left_caller);
	case -50:
		stage_7_over();
		return left_caller;
	case -48:
		return stage_7_exit(left_caller);
	case -46:
		return stage_7_closing_scene(u, left_caller);
	case -44:
		return stage_7_end_phase(u, left_caller);
	case -42:
		stage_8_setup();
		return left_caller;
	case -40:
		stage_8_title(u);
		return left_caller;
	case -38:
		stage_8_entrance(u);
		return left_caller;
	case -36:
		return stage_8_begin(u, left_caller);
	case -34:
		stage_8_opening();
		return left_caller;
	case -32:
		return stage_8_play(left_caller);
	case -30:
		return stage_8_first_part_exit(left_caller);
	case -28:
		return stage_8_story(u, left_caller);
	case -26:
		return stage_8_robot_entrance(left_caller);
	case -24:
		return stage_8_final_fight(left_caller);
	case -22:
		stage_8_over();
		return left_caller;
	case -20:
		return stage_8_exit(left_caller);
	case -18:
		return stage_8_closing_scene(left_caller);
	case -16:
		return stage_8_objects_wait(left_caller);
	case -14:
		return stage_8_end_phase(u, left_caller);
	case -12:
		ending_setup();
		return left_caller;
	case -10:
		ending_run(u);
		return left_caller;
	case -8:
		ending_end();
		return left_caller;
	case -6:
		game_over_start();
		return left_caller;
	case -4:
		game_over_show();
		return left_caller;
	case -2:
		game_over_wait();
		return left_caller;
	}
	unreachable();
}

/* Starts the name entry: its music, the objects running again, its palettes and background, map scene 03
   drawn */
void name_entry_start(uint16_t palette_job)
{
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, scroll_x = 0, scroll_y = 0;

	command = 0x9000u;
	queue_sound_always(command);
	objects_frozen = 0u;
	scroll_x = 0xFFF0u;
	set_scroll_x(scroll_x);
	scroll_y = 0u;
	set_scroll_y(scroll_y);
	palette_request_kind = 1u;
	request = 0x70Du;
	palette_job = palette_request(palette_job, request);
	palette_request_kind = 1u;
	request = 0x880u;
	palette_job = palette_request(palette_job, request);
	palette_request_kind = 1u;
	request = 0x886u;
	palette_job = palette_request(palette_job, request);
	palette_request_kind = 3u;
	request = 0x3E36u;
	palette_request(palette_job, request);
	map_scene = 3u;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_and_columns = 0x2Cu;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	game_step++;
}

/* A frame of the name entry, run by bank 11 until it is done */
void name_entry_run(void)
{
	uint32_t carry = 0;

	window_bank = 0x11u;
	set_lines(window_bank);
	carry = name_entry();
	if (carry)
		game_step++;
}

/* Ends the name entry: the sprites and the sound stopped, the game's end, and the attract set to show
   the high scores */
void name_entry_end(void)
{
	uint16_t command = 0, request = 0, u = 0;

	clear_sprites();
	command = 0u;
	queue_sound_always(command);
	u = end_game();
	palette_request_kind = 3u;
	request = 0u;
	palette_request(u, request);
	mode_step = 3u;
}
