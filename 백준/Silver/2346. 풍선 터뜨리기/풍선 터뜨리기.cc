#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int N, num, cmd;
	deque< pair<int, int> > deq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		deq.push_back(make_pair(num, i + 1));
	}

	while (!deq.empty())
	{
		cmd = deq.front().first;
		cout << deq.front().second << " ";
		deq.pop_front();
		if (cmd > 0)
		{
			for (int i = 0; i < cmd - 1; i++)
			{
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			cmd *= -1;
			deq.push_front(deq.back());
			deq.pop_back();
			for (int i = 0; i < cmd - 1; i++)
			{
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
}