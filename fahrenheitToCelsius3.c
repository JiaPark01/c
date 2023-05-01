#include <stdio.h>

int main(void)
{
	int fahr;
	int celsius;
	int celsiusDec;
	int celsius1000;
	
	fahr = 100;
	//celsius = (fahr - 32) * 5 / 9;
	// celsiusDec = (((fahr - 32) * 5000 / 9 - ((fahr - 32) * 5 / 9 * 1000)) + 5) / 10;
	celsius1000 = 1000 * 5 * (fahr - 32) / 9;
	celsius = celsius1000 / 1000;
	celsiusDec = (celsius1000 % 1000 + 5) / 10;
	
	printf("%d degrees fahrenheit = %d.%d degrees celsius\n", fahr, celsius, celsiusDec);
	
	return 0;
}
