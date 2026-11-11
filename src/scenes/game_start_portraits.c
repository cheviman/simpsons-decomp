/**
 *    Name:        scenes/game_start_portraits.c
 *    Description: the game start's four portraits
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs the game start's portraits screen and counts the players' presses */
void game_start_portraits(uint16_t u)
{
	uint8_t wait = 0;
	uint16_t controls = 0, subphase_steps = 0;
	uint8_t old_skip_wait = 0, players_left = 0;

	scene_running = 0u;
	game_start_join_players();
	subphase_steps = game_start_portraits_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_subphase << 1))
	{
	case 0:
		game_start_draw_portraits(u);
		break;
	case 2:
		game_start_run_portraits();
		break;
	case 4:
		portrait_start(subphase_steps, u);
		break;
	case 6:
		portrait_wait_join(subphase_steps, u);
		break;
	case 8:
		portrait_wait(subphase_steps);
		break;
	case 10:
		portrait_come_alive(subphase_steps, u);
		break;
	case 12:
		portrait_blink_now_and_then(subphase_steps);
		break;
	case 14:
		portrait_wait_animation(subphase_steps);
		break;
	}
	old_skip_wait = skip_wait;
	wait = old_skip_wait + 1u;
	if ((uint8_t)(old_skip_wait + 1u) < old_skip_wait)
		wait = 0xFFu;
	skip_wait = wait;
	if (wait < 0x20u)
		return;
	controls = player_controls_ADDRESS + 0x2u;
	portrait_player_bit = 1u;
	portrait_players_left = 4u;
	do
	{
		if ((players_joined & portrait_player_bit) != 0u)
		{
			if (separate_coin_slots != 0u)
			{
				if ((mem_read8(controls) & 0xB0u) != 0u)
				{
					skip_wait = 0u;
					scene_running++;
				}
			}
			else if ((mem_read8(controls) & 0xB0u) != 0u)
			{
				skip_wait = 0u;
				scene_running++;
			}
		}
		controls += 4u;
		portrait_player_bit = (uint32_t)portrait_player_bit << 1;
		players_left = portrait_players_left;
		portrait_players_left = players_left - 1u;
	} while (players_left != 1u);
}

/* Marks in 485B the players who join (pressing, or with free play set up) */
void game_start_join_players(void)
{
	uint8_t count = 0;
	uint16_t controls = 0, slot_credit = 0;
	uint8_t slots_left = 0, players_left = 0;

	if (separate_coin_slots != 0u)
	{
		slot_credit = slot_credits_ADDRESS;
		join_bit_or_slots = 4u;
		join_slot_bit = 1u;
		do
		{
			if (mem_read16(slot_credit) != 0u)
				players_joined |= join_slot_bit;
			slot_credit += 8u;
			join_slot_bit = (uint32_t)join_slot_bit << 1;
			slots_left = join_bit_or_slots;
			join_bit_or_slots = slots_left - 1u;
		} while (slots_left != 1u);
		return;
	}
	if (credits == 0u)
		return;
	controls = player_controls_ADDRESS + 0x2u;
	count = 4u;
	join_bit_or_slots = 1u;
	do
	{
		if ((mem_read8(controls) & 0xB0u) != 0u)
			players_joined |= join_bit_or_slots;
		controls += 4u;
		join_bit_or_slots = (uint32_t)join_bit_or_slots << 1;
		players_left = count;
		count = players_left - 1u;
	} while (players_left != 1u);
}

/* Draws the portraits' screen: palettes, scene 80 and each portrait's colours */
void game_start_draw_portraits(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, layer_and_columns = 0, portrait_area = 0, request = 0, tile = 0;
	uint8_t tile_low = 0, tile_high = 0;
	uint8_t columns_left = 0, rows_left = 0;
	uint16_t area_record = 0;

	io_write8(colour_bases_back_sprites_fixed, 0x3Fu);
	io_write8(colour_bases_layers_a_b, 0x36u);
	palette_request_kind = 1u;
	request = 0x408u;
	palette_job = vector_palette_request(palette_job, request);
	palette_request_kind = 2u;
	request = 0x1Bu;
	vector_palette_request(palette_job, request);
	map_scene = 0x80u;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	layer_and_columns = 0x12Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16, &ignored16_2);
	portrait_number = 0u;
	do
	{
		area_record = portrait_areas_ADDRESS + (int8_t)(((uint32_t)portrait_number << 1) << 1);
		portrait_area = area_record + 2u;
		tile = PORTRAIT_AREA(area_record)->tiles;
		portrait_rows_left = 0x14u;
		do
		{
			portrait_columns_left = 9u;
			do
			{
				mem_write8(tile - 0x2000u, PORTRAIT_AREA(portrait_area - 0x2u)->colour);
				tile++;
				tile_high = tile >> 8;
				tile_low = (uint8_t)tile;
				tile_high = (tile_high & 7u) | 0x28u;
				tile = ((uint32_t)tile_high << 8) | tile_low;
				columns_left = portrait_columns_left;
				portrait_columns_left = columns_left - 1u;
			} while (columns_left != 1u);
			tile += 0x37u;
			tile_high = tile >> 8;
			tile_low = (uint8_t)tile;
			tile_high = (tile_high & 7u) | 0x28u;
			tile = ((uint32_t)tile_high << 8) | tile_low;
			rows_left = portrait_rows_left;
			portrait_rows_left = rows_left - 1u;
		} while (rows_left != 1u);
		portrait_number++;
	} while (portrait_number != 4u);
	io_write8(colour_bases_back_sprites_fixed, 0x13u);
	io_write8(colour_bases_layers_a_b, 0x2Cu);
	step_subphase++;
}

/* Runs the four portrait objects */
void game_start_run_portraits(void)
{
	uint16_t object = 0, test_player = 0;
	uint8_t portrait_index = 0;

	object = OBJECT_ADDRESS(14);
	portrait_player_bit = 1u;
	portrait_index = 0u;
	do
	{
		test_player = test_player_records[(int8_t)((uint8_t)((uint32_t)portrait_index << 1)) / 2];
		portrait_run(object, test_player);
		object += 0xC0u;
		portrait_player_bit = (uint32_t)portrait_player_bit << 1;
		portrait_index = portrait_index + 1u;
	} while (portrait_index != 4u);
}

/* Runs a portrait by its step */
void portrait_run(uint16_t object, uint16_t test_player)
{
	uint8_t step = 0;

	step = OBJECT(object)->portrait.step;
	switch ((int8_t)(uint8_t)((uint32_t)step << 1))
	{
	case 0:
		portrait_start(object, test_player);
		return;
	case 2:
		portrait_wait_join(object, test_player);
		return;
	case 4:
		portrait_wait(object);
		return;
	case 6:
		portrait_come_alive(object, test_player);
		return;
	case 8:
		portrait_blink_now_and_then(object);
		return;
	case 10:
		portrait_wait_animation(object);
		return;
	}
}

/* Sets the portrait and its shadow up from its record */
void portrait_start(uint16_t object, uint16_t test_player)
{
	uint16_t kind = 0, kind_and_animation = 0;
	uint8_t step = 0;
	uint16_t kind_2 = 0, portrait_x = 0, z = 0, shadow_kind = 0, shadow_x = 0;

	OBJECT(object)->flags = 0x80u;
	kind_2 = (((uint32_t)TEST_PLAYER(test_player)->kind << 8u) | TEST_PLAYER(test_player)->animation);
	kind_and_animation = kind_2;
	OBJECT(object)->kind = kind_and_animation >> 8;
	OBJECT(object)->animation = kind_and_animation | 0x80u;
	portrait_x = TEST_PLAYER(test_player)->x;
	OBJECT(object)->x = portrait_x;
	OBJECT(object)->y = 0x80u;
	z = TEST_PLAYER(test_player)->z;
	OBJECT(object)->z = z;
	shadow_kind = TEST_PLAYER(test_player)->shadow_kind;
	kind = shadow_kind;
	OBJECT(object + 0x60u)->kind = (uint8_t)(kind >> 8u);
	OBJECT(object + 0x60u)->animation = (uint8_t)kind;
	shadow_x = TEST_PLAYER(test_player)->shadow_x;
	OBJECT(object + 0x60u)->x = shadow_x;
	OBJECT(object + 0x60u)->y = 0x80u;
	OBJECT(object + 0x60u)->z = 0x58u;
	step = OBJECT(object)->portrait.step;
	OBJECT(object)->portrait.step = step + 1u;
}

/* Waits for its player to join */
void portrait_wait_join(uint16_t object, uint16_t test_player)
{
	uint8_t button = 0, step = 0;

	button = TEST_PLAYER(test_player)->button;
	if ((button & players_joined) != 0u)
	{
		OBJECT(object)->portrait.wait = 0x20u;
		step = OBJECT(object)->portrait.step;
		OBJECT(object)->portrait.step = step + 1u;
	}
}

/* Waits 20 frames after its player joins */
void portrait_wait(uint16_t object)
{
	uint8_t wait = 0, step = 0;

	wait = OBJECT(object)->portrait.wait;
	OBJECT(object)->portrait.wait = wait - 1u;
	if (wait != 1u)
	{
		OBJECT(object)->portrait.portrait_frame = 0x11u;
		OBJECT(object)->portrait.frame_wait = 3u;
		step = OBJECT(object)->portrait.step;
		OBJECT(object)->portrait.step = step + 1u;
	}
}

/* Animates the portrait coming alive, then its colours and its voice */
void portrait_come_alive(uint16_t object, uint16_t test_player)
{
	uint8_t frame = 0;
	uint16_t command = 0, request = 0, test_player_again = 0;
	uint8_t saved_frame = 0;
	uint16_t saved_test_player = 0;
	uint8_t wait_left = 0, portrait_frame = 0, portrait_frame_2 = 0, palette_set = 0, step = 0;
	uint16_t palette_effect = 0, start_sound = 0;

	wait_left = OBJECT(object)->portrait.frame_wait;
	OBJECT(object)->portrait.frame_wait = wait_left - 1u;
	if (wait_left != 1u)
		return;
	OBJECT(object)->portrait.frame_wait = 3u;
	portrait_frame = OBJECT(object)->portrait.portrait_frame;
	OBJECT(object)->portrait.portrait_frame = portrait_frame + 1u;
	portrait_frame_2 = OBJECT(object)->portrait.portrait_frame;
	frame = portrait_frame_2;
	if (frame != 0x16u)
	{
		OBJECT(object)->animation = frame | 0x80u;
		return;
	}
	OBJECT(object + 0x60u)->flags = 0x80u;
	saved_frame = frame;
	saved_test_player = test_player;
	palette_request_kind = 1u;
	palette_set = TEST_PLAYER(test_player)->palette_set;
	request = 0x600u | palette_set;
	vector_palette_request(test_player, request);
	test_player = saved_test_player;
	palette_request_kind = 2u;
	palette_effect = TEST_PLAYER(test_player)->palette_effect;
	request = palette_effect;
	vector_palette_request(test_player, request);
	test_player_again = saved_test_player;
	start_sound = TEST_PLAYER(test_player_again)->sound;
	command = start_sound;
	vector_queue_sound_always(command);
	frame = saved_frame;
	step = OBJECT(object)->portrait.step;
	OBJECT(object)->portrait.step = step + 1u;
	OBJECT(object)->animation = frame | 0x80u;
}

/* Now and then (at random) plays its idle animation */
void portrait_blink_now_and_then(uint16_t object)
{
	uint16_t object_as_number = 0;
	uint8_t step = 0;

	object_as_number = object;
	if (((object_as_number + random_number) & 0xF7u) == 0u)
	{
		OBJECT(object)->animation = 0x8Bu;
		step = OBJECT(object)->portrait.step;
		OBJECT(object)->portrait.step = step + 1u;
	}
}

/* Waits for the idle animation's end, then waits for the next */
void portrait_wait_animation(uint16_t object)
{
	uint8_t animation_flags = 0, step = 0;

	animation_flags = OBJECT(object)->animation_flags;
	if ((animation_flags & 1u) != 0u)
	{
		step = OBJECT(object)->portrait.step;
		OBJECT(object)->portrait.step = step - 1u;
	}
}
