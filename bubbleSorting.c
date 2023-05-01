#include <stdio.h>
#define MAX 10

int main(void) {
	int nums[MAX] = {50, 30, 100, 10, 20, 90, 80, 40, 60, 70};
	int temp;
	
	for (int i = MAX - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[j+1]) {
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
			for (int k = 0; k < MAX; ++k) {
				printf("%d ", nums[k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", nums[i]);
	}
	
	printf("\n");
	
	return 0;
}
