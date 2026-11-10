/**
 *    Name:        video/clear.c
 *    Description: clearing the K052109's three tile layers and the sprite RAM
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Clears the K052109's three layers. */
void clear_tile_layers(void)
{
	uint16_t ignored16 = 0, ignored16_3 = 0;

	clear_layer_a();
	clear_layer_b();
	clear_text_layer(&ignored16, &ignored16_3);
}

/* Clears layer A: its tiles blank (10) and its colours 0. */
uint16_t clear_layer_a(void)
{
	uint16_t blank_tiles = 0, place = 0, words_left = 0;
	uint16_t t1 = 0, t2 = 0;

	place = 0x800u;
	blank_tiles = 0x1010u;
	words_left = 0x400u;
	do
	{
		mem_write16(place + 0x2000u, blank_tiles);
		t1 = place;
		place = t1 + 2u;
		mem_write16(t1, 0u);
		t2 = words_left - 1u;
		words_left = t2;
	} while (t2 != 0u);
	return words_left;
}

/* Clears layer B: its tiles blank (10) and its colours 0. */
uint16_t clear_layer_b(void)
{
	uint16_t blank_tiles = 0, place = 0, words_left = 0;
	uint16_t t1 = 0, t2 = 0;

	place = 0x1000u;
	blank_tiles = 0x1010u;
	words_left = 0x400u;
	do
	{
		mem_write16(place + 0x2000u, blank_tiles);
		t1 = place;
		place = t1 + 2u;
		mem_write16(t1, 0u);
		t2 = words_left - 1u;
		words_left = t2;
	} while (t2 != 0u);
	return words_left;
}

/* Clears the text layer's 36 visible columns of its 32 rows and puts tile 3F in the two columns at each
   side of them. */
void clear_text_layer(uint16_t *p_place, uint16_t *p_d)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, place = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t2 = 0, t3 = 0, t6 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0;

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
			t1 = place;
			place = t1 + 2u;
			mem_write16(t1, 0x1010u);
			t2 = stack_4;
			stack_4 = t2 - 1u;
		} while (t2 != 1u);
		place = (((uint32_t)stack_3 << 8) | stack_2) + 0x40u;
		t3 = stack;
		stack = t3 - 1u;
	} while (t3 != 1u);
	place = 0x200Cu;
	stack = 0x20u;
	stack_2 = 0u;
	stack_3 = 0u;
	stack_4 = 0x3Fu;
	stack_5 = 0x3Fu;
	do
	{
		t4 = ((uint32_t)stack_5 << 8) | stack_4;
		d = (uint8_t)t4;
		a = (uint8_t)(t4 >> 8);
		mem_write16(place, ((uint32_t)a << 8) | (d & 0xFFu));
		mem_write16(place + 0x26u, ((uint32_t)a << 8) | (d & 0xFFu));
		t5 = ((uint32_t)stack_3 << 8) | stack_2;
		d = (uint8_t)t5;
		a = (uint8_t)(t5 >> 8);
		mem_write16(place - 0x2000u, (uint32_t)a << 8);
		mem_write16(place - 0x1FDAu, (uint32_t)a << 8);
		place += 0x40u;
		t6 = stack;
		stack = t6 - 1u;
	} while (t6 != 1u);
	d_2 = (uint32_t)a << 8;
	*p_place = place;
	*p_d = d_2;
}

/* Clears the sprite RAM (2000-2FFF). */
void clear_sprites(uint16_t *p_place, uint16_t *p_bytes_left)
{
	uint8_t control = 0, words_left = 0;
	uint16_t bytes_left = 0, place = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

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
			t1 = place;
			place = t1 + 2u;
			mem_write16(t1, 0u);
			t2 = words_left;
			words_left = t2 - 1u;
		} while (t2 != 1u);
		t3 = bytes_left - 0x10u;
		bytes_left = t3;
	} while (t3 != 0u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	*p_place = place;
	*p_bytes_left = bytes_left;
}
