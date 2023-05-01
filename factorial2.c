#include <stdio.h>

long long fac(int num)
{
	if (num == 1 ) return 1LL;
	else return (long long)num * fac(num - 1);
}

int main(void)
{
	for (int i = 1; i <= 100; ++i) {
		long long result = fac(i);
		printf("%d! : %lld\n", i, result);
	}
	
	return 0;
}
