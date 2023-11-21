#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m, a, b, cnt = 0;
	vector< vector<int> > classMate;
	vector<bool> visited;

	cin >> n >> m;
	classMate.resize(n+1);
	visited = vector<bool>(n, false);

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		classMate[a].push_back(b);
		classMate[b].push_back(a);
	}

	for(int i = 0; i < classMate[1].size(); i++)
	{
		int f = classMate[1][i];
		if(visited[f] == false)
		{
			visited[f] = true;
			cnt++;
		}
		for(int j = 0; j < classMate[f].size(); j++)
		{
			int ff = classMate[f][j];
			if(visited[ff] == false && ff != 1)
			{
				visited[ff] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}
