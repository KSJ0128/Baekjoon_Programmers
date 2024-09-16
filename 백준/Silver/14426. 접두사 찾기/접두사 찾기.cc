#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	vector<Node*> child;
	bool is_end;

	Node() : child(26, NULL), is_end(false) {}
};

class Trie {
	private :
	Node *root;

	// 공통 함수: 주어진 문자열로 끝나는 노드를 찾는다
	Node* findNode(string &prefix) {
		Node* node = root;
		for (char c : prefix) {
			int idx = c - 'a';
			if (!node->child[idx]) {
				return NULL;  // 접두사에 해당하는 경로가 없으면 NULL 반환
			}
			node = node->child[idx];
		}
		return node;
	}

	public :
	Trie() {
		root = new Node();
	}

	// insert 함수 : 트라이 자료구조에 문자열이 존재하지 않으면 추가
	void insert(string &word)
	{
		Node *node = root;
		for (char c : word)
		{
			int idx = c - 'a';
			if (!node->child[idx])
				node->child[idx] = new Node();
			node = node->child[idx];
		}
		node->is_end = true;
	}

	// search 함수: 해당 문자열이 트라이에 존재하는지 확인
	bool search(string &word) {
		Node* node = findNode(word);
	return node != NULL && node->is_end;
	}

	// startsWith 함수: 해당 접두사가 존재하는지 확인
	bool startsWith(string &prefix) {
		Node* node = findNode(prefix);
		return node != NULL;
	}
};

int N, M, cnt = 0;
vector<string> str_set;


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Trie trie;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		trie.insert(str); // 트라이 자료구조에 문자열 저장
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		if (trie.startsWith(str)) // 접두사 있는지 조회
			cnt++;
	}
	cout << cnt;
}
