#include <iostream>
using namespace std;

int main()
{
    int N; cin>>N;
    int h,t,o;
    int num=0;
    if(N<100)
    {
        cout<<N;
    }
    else
    {
        num=99;
        for(int i=num+1; i<=N;i++)
        {
            h=i/100; t=i%100/10; o=i%10;
            if(h-t==t-o)
            {
                num+=1;
            }
        }
        cout<<num;
    }
    
    return 0;
}