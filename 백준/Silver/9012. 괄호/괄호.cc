#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	int T;
	string parenthesis;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		stack<char> st;
		bool check = true;
		cin >> parenthesis;
		for (int j = 0; j < parenthesis.length(); j++)
		{
			if (parenthesis[j] == '(')
				st.push('(');
			else
			{
				if (!st.empty())
					st.pop();
				else
				{
					check = false;
					break;
				}
			}
		}
		if (!st.empty())
			cout << "NO" << '\n';
		else if (!check)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}