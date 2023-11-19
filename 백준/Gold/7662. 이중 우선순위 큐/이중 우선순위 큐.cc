#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int T, k;
    string operations;
    cin >> T;
    for(int j = 0; j < T; j++)
    {
        int cnt = 0;
        map<int, int> check;
        priority_queue< int, vector<int>, greater<int> > pq_min;
        priority_queue< int, vector<int>, less<int> > pq_max;

        cin >> k;
        cin.ignore();
        for(int i = 0; i < k; i++)
        {
            getline(cin, operations);
            if (operations[0] == 'I')
            {
                if (cnt == 0)
                {
                    while (!pq_min.empty())
                        pq_min.pop();
                    while (!pq_max.empty())
                        pq_max.pop();
                }
                int num = stoi(operations.substr(2));
                pq_min.push(num);
                pq_max.push(num);
                check[num]++;
                cnt++;
            }
            else if (operations[0] == 'D' && cnt != 0)
            {
                int num = stoi(operations.substr(2));
                if (num == 1)
                {
                    if(!pq_max.empty())
                    {
                        check[pq_max.top()]--;
                        pq_max.pop();
                    }
                    while(!pq_min.empty() && check[pq_min.top()] == 0)
                    {
                        pq_min.pop();
                    }
                    while(!pq_max.empty() && check[pq_max.top()] == 0)
                    {
                        pq_max.pop();
                    }
                }
                else
                {

                    if(!pq_min.empty())
                    {
                        check[pq_min.top()]--;
                        pq_min.pop();
                    }
                    while(!pq_min.empty() && check[pq_min.top()] == 0)
                    {
                        pq_min.pop();
                    }
                    while(!pq_max.empty() && check[pq_max.top()] == 0)
                    {
                        pq_max.pop();
                    }
                }
                cnt--;
            }
        }
        if (cnt == 0)
            cout << "EMPTY" << '\n';
        else
            cout << pq_max.top() << " " << pq_min.top() << '\n';
    } 
}