#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<21);
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
bool judge(int x,int y){
	if(gcd(x,y)==1) return true;
	return false;
}
int maps[30][30];
ll dp[maxn][30];
int main(){
	for(int i=1;i<=21;i++){
		for(int j=1;j<=21;j++){
			if(judge(i,j)){
				maps[i][j]=1;
			}
		}
	}
	ll num=(1<<21)-1;//��������е㶼�߹������ 
	dp[1][1]=1;//����1����1�ķ�����Ϊ1 
	for(int i=1;i<=num;i++){//i�Ķ����Ʊ�ʾ��û�е����ĳ���������λΪ1��ʾ�������Ϊ0��ʾû����� 
		for(int j=1;j<=21;j++){
			if((i>>(j-1)&1)){//jλ����������ܵ���jλ 
				int q=i-(1<<(j-1)); //�ѵ�jλ�����ɾȥ�󵽴�j�ķ����ж����� 
				for(int k=1;k<=21;k++){
					if(maps[k][j]==1&&((q>>(k-1))&1)==1){//K��j��·���߲��ҵ����k 
						dp[i][j]+=dp[q][k];
					}
				}
			} 
		}
	}
	ll ans=0;
	for(int i=1;i<=21;i++){
		ans+=dp[(1<<21)-1][i];//�����еĶ�����������ж����� 
	}
	cout<<ans<<endl; 
}
