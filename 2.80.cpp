#include <stdio.h>
#include <assert.h>
#include <windows.h.>

int threefourths(int x) //��Ʈ���� ���� o
{
	int is_neg = x & INT_MIN;

	int fir_30, last_2; //����2~31��° ��Ʈ, 0~1��° ��Ʈ
	fir_30 = x & (~0x3); // 0~1���� ��Ʈ�� ����
	last_2 = x & 0x3; //0~1��°�� ������ ������ ��Ʈ�� ����

	fir_30 = fir_30 >> 2; //4�� ����, �Ҽ������� ���� �߻� x
	last_2 = last_2 + last_2 + last_2; //alst_2�� ���� ���� (x3), �����÷ο� �߻� x

	fir_30 = fir_30 + fir_30 + fir_30; //fir_30�� ���� ������ (x3)

	int bias = (1 << 2) - 1;
	(is_neg && (last_2 += bias));

	last_2 = last_2 >> 2; //4�� ����

	return fir_30 + last_2; //���� ����
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