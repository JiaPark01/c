#include <stdio.h>

#define SQUARE(i) ((i) * (i))

int square(int i )
{
	return i * i;
}

int main(void)
{
	int i = 10;
	//int result = square(i);
	int result = SQUARE(i);		// int result = ((i) * (i))
	
	result = square(++i);		// 11 * 11
	result = SQUARE(++i);		// 11 * 12 or 12 * 11
	
	printf("result : %d\n", result);
	
	return 0;
}
