#include <iostream>
using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    B+=C;
    for(;B>59;)
    {
        if(B>59)
        {
            B-=60;
            A+=1;
            if(A>23)
            {
                A=0;
            }
        }
    }
    cout<<A<<" "<<B;

    return 0;
}