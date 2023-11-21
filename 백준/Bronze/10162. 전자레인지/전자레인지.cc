#include <iostream>
using namespace std;

int main()
{
    int t,a,b,c;
    a=0;b=0;c=0;
    cin>>t;

    if((t%10)!=0)
    {
        cout<<-1;
    }
    else if((t%10)==0)
    {
        for(;t!=0;)
        {
            if(t>299)
            {
                t-=300;
                a+=1;
            }
            else if(t>59)
            {
                t-=60;
                b+=1;
            }
            else if(t>9)
            {
                t-=10;
                c+=1;
            }
        }
        cout<<a<<" "<<b<<" "<<c;
    }
    return 0;
}