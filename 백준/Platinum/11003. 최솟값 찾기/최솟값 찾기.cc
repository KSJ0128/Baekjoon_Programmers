#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;

	deque< pair<int,int> > deq;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		// 삽입
		while (!deq.empty() && deq.back().first > tmp)
			deq.pop_back();
		deq.push_back(make_pair(tmp, i));

		// 출력
		while (deq.front().second <= i - L)
			deq.pop_front();

		cout << deq.front().first << " ";
	}
}