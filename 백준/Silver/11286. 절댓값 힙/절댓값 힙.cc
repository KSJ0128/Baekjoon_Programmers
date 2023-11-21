#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    priority_queue< int, vector<int>, compare > pq;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        if (x != 0)
            pq.push(x);
        else
        {
            if(pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}