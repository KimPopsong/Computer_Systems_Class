#include <stdio.h>
#include <Windows.h>

int int_32() 
{
	int set_msb = 1 << 31; //1을 왼쪽으로 31번 쉬프트해서 -2147483648을 만듬
	int beyond_msb = set_msb << 1; //set_msb에서 한번 더 쉬프트하면 beyond_msb는 0이됨

	return set_msb && !beyond_msb; //32비트 머신이면 1을 반환, 아니면 0을 반환
}

int main()
{
	if (int_32())
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return  0;
}