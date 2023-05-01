#include <stdio.h>
#define MAX 10

int main(void) {
	int nums[MAX] = {50, 30, 100, 10, 20, 90, 80, 40, 60, 70};
	int temp;
	
	for (int i = 0; i < MAX - 1; ++i) {
		for (int j = i + 1; j < MAX; ++j) {
			if (nums[i] > nums[j]) {
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", nums[i]);
	}
	
	printf("\n");
	
	return 0;
}
