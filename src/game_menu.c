#include <stdio.h>
#include <stdlib.h>
#include "game_menu.h"
#include "game_logic.h"
#include "game_rules.h"
#include "game_constants.h"
#include "console_output.h"

// 전역 변수 정의
int board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
}; // 게임 보드 초기화
int turn = 1, flag = 0; // 게임 턴과 승리 플래그
int game_mode; //game mode
int player_1, player_2, computer; // 플레이어와 플레이어2 그리고  컴퓨터 구분
int game_time_limit; //time

void game_menu()  // game_menu함수를 새로 만들었음
{               //사용자가 첫 화면에 보았을 때 어떤 게임인지 알기 쉽고 컴튜터랑 게임을 할지 아니면 멀티플레이 게임을 할지 
                //기능을 선택할 수 있게 해줌
                //case 1에 있는 single_mode함수를 실행
    int choice;
    game_menu_output();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            single_mode();
            break;
        case 2:
            multi_mode();
            break;
        case 3:  //프로그램 강제 종료
            printf("End the program\n");
            exit(1);
        default: // case 1,2,3에 해당되지 않는다면 재입력
            input_domain_error_output();
            game_menu();
    }
}

void single_mode() { //컴퓨터랑 게임 
    int choice;
    single_mode_output();
    scanf("%d", &choice);
    turn = 1;

    switch (choice) {
        case 1:
            game_mode = 1;
            single_mode_easy();//쉬운 모드
            break;
        case 2:
            game_mode = 2;
            single_mode_hard();//어려운 모드
            break;
        case 3:
            game_menu(); // 이전 화면으로 이동
            break;
        default:  // case 1,2,3에 해당되지 않는다면 재입력
            input_domain_error_output();
            single_mode();
    }
}

void multi_mode() {
    int choice;
    multi_mode_output();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            game_mode = 3;
            multi_mode_original();
            break;
        case 2:
            multi_mode_speed();
            break;
        case 3:
            game_menu();
            break;
        default:
            input_domain_error_output();
            multi_mode();
    }
}

void single_mode_easy() {
    single_mode_easy_output();
    player_1 = 1;
    computer = 0;
    player_1_turn();
}

void single_mode_hard() {
    int choice;
    single_mode_hard_output();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            player_1 = 1;
            computer = 0;
            player_1_turn();
            break;
        case 2:            
            player_1 = 0;
            computer = 1;
            computer_turn_hard();
            break;
        case 3:
            single_mode(); //이전 화면으로 이동
            break;
        default:// case 1,2,3에 해당되지 않는다면 재입력
            input_domain_error_output();
            single_mode_hard();

    }
}

void multi_mode_original() {
    int choice;
    multi_mode_original_output();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            player_2 = 0;
            player_1 = 1;
            player_1_turn();
            break;
        case 2:
            player_2 = 1;
            player_1 = 0;
            player_2_turn();
            break;
        case 3:
            multi_mode(); //이전 화면으로 이동
            break;
        default:  // case 1,2,3에 해당되지 않는다면 재입력
            input_domain_error_output();
            multi_mode_original();
    }
}

void multi_mode_speed() {
    multi_mode_speed_output_first();
    scanf("%d", &game_time_limit);

    if (game_time_limit==0) {
        game_menu();
    }
    
    int choice;
    multi_mode_speed_output_second();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            player_2 = 0;
            player_1 = 1;// player-1 승 flag값 사용
            player_1_turn_speed();//single_player_turn함수 호출
            break;
        case 2:
            player_2 = 1;//player2 승 flag값 사용
            player_1 = 0;
            player_2_turn_speed();//player_2_turn()함수 호출
            break;
        case 3:
            multi_mode(); //이전 화면으로 이동
            break;
        default:  // case 1,2,3에 해당되지 않는다면 재입력
            input_domain_error_output();
            multi_mode_speed();
    }
}

