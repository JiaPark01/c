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
		if (a > c) {
			max = 'a';
			if (b > c) {
				mid = 'b';
				min = 'c';
			} else {
				mid = 'c';
				min = 'b';
			}
		} else {
			max = 'c';
			mid = 'a';
			min = 'b';
		}
	} else {
		if (a > c) {
			max = 'b';
			mid = 'a';
			min = 'c';
		} else {
			min = 'a';
			if (b > c) {
				max = 'b';
				mid = 'c';
			} else {
				max = 'c';
				mid = 'b';
			}
		}
	}
	
	printf("Max: %c\nMid: %c\nMin: %c\n", max, mid, min);
	
	return 0;
}
