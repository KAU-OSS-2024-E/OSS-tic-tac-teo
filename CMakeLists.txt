cmake_minimum_required(VERSION 3.10)

project(OSS_tic_tac_toe VERSION 1.0)

set(CMAKE_C_STANDARD 99)

include_directories(headers)

set(SRC_FILES
    src/main.c
    src/game_logic.c
    src/game_menu.c
    src/game_rules.c
    src/console_output.c
)

if(WIN32)
    list(APPEND SRC_FILES
        src_for_win/env.c
        src_for_win/move_cursor.c
    )
elseif(UNIX)
    list(APPEND SRC_FILES
        src_for_linux/env.c
        src_for_linux/move_cursor.c
    )
endif()

add_executable(${PROJECT_NAME} ${SRC_FILES})