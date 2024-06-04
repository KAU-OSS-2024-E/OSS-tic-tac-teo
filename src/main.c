#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "env.h"
#include "game_menu.h"
#include "move_cursor.h"
#include "game_constants.h"


// 전역 변수 정의
int board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
}; // 게임 보드 초기화
int turn = 1, flag = 0; // 게임 턴과 승리 플래그
int mode; //game mode
int player_1, player_2, computer; // 플레이어와 플레이어2 그리고  컴퓨터 구분
int game_time_limit; //time

int main() {
    srand(time(NULL)); // 시드 설정

    clear_console(); // 화면을 클리어
    game_menu(); //game menu 함수 호출
    wait_input();
    return 0;
}
