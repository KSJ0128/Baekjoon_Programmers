#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool visited[MAX][MAX];
char map[MAX][MAX];
int H, W;

void BFS(int row, int col) {
	queue< pair<int,int> > que;
	que.push(make_pair(row, col));
	visited[row][col] = true;

	while (!que.empty()) {
		int f_row = que.front().first;
		int f_col = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			if (f_row + dx[i] >= 0 && f_row + dx[i] < H && f_col + dy[i] >= 0 && f_col + dy[i] < W) {
				if (!visited[f_row + dx[i]][f_col + dy[i]] && map[f_row + dx[i]][f_col + dy[i]] == '#') {
					visited[f_row + dx[i]][f_col + dy[i]] = true;
					que.push(make_pair(f_row + dx[i], f_col + dy[i]));
				}
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W;

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> map[j][k];
				visited[j][k] = false;
			}
		}

		int cnt = 0;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				if (!visited[j][k] && map[j][k] == '#') {
					BFS(j, k);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}
