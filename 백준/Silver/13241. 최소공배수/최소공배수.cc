#include <iostream>
using namespace std;

long long int GDC(long long int big, long long int small) {
	long long int tmp;

	while (big % small != 0) {
		tmp = big;
		big = small;
		small = tmp % big;
	}
	return small;
}

int main() {
	long long int A, B, gdc;
	cin >> A >> B;

	gdc = (A > B) ? GDC(A, B) : GDC(B, A);
	cout << A * B / gdc;
}