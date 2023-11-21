#include <iostream>
using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    if(B>=45)
    {
        B-=45;
    }
    else
    {
        A-=1;
        
        if(A<0)
           A=23;

        B+=15;
    }
    cout<<A<<" "<<B;

    return 0;
}