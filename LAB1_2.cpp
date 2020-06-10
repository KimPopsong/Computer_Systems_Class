#include <stdio.h>

int byteSwap(int x, int n, int m)
{
	int a = (x >> (n << 3)) & 0xFF, b = (x >> (m << 3)) & 0xFF;
	int clear1 = 0xFF << (n << 3) | 0xFF << (m << 3);

	x = (x & ~clear1);
	x = (x | (a << (m << 3))) | (b << (n << 3));

	return x;
}

int main()
{
	int x = 0xDEADBEEF;
	int n = 1, m = 3;
	printf("%#x", byteSwap(x, n, m));

	return 0;
}