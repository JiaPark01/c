#include <stdio.h>

int main(void)
{
	int i = 100;
	double d = 3.14;
	
	void* p;
	
	p = &i;
	*(int *)p = 200;
	printf("i: %d\n", i);
	
	p = &d;
	*(double *)p = 5.24;
	printf("d: %lf\n", d);
	
	return 0;
}
