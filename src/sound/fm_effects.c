/**
 *    Name:        fm_effects.c
 *    Description: the FM effects (commands 01-38), each a chain of handlers its record runs one pass at a time
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the Z80 sound program decompiled into C by
 *    tools/decompile_sound.py, with the names of sound_symbols.txt.
 */
#include "sound.h"

void fm_effect_02(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x30u);
	hl = fm_effect_02_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_02_delay(uint16_t ix)
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
	fm_effect_01(ix);
}

void fm_effect_01(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x10BEu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x600u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 6u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x2Au);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	hl = fm_effect_01_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_01_retrigger(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(27);
	de = 8u;
	zero = fm_effect_01_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	de = 0xFF30u;
	zero = fm_effect_01_move_pitch(de, ix);
	z80_block(47);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x2Au);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	hl = fm_effect_01_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_01_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;
	uint8_t t1 = 0;

	z80_block(27);
	de = 0xFFF8u;
	zero = fm_effect_01_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	de = 0xD0u;
	zero = fm_effect_01_move_pitch(de, ix);
	z80_block(47);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_01_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(104);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t2 == 0u;
	z80_write8((uint16_t)(ix + 1u), t2);
	return zero;
}

void fm_effect_04(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x10u);
	hl = fm_effect_04_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_04_delay(uint16_t ix)
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
	fm_effect_03(ix);
}

void fm_effect_03(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x115Du;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xF00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xFu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(77);
	z80_write8(ix, 0x10u);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	z80_write8((uint16_t)(ix + 4u), 0u);
	hl = fm_effect_03_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_03_pitch(uint16_t ix)
{
	uint16_t de = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	de = 0xFFF8u;
	fm_effect_03_move_pitch(de, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(46);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	de = 0xB0u;
	fm_effect_03_move_pitch(de, ix);
	z80_block(28);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_03_move_pitch(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(97);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_effect_06(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(43);
	a = 0x20u;
	z80_write8((uint16_t)(ix + 4u), 0x20u);
	set_volume(ix, a);
	z80_block(39);
	z80_write8(ix, 0x70u);
	hl = fm_effect_06_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_06_delay(uint16_t ix)
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
	fm_effect_05_note(ix);
}

void fm_effect_05(uint16_t ix)
{
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 0x18u);
	fm_effect_05_note(ix);
}

void fm_effect_05_note(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x11D6u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8(ix, 4u);
	fm_effect_05_retrigger(ix);
}

void fm_effect_05_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x800u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 8u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x80u);
	hl = fm_effect_05_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_05_slide(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) + 0x10u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	a = z80_read8((uint16_t)(ix + 4u)) + 0x18u;
	z80_write8((uint16_t)(ix + 4u), a);
	set_volume(ix, a);
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_05_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_07(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1265u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1800u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x18u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 4u);
	hl = fm_effect_07_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_07_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 1u;
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
	stop_channel(ix);
}

void fm_effect_09(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8((uint16_t)(ix + 2u), 0xCu);
	hl = fm_effect_09_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_09_delay(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 2u));
	z80_write8((uint16_t)(ix + 2u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_08(ix);
}

void fm_effect_08(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x12C8u;
	load_patch(hl, ix);
	z80_block(87);
	z80_write8(ix, 0xE1u);
	z80_write8((uint16_t)(ix + 1u), 0x12u);
	z80_write8((uint16_t)(ix + 2u), 1u);
	hl = fm_effect_08_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_08_retrigger(uint16_t ix)
{
	uint8_t d = 0, e = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 2u));
	z80_write8((uint16_t)(ix + 2u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(142);
	z80_write8((uint16_t)(ix + 2u), 0x18u);
	hl = z80_read16(ix);
	e = z80_read8(hl);
	hl++;
	d = z80_read8(hl);
	hl++;
	z80_write16(ix, hl);
	if (d == 0xFFu)
	{
		z80_block(39);
		z80_write8((uint16_t)(ix + 2u), 0u);
		hl = fm_effect_08_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(21);
	hl = ((uint32_t)d << 8) | e;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_08_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 2u));
	z80_write8((uint16_t)(ix + 2u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_0d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x10u);
	hl = fm_effect_0d_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0d_delay(uint16_t ix)
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
	fm_effect_0c(ix);
}

void fm_effect_0c(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1351u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1300u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x13u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 3u);
	z80_write8((uint16_t)(ix + 1u), 0x18u);
	hl = fm_effect_0c_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0c_retrigger(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	de = SOUND_BANK_FE00;
	fm_effect_0c_move_pitch(de, ix);
	z80_block(20);
	hl = fm_effect_0c_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0c_retrigger_2(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(39);
		z80_write8((uint16_t)(ix + 1u), 0u);
		hl = fm_effect_0c_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(27);
	de = 0x80u;
	fm_effect_0c_move_pitch(de, ix);
	z80_block(20);
	hl = fm_effect_0c_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0c_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_0c_move_pitch(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	key_off(ix);
	z80_block(104);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(29);
	z80_write8((uint16_t)(ix + 1u), 0x18u);
	key_on(ix);
}

void fm_effect_0e(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x13ECu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 8u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_0e_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0e_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0, hl = 0;

	z80_block(27);
	de = 0xFFC0u;
	zero = fm_effect_0e_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x60u);
	hl = fm_effect_0e_pitch_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0e_pitch_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0x18u;
	zero = fm_effect_0e_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_0e_slide(ix);
}

void fm_effect_0e_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0x600u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_0e_pitch_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0e_pitch_3(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;
	uint8_t t1 = 0;

	z80_block(27);
	de = 0x18u;
	zero = fm_effect_0e_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_0e_slide(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_0e_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 2u)) + de;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 6) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t1 == 0u;
	z80_write8((uint16_t)(ix + 1u), t1);
	return zero;
}

void fm_effect_0f(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x148Cu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 8u);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_0f_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_0f_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 == 1u)
	{
		z80_block(52);
		z80_write8((uint16_t)(ix + 1u), 0x40u);
		t2 = z80_read8(ix);
		z80_write8(ix, t2 - 1u);
		if (t2 == 1u)
		{
			stop_channel(ix);
			return;
		}
		z80_block(107);
		hl = z80_read16((uint16_t)(ix + 2u)) - 0x400u;
		z80_write16((uint16_t)(ix + 2u), hl);
		set_pitch(hl, ix);
		return;
	}
	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) + 0x18u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if (((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u) == 0u)
	{
		set_pitch(hl, ix);
		return;
	}
	z80_block(31);
	hl += 0x400u;
	set_pitch(hl, ix);
}

void fm_effect_10(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1509u;
	load_patch(hl, ix);
	z80_block(65);
	hl = pcm_voice_playing_ADDRESS;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x10u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 8u);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_10_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_10_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 == 1u)
	{
		z80_block(52);
		z80_write8((uint16_t)(ix + 1u), 0x40u);
		t2 = z80_read8(ix);
		z80_write8(ix, t2 - 1u);
		if (t2 == 1u)
		{
			stop_channel(ix);
			return;
		}
		z80_block(107);
		hl = z80_read16((uint16_t)(ix + 2u)) - 0x400u;
		z80_write16((uint16_t)(ix + 2u), hl);
		set_pitch(hl, ix);
		return;
	}
	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) + 0x40u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if (((z80_read8((uint16_t)(ix + 1u)) >> 3) & 1u) == 0u)
	{
		set_pitch(hl, ix);
		return;
	}
	z80_block(31);
	hl += 0x100u;
	set_pitch(hl, ix);
}

void fm_effect_11(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1586u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1700u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x17u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 2u);
	hl = fm_effect_11_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_11_pitch(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t de = 0;
	uint16_t t1 = 0;

	z80_block(27);
	de = 0xFFF8u;
	fm_effect_11_move_pitch(de, ix);
	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((h | l) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_11_move_pitch(uint16_t de, uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 2u)) + de;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8(ix) >> 1) & 1u)
	{
		z80_block(21);
		hl += 0x100u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_12(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x15F7u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x400u;
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 4u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 3u);
	hl = fm_effect_12_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_12_delay(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8((uint16_t)(ix + 2u), 0xA0u);
	z80_write8((uint16_t)(ix + 3u), 1u);
	hl = fm_effect_12_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_12_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	z80_block(115);
	t1 = z80_read16(ix) - 1u;
	t2 = t1 - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	if ((z80_read8((uint16_t)(ix + 2u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t3 = (((uint32_t)h << 8) | l) - 0xC0u;
		h = (uint8_t)(t3 >> 8);
		l = (uint8_t)t3;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t4 = z80_read16((uint16_t)(ix + 2u)) - 1u;
	h = (uint8_t)(t4 >> 8);
	l = (uint8_t)t4;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_13(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x167Fu;
	load_patch(hl, ix);
	z80_block(84);
	hl = 0x700u;
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 7u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8((uint16_t)(ix + 3u), 0u);
	z80_write8((uint16_t)(ix + 4u), 1u);
	hl = fm_effect_13_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_13_slide(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(104);
	l = z80_read8(ix);
	h = z80_read8((uint16_t)(ix + 1u));
	t1 = (((uint32_t)h << 8) | l) + 0x1E0u;
	carry = (uint16_t)((((uint32_t)h << 8) | l) + 0x1E0u) < (uint16_t)(((uint32_t)h << 8) | l);
	z80_write16(ix, t1);
	if (carry == 0u)
		z80_cycles(5);
	else
	{
		z80_block(23);
		z80_write8((uint16_t)(ix + 2u), z80_read8((uint16_t)(ix + 2u)) + 1u);
	}
	z80_block(65);
	l = z80_read8((uint16_t)(ix + 1u));
	h = z80_read8((uint16_t)(ix + 2u));
	if ((z80_read8((uint16_t)(ix + 3u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t2 = (((uint32_t)h << 8) | l) + 0x200u;
		h = (uint8_t)(t2 >> 8);
		l = (uint8_t)t2;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t3 = z80_read16((uint16_t)(ix + 3u)) - 1u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 3u), l);
	z80_write8((uint16_t)(ix + 4u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(58);
	z80_write8((uint16_t)(ix + 3u), 0x40u);
	z80_write8((uint16_t)(ix + 4u), 1u);
	hl = fm_effect_13_slide_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_13_slide_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(62);
	t1 = z80_read16((uint16_t)(ix + 3u)) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	if ((l | h) == 0u)
	{
		z80_block(55);
		z80_write8((uint16_t)(ix + 3u), 0xC0u);
		z80_write8((uint16_t)(ix + 4u), 0u);
		key_off(ix);
		z80_block(20);
		hl = fm_effect_13_slide_3_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(103);
	z80_write8((uint16_t)(ix + 3u), l);
	z80_write8((uint16_t)(ix + 4u), h);
	l = z80_read8((uint16_t)(ix + 1u));
	h = z80_read8((uint16_t)(ix + 2u));
	if ((z80_read8((uint16_t)(ix + 3u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t2 = (((uint32_t)h << 8) | l) + 0x200u;
		h = (uint8_t)(t2 >> 8);
		l = (uint8_t)t2;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
}

void fm_effect_13_slide_3(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(132);
	t1 = z80_read16((uint16_t)(ix + 1u)) - 6u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 1u), l);
	z80_write8((uint16_t)(ix + 2u), h);
	if ((z80_read8((uint16_t)(ix + 3u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t2 = (((uint32_t)h << 8) | l) + 0x200u;
		h = (uint8_t)(t2 >> 8);
		l = (uint8_t)t2;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t3 = z80_read16((uint16_t)(ix + 3u)) - 1u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 3u), l);
	z80_write8((uint16_t)(ix + 4u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_14(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x176Eu;
	load_patch(hl, ix);
	z80_block(84);
	hl = 0x200u;
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 2u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8((uint16_t)(ix + 3u), 0u);
	z80_write8((uint16_t)(ix + 4u), 2u);
	hl = fm_effect_14_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_14_slide(uint16_t ix)
{
	uint32_t carry = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(66);
	l = z80_read8(ix);
	h = z80_read8((uint16_t)(ix + 1u));
	t1 = (((uint32_t)h << 8) | l) + 0xC0u;
	carry = (uint16_t)((((uint32_t)h << 8) | l) + 0xC0u) < (uint16_t)(((uint32_t)h << 8) | l);
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	if (carry == 0u)
		z80_cycles(5);
	else
	{
		z80_block(23);
		z80_write8((uint16_t)(ix + 2u), z80_read8((uint16_t)(ix + 2u)) + 1u);
	}
	z80_block(88);
	z80_write8(ix, l);
	z80_write8((uint16_t)(ix + 1u), h);
	l = h;
	h = z80_read8((uint16_t)(ix + 2u));
	if ((z80_read8((uint16_t)(ix + 3u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t2 = (((uint32_t)h << 8) | l) + 0x80u;
		h = (uint8_t)(t2 >> 8);
		l = (uint8_t)t2;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t3 = z80_read16((uint16_t)(ix + 3u)) - 1u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 3u), l);
	z80_write8((uint16_t)(ix + 4u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(58);
	z80_write8((uint16_t)(ix + 3u), 0u);
	z80_write8((uint16_t)(ix + 4u), 0xAu);
	hl = fm_effect_14_slide_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_14_slide_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0, t2 = 0;

	z80_block(65);
	l = z80_read8((uint16_t)(ix + 1u));
	h = z80_read8((uint16_t)(ix + 2u));
	if ((z80_read8((uint16_t)(ix + 3u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		t1 = (((uint32_t)h << 8) | l) + 0x80u;
		h = (uint8_t)(t1 >> 8);
		l = (uint8_t)t1;
	}
	z80_block(17);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(95);
	t2 = z80_read16((uint16_t)(ix + 3u)) - 1u;
	h = (uint8_t)(t2 >> 8);
	l = (uint8_t)t2;
	z80_write8((uint16_t)(ix + 3u), l);
	z80_write8((uint16_t)(ix + 4u), h);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_15(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x181Au;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0x400u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = fm_effect_15_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_15_note(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
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
	z80_block(17);
	key_off(ix);
	z80_block(27);
	hl = 0x1833u;
	load_patch(hl, ix);
	z80_block(65);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 3u);
	hl = 0x300u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 2u), 0xB0u);
	hl = fm_effect_15_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_15_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(124);
	hl = z80_read16(ix) - 4u;
	z80_write16(ix, hl);
	if ((z80_read8((uint16_t)(ix + 2u)) & 1u) == 0u)
		z80_cycles(5);
	else
	{
		z80_block(21);
		hl += 0x280u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 2u));
	z80_write8((uint16_t)(ix + 2u), t1 - 1u);
	if (t1 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(10);
}

void fm_effect_17(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;

	z80_block(24);
	a = 0xAu;
	set_volume(ix, a);
	z80_block(39);
	z80_write8(ix, 0x2Cu);
	hl = fm_effect_17_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_17_delay(uint16_t ix)
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
	fm_effect_16(ix);
}

void fm_effect_16(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x18BFu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x600u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 6u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(77);
	z80_write8(ix, 0xBu);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	z80_write8((uint16_t)(ix + 4u), 0u);
	hl = fm_effect_16_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_16_pitch(uint16_t ix)
{
	uint16_t de = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(27);
	de = 0x10u;
	fm_effect_16_move_pitch(de, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(46);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	de = SOUND_BANK_FE00;
	fm_effect_16_move_pitch(de, ix);
	z80_block(28);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_16_move_pitch(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(97);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_effect_18(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x193Du;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x800u;
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 8u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x70u);
	hl = fm_effect_18_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_18_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 1u)) + 0x20u;
	z80_write16((uint16_t)(ix + 1u), hl);
	if ((z80_read8(ix) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_19(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1999u;
	load_patch(hl, ix);
	z80_block(38);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 4u), 0xBu);
	fm_effect_19_retrigger(ix);
}

void fm_effect_19_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1300u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x13u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_19_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_19_slide(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) - 0x10u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	a = z80_read8((uint16_t)(ix + 4u)) + 0xBu;
	z80_write8((uint16_t)(ix + 4u), a);
	set_volume(ix, a);
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_19_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_1a(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1A0Fu;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8(ix, 3u);
	fm_effect_1a_retrigger(ix);
}

void fm_effect_1a_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0u);
	hl = fm_effect_1a_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1a_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) - 8u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_1a_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_1b(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1A76u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_1b_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1b_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0, hl = 0;

	z80_block(27);
	de = 0xFFC8u;
	zero = fm_effect_1b_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0xE0u);
	hl = fm_effect_1b_pitch_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1b_pitch_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0x10u;
	zero = fm_effect_1b_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_1b_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 2u)) + de;
	z80_write16((uint16_t)(ix + 2u), hl);
	if (((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u) == 0u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t1 == 0u;
	z80_write8((uint16_t)(ix + 1u), t1);
	return zero;
}

void fm_effect_1c(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1AE8u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1500u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x15u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_1c_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1c_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0, hl = 0;

	z80_block(27);
	de = 0xFFB0u;
	zero = fm_effect_1c_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_1c_pitch_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1c_pitch_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0x20u;
	zero = fm_effect_1c_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	fm_effect_1c_slide(ix);
}

void fm_effect_1c_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0x200u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_1c_pitch_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1c_pitch_3(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;
	uint8_t t1 = 0;

	z80_block(27);
	de = 8u;
	zero = fm_effect_1c_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_1c_slide(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_1c_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 2u)) + de;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t1 == 0u;
	z80_write8((uint16_t)(ix + 1u), t1);
	return zero;
}

void fm_effect_1d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1B88u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1500u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x15u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_1d_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1d_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0xFFB0u;
	zero = fm_effect_1d_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(19);
	z80_write8(ix, 0xAu);
	fm_effect_1d_pitch_2(ix);
}

void fm_effect_1d_pitch_2(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	hl = fm_effect_1d_pitch_3_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1d_pitch_3(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;
	uint8_t t1 = 0;

	z80_block(27);
	de = 0xFFF0u;
	zero = fm_effect_1d_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_1d_pitch_2(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_1d_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 2u)) + de;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x100u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t1 == 0u;
	z80_write8((uint16_t)(ix + 1u), t1);
	return zero;
}

void fm_effect_1e(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1C10u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1500u;
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 0x15u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x80u);
	hl = fm_effect_1e_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1e_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 1u)) - 0x28u;
	z80_write16((uint16_t)(ix + 1u), hl);
	if ((z80_read8(ix) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_1f(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1C6Cu;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0xD00u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x40u);
	hl = fm_effect_1f_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1f_retrigger(uint16_t ix)
{
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
	z80_block(17);
	key_off(ix);
	z80_block(27);
	hl = pcm_voice_playing_ADDRESS;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0u);
	z80_write8((uint16_t)(ix + 1u), 2u);
	hl = fm_effect_1f_end_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_1f_end(uint16_t ix)
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

void fm_effect_20(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1CD0u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1700u;
	z80_write8((uint16_t)(ix + 1u), 0u);
	z80_write8((uint16_t)(ix + 2u), 0x17u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8(ix, 0x30u);
	hl = fm_effect_20_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_20_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0, hl = 0;

	z80_block(27);
	de = 0xFFA0u;
	zero = fm_effect_20_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(39);
	z80_write8(ix, 0x40u);
	hl = fm_effect_20_pitch_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_20_pitch_2(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0x40u;
	zero = fm_effect_20_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_20_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0;

	z80_block(117);
	hl = z80_read16((uint16_t)(ix + 1u)) + de;
	z80_write16((uint16_t)(ix + 1u), hl);
	if ((z80_read8(ix) >> 3) & 1u)
	{
		z80_block(21);
		hl += 0x200u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(33);
	t1 = z80_read8(ix) - 1u;
	zero = t1 == 0u;
	z80_write8(ix, t1);
	return zero;
}

void fm_effect_21(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1D42u;
	load_patch(hl, ix);
	z80_block(27);
	hl = 0x600u;
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(68);
	z80_write8(ix, 0x80u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = fm_effect_21_end_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_21_end(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t t1 = 0;

	z80_block(95);
	t1 = z80_read16(ix) - 1u;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 1u), h);
	z80_write8(ix, l);
	if ((l | h) != 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_22(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1D8Cu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1500u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x15u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x18u);
	z80_write8((uint16_t)(ix + 1u), 0xAu);
	hl = fm_effect_22_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_22_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_block(67);
		t2 = z80_read16((uint16_t)(ix + 2u)) - 0x130u;
		h = (uint8_t)(t2 >> 8);
		l = (uint8_t)t2;
		z80_block(48);
		z80_write8((uint16_t)(ix + 2u), l);
		z80_write8((uint16_t)(ix + 3u), h);
		hl = ((uint32_t)h << 8) | l;
		set_pitch(hl, ix);
		return;
	}
	z80_block(52);
	z80_write8(ix, 0x18u);
	t3 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t3 - 1u);
	if (t3 == 1u)
	{
		stop_channel(ix);
		return;
	}
	z80_block(20);
	h = 0x15u;
	l = 0u;
	z80_block(48);
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_effect_23(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1DF3u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8(ix, 3u);
	fm_effect_23_retrigger(ix);
}

void fm_effect_23_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x80u);
	hl = fm_effect_23_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_23_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) - 0x14u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 1) & 1u)
	{
		z80_block(21);
		hl += 0x100u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_23_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_24(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1E5Au;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xB00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xBu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x20u);
	z80_write8((uint16_t)(ix + 1u), 8u);
	hl = fm_effect_24_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_24_retrigger(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(39);
		z80_write8(ix, 0u);
		hl = fm_effect_24_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(133);
	z80_write8(ix, 0x20u);
	t3 = z80_read16((uint16_t)(ix + 2u)) + 0x140u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_24_hold(uint16_t ix)
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
	stop_channel(ix);
}

void fm_effect_25(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 8u);
	hl = fm_effect_25_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_25_note(uint16_t ix)
{
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
	hl = 0x1ECEu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0xB08u;
	z80_write8((uint16_t)(ix + 2u), 8u);
	z80_write8((uint16_t)(ix + 3u), 0xBu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x20u);
	z80_write8((uint16_t)(ix + 1u), 8u);
	hl = fm_effect_25_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_25_retrigger(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0;

	z80_block(28);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(39);
		z80_write8(ix, 0u);
		hl = fm_effect_25_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(133);
	z80_write8(ix, 0x20u);
	t3 = z80_read16((uint16_t)(ix + 2u)) + 0x140u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_25_hold(uint16_t ix)
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
	stop_channel(ix);
}

void fm_effect_26(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1F50u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1200u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x12u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(19);
	z80_write8(ix, 3u);
	fm_effect_26_transpose(ix);
}

void fm_effect_26_transpose(uint16_t ix)
{
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(136);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0xB00u;
	z80_write16((uint16_t)(ix + 2u), t1);
	hl = fm_effect_26_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_26_slide(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	zero = fm_effect_26_move_pitch(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(136);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t1 = z80_read16((uint16_t)(ix + 2u)) + 0x100u;
	z80_write16((uint16_t)(ix + 2u), t1);
	hl = fm_effect_26_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_26_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t t1 = 0;

	z80_block(17);
	zero = fm_effect_26_move_pitch(ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t1 = z80_read8(ix);
	z80_write8(ix, t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_26_transpose(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_26_move_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(114);
	t1 = z80_read16((uint16_t)(ix + 2u)) + 0x1Cu;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t2 == 0u;
	z80_write8((uint16_t)(ix + 1u), t2);
	return zero;
}

void fm_effect_27(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x1FDEu;
	load_patch(hl, ix);
	z80_block(103);
	z80_write8(ix, 6u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = 0x17D8u;
	z80_write8((uint16_t)(ix + 2u), 0xD8u);
	z80_write8((uint16_t)(ix + 3u), 0x17u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(20);
	hl = fm_effect_27_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_27_retrigger(uint16_t ix)
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
	z80_block(36);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	key_off(ix);
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(39);
		z80_write8(ix, 0x80u);
		hl = fm_effect_27_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(114);
	t3 = z80_read16((uint16_t)(ix + 2u)) - 0x40u;
	h = (uint8_t)(t3 >> 8);
	l = (uint8_t)t3;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_27_hold(uint16_t ix)
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
	stop_channel(ix);
}

void fm_effect_28(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2052u;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x600u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 6u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 0x10u);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	hl = fm_effect_28_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_28_slide(uint16_t ix)
{
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) + 0x20u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x200u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(144);
	z80_write8((uint16_t)(ix + 1u), 0x20u);
	hl = z80_read16((uint16_t)(ix + 2u)) - 0x3E8u;
	z80_write16((uint16_t)(ix + 2u), hl);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_29(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x20CBu;
	load_patch(hl, ix);
	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_29_pitch_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_29_pitch(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;

	z80_block(27);
	de = 0xFFB8u;
	zero = fm_effect_29_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(19);
	z80_write8(ix, 3u);
	fm_effect_29_setup(ix);
}

void fm_effect_29_setup(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_29_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_29_slide(uint16_t ix)
{
	uint32_t zero = 0;
	uint16_t de = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(27);
	de = 0x20u;
	zero = fm_effect_29_move_pitch(de, ix);
	z80_block(5);
	if (zero == 0u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(130);
	t1 = z80_read16((uint16_t)(ix + 2u)) - 0x600u;
	z80_write16((uint16_t)(ix + 2u), t1);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_29_setup(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

uint32_t fm_effect_29_move_pitch(uint16_t de, uint16_t ix)
{
	uint32_t zero = 0;
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	z80_block(104);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(33);
	t2 = z80_read8((uint16_t)(ix + 1u)) - 1u;
	zero = t2 == 0u;
	z80_write8((uint16_t)(ix + 1u), t2);
	return zero;
}

void fm_effect_2b(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x30u);
	hl = fm_effect_2b_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2b_delay(uint16_t ix)
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
	fm_effect_2a(ix);
}

void fm_effect_2a(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x214Cu;
	load_patch(hl, ix);
	z80_block(65);
	hl = pcm_voice_playing_ADDRESS;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x10u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 3u);
	z80_write8((uint16_t)(ix + 1u), 0x18u);
	hl = fm_effect_2a_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2a_retrigger(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(27);
	de = 0x180u;
	fm_effect_2a_move_pitch(de, ix);
	z80_block(20);
	hl = fm_effect_2a_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2a_retrigger_2(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(39);
		z80_write8((uint16_t)(ix + 1u), 0u);
		hl = fm_effect_2a_hold_ADDRESS;
		set_channel_handler(hl, ix);
		return;
	}
	z80_block(27);
	de = 0xFF80u;
	fm_effect_2a_move_pitch(de, ix);
	z80_block(20);
	hl = fm_effect_2a_retrigger_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2a_hold(uint16_t ix)
{
	uint8_t t1 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_2a_move_pitch(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(17);
	key_off(ix);
	z80_block(104);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(29);
	z80_write8((uint16_t)(ix + 1u), 0x18u);
	key_on(ix);
}

void fm_effect_2c(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x21E7u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 5u);
	fm_effect_2c_retrigger(ix);
}

void fm_effect_2c_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0xC00u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_2c_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2c_delay(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2c_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xC0u;
	if (t2 != 1u)
	{
		fm_effect_2c_transpose(de, ix);
		return;
	}
	z80_block(58);
	z80_write8(ix, 2u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = fm_effect_2c_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2c_hold(uint16_t ix)
{
	uint16_t de = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2c_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xFF00u;
	if (t2 != 1u)
	{
		fm_effect_2c_transpose(de, ix);
		return;
	}
	z80_block(33);
	t3 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t3 - 1u);
	if (t3 != 1u)
	{
		fm_effect_2c_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_2c_transpose(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(97);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	fm_effect_2c_slide(hl, ix);
}

void fm_effect_2c_setup(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(38);
	hl = z80_read16((uint16_t)(ix + 2u));
	fm_effect_2c_slide(hl, ix);
}

void fm_effect_2c_slide(uint16_t hl, uint16_t ix)
{
	z80_block(30);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_2d(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x20u);
	hl = fm_effect_2d_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2d_note(uint16_t ix)
{
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
	hl = 0x2288u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 5u);
	fm_effect_2d_retrigger(ix);
}

void fm_effect_2d_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0xC04u;
	z80_write8((uint16_t)(ix + 2u), 4u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_2d_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2d_delay(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2d_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xC0u;
	if (t2 != 1u)
	{
		fm_effect_2d_transpose(de, ix);
		return;
	}
	z80_block(58);
	z80_write8(ix, 2u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = fm_effect_2d_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2d_hold(uint16_t ix)
{
	uint16_t de = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2d_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xFF00u;
	if (t2 != 1u)
	{
		fm_effect_2d_transpose(de, ix);
		return;
	}
	z80_block(33);
	t3 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t3 - 1u);
	if (t3 != 1u)
	{
		fm_effect_2d_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_2d_transpose(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(97);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	fm_effect_2d_slide(hl, ix);
}

void fm_effect_2d_setup(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(38);
	hl = z80_read16((uint16_t)(ix + 2u));
	fm_effect_2d_slide(hl, ix);
}

void fm_effect_2d_slide(uint16_t hl, uint16_t ix)
{
	z80_block(30);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_2e(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x40u);
	hl = fm_effect_2e_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2e_note(uint16_t ix)
{
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
	hl = 0x2337u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 5u);
	fm_effect_2e_retrigger(ix);
}

void fm_effect_2e_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0xC08u;
	z80_write8((uint16_t)(ix + 2u), 8u);
	z80_write8((uint16_t)(ix + 3u), 0xCu);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_2e_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2e_delay(uint16_t ix)
{
	uint16_t de = 0, hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2e_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xC0u;
	if (t2 != 1u)
	{
		fm_effect_2e_transpose(de, ix);
		return;
	}
	z80_block(58);
	z80_write8(ix, 2u);
	z80_write8((uint16_t)(ix + 1u), 1u);
	hl = fm_effect_2e_hold_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2e_hold(uint16_t ix)
{
	uint16_t de = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	z80_block(33);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		fm_effect_2e_setup(ix);
		return;
	}
	z80_block(62);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	de = 0xFF00u;
	if (t2 != 1u)
	{
		fm_effect_2e_transpose(de, ix);
		return;
	}
	z80_block(33);
	t3 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t3 - 1u);
	if (t3 != 1u)
	{
		fm_effect_2e_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_2e_transpose(uint16_t de, uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint16_t t1 = 0;

	z80_block(97);
	t1 = z80_read16((uint16_t)(ix + 2u)) + de;
	h = (uint8_t)(t1 >> 8);
	l = (uint8_t)t1;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	fm_effect_2e_slide(hl, ix);
}

void fm_effect_2e_setup(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(38);
	hl = z80_read16((uint16_t)(ix + 2u));
	fm_effect_2e_slide(hl, ix);
}

void fm_effect_2e_slide(uint16_t hl, uint16_t ix)
{
	z80_block(30);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 5) & 1u)
	{
		z80_block(21);
		hl += 0x700u;
	}
	z80_block(10);
	set_pitch(hl, ix);
}

void fm_effect_2f(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x23E6u;
	load_patch(hl, ix);
	z80_block(38);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 4u), 0xBu);
	fm_effect_2f_retrigger(ix);
}

void fm_effect_2f_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1400u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x14u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_2f_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_2f_slide(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) - 0xCu;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	a = z80_read8((uint16_t)(ix + 4u)) + 0xBu;
	z80_write8((uint16_t)(ix + 4u), a);
	set_volume(ix, a);
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_2f_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_32(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x20u);
	hl = fm_effect_32_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_32_delay(uint16_t ix)
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
	fm_effect_31(ix);
}

void fm_effect_31(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x50u);
	hl = fm_effect_31_delay_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_31_delay(uint16_t ix)
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
	fm_effect_30(ix);
}

void fm_effect_30(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x245Cu;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 4u);
	fm_effect_30_retrigger(ix);
}

void fm_effect_30_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = 0x1200u;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x12u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 8u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_30_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_30_retrigger_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = z80_read8((uint16_t)(ix + 4u));
		z80_write8((uint16_t)(ix + 4u), t3 - 1u);
		if (t3 != 1u)
		{
			fm_effect_30_retrigger(ix);
			return;
		}
		z80_block(10);
		stop_channel(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(114);
	t4 = z80_read16((uint16_t)(ix + 2u)) - 0x80u;
	h = (uint8_t)(t4 >> 8);
	l = (uint8_t)t4;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_33(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x24E8u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 4u);
	fm_effect_33_retrigger(ix);
}

void fm_effect_33_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = fm_effect_05_ADDRESS;
	z80_write8((uint16_t)(ix + 2u), 8u);
	z80_write8((uint16_t)(ix + 3u), 0x12u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(58);
	z80_write8(ix, 8u);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	hl = fm_effect_33_retrigger_2_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_33_retrigger_2(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(52);
	z80_write8((uint16_t)(ix + 1u), 0x30u);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 == 1u)
	{
		z80_block(33);
		t3 = z80_read8((uint16_t)(ix + 4u));
		z80_write8((uint16_t)(ix + 4u), t3 - 1u);
		if (t3 != 1u)
		{
			fm_effect_33_retrigger(ix);
			return;
		}
		z80_block(10);
		stop_channel(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(114);
	t4 = z80_read16((uint16_t)(ix + 2u)) - 0x80u;
	h = (uint8_t)(t4 >> 8);
	l = (uint8_t)t4;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
	z80_block(10);
	key_on(ix);
}

void fm_effect_34(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2558u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 2u);
	fm_effect_34_setup(ix);
}

void fm_effect_34_setup(uint16_t ix)
{
	z80_block(19);
	z80_write8(ix, 8u);
	fm_effect_34_retrigger(ix);
}

void fm_effect_34_retrigger(uint16_t ix)
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
	hl = fm_effect_34_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_34_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
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
		fm_effect_34_retrigger(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(33);
	t4 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t4 - 1u);
	if (t4 != 1u)
	{
		fm_effect_34_setup(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_35(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(39);
	z80_write8(ix, 0x20u);
	hl = fm_effect_35_note_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_35_note(uint16_t ix)
{
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
	hl = 0x25C1u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 2u);
	fm_effect_35_setup(ix);
}

void fm_effect_35_setup(uint16_t ix)
{
	z80_block(19);
	z80_write8(ix, 8u);
	fm_effect_35_retrigger(ix);
}

void fm_effect_35_retrigger(uint16_t ix)
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
	hl = fm_effect_35_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_35_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
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
		fm_effect_35_retrigger(ix);
		return;
	}
	z80_block(17);
	key_off(ix);
	z80_block(33);
	t4 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t4 - 1u);
	if (t4 != 1u)
	{
		fm_effect_35_setup(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_36(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2638u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 0x18u);
	fm_effect_36_retrigger(ix);
}

void fm_effect_36_retrigger(uint16_t ix)
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
	hl = fm_effect_36_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_36_slide(uint16_t ix)
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
	t3 = z80_read8((uint16_t)(ix + 4u));
	z80_write8((uint16_t)(ix + 4u), t3 - 1u);
	if (t3 != 1u)
	{
		fm_effect_36_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}

void fm_effect_37(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x2694u;
	load_patch(hl, ix);
	z80_block(19);
	z80_write8((uint16_t)(ix + 4u), 5u);
	fm_effect_37_retrigger(ix);
}

void fm_effect_37_retrigger(uint16_t ix)
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
	hl = fm_effect_37_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_37_slide(uint16_t ix)
{
	uint8_t h = 0, l = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

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
		z80_block(33);
		t3 = z80_read8((uint16_t)(ix + 4u));
		z80_write8((uint16_t)(ix + 4u), t3 - 1u);
		if (t3 != 1u)
		{
			fm_effect_37_retrigger(ix);
			return;
		}
		z80_block(10);
		stop_channel(ix);
		return;
	}
	z80_block(107);
	t4 = z80_read16((uint16_t)(ix + 2u)) + 0x40u;
	h = (uint8_t)(t4 >> 8);
	l = (uint8_t)t4;
	z80_write8((uint16_t)(ix + 2u), l);
	z80_write8((uint16_t)(ix + 3u), h);
	hl = ((uint32_t)h << 8) | l;
	set_pitch(hl, ix);
}

void fm_effect_38(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(27);
	hl = 0x26FEu;
	load_patch(hl, ix);
	z80_block(38);
	z80_write8(ix, 4u);
	z80_write8((uint16_t)(ix + 4u), 8u);
	fm_effect_38_retrigger(ix);
}

void fm_effect_38_retrigger(uint16_t ix)
{
	uint16_t hl = 0;

	z80_block(65);
	hl = pcm_voice_playing_ADDRESS;
	z80_write8((uint16_t)(ix + 2u), 0u);
	z80_write8((uint16_t)(ix + 3u), 0x10u);
	set_pitch(hl, ix);
	z80_block(17);
	key_on(ix);
	z80_block(39);
	z80_write8((uint16_t)(ix + 1u), 0x40u);
	hl = fm_effect_38_slide_ADDRESS;
	set_channel_handler(hl, ix);
}

void fm_effect_38_slide(uint16_t ix)
{
	uint8_t a = 0;
	uint16_t hl = 0;
	uint8_t t1 = 0, t2 = 0;

	z80_block(127);
	hl = z80_read16((uint16_t)(ix + 2u)) - 0x10u;
	z80_write16((uint16_t)(ix + 2u), hl);
	if ((z80_read8((uint16_t)(ix + 1u)) >> 4) & 1u)
	{
		z80_block(21);
		hl += 0x300u;
	}
	z80_block(17);
	set_pitch(hl, ix);
	z80_block(28);
	t1 = z80_read8((uint16_t)(ix + 1u));
	z80_write8((uint16_t)(ix + 1u), t1 - 1u);
	if (t1 != 1u)
	{
		z80_cycles(6);
		return;
	}
	z80_block(62);
	a = z80_read8((uint16_t)(ix + 4u)) + 8u;
	z80_write8((uint16_t)(ix + 4u), a);
	set_volume(ix, a);
	z80_block(33);
	t2 = z80_read8(ix);
	z80_write8(ix, t2 - 1u);
	if (t2 != 1u)
	{
		fm_effect_38_retrigger(ix);
		return;
	}
	z80_block(10);
	stop_channel(ix);
}
