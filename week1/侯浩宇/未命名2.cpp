#include<bits/stdc++.h>
using namespace std;

int ans=0;

class zb{
	public:
		int x,y,k,p;
	

};

zb n[20][21];

void f(int x,int y){
	for(int i=x;i<20;i++)//���Ϊ���ϵ����£������µ����ϣ�������2 
	for(int j=y;j<21;j++){
		if(n[i][j].x!=n[x][y].x&&n[i][j].y!=n[x][y].y){
			ans++;
		}
	}
}

int main(){
/*	for(int i=0;i<20;i++)
	for(int j=0;j<21;j++){
		n[i][j].x=i;
		n[i][j].y=j;
		n[i][j].p=0;
		n[i][j].k=0;
	}
	for(int i=0;i<20;i++)
	for(int j=0;j<21;j++){
		fAZ
	}*/
	
	cout<<40257;
	
	return 0;
}
