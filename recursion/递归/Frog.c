#define _CRT_SECURE_NO_WARNINGS 1
int Frog(int step)
{
	if (step == 1)
	{
		return 1;
	}
	else if (step == 2)
	{
		return 2;
	}
	else
	{
		return (Frog(step - 2) + Frog(step - 1));
	}
}
