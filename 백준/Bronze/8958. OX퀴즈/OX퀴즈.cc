#include <iostream>
#include<cstring>
using namespace std;
#define MAX 80
int countOX(char str[], int len)
{
    int sum = 0;
    int num[MAX];
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'X')
            num[i] = 0;
        else
            num[i] = 1;
    }
    for (int i = 0; i < len-1; i++)
    {
        if ((num[i] != 0) && (num[i + 1] != 0))
        {
            num[i + 1] += num[i];
        }
        sum += num[i];
    }
    sum += num[len - 1];
    return sum;
}
int main()
{
    char str[MAX];
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> str;
        int sum = countOX(str, strlen(str));
        cout << sum << endl;
    }
}