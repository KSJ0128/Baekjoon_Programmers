#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    cin>>x;

    if((x-1)%8==0)
        cout<<1;
    else if((x-2)%8==0||x%8==0)
        cout<<2;
    else if((x-3)%8==0||(x-7)%8==0)
        cout<<3;
    else if((x-4)%8==0||(x-6)%8==0)
        cout<<4;
    else 
        cout<<5; 

    return 0;
}