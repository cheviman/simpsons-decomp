/**
 *    Name:        stages/rank.c
 *    Description: the game's rank (direct page 61) and the HURRY UP's timer
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Works out the game's rank (at most 1F) from its terms, each frame of play */
void rank_update(void)
{
	uint8_t start_rank = 0;

	rank = 0u;
	rank_count_frame();
	rank_add_base();
	rank_add_players();
	rank_add_time_step();
	rank_add_scene();
	rank_check_frame_limit();
	set_spawn_level();
	hurry_up_timer();
	start_rank = 0x1Fu;
	if (rank > 0x1Fu)
		rank = start_rank;
}

/* Counts the frames toward the rank's next time step */
void rank_count_frame(void)
{
	rank_frames++;
}

/* Adds the difficulty's base (the attract's is 1) */
void rank_add_base(void)
{
	uint8_t setting = 0;
	uint16_t amounts = 0;

	amounts = rank_base_ADDRESS;
	if (in_attract != 0u)
		setting = 1u;
	else
		setting = difficulty_setting;
	rank += RANK_AMOUNT(amounts + (int8_t)setting);
}

/* Adds the term for the players in the game */
void rank_add_players(void)
{
	rank += rank_by_players[(int8_t)((uint8_t)(player_count - 1u))];
}

/* Raises the time step (up to 5) each time the scene's time passes, and adds it */
void rank_add_time_step(void)
{
	uint8_t time_step = 0;
	uint16_t t1 = 0;

	t1 = rank_frames;
	if (t1 < rank_step_times[(int8_t)((uint8_t)((uint32_t)scene << 1)) / 2])
	{
		rank += rank_time_step;
		return;
	}
	rank_time_step++;
	time_step = 5u;
	if (rank_time_step > 5u)
		rank_time_step = time_step;
	rank_frames = 0u;
	rank += rank_time_step;
}

/* Adds the scene's term */
void rank_add_scene(void)
{
	rank += rank_by_scene[(int8_t)scene];
}

/* Compares a count with the scene's limit; the result is not used */
void rank_check_frame_limit(void)
{
	uint16_t t1 = 0;

	t1 = camera_wait_frames;
}

/* Counts idle frames; after 256 puts in the HURRY UP */
void hurry_up_timer(void)
{
	uint32_t carry = 0;
	uint8_t list_number = 0;
	uint16_t hurry_object = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	t1 = hurry_up_frames;
	t2 = t1 + 1u;
	hurry_up_frames = t2;
	if (hurry_up_out != 0u)
		hurry_up_frames = 0u;
	t3 = io_read8(0x1883u);
	if (t3 != 0u)
		hurry_up_frames = 0u;
	if (stage_scrolls_on == 0u)
		hurry_up_frames = 0u;
	if (camera_x_held != 0u)
		hurry_up_frames = 0u;
	if (camera_y_held != 0u)
		hurry_up_frames = 0u;
	if ((uint16_t)camera_x_speed != 0u)
		hurry_up_frames = 0u;
	t4 = hurry_up_frames;
	if (t4 < 0x100u)
		return;
	list_number = 2u;
	vector_find_free_slot(list_number, &hurry_object, &carry);
	hurry_up_object = hurry_object;
	hurry_up_out = 1u;
	OBJECT(hurry_object)->type = 8;
	hurry_up_frames = 0u;
}

/* The level of the spawns the stage puts in: the players less one, plus the difficulty (1 in the
   attract) */
void set_spawn_level(void)
{
	uint8_t level = 0;

	level = (player_count - 1u) & 3u;
	if (in_attract != 0u)
		level++;
	else
		level += difficulty_setting;
	difficulty = level;
}
