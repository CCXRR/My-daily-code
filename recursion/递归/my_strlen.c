#define _CRT_SECURE_NO_WARNINGS 1
int my_strlen(char* p)
{
	if (*p == '\0') {
		return 0;
	}
	else
	{
		return (my_strlen(p + 1) + 1);
	}
}