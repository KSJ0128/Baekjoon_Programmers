#include <iostream>
using namespace std;

int main()
{
    int L,A,B,C,D,k,m;
    cin>>L>>A>>B>>C>>D;
    k=A/C;m=B/D;
    if(k>m)
    {
        if(A%C==0)
            cout<<L-k;
        else
            cout<<L-(k+1);
    }
    else
    {
        if(B%D==0)
            cout<<L-m;
        else
            cout<<L-(m+1);
    }
    return 0;
}