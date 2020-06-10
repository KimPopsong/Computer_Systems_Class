#include <stdio.h>
#include <Windows.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	unsigned del = ((unsigned)0xFF) << (i << 3); //AB�� ��ü�� �κ��� 0xFF�� ä��
	unsigned replace = ((unsigned)b) << (i << 3); //AB�� ��ü�� ��ġ�� �̵�

	unsigned deleted = x & ~del; //~del�� ��ü�� �κ��� 0���� �ʱ�ȭ ( �������� 1) �׸��� & ����

	unsigned finish = deleted | replace; //|�������� ������

	return finish;
}

int main()
{
	printf("%#x\n", replace_byte(0x12345678, 2, 0xAB));
	printf("%#x\n", replace_byte(0x12345678, 0, 0xAB));

	system("pause");
	return 0;
}