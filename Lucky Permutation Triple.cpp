#include<iostream>
using namespace std;

long int n;

int main(){
    cin>>n;
    if(n%2==1){
        for(int i=0;i<n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=1;i<n;i++){
            cout<<i<<" ";
        }
        cout<<0<<endl;
        for(int i=1;i<n;i+=2){
            cout<<i<<" ";
        }
        for(int i=0;i<n;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    } 
    return 0;
}
