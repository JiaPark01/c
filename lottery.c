#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 7
#define LOT 45

int main(void)
{
	srand(time(NULL));
	
	int lottery[MAX];
	
	for (int i = 0; i < MAX; ++i) {
		lottery[i] = rand() % LOT + 1;
		int j = 0;
		while (j < i) {
			if (lottery[i] != lottery[j]) ++j;
			else {
				lottery[i] = rand() % LOT + 1;
				j = 0;
			}
		}
		
		if (i == MAX - 1) printf("Bonus: ");
		printf("%d ", lottery[i]);
	}
	
	printf("\n");
	
	return 0;
}
