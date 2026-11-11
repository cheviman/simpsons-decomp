/**
 *    Name:        stages/scroll.c
 *    Description: the camera, the stages' scrolling and the screen shake
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Each frame of a step: clears the camera's move, runs the screen shake and the step's scrolling (the
   camera for stages 1-4 and 8, the special scrolls of the cemetery and stages 5-7, story 1's). */
uint16_t stage_scroll(uint16_t u)
{
	camera_x_speed = 0;
	camera_y_speed = 0;
	u = screen_shake(u);
	switch ((int8_t)(uint8_t)((uint32_t)game_step << 1))
	{
	case 0:
	case 6:
	case 10:
	case 20:
	case 24:
	case 28:
	case 32:
		stage_scroll_none();
		return u;
	case 2:
		story_1_scroll();
		return u;
	case 4:
	case 8:
	case 12:
	case 16:
	case 30:
		return stage_follow_camera();
	case 14:
		return cemetery_scroll_update(u);
	case 18:
		return stage_5_scroll();
	case 22:
		return dreamland_scroll();
	case 26:
		return stage_7_scroll();
	case 34:
		cemetery_scroll_start();
		return u;
	case 36:
		cemetery_scroll_speed_up();
		return u;
	case 38:
		cemetery_scroll_cruise();
		return u;
	case 40:
		cemetery_scroll_slow_down();
		return u;
	case 42:
		return cemetery_put_in_boss(u);
	case 44:
		return cemetery_follow_camera();
	case 46:
	case 48:
	case 50:
	case 52:
	case 54:
	case 56:
	case 58:
	case 60:
		return stage_5_next_part(u);
	case 62:
		stage_5_scroll_end();
		return u;
	}
	unreachable();
}

/* Stages 1, 2, 3's forest, 4 and 8: the camera follows the stage's record. */
uint16_t stage_follow_camera(void)
{
	uint16_t u = 0;

	u = camera_update();
	return u;
}

/* Stage 3's cemetery (step 7): runs its scroll's step (stage_scroll_step). */
uint16_t cemetery_scroll_update(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)stage_scroll_step << 1))
		{
		case 0:
			cemetery_scroll_start();
			return u;
		case 2:
			cemetery_scroll_speed_up();
			return u;
		case 4:
			cemetery_scroll_cruise();
			return u;
		case 6:
			cemetery_scroll_slow_down();
			return u;
		case 8:
			return cemetery_put_in_boss(u);
		case 10:
			return cemetery_follow_camera();
		case 12:
		case 14:
		case 16:
		case 18:
		case 20:
		case 22:
		case 24:
		case 26:
			return stage_5_next_part(u);
		case 28:
			break;
		case -34:
		case -28:
		case -24:
		case -14:
		case -10:
		case -6:
		case -2:
			stage_scroll_none();
			return u;
		case -32:
			story_1_scroll();
			return u;
		case -30:
		case -26:
		case -22:
		case -18:
		case -4:
			return stage_follow_camera();
		case -20:
			continue;
		case -16:
			return stage_5_scroll();
		case -12:
			return dreamland_scroll();
		case -8:
			return stage_7_scroll();
		}
		break;
	}
	stage_5_scroll_end();
	return u;
}

/* The cemetery's step 0: makes layer B the camera's main layer, queues sound 5A00 and the next part's
   music, and goes on. */
void cemetery_scroll_start(void)
{
	uint16_t command = 0;

	layer_a_edges_on = 1u;
	layer_rows_on = 1u;
	camera_main_layer = 1u;
	command = 0x5A00u;
	vector_queue_sound(command);
	stage_part++;
	vector_play_scene_music();
	stage_scroll_step++;
}

/* The cemetery's step 1: scrolls up, the speed growing every other frame up to 0090. */
void cemetery_scroll_speed_up(void)
{
	uint16_t speed = 0;

	if ((((uint16_t)((uint32_t)(uint8_t)frame_count << 8) >> 8) & 1u) != 0u)
	{
		cemetery_scroll_up();
		return;
	}
	speed = cemetery_scroll_speed + 1u;
	if ((int16_t)speed >= 0x90)
	{
		cemetery_scroll_speed = 0x90u;
		stage_scroll_step++;
		cemetery_scroll_up();
		return;
	}
	cemetery_scroll_speed = speed;
	cemetery_scroll_up();
}

/* The cemetery's step 2: scrolls up until past 04E0. */
void cemetery_scroll_cruise(void)
{
	cemetery_scroll_up();
	if ((int16_t)cemetery_scroll > 0x4E0)
		stage_scroll_step++;
}

/* The cemetery's step 3: slows down; at 0500 stops there, lays 6 rows of 9 cells of floor in the floor
   map and queues sound 5B00. */
void cemetery_scroll_slow_down(void)
{
	uint8_t tile_code = 0;
	uint16_t command = 0, tile = 0;
	uint16_t stack = 0;
	uint8_t cells_left = 0, rows_left = 0;
	uint16_t floor_place = 0;

	cemetery_scroll_speed--;
	cemetery_scroll_up();
	if ((int16_t)cemetery_scroll < 0x500)
		return;
	cemetery_scroll_speed = 0u;
	layer_a_scroll_y = 0x500u;
	cemetery_scroll = 0x500u;
	tile = 0x4460u;
	cemetery_floor_rows_left = 6u;
	do
	{
		cemetery_floor_cells_left = 9u;
		tile_code = 0x10u;
		stack = tile;
		do
		{
			floor_place = tile;
			tile = floor_place + 1u;
			mem_write8(floor_place, tile_code);
			cells_left = cemetery_floor_cells_left;
			cemetery_floor_cells_left = cells_left - 1u;
		} while (cells_left != 1u);
		tile = stack + 0x40u;
		rows_left = cemetery_floor_rows_left;
		cemetery_floor_rows_left = rows_left - 1u;
	} while (rows_left != 1u);
	command = 0x5B00u;
	vector_queue_sound(command);
	stage_scroll_step++;
}

/* The cemetery's step 4: once 2 enemies or fewer are left, puts in stage 3's boss (list 0 type 3E) and
   its door (list 1 type ED). */
uint16_t cemetery_put_in_boss(uint16_t object)
{
	uint32_t carry = 0;
	uint8_t list_number = 0;
	uint16_t new_object = 0;
	uint8_t enemies_in_play = 0;

	enemies_in_play = io_read8(enemies_present);
	if (enemies_in_play > 2u)
		return object;
	list_number = 0u;
	vector_find_free_slot(list_number, &new_object, &carry);
	OBJECT(new_object)->type = 0x3E;
	list_number = 1u;
	vector_find_free_slot(list_number, &object, &carry);
	OBJECT(object)->type = -0x13;
	stage_scroll_step++;
	return object;
}

/* The cemetery's step 5: the camera follows the stage's record, with both layers' x offset at 0130 and
   layer A's second y offset at FF00. */
uint16_t cemetery_follow_camera(void)
{
	uint16_t u = 0;

	u = camera_update();
	layer_a_offset_x = 0x130u;
	layer_b_offset_x = 0x130u;
	layer_a_offset_y2 = 0xFF00u;
	return u;
}

/* Moves the cemetery's scroll up by its speed into layer A's y scroll, with layer A's y offset by
   stage_3_part_2_layer_offsets; the players can not push the camera meanwhile. */
void cemetery_scroll_up(void)
{
	uint32_t carry = 0;
	uint8_t scroll_high = 0, scroll_low = 0;
	uint16_t step_word = 0;
	uint16_t offset_record = 0, until = 0, layer_step_word = 0, cemetery_y_low = 0, cemetery_speed = 0, old_cemetery_y_low = 0, new_cemetery_y_low = 0;
	uint32_t cemetery_scroll_halfword = 0;

	offset_record = stage_3_part_2_layer_offsets_ADDRESS + (int8_t)(((uint32_t)cemetery_layer_offset_step << 1) << 1);
	step_word = offset_record + 2u;
	until = LAYER_OFFSET_STEP(offset_record)->until;
	if ((int16_t)until <= (int16_t)layer_a_scroll_y)
	{
		cemetery_layer_offset_step++;
		step_word += 2u;
	}
	layer_step_word = LAYER_STEP_WORD(step_word);
	layer_a_offset_y = layer_step_word;
	cemetery_y_low = (((uint32_t)(cemetery_scroll & 0xFFu) << 8u) | cemetery_scroll_fraction);
	cemetery_speed = cemetery_scroll_speed;
	old_cemetery_y_low = cemetery_y_low;
	new_cemetery_y_low = old_cemetery_y_low + cemetery_speed;
	carry = (uint16_t)(old_cemetery_y_low + cemetery_speed) < old_cemetery_y_low;
	scroll_low = (uint8_t)new_cemetery_y_low;
	scroll_high = (uint8_t)(new_cemetery_y_low >> 8);
	AT16(layer_a_scroll_y, -1) = ((uint32_t)scroll_high << 8) | (scroll_low & 0xFFu);
	cemetery_scroll_halfword = ((uint32_t)scroll_high << 8) | (scroll_low & 0xFFu);
	cemetery_scroll = (cemetery_scroll & 0xFF00u) | ((cemetery_scroll_halfword >> 8u) & 0xFFu);
	cemetery_scroll_fraction = (uint8_t)cemetery_scroll_halfword;
	scroll_high = (uint8_t)(cemetery_scroll >> 8u) + carry;
	cemetery_scroll = (cemetery_scroll & 0xFFu) | ((scroll_high & 0xFFu) << 8u);
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | ((scroll_high & 0xFFu) << 8u);
	players_push_x = 0;
	players_push_y = 0;
}

/* Stage 5 (step 9): the camera follows the stage's record and, by stage_scroll_step, the stage moves on
   to its next part at each of 8 places. */
uint16_t stage_5_scroll(void)
{
	uint8_t step_offset = 0;
	uint16_t part = 0;

	for (;;)
	{
		camera_update();
		step_offset = (uint32_t)stage_scroll_step << 1;
		part = stage_5_scroll_parts_ADDRESS + (int8_t)((uint32_t)step_offset << 1);
		switch ((int8_t)step_offset)
		{
		case 0:
		case 2:
		case 4:
		case 6:
		case 8:
		case 10:
		case 12:
		case 14:
			return stage_5_next_part(part);
		case 16:
			break;
		case -46:
		case -40:
		case -36:
		case -26:
		case -22:
		case -18:
		case -14:
			stage_scroll_none();
			return part;
		case -44:
			story_1_scroll();
			return part;
		case -42:
		case -38:
		case -34:
		case -30:
		case -16:
			return stage_follow_camera();
		case -32:
			return cemetery_scroll_update(part);
		case -28:
			continue;
		case -24:
			return dreamland_scroll();
		case -20:
			return stage_7_scroll();
		case -12:
			cemetery_scroll_start();
			return part;
		case -10:
			cemetery_scroll_speed_up();
			return part;
		case -8:
			cemetery_scroll_cruise();
			return part;
		case -6:
			cemetery_scroll_slow_down();
			return part;
		case -4:
			return cemetery_put_in_boss(part);
		case -2:
			return cemetery_follow_camera();
		}
		break;
	}
	stage_5_scroll_end();
	return part;
}

/* When the camera's x reaches the part's place (0370, 03C5, 041A, 0470, 04B0, 0500, 0550, 05A0), moves
   to the stage's next part and queues its sound command (7F01-7F07, then 7F00). */
uint16_t stage_5_next_part(uint16_t part)
{
	uint16_t command = 0;
	uint16_t part_x_at = 0;

	part_x_at = part;
	part = part_x_at + 2u;
	if ((int16_t)mem_read16(part_x_at) <= (int16_t)camera_x)
	{
		stage_scroll_step++;
		stage_part++;
		command = mem_read16(part);
		vector_queue_sound(command);
	}
	return part;
}

/* Stage 5 past its last part: nothing more. */
void stage_5_scroll_end(void)
{
}

/* Stage 7, step 0: when the camera's x reaches 0610, moves to the stage's next part and its music. */
void stage_7_next_part(void)
{
	if ((int16_t)camera_x >= 0x610)
	{
		stage_scroll_step++;
		stage_part++;
		vector_play_scene_music();
	}
}

/* Stage 7 past its part: nothing more. */
void stage_7_scroll_end(void)
{
}

/* Steps without scrolling (the bonus stages, the stories but the first, the ending). */
void stage_scroll_none(void)
{
}

/* Story 1 (step 1): adds the camera's move to layer A's x and y scroll. */
void story_1_scroll(void)
{
	uint32_t carry = 0;
	uint16_t layer_a_x_low = 0, camera_speed_x = 0, old_layer_a_x_low = 0, new_layer_a_x_low = 0, layer_a_y_low = 0, camera_speed_y = 0, old_layer_a_y_low = 0, new_layer_a_y_low = 0;

	layer_a_x_low = AT16(layer_a_scroll_x, -1);
	camera_speed_x = camera_x_speed;
	old_layer_a_x_low = layer_a_x_low;
	new_layer_a_x_low = old_layer_a_x_low + camera_speed_x;
	carry = (uint16_t)(old_layer_a_x_low + camera_speed_x) < old_layer_a_x_low;
	AT16(layer_a_scroll_x, -1) = new_layer_a_x_low;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(camera_x_speed >> 8u) >> 8) + (uint8_t)(layer_a_scroll_x >> 8u) + carry & 0xFFu) << 8u);
	layer_a_y_low = AT16(layer_a_scroll_y, -1);
	camera_speed_y = camera_y_speed;
	old_layer_a_y_low = layer_a_y_low;
	new_layer_a_y_low = old_layer_a_y_low + camera_speed_y;
	carry = (uint16_t)(old_layer_a_y_low + camera_speed_y) < old_layer_a_y_low;
	AT16(layer_a_scroll_y, -1) = new_layer_a_y_low;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(camera_y_speed >> 8u) >> 8) + (uint8_t)(layer_a_scroll_y >> 8u) + carry & 0xFFu) << 8u);
}

/* Runs the screen shake while one is on (screen_shake_on). */
uint16_t screen_shake(uint16_t u)
{
	switch ((int8_t)(uint8_t)((uint32_t)screen_shake_on << 1))
	{
	case 0:
		screen_shake_none();
		return u;
	case 2:
		return screen_shake_by_kind(u);
	case 4:
	case 6:
	case 8:
		return screen_shake_advance(u);
	case -4:
		stage_7_next_part();
		return u;
	case -2:
		stage_7_scroll_end();
		return u;
	}
	unreachable();
}

/* No screen shake. */
void screen_shake_none(void)
{
}

/* Runs the screen shake of its kind (screen_shake_kind). */
uint16_t screen_shake_by_kind(uint16_t u)
{
	for (;;)
	{
		switch ((int8_t)(uint8_t)((uint32_t)screen_shake_kind << 1))
		{
		case 0:
		case 2:
		case 4:
			break;
		case -8:
			stage_7_next_part();
			return u;
		case -6:
			stage_7_scroll_end();
			return u;
		case -4:
			screen_shake_none();
			return u;
		case -2:
			continue;
		}
		break;
	}
	return screen_shake_advance(u);
}

/* Every other frame moves both layers by the shake's next step (screen_shake_steps) and the sprites the
   other way, until the kind's length (screen_shake_lengths), then ends the shake. */
uint16_t screen_shake_advance(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t sprite_scroll_x_high = 0, sprite_scroll_x_low = 0;
	uint16_t shake = 0;
	uint16_t layer_a_x_low = 0, pixels = 0, old_layer_a_x_low = 0, new_layer_a_x_low = 0, layer_b_x_low = 0, pixels_2 = 0, old_layer_b_x_low = 0, new_layer_b_x_low = 0, back_pixels = 0, new_sprite_scroll_x = 0;

	if (screen_shake_frame != 1u)
	{
		screen_shake_frame++;
		return u;
	}
	screen_shake_frame = 0u;
	shake = screen_shake_steps_ADDRESS + (uint8_t)((screen_shake_step & 7u) << 1);
	layer_a_x_low = AT16(layer_a_scroll_x, -1);
	pixels = (((uint32_t)(uint8_t)SHAKE_STEP(shake)->pixels << 8u) | SHAKE_STEP(shake)->fraction);
	old_layer_a_x_low = layer_a_x_low;
	new_layer_a_x_low = old_layer_a_x_low + pixels;
	carry = (uint16_t)(old_layer_a_x_low + pixels) < old_layer_a_x_low;
	AT16(layer_a_scroll_x, -1) = new_layer_a_x_low;
	layer_a_scroll_x = (layer_a_scroll_x & 0xFFu) | ((((uint16_t)SHAKE_STEP(shake)->pixels >> 8) + (uint8_t)(layer_a_scroll_x >> 8u) + carry & 0xFFu) << 8u);
	layer_b_x_low = AT16(layer_b_scroll_x, -1);
	pixels_2 = (((uint32_t)(uint8_t)SHAKE_STEP(shake)->pixels << 8u) | SHAKE_STEP(shake)->fraction);
	old_layer_b_x_low = layer_b_x_low;
	new_layer_b_x_low = old_layer_b_x_low + pixels_2;
	carry = (uint16_t)(old_layer_b_x_low + pixels_2) < old_layer_b_x_low;
	AT16(layer_b_scroll_x, -1) = new_layer_b_x_low;
	layer_b_scroll_x = (layer_b_scroll_x & 0xFFu) | ((((uint16_t)SHAKE_STEP(shake)->pixels >> 8) + (uint8_t)(layer_b_scroll_x >> 8u) + carry & 0xFFu) << 8u);
	back_pixels = (int8_t)(0u - SHAKE_STEP(shake)->pixels);
	new_sprite_scroll_x = back_pixels + sprite_scroll_x;
	sprite_scroll_x_high = (uint8_t)(new_sprite_scroll_x >> 8);
	sprite_scroll_x_low = (uint8_t)new_sprite_scroll_x;
	sprite_scroll_x = ((uint32_t)sprite_scroll_x_high << 8) | sprite_scroll_x_low;
	io_write16(sprite_chip_scroll_x, ((uint32_t)sprite_scroll_x_high << 8) | sprite_scroll_x_low);
	screen_shake_step++;
	u = screen_shake_lengths_ADDRESS;
	if (screen_shake_step != screen_shake_lengths[(int8_t)screen_shake_kind])
	{
		screen_shake_frame++;
		return u;
	}
	screen_shake_step = 0u;
	screen_shake_on = 0u;
	screen_shake_kind = 0u;
	return u;
}

/* Moves the camera: takes the players' push into the move (unless held), applies the stage record
   entry's x and y limits, moves the camera and the layers, takes the entry's flags (direct page A9, AA,
   9C, 9D, 92), moves to the next entry when a check says so, and caps the x move at 0300. */
uint16_t camera_update(void)
{
	uint32_t carry = 0;
	uint16_t entry = 0, entry_data = 0;
	uint16_t first_data = 0, old_x_speed = 0, pushed_x_speed = 0, old_y_speed = 0, pushed_y_speed = 0, camera_x_low = 0, x_speed_now = 0, old_camera_x_low = 0, new_camera_x_low = 0, camera_y_low = 0, y_speed_now = 0, old_camera_y_low = 0, new_camera_y_low = 0, layer_a_edges_at = 0, layer_b_edges_at = 0, columns_at = 0, rows_at = 0, fast_x_speed = 0;

	if (camera_x_held != 0u)
		players_push_x = 0;
	if (camera_y_held != 0u)
		players_push_y = 0;
	if ((uint16_t)players_push_x != 0u && players_push_x >= 0)
		camera_wait_frames = 0u;
	camera_entry_advance = 0u;
	entry = stage_record_entry;
	first_data = CAMERA_ENTRY(entry)->data;
	entry_data = first_data;
	old_x_speed = camera_x_speed;
	pushed_x_speed = old_x_speed + players_push_x;
	camera_x_speed = pushed_x_speed;
	old_y_speed = camera_y_speed;
	pushed_y_speed = old_y_speed - players_push_y;
	camera_y_speed = pushed_y_speed;
	camera_check_x(&entry, &entry_data);
	entry_data = camera_check_y(entry, entry_data);
	camera_x_low = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	x_speed_now = camera_x_speed;
	old_camera_x_low = camera_x_low;
	new_camera_x_low = old_camera_x_low + x_speed_now;
	carry = (uint16_t)(old_camera_x_low + x_speed_now) < old_camera_x_low;
	camera_x = (camera_x & 0xFF00u) | ((new_camera_x_low >> 8u) & 0xFFu);
	camera_x_fraction = (uint8_t)new_camera_x_low;
	camera_x = (camera_x & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(camera_x_speed >> 8u) >> 8) + (uint8_t)(camera_x >> 8u) + carry & 0xFFu) << 8u);
	camera_y_low = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	y_speed_now = camera_y_speed;
	old_camera_y_low = camera_y_low;
	new_camera_y_low = old_camera_y_low + y_speed_now;
	carry = (uint16_t)(old_camera_y_low + y_speed_now) < old_camera_y_low;
	camera_y = (camera_y & 0xFF00u) | ((new_camera_y_low >> 8u) & 0xFFu);
	camera_y_fraction = (uint8_t)new_camera_y_low;
	camera_y = (camera_y & 0xFFu) | ((((uint16_t)(int8_t)(uint8_t)(camera_y_speed >> 8u) >> 8) + (uint8_t)(camera_y >> 8u) + carry & 0xFFu) << 8u);
	entry_data = camera_scroll_layers(entry_data);
	layer_a_edges_at = entry_data;
	layer_a_edges_on = mem_read8(layer_a_edges_at);
	layer_b_edges_at = layer_a_edges_at + 1u;
	layer_b_edges_on = mem_read8(layer_b_edges_at);
	columns_at = layer_b_edges_at + 1u;
	layer_columns_on = mem_read8(columns_at);
	rows_at = columns_at + 1u;
	entry_data = rows_at + 1u;
	layer_rows_on = mem_read8(rows_at);
	stage_scrolls_on = mem_read8(entry_data);
	if (camera_entry_advance != 0u)
		stage_record_entry += 4u;
	if (draw_all_layer_edges == 0u && layer_columns_on != 0u)
	{
		fast_x_speed = camera_x_speed;
		if ((int16_t)fast_x_speed >= 0x300)
			camera_x_speed = 0x300;
	}
	players_push_x = 0;
	players_push_y = 0;
	return entry_data;
}

/* Runs the entry's x check for the way the camera moves (its first record for right, its second for
   left). */
void camera_check_x(uint16_t *p_entry, uint16_t *p_entry_data)
{
	uint16_t entry = (uint16_t)*p_entry;
	uint16_t entry_data = (uint16_t)*p_entry_data;

	if (camera_x_speed < 0)
	{
		entry_data += 3u;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(entry_data) << 1))
		{
		case 0:
			camera_stop_at_x_left(entry_data);
			break;
		case -8:
		case 2:
			camera_drop_push_x();
			break;
		case 4:
			camera_x_free_left();
			break;
		case -4:
		case 6:
			camera_x_follows_y_down(entry, entry_data);
			break;
		case -2:
		case 8:
			camera_x_follows_y_up(entry, entry_data);
			break;
		case 10:
			camera_y_free_down();
			break;
		case 12:
			camera_stop_at_y(entry_data);
			break;
		case 14:
		case 22:
			camera_drop_push_y();
			break;
		case 16:
		case 24:
			camera_y_free();
			break;
		case 18:
			camera_y_free_up();
			break;
		case 20:
			camera_stop_at_y_up(entry_data);
			break;
		case -10:
			camera_stop_at_x(entry_data);
			break;
		case -6:
			camera_next_entry_at_x(&entry, &entry_data);
			break;
		}
		entry_data += 3u;
	}
	else
	{
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(entry_data) << 1))
		{
		case 0:
			camera_stop_at_x(entry_data);
			break;
		case 2:
		case 12:
			camera_drop_push_x();
			break;
		case 4:
			camera_next_entry_at_x(&entry, &entry_data);
			break;
		case 6:
		case 16:
			camera_x_follows_y_down(entry, entry_data);
			break;
		case 8:
		case 18:
			camera_x_follows_y_up(entry, entry_data);
			break;
		case 10:
			camera_stop_at_x_left(entry_data);
			break;
		case 14:
			camera_x_free_left();
			break;
		case 20:
			camera_y_free_down();
			break;
		case 22:
			camera_stop_at_y(entry_data);
			break;
		case 24:
		case 32:
			camera_drop_push_y();
			break;
		case 26:
		case 34:
			camera_y_free();
			break;
		case 28:
			camera_y_free_up();
			break;
		case 30:
			camera_stop_at_y_up(entry_data);
			break;
		}
		entry_data += 6u;
	}
	*p_entry = entry;
	*p_entry_data = entry_data;
}

/* Moving right: the move is cut so that the camera stops at the check's x. */
void camera_stop_at_x(uint16_t check)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t stop_x_low = 0;
	uint16_t x_speed_now = 0, camera_x_low = 0, x_move = 0, stop_x = 0, stopping_speed = 0;

	x_speed_now = camera_x_speed;
	camera_x_low = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	x_move = x_speed_now;
	carry = (uint16_t)(x_move + camera_x_low) < x_move;
	stack = (uint16_t)(x_move + camera_x_low) >> 8;
	stop_x = CAMERA_CHECK(check)->place;
	if ((int16_t)stop_x <= (int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(camera_x_speed >> 8u) >> 8) + (uint8_t)(camera_x >> 8u) + carry) << 8) | stack))
	{
		stop_x_low = CAMERA_CHECK(check)->place_low;
		stopping_speed = ((uint32_t)stop_x_low << 8) - (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
		camera_x_speed = stopping_speed;
	}
}

/* Moving right: counts the frames the camera waits (unless held) and moves to the record's next entry
   once the camera passes the entry's x. */
void camera_next_entry_at_x(uint16_t *p_entry, uint16_t *p_check)
{
	uint16_t entry = (uint16_t)*p_entry;
	uint16_t check = (uint16_t)*p_check;
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint16_t x_speed_now = 0, camera_x_low = 0, x_move = 0;

	if (camera_x_held == 0u)
		camera_wait_frames++;
	x_speed_now = camera_x_speed;
	camera_x_low = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	x_move = x_speed_now;
	carry = (uint16_t)(x_move + camera_x_low) < x_move;
	stack = (uint16_t)(x_move + camera_x_low) >> 8;
	if (CAMERA_ENTRY(entry)->x <= (uint16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(camera_x_speed >> 8u) >> 8) + (uint8_t)(camera_x >> 8u) + carry) << 8) | stack))
		camera_next_entry(&entry, &check);
	*p_entry = entry;
	*p_check = check;
}

/* The x move follows the y move going down, scaled by the check's ratio (the players' x push dropped). */
void camera_x_follows_y_down(uint16_t entry, uint16_t check)
{
	uint16_t x_move = 0, y_move = 0;
	uint8_t follow_ratio = 0;

	camera_drop_push_x();
	if (camera_y_speed < 0)
	{
		camera_drop_push_y();
		return;
	}
	y_move = camera_y_speed;
	camera_scaled_move = y_move;
	follow_ratio = CAMERA_CHECK(check)->ratio;
	x_move = (y_move & 0xFFu) | ((uint32_t)follow_ratio << 8);
	x_move = camera_scale_move(entry, x_move);
	camera_x_speed = x_move;
}

/* The x move follows the y move going up, scaled by the check's ratio (the players' x push dropped). */
void camera_x_follows_y_up(uint16_t entry, uint16_t check)
{
	uint16_t x_move = 0, y_move = 0;
	uint8_t follow_ratio = 0;

	camera_drop_push_x();
	if (camera_y_speed >= 0)
	{
		camera_drop_push_y();
		return;
	}
	y_move = 0u - camera_y_speed;
	camera_scaled_move = y_move;
	follow_ratio = CAMERA_CHECK(check)->ratio;
	x_move = (y_move & 0xFFu) | ((uint32_t)follow_ratio << 8);
	x_move = camera_scale_move(entry, x_move);
	camera_x_speed = x_move;
}

/* Moving left: no check. */
void camera_x_free_left(void)
{
}

/* Moving left: the move is cut so that the camera stops at the check's x. */
void camera_stop_at_x_left(uint16_t check)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t stop_x_low = 0;
	uint16_t x_speed_now = 0, camera_x_low = 0, x_move = 0, stop_x = 0, stopping_speed = 0;

	x_speed_now = camera_x_speed;
	camera_x_low = (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	x_move = x_speed_now;
	carry = (uint16_t)(x_move + camera_x_low) < x_move;
	stack = (uint16_t)(x_move + camera_x_low) >> 8;
	stop_x = CAMERA_CHECK(check)->place;
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(camera_x_speed >> 8u) >> 8) + (uint8_t)(camera_x >> 8u) + carry) << 8) | stack) <= (int16_t)stop_x)
	{
		stop_x_low = CAMERA_CHECK(check)->place_low;
		stopping_speed = ((uint32_t)stop_x_low << 8) - (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
		camera_x_speed = stopping_speed;
	}
}

/* Takes the players' x push back out of the x move: the camera does not move in x. */
void camera_drop_push_x(void)
{
	camera_x_speed -= players_push_x;
}

/* Runs the entry's y check for the way the camera moves (its first record for down, its second for up). */
uint16_t camera_check_y(uint16_t entry, uint16_t entry_data)
{
	if (camera_y_speed < 0)
	{
		entry_data += 3u;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(entry_data) << 1))
		{
		case 0:
			camera_y_free_up();
			break;
		case 2:
			camera_stop_at_y_up(entry_data);
			break;
		case -4:
		case 4:
			camera_drop_push_y();
			break;
		case -2:
		case 6:
			camera_y_free();
			break;
		case -28:
			camera_stop_at_x(entry_data);
			break;
		case -26:
		case -16:
			camera_drop_push_x();
			break;
		case -24:
			camera_next_entry_at_x(&entry, &entry_data);
			break;
		case -22:
		case -12:
			camera_x_follows_y_down(entry, entry_data);
			break;
		case -20:
		case -10:
			camera_x_follows_y_up(entry, entry_data);
			break;
		case -18:
			camera_stop_at_x_left(entry_data);
			break;
		case -14:
			camera_x_free_left();
			break;
		case -8:
			camera_y_free_down();
			break;
		case -6:
			camera_stop_at_y(entry_data);
			break;
		}
		entry_data += 3u;
		return entry_data;
	}
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(entry_data) << 1))
	{
	case 0:
		camera_y_free_down();
		break;
	case 2:
		camera_stop_at_y(entry_data);
		break;
	case 4:
	case 12:
		camera_drop_push_y();
		break;
	case 6:
	case 14:
		camera_y_free();
		break;
	case 8:
		camera_y_free_up();
		break;
	case 10:
		camera_stop_at_y_up(entry_data);
		break;
	case -20:
		camera_stop_at_x(entry_data);
		break;
	case -18:
	case -8:
		camera_drop_push_x();
		break;
	case -16:
		camera_next_entry_at_x(&entry, &entry_data);
		break;
	case -14:
	case -4:
		camera_x_follows_y_down(entry, entry_data);
		break;
	case -12:
	case -2:
		camera_x_follows_y_up(entry, entry_data);
		break;
	case -10:
		camera_stop_at_x_left(entry_data);
		break;
	case -6:
		camera_x_free_left();
		break;
	}
	entry_data += 6u;
	return entry_data;
}

/* Moving down: no check. */
void camera_y_free_down(void)
{
}

/* Moving up: no check. */
void camera_y_free_up(void)
{
}

/* Moving down: the move is cut so that the camera stops at the check's y. */
void camera_stop_at_y(uint16_t check)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t stop_y_low = 0;
	uint16_t y_speed_now = 0, camera_y_low = 0, y_move = 0, stop_y = 0, stopping_speed = 0;

	y_speed_now = camera_y_speed;
	camera_y_low = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	y_move = y_speed_now;
	carry = (uint16_t)(y_move + camera_y_low) < y_move;
	stack = (uint16_t)(y_move + camera_y_low) >> 8;
	stop_y = CAMERA_CHECK(check)->place;
	if ((int16_t)stop_y <= (int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(camera_y_speed >> 8u) >> 8) + (uint8_t)(camera_y >> 8u) + carry) << 8) | stack))
	{
		stop_y_low = CAMERA_CHECK(check)->place_low;
		stopping_speed = ((uint32_t)stop_y_low << 8) - (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
		camera_y_speed = stopping_speed;
	}
}

/* No y check. */
void camera_y_free(void)
{
}

/* Moving up: the move is cut so that the camera stops at the check's y. */
void camera_stop_at_y_up(uint16_t check)
{
	uint32_t carry = 0;
	uint8_t stack = 0;
	uint8_t stop_y_low = 0;
	uint16_t y_speed_now = 0, camera_y_low = 0, y_move = 0, stop_y = 0, stopping_speed = 0;

	y_speed_now = camera_y_speed;
	camera_y_low = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	y_move = y_speed_now;
	carry = (uint16_t)(y_move + camera_y_low) < y_move;
	stack = (uint16_t)(y_move + camera_y_low) >> 8;
	stop_y = CAMERA_CHECK(check)->place;
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)(uint8_t)(camera_y_speed >> 8u) >> 8) + (uint8_t)(camera_y >> 8u) + carry) << 8) | stack) <= (int16_t)stop_y)
	{
		stop_y_low = CAMERA_CHECK(check)->place_low;
		stopping_speed = ((uint32_t)stop_y_low << 8) - (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
		camera_y_speed = stopping_speed;
	}
}

/* Takes the players' y push back out of the y move: the camera does not move in y. */
void camera_drop_push_y(void)
{
	camera_y_speed += players_push_y;
}

/* Moves the camera's main layer by the camera's move and the other layer by the entry's x and y ratios,
   and sets the layers' offsets to the side the new tiles come in from. */
uint16_t camera_scroll_layers(uint16_t entry_data)
{
	uint16_t layer_y_move = 0, main_layer = 0, ratio = 0, scroll = 0, x_move = 0, y_move = 0;
	uint8_t stack = 0;
	uint16_t main_layer_at = 0, ratio_at = 0;

	main_layer_at = entry_data;
	entry_data = main_layer_at + 1u;
	main_layer = (uint32_t)mem_read8(main_layer_at) << 8;
	camera_main_layer = main_layer >> 8;
	scroll = LAYER_SCROLL(layer_scrolls_ADDRESS + (int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)(main_layer >> 8) << 1) << 8) >> 8) - 0x4u)->x;
	layer_move_x = camera_x_speed;
	layer_move_y = camera_y_speed;
	layer_scroll_move(scroll);
	scroll = LAYER_SCROLL(layer_scrolls_ADDRESS + ((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)camera_main_layer << 8) >> 8) + 1u) << 8) >> 8) & 1u) << 8) >> 8) << 1) << 8) >> 8) - 0x4u)->x;
	x_move = camera_x_speed;
	camera_scaled_move = x_move;
	ratio_at = entry_data;
	entry_data = ratio_at + 1u;
	ratio = (x_move & 0xFFu) | ((uint32_t)mem_read8(ratio_at) << 8);
	stack = ratio >> 8;
	ratio = camera_scale_move(scroll, ratio);
	layer_move_x = ratio;
	y_move = camera_y_speed;
	camera_scaled_move = y_move;
	layer_y_move = (y_move & 0xFFu) | ((uint32_t)stack << 8);
	layer_y_move = camera_scale_move(scroll, layer_y_move);
	layer_move_y = layer_y_move;
	layer_scroll_move(scroll);
	layer_a_offset_x = 0u;
	layer_b_offset_x = 0u;
	if (camera_x_speed >= 0)
	{
		layer_a_offset_x = 0x160u;
		layer_b_offset_x = 0x160u;
	}
	layer_a_offset_y = 0u;
	layer_b_offset_y = 0u;
	if (camera_y_speed >= 0)
	{
		layer_a_offset_y = 0xE0u;
		layer_b_offset_y = 0xE0u;
	}
	return entry_data;
}

/* Adds F2 to the layer's x scroll and F4 to its y scroll, through the addresses of its layer_scroll
   record. */
void layer_scroll_move(uint16_t scroll)
{
	uint32_t carry = 0;
	uint16_t scroll_variable = 0;
	uint16_t move_x = 0, scroll_x_low = 0, added_move_x = 0, new_scroll_x_low = 0, y_variable = 0, move_y = 0, scroll_y_low = 0, added_move_y = 0, new_scroll_y_low = 0;

	scroll_variable = LAYER_SCROLL(scroll)->x;
	move_x = layer_move_x;
	scroll_x_low = io_read16(scroll_variable + 1u);
	added_move_x = move_x;
	new_scroll_x_low = added_move_x + scroll_x_low;
	carry = (uint16_t)(added_move_x + scroll_x_low) < added_move_x;
	io_write16(scroll_variable + 1u, new_scroll_x_low);
	mem_write8(scroll_variable, ((uint16_t)layer_move_x_high >> 8) + mem_read8(scroll_variable) + carry);
	y_variable = LAYER_SCROLL(scroll)->y;
	scroll_variable = y_variable;
	move_y = layer_move_y;
	scroll_y_low = mem_read16(scroll_variable + 1u);
	added_move_y = move_y;
	new_scroll_y_low = added_move_y + scroll_y_low;
	carry = (uint16_t)(added_move_y + scroll_y_low) < added_move_y;
	mem_write16(scroll_variable + 1u, new_scroll_y_low);
	mem_write8(scroll_variable, ((uint16_t)layer_move_y_high >> 8) + mem_read8(scroll_variable) + carry);
}

/* Moves to the stage record's next entry and runs its start (by its first byte). */
void camera_next_entry(uint16_t *p_entry, uint16_t *p_entry_data)
{
	uint16_t entry = (uint16_t)*p_entry;
	uint16_t entry_data = 0;
	uint16_t next_data = 0;

	entry += 4u;
	stage_record_entry = entry;
	next_data = CAMERA_ENTRY(entry)->data;
	entry_data = next_data;
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(entry_data) << 1))
	{
	case 0:
	case 4:
		camera_entry_start_none();
		break;
	case 2:
		camera_move_to_last_entry_x(entry);
		break;
	case 6:
		camera_entry_start_going_up(entry);
		break;
	case 8:
		camera_entry_start_going_down(entry);
		break;
	case 10:
		camera_scale_quarter();
		break;
	case 12:
		camera_scale_half();
		break;
	case 14:
	case 18:
		camera_scale_same();
		break;
	case 16:
		camera_scale_none();
		break;
	case 20:
		camera_scale_double();
		break;
	case 22:
		camera_scale_quadruple();
		break;
	}
	*p_entry = entry;
	*p_entry_data = entry_data;
}

/* An entry with nothing to do at its start. */
void camera_entry_start_none(void)
{
}

/* An entry's start: going up, the y move dropped; keeps the camera's y in direct page 9F and sets the x
   move onto the last entry's x. */
uint16_t camera_entry_start_going_up(uint16_t entry)
{
	if (camera_y_speed < 0)
		camera_drop_push_y();
	entry_start_camera_y = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	return camera_move_to_last_entry_x(entry);
}

/* An entry's start: going down, the y move dropped; keeps the camera's y in direct page 9F and sets the
   x move onto the last entry's x. */
uint16_t camera_entry_start_going_down(uint16_t entry)
{
	if (camera_y_speed >= 0)
		camera_drop_push_y();
	entry_start_camera_y = (((uint32_t)(camera_y & 0xFFu) << 8u) | camera_y_fraction);
	return camera_move_to_last_entry_x(entry);
}

/* Sets the x move so that the camera goes just past the last entry's x. */
uint16_t camera_move_to_last_entry_x(uint16_t entry)
{
	uint8_t move_high = 0, move_low = 0;
	uint16_t x_move = 0;
	uint16_t to_last_x = 0;

	to_last_x = ((uint32_t)(uint8_t)CAMERA_ENTRY(entry - 0x4u)->x << 8) - (((uint32_t)(camera_x & 0xFFu) << 8u) | camera_x_fraction);
	move_low = (uint8_t)to_last_x;
	move_high = (to_last_x >> 8) + 1u;
	camera_x_speed = ((uint32_t)move_high << 8) | move_low;
	x_move = ((uint32_t)move_high << 8) | move_low;
	return x_move;
}

/* Scales the move in F0 by the ratio A: -3 a quarter, -2 a half, -1 and 1 as it is, 0 none, 2 double, 3
   four times. */
uint16_t camera_scale_move(uint16_t entry, uint16_t ratio)
{
	uint8_t ratio_offset = 0;
	uint16_t d = 0;

	ratio_offset = (uint32_t)(ratio >> 8) << 1;
	switch ((int8_t)ratio_offset)
	{
	case 0:
		return camera_scale_none();
	case -2:
	case 2:
		return camera_scale_same();
	case 4:
		return camera_scale_double();
	case 6:
		return camera_scale_quadruple();
	case -16:
	case -12:
		d = (ratio & 0xFFu) | ((uint32_t)ratio_offset << 8);
		camera_entry_start_none();
		return d;
	case -14:
		return camera_move_to_last_entry_x(entry);
	case -10:
		return camera_entry_start_going_up(entry);
	case -8:
		return camera_entry_start_going_down(entry);
	case -6:
		return camera_scale_quarter();
	case -4:
		return camera_scale_half();
	}
	unreachable();
}

/* The move in F0 divided by 4. */
uint16_t camera_scale_quarter(void)
{
	uint32_t carry = 0;
	uint8_t move_high = 0, move_low = 0;
	uint16_t scaled_move = 0;
	uint16_t unscaled_move = 0;

	unscaled_move = camera_scaled_move;
	move_high = (uint8_t)(unscaled_move >> 8);
	carry = move_high & 1u;
	move_high = (int8_t)move_high >> 1;
	move_low = ((uint8_t)unscaled_move >> 1) | (carry << 7);
	carry = move_high & 1u;
	scaled_move = ((uint32_t)(uint8_t)((int8_t)move_high >> 1) << 8) | (uint8_t)((move_low >> 1) | (carry << 7));
	return scaled_move;
}

/* The move in F0 divided by 2. */
uint16_t camera_scale_half(void)
{
	uint32_t carry = 0;
	uint8_t move_high = 0;
	uint16_t scaled_move = 0;
	uint16_t unscaled_move = 0;

	unscaled_move = camera_scaled_move;
	move_high = (uint8_t)(unscaled_move >> 8);
	carry = move_high & 1u;
	scaled_move = ((uint32_t)(uint8_t)((int8_t)move_high >> 1) << 8) | (uint8_t)(((uint8_t)unscaled_move >> 1) | (carry << 7));
	return scaled_move;
}

/* The move in F0 as it is. */
uint16_t camera_scale_same(void)
{
	uint16_t scaled_move = 0;

	scaled_move = camera_scaled_move;
	return scaled_move;
}

/* No move. */
uint16_t camera_scale_none(void)
{
	uint16_t scaled_move = 0;

	scaled_move = 0u;
	return scaled_move;
}

/* The move in F0 times 2. */
uint16_t camera_scale_double(void)
{
	uint32_t carry = 0;
	uint8_t move_low = 0;
	uint16_t scaled_move = 0;
	uint16_t unscaled_move = 0;

	unscaled_move = camera_scaled_move;
	move_low = (uint8_t)unscaled_move;
	carry = (int8_t)move_low < 0;
	scaled_move = ((uint32_t)(uint8_t)(((uint32_t)(unscaled_move >> 8) << 1) | carry) << 8) | (uint8_t)((uint32_t)move_low << 1);
	return scaled_move;
}

/* The move in F0 times 4. */
uint16_t camera_scale_quadruple(void)
{
	uint32_t carry = 0;
	uint8_t move_high = 0, move_low = 0;
	uint16_t scaled_move = 0;
	uint16_t unscaled_move = 0;

	unscaled_move = camera_scaled_move;
	move_low = (uint8_t)unscaled_move;
	carry = (int8_t)move_low < 0;
	move_low = (uint32_t)move_low << 1;
	move_high = (uint8_t)(((uint32_t)(unscaled_move >> 8) << 1) | carry);
	carry = (int8_t)move_low < 0;
	scaled_move = ((uint32_t)(uint8_t)(((uint32_t)move_high << 1) | carry) << 8) | (uint8_t)((uint32_t)move_low << 1);
	return scaled_move;
}

/* Stage 6, Dreamland (step 11): layer A scrolls down a line a frame without end, layer B and the sprites
   bob a pixel every 8 frames, turning every 32 frames, and the camera follows the stage's record. */
uint16_t dreamland_scroll(void)
{
	uint32_t carry = 0;
	uint8_t scroll_step = 0;
	uint16_t u = 0;
	uint16_t layer_a_y_low = 0, old_layer_a_y_low = 0, layer_b_y_again = 0, layer_b_y_minus = 0, layer_b_y = 0, layer_b_y_plus = 0, sprite_y_again = 0, sprite_y_minus = 0, sprite_y = 0, sprite_y_plus = 0, sprite_x_now = 0, sprite_y_now = 0;

	layer_a_y_low = AT16(layer_a_scroll_y, -1);
	old_layer_a_y_low = layer_a_y_low;
	carry = (uint16_t)(old_layer_a_y_low + 0x100u) < old_layer_a_y_low;
	AT16(layer_a_scroll_y, -1) = old_layer_a_y_low + 0x100u;
	layer_a_scroll_y = (layer_a_scroll_y & 0xFFu) | ((((uint8_t)(layer_a_scroll_y >> 8u) + carry) & 1u & 0xFFu) << 8u);
	scroll_step = stage_scroll_step;
	if ((scroll_step & 0x20u) != 0u)
	{
		if ((scroll_step & 7u) == 0u)
		{
			layer_b_y_again = layer_b_scroll_y;
			layer_b_y_minus = layer_b_y_again - 1u;
			layer_b_scroll_y = layer_b_y_minus;
		}
	}
	else if ((scroll_step & 7u) == 0u)
	{
		layer_b_y = layer_b_scroll_y;
		layer_b_y_plus = layer_b_y + 1u;
		layer_b_scroll_y = layer_b_y_plus;
	}
	scroll_step = stage_scroll_step;
	if (flip_screen != 0u)
		scroll_step = ~scroll_step;
	if ((scroll_step & 0x20u) != 0u)
	{
		if ((stage_scroll_step & 7u) == 0u)
		{
			sprite_y_again = sprite_scroll_y;
			sprite_y_minus = sprite_y_again - 1u;
			sprite_scroll_y = sprite_y_minus;
		}
	}
	else if ((stage_scroll_step & 7u) == 0u)
	{
		sprite_y = sprite_scroll_y;
		sprite_y_plus = sprite_y + 1u;
		sprite_scroll_y = sprite_y_plus;
	}
	stage_scroll_step++;
	sprite_x_now = sprite_scroll_x;
	io_write16(sprite_chip_scroll_x, sprite_x_now);
	sprite_y_now = sprite_scroll_y;
	io_write16(sprite_chip_scroll_y, sprite_y_now);
	u = camera_update();
	return u;
}

/* Stage 7 (step 13): the camera follows the stage's record and, by stage_scroll_step, the stage moves on
   to its next part at 0610. */
uint16_t stage_7_scroll(void)
{
	uint16_t u = 0;

	u = camera_update();
	switch ((int8_t)(uint8_t)((uint32_t)stage_scroll_step << 1))
	{
	case 0:
		stage_7_next_part();
		return u;
	case 2:
		stage_7_scroll_end();
		return u;
	case 4:
		screen_shake_none();
		return u;
	case 6:
		return screen_shake_by_kind(u);
	case 8:
	case 10:
	case 12:
		return screen_shake_advance(u);
	}
	unreachable();
}
