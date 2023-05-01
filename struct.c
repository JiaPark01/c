#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

void printDate(struct date d)
{
	printf("(%d/%02d/%02d)\n", d.year, d.month, d.day);
}

int main(void)
{
	/*	
	
	int today_year = 2023;
	int today_month = 3;
	int today_day = 6;
	
	int birthday_year = 2005;
	int birthday_month = 8;
	int birthday_day = 2;
	
	int temp_year;
	int temp_month;
	int temp_day;
	temp_year = today_year;
	temp_month = today_month;
	temp_day = today_day;
	
	printDate(today_year, today_month, today_day);
	printDate(birthday_year, birthday_month, birthday_day);
	
	*/
	
	struct date today;
	today.year = 2023;
	today.month = 3;
	today.day = 6;
	
	struct date birthday = {2005, 8, 2};
	
	struct date temp;
	temp = today;				// at once
	
	printDate(today);
	printDate(birthday);
	
	return 0;
}
