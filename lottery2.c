#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	
	int lottery[7];
	
	for (int i = 0; i < 7;) {
		lottery[i] = rand() % 45 + 1;
		
		int j;
		for (j = 0; j < i; ++j) {
			if (lottery[i] == lottery[j]) {
				break;
			}
		}
		
		if (j == 1) {
			++i;
		}
	}
	
	for (int i = 0; i < 7; ++i) {
		printf("%d ", lottery[i]);
	}
}
