#include <stdio.h>
#include <stdlib.h>
#include "main_menu.h"
#include "game_logic.h"
#include "move_cursor.h"

void main_menu()  // main_menu함수를 새로 만들었음
{               //사용자가 첫 화면에 보았을 때 어떤 게임인지 알기 쉽고 컴튜터랑 게임을 할지 아니면 멀티플레이 게임을 할지 
                //기능을 선택할 수 있게 해줌
                //case 1에 있는 play_with_com함수를 실행
                //case 2에 있는 멀티 플레이 함수 기능은 따로 만들어야 함
    int choice;
    system("cls");
    printf("\n-------- Tic Tac Toe Game--------");
    printf("\n1. Play with computer ");
    printf("\n2. Multiplay");
    printf("\n3. Exit");

    printf("\nEnter your choice:>");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            play_with_com();
            break;
        case 2:
           //multiplay();
            break;
        case 3:  //프로그램 강제 종료
            printf("End the program\n");
            exit(1);
        default: // case 1,2,3에 해당되지 않는다면 재입력
            main_menu();
    }
}

void play_with_com() { //컴퓨터랑 게임 
    int choice;
    system("cls");
    printf("\n--------loading--------");
    printf("\n1 : Play with X"); // X가 먼저 시작
    printf("\n2 : Play with O"); // O가 먼저 시작
    printf("\n3 : Exit");
    printf("\nEnter your choice:>");
    scanf("%d", &choice);
    turn = 1;
    switch (choice) {
        case 1:
            player = 1;
            comp = 0;
            player_move();
            break;
        case 2:
            player = 0;
            comp = 1;
            start_game();
            break;
        case 3:
            exit(1);
            
        default:
            play_with_com();
    }
}
