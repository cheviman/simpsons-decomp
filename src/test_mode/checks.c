/**
 *    Name:        test_mode/checks.c
 *    Description: ROM, screen, colour and I/O checks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The 1 ROM CHECK page, by its step */
void test_rom_check_page(uint16_t setting, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, x = 0;

	x = test_rom_check_page_steps_ADDRESS;
	switch ((uint16_t)(x + (int8_t)((uint32_t)test_page_step << 1)))
	{
	case test_menu_page_steps_ADDRESS:
		test_menu_open(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		test_menu_update(&ignored16, &carry);
		return;
	case test_rom_check_page_steps_ADDRESS:
		carry = test_rom_check_open(x);
		return;
	case 0x60A3u:
		test_rom_check_run(&ignored16, &carry);
		return;
	case test_screen_check_page_steps_ADDRESS:
		test_screen_check_draw(&ignored16, &carry);
		return;
	case test_color_check_page_steps_ADDRESS:
		test_color_check_draw(&ignored16, &carry);
		return;
	case test_io_check_page_steps_ADDRESS:
		test_io_check_open(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		carry = test_music_open(x);
		return;
	case 0x621Du:
		test_music_first_choice(&ignored16, &carry);
		return;
	case 0x621Fu:
		test_music_choice(&d, &carry);
		return;
	case 0x6221u:
		test_music_replay(&ignored16, &carry);
		return;
	case test_sound_page_steps_ADDRESS:
		carry = test_sound_open(x);
		return;
	case 0x6279u:
		test_sound_first_choice(&ignored16, &carry);
		return;
	case 0x627Bu:
		test_sound_choice(&d, &carry);
		return;
	case 0x627Du:
		test_sound_replay(&ignored16, &carry);
		return;
	case test_options_page_steps_ADDRESS:
		test_options_open(&ignored16, &carry);
		return;
	case test_choose_setting_steps_ADDRESS:
		test_choose_setting_open(x, setting, &d, &carry);
		return;
	case 0x642Du:
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Starts the ROM check and prints its page */
uint32_t test_rom_check_open(uint16_t tiles)
{
	uint16_t text_number = 0;

	rom_check_step = 0u;
	text_number = 0x100u;
	return test_open_page(tiles, text_number);
}

/* Unused: the ROM check page's next step. */
void unused_test_rom_check_next_step(void)
{
	test_page_step++;
}

/* Runs the ROM check's next step and the page's menu */
void test_rom_check_run(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, row = 0;

	row = 0x26DDu;
	io_write8(0x26DDu, 0x10u);
	test_unmark_row(row, &ignored16, &d);
	d = test_rom_check_step(d);
	*p_d = d;
	test_menu_update(p_d, &carry);
	*p_carry = carry;
}

/* The 2 SCREEN CHECK page, by its step */
void test_screen_check_page(uint16_t setting, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, x = 0;

	x = test_screen_check_page_steps_ADDRESS;
	switch ((uint16_t)(x + (int8_t)((uint32_t)test_page_step << 1)))
	{
	case test_menu_page_steps_ADDRESS:
		test_menu_open(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		test_menu_update(&ignored16, &carry);
		return;
	case test_rom_check_page_steps_ADDRESS:
		carry = test_rom_check_open(x);
		return;
	case 0x60A3u:
		test_rom_check_run(&ignored16, &carry);
		return;
	case test_screen_check_page_steps_ADDRESS:
		test_screen_check_draw(&ignored16, &carry);
		return;
	case test_color_check_page_steps_ADDRESS:
		test_color_check_draw(&ignored16, &carry);
		return;
	case test_io_check_page_steps_ADDRESS:
		test_io_check_open(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		carry = test_music_open(x);
		return;
	case 0x621Du:
		test_music_first_choice(&ignored16, &carry);
		return;
	case 0x621Fu:
		test_music_choice(&d, &carry);
		return;
	case 0x6221u:
		test_music_replay(&ignored16, &carry);
		return;
	case test_sound_page_steps_ADDRESS:
		carry = test_sound_open(x);
		return;
	case 0x6279u:
		test_sound_first_choice(&ignored16, &carry);
		return;
	case 0x627Bu:
		test_sound_choice(&d, &carry);
		return;
	case 0x627Du:
		test_sound_replay(&ignored16, &carry);
		return;
	case test_options_page_steps_ADDRESS:
		test_options_open(&ignored16, &carry);
		return;
	case test_choose_setting_steps_ADDRESS:
		test_choose_setting_open(x, setting, &d, &carry);
		return;
	case 0x642Du:
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Fills the screen with the crosshatch tiles and prints the page */
void test_screen_check_draw(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t pairs_left = 0, rows_left = 0;
	uint16_t lower_tiles = 0, text_number = 0, tiles = 0, upper_tiles = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	upper_tiles = 0x2F2Eu;
	lower_tiles = 0x2D2Cu;
	tiles = 0x2800u;
	rows_left = 0xEu;
	do
	{
		pairs_left = 0x14u;
		do
		{
			mem_write16(tiles + 0x40u, lower_tiles);
			t1 = tiles;
			tiles = t1 + 2u;
			mem_write16(t1, upper_tiles);
			t2 = pairs_left;
			pairs_left = t2 - 1u;
		} while (t2 != 1u);
		tiles += 0x58u;
		t3 = rows_left;
		rows_left = t3 - 1u;
	} while (t3 != 1u);
	text_number = 0x200u | pairs_left;
	carry = test_open_page(tiles, text_number);
	*p_d = text_number;
	*p_carry = carry;
}

/* The 3 COLOR CHECK page, by its step */
void test_color_check_page(uint16_t setting, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, x = 0;

	x = test_color_check_page_steps_ADDRESS;
	switch ((uint16_t)(x + (int8_t)((uint32_t)test_page_step << 1)))
	{
	case test_menu_page_steps_ADDRESS:
		test_menu_open(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		test_menu_update(&ignored16, &carry);
		return;
	case test_rom_check_page_steps_ADDRESS:
		carry = test_rom_check_open(x);
		return;
	case 0x60A3u:
		test_rom_check_run(&ignored16, &carry);
		return;
	case test_screen_check_page_steps_ADDRESS:
		test_screen_check_draw(&ignored16, &carry);
		return;
	case test_color_check_page_steps_ADDRESS:
		test_color_check_draw(&ignored16, &carry);
		return;
	case test_io_check_page_steps_ADDRESS:
		test_io_check_open(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		carry = test_music_open(x);
		return;
	case 0x621Du:
		test_music_first_choice(&ignored16, &carry);
		return;
	case 0x621Fu:
		test_music_choice(&d, &carry);
		return;
	case 0x6221u:
		test_music_replay(&ignored16, &carry);
		return;
	case test_sound_page_steps_ADDRESS:
		carry = test_sound_open(x);
		return;
	case 0x6279u:
		test_sound_first_choice(&ignored16, &carry);
		return;
	case 0x627Bu:
		test_sound_choice(&d, &carry);
		return;
	case 0x627Du:
		test_sound_replay(&ignored16, &carry);
		return;
	case test_options_page_steps_ADDRESS:
		test_options_open(&ignored16, &carry);
		return;
	case test_choose_setting_steps_ADDRESS:
		test_choose_setting_open(x, setting, &d, &carry);
		return;
	case 0x642Du:
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Draws the colour blocks and the four colour ramps and prints the page */
void test_color_check_draw(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0, colour = 0, tile = 0;
	uint16_t d = 0, text_number = 0, tile_and_colour = 0, tiles = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	tile = 0x31u;
	tiles = 0x2190u;
	colour_blocks_left = 8u;
	do
	{
		colour_block_rows_left = 6u;
		do
		{
			colour_block_tiles_left = 4u;
			colour = 0x80u;
			do
			{
				tile_and_colour = ((uint32_t)tile << 8) | colour;
				tiles = test_put_tile(tiles, tile_and_colour);
				t1 = colour_block_tiles_left;
				colour_block_tiles_left = t1 - 1u;
			} while (t1 != 1u);
			tiles += 0x3Cu;
			t2 = colour_block_rows_left;
			colour_block_rows_left = t2 - 1u;
		} while (t2 != 1u);
		tile++;
		tiles -= 0x17Cu;
		t3 = colour_blocks_left;
		colour_blocks_left = t3 - 1u;
	} while (t3 != 1u);
	tiles = 0x3344u;
	tile_and_colour = 0x3000u;
	test_color_check_draw_ramp(&tiles, &tile_and_colour);
	tiles = 0x3404u;
	tile_and_colour = 0x3040u;
	test_color_check_draw_ramp(&tiles, &tile_and_colour);
	tiles = 0x34C4u;
	tile_and_colour = 0x3080u;
	test_color_check_draw_ramp(&tiles, &tile_and_colour);
	tiles = 0x3584u;
	d = 0x30C0u;
	test_color_check_draw_ramp(&tiles, &d);
	b = (uint8_t)d;
	text_number = 0x300u | b;
	carry = test_open_page(tiles, text_number);
	*p_d = text_number;
	*p_carry = carry;
}

/* Draws one ramp of 16 colours, two tiles by two each */
void test_color_check_draw_ramp(uint16_t *p_tiles, uint16_t *p_tile_and_colour)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t tile_and_colour = (uint16_t)*p_tile_and_colour;
	uint8_t a = 0, b = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	stack = (uint8_t)tile_and_colour;
	stack_2 = tile_and_colour >> 8;
	ramp_colours_left = 0x10u;
	do
	{
		ramp_rows_left = 2u;
		do
		{
			t1 = ((uint32_t)stack_2 << 8) | stack;
			a = (uint8_t)(t1 >> 8);
			b = (uint8_t)t1;
			tile_and_colour = ((uint32_t)a << 8) | b;
			tiles = test_put_tile(tiles, tile_and_colour);
			tile_and_colour = ((uint32_t)a << 8) | b;
			tiles = test_put_tile(tiles, tile_and_colour);
			tiles += 0x3Eu;
			t2 = ramp_rows_left;
			ramp_rows_left = t2 - 1u;
		} while (t2 != 1u);
		tiles -= 0x7Eu;
		stack_2 = stack_2 + 1u;
		t3 = ramp_colours_left;
		ramp_colours_left = t3 - 1u;
	} while (t3 != 1u);
	tile_and_colour = ((uint32_t)stack_2 << 8) | stack;
	*p_tiles = tiles;
	*p_tile_and_colour = tile_and_colour;
}

/* The 4 IO CHECK page, by its step */
void test_io_check_page(uint16_t setting, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, x = 0;

	x = test_io_check_page_steps_ADDRESS;
	switch ((uint16_t)(x + (int8_t)((uint32_t)test_page_step << 1)))
	{
	case test_menu_page_steps_ADDRESS:
		test_menu_open(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		test_menu_update(&ignored16, &carry);
		return;
	case test_rom_check_page_steps_ADDRESS:
		carry = test_rom_check_open(x);
		return;
	case 0x60A3u:
		test_rom_check_run(&ignored16, &carry);
		return;
	case test_screen_check_page_steps_ADDRESS:
		test_screen_check_draw(&ignored16, &carry);
		return;
	case test_color_check_page_steps_ADDRESS:
		test_color_check_draw(&ignored16, &carry);
		return;
	case test_io_check_page_steps_ADDRESS:
		test_io_check_open(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		carry = test_music_open(x);
		return;
	case 0x621Du:
		test_music_first_choice(&ignored16, &carry);
		return;
	case 0x621Fu:
		test_music_choice(&d, &carry);
		return;
	case 0x6221u:
		test_music_replay(&ignored16, &carry);
		return;
	case test_sound_page_steps_ADDRESS:
		carry = test_sound_open(x);
		return;
	case 0x6279u:
		test_sound_first_choice(&ignored16, &carry);
		return;
	case 0x627Bu:
		test_sound_choice(&d, &carry);
		return;
	case 0x627Du:
		test_sound_replay(&ignored16, &carry);
		return;
	case test_options_page_steps_ADDRESS:
		test_options_open(&ignored16, &carry);
		return;
	case test_choose_setting_steps_ADDRESS:
		test_choose_setting_open(x, setting, &d, &carry);
		return;
	case 0x642Du:
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Prints the I/O page, with the start buttons' row when the game has them */
void test_io_check_open(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint16_t d = 0, setting = 0, text_number = 0, value = 0;
	uint16_t t1 = 0, t2 = 0;

	setting = 0x5A60u;
	test_read_setting(&x, &setting, &value, &zero);
	if (zero == 0u)
	{
		text_number = (value & 0xFFu) | 0x1700u;
		carry = test_open_page(x, text_number);
		d = 0x1010u;
		io_write16(0x24E2u, 0x1010u);
		t1 = 0x24E4u;
		io_write16(t1, 0x1010u);
		t2 = t1 + 7u;
		mem_write16(t2, 0x1010u);
		mem_write16(t2 + 2u, 0x1010u);
	}
	else
	{
		d = (value & 0xFFu) | 0x400u;
		carry = test_open_page(x, d);
	}
	*p_d = d;
	*p_carry = carry;
}

/* Shows each input bit as 0 or 1 and runs the page's menu */
void test_io_check_run(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, bit = 0, bit_2 = 0, bits_left = 0, port_bits = 0, ports_left = 0;
	uint16_t d = 0, port = 0, setting = 0, tiles = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0;

	port = 0x1F90u;
	tiles = 0x22CCu;
	ports_left = 4u;
	test_coin_bits = coin_inputs;
	do
	{
		t1 = port;
		port = t1 + 1u;
		port_bits = mem_read8(t1);
		tiles += 9u;
		stack_2 = tiles >> 8;
		stack = (uint8_t)tiles;
		stack_3 = ports_left;
		bits_left = 6u;
		do
		{
			stack_4 = bits_left;
			bit = 0u;
			t2 = port_bits;
			port_bits = t2 >> 1;
			if ((t2 & 1u) == 0u)
				bit++;
			bit_2 = bit;
			tiles = test_io_check_draw_bit(tiles, bit_2);
			t3 = stack_4;
			bits_left = t3 - 1u;
		} while (t3 != 1u);
		tiles += 0x40u;
		stack_5 = port >> 8;
		stack_4 = (uint8_t)port;
		setting = 0x5A60u;
		d = (uint32_t)port_bits << 8;
		test_read_setting(&tiles, &setting, &d, &zero);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		port = ((uint32_t)stack_5 << 8) | stack_4;
		stack_4 = b;
		if (zero || (int8_t)stack_3 > 2)
		{
			bit = 0u;
			t4 = test_coin_bits;
			test_coin_bits = t4 >> 1;
			if (t4 & 1u)
				bit++;
			bit_2 = bit;
			tiles = test_io_check_draw_bit(tiles, bit_2);
		}
		else
			tiles += 0x40u;
		if (stack_4 != 0u)
		{
			bit = 0u;
			if (((a >> 1) & 1u) == 0u)
				bit++;
			bit_2 = bit;
			test_io_check_draw_bit(tiles, bit_2);
		}
		tiles = ((uint32_t)stack_2 << 8) | stack;
		t5 = stack_3;
		ports_left = t5 - 1u;
	} while (t5 != 1u);
	d = ports_left;
	*p_d = d;
	test_menu_update(p_d, &carry);
	*p_carry = carry;
}

/* Prints one input's 0 or 1 with its colour, a row down */
uint16_t test_io_check_draw_bit(uint16_t tiles, uint8_t bit)
{
	uint32_t carry = 0;
	uint8_t bit_tile = 0;
	uint8_t t1 = 0, t2 = 0;

	bit_tile = (uint8_t)bit;
	mem_write8(tiles + 0x40u, bit_tile);
	carry = 0u;
	test_io_unread_byte = 0u;
	t1 = (bit_tile >> 1) | (carry << 7);
	carry = bit_tile & 1u;
	bit_tile = t1;
	t2 = (bit_tile >> 1) | (carry << 7);
	carry = bit_tile & 1u;
	mem_write8(tiles - 0x1FC0u, (t2 >> 1) | (carry << 7));
	tiles += 0x40u;
	return tiles;
}
