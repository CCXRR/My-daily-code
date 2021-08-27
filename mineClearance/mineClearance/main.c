#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main() //主体
{				 
	int choice = 0;  //选择是否进行游戏存放0或1
	char faceMineBoard[OUT_ROW][OUT_COLUMN]; //定义表雷盘 为打印供玩家游玩查看的棋盘
	char kernelMineBoard[OUT_ROW][OUT_COLUMN]; //定义里雷盘 为内部存放雷位置数据的棋盘
	
	srand((unsigned)time(NULL)); //随机数撒种

	headline(); //大标题

	do
	{
		init(faceMineBoard, kernelMineBoard); //初始化模块
		if (choice == 0)
		{
			menu();
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:
			game(faceMineBoard, kernelMineBoard);
			scanf("%d", &choice);
		case 0:
			break;
		default:
			printf("请输入整数1或0\n");
			break;
		}
	} while (choice);
}