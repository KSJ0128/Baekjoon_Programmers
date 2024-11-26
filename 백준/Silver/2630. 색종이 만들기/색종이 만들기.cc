#include <iostream>
using namespace std;
#define MAX 129

int N, white = 0, blue = 0;
int arr[MAX][MAX] = {0,};

void init() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void paper(int x, int y, int r) {
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
		if (arr[x][y] == 0)
			white++;
		else
			blue++;
	}
	else {
		for (int i = x; i <= x + r/2; i += r/2) {
			for (int j = y; j <= y + r/2; j += r/2) {
				paper(i, j, r/2);
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	paper(1,1,N);

	cout << white << '\n' << blue;
}
