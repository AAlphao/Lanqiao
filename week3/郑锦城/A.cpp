#include<iostream>
#include<cmath>
using namespace std;
bool judge(int n)
{
    int m;
    while(n>0)
    {
        m=n%10;
        switch (m)
        {
        case 1:
            return true;
            break;
        case 2 :
            return true;
            break;
        case 0:
            return true;
            break;
        case 9:
            return true;
            break;
        default:
            break;
        }
        n/=10;
    }
}
int main()
{
    long long sum=0;
    //�õ�һ����
    for(int i=1;i<=2019;i++)
    {
        //�ж��Ƿ���2��0��1��9
        if(judge(i))
        {
            //�ǵĻ��������ƽ��
            //�����е�ƽ��������
            sum=sum+pow(i,2);
        }
    }
    cout<<sum;
    //�и�����Ŀӣ���sum�����͸�Ϊlong long ����

    return 0;
}
