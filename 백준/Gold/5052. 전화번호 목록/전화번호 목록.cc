#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t, n;

struct Node {
	bool is_end;
	vector<Node*> child;

	Node() : is_end(false), child(26, NULL) {}
};

struct Trie {
	private :
		Node *root;

		Node *findNode(string &str)
		{
			Node *node = root;

			for (char c : str)
			{
				int idx = c - '0';
				if (!node->child[idx])
				{
					return NULL;
				}
				node = node->child[idx];
			}
			return node;
		}

	public :
		Trie() {
			root = new Node();
		}

		bool	insert(string &str)
		{
			Node *node = root;
			bool overlap = false;
			for (char c : str)
			{
				int idx = c - '0';
				if (!node->child[idx])
				{
					node->child[idx] = new Node();
				}

				if (node->is_end)
				{
					overlap = true;
				}
				node = node->child[idx];
			}
			node->is_end = true;
			return overlap;
		}

		bool	startsWith(string &str)
		{
			Node *node = findNode(str);
			return node != NULL;
		}
};

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		Trie trie;
		bool check = false;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string phone;
			cin >> phone;

			if (trie.startsWith(phone))
				check = true;
			if (check)
				continue;
			if (trie.insert(phone))
				check = true;
		}
		if (check)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

}
