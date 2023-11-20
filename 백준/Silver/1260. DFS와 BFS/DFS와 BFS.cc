#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> >graph;
vector<bool> d_visited;
vector<bool> b_visited;

void DFS(int v)
{
	if (!d_visited[v])
	{
		cout << v << " ";
		d_visited[v] = true;
		for(size_t i = 0; i < graph[v].size(); i++)
		{
			if(!d_visited[graph[v][i]])
			{
				DFS(graph[v][i]);
			}
		}
	}
}
void BFS(int v)
{
	queue<int> q;
	q.push(v);
	b_visited[v] = true;

	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		cout << f << " ";

		for(int i : graph[f])
		{
			if (!b_visited[i])
			{
				b_visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int N, M, V, a, b; // 노드 개수, 에지 개수, 탐색 시작 번호
	cin >> N >> M >> V;
	graph.resize(N+1);
	d_visited = vector<bool>(N+1, false);
	b_visited = vector<bool>(N+1, false);

	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	DFS(V);
	cout << endl;
	BFS(V);
}