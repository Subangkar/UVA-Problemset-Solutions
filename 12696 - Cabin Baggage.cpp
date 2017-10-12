#include<stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t, i, n;
	float a, b, c, d, s;
	//    scanf("%d",&t);
	cin >> t;
	n = 0;
	for (i = 0; i<t; i++)
	{
		//        scanf("%f %f %f %f",&a,&b,&c,&d);
		cin >> a >> b >> c >> d;
		s = a + b + c;
		if (a <= 56 && b <= 45 && c <= 25 && d <= 7)
		{
			printf("1\n");
			n++;
		}
		else if (s <= 125 && d <= 7)
		{
			printf("1\n");
			n++;
		}
		else printf("0\n");

	}
	printf("%d\n", n);

	return 0;
}
