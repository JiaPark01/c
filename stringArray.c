#include <stdio.h>

void printStringArray1(char (*pArr)[20], int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%s\n", pArr[i]);		// &pArr[i][0]
	}
	printf("\n");
}

void printStringArray2(char **cities, int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%s\n", cities[i]); 
	}
	printf("\n");
}


int main(void)
{
	// for editing (makes a copy)
	char cities1[][20] = {
		"Seoul", "Los Angeles", "Paris", "Rio de Janeiro", "Moscow"
	};
	
	
	// for printing-only
	char *cities2[] = {
		"Seoul", "Los Angeles", "Paris", "Rio de Janeiro", "Moscow"
	};
	
	printStringArray1(cities1, 5);
	printStringArray2(cities2, 5);
	
	return 0;
}
