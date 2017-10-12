#include <iostream>

using namespace std;

unsigned long long revNum(unsigned long long n)
{
	long long revN = 0;
	
	while (n)
	{
		revN *= 10;
		revN += (n % 10);

		n /= 10;
	}

	return revN;
}

int main()
{
	int t = 0, cs = 0;
	unsigned long long n = 0, revN = 0;
	unsigned long long cycCnt = 0;

	cin >> t;

	while (cs++<t)
	{
		cin >> n;
		
		cycCnt = 1;
		revN = revNum(n);

		do
		{

			n += revN;

		} while (n != (revN = revNum(n)) && ++cycCnt);

		cout << cycCnt << " " << n << endl;
	}

	return 0;
}
