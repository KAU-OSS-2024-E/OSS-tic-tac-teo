#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "env.h"
#include "game_menu.h"
#include "move_cursor.h"
#include "game_constants.h"

int main() {
    srand(time(NULL)); // 시드 설정
    clear_console(); // 화면을 클리어
    game_menu(); //game menu 함수 호출
    return 0;
}
