/**
 *    Name:        system/interrupts.c
 *    Description: the IRQ's handler (the K052109's, at VBLANK: the inputs, the coin counters, the jobs) and the FIRQ's (the sprite DMA's)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint32_t carry = 0;
	uint8_t b = 0, control = 0, d_2 = 0, output = 0, scroll_x_high = 0, sprite_control = 0;
	uint16_t controls = 0, controls_port = 0, d = 0, port = 0, queue_place = 0, request = 0, slot = 0, y = 0;
	uint8_t saved_board_control = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t7 = 0;
	uint16_t t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0;

	disable_irq();
	io_write8(0x1D00u, 0xFBu);
	enable_irq();
	take_interrupts();
	io_write8(0x1D00u, 0xFFu);
	saved_board_control = board_control;
	coins_inserted = 0u;
	coin_inputs_before = coin_inputs_last;
	coin_inputs_last = coin_inputs;
	t1 = io_read8(0x1F80u);
	coin_inputs = ~t1;
	t2 = game_mode;
	firq_point();
	take_interrupts();
	if (t2 != 0u)
	{
		if (slot_1_counter_time == 0u)
		{
			if (slot_1_counter_pulses != 0u)
			{
				slot_1_counter_pulses--;
				output = board_output | 1u;
				board_output = output;
				io_write8(0x1FC0u, output);
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
				io_write8(0x1FC0u, output);
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
					io_write8(0x1FC0u, output);
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
					io_write8(0x1FC0u, output);
				}
			}
		}
		d = 0x100u;
		coin_inserted(&d, &carry);
		if (carry)
		{
			slot = slot_credits_ADDRESS;
			add_coin(slot, (uint8_t)d);
		}
		d = 0x200u;
		coin_inserted(&d, &carry);
		b = (uint8_t)d;
		if (carry)
		{
			slot = slot_2_credits_ADDRESS;
			d = add_coin(slot, (uint8_t)d);
			b = (uint8_t)d;
		}
		if (four_coin_slots != 0u)
		{
			d = 0x400u;
			coin_inserted(&d, &carry);
			if (carry)
			{
				slot = slot_3_credits_ADDRESS;
				add_coin(slot, (uint8_t)d);
			}
			d = 0x800u;
			coin_inserted(&d, &carry);
			b = (uint8_t)d;
			if (carry)
			{
				slot = slot_4_credits_ADDRESS;
				d = add_coin(slot, (uint8_t)d);
				b = (uint8_t)d;
			}
		}
		t3 = io_read8(0x1F81u);
		if ((t3 & 1u) == 0u)
		{
			palette_request_kind = 3u;
			request = 0u;
			palette_request(request, &y, &slot);
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
		t4 = queue_place;
		queue_place = t4 + 2u;
		t5 = mem_read16(t4);
		b = (uint8_t)t5;
		io_write16(0x1FC6u, ((uint32_t)(t5 >> 8) << 8) | b);
		t6 = io_read8(0x1FC4u);
		if (queue_place > sound_queue_ADDRESS + 0x3Bu)
			queue_place = sound_queue_ADDRESS;
		sound_queue_read = queue_place;
	}
	if (irq_busy != 0u)
	{
		control = saved_board_control;
		board_control = control;
		io_write8(0x1FC2u, control);
		return;
	}
	frame_count++;
	irq_busy = 1u;
	t7 = io_read8(0x1FCAu);
	d_2 = b;
	y = run_palette_jobs(y, d_2);
	port = 0x1F90u;
	controls = player_controls_ADDRESS;
	read_controls(controls, port);
	port = 0x1F91u;
	controls = player_controls_ADDRESS + 0x4u;
	read_controls(controls, port);
	port = 0x1F92u;
	controls = player_controls_ADDRESS + 0x8u;
	read_controls(controls, port);
	controls_port = 0x1F93u;
	controls = player_controls_ADDRESS + 0xCu;
	read_controls(controls, controls_port);
	t8 = layer_a_scroll_x;
	t9 = t8 - 0x5Au;
	scroll_x_high = (t9 >> 8) & 1u;
	t10 = scroll_x_high | 0x1000u;
	io_write16(0x1A00u, ((uint32_t)(uint8_t)t9 << 8) | (uint8_t)t10);
	io_write8(0x180Cu, (uint8_t)layer_a_scroll_y - 0x10u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	t11 = layer_b_scroll_x;
	t12 = t11 - 0x5Au;
	scroll_x_high = (t12 >> 8) & 1u;
	t13 = scroll_x_high | 0x1000u;
	io_write16(0x3A00u, ((uint32_t)(uint8_t)t12 << 8) | (uint8_t)t13);
	io_write8(0x380Cu, (uint8_t)layer_b_scroll_y - 0x10u);
	t14 = layer_a_scroll_x;
	layer_a_last_scroll_x = t14;
	t15 = layer_a_scroll_y;
	layer_a_last_scroll_y = t15;
	t16 = layer_b_scroll_x;
	layer_b_last_scroll_x = t16;
	t17 = layer_b_scroll_y;
	layer_b_last_scroll_y = t17;
	last_stage_scroll_x = (last_stage_scroll_x & 0xFFu) | (((uint8_t)(camera_x >> 8u) & 0xFFu) << 8u);
	t18 = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	AT16(last_stage_scroll_x, -1) = t18;
	last_stage_scroll_y = (last_stage_scroll_y & 0xFFu) | (((uint8_t)(camera_y >> 8u) & 0xFFu) << 8u);
	t19 = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	AT16(last_stage_scroll_y, -1) = t19;
	last_cemetery_scroll_high = (uint8_t)(cemetery_scroll >> 8u);
	t20 = (((uint32_t)(cemetery_scroll & 0xFFu) << 8u) | cemetery_scroll_fraction);
	b = (uint8_t)t20;
	last_cemetery_scroll_low = ((uint32_t)(t20 >> 8) << 8) | b;
	do
	{
	} while (dma_pending != 0u);
	dma_pending = 1u;
	d_2 = b;
	switch ((int8_t)(uint8_t)((uint32_t)game_mode << 1))
	{
	case 0:
		test_mode(y, controls_port, d_2);
		break;
	case 2:
		attract(y, controls_port);
		break;
	case 4:
		game_mode_frame(controls_port);
		break;
	case 6:
		test_mode_start();
		break;
	case 8:
		test_mode_run(y, d_2);
		break;
	}
	draw_scrolled_layer_edges();
	update_sprites();
	control = saved_board_control;
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
	window_bank = 0x20u;
	set_lines(window_bank);
	irq_busy = 0u;
}

/* The test mode's routine at each frame, by game_scene: its start, then bank 2F's test mode. */
void test_mode(uint16_t y, uint16_t u, uint8_t d)
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
			attract(y, u);
			return;
		case -2:
			game_mode_frame(u);
			return;
		}
		break;
	}
	test_mode_run(y, d);
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
void test_mode_run(uint16_t y, uint8_t d)
{
	uint8_t d_2 = 0;
	uint8_t stack = 0;

	stack = d;
	window_bank = 0x2Fu;
	set_lines(window_bank);
	d_2 = stack;
	test_run_page(y, d_2);
}

/* The FIRQ's routine, once the sprite DMA is over: turns the FIRQ and the K053246's interrupt off and
   clears dma_pending, which lets the next frame's sprites be written. */
void firq_handler(void)
{
	uint8_t control = 0, sprite_control = 0;

	disable_firq();
	control = board_control & ~4u;
	board_control = control;
	io_write8(0x1FC2u, control);
	sprite_control = sprite_chip_control & 0xEFu;
	sprite_chip_control = sprite_control;
	io_write8(0x1FA5u, sprite_control);
	dma_pending = 0u;
}
