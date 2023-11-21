#include <iostream>
using namespace std;
#define Max 333334

int main()
{
    int d1,d2,d3;
    cin>>d1>>d2>>d3;

    if(d1==d2&&d2==d3&&d3==d1)//666
    {
        cout<<10000+d1*1000;
    }
    else if(d1==d2||d2==d3||d3==d1)//336
    {
        if(d1==d2)
            cout<<1000+d2*100;
        else if(d2==d3)
            cout<<1000+d2*100;
        else
            cout<<1000+d1*100;
    }
    else if(d1!=d2&&d2!=d3&&d3!=d1)//345
    {
        if(d1>d2)
        {
            if(d2>d3)
                cout<<d1*100;
            else
                {d1=d1>d3? d1: d3;
                cout<<d1*100;}
        }
        else if(d1<d2)
        {    if(d1>d3)
                cout<<d2*100;
            else    
                {
                    d2=d2>d3? d2: d3;
                cout<<d2*100;
                }
        }
    }

    return 0;
}