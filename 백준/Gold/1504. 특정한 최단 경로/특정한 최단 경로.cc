#include <iostream>
#include <vector>
#define MAX 9999999
using namespace std;

vector< vector<int> > dist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E, a, b, c;
	int v1, v2, min_distance = 0;
	cin >> N >> E;

	dist.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		dist[i] = vector<int>(N + 1, MAX);
		dist[i][i] = 0;
	}
	for (int i = 0; i < E; i++) // route setting
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int k = 1; k <= N; k++)
		for (int s = 1; s <= N; s++)
			for (int e = 1; e <= N; e++)
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);

	cin >> v1 >> v2;
	if (dist[1][v1] != MAX && dist[v1][v2] != MAX && dist[v2][N] != MAX)
	{
		min_distance = dist[1][v1] + dist[v1][v2] + dist[v2][N];
		if (min_distance > dist[1][v2] + dist[v2][v1] + dist[v1][N])
			min_distance = dist[1][v2] + dist[v2][v1] + dist[v1][N];
		cout << min_distance;
	}
	else
		cout << -1;
}
