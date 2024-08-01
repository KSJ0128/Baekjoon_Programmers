#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
int main() {
	unordered_map< string, string > member; // 걸그룹 멤버 - 팀
	unordered_map< string, set<string> > group; // 걸그룹 팀 - 멤버 set

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		set<string> people;
		string team, name;
		int num;
		cin >> team >> num; // 걸그룹 이름, 멤버 수

		for (int j = 0; j < num; j++) {
			cin >> name; // 걸그룹 멤버 이름
			member[name] = team; // 멤버 - 팀
			people.insert(name); // 멤버 set
		}
		group[team] = people; // 팀 - 멤버 set
	}

	for (int i = 0; i < M; i++) {
		string name;
		int section;

		cin >> name >> section;
		if (section == 1) {
			unordered_map<string, string>::iterator it = member.find(name);
			cout << it->second << '\n';
		}
		else {
			unordered_map< string, set<string> >::iterator team = group.find(name);
			for (auto iter = team->second.begin(); iter != team->second.end(); iter++)
				cout << *iter << " ";
			cout << '\n';
		}
	}
}