#include <cstdio>

int main()
{
	long long n = 0, r = 0;

	while (scanf("%lld", &n) && n >= 0)
	{
		r = 1 + ((n*(n + 1)) >> 1);
		printf("%lld\n", r);
	}

	return 0;
}