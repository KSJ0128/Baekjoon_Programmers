#include <iostream>
#include <vector>
#define MAX 9999999
using namespace std;

vector<vector<int>> dist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X, M, s, e, T;
	int max_time = 0;
	cin >> N >> M >> X;

	dist.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		dist[i] = vector<int>(N + 1, MAX);
	}

	for (int i = 0; i < M; i++) // 경로 세팅
	{
		cin >> s >> e >> T;
		dist[s][e] = T;
	}

	for (int k = 1; k <= N; k++) // 플로이드-워셜
	{
		for (int s = 1; s <= N; s++)
		{
			if (dist[s][k] == MAX)
				continue;
			for (int e = 1; e <= N; e++)
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
		}
	}

	for (int s = 1; s <= N; s++)
		if (dist[s][X] != MAX && dist[X][s] != MAX && s != X && max_time < dist[s][X] + dist[X][s])
			max_time = dist[s][X] + dist[X][s];

	cout << max_time;
}