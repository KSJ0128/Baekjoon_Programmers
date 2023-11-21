#include <iostream>
#include <queue>
using namespace std;
const int SIZE = 1000;
int main()
{
    queue<int> q;
    int josephus[SIZE];
    int top = 0, n, k;
    cin >> n >> k; 
    
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        for(int i = 0; i < k-1; i++)
        {   
            q.push(q.front());
            q.pop(); 
        }
        josephus[top++] = q.front();
        q.pop();
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            if(n == 1)
                cout << "<" << josephus[0] << ">";
            else
                cout << "<" << josephus[i] << ", ";
        }
        else if(i == n-1)
            cout << josephus[i] << ">";
        else 
            cout << josephus[i] << ", ";
    }
}