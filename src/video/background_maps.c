/**
 *    Name:        video/background_maps.c
 *    Description: the tile layers' maps: the edges drawn as they scroll, whole layers, the floor map, tile pictures, the tile banks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* In the IRQ: marks a column of each tile layer to draw when its scroll x crossed 8 pixels since last
   frame, a row when its scroll y did (and the floor map's, from the floor layer), then draws the marked
   ones, one column and one row a frame unless draw_all_layer_edges is set. */
void draw_scrolled_layer_edges(void)
{
	uint8_t layers_to_draw = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	if (layer_a_edges_on != 0u)
	{
		if (layer_columns_on != 0u && ((layer_a_last_scroll_x == 0u && layer_a_scroll_x != 0u) || (((uint8_t)layer_a_scroll_x ^ (uint8_t)layer_a_last_scroll_x) & 8u) != 0u))
		{
			layers_to_draw = layer_columns_to_draw | 2u;
			if (camera_main_layer == 0u)
				layers_to_draw |= 4u;
			layer_columns_to_draw = layers_to_draw;
		}
		if (layer_rows_on != 0u && ((layer_a_last_scroll_y == 0u && layer_a_scroll_y != 0u) || (((uint8_t)layer_a_scroll_y ^ (uint8_t)layer_a_last_scroll_y) & 8u) != 0u))
		{
			layers_to_draw = layer_rows_to_draw | 2u;
			if (camera_main_layer == 0u)
				layers_to_draw |= 4u;
			layer_rows_to_draw = layers_to_draw;
		}
	}
	if (layer_b_edges_on != 0u)
	{
		if (layer_columns_on != 0u && ((layer_b_last_scroll_x == 0u && layer_b_scroll_x != 0u) || (((uint8_t)layer_b_scroll_x ^ (uint8_t)layer_b_last_scroll_x) & 8u) != 0u))
		{
			layers_to_draw = layer_columns_to_draw | 1u;
			if (camera_main_layer != 0u)
				layers_to_draw |= 4u;
			layer_columns_to_draw = layers_to_draw;
		}
		if (layer_rows_on != 0u && ((layer_b_last_scroll_y == 0u && layer_b_scroll_y != 0u) || (((uint8_t)layer_b_scroll_y ^ (uint8_t)layer_b_last_scroll_y) & 8u) != 0u))
		{
			layers_to_draw = layer_rows_to_draw | 1u;
			if (camera_main_layer != 0u)
				layers_to_draw |= 4u;
			layer_rows_to_draw = layers_to_draw;
		}
	}
	stack = 4u;
	stack_2 = 3u;
	do
	{
		if ((stack & layer_columns_to_draw) != 0u)
		{
			switch ((int8_t)(uint8_t)((uint32_t)stack_2 << 1))
			{
			case 0:
			case 6:
				draw_floor_map_column();
				break;
			case 2:
				draw_layer_b_column();
				break;
			case 4:
				draw_layer_a_column();
				break;
			case 8:
			case 14:
				draw_floor_map_row();
				break;
			case 10:
				draw_layer_b_row();
				break;
			case 12:
				draw_layer_a_row();
				break;
			}
			layer_columns_to_draw &= ~stack;
			if (draw_all_layer_edges == 0u)
				break;
		}
		stack = stack >> 1;
		t1 = stack_2;
		stack_2 = t1 - 1u;
	} while (t1 != 1u);
	stack = 4u;
	stack_2 = 3u;
	do
	{
		if ((stack & layer_rows_to_draw) != 0u)
		{
			switch ((int8_t)(uint8_t)((uint32_t)stack_2 << 1))
			{
			case 0:
			case 6:
				draw_floor_map_row();
				break;
			case 2:
				draw_layer_b_row();
				break;
			case 4:
				draw_layer_a_row();
				break;
			case -8:
			case -2:
				draw_floor_map_column();
				break;
			case -6:
				draw_layer_b_column();
				break;
			case -4:
				draw_layer_a_column();
				break;
			}
			layer_rows_to_draw &= ~stack;
			if (draw_all_layer_edges == 0u)
				break;
		}
		stack = stack >> 1;
		t2 = stack_2;
		stack_2 = t2 - 1u;
	} while (t2 != 1u);
}

/* Fills the floor map's column at the floor layer's scroll x from its map's blocks. */
void draw_floor_map_column(void)
{
	uint16_t d = 0, ignored16 = 0, map_cell = 0;

	d = (uint32_t)camera_main_layer << 8;
	find_layer_column(&map_cell, &ignored16, &d);
	fill_floor_map_column(map_cell, (uint8_t)d);
}

/* Fills the floor map's row at the floor layer's scroll y from its map's blocks. */
void draw_floor_map_row(void)
{
	uint16_t d = 0, ignored16 = 0, map_cell = 0;

	d = (uint32_t)camera_main_layer << 8;
	find_layer_row(&map_cell, &ignored16, &d);
	fill_floor_map_row(map_cell, (uint8_t)d);
}

/* Draws layer A's column of tiles at its scroll x from its map. */
void draw_layer_a_column(void)
{
	uint16_t d = 0, map_cell = 0, tile_place = 0;

	d = 0u;
	find_layer_column(&map_cell, &tile_place, &d);
	draw_map_column((uint8_t)d, &map_cell, &tile_place);
}

/* Draws layer B's column of tiles at its scroll x from its map. */
void draw_layer_b_column(void)
{
	uint16_t d = 0, map_cell = 0, tile_place = 0;

	d = 0x100u;
	find_layer_column(&map_cell, &tile_place, &d);
	draw_map_column((uint8_t)d, &map_cell, &tile_place);
}

/* Draws layer A's row of tiles at its scroll y from its map. */
void draw_layer_a_row(void)
{
	uint16_t d = 0, map_cell = 0, tile_place = 0;

	d = 0u;
	find_layer_row(&map_cell, &tile_place, &d);
	draw_map_row(map_cell, tile_place, (uint8_t)d);
}

/* Draws layer B's row of tiles at its scroll y from its map. */
void draw_layer_b_row(void)
{
	uint16_t d = 0, map_cell = 0, tile_place = 0;

	d = 0x100u;
	find_layer_row(&map_cell, &tile_place, &d);
	draw_map_row(map_cell, tile_place, (uint8_t)d);
}

/* Draws a number of columns of a tile layer (0 A, 1 B) from its scroll x on, 8 pixels apart (38 for the
   whole screen), then puts its x offset back to 0 and the bank as it was. */
void draw_layer_columns(uint16_t layer_and_columns, uint16_t *p_layer_map, uint16_t *p_map_cell, uint16_t *p_tile_place)
{
	uint8_t layer = 0;
	uint16_t d = 0, layer_map = 0, map_cell = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0, saved_window_bank = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t3 = 0;
	uint16_t offset_x = 0, t1 = 0, t2 = 0, offset_x_2 = 0, offset_x_3 = 0;

	layer = (uint8_t)(layer_and_columns >> 8);
	stack = (uint8_t)layer_and_columns;
	stack_2 = layer;
	layer_map = layer_maps[layer & 0x7Fu];
	saved_window_bank = window_bank;
	do
	{
		stack_5 = layer_map >> 8;
		stack_4 = (uint8_t)layer_map;
		d = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &tile_place, &d);
		draw_map_column((uint8_t)d, &map_cell, &tile_place);
		layer_map = ((uint32_t)stack_5 << 8) | stack_4;
		offset_x = LAYER_MAP(layer_map)->offset_x;
		t1 = mem_read16(offset_x);
		t2 = t1 + 8u;
		offset_x_2 = LAYER_MAP(layer_map)->offset_x;
		mem_write16(offset_x_2, t2);
		t3 = stack;
		stack = t3 - 1u;
	} while (t3 != 1u);
	offset_x_3 = LAYER_MAP(layer_map)->offset_x;
	mem_write16(offset_x_3, 0u);
	window_bank = saved_window_bank;
	set_lines(window_bank);
	*p_layer_map = layer_map;
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
}

/* Draws a number of columns of a tile layer from its scroll x on and fills the floor map's same columns
   from its map, then puts its x offset back to 0. */
void draw_layer_columns_with_floor_map(uint16_t layer_and_columns, uint16_t *p_map_cell, uint16_t *p_tile_place)
{
	uint8_t layer = 0;
	uint16_t d = 0, layer_map = 0, map_cell = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t5 = 0;
	uint16_t offset_x = 0, offset_y = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;

	layer = (uint8_t)(layer_and_columns >> 8);
	stack = (uint8_t)layer_and_columns;
	stack_2 = layer;
	layer_map = layer_maps[layer & 0x7Fu];
	offset_x = LAYER_MAP(layer_map)->offset_x;
	mem_write16(offset_x, 0u);
	offset_y = LAYER_MAP(layer_map)->offset_y;
	mem_write16(offset_y, 0u);
	do
	{
		stack_4 = layer_map >> 8;
		stack_3 = (uint8_t)layer_map;
		d = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &tile_place, &d);
		draw_map_column((uint8_t)d, &map_cell, &tile_place);
		layer_map = ((uint32_t)stack_4 << 8) | stack_3;
		stack_4 = layer_map >> 8;
		stack_3 = (uint8_t)layer_map;
		d = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &tile_place, &d);
		map_cell = fill_floor_map_column(map_cell, (uint8_t)d);
		layer_map = ((uint32_t)stack_4 << 8) | stack_3;
		t1 = io_read16(layer_map + 0xAu);
		t2 = mem_read16(t1);
		t3 = t2 + 8u;
		t4 = io_read16(layer_map + 0xAu);
		mem_write16(t4, t3);
		t5 = stack;
		stack = t5 - 1u;
	} while (t5 != 1u);
	t6 = io_read16(layer_map + 0xAu);
	mem_write16(t6, 0u);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
}

/* Draws a picture of tiles (tile_pictures) into the tile RAM in its colour, or, with bit 7 of the
   number, blank tiles over its place. */
void draw_tile_picture(uint16_t picture_number)
{
	uint8_t colour = 0, number = 0, tile = 0;
	uint16_t picture = 0, place = 0, places = 0, tile_bytes = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t tile_picture_entry = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	number = (uint8_t)(picture_number >> 8);
	places = tile_pictures_ADDRESS;
	if ((int8_t)number < 0)
	{
		number = 0u;
		picture_blank++;
	}
	tile_picture_entry = TILE_PICTURE_ENTRY(places + (number & 0x7Fu) * 0x2u);
	window_bank = TILE_PICTURE_PLACE(tile_picture_entry)->bank;
	set_lines(window_bank);
	t1 = tile_picture_entry + 1u;
	place = TILE_PICTURE_PLACE(t1 - 0x1u)->tiles;
	picture = TILE_PICTURE_PLACE(t1 - 0x1u)->picture;
	t2 = picture;
	picture_width = TILE_PICTURE(t2)->width;
	t3 = t2 + 1u;
	picture_rows_left = TILE_PICTURE(t3 - 0x1u)->height;
	t4 = t3 + 1u;
	tile_bytes = t4 + 1u;
	picture_colour = TILE_PICTURE(t4 - 0x2u)->colour;
	do
	{
		picture_columns_left = picture_width;
		colour = picture_colour;
		do
		{
			mem_write8(place - 0x2000u, colour);
			t5 = tile_bytes;
			tile_bytes = t5 + 1u;
			tile = mem_read8(t5);
			if (picture_blank != 0u)
				tile = 1u;
			t6 = place;
			place = t6 + 1u;
			mem_write8(t6, tile);
			t7 = picture_columns_left;
			picture_columns_left = t7 - 1u;
		} while (t7 != 1u);
		place += (int8_t)(0x40u - picture_width);
		t8 = picture_rows_left;
		picture_rows_left = t8 - 1u;
	} while (t8 != 1u);
}

/* For a tile layer's column at its scroll x: its place in the tile RAM, the floor map's column, the
   map's cell at that x and the scroll y (the area's bank switched in and kept), and the tile's column in
   the block. */
void find_layer_column(uint16_t *p_map_cell, uint16_t *p_tile_place, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, layer = 0, scene_number = 0;
	uint16_t area_lists = 0, d_2 = 0, layer_map = 0, map_cell = 0, scene_area = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t8 = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, t1 = 0, offset_x = 0, t2 = 0, scroll_y = 0, t3 = 0, t4 = 0, t5 = 0, scroll_x_2 = 0, t6 = 0, offset_x_2 = 0, t7 = 0, maps = 0, maps_high = 0, scroll_x_3 = 0, t9 = 0, offset_x_3 = 0, t10 = 0, scroll_y_2 = 0, t11 = 0, offset_y2 = 0, t12 = 0, t13 = 0, scroll_x_4 = 0, t14 = 0, offset_x_4 = 0, t15 = 0;

	layer = (uint8_t)(d >> 8);
	map_layer = layer;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)layer << 1)) / 2];
	tile_place = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	t1 = mem_read16(scroll_x);
	offset_x = LAYER_MAP(layer_map)->offset_x;
	t2 = t1 + mem_read16(offset_x);
	carry = (t2 >> 8) & 1u;
	map_place_offset = ((uint8_t)(((uint8_t)t2 >> 1) | (carry << 7)) >> 1) >> 1;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	t3 = mem_read16(scroll_y);
	b = (uint8_t)t3;
	map_draw_scroll = ((uint32_t)(t3 >> 8) << 8) | b;
	t4 = 0x40u * ((((b & 0xE0u) >> 1) >> 1) >> 1);
	t5 = t4 + map_place_offset;
	tile_place += t5;
	scroll_x_2 = LAYER_MAP(layer_map)->scroll_x;
	t6 = mem_read16(scroll_x_2);
	offset_x_2 = LAYER_MAP(layer_map)->offset_x;
	t7 = t6 + mem_read16(offset_x_2);
	carry = (t7 >> 8) & 1u;
	floor_map_place = floor_map_ADDRESS + (((uint8_t)(((uint8_t)t7 >> 1) | (carry << 7)) >> 1) >> 1);
	maps = LAYER_MAP(layer_map)->maps;
	area_lists = maps;
	t8 = map_scene;
	scene_number = t8;
	if ((int8_t)t8 < 0)
	{
		maps_high = LAYER_MAP(layer_map)->maps_high;
		area_lists = maps_high;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(area_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	map_bank = bank;
	bank_2 = SCENE_AREA(scene_area)->bank;
	window_bank = bank_2;
	set_lines(window_bank);
	scroll_x_3 = LAYER_MAP(layer_map)->scroll_x;
	t9 = mem_read16(scroll_x_3);
	offset_x_3 = LAYER_MAP(layer_map)->offset_x;
	t10 = t9 + mem_read16(offset_x_3);
	map_cell = mem_read16(SCENE_AREA(scene_area)->address + (int8_t)((uint32_t)(t10 >> 8) << 1));
	b = (((((uint8_t)t10 >> 1) >> 1) >> 1) >> 1) & 0xEu;
	map_place_offset = b;
	stack_2 = map_cell >> 8;
	stack = (uint8_t)map_cell;
	map_column_cell = map_cell + b;
	scroll_y_2 = LAYER_MAP(layer_map)->scroll_y;
	t11 = mem_read16(scroll_y_2);
	a = (uint8_t)(t11 >> 8);
	b = (uint8_t)t11;
	map_draw_scroll = ((uint32_t)a << 8) | b;
	offset_y2 = LAYER_MAP(layer_map)->offset_y2;
	t12 = (((uint32_t)a << 8) | b) + mem_read16(offset_y2);
	a = (uint8_t)(t12 >> 8);
	carry = a & 1u;
	t13 = (((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | ((((uint8_t)t12 >> 1) | (carry << 7)) & 0xF0u)) + map_place_offset;
	map_cell = (((uint32_t)stack_2 << 8) | stack) + t13;
	scroll_x_4 = LAYER_MAP(layer_map)->scroll_x;
	t14 = mem_read16(scroll_x_4);
	offset_x_4 = LAYER_MAP(layer_map)->offset_x;
	t15 = t14 + mem_read16(offset_x_4);
	d_2 = ((uint32_t)(t15 >> 8) << 8) | (((((uint8_t)t15 >> 1) >> 1) >> 1) & 3u);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
	*p_d = d_2;
}

/* For a tile layer's row at its scroll y: its place in the tile RAM, the floor map's row, the map's cell
   at that y and the scroll x (the area's bank switched in and kept), the step to the next strip, and the
   tile's row in the block. */
void find_layer_row(uint16_t *p_map_cell, uint16_t *p_tile_place, uint16_t *p_d)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, layer = 0, scene_number = 0;
	uint16_t address = 0, area_lists = 0, d_2 = 0, layer_map = 0, map_cell = 0, scene_area = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t4 = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, t1 = 0, scroll_y = 0, offset_y = 0, t2 = 0, t3 = 0, maps = 0, maps_high = 0, scroll_x_2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, scroll_y_2 = 0, t9 = 0, offset_y_2 = 0, t10 = 0, offset_y2 = 0, t11 = 0, t12 = 0, scroll_y_3 = 0, t13 = 0, offset_y_3 = 0, t14 = 0, offset_y2_2 = 0, t15 = 0;

	layer = (uint8_t)(d >> 8);
	map_layer = layer;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)layer << 1)) / 2];
	tile_place = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	t1 = mem_read16(scroll_x);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	map_draw_scroll = ((uint32_t)a << 8) | b;
	carry = a & 1u;
	map_place_offset = ((uint8_t)(((b & 0xE0u) >> 1) | (carry << 7)) >> 1) >> 1;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	offset_y = LAYER_MAP(layer_map)->offset_y;
	t2 = 0x40u * ((((uint8_t)((uint8_t)mem_read16(scroll_y) + mem_read16(offset_y)) >> 1) >> 1) >> 1);
	t3 = t2 + map_place_offset;
	a = (uint8_t)(t3 >> 8);
	b = (uint8_t)t3;
	tile_place += ((uint32_t)a << 8) | b;
	floor_map_place = floor_map_ADDRESS + (((uint32_t)a << 8) | b);
	maps = LAYER_MAP(layer_map)->maps;
	area_lists = maps;
	t4 = map_scene;
	scene_number = t4;
	if ((int8_t)t4 < 0)
	{
		maps_high = LAYER_MAP(layer_map)->maps_high;
		area_lists = maps_high;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(area_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	map_bank = bank;
	bank_2 = SCENE_AREA(scene_area)->bank;
	window_bank = bank_2;
	set_lines(window_bank);
	address = SCENE_AREA(scene_area)->address;
	scroll_x_2 = LAYER_MAP(layer_map)->scroll_x;
	t5 = mem_read16(scroll_x_2);
	a = (uint32_t)(t5 >> 8) << 1;
	stack_2 = layer_map >> 8;
	stack = (uint8_t)layer_map;
	stack_3 = t5;
	stack_4 = a;
	map_strip_step = mem_read16(address + (int8_t)a);
	t6 = mem_read16(address + (int8_t)(a + 2u));
	t7 = t6 - map_strip_step;
	t8 = t7 - 0x10u;
	map_strip_step = t8;
	layer_map = ((uint32_t)stack_2 << 8) | stack;
	map_cell = mem_read16(address + (int8_t)stack_4);
	map_place_offset = ((((stack_3 >> 1) >> 1) >> 1) >> 1) & 0xEu;
	scroll_y_2 = LAYER_MAP(layer_map)->scroll_y;
	t9 = mem_read16(scroll_y_2);
	offset_y_2 = LAYER_MAP(layer_map)->offset_y;
	t10 = t9 + mem_read16(offset_y_2);
	offset_y2 = LAYER_MAP(layer_map)->offset_y2;
	t11 = t10 + mem_read16(offset_y2);
	a = (uint8_t)(t11 >> 8);
	carry = a & 1u;
	t12 = (((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | ((((uint8_t)t11 >> 1) | (carry << 7)) & 0xF0u)) + map_place_offset;
	map_cell += t12;
	scroll_y_3 = LAYER_MAP(layer_map)->scroll_y;
	t13 = mem_read16(scroll_y_3);
	offset_y_3 = LAYER_MAP(layer_map)->offset_y;
	t14 = t13 + mem_read16(offset_y_3);
	offset_y2_2 = LAYER_MAP(layer_map)->offset_y2;
	t15 = t14 + mem_read16(offset_y2_2);
	d_2 = ((uint32_t)(t15 >> 8) << 8) | (((uint8_t)t15 >> 1) & 0xCu);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
	*p_d = d_2;
}

/* Draws a column of a map block's 4 x 4 tiles down the tile RAM, with the block's colour. */
uint16_t draw_block_column(uint16_t block, uint16_t tile_place, uint16_t block_column)
{
	uint8_t colour = 0, tile = 0;
	uint16_t tile_cell = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	block_cells_left = 4u;
	t1 = block;
	colour = mem_read8(t1);
	tile_cell = t1 + 2u + (int8_t)(block_column >> 8);
	do
	{
		tile = mem_read8(tile_cell);
		mem_write8(tile_place - 0x2000u, colour);
		mem_write8(tile_place, tile);
		tile_cell += 4u;
		tile_place += 0x40u;
		t2 = block_cells_left;
		block_cells_left = t2 - 1u;
	} while (t2 != 1u);
	return tile_place;
}

/* Draws a row of a map block's 4 x 4 tiles across the tile RAM, with the block's colour. */
uint16_t draw_block_row(uint16_t block, uint16_t tile_place, uint16_t block_row)
{
	uint8_t colour = 0, tile = 0;
	uint16_t tile_cell = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	block_cells_left = 4u;
	t1 = block;
	colour = mem_read8(t1);
	tile_cell = t1 + 2u + (int8_t)(block_row >> 8);
	do
	{
		t2 = tile_cell;
		tile_cell = t2 + 1u;
		tile = mem_read8(t2);
		mem_write8(tile_place - 0x2000u, colour);
		t3 = tile_place;
		tile_place = t3 + 1u;
		mem_write8(t3, tile);
		t4 = block_cells_left;
		block_cells_left = t4 - 1u;
	} while (t4 != 1u);
	return tile_place;
}

/* Copies a column of a map block's floor pattern (block_tile_flags) down the floor map, keeping the
   column in floor_pattern_offset. */
uint16_t copy_block_floor_column(uint16_t block, uint16_t floor_place, uint16_t block_column)
{
	uint16_t pattern_cell = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	floor_pattern_offset = block_column >> 8;
	t1 = mem_read8(block + 1u);
	floor_pattern = t1;
	t2 = floor_pattern * 0x10u;
	pattern_cell = block_tile_flags_ADDRESS + t2 + (int8_t)floor_pattern_offset;
	block_cells_left = 4u;
	do
	{
		mem_write8(floor_place, mem_read8(pattern_cell));
		pattern_cell += 4u;
		floor_place += 0x40u;
		t3 = block_cells_left;
		block_cells_left = t3 - 1u;
	} while (t3 != 1u);
	return floor_place;
}

/* Copies 4 cells of a map block's floor pattern across the floor map, from the offset the last column
   copy left in floor_pattern_offset (not the row its caller asks for). */
uint16_t copy_block_floor_row(uint16_t block, uint16_t floor_place)
{
	uint16_t pattern_cell = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(block + 1u);
	floor_pattern = t1;
	t2 = floor_pattern * 0x10u;
	pattern_cell = block_tile_flags_ADDRESS + t2 + (int8_t)floor_pattern_offset;
	block_cells_left = 4u;
	do
	{
		t3 = pattern_cell;
		pattern_cell = t3 + 1u;
		t4 = floor_place;
		floor_place = t4 + 1u;
		mem_write8(t4, mem_read8(t3));
		t5 = block_cells_left;
		block_cells_left = t5 - 1u;
	} while (t5 != 1u);
	return floor_place;
}

/* Draws a column of 8 map blocks (256 pixels) of tiles down the tile RAM from the map's cells, wrapping
   at the tile RAM's bottom. */
void draw_map_column(uint8_t block_column, uint16_t *p_map_cell, uint16_t *p_tile_place)
{
	uint16_t map_cell = (uint16_t)*p_map_cell;
	uint16_t tile_place = (uint16_t)*p_tile_place;
	uint8_t b = 0, wrapped = 0;
	uint16_t block_number = 0, d = 0, x = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	block_tile_column = block_column;
	map_column_blocks_left = 8u;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		t1 = mem_read16(map_cell);
		column_map_cell = map_cell;
		block_number = (((t1 >> 8) & 3u) << 8) | (uint8_t)t1;
		x = find_map_block(block_number);
		d = (block_number & 0xFFu) | ((uint32_t)block_tile_column << 8);
		tile_place = draw_block_column(x, tile_place, d);
		t2 = map_draw_scroll;
		t3 = t2 + 0x20u;
		b = (uint8_t)t3;
		wrapped = (t3 >> 8) ^ (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 1u) != 0u)
			tile_place -= 0x800u;
		map_draw_scroll = ((uint32_t)wrapped << 8) | b;
		map_cell = column_map_cell + 0x10u;
		t4 = map_column_blocks_left;
		map_column_blocks_left = t4 - 1u;
	} while (t4 != 1u);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
}

/* Fills a column of the floor map from 8 map blocks' floor patterns (256 pixels), wrapping at its 32nd
   row, with the board's sprite RAM view switched in meanwhile. */
uint16_t fill_floor_map_column(uint16_t map_cell, uint8_t block_column)
{
	uint8_t b = 0, control = 0, wrapped = 0;
	uint16_t block_number = 0, d = 0, floor_place = 0, x = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	block_tile_column = block_column;
	map_column_blocks_left = 8u;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		t1 = mem_read16(map_cell);
		column_map_cell = map_cell;
		block_number = t1;
		x = find_map_block(block_number);
		floor_place = floor_map_place;
		d = (block_number & 0xFFu) | ((uint32_t)block_tile_column << 8);
		floor_place = copy_block_floor_column(x, floor_place, d);
		t2 = map_draw_scroll;
		t3 = t2 + 0x20u;
		b = (uint8_t)t3;
		wrapped = (t3 >> 8) ^ (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 1u) != 0u)
			floor_place -= 0x800u;
		map_draw_scroll = ((uint32_t)wrapped << 8) | b;
		floor_map_place = floor_place;
		map_cell = column_map_cell + 0x10u;
		t4 = map_column_blocks_left;
		map_column_blocks_left = t4 - 1u;
	} while (t4 != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
	return map_cell;
}

/* Draws a row of 12 map blocks of tiles across the tile RAM from the map's cells, wrapping at its right
   edge and going on into the next strip of the map. */
void draw_map_row(uint16_t map_cell, uint16_t tile_place, uint8_t block_row)
{
	uint8_t wrapped = 0;
	uint16_t block_number = 0, d = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	block_tile_row = block_row;
	map_row_blocks_left = 0xCu;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		t1 = map_cell;
		map_cell = t1 + 2u;
		t2 = mem_read16(t1);
		stack_2 = map_cell >> 8;
		stack = (uint8_t)map_cell;
		block_number = (((t2 >> 8) & 3u) << 8) | (uint8_t)t2;
		x = find_map_block(block_number);
		d = (block_number & 0xFFu) | ((uint32_t)block_tile_row << 8);
		tile_place = draw_block_row(x, tile_place, d);
		t3 = map_draw_scroll;
		t4 = t3 + 0x20u;
		wrapped = (uint8_t)(t4 >> 8);
		map_next_scroll = ((uint32_t)wrapped << 8) | (uint8_t)t4;
		wrapped ^= (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 2u) != 0u)
			tile_place -= 0x40u;
		map_cell = ((uint32_t)stack_2 << 8) | stack;
		if ((wrapped & 1u) != 0u)
		{
			t5 = map_strip_step;
			map_cell += t5;
		}
		t6 = map_next_scroll;
		map_draw_scroll = t6;
		t7 = map_row_blocks_left;
		map_row_blocks_left = t7 - 1u;
	} while (t7 != 1u);
}

/* Fills a row of the floor map from 11 map blocks' floor patterns, wrapping at its right edge and going
   on into the next strip of the map. */
void fill_floor_map_row(uint16_t map_cell, uint8_t block_row)
{
	uint8_t control = 0, wrapped = 0;
	uint16_t block_number = 0, floor_place = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	block_tile_row = block_row;
	map_row_blocks_left = 0xBu;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		t1 = map_cell;
		map_cell = t1 + 2u;
		t2 = mem_read16(t1);
		stack_2 = map_cell >> 8;
		stack = (uint8_t)map_cell;
		block_number = t2;
		x = find_map_block(block_number);
		floor_place = floor_map_place;
		floor_place = copy_block_floor_row(x, floor_place);
		t3 = map_draw_scroll;
		t4 = t3 + 0x20u;
		wrapped = (uint8_t)(t4 >> 8);
		map_next_scroll = ((uint32_t)wrapped << 8) | (uint8_t)t4;
		wrapped ^= (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 2u) != 0u)
			floor_place -= 0x40u;
		floor_map_place = floor_place;
		map_cell = ((uint32_t)stack_2 << 8) | stack;
		if ((wrapped & 1u) != 0u)
		{
			t5 = map_strip_step;
			map_cell += t5;
		}
		t6 = map_next_scroll;
		map_draw_scroll = t6;
		t7 = map_row_blocks_left;
		map_row_blocks_left = t7 - 1u;
	} while (t7 != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
}

/* The address of a map block by its number, in the block array of the layer the map is being drawn for
   (its bank switched in). */
uint16_t find_map_block(uint16_t block_number)
{
	map_block = block_number;
	switch ((int8_t)(uint8_t)((uint32_t)map_layer << 1))
	{
	case 0:
		return find_layer_a_block();
	case 2:
		return find_layer_b_block();
	}
	unreachable();
}

/* The address of one of layer A's map blocks (18 bytes each) in the scene's area's block array
   (block_scenes_a), its bank switched in. */
uint16_t find_layer_a_block(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, scene_number = 0;
	uint16_t address = 0, block = 0, scene_area = 0, scene_lists = 0;
	uint8_t t1 = 0, bank = 0;
	uint16_t t2 = 0, t3 = 0;

	scene_lists = block_scenes_a_ADDRESS;
	t1 = map_scene;
	scene_number = t1;
	if ((int8_t)t1 < 0)
	{
		scene_lists = block_scenes_a_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	window_bank = bank;
	set_lines(window_bank);
	address = SCENE_AREA(scene_area)->address;
	t2 = map_block;
	b = (uint8_t)t2;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(t2 >> 8) << 1) | carry);
	map_block = ((uint32_t)a << 8) | b;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t3 = (((uint32_t)(uint8_t)(((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1)) + map_block;
	block = address + t3;
	return block;
}

/* The address of one of layer B's map blocks (18 bytes each) in the scene's area's block array
   (block_scenes_b), its bank switched in. */
uint16_t find_layer_b_block(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, scene_number = 0;
	uint16_t address = 0, block = 0, scene_area = 0, scene_lists = 0;
	uint8_t t1 = 0, bank = 0;
	uint16_t t2 = 0, t3 = 0;

	scene_lists = block_scenes_b_ADDRESS;
	t1 = map_scene;
	scene_number = t1;
	if ((int8_t)t1 < 0)
	{
		scene_lists = block_scenes_b_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	window_bank = bank;
	set_lines(window_bank);
	address = SCENE_AREA(scene_area)->address;
	t2 = map_block;
	b = (uint8_t)t2;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)(t2 >> 8) << 1) | carry);
	map_block = ((uint32_t)a << 8) | b;
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	b = (uint32_t)b << 1;
	a = (uint8_t)(((uint32_t)a << 1) | carry);
	carry = (int8_t)b < 0;
	t3 = (((uint32_t)(uint8_t)(((uint32_t)a << 1) | carry) << 8) | (uint8_t)((uint32_t)b << 1)) + map_block;
	block = address + t3;
	return block;
}

/* Sets the K052109's tile ROM banks for the map's scene and area (layer_modes). */
void set_area_tile_banks(void)
{
	uint8_t scene_number = 0, tile_banks = 0;
	uint16_t mode_lists = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	mode_lists = layer_modes_ADDRESS;
	t1 = map_scene;
	scene_number = t1;
	if ((int8_t)t1 < 0)
	{
		mode_lists = layer_modes_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	t2 = LAYER_MODE_LIST(mode_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)((uint32_t)map_area << 1);
	io_write8(0x1D80u, LAYER_MODE(t2)->tile_banks_01);
	tile_banks = LAYER_MODE(t2)->tile_banks_23;
	io_write8(0x1F00u, tile_banks);
}
