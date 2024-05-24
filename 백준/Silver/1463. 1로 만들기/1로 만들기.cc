#include <iostream>
using namespace std;

#define MAX 1000002
int DP[MAX];

int main()
{
	int N;
	cin >> N;

	DP[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + 1;

		if (i % 2 == 0)
		{
			DP[i] = (DP[i] < DP[i / 2] + 1) ? DP[i] : DP[i / 2] + 1;
		}

		if (i % 3 == 0)
		{
			DP[i] = (DP[i] < DP[i / 3] + 1) ? DP[i]: DP[i / 3] + 1;
		}
	}

	cout << DP[N];
}