#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> parent;

typedef struct Edge
{
	int s, e, v;

	Edge(int i, int j, int dis)
	{
		s = i;
		e = j;
		v = dis;
	}

	bool operator > (const Edge &temp) const
	{
		return v > temp.v;
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
		return ;
	else
		parent[u2] = u1;
}

int main()
{
	int N, total_len = 0;
	char len;
	bool empty = false;
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	cin >> N;
	parent = vector<int>(N, -1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> len;
			if (len >= 'a' && len <= 'z')
			{
				int val = len - 'a' + 1;
				total_len += val;
				if (i != j)
					pq.push(Edge(i, j, val));
			}
			else if (len >= 'A' && len <= 'Z')
			{
				int val = len - 'A' + 27;
				total_len += val;
				if (i != j)
					pq.push(Edge(i, j, val));
			}
		}
	}

	int mst_edge = 0;
	int mst_weight = 0;

	while (mst_edge < N -1)
	{
		if (pq.empty())
		{
			empty = true;
			break;
		}

		Edge now = pq.top();
		pq.pop();

		if (find_set(now.s) != find_set(now.e))
		{
			union_set(now.s, now.e);
			mst_edge++;
			mst_weight += now.v;
		}
	}

	if (empty)
		cout << -1;
	else
		cout << total_len - mst_weight;
}