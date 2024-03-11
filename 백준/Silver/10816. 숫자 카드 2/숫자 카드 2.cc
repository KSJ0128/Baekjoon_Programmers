#include <iostream>
using namespace std;
#define MAX 20000001
int card[MAX];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	for (int i = 0; i < MAX; i++)
		card[i] = 0;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		card[tmp + 10000000] += 1;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		cout << card[tmp + 10000000] << '\n';
	}
}