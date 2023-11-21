#include <iostream>
#include <string>
using namespace std;
int main()
{
    int space = 1;

    string s; getline(cin, s, '\n'); 
    // cin으로 입력 받으면 공백 포함 안되므로 getline으로 받기
    
    if(s.length() > 1)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s.at(i) == ' ')
            {  
                if(i != 0 && i != s.length()-1)
                    space += 1;
            }
        }
        cout << space;
    }
    else
    { 
        if(s[0]!=' ')
            cout << 1;
        else
            cout << 0;
    }
       
}