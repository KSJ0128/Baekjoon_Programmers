#include <iostream>
#define MAX 12
using namespace std;

int T, n;
int DP[MAX] = {0,};

void setting() {
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i < MAX; i++) {
		DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
	}
}

int main() {
	setting();

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		cout << DP[n] << '\n';
	}
}
