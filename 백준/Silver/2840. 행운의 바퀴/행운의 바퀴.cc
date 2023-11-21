#include <iostream>
#include <list>
using namespace std;
int main()
{
    int N, K, count, top = 0; // 바퀴 칸 수, 바퀴 돌리는 횟수, 글자 바뀌는 횟수
    char alphabet; // 가리키는 글자
    bool check = true, overlap[26] = {false};
    list<char> wheel(25);
    list<char>:: iterator iter;

    cin >> N >> K;

    for(int i = 0; i < K; i++)
    {
        cin >> count >> alphabet;
        top = (top + count) % N; // top 초기화

        int j = 0;
        iter = wheel.begin();

        while(j < top) // iter 초기화
        {
            j++; iter++; 
        }

        if(*iter == 0) // 룰렛 위치가 비어있을 때
        {
            if(overlap[alphabet - 'A'] == true) // 알파벳 중복인 경우
                check = false;
            else // 알파벳 중복 아닌 경우
            {
                overlap[alphabet - 'A'] = true;
                *iter = alphabet;
            }
        }
        else if (*iter == alphabet) // 룰렛 위치에 같은 알파벳이 차 있을 때
        {
            continue;
        }
        else // 룰렛 위치에 다른 알파벳이 차 있을 때
            check = false;
    }

    if(check == false) // 잘못된 바퀴인 경우
        cout << "!";
    else 
    {
        for(int i = 0, j = top; i < N; i++) // 바퀴 개수 만큼
        {
            if(*iter == 0) // 룰렛 비어있을 때
                cout << "?";
            else // 룰렛 차 있을 때
                cout << *iter;

            if(j == 0)
            {
                while(j != N-1)
                {
                    iter++;
                    j++;
                }
            }
            else
            {
                iter--;
                j--;
            }
        }
    }
}