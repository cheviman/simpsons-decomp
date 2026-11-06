/**
 *    Name:        unsorted/bank_2F.c
 *    Description: bank 2F's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_05E000(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	a = 0u;
	b = 0u;
	do
	{
		d = ((uint32_t)a << 8) | b;
		sub_05E8F1(d);
		t1 = (((uint32_t)a << 8) | b) + 0x101u;
		a = (uint8_t)(t1 >> 8);
		b = (uint8_t)t1;
	} while (a < 0x80u);
	unk_48F0 = 0u;
	a = 0u;
	do
	{
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		d = sub_05E915(d);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		if (b != unk_48F0)
		{
			d = 0x100u | b;
			return d;
		}
		a++;
		unk_48F0++;
	} while (a < 0x80u);
	d = b;
	return d;
}

void unused_05E003(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_05EA57(&ignored16, &ignored16_2);
}

void sub_05E006(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	sub_05EA46(&ignored16, &ignored16_2);
}

void sub_05E009(uint16_t y, uint16_t d)
{
	uint8_t a = 0;
	uint16_t x = 0;

	disable_irq();
	io_write8(VIDEO_1D00, 0xFBu);
	x = loaded_table_05F580_ADDRESS;
	a = (uint32_t)unk_5908 << 1;
	d |= (uint32_t)a << 8;
	switch ((int8_t)a)
	{
	case 0:
		sub_05E042(y, d);
		break;
	case 2:
		sub_05E09B(y, d);
		break;
	case 4:
		sub_05E0C3(y, d);
		break;
	case 6:
		sub_05E0EC(y, d);
		break;
	case 8:
		sub_05E177(y, d);
		break;
	case 10:
		sub_05E215(y, d);
		break;
	case 12:
		sub_05E271(y, d);
		break;
	case 14:
		sub_05E2AA();
		break;
	case 16:
		sub_05E2C3(y, d);
		break;
	case 18:
		sub_05E3A7();
		break;
	case 20:
		sub_05E3B0(x, d);
		break;
	case 22:
	case 24:
		sub_05E3FB();
		break;
	case 26:
		sub_05E403();
		break;
	case 28:
		sub_05E40B();
		break;
	case 30:
		sub_05E413();
		break;
	case 32:
		sub_05E420();
		break;
	case 34:
		sub_05E467(y, d);
		break;
	case 36:
		sub_05E484();
		break;
	case 38:
		sub_05E4D6();
		break;
	case 40:
		sub_05E4DE();
		break;
	case 42:
		sub_05E4F5();
		break;
	case 44:
		sub_05E4F9();
		break;
	}
	enable_irq();
	take_interrupts();
	io_write8(VIDEO_1D00, 0xFFu);
}

uint16_t sub_05E00C(void)
{
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;

	sub_05EA91();
	d_2 = (d & 0xFFu) | 0x7E00u;
	d_2 = sub_05E915(d_2);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	stack = b;
	d_2 = (d_2 & 0xFFu) | ((uint32_t)(uint8_t)(a + 1u) << 8);
	d_2 = sub_05E915(d_2);
	b = (uint8_t)d_2;
	a = stack;
	if ((uint16_t)(((uint32_t)a << 8) | b) == (((uint32_t)unk_48F0 << 8u) | unk_48F1))
	{
		d_2 = (uint32_t)a << 8;
		return d_2;
	}
	d_2 = ((uint32_t)a << 8) | 3u;
	return d_2;
}

void sub_05E00F(void)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0;
	uint16_t t1 = 0;

	u = 0x59F0u;
	a = 0x68u;
	do
	{
		d = (d & 0xFFu) | ((uint32_t)a << 8);
		d = sub_05E915(d);
		a = (uint8_t)(d >> 8);
		t1 = u;
		u = t1 + 1u;
		mem_write8(t1, (uint8_t)d);
		a++;
	} while (a < 0x7Eu);
}

uint16_t sub_05E012(uint16_t d)
{
	return sub_05E915(d);
}

void sub_05E015(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0;

	unk_4872 = 0u;
	sub_05EDB4();
	x = loaded_table_05FD78_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)(uint8_t)(unk_4805 >> 8u) << 1))
	{
	case 0:
		sub_05EE08(u);
		break;
	case 2:
		sub_05EEAB();
		break;
	case 4:
		sub_05EEDA(x, u);
		break;
	case 6:
		sub_05EF1B(x, u);
		break;
	case 8:
		sub_05EF2C(x);
		break;
	case 10:
		sub_05EF3F(x, u);
		break;
	case 12:
		sub_05EF89(x);
		break;
	case 14:
		sub_05EF9D(x);
		break;
	}
	a = unk_4878;
	carry = (uint8_t)(a + 1u) < a;
	a++;
	if (carry)
		a = 0xFFu;
	unk_4878 = a;
	if (a < 0x20u)
		return;
	x = unk_4842_ADDRESS;
	unk_48F0 = 1u;
	unk_48F1 = 4u;
	do
	{
		if ((unk_485B & unk_48F0) != 0u)
		{
			if (unk_483B != 0u)
			{
				if ((mem_read8(x) & 0xB0u) != 0u)
				{
					unk_4878 = 0u;
					unk_4872++;
				}
			}
			else if ((mem_read8(x) & 0xB0u) != 0u)
			{
				unk_4878 = 0u;
				unk_4872++;
			}
		}
		x += 4u;
		unk_48F0 = (uint32_t)unk_48F0 << 1;
		t1 = unk_48F1;
		unk_48F1 = t1 - 1u;
	} while (t1 != 1u);
}

void sub_05E042(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E047_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E04B(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	a = unk_480F | 1u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	b = 8u;
	y = test_mode_palettes_ADDRESS;
	do
	{
		t1 = y;
		y = t1 + 2u;
		x = mem_read16(t1);
		u = 0x20u;
		while (u != 0u)
		{
			mem_write8(x, mem_read8(y));
			y++;
			x++;
			u--;
		}
		t2 = b;
		b = t2 - 1u;
	} while (t2 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	sub_05E733();
	sub_07869B(&x, &ignored16);
	a = 0u;
	d = 0u;
	carry = sub_05E62A(x, d);
	y = 0x5A60u;
	d = (uint32_t)a << 8;
	sub_05E60A(&ignored16_2, &y, &d, &zero);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	x = 0x255Bu;
	u = test_mode_text_05FB5A_ADDRESS;
	if (b != 0u)
		u = test_mode_text_05FB52_ADDRESS;
	b = 0u;
	d_2 = 0u;
	sub_05E650(d_2, &x, &u, &carry);
	d = ((uint32_t)a << 8) | b;
	*p_d = d;
	*p_carry = carry;
}

void sub_05E09B(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E0A1_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E0A5(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;

	unk_5A10 = 0u;
	d_2 = (d & 0xFFu) | 0x100u;
	carry = sub_05E62A(x, d_2);
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}

void unreached_05E0AE(void)
{
	unk_5909++;
}

void sub_05E0B3(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t ignored16 = 0, x = 0;

	x = VIDEO_26DD;
	io_write8(VIDEO_26DD, 0x10u);
	sub_05E5BD(x, &ignored16, &d);
	d = sub_05EAB0(d);
	*p_d = d;
	sub_05E506(p_d, &carry);
	*p_carry = carry;
}

void sub_05E0C3(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E0C9_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E0CD(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	u = 0x2F2Eu;
	y = 0x2D2Cu;
	x = 0x2800u;
	a = 0xEu;
	do
	{
		b = 0x14u;
		do
		{
			mem_write16(x + 0x40u, y);
			t1 = x;
			x = t1 + 2u;
			mem_write16(t1, u);
			t2 = b;
			b = t2 - 1u;
		} while (t2 != 1u);
		x += 0x58u;
		t3 = a;
		a = t3 - 1u;
	} while (t3 != 1u);
	d = 0x200u | b;
	carry = sub_05E62A(x, d);
	*p_d = d;
	*p_carry = carry;
}

void sub_05E0EC(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E0F2_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E0F6(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	a = 0x31u;
	x = 0x2190u;
	unk_48F0 = 8u;
	do
	{
		unk_48F1 = 6u;
		do
		{
			unk_48F2 = 4u;
			b = 0x80u;
			do
			{
				d = ((uint32_t)a << 8) | b;
				x = sub_05E6FD(x, d);
				t1 = unk_48F2;
				unk_48F2 = t1 - 1u;
			} while (t1 != 1u);
			x += 0x3Cu;
			t2 = unk_48F1;
			unk_48F1 = t2 - 1u;
		} while (t2 != 1u);
		a++;
		x -= 0x17Cu;
		t3 = unk_48F0;
		unk_48F0 = t3 - 1u;
	} while (t3 != 1u);
	x = 0x3344u;
	d = 0x3000u;
	sub_05E14F(&x, &d);
	x = 0x3404u;
	d = 0x3040u;
	sub_05E14F(&x, &d);
	x = 0x34C4u;
	d = 0x3080u;
	sub_05E14F(&x, &d);
	x = 0x3584u;
	d = 0x30C0u;
	sub_05E14F(&x, &d);
	b = (uint8_t)d;
	d = 0x300u | b;
	carry = sub_05E62A(x, d);
	*p_d = d;
	*p_carry = carry;
}

void sub_05E14F(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	stack = (uint8_t)d;
	stack_2 = d >> 8;
	unk_48F0 = 0x10u;
	do
	{
		unk_48F1 = 2u;
		do
		{
			t1 = ((uint32_t)stack_2 << 8) | stack;
			a = (uint8_t)(t1 >> 8);
			b = (uint8_t)t1;
			d_2 = ((uint32_t)a << 8) | b;
			x = sub_05E6FD(x, d_2);
			d_2 = ((uint32_t)a << 8) | b;
			x = sub_05E6FD(x, d_2);
			x += 0x3Eu;
			t2 = unk_48F1;
			unk_48F1 = t2 - 1u;
		} while (t2 != 1u);
		x -= 0x7Eu;
		stack_2 = stack_2 + 1u;
		t3 = unk_48F0;
		unk_48F0 = t3 - 1u;
	} while (t3 != 1u);
	d_2 = ((uint32_t)stack_2 << 8) | stack;
	*p_x = x;
	*p_d = d_2;
}

void sub_05E177(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E17D_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E181(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint16_t d_2 = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	y = 0x5A60u;
	sub_05E60A(&x, &y, &d, &zero);
	if (zero == 0u)
	{
		d_2 = (d & 0xFFu) | 0x1700u;
		carry = sub_05E62A(x, d_2);
		d_2 = 0x1010u;
		io_write16(VIDEO_24E2, 0x1010u);
		t1 = 0x24E4u;
		io_write16(t1, 0x1010u);
		t2 = t1 + 7u;
		mem_write16(t2, 0x1010u);
		mem_write16(t2 + 2u, 0x1010u);
	}
	else
	{
		d_2 = (d & 0xFFu) | 0x400u;
		carry = sub_05E62A(x, d_2);
	}
	*p_d = d_2;
	*p_carry = carry;
}

void sub_05E1A5(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t d_2 = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	y = IO_1F90;
	x = 0x22CCu;
	b = 4u;
	unk_48F0 = unk_483D;
	do
	{
		t1 = y;
		y = t1 + 1u;
		a = mem_read8(t1);
		x += 9u;
		stack_2 = x >> 8;
		stack = (uint8_t)x;
		stack_3 = b;
		b = 6u;
		do
		{
			stack_4 = b;
			b = 0u;
			carry = (a >> 0) & 1u;
			a = a >> 1;
			if (carry == 0u)
				b++;
			d = b;
			x = sub_05E204(x, d);
			t2 = stack_4;
			b = t2 - 1u;
		} while (t2 != 1u);
		x += 0x40u;
		stack_5 = y >> 8;
		stack_4 = (uint8_t)y;
		y = 0x5A60u;
		d_2 = (uint32_t)a << 8;
		sub_05E60A(&x, &y, &d_2, &zero);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		y = ((uint32_t)stack_5 << 8) | stack_4;
		stack_4 = b;
		if (zero || (int8_t)stack_3 > 2)
		{
			b = 0u;
			t3 = unk_48F0;
			carry = (t3 >> 0) & 1u;
			unk_48F0 = t3 >> 1;
			if (carry)
				b++;
			d = b;
			x = sub_05E204(x, d);
		}
		else
			x += 0x40u;
		if (stack_4 != 0u)
		{
			b = 0u;
			carry = ((a >> 1) >> 0) & 1u;
			if (carry == 0u)
				b++;
			d = b;
			sub_05E204(x, d);
		}
		x = ((uint32_t)stack_2 << 8) | stack;
		t4 = stack_3;
		b = t4 - 1u;
	} while (t4 != 1u);
	d_2 = b;
	*p_d = d_2;
	sub_05E506(p_d, &carry);
	*p_carry = carry;
}

uint16_t sub_05E204(uint16_t x, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	mem_write8(x + 0x40u, b);
	carry = 0u;
	unk_48F1 = 0u;
	t1 = (b >> 1) | (carry << 7);
	carry = (b >> 0) & 1u;
	b = t1;
	t2 = (b >> 1) | (carry << 7);
	carry = (b >> 0) & 1u;
	mem_write8(x - 0x1FC0u, (t2 >> 1) | (carry << 7));
	x += 0x40u;
	return x;
}

void sub_05E215(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E21B_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E223(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	sub_05E261(&d, &carry);
	if (carry)
		sub_05E23E(&d, &carry);
	*p_d = d;
	*p_carry = carry;
}

void sub_05E229(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;

	sub_05E506(&d, &carry);
	if (carry)
	{
		x = unk_5915_ADDRESS;
		d = (d & 0xFFu) | 0x3000u;
		d = sub_05E248(x, d);
		sub_05E235(x, &d, &carry);
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_05E235(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;

	d_2 = (d & 0xFFu) | 0x500u;
	carry = sub_05E62A(x, d_2);
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}

void sub_05E23A(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	unk_5909--;
	*p_d = d;
	sub_05E23E(p_d, &carry);
	*p_carry = carry;
}

void sub_05E23E(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	a = unk_5915;
	x = 0x68EFu;
	a -= 0x30u;
	d = DATA16(x + (int8_t)a + (int8_t)a);
	carry = sub_078680(d);
	*p_d = d;
	*p_carry = carry;
}

uint16_t sub_05E248(uint16_t x, uint16_t d)
{
	uint8_t a = 0;
	uint8_t stack = 0;

	a = (uint8_t)(d >> 8);
	if ((uint8_t)d != 0u)
	{
		unk_5917 = 0xFAu;
		return sub_05E733();
	}
	stack = a;
	a = mem_read8(x) + 1u;
	if (stack < a)
		a = 0u;
	mem_write8(x, a);
	unk_5917 = 0xFAu;
	return sub_05E733();
}

void sub_05E261(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0;

	sub_05E506(&d, &carry);
	a = (uint8_t)(d >> 8);
	if (carry)
	{
		a = 0xFAu;
		unk_5917 = 0xFAu;
		unk_5909++;
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	*p_d = d_2;
	*p_carry = carry;
}

void sub_05E271(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E277_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E27F(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	sub_05E261(&d, &carry);
	if (carry)
		sub_05E2A0(&d, &carry);
	*p_d = d;
	*p_carry = carry;
}

void sub_05E285(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t x = 0;
	uint8_t t1 = 0;

	t1 = unk_5917;
	unk_5917 = t1 - 1u;
	if (t1 == 1u)
	{
		x = unk_5916_ADDRESS;
		d = (d & 0xFFu) | 0xAA00u;
		d = sub_05E248(x, d);
		sub_05E297(x, &d, &carry);
	}
	else
	{
		sub_05E506(&d, &carry);
		if (carry)
		{
			x = unk_5916_ADDRESS;
			d = (d & 0xFFu) | 0xAA00u;
			d = sub_05E248(x, d);
			sub_05E297(x, &d, &carry);
		}
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_05E297(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;

	d_2 = (d & 0xFFu) | 0x600u;
	carry = sub_05E62A(x, d_2);
	*p_d = (*p_d & 0xFFu) | d_2;
	*p_carry = carry;
}

void sub_05E29C(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0;

	unk_5909--;
	*p_d = d;
	sub_05E2A0(p_d, &carry);
	*p_carry = carry;
}

void sub_05E2A0(uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	a = unk_5916;
	x = 0x6799u;
	a -= 0x30u;
	d = DATA16(x + (int8_t)a + (int8_t)a);
	carry = sub_078680(d);
	*p_d = d;
	*p_carry = carry;
}

void sub_05E2AA(void)
{
	uint32_t carry = 0;
	uint8_t b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A60u;
	d = 7u;
	sub_05E425(y, &d, &carry);
	b = (uint8_t)d;
	if (carry == 0u || b == 0u)
		return;
	y = 0x5A62u;
	d_2 = 0u;
	sub_05E5E8(y, d_2);
	unk_591B = 0u;
}

void sub_05E2C3(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E2C9_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E2CD(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0;

	t1 = d >> 8;
	a = t1 - 1u;
	if (t1 == 1u)
		d_2 = (uint32_t)a << 8;
	else
	{
		d_2 = 0x2300u;
		x = sub_05E6FD(x, d_2);
	}
	*p_x = x;
	*p_d = (*p_d & 0xFFu) | d_2;
}

uint16_t sub_05E2D6(uint16_t x, uint16_t d)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0, d_3 = 0;
	uint16_t d_2 = 0, u = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;

	y = 0x5A59u;
	sub_05E60A(&x, &y, &d, &zero);
	b = (uint8_t)d;
	stack = b;
	a = DATA8(rom_05FA5D_ADDRESS + (int8_t)b) - 0x30u;
	if (unk_48F0 == 0u)
	{
		y = 0x5A62u;
		d_2 = (uint32_t)a << 8;
		sub_05E60A(&x, &y, &d_2, &zero);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		stack_2 = b;
		a += stack_2;
	}
	b = 0u;
	d_2 = (uint32_t)a << 8;
	x = sub_05E6FD(x, d_2);
	x++;
	u = test_mode_text_05FA9B_ADDRESS;
	d_3 = b;
	sub_05E650(d_3, &x, &u, &carry);
	d_2 = ((uint32_t)a << 8) | b;
	sub_05E2CD(&x, &d_2);
	x++;
	a = DATA8(rom_05FA6F_ADDRESS + (int8_t)stack) - 0x30u;
	d_2 = ((uint32_t)a << 8) | b;
	x = sub_05E6FD(x, d_2);
	u = test_mode_text_05FAA0_ADDRESS;
	d_3 = b;
	sub_05E650(d_3, &x, &u, &carry);
	d_2 = ((uint32_t)a << 8) | b;
	sub_05E2CD(&x, &d_2);
	return d_2;
}

void sub_05E31B(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, d_3 = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0, x = 0, y = 0;

	x = 0x219Fu;
	unk_48F0 = 0u;
	d = sub_05E2D6(x, d);
	x = 0x21DFu;
	unk_48F0++;
	d = sub_05E2D6(x, d);
	y = 0x5A5Du;
	sub_05E60A(&ignored16, &y, &d, &zero);
	b = (uint8_t)d;
	x = 0x229Fu;
	a = (uint16_t)(((uint32_t)a << 8) | b) + 1u;
	b = 0u;
	d_2 = (uint32_t)a << 8;
	x = sub_05E6FD(x, d_2);
	u = test_mode_text_05F984_ADDRESS;
	d_3 = b;
	sub_05E650(d_3, &x, &u, &carry);
	d_2 = ((uint32_t)a << 8) | b;
	sub_05E2CD(&x, &d_2);
	y = 0x5A5Cu;
	sub_05E60A(&ignored16, &y, &d_2, &zero);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	x = 0x235Fu;
	u = DATA16(0x7935u + (int8_t)((uint32_t)b << 1));
	d_3 = 0u;
	sub_05E650(d_3, &x, &u, &carry);
	y = 0x5A5Eu;
	d_2 = (uint32_t)a << 8;
	sub_05E60A(&ignored16, &y, &d_2, &zero);
	a = (uint8_t)(d_2 >> 8);
	x = 0x241Fu;
	sub_05E399(x, (uint8_t)d_2);
	y = 0x5A5Fu;
	d_2 = (uint32_t)a << 8;
	sub_05E60A(&ignored16, &y, &d_2, &zero);
	a = (uint8_t)(d_2 >> 8);
	b = (uint8_t)d_2;
	x = 0x24DFu;
	u = test_mode_text_05FABA_ADDRESS;
	if (b != 0u)
		u = test_mode_text_05FB3D_ADDRESS;
	d_3 = 0u;
	sub_05E650(d_3, &x, &u, &carry);
	y = 0x5A61u;
	d_2 = (uint32_t)a << 8;
	sub_05E60A(&ignored16, &y, &d_2, &zero);
	b = (uint8_t)d_2;
	x = 0x259Fu;
	u = test_mode_text_05FADE_ADDRESS;
	if (b != 0u)
		u = test_mode_text_05FAE7_ADDRESS;
	b = 0u;
	d_3 = 0u;
	sub_05E650(d_3, &x, &u, &carry);
	d_2 = 0x800u | b;
	carry = sub_05E62A(x, d_2);
	*p_d = d_2;
	*p_carry = carry;
}

void sub_05E399(uint16_t x, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t u = 0;

	u = loaded_table_05FB68_ADDRESS;
	if ((uint8_t)d != 0u)
		u = loaded_table_05FB65_ADDRESS;
	d_2 = 0u;
	sub_05E650(d_2, &x, &u, &carry);
}

void sub_05E3A7(void)
{
	sub_078659();
	switch (rom_07FFFE[0])
	{
	case 0x86CEu:
		break;
	}
	sub_0786CE();
}

void sub_05E3B0(uint16_t x, uint16_t d)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, y = 0;

	y = 0x5A60u;
	sub_05E60A(&x, &y, &d, &zero);
	if (zero == 0u)
	{
		y = 0x5A59u;
		d_2 = 0xAu;
		sub_05E425(y, &d_2, &carry);
		return;
	}
	y = 0x5A62u;
	sub_05E60A(&x, &y, &d, &zero);
	b = (uint8_t)d;
	if (zero)
		a = 0x13u;
	else
	{
		unk_591B = 1u;
		d = 0x1400u | (uint8_t)(b - 2u);
		x = sub_05E3EF(x, d);
		a = 0x15u;
	}
	d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
	sub_05E3E9(x, d_2);
	unk_5909 = 0u;
	unk_5908 = 0x12u;
}

void sub_05E3E9(uint16_t x, uint16_t d)
{
	uint32_t zero = 0;
	uint16_t y = 0;

	y = 0x5A59u;
	sub_05E60A(&x, &y, &d, &zero);
	sub_05E3EF(x, d);
}

uint16_t sub_05E3EF(uint16_t x, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t d_2 = 0;

	unk_5908 = d >> 8;
	carry = sub_05E62A(x, d);
	d_2 = (d & 0xFFu) | 0x4000u;
	return sub_05E5A7(d_2);
}

void sub_05E3FB(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A5Du;
	d = 0xCu;
	sub_05E425(y, &d, &carry);
}

void sub_05E403(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A5Cu;
	d = 0xDu;
	sub_05E425(y, &d, &carry);
}

void sub_05E40B(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A5Eu;
	d = 0xEu;
	sub_05E425(y, &d, &carry);
}

void sub_05E413(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A5Fu;
	d = 0xFu;
	sub_05E425(y, &d, &carry);
	b = (uint8_t)d;
	io_write8(VIDEO_1E80, b);
}

void sub_05E420(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A61u;
	d = 0x10u;
	sub_05E425(y, &d, &carry);
}

void sub_05E425(uint16_t y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t x = 0;

	x = loaded_table_05E42B_ADDRESS;
	a = unk_5909;
	carry = (int8_t)a < 0;
	a = (uint32_t)a << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&d, &carry);
		break;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&d, &carry);
		break;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &d, &carry);
		break;
	case 0x60A3u:
		sub_05E0B3(&d, &carry);
		break;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&d, &carry);
		break;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&d, &carry);
		break;
	case loaded_table_05E17D_ADDRESS:
		d = (uint32_t)a << 8;
		sub_05E181(x, &d, &carry);
		break;
	case 0x617Fu:
		sub_05E1A5(&d, &carry);
		break;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &d, &carry);
		break;
	case 0x621Du:
		sub_05E223(&d, &carry);
		break;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		break;
	case 0x6221u:
		sub_05E23A(&d, &carry);
		break;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &d, &carry);
		break;
	case 0x6279u:
		sub_05E27F(&d, &carry);
		break;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		break;
	case 0x627Du:
		sub_05E29C(&d, &carry);
		break;
	case 0x627Fu:
		d |= (uint32_t)a << 8;
		sub_07AAE0();
		break;
	case loaded_table_05E2C9_ADDRESS:
		d = (uint32_t)a << 8;
		sub_05E31B(&d, &carry);
		break;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		break;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		break;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &d, &carry);
		break;
	case 0x646Fu:
		sub_05E481(&d, &carry);
		break;
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_05E42F(uint16_t x, uint16_t y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0;
	uint16_t d_2 = 0, y_2 = 0;
	uint16_t stack = 0;

	stack = y;
	d = (d & 0xFFu) | ((uint32_t)(uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) << 8);
	carry = sub_05E62A(x, d);
	y_2 = stack;
	d_2 = unk_4000_ADDRESS;
	sub_05E461(&y_2, &d_2);
	*p_d = d_2;
	sub_05E43C(y_2, p_d, &carry);
	*p_carry = carry;
}

void sub_05E43C(uint16_t y, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;
	uint32_t zero = 0;
	uint8_t a = 0, b = 0, d_3 = 0;
	uint16_t d_2 = 0, ignored16 = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0;

	stack_2 = y >> 8;
	stack = (uint8_t)y;
	sub_05E506(&d, &carry);
	b = (uint8_t)d;
	y_2 = ((uint32_t)stack_2 << 8) | stack;
	if (carry == 0u)
	{
		d_2 = unk_4000_ADDRESS;
		sub_05E461(&y_2, &d_2);
		b = (uint8_t)d_2;
		carry = 0u;
		d_2 = b;
	}
	else
	{
		stack = b;
		d_2 = 0u;
		sub_05E60A(&ignored16, &y_2, &d_2, &zero);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		d_2 = ((uint32_t)a << 8) | b;
		sub_05E5A7(d_2);
		d_3 = (uint8_t)(stack - 1u);
		y_2 = sub_05E5E8(y_2, d_3);
		d_2 = unk_4000_ADDRESS;
		sub_05E461(&y_2, &d_2);
		a = (uint8_t)(d_2 >> 8);
		b = (uint8_t)d_2;
		carry = 1u;
		d_2 = ((uint32_t)(uint8_t)~a << 8) | b;
	}
	*p_d = d_2;
	*p_carry = carry;
}

void sub_05E461(uint16_t *p_y, uint16_t *p_d)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t zero = 0;
	uint16_t ignored16 = 0;

	sub_05E60A(&ignored16, &y, &d, &zero);
	sub_05E5A7(d);
	*p_y = y;
	*p_d = d;
}

void sub_05E467(uint16_t y, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;

	x = loaded_table_05E46D_ADDRESS;
	a = (uint32_t)unk_5909 << 1;
	switch ((uint16_t)(x + (int8_t)a))
	{
	case loaded_table_05E047_ADDRESS:
		sub_05E04B(&ignored16, &carry);
		return;
	case 0x6049u:
	case 0x60CBu:
	case 0x60F4u:
	case 0x62CBu:
		sub_05E506(&ignored16, &carry);
		return;
	case loaded_table_05E0A1_ADDRESS:
		sub_05E0A5(x, &ignored16, &carry);
		return;
	case 0x60A3u:
		sub_05E0B3(&ignored16, &carry);
		return;
	case loaded_table_05E0C9_ADDRESS:
		sub_05E0CD(&ignored16, &carry);
		return;
	case loaded_table_05E0F2_ADDRESS:
		sub_05E0F6(&ignored16, &carry);
		return;
	case loaded_table_05E17D_ADDRESS:
		sub_05E181(x, &ignored16, &carry);
		return;
	case 0x617Fu:
		sub_05E1A5(&ignored16, &carry);
		return;
	case loaded_table_05E21B_ADDRESS:
		sub_05E235(x, &ignored16, &carry);
		return;
	case 0x621Du:
		sub_05E223(&ignored16, &carry);
		return;
	case 0x621Fu:
		sub_05E229(&d, &carry);
		return;
	case 0x6221u:
		sub_05E23A(&ignored16, &carry);
		return;
	case loaded_table_05E277_ADDRESS:
		sub_05E297(x, &ignored16, &carry);
		return;
	case 0x6279u:
		sub_05E27F(&ignored16, &carry);
		return;
	case 0x627Bu:
		sub_05E285(&d, &carry);
		return;
	case 0x627Du:
		sub_05E29C(&ignored16, &carry);
		return;
	case 0x627Fu:
		sub_07AAE0();
		return;
	case loaded_table_05E2C9_ADDRESS:
		d_2 = (uint32_t)a << 8;
		sub_05E31B(&d_2, &carry);
		return;
	case loaded_table_05E42B_ADDRESS:
		sub_05E42F(x, y, &d, &carry);
		return;
	case 0x642Du:
		sub_05E43C(y, &d, &carry);
		return;
	case loaded_table_05E46D_ADDRESS:
		sub_05E471(x, &ignored16, &carry);
		return;
	case 0x646Fu:
		sub_05E481(&ignored16, &carry);
		return;
	}
}

void sub_05E471(uint16_t x, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint8_t b = 0, d = 0;
	uint16_t d_2 = 0, u = 0, x_2 = 0;

	u = test_mode_text_05FAEE_ADDRESS;
	d = 0u;
	sub_05E650(d, &x, &u, &carry);
	sub_05EA46(&x_2, &d_2);
	b = (uint8_t)d_2;
	d_2 = 0x1100u | b;
	carry = sub_05E62A(x_2, d_2);
	*p_d = d_2;
	*p_carry = carry;
}

void sub_05E481(uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t carry = *p_carry;

	*p_d = d;
	sub_05E506(p_d, &carry);
	*p_carry = carry;
}

void sub_05E484(void)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0;

	y = unk_591B_ADDRESS;
	d = 0x12u;
	sub_05E425(y, &d, &carry);
	b = (uint8_t)d;
	if (carry == 0u)
		return;
	y = 0x5A62u;
	if (b != 0u)
	{
		sub_05E60A(&ignored16, &y, &d, &zero);
		b = (uint8_t)d;
		if (zero)
			b++;
		unk_591C = b - 2u;
		b = 0x14u;
	}
	else
	{
		stack = b;
		sub_05E60A(&ignored16, &y, &d, &zero);
		b = stack;
		if (zero == 0u)
		{
			d = b;
			sub_05E5E8(y, (uint8_t)d);
		}
		b = 0x13u;
	}
	x = 0x22CCu;
	a = 0x10u;
	u = 0x600u;
	while (u != 0u)
	{
		mem_write8(x, a);
		x++;
		u--;
	}
	if (b != 0x14u)
	{
		unk_5908 = b;
		unk_5909 = 0u;
		unk_5913 = 0u;
		return;
	}
	stack = b;
	d = (d & 0xFFu) | 0x1500u;
	sub_05E3E9(x, d);
	b = stack;
	unk_5908 = b;
	unk_5909 = 0u;
	unk_5913 = 0u;
}

void sub_05E4D6(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;

	y = 0x5A59u;
	d = 0x13u;
	sub_05E425(y, &d, &carry);
}

void sub_05E4DE(void)
{
	uint32_t carry = 0;
	uint8_t b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;

	y = unk_591C_ADDRESS;
	d = 0x14u;
	sub_05E425(y, &d, &carry);
	b = (uint8_t)d;
	if (carry == 0u)
		return;
	y = 0x5A62u;
	d_2 = (uint8_t)(b + 2u);
	sub_05E5E8(y, d_2);
	b = 0x15u;
	unk_5908 = b;
	unk_5909 = 0u;
	unk_5913 = 0u;
}

void sub_05E4F5(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, y = 0;

	b = 0x15u;
	y = 0x5A59u;
	d = b;
	sub_05E425(y, &d, &carry);
}

void sub_05E4F9(void)
{
	unk_5909 = 0u;
	unk_5908 = 0u;
}

void sub_05E506(uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, ignored16 = 0, u = 0, x = 0, y = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	b = (uint8_t)d;
	y = unk_590B_ADDRESS;
	u = unk_590D_ADDRESS;
	t1 = io_read8(IO_1F90);
	t2 = t1 & 0xCu;
	a = t2;
	if (t2 == 0u)
	{
		a = 0u;
		unk_5914 = a;
	}
	else if (unk_5914 != 0u)
		unk_5914--;
	else
	{
		b = mem_read8(unk_590B);
		t3 = DATA8(indexed_table_05E502_ADDRESS + ((a >> 1) >> 1)) + mem_read8(unk_590B);
		a = t3;
		if ((int8_t)t3 < 0)
			a = unk_590A - 3u;
		if ((int8_t)unk_590A <= (int8_t)a)
			a = 0u;
		mem_write8(unk_590B, a);
		x = mem_read16(unk_590D + b);
		mem_write8(x, 0x10u);
		d_2 = 0x10u;
		sub_05E5BD(x, &u, &d_2);
		b = (uint8_t)d_2;
		a = 7u;
		unk_5914 = 7u;
		unk_5914 = a;
	}
	x = mem_read16(mem_read16(u) + (int8_t)mem_read8(unk_590B));
	mem_write8(x, 0xA0u);
	d_2 = 0x4000u | b;
	sub_05E5BE(&x, &u, &d_2);
	b = (uint8_t)d_2;
	if ((unk_4842 & 0x10u) == 0u)
	{
		carry = 0u;
		d_2 = b;
	}
	else
	{
		mem_write8(x, 0x10u);
		a = mem_read8(mem_read16(u) + (int8_t)(mem_read8(unk_590B) + 2u));
		if (a == 0x20u)
		{
			t4 = (int8_t)mem_read8(unk_590B);
			stack_10001 = t4 >> 8;
			stack_10002 = t4;
			stack = konami_divx((uint16_t)(((uint32_t)stack_10001 << 8) | stack_10002), 3u);
			carry = 1u;
			d_2 = ((uint32_t)(uint8_t)~(stack >> 8) << 8) | (uint8_t)stack;
		}
		else
		{
			unk_5908 = a;
			unk_5909 = 0u;
			sub_05E733();
			sub_078695();
			sub_078698();
			sub_07869B(&ignored16, &d_2);
			b = (uint8_t)d_2;
			unk_5913 = 0u;
			carry = 0u;
			d_2 = b;
		}
	}
	*p_d = d_2;
	*p_carry = carry;
}

uint16_t sub_05E5A7(uint16_t d)
{
	uint8_t b = 0;
	uint16_t d_2 = 0, ignored16 = 0, x = 0;
	uint8_t stack = 0;

	stack = d >> 8;
	b = 3u * (d + 1u);
	x = mem_read16(unk_590D + (int8_t)b);
	d_2 = (uint32_t)stack << 8;
	sub_05E5BE(&x, &ignored16, &d_2);
	return x;
}

void sub_05E5BD(uint16_t x, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;

	d &= 0xFFu;
	*p_u = u;
	*p_d = d;
	sub_05E5BE(&x, p_u, p_d);
}

void sub_05E5BE(uint16_t *p_x, uint16_t *p_u, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u_2 = 0, x_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0, stack_7 = 0, stack_8 = 0;
	uint16_t t1 = 0, t2 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	stack_4 = x >> 8;
	stack_3 = (uint8_t)x;
	stack_5 = (uint8_t)d;
	stack_6 = d >> 8;
	t1 = ((uint32_t)stack_4 << 8) | stack_3;
	t2 = t1 - 0x2000u;
	stack_7 = (t2 & 0xC0u) + 0xFu;
	stack_8 = t2 >> 8;
	x_2 = ((uint32_t)stack_8 << 8) | stack_7;
	b = unk_5908;
	if (b == 0x15u)
		x_2 += 0x11u;
	a = stack_6;
	u_2 = 0x24u;
	if ((int8_t)b >= 0x14)
		u_2 = 0x12u;
	while (u_2 != 0u)
	{
		mem_write8(x_2, a);
		x_2++;
		u_2--;
	}
	x_2 = ((uint32_t)stack_4 << 8) | stack_3;
	u_2 = ((uint32_t)stack_2 << 8) | stack;
	d_2 = ((uint32_t)stack_6 << 8) | stack_5;
	*p_x = x_2;
	*p_u = u_2;
	*p_d = d_2;
}

uint16_t sub_05E5E8(uint16_t y, uint8_t d)
{
	uint16_t d_2 = 0, ignored16 = 0, ignored16_2 = 0, y_2 = 0;
	uint8_t stack = 0, stack_4 = 0, stack_8 = 0;

	if ((int16_t)y < 0x5A58 || y > 0x5A67u)
	{
		mem_write8(y, d);
		return y;
	}
	stack_4 = y >> 8;
	stack = (uint8_t)y;
	stack_8 = y - 0x59F0u;
	d_2 = (d & 0xFFu) | ((uint32_t)stack_8 << 8);
	sub_05E8F1(d_2);
	sub_05EA57(&ignored16, &ignored16_2);
	y_2 = ((uint32_t)stack_4 << 8) | stack;
	return y_2;
}

void sub_05E60A(uint16_t *p_x, uint16_t *p_y, uint16_t *p_d, uint32_t *p_zero)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint16_t d = (uint16_t)*p_d;
	uint32_t zero = *p_zero;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0, stack_4 = 0, stack_5 = 0, stack_6 = 0, stack_7 = 0, stack_8 = 0;
	uint8_t t1 = 0;

	a = (uint8_t)(d >> 8);
	if ((int16_t)y < 0x5A58 || y > 0x5A67u)
	{
		t1 = mem_read8(y);
		zero = t1 == 0u;
		d_2 = ((uint32_t)a << 8) | t1;
	}
	else
	{
		stack_4 = y >> 8;
		stack = (uint8_t)y;
		stack_6 = x >> 8;
		stack_5 = (uint8_t)x;
		stack_7 = a;
		stack_8 = y - 0x59F0u;
		d_2 = (d & 0xFFu) | ((uint32_t)stack_8 << 8);
		d_2 = sub_05E915(d_2);
		b = (uint8_t)d_2;
		zero = b == 0u;
		x = ((uint32_t)stack_6 << 8) | stack_5;
		y = ((uint32_t)stack_4 << 8) | stack;
		d_2 = ((uint32_t)stack_7 << 8) | b;
	}
	*p_x = x;
	*p_y = y;
	*p_d = d_2;
	*p_zero = zero;
}

uint32_t sub_05E62A(uint16_t x, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	u = DATA16(test_mode_texts_ADDRESS + (int8_t)((uint32_t)(d >> 8) << 1));
	d_2 = 0u;
	sub_05E650(d_2, &x, &u, &carry);
	t1 = u;
	unk_590A = mem_read8(t1);
	t2 = t1 + 1u;
	t3 = mem_read16(t2);
	unk_590B = t3;
	carry = 0u;
	unk_5912 = 0u;
	unk_590D = t2 + 2u;
	unk_5909++;
	return carry;
}

void sub_05E650(uint16_t d, uint16_t *p_x, uint16_t *p_u, uint32_t *p_carry)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = *p_carry;
	bool L_05E69F = false, L_05E6A6 = false, L_05E6AE = false, L_05E6C1 = false;
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0;
	uint8_t stack_10005 = 0, stack_10006 = 0, stack_10007 = 0, stack_10008 = 0;
	uint16_t stack = 0, stack_6 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	for (;;)
	{
		b = (uint8_t)d;
		stack = x;
		unk_591A = 0u;
		for (;;)
		{
			t1 = u;
			u = t1 + 1u;
			a = mem_read8(t1);
			if (a < 0xC0u)
			{
				t2 = a;
				a = t2 - 0x30u;
				if (t2 < 0x30u)
					break;
				d = ((uint32_t)a << 8) | b;
				x = sub_05E6FD(x, d);
				if (unk_591A == 0u)
					continue;
				x += 0x3Fu;
				continue;
			}
			t3 = a;
			a = t3 + 0x39u;
			if (t3 < 0xC7u)
			{
				a += 7u;
				carry = (int8_t)a < 0;
				switch ((int8_t)(uint8_t)((uint32_t)a << 1))
				{
				case 0:
					*p_x = x;
					*p_u = u;
					*p_carry = carry;
					return;
				case 2:
					L_05E69F = true;
					break;
				case 4:
					L_05E6A6 = true;
					break;
				case 6:
					L_05E6AE = true;
					break;
				case 8:
					L_05E6C1 = true;
					break;
				case 10:
					t4 = u;
					u = t4 + 2u;
					d = ((uint32_t)mem_read8(mem_read16(t4)) << 8) | b;
					sub_05E711(&x, &d);
					b = (uint8_t)d;
					continue;
				case 12:
					unk_591A++;
					continue;
				}
			}
			if (L_05E69F)
				break;
			if (L_05E6A6)
				break;
			if (L_05E6AE)
				break;
			if (L_05E6C1)
				break;
			stack_6 = u;
			stack_10007 = a;
			stack_10008 = b;
			u_2 = DATA16(test_mode_words_ADDRESS + (int8_t)((uint32_t)a << 1));
			d = b;
			sub_05E650(d, &x, &u_2, &carry);
			b = stack_10008;
			u = stack_6;
			if (stack_10007 == 0u)
			{
				*p_x = x;
				*p_u = u;
				*p_carry = carry;
				return;
			}
		}
		if (L_05E69F || L_05E6A6 || L_05E6AE || !L_05E6C1)
		{
			if (L_05E69F || L_05E6A6 || !L_05E6AE)
			{
				if (L_05E69F || !L_05E6A6)
				{
					if (!L_05E69F)
					{
						t5 = (uint32_t)(uint8_t)(a + 0x30u) << 6;
						t6 = u;
						u = t6 + 1u;
						t7 = (((uint32_t)(t5 >> 8) << 8) | (uint8_t)(t5 + mem_read8(t6))) + 0x208Cu;
						stack_10005 = t7 >> 8;
						stack_10006 = t7;
						x = ((uint32_t)stack_10005 << 8) | stack_10006;
						continue;
					}
					L_05E69F = false;
					x = stack + 0x40u;
					continue;
				}
				L_05E6A6 = false;
				x = stack + 0x80u;
				continue;
			}
			L_05E6AE = false;
			x = stack;
			if (unk_591A != 0u)
			{
				x += 3u;
				continue;
			}
			x += 0xC0u;
			continue;
		}
		L_05E6C1 = false;
		x = stack;
		if (unk_591A != 0u)
		{
			x += 4u;
			continue;
		}
		x += 0x100u;
	}
}

uint16_t sub_05E6FD(uint16_t x, uint16_t d)
{
	uint16_t x_2 = 0;
	uint16_t t1 = 0;

	io_write8(x - 0x2000u, (uint8_t)d);
	t1 = x;
	x_2 = t1 + 1u;
	io_write8(t1, d >> 8);
	return x_2;
}

void unused_05E704(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint8_t stack = 0, stack_2 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	d = (uint32_t)stack_2 << 8;
	sub_05E711(&x, &d);
	d = (uint32_t)stack << 8;
	sub_05E711(&x, &d);
}

void sub_05E711(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t d = (uint16_t)*p_d;
	uint8_t a = 0;
	uint16_t d_2 = 0, x_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	a = (uint8_t)(d >> 8);
	stack = (uint8_t)d;
	stack_2 = a;
	t1 = x;
	mem_write8(t1, DATA8(indexed_table_05F5AE_ADDRESS + ((((a >> 1) >> 1) >> 1) >> 1)));
	t2 = t1 + 1u;
	x_2 = t2 + 1u;
	mem_write8(t2, DATA8(indexed_table_05F5AE_ADDRESS + (stack_2 & 0xFu)));
	d_2 = ((uint32_t)stack_2 << 8) | stack;
	*p_x = x_2;
	*p_d = d_2;
}

uint16_t sub_05E733(void)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0u;
	carry = sub_078680(d);
	return d;
}

uint16_t sub_05E8F1(uint16_t d)
{
	uint16_t x = 0;

	unk_5A00 = d >> 8;
	unk_5A01 = (uint8_t)d;
	sub_05E932();
	sub_05E938();
	sub_05E93E();
	sub_05E965();
	sub_05E98A();
	sub_05E98F();
	x = sub_05E9A1();
	io_write8(IO_1FC2, unk_480F);
	return x;
}

uint16_t sub_05E915(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;

	a = (uint8_t)(d >> 8);
	stack = a;
	unk_5A00 = a;
	sub_05E9A6();
	sub_05E93E();
	sub_05E9AB();
	sub_05E98A();
	b = unk_5A02;
	io_write8(IO_1FC2, unk_480F);
	d_2 = ((uint32_t)stack << 8) | b;
	return d_2;
}

void sub_05E932(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FC7C_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
}

void sub_05E938(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FC9A_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
}

void sub_05E93E(void)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0;

	x = 0x7CA8u;
	a = indexed_table_05FCA7;
	b = unk_5A00;
	do
	{
		if ((b & 0x40u) != 0u)
			a |= 0x80u;
		io_write8(IO_1FC2, a);
		sub_05E9F2();
		t1 = x;
		x = t1 + 1u;
		io_write8(IO_1FC2, a | mem_read8(t1));
		sub_05E9F2();
		b = (uint32_t)b << 1;
		t2 = x;
		x = t2 + 1u;
		a = mem_read8(t2);
	} while (a != 0xFFu);
}

void sub_05E965(void)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0;

	x = 0x7CB7u;
	a = indexed_table_05FCB6;
	b = unk_5A01;
	do
	{
		if ((b & 0x80u) != 0u)
			a |= 0x80u;
		io_write8(IO_1FC2, a);
		sub_05E9F2();
		t1 = x;
		x = t1 + 1u;
		io_write8(IO_1FC2, a | mem_read8(t1));
		sub_05E9F2();
		b = (uint32_t)b << 1;
		t2 = x;
		x = t2 + 1u;
		a = mem_read8(t2);
	} while (a != 0xFFu);
}

void sub_05E98A(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FCC7_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
}

void sub_05E98F(void)
{
	uint8_t t1 = 0;

	do
	{
		io_write8(IO_1FC2, indexed_table_05FCCB);
		t1 = io_read8(IO_1F81);
	} while ((t1 & 0x20u) == 0u);
}

uint16_t sub_05E9A1(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FCCC_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
	return x;
}

void sub_05E9A6(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FD08_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
}

void sub_05E9AB(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0;
	uint32_t t6 = 0;

	x = loaded_table_05FD23_ADDRESS;
	b = 8u;
	carry = 0u;
	unk_5A02 = 0u;
	do
	{
		t1 = x;
		x = t1 + 1u;
		io_write8(IO_1FC2, mem_read8(t1));
		sub_05E9F2();
		t2 = x;
		x = t2 + 1u;
		io_write8(IO_1FC2, mem_read8(t2));
		sub_05E9F2();
		t3 = io_read8(IO_1F81);
		t4 = t3 & 0x10u;
		a = t4;
		if (t4 != 0u)
			a = 1u;
		t5 = unk_5A02;
		t6 = ((uint32_t)t5 << 1) | carry;
		carry = t5 >> 7;
		unk_5A02 = t6;
		unk_5A02 |= a;
		t7 = b;
		b = t7 - 1u;
	} while (t7 != 1u);
}

void unreached_05E9E0(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint16_t t1 = 0;

	x = indexed_table_05FCF7_ADDRESS;
	do
	{
		t1 = x;
		x = t1 + 1u;
		a = mem_read8(t1);
		io_write8(IO_1FC2, a);
		sub_05E9F2();
	} while (a != 0xFFu);
}

void sub_05E9F2(void)
{
	uint8_t t1 = 0;

	t1 = io_read8(IO_1FCA);
}

void sub_05EA46(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, x = 0;
	uint16_t t1 = 0;

	u = loaded_table_05FD36_ADDRESS;
	a = 0x68u;
	for (;;)
	{
		t1 = u;
		u = t1 + 1u;
		b = mem_read8(t1);
		if (b == 0xFFu)
			break;
		d = ((uint32_t)a << 8) | b;
		sub_05E8F1(d);
		a++;
	}
	*p_x = x;
	*p_d = d;
	sub_05EA57(p_x, p_d);
}

void sub_05EA57(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	sub_05EA91();
	a = 0x7Eu;
	d = 0x7E00u | unk_48F0;
	sub_05E8F1(d);
	d = ((uint32_t)(uint8_t)(a + 1u) << 8) | unk_48F1;
	x = sub_05E8F1(d);
	*p_x = x;
	*p_d = d;
}

void sub_05EA91(void)
{
	uint8_t d = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0;
	uint32_t unk_48F0_halfword = 0;

	d = 0u;
	unk_48F0 = 0u;
	unk_48F1 = 0u;
	unk_48F2 = 0u;
	do
	{
		d_2 = (d & 0xFFu) | ((uint32_t)unk_48F2 << 8);
		d_2 = sub_05E915(d_2);
		t1 = (d_2 & 0xFFu) + (((uint32_t)unk_48F0 << 8u) | unk_48F1);
		d = (uint8_t)t1;
		unk_48F0_halfword = ((uint32_t)(t1 >> 8) << 8) | (d & 0xFFu);
		unk_48F0 = (uint8_t)(unk_48F0_halfword >> 8u);
		unk_48F1 = (uint8_t)unk_48F0_halfword;
		unk_48F2++;
	} while (unk_48F2 < 0x7Eu);
}

uint16_t sub_05EAB0(uint16_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0;

	a = (uint32_t)unk_5A10 << 1;
	switch ((int8_t)a)
	{
	case 0:
		return sub_05EABA();
	case 2:
	case 4:
	case 6:
	case 8:
		return sub_05EADE();
	case 10:
		return sub_05EB19();
	case 12:
	case 14:
	case 16:
	case 18:
		return sub_05EB48();
	case 20:
		return sub_05EB83(d);
	case 22:
		return sub_05EBBF(d);
	case 24:
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		sub_05EBE6();
		return d_2;
	}
	unreachable();
}

uint16_t sub_05EABA(void)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0, y = 0;

	y = unk_5A10_ADDRESS;
	x = unk_5A11_ADDRESS;
	unk_5A10 = 0u;
	u = 0xFu;
	while (u != 0u)
	{
		mem_write8(x, mem_read8(y));
		y++;
		x++;
		u--;
	}
	d = 0xCu;
	sub_0785C0(d);
	sub_078605(&ignored16, &d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	a &= 0x80u;
	unk_5A1B = a;
	if (a == 0u)
	{
		d = sub_078608();
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
	}
	unk_5A10++;
	d = ((uint32_t)a << 8) | b;
	return d;
}

uint16_t sub_05EADE(void)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, x = 0;

	x = 0u;
	unk_48F8 = 0u;
	io_write8(VIDEO_1D80, 0x10u);
	io_write8(VIDEO_1F00, 0x32u);
	sub_05EBE7(&x, &ignored16);
	unk_48F8 = 0u;
	io_write8(VIDEO_1D80, 0x54u);
	io_write8(VIDEO_1F00, 0x76u);
	sub_05EBE7(&x, &d);
	a = (uint32_t)unk_5A11 << 1;
	mem_write16(unk_5A12_ADDRESS + (int8_t)a, x);
	unk_5A11++;
	unk_5A10++;
	d = (d & 0xFFu) | ((uint32_t)a << 8);
	return d;
}

uint16_t sub_05EB19(void)
{
	uint16_t d = 0, x = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = unk_5A14;
	x = unk_5A12 + t1;
	sub_05ECFE(x);
	t2 = unk_5A18;
	x = unk_5A16 + t2;
	d = sub_05ECFE(x);
	io_write8(VIDEO_1D80, 0x10u);
	io_write8(VIDEO_1F00, 0x32u);
	unk_5A11 = 0u;
	unk_5A10++;
	d = (d & 0xFFu) | 0x3200u;
	return d;
}

uint16_t sub_05EB48(void)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	a = unk_4855 & 0xEFu;
	unk_4855 = a;
	io_write8(IO_1FA5, a);
	x = 0u;
	unk_48F4 = 0u;
	unk_48F5 = 0u;
	unk_48F6 = (unk_48F6 & 0xFFu) | ((DATA8(indexed_table_05FD74_ADDRESS + (int8_t)unk_5A11) & 0xFFu) << 8u);
	unk_48F0 = 8u;
	do
	{
		x = sub_05EC6D(x);
		t1 = unk_48F0;
		unk_48F0 = t1 - 1u;
	} while (t1 != 1u);
	d = sub_05ECFE(x);
	unk_5A11++;
	unk_5A10++;
	return d;
}

uint16_t sub_05EB83(uint16_t d)
{
	uint32_t zero = 0;
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0;

	a = unk_4855 | 0x10u;
	unk_4855 = a;
	io_write8(IO_1FA5, a);
	t1 = unk_5A1B;
	a = t1;
	if (t1 != 0u)
	{
		unk_5A10++;
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	sub_078611(&d, &zero);
	if (zero == 0u)
	{
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	sub_07860B();
	sub_078605(&x, &d_2);
	a = (uint8_t)(d_2 >> 8);
	u = 0x251Fu;
	if ((a & 4u) != 0u)
	{
		d = sub_05ED28(x, u);
		a = (uint8_t)(d >> 8);
		unk_5A10++;
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	d_2 = sub_05ED0F(x, u);
	unk_5A10++;
	return d_2;
}

uint16_t sub_05EBBF(uint16_t d)
{
	uint8_t a = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0;

	t1 = unk_5A1B;
	a = t1;
	if (t1 != 0u)
	{
		unk_5A10++;
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	sub_07860E();
	sub_078605(&x, &d_2);
	a = (uint8_t)(d_2 >> 8);
	u = 0x259Fu;
	if ((a & 8u) != 0u)
	{
		d = sub_05ED28(x, u);
		a = (uint8_t)(d >> 8);
		unk_5A10++;
		d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
		return d_2;
	}
	d_2 = sub_05ED0F(x, u);
	unk_5A10++;
	return d_2;
}

void sub_05EBE6(void)
{
}

void sub_05EBE7(uint16_t *p_x, uint16_t *p_d)
{
	uint16_t x = (uint16_t)*p_x;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	disable_irq();
	io_write8(VIDEO_1D00, 0xFBu);
	disable_firq();
	a = unk_480F & ~4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	unk_48E8 = 0x40u;
	do
	{
		io_write8(VIDEO_1E00, (uint8_t)(unk_48F8 >> 8u));
		u = VIDEO_2000 + (int8_t)unk_5A11;
		y = 0x800u;
		a = unk_4810 | 8u;
		unk_4810 = a;
		io_write8(IO_1FC0, a);
		do
		{
			t1 = io_read8(IO_1FCA);
			b = mem_read8(u);
			x += b;
			u += 4u;
			t2 = y - 1u;
			y = t2;
		} while (t2 != 0u);
		a = unk_4810 & ~8u;
		unk_4810 = a;
		io_write8(IO_1FC0, a);
		unk_48F8 = (unk_48F8 & 0xFFu) | (((uint8_t)(unk_48F8 >> 8u) + 1u & 0xFFu) << 8u);
		t3 = unk_48E8;
		unk_48E8 = t3 - 1u;
	} while (t3 != 1u);
	enable_irq();
	take_interrupts();
	stack = a;
	io_write8(VIDEO_1D00, 0xFFu);
	enable_firq();
	take_interrupts();
	a = unk_480F | 4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	d = ((uint32_t)stack << 8) | b;
	*p_x = x;
	*p_d = d;
}

uint16_t sub_05EC6D(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t5 = 0;
	uint16_t t3 = 0, t4 = 0, t6 = 0;
	uint32_t unk_48F5_halfword = 0;

	y = 0u;
	disable_irq();
	io_write8(VIDEO_1D00, 0xFBu);
	disable_firq();
	a = unk_480F & ~4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	a = unk_4810 & 0xDFu;
	unk_4810 = a;
	io_write8(IO_1FC0, a);
	do
	{
		io_write8(IO_1FA6, unk_48F4);
		io_write8(IO_1FA7, unk_48F5);
		io_write8(IO_1FA4, (uint8_t)(unk_48F6 >> 8u));
		t1 = io_read8(IO_1FC8);
		t2 = io_read8(IO_1FC9);
		x = x + t1 + t2;
		t3 = (((uint32_t)unk_48F5 << 8u) | (unk_48F6 >> 8u));
		t4 = t3;
		carry = (uint16_t)(t4 + 4u) < t4;
		unk_48F5_halfword = t4 + 4u;
		unk_48F5 = (uint8_t)(unk_48F5_halfword >> 8u);
		unk_48F6 = (unk_48F6 & 0xFFu) | ((unk_48F5_halfword & 0xFFu) << 8u);
		unk_48F4 += carry;
		t5 = io_read8(IO_1FCA);
		t6 = y - 1u;
		y = t6;
	} while (t6 != 0u);
	a = unk_4810 | 0x20u;
	unk_4810 = a;
	io_write8(IO_1FC0, a);
	enable_irq();
	take_interrupts();
	io_write8(VIDEO_1D00, 0xFFu);
	enable_firq();
	take_interrupts();
	a = unk_480F | 4u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return x;
}

uint16_t sub_05ECFE(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;

	a = (uint32_t)unk_5A1A << 1;
	u = DATA16(indexed_table_05FD68_ADDRESS + (int8_t)a);
	if (x != DATA16(indexed_table_05FD5C_ADDRESS + (int8_t)a))
		return sub_05ED28(x, u);
	return sub_05ED0F(x, u);
}

uint16_t sub_05ED0F(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, x_2 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0;

	io_write8(u - 0x2000u, 0u);
	t1 = u;
	u_2 = t1 + 1u;
	io_write8(t1, 0x1Fu);
	mem_write8(u_2 - 0x2000u, 0u);
	t2 = u_2;
	mem_write8(t2, 0x1Bu);
	unk_48F0 = 0u;
	u_2 = t2 + 2u;
	stack = x;
	x_2 = u_2 + 2u;
	d = stack;
	d = sub_078692(x_2, d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	unk_5A1A++;
	d = ((uint32_t)a << 8) | b;
	return d;
}

uint16_t sub_05ED28(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, x_2 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	io_write8(u - 0x2000u, 0x40u);
	t1 = u;
	u_2 = t1 + 1u;
	io_write8(t1, 0x12u);
	mem_write8(u_2 - 0x2000u, 0x40u);
	t2 = u_2;
	u_2 = t2 + 1u;
	mem_write8(t2, 0x11u);
	mem_write8(u_2 - 0x2000u, 0x40u);
	t3 = u_2;
	mem_write8(t3, 0x14u);
	unk_48F0 = 0x40u;
	stack = x;
	x_2 = t3 + 3u;
	d = stack;
	d = sub_078692(x_2, d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	unk_5A1A++;
	d = ((uint32_t)a << 8) | b;
	return d;
}

void sub_05EDB4(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_483B != 0u)
	{
		x = unk_4817_ADDRESS;
		unk_48F0 = 4u;
		unk_48F1 = 1u;
		do
		{
			if (mem_read16(x) != 0u)
				unk_485B |= unk_48F1;
			x += 8u;
			unk_48F1 = (uint32_t)unk_48F1 << 1;
			t1 = unk_48F0;
			unk_48F0 = t1 - 1u;
		} while (t1 != 1u);
		return;
	}
	if (unk_4837 == 0u)
		return;
	x = unk_4842_ADDRESS;
	a = 4u;
	unk_48F0 = 1u;
	do
	{
		if ((mem_read8(x) & 0xB0u) != 0u)
			unk_485B |= unk_48F0;
		x += 4u;
		unk_48F0 = (uint32_t)unk_48F0 << 1;
		t2 = a;
		a = t2 - 1u;
	} while (t2 != 1u);
}

uint16_t sub_05EE08(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u_2 = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	unk_487E = 1u;
	d = 0x408u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 2u;
	d = 0x1Bu;
	sub_078677(d, &ignored16, &u);
	unk_4875 = 0x80u;
	unk_4876 = 0u;
	sub_0786B0();
	d = 0x2Cu;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	d = 0x12Cu;
	sub_0786AD(d, &ignored16_2, &ignored16, &ignored16_3);
	unk_48F0 = 0u;
	do
	{
		t1 = loaded_table_05FDD8_ADDRESS + (int8_t)(((uint32_t)unk_48F0 << 1) << 1);
		x = t1 + 2u;
		u_2 = DATA16(t1);
		unk_48F2 = 0x14u;
		do
		{
			unk_48F1 = 9u;
			do
			{
				mem_write8(u_2 - 0x2000u, mem_read8(x));
				u_2++;
				stack_2 = u_2 >> 8;
				stack = (uint8_t)u_2;
				stack_2 = (stack_2 & 7u) | 0x28u;
				u_2 = ((uint32_t)stack_2 << 8) | stack;
				t2 = unk_48F1;
				unk_48F1 = t2 - 1u;
			} while (t2 != 1u);
			u_2 += 0x37u;
			stack_2 = u_2 >> 8;
			stack = (uint8_t)u_2;
			stack_2 = (stack_2 & 7u) | 0x28u;
			u_2 = ((uint32_t)stack_2 << 8) | stack;
			t3 = unk_48F2;
			unk_48F2 = t3 - 1u;
		} while (t3 != 1u);
		unk_48F0++;
	} while (unk_48F0 != 4u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	unk_4805 = (unk_4805 & 0xFFu) | (((uint8_t)(unk_4805 >> 8u) + 1u & 0xFFu) << 8u);
	return x;
}

uint16_t sub_05EEAB(void)
{
	uint16_t u = 0, x = 0;
	uint8_t stack = 0;

	x = unk_4F80_ADDRESS;
	unk_48F0 = 1u;
	stack = 0u;
	do
	{
		u = DATA16(test_player_records_ADDRESS + (int8_t)((uint32_t)stack << 1));
		x = sub_05EED1(x, u);
		x += 0xC0u;
		unk_48F0 = (uint32_t)unk_48F0 << 1;
		stack = stack + 1u;
	} while (stack != 4u);
	return x;
}

uint16_t sub_05EED1(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 1u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_05EEDA(x, u);
		return x;
	case 2:
		sub_05EF1B(x, u);
		return x;
	case 4:
		sub_05EF2C(x);
		return x;
	case 6:
		sub_05EF3F(x, u);
		return x;
	case 8:
		sub_05EF89(x);
		return x;
	case 10:
		sub_05EF9D(x);
		return x;
	case -4:
		return sub_05EE08(u);
	case -2:
		return sub_05EEAB();
	}
	unreachable();
}

void sub_05EEDA(uint16_t x, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read16(u + 2u);
	d = t1;
	mem_write8(x + 4u, d >> 8);
	mem_write8(x + 5u, d | 0x80u);
	t2 = mem_read16(u + 4u);
	mem_write16(x + 0xCu, t2);
	mem_write16(x + 0x11u, 0x80u);
	t3 = mem_read16(u + 6u);
	mem_write16(x + 0x16u, t3);
	t4 = mem_read16(u + 8u);
	d = t4;
	mem_write16(x + 0x64u, d);
	t5 = mem_read16(u + 0xAu);
	mem_write16(x + 0x6Cu, t5);
	mem_write16(x + 0x71u, 0x80u);
	mem_write16(x + 0x76u, 0x58u);
	t6 = mem_read8(x + 1u);
	mem_write8(x + 1u, t6 + 1u);
}

void sub_05EF1B(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 0x11u);
	if ((t1 & unk_485B) != 0u)
	{
		mem_write8(x + 0x30u, 0x20u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

void sub_05EF2C(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 0x30u, t1 - 1u);
	if (t1 != 1u)
	{
		mem_write8(x + 0x29u, 0x11u);
		mem_write8(x + 0x28u, 3u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

void sub_05EF3F(uint16_t x, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0;
	uint8_t stack = 0;
	uint16_t stack_3 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;
	uint16_t t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 0x28u, 3u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	t3 = mem_read8(x + 0x29u);
	a = t3;
	if (a != 0x16u)
	{
		mem_write8(x + 5u, a | 0x80u);
		return;
	}
	mem_write8(x + 0x60u, 0x80u);
	stack = a;
	stack_3 = u;
	unk_487E = 1u;
	t4 = mem_read8(u + 0xCu);
	d = 0x600u | t4;
	sub_078677(d, &ignored16, &u);
	u_2 = stack_3;
	unk_487E = 2u;
	t5 = mem_read16(u_2 + 0xDu);
	d = t5;
	sub_078677(d, &ignored16, &u_2);
	t6 = mem_read16(stack_3 + 0xFu);
	d = t6;
	sub_07869E(d);
	a = stack;
	t7 = mem_read8(x + 1u);
	mem_write8(x + 1u, t7 + 1u);
	mem_write8(x + 5u, a | 0x80u);
}

void sub_05EF89(uint16_t x)
{
	uint16_t stack = 0;
	uint8_t t1 = 0;

	stack = x;
	if (((stack + unk_4858) & 0xF7u) == 0u)
	{
		mem_write8(x + 5u, 0x8Bu);
		t1 = mem_read8(x + 1u);
		mem_write8(x + 1u, t1 + 1u);
	}
}

void sub_05EF9D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 - 1u);
	}
}
