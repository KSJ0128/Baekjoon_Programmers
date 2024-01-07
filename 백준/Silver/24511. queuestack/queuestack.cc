#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, len;
	deque<int> deq;
	cin >> N;

	vector<int> ds(N);
	for (int i = 0; i < N; i++)
		cin >> ds[i];

	vector<int> element(N);
	for (int i = 0; i < N; i++)
	{
		cin >> element[i];
		if (ds[i] == 0)
			deq.push_front(element[i]);
	}

	cin >> len;
	vector<int> is(len);
	for (int i = 0; i < len; i++)
		cin >> is[i];

	if (deq.empty())
	{
		for (int i = 0; i < len; i++)
			cout << is[i] << " ";
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			deq.push_back(is[i]);
			cout << deq.front() << " ";
			deq.pop_front();
		}
	}
}