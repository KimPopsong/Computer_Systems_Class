#include <stdio.h>
#include <Windows.h>

int isAsciiDigit(int x) {
	int a_0 = 0x30, a_9 = 0x39;

	printf("%#x\n", (x + ~a_0 + 1));
	printf("%#x\n", ((x + ~a_0 + 1) >> 31));
	printf("%#x\n", !((x + ~a_0 + 1) >> 31));
	printf("%#x\n", (x + ~a_9));
	printf("%#x\n", (x + ~a_9) >> 31);
	return !((x + ~a_0 + 1) >> 31) & (x + ~a_9) >> 31;
}
int main()
{
	printf("%d\n", isAsciiDigit(0x35));
	printf("\n");
	printf("%d\n", isAsciiDigit(0x3a));
	printf("\n");
	printf("%d\n", isAsciiDigit(0x2F));
	printf("\n");
	printf("%d\n", isAsciiDigit(-1000));
	printf("\n");
	printf("%d\n", isAsciiDigit(0xFFFFFFFF));
	printf("\n");

	system("pause");
	return 0;
}