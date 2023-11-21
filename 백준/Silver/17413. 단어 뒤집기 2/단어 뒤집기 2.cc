#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<char> que;
    stack<char> s;
    string S;

    getline(cin,S);

    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == '<') // tag 출력
        {
            while(S[i] != '>')
                cout << S[i++];
            cout << S[i];
        }
        else // 단어, 공백 출력
        {
            while(i < S.size())
            {
                if(S[i] == '<')
                {
                    i--;
                    break;
                }
                else if(S[i] == ' ')
                    break;
                s.push(S[i++]); // 역출력
            }
            
            while(!s.empty()) // 단어 끝났을 때
            {
                cout << s.top();
                s.pop();
            }
            
            if(S[i] == ' ')
            {
                cout << ' ';
            }
        }
    }
}