#include <stdio.h>

int main(void)
{
	int a, b, temp;
	
	a = 100;
	b = 200;
	
	printf("a: %d\tb:%d\n", a, b);
	
	temp = a;
	a = b;
	b = temp;
	
	printf("a: %d\tb:%d\n", a, b);
	
	return 0;
}
