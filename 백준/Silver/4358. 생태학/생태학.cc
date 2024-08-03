#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
#include <set>
#include <cmath>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	unordered_map<string, double> tree;
	set<string> type;

	while (1) {
		string tmp;
		getline(cin, tmp);

		if (cin.eof()) break;

		cnt++;
		if (type.find(tmp) != type.end())
			tree[tmp] += 1.0;
		else {
			type.insert(tmp);
			tree[tmp] = 1.0;
		}
	}

	cout << fixed << setprecision(4);

	auto it = type.begin();
	while (it != type.end()) {
		cout << *it << " " << round(tree[*it] / cnt * 100.0 * 10000.0) / 10000.0 << '\n';
		it++;
	}
}
