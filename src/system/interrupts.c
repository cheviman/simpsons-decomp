/**
 *    Name:        system/interrupts.c
 *    Description: the IRQ's handler (the K052109's, at VBLANK: the inputs, the coin counters, the jobs) and the FIRQ's (the sprite DMA's)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The IRQ's routine, at each frame: counts the coins and pulses the coin counters, enters the test mode
   when its switch is pressed, sends the Z80 one queued sound command, then reads the controls, sets the
   tile layers' scrolls, runs the palette jobs and the routine of the game's state (test mode, attract or
   game) and updates the sprites for the DMA. */
void irq_handler(void)
{
	uint32_t coin_dropped = 0;
	uint8_t b = 0, control = 0, d = 0, output = 0, scroll_x_high = 0, sprite_control = 0;
	uint16_t coin_bit = 0, controls = 0, controls_port = 0, port = 0, queue_place = 0, request = 0, slot = 0;
	uint8_t saved_board_control = 0;
	uint8_t coin_port = 0, mode_before_firq = 0, test_inputs = 0, sound_irq_read = 0, watchdog_read = 0;
	uint16_t sound_slot_place = 0, sound_command = 0, layer_a_x = 0, layer_a_chip_x = 0, layer_a_x_swapped = 0, layer_b_x = 0, layer_b_chip_x = 0, layer_b_x_swapped = 0, kept_layer_a_x = 0, kept_layer_a_y = 0, kept_layer_b_x = 0, kept_layer_b_y = 0, camera_x_low = 0, camera_y_low = 0, cemetery_scroll_low = 0;

	disable_irq();
	io_write8(tile_chip_irq_control, 0xFBu);
	enable_irq();
	take_interrupts();
	io_write8(tile_chip_irq_control, 0xFFu);
	saved_board_control = board_control;
	coins_inserted = 0u;
	coin_inputs_before = coin_inputs_last;
	coin_inputs_last = coin_inputs;
	coin_port = io_read8(coin_switch_port);
	coin_inputs = ~coin_port;
	mode_before_firq = game_mode;
	firq_point();
	take_interrupts();
	if (mode_before_firq != 0u)
	{
		if (slot_1_counter_time == 0u)
		{
			if (slot_1_counter_pulses != 0u)
			{
				slot_1_counter_pulses--;
				output = board_output | 1u;
				board_output = output;
				io_write8(board_output_register, output);
				slot_1_counter_time = 8u;
			}
		}
		else
		{
			slot_1_counter_time--;
			if (slot_1_counter_time != 4u)
			{
				output = board_output & ~1u;
				board_output = output;
				io_write8(board_output_register, output);
			}
		}
		if (four_coin_slots == 0u)
		{
			if (slot_2_counter_time == 0u)
			{
				if (slot_2_counter_pulses != 0u)
				{
					slot_2_counter_pulses--;
					output = board_output | 2u;
					board_output = output;
					io_write8(board_output_register, output);
					slot_2_counter_time = 8u;
				}
			}
			else
			{
				slot_2_counter_time--;
				if (slot_2_counter_time != 4u)
				{
					output = board_output & ~2u;
					board_output = output;
					io_write8(board_output_register, output);
				}
			}
		}
		coin_bit = 0x100u;
		coin_inserted(&coin_bit, &coin_dropped);
		if (coin_dropped)
		{
			slot = slot_credits_ADDRESS;
			add_coin(slot, (uint8_t)coin_bit);
		}
		coin_bit = 0x200u;
		coin_inserted(&coin_bit, &coin_dropped);
		b = (uint8_t)coin_bit;
		if (coin_dropped)
		{
			slot = slot_2_credits_ADDRESS;
			coin_bit = add_coin(slot, (uint8_t)coin_bit);
			b = (uint8_t)coin_bit;
		}
		if (four_coin_slots != 0u)
		{
			coin_bit = 0x400u;
			coin_inserted(&coin_bit, &coin_dropped);
			if (coin_dropped)
			{
				slot = slot_3_credits_ADDRESS;
				add_coin(slot, (uint8_t)coin_bit);
			}
			coin_bit = 0x800u;
			coin_inserted(&coin_bit, &coin_dropped);
			b = (uint8_t)coin_bit;
			if (coin_dropped)
			{
				slot = slot_4_credits_ADDRESS;
				coin_bit = add_coin(slot, (uint8_t)coin_bit);
				b = (uint8_t)coin_bit;
			}
		}
		test_inputs = io_read8(test_eeprom_port);
		if ((test_inputs & 1u) == 0u)
		{
			palette_request_kind = 3u;
			request = 0u;
			palette_request(slot, request);
			b = 0u;
			in_attract = 0u;
			game_mode = 0u;
			mode_step = 0u;
			mode_phase = 0u;
			game_step = 0u;
		}
	}
	queue_place = sound_queue_read;
	if (queue_place != sound_queue_write)
	{
		sound_slot_place = queue_place;
		queue_place = sound_slot_place + 2u;
		sound_command = mem_read16(sound_slot_place);
		b = (uint8_t)sound_command;
		io_write16(sound_command_port, ((uint32_t)(sound_command >> 8) << 8) | b);
		sound_irq_read = io_read8(sound_irq_port);
		if (queue_place > sound_queue_ADDRESS + 0x3Bu)
			queue_place = sound_queue_ADDRESS;
		sound_queue_read = queue_place;
	}
	if (irq_busy != 0u)
	{
		control = saved_board_control;
		board_control = control;
		io_write8(board_control_register, control);
		return;
	}
	frame_count++;
	irq_busy = 1u;
	watchdog_read = io_read8(watchdog_port);
	d = b;
	run_palette_jobs(d);
	port = player_1_input_port;
	controls = player_controls_ADDRESS;
	read_controls(controls, port);
	port = player_2_input_port;
	controls = player_controls_ADDRESS + 0x4u;
	read_controls(controls, port);
	port = player_3_input_port;
	controls = player_controls_ADDRESS + 0x8u;
	read_controls(controls, port);
	controls_port = player_4_input_port;
	controls = player_controls_ADDRESS + 0xCu;
	read_controls(controls, controls_port);
	layer_a_x = layer_a_scroll_x;
	layer_a_chip_x = layer_a_x - 0x5Au;
	scroll_x_high = (layer_a_chip_x >> 8) & 1u;
	layer_a_x_swapped = scroll_x_high | 0x1000u;
	io_write16(tile_chip_layer_a_x, ((uint32_t)(uint8_t)layer_a_chip_x << 8) | (uint8_t)layer_a_x_swapped);
	io_write8(tile_chip_layer_a_y, (uint8_t)layer_a_scroll_y - 0x10u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	layer_b_x = layer_b_scroll_x;
	layer_b_chip_x = layer_b_x - 0x5Au;
	scroll_x_high = (layer_b_chip_x >> 8) & 1u;
	layer_b_x_swapped = scroll_x_high | 0x1000u;
	io_write16(tile_chip_layer_b_x, ((uint32_t)(uint8_t)layer_b_chip_x << 8) | (uint8_t)layer_b_x_swapped);
	io_write8(tile_chip_layer_b_y, (uint8_t)layer_b_scroll_y - 0x10u);
	kept_layer_a_x = layer_a_scroll_x;
	layer_a_last_scroll_x = kept_layer_a_x;
	kept_layer_a_y = layer_a_scroll_y;
	layer_a_last_scroll_y = kept_layer_a_y;
	kept_layer_b_x = layer_b_scroll_x;
	layer_b_last_scroll_x = kept_layer_b_x;
	kept_layer_b_y = layer_b_scroll_y;
	layer_b_last_scroll_y = kept_layer_b_y;
	last_stage_scroll_x = (last_stage_scroll_x & 0xFFu) | (((uint8_t)(camera_x >> 8u) & 0xFFu) << 8u);
	camera_x_low = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	AT16(last_stage_scroll_x, -1) = camera_x_low;
	last_stage_scroll_y = (last_stage_scroll_y & 0xFFu) | (((uint8_t)(camera_y >> 8u) & 0xFFu) << 8u);
	camera_y_low = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	AT16(last_stage_scroll_y, -1) = camera_y_low;
	last_cemetery_scroll_high = (uint8_t)(cemetery_scroll >> 8u);
	cemetery_scroll_low = (((uint32_t)(cemetery_scroll & 0xFFu) << 8u) | cemetery_scroll_fraction);
	b = (uint8_t)cemetery_scroll_low;
	last_cemetery_scroll_low = ((uint32_t)(cemetery_scroll_low >> 8) << 8) | b;
	do
	{
	} while (dma_pending != 0u);
	dma_pending = 1u;
	d = b;
	switch ((int8_t)(uint8_t)((uint32_t)game_mode << 1))
	{
	case 0:
		test_mode(controls_port, d);
		break;
	case 2:
		attract(controls_port);
		break;
	case 4:
		game_mode_frame(controls_port);
		break;
	case 6:
		test_mode_start();
		break;
	case 8:
		test_mode_run(d);
		break;
	}
	draw_scrolled_layer_edges();
	update_sprites();
	control = saved_board_control;
	board_control = control;
	io_write8(board_control_register, control);
	enable_firq();
	take_interrupts();
	control = board_control | 4u;
	board_control = control;
	io_write8(board_control_register, control);
	sprite_control = sprite_chip_control | 0x10u;
	sprite_chip_control = sprite_control;
	io_write8(sprite_chip_control_register, sprite_control);
	window_bank = 0x20u;
	set_lines(window_bank);
	irq_busy = 0u;
}

/* The test mode's routine at each frame, by game_scene: its start, then bank 2F's test mode. */
void test_mode(uint16_t u, uint8_t d)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_step << 1))
		{
		case 0:
			test_mode_start();
			return;
		case 2:
			break;
		case -6:
			continue;
		case -4:
			attract(u);
			return;
		case -2:
			game_mode_frame(u);
			return;
		}
		break;
	}
	test_mode_run(d);
}

/* Starts the test mode: clears the tile layers, the scores and the game's variables, and the test mode's
   variables at 5900-59EF. */
void test_mode_start(void)
{
	uint16_t clear_from = 0, clear_to = 0, count = 0;

	clear_tile_layers();
	reset_for_game();
	clear_from = test_mode_variables_ADDRESS;
	clear_to = 0x5901u;
	test_mode_variables = 0u;
	count = 0xEFu;
	while (count != 0u)
	{
		mem_write8(clear_to, mem_read8(clear_from));
		clear_from++;
		clear_to++;
		count--;
	}
	mode_step++;
}

/* Runs a frame of bank 2F's test mode. */
void test_mode_run(uint8_t d)
{
	uint8_t d_2 = 0;
	uint8_t saved_b = 0;

	saved_b = d;
	window_bank = 0x2Fu;
	set_lines(window_bank);
	d_2 = saved_b;
	test_run_page(d_2);
}

/* The FIRQ's routine, once the sprite DMA is over: turns the FIRQ and the K053246's interrupt off and
   clears dma_pending, which lets the next frame's sprites be written. */
void firq_handler(void)
{
	uint8_t control = 0, sprite_control = 0;

	disable_firq();
	control = board_control & ~4u;
	board_control = control;
	io_write8(board_control_register, control);
	sprite_control = sprite_chip_control & 0xEFu;
	sprite_chip_control = sprite_control;
	io_write8(sprite_chip_control_register, sprite_control);
	dma_pending = 0u;
}
