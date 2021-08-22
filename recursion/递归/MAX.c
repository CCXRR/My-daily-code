#define _CRT_SECURE_NO_WARNINGS 1

int MAX(int arr1[], int n)
{
	int max;
	if (n == 0) {
		max = arr1[0];
		return max;
	}
	else if (MAX(arr1, n - 1) < arr1[n]) {
		max = arr1[n];
		return max;
	}
}