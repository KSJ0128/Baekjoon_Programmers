#include <iostream>
using namespace std;
int main()
{
    int C; std::cin>>C;
    int score[1000]={0,};
    for(int i=0;i<C;i++)
    {
        double student; std::cin>>student;
        int mean=0.0;
        int percent=0.0;
        for(int j=0;j<student;j++)
        {
            std::cin>>score[j];
            mean+=score[j];
        }
        mean=(double)mean/student;
        for(int j=0;j<student;j++)
        {
            if(score[j]>mean)
            {
                percent++;
            }
        }
        cout<<fixed;
        cout.precision(3);
        cout<<((double)percent/student)*100<<"%"<<endl;
    }
    return 0;
}