#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000

vector< vector<int> > relation;

bool DFS(int n, int depth, vector<bool> friends)
{
	friends[n] = true;
	depth++;

	if (depth == 5)
		return (true);

	for (int i : relation[n])
	{
		if (!friends[i])
			if (DFS(i, depth, friends))
                return true; // 연결된 친구 중 하나가 depth 5에 도달하면 true 반환
	}
	friends[n] = false; // 탐색이 끝나면 다시 방문 표시를 해제 (백트래킹)
    return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector <bool> friends;
	int N, M; // 친구 수, 관계 수
	cin >> N >> M;

	relation.resize(N);
	friends.resize(N);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < N; i++)
			friends[i] = false;

		if (DFS(i, 0, friends))
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
