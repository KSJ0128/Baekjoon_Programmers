#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000000

bool is_prime(int N) {
	if (N == 2 || N == 3) return true;
	else if (N % 2 == 0 || N % 3 == 0) return false;

	for (int i = 4; i <= sqrt(N); i++) {
		if (N % i == 0) return false;
	}

	return true;
}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	cin >> T;

	vector<int> prime;
	for (int i = 2; i <= MAX; i++) {
		if (is_prime(i))
			prime.push_back(i);
	}

	for (int i = 0; i < T; i++) {
		cin >> N;
		int cnt = 0, f = 0, e = prime.size() - 1;
		while (e >= f) {
			if (prime[f] + prime[e] > N) e--;
			else if (prime[f] + prime[e] < N) f++;
			else if (prime[f] + prime[e] == N) {
				cnt++;
				f++;
				e--;
			}
		}
		cout << cnt << '\n';
	}
}
