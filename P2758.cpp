#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n=a.size();
	int m=b.size();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i]==b[j])
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			else
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
