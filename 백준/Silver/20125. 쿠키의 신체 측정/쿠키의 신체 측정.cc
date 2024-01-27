#include <iostream>
#include <vector>

using namespace std;
#define MAX 1001
char cookie[MAX][MAX]; // 0 ~ 1001
int main()
{
    int N, l_arm = 0, r_arm = 0, l_leg = 0, r_leg = 0, waist = 0;
    int h_x = 0, h_y = 0, w_x, w_y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> cookie[i][j]; // i = 행, j = 열

    for(int i = 1; i <= N; i++) // 심장 찾기
    {
        for(int j = 1; j <= N; j++)
        {
            if(cookie[i][j] == '*' && i-1 >= 1 && j-1 >= 1 && i+2 <= 1000 && j+1 <= 1000)
            {
                if(cookie[i-1][j] == '*' && cookie[i][j-1] == '*' &&
                        cookie[i][j+1] == '*' && cookie[i+1][j] == '*')
                {
                    h_x = i;
                    h_y = j;
                    break;
                }
            }
        }
        if (h_x != 0 && h_y != 0)
            break;
    }

    int tmp = h_y;
    while (--tmp >= 1 && cookie[h_x][tmp] == '*')
        l_arm++;

    tmp = h_y;
    while (++tmp <= 1000 && cookie[h_x][tmp] == '*')
        r_arm++;

    tmp = h_x;
    while (++tmp <= 1000 && cookie[tmp][h_y] == '*')
        waist++;

    w_x = h_x + waist;
    w_y = h_y;

    tmp = w_x;
    while (++tmp <= 1000 && cookie[tmp][w_y-1] == '*')
        l_leg++;

    tmp = w_x;
    while (++tmp <= 1000 && cookie[tmp][w_y+1] == '*')
        r_leg++;

    cout << h_x << " " << h_y << '\n';
    cout << l_arm << " " << r_arm << " " << waist << " " << l_leg << " " << r_leg ;
}