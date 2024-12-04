#include <iostream>
#include <cmath>
#define MAX 301
using namespace std;

int N;
int stair[MAX] = {0,};
long DP[MAX] = {0,};

void setting() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
}

void up_stairs() {
	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = (stair[1] > stair[2]) ? stair[1] + stair[3] : stair[2] + stair[3];

	for (int i = 4; i <= N; i++) {
		DP[i] = (DP[i-2] + stair[i] > DP[i-3] + stair[i-1] + stair[i]) ? DP[i-2] + stair[i] : DP[i-3] + stair[i-1] + stair[i];
	}
}

int main() {
	setting();

	up_stairs();
	cout << DP[N];
}
