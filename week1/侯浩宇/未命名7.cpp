#include<bits/stdc++.h>
using namespace std;

char xorr(char a,char b){//��� 
	if(a==b)
	return '0';
	else 
	return '1';
}

string ans[10001],ans2;

string startA="0",startB="0";

int maxx[1000],p=0,l_n[10001],num=0;
void maxlength(int i){//�ж������ 
//	cout<<"maxx:"<<maxx<<"ans:"<<ans<<endl; 
	if(maxx[num]==ans[i].length()){
//		p++;
		l_n[num]++;
	}
	
	if(maxx[num]<ans[i].length()){
		maxx[++num]=ans[i].length();
//		p=1;
		l_n[num]=1;
	}

	
}


void erjinzhi(int x,int i){//ת������ 
	double p=0;
	ans[i]="";
	while(x){
		int x1=x%2;
		ans[i]+=char(x1+48);//ans Ϊ���ŵĶ�������   ʹ��β���� 
		maxlength(i);
		p++;
		x/=2;
	}

}

int n,x[200000];

void notonly(){
	
	if(l_n[num]==1){
		cout<<1;//��Ψһ�������������A���A�����AӮ 
		return;
	}
	
	if(l_n[num]==0){
		cout<<0;//ֻ��0�������䣬ƽ�� 
		return;
	}	
	
	for(int i=0;i<n;i++){
		if(ans[i].length()==maxx[num]){
			for(int j=0;j<ans[i].length();j++){
				startA[j]=xorr(ans[i][j],startA[j]);
			}
		}
	}
	
	if(startA[maxx[num]]>startB[maxx[num]]){
		cout<<1;
		return;
	}
	
	if(startA[maxx[num]]<startB[maxx[num]]){
		cout<<-1;
		return;
	}
	
	num--;
	notonly();
	
}



void yihuo(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
		
		if(x[i]>0)
		    erjinzhi(x[i],i);
	}
	

	
	notonly();
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		yihuo();
		
	}
	
//erjinzhi(4);	

	return 0;
}
