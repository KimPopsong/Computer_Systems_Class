#include <stdio.h>
#include <windows.h>

int main()
{
	int a = -2147483647 - 1U;
	int b = -1, c = 0U;
	unsigned int d = 0, e = -1;

	printf("%d\n", e);
	printf("%u\n", e);
	printf("%u\n", a);
	printf("%d\n", (-1 < 0U));
	printf("%d\n", b < d);
	printf("%d\n", (-2147483647 - 1 == 2147483648U)); //1
	printf("%d\n", (-2147483647 - 1 < 2147483647)); //2
	printf("%d\n", (-2147483647 - 1U < 2147483647)); //3
	printf("%d\n", (-2147483647 - 1 < -2147483647)); //4
	printf("%d\n", (-2147483647 - 1U < -2147483647)); //5
	printf("%d\n", (-2147483647 - 1U));
	printf("%u\n", (-2147483647 - 1U));
	printf("%d\n", (-2147483647));
	printf("%u\n", (-2147483647));
	return 0;
}