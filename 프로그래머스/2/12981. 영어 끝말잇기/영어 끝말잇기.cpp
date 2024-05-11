#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> visit;
    string past;
    string now;
    
    visit.push_back(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        past = words[i - 1];
        now = words[i];
            
        if (past.back() != now[0])
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        
        if (find(visit.begin(), visit.end(), now) != visit.end())
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        
        visit.push_back(now);
    }
    
    if (answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}