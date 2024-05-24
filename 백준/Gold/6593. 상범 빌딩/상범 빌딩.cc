#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX 35

int visited[MAX][MAX][MAX];
char building[MAX][MAX][MAX];
int L = 1, R = 1, C = 1;

int x[] = {0, 0, 0, 0, 1, -1};
int y[] = {0, 0, 1, -1, 0, 0};
int z[] = {1, -1, 0, 0, 0, 0};

int BFS(int S_L, int S_R, int S_C)
{
	queue< tuple<int,int,int> > q;
	q.push(make_tuple(S_L, S_R, S_C));

	while (!q.empty())
	{
		int front_L = get<0>(q.front());
		int front_R = get<1>(q.front());
		int front_C = get<2>(q.front());

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int new_L = front_L + x[i];
			int new_R = front_R + y[i];
			int new_C = front_C + z[i];

			if (new_L >= 0 && new_L < L && new_R >= 0 && new_R < R && new_C >= 0 && new_C < C) // 범위 검사
			{
				if (visited[new_L][new_R][new_C] == 0)
				{
					visited[new_L][new_R][new_C] = visited[front_L][front_R][front_C] + 1;

					if (building[new_L][new_R][new_C] == '.')
					{
						q.push(make_tuple(new_L, new_R, new_C));
					}
					else if (building[new_L][new_R][new_C] == 'E')
					{
						return visited[new_L][new_R][new_C];
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (L != 0 && R != 0 && C != 0)
	{
		// 빌딩 층 수, 행, 열
		cin >> L >> R >> C;

		// 빌딩 시작 위치
		int S_L, S_R, S_C;

		// Initialize visited array
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    visited[i][j][k] = 0;
                }
            }
        }

        // Initialize building array
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    building[i][j][k] = '#';
                }
            }
        }

		// building 정보 입력 받기
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S')
					{
						S_L = i, S_R = j, S_C = k;
					}
				}
			}
		}

		int step = BFS(S_L, S_R, S_C);

		if (step != 0)
			cout << "Escaped in " << step << " minute(s)." << '\n';
		else if (L != 0 && R != 0 && C != 0)
			cout << "Trapped!" << '\n';
	}
}