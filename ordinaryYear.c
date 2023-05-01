#include <stdio.h>

int main(void)
{
	int year, isOrd;
	
	printf("Enter year: ");
	scanf("%d", &year);
	
	//isOrd = !(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	isOrd = year % 4 != 0 || year % 100 == 0 && year % 400 != 0;
	
	printf("Year: %d\tisOrd: %d\n", year, isOrd);
	
	return 0;
}
