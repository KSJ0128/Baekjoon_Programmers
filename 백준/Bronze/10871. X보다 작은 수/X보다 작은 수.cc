#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10000

int main()
{
    int number,standard;
    int word[MAX];

    cin>>number>>standard;

    for(int i=0;i<number;i++)
    {
        cin>>word[i];
    }

    for(int i=0;i<number;i++)
    {
        if(word[i]<standard)
        {
            cout<<word[i]<<" ";
        }
    }
}