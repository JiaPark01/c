#include <stdio.h>

int main(void)
{
	int num;
	
	printf("Enter number: ");
	scanf("%d", &num);
	
	if (num < 0) {
		num = -num;
	}
	
	printf("Absolute value: %d\n", num);
	
	return 0;
}
