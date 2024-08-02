#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		unordered_map< string, set<string> > style;
		int n;
		cin >> n;

		if (n == 0) {
			cout << 0 << '\n';
			continue;
		}
		for (int j = 0; j < n; j++) {
			set<string> tmp;
			string name, cloth;
			cin >> name >> cloth;

			if (!style.count(cloth)) {
				tmp.insert(name);
				style[cloth] = tmp;
			}
			else {
				style[cloth].insert(name);
			}
		}

		auto it = style.begin();
		int total = 0;
		while (it != style.end()) {
			if (total == 0){
				total += it->second.size() + 1;
			}
			else {
				total *= (it->second.size() + 1);
			}
			it++;
		}

		cout << total - 1 << '\n';
	}
}