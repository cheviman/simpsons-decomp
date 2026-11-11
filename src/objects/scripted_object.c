/**
 *    Name:        objects/scripted_object.c
 *    Description: the object that runs a script of commands (types E8, E9, 2A)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Runs a scripted object: moves it, then runs its script's commands until one waits */
uint16_t scripted_object(uint16_t object, uint16_t rise_speed)
{
	bool L_03DC18 = false;
	uint32_t negative = 0;
	uint8_t floor_height = 0, floor_value = 0, landing_height = 0, landing_z_high = 0, landing_z_low = 0, wait_x_high = 0, wait_x_low = 0, x_high = 0, x_low = 0, zoom = 0, zoom_bits = 0;
	uint16_t command_handlers = 0, floor_cell = 0, script_cursor = 0;
	uint8_t kind = 0, parameter = 0, zoom_flags = 0, zoom_step = 0, zoom_x = 0, landing_floor = 0, wait = 0;
	uint16_t screen_x = 0, acceleration_x = 0, x_speed = 0, new_x_speed = 0, acceleration_y = 0, y_speed = 0, new_y_speed = 0, acceleration_z = 0, z_speed = 0, new_z_speed = 0, new_floor_z = 0, wait_x = 0, current_x = 0, z_speed_2 = 0, landing_z = 0, z = 0, script = 0, command_place = 0;

	screen_x = OBJECT(object)->x;
	x_high = (uint8_t)(screen_x >> 8);
	x_low = (uint8_t)screen_x;
	if ((uint16_t)(((uint32_t)x_high << 8) | x_low) > 0x1A0u || (int16_t)(((uint32_t)x_high << 8) | x_low) < 0x20)
	{
		OBJECT(object)->flags = 0u;
		return rise_speed;
	}
	kind = OBJECT(object)->kind;
	if (kind == 0u)
	{
		parameter = OBJECT(object)->parameter;
		OBJECT(object)->scripted_object.script = scripted_object_scripts[(int8_t)((uint8_t)((uint32_t)parameter << 1)) / 2];
		OBJECT(object)->flags = 0x80u;
		OBJECT(object)->scripted_object.landing_floor = -1;
		L_03DC18 = true;
	}
	if (!L_03DC18)
	{
		acceleration_x = OBJECT(object)->scripted_object.acceleration_x;
		x_speed = OBJECT(object)->x_speed;
		new_x_speed = acceleration_x + x_speed;
		OBJECT(object)->x_speed = new_x_speed;
		acceleration_y = OBJECT(object)->scripted_object.acceleration_y;
		y_speed = OBJECT(object)->y_speed;
		new_y_speed = acceleration_y + y_speed;
		OBJECT(object)->y_speed = new_y_speed;
		acceleration_z = OBJECT(object)->scripted_object.acceleration_z;
		z_speed = OBJECT(object)->z_speed;
		new_z_speed = acceleration_z + z_speed;
		OBJECT(object)->z_speed = new_z_speed;
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
		new_floor_z = floor_height;
		OBJECT(object)->floor_z = new_floor_z;
		wait_x = OBJECT(object)->scripted_object.wait_x;
		wait_x_high = (uint8_t)(wait_x >> 8);
		wait_x_low = (uint8_t)wait_x;
		if (wait_x != 0u)
		{
			current_x = OBJECT(object)->x;
			if ((int16_t)(((uint32_t)wait_x_high << 8) | wait_x_low) < (int16_t)current_x)
				return rise_speed;
			OBJECT(object)->scripted_object.wait_x = 0u;
			L_03DC18 = true;
		}
		if (!L_03DC18)
		{
			landing_floor = OBJECT(object)->scripted_object.landing_floor;
			landing_height = landing_floor;
			if ((int8_t)landing_floor >= 0)
			{
				z_speed_2 = OBJECT(object)->z_speed;
				rise_speed = z_speed_2;
				if ((int16_t)rise_speed > 0)
					return rise_speed;
				landing_z = (int8_t)landing_height;
				landing_z_high = (uint8_t)(landing_z >> 8);
				landing_z_low = (uint8_t)landing_z;
				z = OBJECT(object)->z;
				if ((int16_t)(((uint32_t)landing_z_high << 8) | landing_z_low) < (int16_t)z)
					return rise_speed;
				OBJECT(object)->z = ((uint32_t)landing_z_high << 8) | landing_z_low;
				OBJECT(object)->scripted_object.landing_floor = -1;
				OBJECT(object)->x_speed = 0;
				OBJECT(object)->y_speed = 0;
				OBJECT(object)->z_speed = 0;
				OBJECT(object)->scripted_object.acceleration_x = 0;
				OBJECT(object)->scripted_object.acceleration_y = 0;
				OBJECT(object)->scripted_object.acceleration_z = 0;
				L_03DC18 = true;
			}
			if (!L_03DC18)
			{
				wait = OBJECT(object)->scripted_object.wait;
				OBJECT(object)->scripted_object.wait = wait - 1u;
				if (wait != 1u)
					return rise_speed;
			}
		}
	}
	script = OBJECT(object)->scripted_object.script;
	command_place = script;
	leftover_y = command_place + 1u;
	command_handlers = scripted_object_commands_ADDRESS;
	switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
	{
	case 0:
		return scripted_object_set_attributes(object);
	case 2:
		script_cursor = (uint16_t)leftover_y;
		scripted_object_wait(object, script_cursor);
		return command_handlers;
	case 4:
		scripted_object_end(object);
		return command_handlers;
	case 6:
		return scripted_object_set_kind(object);
	case 8:
		return scripted_object_set_animation(object);
	case 10:
		return scripted_object_set_place(object);
	case 12:
		return scripted_object_set_speeds(object);
	case 14:
		return scripted_object_set_accelerations(object);
	case 16:
		return scripted_object_toggle_airborne(object);
	case 18:
		return scripted_object_set_shadow(object);
	case 20:
		script_cursor = (uint16_t)leftover_y;
		scripted_object_wait_landing(object, script_cursor);
		return command_handlers;
	case 22:
		return scripted_object_play_sound(object);
	case 24:
		return scripted_object_set_zoom(object);
	case 26:
		return scripted_object_set_zoom_step(object);
	case 28:
		return scripted_object_stop(object);
	case 30:
		script_cursor = (uint16_t)leftover_y;
		scripted_object_wait_x(object, script_cursor);
		return command_handlers;
	}
	unreachable();
}

/* Command 00: its sprite attributes (field 09) */
uint16_t scripted_object_set_attributes(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 1u;
		OBJECT(object)->attributes = mem_read8(leftover_y);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			continue;
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 01: waits that many frames */
void scripted_object_wait(uint16_t object, uint16_t script_cursor)
{
	uint16_t script = 0;
	uint16_t operand_place = 0;

	operand_place = script_cursor;
	script = operand_place + 1u;
	OBJECT(object)->scripted_object.wait = mem_read8(operand_place);
	OBJECT(object)->scripted_object.script = script;
	leftover_y = script;
}

/* Command 02: removes the object */
void scripted_object_end(uint16_t object)
{
	OBJECT(object)->flags = 0u;
}

/* Command 03: its kind and animation */
uint16_t scripted_object_set_kind(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t kind_with_animation = 0, command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 2u;
		kind_with_animation = mem_read16(leftover_y);
		OBJECT(object)->kind = (uint8_t)(kind_with_animation >> 8u);
		OBJECT(object)->animation = (uint8_t)kind_with_animation;
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			continue;
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 04: its animation */
uint16_t scripted_object_set_animation(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 1u;
		OBJECT(object)->animation = mem_read8(leftover_y);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			continue;
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 05: its place, y from the camera's */
uint16_t scripted_object_set_place(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t y_place = 0, z_place = 0, command_place = 0;

	for (;;)
	{
		OBJECT(object)->x = mem_read16(leftover_y);
		y_place = leftover_y + 2u;
		OBJECT(object)->y = mem_read16(y_place) + camera_y;
		z_place = y_place + 2u;
		script_cursor = z_place + 2u;
		OBJECT(object)->z = mem_read16(z_place);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(command_place) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			continue;
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 06: its three speeds */
uint16_t scripted_object_set_speeds(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t y_speed_place = 0, z_speed_place = 0, command_place = 0;

	for (;;)
	{
		OBJECT(object)->x_speed = mem_read16(leftover_y);
		y_speed_place = leftover_y + 2u;
		OBJECT(object)->y_speed = mem_read16(y_speed_place);
		z_speed_place = y_speed_place + 2u;
		script_cursor = z_speed_place + 2u;
		OBJECT(object)->z_speed = mem_read16(z_speed_place);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(command_place) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			continue;
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 07: what is added to its speeds each frame */
uint16_t scripted_object_set_accelerations(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t y_acceleration_place = 0, z_acceleration_place = 0, command_place = 0;

	for (;;)
	{
		OBJECT(object)->scripted_object.acceleration_x = mem_read16(leftover_y);
		y_acceleration_place = leftover_y + 2u;
		OBJECT(object)->scripted_object.acceleration_y = mem_read16(y_acceleration_place);
		z_acceleration_place = y_acceleration_place + 2u;
		script_cursor = z_acceleration_place + 2u;
		OBJECT(object)->scripted_object.acceleration_z = mem_read16(z_acceleration_place);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)((uint16_t)((uint32_t)(uint8_t)((uint32_t)((uint16_t)((uint32_t)mem_read8(command_place) << 8) >> 8) << 1) << 8) >> 8))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			continue;
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 08: flips the in-the-air bit of its flags */
uint16_t scripted_object_toggle_airborne(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		OBJECT(object)->flags ^= 8u;
		command_place = leftover_y;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			continue;
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 09: its field 5B (the shadow it shows) */
uint16_t scripted_object_set_shadow(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 1u;
		OBJECT(object)->shadow_player = mem_read8(leftover_y);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			continue;
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 0A: waits until it falls to that floor height */
void scripted_object_wait_landing(uint16_t object, uint16_t script_cursor)
{
	uint16_t script = 0;
	uint16_t operand_place = 0;

	operand_place = script_cursor;
	script = operand_place + 1u;
	OBJECT(object)->scripted_object.landing_floor = mem_read8(operand_place);
	OBJECT(object)->scripted_object.script = script;
	leftover_y = script;
}

/* Command 0B: queues a sound command, unless its field 30 is negative */
uint16_t scripted_object_play_sound(uint16_t object)
{
	uint8_t sound = 0, sound_argument = 0;
	uint16_t command = 0, command_handlers = 0, script_cursor = 0;
	uint16_t stack = 0;
	uint8_t parameter = 0;
	uint16_t sound_word = 0, command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 2u;
		sound_word = mem_read16(leftover_y);
		sound_argument = (uint8_t)sound_word;
		sound = (uint8_t)(sound_word >> 8);
		parameter = OBJECT(object)->parameter;
		if ((int8_t)parameter >= 0)
		{
			stack = script_cursor;
			command = (sound_argument & 0xFFu) | ((uint32_t)sound << 8);
			vector_queue_sound(command);
			script_cursor = stack;
		}
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			continue;
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 0C: its zoom, and starts or stops it growing */
uint16_t scripted_object_set_zoom(uint16_t object)
{
	uint8_t zoom = 0;
	uint16_t command_handlers = 0, script_cursor = 0;
	uint8_t zoom_flags = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 1u;
		zoom = mem_read8(leftover_y);
		OBJECT(object)->zoom_x = zoom;
		OBJECT(object)->zoom_y = zoom;
		zoom_flags = OBJECT(object)->scripted_object.zoom_flags;
		OBJECT(object)->scripted_object.zoom_flags = zoom_flags ^ 0x10u;
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			continue;
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 0D: what its zoom grows by each frame */
uint16_t scripted_object_set_zoom_step(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		script_cursor = leftover_y + 1u;
		OBJECT(object)->scripted_object.zoom_step = mem_read8(leftover_y);
		command_place = script_cursor;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			continue;
		case 28:
			return scripted_object_stop(object);
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 0E: stops it */
uint16_t scripted_object_stop(uint16_t object)
{
	uint16_t command_handlers = 0, script_cursor = 0;
	uint16_t command_place = 0;

	for (;;)
	{
		OBJECT(object)->x_speed = 0;
		OBJECT(object)->y_speed = 0;
		OBJECT(object)->z_speed = 0;
		OBJECT(object)->scripted_object.acceleration_x = 0;
		OBJECT(object)->scripted_object.acceleration_y = 0;
		OBJECT(object)->scripted_object.acceleration_z = 0;
		command_place = leftover_y;
		leftover_y = command_place + 1u;
		command_handlers = scripted_object_commands_ADDRESS;
		switch ((int8_t)(uint8_t)((uint32_t)mem_read8(command_place) << 1))
		{
		case 0:
			return scripted_object_set_attributes(object);
		case 2:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait(object, script_cursor);
			return command_handlers;
		case 4:
			scripted_object_end(object);
			return command_handlers;
		case 6:
			return scripted_object_set_kind(object);
		case 8:
			return scripted_object_set_animation(object);
		case 10:
			return scripted_object_set_place(object);
		case 12:
			return scripted_object_set_speeds(object);
		case 14:
			return scripted_object_set_accelerations(object);
		case 16:
			return scripted_object_toggle_airborne(object);
		case 18:
			return scripted_object_set_shadow(object);
		case 20:
			script_cursor = (uint16_t)leftover_y;
			scripted_object_wait_landing(object, script_cursor);
			return command_handlers;
		case 22:
			return scripted_object_play_sound(object);
		case 24:
			return scripted_object_set_zoom(object);
		case 26:
			return scripted_object_set_zoom_step(object);
		case 28:
			continue;
		case 30:
			break;
		}
		break;
	}
	script_cursor = (uint16_t)leftover_y;
	scripted_object_wait_x(object, script_cursor);
	return command_handlers;
}

/* Command 0F: waits until its x reaches that place */
void scripted_object_wait_x(uint16_t object, uint16_t script_cursor)
{
	uint16_t script = 0;
	uint16_t operand_place = 0;

	operand_place = script_cursor;
	script = operand_place + 2u;
	OBJECT(object)->scripted_object.wait_x = mem_read16(operand_place);
	OBJECT(object)->scripted_object.script = script;
	leftover_y = script;
}
