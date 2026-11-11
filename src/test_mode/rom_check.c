/**
 *    Name:        test_mode/rom_check.c
 *    Description: the ROM check page
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the ROM check's step */
uint16_t test_rom_check_step(uint16_t d)
{
	uint8_t step_offset = 0;
	uint16_t d_2 = 0;

	step_offset = (uint32_t)rom_check_step << 1;
	switch ((int8_t)step_offset)
	{
	case 0:
		return test_rom_check_start();
	case 2:
	case 4:
	case 6:
	case 8:
		return test_rom_check_sum_tiles();
	case 10:
		return test_rom_check_tiles_result();
	case 12:
	case 14:
	case 16:
	case 18:
		return test_rom_check_sum_sprites();
	case 20:
		return test_rom_check_6g(d);
	case 22:
		return test_rom_check_7g(d);
	case 24:
		d_2 = (d & 0xFFu) | ((uint32_t)step_offset << 8);
		test_rom_check_done();
		return d_2;
	}
	unreachable();
}

/* Clears the check's variables and asks the sound CPU to sum its ROM */
uint16_t test_rom_check_start(void)
{
	uint8_t answer_low = 0, no_sound_cpu = 0;
	uint16_t clear_from = 0, clear_to = 0, count = 0, d = 0, ignored16 = 0, sound_cpu_answer = 0, text_number = 0;

	clear_from = rom_check_step_ADDRESS;
	clear_to = rom_check_chip_ADDRESS;
	rom_check_step = 0u;
	count = 0xFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	text_number = 0xCu;
	vector_print_game_text(text_number);
	vector_ask_sound_cpu_check(&ignored16, &sound_cpu_answer);
	no_sound_cpu = (uint8_t)(sound_cpu_answer >> 8);
	answer_low = (uint8_t)sound_cpu_answer;
	no_sound_cpu &= 0x80u;
	rom_check_no_sound_cpu = no_sound_cpu;
	if (no_sound_cpu == 0u)
	{
		sound_cpu_answer = start_sample_rom_check();
		no_sound_cpu = (uint8_t)(sound_cpu_answer >> 8);
		answer_low = (uint8_t)sound_cpu_answer;
	}
	rom_check_step++;
	d = ((uint32_t)no_sound_cpu << 8) | answer_low;
	return d;
}

/* Sums a quarter of the tile ROMs (both banks of the K052109) */
uint16_t test_rom_check_sum_tiles(void)
{
	uint8_t chip_offset = 0;
	uint16_t d = 0, ignored16 = 0, sum = 0;

	sum = 0u;
	tile_rom_address = 0u;
	io_write8(tile_chip_banks_0_1, 0x10u);
	io_write8(tile_chip_banks_2_3, 0x32u);
	test_sum_tile_rom(&sum, &ignored16);
	tile_rom_address = 0u;
	io_write8(tile_chip_banks_0_1, 0x54u);
	io_write8(tile_chip_banks_2_3, 0x76u);
	test_sum_tile_rom(&sum, &d);
	chip_offset = (uint32_t)rom_check_chip << 1;
	mem_write16(rom_check_tile_sums_ADDRESS + (int8_t)chip_offset, sum);
	rom_check_chip++;
	rom_check_step++;
	d = (d & 0xFFu) | ((uint32_t)chip_offset << 8);
	return d;
}

/* Checks the two tile ROMs' sums and prints them */
uint16_t test_rom_check_tiles_result(void)
{
	uint16_t d = 0, sum = 0;
	uint16_t tile_sum = 0, tile_sum_4 = 0;

	tile_sum = rom_check_tile_sums(1);
	sum = rom_check_tile_sums(0) + tile_sum;
	test_check_rom_sum(sum);
	tile_sum_4 = rom_check_tile_sums(3);
	sum = rom_check_tile_sums(2) + tile_sum_4;
	d = test_check_rom_sum(sum);
	io_write8(tile_chip_banks_0_1, 0x10u);
	io_write8(tile_chip_banks_2_3, 0x32u);
	rom_check_chip = 0u;
	rom_check_step++;
	d = (d & 0xFFu) | 0x3200u;
	return d;
}

/* Sums one sprite ROM through the K053246 and checks it */
uint16_t test_rom_check_sum_sprites(void)
{
	uint8_t sprite_control = 0;
	uint16_t d = 0, sum = 0;
	uint8_t passes_to_go = 0;

	sprite_control = sprite_chip_control & 0xEFu;
	sprite_chip_control = sprite_control;
	io_write8(sprite_chip_control_register, sprite_control);
	sum = 0u;
	sprite_rom_address = 0u;
	sprite_rom_address_bottom = sprite_rom_read_banks[(int8_t)rom_check_chip];
	sprite_rom_passes_left = 8u;
	do
	{
		sum = test_sum_sprite_rom(sum);
		passes_to_go = sprite_rom_passes_left;
		sprite_rom_passes_left = passes_to_go - 1u;
	} while (passes_to_go != 1u);
	d = test_check_rom_sum(sum);
	rom_check_chip++;
	rom_check_step++;
	return d;
}

/* Prints the sound board's 6G result and sum the sound CPU reports */
uint16_t test_rom_check_6g(uint16_t d)
{
	uint32_t answered = 0;
	uint8_t answer_bits = 0, no_sound_cpu = 0, sprite_control = 0;
	uint16_t d_2 = 0, place = 0, sample_sum = 0;
	uint8_t sound_cpu_missing = 0;

	sprite_control = sprite_chip_control | 0x10u;
	sprite_chip_control = sprite_control;
	io_write8(sprite_chip_control_register, sprite_control);
	sound_cpu_missing = rom_check_no_sound_cpu;
	no_sound_cpu = sound_cpu_missing;
	if (sound_cpu_missing != 0u)
	{
		rom_check_step++;
		d_2 = (d & 0xFFu) | ((uint32_t)no_sound_cpu << 8);
		return d_2;
	}
	sample_rom_check_answered(&d, &answered);
	if (answered == 0u)
	{
		d_2 = (d & 0xFFu) | ((uint32_t)no_sound_cpu << 8);
		return d_2;
	}
	check_sample_rom_1f();
	vector_ask_sound_cpu_check(&sample_sum, &d_2);
	answer_bits = (uint8_t)(d_2 >> 8);
	place = 0x251Fu;
	if ((answer_bits & 4u) != 0u)
	{
		d = test_print_rom_bad(sample_sum, place);
		no_sound_cpu = (uint8_t)(d >> 8);
		rom_check_step++;
		d_2 = (d & 0xFFu) | ((uint32_t)no_sound_cpu << 8);
		return d_2;
	}
	d_2 = test_print_rom_ok(sample_sum, place);
	rom_check_step++;
	return d_2;
}

/* Prints the sound board's 7G result and sum the sound CPU reports */
uint16_t test_rom_check_7g(uint16_t d)
{
	uint8_t answer_bits = 0, no_sound_cpu = 0;
	uint16_t d_2 = 0, place = 0, sample_sum = 0;
	uint8_t sound_cpu_missing = 0;

	sound_cpu_missing = rom_check_no_sound_cpu;
	no_sound_cpu = sound_cpu_missing;
	if (sound_cpu_missing != 0u)
	{
		rom_check_step++;
		d_2 = (d & 0xFFu) | ((uint32_t)no_sound_cpu << 8);
		return d_2;
	}
	check_sample_rom_1d();
	vector_ask_sound_cpu_check(&sample_sum, &d_2);
	answer_bits = (uint8_t)(d_2 >> 8);
	place = 0x259Fu;
	if ((answer_bits & 8u) != 0u)
	{
		d = test_print_rom_bad(sample_sum, place);
		no_sound_cpu = (uint8_t)(d >> 8);
		rom_check_step++;
		d_2 = (d & 0xFFu) | ((uint32_t)no_sound_cpu << 8);
		return d_2;
	}
	d_2 = test_print_rom_ok(sample_sum, place);
	rom_check_step++;
	return d_2;
}

/* The check's last step: nothing more */
void test_rom_check_done(void)
{
}

/* Adds up the tile ROM's bytes through the K052109, interrupts off */
void test_sum_tile_rom(uint16_t *p_sum, uint16_t *p_d)
{
	uint16_t sum = (uint16_t)*p_sum;
	uint8_t control = 0, output = 0, rom_byte = 0;
	uint16_t bytes_left = 0, d = 0, rom_place = 0;
	uint8_t saved_output = 0;
	uint8_t watchdog_read = 0, pages_to_go = 0;
	uint16_t remaining_bytes = 0;

	disable_irq();
	io_write8(tile_chip_irq_control, 0xFBu);
	disable_firq();
	control = board_control & ~4u;
	board_control = control;
	io_write8(board_control_register, control);
	tile_rom_pages_left = 0x40u;
	do
	{
		io_write8(0x1E00u, tile_rom_page);
		rom_place = 0x2000u + (int8_t)rom_check_chip;
		bytes_left = 0x800u;
		output = board_output | 8u;
		board_output = output;
		io_write8(board_output_register, output);
		do
		{
			watchdog_read = io_read8(watchdog_port);
			rom_byte = mem_read8(rom_place);
			sum += rom_byte;
			rom_place += 4u;
			remaining_bytes = bytes_left - 1u;
			bytes_left = remaining_bytes;
		} while (remaining_bytes != 0u);
		output = board_output & ~8u;
		board_output = output;
		io_write8(board_output_register, output);
		tile_rom_page++;
		pages_to_go = tile_rom_pages_left;
		tile_rom_pages_left = pages_to_go - 1u;
	} while (pages_to_go != 1u);
	enable_irq();
	leftover_y = bytes_left;
	take_interrupts();
	saved_output = output;
	io_write8(tile_chip_irq_control, 0xFFu);
	enable_firq();
	leftover_y = bytes_left;
	take_interrupts();
	control = board_control | 4u;
	board_control = control;
	io_write8(board_control_register, control);
	d = ((uint32_t)saved_output << 8) | rom_byte;
	*p_sum = sum;
	*p_d = d;
}

/* Adds up 10000 words of a sprite ROM through the K053246, interrupts off */
uint16_t test_sum_sprite_rom(uint16_t sum)
{
	uint32_t carry = 0;
	uint8_t control = 0, output = 0;
	uint16_t reads_left = 0;
	uint8_t first_byte = 0, second_byte = 0, watchdog_read = 0;
	uint16_t old_address_low = 0, address_low_before = 0, remaining_reads = 0;

	reads_left = 0u;
	disable_irq();
	io_write8(tile_chip_irq_control, 0xFBu);
	disable_firq();
	control = board_control & ~4u;
	board_control = control;
	io_write8(board_control_register, control);
	output = board_output & 0xDFu;
	board_output = output;
	io_write8(board_output_register, output);
	do
	{
		io_write8(sprite_chip_rom_high, sprite_rom_address_high);
		io_write8(sprite_chip_rom_middle, sprite_rom_address_middle);
		io_write8(sprite_chip_rom_bottom, sprite_rom_address_bottom);
		first_byte = io_read8(sprite_chip_rom_first_byte);
		second_byte = io_read8(sprite_chip_rom_second_byte);
		sum = sum + first_byte + second_byte;
		old_address_low = sprite_rom_address_low;
		address_low_before = old_address_low;
		carry = (uint16_t)(address_low_before + 4u) < address_low_before;
		sprite_rom_address_low = address_low_before + 4u;
		sprite_rom_address_high += carry;
		watchdog_read = io_read8(watchdog_port);
		remaining_reads = reads_left - 1u;
		reads_left = remaining_reads;
	} while (remaining_reads != 0u);
	output = board_output | 0x20u;
	board_output = output;
	io_write8(board_output_register, output);
	enable_irq();
	leftover_y = reads_left;
	take_interrupts();
	io_write8(tile_chip_irq_control, 0xFFu);
	enable_firq();
	leftover_y = reads_left;
	take_interrupts();
	control = board_control | 4u;
	board_control = control;
	io_write8(board_control_register, control);
	return sum;
}

/* Compares a graphics ROM's sum with the right one and prints OK or BAD */
uint16_t test_check_rom_sum(uint16_t sum)
{
	uint8_t line_offset = 0;
	uint16_t place = 0;

	line_offset = (uint32_t)rom_check_line << 1;
	place = TABLE16(graphics_rom_result_places, (int8_t)line_offset);
	if (sum != TABLE16(graphics_rom_sums, (int8_t)line_offset))
		return test_print_rom_bad(sum, place);
	return test_print_rom_ok(sum, place);
}

/* Prints OK and the sum, and moves to the next result's line */
uint16_t test_print_rom_ok(uint16_t sum, uint16_t place)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, place_2 = 0;
	uint16_t printed_sum = 0;
	uint16_t letter_o_place = 0, letter_k_place = 0;

	io_write8(place - 0x2000u, 0u);
	letter_o_place = place;
	place = letter_o_place + 1u;
	io_write8(letter_o_place, 0x1Fu);
	mem_write8(place - 0x2000u, 0u);
	letter_k_place = place;
	mem_write8(letter_k_place, 0x1Bu);
	hex_colour = 0u;
	place = letter_k_place + 2u;
	printed_sum = sum;
	place_2 = place + 2u;
	d = printed_sum;
	d = vector_print_hex_word(place_2, d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	rom_check_line++;
	d = ((uint32_t)a << 8) | b;
	return d;
}

/* Prints BAD (in colour 40) and the sum, and moves to the next result's line */
uint16_t test_print_rom_bad(uint16_t sum, uint16_t place)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, place_2 = 0;
	uint16_t printed_sum = 0;
	uint16_t letter_b_place = 0, letter_a_place = 0, letter_d_place = 0;

	io_write8(place - 0x2000u, 0x40u);
	letter_b_place = place;
	place = letter_b_place + 1u;
	io_write8(letter_b_place, 0x12u);
	mem_write8(place - 0x2000u, 0x40u);
	letter_a_place = place;
	place = letter_a_place + 1u;
	mem_write8(letter_a_place, 0x11u);
	mem_write8(place - 0x2000u, 0x40u);
	letter_d_place = place;
	mem_write8(letter_d_place, 0x14u);
	hex_colour = 0x40u;
	printed_sum = sum;
	place_2 = letter_d_place + 3u;
	d = printed_sum;
	d = vector_print_hex_word(place_2, d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	rom_check_line++;
	d = ((uint32_t)a << 8) | b;
	return d;
}
