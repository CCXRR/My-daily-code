#pragma once
#ifndef _GAME_
#define _GAME_

#define ROW 3 //棋盘行
#define COLUMN 3 //棋盘列
#define NUMBER 3 //几个棋子相连能够获胜
#define ROW_MOVE_RANGE 3 //电脑在行上的落子范围 （范围 1 到 无穷）
#define COLUMN_MOVE_RANGE 3 //电脑在列上的落子范围 （范围 1 到 无穷）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int choice);//菜单
void game(char board[ROW][COLUMN]);//游戏主体
int victoryJudge(char board[ROW][COLUMN]);//判断胜负平局
int continueJudge(char board[ROW][COLUMN]);//通过判断棋盘是否下满来判断平局还是继续游戏
int occupyJudge(char board[ROW][COLUMN], int x, int y);//判断人和电脑落子位置是否合理
void playerMove(char board[ROW][COLUMN]);//实现玩家下棋
void computerMove(char board[ROW][COLUMN]);//实现电脑下棋
void boardPrint(char board[ROW][COLUMN]);//打印棋盘


#endif 
