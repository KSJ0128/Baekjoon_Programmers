#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int h1,m1,s1,h2,m2,s2,h3,m3,s3,h4,m4,s4,h5,m5,s5,h6,m6,s6;
    cin>>h1>>m1>>s1>>h4>>m4>>s4;
    
    s4-=s1;
    if(s4<0)
    {
        s4+=60;
        m4-=1;
    }
    m4-=m1;
    if(m4<0)
    {
        m4+=60;
        h4-=1;
    }
    h4-=h1;
    if(h4<0)
        h4+=24;
    cout<<h4<<" "<<m4<<" "<<s4<<endl;

    cin>>h2>>m2>>s2>>h5>>m5>>s5;
    s5-=s2;
    if(s5<0)
    {
        s5+=60;
        m5-=1;
    }
    m5-=m2;
    if(m5<0)
    {
        m5+=60;
        h5-=1;
    }
    h5-=h2;
    if(h5<0)
        h5+=24;
    cout<<h5<<" "<<m5<<" "<<s5<<endl;

    cin>>h3>>m3>>s3>>h6>>m6>>s6;
    s6-=s3;
    if(s6<0)
    {
        s6+=60;
        m6-=1;
    }
    m6-=m3;
    if(m6<0)
    {
        m6+=60;
        h6-=1;
    }
    h6-=h3;
    if(h6<0)
        h6+=24;
    cout<<h6<<" "<<m6<<" "<<s6<<endl;
    return 0;
}