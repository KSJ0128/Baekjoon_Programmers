#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000000

int main()
{
    int number,max,min;
    int num[MAX];

    cin>>number;

    for(int i=0;i<number;i++)
    {
        cin>>num[i];

    }
    max=num[0];
    min=num[0];

    for(int i=1;i<number;i++)
    {
        if(max<num[i])
        {
            max=num[i];
        }
        if(min>num[i])
        {
            min=num[i];
        }
    }
    cout<<min<<" "<<max;
}