#include <stdio.h>

int posswin(int p, int *board) // starting of function to check whether you put value at an empty space
{
  // p==1 then X   p==0  then  O
  int i;
  int check_val, pos;

  if (p == 1)
    check_val = 18;
  else
    check_val = 50;

  i = 1;
  while (i <= 9) // row check
  {
    if (board[i] * board[i + 1] * board[i + 2] == check_val)
    {
      if (board[i] == 2)
        return i;
      if (board[i + 1] == 2)
        return i + 1;
      if (board[i + 2] == 2)
        return i + 2;
    }
    i += 3;
  }

  i = 1;
  while (i <= 3) // column check
  {
    if (board[i] * board[i + 3] * board[i + 6] == check_val)
    {
      if (board[i] == 2)
        return i;
      if (board[i + 3] == 2)
        return i + 3;
      if (board[i + 6] == 2)
        return i + 6;
    }
    i++;
  }

  if (board[1] * board[5] * board[9] == check_val)
  {
    if (board[1] == 2)
      return 1;
    if (board[5] == 2)
      return 5;
    if (board[9] == 2)
      return 9;
  }

  if (board[3] * board[5] * board[7] == check_val)
  {
    if (board[3] == 2)
      return 3;
    if (board[5] == 2)
      return 5;
    if (board[7] == 2)
      return 7;
  }
  return 0;
}