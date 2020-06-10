//http://blog.scarboroughcoral.top/2019/02/12/csapp-lab-1/
#include <stdio.h>

int howManyBits(int x)
{
	int x16, x8, x4, x2, x1, x0;
	int sign = x >> 31;
	int cnt = 0;

	x = (sign & ~x) | (~sign & x);

	x16 = !!(x >> 16) << 4;
	x = x >> x16;
	cnt += x16;

	x8 = !!(x >> 8) << 3;
	x = x >> x8;
	cnt += x8;

	x4 = !!(x >> 4) << 2;
	x = x >> x4;
	cnt += x4;

	x2 = !!(x >> 2) << 1;
	x = x >> x2;
	cnt += x2;

	x1 = !!(x >> 1);
	x = x >> x1;
	cnt += x1;

	x0 = x;
	cnt += x0;

	return cnt + 1;
}

int main()
{
	printf("%d\n", howManyBits(12));
	printf("%d\n", howManyBits(298));
	printf("%d\n", howManyBits(-5));
	printf("%d\n", howManyBits(0));
	printf("%d\n", howManyBits(-1));
	printf("%d\n", howManyBits(0x80000000));

	return 0;
}