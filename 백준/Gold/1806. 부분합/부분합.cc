#include <iostream>
#include <vector>
using namespace std;

vector<long long> pre_sum;
int cnt = 100001;
long long start_idx, end_idx;
int N, S;

void	update()
{
	while (pre_sum[end_idx] - pre_sum[start_idx] >= S)
		start_idx++;
	if (cnt > end_idx - start_idx + 1)
		cnt = end_idx - start_idx + 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	pre_sum.push_back(0);
	start_idx = pre_sum[0];
	end_idx = start_idx;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		pre_sum.push_back(pre_sum[i - 1] + n);
		end_idx = i;
		if (pre_sum[end_idx] >= S)
			update();
	}

	if (pre_sum[end_idx] < S)
		cout << 0;
	else
		cout << cnt;
}
