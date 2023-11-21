#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<int> color;
vector<vector<int> > graph;
bool check;

void DFS(int n)
{
	visited[n] = true;

	for(int i : graph[n])
	{
		if (!visited[i])
		{
			if (color[n] == 0)
				color[i] = 1;
			else
				color[i] = 0;
			DFS(i);
		}
		else if(color[n] == color[i])
		{
			check = false;
			return ;
		}
	}
	return ;
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
		check = true;
		cin >> V >> E;
		visited = vector<bool>(V + 1, false);
		color = vector<int>(V + 1, -1);
		graph.clear();
		graph.resize(V + 1);

		for(int j = 0; j < E; j++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++)
		{
			if(!visited[i])
			{
				color[i] = 0;
				DFS(i);
				if (!check)
					break;
			}
		}
		if(check)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}