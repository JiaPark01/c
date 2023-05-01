#include <stdio.h>
#define MAX 10

int main(void) {
	int nums[MAX] = {50, 30, 100, 10, 20, 90, 80, 40, 60, 70};
	int sum = 0, value, i;
	
	printf("Enter value to find: ");
	scanf("%d", &value);
	
	for (i = 0; i < MAX; ++i) {
		if (nums[i] == value) {
			break;
		}
	}
	
	if (i < MAX) {
		printf("%d found\tIndex: %d\n", value, i);
	} else printf("%d not found\n", value);
	
	return 0;
}
