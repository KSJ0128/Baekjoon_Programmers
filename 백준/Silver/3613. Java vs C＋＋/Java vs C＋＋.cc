#include <iostream>
#include <string>
using namespace std;
int main() {
	string var;
	cin >> var;

	int len = var.length();
	bool java = false, cpp = false;
	for (int i = 0; i < len; i++)
	{

		if (var[i] == '_')
		{
			cpp = true;
			if (i == 0 || i == len - 1 || var[i-1] == '_')
				java = true;
		}
		if (var[i] >= 'A' && var[i] <= 'Z')
		{
			java = true;
			if (i == 0)
				cpp = true;
		}
	}

	if (java && cpp)
		cout << "Error!\n";
	else {
		for (int i = 0; i < len; i++)
		{
			if (var[i] >= 'a' && var[i] <= 'z')
				cout << var[i];
			else if (var[i] == '_')
			{
				i++;
				char c = var[i] - 32;
				cout << c;
			}
			else if (var[i] >= 'A' && var[i] <= 'Z')
			{
				char c = var[i] + 32;
				cout << "_" << c;
			}
		}
	}
}
