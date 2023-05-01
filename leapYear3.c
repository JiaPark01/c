#include <stdio.h>

int main(void)
{
	int year;
	
	printf("Enter year: ");
	scanf("%d", &year);
	
	/*
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
	//if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		printf("%d is a leap year\n", year);
	} else {
		printf("%d is an ordinary year\n", year);
	}
	*/
	
	printf("%d is a%s\n", year,
		(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? " leap year" : "n ordinary year");
	
	return 0;
}
