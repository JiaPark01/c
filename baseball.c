#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	
	int question[3];
	int s = 0, b = 0, count = 0;
	
	for (int i = 0; i < 3; ++i) {
		question[i] = rand() % 9 + 1;
		int j = 0;
		while (j < i) {
			if (question[i] != question[j]) ++j;
			else {
				question[i] = rand() % 9 + 1;
				j = 0;
			}
		}
		printf("%d ", question[i]);
	}
	
	while (s != 3) {
		s = b = 0;
		int answer[3];
		
		printf("Enter 3 numbers: ");
		
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &answer[i]);
		}
		
		for (int i = 0; i < 3; ++i) {
			if (question[i] == answer[i]) {
				++s;
			} else {
				for (int j = 0; j < 3; ++j) {
					if (question[i] == answer[j]) {
					++b;
					}
				}
			}
		}
		printf("Strike: %d\tBall: %d\n\n", s, b);
		++count;
	}
	
	printf("Congratulations! Number of guesses: %d\n", count);
	
	return 0;
}
