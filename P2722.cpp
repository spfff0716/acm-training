#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N];
int main()
{
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int p,t;
		cin>>p>>t;
		for(int j=t;j<=m;j++)
		{
			dp[j]=max(dp[j],dp[j-t]+p);
		}
	}
	cout<<dp[m];
	return 0;
}
