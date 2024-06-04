
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"
#include "game_rules.h"
#include "move_cursor.h"
#include "game_constants.h"
#include "console_output.h"

void player_1_turn() { // 플레이어의 움직임 처리 함수입니다.
    int pos;
    int row, col;
    check_draw(); // 무승부 조건을 확인합니다.
    board_output(); // 게임 보드를 그립니다.
    move_cursor(CURSOR_X, CURSOR_Y - 2); // 위치 입력시의 커서의 Y좌표가 결과 출력시와는 다르기 때문에 값을 조정해줍니다.
    printf("Your Turn :> ");
    scanf("%d", &pos); // 사용자로부터 보드의 위치를 입력받을 때 편의상 (x, y)의 형태가 아닌 키패드 1 ~ 9 의 형태로 받습니다.

    row = (pos - 1) / 3;
    col = (pos - 1) % 3; // 사용자로부터 입력받은 1 ~ 9까지의 입력값을 2차원 배열의 위치에 알맞은 값으로 변경합니다.

    if (board[row][col] != EMPTY)
        player_1_turn(); // 유효하지 않은 위치면 재귀 호출을 통해 다시 입력받습니다.

    if (pos == find_win_position(player_1, board)) { // 플레이어가 이길 수 있는 위치인지 확인합니다.
        next_turn(pos); // 정해진 위치에 마커를 표시하고 다음 턴으로 넘어갑니다.
        board_output();
        win_player_output();
        exit(0);
    }

    next_turn(pos);
    board_output();
    check_draw();

    switch (mode){
        case 1: 
            computer_turn_easy(); // 쉬운 모드 컴퓨터의 턴으로 전환합니다.
            break;
        case 2:
            computer_turn_hard(); // 컴퓨터의 턴으로 전환합니다.
            break;
        default:
            player_2_turn(); // player2의 턴으로 전환합니다.
            break;
    }
}

void player_2_turn() { //플레이어2의 움직임 처리 함수입니다.
    int pos;
    int row, col;
    check_draw(); 
    board_output(); 
    move_cursor(CURSOR_X, CURSOR_Y - 2);
    printf("player 2 Turn :> ");
    scanf("%d", &pos); // player2의 입력을 받아 pos 변수에 저장

    row = (pos - 1) / 3;
    col = (pos - 1) % 3; 

    if (board[row][col] != EMPTY)
        player_2_turn(); // 유효하지 않은 위치면 재귀 호출을 통해 다시 입력받습니다.
    
    if (pos == find_win_position(player_2, board)) { // 플레이어2가 이길 수 있는 위치인지 확인합니다.
        next_turn(pos);
        board_output();
        void win_player_2_output();
        exit(0);
    }

    next_turn(pos); // 정해진 위치에 플레이어2의 마커를 표시하고 다음 턴으로 넘어갑니다. 
    board_output();
    check_draw();
    player_1_turn(); //플레이어의 턴으로 전환합니다.
}

void player_1_turn_speed() {
    int pos;
    int row, col;
    time_t start_time, current_time;

    start_time = time(NULL); // 현재 시간을 얻음
    
    check_draw();
    board_output();
    move_cursor(CURSOR_X, CURSOR_Y - 2);
    printf("Your Turn :> ");
    scanf("%d", &pos);

    row = (pos - 1) / 3;
    col = (pos - 1) % 3;

    if (board[row][col] != EMPTY) {
        wrong_position_error_output();
        player_2_turn_speed(); // 유효하지 않은 위치면 다시 입력
    }

    current_time = time(NULL); // 현재 시간을 다시 얻음
    if (current_time - start_time > game_time_limit) {
        time_over_output();
        player_2_turn_speed();
    }

    if (pos == find_win_position(player_1, board)) { // 플레이어가 이길 수 있는 위치인지 확인
        next_turn_multi(pos, player_1);
        board_output();
        win_player_1_output();
        exit(0);
    }

    next_turn_multi(pos, player_1);
    board_output();
    check_draw();
    player_2_turn_speed();
}

void player_2_turn_speed() { //player2함수 
    int pos;
    int row, col;
    time_t start_time, current_time;

    start_time = time(NULL);
    
    check_draw();
    board_output();
    move_cursor(CURSOR_X, CURSOR_Y - 2);
    printf("player 2 Turn :> ");
    scanf("%d", &pos);

    row = (pos - 1) / 3;
    col = (pos - 1) % 3;

    if (board[row][col] != EMPTY) {
        wrong_position_error_output();
        player_1_turn_speed(); // 유효하지 않은 위치면 다시 입력
    }

    current_time = time(NULL); // 현재 시간을 다시 얻음

    if (current_time - start_time > game_time_limit) {
        time_over_output();
        player_1_turn_speed();
    }

    if (pos == find_win_position(player_2, board)) { // 플레이어2가 이길 수 있는 위치인지 확인
        next_turn_multi(pos, player_2);
        board_output();
        win_player_2_output();
        exit(0);
    }

    next_turn_multi(pos, player_2);
    board_output();
    check_draw();
    player_1_turn_speed();
}

void computer_turn_hard() { // 게임 시작 시 컴퓨터의 움직임을 처리하는 함수입니다.
    int com_win_position = find_win_position(computer, board); // 컴퓨터가 이길 수 있는 위치를 찾습니다.
    int player_win_position = find_win_position(player_1, board); // 플레이어가 이길 수 있는 위치를 찾습니다.
    int best_move = find_best_move(); // 최선의 수를 찾습니다.


    if (com_win_position) {
        next_turn(com_win_position); // 컴퓨터가 이길 수 있는 위치가 있으면 해당 위치에 마커를 놓고 턴을 넘깁니다.
        flag = 1; // 컴퓨터가 승리함을 표시합니다.
    } 
    else if (player_win_position)
        next_turn(player_win_position); // 플레이어가 이길 수 있는 위치가 있으면 해당 위치에 마커를 놓고 턴을 넘깁니다.
    else if (best_move)
        next_turn(best_move); // 최선의 수가 있으면 해당 위치에 마커를 놓고 턴을 넘깁니다.
    else
        next_turn(find_next_best_move()); // 다음으로 좋은 수를 찾아 마커를 놓고 턴을 넘깁니다.
    
    board_output();

    if (flag) { // 컴퓨터가 승리한 경우를 처리합니다.
        win_computer_output();
    } 
    else
        player_1_turn();
}

void computer_turn_easy() {
    int com_random_position;
    int rand_row, rand_col;
    
    do{
        com_random_position = rand() % 9 + 1;
        rand_row = (com_random_position - 1) / 3;
        rand_col = (com_random_position - 1) % 3;
    } while(board[rand_row][rand_col]!=EMPTY);

    if (com_random_position == find_win_position(computer, board)) { 
        next_turn(com_random_position);
        board_output();
        win_computer_output();
        exit(0);
    }
    next_turn(com_random_position);
    board_output();
    
    check_draw(); 
    player_1_turn();
}


void next_turn(int position) { // 다음 턴을 처리하는 함수입니다.
    int row, col;

    row = (position - 1) / 3;
    col = (position - 1) % 3; // 매개변수로 받은 1 ~ 9까지의 값을 2차원 배열의 위치에 알맞은 값으로 변경합니다.

    if (turn % 2)
        board[row][col] = MARK_X;
    else
        board[row][col] = MARK_O; // turn의 값에 따라 보드에 X 또는 O를 표시합니다.
    turn++; // turn 값을 증가시킵니다.
}


void next_turn_multi(int position, int p) {
    // p==1 then X   p==0  then  O
    int row, col;

    row = (position - 1) / 3;
    col = (position - 1) % 3;

    if (p)
        board[row][col] = MARK_X;
    else
        board[row][col] = MARK_O;
    turn++;
}

int find_best_move() {

    if (board[1][1] == EMPTY)
        return 5;
    if (board[0][1] == EMPTY)
        return 2;
    if (board[1][0] == EMPTY)
        return 4;
    if (board[1][2] == EMPTY)
        return 6;
    if (board[2][1] == EMPTY)
        return 8; // 십자가 모양으로 비어있는 위치를 확인 후 해당 위치를 반환합니다.
    return 0;
}

int find_next_best_move() {
    if (board[0][0] == EMPTY)
        return 1;
    if (board[0][2] == EMPTY)
        return 3;
    if (board[2][0] == EMPTY)
        return 7;
    if (board[2][2] == EMPTY)
        return 9; // 네 개의 모서리에 비어있는 위치를 확인 후 해당 위치를 반환합니다.
    return 0;
}