#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

extern int board[3][3];
extern int turn, flag;
extern int player, comp;

void player_move();
void start_game();
void check_draw();
void draw_board();
void place_marker(char ch, int row, int col);
void next_turn(int position);
int find_best_move();
int find_next_best_move();

#endif
