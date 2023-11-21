#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // 시간 절약
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stickCount = 0, laserCount = 0;
    stack<char> s;
    stack<int> laser;

    string str = "";
    cin >> str;

    for(int i = 0; i < str.size(); i++) // 괄호 문자열 하나씩
    {
        if(str[i] == '(')
        {
            s.push('(');

            if(str[i-1] == '(')
            {
                laser.push(laserCount);
                laserCount = 0;
            }
        }
        else 
        {
            s.pop();

            if(str[i-1] == '(')
            {
                laserCount++;

                if(s.empty())
                    laserCount = 0;
            }
            else // laser 아닐 때
            {
                stickCount += laserCount + 1;

                if(s.empty())
                {
                    laserCount = 0;
                }
                else
                {
                    if(!laser.empty())
                    {
                        laserCount += laser.top();
                        laser.pop();
                    }
                }
            }
        }
    }
    cout << stickCount;
}