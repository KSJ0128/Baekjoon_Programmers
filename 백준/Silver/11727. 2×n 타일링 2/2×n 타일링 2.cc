#include <iostream>
#define MAX 10001
using namespace std;

int n;
int arr[MAX] = {0,};

void DP(int n) {
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i-1] + (arr[i-2] * 2)) % 10007;
	}

	cout << arr[n];
}

int main() {
	cin >> n;

	DP(n);
}
