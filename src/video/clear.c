/**
 *    Name:        video/clear.c
 *    Description: clearing the K052109's three tile layers and the sprite RAM
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
}

/* Clears the text layer's 36 visible columns of its 32 rows and puts tile 3F in the two columns at each
   side of them. */
void clear_text_layer(uint16_t *p_place, uint16_t *p_d)
{
	uint8_t edge_high = 0, edge_low = 0;
	uint16_t d = 0, place = 0;
	uint8_t rows_to_go = 0, row_or_colours_low = 0, row_or_colours_high = 0, words_or_tiles_low = 0, edge_tiles_high = 0;
	uint8_t row_words_left = 0, rows_left = 0, edge_rows_left = 0;
	uint16_t written_place = 0, edge_tiles = 0, edge_colours = 0;

	place = 0x200Eu;
	rows_to_go = 0x20u;
	do
	{
		row_or_colours_high = place >> 8;
		row_or_colours_low = (uint8_t)place;
		words_or_tiles_low = 0x12u;
		do
		{
			mem_write16(place - 0x2000u, 0u);
			written_place = place;
			place = written_place + 2u;
			mem_write16(written_place, 0x1010u);
			row_words_left = words_or_tiles_low;
			words_or_tiles_low = row_words_left - 1u;
		} while (row_words_left != 1u);
		place = (((uint32_t)row_or_colours_high << 8) | row_or_colours_low) + 0x40u;
		rows_left = rows_to_go;
		rows_to_go = rows_left - 1u;
	} while (rows_left != 1u);
	place = 0x200Cu;
	rows_to_go = 0x20u;
	row_or_colours_low = 0u;
	row_or_colours_high = 0u;
	words_or_tiles_low = 0x3Fu;
	edge_tiles_high = 0x3Fu;
	do
	{
		edge_tiles = ((uint32_t)edge_tiles_high << 8) | words_or_tiles_low;
		edge_low = (uint8_t)edge_tiles;
		edge_high = (uint8_t)(edge_tiles >> 8);
		mem_write16(place, ((uint32_t)edge_high << 8) | (edge_low & 0xFFu));
		mem_write16(place + 0x26u, ((uint32_t)edge_high << 8) | (edge_low & 0xFFu));
		edge_colours = ((uint32_t)row_or_colours_high << 8) | row_or_colours_low;
		edge_low = (uint8_t)edge_colours;
		edge_high = (uint8_t)(edge_colours >> 8);
		mem_write16(place - 0x2000u, (uint32_t)edge_high << 8);
		mem_write16(place - 0x1FDAu, (uint32_t)edge_high << 8);
		place += 0x40u;
		edge_rows_left = rows_to_go;
		rows_to_go = edge_rows_left - 1u;
	} while (edge_rows_left != 1u);
	d = (uint32_t)edge_high << 8;
	*p_place = place;
	*p_d = d;
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
	io_write8(board_control_register, control);
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
	io_write8(board_control_register, control);
	return place;
}
