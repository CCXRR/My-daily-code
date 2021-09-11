//将参数字符串中的字符反向排列

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//无递归法
//void reverse_string(char arr[], int sz)
//{
//	int tmp;
//	int i = 0;
//	while (i < sz - i - 1)
//	{
//		tmp = arr[sz - i - 1];
//		arr[sz - i - 1] = arr[i];
//		arr[i] = tmp;
//		i++;
//	}
//}

// 递归法

void reverse_string2(char arr[])
{
	int i;
	char tmp;

	i = strlen(arr);
	tmp = arr[0];
	arr[0] = arr[i - 1];
	arr[i - 1] = '\0';  
	if (strlen(arr + 1) >= 2)      
	{
		reverse_string2(arr + 1);    
	}
	arr[i - 1] = tmp;
}

int main()
{
	char arr[] = "abcdef";
	//int sz;
	
	//sz = sizeof(arr) / sizeof(arr[0]) - 1;
	
	//reverse_string(arr, sz);

	reverse_string2(arr);

	printf("%s\n", arr);

	return 0;
}