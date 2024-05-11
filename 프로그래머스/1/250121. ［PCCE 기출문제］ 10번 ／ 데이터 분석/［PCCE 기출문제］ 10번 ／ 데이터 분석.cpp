#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int split_i;
int sort_i;

bool compare(vector<int> data1, vector<int> data2)
{
    return data1[sort_i] < data2[sort_i];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    if (ext == "code")
        split_i = 0;
    else if (ext == "date")
        split_i = 1;
    else if (ext == "maximum")
        split_i = 2;
    else if (ext == "remain")
        split_i = 3;
    
    if (sort_by == "code")
        sort_i = 0;
    else if (sort_by == "date")
        sort_i = 1;
    else if (sort_by == "maximum")
        sort_i = 2;
    else if (sort_by == "remain")
        sort_i = 3;
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][split_i] < val_ext)
            answer.push_back(data[i]);
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}