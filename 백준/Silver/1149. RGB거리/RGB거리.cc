#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int red[MAX] = {0,};
int green[MAX] = {0,};
int blue[MAX] = {0,};
long DP[MAX][3] = {0,};

void setting() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> red[i] >> green[i] >> blue[i];
	}
}

void RGB() {
	DP[1][0] = red[1];
	DP[1][1] = green[1];
	DP[1][2] = blue[1];

	for (int i = 2; i <= N; i++) {
		DP[i][0] = min(DP[i-1][1] + red[i], DP[i-1][2] + red[i]);
		DP[i][1] = min(DP[i-1][0] + green[i], DP[i-1][2] + green[i]);
		DP[i][2] = min(DP[i-1][0] + blue[i], DP[i-1][1] + blue[i]);
	}
}

int main() {
	setting();

	RGB();

	cout << *min_element(DP[N], DP[N]+3);
}
