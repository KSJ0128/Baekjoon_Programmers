#include <iostream>
#include <vector>
#include <algorithm>
#define MAX = 20;
using namespace std;

int N, S;
int cnt = 0;
vector<int> seq;

void counting(int sum, int i) {
	if (i >= N)
		return ;
	else
	{
		counting(sum, i+1);
		if (sum + seq[i] == S) {
			cnt++;
			// cout << i << endl;
		}
		counting(sum + seq[i], i+1);
	}
	// cout << "case\n";
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		seq.push_back(num);
	}

	sort(seq.begin(), seq.end());
	counting(0, 0);

	cout << cnt;
}
