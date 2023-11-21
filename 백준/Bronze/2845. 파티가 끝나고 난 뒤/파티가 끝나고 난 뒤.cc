#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int people, square, a,b,c,d,e;
    cin>>people>>square;
    people*=square;
    cin>>a>>b>>c>>d>>e;
    cout<<a-people<<" "<<b-people<<" "<<c-people<<" "<<d-people<<" "<<e-people;
}