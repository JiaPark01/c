#include <stdio.h>
#define MAX 10

int main(void) {
	int nums[MAX] = {50, 30, 100, 10, 20, 90, 80, 40, 60, 70}, sum = 0;
	
	for (int i = 0; i < MAX; ++i) {
		
		//scanf("%d", &nums[i]);
		sum += nums[i];
	}
	
	printf("Sum: %d\n", sum);
	
	sum = 0;
	
	for (int i = 0; i < MAX; ++i) {
		if (nums[i] <= 50) {
			sum += nums[i];
		}
	}
	
	printf("Sum: %d\n", sum);
	
	return 0;
}
