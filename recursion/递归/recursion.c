//--�ݹ��ʹ����ϰ--
//1. ����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�����磺���룺1234����� 1 2 3 4.
//2. ������ǰn������ֵ
//3. ��д��������������ʱ���������ַ�������
//4. ��n�Ľ׳ˡ��������������
//5. ��쳲�������(fibonacci)�������������
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "recursion.h"

int main()
{
	{//1. ����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�����磺���룺1234����� 1 2 3 4.
		int a;

		scanf("%d", &a);
		print(a);

		return 0;
	}

	{//2. ������ǰn������ֵ
					 //0  1  2  3  4   5   6   7   8 
		int arr1[] = { 8, 9, 1, 3, 23, 15, 16, 27, 33 }; //array	����
		int n;
		int max;
		scanf("%d", &n);
		max = MAX(arr1, n);
		printf("���ֵΪ:>%d\n", max);
		return 0;
	}

	{//3. ��д��������������ʱ���������ַ�������
		int length;
		char arr1[] = "interesting";

		length = my_strlen(arr1);
		printf("%d\n", length);
		return 0;
	}

	{//4. ��n�Ľ׳ˡ��������������
		int n;
		int fac;				//factorial		�׳�

		scanf("%d", &n);
		fac = Fac(n);
		printf("%d\n", fac);

		return 0;
	}

	{//5. ��쳲�������(fibonacci)�������������
		int n;
		int fib;

		scanf("%d", &n);
		fib = Fib(n);
		printf("%d\n", fib);

		return 0;
	}
}