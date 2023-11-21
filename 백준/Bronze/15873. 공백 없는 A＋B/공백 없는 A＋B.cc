#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a;
    
    b=a/10;
    c=a%10;
    
    if(c==0)
    {
        b/=10;
        c=10;
    }
    a=b+c;
    cout<<a;
    return 0;
}