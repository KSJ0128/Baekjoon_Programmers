#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
	if (n < 2) return false;
	else if (n == 2 || n == 3) return true;
	else if (n % 2 == 0 || n % 3 == 0) return false;

	int sq = sqrt(n);

	for (int i = 4; i <= sq; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	while (n != 0) {
		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (is_prime(i))
				cnt++;
		}
		cout << cnt << '\n';
		cin >> n;
	}
}