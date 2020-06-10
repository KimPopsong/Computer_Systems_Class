#include <stdio.h>
#include <Windows.h>

int float_f2i(unsigned uf) {
	unsigned e = (0x7F800000 & uf);
	unsigned f = 0x007FFFFF & uf;
	unsigned result = 0, b = 127;

	e = e >> 23;
	f = f | 0x00800000;

	if (e < b)
		return 0;

	else if (e >= 158)
		return 0x80000000u;

	else if (e > 148)
		result = f << (e - 150);

	else
		result = f >> (150 - e);

	if (0x80000000 & uf)
		return -result;

	else
		return result;
}

int main()
{
	printf("%d\n", float_f2i(0x4B000000));
	printf("%d\n", float_f2i(0x4A80FFFF));
	printf("%d\n", float_f2i(0x4B000000));

	system("pause");
	return 0;
}