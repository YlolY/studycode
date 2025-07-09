#include<iostream>
using namespace std;


int main(){
	int n,a[100]={0},b[100]={0};
	cin>>n;
	a[0]=b[0]=1;
	if(n==1){
		cout<<1;
	}
	else{
		for(int i=2;i<=n;i++){
			for(int j=0;j<100;j++){
				b[j]*=i;
			}
			for(int j=0;j<100;j++){
				if(b[j]>9){
					b[j+1]+=(b[j]/10);
					b[j]%=10;
				}
			}
			for(int j=0;j<100;j++){
				a[j]+=b[j];

			}
			for(int j=0;j<100;j++){
				if(a[j]>9){
					a[j+1]+=(a[j]/10);
					a[j]%=10;
				}
			}

		}
		int x=99;
		for(int i=99;a[i]==0&&i==x;i--)x--;
		for(int i=x;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
