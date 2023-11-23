#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 99999999
using namespace std;

vector<vector<int>> dist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b, c;
	cin >> n >> m;
	
	dist.resize(n + 1);
	
	for (int i = 1; i <= n; i++) // n x n 인접 행렬 setting
		dist[i].resize(n + 1);

	for (int i = 1; i <= n; i++) // dist 초기화
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) // bus route setting
	{
		cin >> a >> b >> c;
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
		for (int s = 1; s <= n; s++)
			for (int e = 1; e <= n; e++)
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == MAX)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}