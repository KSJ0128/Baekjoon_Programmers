#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int N, num, card = 0;
    priority_queue< int, vector<int>, greater<int> > pq;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1)
    {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        card += num1 + num2;
        pq.push(num1 + num2);
    }
    cout << card;
}