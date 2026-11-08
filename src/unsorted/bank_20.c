/**
 *    Name:        unsorted/bank_20.c
 *    Description: bank 20's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    07-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_040003(void)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0;
	uint8_t stack = 0;
	uint16_t t1 = 0;

	if (unk_486A == 0u)
		return;
	a = 0u;
	do
	{
		stack = a;
		x = gauge_player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2];
		sub_040946(x);
		d = (uint32_t)stack << 8;
		sub_040953(d);
		a = stack + 1u;
	} while (a != 4u);
	if (unk_483B != 0u)
		return;
	x = 0x2766u;
	u = indexed_table_041745_ADDRESS;
	d = 0u;
	sub_040B88(x, u, d);
	t1 = unk_4837;
	b = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)(t1 >> 8) << 8) | b) > 0xFFu)
		b = 0xFFu;
	d = b;
	sub_0409CF(&ignored16, &d, &carry);
	a = (uint8_t)(d >> 8);
	if (carry)
		a = 0x99u;
	x = 0x276Du;
	d = (uint32_t)a << 8;
	sub_0785EA(x, d);
}

void sub_040006(void)
{
	uint16_t d = 0, u = 0, x = 0;

	x = 0x2213u;
	u = indexed_table_0416A3_ADDRESS;
	d = 0u;
	sub_040B88(x, u, d);
	sub_040B44();
}

void sub_040009(void)
{
	uint8_t d = 0;
	uint16_t d_2 = 0, u = 0, x = 0;
	uint8_t stack = 0;

	stack = d;
	x = 0x2213u;
	u = indexed_table_0416A3_ADDRESS;
	d_2 = loaded_table_078000_ADDRESS;
	sub_040B88(x, u, d_2);
	sub_040B73();
	x = 0x2394u;
	u = indexed_table_0416F4_ADDRESS;
	d_2 = 0u;
	sub_040B88(x, u, d_2);
}

void sub_04000C(void)
{
	uint16_t d = 0, u = 0, x = 0;

	x = 0x2394u;
	u = indexed_table_0416F4_ADDRESS;
	d = 0u;
	sub_040B88(x, u, d);
}

uint16_t sub_04000F(void)
{
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t counters = 0;

	a = 0u;
	stack = 0u;
	do
	{
		counters = GAUGE_PLAYER(gauge_player_records[(int8_t)((uint8_t)((uint32_t)a << 1)) / 2])->counters;
		y = counters;
		t1 = mem_read8(y + 3u);
		a = t1;
		if (t1 != 0u)
			a--;
		mem_write8(y + 3u, a);
		stack = stack + 1u;
		a = stack;
	} while (a != 4u);
	return y;
}

void sub_040012(void)
{
	uint8_t a = 0;

	unk_4861 = 0u;
	sub_040C61();
	sub_040C65();
	sub_040C7D();
	sub_040C8D();
	sub_040CB7();
	sub_040CC6();
	sub_040D36();
	sub_040CD7();
	a = 0x1Fu;
	if (unk_4861 > 0x1Fu)
		unk_4861 = a;
}

void sub_04001E(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_041010_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_040027(u);
			return;
		case 2:
			sub_0400AA();
			return;
		case 4:
			sub_040108();
			return;
		case 6:
			sub_04014B();
			return;
		case 8:
			sub_04019F();
			return;
		case 10:
			sub_0401B7();
			return;
		case 12:
			sub_040215();
			return;
		case 14:
			sub_040247();
			return;
		case 16:
			sub_040250();
			return;
		case 18:
			sub_040274();
			return;
		case 20:
			sub_04028D(u);
			return;
		case 22:
			sub_0402AE();
			return;
		case 24:
			sub_0402EC();
			return;
		case 26:
			sub_040300();
			return;
		case 28:
			sub_04030F();
			return;
		case 30:
			sub_040330();
			return;
		case 32:
			sub_04034B();
			return;
		case 34:
			sub_040361();
			return;
		case 36:
			sub_0403B1();
			return;
		case 38:
			sub_0403E4();
			return;
		case 40:
			sub_0403F3();
			return;
		case 42:
			sub_040414();
			return;
		case 44:
			sub_04042F(u);
			return;
		case 46:
			sub_04047A();
			return;
		case 48:
			sub_040500();
			return;
		case 50:
			sub_040517();
			return;
		case 52:
			sub_040547();
			return;
		case 54:
			sub_0405A3(u);
			return;
		case 56:
			sub_0405E4();
			return;
		case 58:
			sub_040618();
			return;
		case 60:
			sub_040646();
			return;
		case 62:
			sub_040687();
			return;
		case 64:
			sub_0406A2();
			return;
		case 66:
			sub_0406CA();
			return;
		case 68:
			sub_0406EB();
			return;
		case 70:
			sub_040709(u);
			return;
		case 72:
			sub_040758(u);
			return;
		case 74:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 76:
		case 82:
			sub_0407CA(x);
			return;
		case 78:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 80:
			sub_0407EC(x, y);
			return;
		case 84:
			break;
		case -16:
			continue;
		case -14:
			sub_0400FF(y, u);
			return;
		case -12:
			sub_0401AE(y, u);
			return;
		case -10:
			sub_0402A5(y, u);
			return;
		case -8:
			sub_040358(y, u);
			return;
		case -6:
			sub_040471(y, u);
			return;
		case -4:
			sub_04063D(y, u);
			return;
		case -2:
			sub_040700(y, u);
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_040027(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, x = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_487E = 3u;
	d = 0x7A53u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0xF02u;
	sub_078677(d, &ignored16, &u);
	sub_0408BF();
	unk_48BE = 0x10u;
	unk_48CE = 0x10u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	x = 0x2800u;
	b = 0x10u;
	do
	{
		mem_write8(x - 0x2000u, 0u);
		t1 = x;
		x = t1 + 1u;
		mem_write8(t1, b);
	} while (x != 0x3000u);
	x = 0x3000u;
	b = 0x10u;
	do
	{
		mem_write8(x - 0x2000u, 0u);
		t2 = x;
		x = t2 + 1u;
		mem_write8(t2, b);
	} while (x != 0x3800u);
	sub_04086B();
	d = loaded_table_078000_ADDRESS;
	carry = sub_078680(d);
	x = unk_4F80_ADDRESS;
	u_2 = loaded_table_041066_ADDRESS;
	unk_4FA8 = 0xFF00u;
	unk_4F8A = 0xFFu;
	unk_4F8B = 0xFFu;
	unk_4F89 = 0x30u;
	sub_04080D(&x, &u_2);
	mem_write8(x - 0x60u, 0x90u);
	unk_480B = 0xA0u;
	unk_4804++;
}

void sub_0400AA(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	x = unk_4F80_ADDRESS;
	unk_4F80 = 0x90u;
	t1 = unk_4FA8;
	t2 = t1 - VIDEO_00C0;
	a = (uint8_t)(t2 >> 8);
	unk_4FA8 = ((uint32_t)a << 8) | (t2 & 0xFFu);
	unk_4F8A = a;
	unk_4F8B = a;
	if (a <= 0x40u)
		unk_4F89 = 0x10u;
	t3 = AT16(unk_48BE, -1);
	t4 = t3;
	t5 = t4 - 0x80u;
	carry = t4 < 0x80u;
	AT16(unk_48BE, -1) = t5;
	unk_48BE = (unk_48BE & 0xFFu) | (((uint8_t)(unk_48BE >> 8u) - carry & 0xFFu) << 8u);
	t6 = AT16(unk_48CE, -1);
	t7 = t6;
	carry = (uint16_t)(t7 + 0x80u) < t7;
	AT16(unk_48CE, -1) = t7 + 0x80u;
	unk_48CE = (unk_48CE & 0xFFu) | (((uint8_t)(unk_48CE >> 8u) + carry & 0xFFu) << 8u);
	if ((unk_4815 & 1u) == 0u)
	{
		t8 = unk_480B;
		unk_480B = t8 - 1u;
		if (t8 == 1u)
		{
			unk_4803++;
			unk_4804 = 0u;
		}
	}
}

void sub_0400FF(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_041014_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_040108();
			return;
		case 2:
			sub_04014B();
			return;
		case 4:
			sub_04019F();
			return;
		case 6:
			sub_0401B7();
			return;
		case 8:
			sub_040215();
			return;
		case 10:
			sub_040247();
			return;
		case 12:
			sub_040250();
			return;
		case 14:
			sub_040274();
			return;
		case 16:
			sub_04028D(u);
			return;
		case 18:
			sub_0402AE();
			return;
		case 20:
			sub_0402EC();
			return;
		case 22:
			sub_040300();
			return;
		case 24:
			sub_04030F();
			return;
		case 26:
			sub_040330();
			return;
		case 28:
			sub_04034B();
			return;
		case 30:
			sub_040361();
			return;
		case 32:
			sub_0403B1();
			return;
		case 34:
			sub_0403E4();
			return;
		case 36:
			sub_0403F3();
			return;
		case 38:
			sub_040414();
			return;
		case 40:
			sub_04042F(u);
			return;
		case 42:
			sub_04047A();
			return;
		case 44:
			sub_040500();
			return;
		case 46:
			sub_040517();
			return;
		case 48:
			sub_040547();
			return;
		case 50:
			sub_0405A3(u);
			return;
		case 52:
			sub_0405E4();
			return;
		case 54:
			sub_040618();
			return;
		case 56:
			sub_040646();
			return;
		case 58:
			sub_040687();
			return;
		case 60:
			sub_0406A2();
			return;
		case 62:
			sub_0406CA();
			return;
		case 64:
			sub_0406EB();
			return;
		case 66:
			sub_040709(u);
			return;
		case 68:
			sub_040758(u);
			return;
		case 70:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 72:
		case 78:
			sub_0407CA(x);
			return;
		case 74:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 76:
			sub_0407EC(x, y);
			return;
		case 80:
			break;
		case -20:
			sub_04001E(y, u);
			return;
		case -18:
			continue;
		case -16:
			sub_0401AE(y, u);
			return;
		case -14:
			sub_0402A5(y, u);
			return;
		case -12:
			sub_040358(y, u);
			return;
		case -10:
			sub_040471(y, u);
			return;
		case -8:
			sub_04063D(y, u);
			return;
		case -6:
			sub_040700(y, u);
			return;
		case -4:
			sub_040027(u);
			return;
		case -2:
			sub_0400AA();
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_040108(void)
{
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0;
	uint16_t t1 = 0, t2 = 0;

	unk_4F80 = 0x90u;
	t1 = unk_4FA8;
	t2 = t1 - VIDEO_00C0;
	a = (uint8_t)(t2 >> 8);
	unk_4FA8 = ((uint32_t)a << 8) | (t2 & 0xFFu);
	unk_4F8A = a;
	unk_4F8B = a;
	sub_0408BF();
	unk_48BE = 0x170u;
	unk_48CE = 0x150u;
	u = sub_04086B();
	unk_48D5 = 0x20u;
	unk_487E = 3u;
	d = 0u;
	sub_078677(d, &ignored16, &u);
	unk_480B = 0x90u;
	unk_4804++;
}

void sub_04014B(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, x = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	x = unk_4F80_ADDRESS;
	if (unk_4F80 != 0u)
	{
		unk_4F80 = 0x90u;
		t1 = unk_4FA8;
		t2 = t1 - VIDEO_00C0;
		a = (uint8_t)(t2 >> 8);
		unk_4FA8 = ((uint32_t)a << 8) | (t2 & 0xFFu);
		unk_4F8A = a;
		unk_4F8B = a;
		if (a <= 0x10u)
			sub_07868C(&ignored16, &ignored16_2);
	}
	t3 = unk_480B;
	unk_480B = t3 - 1u;
	if (t3 == 1u)
	{
		unk_480B = 1u;
		unk_4804++;
		return;
	}
	t4 = AT16(unk_48C5, -1);
	t5 = t4;
	carry = (uint16_t)(t5 + 0x18u) < t5;
	AT16(unk_48C5, -1) = t5 + 0x18u;
	unk_48C5 = (unk_48C5 & 0xFFu) | (((uint8_t)(unk_48C5 >> 8u) + carry & 0xFFu) << 8u);
	t6 = (((uint32_t)(unk_48D5 & 0xFFu) << 8u) | unk_48D7);
	t7 = t6;
	t8 = t7 - 0x30u;
	carry = t7 < 0x30u;
	unk_48D5 = (unk_48D5 & 0xFF00u) | ((t8 >> 8u) & 0xFFu);
	unk_48D7 = (uint8_t)t8;
	unk_48D5 = (unk_48D5 & 0xFFu) | (((uint8_t)(unk_48D5 >> 8u) - carry & 0xFFu) << 8u);
}

void sub_04019F(void)
{
	uint8_t t1 = 0;

	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_078698();
	unk_4803++;
	unk_4804 = 0u;
}

void sub_0401AE(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_04101A_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_0401B7();
			return;
		case 2:
			sub_040215();
			return;
		case 4:
			sub_040247();
			return;
		case 6:
			sub_040250();
			return;
		case 8:
			sub_040274();
			return;
		case 10:
			sub_04028D(u);
			return;
		case 12:
			sub_0402AE();
			return;
		case 14:
			sub_0402EC();
			return;
		case 16:
			sub_040300();
			return;
		case 18:
			sub_04030F();
			return;
		case 20:
			sub_040330();
			return;
		case 22:
			sub_04034B();
			return;
		case 24:
			sub_040361();
			return;
		case 26:
			sub_0403B1();
			return;
		case 28:
			sub_0403E4();
			return;
		case 30:
			sub_0403F3();
			return;
		case 32:
			sub_040414();
			return;
		case 34:
			sub_04042F(u);
			return;
		case 36:
			sub_04047A();
			return;
		case 38:
			sub_040500();
			return;
		case 40:
			sub_040517();
			return;
		case 42:
			sub_040547();
			return;
		case 44:
			sub_0405A3(u);
			return;
		case 46:
			sub_0405E4();
			return;
		case 48:
			sub_040618();
			return;
		case 50:
			sub_040646();
			return;
		case 52:
			sub_040687();
			return;
		case 54:
			sub_0406A2();
			return;
		case 56:
			sub_0406CA();
			return;
		case 58:
			sub_0406EB();
			return;
		case 60:
			sub_040709(u);
			return;
		case 62:
			sub_040758(u);
			return;
		case 64:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 66:
		case 72:
			sub_0407CA(x);
			return;
		case 68:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 70:
			sub_0407EC(x, y);
			return;
		case 74:
			break;
		case -26:
			sub_04001E(y, u);
			return;
		case -24:
			sub_0400FF(y, u);
			return;
		case -22:
			continue;
		case -20:
			sub_0402A5(y, u);
			return;
		case -18:
			sub_040358(y, u);
			return;
		case -16:
			sub_040471(y, u);
			return;
		case -14:
			sub_04063D(y, u);
			return;
		case -12:
			sub_040700(y, u);
			return;
		case -10:
			sub_040027(u);
			return;
		case -8:
			sub_0400AA();
			return;
		case -6:
			sub_040108();
			return;
		case -4:
			sub_04014B();
			return;
		case -2:
			sub_04019F();
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_0401B7(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0x4D0u;
	unk_48C3 = 0xFFF0u;
	unk_489C = 1u;
	unk_48A9 = 1u;
	unk_4899 = 1u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x2Au;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	x = unk_4F80_ADDRESS;
	u = loaded_table_04106B_ADDRESS;
	unk_4F8F = 0xFF00u;
	unk_4F99 = 0x200u;
	sub_04080D(&x, &u);
	unk_480B = 0x60u;
	unk_4804++;
}

void sub_040215(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	x = unk_4F80_ADDRESS;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_4F8F = 0xF900u;
		unk_480B = 1u;
		unk_4804++;
		return;
	}
	t2 = unk_4F99;
	unk_4F99 = t2 - 0xCu;
	d = AT16(unk_48BE, -1);
	carry = d < 0x600u;
	AT16(unk_48BE, -1) = d - 0x600u;
	unk_48BE = (unk_48BE & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(unk_48BE >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
}

void sub_040247(void)
{
	uint8_t t1 = 0;

	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
		unk_4804++;
}

void sub_040250(void)
{
	uint16_t u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0x5F0u;
	sub_040870();
	x = unk_4F80_ADDRESS;
	u = loaded_table_0410B1_ADDRESS;
	sub_04076D(x, u);
	unk_480B = 0xE0u;
	unk_4883 = 0u;
	unk_4884 = 0u;
	unk_4804++;
}

void sub_040274(void)
{
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	d = 0u;
	sub_04082C(d);
	d = 0x100u;
	sub_04082C(d);
	x = unk_4F80_ADDRESS;
	d = 0u;
	sub_04078D(x, d);
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
		unk_4804++;
}

void sub_04028D(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_487E = 1u;
	d = 0x203u;
	sub_078677(d, &ignored16, &u);
	sub_07868C(&ignored16_2, &ignored16_3);
	sub_07869B(&ignored16_2, &ignored16_4);
	unk_4803++;
	unk_4804 = 0u;
}

void sub_0402A5(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_041026_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_0402AE();
			return;
		case 2:
			sub_0402EC();
			return;
		case 4:
			sub_040300();
			return;
		case 6:
			sub_04030F();
			return;
		case 8:
			sub_040330();
			return;
		case 10:
			sub_04034B();
			return;
		case 12:
			sub_040361();
			return;
		case 14:
			sub_0403B1();
			return;
		case 16:
			sub_0403E4();
			return;
		case 18:
			sub_0403F3();
			return;
		case 20:
			sub_040414();
			return;
		case 22:
			sub_04042F(u);
			return;
		case 24:
			sub_04047A();
			return;
		case 26:
			sub_040500();
			return;
		case 28:
			sub_040517();
			return;
		case 30:
			sub_040547();
			return;
		case 32:
			sub_0405A3(u);
			return;
		case 34:
			sub_0405E4();
			return;
		case 36:
			sub_040618();
			return;
		case 38:
			sub_040646();
			return;
		case 40:
			sub_040687();
			return;
		case 42:
			sub_0406A2();
			return;
		case 44:
			sub_0406CA();
			return;
		case 46:
			sub_0406EB();
			return;
		case 48:
			sub_040709(u);
			return;
		case 50:
			sub_040758(u);
			return;
		case 52:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 54:
		case 60:
			sub_0407CA(x);
			return;
		case 56:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 58:
			sub_0407EC(x, y);
			return;
		case 62:
			break;
		case -38:
			sub_04001E(y, u);
			return;
		case -36:
			sub_0400FF(y, u);
			return;
		case -34:
			sub_0401AE(y, u);
			return;
		case -32:
			continue;
		case -30:
			sub_040358(y, u);
			return;
		case -28:
			sub_040471(y, u);
			return;
		case -26:
			sub_04063D(y, u);
			return;
		case -24:
			sub_040700(y, u);
			return;
		case -22:
			sub_040027(u);
			return;
		case -20:
			sub_0400AA();
			return;
		case -18:
			sub_040108();
			return;
		case -16:
			sub_04014B();
			return;
		case -14:
			sub_04019F();
			return;
		case -12:
			sub_0401B7();
			return;
		case -10:
			sub_040215();
			return;
		case -8:
			sub_040247();
			return;
		case -6:
			sub_040250();
			return;
		case -4:
			sub_040274();
			return;
		case -2:
			sub_04028D(u);
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_0402AE(void)
{
	uint16_t u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0xFFF0u;
	unk_48CE = 0x280u;
	unk_4876 = 1u;
	sub_040870();
	unk_4876 = 0u;
	sub_040897();
	unk_4876 = 1u;
	x = unk_4F80_ADDRESS;
	u = loaded_table_041070_ADDRESS;
	unk_4F89 = 0x20u;
	unk_4F86 = 0x40u;
	sub_04080D(&x, &u);
	unk_480B = 0x40u;
	unk_4804++;
}

void sub_0402EC(void)
{
	uint8_t t1 = 0;

	unk_4F86 = 0x40u;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_480B = 0x80u;
		unk_4804++;
	}
}

void sub_040300(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_07868C(&ignored16, &ignored16_2);
	sub_078698();
	unk_4804++;
}

void sub_04030F(void)
{
	uint16_t u = 0, x = 0;

	unk_48BE = 0x110u;
	sub_040870();
	x = unk_4F80_ADDRESS;
	u = loaded_table_0410BB_ADDRESS;
	sub_04076D(x, u);
	unk_480B = 0xE0u;
	unk_4883 = 0u;
	unk_4884 = 0u;
	unk_4804++;
}

void sub_040330(void)
{
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	d = 0x200u;
	sub_04082C(d);
	d = 0x300u;
	sub_04082C(d);
	x = unk_4F80_ADDRESS;
	d = 0x100u;
	sub_04078D(x, d);
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
		unk_4804++;
}

void sub_04034B(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	sub_07868C(&ignored16, &ignored16_2);
	sub_07869B(&ignored16, &ignored16_3);
	unk_4803++;
	unk_4804 = 0u;
}

void sub_040358(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_041032_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_040361();
			return;
		case 2:
			sub_0403B1();
			return;
		case 4:
			sub_0403E4();
			return;
		case 6:
			sub_0403F3();
			return;
		case 8:
			sub_040414();
			return;
		case 10:
			sub_04042F(u);
			return;
		case 12:
			sub_04047A();
			return;
		case 14:
			sub_040500();
			return;
		case 16:
			sub_040517();
			return;
		case 18:
			sub_040547();
			return;
		case 20:
			sub_0405A3(u);
			return;
		case 22:
			sub_0405E4();
			return;
		case 24:
			sub_040618();
			return;
		case 26:
			sub_040646();
			return;
		case 28:
			sub_040687();
			return;
		case 30:
			sub_0406A2();
			return;
		case 32:
			sub_0406CA();
			return;
		case 34:
			sub_0406EB();
			return;
		case 36:
			sub_040709(u);
			return;
		case 38:
			sub_040758(u);
			return;
		case 40:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 42:
		case 48:
			sub_0407CA(x);
			return;
		case 44:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 46:
			sub_0407EC(x, y);
			return;
		case 50:
			break;
		case -50:
			sub_04001E(y, u);
			return;
		case -48:
			sub_0400FF(y, u);
			return;
		case -46:
			sub_0401AE(y, u);
			return;
		case -44:
			sub_0402A5(y, u);
			return;
		case -42:
			continue;
		case -40:
			sub_040471(y, u);
			return;
		case -38:
			sub_04063D(y, u);
			return;
		case -36:
			sub_040700(y, u);
			return;
		case -34:
			sub_040027(u);
			return;
		case -32:
			sub_0400AA();
			return;
		case -30:
			sub_040108();
			return;
		case -28:
			sub_04014B();
			return;
		case -26:
			sub_04019F();
			return;
		case -24:
			sub_0401B7();
			return;
		case -22:
			sub_040215();
			return;
		case -20:
			sub_040247();
			return;
		case -18:
			sub_040250();
			return;
		case -16:
			sub_040274();
			return;
		case -14:
			sub_04028D(u);
			return;
		case -12:
			sub_0402AE();
			return;
		case -10:
			sub_0402EC();
			return;
		case -8:
			sub_040300();
			return;
		case -6:
			sub_04030F();
			return;
		case -4:
			sub_040330();
			return;
		case -2:
			sub_04034B();
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_040361(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0x240u;
	unk_48CE = 0x240u;
	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x40u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	unk_48BE = 0x2B0u;
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	x = unk_4F80_ADDRESS;
	u = loaded_table_041075_ADDRESS;
	sub_04080D(&x, &u);
	u = loaded_table_04107A_ADDRESS;
	sub_04080D(&x, &u);
	unk_480B = 0xF0u;
	unk_4804++;
}

void sub_0403B1(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	x = unk_4F80_ADDRESS;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_4F8F = 0u;
		mem_write16(x + 0x6Fu, 0u);
		unk_480B = 0xE0u;
		unk_4804++;
		return;
	}
	unk_4F8F = 0x80u;
	mem_write16(x + 0x6Fu, 0x80u);
	d = AT16(unk_48BE, -1);
	carry = d < 0x80u;
	AT16(unk_48BE, -1) = d - 0x80u;
	unk_48BE = (unk_48BE & 0xFFu) | (((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)(uint8_t)(unk_48BE >> 8u) << 8) >> 8) - carry) << 8) >> 8 & 0xFFu) << 8u);
}

void sub_0403E4(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	sub_040447();
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_07868C(&ignored16, &ignored16_2);
	unk_4804++;
}

void sub_0403F3(void)
{
	uint16_t u = 0, x = 0;

	unk_48BE = 0x3F0u;
	sub_040870();
	x = unk_4F80_ADDRESS;
	u = loaded_table_0410C5_ADDRESS;
	sub_04076D(x, u);
	unk_480B = 0xC0u;
	unk_4883 = 0u;
	unk_4884 = 0u;
	unk_4804++;
}

void sub_040414(void)
{
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	d = 0x400u;
	sub_04082C(d);
	d = 0x500u;
	sub_04082C(d);
	x = unk_4F80_ADDRESS;
	d = 0x200u;
	sub_04078D(x, d);
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
		unk_4804++;
}

void sub_04042F(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0, ignored16_4 = 0;

	unk_487E = 1u;
	d = 0x204u;
	sub_078677(d, &ignored16, &u);
	sub_07868C(&ignored16_2, &ignored16_3);
	sub_07869B(&ignored16_2, &ignored16_4);
	unk_4803++;
	unk_4804 = 0u;
}

void sub_040447(void)
{
	uint8_t a = 0;
	uint16_t x = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	x = unk_4F80_ADDRESS;
	if ((unk_4815 & 0xFu) == 0u)
	{
		t1 = (uint8_t)(unk_4FA8 >> 8u);
		t2 = t1 * 0xDu;
		AT8(unk_4FA8, 1) = t2 + 7u;
		a = (t2 >> 8) & 1u;
		stack = a;
		AS8(unk_4F84) = (a + 0x1Au) | 0x80u;
		unk_4FE5 = (stack + 0x1Cu) | 0x80u;
	}
}

void sub_040471(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_04103E_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_04047A();
			return;
		case 2:
			sub_040500();
			return;
		case 4:
			sub_040517();
			return;
		case 6:
			sub_040547();
			return;
		case 8:
			sub_0405A3(u);
			return;
		case 10:
			sub_0405E4();
			return;
		case 12:
			sub_040618();
			return;
		case 14:
			sub_040646();
			return;
		case 16:
			sub_040687();
			return;
		case 18:
			sub_0406A2();
			return;
		case 20:
			sub_0406CA();
			return;
		case 22:
			sub_0406EB();
			return;
		case 24:
			sub_040709(u);
			return;
		case 26:
			sub_040758(u);
			return;
		case 28:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 30:
		case 36:
			sub_0407CA(x);
			return;
		case 32:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 34:
			sub_0407EC(x, y);
			return;
		case 38:
			break;
		case -62:
			sub_04001E(y, u);
			return;
		case -60:
			sub_0400FF(y, u);
			return;
		case -58:
			sub_0401AE(y, u);
			return;
		case -56:
			sub_0402A5(y, u);
			return;
		case -54:
			sub_040358(y, u);
			return;
		case -52:
			continue;
		case -50:
			sub_04063D(y, u);
			return;
		case -48:
			sub_040700(y, u);
			return;
		case -46:
			sub_040027(u);
			return;
		case -44:
			sub_0400AA();
			return;
		case -42:
			sub_040108();
			return;
		case -40:
			sub_04014B();
			return;
		case -38:
			sub_04019F();
			return;
		case -36:
			sub_0401B7();
			return;
		case -34:
			sub_040215();
			return;
		case -32:
			sub_040247();
			return;
		case -30:
			sub_040250();
			return;
		case -28:
			sub_040274();
			return;
		case -26:
			sub_04028D(u);
			return;
		case -24:
			sub_0402AE();
			return;
		case -22:
			sub_0402EC();
			return;
		case -20:
			sub_040300();
			return;
		case -18:
			sub_04030F();
			return;
		case -16:
			sub_040330();
			return;
		case -14:
			sub_04034B();
			return;
		case -12:
			sub_040361();
			return;
		case -10:
			sub_0403B1();
			return;
		case -8:
			sub_0403E4();
			return;
		case -6:
			sub_0403F3();
			return;
		case -4:
			sub_040414();
			return;
		case -2:
			sub_04042F(u);
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_04047A(void)
{
	uint16_t d = 0, ignored16 = 0, u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0x510u;
	unk_48CE = 0x390u;
	sub_040870();
	unk_4876 = 0u;
	sub_040897();
	unk_4876 = 1u;
	x = unk_4F80_ADDRESS;
	u = loaded_table_04108E_ADDRESS;
	unk_4F89 = 0x10u;
	sub_04080D(&x, &u);
	u = loaded_table_041089_ADDRESS;
	mem_write8(x + 6u, 0x40u);
	mem_write8(x + 9u, 0x10u);
	sub_04080D(&x, &u);
	u = loaded_table_04109D_ADDRESS;
	mem_write16(x + 0x16u, 0x80u);
	sub_04080D(&x, &u);
	u = loaded_table_0410A2_ADDRESS;
	mem_write16(x + 0x16u, 0x80u);
	sub_04080D(&x, &u);
	x = 0x5100u;
	u = loaded_table_041093_ADDRESS;
	unk_5109 = 0x30u;
	unk_510F = 0xFA00u;
	unk_5114 = 0x1C0u;
	sub_04080D(&x, &u);
	mem_write8(x - 0x5Cu, 0xFu);
	unk_487E = 3u;
	d = 0x7A53u;
	sub_078677(d, &ignored16, &u);
	unk_480B = 0x50u;
	unk_4804++;
}

void sub_040500(void)
{
	uint8_t t1 = 0;

	unk_4FE6 = 0x40u;
	sub_040625();
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_480B = 0x18u;
		unk_4804++;
	}
}

void sub_040517(void)
{
	uint8_t t1 = 0;

	sub_040625();
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
	{
		sub_040567();
		return;
	}
	unk_4F84 = (unk_4F84 & 0xFF00u) | 0xA4u;
	unk_4F8C = 0x10Fu;
	unk_4F91 = 0x98u;
	unk_4FA8 &= 0xFFu;
	unk_4FE5 |= 0x80u;
	unk_480B = 0x50u;
	unk_4804++;
}

void sub_040547(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, x = 0;
	uint8_t t1 = 0;

	x = sub_040625();
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
	{
		sub_040567();
		return;
	}
	mem_write8(x + 0x28u, 0u);
	sub_078698();
	sub_07868C(&ignored16_2, &u);
	unk_487E = 3u;
	d = 0u;
	sub_078677(d, &ignored16, &u);
	unk_4804++;
}

void sub_040567(void)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	x = unk_4F80_ADDRESS;
	unk_4FA8 = (unk_4FA8 & 0xFFu) | (((uint8_t)(unk_4FA8 >> 8u) + 1u & 0xFFu) << 8u);
	a = (uint8_t)(unk_4FA8 >> 8u);
	if (a == 0xFu)
	{
		AS8(unk_4F84) = 0x99u;
		unk_4F8C = 0x130u;
		unk_4F91 = 0x96u;
		d = 0x4300u;
		carry = sub_078680(d);
		return;
	}
	if (a == 0x1Eu)
	{
		AS8(unk_4F84) = 0xA4u;
		unk_4F8C = 0x10Fu;
		unk_4F91 = 0x98u;
		return;
	}
}

void sub_0405A3(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, u_2 = 0, x = 0;

	unk_487E = 2u;
	d = 1u;
	sub_078677(d, &ignored16, &u);
	AT16(unk_4FA8, -1) = u;
	sub_0408BF();
	unk_48BE = 0xFFF0u;
	unk_48CE = 0xFFF0u;
	unk_4876 = 2u;
	sub_040870();
	x = unk_4F80_ADDRESS;
	u_2 = loaded_table_0410CF_ADDRESS;
	x = sub_04076D(x, u_2);
	u_2 = loaded_table_0410D9_ADDRESS;
	sub_04076D(x, u_2);
	unk_480B = 0xE0u;
	unk_4883 = 0u;
	unk_4884 = 0u;
	unk_4804++;
}

void sub_0405E4(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, x = 0;
	uint8_t t1 = 0;

	d = 0x600u;
	sub_04082C(d);
	d = 0x700u;
	sub_04082C(d);
	if ((unk_4815 & 0xFu) == 0u)
	{
		d = 0x4500u;
		carry = sub_078680(d);
	}
	x = unk_4F80_ADDRESS;
	d = 0x300u;
	sub_04078D(x, d);
	x = unk_5040_ADDRESS;
	d = 0x400u;
	sub_04078D(x, d);
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		mem_write8(AT16(unk_4FA8, -1), 0u);
		unk_4804++;
	}
}

void sub_040618(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	sub_07868C(&ignored16, &ignored16_2);
	sub_07869B(&ignored16, &ignored16_3);
	unk_4803++;
	unk_4804 = 0u;
}

uint16_t sub_040625(void)
{
	uint16_t x = 0;

	x = 0x5100u;
	if ((int16_t)unk_510C <= 0)
	{
		unk_510C = 0x1A0u;
		mem_write16(x + 0x11u, VIDEO_00C0);
	}
	return x;
}

void sub_04063D(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_04104C_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_040646();
			return;
		case 2:
			sub_040687();
			return;
		case 4:
			sub_0406A2();
			return;
		case 6:
			sub_0406CA();
			return;
		case 8:
			sub_0406EB();
			return;
		case 10:
			sub_040709(u);
			return;
		case 12:
			sub_040758(u);
			return;
		case 14:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 16:
		case 22:
			sub_0407CA(x);
			return;
		case 18:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 20:
			sub_0407EC(x, y);
			return;
		case 24:
			break;
		case -76:
			sub_04001E(y, u);
			return;
		case -74:
			sub_0400FF(y, u);
			return;
		case -72:
			sub_0401AE(y, u);
			return;
		case -70:
			sub_0402A5(y, u);
			return;
		case -68:
			sub_040358(y, u);
			return;
		case -66:
			sub_040471(y, u);
			return;
		case -64:
			continue;
		case -62:
			sub_040700(y, u);
			return;
		case -60:
			sub_040027(u);
			return;
		case -58:
			sub_0400AA();
			return;
		case -56:
			sub_040108();
			return;
		case -54:
			sub_04014B();
			return;
		case -52:
			sub_04019F();
			return;
		case -50:
			sub_0401B7();
			return;
		case -48:
			sub_040215();
			return;
		case -46:
			sub_040247();
			return;
		case -44:
			sub_040250();
			return;
		case -42:
			sub_040274();
			return;
		case -40:
			sub_04028D(u);
			return;
		case -38:
			sub_0402AE();
			return;
		case -36:
			sub_0402EC();
			return;
		case -34:
			sub_040300();
			return;
		case -32:
			sub_04030F();
			return;
		case -30:
			sub_040330();
			return;
		case -28:
			sub_04034B();
			return;
		case -26:
			sub_040361();
			return;
		case -24:
			sub_0403B1();
			return;
		case -22:
			sub_0403E4();
			return;
		case -20:
			sub_0403F3();
			return;
		case -18:
			sub_040414();
			return;
		case -16:
			sub_04042F(u);
			return;
		case -14:
			sub_04047A();
			return;
		case -12:
			sub_040500();
			return;
		case -10:
			sub_040517();
			return;
		case -8:
			sub_040547();
			return;
		case -6:
			sub_0405A3(u);
			return;
		case -4:
			sub_0405E4();
			return;
		case -2:
			sub_040618();
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_040646(void)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, x = 0;

	sub_0408BF();
	unk_48BE = 0x110u;
	unk_48CE = 0x110u;
	sub_040870();
	d = 0x4400u;
	carry = sub_078680(d);
	x = unk_4F80_ADDRESS;
	u = loaded_table_0410A7_ADDRESS;
	unk_4F99 = VIDEO_0C00;
	sub_04080D(&x, &u);
	u = loaded_table_041098_ADDRESS;
	mem_write8(x + 6u, 0x40u);
	sub_04080D(&x, &u);
	u = loaded_table_0410AC_ADDRESS;
	sub_04080D(&x, &u);
	mem_write8(x - 0x60u, 0u);
	unk_480B = 0x10u;
	unk_4804++;
}

void sub_040687(void)
{
	uint16_t x = 0;
	uint8_t t1 = 0;

	x = unk_4F80_ADDRESS;
	unk_4FE6 = 0x40u;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_480B = 0x30u;
		unk_4F99 = 0u;
		unk_4804++;
		return;
	}
}

void sub_0406A2(void)
{
	uint16_t x = 0;
	uint8_t t1 = 0;

	x = unk_4F80_ADDRESS;
	unk_4FE6 = 0x40u;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_4F8C = 0xD8u;
		unk_4F91 = 0x100u;
		unk_4F99 = 0xF400u;
		unk_480B = 0xCu;
		unk_4804++;
	}
}

void sub_0406CA(void)
{
	uint16_t x = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	x = unk_4F80_ADDRESS;
	unk_4FE6 = 0x40u;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 == 1u)
	{
		unk_4F80 = 0u;
		t2 = mem_read16(x + 0x71u);
		t3 = t2 + 4u;
		mem_write16(x + 0x71u, t3);
		unk_480B = 0x50u;
		unk_4804++;
	}
}

void sub_0406EB(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	unk_5040 = 0x80u;
	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
		return;
	sub_07868C(&ignored16, &ignored16_2);
	unk_4804 = 0u;
	unk_4803++;
}

void sub_040700(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;

	for (;;)
	{
		x = loaded_table_041056_ADDRESS;
		a = (uint32_t)unk_4804 << 1;
		switch ((int8_t)a)
		{
		case 0:
			sub_040709(u);
			return;
		case 2:
			sub_040758(u);
			return;
		case 4:
			d = (uint32_t)a << 8;
			sub_04079E(x, y, d);
			return;
		case 6:
		case 12:
			sub_0407CA(x);
			return;
		case 8:
			d = (uint32_t)a << 8;
			sub_0407E0(x, d);
			return;
		case 10:
			sub_0407EC(x, y);
			return;
		case 14:
			break;
		case -86:
			sub_04001E(y, u);
			return;
		case -84:
			sub_0400FF(y, u);
			return;
		case -82:
			sub_0401AE(y, u);
			return;
		case -80:
			sub_0402A5(y, u);
			return;
		case -78:
			sub_040358(y, u);
			return;
		case -76:
			sub_040471(y, u);
			return;
		case -74:
			sub_04063D(y, u);
			return;
		case -72:
			continue;
		case -70:
			sub_040027(u);
			return;
		case -68:
			sub_0400AA();
			return;
		case -66:
			sub_040108();
			return;
		case -64:
			sub_04014B();
			return;
		case -62:
			sub_04019F();
			return;
		case -60:
			sub_0401B7();
			return;
		case -58:
			sub_040215();
			return;
		case -56:
			sub_040247();
			return;
		case -54:
			sub_040250();
			return;
		case -52:
			sub_040274();
			return;
		case -50:
			sub_04028D(u);
			return;
		case -48:
			sub_0402AE();
			return;
		case -46:
			sub_0402EC();
			return;
		case -44:
			sub_040300();
			return;
		case -42:
			sub_04030F();
			return;
		case -40:
			sub_040330();
			return;
		case -38:
			sub_04034B();
			return;
		case -36:
			sub_040361();
			return;
		case -34:
			sub_0403B1();
			return;
		case -32:
			sub_0403E4();
			return;
		case -30:
			sub_0403F3();
			return;
		case -28:
			sub_040414();
			return;
		case -26:
			sub_04042F(u);
			return;
		case -24:
			sub_04047A();
			return;
		case -22:
			sub_040500();
			return;
		case -20:
			sub_040517();
			return;
		case -18:
			sub_040547();
			return;
		case -16:
			sub_0405A3(u);
			return;
		case -14:
			sub_0405E4();
			return;
		case -12:
			sub_040618();
			return;
		case -10:
			sub_040646();
			return;
		case -8:
			sub_040687();
			return;
		case -6:
			sub_0406A2();
			return;
		case -4:
			sub_0406CA();
			return;
		case -2:
			sub_0406EB();
			return;
		}
		break;
	}
	sub_04080C();
}

void sub_040709(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, u_2 = 0;

	sub_0408BF();
	unk_48BE = 0xFFF0u;
	unk_48CE = 0xFFF0u;
	unk_487E = 1u;
	d = 0xD01u;
	sub_078677(d, &ignored16, &u);
	unk_487E = 1u;
	d = 0x20Cu;
	sub_078677(d, &ignored16, &u);
	unk_4875 = 0u;
	unk_4876 = 3u;
	sub_040870();
	unk_4875 = 2u;
	unk_4876 = 0u;
	u_2 = sub_040897();
	unk_487E = 3u;
	d = 0x7FFFu;
	sub_078677(d, &ignored16, &u_2);
	unk_480B = 0x80u;
	unk_4883 = 0u;
	unk_4804++;
}

void sub_040758(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	t1 = unk_480B;
	unk_480B = t1 - 1u;
	if (t1 != 1u)
		return;
	unk_487E = 3u;
	d = 0u;
	sub_078677(d, &ignored16, &u);
	unk_4802++;
}

uint16_t sub_04076D(uint16_t x, uint16_t u)
{
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 0x28u, 0x60u);
	sub_04080D(&x, &u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	sub_04080D(&x, &u);
	return x;
}

void sub_04078D(uint16_t x, uint16_t d)
{
	uint8_t b = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = loaded_table_04105A_ADDRESS;
	y = profile_moves[((d | b) >> 8) & 0x7Fu];
	t1 = mem_read8(x + 1u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_04079E(x, y, d);
		return;
	case 2:
	case 8:
		sub_0407CA(x);
		return;
	case 4:
		sub_0407E0(x, d);
		return;
	case 6:
		sub_0407EC(x, y);
		return;
	case 10:
		sub_04080C();
		return;
	case -90:
		sub_04001E(y, u);
		return;
	case -88:
		sub_0400FF(y, u);
		return;
	case -86:
		sub_0401AE(y, u);
		return;
	case -84:
		sub_0402A5(y, u);
		return;
	case -82:
		sub_040358(y, u);
		return;
	case -80:
		sub_040471(y, u);
		return;
	case -78:
		sub_04063D(y, u);
		return;
	case -76:
		sub_040700(y, u);
		return;
	case -74:
		sub_040027(u);
		return;
	case -72:
		sub_0400AA();
		return;
	case -70:
		sub_040108();
		return;
	case -68:
		sub_04014B();
		return;
	case -66:
		sub_04019F();
		return;
	case -64:
		sub_0401B7();
		return;
	case -62:
		sub_040215();
		return;
	case -60:
		sub_040247();
		return;
	case -58:
		sub_040250();
		return;
	case -56:
		sub_040274();
		return;
	case -54:
		sub_04028D(u);
		return;
	case -52:
		sub_0402AE();
		return;
	case -50:
		sub_0402EC();
		return;
	case -48:
		sub_040300();
		return;
	case -46:
		sub_04030F();
		return;
	case -44:
		sub_040330();
		return;
	case -42:
		sub_04034B();
		return;
	case -40:
		sub_040361();
		return;
	case -38:
		sub_0403B1();
		return;
	case -36:
		sub_0403E4();
		return;
	case -34:
		sub_0403F3();
		return;
	case -32:
		sub_040414();
		return;
	case -30:
		sub_04042F(u);
		return;
	case -28:
		sub_04047A();
		return;
	case -26:
		sub_040500();
		return;
	case -24:
		sub_040517();
		return;
	case -22:
		sub_040547();
		return;
	case -20:
		sub_0405A3(u);
		return;
	case -18:
		sub_0405E4();
		return;
	case -16:
		sub_040618();
		return;
	case -14:
		sub_040646();
		return;
	case -12:
		sub_040687();
		return;
	case -10:
		sub_0406A2();
		return;
	case -8:
		sub_0406CA();
		return;
	case -6:
		sub_0406EB();
		return;
	case -4:
		sub_040709(u);
		return;
	case -2:
		sub_040758(u);
		return;
	}
}

void sub_04079E(uint16_t x, uint16_t move, uint16_t d)
{
	uint16_t profile_move = 0, speed_x = 0, speed_y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 != 1u)
		return;
	stack = d >> 8;
	t2 = move;
	speed_x = PROFILE_MOVE(t2)->speed_x;
	mem_write16(x + 0xFu, speed_x);
	mem_write16(x + 0x6Fu, speed_x);
	t3 = t2 + 2u;
	profile_move = t3 + 2u;
	speed_y = PROFILE_MOVE(t3 - 0x2u)->speed_y;
	mem_write16(x + 0x14u, speed_y);
	mem_write16(x + 0x74u, speed_y);
	if ((uint16_t)((uint32_t)stack << 8) >> 8 == 4u)
		mem_write16(x + 0x6Fu, 0xFF00u);
	mem_write8(x + 0x28u, (uint16_t)((uint32_t)PROFILE_MOVE(profile_move - 0x4u)->frames << 8) >> 8);
	t4 = mem_read8(x + 1u);
	mem_write8(x + 1u, t4 + 1u);
}

void sub_0407CA(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x6Fu, 0u);
		mem_write16(x + 0x74u, 0u);
		t2 = mem_read8(x + 1u);
		mem_write8(x + 1u, t2 + 1u);
	}
}

void sub_0407E0(uint16_t x, uint16_t d)
{
	uint8_t t1 = 0;

	if (d >> 8 == 0u)
	{
		mem_write8(x + 0x28u, 0x40u);
		t1 = mem_read8(x + 1u);
		mem_write8(x + 1u, t1 + 1u);
	}
}

void sub_0407EC(uint16_t x, uint16_t move)
{
	uint16_t d = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = move;
		d = 0u - PROFILE_MOVE(t2)->speed_x;
		mem_write16(x + 0xFu, d);
		mem_write16(x + 0x6Fu, d);
		t3 = t2 + 2u;
		d = 0u - PROFILE_MOVE(t3 - 0x2u)->speed_y;
		mem_write16(x + 0x14u, d);
		mem_write16(x + 0x74u, d);
		d = (uint32_t)PROFILE_MOVE(t3 - 0x2u)->frames << 8;
		mem_write8(x + 0x28u, d >> 8);
		t4 = mem_read8(x + 1u);
		mem_write8(x + 1u, t4 + 1u);
	}
}

void sub_04080C(void)
{
}

void sub_04080D(uint16_t *p_x, uint16_t *p_u)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 4u, 0xEu);
	t1 = u;
	mem_write8(x + 5u, mem_read8(t1) | 0x80u);
	t2 = t1 + 1u;
	t3 = mem_read16(t2);
	mem_write16(x + 0xCu, t3);
	t4 = t2 + 2u;
	u_2 = t4 + 2u;
	t5 = mem_read16(t4);
	mem_write16(x + 0x11u, t5);
	x += 0x60u;
	*p_x = x;
	*p_u = u_2;
}

void sub_04082C(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint32_t unk_48F1_halfword = 0, unk_48F1_halfword_2 = 0;

	t1 = profile_texts[(d >> 8) & 0x7Fu];
	x = t1 + 2u;
	t2 = mem_read16(t1);
	unk_48F3 = (uint8_t)(t2 >> 8u);
	unk_48F4 = (uint8_t)t2;
	a = 0u;
	for (;;)
	{
		unk_48F1_halfword = (((uint32_t)unk_48F1 << 8u) | unk_48F2) + 1u;
		unk_48F1 = (uint8_t)(unk_48F1_halfword >> 8u);
		unk_48F2 = (uint8_t)unk_48F1_halfword;
		t3 = x;
		x = t3 + 1u;
		b = mem_read8(t3);
		if (b == 0xFFu)
			return;
		if (b == 0xFEu)
		{
			t4 = x;
			unk_48F1_halfword_2 = mem_read16(t4);
			unk_48F1 = (uint8_t)(unk_48F1_halfword_2 >> 8u);
			unk_48F2 = (uint8_t)unk_48F1_halfword_2;
			unk_48F0 = 0u;
			t5 = t4 + 2u;
			x = t5 + 1u;
			b = mem_read8(t5);
		}
		if (a == mem_read8((((uint32_t)unk_48F3 << 8u) | unk_48F4)))
			break;
		a++;
	}
	x = (((uint32_t)unk_48F1 << 8u) | unk_48F2);
	mem_write8(x, b - 0x30u);
	mem_write8(x - 0x2000u, unk_48F0);
	t6 = (((uint32_t)unk_48F3 << 8u) | unk_48F4);
	mem_write8(t6, mem_read8(t6) + 1u);
}

uint16_t sub_04086B(void)
{
	uint16_t u = 0;

	sub_040870();
	u = sub_040897();
	return u;
}

void sub_040870(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, ignored16_3 = 0;

	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x26u;
	sub_0786AD(d, &ignored16, &ignored16_2, &ignored16_3);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
}

uint16_t sub_040897(void)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0;

	io_write8(IO_1FB9, 0x3Fu);
	io_write8(IO_1FBA, 0x36u);
	d = 0x126u;
	sub_0786AD(d, &ignored16, &ignored16_2, &u);
	io_write8(IO_1FB9, 0x13u);
	io_write8(IO_1FBA, 0x2Cu);
	return u;
}

void sub_0408BF(void)
{
	unk_48BE = 0u;
	unk_48CE = 0u;
	unk_48C5 = 0u;
	unk_48D5 = 0u;
	unk_48C3 = 0u;
	unk_48D3 = 0u;
	unk_48CA = 0u;
	unk_48DA = 0u;
	unk_489C = 0u;
	unk_48A9 = 0u;
	unk_4899 = 0u;
}

void sub_040946(uint16_t x)
{
	uint16_t d = 0, x_2 = 0;
	uint16_t score = 0, score_tiles = 0;

	score = GAUGE_PLAYER(x)->score;
	d = mem_read16(score);
	score_tiles = GAUGE_PLAYER(x)->score_tiles;
	x_2 = score_tiles;
	sub_0786A7(x_2, d);
}

void sub_040953(uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, gauge_player = 0, u = 0;
	uint8_t t2 = 0, number = 0, number_2 = 0, number_3 = 0, number_4 = 0, number_5 = 0, number_6 = 0;
	uint16_t status = 0, lives_tiles = 0, lives = 0, t1 = 0, status_2 = 0, continue_tiles = 0, counters = 0;

	gauge_player = gauge_player_records[(int8_t)((uint8_t)((uint32_t)(d >> 8) << 1)) / 2];
	status = GAUGE_PLAYER(gauge_player)->status;
	if (mem_read8(status) == 2u)
	{
		lives_tiles = GAUGE_PLAYER(gauge_player)->lives_tiles;
		u = lives_tiles;
		lives = GAUGE_PLAYER(gauge_player)->lives;
		t1 = mem_read16(lives);
		b = (uint8_t)t1;
		if ((uint16_t)(((uint32_t)(t1 >> 8) << 8) | b) > 0xFFu)
			b = 0xFFu;
		d_2 = (uint8_t)(b - 1u);
		sub_0409CF(&u, &d_2, &carry);
		a = (uint8_t)(d_2 >> 8);
		if (carry)
			a = 0x99u;
		d_2 = (d_2 & 0xFFu) | ((uint32_t)a << 8);
		sub_040AA8(gauge_player, u, d_2);
		sub_040B0C(gauge_player);
		gauge_player = sub_0409F2(gauge_player);
		t2 = mem_read8(gauge_player + 1u);
		d_2 = (uint32_t)t2 << 8;
		sub_040BCE(d_2);
		return;
	}
	number = GAUGE_PLAYER(gauge_player)->number;
	d_2 = ((uint32_t)number << 8) | 0xAu;
	sub_040BCE(d_2);
	number_2 = GAUGE_PLAYER(gauge_player)->number;
	d_2 = ((uint32_t)number_2 << 8) | 1u;
	sub_040BCE(d_2);
	status_2 = GAUGE_PLAYER(gauge_player)->status;
	a = mem_read8(status_2);
	if (a == 3u)
	{
		continue_tiles = GAUGE_PLAYER(gauge_player)->continue_tiles;
		u = continue_tiles;
		counters = GAUGE_PLAYER(gauge_player)->counters;
		d_2 = (d_2 & 0xFFu) | ((uint32_t)mem_read8(counters) << 8);
		sub_040AA8(gauge_player, u, d_2);
		number_3 = GAUGE_PLAYER(gauge_player)->number;
		d_2 = ((uint32_t)number_3 << 8) | 2u;
		sub_040BCE(d_2);
		return;
	}
	if (a == 4u)
	{
		number_4 = GAUGE_PLAYER(gauge_player)->number;
		d_2 = ((uint32_t)number_4 << 8) | 4u;
		sub_040BCE(d_2);
		return;
	}
	if (a == 1u || a == 5u)
	{
		number_5 = GAUGE_PLAYER(gauge_player)->number;
		d_2 = ((uint32_t)number_5 << 8) | 5u;
		sub_040BCE(d_2);
		return;
	}
	number_6 = GAUGE_PLAYER(gauge_player)->number;
	d_2 = ((uint32_t)number_6 << 8) | 3u;
	sub_040BCE(d_2);
}

void sub_0409CF(uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint16_t u = (uint16_t)*p_u;
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint32_t half_carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	b = (uint8_t)d;
	stack_2 = u >> 8;
	stack = (uint8_t)u;
	u_2 = loaded_table_04177A_ADDRESS;
	stack_4 = 8u;
	carry = 0u;
	a = 0u;
	do
	{
		if ((b & 1u) != 0u)
		{
			t1 = mem_read8(u_2);
			t2 = a + t1;
			half_carry = ((a ^ t1 ^ t2) >> 4) & 1u;
			carry = (uint8_t)(a + t1) < a;
			a = t2;
			t3 = konami_daa(a, half_carry, carry);
			carry = konami_daa_carry(a, half_carry, carry);
			a = t3;
		}
		if (carry)
			break;
		u_2++;
		b = b >> 1;
		carry = 0u;
		t4 = stack_4;
		stack_4 = t4 - 1u;
	} while (t4 != 1u);
	u_2 = ((uint32_t)stack_2 << 8) | stack;
	d_2 = ((uint32_t)a << 8) | b;
	*p_u = u_2;
	*p_d = d_2;
	*p_carry = carry;
}

uint16_t sub_0409F2(uint16_t x)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0, bottom = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0;
	uint16_t counters = 0, health = 0, t2 = 0, t6 = 0, t7 = 0;

	counters = GAUGE_PLAYER(x)->counters;
	u = counters;
	a = 0x1Fu;
	health = GAUGE_PLAYER(x)->health;
	t1 = mem_read8(health);
	b = t1;
	if (t1 != 0u)
	{
		t2 = (uint32_t)a * b;
		stack_2 = x >> 8;
		stack = (uint8_t)x;
		stack_3 = t2;
		stack_4 = t2 >> 8;
		stack_3 = konami_divx((uint16_t)(((uint32_t)stack_4 << 8) | stack_3), 0x28u);
		b = stack_3 + 1u;
		x = ((uint32_t)stack_2 << 8) | stack;
	}
	t3 = mem_read8(u + 2u);
	zero = (uint8_t)(b - t3) == 0u;
	carry = b < t3;
	if (b == t3)
		b = 2u;
	else if (carry | zero)
		b = 1u;
	else
		b = 0u;
	t4 = mem_read8(u + 2u);
	a = t4;
	t5 = mem_read8(u + 3u);
	if (t5 != 0u)
		return x;
	if (b != 2u)
	{
		if (b == 1u)
			a--;
		else
			a++;
		mem_write8(u + 2u, a);
		mem_write8(u + 3u, 2u);
	}
	t6 = mem_read16(x + 0xEu);
	u = t6;
	stack = 4u;
	do
	{
		if (a == 0u)
		{
			stack_2 = a;
			mem_write8(u, 0x8Du);
			mem_write8(u - 0x2000u, 0xC0u);
			mem_write8(u + 0x40u, 0x9Du);
			mem_write8(u - 0x1FC0u, 0xC0u);
			a = stack_2;
		}
		else
		{
			if (a > 8u)
			{
				stack_2 = a;
				mem_write8(u, 0x85u);
				mem_write8(u - 0x2000u, 0xC0u);
				mem_write8(u + 0x40u, 0x95u);
				mem_write8(u - 0x1FC0u, 0xC0u);
				a = stack_2;
			}
			else
			{
				stack_2 = a;
				t7 = gauge_step_tiles_ADDRESS + (int8_t)((uint32_t)a << 1);
				mem_write8(u, GAUGE_STEP(t7)->top);
				mem_write8(u - 0x2000u, 0xC0u);
				bottom = GAUGE_STEP(t7)->bottom;
				mem_write8(u + 0x40u, bottom);
				mem_write8(u - 0x1FC0u, 0xC0u);
				a = stack_2;
			}
			t8 = a;
			a = t8 - 8u;
			if (t8 < 8u)
				a = 0u;
		}
		u++;
		t9 = stack;
		stack = t9 - 1u;
	} while (t9 != 1u);
	return x;
}

void sub_040AA8(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, bottom = 0;
	uint16_t y = 0;
	uint8_t stack_F = 0, stack = 0;
	uint8_t number = 0, t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	stack = d >> 8;
	number = GAUGE_PLAYER(x)->number;
	stack_F = GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)(((uint32_t)number << 1) + 1u))->column;
	y = big_digits_ADDRESS;
	t1 = stack & ~0xFu;
	a = t1;
	if (t1 == 0u)
		a = 0xA0u;
	t2 = y + ((a >> 1) >> 1);
	a = BIG_DIGIT(t2)->attribute | stack_F;
	mem_write8(u - 0x2000u, a);
	mem_write8(u - 0x1FC0u, a);
	t3 = t2 + 1u;
	mem_write8(u, BIG_DIGIT(t3 - 0x1u)->top);
	bottom = BIG_DIGIT(t3 - 0x1u)->bottom;
	mem_write8(u + 0x40u, bottom);
	u++;
	t4 = big_digits_ADDRESS + (uint8_t)(((stack & 0xFu) << 1) << 1);
	a = BIG_DIGIT(t4)->attribute | stack_F;
	mem_write8(u - 0x2000u, a);
	mem_write8(u - 0x1FC0u, a);
	t5 = t4 + 1u;
	mem_write8(u, BIG_DIGIT(t5 - 0x1u)->top);
	bottom = BIG_DIGIT(t5 - 0x1u)->bottom;
	mem_write8(u + 0x40u, bottom);
}

void sub_040B0C(uint16_t x)
{
	uint16_t d = 0;
	uint8_t number = 0;

	number = GAUGE_PLAYER(x)->number;
	d = ((uint32_t)number << 8) | (uint8_t)(number + 6u);
	sub_040BCE(d);
}

void sub_040B44(void)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, x = 0;
	uint8_t stack = 0, stack_2 = 0;

	a = unk_4A1C;
	stack = a;
	a = (((a >> 1) >> 1) >> 1) >> 1;
	stack_2 = a;
	u = continue_digit_pictures[a & 0x7Fu];
	x = 0x2418u;
	a = stack_2;
	if (a == 0u)
		a = 0x80u;
	d = (uint32_t)a << 8;
	sub_040B88(x, u, d);
	u = continue_digit_pictures[stack & 0xFu];
	x = 0x2420u;
	d = 0u;
	sub_040B88(x, u, d);
}

void sub_040B73(void)
{
	uint16_t d = 0, u = 0, x = 0;

	x = 0x2418u;
	u = indexed_table_041405_ADDRESS;
	d = loaded_table_078000_ADDRESS;
	sub_040B88(x, u, d);
	x = 0x2420u;
	u = indexed_table_041405_ADDRESS;
	d = loaded_table_078000_ADDRESS;
	sub_040B88(x, u, d);
}

void sub_040B88(uint16_t x, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0, stack_5 = 0;
	uint8_t t5 = 0, t8 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;

	stack = d >> 8;
	t1 = u;
	t2 = mem_read16(t1);
	stack_2 = t2;
	stack_3 = t2 >> 8;
	t3 = t1 + 2u;
	u_2 = t3 + 1u;
	stack_5 = mem_read8(t3);
	do
	{
		stack_4 = stack_3;
		if ((int8_t)stack < 0)
		{
			a = 0x10u;
			b = 0u;
			do
			{
				mem_write8(x - 0x2000u, b);
				t4 = x;
				x = t4 + 1u;
				mem_write8(t4, a);
				t5 = stack_4;
				stack_4 = t5 - 1u;
			} while (t5 != 1u);
		}
		else
		{
			b = stack_5;
			do
			{
				mem_write8(x - 0x2000u, b);
				t6 = u_2;
				u_2 = t6 + 1u;
				t7 = x;
				x = t7 + 1u;
				mem_write8(t7, mem_read8(t6));
				t8 = stack_4;
				stack_4 = t8 - 1u;
			} while (t8 != 1u);
		}
		x += (int8_t)(0x40u - stack_3);
		t9 = stack_2;
		stack_2 = t9 - 1u;
	} while (t9 != 1u);
}

void sub_040BCE(uint16_t d)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, x = 0;
	uint8_t stack_E = 0, stack_F = 0, stack = 0, stack_11 = 0, stack_12 = 0, stack_13 = 0, stack_14 = 0, stack_15 = 0, stack_16 = 0;
	uint8_t t7 = 0, t8 = 0;
	uint16_t column = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t9 = 0;

	a = (uint8_t)(d >> 8);
	stack_16 = a;
	stack = a & 0x7Fu;
	stack_F = (uint8_t)d;
	column = (((uint32_t)GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->column << 8u) | GAUGE_COLUMN(gauge_player_columns_ADDRESS + (int8_t)((uint32_t)stack << 1))->colour);
	stack_11 = column >> 8;
	stack_13 = column;
	x = gauge_pictures[(int8_t)((uint8_t)((uint32_t)stack_F << 1)) / 2];
	do
	{
		t1 = x;
		u = mem_read16(t1) + (int8_t)stack_11;
		t2 = t1 + 2u;
		stack_15 = mem_read8(t2);
		t3 = t2 + 1u;
		stack_14 = mem_read8(t3);
		t4 = t3 + 1u;
		x = t4 + 1u;
		a = mem_read8(t4) | stack_13;
		if ((int8_t)stack_16 < 0)
			a = 0u;
		stack_E = a;
		do
		{
			stack_12 = stack_15;
			b = stack_E;
			do
			{
				mem_write8(u - 0x2000u, b);
				t5 = x;
				x = t5 + 1u;
				t6 = u;
				u = t6 + 1u;
				mem_write8(t6, mem_read8(t5));
				t7 = stack_12;
				stack_12 = t7 - 1u;
			} while (t7 != 1u);
			u += (int8_t)(0x40u - stack_15);
			t8 = stack_14;
			stack_14 = t8 - 1u;
		} while (t8 != 1u);
		t9 = x;
		x = t9 + 1u;
	} while (mem_read8(t9) == 0u);
}

void sub_040C61(void)
{
	unk_4863++;
}

void sub_040C65(void)
{
	uint8_t a = 0;
	uint16_t amounts = 0;

	amounts = rank_base_ADDRESS;
	if (unk_4811 != 0u)
		a = 1u;
	else
		a = unk_4814;
	unk_4861 += RANK_AMOUNT(amounts + (int8_t)a);
}

void sub_040C7D(void)
{
	unk_4861 += rank_by_players[(int8_t)((uint8_t)(unk_4857 - 1u))];
}

void sub_040C8D(void)
{
	uint8_t a = 0;
	uint16_t t1 = 0;

	t1 = unk_4863;
	if (t1 < rank_step_times[(int8_t)((uint8_t)((uint32_t)unk_4867 << 1)) / 2])
	{
		unk_4861 += unk_4862;
		return;
	}
	unk_4862++;
	a = 5u;
	if (unk_4862 > 5u)
		unk_4862 = a;
	unk_4863 = 0u;
	unk_4861 += unk_4862;
}

void sub_040CB7(void)
{
	unk_4861 += rank_by_scene[(int8_t)unk_4867];
}

void sub_040CC6(void)
{
	uint16_t t1 = 0;

	t1 = unk_4865;
}

void sub_040CD7(void)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t u = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	t1 = unk_4893;
	t2 = t1 + 1u;
	unk_4893 = t2;
	if (unk_488F != 0u)
		unk_4893 = 0u;
	t3 = io_read8(VIDEO_1883);
	if (t3 != 0u)
		unk_4893 = 0u;
	if (unk_4892 == 0u)
		unk_4893 = 0u;
	if (unk_48A7 != 0u)
		unk_4893 = 0u;
	if (unk_48A8 != 0u)
		unk_4893 = 0u;
	if (unk_48DE != 0u)
		unk_4893 = 0u;
	t4 = unk_4893;
	if (t4 < 0x100u)
		return;
	d = 2u;
	sub_07867D(d, &u, &carry);
	unk_4890 = u;
	unk_488F = 1u;
	mem_write8(u + 1u, 8u);
	unk_4893 = 0u;
}

void sub_040D36(void)
{
	uint8_t a = 0;

	a = (unk_4857 - 1u) & 3u;
	if (unk_4811 != 0u)
		a++;
	else
		a += unk_4814;
	unk_486B = a;
}
