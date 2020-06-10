#include <stdio.h>
#include <Windows.h>

int int_16()
{
	int set_msb = 1 << 15 << 15 << 1; //16비트 머신에서 1을 15번 쉬프트시켜 32786을 만듬. 그 후 16번 더 쉬프트시켜 32비트 머신에서도 동작 가능하게 코딩.
	int beyond_msb = set_msb << 1; //set_msb에서 한번 더 쉬프트하면 beyond_msb는 0이됨

	return set_msb && !beyond_msb; //16비트 머신, 또는 32비트 머신이면 1을 반환, 아니면 0을 반환
}

int main()
{
	if (int_16())
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return  0;
}