#include <stdio.h>

int main(void)
{
	int score;
	char grade;
	
	printf("Enter score: ");
	scanf("%d", &score);
	
	switch (score / 10) {
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
	}
	
	printf("Score: %d\tGrade: %c\n", score, grade);
	
	return 0;
}
