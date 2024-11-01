#include <iostream>
#include <string>
using namespace std;

int S, P, a_cnt, c_cnt, g_cnt, t_cnt;
string dna_str;

void input() {
	cin >> S >> P >> dna_str;
	cin >> a_cnt >> c_cnt >> g_cnt >> t_cnt;
}

bool check(int a_num, int c_num, int g_num, int t_num) {
	if (a_num < a_cnt || c_num < c_cnt || g_num < g_cnt || t_num < t_cnt)
		return false;
	return true;
}

void init(string *sub_str, int *a_num, int *c_num, int *g_num, int *t_num) {
	*(sub_str) = dna_str.substr(0, P);

	for (char c : *(sub_str)) {
		if (c == 'A')
			(*a_num)++;
		else if (c == 'C')
			(*c_num)++;
		else if (c == 'G')
			(*g_num)++;
		else
			(*t_num)++;
	}
}

void setting(int idx, int *a_num, int *c_num, int *g_num, int *t_num) {
	if (dna_str.at(idx-P) == 'A')
		(*a_num)--;
	else if (dna_str.at(idx-P) == 'C')
		(*c_num)--;
	else if (dna_str.at(idx-P) == 'G')
		(*g_num)--;
	else
		(*t_num)--;

	if (dna_str.at(idx) == 'A')
		(*a_num)++;
	else if (dna_str.at(idx) == 'C')
		(*c_num)++;
	else if (dna_str.at(idx) == 'G')
		(*g_num)++;
	else
		(*t_num)++;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int cnt = 0;
	string sub_str;
	int a_num = 0, c_num = 0, g_num = 0, t_num = 0;

	// init
	for (int i = 0; i < P; i++) {
		if (dna_str[i] == 'A') a_num++;
		else if (dna_str[i] == 'C') c_num++;
		else if (dna_str[i] == 'G') g_num++;
 		else if (dna_str[i] == 'T') t_num++;
	}

	if (check(a_num, c_num, g_num, t_num))
		cnt++;

	for (int i = P; i < S; i++) {
		setting(i, &a_num, &c_num, &g_num, &t_num);

		if (check(a_num, c_num, g_num, t_num))
			cnt++;
	}

	cout << cnt;
}