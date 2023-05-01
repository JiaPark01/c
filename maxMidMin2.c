#include <stdio.h>

int main(void)
{
	int a, b, c;
	char max, mid, min;
	
	printf("Enter a value for a: ");
	scanf("%d", &a);
	printf("Enter a value for b: ");
	scanf("%d", &b);
	printf("Enter a value for c: ");
	scanf("%d", &c);
	
	if (a > b) {
		max = a;
		min = b;
	} else {
		max = b;
		min = a;
	}
	
	if (c > max) {
		mid = max;
		max = c;
	} else if (c > min) {
		mid = c;
	} else {
		mid = min;
		min = c;
	}
	
	printf("Max: %d\nMid: %d\nMin: %d\n", max, mid, min);
	
	return 0;
}
