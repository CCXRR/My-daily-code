//数组交换；二分法查找；
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* p1, int* p2)
{
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int binary_search(int arr1[], int num1, int sz)
{
	int ret = -1;
	int left, right, mid;
	left = 0;
	right = sz - 1;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (arr1[mid] > num1) {
			right = mid - 1;
		}
		else if (arr1[mid] < num1) {
			left = mid + 1;
		}
		else
		{
			ret = mid;
			break;
		}
	}
	return ret;
}

int main()
{
	int a, b;
	int num1;
	int sz;
	int ret;     //0  1  2  3  4  5   6   7   8
	int arr1[] = { 1, 2, 3, 4, 6, 12, 15, 26, 28 };

	scanf("%d%d", &a, &b);
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	scanf("%d", &num1);
	sz = sizeof(arr1) / sizeof(arr1[0]);
	ret = binary_search(arr1, num1, sz);
	if (ret == -1) {
		printf("没有这个数\n");
	}
	else {
		printf("%d", ret);
	}

	return 0;
}