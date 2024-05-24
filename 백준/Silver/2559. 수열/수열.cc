#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000
int temp[MAX];

int main()
{
	int N, K;
	int max = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> temp[i];

	queue<int> q;

	for (int j = 0; j < K; j++)
	{
		q.push(temp[j]);
		max += temp[j];
	}

	int now = max;
	for (int i = K; i < N; i++)
	{
		now = now - q.front() + temp[i];
		q.pop();
		q.push(temp[i]);

		max = (now > max) ? now : max;
	}

	cout << max;
}