#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start_idx = 1, end_idx = 1, N;
	cin >> N;

	int sum = 0, cnt = 1;
	while (end_idx < N)
	{
		sum += end_idx;

		if (sum >= N)
		{
			if (sum == N)
				cnt++;
			start_idx++;
			end_idx = start_idx;
			sum = 0;
		}
		else
			end_idx++;
	}
	cout << cnt;
}
