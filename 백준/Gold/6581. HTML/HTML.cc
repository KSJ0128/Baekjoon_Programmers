#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string html, line, word;
	int idx = 0, total;

	// html 세팅
	while (getline(cin, line))
		html += line + '\n';
	line.clear();

	total = html.length();
	while (idx < total)
	{
		while (html[idx] != ' ' && html[idx] != '\t' && html[idx] != '\n' && idx < total)
			word += html[idx++];

		if (word == "<br>")
		{
			cout << line << '\n';
			line.clear();
		}
		else if (word == "<hr>")
		{
			if (line != "")
				cout << line << '\n';
			for (int i = 0; i < 80; i++)
					cout << '-';
				cout << '\n';
			line.clear();
		}
		else if (line.length() + word.length() >= 80)
		{
			cout << line << '\n';
			line.clear();
			line += word;
		}
		else if (word != "")
		{
			if (line != "")
				line += " ";
			line += word;
		}
		word.clear();
		idx++;
	}
	cout << line << '\n';
}