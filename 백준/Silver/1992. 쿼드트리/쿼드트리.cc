#include <iostream>
using namespace std;
#define MAX 65

int N;
char arr[MAX][MAX] = {0,};

void init() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void quadTree(int x, int y, int r) {
	bool check = true;

	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + r; j++) {
			if (arr[x][y] != arr[i][j]) {
				check = false;
				break;
			}
		}
		if (!check)
			break;
	}

	if (check) {
		cout << arr[x][y];
	}
	else {
		cout << "(";
		for (int i = x; i < x + r; i += r/2) {
			for (int j = y; j < y + r; j += r/2) {
				quadTree(i, j, r/2);
			}
		}
		cout << ")";
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();

	quadTree(1,1,N);
}
