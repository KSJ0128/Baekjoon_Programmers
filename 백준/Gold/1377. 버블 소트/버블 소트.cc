#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num, max = 0;
	vector< pair<int, int> > arr;
	vector<int> diff;

	cin >> N;
	arr.resize(N);
	diff.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >>num;
		arr[i] = make_pair(num, i);
	}

	stable_sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		diff[i] = arr[i].second - i;

		if (max < diff[i])
			max = diff[i];
	}
	cout << max + 1;
}