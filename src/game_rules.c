#include "game_rules.h"

int find_win_position(int p, int board[3][3]) // starting of function to check whether you put value at an empty space
{
  // p==1 then X   p==0  then  O
  int i, j;
  int check_val;

  if (p == 1)
    check_val = 18;
  else
    check_val = 50;

  // row check
  for (i = 0; i < 3; i++) {
      if (board[i][0] * board[i][1] * board[i][2] == check_val) {
          for (j = 0; j < 3; j++) {
              if (board[i][j] == 2)
                  return i * 3 + j + 1;
          }
      }
  }

  // column check
  for (j = 0; j < 3; j++) {
      if (board[0][j] * board[1][j] * board[2][j] == check_val) {
          for (i = 0; i < 3; i++) {
              if (board[i][j] == 2)
                  return i * 3 + j + 1;
          }
      }
  }

// diagonal check
  if (board[0][0] * board[1][1] * board[2][2] == check_val) {
      for (i = 0; i < 3; i++) {
          if (board[i][i] == 2)
              return i * 3 + i + 1;
      }
  }

  if (board[0][2] * board[1][1] * board[2][0] == check_val) {
      for (i = 0; i < 3; i++) {
          if (board[i][2 - i] == 2)
              return i * 3 + 2 - i + 1;
      }
  }


  return 0;
}
