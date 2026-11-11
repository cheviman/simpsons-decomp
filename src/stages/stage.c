/**
 *    Name:        stages/stage.c
 *    Description: what every stage shares: its opening, its frame, its end
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* A frame of a stage's opening: its scene's routine from scene_routines (a story script for the actor)
   runs until it clears scene_running, then the stage plays; in the attract's demo it is skipped at once */
uint16_t stage_opening(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;
	uint16_t routine_record = 0;

	if (in_attract != 0u)
	{
		step_phase++;
		check_collisions(&ignored16, &ignored16_2);
		update_players(&ignored16_3, &u, &ignored16_2, &carry);
		return u;
	}
	scene_running = 1u;
	run_child_objects(0u);
	routine_record = scene_routines_ADDRESS + (int8_t)(((uint32_t)scene << 1) << 1);
	window_bank = SCENE_ROUTINE(routine_record)->bank;
	set_lines(window_bank);
	switch ((uint16_t)(routine_record + 1u))
	{
	case scene_routines_ADDRESS + 0x1u:
		stage_1_events();
		break;
	case scene_routines_ADDRESS + 0x5u:
		stage_2_events();
		break;
	case scene_routines_ADDRESS + 0x9u:
	case scene_routines_ADDRESS + 0x1Du:
	case scene_routines_ADDRESS + 0x29u:
		carry = scene_routine_nothing();
		break;
	case scene_routines_ADDRESS + 0xDu:
		stage_3_forest_events();
		break;
	case scene_routines_ADDRESS + 0x11u:
		stage_3_cemetery_events();
		break;
	case scene_routines_ADDRESS + 0x15u:
		stage_4_events();
		break;
	case scene_routines_ADDRESS + 0x19u:
		stage_5_events();
		break;
	case scene_routines_ADDRESS + 0x21u:
		stage_6_events();
		break;
	case scene_routines_ADDRESS + 0x25u:
		stage_7_events();
		break;
	case scene_routines_ADDRESS + 0x2Du:
		stage_8_events();
		break;
	}
	if (scene_running != 0u)
	{
		check_collisions(&ignored16, &ignored16_2);
		update_players(&ignored16_3, &u, &ignored16_2, &carry);
		return u;
	}
	step_phase++;
	check_collisions(&ignored16, &ignored16_2);
	update_players(&ignored16_3, &u, &ignored16_2, &carry);
	return u;
}

/* A frame of a stage's play: the rank, the hits, the spawns, every object list, the players' objects,
   the players' handling and the check that someone still plays */
void stage_play_frame(uint16_t *p_u, uint32_t *p_left_caller)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;

	window_bank = 0x20u;
	set_lines(window_bank);
	rank_update();
	check_collisions(&ignored16, &ignored16_2);
	spawn_stage_objects();
	run_list_1_objects(&ignored16, p_left_caller);
	*p_left_caller = run_enemies(*p_left_caller);
	run_child_objects(ignored16);
	run_stage_event();
	window_bank = 0x1Cu;
	set_lines(window_bank);
	player_run_all();
	window_bank = 0x1Fu;
	set_lines(window_bank);
	u = players_update_second_sprites();
	window_bank = 0x13u;
	set_lines(window_bank);
	stage_scroll(u);
	update_players(&ignored16_3, &u, &ignored16_2, &carry);
	u = game_phase_check(u);
	*p_u = u;
}

/* Sets the stage's and both tile layers' scroll x (and their last frame's copies) and clears the layers'
   x offsets */
void set_scroll_x(uint16_t scroll_x)
{
	layer_a_scroll_x = scroll_x;
	layer_b_scroll_x = scroll_x;
	layer_a_last_scroll_x = scroll_x;
	layer_b_last_scroll_x = scroll_x;
	camera_x = scroll_x;
	last_stage_scroll_x = scroll_x;
	layer_a_offset_x = 0u;
	layer_b_offset_x = 0u;
}

/* Sets the stage's and both tile layers' scroll y (and their last frame's copies) and clears the layers'
   y offsets */
void set_scroll_y(uint16_t scroll_y)
{
	layer_a_scroll_y = scroll_y;
	layer_b_scroll_y = scroll_y;
	layer_a_last_scroll_y = scroll_y;
	layer_b_last_scroll_y = scroll_y;
	camera_y = scroll_y;
	last_stage_scroll_y = scroll_y;
	layer_a_offset_y = 0u;
	layer_b_offset_y = 0u;
}

/* Marks the stage over for the players' objects, clears the enemies and moves to the next phase */
uint16_t stage_over(void)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u = 0;

	io_write8(0x184Bu, 1u);
	clear_enemy_objects();
	step_phase++;
	update_players(&ignored16, &u, &ignored16_2, &carry);
	return u;
}

/* A frame of the players leaving the stage: when they are all out the stage's players are noted again,
   the next phase starts and it returns done (carry) */
void stage_players_exit(uint16_t *p_u, uint32_t *p_left_caller, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0;
	uint8_t players_signal = 0;

	scene_running = 1u;
	run_list_1_objects(&ignored16, p_left_caller);
	run_child_objects(ignored16);
	window_bank = 0x1Cu;
	set_lines(window_bank);
	player_run_all();
	update_players(&ignored16_2, &u, &ignored16_3, &carry);
	players_signal = io_read8(0x184Eu);
	if (players_signal == 0u)
		carry = scene_routine_nothing();
	else
	{
		players_present = players_playing;
		step_phase++;
		carry = 1u;
	}
	*p_u = u;
	*p_carry = carry;
}

/* Does nothing and returns not done: the story scenes' routine, and the players not all out yet */
uint32_t scene_routine_nothing(void)
{
	uint32_t carry = 0;

	carry = 0u;
	return carry;
}

/* Sets current_scene from step_scenes by game_step */
void set_step_scene(void)
{
	scene = step_scenes[(int8_t)game_step];
}

/* Plays the music of the scene's current part (stage_part) */
void play_stage_music(void)
{
	uint16_t music_by_scene = 0;

	music_by_scene = stage_music_lists_ADDRESS;
	play_scene_music(music_by_scene);
}

/* Plays the scene's music again after a continue, from its own table */
void resume_stage_music(void)
{
	uint16_t music_by_scene = 0;

	music_by_scene = resumed_stage_music_lists_ADDRESS;
	play_scene_music(music_by_scene);
}

/* Sends the sound commands of the scene's music part from the given table (two in scene 6), unless
   boss_beaten */
void play_scene_music(uint16_t music_by_scene)
{
	uint32_t carry = 0;
	uint8_t part_offset = 0;
	uint16_t command = 0, scene_music = 0;
	uint16_t music_at = 0, music_command = 0, second_command = 0;

	if (boss_beaten != 0u)
		return;
	scene_music = mem_read16(music_by_scene + (int8_t)((uint32_t)scene << 1));
	part_offset = (uint32_t)stage_part << 1;
	if (scene == 6u)
		part_offset = (uint32_t)part_offset << 1;
	music_at = scene_music + (int8_t)part_offset;
	scene_music = music_at + 2u;
	music_command = mem_read16(music_at);
	command = music_command;
	carry = queue_sound_unless_attract(command);
	if (scene == 6u)
	{
		second_command = mem_read16(scene_music);
		command = second_command;
		carry = queue_sound_unless_attract(command);
	}
}
