#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long N, S, cnt = 0;
vector <long long> arr;
map<long long, long long> sub_sum;

void	left_search(int idx, int sum)
{
	if (idx == N / 2)
	{
		sub_sum[sum]++;
		return ;
	}
	left_search(idx + 1, sum);
	left_search(idx + 1, sum + arr[idx]);
}

void	right_search(int idx, int sum)
{
	if (idx == N)
	{
		cnt += sub_sum[S - sum];
		return ;
	}
	right_search(idx + 1, sum);
	right_search(idx + 1, sum + arr[idx]);
}

int	main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	left_search(0, 0);
	right_search(N / 2, 0);

	if (S == 0)
		cout << cnt - 1;
	else
		cout << cnt;
}
