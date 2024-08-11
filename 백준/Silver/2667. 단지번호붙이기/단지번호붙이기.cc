#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char map[26][26];
bool visited[26][26];

int BFS(int row, int col, int N) {
	queue< pair<int,int> > que;
	visited[row][col] = true;
	int cnt = 0;

	que.push(make_pair(row, col));

	while (!que.empty()) {
		int f_row = que.front().first;
		int f_col = que.front().second;
		cnt++;

		que.pop();

		for (int i = 0; i < 4; i++) {
			if (f_row + dx[i] >= 0 && f_row + dx[i] < N && f_col + dy[i] >= 0 && f_col + dy[i] < N)
			{
				if (!visited[f_row + dx[i]][f_col + dy[i]] && map[f_row + dx[i]][f_col + dy[i]] == '1') {
					que.push(make_pair(f_row + dx[i], f_col + dy[i]));
					visited[f_row + dx[i]][f_col + dy[i]] = true;
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	memset(map, 0, 26 * 26);
	memset(visited, false, 26 * 26);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	vector<int> house;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == '1') {
				cnt++;
				house.push_back(BFS(i, j, N));
			}
		}
	}

	sort(house.begin(), house.end());

	cout << cnt << '\n';

	for (int i = 0; i < house.size(); i++)
		cout << house[i] << '\n';
}
