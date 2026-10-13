#include <bits/stdc++.h>
using namespace std;
long mod=1e9+7;
int dp[10010];
int main()
{
	int n,w;
	cin>>n>>w;
	vector<int>money(n);
	for(int i=0;i<n;i++)
	{
		cin>>money[i];
	}
	dp[0]=1;
	for(int i=1;i<=w;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i-money[j]>=0)
			{
				dp[i]+=dp[i-money[j]]%mod;
			}
		}
	}
	cout<<dp[w];
	return 0;
 } 
