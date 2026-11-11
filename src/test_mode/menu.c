/**
 *    Name:        test_mode/menu.c
 *    Description: the test mode's page runner
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the test mode's page with the FIRQ and the K052109's IRQ off */
void test_run_page(uint8_t d)
{
	uint16_t pages = 0;

	disable_irq();
	io_write8(tile_chip_irq_control, 0xFBu);
	pages = test_pages_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)test_page << 1))
	{
	case 0:
		test_menu_page(d);
		break;
	case 2:
		test_rom_check_page(d);
		break;
	case 4:
		test_screen_check_page(d);
		break;
	case 6:
		test_color_check_page(d);
		break;
	case 8:
		test_io_check_page(d);
		break;
	case 10:
		test_music_page(d);
		break;
	case 12:
		test_sound_page(d);
		break;
	case 14:
		test_start_buttons_page();
		break;
	case 16:
		test_options_page(d);
		break;
	case 18:
		test_exit();
		break;
	case 20:
		test_coin_setting_page(pages);
		break;
	case 22:
	case 24:
		test_players_page();
		break;
	case 26:
		test_difficulty_page();
		break;
	case 28:
		test_attract_sound_page();
		break;
	case 30:
		test_screen_flip_page();
		break;
	case 32:
		test_sound_output_page();
		break;
	case 34:
		test_factory_setting_page(d);
		break;
	case 36:
		test_premium_start_page();
		break;
	case 38:
		test_coinage_page();
		break;
	case 40:
		test_premium_coins_page();
		break;
	case 42:
		test_premium_coinage_page();
		break;
	case 44:
		test_back_to_menu();
		break;
	}
	enable_irq();
	take_interrupts();
	io_write8(tile_chip_irq_control, 0xFFu);
}

/* The MANUAL TEST MENU page, by its step */
void test_menu_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_menu_page_steps_ADDRESS;
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

/* Loads the test mode's palettes and prints the main menu and the start buttons' setting */
void test_menu_open(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t colour = 0, control = 0, menu_text_number = 0, palettes_left = 0, print_colour = 0, start_buttons = 0;
	uint16_t colour_place = 0, count = 0, d = 0, ignored16 = 0, ignored16_2 = 0, palette_data = 0, setting = 0, start_buttons_word = 0, text = 0, text_number = 0, tiles = 0, x = 0;
	uint8_t palettes_to_go = 0;
	uint16_t palette_record = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	palettes_left = 8u;
	palette_data = test_mode_palettes_ADDRESS;
	do
	{
		palette_record = palette_data;
		palette_data = palette_record + 2u;
		colour_place = mem_read16(palette_record);
		count = 0x20u;
		while (count != 0u)
		{
			mem_write8(colour_place, mem_read8(palette_data));
			palette_data++;
			colour_place++;
			count--;
		}
		palettes_to_go = palettes_left;
		palettes_left = palettes_to_go - 1u;
	} while (palettes_to_go != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	test_silence();
	vector_clear_text_layer(&x, &ignored16);
	menu_text_number = 0u;
	text_number = 0u;
	test_open_page(x, text_number);
	setting = 0x5A60u;
	start_buttons_word = (uint32_t)menu_text_number << 8;
	test_read_setting(&ignored16_2, &setting, &start_buttons_word, &zero);
	menu_text_number = (uint8_t)(start_buttons_word >> 8);
	start_buttons = (uint8_t)start_buttons_word;
	tiles = 0x255Bu;
	text = test_text_without_ADDRESS;
	if (start_buttons != 0u)
		text = test_text_with_ADDRESS;
	print_colour = 0u;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	d = ((uint32_t)menu_text_number << 8) | print_colour;
	*p_d = d;
	*p_carry = carry;
}

/* Moves the cursor with the 1P joystick, and on SHOOT1 goes to the line's page or hands back its line */
void test_menu_update(uint16_t *p_d, uint32_t *p_line_chosen)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t line_chosen = *p_line_chosen;
	uint8_t b = 0, cursor = 0, joystick = 0, old_cursor = 0, page = 0, repeat_delay = 0;
	uint16_t cursor_place = 0, cursor_variable = 0, d_2 = 0, ignored16 = 0, menu_lines = 0;
	uint8_t cursor_high = 0, cursor_low = 0;
	uint16_t chosen_line = 0;
	uint8_t player_1_port = 0, up_down_bits = 0, moved_cursor = 0;
	uint16_t cursor_word = 0;

	b = (uint8_t)d;
	cursor_variable = test_menu_cursor_variable_ADDRESS;
	menu_lines = test_menu_lines_ADDRESS;
	player_1_port = io_read8(player_1_input_port);
	up_down_bits = player_1_port & 0xCu;
	joystick = up_down_bits;
	if (up_down_bits == 0u)
	{
		repeat_delay = 0u;
		test_cursor_repeat = repeat_delay;
	}
	else if (test_cursor_repeat != 0u)
		test_cursor_repeat--;
	else
	{
		old_cursor = mem_read8(test_menu_cursor_variable);
		moved_cursor = test_menu_cursor_steps[(joystick >> 1) >> 1] + mem_read8(test_menu_cursor_variable);
		cursor = moved_cursor;
		if ((int8_t)moved_cursor < 0)
			cursor = test_menu_length - 3u;
		if ((int8_t)test_menu_length <= (int8_t)cursor)
			cursor = 0u;
		mem_write8(test_menu_cursor_variable, cursor);
		cursor_place = mem_read16(test_menu_lines + old_cursor);
		mem_write8(cursor_place, 0x10u);
		d_2 = 0x10u;
		test_unmark_row(cursor_place, &menu_lines, &d_2);
		b = (uint8_t)d_2;
		repeat_delay = 7u;
		test_cursor_repeat = 7u;
		test_cursor_repeat = repeat_delay;
	}
	cursor_place = mem_read16(mem_read16(menu_lines) + (int8_t)mem_read8(test_menu_cursor_variable));
	mem_write8(cursor_place, 0xA0u);
	d_2 = 0x4000u | b;
	test_colour_row(&cursor_place, &menu_lines, &d_2);
	b = (uint8_t)d_2;
	if ((player_controls(2) & 0x10u) == 0u)
	{
		line_chosen = 0u;
		d_2 = b;
	}
	else
	{
		mem_write8(cursor_place, 0x10u);
		page = mem_read8(mem_read16(menu_lines) + (int8_t)(mem_read8(test_menu_cursor_variable) + 2u));
		if (page == 0x20u)
		{
			cursor_word = (int8_t)mem_read8(test_menu_cursor_variable);
			cursor_high = cursor_word >> 8;
			cursor_low = cursor_word;
			chosen_line = konami_divx((uint16_t)(((uint32_t)cursor_high << 8) | cursor_low), 3u);
			line_chosen = 1u;
			d_2 = ((uint32_t)(uint8_t)~(chosen_line >> 8) << 8) | (uint8_t)chosen_line;
		}
		else
		{
			test_page = page;
			test_page_step = 0u;
			test_silence();
			vector_clear_layer_a();
			vector_clear_layer_b();
			vector_clear_text_layer(&ignored16, &d_2);
			b = (uint8_t)d_2;
			test_cursor = 0u;
			line_chosen = 0u;
			d_2 = b;
		}
	}
	*p_d = d_2;
	*p_line_chosen = line_chosen;
}

/* Colours menu line B's row with A */
uint16_t test_mark_line(uint16_t colour_and_line)
{
	uint8_t line_offset = 0;
	uint16_t colour = 0, ignored16 = 0, row = 0;
	uint8_t saved_colour = 0;

	saved_colour = colour_and_line >> 8;
	line_offset = 3u * (colour_and_line + 1u);
	row = mem_read16(test_menu_lines + (int8_t)line_offset);
	colour = (uint32_t)saved_colour << 8;
	test_colour_row(&row, &ignored16, &colour);
	return row;
}

/* Clears the colour of the row at X */
void test_unmark_row(uint16_t row, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;

	*p_u = u;
	*p_d = d;
	test_colour_row(&row, p_u, p_d);
}

/* Colours the row at X with A */
void test_colour_row(uint16_t *p_row, uint16_t *p_u, uint16_t *p_colour)
{
	uint16_t row = (uint16_t)*p_row;
	uint16_t u = (uint16_t)*p_u;
	uint16_t colour = (uint16_t)*p_colour;
	uint8_t colour_byte = 0, page = 0;
	uint16_t colour_place = 0, count = 0, u_2 = 0;
	uint8_t saved_u_low = 0, saved_u_high = 0, row_low = 0, row_high = 0, saved_colour_low = 0, row_colour = 0, colour_place_low = 0, colour_place_high = 0;
	uint16_t saved_row = 0, row_colours = 0;

	saved_u_high = u >> 8;
	saved_u_low = (uint8_t)u;
	row_high = row >> 8;
	row_low = (uint8_t)row;
	saved_colour_low = (uint8_t)colour;
	row_colour = colour >> 8;
	saved_row = ((uint32_t)row_high << 8) | row_low;
	row_colours = saved_row - 0x2000u;
	colour_place_low = (row_colours & 0xC0u) + 0xFu;
	colour_place_high = row_colours >> 8;
	colour_place = ((uint32_t)colour_place_high << 8) | colour_place_low;
	page = test_page;
	if (page == 0x15u)
		colour_place += 0x11u;
	colour_byte = row_colour;
	count = 0x24u;
	if ((int8_t)page >= 0x14)
		count = 0x12u;
	while (count != 0u)
	{
		mem_write8(colour_place, colour_byte);
		colour_place++;
		count--;
	}
	row = ((uint32_t)row_high << 8) | row_low;
	u_2 = ((uint32_t)saved_u_high << 8) | saved_u_low;
	colour = ((uint32_t)row_colour << 8) | saved_colour_low;
	*p_row = row;
	*p_u = u_2;
	*p_colour = colour;
}

/* Writes setting Y (5A58-5A67 stand for EEPROM 68-77) and the EEPROM's sum; else the variable */
uint16_t test_write_setting(uint16_t setting, uint8_t value)
{
	uint16_t cell = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t saved_setting_low = 0, saved_setting_high = 0, eeprom_cell = 0;

	if ((int16_t)setting < 0x5A58 || setting > 0x5A67u)
	{
		mem_write8(setting, value);
		return setting;
	}
	saved_setting_high = setting >> 8;
	saved_setting_low = (uint8_t)setting;
	eeprom_cell = setting - 0x59F0u;
	cell = (value & 0xFFu) | ((uint32_t)eeprom_cell << 8);
	eeprom_write(cell);
	eeprom_write_sum(&ignored16, &ignored16_2);
	setting = ((uint32_t)saved_setting_high << 8) | saved_setting_low;
	return setting;
}

/* Reads setting Y from the EEPROM (5A58-5A67), else the variable, into B */
void test_read_setting(uint16_t *p_x, uint16_t *p_setting, uint16_t *p_value, uint32_t *p_setting_off)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t setting = (uint16_t)*p_setting;
	uint16_t value = (uint16_t)*p_value;
	uint32_t setting_off = *p_setting_off;
	uint8_t value_byte = 0, value_high = 0;
	uint16_t eeprom_word = 0;
	uint8_t saved_setting_low = 0, saved_setting_high = 0, saved_tiles_low = 0, saved_tiles_high = 0, saved_value_high = 0, eeprom_cell = 0;
	uint8_t setting_byte = 0;

	value_high = (uint8_t)(value >> 8);
	if ((int16_t)setting < 0x5A58 || setting > 0x5A67u)
	{
		setting_byte = mem_read8(setting);
		setting_off = setting_byte == 0u;
		value = ((uint32_t)value_high << 8) | setting_byte;
	}
	else
	{
		saved_setting_high = setting >> 8;
		saved_setting_low = (uint8_t)setting;
		saved_tiles_high = x >> 8;
		saved_tiles_low = (uint8_t)x;
		saved_value_high = value_high;
		eeprom_cell = setting - 0x59F0u;
		eeprom_word = (value & 0xFFu) | ((uint32_t)eeprom_cell << 8);
		eeprom_word = eeprom_read(eeprom_word);
		value_byte = (uint8_t)eeprom_word;
		setting_off = value_byte == 0u;
		x = ((uint32_t)saved_tiles_high << 8) | saved_tiles_low;
		setting = ((uint32_t)saved_setting_high << 8) | saved_setting_low;
		value = ((uint32_t)saved_value_high << 8) | value_byte;
	}
	*p_x = x;
	*p_setting = setting;
	*p_value = value;
	*p_setting_off = setting_off;
}

/* Prints test_mode_texts[A] and takes its menu: its length, cursor variable and lines */
uint32_t test_open_page(uint16_t tiles, uint16_t text_number)
{
	uint32_t line_chosen = 0;
	uint8_t colour = 0;
	uint16_t text = 0;
	uint16_t page_menu = 0, cursor_variable_place = 0, cursor_variable_address = 0;

	text = test_mode_texts[(int8_t)((uint8_t)((uint32_t)(text_number >> 8) << 1)) / 2];
	colour = 0u;
	test_print(colour, &tiles, &text, &line_chosen);
	page_menu = text;
	test_menu_length = mem_read8(page_menu);
	cursor_variable_place = page_menu + 1u;
	cursor_variable_address = mem_read16(cursor_variable_place);
	test_menu_cursor_variable = cursor_variable_address;
	line_chosen = 0u;
	test_check_cursor = 0u;
	test_menu_lines = cursor_variable_place + 2u;
	test_page_step++;
	return line_chosen;
}

/* The test mode's printer: letters, places, new lines, hex bytes and words, up to C0 */
void test_print(uint16_t colour, uint16_t *p_tiles, uint16_t *p_text, uint32_t *p_carry)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t text = (uint16_t)*p_text;
	uint32_t carry = *p_carry;
	bool L_05E69F = false, L_05E6A6 = false, L_05E6AE = false, L_05E6C1 = false;
	uint8_t character = 0, colour_byte = 0, command = 0, tile = 0;
	uint8_t new_place_high = 0, new_place_low = 0, saved_word_number = 0, saved_colour = 0;
	uint16_t line_start = 0, saved_text = 0;
	uint8_t printed_character = 0, command_character = 0;
	uint16_t text_place = 0, variable_address_place = 0, place_row_offset = 0, column_place = 0, new_tiles = 0;

	for (;;)
	{
		colour_byte = (uint8_t)colour;
		line_start = tiles;
		test_print_down = 0u;
		for (;;)
		{
			text_place = text;
			text = text_place + 1u;
			character = mem_read8(text_place);
			if (character < 0xC0u)
			{
				printed_character = character;
				tile = printed_character - 0x30u;
				if (printed_character < 0x30u)
					break;
				colour = ((uint32_t)tile << 8) | colour_byte;
				tiles = test_put_tile(tiles, colour);
				if (test_print_down == 0u)
					continue;
				tiles += 0x3Fu;
				continue;
			}
			command_character = character;
			command = command_character + 0x39u;
			if (command_character < 0xC7u)
			{
				command += 7u;
				carry = (int8_t)command < 0;
				switch ((int8_t)(uint8_t)((uint32_t)command << 1))
				{
				case 0:
					*p_tiles = tiles;
					*p_text = text;
					*p_carry = carry;
					return;
				case 2:
					L_05E69F = true;
					break;
				case 4:
					L_05E6A6 = true;
					break;
				case 6:
					L_05E6AE = true;
					break;
				case 8:
					L_05E6C1 = true;
					break;
				case 10:
					variable_address_place = text;
					text = variable_address_place + 2u;
					colour = ((uint32_t)mem_read8(mem_read16(variable_address_place)) << 8) | colour_byte;
					test_print_hex(&tiles, &colour);
					colour_byte = (uint8_t)colour;
					continue;
				case 12:
					test_print_down++;
					continue;
				}
			}
			if (L_05E69F)
				break;
			if (L_05E6A6)
				break;
			if (L_05E6AE)
				break;
			if (L_05E6C1)
				break;
			saved_text = text;
			saved_word_number = command;
			saved_colour = colour_byte;
			text = test_mode_words[(int8_t)((uint8_t)((uint32_t)command << 1)) / 2];
			colour = colour_byte;
			test_print(colour, &tiles, &text, &carry);
			colour_byte = saved_colour;
			text = saved_text;
			if (saved_word_number == 0u)
			{
				*p_tiles = tiles;
				*p_text = text;
				*p_carry = carry;
				return;
			}
		}
		if (L_05E69F || L_05E6A6 || L_05E6AE || !L_05E6C1)
		{
			if (L_05E69F || L_05E6A6 || !L_05E6AE)
			{
				if (L_05E69F || !L_05E6A6)
				{
					if (!L_05E69F)
					{
						place_row_offset = (uint32_t)(uint8_t)(tile + 0x30u) << 6;
						column_place = text;
						text = column_place + 1u;
						new_tiles = (((uint32_t)(place_row_offset >> 8) << 8) | (uint8_t)(place_row_offset + mem_read8(column_place))) + 0x208Cu;
						new_place_high = new_tiles >> 8;
						new_place_low = new_tiles;
						tiles = ((uint32_t)new_place_high << 8) | new_place_low;
						continue;
					}
					L_05E69F = false;
					tiles = line_start + 0x40u;
					continue;
				}
				L_05E6A6 = false;
				tiles = line_start + 0x80u;
				continue;
			}
			L_05E6AE = false;
			tiles = line_start;
			if (test_print_down != 0u)
			{
				tiles += 3u;
				continue;
			}
			tiles += 0xC0u;
			continue;
		}
		L_05E6C1 = false;
		tiles = line_start;
		if (test_print_down != 0u)
		{
			tiles += 4u;
			continue;
		}
		tiles += 0x100u;
	}
}

/* Puts tile A with colour B at X and steps X */
uint16_t test_put_tile(uint16_t tiles, uint16_t tile_and_colour)
{
	uint16_t tile_place = 0;

	io_write8(tiles - 0x2000u, (uint8_t)tile_and_colour);
	tile_place = tiles;
	tiles = tile_place + 1u;
	io_write8(tile_place, tile_and_colour >> 8);
	return tiles;
}

/* Unused: prints a word as four hex digits. */
void unused_test_print_hex_word(uint16_t tiles, uint16_t printed_word)
{
	uint16_t value = 0;
	uint8_t word_low_byte = 0, word_high_byte = 0;

	word_high_byte = printed_word >> 8;
	word_low_byte = (uint8_t)printed_word;
	value = (uint32_t)word_high_byte << 8;
	test_print_hex(&tiles, &value);
	value = (uint32_t)word_low_byte << 8;
	test_print_hex(&tiles, &value);
}

/* Prints A as two hex digits at X */
void test_print_hex(uint16_t *p_tiles, uint16_t *p_value)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t value = (uint16_t)*p_value;
	uint8_t printed_byte = 0;
	uint8_t saved_colour = 0, kept_printed_byte = 0;
	uint16_t high_digit_place = 0, low_digit_place = 0;

	printed_byte = (uint8_t)(value >> 8);
	saved_colour = (uint8_t)value;
	kept_printed_byte = printed_byte;
	high_digit_place = tiles;
	mem_write8(high_digit_place, test_mode_hex_digit_tiles[(((printed_byte >> 1) >> 1) >> 1) >> 1]);
	low_digit_place = high_digit_place + 1u;
	tiles = low_digit_place + 1u;
	mem_write8(low_digit_place, test_mode_hex_digit_tiles[kept_printed_byte & 0xFu]);
	value = ((uint32_t)kept_printed_byte << 8) | saved_colour;
	*p_tiles = tiles;
	*p_value = value;
}

/* Queues sound command 0000 (all sounds off) */
uint16_t test_silence(void)
{
	uint16_t command = 0;

	command = 0u;
	vector_queue_sound(command);
	return command;
}
