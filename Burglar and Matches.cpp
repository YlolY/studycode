#include <iostream>
#include<string>
#include<utility>
using namespace std;

int main() {
	unsigned long long int n,sum;
	int m;
	sum=0;
	cin>>n>>m;
	pair<unsigned long long int,int> x[m];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		x[i]=make_pair(a,b);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m-1;j++){
			pair<unsigned long long int,int> tmp;
			if(x[j].second<x[j+1].second){
				tmp=x[j];
				x[j]=x[j+1];
				x[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(n>=x[i].first){
			sum+=(x[i].first*x[i].second);
			n-=x[i].first;
		}
		else{
			sum+=(n*x[i].second);
			n=0;
			break;
		}

		if(n==0){
				break;
		}
	}
	cout<<sum<<endl;
	return 0;
}
