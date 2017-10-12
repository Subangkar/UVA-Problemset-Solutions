#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define R 1
#define B 3

#define oposColor(clr) (clr == R ? B : R)
#define clearQueue() while (!q.empty()) q.pop()

queue<int> q;


bool bfs(int src, vector<int> node[], int color[])
{
	q.pop();

	for (vector<int>::iterator it = node[src].begin(); it != node[src].end(); ++it)
	{
		if (color[src] == color[*it]) return false;

		if (!color[*it])
		{
			color[*it] = oposColor(color[src]);
			q.push(*it);
		}
	}

	if (q.empty()) return true;

	return bfs(q.front(), node, color);
}


int main()
{
	int n = 0, edgNo = 0;
	int a = 0, b = 0;
	while (cin >> n, n != 0)
	{
		cin >> edgNo;

		vector<int> node[n];// = new vector<int>

		int color[200] = { R,0 };

		for (int i = 0; i < edgNo; ++i)
		{
			cin >> a >> b;

			node[a].push_back(b);
			node[b].push_back(a);
		}

		q.push(0);
		cout << (bfs(0, node, color) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;

		clearQueue();
//		delete[] node;
	}

	return 0;
}
