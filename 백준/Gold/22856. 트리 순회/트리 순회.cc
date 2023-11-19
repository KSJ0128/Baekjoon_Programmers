#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, Data, Left, Right;
//최초 노드 카운트는 제외해야하기 때문에 -1로 설정
int cnt = -1, Rcnt = -1;

map<int, pair<int, int>> tree;

void input() 
{
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cin >> Data >> Left >> Right;
        //Data가 중복되면 알아서 좌우로 들어간다.
        // 트리에 노드 insert <Data, <left, right>>
        tree[Data].first = Left; 
        tree[Data].second = Right;
    }
}

//flag : 루트노드 기준 좌측 트리 우측트리 구분자
void travel(int node, bool flag) 
{
    //해당노드가 없는 노드라면 함수 리턴
    if (node == -1) 
        return;

    //순회 횟수 증가
    cnt++;

    //좌측 노드 순회
    travel(tree[node].first, 0);

    //우측 노드에 도달했다면 우순회 횟수 증가
    if (flag) 
    {
        //우측트리 우측 노드 방문 횟수 카운트
        Rcnt++;
        travel(tree[node].second, 1);
    }
    else 
    {
        travel(tree[node].second, 0);
    }
}

int main() 
{
    input();
    travel(1, 1);
    printf("%d", 2 * cnt - Rcnt);
}