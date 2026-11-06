/**
 *    Name:        unsorted/bank_16.c
 *    Description: bank 16's code
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

void sub_02C000(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_02DDDB_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02CE41(x, &y, &u);
		break;
	case 2:
		sub_02CE65();
		break;
	case -8:
		u = sub_02CBD6(x, u);
		break;
	case -6:
		sub_02CBF6(x);
		break;
	case -4:
		sub_02CC0C(x, &y, &u);
		break;
	case -2:
		sub_02CC42(x);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x1F0u)
		mem_write8(x, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_02C003(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DC1E_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C3FF(x, &y, &u);
		break;
	case 2:
		sub_02C442(x);
		break;
	case 4:
		sub_02C44C(x, &y, &u);
		break;
	case 6:
		sub_02C47A(x);
		break;
	case 8:
		sub_02C43B();
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C006(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_02DC71_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
	case 18:
		sub_02C553(x, &y, &u);
		break;
	case 2:
		u = sub_02C4AA(x);
		break;
	case 4:
		sub_02C4BE(x);
		break;
	case 6:
	case 24:
		y = sub_02C5EB(x);
		break;
	case 8:
	case 26:
		sub_02C60B(x);
		break;
	case 10:
	case 28:
		sub_02C628(x);
		break;
	case 12:
	case 30:
		sub_02C637(x);
		break;
	case -4:
	case 14:
		sub_02C585(x, &y, &u);
		break;
	case -2:
	case 16:
		sub_02C5A7(x, &y, &u);
		break;
	case 20:
		u = sub_02C5BF(x);
		break;
	case 22:
		sub_02C5D1(x);
		break;
	}
	u = sub_078593(x, u);
	sub_02C4D6(x);
	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		t2 = t1 - 0x10u;
		if (t2 >= 0x1A0u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C009(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C9E7(x, &y, &ignored16);
		break;
	case 2:
		sub_02CA3A(x);
		break;
	case 4:
		sub_02CA5B(x, &y, &ignored16);
		break;
	case 6:
		sub_02CA9A(x);
		break;
	case 8:
		sub_02C9B9(x, &y, &ignored16);
		break;
	case 10:
		sub_02C9C3(x, &y, &ignored16);
		break;
	case 12:
		sub_02C9D5(x, &y, &ignored16);
		break;
	case 14:
		sub_02C9E6();
		break;
	}
	u = loaded_table_02DD45_ADDRESS;
	t1 = mem_read8(x + 0x37u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02C9B9(x, &y, &u);
		break;
	case 2:
		sub_02C9C3(x, &y, &u);
		break;
	case 4:
		sub_02C9D5(x, &y, &u);
		break;
	case 6:
		sub_02C9E6();
		break;
	case -8:
		sub_02C9E7(x, &y, &u);
		break;
	case -6:
		sub_02CA3A(x);
		break;
	case -4:
		sub_02CA5B(x, &y, &u);
		break;
	case -2:
		sub_02CA9A(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02C00C(uint16_t x, uint32_t y, uint8_t d)
{
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DD2F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C955(x, &ignored16, &u);
		break;
	case 2:
		sub_02C970(x);
		break;
	case 4:
		sub_02C97F(x);
		break;
	case 6:
		sub_02C987();
		break;
	}
	carry = sub_078683(x, carry);
	return u;
}

void sub_02C00F(uint16_t x, uint32_t carry, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	carry = sub_078683(x, carry);
	if (carry)
	{
		u = loaded_table_02DD9F_ADDRESS;
		t1 = mem_read8(x + 2u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02CB7D(x, &y, &u, p_left_caller);
			break;
		case 2:
			sub_02CD2B(x, &y, &u, p_left_caller);
			break;
		case 4:
			sub_02CD43();
			break;
		case 6:
			u = sub_02CD44(x);
			break;
		case 8:
			y = sub_02CD50(x, y);
			break;
		case 10:
			sub_02CD7B(x);
			break;
		case 12:
			u = sub_02CD9A(x);
			break;
		case 14:
			y = sub_02CDBF(x, y);
			break;
		case 16:
			sub_02CDD4(x);
			break;
		case -4:
			sub_02CBCD(x, &y, &u);
			break;
		case -2:
			sub_02CC00(x, &y, &u);
			break;
		}
		t2 = mem_read8(x + 2u);
		a = t2;
		if ((int8_t)t2 >= 0 && a < 4u)
		{
			u = sub_078593(x, u);
			t3 = mem_read8(x + 2u);
			if ((int8_t)t3 < 0)
			{
				t4 = mem_read8(x + 0x27u);
				unk_48F0 = t4 & 0x30u;
				t5 = mem_read8(x + 0x5Bu);
				mem_write8(x + 0x5Bu, (t5 & 0xCFu) | unk_48F0);
			}
		}
		u = sub_02CB0C(x, u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C012(uint16_t x, uint32_t carry, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	carry = sub_078683(x, carry);
	if (carry)
	{
		u = loaded_table_02DCA5_ADDRESS;
		t1 = mem_read8(x + 2u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02C6C5(x, &y, &u);
			break;
		case 2:
		case 4:
			sub_02C6DF();
			break;
		case 6:
			sub_02C6E0(x);
			break;
		case 8:
			y = sub_02C6F0(x);
			break;
		case 10:
			sub_02C70D(x);
			break;
		case 12:
			sub_02C710(x, &y, &u);
			break;
		case 14:
			sub_02C74D(x);
			break;
		case 16:
			sub_02C6A4(x);
			break;
		case 18:
			sub_02C6BB(x);
			break;
		case -14:
		case -8:
			sub_02C58E(x);
			break;
		case -12:
		case -6:
			sub_02C59D(x);
			break;
		case -10:
			sub_02C5B0(x);
			break;
		case -4:
		case -2:
			sub_02C69B(x, &y, &u);
			break;
		}
		t2 = mem_read8(x + 2u);
		if ((int8_t)t2 >= 0)
		{
			t3 = mem_read8(x + 2u);
			if (t3 > 2u)
			{
				u = sub_078593(x, u);
				sub_02C683(x);
			}
		}
		u = sub_02CB0C(x, u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C015(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t ignored16 = 0, u = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C820(x, &y, &ignored16);
		break;
	case 2:
	case 94:
		sub_02C8C8();
		break;
	case 4:
		sub_02C8AE(x);
		break;
	case 6:
		sub_02C86F(x, &y, &ignored16);
		break;
	case 8:
		y = sub_02C8DE(x);
		break;
	case 10:
		sub_02C8FC(x, &y, &ignored16);
		break;
	case 12:
		sub_02C923(x);
		break;
	case 14:
		sub_02C93B(x);
		break;
	case 16:
		sub_02C775(x, &y, &ignored16);
		break;
	case 18:
		sub_02C77E(x, &y, &ignored16);
		break;
	case 20:
		sub_02C78F(x, &y, &ignored16);
		break;
	case 22:
		sub_02C7A0(x, &y, &ignored16);
		break;
	case 24:
		sub_02C7B1(x, &y, &ignored16);
		break;
	case 26:
		sub_02C7C6();
		break;
	}
	u = loaded_table_02DCD1_ADDRESS;
	t1 = mem_read8(x + 0x37u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02C77E(x, &y, &u);
		break;
	case 2:
		sub_02C78F(x, &y, &u);
		break;
	case 4:
		sub_02C7A0(x, &y, &u);
		break;
	case 6:
		sub_02C7B1(x, &y, &u);
		break;
	case 8:
		sub_02C7C6();
		break;
	case -16:
	case 76:
		sub_02C8C8();
		break;
	case -18:
		sub_02C820(x, &y, &u);
		break;
	case -14:
		u = sub_02C8AE(x);
		break;
	case -12:
		sub_02C86F(x, &y, &u);
		break;
	case -10:
		y = sub_02C8DE(x);
		break;
	case -8:
		sub_02C8FC(x, &y, &u);
		break;
	case -6:
		sub_02C923(x);
		break;
	case -4:
		sub_02C93B(x);
		break;
	case -2:
		sub_02C775(x, &y, &u);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C018(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DE11_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D098(x, &y, &u);
		break;
	case 2:
		sub_02D0CB(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C01B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DE35_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D183(x, &y, &u);
		break;
	case 2:
		sub_02D182();
		break;
	case -6:
		sub_02D2DA(x, &y, &u);
		break;
	case -4:
		sub_02D26C(x, &y, &u);
		break;
	case -2:
		sub_02D305(x, &y, &u);
		break;
	}
	u = sub_078593(x, u);
	u = sub_02D15A(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C01E(uint16_t x, uint32_t carry, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	carry = sub_078683(x, carry);
	if (carry)
	{
		u = loaded_table_02DBB2_ADDRESS;
		t1 = mem_read8(x + 2u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02C16A(x, &y, &u, p_left_caller);
			break;
		case 2:
			sub_02C190();
			break;
		case 4:
		case 6:
			sub_02C1AC(x, &y, &u, p_left_caller);
			break;
		case 8:
			sub_02C6C5(x, &y, &u);
			break;
		case 10:
			sub_02C1DF(x);
			break;
		case 12:
			sub_02C1E9();
			break;
		case 14:
			sub_02C6E0(x);
			break;
		case 16:
			y = sub_02C1EA(x);
			break;
		case 18:
			sub_02C70D(x);
			break;
		case 20:
			sub_02C710(x, &y, &u);
			break;
		case 22:
			y = sub_02C207(x, y);
			break;
		case 24:
			sub_02C22A(x);
			break;
		case 26:
			y = sub_02C1B5(x);
			break;
		case 28:
			sub_02C1D5(x);
			break;
		case 30:
			sub_02C23F(x, &y, &u);
			break;
		case 32:
			sub_02C277(x);
			break;
		case 34:
			sub_02C29A(x);
			break;
		case 36:
			sub_02C2B8(x);
			break;
		case 38:
			sub_02C2CA(x);
			break;
		case 40:
			sub_02C2D8();
			break;
		case -4:
			sub_02CBCD(x, &y, &u);
			break;
		case -2:
			sub_02CC00(x, &y, &u);
			break;
		}
		u = sub_078593(x, u);
		t2 = mem_read8(x + 2u);
		a = t2;
		if ((int8_t)t2 < 0)
		{
			if (a == 0xFFu && (unk_4815 & 0x1Fu) == 0u)
			{
				d = 0x6500u;
				carry = sub_078680(d);
			}
			t3 = mem_read8(x + 0x27u);
			unk_48F0 = t3 & 0x30u;
			t4 = mem_read8(x + 0x5Bu);
			mem_write8(x + 0x5Bu, (t4 & 0xCFu) | unk_48F0);
		}
		u = sub_02CB0C(x, u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C021(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t d_2 = 0, u = 0;
	uint8_t t4 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t6 = 0;

	u = loaded_table_02DFC1_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)d << 1))
	{
	case 0:
		sub_02D86A(x, &y, &u);
		break;
	case 2:
		sub_02D8B4(x);
		break;
	case 4:
		sub_02D8CA(x);
		break;
	case 6:
		u = sub_02D913(x);
		break;
	case 8:
		u = sub_02D935(x);
		break;
	case 10:
		sub_02D96D(x);
		break;
	case 12:
		sub_02D983(x);
		break;
	case 14:
		sub_02D9A9(x);
		break;
	}
	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x1C0u)
	{
		t2 = mem_read16(x + 0xCu);
		t3 = mem_read16(x + 0x3Eu);
		d_2 = t2 + unk_48AC - t3;
		if ((uint16_t)(d_2 >> 15 ? 0u - d_2 : d_2) < 0x34u)
			mem_write8(x + VIDEO_0031, 0u);
		else
		{
			t4 = mem_read8(x + VIDEO_0031);
			if (t4 == 0u)
			{
				t5 = mem_read8(x + VIDEO_0031);
				mem_write8(x + VIDEO_0031, t5 + 1u);
				t6 = mem_read16(x + 0xFu);
				mem_write16(x + 0xFu, 0u - t6);
				sub_0785C6(x);
			}
		}
	}
	else
		mem_write8(x, 0u);
	*p_y = y;
	*p_u = u;
}

void sub_02C024(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DFE5_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02DA0A(x, &y, &u);
		break;
	case 2:
		sub_02DA13();
		break;
	case 4:
		sub_02D9E8(x);
		break;
	case 6:
		sub_02D9F6(x);
		break;
	case -6:
		sub_02D9F5();
		break;
	case -4:
		sub_02D9C6(x);
		break;
	case -2:
		sub_02D9DF(x, &y, &u);
		break;
	}
	u = sub_078593(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C027(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DFAB_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D7B0(x, &y, &u);
		break;
	case 2:
		u = sub_02D7BD(x, u);
		break;
	case 4:
		sub_02D7D6();
		break;
	case 6:
		y = sub_02D7D7(x);
		break;
	case 8:
		y = sub_02D7FA(x, y);
		break;
	case 10:
		sub_02D80F(x);
		break;
	case 12:
		sub_02D81D(x);
		break;
	case 14:
		sub_02D82C(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C02A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_02DBBA_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C6C5(x, &y, &u);
		break;
	case 2:
		sub_02C1DF(x);
		break;
	case 4:
		sub_02C1E9();
		break;
	case 6:
		sub_02C6E0(x);
		break;
	case 8:
		y = sub_02C1EA(x);
		break;
	case 10:
		sub_02C70D(x);
		break;
	case 12:
		sub_02C710(x, &y, &u);
		break;
	case 14:
		y = sub_02C207(x, y);
		break;
	case 16:
		sub_02C22A(x);
		break;
	case 18:
		y = sub_02C1B5(x);
		break;
	case 20:
		sub_02C1D5(x);
		break;
	case 22:
		sub_02C23F(x, &y, &u);
		break;
	case 24:
		sub_02C277(x);
		break;
	case 26:
		sub_02C29A(x);
		break;
	case 28:
		sub_02C2B8(x);
		break;
	case 30:
		sub_02C2CA(x);
		break;
	case 32:
		sub_02C2D8();
		break;
	case -12:
		sub_02CBCD(x, &y, &u);
		break;
	case -10:
		sub_02CC00(x, &y, &u);
		break;
	case -8:
		sub_02C16A(x, &y, &u, p_left_caller);
		break;
	case -6:
		sub_02C190();
		break;
	case -4:
	case -2:
		sub_02C1AC(x, &y, &u, p_left_caller);
		break;
	}
	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 >= 0)
	{
		t2 = mem_read8(x + 2u);
		if (t2 > 2u)
		{
			u = sub_078593(x, u);
			sub_02C683(x);
		}
	}
	u = sub_02CB0C(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02C02D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DB44_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C0C9(x, &y, &u);
		break;
	case 2:
		sub_02C10F(x, &u, p_left_caller);
		break;
	case 4:
		u = sub_02C120(x, u);
		break;
	case 6:
		sub_02C12B();
		break;
	case 8:
		sub_02C078(x, &y, &u);
		break;
	case 10:
		sub_02C0B4(x);
		break;
	case 12:
		sub_02C0BD(x);
		break;
	case -4:
	case -2:
		sub_02C06F(x, &y, &u, p_left_caller);
		break;
	}
	u = sub_078593(x, u);
	sub_078674(x);
	u = sub_078593(x, u);
	*p_y = y;
	*p_u = u;
}

void sub_02C036(void)
{
}

void sub_02C039(void)
{
}

void sub_02C03C(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = hit_box_02DF75_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D69B(x, &y, &u);
		break;
	case 2:
		sub_02D6BB(x);
		break;
	case 4:
		sub_02D6D4(x);
		break;
	case 6:
		sub_02D6FD(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C03F(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = hit_box_02DF9B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D728(x, &y, &u);
		break;
	case 2:
		sub_02D76E(x);
		break;
	case 4:
		sub_02D790(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C042(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DC83_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case -18:
	case 0:
		sub_02C553(x, &y, &u);
		break;
	case 2:
		u = sub_02C5BF(x);
		break;
	case 4:
		sub_02C5D1(x);
		break;
	case -12:
	case 6:
		y = sub_02C5EB(x);
		break;
	case -10:
	case 8:
		sub_02C60B(x);
		break;
	case -8:
	case 10:
		sub_02C628(x);
		break;
	case -6:
	case 12:
		sub_02C637(x);
		break;
	case -22:
	case -4:
		sub_02C585(x, &y, &u);
		break;
	case -20:
	case -2:
		sub_02C5A7(x, &y, &u);
		break;
	case -16:
		u = sub_02C4AA(x);
		break;
	case -14:
		sub_02C4BE(x);
		break;
	}
	u = sub_078593(x, u);
	sub_02C4D6(x);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C045(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DBE2_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C2DF(x, &y, &u);
		break;
	case 2:
		sub_02C332(x);
		break;
	case 4:
		sub_02C340(x);
		break;
	case 6:
		sub_02C35F(x, &y, &u);
		break;
	case 8:
		sub_02C37D();
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C048(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DBD0_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02C23F(x, &y, &u);
		break;
	case 2:
		sub_02C277(x);
		break;
	case 4:
		sub_02C29A(x);
		break;
	case 6:
		sub_02C2B8(x);
		break;
	case 8:
		sub_02C2CA(x);
		break;
	case 10:
		sub_02C2D8();
		break;
	case -34:
		sub_02CBCD(x, &y, &u);
		break;
	case -32:
		sub_02CC00(x, &y, &u);
		break;
	case -30:
		sub_02C16A(x, &y, &u, p_left_caller);
		break;
	case -28:
		sub_02C190();
		break;
	case -26:
	case -24:
		sub_02C1AC(x, &y, &u, p_left_caller);
		break;
	case -22:
		sub_02C6C5(x, &y, &u);
		break;
	case -20:
		sub_02C1DF(x);
		break;
	case -18:
		sub_02C1E9();
		break;
	case -16:
		sub_02C6E0(x);
		break;
	case -14:
		y = sub_02C1EA(x);
		break;
	case -12:
		sub_02C70D(x);
		break;
	case -10:
		sub_02C710(x, &y, &u);
		break;
	case -8:
		y = sub_02C207(x, y);
		break;
	case -6:
		sub_02C22A(x);
		break;
	case -4:
		y = sub_02C1B5(x);
		break;
	case -2:
		sub_02C1D5(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C04B(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0;

	b = (uint8_t)d;
	u = loaded_table_02DEE1_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D437(x, &y, &u);
		break;
	case 2:
		sub_02D494(x);
		break;
	case 4:
		sub_02D4B5(x);
		break;
	case 6:
		sub_02D4EB(x);
		break;
	case 8:
		y = sub_02D503(x);
		break;
	case 10:
		sub_02D52E(x);
		break;
	case 12:
		sub_02D531(x);
		break;
	case 14:
		sub_02D4EA();
		break;
	case 16:
		sub_02D38E(x);
		break;
	case 18:
		sub_02D3B4(x);
		break;
	case 20:
		sub_02D3E6(x);
		break;
	case 22:
		sub_02D436();
		break;
	case -4:
	case -2:
		sub_02D385(x, &y, &u);
		break;
	}
	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 < 0)
	{
		carry = sub_078683(x, carry);
		*p_y = y;
		*p_u = u;
		return;
	}
	sub_0785C6(x);
	u = sub_02CB0C(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C04E(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DE05_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D043(x, &y, &u);
		break;
	case 2:
		sub_02D06E(x);
		break;
	case 4:
		sub_02D088(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C051(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DDE5_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02CE6F(x, &y, &u);
		break;
	case 2:
		sub_02CEB3(x);
		break;
	case 4:
		sub_02CF01(x);
		break;
	case 6:
		sub_02CF65(x);
		break;
	case 8:
		sub_02CFF4(x);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C054(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DF15_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D55C(x, &y, &u);
		break;
	case 2:
	case 4:
		sub_02D56D();
		break;
	case 6:
		sub_02D56E(x);
		break;
	case 8:
		y = sub_02D58A(x);
		break;
	case 10:
		sub_02D5AA(x);
		break;
	case 12:
		sub_02C710(x, &y, &u);
		break;
	case 14:
		sub_02C74D(x);
		break;
	case -4:
	case -2:
		sub_02C69B(x, &y, &u);
		break;
	}
	u = sub_02CB0C(x, u);
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C05A(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint32_t carry = 0;
	uint8_t b = 0;
	uint16_t u = 0;

	b = (uint8_t)d;
	u = loaded_table_02DE1B_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D0E5(x, &y, &u);
		break;
	case 2:
		u = sub_02D103(x);
		break;
	case 4:
		sub_02D116(x);
		break;
	case 6:
		sub_02D12D(x, &y, &u);
		break;
	}
	carry = sub_078683(x, carry);
	*p_y = y;
	*p_u = u;
}

void sub_02C05D(uint16_t x, uint8_t d, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t b = 0;
	uint16_t u = 0;
	uint16_t t1 = 0, t2 = 0;

	b = (uint8_t)d;
	u = loaded_table_02DF2F_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)b << 1))
	{
	case 0:
		sub_02D5E2(x, &y, &u);
		break;
	case 2:
		sub_02D61A(x, &y, &u);
		break;
	case 4:
		sub_02D619();
		break;
	case 6:
		sub_02D683(x);
		break;
	case 8:
		y = sub_02CD50(x, y);
		break;
	case 10:
		sub_02CD7B(x);
		break;
	case 12:
		u = sub_02CD9A(x);
		break;
	case 14:
		y = sub_02CDBF(x, y);
		break;
	case 16:
		sub_02CDD4(x);
		break;
	case -4:
		sub_02CBCD(x, &y, &u);
		break;
	case -2:
		sub_02CC00(x, &y, &u);
		break;
	}
	u = sub_02CB0C(x, u);
	if (mem_read8(x) != 0u)
	{
		t1 = mem_read16(x + 0xCu);
		t2 = t1 - 0x40u;
		if (t2 >= 0x1C0u)
			mem_write8(x, 0u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C06F(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02DB4C_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02C078(x, &y, &u);
			break;
		case 2:
			sub_02C0B4(x);
			break;
		case 4:
			sub_02C0BD(x);
			break;
		case -12:
		case -10:
			continue;
		case -8:
			sub_02C0C9(x, &y, &u);
			break;
		case -6:
			sub_02C10F(x, &u, p_left_caller);
			break;
		case -4:
			u = sub_02C120(x, u);
			break;
		case -2:
			sub_02C12B();
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C078(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	y = child_object_02DB52_ADDRESS;
	sub_07862F(x, y, &ignored16, &carry);
	d = 0x6C00u;
	carry = sub_078680(d);
	u = sub_02CCE8(x);
	t1 = mem_read8(x + 0x44u);
	if (t1 != 0u)
	{
		mem_write16(x + 0x19u, 0x800u);
		mem_write8(x + 4u, 9u);
		t2 = mem_read8(x + 0x30u);
		a = (t2 & 1u) << 1;
		mem_write8(x + 0x30u, a);
		mem_write8(x + 5u, a | 0x80u);
		mem_write8(x + 0x29u, 2u);
	}
	else
	{
		mem_write8(x + 0x3Bu, 0x10u);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C0B4(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

void sub_02C0BD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
		mem_write16(x + 1u, 0x2700u);
}

void sub_02C0C9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t5 = 0;

	u = object_setup_02DBA8_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 - 2u;
	mem_write16(x + 0x11u, t2);
	mem_write8(x + 9u, 0x10u);
	t3 = mem_read8(x + 0x30u);
	mem_write8(x + 0x44u, DATA8(loaded_table_02DB68_ADDRESS + (uint8_t)((((((uint8_t)unk_49D4 + (uint8_t)unk_49DC + (uint8_t)unk_49E4 + (uint8_t)unk_49EC) & 7u) << 1) << 1) << 1) + (int8_t)t3));
	u = indexed_table_02DB58_ADDRESS;
	t4 = mem_read8(x + 0x30u);
	t5 = DATA16(indexed_table_02DB58_ADDRESS + (int8_t)((uint32_t)t4 << 1));
	mem_write16(x + 0xCu, t5);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C10F(uint16_t x, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	d = t1;
	if (d < 0x160u)
	{
		d = (d & 0xFFu) | 0x200u;
		sub_02CC4A(x, d, &u, p_left_caller);
		if (*p_left_caller == 0u)
		{
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
		}
	}
	*p_u = u;
}

uint16_t sub_02C120(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t1 = 0;

	if (unk_487D == 0u)
	{
		sub_02C12B();
		return u;
	}
	u_2 = sub_02CCE8(x);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02C12B();
	return u_2;
}

void sub_02C12B(void)
{
}

void sub_02C16A(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_02DDCD_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x1Du, 0u);
	t1 = mem_read8(x + 0x30u);
	a = t1 | 0x80u;
	mem_write8(x + 5u, a);
	mem_write8(x + 0x30u, a + 1u);
	t2 = mem_read16(x + 0x11u);
	t3 = t2 - 2u;
	d = (uint8_t)t3;
	mem_write16(x + 0x11u, ((uint32_t)(t3 >> 8) << 8) | (d & 0xFFu));
	d_2 = (d & 0xFFu) | 0x400u;
	sub_02CC4A(x, d_2, &u, p_left_caller);
	if (*p_left_caller == 0u)
	{
		t4 = mem_read8(x + 2u);
		mem_write8(x + 2u, t4 + 1u);
		sub_02C190();
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C190(void)
{
}

void sub_02C1AC(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02DBCC_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			y = sub_02C1B5(x);
			break;
		case 2:
			sub_02C1D5(x);
			break;
		case 4:
			sub_02C23F(x, &y, &u);
			break;
		case 6:
			sub_02C277(x);
			break;
		case 8:
			sub_02C29A(x);
			break;
		case 10:
			sub_02C2B8(x);
			break;
		case 12:
			sub_02C2CA(x);
			break;
		case 14:
			sub_02C2D8();
			break;
		case -30:
			sub_02CBCD(x, &y, &u);
			break;
		case -28:
			sub_02CC00(x, &y, &u);
			break;
		case -26:
			sub_02C16A(x, &y, &u, p_left_caller);
			break;
		case -24:
			sub_02C190();
			break;
		case -22:
		case -20:
			continue;
		case -18:
			sub_02C6C5(x, &y, &u);
			break;
		case -16:
			sub_02C1DF(x);
			break;
		case -14:
			sub_02C1E9();
			break;
		case -12:
			sub_02C6E0(x);
			break;
		case -10:
			y = sub_02C1EA(x);
			break;
		case -8:
			sub_02C70D(x);
			break;
		case -6:
			sub_02C710(x, &y, &u);
			break;
		case -4:
			y = sub_02C207(x, y);
			break;
		case -2:
			sub_02C22A(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02C1B5(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0;

	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write8(x, 0x80u);
	mem_write16(x + 0xFu, 0u);
	y = hit_box_02DAD8_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 4u, 0x9CA2u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
	sub_078674(x);
	return y;
}

void sub_02C1D5(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02C1DF(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		sub_02C1E9();
		return;
	}
	mem_write8(x + 2u, 7u);
	sub_02C1E9();
}

void sub_02C1E9(void)
{
}

uint16_t sub_02C1EA(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	y = hit_box_02DAD0_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_078674(x);
	return y;
}

uint16_t sub_02C207(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return y;
	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write8(x, 0xC0u);
	y = hit_box_02DAD8_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 4u, 0x9C8Au);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

void sub_02C22A(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02C23F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0;

	u = object_setup_02DBDC_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read16(x + 0xCu);
	t2 = t1 + 0x10u;
	mem_write16(x + 0xCu, t2);
	t3 = mem_read8(x + 6u);
	mem_write8(x + 6u, t3 | 0x80u);
	t4 = mem_read8(x + 0x30u);
	if (t4 != 0u)
	{
		t5 = mem_read8(x + 5u);
		mem_write8(x + 5u, (t5 + 1u) | 0x80u);
	}
	mem_write8(x, 0x80u);
	t6 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t6 & 0xCFu) | 0x20u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C277(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	if (unk_487D == 0u)
		return;
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
	{
		d = 0x1500u;
		carry = sub_078680(d);
	}
	mem_write16(x + 0x19u, 0x40u);
	mem_write8(x + 0x3Bu, 4u);
	mem_write8(x + VIDEO_003C, 8u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
}

void sub_02C29A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 4u);
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
		{
			mem_write8(x + 0x3Bu, 0x40u);
			mem_write16(x + 0x19u, 0x40u);
			t3 = mem_read8(x + 2u);
			mem_write8(x + 2u, t3 + 1u);
		}
	}
}

void sub_02C2B8(uint16_t x)
{
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 + 4u);
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 == 1u)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_02C2CA(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	if (t1 < 0x80u)
	{
		sub_02C2D8();
		return;
	}
	mem_write16(x + 0x19u, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02C2D8();
}

void sub_02C2D8(void)
{
}

void sub_02C2DF(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0;

	u = object_setup_02DBEC_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read16(x + 0xCu);
	t2 = t1 + 0x10u;
	mem_write16(x + 0xCu, t2);
	t3 = mem_read8(x + 6u);
	mem_write8(x + 6u, t3 | 0x80u);
	t4 = mem_read8(x + 0x30u);
	if (t4 == 0u)
	{
		t5 = mem_read8(x + 5u);
		mem_write8(x + 5u, (t5 - 1u) | 0x80u);
		sub_078650(x, &u, &d);
		a = (uint8_t)(d >> 8);
		mem_write16(x + 0x2Au, u);
		mem_write8(x + 0x33u, a);
		stack = u;
		b = (uint8_t)stack;
		unk_48F0 = b;
		mem_write16(x + 0x38u, ((uint32_t)(stack >> 8) << 8) | (b & 0xC0u));
	}
	mem_write16(x + 0x5Cu, 0u);
	t6 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t6 & 0xCFu) | 0x20u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C332(uint16_t x)
{
	uint8_t t1 = 0;

	if (unk_4892 == 0u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02C340(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	t2 = mem_read8(x + 0x30u);
	if (t2 == 0u)
	{
		d = 0x1300u;
		carry = sub_078680(d);
	}
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write16(x + 0x19u, 0xFF80u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_02C35F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		sub_02C37D();
	else
	{
		mem_write16(x + 0x19u, 0u);
		t2 = mem_read8(x + 0x30u);
		if (t2 == 0u)
		{
			t3 = mem_read8(x + 6u);
			mem_write8(x + 6u, t3 | 0x80u);
			t4 = io_read8(VIDEO_184A);
			io_write8(VIDEO_184A, t4 + 1u);
			sub_02C37E(x, &y, &u);
		}
		t5 = mem_read8(x + 2u);
		mem_write8(x + 2u, t5 + 1u);
		sub_02C37D();
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C37D(void)
{
}

void sub_02C37E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0, y = 0;
	uint8_t stack = 0;
	uint8_t t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;
	uint16_t t1 = 0, t2 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	unk_48F4 = 0x20u;
	t1 = mem_read16(x + 0x2Au);
	stack = t1;
	b = stack;
	mem_write8(x + 0x34u, b);
	b -= 5u;
	do
	{
		if (DATA8(indexed_table_02DBF2_ADDRESS + (int8_t)unk_48F4) != 0u)
			y = record_02DC12_ADDRESS;
		else
			y = record_02DC18_ADDRESS;
		t2 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t2 + b;
		mem_write8(u, DATA8(y));
		t3 = mem_read8(y + 1u);
		mem_write8(u + 0x40u, t3);
		t4 = mem_read8(y + 2u);
		mem_write8(u + 0x80u, t4);
		t5 = mem_read8(y + 3u);
		mem_write8(u + VIDEO_00C0, t5);
		t6 = mem_read8(y + 4u);
		mem_write8(u + 0x100u, t6);
		t7 = mem_read8(y + 5u);
		mem_write8(u + 0x140u, t7);
		b++;
		t8 = unk_48F4;
		unk_48F4 = t8 - 1u;
	} while (t8 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	*p_y = y;
	*p_u = u;
}

void sub_02C3FF(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t7 = 0;
	uint16_t t5 = 0, t6 = 0;

	u = object_setup_02DC28_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read8(x + 0x30u);
	u = loaded_table_02DC2E_ADDRESS + (int8_t)(((uint32_t)t2 << 1) << 1);
	t3 = io_read8(VIDEO_1874);
	if (t3 < DATA8(u))
		mem_write8(x + 2u, 4u);
	else
	{
		t4 = mem_read8(u + 1u);
		t5 = (uint32_t)t4 << 4;
		mem_write16(x + 0x3Eu, t5);
		t6 = mem_read16(u + 2u);
		mem_write8(x + 0x3Bu, t6 >> 8);
		mem_write8(x + 0x30u, t6);
		t7 = mem_read8(x + 2u);
		mem_write8(x + 2u, t7 + 1u);
		sub_02C43B();
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C43B(void)
{
}

void sub_02C442(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = io_read8(VIDEO_1884);
	if (t1 != 0u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02C44C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint8_t a = 0;
	uint16_t ignored16 = 0, u_2 = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 5u, 0x95u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	u_2 = indexed_table_02DC3E_ADDRESS;
	t3 = mem_read8(x + 0x30u);
	y_2 = DATA16(indexed_table_02DC3E_ADDRESS + (int8_t)((uint32_t)t3 << 1));
	for (;;)
	{
		t4 = y_2;
		y_2 = t4 + 1u;
		a = mem_read8(t4);
		if (a == 0x7Fu)
			break;
		t5 = io_read8(VIDEO_1874);
		if (a < t5)
			sub_07862C(x, y_2, &u_2, &ignored16, &carry);
		y_2 += 8u;
	}
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02C47A(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return;
	mem_write8(x, 0u);
	d = 0x2200u;
	carry = sub_078680(d);
}

uint16_t sub_02C4AA(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if (t2 == 4u)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
	}
	return u;
}

void sub_02C4BE(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0xC8u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_02C4D6(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t6 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	if (mem_read8(x) == 0u)
		return;
	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 < 0)
		return;
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	if ((int8_t)a < 0)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x, 0x80u);
		mem_write8(x + 0x28u, 0u);
		d = 0x6500u;
		carry = sub_078680(d);
		return;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t2 = mem_read16(x + 0x16u);
	t3 = mem_read16(x + 0x5Cu);
	if (t2 != t3)
		a = mem_read8(x) | 8u;
	else
		a = mem_read8(x) & ~8u;
	mem_write8(x, a);
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F1 = a;
	if (a == unk_48F0)
		return;
	if ((int8_t)a < 0)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x, 0x80u);
		mem_write8(x + 0x28u, 0u);
		d = 0x6500u;
		carry = sub_078680(d);
		return;
	}
	t4 = (unk_48F1 & 0xFu) << 3;
	t5 = mem_read16(x + 0x16u);
	if (t4 < t5)
	{
		unk_48F2 = unk_48F1 & 0x30u;
		t6 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t6 & 0xCFu) | unk_48F2);
		return;
	}
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write8(x + 2u, 0xFEu);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x28u, 0u);
	d = 0x6500u;
	carry = sub_078680(d);
}

void sub_02C553(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0;

	u = object_setup_02DC91_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x30u);
	a = t1 | 0x80u;
	mem_write8(x + 5u, a);
	mem_write8(x + 0x30u, a + 1u);
	t2 = mem_read16(x + 0x40u);
	u = t2;
	t3 = mem_read8(u + 9u);
	if ((t3 & 0x40u) != 0u)
	{
		t4 = mem_read8(x + 9u);
		mem_write8(x + 9u, t4 | 0x40u);
	}
	mem_write8(x + 0x3Bu, 8u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C585(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DC97_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
	case 6:
		sub_02C58E(x);
		break;
	case 2:
	case 8:
		sub_02C59D(x);
		break;
	case 4:
		sub_02C5B0(x);
		break;
	case 10:
	case 12:
		sub_02C69B(x, &y, &u);
		break;
	case 14:
		sub_02C6C5(x, &y, &u);
		break;
	case 16:
	case 18:
		sub_02C6DF();
		break;
	case 20:
		sub_02C6E0(x);
		break;
	case 22:
		y = sub_02C6F0(x);
		break;
	case 24:
		sub_02C70D(x);
		break;
	case 26:
		sub_02C710(x, &y, &u);
		break;
	case 28:
		sub_02C74D(x);
		break;
	case 30:
		sub_02C6A4(x);
		break;
	case 32:
		sub_02C6BB(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C58E(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0u);
	mem_write8(x + 5u, 0x80u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_02C59D(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02C5A7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DC9B_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02C5B0(x);
		break;
	case -4:
	case 2:
		sub_02C58E(x);
		break;
	case -2:
	case 4:
		sub_02C59D(x);
		break;
	case 6:
	case 8:
		sub_02C69B(x, &y, &u);
		break;
	case 10:
		sub_02C6C5(x, &y, &u);
		break;
	case 12:
	case 14:
		sub_02C6DF();
		break;
	case 16:
		sub_02C6E0(x);
		break;
	case 18:
		y = sub_02C6F0(x);
		break;
	case 20:
		sub_02C70D(x);
		break;
	case 22:
		sub_02C710(x, &y, &u);
		break;
	case 24:
		sub_02C74D(x);
		break;
	case 26:
		sub_02C6A4(x);
		break;
	case 28:
		sub_02C6BB(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C5B0(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = 0x6500u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

uint16_t sub_02C5BF(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 2u);
	if ((int8_t)t2 < 0)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
	}
	return u;
}

void sub_02C5D1(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC8u);
		mem_write16(x + 0xFu, 0xFD00u);
		mem_write16(x + 0x19u, 0x300u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_02C5EB(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	y = hit_box_02DAA8_ADDRESS;
	sub_0785B4(x, y);
	if (unk_4857 >= 3u)
		mem_write8(x + 0x1Cu, 0x10u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	return y;
}

void sub_02C60B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	mem_write16(x + 0x19u, 0x500u);
	mem_write8(x, mem_read8(x) | 8u);
	d = 0x6500u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_02C628(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	d = 0x6500u;
	carry = sub_078680(d);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void sub_02C637(uint16_t x)
{
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	t1 = mem_read16(x + 0x16u);
	t2 = mem_read16(x + 0x5Cu);
	if (t1 != t2)
	{
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 - 1u);
		mem_write8(x, mem_read8(x) | 8u);
	}
	t4 = mem_read16(x + 0xFu);
	if (t4 == 0u)
	{
		mem_write8(x + 2u, 0xFEu);
		mem_write8(x + 0x28u, 0u);
		mem_write8(x, 0x80u);
	}
}

void sub_02C683(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 2u);
	if (t1 == 5u && (mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
	}
}

void sub_02C69B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02DCB5_ADDRESS;
		t1 = mem_read8(x + 0x28u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02C6A4(x);
			break;
		case 2:
			sub_02C6BB(x);
			break;
		case -30:
		case -24:
			sub_02C58E(x);
			break;
		case -28:
		case -22:
			sub_02C59D(x);
			break;
		case -26:
			sub_02C5B0(x);
			break;
		case -20:
		case -18:
			continue;
		case -16:
			sub_02C6C5(x, &y, &u);
			break;
		case -14:
		case -12:
			sub_02C6DF();
			break;
		case -10:
			sub_02C6E0(x);
			break;
		case -8:
			y = sub_02C6F0(x);
			break;
		case -6:
			sub_02C70D(x);
			break;
		case -4:
			sub_02C710(x, &y, &u);
			break;
		case -2:
			sub_02C74D(x);
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02C6A4(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x19u, 0x80u);
	mem_write8(x + 5u, 0x80u);
	t1 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t1 + 1u);
}

void sub_02C6BB(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02C6C5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02DCB9_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x5Bu, 2u);
	t1 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t1 | 0x80u);
	t2 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t2 + 1u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C6DF(void)
{
}

void sub_02C6E0(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x3Du, 1u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 - 1u);
}

uint16_t sub_02C6F0(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	y = hit_box_02DAB8_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	sub_02C70D(x);
	return y;
}

void sub_02C70D(uint16_t x)
{
	sub_078674(x);
}

void sub_02C710(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0;
	uint16_t t1 = 0, t3 = 0;

	mem_write8(x, 0x88u);
	y = hit_box_02DAC0_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 0x19u, 0x600u);
	mem_write16(x + 0xFu, 0x100u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	if ((t2 & 0x40u) == 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t4 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t4 + 1u) | 0x80u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C74D(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint16_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 0u);
		return;
	}
	t1 = mem_read16(x + 0x19u);
	if ((int16_t)t1 < 0)
	{
		sub_078674(x);
		return;
	}
}

void sub_02C775(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	y = loaded_table_02DCE1_ADDRESS;
	sub_02C7C7(x, &y, &u);
	t1 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C77E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x1B0u)
		return;
	y_2 = loaded_table_02DCED_ADDRESS;
	sub_02C7C7(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02C78F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x190u)
		return;
	y_2 = loaded_table_02DCF9_ADDRESS;
	sub_02C7C7(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02C7A0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x170u)
		return;
	y_2 = loaded_table_02DD05_ADDRESS;
	sub_02C7C7(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02C7B1(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x150u)
	{
		sub_02C7C6();
		return;
	}
	y = loaded_table_02DD11_ADDRESS;
	sub_02C7C7(x, &y, &u);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	mem_write8(x + 2u, 2u);
	sub_02C7C6();
	*p_y = y;
	*p_u = u;
}

void sub_02C7C6(void)
{
}

void sub_02C7C7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t stack = 0;
	uint8_t t2 = 0, t4 = 0, t5 = 0, t6 = 0;
	uint16_t t1 = 0, t3 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t1 = mem_read16(x + 0x2Au);
	t2 = mem_read8(x + 0x37u);
	stack = t1 + (int8_t)(((uint32_t)t2 << 1) << 1);
	b = stack;
	mem_write8(x + 0x34u, b);
	b -= 3u;
	unk_48F4 = 4u;
	do
	{
		t3 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t3 + b;
		mem_write8(u - 0x40u, mem_read8(y));
		t4 = mem_read8(y + 4u);
		mem_write8(u, t4);
		t5 = mem_read8(y + 8u);
		mem_write8(u + 0x40u, t5);
		b++;
		y++;
		t6 = unk_48F4;
		unk_48F4 = t6 - 1u;
	} while (t6 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	*p_y = y;
	*p_u = u;
}

void sub_02C820(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t4 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02DCDB_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 0x5Bu, 0x40u);
	mem_write8(x + 0x3Du, 0x40u);
	mem_write16(x + 0xCu, 0x1BFu);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 - 2u;
	mem_write16(x + 0x11u, t2);
	sub_078650(x, &u, &d);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x33u, a);
	stack = u;
	b = (uint8_t)stack;
	unk_48F0 = b;
	mem_write16(x + 0x38u, ((uint32_t)(stack >> 8) << 8) | (b & 0xC0u));
	unk_48F0 = (unk_48F0 - 2u) & 0x3Fu;
	t3 = mem_read16(x + 0x38u);
	stack_10001 = t3 >> 8;
	stack_10002 = t3 | unk_48F0;
	u = ((uint32_t)stack_10001 << 8) | stack_10002;
	mem_write16(x + 0x2Au, u);
	mem_write8(x + 0x37u, 0xFFu);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C86F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, b = 0;
	uint16_t u_2 = 0;
	uint16_t stack = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t6 = 0;
	uint16_t t3 = 0, t5 = 0;

	t1 = mem_read8(x + 0x3Du);
	if (t1 == 0u)
	{
		mem_write8(x + 2u, 5u);
		*p_y = y;
		*p_u = u;
		sub_02C8FC(x, p_y, p_u);
		return;
	}
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 - 1u);
	mem_write8(x + 0x28u, 0u);
	mem_write8(x + 0x1Du, 0u);
	t3 = mem_read16(x + 0x2Au);
	stack = t3;
	b = (uint8_t)stack;
	mem_write8(x + 0x34u, b);
	b -= 7u;
	unk_48F4 = 0x14u;
	t4 = mem_read8(x + 0x33u);
	a = t4;
	do
	{
		t5 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u_2 = t5 + b;
		mem_write8(u_2 - 0x40u, a);
		mem_write8(u_2, a);
		mem_write8(u_2 + 0x40u, a);
		b++;
		t6 = unk_48F4;
		unk_48F4 = t6 - 1u;
	} while (t6 != 1u);
	u_2 = sub_02C8AE(x);
	*p_y = y;
	*p_u = u_2;
}

uint16_t sub_02C8AE(uint16_t x)
{
	uint16_t u = 0;

	u = sub_02C8B1(x);
	return u;
}

uint16_t sub_02C8B1(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DD1D_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case -92:
	case 0:
		sub_02C8C8();
		return u;
	case 2:
		sub_02C8BA(x);
		return u;
	case 4:
		sub_02C8C9(x);
		return u;
	}
	unreachable();
}

void sub_02C8BA(uint16_t x)
{
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x5Cu);
	mem_write16(x + 0x16u, t1);
	mem_write8(x + 6u, 0x80u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 - 1u);
	sub_02C8C8();
}

void sub_02C8C8(void)
{
}

void sub_02C8C9(uint16_t x)
{
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = io_read8(VIDEO_1874);
	t2 = mem_read16(x + 0x16u);
	t3 = (uint8_t)((uint32_t)t1 << 1) + t2;
	mem_write16(x + 0x16u, t3);
	mem_write8(x + 6u, 0x80u);
	t4 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t4 - 1u);
}

uint16_t sub_02C8DE(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0;

	mem_write8(x + 0x3Du, 0u);
	mem_write16(x + 0xFu, 0x400u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x, 0x80u);
	y = hit_box_02DB10_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	return y;
}

void sub_02C8FC(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0, ignored16_2 = 0, u = 0, y = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		sub_078674(x);
		return;
	}
	d = 0x6E00u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 0x3Bu, 4u);
	y = child_object_02DD23_ADDRESS;
	sub_07862F(x, y, &ignored16_2, &carry);
	y = child_object_02DD29_ADDRESS;
	sub_07862F(x, y, &u, &carry);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_078674(x);
	*p_y = y;
	*p_u = u;
}

void sub_02C923(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0x84u);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 0x3Bu, 0x10u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	sub_078674(x);
}

void sub_02C93B(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x, mem_read8(x) ^ 0x84u);
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
}

void sub_02C955(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02DD37_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x88u);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write16(x + 0x19u, 0x400u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C970(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0x19u, 0x200u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02C97F(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		sub_02C987();
		return;
	}
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02C987();
}

void sub_02C987(void)
{
}

void sub_02C991(uint16_t x)
{
	uint16_t ignored16 = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	mem_write8(x + 0x37u, 0u);
	y = loaded_table_02DD71_ADDRESS;
	sub_02C7C7(x, &y, &ignored16);
	t1 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t1 + 1u);
	y = loaded_table_02DD71_ADDRESS;
	sub_02C7C7(x, &y, &ignored16);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	y = loaded_table_02DD71_ADDRESS;
	sub_02C7C7(x, &y, &ignored16);
	t3 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t3 + 1u);
}

void sub_02C9B9(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	y = loaded_table_02DD4D_ADDRESS;
	sub_02C7C7(x, &y, &u);
	t1 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02C9C3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t u_2 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x180u)
		return;
	y_2 = loaded_table_02DD59_ADDRESS;
	sub_02C7C7(x, &y_2, &u_2);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	*p_y = y_2;
	*p_u = u_2;
}

void sub_02C9D5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 >= 0x1A0u)
	{
		sub_02C9E6();
		return;
	}
	y = loaded_table_02DD65_ADDRESS;
	sub_02C7C7(x, &y, &u);
	t2 = mem_read8(x + 0x37u);
	mem_write8(x + 0x37u, t2 + 1u);
	sub_02C9E6();
	*p_y = y;
	*p_u = u;
}

void sub_02C9E6(void)
{
}

void sub_02C9E7(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t stack_10001 = 0, stack_10002 = 0;
	uint16_t stack = 0;
	uint8_t t3 = 0, t5 = 0;
	uint16_t t1 = 0, t2 = 0, t4 = 0;

	u = object_setup_02DD7D_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x5Bu, 0x40u);
	t1 = mem_read16(x + 0x11u);
	t2 = t1 - 2u;
	mem_write16(x + 0x11u, t2);
	t3 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t3 & 0xCFu) | 0x10u);
	sub_078650(x, &u, &d);
	a = (uint8_t)(d >> 8);
	mem_write8(x + 0x33u, a);
	stack = u;
	b = (uint8_t)stack;
	unk_48F0 = b;
	mem_write16(x + 0x38u, ((uint32_t)(stack >> 8) << 8) | (b & 0xC0u));
	unk_48F0 = (unk_48F0 - 2u) & 0x3Fu;
	t4 = mem_read16(x + 0x38u);
	stack_10001 = t4 >> 8;
	stack_10002 = t4 | unk_48F0;
	u = ((uint32_t)stack_10001 << 8) | stack_10002;
	mem_write16(x + 0x2Au, u);
	mem_write8(x + 0x37u, 0u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02CA3A(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x37u);
	if (t1 == 3u)
	{
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

uint16_t sub_02CA45(void)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0;

	b = 4u;
	a = (uint8_t)unk_4815;
	do
	{
		u = DATA16(indexed_table_02DD83_ADDRESS + (uint8_t)((a & 3u) << 1));
		t1 = mem_read8(u);
		a = t1;
		if (t1 != 0u)
			break;
		a++;
		t2 = b;
		b = t2 - 1u;
	} while (t2 != 1u);
	return u;
}

void sub_02CA5B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0xCu);
	if (t1 < 0x128u)
	{
		u = sub_02CA45();
		sub_078626(x, u);
		t2 = mem_read8(x + 0x36u);
		if (t2 == 0xA0u)
		{
			mem_write8(x, 0xC0u);
			mem_write16(x + 0xFu, 0xFE00u);
			mem_write16(x + 0x14u, 0xFC00u);
			t3 = mem_read8(x + 2u);
			mem_write8(x + 2u, t3 + 1u);
			sub_02C991(x);
			y = child_object_02DD8B_ADDRESS;
			sub_07862C(x, y, &u, &ignored16, &carry);
			if (unk_4857 > 2u)
			{
				y = child_object_02DD93_ADDRESS;
				sub_07862C(x, y, &u, &ignored16, &carry);
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_02CA9A(uint16_t x)
{
	uint8_t a = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x11u);
	if (t1 < 0x40u)
	{
		mem_write8(x, 0u);
		return;
	}
	a = mem_read8(x) ^ 0x40u;
	mem_write8(x, a);
	if ((a & 0x40u) != 0u)
	{
		mem_write8(x + 0x1Du, 2u);
		return;
	}
	mem_write8(x + 0x1Du, 0x14u);
	sub_078674(x);
}

uint16_t sub_02CB0C(uint16_t x, uint16_t u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0, t10 = 0;
	uint16_t t3 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;

	if (mem_read8(x) == 0u)
		return u;
	t1 = mem_read8(x + VIDEO_0031);
	if (t1 != 0u)
		return u;
	t2 = mem_read8(x + 0x3Du);
	if (t2 != 0u)
	{
		t3 = mem_read16(x + 0x40u);
		u_2 = t3;
		t4 = mem_read8(u_2 + 9u);
		unk_48F0 = t4 & 0x30u;
		t5 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t5 & 0xCFu) | unk_48F0);
		return u_2;
	}
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F0 = a;
	if ((int8_t)a < 0)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 0xFEu);
		return u;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t6 = mem_read16(x + 0x16u);
	t7 = mem_read16(x + 0x5Cu);
	if (t6 != t7)
		a = mem_read8(x) | 8u;
	else
		a = mem_read8(x) & ~8u;
	mem_write8(x, a);
	sub_07863B(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	unk_48F1 = a;
	if (a == unk_48F0)
		return u;
	if ((int8_t)a >= 0)
	{
		t8 = (unk_48F1 & 0xFu) << 3;
		t9 = mem_read16(x + 0x16u);
		if (t8 < t9)
		{
			unk_48F2 = unk_48F1 & 0x30u;
			t10 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t10 & 0xCFu) | unk_48F2);
			return u;
		}
	}
	mem_write16(x + 0xFu, 0u);
	mem_write8(x + 2u, 0xFEu);
	return u;
}

void sub_02CB7D(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0, u_2 = 0;
	uint8_t t1 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 0x28u);
	if (t1 != 0u)
	{
		t2 = mem_read16(x + 0xCu);
		if (t2 < 0x180u)
		{
			t3 = mem_read16(x + 0x11u);
			t4 = t3 - 2u;
			d = (uint8_t)t4;
			mem_write16(x + 0x11u, ((uint32_t)(t4 >> 8) << 8) | (d & 0xFFu));
			mem_write8(x + 6u, 0x80u);
			t5 = mem_read8(x + 0x47u);
			d_2 = (d & 0xFFu) | ((uint32_t)t5 << 8);
			sub_02CC4A(x, d_2, &u, p_left_caller);
			if (*p_left_caller == 0u)
			{
				t6 = mem_read8(x + 2u);
				mem_write8(x + 2u, t6 + 1u);
			}
		}
	}
	else
	{
		u_2 = object_setup_02DDCD_ADDRESS;
		y = sub_0785AB(x, u_2);
		u = indexed_table_02DDB1_ADDRESS;
		t7 = mem_read8(x + 0x30u);
		mem_write8(x + 0x47u, DATA8(indexed_table_02DDB1_ADDRESS + (t7 >> 1)));
		t8 = mem_read8(x + 0x30u);
		a = t8 | 0x80u;
		mem_write8(x + 5u, a);
		mem_write8(x + 0x30u, a + 1u);
		t9 = mem_read8(x + 0x3Du);
		if (t9 != 0u)
		{
			t6 = mem_read8(x + 2u);
			mem_write8(x + 2u, t6 + 1u);
		}
		else
		{
			t10 = mem_read8(x + 0x28u);
			mem_write8(x + 0x28u, t10 + 1u);
			t11 = mem_read8(x + VIDEO_0031);
			mem_write8(x + VIDEO_0031, t11 + 1u);
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_02CBCD(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DDD3_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		u = sub_02CBD6(x, u);
		break;
	case 2:
		sub_02CBF6(x);
		break;
	case 4:
		sub_02CC0C(x, &y, &u);
		break;
	case 6:
		sub_02CC42(x);
		break;
	case 8:
		sub_02CE41(x, &y, &u);
		break;
	case 10:
		sub_02CE65();
		break;
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02CBD6(uint16_t x, uint16_t u)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = 0x6C00u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0u);
	t1 = mem_read8(x + VIDEO_0031);
	if (t1 != 0u)
		u = sub_02CCE8(x);
	mem_write8(x + 5u, 0x80u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	return u;
}

void sub_02CBF6(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02CC00(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DDD7_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02CC0C(x, &y, &u);
		break;
	case 2:
		sub_02CC42(x);
		break;
	case 4:
		sub_02CE41(x, &y, &u);
		break;
	case 6:
		sub_02CE65();
		break;
	case -4:
		u = sub_02CBD6(x, u);
		break;
	case -2:
		sub_02CBF6(x);
		break;
	}
	sub_078674(x);
	*p_y = y;
	*p_u = u;
}

void sub_02CC0C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t7 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	if (t1 != 0u)
		sub_02CCE8(x);
	mem_write8(x, 0x80u);
	y = hit_box_02DAA0_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t2 | 0x80u);
	mem_write16(x + 0xFu, 0x400u);
	t3 = mem_read16(x + 0x25u);
	u = t3;
	t4 = mem_read16(u + 0xCu);
	t5 = mem_read16(x + 0xCu);
	if (t5 <= t4)
	{
		t6 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t6);
	}
	mem_write8(x + 0x29u, 0u);
	t7 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02CC42(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	sub_078674(x);
}

void sub_02CC4A(uint16_t x, uint16_t d, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint8_t a = 0, b = 0;
	uint16_t d_2 = 0, u = 0;
	uint32_t left_caller = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0;
	uint16_t t2 = 0, t9 = 0;

	io_write8(VIDEO_188B, d >> 8);
	sub_078650(x, &u, &d_2);
	a = (uint8_t)(d_2 >> 8);
	stack = a;
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	mem_write8(x + 0x33u, stack);
	stack_2 = u >> 8;
	stack = (uint8_t)u;
	b = stack;
	mem_write8(x + 0x34u, b);
	mem_write16(x + 0x38u, ((uint32_t)stack_2 << 8) | (b & 0xC0u));
	unk_48F4 = 3u;
	t1 = mem_read8(x + 0x34u);
	b = t1 - 1u;
	unk_48F5 = b;
	for (;;)
	{
		t2 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t2 + b;
		t3 = mem_read8(x + 0x33u);
		if (mem_read8(u) != t3)
		{
			mem_write8(x + 2u, 0xFEu);
			a = unk_480F & ~3u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			left_caller = 1u;
			break;
		}
		t4 = mem_read8(u + 0x40u);
		t5 = mem_read8(x + 0x33u);
		if (t4 != t5)
		{
			mem_write8(x + 2u, 0xFEu);
			a = unk_480F & ~3u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			left_caller = 1u;
			break;
		}
		b++;
		t6 = unk_48F4;
		unk_48F4 = t6 - 1u;
		if (t6 != 1u)
			continue;
		unk_48F4 = 3u;
		b = unk_48F5;
		t7 = mem_read8(x + 0x33u);
		t8 = io_read8(VIDEO_188B);
		a = (t7 & 0xFu) + t8;
		if (a >= 0x10u)
		{
			mem_write8(x + 2u, 0xFEu);
			a = unk_480F & ~3u;
			unk_480F = a;
			io_write8(IO_1FC2, a);
			left_caller = 1u;
			break;
		}
		do
		{
			t9 = mem_read16(x + 0x38u);
			b &= 0x3Fu;
			u = t9 + b;
			mem_write8(u, a);
			b++;
			t10 = unk_48F4;
			unk_48F4 = t10 - 1u;
		} while (t10 != 1u);
		a = unk_480F & ~3u;
		unk_480F = a;
		io_write8(IO_1FC2, a);
		t11 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t11 + 1u);
		left_caller = 0u;
		break;
	}
	*p_u = u;
	*p_left_caller = left_caller;
}

uint16_t sub_02CCE8(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t u = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	t1 = mem_read8(x + 0x34u);
	b = t1 - 1u;
	unk_48F4 = 3u;
	t2 = mem_read8(x + 0x33u);
	a = t2;
	do
	{
		t3 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t3 + b;
		mem_write8(u, a);
		b++;
		t4 = unk_48F4;
		unk_48F4 = t4 - 1u;
	} while (t4 != 1u);
	mem_write8(x + VIDEO_0031, 0u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return u;
}

void sub_02CD2B(uint16_t x, uint16_t *p_y, uint16_t *p_u, uint32_t *p_left_caller)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Du);
	if (t1 != 0u)
	{
		y = hit_box_02DA98_ADDRESS;
		sub_0785B4(x, y);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
		sub_02CD43();
	}
	else
	{
		t3 = mem_read8(x + 0x28u);
		if (t3 != 0u)
		{
			y = hit_box_02DA98_ADDRESS;
			sub_0785B4(x, y);
			t2 = mem_read8(x + 2u);
			mem_write8(x + 2u, t2 + 1u);
			sub_02CD43();
		}
		else
		{
			d = 0x400u;
			sub_02CC4A(x, d, &u, p_left_caller);
			if (*p_left_caller == 0u)
			{
				y = hit_box_02DA98_ADDRESS;
				sub_0785B4(x, y);
				t2 = mem_read8(x + 2u);
				mem_write8(x + 2u, t2 + 1u);
				sub_02CD43();
			}
		}
	}
	*p_y = y;
	*p_u = u;
}

void sub_02CD43(void)
{
}

uint16_t sub_02CD44(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t1 = 0;

	mem_write8(x, 0x80u);
	u = sub_02CCE8(x);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 - 1u);
	return u;
}

uint16_t sub_02CD50(uint16_t x, uint16_t y)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, y_2 = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	t1 = mem_read8(x + 0x17u);
	if (t1 <= (uint8_t)((((a & 0xFu) << 1) << 1) << 1))
	{
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 2u, 0xFEu);
		return y;
	}
	y_2 = hit_box_02DAA0_ADDRESS;
	sub_0785B4(x, y_2);
	mem_write8(x + 0x3Du, 0u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_078674(x);
	return y_2;
}

void sub_02CD7B(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0x19u, 0x400u);
		t1 = mem_read8(x + 0x30u);
		mem_write8(x + 5u, t1 | 0x80u);
		mem_write8(x + 2u, 0xFFu);
		mem_write8(x + 0x28u, 1u);
	}
	sub_078674(x);
}

uint16_t sub_02CD9A(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0, t4 = 0;
	uint16_t t1 = 0, t3 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	mem_write16(x + 0x19u, 0x600u);
	mem_write16(x + 0xFu, 0x100u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read8(u + 9u);
	if ((t2 & 0x40u) == 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t3);
	}
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	return u;
}

uint16_t sub_02CDBF(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, y_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	t1 = mem_read16(x + 0x19u);
	if ((int16_t)t1 >= 0)
		return y;
	y_2 = hit_box_02DAA0_ADDRESS;
	sub_0785B4(x, y_2);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_078674(x);
	return y_2;
}

void sub_02CDD4(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
	{
		sub_078674(x);
		return;
	}
	t1 = mem_read8(x + 0xFu);
	unk_48F0 = t1;
	mem_write16(x + 0xFu, 0x400u);
	if ((int8_t)unk_48F0 < 0)
	{
		t2 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t2);
	}
	mem_write16(x + 0x19u, 0x400u);
	t3 = mem_read8(x + 0x30u);
	mem_write8(x + 5u, t3 | 0x80u);
	mem_write8(x + 2u, 0xFFu);
	mem_write8(x + 0x28u, 1u);
	sub_078674(x);
}

void unreached_02CE07(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	mem_write8(x + 0x3Du, 0u);
	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void unreached_02CE13(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void unreached_02CE1C(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x80u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
}

void unreached_02CE25(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02CE41(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_02DDDF_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	t2 = mem_read16(x + 0x16u);
	t3 = t2 + 0x4Cu;
	mem_write16(x + 0x16u, t3);
	u = sub_02D218(x);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	sub_02CE65();
	*p_y = y;
	*p_u = u;
}

void sub_02CE65(void)
{
}

void sub_02CE6F(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t negative = 0;
	uint8_t a = 0;
	uint16_t d = 0, u = 0, y = 0;
	uint8_t t1 = 0, t3 = 0, t4 = 0;
	uint16_t t2 = 0;

	u = object_setup_02DDEF_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	mem_write8(x + 0x5Bu, 0x40u);
	t1 = mem_read8(x + 0x30u);
	a = t1;
	mem_write8(x + 0x3Du, a);
	u = loaded_table_02DDF5_ADDRESS + (int8_t)(((uint32_t)a << 1) << 1);
	t2 = DATA16(u);
	mem_write8(x + 0x30u, t2 >> 8);
	mem_write8(x + 0x5Du, t2);
	t3 = mem_read8(u + 2u);
	mem_write8(x + 0x3Bu, t3);
	mem_write16(x + 0xAu, 0x4040u);
	d = 0u;
	sub_078638(x, &d, &negative);
	a = (uint8_t)(d >> 8);
	if ((int8_t)a >= 0)
		mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02CEB3(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read8(x + 0x3Du);
		if ((int8_t)t2 >= 0)
		{
			t3 = mem_read8(x + 0x3Bu);
			if (t3 == 0x10u)
			{
				mem_write8(x, 0x88u);
				mem_write8(x + 6u, 0x80u);
			}
		}
		return;
	}
	t4 = mem_read8(x + 0x3Du);
	if ((int8_t)t4 >= 0)
	{
		mem_write8(x + 0x3Bu, 0x60u);
		t5 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t5 & 0xCFu) | 0x10u);
		t6 = mem_read8(x + 2u);
		mem_write8(x + 2u, t6 + 1u);
		return;
	}
	mem_write8(x + 0x3Bu, 0x60u);
	t7 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t7 & 0xCFu) | 0x20u);
	mem_write8(x, 0x80u);
	mem_write8(x + 2u, 4u);
}

void sub_02CF01(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t1 - 0x30u);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		sub_02CF41(x);
		return;
	}
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	d = 0x6500u;
	carry = sub_078680(d);
	t3 = mem_read8(x + 0x30u);
	if (t3 == 0u)
	{
		mem_write8(x, 0xC0u);
		mem_write16(x + 0x14u, 0xFF80u);
		mem_write16(x + 0x19u, 0x200u);
		sub_02CF41(x);
		return;
	}
	mem_write16(x + 0x14u, 0xFD00u);
	mem_write16(x + 0x19u, 0x400u);
	mem_write8(x, 0xD8u);
	sub_02CF41(x);
}

void sub_02CF41(uint16_t x)
{
	uint32_t carry = 0;

	carry = ((uint8_t)unk_4815 >> 0) & 1u;
	if (carry == 0u)
	{
		mem_write8(x, mem_read8(x) | 0x40u);
		mem_write8(x + 0x1Du, 0xAu);
		return;
	}
	mem_write8(x, mem_read8(x) & 0xBFu);
	mem_write8(x + 0x1Du, 0x14u);
	sub_078674(x);
}

void sub_02CF65(uint16_t x)
{
	uint32_t negative = 0, carry = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t t1 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	mem_write8(x, 0u);
	t1 = mem_read8(x + 0x30u);
	if (t1 != 0u)
	{
		mem_write8(x, 0x10u);
		t2 = mem_read16(x + 0xAu);
		t3 = t2 - 0x101u;
		d = (uint8_t)t3;
		a = (uint8_t)(t3 >> 8);
		if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >= 0x2020u)
			mem_write16(x + 0xAu, ((uint32_t)a << 8) | (d & 0xFFu));
	}
	d_2 = 0u;
	sub_078638(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a < 0)
	{
		t4 = mem_read16(x + 0x11u);
		if (t4 < 0x40u)
			mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x5Du, 0u);
		mem_write8(x, mem_read8(x) | 0x80u);
		t5 = mem_read8(x + 0x3Bu);
		mem_write8(x + 0x3Bu, t5 - 1u);
		if (t5 != 1u)
		{
			t6 = mem_read16(x + 0x19u);
			t7 = t6 - 0x20u;
			a = (uint8_t)(t7 >> 8);
			t8 = ((uint32_t)a << 8) | (t7 & 0xFFu);
			mem_write16(x + 0x19u, t8);
			if ((int16_t)t8 >= 0 || a >= 0xFCu)
				return;
			mem_write8(x + 0x19u, 0xFCu);
			return;
		}
		d_2 = 0x6500u;
		carry = sub_078680(d_2);
		mem_write8(x, 0u);
		return;
	}
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	mem_write8(x, mem_read8(x) | 0xC8u);
	t9 = mem_read16(x + 0x19u);
	t10 = t9 - 0x20u;
	mem_write16(x + 0x19u, t10);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		sub_02CF41(x);
		return;
	}
	d_2 = 0x6500u;
	carry = sub_078680(d_2);
	mem_write16(x + 0x14u, 0xFF00u);
	mem_write16(x + 0x19u, 0x200u);
	sub_02CF41(x);
}

void sub_02CFF4(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t2 = 0, t3 = 0;
	uint16_t t1 = 0, t4 = 0, t5 = 0;

	t1 = mem_read16(x + 0x16u);
	d = t1;
	if ((int16_t)t1 < 0 && d < 0xFF80u)
	{
		d = 0x6500u;
		carry = sub_078680(d);
		mem_write8(x, 0u);
		return;
	}
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	t3 = mem_read8(x + 0x3Bu);
	if ((uint16_t)((uint32_t)t3 << 8) >> 8 < 0x20u)
	{
		mem_write8(x, 0x90u);
		t4 = mem_read16(x + 0xAu);
		d = t4 + 0x202u;
		if (d < 0x8080u)
			mem_write16(x + 0xAu, d);
	}
	t5 = mem_read16(x + 0x19u);
	d = t5 - 0x20u;
	mem_write16(x + 0x19u, d);
	if ((int16_t)d >= 0 || d >> 8 >= 0xFCu)
		return;
	mem_write8(x + 0x19u, 0xFCu);
}

void sub_02D043(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02DE0B_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x30u);
	if (t1 == 0u)
	{
		unk_4A84 = 0x97u;
		unk_4B44 = 0x97u;
		unk_4C04 = 0x97u;
		unk_4CC4 = 0x97u;
	}
	t2 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t2 & 0xCFu) | 0x10u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D06E(uint16_t x)
{
	uint8_t t1 = 0;

	if ((mem_read8(x) & 0x20u) != 0u)
	{
		mem_write8(x, 0x80u);
		mem_write8(x + 5u, 0x81u);
		mem_write8(x + 0x3Bu, 0x40u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02D088(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
		mem_write8(x, 0u);
}

void sub_02D098(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	u = object_setup_02DE15_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Bu, 0x20u);
	mem_write16(x + 0xFu, 0x20u);
	mem_write16(x + 0x19u, 0xFF00u);
	t2 = mem_read8(x + 0x30u);
	if (t2 != 0u)
		mem_write8(x + 5u, 0x90u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D0CB(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read16(x + 0x16u);
		if (t2 < 0x10u)
			mem_write8(x, 0u);
		return;
	}
	mem_write8(x, 0u);
}

void sub_02D0E5(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02DE23_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x10u);
	mem_write8(x + 0x30u, 0x1Cu);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02D103(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	if ((mem_read8(u) & 0x40u) == 0u)
	{
		mem_write8(x, 0x88u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
	return u;
}

void sub_02D116(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x, 0x88u);
		mem_write16(x + 0xFu, 0x200u);
		mem_write16(x + 0x19u, 0x200u);
		t1 = mem_read8(x + 2u);
		mem_write8(x + 2u, t1 + 1u);
	}
}

void sub_02D12D(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0, carry = 0;
	uint16_t d = 0, ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write16(x + 0xFu, 0u);
		d = 0u;
		sub_078638(x, &d, &negative);
		if ((int8_t)(d >> 8) < 0)
			mem_write8(x, 0u);
		else
		{
			mem_write16(x + 1u, 0x100u);
			y = child_object_02DE29_ADDRESS;
			sub_07862F(x, y, &u, &carry);
		}
	}
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02D15A(uint16_t x, uint16_t u)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0;

	t1 = mem_read8(x + 2u);
	if ((int8_t)t1 >= 0 && (mem_read8(x) & 0x20u) != 0u)
	{
		t2 = mem_read16(x + 0x25u);
		u = t2;
		t3 = mem_read16(u + 0x16u);
		t4 = mem_read16(x + 0x5Cu);
		t5 = t3 - t4;
		if (t5 >= 0x50u)
		{
			mem_write8(x, 0x80u);
			mem_write8(x + 2u, 0xFDu);
			mem_write8(x + 0x28u, 0u);
			sub_02D182();
			return u;
		}
	}
	sub_02D182();
	return u;
}

void sub_02D182(void)
{
}

void sub_02D183(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t ignored16 = 0, ignored16_2 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t6 = 0, t9 = 0;
	uint16_t t4 = 0, t5 = 0, t7 = 0, t8 = 0, t10 = 0, t11 = 0;

	u = object_setup_02DEAD_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x30u);
	a = t1;
	if ((int8_t)t1 < 0)
	{
		t2 = a & 0x7Fu;
		a = t2;
		if (t2 == 0u)
		{
			t3 = mem_read8(x + 9u);
			mem_write8(x + 9u, (t3 & 0xCFu) | 0x20u);
			mem_write8(x, 0x80u);
			*p_y = y;
			*p_u = u;
			return;
		}
		mem_write8(x + 0x30u, a);
		if (a != 1u)
		{
			y = child_object_02DE8D_ADDRESS;
			sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
			a = 2u;
		}
		else
		{
			y = child_object_02DE75_ADDRESS;
			sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
			y = child_object_02DE7D_ADDRESS;
			sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
			y = child_object_02DE85_ADDRESS;
			sub_07862C(x, y, &ignored16, &ignored16_2, &carry);
			a = 0u;
		}
	}
	mem_write8(x + 0x47u, DATA8(object_16_flags_ADDRESS + (int8_t)a));
	u = object_16_kinds_ADDRESS + (int8_t)(((uint32_t)a << 1) << 1);
	t4 = DATA16(u);
	mem_write16(x + 0x3Eu, t4);
	t5 = mem_read16(u + 2u);
	b = (uint8_t)t5;
	mem_write8(x + 4u, t5 >> 8);
	mem_write8(x + 5u, b);
	mem_write8(x + 0x54u, b);
	mem_write8(x + 0x3Du, b);
	t6 = mem_read8(x + 0x30u);
	u = loaded_table_02DE95_ADDRESS + (int8_t)(((uint32_t)t6 << 1) << 1);
	t7 = DATA16(u);
	mem_write16(x + 0x50u, t7);
	t8 = mem_read16(u + 2u);
	mem_write16(x + 0x52u, t8);
	mem_write8(x + VIDEO_003C, 5u);
	t9 = mem_read8(x + 2u);
	mem_write8(x + 2u, t9 + 1u);
	t10 = mem_read16(x + 0x11u);
	t11 = t10 - 2u;
	mem_write16(x + 0x11u, t11);
	u = sub_02D218(x);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02D218(uint16_t x)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, u = 0;
	uint8_t stack = 0, stack_2 = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t1 + 1u);
	sub_078650(x, &u, &d);
	a = (uint8_t)(d >> 8);
	stack = a;
	a = unk_480F | 2u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	mem_write8(x + 0x33u, stack);
	mem_write16(x + 0x2Au, u);
	stack_2 = u >> 8;
	stack = (uint8_t)u;
	b = stack;
	mem_write8(x + 0x34u, b);
	mem_write16(x + 0x38u, ((uint32_t)stack_2 << 8) | (b & 0xC0u));
	unk_48F4 = 3u;
	t2 = mem_read8(x + 0x34u);
	b = t2 - 2u;
	a = 0xFFu;
	do
	{
		t3 = mem_read16(x + 0x38u);
		b &= 0x3Fu;
		u = t3 + b;
		mem_write8(u, a);
		b++;
		t4 = unk_48F4;
		unk_48F4 = t4 - 1u;
	} while (t4 != 1u);
	a = unk_480F & ~3u;
	unk_480F = a;
	io_write8(IO_1FC2, a);
	return u;
}

void sub_02D26C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DEB3_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02D275(x);
		break;
	case 2:
		sub_02D285(x);
		break;
	case 4:
		sub_02D2A3(x);
		break;
	case 6:
		sub_02D2B3(x);
		break;
	case 8:
		sub_02D2C3(x);
		break;
	case 10:
		sub_02D2E3(x, &y, &u);
		break;
	case 12:
	case 32:
		sub_02D359(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D275(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	d = unk_4800_ADDRESS;
	carry = sub_078680(d);
	t1 = mem_read8(x + 0x50u);
	mem_write8(x + 5u, t1);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_02D285(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x51u);
		mem_write8(x + 5u, t2);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
		return;
	}
	t4 = mem_read8(x + 6u);
	if ((t4 & 2u) == 0u)
		return;
	d = 0xC01u;
	carry = sub_078680(d);
}

void sub_02D2A3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x52u);
		mem_write8(x + 5u, t2);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_02D2B3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		t2 = mem_read8(x + 0x53u);
		mem_write8(x + 5u, t2);
		t3 = mem_read8(x + 0x29u);
		mem_write8(x + 0x29u, t3 + 1u);
	}
}

void sub_02D2C3(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x, 0xC0u);
		t2 = mem_read8(x + 0x54u);
		mem_write8(x + 5u, t2);
		mem_write8(x + 2u, 1u);
	}
}

void sub_02D2DA(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DEBD_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02D2E3(x, &y, &u);
		break;
	case 2:
	case 22:
		sub_02D359(x);
		break;
	case -10:
		sub_02D275(x);
		break;
	case -8:
		sub_02D285(x);
		break;
	case -6:
		sub_02D2A3(x);
		break;
	case -4:
		sub_02D2B3(x);
		break;
	case -2:
		sub_02D2C3(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D2E3(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Du);
	mem_write8(x + 5u, t1 + 1u);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t2 + 1u);
	t3 = mem_read8(x + 4u);
	if (t3 != 0xFu)
	{
		y = child_object_02DEC9_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
	}
	else
	{
		y = child_object_02DEC1_ADDRESS;
		sub_07862C(x, y, &u, &ignored16, &carry);
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D305(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DED1_ADDRESS;
	t1 = mem_read8(x + 0x28u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02D30E(x, &y, &u);
		break;
	case -18:
	case 2:
		sub_02D359(x);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D30E(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint8_t a = 0, b = 0;
	uint16_t d = 0, ignored16 = 0, u = 0, y = 0;
	uint8_t t2 = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;
	uint16_t t1 = 0, t5 = 0;

	y = child_object_02DED5_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	if (carry)
	{
		t1 = mem_read16(x + 0x3Eu);
		y = t1;
		t2 = mem_read8(x + VIDEO_003C);
		mem_write8(x + VIDEO_003C, t2 - 1u);
		if (t2 == 1u)
			mem_write8(x + 0x1Bu, 0u);
		t3 = mem_read8(x + VIDEO_003C);
		b = mem_read8(y + (t3 & 0xFu));
		unk_48F0 = b;
		if (unk_4857 <= (b >> 1) >> 1)
		{
			t4 = mem_read8(x + 0x47u);
			a = t4;
		}
		else
			a = unk_48F0;
		mem_write8(u + 0x30u, a);
		t5 = mem_read16(x + 0x25u);
		mem_write16(u + 0x2Au, t5);
	}
	d = 0x1C00u;
	carry = sub_078680(d);
	t6 = mem_read8(x + 0x3Du);
	mem_write8(x + 5u, t6 + 1u);
	mem_write8(x + 0x3Bu, 0x20u);
	t7 = mem_read8(x + 0x28u);
	mem_write8(x + 0x28u, t7 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D359(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x3Du);
		mem_write8(x + 5u, t2);
		mem_write8(x + 2u, 1u);
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x28u, 0u);
	}
}

void sub_02D385(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02DEF1_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02D38E(x);
			break;
		case 2:
			sub_02D3B4(x);
			break;
		case 4:
			sub_02D3E6(x);
			break;
		case 6:
			sub_02D436();
			break;
		case -20:
		case -18:
			continue;
		case -16:
			sub_02D437(x, &y, &u);
			break;
		case -14:
			sub_02D494(x);
			break;
		case -12:
			sub_02D4B5(x);
			break;
		case -10:
			sub_02D4EB(x);
			break;
		case -8:
			y = sub_02D503(x);
			break;
		case -6:
			sub_02D52E(x);
			break;
		case -4:
			sub_02D531(x);
			break;
		case -2:
			sub_02D4EA();
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D38E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 4u, 4u);
	t1 = mem_read8(x + 0x2Du);
	mem_write8(x + 5u, t1 + 1u);
	mem_write8(x, 0x88u);
	mem_write16(x + 0x14u, 0xFD00u);
	mem_write16(x + 0x19u, 0x80u);
	mem_write16(x + 0xAu, 0x4040u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
	sub_02D3B4(x);
}

void sub_02D3B4(uint16_t x)
{
	uint32_t negative = 0;
	uint8_t a = 0, d = 0;
	uint16_t d_2 = 0;
	uint8_t t3 = 0;
	uint16_t t1 = 0, t2 = 0;

	mem_write8(x, 0x98u);
	t1 = mem_read16(x + 0xAu);
	t2 = t1 - 0x101u;
	d = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((uint16_t)(((uint32_t)a << 8) | (d & 0xFFu)) >= 0x2020u)
		mem_write16(x + 0xAu, ((uint32_t)a << 8) | (d & 0xFFu));
	sub_078647(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	if ((int8_t)a >= 0)
		return;
	d_2 = 0u;
	sub_078638(x, &d_2, &negative);
	a = (uint8_t)(d_2 >> 8);
	mem_write8(x + 0x5Du, (((a & 0xFu) << 1) << 1) << 1);
	mem_write16(x + 0x14u, 0u);
	mem_write16(x + 0x19u, 0xFF80u);
	t3 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t3 + 1u);
}

void sub_02D3E6(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t4 = 0, t7 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;

	mem_write8(x, 0x98u);
	t1 = mem_read16(x + 0xAu);
	d = t1 + 0x101u;
	if (d <= 0x4040u)
		mem_write16(x + 0xAu, d);
	t2 = mem_read16(x + 0x19u);
	mem_write16(x + 0x19u, t2 - 0x10u);
	carry = sub_078662(x);
	if (carry == 0u)
	{
		sub_02D436();
		return;
	}
	t3 = mem_read16(x + 0xAu);
	if (t3 < 0x4040u)
	{
		sub_02D436();
		return;
	}
	t4 = mem_read8(x + 0x2Cu);
	mem_write8(x + 4u, (uint16_t)((uint32_t)t4 << 8) >> 8);
	mem_write8(x + 5u, 0x80u);
	mem_write16(x + 0xFu, 0x200u);
	t5 = mem_read16(x + 0xCu);
	if (t5 < 0xE0u)
	{
		t6 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t6);
	}
	mem_write8(x, 0x80u);
	t7 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t7 + 1u);
	sub_0785C6(x);
}

void sub_02D436(void)
{
}

void sub_02D437(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t9 = 0;
	uint16_t t2 = 0, t3 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0;

	u = object_setup_02DF0B_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_02DEF9_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	a = (uint8_t)(t2 >> 8);
	mem_write16(x + 0x2Cu, ((uint32_t)a << 8) | (t2 & 0xFFu));
	mem_write8(x + 4u, a);
	t3 = mem_read16(u + 2u);
	mem_write8(x + 9u, t3 >> 8);
	mem_write8(x + 0x44u, t3);
	u = indexed_table_02DF05_ADDRESS;
	t4 = mem_read8(x + 0x30u);
	t5 = DATA16(indexed_table_02DF05_ADDRESS + (int8_t)((uint32_t)t4 << 1));
	mem_write16(x + 0x50u, t5);
	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x + VIDEO_003C, 2u);
	mem_write16(x + 0xFu, 0x100u);
	t6 = mem_read16(x + 0xCu);
	if (t6 >= 0xE0u)
	{
		t7 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t7);
	}
	t8 = mem_read16(x + 0xFu);
	mem_write16(x + 0x3Eu, t8);
	t9 = mem_read8(x + 2u);
	mem_write8(x + 2u, t9 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D494(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 0x50u);
		mem_write8(x + 0x3Bu, t2);
		mem_write8(x, 0xC0u);
		mem_write8(x + 0x1Du, 0xFFu);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x81u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_02D4B5(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0, t5 = 0, t6 = 0;
	uint16_t t4 = 0;

	t1 = mem_read8(x + 0x3Du);
	if (t1 != 0u)
	{
		sub_02D4EA();
		return;
	}
	t2 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t2 - 1u);
	if (t2 != 1u)
	{
		sub_02D4EA();
		return;
	}
	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Bu, 0x40u);
	mem_write8(x + 0x1Du, 0u);
	t3 = mem_read8(x + 0x2Cu);
	mem_write8(x + 4u, t3);
	mem_write8(x + 5u, 0x80u);
	t4 = mem_read16(x + 0x3Eu);
	mem_write16(x + 0xFu, t4);
	t5 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t5 - 1u);
	if (t5 != 1u)
	{
		t6 = mem_read8(x + 2u);
		mem_write8(x + 2u, t6 - 1u);
		sub_02D4EA();
		return;
	}
	mem_write8(x + 2u, 7u);
}

void sub_02D4EA(void)
{
}

void sub_02D4EB(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + 0x3Du, 1u);
	mem_write8(x, 0x80u);
	mem_write8(x + 4u, 4u);
	t1 = mem_read8(x + 0x2Du);
	mem_write8(x + 5u, t1);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 - 1u);
}

uint16_t sub_02D503(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t4 = 0, t5 = 0;
	uint16_t t3 = 0;

	t1 = mem_read8(x + 0x44u);
	if (t1 == 0u)
	{
		d = 0x5F00u;
		carry = sub_078680(d);
	}
	t2 = mem_read8(x + 0x51u);
	if (t2 == 0u)
	{
		t3 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, (int16_t)t3 >> 1);
	}
	mem_write8(x, 0x88u);
	mem_write8(x + 0x3Du, 0u);
	t4 = mem_read8(x + 0x2Du);
	mem_write8(x + 5u, t4 + 1u);
	y = hit_box_02DB20_ADDRESS;
	sub_0785B4(x, y);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	sub_02D52E(x);
	return y;
}

void sub_02D52E(uint16_t x)
{
	sub_078674(x);
}

void sub_02D531(uint16_t x)
{
	uint8_t t1 = 0;
	uint16_t t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x2Cu);
	mem_write8(x + 4u, t1);
	mem_write8(x + 5u, 0x80u);
	mem_write8(x + 2u, 0xFEu);
	t2 = mem_read16(x + 0x11u);
	t3 = t2 + 2u;
	mem_write16(x + 0x11u, t3);
	mem_write8(x + 6u, 0x80u);
}

void sub_02D55C(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0;

	u = object_setup_02DF25_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + VIDEO_003C, 1u);
	t1 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t1 + 1u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02D56D();
	*p_y = y;
	*p_u = u;
}

void sub_02D56D(void)
{
}

void sub_02D56E(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x + VIDEO_0031, 0u);
	mem_write8(x + 0x3Du, 1u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x58u);
	if (t1 == 2u)
		mem_write8(x, 4u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 - 1u);
}

uint16_t sub_02D58A(uint16_t x)
{
	uint16_t y = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	mem_write8(x + 0x3Du, 0u);
	t1 = mem_read8(x + 5u);
	mem_write8(x + 5u, (t1 + 1u) | 0x80u);
	y = hit_box_02DB30_ADDRESS;
	sub_0785B4(x, y);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_0785C6(x);
	sub_078674(x);
	return y;
}

void sub_02D5AA(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		t1 = mem_read8(x + VIDEO_003C);
		if (t1 != 0u)
		{
			t2 = mem_read8(x + VIDEO_003C);
			mem_write8(x + VIDEO_003C, t2 - 1u);
			mem_write16(x + 0x19u, 0x200u);
			mem_write8(x, 0x88u);
		}
	}
	sub_078674(x);
}

void sub_02D5E2(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint8_t a = 0;
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t4 = 0, t5 = 0;
	uint16_t t2 = 0, t3 = 0;

	u = object_setup_02DF41_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 4u);
	mem_write16(x + 0x5Cu, 0u);
	mem_write8(x + 9u, 0x10u);
	t1 = mem_read8(x + 0x30u);
	u = loaded_table_02DF47_ADDRESS + (int8_t)(((uint32_t)t1 << 1) << 1);
	t2 = DATA16(u);
	a = (uint8_t)(t2 >> 8);
	mem_write8(x + 5u, a);
	mem_write8(x + 0x32u, a);
	mem_write8(x + 0x30u, a);
	mem_write8(x + 0x3Bu, t2);
	t3 = mem_read16(u + 2u);
	mem_write16(x + 0xCu, t3);
	t4 = mem_read8(x + VIDEO_0031);
	mem_write8(x + VIDEO_0031, t4 + 1u);
	t5 = mem_read8(x + 2u);
	mem_write8(x + 2u, t5 + 1u);
	sub_02D619();
	*p_y = y;
	*p_u = u;
}

void sub_02D619(void)
{
}

void sub_02D61A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	u = loaded_table_02DF67_ADDRESS;
	t1 = mem_read8(x + 0x29u);
	switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
	{
	case 0:
		sub_02D623(x);
		break;
	case 2:
		sub_02D643(x);
		break;
	case 4:
		y = sub_02D65C(x, y);
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D623(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	d = 0x301u;
	carry = sub_078680(d);
	mem_write8(x, 0xC8u);
	mem_write16(x + 0xFu, 0x300u);
	mem_write16(x + 0x19u, 0xFF00u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

void sub_02D643(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, ignored16 = 0;
	uint8_t t1 = 0, t2 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry == 0u)
		return;
	t1 = mem_read8(x + 0x32u);
	mem_write8(x + 5u, t1 + 1u);
	d = VIDEO_2000;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0u);
	t2 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t2 + 1u);
}

uint16_t sub_02D65C(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	t2 = mem_read8(x + 0x32u);
	mem_write8(x + 5u, t2 + 2u);
	mem_write8(x, 0xC0u);
	y = hit_box_02DA98_ADDRESS;
	sub_0785B4(x, y);
	mem_write16(x + 0x28u, 0u);
	mem_write8(x + 2u, 2u);
	return y;
}

void sub_02D683(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 0x32u);
	mem_write8(x + 5u, t1);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 - 1u);
}

void sub_02D69B(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02DF7D_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write16(x + 0x16u, 0xFF80u);
	mem_write8(x, 0x80u);
	mem_write8(x + 9u, 0x20u);
	mem_write16(x + 0x19u, VIDEO_00C0);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D6BB(uint16_t x)
{
	uint16_t d = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	t1 = mem_read16(x + 0x16u);
	d = t1;
	if ((int16_t)t1 >= 0 && d >= 0x70u)
	{
		mem_write16(x + 0x19u, 0xFF00u);
		mem_write8(x + 0x3Bu, 0x30u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02D6D4(uint16_t x)
{
	uint8_t t1 = 0, t3 = 0;
	uint16_t t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
	{
		t2 = mem_read16(x + 0x19u);
		mem_write16(x + 0x19u, 0u - t2);
		return;
	}
	mem_write8(x + 9u, 0x10u);
	mem_write16(x + 0x14u, 0xFF00u);
	mem_write16(x + 0x19u, 0x200u);
	mem_write16(x + 0x5Cu, 0x50u);
	mem_write8(x + 5u, 0x81u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
}

void sub_02D6FD(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0;

	sub_0785B1(x, &ignored16, &carry);
	if (carry)
	{
		mem_write8(x, 0xC0u);
		mem_write16(x + 0x14u, 0u);
		mem_write16(x + 4u, 0x58Cu);
		mem_write16(x + 1u, 0x102u);
		mem_write8(x + VIDEO_0031, 1u);
		mem_write8(x + 0x3Du, 0u);
	}
}

void sub_02D728(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0, t8 = 0, t10 = 0;
	uint16_t t4 = 0, t5 = 0, t6 = 0, t7 = 0, t9 = 0;

	u = object_setup_02DFA5_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	t2 = mem_read8(x + 0x30u);
	if (t2 != 0u)
	{
		t3 = io_read8(VIDEO_187F);
		io_write8(VIDEO_187F, 0u);
		mem_write16(x + 4u, 0x1007u);
		t4 = mem_read16(x + 0xCu);
		t5 = t4 + 8u;
		mem_write16(x + 0xCu, t5);
		t6 = mem_read16(x + 0x11u);
		t7 = t6 - 2u;
		mem_write16(x + 0x11u, t7);
	}
	u = rom_02DFA1_ADDRESS;
	t8 = mem_read8(x + 0x30u);
	t9 = DATA16(rom_02DFA1_ADDRESS + (int8_t)((uint32_t)t8 << 1));
	mem_write16(x + 0x3Eu, t9);
	t10 = mem_read8(x + 2u);
	mem_write8(x + 2u, t10 + 1u);
	*p_y = y;
	*p_u = u;
}

void sub_02D76E(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;
	uint8_t t3 = 0, t4 = 0;
	uint16_t t1 = 0, t2 = 0;

	t1 = unk_48AC;
	t2 = mem_read16(x + 0x3Eu);
	if (t1 < t2)
		return;
	t3 = mem_read8(x + 0x30u);
	if (t3 == 0u)
	{
		d = 0x4600u;
		carry = sub_078680(d);
	}
	mem_write16(x + 0x19u, 0x200u);
	mem_write8(x + 0x3Bu, 0x40u);
	t4 = mem_read8(x + 2u);
	mem_write8(x + 2u, t4 + 1u);
}

void sub_02D790(uint16_t x)
{
	uint8_t a = 0;
	uint8_t t1 = 0, t2 = 0;

	unk_48A7--;
	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x, 0u);
	t2 = mem_read8(x + 0x3Bu);
	a = t2;
	if (a == 0x20u)
		io_write8(VIDEO_187F, a);
}

void sub_02D7B0(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02DFBB_ADDRESS;
	y = sub_0785AB(x, u);
	mem_write8(x + 9u, 0u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	*p_y = y;
	*p_u = u;
}

uint16_t sub_02D7BD(uint16_t x, uint16_t u)
{
	uint16_t u_2 = 0;
	uint8_t t2 = 0;
	uint16_t t1 = 0;

	if ((unk_4815 & 0xFu) != 0u || (mem_read8(x) & 0x20u) == 0u)
	{
		sub_02D7D6();
		return u;
	}
	t1 = mem_read16(x + 0x40u);
	u_2 = t1;
	mem_write8(u_2 + 2u, 3u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	sub_02D7D6();
	return u_2;
}

void sub_02D7D6(void)
{
}

uint16_t sub_02D7D7(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0, y = 0;
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	y = hit_box_02DF8B_ADDRESS;
	sub_0785B4(x, y);
	t1 = mem_read8(x + VIDEO_003C);
	mem_write8(x + VIDEO_003C, t1 - 1u);
	t2 = mem_read8(x + VIDEO_003C);
	carry = (t2 >> 0) & 1u;
	if (carry)
		mem_write8(x + 0x1Du, 8u);
	d = 0x6000u;
	carry = sub_078680(d);
	mem_write8(x + 5u, 0x87u);
	t3 = mem_read8(x + 2u);
	mem_write8(x + 2u, t3 + 1u);
	return y;
}

uint16_t sub_02D7FA(uint16_t x, uint16_t y)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry == 0u)
		return y;
	y = hit_box_02DF83_ADDRESS;
	sub_0785B4(x, y);
	mem_write8(x + 0x3Bu, 0x20u);
	t2 = mem_read8(x + 2u);
	mem_write8(x + 2u, t2 + 1u);
	return y;
}

void sub_02D80F(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 5u, 0x88u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02D81D(uint16_t x)
{
	uint32_t carry = 0;
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 6u);
	carry = (t1 >> 0) & 1u;
	if (carry)
	{
		mem_write8(x + 0x3Bu, 0x40u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02D82C(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
		mem_write8(x + 2u, 1u);
}

void sub_02D86A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint32_t carry = 0;
	uint16_t ignored16 = 0, u = 0, y = 0;
	uint8_t t1 = 0, t7 = 0;
	uint16_t t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	u = object_setup_02DFD9_ADDRESS;
	sub_0785AB(x, u);
	mem_write8(x, 0x80u);
	t1 = mem_read8(x + 9u);
	mem_write8(x + 9u, (t1 & 0xCFu) | 0x20u);
	t2 = mem_read16(x + 0xCu);
	t3 = t2 + unk_48AC;
	t4 = t3 - 0x30u;
	mem_write16(x + 0x3Eu, t4);
	y = child_object_02DFD1_ADDRESS;
	sub_07862C(x, y, &u, &ignored16, &carry);
	mem_write16(x + 0x40u, u);
	mem_write16(x + 0xCu, 0x18Eu);
	t5 = mem_read16(x + 0x11u);
	t6 = t5 - 6u;
	mem_write16(x + 0x11u, t6);
	mem_write16(x + 0xFu, 0xFF00u);
	mem_write8(x + 0x3Bu, 0x40u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 + 1u);
	sub_0785C6(x);
	*p_y = y;
	*p_u = u;
}

void sub_02D8B4(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x + 0x3Bu, 0x20u);
		mem_write16(x + 0xFu, 0u);
		mem_write8(x + 5u, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02D8CA(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t7 = 0;
	uint16_t t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 != 1u)
		return;
	mem_write8(x + 0x3Bu, (unk_4858 & 0x3Fu) + 0x10u);
	t2 = mem_read8(x + VIDEO_0031);
	if (t2 == 0u)
	{
		mem_write16(x + 0xFu, 0xFF00u);
		if ((int8_t)unk_4858 >= 0)
		{
			t3 = mem_read16(x + 0xFu);
			mem_write16(x + 0xFu, 0u - t3);
		}
	}
	else
	{
		t4 = mem_read16(x + 0xCu);
		t5 = t4 + unk_48AC;
		t6 = mem_read16(x + 0x3Eu);
		if (t6 <= t5)
			mem_write16(x + 0xFu, 0xFF00u);
		else
			mem_write16(x + 0xFu, 0x100u);
	}
	mem_write8(x + 5u, 0x81u);
	t7 = mem_read8(x + 2u);
	mem_write8(x + 2u, t7 - 1u);
	sub_0785C6(x);
}

uint16_t sub_02D913(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t5 = 0, t6 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	mem_write16(x + 0xFu, 0x400u);
	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	if (t3 <= t2)
	{
		t4 = mem_read16(x + 0xFu);
		mem_write16(x + 0xFu, 0u - t4);
		t5 = mem_read8(x + VIDEO_0031);
		mem_write8(x + VIDEO_0031, t5 + 1u);
	}
	mem_write8(x + 5u, 0x81u);
	t6 = mem_read8(x + 2u);
	mem_write8(x + 2u, t6 + 1u);
	sub_0785C6(x);
	return u;
}

uint16_t sub_02D935(uint16_t x)
{
	uint16_t u = 0;
	uint8_t t8 = 0, t9 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0;

	t1 = mem_read16(x + 0x40u);
	u = t1;
	t2 = mem_read16(x + 0xCu);
	t3 = mem_read16(u + 0xCu);
	t4 = t2 - t3;
	t5 = t4;
	t6 = t5 >> 15 ? 0u - t5 : t5;
	if (t6 < 4u)
	{
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0xFF00u);
		mem_write8(x + 0x3Bu, 8u);
		t7 = mem_read16(x + 0x40u);
		u = t7;
		mem_write8(u + 2u, 3u);
		mem_write8(x + 5u, 0x81u);
		t8 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t8 & 0xCFu) | 0x10u);
		t9 = mem_read8(x + 2u);
		mem_write8(x + 2u, t9 + 1u);
	}
	return u;
}

void sub_02D96D(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 0x3Bu, 0x20u);
		mem_write8(x + 5u, 0x80u);
		t2 = mem_read8(x + 2u);
		mem_write8(x + 2u, t2 + 1u);
	}
}

void sub_02D983(uint16_t x)
{
	uint8_t t1 = 0, t2 = 0, t3 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		t2 = mem_read8(x + 9u);
		mem_write8(x + 9u, (t2 & 0xCFu) | 0x20u);
		mem_write16(x + 0xFu, 0u);
		mem_write16(x + 0x14u, 0x100u);
		mem_write8(x + 0x3Bu, 8u);
		mem_write8(x + 5u, 0x81u);
		t3 = mem_read8(x + 2u);
		mem_write8(x + 2u, t3 + 1u);
	}
}

void sub_02D9A9(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write16(x + 0x14u, 0u);
		mem_write8(x + 2u, 1u);
		mem_write8(x + 0x3Bu, 1u);
	}
}

void sub_02D9C6(uint16_t x)
{
	uint32_t carry = 0;
	uint16_t d = 0;

	d = 0x6300u;
	carry = sub_078680(d);
	mem_write16(x + 0xFu, 0xFE00u);
	mem_write8(x + 5u, 0x81u);
	mem_write8(x + 2u, 0xFDu);
	sub_0785C6(x);
}

void sub_02D9DF(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t y = (uint16_t)*p_y;
	uint16_t u = 0;
	uint8_t t1 = 0;

	for (;;)
	{
		u = loaded_table_02DFE9_ADDRESS;
		t1 = mem_read8(x + 0x29u);
		switch ((int8_t)(uint8_t)((uint32_t)t1 << 1))
		{
		case 0:
			sub_02D9E8(x);
			break;
		case 2:
			sub_02D9F6(x);
			break;
		case -10:
			sub_02D9F5();
			break;
		case -8:
			sub_02D9C6(x);
			break;
		case -6:
			continue;
		case -4:
			sub_02DA0A(x, &y, &u);
			break;
		case -2:
			sub_02DA13();
			break;
		}
		break;
	}
	*p_y = y;
	*p_u = u;
}

void sub_02D9E8(uint16_t x)
{
	uint8_t t1 = 0;

	mem_write8(x + 5u, 0x82u);
	mem_write8(x + 0x3Bu, 0x40u);
	t1 = mem_read8(x + 0x29u);
	mem_write8(x + 0x29u, t1 + 1u);
	sub_02D9F5();
}

void sub_02D9F5(void)
{
}

void sub_02D9F6(uint16_t x)
{
	uint8_t t1 = 0;

	t1 = mem_read8(x + 0x3Bu);
	mem_write8(x + 0x3Bu, t1 - 1u);
	if (t1 == 1u)
	{
		mem_write8(x, 0xC0u);
		mem_write8(x + 2u, 1u);
		mem_write8(x + 5u, 0x80u);
	}
}

void sub_02DA0A(uint16_t x, uint16_t *p_y, uint16_t *p_u)
{
	uint16_t u = 0, y = 0;
	uint8_t t1 = 0;

	u = object_setup_02DFED_ADDRESS;
	y = sub_0785AB(x, u);
	t1 = mem_read8(x + 2u);
	mem_write8(x + 2u, t1 + 1u);
	sub_02DA13();
	*p_y = y;
	*p_u = u;
}

void sub_02DA13(void)
{
}
