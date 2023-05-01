long long power(int base, int exp)	// func definition
{
	long long res = 1LL;
	for (int i = 1; i <= exp; ++i) {
		res *= base;
	}
	return res;
}

