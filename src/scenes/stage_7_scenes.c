/**
 *    Name:        scenes/stage_7_scenes.c
 *    Description: stage 7's two scripted scenes
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Stage 7's scene: puts the four kind-A4 objects at their places in the stage. */
void stage_7_scene_set_up(uint16_t *p_x, uint16_t *p_object)
{
	uint16_t object = 0, record_and_count = 0, x = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, z = 0;

	x = clear_child_objects();
	scene_x_offset = 0x8CFu - camera_x;
	record_and_count = 0x1404u;
	do
	{
		stack = record_and_count;
		object = scene_put_placement(x, record_and_count);
		t1 = OBJECT(object)->x;
		OBJECT(object)->x = t1 + scene_x_offset;
		z = OBJECT(object)->z;
		OBJECT(object)->z = z + camera_y;
		OBJECT(object)->y = 0xD8u;
		record_and_count = (stack & 0xFFu) | ((uint32_t)(uint8_t)((stack >> 8) + 1u) << 8);
		t2 = (uint8_t)record_and_count;
		record_and_count = (record_and_count & ~0xFFu) | (uint8_t)(t2 - 1u);
	} while (t2 != 1u);
	t3 = io_read8(scene_state);
	io_write8(scene_state, t3 + 1u);
	*p_x = x;
	*p_object = object;
}

/* Stage 7's scene: waits for the scroll to reach them, then a sound (7A00). */
void stage_7_scene_wait_scroll(void)
{
	uint32_t carry = 0;
	uint16_t command = 0;
	uint8_t t1 = 0;

	if ((int16_t)camera_x < 0x9B0)
		return;
	command = 0x7A00u;
	carry = vector_queue_sound(command);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
}

/* Unused: would wait for the scroll to reach 0A4F. */
void unused_stage_7_scene_wait_far(void)
{
	uint8_t t1 = 0;

	if ((int16_t)camera_x >= 0xA4F)
	{
		t1 = io_read8(scene_state);
		io_write8(scene_state, t1 + 1u);
	}
}

/* Stage 7's scene: waits for the stage's signal to go on. */
void stage_7_scene_wait_signal(void)
{
	uint8_t t1 = 0;

	if (stage_cue != 0u)
	{
		io_write16(0x18E2u, 0xFFFFu);
		t1 = io_read8(scene_state);
		io_write8(scene_state, t1 + 1u);
	}
}

/* Stage 7's scene: the view and the objects rise faster and faster, a row of tiles blanked as it goes;
   when the time is up, the scene's variables are cleared and it is over. */
void stage_7_scene_lift(uint16_t *p_tile, uint16_t *p_clear_from, uint16_t *p_u)
{
	uint16_t clear_from = (uint16_t)*p_clear_from;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t clear_to = 0, count = 0, object = 0, tile = 0;
	uint8_t t8 = 0, t10 = 0, t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, z = 0, t11 = 0, t12 = 0;

	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 == 1u)
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
		t2 = io_read16(0x18EBu);
		t3 = t2 + 2u;
		io_write16(0x18EBu, t3);
		t4 = (((uint32_t)(layer_b_scroll_y & 0xFFu) << 8u) | layer_b_scroll_y_fraction);
		t5 = io_read16(0x18EBu);
		t6 = t4;
		t7 = t6 + t5;
		carry = (uint16_t)(t6 + t5) < t6;
		layer_b_scroll_y = (layer_b_scroll_y & 0xFF00u) | ((t7 >> 8u) & 0xFFu);
		layer_b_scroll_y_fraction = (uint8_t)t7;
		t8 = io_read8(0x18EBu);
		layer_b_scroll_y = (layer_b_scroll_y & 0xFFu) | ((((uint16_t)(int8_t)t8 >> 8) + (uint8_t)(layer_b_scroll_y >> 8u) + carry & 0xFFu) << 8u);
		object = OBJECT_ADDRESS(8);
		lift_items_left = 4u;
		do
		{
			t9 = io_read16(0x18EBu);
			OBJECT(object)->z_speed = t9;
			object += 0x60u;
			t10 = lift_items_left;
			lift_items_left = t10 - 1u;
		} while (t10 != 1u);
		z = OBJECT(OBJECT_ADDRESS(10))->z;
		if ((int16_t)z >= 0x8F)
			OBJECT(OBJECT_ADDRESS(10))->shadow_player = 1u;
		t11 = ((((((uint8_t)layer_b_scroll_y >> 1) >> 1) >> 1) + 0x1Cu) & 0x1Fu) * 0x40u;
		tile = 0x3000u + t11;
		lift_items_left = 0x40u;
		a = 0x10u;
		b = 0u;
		do
		{
			mem_write8(tile - 0x2000u, b);
			t12 = tile;
			tile = t12 + 1u;
			mem_write8(t12, a);
			t13 = lift_items_left;
			lift_items_left = t13 - 1u;
		} while (t13 != 1u);
	}
	*p_tile = tile;
	*p_clear_from = clear_from;
	*p_u = u;
}

/* Stage 7's scene, second track: waits for its signal from the stage. */
void stage_7_scene_wait_train(void)
{
	uint8_t t1 = 0;

	if (stage_cue_timer != 0u)
	{
		t1 = io_read8(scene_substate);
		io_write8(scene_substate, t1 + 1u);
	}
}

/* Stage 7's scene, second track: puts a chain of six linked pairs of objects and plays a sound (8300). */
void stage_7_scene_put_chain(uint16_t *p_last_link, uint16_t *p_link, uint16_t *p_new_object)
{
	uint32_t carry = 0;
	uint16_t command = 0, last_link = 0, link = 0, new_object = 0, record_number = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	io_write16(0x18EEu, 0x808u);
	new_object = stage_7_scene_new_object();
	io_write16(0x18F0u, new_object);
	io_write16(0x18F2u, new_object);
	chain_last_link = new_object;
	chain_links_left = 6u;
	do
	{
		record_number = 0x2800u;
		link = stage_7_scene_put_link(new_object, record_number);
		stack = link;
		io_write16(chain_last_link + 0x2Au, link);
		chain_last_link = link;
		new_object = stage_7_scene_new_object();
		record_number = 0x2900u;
		link = stage_7_scene_put_link(new_object, record_number);
		mem_write16(stack + 0x28u, link);
		new_object = stage_7_scene_new_object();
		last_link = stack;
		t1 = chain_links_left;
		chain_links_left = t1 - 1u;
	} while (t1 != 1u);
	t2 = io_read16(0x18F0u);
	OBJECT(last_link)->behaviour = t2;
	command = 0x8300u;
	carry = vector_queue_sound(command);
	t3 = io_read8(scene_substate);
	io_write8(scene_substate, t3 + 1u);
	*p_last_link = last_link;
	*p_link = link;
	*p_new_object = new_object;
}

/* Stage 7's scene, second track: moves the chain along until it is in place, then stops it. */
void stage_7_scene_move_chain(uint16_t *p_link, uint16_t *p_pair)
{
	uint16_t link = 0, pair = 0, x_speed = 0;
	uint8_t t4 = 0, t5 = 0, t9 = 0, t10 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, action = 0, behaviour = 0, t6 = 0, t7 = 0, t8 = 0, action_2 = 0, behaviour_2 = 0;

	t1 = io_read16(0x18F2u);
	t2 = mem_read16(t1 + 0xCu);
	if ((uint16_t)(t2 - 0x40u + camera_x) == 0x9E8u)
	{
		t3 = io_read16(0x18F0u);
		link = t3;
		chain_links_left = 6u;
		x_speed = 0u;
		do
		{
			OBJECT(link)->x_speed = x_speed;
			action = (((uint32_t)OBJECT(link)->action << 8u) | OBJECT(link)->action_step);
			pair = action;
			OBJECT(pair)->x_speed = x_speed;
			behaviour = OBJECT(link)->behaviour;
			link = behaviour;
			t4 = chain_links_left;
			chain_links_left = t4 - 1u;
		} while (t4 != 1u);
		t5 = io_read8(scene_substate);
		io_write8(scene_substate, t5 + 1u);
	}
	else
	{
		t6 = io_read16(0x18F0u);
		link = t6;
		t7 = OBJECT(link)->x;
		t8 = io_read16(0x18EEu);
		if ((uint16_t)(t7 - 0x40u + camera_x - t8) != 0x60u)
		{
			OBJECT(link)->x_speed = 0x200;
			action_2 = (((uint32_t)OBJECT(link)->action << 8u) | OBJECT(link)->action_step);
			pair = action_2;
			OBJECT(pair)->x_speed = 0x200;
		}
		else
		{
			t9 = io_read8(0x18EDu);
			io_write8(0x18EDu, t9 + 1u);
			t10 = io_read8(0x18EDu);
			if ((uint16_t)((uint32_t)t10 << 8) >> 8 == 6u)
			{
				t3 = io_read16(0x18F0u);
				link = t3;
				chain_links_left = 6u;
				x_speed = 0u;
				do
				{
					OBJECT(link)->x_speed = x_speed;
					action = (((uint32_t)OBJECT(link)->action << 8u) | OBJECT(link)->action_step);
					pair = action;
					OBJECT(pair)->x_speed = x_speed;
					behaviour = OBJECT(link)->behaviour;
					link = behaviour;
					t4 = chain_links_left;
					chain_links_left = t4 - 1u;
				} while (t4 != 1u);
				t5 = io_read8(scene_substate);
				io_write8(scene_substate, t5 + 1u);
			}
			else
			{
				behaviour_2 = OBJECT(link)->behaviour;
				link = behaviour_2;
				io_write16(0x18F0u, link);
				OBJECT(link)->x_speed = 0x200;
				action_2 = (((uint32_t)OBJECT(link)->action << 8u) | OBJECT(link)->action_step);
				pair = action_2;
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
	uint32_t carry = 0;
	uint8_t list_number = 0;
	uint16_t u = 0;

	list_number = 0u;
	vector_find_free_slot(list_number, &u, &carry);
	if (carry == 0u)
	{
		list_number = 1u;
		vector_find_free_slot(list_number, &u, &carry);
	}
	return u;
}

/* Stage 7's closing scene: stops the sound, loads its colours and clears the screen. */
void stage_7_end_set_up(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t command = 0, ignored16 = 0, ignored16_2 = 0, job = 0, request = 0, scroll_x = 0, scroll_y = 0, u_2 = 0, x = 0, y = 0;
	uint8_t t1 = 0;

	job = 0u;
	vector_queue_job(job);
	command = 0u;
	vector_queue_sound_always(command);
	command = 0x7A00u;
	vector_queue_sound_always(command);
	palette_request_kind = 1u;
	request = 0xC8Cu;
	vector_palette_request(request, &ignored16, &u);
	scroll_x = 0xFFF0u;
	vector_set_scroll_x(scroll_x);
	scroll_y = 0u;
	vector_set_scroll_y(scroll_y);
	vector_clear_objects(&ignored16_2, &u_2);
	vector_clear_sprites(&x, &y);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x;
	*p_y = y;
	*p_u = u_2;
}

/* Stage 7's closing scene: Channel 6's area 1 with its colours. */
void stage_7_end_show(uint16_t *p_x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t layer_and_columns = 0, request = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t t1 = 0;

	if (layer_clear_pending != 0u)
		return;
	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	map_scene = 0x8Cu;
	map_area = 1u;
	vector_set_layer_modes();
	layer_and_columns = 0x126u;
	vector_draw_layer_strips(layer_and_columns, &x_2, &y_2, &u_2);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	palette_request_kind = 3u;
	request = 0x7A53u;
	vector_palette_request(request, &y_2, &u_2);
	t1 = io_read8(scene_state);
	io_write8(scene_state, t1 + 1u);
	*p_x = x_2;
	*p_y = y_2;
	*p_u = u_2;
}

/* Stage 7's closing scene: puts the kind-A4 object moving off and the players who played aboard it. */
uint16_t stage_7_end_board(uint16_t default_object)
{
	uint8_t record = 0;
	uint16_t object = 0, record_number = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

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
			stack = record;
			record_number = (uint32_t)record << 8;
			object = scene_put_placement(default_object, record_number);
			OBJECT(object)->zoom_x = 0x40u;
			OBJECT(object)->zoom_y = 0x40u;
			OBJECT(object)->attributes = 0x40u;
			record = stack;
		}
		record++;
		rider_bits = rider_bits >> 1;
		t1 = scene_riders_left;
		scene_riders_left = t1 - 1u;
	} while (t1 != 1u);
	io_write16(0x18E2u, 0xF0u);
	t2 = io_read8(scene_state);
	io_write8(scene_state, t2 + 1u);
	return object;
}

/* Stage 7's closing scene: the kind-A4 object flies up into the distance with the players aboard, then
   crosses back far off, small. */
void stage_7_end_take_off(uint16_t *p_x, uint16_t *p_object)
{
	uint16_t object = (uint16_t)*p_object;
	uint8_t record = 0;
	uint16_t object_2 = 0, record_number = 0, x = 0;
	uint8_t stack = 0;
	uint8_t zoom_x = 0, zoom_y = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, z_speed = 0, t2 = 0, t3 = 0;

	object_2 = OBJECT_ADDRESS(8);
	t1 = OBJECT(OBJECT_ADDRESS(8))->x;
	if ((int16_t)t1 >= 0xE0)
	{
		z_speed = OBJECT(object_2)->z_speed;
		t2 = z_speed + 4u;
		OBJECT(object_2)->z_speed = t2;
		if ((frame_count & 3u) == 0u)
		{
			zoom_x = OBJECT(object_2)->zoom_x;
			OBJECT(object_2)->zoom_x = zoom_x + 1u;
			zoom_y = OBJECT(object_2)->zoom_y;
			OBJECT(object_2)->zoom_y = zoom_y + 1u;
		}
	}
	x = stage_7_end_zoom_riders();
	t3 = io_read16(0x18E2u);
	io_write16(0x18E2u, t3 - 1u);
	if (t3 != 1u)
		x = stage_7_end_move_riders();
	else
	{
		record_number = 0x1D00u;
		object = scene_put_placement(x, record_number);
		OBJECT(object)->x_speed = -0x80;
		OBJECT(object)->x_speed = -0x80;
		OBJECT(object)->z_speed = 0x80;
		OBJECT(object)->flags |= 0x10u;
		OBJECT(object)->attributes = 0u;
		OBJECT(object)->zoom_x = 0xC0u;
		OBJECT(object)->zoom_y = 0xC0u;
		scene_riders_left = 4u;
		rider_bits = players_present;
		record = 0x1Eu;
		do
		{
			if ((rider_bits & 1u) != 0u)
			{
				stack = record;
				record_number = (uint32_t)record << 8;
				object = scene_put_placement(x, record_number);
				OBJECT(object)->flags |= 0x10u;
				OBJECT(object)->attributes = 0u;
				OBJECT(object)->zoom_x = 0xC0u;
				OBJECT(object)->zoom_y = 0xC0u;
				record = stack;
			}
			record++;
			rider_bits = rider_bits >> 1;
			t4 = scene_riders_left;
			scene_riders_left = t4 - 1u;
		} while (t4 != 1u);
		OBJECT(OBJECT_ADDRESS(8))->attributes = 0x20u;
		OBJECT(OBJECT_ADDRESS(9))->attributes = 0x20u;
		OBJECT(OBJECT_ADDRESS(10))->attributes = 0x20u;
		OBJECT(OBJECT_ADDRESS(11))->attributes = 0x20u;
		OBJECT(OBJECT_ADDRESS(12))->attributes = 0x20u;
		t5 = io_read8(scene_state);
		io_write8(scene_state, t5 + 1u);
		x = stage_7_end_zoom_riders();
	}
	*p_x = x;
	*p_object = object;
}

/* Stage 7's closing scene: the kind-A4 object slows down until it is in place (no scenario reaches it). */
void stage_7_end_slow_down(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t x = 0, z_speed = 0;
	uint8_t t1 = 0;
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
		io_write16(0x18E2u, 0x100u);
		t1 = io_read8(scene_state);
		io_write8(scene_state, t1 + 1u);
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
	uint16_t t1 = 0;

	OBJECT(OBJECT_ADDRESS(8))->z_speed--;
	t1 = io_read16(0x18E2u);
	io_write16(0x18E2u, t1 - 1u);
	if (t1 != 1u)
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
	uint8_t t1 = 0;

	object = OBJECT_ADDRESS(8);
	scene_objects_left = 5u;
	do
	{
		OBJECT(object)->flags |= 0x10u;
		object += 0x60u;
		t1 = scene_objects_left;
		scene_objects_left = t1 - 1u;
	} while (t1 != 1u);
	return stage_7_end_move_riders();
}

/* Stage 7's closing scene: the riders take the kind-A4 object's speeds and size. */
uint16_t stage_7_end_move_riders(void)
{
	uint8_t zoom_x = 0;
	uint16_t object = 0;
	uint8_t t1 = 0;
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
		t1 = scene_objects_left;
		scene_objects_left = t1 - 1u;
	} while (t1 != 1u);
	return object;
}
