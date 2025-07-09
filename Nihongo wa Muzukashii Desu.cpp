#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(str.find("ikimasu")==0){
			str.replace(str.find("ikimasu"),7, "itte");
		}
		else if(str.find("shimasu")!=-1){
			str.replace(str.find("shimasu"),7, "shite");
		}
		else if(str.find("chimasu")!=-1){
			str.replace(str.find("chimasu"),7, "tte");
		}
		else if(str.find("rimasu")!=-1){
			str.replace(str.find("rimasu"),6, "tte");
		}
		else if(str.find("mimasu")!=-1){
			str.replace(str.find("mimasu"),6, "nde");
		}
		else if(str.find("bimasu")!=-1){
			str.replace(str.find("bimasu"),6, "nde");
		}
		else if(str.find("nimasu")!=-1){
			str.replace(str.find("nimasu"),6, "nde");
		}

		else if(str.find("kimasu")!=-1){
			str.replace(str.find("kimasu"),6, "ite");
		}
		else if(str.find("gimasu")!=-1){
			str.replace(str.find("gimasu"),6, "ide");
		}

		cout<<str<<endl;
	}
	    return 0;
}
