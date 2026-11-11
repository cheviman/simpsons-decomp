# Name:        CMakeLists.txt
# Description: build of The Simpsons: the game (from its assets, in a window or headless) and its development tools
# Version:     0.1.0
# Created:     05-11-2026
# Modified:    11-11-2026
# Author:      Sebastian Toyos
cmake_minimum_required(VERSION 3.20)
project(simpsons C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Every executable lands in build/bin (SIMPSONS_BIN_DIR), whatever the generator or configuration
set(SIMPSONS_BIN_DIR ${CMAKE_SOURCE_DIR}/build/bin CACHE PATH "Where the executables go")
foreach(config IN ITEMS "" _DEBUG _RELEASE _RELWITHDEBINFO _MINSIZEREL)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY${config} ${SIMPSONS_BIN_DIR})
endforeach()

if(MSVC)
	add_compile_options(/W3 /utf-8)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# The game's executables nest their calls as the program's do (a jump to another function is a call that returns,
# and the translated code's locals are many): their main thread gets a stack of 64 MB, which on Windows the
# executable sets at link time: /STACK for MSVC and clang-cl, through the compiler's driver for Clang aimed at MSVC's
# runtime, --stack for MinGW's GCC and Clang (ld, lld). On Linux and macOS the main thread's stack is the system's,
# not the executable's: the limit the game is started under (`ulimit -s`, 8 MB by default on most systems; macOS's
# linker can also write one into the executable, -stack_size), and nothing here asks for one. The game has been run
# with 64 MB only.
function(simpsons_game_stack target)
	if(MSVC)
		target_link_options(${target} PRIVATE /STACK:67108864)
	elseif(WIN32 AND CMAKE_C_SIMULATE_ID STREQUAL "MSVC")
		target_link_options(${target} PRIVATE LINKER:/STACK:67108864)
	elseif(WIN32)
		target_link_options(${target} PRIVATE LINKER:--stack,67108864)
	endif()
endfunction()

# The board as the program sees it (memory map, banks, interrupts, the EEPROM), the controls' scripts, and the
# ROM set's regions
add_library(simpsons_runtime STATIC
	runtime/src/machine.c
	runtime/src/sound.c
	runtime/src/script.c
	runtime/src/game_data.c
)
target_include_directories(simpsons_runtime PUBLIC runtime/include PRIVATE runtime/src)

# zlib's inflate (the ROM set's .zip, the assets' PNG files)
add_library(simpsons_inflate STATIC runtime/src/inflate.c)
target_include_directories(simpsons_inflate PUBLIC runtime/src)

# The reader of the player's ROM set: for the tools that run the original code, never for the game
add_library(simpsons_rom_set STATIC runtime/src/rom_set.c)
target_link_libraries(simpsons_rom_set PUBLIC simpsons_runtime simpsons_inflate)
target_include_directories(simpsons_rom_set PRIVATE runtime/src)

# The game's own video (runtime/src/video.c, simpsons/video.h): the frames MAME's video draws, pixel for pixel
# (kref --video-check)
add_library(simpsons_video STATIC runtime/src/video.c)
target_link_libraries(simpsons_video PUBLIC simpsons_runtime)

# The game's own sound chips (runtime/src/ym2151.c, k053260.c): the samples MAME's make (kref --sound-check)
add_library(simpsons_sound_chips STATIC runtime/src/ym2151.c runtime/src/k053260.c)
target_link_libraries(simpsons_sound_chips PUBLIC simpsons_runtime)

# The game's assets (runtime/src/assets.c, png.c, game/assets.h): the ROM set's bytes back from the files
# tools/extract_assets.py writes (kref --assets-check)
add_library(simpsons_assets STATIC runtime/src/assets.c runtime/src/png.c runtime/src/music.c)
target_link_libraries(simpsons_assets PUBLIC simpsons_runtime simpsons_inflate)

# The game's own sound board: the Z80 sound program decompiled to C (src/sound/, tools/decompile_sound.py) on its
# timing model and the board's chips (runtime/src/sound_cpu.c, sound_board.c, simpsons/sound_board.h): the samples and
# the RAM MAME's board makes under the same timing model (kref --sound-timing --sound-board-check)
file(GLOB SIMPSONS_SOUND_PROGRAM CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/sound/*.c)
add_library(simpsons_sound STATIC runtime/src/sound_cpu.c runtime/src/sound_board.c ${SIMPSONS_SOUND_PROGRAM})
target_include_directories(simpsons_sound PUBLIC runtime/include PRIVATE runtime/src src/sound)
target_link_libraries(simpsons_sound PUBLIC simpsons_sound_chips simpsons_runtime)
if(MSVC)
	target_compile_options(simpsons_sound PRIVATE /wd4102 /wd4244)
endif()

find_package(Python3 COMPONENTS Interpreter)

# The reference tools: the original program on MAME's cores (tools/core/konami/reference): Konami's CPU, its
# disassembler's oracle and kref on the board model; the video and the sound board follow
option(SIMPSONS_REFERENCE_TOOLS "Build the MAME-based reference tools" ON)
if(SIMPSONS_REFERENCE_TOOLS)
	if(NOT Python3_FOUND)
		message(FATAL_ERROR "The reference tools need Python 3 (MAME's Konami CPU core is written by m6809make.py)")
	endif()
	set(K_CPU 053248)
	set(K_GAME_RUNTIME simpsons_rom_set simpsons_video simpsons_sound_chips simpsons_assets)
	set(K_GAME_SOUND simpsons_sound)
	include(${CMAKE_SOURCE_DIR}/tools/core/konami/reference/reference.cmake)
	# the reference's sound board runs the game's own chips beside MAME's (kref --sound-check), wherever it goes
	target_link_libraries(ksound_053260_reference PUBLIC simpsons_sound_chips)
	# the translated program's helpers on all their inputs (tools/core/konami/reference/compare_konami_ops.py)
	add_executable(konami_ops_check tools/core/konami/reference/konami_ops_check.c runtime/src/konami_ops.c)
	target_include_directories(konami_ops_check PRIVATE runtime/include)
endif()

# The game: the decompiled 053248 program (src/, tools/decompile.py; SIMPSONS_DECOMPILED_DIR picks another copy) on
# its runtime (runtime/src/game_program.c: the frame, the bank, the interrupt mask and the interrupts, the tables it
# reads by name from the assets), the board's code in place of the boot's ROM sum (runtime/src/board_game.c), the
# game's own video and sound board, from its assets (runtime/src/game.c). simpsons_game_headless runs it with no
# screen or sound (check_scenarios.py compares it with kref), simpsons in a window. It opens no ROM
set(SIMPSONS_DECOMPILED_DIR ${CMAKE_SOURCE_DIR}/src CACHE PATH "The game's C (tools/decompile.py)")
file(GLOB_RECURSE SIMPSONS_DECOMPILED CONFIGURE_DEPENDS ${SIMPSONS_DECOMPILED_DIR}/*.c)
list(FILTER SIMPSONS_DECOMPILED EXCLUDE REGEX "/sound/[^/]*\\.c$")    # (the sound program's: simpsons_sound)
if(SIMPSONS_DECOMPILED)
	add_library(simpsons_game_program STATIC runtime/src/game_program.c runtime/src/konami_ops.c
		runtime/src/board_game.c ${SIMPSONS_DECOMPILED})
	target_include_directories(simpsons_game_program PUBLIC runtime/include PRIVATE ${SIMPSONS_DECOMPILED_DIR})
	target_link_libraries(simpsons_game_program PUBLIC simpsons_runtime)
	if(MSVC)
		target_compile_options(simpsons_game_program PRIVATE /bigobj /wd4244 /wd4146 /wd4102)
	else()
		target_compile_options(simpsons_game_program PRIVATE -fno-strict-aliasing)
	endif()
	add_library(simpsons_game_decompiled STATIC runtime/src/game.c)
	target_link_libraries(simpsons_game_decompiled PUBLIC simpsons_game_program simpsons_video simpsons_sound
		simpsons_assets)
	add_executable(simpsons_game_headless ports/headless/main.c)
	target_link_libraries(simpsons_game_headless PRIVATE simpsons_game_decompiled)
	# (the decompiled calls nest as the program's do; a jump to another function is a call that returns)
	simpsons_game_stack(simpsons_game_headless)
	set(SIMPSONS_WINDOW_PROGRAM simpsons_game_decompiled)
else()
	message(STATUS "No decompiled program in src/ (tools/decompile.py): no simpsons_game_headless")
endif()

# The game: the 053248 program translated to C an instruction at a time (the translation scaffold: tools/recompile.py
# writes build/generated, from the player's ROM: never part of the repository) with the board's own code in place of
# its ROM test, on the board model with frame timing, the game's own video and sound board, from its assets
# (runtime/src/game.c). simpsons_headless runs it with no screen or sound (check_scenarios.py --translated compares it
# with kref), simpsons in a window (SDL2). Neither opens the ROM set (tools/rom_in_executables.py: they hold none of it).
file(GLOB SIMPSONS_GENERATED CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/build/generated/*.c)
if(SIMPSONS_GENERATED)
	add_library(simpsons_program STATIC runtime/src/konami_cpu.c runtime/src/konami_ops.c runtime/src/board_code.c
		${SIMPSONS_GENERATED})
	target_include_directories(simpsons_program PUBLIC runtime/include PRIVATE ${CMAKE_SOURCE_DIR}/build/generated)
	target_link_libraries(simpsons_program PUBLIC simpsons_runtime)
	add_library(simpsons_game STATIC runtime/src/game.c)
	target_link_libraries(simpsons_game PUBLIC simpsons_program simpsons_video simpsons_sound simpsons_assets)
	add_executable(simpsons_headless ports/headless/main.c)
	target_link_libraries(simpsons_headless PRIVATE simpsons_game)
	if(MSVC)
		target_compile_options(simpsons_program PRIVATE /bigobj /wd4102 /wd4244)
	endif()
	# (the translated calls nest as the program's do, and the code's locals are many)
	simpsons_game_stack(simpsons_headless)
	if(NOT SIMPSONS_WINDOW_PROGRAM)
		set(SIMPSONS_WINDOW_PROGRAM simpsons_game)
	endif()
else()
	message(STATUS "No generated program in build/generated (tools/recompile.py): no game")
endif()

# The game in a window (ports/sdl2): the decompiled program where src/ has it (SIMPSONS_WINDOW_PROGRAM), else the
# translation scaffold; SDL2 from the system, or on Windows the development package unpacked in
# build/downloads/sdl2, its library beside the executable
if(SIMPSONS_WINDOW_PROGRAM)
	set(SIMPSONS_SDL2_UNPACKED "")
	if(WIN32)
		file(GLOB SIMPSONS_SDL2_UNPACKED ${CMAKE_SOURCE_DIR}/build/downloads/sdl2/SDL2-*/cmake)
	endif()
	find_package(SDL2 CONFIG QUIET HINTS ${SIMPSONS_SDL2_UNPACKED})
	if(SDL2_FOUND)
		set(SIMPSONS_SDL2 SDL2::SDL2)
		if(TARGET SDL2::SDL2main)
			list(APPEND SIMPSONS_SDL2 SDL2::SDL2main)
		endif()
		add_executable(simpsons WIN32 ports/sdl2/main.c)
		target_link_libraries(simpsons PRIVATE ${SIMPSONS_WINDOW_PROGRAM} ${SIMPSONS_SDL2})
		simpsons_game_stack(simpsons)
		if(WIN32)
			add_custom_command(TARGET simpsons POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SDL2::SDL2> $<TARGET_FILE_DIR:simpsons>)
		endif()
	else()
		message(STATUS "No SDL2: the window port (simpsons) is not built")
	endif()
endif()
