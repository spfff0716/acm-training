#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>dp[i][j];
		}
	}
	int res=dp[1][1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				dp[i][j]=dp[i][j]+dp[i-1][j];
			}
			else if(j==i)
			{
				dp[i][j]=dp[i][j]+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+dp[i][j];
			}
			res=max(res,dp[i][j]);
		}
	}
	cout<<res;
	return 0;
}
