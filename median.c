#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2)
{
	int left = *(int*)p1;
	int right = *(int*)p2;
	
	if (left > right)
		return 1;
	else if (left == right)
		return 0;
	else return -1;
	
}

int median(const int* pArr, int size)
{
	int *pNums = malloc(sizeof(int) * size);
	
	for (int i = 0; i < size; ++i) {
		pNums[i] = pArr[i];
	}
	
	// sort by qsort()
	qsort(pNums, size, sizeof(int), compare);
	
	/*
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (pNums[j] > pNums[j+1]) {
				int temp = pNums[j];
				pNums[j] = pNums[j+1];
				pNums[j+1] = temp;
			}
		}
	}
	*/
	
	int median = (size % 2) ? median = pNums[size/2] : (pNums[size/2-1] + pNums[size/2]) / 2;
	
	/*
	int median = 0;
	
	if (size % 2) median = pNums[size/2];
	else {
		median = (pNums[size/2-1] + pNums[size/2]) / 2;
	}
	*/
	free(pNums);
	
	return median;
}

int main(void)
{
	int nums[] = {30, 50, 90, 100, 10, 20, 40, 70, 80, 60};
	
	int result = median(nums, 10);
	printf("median : %d\n", result);
	
	int nums2[] = {2, 3, 1};
	result = median(nums2, 3);
	printf("median : %d\n", result);
	
	int nums3[] = {4, 2};
	result = median(nums3, 2);
	printf("median : %d\n", result);
	
	return 0;
}
