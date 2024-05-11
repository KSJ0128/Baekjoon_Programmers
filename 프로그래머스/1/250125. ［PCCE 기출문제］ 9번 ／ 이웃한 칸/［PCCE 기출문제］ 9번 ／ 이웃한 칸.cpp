#include <string>
#include <vector>

using namespace std;

vector<int> dh = {0,1,-1,0};
vector<int> dw = {1,0,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int len = board.size();
    
    for (int i = 0; i < 4; i++)
    {
        if (h + dh[i] < 0 || h + dh[i] >= len)
            continue;
        if (w + dw[i] < 0 || w + dw[i] >= len)
            continue;
        
        if (board[h + dh[i]][w + dw[i]] == board[h][w])
            answer++;
    }
    
    return answer;
}