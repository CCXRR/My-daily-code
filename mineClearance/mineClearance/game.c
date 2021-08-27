#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void headline() //大标题
{
	printf("            _             _____ _                                     \n");
	printf("           (_)           / ____| |                                    \n");
	printf("  _ __ ___  _ _ __   ___| |    | | ___  __ _ _ __ __ _ _ __   ___ ___ \n");
	printf(" | '_ ` _ \\| | '_ \\ / _ \\ |    | |/ _ \\/ _` | '__/ _` | '_ \\ / __/ _ \\\n");
	printf(" | | | | | | | | | |  __/ |____| |  __/ (_| | | | (_| | | | | (_|  __/\n");
	printf(" |_| |_| |_|_|_| |_|\\___|\\_____|_|\\___|\\__,_|_|  \\__,_|_| |_|\\___\\___|\n");
}

void menu() //游戏菜单 
{
	printf("******************************\n");
	printf("*******1.play     0.exit******\n");
	printf("******************************\n");
}

void initMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column, char symbols) //初始化雷盘
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			faceMineBoard[i][j] = symbols;
		}
	}
}

void putMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], int mineNumber, int x, int y) //埋雷
{
	int i, j;

	while (mineNumber)
	{
		i = rand() % IN_ROW + 1;
		j = rand() % IN_COLUMN + 1;

		if (kernelMineBoard[i][j] - '0' == 0 && (&kernelMineBoard[i][j]) != (&kernelMineBoard[x][y]))
		{
			kernelMineBoard[i][j] = '1';
			mineNumber--;
		}
	}
}

void init(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]) //初始化模块
{
	initMineBoard(faceMineBoard, OUT_ROW, OUT_COLUMN, '*'); //初始化表雷盘
	initMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN, '0'); //初始化里雷盘
}

void printMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column) //打印雷盘
{
	int i, j;

	for (i = 0; i < row - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < column - 1; j++)
		{
			if (i == 0)
			{
				printf("%d ", j);
			}
			else
			{
				printf("%c ", faceMineBoard[i][j]);
			}
		}
		printf("\n");
	}
}

void statisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //在扫出的无雷格子中放入周围雷数之和
{
	int i, j;
	char count = '0';

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (kernelMineBoard[i][j] == '1')
			{
				count++;
			}
		}
	}
	faceMineBoard[x][y] = count;
}

int newStatisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //计算四周雷数之和并返回
{
	int i, j;
	char count = '0';

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (kernelMineBoard[i][j] == '1')
			{
				count++;
			}
		}
	}

	return (count - '0');
}

void openBoard(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //展开模块
{
	if (x >= 1 && x <= IN_ROW && y >= 1 && y <= IN_COLUMN)
	{
		if (newStatisticsAround(kernelMineBoard, faceMineBoard, x, y) != 0)
		{
			statisticsAround(kernelMineBoard, faceMineBoard, x, y);
		}
		else
		{
			if (faceMineBoard[x + 1][y + 1] == '*' || faceMineBoard[x + 1][y - 1] == '*' || faceMineBoard[x - 1][y + 1] == '*' || faceMineBoard[x - 1][y - 1] == '*') //防止重复展开
			{
				faceMineBoard[x + 1][y + 1] = '0'; //以（x， y）方格为中心向四周展开
				faceMineBoard[x + 1][y - 1] = '0';
				faceMineBoard[x + 1][y] = '0';
				faceMineBoard[x - 1][y - 1] = '0';
				faceMineBoard[x - 1][y] = '0';
				faceMineBoard[x - 1][y + 1] = '0';
				faceMineBoard[x][y - 1] = '0';
				faceMineBoard[x][y + 1] = '0';

				openBoard(kernelMineBoard, faceMineBoard, x + 1, y + 1);
				openBoard(kernelMineBoard, faceMineBoard, x + 1, y);
				openBoard(kernelMineBoard, faceMineBoard, x + 1, y - 1);
				openBoard(kernelMineBoard, faceMineBoard, x, y + 1);
				openBoard(kernelMineBoard, faceMineBoard, x, y - 1);
				openBoard(kernelMineBoard, faceMineBoard, x - 1, y + 1);
				openBoard(kernelMineBoard, faceMineBoard, x - 1, y);
				openBoard(kernelMineBoard, faceMineBoard, x - 1, y - 1);
			}
		}
	}
}

int sweeperMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int* count2)//扫雷
{
	int i, j;

	printf("请输入坐标(空格隔开)\n");
	while (1)
	{
		scanf("%d %d", &i, &j);

		if (faceMineBoard[i][j] == '*' && i > 0 && j > 0 && i <= IN_ROW && j <= IN_COLUMN)
		{
			if (*count2 == 1)
			{
				putMine(kernelMineBoard, MINE_NUMBER, i, j); //埋雷
				(*count2)++;
			}
			if (kernelMineBoard[i][j] == '0')
			{
				statisticsAround(kernelMineBoard, faceMineBoard, i, j); //在扫出的无雷格子中放入周围雷数之和
				openBoard(kernelMineBoard, faceMineBoard, i, j); //张开雷盘 递归

				return 1;
			}

			if (kernelMineBoard[i][j] == '1')
			{
				faceMineBoard[i][j] = '1';
				return 0;
			}

		}
		else
		{
			printf("该坐标已排除或坐标超出棋盘范围，请重新输入\n");
		}
	}
}

void isWin(char faceMineBoard[OUT_ROW][OUT_COLUMN], int* p) //判断胜负
{
	int i, j;

	for (i = 1; i <= IN_ROW; i++)
	{
		for (j = 1; j <= IN_COLUMN; j++)
		{
			if (faceMineBoard[i][j] == '*')
			{
				(*p)++;
			}
		}
	}
}

void game(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]) //游戏模块
{
	int result;
	int count1 = 0; //计算faceMineBoard中*的数量 用于判断胜负
	int count2 = 1; //实现第一次不会踩雷

	do
	{
		printMineBoard(faceMineBoard, OUT_ROW, OUT_COLUMN); //打印雷盘
		result = sweeperMine(kernelMineBoard, faceMineBoard, &count2); //扫雷

		count1 = 0;
		isWin(faceMineBoard, &count1); //判断胜负

		if (result == 0)
		{
			printMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN); //打印雷盘
			printf("你被炸死了是否继续（0 or 1）>:");
		}

		if (count1 == MINE_NUMBER)
		{
			printMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN); //打印雷盘
			printf("你赢了！是否继续（0 or 1）>:");
			break;
		}
	} while (result);
}