#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#define IN_ROW 9 //����
#define IN_COLUMN 9 //����
#define OUT_ROW 11 //����
#define OUT_COLUMN 11 //����
#define MINE_NUMBER 10 //����

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void headline(); //�����
void menu(); //��Ϸ�˵� 
void initMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column, char symbols); //��ʼ������
void putMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], int mineNumber, int x, int y); //����
void init(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]); //��ʼ��ģ��
void printMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column); //��ӡ����
void statisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //��ɨ�������׸����з�����Χ����֮��
int newStatisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //������������֮�Ͳ�����
void openBoard(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y); //չ��ģ��
int sweeperMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int* count2); //ɨ��
void isWin(char faceMineBoard[OUT_ROW][OUT_COLUMN], int* p); //��Ϸģ��
void game(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]); //�ж�ʤ��

#endif // !_GAME_H_
