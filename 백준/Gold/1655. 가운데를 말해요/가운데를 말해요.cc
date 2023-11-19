#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    priority_queue< int, vector<int>, greater<int> > pq_min;
    priority_queue< int, vector<int>, less<int> > pq_max;
    
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> num;
        if (i % 2 == 1)
        {
            if (i == 1 || num <= pq_min.top())
                pq_max.push(num);
            else
            {
                pq_max.push(pq_min.top());
                pq_min.pop();
                pq_min.push(num);
            }
        }
        else
        {
            if (num >= pq_max.top())
                pq_min.push(num);
            else
            {
                pq_min.push(pq_max.top());
                pq_max.pop();
                pq_max.push(num);
            }
        }
        cout << pq_max.top() << '\n';
    }
}