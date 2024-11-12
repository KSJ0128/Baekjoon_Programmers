#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 200001
using namespace std;

int N, K;
int visited[MAX][2] = {0,}; // 방문 여부, 시간

struct compare{
	bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
		return a.first > b.first;
	}
};

int BFS() {
	priority_queue<pair<int,int>, vector< pair<int,int> >, compare> pq;
	pq.push(make_pair(0, N));
	visited[N][0] = true;
	visited[N][1] = 0;

	while (!pq.empty()) {
		int time = pq.top().first;
		int pos = pq.top().second;
		// printf("Time : %d, Pos : %d\n", time, pos);

		if (pos == K)
			return time;

		pq.pop();

		if (pos * 2 < MAX && (!visited[pos * 2][0] || visited[pos * 2][1] > time))
		{
			pq.push(make_pair(time, pos * 2));
			visited[pos * 2][0] = true;
			visited[pos * 2][1] = time;
		}
		if (pos + 1 < MAX && (!visited[pos + 1][0] || visited[pos + 1][1] > time + 1))
		{
			pq.push(make_pair(time + 1, pos + 1));
			visited[pos + 1][0] = true;
			visited[pos + 1][1] = time + 1;
		}
		if (pos - 1 >= 0 && (!visited[pos - 1][0] || visited[pos - 1][1] > time + 1))
		{
			pq.push(make_pair(time + 1, pos - 1));
			visited[pos - 1][0] = true;
			visited[pos - 1][1] = time + 1;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << BFS();
}
