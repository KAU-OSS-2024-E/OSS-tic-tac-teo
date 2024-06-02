#include "env.h"
#include "move_cursor.h"

void clear_console() {
    system("cls");
}

void sleep_time(int time){
    Sleep(time);
}

COORD coord = {0, 0}; // this is global variable
                      // center of axis is set to the top left cornor of the screen

void move_cursor(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}