#include <stdio.h>

int main(void)
{
	int celsius;
	double fahr;
	
	//celsius = 24;
	
	scanf("%d", &celsius);
	fahr = 9.0 / 5.0 * celsius + 32;
	
	printf("%d degrees celsius = %.2f degrees fahrenheit\n", celsius, fahr);
	return 0;
}
