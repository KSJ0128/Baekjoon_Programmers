#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int R, C;
bool exit_success = false;
int exit_time = 0;
char arr[MAX][MAX];
int visited[MAX][MAX] = {0,};

queue< pair<int,int> > fire;
queue< pair<int,int> > person;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void BFS_fire(int size) {
	while (size > 0) {
		int row = fire.front().first;
		int col = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++) {
			if (row + dx[i] >= 0 && row + dx[i] < R && col + dy[i] >= 0 && col + dy[i] < C) {
				if (arr[row + dx[i]][col + dy[i]] == '.') {
					arr[row + dx[i]][col + dy[i]] = 'F';
					fire.push(make_pair(row + dx[i], col + dy[i]));
				}
			}
		}
		size--;
	}
}

void BFS_person(int size) {
	while (size > 0) {
		int row = person.front().first;
		int col = person.front().second;
		person.pop();

		for (int i = 0; i < 4; i++) {
			if (row + dx[i] >= 0 && row + dx[i] < R && col + dy[i] >= 0 && col + dy[i] < C) {
				if (arr[row + dx[i]][col + dy[i]] == '.' && !visited[row + dx[i]][col + dy[i]]) {
					if (row + dx[i] == 0 || row + dx[i] == R-1 || col + dy[i] == 0 || col + dy[i] == C - 1) {
						exit_success = true;
						return ;
					}
					visited[row + dx[i]][col + dy[i]] = true;
					person.push(make_pair(row + dx[i], col + dy[i]));
				}
			}
		}
		size--;
	}
}

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
					exit_success = true;
					return ;
				}
				person.push(make_pair(i,j));
			}
			else if (arr[i][j] == 'F')
				fire.push(make_pair(i,j));
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	init();

	while (!person.empty() && !exit_success) {
		exit_time++;
		BFS_fire(fire.size());
		BFS_person(person.size());
	}

	if (exit_success)
		cout << exit_time + 1;
	else
		cout << "IMPOSSIBLE";
}
