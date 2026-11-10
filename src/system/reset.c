/**
 *    Name:        system/reset.c
 *    Description: clearing the variables of a stage, of a game, and the scores
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Clears the stage's variables (4870-48FF), then the objects and the tile chip's variables. */
uint16_t reset_for_stage(void)
{
	uint16_t clear_from = 0, clear_to = 0, count = 0;

	clear_from = stage_variables_ADDRESS;
	clear_to = text_colour_ADDRESS;
	stage_variables = 0u;
	count = 0x8Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	return reset_sprites_and_objects();
}

/* Sets the sprite chip's offsets for the flip setting, clears the objects, the variables the game keeps
   in the tile chip's RAM (1840-18FF) and the palette jobs (3C00-3DFF), and a byte of each player's
   record. */
uint16_t reset_sprites_and_objects(void)
{
	uint16_t clear_from = 0, clear_to = 0, count = 0, ignored16 = 0, ignored16_2 = 0;

	if (flip_screen != 0u)
	{
		io_write16(0x1FA0u, 0x255u);
		sprite_scroll_x = 0x255u;
		io_write16(0x1FA2u, 0x71u);
		sprite_scroll_y = 0x71u;
	}
	else
	{
		io_write16(0x1FA0u, 0x15u);
		sprite_scroll_x = 0x15u;
		io_write16(0x1FA2u, 0x261u);
		sprite_scroll_y = 0x261u;
	}
	sprite_scroll_x_pad = 0u;
	sprite_scroll_y_pad = 0u;
	clear_objects(&ignored16, &ignored16_2);
	clear_from = scene_state;
	clear_to = scene_substate;
	io_write8(scene_state, 0u);
	count = 0x1Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_from = 0x1860u;
	clear_to = 0x1861u;
	io_write8(0x1860u, 0u);
	count = 0x7Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_from = 0x1840u;
	clear_to = 0x1841u;
	io_write8(0x1840u, 0u);
	count = 0x1Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_objects(&ignored16, &ignored16_2);
	clear_from = 0x3C00u;
	clear_to = 0x3C01u;
	io_write8(0x3C00u, 0u);
	count = 0x1FFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	marge_entry_status = 0u;
	homer_entry_status = 0u;
	bart_entry_status = 0u;
	lisa_entry_status = 0u;
	return count;
}

/* Clears the four players' scores, then the game's variables. */
uint16_t reset_for_game(void)
{
	marge_score = 0u;
	homer_score = 0u;
	bart_score = 0u;
	lisa_score = 0u;
	return reset_for_play();
}

/* Clears the game's variables (4860-48FF, 3840-386F, the players' countdowns), then the objects and the
   tile chip's variables. */
uint16_t reset_for_play(void)
{
	uint16_t clear_from = 0, clear_to = 0, count = 0;

	clear_from = play_variables_ADDRESS;
	clear_to = rank_ADDRESS;
	play_variables = 0u;
	count = 0x9Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_from = 0x3840u;
	clear_to = 0x3841u;
	io_write8(0x3840u, 0u);
	count = 0x2Fu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	marge_grab_hints = 0u;
	homer_grab_hints = 0u;
	bart_grab_hints = 0u;
	lisa_grab_hints = 0u;
	unused_marge_word_1 = 0u;
	unused_marge_word_2 = 0u;
	unused_marge_byte = 0u;
	unused_homer_word_1 = 0u;
	unused_homer_word_2 = 0u;
	unused_homer_byte = 0u;
	unused_bart_word_1 = 0u;
	unused_bart_word_2 = 0u;
	unused_bart_byte = 0u;
	unused_lisa_word_1 = 0u;
	unused_lisa_word_2 = 0u;
	unused_lisa_byte = 0u;
	return reset_sprites_and_objects();
}
