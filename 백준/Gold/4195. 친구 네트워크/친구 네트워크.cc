#include <iostream>
#include <cstring>
#include <unordered_map>
#define MAX 200001
using namespace std;

unordered_map<string, int> names;
int node[MAX];
int cnt[MAX];
int node_size;

void addNode(string a, string b) {
	if (names.find(a) == names.end())
		names[a] = node_size++;

	if (names.find(b) == names.end())
		names[b] = node_size++;
}

int findNode(int idx) {
	if (node[idx] == idx)
        return idx;
	else
    	return node[idx] = findNode(node[idx]);
}

void unionNode(string a, string b) {
	int idx1 = findNode(names[a]);
	int idx2 = findNode(names[b]);

	if (idx1 > idx2)
	{
		node[idx1] = idx2;
		cnt[idx2] += cnt[idx1];
	}
	else if (idx2 > idx1)
	{
		node[idx2] = idx1;
		cnt[idx1] += cnt[idx2];
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		node_size = 1;
		names.clear();
		int F;
		cin >> F;

		// Initialize parent and size arrays
		for (int i = 0; i < MAX; i++) {
			node[i] = i;
			cnt[i] = 1;
		}

		while (F-- > 0) {
			string name1, name2;
			cin >> name1 >> name2;

			addNode(name1, name2);
			unionNode(name1, name2);

			cout << cnt[findNode(names[name1])] << '\n';
		}
	}
}
