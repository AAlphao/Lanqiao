#include <iostream>
using namespace std;
const int N = 21;
const int M = 1 << N; // 2^21;
long long num[M][N];//״̬�����,���淽��������
bool sign[N][N];
int gcd(int a, int b) //���Լ��
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j <= 21; j++)
            if (gcd(i, j) == 1)         //�������
                sign[i - 1][j - 1] = true; //��ͨ��
    num[1][0] = 1;
    for (int i = 1; i <= M - 1; i++)//����״̬
        for (int j = 0; j <= 20; j++)//�������
            if (i >> j & 1) //���i�ĵ�jλΪ1�����״̬�߹������
                for (int k = 0; k <= 20; k++)
                    if (i - (1 << j) >> k & 1 && sign[k][j]) //��� ʹi�ĵ�jλΪ0����kλΪ1��k��j��ͨ�����״̬����k�ߵ�j�����ġ�
                        num[i][j] += num[i - (1 << j)][k];//����+=��k���������״̬������
    long long ans = 0;
    for (int i = 1; i <= 20; i++)//�����нڵ㶼�߹���״̬��������ͬ�����
        ans += num[M - 1][i];
    cout << ans ;
}
