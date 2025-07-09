#include<iostream>
using namespace std;

typedef long long LL;
const int maxn=5e5+20;
int n,m;

struct node{
	LL sum[maxn];
	int lowbit(int x){
		return x&(-x);
	}
	LL query(int x){
		LL k=0;
		while(x){
			k+=sum[x];
			x-=lowbit(x);
		}
		return k;
	}
	void Add(int x,LL k){
		while(x<=n){
			sum[x]+=k;
			x+=lowbit(x);
		}
	}
}BIT;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		BIT.Add(i,t);
	}
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			BIT.Add(x,y);

		}
		else{
			cout<<BIT.query(y)-BIT.query(x-1)<<endl;
		}
	}
	return 0;
}
