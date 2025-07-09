#include<iostream>
#include<math.h>
using namespace std;


int main(){

	int a[1000]={0},b[1000]={0};
	string x,y;
	cin>>x>>y;


	for(int i=0;i<x.size();i++){
		a[i]=int(x[x.size()-i-1])-'0';
	}
	for(int i=0;i<y.size();i++){
		b[i]=int(y[y.size()-i-1])-'0';
	}
	for(int i=0;i<max(x.size(),y.size());i++){
		a[i]+=b[i];
	}
	for(int i=0;i<max(x.size(),y.size());i++){
		if(a[i]>9){
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	int m=0;
	for(int i=0;i<max(x.size(),y.size());i++){
		if(a[i]==0)
		m++;
	}
	if(m==max(x.size(),y.size()))
	cout<<0;
	int k=0;
	for(int j=1000-1;j>=0;j--){
		if(k==0){

			if(a[j]==0){
			continue;
			}
			else{
				cout<<a[j];
				k=1;
			}
		}
		else{
			cout<<a[j];
		}
	}
	return 0;
}
