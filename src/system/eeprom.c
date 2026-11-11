/**
 *    Name:        system/eeprom.c
 *    Description: the EEPROM's test and reset (bank 2F's entries)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    11-11-2026
 *    Author:      Sebastian Toyos
 *
 *    The Simpsons (arcade, Konami 1991): the game's 053248 program decompiled into C by
 *    tools/decompile.py, with the names of symbols.txt.
 */
#include "game.h"

/* Writes every EEPROM address with its own number and reads it back: 0 good, 1 bad */
uint16_t eeprom_test(void)
{
	uint8_t address = 0, data = 0;
	uint16_t bad = 0, cell = 0;
	uint16_t next_cell = 0;

	address = 0u;
	data = 0u;
	do
	{
		cell = ((uint32_t)address << 8) | data;
		eeprom_write(cell);
		next_cell = (((uint32_t)address << 8) | data) + 0x101u;
		address = (uint8_t)(next_cell >> 8);
		data = (uint8_t)next_cell;
	} while (address < 0x80u);
	eeprom_test_address = 0u;
	address = 0u;
	do
	{
		cell = (cell & 0xFFu) | ((uint32_t)address << 8);
		cell = eeprom_read(cell);
		address = (uint8_t)(cell >> 8);
		data = (uint8_t)cell;
		if (data != eeprom_test_address)
		{
			bad = 0x100u | data;
			return bad;
		}
		address++;
		eeprom_test_address++;
	} while (address < 0x80u);
	bad = data;
	return bad;
}

/* Unused: a slot of the test mode's bank that jumps to eeprom_write_sum. */
void unused_vector_eeprom_write_sum(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	eeprom_write_sum(&ignored16, &ignored16_2);
}

/* Writes the factory settings into the EEPROM */
void eeprom_reset_settings(void)
{
	uint16_t ignored16 = 0, ignored16_2 = 0;

	eeprom_write_defaults(&ignored16, &ignored16_2);
}

/* Checks the settings' sum against the one stored: B 0 good, 3 bad */
uint16_t eeprom_verify(void)
{
	uint8_t address = 0, d = 0, stored_high = 0, stored_high_2 = 0, stored_low = 0;
	uint16_t bad = 0, cell = 0;
	uint8_t stack = 0;

	eeprom_sum();
	cell = (d & 0xFFu) | 0x7E00u;
	cell = eeprom_read(cell);
	address = (uint8_t)(cell >> 8);
	stored_high_2 = (uint8_t)cell;
	stack = stored_high_2;
	cell = (cell & 0xFFu) | ((uint32_t)(uint8_t)(address + 1u) << 8);
	cell = eeprom_read(cell);
	stored_low = (uint8_t)cell;
	stored_high = stack;
	if ((uint16_t)(((uint32_t)stored_high << 8) | stored_low) == eeprom_total)
	{
		bad = (uint32_t)stored_high << 8;
		return bad;
	}
	bad = ((uint32_t)stored_high << 8) | 3u;
	return bad;
}

/* Copies the EEPROM's settings (68-7D) into the work RAM at 59F0 */
void eeprom_load_settings(void)
{
	uint8_t address = 0;
	uint16_t cell = 0, setting_place = 0;
	uint16_t setting_byte_place = 0;

	setting_place = 0x59F0u;
	address = 0x68u;
	do
	{
		cell = (cell & 0xFFu) | ((uint32_t)address << 8);
		cell = eeprom_read(cell);
		address = (uint8_t)(cell >> 8);
		setting_byte_place = setting_place;
		setting_place = setting_byte_place + 1u;
		mem_write8(setting_byte_place, (uint8_t)cell);
		address++;
	} while (address < 0x7Eu);
}

/* Reads EEPROM address A into B (for the fixed program) */
uint16_t eeprom_read_byte(uint16_t cell)
{
	return eeprom_read(cell);
}

/* Writes byte B at EEPROM address A: unlock, write, address, data, end, wait, lock */
uint16_t eeprom_write(uint16_t cell)
{
	uint16_t x = 0;

	eeprom_address = cell >> 8;
	eeprom_data = (uint8_t)cell;
	eeprom_send_unlock();
	eeprom_send_write();
	eeprom_send_address();
	eeprom_send_data();
	eeprom_deselect();
	eeprom_wait_ready();
	x = eeprom_send_lock();
	io_write8(board_control_register, board_control);
	return x;
}

/* Reads the EEPROM at address A into B */
uint16_t eeprom_read(uint16_t cell)
{
	uint8_t address = 0, data = 0;
	uint8_t stack = 0;

	address = (uint8_t)(cell >> 8);
	stack = address;
	eeprom_address = address;
	eeprom_send_read();
	eeprom_send_address();
	eeprom_receive_data();
	eeprom_deselect();
	data = eeprom_read_data;
	io_write8(board_control_register, board_control);
	cell = ((uint32_t)stack << 8) | data;
	return cell;
}

/* Sends the unlock command */
void eeprom_send_unlock(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_unlock_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
}

/* Sends the start of a write command */
void eeprom_send_write(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_write_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
}

/* Clocks out the 7 address bits of 5A00 */
void eeprom_send_address(void)
{
	uint8_t address_bits = 0, signal = 0;
	uint16_t signals = 0;
	uint16_t clock_place = 0, signal_place = 0;

	signals = 0x7CA8u;
	signal = eeprom_address_signals[0];
	address_bits = eeprom_address;
	do
	{
		if ((address_bits & 0x40u) != 0u)
			signal |= 0x80u;
		io_write8(board_control_register, signal);
		eeprom_delay();
		clock_place = signals;
		signals = clock_place + 1u;
		io_write8(board_control_register, signal | mem_read8(clock_place));
		eeprom_delay();
		address_bits = (uint32_t)address_bits << 1;
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
	} while (signal != 0xFFu);
}

/* Clocks out the 8 data bits of 5A01 */
void eeprom_send_data(void)
{
	uint8_t data_bits = 0, signal = 0;
	uint16_t signals = 0;
	uint16_t clock_place = 0, signal_place = 0;

	signals = 0x7CB7u;
	signal = eeprom_data_signals[0];
	data_bits = eeprom_data;
	do
	{
		if ((data_bits & 0x80u) != 0u)
			signal |= 0x80u;
		io_write8(board_control_register, signal);
		eeprom_delay();
		clock_place = signals;
		signals = clock_place + 1u;
		io_write8(board_control_register, signal | mem_read8(clock_place));
		eeprom_delay();
		data_bits = (uint32_t)data_bits << 1;
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
	} while (signal != 0xFFu);
}

/* Ends a command (chip select off) */
void eeprom_deselect(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_deselect_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
}

/* Waits for the EEPROM to finish writing */
void eeprom_wait_ready(void)
{
	uint8_t status_port = 0;

	do
	{
		io_write8(board_control_register, eeprom_wait_signal[0]);
		status_port = io_read8(test_eeprom_port);
	} while ((status_port & 0x20u) == 0u);
}

/* Sends the lock command */
uint16_t eeprom_send_lock(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_lock_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
	return signals;
}

/* Sends the start of a read command */
void eeprom_send_read(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_read_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
}

/* Clocks in 8 data bits into 5A02 */
void eeprom_receive_data(void)
{
	uint32_t carry = 0;
	uint8_t bits_left = 0, data_bit = 0;
	uint16_t signals = 0;
	uint8_t status_port = 0, data_line = 0, read_bits = 0, bits_left_was = 0;
	uint16_t signal_place = 0, clock_place = 0;
	uint32_t read_bits_shifted = 0;

	signals = eeprom_receive_bits_ADDRESS;
	bits_left = 8u;
	carry = 0u;
	eeprom_read_data = 0u;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		io_write8(board_control_register, mem_read8(signal_place));
		eeprom_delay();
		clock_place = signals;
		signals = clock_place + 1u;
		io_write8(board_control_register, mem_read8(clock_place));
		eeprom_delay();
		status_port = io_read8(test_eeprom_port);
		data_line = status_port & 0x10u;
		data_bit = data_line;
		if (data_line != 0u)
			data_bit = 1u;
		read_bits = eeprom_read_data;
		read_bits_shifted = ((uint32_t)read_bits << 1) | carry;
		carry = read_bits >> 7;
		eeprom_read_data = read_bits_shifted;
		eeprom_read_data |= data_bit;
		bits_left_was = bits_left;
		bits_left = bits_left_was - 1u;
	} while (bits_left_was != 1u);
}

/* Unused: clocks eight 1 bits into the EEPROM. */
void unused_eeprom_send_ones(void)
{
	uint8_t signal = 0;
	uint16_t signals = 0;
	uint16_t signal_place = 0;

	signals = eeprom_ones_bits_ADDRESS;
	do
	{
		signal_place = signals;
		signals = signal_place + 1u;
		signal = mem_read8(signal_place);
		io_write8(board_control_register, signal);
		eeprom_delay();
	} while (signal != 0xFFu);
}

/* Kicks the watchdog and waits between the EEPROM's signals */
void eeprom_delay(void)
{
	uint8_t watchdog_read = 0;

	watchdog_read = io_read8(watchdog_port);
}

/* Writes the factory settings from 68 on, then the sum */
void eeprom_write_defaults(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t address = 0, data = 0;
	uint16_t cell = 0, d = 0, defaults = 0, x = 0;
	uint16_t default_place = 0;

	defaults = eeprom_factory_settings_ADDRESS;
	address = 0x68u;
	for (;;)
	{
		default_place = defaults;
		defaults = default_place + 1u;
		data = mem_read8(default_place);
		if (data == 0xFFu)
			break;
		cell = ((uint32_t)address << 8) | data;
		eeprom_write(cell);
		address++;
	}
	*p_x = x;
	*p_d = d;
	eeprom_write_sum(p_x, p_d);
}

/* Writes the sum of EEPROM 00-7D at 7E-7F */
void eeprom_write_sum(uint16_t *p_x, uint16_t *p_d)
{
	uint8_t address = 0;
	uint16_t cell = 0, x = 0;

	eeprom_sum();
	address = 0x7Eu;
	cell = 0x7E00u | eeprom_total_high;
	eeprom_write(cell);
	cell = ((uint32_t)(uint8_t)(address + 1u) << 8) | eeprom_total_low;
	x = eeprom_write(cell);
	*p_x = x;
	*p_d = cell;
}

/* Adds up EEPROM 00-7D into the scratch word */
void eeprom_sum(void)
{
	uint8_t total_low = 0;
	uint16_t cell = 0;
	uint16_t new_total = 0;

	total_low = 0u;
	eeprom_total = 0u;
	eeprom_sum_address = 0u;
	do
	{
		cell = (total_low & 0xFFu) | ((uint32_t)eeprom_sum_address << 8);
		cell = eeprom_read(cell);
		new_total = (cell & 0xFFu) + eeprom_total;
		total_low = (uint8_t)new_total;
		eeprom_total = ((uint32_t)(new_total >> 8) << 8) | (total_low & 0xFFu);
		eeprom_sum_address++;
	} while (eeprom_sum_address < 0x7Eu);
}
