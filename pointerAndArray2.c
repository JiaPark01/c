#include <stdio.h>

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int* p;
	
	p = nums;
	
	printf("Array in array form\n");
	for (int i = 0; i < 5; ++i) {
		printf("nums[%d]: %d\n", i, nums[i]);
	}
	
	printf("\nArray in pointer form\n");
	
	for (int i = 0; i < 5; ++i) {
		printf("*(nums + %d): %d\n", i, *(nums + i));
	}
	
	printf("\nPointer in pointer form\n");
	
	for (int i = 0; i < 5; ++i) {
		printf("*(p + %d): %d\n", i, *(p + i));
	}
	
	printf("\nPointer in array form\n");
	
	for (int i = 0; i < 5; ++i) {
		printf("p[%d]: %d\n", i, p[i]);
	}
	
	return 0;
}
