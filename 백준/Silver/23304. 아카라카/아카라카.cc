#include <iostream>
#include <string>
using namespace std;

bool pal_check(string str, int len)
{
	int i = 0, mid = len / 2, left, right;

	if (len == 1)
		return (true);
	else
	{
		int sub_len = len / 2;
		string head = str.substr(0, sub_len);
		string tail = str.substr(len - sub_len, sub_len);

		if (!pal_check(head, sub_len))
			return (false);
		if (!pal_check(tail, sub_len))
			return (false);

		if (len % 2 == 0)
			left = mid - 1 - i, right = mid + i;
		else
			left = mid - 1 - i, right = mid + 1 + i;

		while (left >= 0 && right < len)
		{
			if (str[left] != str[right])
				return (false);
			left--;
			right++;
		}
		return (true);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string palindrom;
	cin >> palindrom;

	int len = palindrom.length();

	if (pal_check(palindrom, len))
		cout << "AKARAKA";
	else
		cout << "IPSELENTI";
}
