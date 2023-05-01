#include <stdio.h>

int main(void)
{
	int fahr;
	int celsius1000;
	int celsiusDec;
	
	fahr = 100;
	celsius1000 = (fahr - 32) * 1000 * 5 / 9;
	celsiusDec = ((celsius1000 - celsius1000 / 1000 * 1000) + 5) / 10;
	
	printf("%d degrees fahrenheit = %d.%d degrees celsius\n", fahr, celsius1000 / 1000, celsiusDec);
	
	return 0;
}
