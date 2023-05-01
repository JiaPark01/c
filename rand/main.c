#include <stdio.h>
#include <time.h>
#include "rand.h"			// if already exists in lib, don't include

int main(void)
{
	/*
	int seed;
	my_srand(&seed, time(NULL));
	
	seed = 0;
	
	int num = rand(&seed);
	*/
	
	my_srand(time(NULL));
	
	for (int i = 1; i < 10; ++i) {
		int num = my_rand();
		
		printf("%d\n", num);
	}
	
	return 0;
}
