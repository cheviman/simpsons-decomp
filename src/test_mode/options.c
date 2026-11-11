/**
 *    Name:        test_mode/options.c
 *    Description: start buttons and the coin/game options
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The 7 START BUTTON page: with or without start buttons (which turns the premium start off) */
void test_start_buttons_page(void)
{
	uint32_t carry = 0;
	uint8_t choice = 0, value = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A60u;
	text_and_choice = 7u;
	test_choose_setting(setting, &text_and_choice, &carry);
	choice = (uint8_t)text_and_choice;
	if (carry == 0u || choice == 0u)
		return;
	setting = 0x5A62u;
	value = 0u;
	test_write_setting(setting, value);
	test_premium_start = 0u;
}

/* The 8 COIN/GAME OPTIONS page, by its step */
void test_options_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_options_page_steps_ADDRESS;
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

/* Prints an S unless the count was 1 */
uint16_t test_print_plural(uint16_t tiles, uint16_t count)
{
	uint16_t tile_and_colour = 0;

	if (count >> 8 == 1u)
		return tiles;
	tile_and_colour = 0x2300u;
	return test_put_tile(tiles, tile_and_colour);
}

/* Prints the coin setting as n COIN(S) n CREDIT(S), the continue's with the extra coins */
void test_print_coinage(uint16_t tiles)
{
	uint32_t zero = 0, carry = 0;
	uint8_t coinage = 0, coins = 0, colour = 0, colour_2 = 0, credits_digit = 0, extra_coins = 0;
	uint16_t coins_and_extra = 0, count = 0, setting = 0, text = 0, tile_and_colour = 0, value = 0;
	uint8_t stack = 0, stack_2 = 0;

	setting = 0x5A59u;
	test_read_setting(&tiles, &setting, &value, &zero);
	coinage = (uint8_t)value;
	stack = coinage;
	coins = coin_setting_coin_digits[1 + (int8_t)coinage] - 0x30u;
	if (test_coinage_line == 0u)
	{
		setting = 0x5A62u;
		coins_and_extra = (uint32_t)coins << 8;
		test_read_setting(&tiles, &setting, &coins_and_extra, &zero);
		coins = (uint8_t)(coins_and_extra >> 8);
		extra_coins = (uint8_t)coins_and_extra;
		stack_2 = extra_coins;
		coins += stack_2;
	}
	colour_2 = 0u;
	tile_and_colour = (uint32_t)coins << 8;
	tiles = test_put_tile(tiles, tile_and_colour);
	tiles++;
	text = test_text_coin_ADDRESS;
	colour = colour_2;
	test_print(colour, &tiles, &text, &carry);
	count = ((uint32_t)coins << 8) | colour_2;
	tiles = test_print_plural(tiles, count);
	tiles++;
	credits_digit = coin_setting_credit_digits[1 + (int8_t)stack] - 0x30u;
	tile_and_colour = ((uint32_t)credits_digit << 8) | colour_2;
	tiles = test_put_tile(tiles, tile_and_colour);
	text = test_text_credit_ADDRESS;
	colour = colour_2;
	test_print(colour, &tiles, &text, &carry);
	count = ((uint32_t)credits_digit << 8) | colour_2;
	test_print_plural(tiles, count);
}

/* Prints the options page with every setting's value */
void test_options_open(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t b = 0, colour = 0, players_digit = 0, setting_byte = 0;
	uint16_t count = 0, ignored16 = 0, setting = 0, text = 0, text_number = 0, tile_and_colour = 0, tiles = 0, value = 0;

	tiles = 0x219Fu;
	test_coinage_line = 0u;
	test_print_coinage(tiles);
	tiles = 0x21DFu;
	test_coinage_line++;
	test_print_coinage(tiles);
	setting = 0x5A5Du;
	test_read_setting(&ignored16, &setting, &value, &zero);
	setting_byte = (uint8_t)value;
	tiles = 0x229Fu;
	players_digit = (uint16_t)(((uint32_t)players_digit << 8) | setting_byte) + 1u;
	b = 0u;
	tile_and_colour = (uint32_t)players_digit << 8;
	tiles = test_put_tile(tiles, tile_and_colour);
	text = test_text_player_ADDRESS;
	colour = b;
	test_print(colour, &tiles, &text, &carry);
	count = ((uint32_t)players_digit << 8) | b;
	test_print_plural(tiles, count);
	setting = 0x5A5Cu;
	test_read_setting(&ignored16, &setting, &value, &zero);
	setting_byte = (uint8_t)value;
	tiles = 0x235Fu;
	text = test_mode_words[31 + (int8_t)((uint8_t)((uint32_t)setting_byte << 1)) / 2];
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	setting = 0x5A5Eu;
	test_read_setting(&ignored16, &setting, &value, &zero);
	tiles = 0x241Fu;
	test_print_off_on(tiles, (uint8_t)value);
	setting = 0x5A5Fu;
	test_read_setting(&ignored16, &setting, &value, &zero);
	setting_byte = (uint8_t)value;
	tiles = 0x24DFu;
	text = test_text_normal_ADDRESS;
	if (setting_byte != 0u)
		text = test_text_upside_down_ADDRESS;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	setting = 0x5A61u;
	test_read_setting(&ignored16, &setting, &value, &zero);
	setting_byte = (uint8_t)value;
	tiles = 0x259Fu;
	text = test_text_monaural_ADDRESS;
	if (setting_byte != 0u)
		text = test_text_stereo_ADDRESS;
	b = 0u;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	text_number = 0x800u | b;
	carry = test_open_page(tiles, text_number);
	*p_d = text_number;
	*p_carry = carry;
}

/* Prints OFF or ON for B */
void test_print_off_on(uint16_t tiles, uint8_t value)
{
	uint32_t carry = 0;
	uint8_t colour = 0;
	uint16_t text = 0;

	text = test_text_off_ADDRESS;
	if ((uint8_t)value != 0u)
		text = test_text_on_ADDRESS;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
}

/* Leaves the test mode: tells the sound CPU, then restarts at the reset vector */
void test_exit(void)
{
	vector_reset_sound();
	switch (reset_vector[0])
	{
	case 0x86CEu:
		break;
	}
	boot();
}

/* The 8-1 COIN SETTING page: plain, or with the premium start's settings */
void test_coin_setting_page(uint16_t x)
{
	uint32_t zero = 0, carry = 0;
	uint8_t next_page = 0, premium_coins = 0;
	uint16_t d = 0, ignored16 = 0, setting = 0;

	setting = 0x5A60u;
	test_read_setting(&x, &setting, &ignored16, &zero);
	if (zero == 0u)
	{
		setting = 0x5A59u;
		d = 0xAu;
		test_choose_setting(setting, &d, &carry);
		return;
	}
	setting = 0x5A62u;
	test_read_setting(&x, &setting, &d, &zero);
	premium_coins = (uint8_t)d;
	if (zero)
		next_page = 0x13u;
	else
	{
		test_premium_start = 1u;
		d = 0x1400u | (uint8_t)(premium_coins - 2u);
		x = test_open_page_marked(x, d);
		next_page = 0x15u;
	}
	d = (d & 0xFFu) | ((uint32_t)next_page << 8);
	test_open_coinage_page(x, d);
	test_page_step = 0u;
	test_page = 0x12u;
}

/* Opens page A with the coin setting's line marked */
void test_open_coinage_page(uint16_t x, uint16_t d)
{
	uint32_t zero = 0;
	uint16_t setting = 0;

	setting = 0x5A59u;
	test_read_setting(&x, &setting, &d, &zero);
	test_open_page_marked(x, d);
}

/* Makes page A the current one, prints it and marks line B */
uint16_t test_open_page_marked(uint16_t tiles, uint16_t page_and_line)
{
	uint16_t colour_and_line = 0;

	test_page = page_and_line >> 8;
	test_open_page(tiles, page_and_line);
	colour_and_line = (page_and_line & 0xFFu) | 0x4000u;
	return test_mark_line(colour_and_line);
}

/* The 8-2 NUMBER OF PLAYERS page */
void test_players_page(void)
{
	uint32_t carry = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A5Du;
	text_and_choice = 0xCu;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* The 8-3 DIFFICULTY page */
void test_difficulty_page(void)
{
	uint32_t carry = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A5Cu;
	text_and_choice = 0xDu;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* The 8-4 SOUND IN ATTRACT MODE page */
void test_attract_sound_page(void)
{
	uint32_t carry = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A5Eu;
	text_and_choice = 0xEu;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* The 8-5 VIDEO SCREEN FLIP page, flipping the K052109 as it is chosen */
void test_screen_flip_page(void)
{
	uint32_t carry = 0;
	uint8_t choice = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A5Fu;
	text_and_choice = 0xFu;
	test_choose_setting(setting, &text_and_choice, &carry);
	choice = (uint8_t)text_and_choice;
	io_write8(tile_chip_flip, choice);
}

/* The 8-6 SOUND OUTPUT page (monaural or stereo) */
void test_sound_output_page(void)
{
	uint32_t carry = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A61u;
	text_and_choice = 0x10u;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* A page that chooses the setting at Y among its lines (page B), by its step */
void test_choose_setting(uint16_t setting, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t page_steps = 0;

	page_steps = test_choose_setting_steps_ADDRESS;
	switch ((uint16_t)(page_steps + (int8_t)((uint32_t)test_page_step << 1)))
	{
	case test_menu_page_steps_ADDRESS:
		test_menu_open(&d, &carry);
		break;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		test_menu_update(&d, &carry);
		break;
	case test_rom_check_page_steps_ADDRESS:
		carry = test_rom_check_open(page_steps);
		break;
	case 0x60A3u:
		test_rom_check_run(&d, &carry);
		break;
	case test_screen_check_page_steps_ADDRESS:
		test_screen_check_draw(&d, &carry);
		break;
	case test_color_check_page_steps_ADDRESS:
		test_color_check_draw(&d, &carry);
		break;
	case test_io_check_page_steps_ADDRESS:
		test_io_check_open(page_steps, &d, &carry);
		break;
	case 0x617Fu:
		test_io_check_run(&d, &carry);
		break;
	case test_music_page_steps_ADDRESS:
		carry = test_music_open(page_steps);
		break;
	case 0x621Du:
		test_music_first_choice(&d, &carry);
		break;
	case 0x621Fu:
		test_music_choice(&d, &carry);
		break;
	case 0x6221u:
		test_music_replay(&d, &carry);
		break;
	case test_sound_page_steps_ADDRESS:
		carry = test_sound_open(page_steps);
		break;
	case 0x6279u:
		test_sound_first_choice(&d, &carry);
		break;
	case 0x627Bu:
		test_sound_choice(&d, &carry);
		break;
	case 0x627Du:
		test_sound_replay(&d, &carry);
		break;
	case test_options_page_steps_ADDRESS:
		test_options_open(&d, &carry);
		break;
	case test_choose_setting_steps_ADDRESS:
		test_choose_setting_open(page_steps, setting, &d, &carry);
		break;
	case 0x642Du:
		test_choose_setting_run(setting, &d, &carry);
		break;
	case test_factory_setting_page_steps_ADDRESS:
		test_factory_setting_apply(page_steps, &d, &carry);
		break;
	case 0x646Fu:
		test_factory_setting_wait(&d, &carry);
		break;
	}
	*p_d = d;
	*p_carry = carry;
}

/* Prints the setting's page and marks its value's line */
void test_choose_setting_open(uint16_t tiles, uint16_t setting, uint16_t *p_mark_colour_word, uint32_t *p_carry)
{
	uint16_t mark_colour_word = (uint16_t)*p_mark_colour_word;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t stack = 0;

	stack = setting;
	mark_colour_word |= (uint32_t)(uint16_t)(((uint32_t)a << 8) | mark_colour_word) << 8;
	test_open_page(tiles, mark_colour_word);
	setting = stack;
	mark_colour_word = 0x4000u;
	test_mark_setting(&setting, &mark_colour_word);
	*p_mark_colour_word = mark_colour_word;
	test_choose_setting_run(setting, p_mark_colour_word, &carry);
	*p_carry = carry;
}

/* Runs the menu; a chosen line becomes the setting (carry set) */
void test_choose_setting_run(uint16_t setting, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, value = 0;
	uint16_t colour_and_line = 0, d_2 = 0, ignored16 = 0;
	uint8_t stack = 0, stack_2 = 0;

	stack_2 = setting >> 8;
	stack = (uint8_t)setting;
	test_menu_update(&d, &carry);
	b = (uint8_t)d;
	setting = ((uint32_t)stack_2 << 8) | stack;
	if (carry == 0u)
	{
		d_2 = 0x4000u;
		test_mark_setting(&setting, &d_2);
		b = (uint8_t)d_2;
		carry = 0u;
		d_2 = b;
	}
	else
	{
		stack = b;
		d_2 = 0u;
		test_read_setting(&ignored16, &setting, &d_2, &zero);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		colour_and_line = ((uint32_t)a << 8) | b;
		test_mark_line(colour_and_line);
		value = (uint8_t)(stack - 1u);
		setting = test_write_setting(setting, value);
		d_2 = 0x4000u;
		test_mark_setting(&setting, &d_2);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		carry = 1u;
		d_2 = ((uint32_t)(uint8_t)~a << 8) | b;
	}
	*p_d = d_2;
	*p_carry = carry;
}

/* Colours the line of the setting at Y's value with A */
void test_mark_setting(uint16_t *p_setting, uint16_t *p_d)
{
	uint16_t setting = (uint16_t)*p_setting;
	uint16_t d = (uint16_t)*p_d;
	uint32_t zero = 0;
	uint16_t ignored16 = 0;

	test_read_setting(&ignored16, &setting, &d, &zero);
	test_mark_line(d);
	*p_setting = setting;
	*p_d = d;
}

/* The 8-7 FACTORY SETTING page, by its step */
void test_factory_setting_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_factory_setting_page_steps_ADDRESS;
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

/* Writes the factory settings and prints COMPLETE. */
void test_factory_setting_apply(uint16_t tiles, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0, colour = 0;
	uint16_t d = 0, text = 0, text_number = 0, x = 0;

	text = test_text_factory_setting_ADDRESS;
	colour = 0u;
	test_print(colour, &tiles, &text, &carry);
	eeprom_write_defaults(&x, &d);
	b = (uint8_t)d;
	text_number = 0x1100u | b;
	carry = test_open_page(x, text_number);
	*p_d = text_number;
	*p_carry = carry;
}

/* Runs the page's menu */
void test_factory_setting_wait(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	*p_d = d;
	test_menu_update(p_d, &carry);
	*p_carry = carry;
}

/* The premium start's OFF/ON choice, then the coin settings that go with it */
void test_premium_start_page(void)
{
	uint32_t zero = 0, carry = 0;
	uint8_t blank_tile = 0, choice = 0, next_page = 0, premium_coins = 0;
	uint16_t clear_to = 0, count = 0, d = 0, ignored16 = 0, setting = 0;
	uint8_t stack = 0;

	setting = test_premium_start_ADDRESS;
	d = 0x12u;
	test_choose_setting(setting, &d, &carry);
	choice = (uint8_t)d;
	if (carry == 0u)
		return;
	setting = 0x5A62u;
	if (choice != 0u)
	{
		test_read_setting(&ignored16, &setting, &d, &zero);
		premium_coins = (uint8_t)d;
		if (zero)
			premium_coins++;
		test_premium_coins = premium_coins - 2u;
		next_page = 0x14u;
	}
	else
	{
		stack = choice;
		test_read_setting(&ignored16, &setting, &d, &zero);
		choice = stack;
		if (zero == 0u)
		{
			d = choice;
			test_write_setting(setting, (uint8_t)d);
		}
		next_page = 0x13u;
	}
	clear_to = 0x22CCu;
	blank_tile = 0x10u;
	count = 0x600u;
	while (count != 0u)
	{
		mem_write8(clear_to, blank_tile);
		clear_to++;
		count--;
	}
	if (next_page != 0x14u)
	{
		test_page = next_page;
		test_page_step = 0u;
		test_cursor = 0u;
		return;
	}
	stack = next_page;
	d = (d & 0xFFu) | 0x1500u;
	test_open_coinage_page(clear_to, d);
	next_page = stack;
	test_page = next_page;
	test_page_step = 0u;
	test_cursor = 0u;
}

/* The coin settings' page without the premium start */
void test_coinage_page(void)
{
	uint32_t carry = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = 0x5A59u;
	text_and_choice = 0x13u;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* The extra coins for the premium start (1-5), stored as the setting less 2 */
void test_premium_coins_page(void)
{
	uint32_t carry = 0;
	uint8_t choice = 0, next_page = 0, value = 0;
	uint16_t setting = 0, text_and_choice = 0;

	setting = test_premium_coins_ADDRESS;
	text_and_choice = 0x14u;
	test_choose_setting(setting, &text_and_choice, &carry);
	choice = (uint8_t)text_and_choice;
	if (carry == 0u)
		return;
	setting = 0x5A62u;
	value = (uint8_t)(choice + 2u);
	test_write_setting(setting, value);
	next_page = 0x15u;
	test_page = next_page;
	test_page_step = 0u;
	test_cursor = 0u;
}

/* The coin settings' page with the premium start */
void test_premium_coinage_page(void)
{
	uint32_t carry = 0;
	uint8_t next_page = 0;
	uint16_t setting = 0, text_and_choice = 0;

	next_page = 0x15u;
	setting = 0x5A59u;
	text_and_choice = next_page;
	test_choose_setting(setting, &text_and_choice, &carry);
}

/* Goes back to the main menu */
void test_back_to_menu(void)
{
	test_page_step = 0u;
	test_page = 0u;
}
