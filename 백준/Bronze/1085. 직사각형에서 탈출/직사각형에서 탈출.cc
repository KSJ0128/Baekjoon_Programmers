#include <iostream>
using namespace std;

int main()
{
    int x,y,w,h; cin>>x>>y>>w>>h;
    
    int xw = x < w-x ? x : w-x ;
    int yh = y < h-y ? y : h-y ;
    
    if( xw< yh )
        cout<<xw;
    else
        cout<<yh;
}