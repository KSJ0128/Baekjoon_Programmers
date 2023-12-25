#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int cnt = 0;
	int anagram1[26] = {0,}, anagram2[26] = {0,};
	string word1, word2;

	cin >> word1 >> word2;

	for (int i = 0; i < word1.length(); i++)
		anagram1[word1[i] - 'a'] += 1;

	for (int i = 0; i < word2.length(); i++)
		anagram2[word2[i] - 'a'] += 1;

	for (int i = 0; i < 26; i++)
	{
		if (anagram1[i] != anagram2[i])
			cnt += abs(anagram1[i] - anagram2[i]);
	}

	cout << cnt;
}