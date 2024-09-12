#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 15

int check[MAX][MAX];
int cnt = 0;
int N;

void queen(int i)
{
	if (i == N + 1)
	{
		cnt++;
		return ;
	}

	for (int j = 1; j <= N; j++)
	{
		bool flag = true;
		for (int k = 1; k <= N; k++)
		{
			if (check[k][j] == 1) // 세로 탐색
			{
				flag = false;
				break;
			}

			if (i - k >= 1 && j + k <= N && check[i - k][j + k] == 1) // 오른쪽 대각선 탐색
			{
				flag = false;
				break;
			}

			if (i - k >= 1 && j - k >= 1 && check[i - k][j - k] == 1) // 왼쪽 대각선 탐색
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			check[i][j] = 1; // 퀸을 놓음
			queen(i + 1);
			check[i][j] = 0;
		}
	}
}

int main () {
	cin >> N;

	if (N == 1) {
		cout << 1;
		return (0);
	}
	else if (N == 2 || N == 3) {
		cout << 0;
		return (0);
	}

	for (int i = 0; i < MAX; i++)
		fill(check[i], check[i] + MAX, 0);

	queen(1);

	cout << cnt;
	return (0);
}
