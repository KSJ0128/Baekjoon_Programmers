#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int T, K, data;
    long long n1, n2;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        long long cnt = 0;
        cin >> K;
        priority_queue< long long, vector<long long>, greater<long long> > pq;
        for(int j = 0; j < K; j++)
        {
            cin >> data;
            pq.push(data);
        }
        while(pq.size() > 1)
        {
            n1 = pq.top();
            pq.pop();
            n2 = pq.top();
            pq.pop();
            cnt += n1 + n2;
            pq.push(n1 + n2);
        }
        cout << cnt << '\n';
    }
}