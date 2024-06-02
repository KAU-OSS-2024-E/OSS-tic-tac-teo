#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>// Sleep함수를 사용하기 위한 헤더 파일 
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
    printf("\n---------- Tic Tac Toe Game ----------");
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
            system("cls");
            printf("Please enter a number from 1 to 3!"); //범위 내에서 출력하라는 문장 출력
            Sleep(2000);//2초 동안 지연 시간 설정
            main_menu();
    }
}

void play_with_com() { //컴퓨터랑 게임 
    int choice;
    system("cls");
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n--------- Play with computer ---------");
    printf("\n1 : Easy mode"); // X가 먼저 시작
    printf("\n2 : Hard mode"); // O가 먼저 시작
    printf("\n3 : Exit");
    printf("\nEnter your choice:>");
    scanf("%d", &mode);
    turn = 1;
    switch (mode) {
        case 1:
            play_with_com_easy();
            break;
        case 2:
            play_with_com_hard();
            break;
        case 3:
            exit(1);
        default:  // case 1,2,3에 해당되지 않는다면 재입력
            system("cls");
            printf("Please enter a number from 1 to 3!"); //범위 내에서 출력하라는 문장 출력
            Sleep(2000); //2초 동안 지연 시간 설정
            play_with_com();
    }
}

void play_with_com_easy() {
    system("cls");
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n------------- Easy mode --------------");
    player = 1;
    comp = 0;
    player_move();
}

void play_with_com_hard() {
    int choice;
    system("cls");
    printf("\n---------- Tic Tac Toe Game ----------");
    printf("\n------------- Hard mode --------------");
    printf("\n1 : Play first"); // X가 먼저 시작
    printf("\n2 : Computer play first"); // O가 먼저 시작
    printf("\n3 : Exit");
    printf("\nEnter your choice:>");
    scanf("%d", &choice);

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
        default:// case 1,2,3에 해당되지 않는다면 재입력
            system("cls");
            printf("Please enter a number from 1 to 3!"); //범위 내에서 출력하라는 문장 출력
            Sleep(2000); //2초 동안 지연 시간 설정
            play_with_com();
    }
}