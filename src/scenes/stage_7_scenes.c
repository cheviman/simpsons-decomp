/**
 *    Name:        scenes/stage_7_scenes.c
 *    Description: stage 7's two scripted scenes
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 7's scene: puts the four kind-A4 objects at their places in the stage. */
uint16_t stage_7_scene_set_up(void)
{
	uint16_t default_object = 0, object = 0, record_and_count = 0;
	uint16_t saved_record_and_count = 0;
	uint8_t placements_left = 0, old_scene_state = 0;
	uint16_t placed_x = 0, z = 0;

	default_object = clear_child_objects();
	scene_x_offset = 0x8CFu - camera_x;
	record_and_count = 0x1404u;
	do
	{
		saved_record_and_count = record_and_count;
		object = scene_put_placement(default_object, record_and_count);
		placed_x = OBJECT(object)->x;
		OBJECT(object)->x = placed_x + scene_x_offset;
		z = OBJECT(object)->z;
		OBJECT(object)->z = z + camera_y;
		OBJECT(object)->y = 0xD8u;
		record_and_count = (saved_record_and_count & 0xFFu) | ((uint32_t)(uint8_t)((saved_record_and_count >> 8) + 1u) << 8);
		placements_left = (uint8_t)record_and_count;
		record_and_count = (record_and_count & ~0xFFu) | (uint8_t)(placements_left - 1u);
	} while (placements_left != 1u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return default_object;
}

/* Stage 7's scene: waits for the scroll to reach them, then a sound (7A00). */
void stage_7_scene_wait_scroll(void)
{
	uint16_t command = 0;
	uint8_t old_scene_state = 0;

	if ((int16_t)camera_x < 0x9B0)
		return;
	command = 0x7A00u;
	vector_queue_sound(command);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Unused: would wait for the scroll to reach 0A4F. */
void unused_stage_7_scene_wait_far(void)
{
	uint8_t old_scene_state = 0;

	if ((int16_t)camera_x >= 0xA4F)
	{
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* Stage 7's scene: waits for the stage's signal to go on. */
void stage_7_scene_wait_signal(void)
{
	uint8_t old_scene_state = 0;

	if (stage_cue != 0u)
	{
		io_write16(scene_wait, 0xFFFFu);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
	}
}

/* Stage 7's scene: the view and the objects rise faster and faster, a row of tiles blanked as it goes;
   when the time is up, the scene's variables are cleared and it is over. */
void stage_7_scene_lift(uint16_t *p_tile, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t tile_code = 0, tile_colour = 0;
	uint16_t clear_from = 0, clear_to = 0, count = 0, object = 0, tile = 0;
	uint8_t speed_high = 0, items_left = 0, columns_left = 0;
	uint16_t lift_frames_left = 0, lift_speed = 0, new_lift_speed = 0, layer_b_y_low = 0, speed_added = 0, old_layer_b_y_low = 0, new_layer_b_y_low = 0, item_speed = 0, z = 0, row_offset = 0, tile_place = 0;

	lift_frames_left = io_read16(scene_wait);
	io_write16(scene_wait, lift_frames_left - 1u);
	if (lift_frames_left == 1u)
	{
		clear_from = scene_state;
		clear_to = scene_substate;
		io_write8(scene_state, 0u);
		count = 0x1Fu;
		while (count != 0u)
		{
			mem_write8(clear_to, mem_read8(clear_from));
			clear_from++;
			clear_to++;
			count--;
		}
		vector_clear_objects(&tile, &u);
		scene_running = 0u;
	}
	else
	{
		lift_speed = io_read16(scene_layer_b_speed);
		new_lift_speed = lift_speed + 2u;
		io_write16(scene_layer_b_speed, new_lift_speed);
		layer_b_y_low = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
		speed_added = io_read16(scene_layer_b_speed);
		old_layer_b_y_low = layer_b_y_low;
		new_layer_b_y_low = old_layer_b_y_low + speed_added;
		carry = (uint16_t)(old_layer_b_y_low + speed_added) < old_layer_b_y_low;
		layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((new_layer_b_y_low >> 8u) & 0xFFu);
		layer_b_scroll_y_fraction = (uint8_t)new_layer_b_y_low;
		speed_high = io_read8(scene_layer_b_speed);
		layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | ((((uint16_t)(int8_t)speed_high >> 8) + (uint8_t)(layer_b_scroll_y >> 8u) + carry & 0xFFu) << 8u);
		object = OBJECT_ADDRESS(8);
		lift_items_left = 4u;
		do
		{
			item_speed = io_read16(scene_layer_b_speed);
			OBJECT(object)->z_speed = item_speed;
			object += 0x60u;
			items_left = lift_items_left;
			lift_items_left = items_left - 1u;
		} while (items_left != 1u);
		z = OBJECT(OBJECT_ADDRESS(10))->z;
		if ((int16_t)z >= 0x8F)
			OBJECT(OBJECT_ADDRESS(10))->shadow_player = 1u;
		row_offset = ((((((uint8_t)layer_b_scroll_y >> 1) >> 1) >> 1) + 0x1Cu) & 0x1Fu) * 0x40u;
		tile = 0x3000u + row_offset;
		lift_items_left = 0x40u;
		tile_code = 0x10u;
		tile_colour = 0u;
		do
		{
			mem_write8(tile - 0x2000u, tile_colour);
			tile_place = tile;
			tile = tile_place + 1u;
			mem_write8(tile_place, tile_code);
			columns_left = lift_items_left;
			lift_items_left = columns_left - 1u;
		} while (columns_left != 1u);
	}
	*p_tile = tile;
	*p_u = u;
}

/* Stage 7's scene, second track: waits for its signal from the stage. */
void stage_7_scene_wait_train(void)
{
	uint8_t old_scene_substate = 0;

	if (stage_cue_timer != 0u)
	{
		old_scene_substate = io_read8(scene_substate);
		io_write8(scene_substate, old_scene_substate + 1u);
	}
}

/* Stage 7's scene, second track: puts a chain of six linked pairs of objects and plays a sound (8300). */
void stage_7_scene_put_chain(uint16_t *p_last_link, uint16_t *p_new_object)
{
	uint16_t command = 0, last_link = 0, link = 0, link_before = 0, new_object = 0, record_number = 0, upper_link = 0;
	uint16_t saved_link = 0;
	uint8_t links_left = 0, old_scene_substate = 0;
	uint16_t first_link = 0;

	io_write16(bonus_1_intro_player, 0x808u);
	new_object = stage_7_scene_new_object();
	io_write16(chain_lead_link, new_object);
	io_write16(chain_end_link, new_object);
	chain_last_link = new_object;
	chain_links_left = 6u;
	do
	{
		record_number = 0x2800u;
		link = stage_7_scene_put_link(new_object, record_number);
		saved_link = link;
		link_before = chain_last_link;
		OBJECT(link_before)->stage_7_link.next_link = link;
		chain_last_link = link;
		new_object = stage_7_scene_new_object();
		record_number = 0x2900u;
		link = stage_7_scene_put_link(new_object, record_number);
		upper_link = saved_link;
		OBJECT(upper_link)->stage_7_link.pair = link;
		new_object = stage_7_scene_new_object();
		last_link = saved_link;
		links_left = chain_links_left;
		chain_links_left = links_left - 1u;
	} while (links_left != 1u);
	first_link = io_read16(chain_lead_link);
	OBJECT(last_link)->stage_7_link.next_link = first_link;
	command = 0x8300u;
	vector_queue_sound(command);
	old_scene_substate = io_read8(scene_substate);
	io_write8(scene_substate, old_scene_substate + 1u);
	*p_last_link = last_link;
	*p_new_object = new_object;
}

/* Stage 7's scene, second track: moves the chain along until it is in place, then stops it. */
void stage_7_scene_move_chain(uint16_t *p_link, uint16_t *p_pair)
{
	uint16_t end_link = 0, link = 0, pair = 0, x_speed = 0;
	uint8_t links_left = 0, old_scene_substate = 0, old_links_moved = 0, links_moved = 0;
	uint16_t end_link_place = 0, end_x = 0, first_link = 0, pair_2 = 0, next_link = 0, lead_link = 0, lead_x = 0, chain_spacing = 0, pair_3 = 0, next_link_2 = 0;

	end_link_place = io_read16(chain_end_link);
	end_link = end_link_place;
	end_x = OBJECT(end_link)->x;
	if ((uint16_t)(end_x - 0x40u + camera_x) == 0x9E8u)
	{
		first_link = io_read16(chain_lead_link);
		link = first_link;
		chain_links_left = 6u;
		x_speed = 0u;
		do
		{
			OBJECT(link)->x_speed = x_speed;
			pair_2 = OBJECT(link)->stage_7_link.pair;
			pair = pair_2;
			OBJECT(pair)->x_speed = x_speed;
			next_link = OBJECT(link)->stage_7_link.next_link;
			link = next_link;
			links_left = chain_links_left;
			chain_links_left = links_left - 1u;
		} while (links_left != 1u);
		old_scene_substate = io_read8(scene_substate);
		io_write8(scene_substate, old_scene_substate + 1u);
	}
	else
	{
		lead_link = io_read16(chain_lead_link);
		link = lead_link;
		lead_x = OBJECT(link)->x;
		chain_spacing = io_read16(bonus_1_intro_player);
		if ((uint16_t)(lead_x - 0x40u + camera_x - chain_spacing) != 0x60u)
		{
			OBJECT(link)->x_speed = 0x200;
			pair_3 = OBJECT(link)->stage_7_link.pair;
			pair = pair_3;
			OBJECT(pair)->x_speed = 0x200;
		}
		else
		{
			old_links_moved = io_read8(dream_wave_size);
			io_write8(dream_wave_size, old_links_moved + 1u);
			links_moved = io_read8(dream_wave_size);
			if ((uint16_t)((uint32_t)links_moved << 8) >> 8 == 6u)
			{
				first_link = io_read16(chain_lead_link);
				link = first_link;
				chain_links_left = 6u;
				x_speed = 0u;
				do
				{
					OBJECT(link)->x_speed = x_speed;
					pair_2 = OBJECT(link)->stage_7_link.pair;
					pair = pair_2;
					OBJECT(pair)->x_speed = x_speed;
					next_link = OBJECT(link)->stage_7_link.next_link;
					link = next_link;
					links_left = chain_links_left;
					chain_links_left = links_left - 1u;
				} while (links_left != 1u);
				old_scene_substate = io_read8(scene_substate);
				io_write8(scene_substate, old_scene_substate + 1u);
			}
			else
			{
				next_link_2 = OBJECT(link)->stage_7_link.next_link;
				link = next_link_2;
				io_write16(chain_lead_link, link);
				OBJECT(link)->x_speed = 0x200;
				pair_3 = OBJECT(link)->stage_7_link.pair;
				pair = pair_3;
				OBJECT(pair)->x_speed = 0x200;
			}
		}
	}
	*p_link = link;
	*p_pair = pair;
}

/* Stage 7's scene, second track: clears its signal. */
void stage_7_scene_chain_done(void)
{
	stage_cue_timer = 0u;
}

/* Stage 7's scene: puts the given record of object_12_placements as a link of the chain at the chain's
   start. */
uint16_t stage_7_scene_put_link(uint16_t new_object, uint16_t record_number)
{
	uint16_t default_object = 0, link = 0;

	default_object = new_object;
	link = scene_put_placement(default_object, record_number);
	OBJECT(link)->type = -0xC;
	OBJECT(link)->x = 0x808u - camera_x + 0x40u;
	OBJECT(link)->y = 0x90u + camera_y;
	return link;
}

/* Stage 7's scene: takes a free object from the first list, or else the second. */
uint16_t stage_7_scene_new_object(void)
{
	uint32_t slot_found = 0;
	uint8_t list_number = 0;
	uint16_t free_slot = 0;

	list_number = 0u;
	vector_find_free_slot(list_number, &free_slot, &slot_found);
	if (slot_found == 0u)
	{
		list_number = 1u;
		vector_find_free_slot(list_number, &free_slot, &slot_found);
	}
	return free_slot;
}

/* Stage 7's closing scene: stops the sound, loads its colours and clears the screen. */
void stage_7_end_set_up(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0, x = 0;
	uint8_t old_scene_state = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	command = 0x7A00u;
	vector_queue_sound_always(command);
	palette_request_kind = 1u;
	request = 0xC8Cu;
	vector_palette_request(u, request);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16, &u_2);
	x = vector_clear_sprites();
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x;
	*p_u = u_2;
}

/* Stage 7's closing scene: Channel 6's area 1 with its colours. */
void stage_7_end_show(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t layer_and_columns = 0, request = 0, u_2 = 0, x_2 = 0;
	uint8_t old_scene_state = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	map_scene = 0x8Cu;
	map_area = 1u;
	vector_set_layer_modes();
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &x_2, &u_2);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	palette_request_kind = 3u;
	request = 0x7A53u;
	u_2 = vector_palette_request(u_2, request);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	*p_x = x_2;
	*p_u = u_2;
}

/* Stage 7's closing scene: puts the kind-A4 object moving off and the players who played aboard it. */
void stage_7_end_board(uint16_t default_object)
{
	uint8_t record = 0;
	uint16_t object = 0, record_number = 0;
	uint8_t saved_record = 0;
	uint8_t riders_left = 0, old_scene_state = 0;

	record_number = 0x1800u;
	object = scene_put_placement(default_object, record_number);
	OBJECT(object)->x_speed = 0x200;
	OBJECT(object)->zoom_x = 0x40u;
	OBJECT(object)->zoom_y = 0x40u;
	OBJECT(object)->attributes = 0x40u;
	scene_riders_left = 4u;
	rider_bits = players_present;
	record = 0x19u;
	do
	{
		if ((rider_bits & 1u) != 0u)
		{
			saved_record = record;
			record_number = (uint32_t)record << 8;
			object = scene_put_placement(default_object, record_number);
			OBJECT(object)->zoom_x = 0x40u;
			OBJECT(object)->zoom_y = 0x40u;
			OBJECT(object)->attributes = 0x40u;
			record = saved_record;
		}
		record++;
		rider_bits = rider_bits >> 1;
		riders_left = scene_riders_left;
		scene_riders_left = riders_left - 1u;
	} while (riders_left != 1u);
	io_write16(scene_wait, 0xF0u);
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
}

/* Stage 7's closing scene: the kind-A4 object flies up into the distance with the players aboard, then
   crosses back far off, small. */
uint16_t stage_7_end_take_off(void)
{
	uint8_t record = 0;
	uint16_t default_object = 0, object = 0, object_2 = 0, record_number = 0;
	uint8_t saved_record = 0;
	uint8_t zoom_x = 0, zoom_y = 0, riders_left = 0, old_scene_state = 0;
	uint16_t board_x = 0, z_speed = 0, new_z_speed = 0, take_off_wait = 0;

	object = OBJECT_ADDRESS(8);
	board_x = OBJECT(OBJECT_ADDRESS(8))->x;
	if ((int16_t)board_x >= 0xE0)
	{
		z_speed = OBJECT(object)->z_speed;
		new_z_speed = z_speed + 4u;
		OBJECT(object)->z_speed = new_z_speed;
		if ((frame_count & 3u) == 0u)
		{
			zoom_x = OBJECT(object)->zoom_x;
			OBJECT(object)->zoom_x = zoom_x + 1u;
			zoom_y = OBJECT(object)->zoom_y;
			OBJECT(object)->zoom_y = zoom_y + 1u;
		}
	}
	default_object = stage_7_end_zoom_riders();
	take_off_wait = io_read16(scene_wait);
	io_write16(scene_wait, take_off_wait - 1u);
	if (take_off_wait != 1u)
		return stage_7_end_move_riders();
	record_number = 0x1D00u;
	object_2 = scene_put_placement(default_object, record_number);
	OBJECT(object_2)->x_speed = -0x80;
	OBJECT(object_2)->x_speed = -0x80;
	OBJECT(object_2)->z_speed = 0x80;
	OBJECT(object_2)->flags |= 0x10u;
	OBJECT(object_2)->attributes = 0u;
	OBJECT(object_2)->zoom_x = 0xC0u;
	OBJECT(object_2)->zoom_y = 0xC0u;
	scene_riders_left = 4u;
	rider_bits = players_present;
	record = 0x1Eu;
	do
	{
		if ((rider_bits & 1u) != 0u)
		{
			saved_record = record;
			record_number = (uint32_t)record << 8;
			object_2 = scene_put_placement(default_object, record_number);
			OBJECT(object_2)->flags |= 0x10u;
			OBJECT(object_2)->attributes = 0u;
			OBJECT(object_2)->zoom_x = 0xC0u;
			OBJECT(object_2)->zoom_y = 0xC0u;
			record = saved_record;
		}
		record++;
		rider_bits = rider_bits >> 1;
		riders_left = scene_riders_left;
		scene_riders_left = riders_left - 1u;
	} while (riders_left != 1u);
	OBJECT(OBJECT_ADDRESS(8))->attributes = 0x20u;
	OBJECT(OBJECT_ADDRESS(9))->attributes = 0x20u;
	OBJECT(OBJECT_ADDRESS(10))->attributes = 0x20u;
	OBJECT(OBJECT_ADDRESS(11))->attributes = 0x20u;
	OBJECT(OBJECT_ADDRESS(12))->attributes = 0x20u;
	old_scene_state = io_read8(scene_state);
	io_write8(scene_state, old_scene_state + 1u);
	return stage_7_end_zoom_riders();
}

/* Stage 7's closing scene: the kind-A4 object slows down until it is in place (no scenario reaches it). */
void stage_7_end_slow_down(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0, z_speed = 0;
	uint8_t old_scene_state = 0;
	uint16_t z_speed_2 = 0;

	z_speed_2 = OBJECT(OBJECT_ADDRESS(8))->z_speed;
	z_speed = z_speed_2 - 1u;
	if (z_speed_2 == 0u)
		z_speed = 0u;
	OBJECT(OBJECT_ADDRESS(8))->z_speed = z_speed;
	if ((int16_t)OBJECT(OBJECT_ADDRESS(8))->x > 0x130)
		x = stage_7_end_zoom_riders();
	else
	{
		io_write16(scene_wait, 0x100u);
		old_scene_state = io_read8(scene_state);
		io_write8(scene_state, old_scene_state + 1u);
		stage_7_end_finish(&x, &u);
	}
	*p_x = x;
	*p_u = u;
}

/* Stage 7's closing scene: after its time, it is over and the objects are cleared. */
void stage_7_end_finish(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0;
	uint16_t finish_wait = 0;

	OBJECT(OBJECT_ADDRESS(8))->z_speed--;
	finish_wait = io_read16(scene_wait);
	io_write16(scene_wait, finish_wait - 1u);
	if (finish_wait != 1u)
		x = stage_7_end_zoom_riders();
	else
	{
		vector_clear_objects(&x, &u);
		scene_running = 0u;
	}
	*p_x = x;
	*p_u = u;
}

/* Stage 7's closing scene: the kind-A4 object and its riders drawn zoomed, the riders moving with it. */
uint16_t stage_7_end_zoom_riders(void)
{
	uint16_t object = 0;
	uint8_t objects_left = 0;

	object = OBJECT_ADDRESS(8);
	scene_objects_left = 5u;
	do
	{
		OBJECT(object)->flags |= 0x10u;
		object += 0x60u;
		objects_left = scene_objects_left;
		scene_objects_left = objects_left - 1u;
	} while (objects_left != 1u);
	return stage_7_end_move_riders();
}

/* Stage 7's closing scene: the riders take the kind-A4 object's speeds and size. */
uint16_t stage_7_end_move_riders(void)
{
	uint8_t zoom_x = 0;
	uint16_t object = 0;
	uint8_t riders_left = 0;
	uint16_t x_speed = 0, z_speed = 0;

	object = OBJECT_ADDRESS(9);
	scene_objects_left = 4u;
	do
	{
		x_speed = OBJECT(OBJECT_ADDRESS(8))->x_speed;
		OBJECT(object)->x_speed = x_speed;
		z_speed = OBJECT(OBJECT_ADDRESS(8))->z_speed;
		OBJECT(object)->z_speed = z_speed;
		zoom_x = OBJECT(OBJECT_ADDRESS(8))->zoom_x;
		OBJECT(object)->zoom_x = zoom_x;
		OBJECT(object)->zoom_y = zoom_x;
		object += 0x60u;
		riders_left = scene_objects_left;
		scene_objects_left = riders_left - 1u;
	} while (riders_left != 1u);
	return object;
}
