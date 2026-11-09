/**
 *    Name:        unsorted/bank_1E.c
 *    Description: bank 1E's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

uint16_t sub_03C000(uint16_t x, uint16_t u)
{
	uint8_t d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = indexed_table_03DDBD_ADDRESS;
	d = 2u;
	sub_03C340(x, y, d);
	t1 = mem_read8(x + 0x2Eu);
	y = loaded_table_03DD70_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		return sub_03C359(x);
	case 2:
		return sub_03C3A2(x, y);
	case 4:
	case 38:
		return sub_03C404(x, u);
	case 6:
		return sub_03C444(x, u);
	case 8:
		return sub_03C4C1(x, u);
	case 10:
		return sub_03C3C1(x, y);
	case 12:
		return sub_03C3DF(x, y);
	case 14:
		return sub_03C677(x, u);
	case 16:
		return sub_03C69B(x, u);
	case 18:
		return sub_03C6AB(x, u);
	case 20:
		return sub_03C6D5(x, u);
	case 22:
		return sub_03C6F9(x, u);
	case 24:
		return sub_03C718(x, u);
	case 26:
		return sub_03C740(x, u);
	case 28:
		return sub_03C753(x, u);
	case 30:
		return sub_03C75C(x, y);
	case 32:
		return sub_03C76A(x, y);
	case 34:
		return sub_03C772(x, y);
	case 36:
		sub_03C789(x);
		return y;
	case 40:
		return sub_03C654(x, u);
	}
	unreachable();
}

void sub_03C003(uint16_t x, uint32_t y)
{
	uint8_t t1 = 0;

	if ((mem_read8(x) & 4u) == 0u)
	{
		t1 = mem_read8(x + 0x3Fu);
		mem_write8(x + 0x3Fu, t1 - 1u);
		if (t1 == 1u)
			mem_write8(x, 0u);
		return;
	}
	sub_03C179(x);
	mem_write16(x + 4u, 0x9288u);
	y = indexed_table_03DDCE_ADDRESS;
	sub_03C2E5(x, y);
	mem_write8(x + 0x24u, 0u);
	mem_write16(x + 0x1Cu, 0x80Au);
	mem_write8(x + 0x3Fu, 0x15u);
}

uint16_t sub_03C006(uint16_t x, uint32_t y, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0;
	uint16_t t9 = 0, t11 = 0, t12 = 0, t13 = 0;

	if ((mem_read8(x) & 4u) == 0u)
	{
		t1 = mem_read8(x + VIDEO_002F);
		a = t1;
		if (a == 4u)
		{
			t2 = mem_read8(x + VIDEO_002F);
			mem_write8(x + VIDEO_002F, t2 + 1u);
			t3 = io_read8(VIDEO_184A);
			if ((int8_t)t3 < 7)
			{
				t4 = io_read8(VIDEO_184A);
				io_write8(VIDEO_184A, t4 + 1u);
				y = child_object_03DDE6_ADDRESS;
				sub_07862F(x, y, &u, &carry);
			}
		}
		else if ((int8_t)a <= 4)
		{
			t5 = mem_read8(x + VIDEO_002F);
			mem_write8(x + VIDEO_002F, t5 + 1u);
		}
		t6 = mem_read8(x + 0x3Fu);
		mem_write8(x + 0x3Fu, t6 - 1u);
		if (t6 == 1u)
			mem_write8(x, 0u);
		return u;
	}
	a = 0x80u;
	t7 = io_read8(VIDEO_184A);
	b = t7;
	if (t7 != 0u && b != 3u && b != 6u)
	{
		mem_write8(x, a);
		t8 = io_read8(VIDEO_184A);
		t9 = football_player_line_pieces_ADDRESS + (int8_t)((uint32_t)t8 << 1);
		mem_write16(x + 4u, 0x9200u | LINE_PIECE(t9)->animation);
		b = LINE_PIECE(t9)->dx;
		t10 = mem_read8(x + 9u);
		if ((t10 & 0x40u) != 0u)
			b = 0u - b;
		t11 = (int8_t)b;
		t12 = mem_read16(x + 0xCu);
		t13 = t11 + t12;
		mem_write16(x + 0xCu, t13);
		mem_write8(x + 0x3Fu, 0x13u);
		return u;
	}
	y = indexed_table_03DDD2_ADDRESS;
	sub_03C2E5(x, y);
	mem_write8(x + 0x24u, 1u);
	mem_write16(x + 0x1Cu, 0xC05u);
	a = 0xC0u;
	mem_write8(x, a);
	t8 = io_read8(VIDEO_184A);
	t9 = football_player_line_pieces_ADDRESS + (int8_t)((uint32_t)t8 << 1);
	mem_write16(x + 4u, 0x9200u | LINE_PIECE(t9)->animation);
	b = LINE_PIECE(t9)->dx;
	t10 = mem_read8(x + 9u);
	if ((t10 & 0x40u) != 0u)
		b = 0u - b;
	t11 = (int8_t)b;
	t12 = mem_read16(x + 0xCu);
	t13 = t11 + t12;
	mem_write16(x + 0xCu, t13);
	mem_write8(x + 0x3Fu, 0x13u);
	return u;
}

void sub_03C009(uint16_t u, uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint8_t d = 0;
	uint16_t y = 0;
	uint8_t t1 = 0;

	y = indexed_table_03DE6B_ADDRESS;
	d = 3u;
	sub_03C340(x, y, d);
	t1 = mem_read8(x + 0x2Eu);
	y = loaded_table_03DDEC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		y = sub_03C8CD(x);
		break;
	case 2:
		y = sub_03C976(x, y);
		break;
	case 4:
		y = sub_03C990(x, y);
		break;
	case 6:
		sub_03C9A4(&x, &y);
		break;
	case 8:
		y = sub_03CA2B(x, y);
		break;
	case 10:
		y = sub_03CA55(x, u);
		break;
	case 12:
		y = sub_03CA79(x, u);
		break;
	case 14:
		y = sub_03CAA8(x);
		break;
	case 16:
		y = sub_03CC2C(x, u);
		break;
	case 18:
		y = sub_03CB96(x, u);
		break;
	case 20:
		y = sub_03CBEA(x);
		break;
	case 22:
	case 36:
		y = sub_03CC38(x);
		break;
	case 24:
		y = sub_03CC47(x, y);
		break;
	case 26:
		y = sub_03CD05(x, y);
		break;
	case 28:
		sub_03CD3A(x);
		break;
	case 30:
		y = sub_03CCE5(x, y);
		break;
	case 32:
		y = sub_03CC0A(x, u);
		break;
	case 34:
		y = sub_03CC1B(x, u);
		break;
	case 38:
		sub_03CD47(x);
		break;
	}
	*p_x = x;
	*p_y = y;
}

uint16_t sub_03C00C(uint16_t x, uint16_t y)
{
	uint8_t a = 0, d = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0, t3 = 0, t8 = 0, t9 = 0, t12 = 0;
	uint16_t t2 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t10 = 0, speed_x = 0, t11 = 0, t13 = 0;

	if (mem_read8(x) == 4u)
	{
		mem_write8(x, 0x80u);
		mem_write16(x + 4u, 0x1091u);
		return y;
	}
	t1 = mem_read8(x + 0x2Eu);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0x19u);
		d = (uint8_t)t2;
		a = (uint8_t)(t2 >> 8);
		t3 = mem_read8(x + 0x16u);
		if ((int8_t)t3 < 0)
		{
			mem_write16(x + 0x16u, 0u);
			t4 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
			t5 = (int16_t)t4 >> 1;
			d = (uint8_t)t5;
			a = (uint8_t)(t5 >> 8);
		}
		t6 = (((uint32_t)a << 8) | (d & 0xFFu)) - 0x60u;
		mem_write16(x + 0x19u, t6);
		t7 = mem_read16(x + 0x11u);
		if ((int16_t)t7 <= 0x76)
			mem_write8(x, 0u);
		return y;
	}
	t8 = io_read8(VIDEO_184A);
	a = t8;
	if (t8 == 0u)
		return y;
	if (a != 1u)
	{
		mem_write8(x + 0x2Eu, a);
		t9 = mem_read8(x + 0x2Du);
		t10 = bear_part_flights_ADDRESS + (int8_t)(((uint32_t)t9 << 1) << 1);
		speed_x = PART_FLIGHT(t10)->speed_x;
		mem_write16(x + 0xFu, speed_x);
		t11 = t10 + 2u;
		y = t11 + 1u;
		mem_write8(x + 0x14u, PART_FLIGHT(t11 - 0x2u)->speed_y);
		mem_write8(x + 0x19u, PART_FLIGHT(y - 0x3u)->speed_z);
		mem_write8(x, 0x88u);
		return y;
	}
	t12 = mem_read8(x + 0x2Du);
	t13 = mem_read16(x + 0x54u);
	y_2 = t13;
	if ((((uint8_t)unk_4815 + t12) & 4u) != 0u)
		y_2 += 2u;
	mem_write16(x + 0x16u, y_2);
	mem_write8(x + 6u, 0x80u);
	return y_2;
}

uint16_t sub_03C00F(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u_2 = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	if (mem_read8(x) == 4u)
	{
		mem_write16(x + 0x2Du, 0u);
		mem_write8(x, 0x80u);
		mem_write16(x + 4u, 0xAE80u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write8(x + 0x1Fu, 0x24u);
		mem_write8(x + 0x20u, 0x24u);
		mem_write8(x + 0x21u, 0x24u);
		mem_write8(x + 0x24u, 0x24u);
		mem_write16(x + 0x2Eu, 0x200u);
		t1 = (unk_4858 & 3u) * 0xC0u;
		t2 = t1 + unk_4A40_ADDRESS;
		mem_write16(x + 0x2Bu, t2);
		mem_write8(x + 0x28u, 0u);
		t3 = unk_48AC;
		mem_write16(x + 0x29u, t3);
	}
	t4 = mem_read8(x + 0x2Du);
	switch ((int8_t)(uint8_t)((uint32_t)t4 << 1))
	{
	case 0:
	case 2:
	case 4:
		sub_03D033(x);
		return u;
	case 6:
	case 8:
		return sub_03D073(x);
	case 10:
		return sub_03D0A0(x);
	case 12:
		sub_03D155(x);
		return u;
	case 14:
		sub_03D198(x);
		return u;
	case 16:
		sub_03D1C0(x, &ignored16, &u);
		return u;
	case 18:
		sub_03D1F0(x, 0u);
		return u;
	case 20:
		sub_03D240(x, &ignored16, &u);
		return u;
	case 22:
		sub_03D275(x, &ignored16, &u);
		return u;
	case 24:
		sub_03D2FE(x, &ignored16, &u);
		return u;
	case 26:
		sub_03D497(x, &ignored16, &u);
		return u;
	case 28:
		sub_03D3DE(x, &ignored16, &u);
		return u;
	case 30:
	case 44:
		sub_03D44A(x, &ignored16, &u);
		return u;
	case 32:
		sub_03D445(x, &ignored16, &u);
		return u;
	case 34:
		sub_03D612(x, &ignored16, &u_2);
		return u_2;
	case 36:
		sub_03D60F(x, &ignored16, &u_2);
		return u_2;
	case 38:
		sub_03D67C(x, &ignored16, &u);
		return u;
	case 40:
		sub_03D679(x, 0u);
		return u;
	case 42:
		sub_03D2BE(x, &ignored16, &u);
		return u;
	case 46:
		sub_03D6AF(x, &u_2, &carry);
		return u_2;
	case 48:
		sub_03D488(x, &ignored16, &u);
		return u;
	case 50:
		sub_03D49E(x, &ignored16, &u);
		return u;
	case 52:
		sub_03D4A7(x, &ignored16, &u);
		return u;
	case 54:
		sub_03D4DA(x, 0u);
		return u;
	case 56:
		sub_03D4E7(x, 0u);
		return u;
	case 58:
		sub_03D440(x, &ignored16, &u);
		return u;
	}
	unreachable();
}

void sub_03C012(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t7 = 0, t9 = 0, t17 = 0, t18 = 0;
	uint16_t t3 = 0, t5 = 0, t6 = 0, t8 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t19 = 0, t20 = 0;
	uint32_t unk_48F3_halfword = 0;

	if (mem_read8(x) != 4u)
	{
		t1 = mem_read8(x + 0x2Eu);
		if (t1 != 0u)
		{
			t2 = mem_read8(x + 6u);
			if ((t2 & 1u) != 0u)
				mem_write8(x, 0u);
		}
		else
		{
			t3 = mem_read16(x + 0x19u);
			a = (uint8_t)(t3 >> 8);
			b = (uint8_t)t3;
			t4 = mem_read8(x + 0x16u);
			if ((int8_t)t4 >= 0)
			{
				t5 = (((uint32_t)a << 8) | b) - 0x60u;
				mem_write16(x + 0x19u, t5);
				if ((unk_4815 & 1u) == 0u)
				{
					t6 = mem_read16(x + 0x40u);
					y = t6;
					b = 0xC8u;
					u = 0x401u;
					t7 = mem_read8(y + 0x1Bu);
					if (t7 == 0u)
					{
						b = 0x88u;
						u = 0u;
					}
					mem_write8(x, b);
					mem_write16(x + 0x1Cu, u);
				}
				else
				{
					mem_write8(x, 0x88u);
					t8 = mem_read16(x + 0x40u);
					t9 = mem_read8(t8 + 0x1Bu);
					if (t9 <= 0x48u)
					{
						t6 = mem_read16(x + 0x40u);
						y = t6;
						b = 0xC8u;
						u = 0x401u;
						t7 = mem_read8(y + 0x1Bu);
						if (t7 == 0u)
						{
							b = 0x88u;
							u = 0u;
						}
						mem_write8(x, b);
						mem_write16(x + 0x1Cu, u);
					}
					else
					{
						y = 0x111u;
						mem_write16(x + 0x1Cu, 0x111u);
						sub_078674(x);
					}
				}
			}
			else
			{
				if ((int16_t)(((uint32_t)a << 8) | b) < -0x110)
				{
					stack = a;
					stack_10002 = b;
					d = 0x6500u;
					carry = sub_078680(d);
					a = stack;
					b = stack_10002;
					y = 0xFE80u;
					mem_write16(x + 0x14u, 0xFE80u);
				}
				mem_write16(x + 0x16u, 0u);
				t10 = 0u - (((uint32_t)a << 8) | b);
				a = (uint8_t)(t10 >> 8);
				b = (uint8_t)t10;
				unk_48F3_halfword = ((uint32_t)a << 8) | b;
				unk_48F3 = (uint8_t)(unk_48F3_halfword >> 8u);
				unk_48F4 = (uint8_t)unk_48F3_halfword;
				t11 = (((uint32_t)a << 8) | b) + (((uint32_t)unk_48F3 << 8u) | unk_48F4);
				t12 = t11 + (((uint32_t)unk_48F3 << 8u) | unk_48F4);
				t13 = (int16_t)t12 >> 2;
				stack = t13 >> 8;
				stack_10002 = t13;
				t14 = 0x98u + unk_48B2;
				t15 = mem_read16(x + 0x11u);
				t16 = t14;
				a = stack;
				b = stack_10002;
				if ((int16_t)t15 <= (int16_t)t16)
				{
					mem_write16(x + 0x19u, 0u);
					mem_write16(x + 0x14u, 0u);
					mem_write16(x + 4u, 0x580u);
					t17 = mem_read8(x + 0x2Eu);
					mem_write8(x + 0x2Eu, t17 + 1u);
				}
				else
				{
					t5 = (((uint32_t)a << 8) | b) - 0x60u;
					mem_write16(x + 0x19u, t5);
					if ((unk_4815 & 1u) == 0u)
					{
						t6 = mem_read16(x + 0x40u);
						y = t6;
						b = 0xC8u;
						u = 0x401u;
						t7 = mem_read8(y + 0x1Bu);
						if (t7 == 0u)
						{
							b = 0x88u;
							u = 0u;
						}
						mem_write8(x, b);
						mem_write16(x + 0x1Cu, u);
					}
					else
					{
						mem_write8(x, 0x88u);
						t8 = mem_read16(x + 0x40u);
						t9 = mem_read8(t8 + 0x1Bu);
						if (t9 <= 0x48u)
						{
							t6 = mem_read16(x + 0x40u);
							y = t6;
							b = 0xC8u;
							u = 0x401u;
							t7 = mem_read8(y + 0x1Bu);
							if (t7 == 0u)
							{
								b = 0x88u;
								u = 0u;
							}
							mem_write8(x, b);
							mem_write16(x + 0x1Cu, u);
						}
						else
						{
							y = 0x111u;
							mem_write16(x + 0x1Cu, 0x111u);
							sub_078674(x);
						}
					}
				}
			}
		}
	}
	else
	{
		mem_write8(x, 0xC8u);
		mem_write8(x + 0x5Bu, 0x40u);
		t18 = mem_read8(x + 0x30u);
		if (t18 != 0u)
		{
			mem_write16(x + 4u, 0xAF83u);
			a = 0x10u;
			b = 4u;
		}
		else
		{
			mem_write16(x + 4u, 0xAF83u);
			a = 0x10u;
			b = 4u;
		}
		mem_write16(x + 0x1Fu, ((uint32_t)a << 8) | b);
		mem_write8(x + 0x21u, a);
		mem_write8(x + 0x24u, a);
		t19 = (uint8_t)((((unk_4858 & 0x1Fu) << 1) << 1) << 1) + 0x60u;
		mem_write16(x + 0xCu, t19);
		t20 = 0xF0u + unk_48B2;
		mem_write16(x + 0x11u, t20);
		mem_write16(x + 0x16u, 0x80u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_03C015(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, y_2 = 0;
	uint8_t t2 = 0, t12 = 0, t13 = 0, t14 = 0, t17 = 0, t18 = 0, t23 = 0;
	uint16_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t15 = 0, t16 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t24 = 0, t25 = 0;

	t1 = mem_read16(x + 0xCu);
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)a << 8) | b) > 0x1A0u || (int16_t)(((uint32_t)a << 8) | b) < 0x20)
	{
		mem_write8(x, 0u);
		return;
	}
	t2 = mem_read8(x + 4u);
	if (t2 != 0u)
	{
		t3 = mem_read16(x + 0x36u);
		t4 = mem_read16(x + 0xFu);
		t5 = t3 + t4;
		mem_write16(x + 0xFu, t5);
		t6 = mem_read16(x + 0x38u);
		t7 = mem_read16(x + 0x14u);
		t8 = t6 + t7;
		mem_write16(x + 0x14u, t8);
		t9 = mem_read16(x + 0x3Au);
		t10 = mem_read16(x + 0x19u);
		t11 = t9 + t10;
		mem_write16(x + 0x19u, t11);
		t12 = mem_read8(x + 0x3Du);
		a = t12;
		if (t12 != 0u)
		{
			mem_write8(x, a | mem_read8(x));
			t13 = mem_read8(x + 0x3Eu);
			t14 = mem_read8(x + 0xAu);
			a = t13 + t14;
			mem_write8(x + 0xAu, a);
			mem_write8(x + 0xBu, a);
		}
		sub_07863B(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		b = 0u;
		if ((int8_t)a >= 0)
			b = (((a & 0xFu) << 1) << 1) << 1;
		t15 = b;
		mem_write16(x + 0x5Cu, t15);
		t16 = mem_read16(x + 0x42u);
		a = (uint8_t)(t16 >> 8);
		b = (uint8_t)t16;
		if (t16 == 0u)
		{
			t17 = mem_read8(x + VIDEO_003C);
			b = t17;
			if ((int8_t)t17 < 0)
			{
				t18 = mem_read8(x + 0x34u);
				mem_write8(x + 0x34u, t18 - 1u);
				if (t18 != 1u)
					return;
			}
			else
			{
				t19 = mem_read16(x + 0x19u);
				u_2 = t19;
				if ((int16_t)u_2 > 0)
				{
					*p_u = u_2;
					return;
				}
				t20 = (int8_t)b;
				a = (uint8_t)(t20 >> 8);
				b = (uint8_t)t20;
				t21 = mem_read16(x + 0x16u);
				if ((int16_t)(((uint32_t)a << 8) | b) < (int16_t)t21)
				{
					*p_u = u_2;
					return;
				}
				mem_write16(x + 0x16u, ((uint32_t)a << 8) | b);
				mem_write8(x + VIDEO_003C, 0xFFu);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
				mem_write16(x + 0x19u, 0u);
				mem_write16(x + 0x36u, 0u);
				mem_write16(x + 0x38u, 0u);
				mem_write16(x + 0x3Au, 0u);
			}
		}
		else
		{
			t22 = mem_read16(x + 0xCu);
			if ((int16_t)(((uint32_t)a << 8) | b) < (int16_t)t22)
				return;
			mem_write16(x + 0x42u, 0u);
		}
	}
	else
	{
		t23 = mem_read8(x + 0x30u);
		mem_write16(x + 0x32u, scripted_object_scripts[(int8_t)((uint8_t)((uint32_t)t23 << 1)) / 2]);
		mem_write8(x, 0x80u);
		mem_write8(x + VIDEO_003C, 0xFFu);
	}
	t24 = mem_read16(x + 0x32u);
	t25 = t24;
	y_2 = t25 + 1u;
	u_2 = loaded_table_03DFAA_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t25) << 1))
	{
	case 0:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC23(x, p_y, p_u);
		return;
	case 2:
		y_2 = sub_03DC2B(x, y_2);
		*p_y = y_2;
		*p_u = u_2;
		return;
	case 4:
		sub_03DC34(x);
		*p_y = y_2;
		*p_u = u_2;
		return;
	case 6:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC38(x, p_y, p_u);
		return;
	case 8:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC40(x, p_y, p_u);
		return;
	case 10:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC48(x, p_y, p_u);
		return;
	case 12:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC5D(x, p_y, p_u);
		return;
	case 14:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC6F(x, p_y, p_u);
		return;
	case 16:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC81(x, p_y, p_u);
		return;
	case 18:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC8C(x, p_y, p_u);
		return;
	case 20:
		y_2 = sub_03DC94(x, y_2);
		*p_y = y_2;
		*p_u = u_2;
		return;
	case 22:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DC9D(x, p_y, p_u);
		return;
	case 24:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DCAE(x, p_y, p_u);
		return;
	case 26:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DCC1(x, p_y, p_u);
		return;
	case 28:
		*p_y = y_2;
		*p_u = u_2;
		sub_03DCC9(x, p_y, p_u);
		return;
	case 30:
		y_2 = sub_03DCDE(x, y_2);
		*p_y = y_2;
		*p_u = u_2;
		return;
	}
}

uint16_t sub_03C018(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	mem_write16(x + 0x1Cu, 0u);
	t1 = mem_read8(x + 0x2Eu);
	y = loaded_table_03DEDC_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_03D1C0(x, &y, &ignored16);
		return y;
	case 2:
		return sub_03D1F0(x, y);
	case 4:
		sub_03D240(x, &y, &ignored16);
		return y;
	case 6:
		sub_03D275(x, &y, &ignored16);
		return y;
	case 8:
		sub_03D2FE(x, &y, &ignored16);
		return y;
	case 10:
		sub_03D497(x, &y, &ignored16);
		return y;
	case 12:
		sub_03D3DE(x, &y, &ignored16);
		return y;
	case 14:
	case 28:
		sub_03D44A(x, &y, &ignored16);
		return y;
	case 16:
		sub_03D445(x, &y, &ignored16);
		return y;
	case 18:
		sub_03D612(x, &y, &ignored16);
		return y;
	case 20:
		sub_03D60F(x, &y, &ignored16);
		return y;
	case 22:
		sub_03D67C(x, &y, &ignored16);
		return y;
	case 24:
		return sub_03D679(x, y);
	case 26:
		sub_03D2BE(x, &y, &ignored16);
		return y;
	case 30:
		sub_03D6AF(x, &ignored16, &carry);
		return y;
	case 32:
		sub_03D488(x, &y, &ignored16);
		return y;
	case 34:
		sub_03D49E(x, &y, &ignored16);
		return y;
	case 36:
		sub_03D4A7(x, &y, &ignored16);
		return y;
	case 38:
		return sub_03D4DA(x, y);
	case 40:
		return sub_03D4E7(x, y);
	case 42:
		sub_03D440(x, &y, &ignored16);
		return y;
	case -16:
	case -14:
	case -12:
		sub_03D033(x);
		return y;
	case -10:
	case -8:
		sub_03D073(x);
		return y;
	case -6:
		sub_03D0A0(x);
		return y;
	case -4:
		sub_03D155(x);
		return y;
	case -2:
		sub_03D198(x);
		return y;
	}
	unreachable();
}

uint16_t sub_03C01B(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if ((int16_t)t1 < 0x40)
	{
		mem_write8(x, 0u);
		return y;
	}
	t2 = mem_read8(x + 0x2Eu);
	y_2 = bank_1e_states_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)t2 << 1))
	{
	case 0:
		sub_03D708(x);
		return y_2;
	case 2:
		return sub_03D72C(x, y_2);
	case 4:
	case 28:
		return sub_03D748(x, y_2);
	case 6:
		return sub_03D781(x, y_2);
	case 8:
	case 10:
		return sub_03D7D3(x);
	case 12:
		return sub_03D7E9(x);
	case 14:
		return sub_03D81C(x);
	case 16:
		return sub_03D83F(x);
	case 18:
		return sub_03D79B(x);
	case 20:
		return sub_03D7CA(x);
	case 22:
		return sub_03D899(x, y_2);
	case 24:
		return sub_03D884(x, y_2);
	case 26:
		sub_03D88C(x);
		return y_2;
	}
	unreachable();
}

void sub_03C01E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	if (mem_read8(x) == 4u)
	{
		mem_write8(x, 0x80u);
		mem_write16(x + 4u, 0x9091u);
		d = 0x6C00u;
		carry = sub_078680(d);
		return;
	}
	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
		mem_write8(x, 0u);
}

uint32_t sub_03C021(void)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = unk_4850;
	b = t1 >> 1;
	if ((t1 & 1u) == 0u || (int8_t)unk_4A42 >= 0)
	{
		t2 = b;
		b = t2 >> 1;
		if ((t2 & 1u) == 0u || (int8_t)unk_4B02 >= 0)
		{
			t3 = b;
			b = t3 >> 1;
			if (((t3 & 1u) == 0u || (int8_t)unk_4BC2 >= 0) && ((b & 1u) == 0u || (int8_t)unk_4C82 >= 0))
			{
				carry = 0u;
				return carry;
			}
		}
	}
	carry = 1u;
	return carry;
}

void sub_03C04C(uint16_t x, uint16_t y, uint16_t d)
{
	mem_write8(x + 5u, d >> 8);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x2Eu, y);
}

void sub_03C066(uint16_t x)
{
	mem_write8(x, mem_read8(x) | 8u);
}

void sub_03C06F(uint16_t x)
{
	mem_write8(x, mem_read8(x) & ~8u);
}

void sub_03C078(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0;
	uint16_t d = 0;
	uint16_t stack = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	mem_write16(x + 0x19u, u);
	sub_078644(x, &d, &negative);
	if (d >> 8 == 0u)
	{
		t1 = mem_read16(x + 0xCu);
		d = t1;
	}
	else
	{
		t2 = mem_read16(x + 0xCu);
		d = t2;
		if ((int16_t)d > 0xE0)
		{
			if ((int16_t)d > 0xE0)
			{
				stack = y;
				stack = 0u - stack;
				y = stack;
				mem_write16(x + 0xFu, y);
				sub_03C066(x);
				*p_y = y;
				*p_u = u;
				return;
			}
			t1 = mem_read16(x + 0xCu);
			d = t1;
		}
	}
	if ((int16_t)d < 0x78)
	{
		if ((int16_t)y >= 0)
		{
			mem_write16(x + 0xFu, y);
			sub_03C066(x);
			*p_y = y;
			*p_u = u;
			return;
		}
		if ((int16_t)y < 0)
		{
			stack = y;
			stack = 0u - stack;
			y = stack;
			mem_write16(x + 0xFu, y);
			sub_03C066(x);
			*p_y = y;
			*p_u = u;
			return;
		}
	}
	if ((int16_t)d <= 0x138)
	{
		t3 = mem_read16(x + 0x25u);
		u = t3;
		t4 = mem_read8(u + 9u);
		if ((t4 & 0x40u) == 0u)
		{
			mem_write16(x + 0xFu, y);
			sub_03C066(x);
			*p_y = y;
			*p_u = u;
			return;
		}
		stack = y;
		stack = 0u - stack;
		y = stack;
		mem_write16(x + 0xFu, y);
		sub_03C066(x);
		*p_y = y;
		*p_u = u;
		return;
	}
	if ((int16_t)y >= 0)
	{
		stack = y;
		stack = 0u - stack;
		y = stack;
		mem_write16(x + 0xFu, y);
		sub_03C066(x);
		*p_y = y;
		*p_u = u;
		return;
	}
	if ((int16_t)y < 0)
	{
		mem_write16(x + 0xFu, y);
		sub_03C066(x);
		*p_y = y;
		*p_u = u;
		return;
	}
	t3 = mem_read16(x + 0x25u);
	u = t3;
	t4 = mem_read8(u + 9u);
	if ((t4 & 0x40u) != 0u)
	{
		stack = y;
		stack = 0u - stack;
		y = stack;
	}
	mem_write16(x + 0xFu, y);
	sub_03C066(x);
	*p_y = y;
	*p_u = u;
}

void unused_03C0C0(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x1Eu);
	a = t1;
	if ((int8_t)a < 0x10)
		return;
	if (a == 0xFFu)
	{
		t2 = mem_read16(x + 0x25u);
		u = t2;
		t3 = mem_read8(u + 4u);
		if (t3 == 5u)
		{
			mem_write8(u + 0x42u, 1u);
			return;
		}
	}
}

uint16_t sub_03C0E0(uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(u + 9u);
	a = t1;
	b = 0x18u;
	if ((a & 0x40u) != 0u)
		b = 0u - b;
	d = ((uint32_t)a << 8) | b;
	return d;
}

void sub_03C0EB(uint16_t x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0, t6 = 0;

	t1 = mem_read16(x + 0xDu);
	d = t1;
	t2 = mem_read16(x + 0xFu);
	carry = (uint16_t)(d + t2) < d;
	stack = (uint16_t)(d + t2) >> 8;
	t3 = mem_read8(x + 0xFu);
	t4 = mem_read8(x + 0xCu);
	d = ((uint32_t)(uint8_t)(((uint16_t)(int8_t)t3 >> 8) + t4 + carry) << 8) | stack;
	if ((int16_t)d >= 0x70)
	{
		if ((int16_t)d <= 0x140)
			sub_03C114(x, &y, &carry);
		else
		{
			t5 = mem_read16(x + 0xFu);
			if ((int16_t)t5 < 0)
				sub_03C114(x, &y, &carry);
			else
				sub_03C153(x, &y, &carry);
		}
	}
	else
	{
		t6 = mem_read16(x + 0xFu);
		if ((int16_t)t6 >= 0)
			sub_03C114(x, &y, &carry);
		else
			sub_03C153(x, &y, &carry);
	}
	*p_y = y;
	*p_carry = carry;
}

void sub_03C114(uint16_t x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint32_t negative = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
	{
		unk_48F0 = a & 0x30u;
		t1 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
		t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
		t3 = mem_read16(x + 0x16u);
		if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
		{
			mem_write16(x + 0x14u, 0u);
			sub_03C153(x, &y, &carry);
		}
		else
		{
			mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
			d = ((uint32_t)a << 8) | b;
			sub_03C159(x, d, &y, &carry);
		}
	}
	else
	{
		sub_078644(x, &d, &negative);
		a = (uint8_t)(d >> 8);
		if ((int8_t)a >= 0)
		{
			mem_write16(x + 0x14u, 0u);
			unk_48F0 = a & 0x30u;
			t1 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
			t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
			a = (uint8_t)(t2 >> 8);
			b = (uint8_t)t2;
			t3 = mem_read16(x + 0x16u);
			if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
			{
				mem_write16(x + 0x14u, 0u);
				sub_03C153(x, &y, &carry);
			}
			else
			{
				mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
				d = ((uint32_t)a << 8) | b;
				sub_03C159(x, d, &y, &carry);
			}
		}
		else
		{
			mem_write16(x + 0xFu, 0u);
			sub_078647(x, &d, &negative);
			a = (uint8_t)(d >> 8);
			if ((int8_t)a >= 0)
			{
				unk_48F0 = a & 0x30u;
				t1 = mem_read8(x + 9u);
				mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
				t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
				a = (uint8_t)(t2 >> 8);
				b = (uint8_t)t2;
				t3 = mem_read16(x + 0x16u);
				if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
				{
					mem_write16(x + 0x14u, 0u);
					sub_03C153(x, &y, &carry);
				}
				else
				{
					mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
					d = ((uint32_t)a << 8) | b;
					sub_03C159(x, d, &y, &carry);
				}
			}
			else if ((int8_t)a < 0)
			{
				mem_write16(x + 0x14u, 0u);
				sub_03C153(x, &y, &carry);
			}
			else
			{
				mem_write16(x + 0x14u, 0u);
				unk_48F0 = a & 0x30u;
				t1 = mem_read8(x + 9u);
				mem_write8(x + 9u, (t1 & 0xCFu) | unk_48F0);
				t2 = (uint8_t)((((a & 0xFu) << 1) << 1) << 1);
				a = (uint8_t)(t2 >> 8);
				b = (uint8_t)t2;
				t3 = mem_read16(x + 0x16u);
				if ((int16_t)t3 < (int16_t)(((uint32_t)a << 8) | b))
				{
					mem_write16(x + 0x14u, 0u);
					sub_03C153(x, &y, &carry);
				}
				else
				{
					mem_write16(x + 0x5Cu, ((uint32_t)a << 8) | b);
					d = ((uint32_t)a << 8) | b;
					sub_03C159(x, d, &y, &carry);
				}
			}
		}
	}
	*p_y = y;
	*p_carry = carry;
}

void sub_03C153(uint16_t x, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t d = 0;
	uint16_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	t1 = mem_read16(x + 0x5Cu);
	d = t1;
	*p_y = y;
	sub_03C159(x, d, p_y, &carry);
	*p_carry = carry;
}

void sub_03C159(uint16_t x, uint16_t d, uint16_t *p_y, uint32_t *p_carry)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = *p_carry;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read16(x + 0x16u);
	if ((int16_t)t1 <= (int16_t)d)
	{
		mem_write16(x + 0x16u, d);
		t2 = mem_read16(x + 0x19u);
		y = t2;
		if (t2 != 0u)
		{
			mem_write16(x + 0x19u, 0u);
			sub_03C06F(x);
		}
		carry = 1u;
	}
	else
	{
		t3 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, t3 - 0x60u);
		carry = 0u;
	}
	*p_y = y;
	*p_carry = carry;
}

void sub_03C179(uint16_t x)
{
	mem_write8(x, 0xC0u);
}

uint16_t sub_03C17F(void)
{
	uint32_t zero = 0;
	uint16_t u = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = (unk_4858 & 3u) * 0xC0u;
	t2 = t1 + unk_4A40_ADDRESS;
	stack = t2 >> 8;
	stack_10002 = t2;
	u = ((uint32_t)stack << 8) | stack_10002;
	sub_03C1A1(&u, &zero);
	if (zero == 0u)
		return u;
	sub_03C1A1(&u, &zero);
	if (zero == 0u)
		return u;
	sub_03C1A1(&u, &zero);
	if (zero)
		sub_03C1A1(&u, &zero);
	return u;
}

void sub_03C1A1(uint16_t *p_u, uint32_t *p_zero)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = *p_zero;

	u += 0xC0u;
	if (u == unk_4D40_ADDRESS)
		u = unk_4A40_ADDRESS;
	zero = mem_read8(u) == 0u;
	*p_u = u;
	*p_zero = zero;
}

void sub_03C1B1(uint16_t x, uint16_t u, uint16_t d)
{
	uint32_t overflow = 0;
	uint8_t b = 0;
	uint8_t t1 = 0, t2 = 0;

	d = sub_078671(x, u, d);
	b = (uint8_t)d;
	t1 = unk_48F0;
	t2 = ((d & ~0xFFu) | b) >> 8;
	overflow = (uint32_t)(int8_t)t2 - (int8_t)t1 != (uint32_t)(int8_t)(t2 - t1);
	if ((int8_t)t2 < (int8_t)t1)
	{
		if (overflow == 0u)
			b = 0u - b;
	}
	else if (overflow)
	{
		b = 0u - b;
		unk_48F0 += b;
		return;
	}
	unk_48F0 += b;
}

uint16_t sub_03C1C7(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x25u);
	u = t1;
	t2 = mem_read8(u + 0x5Bu);
	mem_write8(x + 0x27u, t2 & ~0xFu);
	return u;
}

void sub_03C1D3(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x27u);
	mem_write8(x + 0x27u, t1 | 0x81u);
}

void sub_03C1DC(uint16_t x, uint16_t *p_u, uint16_t *p_d, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t d = 0, u = 0;

	u = unk_4A40_ADDRESS;
	d = unk_4850;
	sub_03C1FE(x, u, &d, &carry);
	if (carry == 0u)
	{
		u = unk_4B00_ADDRESS;
		sub_03C1FE(x, u, &d, &carry);
		if (carry == 0u)
		{
			u = unk_4BC0_ADDRESS;
			sub_03C1FE(x, u, &d, &carry);
			if (carry == 0u)
			{
				u = unk_4C80_ADDRESS;
				sub_03C1FE(x, u, &d, &carry);
			}
		}
	}
	*p_u = u;
	*p_d = d;
	*p_carry = carry;
}

void sub_03C1FE(uint16_t x, uint16_t u, uint16_t *p_d, uint32_t *p_carry)
{
	uint8_t d = (uint8_t)*p_d;
	uint32_t carry = *p_carry;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = d;
	d_2 = t1 >> 1;
	if ((t1 & 1u) == 0u)
	{
		carry = 0u;
		d_2 &= 0xFFu;
	}
	else
	{
		stack = (uint8_t)d_2;
		t2 = mem_read16(x + 0xCu);
		t3 = mem_read16(u + 0xCu);
		d_2 = t2 - t3;
		t4 = d_2 >> 15 ? 0u - d_2 : d_2;
		d_2 = stack;
		if ((int16_t)unk_48F8 <= (int16_t)t4)
		{
			carry = 0u;
			d_2 &= 0xFFu;
		}
		else
		{
			stack = (uint8_t)d_2;
			t5 = mem_read16(x + 0x11u);
			t6 = mem_read16(u + 0x11u);
			d_2 = t5 - t6;
			d_2 = (uint16_t)(d_2 >> 15 ? 0u - d_2 : d_2);
			t7 = d_2;
			d_2 = (d_2 & ~0xFFu) | stack;
			if ((int16_t)unk_48FA <= (int16_t)t7)
			{
				carry = 0u;
				d_2 &= 0xFFu;
			}
			else
			{
				carry = 1u;
				d_2 = (d_2 & 0xFFu) | ((uint32_t)(uint8_t)~(d_2 >> 8) << 8);
			}
		}
	}
	*p_d = d_2;
	*p_carry = carry;
}

void sub_03C225(uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;

	u = unk_4A40_ADDRESS;
	sub_03C240(&u, &carry);
	if (carry == 0u)
	{
		u = unk_4B00_ADDRESS;
		sub_03C240(&u, &carry);
		if (carry == 0u)
		{
			u = unk_4BC0_ADDRESS;
			sub_03C240(&u, &carry);
			if (carry == 0u)
			{
				u = unk_4C80_ADDRESS;
				sub_03C240(&u, &carry);
			}
		}
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_03C240(uint16_t *p_u, uint32_t *p_carry)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = *p_carry;
	uint16_t t1 = 0;

	if (mem_read8(u) == 0u)
		carry = 0u;
	else
	{
		t1 = mem_read16(u + 0x16u);
		u = t1;
		if (t1 == 0u)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_03C24E(uint16_t x)
{
	mem_write8(x, mem_read8(x) | 4u);
}

void sub_03C257(uint16_t x)
{
	mem_write8(x, mem_read8(x) & ~4u);
}

void sub_03C260(uint16_t x, uint16_t y, uint16_t *p_u, uint32_t *p_zero, uint32_t *p_negative)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = *p_zero;
	uint32_t negative = *p_negative;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	if ((mem_read8(x) & 0x20u) == 0u)
	{
		negative = 0u;
		zero = 1u;
	}
	else
	{
		t1 = mem_read8(x + 0x1Eu);
		a = t1;
		if ((int8_t)a < 0x11)
		{
			negative = 0u;
			zero = 1u;
		}
		else
		{
			mem_write16(x + 0x1Cu, 0u);
			t2 = mem_read16(x + 0x25u);
			u = t2;
			if ((int16_t)u >= 0x4A40 && (int16_t)u < 0x4D40)
			{
				mem_write8(u + 0x2Au, a);
				mem_write16(u + 0x49u, x);
			}
			mem_write8(x, 0x80u);
			t3 = mem_read8(x + 0x1Bu);
			a = t3;
			b = unk_4857;
			if (a <= mem_read8(y + (int8_t)b))
			{
				t4 = mem_read8(x + 0x1Bu);
				a = t4;
			}
			if (a <= mem_read8(y + (int8_t)b))
			{
				mem_write8(x + 0x1Bu, 0u);
				u = sub_03C1C7(x);
				d = 0x6600u;
				carry = sub_078680(d);
				negative = 1u;
				zero = 0xFFu == 0u;
			}
			else
			{
				d = 0x6600u;
				carry = sub_078680(d);
				negative = 0u;
				zero = 1u == 0u;
			}
		}
	}
	*p_u = u;
	*p_zero = zero;
	*p_negative = negative;
}

uint32_t sub_03C2B5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	mem_write8(x, (mem_read8(x) ^ 0x80u) | 4u);
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
	{
		carry = 0u;
		return carry;
	}
	mem_write8(x, 0u);
	sub_03C1D3(x);
	carry = 1u;
	return carry;
}

uint32_t sub_03C2CE(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
		sub_03C257(x);
	else
		y = 0u;
	mem_write16(x + 0x1Cu, y);
	t2 = mem_read8(x + 6u);
	carry = t2 & 1u;
	return carry;
}

uint16_t sub_03C2E5(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + 0x1Fu, mem_read16(t1));
	d = mem_read16(y_2);
	mem_write16(x + 0x21u, d);
	mem_write8(x + 0x24u, d >> 8);
	return y_2;
}

void unused_03C2F3(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0;
	uint16_t t1 = 0;

	a = 0u;
	t1 = mem_read16(x + 0xFu);
	if ((int16_t)t1 < 0)
		a = 0x40u;
	t2 = mem_read8(x + 9u);
	if (((a ^ t2) & 0x40u) != 0u)
	{
		t3 = mem_read8(x + 9u);
		mem_write8(x + 9u, t3 ^ 0x40u);
		t4 = mem_read8(x + 5u);
		mem_write8(x + 5u, t4 | 0x80u);
	}
}

uint16_t sub_03C313(uint16_t x)
{
	uint8_t a = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = sub_078620(x);
	t1 = mem_read8(x + 9u);
	a = t1 & 0xBFu;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 < (int16_t)t2)
		a |= 0x40u;
	mem_write8(x + 9u, a);
	return u;
}

void sub_03C329(uint16_t x, uint16_t y, uint16_t d)
{
	uint16_t d_2 = 0;

	d_2 = (d & ~0xFFu) | mem_read8(y + (unk_4861 >> 1));
	sub_078617(x, d_2);
}

void unreached_03C332(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	t1 = mem_read16(x + 0xFu);
	if (t1 == 0u)
	{
		t2 = mem_read16(x + 0x14u);
		if (t2 == 0u)
			return;
	}
}

void sub_03C340(uint16_t x, uint16_t y, uint16_t d)
{
	d |= (uint32_t)mem_read8(y + (int8_t)unk_4857) << 8;
	sub_0786BF(x, y, d);
}

uint16_t sub_03C359(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	sub_03C179(x);
	mem_write8(x + 4u, 0x92u);
	mem_write8(x + 0x1Bu, 0xA0u);
	mem_write8(x + 0x45u, 0xA0u);
	mem_write8(x + 0x46u, 0xA0u);
	mem_write8(x + 9u, 0x20u);
	y = 0x100u;
	d = 0x8200u;
	sub_03C04C(x, y, d);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 + 0x30u;
	mem_write16(x + 0x11u, t2);
	t3 = mem_read16(x + 0x16u);
	t4 = t3 - 0x30u;
	mem_write16(x + 0x16u, t4);
	mem_write8(x + 0x3Eu, 0x14u);
	mem_write8(x + 0x57u, 0x14u);
	t5 = io_read8(VIDEO_184A);
	io_write8(VIDEO_184A, 0u);
	y = child_object_03DD9A_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	io_write16(VIDEO_1852, u);
	return y;
}

uint16_t sub_03C3A2(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = io_read8(VIDEO_184A);
	if (t1 == 0u)
		return y;
	y_2 = 0x514u;
	mem_write16(x + 0x2Eu, 0x514u);
	t2 = mem_read16(x + 0x11u);
	mem_write16(x + 0x11u, t2 - 0x30u);
	mem_write16(x + 0x16u, 0u);
	mem_write8(x + 9u, 0u);
	mem_write8(x + 0x57u, 0u);
	return y_2;
}

uint16_t sub_03C3C1(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return y;
	unk_487C = 1u;
	mem_write8(x + 0x3Fu, 0x86u - unk_4861 - unk_4861);
	y_2 = 0x600u;
	d = 0x8300u;
	sub_03C04C(x, y_2, d);
	return y_2;
}

uint16_t sub_03C3DF(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	unk_487C = 0u;
	y_2 = 0x214u;
	d = loaded_table_078000_ADDRESS;
	sub_03C04C(x, y_2, d);
	y_2 = indexed_table_03DDA2_ADDRESS;
	sub_03C2E5(x, y_2);
	mem_write8(x, (mem_read8(x) & ~4u) | 0xC0u);
	a = 0u;
	b = 0x3Cu;
	unk_48F8 = ((uint32_t)a << 8) | b;
	unk_48FA = 0xCu;
	sub_03C1DC(x, &u, &ignored16, &carry);
	if (carry == 0u)
		return sub_03C7AC(x, u);
	t2 = mem_read8(x + 0x46u);
	t3 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t2 - t3) < 0xCu)
	{
		u = 0x7DA5u;
		b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
		a = 0x14u;
	}
	else
	{
		t4 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x46u, t4);
		a = 0x14u;
		b = 1u;
	}
	mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return sub_03C654(x, u);
}

uint16_t sub_03C404(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03C7AC(x, u);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
		return sub_03C433(x, u);
	t3 = mem_read8(x + 0x3Fu);
	mem_write8(x + 0x3Fu, t3 - 1u);
	if (t3 == 1u)
		return sub_03C449(x, u);
	return sub_03C414(x);
}

uint16_t sub_03C414(uint16_t x)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;

	y = 0x300u;
	d = 0x8100u;
	sub_03C04C(x, y, d);
	u = sub_078620(x);
	mem_write16(x + 0x34u, u);
	d = sub_03C0E0(u);
	d = sub_078671(x, u, d);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x32u, a);
	mem_write8(x + 0x36u, 0x10u);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C433(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;

	io_write8(VIDEO_003C, 0x1Eu);
	y = 0x800u;
	d = 0x8500u;
	sub_03C04C(x, y, d);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C444(uint16_t x, uint16_t u)
{
	uint32_t negative = 0, overflow = 0;
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x3Fu);
	mem_write8(x + 0x3Fu, t1 - 1u);
	if (t1 == 1u)
		return sub_03C449(x, u);
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
		return sub_03C433(x, u);
	t3 = mem_read16(x + 0x34u);
	u_2 = t3;
	d = sub_03C0E0(u_2);
	d = sub_078671(x, u_2, d);
	a = (uint8_t)(d >> 8);
	t4 = mem_read8(x + 0x32u);
	negative = (uint8_t)(a - t4) >> 7;
	overflow = (uint32_t)(int8_t)a - (int8_t)t4 != (uint32_t)(int8_t)(a - t4);
	if (a == t4)
		a = 0x1Cu;
	else
	{
		if ((negative ^ overflow) == 0u)
		{
			if (overflow)
			{
				a = 0xF9u;
				mem_write8(x + 0x33u, a);
				t5 = mem_read8(x + 0x32u);
				a += t5;
				mem_write8(x + 0x32u, a);
				t6 = mem_read8(x + 0x36u);
				d = ((uint32_t)a << 8) | t6;
				sub_078617(x, d);
				if ((unk_4858 & 0x7Fu) != 0u)
					return sub_03C4F4(x, u_2);
				mem_write16(x + 0x2Eu, 0x478u);
				mem_write8(x + 0x33u, 5u);
				return sub_03C4F4(x, u_2);
			}
			a = 7u;
			mem_write8(x + 0x33u, a);
			t5 = mem_read8(x + 0x32u);
			a += t5;
			mem_write8(x + 0x32u, a);
			t6 = mem_read8(x + 0x36u);
			d = ((uint32_t)a << 8) | t6;
			sub_078617(x, d);
			if ((unk_4858 & 0x7Fu) != 0u)
				return sub_03C4F4(x, u_2);
			mem_write16(x + 0x2Eu, 0x478u);
			mem_write8(x + 0x33u, 5u);
			return sub_03C4F4(x, u_2);
		}
		if (overflow)
			a = 7u;
		else
			a = 0xF9u;
	}
	mem_write8(x + 0x33u, a);
	t5 = mem_read8(x + 0x32u);
	a += t5;
	mem_write8(x + 0x32u, a);
	t6 = mem_read8(x + 0x36u);
	d = ((uint32_t)a << 8) | t6;
	sub_078617(x, d);
	if ((unk_4858 & 0x7Fu) != 0u)
		return sub_03C4F4(x, u_2);
	mem_write16(x + 0x2Eu, 0x478u);
	mem_write8(x + 0x33u, 5u);
	return sub_03C4F4(x, u_2);
}

uint16_t sub_03C449(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t stack = 0, stack_10002 = 0;

	if ((int8_t)unk_4857 > 2)
		sub_03C24E(x);
	unk_48F0 = unk_4857 >> 1;
	mem_write8(x + 0x3Fu, 0x86u - unk_48F0 - unk_48F0);
	stack = 0xBu;
	stack_10002 = 0x12u;
	y = ((uint32_t)stack << 8) | stack_10002;
	d = 0x8900u;
	sub_03C04C(x, y, d);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C4C1(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x2Eu, 3u);
		u = sub_078620(x);
		mem_write16(x + 0x34u, u);
	}
	t2 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t2 - 1u);
	if (t2 == 1u)
		return sub_03C433(x, u);
	t3 = mem_read8(x + 0x33u);
	b = t3;
	if ((unk_4858 & ~0xFu) == 0u)
		mem_write8(x + 0x33u, 0u - b);
	t4 = mem_read8(x + 0x33u);
	t5 = mem_read8(x + 0x32u);
	a = t4 + t5;
	mem_write8(x + 0x32u, a);
	t6 = mem_read8(x + 0x36u);
	d = ((uint32_t)a << 8) | t6;
	sub_078617(x, d);
	return sub_03C4F4(x, u);
}

uint16_t sub_03C4F4(uint16_t x, uint16_t u)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, y = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t13 = 0, t14 = 0, t18 = 0, t19 = 0, t20 = 0, t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0;
	uint16_t t1 = 0, t10 = 0, t11 = 0, t12 = 0, t15 = 0, t16 = 0, t17 = 0;

	a = 0u;
	t1 = mem_read16(x + 0xFu);
	if ((int16_t)t1 < 0)
		a = 0x40u;
	t2 = mem_read8(x + 9u);
	if (((a ^ t2) & 0x40u) == 0u)
		mem_write8(x + 0x37u, 0u);
	else
	{
		t3 = mem_read8(x + 0x37u);
		mem_write8(x + 0x37u, t3 + 1u);
		t4 = mem_read8(x + 0x37u);
		if (t4 >= 0x10u)
		{
			mem_write8(x + 9u, a);
			mem_write8(x + 0x37u, 0u);
		}
	}
	t5 = mem_read8(x + 0xEu);
	t6 = mem_read8(x + 0x13u);
	if (((t5 + t6) & 0x3Cu) == 0u)
	{
		t7 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x36u, ((uint16_t)((uint32_t)(uint8_t)(((uint8_t)(0xFFu - t7) >> 1) + football_player_speed_ranges_by_rank[unk_4861 >> 1]) * unk_4858) >> 8) + 0x10u);
	}
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((a & 0xFu) != 0u)
	{
		t8 = mem_read8(x + 0x32u);
		mem_write8(x + 0x32u, t8 - 0x80u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
	}
	else
	{
		t9 = mem_read8(x + 0xFu);
		unk_48F0 = (uint16_t)(int8_t)t9 >> 8;
		t10 = mem_read16(x + 0xDu);
		t11 = mem_read16(x + 0xFu);
		t12 = t10;
		carry = (uint16_t)(t12 + t11) < t12;
		b = (uint8_t)((uint16_t)(t12 + t11) >> 8);
		t13 = mem_read8(x + 0xCu);
		a = t13 + unk_48F0 + carry;
		y = 0x30u;
		if ((int16_t)(((uint32_t)a << 8) | b) < 0x30)
		{
			mem_write16(x + 0xCu, y);
			t8 = mem_read8(x + 0x32u);
			mem_write8(x + 0x32u, t8 - 0x80u);
			mem_write16(x + 0xFu, 0u);
			mem_write16(x + 0x14u, 0u);
		}
		else
		{
			y = 0x180u;
			if ((int16_t)(((uint32_t)a << 8) | b) <= 0x180)
			{
				t14 = mem_read8(x + 0x14u);
				unk_48F0 = (uint16_t)(int8_t)t14 >> 8;
				t15 = mem_read16(x + 0x12u);
				t16 = mem_read16(x + 0x14u);
				t17 = t15;
				carry = (uint16_t)(t17 + t16) < t17;
				b = (uint8_t)((uint16_t)(t17 + t16) >> 8);
				t18 = mem_read8(x + 0x11u);
				a = t18 + unk_48F0 + carry;
				y = 0x58u;
				if ((int16_t)(((uint32_t)a << 8) | b) < 0x58)
				{
					mem_write16(x + 0x11u, y);
					t8 = mem_read8(x + 0x32u);
					mem_write8(x + 0x32u, t8 - 0x80u);
					mem_write16(x + 0xFu, 0u);
					mem_write16(x + 0x14u, 0u);
				}
				else
				{
					y = 0x170u;
					if ((int16_t)(((uint32_t)a << 8) | b) > 0x170)
					{
						mem_write16(x + 0x11u, y);
						t8 = mem_read8(x + 0x32u);
						mem_write8(x + 0x32u, t8 - 0x80u);
						mem_write16(x + 0xFu, 0u);
						mem_write16(x + 0x14u, 0u);
					}
				}
			}
			else
			{
				mem_write16(x + 0xCu, y);
				t8 = mem_read8(x + 0x32u);
				mem_write8(x + 0x32u, t8 - 0x80u);
				mem_write16(x + 0xFu, 0u);
				mem_write16(x + 0x14u, 0u);
			}
		}
	}
	t19 = mem_read8(x + 0x1Bu);
	if (t19 < 0x60u)
	{
		t20 = mem_read8(x + 0x3Eu);
		if (t20 != 0u)
		{
			mem_write8(x + 0x3Eu, 0u);
			t21 = mem_read8(x + 0x32u);
			if ((t21 & 0xE0u) == 0u)
			{
				y = 0xD00u;
				d = (d & 0xFFu) | 0x8C00u;
				sub_03C04C(x, y, d);
				return sub_03C7AC(x, u);
			}
		}
	}
	t22 = mem_read8(x + 0x41u);
	mem_write8(x + 0x41u, t22 - 1u);
	if (t22 == 1u)
	{
		unk_48F0 = (uint32_t)unk_4857 << 1;
		mem_write8(x + 0x41u, 0xC6u - unk_48F0 - unk_48F0 - unk_48F0);
		stack = 9u;
		stack_10002 = 0x18u;
		y = ((uint32_t)stack << 8) | stack_10002;
		d = (d & 0xFFu) | 0x8600u;
		sub_03C04C(x, y, d);
		return sub_03C7AC(x, u);
	}
	carry = sub_03C021();
	if (carry == 0u)
	{
		a = 0u;
		b = 0x3Cu;
		unk_48F8 = ((uint32_t)a << 8) | b;
		unk_48FA = 0xCu;
		sub_03C1DC(x, &u_2, &ignored16, &carry);
		if (carry == 0u)
			return sub_03C7AC(x, u_2);
		t23 = mem_read8(x + 0x46u);
		t24 = mem_read8(x + 0x1Bu);
		if ((uint8_t)(t23 - t24) < 0xCu)
		{
			u_2 = 0x7DA5u;
			b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
			a = 0x14u;
		}
		else
		{
			t25 = mem_read8(x + 0x1Bu);
			mem_write8(x + 0x46u, t25);
			a = 0x14u;
			b = 1u;
		}
		mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		return sub_03C654(x, u_2);
	}
	if (unk_4857 == 1u)
		y = 0x13FEu;
	else
	{
		y = 0x1350u;
		if ((unk_4858 & 3u) == 0u)
			y = 0x1364u;
	}
	d = (d & 0xFFu) | 0x9000u;
	sub_03C04C(x, y, d);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C654(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03C7AC(x, u);
	y = 0x728u;
	d = 0x8400u;
	sub_03C04C(x, y, d);
	mem_write8(x + 0x1Fu, 0x1Cu);
	mem_write8(x + 0x22u, 0x1Cu);
	sub_03C24E(x);
	u = sub_03C313(x);
	mem_write8(x + 0x37u, 0u);
	if (1u == 0u)
		return sub_03C7AC(x, u);
	return sub_03C677(x, u);
}

uint16_t sub_03C677(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	y = 0xC0Au;
	carry = sub_03C2CE(x, y);
	a = 1u;
	t1 = mem_read8(x + 0x3Fu);
	if (1u != t1)
	{
		t2 = mem_read8(x + 0x3Fu);
		mem_write8(x + 0x3Fu, t2 - 1u);
	}
	t3 = mem_read8(x + 0x41u);
	if (a != t3)
	{
		t4 = mem_read8(x + 0x41u);
		mem_write8(x + 0x41u, t4 - 1u);
	}
	t5 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t5 - 1u);
	if (t5 != 1u)
		return sub_03C7AC(x, u);
	y = 0x214u;
	d = loaded_table_078000_ADDRESS;
	sub_03C04C(x, y, d);
	y = indexed_table_03DDA2_ADDRESS;
	sub_03C2E5(x, y);
	mem_write8(x, (mem_read8(x) & ~4u) | 0xC0u);
	a = 0u;
	b = 0x3Cu;
	unk_48F8 = ((uint32_t)a << 8) | b;
	unk_48FA = 0xCu;
	sub_03C1DC(x, &u, &ignored16, &carry);
	if (carry == 0u)
		return sub_03C7AC(x, u);
	t6 = mem_read8(x + 0x46u);
	t7 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t6 - t7) < 0xCu)
	{
		u = 0x7DA5u;
		b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
		a = 0x14u;
	}
	else
	{
		t8 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x46u, t8);
		a = 0x14u;
		b = 1u;
	}
	mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return sub_03C654(x, u);
}

uint16_t sub_03C69B(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return sub_03C7AC(x, u);
	return sub_03C414(x);
}

uint16_t sub_03C6AB(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, u_2 = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03C6C7(x, u);
	y = 0xA00u;
	d = 0x8700u;
	sub_03C04C(x, y, d);
	y = child_object_03DDC2_ADDRESS;
	sub_07862F(x, y, &u_2, &carry);
	d = 0x6D00u;
	carry = sub_078680(d);
	return sub_03C7AC(x, u_2);
}

uint16_t sub_03C6C7(uint16_t x, uint16_t u)
{
	if ((int8_t)unk_4857 <= 2)
		return sub_03C7AC(x, u);
	sub_03C24E(x);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C6D5(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x, mem_read8(x) | 0xC0u);
	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 1u) == 0u)
	{
		if ((a & 2u) == 0u)
		{
			mem_write16(x + 0x1Cu, 0u);
			return sub_03C7AC(x, u);
		}
		mem_write16(x + 0x1Cu, 0x40Au);
		return sub_03C7AC(x, u);
	}
	y = 0x214u;
	d = loaded_table_078000_ADDRESS;
	sub_03C04C(x, y, d);
	y = indexed_table_03DDA2_ADDRESS;
	sub_03C2E5(x, y);
	mem_write8(x, (mem_read8(x) & ~4u) | 0xC0u);
	a = 0u;
	b = 0x3Cu;
	unk_48F8 = ((uint32_t)a << 8) | b;
	unk_48FA = 0xCu;
	sub_03C1DC(x, &u_2, &ignored16, &carry);
	if (carry == 0u)
		return sub_03C7AC(x, u_2);
	t2 = mem_read8(x + 0x46u);
	t3 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t2 - t3) < 0xCu)
	{
		u_2 = 0x7DA5u;
		b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
		a = 0x14u;
	}
	else
	{
		t4 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x46u, t4);
		a = 0x14u;
		b = 1u;
	}
	mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return sub_03C654(x, u_2);
}

uint16_t sub_03C6F9(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 6u);
		if ((t2 & 1u) == 0u)
			return sub_03C6C7(x, u);
	}
	y = VIDEO_0C00;
	d = 0x8A00u;
	sub_03C04C(x, y, d);
	mem_write8(x, 0xC0u);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C718(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	mem_write8(x, mem_read8(x) | 0xC0u);
	t1 = mem_read8(x + 6u);
	a = t1;
	if ((a & 1u) != 0u)
	{
		y = 0x214u;
		d = loaded_table_078000_ADDRESS;
		sub_03C04C(x, y, d);
		y = indexed_table_03DDA2_ADDRESS;
		sub_03C2E5(x, y);
		mem_write8(x, (mem_read8(x) & ~4u) | 0xC0u);
		a = 0u;
		b = 0x3Cu;
		unk_48F8 = ((uint32_t)a << 8) | b;
		unk_48FA = 0xCu;
		sub_03C1DC(x, &u, &ignored16, &carry);
		if (carry == 0u)
			return sub_03C7AC(x, u);
		t2 = mem_read8(x + 0x46u);
		t3 = mem_read8(x + 0x1Bu);
		if ((uint8_t)(t2 - t3) < 0xCu)
		{
			u = 0x7DA5u;
			b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
			a = 0x14u;
		}
		else
		{
			t4 = mem_read8(x + 0x1Bu);
			mem_write8(x + 0x46u, t4);
			a = 0x14u;
			b = 1u;
		}
		mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		return sub_03C654(x, u);
	}
	if ((a & 2u) == 0u)
		return sub_03C7AC(x, u);
	y = child_object_03DDC8_ADDRESS;
	sub_07862F(x, y, &u_2, &carry);
	t5 = io_read8(VIDEO_184A);
	io_write8(VIDEO_184A, 0u);
	d = 0x6200u;
	carry = sub_078680(d);
	return sub_03C7AC(x, u_2);
}

uint16_t sub_03C740(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return sub_03C7AC(x, u);
	y = 0xE78u;
	d = 0x8200u;
	sub_03C04C(x, y, d);
	return sub_03C7AC(x, u);
}

uint16_t sub_03C753(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Fu, 0x86u - unk_4861 - unk_4861);
		y = 0x600u;
		d = 0x8300u;
		sub_03C04C(x, y, d);
		return y;
	}
	return sub_03C7AC(x, u);
}

uint16_t sub_03C75C(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	y_2 = 0x206u;
	d = loaded_table_078000_ADDRESS;
	sub_03C04C(x, y_2, d);
	y_2 = indexed_table_03DDA2_ADDRESS;
	sub_03C2E5(x, y_2);
	mem_write8(x, (mem_read8(x) & ~4u) | 0xC0u);
	a = 0u;
	b = 0x3Cu;
	unk_48F8 = ((uint32_t)a << 8) | b;
	unk_48FA = 0xCu;
	sub_03C1DC(x, &u, &ignored16, &carry);
	if (carry == 0u)
		return sub_03C7AC(x, u);
	t2 = mem_read8(x + 0x46u);
	t3 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t2 - t3) < 0xCu)
	{
		u = 0x7DA5u;
		b = football_player_attack_delays_by_players[(int8_t)unk_4857 - 1];
		a = 0x14u;
	}
	else
	{
		t4 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x46u, t4);
		a = 0x14u;
		b = 1u;
	}
	mem_write16(x + 0x2Eu, ((uint32_t)a << 8) | b);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	return sub_03C654(x, u);
}

uint16_t sub_03C76A(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;

	sub_03C0EB(x, &y, &carry);
	if (carry == 0u)
		return y;
	y_2 = 0x600u;
	d = 0x8300u;
	sub_03C04C(x, y_2, d);
	return y_2;
}

uint16_t sub_03C772(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0;

	sub_03C0EB(x, &y, &carry);
	if (carry)
	{
		t1 = mem_read8(x + VIDEO_002F);
		mem_write8(x + VIDEO_002F, t1 - 1u);
		if (t1 == 1u)
		{
			y_2 = 0x1278u;
			mem_write16(x + 0x2Eu, 0x1278u);
			d = 0x3F3Au;
			carry = sub_078680(d);
			return y_2;
		}
	}
	return y;
}

void sub_03C789(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	carry = sub_03C2B5(x);
	if (carry == 0u)
		return;
	t1 = io_read8(VIDEO_1850);
	io_write8(VIDEO_1850, 0u);
	d = 0x9600u;
	carry = sub_078689(d);
	unk_487D = 1u;
	unk_4804++;
	unk_4805 = 0x100u;
}

uint16_t sub_03C7AC(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint16_t d = 0, ignored16 = 0, u_2 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	y = indexed_table_03DDB9_ADDRESS;
	sub_03C260(x, y, &u, &zero, &negative);
	if (zero)
		return y;
	if (negative)
	{
		d = 0u;
		carry = sub_078680(d);
		d = 0x9800u;
		carry = sub_078689(d);
		y = 0x1178u;
		d = 0x8F00u;
		sub_03C04C(x, y, d);
		u_2 = 0x600u;
		y = 0x400u;
		sub_03C078(x, &y, &u_2);
		return y;
	}
	unk_487E = 2u;
	d = 0xEu;
	sub_078677(d, &ignored16, &u);
	t1 = mem_read8(x + 0x45u);
	t2 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t1 - t2) <= 8u)
	{
		y = 0xF06u;
		d = 0x8D0Eu;
		sub_03C04C(x, y, d);
		return y;
	}
	t3 = mem_read8(x + 0x1Bu);
	mem_write8(x + 0x45u, t3);
	y = 0x1006u;
	d = 0x8E0Eu;
	sub_03C04C(x, y, d);
	u_2 = 0x600u;
	y = 0x400u;
	sub_03C078(x, &y, &u_2);
	t4 = mem_read8(x + 0x17u);
	mem_write8(x + 0x17u, t4 + 1u);
	return sub_03C76A(x, y);
}

uint16_t sub_03C8CD(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x + 4u, 0xA2u);
	mem_write8(x + 0x1Bu, 0xE0u);
	mem_write8(x + 0x46u, 0xE0u);
	mem_write8(x + 0x47u, 0xE0u);
	t1 = mem_read16(x + 0xCu);
	t2 = t1 + 0x40u;
	mem_write16(x + 0xCu, t2);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x + 9u, 0x40u);
	mem_write8(x + 0x33u, 0x40u);
	unk_48F8 = object_1e_part_offsets_ADDRESS;
	unk_48F1 = 0u;
	unk_48F0 = 8u;
	y = child_object_03DE1C_ADDRESS;
	sub_03C925(x, y);
	unk_48F0 = 0xAu;
	y = child_object_03DE24_ADDRESS;
	sub_03C925(x, y);
	unk_48F0 = 6u;
	y = child_object_03DE14_ADDRESS;
	sub_03C925(x, y);
	t3 = io_read8(VIDEO_184A);
	io_write8(VIDEO_184A, 0u);
	t4 = mem_read8(x + 0x2Eu);
	mem_write8(x + 0x2Eu, t4 + 1u);
	return y;
}

void sub_03C925(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint16_t stack = 0;
	uint8_t t13 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	do
	{
		if ((int8_t)unk_48F1 >= 0xB)
			break;
		stack = y;
		sub_07862C(x, y, &u, &ignored16, &carry);
		if (carry)
		{
			t1 = unk_48F8;
			t2 = (int8_t)mem_read8(t1);
			t3 = mem_read16(u + 0xCu);
			t4 = t2 + t3;
			a = (uint8_t)(t4 >> 8);
			b = (uint8_t)t4;
			mem_write16(u + 0xCu, ((uint32_t)a << 8) | b);
			mem_write16(u + 0x50u, ((uint32_t)a << 8) | b);
			t5 = t1 + 1u;
			t6 = (int8_t)mem_read8(t5);
			t7 = mem_read16(u + 0x11u);
			t8 = t6 + t7;
			a = (uint8_t)(t8 >> 8);
			b = (uint8_t)t8;
			mem_write16(u + 0x11u, ((uint32_t)a << 8) | b);
			mem_write16(u + 0x52u, ((uint32_t)a << 8) | b);
			t9 = t5 + 1u;
			t10 = (int8_t)mem_read8(t9);
			t11 = mem_read16(u + 0x16u);
			t12 = t10 + t11;
			a = (uint8_t)(t12 >> 8);
			b = (uint8_t)t12;
			mem_write16(u + 0x16u, ((uint32_t)a << 8) | b);
			mem_write16(u + 0x54u, ((uint32_t)a << 8) | b);
			unk_48F8 = t9 + 1u;
			mem_write8(u + 0x42u, 0xFFu);
			mem_write8(u + 0x57u, 0xFFu);
			mem_write8(u + 0x2Du, unk_48F1);
			unk_48F1++;
		}
		y = stack;
		t13 = unk_48F0;
		unk_48F0 = t13 - 1u;
	} while (t13 != 1u);
}

uint16_t sub_03C976(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;

	if (unk_4892 != 0u)
		return y;
	d = 0xFD00u;
	carry = sub_078680(d);
	mem_write8(x + 0x42u, 0u);
	mem_write8(x + 0x57u, 0u);
	y_2 = 0x23Cu;
	d = 0x8A00u;
	sub_03C04C(x, y_2, d);
	return y_2;
}

uint16_t sub_03C990(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		io_write8(VIDEO_184A, 1u);
		y_2 = 0x3FAu;
		d = 0x8A00u;
		sub_03C04C(x, y_2, d);
		return y_2;
	}
	return y;
}

void sub_03C9A4(uint16_t *p_x, uint16_t *p_y)
{
	uint16_t x = (uint16_t)*p_x;
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, x_2 = 0, y_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_3 = 0, stack_4 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0, t5 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		y_2 = 0x428u;
		d = loaded_table_078000_ADDRESS;
		sub_03C04C(x, y_2, d);
		mem_write16(x + 0xFu, 0xFF00u);
		y = 0xFF00u;
		mem_write16(x + 0x14u, 0xFF00u);
	}
	else
	{
		t2 = mem_read8(x + VIDEO_002F);
		a = t2;
		if (a == 0xDCu)
			unk_487C = 1u;
		if ((int8_t)a > 0x4B)
		{
			b = 0u;
			if ((a & 0x10u) == 0u)
				b++;
			io_write8(VIDEO_184A, b);
		}
		else if ((int8_t)a >= 0x4B)
		{
			sub_078650(x, &u, &ignored16);
			a = unk_480F | 2u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			stack_2 = u >> 8;
			stack = (uint8_t)u;
			a = stack_2;
			t3 = io_read8(VIDEO_00C0);
			b = stack & t3;
			stack_2 = x >> 8;
			stack = (uint8_t)x;
			stack_3 = b;
			stack_4 = a;
			x_2 = ((uint32_t)stack_4 << 8) | stack_3;
			u = 0x100u;
			a = 0u;
			while (u != 0u)
			{
				mem_write8(x_2, a);
				x_2++;
				u--;
			}
			x = ((uint32_t)stack_2 << 8) | stack;
			a = unk_480F & ~3u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			mem_write8(x, 0x80u);
			t4 = io_read16(x + 0x11u);
			t5 = t4 + 0x10u;
			io_write16(x + 0x11u, t5);
			d = 0x7000u;
			carry = sub_078680(d);
			b = 2u;
			io_write8(VIDEO_184A, b);
		}
	}
	*p_x = x;
	*p_y = y;
}

uint16_t sub_03CA2B(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	unk_487C = 0u;
	t1 = mem_read8(x + VIDEO_002F);
	if (t1 == 0x26u)
	{
		d = 0x3F37u;
		carry = sub_078680(d);
	}
	t2 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t2 - 1u);
	if (t2 != 1u)
		return y;
	y_2 = indexed_table_03DE50_ADDRESS;
	sub_03C2E5(x, y_2);
	d = 0x7400u;
	carry = sub_078680(d);
	y_2 = 0x53Cu;
	d = 0x8900u;
	sub_03C04C(x, y_2, d);
	return y_2;
}

uint16_t sub_03CA55(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03CD84(x, u);
	return sub_03CA5B(x);
}

uint16_t sub_03CA5B(uint16_t x)
{
	uint16_t y = 0;

	y = 0x610u;
	return sub_03CA5E(x, y);
}

uint16_t sub_03CA5E(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, u = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0;

	stack = y;
	y_2 = indexed_table_03DE50_ADDRESS;
	sub_03C2E5(x, y_2);
	y_2 = stack;
	d = 0x8900u;
	sub_03C04C(x, y_2, d);
	u = sub_078620(x);
	mem_write16(x + 0x34u, u);
	sub_03C257(x);
	t1 = mem_read8(x + 0x36u);
	if (t1 != 0u)
		return sub_03CD8A(x, u);
	carry = sub_03C021();
	if (carry == 0u)
		return sub_03CD84(x, u);
	t2 = mem_read8(x + 0x36u);
	mem_write8(x + 0x36u, t2 + 1u);
	d = 0x7400u;
	carry = sub_078680(d);
	y_2 = 0x53Cu;
	d = 0x8A00u;
	sub_03C04C(x, y_2, d);
	return sub_03CDD8(x, u);
}

uint16_t sub_03CA79(uint16_t x, uint16_t u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u_2 = 0, y = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03CD84(x, u);
	a = unk_4858;
	if ((a & 8u) == 0u)
	{
		t2 = (a & 3u) * 0xC0u;
		t3 = t2 + unk_4A40_ADDRESS;
		b = (uint8_t)t3;
		stack = t3 >> 8;
		stack_10002 = b;
		u_2 = ((uint32_t)stack << 8) | stack_10002;
		if (mem_read8(u_2) == 0u)
		{
			d = b;
			u_2 = sub_078620(x);
		}
		mem_write16(x + 0x34u, u_2);
		y = 0x700u;
		d |= 0x8000u;
		sub_03C04C(x, y, d);
		return sub_03CD84(x, u_2);
	}
	d = b;
	u_2 = sub_078620(x);
	mem_write16(x + 0x34u, u_2);
	y = 0x700u;
	d |= 0x8000u;
	sub_03C04C(x, y, d);
	return sub_03CD84(x, u_2);
}

uint16_t sub_03CAA8(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, y = 0;
	uint8_t stack = 0, stack_10002 = 0;
	uint8_t t1 = 0, t3 = 0, t5 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0;
	uint16_t t2 = 0, t4 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 2u) != 0u)
	{
		unk_4897 = 1u;
		unk_4898 = 2u;
		d = 0x7500u;
		carry = sub_078680(d);
		t2 = (uint32_t)(uint8_t)((((uint32_t)unk_4861 << 1) << 1) << 1) * unk_4858;
		if (t2 >= 0x3000u)
		{
			y = child_object_03DE54_ADDRESS;
			t3 = mem_read8(x + 0x1Bu);
			if ((int8_t)t3 < 0x20 && (unk_4858 & 3u) == 0u)
				y = child_object_03DE5C_ADDRESS;
			sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
		}
	}
	unk_48F8 = 0x30u;
	unk_48FA = 8u;
	sub_03C1DC(x, &ignored16, &d, &carry);
	b = (uint8_t)d;
	if (carry == 0u)
	{
		t4 = mem_read16(x + 0x34u);
		u = t4;
		if ((unk_4815 & 7u) != 0u)
		{
			d = b;
			d = sub_078671(x, u, d);
			y = indexed_table_03DE70_ADDRESS;
			sub_03C329(x, y, d);
			return sub_03CD84(x, u);
		}
		t5 = mem_read8(x + 9u);
		a = t5 & 0x40u;
		t6 = mem_read16(x + 0xCu);
		t7 = mem_read16(u + 0xCu);
		if ((int16_t)t7 <= (int16_t)t6)
		{
			b = 0xDAu;
			if (a != 0u)
			{
				d = b;
				d = sub_078671(x, u, d);
				y = indexed_table_03DE70_ADDRESS;
				sub_03C329(x, y, d);
				return sub_03CD84(x, u);
			}
			t8 = mem_read8(x + 9u);
			mem_write8(x + 9u, t8 | 0x40u);
			t9 = mem_read8(x + 6u);
			mem_write8(x + 6u, t9 | 0x80u);
			d = b;
			d = sub_078671(x, u, d);
			y = indexed_table_03DE70_ADDRESS;
			sub_03C329(x, y, d);
			return sub_03CD84(x, u);
		}
		b = 0x26u;
		if (a == 0u)
		{
			d = b;
			d = sub_078671(x, u, d);
			y = indexed_table_03DE70_ADDRESS;
			sub_03C329(x, y, d);
			return sub_03CD84(x, u);
		}
		t10 = mem_read8(x + 9u);
		mem_write8(x + 9u, t10 & 0xBFu);
		t11 = mem_read8(x + 6u);
		mem_write8(x + 6u, t11 | 0x80u);
		d = b;
		d = sub_078671(x, u, d);
		y = indexed_table_03DE70_ADDRESS;
		sub_03C329(x, y, d);
		return sub_03CD84(x, u);
	}
	d = 0x6A00u;
	carry = sub_078680(d);
	mem_write8(x + 0x1Fu, 0x28u);
	mem_write8(x + 0x22u, 0xFAu);
	u = sub_03C313(x);
	if (unk_4857 != 1u)
	{
		sub_03C225(&u, &carry);
		if (carry)
		{
			y = 0x800u;
			d = 0x81FAu;
			sub_03C04C(x, y, d);
			sub_03C24E(x);
			return sub_03CC2C(x, u);
		}
	}
	t12 = mem_read8(x + 0x47u);
	t13 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t12 - t13) > 0x10u)
	{
		t14 = mem_read8(x + 0x1Bu);
		mem_write8(x + 0x47u, t14);
		y = 0x1101u;
		d = 0x8AFAu;
		sub_03C04C(x, y, d);
		return sub_03CD84(x, u);
	}
	u = 0x7E63u;
	stack = 0x11u;
	stack_10002 = bear_attack_delays_by_players[(int8_t)unk_4857 - 1];
	y = ((uint32_t)stack << 8) | stack_10002;
	d = 0x8AFAu;
	sub_03C04C(x, y, d);
	return sub_03CD84(x, u);
}

uint16_t sub_03CB96(uint16_t x, uint16_t u)
{
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0, t5 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return sub_03CBCA(x, u);
	mem_write8(x, 0xC0u);
	y = 0xA00u;
	d = 0x8C00u;
	sub_03C04C(x, y, d);
	t2 = bear_charge_speeds_by_rank[((unk_4861 >> 1) & ~1u) / 2u];
	d_2 = (uint8_t)t2;
	stack = t2 >> 8;
	t3 = mem_read8(x + 9u);
	t4 = t3 & 0x40u;
	a = stack;
	if (t4 != 0u)
	{
		t5 = 0u - (((uint32_t)a << 8) | (d_2 & 0xFFu));
		d_2 = (uint8_t)t5;
		a = (uint8_t)(t5 >> 8);
	}
	mem_write16(x + 0xFu, ((uint32_t)a << 8) | (d_2 & 0xFFu));
	y = indexed_table_03DE90_ADDRESS;
	sub_03C2E5(x, y);
	return sub_03CBCA(x, u);
}

uint16_t sub_03CBCA(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint16_t d = 0, y = 0;

	y = indexed_table_03DE67_ADDRESS;
	sub_03C260(x, y, &u, &zero, &negative);
	if (zero)
	{
		sub_03C0EB(x, &y, &carry);
		return y;
	}
	if (negative)
		return sub_03CE21(x);
	unk_487E = 2u;
	d = 0x27u;
	sub_078677(d, &y, &u);
	mem_write8(x, 0xC4u);
	sub_03C0EB(x, &y, &carry);
	return y;
}

uint16_t sub_03CBEA(uint16_t x)
{
	uint8_t d = 0;
	uint16_t d_2 = 0, u = 0, y = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write16(x + 0x1Cu, 0x809u);
	t1 = mem_read16(x + 0xCu);
	u = t1;
	t2 = mem_read16(x + 0xFu);
	d = (uint8_t)t2;
	if (t2 != 0u)
		return sub_03CBCA(x, u);
	mem_write16(x + 0x1Cu, 0u);
	mem_write8(x, 0xC0u);
	y = 0x1000u;
	d_2 = (d & 0xFFu) | 0x8800u;
	sub_03C04C(x, y, d_2);
	return sub_03CBCA(x, u);
}

uint16_t sub_03CC0A(uint16_t x, uint16_t u)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	sub_03C24E(x);
	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return sub_03CD84(x, u);
	y = 0x603u;
	return sub_03CA5E(x, y);
}

uint16_t sub_03CC1B(uint16_t x, uint16_t u)
{
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03CD84(x, u);
	y = 0x800u;
	d = 0x8100u;
	sub_03C04C(x, y, d);
	sub_03C24E(x);
	return sub_03CC2C(x, u);
}

uint16_t sub_03CC2C(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t y = 0;

	y = 0x80Au;
	carry = sub_03C2CE(x, y);
	if (carry)
		return sub_03CA5B(x);
	return sub_03CDD8(x, u);
}

uint16_t sub_03CC38(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0;

	sub_03C0EB(x, &ignored16, &carry);
	y = 0x601u;
	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		return sub_03CA5E(x, y);
	return y;
}

uint16_t sub_03CC47(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_03C0EB(x, &y, &carry);
	if (carry == 0u)
		return y;
	t1 = mem_read8(x + VIDEO_002F);
	if (t1 == 0u)
		return sub_03CCBA(x, y);
	t2 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t2 - 1u);
	if (t2 != 1u)
	{
		unk_4897 = 1u;
		unk_4898 = 1u;
		if ((int8_t)unk_4861 <= 0xC)
		{
			if ((int8_t)unk_4858 >= 0)
				return sub_03CCBA(x, y);
			y_2 = 0x280u;
			u = 0x400u;
			sub_03C078(x, &y_2, &u);
			return y_2;
		}
		y = child_object_03DE54_ADDRESS;
		sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
		if ((int8_t)unk_4861 <= 0x14)
		{
			if ((int8_t)unk_4858 >= 0)
				return sub_03CCBA(x, y);
			y_2 = 0x280u;
			u = 0x400u;
			sub_03C078(x, &y_2, &u);
			return y_2;
		}
		y = child_object_03DE54_ADDRESS;
		sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
		if ((int8_t)unk_4858 >= 0)
			return sub_03CCBA(x, y);
		y_2 = 0x280u;
		u = 0x400u;
		sub_03C078(x, &y_2, &u);
		return y_2;
	}
	unk_4897 = 1u;
	unk_4898 = 1u;
	if ((int8_t)unk_4861 <= 8)
		return y;
	y = child_object_03DE54_ADDRESS;
	sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	if ((int8_t)unk_4861 > 0xF)
	{
		y = child_object_03DE54_ADDRESS;
		sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
	}
	return y;
}

void unreached_03CCAA(uint16_t x)
{
	uint16_t y = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	y = t1;
	if ((int16_t)y >= 0x70 || (int16_t)y <= 0x140)
	{
		sub_03CCBA(x, y);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	sub_03CCBA(x, y);
}

uint16_t sub_03CCBA(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x1Bu);
	if (t1 == 0u)
	{
		y_2 = 0xDC8u;
		d = 0x8600u;
		sub_03C04C(x, y_2, d);
		mem_write8(x, 0x80u);
		mem_write16(x + 0xAu, 0x4040u);
		mem_write16(x + 0x1Cu, 0u);
		return y_2;
	}
	t2 = mem_read8(x + 0x3Fu);
	mem_write8(x + 0x3Fu, t2 + 1u);
	t3 = mem_read8(x + 0x3Fu);
	if (t3 > 3u)
	{
		mem_write8(x + 0x3Fu, 0u);
		y_2 = 0xF00u;
		d = 0x8400u;
		sub_03C04C(x, y_2, d);
		return y_2;
	}
	t4 = mem_read8(x + 6u);
	if ((t4 & 1u) == 0u)
		return y;
	y_2 = 0x1200u;
	d = 0x8800u;
	sub_03C04C(x, y_2, d);
	return y_2;
}

uint16_t sub_03CCE5(uint16_t x, uint16_t y)
{
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		t2 = mem_read8(x + 6u);
		if ((t2 & 1u) != 0u)
		{
			y_2 = 0x1200u;
			d = 0x8800u;
			sub_03C04C(x, y_2, d);
			return y_2;
		}
	}
	return y;
}

uint16_t sub_03CD05(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = io_read8(VIDEO_002F);
	io_write8(VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x2Eu, 0xE78u);
		mem_write16(x + 4u, 0x81BBu);
		sub_03CD3A(x);
		return y;
	}
	t2 = io_read8(VIDEO_002F);
	a = t2;
	if (a == 0x11u)
	{
		y = child_object_03DE94_ADDRESS;
		sub_07862C(x, y, &ignored16, &d, &carry);
		a = (uint8_t)(d >> 8);
	}
	if (a <= 0x28u)
	{
		mem_write8(x, 0x90u);
		t3 = mem_read8(x + 0xAu);
		a = t3 + 1u;
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
	}
	return y;
}

void sub_03CD3A(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x2Eu, 0x135Au);
		return;
	}
}

void sub_03CD47(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	carry = sub_03C2B5(x);
	if (carry == 0u)
		return;
	d = 0x9600u;
	carry = sub_078689(d);
	unk_487D = 1u;
	unk_4804++;
	unk_4805 = 0x100u;
}

uint16_t sub_03CD84(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_03C0EB(x, &ignored16, &carry);
	mem_write8(x + 0x36u, 0u);
	return sub_03CD8A(x, u);
}

uint16_t sub_03CD8A(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	mem_write8(x, mem_read8(x) | 0xC0u);
	stack = ((((uint32_t)unk_4857 << 1) << 1) << 1) << 1;
	t1 = mem_read8(x + 0x3Au);
	if (t1 < (uint8_t)(0x96u - stack))
		return sub_03CDD8(x, u);
	mem_write8(x + 0x3Au, 0u);
	if (unk_4857 == 1u)
	{
		carry = sub_03C021();
		if (carry)
			return sub_03CDD8(x, u);
	}
	d = 0x7400u;
	carry = sub_078680(d);
	t2 = mem_read16(x + 0xCu);
	y = t2;
	if ((int16_t)y >= 0x58)
	{
		if ((int16_t)y > 0x162)
			mem_write8(x + 9u, 0x40u);
	}
	else
		mem_write8(x + 9u, 0u);
	y = 0x900u;
	d = 0x8B00u;
	sub_03C04C(x, y, d);
	return sub_03CDD8(x, u);
}

uint16_t sub_03CDD8(uint16_t x, uint16_t u)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	sub_03C0EB(x, &ignored16, &carry);
	t1 = mem_read8(x + 0x3Au);
	if (t1 != 0xFFu)
	{
		t2 = mem_read8(x + 0x3Au);
		mem_write8(x + 0x3Au, t2 + 1u);
	}
	y = indexed_table_03DE67_ADDRESS;
	sub_03C260(x, y, &u, &zero, &negative);
	if (zero)
		return y;
	t3 = mem_read8(x + 9u);
	t4 = mem_read8(u + 9u);
	if ((t3 ^ t4) == 0u)
	{
		y = 0xB00u;
		a = 0x83u;
	}
	else
	{
		y = 0xB00u;
		a = 0x82u;
	}
	d = (uint32_t)a << 8;
	sub_03C04C(x, y, d);
	unk_487E = 2u;
	d = 0x27u;
	sub_078677(d, &y, &u);
	t5 = mem_read8(x + 0x1Bu);
	if (t5 == 0u)
		return sub_03CE21(x);
	t6 = mem_read8(x + 0x46u);
	t7 = mem_read8(x + 0x1Bu);
	if ((uint8_t)(t6 - t7) > 0xCu)
		return sub_03CE2D(x);
	return y;
}

uint16_t sub_03CE21(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0u;
	carry = sub_078680(d);
	d = 0x9800u;
	carry = sub_078689(d);
	return sub_03CE2D(x);
}

uint16_t sub_03CE2D(uint16_t x)
{
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x1Bu);
	mem_write8(x + 0x46u, t1);
	y = 0xC02u;
	d = 0x8500u;
	sub_03C04C(x, y, d);
	unk_4897 = 1u;
	unk_4898 = 1u;
	u = 0x500u;
	y = 0x380u;
	sub_03C078(x, &y, &u);
	return y;
}

void sub_03D033(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	mem_write16(x + 0xCu, 0x148u);
	mem_write16(x + 0x11u, 0x80u);
	mem_write16(x + 0x16u, 0x80u);
	t1 = unk_48E0;
	t2 = 0u - t1;
	mem_write16(x + 0x14u, t2);
	t3 = mem_read8(x + 6u);
	if (t3 == 2u)
	{
		d = VIDEO_1F00;
		carry = sub_078680(d);
	}
	t4 = mem_read16(x + 0x2Eu);
	mem_write16(x + 0x2Eu, t4 - 1u);
	if (t4 == 1u)
	{
		t5 = mem_read8(x + 0x2Du);
		mem_write8(x + 0x2Du, t5 + 1u);
		t6 = mem_read8(x + 5u);
		mem_write8(x + 5u, (t6 + 1u) | 0x80u);
		mem_write16(x + 0x2Eu, 0x140u);
	}
	sub_03D180(x);
}

uint16_t sub_03D073(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	mem_write8(x + 0x2Du, 5u);
	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	do
	{
		t2 = mem_read8(x + 0x28u);
		mem_write8(x + 0x28u, t2 + 1u);
		t3 = mem_read8(x + 0x28u);
		if (t3 == 5u)
		{
			mem_write8(x + 0x2Du, 7u);
			mem_write16(x + 4u, 0x480u);
			return u;
		}
		u += 0xC0u;
		if (u == unk_4D40_ADDRESS)
			u = unk_4A40_ADDRESS;
	} while (mem_read8(u) == 0u);
	mem_write16(x + 0x2Bu, u);
	mem_write16(x + 0x2Eu, 0xC8u);
	return sub_03D0A0(x);
}

uint16_t sub_03D0A0(uint16_t x)
{
	uint16_t d = 0, u = 0;
	uint8_t t21 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0;

	t1 = mem_read16(x + 0x2Bu);
	u = t1;
	if (mem_read8(u) == 0u)
	{
		sub_03D15D(x);
		return u;
	}
	t2 = mem_read16(x + 0x2Eu);
	mem_write16(x + 0x2Eu, t2 - 1u);
	if (t2 == 1u)
	{
		sub_03D15D(x);
		return u;
	}
	t3 = mem_read16(u + 0x11u);
	t4 = mem_read16(u + 0x16u);
	mem_write16(u + 0x11u, t3 + t4 - 0x80u);
	t5 = mem_read16(x + 0xCu);
	d = t5 + 0x18u;
	t6 = mem_read16(u + 0xCu);
	if ((int16_t)d <= (int16_t)t6)
	{
		t7 = mem_read16(x + 0x2Bu);
		u = t7;
		d = 0xF6u;
		d = sub_078671(x, u, d);
		d = (d & ~0xFFu) | 0x80u;
		sub_078617(x, d);
		t8 = mem_read16(u + 0x11u);
		t9 = mem_read16(u + 0x16u);
		mem_write16(u + 0x11u, t8 - t9 + 0x80u);
		mem_write8(u + 6u, 0x80u);
		sub_03D180(x);
		return u;
	}
	t10 = mem_read16(u + 0xCu);
	if ((int16_t)t10 <= (int16_t)(d - 0x30u))
	{
		t7 = mem_read16(x + 0x2Bu);
		u = t7;
		d = 0xF6u;
		d = sub_078671(x, u, d);
		d = (d & ~0xFFu) | 0x80u;
		sub_078617(x, d);
		t8 = mem_read16(u + 0x11u);
		t9 = mem_read16(u + 0x16u);
		mem_write16(u + 0x11u, t8 - t9 + 0x80u);
		mem_write8(u + 6u, 0x80u);
		sub_03D180(x);
		return u;
	}
	t11 = mem_read16(x + 0x11u);
	d = t11 + 0x10u;
	t12 = mem_read16(u + 0x11u);
	if ((int16_t)d <= (int16_t)t12)
	{
		t7 = mem_read16(x + 0x2Bu);
		u = t7;
		d = 0xF6u;
		d = sub_078671(x, u, d);
		d = (d & ~0xFFu) | 0x80u;
		sub_078617(x, d);
		t8 = mem_read16(u + 0x11u);
		t9 = mem_read16(u + 0x16u);
		mem_write16(u + 0x11u, t8 - t9 + 0x80u);
		mem_write8(u + 6u, 0x80u);
		sub_03D180(x);
		return u;
	}
	t13 = mem_read16(u + 0x11u);
	if ((int16_t)t13 <= (int16_t)(d - 0x20u))
	{
		t7 = mem_read16(x + 0x2Bu);
		u = t7;
		d = 0xF6u;
		d = sub_078671(x, u, d);
		d = (d & ~0xFFu) | 0x80u;
		sub_078617(x, d);
		t8 = mem_read16(u + 0x11u);
		t9 = mem_read16(u + 0x16u);
		mem_write16(u + 0x11u, t8 - t9 + 0x80u);
		mem_write8(u + 6u, 0x80u);
		sub_03D180(x);
		return u;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	t14 = mem_read16(u + 0x11u);
	t15 = mem_read16(u + 0x16u);
	mem_write16(u + 0x11u, t14 - t15 + 0x80u);
	mem_write8(x + 5u, 0x84u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x, 0xC0u);
	t16 = mem_read16(x + 0x2Bu);
	u = t16;
	t17 = mem_read16(x + 0x11u);
	d = t17;
	mem_write16(x + 0x32u, d);
	t18 = mem_read16(u + 0x16u);
	mem_write16(x + 0x11u, d - t18 + 0x80u);
	t19 = mem_read16(x + 0x16u);
	d = t19;
	mem_write16(x + 0x34u, d);
	t20 = mem_read16(u + 0x16u);
	mem_write16(x + 0x16u, d + t20 - 0x80u);
	mem_write16(x + 0x1Cu, 0x1406u);
	t21 = mem_read8(x + 0x2Du);
	mem_write8(x + 0x2Du, t21 + 1u);
	return u;
}

void sub_03D155(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
	{
		sub_03D15D(x);
		return;
	}
}

void sub_03D15D(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x2Du, 4u);
	mem_write16(x + 0x16u, 0u);
	mem_write16(x + 0x1Cu, 0u);
	t1 = mem_read16(x + 0x32u);
	mem_write16(x + 0x11u, t1);
	t2 = mem_read16(x + 0x34u);
	mem_write16(x + 0x16u, t2);
	mem_write8(x + 6u, 0x80u);
}

void sub_03D180(uint16_t x)
{
	uint16_t d = 0;
	uint16_t t1 = 0;

	d = unk_48AC;
	t1 = mem_read16(x + 0x29u);
	if (d == t1)
	{
		mem_write16(x + 0x29u, d);
		return;
	}
	mem_write8(x + 0x2Du, 7u);
	mem_write16(x + 4u, 0x480u);
}

void sub_03D198(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((((uint16_t)((uint32_t)t1 << 8) >> 8) & 1u) != 0u)
	{
		mem_write8(x, 0u);
		unk_488F = 0u;
	}
	mem_write16(x + 0xFu, unk_48DE);
	mem_write16(x + 0x14u, 0u - unk_48E0);
}

void unused_03D1BF(void)
{
}

void sub_03D1C0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		y = child_object_03DF08_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
		mem_write16(x + 0x41u, u);
		mem_write16(u + 0x41u, x);
	}
	d = 0x80u;
	a = 0xC4u;
	t2 = mem_read8(x + 0x30u);
	if (t2 != 0u)
	{
		d = 0xC0u;
		a = 0xC3u;
	}
	mem_write8(x + 4u, a);
	mem_write8(x + 0x1Bu, d);
	mem_write8(x + 9u, 0x40u);
	t3 = mem_read8(x + 0x2Eu);
	mem_write8(x + 0x2Eu, t3 + 1u);
	mem_write8(x + 0x57u, 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03D1F0(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	if (unk_4892 != 0u)
		return y;
	mem_write8(x + 0x57u, 0u);
	unk_487C = 1u;
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x60u);
	mem_write16(x + 0xCu, 0x1A0u);
	mem_write16(x + 0x11u, 0xE8u);
	y_2 = 0x2E0u;
	d = 0x81E8u;
	sub_03C04C(x, y_2, d);
	y_2 = 0xFF40u;
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		y_2 = 0xFEE0u;
	mem_write16(x + 0xFu, y_2);
	mem_write16(x + 0x14u, 0xFFE0u);
	t2 = io_read16(VIDEO_1852);
	y_2 = t2;
	mem_write8(y_2 + 0x2Au, 1u);
	d = 0x6000u;
	carry = sub_078680(d);
	return y_2;
}

void sub_03D240(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		y = 0x3C0u;
		d = 0x8900u;
		sub_03C04C(x, y, d);
		t2 = mem_read8(x + 0x30u);
		if (t2 == 0u)
		{
			d = 0x3F35u;
			carry = sub_078680(d);
			y = child_object_03DF10_ADDRESS;
			sub_07862F(x, y, &u, &carry);
		}
	}
	else
	{
		t3 = mem_read8(x + VIDEO_002F);
		if (t3 == 0x14u)
		{
			t4 = io_read16(VIDEO_1852);
			y = t4;
			mem_write8(y + 0x2Au, 0u);
			d = 0x6000u;
			carry = sub_078680(d);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D275(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
		sub_03D285(x, &y, &u);
	*p_y = y;
	*p_u = u;
}

void sub_03D27B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, y = 0;

	y = 0xD00u;
	d = 0x8700u;
	sub_03C04C(x, y, d);
	*p_y = y;
	*p_u = u;
	sub_03D295(x, p_y, p_u);
}

void sub_03D285(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, t1 & 0xCFu);
	y = 0x400u;
	d = 0x8100u;
	sub_03C04C(x, y, d);
	*p_y = y;
	*p_u = u;
	sub_03D295(x, p_y, p_u);
}

void sub_03D295(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	y = indexed_table_03DF16_ADDRESS;
	sub_03D6C9(x, y);
	mem_write8(x, (mem_read8(x) | 0xC0u) & ~4u);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		u = sub_03C17F();
	else
		u = sub_078620(x);
	mem_write16(x + 0x34u, u);
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x32u, a);
	*p_y = y;
	*p_u = u;
	sub_03D51B(x, p_y, p_u);
}

void sub_03D2BE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, x_2 = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
		sub_03D537(x, &y, &u);
	else
	{
		stack = x;
		y = x + 0xCu;
		t2 = mem_read16(x + 0x41u);
		x_2 = t2 + 0xCu;
		u_2 = 0xFu;
		while (u_2 != 0u)
		{
			mem_write8(x_2, mem_read8(y));
			y++;
			x_2++;
			u_2--;
		}
		x_2 = stack;
		t3 = mem_read16(x_2 + 0x34u);
		u = t3;
		t4 = mem_read16(x_2 + 0xCu);
		t5 = mem_read16(u + 0xCu);
		d = t4 - t5;
		if ((int16_t)(d >> 15 ? 0u - d : d) >= 0x4A)
			sub_03D380(x_2, &y, &u);
		else
		{
			t6 = mem_read16(x_2 + 0x11u);
			t7 = mem_read16(u + 0x11u);
			d = t6 - t7;
			if ((int16_t)(d >> 15 ? 0u - d : d) >= 0x12 || (((uint16_t)((uint32_t)unk_4858 << 8) >> 8) & 0x30u) == 0u)
				sub_03D380(x_2, &y, &u);
			else
				sub_03D333(x_2, &y, &u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D2FE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0, u_2 = 0, y = 0;
	uint8_t t1 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x36u);
	mem_write8(x + 0x36u, t1 - 1u);
	if (t1 == 1u)
	{
		y = 0x1500u;
		d = 0x8300u;
		sub_03C04C(x, y, d);
		*p_y = y;
		*p_u = u;
		sub_03D440(x, p_y, p_u);
		return;
	}
	t2 = mem_read16(x + 0x34u);
	u_2 = t2;
	t3 = mem_read16(x + 0xCu);
	t4 = mem_read16(u_2 + 0xCu);
	d = t3 - t4;
	if ((int16_t)(d >> 15 ? 0u - d : d) < 0x3A)
	{
		t5 = mem_read16(x + 0x11u);
		t6 = mem_read16(u_2 + 0x11u);
		d = t5 - t6;
		if ((int16_t)(d >> 15 ? 0u - d : d) < 0xA)
		{
			t7 = mem_read8(x + 0x30u);
			if ((((uint16_t)((uint32_t)(uint8_t)(((uint16_t)((uint32_t)unk_4858 << 8) >> 8) + t7) << 8) >> 8) & 0x30u) != 0u)
			{
				*p_y = y;
				*p_u = u_2;
				sub_03D333(x, p_y, p_u);
				return;
			}
		}
	}
	*p_y = y;
	*p_u = u_2;
	sub_03D380(x, p_y, p_u);
}

void sub_03D333(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t y = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	y = indexed_table_03DF22_ADDRESS;
	sub_03D6C9(x, y);
	t1 = mem_read8(x + 9u);
	a = t1 | 0x40u;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t2 < (int16_t)t3)
		a &= 0xBFu;
	mem_write8(x + 9u, a);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	if (unk_4857 != 1u)
	{
		t4 = mem_read16(u + 0x16u);
		if (t4 == 0u)
		{
			t5 = mem_read8(x + 0x30u);
			if (((unk_4858 ^ t5) & 0xFu) <= stage_3_boss_slow_attack_chances_by_players[(int8_t)unk_4857 - 1])
			{
				mem_write16(x + 0x2Eu, 0x60Eu);
				*p_y = y;
				*p_u = u;
				sub_03D537(x, p_y, p_u);
				return;
			}
		}
		mem_write16(x + 0x2Eu, 0x601u);
		*p_y = y;
		*p_u = u;
		sub_03D537(x, p_y, p_u);
		return;
	}
	t5 = mem_read8(x + 0x30u);
	if (stage_3_boss_slow_attack_chances_by_players[(int8_t)unk_4857 - 1] < ((unk_4858 ^ t5) & 0xFu))
	{
		mem_write16(x + 0x2Eu, 0x601u);
		*p_y = y;
		*p_u = u;
		sub_03D537(x, p_y, p_u);
		return;
	}
	mem_write16(x + 0x2Eu, 0x60Eu);
	*p_y = y;
	*p_u = u;
	sub_03D537(x, p_y, p_u);
}

void sub_03D380(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, ignored16 = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t2 = 0, t3 = 0, t9 = 0, t10 = 0, t11 = 0;

	t1 = mem_read8(x + 9u);
	a = t1 & 0x40u;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)t3 <= (int16_t)t2)
	{
		if (a == 0u)
		{
			t4 = mem_read8(x + 9u);
			mem_write8(x + 9u, t4 | 0x40u);
			t5 = mem_read8(x + 6u);
			mem_write8(x + 6u, t5 | 0x80u);
		}
	}
	else if (a != 0u)
	{
		t6 = mem_read8(x + 9u);
		mem_write8(x + 9u, t6 & 0xBFu);
		t7 = mem_read8(x + 6u);
		mem_write8(x + 6u, t7 | 0x80u);
	}
	t8 = mem_read8(x + 0x32u);
	unk_48F0 = t8;
	d = 5u;
	sub_03C1B1(x, u, d);
	a = unk_48F0;
	mem_write8(x + 0x32u, a);
	d_2 = 5u | ((uint32_t)a << 8);
	sub_03D6DC(x, d_2);
	t9 = mem_read16(x + 0xFu);
	t10 = mem_read16(x + 0xFu);
	t11 = t9 + t10;
	mem_write16(x + 0xFu, t11);
	sub_03C0EB(x, &ignored16, &carry);
	*p_y = y;
	*p_u = u;
	sub_03D51B(x, p_y, p_u);
}

void sub_03D3DE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t3 = 0, t7 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		sub_03D537(x, &y, &u);
	else
	{
		sub_03C24E(x);
		t2 = mem_read8(x + 0x43u);
		if (t2 == 0u)
		{
			t3 = mem_read16(x + 0x34u);
			u = t3;
			t4 = mem_read8(u + 2u);
			if (t4 == 1u)
			{
				t5 = mem_read8(x + 0x30u);
				if (t5 != 1u)
				{
					y = indexed_table_03DF32_ADDRESS;
					sub_03C2E5(x, y);
					y = 0x800u;
					d = 0x8400u;
					sub_03C04C(x, y, d);
				}
				else
				{
					y = 0x500u;
					d = 0x8200u;
					sub_03C04C(x, y, d);
					sub_03C066(x);
					mem_write8(x, 0x80u);
					u = 0x580u;
					y = 0x400u;
					t6 = mem_read8(x + 0x17u);
					mem_write8(x + 0x17u, t6 + 1u);
					sub_03C078(x, &y, &u);
					sub_03C0EB(x, &y, &carry);
				}
			}
			else
			{
				u = sub_03C313(x);
				y = 0x700u;
				d = 0x8300u;
				sub_03C04C(x, y, d);
				sub_03D44A(x, &y, &u);
			}
		}
		else
		{
			y = 0xE00u;
			d = 0x8800u;
			sub_03C04C(x, y, d);
			t7 = mem_read16(x + 0x41u);
			u = t7;
			mem_write16(u + 0xFu, 0u);
			mem_write16(u + 0x14u, 0u);
			mem_write16(u + 0x19u, 0u);
			sub_03D537(x, &y, &u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D440(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;

	y = 0x11u;
	*p_y = y;
	*p_u = u;
	sub_03D44D(x, p_y, p_u);
}

void sub_03D445(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;

	y = 0x401u;
	*p_y = y;
	*p_u = u;
	sub_03D44D(x, p_y, p_u);
}

void sub_03D44A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;

	y = 0x801u;
	*p_y = y;
	*p_u = u;
	sub_03D44D(x, p_y, p_u);
}

void sub_03D44D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	carry = sub_03C2CE(x, y);
	if (carry == 0u)
		sub_03D537(x, &y_2, &u);
	else
	{
		mem_write16(x + 0x1Cu, 0u);
		t1 = mem_read8(x + 0x43u);
		if (t1 != 0u)
			sub_03D27B(x, &y_2, &u);
		else
		{
			t2 = mem_read8(x + 0x30u);
			if (t2 == 1u)
				sub_03D285(x, &y_2, &u);
			else
			{
				t3 = mem_read8(x + 0x2Eu);
				if (t3 == 8u || stage_3_boss_follow_up_chances_by_players[(int8_t)unk_4857] < unk_4858)
					sub_03D285(x, &y_2, &u);
				else
				{
					y_2 = indexed_table_03DF32_ADDRESS;
					sub_03C2E5(x, y_2);
					y_2 = 0x800u;
					d = 0x8400u;
					sub_03C04C(x, y_2, d);
				}
			}
		}
	}
	*p_y = y_2;
	*p_u = u;
}

void sub_03D488(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		sub_03D537(x, &y, &u);
	else
	{
		t2 = mem_read8(x + 0x43u);
		if (t2 != 0u)
			sub_03D27B(x, &y, &u);
		else
			sub_03D285(x, &y, &u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D497(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;

	sub_03C0EB(x, &y, &carry);
	if (carry)
		sub_03D285(x, &y, &u);
	*p_y = y;
	*p_u = u;
}

void sub_03D49E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) != 0u)
		sub_03D285(x, &y, &u);
	*p_y = y;
	*p_u = u;
}

void sub_03D4A7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_03C0EB(x, &y, &carry);
	if (carry)
	{
		t1 = mem_read8(x + 0x1Bu);
		if (t1 != 0u)
			sub_03D285(x, &y, &u);
		else
		{
			t2 = mem_read16(x + 0x41u);
			t3 = mem_read8(t2 + 0x2Eu);
			if ((int8_t)t3 >= 0x13)
			{
				d = 0u;
				carry = sub_078680(d);
				d = 0x9800u;
				carry = sub_078689(d);
			}
			y = 0x133Cu;
			d = 0x8600u;
			sub_03C04C(x, y, d);
			mem_write8(x, 0x80u);
			mem_write16(x + 0x1Cu, 0u);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03D4DA(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 == 1u)
	{
		y_2 = 0x143Cu;
		mem_write16(x + 0x2Eu, 0x143Cu);
		return y_2;
	}
	return y;
}

uint16_t sub_03D4E7(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	carry = sub_03C2B5(x);
	if (carry == 0u)
		return y;
	mem_write8(x, 0u);
	t1 = mem_read16(x + 0x41u);
	y_2 = t1;
	if (mem_read8(y_2) != 0u)
		return y_2;
	d = 0x6000u;
	carry = sub_078680(d);
	t2 = io_read16(VIDEO_1852);
	y_2 = t2;
	mem_write8(y_2 + 0x2Au, 1u);
	unk_487D = 1u;
	unk_4804++;
	unk_4805 = 0x100u;
	return y_2;
}

void sub_03D51B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	carry = sub_03C021();
	if (carry == 0u)
		sub_03D537(x, &y, &u);
	else
	{
		t1 = mem_read8(x + 0x43u);
		if (t1 != 0u)
		{
			y = 0x1028u;
			d = 0x8B00u;
			sub_03C04C(x, y, d);
			sub_03D537(x, &y, &u);
		}
		else
		{
			y = 0x1028u;
			d = loaded_table_078000_ADDRESS;
			sub_03C04C(x, y, d);
			sub_03D537(x, &y, &u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D537(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t b = 0, d = 0;
	uint16_t d_2 = 0, u_2 = 0, x_2 = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t8 = 0, t9 = 0, t10 = 0, t14 = 0, t15 = 0;
	uint16_t t4 = 0, t5 = 0, t7 = 0, t11 = 0, t12 = 0, t13 = 0;

	sub_03C114(x, &y, &carry);
	b = (uint8_t)d;
	t1 = mem_read8(x + 0x40u);
	mem_write8(x + 0x40u, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x43u);
		if (t2 == 0u)
		{
			t3 = mem_read8(x + 0x30u);
			if (t3 == 0u)
			{
				sub_03D6AF(x, &u, &carry);
				b = (uint8_t)d;
				if (carry)
				{
					t4 = mem_read16(x + 0x41u);
					u = t4;
					t5 = mem_read16(u + 0x16u);
					b = (uint8_t)t5;
					if (t5 == 0u)
					{
						t6 = mem_read8(x + 0x3Au);
						if ((uint8_t)(0x64u - unk_4861 - unk_4861) <= t6)
						{
							mem_write8(x + 0x3Au, 0u);
							mem_write8(x, 0x80u);
							y_2 = 0x900u;
							d_2 = 0x8100u;
							sub_03C04C(x, y_2, d_2);
							stack = x;
							t7 = mem_read16(x + 0x41u);
							x_2 = t7;
							b = 0x80u;
							mem_write8(x_2, 0x80u);
							mem_write16(x_2 + 0x19u, 0u);
							y_2 = 0xA00u;
							d_2 = 0x8100u;
							sub_03C04C(x_2, y_2, d_2);
							x = stack;
						}
					}
				}
			}
		}
	}
	t8 = mem_read8(x + 0x3Au);
	if (t8 != 0xFFu)
	{
		t9 = mem_read8(x + 0x3Au);
		mem_write8(x + 0x3Au, t9 + 1u);
	}
	y_2 = indexed_table_03DF3D_ADDRESS;
	d_2 = b;
	sub_03C260(x, y_2, &u, &zero, &negative);
	if (zero == 0u)
	{
		mem_write8(x + 0x40u, 0x10u);
		t10 = mem_read8(x + 0x43u);
		if (t10 != 0u)
		{
			t11 = mem_read16(x + 0xCu);
			t12 = mem_read16(x + 0x11u);
			stack = x;
			t13 = mem_read16(x + 0x41u);
			x_2 = t13;
			mem_write16(x_2 + 0xCu, t11);
			mem_write16(x_2 + 0x11u, t12);
			mem_write16(x_2 + 0x16u, 0x24u);
			mem_write8(x_2, 0x80u);
			y_2 = 0x1200u;
			d_2 |= 0x8500u;
			sub_03C04C(x_2, y_2, d_2);
			u_2 = 0x700u;
			y_2 = 0x200u;
			sub_03C078(x_2, &y_2, &u_2);
			sub_03C0EB(x_2, &y_2, &carry);
			mem_write8(x_2 + 0x43u, 0u);
			x = stack;
			mem_write8(x + 0x43u, 0u);
			y_2 = 0x1200u;
			d_2 = (d_2 & 0xFFu) | 0x8500u;
			sub_03C04C(x, y_2, d_2);
			u = 0x500u;
			y_2 = 0x380u;
			sub_03C078(x, &y_2, &u);
			mem_write8(x + 0x17u, 1u);
			sub_03C0EB(x, &y_2, &carry);
		}
		else
		{
			t14 = mem_read8(x + 0x1Bu);
			if (t14 == 0u)
			{
				y_2 = 0x1200u;
				d_2 = (d_2 & 0xFFu) | 0x8500u;
				sub_03C04C(x, y_2, d_2);
				u = 0x500u;
				y_2 = 0x380u;
				sub_03C078(x, &y_2, &u);
				mem_write8(x + 0x17u, 1u);
				sub_03C0EB(x, &y_2, &carry);
			}
			else
			{
				t15 = mem_read8(x + 0x1Eu);
				if (t15 >= 0x12u)
				{
					y_2 = 0x1200u;
					d_2 = (d_2 & 0xFFu) | 0x8500u;
					sub_03C04C(x, y_2, d_2);
					u = 0x500u;
					y_2 = 0x380u;
					sub_03C078(x, &y_2, &u);
					mem_write8(x + 0x17u, 1u);
					sub_03C0EB(x, &y_2, &carry);
				}
				else
				{
					y_2 = 0x1100u;
					d_2 |= 0x8500u;
					sub_03C04C(x, y_2, d_2);
				}
			}
		}
	}
	*p_y = y_2;
	*p_u = u;
}

void sub_03D60F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;

	*p_y = y;
	*p_u = u;
	sub_03D63F(x, p_y, p_u);
}

void sub_03D612(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t d = 0, ignored16 = 0, u = 0, x_2 = 0, y = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	sub_03D63F(x, &y, &ignored16);
	t1 = mem_read16(x + 0x41u);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	d = t2 - 0xAu;
	t3 = mem_read16(u + 0xCu);
	if ((int16_t)d < (int16_t)t3)
	{
		t4 = mem_read16(u + 0xCu);
		if ((int16_t)t4 < (int16_t)(d + 0x14u))
		{
			t5 = mem_read16(x + 0x11u);
			d = t5 - 0xAu;
			t6 = mem_read16(u + 0x11u);
			if ((int16_t)d < (int16_t)t6)
			{
				d += 0x14u;
				t7 = mem_read16(u + 0x11u);
				if ((int16_t)t7 <= (int16_t)d)
				{
					y = 0xB1Cu;
					d = (d & 0xFFu) | 0x8000u;
					sub_03C04C(x, y, d);
					t8 = mem_read16(x + 0x41u);
					x_2 = t8;
					mem_write16(x_2 + 0x19u, 0x700u);
					mem_write16(x_2 + 0x17u, 0x700u);
					y = VIDEO_0C00;
					d = 0x8200u;
					sub_03C04C(x_2, y, d);
				}
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_03D63F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	t1 = mem_read16(x + 0x41u);
	u = t1;
	d = sub_07861D(x, u);
	sub_03D6DC(x, d);
	t2 = mem_read8(x + 9u);
	a = t2 & 0xBFu;
	t3 = mem_read16(x + 0xFu);
	y = t3;
	if ((int16_t)t3 < 0)
		a |= 0x40u;
	mem_write8(x + 9u, a);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03D679(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;

	sub_03C0EB(x, &y, &carry);
	return y;
}

void sub_03D67C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read16(x + 0x41u);
	u_2 = t2;
	mem_write16(u_2 + 0x2Eu, 0xD00u);
	mem_write8(u_2 + 5u, 0x87u);
	mem_write16(u_2 + 0xFu, 0u);
	mem_write16(u_2 + 0x14u, 0u);
	mem_write16(u_2 + 0x19u, 0u);
	mem_write8(u_2, 0xC0u);
	mem_write8(x + 0x43u, 1u);
	mem_write8(u_2 + 0x43u, 1u);
	y_2 = indexed_table_03DF2E_ADDRESS;
	sub_03C2E5(x, y_2);
	*p_y = y_2;
	*p_u = u_2;
	sub_03D27B(x, p_y, p_u);
}

void sub_03D6AF(uint16_t x, uint16_t *p_u, uint32_t *p_carry)
{
	uint32_t carry = *p_carry;
	uint16_t u = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x41u);
	u = t1;
	t2 = mem_read8(u + 1u);
	if (t2 != 0x3Eu || mem_read8(u) == 0u)
		carry = 0u;
	else
	{
		t3 = mem_read8(u + 0x2Eu);
		if ((int8_t)t3 >= 0x13)
			carry = 0u;
		else
			carry = 1u;
	}
	*p_u = u;
	*p_carry = carry;
}

void sub_03D6C9(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		y += 4u;
		t2 = mem_read8(x + 0x43u);
		if (t2 != 0u)
			y += 4u;
	}
	sub_03C2E5(x, y);
}

void sub_03D6DC(uint16_t x, uint16_t d)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		y = indexed_table_03DF42_ADDRESS;
		sub_03C329(x, y, d);
		return;
	}
	y = indexed_table_03DF52_ADDRESS;
	sub_03C329(x, y, d);
}

uint16_t sub_03D702(uint16_t x, uint8_t d)
{
	uint8_t b = 0;
	uint16_t state_start = 0;
	uint16_t wait = 0;

	b = (uint8_t)d;
	state_start = object_f9_state_starts_ADDRESS;
	mem_write8(x + 0x2Eu, b);
	wait = (((uint32_t)STATE_START(state_start + (b & 0x7Fu) * 0x2u)->wait << 8u) | STATE_START(state_start + (b & 0x7Fu) * 0x2u)->animation);
	b = (uint8_t)wait;
	mem_write8(x + VIDEO_002F, ((wait & ~0xFFu) | b) >> 8);
	mem_write8(x + 5u, b);
	return state_start;
}

void sub_03D708(uint16_t x)
{
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write8(x + 4u, 0xB9u);
	mem_write8(x + 0x42u, 0xFFu);
	mem_write8(x + 0x57u, 0xFFu);
	mem_write8(x + 0x1Bu, 8u);
	t1 = unk_48AC;
	t2 = t1 + 0x60u;
	t3 = mem_read16(x + 0xCu);
	t4 = t2 + t3;
	mem_write16(x + 0x33u, t4);
	mem_write8(x + 0x2Eu, 1u);
}

uint16_t sub_03D72C(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;

	unk_48F8 = 0x30u;
	unk_48FA = 0x10u;
	sub_03C1DC(x, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		mem_write8(x, 0x80u);
		d = 2u;
		return sub_03D702(x, d);
	}
	return y;
}

uint16_t sub_03D748(uint16_t x, uint16_t y)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0;
	uint8_t t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = unk_48AC;
	t2 = mem_read16(x + 0xCu);
	t3 = t1 + t2;
	t4 = mem_read16(x + 0x33u);
	if ((int16_t)t4 < (int16_t)t3)
		mem_write16(x + 0xFu, 0u);
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((uint8_t)(a + 1u) == 0u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
	}
	t5 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t5 - 1u);
	if (t5 != 1u)
		return y;
	mem_write8(x, 0x80u);
	d = 0xE00u;
	carry = sub_078680(d);
	mem_write8(x + 0x32u, 0u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	d_2 = 3u;
	return sub_03D702(x, d_2);
}

uint16_t sub_03D781(uint16_t x, uint16_t y)
{
	uint8_t d = 0;
	uint16_t y_2 = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	mem_write8(x, mem_read8(x) | 0x40u);
	d = 4u;
	sub_03D702(x, d);
	y_2 = indexed_table_03DF9A_ADDRESS;
	return sub_03C2E5(x, y_2);
}

uint16_t sub_03D79B(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0;
	uint8_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	stack = ((((uint32_t)(uint8_t)unk_4815 << 1) << 1) << 1) & 0x78u;
	t1 = mem_read8(x + 0xDu);
	if (((t1 - 0x40u) & 0x78u) != stack)
		return sub_03D86A(x);
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, t2 & 0xBFu);
	d = 0xAu;
	sub_03D702(x, d);
	d_2 = 0x2A01u;
	carry = sub_078680(d_2);
	t3 = mem_read8(x + 0x32u);
	mem_write8(x + 0x32u, t3 + 1u);
	return sub_03D86A(x);
}

uint16_t sub_03D7CA(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
		return sub_03D7D9(x);
	return sub_03D86A(x);
}

uint16_t sub_03D7D3(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03D86A(x);
	return sub_03D7D9(x);
}

uint16_t sub_03D7D9(uint16_t x)
{
	uint8_t d = 0;

	d = 6u;
	sub_03D702(x, d);
	mem_write8(x, mem_read8(x) | 0x40u);
	return sub_03D850(x);
}

uint16_t sub_03D7E9(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0;
	uint8_t t1 = 0;

	unk_48F8 = 0x40u;
	unk_48FA = 0x10u;
	sub_03C1DC(x, &ignored16, &ignored16_2, &carry);
	if (carry)
	{
		d = 7u;
		sub_03D702(x, d);
		if ((unk_4858 & 3u) == 0u)
			mem_write8(x + VIDEO_002F, 1u);
		return sub_03D850(x);
	}
	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03D850(x);
	return sub_03D800(x);
}

uint16_t sub_03D800(uint16_t x)
{
	uint8_t d = 0;

	d = 9u;
	sub_03D702(x, d);
	return sub_03D86A(x);
}

uint16_t sub_03D81C(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + VIDEO_002F);
	mem_write8(x + VIDEO_002F, t1 - 1u);
	if (t1 != 1u)
		return sub_03D86A(x);
	d = 0x1C00u;
	carry = sub_078680(d);
	sub_03C24E(x);
	d_2 = 8u;
	sub_03D702(x, d_2);
	y = indexed_table_03DF9E_ADDRESS;
	sub_03C2E5(x, y);
	sub_03C313(x);
	t2 = mem_read8(x + 0x32u);
	mem_write8(x + 0x32u, t2 + 1u);
	return sub_03D86A(x);
}

uint16_t sub_03D83F(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t b = 0, d = 0;
	uint16_t y = 0;

	y = 0x401u;
	carry = sub_03C2CE(x, y);
	if (carry == 0u)
		return sub_03D86A(x);
	mem_write16(x + 0x1Cu, 0u);
	b = 5u;
	d = b;
	sub_03D702(x, d);
	y = indexed_table_03DF9A_ADDRESS;
	return sub_03C2E5(x, y);
}

uint16_t sub_03D850(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t d_2 = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	carry = sub_03C021();
	if (carry)
		return sub_03D800(x);
	t1 = mem_read8(x + 0x32u);
	if (t1 <= 3u)
		return sub_03D86A(x);
	d = 0x1900u;
	carry = sub_078680(d);
	d_2 = 0xBu;
	sub_03D702(x, d_2);
	sub_03C24E(x);
	return sub_03D86A(x);
}

uint16_t sub_03D86A(uint16_t x)
{
	uint32_t zero = 0, negative = 0, carry = 0;
	uint8_t d = 0;
	uint16_t d_2 = 0, ignored16 = 0, y = 0;

	y = 0x7FA1u;
	sub_03C260(x, y, &ignored16, &zero, &negative);
	if (zero)
		return y;
	if (negative == 0u)
	{
		d = 0xCu;
		return sub_03D702(x, d);
	}
	d_2 = 0x1000u;
	carry = sub_078680(d_2);
	d = 0xDu;
	return sub_03D702(x, d);
}

uint16_t sub_03D884(uint16_t x, uint16_t y)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if (t1 & 1u)
		return sub_03D7D9(x);
	return y;
}

void sub_03D88C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return;
	mem_write8(x, 0u);
	sub_03C1D3(x);
}

uint16_t sub_03D899(uint16_t x, uint16_t y)
{
	uint8_t a = 0, d_2 = 0;
	uint16_t d = 0, u = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	if ((t1 & 1u) == 0u)
		return y;
	u = sub_03C17F();
	d = sub_07861D(x, u);
	a = (uint8_t)(d >> 8);
	d = ((uint32_t)a << 8) | 0x60u;
	sub_078617(x, d);
	mem_write8(x, 4u);
	d_2 = 0xEu;
	return sub_03D702(x, d_2);
}

void sub_03DC23(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 1u;
		mem_write8(x + 9u, mem_read8(t1));
		t2 = y_2;
		y = t2 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			continue;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03DC2B(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + 0x34u, mem_read8(t1));
	mem_write16(x + 0x32u, y_2);
	return y_2;
}

void sub_03DC34(uint16_t x)
{
	mem_write8(x, 0u);
}

void sub_03DC38(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 2u;
		t2 = mem_read16(t1);
		mem_write16(x + 4u, t2);
		t3 = y_2;
		y = t3 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t3) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			continue;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC40(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 1u;
		mem_write8(x + 5u, mem_read8(t1));
		t2 = y_2;
		y = t2 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			continue;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC48(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = y;
		mem_write16(x + 0xCu, mem_read16(t1));
		t2 = t1 + 2u;
		mem_write16(x + 0x11u, mem_read16(t2) + unk_48B2);
		t3 = t2 + 2u;
		y_2 = t3 + 2u;
		mem_write16(x + 0x16u, mem_read16(t3));
		t4 = y_2;
		y = t4 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			continue;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC5D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = y;
		mem_write16(x + 0xFu, mem_read16(t1));
		t2 = t1 + 2u;
		mem_write16(x + 0x14u, mem_read16(t2));
		t3 = t2 + 2u;
		y_2 = t3 + 2u;
		mem_write16(x + 0x19u, mem_read16(t3));
		t4 = y_2;
		y = t4 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			continue;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC6F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = y;
		mem_write16(x + 0x36u, mem_read16(t1));
		t2 = t1 + 2u;
		mem_write16(x + 0x38u, mem_read16(t2));
		t3 = t2 + 2u;
		y_2 = t3 + 2u;
		mem_write16(x + 0x3Au, mem_read16(t3));
		t4 = y_2;
		y = t4 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			continue;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC81(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		mem_write8(x, mem_read8(x) ^ 8u);
		t1 = y;
		y = t1 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t1) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			continue;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DC8C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 1u;
		mem_write8(x + 0x5Bu, mem_read8(t1));
		t2 = y_2;
		y = t2 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			continue;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03DC94(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 1u;
	mem_write8(x + VIDEO_003C, mem_read8(t1));
	mem_write16(x + 0x32u, y_2);
	return y_2;
}

void sub_03DC9D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0, y_2 = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 2u;
		t2 = mem_read16(t1);
		d = (uint8_t)t2;
		a = (uint8_t)(t2 >> 8);
		t3 = mem_read8(x + 0x30u);
		if ((int8_t)t3 >= 0)
		{
			stack = y_2;
			d_2 = (d & 0xFFu) | ((uint32_t)a << 8);
			carry = sub_078680(d_2);
			y_2 = stack;
		}
		t4 = y_2;
		y = t4 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t4) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			continue;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DCAE(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0;
	uint16_t u = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0, t3 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 1u;
		a = mem_read8(t1);
		mem_write8(x + 0xAu, a);
		mem_write8(x + 0xBu, a);
		t2 = mem_read8(x + 0x3Du);
		mem_write8(x + 0x3Du, t2 ^ 0x10u);
		t3 = y_2;
		y = t3 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t3) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			continue;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DCC1(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0, y_2 = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = y;
		y_2 = t1 + 1u;
		mem_write8(x + 0x3Eu, mem_read8(t1));
		t2 = y_2;
		y = t2 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			continue;
		case 28:
			*p_y = y;
			*p_u = u;
			sub_03DCC9(x, p_y, p_u);
			return;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

void sub_03DCC9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 0x19u, 0u);
		mem_write16(x + 0x36u, 0u);
		mem_write16(x + 0x38u, 0u);
		mem_write16(x + 0x3Au, 0u);
		t1 = y;
		y = t1 + 1u;
		u = loaded_table_03DFAA_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t1) << 1))
		{
		case 0:
			*p_y = y;
			*p_u = u;
			sub_03DC23(x, p_y, p_u);
			return;
		case 2:
			y = sub_03DC2B(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 4:
			sub_03DC34(x);
			*p_y = y;
			*p_u = u;
			return;
		case 6:
			*p_y = y;
			*p_u = u;
			sub_03DC38(x, p_y, p_u);
			return;
		case 8:
			*p_y = y;
			*p_u = u;
			sub_03DC40(x, p_y, p_u);
			return;
		case 10:
			*p_y = y;
			*p_u = u;
			sub_03DC48(x, p_y, p_u);
			return;
		case 12:
			*p_y = y;
			*p_u = u;
			sub_03DC5D(x, p_y, p_u);
			return;
		case 14:
			*p_y = y;
			*p_u = u;
			sub_03DC6F(x, p_y, p_u);
			return;
		case 16:
			*p_y = y;
			*p_u = u;
			sub_03DC81(x, p_y, p_u);
			return;
		case 18:
			*p_y = y;
			*p_u = u;
			sub_03DC8C(x, p_y, p_u);
			return;
		case 20:
			y = sub_03DC94(x, y);
			*p_y = y;
			*p_u = u;
			return;
		case 22:
			*p_y = y;
			*p_u = u;
			sub_03DC9D(x, p_y, p_u);
			return;
		case 24:
			*p_y = y;
			*p_u = u;
			sub_03DCAE(x, p_y, p_u);
			return;
		case 26:
			*p_y = y;
			*p_u = u;
			sub_03DCC1(x, p_y, p_u);
			return;
		case 28:
			continue;
		case 30:
			break;
		}
		break;
	}
	y = sub_03DCDE(x, y);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_03DCDE(uint16_t x, uint16_t y)
{
	uint16_t y_2 = 0;
	uint16_t t1 = 0;

	t1 = y;
	y_2 = t1 + 2u;
	mem_write16(x + 0x42u, mem_read16(t1));
	mem_write16(x + 0x32u, y_2);
	return y_2;
}
