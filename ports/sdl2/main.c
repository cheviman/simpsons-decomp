/**
 *    Name:        main.c
 *    Description: the game in a window: SDL2 shows its screen, plays its sound, reads the controls and keeps the
 *                 pace, around the same game and board the headless runs check
 *    Version:     0.1.0
 *    Created:     06-11-2026
 *    Modified:    06-11-2026
 *    Author:      Sebastian Toyos
 *
 *    license:BSD-3-Clause
 *    Usage: simpsons [--script FILE [--fast]] [--hashes FILE] [--video-hashes FILE] [--sound-hashes FILE] [--service]
 *                    [--assets FOLDER]
 *
 *    The game (runtime/src/game.c and the program) runs as it is: this file only wraps it. When each frame is done
 *    the port reads the keyboard and the game controllers into the board's inputs for the next one, closes the
 *    frame's sound and queues it, puts the frame in the window, and waits for the frame's time (the board's 59.185
 *    a second) to pass.
 *
 *    The game's data is its assets (game/assets.h), the files tools/extract_assets.py writes from the player's ROM
 *    set: --assets, or the folder 'assets' beside the executable or up to three folders above it, or in the current
 *    folder. The game starts with the factory settings every time (the EEPROM's, from the assets).
 *
 *    --script plays a control script (runtime/include/simpsons/script.h) instead of the keyboard, to its end;
 *    --fast runs it without waiting for the frames' time. --hashes, --video-hashes and --sound-hashes write for
 *    each frame the hashes kref writes, so a run in the window compares with the reference frame by frame.
 *    --service holds the test switch all along (from the start: the board then resets its EEPROM).
 *
 *    Controls (the cabinet has four players, each with a coin slot and a start button, which the factory settings
 *    leave unused: a coin and the attack button bring a player in; player 1 is Marge, 2 Homer, 3 Bart, 4 Lisa):
 *      arrows                         move (player 1)
 *      Z or left Ctrl                 attack         X or left Alt     jump
 *      5, 6, 7, 8                     coins 1-4      1, 2, 3, 4        start 1-4
 *      F2                             the test switch (held: the test mode's menu)
 *      Escape                         quit           F11 or Alt+Enter  full screen
 *      F3                             smooth or sharp pixels
 *    Game controllers, players 1 to 4 in the order they are plugged: the pad or the left stick moves, A attacks,
 *    B jumps, Back is the coin, Start the start button.
 */
#include "game/game.h"
#include "simpsons/machine.h"
#include "simpsons/program.h"
#include "simpsons/script.h"
#include "simpsons/video.h"

#include <SDL.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE               "The Simpsons"
#define PLAYERS             4
#define WINDOW_SCALE        3
#define STICK_DEAD_ZONE     8000
#define QUEUE_FRAMES_MAX    6          /* sound queued beyond this many frames is dropped */
/* the board's refresh: 6 MHz pixels, 384 a line, 264 lines */
#define FRAME_RATE_NUMERATOR    6000000u
#define FRAME_RATE_DENOMINATOR  (384u * 264u)

#define USAGE "Usage: simpsons [--script FILE [--fast]] [--hashes FILE] [--video-hashes FILE] [--sound-hashes FILE]" \
	" [--service] [--assets FOLDER]"

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static SDL_AudioDeviceID audio;
static SDL_GameController *controllers[PLAYERS];
static bool smooth;
static uint64_t next_frame;           /* performance counter value the next frame waits for */
static simpsons_script *script;
static uint64_t script_frames;
static bool fast;
static bool service_held;             /* --service: the test switch on all along */
static FILE *hashes;
static FILE *video_hashes;
static FILE *sound_hashes;

/* ---- the end ---- */

static void quit(void)
{
	if (hashes)
		fclose(hashes);
	if (video_hashes)
		fclose(video_hashes);
	if (sound_hashes)
		fclose(sound_hashes);
	simpsons_script_free(script);
	if (audio)
		SDL_CloseAudioDevice(audio);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(0);
}

/* ---- the picture ---- */

static void show_frame(void)
{
	SDL_UpdateTexture(texture, NULL, game_frame()->pixels, SIMPSONS_VIDEO_WIDTH * (int)sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

static void toggle_full_screen(void)
{
	const bool full = (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) == 0;

	SDL_SetWindowFullscreen(window, full ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

static void toggle_smooth(void)
{
	smooth = !smooth;
	SDL_SetTextureScaleMode(texture, smooth ? SDL_ScaleModeLinear : SDL_ScaleModeNearest);
}

/* ---- the sound ---- */

static void open_audio(void)
{
	SDL_AudioSpec wanted, got;

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0)
		return;
	SDL_zero(wanted);
	wanted.freq = (int)game_audio_rate();
	wanted.format = AUDIO_S16SYS;
	wanted.channels = 2;
	wanted.samples = 1024;
	audio = SDL_OpenAudioDevice(NULL, 0, &wanted, &got, 0);
	if (audio)
		SDL_PauseAudioDevice(audio, 0);
}

/* the frame's samples, unless the queue is already many frames ahead (a slow start, a pause) */
static void queue_sound(void)
{
	size_t count;
	const int16_t *samples = game_audio(&count);
	const size_t bytes = count * 2u * sizeof(int16_t);

	if (!audio || !count || fast)
		return;
	if (SDL_GetQueuedAudioSize(audio) > QUEUE_FRAMES_MAX * bytes)
		return;
	SDL_QueueAudio(audio, samples, (Uint32)bytes);
}

/* ---- the controls ---- */

static void read_events(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				quit();
				return;
			case SDL_KEYDOWN:
				if (event.key.repeat)
					break;
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit();
				if (event.key.keysym.sym == SDLK_F11
					|| (event.key.keysym.sym == SDLK_RETURN && (event.key.keysym.mod & KMOD_ALT)))
					toggle_full_screen();
				if (event.key.keysym.sym == SDLK_F3)
					toggle_smooth();
				break;
			case SDL_CONTROLLERDEVICEADDED:
				for (int player = 0; player < PLAYERS; player++)
					if (!controllers[player])
					{
						controllers[player] = SDL_GameControllerOpen(event.cdevice.which);
						break;
					}
				break;
			case SDL_CONTROLLERDEVICEREMOVED:
				for (int player = 0; player < PLAYERS; player++)
					if (controllers[player]
						&& SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controllers[player])) == event.cdevice.which)
					{
						SDL_GameControllerClose(controllers[player]);
						controllers[player] = NULL;
					}
				break;
			default:
				break;
		}
	}
}

static bool button(SDL_GameController *pad, SDL_GameControllerButton which)
{
	return pad && SDL_GameControllerGetButton(pad, which) != 0;
}

static bool stick(SDL_GameController *pad, SDL_GameControllerAxis axis, int sign)
{
	return pad && SDL_GameControllerGetAxis(pad, axis) * sign > STICK_DEAD_ZONE;
}

/* the controls into the board's inputs, which it reads in the next frame (active low: a cleared bit is a pressed
   button) */
static void read_controls(void)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	uint8_t coins = 0xFF;

	for (int player = 0; player < PLAYERS; player++)
	{
		SDL_GameController *pad = controllers[player];
		const bool keyboard = player == 0;
		bool left = button(pad, SDL_CONTROLLER_BUTTON_DPAD_LEFT) || stick(pad, SDL_CONTROLLER_AXIS_LEFTX, -1);
		bool right = button(pad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) || stick(pad, SDL_CONTROLLER_AXIS_LEFTX, 1);
		bool up = button(pad, SDL_CONTROLLER_BUTTON_DPAD_UP) || stick(pad, SDL_CONTROLLER_AXIS_LEFTY, -1);
		bool down = button(pad, SDL_CONTROLLER_BUTTON_DPAD_DOWN) || stick(pad, SDL_CONTROLLER_AXIS_LEFTY, 1);
		bool attack = button(pad, SDL_CONTROLLER_BUTTON_A);
		bool jump = button(pad, SDL_CONTROLLER_BUTTON_B);
		bool start = button(pad, SDL_CONTROLLER_BUTTON_START) || keys[SDL_SCANCODE_1 + player];
		uint8_t pressed = 0;

		if (keyboard)
		{
			left |= keys[SDL_SCANCODE_LEFT] != 0;
			right |= keys[SDL_SCANCODE_RIGHT] != 0;
			up |= keys[SDL_SCANCODE_UP] != 0;
			down |= keys[SDL_SCANCODE_DOWN] != 0;
			attack |= keys[SDL_SCANCODE_Z] || keys[SDL_SCANCODE_LCTRL];
			jump |= keys[SDL_SCANCODE_X] || keys[SDL_SCANCODE_LALT];
		}
		pressed |= left ? SIMPSONS_LEFT : 0;
		pressed |= right ? SIMPSONS_RIGHT : 0;
		pressed |= up ? SIMPSONS_UP : 0;
		pressed |= down ? SIMPSONS_DOWN : 0;
		pressed |= attack ? SIMPSONS_ATTACK : 0;
		pressed |= jump ? SIMPSONS_JUMP : 0;
		pressed |= start ? SIMPSONS_START : 0;
		simpsons_board.players[player] = (uint8_t)~pressed;
		if (keys[SDL_SCANCODE_5 + player] || button(pad, SDL_CONTROLLER_BUTTON_BACK))
			coins &= (uint8_t)~(SIMPSONS_COIN1 << player);
	}
	simpsons_board.coins = coins;
	if (keys[SDL_SCANCODE_F2] || service_held)
		simpsons_board.test &= (uint8_t)~SIMPSONS_TEST_SERVICE;
	else
		simpsons_board.test |= SIMPSONS_TEST_SERVICE;
}

/* ---- the frames ---- */

static void wait_for_frame(void)
{
	const uint64_t frequency = SDL_GetPerformanceFrequency();
	const uint64_t period = frequency * FRAME_RATE_DENOMINATOR / FRAME_RATE_NUMERATOR;
	uint64_t now = SDL_GetPerformanceCounter();

	if (next_frame == 0 || now > next_frame + 4 * period)
		next_frame = now;    /* (behind by more than a few frames: the pace starts again from here) */
	next_frame += period;
	while ((now = SDL_GetPerformanceCounter()) < next_frame)
	{
		const uint64_t left_ms = (next_frame - now) * 1000 / frequency;

		if (left_ms > 1)
			SDL_Delay((Uint32)(left_ms - 1));
	}
}

static void on_frame_done(void)
{
	const uint64_t number = simpsons_board.frame;

	read_events();
	if (script)
		simpsons_script_apply(script, simpsons_board.frame);
	else
		read_controls();
	game_end_frame();
	queue_sound();
	if (hashes)
		fprintf(hashes, "%" PRIu64 " %016" PRIx64 "\n", number, simpsons_state_hash());
	if (video_hashes)
		fprintf(video_hashes, "%" PRIu64 " %016" PRIx64 "\n", number, simpsons_video_hash(game_frame()));
	if (sound_hashes)
		fprintf(sound_hashes, "%" PRIu64 " %016" PRIx64 " %016" PRIx64 "\n", number, game_sound_samples_hash(),
			game_sound_state_hash());
	show_frame();
	if (script && script_frames && number >= script_frames)
		quit();
	else if (!fast)
		wait_for_frame();
}

/* ---- the start ---- */

/* 'assets' beside the executable or in a folder above it (build/bin's executable finds the repository's), else in
   the current folder */
static const char *find_assets(char *path, size_t size)
{
	char *base = SDL_GetBasePath();
	char folder[1024];

	if (!base)
		return "assets";
	snprintf(folder, sizeof(folder), "%s", base);
	SDL_free(base);
	for (int up = 0; up <= 3; up++)
	{
		/* (the files every extraction writes now: an older, incomplete one is passed over) */
		static const char *const k_needed[] = { "data/layout.txt", "data/structures.txt", "sound_data/layout.txt",
			"eeprom.txt" };
		size_t length = strlen(folder);
		bool complete = true;

		for (size_t file = 0; file < sizeof(k_needed) / sizeof(k_needed[0]) && complete; file++)
		{
			FILE *probe;

			snprintf(path, size, "%sassets/%s", folder, k_needed[file]);
			probe = fopen(path, "rb");
			complete = probe != NULL;
			if (probe)
				fclose(probe);
		}
		if (complete)
		{
			snprintf(path, size, "%sassets", folder);
			return path;
		}
		/* the folder above: drop the last name and its separator */
		if (length && (folder[length - 1] == '/' || folder[length - 1] == '\\'))
			folder[--length] = 0;
		while (length && folder[length - 1] != '/' && folder[length - 1] != '\\')
			folder[--length] = 0;
		if (!length)
			break;
	}
	return "assets";
}

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

static void fail(const char *message)
{
	fprintf(stderr, "%s\n", message);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, TITLE, message, NULL);
	exit(1);
}

int main(int argc, char **argv)
{
	char assets_path[1024];
	const char *assets = NULL;
	const char *script_path = NULL;
	bool service = false;
	char message[1200];

	for (int index = 1; index < argc; index++)
	{
		if (strcmp(argv[index], "--script") == 0 && index + 1 < argc)
			script_path = argv[++index];
		else if (strcmp(argv[index], "--fast") == 0)
			fast = true;
		else if (strcmp(argv[index], "--hashes") == 0 && index + 1 < argc)
			hashes = open_output(argv[++index]);
		else if (strcmp(argv[index], "--video-hashes") == 0 && index + 1 < argc)
			video_hashes = open_output(argv[++index]);
		else if (strcmp(argv[index], "--sound-hashes") == 0 && index + 1 < argc)
			sound_hashes = open_output(argv[++index]);
		else if (strcmp(argv[index], "--service") == 0)
			service = true;
		else if (strcmp(argv[index], "--assets") == 0 && index + 1 < argc)
			assets = argv[++index];
		else
			fail(USAGE);
	}
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS) != 0)
	{
		snprintf(message, sizeof(message), "The window cannot be opened: %s", SDL_GetError());
		fail(message);
	}
	if (!assets)
		assets = find_assets(assets_path, sizeof(assets_path));
	{
		const char *problem = game_load(assets);

		if (problem)
		{
			snprintf(message, sizeof(message), "The game's assets in %s cannot be read: %s", assets, problem);
			fail(message);
		}
	}
	if (script_path)
	{
		char error[256];

		script = simpsons_script_load(script_path, error, sizeof(error));
		if (!script)
			fail(error);
		script_frames = simpsons_script_frames(script);
	}

	window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SIMPSONS_VIDEO_WIDTH * WINDOW_SCALE, SIMPSONS_VIDEO_HEIGHT * WINDOW_SCALE, SDL_WINDOW_RESIZABLE);
	renderer = window ? SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED) : NULL;
	if (!renderer)
		renderer = window ? SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) : NULL;
	texture = renderer ? SDL_CreateTexture(renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STREAMING,
		SIMPSONS_VIDEO_WIDTH, SIMPSONS_VIDEO_HEIGHT) : NULL;
	if (!texture)
	{
		snprintf(message, sizeof(message), "The window cannot be opened: %s", SDL_GetError());
		fail(message);
	}
	SDL_RenderSetLogicalSize(renderer, SIMPSONS_VIDEO_WIDTH, SIMPSONS_VIDEO_HEIGHT);
	SDL_SetTextureScaleMode(texture, SDL_ScaleModeNearest);

	{
		const char *problem = game_reset(service, true);

		if (problem)
		{
			snprintf(message, sizeof(message), "The game does not start: %s", problem);
			fail(message);
		}
	}
	service_held = service;
	open_audio();
	if (script)
		simpsons_script_apply(script, 0);
	game_frame_done = on_frame_done;
	program_run();
	quit();
	return 0;
}
