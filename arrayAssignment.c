#include <stdio.h>

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int nums2[5];
	
	for (int i = 0; i < 5; ++i) {
		nums2[i] = nums[i];
		printf("%d ", nums2[i]);
	}
	
	return 0;
}
