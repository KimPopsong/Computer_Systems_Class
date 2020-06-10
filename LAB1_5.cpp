#include <stdio.h>

int leftBitCount(int x) 
{
	int t = x;
	int res, s, i = !(~x);

	res = !(~(t >> 16)) << 4;

	t = t << res;
	s = !(~(t >> 24)) << 3;
	t = t << s;
	res = res | s;

	s = !(~(t >> 28)) << 2;
	t = t << s;
	res = res | s;

	s = !(~(t >> 30)) << 1;
	t = t << s;
	res = res | s;

	res = res ^ (1 & ((t >> 31)));

	return res + i;
}

int main()
{
	printf("%d\n", leftBitCount(0xFFFFFFFF));
	printf("%d\n", leftBitCount(0));
	printf("%d\n", leftBitCount(-31));
	printf("%d\n", leftBitCount(0x1000));
}