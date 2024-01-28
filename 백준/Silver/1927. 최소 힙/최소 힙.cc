#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, x;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0)
			pq.push(x);
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
	}
}