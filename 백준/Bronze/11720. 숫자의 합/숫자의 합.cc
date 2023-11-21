#include <iostream>
using namespace std;

int main()
{
    int n=0; //숫자의 개수
    cin >> n;
    char number[n]; //숫자 저장할 배열, 문자열로 입력받아 한 글자씩 배열에 저장.
    cin >> number; // 숫자 문자열 형태로 입력 받음
    
    int num = 0; // 숫자 합계
    
    for( int i = 0; i < n; i++)
    {
        num += number[i]-'0'; // 문자열 형식이기 떄문에 '0'을 뺀 값이 숫자로 들어감
        // ex) '4'-'0' = 4
    }
    
    cout << num<<endl;
}