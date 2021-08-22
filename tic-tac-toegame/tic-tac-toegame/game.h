#pragma once
#ifndef _GAME_
#define _GAME_

#define ROW 3 //������
#define COLUMN 3 //������
#define NUMBER 3 //�������������ܹ���ʤ
#define ROW_MOVE_RANGE 3 //���������ϵ����ӷ�Χ ����Χ 1 �� ���
#define COLUMN_MOVE_RANGE 3 //���������ϵ����ӷ�Χ ����Χ 1 �� ���

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int choice);//�˵�
void game(char board[ROW][COLUMN]);//��Ϸ����
int victoryJudge(char board[ROW][COLUMN]);//�ж�ʤ��ƽ��
int continueJudge(char board[ROW][COLUMN]);//ͨ���ж������Ƿ��������ж�ƽ�ֻ��Ǽ�����Ϸ
int occupyJudge(char board[ROW][COLUMN], int x, int y);//�ж��˺͵�������λ���Ƿ����
void playerMove(char board[ROW][COLUMN]);//ʵ���������
void computerMove(char board[ROW][COLUMN]);//ʵ�ֵ�������
void boardPrint(char board[ROW][COLUMN]);//��ӡ����


#endif 
