#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
string max_str = "0";
string min_str = "9876543210";

vector<char> sign;
vector<char> num;
bool check[10] = {false, };

void DFS(string str) {
	int len = str.length();

	if (len == k + 1) {
		if (max_str < str)
			max_str = str;
		if (min_str > str)
			min_str = str;
		return ;
	}

	for (int i = 0; i < 10; i++) {
		if (!check[i])
		{
			if (sign[len - 1] == '>' && str[len - 1] > num[i])
			{
				check[i] = true;
				str += num[i];
				DFS(str);
				str.pop_back();
				check[i] = false;
			}
			else if (sign[len - 1] == '<' && str[len - 1] < num[i])
			{
				check[i] = true;
				str += num[i];
				DFS(str);
				str.pop_back();
				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		sign.push_back(c);
	}

	for (int i = 0; i < 10; i++)
		num.push_back('0' + i);

	for (int i = 0; i < 10; i++) {
		check[i] = true;
		DFS(to_string(i));
		check[i] = false;
	}

	cout << max_str << '\n' << min_str;
}
