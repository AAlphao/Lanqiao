#include<bits/stdc++.h>
using namespace std;

//��ΪN���ܴﵽ100000������֮��һ��ѭ�� 
//��α�֤ÿһʱ��ÿ�ҵ����޶��������ȼ���һ�أ�
//ֻ�ܼ�¼��һ���ж�����������ж�Զ�� 

//����Խṹ���pair�涩����cun[N]���������; 2*N��С 
//����ǰ�vector<int> cun[N] ÿ��ʱ����Ӧ���������� �ռ�ռ�ø��� 
//**********�������ڴ洢��ʽ��ͬ����ʱ�临�ӶȵĲ�ͬ��������Ϊ��Ҫ�����ж�������һ�飡
const int N = 100005;
typedef pair<int, int> pir; 

int main() {
	int res = 0;
	int n, m, t;//n�������꣬m�У���tʱ��
	cin >> n >> m >> t;
	vector<pair<int,int> > val(m);//val��¼����
	vector<int> shop(n, 0);//shop��¼ÿ�ҵ��ʱ�����ȼ� 
	vector<bool> judge(n, false);//judge��¼ÿ�ҵ��ʱ�Ƿ���뻺��
	vector<int> record(n, 0);//record��¼��һ���ж�����ʲôʱ�� 
	 
	int ts, id;
	for(int i = 0; i < m; i++){
		cin >> ts >> id;
		val[i] = pir(ts,id);
	} 
	sort(val.begin(), val.end());
//	for(int i = 0; i < m; i++){
//		cout << val[i].first << " " << val[i].second << endl;
//	}
	
	for(int i = 0; i < m; i++){
		int t = val[i].first, d = val[i].second;//tʱ��d������
		if(t != record[d]) shop[d] = shop[d] - (t-record[d]-1);
		if(shop[d] < 0){
			shop[d] = 0;
		}
		if(judge[d] && shop[d] <= 3){
			judge[d] = false;
			res --;
		} 
		record[d] = t;
		shop[d] += 2;
		if(!judge[d] && shop[d] > 5) judge[d] = true, res++;
	}
	for(int i = 1; i <= n; i++){
		if(record[i] != t){
			shop[i] = shop[i] - (t - record[i]);
		}
		if(judge[i] && shop[i] <= 3) res--;
	}
	cout << res;
}
/*
1 5 10
1 1
2 1
3 1
4 1
5 1

*/


