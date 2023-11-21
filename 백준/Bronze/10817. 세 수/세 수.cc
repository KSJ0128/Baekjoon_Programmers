#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int max, mid;
    cin>>a>>b>>c;
    
    mid = a > b ? a : b;
    max = mid > c ? mid : c; // max 정해짐
    
   if(max == a)
   {
       mid = b > c ? b : c;
       cout<<mid;
   }
    else if( max == b)
    {
        mid = a > c ? a : c;
        cout<<mid;
    }
    else
    {
        cout<<mid;
    }
}
