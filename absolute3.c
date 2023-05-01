#include <stdio.h>

int main(void)
{
	int num;
	//int result;
	
	printf("Enter number: ");
	scanf("%d", &num);
	
	/*
	if (num >= 0) {
		result = num;
	} else {
		result = -num;
	}
	*/
	
	printf("Absolute value of %d: %d\n", num, (num >= 0) ? num : -num);
	
	return 0;
}
