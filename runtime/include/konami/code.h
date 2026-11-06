/**
 *    Name:        code.h
 *    Description: the translated program's functions by the place their code starts at
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    A place is the program region's offset of the code (a bank's at its bank x 2000 plus its address in the window,
 *    the fixed program's at 078000 plus its address less 8000), sorted, for the runtime's calls and jumps through
 *    computed addresses (tools/core/konami_cpu/translate.py writes the table: build/generated/entries.c).
 */
#ifndef KONAMI_CODE_H
#define KONAMI_CODE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct konami_code_entry
{
	uint32_t place;
	void (*function)(void);
} konami_code_entry;

extern const konami_code_entry konami_code_entries[];
extern const size_t konami_code_entry_count;

#ifdef __cplusplus
}
#endif

#endif
