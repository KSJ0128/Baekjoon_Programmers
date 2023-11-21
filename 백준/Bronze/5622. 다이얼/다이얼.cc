#include <iostream>
#include <cstring>
#define MIN 2
#define MAX 15
using namespace std;

int tosec(char alp[],int len)
{
    int num[MAX];
    int sum=0;

    for(int i=0;i<len;i++)//알파벳 숫자로 변환
    {
        if((alp[i]=='A')||(alp[i]=='B')||(alp[i]=='C'))
        num[i]=3;
        else if((alp[i]=='D')||(alp[i]=='E')||(alp[i]=='F'))
        num[i]=4;
        else if((alp[i]=='G')||(alp[i]=='H')||(alp[i]=='I'))
        num[i]=5;
        else if((alp[i]=='J')||(alp[i]=='K')||(alp[i]=='L'))
        num[i]=6;
        else if((alp[i]=='M')||(alp[i]=='N')||(alp[i]=='O'))
        num[i]=7;
        else if((alp[i]=='P')||(alp[i]=='Q')||(alp[i]=='R')||(alp[i]=='S'))
        num[i]=8;
        else if((alp[i]=='T')||(alp[i]=='U')||(alp[i]=='V'))
        num[i]=9;
        else//'w,x,y,z'의 경우
        num[i]=10;
        
        sum+=num[i];
    }

    return sum;
}

int main()
{
    char alp[MAX];//단어 들어갈 배열
    cin>>alp;

    int sec=tosec(alp,strlen(alp));
    cout<<sec<<endl;
}