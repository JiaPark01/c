#include <stdio.h>

int main(void)
{
	int score;
	int isPass;
	
	printf("Enter score: ");
	scanf("%d", &score);
	
	isPass = score >= 60;
	
	printf("Score: %d\tisPass: %d\n", score, isPass);
	
	return 0;
}
