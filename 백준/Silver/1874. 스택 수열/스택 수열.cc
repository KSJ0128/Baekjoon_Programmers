#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, num, j = 1;
    bool no = true;
    string check = "";
    cin >> n;
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        cin >> num;

        if(s.empty()) // 스택 비어있는 경우
        {
            while(j <= num)
            {
                s.push(j++);
                check += '+';
            }
            s.pop();
            check += '-';
        }
        else // 스택 비어있지 않은 경우
        {
            if(s.top() == num) // top과 num이 같아 바로 pop 가능한 경우
            {
                s.pop();
                check += '-';
            }
            else if(s.top() < num) // top이 num보다 작아 push 필요한 경우
            {
                while(j <= num)
                {
                    s.push(j++);
                    check += '+';
                }
                s.pop();
                check += '-';
            }
            else // top이 num보다 커 에러나는 경우
            {
                no = false;
                continue;
            }
        }
    }

    if(no == false)
        cout << "NO";
    else
    {
        for(int i = 0; i < check.size(); i++)
        {
            cout << check[i] << '\n';
        }
    }
}