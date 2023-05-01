#include <stdio.h>

int main(void)
{
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	if (num > 0) {
		printf("%d is a positive number\n", num);
	} else if (num == 0) {
		printf("%d is zero\n", num);
	} else {
		printf("%d is a negative number\n", num);
	}
	
	//printf("%d is %s\n", num,
		//(num > 0) ? "a positive number" : (num == 0) ? "zero" : "a negative number");
	
	return 0;
}
