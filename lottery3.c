#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int balls[45];
	
	for (int i = 0; i < 45; ++i) {
		balls[i] = i + 1;
	}
	
	srand(time(NULL));
	for (int i = 0; i < 1000000; ++i) {		
		int j = rand() % 45;
		int k = rand() % 45;
		
		int temp = balls[j];
		balls[j] = balls[k];
		balls[k] = temp;
	}
	
	for (int i = 0; i < 7; ++i) {
		printf("%d ", balls[i]);
	}
	printf("\n");
	
	return 0;
}
