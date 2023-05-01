#include <stdio.h>
#define NUM 3

int main(void)
{
	int kor, eng, math, sum;
	double avg;
	
	printf("Enter the scores of Korean, English, Maths: ");
	scanf("%d %d %d", &kor, &eng, &math);
	
	sum = kor + eng + math;
	avg = (double)sum / NUM;
	
	printf("Sum: %d\nAverage: %.2lf\n", sum, avg);
	
	return 0;
}
