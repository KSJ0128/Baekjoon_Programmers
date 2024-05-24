#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 51
char square[MAX][MAX];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, len;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> square[i][j];
		}
	}

	len = (N > M) ? M : N;
	pair<int,int> lt = make_pair(0,0), rt = make_pair(0, len - 1), lb = make_pair(len - 1, 0);

	while (true)
	{
		if (square[lt.first][lt.second] == square[rt.first][rt.second] &&
			square[lt.first][lt.second] == square[lb.first][lb.second] &&
			square[lt.first][lt.second] == square[lb.first][rt.second])
		{
			cout << len * len << endl;
			// cout << lt.first << " " << lt.second << endl
			//  << rt.first << " " << rt.second << endl
			//  << lb.first << " " << lb.second << endl;
			break;
		}
		else
		{
			if (rt.second + 1 < M) // 우측 이동
			{
				lt.second++;
				rt.second++;
				lb.second++;
			}
			else if (lb.first + 1 < N) // 하단 이동
			{
				lt.first++;
				rt.first++;
				lb.first++;

				lt.second = 0;
				lb.second = 0;
				rt.second = len - 1;
			}
			else // 길이 조정
			{
				len--;

				lt.first = 0;
				rt.first = 0;
				lb.first = len - 1;

				lt.second = 0;
				lb.second = 0;
				rt.second = len - 1;
			}
		}
	}
}