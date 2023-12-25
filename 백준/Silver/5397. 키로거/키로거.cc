#include <iostream>
#include <stack>
#include <deque>
#include <string>
using namespace std;
int main()
{
	int T;
	string password;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		deque<char> front_password;
		stack<char> back_password;
		cin >> password;
		for (int j = 0; j < password.length(); j++)
		{
			if (password[j] == '-')
			{
				if (front_password.size() != 0)
					front_password.pop_back();
			}
			else if (password[j] == '<')
			{
				if (front_password.size() != 0)
				{
					back_password.push(front_password.back());
					front_password.pop_back();
				}
			}
			else if (password[j] == '>')
			{
				if (back_password.size() != 0)
				{
					front_password.push_back(back_password.top());
					back_password.pop();
				}
			}
			else
				front_password.push_back(password[j]);
		}
		while (!front_password.empty())
		{
			cout << front_password.front();
			front_password.pop_front();
		}
		while (!back_password.empty())
		{
			cout << back_password.top();
			back_password.pop();
		}
		cout << '\n';
	}
}
