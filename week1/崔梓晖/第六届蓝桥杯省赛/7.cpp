#include<bits/stdc++.h>
using namespace std;

int N, M, Q;
const int maxM = 2e5;
const int maxN = 5e4 + 5;
int par[maxN];

//����� 
struct edge {
	int begin, end, cost;
}edges[maxM];

bool cmp(edge x, edge y) {
	return x.cost<y.cost;
}

//���鼯
int get_root(int a) {    //����ڵ� 
	if(par[a] != a) {
		par[a] = get_root(par[a]);
	}
	return par[a];
}

//��ѯ�Ƿ���ͬһ������ 
bool query(int a,int b) {
     return get_root(a) == get_root(b);
}

//�ϲ�������� 
void merge(int a,int b) {
     par[get_root(a)] = get_root(b);
}

//ÿ��ѯ�ʶ�Ҫ��ʼ�� 
void init() {
	for(int i = 1;i <= N;i++) {
		par[i] = i;
	}
}

int solve(int l, int r, int k, int c) {
	init();
	for(int i = 0;i < M;i++) {
		int begin = edges[i].begin;
		int end = edges[i].end;
		int cost = edges[i].cost;
		
		if(get_root(begin) == get_root(end)) {   //�ñߵ���������Ѿ���ͬһ�������� 
			continue;
		}else {
			merge(begin, end);  //�ϲ��ӱ� 
		}
		//ÿ���һ���߶�Ҫ�ж�һ���Ѿ������������Ǿ��˳� 
		bool flag = true;
		int parent = 0;
		//���l��r��ģk��c�ĵ��Ƿ��Ѿ���ͨ 
		for(int i = l;i <= r;i++) {
			if(i % k == c) {
				if(parent == 0) {
					parent = get_root(i);
				}else {
					if(parent != get_root(i)) {   //ʵ���Ͼ��Ǽ����Щ����ǲ�����ͬһ�������� 
						flag = false;
						break;
					}
				}
			}
		}
		if(flag) {
			cout<<cost<<endl;  //�Ѿ���ͬһ�����ϣ�˵���Ѿ���ͨ 
			break;
		}
	}
	return 1;
}

int main() {
	cin>>N>>M>>Q;
	for(int i = 0;i < M;i++) {
		cin>>edges[i].begin>>edges[i].end>>edges[i].cost;
	} 
	sort(edges, edges + M, cmp);   //�ߴ�С�������� 
	for(int i = 0;i < Q;i++) {
		int l, r, k, c;
		cin>>l>>r>>k>>c;
		solve(l, r, k, c);
	}
	return 0;
}

