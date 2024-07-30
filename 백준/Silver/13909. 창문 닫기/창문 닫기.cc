#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N, idx = 1;
	cin >> N;

	while (pow(idx, 2) <= N)
		idx++;

	cout << idx - 1;
}
