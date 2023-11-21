#include <iostream>
using namespace std;

const int MAX_STACK=100000;//스택 최대 크기

class stack {
    int top;
    int data[MAX_STACK];
    int money;

    public:
    stack() { top = -1, money=0; }

    void push(int a)
    {
        data[++top]=a;
    }

    void pop(int a)
    {
        top-=1;
    }

    int sum(int a)
    {
        for(int i=0;i<=top;i++)
        {
            money+=data[i];
        }
        return money;
    }
};

int main()
{
    int K,m;
    stack zero;
    cin>>K;//줄의 개수

    for(int i=0;i<K;i++)
    {
        cin>>m;//돈의 금액

        if(m==0)
        {
            zero.pop(m);
        }
        else
        {
            zero.push(m);
        }
    }

    cout<<zero.sum(K)<<endl;

}