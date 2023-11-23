#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dist;

int main()
{
	int N;
	cin >> N;
	
	dist.resize(N + 1);
	for (int i = 1; i <= N; i++) // dist 초기화
		dist[i].resize(N + 1);

	for (int i = 1; i <= N; i++) // 경로 세팅
		for (int j = 1; j <= N; j++)
			cin >> dist[i][j];

	for (int k = 1; k <= N; k++)
		for (int s = 1; s <= N; s++)
			for (int e = 1; e <= N; e++)
				if (dist[s][k] == 1 && dist[k][e] == 1)
					dist[s][e] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << dist[i][j] << " ";
		cout << '\n';
	}
}