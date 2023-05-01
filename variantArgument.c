#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...)
{
	va_list ap;
	va_start(ap, n);
	
	int sum = 0;
	
	for (int i = 1; i <= n; ++i) {
		int value = va_arg(ap, int);		// give type for generic prgm
		sum += value;
	}
	
	va_end(ap);
	
	return sum;
}

int main(void)
{
	int result;
	result = sum(5, 1, 2, 3, 4, 5);
	printf("result : %d\n", result);
	
	result = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	printf("result : %d\n", result);
	
	return 0;
}
