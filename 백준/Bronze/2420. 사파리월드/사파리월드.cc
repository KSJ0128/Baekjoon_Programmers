#include <iostream>
using namespace std;

int main()
{
    long long N,M,R;
    cin>>N>>M;
    R=0;

    if(N>M)
    {
        cout<<N-M;
    }
    else if(N==M)
    {
        cout<<0;
    }
    else
    {
        R=N-M;
        R*=-1;
        cout<<R;
    }
    return 0;
}