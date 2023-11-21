#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nRank;
vector<int> arr;

int binSrch(int num)
{
    int left = 0, right = nRank.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(num == nRank[mid])
            return mid;
        else if(num < nRank[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
        nRank.push_back(num);
    }

    sort(nRank.begin(), nRank.end());
    nRank.erase(unique(nRank.begin(), nRank.end()), nRank.end());
    
    for(int i = 0; i < N; i++)
        cout << binSrch(arr[i]) << '\n';
}