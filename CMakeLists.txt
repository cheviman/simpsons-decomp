# Name:        CMakeLists.txt
# Description: build of The Simpsons' development tools (the board's runtime and the game come later)
# Version:     0.1.0
# Created:     05-11-2026
# Modified:    05-11-2026
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

# The board as the program sees it (memory map, banks, interrupts, the EEPROM), the controls' scripts, and the
# ROM set's regions
add_library(simpsons_runtime STATIC
	runtime/src/machine.c
	runtime/src/sound.c
	runtime/src/script.c
	runtime/src/game_data.c
)
target_include_directories(simpsons_runtime PUBLIC runtime/include PRIVATE runtime/src)

# The reader of the player's ROM set: for the tools that run the original code, never for the game
add_library(simpsons_rom_set STATIC runtime/src/rom_set.c runtime/src/inflate.c)
target_link_libraries(simpsons_rom_set PUBLIC simpsons_runtime)
target_include_directories(simpsons_rom_set PRIVATE runtime/src)

find_package(Python3 COMPONENTS Interpreter)

# The reference tools: the original program on MAME's cores (tools/core/konami/reference): Konami's CPU, its
# disassembler's oracle and kref on the board model; the video and the sound board follow
option(SIMPSONS_REFERENCE_TOOLS "Build the MAME-based reference tools" ON)
if(SIMPSONS_REFERENCE_TOOLS)
	if(NOT Python3_FOUND)
		message(FATAL_ERROR "The reference tools need Python 3 (MAME's Konami CPU core is written by m6809make.py)")
	endif()
	set(K_CPU 053248)
	set(K_GAME_RUNTIME simpsons_rom_set)
	include(${CMAKE_SOURCE_DIR}/tools/core/konami/reference/reference.cmake)
	# the translated program's helpers on all their inputs (tools/core/konami/reference/compare_konami_ops.py)
	add_executable(konami_ops_check tools/core/konami/reference/konami_ops_check.c runtime/src/konami_ops.c)
	target_include_directories(konami_ops_check PRIVATE runtime/include)
endif()

# The translation scaffold: the 053248 program translated to C an instruction at a time (tools/recompile.py writes
# build/generated, from the player's ROM: never part of the repository) on the board model, with frame timing, and
# the reference's sound board and video (simpsons_headless, which check_scenarios.py --translated compares with kref
# --timing frames)
file(GLOB SIMPSONS_GENERATED CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/build/generated/*.c)
option(SIMPSONS_SCAFFOLD "Build the 053248 translation scaffold (simpsons_headless)" ON)
if(SIMPSONS_SCAFFOLD AND SIMPSONS_REFERENCE_TOOLS AND SIMPSONS_GENERATED)
	add_library(simpsons_program STATIC runtime/src/konami_cpu.c runtime/src/konami_ops.c ${SIMPSONS_GENERATED})
	target_include_directories(simpsons_program PUBLIC runtime/include PRIVATE ${CMAKE_SOURCE_DIR}/build/generated)
	target_link_libraries(simpsons_program PUBLIC simpsons_rom_set)
	add_executable(simpsons_headless ports/headless/main.cpp)
	target_link_libraries(simpsons_headless PRIVATE simpsons_program ksound_053260_reference kvideo_053246_reference
		simpsons_rom_set)
	if(MSVC)
		target_compile_options(simpsons_program PRIVATE /bigobj /wd4102 /wd4244)
		# (the translated calls nest as the program's do, and the code's locals are many)
		target_link_options(simpsons_headless PRIVATE /STACK:67108864)
	endif()
elseif(SIMPSONS_SCAFFOLD AND SIMPSONS_REFERENCE_TOOLS)
	message(STATUS "No generated program in build/generated (tools/recompile.py): no scaffold")
endif()
