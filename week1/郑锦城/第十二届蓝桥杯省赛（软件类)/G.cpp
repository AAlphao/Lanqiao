#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int m;
        for(int i=0;i<n;i++)//����
        {
            cin>>m;//ÿһ�ֵ�ѯ����
            int c[m];
            int sum=0;
            int max1=0;
            for(int j=0;j<m;j++)//���������
            {
                    cin>>c[j];
                    if(c[j]>max1)//�ҳ����������һ��ȥ������1
                    {
                        max1=c[j];
                    }
                    sum^=c[j];
            }
            //ƽ��
            if(sum==0)
            {
                cout<<0;
                continue;
            }else{}
            //��ȡ���λ��1,�������������aӮ������bӮ
            int c1=0;
            while(max1>0)
            {
                max1>>=1;
                c1++;
            }
            int c11=0;
            for(int k=0;k<m;k++)//��c1λ���м���1
            {
                c11+=(c[k]>>c1);
            }
            if(!c11%2)
                {
                    cout<<1;
                }
                else
                {
                    cout<<-1;
                }


        }

    return 0;
}
