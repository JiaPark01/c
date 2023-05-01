#include <stdio.h>

int main(void)
{
	int fahr;
	double celsius;
	
	fahr = 100;
	celsius = (fahr - 32) * 5.0 / 9.0;
	
	printf("%d degrees fahrenheit = %.2f degrees celsius\n", fahr, celsius);
	
	return 0;
}
