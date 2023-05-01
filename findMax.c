#include <stdio.h>

int findMax(const int *pArr, int size)
{
	int max = *pArr;
	for (int i = 1; i < size; ++i) {
		if (pArr[i] > max) max = pArr[i];
	}
	return max;
}

int main(void) {
	int nums[10] = {50, 30, 100, 10, 20, 90, 80, 40, 60, 70};
	
	int max = findMax(nums, 10);
	
	printf("Max: %d\n", max);
	
	return 0;
}
