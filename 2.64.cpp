#include <stdio.h>
#include <Windows.h>

int any_odd_one(unsigned x)
{
	unsigned check = 0xAAAAAAAA; //10101010... -> Ȧ���ڸ��� 1

	if ((0xAAAAAAAA & x) == 0) //x�� Check�� &�����ؼ� Ȧ����Ʈ�� 1���� �˻�. 1�� �ִٸ� 1�� ��ȯ.
		return 1;

	else
		return 0;
}

int main()
{
	unsigned t;

	scanf("%x", &t); //t�Է�

	if (any_odd_one(t))
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return 0;
}