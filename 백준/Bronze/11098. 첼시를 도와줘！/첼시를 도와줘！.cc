#include <iostream>
using namespace std;
int main()
{
    int n, p, C1, C2;
    string name1, name2, name[100];

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p; // 테스트 케이스 개수 만큼 선수의 수 입력 받음

        for(int j = 0; j < p; j++)
        {
           cin >> C1 >> name1;
           
           if(C1 > C2)
           {
               name2 = name1;
               C2 = C1;
           }
        }
        name[i] = name2;
        C2 = 0;
    }

    for(int i = 0; i < n; i++)
    {
        cout << name[i] << endl;
    }
}