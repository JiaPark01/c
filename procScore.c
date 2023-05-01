#include <stdio.h>

int main(void)
{
	int score[5], total = 0;
	double avg = 0;
	
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &score[i]);
		total += score[i];
	}
	
	avg = total / 5.0;
	
	printf("Total score: %d\tAverage: %.2lf\n", total, avg);
	
	return 0;
}
