#include <stdio.h>

long long power(int base, int exp)
{
	long long res = 1LL;
	for (int i = 1; i <= exp; ++i) {
		res *= base;
	}
	return res;
}

int main(void)
{
	//int re = power(2, 3);
	//printf("2 to power of 3: %d\n", re);
	
	for (int i = 0; i <= 32; ++i) {
		long long result = power(2, i);
		printf("2 to power of %d: %lld\n", i, result);
	}
	
	return 0;
}
