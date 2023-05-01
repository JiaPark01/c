#include <stdio.h>

int main(void)
{
	int scores[5], pass = 0, fail = 0;
	
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &scores[i]);
		
		if (scores[i] >= 60) {
			++pass;
		} else {
			++fail;
		}
	}
	
	printf("Num of passes: %d\tNum of fails: %d\n", pass, fail);
	
	return 0;
}
