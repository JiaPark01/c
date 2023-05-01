#include <stdio.h>

int main(void)
{
	int base;
	int height;
	double area;
	
	/*
	printf("Enter base length: ");
	scanf("%d", &base);
	
	printf("\nEnter height: ");
	scanf("%d", &height);
	*/
	
	printf("Enter base length and height: ");
	scanf("%d %d", &base, &height);
	
	area = base * height / 2.0;
	
	printf("\nArea: %.1f\n", area);
	
	return 0;
}
