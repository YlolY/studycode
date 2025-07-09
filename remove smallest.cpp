#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		int a[200];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+n+1);

		int x=n;
		for(int j=1;j<n;j++){
			if(a[j+1]-a[j]<=1){
				x--;
			}
		}

		if(x==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
