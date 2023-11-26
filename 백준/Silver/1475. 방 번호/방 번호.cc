#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, num, max_index;
	vector <int> set(10, 0);

	cin >> N;
	while (N > 0)
	{
		num = N % 10;
		N /= 10;
		set[num]++;
	}

	if (set[6] >=  set[9])
		set[6] = set[9] + (set[6] - set[9] + 1) / 2;
	else
		set[9] =  set[6] + (set[9] - set[6] + 1) / 2;

	max_index = max_element(set.begin(), set.end()) - set.begin();
	cout << set[max_index];
}