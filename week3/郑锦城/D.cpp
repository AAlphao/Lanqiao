#include<bits/stdc++.h>
using namespace std;

int a[100][100],v[100][100];//��ͼ����������

struct point
{
    int x;
    int y;
    int step;
};
queue<point> r;//������У���Ӻͳ���
//���򣬷ֱ�Ϊ��������
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main()
{

    //����
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int startx,starty,p,q;
    cin>>startx>>starty>>p>>q;
    //bfs

    point start;
    start.x=startx;
    start.y=starty;
    start.step=0;

    r.push(start);//�������ӣ�push��һ������
    v[startx][starty]=1;
    int flag = 0;
    while(!r.empty())
    {
        int x = r.front().x;
        int y = r.front().y;
        if(x == p && y == q)//�յ�����
        {
            flag = 1;
            cout<<r.front().step;
            //�ҵ��������˳�������һ������С��
            break;
        }
        for(int k=0;k<=3;k++)//�ĸ�����
        {
            int tx,ty;
            tx = x + dx[k];
            ty = y + dy[k];
            if(a[tx][ty] == 1 /*�յ�*/ && v[tx][ty] == 0/*δ����*/)
            {
                //���
                point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = r.front().step + 1;
                r.push(temp);
                v[tx][ty]=1;
            }
        }
        r.pop();//��չ���˽�����Ԫ�س���
    }
    if(!flag)
    {
        cout<<"no answer!";
    }
    return 0;
}
