#include <iostream>
using namespace std;

long long mult(long long A, long long B, long long C)
{
    if(B == 1)
        return A % C;
    else
    {
        long long result = mult(A, B/2, C);
        result = (result * result) % C;
        if(B % 2 == 0)
            return result;
        else
            return (result * A) % C;
    }
}

int main()
{
    long long A, B, C; // A: 곱하는 수, B: 곱할 횟수, C: 모듈러
    cin >> A >> B >> C;

    cout << mult(A, B, C);
}