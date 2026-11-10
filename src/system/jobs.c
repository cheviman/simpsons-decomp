/**
 *    Name:        system/jobs.c
 *    Description: the queues: the main loop's jobs and the sound commands for the Z80, and the jobs themselves
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Puts the job A with its argument B in the main loop's queue (job 0, a screen clear, is counted until
   done). */
void queue_job(uint16_t job)
{
	uint16_t queue_place = 0;
	uint16_t t1 = 0;

	if (job >> 8 == 0u)
		layer_clear_pending++;
	t1 = job_queue_write;
	queue_place = t1 + 2u;
	mem_write16(t1, job);
	if (queue_place >= high_scores_ADDRESS)
		queue_place = job_queue_ADDRESS;
	job_queue_write = queue_place;
}

/* Queues the sound command D for the Z80, unless it is FFFF or the attract runs with its sound off. */
uint32_t queue_sound(uint16_t command)
{
	uint32_t carry = 0;

	carry = command < 0xFFFFu;
	if (command == 0xFFFFu || (in_attract != 0u && attract_sound == 0u))
		return carry;
	return queue_sound_always(command);
}

/* Queues the sound command D for the Z80, unless it is FFFF or the attract runs. */
uint32_t queue_sound_unless_attract(uint16_t command)
{
	uint32_t carry = 0;

	carry = command < 0xFFFFu;
	if (command == 0xFFFFu || in_attract != 0u)
		return carry;
	return queue_sound_always(command);
}

/* Queues the sound command D for the Z80 unless it is FFFF. */
uint32_t queue_sound_always(uint16_t command)
{
	uint32_t carry = 0;
	uint16_t queue_place = 0;
	uint16_t t1 = 0;

	carry = command < 0xFFFFu;
	if (command == 0xFFFFu)
		return carry;
	t1 = sound_queue_write;
	queue_place = t1 + 2u;
	mem_write16(t1, command);
	carry = queue_place < sound_queue_ADDRESS + 0x3Bu;
	if (queue_place > sound_queue_ADDRESS + 0x3Bu)
		queue_place = sound_queue_ADDRESS;
	sound_queue_write = queue_place;
	return carry;
}

/* Job 0: clears the tile layers B names (0 all, 1 the text layer, 2 layer A, 3 layer B) and marks the
   clears done. */
void job_clear_screen(uint8_t layers_to_clear)
{
	switch ((int8_t)(uint8_t)((uint32_t)layers_to_clear << 1))
	{
	case 0:
		job_clear_all_layers();
		break;
	case 2:
		job_clear_text_layer();
		break;
	case 4:
		job_clear_layer_a();
		break;
	case 6:
		job_clear_layer_b();
		break;
	}
	layer_clear_pending = 0u;
}

/* Clears the three tile layers (job 0 with B 0). */
void job_clear_all_layers(void)
{
	clear_tile_layers();
}

/* Clears the text layer (job 0 with B 1). */
void job_clear_text_layer(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	clear_text_layer(&ignored16, &ignored16_2);
}

/* Clears layer A (job 0 with B 2). */
void job_clear_layer_a(void)
{
	clear_layer_a();
}

/* Clears layer B (job 0 with B 3). */
void job_clear_layer_b(void)
{
	clear_layer_b();
}

/* Job 1: prints the game's text B in the colour job 2 set. */
void job_print_game_text(uint8_t game_text)
{
	uint16_t text_number = 0;

	text_number = (game_text & 0xFFu) | ((uint32_t)text_colour << 8);
	print_game_text(text_number);
}

/* Job 2: sets the colour job 1 prints in. */
void job_set_text_colour(uint8_t colour)
{
	text_colour = colour;
}

/* Job 3: adds score_additions' entry B to Marge's score (player 1). */
void job_add_marge_score(uint8_t addition)
{
	uint16_t score = 0;

	score = marge_score_ADDRESS;
	add_score(score, addition);
}

/* Job 4: adds score_additions' entry B to Homer's score (player 2). */
void job_add_homer_score(uint8_t addition)
{
	uint16_t score = 0;

	score = homer_score_ADDRESS;
	add_score(score, addition);
}

/* Job 5: adds score_additions' entry B to Bart's score (player 3). */
void job_add_bart_score(uint8_t addition)
{
	uint16_t score = 0;

	score = bart_score_ADDRESS;
	add_score(score, addition);
}

/* Job 6: adds score_additions' entry B to Lisa's score (player 4). */
void job_add_lisa_score(uint8_t addition)
{
	uint16_t score = 0;

	score = lisa_score_ADDRESS;
	add_score(score, addition);
}

/* Jobs 7 to 15: nothing. */
void job_none(void)
{
}
