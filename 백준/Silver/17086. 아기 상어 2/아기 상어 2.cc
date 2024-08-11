#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 51

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int visited[MAX][MAX];
int map[MAX][MAX];
queue< pair<int,int> > que;
int N, M;

void BFS() {

	while(!que.empty()) {
		int f_row = que.front().first;
		int f_col = que.front().second;

		que.pop();

		for (int i = 0; i < 8; i++) {
			if (f_row + dx[i] >= 0 && f_row + dx[i] < N && f_col + dy[i] >= 0 && f_col + dy[i] < M) // range check
			{
				if (visited[f_row + dx[i]][f_col + dy[i]] == -1 && map[f_row + dx[i]][f_col + dy[i]] == 0) // visit check && 0인 경우
				{
					que.push(make_pair(f_row + dx[i], f_col + dy[i]));
					visited[f_row + dx[i]][f_col + dy[i]] = visited[f_row][f_col] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	memset(map, 0, sizeof(map));
	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				que.push(make_pair(i,j));
				visited[i][j] = 0;
			}
		}
	}

	BFS();

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max < visited[i][j])
				max = visited[i][j];
		}
	}
	cout << max;
}
