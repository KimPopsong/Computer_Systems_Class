#include <stdio.h>

int upperBits(int n)
{
	n = (!!n << 31) >> (n + ~0);

	return n;
}

int main()
{
	printf("%#x\n", upperBits(1));

	return 0;
}