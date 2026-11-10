/**
 *    Name:        scenes/game_start_portraits.c
 *    Description: the game start's four portraits
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
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
	uint16_t controls = 0, x = 0;
	uint8_t t1 = 0, t2 = 0;

	scene_running = 0u;
	game_start_join_players();
	x = game_start_portraits_steps_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)step_subphase << 1))
	{
	case 0:
		game_start_draw_portraits(u);
		break;
	case 2:
		game_start_run_portraits();
		break;
	case 4:
		portrait_start(x, u);
		break;
	case 6:
		portrait_wait_join(x, u);
		break;
	case 8:
		portrait_wait(x);
		break;
	case 10:
		portrait_come_alive(x, u);
		break;
	case 12:
		portrait_blink_now_and_then(x);
		break;
	case 14:
		portrait_wait_animation(x);
		break;
	}
	t1 = skip_wait;
	wait = t1 + 1u;
	if ((uint8_t)(t1 + 1u) < t1)
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
		t2 = portrait_players_left;
		portrait_players_left = t2 - 1u;
	} while (t2 != 1u);
}

/* Marks in 485B the players who join (pressing, or with free play set up) */
void game_start_join_players(void)
{
	uint8_t count = 0;
	uint16_t controls = 0, slot_credit = 0;
	uint8_t t1 = 0, t2 = 0;

	if (separate_coin_slots != 0u)
	{
		slot_credit = slot_credits_ADDRESS;
		join_player_bit = 4u;
		join_slot_bit = 1u;
		do
		{
			if (mem_read16(slot_credit) != 0u)
				players_joined |= join_slot_bit;
			slot_credit += 8u;
			join_slot_bit = (uint32_t)join_slot_bit << 1;
			t1 = join_player_bit;
			join_player_bit = t1 - 1u;
		} while (t1 != 1u);
		return;
	}
	if (credits == 0u)
		return;
	controls = player_controls_ADDRESS + 0x2u;
	count = 4u;
	join_player_bit = 1u;
	do
	{
		if ((mem_read8(controls) & 0xB0u) != 0u)
			players_joined |= join_player_bit;
		controls += 4u;
		join_player_bit = (uint32_t)join_player_bit << 1;
		t2 = count;
		count = t2 - 1u;
	} while (t2 != 1u);
}

/* Draws the portraits' screen: palettes, scene 80 and each portrait's colours */
void game_start_draw_portraits(uint16_t palette_job)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, layer_and_columns = 0, portrait_area = 0, request = 0, tile = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	io_write8(0x1FB9u, 0x3Fu);
	io_write8(0x1FBAu, 0x36u);
	palette_request_kind = 1u;
	request = 0x408u;
	vector_palette_request(request, &ignored16, &palette_job);
	palette_request_kind = 2u;
	request = 0x1Bu;
	vector_palette_request(request, &ignored16, &palette_job);
	map_scene = 0x80u;
	map_area = 0u;
	vector_set_layer_modes();
	layer_and_columns = 0x2Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
	layer_and_columns = 0x12Cu;
	vector_draw_layer_strips(layer_and_columns, &ignored16_2, &ignored16, &ignored16_3);
	portrait_number = 0u;
	do
	{
		t1 = portrait_areas_ADDRESS + (int8_t)(((uint32_t)portrait_number << 1) << 1);
		portrait_area = t1 + 2u;
		tile = PORTRAIT_AREA(t1)->tiles;
		portrait_rows_left = 0x14u;
		do
		{
			portrait_columns_left = 9u;
			do
			{
				mem_write8(tile - 0x2000u, PORTRAIT_AREA(portrait_area - 0x2u)->colour);
				tile++;
				stack_2 = tile >> 8;
				stack = (uint8_t)tile;
				stack_2 = (stack_2 & 7u) | 0x28u;
				tile = ((uint32_t)stack_2 << 8) | stack;
				t2 = portrait_columns_left;
				portrait_columns_left = t2 - 1u;
			} while (t2 != 1u);
			tile += 0x37u;
			stack_2 = tile >> 8;
			stack = (uint8_t)tile;
			stack_2 = (stack_2 & 7u) | 0x28u;
			tile = ((uint32_t)stack_2 << 8) | stack;
			t3 = portrait_rows_left;
			portrait_rows_left = t3 - 1u;
		} while (t3 != 1u);
		portrait_number++;
	} while (portrait_number != 4u);
	io_write8(0x1FB9u, 0x13u);
	io_write8(0x1FBAu, 0x2Cu);
	step_subphase++;
}

/* Runs the four portrait objects */
void game_start_run_portraits(void)
{
	uint16_t object = 0, test_player = 0;
	uint8_t stack = 0;

	object = OBJECT_ADDRESS(14);
	portrait_player_bit = 1u;
	stack = 0u;
	do
	{
		test_player = test_player_records[(int8_t)((uint8_t)((uint32_t)stack << 1)) / 2];
		portrait_run(object, test_player);
		object += 0xC0u;
		portrait_player_bit = (uint32_t)portrait_player_bit << 1;
		stack = stack + 1u;
	} while (stack != 4u);
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
	uint16_t kind_2 = 0, t1 = 0, z = 0, shadow_kind = 0, shadow_x = 0;

	OBJECT(object)->flags = 0x80u;
	kind_2 = (((uint32_t)TEST_PLAYER(test_player)->kind << 8u) | TEST_PLAYER(test_player)->animation);
	kind_and_animation = kind_2;
	OBJECT(object)->kind = kind_and_animation >> 8;
	OBJECT(object)->animation = kind_and_animation | 0x80u;
	t1 = TEST_PLAYER(test_player)->x;
	OBJECT(object)->x = t1;
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
	uint16_t command = 0, ignored16 = 0, request = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, portrait_frame = 0, portrait_frame_2 = 0, palette_set = 0, step = 0;
	uint16_t palette_effect = 0, t2 = 0;

	t1 = OBJECT(object)->portrait.frame_wait;
	OBJECT(object)->portrait.frame_wait = t1 - 1u;
	if (t1 != 1u)
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
	stack = frame;
	stack_3 = test_player;
	palette_request_kind = 1u;
	palette_set = TEST_PLAYER(test_player)->palette_set;
	request = 0x600u | palette_set;
	vector_palette_request(request, &ignored16, &test_player);
	test_player = stack_3;
	palette_request_kind = 2u;
	palette_effect = TEST_PLAYER(test_player)->palette_effect;
	request = palette_effect;
	vector_palette_request(request, &ignored16, &test_player);
	t2 = mem_read16(stack_3 + 0xFu);
	command = t2;
	vector_queue_sound_always(command);
	frame = stack;
	step = OBJECT(object)->portrait.step;
	OBJECT(object)->portrait.step = step + 1u;
	OBJECT(object)->animation = frame | 0x80u;
}

/* Now and then (at random) plays its idle animation */
void portrait_blink_now_and_then(uint16_t object)
{
	uint16_t stack = 0;
	uint8_t step = 0;

	stack = object;
	if (((stack + random_number) & 0xF7u) == 0u)
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
