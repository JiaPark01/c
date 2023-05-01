#include <stdio.h>

int main(void)
{
	int year, isLeap;
	
	printf("Enter year: ");
	scanf("%d", &year);
	
	isLeap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	
	printf("Year: %d\tisLeap: %d\n", year, isLeap);
	
	return 0;
}
