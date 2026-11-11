/**
 *    Name:        attract/intro.c
 *    Description: the attract's opening and the family's profiles
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* The attract's opening, by its substep */
void attract_opening(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_opening_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_opening_start(u);
			return;
		case 2:
			attract_opening_zoom();
			return;
		case 4:
			attract_opening_end_start();
			return;
		case 6:
			attract_opening_end_scroll();
			return;
		case 8:
			attract_opening_end_wait();
			return;
		case 10:
			attract_bart_scene_start();
			return;
		case 12:
			attract_bart_scene_move();
			return;
		case 14:
			attract_bart_scene_wait();
			return;
		case 16:
			attract_bart_profile_start();
			return;
		case 18:
			attract_bart_profile_type();
			return;
		case 20:
			attract_bart_profile_end(u);
			return;
		case 22:
			attract_homer_scene_start();
			return;
		case 24:
			attract_homer_scene_wait();
			return;
		case 26:
			attract_homer_scene_end();
			return;
		case 28:
			attract_homer_profile_start();
			return;
		case 30:
			attract_homer_profile_type();
			return;
		case 32:
			attract_homer_profile_end();
			return;
		case 34:
			attract_lisa_scene_start();
			return;
		case 36:
			attract_lisa_scene_walk();
			return;
		case 38:
			attract_lisa_scene_play();
			return;
		case 40:
			attract_lisa_profile_start();
			return;
		case 42:
			attract_lisa_profile_type();
			return;
		case 44:
			attract_lisa_profile_end(u);
			return;
		case 46:
			attract_marge_scene_start();
			return;
		case 48:
			attract_marge_scene_wait();
			return;
		case 50:
			attract_marge_scene_pose();
			return;
		case 52:
			attract_marge_scene_end();
			return;
		case 54:
			attract_marge_profile_start(u);
			return;
		case 56:
			attract_marge_profile_type();
			return;
		case 58:
			attract_marge_profile_end();
			return;
		case 60:
			attract_leap_start();
			return;
		case 62:
			attract_leap_rise();
			return;
		case 64:
			attract_leap_fall();
			return;
		case 66:
			attract_leap_land();
			return;
		case 68:
			attract_leap_end();
			return;
		case 70:
			attract_last_screen_start(u);
			return;
		case 72:
			attract_last_screen_wait(u);
			return;
		case 74:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 76:
		case 82:
			attract_profile_move_stop(object);
			return;
		case 78:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 80:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 84:
			break;
		case -16:
			continue;
		case -14:
			attract_opening_end(u);
			return;
		case -12:
			attract_bart(u);
			return;
		case -10:
			attract_homer(u);
			return;
		case -8:
			attract_lisa(u);
			return;
		case -6:
			attract_marge(u);
			return;
		case -4:
			attract_leap(u);
			return;
		case -2:
			attract_last_screen(u);
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Sets the opening up: palettes, the layers, the attract song and the big picture at full zoom */
void attract_opening_start(uint16_t palette_job)
{
	uint32_t carry = 0;
	uint8_t tile_code = 0;
	uint16_t command = 0, object = 0, picture = 0, request = 0, tile = 0;
	uint16_t layer_a_tile = 0, layer_b_tile = 0;

	palette_request_kind = 3u;
	request = 0x7A53u;
	palette_job = vector_palette_request(palette_job, request);
	palette_request_kind = 1u;
	request = 0xF02u;
	vector_palette_request(palette_job, request);
	attract_reset_layers();
	layer_a_scroll_x = 0x10u;
	layer_b_scroll_x = 0x10u;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	tile = 0x2800u;
	tile_code = 0x10u;
	do
	{
		mem_write8(tile - 0x2000u, 0u);
		layer_a_tile = tile;
		tile = layer_a_tile + 1u;
		mem_write8(layer_a_tile, tile_code);
	} while (tile != 0x3000u);
	tile = 0x3000u;
	tile_code = 0x10u;
	do
	{
		mem_write8(tile - 0x2000u, 0u);
		layer_b_tile = tile;
		tile = layer_b_tile + 1u;
		mem_write8(layer_b_tile, tile_code);
	} while (tile != 0x3800u);
	attract_draw_layers();
	command = 0x8000u;
	carry = vector_queue_sound(command);
	object = OBJECT_ADDRESS(14);
	picture = attract_opening_picture_ADDRESS;
	OBJECT(OBJECT_ADDRESS(14))->action = 0xFFu;
	OBJECT(OBJECT_ADDRESS(14))->action_step = 0u;
	OBJECT(OBJECT_ADDRESS(14))->zoom_x = 0xFFu;
	OBJECT(OBJECT_ADDRESS(14))->zoom_y = 0xFFu;
	OBJECT(OBJECT_ADDRESS(14))->attributes = 0x30u;
	attract_put_picture(&object, &picture);
	OBJECT(object - 0x60u)->flags = 0x90u;
	step_timer = (step_timer & 0xFFu) | 0xA000u;
	step_phase++;
}

/* Shrinks the picture while the two layers slide apart, then the next step */
void attract_opening_zoom(void)
{
	uint32_t carry = 0;
	uint8_t zoom = 0;
	uint16_t object = 0;
	uint8_t wait_left = 0;
	uint16_t action = 0, new_zoom = 0, layer_a_x_low = 0, old_layer_a_x_low = 0, new_layer_a_x_low = 0, layer_b_x_low = 0, old_layer_b_x_low = 0;
	uint32_t action_halfword = 0;

	object = OBJECT_ADDRESS(14);
	OBJECT(OBJECT_ADDRESS(14))->flags = 0x90u;
	action = (((uint32_t)OBJECT(OBJECT_ADDRESS(14))->action << 8u) | OBJECT(OBJECT_ADDRESS(14))->action_step);
	new_zoom = action - 0xC0u;
	zoom = (uint8_t)(new_zoom >> 8);
	action_halfword = ((uint32_t)zoom << 8) | (new_zoom & 0xFFu);
	OBJECT(OBJECT_ADDRESS(14))->action = (uint8_t)(action_halfword >> 8u);
	OBJECT(OBJECT_ADDRESS(14))->action_step = (uint8_t)action_halfword;
	OBJECT(OBJECT_ADDRESS(14))->zoom_x = zoom;
	OBJECT(OBJECT_ADDRESS(14))->zoom_y = zoom;
	if (zoom <= 0x40u)
		OBJECT(object)->attributes = 0x10u;
	layer_a_x_low = AT16(layer_a_scroll_x, -1);
	old_layer_a_x_low = layer_a_x_low;
	new_layer_a_x_low = old_layer_a_x_low - 0x80u;
	carry = old_layer_a_x_low < 0x80u;
	AT16(layer_a_scroll_x, -1) = new_layer_a_x_low;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | (((uint8_t)(layer_a_scroll_x >> 8u) - carry & 0xFFu) << 8u);
	layer_b_x_low = AT16(layer_b_scroll_x, -1);
	old_layer_b_x_low = layer_b_x_low;
	carry = (uint16_t)(old_layer_b_x_low + 0x80u) < old_layer_b_x_low;
	AT16(layer_b_scroll_x, -1) = old_layer_b_x_low + 0x80u;
	layer_b_scroll_x = (layer_b_scroll_x & 0xFFu) | (((uint8_t)(layer_b_scroll_x >> 8u) + carry & 0xFFu) << 8u);
	if ((frame_count & 1u) == 0u)
	{
		wait_left = (uint8_t)(step_timer >> 8u);
		step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
		if (wait_left == 1u)
		{
			game_step++;
			step_phase = 0u;
		}
	}
}

/* The opening's second part, by its substep */
void attract_opening_end(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_opening_end_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_opening_end_start();
			return;
		case 2:
			attract_opening_end_scroll();
			return;
		case 4:
			attract_opening_end_wait();
			return;
		case 6:
			attract_bart_scene_start();
			return;
		case 8:
			attract_bart_scene_move();
			return;
		case 10:
			attract_bart_scene_wait();
			return;
		case 12:
			attract_bart_profile_start();
			return;
		case 14:
			attract_bart_profile_type();
			return;
		case 16:
			attract_bart_profile_end(u);
			return;
		case 18:
			attract_homer_scene_start();
			return;
		case 20:
			attract_homer_scene_wait();
			return;
		case 22:
			attract_homer_scene_end();
			return;
		case 24:
			attract_homer_profile_start();
			return;
		case 26:
			attract_homer_profile_type();
			return;
		case 28:
			attract_homer_profile_end();
			return;
		case 30:
			attract_lisa_scene_start();
			return;
		case 32:
			attract_lisa_scene_walk();
			return;
		case 34:
			attract_lisa_scene_play();
			return;
		case 36:
			attract_lisa_profile_start();
			return;
		case 38:
			attract_lisa_profile_type();
			return;
		case 40:
			attract_lisa_profile_end(u);
			return;
		case 42:
			attract_marge_scene_start();
			return;
		case 44:
			attract_marge_scene_wait();
			return;
		case 46:
			attract_marge_scene_pose();
			return;
		case 48:
			attract_marge_scene_end();
			return;
		case 50:
			attract_marge_profile_start(u);
			return;
		case 52:
			attract_marge_profile_type();
			return;
		case 54:
			attract_marge_profile_end();
			return;
		case 56:
			attract_leap_start();
			return;
		case 58:
			attract_leap_rise();
			return;
		case 60:
			attract_leap_fall();
			return;
		case 62:
			attract_leap_land();
			return;
		case 64:
			attract_leap_end();
			return;
		case 66:
			attract_last_screen_start(u);
			return;
		case 68:
			attract_last_screen_wait(u);
			return;
		case 70:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 72:
		case 78:
			attract_profile_move_stop(object);
			return;
		case 74:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 76:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 80:
			break;
		case -20:
			attract_opening(u);
			return;
		case -18:
			continue;
		case -16:
			attract_bart(u);
			return;
		case -14:
			attract_homer(u);
			return;
		case -12:
			attract_lisa(u);
			return;
		case -10:
			attract_marge(u);
			return;
		case -8:
			attract_leap(u);
			return;
		case -6:
			attract_last_screen(u);
			return;
		case -4:
			attract_opening_start(u);
			return;
		case -2:
			attract_opening_zoom();
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Draws the next layers while the picture keeps shrinking */
void attract_opening_end_start(void)
{
	uint8_t zoom = 0;
	uint16_t request = 0, u = 0;
	uint16_t action = 0, new_zoom = 0;
	uint32_t action_halfword = 0;

	OBJECT(OBJECT_ADDRESS(14))->flags = 0x90u;
	action = (((uint32_t)OBJECT(OBJECT_ADDRESS(14))->action << 8u) | OBJECT(OBJECT_ADDRESS(14))->action_step);
	new_zoom = action - 0xC0u;
	zoom = (uint8_t)(new_zoom >> 8);
	action_halfword = ((uint32_t)zoom << 8) | (new_zoom & 0xFFu);
	OBJECT(OBJECT_ADDRESS(14))->action = (uint8_t)(action_halfword >> 8u);
	OBJECT(OBJECT_ADDRESS(14))->action_step = (uint8_t)action_halfword;
	OBJECT(OBJECT_ADDRESS(14))->zoom_x = zoom;
	OBJECT(OBJECT_ADDRESS(14))->zoom_y = zoom;
	attract_reset_layers();
	layer_a_scroll_x = 0x170u;
	layer_b_scroll_x = 0x150u;
	u = attract_draw_layers();
	layer_b_scroll_y = 0x20u;
	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(u, request);
	step_timer = (step_timer & 0xFFu) | 0x9000u;
	step_phase++;
}

/* The layers scroll up and down apart, the picture shrinks away */
void attract_opening_end_scroll(void)
{
	uint32_t carry = 0;
	uint8_t zoom = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, object = 0;
	uint8_t wait_left = 0;
	uint16_t action = 0, new_zoom = 0, layer_a_y_low = 0, old_layer_a_y_low = 0, layer_b_y_low = 0, old_layer_b_y_low = 0, new_layer_b_y_low = 0;
	uint32_t action_halfword = 0;

	object = OBJECT_ADDRESS(14);
	if (OBJECT(OBJECT_ADDRESS(14))->flags != 0u)
	{
		OBJECT(object)->flags = 0x90u;
		action = (((uint32_t)OBJECT(object)->action << 8u) | OBJECT(object)->action_step);
		new_zoom = action - 0xC0u;
		zoom = (uint8_t)(new_zoom >> 8);
		action_halfword = ((uint32_t)zoom << 8) | (new_zoom & 0xFFu);
		OBJECT(object)->action = (uint8_t)(action_halfword >> 8u);
		OBJECT(object)->action_step = (uint8_t)action_halfword;
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		if (zoom <= 0x10u)
			vector_clear_objects(&ignored16, &ignored16_2);
	}
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		step_timer = (step_timer & 0xFFu) | 0x100u;
		step_phase++;
		return;
	}
	layer_a_y_low = AT16(layer_a_scroll_y, -1);
	old_layer_a_y_low = layer_a_y_low;
	carry = (uint16_t)(old_layer_a_y_low + 0x18u) < old_layer_a_y_low;
	AT16(layer_a_scroll_y, -1) = old_layer_a_y_low + 0x18u;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | (((uint8_t)(layer_a_scroll_y >> 8u) + carry & 0xFFu) << 8u);
	layer_b_y_low = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
	old_layer_b_y_low = layer_b_y_low;
	new_layer_b_y_low = old_layer_b_y_low - 0x30u;
	carry = old_layer_b_y_low < 0x30u;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((new_layer_b_y_low >> 8u) & 0xFFu);
	layer_b_scroll_y_fraction = (uint8_t)new_layer_b_y_low;
	layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | (((uint8_t)(layer_b_scroll_y >> 8u) - carry & 0xFFu) << 8u);
}

/* Clears the layers and goes on to Bart's part */
void attract_opening_end_wait(void)
{
	uint8_t wait_left = 0;

	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	vector_clear_layer_b();
	game_step++;
	step_phase = 0u;
}

/* Bart's part of the attract, by its substep */
void attract_bart(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_bart_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_bart_scene_start();
			return;
		case 2:
			attract_bart_scene_move();
			return;
		case 4:
			attract_bart_scene_wait();
			return;
		case 6:
			attract_bart_profile_start();
			return;
		case 8:
			attract_bart_profile_type();
			return;
		case 10:
			attract_bart_profile_end(u);
			return;
		case 12:
			attract_homer_scene_start();
			return;
		case 14:
			attract_homer_scene_wait();
			return;
		case 16:
			attract_homer_scene_end();
			return;
		case 18:
			attract_homer_profile_start();
			return;
		case 20:
			attract_homer_profile_type();
			return;
		case 22:
			attract_homer_profile_end();
			return;
		case 24:
			attract_lisa_scene_start();
			return;
		case 26:
			attract_lisa_scene_walk();
			return;
		case 28:
			attract_lisa_scene_play();
			return;
		case 30:
			attract_lisa_profile_start();
			return;
		case 32:
			attract_lisa_profile_type();
			return;
		case 34:
			attract_lisa_profile_end(u);
			return;
		case 36:
			attract_marge_scene_start();
			return;
		case 38:
			attract_marge_scene_wait();
			return;
		case 40:
			attract_marge_scene_pose();
			return;
		case 42:
			attract_marge_scene_end();
			return;
		case 44:
			attract_marge_profile_start(u);
			return;
		case 46:
			attract_marge_profile_type();
			return;
		case 48:
			attract_marge_profile_end();
			return;
		case 50:
			attract_leap_start();
			return;
		case 52:
			attract_leap_rise();
			return;
		case 54:
			attract_leap_fall();
			return;
		case 56:
			attract_leap_land();
			return;
		case 58:
			attract_leap_end();
			return;
		case 60:
			attract_last_screen_start(u);
			return;
		case 62:
			attract_last_screen_wait(u);
			return;
		case 64:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 66:
		case 72:
			attract_profile_move_stop(object);
			return;
		case 68:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 70:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 74:
			break;
		case -26:
			attract_opening(u);
			return;
		case -24:
			attract_opening_end(u);
			return;
		case -22:
			continue;
		case -20:
			attract_homer(u);
			return;
		case -18:
			attract_lisa(u);
			return;
		case -16:
			attract_marge(u);
			return;
		case -14:
			attract_leap(u);
			return;
		case -12:
			attract_last_screen(u);
			return;
		case -10:
			attract_opening_start(u);
			return;
		case -8:
			attract_opening_zoom();
			return;
		case -6:
			attract_opening_end_start();
			return;
		case -4:
			attract_opening_end_scroll();
			return;
		case -2:
			attract_opening_end_wait();
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Starts Bart's scene: its layer and its object moving */
void attract_bart_scene_start(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, picture = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0x4D0u;
	layer_a_offset_x = 0xFFF0u;
	layer_columns_on = 1u;
	layer_a_edges_on = 1u;
	draw_all_layer_edges = 1u;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x2Au;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	object = OBJECT_ADDRESS(14);
	picture = attract_bart_scene_picture_ADDRESS;
	OBJECT(OBJECT_ADDRESS(14))->x_speed = -0x100;
	OBJECT(OBJECT_ADDRESS(14))->z_speed = 0x200;
	attract_put_picture(&object, &picture);
	step_timer = (step_timer & 0xFFu) | 0x6000u;
	step_phase++;
}

/* Its object rises and falls while the layer races by, then speeds off */
void attract_bart_scene_move(void)
{
	uint32_t carry = 0;
	uint16_t object = 0, scroll_x_low = 0;
	uint8_t wait_left = 0;
	uint16_t z_speed = 0;

	object = OBJECT_ADDRESS(14);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		OBJECT(object)->x_speed = -0x700;
		step_timer = (step_timer & 0xFFu) | 0x100u;
		step_phase++;
		return;
	}
	z_speed = OBJECT(object)->z_speed;
	OBJECT(object)->z_speed = z_speed - 0xCu;
	scroll_x_low = AT16(layer_a_scroll_x, -1);
	carry = scroll_x_low < 0x600u;
	AT16(layer_a_scroll_x, -1) = scroll_x_low - 0x600u;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(layer_a_scroll_x >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
}

/* Waits a frame, then Bart's profile */
void attract_bart_scene_wait(void)
{
	uint8_t wait_left = 0;

	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
		step_phase++;
}

/* Starts Bart's profile: its layer and his two pictures */
void attract_bart_profile_start(void)
{
	uint16_t object = 0, picture = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0x5F0u;
	attract_draw_layer_a();
	object = OBJECT_ADDRESS(14);
	picture = attract_bart_profile_pictures_ADDRESS;
	attract_profile_place(object, picture);
	step_timer = (step_timer & 0xFFu) | 0xE000u;
	profile_typed = 0u;
	profile_alias_typed = 0u;
	step_phase++;
}

/* Types Bart's profile texts while his picture moves */
void attract_bart_profile_type(void)
{
	uint16_t move_number = 0, object = 0, text_number = 0;
	uint8_t wait_left = 0;

	text_number = 0u;
	attract_type_profile_text(text_number);
	text_number = 0x100u;
	attract_type_profile_text(text_number);
	object = OBJECT_ADDRESS(14);
	move_number = 0u;
	attract_profile_move(object, move_number);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
		step_phase++;
}

/* Ends Bart's profile: palette, objects and texts cleared */
void attract_bart_profile_end(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, request = 0;

	palette_request_kind = 1u;
	request = 0x203u;
	vector_palette_request(palette_job, request);
	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_text_layer(&ignored16, &ignored16_3);
	game_step++;
	step_phase = 0u;
}

/* Homer's part of the attract, by its substep */
void attract_homer(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_homer_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_homer_scene_start();
			return;
		case 2:
			attract_homer_scene_wait();
			return;
		case 4:
			attract_homer_scene_end();
			return;
		case 6:
			attract_homer_profile_start();
			return;
		case 8:
			attract_homer_profile_type();
			return;
		case 10:
			attract_homer_profile_end();
			return;
		case 12:
			attract_lisa_scene_start();
			return;
		case 14:
			attract_lisa_scene_walk();
			return;
		case 16:
			attract_lisa_scene_play();
			return;
		case 18:
			attract_lisa_profile_start();
			return;
		case 20:
			attract_lisa_profile_type();
			return;
		case 22:
			attract_lisa_profile_end(u);
			return;
		case 24:
			attract_marge_scene_start();
			return;
		case 26:
			attract_marge_scene_wait();
			return;
		case 28:
			attract_marge_scene_pose();
			return;
		case 30:
			attract_marge_scene_end();
			return;
		case 32:
			attract_marge_profile_start(u);
			return;
		case 34:
			attract_marge_profile_type();
			return;
		case 36:
			attract_marge_profile_end();
			return;
		case 38:
			attract_leap_start();
			return;
		case 40:
			attract_leap_rise();
			return;
		case 42:
			attract_leap_fall();
			return;
		case 44:
			attract_leap_land();
			return;
		case 46:
			attract_leap_end();
			return;
		case 48:
			attract_last_screen_start(u);
			return;
		case 50:
			attract_last_screen_wait(u);
			return;
		case 52:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 54:
		case 60:
			attract_profile_move_stop(object);
			return;
		case 56:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 58:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 62:
			break;
		case -38:
			attract_opening(u);
			return;
		case -36:
			attract_opening_end(u);
			return;
		case -34:
			attract_bart(u);
			return;
		case -32:
			continue;
		case -30:
			attract_lisa(u);
			return;
		case -28:
			attract_marge(u);
			return;
		case -26:
			attract_leap(u);
			return;
		case -24:
			attract_last_screen(u);
			return;
		case -22:
			attract_opening_start(u);
			return;
		case -20:
			attract_opening_zoom();
			return;
		case -18:
			attract_opening_end_start();
			return;
		case -16:
			attract_opening_end_scroll();
			return;
		case -14:
			attract_opening_end_wait();
			return;
		case -12:
			attract_bart_scene_start();
			return;
		case -10:
			attract_bart_scene_move();
			return;
		case -8:
			attract_bart_scene_wait();
			return;
		case -6:
			attract_bart_profile_start();
			return;
		case -4:
			attract_bart_profile_type();
			return;
		case -2:
			attract_bart_profile_end(u);
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Starts Homer's scene: its layers and its object */
void attract_homer_scene_start(void)
{
	uint16_t object = 0, picture = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0x280u;
	map_area = 1u;
	attract_draw_layer_a();
	map_area = 0u;
	attract_draw_layer_b();
	map_area = 1u;
	object = OBJECT_ADDRESS(14);
	picture = attract_homer_scene_picture_ADDRESS;
	OBJECT(OBJECT_ADDRESS(14))->attributes = 0x20u;
	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	attract_put_picture(&object, &picture);
	step_timer = (step_timer & 0xFFu) | 0x4000u;
	step_phase++;
}

/* Holds the scene for its frames */
void attract_homer_scene_wait(void)
{
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(14))->animation_flags = 0x40u;
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		step_timer = (step_timer & 0xFFu) | 0x8000u;
		step_phase++;
	}
}

/* Clears the scene's objects and layer */
void attract_homer_scene_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_left = 0;

	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_layer_b();
	step_phase++;
}

/* Starts Homer's profile: its layer and his two pictures */
void attract_homer_profile_start(void)
{
	uint16_t object = 0, picture = 0;

	layer_a_scroll_x = 0x110u;
	attract_draw_layer_a();
	object = OBJECT_ADDRESS(14);
	picture = attract_homer_profile_pictures_ADDRESS;
	attract_profile_place(object, picture);
	step_timer = (step_timer & 0xFFu) | 0xE000u;
	profile_typed = 0u;
	profile_alias_typed = 0u;
	step_phase++;
}

/* Types Homer's profile texts while his picture moves */
void attract_homer_profile_type(void)
{
	uint16_t move_number = 0, object = 0, text_number = 0;
	uint8_t wait_left = 0;

	text_number = 0x200u;
	attract_type_profile_text(text_number);
	text_number = 0x300u;
	attract_type_profile_text(text_number);
	object = OBJECT_ADDRESS(14);
	move_number = 0x100u;
	attract_profile_move(object, move_number);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
		step_phase++;
}

/* Ends Homer's profile: objects and texts cleared */
void attract_homer_profile_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_text_layer(&ignored16, &ignored16_3);
	game_step++;
	step_phase = 0u;
}

/* Lisa's part of the attract, by its substep */
void attract_lisa(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_lisa_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_lisa_scene_start();
			return;
		case 2:
			attract_lisa_scene_walk();
			return;
		case 4:
			attract_lisa_scene_play();
			return;
		case 6:
			attract_lisa_profile_start();
			return;
		case 8:
			attract_lisa_profile_type();
			return;
		case 10:
			attract_lisa_profile_end(u);
			return;
		case 12:
			attract_marge_scene_start();
			return;
		case 14:
			attract_marge_scene_wait();
			return;
		case 16:
			attract_marge_scene_pose();
			return;
		case 18:
			attract_marge_scene_end();
			return;
		case 20:
			attract_marge_profile_start(u);
			return;
		case 22:
			attract_marge_profile_type();
			return;
		case 24:
			attract_marge_profile_end();
			return;
		case 26:
			attract_leap_start();
			return;
		case 28:
			attract_leap_rise();
			return;
		case 30:
			attract_leap_fall();
			return;
		case 32:
			attract_leap_land();
			return;
		case 34:
			attract_leap_end();
			return;
		case 36:
			attract_last_screen_start(u);
			return;
		case 38:
			attract_last_screen_wait(u);
			return;
		case 40:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 42:
		case 48:
			attract_profile_move_stop(object);
			return;
		case 44:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 46:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 50:
			break;
		case -50:
			attract_opening(u);
			return;
		case -48:
			attract_opening_end(u);
			return;
		case -46:
			attract_bart(u);
			return;
		case -44:
			attract_homer(u);
			return;
		case -42:
			continue;
		case -40:
			attract_marge(u);
			return;
		case -38:
			attract_leap(u);
			return;
		case -36:
			attract_last_screen(u);
			return;
		case -34:
			attract_opening_start(u);
			return;
		case -32:
			attract_opening_zoom();
			return;
		case -30:
			attract_opening_end_start();
			return;
		case -28:
			attract_opening_end_scroll();
			return;
		case -26:
			attract_opening_end_wait();
			return;
		case -24:
			attract_bart_scene_start();
			return;
		case -22:
			attract_bart_scene_move();
			return;
		case -20:
			attract_bart_scene_wait();
			return;
		case -18:
			attract_bart_profile_start();
			return;
		case -16:
			attract_bart_profile_type();
			return;
		case -14:
			attract_bart_profile_end(u);
			return;
		case -12:
			attract_homer_scene_start();
			return;
		case -10:
			attract_homer_scene_wait();
			return;
		case -8:
			attract_homer_scene_end();
			return;
		case -6:
			attract_homer_profile_start();
			return;
		case -4:
			attract_homer_profile_type();
			return;
		case -2:
			attract_homer_profile_end();
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Starts Lisa's scene: its layers and two objects */
void attract_lisa_scene_start(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, picture = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0x240u;
	layer_b_scroll_x = 0x240u;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x40u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_a_scroll_x = 0x2B0u;
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	object = OBJECT_ADDRESS(14);
	picture = attract_lisa_scene_picture_1_ADDRESS;
	attract_put_picture(&object, &picture);
	picture = attract_lisa_scene_picture_2_ADDRESS;
	attract_put_picture(&object, &picture);
	step_timer = (step_timer & 0xFFu) | 0xF000u;
	step_phase++;
}

/* Its two objects walk in while the layer scrolls */
void attract_lisa_scene_walk(void)
{
	uint32_t carry = 0;
	uint16_t object = 0, scroll_x_low = 0;
	uint8_t wait_left = 0;

	object = OBJECT_ADDRESS(14);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object + 0x60u)->x_speed = 0;
		step_timer = (step_timer & 0xFFu) | 0xE000u;
		step_phase++;
		return;
	}
	OBJECT(object)->x_speed = 0x80;
	OBJECT(object + 0x60u)->x_speed = 0x80;
	scroll_x_low = AT16(layer_a_scroll_x, -1);
	carry = scroll_x_low < 0x80u;
	AT16(layer_a_scroll_x, -1) = scroll_x_low - 0x80u;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(layer_a_scroll_x >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
}

/* Its objects change pictures at random for the scene's frames */
void attract_lisa_scene_play(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_left = 0;

	attract_lisa_scene_animate();
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	vector_clear_objects(&ignored16, &ignored16_2);
	step_phase++;
}

/* Starts Lisa's profile: its layer and her two pictures */
void attract_lisa_profile_start(void)
{
	uint16_t object = 0, picture = 0;

	layer_a_scroll_x = 0x3F0u;
	attract_draw_layer_a();
	object = OBJECT_ADDRESS(14);
	picture = attract_lisa_profile_pictures_ADDRESS;
	attract_profile_place(object, picture);
	step_timer = (step_timer & 0xFFu) | 0xC000u;
	profile_typed = 0u;
	profile_alias_typed = 0u;
	step_phase++;
}

/* Types Lisa's profile texts while her picture moves */
void attract_lisa_profile_type(void)
{
	uint16_t move_number = 0, object = 0, text_number = 0;
	uint8_t wait_left = 0;

	text_number = 0x400u;
	attract_type_profile_text(text_number);
	text_number = 0x500u;
	attract_type_profile_text(text_number);
	object = OBJECT_ADDRESS(14);
	move_number = 0x200u;
	attract_profile_move(object, move_number);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
		step_phase++;
}

/* Ends Lisa's profile: palette, objects and texts cleared */
void attract_lisa_profile_end(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, request = 0;

	palette_request_kind = 1u;
	request = 0x204u;
	vector_palette_request(palette_job, request);
	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_text_layer(&ignored16, &ignored16_3);
	game_step++;
	step_phase = 0u;
}

/* Every 16 frames picks the two objects' next pictures at random */
void attract_lisa_scene_animate(void)
{
	uint8_t pose = 0;
	uint16_t object = 0;
	uint8_t stack = 0;
	uint8_t action = 0;
	uint16_t random_product = 0;

	object = OBJECT_ADDRESS(14);
	if ((frame_count & 0xFu) == 0u)
	{
		action = OBJECT(object)->action;
		random_product = action * 0xDu;
		OBJECT(object)->action = random_product + 7u;
		pose = (random_product >> 8) & 1u;
		stack = pose;
		OBJECT(object)->animation = (pose + 0x1Au) | 0x80u;
		OBJECT(object + 0x60u)->animation = (stack + 0x1Cu) | 0x80u;
	}
}

/* Marge and Maggie's part of the attract, by its substep */
void attract_marge(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_marge_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_marge_scene_start();
			return;
		case 2:
			attract_marge_scene_wait();
			return;
		case 4:
			attract_marge_scene_pose();
			return;
		case 6:
			attract_marge_scene_end();
			return;
		case 8:
			attract_marge_profile_start(u);
			return;
		case 10:
			attract_marge_profile_type();
			return;
		case 12:
			attract_marge_profile_end();
			return;
		case 14:
			attract_leap_start();
			return;
		case 16:
			attract_leap_rise();
			return;
		case 18:
			attract_leap_fall();
			return;
		case 20:
			attract_leap_land();
			return;
		case 22:
			attract_leap_end();
			return;
		case 24:
			attract_last_screen_start(u);
			return;
		case 26:
			attract_last_screen_wait(u);
			return;
		case 28:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 30:
		case 36:
			attract_profile_move_stop(object);
			return;
		case 32:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 34:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 38:
			break;
		case -62:
			attract_opening(u);
			return;
		case -60:
			attract_opening_end(u);
			return;
		case -58:
			attract_bart(u);
			return;
		case -56:
			attract_homer(u);
			return;
		case -54:
			attract_lisa(u);
			return;
		case -52:
			continue;
		case -50:
			attract_leap(u);
			return;
		case -48:
			attract_last_screen(u);
			return;
		case -46:
			attract_opening_start(u);
			return;
		case -44:
			attract_opening_zoom();
			return;
		case -42:
			attract_opening_end_start();
			return;
		case -40:
			attract_opening_end_scroll();
			return;
		case -38:
			attract_opening_end_wait();
			return;
		case -36:
			attract_bart_scene_start();
			return;
		case -34:
			attract_bart_scene_move();
			return;
		case -32:
			attract_bart_scene_wait();
			return;
		case -30:
			attract_bart_profile_start();
			return;
		case -28:
			attract_bart_profile_type();
			return;
		case -26:
			attract_bart_profile_end(u);
			return;
		case -24:
			attract_homer_scene_start();
			return;
		case -22:
			attract_homer_scene_wait();
			return;
		case -20:
			attract_homer_scene_end();
			return;
		case -18:
			attract_homer_profile_start();
			return;
		case -16:
			attract_homer_profile_type();
			return;
		case -14:
			attract_homer_profile_end();
			return;
		case -12:
			attract_lisa_scene_start();
			return;
		case -10:
			attract_lisa_scene_walk();
			return;
		case -8:
			attract_lisa_scene_play();
			return;
		case -6:
			attract_lisa_profile_start();
			return;
		case -4:
			attract_lisa_profile_type();
			return;
		case -2:
			attract_lisa_profile_end(u);
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Starts Marge's scene: its layers and objects */
void attract_marge_scene_start(void)
{
	uint16_t moving_picture = 0, object = 0, picture = 0, request = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0x510u;
	layer_b_scroll_x = 0x390u;
	attract_draw_layer_a();
	map_area = 0u;
	attract_draw_layer_b();
	map_area = 1u;
	object = OBJECT_ADDRESS(14);
	picture = attract_marge_scene_picture_1_ADDRESS;
	OBJECT(OBJECT_ADDRESS(14))->attributes = 0x10u;
	attract_put_picture(&object, &picture);
	picture = attract_marge_scene_picture_2_ADDRESS;
	OBJECT(object)->animation_flags = 0x40u;
	OBJECT(object)->attributes = 0x10u;
	attract_put_picture(&object, &picture);
	picture = attract_marge_scene_picture_3_ADDRESS;
	OBJECT(object)->z = 0x80u;
	attract_put_picture(&object, &picture);
	picture = attract_marge_scene_picture_4_ADDRESS;
	OBJECT(object)->z = 0x80u;
	attract_put_picture(&object, &picture);
	object = OBJECT_ADDRESS(18);
	moving_picture = attract_marge_scene_moving_picture_ADDRESS;
	OBJECT(OBJECT_ADDRESS(18))->attributes = 0x30u;
	OBJECT(OBJECT_ADDRESS(18))->x_speed = -0x600;
	OBJECT(OBJECT_ADDRESS(18))->y_speed = 0x1C0;
	attract_put_picture(&object, &moving_picture);
	OBJECT(object - 0x60u)->kind = 0xFu;
	palette_request_kind = 3u;
	request = 0x7A53u;
	vector_palette_request(moving_picture, request);
	step_timer = (step_timer & 0xFFu) | 0x5000u;
	step_phase++;
}

/* Runs the scene for its frames */
void attract_marge_scene_wait(void)
{
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(15))->animation_flags = 0x40u;
	attract_marge_scene_wrap();
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		step_timer = (step_timer & 0xFFu) | 0x1800u;
		step_phase++;
	}
}

/* Puts its first object in its pose, then runs the scene */
void attract_marge_scene_pose(void)
{
	uint8_t wait_left = 0;

	attract_marge_scene_wrap();
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
	{
		attract_marge_scene_animate();
		return;
	}
	OBJECT(OBJECT_ADDRESS(14))->animation = 0xA4u;
	OBJECT(OBJECT_ADDRESS(14))->x = 0x10Fu;
	OBJECT(OBJECT_ADDRESS(14))->y = 0x98u;
	OBJECT(OBJECT_ADDRESS(14))->action = 0u;
	OBJECT(OBJECT_ADDRESS(15))->animation |= 0x80u;
	step_timer = (step_timer & 0xFFu) | 0x5000u;
	step_phase++;
}

/* Ends Marge's scene: layer and objects cleared */
void attract_marge_scene_end(void)
{
	uint16_t ignored16 = 0, object = 0, request = 0, u = 0;
	uint8_t wait_left = 0;

	object = attract_marge_scene_wrap();
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
	{
		attract_marge_scene_animate();
		return;
	}
	OBJECT(object)->action = 0u;
	vector_clear_layer_b();
	vector_clear_objects(&ignored16, &u);
	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(u, request);
	step_phase++;
}

/* Its first object's two pictures in turn, with a sound */
void attract_marge_scene_animate(void)
{
	uint32_t carry = 0;
	uint8_t action = 0;
	uint16_t command = 0, object = 0;

	object = OBJECT_ADDRESS(14);
	OBJECT(OBJECT_ADDRESS(14))->action++;
	action = OBJECT(OBJECT_ADDRESS(14))->action;
	if (action == 0xFu)
	{
		OBJECT(object)->animation = 0x99u;
		OBJECT(object)->x = 0x130u;
		OBJECT(object)->y = 0x96u;
		command = 0x4300u;
		carry = vector_queue_sound(command);
		return;
	}
	if (action == 0x1Eu)
	{
		OBJECT(object)->animation = 0xA4u;
		OBJECT(object)->x = 0x10Fu;
		OBJECT(object)->y = 0x98u;
		return;
	}
}

/* Starts Marge and Maggie's profiles: the layer and their pictures */
void attract_marge_profile_start(uint16_t action_step)
{
	uint16_t object = 0, picture = 0, request = 0;

	palette_request_kind = 2u;
	request = 1u;
	action_step = vector_palette_request(action_step, request);
	OBJECT(OBJECT_ADDRESS(14))->action_step = (uint8_t)(action_step >> 8u);
	OBJECT(OBJECT_ADDRESS(14))->behaviour = (OBJECT(OBJECT_ADDRESS(14))->behaviour & 0xFFu) | ((action_step & 0xFFu) << 8u);
	attract_reset_layers();
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0xFFF0u;
	map_area = 2u;
	attract_draw_layer_a();
	object = OBJECT_ADDRESS(14);
	picture = attract_marge_profile_pictures_ADDRESS;
	object = attract_profile_place(object, picture);
	picture = attract_maggie_profile_pictures_ADDRESS;
	attract_profile_place(object, picture);
	step_timer = (step_timer & 0xFFu) | 0xE000u;
	profile_typed = 0u;
	profile_alias_typed = 0u;
	step_phase++;
}

/* Types Marge's and Maggie's profiles while their pictures move, with a sound */
void attract_marge_profile_type(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, move_number = 0, object = 0, text_number = 0;
	uint8_t wait_left = 0;

	text_number = 0x600u;
	attract_type_profile_text(text_number);
	text_number = 0x700u;
	attract_type_profile_text(text_number);
	if ((frame_count & 0xFu) == 0u)
	{
		command = 0x4500u;
		carry = vector_queue_sound(command);
	}
	object = OBJECT_ADDRESS(14);
	move_number = 0x300u;
	attract_profile_move(object, move_number);
	object = OBJECT_ADDRESS(16);
	move_number = 0x400u;
	attract_profile_move(object, move_number);
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		mem_write8((((uint32_t)OBJECT(OBJECT_ADDRESS(14))->action_step << 8u) | (OBJECT(OBJECT_ADDRESS(14))->behaviour >> 8u)), 0u);
		step_phase++;
	}
}

/* Ends their profiles: objects and texts cleared */
void attract_marge_profile_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	vector_clear_objects(&ignored16, &ignored16_2);
	vector_clear_text_layer(&ignored16, &ignored16_3);
	game_step++;
	step_phase = 0u;
}

/* Brings the moving object back in at the right when it leaves at the left */
uint16_t attract_marge_scene_wrap(void)
{
	uint16_t object = 0;

	object = OBJECT_ADDRESS(18);
	if ((int16_t)OBJECT(OBJECT_ADDRESS(18))->x <= 0)
	{
		OBJECT(object)->x = 0x1A0u;
		OBJECT(object)->y = 0xC0u;
	}
	return object;
}

/* The attract's leap scene, by its substep */
void attract_leap(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_leap_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_leap_start();
			return;
		case 2:
			attract_leap_rise();
			return;
		case 4:
			attract_leap_fall();
			return;
		case 6:
			attract_leap_land();
			return;
		case 8:
			attract_leap_end();
			return;
		case 10:
			attract_last_screen_start(u);
			return;
		case 12:
			attract_last_screen_wait(u);
			return;
		case 14:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 16:
		case 22:
			attract_profile_move_stop(object);
			return;
		case 18:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 20:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 24:
			break;
		case -76:
			attract_opening(u);
			return;
		case -74:
			attract_opening_end(u);
			return;
		case -72:
			attract_bart(u);
			return;
		case -70:
			attract_homer(u);
			return;
		case -68:
			attract_lisa(u);
			return;
		case -66:
			attract_marge(u);
			return;
		case -64:
			continue;
		case -62:
			attract_last_screen(u);
			return;
		case -60:
			attract_opening_start(u);
			return;
		case -58:
			attract_opening_zoom();
			return;
		case -56:
			attract_opening_end_start();
			return;
		case -54:
			attract_opening_end_scroll();
			return;
		case -52:
			attract_opening_end_wait();
			return;
		case -50:
			attract_bart_scene_start();
			return;
		case -48:
			attract_bart_scene_move();
			return;
		case -46:
			attract_bart_scene_wait();
			return;
		case -44:
			attract_bart_profile_start();
			return;
		case -42:
			attract_bart_profile_type();
			return;
		case -40:
			attract_bart_profile_end(u);
			return;
		case -38:
			attract_homer_scene_start();
			return;
		case -36:
			attract_homer_scene_wait();
			return;
		case -34:
			attract_homer_scene_end();
			return;
		case -32:
			attract_homer_profile_start();
			return;
		case -30:
			attract_homer_profile_type();
			return;
		case -28:
			attract_homer_profile_end();
			return;
		case -26:
			attract_lisa_scene_start();
			return;
		case -24:
			attract_lisa_scene_walk();
			return;
		case -22:
			attract_lisa_scene_play();
			return;
		case -20:
			attract_lisa_profile_start();
			return;
		case -18:
			attract_lisa_profile_type();
			return;
		case -16:
			attract_lisa_profile_end(u);
			return;
		case -14:
			attract_marge_scene_start();
			return;
		case -12:
			attract_marge_scene_wait();
			return;
		case -10:
			attract_marge_scene_pose();
			return;
		case -8:
			attract_marge_scene_end();
			return;
		case -6:
			attract_marge_profile_start(u);
			return;
		case -4:
			attract_marge_profile_type();
			return;
		case -2:
			attract_marge_profile_end();
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Starts the scene: its layer, a sound and three objects, one leaping up */
void attract_leap_start(void)
{
	uint32_t carry = 0;
	uint16_t command = 0, object = 0, picture = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0x110u;
	layer_b_scroll_x = 0x110u;
	attract_draw_layer_a();
	command = 0x4400u;
	carry = vector_queue_sound(command);
	object = OBJECT_ADDRESS(14);
	picture = attract_leap_picture_1_ADDRESS;
	OBJECT(OBJECT_ADDRESS(14))->z_speed = 0xC00;
	attract_put_picture(&object, &picture);
	picture = attract_leap_picture_2_ADDRESS;
	OBJECT(object)->animation_flags = 0x40u;
	attract_put_picture(&object, &picture);
	picture = attract_leap_picture_3_ADDRESS;
	attract_put_picture(&object, &picture);
	OBJECT(object - 0x60u)->flags = 0u;
	step_timer = (step_timer & 0xFFu) | 0x1000u;
	step_phase++;
}

/* The leap rises, then stops */
void attract_leap_rise(void)
{
	uint16_t object = 0;
	uint8_t wait_left = 0;

	object = OBJECT_ADDRESS(14);
	OBJECT(OBJECT_ADDRESS(15))->animation_flags = 0x40u;
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		step_timer = (step_timer & 0xFFu) | 0x3000u;
		OBJECT(object)->z_speed = 0;
		step_phase++;
		return;
	}
}

/* After a pause the leaping object comes down at 00D8 */
void attract_leap_fall(void)
{
	uint16_t object = 0;
	uint8_t wait_left = 0;

	object = OBJECT_ADDRESS(14);
	OBJECT(OBJECT_ADDRESS(15))->animation_flags = 0x40u;
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		OBJECT(object)->x = 0xD8u;
		OBJECT(object)->y = 0x100u;
		OBJECT(object)->z_speed = -0xC00;
		step_timer = (step_timer & 0xFFu) | 0xC00u;
		step_phase++;
	}
}

/* The object lands and is removed */
void attract_leap_land(void)
{
	uint16_t object = 0;
	uint8_t wait_left = 0;
	uint16_t partner_y = 0, new_partner_y = 0;

	object = OBJECT_ADDRESS(14);
	OBJECT(OBJECT_ADDRESS(15))->animation_flags = 0x40u;
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left == 1u)
	{
		OBJECT(object)->flags = 0u;
		partner_y = OBJECT(object + 0x60u)->y;
		new_partner_y = partner_y + 4u;
		OBJECT(object + 0x60u)->y = new_partner_y;
		step_timer = (step_timer & 0xFFu) | 0x5000u;
		step_phase++;
	}
}

/* Waits, then clears the objects and goes on */
void attract_leap_end(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t wait_left = 0;

	OBJECT(OBJECT_ADDRESS(16))->flags = 0x80u;
	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	vector_clear_objects(&ignored16, &ignored16_2);
	step_phase = 0u;
	game_step++;
}

/* The attract's last screen of this part, by its substep */
void attract_last_screen(uint16_t u)
{
	uint8_t phase_offset = 0;
	uint16_t move = 0, move_number = 0, object = 0;

	for (;;)
	{
		object = attract_last_screen_phases_ADDRESS;
		phase_offset = (uint32_t)step_phase << 1;
		switch ((int8_t)phase_offset)
		{
		case 0:
			attract_last_screen_start(u);
			return;
		case 2:
			attract_last_screen_wait(u);
			return;
		case 4:
			move = (uint16_t)leftover_y;
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_out(object, move, move_number);
			return;
		case 6:
		case 12:
			attract_profile_move_stop(object);
			return;
		case 8:
			move_number = (uint32_t)phase_offset << 8;
			attract_profile_move_pause(object, move_number);
			return;
		case 10:
			move = (uint16_t)leftover_y;
			attract_profile_move_back(object, move);
			return;
		case 14:
			break;
		case -86:
			attract_opening(u);
			return;
		case -84:
			attract_opening_end(u);
			return;
		case -82:
			attract_bart(u);
			return;
		case -80:
			attract_homer(u);
			return;
		case -78:
			attract_lisa(u);
			return;
		case -76:
			attract_marge(u);
			return;
		case -74:
			attract_leap(u);
			return;
		case -72:
			continue;
		case -70:
			attract_opening_start(u);
			return;
		case -68:
			attract_opening_zoom();
			return;
		case -66:
			attract_opening_end_start();
			return;
		case -64:
			attract_opening_end_scroll();
			return;
		case -62:
			attract_opening_end_wait();
			return;
		case -60:
			attract_bart_scene_start();
			return;
		case -58:
			attract_bart_scene_move();
			return;
		case -56:
			attract_bart_scene_wait();
			return;
		case -54:
			attract_bart_profile_start();
			return;
		case -52:
			attract_bart_profile_type();
			return;
		case -50:
			attract_bart_profile_end(u);
			return;
		case -48:
			attract_homer_scene_start();
			return;
		case -46:
			attract_homer_scene_wait();
			return;
		case -44:
			attract_homer_scene_end();
			return;
		case -42:
			attract_homer_profile_start();
			return;
		case -40:
			attract_homer_profile_type();
			return;
		case -38:
			attract_homer_profile_end();
			return;
		case -36:
			attract_lisa_scene_start();
			return;
		case -34:
			attract_lisa_scene_walk();
			return;
		case -32:
			attract_lisa_scene_play();
			return;
		case -30:
			attract_lisa_profile_start();
			return;
		case -28:
			attract_lisa_profile_type();
			return;
		case -26:
			attract_lisa_profile_end(u);
			return;
		case -24:
			attract_marge_scene_start();
			return;
		case -22:
			attract_marge_scene_wait();
			return;
		case -20:
			attract_marge_scene_pose();
			return;
		case -18:
			attract_marge_scene_end();
			return;
		case -16:
			attract_marge_profile_start(u);
			return;
		case -14:
			attract_marge_profile_type();
			return;
		case -12:
			attract_marge_profile_end();
			return;
		case -10:
			attract_leap_start();
			return;
		case -8:
			attract_leap_rise();
			return;
		case -6:
			attract_leap_fall();
			return;
		case -4:
			attract_leap_land();
			return;
		case -2:
			attract_leap_end();
			return;
		}
		break;
	}
	attract_profile_move_done();
}

/* Draws the two layers of the last screen and its palettes */
void attract_last_screen_start(uint16_t palette_job)
{
	uint16_t request = 0, u = 0;

	attract_reset_layers();
	layer_a_scroll_x = 0xFFF0u;
	layer_b_scroll_x = 0xFFF0u;
	palette_request_kind = 1u;
	request = 0xD01u;
	palette_job = vector_palette_request(palette_job, request);
	palette_request_kind = 1u;
	request = 0x20Cu;
	vector_palette_request(palette_job, request);
	map_scene = 0u;
	map_area = 3u;
	attract_draw_layer_a();
	map_scene = 2u;
	map_area = 0u;
	u = attract_draw_layer_b();
	palette_request_kind = 3u;
	request = 0x7FFFu;
	vector_palette_request(u, request);
	step_timer = (step_timer & 0xFFu) | 0x8000u;
	profile_typed = 0u;
	step_phase++;
}

/* Waits, fades, and hands over to the attract's next part */
void attract_last_screen_wait(uint16_t palette_job)
{
	uint16_t request = 0;
	uint8_t wait_left = 0;

	wait_left = (uint8_t)(step_timer >> 8u);
	step_timer = (step_timer & 0xFFu) | ((wait_left - 1u & 0xFFu) << 8u);
	if (wait_left != 1u)
		return;
	palette_request_kind = 3u;
	request = 0u;
	vector_palette_request(palette_job, request);
	mode_phase++;
}

/* Puts a profile's two pictures in, still */
uint16_t attract_profile_place(uint16_t object, uint16_t picture)
{
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	OBJECT(object)->attract_profile.move_frames = 0x60u;
	attract_put_picture(&object, &picture);
	OBJECT(object)->x_speed = 0;
	OBJECT(object)->y_speed = 0;
	OBJECT(object)->z_speed = 0;
	attract_put_picture(&object, &picture);
	return object;
}

/* Runs move A of the profile picture in X by its step */
void attract_profile_move(uint16_t object, uint16_t move_number)
{
	uint8_t b = 0;
	uint16_t move = 0, move_steps = 0;
	uint8_t move_step = 0;

	move_steps = attract_profile_move_steps_ADDRESS;
	leftover_y = profile_moves[((move_number | b) >> 8) & 0x7Fu];
	move_step = OBJECT(object)->attract_profile.move_step;
	switch ((int8_t)(uint8_t)((uint32_t)move_step << 1))
	{
	case 0:
		move = (uint16_t)leftover_y;
		attract_profile_move_out(object, move, move_number);
		return;
	case 2:
	case 8:
		attract_profile_move_stop(object);
		return;
	case 4:
		attract_profile_move_pause(object, move_number);
		return;
	case 6:
		move = (uint16_t)leftover_y;
		attract_profile_move_back(object, move);
		return;
	case 10:
		attract_profile_move_done();
		return;
	case -90:
		attract_opening(move_steps);
		return;
	case -88:
		attract_opening_end(move_steps);
		return;
	case -86:
		attract_bart(move_steps);
		return;
	case -84:
		attract_homer(move_steps);
		return;
	case -82:
		attract_lisa(move_steps);
		return;
	case -80:
		attract_marge(move_steps);
		return;
	case -78:
		attract_leap(move_steps);
		return;
	case -76:
		attract_last_screen(move_steps);
		return;
	case -74:
		attract_opening_start(move_steps);
		return;
	case -72:
		attract_opening_zoom();
		return;
	case -70:
		attract_opening_end_start();
		return;
	case -68:
		attract_opening_end_scroll();
		return;
	case -66:
		attract_opening_end_wait();
		return;
	case -64:
		attract_bart_scene_start();
		return;
	case -62:
		attract_bart_scene_move();
		return;
	case -60:
		attract_bart_scene_wait();
		return;
	case -58:
		attract_bart_profile_start();
		return;
	case -56:
		attract_bart_profile_type();
		return;
	case -54:
		attract_bart_profile_end(move_steps);
		return;
	case -52:
		attract_homer_scene_start();
		return;
	case -50:
		attract_homer_scene_wait();
		return;
	case -48:
		attract_homer_scene_end();
		return;
	case -46:
		attract_homer_profile_start();
		return;
	case -44:
		attract_homer_profile_type();
		return;
	case -42:
		attract_homer_profile_end();
		return;
	case -40:
		attract_lisa_scene_start();
		return;
	case -38:
		attract_lisa_scene_walk();
		return;
	case -36:
		attract_lisa_scene_play();
		return;
	case -34:
		attract_lisa_profile_start();
		return;
	case -32:
		attract_lisa_profile_type();
		return;
	case -30:
		attract_lisa_profile_end(move_steps);
		return;
	case -28:
		attract_marge_scene_start();
		return;
	case -26:
		attract_marge_scene_wait();
		return;
	case -24:
		attract_marge_scene_pose();
		return;
	case -22:
		attract_marge_scene_end();
		return;
	case -20:
		attract_marge_profile_start(move_steps);
		return;
	case -18:
		attract_marge_profile_type();
		return;
	case -16:
		attract_marge_profile_end();
		return;
	case -14:
		attract_leap_start();
		return;
	case -12:
		attract_leap_rise();
		return;
	case -10:
		attract_leap_fall();
		return;
	case -8:
		attract_leap_land();
		return;
	case -6:
		attract_leap_end();
		return;
	case -4:
		attract_last_screen_start(move_steps);
		return;
	case -2:
		attract_last_screen_wait(move_steps);
		return;
	}
}

/* After its wait, moves the picture and its partner by the move's speeds */
void attract_profile_move_out(uint16_t object, uint16_t move, uint16_t move_number)
{
	uint16_t profile_move = 0, speed_x = 0, speed_y = 0;
	uint8_t stack = 0;
	uint8_t move_frames = 0, move_step = 0;
	uint16_t speed_x_at = 0, speed_y_at = 0;

	move_frames = OBJECT(object)->attract_profile.move_frames;
	OBJECT(object)->attract_profile.move_frames = move_frames - 1u;
	if (move_frames != 1u)
		return;
	stack = move_number >> 8;
	speed_x_at = move;
	speed_x = PROFILE_MOVE(speed_x_at)->speed_x;
	OBJECT(object)->x_speed = speed_x;
	OBJECT(object + 0x60u)->x_speed = speed_x;
	speed_y_at = speed_x_at + 2u;
	profile_move = speed_y_at + 2u;
	speed_y = PROFILE_MOVE(speed_y_at - 0x2u)->speed_y;
	OBJECT(object)->y_speed = speed_y;
	OBJECT(object + 0x60u)->y_speed = speed_y;
	if ((uint16_t)((uint32_t)stack << 8) >> 8 == 4u)
		OBJECT(object + 0x60u)->x_speed = -0x100;
	OBJECT(object)->attract_profile.move_frames = (uint16_t)((uint32_t)PROFILE_MOVE(profile_move - 0x4u)->frames << 8) >> 8;
	move_step = OBJECT(object)->attract_profile.move_step;
	OBJECT(object)->attract_profile.move_step = move_step + 1u;
}

/* Stops the picture after the move's frames */
void attract_profile_move_stop(uint16_t object)
{
	uint8_t move_frames = 0, move_step = 0;

	move_frames = OBJECT(object)->attract_profile.move_frames;
	OBJECT(object)->attract_profile.move_frames = move_frames - 1u;
	if (move_frames == 1u)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object + 0x60u)->x_speed = 0;
		OBJECT(object + 0x60u)->y_speed = 0;
		move_step = OBJECT(object)->attract_profile.move_step;
		OBJECT(object)->attract_profile.move_step = move_step + 1u;
	}
}

/* Move 0 pauses 40 frames and goes on to move back; the others stop here */
void attract_profile_move_pause(uint16_t object, uint16_t move_number)
{
	uint8_t move_step = 0;

	if (move_number >> 8 == 0u)
	{
		OBJECT(object)->attract_profile.move_frames = 0x40u;
		move_step = OBJECT(object)->attract_profile.move_step;
		OBJECT(object)->attract_profile.move_step = move_step + 1u;
	}
}

/* Moves the picture back the way it came */
void attract_profile_move_back(uint16_t object, uint16_t move)
{
	uint16_t frames = 0, x_speed = 0, y_speed = 0;
	uint8_t move_frames = 0, move_step = 0;
	uint16_t speed_x_at = 0, speed_y_at = 0;

	move_frames = OBJECT(object)->attract_profile.move_frames;
	OBJECT(object)->attract_profile.move_frames = move_frames - 1u;
	if (move_frames == 1u)
	{
		speed_x_at = move;
		x_speed = 0u - PROFILE_MOVE(speed_x_at)->speed_x;
		OBJECT(object)->x_speed = x_speed;
		OBJECT(object + 0x60u)->x_speed = x_speed;
		speed_y_at = speed_x_at + 2u;
		y_speed = 0u - PROFILE_MOVE(speed_y_at - 0x2u)->speed_y;
		OBJECT(object)->y_speed = y_speed;
		OBJECT(object + 0x60u)->y_speed = y_speed;
		frames = (uint32_t)PROFILE_MOVE(speed_y_at - 0x2u)->frames << 8;
		OBJECT(object)->attract_profile.move_frames = frames >> 8;
		move_step = OBJECT(object)->attract_profile.move_step;
		OBJECT(object)->attract_profile.move_step = move_step + 1u;
	}
}

/* The move's last step: nothing more */
void attract_profile_move_done(void)
{
}

/* Puts in a kind 0E object from a record (animation, x, y) and moves on to the next slot */
void attract_put_picture(uint16_t *p_object, uint16_t *p_picture)
{
	uint16_t object = (uint16_t)*p_object;
	uint16_t picture = (uint16_t)*p_picture;
	uint16_t animation_at = 0, x_at = 0, picture_x = 0, y_at = 0, picture_y = 0;

	OBJECT(object)->flags = 0x80u;
	OBJECT(object)->kind = 0xEu;
	animation_at = picture;
	OBJECT(object)->animation = ATTRACT_PICTURE(animation_at)->animation | 0x80u;
	x_at = animation_at + 1u;
	picture_x = ATTRACT_PICTURE(x_at - 0x1u)->x;
	OBJECT(object)->x = picture_x;
	y_at = x_at + 2u;
	picture = y_at + 2u;
	picture_y = ATTRACT_PICTURE(y_at - 0x3u)->y;
	OBJECT(object)->y = picture_y;
	object += 0x60u;
	*p_object = object;
	*p_picture = picture;
}

/* Types the next letter of profile text A, its count kept where the text says */
void attract_type_profile_text(uint16_t text_number)
{
	uint8_t letter = 0, letter_index = 0;
	uint16_t place = 0, text = 0;
	uint16_t profile_text = 0, counter_address = 0, letter_at = 0, place_at = 0, letter_after_place_at = 0, counter = 0;

	profile_text = profile_texts[(text_number >> 8) & 0x7Fu];
	text = profile_text + 2u;
	counter_address = mem_read16(profile_text);
	profile_count_address = counter_address;
	letter_index = 0u;
	for (;;)
	{
		profile_letter_place++;
		letter_at = text;
		text = letter_at + 1u;
		letter = mem_read8(letter_at);
		if (letter == 0xFFu)
			return;
		if (letter == 0xFEu)
		{
			place_at = text;
			profile_letter_place = mem_read16(place_at);
			profile_letter_colour = 0u;
			letter_after_place_at = place_at + 2u;
			text = letter_after_place_at + 1u;
			letter = mem_read8(letter_after_place_at);
		}
		if (letter_index == mem_read8(profile_count_address))
			break;
		letter_index++;
	}
	place = profile_letter_place;
	mem_write8(place, letter - 0x30u);
	mem_write8(place - 0x2000u, profile_letter_colour);
	counter = profile_count_address;
	mem_write8(counter, mem_read8(counter) + 1u);
}

/* Draws both layers of the scene */
uint16_t attract_draw_layers(void)
{
	uint16_t u = 0;

	attract_draw_layer_a();
	u = attract_draw_layer_b();
	return u;
}

/* Draws layer A of the scene */
void attract_draw_layer_a(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0;

	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x26u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
}

/* Draws layer B of the scene */
uint16_t attract_draw_layer_b(void)
{
	uint16_t ignored16 = 0, layer_and_columns = 0, u = 0;

	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	return u;
}

/* Zeroes both layers' scrolls and offsets */
void attract_reset_layers(void)
{
	layer_a_scroll_x = 0u;
	layer_b_scroll_x = 0u;
	layer_a_scroll_y = 0u;
	layer_b_scroll_y = 0u;
	layer_a_offset_x = 0u;
	layer_b_offset_x = 0u;
	layer_a_offset_y = 0u;
	layer_b_offset_y = 0u;
	layer_columns_on = 0u;
	layer_a_edges_on = 0u;
	draw_all_layer_edges = 0u;
}
