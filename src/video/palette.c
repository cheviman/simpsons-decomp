/**
 *    Name:        video/palette.c
 *    Description: the palette requests and the palette jobs that run them a frame at a time
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Unused: does nothing. */
void unused_palette_no_op(void)
{
}

/* Starts a palette request of the kind palette_request_kind says, with its argument */
void palette_request(uint16_t request, uint16_t *p_y, uint16_t *p_palette_job)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t palette_job = (uint16_t)*p_palette_job;
	uint8_t stack = 0;

	stack = request >> 8;
	request = (request & 0xFFu) | ((uint32_t)stack << 8);
	switch (palette_request_handlers[(int8_t)((uint8_t)((uint32_t)palette_request_kind << 1)) / 2])
	{
	case code_read_as_tiles_07BAEC_ADDRESS:
		palette_job = request_palette_sets(request);
		break;
	case 0xBB12u:
		palette_job = request_palette_effect_in_slot(palette_job, request);
		break;
	case 0xBB1Fu:
		palette_job = request_palette_effect(request);
		break;
	case 0xBB71u:
		palette_job = request_background_colour(request);
		break;
	case 0xBB85u:
		palette_job = request_palette_fade(request);
		break;
	case 0xBBF6u:
		request_white_flash(request, &y, &palette_job);
		break;
	case 0xBC78u:
		palette_job = request_palette_clear(request);
		break;
	}
	*p_y = y;
	*p_palette_job = palette_job;
}

/* Takes a free palette job for a load of palette sets: which of the set's loads and the set */
uint16_t request_palette_sets(uint16_t request)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	palette_request_word = request;
	find_free_palette_job(&u, &carry);
	if (carry == 0u)
	{
		palette_request_saved_bank = window_bank;
		mem_write8(u, 1u);
		t1 = palette_request_word;
		mem_write16(u + 1u, t1);
		window_bank = palette_request_saved_bank;
		set_lines(window_bank);
	}
	return u;
}

/* Starts a palette effect again in the caller's job when that job runs one, else in a new job */
uint16_t request_palette_effect_in_slot(uint16_t palette_job, uint16_t request)
{
	uint32_t carry = 0;
	uint8_t b = 0, delay = 0, job_kind = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	b = (uint8_t)request;
	palette_request_word = ((uint32_t)(request >> 8) << 8) | b;
	job_kind = io_read8(palette_job);
	if (job_kind != 2u)
	{
		request = ((uint32_t)job_kind << 8) | b;
		return request_palette_effect(request);
	}
	palette_request_saved_bank = window_bank;
	io_write8(palette_job, 2u);
	window_bank = 0x2Eu;
	set_lines(window_bank);
	mem_write8(palette_job + 1u, 0u);
	mem_write8(palette_job + 7u, 0u);
	t1 = palette_request_word;
	b = (uint8_t)t1;
	carry = (int8_t)b < 0;
	t2 = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1))) + 2u;
	mem_write8(palette_job + 6u, io_read8(t2));
	t3 = t2 + 1u;
	delay = mem_read8(t3);
	mem_write8(palette_job + 4u, delay);
	mem_write8(palette_job + 5u, delay);
	mem_write16(palette_job + 2u, t3 + 1u);
	window_bank = palette_request_saved_bank;
	set_lines(window_bank);
	return palette_job;
}

/* Takes a free palette job for a palette effect of bank 2E: its colours a step, its delay and its first
   step */
uint16_t request_palette_effect(uint16_t request)
{
	uint32_t carry = 0;
	uint8_t b = 0, delay = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	palette_request_word = request;
	find_free_palette_job(&u, &carry);
	if (carry == 0u)
	{
		palette_request_saved_bank = window_bank;
		mem_write8(u, 2u);
		window_bank = 0x2Eu;
		set_lines(window_bank);
		mem_write8(u + 1u, 0u);
		mem_write8(u + 7u, 0u);
		t1 = palette_request_word;
		b = (uint8_t)t1;
		carry = (int8_t)b < 0;
		t2 = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(t1 >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1))) + 2u;
		mem_write8(u + 6u, io_read8(t2));
		t3 = t2 + 1u;
		delay = mem_read8(t3);
		mem_write8(u + 4u, delay);
		mem_write8(u + 5u, delay);
		mem_write16(u + 2u, t3 + 1u);
		window_bank = palette_request_saved_bank;
		set_lines(window_bank);
	}
	return u;
}

/* Takes a free palette job to set the background colour */
uint16_t request_background_colour(uint16_t request)
{
	uint32_t carry = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	palette_request_word = request;
	find_free_palette_job(&u, &carry);
	if (carry == 0u)
	{
		mem_write8(u, 3u);
		t1 = palette_request_word;
		mem_write16(u + 1u, t1);
	}
	return u;
}

/* Takes a free palette job to darken (kind 4) or brighten (kind 5) the palette ranges the request's bits
   name */
uint16_t request_palette_fade(uint16_t request)
{
	uint32_t carry = 0;
	uint8_t fade_mask = 0, fade_mask_high = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	palette_request_word = request;
	find_free_palette_job(&u, &carry);
	if (carry)
		return u;
	mem_write8(u + 3u, 0u);
	mem_write8(u + 4u, palette_request_argument);
	mem_write8(u, palette_request_kind);
	palette_fade_ranges = 0u;
	if ((palette_request_bits & 0x10u) != 0u)
		palette_fade_ranges_high = 0x40u;
	if ((palette_request_bits & 8u) != 0u)
	{
		palette_fade_ranges_high |= 0x3Fu;
		palette_fade_ranges_low = 0xC0u;
	}
	if ((palette_request_bits & 4u) != 0u)
		palette_fade_ranges_low |= 0x30u;
	if ((palette_request_bits & 2u) != 0u)
		palette_fade_ranges_low |= 0xCu;
	if ((palette_request_bits & 1u) != 0u)
		palette_fade_ranges_low |= 3u;
	t1 = palette_fade_ranges;
	fade_mask = (uint8_t)t1;
	fade_mask_high = (uint8_t)(t1 >> 8);
	mem_write16(u + 1u, ((uint32_t)fade_mask_high << 8) | (fade_mask & 0xFFu));
	mem_write16(u + 5u, ((uint32_t)fade_mask_high << 8) | (fade_mask & 0xFFu));
	return u;
}

/* Takes a free palette job for a white flash: a palette bank turned white and the K053251's priorities
   that show it on the layers the request's bits name */
void request_white_flash(uint16_t request, uint16_t *p_words_left, uint16_t *p_u)
{
	uint16_t words_left = (uint16_t)*p_words_left;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, control = 0, layer_bits = 0, priority = 0;
	uint16_t colour_place = 0, u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	palette_request_word = request;
	find_free_palette_job(&u, &carry);
	if (carry == 0u)
	{
		control = board_control | 1u;
		board_control = control;
		io_write8(0x1FC2u, control);
		colour_place = 0xC00u;
		words_left = 0x100u;
		a = 0xFFu;
		b = 0xFFu;
		do
		{
			t1 = colour_place;
			colour_place = t1 + 2u;
			mem_write16(t1, ((uint32_t)a << 8) | b);
			t2 = words_left - 1u;
			words_left = t2;
		} while (t2 != 0u);
		control = board_control & ~3u;
		board_control = control;
		io_write8(0x1FC2u, control);
		white_flash_priorities = 0u;
		priority = 0x10u;
		layer_bits = palette_request_bits;
		if ((layer_bits & 1u) != 0u)
			priority = 0x30u;
		white_flash_priorities_high = priority;
		priority = 0u;
		if ((layer_bits & 8u) != 0u)
			priority = 0xCu;
		white_flash_priorities_high |= priority;
		priority = 0x28u;
		if ((layer_bits & 4u) != 0u)
			priority = 0x30u;
		white_flash_priorities_low = priority;
		priority = 4u;
		if ((layer_bits & 2u) != 0u)
			priority = 6u;
		white_flash_priorities_low |= priority;
		mem_write8(u, 6u);
		t3 = palette_request_word;
		mem_write16(u + 1u, t3);
		t4 = white_flash_priorities;
		mem_write16(u + 3u, t4);
	}
	*p_words_left = words_left;
	*p_u = u;
}

/* Takes a free palette job to clear the palette ranges the request's bits name */
uint16_t request_palette_clear(uint16_t request)
{
	uint32_t carry = 0;
	uint16_t u = 0;

	palette_request_bits = request >> 8;
	find_free_palette_job(&u, &carry);
	if (carry == 0u)
	{
		mem_write8(u + 1u, palette_request_bits);
		mem_write8(u, 7u);
	}
	return u;
}

/* Runs each of the 64 palette jobs that is in use, by its kind */
uint16_t run_palette_jobs(uint16_t y, uint16_t d)
{
	uint8_t job_kind = 0;
	uint16_t palette_job = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	palette_job = 0x3C00u;
	palette_jobs_left = 0x40u;
	do
	{
		t1 = mem_read8(palette_job);
		job_kind = t1;
		if (t1 != 0u)
		{
			stack = palette_job;
			switch ((int8_t)(uint8_t)((uint32_t)job_kind << 1))
			{
			case 0:
			case 2:
				palette_job_load_sets(palette_job, &y, &d);
				break;
			case 4:
				palette_job_effect(palette_job, &y, &d);
				break;
			case 6:
				d = palette_job_background_colour(palette_job);
				break;
			case 8:
				palette_job_darken(palette_job, &y, &d);
				break;
			case 10:
				palette_job_brighten(palette_job, &y, &d);
				break;
			case 12:
				palette_job_white_flash(palette_job, &y, &d);
				break;
			case 14:
				y = palette_job_clear(y, palette_job);
				break;
			}
			palette_job = stack;
		}
		palette_job += 8u;
		t2 = palette_jobs_left;
		palette_jobs_left = t2 - 1u;
	} while (t2 != 1u);
	return y;
}

/* Palette job 1: loads the set's palettes whose bits the job holds, and frees the job */
void palette_job_load_sets(uint16_t palette_job, uint16_t *p_palette_load, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint8_t load_bit = 0, set_number = 0;
	uint16_t d_2 = 0, destination = 0, palette_load = 0, set_table = 0, source = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, palettes = 0, t4 = 0;
	uint16_t destination_2 = 0;

	window_bank = 0x2Du;
	set_lines(window_bank);
	io_write8(palette_job, 0u);
	t1 = mem_read8(palette_job + 1u);
	palette_loads_wanted = t1;
	set_table = palette_sets_ADDRESS;
	t2 = mem_read8(palette_job + 2u);
	set_number = t2;
	if ((int8_t)t2 < 0)
	{
		set_table = palette_sets_high_ADDRESS;
		set_number &= 0x7Fu;
	}
	set_number = (uint32_t)set_number << 1;
	palette_load = PALETTE_SET(set_table + (int8_t)set_number);
	palette_loads_left = 4u;
	do
	{
		t3 = palette_loads_wanted & 1u;
		load_bit = t3;
		if (t3 != 0u)
		{
			source = PALETTE_LOAD(palette_load)->source;
			destination_2 = PALETTE_LOAD(palette_load)->destination;
			destination = destination_2;
			palettes = PALETTE_LOAD(palette_load)->palettes;
			d = (d & 0xFFu) | ((uint32_t)palettes << 8);
			d = load_palettes(destination, source, d);
			load_bit = (uint8_t)(d >> 8);
			set_number = (uint8_t)d;
		}
		palette_load += 5u;
		palette_loads_wanted = palette_loads_wanted >> 1;
		t4 = palette_loads_left;
		palette_loads_left = t4 - 1u;
	} while (t4 != 1u);
	d_2 = ((uint32_t)load_bit << 8) | set_number;
	*p_palette_load = palette_load;
	*p_d = d_2;
}

/* Palette job 2: after the effect's delay runs its next step, forward or backward, or the command the
   step holds */
void palette_job_effect(uint16_t palette_job, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, frames_waited = 0, step_mark = 0;
	uint16_t d_2 = 0, step = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, address = 0, t5 = 0;
	uint16_t t4 = 0;

	stack = d;
	window_bank = 0x2Eu;
	set_lines(window_bank);
	b = stack;
	t1 = mem_read8(palette_job + 4u);
	frames_waited = t1;
	t2 = mem_read8(palette_job + 5u);
	if (frames_waited != t2)
	{
		t3 = mem_read8(palette_job + 4u);
		mem_write8(palette_job + 4u, t3 + 1u);
		d_2 = ((uint32_t)frames_waited << 8) | b;
	}
	else
	{
		a = board_control | 1u;
		board_control = a;
		io_write8(0x1FC2u, a);
		mem_write8(palette_job + 4u, 0u);
		t4 = mem_read16(palette_job + 2u);
		step = t4;
		address = (uint8_t)(PALETTE_EFFECT_STEP(step)->address >> 8u);
		step_mark = address;
		if ((int8_t)address >= 0)
		{
			y = palette_effect_directions_ADDRESS;
			t5 = mem_read8(palette_job + 1u);
			a = (uint32_t)t5 << 1;
			left_caller = 0u;
			d_2 = ((uint32_t)a << 8) | b;
			switch ((int8_t)a)
			{
			case 0:
				palette_effect_forward(palette_job, &step, &y, &d_2);
				break;
			case 2:
				palette_effect_backward(palette_job, &step, &y, &d_2, &carry);
				break;
			case 4:
				carry = palette_effect_stop(palette_job);
				break;
			case 6:
				palette_effect_reverse(palette_job, &step, &carry);
				break;
			case 8:
				palette_effect_repeat(palette_job, &step, &carry);
				break;
			case 10:
				darken_colour(palette_job, &d_2, &carry);
				break;
			case 12:
				brighten_colour(palette_job, &d_2, &carry);
				break;
			case -76:
			case -4:
				stage_3_forest_end_phase_tail(&step, &y, &palette_job, &d_2, &left_caller, &carry);
				break;
			case -74:
			case -2:
				palette_effects_overrun();
				break;
			}
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
			if (left_caller != 0u)
				d_2 = ((uint32_t)a << 8) | b;
			else
			{
				stack = a;
				a = board_control & ~3u;
				board_control = a;
				io_write8(0x1FC2u, a);
				d_2 = ((uint32_t)stack << 8) | b;
			}
		}
		else
		{
			d_2 = ((uint32_t)step_mark << 8) | b;
			palette_effect_command(&step, &y, &palette_job, &d_2, &left_caller, &carry);
			a = (uint8_t)(d_2 >> 8);
			b = (uint8_t)d_2;
			if (left_caller != 0u)
				d_2 = ((uint32_t)a << 8) | b;
			else if (carry)
			{
				stack = a;
				a = board_control & ~3u;
				board_control = a;
				io_write8(0x1FC2u, a);
				d_2 = ((uint32_t)stack << 8) | b;
			}
			else
			{
				y = palette_effect_directions_ADDRESS;
				t5 = mem_read8(palette_job + 1u);
				a = (uint32_t)t5 << 1;
				left_caller = 0u;
				d_2 = ((uint32_t)a << 8) | b;
				switch ((int8_t)a)
				{
				case 0:
					palette_effect_forward(palette_job, &step, &y, &d_2);
					break;
				case 2:
					palette_effect_backward(palette_job, &step, &y, &d_2, &carry);
					break;
				case 4:
					carry = palette_effect_stop(palette_job);
					break;
				case 6:
					palette_effect_reverse(palette_job, &step, &carry);
					break;
				case 8:
					palette_effect_repeat(palette_job, &step, &carry);
					break;
				case 10:
					darken_colour(palette_job, &d_2, &carry);
					break;
				case 12:
					brighten_colour(palette_job, &d_2, &carry);
					break;
				case -76:
				case -4:
					stage_3_forest_end_phase_tail(&step, &y, &palette_job, &d_2, &left_caller, &carry);
					break;
				case -74:
				case -2:
					palette_effects_overrun();
					break;
				}
				a = (uint8_t)(d_2 >> 8);
				b = (uint8_t)d_2;
				if (left_caller != 0u)
					d_2 = ((uint32_t)a << 8) | b;
				else
				{
					stack = a;
					a = board_control & ~3u;
					board_control = a;
					io_write8(0x1FC2u, a);
					d_2 = ((uint32_t)stack << 8) | b;
				}
			}
		}
	}
	*p_y = y;
	*p_d = d_2;
}

/* Sets the colours of the effect's step and moves to the next step */
void palette_effect_forward(uint16_t palette_job, uint16_t *p_step, uint16_t *p_y, uint16_t *p_d)
{
	uint16_t step = (uint16_t)*p_step;
	uint8_t a = 0, colours_left = 0, d = 0;
	uint16_t address = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0, colour = 0;

	t1 = mem_read8(palette_job + 6u);
	palette_effect_colours_left = t1;
	for (;;)
	{
		t2 = step;
		address = PALETTE_EFFECT_STEP(t2)->address;
		t3 = t2 + 2u;
		step = t3 + 2u;
		colour = PALETTE_EFFECT_STEP(t3 - 0x2u)->colour;
		d = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (d & 0xFFu));
		t4 = palette_effect_colours_left;
		colours_left = t4;
		if (t4 == 0u)
			break;
		palette_effect_colours_left--;
	}
	mem_write16(palette_job + 2u, step);
	stack = colours_left;
	a = board_control & ~3u;
	board_control = a;
	io_write8(0x1FC2u, a);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_step = step;
	*p_y = address;
	*p_d = d_2;
}

/* Sets the colours of the effect's step and moves to the one before; at its first step the effect runs
   forward again */
void palette_effect_backward(uint16_t palette_job, uint16_t *p_step, uint16_t *p_y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t carry = *p_carry;
	uint8_t a = 0, d = 0, step_mark = 0;
	uint16_t address = 0, d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, address_2 = 0;
	uint16_t t2 = 0, t3 = 0, colour = 0;

	t1 = mem_read8(palette_job + 6u);
	palette_effect_colours_left = t1;
	for (;;)
	{
		t2 = step;
		address = PALETTE_EFFECT_STEP(t2)->address;
		t3 = t2 + 2u;
		step = t3 + 2u;
		colour = PALETTE_EFFECT_STEP(t3 - 0x2u)->colour;
		d = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (d & 0xFFu));
		if (palette_effect_colours_left == 0u)
			break;
		step -= 8u;
		palette_effect_colours_left--;
	}
	step -= 8u;
	address_2 = (uint8_t)(PALETTE_EFFECT_STEP(step)->address >> 8u);
	step_mark = address_2;
	if ((int8_t)address_2 < 0)
	{
		carry = 0u;
		mem_write8(palette_job + 1u, 0u);
		step += 4u;
	}
	mem_write16(palette_job + 2u, step);
	stack = step_mark;
	a = board_control & ~3u;
	board_control = a;
	io_write8(0x1FC2u, a);
	d_2 = (d & 0xFFu) | ((uint32_t)stack << 8);
	*p_step = step;
	*p_y = address;
	*p_d = d_2;
	*p_carry = carry;
}

/* Runs the command of an effect's step: stop, reverse or repeat */
void palette_effect_command(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u, uint16_t *p_d, uint32_t *p_left_caller, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t command = 0;
	uint16_t y = 0;
	uint32_t left_caller = 0;

	y = palette_effect_commands_ADDRESS;
	command = (d >> 8) & 0x7Fu;
	carry = (int8_t)command < 0;
	command = (uint32_t)command << 1;
	switch ((int8_t)command)
	{
	case 0:
		left_caller = 0u;
		carry = palette_effect_stop(u);
		break;
	case 2:
		left_caller = 0u;
		palette_effect_reverse(u, &x, &carry);
		break;
	case 4:
		left_caller = 0u;
		palette_effect_repeat(u, &x, &carry);
		break;
	case 6:
		left_caller = 0u;
		darken_colour(u, &d, &carry);
		break;
	case 8:
		left_caller = 0u;
		brighten_colour(u, &d, &carry);
		break;
	case -80:
	case -8:
		d = (d & 0xFFu) | ((uint32_t)command << 8);
		stage_3_forest_end_phase_tail(&x, &y, &u, &d, &left_caller, &carry);
		break;
	case -78:
	case -6:
		left_caller = 0u;
		d = (d & 0xFFu) | ((uint32_t)command << 8);
		palette_effects_overrun();
		break;
	case -4:
		left_caller = 0u;
		palette_effect_forward(u, &x, &y, &d);
		break;
	case -2:
		left_caller = 0u;
		palette_effect_backward(u, &x, &y, &d, &carry);
		break;
	}
	*p_x = x;
	*p_y = y;
	*p_u = u;
	*p_d = d;
	*p_left_caller = left_caller;
	*p_carry = carry;
}

/* An effect's command 80: the effect ends and its job is freed */
uint32_t palette_effect_stop(uint16_t palette_job)
{
	uint32_t carry = 0;

	io_write8(palette_job, 0u);
	carry = 1u;
	return carry;
}

/* An effect's command 81: the effect runs backward from its last step */
void palette_effect_reverse(uint16_t palette_job, uint16_t *p_step, uint32_t *p_carry)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t carry = *p_carry;

	mem_write8(palette_job + 1u, 1u);
	step -= 4u;
	mem_write16(palette_job + 2u, step);
	carry = 0u;
	*p_step = step;
	*p_carry = carry;
}

/* An effect's command 82: goes back to the step it names, the number of times it says (FF for ever),
   then on */
void palette_effect_repeat(uint16_t palette_job, uint16_t *p_step, uint32_t *p_carry)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t carry = *p_carry;
	uint8_t repeat_count = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(step + 1u);
	repeat_count = t1;
	if (repeat_count == 0xFFu)
	{
		t2 = mem_read16(step + 2u);
		step = t2 + 4u;
		mem_write16(palette_job + 2u, step);
		carry = 0u;
	}
	else
	{
		t3 = mem_read8(palette_job + 7u);
		if (repeat_count == t3)
		{
			mem_write8(palette_job + 7u, 0u);
			step += 4u;
			mem_write16(palette_job + 2u, step);
			carry = 0u;
		}
		else
		{
			t4 = mem_read8(palette_job + 7u);
			mem_write8(palette_job + 7u, t4 + 1u);
			t2 = mem_read16(step + 2u);
			step = t2 + 4u;
			mem_write16(palette_job + 2u, step);
			carry = 0u;
		}
	}
	*p_step = step;
	*p_carry = carry;
}

/* Palette job 3: sets the background colour and frees the job */
uint16_t palette_job_background_colour(uint16_t palette_job)
{
	uint8_t colour_high = 0, colour_low = 0, control = 0;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(0x1FC2u, control);
	t1 = mem_read16(palette_job + 1u);
	colour_low = (uint8_t)t1;
	colour_high = (uint8_t)(t1 >> 8);
	io_write16(0xC00u, ((uint32_t)colour_high << 8) | (colour_low & 0xFFu));
	io_write8(palette_job, 0u);
	stack = colour_high;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	d = (colour_low & 0xFFu) | ((uint32_t)stack << 8);
	return d;
}

/* Palette job 4: a step of a fade to dark */
void palette_job_darken(uint16_t palette_job, uint16_t *p_y, uint16_t *p_frames_left)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t frames_left = 0;
	uint16_t t1 = 0;

	palette_fade_brightens = 0u;
	t1 = mem_read16(palette_job + 3u);
	frames_left = t1;
	if (t1 == 0u)
		io_write8(palette_job, 0u);
	else
		palette_job_fade(palette_job, &y, &frames_left);
	*p_y = y;
	*p_frames_left = frames_left;
}

/* Palette job 5: a step of a fade to bright */
void palette_job_brighten(uint16_t palette_job, uint16_t *p_y, uint16_t *p_fade_mask)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t fade_mask = (uint16_t)*p_fade_mask;

	palette_fade_brightens = 1u;
	*p_y = y;
	*p_fade_mask = fade_mask;
	palette_job_fade(palette_job, p_y, p_fade_mask);
}

/* A step of a fade: each colour of the step's palette range darkened or brightened by one when the job's
   mask names it; the job ends when its frames run out */
void palette_job_fade(uint16_t palette_job, uint16_t *p_y, uint16_t *p_fade_mask)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t fade_mask = (uint16_t)*p_fade_mask;
	uint32_t carry = 0;
	uint8_t a = 0, control = 0, step_bit = 0;
	uint16_t colour_place = 0, fade_range = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t10 = 0;
	uint16_t t1 = 0, t3 = 0, t6 = 0, t9 = 0;

	t1 = mem_read16(palette_job + 3u);
	mem_write16(palette_job + 3u, t1 - 1u);
	t2 = mem_read8(palette_job + 7u);
	if (t2 == 0x10u)
	{
		t3 = mem_read16(palette_job + 1u);
		fade_mask = t3;
		mem_write16(palette_job + 5u, ((uint32_t)(t3 >> 8) << 8) | (fade_mask & 0xFFu));
		mem_write8(palette_job + 7u, 0u);
	}
	t4 = mem_read8(palette_job + 6u);
	t5 = t4 & 1u;
	step_bit = t5;
	if (t5 == 0u)
	{
		t6 = mem_read16(palette_job + 5u);
		mem_write16(palette_job + 5u, t6 >> 1);
		t7 = mem_read8(palette_job + 7u);
		mem_write8(palette_job + 7u, t7 + 1u);
		stack = step_bit;
		control = board_control & ~3u;
		board_control = control;
		io_write8(0x1FC2u, control);
		fade_mask = (fade_mask & 0xFFu) | ((uint32_t)stack << 8);
	}
	else
	{
		stack_2 = palette_job >> 8;
		stack = (uint8_t)palette_job;
		control = board_control | 1u;
		board_control = control;
		io_write8(0x1FC2u, control);
		t8 = mem_read8(palette_job + 7u);
		t9 = fade_ranges_ADDRESS + (int8_t)(((uint32_t)t8 << 1) << 1);
		fade_range = t9 + 1u;
		palette_fade_colours_left = FADE_RANGE(t9)->colours;
		colour_place = FADE_RANGE(fade_range - 0x1u)->address;
		for (;;)
		{
			y = palette_fade_directions_ADDRESS;
			a = (uint32_t)palette_fade_brightens << 1;
			left_caller = 0u;
			fade_mask = (fade_mask & 0xFFu) | ((uint32_t)a << 8);
			switch ((int8_t)a)
			{
			case 0:
				darken_colour(colour_place, &fade_mask, &carry);
				break;
			case 2:
				brighten_colour(colour_place, &fade_mask, &carry);
				break;
			case -86:
			case -14:
				stage_3_forest_end_phase_tail(&fade_range, &y, &colour_place, &fade_mask, &left_caller, &carry);
				break;
			case -84:
			case -12:
				palette_effects_overrun();
				break;
			case -10:
				palette_effect_forward(colour_place, &fade_range, &y, &fade_mask);
				break;
			case -8:
				palette_effect_backward(colour_place, &fade_range, &y, &fade_mask, &carry);
				break;
			case -6:
				carry = palette_effect_stop(colour_place);
				break;
			case -4:
				palette_effect_reverse(colour_place, &fade_range, &carry);
				break;
			case -2:
				palette_effect_repeat(colour_place, &fade_range, &carry);
				break;
			}
			step_bit = (uint8_t)(fade_mask >> 8);
			if (left_caller != 0u)
				break;
			colour_place += 2u;
			t10 = palette_fade_colours_left;
			palette_fade_colours_left = t10 - 1u;
			if (t10 == 1u)
			{
				palette_job = ((uint32_t)stack_2 << 8) | stack;
				t6 = mem_read16(palette_job + 5u);
				mem_write16(palette_job + 5u, t6 >> 1);
				t7 = mem_read8(palette_job + 7u);
				mem_write8(palette_job + 7u, t7 + 1u);
				stack = step_bit;
				control = board_control & ~3u;
				board_control = control;
				io_write8(0x1FC2u, control);
				fade_mask = (fade_mask & 0xFFu) | ((uint32_t)stack << 8);
				break;
			}
		}
	}
	*p_y = y;
	*p_fade_mask = fade_mask;
}

/* Palette job 6: the white flash every other frame for its frames, then the white palette bank cleared
   and the job freed */
void palette_job_white_flash(uint16_t palette_job, uint16_t *p_words_left, uint16_t *p_d)
{
	uint16_t words_left = (uint16_t)*p_words_left;
	uint8_t d = (uint8_t)*p_d;
	uint8_t a = 0, control = 0, priority = 0;
	uint16_t colour_place = 0, d_2 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(palette_job + 2u);
	mem_write8(palette_job + 2u, t1 - 1u);
	if (t1 == 1u)
	{
		control = board_control | 1u;
		board_control = control;
		io_write8(0x1FC2u, control);
		colour_place = 0xC00u;
		words_left = 0x100u;
		d = 0u;
		a = 0u;
		do
		{
			t2 = colour_place;
			colour_place = t2 + 2u;
			mem_write16(t2, (uint32_t)a << 8);
			t3 = words_left - 1u;
			words_left = t3;
		} while (t3 != 0u);
		control = board_control & ~3u;
		board_control = control;
		io_write8(0x1FC2u, control);
		io_write8(palette_job, 0u);
		io_write8(0x1FB9u, 0x13u);
		priority = 0x2Cu;
		io_write8(0x1FBAu, 0x2Cu);
	}
	else if ((frame_count & 1u) == 0u)
	{
		t4 = mem_read8(palette_job + 3u);
		io_write8(0x1FB9u, t4);
		t5 = mem_read8(palette_job + 4u);
		priority = t5;
		io_write8(0x1FBAu, priority);
	}
	else
	{
		io_write8(0x1FB9u, 0x13u);
		priority = 0x2Cu;
		io_write8(0x1FBAu, 0x2Cu);
	}
	d_2 = (d & 0xFFu) | ((uint32_t)priority << 8);
	*p_words_left = words_left;
	*p_d = d_2;
}

/* Palette job 7: clears the palette ranges whose bits the job holds, and frees the job */
uint16_t palette_job_clear(uint16_t y, uint16_t palette_job)
{
	uint8_t control = 0;
	uint16_t address = 0, clear_to = 0, count = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(0x1FC2u, control);
	io_write8(palette_job, 0u);
	palette_clear_range = 0u;
	t1 = mem_read8(palette_job + 1u);
	palette_clear_bits = t1;
	do
	{
		if ((palette_clear_bits & 1u) != 0u)
		{
			t2 = palette_clears_ADDRESS + (int8_t)(((uint32_t)palette_clear_range << 1) << 1);
			count = PALETTE_CLEAR(t2)->extra_bytes;
			address = PALETTE_CLEAR(t2)->address;
			y = address;
			t3 = address;
			clear_to = t3 + 1u;
			mem_write8(t3, 0u);
			while (count != 0u)
			{
				mem_write8(clear_to, mem_read8(y));
				y++;
				clear_to++;
				count--;
			}
		}
		palette_clear_bits = palette_clear_bits >> 1;
		palette_clear_range++;
	} while (palette_clear_range != 4u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return y;
}

/* Finds a free palette job among the 64; carry when there is none */
void find_free_palette_job(uint16_t *p_palette_job, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t palette_job = 0;
	uint8_t t1 = 0;

	palette_job = 0x3C00u;
	palette_jobs_left = 0x40u;
	for (;;)
	{
		if (mem_read8(palette_job) == 0u)
		{
			carry = 0u;
			break;
		}
		palette_job += 8u;
		t1 = palette_jobs_left;
		palette_jobs_left = t1 - 1u;
		if (t1 == 1u)
		{
			carry = 1u;
			break;
		}
	}
	*p_palette_job = palette_job;
	*p_carry = carry;
}

/* Copies palettes of 16 colours from bank 2D into the palette RAM */
uint16_t load_palettes(uint16_t destination, uint16_t source, uint16_t palette_count)
{
	uint8_t colour_high = 0, colour_low = 0, control = 0;
	uint8_t stack = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	stack = palette_count >> 8;
	control = board_control | 1u;
	board_control = control;
	io_write8(0x1FC2u, control);
	window_bank = 0x2Du;
	set_lines(window_bank);
	palettes_to_load = stack;
	do
	{
		palette_colours_left = 0x10u;
		do
		{
			t1 = source;
			source = t1 + 2u;
			t2 = mem_read16(t1);
			colour_high = (uint8_t)(t2 >> 8);
			colour_low = (uint8_t)t2;
			t3 = destination;
			destination = t3 + 2u;
			mem_write16(t3, ((uint32_t)colour_high << 8) | colour_low);
			t4 = palette_colours_left;
			palette_colours_left = t4 - 1u;
		} while (t4 != 1u);
		t5 = palettes_to_load;
		palettes_to_load = t5 - 1u;
	} while (t5 != 1u);
	stack = colour_high;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	palette_count = ((uint32_t)stack << 8) | colour_low;
	return palette_count;
}

/* Takes one step off each component of a colour that is not at 0 */
void darken_colour(uint16_t colour_place, uint16_t *p_colour, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t colour_high = 0;
	uint16_t colour = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	fade_steps = 0u;
	t1 = io_read16(colour_place);
	colour_high = (uint8_t)(t1 >> 8);
	fade_colour = ((uint32_t)colour_high << 8) | (t1 & 0xFFu);
	if ((colour_high & ~7u) != 0u)
		fade_steps_high = 8u;
	if ((fade_colour_high & 3u) != 0u || (fade_colour_low & 0xC0u) != 0u)
		fade_steps_low = 0x40u;
	if ((fade_colour_low & 0x1Eu) != 0u)
		fade_steps_low |= 2u;
	t2 = fade_colour;
	t3 = fade_steps;
	t4 = t2;
	t5 = t4 - t3;
	carry = t4 < t3;
	colour = t5;
	io_write16(colour_place, ((uint32_t)(t5 >> 8) << 8) | (colour & 0xFFu));
	*p_colour = colour;
	*p_carry = carry;
}

/* Adds one step to each component of a colour that is not at its top */
void brighten_colour(uint16_t colour_place, uint16_t *p_colour, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t colour_high = 0;
	uint16_t colour = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	fade_steps = 0u;
	t1 = io_read16(colour_place);
	colour_high = (uint8_t)(t1 >> 8);
	fade_colour = ((uint32_t)colour_high << 8) | (t1 & 0xFFu);
	if ((colour_high & 0x78u) != 0x78u)
		fade_steps_high = 4u;
	if ((fade_colour_high & 3u) != 3u || (fade_colour_low & 0xC0u) != 0xC0u)
		fade_steps_low = 0x20u;
	if ((fade_colour_low & 0x1Eu) != 0x1Eu)
		fade_steps_low |= 1u;
	t2 = fade_colour;
	t3 = fade_steps;
	t4 = t2;
	t5 = t4 + t3;
	carry = (uint16_t)(t4 + t3) < t4;
	colour = t5;
	io_write16(colour_place, ((uint32_t)(t5 >> 8) << 8) | (colour & 0xFFu));
	*p_colour = colour;
	*p_carry = carry;
}
