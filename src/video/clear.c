/**
 *    Name:        video/clear.c
 *    Description: clearing the K052109's three tile layers and the sprite RAM
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Clears the K052109's three layers. */
void clear_tile_layers(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	clear_layer_a();
	clear_layer_b();
	clear_text_layer(&ignored16, &ignored16_2);
}

/* Clears layer A: its tiles blank (10) and its colours 0. */
void clear_layer_a(void)
{
	uint16_t blank_tiles = 0, place = 0, words_left = 0;
	uint16_t cleared_place = 0, remaining_words = 0;

	place = 0x800u;
	blank_tiles = 0x1010u;
	words_left = 0x400u;
	do
	{
		mem_write16(place + 0x2000u, blank_tiles);
		cleared_place = place;
		place = cleared_place + 2u;
		mem_write16(cleared_place, 0u);
		remaining_words = words_left - 1u;
		words_left = remaining_words;
	} while (remaining_words != 0u);
	leftover_y = words_left;
}

/* Clears layer B: its tiles blank (10) and its colours 0. */
void clear_layer_b(void)
{
	uint16_t blank_tiles = 0, place = 0, words_left = 0;
	uint16_t cleared_place = 0, remaining_words = 0;

	place = 0x1000u;
	blank_tiles = 0x1010u;
	words_left = 0x400u;
	do
	{
		mem_write16(place + 0x2000u, blank_tiles);
		cleared_place = place;
		place = cleared_place + 2u;
		mem_write16(cleared_place, 0u);
		remaining_words = words_left - 1u;
		words_left = remaining_words;
	} while (remaining_words != 0u);
	leftover_y = words_left;
}

/* Clears the text layer's 36 visible columns of its 32 rows and puts tile 3F in the two columns at each
   side of them. */
void clear_text_layer(uint16_t *p_place, uint16_t *p_d)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, place = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t row_words_left = 0, rows_left = 0, edge_rows_left = 0;
	uint16_t written_place = 0, edge_tiles = 0, edge_colours = 0;

	place = 0x200Eu;
	stack = 0x20u;
	do
	{
		stack_3 = place >> 8;
		stack_2 = (uint8_t)place;
		stack_4 = 0x12u;
		do
		{
			mem_write16(place - 0x2000u, 0u);
			written_place = place;
			place = written_place + 2u;
			mem_write16(written_place, 0x1010u);
			row_words_left = stack_4;
			stack_4 = row_words_left - 1u;
		} while (row_words_left != 1u);
		place = (((uint32_t)stack_3 << 8) | stack_2) + 0x40u;
		rows_left = stack;
		stack = rows_left - 1u;
	} while (rows_left != 1u);
	place = 0x200Cu;
	stack = 0x20u;
	stack_2 = 0u;
	stack_3 = 0u;
	stack_4 = 0x3Fu;
	stack_5 = 0x3Fu;
	do
	{
		edge_tiles = ((uint32_t)stack_5 << 8) | stack_4;
		d = (uint8_t)edge_tiles;
		a = (uint8_t)(edge_tiles >> 8);
		mem_write16(place, ((uint32_t)a << 8) | (d & 0xFFu));
		mem_write16(place + 0x26u, ((uint32_t)a << 8) | (d & 0xFFu));
		edge_colours = ((uint32_t)stack_3 << 8) | stack_2;
		d = (uint8_t)edge_colours;
		a = (uint8_t)(edge_colours >> 8);
		mem_write16(place - 0x2000u, (uint32_t)a << 8);
		mem_write16(place - 0x1FDAu, (uint32_t)a << 8);
		place += 0x40u;
		edge_rows_left = stack;
		stack = edge_rows_left - 1u;
	} while (edge_rows_left != 1u);
	d_2 = (uint32_t)a << 8;
	*p_place = place;
	*p_d = d_2;
}

/* Clears the sprite RAM (2000-2FFF). */
uint16_t clear_sprites(void)
{
	uint8_t control = 0, words_left = 0;
	uint16_t bytes_left = 0, place = 0;
	uint8_t sprite_words_left = 0;
	uint16_t cleared_place = 0, remaining_bytes = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	place = 0x2000u;
	bytes_left = 0x1000u;
	do
	{
		words_left = 8u;
		do
		{
			cleared_place = place;
			place = cleared_place + 2u;
			mem_write16(cleared_place, 0u);
			sprite_words_left = words_left;
			words_left = sprite_words_left - 1u;
		} while (sprite_words_left != 1u);
		remaining_bytes = bytes_left - 0x10u;
		bytes_left = remaining_bytes;
	} while (remaining_bytes != 0u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	leftover_y = bytes_left;
	return place;
}
