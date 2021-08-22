#define _CRT_SECURE_NO_WARNINGS 1
//循环解决
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 2;
//
//	while (n != 3)
//	{
//		a = b;
//		b = c;
//		c = a + b;
//		n--;
//	}
//
//	return c;
//}

//递归解决
int Fib(int n)
{
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return (Fib(n - 1) + Fib(n - 2));
	}

}