#include <iostream>

using namespace std;



int main()
{
	long long a=0, b=0;

	while (cin >> a >> b)
	{
		cout << ((a > b ? (a - b) : (b - a))) << endl;
	}

	return 0;
}
