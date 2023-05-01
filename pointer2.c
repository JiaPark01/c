#include <stdio.h>

int main(void)
{
	int num;
	int nums[5];
	
	int* p = NULL;
	
	p = &num;
	*p = 10;
	
	p = &nums[1];
	*p = 100;
	
	printf("num: %d\tnum[1]: %d\n", num, nums[1]);
	
	return 0;
}
