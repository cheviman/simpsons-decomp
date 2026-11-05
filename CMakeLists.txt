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
endif()
