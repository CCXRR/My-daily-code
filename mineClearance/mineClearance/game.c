#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void headline() //�����
{
	printf("            _             _____ _                                     \n");
	printf("           (_)           / ____| |                                    \n");
	printf("  _ __ ___  _ _ __   ___| |    | | ___  __ _ _ __ __ _ _ __   ___ ___ \n");
	printf(" | '_ ` _ \\| | '_ \\ / _ \\ |    | |/ _ \\/ _` | '__/ _` | '_ \\ / __/ _ \\\n");
	printf(" | | | | | | | | | |  __/ |____| |  __/ (_| | | | (_| | | | | (_|  __/\n");
	printf(" |_| |_| |_|_|_| |_|\\___|\\_____|_|\\___|\\__,_|_|  \\__,_|_| |_|\\___\\___|\n");
}

void menu() //��Ϸ�˵� 
{
	printf("******************************\n");
	printf("*******1.play     0.exit******\n");
	printf("******************************\n");
}

void initMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column, char symbols) //��ʼ������
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

void putMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], int mineNumber, int x, int y) //����
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

void init(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]) //��ʼ��ģ��
{
	initMineBoard(faceMineBoard, OUT_ROW, OUT_COLUMN, '*'); //��ʼ��������
	initMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN, '0'); //��ʼ��������
}

void printMineBoard(char faceMineBoard[OUT_ROW][OUT_COLUMN], int row, int column) //��ӡ����
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

void statisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //��ɨ�������׸����з�����Χ����֮��
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

int newStatisticsAround(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //������������֮�Ͳ�����
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

void openBoard(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int x, int y) //չ��ģ��
{
	if (x >= 1 && x <= IN_ROW && y >= 1 && y <= IN_COLUMN)
	{
		if (newStatisticsAround(kernelMineBoard, faceMineBoard, x, y) != 0)
		{
			statisticsAround(kernelMineBoard, faceMineBoard, x, y);
		}
		else
		{
			if (faceMineBoard[x + 1][y + 1] == '*' || faceMineBoard[x + 1][y - 1] == '*' || faceMineBoard[x - 1][y + 1] == '*' || faceMineBoard[x - 1][y - 1] == '*') //��ֹ�ظ�չ��
			{
				faceMineBoard[x + 1][y + 1] = '0'; //�ԣ�x�� y������Ϊ����������չ��
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

int sweeperMine(char kernelMineBoard[OUT_ROW][OUT_COLUMN], char faceMineBoard[OUT_ROW][OUT_COLUMN], int* count2)//ɨ��
{
	int i, j;

	printf("����������(�ո����)\n");
	while (1)
	{
		scanf("%d %d", &i, &j);

		if (faceMineBoard[i][j] == '*' && i > 0 && j > 0 && i <= IN_ROW && j <= IN_COLUMN)
		{
			if (*count2 == 1)
			{
				putMine(kernelMineBoard, MINE_NUMBER, i, j); //����
				(*count2)++;
			}
			if (kernelMineBoard[i][j] == '0')
			{
				statisticsAround(kernelMineBoard, faceMineBoard, i, j); //��ɨ�������׸����з�����Χ����֮��
				openBoard(kernelMineBoard, faceMineBoard, i, j); //�ſ����� �ݹ�

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
			printf("���������ų������곬�����̷�Χ������������\n");
		}
	}
}

void isWin(char faceMineBoard[OUT_ROW][OUT_COLUMN], int* p) //�ж�ʤ��
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

void game(char faceMineBoard[OUT_ROW][OUT_COLUMN], char kernelMineBoard[OUT_ROW][OUT_COLUMN]) //��Ϸģ��
{
	int result;
	int count1 = 0; //����faceMineBoard��*������ �����ж�ʤ��
	int count2 = 1; //ʵ�ֵ�һ�β������

	do
	{
		printMineBoard(faceMineBoard, OUT_ROW, OUT_COLUMN); //��ӡ����
		result = sweeperMine(kernelMineBoard, faceMineBoard, &count2); //ɨ��

		count1 = 0;
		isWin(faceMineBoard, &count1); //�ж�ʤ��

		if (result == 0)
		{
			printMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN); //��ӡ����
			printf("�㱻ը�����Ƿ������0 or 1��>:");
		}

		if (count1 == MINE_NUMBER)
		{
			printMineBoard(kernelMineBoard, OUT_ROW, OUT_COLUMN); //��ӡ����
			printf("��Ӯ�ˣ��Ƿ������0 or 1��>:");
			break;
		}
	} while (result);
}