#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   int a,b;

   while(true)
   {
       cin>>a>>b;
       if(cin.eof())
       {
          break;
        }
        cout<<a+b<<endl;
   }
}