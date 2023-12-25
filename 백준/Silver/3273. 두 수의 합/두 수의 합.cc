#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, cnt = 0;
	cin >> n;

	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> x;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == x)
				cnt++;
			else if (arr[i] + arr[j] > x)
				break;
		}
	}
	cout << cnt;
}