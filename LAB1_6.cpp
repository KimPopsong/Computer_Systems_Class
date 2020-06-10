#include <stdio.h>
#include <Windows.h>

int isTmin(int x)
{
	return !(x + x) & !!(x);
}

int main()
{
	printf("%d\n", isTmin(INT_MIN));
	return 0;
}