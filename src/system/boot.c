/**
 *    Name:        system/boot.c
 *    Description: the reset: the board set up, the RAM and ROM checks, the main loop that runs the jobs
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The reset: sets the chips up, tests and clears the RAMs, runs the EEPROM test when the test switch is
   held, then the RAM ROM CHECK, loads the first palettes, sets the queues, the high score table and the
   settings, turns the interrupts on and runs the main loop: bank 20's background work and the jobs the
   queue holds, one at a time. */
void boot(void)
{
	uint32_t zero = 0;
	uint8_t control = 0, delay = 0, eeprom_bad = 0, free_mark_high = 0, free_mark_low = 0, job_argument = 0, job_argument_2 = 0, job_kind = 0, letters_left = 0, pattern = 0, screen_flip = 0, sprite_control = 0, table_bytes_left = 0;
	uint16_t bytes_left = 0, clear_from = 0, clear_to = 0, count = 0, d = 0, default_entries = 0, destination = 0, high_score_place = 0, ignored16 = 0, ignored16_2 = 0, job_place = 0, letters = 0, palette_count = 0, place = 0, queue_place = 0, source = 0, test_place = 0, text_number = 0, wait_left = 0;
	uint8_t power_on_count = 0, old_scroll_control = 0, sound_irq_read = 0, old_flip = 0, watchdog_read = 0, letters_left_was = 0, watchdog_read_10 = 0, delay_was = 0, watchdog_read_2 = 0, watchdog_read_3 = 0, dma_still_pending = 0, test_inputs = 0, watchdog_read_4 = 0, test_inputs_2 = 0, old_flip_2 = 0, watchdog_read_5 = 0, watchdog_read_6 = 0, watchdog_read_7 = 0, delay_was_2 = 0, table_bytes_left_was = 0, watchdog_read_8 = 0, watchdog_read_9 = 0;
	uint16_t pattern_place = 0, remaining_bytes = 0, checked_place = 0, letter_place = 0, tile_place = 0, remaining_wait = 0, remaining_bytes_2 = 0, cleared_place = 0, remaining_bytes_3 = 0, remaining_wait_2 = 0, job_slot_place = 0, sound_slot_place = 0, default_byte_place = 0, high_score_byte_place = 0, job_word = 0, taken_job_place = 0;

	delay = 0u;
	do
	{
		power_on_count = delay + 1u;
		delay = power_on_count;
	} while (power_on_count != 0u);
	mem_write8(0x7C00u, 0x13u);
	io_write8(0x1D00u, 0xFBu);
	io_write8(0x1FC2u, 0u);
	io_write8(0x1FA4u, 0x24u);
	io_write8(0x1FC0u, 0x30u);
	io_write8(0x1D80u, 0x10u);
	io_write8(0x1F00u, 0x32u);
	old_scroll_control = io_read8(0x1C80u);
	io_write8(0x1C80u, 0u);
	io_write16(0x1FC6u, 0u);
	sound_irq_read = io_read8(0x1FC4u);
	old_flip = io_read8(0x1E80u);
	io_write8(0x1E80u, 0u);
	io_write16(0x1FA0u, 0u);
	io_write16(0x1FA2u, 0u);
	io_write8(0x1FB0u, 0x3Fu);
	io_write8(0x1FB2u, 4u);
	io_write8(0x1FB3u, 0x28u);
	io_write8(0x1FB4u, 0x18u);
	io_write8(0x1FB6u, 0x17u);
	io_write8(0x1FB7u, 0x27u);
	io_write8(0x1FB8u, 0x37u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	io_write8(0x1FBBu, 0u);
	io_write8(0x1FBCu, 5u);
	pattern = 0u;
	do
	{
		test_place = ram_test_start_ADDRESS;
		bytes_left = 0x300u;
		do
		{
			pattern_place = test_place;
			test_place = pattern_place + 1u;
			mem_write8(pattern_place, pattern);
			remaining_bytes = bytes_left - 1u;
			bytes_left = remaining_bytes;
		} while (remaining_bytes != 0u);
		watchdog_read = io_read8(0x1FCAu);
		test_place = ram_test_start_ADDRESS;
		bytes_left = 0x300u;
		do
		{
			checked_place = test_place;
			test_place = checked_place + 1u;
			if (pattern != mem_read8(checked_place))
			{
				letters_left = 0x1Bu;
				letters = ram_check_bad_texts_ADDRESS;
				place = 0x2313u;
				do
				{
					mem_write8(place - 0x2000u, 0u);
					letter_place = letters;
					letters = letter_place + 1u;
					tile_place = place;
					place = tile_place + 1u;
					mem_write8(tile_place, mem_read8(letter_place) - 0x30u);
					letters_left_was = letters_left;
					letters_left = letters_left_was - 1u;
				} while (letters_left_was != 1u);
				delay = 8u;
				do
				{
					wait_left = 0u;
					do
					{
						remaining_wait = wait_left - 1u;
						wait_left = remaining_wait;
					} while (remaining_wait != 0u);
					watchdog_read_10 = io_read8(0x1FCAu);
					delay_was = delay;
					delay = delay_was - 1u;
				} while (delay_was != 1u);
				reset_sound();
				boot();
				return;
			}
			remaining_bytes_2 = bytes_left - 1u;
			bytes_left = remaining_bytes_2;
		} while (remaining_bytes_2 != 0u);
		watchdog_read_2 = io_read8(0x1FCAu);
		pattern += 0x55u;
	} while (pattern != 0x54u);
	test_place = ram_test_start_ADDRESS;
	bytes_left = 0x300u;
	do
	{
		cleared_place = test_place;
		test_place = cleared_place + 1u;
		mem_write8(cleared_place, 0u);
		remaining_bytes_3 = bytes_left - 1u;
		bytes_left = remaining_bytes_3;
	} while (remaining_bytes_3 != 0u);
	zero = check_work_ram();
	if (zero == 0u)
	{
		letters_left = 0x1Bu;
		letters = ram_check_bad_texts_ADDRESS;
		place = 0x2313u;
		do
		{
			mem_write8(place - 0x2000u, 0u);
			letter_place = letters;
			letters = letter_place + 1u;
			tile_place = place;
			place = tile_place + 1u;
			mem_write8(tile_place, mem_read8(letter_place) - 0x30u);
			letters_left_was = letters_left;
			letters_left = letters_left_was - 1u;
		} while (letters_left_was != 1u);
		delay = 8u;
		do
		{
			wait_left = 0u;
			do
			{
				remaining_wait = wait_left - 1u;
				wait_left = remaining_wait;
			} while (remaining_wait != 0u);
			watchdog_read_10 = io_read8(0x1FCAu);
			delay_was = delay;
			delay = delay_was - 1u;
		} while (delay_was != 1u);
		reset_sound();
		boot();
		return;
	}
	clear_from = floor_map_ADDRESS;
	clear_to = 0x4001u;
	floor_map = 0u;
	count = 0x1FFFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_from = 0x1840u;
	clear_to = 0x1841u;
	io_write8(0x1840u, 0u);
	count = 0x1BFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	io_write8(0x1FC2u, 0u);
	clear_from = 0x3840u;
	clear_to = 0x3841u;
	io_write8(0x3840u, 0u);
	count = 0x1BFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	clear_from = 0x3C00u;
	clear_to = 0x3C01u;
	io_write8(0x3C00u, 0u);
	count = 0x3FFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	io_write8(0x1FC2u, 2u);
	clear_from = 0x2000u;
	clear_to = 0x2001u;
	io_write8(0x2000u, 0u);
	count = 0x1FFFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	io_write8(0x1FC2u, 1u);
	clear_from = 0u;
	clear_to = 1u;
	io_write8(0u, 0u);
	count = 0xFFFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	io_write8(0x1FC2u, 1u);
	watchdog_read_3 = io_read8(0x1FCAu);
	enable_firq();
	leftover_y = clear_from;
	take_interrupts();
	board_control = 4u;
	io_write8(0x1FC2u, 4u);
	sprite_chip_control = 0x34u;
	io_write8(0x1FA5u, 0x34u);
	dma_pending = 1u;
	do
	{
		dma_still_pending = dma_pending;
		leftover_y = clear_from;
		frame_wait(SIMPSONS_BOOT_WAIT);
		leftover_y = clear_from;
		take_interrupts();
	} while (dma_still_pending != 0u);
	test_inputs = io_read8(0x1F81u);
	if ((test_inputs & 1u) == 0u)
	{
		set_check_colours();
		control = board_control & ~3u;
		board_control = control;
		io_write8(0x1FC2u, control);
		clear_tile_layers();
		watchdog_read_4 = io_read8(0x1FCAu);
		text_number = 6u;
		print_game_text(text_number);
		window_bank = 0x2Fu;
		set_lines(window_bank);
		d = eeprom_test();
		eeprom_bad = (uint8_t)(d >> 8);
		if (eeprom_bad != 0u)
		{
			text_number = 8u;
			print_game_text(text_number);
			for (;;)
			{
			}
		}
		text_number = 7u;
		print_game_text(text_number);
		text_number = 9u;
		print_game_text(text_number);
		window_bank = 0x2Fu;
		set_lines(window_bank);
		eeprom_reset_settings();
		d = 0xAu;
		print_game_text(d);
		do
		{
			test_inputs_2 = io_read8(0x1F81u);
			frame_wait(SIMPSONS_SWITCH_WAIT);
			take_interrupts();
		} while ((test_inputs_2 & 1u) == 0u);
	}
	window_bank = 0x2Fu;
	set_lines(window_bank);
	d |= 0x6F00u;
	d = eeprom_read_byte(d);
	screen_flip = (uint8_t)d;
	if (screen_flip != 0u)
		io_write8(0x1E80u, 1u);
	else
	{
		old_flip_2 = io_read8(0x1E80u);
		io_write8(0x1E80u, 0u);
	}
	ram_rom_check();
	io_write8(0x1FA5u, 0x24u);
	sprite_chip_control = 0x24u;
	io_write16(0x1A00u, 0u);
	io_write16(0x3A00u, 0u);
	io_write8(0x180Cu, 0u);
	io_write8(0x380Cu, 0u);
	destination = 0u;
	source = loaded_table_05F1E0_ADDRESS;
	d = (d & 0xFFu) | 0xF00u;
	d = load_palettes(destination, source, d);
	destination = 0x400u;
	source = 0x6F00u;
	d = (d & 0xFFu) | 0x300u;
	d = load_palettes(destination, source, d);
	destination = 0x800u;
	source = 0x6000u;
	d = (d & 0xFFu) | 0x300u;
	d = load_palettes(destination, source, d);
	destination = 0xA00u;
	source = 0x6860u;
	palette_count = (d & 0xFFu) | 0x300u;
	load_palettes(destination, source, palette_count);
	clear_tile_layers();
	watchdog_read_5 = io_read8(0x1FCAu);
	clear_tile_layers();
	watchdog_read_6 = io_read8(0x1FCAu);
	dma_pending = 1u;
	draw_boot_pattern();
	delay = 3u;
	do
	{
		wait_left = 0u;
		do
		{
			remaining_wait_2 = wait_left - 1u;
			wait_left = remaining_wait_2;
		} while (remaining_wait_2 != 0u);
		watchdog_read_7 = io_read8(0x1FCAu);
		delay_was_2 = delay;
		delay = delay_was_2 - 1u;
	} while (delay_was_2 != 1u);
	queue_place = job_queue_ADDRESS;
	job_queue_write = job_queue_ADDRESS;
	job_queue_read = job_queue_ADDRESS;
	free_mark_high = 0xFFu;
	free_mark_low = 0xFFu;
	do
	{
		job_slot_place = queue_place;
		queue_place = job_slot_place + 2u;
		QUEUED_JOB(job_slot_place)->job = ((uint32_t)free_mark_high << 8) | free_mark_low;
	} while (queue_place != high_scores_ADDRESS);
	queue_place = sound_queue_ADDRESS;
	sound_queue_write = sound_queue_ADDRESS;
	sound_queue_read = sound_queue_ADDRESS;
	free_mark_high = 0xFFu;
	free_mark_low = 0xFFu;
	do
	{
		sound_slot_place = queue_place;
		queue_place = sound_slot_place + 2u;
		mem_write16(sound_slot_place, ((uint32_t)free_mark_high << 8) | free_mark_low);
	} while (queue_place != job_queue_write_ADDRESS);
	high_score_place = high_scores_ADDRESS;
	default_entries = default_high_scores_ADDRESS;
	table_bytes_left = 0x50u;
	do
	{
		default_byte_place = default_entries;
		default_entries = default_byte_place + 1u;
		high_score_byte_place = high_score_place;
		high_score_place = high_score_byte_place + 1u;
		mem_write8(high_score_byte_place, mem_read8(default_byte_place));
		table_bytes_left_was = table_bytes_left;
		table_bytes_left = table_bytes_left_was - 1u;
	} while (table_bytes_left_was != 1u);
	clear_objects(&ignored16_2, &ignored16);
	watchdog_read_8 = io_read8(0x1FCAu);
	window_bank = 0x2Fu;
	set_lines(window_bank);
	eeprom_load_settings();
	apply_settings();
	game_mode = 1u;
	io_write8(0x1FC0u, board_output);
	watchdog_read_9 = io_read8(0x1FCAu);
	irq_busy = 0u;
	dma_pending = 1u;
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	enable_firq();
	take_interrupts();
	control = board_control | 4u;
	board_control = control;
	io_write8(0x1FC2u, control);
	sprite_control = sprite_chip_control | 0x10u;
	sprite_chip_control = sprite_control;
	io_write8(0x1FA5u, sprite_control);
	enable_irq();
	take_interrupts();
	io_write8(0x1D00u, 0xFFu);
	for (;;)
	{
		window_bank = 0x20u;
		set_lines(window_bank);
		gauges_draw();
		job_place = job_queue_read;
		job_word = QUEUED_JOB(job_place)->job;
		job_kind = (uint8_t)(job_word >> 8);
		job_argument = (uint8_t)job_word;
		frame_wait(SIMPSONS_FRAME_WAIT);
		take_interrupts();
		if ((int16_t)job_word < 0)
			continue;
		taken_job_place = job_place;
		job_place = taken_job_place + 2u;
		QUEUED_JOB(taken_job_place)->job = 0xFFFFu;
		if (job_place >= job_queue_ADDRESS + 0x3Bu)
			job_place = job_queue_ADDRESS;
		job_queue_read = job_place;
		job_kind = (uint32_t)job_kind << 1;
		job_argument_2 = job_argument;
		switch ((int8_t)job_kind)
		{
		case 0:
			job_clear_screen(job_argument_2);
			break;
		case 2:
			job_print_game_text(job_argument_2);
			break;
		case 4:
			job_set_text_colour(job_argument_2);
			break;
		case 6:
			job_add_marge_score(job_argument_2);
			break;
		case 8:
			job_add_homer_score(job_argument_2);
			break;
		case 10:
			job_add_bart_score(job_argument_2);
			break;
		case 12:
			job_add_lisa_score(job_argument_2);
			break;
		case 14:
		case 16:
		case 18:
		case 20:
		case 22:
		case 24:
		case 26:
		case 28:
		case 30:
			job_none();
			break;
		}
	}
}

/* Unused: the SWI and NMI vectors' routine; it returns at once and nothing raises them. */
void ignore_interrupt(void)
{
}

/* Takes the settings the test mode keeps at 59F1 into the game's variables: the coinage, the coin slots'
   mode, the lives, the difficulty, the sound in the attract, the screen flipped or not (the tile and
   sprite chips set for it), the coin counters' port bit and the first credit's extra coins. */
void apply_settings(void)
{
	uint8_t coinage = 0, coinage_coins = 0, output = 0, sprite_control = 0;
	uint16_t settings = 0;
	uint8_t stack = 0;
	uint8_t lives_chosen = 0, difficulty_chosen = 0, attract_sound_chosen = 0, flip_chosen = 0, stereo_chosen = 0, extra_coins_chosen = 0;

	settings = coin_setting_ADDRESS;
	coinage = coinages[(int8_t)coin_setting];
	stack = coinage;
	coinage &= 0xFu;
	slot_1_credits_per_coins = coinage;
	slot_2_credits_per_coins = coinage;
	coinage_coins = (((stack >> 1) >> 1) >> 1) >> 1;
	slot_1_coins_per_credit = coinage_coins;
	slot_2_coins_per_credit = coinage_coins;
	if (coin_slots_setting == 0u)
	{
		separate_coin_slots = 1u;
		four_coin_slots = 1u;
	}
	else
	{
		separate_coin_slots = 0u;
		four_coin_slots = 0u;
	}
	lives_chosen = lives_option;
	lives_per_credit = lives_chosen + 1u;
	difficulty_chosen = difficulty_option;
	difficulty_setting = difficulty_chosen;
	attract_sound_chosen = attract_sound_option;
	attract_sound = attract_sound_chosen;
	flip_chosen = screen_flip_option;
	if (flip_chosen != 0u)
	{
		io_write8(0x1E80u, 1u);
		sprite_control = sprite_chip_control | 3u;
		sprite_chip_control = sprite_control;
		io_write8(0x1FA5u, sprite_control);
		flip_screen = 1u;
		io_write16(0x1FA0u, 0x255u);
		sprite_scroll_x = 0x255u;
		io_write16(0x1FA2u, 0x71u);
		sprite_scroll_y = 0x71u;
	}
	else
	{
		io_write8(0x1E80u, 0u);
		sprite_control = sprite_chip_control & ~3u;
		sprite_chip_control = sprite_control;
		io_write8(0x1FA5u, sprite_control);
		flip_screen = 0u;
		io_write16(0x1FA0u, 0x15u);
		sprite_scroll_x = 0x15u;
		io_write16(0x1FA2u, 0x261u);
		sprite_scroll_y = 0x261u;
	}
	sprite_scroll_x_pad = 0u;
	sprite_scroll_y_pad = 0u;
	output = 0x30u;
	stereo_chosen = sound_output_option;
	if (stereo_chosen != 0u)
		output |= 4u;
	board_output = output;
	extra_coins_chosen = first_credit_coins_option;
	first_credit_extra_coins = extra_coins_chosen;
}

/* Fills the text layer's middle, 36 tiles by 32 rows, with a pattern of tiles 2E 2F over 2C 2D. */
void draw_boot_pattern(void)
{
	uint8_t control = 0, pairs_left = 0, rows_left = 0;
	uint16_t place = 0, tile_pair = 0;
	uint8_t pairs_left_was = 0, pairs_left_was_2 = 0, rows_left_was = 0;
	uint16_t pair_place = 0, pair_place_2 = 0;

	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	place = 0x200Eu;
	rows_left = 0x10u;
	do
	{
		pairs_left = 0x12u;
		tile_pair = 0x2F2Eu;
		do
		{
			pair_place = place;
			place = pair_place + 2u;
			mem_write16(pair_place, tile_pair);
			pairs_left_was = pairs_left;
			pairs_left = pairs_left_was - 1u;
		} while (pairs_left_was != 1u);
		place += 0x1Cu;
		pairs_left = 0x12u;
		tile_pair = 0x2D2Cu;
		do
		{
			pair_place_2 = place;
			place = pair_place_2 + 2u;
			mem_write16(pair_place_2, tile_pair);
			pairs_left_was_2 = pairs_left;
			pairs_left = pairs_left_was_2 - 1u;
		} while (pairs_left_was_2 != 1u);
		place += 0x1Cu;
		rows_left_was = rows_left;
		rows_left = rows_left_was - 1u;
	} while (rows_left_was != 1u);
}

/* Tests the work RAM 4000-5CFF word by word; Z when it is good. */
uint32_t check_work_ram(void)
{
	uint32_t zero = 0;
	uint16_t count = 0, start = 0, test_result = 0;

	start = floor_map_ADDRESS;
	count = 0xE80u;
	test_result = test_ram_words(count, start);
	zero = (uint8_t)test_result == 0u;
	return zero;
}

/* The RAM ROM CHECK screen: tests the sprite, tile and palette RAMs and the EEPROM, adds up the
   program's four chips and checks them against their sums, asks the Z80 to check its ROM and RAM, prints
   OK or BAD by each chip and each sum, waits a while and restarts the game when anything was bad. */
void ram_rom_check(void)
{
	uint8_t answer_bits = 0, check_result = 0, sum_high = 0, sum_low = 0, wait_high = 0, wait_low = 0;
	uint16_t answer = 0, bad = 0, check_word = 0, count = 0, count_2 = 0, ignored16 = 0, ignored16_3 = 0, place = 0, place_2 = 0, start = 0, start_2 = 0, text_number = 0;
	uint8_t stack = 0;
	uint8_t watchdog_read = 0, watchdog_read_2 = 0, wait_loops_was = 0;
	uint16_t sum_13c = 0, sum_15c = 0, sum_16c = 0, sum_17c = 0, wait_count = 0, wait_count_left = 0;

	check_failed = 0u;
	check_11f = 0u;
	do
	{
	} while (dma_pending != 0u);
	io_write8(0x1FC2u, 6u);
	start = 0x2000u;
	count_2 = 0x1000u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_1j = check_result;
	io_write8(0x1FC2u, 4u);
	start = 0x2000u;
	count_2 = 0xC00u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_16g = check_result;
	start = 0x1840u;
	count_2 = 0xE0u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_16g |= check_result;
	start = 0u;
	count_2 = 0xC00u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_16f = check_result;
	start = 0x3840u;
	count_2 = 0xE0u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_16f |= check_result;
	start = 0x3C00u;
	count_2 = 0x200u;
	check_word = test_ram_words(count_2, start);
	check_result = (uint8_t)check_word;
	check_16f |= check_result;
	io_write8(0x1FC2u, 5u);
	start = 1u;
	count_2 = 0x800u;
	check_word = test_ram_bytes(count_2, start);
	check_result = (uint8_t)check_word;
	check_9g = check_result;
	io_write8(0x1FC2u, 5u);
	start = 0u;
	count_2 = 0x800u;
	check_word = test_ram_bytes(count_2, start);
	check_result = (uint8_t)check_word;
	check_8g = check_result;
	window_bank = 0x2Fu;
	set_lines(window_bank);
	check_word = eeprom_verify();
	check_result = (uint8_t)check_word;
	check_12c = check_result;
	clear_tile_layers();
	watchdog_read = io_read8(0x1FCAu);
	text_number = 0xBu;
	print_game_text(text_number);
	place = 0x2122u;
	bad = check_11f;
	print_check_result(place, (uint8_t)bad);
	place = 0x21A2u;
	bad = check_1j;
	print_check_result(place, (uint8_t)bad);
	place = 0x2222u;
	bad = check_16g;
	print_check_result(place, (uint8_t)bad);
	place = 0x22A2u;
	bad = check_16f;
	print_check_result(place, (uint8_t)bad);
	place = 0x2322u;
	bad = check_9g;
	print_check_result(place, (uint8_t)bad);
	place = 0x23A2u;
	bad = check_8g;
	print_check_result(place, (uint8_t)bad);
	place = 0x2422u;
	bad = check_12c;
	print_check_result(place, (uint8_t)bad);
	set_check_colours();
	rom_sum = 0u;
	stack = 0x20u;
	do
	{
		window_bank = stack;
		set_lines(window_bank);
		add_bank_bytes();
		stack = stack + 1u;
	} while (stack != 0x30u);
	sum_13c = rom_sum;
	if (sum_13c != rom_13c_sum[0])
		check_result = 3u;
	else
		check_result = 0u;
	place = 0x24A2u;
	bad = check_result;
	bad = print_check_result(place, (uint8_t)bad);
	place_2 = 0x24A6u;
	print_rom_sum(place_2, (uint8_t)bad);
	rom_sum = 0u;
	start_2 = fixed_program_start_ADDRESS;
	count = fixed_program_start_ADDRESS;
	add_fixed_bytes(start_2, count);
	stack = 0x30u;
	do
	{
		window_bank = stack;
		set_lines(window_bank);
		add_bank_bytes();
		stack = stack + 1u;
	} while (stack != 0x3Cu);
	sum_15c = rom_sum;
	if (sum_15c != rom_15c_sum[0])
		check_result = 3u;
	else
		check_result = 0u;
	place = 0x2522u;
	bad = check_result;
	bad = print_check_result(place, (uint8_t)bad);
	place_2 = 0x2526u;
	print_rom_sum(place_2, (uint8_t)bad);
	rom_sum = 0u;
	stack = 0u;
	do
	{
		window_bank = stack;
		set_lines(window_bank);
		add_bank_bytes();
		stack = stack + 1u;
	} while (stack != 0x10u);
	sum_16c = rom_sum;
	if (sum_16c != rom_16c_sum[0])
		check_result = 3u;
	else
		check_result = 0u;
	place = 0x25A2u;
	bad = check_result;
	bad = print_check_result(place, (uint8_t)bad);
	place_2 = 0x25A6u;
	print_rom_sum(place_2, (uint8_t)bad);
	rom_sum = 0u;
	stack = 0x10u;
	do
	{
		window_bank = stack;
		set_lines(window_bank);
		add_bank_bytes();
		stack = stack + 1u;
	} while (stack != 0x20u);
	sum_17c = rom_sum;
	if (sum_17c != rom_17c_sum[0])
		check_result = 3u;
	else
		check_result = 0u;
	place = 0x2622u;
	bad = check_result;
	bad = print_check_result(place, (uint8_t)bad);
	place_2 = 0x2626u;
	print_rom_sum(place_2, (uint8_t)bad);
	ask_sound_cpu_check(&ignored16, &answer);
	answer_bits = (uint8_t)(answer >> 8);
	if ((int8_t)answer_bits >= 0)
	{
		check_word = read_sound_rom_sum();
		sum_high = (uint8_t)(check_word >> 8);
		sum_low = (uint8_t)check_word;
		rom_sum = ((uint32_t)sum_high << 8) | sum_low;
		ask_sound_cpu_check(&ignored16, &answer);
		answer_bits = (uint8_t)(answer >> 8);
		check_result = 0u;
		if ((answer_bits & 2u) != 0u)
			check_result = 3u;
		place = 0x26A2u;
		bad = check_result;
		bad = print_check_result(place, (uint8_t)bad);
		place_2 = 0x26A6u;
		print_rom_sum(place_2, (uint8_t)bad);
		ask_sound_cpu_check(&ignored16, &answer);
		answer_bits = (uint8_t)(answer >> 8);
		check_result = 0u;
		if ((answer_bits & 1u) != 0u)
			check_result = 3u;
		place = 0x2722u;
		bad = check_result;
		print_check_result(place, (uint8_t)bad);
	}
	else
	{
		place = 0x26A2u;
		bad = 3u;
		print_check_result(place, (uint8_t)bad);
		place = 0x2722u;
		bad = 3u;
		print_check_result(place, (uint8_t)bad);
		check_failed = 1u;
	}
	check_wait_loops = 0x10u;
	do
	{
		wait_high = 0u;
		wait_low = 0u;
		do
		{
			wait_count = ((uint32_t)wait_high << 8) | wait_low;
			wait_count_left = wait_count - 1u;
			wait_high = (uint8_t)(wait_count_left >> 8);
			wait_low = (uint8_t)wait_count_left;
		} while (wait_count != 1u);
		watchdog_read_2 = io_read8(0x1FCAu);
		wait_loops_was = check_wait_loops;
		check_wait_loops = wait_loops_was - 1u;
	} while (wait_loops_was != 1u);
	if (check_failed != 0u)
	{
		boot();
		return;
	}
	clear_text_layer(&ignored16, &ignored16_3);
}

/* Sets the texts' colours for the RAM checks' screens: white (FFFF) at 0400, and red (001F) at 0420 for
   BAD. */
void set_check_colours(void)
{
	uint8_t colour_high = 0, colour_low = 0;
	uint16_t colour_place = 0;
	uint8_t stack = 0;
	uint8_t colours_left_was = 0, colours_left_was_2 = 0;
	uint16_t written_colour_place = 0, written_colour_place_2 = 0;

	io_write8(0x1FC2u, 5u);
	colour_place = 0x400u;
	stack = 0xFu;
	colour_low = 0xFFu;
	colour_high = 0xFFu;
	do
	{
		written_colour_place = colour_place;
		colour_place = written_colour_place + 2u;
		mem_write16(written_colour_place, ((uint32_t)colour_high << 8) | (colour_low & 0xFFu));
		colours_left_was = stack;
		stack = colours_left_was - 1u;
	} while (colours_left_was != 1u);
	mem_write16(colour_place, 0u);
	colour_place = 0x420u;
	stack = 0x10u;
	colour_low = 0x1Fu;
	colour_high = 0u;
	do
	{
		written_colour_place_2 = colour_place;
		colour_place = written_colour_place_2 + 2u;
		mem_write16(written_colour_place_2, ((uint32_t)colour_high << 8) | colour_low);
		colours_left_was_2 = stack;
		stack = colours_left_was_2 - 1u;
	} while (colours_left_was_2 != 1u);
}

/* Prints the sum the check added up (48FA) as four hex digits at X, in red when B is not 0. */
void print_rom_sum(uint16_t place, uint8_t bad)
{
	uint8_t colour = 0;
	uint16_t value = 0;

	colour = (uint8_t)bad;
	hex_colour = 0u;
	if (colour != 0u)
		colour = 0x40u;
	hex_colour = colour;
	value = rom_sum;
	print_hex_word(place, value);
}

/* Tests Y words of RAM from U with the patterns FFFF, AAAA, 5555 and 0000: B 3 when one does not read
   back, else 0. */
uint16_t test_ram_words(uint16_t count, uint16_t start)
{
	uint16_t bad = 0, pattern = 0, wait_left = 0, word_place = 0, words_left = 0;
	uint16_t stack = 0;
	uint8_t watchdog_read = 0, watchdog_read_2 = 0, watchdog_read_3 = 0;
	uint16_t written_word_place = 0, words_left_was = 0, wait_left_was = 0, checked_word_place = 0, words_left_was_2 = 0;

	pattern = 0xFFFFu;
	ram_test_start = start;
	do
	{
		stack = count;
		words_left = stack;
		word_place = ram_test_start;
		do
		{
			written_word_place = word_place;
			word_place = written_word_place + 2u;
			mem_write16(written_word_place, pattern);
			watchdog_read = io_read8(0x1FCAu);
			words_left_was = words_left;
			words_left = words_left_was - 1u;
		} while (words_left_was != 1u);
		wait_left = 0x1000u;
		do
		{
			watchdog_read_2 = io_read8(0x1FCAu);
			wait_left_was = wait_left;
			wait_left = wait_left_was - 1u;
		} while (wait_left_was != 1u);
		stack = count;
		words_left = stack;
		word_place = ram_test_start;
		do
		{
			watchdog_read_3 = io_read8(0x1FCAu);
			checked_word_place = word_place;
			word_place = checked_word_place + 2u;
			if (pattern != mem_read16(checked_word_place))
			{
				bad = (words_left & ~0xFFu) | 3u;
				return bad;
			}
			words_left_was_2 = words_left;
			words_left = words_left_was_2 - 1u;
		} while (words_left_was_2 != 1u);
		pattern -= 0x5555u;
	} while (pattern != 0xAAABu);
	words_left &= ~0xFFu;
	return words_left;
}

/* Tests Y bytes of RAM from U, every other one (one chip of the palette RAM), with the patterns FF, AA,
   55 and 00: B 3 when one does not read back. */
uint16_t test_ram_bytes(uint16_t count, uint16_t start)
{
	uint8_t pattern = 0;
	uint16_t bad = 0, byte_place = 0, bytes_left = 0, wait_left = 0;
	uint8_t watchdog_read = 0, watchdog_read_2 = 0, watchdog_read_3 = 0;
	uint16_t written_byte_place = 0, bytes_still_left = 0, wait_still_left = 0, checked_byte_place = 0, bytes_still_left_2 = 0;

	pattern = 0xFFu;
	ram_test_start = start;
	do
	{
		bytes_left = count;
		byte_place = ram_test_start;
		do
		{
			written_byte_place = byte_place;
			byte_place = written_byte_place + 2u;
			mem_write8(written_byte_place, pattern);
			watchdog_read = io_read8(0x1FCAu);
			bytes_still_left = bytes_left - 1u;
			bytes_left = bytes_still_left;
		} while (bytes_still_left != 0u);
		wait_left = 0x1000u;
		do
		{
			watchdog_read_2 = io_read8(0x1FCAu);
			wait_still_left = wait_left - 1u;
			wait_left = wait_still_left;
		} while (wait_still_left != 0u);
		bytes_left = count;
		byte_place = ram_test_start;
		do
		{
			watchdog_read_3 = io_read8(0x1FCAu);
			checked_byte_place = byte_place;
			byte_place = checked_byte_place + 2u;
			if (pattern != mem_read8(checked_byte_place))
			{
				bad = ((uint32_t)pattern << 8) | 3u;
				return bad;
			}
			bytes_still_left_2 = bytes_left - 1u;
			bytes_left = bytes_still_left_2;
		} while (bytes_still_left_2 != 0u);
		pattern -= 0x55u;
	} while (pattern != 0xABu);
	bad = (uint32_t)pattern << 8;
	return bad;
}

/* Adds the bytes of the bank in the window (6000-7FFF) to the check's sum. */
void add_bank_bytes(void)
{
	uint16_t count = 0, start = 0;

	start = 0x6000u;
	count = 0x2000u;
	add_rom_bytes(start, count);
}

/* Starts the check's sum and adds U bytes from X (the fixed program, 8000-FFFF). */
void add_fixed_bytes(uint16_t start, uint16_t count)
{
	rom_sum = 0u;
	add_rom_bytes(start, count);
}

void BOARD_ORIGINAL(add_rom_bytes)(uint16_t start, uint16_t count)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	do
	{
		t1 = rom_sum;
		b = (uint8_t)t1;
		t2 = start;
		start = t2 + 1u;
		t3 = mem_read8(t2);
		carry = (uint8_t)(b + t3) < b;
		rom_sum = ((uint32_t)(uint8_t)((t1 >> 8) + carry) << 8) | (uint8_t)(b + t3);
		count--;
	} while (count != 0u);
	t4 = io_read8(0x1FCAu);
}

/* Prints OK, or BAD in red when B is not 0 (and marks the check as failed), at the tile RAM's U. */
uint16_t print_check_result(uint16_t place, uint8_t bad)
{
	uint8_t colour = 0, result_code = 0, tile = 0;
	uint16_t letters = 0, tile_and_result = 0;
	uint8_t stack = 0;
	uint8_t letters_left_was = 0;
	uint16_t letter_place = 0, tile_place = 0;

	result_code = (uint8_t)bad;
	stack = result_code;
	check_failed |= result_code;
	colour = stack;
	io_write8(0x1FC2u, 4u);
	letters = check_result_texts_ADDRESS;
	if (colour != 0u)
	{
		letters += colour;
		colour = 0x40u;
	}
	result_letters_left = 3u;
	do
	{
		mem_write8(place - 0x2000u, colour);
		letter_place = letters;
		letters = letter_place + 1u;
		tile = mem_read8(letter_place) - 0x30u;
		tile_place = place;
		place = tile_place + 1u;
		mem_write8(tile_place, tile);
		letters_left_was = result_letters_left;
		result_letters_left = letters_left_was - 1u;
	} while (letters_left_was != 1u);
	tile_and_result = ((uint32_t)tile << 8) | stack;
	return tile_and_result;
}

/* Asks the Z80 for its checks (command F181) and returns its answer in D, or 8F00 when it does not
   answer. */
void ask_sound_cpu_check(uint16_t *p_wait_left, uint16_t *p_answer)
{
	uint8_t command = 0;
	uint16_t answer = 0, wait_left = 0;
	uint8_t sound_irq_read = 0, sound_echo = 0;
	uint16_t wait_still_left = 0, sound_answer = 0;

	command = 0x81u;
	io_write16(0x1FC6u, 0xF181u);
	sound_irq_read = io_read8(0x1FC4u);
	wait_left = 0x2000u;
	for (;;)
	{
		wait_still_left = wait_left - 1u;
		wait_left = wait_still_left;
		if (wait_still_left == 0u)
		{
			answer = 0x8F00u;
			break;
		}
		sound_echo = io_read8(0x1FC7u);
		if ((uint8_t)command == sound_echo)
		{
			sound_answer = io_read16(0x1FC6u);
			answer = sound_answer;
			break;
		}
	}
	*p_wait_left = wait_left;
	*p_answer = answer;
}

/* Asks the Z80 for the sum of its ROM (commands F383 and F282) and returns it in D. */
uint16_t read_sound_rom_sum(void)
{
	uint8_t sum_high = 0, sum_low = 0;
	uint16_t sound_exchange = 0, sum = 0;
	uint8_t stack = 0;

	sound_exchange = 0xF383u;
	sound_exchange = send_sound_command_and_wait(sound_exchange);
	sum_high = (uint8_t)(sound_exchange >> 8);
	stack = sum_high;
	sound_exchange = 0xF282u;
	sound_exchange = send_sound_command_and_wait(sound_exchange);
	sum_low = (uint8_t)(sound_exchange >> 8);
	sum = ((uint32_t)stack << 8) | sum_low;
	return sum;
}

/* Sends the Z80 the command FF00, without waiting. */
void reset_sound(void)
{
	uint8_t sound_irq_read = 0;

	io_write16(0x1FC6u, 0xFF00u);
	sound_irq_read = io_read8(0x1FC4u);
}

/* Sends the Z80 the command in D and waits until it echoes the command's low byte; returns its answer in
   D. */
uint16_t send_sound_command_and_wait(uint16_t command)
{
	uint8_t sound_irq_read = 0, sound_echo = 0;
	uint16_t sound_answer = 0;

	io_write16(0x1FC6u, command);
	sound_irq_read = io_read8(0x1FC4u);
	do
	{
		sound_echo = io_read8(0x1FC7u);
	} while ((uint8_t)command != sound_echo);
	sound_answer = io_read16(0x1FC6u);
	command = sound_answer;
	return command;
}
