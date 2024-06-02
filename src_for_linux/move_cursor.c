#include "env.h"


void move_cursor(int x, int y) {
    move(y, x);
    refresh();
}
void wait_input(){
    // 화면 갱신
    refresh();

    // 사용자 입력 대기
    getch();

    // ncurses 종료
    endwin();
}