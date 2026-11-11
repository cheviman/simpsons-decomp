/**
 *    Name:        test_mode/sound_test.c
 *    Description: the music and sound checks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The 5 MUSIC CHECK page, by its step */
void test_music_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_music_page_steps_ADDRESS;
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

/* Waits for the first choice, then plays the music number */
void test_music_first_choice(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	test_sound_test_first_press(&d, &carry);
	if (carry)
		test_music_play(&d, &carry);
	*p_d = d;
	*p_carry = carry;
}

/* NEXT MUSIC steps the number (wrapping past 30), REPLAY MUSIC replays it */
void test_music_choice(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t number_variable = 0;

	test_menu_update(&d, &carry);
	if (carry)
	{
		number_variable = test_music_number_ADDRESS;
		d = (d & 0xFFu) | 0x3000u;
		d = test_sound_test_next(number_variable, d);
		carry = test_music_open(number_variable);
	}
	*p_d = d;
	*p_carry = carry;
}

/* Prints the music page */
uint32_t test_music_open(uint16_t tiles)
{
	uint16_t text_number = 0;

	text_number = 0x500u;
	return test_open_page(tiles, text_number);
}

/* Plays the music number again after the page is printed */
void test_music_replay(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	test_page_step--;
	*p_d = d;
	test_music_play(p_d, &carry);
	*p_carry = carry;
}

/* Plays music number 5915 from the music list */
void test_music_play(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t number = 0;
	uint16_t commands = 0, sound_test_command = 0;

	number = test_music_number;
	commands = 0x68EFu;
	number -= 0x30u;
	sound_test_command = SOUND_TEST_COMMAND(commands + (int8_t)number * 0x2u);
	carry = vector_queue_sound(sound_test_command);
	*p_d = sound_test_command;
	*p_carry = carry;
}

/* On the first line steps the number at X (wrapping past A); stops the sound and restarts the timer */
uint16_t test_sound_test_next(uint16_t number_variable, uint16_t last_and_line)
{
	uint8_t last_number = 0, number = 0;
	uint8_t stack = 0;

	last_number = (uint8_t)(last_and_line >> 8);
	if ((uint8_t)last_and_line != 0u)
	{
		test_sound_timer = 0xFAu;
		return test_silence();
	}
	stack = last_number;
	number = mem_read8(number_variable) + 1u;
	if (stack < number)
		number = 0u;
	mem_write8(number_variable, number);
	test_sound_timer = 0xFAu;
	return test_silence();
}

/* On a choice in the menu, restarts the timer and goes to the page's next step */
void test_sound_test_first_press(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0;

	test_menu_update(&d, &carry);
	a = (uint8_t)(d >> 8);
	if (carry)
	{
		a = 0xFAu;
		test_sound_timer = 0xFAu;
		test_page_step++;
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_d = d_2;
	*p_carry = carry;
}

/* The 6 SOUND CHECK page, by its step */
void test_sound_page(uint16_t d)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, page_steps = 0, setting = 0;

	page_steps = test_sound_page_steps_ADDRESS;
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

/* Waits for the first choice, then plays the sound number */
void test_sound_first_choice(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	test_sound_test_first_press(&d, &carry);
	if (carry)
		test_sound_play(&d, &carry);
	*p_d = d;
	*p_carry = carry;
}

/* NEXT SOUND or REPLAY SOUND; the timer running out steps to the next sound by itself */
void test_sound_choice(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t number_variable = 0;
	uint8_t timer_before = 0;

	timer_before = test_sound_timer;
	test_sound_timer = timer_before - 1u;
	if (timer_before == 1u)
	{
		number_variable = test_sound_number_ADDRESS;
		d = (d & 0xFFu) | 0xAA00u;
		d = test_sound_test_next(number_variable, d);
		carry = test_sound_open(number_variable);
	}
	else
	{
		test_menu_update(&d, &carry);
		if (carry)
		{
			number_variable = test_sound_number_ADDRESS;
			d = (d & 0xFFu) | 0xAA00u;
			d = test_sound_test_next(number_variable, d);
			carry = test_sound_open(number_variable);
		}
	}
	*p_d = d;
	*p_carry = carry;
}

/* Prints the sound page */
uint32_t test_sound_open(uint16_t tiles)
{
	uint16_t text_number = 0;

	text_number = 0x600u;
	return test_open_page(tiles, text_number);
}

/* Plays the sound number again after the page is printed */
void test_sound_replay(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	test_page_step--;
	*p_d = d;
	test_sound_play(p_d, &carry);
	*p_carry = carry;
}

/* Plays sound number 5916 from the effects' list */
void test_sound_play(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t number = 0;
	uint16_t commands = 0, sound_test_command = 0;

	number = test_sound_number;
	commands = 0x6799u;
	number -= 0x30u;
	sound_test_command = SOUND_TEST_COMMAND(commands + (int8_t)number * 0x2u);
	carry = vector_queue_sound(sound_test_command);
	*p_d = sound_test_command;
	*p_carry = carry;
}
