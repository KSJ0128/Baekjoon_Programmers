#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A,B,C;
    double root,rate;
    cin>>A>>B>>C;
    root=sqrt(pow(B,2)+pow(C,2));
    rate=A/root;
    B*=rate;
    C*=rate;
    cout<<B<<" "<<C;

    return 0;
}