#include<iostream>
#include<map>
using namespace std;


int main(){

	int n;
	cin>>n;
	map<int,int> mp;
	long long sum=0;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(int i=1;i<n;i++){
		mp[a[i]]--;
		for(int j=0;j<=30;j++){
			sum+=mp[(1<<j)-a[i]];

		}
	}
	cout<<sum<<endl;

    return 0;
}
