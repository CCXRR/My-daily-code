
/*
 _   _             _                    _             
| | (_)           | |                  | |            
| |_ _  ___ ______| |_ __ _  ___ ______| |_ ___   ___ 
| __| |/ __|______| __/ _` |/ __|______| __/ _ \ / _ \
| |_| | (__       | || (_| | (__       | || (_) |  __/
 \__|_|\___|       \__\__,_|\___|       \__\___/ \___|
*/

/* 
   |   |
---|---|---   棋盘示例
   |   |
---|---|---
   |   |         
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	int choice = 0;
	int i, j;//i 行 j 列
	char board[ROW][COLUMN] = { '0' };//如果二维数组在函数体外定义，系统会自动给它的全部元素都初始化为0。如果二维数组在函数体内定义，系统不会自动给它初始化。一维数组同理。 在数组中，部分初始化时，未被显式初始化的元素会被自动初始化为0。利用这个特性，可以用简单方法给二维数组全部初始化为0。 比如这样初始化：int birduu[3][2] = { 0 }; 数组 birduu 的元素值就全部是0了。（其实只是显式初始化第一个元素为0 ，其它元素会被自动初始化为0）。详细讲解见 biruu.com 的C语言在线参考手册。
	srand((unsigned)time(NULL));

	printf(" _   _             _                    _             \n");
	printf("| | (_)           | |                  | |            \n");
	printf("| |_ _  ___ ______| |_ __ _  ___ ______| |_ ___   ___ \n");
	printf("| __| |/ __|______| __/ _` |/ __|______| __/ _ \\ / _ \\\n");
	printf("| |_| | (__       | || (_| | (__       | || (_) |  __/\n");
	printf(" \\__|_|\\___|       \\__\\__,_|\\___|       \\__\\___/ \\___|\n");
	
	do
	{
		for (i = 0; i < ROW; i++) //初始化棋盘，没棋子的棋格以空格填充。
		{
			for (j = 0; j < COLUMN; j++)
			{
				board[i][j] = ' ';
			}
		}
		menu(choice);	//菜单
		scanf("%d", &choice);
		switch (choice) // 判断是否进入游戏
		{
		case 1:
			// 开始游戏
			game(board);
			break;
		case 0:
			break;
		default:
			printf("please input 0 or 1 \n");
		}
	} while (choice);
}