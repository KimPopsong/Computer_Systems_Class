#include <stdio.h>
#include <Windows.h>

int int_16()
{
	int set_msb = 1 << 15 << 15 << 1; //16��Ʈ �ӽſ��� 1�� 15�� ����Ʈ���� 32786�� ����. �� �� 16�� �� ����Ʈ���� 32��Ʈ �ӽſ����� ���� �����ϰ� �ڵ�.
	int beyond_msb = set_msb << 1; //set_msb���� �ѹ� �� ����Ʈ�ϸ� beyond_msb�� 0�̵�

	return set_msb && !beyond_msb; //16��Ʈ �ӽ�, �Ǵ� 32��Ʈ �ӽ��̸� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
}

int main()
{
	if (int_16())
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return  0;
}