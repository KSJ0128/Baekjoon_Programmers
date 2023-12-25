#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N, max_index;
	cin >> N;

	vector<int> set(10, 0);

	while (N > 0)
	{
		set[N % 10] += 1;
		N /= 10;
	}

	set[6] = (set[6] + set[9] + 1) / 2;
	set[9] = set[6];

	max_index = max_element(set.begin(), set.end()) - set.begin();
	cout << set[max_index];
}