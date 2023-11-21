#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num=0;
    int check[10]={0,};
    int check2[42]={0,};

    for(int i=0;i<10;i++)
    {
        cin>>check[i];
        check[i]%=42;
    }

   for(int i=0;i<42;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(check[j]==i)
            {
                check2[i]+=1;
            }
        }
    }
    
    for(int i=0;i<42;i++)
    {
        if(check2[i]!=0)
        {
            num+=1;
        }
    }
    cout<<num;
    return 0;
}