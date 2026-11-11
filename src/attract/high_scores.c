/**
 *    Name:        attract/high_scores.c
 *    Description: the attract's high score table
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The attract's high score table: puts its heading, then clears the objects' sprites and sets the page's
   time (192 frames). */
void high_scores_set_up(void)
{
	OBJECT(OBJECT_ADDRESS(14))->flags = 0x80u;
	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	OBJECT(OBJECT_ADDRESS(14))->kind = 0xFu;
	OBJECT(OBJECT_ADDRESS(14))->animation = 0x9Fu;
	OBJECT(OBJECT_ADDRESS(14))->x = 0x138u;
	OBJECT(OBJECT_ADDRESS(14))->y = 0x98u;
	high_scores_clear_sprites();
}

/* The attract's high score table: clears the objects' sprites and sets the page's time (192 frames). */
void high_scores_clear_sprites(void)
{
	uint16_t object = 0, object_count = 0;

	object = OBJECT_ADDRESS(0);
	object_count = 0x800u;
	reserve_objects_for_sprites(object, object_count);
	scene_timer = (scene_timer & 0xFFu) | 0xC000u;
	game_step++;
}

/* The attract's high score table: shows places 1 to 5; when its time is up, starts the wavy exit with
   its sound (0700). */
void high_scores_show_first(void)
{
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS;
	first_place = 0x100u;
	high_scores_print_entries(entry, first_place);
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	io_write8(tile_chip_scroll_control, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: waves the page line by line and wobbles its sprites' height, then
   clears them. */
void high_scores_wave_out(void)
{
	uint8_t control = 0, height = 0, wave = 0;
	uint16_t command = 0, line_scroll = 0, sprite = 0;
	uint8_t wait_left = 0, discarded_read = 0, rows_left = 0;
	uint16_t wave_product = 0, row_scroll = 0, row_scroll_at = 0;

	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		command = 0u;
		vector_queue_sound(command);
		discarded_read = io_read8(tile_chip_scroll_control);
		io_write8(tile_chip_scroll_control, 0u);
		vector_clear_sprites();
		game_step++;
		return;
	}
	line_scroll = tile_chip_layer_a_x;
	wave_lines_left = 0u;
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	do
	{
		wave_product = 0xDu * table_wave_offset;
		row_scroll = wave_product - 0x7001u;
		wave = (uint8_t)row_scroll;
		row_scroll_at = line_scroll;
		line_scroll = row_scroll_at + 2u;
		mem_write16(row_scroll_at, ((uint32_t)(row_scroll >> 8) << 8) | wave);
		table_wave_offset = wave;
		rows_left = wave_lines_left;
		wave_lines_left = rows_left - 1u;
	} while (rows_left != 1u);
	table_wave_offset = 0xDu * (uint8_t)frame_count;
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	sprite = 0x2000u;
	while (mem_read8(sprite) != 0u)
	{
		height = 0xDu * table_wave_offset;
		if (height < 0x30u)
			height = 0x30u;
		mem_write8(sprite + 0xBu, height);
		sprite += 0x10u;
	}
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
}

/* The attract's high score table: shows places 6 to 10; when its time is up, starts the wavy exit. */
void high_scores_show_second(void)
{
	uint16_t command = 0, entry = 0, first_place = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	entry = high_scores_ADDRESS + 0x28u;
	first_place = 0x600u;
	high_scores_print_entries(entry, first_place);
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	io_write8(tile_chip_scroll_control, 3u);
	scene_timer = (scene_timer & 0xFFu) | 0x8000u;
	command = 0x700u;
	vector_queue_sound(command);
	game_step++;
}

/* The attract's high score table: fades the colours out. */
void high_scores_fade_out(uint16_t palette_job)
{
	uint16_t request = 0;

	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(palette_job, request);
	vector_clear_layer_a();
	scene_timer = (scene_timer & 0xFFu) | 0x4000u;
	game_step++;
}

/* The attract's high score table: after the fade, clears the objects and goes on to the attract's next
   part. */
void high_scores_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	wait_left = (uint8_t)(scene_timer >> 8u);
	scene_timer = (scene_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	vector_clear_objects(&ignored16, &ignored16_2);
	mode_phase++;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}

/* The high score table: prints five entries, numbered from the given place: place, initials, score and
   the player's little animated face. */
void high_scores_print_entries(uint16_t entry, uint16_t first_place)
{
	uint32_t carry = 0, half_carry = 0;
	uint8_t icon_frame = 0, place = 0, tens = 0;
	uint16_t entry_icon = 0, icons = 0, letter_and_colour = 0, sprite = 0;
	uint8_t saved_entry_low = 0, saved_entry_high = 0, digits_low_then_icon = 0, digits_high_then_sprite_low = 0, sprite_high = 0;
	uint8_t place_tens = 0, initials_to_print = 0, digits_left = 0, entries_left = 0;
	uint16_t place_tens_x = 0, x_after_tens = 0, initial_at = 0, initial_x = 0, x_after_initial = 0, score_at = 0, bcd_score = 0, digits = 0, digits_shifted = 0, stored_digits = 0, digit_x = 0, x_after_digit = 0, entry_y = 0, next_entry_y = 0;

	sprite = 0x2000u;
	table_place = first_place >> 8;
	table_entries_left = 5u;
	sprite_text_x = 0x88u;
	sprite_text_y = 0x130u;
	do
	{
		saved_entry_high = entry >> 8;
		saved_entry_low = (uint8_t)entry;
		place_tens = (((table_place >> 1) >> 1) >> 1) >> 1;
		tens = place_tens;
		if (place_tens != 0u)
		{
			letter_and_colour = (uint32_t)(uint8_t)(tens + 0x30u) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
		}
		place_tens_x = sprite_text_x;
		x_after_tens = place_tens_x + 0x10u;
		sprite_text_x = x_after_tens;
		letter_and_colour = (uint32_t)(uint8_t)((table_place & 0xFu) + 0x30u) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		table_characters_left = 3u;
		sprite_text_x = 0xB8u;
		do
		{
			initial_at = entry;
			entry = initial_at + 1u;
			letter_and_colour = (uint32_t)mem_read8(initial_at) << 8;
			sprite = print_sprite_letter(sprite, letter_and_colour);
			initial_x = sprite_text_x;
			x_after_initial = initial_x + 0x10u;
			sprite_text_x = x_after_initial;
			initials_to_print = table_characters_left;
			table_characters_left = initials_to_print - 1u;
		} while (initials_to_print != 1u);
		sprite_text_x = 0xE0u;
		table_characters_left = 4u;
		score_at = entry;
		entry_icon = score_at + 2u;
		bcd_score = mem_read16(score_at);
		digits_low_then_icon = bcd_score;
		digits_high_then_sprite_low = bcd_score >> 8;
		table_digit_shown = 0u;
		do
		{
			if (table_digit_shown != 0u || table_characters_left == 1u || (digits_high_then_sprite_low & ~0xFu) != 0u)
			{
				letter_and_colour = (uint32_t)(uint8_t)(((((digits_high_then_sprite_low >> 1) >> 1) >> 1) >> 1) + 0x30u) << 8;
				sprite = print_sprite_letter(sprite, letter_and_colour);
				table_digit_shown++;
			}
			digits = ((uint32_t)digits_high_then_sprite_low << 8) | digits_low_then_icon;
			digits_shifted = (uint32_t)digits << 4;
			stored_digits = digits_shifted;
			digits_high_then_sprite_low = stored_digits >> 8;
			digits_low_then_icon = stored_digits;
			digit_x = sprite_text_x;
			x_after_digit = digit_x + 0x10u;
			sprite_text_x = x_after_digit;
			digits_left = table_characters_left;
			table_characters_left = digits_left - 1u;
		} while (digits_left != 1u);
		sprite_text_x = 0x128u;
		digits_low_then_icon = mem_read8(entry_icon);
		icons = high_score_icons_ADDRESS;
		sprite_high = sprite >> 8;
		digits_high_then_sprite_low = (uint8_t)sprite;
		icon_frame = ((((uint8_t)(((uint16_t)(((uint32_t)sprite_high << 8) | digits_high_then_sprite_low) >> 3) + (uint8_t)frame_count) >> 1) >> 1) >> 1) >> 1;
		if ((icon_frame & 4u) == 0u)
			icon_frame = 0u;
		letter_and_colour = (uint32_t)(uint8_t)((icon_frame & 3u) + HIGH_SCORE_ICON(icons + (int8_t)digits_low_then_icon)) << 8;
		sprite = print_sprite_letter(sprite, letter_and_colour);
		sprite_text_x = 0x88u;
		entry_y = sprite_text_y;
		next_entry_y = entry_y - 0x18u;
		sprite_text_y = next_entry_y;
		place = table_place;
		half_carry = ((uint8_t)(place ^ 1u ^ (place + 1u)) >> 4) & 1u;
		carry = (uint8_t)(place + 1u) < place;
		table_place = konami_daa((uint8_t)(place + 1u), half_carry, carry);
		entry = (((uint32_t)saved_entry_high << 8) | saved_entry_low) + 8u;
		entries_left = table_entries_left;
		table_entries_left = entries_left - 1u;
	} while (entries_left != 1u);
}

/* Puts a letter as a sprite of the given colour at the current place, into the next sprite of the sprite
   RAM. */
uint16_t print_sprite_letter(uint16_t sprite, uint16_t letter_and_colour)
{
	uint16_t colour = 0;
	uint8_t saved_colour = 0;

	saved_colour = (uint8_t)letter_and_colour;
	sprite_text_code = ((uint32_t)sprite_font_code_high[0] << 8) | sprite_font_codes[(int8_t)((uint8_t)((letter_and_colour >> 8) - 0x30u))];
	colour = saved_colour;
	sprite = put_sprite(sprite, colour);
	return sprite;
}

/* Unused: would put a sprite code taken from a table, colour 0F, into the next sprite. */
void unused_print_sprite_code(uint16_t sprite_codes, uint16_t sprite)
{
	uint16_t colour = 0;
	uint16_t sprite_code = 0;

	sprite_code = mem_read16(sprite_codes + (int8_t)((uint32_t)sprite_code_index << 1));
	sprite_text_code = sprite_code;
	colour = 0xFu;
	put_sprite(sprite, colour);
}

/* Writes a sprite straight into the sprite RAM: the code, the current place, the given colour, at normal
   size; then moves on to the next sprite. */
uint16_t put_sprite(uint16_t sprite, uint16_t colour)
{
	uint8_t control = 0;
	uint8_t saved_flags = 0;
	uint16_t sprite_code = 0, sprite_x = 0, sprite_y = 0;

	saved_flags = colour >> 8;
	control = board_control | 2u;
	board_control = control;
	io_write8(board_control_register, control);
	io_write8(sprite, saved_flags | 0x80u);
	mem_write16(sprite + 0xCu, colour | 0x20u);
	sprite_code = sprite_text_code;
	mem_write16(sprite + 2u, sprite_code);
	sprite_x = sprite_text_x;
	mem_write16(sprite + 6u, sprite_x);
	sprite_y = sprite_text_y;
	mem_write16(sprite + 4u, sprite_y);
	mem_write16(sprite + 8u, 0x40u);
	mem_write16(sprite + 0xAu, 0x40u);
	sprite += 0x10u;
	control = board_control & ~3u;
	board_control = control;
	io_write8(board_control_register, control);
	return sprite;
}

/* The attract's high score step, by mode_phase */
void attract_high_scores(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)mode_phase << 1))
		{
		case 0:
			high_scores_start(u);
			return;
		case 2:
			high_scores_draw_background();
			return;
		case 4:
			high_scores_show(u);
			return;
		case 6:
			high_scores_close(u);
			return;
		case 8:
			warning_skip(u);
			return;
		case 10:
			warning_first_page();
			return;
		case 12:
			warning_second_page();
			return;
		case 14:
			warning_end(u);
			return;
		case 16:
			coin_title_start();
			return;
		case 18:
			coin_title_draw();
			return;
		case 20:
			break;
		case -32:
			attract_opening_scene(u);
			return;
		case -30:
			attract_demo(u);
			return;
		case -28:
			attract_title(u);
			return;
		case -26:
			continue;
		case -24:
			attract_warning(u);
			return;
		case -22:
			attract_coin_title(u);
			return;
		case -20:
			attract_clear_screen();
			return;
		case -18:
			attract_wait_clear();
			return;
		case -16:
			attract_opening_run(u);
			return;
		case -14:
			attract_next_scene();
			return;
		case -12:
			attract_title_clear();
			return;
		case -10:
			attract_title_wait(u);
			return;
		case -8:
			title_show_notices();
			return;
		case -6:
			title_end();
			return;
		case -4:
			demo_start();
			return;
		case -2:
			demo_play(u);
			return;
		}
		break;
	}
	coin_title_blink();
}

/* Starts the high score screen: queues the tile layers' clear, sets the background colour, the scroll
   and the palettes */
void high_scores_start(uint16_t palette_job)
{
	uint16_t job = 0, request = 0;

	job = 0u;
	queue_job(job);
	palette_request_kind = 3u;
	request = 0u;
	palette_job = palette_request(palette_job, request);
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0xFFF0u;
	palette_request_kind = 1u;
	request = 0xF01u;
	palette_request(palette_job, request);
	attract_timer = 0x40u;
	mode_phase++;
}

/* Once the layers are clear, draws map scene 02 on both tile layers as the high score screen's
   background */
void high_scores_draw_background(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, request = 0, u = 0;

	if (layer_clear_pending != 0u)
		return;
	map_scene = 2u;
	map_area = 0u;
	set_area_tile_banks();
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_and_columns = 0x26u;
	draw_layer_columns(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x126u;
	draw_layer_columns(layer_and_columns, &ignored16, &u);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	palette_request_kind = 3u;
	request = 0x7A53u;
	palette_request(u, request);
	mode_phase++;
}

/* Runs bank 11's high score table for the frame */
void high_scores_show(uint16_t palette_job)
{
	window_bank = 0x11u;
	set_lines(window_bank);
	switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
	{
	case 0:
		high_scores_set_up();
		return;
	case 2:
		high_scores_show_first();
		return;
	case 4:
	case 10:
		high_scores_wave_out();
		return;
	case 6:
		high_scores_clear_sprites();
		return;
	case 8:
		high_scores_show_second();
		return;
	case 12:
		high_scores_fade_out(palette_job);
		return;
	case 14:
		high_scores_end();
		return;
	}
}

/* Ends the high score screen: the background colour, the sprites, the palettes and the scroll reset, and
   the attract's next step */
void high_scores_close(uint16_t palette_job)
{
	uint16_t request = 0;

	palette_request_kind = 3u;
	request = 0u;
	palette_job = palette_request(palette_job, request);
	clear_sprites();
	palette_request_kind = 1u;
	request = 0xF00u;
	palette_request(palette_job, request);
	layer_a_scroll_x = 0u;
	layer_b_scroll_x = 0u;
	mode_step++;
	mode_phase = 0u;
	game_step = 0u;
	step_phase = 0u;
	step_subphase = 0u;
	step_countdown = 0u;
}
