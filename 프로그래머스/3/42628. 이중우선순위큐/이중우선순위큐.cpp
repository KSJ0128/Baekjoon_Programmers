#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    priority_queue< int, vector<int>, greater<int> > pq_min;
    priority_queue< int, vector<int>, less<int> > pq_max;

    for(int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            if (cnt == 0)
            {
                while (pq_min.size() != 0)
                    pq_min.pop();
                while (pq_max.size() != 0)
                    pq_max.pop();
            }
            
            int num = stoi(operations[i].substr(2));
            pq_min.push(num);
            pq_max.push(num);
            cnt++;
        }
        else if (operations[i][0] == 'D' && cnt != 0)
        {
            if (operations[i][2] == '1')
            {
                pq_max.pop();
                cnt--;
            }
            else
            {
                pq_min.pop();
                cnt--;
            }
        }
    }

    if (cnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }
    return answer;
}