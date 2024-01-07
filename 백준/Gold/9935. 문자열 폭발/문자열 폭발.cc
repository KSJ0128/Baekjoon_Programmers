#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, bomb, new_str = "";
	stack<char> st;
	cin >> str >> bomb;

	int b_len = bomb.length();
	for (size_t i = 0; i < str.length(); i++)
	{
		st.push(str[i]);
		if (bomb[b_len - 1] == st.top() && st.size() >= b_len)
		{
			string tmp;
			for (int j = 0; j < b_len; j++)
			{
				tmp.push_back(st.top());
				st.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp.compare(bomb) != 0)
			{
				for (int j = 0; j < b_len; j++)
					st.push(tmp[j]);
			}
		}
	}

	while (!st.empty())
	{
		new_str.push_back(st.top());
		st.pop();
	}

	reverse(new_str.begin(), new_str.end());

	if (new_str.empty())
		cout << "FRULA";
	else
		cout << new_str;
}