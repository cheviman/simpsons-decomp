/**
 *    Name:        stages/stories.c
 *    Description: the story steps
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Step 1, the first story (Smithers takes the diamond and Maggie), by step_phase, the gauges hidden */
uint32_t step_story_1(uint16_t u)
{
	uint32_t left_caller = 0;

	for (;;)
	{
		gauges_shown = 0u;
		switch ((int8_t)(uint8_t)((uint32_t)step_phase << 1))
		{
		case 0:
			left_caller = 0u;
			story_1_start();
			return left_caller;
		case 2:
			left_caller = 0u;
			story_1_wait_layers();
			return left_caller;
		case 4:
			left_caller = 0u;
			story_1_run(u);
			return left_caller;
		case 6:
			left_caller = 0u;
			stage_1_setup();
			return left_caller;
		case 8:
			left_caller = 0u;
			stage_1_title(u);
			return left_caller;
		case 10:
			left_caller = 0u;
			return stage_1_begin(u, left_caller);
		case 12:
			left_caller = 0u;
			stage_1_opening();
			return left_caller;
		case 14:
			left_caller = 0u;
			return stage_1_play(left_caller);
		case 16:
			left_caller = 0u;
			stage_1_over();
			return left_caller;
		case 18:
			left_caller = 0u;
			return stage_1_exit(left_caller);
		case 20:
			left_caller = 0u;
			return stage_1_end_phase(u, left_caller);
		case 22:
			left_caller = 0u;
			bonus_1_setup();
			return left_caller;
		case 24:
			left_caller = 0u;
			bonus_1_draw();
			return left_caller;
		case 26:
			left_caller = 0u;
			bonus_1_intro_phase();
			return left_caller;
		case 28:
			left_caller = 0u;
			bonus_1_run();
			return left_caller;
		case 30:
			left_caller = 0u;
			bonus_1_end_phase();
			return left_caller;
		case 32:
			left_caller = 0u;
			stage_2_setup();
			return left_caller;
		case 34:
			left_caller = 0u;
			stage_2_title(u);
			return left_caller;
		case 36:
			left_caller = 0u;
			return stage_2_begin(u, left_caller);
		case 38:
			left_caller = 0u;
			stage_2_opening();
			return left_caller;
		case 40:
			left_caller = 0u;
			return stage_2_play(left_caller);
		case 42:
			left_caller = 0u;
			stage_2_after_boss();
			return left_caller;
		case 44:
			left_caller = 0u;
			stage_2_closing_scene();
			return left_caller;
		case 46:
			left_caller = 0u;
			stage_2_end_phase(u);
			return left_caller;
		case 48:
			left_caller = 0u;
			stage_3_forest_setup();
			return left_caller;
		case 50:
			left_caller = 0u;
			stage_3_forest_title(u);
			return left_caller;
		case 52:
			left_caller = 0u;
			return stage_3_forest_begin(u, left_caller);
		case 54:
			left_caller = 0u;
			stage_3_forest_opening();
			return left_caller;
		case 56:
			left_caller = 0u;
			return stage_3_forest_play(left_caller);
		case 58:
			left_caller = 0u;
			return stage_3_forest_cleared(left_caller);
		case 60:
			left_caller = 0u;
			stage_3_forest_over();
			return left_caller;
		case 62:
			left_caller = 0u;
			return stage_3_forest_exit(left_caller);
		case 64:
			return stage_3_forest_end_phase();
		case 66:
			left_caller = 0u;
			stage_3_cemetery_setup();
			return left_caller;
		case 68:
			left_caller = 0u;
			return stage_3_cemetery_begin(u, left_caller);
		case 70:
			left_caller = 0u;
			stage_3_cemetery_opening();
			return left_caller;
		case 72:
			left_caller = 0u;
			return stage_3_cemetery_play(left_caller);
		case 74:
			left_caller = 0u;
			stage_3_cemetery_over();
			return left_caller;
		case 76:
			left_caller = 0u;
			return stage_3_cemetery_exit(left_caller);
		case 78:
			left_caller = 0u;
			return stage_3_cemetery_end_phase(u, left_caller);
		case 80:
			left_caller = 0u;
			stage_4_setup();
			return left_caller;
		case 82:
			left_caller = 0u;
			stage_4_title(u);
			return left_caller;
		case 84:
			left_caller = 0u;
			return stage_4_begin(u, left_caller);
		case 86:
			left_caller = 0u;
			stage_4_opening();
			return left_caller;
		case 88:
			left_caller = 0u;
			return stage_4_play(left_caller);
		case 90:
			left_caller = 0u;
			stage_4_over();
			return left_caller;
		case 92:
			left_caller = 0u;
			return stage_4_exit(left_caller);
		case 94:
			left_caller = 0u;
			return stage_4_end_phase(left_caller);
		case 96:
			left_caller = 0u;
			stage_5_setup();
			return left_caller;
		case 98:
			left_caller = 0u;
			stage_5_title(u);
			return left_caller;
		case 100:
			left_caller = 0u;
			return stage_5_begin(u, left_caller);
		case 102:
			left_caller = 0u;
			stage_5_opening();
			return left_caller;
		case 104:
			left_caller = 0u;
			return stage_5_play(left_caller);
		case 106:
			left_caller = 0u;
			stage_5_over();
			return left_caller;
		case 108:
			left_caller = 0u;
			return stage_5_exit(left_caller);
		case 110:
			left_caller = 0u;
			stage_5_closing_scene(u);
			return left_caller;
		case 112:
			left_caller = 0u;
			stage_5_end_phase(u);
			return left_caller;
		case 114:
			left_caller = 0u;
			stage_6_setup();
			return left_caller;
		case 116:
			left_caller = 0u;
			stage_6_title(u);
			return left_caller;
		case 118:
			left_caller = 0u;
			return stage_6_begin(u, left_caller);
		case 120:
			left_caller = 0u;
			stage_6_opening();
			return left_caller;
		case 122:
			left_caller = 0u;
			return stage_6_play(left_caller);
		case 124:
			left_caller = 0u;
			stage_6_over();
			return left_caller;
		case 126:
			break;
		case -54:
			return game_start_phase(u);
		case -52:
			return game_run_step(u);
		case -50:
			left_caller = 0u;
			game_continue_phase();
			return left_caller;
		case -48:
			left_caller = 0u;
			return game_over_phase(u, left_caller);
		case -46:
			left_caller = 0u;
			return name_entry_phase(u, left_caller);
		case -44:
			left_caller = 0u;
			game_start_clear();
			return left_caller;
		case -42:
			left_caller = 0u;
			game_start_palettes(u);
			return left_caller;
		case -40:
			return step_portraits(u);
		case -38:
			continue;
		case -36:
			return step_stage_1(u);
		case -34:
			return step_bonus_1(u);
		case -32:
			return step_stage_2(u);
		case -30:
			left_caller = 0u;
			step_story_2();
			return left_caller;
		case -28:
			return step_stage_3_forest(u);
		case -26:
			return step_stage_3_cemetery(u);
		case -24:
			return step_stage_4(u);
		case -22:
			return step_stage_5(u);
		case -20:
			left_caller = 0u;
			step_story_3();
			return left_caller;
		case -18:
			return step_stage_6(u);
		case -16:
			return step_bonus_2(u);
		case -14:
			return step_stage_7(u);
		case -12:
			left_caller = 0u;
			step_story_4();
			return left_caller;
		case -10:
			return step_stage_8(u);
		case -8:
			return step_ending(u);
		case -6:
			left_caller = 0u;
			portraits_start(u);
			return left_caller;
		case -4:
			left_caller = 0u;
			portraits_run(u);
			return left_caller;
		case -2:
			left_caller = 0u;
			portraits_wait(u);
			return left_caller;
		}
		break;
	}
	left_caller = 0u;
	return stage_6_exit(left_caller);
}

/* Clears the sprites and the scene's variables and queues the tile layers' clear for the first story */
void story_1_start(void)
{
	uint16_t job = 0;

	clear_sprites();
	reset_for_stage();
	job = 0u;
	queue_job(job);
	step_phase++;
}

/* Waits for the tile layers' clear */
void story_1_wait_layers(void)
{
	if (layer_clear_pending == 0u)
		step_phase++;
}

/* A frame of the first story, run by bank 13 until it clears scene_running; then the game's next step
   (stage 1) */
void story_1_run(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	scene_running = 1u;
	window_bank = 0x13u;
	set_lines(window_bank);
	u = stage_scroll(u);
	window_bank = 0x13u;
	set_lines(window_bank);
	story_1(u);
	if (scene_running == 0u)
	{
		game_step++;
		step_phase = 0u;
		step_subphase = 0u;
		step_countdown = 0u;
	}
	update_players(&ignored16, &ignored16_2, &ignored16_3, &carry);
}

/* Step 5, the second story: only sets the step's scene and moves on; the story plays in the next stage's
   opening */
void step_story_2(void)
{
	gauges_shown = 0u;
	set_step_scene();
	game_step++;
}

/* Step 10, the third story: only sets the step's scene and moves on */
void step_story_3(void)
{
	uint8_t discarded_read = 0;

	discarded_read = io_read8(tile_chip_scroll_control);
	io_write8(tile_chip_scroll_control, 0u);
	gauges_shown = 0u;
	set_step_scene();
	game_step++;
}

/* Step 14, the fourth story: only sets the step's scene and moves on */
void step_story_4(void)
{
	gauges_shown = 0u;
	set_step_scene();
	game_step++;
}
