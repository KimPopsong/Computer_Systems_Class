#include <stdio.h>
#include <Windows.h>

unsigned float_abs(unsigned uf) {
	unsigned t = uf & 0x7FFFFFFF;
	if (t > 0x7F800000) return uf;
	else return t;
}

int main()
{
	unsigned uf = 0xFFFFFFFF;

	printf("%#x\n", float_abs(uf));

	system("pause");
	return 0;
}