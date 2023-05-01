#include "date.h"

int main(void)
{
	struct date today = {2023, 3, 6};
	struct date birthday;
	birthday.year = 2001;
	birthday.month = 3;
	birthday.day = 5;
	
	printDate(&today);
	printDate(&birthday);
	
	return 0;
}
