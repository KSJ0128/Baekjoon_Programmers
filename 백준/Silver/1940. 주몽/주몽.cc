#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	vector<int> things;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int thing;
		cin >> thing;

		things.push_back(thing);
	}
	sort(things.begin(), things.end());

	int i = 0, j = things.size() - 1, cnt = 0;
	while (i < j)
	{
		if (things[i] + things[j] == M)
		{
			i++;
			j--;
			cnt++;
		}
		else if (things[i] + things[j] > M)
			j--;
		else
			i++;
	}
	cout << cnt;
}
