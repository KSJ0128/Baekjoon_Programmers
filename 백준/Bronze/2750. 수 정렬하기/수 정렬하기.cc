#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int s = a;
    a = b;
    b = s;
}

void selectionSort(int list[], int N) // 배열을 매개변수로 사용시 주소도 전달됨
{
    for(int i = 0; i < N-1; i++)
    {
        int least = i;

        for(int j = i+1; j < N; j++)
        {
            if(list[j] < list[least])
                least = j;
        }
        swap(list[i], list[least]);
    }

}

int main()
{
    int N;
    cin >> N;

    int number[N];
    
    for(int i = 0; i < N; i++)
        cin >> number[i];

    selectionSort(number, N);
    
    for(int i = 0; i < N; i++)
        cout << number[i] << endl;
}