#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000000

int main()
{
    int nine[9];
    int max=0;
    int number;
    
    for(int i=0;i<9;i++)
    {
        cin>>nine[i];
        
        if(max<nine[i])
        {
            max=nine[i];
            number=i+1;
        }
    }
    cout<<max<<endl<<number;
}