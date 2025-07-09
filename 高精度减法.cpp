#include<iostream>
#include<string>
#include<math.h>
using namespace std;


int main(){
	int a[11000]={0},b[11000]={0};
	string a1,b1;

	cin>>a1>>b1;

	for(int i=0;i<a1.size();i++){
		a[i]=int(a1[a1.size()-1-i])-'0';
	}
	for(int i=0;i<b1.size();i++){
		b[i]=int(b1[b1.size()-1-i])-'0';
	}

	if(a1.size()<b1.size()){
		for(int i=0;i<11000;i++){
			int c=b[i];
			b[i]=a[i];
			a[i]=c;
		}
		cout<<'-';
	}

	if(a1.size()==b1.size()){
		for(int i=a1.size();i>=0;i--){
			if(a[i]>=b[i]){
				if(i==0){
					if(a[0]-b[0]==0){
						cout<<'0';
					}

				}
				continue;
			}
			else{
				for(int i=0;i<11000;i++){
					int c=b[i];
					b[i]=a[i];
					a[i]=c;
				}
				cout<<'-';
				break;
			}
		}
	}

	for(int i=max(a1.size(),b1.size());i>=0;i--){
		a[i]-=b[i];
	}
	for(int i=max(a1.size(),b1.size());i>=0;i--){
		if(a[i]<0){
			for(int k=i+1;k<a1.size()+1;k++){
				if(a[k]==0){
					a[k]+=9;
				}
				else{
					a[k]-=1;
					break;
				}
			}
			a[i]+=10;
		}
	}

	int x=max(a1.size(),b1.size());
	for(int i=max(a1.size(),b1.size());a[i]==0&&i==x;i--)x--;
	for(int i=x;i>=0;i--){
		cout<<a[i];
	}

	return 0;
}
