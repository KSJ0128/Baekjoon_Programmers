#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   int num,t,o,sum,cycle;

   cin>>sum;//수 입력받기
   num=sum;

   while(true)
   {
       cycle+=1;
       t=sum/10;//6만드는과정
       o=sum%10;//8만드는과정
       if(o*10+(t+o)%10==num)
       {
           break;
       }

       sum=o*10+(t+o)%10;//6+8=68 만드는 과정
   }
   cout<<cycle;
}