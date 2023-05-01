#include <stdio.h>

int main(void)
{
	int num, result;
	
	printf("Enter number: ");
	scanf("%d", &num);
	
	if (num >= 0) {
		result = num;
	} else {
		result = -num;
	}
	
	printf("Absolute value of %d: %d\n", num, result);
	
	return 0;
}
