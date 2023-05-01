#include <stdio.h>
#include "date.h"

void printDate(const struct date *pd)
{
	//printf("(%d/%02d/%02d)\n", (*pd).year, (*pd).month, (*pd).day);
	printf("(%d/%02d/%02d)\n", pd->year, pd->month, pd->day);
}
