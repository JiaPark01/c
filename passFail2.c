#include <stdio.h>

int main(void)
{
	int score;
	
	printf("Enter score: ");
	
	scanf("%d", &score);
	
	if (score >= 60) {
		printf("Score: %d\tPass\n", score);
	} else {
		printf("Score: %d\tFail\n", score);
	}
	
	return 0;
}
