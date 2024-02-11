#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> parent;

typedef struct Edge
{
	int v1, v2, w;

	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		w = c;
	}

	bool operator > (const Edge& e) const
	{
		return w > e.w;
	}
} Edge;

int find_set(int a)
{
	if (parent[a] == -1)
		return a;
	else
		return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a == b)
		return ;
	else if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main()
{
	int V, E, A, B, C;
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	cin >> V >> E;
	parent = vector<int> (V+1, -1);

	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		pq.push(Edge(A, B, C));
	}

	int mst_edge = 0;
	long long mst_weight = 0;

	while (mst_edge < V-1)
	{
		Edge e = pq.top();
		pq.pop();

		if (find_set(e.v1) != find_set(e.v2))
		{
			union_set(e.v1, e.v2);
			mst_weight += e.w;
			mst_edge++;
		}
	}

	cout << mst_weight;
}