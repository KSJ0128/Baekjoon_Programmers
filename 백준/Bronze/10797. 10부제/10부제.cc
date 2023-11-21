#include <iostream>
using namespace std;

int main()
{
    int car[5],day,num;
    cin>>day;
    num=0;

    for(int i=0;i<5;i++)
    {
        cin>>car[i];
        if(day==car[i])
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}