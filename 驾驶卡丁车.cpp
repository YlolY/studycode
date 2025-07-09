#include<iostream>
#include<math.h>
using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int main()
{
	int n,m,x,y;
	string p[52],cd[52];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cd[i]='#';
		cin>>p[i];
		cd[i]+=p[i];
		cd[i]+='#';
	}

	cd[0]="##################################################";
	cd[n+1]="##################################################";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(cd[i][j]=='*')
			{
				x=i;
				y=j;
			}

		}
	}


	int num;
	cin>>num;

	string ml;
	cin>>ml;

	int v=0,fx=0;

	for(int i=0;i<num;i++)
	{
		if(ml[i]=='U'){
			v++;
		}
		else if(ml[i]=='D'){
			v--;
			v=max(0,v);
		}
		else if(ml[i]=='R'){
			fx=(fx+9)%8;
		}
		else if(ml[i]=='L'){
			fx=(fx+7)%8;
		}

		for(int j=0;j<v;j++){
			if(x<1||x>n||y<1||y>m||cd[x+dx[fx]][y+dy[fx]]=='#'){
				cout<<"Crash! ";
				v=0;
				break;
			}
			else{
				if(fx%2==0){
					x+=dx[fx];
					y+=dy[fx];
				}
				else{
					if(cd[x+dx[(fx+7)%8]][y+dy[(fx+7)%8]]=='#'&&cd[x+dx[(fx+9)%8]][y+dy[(fx+9)%8]]=='#'){
						cout<<"Crash! ";
						v=0;
						break;
					}
					else{
						x+=dx[fx];
						y+=dy[fx];
					}
				}
			}
		}
	cout<<x<<" "<<y<<endl;

	}

	return 0;
}
