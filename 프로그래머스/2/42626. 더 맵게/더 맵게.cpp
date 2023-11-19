#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int cnt = 0, score = 0;
    priority_queue< int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());

    while (pq.top() < K)
    {
        if (pq.size() < 2)
            break;
        score = pq.top();
        pq.pop();
        score += pq.top() * 2;
        pq.pop();
        pq.push(score);
        cnt++;
    }
    if (pq.top() >= K)
        return cnt;
    else
        return -1;
}