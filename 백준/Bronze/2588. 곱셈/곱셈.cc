#include <iostream>
using namespace std;

int main()
{
    int A,B,C,D,E,F,G;
    cin>>A>>B;
    C=A*(B%10);
    D=A*((B%100)/10);
    E=A*(B/100);
    G=C+D*10+E*100;
    cout<<C<<endl<<D<<endl<<E<<endl<<G;
    
    return 0;
}