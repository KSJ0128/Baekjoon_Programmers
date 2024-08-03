#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

struct Compare {
	bool operator() (const pair<string,int> &a, const pair<string,int> &b) const{
		if (a.second == b.second) {
			if (a.first.length() == b.first.length())
				return a.first < b.first;
			else
				return a.first.length() > b.first.length();
		}
		else
			return a.second > b.second;
	}
};

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	set< pair<string, int>, Compare> wordbook;
	unordered_map<string, int> words;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		if (word.length() < M)
			continue;

		if (words.find(word) == words.end()) {
			wordbook.insert(make_pair(word, 1));
			words[word] = 1;
		}
		else {
			pair<string, int> key = make_pair(word, words[word]);
			wordbook.erase(key);
			words[word]++;
			wordbook.insert(make_pair(word, words[word]));
		}
	}

	auto it = wordbook.begin();
	while (it != wordbook.end()) {
		cout << it->first << '\n';
		it++;
	}
}
