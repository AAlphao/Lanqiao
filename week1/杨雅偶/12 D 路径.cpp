#include<iostream>
using namespace std;
int lcm(int x, int y){
	int a,b;
 	a=x;
 	b=y;
 	int z = y;
	while(x%y!=0){
		z = x%y;
		x = y;
		y = z;	
	}
 	return a*b/z;
 }
int main(){
	int lu[3000] = {0};
	for (int i = 2; i <= 2021; i++)
	{
		int M = 100000000;//��ʾ****��ֵҪ���ٵ��㹻�����ٴ��ڸ���𰸣������������ 
		if (i - 21 > 0)//�������21,���i-21��ʼ 
		{
			for (int j = i-21; j < i; j++)
			{
				//���õ�ľ���Ϊ����С�ڵ���21������һ�����̾��루dp[j]) ��������һ��
				//���õ�ľ��루����С��������
				//��̾������������� �������Сֵ 
				M= min(M,lcm(j,i) + lu[j]);
			}
		}
		else
		{
			//�����1��ʼ 
			for (int j = 1; j < i; j++)
			{
				    //ͬ�� 
					M = min(M,lcm(j,i) + lu[j]);
			}
		}
		//�õ����̾���Ϊ��õ���Сֵ 
		lu[i] = M;
	}
	cout << lu[2021];
	return 0;
}
