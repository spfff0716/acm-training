#include <bits/stdc++.h>
using namespace std;
int dp[305][305];
const int INF=0x3f3f3f3f;
int s[305];
int main()
{
	int n;
	cin>>n;
	memset(dp,0x3f,sizeof(dp));
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		s[i]=s[i-1]+m;
		dp[i][i]=0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			for(int j=i;j<=i+l-2;j++)
			{
				dp[i][i+l-1]=min(dp[i][i+l-1],dp[i][j]+dp[j+1][i+l-1]+s[i+l-1]-s[i-1]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
