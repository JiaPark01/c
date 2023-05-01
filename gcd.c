#include <stdio.h>

int getGCD(int a, int b)
{
	
	/*if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	*/
	
	int remainder = 0;
	
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	
	return a;
}

int main(void)
{
	int a, b;
	
	printf("Enter 2 numbers: ");
	scanf("%d %d", &a, &b);
	
	int re = getGCD(a, b);
	
	printf("GCD of %d and %d: %d\n", a, b, re);
		
	return 0;
}
