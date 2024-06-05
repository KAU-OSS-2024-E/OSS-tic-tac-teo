cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름과 버전 설정
project(OSS_tic_tac_toe VERSION 1.0)

# C 표준 설정
set(CMAKE_C_STANDARD 99)

# 헤더 파일 디렉토리 포함
include_directories(headers)

# 소스 파일 설정
set(SRC_FILES
    src/main.c
    src/game_logic.c
    src/game_menu.c
    src/game_rules.c
    src/console_output.c
)

# 플랫폼에 따라 소스 파일 추가
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
    # ncurses 라이브러리 링크
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
endif()

# 실행 파일 출력 디렉토리를 프로젝트 루트로 설정
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 필요한 경우 라이브러리 링크
if(UNIX)
    target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
endif()
