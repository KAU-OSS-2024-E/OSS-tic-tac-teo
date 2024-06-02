#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

extern int board[3][3];
extern int turn, flag;
extern int mode;
extern int player, comp;

void player_move();
void start_game();
void start_easy();
void check_draw();
void draw_board();
void place_marker(char ch, int row, int col);
void next_turn(int position);
int find_best_move();
int find_next_best_move();

#endif
