#include <bits/stdc++.h>
using namespace std;
int dp[10005][1005];
int d[10005][2];
int water[10005][2];
bool vis[10005];
const int INF=0x3f3f3f3f;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>d[i][0]>>d[i][1];
	}
	for(int i=0;i<k;i++)
	{
		int p;
		cin>>p;
		vis[p]=true;
		cin>>water[p][0]>>water[p][1];
	}
	for(int i=1;i<=m;i++)
	{
		dp[0][i]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int up=d[i-1][0];
		int down=d[i-1][1];
		if(vis[i])
		{
			int flag=1;
			int l=water[i][0];
			int r=water[i][1];
			for(int j=l;j<=m-down;j++)
			{
				if(j<l||j>r)
				continue;
				dp[i][j]=min(dp[i][j],dp[i-1][j+down]);
				if(dp[i][j]!=INF)
				flag=0;
			}
			for(int j=up+1;j<=m&&j>l+1&&j<r;j++)
			{
				if(j<l||j>r)
				continue;
				dp[i][j]=min(dp[i][j],dp[i-1][j-up]+1);
				if(dp[i][j]!=INF)
				flag=0;
			}
			for(int j=m-up;j<=m&&j>l+1&&j<r;j++)
			{
				if(j<l||j>r)
				continue;
				dp[i][m]=min(dp[i][m],dp[i-1][j]+1);
				if(dp[i][j]!=INF)
				flag=0;
			}
			if(flag)
			{
				cout<<0<<'\n'<<ans;
				return 0;
			}
			else
			ans++;
		}
		else
		{
			for(int j=1;j<=m-down;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j+down]);
			}
			for(int j=up+1;j<=m;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j-up]+1);
			}
			for(int j=m-up;j<=m;j++)
			{
				dp[i][m]=min(dp[i][m],dp[i-1][j]+1);
			}
		}
	}
	int res=INF;
	for(int j=1;j<=m;j++)
	{
		res=min(res,dp[n][j]);
	}
	cout<<1<<'\n'<<res;
	return 0;
 } 
