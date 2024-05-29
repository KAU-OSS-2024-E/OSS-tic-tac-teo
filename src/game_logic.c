#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "game_logic.h"
#include "move_cursor.h"
#include "game_rules.h"

void player_move() {//multiplay
    int pos;
    check_draw(); // 무승부 확인
    draw_board();
    printf("Your Turn :> ");
    scanf("%d", &pos);

    if (board[pos] != 2)
        player_move(); // 유효하지 않은 위치면 다시 입력

    if (pos == find_win_position(player, board)) { // 플레이어가 이길 수 있는 위치인지 확인
        next_turn(pos);
        draw_board();
        printf("Player wins");
        getch();
        exit(0);
    }
    else {
        next_turn(pos);
        start_game(); // 컴퓨터의 턴으로 전환
    }

    
}

void start_game() {
    int com_win_position = find_win_position(comp, board);
    int player_win_position = find_win_position(player, board);
    int best_move = find_best_move();

    draw_board();

    if (com_win_position) {
        next_turn(com_win_position);
        flag = 1;
    } else if (player_win_position)
        next_turn(player_win_position);
    else if (best_move)
        next_turn(best_move);
    else
        next_turn(find_next_best_move());
    


    if (flag) {
        draw_board();
        printf("Computer wins");
        getch();
    } else
        player_move();
}

void check_draw() {
    if (turn > 9) {
        draw_board();
        printf("Game Draw");
        getch();
        exit(0);
    }
}

void draw_board() {
    // int j = 0; 
    system("cls");
    
    for(int j = 1 ; j < 10 ; j++){
        if (board[j] == 3){
            printf("| X ");
        }
        else if (board[j] == 5){
            printf("| O ");             
        }
        else {
            printf("|   ");
        }
        if(j%3 == 0 ){
            printf("|\n");
        }
    }
    
}

void next_turn(int position) {//update board
    if (turn % 2)
        board[position] = 3;
    else
        board[position] = 5;
    
    turn++;
}

int find_best_move() { //use case 
    if (board[5] == 2)
        return 5;
    if (board[2] == 2)
        return 2;
    if (board[4] == 2)
        return 4;
    if (board[6] == 2)
        return 6;
    if (board[8] == 2)
        return 8;
    return 0;
}

int find_next_best_move() {//use switch case
    if (board[1] == 2)
        return 1;
    if (board[3] == 2)
        return 3;
    if (board[7] == 2)
        return 7;
    if (board[9] == 2)
        return 9;
    return 0;
}
