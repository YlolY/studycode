#include<iostream>
#include<math.h>
#include<string>
using namespace std;


int main(){

	int a[5001]={0};
	long long y,d=0;
	string x;
	cin>>x>>y;

	for(int i=0;i<x.size();i++){
		a[i]=int(x[x.size()-i-1])-'0';
	}

	for(int i=x.size()-1;i>=0;i--){
  		int c=a[i];
		a[i]=(d*10+a[i])/y;
		d=(d*10+c)%y;

	}


	int m=0;
	for(int i=0;i<x.size();i++){
		if(a[i]==0)
		m++;
	}
	if(m==x.size())
	cout<<0;


	int k=0;
	for(int j=5000;j>=0;j--){
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
