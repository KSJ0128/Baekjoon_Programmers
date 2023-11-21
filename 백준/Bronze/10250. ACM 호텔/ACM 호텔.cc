#include <iostream>
using namespace std;

int main()
{
    int t; cin>>t;
    int result[10000]={0,};
    int h, w, n; // h=6, w=12, n=10

    for(int i=0; i<t; i++)
    {
        cin>>h>>w>>n;
        
        int y = n % h ; // 4
        int x = ( n / h ) + 1; // 1+1 = 2
        
        if(y==0)
        {
            x -=1 ;
            y = h;
        }
        
        result[i] = y*100+x;
    }
    
    for(int i=0;i<t;i++)
    {
        cout<<result[i]<<endl;
    }
}