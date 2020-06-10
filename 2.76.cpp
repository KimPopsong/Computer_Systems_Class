#include <stdio.h>
#include <assert.h>
#include <Windows.h>

void* n_calloc(size_t nmemb, size_t size) //비트수준 연산 x
{
	if (nmemb == 0 || size == 0)
		return NULL;

	size_t check_of;

	check_of = nmemb * size;

	if (size = check_of / nmemb) //오버플로우 체크
	{
		void* ptr = malloc(check_of);
		memset(ptr, 0, check_of);
		return ptr;
	}

	else
		return NULL;
}

int main()
{
	void* p;

	p = n_calloc(0xFF, 1);

	if (p != NULL)
		printf("Not Overflow\n");

	else
		printf("Overflow\n");

	free(p);

	p = n_calloc(0xFFFFFFFFFFFFFFFF, 2);

	if (p != NULL)
		printf("Not Overflow\n");

	else
		printf("Overflow\n");

	free(p);
	
	return 0;
}