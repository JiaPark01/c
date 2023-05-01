#include <stdio.h>

int main(void)
{
	int num, isOdd;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	isOdd = num % 2 == 1;
	
	printf("Number: %d\tisOdd: %d\n", num, isOdd);
	
	return 0;
}
