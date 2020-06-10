#include <stdio.h>
#include <assert.h>
#include <math.h>

float u2f(unsigned x) {
	return *(float*)& x;
}

float fpwr2(int x) {
	unsigned exp, frac;
	unsigned u;

	if (x < 2 - pow(2, 7) - 23) 
	{
		exp = 0;
		frac = 0;
	}

	else if (x < 2 - pow(2, 7)) 
	{
		exp = 0;
		frac = 1 << (unsigned)(x - (2 - pow(2, 7) - 23));
	}

	else if (x < pow(2, 7) - 1 + 1) 
	{
		exp = pow(2, 7) - 1 + x;
		frac = 0;
	}

	else 
	{
		exp = 0xFF;
		frac = 0;
	}

	u = exp << 23 | frac;

	return u2f(u);
}

int main() 
{
	printf("%f\n", fpwr2(0));
	printf("%f\n", fpwr2(5));
	printf("%f\n", fpwr2(100));
	printf("%f\n", fpwr2(-100));
	printf("%f\n", fpwr2(10000));
	printf("%f\n", fpwr2(-10000));
	
	return 0;
}