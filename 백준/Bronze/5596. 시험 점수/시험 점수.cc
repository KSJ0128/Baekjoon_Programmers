#include <iostream>
using namespace std;

int main()
{
    int A,B,C,D,SUM;
    cin>>A>>B>>C>>D;
    SUM=A+B+C+D;

    int a,b,c,d,sum;
    cin>>a>>b>>c>>d;
    sum=a+b+c+d;

    if(SUM>=sum)
    {
        cout<<SUM;
    }
    else
    {
        cout<<sum;
    }
    return 0;
}