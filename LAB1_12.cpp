#include <stdio.h>
#include <Windows.h>

int isPower2(int x)
{
	int t = x + ~0;
	printf("%#x\n", t);

	int sign = ((x >> 31) & 1) ^ !!x;

	printf("%#x\n", (x >> 31));
	printf("%#x\n", ((x >> 31) & 1));
	printf("%#x\n", ((x >> 31) & 1) ^ !!x);

	x = t & x;
	printf("%#x\n", x = t & x);

	return !x & sign;
}

int main()
{
	
	printf("%d\n\n", isPower2(0));
	printf("%d\n\n", isPower2(10));
	printf("%d\n\n", isPower2(8));
	printf("%d\n\n", isPower2(-1));
	printf("%d\n\n", isPower2(-8));

	system("pause");
	return 0;
}