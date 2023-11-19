#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> parent;

typedef struct Edge
{
	int s, e, v; // 시작 노드, 끝 노드, 가중치

	Edge(int start, int end, int value)
	{
		s = start;
		e = end;
		v = value;
	}

	bool operator > (const Edge& temp) const
	{
		return v > temp.v;
	}
} Edge;

int find_set(int n)
{
	while (parent[n] != -1)
		n = parent[n];
	return n;
}

void union_set(int n1, int n2)
{
	if (n1 > n2)
	{
		parent[n1] = n2;
	}
	else if(n1 == n2)
		return ;
	else
	{
		parent[n2] = n1;
	}
}

int main()
{
	int V, E, A, B, C; // 노드, 에지, 노드1, 노드2, 가중치
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	cin >> V >> E;
	parent = vector<int>(V + 1, -1);

	for (int i = 0; i < E; i++) // 에지 정보 입력 받기
	{
		cin >> A >> B >> C;
		pq.push(Edge(A, B, C));
	}

	int mst_edge = 0; // mst에 속하는 에지 개수
	long long mst_weight = 0; // mst에 속하는 에지의 가중치 합

	while (mst_edge < V - 1)
	{
		Edge now = pq.top();
		pq.pop();

		if (find_set(now.s) != find_set(now.e))
		{
			union_set(find_set(now.s), find_set(now.e));
			mst_weight += now.v;
			mst_edge++;
		}
	}

	cout << mst_weight;
}