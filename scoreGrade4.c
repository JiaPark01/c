#include <stdio.h>

int main(void)
{
	char grades[11] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
	
	int score;
	char grade;
	
	printf("Enter score: ");
	scanf("%d", &score);
	
	grade = grades[score / 10];
	
	printf("Score: %d\tGrade: %c\n", score, grade);
	
	return 0;
}
