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

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	stable_sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		if (max < arr[i].second - i)
			max = arr[i].second - i;
	}
	cout << max + 1;
}