#include <stdio.h>
#include <Windows.h>

unsigned float_half(unsigned uf)
{
	unsigned e = (uf >> 23) & 0xFF;
	unsigned f = (0x007FFFFF & uf);
	unsigned sign = 0x80000000 & uf;

	if (e == 0)
	{
		if ((f & 3) == 3)
			f += 1;

		f = f >> 1;
	}

	else if (e == 1)
	{
		if (f != 0x7FFFFF)
			e = 0;
		f = f | 0x800000;
	}

	else if (e == 0xFF)
		return uf;

	else
		e--;

	return sign | (e << 23) | f;
}

int main()
{
	printf("%.8X\n", 0x12345678);
	printf("%.8X\n", float_half(0x12345678));
	printf("%.8X\n", float_half(0xFF945678));

	system("pause");
	return 0;
}