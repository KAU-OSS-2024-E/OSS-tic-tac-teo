#include <stdio.h>
#include <stdlib.h>
#include "env.h"
#include "game_logic.h"
#include "move_cursor.h"
#include "game_constants.h"

void game_menu_output() {               
    clear_console();
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n1. Play with computer ");
    printf("\n2. multi_mode");
    printf("\n3. Exit");
    printf("\nEnter your choice:>");
}

void single_mode_output() { //컴퓨터랑 게임 
    clear_console();
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- Play with computer ---------");
    printf("\n1 : Easy mode"); 
    printf("\n2 : Hard mode"); 
    printf("\n3 : Go Back");
    printf("\nEnter your choice:>");
}

void multi_mode_output() { //멀티 플레이
    clear_console();;
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- multi_mode ---------");
    printf("\n1 : Normal Mode"); // X가 먼저 시작
    printf("\n2 : Speed Mode"); // O가 먼저 시작
    printf("\n3 : Go Back");
    printf("\nEnter your choice:>");
}

void multi_mode_original_output() {
    clear_console();;
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- multi_mode ---------");
    printf("\n1 : player 1 start first"); // player1로 먼저 시작
    printf("\n2 : player 2 start first"); // player2로 먼저 시작
    printf("\n3 : Go Back");
    printf("\nEnter your choice:>");
}

void multi_mode_speed_output_first() {
    clear_console();;
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- Speed Mode ---------");
    printf("\nEnter the time limit (in seconds, 0 to go back):");
    printf("\nEnter your choice:>");
}
void multi_mode_speed_output_second() {
    clear_console();;
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- Speed Mode ---------");
    printf("\nlimit time : %d", game_time_limit);
    printf("\n1 : player 1 start first"); // X가 먼저 시작
    printf("\n2 : player 2 start first"); // O가 먼저 시작
    printf("\n3 : Go Back");
    printf("\nEnter your choice:>");
}

void single_mode_easy_output() {
    clear_console();
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n------------- Easy mode --------------");
}

void single_mode_hard_output() {
    clear_console();
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n------------- Hard mode --------------");
    printf("\n1 : Play first"); // X가 먼저 시작
    printf("\n2 : Computer play first"); // O가 먼저 시작
    printf("\n3 : Go Back");
    printf("\nEnter your choice:>");
}

void input_domain_error_output() {
    clear_console();
    printf("Please enter a number from 1 to 3!"); //범위 내에서 출력하라는 문장 출력
    sleep_time(2000); //2초 동안 지연 시간 설정
}

void place_marker(char marker, int row, int col) { // 마커를 지정된 위치에 놓는 함수입니다.
    int x = 31 + col * 8;
    int y = 10 + row * 3;
    move_cursor(x,y);
    printf("%c", marker);
}

void board_output() { // 게임 보드를 그리는 함수입니다.
    clear_console(); // 화면을 클리어합니다.

    for (int i = 0; i < BOARD_SIZE; i++) { // board의 열을 출력합니다.
        for (int j = 0; j < BOARD_SIZE; j++) { // board의 행을 출력합니다.
            if (j != 0){
                printf("|"); // 세로줄을 출력합니다.
            } 
            if (board[i][j] == MARK_X){
                place_marker('X', 32 + j * 8, 10 + i * 2);
            }
            else if (board[i][j] == MARK_O){
                place_marker('O', 32 + j * 8, 10 + i * 2);
            }
            else{
                place_marker(' ', 32 + j * 8, 10 + i * 2); // board의 상태에 따라 알맞은 마커를 출력합니다.
            }
        }
        printf("\n");

        if (i != 2){
            printf("------\n"); // 가로 줄이 있는 경우에만 구분선을 출력합니다.
        }
    }
}

void time_over_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("Time Over");
    sleep_time(1000);
}

void wrong_position_error_output() {
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("wrong postion");
    sleep_time(1000);
}

void win_computer_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("Computer wins");
    wait_input();
}

void game_draw_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("Game Draw");
    wait_input();
}

void win_player_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("player wins");
    wait_input();
}

void win_player_1_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("player 1 wins");
    wait_input();
}

void win_player_2_output(){
    move_cursor(CURSOR_X, CURSOR_Y);
    printf("player 2 wins");
    wait_input();
}