#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 200001
using namespace std;

int N, K;
int visited[MAX][2] = {0,};
int route[MAX];

struct cmp {
	bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
		return a.first > b.first;
	}
};

int BFS() {
	priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> pq;
	pq.push(make_pair(0, N));
	visited[N][0] = true;
	visited[N][1] = 0;

	while (!pq.empty()) {
		int time = pq.top().first;
		int pos = pq.top().second;

		if (pos == K)
			return time;

		pq.pop();

		if (pos * 2 < MAX && (visited[pos * 2][0] == false || visited[pos * 2][1] > time + 1)) {
			visited[pos * 2][0] = true;
			visited[pos * 2][1] = time + 1;
			route[pos * 2] = pos;
			pq.push(make_pair(time + 1, pos * 2));
		}

		if (pos + 1 < MAX && (visited[pos + 1][0] == false || visited[pos + 1][1] > time + 1)) {
			visited[pos + 1][0] = true;
			visited[pos + 1][1] = time + 1;
			route[pos + 1] = pos;
			pq.push(make_pair(time + 1, pos + 1));
		}

		if (pos - 1< MAX && (visited[pos - 1][0] == false || visited[pos - 1][1] > time + 1)) {
			visited[pos - 1][0] = true;
			visited[pos - 1][1] = time;
			route[pos - 1] = pos;
			pq.push(make_pair(time + 1, pos - 1));
		}
	}
}

void print(int pos) {
	if (route[pos] != -1)
		print(route[pos]);

	cout << pos << " ";
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < MAX; i++)
		route[i] = -1;

	cin >> N >> K;

	cout << BFS() << '\n';

	print(K);
}
