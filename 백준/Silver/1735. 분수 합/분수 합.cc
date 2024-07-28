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
	int A, B, C, D; // A / B, C / D
	long long int nume, deno; // 분자, 분모

	cin >> A >> B >> C >> D;

	deno = B * D;
	nume = A * D + B * C;

	long long int gdc = (deno < nume) ? GDC(nume, deno) : GDC(deno, nume);
	nume /= gdc;
	deno /= gdc;

	cout << nume << " " << deno;
}
