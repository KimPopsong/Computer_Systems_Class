#include <stdio.h>
#include <Windows.h>

int int_32() 
{
	int set_msb = 1 << 31; //1�� �������� 31�� ����Ʈ�ؼ� -2147483648�� ����
	int beyond_msb = set_msb << 1; //set_msb���� �ѹ� �� ����Ʈ�ϸ� beyond_msb�� 0�̵�

	return set_msb && !beyond_msb; //32��Ʈ �ӽ��̸� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
}

int main()
{
	if (int_32())
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return  0;
}