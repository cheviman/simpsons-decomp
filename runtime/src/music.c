/**
 *    Name:        music.c
 *    Description: the songs' Standard MIDI Files back into the sound program's music (music.h)
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    The format is tools/sound_music.py's, whose docstring says it whole; this is its way back (parse,
 *    driver_tracks, rebuild), the same steps in C:
 *      - music.txt lists the files, a song each: each line's first word (but the comments, '#'), the file's
 *        name without .mid;
 *      - a file is a Standard MIDI File; the tracks with an 'S' event (FF 7F LEN 7D 'S' NAME) are the song's 12
 *        channels, YM2151 1-8 then K053260 1-4; 'N' names the song header, 'U' gives bytes no track shows; the
 *        file's other events (tempo, names, programs, pans, pitch bends) are the writer's, for players;
 *      - a channel's events at a tick are its commands ('C': the driver's bytes, an address last as a place's
 *        name) and then a step: a note (Note On; its Note Off where the driver keys it off), a rest ('R'), a
 *        held note ('H': the bytes after E5, and its Note On), or 'Z', where the file stops showing it; a step
 *        lasts to the channel's next one;
 *      - the header's 24 bytes are the 'S' places' Z80 addresses; then each channel, one after the other, keeps
 *        the driver's record (octave, drum mode, gate, instrument and its transposition, loops, part) and its
 *        place, from 'S': a command's bytes go there and the place moves on as the driver's does; a note's byte
 *        is its length's code (note_lengths) and the pitch nibble its key gives from the octave (and the PCM
 *        instrument's transposition); a byte that comes back twice has to be the same.
 */
#include "music.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TICKS_A_QUARTER 24      /* the files' division: a driver's tick is a file's tick at it */
#define UNIT            32      /* the accumulator's units a tick */
#define SONG_TRACKS     12      /* YM2151 1-8, K053260 1-4 */
#define FM_CHANNELS     8
#define TAG             0x7D    /* the non-commercial manufacturer id of the driver's meta events */
#define DRUM_BASE       34      /* a drum routine N's key */
#define WINDOW          0x8000u /* the Z80's window onto a bank of 16 KB */
#define BANK_START      0x10000u
#define BANK_SIZE       0x4000u
#define NAME_SIZE       128
#define WHERE_SIZE      256
#define NO_TICK         (-1)

static char g_problem[512];

static int fail(const char *format, ...)
{
	va_list arguments;

	va_start(arguments, format);
	vsnprintf(g_problem, sizeof(g_problem), format, arguments);
	va_end(arguments);
	return 0;
}

static void *grow(void *list, size_t *capacity, size_t needed, size_t unit)
{
	if (needed <= *capacity)
		return list;
	*capacity = needed * 2 + 16;
	return realloc(list, *capacity * unit);
}

/* Python's //: the quotient rounded down */
static int64_t floor_div(int64_t value, int64_t by)
{
	const int64_t quotient = value / by;

	return (value % by != 0 && (value < 0) != (by < 0)) ? quotient - 1 : quotient;
}

/* ---- the driver ---- */

/* a command's bytes (an octave's and a step's 1): 0 for the ones that jump to 0000 (E8-EC, F8-FD) and E5 */
static uint32_t command_length(uint8_t command)
{
	if (command < 0xE0)
		return 1;
	switch (command)
	{
	case 0xE0: case 0xE1: case 0xE2: case 0xE3: case 0xE4: case 0xE6: case 0xEE: case 0xEF: case 0xF2: case 0xF4:
	case 0xFE:
		return 2;
	case 0xE7:
		return 10;
	case 0xED:
		return 5;
	case 0xF0:
		return 3;
	case 0xF1: case 0xF6:
		return 4;
	case 0xF3: case 0xF5: case 0xF7: case 0xFF:
		return 1;
	default:
		return 0;
	}
}

/* where a command's address is (always its last two bytes), 0 when it has none */
static uint32_t address_at(uint8_t command)
{
	switch (command)
	{
	case 0xF0: return 1;
	case 0xF1: case 0xF6: return 2;
	default: return 0;
	}
}

/* The Z80's address of a region's place (a bank's in the window 8000-BFFF) */
static uint32_t z80_address(uint32_t place)
{
	return place < WINDOW ? place : WINDOW + ((place - BANK_START) & (BANK_SIZE - 1));
}

/* a channel's record, what the way back needs of it (41AE) */
typedef struct
{
	int number, pcm;
	uint32_t place;
	uint8_t octave, mode, gate, instrument, jump_count, loop_count, loop_2_count, repeat_count;
	int32_t transposition;      /* a PCM instrument's, in the pitch table's bytes */
	uint32_t loop_start, loop_2_start, repeat_return, repeat_part;
} channel;

/* The command 'data' at the channel's place ('target' the place of the address it carries): what it does to the
   record; the place the track goes on at, -1 when it ends */
static int64_t execute(channel *ch, const uint8_t *data, uint32_t size, uint32_t target, const music_places *places)
{
	const uint32_t at = ch->place;
	const uint8_t command = data[0], argument = size > 1 ? data[1] : 0;

	if (command < 0x10)
	{
		ch->octave = command;
		return at + 1;
	}
	switch (command)
	{
	case 0xE0:
		ch->mode = argument;
		break;
	case 0xE2:
		ch->instrument = argument;
		if (ch->pcm)
			ch->transposition = argument < places->transposition_count ? places->transpositions[argument] : 0;
		break;
	case 0xE4:
		ch->gate = argument;
		break;
	case 0xF0:
		return target;
	case 0xF1:
		ch->jump_count++;
		if (ch->jump_count == argument)
		{
			ch->jump_count = 0;
			return target;
		}
		return at + 4;
	case 0xF2:
		ch->loop_count = argument;
		ch->loop_start = at + 2;
		return at + 2;
	case 0xF3:
		ch->loop_count--;
		return ch->loop_count == 0 ? at + 1 : ch->loop_start;
	case 0xF4:
		ch->loop_2_count = argument;
		ch->loop_2_start = at + 2;
		return at + 2;
	case 0xF5:
		ch->loop_2_count--;
		return ch->loop_2_count == 0 ? at + 1 : ch->loop_2_start;
	case 0xF6:
		ch->repeat_count = argument;
		ch->repeat_return = at + 2;         /* the F6's address, which F7 reads again */
		ch->repeat_part = target;
		return target;
	case 0xF7:
		ch->repeat_count--;
		return ch->repeat_count == 0 ? ch->repeat_return + 2 : ch->repeat_part;
	case 0xFF:
		return -1;
	default:
		break;
	}
	return at + size;
}

/* The key of the note whose pitch nibble is 'nibble': a drum's DRUM_BASE + N, else 11 + the note's bytes into the
   pitch table / 2 (42FE-4316: a byte, and a PCM instrument's transposition); -1 when none has it */
static int key_of(const channel *ch, int nibble)
{
	int64_t offset, key;

	if (ch->mode)
		return nibble > 0 && nibble <= 15 ? DRUM_BASE + nibble : -1;
	offset = ((2 * nibble + ((24 * ch->octave) & 0xFF)) & 0xFF) + (ch->pcm ? ch->transposition : 0);
	key = 11 + floor_div(offset, 2);
	return key >= 0 && key <= 127 ? (int)key : -1;
}

/* the pitch nibble that gives 'key' (the first); -1 when none does */
static int nibble_of(const channel *ch, int key)
{
	for (int nibble = 0; nibble < 16; nibble++)
		if (key_of(ch, nibble) == key)
			return nibble;
	return -1;
}

/* 4916: the units of a note's 'length' its gate takes off its end, bit by bit (1 at least; 0 for gate 0) */
static uint32_t gate_units(uint32_t length, uint8_t gate)
{
	uint32_t found = 0, part = length & 0xFFFF;

	if (!gate)
		return 0;
	for (int bit = 7; bit >= 0; bit--)
	{
		part >>= 1;
		if (gate >> bit & 1)
			found += part;
	}
	found &= 0xFFFF;
	return found ? found : 1;
}

/* The ticks after a note of 'units' starts where the driver keys it off */
static int64_t released(const channel *ch, int64_t units)
{
	int64_t ticks;

	if (ch->mode || !ch->gate)
		return floor_div(units, UNIT);
	ticks = floor_div(units - (int64_t)gate_units((uint32_t)units, ch->gate) + UNIT / 2, UNIT);
	return ticks > 1 ? ticks : 1;
}

/* the length's code of a note or a rest of 'units' (the first); -1 if none has it */
static int code_of(int64_t units, const music_places *places)
{
	for (size_t code = 0; code < places->length_count; code++)
		if (places->lengths[code] == units)
			return (int)code;
	return -1;
}

/* The bytes of a held note after E5, from 'data': b1, then up to the first byte with a nibble F */
static uint32_t held_length(const uint8_t *data, uint32_t size)
{
	uint32_t at = 1;

	while (at < size && data[at] >> 4 != 0x0F && (data[at] & 0x0F) != 0x0F)
		at++;
	return at + 1 < size ? at + 1 : size;
}

/* The units of a held note's bytes (after E5), as 4737 adds them up; -1 when a code is none of note_lengths' */
static int64_t held_units(const uint8_t *data, uint32_t size, const music_places *places)
{
	int codes[64];
	int count = 0;
	int64_t total = 0;

	codes[count++] = data[0] >> 4;
	for (uint32_t at = 1; at < size && count + 2 <= 64; at++)
	{
		if (data[at] >> 4 == 0x0F)
			break;
		codes[count++] = data[at] >> 4;
		if ((data[at] & 0x0F) == 0x0F)
			break;
		codes[count++] = data[at] & 0x0F;
	}
	for (int index = 0; index < count; index++)
	{
		if ((size_t)codes[index] >= places->length_count)
			return -1;
		total += places->lengths[codes[index]];
	}
	return total;
}

/* ---- the files ---- */

enum { EVENT_ON, EVENT_OFF, EVENT_META };

typedef struct
{
	int64_t tick;
	size_t order;               /* its place in the track */
	uint8_t kind, type, key;    /* type: a meta event's */
	const uint8_t *data;
	uint32_t size;
} event;

typedef struct
{
	event *list;
	size_t count, capacity;
} events;

static int add_event(events *track, int64_t tick, uint8_t kind, uint8_t type, uint8_t key, const uint8_t *data,
	uint32_t size)
{
	event *added;

	track->list = grow(track->list, &track->capacity, track->count + 1, sizeof(event));
	if (!track->list)
		return fail("no memory for a MIDI file's events");
	added = &track->list[track->count];
	added->order = track->count++;
	added->tick = tick;
	added->kind = kind;
	added->type = type;
	added->key = key;
	added->data = data;
	added->size = size;
	return 1;
}

/* a variable-length quantity (4 bytes at most) */
static int read_number(const uint8_t *body, size_t size, size_t *place, uint32_t *value, const char *where,
	size_t track)
{
	*value = 0;
	for (int bytes = 0; bytes < 4; bytes++)
	{
		if (*place >= size)
			return fail("%s: track %zu ends inside an event", where, track);
		*value = *value << 7 | (body[*place] & 0x7Fu);
		if (!(body[(*place)++] & 0x80))
			return 1;
	}
	return fail("%s: track %zu: a variable-length quantity of more than 4 bytes", where, track);
}

/* A Standard MIDI File's tracks: Note Ons, Note Offs and meta events (the rest left out) */
static int parse(const uint8_t *data, size_t size, const char *where, uint32_t *division, events **tracks,
	size_t *track_count)
{
	size_t at, capacity = 0;

	*tracks = NULL;
	*track_count = 0;
	if (size < 14 || memcmp(data, "MThd", 4))
		return fail("%s is no Standard MIDI File", where);
	*division = (uint32_t)data[12] << 8 | data[13];
	if ((*division & 0x8000) || !*division)
		return fail("%s: its time is no ticks a quarter note", where);
	at = 8 + ((size_t)data[4] << 24 | (size_t)data[5] << 16 | (size_t)data[6] << 8 | data[7]);
	while (at + 8 <= size)
	{
		const uint8_t *chunk = data + at;
		size_t length = (size_t)chunk[4] << 24 | (size_t)chunk[5] << 16 | (size_t)chunk[6] << 8 | chunk[7];
		const uint8_t *body = chunk + 8;
		size_t place = 0;
		int64_t tick = 0;
		int status = -1;
		events *track;

		if (length > size - at - 8)
			length = size - at - 8;
		at += 8 + length;
		if (memcmp(chunk, "MTrk", 4))
			continue;
		*tracks = grow(*tracks, &capacity, *track_count + 1, sizeof(events));
		if (!*tracks)
			return fail("no memory for a MIDI file's tracks");
		track = &(*tracks)[(*track_count)++];
		memset(track, 0, sizeof(*track));
		while (place < length)
		{
			uint32_t delta, count;
			uint8_t byte;

			if (!read_number(body, length, &place, &delta, where, *track_count))
				return 0;
			tick += delta;
			if (place >= length)
				return fail("%s: track %zu ends inside an event", where, *track_count);
			byte = body[place];
			if (byte == 0xFF)
			{
				uint8_t type;

				if (place + 1 >= length)
					return fail("%s: track %zu ends inside an event", where, *track_count);
				type = body[place + 1];
				place += 2;
				if (!read_number(body, length, &place, &count, where, *track_count))
					return 0;
				if (type == 0x2F)
					break;
				if (count > length - place)
					count = (uint32_t)(length - place);
				if (!add_event(track, tick, EVENT_META, type, 0, body + place, count))
					return 0;
				place += count;
				continue;
			}
			if (byte == 0xF0 || byte == 0xF7)
			{
				place++;
				if (!read_number(body, length, &place, &count, where, *track_count))
					return 0;
				place += count;
				continue;
			}
			if (byte & 0x80)
			{
				if (byte > 0xF0)
					return fail("%s: track %zu, tick %lld: a status byte %02X", where, *track_count, (long long)tick,
						byte);
				status = byte;
				place++;
			}
			else if (status < 0)
				return fail("%s: track %zu, tick %lld: data with no status before it", where, *track_count,
					(long long)tick);
			count = (status & 0xE0) == 0xC0 ? 1 : 2;
			if (place + count > length)
				return fail("%s: track %zu ends inside an event", where, *track_count);
			if ((status & 0xF0) == 0x90 && body[place + 1])
			{
				if (!add_event(track, tick, EVENT_ON, 0, body[place], NULL, 0))
					return 0;
			}
			else if ((status & 0xF0) == 0x80 || (status & 0xF0) == 0x90)
			{
				if (!add_event(track, tick, EVENT_OFF, 0, body[place], NULL, 0))
					return 0;
			}
			place += count;
		}
	}
	return 1;
}

/* ---- a song's channels ---- */

enum { STEP_NONE, STEP_NOTE, STEP_REST, STEP_HELD, STEP_CUT };

typedef struct
{
	int64_t tick;
	size_t first, count;        /* its commands in the track's */
	int step, key;              /* key -1: none (yet) */
	const uint8_t *held;
	uint32_t held_size;
	int64_t released;           /* its Note Off's tick, NO_TICK */
} step_read;

typedef struct
{
	const uint8_t *data;
	uint32_t size;
} command;

typedef struct
{
	char start[NAME_SIZE];
	char where[WHERE_SIZE];
	command *commands;
	size_t command_count, command_capacity;
	step_read *reads;
	size_t read_count, read_capacity;
} driver_track;

typedef struct
{
	const uint8_t *data;        /* a 'U' event's: its place's name, a 0 byte, the bytes */
	uint32_t size;
	char where[WHERE_SIZE];
} unshown_bytes;

typedef struct
{
	char header[NAME_SIZE];     /* 'N': the song header's place */
	char header_where[WHERE_SIZE];
	int has_header;
	unshown_bytes *unshown;
	size_t unshown_count, unshown_capacity;
	driver_track *tracks;
	size_t track_count, track_capacity;
} song;

static void free_song(song *each)
{
	for (size_t index = 0; index < each->track_count; index++)
	{
		free(each->tracks[index].commands);
		free(each->tracks[index].reads);
	}
	free(each->tracks);
	free(each->unshown);
	memset(each, 0, sizeof(*each));
}

/* the events of a track by tick, the Note Offs first, then in the track's order */
static int by_tick(const void *first, const void *second)
{
	const event *a = first, *b = second;
	const int a_off = a->kind == EVENT_OFF, b_off = b->kind == EVENT_OFF;

	if (a->tick != b->tick)
		return a->tick < b->tick ? -1 : 1;
	if (a_off != b_off)
		return a_off ? -1 : 1;
	return a->order < b->order ? -1 : a->order > b->order;
}

static void text_of(const uint8_t *data, uint32_t size, char *text, size_t capacity)
{
	const size_t length = size < capacity - 1 ? size : capacity - 1;

	memcpy(text, data, length);
	text[length] = 0;
}

/* A track's driver's events into a song's channel (when it has an 'S'), and its 'N' and 'U' events
   (sound_music.py's driver_tracks) */
static int read_track(song *into, events *track, const char *file, size_t index)
{
	driver_track found;
	size_t open = 0;            /* the read whose note is on, 1 on (0: none) */
	int open_key = -1, ended = 0, has_start = 0;

	memset(&found, 0, sizeof(found));
	snprintf(found.where, sizeof(found.where), "%s, track %zu", file, index + 1);
	qsort(track->list, track->count, sizeof(event), by_tick);
	for (size_t ordered = 0; ordered < track->count; ordered++)
	{
		const event *each = &track->list[ordered];
		const uint8_t *data = NULL;
		uint32_t size = 0;
		char tag = 0;
		step_read *read;

		if (each->kind == EVENT_OFF)
		{
			if (open && open_key == each->key)
			{
				found.reads[open - 1].released = each->tick;
				open = 0;
			}
			continue;
		}
		if (each->kind == EVENT_META)
		{
			const uint8_t *zero;

			if (each->type != 0x7F || each->size < 2 || each->data[0] != TAG)
				continue;
			tag = (char)each->data[1];
			data = each->data + 2;
			size = each->size - 2;
			if (tag == 'N')
			{
				if (!(zero = memchr(data, 0, size)))
				{
					fail("%s, tick %lld: an 'N' event with no place", found.where, (long long)each->tick);
					goto failed;
				}
				text_of(data, (uint32_t)(zero - data), into->header, sizeof(into->header));
				snprintf(into->header_where, sizeof(into->header_where), "%s, tick %lld", found.where,
					(long long)each->tick);
				into->has_header = 1;
				continue;
			}
			if (tag == 'U')
			{
				unshown_bytes *added;

				if (!memchr(data, 0, size))
				{
					fail("%s, tick %lld: a 'U' event with no place", found.where, (long long)each->tick);
					goto failed;
				}
				into->unshown = grow(into->unshown, &into->unshown_capacity, into->unshown_count + 1,
					sizeof(unshown_bytes));
				if (!into->unshown)
				{
					fail("no memory for the music");
					goto failed;
				}
				added = &into->unshown[into->unshown_count++];
				added->data = data;
				added->size = size;
				snprintf(added->where, sizeof(added->where), "%s, tick %lld", found.where, (long long)each->tick);
				continue;
			}
			if (tag == 'S')
			{
				text_of(data, size, found.start, sizeof(found.start));
				has_start = 1;
				continue;
			}
			if (tag != 'C' && tag != 'R' && tag != 'H' && tag != 'Z')
				continue;
		}
		if (!has_start)
		{
			fail("%s, tick %lld: the driver's events come before its start ('S')", found.where,
				(long long)each->tick);
			goto failed;
		}
		if (ended)
		{
			fail("%s, tick %lld: an event after the channel's end", found.where, (long long)each->tick);
			goto failed;
		}
		if (!found.read_count || found.reads[found.read_count - 1].tick != each->tick)
		{
			if (found.read_count && found.reads[found.read_count - 1].step == STEP_NONE)
			{
				fail("%s, tick %lld: commands with no step after them", found.where,
					(long long)found.reads[found.read_count - 1].tick);
				goto failed;
			}
			found.reads = grow(found.reads, &found.read_capacity, found.read_count + 1, sizeof(step_read));
			if (!found.reads)
			{
				fail("no memory for the music");
				goto failed;
			}
			read = &found.reads[found.read_count++];
			memset(read, 0, sizeof(*read));
			read->tick = each->tick;
			read->first = found.command_count;
			read->key = -1;
			read->released = NO_TICK;
		}
		read = &found.reads[found.read_count - 1];
		if (each->kind == EVENT_ON)
		{
			if (read->step != STEP_NONE && !(read->step == STEP_HELD && read->key < 0))
			{
				fail("%s, tick %lld: a second step at a tick", found.where, (long long)each->tick);
				goto failed;
			}
			if (open)
			{
				fail("%s, tick %lld: a note starts before the one at tick %lld ends", found.where,
					(long long)each->tick, (long long)found.reads[open - 1].tick);
				goto failed;
			}
			if (read->step == STEP_NONE)
				read->step = STEP_NOTE;
			read->key = each->key;
			open = found.read_count;
			open_key = each->key;
			continue;
		}
		if (read->step != STEP_NONE)
		{
			fail("%s, tick %lld: an event after the tick's step", found.where, (long long)each->tick);
			goto failed;
		}
		if (tag == 'C')
		{
			if (!size)
			{
				fail("%s, tick %lld: a command with no bytes", found.where, (long long)each->tick);
				goto failed;
			}
			found.commands = grow(found.commands, &found.command_capacity, found.command_count + 1, sizeof(command));
			if (!found.commands)
			{
				fail("no memory for the music");
				goto failed;
			}
			found.commands[found.command_count].data = data;
			found.commands[found.command_count++].size = size;
			read->count++;
			ended = data[0] == 0xFF;
		}
		else if (tag == 'R')
			read->step = STEP_REST;
		else if (tag == 'H')
		{
			read->step = STEP_HELD;
			read->held = data;
			read->held_size = size;
		}
		else
		{
			read->step = STEP_CUT;
			ended = 1;
		}
	}
	if (!has_start)
	{
		free(found.commands);
		free(found.reads);
		return 1;
	}
	if (found.read_count && found.reads[found.read_count - 1].step == STEP_NONE && !ended)
	{
		fail("%s, tick %lld: commands with no step after them", found.where,
			(long long)found.reads[found.read_count - 1].tick);
		goto failed;
	}
	into->tracks = grow(into->tracks, &into->track_capacity, into->track_count + 1, sizeof(driver_track));
	if (!into->tracks)
	{
		fail("no memory for the music");
		goto failed;
	}
	into->tracks[into->track_count++] = found;
	return 1;
failed:
	free(found.commands);
	free(found.reads);
	return 0;
}

/* ---- the bytes ---- */

typedef struct
{
	const music_places *places;
	uint8_t *image, *given;
	uint16_t *source;           /* the file that gave a byte first (its number in music.txt, 1 on) */
	char (*files)[NAME_SIZE];
	uint16_t file;
} music_bytes;

static int put(music_bytes *into, uint32_t place, const uint8_t *data, uint32_t size, const char *where)
{
	for (uint32_t offset = 0; offset < size; offset++)
	{
		const uint32_t at = place + offset;

		if (at >= MUSIC_SPACE)
			return fail("%s: a byte past the sound region (%X)", where, (unsigned)at);
		if (into->given[at] && into->image[at] != data[offset])
		{
			char name[NAME_SIZE];

			into->places->name_of(into->places->host, at, name, sizeof(name));
			return fail("%s: the byte at %s comes back as %02X, and as %02X from %s", where, name, data[offset],
				into->image[at], into->files[into->source[at] - 1]);
		}
		if (!into->given[at])
		{
			into->image[at] = data[offset];
			into->given[at] = 1;
			into->source[at] = into->file;
		}
	}
	return 1;
}

static int place_of(const music_places *places, const char *name, uint32_t *place, const char *where)
{
	if (!places->place_of(places->host, name, place))
		return fail("%s: no place is named %s", where, name);
	return 1;
}

/* A step's bytes at the channel's place: a note's or a rest's byte, or a held note's */
static int put_step(music_bytes *into, channel *ch, const step_read *read, int64_t following, const char *here)
{
	const music_places *places = into->places;
	const int64_t units = (following - read->tick) * UNIT;
	uint8_t data[64];
	uint32_t size;

	if (read->step == STEP_HELD)
	{
		int64_t held;
		int nibble;

		if (!read->held_size || held_length(read->held, read->held_size) != read->held_size
			|| read->held_size + 1 > sizeof(data))
			return fail("%s: the held note's bytes ('H') do not end at their first nibble F", here);
		held = held_units(read->held, read->held_size, places);
		if (held < 0)
			return fail("%s: the held note's bytes ('H') have a length's code note_lengths has not", here);
		if (held != units)
			return fail("%s: the held note lasts %lld units; its lengths ('H') add up to %lld", here,
				(long long)units, (long long)held);
		if (read->key < 0)
			return fail("%s: the held note ('H') has no Note On", here);
		nibble = nibble_of(ch, read->key);
		if (nibble < 0)
			return fail("%s: no pitch gives the key %d from the channel's octave", here, read->key);
		data[0] = 0xE5;
		data[1] = (uint8_t)((read->held[0] & 0xF0) | nibble);
		memcpy(data + 2, read->held + 1, read->held_size - 1);
		size = read->held_size + 1;
	}
	else
	{
		const int code = code_of(units, places);
		int nibble = 0;

		if (code < 0)
			return fail("%s: no note or rest lasts %lld units (note_lengths)", here, (long long)units);
		if (read->step == STEP_NOTE)
		{
			nibble = nibble_of(ch, read->key);
			if (nibble <= 0)
				return fail("%s: no pitch gives the key %d from the channel's octave", here, read->key);
		}
		data[0] = (uint8_t)(code << 4 | nibble);
		size = 1;
	}
	if (read->step != STEP_REST)
	{
		const int64_t expected = read->tick + released(ch, units);

		if (read->released == NO_TICK)
			return fail("%s: the note has no Note Off", here);
		if (read->released != expected)
			return fail("%s: the note ends at tick %lld; the driver keys it off at %lld", here,
				(long long)read->released, (long long)expected);
	}
	if (!put(into, ch->place, data, size, here))
		return 0;
	ch->place += size;
	return 1;
}

/* A channel's reads, one after the other, into the bytes (sound_music.py's rebuild) */
static int put_track(music_bytes *into, const driver_track *track, int number, uint32_t start)
{
	channel ch;

	memset(&ch, 0, sizeof(ch));
	ch.number = number;
	ch.pcm = number >= FM_CHANNELS;
	ch.place = start;
	for (size_t index = 0; index < track->read_count; index++)
	{
		const step_read *read = &track->reads[index];
		char here[WHERE_SIZE + 32];
		int ended = 0;

		snprintf(here, sizeof(here), "%s, tick %lld", track->where, (long long)read->tick);
		for (size_t each = 0; each < read->count; each++)
		{
			const command *item = &track->commands[read->first + each];
			const uint8_t code = item->data[0];
			const uint32_t address = address_at(code);
			uint8_t bytes[16];
			uint32_t length = item->size, target = 0;
			int64_t place;

			if ((code >= 0x10 && code < 0xE0) || code == 0xE5 || !code)
				return fail("%s: %02X is no command ('C')", here, code);
			if (code >= 0xE0 && !command_length(code))
				return fail("%s: the command %02X jumps to 0000", here, code);
			if (address)
			{
				char name[NAME_SIZE];

				text_of(item->data + (item->size > address ? address : item->size),
					item->size > address ? item->size - address : 0, name, sizeof(name));
				if (!place_of(into->places, name, &target, here))
					return 0;
				memcpy(bytes, item->data, item->size < address ? item->size : address);
				bytes[address] = (uint8_t)z80_address(target);
				bytes[address + 1] = (uint8_t)(z80_address(target) >> 8);
				length = address + 2;
			}
			else if (length <= sizeof(bytes))
				memcpy(bytes, item->data, length);
			if (length != command_length(code))
				return fail("%s: the command %02X has %u bytes; the driver reads %u", here, code, (unsigned)length,
					(unsigned)command_length(code));
			if (!put(into, ch.place, bytes, length, here))
				return 0;
			place = execute(&ch, bytes, length, target, into->places);
			if (place < 0)
			{
				ended = 1;
				break;
			}
			ch.place = (uint32_t)place;
		}
		if (ended || read->step == STEP_NONE || read->step == STEP_CUT)
			continue;
		if (index + 1 >= track->read_count)
			return fail("%s: no step after it says how long it is", here);
		if (!put_step(into, &ch, read, track->reads[index + 1].tick, here))
			return 0;
	}
	return 1;
}

/* A file's song into the bytes: the header, the channels, the bytes no track shows */
static int rebuild(music_bytes *into, const uint8_t *data, size_t size, const char *file)
{
	const music_places *places = into->places;
	uint32_t division, header, starts[SONG_TRACKS];
	events *tracks = NULL;
	size_t track_count = 0;
	song found;
	int ok = 0;

	memset(&found, 0, sizeof(found));
	if (!parse(data, size, file, &division, &tracks, &track_count))
		goto done;
	for (size_t index = 0; index < track_count; index++)
		if (!read_track(&found, &tracks[index], file, index))
			goto done;
	if (!found.has_header)
	{
		fail("%s: no 'N' event says its song header", file);
		goto done;
	}
	if (found.track_count != SONG_TRACKS)
	{
		fail("%s: %zu tracks with a start ('S'); a song has %d", file, found.track_count, SONG_TRACKS);
		goto done;
	}
	/* the driver's ticks */
	for (size_t index = 0; index < found.track_count; index++)
	{
		driver_track *track = &found.tracks[index];

		for (size_t read = 0; read < track->read_count; read++)
		{
			int64_t *ticks[2] = { &track->reads[read].tick, &track->reads[read].released };

			for (int slot = 0; slot < 2; slot++)
			{
				if (*ticks[slot] == NO_TICK)
					continue;
				if (*ticks[slot] * TICKS_A_QUARTER % division)
				{
					fail("%s: the tick %lld is no whole driver's tick", track->where, (long long)*ticks[slot]);
					goto done;
				}
				*ticks[slot] = *ticks[slot] * TICKS_A_QUARTER / division;
			}
		}
	}
	/* the header: the channels' starts */
	if (!place_of(places, found.header, &header, found.header_where))
		goto done;
	for (size_t index = 0; index < SONG_TRACKS; index++)
	{
		char where[WHERE_SIZE + 16];
		uint8_t entry[2];

		snprintf(where, sizeof(where), "%s, its start", found.tracks[index].where);
		if (!place_of(places, found.tracks[index].start, &starts[index], where))
			goto done;
		entry[0] = (uint8_t)z80_address(starts[index]);
		entry[1] = (uint8_t)(z80_address(starts[index]) >> 8);
		snprintf(where, sizeof(where), "%s's 'S'", file);
		if (!put(into, header + 2 * (uint32_t)index, entry, 2, where))
			goto done;
	}
	for (size_t index = 0; index < SONG_TRACKS; index++)
		if (!put_track(into, &found.tracks[index], (int)index, starts[index]))
			goto done;
	/* the bytes no track shows */
	for (size_t index = 0; index < found.unshown_count; index++)
	{
		const unshown_bytes *each = &found.unshown[index];
		const uint8_t *zero = memchr(each->data, 0, each->size);
		const uint32_t name_size = (uint32_t)(zero - each->data);
		char name[NAME_SIZE];
		uint32_t place;

		text_of(each->data, name_size, name, sizeof(name));
		if (!place_of(places, name, &place, each->where)
			|| !put(into, place, zero + 1, each->size - name_size - 1, each->where))
			goto done;
	}
	ok = 1;
done:
	free_song(&found);
	for (size_t index = 0; index < track_count; index++)
		free(tracks[index].list);
	free(tracks);
	return ok;
}

/* ---- the songs ---- */

static uint8_t *read_whole(const char *path, size_t *size)
{
	FILE *file = fopen(path, "rb");
	uint8_t *data;
	long length;

	if (!file)
		return NULL;
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);
	data = malloc(length > 0 ? (size_t)length + 1 : 1u);
	if (data && length > 0 && fread(data, 1, (size_t)length, file) != (size_t)length)
	{
		free(data);
		data = NULL;
	}
	fclose(file);
	if (data)
		data[length > 0 ? length : 0] = 0;
	*size = length > 0 ? (size_t)length : 0;
	return data;
}

const char *music_read(const char *folder, const music_places *places, uint8_t *image, uint8_t *given)
{
	char path[1024], (*files)[NAME_SIZE] = NULL;
	size_t size, file_count = 0, file_capacity = 0;
	uint8_t *listing;
	music_bytes into;
	int ok = 1;

	g_problem[0] = 0;
	snprintf(path, sizeof(path), "%s/music.txt", folder);
	if (!(listing = read_whole(path, &size)))
		return "there is no music.txt";
	/* the files music.txt names: each line's first word, but the comments' */
	{
		char *at = (char *)listing;

		while (*at && ok)
		{
			char *line = at, *end = strchr(at, '\n'), *word;
			size_t length;

			at = end ? end + 1 : at + strlen(at);
			if (end)
				*end = 0;
			if (line[0] == '#')
				continue;
			word = line + strspn(line, " \t\r\f\v");
			length = strcspn(word, " \t\r\f\v");
			if (!length)
				continue;
			if (length >= NAME_SIZE)
				ok = fail("music.txt: a name too long");
			else
			{
				files = grow(files, &file_capacity, file_count + 1, sizeof(*files));
				if (!files)
					ok = fail("no memory for the music");
				else
				{
					memcpy(files[file_count], word, length);
					files[file_count++][length] = 0;
				}
			}
		}
	}
	free(listing);
	memset(&into, 0, sizeof(into));
	into.places = places;
	into.image = image;
	into.given = given;
	into.files = files;
	if (ok && !(into.source = calloc(MUSIC_SPACE, sizeof(*into.source))))
		ok = fail("no memory for the music");
	for (size_t index = 0; index < file_count && ok; index++)
	{
		uint8_t *data;
		char file[NAME_SIZE + 8];

		snprintf(file, sizeof(file), "%s.mid", files[index]);
		snprintf(path, sizeof(path), "%s/%s", folder, file);
		if (!(data = read_whole(path, &size)))
		{
			ok = fail("music.txt names %s, and there is no %s", files[index], file);
			break;
		}
		into.file = (uint16_t)(index + 1);
		snprintf(files[index], NAME_SIZE, "%s", file);
		ok = rebuild(&into, data, size, file);
		free(data);
	}
	free(into.source);
	free(files);
	return ok ? NULL : g_problem;
}
