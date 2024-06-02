cmake_minimum_required(VERSION 3.10)

# Project name
project(TicTacToe C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(headers)

# Source files
set(SOURCES
    src/game_logic.c
    src/game_rules.c
    src/main.c
    src/main_menu.c
    src/move_cursor.c
)

# Executable
add_executable(TicTacToe ${SOURCES})

# Platform-specific settings
if (WIN32)
    target_link_libraries(TicTacToe user32)
endif()
