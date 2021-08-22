//--递归的使用练习--
//1. 接受一个整型值（无符号），按照顺序打印它的每一位。例如：输入：1234，输出 1 2 3 4.
//2. 求数组前n项的最大值
//3. 编写函数不允许创建临时变量，求字符串长度
//4. 求n的阶乘。（不考虑溢出）
//5. 求斐波那契数(fibonacci)（不考虑溢出）
//6. 求汉诺塔（Tower of Hanoi）
//7. 青蛙跳台阶 有n个台阶，青蛙一次可以跳1个台阶，也可以跳两个台阶，青蛙跳到n个台阶有多少种跳法。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "recursion.h"

int main()
{
	{//1. 接受一个整型值（无符号），按照顺序打印它的每一位。例如：输入：1234，输出 1 2 3 4.
		int a;

		scanf("%d", &a);
		print(a);

		return 0;
	}

	{//2. 求数组前n项的最大值
					 0  1  2  3  4   5   6   7   8 
		int arr1[] = { 8, 9, 1, 3, 23, 15, 16, 27, 33 }; //array	数组
		int n;
		int max;
		scanf("%d", &n);
		max = max(arr1, n);
		printf("最大值为:>%d\n", max);
		return 0;
	}

	{//3. 编写函数不允许创建临时变量，求字符串长度
		int length;
		char arr1[] = "interesting";

		length = my_strlen(arr1);
		printf("%d\n", length);
		return 0;
	}

	{//4. 求n的阶乘。（不考虑溢出）
		int n;
		int fac;				//factorial		阶乘

		scanf("%d", &n);
		fac = fac(n);
		printf("%d\n", fac);

		return 0;
	}

	{//5. 求斐波那契数(fibonacci)（不考虑溢出）
		int n;
		int fib;

		scanf("%d", &n);
		fib = fib(n);
		printf("%d\n", fib);

		return 0;
	}

	{//6. 求汉诺塔（Tower of Hanoi）
		int layer;
		int count = 0;
		
		scanf("%d", &layer);
		Hanoi(layer, 'A', 'B', 'C', &count);
		printf("共移动%d次\n", count);

		return 0;
	}

	{//7. 青蛙跳台阶
		int step;
		int count = 0;

		scanf("%d", &step);
		count = Frog(step, &count);
		printf("%d", count);

		return 0;
	}
}
