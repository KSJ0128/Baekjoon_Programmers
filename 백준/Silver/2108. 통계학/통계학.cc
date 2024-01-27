#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define MAX 8001

bool cmp(pair<int, int> a, pair<int, int> b) // 최빈
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

// 평균, 중앙, 최빈, 범위(최대 - 최소)
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    double mean = 0, tmp, M = -2147483648, m = 2147483647;
    vector< pair<int, int> > num(MAX, make_pair(0, 0));
    vector<int> med;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;

        mean += tmp; // 평균
        if (M < tmp) // 최대
            M = tmp;
        if (m > tmp) // 최소
            m = tmp;
        int cnt = num[tmp + 4000].second;
        num[tmp + 4000] = make_pair((int)tmp, cnt + 1);
        med.push_back(tmp);
    }

    mean = round(mean / N);
    if (mean == -0)
        cout << 0 << '\n';
    else
        cout << mean << '\n';
    sort(med.begin(), med.end());
    cout << med[N / 2] << '\n'; // 중앙
    sort(num.begin(), num.end(), cmp);
    if (num[0].second == num[1].second) // 최빈
        cout << num[1].first << '\n';
    else
        cout << num[0].first << '\n';
    cout << M - m; // 범위
}
