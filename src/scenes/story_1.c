/**
 *    Name:        scenes/story_1.c
 *    Description: story 1: the opening
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Story 1, the opening: runs its part; carry set when a part has ended and the next one starts. */
void story_1(uint16_t u)
{
	uint16_t scene_steps = 0;
	uint8_t scene_step = 0, part_done = 0, discarded_read = 0, old_scene_state = 0, discarded_read_2 = 0;

	scene_steps = story_1_states_ADDRESS;
	scene_step = io_read8(scene_state);
	switch ((int8_t)(uint8_t)((uint32_t)scene_step << 1))
	{
	case 0:
		story_1_set_up_street(u);
		break;
	case 2:
		story_1_street(u);
		break;
	case 4:
		story_1_redraw(scene_steps);
		break;
	case 6:
		story_1_rise(u);
		break;
	case 8:
		story_1_pan(u);
		break;
	case 10:
		story_1_end(u);
		break;
	case 12:
		story_1_rise_start();
		break;
	case 14:
		story_1_rise_slow_down(u);
		break;
	case 16:
		story_1_rise_coast();
		break;
	case 18:
		story_1_pan_right(scene_steps);
		break;
	case 20:
		story_1_pan_wait(scene_steps);
		break;
	case 22:
		story_1_end_start();
		break;
	case 24:
		story_1_end_sounds();
		break;
	case 26:
	case 30:
	case 34:
	case 38:
		story_1_hide_text();
		break;
	case 28:
	case 32:
	case 36:
	case 40:
		story_1_show_text();
		break;
	case 42:
		story_1_finish(scene_steps);
		break;
	case 44:
		story_1_marge(scene_steps);
		break;
	case 46:
		story_1_homer(scene_steps);
		break;
	case 48:
		story_1_bart(scene_steps);
		break;
	case 50:
		story_1_lisa(scene_steps);
		break;
	case 52:
		story_1_marge_walks_in();
		break;
	case 54:
	case 60:
	case 64:
	case 68:
		story_1_character_done();
		break;
	case 56:
		story_1_homer_walks_in();
		break;
	case 58:
		story_1_homer_stops(scene_steps);
		break;
	case 62:
		story_1_bart_walks_in();
		break;
	case 66:
		story_1_lisa_walks_in();
		break;
	case 70:
		story_1_smithers(scene_steps);
		break;
	case 72:
		story_1_first_goon(scene_steps);
		break;
	case 74:
		story_1_second_goon(scene_steps);
		break;
	case 76:
		story_1_smithers_runs_in();
		break;
	case 78:
		story_1_smithers_collide(scene_steps);
		break;
	case 80:
		story_1_smithers_drop(scene_steps);
		break;
	case 82:
		story_1_smithers_run_off(scene_steps);
		break;
	case 84:
		story_1_smithers_gone();
		break;
	case 86:
		story_1_first_goon_appears();
		break;
	case 88:
	case 96:
		story_1_goon_start_running(scene_steps);
		break;
	case 90:
	case 98:
		story_1_goon_run_off(scene_steps);
		break;
	case 92:
	case 100:
		story_1_goon_gone();
		break;
	case 94:
		story_1_second_goon_appears();
		break;
	case 102:
		story_1_text_appears();
		break;
	case 104:
		story_1_text_sound(scene_steps);
		break;
	case 106:
		story_1_text_goes(scene_steps);
		break;
	case 108:
		story_1_text_gone();
		break;
	case 110:
		story_1_dropped_object_fall(scene_steps);
		break;
	case 112:
		story_1_dropped_object_gone(scene_steps);
		break;
	}
	part_done = io_read8(scene_wait);
	if (part_done == 0u)
		return;
	discarded_read = io_read8(scene_wait);
	io_write8(scene_wait, 0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	discarded_read_2 = io_read8(scene_substate);
	io_write8(scene_substate, 0u);
}

/* Story 1's first part: the stage 1 street (scene 82) drawn, its palettes, sounds 9100 and 4600, and two
   objects (kind 04 animation 08, kind 0F animation 16); B0 frames. */
uint16_t story_1_set_up_street(uint16_t palette_job)
{
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, record = 0, request = 0, scroll_x = 0, scroll_y = 0, street_object = 0;
	uint8_t old_part_done = 0;

	scroll_x = 0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0x10u;
	vector_set_scroll_y(scroll_y);
	palette_request_kind = 1u;
	request = 0xE81u;
	palette_job = vector_palette_request(palette_job, request);
	palette_request_kind = 1u;
	request = 0x805u;
	vector_palette_request(palette_job, request);
	command = 0x9100u;
	vector_queue_sound(command);
	command = 0x4600u;
	vector_queue_sound(command);
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x82u;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x12Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	record = story_1_street_object_start_1_ADDRESS;
	story_put_object(record);
	record = story_1_street_object_start_2_ADDRESS;
	street_object = story_put_object(record);
	io_write8(scene_short_wait, 0xB0u);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return street_object;
}

/* Story 1's street: the family walks in from the right, Smithers runs in, stops, lets something fall and
   runs off to the right with his two goons, and a text shows; after B0 frames (or a button) the story's
   scene 81 is drawn with palette effect 3, sound 3F25, a text (kind 0E animation 25) and a screen shake,
   for 50 frames. */
uint16_t story_1_street(uint16_t palette_job)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t command = 0, effect_job = 0, ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, object = 0, record = 0, request = 0, wait = 0, x = 0;
	uint8_t street_wait = 0, old_part_done = 0;

	wait = 0x4000u | b;
	vector_check_skip(wait, &ignored16, &carry);
	if (carry == 0u)
	{
		street_wait = io_read8(scene_short_wait);
		io_write8(scene_short_wait, street_wait - 1u);
		if (street_wait != 1u)
		{
			story_1_family();
			story_1_runners();
			story_1_text();
			x = story_1_dropped_object();
			return x;
		}
	}
	palette_request_kind = 1u;
	request = 0xF05u;
	vector_palette_request(palette_job, request);
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_a_scroll_x = 0xFFF0u;
	layer_a_scroll_y = 0u;
	map_scene = 0x81u;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &effect_job);
	vector_clear_layer_b();
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	skip_wait = 0u;
	palette_request_kind = 2u;
	request = 3u;
	effect_job = vector_palette_request(effect_job, request);
	io_write16(scene_second_wait, effect_job);
	command = 0x3F25u;
	vector_queue_sound(command);
	vector_clear_objects(&ignored16, &ignored16_2);
	record = story_1_street_text_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->y_speed = 0x180;
	screen_shake_on = 1u;
	screen_shake_kind = 1u;
	io_write8(scene_short_wait, 0x50u);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return object;
}

/* Story 1, after 50 frames (or a button): stops the palette effect, draws both layers at their new
   places and shows the text again. */
uint16_t story_1_redraw(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, record = 0, wait = 0;
	uint8_t street_wait = 0, old_part_done = 0;
	uint16_t effect_job = 0;

	wait = 0x4000u | b;
	vector_check_skip(wait, &x, &carry);
	if (carry == 0u)
	{
		street_wait = io_read8(scene_short_wait);
		io_write8(scene_short_wait, street_wait - 1u);
		if (street_wait != 1u)
			return x;
	}
	effect_job = io_read16(scene_second_wait);
	mem_write8(effect_job, 0u);
	layer_b_scroll_x = 0xFFF0u;
	layer_b_scroll_y = 0u;
	map_area = 0u;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	layer_and_columns = 0x124u;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_b_scroll_x = 0xF0u;
	layer_a_scroll_x = 0x10u;
	layer_a_scroll_y = 0x200u;
	map_area = 1u;
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	vector_clear_objects(&ignored16, &ignored16_2);
	record = story_1_redraw_text_start_ADDRESS;
	x = story_put_object(record);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return x;
}

/* Story 1's rising part: runs its step (18E1); a button skips to the last part. */
uint16_t story_1_rise(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t steps = 0, wait = 0;
	uint8_t old_scene_state = 0, scene_substep = 0;

	for (;;)
	{
		wait = 0x4000u;
		vector_check_skip(wait, &steps, &carry);
		if (carry)
		{
			old_scene_state = io_read8(scene_state);
			io_write8(scene_state, old_scene_state + 1u);
			return story_1_last_view();
		}
		steps = story_1_rise_steps_ADDRESS;
		scene_substep = io_read8(scene_substate);
		switch ((int8_t)(uint8_t)((uint32_t)scene_substep << 1))
		{
		case 0:
			story_1_rise_start();
			return steps;
		case 2:
			story_1_rise_slow_down(u);
			return steps;
		case 4:
			story_1_rise_coast();
			return steps;
		case 6:
			return story_1_pan_right(steps);
		case 8:
			return story_1_pan_wait(steps);
		case 10:
			story_1_end_start();
			return steps;
		case 12:
			story_1_end_sounds();
			return steps;
		case 14:
		case 18:
		case 22:
		case 26:
			story_1_hide_text();
			return steps;
		case 16:
		case 20:
		case 24:
		case 28:
			story_1_show_text();
			return steps;
		case 30:
			return story_1_finish(steps);
		case 32:
			return story_1_marge(steps);
		case 34:
			return story_1_homer(steps);
		case 36:
			return story_1_bart(steps);
		case 38:
			return story_1_lisa(steps);
		case 40:
			return story_1_marge_walks_in();
		case 42:
		case 48:
		case 52:
		case 56:
			story_1_character_done();
			return steps;
		case 44:
			return story_1_homer_walks_in();
		case 46:
			story_1_homer_stops(steps);
			return steps;
		case 50:
			return story_1_bart_walks_in();
		case 54:
			return story_1_lisa_walks_in();
		case 58:
			return story_1_smithers(steps);
		case 60:
			return story_1_first_goon(steps);
		case 62:
			return story_1_second_goon(steps);
		case 64:
			return story_1_smithers_runs_in();
		case 66:
			story_1_smithers_collide(steps);
			return steps;
		case 68:
			story_1_smithers_drop(steps);
			return steps;
		case 70:
			story_1_smithers_run_off(steps);
			return steps;
		case 72:
			story_1_smithers_gone();
			return steps;
		case 74:
			return story_1_first_goon_appears();
		case 76:
		case 84:
			story_1_goon_start_running(steps);
			return steps;
		case 78:
		case 86:
			story_1_goon_run_off(steps);
			return steps;
		case 80:
		case 88:
			story_1_goon_gone();
			return steps;
		case 82:
			return story_1_second_goon_appears();
		case 90:
			return story_1_text_appears();
		case 92:
			story_1_text_sound(steps);
			return steps;
		case 94:
			story_1_text_goes(steps);
			return steps;
		case 96:
			story_1_text_gone();
			return steps;
		case 98:
			story_1_dropped_object_fall(steps);
			return steps;
		case 100:
			break;
		case -12:
			return story_1_set_up_street(u);
		case -10:
			return story_1_street(u);
		case -8:
			return story_1_redraw(steps);
		case -6:
			continue;
		case -4:
			return story_1_pan(u);
		case -2:
			return story_1_end(u);
		}
		break;
	}
	story_1_dropped_object_gone(steps);
	return steps;
}

/* Its step 0: layer A's y offset 0, a scroll speed of FA00, queues sound 0101. */
void story_1_rise_start(void)
{
	uint16_t command = 0;
	uint8_t old_scene_substate = 0;

	layer_a_offset_y = 0u;
	io_write16(scene_layer_a_speed, 0xFA00u);
	layer_a_edges_on = 1u;
	layer_rows_on = 1u;
	draw_all_layer_edges = 1u;
	command = 0x101u;
	vector_queue_sound(command);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
}

/* Its step 1: layer A scrolls with the speed slowing down while the text rises; when the speed has run
   out, palette effect 4 and 98 frames more. */
void story_1_rise_slow_down(uint16_t palette_job)
{
	uint8_t speed_high = 0;
	uint16_t request = 0;
	uint8_t old_scene_substate = 0;
	uint16_t rise_speed = 0, new_rise_speed = 0;

	OBJECT(OBJECT_ADDRESS(14))->z_speed = 0x70;
	rise_speed = io_read16(scene_layer_a_speed);
	new_rise_speed = rise_speed + 0xAu;
	speed_high = (uint8_t)(new_rise_speed >> 8);
	io_write16(scene_layer_a_speed, ((uint32_t)speed_high << 8) | (new_rise_speed & 0xFFu));
	if (speed_high != 0u)
	{
		story_1_scroll_layer_a();
		return;
	}
	palette_request_kind = 2u;
	request = 4u;
	vector_palette_request(palette_job, request);
	io_write8(scene_short_wait, 0x98u);
	layer_a_offset_y = 0xE0u;
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
}

/* Its step 2: for 98 frames layer A scrolls the other way, the text sinking; then the part ends. */
void story_1_rise_coast(void)
{
	uint8_t coast_wait = 0, old_part_done = 0;
	uint16_t rise_speed = 0;

	coast_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, coast_wait - 1u);
	if (coast_wait != 1u)
	{
		rise_speed = io_read16(scene_layer_a_speed);
		io_write16(scene_layer_a_speed, rise_speed + 0xAu);
		OBJECT(OBJECT_ADDRESS(14))->z_speed = -0x60;
		story_1_scroll_layer_a();
		return;
	}
	layer_a_edges_on = 0u;
	layer_rows_on = 0u;
	draw_all_layer_edges = 0u;
	io_write8(scene_short_wait, 0x18u);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
}

/* Moves layer A's y scroll by the story's scroll speed (18E5). */
void story_1_scroll_layer_a(void)
{
	uint32_t carry = 0;
	uint8_t rise_speed_high = 0;
	uint16_t layer_a_y_low = 0, rise_speed = 0, old_layer_a_y_low = 0, new_layer_a_y_low = 0;

	layer_a_y_low = AT16(layer_a_scroll_y, -1);
	rise_speed = io_read16(scene_layer_a_speed);
	old_layer_a_y_low = layer_a_y_low;
	new_layer_a_y_low = old_layer_a_y_low + rise_speed;
	carry = (uint16_t)(old_layer_a_y_low + rise_speed) < old_layer_a_y_low;
	AT16(layer_a_scroll_y, -1) = new_layer_a_y_low;
	rise_speed_high = io_read8(scene_layer_a_speed);
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | ((((uint16_t)(int8_t)rise_speed_high >> 8) + (uint8_t)(layer_a_scroll_y >> 8u) + carry & 0xFFu) << 8u);
}

/* Story 1's panning part: runs its step (18E1). */
uint16_t story_1_pan(uint16_t u)
{
	uint16_t steps = 0;
	uint8_t scene_substep = 0;

	for (;;)
	{
		steps = story_1_pan_steps_ADDRESS;
		scene_substep = io_read8(scene_substate);
		switch ((int8_t)(uint8_t)((uint32_t)scene_substep << 1))
		{
		case 0:
			return story_1_pan_right(steps);
		case 2:
			return story_1_pan_wait(steps);
		case 4:
			story_1_end_start();
			return steps;
		case 6:
			story_1_end_sounds();
			return steps;
		case 8:
		case 12:
		case 16:
		case 20:
			story_1_hide_text();
			return steps;
		case 10:
		case 14:
		case 18:
		case 22:
			story_1_show_text();
			return steps;
		case 24:
			return story_1_finish(steps);
		case 26:
			return story_1_marge(steps);
		case 28:
			return story_1_homer(steps);
		case 30:
			return story_1_bart(steps);
		case 32:
			return story_1_lisa(steps);
		case 34:
			return story_1_marge_walks_in();
		case 36:
		case 42:
		case 46:
		case 50:
			story_1_character_done();
			return steps;
		case 38:
			return story_1_homer_walks_in();
		case 40:
			story_1_homer_stops(steps);
			return steps;
		case 44:
			return story_1_bart_walks_in();
		case 48:
			return story_1_lisa_walks_in();
		case 52:
			return story_1_smithers(steps);
		case 54:
			return story_1_first_goon(steps);
		case 56:
			return story_1_second_goon(steps);
		case 58:
			return story_1_smithers_runs_in();
		case 60:
			story_1_smithers_collide(steps);
			return steps;
		case 62:
			story_1_smithers_drop(steps);
			return steps;
		case 64:
			story_1_smithers_run_off(steps);
			return steps;
		case 66:
			story_1_smithers_gone();
			return steps;
		case 68:
			return story_1_first_goon_appears();
		case 70:
		case 78:
			story_1_goon_start_running(steps);
			return steps;
		case 72:
		case 80:
			story_1_goon_run_off(steps);
			return steps;
		case 74:
		case 82:
			story_1_goon_gone();
			return steps;
		case 76:
			return story_1_second_goon_appears();
		case 84:
			return story_1_text_appears();
		case 86:
			story_1_text_sound(steps);
			return steps;
		case 88:
			story_1_text_goes(steps);
			return steps;
		case 90:
			story_1_text_gone();
			return steps;
		case 92:
			story_1_dropped_object_fall(steps);
			return steps;
		case 94:
			break;
		case -18:
			return story_1_set_up_street(u);
		case -16:
			return story_1_street(u);
		case -14:
			return story_1_redraw(steps);
		case -12:
			return story_1_rise(u);
		case -10:
			continue;
		case -8:
			return story_1_end(u);
		case -6:
			story_1_rise_start();
			return steps;
		case -4:
			story_1_rise_slow_down(u);
			return steps;
		case -2:
			story_1_rise_coast();
			return steps;
		}
		break;
	}
	story_1_dropped_object_gone(steps);
	return steps;
}

/* Its step 0: layer B scrolls 10 pixels a frame; then a text (kind 0E animation 26) with sound 4400, for
   40 frames. */
uint16_t story_1_pan_right(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t command = 0, object = 0, record = 0;
	uint8_t pan_wait = 0, old_scene_substate = 0;
	uint16_t layer_b_x_low = 0, old_layer_b_x_low = 0;

	pan_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, pan_wait - 1u);
	if (pan_wait == 1u)
	{
		record = story_1_pan_text_start_ADDRESS;
		object = story_put_object(record);
		OBJECT(object)->z_speed = 0;
		command = 0x4400u;
		vector_queue_sound(command);
		io_write8(scene_short_wait, 0x40u);
		old_scene_substate = io_read8(scene_substate);
		io_write8(scene_substate, old_scene_substate + 1u);
		return object;
	}
	layer_b_x_low = AT16(layer_b_scroll_x, -1);
	old_layer_b_x_low = layer_b_x_low;
	carry = (uint16_t)(old_layer_b_x_low + 0xA00u) < old_layer_b_x_low;
	AT16(layer_b_scroll_x, -1) = old_layer_b_x_low + 0xA00u;
	layer_b_scroll_x = (layer_b_scroll_x & 0xFFu) | ((0u + (uint8_t)(layer_b_scroll_x >> 8u) + carry & 0xFFu) << 8u);
	return x;
}

/* Its step 1: waits, then redraws for the last part. */
uint16_t story_1_pan_wait(uint16_t x)
{
	uint8_t pan_wait = 0;

	pan_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, pan_wait - 1u);
	if (pan_wait == 1u)
		return story_1_last_view();
	return x;
}

/* Draws both layers at x 0110 and shows the last text (kind 0E animation 27); the part ends. */
uint16_t story_1_last_view(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, record = 0, text_object = 0;
	uint8_t old_part_done = 0;

	layer_a_scroll_x = 0x110u;
	layer_a_scroll_y = 0u;
	layer_b_scroll_x = 0x110u;
	layer_b_scroll_y = 0u;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_area = 0u;
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x12Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	vector_clear_objects(&ignored16, &ignored16_2);
	record = story_1_last_view_text_start_ADDRESS;
	text_object = story_put_object(record);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return text_object;
}

/* Story 1's last part: runs its step (18E1); a button ends the story. */
uint16_t story_1_end(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, steps = 0, wait = 0, x = 0;
	uint8_t scene_substep = 0, old_part_done = 0;

	for (;;)
	{
		wait = 0x4000u;
		vector_check_skip(wait, &steps, &carry);
		if (carry)
			break;
		steps = story_1_end_steps_ADDRESS;
		scene_substep = io_read8(scene_substate);
		switch ((int8_t)(uint8_t)((uint32_t)scene_substep << 1))
		{
		case 0:
			story_1_end_start();
			return steps;
		case 2:
			story_1_end_sounds();
			return steps;
		case 4:
		case 8:
		case 12:
		case 16:
			story_1_hide_text();
			return steps;
		case 6:
		case 10:
		case 14:
		case 18:
			story_1_show_text();
			return steps;
		case 20:
			return story_1_finish(steps);
		case 22:
			return story_1_marge(steps);
		case 24:
			return story_1_homer(steps);
		case 26:
			return story_1_bart(steps);
		case 28:
			return story_1_lisa(steps);
		case 30:
			return story_1_marge_walks_in();
		case 32:
		case 38:
		case 42:
		case 46:
			story_1_character_done();
			return steps;
		case 34:
			return story_1_homer_walks_in();
		case 36:
			story_1_homer_stops(steps);
			return steps;
		case 40:
			return story_1_bart_walks_in();
		case 44:
			return story_1_lisa_walks_in();
		case 48:
			return story_1_smithers(steps);
		case 50:
			return story_1_first_goon(steps);
		case 52:
			return story_1_second_goon(steps);
		case 54:
			return story_1_smithers_runs_in();
		case 56:
			story_1_smithers_collide(steps);
			return steps;
		case 58:
			story_1_smithers_drop(steps);
			return steps;
		case 60:
			story_1_smithers_run_off(steps);
			return steps;
		case 62:
			story_1_smithers_gone();
			return steps;
		case 64:
			return story_1_first_goon_appears();
		case 66:
		case 74:
			story_1_goon_start_running(steps);
			return steps;
		case 68:
		case 76:
			story_1_goon_run_off(steps);
			return steps;
		case 70:
		case 78:
			story_1_goon_gone();
			return steps;
		case 72:
			return story_1_second_goon_appears();
		case 80:
			return story_1_text_appears();
		case 82:
			story_1_text_sound(steps);
			return steps;
		case 84:
			story_1_text_goes(steps);
			return steps;
		case 86:
			story_1_text_gone();
			return steps;
		case 88:
			story_1_dropped_object_fall(steps);
			return steps;
		case 90:
			story_1_dropped_object_gone(steps);
			return steps;
		case -22:
			return story_1_set_up_street(u);
		case -20:
			return story_1_street(u);
		case -18:
			return story_1_redraw(steps);
		case -16:
			return story_1_rise(u);
		case -14:
			return story_1_pan(u);
		case -12:
			continue;
		case -10:
			story_1_rise_start();
			return steps;
		case -8:
			story_1_rise_slow_down(u);
			return steps;
		case -6:
			story_1_rise_coast();
			return steps;
		case -4:
			return story_1_pan_right(steps);
		case -2:
			return story_1_pan_wait(steps);
		}
	}
	scene_running = 0u;
	vector_clear_objects(&x, &ignored16);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return x;
}

/* Its first step: a wait of 20 frames. */
void story_1_end_start(void)
{
	uint8_t old_scene_substate = 0;

	io_write8(scene_short_wait, 0x20u);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
}

/* Its second step: queues sounds 3F09-3F0B and waits 38 frames. */
void story_1_end_sounds(void)
{
	uint16_t command = 0;
	uint8_t old_scene_substate = 0;

	io_write8(scene_short_wait, 0x38u);
	command = 0x3F09u;
	vector_queue_sound(command);
	command = 0x3F0Au;
	vector_queue_sound(command);
	command = 0x3F0Bu;
	vector_queue_sound(command);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
}

/* Hides the text after its wait, for 8 frames. */
void story_1_hide_text(void)
{
	uint8_t caption_wait = 0, old_scene_substate = 0;

	caption_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, caption_wait - 1u);
	if (caption_wait == 1u)
	{
		OBJECT(OBJECT_ADDRESS(14))->flags = 4u;
		io_write8(scene_short_wait, 8u);
		old_scene_substate = io_read8(scene_substate);
		io_write8(scene_substate, old_scene_substate + 1u);
	}
}

/* Shows the text again with sound 4A00 after its wait, for 8 frames (80 the last time): the text blinks
   four times. */
void story_1_show_text(void)
{
	uint8_t next_wait = 0;
	uint16_t command = 0;
	uint8_t caption_wait = 0, substate_now = 0, old_scene_substate = 0;

	caption_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, caption_wait - 1u);
	if (caption_wait != 1u)
		return;
	command = 0x4A00u;
	vector_queue_sound(command);
	OBJECT(OBJECT_ADDRESS(14))->flags = 0x80u;
	next_wait = 8u;
	substate_now = io_read8(scene_substate);
	if (substate_now == 9u)
		next_wait = 0x80u;
	io_write8(scene_short_wait, next_wait);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
}

/* After the last wait the story ends: the objects cleared, direct page 72 cleared. */
uint16_t story_1_finish(uint16_t x)
{
	uint16_t ignored16 = 0;
	uint8_t finish_wait = 0, old_part_done = 0;

	finish_wait = io_read8(scene_short_wait);
	io_write8(scene_short_wait, finish_wait - 1u);
	if (finish_wait != 1u)
		return x;
	scene_running = 0u;
	vector_clear_objects(&x, &ignored16);
	old_part_done = io_read8(scene_wait);
	io_write8(scene_wait, old_part_done + 1u);
	return x;
}

/* Runs the script of each of the four players' objects (their field 01 the step). */
void story_1_family(void)
{
	uint16_t family_scripts = 0, object = 0;
	uint8_t stack = 0;

	object = OBJECT_ADDRESS(0);
	stack = 0u;
	do
	{
		family_scripts = story_1_family_scripts_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)stack << 1))
		{
		case 0:
			object = story_1_marge(object);
			break;
		case 2:
			object = story_1_homer(object);
			break;
		case 4:
			object = story_1_bart(object);
			break;
		case 6:
			object = story_1_lisa(object);
			break;
		case 8:
			object = story_1_marge_walks_in();
			break;
		case 10:
		case 16:
		case 20:
		case 24:
			story_1_character_done();
			break;
		case 12:
			object = story_1_homer_walks_in();
			break;
		case 14:
			story_1_homer_stops(object);
			break;
		case 18:
			object = story_1_bart_walks_in();
			break;
		case 22:
			object = story_1_lisa_walks_in();
			break;
		case 26:
			object = story_1_smithers(object);
			break;
		case 28:
			object = story_1_first_goon(object);
			break;
		case 30:
			object = story_1_second_goon(object);
			break;
		case 32:
			object = story_1_smithers_runs_in();
			break;
		case 34:
			story_1_smithers_collide(object);
			break;
		case 36:
			story_1_smithers_drop(object);
			break;
		case 38:
			story_1_smithers_run_off(object);
			break;
		case 40:
			story_1_smithers_gone();
			break;
		case 42:
			object = story_1_first_goon_appears();
			break;
		case 44:
		case 52:
			story_1_goon_start_running(object);
			break;
		case 46:
		case 54:
			story_1_goon_run_off(object);
			break;
		case 48:
		case 56:
			story_1_goon_gone();
			break;
		case 50:
			object = story_1_second_goon_appears();
			break;
		case 58:
			object = story_1_text_appears();
			break;
		case 60:
			story_1_text_sound(object);
			break;
		case 62:
			story_1_text_goes(object);
			break;
		case 64:
			story_1_text_gone();
			break;
		case 66:
			story_1_dropped_object_fall(object);
			break;
		case 68:
			story_1_dropped_object_gone(object);
			break;
		case -44:
			object = story_1_set_up_street(family_scripts);
			break;
		case -42:
			object = story_1_street(family_scripts);
			break;
		case -40:
			object = story_1_redraw(object);
			break;
		case -38:
			object = story_1_rise(family_scripts);
			break;
		case -36:
			object = story_1_pan(family_scripts);
			break;
		case -34:
			object = story_1_end(family_scripts);
			break;
		case -32:
			story_1_rise_start();
			break;
		case -30:
			story_1_rise_slow_down(family_scripts);
			break;
		case -28:
			story_1_rise_coast();
			break;
		case -26:
			object = story_1_pan_right(object);
			break;
		case -24:
			object = story_1_pan_wait(object);
			break;
		case -22:
			story_1_end_start();
			break;
		case -20:
			story_1_end_sounds();
			break;
		case -18:
		case -14:
		case -10:
		case -6:
			story_1_hide_text();
			break;
		case -16:
		case -12:
		case -8:
		case -4:
			story_1_show_text();
			break;
		case -2:
			object = story_1_finish(object);
			break;
		}
		object += 0xC0u;
		stack = stack + 1u;
	} while (stack != 4u);
}

/* Marge's slot (4A40), shown with kind 11 (the maggie set): runs its step. */
uint16_t story_1_marge(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_marge_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_marge_walks_in();
		case 2:
		case 8:
		case 12:
		case 16:
			story_1_character_done();
			return object;
		case 4:
			return story_1_homer_walks_in();
		case 6:
			story_1_homer_stops(object);
			return object;
		case 10:
			return story_1_bart_walks_in();
		case 14:
			return story_1_lisa_walks_in();
		case 18:
			return story_1_smithers(object);
		case 20:
			return story_1_first_goon(object);
		case 22:
			return story_1_second_goon(object);
		case 24:
			return story_1_smithers_runs_in();
		case 26:
			story_1_smithers_collide(object);
			return object;
		case 28:
			story_1_smithers_drop(object);
			return object;
		case 30:
			story_1_smithers_run_off(object);
			return object;
		case 32:
			story_1_smithers_gone();
			return object;
		case 34:
			return story_1_first_goon_appears();
		case 36:
		case 44:
			story_1_goon_start_running(object);
			return object;
		case 38:
		case 46:
			story_1_goon_run_off(object);
			return object;
		case 40:
		case 48:
			story_1_goon_gone();
			return object;
		case 42:
			return story_1_second_goon_appears();
		case 50:
			return story_1_text_appears();
		case 52:
			story_1_text_sound(object);
			return object;
		case 54:
			story_1_text_goes(object);
			return object;
		case 56:
			story_1_text_gone();
			return object;
		case 58:
			story_1_dropped_object_fall(object);
			return object;
		case 60:
			break;
		case -52:
			return story_1_set_up_street(steps);
		case -50:
			return story_1_street(steps);
		case -48:
			return story_1_redraw(object);
		case -46:
			return story_1_rise(steps);
		case -44:
			return story_1_pan(steps);
		case -42:
			return story_1_end(steps);
		case -40:
			story_1_rise_start();
			return object;
		case -38:
			story_1_rise_slow_down(steps);
			return object;
		case -36:
			story_1_rise_coast();
			return object;
		case -34:
			return story_1_pan_right(object);
		case -32:
			return story_1_pan_wait(object);
		case -30:
			story_1_end_start();
			return object;
		case -28:
			story_1_end_sounds();
			return object;
		case -26:
		case -22:
		case -18:
		case -14:
			story_1_hide_text();
			return object;
		case -24:
		case -20:
		case -16:
		case -12:
			story_1_show_text();
			return object;
		case -10:
			return story_1_finish(object);
		case -8:
			continue;
		case -6:
			return story_1_homer(object);
		case -4:
			return story_1_bart(object);
		case -2:
			return story_1_lisa(object);
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts her in at the right, walking left. */
uint16_t story_1_marge_walks_in(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_marge_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* Homer (4B00): runs his step. */
uint16_t story_1_homer(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_homer_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_homer_walks_in();
		case 2:
			story_1_homer_stops(object);
			return object;
		case -2:
		case 4:
		case 8:
		case 12:
			story_1_character_done();
			return object;
		case 6:
			return story_1_bart_walks_in();
		case 10:
			return story_1_lisa_walks_in();
		case 14:
			return story_1_smithers(object);
		case 16:
			return story_1_first_goon(object);
		case 18:
			return story_1_second_goon(object);
		case 20:
			return story_1_smithers_runs_in();
		case 22:
			story_1_smithers_collide(object);
			return object;
		case 24:
			story_1_smithers_drop(object);
			return object;
		case 26:
			story_1_smithers_run_off(object);
			return object;
		case 28:
			story_1_smithers_gone();
			return object;
		case 30:
			return story_1_first_goon_appears();
		case 32:
		case 40:
			story_1_goon_start_running(object);
			return object;
		case 34:
		case 42:
			story_1_goon_run_off(object);
			return object;
		case 36:
		case 44:
			story_1_goon_gone();
			return object;
		case 38:
			return story_1_second_goon_appears();
		case 46:
			return story_1_text_appears();
		case 48:
			story_1_text_sound(object);
			return object;
		case 50:
			story_1_text_goes(object);
			return object;
		case 52:
			story_1_text_gone();
			return object;
		case 54:
			story_1_dropped_object_fall(object);
			return object;
		case 56:
			break;
		case -56:
			return story_1_set_up_street(steps);
		case -54:
			return story_1_street(steps);
		case -52:
			return story_1_redraw(object);
		case -50:
			return story_1_rise(steps);
		case -48:
			return story_1_pan(steps);
		case -46:
			return story_1_end(steps);
		case -44:
			story_1_rise_start();
			return object;
		case -42:
			story_1_rise_slow_down(steps);
			return object;
		case -40:
			story_1_rise_coast();
			return object;
		case -38:
			return story_1_pan_right(object);
		case -36:
			return story_1_pan_wait(object);
		case -34:
			story_1_end_start();
			return object;
		case -32:
			story_1_end_sounds();
			return object;
		case -30:
		case -26:
		case -22:
		case -18:
			story_1_hide_text();
			return object;
		case -28:
		case -24:
		case -20:
		case -16:
			story_1_show_text();
			return object;
		case -14:
			return story_1_finish(object);
		case -12:
			return story_1_marge(object);
		case -10:
			continue;
		case -8:
			return story_1_bart(object);
		case -6:
			return story_1_lisa(object);
		case -4:
			return story_1_marge_walks_in();
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts him in at the right, walking left for A8 frames. */
uint16_t story_1_homer_walks_in(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_homer_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	OBJECT(object)->action = 0xA8u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* After his walk stops with animation D1. */
void story_1_homer_stops(uint16_t object)
{
	uint8_t action = 0, type = 0;

	action = OBJECT(object)->action;
	OBJECT(object)->action = action - 1u;
	if (action == 1u)
	{
		OBJECT(object)->animation = 0xD1u;
		OBJECT(object)->x_speed = 0;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
	}
}

/* Bart (4BC0): runs his step. */
uint16_t story_1_bart(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_bart_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_bart_walks_in();
		case -8:
		case -2:
		case 2:
		case 6:
			story_1_character_done();
			return object;
		case 4:
			return story_1_lisa_walks_in();
		case 8:
			return story_1_smithers(object);
		case 10:
			return story_1_first_goon(object);
		case 12:
			return story_1_second_goon(object);
		case 14:
			return story_1_smithers_runs_in();
		case 16:
			story_1_smithers_collide(object);
			return object;
		case 18:
			story_1_smithers_drop(object);
			return object;
		case 20:
			story_1_smithers_run_off(object);
			return object;
		case 22:
			story_1_smithers_gone();
			return object;
		case 24:
			return story_1_first_goon_appears();
		case 26:
		case 34:
			story_1_goon_start_running(object);
			return object;
		case 28:
		case 36:
			story_1_goon_run_off(object);
			return object;
		case 30:
		case 38:
			story_1_goon_gone();
			return object;
		case 32:
			return story_1_second_goon_appears();
		case 40:
			return story_1_text_appears();
		case 42:
			story_1_text_sound(object);
			return object;
		case 44:
			story_1_text_goes(object);
			return object;
		case 46:
			story_1_text_gone();
			return object;
		case 48:
			story_1_dropped_object_fall(object);
			return object;
		case 50:
			break;
		case 104:
			story_1_bart_steps_overrun();
			return object;
		case -62:
			return story_1_set_up_street(steps);
		case -60:
			return story_1_street(steps);
		case -58:
			return story_1_redraw(object);
		case -56:
			return story_1_rise(steps);
		case -54:
			return story_1_pan(steps);
		case -52:
			return story_1_end(steps);
		case -50:
			story_1_rise_start();
			return object;
		case -48:
			story_1_rise_slow_down(steps);
			return object;
		case -46:
			story_1_rise_coast();
			return object;
		case -44:
			return story_1_pan_right(object);
		case -42:
			return story_1_pan_wait(object);
		case -40:
			story_1_end_start();
			return object;
		case -38:
			story_1_end_sounds();
			return object;
		case -36:
		case -32:
		case -28:
		case -24:
			story_1_hide_text();
			return object;
		case -34:
		case -30:
		case -26:
		case -22:
			story_1_show_text();
			return object;
		case -20:
			return story_1_finish(object);
		case -18:
			return story_1_marge(object);
		case -16:
			return story_1_homer(object);
		case -14:
			continue;
		case -12:
			return story_1_lisa(object);
		case -10:
			return story_1_marge_walks_in();
		case -6:
			return story_1_homer_walks_in();
		case -4:
			story_1_homer_stops(object);
			return object;
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts him in at the right, walking left. */
uint16_t story_1_bart_walks_in(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_bart_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* Lisa (4C80): runs her step. */
uint16_t story_1_lisa(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_lisa_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_lisa_walks_in();
		case -12:
		case -6:
		case -2:
		case 2:
			story_1_character_done();
			return object;
		case 4:
			return story_1_smithers(object);
		case 6:
			return story_1_first_goon(object);
		case 8:
			return story_1_second_goon(object);
		case 10:
			return story_1_smithers_runs_in();
		case 12:
			story_1_smithers_collide(object);
			return object;
		case 14:
			story_1_smithers_drop(object);
			return object;
		case 16:
			story_1_smithers_run_off(object);
			return object;
		case 18:
			story_1_smithers_gone();
			return object;
		case 20:
			return story_1_first_goon_appears();
		case 22:
		case 30:
			story_1_goon_start_running(object);
			return object;
		case 24:
		case 32:
			story_1_goon_run_off(object);
			return object;
		case 26:
		case 34:
			story_1_goon_gone();
			return object;
		case 28:
			return story_1_second_goon_appears();
		case 36:
			return story_1_text_appears();
		case 38:
			story_1_text_sound(object);
			return object;
		case 40:
			story_1_text_goes(object);
			return object;
		case 42:
			story_1_text_gone();
			return object;
		case 44:
			story_1_dropped_object_fall(object);
			return object;
		case 46:
			break;
		case -66:
			return story_1_set_up_street(steps);
		case -64:
			return story_1_street(steps);
		case -62:
			return story_1_redraw(object);
		case -60:
			return story_1_rise(steps);
		case -58:
			return story_1_pan(steps);
		case -56:
			return story_1_end(steps);
		case -54:
			story_1_rise_start();
			return object;
		case -52:
			story_1_rise_slow_down(steps);
			return object;
		case -50:
			story_1_rise_coast();
			return object;
		case -48:
			return story_1_pan_right(object);
		case -46:
			return story_1_pan_wait(object);
		case -44:
			story_1_end_start();
			return object;
		case -42:
			story_1_end_sounds();
			return object;
		case -40:
		case -36:
		case -32:
		case -28:
			story_1_hide_text();
			return object;
		case -38:
		case -34:
		case -30:
		case -26:
			story_1_show_text();
			return object;
		case -24:
			return story_1_finish(object);
		case -22:
			return story_1_marge(object);
		case -20:
			return story_1_homer(object);
		case -18:
			return story_1_bart(object);
		case -16:
			continue;
		case -14:
			return story_1_marge_walks_in();
		case -10:
			return story_1_homer_walks_in();
		case -8:
			story_1_homer_stops(object);
			return object;
		case -4:
			return story_1_bart_walks_in();
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts her in at the right, walking left. */
uint16_t story_1_lisa_walks_in(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_lisa_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->attributes = 0x40u;
	OBJECT(object)->x_speed = -0x100;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* A story character's script has ended: nothing more. */
void story_1_character_done(void)
{
}

/* Runs Smithers' and his two goons' scripts (4FE0, 5040, 50A0), each facing the way it moves. */
void story_1_runners(void)
{
	uint8_t attributes = 0;
	uint16_t object = 0, runner_scripts = 0;
	uint8_t stack = 0;
	uint8_t attributes_2 = 0, x_speed = 0;

	object = OBJECT_ADDRESS(15);
	stack = 0u;
	do
	{
		runner_scripts = story_1_runner_scripts_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)stack << 1))
		{
		case 0:
			object = story_1_smithers(object);
			break;
		case 2:
			object = story_1_first_goon(object);
			break;
		case 4:
			object = story_1_second_goon(object);
			break;
		case 6:
			object = story_1_smithers_runs_in();
			break;
		case 8:
			story_1_smithers_collide(object);
			break;
		case 10:
			story_1_smithers_drop(object);
			break;
		case 12:
			story_1_smithers_run_off(object);
			break;
		case 14:
			story_1_smithers_gone();
			break;
		case 16:
			object = story_1_first_goon_appears();
			break;
		case 18:
		case 26:
			story_1_goon_start_running(object);
			break;
		case 20:
		case 28:
			story_1_goon_run_off(object);
			break;
		case 22:
		case 30:
			story_1_goon_gone();
			break;
		case 24:
			object = story_1_second_goon_appears();
			break;
		case 32:
			object = story_1_text_appears();
			break;
		case 34:
			story_1_text_sound(object);
			break;
		case 36:
			story_1_text_goes(object);
			break;
		case 38:
			story_1_text_gone();
			break;
		case 40:
			story_1_dropped_object_fall(object);
			break;
		case 42:
			story_1_dropped_object_gone(object);
			break;
		case -70:
			object = story_1_set_up_street(runner_scripts);
			break;
		case -68:
			object = story_1_street(runner_scripts);
			break;
		case -66:
			object = story_1_redraw(object);
			break;
		case -64:
			object = story_1_rise(runner_scripts);
			break;
		case -62:
			object = story_1_pan(runner_scripts);
			break;
		case -60:
			object = story_1_end(runner_scripts);
			break;
		case -58:
			story_1_rise_start();
			break;
		case -56:
			story_1_rise_slow_down(runner_scripts);
			break;
		case -54:
			story_1_rise_coast();
			break;
		case -52:
			object = story_1_pan_right(object);
			break;
		case -50:
			object = story_1_pan_wait(object);
			break;
		case -48:
			story_1_end_start();
			break;
		case -46:
			story_1_end_sounds();
			break;
		case -44:
		case -40:
		case -36:
		case -32:
			story_1_hide_text();
			break;
		case -42:
		case -38:
		case -34:
		case -30:
			story_1_show_text();
			break;
		case -28:
			object = story_1_finish(object);
			break;
		case -26:
			object = story_1_marge(object);
			break;
		case -24:
			object = story_1_homer(object);
			break;
		case -22:
			object = story_1_bart(object);
			break;
		case -20:
			object = story_1_lisa(object);
			break;
		case -18:
			object = story_1_marge_walks_in();
			break;
		case -16:
		case -10:
		case -6:
		case -2:
			story_1_character_done();
			break;
		case -14:
			object = story_1_homer_walks_in();
			break;
		case -12:
			story_1_homer_stops(object);
			break;
		case -8:
			object = story_1_bart_walks_in();
			break;
		case -4:
			object = story_1_lisa_walks_in();
			break;
		}
		attributes_2 = OBJECT(object)->attributes;
		attributes = attributes_2 & 0xBFu;
		x_speed = (uint8_t)(OBJECT(object)->x_speed >> 8u);
		if ((int8_t)x_speed < 0)
			attributes |= 0x40u;
		OBJECT(object)->attributes = attributes;
		object += 0x60u;
		stack = stack + 1u;
	} while (stack != 3u);
}

/* Smithers (kind 9C): runs his step. */
uint16_t story_1_smithers(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_smithers_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_smithers_runs_in();
		case 2:
			story_1_smithers_collide(object);
			return object;
		case 4:
			story_1_smithers_drop(object);
			return object;
		case 6:
			story_1_smithers_run_off(object);
			return object;
		case 8:
			story_1_smithers_gone();
			return object;
		case 10:
			return story_1_first_goon_appears();
		case 12:
		case 20:
			story_1_goon_start_running(object);
			return object;
		case 14:
		case 22:
			story_1_goon_run_off(object);
			return object;
		case 16:
		case 24:
			story_1_goon_gone();
			return object;
		case 18:
			return story_1_second_goon_appears();
		case 26:
			return story_1_text_appears();
		case 28:
			story_1_text_sound(object);
			return object;
		case 30:
			story_1_text_goes(object);
			return object;
		case 32:
			story_1_text_gone();
			return object;
		case 34:
			story_1_dropped_object_fall(object);
			return object;
		case 36:
			break;
		case -76:
			return story_1_set_up_street(steps);
		case -74:
			return story_1_street(steps);
		case -72:
			return story_1_redraw(object);
		case -70:
			return story_1_rise(steps);
		case -68:
			return story_1_pan(steps);
		case -66:
			return story_1_end(steps);
		case -64:
			story_1_rise_start();
			return object;
		case -62:
			story_1_rise_slow_down(steps);
			return object;
		case -60:
			story_1_rise_coast();
			return object;
		case -58:
			return story_1_pan_right(object);
		case -56:
			return story_1_pan_wait(object);
		case -54:
			story_1_end_start();
			return object;
		case -52:
			story_1_end_sounds();
			return object;
		case -50:
		case -46:
		case -42:
		case -38:
			story_1_hide_text();
			return object;
		case -48:
		case -44:
		case -40:
		case -36:
			story_1_show_text();
			return object;
		case -34:
			return story_1_finish(object);
		case -32:
			return story_1_marge(object);
		case -30:
			return story_1_homer(object);
		case -28:
			return story_1_bart(object);
		case -26:
			return story_1_lisa(object);
		case -24:
			return story_1_marge_walks_in();
		case -22:
		case -16:
		case -12:
		case -8:
			story_1_character_done();
			return object;
		case -20:
			return story_1_homer_walks_in();
		case -18:
			story_1_homer_stops(object);
			return object;
		case -14:
			return story_1_bart_walks_in();
		case -10:
			return story_1_lisa_walks_in();
		case -6:
			continue;
		case -4:
			return story_1_first_goon(object);
		case -2:
			return story_1_second_goon(object);
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts him in running left fast. */
uint16_t story_1_smithers_runs_in(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_smithers_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->x_speed = -0x200;
	OBJECT(object)->action_step = 0xA0u;
	OBJECT(object)->attributes = 0x60u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* At x A0 stops with animation 8D, a little further back. */
void story_1_smithers_collide(uint16_t object)
{
	uint8_t type = 0;
	uint16_t smithers_x = 0, smithers_y = 0;

	smithers_x = OBJECT(object)->x;
	if ((int16_t)smithers_x <= 0xA0)
	{
		OBJECT(object)->animation = 0x8Du;
		OBJECT(object)->attributes = 0x88u;
		OBJECT(object)->x_speed = 0;
		smithers_y = OBJECT(object)->y;
		OBJECT(object)->y = smithers_y - 8u;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
	}
}

/* At the animation's end lets go of an object (kind 9C animation 09) and shows animation 80. */
void story_1_smithers_drop(uint16_t object)
{
	uint16_t record = 0;
	uint16_t stack = 0;
	uint8_t animation_flags = 0, type = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) == 0u)
		return;
	OBJECT(object)->attributes = 0u;
	record = story_1_smithers_drop_start_ADDRESS;
	stack = object;
	story_put_object(record);
	object = stack;
	OBJECT(object)->animation = 0x80u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
}

/* Runs off along a curve (his direction, field 29, turning by 2 a frame), then straight right. */
void story_1_smithers_run_off(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t heading = 0;
	uint8_t action_step_2 = 0, old_heading = 0, type = 0;

	action_step_2 = OBJECT(object)->action_step;
	old_heading = action_step_2;
	action_step = old_heading + 2u;
	OBJECT(object)->action_step = action_step;
	if ((uint8_t)(old_heading + 2u) < old_heading)
	{
		OBJECT(object)->x_speed = 0x200;
		OBJECT(object)->y_speed = 0;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
		return;
	}
	heading = ((uint32_t)action_step << 8) | 0x40u;
	vector_set_speed_by_direction(object, heading);
}

/* Smithers' script has ended: nothing more. */
void story_1_smithers_gone(void)
{
}

/* The first of Smithers' goons (5040): runs its step. */
uint16_t story_1_first_goon(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_first_goon_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_first_goon_appears();
		case 2:
		case 10:
			story_1_goon_start_running(object);
			return object;
		case 4:
		case 12:
			story_1_goon_run_off(object);
			return object;
		case 6:
		case 14:
			story_1_goon_gone();
			return object;
		case 8:
			return story_1_second_goon_appears();
		case 16:
			return story_1_text_appears();
		case 18:
			story_1_text_sound(object);
			return object;
		case 20:
			story_1_text_goes(object);
			return object;
		case 22:
			story_1_text_gone();
			return object;
		case 24:
			story_1_dropped_object_fall(object);
			return object;
		case 26:
			break;
		case -86:
			return story_1_set_up_street(steps);
		case -84:
			return story_1_street(steps);
		case -82:
			return story_1_redraw(object);
		case -80:
			return story_1_rise(steps);
		case -78:
			return story_1_pan(steps);
		case -76:
			return story_1_end(steps);
		case -74:
			story_1_rise_start();
			return object;
		case -72:
			story_1_rise_slow_down(steps);
			return object;
		case -70:
			story_1_rise_coast();
			return object;
		case -68:
			return story_1_pan_right(object);
		case -66:
			return story_1_pan_wait(object);
		case -64:
			story_1_end_start();
			return object;
		case -62:
			story_1_end_sounds();
			return object;
		case -60:
		case -56:
		case -52:
		case -48:
			story_1_hide_text();
			return object;
		case -58:
		case -54:
		case -50:
		case -46:
			story_1_show_text();
			return object;
		case -44:
			return story_1_finish(object);
		case -42:
			return story_1_marge(object);
		case -40:
			return story_1_homer(object);
		case -38:
			return story_1_bart(object);
		case -36:
			return story_1_lisa(object);
		case -34:
			return story_1_marge_walks_in();
		case -32:
		case -26:
		case -22:
		case -18:
			story_1_character_done();
			return object;
		case -30:
			return story_1_homer_walks_in();
		case -28:
			story_1_homer_stops(object);
			return object;
		case -24:
			return story_1_bart_walks_in();
		case -20:
			return story_1_lisa_walks_in();
		case -16:
			return story_1_smithers(object);
		case -14:
			continue;
		case -12:
			return story_1_second_goon(object);
		case -10:
			return story_1_smithers_runs_in();
		case -8:
			story_1_smithers_collide(object);
			return object;
		case -6:
			story_1_smithers_drop(object);
			return object;
		case -4:
			story_1_smithers_run_off(object);
			return object;
		case -2:
			story_1_smithers_gone();
			return object;
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts it in standing, to wait 60 frames and set off to the direction A0. */
uint16_t story_1_first_goon_appears(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_first_goon_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->action = 0x60u;
	OBJECT(object)->action_step = 0xA0u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* The second of Smithers' goons (50A0): runs its step. */
uint16_t story_1_second_goon(uint16_t object)
{
	uint16_t steps = 0;
	uint8_t type = 0;

	for (;;)
	{
		steps = story_1_second_goon_steps_ADDRESS;
		type = OBJECT(object)->type;
		switch ((int8_t)(uint8_t)((uint32_t)type << 1))
		{
		case 0:
			return story_1_second_goon_appears();
		case -6:
		case 2:
			story_1_goon_start_running(object);
			return object;
		case -4:
		case 4:
			story_1_goon_run_off(object);
			return object;
		case -2:
		case 6:
			story_1_goon_gone();
			return object;
		case 8:
			return story_1_text_appears();
		case 10:
			story_1_text_sound(object);
			return object;
		case 12:
			story_1_text_goes(object);
			return object;
		case 14:
			story_1_text_gone();
			return object;
		case 16:
			story_1_dropped_object_fall(object);
			return object;
		case 18:
			break;
		case -94:
			return story_1_set_up_street(steps);
		case -92:
			return story_1_street(steps);
		case -90:
			return story_1_redraw(object);
		case -88:
			return story_1_rise(steps);
		case -86:
			return story_1_pan(steps);
		case -84:
			return story_1_end(steps);
		case -82:
			story_1_rise_start();
			return object;
		case -80:
			story_1_rise_slow_down(steps);
			return object;
		case -78:
			story_1_rise_coast();
			return object;
		case -76:
			return story_1_pan_right(object);
		case -74:
			return story_1_pan_wait(object);
		case -72:
			story_1_end_start();
			return object;
		case -70:
			story_1_end_sounds();
			return object;
		case -68:
		case -64:
		case -60:
		case -56:
			story_1_hide_text();
			return object;
		case -66:
		case -62:
		case -58:
		case -54:
			story_1_show_text();
			return object;
		case -52:
			return story_1_finish(object);
		case -50:
			return story_1_marge(object);
		case -48:
			return story_1_homer(object);
		case -46:
			return story_1_bart(object);
		case -44:
			return story_1_lisa(object);
		case -42:
			return story_1_marge_walks_in();
		case -40:
		case -34:
		case -30:
		case -26:
			story_1_character_done();
			return object;
		case -38:
			return story_1_homer_walks_in();
		case -36:
			story_1_homer_stops(object);
			return object;
		case -32:
			return story_1_bart_walks_in();
		case -28:
			return story_1_lisa_walks_in();
		case -24:
			return story_1_smithers(object);
		case -22:
			return story_1_first_goon(object);
		case -20:
			continue;
		case -18:
			return story_1_smithers_runs_in();
		case -16:
			story_1_smithers_collide(object);
			return object;
		case -14:
			story_1_smithers_drop(object);
			return object;
		case -12:
			story_1_smithers_run_off(object);
			return object;
		case -10:
			story_1_smithers_gone();
			return object;
		case -8:
			return story_1_first_goon_appears();
		}
		break;
	}
	story_1_dropped_object_gone(object);
	return object;
}

/* Puts it in standing, to wait 60 frames and set off to the direction 80. */
uint16_t story_1_second_goon_appears(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_second_goon_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->action = 0x60u;
	OBJECT(object)->action_step = 0x80u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* After its wait starts running (animation 90). */
void story_1_goon_start_running(uint16_t object)
{
	uint8_t action = 0, type = 0;

	action = OBJECT(object)->action;
	OBJECT(object)->action = action - 1u;
	if (action == 1u)
	{
		OBJECT(object)->animation = 0x90u;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
	}
}

/* Runs off along a curve (its direction turning by 2 a frame), then straight right. */
void story_1_goon_run_off(uint16_t object)
{
	uint8_t action_step = 0;
	uint16_t heading = 0;
	uint8_t action_step_2 = 0, old_heading = 0, type = 0;

	action_step_2 = OBJECT(object)->action_step;
	old_heading = action_step_2;
	action_step = old_heading + 2u;
	OBJECT(object)->action_step = action_step;
	if ((uint8_t)(old_heading + 2u) < old_heading)
	{
		OBJECT(object)->x_speed = 0x200;
		OBJECT(object)->y_speed = 0;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
		return;
	}
	heading = ((uint32_t)action_step << 8) | 0x20u;
	vector_set_speed_by_direction(object, heading);
}

/* A goon's script has ended: nothing more. */
void story_1_goon_gone(void)
{
}

/* The story's text (4F80): runs its step. */
void story_1_text(void)
{
	uint16_t text_object = 0, text_steps = 0;

	text_steps = story_1_text_steps_ADDRESS;
	text_object = OBJECT_ADDRESS(14);
	switch ((int8_t)(uint8_t)((uint32_t)OBJECT(OBJECT_ADDRESS(14))->type << 1))
	{
	case 0:
		story_1_text_appears();
		return;
	case 2:
		story_1_text_sound(text_object);
		return;
	case 4:
		story_1_text_goes(text_object);
		return;
	case 6:
		story_1_text_gone();
		return;
	case 8:
		story_1_dropped_object_fall(text_object);
		return;
	case 10:
		story_1_dropped_object_gone(text_object);
		return;
	case -102:
		story_1_set_up_street(text_steps);
		return;
	case -100:
		story_1_street(text_steps);
		return;
	case -98:
		story_1_redraw(text_object);
		return;
	case -96:
		story_1_rise(text_steps);
		return;
	case -94:
		story_1_pan(text_steps);
		return;
	case -92:
		story_1_end(text_steps);
		return;
	case -90:
		story_1_rise_start();
		return;
	case -88:
		story_1_rise_slow_down(text_steps);
		return;
	case -86:
		story_1_rise_coast();
		return;
	case -84:
		story_1_pan_right(text_object);
		return;
	case -82:
		story_1_pan_wait(text_object);
		return;
	case -80:
		story_1_end_start();
		return;
	case -78:
		story_1_end_sounds();
		return;
	case -76:
	case -72:
	case -68:
	case -64:
		story_1_hide_text();
		return;
	case -74:
	case -70:
	case -66:
	case -62:
		story_1_show_text();
		return;
	case -60:
		story_1_finish(text_object);
		return;
	case -58:
		story_1_marge(text_object);
		return;
	case -56:
		story_1_homer(text_object);
		return;
	case -54:
		story_1_bart(text_object);
		return;
	case -52:
		story_1_lisa(text_object);
		return;
	case -50:
		story_1_marge_walks_in();
		return;
	case -48:
	case -42:
	case -38:
	case -34:
		story_1_character_done();
		return;
	case -46:
		story_1_homer_walks_in();
		return;
	case -44:
		story_1_homer_stops(text_object);
		return;
	case -40:
		story_1_bart_walks_in();
		return;
	case -36:
		story_1_lisa_walks_in();
		return;
	case -32:
		story_1_smithers(text_object);
		return;
	case -30:
		story_1_first_goon(text_object);
		return;
	case -28:
		story_1_second_goon(text_object);
		return;
	case -26:
		story_1_smithers_runs_in();
		return;
	case -24:
		story_1_smithers_collide(text_object);
		return;
	case -22:
		story_1_smithers_drop(text_object);
		return;
	case -20:
		story_1_smithers_run_off(text_object);
		return;
	case -18:
		story_1_smithers_gone();
		return;
	case -16:
		story_1_first_goon_appears();
		return;
	case -14:
	case -6:
		story_1_goon_start_running(text_object);
		return;
	case -12:
	case -4:
		story_1_goon_run_off(text_object);
		return;
	case -10:
	case -2:
		story_1_goon_gone();
		return;
	case -8:
		story_1_second_goon_appears();
		return;
	}
}

/* Puts in a text (kind 0E animation 28) for 20 frames. */
uint16_t story_1_text_appears(void)
{
	uint16_t object = 0, record = 0;
	uint8_t type = 0;

	record = story_1_text_start_ADDRESS;
	object = story_put_object(record);
	OBJECT(object)->action = 0x20u;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
	return object;
}

/* Sets its field 06 bit 6; after 20 frames queues sound 5900. */
void story_1_text_sound(uint16_t object)
{
	uint16_t command = 0;
	uint8_t animation_flags = 0, action = 0, type = 0;

	animation_flags = OBJECT(object)->animation_flags;
	OBJECT(object)->animation_flags = animation_flags | 0x40u;
	action = OBJECT(object)->action;
	OBJECT(object)->action = action - 1u;
	if (action != 1u)
		return;
	command = 0x5900u;
	vector_queue_sound(command);
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
}

/* The text is gone at its animation's end. */
void story_1_text_goes(uint16_t object)
{
	uint8_t animation_flags = 0, type = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		OBJECT(object)->flags = 0u;
		type = OBJECT(object)->type;
		OBJECT(object)->type = type + 1u;
	}
}

/* The text's script has ended: nothing more. */
void story_1_text_gone(void)
{
}

/* What Smithers lets go of (4D40), while it is there: runs its step. */
uint16_t story_1_dropped_object(void)
{
	uint16_t object = 0, steps = 0;
	uint8_t type = 0;

	object = OBJECT_ADDRESS(8);
	if (OBJECT(OBJECT_ADDRESS(8))->flags == 0u)
		return object;
	steps = story_1_dropped_object_steps_ADDRESS;
	type = OBJECT(object)->type;
	switch ((int8_t)(uint8_t)((uint32_t)type << 1))
	{
	case 0:
		story_1_dropped_object_fall(object);
		return object;
	case 2:
		story_1_dropped_object_gone(object);
		return object;
	case -110:
		return story_1_set_up_street(steps);
	case -108:
		return story_1_street(steps);
	case -106:
		return story_1_redraw(object);
	case -104:
		return story_1_rise(steps);
	case -102:
		return story_1_pan(steps);
	case -100:
		return story_1_end(steps);
	case -98:
		story_1_rise_start();
		return object;
	case -96:
		story_1_rise_slow_down(steps);
		return object;
	case -94:
		story_1_rise_coast();
		return object;
	case -92:
		return story_1_pan_right(object);
	case -90:
		return story_1_pan_wait(object);
	case -88:
		story_1_end_start();
		return object;
	case -86:
		story_1_end_sounds();
		return object;
	case -84:
	case -80:
	case -76:
	case -72:
		story_1_hide_text();
		return object;
	case -82:
	case -78:
	case -74:
	case -70:
		story_1_show_text();
		return object;
	case -68:
		return story_1_finish(object);
	case -66:
		return story_1_marge(object);
	case -64:
		return story_1_homer(object);
	case -62:
		return story_1_bart(object);
	case -60:
		return story_1_lisa(object);
	case -58:
		return story_1_marge_walks_in();
	case -56:
	case -50:
	case -46:
	case -42:
		story_1_character_done();
		return object;
	case -54:
		return story_1_homer_walks_in();
	case -52:
		story_1_homer_stops(object);
		return object;
	case -48:
		return story_1_bart_walks_in();
	case -44:
		return story_1_lisa_walks_in();
	case -40:
		return story_1_smithers(object);
	case -38:
		return story_1_first_goon(object);
	case -36:
		return story_1_second_goon(object);
	case -34:
		return story_1_smithers_runs_in();
	case -32:
		story_1_smithers_collide(object);
		return object;
	case -30:
		story_1_smithers_drop(object);
		return object;
	case -28:
		story_1_smithers_run_off(object);
		return object;
	case -26:
		story_1_smithers_gone();
		return object;
	case -24:
		return story_1_first_goon_appears();
	case -22:
	case -14:
		story_1_goon_start_running(object);
		return object;
	case -20:
	case -12:
		story_1_goon_run_off(object);
		return object;
	case -18:
	case -10:
		story_1_goon_gone();
		return object;
	case -16:
		return story_1_second_goon_appears();
	case -8:
		return story_1_text_appears();
	case -6:
		story_1_text_sound(object);
		return object;
	case -4:
		story_1_text_goes(object);
		return object;
	case -2:
		story_1_text_gone();
		return object;
	}
	unreachable();
}

/* Falls with gravity; landing, crashes (animation 8A, sound 6F00). */
void story_1_dropped_object_fall(uint16_t object)
{
	uint32_t carry = 0;
	uint16_t command = 0, ignored16 = 0;
	uint8_t type = 0;

	vector_apply_gravity(object, &ignored16, &carry);
	if (carry == 0u)
		return;
	command = 0x6F00u;
	vector_queue_sound(command);
	OBJECT(object)->animation = 0x8Au;
	type = OBJECT(object)->type;
	OBJECT(object)->type = type + 1u;
}

/* Gone at its animation's end. */
void story_1_dropped_object_gone(uint16_t object)
{
	uint8_t animation_flags = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
		OBJECT(object)->flags = 0u;
}

/* Puts in an object from a story record at U: its address, kind, animation, x, y and z; leaves it in X. */
uint16_t story_put_object(uint16_t record)
{
	uint16_t object = 0;
	uint16_t object_at = 0, kind_at = 0, animation_at = 0, x_at = 0, placed_x = 0, y_at = 0, placed_y = 0, placed_z = 0;

	object_at = record;
	object = STORY_OBJECT_START(object_at)->object;
	OBJECT(object)->animation_flags = 0x80u;
	OBJECT(object)->flags = 0x80u;
	kind_at = object_at + 2u;
	OBJECT(object)->kind = STORY_OBJECT_START(kind_at - 0x2u)->kind;
	animation_at = kind_at + 1u;
	OBJECT(object)->animation = STORY_OBJECT_START(animation_at - 0x3u)->animation | 0x80u;
	x_at = animation_at + 1u;
	placed_x = STORY_OBJECT_START(x_at - 0x4u)->x;
	OBJECT(object)->x = placed_x;
	y_at = x_at + 2u;
	placed_y = STORY_OBJECT_START(y_at - 0x6u)->y;
	OBJECT(object)->y = placed_y;
	placed_z = STORY_OBJECT_START(y_at - 0x6u)->z;
	OBJECT(object)->z = placed_z;
	return object;
}
