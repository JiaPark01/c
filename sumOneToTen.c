#include <stdio.h>

int main(void)
{
	int sum = 0, i = 1;
	
	while (i <= 10) {
		sum += i;
		i++;
	}
	
	printf("Sum [1, 10]: %d\n", sum);
	
	return 0;
}
