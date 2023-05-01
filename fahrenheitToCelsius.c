#include <stdio.h>

int main(void)
{
	int fahr;
	int celsius;
	
	fahr = 100;
	
	celsius = (fahr - 32) * 5 / 9;
	
	printf("%d degrees fahrenheit = %d degrees celsius\n", fahr, celsius);
	
	return 0;
}
