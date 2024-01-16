#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
bool visited[MAX];
int pos[MAX];

void BFS(int N, int K)
{
	queue<int> q;
	visited[N] = true;
	q.push(N);

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		if (f - 1 >= 0 && !visited[f - 1])
		{
			visited[f - 1] = true;
			pos[f - 1] = pos[f] + 1;
			if (f - 1 == K)
				break;
			q.push(f - 1);
		}
		if (f + 1 < MAX && !visited[f + 1])
		{
			visited[f + 1] = true;
			pos[f + 1] = pos[f] + 1;
			if (f + 1 == K)
				break;
			q.push(f + 1);
		}
		if (f * 2 < MAX && !visited[f * 2])
		{
			visited[f * 2] = true;
			pos[f * 2] = pos[f] + 1;
			if (f * 2 == K)
				break;
			q.push(f * 2);
		}
	}
}

int main()
{
	int N, K;
	fill(&pos[0], &pos[MAX-1], 0);
	fill(&visited[0], &visited[MAX-1], false);

	cin >> N >> K;

	BFS(N, K);
	cout << pos[K];
}
