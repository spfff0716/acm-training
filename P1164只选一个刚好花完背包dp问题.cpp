#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>money(n);
	for(int i=0;i<n;i++)
	{
		cin>>money[i];
	}
	vector<int>dp(m+1,0);
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>=money[i];j--)
		{
			dp[j]+=dp[j-money[i]];
		}
	}
	cout<<dp[m];
	return 0;
}
