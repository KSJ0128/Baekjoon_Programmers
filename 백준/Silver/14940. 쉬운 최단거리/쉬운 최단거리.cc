#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int n, m;
int d_n[] = {0, 0, 1, -1};
int d_m[] = {1, -1, 0, 0};

bool visited[MAX][MAX] = {0, };
int map[MAX][MAX] = {0, };
int route[MAX][MAX] = {0, };

void BFS(int s_n, int s_m) {
	queue< pair<int,int> > que;
	visited[s_n][s_m] = true;

	que.push(make_pair(s_n, s_m));

	while (!que.empty()) {
		int f_n = que.front().first, f_m = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			if (f_n + d_n[i] >= 0 && f_n + d_n[i] <= n && f_m + d_m[i] >= 0 && f_m + d_m[i] <= m) {
				if (map[f_n + d_n[i]][f_m + d_m[i]] == 1 && !visited[f_n + d_n[i]][f_m + d_m[i]]) {
					visited[f_n + d_n[i]][f_m + d_m[i]] = true;
					que.push(make_pair(f_n + d_n[i], f_m + d_m[i]));
					route[f_n + d_n[i]][f_m + d_m[i]] = route[f_n][f_m] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	int s_n, s_m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				s_n = i;
				s_m = j;
			}
		}
	}

	BFS(s_n, s_m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (route[i][j] == 0 && map[i][j] == 1)
				cout << -1 << " ";
			else
				cout << route[i][j] << " ";
		}
		cout << '\n';
	}
}
