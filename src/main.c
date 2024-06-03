#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "env.h"
#include "main_menu.h"
#include "move_cursor.h"


// 전역 변수 정의
int board[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}; // 게임 보드 초기화
int turn = 1, flag = 0; // 게임 턴과 승리 플래그
int mode;
int player, player2, comp; // 플레이어와 플레이어2 그리고  컴퓨터 구분

int main() {
    srand(time(NULL)); // 시드 설정

    clear_console(); // 화면을 클리어
    main_menu(); // 메인 메뉴 함수 호출
    wait_input();
    return 0;
}
