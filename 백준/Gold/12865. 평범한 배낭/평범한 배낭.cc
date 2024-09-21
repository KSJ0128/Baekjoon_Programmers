#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector< pair<int,int> > object;
int knapsack[101][100001] = {0,};
int N, K, max_w = 0;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;

		// 각 물건의 무게 및 가치
		object.push_back(make_pair(W, V));
	}

	int idx = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (object[idx].first <= j)
				knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-object[idx].first] + object[idx].second);
			else
				knapsack[i][j] = knapsack[i-1][j];
			max_w = max(max_w, knapsack[i][j]);
		}
		idx++;
	}

	cout << max_w;
}
