/**
 *    Name:        engine/directions.c
 *    Description: speeds from a direction, the sine tables, the direction from one object to another
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
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
	uint16_t saved_heading = 0;

	saved_heading = heading;
	scaled_sine(&quarter_wave, &heading);
	OBJECT(object)->y_speed = heading;
	x_speed = (saved_heading & 0xFFu) | ((uint32_t)(uint8_t)((saved_heading >> 8) + 0x40u) << 8);
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
	uint8_t direction = 0, scaled_high = 0, scaled_low = 0, sine = 0;
	uint16_t scaled = 0;
	uint16_t sine_product = 0, sine_sixteenths = 0, negated_sine = 0;

	direction = (uint8_t)(heading >> 8);
	sine_direction = direction;
	direction &= 0x7Fu;
	if ((direction & 0x40u) != 0u)
		direction = 0u - ((direction & 0x3Fu) - 0x40u);
	sine = mem_read8(quarter_wave + (int8_t)direction);
	if ((uint8_t)heading != 0u)
	{
		sine_product = (uint32_t)sine * (uint8_t)heading;
		heading = sine_product;
		sine = (uint8_t)(sine_product >> 8);
	}
	sine_sixteenths = (uint16_t)(((uint32_t)sine << 8) | (heading & 0xFFu)) >> 4;
	scaled_low = (uint8_t)sine_sixteenths;
	scaled_high = (uint8_t)(sine_sixteenths >> 8);
	if ((int8_t)sine_direction < 0)
	{
		negated_sine = 0u - (((uint32_t)scaled_high << 8) | (scaled_low & 0xFFu));
		scaled_low = (uint8_t)negated_sine;
		scaled_high = (uint8_t)(negated_sine >> 8);
	}
	scaled = (scaled_low & 0xFFu) | ((uint32_t)scaled_high << 8);
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
	uint8_t direction = 0, speed_high = 0, speed_low = 0;
	uint16_t scaled = 0;
	uint16_t sine_speed = 0, negated_speed = 0;

	direction = (uint8_t)(heading >> 8);
	sine_direction = direction;
	direction &= 0x7Fu;
	if ((direction & 0x40u) != 0u)
		direction = 0u - ((direction & 0x3Fu) - 0x40u);
	sine_speed = (uint32_t)mem_read8(quarter_wave + (int8_t)direction) << 4;
	speed_high = (uint8_t)(sine_speed >> 8);
	speed_low = (uint8_t)sine_speed;
	if ((int8_t)sine_direction < 0)
	{
		negated_speed = 0u - (((uint32_t)speed_high << 8) | speed_low);
		speed_high = (uint8_t)(negated_speed >> 8);
		speed_low = (uint8_t)negated_speed;
	}
	scaled = ((uint32_t)speed_high << 8) | speed_low;
	return scaled;
}

/* Sets the object's y and x speeds to walk in a direction (in 256ths of a turn) at the walking speed. */
uint16_t set_walk_speeds_from_direction(uint16_t object, uint16_t u, uint16_t heading)
{
	uint8_t speed_high = 0, speed_low = 0;
	uint16_t across_heading = 0, quarter_wave = 0, u_2 = 0;
	uint8_t saved_u_low = 0, saved_u_high = 0, heading_angle = 0;

	saved_u_high = u >> 8;
	saved_u_low = (uint8_t)u;
	heading_angle = heading >> 8;
	walk_sine(&quarter_wave, &heading);
	speed_high = (uint8_t)(heading >> 8);
	speed_low = (uint8_t)heading;
	OBJECT(object)->y_speed = ((uint32_t)speed_high << 8) | speed_low;
	across_heading = (heading & 0xFFu) | ((uint32_t)(uint8_t)(heading_angle + 0x40u) << 8);
	across_heading = walk_sine_from_table(quarter_wave, across_heading);
	speed_high = (uint8_t)(across_heading >> 8);
	speed_low = (uint8_t)across_heading;
	OBJECT(object)->x_speed = ((uint32_t)speed_high << 8) | speed_low;
	u_2 = ((uint32_t)saved_u_high << 8) | saved_u_low;
	return u_2;
}

/* The direction from the object to a point beside the other one, a signed number of pixels away from it
   in x. */
uint16_t direction_to_beside(uint16_t object, uint16_t other, uint8_t x_offset)
{
	uint8_t angle = 0, difference_high = 0, difference_low = 0, shifts = 0;
	uint16_t direction = 0;
	uint8_t saved_x_offset = 0;
	uint8_t shifts_left_2 = 0, shifts_to_go_2 = 0, shifts_left = 0, shifts_to_go = 0;
	uint16_t x_offset_word = 0, other_x = 0, beside_x = 0, own_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, other_y = 0, own_y = 0, y_difference = 0, signed_y_difference = 0, y_distance = 0;

	difference_low = (uint8_t)x_offset;
	saved_x_offset = difference_low;
	x_offset_word = (int8_t)difference_low;
	other_x = OBJECT(other)->x;
	beside_x = x_offset_word + other_x;
	own_x = OBJECT(object)->x;
	x_difference = beside_x - own_x;
	difference_high = (uint8_t)(x_difference >> 8);
	difference_low = (uint8_t)x_difference;
	direction_dx_sign = difference_high;
	signed_x_difference = ((uint32_t)difference_high << 8) | difference_low;
	x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
	direction_dx = x_distance;
	other_y = OBJECT(other)->y;
	own_y = OBJECT(object)->y;
	y_difference = other_y - own_y;
	difference_high = (uint8_t)(y_difference >> 8);
	direction_dy_sign = difference_high;
	signed_y_difference = ((uint32_t)difference_high << 8) | (uint8_t)y_difference;
	y_distance = signed_y_difference >> 15 ? 0u - signed_y_difference : signed_y_difference;
	difference_high = (uint8_t)(y_distance >> 8);
	difference_low = (uint8_t)y_distance;
	direction_dy = ((uint32_t)difference_high << 8) | difference_low;
	if (direction_dx < (uint16_t)(((uint32_t)difference_high << 8) | difference_low))
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
					shifts_left_2 = shifts;
					shifts = shifts_left_2 - 1u;
				} while (shifts_left_2 != 1u);
			}
			else
			{
				do
				{
					direction_dx = direction_dx >> 1;
					shifts_to_go_2 = shifts + 1u;
					shifts = shifts_to_go_2;
				} while (shifts_to_go_2 != 0u);
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
					shifts_left = shifts;
					shifts = shifts_left - 1u;
				} while (shifts_left != 1u);
			}
			else
			{
				do
				{
					direction_dy = direction_dy >> 1;
					shifts_to_go = shifts + 1u;
					shifts = shifts_to_go;
				} while (shifts_to_go != 0u);
			}
		}
		angle = arctangents[konami_divx(direction_dy, direction_dx_low)];
	}
	if (direction_dx_sign >= 0)
	{
		if (direction_dy_sign < 0)
			angle = 0u - angle;
		direction = ((uint32_t)angle << 8) | saved_x_offset;
		return direction;
	}
	angle += 0x80u;
	if (direction_dy_sign >= 0)
		angle = 0u - angle;
	direction = ((uint32_t)angle << 8) | saved_x_offset;
	return direction;
}

/* The direction from the object to the other one, in 256ths of a turn (0 is +x, 40 +y), from the
   arctangent of the shorter distance over the longer. */
uint16_t direction_to(uint16_t object, uint16_t other)
{
	uint8_t angle = 0, b = 0, difference_high = 0, difference_low = 0, shifts = 0;
	uint16_t direction = 0;
	uint8_t direction_low = 0;
	uint8_t shifts_left_2 = 0, shifts_to_go_2 = 0, shifts_left = 0, shifts_to_go = 0;
	uint16_t other_x = 0, own_x = 0, x_difference = 0, signed_x_difference = 0, x_distance = 0, other_y = 0, own_y = 0, y_difference = 0, signed_y_difference = 0, y_distance = 0;

	direction_low = b;
	other_x = OBJECT(other)->x;
	own_x = OBJECT(object)->x;
	x_difference = other_x - own_x;
	difference_high = (uint8_t)(x_difference >> 8);
	direction_dx_sign = difference_high;
	signed_x_difference = ((uint32_t)difference_high << 8) | (uint8_t)x_difference;
	x_distance = signed_x_difference >> 15 ? 0u - signed_x_difference : signed_x_difference;
	direction_dx = x_distance;
	other_y = OBJECT(other)->y;
	own_y = OBJECT(object)->y;
	y_difference = other_y - own_y;
	difference_high = (uint8_t)(y_difference >> 8);
	direction_dy_sign = difference_high;
	signed_y_difference = ((uint32_t)difference_high << 8) | (uint8_t)y_difference;
	y_distance = signed_y_difference >> 15 ? 0u - signed_y_difference : signed_y_difference;
	difference_high = (uint8_t)(y_distance >> 8);
	difference_low = (uint8_t)y_distance;
	direction_dy = ((uint32_t)difference_high << 8) | difference_low;
	if (direction_dx < (uint16_t)(((uint32_t)difference_high << 8) | difference_low))
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
					shifts_left_2 = shifts;
					shifts = shifts_left_2 - 1u;
				} while (shifts_left_2 != 1u);
			}
			else
			{
				do
				{
					direction_dx = direction_dx >> 1;
					shifts_to_go_2 = shifts + 1u;
					shifts = shifts_to_go_2;
				} while (shifts_to_go_2 != 0u);
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
					shifts_left = shifts;
					shifts = shifts_left - 1u;
				} while (shifts_left != 1u);
			}
			else
			{
				do
				{
					direction_dy = direction_dy >> 1;
					shifts_to_go = shifts + 1u;
					shifts = shifts_to_go;
				} while (shifts_to_go != 0u);
			}
		}
		angle = arctangents[konami_divx(direction_dy, direction_dx_low)];
	}
	if (direction_dx_sign >= 0)
	{
		if (direction_dy_sign < 0)
			angle = 0u - angle;
		direction = ((uint32_t)angle << 8) | direction_low;
		return direction;
	}
	angle += 0x80u;
	if (direction_dy_sign >= 0)
		angle = 0u - angle;
	direction = ((uint32_t)angle << 8) | direction_low;
	return direction;
}
