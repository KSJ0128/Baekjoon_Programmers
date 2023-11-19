#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> parent;
vector<char> univer;

typedef struct Edge
{
	int u, v, d;
	Edge(int u1, int u2, int distance)
	{
		u = u1;
		v = u2;
		d = distance;
	}

	bool operator > (const Edge& temp) const
	{
		return d > temp.d;
	}
} Edge;

int find_set(int u)
{
	while (parent[u] != -1)
		u = parent[u];
	return u;
}

void union_set(int u1, int u2)
{
	u1 = find_set(u1);
	u2 = find_set(u2);

	if (u1 > u2)
		parent[u1] = u2;
	else if (u1 == u2)
		return;
	else
		parent[u2] = u1;
}

int main()
{
	int N, M, u, v, d; // 학교 수, 도로 개수, u대학, v대학, 대학 간 거리
	bool empty = false;
	priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
	cin >> N >> M;
	univer.resize(N + 1);
	parent = vector<int>(N + 1, -1);

	for (int i = 1; i <= N; i++)
		cin >> univer[i];

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> d;
		pq.push(Edge(u, v, d));
	}

	int mst_edge = 0;
	int mst_weight = 0;

	while (mst_edge < N - 1)
	{
		if (pq.empty())
		{
			empty = true;
			break;
		}

		Edge now = pq.top();
		pq.pop();

		if (univer[now.u] != univer[now.v] && find_set(now.u) != find_set(now.v))
		{
			union_set(now.u, now.v);
			mst_edge++;
			mst_weight += now.d;
		}
	}

	if (empty)
		cout << -1;
	else
		cout << mst_weight;
}