#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include "game_rules.h"
#include "move_cursor.h"
#include "game_logic.h"
#include "env.h"
#include "game_constants.h"

void player_move() {
    int pos;
    int row, col;
    check_draw(); // 무승부 확인
    draw_board(); // 게임 보드 그리기
    move_cursor(CURSOR_X, CURSOR_Y - 2);
    printf("Your Turn :> ");
    scanf("%d", &pos);

    row = (pos - 1) / 3;
    col = (pos - 1) % 3;

    if (board[row][col] != EMPTY)
        player_move(); // 유효하지 않은 위치면 다시 입력

    if (pos == find_win_position(player, board)) { // 플레이어가 이길 수 있는 위치인지 확인
        next_turn(pos);
        draw_board();
        move_cursor(CURSOR_X, CURSOR_Y);
        printf("Player wins");
        wait_input();
        exit(0);
    }

    next_turn(pos);
    draw_board();
    if (mode==1) 
    {
        check_draw();
        start_easy(); // 쉬운 모드 컴퓨터의 턴으로 전환
    } else if (mode==2)
    {
        start_game(); // 컴퓨터의 턴으로 전환 
    }
    else 
    {
        player2_move();
    }
}

void player2_move() { //player2함수 
    int pos;
    int row, col;
    check_draw(); // 무승부 확인
    draw_board(); // 게임 보드 그리기
    move_cursor(CURSOR_X, CURSOR_Y - 2);
    printf("player2 Turn :> ");
    scanf("%d", &pos);

    row = (pos - 1) / 3;
    col = (pos - 1) % 3;

    if (board[row][col] != EMPTY)
        player2_move(); // 유효하지 않은 위치면 다시 입력
    
    if (pos == find_win_position(player2, board)) { // 플레이어2가 이길 수 있는 위치인지 확인
        next_turn(pos);
        draw_board();
        move_cursor(CURSOR_X, CURSOR_Y);
        printf("Player2 wins");
        getch();
        exit(0);
    }

    next_turn(pos);
    draw_board();
    check_draw();
    player_move();

}

void start_game() {
    int com_win_position = find_win_position(comp, board);
    int player_win_position = find_win_position(player, board);
    int best_move = find_best_move();

    if (com_win_position) {
        next_turn(com_win_position);
        flag = 1;
    } else if (player_win_position)
        next_turn(player_win_position);
    else if (best_move)
        next_turn(best_move);
    else
        next_turn(find_next_best_move());
    
    draw_board();

    if (flag) {
        move_cursor(CURSOR_X, CURSOR_Y);
        printf("Computer wins");
        wait_input();
    } else

        player_move();
}

void start_easy() {
    int com_random_position;
    int rand_row, rand_col;
    
    do{
        com_random_position = rand() % 9 + 1;
        rand_row = (com_random_position - 1) / 3;
        rand_col = (com_random_position - 1) % 3;
    } while(board[rand_row][rand_col]!=EMPTY);

    if (com_random_position == find_win_position(comp, board)) { 
        next_turn(com_random_position);
        draw_board();
        move_cursor(CURSOR_X, CURSOR_Y);
        printf("Computer wins");
        wait_input();
        exit(0);
    }
    next_turn(com_random_position);
    draw_board();
    
    check_draw(); 
    player_move();
}

void check_draw() { //무승부 확인
    if (turn > 9) {
        move_cursor(CURSOR_X, CURSOR_Y);
        printf("Game Draw");
        wait_input();
        exit(0);
    }
}

void draw_board() {
    clear_console(); // 화면을 클리어

    // 각 셀의 내용을 출력합니다.
    for (int i = 0; i < BOARD_SIZE; i++) {
        // 가로 줄을 출력합니다.
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j != 0)
                printf("|");
            if (board[i][j] == MARK_X)
                place_marker('X', 32 + j * 8, 10 + i * 2);
            else if (board[i][j] == MARK_O)
                place_marker('O', 32 + j * 8, 10 + i * 2);
            else
                place_marker(' ', 32 + j * 8, 10 + i * 2);
        }
        printf("\n");

        // 가로 줄이 있는 경우에만 구분선을 출력합니다.
        if (i != 2)
            printf("------\n");
    }
}

void place_marker(char marker, int row, int col) {
    int x = 31 + col * 8;
    int y = 10 + row * 3;
    move_cursor(x,y);
    printf("%c", marker);
}

void next_turn(int position) {
    int row, col;

    row = (position - 1) / 3;
    col = (position - 1) % 3;

    if (turn % 2)
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
        return 8;
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
        return 9;
    return 0;
}
