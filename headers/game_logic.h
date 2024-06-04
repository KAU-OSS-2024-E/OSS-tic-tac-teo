#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

extern int board[3][3];
extern int turn, flag;
extern int mode;
extern int player,player2,comp; //player2전역 변수 선언 시켜줌
extern int limit;

void player_move();
void player2_move();//player2함수 생성
void player1_move_speed();
void player2_move_speed();
void start_game();
void start_easy();
void check_draw();
void draw_board();
void place_marker(char ch, int row, int col);
void next_turn(int position);
void next_turn_multi(int position, int p);
int find_best_move();
int find_next_best_move();

#endif
