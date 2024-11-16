#include<iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int T, N;
deque<int> deq;
int num[MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
    
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
            long sum = 0;
            deq.clear();

            cin >> N;

            for (int i = 0; i < N; i++) {
                cin >> num[i];
            }

            for (int i = N-1; i >= 0; i--) {
                if (!deq.empty() && deq.back() < num[i])
                {
                    while (!deq.empty()) {
                        sum += deq.back() - deq.front();
                        deq.pop_front();
                    }
                }
                deq.push_front(num[i]);
            }

            while (!deq.empty()) {
                sum += deq.back() - deq.front();
                deq.pop_front();
            }

            cout << "#" << test_case << " " << sum << '\n';


	}
	return 0;
}