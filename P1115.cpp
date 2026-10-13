#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long>dp(n);
	for(int i=0;i<n;i++)
	{
		cin>>dp[i];
	}
	long long res=dp[0];
	for(int i=1;i<n;i++)
	{
		dp[i]=max(dp[i-1]+dp[i],dp[i]);
		res=max(dp[i],res);
	}
	cout<<res;
	return 0;
}
