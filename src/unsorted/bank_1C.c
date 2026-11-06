/**
 *    Name:        unsorted/bank_1C.c
 *    Description: bank 1C's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_038000(void)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0;
	uint16_t t6 = 0;

	t1 = io_read8(VIDEO_184C);
	io_write8(VIDEO_184C, 0u);
	t2 = io_read8(VIDEO_184D);
	io_write8(VIDEO_184D, 0u);
	unk_48E6 = 0u;
	stack = unk_4840;
	stack_10002 = unk_4842;
	y = ((uint32_t)stack << 8) | stack_10002;
	u = unk_4A40_ADDRESS;
	x = unk_49D0_ADDRESS;
	io_write16(VIDEO_1848, unk_49D0_ADDRESS);
	d = 0x100u;
	sub_0380AB(x, y, u, d);
	stack = unk_4844;
	stack_10002 = unk_4846;
	y = ((uint32_t)stack << 8) | stack_10002;
	u = unk_4B00_ADDRESS;
	x = unk_49D8_ADDRESS;
	io_write16(VIDEO_1848, unk_49D8_ADDRESS);
	d = 0x201u;
	sub_0380AB(x, y, u, d);
	stack = unk_4848;
	stack_10002 = unk_484A;
	y = ((uint32_t)stack << 8) | stack_10002;
	u = unk_4BC0_ADDRESS;
	x = unk_49E0_ADDRESS;
	io_write16(VIDEO_1848, unk_49E0_ADDRESS);
	d = 0x402u;
	sub_0380AB(x, y, u, d);
	stack = unk_484C;
	stack_10002 = unk_484E;
	y = ((uint32_t)stack << 8) | stack_10002;
	u = unk_4C80_ADDRESS;
	x = unk_49E8_ADDRESS;
	io_write16(VIDEO_1848, unk_49E8_ADDRESS);
	d = 0x803u;
	sub_0380AB(x, y, u, d);
	t3 = io_read8(VIDEO_184E);
	io_write8(VIDEO_184E, 0u);
	t4 = io_read8(VIDEO_184B);
	if (t4 != 0u)
	{
		t5 = io_read8(VIDEO_184C);
		a = t5;
		if (a != 4u)
			return;
		io_write8(VIDEO_184E, a);
		x = unk_4A40_ADDRESS;
		a = 4u;
		do
		{
			if (mem_read8(x) != 0u)
			{
				t6 = mem_read16(x + 0x3Fu);
				u = t6;
				if (t6 != 0u)
				{
					t7 = mem_read8(x + 0x3Fu);
					if (t7 != 0u)
						mem_write8(u, 0u);
				}
			}
			x += 0xC0u;
			t8 = a;
			a = t8 - 1u;
		} while (t8 != 1u);
	}
}

void sub_0380AB(uint16_t x, uint16_t y, uint16_t u, uint16_t d)
{
	bool L_038159 = false;
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint8_t stack_10004 = 0;
	uint16_t stack = 0, stack_6 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0, t12 = 0, t16 = 0, t17 = 0, t22 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t32 = 0, t33 = 0, t34 = 0;
	uint16_t t9 = 0, t11 = 0, t13 = 0, t14 = 0, t15 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t23 = 0, t24 = 0, t25 = 0, t31 = 0;

	b = (uint8_t)d;
	if (((d >> 8) & unk_4850) == 0u)
	{
		t1 = io_read8(VIDEO_184C);
		io_write8(VIDEO_184C, t1 + 1u);
		return;
	}
	t2 = mem_read8(x + 3u);
	if (t2 == 0u)
	{
		t3 = io_read8(VIDEO_184E);
		if (t3 != 0u)
		{
			t1 = io_read8(VIDEO_184C);
			io_write8(VIDEO_184C, t1 + 1u);
			return;
		}
		stack = x;
		stack_10004 = b;
		t4 = mem_read8(u + 0x34u);
		b = t4;
		mem_write8(u + 5u, 0x80u);
		stack_6 = u;
		x_2 = u + 0x1Cu;
		u_2 = 0x3Du;
		a = 0u;
		while (u_2 != 0u)
		{
			mem_write8(x_2, a);
			x_2++;
			u_2--;
		}
		u = stack_6;
		mem_write8(u + 0x34u, b);
		if ((b & 2u) == 0u)
		{
			mem_write8(u + 9u, 0u);
			mem_write8(u + 0x1Bu, 0x28u);
			mem_write8(stack + 2u, 0x28u);
		}
		x = stack;
		t5 = mem_read8(u + 0x5Bu);
		b = (((((uint32_t)stack_10004 << 1) << 1) << 1) << 1) | t5;
		mem_write8(u + 0x5Bu, b);
		mem_write8(u + 0xBBu, b);
		t6 = mem_read8(x + 2u);
		mem_write8(u + 0x1Bu, t6);
		mem_write8(x + 3u, 1u);
		t7 = mem_read8(u + 0x34u);
		if ((t7 & 2u) != 0u)
		{
			sub_039B0C(u);
			mem_write8(u, 0xC4u);
			t8 = mem_read8(u + 0x34u);
			mem_write8(u + 0x34u, t8 & ~2u);
			sub_039BAD(u);
		}
		else
		{
			a = unk_4867;
			if (a == 4u || a == 0xBu)
				L_038159 = true;
			else
			{
				mem_write16(u + 0x11u, 0xB8u);
				unk_48F1 = 4u;
				carry = sub_038200(u);
				for (;;)
				{
					if (carry)
					{
						t9 = mem_read16(u + 0x11u);
						mem_write16(u + 0x11u, t9 - 8u);
						t10 = unk_48F1;
						unk_48F1 = t10 - 1u;
						if (t10 != 1u)
						{
							carry = sub_038200(u);
							continue;
						}
						unk_48F1 = 9u;
						mem_write16(u + 0x11u, 0xB8u);
						carry = sub_038200(u);
						for (;;)
						{
							if (carry == 0u)
							{
								t11 = unk_48F3 + 0x20u;
								mem_write16(u + 0x16u, t11);
								mem_write16(u + 0x19u, 0x100u);
								t12 = mem_read8(u + 4u);
								t13 = (int8_t)((((((uint32_t)t12 << 1) << 1) << 1) << 1) << 1);
								t14 = t13 - 0x10u;
								mem_write16(u + 0xCu, t14);
								x = 0xE00u;
								mem_write16(u + 0xFu, 0xE00u);
								mem_write8(u + 0x30u, 0x26u);
								mem_write8(u + 5u, 0xBAu);
								d_2 = 0x1601u;
								carry = sub_078680(d_2);
								break;
							}
							t15 = mem_read16(u + 0x11u);
							mem_write16(u + 0x11u, t15 + 8u);
							t16 = unk_48F1;
							unk_48F1 = t16 - 1u;
							if (t16 != 1u)
							{
								carry = sub_038200(u);
								continue;
							}
							L_038159 = true;
							break;
						}
						if (!L_038159)
							break;
					}
					if (L_038159)
						break;
					t11 = unk_48F3 + 0x20u;
					mem_write16(u + 0x16u, t11);
					mem_write16(u + 0x19u, 0x100u);
					t12 = mem_read8(u + 4u);
					t13 = (int8_t)((((((uint32_t)t12 << 1) << 1) << 1) << 1) << 1);
					t14 = t13 - 0x10u;
					mem_write16(u + 0xCu, t14);
					x = 0xE00u;
					mem_write16(u + 0xFu, 0xE00u);
					mem_write8(u + 0x30u, 0x26u);
					mem_write8(u + 5u, 0xBAu);
					d_2 = 0x1601u;
					carry = sub_078680(d_2);
					break;
				}
			}
			if (L_038159)
			{
				t17 = mem_read8(u + 4u);
				t18 = (int8_t)((((((uint32_t)t17 << 1) << 1) << 1) << 1) << 1);
				t19 = t18 + 0xD0u;
				a = (uint8_t)(t19 >> 8);
				b = (uint8_t)t19;
				mem_write16(u + 0xCu, ((uint32_t)a << 8) | b);
				io_write16(VIDEO_1858, ((uint32_t)a << 8) | b);
				mem_write16(u + 0x11u, VIDEO_00C0);
				mem_write16(u + 0x16u, 0xD0u);
				unk_48F1 = 8u;
				x = u;
				sub_07863B(x, &d_2, &negative);
				a = (uint8_t)(d_2 >> 8);
				for (;;)
				{
					if ((uint8_t)(a + 1u) != 0u)
					{
						mem_write16(u + 0x19u, 0xFC00u);
						mem_write8(u + 9u, 0x40u);
						mem_write8(u + 0x30u, 0x27u);
						mem_write8(u + 5u, 0xBBu);
						break;
					}
					t20 = mem_read16(u + 0xCu);
					t21 = t20 - 0x10u;
					mem_write16(u + 0xCu, t21);
					t22 = unk_48F1;
					unk_48F1 = t22 - 1u;
					if (t22 != 1u)
					{
						x = u;
						sub_07863B(x, &d_2, &negative);
						a = (uint8_t)(d_2 >> 8);
						continue;
					}
					t23 = io_read16(VIDEO_1858);
					mem_write16(u + 0xCu, t23);
					do
					{
						t24 = mem_read16(u + 0xCu);
						t25 = t24 + 0x10u;
						mem_write16(u + 0xCu, t25);
						x = u;
						sub_07863B(x, &d_2, &negative);
						a = (uint8_t)(d_2 >> 8);
					} while ((uint8_t)(a + 1u) == 0u);
					mem_write16(u + 0x19u, 0xFC00u);
					mem_write8(u + 9u, 0x40u);
					mem_write8(u + 0x30u, 0x27u);
					mem_write8(u + 5u, 0xBBu);
					break;
				}
				d_2 = 0x1601u;
				carry = sub_078680(d_2);
			}
			mem_write8(u, 0xC4u);
			t8 = mem_read8(u + 0x34u);
			mem_write8(u + 0x34u, t8 & ~2u);
			sub_039BAD(u);
		}
		mem_write8(u + 0x21u, 0x18u);
		mem_write8(u + 0x24u, 0x18u);
		t26 = mem_read8(u + 0x38u);
		mem_write8(u + 0x38u, t26 + 1u);
		mem_write16(u + 0x1Cu, 0x13u);
	}
	else
	{
		t27 = io_read8(VIDEO_184B);
		if (t27 == 0u)
			mem_write16(u + 0x2Eu, y);
		else
		{
			t28 = mem_read8(u + 0x3Eu);
			if (t28 != 0u)
			{
				mem_write8(u + 0x3Eu, 0u);
				mem_write8(u, 0x80u);
			}
			mem_write8(u + 0x60u, 0u);
			t29 = mem_read8(u + 0x66u);
			mem_write8(u + 0x66u, t29 | 1u);
			mem_write16(u + 0x2Eu, 0u);
			t30 = mem_read8(u + 0x39u);
			if ((int8_t)t30 < 0)
			{
				t31 = mem_read16(u + 0x32u);
				x = t31;
				sub_039A1A(x, u);
				mem_write8(u + 0x38u, 0u);
				mem_write8(x + 0x38u, 0u);
			}
		}
	}
	t32 = mem_read8(u + 0x4Fu);
	if (t32 < 0xEu)
	{
		t33 = mem_read8(u + 0x4Fu);
		mem_write8(u + 0x4Fu, t33 + 1u);
	}
	t34 = mem_read8(u + 0x30u);
	y_2 = loaded_table_039D51_ADDRESS;
	switch ((int16_t)(uint8_t)((uint32_t)t34 << 1))
	{
	case 0:
		sub_03839C(y_2, u);
		return;
	case 2:
	case 92:
	case 114:
	case 126:
		sub_039861(u);
		return;
	case 4:
		sub_038636(u);
		return;
	case 6:
		sub_03868A(u);
		return;
	case 8:
		sub_038A69(y_2, u);
		return;
	case 10:
		sub_038A86(y_2, u);
		return;
	case 12:
		sub_038B03(u);
		return;
	case 14:
		sub_038B08(u);
		return;
	case 16:
		sub_038ADA(y_2, u);
		return;
	case 18:
		sub_038B26(u);
		return;
	case 20:
		sub_038B2B(u);
		return;
	case 22:
		sub_038B4B(u);
		return;
	case 24:
		sub_038B50(u);
		return;
	case 26:
		sub_0389EE(u);
		return;
	case 28:
	case 46:
	case 80:
		sub_038DE7(y_2, u);
		return;
	case 30:
		sub_038CF1(u);
		return;
	case 32:
	case 36:
	case 38:
	case 58:
	case 60:
	case 70:
	case 72:
		sub_038DB3(y_2, u);
		return;
	case 34:
		sub_038D59(u);
		return;
	case 40:
		sub_038D75(u);
		return;
	case 42:
		sub_038DBD(u);
		return;
	case 44:
		sub_038DD2(u);
		return;
	case 48:
	case 50:
		sub_038EFA(y_2, u);
		return;
	case 52:
	case 54:
		sub_038E1F(y_2, u);
		return;
	case 56:
		sub_038E45(y_2, u);
		return;
	case 62:
		sub_03902E(u);
		return;
	case 64:
		sub_039065(u);
		return;
	case 66:
		sub_039070(u);
		return;
	case 68:
		sub_039084(u);
		return;
	case 74:
		sub_039128(u);
		return;
	case 76:
		sub_03909B(u);
		return;
	case 78:
		sub_0390CF(u);
		return;
	case 82:
		sub_0388A2(u);
		return;
	case 84:
		sub_03912B(y_2, u);
		return;
	case 86:
		sub_038604(y_2, u);
		return;
	case 88:
		sub_039134(y_2, u);
		return;
	case 90:
		sub_038A55(y_2, u);
		return;
	case 94:
		sub_038C22(y_2, u);
		return;
	case 96:
		sub_03916D(y_2, u);
		return;
	case 98:
		sub_0391C1(u);
		return;
	case 100:
		sub_0382B9(u);
		return;
	case 102:
		sub_038510(u);
		return;
	case 104:
		sub_038560(u);
		return;
	case 106:
	case 108:
		sub_038BF9(y_2, u);
		return;
	case 110:
		sub_0389B2(y_2, u);
		return;
	case 112:
		sub_038B1A(x, y_2, u);
		return;
	case 116:
		sub_038ED5(y_2, u);
		return;
	case 118:
		sub_038EEA(u);
		return;
	case 120:
		sub_038D2A(u);
		return;
	case 122:
		sub_038D3C(u);
		return;
	case 124:
		sub_038D4B(u);
		return;
	}
}

uint32_t sub_038200(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	mem_write16(u + 0xCu, 0x40u);
	unk_48F3 = 0u;
	unk_48F2 = 8u;
	do
	{
		sub_03986D(u, &d, &carry);
		if (carry)
			return carry;
		if ((int8_t)unk_48F3 < (int8_t)d)
			unk_48F3 = (uint8_t)d;
		t1 = mem_read16(u + 0xCu);
		mem_write16(u + 0xCu, t1 + 8u);
		t2 = unk_48F2;
		unk_48F2 = t2 - 1u;
	} while (t2 != 1u);
	carry = 0u;
	return carry;
}

void unreached_03829A(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	t2 = mem_read8(u + 0x30u);
	mem_write8(u + 0x30u, t2 + 1u);
	mem_write8(u, mem_read8(u) & ~4u);
	sub_0392F0(y, u);
}

void unreached_0382AF(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	sub_0386B8(u);
}

void sub_0382B9(uint16_t u)
{
	bool L_038311 = false, L_038314 = false, L_038365 = false, L_03836A = false, L_0384D1 = false, L_0386E1 = false, L_0391EB = false, L_039205 = false, L_039216 = false;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0, t12 = 0, t13 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t9 = 0, t11 = 0, t14 = 0, t15 = 0;

	t1 = mem_read16(u + 0x32u);
	x = t1;
	t2 = mem_read16(u + 0x16u);
	b = (uint8_t)t2;
	t3 = mem_read16(u + 0x5Cu);
	if ((int16_t)(((uint32_t)(t2 >> 8) << 8) | b) <= (int16_t)t3)
	{
		t4 = mem_read8(u + VIDEO_002F);
		t5 = mem_read8(x + VIDEO_002F);
		a = t4 | t5;
		do
		{
			do
			{
				do
				{
					if (L_039205 || L_0391EB || L_0386E1 || (a & 0x20u) != 0u)
					{
						do
						{
							if (L_0391EB || !L_039205)
							{
								if (L_0391EB || L_0391EB || !L_0386E1)
								{
									if (!L_0391EB)
									{
										if (!L_0391EB)
										{
											mem_write16(u + 0x19u, 0x780u);
											sub_039B9B(u);
											mem_write8(u + 0x38u, 1u);
											mem_write16(u + 0x30u, 0x3300u);
											mem_write8(u + 0x3Bu, 0x33u);
											b = 0xF0u;
										}
									}
									L_0391EB = false;
									unk_48F2 = b;
									y = indexed_table_039E3D_ADDRESS;
									t6 = mem_read8(u + 0x35u);
									t7 = mem_read8(u + 4u);
									t8 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t6 << 1) << 1) + t7));
									a = t8;
								}
							}
							for (;;)
							{
								if (L_039205 || L_039205 || L_0386E1 || (int8_t)t8 < 0)
								{
									if (L_039205 || L_039205 || !L_0386E1)
									{
										L_039205 = false;
										t9 = mem_read16(u + 0x32u);
										x = t9;
										sub_039A6E(x, u);
										t10 = mem_read8(x + 4u);
										a = t10;
									}
									for (;;)
									{
										if (L_039216 || L_0386E1 || (int8_t)unk_4858 >= 0)
										{
											if (L_039216 || !L_0386E1)
											{
												L_039216 = false;
												mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
												t11 = mem_read16(u + 0x28u);
												mem_write16(u + 0x28u, t11 - 1u);
												if (t11 != 1u)
												{
													sub_0392F0(y, u);
													return;
												}
												t12 = mem_read8(u + 0x35u);
											}
											if (L_0386E1 || t12 == 2u)
											{
												L_0386E1 = false;
												t13 = mem_read8(u + 0x35u);
												a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t13);
												mem_write8(u + VIDEO_003C, a);
												mem_write16(u + 0x1Cu, 0xC13u);
												t14 = mem_read16(u + 0x16u);
												x = t14;
												t15 = mem_read16(u + 0x5Cu);
												if ((int16_t)t15 < (int16_t)x)
												{
													sub_03893B(x, u);
													b = 0xFCu;
												}
												else
												{
													mem_write16(u + 0xFu, 0u);
													mem_write16(u + 0x14u, 0u);
													b = 0xF8u;
												}
												mem_write8(u + 0x30u, a);
												L_0391EB = true;
											}
											if (!L_0391EB)
											{
												sub_039A1A(x, u);
												mem_write8(x, 0xC0u);
												mem_write16(u + 0xFu, 0u);
												mem_write16(x + 0xFu, 0u);
												mem_write16(u + 0x14u, 0u);
												mem_write16(x + 0x14u, 0u);
												sub_0392F0(y, u);
												return;
											}
										}
										if (L_0391EB)
											break;
										t16 = mem_read8(u + 4u);
										a = t16;
										L_039216 = true;
									}
								}
								if (L_0391EB)
									break;
								mem_write8(u + 5u, a + unk_48F2);
								L_039205 = true;
							}
						} while (L_0391EB);
					}
					mem_write16(u + 0x1Cu, 0u);
					y = indexed_table_039F21_ADDRESS;
					do
					{
						if (L_0384D1 || (a & 0x10u) == 0u)
						{
							if (!L_0384D1)
								t17 = mem_read8(u + 0x35u);
							if (L_0384D1 || (int8_t)t17 >= 2)
							{
								if (!L_0384D1)
								{
									t18 = mem_read8(x + 0x2Eu);
									t19 = t18 & 0xFu;
									a = t19;
									if (t19 != 0u)
									{
										d = (uint32_t)a << 8;
										sub_0383D4(y, u, d);
										return;
									}
									t20 = mem_read8(u + 0x2Eu);
									t21 = t20 & 0xFu;
									a = t21;
									if (t21 != 0u)
									{
										d = (uint32_t)a << 8;
										sub_0383D4(y, u, d);
										return;
									}
								}
								L_0384D1 = false;
								mem_write8(u + 0x38u, 1u);
								mem_write16(u + 0xFu, 0u);
								mem_write16(u + 0x14u, 0u);
								t22 = mem_read8(u + 0x35u);
								if (t22 == 0u)
								{
									t23 = mem_read8(u + 6u);
									mem_write8(u + 6u, t23 | 0x40u);
									L_039205 = true;
								}
								if (!L_039205)
								{
									b = 0xE8u;
									L_0391EB = true;
								}
							}
						}
						else
						{
							t24 = mem_read8(u + 0x35u);
							a = t24;
							L_0386E1 = (int8_t)a >= 2;
							if (!L_0386E1)
							{
								L_038314 = a != 1u;
								if (!L_038314)
								{
									t25 = mem_read8(u + 0x55u);
									mem_write8(u + 0x55u, t25 - 1u);
									L_038314 = t25 != 1u;
									if (!L_038314)
									{
										mem_write8(u + 0x55u, 3u);
										t26 = mem_read8(u + VIDEO_002F);
										if ((t26 & 0x10u) != 0u)
										{
											a = 0x3Fu;
											b = 0x2Au;
											L_038311 = true;
										}
										else
										{
											t27 = mem_read8(x + VIDEO_002F);
											L_038314 = (t27 & 0x10u) == 0u;
											if (!L_038314)
											{
												a = 0x3Fu;
												b = 0x2Bu;
												L_038311 = true;
											}
										}
										if (!L_038314)
										{
											if (L_038311)
											{
												L_038311 = false;
												d = ((uint32_t)a << 8) | b;
												carry = sub_078680(d);
											}
										}
									}
								}
								b = 0x13u;
								mem_write16(u + 0x1Cu, 0x413u);
								y = loaded_table_039F5D_ADDRESS;
							}
						}
						if (L_039205)
							break;
						if (L_0391EB)
							break;
						if (L_0386E1)
							break;
						if ((unk_4815 & 0xFu) == 0u)
						{
							b = 0x11u;
							mem_write16(u + 0x1Cu, 0x411u);
						}
						t28 = mem_read8(u + 0x2Au);
						if (t28 != 0u)
						{
							stack = y;
							y = loaded_table_039E3B_ADDRESS;
							d = b;
							sub_039BF9(y, u);
							y = stack;
						}
						t29 = mem_read8(u + 0x36u);
						for (;;)
						{
							if (L_03836A || (int8_t)t29 >= 0)
							{
								if (!L_03836A)
								{
									t30 = mem_read8(u + VIDEO_002F);
									t31 = mem_read8(x + VIDEO_002F);
									unk_48F0 = (t30 | t31) & 0x10u;
									t32 = mem_read8(u + 0x2Eu);
									a = t32;
									t33 = mem_read8(u + 0x36u);
								}
								for (;;)
								{
									if (L_038365 || L_03836A || t33 != 0u)
									{
										if (L_038365 || !L_03836A)
										{
											L_038365 = false;
											a = (a & 0xEFu) | unk_48F0;
										}
										L_03836A = false;
										t34 = a & 0x1Fu;
										a = t34;
										if (t34 != 0u)
										{
											d = (d & 0xFFu) | ((a & 0xFu) << 8);
											sub_0383D4(y, u, d);
											return;
										}
										L_0384D1 = true;
									}
									if (L_0384D1)
										break;
									t35 = mem_read8(x + 0x2Eu);
									a = t35;
									L_038365 = true;
								}
							}
							if (L_0384D1)
								break;
							t36 = mem_read8(u + 0x2Eu);
							t37 = mem_read8(x + 0x2Eu);
							a = t36 | t37;
							L_03836A = true;
						}
					} while (L_0384D1);
				} while (L_039205);
			} while (L_0391EB);
		} while (L_0386E1);
	}
	sub_039B9B(u);
	mem_write16(u + 0x19u, 0x600u);
	sub_038556(u);
}

void sub_03839C(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, x = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0, t14 = 0, t15 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t31 = 0, t32 = 0, t33 = 0, t34 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, t11 = 0, t13 = 0, t16 = 0, t30 = 0;

	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)t1)
	{
		mem_write8(u + 0x30u, 3u);
		sub_039B9B(u);
		mem_write16(u + 0x19u, 0x600u);
		mem_write8(u + 0x38u, 1u);
		sub_03868A(u);
		return;
	}
	t3 = mem_read8(u + VIDEO_002F);
	b = t3;
	if ((b & 0x20u) != 0u)
	{
		t4 = mem_read8(u + VIDEO_002F);
		if (t4 != 0x30u)
		{
			sub_039B9B(u);
			mem_write16(u + 0x38u, 0x100u);
			sub_039BAD(u);
			mem_write16(u + 0x30u, 0x200u);
			mem_write8(u + 0x3Bu, 2u);
			mem_write16(u + 0x19u, 0x780u);
			sub_038636(u);
			return;
		}
		t5 = mem_read16(u + 0x3Fu);
		if (t5 == 0u)
		{
			mem_write16(u + 0x19u, 0x600u);
			d = 0x3F20u;
			sub_039C50(u, d);
			sub_039B9B(u);
			t6 = mem_read8(u + 0x2Eu);
			t7 = t6 & 3u;
			b = t7;
			if (t7 == 0u)
			{
				d = 0xDB9u;
				sub_03899A(y, u, d);
				return;
			}
			x = VIDEO_00C0;
			if ((b & 1u) != 0u)
				x = 0xFF40u;
			mem_write16(u + 0xFu, x);
			d = 0xDB9u;
			sub_03899A(y, u, d);
			return;
		}
		t8 = mem_read8(u + 0x3Fu);
		if (t8 != 0u)
		{
			sub_039B9B(u);
			mem_write16(u + 0x38u, 0x100u);
			sub_039BAD(u);
			mem_write16(u + 0x30u, 0x200u);
			mem_write8(u + 0x3Bu, 2u);
			mem_write16(u + 0x19u, 0x780u);
			sub_038636(u);
			return;
		}
		t9 = mem_read8(u + 0x40u);
		stack = 0x80u;
		stack_2 = t9;
		y_2 = ((uint32_t)stack_2 << 8) | stack;
		d = 0xA00u;
		carry = sub_039C2F(y_2, u, d);
		if (carry == 0u)
		{
			mem_write16(u + 0x3Fu, 0u);
			d = 0x2BB1u;
			sub_038988(y_2, u, d);
			return;
		}
		sub_039B9B(u);
		mem_write16(u + 0x38u, 0x100u);
		sub_039BAD(u);
		mem_write16(u + 0x30u, 0x200u);
		mem_write8(u + 0x3Bu, 2u);
		mem_write16(u + 0x19u, 0x780u);
		sub_038636(u);
		return;
	}
	if ((b & 0x10u) != 0u)
	{
		mem_write16(u + 0xFu, 0u);
		t10 = mem_read8(u + 9u);
		mem_write8(u + 0x2Du, t10 & 0x40u);
		t11 = mem_read16(u + 0x3Fu);
		x = t11;
		if (t11 != 0u)
		{
			sub_0387D2(x, u);
			return;
		}
		t12 = mem_read8(u + 0x1Eu);
		a = t12;
		if (a == 0xFEu)
		{
			mem_write16(u + 0x1Cu, 0u);
			t13 = mem_read16(u + 0x25u);
			mem_write16(u + 0x3Fu, t13);
			d_2 = 0xC9u;
			sub_039B5C(u, d_2);
			mem_write8(u + 0x30u, 0x2Cu);
			sub_039861(u);
			return;
		}
		t14 = mem_read8(u + 0x2Eu);
		t15 = t14 & 3u;
		b = t15;
		if (t15 != 0u)
		{
			mem_write8(u + 9u, 0u);
			if ((b & 1u) != 0u)
				mem_write8(u + 9u, 0x40u);
		}
		if (a != 0xFFu)
		{
			sub_03886D(y, u);
			return;
		}
		mem_write16(u + 0x1Cu, 0u);
		t16 = mem_read16(u + 0x25u);
		x = t16;
		t17 = mem_read8(x + 0x1Du);
		if (t17 != 0xFFu)
		{
			sub_03886D(y, u);
			return;
		}
		t18 = mem_read8(x + 0x58u);
		if (t18 != 0u)
		{
			sub_03886D(y, u);
			return;
		}
		t19 = mem_read8(x + 4u);
		b = t19;
		if ((int8_t)b > 5 && (int8_t)b < 9)
		{
			mem_write16(u + 0x3Fu, b);
			d = 0x1800u;
			carry = sub_078680(d);
			mem_write8(u + 0x9Fu, 0x14u);
			mem_write16(u + 0x14u, 0u);
			mem_write8(x + 0x3Du, 1u);
			mem_write16(x + 0x40u, u);
			t20 = mem_read8(u + 4u);
			mem_write8(x + 0x58u, t20 + 1u);
			mem_write8(x + 2u, 3u);
			y_2 = loaded_table_039DD9_ADDRESS;
			y_2 = sub_0399CA(x, y_2, u);
			d = 0x2FBDu;
			sub_03899D(y_2, u, d);
			return;
		}
		mem_write16(u + 0x3Fu, x);
		t21 = mem_read8(u + 0x5Bu);
		stack = t21 & 0x30u;
		t22 = mem_read8(x + 0x5Bu);
		mem_write8(x + 0x5Bu, (t22 & 0xCFu) | stack);
		d = 0x1800u;
		carry = sub_078680(d);
		mem_write8(u + 0x9Fu, 0x14u);
		mem_write16(u + 0x14u, 0u);
		mem_write8(x + 0x3Du, 1u);
		mem_write16(x + 0x40u, u);
		t20 = mem_read8(u + 4u);
		mem_write8(x + 0x58u, t20 + 1u);
		mem_write8(x + 2u, 3u);
		y_2 = loaded_table_039DD9_ADDRESS;
		y_2 = sub_0399CA(x, y_2, u);
		d = 0x2FBDu;
		sub_03899D(y_2, u, d);
		return;
	}
	if ((b & 0xFu) != 0u)
	{
		t23 = mem_read8(u + 0x4Fu);
		if ((int8_t)t23 <= 0xC)
		{
			t24 = mem_read8(u + 0x50u);
			if (t24 < 4u)
			{
				t25 = mem_read8(u + 0x50u);
				mem_write8(u + 0x50u, t25 + 1u);
			}
		}
		mem_write8(u + 0x4Fu, 0u);
	}
	t26 = mem_read8(u + 0x2Eu);
	t27 = t26 & 0xFu;
	a = t27;
	if (t27 != 0u)
	{
		y_2 = indexed_table_039F21_ADDRESS;
		d = (uint32_t)a << 8;
		sub_0383D4(y_2, u, d);
		return;
	}
	t28 = io_read8(VIDEO_184C);
	io_write8(VIDEO_184C, t28 + 1u);
	t29 = mem_read8(u + 0x38u);
	b = t29;
	if (t29 != 0u)
	{
		b++;
		if (b == 0xA0u)
		{
			d = 0x3F10u;
			sub_039C50(u, d);
			d = 0x210u;
			sub_039C29(y, u, d);
			mem_write8(u + 5u, 0xAFu);
			mem_write8(u + 0x38u, 1u);
			sub_0392F0(y, u);
			return;
		}
		t30 = mem_read16(u + 0x3Fu);
		y_2 = t30;
		if (t30 != 0u)
		{
			sub_0392F0(y_2, u);
			return;
		}
		t31 = mem_read8(u + 0x39u);
		if (t31 != 0x20u)
		{
			t32 = mem_read8(u + 0x39u);
			mem_write8(u + 0x39u, t32 + 1u);
		}
		else
		{
			t33 = mem_read8(u + 4u);
			mem_write8(u + 0x1Du, t33 - 0x80u);
			mem_write8(u + 0x1Cu, 0u);
			mem_write16(u + 0x1Fu, 0x1008u);
		}
		mem_write8(u + 0x38u, b);
		sub_0392F0(y_2, u);
		return;
	}
	t34 = mem_read8(u + 0x38u);
	mem_write8(u + 0x38u, t34 + 1u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	y_2 = loaded_table_039E45_ADDRESS;
	d_2 = 0x80u;
	sub_039242(y_2, u, d_2);
}

void sub_0383D4(uint16_t y, uint16_t u, uint16_t d)
{
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t x = 0, y_2 = 0;
	uint8_t t4 = 0, t5 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t17 = 0, t18 = 0, t20 = 0, t21 = 0, t24 = 0, t25 = 0, t26 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t11 = 0, t16 = 0, t19 = 0, t22 = 0, t23 = 0;

	t1 = y + (uint8_t)(((uint32_t)(d >> 8) << 1) << 1);
	y_2 = t1 + 2u;
	t2 = mem_read16(t1);
	a = (uint8_t)(t2 >> 8);
	t3 = ((uint32_t)a << 8) | (uint8_t)t2;
	mem_write16(u + 0xFu, t3);
	if (t3 != 0u)
	{
		unk_48F3 = a & 0x40u;
		t4 = mem_read8(u + 9u);
		mem_write8(u + 9u, (t4 & 0xBFu) | unk_48F3);
		t5 = mem_read8(u + 0x39u);
		if ((int8_t)t5 < 0)
		{
			t6 = mem_read16(u + 0x32u);
			x = t6;
			t7 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t7 & 0xBFu) | unk_48F3);
		}
	}
	sub_0398A9(y_2, u);
	t8 = mem_read8(u + 0x38u);
	if (t8 != 0u)
	{
		t9 = mem_read8(u + 0x39u);
		if ((int8_t)t9 >= 0)
		{
			mem_write16(u + 0x38u, 0u);
			mem_write8(u + 0x34u, 0u);
			sub_039BAD(u);
			b = 0x81u;
			y_2 = loaded_table_039E55_ADDRESS;
			t10 = mem_read8(u + 0x2Eu);
			if ((t10 & 4u) == 0u)
			{
				d_2 = b;
				sub_039242(y_2, u, d_2);
				return;
			}
			d_2 = (uint8_t)(b + 1u);
			sub_039242(y_2, u, d_2);
			return;
		}
		t11 = mem_read16(u + 0x32u);
		x = t11;
		t12 = mem_read8(u + 0x36u);
		if ((int8_t)t12 >= 0)
		{
			mem_write8(u + 0x38u, 0u);
			sub_0391D0(u);
			return;
		}
		b = 1u;
		t13 = mem_read8(u + 0x2Eu);
		if ((t13 & 0x1Fu) == 0u)
		{
			mem_write8(u + 0x36u, 0u);
			mem_write8(x + 0x36u, b);
		}
		else
		{
			mem_write8(u + 0x36u, b);
			mem_write8(x + 0x36u, 0u);
		}
		mem_write8(u + 0x38u, 0u);
		sub_0391D0(u);
		return;
	}
	t14 = mem_read8(u + 0x39u);
	if ((int8_t)t14 >= 0)
	{
		mem_write8(u + 0x39u, 0u);
		sub_039BAD(u);
		b = 1u;
		y_2 = loaded_table_039E55_ADDRESS;
		t15 = mem_read8(u + 0x2Eu);
		if ((t15 & 4u) == 0u)
		{
			d_2 = b;
			sub_039242(y_2, u, d_2);
			return;
		}
		d_2 = (uint8_t)(b + 1u);
		sub_039242(y_2, u, d_2);
		return;
	}
	for (;;)
	{
		t16 = mem_read16(u + 0x32u);
		x = t16;
		sub_039A6E(x, u);
		t17 = mem_read8(x + 4u);
		a = t17;
		if ((int8_t)unk_4858 < 0)
		{
			t18 = mem_read8(u + 4u);
			a = t18;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t19 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t19 - 1u);
		if (t19 != 1u)
		{
			sub_0392F0(y_2, u);
			return;
		}
		t20 = mem_read8(u + 0x35u);
		if (t20 != 2u)
			break;
		t21 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t21);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t22 = mem_read16(u + 0x16u);
		x = t22;
		t23 = mem_read16(u + 0x5Cu);
		if ((int16_t)t23 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
		unk_48F2 = b;
		y_2 = indexed_table_039E3D_ADDRESS;
		t24 = mem_read8(u + 0x35u);
		t25 = mem_read8(u + 4u);
		t26 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t24 << 1) << 1) + t25));
		a = t26;
		if ((int8_t)t26 < 0)
			continue;
		mem_write8(u + 5u, a + unk_48F2);
	}
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y_2, u);
}

void sub_038510(uint16_t u)
{
	bool L_038533 = false;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0, t19 = 0, t20 = 0, t23 = 0, t24 = 0, t25 = 0;
	uint16_t t1 = 0, t9 = 0, t10 = 0, t11 = 0, t15 = 0, t18 = 0, t21 = 0, t22 = 0;

	t1 = mem_read16(u + 0x32u);
	x = t1;
	t2 = mem_read8(u + 0x2Eu);
	t3 = mem_read8(x + 0x2Eu);
	d = (uint32_t)(t2 | t3) << 8;
	y = sub_03988B(u, d);
	t4 = mem_read8(u + VIDEO_003C);
	L_038533 = t4 != 0u;
	if (!L_038533)
	{
		t5 = mem_read8(u + 0x35u);
		L_038533 = (int8_t)t5 < 2;
		if (!L_038533)
		{
			t6 = mem_read8(u + VIDEO_002F);
			t7 = mem_read8(x + VIDEO_002F);
			L_038533 = ((t6 | t7) & 0x10u) == 0u;
		}
	}
	if (L_038533)
	{
		t8 = mem_read8(u + VIDEO_0031);
		mem_write8(u + VIDEO_0031, t8 + 1u);
		t9 = mem_read16(u + 0x19u);
		t10 = t9 - 0x40u;
		t11 = t10;
		mem_write16(u + 0x19u, t11);
		if ((int16_t)t11 < 0)
		{
			sub_038556(u);
			return;
		}
		t12 = mem_read8(u + 0x2Eu);
		t13 = mem_read8(x + 0x2Eu);
		if (((t12 | t13) & 0x20u) == 0u)
		{
			t14 = mem_read8(u + VIDEO_0031);
			if ((int8_t)t14 > 3)
			{
				sub_038556(u);
				return;
			}
		}
		t15 = mem_read16(u + 0x32u);
		x = t15;
		sub_039A6E(x, u);
		t16 = mem_read8(x + 4u);
		a = t16;
		if ((int8_t)unk_4858 < 0)
		{
			t17 = mem_read8(u + 4u);
			a = t17;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t18 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t18 - 1u);
		if (t18 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t19 = mem_read8(u + 0x35u);
		if (t19 != 2u)
		{
			sub_039A1A(x, u);
			mem_write8(x, 0xC0u);
			mem_write16(u + 0xFu, 0u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			mem_write16(x + 0x14u, 0u);
			sub_0392F0(y, u);
			return;
		}
	}
	do
	{
		t20 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t20);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t21 = mem_read16(u + 0x16u);
		x = t21;
		t22 = mem_read16(u + 0x5Cu);
		if ((int16_t)t22 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t23 = mem_read8(u + 0x35u);
		t24 = mem_read8(u + 4u);
		t25 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t23 << 1) << 1) + t24));
		a = t25;
		if ((int8_t)t25 >= 0)
			mem_write8(u + 5u, a + unk_48F2);
		t15 = mem_read16(u + 0x32u);
		x = t15;
		sub_039A6E(x, u);
		t16 = mem_read8(x + 4u);
		a = t16;
		if ((int8_t)unk_4858 < 0)
		{
			t17 = mem_read8(u + 4u);
			a = t17;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t18 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t18 - 1u);
		if (t18 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t19 = mem_read8(u + 0x35u);
	} while (t19 == 2u);
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y, u);
}

void sub_038556(uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0, t8 = 0, t9 = 0;
	uint16_t t4 = 0, t7 = 0, t10 = 0, t11 = 0;

	mem_write8(u + 0x30u, 0x34u);
	b = 0xF4u;
	for (;;)
	{
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t1 = mem_read8(u + 0x35u);
		t2 = mem_read8(u + 4u);
		t3 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t1 << 1) << 1) + t2));
		a = t3;
		if ((int8_t)t3 >= 0)
			mem_write8(u + 5u, a + unk_48F2);
		t4 = mem_read16(u + 0x32u);
		x = t4;
		sub_039A6E(x, u);
		t5 = mem_read8(x + 4u);
		a = t5;
		if ((int8_t)unk_4858 < 0)
		{
			t6 = mem_read8(u + 4u);
			a = t6;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t7 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t7 - 1u);
		if (t7 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t8 = mem_read8(u + 0x35u);
		if (t8 != 2u)
			break;
		t9 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t9);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t10 = mem_read16(u + 0x16u);
		x = t10;
		t11 = mem_read16(u + 0x5Cu);
		if ((int16_t)t11 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
	}
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y, u);
}

void sub_038560(uint16_t u)
{
	bool L_038583 = false;
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0, t17 = 0, t18 = 0, t20 = 0, t21 = 0, t24 = 0, t25 = 0, t26 = 0;
	uint16_t t1 = 0, t8 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t19 = 0, t22 = 0, t23 = 0;

	t1 = mem_read16(u + 0x32u);
	x = t1;
	t2 = mem_read8(u + 0x2Eu);
	t3 = mem_read8(x + 0x2Eu);
	d = (uint32_t)(t2 | t3) << 8;
	y = sub_03988B(u, d);
	t4 = mem_read8(u + VIDEO_003C);
	L_038583 = t4 != 0u;
	if (!L_038583)
	{
		t5 = mem_read8(u + 0x35u);
		L_038583 = (int8_t)t5 < 2;
		if (!L_038583)
		{
			t6 = mem_read8(u + VIDEO_002F);
			t7 = mem_read8(x + VIDEO_002F);
			L_038583 = ((t6 | t7) & 0x10u) == 0u;
		}
	}
	if (L_038583)
	{
		sub_039B38(u, &zero, &negative, &overflow);
		if ((negative ^ overflow) | zero)
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			t8 = mem_read16(u + 0x5Cu);
			y = t8;
			mem_write16(u + 0x16u, y);
			mem_write16(x + 0x16u, y);
			mem_write8(u + 0x18u, 0u);
			mem_write8(x + 0x18u, 0u);
			t9 = mem_read8(u + 4u);
			if (t9 == 0u)
			{
				t10 = mem_read16(u + 0x19u);
				t11 = (int16_t)t10 >> 1;
				a = (uint8_t)(t11 >> 8);
				b = (uint8_t)t11;
				if ((int8_t)a >= -4)
				{
					mem_write16(u + 0x19u, 0u);
					sub_0391CD(u);
					return;
				}
				t12 = 0u - (((uint32_t)a << 8) | b);
				a = (uint8_t)(t12 >> 8);
				mem_write16(u + 0x19u, ((uint32_t)a << 8) | (uint8_t)t12);
				mem_write16(u + 0x16u, y + (int8_t)(0u - a));
				sub_038556(u);
				return;
			}
			sub_039BA4(u);
			mem_write16(u + 0x19u, 0u);
			sub_0391CD(u);
			return;
		}
		t13 = mem_read16(u + 0x19u);
		t14 = t13 - 0x40u;
		a = (uint8_t)(t14 >> 8);
		b = (uint8_t)t14;
		if ((int16_t)(((uint32_t)a << 8) | b) > -0x300)
		{
			t15 = (((uint32_t)a << 8) | b) - 0x80u;
			a = (uint8_t)(t15 >> 8);
			b = (uint8_t)t15;
		}
		mem_write16(u + 0x19u, ((uint32_t)a << 8) | b);
		t16 = mem_read16(u + 0x32u);
		x = t16;
		sub_039A6E(x, u);
		t17 = mem_read8(x + 4u);
		a = t17;
		if ((int8_t)unk_4858 < 0)
		{
			t18 = mem_read8(u + 4u);
			a = t18;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t19 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t19 - 1u);
		if (t19 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t20 = mem_read8(u + 0x35u);
		if (t20 != 2u)
		{
			sub_039A1A(x, u);
			mem_write8(x, 0xC0u);
			mem_write16(u + 0xFu, 0u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			mem_write16(x + 0x14u, 0u);
			sub_0392F0(y, u);
			return;
		}
	}
	do
	{
		t21 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t21);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t22 = mem_read16(u + 0x16u);
		x = t22;
		t23 = mem_read16(u + 0x5Cu);
		if ((int16_t)t23 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t24 = mem_read8(u + 0x35u);
		t25 = mem_read8(u + 4u);
		t26 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t24 << 1) << 1) + t25));
		a = t26;
		if ((int8_t)t26 >= 0)
			mem_write8(u + 5u, a + unk_48F2);
		t16 = mem_read16(u + 0x32u);
		x = t16;
		sub_039A6E(x, u);
		t17 = mem_read8(x + 4u);
		a = t17;
		if ((int8_t)unk_4858 < 0)
		{
			t18 = mem_read8(u + 4u);
			a = t18;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t19 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t19 - 1u);
		if (t19 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t20 = mem_read8(u + 0x35u);
	} while (t20 == 2u);
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y, u);
}

void sub_038604(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 6u);
	a = t1;
	if ((a & 2u) == 0u)
	{
		carry = (a >> 0) & 1u;
		if (carry == 0u)
		{
			sub_0392F0(y, u);
			return;
		}
		sub_038C36(y, u);
		return;
	}
	d = 0x1900u;
	carry = sub_078680(d);
	sub_0392F0(y, u);
}

void sub_038636(uint16_t u)
{
	uint8_t b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t6 = 0, t7 = 0, t11 = 0, t13 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0;

	t1 = mem_read8(u + 0x2Eu);
	d = (uint32_t)t1 << 8;
	y = sub_03988B(u, d);
	t2 = mem_read8(u + VIDEO_003C);
	if (t2 == 0u)
	{
		t3 = mem_read16(u + 0x16u);
		t4 = mem_read16(u + 0x5Cu);
		t5 = t3 - t4;
		if ((int16_t)t5 > 0x18)
		{
			t6 = mem_read8(u + VIDEO_002F);
			if ((t6 & 0x10u) != 0u)
			{
				sub_0387C4(y, u);
				return;
			}
		}
	}
	t7 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t7 + 1u);
	t8 = mem_read16(u + 0x19u);
	t9 = t8 - 0x40u;
	t10 = t9;
	mem_write16(u + 0x19u, t10);
	if ((int16_t)t10 < 0)
	{
		sub_038670(y, u);
		return;
	}
	t11 = mem_read8(u + 0x2Eu);
	if ((t11 & 0x20u) != 0u)
	{
		b = 0x83u;
		y = loaded_table_039E45_ADDRESS;
		t12 = mem_read16(u + 0x19u);
		if ((int16_t)t12 > 0x480)
		{
			d_2 = b;
			sub_039242(y, u, d_2);
			return;
		}
		d_2 = (uint8_t)(b + 1u);
		sub_039242(y, u, d_2);
		return;
	}
	t13 = mem_read8(u + VIDEO_0031);
	if ((int8_t)t13 > 3)
	{
		sub_038670(y, u);
		return;
	}
	b = 0x83u;
	y = loaded_table_039E45_ADDRESS;
	t12 = mem_read16(u + 0x19u);
	if ((int16_t)t12 > 0x480)
	{
		d_2 = b;
		sub_039242(y, u, d_2);
		return;
	}
	d_2 = (uint8_t)(b + 1u);
	sub_039242(y, u, d_2);
}

void sub_038670(uint16_t y, uint16_t u)
{
	mem_write8(u + 0x30u, 3u);
	sub_0392F0(y, u);
}

void sub_03868A(uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(u + 0x2Eu);
	d = (uint32_t)t1 << 8;
	y = sub_03988B(u, d);
	t2 = mem_read8(u + VIDEO_003C);
	if (t2 == 0u)
	{
		t3 = mem_read8(u + VIDEO_002F);
		if ((t3 & 0x10u) != 0u)
		{
			sub_0387C4(y, u);
			return;
		}
	}
	sub_039B38(u, &zero, &negative, &overflow);
	if ((negative ^ overflow) | zero)
	{
		sub_0386B8(u);
		return;
	}
	t4 = mem_read16(u + 0x19u);
	t5 = t4 - 0x40u;
	a = (uint8_t)(t5 >> 8);
	b = (uint8_t)t5;
	if ((int16_t)t5 >= 0)
	{
		t6 = (((uint32_t)a << 8) | b) - 0x80u;
		a = (uint8_t)(t6 >> 8);
		b = (uint8_t)t6;
	}
	mem_write16(u + 0x19u, ((uint32_t)a << 8) | b);
	y = loaded_table_039E45_ADDRESS;
	d_2 = 0x85u;
	sub_039242(y, u, d_2);
}

void sub_0386B8(uint16_t u)
{
	uint16_t t1 = 0;

	sub_039BA4(u);
	t1 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t1);
	mem_write8(u + 0x18u, 0u);
	mem_write16(u + 0x19u, 0u);
	mem_write16(u + 0xFu, 0u);
	sub_0386CA(u);
}

void sub_0386CA(uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;

	mem_write16(u + 0x14u, 0u);
	mem_write16(u + 0x3Bu, 0u);
	mem_write16(u + 0x38u, 0x100u);
	mem_write8(u + 0x30u, 0u);
	y = loaded_table_039E55_ADDRESS;
	d = 0x80u;
	sub_039242(y, u, d);
}

void sub_0387C4(uint16_t y, uint16_t u)
{
	uint16_t x = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + 9u);
	mem_write8(u + 0x2Du, t1 & 0x40u);
	t2 = mem_read16(u + 0x3Fu);
	x = t2;
	if (t2 == 0u)
	{
		sub_03886D(y, u);
		return;
	}
	sub_0387D2(x, u);
}

void sub_0387D2(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0, d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write16(u + 0x53u, 0x40u);
	t1 = mem_read8(u + 0x40u);
	a = t1;
	t2 = mem_read8(u + 0x3Fu);
	if (t2 != 0u)
	{
		t3 = mem_read8(x + 4u);
		a = t3;
	}
	a -= 4u;
	b = a;
	y = loaded_table_039DE1_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)a << 1))
	{
	case 0:
		d = b;
		sub_0387ED(x, y, u, d);
		return;
	case 2:
		d = b;
		sub_03880C(y, u, d);
		return;
	case 4:
		d = b;
		sub_038818(u, d);
		return;
	case 6:
		d = b;
		sub_038822(u, d);
		return;
	case 8:
		sub_038833(y, u);
		return;
	}
}

void sub_0387ED(uint16_t x, uint16_t y, uint16_t u, uint8_t d)
{
	uint8_t b = 0, d_3 = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	b = (uint8_t)d;
	t1 = mem_read8(u + 4u);
	if (t1 == 1u)
	{
		stack = b;
		t2 = mem_read16(x + 4u);
		t3 = ((uint32_t)(t2 >> 8) << 8) | (t2 & 0x7Eu);
		b = stack;
		if (t3 == 0x41Au)
		{
			mem_write8(u + VIDEO_0031, 0u);
			d_2 = 0x4E0u;
			sub_038988(y, u, d_2);
			return;
		}
	}
	d_3 = b;
	sub_03880C(y, u, d_3);
}

void sub_03880C(uint16_t y, uint16_t u, uint16_t d)
{
	uint8_t a = 0;

	mem_write8(u + VIDEO_0031, 0u);
	d = ((uint32_t)(uint8_t)((uint16_t)(((uint32_t)a << 8) | d) + 4u) << 8) | (uint8_t)(d - 0x50u);
	sub_038988(y, u, d);
}

void sub_038818(uint16_t u, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t d_3 = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;

	stack = d;
	d_2 = 0x6A00u;
	carry = sub_078680(d_2);
	d_3 = stack;
	sub_038822(u, d_3);
}

void sub_038822(uint16_t u, uint16_t d)
{
	uint16_t y = 0;

	mem_write8(u + VIDEO_0031, 0x3Cu);
	y = 0x813u;
	d = ((uint32_t)(uint8_t)(d + 4u) << 8) | (uint8_t)(d - 0x50u);
	sub_038985(y, u, d);
}

void sub_038833(uint16_t y, uint16_t u)
{
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 0x60u);
	if (t1 != 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	mem_write8(u + VIDEO_0031, 0x3Cu);
	d = 0x8B4u;
	sub_038988(y, u, d);
}

void sub_03886D(uint16_t y, uint16_t u)
{
	uint16_t d = 0, y_2 = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(u + 0x4Eu, 1u);
	mem_write8(u + VIDEO_003C, 1u);
	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)t1)
	{
		sub_038902(u);
		return;
	}
	t3 = mem_read8(u + 0x4Fu);
	if ((int8_t)t3 >= 8)
	{
		mem_write16(u + 0x1Fu, 0x2010u);
		mem_write8(u + 0x30u, 0x29u);
		mem_write8(u, mem_read8(u) | 2u);
		sub_0392F0(y, u);
		return;
	}
	t4 = mem_read8(u + 0x50u);
	if (t4 < 4u)
	{
		mem_write16(u + 0x1Fu, 0x2010u);
		mem_write8(u + 0x30u, 0x29u);
		mem_write8(u, mem_read8(u) | 2u);
		sub_0392F0(y, u);
		return;
	}
	mem_write8(u + 0x50u, 0u);
	y_2 = 0x414u;
	t5 = mem_read8(u + 0x2Bu);
	mem_write8(u + 0x2Bu, t5 + 1u);
	t6 = mem_read8(u + 0x2Bu);
	if (t6 >= 8u)
	{
		mem_write8(u + 0x2Bu, 0u);
		y_2 = 0x414u;
		d = 0xCB8u;
		sub_03892F(y_2, u, d);
		return;
	}
	d = 0xBB7u;
	sub_03892F(y_2, u, d);
}

void sub_0388A2(uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t t2 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0;

	d = 0x3F20u;
	sub_039C50(u, d);
	if ((mem_read8(u) & 0x20u) == 0u)
	{
		sub_038902(u);
		return;
	}
	t1 = mem_read16(u + 0x25u);
	x = t1;
	if (x < unk_4F80_ADDRESS || x >= 0x5280u)
	{
		sub_038902(u);
		return;
	}
	t2 = mem_read8(u + 9u);
	a = t2 & 0xBFu;
	t3 = mem_read16(u + 0xCu);
	t4 = mem_read16(u + 0x25u);
	t5 = mem_read16(t4 + 0xCu);
	if ((int16_t)t5 < (int16_t)t3)
		a |= 0x40u;
	mem_write8(u + 9u, a);
	t6 = mem_read8(u + 0x4Du);
	b = t6;
	t7 = DATA8(object_1c_move_steps_ADDRESS + (int8_t)b);
	a = t7;
	if ((int8_t)t7 < 0)
	{
		a = 0u;
		b = 0u;
	}
	mem_write8(u + 0x4Du, b + 1u);
	t8 = object_1c_moves_ADDRESS + (int8_t)(((uint32_t)a << 1) << 1);
	t9 = DATA16(t8);
	y = mem_read16(t8 + 2u);
	d = t9;
	sub_03892F(y, u, d);
}

void sub_038902(uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(u + 0x2Eu);
	if ((t1 & 3u) == 0u)
	{
		t2 = mem_read8(u + 0x2Bu);
		mem_write8(u + 0x2Bu, t2 + 1u);
		t3 = mem_read8(u + 0x2Bu);
		if (t3 < 3u)
		{
			y = 0x411u;
			d = 0x9B5u;
			sub_03892F(y, u, d);
			return;
		}
	}
	mem_write8(u + 0x2Bu, 0u);
	y = 0x412u;
	d = 0xAB6u;
	sub_03892F(y, u, d);
}

void sub_03892F(uint16_t y, uint16_t u, uint16_t d)
{
	uint16_t x = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x16u);
	x = t1;
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)x <= (int16_t)t2)
	{
		sub_038985(y, u, d);
		return;
	}
	y_2 = sub_03893B(x, u);
	sub_038995(y_2, u, d);
}

uint16_t sub_03893B(uint16_t x, uint16_t u)
{
	uint16_t d = 0, x_2 = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	d = 0x3F20u;
	sub_039C50(u, d);
	stack = x;
	t1 = mem_read16(u + 0x5Cu);
	t2 = stack - t1;
	x_2 = indexed_table_039E07_ADDRESS;
	if ((int16_t)t2 < 0x40)
		x_2 += 0xAu;
	t3 = x_2;
	y = mem_read16(t3);
	t4 = t3 + 2u;
	t5 = mem_read16(t4);
	mem_write16(u + 0x53u, t5);
	mem_write8(u, mem_read8(u) | 2u);
	t6 = t4 + 2u;
	x_2 = t6 + 2u;
	t7 = mem_read16(t6);
	mem_write16(u + 0x19u, t7);
	t8 = mem_read8(u + 9u);
	if ((t8 & 0x40u) != 0u)
		x_2 += 2u;
	mem_write16(u + 0xFu, mem_read16(x_2));
	mem_write16(u + 0x1Fu, 0x804u);
	mem_write8(u + 0x22u, 8u);
	return y;
}

void sub_038985(uint16_t y, uint16_t u, uint16_t d)
{
	mem_write16(u + 0x42u, y);
	sub_038988(y, u, d);
}

void sub_038988(uint16_t y, uint16_t u, uint16_t d)
{
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)t1)
	{
		sub_038995(y, u, d);
		return;
	}
	mem_write16(u + 0xFu, 0u);
	sub_03899A(y, u, d);
}

void sub_038995(uint16_t y, uint16_t u, uint16_t d)
{
	mem_write16(u + 0x42u, y);
	d = (d & ~0xFFu) | (uint8_t)(d + 0x10u);
	sub_03899A(y, u, d);
}

void sub_03899A(uint16_t y, uint16_t u, uint16_t d)
{
	mem_write16(u + 0x14u, 0u);
	sub_03899D(y, u, d);
}

void sub_03899D(uint16_t y, uint16_t u, uint16_t d)
{
	mem_write8(u + 5u, (uint8_t)d);
	mem_write16(u + 0x30u, d & ~0xFFu);
	mem_write8(u + 0x39u, 0u);
	mem_write8(u + 0x38u, 1u);
	mem_write8(u + 6u, 0u);
	sub_038BF9(y, u);
}

void sub_0389B2(uint16_t y, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	sub_039B9B(u);
	t1 = mem_read8(u + 0x2Au);
	if (t1 != 0u)
	{
		y = loaded_table_039E3C_ADDRESS;
		y = sub_039BF9(y, u);
	}
	t2 = mem_read16(u + 0xFu);
	if (t2 != 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	t3 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t3 - 1u);
	if (t3 == 1u)
	{
		mem_write8(u + 0x30u, 0u);
		mem_write8(u + 5u, 0x80u);
		mem_write16(u + 0x1Cu, 0u);
		sub_0392F0(y, u);
		return;
	}
	a = 8u;
	t4 = mem_read8(u + 9u);
	b = t4 ^ 0x40u;
	mem_write8(u + 9u, b);
	if ((b & 0x40u) != 0u)
		a = 0u - a;
	mem_write8(u + 0xFu, a);
	sub_0392F0(y, u);
}

void sub_0389EE(uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t a = 0, b = 0;
	uint16_t x = 0, y = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0, t4 = 0;

	t1 = mem_read8(u + 0x2Eu);
	a = t1;
	if ((a & 1u) != 0u)
		mem_write8(u + 9u, 0x40u);
	if ((a & 2u) != 0u)
		mem_write8(u + 9u, 0u);
	t2 = mem_read16(u + 0x19u);
	x = t2 - 0x60u;
	mem_write16(u + 0x19u, x);
	b = mem_read8(u);
	if (x != 0x240u)
	{
		y = sub_039BAD(u);
		b &= ~2u;
	}
	else
	{
		y = 0xC13u;
		mem_write16(u + 0x1Cu, 0xC13u);
		mem_write8(u + 0x1Fu, 0x10u);
		mem_write8(u + 0x22u, 8u);
		b |= 2u;
	}
	mem_write8(u, b);
	t3 = mem_read8(u + 0x2Au);
	if (t3 != 0u)
	{
		y = loaded_table_039E3B_ADDRESS;
		y = sub_039BF9(y, u);
	}
	sub_039B38(u, &zero, &negative, &overflow);
	if (((negative ^ overflow) | zero) == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	sub_039BA4(u);
	t4 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t4);
	mem_write8(u + 0x18u, 0u);
	sub_039881(u);
	mem_write8(u + 0x3Bu, 0u);
	sub_038C36(y, u);
}

void sub_038A55(uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 != 1u)
	{
		sub_039861(u);
		return;
	}
	t2 = mem_read16(u + 0x3Fu);
	mem_write16(u + 0x3Fu, 0u);
	mem_write8(t2 + 2u, 4u);
	sub_038C36(y, u);
}

void sub_038A69(uint16_t y, uint16_t u)
{
	uint16_t x = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(u + 0x3Fu);
	x = t1;
	t2 = io_read8(VIDEO_0031);
	if (t2 != 0u)
	{
		sub_038BF9(y, u);
		return;
	}
	y_2 = loaded_table_039E1B_ADDRESS;
	t3 = mem_read8(u + 6u);
	if ((t3 & 2u) != 0u)
	{
		t4 = mem_read8(u + VIDEO_0031);
		mem_write8(u + VIDEO_0031, t4 + 1u);
		y_2 = loaded_table_039E23_ADDRESS;
		sub_038AA1(x, y_2, u);
		return;
	}
	y_2 = sub_0399CA(x, y_2, u);
	sub_038BF9(y_2, u);
}

void sub_038A86(uint16_t y, uint16_t u)
{
	uint16_t x = 0, y_2 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(u + 0x3Fu);
	x = t1;
	t2 = io_read8(VIDEO_0031);
	if (t2 != 0u)
	{
		sub_038BF9(y, u);
		return;
	}
	y_2 = loaded_table_039E1B_ADDRESS;
	t3 = mem_read8(u + 6u);
	if ((t3 & 2u) != 0u)
	{
		t4 = mem_read8(u + VIDEO_0031);
		mem_write8(u + VIDEO_0031, t4 + 1u);
		y_2 = loaded_table_039E23_ADDRESS;
		sub_038AA1(x, y_2, u);
		return;
	}
	y_2 = sub_0399CA(x, y_2, u);
	sub_038BF9(y_2, u);
}

void sub_038AA1(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	d = 0x1900u;
	carry = sub_078680(d);
	sub_0399CA(x, y, u);
	t1 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t1);
	mem_write8(x + 0x13u, 0u);
	mem_write8(x + 2u, 4u);
	mem_write16(u + 0x3Fu, 0u);
	y_2 = 0x400u;
	t2 = mem_read8(u + 9u);
	if ((t2 & 0x40u) != 0u)
		y_2 = 0xFC00u;
	mem_write16(x + 0xFu, y_2);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	sub_038BF9(y_2, u);
}

void sub_038ADA(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 6u);
	a = t1;
	if ((a & 2u) != 0u)
	{
		d = 0x1900u;
		carry = sub_078680(d);
		y_2 = 0x882u;
		d = 0x800u;
		carry = sub_039C2F(y_2, u, d);
		sub_038BF9(y_2, u);
		return;
	}
	carry = (a >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(u + 0x9Fu);
		mem_write8(u + 0x9Fu, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write16(u + 0x3Fu, 0u);
			sub_038BF9(y, u);
			return;
		}
	}
	sub_038BF9(y, u);
}

void sub_038B03(uint16_t u)
{
	uint16_t y = 0;

	y = loaded_table_039E3B_ADDRESS;
	sub_038B53(y, u);
}

void sub_038B08(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 6u);
	if ((t1 & 2u) != 0u)
	{
		d = VIDEO_1E00;
		carry = sub_078680(d);
	}
	y = loaded_table_039E3B_ADDRESS;
	sub_038B53(y, u);
}

void sub_038B1A(uint16_t x, uint16_t y, uint16_t u)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = io_read8(VIDEO_184B);
	if (t1 == 0u)
	{
		y_2 = loaded_table_039E3B_ADDRESS;
		sub_038B53(y_2, u);
		return;
	}
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	sub_03839C(y, u);
}

void sub_038B26(uint16_t u)
{
	uint16_t y = 0;

	y = loaded_table_039E3B_ADDRESS;
	sub_038B2E(y, u);
}

void sub_038B2B(uint16_t u)
{
	uint16_t y = 0;

	y = loaded_table_039E3B_ADDRESS;
	sub_038B2E(y, u);
}

void sub_038B2E(uint16_t y, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(u + 5u);
	if ((int8_t)(t1 & 0x7Fu) >= 0x40)
	{
		sub_038B60(y, u);
		return;
	}
	t2 = mem_read8(u + 0x2Eu);
	t3 = DATA16(indexed_table_039F21_ADDRESS + (uint8_t)(((t2 & 0xFu) << 1) << 1));
	t4 = (int16_t)t3 >> 3;
	mem_write16(u + 0xFu, t4);
	sub_038BA9(y, u);
}

void sub_038B4B(uint16_t u)
{
	uint16_t y = 0;

	y = loaded_table_039E3B_ADDRESS;
	sub_038B53(y, u);
}

void sub_038B50(uint16_t u)
{
	uint16_t y = 0;

	y = loaded_table_039E3B_ADDRESS;
	sub_038B53(y, u);
}

void sub_038B53(uint16_t y, uint16_t u)
{
	uint8_t b = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 5u);
	b = t1 & 0x7Fu;
	if ((int8_t)b < 0x40 || b == 0x7Bu)
	{
		sub_038BA9(y, u);
		return;
	}
	sub_038B60(y, u);
}

void sub_038B60(uint16_t y, uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = mem_read8(u + 0x4Eu);
	if (t1 == 0u)
	{
		t2 = mem_read16(u + 0x19u);
		t3 = mem_read16(u + 0x53u);
		t4 = t2 - t3;
		mem_write16(u + 0x19u, t4);
		sub_039B38(u, &zero, &negative, &overflow);
		if (((negative ^ overflow) | zero) == 0u)
		{
			sub_0392F0(y, u);
			return;
		}
		mem_write8(u + 6u, 1u);
		mem_write8(u + 0x4Eu, 0u);
		sub_038C0B(y, u);
		return;
	}
	t5 = mem_read8(u + 0x2Au);
	if (t5 == 0u)
	{
		t6 = mem_read16(u + 0x5Cu);
		t7 = mem_read16(u + 0x16u);
		if ((int16_t)t7 <= (int16_t)(t6 + 0x1Eu) || (unk_4815 & 7u) != 0u)
		{
			mem_write16(u + 0x1Cu, 0u);
			t2 = mem_read16(u + 0x19u);
			t3 = mem_read16(u + 0x53u);
			t4 = t2 - t3;
			mem_write16(u + 0x19u, t4);
			sub_039B38(u, &zero, &negative, &overflow);
			if (((negative ^ overflow) | zero) == 0u)
			{
				sub_0392F0(y, u);
				return;
			}
			mem_write8(u + 6u, 1u);
			mem_write8(u + 0x4Eu, 0u);
			sub_038C0B(y, u);
			return;
		}
		t8 = mem_read16(u + 0x42u);
		mem_write16(u + 0x1Cu, t8);
		t2 = mem_read16(u + 0x19u);
		t3 = mem_read16(u + 0x53u);
		t4 = t2 - t3;
		mem_write16(u + 0x19u, t4);
		sub_039B38(u, &zero, &negative, &overflow);
		if (((negative ^ overflow) | zero) == 0u)
		{
			sub_0392F0(y, u);
			return;
		}
		mem_write8(u + 6u, 1u);
		mem_write8(u + 0x4Eu, 0u);
		sub_038C0B(y, u);
		return;
	}
	y = loaded_table_039E3C_ADDRESS;
	y = sub_039BF9(y, u);
	mem_write16(u + 0x1Cu, 0u);
	t2 = mem_read16(u + 0x19u);
	t3 = mem_read16(u + 0x53u);
	t4 = t2 - t3;
	mem_write16(u + 0x19u, t4);
	sub_039B38(u, &zero, &negative, &overflow);
	if (((negative ^ overflow) | zero) == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	mem_write8(u + 6u, 1u);
	mem_write8(u + 0x4Eu, 0u);
	sub_038C0B(y, u);
}

void sub_038BA9(uint16_t y, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0, t6 = 0;

	t1 = mem_read8(u + 0x2Au);
	if (t1 != 0u)
		y = sub_039BF9(y, u);
	t2 = mem_read8(u + 6u);
	if ((t2 & 2u) == 0u)
	{
		y = sub_039BAD(u);
		mem_write16(u + 0x1Cu, 0u);
		b = mem_read8(u) & ~2u;
		mem_write8(u, b);
		sub_038BF9(y, u);
		return;
	}
	t3 = mem_read16(u + 0x42u);
	mem_write16(u + 0x1Cu, t3);
	t4 = mem_read8(u + 0x30u);
	a = t4;
	if (a == 0x38u)
	{
		mem_write8(u + 0x1Fu, 0x12u);
		mem_write8(u + 0x22u, 0x10u);
		sub_038BF9(y, u);
		return;
	}
	t5 = mem_read8(u + 4u);
	t6 = DATA16(indexed_table_039F99_ADDRESS + (int8_t)(((((a - 6u) << 1) << 1) + t5) << 1));
	mem_write8(u + 0x1Fu, t6 >> 8);
	mem_write8(u + 0x22u, t6);
	b = mem_read8(u) | 2u;
	mem_write8(u, b);
	sub_038BF9(y, u);
}

void sub_038BF9(uint16_t y, uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint16_t t1 = 0;

	sub_039B38(u, &zero, &negative, &overflow);
	if (zero)
	{
		sub_038C1D(y, u);
		return;
	}
	if ((negative ^ overflow) | zero)
	{
		sub_038C0B(y, u);
		return;
	}
	t1 = mem_read16(u + 0x19u);
	mem_write16(u + 0x19u, t1 - 0x60u);
	sub_038C1D(y, u);
}

void sub_038C0B(uint16_t y, uint16_t u)
{
	uint16_t t1 = 0;

	sub_039BA4(u);
	t1 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t1);
	mem_write8(u + 0x18u, 0u);
	sub_039881(u);
	mem_write8(u + 0x3Bu, 0u);
	sub_038C1D(y, u);
}

void sub_038C1D(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t21 = 0, t22 = 0, t23 = 0;
	uint16_t t3 = 0, t6 = 0, t9 = 0, t10 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0;

	t1 = mem_read8(u + 0x39u);
	if ((int8_t)t1 >= 0)
	{
		sub_038C22(y, u);
		return;
	}
	t2 = mem_read8(u + 6u);
	carry = (t2 >> 0) & 1u;
	if (carry == 0u)
	{
		for (;;)
		{
			t3 = mem_read16(u + 0x32u);
			x = t3;
			sub_039A6E(x, u);
			t4 = mem_read8(x + 4u);
			a = t4;
			if ((int8_t)unk_4858 < 0)
			{
				t5 = mem_read8(u + 4u);
				a = t5;
			}
			mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
			t6 = mem_read16(u + 0x28u);
			mem_write16(u + 0x28u, t6 - 1u);
			if (t6 != 1u)
			{
				sub_0392F0(y, u);
				return;
			}
			t7 = mem_read8(u + 0x35u);
			if (t7 != 2u)
				break;
			t8 = mem_read8(u + 0x35u);
			a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t8);
			mem_write8(u + VIDEO_003C, a);
			mem_write16(u + 0x1Cu, 0xC13u);
			t9 = mem_read16(u + 0x16u);
			x = t9;
			t10 = mem_read16(u + 0x5Cu);
			if ((int16_t)t10 < (int16_t)x)
			{
				sub_03893B(x, u);
				b = 0xFCu;
			}
			else
			{
				mem_write16(u + 0xFu, 0u);
				mem_write16(u + 0x14u, 0u);
				b = 0xF8u;
			}
			mem_write8(u + 0x30u, a);
			unk_48F2 = b;
			y = indexed_table_039E3D_ADDRESS;
			t11 = mem_read8(u + 0x35u);
			t12 = mem_read8(u + 4u);
			t13 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t11 << 1) << 1) + t12));
			a = t13;
			if ((int8_t)t13 < 0)
				continue;
			mem_write8(u + 5u, a + unk_48F2);
		}
		sub_039A1A(x, u);
		mem_write8(x, 0xC0u);
		mem_write16(u + 0xFu, 0u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(u + 0x14u, 0u);
		mem_write16(x + 0x14u, 0u);
		sub_0392F0(y, u);
		return;
	}
	mem_write16(u + 0x1Cu, 0u);
	t14 = mem_read8(u + 0x30u);
	if (t14 != 0x35u)
	{
		t15 = mem_read16(u + 0x16u);
		t16 = mem_read16(u + 0x5Cu);
		if ((int16_t)t15 <= (int16_t)t16)
		{
			sub_0391D0(u);
			return;
		}
		sub_038556(u);
		return;
	}
	t17 = mem_read16(u + 0x5Cu);
	a = (uint8_t)(t17 >> 8);
	b = (uint8_t)t17;
	t18 = mem_read16(u + 0x16u);
	if ((int16_t)t18 <= (int16_t)(((uint32_t)a << 8) | b))
	{
		mem_write16(u + 0x16u, ((uint32_t)a << 8) | b);
		mem_write8(u + 0x18u, 0u);
		mem_write16(u + 0x19u, 0u);
		mem_write16(u + 0xFu, 0u);
	}
	mem_write16(u + 0x14u, 0u);
	t19 = mem_read16(u + 0x32u);
	x = t19;
	mem_write16(u + 0x30u, 0x3703u);
	mem_write8(x + 0x30u, 0x36u);
	mem_write8(u + 5u, 0xF9u);
	mem_write8(x + 5u, 0xF9u);
	mem_write16(u + 0x1Cu, 0x811u);
	t20 = mem_read16(x + 0x16u);
	mem_write16(u + 0x16u, t20 + 0x38u);
	y_2 = 0x800u;
	t21 = mem_read8(u + 9u);
	t22 = t21 & 0x40u;
	a = t22;
	if (t22 != 0u)
		y_2 = 0xF800u;
	mem_write16(u + 0xFu, y_2);
	mem_write16(u + 0x14u, 0u);
	mem_write16(u + 0x19u, 0u);
	stack = a;
	t23 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t23 & 0x70u) | stack);
	sub_039A28(x, u);
	mem_write8(x, mem_read8(u));
	sub_0392F0(y_2, u);
}

void sub_038C22(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	t2 = mem_read8(u + 9u);
	t3 = mem_read8(u + 0x2Du);
	mem_write8(u + 9u, (t2 & 0xBFu) | t3);
	sub_038C3C(y, u);
}

void sub_038C36(uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + 0x1Bu);
	if (t1 == 0u)
	{
		sub_038FAE(u);
		return;
	}
	sub_038C3C(y, u);
}

void sub_038C3C(uint16_t y, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;
	uint16_t t3 = 0, t4 = 0;

	t1 = mem_read8(u + 0x34u);
	if ((int8_t)t1 < 0)
	{
		t2 = mem_read8(u + 9u);
		mem_write8(u + 9u, t2 ^ 0x40u);
		mem_write8(u + 0x34u, 0u);
	}
	mem_write8(u, (mem_read8(u) & ~2u) | 0x40u);
	mem_write8(u + 0x22u, 0u);
	mem_write16(u + 0x1Cu, 0u);
	t3 = mem_read16(u + 0x16u);
	t4 = mem_read16(u + 0x5Cu);
	if ((int16_t)t3 <= (int16_t)t4)
	{
		sub_0386B8(u);
		return;
	}
	sub_038670(y, u);
}

void sub_038CF1(uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint16_t d = 0;
	uint16_t t1 = 0;

	mem_write16(u + 0xFu, 0x100u);
	mem_write16(u + 0x19u, 0x500u);
	sub_039A93(u, &zero, &carry);
	mem_write16(u + 0x14u, 0xFA00u);
	t1 = mem_read16(u + 0x11u);
	if ((int16_t)t1 >= 0x98)
	{
		sub_039861(u);
		return;
	}
	d = 0x3F00u;
	sub_039C50(u, d);
	d = 0x1B00u;
	carry = sub_078680(d);
	sub_039881(u);
	mem_write16(u + 0x11u, 0x98u);
	mem_write16(u + 0x30u, 0x3C10u);
	sub_038D2A(u);
}

void sub_038D2A(uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 != 1u)
	{
		sub_039861(u);
		return;
	}
	mem_write16(u + 0x19u, 0xFF80u);
	mem_write16(u + 0x30u, 0x3D10u);
	sub_038D3C(u);
}

void sub_038D3C(uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 != 1u)
	{
		sub_039861(u);
		return;
	}
	mem_write16(u + 0x19u, 0u);
	mem_write16(u + 0x30u, 0x3E10u);
	sub_038D4B(u);
}

void sub_038D4B(uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 != 1u)
	{
		sub_039861(u);
		return;
	}
	y = 0xE10u;
	d = 0xDEu;
	sub_038F8D(y, u, d);
}

void sub_038D59(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t x = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x5Cu);
	x = t1;
	t2 = mem_read16(u + 0x16u);
	if ((int16_t)t2 <= (int16_t)x)
	{
		mem_write16(u + 0x16u, x);
		mem_write8(u + 0x18u, 0u);
		mem_write16(u + 0x19u, 0u);
		t3 = mem_read8(u + 6u);
		carry = (t3 >> 0) & 1u;
		if (carry)
		{
			sub_038FA1(u);
			return;
		}
	}
	sub_039861(u);
}

void sub_038D75(uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	sub_039B38(u, &zero, &negative, &overflow);
	if ((negative ^ overflow) | zero)
	{
		sub_039BA4(u);
		t1 = mem_read8(u + VIDEO_0031);
		mem_write8(u + VIDEO_0031, t1 - 1u);
		if (t1 == 1u)
		{
			sub_038FA1(u);
			return;
		}
		t2 = mem_read16(u + 0xFu);
		if (t2 == 0u)
		{
			sub_038FA1(u);
			return;
		}
		mem_write16(u + 0x19u, 0u);
		t3 = mem_read16(u + 0x5Cu);
		mem_write16(u + 0x16u, t3);
		mem_write8(u + 0x18u, 0u);
		sub_039A93(u, &zero, &carry);
		if (carry == 0u)
		{
			sub_039861(u);
			return;
		}
		sub_038FA1(u);
		return;
	}
	sub_039B9B(u);
	t4 = mem_read16(u + 0x19u);
	mem_write16(u + 0x19u, t4 - 0x60u);
	sub_039A93(u, &zero, &carry);
	if (zero)
	{
		sub_039861(u);
		return;
	}
	sub_038F0E(u);
}

void sub_038DB3(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_039861(u);
		return;
	}
	sub_038C36(y, u);
}

void sub_038DBD(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_039861(u);
		return;
	}
	t2 = mem_read8(u + 0x1Bu);
	if (t2 == 0u)
	{
		sub_038FAE(u);
		return;
	}
	y = 0x2300u;
	d = 0xDCu;
	sub_038F81(y, u, d);
}

void sub_038DD2(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_039861(u);
		return;
	}
	t2 = mem_read8(u + 0x1Bu);
	if (t2 == 0u)
	{
		sub_038FAE(u);
		return;
	}
	y = 0x2400u;
	d = 0xDDu;
	sub_038F81(y, u, d);
}

void sub_038DE7(uint16_t y, uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	uint16_t t5 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	if (t1 != 0x10u)
	{
		t2 = mem_read8(u + VIDEO_0031);
		mem_write8(u + VIDEO_0031, t2 - 1u);
		if (t2 == 1u)
		{
			sub_038C36(y, u);
			return;
		}
		sub_039861(u);
		return;
	}
	sub_039B38(u, &zero, &negative, &overflow);
	if (((negative ^ overflow) | zero) == 0u)
	{
		mem_write16(u + 0x19u, 0xFD00u);
		sub_039861(u);
		return;
	}
	t3 = mem_read8(u + 0x30u);
	if (t3 == 0x28u)
	{
		sub_039108(u);
		return;
	}
	t4 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t4 - 1u);
	t5 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t5);
	mem_write8(u + 0x18u, 0u);
	mem_write16(u + 0x19u, 0u);
	sub_039861(u);
}

void sub_038E1F(uint16_t y, uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_039B38(u, &zero, &negative, &overflow);
	if (((negative ^ overflow) | zero) == 0u)
	{
		t1 = mem_read16(u + 0x19u);
		mem_write16(u + 0x19u, t1 - 0x60u);
		sub_039861(u);
		return;
	}
	mem_write16(u + 0x19u, 0u);
	t2 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t2);
	mem_write8(u + 0x18u, 0u);
	t3 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t3 - 1u);
	if (t3 == 1u)
	{
		sub_038C36(y, u);
		return;
	}
	sub_039861(u);
}

void sub_038E45(uint16_t y, uint16_t u)
{
	uint8_t a = 0;
	uint16_t d = 0, x = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(u + 0x4Bu);
	x = t1;
	if ((mem_read8(u) & 0x20u) != 0u)
	{
		t2 = mem_read8(u + 0x1Eu);
		a = t2;
		if (t2 != 0u && a < 0x10u)
		{
			mem_write8(x + 0x58u, 2u);
			d = 0x3F24u;
			sub_039C50(u, d);
			t3 = mem_read8(u + 0x60u);
			if (t3 == 0u)
				sub_039BBA(u, &x, &y);
			sub_039B89(u);
			mem_write8(u, 0x80u);
			mem_write8(u + 0x30u, 0x3Au);
		}
	}
	t4 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t4 - 1u);
	if (t4 != 1u)
	{
		sub_038E90(x, y, u);
		return;
	}
	sub_039B89(u);
	mem_write8(u + VIDEO_0031, 0x3Cu);
	t5 = mem_read8(u + 0x1Bu);
	t6 = t5;
	a = t6 - 4u;
	if (t6 < 4u)
		a = 0u;
	mem_write8(u + 0x1Bu, a);
	sub_038E90(x, y, u);
}

void sub_038E90(uint16_t x, uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + 0x1Bu);
	if (t1 == 0u)
	{
		d = 0xD00u;
		carry = sub_039C2F(y, u, d);
		t2 = mem_read16(u + 0x4Bu);
		mem_write8(t2 + 0x58u, 0u);
		sub_038F79(u);
		return;
	}
	t3 = io_read8(VIDEO_184B);
	if (t3 != 0u)
	{
		d = 0xD00u;
		carry = sub_039C2F(y, u, d);
		mem_write8(x + 0x58u, 0u);
		mem_write8(u + 0x3Du, 0u);
		mem_write8(u, 0x80u);
		mem_write8(u + 0x30u, 0x3Bu);
		sub_039861(u);
		return;
	}
	t4 = mem_read8(x + 2u);
	if (t4 == 4u)
	{
		d = 0xD00u;
		carry = sub_039C2F(y, u, d);
		mem_write8(x + 0x58u, 0u);
		mem_write8(u + 0x3Du, 0u);
		mem_write8(u, 0x80u);
		mem_write8(u + 0x30u, 0x3Bu);
		sub_039861(u);
		return;
	}
	t5 = mem_read8(u + VIDEO_002F);
	if (t5 != 0u)
	{
		t6 = mem_read8(u + 0x3Du);
		mem_write8(u + 0x3Du, t6 - 1u);
		if (t6 == 1u)
		{
			d = 0xD00u;
			carry = sub_039C2F(y, u, d);
			mem_write8(x + 0x58u, 0u);
			mem_write8(u + 0x3Du, 0u);
			mem_write8(u, 0x80u);
			mem_write8(u + 0x30u, 0x3Bu);
			sub_039861(u);
			return;
		}
	}
	sub_039861(u);
}

void sub_038ED5(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(u + 0x4Bu);
	x = t1;
	t2 = mem_read8(x + 6u);
	carry = (t2 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_038E90(x, y, u);
		return;
	}
	mem_write8(u, 0xC0u);
	mem_write8(u + 0x30u, 0x1Cu);
	sub_038E90(x, y, u);
}

void sub_038EEA(uint16_t u)
{
	mem_write8(u, 0xC0u);
	mem_write8(u + 5u, 0x80u);
	mem_write8(u + 0x30u, 0u);
	sub_039861(u);
}

void sub_038EFA(uint16_t y, uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t a = 0, b = 0, d = 0;
	uint16_t x = 0, y_2 = 0;
	uint8_t t4 = 0, t5 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0;

	sub_039B38(u, &zero, &negative, &overflow);
	if (((negative ^ overflow) | zero) == 0u)
	{
		t1 = mem_read16(u + 0x19u);
		t2 = t1 - 0x60u;
		mem_write16(u + 0x19u, t2);
		sub_039A93(u, &zero, &carry);
		if (zero)
		{
			sub_039861(u);
			return;
		}
		sub_038F0E(u);
		return;
	}
	t3 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t3);
	mem_write8(u + 0x18u, 0u);
	sub_039BA4(u);
	mem_write16(u + 0x19u, 0u);
	t4 = mem_read8(u + 0xFu);
	b = t4;
	mem_write16(u + 0xFu, 0u);
	t5 = mem_read8(u + 0x30u);
	a = t5;
	if (a == 0x18u)
	{
		t6 = mem_read16(u + 0xCu);
		x = t6;
		if ((int16_t)x < 0x140 && (int16_t)x > 0x70)
		{
			t7 = mem_read8(u + 0xDu);
			a = t7;
			if ((a & 1u) == 0u)
			{
				sub_038C36(y, u);
				return;
			}
		}
	}
	if ((a & 2u) == 0u)
	{
		sub_038F79(u);
		return;
	}
	y_2 = 0x400u;
	if (b == 0u)
	{
		sub_038F79(u);
		return;
	}
	if ((int8_t)b < 0)
		y_2 = 0xFC00u;
	mem_write16(u + 0xFu, y_2);
	y_2 = 0x1420u;
	b = 0xD3u;
	t8 = mem_read8(u + 0x30u);
	if (t8 != 0x19u)
		y_2 = 0x1408u;
	d = b;
	sub_038F81(y_2, u, d);
}

void sub_038F0E(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x1B00u;
	carry = sub_078680(d);
	mem_write8(u + 5u, 0xD6u);
	mem_write16(u + 0x30u, 0x1720u);
	mem_write16(u + 0x19u, 0u);
	sub_039861(u);
}

void sub_038F79(uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;

	mem_write16(u + 0xFu, 0u);
	y = 0x1500u;
	d = 0xD4u;
	sub_038F81(y, u, d);
}

void sub_038F81(uint16_t y, uint16_t u, uint8_t d)
{
	uint16_t t1 = 0;

	sub_039BA4(u);
	t1 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t1);
	mem_write8(u + 0x18u, 0u);
	sub_038F8D(y, u, d);
}

void sub_038F8D(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write8(u + 5u, d);
	mem_write16(u + 0x30u, y);
	mem_write16(u + 0x19u, 0u);
	mem_write16(u + 0x38u, 0x100u);
	sub_039BAD(u);
	sub_03978A(u);
}

void sub_038FA1(uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;

	mem_write16(u + 0xFu, 0u);
	mem_write8(u + 0x2Cu, 0u);
	y = 0x1600u;
	d = 0xD5u;
	sub_038F81(y, u, d);
}

void sub_038FAE(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	t1 = mem_read16(u + 0x3Fu);
	x = t1;
	if (t1 != 0u)
	{
		t2 = mem_read8(u + 0x3Fu);
		if (t2 != 0u)
		{
			mem_write16(u + 0x3Fu, 0u);
			t3 = mem_read8(x + 0x1Du);
			if (t3 != 0xFEu)
			{
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				mem_write8(x + 2u, 6u);
			}
		}
	}
	sub_039881(u);
	d = VIDEO_1A00;
	carry = sub_078680(d);
	unk_4862 = 0u;
	t4 = io_read16(VIDEO_1848);
	t5 = mem_read16(t4);
	d_2 = (uint8_t)t5;
	if ((uint16_t)(((uint32_t)(t5 >> 8) << 8) | (d_2 & 0xFFu)) != 1u)
	{
		mem_write8(u + 5u, 0xDFu);
		mem_write16(u + 0x30u, 0x1F78u);
		sub_039861(u);
		return;
	}
	t6 = io_read16(VIDEO_1848);
	mem_write8(t6 + 6u, 0u);
	mem_write8(u + 5u, 0xCEu);
	y = 0x2E0u;
	d = (d_2 & 0xFFu) | 0xB00u;
	carry = sub_039C2F(y, u, d);
	t7 = mem_read16(u + 0xCu);
	mem_write16(u + 0x6Cu, t7);
	t8 = mem_read16(u + 0x11u);
	x = t8 - 0x50u;
	mem_write16(u + 0x11u, x);
	mem_write16(u + 0x71u, x + 0x10u);
	t9 = mem_read16(u + 0x16u);
	x = t9 + 0x50u;
	mem_write16(u + 0x16u, x);
	mem_write16(u + 0x76u, x);
	mem_write16(u + 0x30u, 0x2052u);
	sub_039861(u);
}

void sub_03902E(uint16_t u)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		unk_4865 = 0u;
		unk_4863 = 0u;
		t2 = io_read16(VIDEO_1848);
		mem_write8(t2 + 3u, 0u);
		mem_write8(u + 0x34u, 0u);
		t3 = io_read16(VIDEO_1848);
		mem_write16(t3, mem_read16(t3) - 1u);
		sub_039861(u);
		return;
	}
	t4 = mem_read8(u + VIDEO_0031);
	a = t4;
	if (a == 0x1Eu)
	{
		mem_write8(u, 0u);
		sub_039861(u);
		return;
	}
	if ((int8_t)(a - 0x1Eu) < 0 || (int8_t)a >= 0x50)
	{
		sub_039861(u);
		return;
	}
	sub_039B51(u);
	sub_039861(u);
}

void sub_039065(uint16_t u)
{
	uint32_t carry = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 0x66u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		y = 0x2E4u;
		mem_write16(u + 0x64u, y);
		t2 = mem_read8(u + 0x30u);
		mem_write8(u + 0x30u, t2 + 1u);
	}
	sub_039B51(u);
	sub_039861(u);
}

void sub_039070(uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(u + 0x64u, 0x2E8u);
		t2 = mem_read8(u + 0x30u);
		mem_write8(u + 0x30u, t2 + 1u);
	}
	sub_039B51(u);
	sub_039861(u);
}

void sub_039084(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(u + 0x66u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
	{
		sub_039861(u);
		return;
	}
	t2 = io_read16(VIDEO_1848);
	mem_write8(t2 + 3u, 0u);
	mem_write8(u + 0x60u, 0u);
	mem_write8(u, 0u);
	unk_4865 = 0u;
	unk_4863 = 0u;
	t3 = io_read16(VIDEO_1848);
	mem_write8(t3 + 3u, 0u);
	mem_write8(u + 0x34u, 0u);
	t4 = io_read16(VIDEO_1848);
	mem_write16(t4, mem_read16(t4) - 1u);
	sub_039861(u);
}

void sub_03909B(uint16_t u)
{
	uint16_t d = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	sub_039B9B(u);
	t1 = mem_read16(u + 0x19u);
	mem_write16(u + 0x19u, t1 + 8u);
	t2 = mem_read16(u + 0xFu);
	d = t2 - 0x70u;
	mem_write16(u + 0xFu, d);
	if ((int16_t)d >= 0)
	{
		t3 = mem_read16(u + 0xCu);
		if ((int16_t)t3 >= 0x72)
		{
			sub_0390EE(u);
			return;
		}
		sub_039861(u);
		return;
	}
	t4 = mem_read8(u + 0x30u);
	mem_write8(u + 0x30u, t4 + 1u);
	mem_write8(u + 5u, 0xBBu);
	t5 = mem_read8(u + 9u);
	mem_write8(u + 9u, (uint16_t)((((uint16_t)((uint32_t)t5 << 8) >> 8) | 0x40u) << 8) >> 8);
	sub_0390EE(u);
}

void sub_0390CF(uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0;
	uint16_t d = 0;
	uint16_t t1 = 0, t2 = 0;

	sub_039B9B(u);
	sub_039B38(u, &zero, &negative, &overflow);
	if ((negative ^ overflow) | zero)
	{
		sub_039108(u);
		return;
	}
	t1 = mem_read16(u + 0x19u);
	mem_write16(u + 0x19u, t1 - 0x60u);
	t2 = mem_read16(u + 0xFu);
	d = t2;
	if ((int16_t)d <= -0x300)
	{
		sub_0390EE(u);
		return;
	}
	mem_write16(u + 0xFu, d - 0x60u);
	sub_0390EE(u);
}

void sub_0390EE(uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, y = 0;

	sub_039A93(u, &zero, &carry);
	if (carry == 0u)
	{
		sub_039861(u);
		return;
	}
	mem_write16(u + 0x19u, 0u);
	mem_write16(u + 0x1Cu, 0u);
	d = 0x1B00u;
	carry = sub_078680(d);
	y = 0x2820u;
	d_2 = 0xD6u;
	sub_038F8D(y, u, d_2);
}

void sub_039108(uint16_t u)
{
	uint16_t t1 = 0;

	mem_write16(u + 0xFu, 0u);
	mem_write16(u + 0x19u, 0u);
	t1 = mem_read16(u + 0x5Cu);
	mem_write16(u + 0x16u, t1);
	mem_write8(u + 0x18u, 0u);
	sub_039B0C(u);
	mem_write8(u + 0x30u, 0u);
	mem_write16(u + 0x1Cu, 0u);
	mem_write8(u + 5u, 0x80u);
	sub_039861(u);
}

void sub_039128(uint16_t u)
{
	sub_039861(u);
}

void sub_03912B(uint16_t y, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(u + VIDEO_0031);
	mem_write8(u + VIDEO_0031, t1 - 1u);
	if (t1 != 1u)
	{
		sub_0392F0(y, u);
		return;
	}
	sub_038C36(y, u);
}

void sub_039134(uint16_t y, uint16_t u)
{
	uint8_t d = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t6 = 0;
	uint16_t t5 = 0;

	t1 = mem_read8(u + 0x2Eu);
	if ((t1 & 0x2Fu) != 0u)
	{
		mem_write16(u + 0x3Fu, 0u);
		mem_write8(u + 0x41u, 0u);
		sub_0386CA(u);
		return;
	}
	t2 = mem_read8(u + 0x41u);
	if ((int8_t)t2 >= 3)
	{
		t3 = io_read8(VIDEO_184D);
		io_write8(VIDEO_184D, t3 + 1u);
		sub_0392F0(y, u);
		return;
	}
	t4 = mem_read8(u + VIDEO_002F);
	if ((t4 & 0x10u) == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	t5 = mem_read16(u + 0x3Fu);
	mem_write8(t5 + 0x28u, 2u);
	d = 0xC9u;
	y_2 = sub_039B5C(u, d);
	t6 = mem_read8(u + 0x41u);
	mem_write8(u + 0x41u, t6 + 1u);
	sub_0392F0(y_2, u);
}

void sub_03916D(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y_2 = 0;
	uint8_t t2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0, t13 = 0, t15 = 0, t16 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t11 = 0, t14 = 0, t17 = 0, t18 = 0;

	t1 = mem_read16(u + 0x32u);
	x = t1;
	t2 = io_read8(VIDEO_184B);
	if (t2 != 0u)
	{
		sub_039A1A(x, u);
		mem_write8(x, 0xC0u);
		sub_03839C(y, u);
		return;
	}
	t3 = mem_read16(u + 0x16u);
	t4 = mem_read16(u + 0x5Cu);
	if ((int16_t)t4 < (int16_t)t3)
	{
		sub_039A1A(x, u);
		mem_write8(x, 0xC0u);
		sub_03839C(y, u);
		return;
	}
	t5 = mem_read8(u + VIDEO_002F);
	t6 = mem_read8(x + VIDEO_002F);
	a = t5 | t6;
	if ((a & 0x20u) != 0u)
	{
		sub_039A1A(x, u);
		mem_write8(x, 0xC0u);
		sub_03839C(y, u);
		return;
	}
	if ((a & 0x1Fu) == 0u)
	{
		sub_0392F0(y, u);
		return;
	}
	t7 = mem_read8(u + 0x35u);
	if ((int8_t)t7 < 2 && unk_4867 == 0u)
	{
		mem_write8(u + 0x9Eu, 0u);
		y_2 = 0xB180u;
		d = 0x300u;
		carry = sub_039C2F(y_2, u, d);
	}
	mem_write8(u + 0x55u, 3u);
	mem_write8(u + 0x30u, 0x31u);
	b = 0xE4u;
	for (;;)
	{
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t8 = mem_read8(u + 0x35u);
		t9 = mem_read8(u + 4u);
		t10 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t8 << 1) << 1) + t9));
		a = t10;
		if ((int8_t)t10 >= 0)
			mem_write8(u + 5u, a + unk_48F2);
		t11 = mem_read16(u + 0x32u);
		x = t11;
		sub_039A6E(x, u);
		t12 = mem_read8(x + 4u);
		a = t12;
		if ((int8_t)unk_4858 < 0)
		{
			t13 = mem_read8(u + 4u);
			a = t13;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t14 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t14 - 1u);
		if (t14 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t15 = mem_read8(u + 0x35u);
		if (t15 != 2u)
			break;
		t16 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t16);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t17 = mem_read16(u + 0x16u);
		x = t17;
		t18 = mem_read16(u + 0x5Cu);
		if ((int16_t)t18 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
	}
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y, u);
}

void sub_0391C1(uint16_t u)
{
	uint16_t t1 = 0;

	t1 = mem_read16(u + 0x32u);
	mem_write16(u + 0x28u, 0x1E0u);
	mem_write16(t1 + 0x28u, 0x1E0u);
	sub_0391CD(u);
}

void sub_0391CD(uint16_t u)
{
	sub_0391D0(u);
}

void sub_0391D0(uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0;
	uint16_t t1 = 0, t6 = 0, t9 = 0, t12 = 0, t13 = 0;

	t1 = mem_read16(u + 0x5Cu);
	y = t1;
	mem_write16(u + 0x16u, y);
	mem_write8(u + 0x18u, 0u);
	sub_039881(u);
	mem_write16(u + 0x3Bu, 0u);
	mem_write8(u + 0x30u, 0x32u);
	t2 = mem_read8(u + 0x35u);
	if (t2 != 0u)
	{
		b = 0xECu;
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t3 = mem_read8(u + 0x35u);
		t4 = mem_read8(u + 4u);
		t5 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t3 << 1) << 1) + t4));
		a = t5;
		if ((int8_t)t5 >= 0)
			mem_write8(u + 5u, a + unk_48F2);
	}
	for (;;)
	{
		t6 = mem_read16(u + 0x32u);
		x = t6;
		sub_039A6E(x, u);
		t7 = mem_read8(x + 4u);
		a = t7;
		if ((int8_t)unk_4858 < 0)
		{
			t8 = mem_read8(u + 4u);
			a = t8;
		}
		mem_write8(u + 0x5Bu, ((((uint32_t)a << 1) << 1) << 1) << 1);
		t9 = mem_read16(u + 0x28u);
		mem_write16(u + 0x28u, t9 - 1u);
		if (t9 != 1u)
		{
			sub_0392F0(y, u);
			return;
		}
		t10 = mem_read8(u + 0x35u);
		if (t10 != 2u)
			break;
		t11 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039DD5_ADDRESS + (int8_t)t11);
		mem_write8(u + VIDEO_003C, a);
		mem_write16(u + 0x1Cu, 0xC13u);
		t12 = mem_read16(u + 0x16u);
		x = t12;
		t13 = mem_read16(u + 0x5Cu);
		if ((int16_t)t13 < (int16_t)x)
		{
			sub_03893B(x, u);
			b = 0xFCu;
		}
		else
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			b = 0xF8u;
		}
		mem_write8(u + 0x30u, a);
		unk_48F2 = b;
		y = indexed_table_039E3D_ADDRESS;
		t3 = mem_read8(u + 0x35u);
		t4 = mem_read8(u + 4u);
		t5 = DATA8(indexed_table_039E3D_ADDRESS + (int8_t)((((uint32_t)t3 << 1) << 1) + t4));
		a = t5;
		if ((int8_t)t5 < 0)
			continue;
		mem_write8(u + 5u, a + unk_48F2);
	}
	sub_039A1A(x, u);
	mem_write8(x, 0xC0u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(x + 0x14u, 0u);
	sub_0392F0(y, u);
}

void sub_039242(uint16_t y, uint16_t u, uint8_t d)
{
	uint8_t a = 0, b = 0, d_2 = 0;
	uint16_t x = 0, y_2 = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0, t13 = 0, t14 = 0, t16 = 0, t17 = 0, t18 = 0, t22 = 0, t23 = 0;
	uint16_t t1 = 0, t6 = 0, t7 = 0, t11 = 0, t15 = 0, t19 = 0, t20 = 0, t21 = 0;

	b = (uint8_t)d;
	t1 = mem_read16(u + 0x3Fu);
	x = t1;
	if (t1 == 0u)
	{
		mem_write8(u + 5u, b);
		sub_0392F0(y, u);
		return;
	}
	t2 = mem_read8(u + 0x3Fu);
	if (t2 == 0u)
	{
		t3 = mem_read8(u + 0x40u);
		stack = (((t3 - 3u) << 1) << 1) << 1;
		mem_write8(u + 5u, b + stack);
		t4 = io_read8(VIDEO_184B);
		if (t4 != 0u)
		{
			sub_03963F(x, u);
			return;
		}
		sub_0392F0(y, u);
		return;
	}
	t5 = mem_read8(u + 4u);
	if (t5 == 1u)
	{
		stack = b;
		t6 = mem_read16(x + 4u);
		t7 = ((uint32_t)(t6 >> 8) << 8) | (t6 & 0x7Eu);
		b = stack;
		if (t7 == 0x41Au)
		{
			mem_write8(u + 5u, b + 0x61u);
			sub_039A6E(x, u);
			t8 = io_read8(VIDEO_184B);
			if (t8 != 0u)
			{
				sub_03963F(x, u);
				return;
			}
			sub_0392F0(y, u);
			return;
		}
	}
	t9 = mem_read8(x + 4u);
	a = (((t9 - 3u) << 1) << 1) << 1;
	stack = a;
	mem_write8(u + 5u, b + stack);
	t10 = io_read8(VIDEO_184B);
	if (t10 != 0u)
	{
		t11 = mem_read16(u + 0x3Fu);
		y_2 = t11;
		if (t11 != 0u)
		{
			t12 = mem_read8(u + 0x3Fu);
			if (t12 != 0u)
			{
				mem_write8(y_2, 0u);
				mem_write16(u + 0x3Fu, 0u);
			}
		}
		sub_03965F(u);
		return;
	}
	t13 = mem_read8(u + 4u);
	t14 = mem_read8(u + 4u);
	t15 = y + (int8_t)(a + t13 + t14);
	y_2 = t15 + 1u;
	b = mem_read8(t15);
	t16 = mem_read8(u + 9u);
	t17 = t16 & 0x40u;
	a = t17;
	if (t17 != 0u)
		b = 0u - b;
	stack = a;
	t18 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t18 & 0xBFu) | stack);
	t19 = (int8_t)b;
	t20 = mem_read16(u + 0xCu);
	t21 = t19 + t20;
	mem_write16(x + 0xCu, t21);
	t22 = mem_read8(u + 6u);
	t23 = mem_read8(u + 0x34u);
	b = ((t22 & 2u) >> 1) ^ t23;
	mem_write8(u + 0x34u, b);
	d_2 = (uint8_t)(b + mem_read8(y_2));
	sub_0399E3(x, u, d_2);
	sub_0392F0(y_2, u);
}

void sub_0392F0(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t19 = 0, t24 = 0;
	uint16_t t3 = 0, t5 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t25 = 0, t26 = 0;

	t1 = mem_read8(u + 0x3Eu);
	if (t1 != 0u)
	{
		t2 = mem_read8(u + 0x3Eu);
		mem_write8(u + 0x3Eu, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(u, 0xC0u);
			t3 = io_read16(VIDEO_1848);
			mem_write8(t3 + 3u, 2u);
			d = 0xD00u;
			carry = sub_039C2F(y, u, d);
			sub_03978A(u);
			return;
		}
		sub_039B51(u);
		sub_03978A(u);
		return;
	}
	if ((mem_read8(u) & 0x20u) == 0u)
	{
		sub_03978A(u);
		return;
	}
	t4 = mem_read8(u + 0x1Eu);
	b = t4;
	if (t4 == 0u)
	{
		sub_03978A(u);
		return;
	}
	if ((int8_t)b < -0x10)
	{
		if ((int8_t)b > -0x7D)
		{
			sub_03978A(u);
			return;
		}
		t5 = mem_read16(u + 0x25u);
		x = t5;
		t6 = mem_read8(x + 0x3Eu);
		if (t6 != 0u)
		{
			sub_03978A(u);
			return;
		}
		t7 = mem_read8(u + 0x39u);
		if ((int8_t)t7 < 0)
		{
			sub_03978A(u);
			return;
		}
		t8 = mem_read8(x + 0x39u);
		if ((int8_t)t8 < 0)
		{
			sub_03978A(u);
			return;
		}
		mem_write8(u + 0x41u, 0u);
		t9 = mem_read8(x + 0x1Eu);
		t10 = mem_read8(u + 4u);
		if ((uint8_t)(t9 + 0x80u) != t10)
		{
			sub_03978A(u);
			return;
		}
		t11 = mem_read8(u + 0x35u);
		a = DATA8(indexed_table_039FD1_ADDRESS + (int8_t)t11);
		mem_write8(u + 0x1Fu, a);
		mem_write8(x + 0x1Fu, a);
		sub_039881(u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write16(u + 0x1Cu, 0u);
		mem_write16(x + 0x1Cu, 0u);
		mem_write16(u + 0x32u, x);
		mem_write16(x + 0x32u, u);
		t12 = mem_read8(u + 4u);
		t13 = mem_read8(x + 4u);
		t14 = loaded_table_039EA9_ADDRESS + (uint8_t)(((((((uint32_t)t12 << 1) << 1) + t13) << 1) << 1) << 1);
		y_2 = t14 + 1u;
		b = DATA8(t14);
		mem_write8(u + 0x35u, b);
		mem_write8(x + 0x35u, b);
		mem_write8(u + 0x39u, 0xFFu);
		mem_write8(x + 0x39u, 0xFFu);
		mem_write8(u + 0x3Du, 0xFFu);
		mem_write8(x + 0x3Du, 0xFFu);
		t15 = mem_read16(y_2 + 3u);
		d = t15;
		carry = sub_078680(d);
		t16 = y_2;
		t17 = (uint32_t)mem_read8(t16) << 2;
		x = unk_4A40_ADDRESS + t17;
		t18 = t16 + 1u;
		y_2 = t18 + 1u;
		mem_write8(x + 0x36u, mem_read8(t18));
		t19 = mem_read8(u + 0x35u);
		mem_write8(x + 5u, t19 - 0x20u);
		mem_write8(x + 0x30u, 0x30u);
		stack = x;
		t20 = (uint32_t)mem_read8(y_2) << 2;
		x = unk_4A40_ADDRESS + t20;
		t21 = y_2 - 1u;
		y_2 = t21;
		mem_write8(x + 0x36u, mem_read8(t21) - 1u);
		mem_write8(x, 4u);
		mem_write8(x + 0x30u, 0x39u);
		d = (d & 0xFFu) | 0x300u;
		sub_039C29(y_2, u, d);
		t22 = mem_read16(x + 0xCu);
		x = stack;
		y_2 += 4u;
		t23 = mem_read16(x + 0xCu);
		if ((int16_t)t22 < (int16_t)t23)
			y_2++;
		t24 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t24 & 0xBFu) | mem_read8(y_2));
		t25 = mem_read16(u + 0x32u);
		x = t25;
		sub_039A6E(x, u);
		sub_03978A(u);
		return;
	}
	if ((int8_t)b >= 0x10)
	{
		sub_03978A(u);
		return;
	}
	t26 = (int8_t)((uint32_t)b << 1);
	switch ((int16_t)t26)
	{
	case 0:
	case 22:
	case 24:
	case 30:
	case -32:
	case -30:
	case -28:
	case -26:
	case -6:
	case -4:
	case -2:
		sub_03978A(u);
		return;
	case 2:
		sub_03945F(u);
		return;
	case 4:
		sub_03955F(u);
		return;
	case 6:
		sub_0395AD(u);
		return;
	case 8:
		sub_0395D9(u);
		return;
	case 10:
		sub_0395EC(y, u);
		return;
	case 12:
		sub_039528(u);
		return;
	case 14:
		sub_0394DC(u);
		return;
	case 16:
		sub_039454(u);
		return;
	case 18:
		sub_039523(u);
		return;
	case 20:
		sub_0394F0(u);
		return;
	case 26:
		sub_039335(u);
		return;
	case -24:
	case -22:
		sub_039360(u);
		return;
	case -20:
	case -18:
	case -16:
		sub_039384(u);
		return;
	case -14:
	case -12:
	case -10:
	case -8:
		sub_0393B6(u);
		return;
	}
}

void sub_039335(uint16_t u)
{
	uint8_t b = 0;
	uint16_t d = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)t1)
	{
		sub_03978A(u);
		return;
	}
	t3 = mem_read8(u + 0x44u);
	b = t3;
	if (t3 == 0u)
	{
		sub_03978A(u);
		return;
	}
	mem_write8(u + 5u, b);
	if (b == 0x97u)
	{
		d = 0x3F28u;
		sub_039C50(u, d);
	}
	mem_write16(u + 0x30u, 0x2A20u);
	mem_write16(u + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	sub_03962F(u);
}

void sub_039360(uint16_t u)
{
	uint16_t y = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0;
	uint16_t t2 = 0, t4 = 0, t8 = 0;

	t1 = mem_read8(u + VIDEO_002F);
	if ((t1 & 0x10u) != 0u)
	{
		t2 = mem_read16(u + 0x3Fu);
		if (t2 == 0u)
		{
			t3 = mem_read8(u + 0x39u);
			if ((int8_t)t3 >= 0)
			{
				t4 = mem_read16(u + 0x25u);
				y = t4;
				t5 = mem_read8(y + 2u);
				if (t5 == 2u)
				{
					sub_03978A(u);
					return;
				}
				stack = u;
				t6 = mem_read8(u + 0x34u);
				mem_write8(u + 0x34u, t6 & ~1u);
				t7 = mem_read8(u + 0x39u);
				if ((int8_t)t7 >= 0)
				{
					mem_write8(u, 0x80u);
					mem_write8(u + 0x30u, 0x1Du);
					mem_write8(u + 5u, 0xBEu);
				}
				mem_write8(y + 2u, 2u);
				mem_write8(y + 0x3Du, 1u);
				mem_write8(y, mem_read8(y) & 0xBFu);
				sub_039881(u);
				u = stack;
				t8 = mem_read16(u + 0x3Fu);
				y = t8;
				if (t8 != 0u)
				{
					t9 = mem_read8(u + 0x3Fu);
					if (t9 != 0u)
					{
						mem_write16(y + 0xFu, 0u);
						mem_write16(y + 0x14u, 0u);
						mem_write16(y + 0x19u, 0u);
						sub_03978A(u);
						return;
					}
				}
			}
		}
	}
	sub_03978A(u);
}

void sub_039384(uint16_t u)
{
	uint16_t y = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0;
	uint16_t t2 = 0, t4 = 0, t9 = 0;

	t1 = mem_read8(u + VIDEO_002F);
	if ((t1 & 0x10u) != 0u)
	{
		t2 = mem_read16(u + 0x3Fu);
		if (t2 == 0u)
		{
			t3 = mem_read8(u + 0x39u);
			if ((int8_t)t3 >= 0)
			{
				t4 = mem_read16(u + 0x25u);
				y = t4;
				t5 = mem_read8(y + 2u);
				if (t5 == 2u)
				{
					sub_03978A(u);
					return;
				}
				mem_write8(u + 0x9Fu, 0x14u);
				t6 = mem_read8(u + 0x1Eu);
				mem_write16(u + 0x3Fu, (uint8_t)(t6 + 0x10u));
				stack = u;
				t7 = mem_read8(u + 0x34u);
				mem_write8(u + 0x34u, t7 & ~1u);
				t8 = mem_read8(u + 0x39u);
				if ((int8_t)t8 >= 0)
				{
					mem_write8(u, 0x80u);
					mem_write8(u + 0x30u, 0x1Du);
					mem_write8(u + 5u, 0xBEu);
				}
				mem_write8(y + 2u, 2u);
				mem_write8(y + 0x3Du, 1u);
				mem_write8(y, mem_read8(y) & 0xBFu);
				sub_039881(u);
				u = stack;
				t9 = mem_read16(u + 0x3Fu);
				y = t9;
				if (t9 != 0u)
				{
					t10 = mem_read8(u + 0x3Fu);
					if (t10 != 0u)
					{
						mem_write16(y + 0xFu, 0u);
						mem_write16(y + 0x14u, 0u);
						mem_write16(y + 0x19u, 0u);
						sub_03978A(u);
						return;
					}
				}
			}
		}
	}
	sub_03978A(u);
}

void sub_0393B6(uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t stack_3 = 0;
	uint16_t stack = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t12 = 0;
	uint16_t t1 = 0, t5 = 0, t11 = 0;

	t1 = mem_read16(u + 0x25u);
	y = t1;
	t2 = mem_read8(y + 2u);
	if (t2 == 2u)
	{
		sub_03978A(u);
		return;
	}
	stack = u;
	t3 = mem_read8(u + 0x1Eu);
	stack_3 = t3;
	t4 = mem_read8(u + 0x39u);
	if ((int8_t)t4 < 0)
	{
		t5 = mem_read16(u + 0x32u);
		x = t5;
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		t6 = mem_read8(u + 0x1Bu);
		a = t6;
		t7 = mem_read8(x + 0x1Bu);
		zero = (uint8_t)(a - t7) == 0u;
		carry = a < t7;
		if (t7 <= a && ((carry | zero) == 0u || (int8_t)unk_4858 < 0))
			u = x;
	}
	d = 0x3F0Cu;
	sub_039C50(u, d);
	d = 0x10Cu;
	sub_039C29(y, u, d);
	t8 = mem_read8(u + 0x1Bu);
	b = t8 + DATA8(indexed_table_039EAD_ADDRESS + (int8_t)(stack_3 + 7u));
	if (b > 0x28u)
		b = 0x28u;
	mem_write8(u + 0x1Bu, b);
	t9 = mem_read8(u + 0x34u);
	mem_write8(u + 0x34u, t9 & ~1u);
	t10 = mem_read8(u + 0x39u);
	if ((int8_t)t10 >= 0)
	{
		mem_write8(u, 0x80u);
		mem_write8(u + 0x30u, 0x1Du);
		mem_write8(u + 5u, 0xBEu);
	}
	mem_write8(y + 2u, 2u);
	mem_write8(y + 0x3Du, 1u);
	mem_write8(y, mem_read8(y) & 0xBFu);
	sub_039881(u);
	u = stack;
	t11 = mem_read16(u + 0x3Fu);
	y = t11;
	if (t11 != 0u)
	{
		t12 = mem_read8(u + 0x3Fu);
		if (t12 != 0u)
		{
			mem_write16(y + 0xFu, 0u);
			mem_write16(y + 0x14u, 0u);
			mem_write16(y + 0x19u, 0u);
			sub_03978A(u);
			return;
		}
	}
	sub_03978A(u);
}

void sub_039454(uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;

	sub_039B9B(u);
	y = 0xF40u;
	d = 0xDBu;
	sub_03961B(y, u, d);
}

void sub_03945F(uint16_t u)
{
	uint8_t d = 0;
	uint16_t x = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0, t5 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	t1 = mem_read16(u + 0x16u);
	x = t1;
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)x)
	{
		sub_0394F0(u);
		return;
	}
	mem_write16(u + 0x19u, 0u);
	t3 = mem_read8(u + 0x1Bu);
	if (t3 == 0u)
	{
		sub_039528(u);
		return;
	}
	t4 = mem_read16(u + 0x25u);
	y = t4;
	t5 = mem_read8(u + 0x2Cu);
	mem_write8(u + 0x2Cu, t5 + 1u);
	stack = x;
	t6 = stack + 0x10u;
	t7 = mem_read16(y + 0x16u);
	if ((int16_t)t6 < (int16_t)t7)
	{
		t8 = mem_read16(y + 0x19u);
		if ((int16_t)t8 < 0)
		{
			t9 = mem_read16(u + 0x5Cu);
			mem_write16(u + 0x16u, t9);
			t10 = mem_read8(u + 0x2Cu);
			if ((int8_t)t10 < 3)
			{
				y = 0x1600u;
				d = 0xD5u;
				sub_039615(y, u, d);
				return;
			}
			mem_write8(u + 0x2Cu, 0u);
			sub_0394DC(u);
			return;
		}
	}
	t11 = mem_read8(y + 9u);
	t12 = mem_read8(u + 9u);
	if (((t11 ^ t12) & 0x40u) != 0u)
	{
		t13 = mem_read8(u + 0x2Cu);
		if ((int8_t)t13 < 3)
		{
			y = VIDEO_1E00;
			d = 0xD1u;
			sub_039615(y, u, d);
			return;
		}
		mem_write8(u + 0x2Cu, 0u);
		y = 0x1500u;
		d = 0xD4u;
		sub_039615(y, u, d);
		return;
	}
	t14 = mem_read8(u + 0x2Cu);
	if ((int8_t)t14 >= 3)
	{
		sub_039523(u);
		return;
	}
	t15 = mem_read8(u + 0xDu);
	if ((t15 & 2u) != 0u)
	{
		y = VIDEO_1E00;
		d = 0xD2u;
		sub_039615(y, u, d);
		return;
	}
	y = 0x1600u;
	d = 0xD5u;
	sub_039615(y, u, d);
}

void sub_0394DC(uint16_t u)
{
	uint8_t d_2 = 0;
	uint16_t d = 0, y = 0;

	d = 0x3F00u;
	sub_039C50(u, d);
	mem_write16(u + 0x19u, 0xFA00u);
	y = 0x1100u;
	d_2 = 0xD0u;
	sub_039615(y, u, d_2);
}

void sub_0394F0(uint16_t u)
{
	uint8_t b = 0, d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + 0x1Bu);
	if (t1 == 0u)
	{
		sub_039573(u);
		return;
	}
	mem_write16(u + 0x14u, 0u);
	sub_039B9B(u);
	t2 = mem_read16(u + 0x25u);
	t3 = mem_read8(t2 + 9u);
	mem_write16(u + 0x19u, 0x680u);
	y = 0x1C0u;
	b = 0x40u;
	if ((t3 & 0x40u) != 0u)
	{
		y = 0xFE40u;
		b = 0u;
	}
	mem_write16(u + 0xFu, y);
	mem_write8(u + 9u, b);
	y = 0x1800u;
	d = 0xD7u;
	sub_03961B(y, u, d);
}

void sub_039523(uint16_t u)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 0x1Bu);
	if (t1 != 0u)
	{
		y = 0x1408u;
		mem_write8(u + 0x2Cu, 0u);
		sub_039533(y, u);
		return;
	}
	sub_039528(u);
}

void sub_039528(uint16_t u)
{
	uint16_t y = 0;

	y = 0x1420u;
	sub_039533(y, u);
}

void sub_039533(uint16_t y, uint16_t u)
{
	uint8_t b = 0, d = 0;
	uint16_t x = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + 0x34u);
	mem_write8(u + 0x34u, t1 | 0x80u);
	t2 = mem_read16(u + 0x25u);
	t3 = mem_read8(t2 + 9u);
	x = 0x400u;
	b = 0u;
	if ((t3 & 0x40u) != 0u)
	{
		x = 0xFC00u;
		b = 0x40u;
	}
	mem_write16(u + 0xFu, x);
	mem_write8(u + 9u, b);
	mem_write8(u + 0x18u, 0u);
	mem_write16(u + 0x19u, 0u);
	d = 0xD3u;
	sub_039618(y, u, d);
}

void sub_03955F(uint16_t u)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x16u);
	t2 = mem_read16(u + 0x5Cu);
	if ((int16_t)t2 < (int16_t)t1)
	{
		sub_0394F0(u);
		return;
	}
	mem_write16(u + 0x19u, 0u);
	t3 = mem_read8(u + 0xDu);
	if ((t3 & 2u) != 0u)
	{
		sub_039528(u);
		return;
	}
	sub_039573(u);
}

void sub_039573(uint16_t u)
{
	uint8_t a = 0, b = 0, d = 0;
	uint16_t y = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	sub_039B9B(u);
	t1 = mem_read16(u + 0x25u);
	t2 = mem_read8(t1 + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		mem_write8(u + 9u, 0x40u);
		b = 0u;
		mem_write8(u + 0xFu, 0xFCu);
		a = 4u;
	}
	else
	{
		mem_write8(u + 9u, 0u);
		a = 4u;
		b = 0u;
		mem_write16(u + 0xFu, 0x400u);
	}
	mem_write16(u + 0x19u, ((uint32_t)a << 8) | b);
	mem_write16(u + 0x14u, 0u);
	y = 0x1900u;
	t3 = mem_read8(u + 0x34u);
	mem_write8(u + 0x34u, t3 | 0x80u);
	d = 0xD2u;
	sub_03961B(y, u, d);
}

void sub_0395AD(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t b = 0, d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(u + 0x4Bu);
	mem_write8(t1 + 0x58u, 1u);
	t2 = io_read16(VIDEO_1848);
	y = t2;
	t3 = mem_read8(y + 6u);
	if ((int8_t)t3 < 5)
	{
		t4 = mem_read8(y + 6u);
		mem_write8(y + 6u, t4 + 1u);
		d = 0x500u;
		carry = sub_039C2F(y, u, d);
	}
	b = 0xBFu;
	y = 0x1C01u;
	t5 = mem_read8(u + 0x1Bu);
	if (t5 != 4u)
	{
		d_2 = b;
		sub_03960A(y, u, d_2);
		return;
	}
	y = 0x1C3Cu;
	d_2 = b;
	sub_03960A(y, u, d_2);
}

void sub_0395D9(uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, y = 0;

	d = 0x5E00u;
	carry = sub_078680(d);
	d = 0x3F28u;
	sub_039C50(u, d);
	y = 0x1B3Cu;
	d_2 = 0xD9u;
	sub_039602(y, u, d_2);
}

void sub_0395EC(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, y_2 = 0;

	d = 0x5E00u;
	carry = sub_078680(d);
	d = 0u;
	sub_039C29(y, u, d);
	d = 0x3F04u;
	sub_039C50(u, d);
	y_2 = 0x1A3Cu;
	d_2 = 0xD8u;
	sub_039602(y_2, u, d_2);
}

void sub_039602(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write8(u, mem_read8(u) & 0x88u);
	sub_03960A(y, u, d);
}

void sub_03960A(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write16(u + 0x30u, y);
	mem_write8(u + 5u, d);
	sub_039881(u);
	sub_03962C(u);
}

void sub_039615(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write16(u + 0xFu, 0u);
	sub_039618(y, u, d);
}

void sub_039618(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write16(u + 0x14u, 0u);
	sub_03961B(y, u, d);
}

void sub_03961B(uint16_t y, uint16_t u, uint8_t d)
{
	mem_write8(u, mem_read8(u) & 0x88u);
	mem_write16(u + 0x30u, y);
	mem_write8(u + 5u, d);
	sub_039B80(u);
	sub_03962C(u);
}

void sub_03962C(uint16_t u)
{
	sub_039B89(u);
	sub_03962F(u);
}

void sub_03962F(uint16_t u)
{
	uint16_t x = 0;
	uint16_t t1 = 0;

	mem_write16(u + 0x1Cu, 0u);
	mem_write8(u + 0x38u, 1u);
	mem_write8(u + 0x41u, 0u);
	t1 = mem_read16(u + 0x3Fu);
	x = t1;
	if (t1 == 0u)
	{
		sub_03965F(u);
		return;
	}
	sub_03963F(x, u);
}

void sub_03963F(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 0x3Fu);
	if (t1 == 0u)
	{
		sub_03965F(u);
		return;
	}
	mem_write16(u + 0x3Fu, 0u);
	t2 = mem_read8(x + 0x1Du);
	if (t2 != 0xFEu)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 2u, 6u);
	}
	sub_039BAD(u);
	sub_03978A(u);
}

void sub_03965F(uint16_t u)
{
	uint32_t zero = 0, carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t u_2 = 0, x = 0;
	uint16_t stack = 0, stack_4 = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(u + 0x39u);
	mem_write8(u + 0x39u, 0u);
	if ((int8_t)t1 >= 0)
	{
		sub_03978A(u);
		return;
	}
	t2 = mem_read16(u + 0x32u);
	x = t2;
	sub_039A28(x, u);
	t3 = mem_read16(u + 0x30u);
	d = (uint8_t)t3;
	a = (uint8_t)(t3 >> 8);
	if (a != 0x1Cu)
	{
		mem_write16(x + 0x30u, ((uint32_t)a << 8) | (d & 0xFFu));
		t4 = mem_read8(u + 5u);
		mem_write8(x + 5u, t4);
	}
	else
	{
		mem_write8(x + 5u, 0x80u);
		mem_write16(x + 0x30u, d & 0xFFu);
	}
	mem_write8(x, mem_read8(u));
	sub_039A6E(x, u);
	stack = u;
	stack_4 = x;
	u_2 = x;
	sub_039A93(u_2, &zero, &carry);
	x = stack_4;
	u = stack;
	t5 = mem_read8(u + 0x1Bu);
	t6 = mem_read8(u + 0x52u);
	t7 = t5;
	a = t7 - t6;
	if (t7 == t6)
	{
		sub_03978A(u);
		return;
	}
	t8 = mem_read8(x + 0x1Bu);
	carry = (uint8_t)(a + t8) < a;
	a += t8;
	if (carry == 0u)
		a = 0u;
	mem_write8(x + 0x1Bu, a);
	sub_03978A(u);
}

void sub_03978A(uint16_t u)
{
	uint32_t zero = 0, negative = 0, overflow = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t6 = 0, t7 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t18 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t17 = 0, t19 = 0;

	t1 = mem_read8(u + 0x39u);
	if ((int8_t)t1 >= 0)
		y = u;
	else
	{
		t2 = mem_read16(u + 0x32u);
		y = t2;
	}
	t3 = mem_read16(u + 0x12u);
	t4 = mem_read16(u + 0x14u);
	t5 = t3;
	carry = (uint16_t)(t5 + t4) < t5;
	stack = (uint16_t)(t5 + t4) >> 8;
	t6 = mem_read8(u + 0x14u);
	t7 = mem_read8(u + 0x11u);
	if ((int16_t)(((uint32_t)(uint8_t)(((uint16_t)(int8_t)t6 >> 8) + t7 + carry) << 8) | stack) < 0x98)
	{
		mem_write16(u + 0x14u, 0u);
		mem_write16(y + 0x14u, 0u);
	}
	t8 = mem_read16(u + 0xDu);
	t9 = mem_read16(u + 0xFu);
	t10 = t8;
	carry = (uint16_t)(t10 + t9) < t10;
	stack = (uint16_t)(t10 + t9) >> 8;
	t11 = mem_read8(u + 0xFu);
	t12 = mem_read8(u + 0xCu);
	a = ((uint16_t)(int8_t)t11 >> 8) + t12 + carry;
	b = stack;
	t13 = mem_read8(u + 0x1Bu);
	if (t13 == 0u)
	{
		if ((int16_t)(((uint32_t)a << 8) | b) >= 0x5A)
		{
			x = 0x140u;
			t14 = mem_read8(u + 0x1Bu);
			if (t14 != 0u)
			{
				stack = a;
				t15 = unk_4867;
				a = stack;
				if (t15 == 4u)
					x = 0x150u;
			}
			else
				x += 0x26u;
			unk_48F8 = x;
			if ((int16_t)unk_48F8 < (int16_t)(((uint32_t)a << 8) | b))
				mem_write16(u + 0xFu, 0u);
		}
		else
			mem_write16(u + 0xFu, 0u);
	}
	else if ((int16_t)(((uint32_t)a << 8) | b) >= 0x70)
	{
		x = 0x140u;
		t14 = mem_read8(u + 0x1Bu);
		if (t14 != 0u)
		{
			stack = a;
			t15 = unk_4867;
			a = stack;
			if (t15 == 4u)
				x = 0x150u;
		}
		else
			x += 0x26u;
		unk_48F8 = x;
		if ((int16_t)unk_48F8 < (int16_t)(((uint32_t)a << 8) | b))
			mem_write16(u + 0xFu, 0u);
	}
	else
		mem_write16(u + 0xFu, 0u);
	x = u;
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		sub_039794(u, &d, &zero, &negative, &overflow);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		if ((negative ^ overflow) | zero)
		{
			mem_write16(u + 0x5Cu, ((uint32_t)a << 8) | b);
			t16 = mem_read8(u + 9u);
			mem_write8(u + 9u, (t16 & 0xCFu) | unk_48F2);
			t17 = mem_read16(u + 0xFu);
			mem_write16(y + 0xFu, t17);
			t18 = mem_read8(u + 0x1Bu);
			t19 = io_read16(VIDEO_1848);
			mem_write8(t19 + 2u, t18);
			return;
		}
	}
	x = u;
	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		sub_039794(u, &d, &zero, &negative, &overflow);
		a = (uint8_t)(d >> 8);
		b = (uint8_t)d;
		if ((negative ^ overflow) | zero)
		{
			mem_write16(u + 0x14u, 0u);
			mem_write16(y + 0x14u, 0u);
			mem_write16(u + 0x5Cu, ((uint32_t)a << 8) | b);
			t16 = mem_read8(u + 9u);
			mem_write8(u + 9u, (t16 & 0xCFu) | unk_48F2);
			t17 = mem_read16(u + 0xFu);
			mem_write16(y + 0xFu, t17);
			t18 = mem_read8(u + 0x1Bu);
			t19 = io_read16(VIDEO_1848);
			mem_write8(t19 + 2u, t18);
			return;
		}
	}
	mem_write16(u + 0xFu, 0u);
	x = u;
	sub_078647(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		mem_write16(u + 0x14u, 0u);
		mem_write16(y + 0x14u, 0u);
		t17 = mem_read16(u + 0xFu);
		mem_write16(y + 0xFu, t17);
		t18 = mem_read8(u + 0x1Bu);
		t19 = io_read16(VIDEO_1848);
		mem_write8(t19 + 2u, t18);
		return;
	}
	sub_039794(u, &d, &zero, &negative, &overflow);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if ((negative ^ overflow) | zero)
	{
		mem_write16(u + 0x5Cu, ((uint32_t)a << 8) | b);
		t16 = mem_read8(u + 9u);
		mem_write8(u + 9u, (t16 & 0xCFu) | unk_48F2);
		t17 = mem_read16(u + 0xFu);
		mem_write16(y + 0xFu, t17);
		t18 = mem_read8(u + 0x1Bu);
		t19 = io_read16(VIDEO_1848);
		mem_write8(t19 + 2u, t18);
		return;
	}
	mem_write16(u + 0x14u, 0u);
	mem_write16(y + 0x14u, 0u);
	t17 = mem_read16(u + 0xFu);
	mem_write16(y + 0xFu, t17);
	t18 = mem_read8(u + 0x1Bu);
	t19 = io_read16(VIDEO_1848);
	mem_write8(t19 + 2u, t18);
}

void sub_039794(uint16_t u, uint16_t *p_d, uint32_t *p_zero, uint32_t *p_negative, uint32_t *p_overflow)
{
	uint16_t d = (uint16_t)*p_d;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t overflow = *p_overflow;
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	a = (uint8_t)(d >> 8);
	unk_48F2 = a & 0x30u;
	t1 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	t2 = mem_read16(u + 0x16u);
	t3 = ((uint32_t)a << 8) | b;
	t4 = t3 - t2;
	negative = t4 >> 15;
	zero = t4 == 0u;
	overflow = (uint32_t)t3 - (int16_t)t2 != (uint32_t)(int16_t)(t3 - t2);
	d_2 = ((uint32_t)a << 8) | b;
	*p_d = d_2;
	*p_zero = zero;
	*p_negative = negative;
	*p_overflow = overflow;
}

void sub_039861(uint16_t u)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(u + 0x1Bu);
	t2 = io_read16(VIDEO_1848);
	mem_write8(t2 + 2u, t1);
}

void sub_03986D(uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0;

	x = u;
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	if (a == 0xFFu)
	{
		carry = 1u;
		d = ((uint32_t)(uint8_t)~a << 8) | b;
	}
	else
	{
		carry = 0u;
		d = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
	}
	*p_d = d;
	*p_carry = carry;
}

void sub_039881(uint16_t u)
{
	mem_write16(u + 0xFu, 0u);
	mem_write16(u + 0x14u, 0u);
	mem_write16(u + 0x19u, 0u);
}

uint16_t sub_03988B(uint16_t u, uint16_t d)
{
	uint8_t a = 0, d_2 = 0;
	uint16_t y = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = indexed_table_039F21_ADDRESS + (uint8_t)((((d >> 8) & 0xFu) << 1) << 1);
	y = t1 + 2u;
	t2 = DATA16(t1);
	d_2 = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if (t2 == 0u)
	{
		sub_0398A9(y, u);
		return y;
	}
	mem_write16(u + 0xFu, ((uint32_t)a << 8) | (d_2 & 0xFFu));
	stack = a & 0x40u;
	t3 = mem_read8(u + 9u);
	mem_write8(u + 9u, (t3 & 0xBFu) | stack);
	sub_0398A9(y, u);
	return y;
}

void sub_0398A9(uint16_t y, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t x = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	t1 = mem_read16(u + 0xCu);
	x = t1;
	t2 = mem_read8(u + 9u);
	if ((t2 & 0x40u) != 0u)
	{
		if ((int16_t)x < 0xC0)
		{
			x = 0x118u;
			if ((unk_4A40 == 0u || (int16_t)unk_4A4C < (int16_t)x) && (unk_4B00 == 0u || (int16_t)unk_4B0C < (int16_t)x) && (unk_4BC0 == 0u || (int16_t)unk_4BCC < (int16_t)x) && (unk_4C80 == 0u || (int16_t)unk_4C8C < (int16_t)x))
			{
				t3 = mem_read16(u + 0xFu);
				unk_48E4 = t3;
			}
		}
	}
	else if ((int16_t)x > 0x100)
	{
		x = 0x98u;
		if ((unk_4A40 == 0u || (int16_t)x < (int16_t)unk_4A4C) && (unk_4B00 == 0u || (int16_t)x < (int16_t)unk_4B0C) && (unk_4BC0 == 0u || (int16_t)x < (int16_t)unk_4BCC) && (unk_4C80 == 0u || (int16_t)x < (int16_t)unk_4C8C))
		{
			t3 = mem_read16(u + 0xFu);
			unk_48E4 = t3;
		}
	}
	t4 = mem_read16(u + 0x11u);
	x = t4;
	t5 = mem_read16(y);
	a = (uint8_t)(t5 >> 8);
	b = (uint8_t)t5;
	t6 = ((uint32_t)a << 8) | b;
	mem_write16(u + 0x14u, t6);
	if (t6 == 0u)
		return;
	if ((int16_t)(((uint32_t)a << 8) | b) < 0)
	{
		t7 = io_read16(VIDEO_1842);
		if ((int16_t)x < (int16_t)t7)
		{
			t8 = io_read16(VIDEO_1844);
			x = t8;
			if ((unk_4A40 == 0u || (int16_t)unk_4A51 < (int16_t)x) && (unk_4B00 == 0u || (int16_t)unk_4B11 < (int16_t)x) && (unk_4BC0 == 0u || (int16_t)unk_4BD1 < (int16_t)x) && (unk_4C80 == 0u || (int16_t)unk_4C91 < (int16_t)x))
			{
				t9 = mem_read16(u + 0x14u);
				t10 = t9 + unk_48E6;
				unk_48E6 = t10;
			}
		}
	}
	else
	{
		t11 = io_read16(VIDEO_1840);
		if ((int16_t)t11 < (int16_t)x)
		{
			t12 = io_read16(VIDEO_1846);
			x = t12;
			if ((unk_4A40 == 0u || (int16_t)x < (int16_t)unk_4A51) && (unk_4B00 == 0u || (int16_t)x < (int16_t)unk_4B11) && (unk_4BC0 == 0u || (int16_t)x < (int16_t)unk_4BD1) && (unk_4C80 == 0u || (int16_t)x < (int16_t)unk_4C91))
			{
				t9 = mem_read16(u + 0x14u);
				t10 = t9 + unk_48E6;
				unk_48E6 = t10;
				return;
			}
		}
	}
}

uint16_t sub_0399CA(uint16_t x, uint16_t y, uint16_t u)
{
	uint8_t b = 0, d = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(u + 4u);
	t2 = y + (int8_t)((uint32_t)t1 << 1);
	y_2 = t2 + 1u;
	b = mem_read8(t2);
	t3 = mem_read8(u + 9u);
	if ((t3 & 0x40u) != 0u)
		b = 0u - b;
	t4 = (int8_t)b;
	t5 = mem_read16(u + 0xCu);
	t6 = t4 + t5;
	mem_write16(x + 0xCu, t6);
	d = mem_read8(y_2);
	sub_0399E3(x, u, d);
	return y_2;
}

void sub_0399E3(uint16_t x, uint16_t u, uint8_t d)
{
	uint8_t t6 = 0, t7 = 0, t8 = 0, t11 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t9 = 0, t10 = 0;

	t1 = (int8_t)d;
	t2 = mem_read16(u + 0x16u);
	t3 = t1 + t2;
	mem_write16(x + 0x16u, t3);
	t4 = mem_read16(u + 0x11u);
	t5 = t4 - 2u;
	mem_write16(x + 0x11u, t5);
	t6 = mem_read8(u + 0xEu);
	mem_write8(x + 0xEu, t6);
	t7 = mem_read8(u + 0x13u);
	mem_write8(x + 0x13u, t7);
	t8 = mem_read8(u + 0x18u);
	mem_write8(x + 0x18u, t8);
	t9 = mem_read16(u + 0x14u);
	mem_write16(x + 0x14u, t9);
	t10 = mem_read16(u + 0x19u);
	mem_write16(x + 0x19u, t10);
	t11 = mem_read8(x + 6u);
	mem_write8(x + 6u, t11 | 0x80u);
}

void sub_039A1A(uint16_t x, uint16_t u)
{
	mem_write8(u + 0x30u, 0u);
	mem_write8(x + 0x30u, 0u);
	mem_write8(u + 5u, 0x80u);
	mem_write8(x + 5u, 0x80u);
	sub_039A28(x, u);
}

void sub_039A28(uint16_t x, uint16_t u)
{
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	mem_write8(u, mem_read8(u) | 0x80u);
	mem_write8(x, mem_read8(x) | 0x80u);
	mem_write16(u + 0x3Bu, 0u);
	mem_write16(x + 0x3Bu, 0u);
	mem_write16(u + 0x38u, 0x100u);
	mem_write16(x + 0x38u, 0x100u);
	mem_write8(u + 0x3Du, 0u);
	mem_write8(x + 0x3Du, 0u);
	mem_write8(u + 0x37u, 0u);
	mem_write8(x + 0x37u, 0u);
	t1 = mem_read16(u + 0x5Cu);
	mem_write16(x + 0x5Cu, t1);
	t2 = mem_read8(u + 4u);
	mem_write8(u + 0x5Bu, ((((uint32_t)t2 << 1) << 1) << 1) << 1);
	t3 = mem_read8(x + 4u);
	mem_write8(x + 0x5Bu, ((((uint32_t)t3 << 1) << 1) << 1) << 1);
}

void sub_039A6E(uint16_t x, uint16_t u)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read16(u + 0xFu);
	mem_write16(x + 0xFu, t1);
	t2 = mem_read16(u + 0x14u);
	mem_write16(x + 0x14u, t2);
	t3 = mem_read16(u + 0x19u);
	mem_write16(x + 0x19u, t3);
	t4 = mem_read16(u + 0xCu);
	mem_write16(x + 0xCu, t4);
	t5 = mem_read16(u + 0x11u);
	mem_write16(x + 0x11u, t5);
	t6 = mem_read16(u + 0x16u);
	mem_write16(x + 0x16u, t6);
}

void sub_039A93(uint16_t u, uint32_t *p_zero, uint32_t *p_carry)
{
	uint32_t zero = *p_zero;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, x = 0, y = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t10 = 0, t11 = 0;
	uint16_t t2 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	x = 0x70u;
	y = 0x140u;
	t1 = mem_read8(u + 0x1Bu);
	if (t1 == 0u)
	{
		t2 = mem_read16(u + 0x16u);
		if (t2 != 0u)
		{
			x -= 0x16u;
			y += 0x26u;
		}
	}
	unk_48F8 = x;
	unk_48FA = y;
	x = u;
	sub_078644(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a < 0)
	{
		mem_write16(u + 0xFu, 0u);
		mem_write16(u + 0x14u, 0u);
		t3 = mem_read8(u + 0x1Bu);
		if (t3 != 0u)
			a = 0xFFu;
		else
			a = 0u;
		carry = 1u;
		zero = (uint8_t)~a == 0u;
	}
	else
	{
		unk_48F0 = a & 0x30u;
		t4 = mem_read8(u + 9u);
		mem_write8(u + 9u, (t4 & 0xCFu) | unk_48F0);
		t5 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
		a = (uint8_t)(t5 >> 8);
		b = (uint8_t)t5;
		t6 = mem_read16(u + 0x16u);
		if ((int16_t)t6 < (int16_t)(((uint32_t)a << 8) | b))
		{
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			t3 = mem_read8(u + 0x1Bu);
			if (t3 != 0u)
				a = 0xFFu;
			else
				a = 0u;
			carry = 1u;
			zero = (uint8_t)~a == 0u;
		}
		else
		{
			stack = b;
			stack_2 = a;
			x = ((uint32_t)stack_2 << 8) | stack;
			t7 = mem_read16(u + 0xFu);
			t8 = mem_read16(u + 0xDu);
			t9 = t7;
			carry = (uint16_t)(t9 + t8) < t9;
			stack = (uint16_t)(t9 + t8) >> 8;
			t10 = mem_read8(u + 0xFu);
			t11 = mem_read8(u + 0xCu);
			a = ((uint16_t)(int8_t)t10 >> 8) + t11 + carry;
			b = stack;
			if ((int16_t)unk_48F8 <= (int16_t)(((uint32_t)a << 8) | b) && (int16_t)(((uint32_t)a << 8) | b) <= (int16_t)unk_48FA)
			{
				mem_write16(u + 0x5Cu, x);
				zero = 1u;
				carry = 0u;
			}
			else
			{
				mem_write16(u + 0xFu, 0u);
				mem_write16(u + 0x14u, 0u);
				t3 = mem_read8(u + 0x1Bu);
				if (t3 != 0u)
					a = 0xFFu;
				else
					a = 0u;
				carry = 1u;
				zero = (uint8_t)~a == 0u;
			}
		}
	}
	*p_zero = zero;
	*p_carry = carry;
}

void sub_039B0C(uint16_t u)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(u + 9u);
	mem_write8(u + 9u, t1 & 0x4Fu);
	mem_write8(u + 0x3Eu, 0x78u);
	mem_write8(u + 0x90u, 0xCu);
	mem_write8(u + 0x60u, 0x80u);
	t2 = mem_read8(u + 4u);
	mem_write8(u + 0x64u, t2);
	mem_write8(u + 0x65u, 0x87u);
	mem_write8(u + 0x69u, 0u);
	mem_write8(u, 0xC4u);
}

void sub_039B38(uint16_t u, uint32_t *p_zero, uint32_t *p_negative, uint32_t *p_overflow)
{
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t overflow = *p_overflow;
	uint32_t carry = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0;

	t1 = mem_read8(u + 0x19u);
	unk_48F2 = (uint16_t)(int8_t)t1 >> 8;
	t2 = mem_read16(u + 0x17u);
	t3 = mem_read16(u + 0x19u);
	t4 = t2;
	carry = (uint16_t)(t4 + t3) < t4;
	t5 = mem_read8(u + 0x16u);
	t6 = mem_read16(u + 0x5Cu);
	t7 = ((uint32_t)(uint8_t)(t5 + unk_48F2 + carry) << 8) | ((uint16_t)(t4 + t3) >> 8);
	t8 = t7 - t6;
	negative = t8 >> 15;
	zero = t8 == 0u;
	overflow = (uint32_t)(int16_t)t7 - (int16_t)t6 != (uint32_t)(int16_t)(t7 - t6);
	*p_zero = zero;
	*p_negative = negative;
	*p_overflow = overflow;
}

void sub_039B51(uint16_t u)
{
	mem_write8(u, (mem_read8(u) | 4u) ^ 0x80u);
}

uint16_t sub_039B5C(uint16_t u, uint8_t d)
{
	uint8_t b = 0;
	uint16_t y = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	b = (uint8_t)d;
	t1 = mem_read16(u + 0x3Fu);
	t2 = mem_read16(t1 + 0xCu);
	y = t2 - 0x18u;
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 <= (int16_t)y)
		b++;
	else
	{
		t4 = mem_read16(u + 0xCu);
		if ((int16_t)y <= (int16_t)t4)
		{
			t5 = mem_read8(u + 9u);
			mem_write8(u + 9u, t5 | 0x40u);
			b++;
			mem_write8(u + 5u, b);
			return y;
		}
	}
	mem_write8(u + 5u, b);
	return y;
}

void sub_039B80(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0;

	d = 0x3F24u;
	sub_039C50(u, d);
	sub_039BBA(u, &ignored16, &ignored16_2);
}

void sub_039B89(uint16_t u)
{
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	unk_487E = 2u;
	t1 = mem_read8(u + 4u);
	d = (uint8_t)(0x22u + t1);
	sub_078677(d, &ignored16, &u);
}

void sub_039B9B(uint16_t u)
{
	mem_write8(u, mem_read8(u) | 8u);
}

void sub_039BA4(uint16_t u)
{
	mem_write8(u, mem_read8(u) & ~8u);
}

uint16_t sub_039BAD(uint16_t u)
{
	uint16_t y = 0;

	mem_write16(u + 0x1Cu, 0u);
	mem_write8(u + 0x22u, 0u);
	y = 0xE06u;
	mem_write16(u + 0x1Fu, 0xE06u);
	return y;
}

void sub_039BBA(uint16_t u, uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;

	d = 0x600u;
	y = 0xEBFu;
	carry = sub_039C2F(y, u, d);
	if (carry == 0u)
	{
		t1 = mem_read8(u + 0x90u);
		if ((int8_t)((uint16_t)((uint32_t)t1 << 8) >> 8) <= 6)
		{
			t2 = mem_read16(u + 0x25u);
			x = t2;
			t3 = mem_read16(u + 0xCu);
			d = t3;
			t4 = mem_read16(x + 0xCu);
			if ((int16_t)t4 <= (int16_t)d)
				d -= 0x10u;
			else
				d += 0x10u;
			mem_write16(u + 0x6Cu, d);
			t5 = mem_read8(u + 0x24u);
			t6 = mem_read16(u + 0x11u);
			mem_write16(u + 0x71u, (int8_t)t5 + t6 - 0x40u);
			t7 = mem_read16(u + 0x16u);
			mem_write16(u + 0x76u, t7 + 0x40u);
		}
	}
	*p_x = x;
	*p_y = y;
}

uint16_t sub_039BF9(uint16_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint16_t stack = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(u + 0x2Au, 0u);
	stack = y;
	d = 0x600u;
	y_2 = 0xEBFu;
	carry = sub_039C2F(y_2, u, d);
	y_2 = stack;
	if (carry)
		return y_2;
	t1 = mem_read16(u + 0x11u);
	mem_write16(u + 0x71u, t1 - 0x20u);
	t2 = mem_read16(u + 0x16u);
	mem_write16(u + 0x76u, mem_read8(y_2) + t2 + 0x20u);
	t3 = mem_read16(u + 0x49u);
	y_2 = t3;
	t4 = mem_read16(y_2 + 0xCu);
	mem_write16(u + 0x6Cu, t4);
	return y_2;
}

void sub_039C29(uint16_t y, uint16_t u, uint16_t d)
{
	uint32_t carry = 0;
	uint16_t d_2 = 0;

	mem_write8(u + VIDEO_00A0, d >> 8);
	d_2 = (d & 0xFFu) | 0x200u;
	carry = sub_039C2F(y, u, d_2);
}

uint32_t sub_039C2F(uint16_t y, uint16_t u, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint8_t t1 = 0;

	a = (uint8_t)(d >> 8);
	t1 = mem_read8(u + 0x90u);
	if ((int8_t)a < (int8_t)t1)
	{
		carry = 1u;
		return carry;
	}
	mem_write8(u + 0x90u, a);
	mem_write16(u + 0x64u, y);
	mem_write8(u + 0x60u, 0x80u);
	mem_write8(u + 0x66u, 0u);
	mem_write16(u + 0x6Fu, 0u);
	mem_write16(u + 0x74u, 0u);
	carry = 0u;
	mem_write16(u + 0x79u, 0u);
	return carry;
}

void sub_039C50(uint16_t u, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 4u);
	d = (d & ~0xFFu) | (uint8_t)(d + t1);
	carry = sub_078680(d);
}

void unused_039C56(uint16_t u, uint16_t d)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 4u);
	d = (d & 0xFFu) | ((uint32_t)(uint8_t)((d >> 8) + t1) << 8);
	carry = sub_078680(d);
}
