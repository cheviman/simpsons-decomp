/**
 *    Name:        script.c
 *    Description: scripted controls for test runs (format in simpsons/script.h)
 *    Version:     0.1.0
 *    Created:     05-11-2026
 *    Modified:    05-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 */
#include "simpsons/script.h"

#include "simpsons/machine.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_PRESS_FRAMES 4

enum
{
	ACTION_PRESS,
	ACTION_HOLD,
	ACTION_RELEASE,
	ACTION_POKE,
	ACTION_END
};

/* The controls: their port (0 the coins, 1-4 the players, 5 the test port) and bit, active low */
typedef struct control
{
	const char *name;
	int port;
	uint8_t bit;
} control;

/* a player's controls: leftN rightN upN downN attackN jumpN startN */
#define PLAYER_CONTROLS(n) \
	{ "left" #n, n, SIMPSONS_LEFT }, { "right" #n, n, SIMPSONS_RIGHT }, { "up" #n, n, SIMPSONS_UP }, \
	{ "down" #n, n, SIMPSONS_DOWN }, { "attack" #n, n, SIMPSONS_ATTACK }, { "jump" #n, n, SIMPSONS_JUMP }, \
	{ "start" #n, n, SIMPSONS_START }

static const control controls[] =
{
	{ "coin1", 0, SIMPSONS_COIN1 }, { "coin2", 0, SIMPSONS_COIN2 }, { "coin3", 0, SIMPSONS_COIN3 },
	{ "coin4", 0, SIMPSONS_COIN4 }, { "service", 5, SIMPSONS_TEST_SERVICE },
	PLAYER_CONTROLS(1), PLAYER_CONTROLS(2), PLAYER_CONTROLS(3), PLAYER_CONTROLS(4)
};
#define CONTROL_COUNT (sizeof(controls) / sizeof(controls[0]))

typedef struct script_event
{
	uint64_t frame;
	int line;              /* line of the script, also the order of events in the same frame */
	int action;
	int target;            /* control index */
	uint32_t frames;       /* press: frames held */
	uint32_t address;      /* poke */
	uint8_t value;         /* poke: byte */
} script_event;

struct simpsons_script
{
	script_event *events;
	size_t count;
	size_t next;                          /* first event not applied yet */
	uint64_t frames;                      /* frames to run, from 'end'; 0 = not said */
	uint64_t release_at[CONTROL_COUNT];   /* frame a press ends; 0 = not pressed by 'press' */
};

static uint8_t *control_port(int port)
{
	return port == 0 ? &simpsons_board.coins : port == 5 ? &simpsons_board.test : &simpsons_board.players[port - 1];
}

static void set_control(int index, bool pressed)
{
	uint8_t *port = control_port(controls[index].port);
	*port = pressed ? (uint8_t)(*port & ~controls[index].bit) : (uint8_t)(*port | controls[index].bit);
}

static int find_control(const char *name)
{
	for (size_t index = 0; index < CONTROL_COUNT; index++)
		if (strcmp(controls[index].name, name) == 0)
			return (int)index;
	return -1;
}

static bool parse_unsigned(const char *text, int base, uint64_t *value)
{
	char *end;

	if (!text[0] || text[0] == '-' || text[0] == '+')
		return false;
	errno = 0;
	*value = strtoull(text, &end, base);
	return errno == 0 && *end == '\0';
}

/* One line into an event; false with 'error' set when the line is wrong */
static bool parse_event(const char *line, uint64_t previous, script_event *event, char *error, size_t error_size)
{
	char words[6][32];
	uint64_t number;
	const int fields = sscanf(line, "%31s %31s %31s %31s %31s %31s",
		words[0], words[1], words[2], words[3], words[4], words[5]);

	if (fields < 2 || fields > 5)
	{
		snprintf(error, error_size, "expected 'FRAME ACTION [ARGUMENTS]'");
		return false;
	}
	if (words[0][0] == '+')
	{
		if (!parse_unsigned(words[0] + 1, 10, &number))
		{
			snprintf(error, error_size, "bad relative frame '%s'", words[0]);
			return false;
		}
		event->frame = previous + number;
	}
	else if (!parse_unsigned(words[0], 10, &event->frame))
	{
		snprintf(error, error_size, "bad frame '%s'", words[0]);
		return false;
	}
	if (strcmp(words[1], "press") == 0 || strcmp(words[1], "hold") == 0 || strcmp(words[1], "release") == 0)
	{
		event->action = words[1][0] == 'p' ? ACTION_PRESS : words[1][0] == 'h' ? ACTION_HOLD : ACTION_RELEASE;
		event->frames = DEFAULT_PRESS_FRAMES;
		if (fields < 3 || (event->action != ACTION_PRESS && fields > 3) || fields > 4)
		{
			snprintf(error, error_size, "expected '%s INPUT%s'", words[1], event->action == ACTION_PRESS ? " [FRAMES]" : "");
			return false;
		}
		event->target = find_control(words[2]);
		if (event->target < 0)
		{
			snprintf(error, error_size, "unknown input '%s'", words[2]);
			return false;
		}
		if (fields == 4)
		{
			if (!parse_unsigned(words[3], 10, &number) || number == 0 || number > 100000)
			{
				snprintf(error, error_size, "bad frame count '%s'", words[3]);
				return false;
			}
			event->frames = (uint32_t)number;
		}
		return true;
	}
	if (strcmp(words[1], "poke") == 0)
	{
		uint64_t value;

		event->action = ACTION_POKE;
		if (fields != 4 || !parse_unsigned(words[2], 16, &number) || number > 0xffff
			|| !parse_unsigned(words[3], 16, &value) || value > 0xff)
		{
			snprintf(error, error_size, "expected 'poke ADDRESS VALUE' in hexadecimal, a 16-bit address and a byte");
			return false;
		}
		event->address = (uint32_t)number;
		event->value = (uint8_t)value;
		return true;
	}
	if (strcmp(words[1], "end") == 0)
	{
		event->action = ACTION_END;
		if (fields != 2)
		{
			snprintf(error, error_size, "expected 'end' with no arguments");
			return false;
		}
		return true;
	}
	snprintf(error, error_size, "unknown action '%s'", words[1]);
	return false;
}

static int compare_events(const void *left, const void *right)
{
	const script_event *a = (const script_event *)left;
	const script_event *b = (const script_event *)right;

	if (a->frame != b->frame)
		return a->frame < b->frame ? -1 : 1;
	return a->line - b->line;
}

simpsons_script *simpsons_script_load(const char *path, char *error, size_t error_size)
{
	FILE *input = fopen(path, "r");
	simpsons_script *script;
	char line[256];
	char problem[160];
	size_t capacity = 0;
	uint64_t previous = 0;
	int number = 0;

	if (!input)
	{
		snprintf(error, error_size, "%s: cannot be read", path);
		return NULL;
	}
	script = (simpsons_script *)calloc(1, sizeof(*script));
	if (!script)
	{
		fclose(input);
		snprintf(error, error_size, "%s: out of memory", path);
		return NULL;
	}
	while (fgets(line, sizeof(line), input))
	{
		char *comment = strchr(line, '#');
		script_event event;

		number++;
		if (comment)
			*comment = '\0';
		if (strspn(line, " \t\r\n") == strlen(line))
			continue;
		memset(&event, 0, sizeof(event));
		event.line = number;
		if (!parse_event(line, previous, &event, problem, sizeof(problem)))
		{
			snprintf(error, error_size, "%s:%d: %s", path, number, problem);
			fclose(input);
			simpsons_script_free(script);
			return NULL;
		}
		previous = event.frame;
		if (event.action == ACTION_END)
		{
			if (!script->frames || event.frame + 1 < script->frames)
				script->frames = event.frame + 1;
			continue;
		}
		if (script->count == capacity)
		{
			const size_t grown = capacity ? capacity * 2 : 64;
			script_event *events = (script_event *)realloc(script->events, grown * sizeof(*events));

			if (!events)
			{
				snprintf(error, error_size, "%s: out of memory", path);
				fclose(input);
				simpsons_script_free(script);
				return NULL;
			}
			script->events = events;
			capacity = grown;
		}
		script->events[script->count++] = event;
	}
	fclose(input);
	if (script->count)
		qsort(script->events, script->count, sizeof(*script->events), compare_events);
	return script;
}

uint64_t simpsons_script_frames(const simpsons_script *script)
{
	return script ? script->frames : 0;
}

void simpsons_script_free(simpsons_script *script)
{
	if (!script)
		return;
	free(script->events);
	free(script);
}

static void run_event(simpsons_script *script, const script_event *event, uint64_t frame)
{
	switch (event->action)
	{
	case ACTION_PRESS:
		set_control(event->target, true);
		script->release_at[event->target] = frame + event->frames;
		break;
	case ACTION_HOLD:
		set_control(event->target, true);
		script->release_at[event->target] = 0;
		break;
	case ACTION_RELEASE:
		set_control(event->target, false);
		script->release_at[event->target] = 0;
		break;
	case ACTION_POKE:
		simpsons_write((uint16_t)event->address, event->value);
		break;
	default:
		break;
	}
}

void simpsons_script_apply(simpsons_script *script, uint64_t frame)
{
	if (!script)
		return;
	for (size_t index = 0; index < CONTROL_COUNT; index++)
		if (script->release_at[index] && script->release_at[index] <= frame)
		{
			set_control((int)index, false);
			script->release_at[index] = 0;
		}
	while (script->next < script->count && script->events[script->next].frame <= frame)
		run_event(script, &script->events[script->next++], frame);
}
