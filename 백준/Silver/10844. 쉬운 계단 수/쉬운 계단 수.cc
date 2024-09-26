#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N;
long long DP[101][10] = {0, };
long long cnt = 0;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i < 10; i++)
		DP[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j > 0)
				DP[i][j] += DP[i-1][j-1];
			DP[i][j] %= 1000000000;
			if (j < 9)
				DP[i][j] += DP[i-1][j+1];
			DP[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cnt += DP[N][i];
		cnt %= 1000000000;
	}

	cout << cnt % 1000000000 << '\n';
}
