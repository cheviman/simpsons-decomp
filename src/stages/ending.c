/**
 *    Name:        stages/ending.c
 *    Description: the ending
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 16, the ending, by step_phase, the gauges hidden */
uint32_t step_ending(uint16_t y, uint16_t u)
{
	uint32_t left_caller = 0;

	gauges_shown = 0u;
	switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
	{
	case 0:
		left_caller = 0u;
		ending_setup();
		return left_caller;
	case 2:
		left_caller = 0u;
		ending_run(u);
		return left_caller;
	case 4:
		left_caller = 0u;
		ending_end();
		return left_caller;
	case 6:
		left_caller = 0u;
		game_over_start();
		return left_caller;
	case 8:
		left_caller = 0u;
		game_over_show();
		return left_caller;
	case 10:
		left_caller = 0u;
		game_over_wait();
		return left_caller;
	case 12:
		left_caller = 0u;
		name_entry_start(u);
		return left_caller;
	case 14:
		left_caller = 0u;
		name_entry_run();
		return left_caller;
	case 16:
		left_caller = 0u;
		name_entry_end();
		return left_caller;
	case -128:
		return stage_3_forest_end_phase();
	case -126:
		left_caller = 0u;
		stage_3_cemetery_setup();
		return left_caller;
	case -124:
		left_caller = 0u;
		return stage_3_cemetery_begin(u, left_caller);
	case -122:
		left_caller = 0u;
		stage_3_cemetery_opening();
		return left_caller;
	case -120:
		left_caller = 0u;
		return stage_3_cemetery_play(y, left_caller);
	case -118:
		left_caller = 0u;
		stage_3_cemetery_over();
		return left_caller;
	case -116:
		left_caller = 0u;
		return stage_3_cemetery_exit(left_caller);
	case -114:
		left_caller = 0u;
		return stage_3_cemetery_end_phase(u, left_caller);
	case -112:
		left_caller = 0u;
		stage_4_setup();
		return left_caller;
	case -110:
		left_caller = 0u;
		stage_4_title(u);
		return left_caller;
	case -108:
		left_caller = 0u;
		return stage_4_begin(u, left_caller);
	case -106:
		left_caller = 0u;
		stage_4_opening();
		return left_caller;
	case -104:
		left_caller = 0u;
		return stage_4_play(y, left_caller);
	case -102:
		left_caller = 0u;
		stage_4_over();
		return left_caller;
	case -100:
		left_caller = 0u;
		return stage_4_exit(left_caller);
	case -98:
		left_caller = 0u;
		return stage_4_end_phase(left_caller);
	case -96:
		left_caller = 0u;
		stage_5_setup();
		return left_caller;
	case -94:
		left_caller = 0u;
		stage_5_title(u);
		return left_caller;
	case -92:
		left_caller = 0u;
		return stage_5_begin(u, left_caller);
	case -90:
		left_caller = 0u;
		stage_5_opening();
		return left_caller;
	case -88:
		left_caller = 0u;
		return stage_5_play(y, left_caller);
	case -86:
		left_caller = 0u;
		stage_5_over();
		return left_caller;
	case -84:
		left_caller = 0u;
		return stage_5_exit(left_caller);
	case -82:
		left_caller = 0u;
		stage_5_closing_scene(u);
		return left_caller;
	case -80:
		left_caller = 0u;
		stage_5_end_phase(u);
		return left_caller;
	case -78:
		left_caller = 0u;
		stage_6_setup();
		return left_caller;
	case -76:
		left_caller = 0u;
		stage_6_title(u);
		return left_caller;
	case -74:
		left_caller = 0u;
		return stage_6_begin(u, left_caller);
	case -72:
		left_caller = 0u;
		stage_6_opening();
		return left_caller;
	case -70:
		left_caller = 0u;
		return stage_6_play(y, left_caller);
	case -68:
		left_caller = 0u;
		stage_6_over();
		return left_caller;
	case -66:
		left_caller = 0u;
		return stage_6_exit(left_caller);
	case -64:
		left_caller = 0u;
		stage_6_closing_scene(u);
		return left_caller;
	case -62:
		left_caller = 0u;
		stage_6_end_phase(u);
		return left_caller;
	case -60:
		left_caller = 0u;
		bonus_2_setup();
		return left_caller;
	case -58:
		left_caller = 0u;
		bonus_2_draw();
		return left_caller;
	case -56:
		left_caller = 0u;
		bonus_2_intro_phase(y);
		return left_caller;
	case -54:
		left_caller = 0u;
		bonus_2_run(y);
		return left_caller;
	case -52:
		left_caller = 0u;
		bonus_2_wait();
		return left_caller;
	case -50:
		left_caller = 0u;
		bonus_2_end_phase(u);
		return left_caller;
	case -48:
		left_caller = 0u;
		stage_7_setup();
		return left_caller;
	case -46:
		left_caller = 0u;
		stage_7_title(u);
		return left_caller;
	case -44:
		left_caller = 0u;
		return stage_7_begin(u, left_caller);
	case -42:
		left_caller = 0u;
		stage_7_opening();
		return left_caller;
	case -40:
		left_caller = 0u;
		return stage_7_play(y, left_caller);
	case -38:
		left_caller = 0u;
		stage_7_over();
		return left_caller;
	case -36:
		left_caller = 0u;
		return stage_7_exit(left_caller);
	case -34:
		left_caller = 0u;
		return stage_7_closing_scene(u, left_caller);
	case -32:
		left_caller = 0u;
		return stage_7_end_phase(u, left_caller);
	case -30:
		left_caller = 0u;
		stage_8_setup();
		return left_caller;
	case -28:
		left_caller = 0u;
		stage_8_title(u);
		return left_caller;
	case -26:
		left_caller = 0u;
		stage_8_entrance(u);
		return left_caller;
	case -24:
		left_caller = 0u;
		return stage_8_begin(u, left_caller);
	case -22:
		left_caller = 0u;
		stage_8_opening();
		return left_caller;
	case -20:
		left_caller = 0u;
		return stage_8_play(y, left_caller);
	case -18:
		left_caller = 0u;
		return stage_8_first_part_exit(left_caller);
	case -16:
		left_caller = 0u;
		return stage_8_story(u, left_caller);
	case -14:
		left_caller = 0u;
		return stage_8_robot_entrance(y, left_caller);
	case -12:
		left_caller = 0u;
		return stage_8_final_fight(y, left_caller);
	case -10:
		left_caller = 0u;
		stage_8_over();
		return left_caller;
	case -8:
		left_caller = 0u;
		return stage_8_exit(left_caller);
	case -6:
		left_caller = 0u;
		return stage_8_closing_scene(left_caller);
	case -4:
		left_caller = 0u;
		return stage_8_objects_wait(left_caller);
	case -2:
		left_caller = 0u;
		return stage_8_end_phase(u, left_caller);
	}
	unreachable();
}

/* Clears the sprites, the tile layers and the scene's variables for the ending */
void ending_setup(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	clear_sprites(&ignored16, &ignored16_2);
	clear_tile_layers();
	reset_for_stage();
	step_phase++;
}

/* A frame of the ending (the family, the staff roll), run by bank 11 until it clears scene_running; then
   the tile layers' clear queued */
void ending_run(uint16_t u)
{
	uint16_t job = 0;

	scene_running = 1u;
	window_bank = 0x11u;
	set_lines(window_bank);
	ending(u);
	if (scene_running != 0u)
		return;
	gauges_shown = 0u;
	job = 0u;
	queue_job(job);
	step_phase++;
}

/* Once the layers are clear, clears the objects and ends the game as after GAME OVER: the high scores
   checked */
void ending_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	gauges_shown = 0u;
	if (layer_clear_pending != 0u)
		return;
	clear_objects(&ignored16, &ignored16_2);
	game_finish();
}
