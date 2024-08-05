#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int area = 0;

struct Compare {
	bool operator() (pair<int,int> a, pair<int,int> b) const{
		return a.first * a.second > b.first * b.second;
	}
};

void setArea(pair<int,int> a, pair<int,int> b) {
	area = max(area, a.first * a.second + b.first * b.second);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int H, W, N;
	vector< pair<int, int> > sticker;
	cin >> H >> W >> N;

	for (int i = 0; i < N; i++) {
		int R, C;
		cin >> R >> C;

		if ((R <= H && C <= W) || (R <= W && C <= H)) {
			sticker.push_back(make_pair(R, C));
		}
	}

	sort(sticker.begin(), sticker.end(), Compare());

	auto f = sticker.begin(), b = sticker.end();

	b--;
	for (int i = 0; i < sticker.size(); i++) {
		for (int j = i + 1; j < sticker.size(); j++) {

		if (sticker[i].first + sticker[j].first <= H && max(sticker[i].second, sticker[j].second) <= W)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].first + sticker[j].second <= H && max(sticker[i].second, sticker[j].first) <= W)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].second + sticker[j].first <= H && max(sticker[i].first, sticker[j].second) <= W)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].second + sticker[j].second <= H && max(sticker[i].first, sticker[j].first) <= W)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].first + sticker[j].first <= W && max(sticker[i].second, sticker[j].second) <= H)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].first + sticker[j].second <= W && max(sticker[i].second, sticker[j].first) <= H)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].second + sticker[j].first <= W && max(sticker[i].first, sticker[j].second) <= H)
			setArea(sticker[i], sticker[j]);

		else if (sticker[i].second + sticker[j].second <= W && max(sticker[i].first, sticker[j].first) <= H)
			setArea(sticker[i], sticker[j]);
		}
	}

	cout << area;
}
