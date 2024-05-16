#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> //window lib depenency
#include "game_rules.h"


int turn = 1, flag = 0;
int player, comp;
int board[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch, int pos);
COORD coord = {0, 0}; // this is global variable
                      // center of axis is set to the top left cornor of the screen
void gotoxy(int x, int y)
{
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 

int main() //main function
{

  printf("hi");
  system("cls");
  menu();
  getch();
  printf("done");
  return 0;
}

void menu()
{
  int choice;
  system("cls");
  printf("\n--------MENU--------");
  printf("\n1 : Play with X");
  printf("\n2 : Play with O");
  printf("\n3 : Exit");
  printf("\nEnter your choice:>");
  scanf("%d", &choice);
  turn = 1;
  switch (choice)
  {
  case 1:
    player = 1;
    comp = 0;
    player_first();
    break;
  case 2:
    player = 0;
    comp = 1;
    start_game();
    break;
  case 3:
    exit(1);
  default:
    menu();
  }
}

int make2()
{
  if (board[5] == 2)
    return 5;
  if (board[2] == 2)
    return 2;
  if (board[4] == 2)
    return 4;
  if (board[6] == 2)
    return 6;
  if (board[8] == 2)
    return 8;
  return 0;
}

int make4()
{
  if (board[1] == 2)
    return 1;
  if (board[3] == 2)
    return 3;
  if (board[7] == 2)
    return 7;
  if (board[9] == 2)
    return 9;
  return 0;
}

void go(int n)
{
  if (turn % 2)
    board[n] = 3;
  else
    board[n] = 5;
  turn++;
}

void player_first()
{
  int pos;

  check_draw();
  draw_board();
  gotoxy(30, 18);
  printf("Your Turn :> ");
  scanf("%d", &pos);

  if (board[pos] != 2)
    player_first();

  if (pos == posswin(player, board))
  {
    go(pos);
    draw_board();
    gotoxy(30, 20);
    // textcolor(128+RED);
    printf("Player Wins");
    getch();
    exit(0);
  }

  go(pos);
  draw_board();
  start_game();
}

void start_game()
{
  // p==1 then X   p==0  then  O
  if (posswin(comp, board))
  {
    go(posswin(comp, board));
    flag = 1;
  }
  else if (posswin(player, board))
    go(posswin(player, board));
  else if (make2())
    go(make2());
  else
    go(make4());
  draw_board();

  if (flag)
  {
    gotoxy(30, 20);
    // textcolor(128+RED);
    printf("Computer wins");
    getch();
  }
  else
    player_first();
}

void check_draw()
{
  if (turn > 9)
  {
    gotoxy(30, 20);
    // textcolor(128+RED);
    printf("Game Draw");
    getch();
    exit(0);
  }
}

void draw_board()
{
  int j;

  for (j = 9; j < 17; j++)
  {
    gotoxy(35, j);
    printf("|       |");
  }
  gotoxy(28, 11);
  printf("-----------------------");
  gotoxy(28, 14);
  printf("-----------------------");

  for (j = 1; j < 10; j++)
  {
    if (board[j] == 3)
      put_X_O('X', j);
    else if (board[j] == 5)
      put_X_O('O', j);
  }
}

void put_X_O(char ch, int pos)
{
  int m;
  int x = 31, y = 10;

  m = pos;

  if (m > 3)
  {
    while (m > 3)
    {
      y += 3;
      m -= 3;
    }
  }
  if (pos % 3 == 0)
    x += 16;
  else
  {
    pos %= 3;
    pos--;
    while (pos)
    {
      x += 8;
      pos--;
    }
  }
  gotoxy(x, y);
  printf("%c", ch);
}
