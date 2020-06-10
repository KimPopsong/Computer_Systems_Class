#include <stdio.h>
#include <Windows.h>

int any_odd_one(unsigned x)
{
	unsigned check = 0xAAAAAAAA; //10101010... -> 홀수자리가 1

	if ((0xAAAAAAAA & x) == 0) //x와 Check를 &연산해서 홀수비트가 1인지 검사. 1이 있다면 1을 반환.
		return 1;

	else
		return 0;
}

int main()
{
	unsigned t;

	scanf("%x", &t); //t입력

	if (any_odd_one(t))
		printf("1\n");

	else
		printf("0\n");

	system("pause");
	return 0;
}