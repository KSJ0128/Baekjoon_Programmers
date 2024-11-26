#include <iostream>
using namespace std;
#define MAX 2188

int N, zero = 0, plusOne= 0, minusOne = 0;
int arr[MAX][MAX] = {0,};

void init() {
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
			zero++;
		else if (arr[x][y] == 1)
			plusOne++;
		else
			minusOne++;
	}
	else {

		for (int i = x; i < x + r; i += r / 3) {
			for (int j = y; j < y + r; j += r / 3) {
				paper(i, j, r / 3);
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	init();

	paper(1,1,N);

	cout << minusOne << '\n' << zero << '\n' << plusOne;
}
