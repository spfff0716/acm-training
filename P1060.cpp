#include <bits/stdc++.h>
using namespace std;
const int N=3*1e4+10;
int dp[N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int w,p;
		cin>>w>>p;
		int v=w*p;
		for(int j=n;j>=w;j--)
		{
			dp[j]=max(dp[j],dp[j-w]+v);
		}
	}
	cout<<dp[n];
	return 0;
}
