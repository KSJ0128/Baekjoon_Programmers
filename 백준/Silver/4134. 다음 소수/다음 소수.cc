#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(long long int n) {
	if (n == 0 || n == 1) return false;
	else if (n == 2 || n == 3) return true;
	else if (n % 2 == 0) return false;

	long long int sq = sqrt(n);

	for (int i = 3; i <= sq; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	long long int n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		while (!is_prime(n))
			n++;

		cout << n << '\n';
	}
}