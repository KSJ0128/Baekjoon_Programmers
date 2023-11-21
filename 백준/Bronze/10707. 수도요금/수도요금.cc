#include <iostream>
using namespace std;

int main()
{
    int A,B,C,D,P;
    cin>>A>>B>>C>>D>>P;

    A*=P;//X사의 총 수도요금
    
    if(P>C)//사용량이 C리터를 넘은 경우 추가금 부여
    {
        B+=(P-C)*D;
    }
    
    if(A>=B)
    {
        cout<<B;
    }
    else
        cout<<A;
    return 0;
}