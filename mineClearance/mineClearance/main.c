#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main() //����
{				 
	int choice = 0;  //ѡ���Ƿ������Ϸ���0��1
	char faceMineBoard[OUT_ROW][OUT_COLUMN]; //��������� Ϊ��ӡ���������鿴������
	char kernelMineBoard[OUT_ROW][OUT_COLUMN]; //���������� Ϊ�ڲ������λ�����ݵ�����
	
	srand((unsigned)time(NULL)); //���������

	headline(); //�����

	do
	{
		init(faceMineBoard, kernelMineBoard); //��ʼ��ģ��
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
			printf("����������1��0\n");
			break;
		}
	} while (choice);
}