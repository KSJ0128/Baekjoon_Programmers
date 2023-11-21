#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

    if(A>2)
        cout<<"After";
    else if(A==2)
    {
        if(B>18)
            cout<<"After";
        else if(B==18)
            cout<<"Special";
        else
            cout<<"Before";
    }
    else
        cout<<"Before";

    return 0;
}