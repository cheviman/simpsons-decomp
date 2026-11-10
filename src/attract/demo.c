/**
 *    Name:        attract/demo.c
 *    Description: the attract's demo: the recorded inputs played through the game
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The attract's demo step: its start, then its frames, by mode_phase */
void attract_demo(uint16_t y, uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			demo_start();
			return;
		case 2:
			demo_play(u);
			return;
		case 4:
			high_scores_start(u);
			return;
		case 6:
			high_scores_draw_background();
			return;
		case 8:
			high_scores_show(u);
			return;
		case 10:
			high_scores_close(u);
			return;
		case 12:
			warning_skip(u);
			return;
		case 14:
			warning_first_page();
			return;
		case 16:
			warning_second_page();
			return;
		case 18:
			warning_end(u);
			return;
		case 20:
			coin_title_start();
			return;
		case 22:
			coin_title_draw();
			return;
		case 24:
			break;
		case -28:
			attract_opening_scene(y, u);
			return;
		case -26:
			continue;
		case -24:
			attract_title(y, u);
			return;
		case -22:
			attract_high_scores(y, u);
			return;
		case -20:
			attract_warning(y, u);
			return;
		case -18:
			attract_coin_title(y, u);
			return;
		case -16:
			attract_clear_screen();
			return;
		case -14:
			attract_wait_clear();
			return;
		case -12:
			attract_opening_run(y, u);
			return;
		case -10:
			attract_next_scene();
			return;
		case -8:
			attract_title_clear();
			return;
		case -6:
			attract_title_wait(u);
			return;
		case -4:
			title_show_notices();
			return;
		case -2:
			title_end();
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Starts the attract's demo: clears the screen, the objects and the game's variables, then from the
   demo's record sets the players who play, its frames, the step it plays and each player's recorded
   inputs */
void demo_start(void)
{
	uint16_t clear_from = 0, clear_to = 0, count = 0, demo_cursor = 0, ignored16 = 0, ignored16_3 = 0, inputs = 0, playback = 0, player = 0, record = 0, request = 0, u = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t frames_2 = 0;
	uint16_t t1 = 0, t2 = 0, frames = 0, t3 = 0, state = 0, object_kind = 0, t4 = 0, lives = 0, lives_2 = 0, state_2 = 0;

	clear_tile_layers();
	reset_for_play();
	clear_objects(&ignored16, &u);
	palette_request_kind = 1u;
	request = 0x880u;
	palette_request(request, &ignored16_3, &u);
	AT16(random_number, -1) = 0u;
	frame_count = 0u;
	clear_from = demo_frames_ADDRESS;
	clear_to = 0x5801u;
	demo_frames &= 0xFFu;
	count = 0xFFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	t1 = demos[(int8_t)((uint8_t)((uint32_t)demo_number << 1)) / 2];
	players_playing = DEMO(t1)->players;
	t2 = t1 + 1u;
	frames = DEMO(t2 - 0x1u)->frames;
	demo_frames = frames;
	t3 = t2 + 2u;
	demo_cursor = t3 + 1u;
	game_step = DEMO(t3 - 0x3u)->step;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
	window_bank = 0x2Cu;
	set_lines(window_bank);
	playback = 0x5810u;
	demo_player = 0u;
	demo_player_bits = players_playing;
	do
	{
		player = player_records[(int8_t)((uint8_t)((uint32_t)demo_player << 1)) / 2];
		state = PLAYER(player)->state;
		mem_write8(state, 0u);
		stack_2 = player >> 8;
		stack = (uint8_t)player;
		object_kind = PLAYER(player)->object_kind;
		mem_write8(object_kind, demo_player);
		t4 = demo_cursor;
		demo_cursor = t4 + 2u;
		inputs = mem_read16(t4);
		mem_write16(playback, inputs);
		frames_2 = DEMO_INPUT(inputs)->frames;
		mem_write8(playback + 2u, frames_2);
		mem_write8(playback + 3u, DEMO_INPUT(inputs)->controls);
		record = ((uint32_t)stack_2 << 8) | stack;
		lives = PLAYER(record)->lives;
		mem_write8(lives, 0u);
		if ((demo_player_bits & 1u) != 0u)
		{
			lives_2 = PLAYER(record)->lives;
			mem_write8(lives_2, 2u);
			state_2 = PLAYER(record)->state;
			mem_write8(state_2, 2u);
		}
		playback += 0x10u;
		demo_player_bits = demo_player_bits >> 1;
		demo_player++;
	} while (demo_player != 4u);
	mode_phase++;
}

/* A frame of the attract's demo: the recorded inputs become the players' controls and the game's frame
   runs; GAME OVER is shown over it once its stage starts, and when demo_frames runs out the next demo is
   chosen and the attract moves on */
void demo_play(uint16_t palette_job)
{
	uint8_t controls = 0;
	uint16_t controls_2 = 0, ignored16 = 0, input_step = 0, playback = 0, port = 0, request = 0;
	uint8_t t2 = 0, frames = 0;
	uint16_t t1 = 0, object_kind = 0;

	if (step_phase == 2u)
	{
		window_bank = 0x20u;
		set_lines(window_bank);
		game_over_draw();
		palette_request_kind = 2u;
		request = 0xBu;
		palette_request(request, &ignored16, &palette_job);
	}
	t1 = demo_frames;
	demo_frames = t1 - 1u;
	if (t1 == 1u)
	{
		demo_number++;
		if (demo_number >= 3u)
			demo_number = 0u;
		reset_for_play();
		mode_step++;
		mode_phase = 0u;
		game_step = 0u;
		step_phase = 0u;
		step_subphase = 0u;
		step_countdown = 0u;
		return;
	}
	window_bank = 0x2Cu;
	set_lines(window_bank);
	playback = 0x5810u;
	demo_player = 0u;
	demo_player_bits = players_playing;
	do
	{
		object_kind = PLAYER(player_records[(int8_t)((uint8_t)((uint32_t)demo_player << 1)) / 2])->object_kind;
		mem_write8(object_kind, demo_player);
		input_step = mem_read16(playback);
		mem_write8(playback + 3u, DEMO_INPUT(input_step)->controls);
		t2 = mem_read8(playback + 2u);
		mem_write8(playback + 2u, t2 - 1u);
		if (t2 == 1u)
		{
			input_step += 2u;
			controls = DEMO_INPUT(input_step)->controls;
			mem_write8(playback + 3u, controls);
			mem_write8(playback + 4u, ~controls);
			frames = DEMO_INPUT(input_step)->frames;
			mem_write8(playback + 2u, frames);
			mem_write16(playback, input_step);
		}
		playback += 0x10u;
		demo_player_bits = demo_player_bits >> 1;
		demo_player++;
	} while (demo_player != 4u);
	marge_demo_controls = ~marge_demo_controls;
	port = marge_demo_controls_ADDRESS;
	controls_2 = player_controls_ADDRESS;
	update_controls(controls_2, port);
	homer_demo_controls = ~homer_demo_controls;
	port = homer_demo_controls_ADDRESS;
	controls_2 = player_controls_ADDRESS + 0x4u;
	update_controls(controls_2, port);
	bart_demo_controls = ~bart_demo_controls;
	port = bart_demo_controls_ADDRESS;
	controls_2 = player_controls_ADDRESS + 0x8u;
	update_controls(controls_2, port);
	lisa_demo_controls = ~lisa_demo_controls;
	port = lisa_demo_controls_ADDRESS;
	controls_2 = player_controls_ADDRESS + 0xCu;
	update_controls(controls_2, port);
	game_mode_frame(port);
	in_attract = 1u;
}
