#include <iostream>
#include <string>
using namespace std;

int T;

bool check_pal(string str, int f, int b)
{
	while (f < b)
	{
		if (str[f] == str[b])
		{
			f++;
			b--;
		}
		else
			return false;
	}
	return true;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;

		int f = 0, b = str.length() - 1;
		int check = 0;
		while (f < b)
		{
			if (str[f] == str[b])
			{
				f++;
				b--;
			}
			else
			{
				check++;
				bool pal_check1 = check_pal(str, f+1, b);
				bool pal_check2 = check_pal(str, f, b-1);

				if (!(pal_check1 || pal_check2))
					check++;
				break;
			}
		}

		if (check == 0)
			cout << "0\n";
		else if (check == 1)
			cout << "1\n";
		else
			cout << "2\n";
	}

}
