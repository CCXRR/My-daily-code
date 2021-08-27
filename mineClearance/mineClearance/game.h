#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#define IN_ROW 9 //内行
#define IN_COLUMN 9 //内列
#define OUT_ROW 11 //外行
#define OUT_COLUMN 11 //外列
#define MINE_NUMBER 10 //雷数

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void headline(); //大标题
void menu(); //游戏菜单 
void initMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column, char symbols); //初始化雷盘
void putMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], int mineNumber, int x, int y); //埋雷
void init(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]); //初始化模块
void printMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column); //打印雷盘
void statisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //在扫出的无雷格子中放入周围雷数之和
int newStatisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //计算四周雷数之和并返回
void openBoard(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //展开模块
int sweeperMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int* count2); //扫雷
void isWin(char faceMineBoard[OUT_ROW][OUT_COLUMN], int* p); //游戏模块
void game(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]); //判断胜负

#endif // !_GAME_H_
