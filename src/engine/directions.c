/**
 *    Name:        engine/directions.c
 *    Description: speeds from a direction, the sine tables, the direction from one object to another
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Sets the object's y and x speeds from a direction (in 256ths of a turn, 40 a quarter: 0 is +x, 40 +y)
   and a speed: the speed times the sine and the cosine, over 16. */
void set_speeds_from_direction(uint16_t object, uint16_t heading)
{
	uint16_t quarter_wave = 0, x_speed = 0;
	uint16_t stack = 0;

	stack = heading;
	scaled_sine(&quarter_wave, &heading);
	OBJECT(object)->y_speed = heading;
	x_speed = (stack & 0xFFu) | ((uint32_t)(uint8_t)((stack >> 8) + 0x40u) << 8);
	x_speed = scaled_sine_from_table(quarter_wave, x_speed);
	OBJECT(object)->x_speed = x_speed;
}

/* The sine of a direction (sines) times a factor, over 16, signed. */
void scaled_sine(uint16_t *p_quarter_wave, uint16_t *p_heading)
{
	uint16_t heading = (uint16_t)*p_heading;
	uint16_t quarter_wave = 0;

	quarter_wave = sines_ADDRESS;
	heading = scaled_sine_from_table(quarter_wave, heading);
	*p_quarter_wave = quarter_wave;
	*p_heading = heading;
}

/* The sine of a direction times a factor, over 16, signed, from the quarter-wave table given. */
uint16_t scaled_sine_from_table(uint16_t quarter_wave, uint16_t heading)
{
	uint8_t a = 0, d = 0, direction = 0, sine = 0;
	uint16_t scaled = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	direction = (uint8_t)(heading >> 8);
	sine_direction = direction;
	direction &= 0x7Fu;
	if ((direction & 0x40u) != 0u)
		direction = 0u - ((direction & 0x3Fu) - 0x40u);
	sine = mem_read8(quarter_wave + (int8_t)direction);
	if ((uint8_t)heading != 0u)
	{
		t1 = (uint32_t)sine * (uint8_t)heading;
		heading = t1;
		sine = (uint8_t)(t1 >> 8);
	}
	t2 = (uint16_t)(((uint32_t)sine << 8) | (heading & 0xFFu)) >> 4;
	d = (uint8_t)t2;
	a = (uint8_t)(t2 >> 8);
	if ((int8_t)sine_direction < 0)
	{
		t3 = 0u - (((uint32_t)a << 8) | (d & 0xFFu));
		d = (uint8_t)t3;
		a = (uint8_t)(t3 >> 8);
	}
	scaled = (d & 0xFFu) | ((uint32_t)a << 8);
	return scaled;
}

/* The sine of a direction at the walking speed (sines_20 times 16: 0140 at a quarter), signed. */
void walk_sine(uint16_t *p_quarter_wave, uint16_t *p_heading)
{
	uint16_t heading = (uint16_t)*p_heading;
	uint16_t quarter_wave = 0;

	quarter_wave = sines_20_ADDRESS;
	heading = walk_sine_from_table(quarter_wave, heading);
	*p_quarter_wave = quarter_wave;
	*p_heading = heading;
}

/* The sine of a direction from the quarter-wave table given, times 16, signed. */
uint16_t walk_sine_from_table(uint16_t quarter_wave, uint16_t heading)
{
	uint8_t a = 0, b = 0, direction = 0;
	uint16_t scaled = 0;
	uint16_t t1 = 0, t2 = 0;

	direction = (uint8_t)(heading >> 8);
	sine_direction = direction;
	direction &= 0x7Fu;
	if ((direction & 0x40u) != 0u)
		direction = 0u - ((direction & 0x3Fu) - 0x40u);
	t1 = (uint32_t)mem_read8(quarter_wave + (int8_t)direction) << 4;
	a = (uint8_t)(t1 >> 8);
	b = (uint8_t)t1;
	if ((int8_t)sine_direction < 0)
	{
		t2 = 0u - (((uint32_t)a << 8) | b);
		a = (uint8_t)(t2 >> 8);
		b = (uint8_t)t2;
	}
	scaled = ((uint32_t)a << 8) | b;
	return scaled;
}

/* Sets the object's y and x speeds to walk in a direction (in 256ths of a turn) at the walking speed. */
uint16_t set_walk_speeds_from_direction(uint16_t object, uint16_t u, uint16_t heading)
{
	uint8_t a = 0, b = 0;
	uint16_t d = 0, quarter_wave = 0, u_2 = 0;
	uint8_t stack = 0, stack_2 = 0, stack_4 = 0;

	stack_2 = u >> 8;
	stack = (uint8_t)u;
	stack_4 = heading >> 8;
	walk_sine(&quarter_wave, &heading);
	a = (uint8_t)(heading >> 8);
	b = (uint8_t)heading;
	OBJECT(object)->y_speed = ((uint32_t)a << 8) | b;
	d = (heading & 0xFFu) | ((uint32_t)(uint8_t)(stack_4 + 0x40u) << 8);
	d = walk_sine_from_table(quarter_wave, d);
	a = (uint8_t)(d >> 8);
	b = (uint8_t)d;
	OBJECT(object)->x_speed = ((uint32_t)a << 8) | b;
	u_2 = ((uint32_t)stack_2 << 8) | stack;
	return u_2;
}

/* The direction from the object to a point beside the other one, a signed number of pixels away from it
   in x. */
uint16_t direction_to_beside(uint16_t object, uint16_t other, uint8_t x_offset)
{
	uint8_t a = 0, angle = 0, b = 0, shifts = 0;
	uint16_t direction = 0;
	uint8_t stack = 0;
	uint8_t t13 = 0, t14 = 0, t15 = 0, t16 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0, t11 = 0, t12 = 0;

	b = (uint8_t)x_offset;
	stack = b;
	t1 = (int8_t)b;
	t2 = OBJECT(other)->x;
	t3 = t1 + t2;
	t4 = OBJECT(object)->x;
	t5 = t3 - t4;
	a = (uint8_t)(t5 >> 8);
	b = (uint8_t)t5;
	direction_dx_sign = a;
	t6 = ((uint32_t)a << 8) | b;
	t7 = t6 >> 15 ? 0u - t6 : t6;
	direction_dx = t7;
	t8 = OBJECT(other)->y;
	t9 = OBJECT(object)->y;
	t10 = t8 - t9;
	a = (uint8_t)(t10 >> 8);
	direction_dy_sign = a;
	t11 = ((uint32_t)a << 8) | (uint8_t)t10;
	t12 = t11 >> 15 ? 0u - t11 : t11;
	a = (uint8_t)(t12 >> 8);
	b = (uint8_t)t12;
	direction_dy = ((uint32_t)a << 8) | b;
	if (direction_dx < (uint16_t)(((uint32_t)a << 8) | b))
	{
		shifts = 6u;
		while (direction_dy_high != 0u)
		{
			direction_dy = direction_dy >> 1;
			shifts--;
		}
		if (shifts != 0u)
		{
			if ((int8_t)shifts >= 0)
			{
				do
				{
					direction_dx = (uint32_t)direction_dx << 1;
					t13 = shifts;
					shifts = t13 - 1u;
				} while (t13 != 1u);
			}
			else
			{
				do
				{
					direction_dx = direction_dx >> 1;
					t14 = shifts + 1u;
					shifts = t14;
				} while (t14 != 0u);
			}
		}
		angle = 0u - (arctangents[konami_divx(direction_dx, direction_dy_low)] - 0x40u);
	}
	else
	{
		shifts = 6u;
		while (direction_dx_high != 0u)
		{
			direction_dx = direction_dx >> 1;
			shifts--;
		}
		if (shifts != 0u)
		{
			if ((int8_t)shifts >= 0)
			{
				do
				{
					direction_dy = (uint32_t)direction_dy << 1;
					t15 = shifts;
					shifts = t15 - 1u;
				} while (t15 != 1u);
			}
			else
			{
				do
				{
					direction_dy = direction_dy >> 1;
					t16 = shifts + 1u;
					shifts = t16;
				} while (t16 != 0u);
			}
		}
		angle = arctangents[konami_divx(direction_dy, direction_dx_low)];
	}
	if (direction_dx_sign >= 0)
	{
		if (direction_dy_sign < 0)
			angle = 0u - angle;
		direction = ((uint32_t)angle << 8) | stack;
		return direction;
	}
	angle += 0x80u;
	if (direction_dy_sign >= 0)
		angle = 0u - angle;
	direction = ((uint32_t)angle << 8) | stack;
	return direction;
}

/* The direction from the object to the other one, in 256ths of a turn (0 is +x, 40 +y), from the
   arctangent of the shorter distance over the longer. */
uint16_t direction_to(uint16_t object, uint16_t other)
{
	uint8_t a = 0, angle = 0, b = 0, shifts = 0;
	uint16_t direction = 0;
	uint8_t stack = 0;
	uint8_t t11 = 0, t12 = 0, t13 = 0, t14 = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;

	stack = b;
	t1 = OBJECT(other)->x;
	t2 = OBJECT(object)->x;
	t3 = t1 - t2;
	a = (uint8_t)(t3 >> 8);
	direction_dx_sign = a;
	t4 = ((uint32_t)a << 8) | (uint8_t)t3;
	t5 = t4 >> 15 ? 0u - t4 : t4;
	direction_dx = t5;
	t6 = OBJECT(other)->y;
	t7 = OBJECT(object)->y;
	t8 = t6 - t7;
	a = (uint8_t)(t8 >> 8);
	direction_dy_sign = a;
	t9 = ((uint32_t)a << 8) | (uint8_t)t8;
	t10 = t9 >> 15 ? 0u - t9 : t9;
	a = (uint8_t)(t10 >> 8);
	b = (uint8_t)t10;
	direction_dy = ((uint32_t)a << 8) | b;
	if (direction_dx < (uint16_t)(((uint32_t)a << 8) | b))
	{
		shifts = 6u;
		while (direction_dy_high != 0u)
		{
			direction_dy = direction_dy >> 1;
			shifts--;
		}
		if (shifts != 0u)
		{
			if ((int8_t)shifts >= 0)
			{
				do
				{
					direction_dx = (uint32_t)direction_dx << 1;
					t11 = shifts;
					shifts = t11 - 1u;
				} while (t11 != 1u);
			}
			else
			{
				do
				{
					direction_dx = direction_dx >> 1;
					t12 = shifts + 1u;
					shifts = t12;
				} while (t12 != 0u);
			}
		}
		angle = 0u - (arctangents[konami_divx(direction_dx, direction_dy_low)] - 0x40u);
	}
	else
	{
		shifts = 6u;
		while (direction_dx_high != 0u)
		{
			direction_dx = direction_dx >> 1;
			shifts--;
		}
		if (shifts != 0u)
		{
			if ((int8_t)shifts >= 0)
			{
				do
				{
					direction_dy = (uint32_t)direction_dy << 1;
					t13 = shifts;
					shifts = t13 - 1u;
				} while (t13 != 1u);
			}
			else
			{
				do
				{
					direction_dy = direction_dy >> 1;
					t14 = shifts + 1u;
					shifts = t14;
				} while (t14 != 0u);
			}
		}
		angle = arctangents[konami_divx(direction_dy, direction_dx_low)];
	}
	if (direction_dx_sign >= 0)
	{
		if (direction_dy_sign < 0)
			angle = 0u - angle;
		direction = ((uint32_t)angle << 8) | stack;
		return direction;
	}
	angle += 0x80u;
	if (direction_dy_sign >= 0)
		angle = 0u - angle;
	direction = ((uint32_t)angle << 8) | stack;
	return direction;
}
