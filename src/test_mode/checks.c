/**
 *    Name:        test_mode/checks.c
 *    Description: ROM, screen, colour and I/O checks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The 1 ROM CHECK page, by its step */
void test_rom_check_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_rom_check_page_steps_ADDRESS;
	switch ((uint16_t)(page_steps + (int8_t)((uint32_t)test_page_step << 1)))
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
		test_rom_check_open(page_steps);
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
		test_io_check_open(page_steps, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		test_music_open(page_steps);
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
		test_sound_open(page_steps);
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
		setting = (uint16_t)leftover_y;
		test_choose_setting_open(page_steps, setting, &d, &carry);
		return;
	case 0x642Du:
		setting = (uint16_t)leftover_y;
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(page_steps, &ignored16, &carry);
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
void test_rom_check_run(uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t line_chosen = *p_line_chosen;
	uint16_t ignored16 = 0, row = 0;

	row = 0x26DDu;
	io_write8(0x26DDu, 0x10u);
	test_unmark_row(row, &ignored16, &d);
	d = test_rom_check_step(d);
	*p_d = d;
	test_menu_update(p_d, &line_chosen);
	*p_line_chosen = line_chosen;
}

/* The 2 SCREEN CHECK page, by its step */
void test_screen_check_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_screen_check_page_steps_ADDRESS;
	switch ((uint16_t)(page_steps + (int8_t)((uint32_t)test_page_step << 1)))
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
		test_rom_check_open(page_steps);
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
		test_io_check_open(page_steps, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		test_music_open(page_steps);
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
		test_sound_open(page_steps);
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
		setting = (uint16_t)leftover_y;
		test_choose_setting_open(page_steps, setting, &d, &carry);
		return;
	case 0x642Du:
		setting = (uint16_t)leftover_y;
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(page_steps, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Fills the screen with the crosshatch tiles and prints the page */
void test_screen_check_draw(uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint32_t line_chosen = *p_line_chosen;
	uint8_t pairs_left = 0, rows_left = 0;
	uint16_t lower_tiles = 0, text_number = 0, tiles = 0, upper_tiles = 0;
	uint8_t pairs_to_go = 0, rows_to_go = 0;
	uint16_t tile_place = 0;

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
			tile_place = tiles;
			tiles = tile_place + 2u;
			mem_write16(tile_place, upper_tiles);
			pairs_to_go = pairs_left;
			pairs_left = pairs_to_go - 1u;
		} while (pairs_to_go != 1u);
		tiles += 0x58u;
		rows_to_go = rows_left;
		rows_left = rows_to_go - 1u;
	} while (rows_to_go != 1u);
	text_number = 0x200u | pairs_left;
	line_chosen = test_open_page(tiles, text_number);
	*p_d = text_number;
	*p_line_chosen = line_chosen;
}

/* The 3 COLOR CHECK page, by its step */
void test_color_check_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_color_check_page_steps_ADDRESS;
	switch ((uint16_t)(page_steps + (int8_t)((uint32_t)test_page_step << 1)))
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
		test_rom_check_open(page_steps);
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
		test_io_check_open(page_steps, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		test_music_open(page_steps);
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
		test_sound_open(page_steps);
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
		setting = (uint16_t)leftover_y;
		test_choose_setting_open(page_steps, setting, &d, &carry);
		return;
	case 0x642Du:
		setting = (uint16_t)leftover_y;
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(page_steps, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Draws the colour blocks and the four colour ramps and prints the page */
void test_color_check_draw(uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint32_t line_chosen = *p_line_chosen;
	uint8_t colour = 0, ramp_colour = 0, tile = 0;
	uint16_t ramp_tile_and_colour = 0, text_number = 0, tile_and_colour = 0, tiles = 0;
	uint8_t block_tiles_to_go = 0, block_rows_to_go = 0, blocks_to_go = 0;

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
				block_tiles_to_go = colour_block_tiles_left;
				colour_block_tiles_left = block_tiles_to_go - 1u;
			} while (block_tiles_to_go != 1u);
			tiles += 0x3Cu;
			block_rows_to_go = colour_block_rows_left;
			colour_block_rows_left = block_rows_to_go - 1u;
		} while (block_rows_to_go != 1u);
		tile++;
		tiles -= 0x17Cu;
		blocks_to_go = colour_blocks_left;
		colour_blocks_left = blocks_to_go - 1u;
	} while (blocks_to_go != 1u);
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
	ramp_tile_and_colour = 0x30C0u;
	test_color_check_draw_ramp(&tiles, &ramp_tile_and_colour);
	ramp_colour = (uint8_t)ramp_tile_and_colour;
	text_number = 0x300u | ramp_colour;
	line_chosen = test_open_page(tiles, text_number);
	*p_d = text_number;
	*p_line_chosen = line_chosen;
}

/* Draws one ramp of 16 colours, two tiles by two each */
void test_color_check_draw_ramp(uint16_t *p_tiles, uint16_t *p_tile_and_colour)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t tile_and_colour = (uint16_t)*p_tile_and_colour;
	uint8_t ramp_colour = 0, ramp_tile = 0;
	uint8_t kept_colour = 0, step_tile = 0;
	uint8_t rows_to_go = 0, colours_to_go = 0;
	uint16_t ramp_step = 0;

	kept_colour = (uint8_t)tile_and_colour;
	step_tile = tile_and_colour >> 8;
	ramp_colours_left = 0x10u;
	do
	{
		ramp_rows_left = 2u;
		do
		{
			ramp_step = ((uint32_t)step_tile << 8) | kept_colour;
			ramp_tile = (uint8_t)(ramp_step >> 8);
			ramp_colour = (uint8_t)ramp_step;
			tile_and_colour = ((uint32_t)ramp_tile << 8) | ramp_colour;
			tiles = test_put_tile(tiles, tile_and_colour);
			tile_and_colour = ((uint32_t)ramp_tile << 8) | ramp_colour;
			tiles = test_put_tile(tiles, tile_and_colour);
			tiles += 0x3Eu;
			rows_to_go = ramp_rows_left;
			ramp_rows_left = rows_to_go - 1u;
		} while (rows_to_go != 1u);
		tiles -= 0x7Eu;
		step_tile = step_tile + 1u;
		colours_to_go = ramp_colours_left;
		ramp_colours_left = colours_to_go - 1u;
	} while (colours_to_go != 1u);
	tile_and_colour = ((uint32_t)step_tile << 8) | kept_colour;
	*p_tiles = tiles;
	*p_tile_and_colour = tile_and_colour;
}

/* The 4 IO CHECK page, by its step */
void test_io_check_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_io_check_page_steps_ADDRESS;
	switch ((uint16_t)(page_steps + (int8_t)((uint32_t)test_page_step << 1)))
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
		test_rom_check_open(page_steps);
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
		test_io_check_open(page_steps, &ignored16, &carry);
		return;
	case 0x617Fu:
		test_io_check_run(&ignored16, &carry);
		return;
	case test_music_page_steps_ADDRESS:
		test_music_open(page_steps);
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
		test_sound_open(page_steps);
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
		setting = (uint16_t)leftover_y;
		test_choose_setting_open(page_steps, setting, &d, &carry);
		return;
	case 0x642Du:
		setting = (uint16_t)leftover_y;
		test_choose_setting_run(setting, &d, &carry);
		return;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(page_steps, &ignored16, &carry);
		return;
	case 0x646Fu:
		test_factory_setting_wait(&ignored16, &carry);
		return;
	}
}

/* Prints the I/O page, with the start buttons' row when the game has them */
void test_io_check_open(uint16_t x, uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint32_t line_chosen = *p_line_chosen;
	uint32_t setting_off = 0;
	uint16_t d = 0, setting = 0, text_number = 0, value = 0;
	uint16_t second_pair_place = 0, third_pair_place = 0;

	setting = 0x5A60u;
	test_read_setting(&x, &setting, &value, &setting_off);
	if (setting_off == 0u)
	{
		text_number = (value & 0xFFu) | 0x1700u;
		line_chosen = test_open_page(x, text_number);
		d = 0x1010u;
		io_write16(0x24E2u, 0x1010u);
		second_pair_place = 0x24E4u;
		io_write16(second_pair_place, 0x1010u);
		third_pair_place = second_pair_place + 7u;
		mem_write16(third_pair_place, 0x1010u);
		mem_write16(third_pair_place + 2u, 0x1010u);
	}
	else
	{
		d = (value & 0xFFu) | 0x400u;
		line_chosen = test_open_page(x, d);
	}
	*p_d = d;
	*p_line_chosen = line_chosen;
}

/* Shows each input bit as 0 or 1 and runs the page's menu */
void test_io_check_run(uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint32_t line_chosen = *p_line_chosen;
	uint32_t setting_off = 0;
	uint8_t bit = 0, bit_2 = 0, bits_left = 0, port_bits = 0, port_bits_left = 0, ports_left = 0, start_buttons_setting = 0;
	uint16_t d = 0, port = 0, setting = 0, tiles = 0;
	uint8_t row_place_low = 0, row_place_high = 0, ports_remaining = 0, kept_byte = 0, saved_port_high = 0;
	uint8_t bits_before_shift = 0, bits_to_go = 0, coin_bits_before_shift = 0, ports_to_go = 0;
	uint16_t port_place = 0;

	port = player_1_input_port;
	tiles = 0x22CCu;
	ports_left = 4u;
	test_coin_bits = coin_inputs;
	do
	{
		port_place = port;
		port = port_place + 1u;
		port_bits = mem_read8(port_place);
		tiles += 9u;
		row_place_high = tiles >> 8;
		row_place_low = (uint8_t)tiles;
		ports_remaining = ports_left;
		bits_left = 6u;
		do
		{
			kept_byte = bits_left;
			bit = 0u;
			bits_before_shift = port_bits;
			port_bits = bits_before_shift >> 1;
			if ((bits_before_shift & 1u) == 0u)
				bit++;
			bit_2 = bit;
			tiles = test_io_check_draw_bit(tiles, bit_2);
			bits_to_go = kept_byte;
			bits_left = bits_to_go - 1u;
		} while (bits_to_go != 1u);
		tiles += 0x40u;
		saved_port_high = port >> 8;
		kept_byte = (uint8_t)port;
		setting = 0x5A60u;
		d = (uint32_t)port_bits << 8;
		test_read_setting(&tiles, &setting, &d, &setting_off);
		port_bits_left = (uint8_t)(d >> 8);
		start_buttons_setting = (uint8_t)d;
		port = ((uint32_t)saved_port_high << 8) | kept_byte;
		kept_byte = start_buttons_setting;
		if (setting_off || (int8_t)ports_remaining > 2)
		{
			bit = 0u;
			coin_bits_before_shift = test_coin_bits;
			test_coin_bits = coin_bits_before_shift >> 1;
			if (coin_bits_before_shift & 1u)
				bit++;
			bit_2 = bit;
			tiles = test_io_check_draw_bit(tiles, bit_2);
		}
		else
			tiles += 0x40u;
		if (kept_byte != 0u)
		{
			bit = 0u;
			if (((port_bits_left >> 1) & 1u) == 0u)
				bit++;
			bit_2 = bit;
			test_io_check_draw_bit(tiles, bit_2);
		}
		tiles = ((uint32_t)row_place_high << 8) | row_place_low;
		ports_to_go = ports_remaining;
		ports_left = ports_to_go - 1u;
	} while (ports_to_go != 1u);
	d = ports_left;
	*p_d = d;
	test_menu_update(p_d, &line_chosen);
	*p_line_chosen = line_chosen;
}

/* Prints one input's 0 or 1 with its colour, a row down */
uint16_t test_io_check_draw_bit(uint16_t tiles, uint8_t bit)
{
	uint32_t carry = 0;
	uint8_t bit_tile = 0;
	uint8_t rotated_once = 0, rotated_twice = 0;

	bit_tile = (uint8_t)bit;
	mem_write8(tiles + 0x40u, bit_tile);
	carry = 0u;
	test_io_unread_byte = 0u;
	rotated_once = (bit_tile >> 1) | (carry << 7);
	carry = bit_tile & 1u;
	bit_tile = rotated_once;
	rotated_twice = (bit_tile >> 1) | (carry << 7);
	carry = bit_tile & 1u;
	mem_write8(tiles - 0x1FC0u, (rotated_twice >> 1) | (carry << 7));
	tiles += 0x40u;
	return tiles;
}
