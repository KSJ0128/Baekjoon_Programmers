#include <iostream>
#include <vector>
using namespace std;

vector< int > travel;

int findSet(int c)
{
	while (travel[c] != -1)
		c = travel[c];
	return c;
}
void unionSet(int a, int b)
{
	a = findSet(a);
	b = findSet(b);
	if (a > b)
		travel[a] = b;
	else if(a == b)
		return;
	else
		travel[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);

	int N, M, city, course, root;
	bool check = true;
	cin >> N >> M;

	travel = vector<int>(N + 1, -1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> city;
			if (city == 1)
				unionSet(i, j);
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> course;
		if (i == 0)
			root = findSet(course);
		else if (root != findSet(course))
		{
			check = false;
			break;
		}
	}

	if (check)
		cout << "YES";
	else
		cout << "NO";
}