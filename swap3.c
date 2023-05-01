#include <stdio.h>

int a, b;

int swap(void)
{
	int temp = a;
	a = b;
	b = temp;
	
	return 0;
}
int main(void)
{
	a = 100;
	b = 200;
	printf("a: %d\tb:%d\n", a, b);
	swap();
	printf("a: %d\tb:%d\n", a, b);
	
	return 0;
}
