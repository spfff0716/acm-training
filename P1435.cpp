#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		dp[i][i]=0;
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])
			{
				dp[i][j]=dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}
