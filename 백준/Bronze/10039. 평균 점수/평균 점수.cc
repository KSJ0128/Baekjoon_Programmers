#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int score=0;
    int mean=0;
    
    for(int i=0;i<5;i++)
    {
        cin>>score;

        if(score<40)
        {
            score=40;
        }
        mean+=score;
    }
    cout<<mean/5;
}