#include <stdio.h>

int main(void)
{
	int score;
	
	printf("Enter score: ");
	scanf("%d", &score);
	
	if (score >= 90) {
		printf("%d is an A\n", score);
	} else if (score >= 80) {
		printf("%d is a B\n", score);
	} else if (score >= 70) {
		printf("%d is a C\n", score);
	} else if (score >= 60) {
		printf("%d is a D\n", score);
	} else {
		printf("%d is an F\n", score);
	}
	
	
	return 0;
}
