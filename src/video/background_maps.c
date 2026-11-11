/**
 *    Name:        video/background_maps.c
 *    Description: the tile layers' maps: the edges drawn as they scroll, whole layers, the floor map, tile pictures, the tile banks
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    10-11-2026
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
	uint8_t column_layers_left = 0, row_layers_left = 0;

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
		column_layers_left = stack_2;
		stack_2 = column_layers_left - 1u;
	} while (column_layers_left != 1u);
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
		row_layers_left = stack_2;
		stack_2 = row_layers_left - 1u;
	} while (row_layers_left != 1u);
}

/* Fills the floor map's column at the floor layer's scroll x from its map's blocks. */
void draw_floor_map_column(void)
{
	uint16_t ignored16 = 0, layer_and_block_column = 0, map_cell = 0;

	layer_and_block_column = (uint32_t)camera_main_layer << 8;
	find_layer_column(&map_cell, &ignored16, &layer_and_block_column);
	leftover_y = map_cell;
	fill_floor_map_column((uint8_t)layer_and_block_column);
}

/* Fills the floor map's row at the floor layer's scroll y from its map's blocks. */
void draw_floor_map_row(void)
{
	uint16_t ignored16 = 0, layer_and_block_row = 0, map_cell = 0;

	layer_and_block_row = (uint32_t)camera_main_layer << 8;
	find_layer_row(&map_cell, &ignored16, &layer_and_block_row);
	fill_floor_map_row(map_cell, (uint8_t)layer_and_block_row);
}

/* Draws layer A's column of tiles at its scroll x from its map. */
void draw_layer_a_column(void)
{
	uint16_t layer_and_block_column = 0, map_cell = 0, tile_place = 0;

	layer_and_block_column = 0u;
	find_layer_column(&map_cell, &tile_place, &layer_and_block_column);
	leftover_y = map_cell;
	draw_map_column(tile_place, (uint8_t)layer_and_block_column);
}

/* Draws layer B's column of tiles at its scroll x from its map. */
void draw_layer_b_column(void)
{
	uint16_t layer_and_block_column = 0, map_cell = 0, tile_place = 0;

	layer_and_block_column = 0x100u;
	find_layer_column(&map_cell, &tile_place, &layer_and_block_column);
	leftover_y = map_cell;
	draw_map_column(tile_place, (uint8_t)layer_and_block_column);
}

/* Draws layer A's row of tiles at its scroll y from its map. */
void draw_layer_a_row(void)
{
	uint16_t layer_and_block_row = 0, map_cell = 0, tile_place = 0;

	layer_and_block_row = 0u;
	find_layer_row(&map_cell, &tile_place, &layer_and_block_row);
	draw_map_row(map_cell, tile_place, (uint8_t)layer_and_block_row);
}

/* Draws layer B's row of tiles at its scroll y from its map. */
void draw_layer_b_row(void)
{
	uint16_t layer_and_block_row = 0, map_cell = 0, tile_place = 0;

	layer_and_block_row = 0x100u;
	find_layer_row(&map_cell, &tile_place, &layer_and_block_row);
	draw_map_row(map_cell, tile_place, (uint8_t)layer_and_block_row);
}

/* Draws a number of columns of a tile layer (0 A, 1 B) from its scroll x on, 8 pixels apart (38 for the
   whole screen), then puts its x offset back to 0 and the bank as it was. */
void draw_layer_columns(uint16_t layer_and_columns, uint16_t *p_layer_map, uint16_t *p_tile_place)
{
	uint8_t layer = 0;
	uint16_t layer_and_block_column = 0, layer_map = 0, map_cell = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0, saved_window_bank = 0, stack_4 = 0, stack_5 = 0;
	uint8_t columns_left_before = 0;
	uint16_t offset_x = 0, layer_offset_x = 0, next_offset_x = 0, offset_x_2 = 0, offset_x_3 = 0;

	layer = (uint8_t)(layer_and_columns >> 8);
	stack = (uint8_t)layer_and_columns;
	stack_2 = layer;
	layer_map = layer_maps[layer & 0x7Fu];
	saved_window_bank = window_bank;
	do
	{
		stack_5 = layer_map >> 8;
		stack_4 = (uint8_t)layer_map;
		layer_and_block_column = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &tile_place, &layer_and_block_column);
		leftover_y = map_cell;
		tile_place = draw_map_column(tile_place, (uint8_t)layer_and_block_column);
		layer_map = ((uint32_t)stack_5 << 8) | stack_4;
		offset_x = LAYER_MAP(layer_map)->offset_x;
		layer_offset_x = mem_read16(offset_x);
		next_offset_x = layer_offset_x + 8u;
		offset_x_2 = LAYER_MAP(layer_map)->offset_x;
		mem_write16(offset_x_2, next_offset_x);
		columns_left_before = stack;
		stack = columns_left_before - 1u;
	} while (columns_left_before != 1u);
	offset_x_3 = LAYER_MAP(layer_map)->offset_x;
	mem_write16(offset_x_3, 0u);
	window_bank = saved_window_bank;
	set_lines(window_bank);
	*p_layer_map = layer_map;
	*p_tile_place = tile_place;
}

/* Draws a number of columns of a tile layer from its scroll x on and fills the floor map's same columns
   from its map, then puts its x offset back to 0. */
uint16_t draw_layer_columns_with_floor_map(uint16_t layer_and_columns)
{
	uint8_t layer = 0;
	uint16_t layer_and_block_column = 0, layer_map = 0, map_cell = 0, tile_place = 0, u = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t columns_left_before = 0;
	uint16_t offset_x = 0, offset_y = 0, layer_offset_x_at = 0, layer_offset_x = 0, next_offset_x = 0, layer_offset_x_to = 0, cleared_offset_x_at = 0;

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
		layer_and_block_column = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &tile_place, &layer_and_block_column);
		leftover_y = map_cell;
		draw_map_column(tile_place, (uint8_t)layer_and_block_column);
		layer_map = ((uint32_t)stack_4 << 8) | stack_3;
		stack_4 = layer_map >> 8;
		stack_3 = (uint8_t)layer_map;
		layer_and_block_column = (uint32_t)stack_2 << 8;
		find_layer_column(&map_cell, &u, &layer_and_block_column);
		leftover_y = map_cell;
		fill_floor_map_column((uint8_t)layer_and_block_column);
		layer_map = ((uint32_t)stack_4 << 8) | stack_3;
		layer_offset_x_at = LAYER_MAP(layer_map)->offset_x;
		layer_offset_x = mem_read16(layer_offset_x_at);
		next_offset_x = layer_offset_x + 8u;
		layer_offset_x_to = LAYER_MAP(layer_map)->offset_x;
		mem_write16(layer_offset_x_to, next_offset_x);
		columns_left_before = stack;
		stack = columns_left_before - 1u;
	} while (columns_left_before != 1u);
	cleared_offset_x_at = LAYER_MAP(layer_map)->offset_x;
	mem_write16(cleared_offset_x_at, 0u);
	return u;
}

/* Draws a picture of tiles (tile_pictures) into the tile RAM in its colour, or, with bit 7 of the
   number, blank tiles over its place. */
void draw_tile_picture(uint16_t picture_number)
{
	uint8_t colour = 0, number = 0, tile = 0;
	uint16_t picture = 0, place = 0, places = 0, tile_bytes = 0;
	uint8_t columns_left_before = 0, rows_left_before = 0;
	uint16_t tile_picture_entry = 0, place_at = 0, width_at = 0, height_at = 0, colour_at = 0, tile_at = 0, written_place = 0;

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
	place_at = tile_picture_entry + 1u;
	place = TILE_PICTURE_PLACE(place_at - 0x1u)->tiles;
	picture = TILE_PICTURE_PLACE(place_at - 0x1u)->picture;
	width_at = picture;
	picture_width = TILE_PICTURE(width_at)->width;
	height_at = width_at + 1u;
	picture_rows_left = TILE_PICTURE(height_at - 0x1u)->height;
	colour_at = height_at + 1u;
	tile_bytes = colour_at + 1u;
	picture_colour = TILE_PICTURE(colour_at - 0x2u)->colour;
	do
	{
		picture_columns_left = picture_width;
		colour = picture_colour;
		do
		{
			mem_write8(place - 0x2000u, colour);
			tile_at = tile_bytes;
			tile_bytes = tile_at + 1u;
			tile = mem_read8(tile_at);
			if (picture_blank != 0u)
				tile = 1u;
			written_place = place;
			place = written_place + 1u;
			mem_write8(written_place, tile);
			columns_left_before = picture_columns_left;
			picture_columns_left = columns_left_before - 1u;
		} while (columns_left_before != 1u);
		place += (int8_t)(0x40u - picture_width);
		rows_left_before = picture_rows_left;
		picture_rows_left = rows_left_before - 1u;
	} while (rows_left_before != 1u);
}

/* For a tile layer's column at its scroll x: its place in the tile RAM, the floor map's column, the
   map's cell at that x and the scroll y (the area's bank switched in and kept), and the tile's column in
   the block. */
void find_layer_column(uint16_t *p_map_cell, uint16_t *p_tile_place, uint16_t *p_strip_and_block_column)
{
	uint16_t strip_and_block_column = (uint16_t)*p_strip_and_block_column;
	uint32_t carry = 0;
	uint8_t b = 0, edge_y_high = 0, layer = 0, scene_number = 0;
	uint16_t area_lists = 0, layer_map = 0, map_cell = 0, scene_area = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t scene_byte = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, tile_scroll_x = 0, offset_x = 0, tile_edge_x = 0, scroll_y = 0, tile_scroll_y = 0, row_offset = 0, tile_offset = 0, scroll_x_2 = 0, floor_scroll_x = 0, offset_x_2 = 0, floor_edge_x = 0, maps = 0, maps_high = 0, scroll_x_3 = 0, map_scroll_x = 0, offset_x_3 = 0, map_edge_x = 0, scroll_y_2 = 0, map_scroll_y = 0, offset_y2 = 0, map_edge_y = 0, cell_offset = 0, scroll_x_4 = 0, column_scroll_x = 0, offset_x_4 = 0, column_edge_x = 0;

	layer = (uint8_t)(strip_and_block_column >> 8);
	map_layer = layer;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)layer << 1)) / 2];
	tile_place = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	tile_scroll_x = mem_read16(scroll_x);
	offset_x = LAYER_MAP(layer_map)->offset_x;
	tile_edge_x = tile_scroll_x + mem_read16(offset_x);
	carry = (tile_edge_x >> 8) & 1u;
	map_place_offset = ((uint8_t)(((uint8_t)tile_edge_x >> 1) | (carry << 7)) >> 1) >> 1;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	tile_scroll_y = mem_read16(scroll_y);
	b = (uint8_t)tile_scroll_y;
	map_draw_scroll = ((uint32_t)(tile_scroll_y >> 8) << 8) | b;
	row_offset = 0x40u * ((((b & 0xE0u) >> 1) >> 1) >> 1);
	tile_offset = row_offset + map_place_offset;
	tile_place += tile_offset;
	scroll_x_2 = LAYER_MAP(layer_map)->scroll_x;
	floor_scroll_x = mem_read16(scroll_x_2);
	offset_x_2 = LAYER_MAP(layer_map)->offset_x;
	floor_edge_x = floor_scroll_x + mem_read16(offset_x_2);
	carry = (floor_edge_x >> 8) & 1u;
	floor_map_place = floor_map_ADDRESS + (((uint8_t)(((uint8_t)floor_edge_x >> 1) | (carry << 7)) >> 1) >> 1);
	maps = LAYER_MAP(layer_map)->maps;
	area_lists = maps;
	scene_byte = map_scene;
	scene_number = scene_byte;
	if ((int8_t)scene_byte < 0)
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
	map_scroll_x = mem_read16(scroll_x_3);
	offset_x_3 = LAYER_MAP(layer_map)->offset_x;
	map_edge_x = map_scroll_x + mem_read16(offset_x_3);
	map_cell = mem_read16(SCENE_AREA(scene_area)->address + (int8_t)((uint32_t)(map_edge_x >> 8) << 1));
	b = (((((uint8_t)map_edge_x >> 1) >> 1) >> 1) >> 1) & 0xEu;
	map_place_offset = b;
	stack_2 = map_cell >> 8;
	stack = (uint8_t)map_cell;
	map_column_cell = map_cell + b;
	scroll_y_2 = LAYER_MAP(layer_map)->scroll_y;
	map_scroll_y = mem_read16(scroll_y_2);
	edge_y_high = (uint8_t)(map_scroll_y >> 8);
	b = (uint8_t)map_scroll_y;
	map_draw_scroll = ((uint32_t)edge_y_high << 8) | b;
	offset_y2 = LAYER_MAP(layer_map)->offset_y2;
	map_edge_y = (((uint32_t)edge_y_high << 8) | b) + mem_read16(offset_y2);
	edge_y_high = (uint8_t)(map_edge_y >> 8);
	carry = edge_y_high & 1u;
	cell_offset = (((uint32_t)(uint8_t)((int8_t)edge_y_high >> 1) << 8) | ((((uint8_t)map_edge_y >> 1) | (carry << 7)) & 0xF0u)) + map_place_offset;
	map_cell = (((uint32_t)stack_2 << 8) | stack) + cell_offset;
	scroll_x_4 = LAYER_MAP(layer_map)->scroll_x;
	column_scroll_x = mem_read16(scroll_x_4);
	offset_x_4 = LAYER_MAP(layer_map)->offset_x;
	column_edge_x = column_scroll_x + mem_read16(offset_x_4);
	strip_and_block_column = ((uint32_t)(column_edge_x >> 8) << 8) | (((((uint8_t)column_edge_x >> 1) >> 1) >> 1) & 3u);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
	*p_strip_and_block_column = strip_and_block_column;
}

/* For a tile layer's row at its scroll y: its place in the tile RAM, the floor map's row, the map's cell
   at that y and the scroll x (the area's bank switched in and kept), the step to the next strip, and the
   tile's row in the block. */
void find_layer_row(uint16_t *p_map_cell, uint16_t *p_tile_place, uint16_t *p_strip_and_block_row)
{
	uint16_t strip_and_block_row = (uint16_t)*p_strip_and_block_row;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, layer = 0, scene_number = 0;
	uint16_t address = 0, area_lists = 0, layer_map = 0, map_cell = 0, scene_area = 0, tile_place = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t scene_byte = 0, bank = 0, bank_2 = 0;
	uint16_t scroll_x = 0, tile_scroll_x = 0, scroll_y = 0, offset_y = 0, row_offset = 0, tile_offset = 0, maps = 0, maps_high = 0, scroll_x_2 = 0, map_scroll_x = 0, next_strip = 0, strip_length = 0, strip_last_row = 0, scroll_y_2 = 0, map_scroll_y = 0, offset_y_2 = 0, map_view_y = 0, offset_y2 = 0, map_edge_y = 0, cell_offset = 0, scroll_y_3 = 0, row_scroll_y = 0, offset_y_3 = 0, row_view_y = 0, offset_y2_2 = 0, row_edge_y = 0;

	layer = (uint8_t)(strip_and_block_row >> 8);
	map_layer = layer;
	layer_map = layer_maps[(int8_t)((uint8_t)((uint32_t)layer << 1)) / 2];
	tile_place = LAYER_MAP(layer_map)->tiles;
	scroll_x = LAYER_MAP(layer_map)->scroll_x;
	tile_scroll_x = mem_read16(scroll_x);
	a = (uint8_t)(tile_scroll_x >> 8);
	b = (uint8_t)tile_scroll_x;
	map_draw_scroll = ((uint32_t)a << 8) | b;
	carry = a & 1u;
	map_place_offset = ((uint8_t)(((b & 0xE0u) >> 1) | (carry << 7)) >> 1) >> 1;
	scroll_y = LAYER_MAP(layer_map)->scroll_y;
	offset_y = LAYER_MAP(layer_map)->offset_y;
	row_offset = 0x40u * ((((uint8_t)((uint8_t)mem_read16(scroll_y) + mem_read16(offset_y)) >> 1) >> 1) >> 1);
	tile_offset = row_offset + map_place_offset;
	a = (uint8_t)(tile_offset >> 8);
	b = (uint8_t)tile_offset;
	tile_place += ((uint32_t)a << 8) | b;
	floor_map_place = floor_map_ADDRESS + (((uint32_t)a << 8) | b);
	maps = LAYER_MAP(layer_map)->maps;
	area_lists = maps;
	scene_byte = map_scene;
	scene_number = scene_byte;
	if ((int8_t)scene_byte < 0)
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
	map_scroll_x = mem_read16(scroll_x_2);
	a = (uint32_t)(map_scroll_x >> 8) << 1;
	stack_2 = layer_map >> 8;
	stack = (uint8_t)layer_map;
	stack_3 = map_scroll_x;
	stack_4 = a;
	map_strip_step = mem_read16(address + (int8_t)a);
	next_strip = mem_read16(address + (int8_t)(a + 2u));
	strip_length = next_strip - map_strip_step;
	strip_last_row = strip_length - 0x10u;
	map_strip_step = strip_last_row;
	layer_map = ((uint32_t)stack_2 << 8) | stack;
	map_cell = mem_read16(address + (int8_t)stack_4);
	map_place_offset = ((((stack_3 >> 1) >> 1) >> 1) >> 1) & 0xEu;
	scroll_y_2 = LAYER_MAP(layer_map)->scroll_y;
	map_scroll_y = mem_read16(scroll_y_2);
	offset_y_2 = LAYER_MAP(layer_map)->offset_y;
	map_view_y = map_scroll_y + mem_read16(offset_y_2);
	offset_y2 = LAYER_MAP(layer_map)->offset_y2;
	map_edge_y = map_view_y + mem_read16(offset_y2);
	a = (uint8_t)(map_edge_y >> 8);
	carry = a & 1u;
	cell_offset = (((uint32_t)(uint8_t)((int8_t)a >> 1) << 8) | ((((uint8_t)map_edge_y >> 1) | (carry << 7)) & 0xF0u)) + map_place_offset;
	map_cell += cell_offset;
	scroll_y_3 = LAYER_MAP(layer_map)->scroll_y;
	row_scroll_y = mem_read16(scroll_y_3);
	offset_y_3 = LAYER_MAP(layer_map)->offset_y;
	row_view_y = row_scroll_y + mem_read16(offset_y_3);
	offset_y2_2 = LAYER_MAP(layer_map)->offset_y2;
	row_edge_y = row_view_y + mem_read16(offset_y2_2);
	strip_and_block_row = ((uint32_t)(row_edge_y >> 8) << 8) | (((uint8_t)row_edge_y >> 1) & 0xCu);
	*p_map_cell = map_cell;
	*p_tile_place = tile_place;
	*p_strip_and_block_row = strip_and_block_row;
}

/* Draws a column of a map block's 4 x 4 tiles down the tile RAM, with the block's colour. */
uint16_t draw_block_column(uint16_t block, uint16_t tile_place, uint16_t block_column)
{
	uint8_t colour = 0, tile = 0;
	uint16_t tile_cell = 0;
	uint8_t cells_left_before = 0;
	uint16_t block_at = 0;

	block_cells_left = 4u;
	block_at = block;
	colour = mem_read8(block_at);
	tile_cell = block_at + 2u + (int8_t)(block_column >> 8);
	do
	{
		tile = mem_read8(tile_cell);
		mem_write8(tile_place - 0x2000u, colour);
		mem_write8(tile_place, tile);
		tile_cell += 4u;
		tile_place += 0x40u;
		cells_left_before = block_cells_left;
		block_cells_left = cells_left_before - 1u;
	} while (cells_left_before != 1u);
	return tile_place;
}

/* Draws a row of a map block's 4 x 4 tiles across the tile RAM, with the block's colour. */
uint16_t draw_block_row(uint16_t block, uint16_t tile_place, uint16_t block_row)
{
	uint8_t colour = 0, tile = 0;
	uint16_t tile_cell = 0;
	uint8_t cells_left_before = 0;
	uint16_t block_at = 0, tile_at = 0, written_place = 0;

	block_cells_left = 4u;
	block_at = block;
	colour = mem_read8(block_at);
	tile_cell = block_at + 2u + (int8_t)(block_row >> 8);
	do
	{
		tile_at = tile_cell;
		tile_cell = tile_at + 1u;
		tile = mem_read8(tile_at);
		mem_write8(tile_place - 0x2000u, colour);
		written_place = tile_place;
		tile_place = written_place + 1u;
		mem_write8(written_place, tile);
		cells_left_before = block_cells_left;
		block_cells_left = cells_left_before - 1u;
	} while (cells_left_before != 1u);
	return tile_place;
}

/* Copies a column of a map block's floor pattern (block_tile_flags) down the floor map, keeping the
   column in floor_pattern_offset. */
uint16_t copy_block_floor_column(uint16_t block, uint16_t floor_place, uint16_t block_column)
{
	uint16_t pattern_cell = 0;
	uint8_t block_floor_pattern = 0, cells_left_before = 0;
	uint16_t pattern_offset = 0;

	floor_pattern_offset = block_column >> 8;
	block_floor_pattern = mem_read8(block + 1u);
	floor_pattern = block_floor_pattern;
	pattern_offset = floor_pattern * 0x10u;
	pattern_cell = block_tile_flags_ADDRESS + pattern_offset + (int8_t)floor_pattern_offset;
	block_cells_left = 4u;
	do
	{
		mem_write8(floor_place, mem_read8(pattern_cell));
		pattern_cell += 4u;
		floor_place += 0x40u;
		cells_left_before = block_cells_left;
		block_cells_left = cells_left_before - 1u;
	} while (cells_left_before != 1u);
	return floor_place;
}

/* Copies 4 cells of a map block's floor pattern across the floor map, from the offset the last column
   copy left in floor_pattern_offset (not the row its caller asks for). */
uint16_t copy_block_floor_row(uint16_t block, uint16_t floor_place)
{
	uint16_t pattern_cell = 0;
	uint8_t block_floor_pattern = 0, cells_left_before = 0;
	uint16_t pattern_offset = 0, pattern_at = 0, written_place = 0;

	block_floor_pattern = mem_read8(block + 1u);
	floor_pattern = block_floor_pattern;
	pattern_offset = floor_pattern * 0x10u;
	pattern_cell = block_tile_flags_ADDRESS + pattern_offset + (int8_t)floor_pattern_offset;
	block_cells_left = 4u;
	do
	{
		pattern_at = pattern_cell;
		pattern_cell = pattern_at + 1u;
		written_place = floor_place;
		floor_place = written_place + 1u;
		mem_write8(written_place, mem_read8(pattern_at));
		cells_left_before = block_cells_left;
		block_cells_left = cells_left_before - 1u;
	} while (cells_left_before != 1u);
	return floor_place;
}

/* Draws a column of 8 map blocks (256 pixels) of tiles down the tile RAM from the map's cells, wrapping
   at the tile RAM's bottom. */
uint16_t draw_map_column(uint16_t tile_place, uint8_t block_column)
{
	uint8_t next_scroll_low = 0, wrapped = 0;
	uint16_t block = 0, block_number = 0, tile_column = 0;
	uint8_t blocks_left_before = 0;
	uint16_t map_word = 0, drawn_scroll = 0, next_scroll = 0;

	block_tile_column = block_column;
	map_column_blocks_left = 8u;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		map_word = mem_read16(leftover_y);
		column_map_cell = leftover_y;
		block_number = (((map_word >> 8) & 3u) << 8) | (uint8_t)map_word;
		block = find_map_block(block_number);
		tile_column = (block_number & 0xFFu) | ((uint32_t)block_tile_column << 8);
		tile_place = draw_block_column(block, tile_place, tile_column);
		drawn_scroll = map_draw_scroll;
		next_scroll = drawn_scroll + 0x20u;
		next_scroll_low = (uint8_t)next_scroll;
		wrapped = (next_scroll >> 8) ^ (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 1u) != 0u)
			tile_place -= 0x800u;
		map_draw_scroll = ((uint32_t)wrapped << 8) | next_scroll_low;
		leftover_y = column_map_cell + 0x10u;
		blocks_left_before = map_column_blocks_left;
		map_column_blocks_left = blocks_left_before - 1u;
	} while (blocks_left_before != 1u);
	return tile_place;
}

/* Fills a column of the floor map from 8 map blocks' floor patterns (256 pixels), wrapping at its 32nd
   row, with the board's sprite RAM view switched in meanwhile. */
void fill_floor_map_column(uint8_t block_column)
{
	uint8_t control = 0, next_scroll_low = 0, wrapped = 0;
	uint16_t block = 0, block_number = 0, floor_place = 0, tile_column = 0;
	uint8_t blocks_left_before = 0;
	uint16_t map_word = 0, drawn_scroll = 0, next_scroll = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	block_tile_column = block_column;
	map_column_blocks_left = 8u;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		map_word = mem_read16(leftover_y);
		column_map_cell = leftover_y;
		block_number = map_word;
		block = find_map_block(block_number);
		floor_place = floor_map_place;
		tile_column = (block_number & 0xFFu) | ((uint32_t)block_tile_column << 8);
		floor_place = copy_block_floor_column(block, floor_place, tile_column);
		drawn_scroll = map_draw_scroll;
		next_scroll = drawn_scroll + 0x20u;
		next_scroll_low = (uint8_t)next_scroll;
		wrapped = (next_scroll >> 8) ^ (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 1u) != 0u)
			floor_place -= 0x800u;
		map_draw_scroll = ((uint32_t)wrapped << 8) | next_scroll_low;
		floor_map_place = floor_place;
		leftover_y = column_map_cell + 0x10u;
		blocks_left_before = map_column_blocks_left;
		map_column_blocks_left = blocks_left_before - 1u;
	} while (blocks_left_before != 1u);
	control = board_control & ~3u;
	board_control = control;
	io_write8(0x1FC2u, control);
}

/* Draws a row of 12 map blocks of tiles across the tile RAM from the map's cells, wrapping at its right
   edge and going on into the next strip of the map. */
void draw_map_row(uint16_t map_cell, uint16_t tile_place, uint8_t block_row)
{
	uint8_t wrapped = 0;
	uint16_t block = 0, block_number = 0, tile_row = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t blocks_left_before = 0;
	uint16_t map_cell_at = 0, map_word = 0, drawn_scroll = 0, next_scroll = 0, strip_jump = 0, new_draw_scroll = 0;

	block_tile_row = block_row;
	map_row_blocks_left = 0xCu;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		map_cell_at = map_cell;
		map_cell = map_cell_at + 2u;
		map_word = mem_read16(map_cell_at);
		stack_2 = map_cell >> 8;
		stack = (uint8_t)map_cell;
		block_number = (((map_word >> 8) & 3u) << 8) | (uint8_t)map_word;
		block = find_map_block(block_number);
		tile_row = (block_number & 0xFFu) | ((uint32_t)block_tile_row << 8);
		tile_place = draw_block_row(block, tile_place, tile_row);
		drawn_scroll = map_draw_scroll;
		next_scroll = drawn_scroll + 0x20u;
		wrapped = (uint8_t)(next_scroll >> 8);
		map_next_scroll = ((uint32_t)wrapped << 8) | (uint8_t)next_scroll;
		wrapped ^= (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 2u) != 0u)
			tile_place -= 0x40u;
		map_cell = ((uint32_t)stack_2 << 8) | stack;
		if ((wrapped & 1u) != 0u)
		{
			strip_jump = map_strip_step;
			map_cell += strip_jump;
		}
		new_draw_scroll = map_next_scroll;
		map_draw_scroll = new_draw_scroll;
		blocks_left_before = map_row_blocks_left;
		map_row_blocks_left = blocks_left_before - 1u;
	} while (blocks_left_before != 1u);
}

/* Fills a row of the floor map from 11 map blocks' floor patterns, wrapping at its right edge and going
   on into the next strip of the map. */
void fill_floor_map_row(uint16_t map_cell, uint8_t block_row)
{
	uint8_t control = 0, wrapped = 0;
	uint16_t block = 0, block_number = 0, floor_place = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t blocks_left_before = 0;
	uint16_t map_cell_at = 0, map_word = 0, drawn_scroll = 0, next_scroll = 0, strip_jump = 0, new_draw_scroll = 0;

	control = board_control | 2u;
	board_control = control;
	io_write8(0x1FC2u, control);
	block_tile_row = block_row;
	map_row_blocks_left = 0xBu;
	do
	{
		window_bank = map_bank;
		set_lines(window_bank);
		map_cell_at = map_cell;
		map_cell = map_cell_at + 2u;
		map_word = mem_read16(map_cell_at);
		stack_2 = map_cell >> 8;
		stack = (uint8_t)map_cell;
		block_number = map_word;
		block = find_map_block(block_number);
		floor_place = floor_map_place;
		floor_place = copy_block_floor_row(block, floor_place);
		drawn_scroll = map_draw_scroll;
		next_scroll = drawn_scroll + 0x20u;
		wrapped = (uint8_t)(next_scroll >> 8);
		map_next_scroll = ((uint32_t)wrapped << 8) | (uint8_t)next_scroll;
		wrapped ^= (uint8_t)(map_draw_scroll >> 8u);
		if ((wrapped & 2u) != 0u)
			floor_place -= 0x40u;
		floor_map_place = floor_place;
		map_cell = ((uint32_t)stack_2 << 8) | stack;
		if ((wrapped & 1u) != 0u)
		{
			strip_jump = map_strip_step;
			map_cell += strip_jump;
		}
		new_draw_scroll = map_next_scroll;
		map_draw_scroll = new_draw_scroll;
		blocks_left_before = map_row_blocks_left;
		map_row_blocks_left = blocks_left_before - 1u;
	} while (blocks_left_before != 1u);
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
	uint8_t block_offset_high = 0, block_offset_low = 0, scene_number = 0;
	uint16_t address = 0, block = 0, scene_area = 0, scene_lists = 0;
	uint8_t scene_byte = 0, bank = 0;
	uint16_t block_number = 0, block_offset = 0;

	scene_lists = block_scenes_a_ADDRESS;
	scene_byte = map_scene;
	scene_number = scene_byte;
	if ((int8_t)scene_byte < 0)
	{
		scene_lists = block_scenes_a_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	window_bank = bank;
	set_lines(window_bank);
	address = SCENE_AREA(scene_area)->address;
	block_number = map_block;
	block_offset_low = (uint8_t)block_number;
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)(block_number >> 8) << 1) | carry);
	map_block = ((uint32_t)block_offset_high << 8) | block_offset_low;
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)block_offset_high << 1) | carry);
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)block_offset_high << 1) | carry);
	carry = (int8_t)block_offset_low < 0;
	block_offset = (((uint32_t)(uint8_t)(((uint32_t)block_offset_high << 1) | carry) << 8) | (uint8_t)((uint32_t)block_offset_low << 1)) + map_block;
	block = address + block_offset;
	return block;
}

/* The address of one of layer B's map blocks (18 bytes each) in the scene's area's block array
   (block_scenes_b), its bank switched in. */
uint16_t find_layer_b_block(void)
{
	uint32_t carry = 0;
	uint8_t block_offset_high = 0, block_offset_low = 0, scene_number = 0;
	uint16_t address = 0, block = 0, scene_area = 0, scene_lists = 0;
	uint8_t scene_byte = 0, bank = 0;
	uint16_t block_number = 0, block_offset = 0;

	scene_lists = block_scenes_b_ADDRESS;
	scene_byte = map_scene;
	scene_number = scene_byte;
	if ((int8_t)scene_byte < 0)
	{
		scene_lists = block_scenes_b_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	scene_area = SCENE_AREA_LIST(scene_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)(((uint32_t)map_area << 1) << 1);
	bank = SCENE_AREA(scene_area)->bank;
	window_bank = bank;
	set_lines(window_bank);
	address = SCENE_AREA(scene_area)->address;
	block_number = map_block;
	block_offset_low = (uint8_t)block_number;
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)(block_number >> 8) << 1) | carry);
	map_block = ((uint32_t)block_offset_high << 8) | block_offset_low;
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)block_offset_high << 1) | carry);
	carry = (int8_t)block_offset_low < 0;
	block_offset_low = (uint32_t)block_offset_low << 1;
	block_offset_high = (uint8_t)(((uint32_t)block_offset_high << 1) | carry);
	carry = (int8_t)block_offset_low < 0;
	block_offset = (((uint32_t)(uint8_t)(((uint32_t)block_offset_high << 1) | carry) << 8) | (uint8_t)((uint32_t)block_offset_low << 1)) + map_block;
	block = address + block_offset;
	return block;
}

/* Sets the K052109's tile ROM banks for the map's scene and area (layer_modes). */
void set_area_tile_banks(void)
{
	uint8_t scene_number = 0, tile_banks = 0;
	uint16_t mode_lists = 0;
	uint8_t scene_byte = 0;
	uint16_t area_mode = 0;

	mode_lists = layer_modes_ADDRESS;
	scene_byte = map_scene;
	scene_number = scene_byte;
	if ((int8_t)scene_byte < 0)
	{
		mode_lists = layer_modes_high_ADDRESS;
		scene_number &= 0x7Fu;
	}
	area_mode = LAYER_MODE_LIST(mode_lists + (int8_t)((uint32_t)scene_number << 1)) + (int8_t)((uint32_t)map_area << 1);
	io_write8(0x1D80u, LAYER_MODE(area_mode)->tile_banks_01);
	tile_banks = LAYER_MODE(area_mode)->tile_banks_23;
	io_write8(0x1F00u, tile_banks);
}
