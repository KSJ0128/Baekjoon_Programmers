#include <iostream>
#include <string>
#include <set>
#define MAX 5
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char game[MAX][MAX];
set<string> check;

int cnt = 0;

void DFS(int row, int col, string str) {
	if (str.length() == 6)
	{
		if (check.find(str) == check.end()) {
			check.insert(str);
			cnt++;
			// cout << str << endl;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (row + dx[i] >= 0 && row + dx[i] < 5 && col + dy[i] >= 0 && col + dy[i] < 5) {
			string tmp = str + game[row + dx[i]][col + dy[i]];
			DFS(row + dx[i], col + dy[i], tmp);
		}
	}
}

int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> game[i][j];
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			DFS(i, j, to_string(game[i][j] - '0'));
		}
	}

	cout << cnt;
}
