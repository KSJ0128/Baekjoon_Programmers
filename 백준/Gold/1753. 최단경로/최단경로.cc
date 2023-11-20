#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9999999

int V, E, K;   // 노드 개수, 에지 개수, 시작 정점
vector< vector< pair<int, int> > > weight;  // 가중치
vector<int> dist; // 경로
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

// Dijkstra의 최단 경로 알고리즘
void Dijkstra()
{
	while (!pq.empty())
	{
		int pq_val = pq.top().first; // 최단 거리 정점 가중치
		int pq_end = pq.top().second; // 최단 거리 정점
		pq.pop();

		for (int i = 0; i < weight[pq_end].size(); i++)
		{
			int next_val = weight[pq_end][i].first; // 최단 거리 정점과 연결된 정점의 가중치
			int next_end = weight[pq_end][i].second; // 최단 거리 정점과 연결된 정점

			if (dist[next_end] > pq_val + next_val) // 해당 정점의 가중치 > 최단 거리 정점 가중치 + 정점 간 거리
			{
				dist[next_end] = pq_val + next_val;
				pq.push(make_pair(dist[next_end], next_end));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력과 메모리 할당
	cin >> V >> E >> K;
	weight.resize(V + 1);
	dist = vector<int>(V + 1, MAX); // dist 배열 무한대로 초기화

	// 인접행렬에 에지 정보 읽어서 저장
	for (int i = 0; i < E; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		weight[start].push_back(make_pair(value, end));
	}

	dist[K] = 0;
	pq.push(make_pair(0, K));

	// Dijkstra 알고리즘
	Dijkstra();

	// 출력
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == MAX)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}
