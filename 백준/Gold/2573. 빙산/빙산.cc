#include <iostream>
#include <queue>
#define MAX 301
using namespace std;

int N, M, cnt = 0, fin_time = 0;
bool check = true;
int arr[MAX][MAX] = {0,}; // first : 빙산, second : 주변 바다
int visited[MAX][MAX] = {0,};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
queue< pair<int,int> > que;

void BFS(int size) {
	bool visited_BFS[MAX][MAX] = {0,};
	queue< pair<int,int> > que_bfs;
	int check_cnt = 0;

	que_bfs.push(make_pair(que.front().first,que.front().second));

	while (!que_bfs.empty()) {
		int row = que_bfs.front().first;
		int col = que_bfs.front().second;

		visited_BFS[row][col] = true;
		check_cnt++;
		que_bfs.pop();

		for (int i = 0; i < 4; i++) {
			if (row + dx[i] >= 0 && row + dx[i] < N && col + dy[i] >= 0 && col + dy[i] < M) {
				if (!visited_BFS[row + dx[i]][col + dy[i]]) {
					visited_BFS[row + dx[i]][col + dy[i]] = true;

				if (arr[row + dx[i]][col + dy[i]] > 0)
					que_bfs.push(make_pair(row + dx[i], col + dy[i]));
				}
			}
		}
	}

	if (size == check_cnt)
		check = false;
}

void melt(int size) {
	while (size > 0) {
		// 빙산의 위치
		int row = que.front().first;
		int col = que.front().second;
		int ice = 0;

		que.pop();

		for (int i = 0; i < 4; i++) {
			if (row + dx[i] >= 0 && row + dx[i] < N && col + dy[i] >= 0 && col + dy[i] < M) {
				if ((visited[row + dx[i]][col + dy[i]] <= visited[row][col]) && (arr[row + dx[i]][col + dy[i]] == 0))
					ice++;
			}
		}

		visited[row][col]++;
		arr[row][col] -= ice;

		if (arr[row][col] <= 0)
		{
			check = true;
			arr[row][col] = 0;
			cnt--;
		}
		else
			que.push(make_pair(row, col));
		size--;
	}
}

void setArray(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				que.push(make_pair(i, j)); // 빙산 que에 Push
				cnt++;
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M; // 행, 열
	setArray(N, M); // 빙산 세팅

	BFS(que.size());

	while (!que.empty() && !check) {
		melt(que.size());
		if (check)
			BFS(que.size());
		fin_time++;
	}

	if (check && !que.empty())
		cout << fin_time;
	else
		cout << 0;
}
