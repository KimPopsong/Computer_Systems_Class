#include <stdio.h>
#include <assert.h>

long cread(long* xp) {
	printf("%d\n", !xp);
	printf("%d\n", xp);
	return (xp ? *xp : 0);
}

long cread_alt(long* xp) {
	printf("%d\n", !xp);
	printf("%d\n", xp);
	return (!xp ? 0 : *xp);
}

int main() {
	long a = 0;

	cread(NULL);
	cread_alt(NULL);
	//assert(cread(&a) == cread_alt(&a));
	//assert(cread(NULL) == cread(NULL));
	//assert(cread(NULL) == cread_alt(NULL));

	return 0;
}