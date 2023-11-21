#include <iostream>
using namespace std;

int main()
{
    int a,b,c,big,mid,small;
    cin>>a>>b;
    if(a>b)
    {
        big=a;small=b;
        cin>>c;
        if(c>a)
        {
            big=c;mid=a;
        }
        else if(c>b)
        {
            mid=c;
        }
        else
        {
            mid=b;small=c;
        }
    }   
    else
    {
        big=b;small=a;
        cin>>c;
        if(c>b)
        {
            big=c;mid=b;
        }
        else if(c>a)
        {
            mid=c;
        }
        else{
            mid=a;small=c;
        }
    }
    cout<<small<<" "<<mid<<" "<<big;
    return 0;
}