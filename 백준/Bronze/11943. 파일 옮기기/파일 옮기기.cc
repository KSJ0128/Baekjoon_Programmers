#include <iostream>
using namespace std;

int main()
{
    int A,B,C,D;
    cin>>A>>B>>C>>D;

    if(A+D>=B+C)
        cout<<B+C;
    else 
        cout<<A+D;
    return 0;
}