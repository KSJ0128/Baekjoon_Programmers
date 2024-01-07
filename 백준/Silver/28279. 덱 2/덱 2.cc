#include <iostream>
#include <deque>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, cmd, num;
	deque<int> deq;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (cmd == 1)
		{
			cin >> num;
			deq.push_front(num);
		}
		else if (cmd == 2)
		{
			cin >> num;
			deq.push_back(num);
		}
		else if (cmd == 3)
		{
			if (!deq.empty())
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (cmd == 4)
		{
			if (!deq.empty())
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (cmd == 5)
			cout << deq.size() << '\n';
		else if (cmd == 6)
		{
			if (deq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == 7)
		{
			if (!deq.empty())
				cout << deq.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (cmd == 8)
		{
			if (!deq.empty())
				cout << deq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}