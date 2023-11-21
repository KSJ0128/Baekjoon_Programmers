#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> visited;
vector<int> color;
vector<vector<int> > graph;

bool BFS(int s)
{
	queue<int> q;

	q.push(s);
	color[s] = 0;
	visited[s] = true;

	while(!q.empty())
	{
		int f = q.front();
		q.pop();

		for(int i = 0; i < graph[f].size(); i++)
		{
			int node = graph[f][i];
			if(!visited[node])
			{
				if (color[f] == 0)
					color[node] = 1;
				else
					color[node] = 0;
				visited[node] = true;
				q.push(node);
			}
			else if (color[node] == color[f])
				return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, V, E, u, v;
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		bool check = true;
		cin >> V >> E;
		graph.clear();
		graph.resize(V + 1);
		color = vector<int>(V + 1, -1);
		visited = vector<bool>(V + 1, false);
		for(int j = 0; j < E; j++) // 무방향 그래프 해결
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) // 비연결 그래프 해결
		{
			if(visited[i] == false)
			{
				if(!BFS(i))
				{
					check = false;
					break;
				}
			}
		}
		if(check)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
