#include "game_logic.h"
#include "game_constants.h"

int find_win_position(int p, int board[BOARD_SIZE][BOARD_SIZE]) {
  int i, j;
  int check_val;

  if (p == 1) // p가 1이면 X, 0이면 O로 표시합니다.
    check_val = 18; // 한 줄의 세 칸 중 두 칸이 채워져있고 한 칸이 비어져있으면 3*3*2 = 18 입니다.
  else
    check_val = 50; // 한 줄의 세 칸 중 두 칸이 채워져있고 한 칸이 비어져있으면 5*5*2 = 50 입니다.

  for (i = 0; i < BOARD_SIZE; i++) { // 각 행을 확인합니다.
      if (board[i][0] * board[i][1] * board[i][2] == check_val) {
          for (j = 0; j < BOARD_SIZE; j++) {
              if (board[i][j] == EMPTY)
                  return i * 3 + j + 1; // 빈 공간의 위치를 반환합니다.
          }
      }
  }

  for (j = 0; j < BOARD_SIZE; j++) { // 각 열을 확인합니다.
      if (board[0][j] * board[1][j] * board[2][j] == check_val) {
          for (i = 0; i < BOARD_SIZE; i++) {
              if (board[i][j] == EMPTY)
                  return i * 3 + j + 1;
          }
      }
  }

  if (board[0][0] * board[1][1] * board[2][2] == check_val) { // 대각선을 확인합니다. (좌상단 -> 우하단)
      for (i = 0; i < BOARD_SIZE; i++) {
          if (board[i][i] == EMPTY)
              return i * 3 + i + 1;
      }
  }

  if (board[0][2] * board[1][1] * board[2][0] == check_val) { // 대각선을 확인합니다. (우상단 -> 좌하단)
      for (i = 0; i < BOARD_SIZE; i++) {
          if (board[i][2 - i] == EMPTY)
              return i * 3 + 2 - i + 1;
      }
  }


  return 0;
}
