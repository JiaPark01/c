#include <stdio.h>

long long fac(int num)
{
	long long res = 1LL;
	for (int i = 1; i <= num; ++i) {
		res *= i;
	}
	return res;
}

int main(void)
{
	for (int i = 1; i <= 100; ++i) {
		long long result = fac(i);
		printf("%d! : %lld\n", i, result);
	}
	
	return 0;
}
