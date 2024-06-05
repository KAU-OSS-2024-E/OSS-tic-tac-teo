#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

extern int board[3][3];
extern int turn, flag;
extern int game_mode;
extern int player_1,player_2,computer; //player2전역 변수 추가적으로 선언 시켜줌
extern int game_time_limit;

void player_1_turn();
void player_2_turn();//milti_player_2_turn 함수 선언
void player_1_turn_speed();
void player_2_turn_speed();

void computer_turn_hard();
void computer_turn_easy();


void next_turn(int position);
void next_turn_multi(int position, int player);
int find_best_move();
int find_next_best_move();

#endif
