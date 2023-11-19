#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, M, num;  
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        priority_queue< int, vector<int>, greater<int> > pq_min;
        priority_queue< int, vector<int>, less<int> > pq_max;

        cin >> M;
        cout << (M+1)/2 << '\n';

        for(int j = 1; j <= M; j++)
        {
            cin >> num;
            if (j % 2 == 1)
            {
                if (j == 1 || num <= pq_min.top())
                    pq_max.push(num);
                else
                {
                    pq_max.push(pq_min.top());
                    pq_min.pop();
                    pq_min.push(num);
                }
                if (j % 10 == 0)
                    cout << pq_max.top() << '\n';
                else
                    cout << pq_max.top() << ' ';
            }
            else
            {
                if(num >= pq_max.top())
                    pq_min.push(num);
                else
                {
                    pq_min.push(pq_max.top());
                    pq_max.pop();
                    pq_max.push(num);
                }
            }
        }
        cout << '\n';
    }
}