#include <cstdio>

int main()
{
	long long s = 0;
	int u = 0;
	int dt = 0;
	double a = 0;
	int v = 0;

	while (scanf("%d %d", &v, &dt) == 2)
	{
		if(dt) a = double(v - u) / dt; // a=const so get the 'a' from the first valuable data

		s = u * (2 * dt) + a * 2 * dt * dt;

		u = v;

		printf("%d\n", s);
	}

	return 0;
}
