/**
 *    Name:        main.c
 *    Description: the game with no screen or sound: the controls a script drives, and hashes of every frame in the
 *                 formats tools/core/konami/reference/kref writes
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Usage: simpsons_headless [--frames N] [--hashes FILE] [--video-hashes FILE] [--sound-hashes FILE]
 *                             [--sound-wav FILE] [--script FILE] [--service] [--assets FOLDER]
 *                             [--dump FRAME ... --dump-dir DIR]
 *    The game (runtime/src/game.c: the program on the board, its own video and sound board) from its assets
 *    (--assets, assets/ by default); it opens no ROM. It runs with frame timing, as kref --timing frames does
 *    (simpsons/frame.h): the script is applied when each VBLANK starts, and the hashes are kref's ("FRAME HASH":
 *    simpsons_state_hash, the frame's pixels with --video-hashes, the sound board's samples and RAM with
 *    --sound-hashes, as kref --sound-timing makes them), so the two compare line by line. --sound-wav writes the
 *    sound the ports play (game_audio: stereo, 16 bits), as kref --sound-wav writes the reference's. --service
 *    holds the test switch from the start. --dump writes the board's memories at the end of those frames into
 *    --dump-dir's folder (FRAME_work_ram.bin, FRAME_palette.bin...), as kref --dump writes the reference's.
 */
#include "game/game.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"
#include "simpsons/script.h"
#include "simpsons/video.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE "Usage: simpsons_headless [--frames N] [--hashes FILE] [--video-hashes FILE] [--sound-hashes FILE]" \
	" [--sound-wav FILE] [--script FILE] [--service] [--assets FOLDER] [--dump FRAME ... --dump-dir DIR]\n"
#define DUMPS_MAX 64

static uint64_t g_frames = 600;
static uint64_t g_dumps[DUMPS_MAX];
static int g_dump_count;
static const char *g_dump_dir = ".";
static FILE *g_hashes;
static FILE *g_video_hashes;
static FILE *g_sound_hashes;
static simpsons_script *g_script;
static FILE *g_wav;
static uint32_t g_wav_bytes;

static FILE *open_output(const char *path)
{
	FILE *file = fopen(path, "w");

	if (!file)
	{
		fprintf(stderr, "%s: cannot be written\n", path);
		exit(1);
	}
	return file;
}

static void put_le(FILE *file, uint32_t value, int bytes)
{
	for (int index = 0; index < bytes; index++)
		fputc((int)(value >> (8 * index)) & 0xFF, file);
}

/* The WAV's header, 16-bit stereo at the sound's rate: written first with no length, then again with it */
static void wav_header(void)
{
	const uint32_t rate = game_audio_rate();

	fseek(g_wav, 0, SEEK_SET);
	fwrite("RIFF", 1, 4, g_wav);
	put_le(g_wav, 36u + g_wav_bytes, 4);
	fwrite("WAVEfmt ", 1, 8, g_wav);
	put_le(g_wav, 16, 4);
	put_le(g_wav, 1, 2);
	put_le(g_wav, 2, 2);
	put_le(g_wav, rate, 4);
	put_le(g_wav, rate * 4u, 4);
	put_le(g_wav, 4, 2);
	put_le(g_wav, 16, 2);
	fwrite("data", 1, 4, g_wav);
	put_le(g_wav, g_wav_bytes, 4);
}

static void finish(void)
{
	if (g_wav)
	{
		wav_header();
		fclose(g_wav);
	}
	if (g_hashes)
		fclose(g_hashes);
	if (g_video_hashes)
		fclose(g_video_hashes);
	if (g_sound_hashes)
		fclose(g_sound_hashes);
	printf("frames:            %" PRIu64 "\n", simpsons_board.frame);
	printf("interrupts taken:  %u\n", program_interrupts());
	printf("sound IRQs:        %u\n", simpsons_board.sound_irqs);
	printf("watchdog resets:   %u\n", simpsons_board.watchdog_resets);
	fflush(stdout);
	exit(0);
}

/* The board's memories at the end of a frame, a file each, as kref --dump writes them (the work RAM in the order
   of its addresses: the board keeps it the other way round) */
static void dump_memories(uint64_t frame)
{
	static uint8_t work_ram[SIMPSONS_WORK_RAM_SIZE];
	const struct { const char *name; const uint8_t *data; size_t size; } memories[] = {
		{ "work_ram", work_ram, sizeof(work_ram) },
		{ "extra_ram", simpsons_board.extra_ram, sizeof(simpsons_board.extra_ram) },
		{ "palette", simpsons_board.palette, sizeof(simpsons_board.palette) },
		{ "tile_ram", simpsons_board.tile_ram, sizeof(simpsons_board.tile_ram) },
		{ "sprite_ram", simpsons_board.sprite_ram, sizeof(simpsons_board.sprite_ram) },
		{ "object_ram", simpsons_board.object_ram, sizeof(simpsons_board.object_ram) },
		{ "eeprom", simpsons_board.eeprom.data, sizeof(simpsons_board.eeprom.data) },
	};

	for (uint32_t offset = 0; offset < SIMPSONS_WORK_RAM_SIZE; offset++)
		work_ram[offset] = *simpsons_work_ram_byte((uint16_t)(SIMPSONS_WORK_RAM + offset));
	for (size_t index = 0; index < sizeof(memories) / sizeof(memories[0]); index++)
	{
		char path[1024];
		FILE *file;

		snprintf(path, sizeof(path), "%s/%" PRIu64 "_%s.bin", g_dump_dir, frame, memories[index].name);
		file = fopen(path, "wb");
		if (!file)
		{
			fprintf(stderr, "%s: cannot be written\n", path);
			exit(1);
		}
		fwrite(memories[index].data, 1, memories[index].size, file);
		fclose(file);
	}
}

/* A frame is done: the controls change, the frame's sound closes and its hashes are taken, as kref's */
static void frame_done(void)
{
	const uint64_t number = simpsons_board.frame;

	simpsons_script_apply(g_script, simpsons_board.frame);
	game_end_frame();
	if (g_wav)
	{
		size_t count;
		const int16_t *samples = game_audio(&count);

		for (size_t index = 0; index < 2u * count; index++)
			put_le(g_wav, (uint16_t)samples[index], 2);
		g_wav_bytes += (uint32_t)(4u * count);
	}
	if (g_sound_hashes)
		fprintf(g_sound_hashes, "%" PRIu64 " %016" PRIx64 " %016" PRIx64 "\n", number, game_sound_samples_hash(),
			game_sound_state_hash());
	if (g_hashes)
		fprintf(g_hashes, "%" PRIu64 " %016" PRIx64 "\n", number, simpsons_state_hash());
	if (g_video_hashes)
		fprintf(g_video_hashes, "%" PRIu64 " %016" PRIx64 "\n", number, simpsons_video_hash(game_frame()));
	for (int index = 0; index < g_dump_count; index++)
		if (g_dumps[index] == number)
			dump_memories(number);
	if (number >= g_frames)
		finish();
}

int main(int argc, char **argv)
{
	const char *assets = "assets", *script_path = NULL, *problem;
	bool frames_given = false, service = false;

	for (int index = 1; index < argc; index++)
	{
		const bool has_value = index + 1 < argc;

		if (!strcmp(argv[index], "--frames") && has_value)
		{
			g_frames = strtoull(argv[++index], NULL, 10);
			frames_given = true;
		}
		else if (!strcmp(argv[index], "--hashes") && has_value)
			g_hashes = open_output(argv[++index]);
		else if (!strcmp(argv[index], "--video-hashes") && has_value)
			g_video_hashes = open_output(argv[++index]);
		else if (!strcmp(argv[index], "--sound-hashes") && has_value)
			g_sound_hashes = open_output(argv[++index]);
		else if (!strcmp(argv[index], "--sound-wav") && has_value)
		{
			if (!(g_wav = fopen(argv[++index], "wb")))
			{
				fprintf(stderr, "%s: cannot be written\n", argv[index]);
				return 1;
			}
		}
		else if (!strcmp(argv[index], "--script") && has_value)
			script_path = argv[++index];
		else if (!strcmp(argv[index], "--assets") && has_value)
			assets = argv[++index];
		else if (!strcmp(argv[index], "--service"))
			service = true;
		else if (!strcmp(argv[index], "--dump") && has_value)
			while (index + 1 < argc && argv[index + 1][0] != '-' && g_dump_count < DUMPS_MAX)
				g_dumps[g_dump_count++] = strtoull(argv[++index], NULL, 10);
		else if (!strcmp(argv[index], "--dump-dir") && has_value)
			g_dump_dir = argv[++index];
		else
		{
			fprintf(stderr, "%s", USAGE);
			return 1;
		}
	}
	if ((problem = game_load(assets)) != NULL)
	{
		fprintf(stderr, "The game's assets in %s cannot be read: %s\n", assets, problem);
		return 1;
	}
	if ((problem = game_reset(service, g_video_hashes != NULL)) != NULL)
	{
		fprintf(stderr, "The game does not start: %s\n", problem);
		return 1;
	}
	if (script_path)
	{
		char error[256];

		g_script = simpsons_script_load(script_path, error, sizeof(error));
		if (!g_script)
		{
			fprintf(stderr, "%s\n", error);
			return 1;
		}
		if (!frames_given && simpsons_script_frames(g_script))
			g_frames = simpsons_script_frames(g_script);
		simpsons_script_apply(g_script, 0);
	}
	if (g_wav)
		wav_header();
	game_frame_done = frame_done;
	program_run();
	return 3;
}
