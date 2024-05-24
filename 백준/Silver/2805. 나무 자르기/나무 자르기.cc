#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	priority_queue<long long> pq;

	// tree setting
	for (long long i = 0; i < N; i++)
	{
		int tree;
		cin >> tree;
		pq.push(tree);
	}

	long long height = 0, cnt = 0, length = 0;

	while (length < M)
	{
		height = pq.top();
		length += cnt;

		while (!pq.empty() && height == pq.top())
		{
			pq.pop();
			cnt++;

			// cout << height << " " << length << " " << cnt <<endl;
		}

		while (length < M && (pq.empty() || height - 1 > pq.top()))
		{
			height--;
			length += cnt;
			// cout << height << " " << length << " " << cnt <<endl;
		}
	}

	cout << height;
}