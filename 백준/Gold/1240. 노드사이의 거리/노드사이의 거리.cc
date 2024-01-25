#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1002
#define IMAX 999999999

int N, M;
vector< pair<int,int> > setting[MAX];
bool visited[MAX];

int BFS(int n1, int n2)
{
	queue< pair<int, int> > q; // 출발점, 이전 거리
	visited[n1] = true;
	q.push(make_pair(n1, 0));

	while (!q.empty())
	{
		int f_n = q.front().first, f_d = q.front().second;
		q.pop();

		if (f_n == n2)
			return f_d;

		for (int i = 0; i < setting[f_n].size(); i++)
		{
			int n_n = setting[f_n][i].first, n_d = setting[f_n][i].second;
			if (n_d != -1 && !visited[n_n])
			{
				visited[n_n] = true;
				q.push(make_pair(n_n, f_d + n_d));
			}
		}
	}
	return (-1);
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n1, n2, d;
	cin >> N >> M;

	for (int i = 0; i < N-1; i++)
	{
		cin >> n1 >> n2 >> d;
		setting[n1].push_back(make_pair(n2, d));
		setting[n2].push_back(make_pair(n1, d));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> n2;
		fill(&visited[0], &visited[N+1], false);

		cout << BFS(n1, n2) << '\n';;
	}
}
