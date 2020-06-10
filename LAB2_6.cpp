#include <stdio.h>

void phase_6(int a[7])
{
	int rbx;
	int rsp;
	int rcx;

	int r12 = a[0];
	int r13 = a[0];
	int r14 = 0;
_48:
	int rbp = r13;
	int rax = &r13;
	

	rax -= 1; //read numbersÇÔ¼ö

	r14 += 1;
	if (r14 == 7)
		goto _111;

	rbx = r14;

	while (1) {
		rax = rbx;
		rax = 4 * rax + rsp;

		if (rax == rsp)
			//explode;
			;

		rbx += 1;

		if (rbx > 6)
			break;
	}

	r13 += 4;

	goto _48;
	rcx = &rsp + 0x1c;


_111:


	
}