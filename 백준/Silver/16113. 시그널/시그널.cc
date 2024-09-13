#include <iostream>
#include <string>
using namespace std;

string sig_str, answer;
int len, width;

bool eight_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
			return false;
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool nine_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
		{
			if (i != 3)
				return false;
		}
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool six_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
			return false;
		if (sig_str[idx + 2 + width * i] != '#')
		{
			if (i != 1)
				return false;
		}
	}
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool five_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
		{
			if (i != 3)
				return false;
		}
		if (sig_str[idx + 2 + width * i] != '#')
		{
			if (i != 1)
				return false;
		}
	}
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool three_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
		{
			if (i != 1 && i != 3)
				return false;
		}
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool two_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
		{
			if (i != 1)
				return false;
		}
		if (sig_str[idx + 2 + width * i] != '#')
		{
			if (i != 3)
				return false;
		}
	}
	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool seven_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}
	return true;
}

bool four_check(int idx) {
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}

	for (int i = 1; i < 3; i++)
	{
		if (sig_str[idx + width * i] != '#')
			return false;
	}

	if (sig_str[idx + 1 + width * 2] != '#')
		return false;
	return true;
}

bool zero_check(int idx) {
	if (sig_str[idx+1] != '#' || sig_str[idx+2] != '#')
		return false;
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
			return false;
		if (sig_str[idx + 2 + width * i] != '#')
			return false;
	}
	if (sig_str[idx + width * 4] != '#' || sig_str[idx + 1 + width * 4] != '#' || sig_str[idx + 2 + width * 4] != '#')
		return false;
	return true;
}

bool one_check(int idx) {
	for (int i = 1; i < 5; i++)
	{
		if (sig_str[idx + width * i] != '#')
			return false;
	}
	return true;
}

int number_check(int idx) {
	int num;

	if (idx + 2 >= width)
		return 1;

	if (one_check(idx))
		num = 1;
	if (four_check(idx))
		num = 4;
	if (seven_check(idx))
		num = 7;
	if (zero_check(idx))
		num = 0;
	if (two_check(idx))
		num = 2;
	if (three_check(idx))
		num = 3;
	if (five_check(idx))
		num = 5;
	if (six_check(idx))
		num = 6;
	if (nine_check(idx))
		num = 9;
	if (eight_check(idx))
		num = 8;

	return num;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> len >> sig_str;

	width = len / 5;
	int i = 0;
	while (i < width)
	{
		if (sig_str[i] == '#')
		{
			int num = number_check(i);
			answer.push_back('0' + num);

			if (num == 1)
				i += 2;
			else
				i += 4;
		}
		else
			i++;
	}
	cout << answer;
}
