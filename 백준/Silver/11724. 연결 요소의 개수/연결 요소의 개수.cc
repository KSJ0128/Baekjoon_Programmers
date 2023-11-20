#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find_set(int n)
{
	while(parent[n] != -1)
		n = parent[n];
	return n;
}

void union_set(int s, int e)
{
	s = find_set(s);
	e = find_set(e);

	if(s > e)
		parent[s] = e;
	else if(s == e)
		return;
	else
		parent[e] = s;
}

int main()
{
	int N, M, s, e, connect = 0;
	cin >> N >> M;

	parent = vector<int>(N+1, -1);

	for(int i = 0; i < M; i++)
	{
		cin >> s >> e;
		union_set(s, e);
	}

	for(int i = 1; i <= N; i++)
	{
		if (parent[i] == -1)
			connect++;
	}
	cout << connect;
}