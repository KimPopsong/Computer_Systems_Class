#include <stdio.h>
#include <Windows.h>

int tsub_ok(int x, int y) //비트수준 연산 X
{
	if ((x < 0 && y > 0) || (x > 0 && y < 0)) //부호가 다를 때
	{
		if ((x > y) && (x - y) < 0) //x가 양수일때, x - y가 0보다 작으면
		{
			return 0;
		}

		if ((y > x) && (y - x) < 0) //y가 양수일때, y - x가 0보다 작으면
		{
			return 0;
		}
	}

	else 
		return 1;
}

int main()
{
	if (tsub_ok(INT_MAX, INT_MIN))
		printf("1\n");

	else
		printf("0\n");

	return 0;
}