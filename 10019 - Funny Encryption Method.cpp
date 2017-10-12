#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
	char num[5];
	int mdec=0, mhex=0x0;
	bitset<16> dec, hex;
//	int b1=0, b2=0;

	int t = 0;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", num);

		sscanf(num, "%d", &mdec);
		sscanf(num, "%x", &mhex);

		dec = mdec;
		hex = mhex;

		printf("%d %d\n", dec.count(), hex.count());
	}
	return 0;
}