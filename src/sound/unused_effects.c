/**
 *    Name:        unused_effects.c
 *    Description: a group of four FM effects no command reaches (unused_effect_group)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void unused_effect_2799(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2780u;
	load_patch(hl, ix);
	z80_block(43);
	a = 0u;
	z80_write8((uint16_t)(ix + 1u), 0u);
	unused_0FF2(ix, a);
	z80_block(65);
	hl = 0x800u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 8u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x10u);
	hl = unused_effect_2799_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void unused_effect_2799_slide(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) + 4u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if (z80_read8((uint16_t)(ix + 1u)) & 1u)
	{
		z80_block(21);
		hl += 0x80u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(59);
	z80_write8(ix, 0x10u);
	a = z80_read8((uint16_t)(ix + 1u)) + 1u;
	if (a >= 0x20u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(29);
	z80_write8((uint16_t)(ix + 1u), a);
	unused_0FF2(ix, a);
}

void unused_effect_280E(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x27F5u;
	load_patch(hl, ix);
	z80_block(43);
	a = 0xAu;
	z80_write8((uint16_t)(ix + 1u), 0xAu);
	unused_0FF2(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x10u);
	hl = unused_effect_280E_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void unused_effect_280E_hold(uint16_t ix)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	z80_write8(ix, 0x10u);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(29);
	a = z80_read8((uint16_t)(ix + 1u));
	unused_0FF2(ix, a);
}

void unused_effect_2856(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x283Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 0x12u;
	unused_0FF2(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 4u);
	hl = unused_effect_2856_end_ADDRESS;
	set_channel_handler(hl, ix);
}

void unused_effect_2856_end(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void unused_effect_289F(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2886u;
	load_patch(hl, ix);
	z80_block(24);
	a = 0x1Fu;
	unused_0FF2(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 0x16u);
	hl = unused_effect_289F_step_ADDRESS;
	set_channel_handler(hl, ix);
}

void unused_effect_289F_step(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = unused_effect_289F_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 2u);
	hl = unused_effect_289F_end_ADDRESS;
	set_channel_handler(hl, ix);
}

void unused_effect_289F_end(uint16_t ix)
{
	uint32_t zero = 0;

	z80_block(17);
	zero = unused_effect_289F_update(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t unused_effect_289F_update(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(100);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	zero = (l | h) == 0u;
	return zero;
}
