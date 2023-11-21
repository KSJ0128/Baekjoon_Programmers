#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
/*int main()
{
    stack<int> st;
    int N, num[1000], curNum = 1, index = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> num[i];
        
    while(index < N)
    {
        if (num[index] == curNum)
            curNum++;
        else
            st.push(num[index]);
        
        while(!st.empty() && curNum == st.top())
        {
            st.pop();
            curNum++;
        }
        index++; 
    }

    if (st.empty())
        cout << "NICE";
    else
        cout << "SAD";
}*/
int main()
{
    stack<int> st;
    queue<int> q;
    vector<int> v;
    int N, num, now = 1;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        q.push(num);
    }

    for(int i = 0; i < N; i++)
    {
        if (q.front() == now) // queue
        {
            v.push_back(now++);
            q.pop();
        }
        else if (!st.empty() && st.top() == now) // stack
        {
            v.push_back(now++);
            st.pop();
        }
        else
        {
            st.push(q.front());
            q.pop();
        }
    }

    while (!st.empty()) // stack
    {
        v.push_back(st.top());
        st.pop();
    }

    bool flag = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i+1]) 
        {
            flag = false;
            break;
        }
    }
    if (flag) 
        cout << "Nice";
    else 
        cout << "Sad";
}