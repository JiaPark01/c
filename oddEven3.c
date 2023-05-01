#include <stdio.h>

int main(void)
{	
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	/*
	if (num % 2) {
		printf("%d is odd\n", num);
	} else {
		printf("%d is even\n", num);
	}
	*/
	
	printf("%d is an %s number\n", num, (num % 2) ? "odd" : "even");
	
	return 0;
}
