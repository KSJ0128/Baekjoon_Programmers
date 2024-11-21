#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

map<int, set<int> > dList;
unordered_map<int,int> pList;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int P, L;
		cin >> P >> L;

		dList[L].insert(P);
		pList[P] = L;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			int P, L;
			cin >> P >> L;

			dList[L].insert(P);
			pList[P] = L;
		}
		else if (cmd == "recommend") {
			int x;
			cin >> x;

			if (x == 1) {
				auto it = dList.rbegin();
                while (it != dList.rend() && it->second.empty()) // 비어 있는 set은 건너뜀
                    it++;
				cout << *it->second.rbegin() << '\n';
			}
			else {
				auto it = dList.begin();
            	while (it != dList.end() && it->second.empty()) // 비어 있는 set은 건너뜀
                	it++;
				cout << *it->second.begin() << '\n';
			}
		}
		else  {
			int P;
			cin >> P;

			int L = pList[P];
			pList.erase(P);

			dList[L].erase(P);
		}
	}

}
