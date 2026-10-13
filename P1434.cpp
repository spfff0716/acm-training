#include <bits/stdc++.h>
using namespace std;
const int N=110;
int r,c;
int dp[110][110];
int high[110][110];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int x,int y)
{
	if(dp[x][y]!=1)
	return dp[x][y];
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=r||ny<0||ny>=c)
		continue;
		if(high[nx][ny]>=high[x][y])
		continue;
		dp[x][y]=max(dp[x][y],dfs(nx,ny)+1);
		
	}
	return dp[x][y];
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>high[i][j];
			dp[i][j]=1;
		}
	}
	int ans=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans;
	return 0;
 } 
