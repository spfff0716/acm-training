#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<long long>dp(n+1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			dp[i]+=dp[j];
		}
	}
	cout<<dp[n];
	return 0;
	
 } 
