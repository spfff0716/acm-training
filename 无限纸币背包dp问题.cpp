#include <bits/stdc++.h>
using namespace std;
const int N=1e9;
int main()
{
	int n,w;
	cin>>n>>w;
	vector<int>money(n);
	for(int i=0;i<n;i++)
	{
		cin>>money[i];
	}
	vector<int>dp(w+1,N);
	dp[0]=0;
	for(int i=1;i<=w;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>=money[j])
			{
				dp[i]=min(dp[i],dp[i-money[j]]+1);
			}
		}
	}
	cout<<dp[w];
	return 0;
	
 } 
