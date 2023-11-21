#include <iostream>
using namespace std;

int main()
{
    int h,m,s,t;
    cin>>h>>m>>s>>t;
    s+=t;
    
    for(;s>59;)
    {
        s-=60;
        m+=1;
        if(m>59)
        {
            m-=60;
            h+=1;
        }
        if(h>23)
        {
            h=0;
        }
    }
    cout<<h<<" "<<m<<" "<<s;
    return 0;
}