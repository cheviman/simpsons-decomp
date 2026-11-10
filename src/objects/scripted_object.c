/**
 *    Name:        objects/scripted_object.c
 *    Description: the object that runs a script of commands (types E8, E9, 2A)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    09-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a scripted object: moves it, then runs its script's commands until one waits */
void scripted_object(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_u)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t u = (uint16_t)*p_u;
	uint32_t negative = 0;
	uint8_t floor_height = 0, floor_value = 0, landing_height = 0, landing_z_high = 0, landing_z_low = 0, wait_x_high = 0, wait_x_low = 0, x_high = 0, x_low = 0, zoom = 0, zoom_bits = 0;
	uint16_t command_handlers = 0, floor_cell = 0, rise_speed = 0;
	uint8_t kind = 0, zoom_flags = 0, zoom_step = 0, zoom_x = 0, landing_floor = 0, wait = 0, parameter = 0;
	uint16_t t1 = 0, acceleration_x = 0, x_speed = 0, t2 = 0, acceleration_y = 0, y_speed = 0, t3 = 0, acceleration_z = 0, z_speed = 0, t4 = 0, t5 = 0, wait_x = 0, z_speed_2 = 0, t6 = 0, z = 0, t7 = 0, script = 0, t8 = 0;

	t1 = OBJECT(object)->x;
	x_high = (uint8_t)(t1 >> 8);
	x_low = (uint8_t)t1;
	if ((uint16_t)(((uint32_t)x_high << 8) | x_low) > 0x1A0u || (int16_t)(((uint32_t)x_high << 8) | x_low) < 0x20)
	{
		OBJECT(object)->flags = 0u;
		return;
	}
	kind = OBJECT(object)->kind;
	if (kind != 0u)
	{
		acceleration_x = OBJECT(object)->scripted_object.acceleration_x;
		x_speed = OBJECT(object)->x_speed;
		t2 = acceleration_x + x_speed;
		OBJECT(object)->x_speed = t2;
		acceleration_y = OBJECT(object)->scripted_object.acceleration_y;
		y_speed = OBJECT(object)->y_speed;
		t3 = acceleration_y + y_speed;
		OBJECT(object)->y_speed = t3;
		acceleration_z = OBJECT(object)->scripted_object.acceleration_z;
		z_speed = OBJECT(object)->z_speed;
		t4 = acceleration_z + z_speed;
		OBJECT(object)->z_speed = t4;
		zoom_flags = OBJECT(object)->scripted_object.zoom_flags;
		zoom_bits = zoom_flags;
		if (zoom_flags != 0u)
		{
			OBJECT(object)->flags |= zoom_bits;
			zoom_step = OBJECT(object)->scripted_object.zoom_step;
			zoom_x = OBJECT(object)->zoom_x;
			zoom = zoom_step + zoom_x;
			OBJECT(object)->zoom_x = zoom;
			OBJECT(object)->zoom_y = zoom;
		}
		vector_floor_ahead(object, &floor_cell, &negative);
		floor_value = (uint8_t)(floor_cell >> 8);
		floor_height = 0u;
		if ((int8_t)floor_value >= 0)
			floor_height = (((floor_value & 0xFu) << 1) << 1) << 1;
		t5 = floor_height;
		OBJECT(object)->floor_z = t5;
		wait_x = OBJECT(object)->scripted_object.wait_x;
		wait_x_high = (uint8_t)(wait_x >> 8);
		wait_x_low = (uint8_t)wait_x;
		if (wait_x == 0u)
		{
			landing_floor = OBJECT(object)->scripted_object.landing_floor;
			landing_height = landing_floor;
			if ((int8_t)landing_floor < 0)
			{
				wait = OBJECT(object)->scripted_object.wait;
				OBJECT(object)->scripted_object.wait = wait - 1u;
				if (wait != 1u)
					return;
			}
			else
			{
				z_speed_2 = OBJECT(object)->z_speed;
				rise_speed = z_speed_2;
				if ((int16_t)rise_speed > 0)
				{
					*p_u = rise_speed;
					return;
				}
				t6 = (int8_t)landing_height;
				landing_z_high = (uint8_t)(t6 >> 8);
				landing_z_low = (uint8_t)t6;
				z = OBJECT(object)->z;
				if ((int16_t)(((uint32_t)landing_z_high << 8) | landing_z_low) < (int16_t)z)
				{
					*p_u = rise_speed;
					return;
				}
				OBJECT(object)->z = ((uint32_t)landing_z_high << 8) | landing_z_low;
				OBJECT(object)->scripted_object.landing_floor = -1;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				OBJECT(object)->z_speed = 0;
				OBJECT(object)->scripted_object.acceleration_x = 0;
				OBJECT(object)->scripted_object.acceleration_y = 0;
				OBJECT(object)->scripted_object.acceleration_z = 0;
			}
		}
		else
		{
			t7 = OBJECT(object)->x;
			if ((int16_t)(((uint32_t)wait_x_high << 8) | wait_x_low) < (int16_t)t7)
				return;
			OBJECT(object)->scripted_object.wait_x = 0u;
		}
	}
	else
	{
		parameter = OBJECT(object)->parameter;
		OBJECT(object)->scripted_object.script = scripted_object_scripts[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->scripted_object.landing_floor = -1;
	}
	script = OBJECT(object)->scripted_object.script;
	t8 = script;
	script_cursor = t8 + 1u;
	command_handlers = scripted_object_commands_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t8) << 1))
	{
	case 0:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_attributes(object, p_script_cursor, p_u);
		return;
	case 2:
		script_cursor = scripted_object_wait(object, script_cursor);
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		return;
	case 4:
		scripted_object_end(object);
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		return;
	case 6:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_kind(object, p_script_cursor, p_u);
		return;
	case 8:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_animation(object, p_script_cursor, p_u);
		return;
	case 10:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_place(object, p_script_cursor, p_u);
		return;
	case 12:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_speeds(object, p_script_cursor, p_u);
		return;
	case 14:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_accelerations(object, p_script_cursor, p_u);
		return;
	case 16:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_toggle_airborne(object, p_script_cursor, p_u);
		return;
	case 18:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_shadow(object, p_script_cursor, p_u);
		return;
	case 20:
		script_cursor = scripted_object_wait_landing(object, script_cursor);
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		return;
	case 22:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_play_sound(object, p_script_cursor, p_u);
		return;
	case 24:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_zoom(object, p_script_cursor, p_u);
		return;
	case 26:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_set_zoom_step(object, p_script_cursor, p_u);
		return;
	case 28:
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		scripted_object_stop(object, p_script_cursor, p_u);
		return;
	case 30:
		script_cursor = scripted_object_wait_x(object, script_cursor);
		*p_script_cursor = script_cursor;
		*p_u = command_handlers;
		return;
	}
}

/* Command 00: its sprite attributes (field 09) */
void scripted_object_set_attributes(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		OBJECT(object)->attributes = mem_read8(t1);
		t2 = script_cursor;
		script_cursor = t2 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			continue;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 01: waits that many frames */
uint16_t scripted_object_wait(uint16_t object, uint16_t script_cursor)
{
	uint16_t t1 = 0;

	t1 = script_cursor;
	script_cursor = t1 + 1u;
	OBJECT(object)->scripted_object.wait = mem_read8(t1);
	OBJECT(object)->scripted_object.script = script_cursor;
	return script_cursor;
}

/* Command 02: removes the object */
void scripted_object_end(uint16_t object)
{
	OBJECT(object)->flags = 0u;
}

/* Command 03: its kind and animation */
void scripted_object_set_kind(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 2u;
		t2 = mem_read16(t1);
		OBJECT(object)->kind = (uint8_t)(t2 >> 8u);
		OBJECT(object)->animation = (uint8_t)t2;
		t3 = script_cursor;
		script_cursor = t3 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t3) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			continue;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 04: its animation */
void scripted_object_set_animation(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		OBJECT(object)->animation = mem_read8(t1);
		t2 = script_cursor;
		script_cursor = t2 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			continue;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 05: its place, y from the camera's */
void scripted_object_set_place(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = script_cursor;
		OBJECT(object)->x = mem_read16(t1);
		t2 = t1 + 2u;
		OBJECT(object)->y = mem_read16(t2) + camera_y;
		t3 = t2 + 2u;
		script_cursor = t3 + 2u;
		OBJECT(object)->z = mem_read16(t3);
		t4 = script_cursor;
		script_cursor = t4 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			continue;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 06: its three speeds */
void scripted_object_set_speeds(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = script_cursor;
		OBJECT(object)->x_speed = mem_read16(t1);
		t2 = t1 + 2u;
		OBJECT(object)->y_speed = mem_read16(t2);
		t3 = t2 + 2u;
		script_cursor = t3 + 2u;
		OBJECT(object)->z_speed = mem_read16(t3);
		t4 = script_cursor;
		script_cursor = t4 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			continue;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 07: what is added to its speeds each frame */
void scripted_object_set_accelerations(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

	for (;;)
	{
		t1 = script_cursor;
		OBJECT(object)->scripted_object.acceleration_x = mem_read16(t1);
		t2 = t1 + 2u;
		OBJECT(object)->scripted_object.acceleration_y = mem_read16(t2);
		t3 = t2 + 2u;
		script_cursor = t3 + 2u;
		OBJECT(object)->scripted_object.acceleration_z = mem_read16(t3);
		t4 = script_cursor;
		script_cursor = t4 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(t4) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			continue;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 08: flips the in-the-air bit of its flags */
void scripted_object_toggle_airborne(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		OBJECT(object)->flags ^= 8u;
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t1) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			continue;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 09: its field 5B (the shadow it shows) */
void scripted_object_set_shadow(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		OBJECT(object)->shadow_player = mem_read8(t1);
		t2 = script_cursor;
		script_cursor = t2 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			continue;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 0A: waits until it falls to that floor height */
uint16_t scripted_object_wait_landing(uint16_t object, uint16_t script_cursor)
{
	uint16_t t1 = 0;

	t1 = script_cursor;
	script_cursor = t1 + 1u;
	OBJECT(object)->scripted_object.landing_floor = mem_read8(t1);
	OBJECT(object)->scripted_object.script = script_cursor;
	return script_cursor;
}

/* Command 0B: queues a sound command, unless its field 30 is negative */
void scripted_object_play_sound(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint32_t carry = 0;
	uint8_t sound = 0, sound_argument = 0;
	uint16_t command = 0, command_handlers = 0;
	uint16_t stack = 0;
	uint8_t parameter = 0;
	uint16_t t1 = 0, t2 = 0, t3 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 2u;
		t2 = mem_read16(t1);
		sound_argument = (uint8_t)t2;
		sound = (uint8_t)(t2 >> 8);
		parameter = OBJECT(object)->parameter;
		if ((int8_t)parameter >= 0)
		{
			stack = script_cursor;
			command = (sound_argument & 0xFFu) | ((uint32_t)sound << 8);
			carry = vector_queue_sound(command);
			script_cursor = stack;
		}
		t3 = script_cursor;
		script_cursor = t3 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t3) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			continue;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 0C: its zoom, and starts or stops it growing */
void scripted_object_set_zoom(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint8_t zoom = 0;
	uint16_t command_handlers = 0;
	uint8_t zoom_flags = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		zoom = mem_read8(t1);
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		zoom_flags = OBJECT(object)->scripted_object.zoom_flags;
		OBJECT(object)->scripted_object.zoom_flags = zoom_flags ^ 0x10u;
		t2 = script_cursor;
		script_cursor = t2 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			continue;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 0D: what its zoom grows by each frame */
void scripted_object_set_zoom_step(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0, t2 = 0;

	for (;;)
	{
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		OBJECT(object)->scripted_object.zoom_step = mem_read8(t1);
		t2 = script_cursor;
		script_cursor = t2 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t2) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			continue;
		case 28:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_stop(object, p_script_cursor, p_command_handlers);
			return;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 0E: stops it */
void scripted_object_stop(uint16_t object, uint16_t *p_script_cursor, uint16_t *p_command_handlers)
{
	uint16_t script_cursor = (uint16_t)*p_script_cursor;
	uint16_t command_handlers = 0;
	uint16_t t1 = 0;

	for (;;)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->scripted_object.acceleration_x = 0;
		OBJECT(object)->scripted_object.acceleration_y = 0;
		OBJECT(object)->scripted_object.acceleration_z = 0;
		t1 = script_cursor;
		script_cursor = t1 + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(t1) << 1))
		{
		case 0:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_attributes(object, p_script_cursor, p_command_handlers);
			return;
		case 2:
			script_cursor = scripted_object_wait(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 4:
			scripted_object_end(object);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 6:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_kind(object, p_script_cursor, p_command_handlers);
			return;
		case 8:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_animation(object, p_script_cursor, p_command_handlers);
			return;
		case 10:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_place(object, p_script_cursor, p_command_handlers);
			return;
		case 12:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_speeds(object, p_script_cursor, p_command_handlers);
			return;
		case 14:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_accelerations(object, p_script_cursor, p_command_handlers);
			return;
		case 16:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_toggle_airborne(object, p_script_cursor, p_command_handlers);
			return;
		case 18:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_shadow(object, p_script_cursor, p_command_handlers);
			return;
		case 20:
			script_cursor = scripted_object_wait_landing(object, script_cursor);
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			return;
		case 22:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_play_sound(object, p_script_cursor, p_command_handlers);
			return;
		case 24:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom(object, p_script_cursor, p_command_handlers);
			return;
		case 26:
			*p_script_cursor = script_cursor;
			*p_command_handlers = command_handlers;
			scripted_object_set_zoom_step(object, p_script_cursor, p_command_handlers);
			return;
		case 28:
			continue;
		case 30:
			break;
		}
		break;
	}
	script_cursor = scripted_object_wait_x(object, script_cursor);
	*p_script_cursor = script_cursor;
	*p_command_handlers = command_handlers;
}

/* Command 0F: waits until its x reaches that place */
uint16_t scripted_object_wait_x(uint16_t object, uint16_t script_cursor)
{
	uint16_t t1 = 0;

	t1 = script_cursor;
	script_cursor = t1 + 2u;
	OBJECT(object)->scripted_object.wait_x = mem_read16(t1);
	OBJECT(object)->scripted_object.script = script_cursor;
	return script_cursor;
}
