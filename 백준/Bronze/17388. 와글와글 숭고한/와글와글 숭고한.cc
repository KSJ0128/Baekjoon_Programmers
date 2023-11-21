#include <iostream>
using namespace std;

int main()
{
    int S,K,H,low;
    cin>>S>>K>>H;

    if(S+K+H<100)
    {
        low=S>=K? K: S;
        low=low>H? H:low;
        
        if(low==S)
            cout<<"Soongsil";
        else if(low==K)
        {
            cout<<"Korea";
        }
        else if(low==H)   
            cout<<"Hanyang";
        
    }
    else
        cout<<"OK";
    return 0;
} 