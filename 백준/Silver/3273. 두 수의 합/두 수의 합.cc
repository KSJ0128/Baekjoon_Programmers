#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, x, cnt = 0;
	vector<int> integer;
	cin >> n;
	integer.resize(n);

	for (int i = 0; i < n; i++)
		cin >> integer[i];

	sort(integer.begin(), integer.end());

	cin >> x;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (integer[i] + integer[j] == x)
			{
				cnt++;
				break;
			}
			else if (integer[i] + integer[j] > x)
				break;
		}
	}

	cout << cnt;
}