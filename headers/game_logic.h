#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

extern int board[3][3];
extern int turn, flag;
extern int mode;
extern int player,player2,comp; //player2전역 변수 선언 시켜줌

void player_move();
void player2_move();//player2함수 생성
void start_game();
void start_easy();
void check_draw();
void draw_board();
void place_marker(char ch, int row, int col);
void next_turn(int position);
int find_best_move();
int find_next_best_move();

#endif
