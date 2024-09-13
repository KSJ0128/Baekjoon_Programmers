#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<long long> pre_sum;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	pre_sum.push_back(0);

	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;

		pre_sum.push_back(pre_sum[i-1] + n);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << pre_sum[b] - pre_sum[a - 1] << '\n';
	}
}
