#include <iostream>
using namespace std;

#define MAX 1000001
int parent[MAX];

int find_parent(int a)
{
	if (parent[a] == -1)
		return a;
	else
		return parent[a] = find_parent(parent[a]);
}

void union_set(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		parent[a] = b;
	else if (a < b)
		parent[b] = a;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	int n, m, p, num1, num2;
	cin >> n >> m;
	fill_n(parent, n+1, -1);

	for (int i = 0; i < m; i++)
	{
		cin >> p >> num1 >> num2;
		if (p == 1)
		{
			if (find_parent(num1) == find_parent(num2))
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
		}
		else
			union_set(num1, num2);
	}
}
