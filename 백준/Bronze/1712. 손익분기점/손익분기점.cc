#include <iostream>
using namespace std;

int main()
{
    int fix,flow,price;
    cin>>fix>>flow>>price;
    if(flow>=price)
        cout<<"-1";
    else
    {
        cout<<fix/(price-flow)+1;
    }
}