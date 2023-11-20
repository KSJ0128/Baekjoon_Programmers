#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 9999999
vector<int> dist;
vector< vector<pair<int,int> > > edge;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

void Dijkstra()
{
	while(!pq.empty())
	{
		int pq_vertex = pq.top().second;
		int pq_distance = pq.top().first;
		pq.pop();
		for(int i = 0; i < edge[pq_vertex].size(); i++)
		{
			int next_vertex = edge[pq_vertex][i].second;
			int next_distance = edge[pq_vertex][i].first;

			if (dist[next_vertex] > pq_distance + next_distance)
			{
				dist[next_vertex] = pq_distance + next_distance;
				pq.push(make_pair(dist[next_vertex], next_vertex));
			}
		}
	}
}

int main()
{
	int N, M, K, X, A, B;
	bool check = false;
	cin >> N >> M >> K >> X;
	dist = vector<int>(N + 1, MAX);
	edge.resize(N + 1);

	for(int i = 0; i < M; i++)
	{
		cin >> A >> B;
		edge[A].push_back(make_pair(1, B));
	}

	dist[X] = 0;
	pq.push(make_pair(dist[X], X));

	Dijkstra();

	for(int i = 1; i <= N; i++)
	{
		if(dist[i] == K)
		{
			check = true;
			cout << i << '\n';
		}
	}

	if (!check)
		cout << -1;
}
