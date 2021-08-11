#define _CRT_SECURE_NO_WARNINGS 1
int Fac(int n)
{
	if (n == 1)
		return 1;
	else
		return (Fac(n - 1) * n);
}