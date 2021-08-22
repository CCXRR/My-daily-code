#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu(int choice) //菜单
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
		printf("还要继续吗？(1继续 0结束)>:");
	}
}

void game(char board[ROW][COLUMN]) //游戏主体
{
	int result;

	boardPrint(board);//打印棋盘
	do
	{
		playerMove(board);//玩家移动
		boardPrint(board);//打印棋盘
		result = victoryJudge(board);
		if (result == 1) {
			printf("你赢了\n");
			break;
		}
		else if (result == 0)
		{
			printf("你输了\n");
			break;
		}
		else if (result == -1)
		{
			printf("平局\n");
			break;
		}
		computerMove(board);//电脑移动
		boardPrint(board);//打印棋盘
		result = victoryJudge(board);//返回1 表示玩家获胜；返回0 表示电脑获胜； 返回-1 表示平局； 返回2 表示继续
		if (result == 1) {
			printf("你赢了\n");
			break;
		}
		else if (result == 0)
		{
			printf("你输了\n");
			break;
		}
		else if (result == -1)
		{
			printf("平局\n");
			break;
		}
	} while (1);
}

int victoryJudge(char board[ROW][COLUMN]) //判断胜负平局
										  //返回1 表示玩家获胜；返回0 表示电脑获胜； 返回-1 表示平局； 返回2 表示继续
{
	int i, j;
	int a, b, c;
	int playerRowCount, playerColumnCount, playerDiagonalCount1, playerDiagonalCount2/*, backslashplayerDiagonalCount1, backslashplayerDiagonalCount2*/;//玩家位三个方向计数器
	int computerRowCount, computerColumnCount, computerDiagonalCount1, computerDiagonalCount2/*, backslashcomputerDiagonalCount1, backslashcomputerDiagonalCount2*/; //电脑位三个方向计数器

	playerRowCount = playerColumnCount = playerDiagonalCount1 = playerDiagonalCount2 /*= backslashplayerDiagonalCount1 = backslashplayerDiagonalCount2*/ = 0;//初始化计数器
	computerRowCount = computerColumnCount = computerDiagonalCount1 = computerDiagonalCount2 /*= backslashcomputerDiagonalCount1 = backslashcomputerDiagonalCount2*/ = 0;//初始化计数器

	//判断横排和竖排
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
				if (board[i][j] == 'X')
					playerRowCount++;
					//玩家
	

				if (board[j][i] == 'X')
				{
					//玩家
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

				//玩家
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
					//电脑

				if (board[j][i] == 'O')
				{
					//电脑
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
				//	//电脑
				//	computerDiagonalCount++;
				//}

				if (computerRowCount == NUMBER || computerColumnCount == NUMBER || computerDiagonalCount1 == NUMBER || computerDiagonalCount2 == NUMBER)
				{
					return 0;
				}

				//电脑
				//if (board[i][j + 1] != 'O')
				//{
				//	computerRowCount = 0;
				//}
				//if (board[j + 1][i] != 'O')
				//{
				//	computerColumnCount = 0;
				//}
				
		}
		playerRowCount = playerColumnCount = playerDiagonalCount1 = playerDiagonalCount2 = 0;//初始化计数器
		computerRowCount = computerColumnCount = computerDiagonalCount1 = computerDiagonalCount2 = 0;//初始化计数器
	}
	//判断倾斜排
	//for (c = ROW; c > 0; c--)
	//{
	//	b = ROW - c;
	//	for (a = 0; a < c; a++, b++)
	//	{
	//		if (board[a][b] == 'X')
	//		{
	//			//玩家
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
	//				//玩家
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

int continueJudge(char board[ROW][COLUMN]) //通过判断棋盘是否下满来判断平局还是继续游戏
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

int occupyJudge(char board[ROW][COLUMN], int x, int y) //判断人和电脑落子位置是否合理
{
	int result = 0;//result = 0 被占用 result = 1 没占用 result = -1 超出范围

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

void playerMove(char board[ROW][COLUMN]) //玩家下棋
{
	int i, j;
	int result = 0;

	do
	{
		printf("请输入坐标 ->哪一行 哪一列(中间用空格隔开)>:");
		scanf("%d %d", &i, &j);
		result = occupyJudge(board, i, j);//棋位是否被占用判断
		if (result == 1)
		{
			board[i - 1][j - 1] = 'X';
			break;
		}
		else if (result == 0)
		{
			printf("你输入的坐标已被占用，请输入其他坐标\n");
		}
		else
		{
			printf("你输入的坐标超出范围，请输入范围内坐标\n");
		}
	} while (1);
}

void computerMove(char board[ROW][COLUMN]) //电脑下棋
{
	int i, j;
	int result = 0;

	do
	{
		i = rand() % ROW_MOVE_RANGE + 1;
		j = rand() % COLUMN_MOVE_RANGE + 1;
		result = occupyJudge(board, i, j);//棋位是否被占用判断
		if (result == 1)
		{
			board[i - 1][j - 1] = 'O';
			break;
		}
	} while (1);
}

void boardPrint(char board[ROW][COLUMN]) //打印棋盘
{
	int i, j;
	printf("\n");
	for (i = 0; i < ROW; i++) // 打印行上的每个棋格
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

