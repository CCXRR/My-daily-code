#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu(int choice) //�˵�
{
	if (choice != 1)
	{
		printf("\t  *******************************\n");
		printf("\t  ***** 1.play       0.exit *****\n");
		printf("\t  *******************************\n");
		printf(">:");
	}
	else
	{
		printf("��Ҫ������(1���� 0����)>:");
	}
}

void game(char board[ROW][COLUMN]) //��Ϸ����
{
	int result;

	boardPrint(board);//��ӡ����
	do
	{
		playerMove(board);//����ƶ�
		boardPrint(board);//��ӡ����
		result = victoryJudge(board);
		if (result == 1) {
			printf("��Ӯ��\n");
			break;
		}
		else if (result == 0)
		{
			printf("������\n");
			break;
		}
		else if (result == -1)
		{
			printf("ƽ��\n");
			break;
		}
		computerMove(board);//�����ƶ�
		boardPrint(board);//��ӡ����
		result = victoryJudge(board);//����1 ��ʾ��һ�ʤ������0 ��ʾ���Ի�ʤ�� ����-1 ��ʾƽ�֣� ����2 ��ʾ����
		if (result == 1) {
			printf("��Ӯ��\n");
			break;
		}
		else if (result == 0)
		{
			printf("������\n");
			break;
		}
		else if (result == -1)
		{
			printf("ƽ��\n");
			break;
		}
	} while (1);
}

int victoryJudge(char board[ROW][COLUMN]) //�ж�ʤ��ƽ��
										  //����1 ��ʾ��һ�ʤ������0 ��ʾ���Ի�ʤ�� ����-1 ��ʾƽ�֣� ����2 ��ʾ����
{
	int i, j;
	int a, b, c;
	int playerRowCount, playerColumnCount, playerDiagonalCount1, playerDiagonalCount2/*, backslashplayerDiagonalCount1, backslashplayerDiagonalCount2*/;//���λ�������������
	int computerRowCount, computerColumnCount, computerDiagonalCount1, computerDiagonalCount2/*, backslashcomputerDiagonalCount1, backslashcomputerDiagonalCount2*/; //����λ�������������

	playerRowCount = playerColumnCount = playerDiagonalCount1 = playerDiagonalCount2 /*= backslashplayerDiagonalCount1 = backslashplayerDiagonalCount2*/ = 0;//��ʼ��������
	computerRowCount = computerColumnCount = computerDiagonalCount1 = computerDiagonalCount2 /*= backslashcomputerDiagonalCount1 = backslashcomputerDiagonalCount2*/ = 0;//��ʼ��������

	//�жϺ��ź�����
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
				if (board[i][j] == 'X')
					playerRowCount++;
					//���
	

				if (board[j][i] == 'X')
				{
					//���
					playerColumnCount++;
				}
				//if (board[i + 1][j + 1] == 'X')
				//{

				//}
				if (board[j][j] == 'X')
				{
					playerDiagonalCount1++;
				}

				if (board[j][ROW - j - 1] == 'X')
				{
					playerDiagonalCount2++;
				}

				if (playerRowCount == NUMBER || playerColumnCount == NUMBER || playerDiagonalCount1 == NUMBER || playerDiagonalCount2 == NUMBER)
				{
					return 1;
				}

				//���
				//if (i < ROW - 1)
				//{
				//	if (board[i][j + 1] != 'X')
				//	{
				//		playerRowCount = 0;
				//	}
				//	if (board[j + 1][i] != 'X')
				//	{
				//		playerColumnCount = 0;
				//	}
				//}
	
				if (board[i][j] == 'O')
					computerRowCount++;	
					//����

				if (board[j][i] == 'O')
				{
					//����
					computerColumnCount++;
				}
				if (board[j][j] == 'O')
				{
					computerDiagonalCount1++;
				}

				if (board[j][ROW - j - 1] == 'O')
				{
					computerDiagonalCount2++;
				}
				//if (board[i + 1][j + 1] == 'O')
				//{
				//	//����
				//	computerDiagonalCount++;
				//}

				if (computerRowCount == NUMBER || computerColumnCount == NUMBER || computerDiagonalCount1 == NUMBER || computerDiagonalCount2 == NUMBER)
				{
					return 0;
				}

				//����
				//if (board[i][j + 1] != 'O')
				//{
				//	computerRowCount = 0;
				//}
				//if (board[j + 1][i] != 'O')
				//{
				//	computerColumnCount = 0;
				//}
				
		}
		playerRowCount = playerColumnCount = playerDiagonalCount1 = playerDiagonalCount2 = 0;//��ʼ��������
		computerRowCount = computerColumnCount = computerDiagonalCount1 = computerDiagonalCount2 = 0;//��ʼ��������
	}
	//�ж���б��
	//for (c = ROW; c > 0; c--)
	//{
	//	b = ROW - c;
	//	for (a = 0; a < c; a++, b++)
	//	{
	//		if (board[a][b] == 'X')
	//		{
	//			//���
	//			playerDiagonalCount1++;
	//		}
	//		if (board[b][a] == 'X')
	//		{
	//			playerDiagonalCount2++;
	//		}
	//		if (board[a][c-1-b])
	//		{
	//			backslashplayerDiagonalCount1++;
	//		}
	//		if (board[a + ROW - c][ROW - b - 1])
	//		{
	//			backslashplayerDiagonalCount2++;
	//		}
	//		if (playerRowCount == NUMBER || playerColumnCount == NUMBER || playerDiagonalCount1 == NUMBER || playerDiagonalCount2 == NUMBER || backslashplayerDiagonalCount1 == NUMBER || backslashplayerDiagonalCount2 == NUMBER)
	//		{
	//			return 1;

	//		}
	//		if (a < (c - 1))
	//		{
	//			if (board[a + 1][b + 1] != 'X')
	//			{
	//				//���
	//				playerDiagonalCount1 = 0;
	//			}
	//			if (board[b + 1][a + 1] != 'X')
	//			{
	//				playerDiagonalCount2 = 0;
	//			}
	//			if (board[a + 1][c - 2 - b] != 'X')
	//			{
	//				backslashplayerDiagonalCount1 = 0;
	//			}
	//			if (board[a + ROW - c + 1][ROW - b - 1 - 1])
	//			{
	//				backslashplayerDiagonalCount2 = 0;
	//			}
	//		}
	//	}
	//}
	return continueJudge(board);
}

int continueJudge(char board[ROW][COLUMN]) //ͨ���ж������Ƿ��������ж�ƽ�ֻ��Ǽ�����Ϸ
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if (board[i][j] == ' ')
			{
				return 2;
			}
		}
	}
	return -1;
}

int occupyJudge(char board[ROW][COLUMN], int x, int y) //�ж��˺͵�������λ���Ƿ����
{
	int result = 0;//result = 0 ��ռ�� result = 1 ûռ�� result = -1 ������Χ

	if (x > ROW || y > COLUMN)
	{
		result = -1;
	}
	else if (board[x - 1][y - 1] == ' ')
	{
		result = 1;
	}

	return result;
}

void playerMove(char board[ROW][COLUMN]) //�������
{
	int i, j;
	int result = 0;

	do
	{
		printf("���������� ->��һ�� ��һ��(�м��ÿո����)>:");
		scanf("%d %d", &i, &j);
		result = occupyJudge(board, i, j);//��λ�Ƿ�ռ���ж�
		if (result == 1)
		{
			board[i - 1][j - 1] = 'X';
			break;
		}
		else if (result == 0)
		{
			printf("������������ѱ�ռ�ã���������������\n");
		}
		else
		{
			printf("����������곬����Χ�������뷶Χ������\n");
		}
	} while (1);
}

void computerMove(char board[ROW][COLUMN]) //��������
{
	int i, j;
	int result = 0;

	do
	{
		i = rand() % ROW_MOVE_RANGE + 1;
		j = rand() % COLUMN_MOVE_RANGE + 1;
		result = occupyJudge(board, i, j);//��λ�Ƿ�ռ���ж�
		if (result == 1)
		{
			board[i - 1][j - 1] = 'O';
			break;
		}
	} while (1);
}

void boardPrint(char board[ROW][COLUMN]) //��ӡ����
{
	int i, j;
	printf("\n");
	for (i = 0; i < ROW; i++) // ��ӡ���ϵ�ÿ�����
	{
			printf("\t\t   ");
		for (j = 0; j < COLUMN; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COLUMN - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
		{
			printf("\t\t   ");
			for (j = 0; j < COLUMN; j++)
			{
				printf("---");
				if (j < COLUMN - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

