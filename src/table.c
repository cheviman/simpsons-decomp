/**
 *    Name:        table.c
 *    Description: the code the board runs by itself (the reset's, the interrupts' handlers) and the tables the game loads by name
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* the code at the reset vector */
void game_entry(void)
{
	sub_0786CE();
}

/* the IRQ's handler (the K052109's, at VBLANK) */
void game_irq(void)
{
	sub_078F43();
}

/* the FIRQ's handler (the sprite DMA's) */
void game_firq(void)
{
	sub_0791B2();
}

const void *rom_021C32_data;
const void *rom_023694_data;
const void *unused_tile_places_data;
const void *value_03BAB1_data;
const void *indexed_table_05FCA7_data;
const void *indexed_table_05FCB6_data;
const void *indexed_table_05FCCB_data;
const void *value_07E423_data;
const void *value_07E425_data;
const void *value_07E427_data;
const void *value_07E429_data;
const void *rom_07FFFE_data;

/* the tables the game loads from its assets: their names, places, pointers and the bytes of their
   elements (the loader puts each element in the host's byte order) */
const game_table game_tables[] =
{
	{ "rom_021C32", 0x021C32u, &rom_021C32_data, 2 },
	{ "rom_023694", 0x023694u, &rom_023694_data, 1 },
	{ "unused_tile_places", 0x0356E5u, &unused_tile_places_data, 1 },
	{ "value_03BAB1", 0x03BAB1u, &value_03BAB1_data, 2 },
	{ "indexed_table_05FCA7", 0x05FCA7u, &indexed_table_05FCA7_data, 1 },
	{ "indexed_table_05FCB6", 0x05FCB6u, &indexed_table_05FCB6_data, 1 },
	{ "indexed_table_05FCCB", 0x05FCCBu, &indexed_table_05FCCB_data, 1 },
	{ "value_07E423", 0x07E423u, &value_07E423_data, 2 },
	{ "value_07E425", 0x07E425u, &value_07E425_data, 2 },
	{ "value_07E427", 0x07E427u, &value_07E427_data, 2 },
	{ "value_07E429", 0x07E429u, &value_07E429_data, 2 },
	{ "rom_07FFFE", 0x07FFFEu, &rom_07FFFE_data, 2 },
};

const size_t game_table_count = 12;
