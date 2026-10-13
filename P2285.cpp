#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e4+10;
int n,m;
int t[M],x[M],y[M],dp[M];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i]>>x[i]>>y[i];
		dp[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(t[i]-t[j]>=(abs(x[i]-x[j])+abs(y[i]-y[j])))
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
