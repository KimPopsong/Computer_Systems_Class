#include <stdio.h>
#include <Windows.h>

int tsub_ok(int x, int y) //��Ʈ���� ���� X
{
	if ((x < 0 && y > 0) || (x > 0 && y < 0)) //��ȣ�� �ٸ� ��
	{
		if ((x > y) && (x - y) < 0) //x�� ����϶�, x - y�� 0���� ������
		{
			return 0;
		}

		if ((y > x) && (y - x) < 0) //y�� ����϶�, y - x�� 0���� ������
		{
			return 0;
		}
	}

	else 
		return 1;
}

int main()
{
	if (tsub_ok(INT_MAX, INT_MIN))
		printf("1\n");

	else
		printf("0\n");

	return 0;
}