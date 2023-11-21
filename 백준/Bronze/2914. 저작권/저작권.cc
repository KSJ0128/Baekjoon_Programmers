#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int song, mean, melody;
    cin>>song>>mean;
    melody=song*(mean-1)+1;
    cout<<melody;
}