#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<char> s;
    
    while(true)
    {
        bool check = true;
        string str;
        getline(cin, str);
        if(str == ".")
            break;
        
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')')
            {
                if(s.empty())
                {
                    check = false;
                    break;
                }

                if(s.top() == '(')
                    s.pop();
                else
                {
                    check = false;
                    break;
                }
            }
            else if(str[i] == ']')
            {
                if(s.empty())
                {
                    check = false;
                    break;
                }

                if(s.top() == '[')
                    s.pop();
                else
                {
                    check = false;
                    break;
                }
            }
        }

        if(check == false)
            cout << "no" << endl;
        else
        {
            if(s.empty())
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        
        while(!s.empty()) // stack 초기화
            s.pop();
    }

}