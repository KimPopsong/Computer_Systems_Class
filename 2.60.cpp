#include <stdio.h>
#include <Windows.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	unsigned del = ((unsigned)0xFF) << (i << 3); //AB로 대체할 부분을 0xFF로 채움
	unsigned replace = ((unsigned)b) << (i << 3); //AB를 대체할 위치로 이동

	unsigned deleted = x & ~del; //~del로 대체할 부분을 0으로 초기화 ( 나머지는 1) 그리고 & 연산

	unsigned finish = deleted | replace; //|연산으로 합해줌

	return finish;
}

int main()
{
	printf("%#x\n", replace_byte(0x12345678, 2, 0xAB));
	printf("%#x\n", replace_byte(0x12345678, 0, 0xAB));

	system("pause");
	return 0;
}