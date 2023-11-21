#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c,num;
    int check[10]={0,};
    
    cin>>a>>b>>c;
    num=a*b*c;
    string s=to_string(num);
    int n=s.size();
    
   for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
            check[0]+=1;
        else if(s[i]=='1')
            check[1]+=1;
        else if(s[i]=='2')
            check[2]+=1;
        else if(s[i]=='3')
            check[3]+=1;
        else if(s[i]=='4')
            check[4]+=1;
        else if(s[i]=='5')
            check[5]+=1;
        else if(s[i]=='6')
            check[6]+=1;
        else if(s[i]=='7')
            check[7]+=1;
        else if(s[i]=='8')
            check[8]+=1;
        else if(s[i]=='9')
            check[9]+=1;
    }
    
    for(int i=0;i<10;i++)
    {
        cout<<check[i]<<endl;
    }
    return 0;
}
