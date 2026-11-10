/**
 *    Name:        test_mode/menu.c
 *    Description: the test mode's page runner
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the test mode's page with the FIRQ and the K052109's IRQ off */
void test_run_page(uint16_t y, uint8_t d)
{
	uint16_t x = 0;

	disable_irq();
	io_write8(0x1D00u, 0xFBu);
	x = test_pages_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)test_page << 1))
	{
	case 0:
		test_menu_page(y, d);
		break;
	case 2:
		test_rom_check_page(y, d);
		break;
	case 4:
		test_screen_check_page(y, d);
		break;
	case 6:
		test_color_check_page(y, d);
		break;
	case 8:
		test_io_check_page(y, d);
		break;
	case 10:
		test_music_page(y, d);
		break;
	case 12:
		test_sound_page(y, d);
		break;
	case 14:
		test_start_buttons_page();
		break;
	case 16:
		test_options_page(y, d);
		break;
	case 18:
		test_exit();
		break;
	case 20:
		test_coin_setting_page(x);
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
		test_factory_setting_page(y, d);
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
	io_write8(0x1D00u, 0xFFu);
}

/* The MANUAL TEST MENU page, by its step */
void test_menu_page(uint16_t setting, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, x = 0;

	x = test_menu_page_steps_ADDRESS;
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

/* Loads the test mode's palettes and prints the main menu and the start buttons' setting */
void test_menu_open(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, colour = 0, control = 0, palettes_left = 0, start_buttons = 0;
	uint16_t colour_place = 0, count = 0, d = 0, ignored16 = 0, ignored16_2 = 0, palette_data = 0, setting = 0, text = 0, text_number = 0, tiles = 0, x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(0x1FC2u, control);
	palettes_left = 8u;
	palette_data = test_mode_palettes_ADDRESS;
	do
	{
		t1 = palette_data;
		palette_data = t1 + 2u;
		colour_place = mem_read16(t1);
		count = 0x20u;
		while (count != 0u)
		{
			mem_write8(colour_place, mem_read8(palette_data));
			palette_data++;
			colour_place++;
			count--;
		}
		t2 = palettes_left;
		palettes_left = t2 - 1u;
	} while (t2 != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	test_silence();
	vector_clear_text_layer(&x, &ignored16);
	a = 0u;
	text_number = 0u;
	carry = test_open_page(x, text_number);
	setting = 0x5A60u;
	d = (uint32_t)a << 8;
	test_read_setting(&ignored16_2, &setting, &d, &zero);
	a = (uint8_t)(d >> 8);
	start_buttons = (uint8_t)d;
	tiles = 0x255Bu;
	text = test_text_without_ADDRESS;
	if (start_buttons != 0u)
		text = test_text_with_ADDRESS;
	b = 0u;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	d = ((uint32_t)a << 8) | b;
	*p_d = d;
	*p_carry = carry;
}

/* Moves the cursor with the 1P joystick, and on SHOOT1 goes to the line's page or hands back its line */
void test_menu_update(uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0, cursor = 0, joystick = 0, old_cursor = 0, page = 0;
	uint16_t cursor_place = 0, cursor_variable = 0, d_2 = 0, ignored16 = 0, menu_lines = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	b = (uint8_t)d;
	cursor_variable = test_menu_cursor_variable_ADDRESS;
	menu_lines = test_menu_lines_ADDRESS;
	t1 = io_read8(0x1F90u);
	t2 = t1 & 0xCu;
	joystick = t2;
	if (t2 == 0u)
	{
		a = 0u;
		test_cursor_repeat = a;
	}
	else if (test_cursor_repeat != 0u)
		test_cursor_repeat--;
	else
	{
		old_cursor = mem_read8(test_menu_cursor_variable);
		t3 = test_menu_cursor_steps[(joystick >> 1) >> 1] + mem_read8(test_menu_cursor_variable);
		cursor = t3;
		if ((int8_t)t3 < 0)
			cursor = test_menu_length - 3u;
		if ((int8_t)test_menu_length <= (int8_t)cursor)
			cursor = 0u;
		mem_write8(test_menu_cursor_variable, cursor);
		cursor_place = mem_read16(test_menu_lines + old_cursor);
		mem_write8(cursor_place, 0x10u);
		d_2 = 0x10u;
		test_unmark_row(cursor_place, &menu_lines, &d_2);
		b = (uint8_t)d_2;
		a = 7u;
		test_cursor_repeat = 7u;
		test_cursor_repeat = a;
	}
	cursor_place = mem_read16(mem_read16(menu_lines) + (int8_t)mem_read8(test_menu_cursor_variable));
	mem_write8(cursor_place, 0xA0u);
	d_2 = 0x4000u | b;
	test_colour_row(&cursor_place, &menu_lines, &d_2);
	b = (uint8_t)d_2;
	if ((player_controls(2) & 0x10u) == 0u)
	{
		carry = 0u;
		d_2 = b;
	}
	else
	{
		mem_write8(cursor_place, 0x10u);
		page = mem_read8(mem_read16(menu_lines) + (int8_t)(mem_read8(test_menu_cursor_variable) + 2u));
		if (page == 0x20u)
		{
			t4 = (int8_t)mem_read8(test_menu_cursor_variable);
			stack_10001 = t4 >> 8;
			stack_10002 = t4;
			stack = konami_divx((uint16_t)(((uint32_t)stack_10001 << 8) | stack_10002), 3u);
			carry = 1u;
			d_2 = ((uint32_t)(uint8_t)~(stack >> 8) << 8) | (uint8_t)stack;
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
			carry = 0u;
			d_2 = b;
		}
	}
	*p_d = d_2;
	*p_carry = carry;
}

/* Colours menu line B's row with A */
uint16_t test_mark_line(uint16_t colour_and_line)
{
	uint8_t line_offset = 0;
	uint16_t colour = 0, ignored16 = 0, row = 0;
	uint8_t stack = 0;

	stack = colour_and_line >> 8;
	line_offset = 3u * (colour_and_line + 1u);
	row = mem_read16(test_menu_lines + (int8_t)line_offset);
	colour = (uint32_t)stack << 8;
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
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0, stack_7 = 0, stack_8 = 0;
	uint16_t t1 = 0, t2 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	stack_4 = row >> 8;
	stack_3 = (uint8_t)row;
	stack_5 = (uint8_t)colour;
	stack_6 = colour >> 8;
	t1 = ((uint32_t)stack_4 << 8) | stack_3;
	t2 = t1 - 0x2000u;
	stack_7 = (t2 & 0xC0u) + 0xFu;
	stack_8 = t2 >> 8;
	colour_place = ((uint32_t)stack_8 << 8) | stack_7;
	page = test_page;
	if (page == 0x15u)
		colour_place += 0x11u;
	colour_byte = stack_6;
	count = 0x24u;
	if ((int8_t)page >= 0x14)
		count = 0x12u;
	while (count != 0u)
	{
		mem_write8(colour_place, colour_byte);
		colour_place++;
		count--;
	}
	row = ((uint32_t)stack_4 << 8) | stack_3;
	u_2 = ((uint32_t)stack_2 << 8) | stack;
	colour = ((uint32_t)stack_6 << 8) | stack_5;
	*p_row = row;
	*p_u = u_2;
	*p_colour = colour;
}

/* Writes setting Y (5A58-5A67 stand for EEPROM 68-77) and the EEPROM's sum; else the variable */
uint16_t test_write_setting(uint16_t setting, uint8_t value)
{
	uint16_t cell = 0, ignored16 = 0, ignored16_2 = 0;
	uint8_t stack = 0, stack_4 = 0, stack_8 = 0;

	if ((int16_t)setting < 0x5A58 || setting > 0x5A67u)
	{
		mem_write8(setting, value);
		return setting;
	}
	stack_4 = setting >> 8;
	stack = (uint8_t)setting;
	stack_8 = setting - 0x59F0u;
	cell = (value & 0xFFu) | ((uint32_t)stack_8 << 8);
	eeprom_write(cell);
	eeprom_write_sum(&ignored16, &ignored16_2);
	setting = ((uint32_t)stack_4 << 8) | stack;
	return setting;
}

/* Reads setting Y from the EEPROM (5A58-5A67), else the variable, into B */
void test_read_setting(uint16_t *p_x, uint16_t *p_setting, uint16_t *p_value, uint32_t *p_zero)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t setting = (uint16_t)*p_setting;
	uint16_t value = (uint16_t)*p_value;
	uint32_t zero = *p_zero;
	uint8_t a = 0, value_byte = 0;
	uint16_t d = 0;
	uint8_t stack = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0, stack_7 = 0, stack_8 = 0;
	uint8_t t1 = 0;

	a = (uint8_t)(value >> 8);
	if ((int16_t)setting < 0x5A58 || setting > 0x5A67u)
	{
		t1 = mem_read8(setting);
		zero = t1 == 0u;
		value = ((uint32_t)a << 8) | t1;
	}
	else
	{
		stack_4 = setting >> 8;
		stack = (uint8_t)setting;
		stack_6 = x >> 8;
		stack_5 = (uint8_t)x;
		stack_7 = a;
		stack_8 = setting - 0x59F0u;
		d = (value & 0xFFu) | ((uint32_t)stack_8 << 8);
		d = eeprom_read(d);
		value_byte = (uint8_t)d;
		zero = value_byte == 0u;
		x = ((uint32_t)stack_6 << 8) | stack_5;
		setting = ((uint32_t)stack_4 << 8) | stack;
		value = ((uint32_t)stack_7 << 8) | value_byte;
	}
	*p_x = x;
	*p_setting = setting;
	*p_value = value;
	*p_zero = zero;
}

/* Prints test_mode_texts[A] and takes its menu: its length, cursor variable and lines */
uint32_t test_open_page(uint16_t tiles, uint16_t text_number)
{
	uint32_t carry = 0;
	uint8_t colour = 0;
	uint16_t text = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	text = test_mode_texts[(int8_t)((uint8_t)((uint32_t)(text_number >> 8) << 1)) / 2];
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	t1 = text;
	test_menu_length = mem_read8(t1);
	t2 = t1 + 1u;
	t3 = mem_read16(t2);
	test_menu_cursor_variable = t3;
	carry = 0u;
	test_check_cursor = 0u;
	test_menu_lines = t2 + 2u;
	test_page_step++;
	return carry;
}

/* The test mode's printer: letters, places, new lines, hex bytes and words, up to C0 */
void test_print(uint16_t colour, uint16_t *p_tiles, uint16_t *p_text, uint32_t *p_carry)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t text = (uint16_t)*p_text;
	uint32_t carry = *p_carry;
	bool L_05E69F = false, L_05E6A6 = false, L_05E6AE = false, L_05E6C1 = false;
	uint8_t character = 0, colour_byte = 0, command = 0, tile = 0;
	uint8_t stack_10005 = 0, stack_10006 = 0, stack_10007 = 0, stack_10008 = 0;
	uint16_t stack = 0, stack_6 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	for (;;)
	{
		colour_byte = (uint8_t)colour;
		stack = tiles;
		test_print_down = 0u;
		for (;;)
		{
			t1 = text;
			text = t1 + 1u;
			character = mem_read8(t1);
			if (character < 0xC0u)
			{
				t2 = character;
				tile = t2 - 0x30u;
				if (t2 < 0x30u)
					break;
				colour = ((uint32_t)tile << 8) | colour_byte;
				tiles = test_put_tile(tiles, colour);
				if (test_print_down == 0u)
					continue;
				tiles += 0x3Fu;
				continue;
			}
			t3 = character;
			command = t3 + 0x39u;
			if (t3 < 0xC7u)
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
					t4 = text;
					text = t4 + 2u;
					colour = ((uint32_t)mem_read8(mem_read16(t4)) << 8) | colour_byte;
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
			stack_6 = text;
			stack_10007 = command;
			stack_10008 = colour_byte;
			text = test_mode_words[(int8_t)((uint8_t)((uint32_t)command << 1)) / 2];
			colour = colour_byte;
			test_print(colour, &tiles, &text, &carry);
			colour_byte = stack_10008;
			text = stack_6;
			if (stack_10007 == 0u)
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
						t5 = (uint32_t)(uint8_t)(tile + 0x30u) << 6;
						t6 = text;
						text = t6 + 1u;
						t7 = (((uint32_t)(t5 >> 8) << 8) | (uint8_t)(t5 + mem_read8(t6))) + 0x208Cu;
						stack_10005 = t7 >> 8;
						stack_10006 = t7;
						tiles = ((uint32_t)stack_10005 << 8) | stack_10006;
						continue;
					}
					L_05E69F = false;
					tiles = stack + 0x40u;
					continue;
				}
				L_05E6A6 = false;
				tiles = stack + 0x80u;
				continue;
			}
			L_05E6AE = false;
			tiles = stack;
			if (test_print_down != 0u)
			{
				tiles += 3u;
				continue;
			}
			tiles += 0xC0u;
			continue;
		}
		L_05E6C1 = false;
		tiles = stack;
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
	uint16_t t1 = 0;

	io_write8(tiles - 0x2000u, (uint8_t)tile_and_colour);
	t1 = tiles;
	tiles = t1 + 1u;
	io_write8(t1, tile_and_colour >> 8);
	return tiles;
}

/* Unused: prints a word as four hex digits. */
void unused_test_print_hex_word(uint16_t tiles, uint16_t u)
{
	uint16_t value = 0;
	uint8_t stack = 0, stack_2 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	value = (uint32_t)stack_2 << 8;
	test_print_hex(&tiles, &value);
	value = (uint32_t)stack << 8;
	test_print_hex(&tiles, &value);
}

/* Prints A as two hex digits at X */
void test_print_hex(uint16_t *p_tiles, uint16_t *p_value)
{
	uint16_t tiles = (uint16_t)*p_tiles;
	uint16_t value = (uint16_t)*p_value;
	uint8_t printed_byte = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	printed_byte = (uint8_t)(value >> 8);
	stack = (uint8_t)value;
	stack_2 = printed_byte;
	t1 = tiles;
	mem_write8(t1, test_mode_hex_digit_tiles[(((printed_byte >> 1) >> 1) >> 1) >> 1]);
	t2 = t1 + 1u;
	tiles = t2 + 1u;
	mem_write8(t2, test_mode_hex_digit_tiles[stack_2 & 0xFu]);
	value = ((uint32_t)stack_2 << 8) | stack;
	*p_tiles = tiles;
	*p_value = value;
}

/* Queues sound command 0000 (all sounds off) */
uint16_t test_silence(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;

	command = 0u;
	carry = vector_queue_sound(command);
	return command;
}
