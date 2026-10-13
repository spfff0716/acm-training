#include <bits/stdc++.h>
using namespace std;
const int N=105;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long dp[N][N][N],arr[N][N];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>arr[i][j];
		}
	}
	int cnt=min(n,k);
	memset(dp,0xcf,sizeof(dp));
	for(int i=0;i<=cnt;i++)
	{
		dp[0][1][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				for(int m=1;m<=cnt;m++)
				{
					dp[i][j][m]=max(dp[i-1][j][m]+arr[i][j],dp[i-1][j][m-1]+3*arr[i][j]);
				}
				dp[i][j][0]=dp[i-1][j][0]+arr[i][j];
			}
			else if(j==i)
			{
				for(int m=1;m<=cnt;m++)
				{
					dp[i][j][m]=max(dp[i-1][j-1][m]+arr[i][j],dp[i-1][j-1][m-1]+3*arr[i][j]);
				}
				dp[i][j][0]=dp[i-1][j-1][0]+arr[i][j];
			}
			else
			{
				for(int m=1;m<=cnt;m++)
				{
					long long left=max(dp[i-1][j-1][m]+arr[i][j],dp[i-1][j-1][m-1]+3*arr[i][j]);
					long long right=max(dp[i-1][j][m]+arr[i][j],dp[i-1][j][m-1]+3*arr[i][j]);
					dp[i][j][m]=max(left,right);
				}
				dp[i][j][0]=max(dp[i-1][j-1][0],dp[i-1][j][0])+arr[i][j];
			}
		}
	}
	long long ans=-INF;
	for(int j=1;j<=n;j++)
	{
		for(int m=0;m<=cnt;m++)
		{
			ans=max(ans,dp[n][j][m]);
		}
	}
	cout<<ans;
	return 0;
 } 
