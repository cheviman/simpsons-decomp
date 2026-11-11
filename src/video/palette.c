/**
 *    Name:        video/palette.c
 *    Description: the palette requests and the palette jobs that run them a frame at a time
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
uint16_t palette_request(uint16_t palette_job, uint16_t request)
{
	uint8_t saved_request_high = 0;

	saved_request_high = request >> 8;
	request = (request & 0xFFu) | ((uint32_t)saved_request_high << 8);
	switch (palette_request_handlers[(int8_t)((uint8_t)((uint32_t)palette_request_kind << 1)) / 2])
	{
	case request_palette_sets_as_code_read_as_tiles_ADDRESS:
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
		palette_job = request_white_flash(request);
		break;
	case 0xBC78u:
		palette_job = request_palette_clear(request);
		break;
	}
	return palette_job;
}

/* Takes a free palette job for a load of palette sets: which of the set's loads and the set */
uint16_t request_palette_sets(uint16_t request)
{
	uint32_t no_free_job = 0;
	uint16_t palette_job = 0;
	uint16_t loads_and_set = 0;

	palette_request_word = request;
	find_free_palette_job(&palette_job, &no_free_job);
	if (no_free_job == 0u)
	{
		palette_request_saved_bank = window_bank;
		PALETTE_JOB(palette_job)->kind = 1u;
		loads_and_set = palette_request_word;
		PALETTE_JOB(palette_job)->sets.loads = (uint8_t)(loads_and_set >> 8u);
		PALETTE_JOB(palette_job)->sets.set = (uint8_t)loads_and_set;
		window_bank = palette_request_saved_bank;
		set_lines(window_bank);
	}
	return palette_job;
}

/* Starts a palette effect again in the caller's job when that job runs one, else in a new job */
uint16_t request_palette_effect_in_slot(uint16_t palette_job, uint16_t request)
{
	uint32_t carry = 0;
	uint8_t delay = 0, effect_low = 0, job_kind = 0;
	uint16_t effect_number = 0, extra_colours_at = 0, delay_at = 0;

	effect_low = (uint8_t)request;
	palette_request_word = ((uint32_t)(request >> 8) << 8) | effect_low;
	job_kind = PALETTE_JOB(palette_job)->kind;
	if (job_kind != 2u)
	{
		request = ((uint32_t)job_kind << 8) | effect_low;
		return request_palette_effect(request);
	}
	palette_request_saved_bank = window_bank;
	PALETTE_JOB(palette_job)->kind = 2u;
	window_bank = 0x2Eu;
	set_lines(window_bank);
	PALETTE_JOB(palette_job)->effect.direction = 0u;
	PALETTE_JOB(palette_job)->effect.repeats = 0u;
	effect_number = palette_request_word;
	effect_low = (uint8_t)effect_number;
	carry = (int8_t)effect_low < 0;
	extra_colours_at = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(effect_number >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)effect_low << 1))) + 2u;
	PALETTE_JOB(palette_job)->effect.extra_colours = io_read8(extra_colours_at);
	delay_at = extra_colours_at + 1u;
	delay = mem_read8(delay_at);
	PALETTE_JOB(palette_job)->effect.frames_waited = delay;
	PALETTE_JOB(palette_job)->effect.delay = delay;
	PALETTE_JOB(palette_job)->effect.step = delay_at + 1u;
	window_bank = palette_request_saved_bank;
	set_lines(window_bank);
	return palette_job;
}

/* Takes a free palette job for a palette effect of bank 2E: its colours a step, its delay and its first
   step */
uint16_t request_palette_effect(uint16_t request)
{
	uint32_t carry = 0;
	uint8_t delay = 0, effect_low = 0;
	uint16_t palette_job = 0;
	uint16_t effect_number = 0, extra_colours_at = 0, delay_at = 0;

	palette_request_word = request;
	find_free_palette_job(&palette_job, &carry);
	if (carry == 0u)
	{
		palette_request_saved_bank = window_bank;
		PALETTE_JOB(palette_job)->kind = 2u;
		window_bank = 0x2Eu;
		set_lines(window_bank);
		PALETTE_JOB(palette_job)->effect.direction = 0u;
		PALETTE_JOB(palette_job)->effect.repeats = 0u;
		effect_number = palette_request_word;
		effect_low = (uint8_t)effect_number;
		carry = (int8_t)effect_low < 0;
		extra_colours_at = TABLE16(palette_effects, (uint16_t)(((uint32_t)(uint8_t)(((uint32_t)(effect_number >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)effect_low << 1))) + 2u;
		PALETTE_JOB(palette_job)->effect.extra_colours = io_read8(extra_colours_at);
		delay_at = extra_colours_at + 1u;
		delay = mem_read8(delay_at);
		PALETTE_JOB(palette_job)->effect.frames_waited = delay;
		PALETTE_JOB(palette_job)->effect.delay = delay;
		PALETTE_JOB(palette_job)->effect.step = delay_at + 1u;
		window_bank = palette_request_saved_bank;
		set_lines(window_bank);
	}
	return palette_job;
}

/* Takes a free palette job to set the background colour */
uint16_t request_background_colour(uint16_t request)
{
	uint32_t no_free_job = 0;
	uint16_t palette_job = 0;
	uint16_t background_colour = 0;

	palette_request_word = request;
	find_free_palette_job(&palette_job, &no_free_job);
	if (no_free_job == 0u)
	{
		PALETTE_JOB(palette_job)->kind = 3u;
		background_colour = palette_request_word;
		PALETTE_JOB(palette_job)->background.colour = background_colour;
	}
	return palette_job;
}

/* Takes a free palette job to darken (kind 4) or brighten (kind 5) the palette ranges the request's bits
   name */
uint16_t request_palette_fade(uint16_t request)
{
	uint32_t no_free_job = 0;
	uint8_t fade_mask = 0, fade_mask_high = 0;
	uint16_t palette_job = 0;
	uint16_t ranges_mask = 0;

	palette_request_word = request;
	find_free_palette_job(&palette_job, &no_free_job);
	if (no_free_job)
		return palette_job;
	PALETTE_JOB(palette_job)->fade.frames_left &= 0xFFu;
	PALETTE_JOB(palette_job)->fade.frames_left = (PALETTE_JOB(palette_job)->fade.frames_left & 0xFF00u) | (palette_request_argument & 0xFFu);
	PALETTE_JOB(palette_job)->kind = palette_request_kind;
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
	ranges_mask = palette_fade_ranges;
	fade_mask = (uint8_t)ranges_mask;
	fade_mask_high = (uint8_t)(ranges_mask >> 8);
	PALETTE_JOB(palette_job)->fade.ranges = ((uint32_t)fade_mask_high << 8) | (fade_mask & 0xFFu);
	PALETTE_JOB(palette_job)->fade.ranges_left = ((uint32_t)fade_mask_high << 8) | (fade_mask & 0xFFu);
	return palette_job;
}

/* Takes a free palette job for a white flash: a palette bank turned white and the K053251's priorities
   that show it on the layers the request's bits name */
uint16_t request_white_flash(uint16_t request)
{
	uint32_t no_free_job = 0;
	uint8_t control = 0, layer_bits = 0, priority = 0, white_high = 0, white_low = 0;
	uint16_t colour_place = 0, palette_job = 0, words_left = 0;
	uint16_t white_place = 0, words_after = 0, flash_request = 0, flash_priorities = 0;

	palette_request_word = request;
	find_free_palette_job(&palette_job, &no_free_job);
	if (no_free_job)
		return palette_job;
	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	colour_place = 0xC00u;
	words_left = 0x100u;
	white_high = 0xFFu;
	white_low = 0xFFu;
	do
	{
		white_place = colour_place;
		colour_place = white_place + 2u;
		mem_write16(white_place, ((uint32_t)white_high << 8) | white_low);
		words_after = words_left - 1u;
		words_left = words_after;
		leftover_y = words_left;
	} while (words_after != 0u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
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
	PALETTE_JOB(palette_job)->kind = 6u;
	flash_request = palette_request_word;
	PALETTE_JOB(palette_job)->flash.flash_layers = (uint8_t)(flash_request >> 8u);
	PALETTE_JOB(palette_job)->flash.frames_left = (uint8_t)flash_request;
	flash_priorities = white_flash_priorities;
	PALETTE_JOB(palette_job)->flash.k053251_9 = (uint8_t)(flash_priorities >> 8u);
	PALETTE_JOB(palette_job)->flash.k053251_10 = (uint8_t)flash_priorities;
	return palette_job;
}

/* Takes a free palette job to clear the palette ranges the request's bits name */
uint16_t request_palette_clear(uint16_t request)
{
	uint32_t no_free_job = 0;
	uint16_t palette_job = 0;

	palette_request_bits = request >> 8;
	find_free_palette_job(&palette_job, &no_free_job);
	if (no_free_job == 0u)
	{
		PALETTE_JOB(palette_job)->clearing.ranges = palette_request_bits;
		PALETTE_JOB(palette_job)->kind = 7u;
	}
	return palette_job;
}

/* Runs each of the 64 palette jobs that is in use, by its kind */
void run_palette_jobs(uint16_t d)
{
	uint8_t job_kind = 0;
	uint16_t palette_job = 0;
	uint16_t saved_job = 0;
	uint8_t slot_kind = 0, jobs_left_was = 0;

	palette_job = palette_jobs;
	palette_jobs_left = 0x40u;
	do
	{
		slot_kind = PALETTE_JOB(palette_job)->kind;
		job_kind = slot_kind;
		if (slot_kind != 0u)
		{
			saved_job = palette_job;
			switch ((int8_t)(uint8_t)((uint32_t)job_kind << 1))
			{
			case 0:
			case 2:
				d = palette_job_load_sets(palette_job);
				break;
			case 4:
				d = palette_job_effect(palette_job, (uint8_t)d);
				break;
			case 6:
				d = palette_job_background_colour(palette_job);
				break;
			case 8:
				d = palette_job_darken(palette_job);
				break;
			case 10:
				d = palette_job_brighten(palette_job, d);
				break;
			case 12:
				d = palette_job_white_flash(palette_job, (uint8_t)d);
				break;
			case 14:
				palette_job_clear(palette_job);
				break;
			}
			palette_job = saved_job;
		}
		palette_job += 8u;
		jobs_left_was = palette_jobs_left;
		palette_jobs_left = jobs_left_was - 1u;
	} while (jobs_left_was != 1u);
}

/* Palette job 1: loads the set's palettes whose bits the job holds, and frees the job */
uint16_t palette_job_load_sets(uint16_t palette_job)
{
	uint8_t load_bit = 0, set_number = 0;
	uint16_t d = 0, destination = 0, palette_load = 0, set_table = 0, source = 0;
	uint8_t wanted_loads = 0, job_set = 0, wanted_bit = 0, palettes = 0, loads_left_was = 0;
	uint16_t destination_2 = 0;

	window_bank = 0x2Du;
	set_lines(window_bank);
	PALETTE_JOB(palette_job)->kind = 0u;
	wanted_loads = PALETTE_JOB(palette_job)->sets.loads;
	palette_loads_wanted = wanted_loads;
	set_table = palette_sets_ADDRESS;
	job_set = PALETTE_JOB(palette_job)->sets.set;
	set_number = job_set;
	if ((int8_t)job_set < 0)
	{
		set_table = palette_sets_high_ADDRESS;
		set_number &= 0x7Fu;
	}
	set_number = (uint32_t)set_number << 1;
	palette_load = PALETTE_SET(set_table + (int8_t)set_number);
	palette_loads_left = 4u;
	do
	{
		wanted_bit = palette_loads_wanted & 1u;
		load_bit = wanted_bit;
		if (wanted_bit != 0u)
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
		loads_left_was = palette_loads_left;
		palette_loads_left = loads_left_was - 1u;
	} while (loads_left_was != 1u);
	leftover_y = palette_load;
	d = ((uint32_t)load_bit << 8) | set_number;
	return d;
}

/* Palette job 2: after the effect's delay runs its next step, forward or backward, or the command the
   step holds */
uint16_t palette_job_effect(uint16_t palette_job, uint8_t d)
{
	uint32_t effect_ended = 0;
	uint8_t a = 0, b = 0, frames_waited = 0, step_mark = 0;
	uint16_t d_2 = 0, step = 0;
	uint32_t left_caller = 0;
	uint8_t kept_byte = 0;
	uint8_t frames_waited_now = 0, effect_delay = 0, frames_waited_was = 0, address = 0, effect_direction = 0;
	uint16_t effect_step = 0;

	kept_byte = d;
	window_bank = 0x2Eu;
	set_lines(window_bank);
	b = kept_byte;
	frames_waited_now = PALETTE_JOB(palette_job)->effect.frames_waited;
	frames_waited = frames_waited_now;
	effect_delay = PALETTE_JOB(palette_job)->effect.delay;
	if (frames_waited != effect_delay)
	{
		frames_waited_was = PALETTE_JOB(palette_job)->effect.frames_waited;
		PALETTE_JOB(palette_job)->effect.frames_waited = frames_waited_was + 1u;
		d_2 = ((uint32_t)frames_waited << 8) | b;
		return d_2;
	}
	a = board_control | 1u;
	board_control = a;
	io_write8(board_control_register, a);
	PALETTE_JOB(palette_job)->effect.frames_waited = 0u;
	effect_step = PALETTE_JOB(palette_job)->effect.step;
	step = effect_step;
	address = (uint8_t)(PALETTE_EFFECT_STEP(step)->address >> 8u);
	step_mark = address;
	if ((int8_t)address >= 0)
	{
		leftover_y = palette_effect_directions_ADDRESS;
		effect_direction = PALETTE_JOB(palette_job)->effect.direction;
		a = (uint32_t)effect_direction << 1;
		left_caller = 0u;
		d_2 = ((uint32_t)a << 8) | b;
		switch ((int8_t)a)
		{
		case 0:
			palette_effect_forward(palette_job, &step, &d_2);
			break;
		case 2:
			palette_effect_backward(palette_job, &step, &d_2, &effect_ended);
			break;
		case 4:
			palette_effect_stop(palette_job);
			break;
		case 6:
			palette_effect_reverse(palette_job, &step, &effect_ended);
			break;
		case 8:
			palette_effect_repeat(palette_job, &step, &effect_ended);
			break;
		case 10:
			darken_colour(palette_job, &d_2, &effect_ended);
			break;
		case 12:
			brighten_colour(palette_job, &d_2, &effect_ended);
			break;
		case -76:
		case -4:
			stage_3_forest_end_phase_tail(&step, &palette_job, &d_2, &left_caller, &effect_ended);
			break;
		case -74:
		case -2:
			palette_effects_overrun();
			break;
		}
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		if (left_caller != 0u)
		{
			d_2 = ((uint32_t)a << 8) | b;
			return d_2;
		}
		kept_byte = a;
		a = board_control & ~3u;
		board_control = a;
		io_write8(board_control_register, a);
		d_2 = ((uint32_t)kept_byte << 8) | b;
		return d_2;
	}
	d_2 = ((uint32_t)step_mark << 8) | b;
	palette_effect_command(&step, &palette_job, &d_2, &left_caller, &effect_ended);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	if (left_caller != 0u)
	{
		d_2 = ((uint32_t)a << 8) | b;
		return d_2;
	}
	if (effect_ended)
	{
		kept_byte = a;
		a = board_control & ~3u;
		board_control = a;
		io_write8(board_control_register, a);
		d_2 = ((uint32_t)kept_byte << 8) | b;
		return d_2;
	}
	leftover_y = palette_effect_directions_ADDRESS;
	effect_direction = PALETTE_JOB(palette_job)->effect.direction;
	a = (uint32_t)effect_direction << 1;
	left_caller = 0u;
	d_2 = ((uint32_t)a << 8) | b;
	switch ((int8_t)a)
	{
	case 0:
		palette_effect_forward(palette_job, &step, &d_2);
		break;
	case 2:
		palette_effect_backward(palette_job, &step, &d_2, &effect_ended);
		break;
	case 4:
		palette_effect_stop(palette_job);
		break;
	case 6:
		palette_effect_reverse(palette_job, &step, &effect_ended);
		break;
	case 8:
		palette_effect_repeat(palette_job, &step, &effect_ended);
		break;
	case 10:
		darken_colour(palette_job, &d_2, &effect_ended);
		break;
	case 12:
		brighten_colour(palette_job, &d_2, &effect_ended);
		break;
	case -76:
	case -4:
		stage_3_forest_end_phase_tail(&step, &palette_job, &d_2, &left_caller, &effect_ended);
		break;
	case -74:
	case -2:
		palette_effects_overrun();
		break;
	}
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	if (left_caller != 0u)
	{
		d_2 = ((uint32_t)a << 8) | b;
		return d_2;
	}
	kept_byte = a;
	a = board_control & ~3u;
	board_control = a;
	io_write8(board_control_register, a);
	d_2 = ((uint32_t)kept_byte << 8) | b;
	return d_2;
}

/* Sets the colours of the effect's step and moves to the next step */
void palette_effect_forward(uint16_t palette_job, uint16_t *p_step, uint16_t *p_d)
{
	uint16_t step = (uint16_t)*p_step;
	uint8_t colour_low = 0, colours_left = 0, control = 0;
	uint16_t address = 0, d = 0;
	uint8_t saved_step_mark = 0;
	uint8_t step_extra_colours = 0, more_colours = 0;
	uint16_t step_at = 0, colour_at = 0, colour = 0;

	step_extra_colours = PALETTE_JOB(palette_job)->effect.extra_colours;
	palette_effect_colours_left = step_extra_colours;
	for (;;)
	{
		step_at = step;
		address = PALETTE_EFFECT_STEP(step_at)->address;
		colour_at = step_at + 2u;
		step = colour_at + 2u;
		colour = PALETTE_EFFECT_STEP(colour_at - 0x2u)->colour;
		colour_low = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (colour_low & 0xFFu));
		more_colours = palette_effect_colours_left;
		colours_left = more_colours;
		if (more_colours == 0u)
			break;
		palette_effect_colours_left--;
	}
	PALETTE_JOB(palette_job)->effect.step = step;
	saved_step_mark = colours_left;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	leftover_y = address;
	d = (colour_low & 0xFFu) | ((uint32_t)saved_step_mark << 8);
	*p_step = step;
	*p_d = d;
}

/* Sets the colours of the effect's step and moves to the one before; at its first step the effect runs
   forward again */
void palette_effect_backward(uint16_t palette_job, uint16_t *p_step, uint16_t *p_d, uint32_t *p_effect_ended)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t effect_ended = *p_effect_ended;
	uint8_t colour_low = 0, control = 0, step_mark = 0;
	uint16_t address = 0, d = 0;
	uint8_t saved_step_mark = 0;
	uint8_t step_extra_colours = 0, address_2 = 0;
	uint16_t step_at = 0, colour_at = 0, colour = 0;

	step_extra_colours = PALETTE_JOB(palette_job)->effect.extra_colours;
	palette_effect_colours_left = step_extra_colours;
	for (;;)
	{
		step_at = step;
		address = PALETTE_EFFECT_STEP(step_at)->address;
		colour_at = step_at + 2u;
		step = colour_at + 2u;
		colour = PALETTE_EFFECT_STEP(colour_at - 0x2u)->colour;
		colour_low = (uint8_t)colour;
		mem_write16(address, ((uint32_t)(colour >> 8) << 8) | (colour_low & 0xFFu));
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
		effect_ended = 0u;
		PALETTE_JOB(palette_job)->effect.direction = 0u;
		step += 4u;
	}
	PALETTE_JOB(palette_job)->effect.step = step;
	saved_step_mark = step_mark;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	leftover_y = address;
	d = (colour_low & 0xFFu) | ((uint32_t)saved_step_mark << 8);
	*p_step = step;
	*p_d = d;
	*p_effect_ended = effect_ended;
}

/* Runs the command of an effect's step: stop, reverse or repeat */
void palette_effect_command(uint16_t *p_x, uint16_t *p_u, uint16_t *p_d, uint32_t *p_left_caller, uint32_t *p_effect_ended)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint32_t effect_ended = *p_effect_ended;
	uint8_t command = 0;
	uint16_t y = 0;
	uint32_t left_caller = 0;

	y = palette_effect_commands_ADDRESS;
	command = (d >> 8) & 0x7Fu;
	effect_ended = (int8_t)command < 0;
	command = (uint32_t)command << 1;
	switch ((int8_t)command)
	{
	case 0:
		left_caller = 0u;
		leftover_y = y;
		effect_ended = palette_effect_stop(u);
		break;
	case 2:
		left_caller = 0u;
		leftover_y = y;
		palette_effect_reverse(u, &x, &effect_ended);
		break;
	case 4:
		left_caller = 0u;
		leftover_y = y;
		palette_effect_repeat(u, &x, &effect_ended);
		break;
	case 6:
		left_caller = 0u;
		leftover_y = y;
		darken_colour(u, &d, &effect_ended);
		break;
	case 8:
		left_caller = 0u;
		leftover_y = y;
		brighten_colour(u, &d, &effect_ended);
		break;
	case -80:
	case -8:
		d = (d & 0xFFu) | ((uint32_t)command << 8);
		stage_3_forest_end_phase_tail(&x, &u, &d, &left_caller, &effect_ended);
		break;
	case -78:
	case -6:
		left_caller = 0u;
		leftover_y = y;
		d = (d & 0xFFu) | ((uint32_t)command << 8);
		palette_effects_overrun();
		break;
	case -4:
		left_caller = 0u;
		palette_effect_forward(u, &x, &d);
		break;
	case -2:
		left_caller = 0u;
		palette_effect_backward(u, &x, &d, &effect_ended);
		break;
	}
	*p_x = x;
	*p_u = u;
	*p_d = d;
	*p_left_caller = left_caller;
	*p_effect_ended = effect_ended;
}

/* An effect's command 80: the effect ends and its job is freed */
uint32_t palette_effect_stop(uint16_t palette_job)
{
	uint32_t effect_ended = 0;

	PALETTE_JOB(palette_job)->kind = 0u;
	effect_ended = 1u;
	return effect_ended;
}

/* An effect's command 81: the effect runs backward from its last step */
void palette_effect_reverse(uint16_t palette_job, uint16_t *p_step, uint32_t *p_effect_ended)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t effect_ended = *p_effect_ended;

	PALETTE_JOB(palette_job)->effect.direction = 1u;
	step -= 4u;
	PALETTE_JOB(palette_job)->effect.step = step;
	effect_ended = 0u;
	*p_step = step;
	*p_effect_ended = effect_ended;
}

/* An effect's command 82: goes back to the step it names, the number of times it says (FF for ever),
   then on */
void palette_effect_repeat(uint16_t palette_job, uint16_t *p_step, uint32_t *p_effect_ended)
{
	uint16_t step = (uint16_t)*p_step;
	uint32_t effect_ended = *p_effect_ended;
	uint8_t repeat_count = 0;
	uint8_t wanted_repeats = 0, repeats_done = 0, repeats_was = 0;
	uint16_t repeat_target = 0;

	wanted_repeats = mem_read8(step + 1u);
	repeat_count = wanted_repeats;
	if (repeat_count == 0xFFu)
	{
		repeat_target = mem_read16(step + 2u);
		step = repeat_target + 4u;
		PALETTE_JOB(palette_job)->effect.step = step;
		effect_ended = 0u;
	}
	else
	{
		repeats_done = PALETTE_JOB(palette_job)->effect.repeats;
		if (repeat_count == repeats_done)
		{
			PALETTE_JOB(palette_job)->effect.repeats = 0u;
			step += 4u;
			PALETTE_JOB(palette_job)->effect.step = step;
			effect_ended = 0u;
		}
		else
		{
			repeats_was = PALETTE_JOB(palette_job)->effect.repeats;
			PALETTE_JOB(palette_job)->effect.repeats = repeats_was + 1u;
			repeat_target = mem_read16(step + 2u);
			step = repeat_target + 4u;
			PALETTE_JOB(palette_job)->effect.step = step;
			effect_ended = 0u;
		}
	}
	*p_step = step;
	*p_effect_ended = effect_ended;
}

/* Palette job 3: sets the background colour and frees the job */
uint16_t palette_job_background_colour(uint16_t palette_job)
{
	uint8_t colour_high = 0, colour_low = 0, control = 0;
	uint16_t d = 0;
	uint8_t saved_colour_high = 0;
	uint16_t background_colour = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	background_colour = PALETTE_JOB(palette_job)->background.colour;
	colour_low = (uint8_t)background_colour;
	colour_high = (uint8_t)(background_colour >> 8);
	io_write16(0xC00u, ((uint32_t)colour_high << 8) | (colour_low & 0xFFu));
	PALETTE_JOB(palette_job)->kind = 0u;
	saved_colour_high = colour_high;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	d = (colour_low & 0xFFu) | ((uint32_t)saved_colour_high << 8);
	return d;
}

/* Palette job 4: a step of a fade to dark */
uint16_t palette_job_darken(uint16_t palette_job)
{
	uint16_t frames_left = 0;
	uint16_t job_frames_left = 0;

	palette_fade_brightens = 0u;
	job_frames_left = PALETTE_JOB(palette_job)->fade.frames_left;
	frames_left = job_frames_left;
	if (job_frames_left == 0u)
	{
		PALETTE_JOB(palette_job)->kind = 0u;
		return frames_left;
	}
	return palette_job_fade(palette_job, frames_left);
}

/* Palette job 5: a step of a fade to bright */
uint16_t palette_job_brighten(uint16_t palette_job, uint16_t fade_mask)
{
	palette_fade_brightens = 1u;
	return palette_job_fade(palette_job, fade_mask);
}

/* A step of a fade: each colour of the step's palette range darkened or brightened by one when the job's
   mask names it; the job ends when its frames run out */
uint16_t palette_job_fade(uint16_t palette_job, uint16_t fade_mask)
{
	uint32_t carry = 0;
	uint8_t control = 0, fade_direction = 0, step_bit = 0;
	uint16_t colour_place = 0, fade_range = 0;
	uint32_t left_caller = 0;
	uint8_t job_low_then_step_bit = 0, saved_job_high = 0;
	uint8_t range_number = 0, ranges_left_low = 0, range_on = 0, range_index = 0, colours_left_was = 0, range_was = 0;
	uint16_t frames_left_was = 0, all_ranges = 0, range_record = 0, ranges_left_was = 0;

	frames_left_was = PALETTE_JOB(palette_job)->fade.frames_left;
	PALETTE_JOB(palette_job)->fade.frames_left = frames_left_was - 1u;
	range_number = PALETTE_JOB(palette_job)->fade.range;
	if (range_number == 0x10u)
	{
		all_ranges = PALETTE_JOB(palette_job)->fade.ranges;
		fade_mask = all_ranges;
		PALETTE_JOB(palette_job)->fade.ranges_left = ((uint32_t)(all_ranges >> 8) << 8) | (fade_mask & 0xFFu);
		PALETTE_JOB(palette_job)->fade.range = 0u;
	}
	ranges_left_low = (uint8_t)PALETTE_JOB(palette_job)->fade.ranges_left;
	range_on = ranges_left_low & 1u;
	step_bit = range_on;
	if (range_on != 0u)
	{
		saved_job_high = palette_job >> 8;
		job_low_then_step_bit = (uint8_t)palette_job;
		control = board_control | 1u;
		board_control = control;
		io_write8(board_control_register, control);
		range_index = PALETTE_JOB(palette_job)->fade.range;
		range_record = fade_ranges_ADDRESS + (int8_t)(((uint32_t)range_index << 1) << 1);
		fade_range = range_record + 1u;
		palette_fade_colours_left = FADE_RANGE(range_record)->colours;
		colour_place = FADE_RANGE(fade_range - 0x1u)->address;
		do
		{
			leftover_y = palette_fade_directions_ADDRESS;
			fade_direction = (uint32_t)palette_fade_brightens << 1;
			left_caller = 0u;
			fade_mask = (fade_mask & 0xFFu) | ((uint32_t)fade_direction << 8);
			switch ((int8_t)fade_direction)
			{
			case 0:
				darken_colour(colour_place, &fade_mask, &carry);
				break;
			case 2:
				brighten_colour(colour_place, &fade_mask, &carry);
				break;
			case -86:
			case -14:
				stage_3_forest_end_phase_tail(&fade_range, &colour_place, &fade_mask, &left_caller, &carry);
				break;
			case -84:
			case -12:
				palette_effects_overrun();
				break;
			case -10:
				palette_effect_forward(colour_place, &fade_range, &fade_mask);
				break;
			case -8:
				palette_effect_backward(colour_place, &fade_range, &fade_mask, &carry);
				break;
			case -6:
				palette_effect_stop(colour_place);
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
				return fade_mask;
			colour_place += 2u;
			colours_left_was = palette_fade_colours_left;
			palette_fade_colours_left = colours_left_was - 1u;
		} while (colours_left_was != 1u);
		palette_job = ((uint32_t)saved_job_high << 8) | job_low_then_step_bit;
	}
	ranges_left_was = PALETTE_JOB(palette_job)->fade.ranges_left;
	PALETTE_JOB(palette_job)->fade.ranges_left = ranges_left_was >> 1;
	range_was = PALETTE_JOB(palette_job)->fade.range;
	PALETTE_JOB(palette_job)->fade.range = range_was + 1u;
	job_low_then_step_bit = step_bit;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	fade_mask = (fade_mask & 0xFFu) | ((uint32_t)job_low_then_step_bit << 8);
	return fade_mask;
}

/* Palette job 6: the white flash every other frame for its frames, then the white palette bank cleared
   and the job freed */
uint16_t palette_job_white_flash(uint16_t palette_job, uint8_t d)
{
	uint8_t black_high = 0, control = 0, priority = 0;
	uint16_t colour_place = 0, d_2 = 0, words_left = 0;
	uint8_t flash_frames_was = 0, flash_k053251 = 0, flash_k053251_10 = 0;
	uint16_t cleared_place = 0, cleared_words_after = 0;

	flash_frames_was = PALETTE_JOB(palette_job)->flash.frames_left;
	PALETTE_JOB(palette_job)->flash.frames_left = flash_frames_was - 1u;
	if (flash_frames_was != 1u)
	{
		if ((frame_count & 1u) == 0u)
		{
			flash_k053251 = PALETTE_JOB(palette_job)->flash.k053251_9;
			io_write8(colour_bases_back_sprites_fixed, flash_k053251);
			flash_k053251_10 = PALETTE_JOB(palette_job)->flash.k053251_10;
			priority = flash_k053251_10;
			io_write8(colour_bases_layers_a_b, priority);
		}
		else
		{
			io_write8(colour_bases_back_sprites_fixed, 0x13u);
			priority = 0x2Cu;
			io_write8(colour_bases_layers_a_b, 0x2Cu);
		}
		d_2 = (d & 0xFFu) | ((uint32_t)priority << 8);
		return d_2;
	}
	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	colour_place = 0xC00u;
	words_left = 0x100u;
	d = 0u;
	black_high = 0u;
	do
	{
		cleared_place = colour_place;
		colour_place = cleared_place + 2u;
		mem_write16(cleared_place, (uint32_t)black_high << 8);
		cleared_words_after = words_left - 1u;
		words_left = cleared_words_after;
		leftover_y = words_left;
	} while (cleared_words_after != 0u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	PALETTE_JOB(palette_job)->kind = 0u;
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	priority = 0x2Cu;
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	d_2 = (d & 0xFFu) | ((uint32_t)priority << 8);
	return d_2;
}

/* Palette job 7: clears the palette ranges whose bits the job holds, and frees the job */
void palette_job_clear(uint16_t palette_job)
{
	uint8_t control = 0;
	uint16_t address = 0, clear_to = 0, count = 0, fill_source = 0;
	uint8_t clear_ranges = 0;
	uint16_t clear_record = 0, first_cleared = 0;

	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	PALETTE_JOB(palette_job)->kind = 0u;
	palette_clear_range = 0u;
	clear_ranges = PALETTE_JOB(palette_job)->clearing.ranges;
	palette_clear_bits = clear_ranges;
	do
	{
		if ((palette_clear_bits & 1u) != 0u)
		{
			clear_record = palette_clears_ADDRESS + (int8_t)(((uint32_t)palette_clear_range << 1) << 1);
			count = PALETTE_CLEAR(clear_record)->extra_bytes;
			address = PALETTE_CLEAR(clear_record)->address;
			fill_source = address;
			leftover_y = fill_source;
			first_cleared = address;
			clear_to = first_cleared + 1u;
			mem_write8(first_cleared, 0u);
			while (count != 0u)
			{
				mem_write8(clear_to, mem_read8(fill_source));
				fill_source++;
				leftover_y = fill_source;
				clear_to++;
				count--;
			}
		}
		palette_clear_bits = palette_clear_bits >> 1;
		palette_clear_range++;
	} while (palette_clear_range != 4u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
}

/* Finds a free palette job among the 64; carry when there is none */
void find_free_palette_job(uint16_t *p_palette_job, uint32_t *p_no_free_job)
{
	uint32_t no_free_job = *p_no_free_job;
	uint16_t palette_job = 0;
	uint8_t jobs_left_was = 0;

	palette_job = palette_jobs;
	palette_jobs_left = 0x40u;
	for (;;)
	{
		if (PALETTE_JOB(palette_job)->kind == 0u)
		{
			no_free_job = 0u;
			break;
		}
		palette_job += 8u;
		jobs_left_was = palette_jobs_left;
		palette_jobs_left = jobs_left_was - 1u;
		if (jobs_left_was == 1u)
		{
			no_free_job = 1u;
			break;
		}
	}
	*p_palette_job = palette_job;
	*p_no_free_job = no_free_job;
}

/* Copies palettes of 16 colours from bank 2D into the palette RAM */
uint16_t load_palettes(uint16_t destination, uint16_t source, uint16_t palette_count)
{
	uint8_t colour_high = 0, colour_low = 0, control = 0;
	uint8_t count_then_colour_high = 0;
	uint8_t colours_left_was = 0, palettes_left_was = 0;
	uint16_t source_at = 0, colour = 0, destination_at = 0;

	count_then_colour_high = palette_count >> 8;
	control = board_control | 1u;
	board_control = control;
	io_write8(board_control_register, control);
	window_bank = 0x2Du;
	set_lines(window_bank);
	palettes_to_load = count_then_colour_high;
	do
	{
		palette_colours_left = 0x10u;
		do
		{
			source_at = source;
			source = source_at + 2u;
			colour = mem_read16(source_at);
			colour_high = (uint8_t)(colour >> 8);
			colour_low = (uint8_t)colour;
			destination_at = destination;
			destination = destination_at + 2u;
			mem_write16(destination_at, ((uint32_t)colour_high << 8) | colour_low);
			colours_left_was = palette_colours_left;
			palette_colours_left = colours_left_was - 1u;
		} while (colours_left_was != 1u);
		palettes_left_was = palettes_to_load;
		palettes_to_load = palettes_left_was - 1u;
	} while (palettes_left_was != 1u);
	count_then_colour_high = colour_high;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	palette_count = ((uint32_t)count_then_colour_high << 8) | colour_low;
	return palette_count;
}

/* Takes one step off each component of a colour that is not at 0 */
void darken_colour(uint16_t colour_place, uint16_t *p_colour, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t colour_high = 0;
	uint16_t colour = 0;
	uint16_t old_colour = 0, saved_colour = 0, component_steps = 0, colour_before = 0, darker_colour = 0;
	uint32_t kind_halfword = 0;

	fade_steps = 0u;
	old_colour = (((uint32_t)PALETTE_JOB(colour_place)->kind << 8u) | PALETTE_JOB(colour_place)->effect.direction);
	colour_high = (uint8_t)(old_colour >> 8);
	fade_colour = ((uint32_t)colour_high << 8) | (old_colour & 0xFFu);
	if ((colour_high & ~7u) != 0u)
		fade_steps_high = 8u;
	if ((fade_colour_high & 3u) != 0u || (fade_colour_low & 0xC0u) != 0u)
		fade_steps_low = 0x40u;
	if ((fade_colour_low & 0x1Eu) != 0u)
		fade_steps_low |= 2u;
	saved_colour = fade_colour;
	component_steps = fade_steps;
	colour_before = saved_colour;
	darker_colour = colour_before - component_steps;
	carry = colour_before < component_steps;
	colour = darker_colour;
	kind_halfword = ((uint32_t)(darker_colour >> 8) << 8) | (colour & 0xFFu);
	PALETTE_JOB(colour_place)->kind = (uint8_t)(kind_halfword >> 8u);
	PALETTE_JOB(colour_place)->effect.direction = (uint8_t)kind_halfword;
	*p_colour = colour;
	*p_carry = carry;
}

/* Adds one step to each component of a colour that is not at its top */
void brighten_colour(uint16_t colour_place, uint16_t *p_colour, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t colour_high = 0;
	uint16_t colour = 0;
	uint16_t old_colour = 0, saved_colour = 0, component_steps = 0, colour_before = 0, brighter_colour = 0;
	uint32_t kind_halfword = 0;

	fade_steps = 0u;
	old_colour = (((uint32_t)PALETTE_JOB(colour_place)->kind << 8u) | PALETTE_JOB(colour_place)->effect.direction);
	colour_high = (uint8_t)(old_colour >> 8);
	fade_colour = ((uint32_t)colour_high << 8) | (old_colour & 0xFFu);
	if ((colour_high & 0x78u) != 0x78u)
		fade_steps_high = 4u;
	if ((fade_colour_high & 3u) != 3u || (fade_colour_low & 0xC0u) != 0xC0u)
		fade_steps_low = 0x20u;
	if ((fade_colour_low & 0x1Eu) != 0x1Eu)
		fade_steps_low |= 1u;
	saved_colour = fade_colour;
	component_steps = fade_steps;
	colour_before = saved_colour;
	brighter_colour = colour_before + component_steps;
	carry = (uint16_t)(colour_before + component_steps) < colour_before;
	colour = brighter_colour;
	kind_halfword = ((uint32_t)(brighter_colour >> 8) << 8) | (colour & 0xFFu);
	PALETTE_JOB(colour_place)->kind = (uint8_t)(kind_halfword >> 8u);
	PALETTE_JOB(colour_place)->effect.direction = (uint8_t)kind_halfword;
	*p_colour = colour;
	*p_carry = carry;
}
