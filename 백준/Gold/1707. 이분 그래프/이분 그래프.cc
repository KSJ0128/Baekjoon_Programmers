/*
	다음은 1707. 이분 그래프를 DFS로 풀이한 코드입니다.
	BFS
*/
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


##############################################################################
##############################################################################
##############################################################################

/*
	다음은 1707. 이분 그래프를 BFS로 풀이한 코드입니다.
	BFS
*/
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
