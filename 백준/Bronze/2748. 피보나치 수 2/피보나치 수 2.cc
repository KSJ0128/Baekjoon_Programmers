#include <iostream>
using namespace std;

int main()
{
    int n;
    long n2 = 0, n1 = 1, p;

    cin >> n;

    if(n == 0)
        p =0;
    else if( n == 1)
        p = 1;
    else
    {
        for(int i=2; i<=n; i++)
        {
            p = n2 + n1;
            n2 = n1;
            n1 = p;
        }
    }

    cout << p;   
}