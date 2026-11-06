/**
 *    Name:        drums.c
 *    Description: the drum routines: a music note's low nibble on a channel with a drum kit (+12) runs one
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void fm_drum_1_1(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x49ACu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xD00u;
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 0xDu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x50u);
	hl = fm_drum_1_1_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_1_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 == 1u)
	{
		drum_done(ix);
		return;
	}
	z80_block(115);
	t2 = z80_read16((uint16_t)(ix + 1u)) - 0x20u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 1u), l);
	z80_write8((uint16_t)(ix + 2u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_drum_1_2(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x49FFu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xC70u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0xFFu);
	hl = fm_drum_1_2_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_2_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_3(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4A38u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xE00u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x80u);
	hl = fm_drum_1_3_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_3_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_4(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4A71u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xE00u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x80u);
	hl = fm_drum_1_4_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_4_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_5(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4AAAu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xE00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xEu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = fm_drum_1_5_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_5_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0xCu;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t2 = z80_read16(ix) - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_6(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4B0Du;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xD00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xDu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = fm_drum_1_6_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_6_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0xCu;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t2 = z80_read16(ix) - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_7(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4B70u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = fm_drum_1_7_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_7_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0xCu;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t2 = z80_read16(ix) - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_8(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4BD3u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x900u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 9u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = fm_drum_1_8_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_1_8_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 2u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t2 = z80_read16(ix) - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	drum_done(ix);
}

void fm_drum_1_9(uint16_t ix)
{
	z80_block(10);
	drum_done(ix);
}

void fm_drum_2_1(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4C39u;
	load_patch(hl, ix);
	fm_drum_2_1_setup(ix);
}

void fm_drum_2_1_setup(uint16_t ix)
{
	z80_block(19);
	z80_write8(ix, 0xAu);
	fm_drum_2_1_retrigger(ix);
}

void fm_drum_2_1_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(84);
	z80_write8((uint16_t)(ix + 1u), 0xC0u);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = fm_drum_2_1_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_2_1_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) + 2u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t3 = z80_read8(ix);
	z80_write8(ix, t3 - 1u);
	if (t3 != 1u)
	{
		fm_drum_2_1_retrigger(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	fm_drum_2_1_setup(ix);
}

void fm_drum_2_2(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4C98u;
	load_patch(hl, ix);
	fm_drum_2_2_setup(ix);
}

void fm_drum_2_2_setup(uint16_t ix)
{
	z80_block(19);
	z80_write8(ix, 0xAu);
	fm_drum_2_2_retrigger(ix);
}

void fm_drum_2_2_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(84);
	z80_write8((uint16_t)(ix + 1u), 0xC0u);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = fm_drum_2_2_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_2_2_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) + 2u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t3 = z80_read8(ix);
	z80_write8(ix, t3 - 1u);
	if (t3 != 1u)
	{
		fm_drum_2_2_retrigger(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	fm_drum_2_2_setup(ix);
}

void fm_drum_2_3(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4CF7u;
	load_patch(hl, ix);
	fm_drum_2_3_retrigger(ix);
}

void fm_drum_2_3_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x600u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 6u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x80u);
	hl = fm_drum_2_3_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_2_3_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) + 2u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(28);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	fm_drum_2_3_retrigger(ix);
}

void fm_drum_2_4(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(46);
	z80_write8(ix, 0u);
	hl = 0x4D49u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1700u;
	z80_write8((uint16_t)(ix + 4u), 0u);
	z80_write8((uint16_t)(ix + 5u), 0x17u);
	set_pitch(hl, ix);
	fm_drum_2_4_retrigger(ix);
}

void fm_drum_2_4_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(17);
	key_on(ix);
	z80_block(65);
	z80_write8((uint16_t)(ix + 6u), 0u);
	z80_write8((uint16_t)(ix + 7u), 0x18u);
	fm_drum_2_4_update_3(ix);
	z80_block(20);
	hl = fm_drum_2_4_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_2_4_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	z80_block(142);
	t1 = z80_read16((uint16_t)(ix + 4u)) + z80_read16((uint16_t)(ix + 2u));
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 4u), l);
	z80_write8((uint16_t)(ix + 5u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(36);
	if (z80_read8((uint16_t)(ix + 5u)) < 8u)
	{
		z80_cycles(7);
		fm_drum_2_4_update(ix);
	}
	z80_block(36);
	if (z80_read8((uint16_t)(ix + 5u)) >= 0x17u)
	{
		z80_cycles(7);
		fm_drum_2_4_update_2(ix);
	}
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 == 1u)
	{
		z80_cycles(7);
		fm_drum_2_4_update_3(ix);
	}
	z80_block(95);
	t3 = z80_read16((uint16_t)(ix + 6u)) - 1u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 6u), l);
	z80_write8((uint16_t)(ix + 7u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(10);
	fm_drum_2_4_retrigger(ix);
}

void fm_drum_2_4_update(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	a = fm_drum_2_4_update_4(ix);
	z80_block(36);
	z80_write8((uint16_t)(ix + 1u), a);
	a = fm_drum_2_4_update_4(ix);
	z80_block(55);
	z80_write8((uint16_t)(ix + 2u), a & 0x1Fu);
	z80_write8((uint16_t)(ix + 3u), 0u);
}

void fm_drum_2_4_update_2(uint16_t ix)
{
	z80_block(17);
	fm_drum_2_4_update(ix);
	fm_drum_2_4_transpose(ix);
}

void fm_drum_2_4_transpose(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(115);
	hl = 0u - z80_read16((uint16_t)(ix + 2u));
	z80_write16((uint16_t)(ix + 2u), hl);
}

void fm_drum_2_4_update_3(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(17);
	fm_drum_2_4_update(ix);
	z80_block(17);
	a = fm_drum_2_4_update_4(ix);
	z80_block(13);
	if ((a & 1u) == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	fm_drum_2_4_transpose(ix);
}

uint8_t fm_drum_2_4_update_4(uint16_t ix)
{
	uint8_t a = 0;

	z80_block(66);
	a = z80_read8(0x200u | z80_read8(ix));
	z80_write8(ix, z80_read8(ix) + 1u);
	return a;
}

void fm_drum_2_5(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4E0Eu;
	load_patch(hl, ix);
	fm_drum_2_5_retrigger(ix);
}

void fm_drum_2_5_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1500u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x15u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0xCu);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_drum_2_5_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_drum_2_5_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		fm_drum_2_5_retrigger(ix);
		return;
	}
	z80_block(107);
	t3 = z80_read16((uint16_t)(ix + 2u)) + 0x40u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_drum_2_6(uint16_t ix)
{
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4FCEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4FE2u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x4FF6u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5010u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x502Au;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5044u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x505Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5072u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5086u;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x509Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x50AEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_drum_1_b_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_drum_1_b_note(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x50B1u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_drum_1_b_note_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_drum_1_b_note_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x50B4u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_c(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x10u);
	hl = pcm_drum_1_c_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_drum_1_c_note(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x50EEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_drum_1_c_note_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_drum_1_c_note_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x50F1u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = pcm_drum_1_c_note_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void pcm_drum_1_c_note_3(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;

	z80_block(17);
	zero = pcm_voice_playing(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	hl = 0x50F4u;
	load_patch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_d(uint16_t ix)
{
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_1_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x513Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5153u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5167u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x517Bu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5195u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x51AFu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x51C9u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x51E3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x51F7u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x520Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x521Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5233u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5247u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x525Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x526Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_2_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5283u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5297u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x52ABu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x52BFu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x52D9u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x52F3u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x530Du;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5327u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x533Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x534Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5363u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5377u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x538Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x539Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x53B3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_3_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x53C7u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x53DBu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x53EFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5403u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5417u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5431u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x544Bu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5465u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5479u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x548Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x54A1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x54B5u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x54C9u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x54DDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x54F1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_4_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5505u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5519u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x552Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5541u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x555Bu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5575u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x558Fu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x55A9u;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x55BDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x55D1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x55E5u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x55F9u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x560Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5621u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5635u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_5_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5649u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x565Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5671u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5685u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x569Fu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x56B9u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x56D3u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x56EDu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5701u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5715u;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5729u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x573Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5751u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5765u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5779u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_6_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x578Du;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x57A1u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x57B5u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x57C9u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x57DDu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x57F7u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5811u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x582Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x583Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5853u;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5867u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x587Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x588Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x58A3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x58B7u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_7_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x58CBu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x58DFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x58F3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5907u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5921u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x593Bu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5955u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x596Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5983u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5997u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x59ABu;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x59BFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x59D3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x59E7u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x59FBu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_8_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A0Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A23u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A37u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A4Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A5Fu;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A73u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A87u;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5A9Bu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5AAFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 5u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5AC3u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5AD7u;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5AEBu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5AFFu;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B13u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_9_e(uint16_t ix)
{
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B2Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B3Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B52u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B6Cu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5B86u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5BA0u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5BBAu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5BCEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5BE2u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5BF6u;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C0Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C1Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C32u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C46u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_a_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C5Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_1(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C6Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_2(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C82u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_3(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5C96u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF40u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_4(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5CB0u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF20u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_5(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5CCAu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xF00u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_6(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5CE4u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xEE0u;
	set_pitch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_7(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5CFEu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_8(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D12u;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_9(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D26u;
	load_patch(hl, ix);
	z80_block(24);
	a = 7u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_a(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D3Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 1u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_b(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D4Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 6u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_c(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D62u;
	load_patch(hl, ix);
	z80_block(24);
	a = 2u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_d(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D76u;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_e(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D8Au;
	load_patch(hl, ix);
	z80_block(24);
	a = 4u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}

void pcm_drum_b_f(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x5D9Eu;
	load_patch(hl, ix);
	z80_block(24);
	a = 3u;
	set_pan(ix, a);
	z80_block(17);
	key_on(ix);
	z80_block(10);
	drum_done(ix);
}
