/**
 *    Name:        video/text.c
 *    Description: the text printers: the game's texts, texts at an address, hex digits
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Prints the game's text number B in colour A, or erases it when B's bit 7 is set (game_texts in bank
   12: INSERT COIN, the copyright, the RAM ROM CHECK's...). */
uint16_t print_game_text(uint16_t text_number)
{
	uint8_t colour_byte = 0, text_offset = 0;
	uint16_t colour = 0, ignored16 = 0, text = 0;
	uint8_t saved_window_bank = 0, stack = 0;
	uint8_t t1 = 0;

	game_text_colour = text_number >> 8;
	saved_window_bank = window_bank;
	colour_byte = game_text_colour;
	t1 = (uint8_t)text_number;
	text_offset = (uint32_t)t1 << 1;
	if ((int8_t)t1 < 0)
	{
		stack = text_offset & 0x7Fu;
		window_bank = 0x12u;
		set_lines(window_bank);
		text = GAME_TEXT_ENTRY(game_texts_address[0] + stack);
		text = erase_text(text);
		window_bank = saved_window_bank;
		set_lines(window_bank);
		return text;
	}
	stack = text_offset & 0x7Fu;
	window_bank = 0x12u;
	set_lines(window_bank);
	text = GAME_TEXT_ENTRY(game_texts_address[0] + stack);
	colour = (text_number & 0xFFu) | ((uint32_t)colour_byte << 8);
	print_text(colour, &ignored16, &text);
	window_bank = saved_window_bank;
	set_lines(window_bank);
	return text;
}

/* Prints the text at U in colour A: an address in the tile RAM, the characters (each a tile, the
   character less 30), '/' and another address, ' */
void print_text(uint16_t colour, uint16_t *p_place, uint16_t *p_text)
{
	uint16_t text = (uint16_t)*p_text;
	uint8_t character = 0;
	uint16_t place = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = text;
		text = t1 + 2u;
		place = mem_read16(t1);
		for (;;)
		{
			t2 = text;
			text = t2 + 1u;
			character = mem_read8(t2);
			if (character == 0x23u)
			{
				*p_place = place;
				*p_text = text;
				return;
			}
			if (character == 0x2Fu)
				break;
			character -= 0x30u;
			mem_write8(place - 0x2000u, ((colour & ~0xFFu) | character) >> 8);
			t3 = place;
			place = t3 + 1u;
			mem_write8(t3, character);
		}
	}
}

/* Blanks the text at U where print_text put it. */
uint16_t erase_text(uint16_t text)
{
	uint8_t character = 0;
	uint16_t place = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = text;
		text = t1 + 2u;
		place = mem_read16(t1);
		for (;;)
		{
			t2 = text;
			text = t2 + 1u;
			character = mem_read8(t2);
			if (character == 0x23u)
				return text;
			if (character == 0x2Fu)
				break;
			mem_write8(place - 0x2000u, 0u);
			t3 = place;
			place = t3 + 1u;
			mem_write8(t3, 0x10u);
		}
	}
	unreachable();
}

/* Prints A as two hex digits at the tile RAM's X in colour B. */
uint16_t print_hex_byte(uint16_t place, uint16_t value)
{
	uint8_t digit_tile = 0, printed_byte = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0, t2 = 0;

	printed_byte = (uint8_t)(value >> 8);
	stack = printed_byte;
	digit_tile = hex_digit_tiles[((((printed_byte & ~0xFu) >> 1) >> 1) >> 1) >> 1];
	io_write8(place - 0x2000u, (uint8_t)value);
	t1 = place;
	place = t1 + 1u;
	io_write8(t1, digit_tile);
	digit_tile = hex_digit_tiles[stack & 0xFu];
	mem_write8(place - 0x2000u, (uint8_t)value);
	t2 = place;
	place = t2 + 1u;
	mem_write8(t2, digit_tile);
	return place;
}

/* Prints D as four hex digits at the tile RAM's X in the colour at 48F0. */
uint16_t print_hex_word(uint16_t place, uint16_t value)
{
	uint8_t a = 0, colour = 0;
	uint16_t d = 0;
	uint8_t stack = 0;

	stack = (uint8_t)value;
	value = (value & ~0xFFu) | hex_colour;
	place = print_hex_byte(place, value);
	colour = hex_colour;
	d = ((uint32_t)stack << 8) | colour;
	print_hex_byte(place, d);
	a = (uint8_t)(d >> 8);
	value = ((uint32_t)a << 8) | colour;
	return value;
}
