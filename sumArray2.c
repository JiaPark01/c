#include <stdio.h>

int sumArray(const int *pArr, int size)		//int sumArray(int pArr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += pArr[i];
	}
	
	return sum;
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	
	int sum;
	sum = sumArray(nums, 5);
	
	printf("Sum: %d\n", sum);
	
	return 0;
}
