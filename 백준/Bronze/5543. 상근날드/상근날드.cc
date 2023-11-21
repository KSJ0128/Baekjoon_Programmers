#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d,e,h,v;
    cin>>a>>b>>c>>d>>e;
    h=a>=b? b: a;
    h=h>=c? c: h;
    v=d>=e? e: d;
    cout<<h+v-50;
    return 0;
}