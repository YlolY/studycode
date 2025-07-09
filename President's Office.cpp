#include<iostream>
using namespace std;
#include<math.h>
#include<algorithm>
#include<string.h>
int n,m,i,j,ans=0;
string str[101];
char zt;
int b[101][101];

void dfs(int i,int j)
{
	b[i][j]=0;
	if(b[i-1][j]==1&&str[i-2][j-1]==str[i-1][j-1])
		dfs(i-1,j);
	if(b[i+1][j]==1&&str[i][j-1]==str[i-1][j-1])
		dfs(i+1,j);
	if(b[i][j-1]==1&&str[i-1][j-2]==str[i-1][j-1])
		dfs(i,j-1);
	if(b[i][j+1]==1&&str[i-1][j]==str[i-1][j-1])
		dfs(i,j+1);
}


int main()
{
	cin>>n>>m>>zt;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(str[i-1][j-1]==zt){
				b[i][j]=2;
				if(i-1>0&&b[i-1][j]!=2&&str[i-2][j-1]!='.')b[i-1][j]=1;
				if(j-1>0&&b[i][j-1]!=2&&str[i-1][j-2]!='.')b[i][j-1]=1;
				if(i+1<=n&&b[i+1][j]!=2&&str[i][j-1]!='.')b[i+1][j]=1;
				if(j+1<=m&&b[i][j+1]!=2&&str[i-1][j]!='.')b[i][j+1]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(b[i][j]==1)
			{
				dfs(i,j);
				ans++;
			}
		}
	}


	cout<<ans;
	return 0;
}
