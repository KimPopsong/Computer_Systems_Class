#include <stdio.h>
#include <assert.h>
#include <windows.h.>

int threefourths(int x) //비트수준 연산 o
{
	int is_neg = x & INT_MIN;

	int fir_30, last_2; //상위2~31번째 비트, 0~1번째 비트
	fir_30 = x & (~0x3); // 0~1번재 비트를 버림
	last_2 = x & 0x3; //0~1번째를 제외한 나머지 비트를 버림

	fir_30 = fir_30 >> 2; //4로 나눔, 소숫점으로 버림 발생 x
	last_2 = last_2 + last_2 + last_2; //alst_2를 세번 더함 (x3), 오버플로우 발생 x

	fir_30 = fir_30 + fir_30 + fir_30; //fir_30을 세번 더해줌 (x3)

	int bias = (1 << 2) - 1;
	(is_neg && (last_2 += bias));

	last_2 = last_2 >> 2; //4로 나눔

	return fir_30 + last_2; //수를 더함
}

int main()
{
	assert(threefourths(8) == 6);
	assert(threefourths(9) == 6);
	assert(threefourths(10) == 7);
	assert(threefourths(11) == 8);
	assert(threefourths(12) == 9);
	assert(threefourths(-8) == -6);
	assert(threefourths(-9) == -6);
	assert(threefourths(-10) == -7);
	assert(threefourths(-11) == -8);
	assert(threefourths(-12) == -9);

	return 0;
}