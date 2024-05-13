#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    // 캐시 사용할 수 없을 때
    if (cacheSize == 0)
        return cities.size() * 5;
    
    for (int i = 0; i < cities.size(); i++)
    {        
        // 소문자화
        for (int j = 0; j < cities[i].length(); j++)
        {
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] + 32;
        }
        
        if (find(cache.begin(), cache.end(), cities[i]) == cache.end())
        {
            if (cache.size() == cacheSize)
                cache.erase(cache.begin(), cache.begin() + 1);
            answer += 5;
        }
        else
        {
            cache.erase(remove(cache.begin(), cache.end(), cities[i]), cache.end());
            answer += 1;
        }
        
        cache.push_back(cities[i]);
    }
    
    return answer;
}