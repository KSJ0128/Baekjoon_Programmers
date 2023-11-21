#include <iostream>
using namespace std;

int main()
{
    int score[6],low1,low2,sum;
    low1=100;low2=100;sum=0;

    for(int i=0;i<6;i++)
    {
        cin>>score[i];
        sum+=score[i];

        if(i<4&&low1>=score[i])
        {
            low1=score[i];
        }
        if(i>=4&&low2>=score[i])
        {
            low2=score[i];
        }
    }
    cout<<sum-low1-low2;
    return 0;
} 