#include <iostream>
using namespace std;
int main()
{
    int arr[100][100] = {0,};
    int x, y, d;
    cin >> x >> y;
    for(int k = 0; k < 2; k++)
    {
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                cin >> d;
                arr[i][j] += d;
            }
        }
    }
    for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                cout << arr[i][j];
                if(j != y - 1)
                    cout << " ";
            }
            if(i != x - 1)
                    cout << endl;
        }
}