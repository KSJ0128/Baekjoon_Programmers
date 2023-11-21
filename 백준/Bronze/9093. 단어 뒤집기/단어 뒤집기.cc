#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string str;
    int T;
    cin >> T;
    cin.ignore();

    for(int i = 0; i < T; i++)
    {
        getline(cin, str);
        string reverse = "";

        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] != ' ')
            {
                s.push(str[j]);

                if(j == str.size() - 1)
                {
                    while(!s.empty())
                    {
                        reverse += s.top();
                        s.pop();
                    }
                }
            } 
            else// 공백 입력된 경우
            {
                while(!s.empty())
                {
                    reverse += s.top();
                    s.pop();
                }
                reverse += ' ';
            }
        }
        cout << reverse << endl;
    }
}