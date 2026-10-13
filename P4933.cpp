#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main()
{
	int n;
	cin>>n;
	long long ans=n;
	vector<long long>h(n);
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	vector<unordered_map<long long,long long>>dp(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			long long d=h[i]-h[j];
			long long cnt=(dp[j][d]+1)%mod;
			dp[i][d]=(dp[i][d]+cnt)%mod;
		}
		for(auto &p:dp[i])
		{
			ans=(ans+p.second)%mod;
		}
	}
	cout<<ans;
	return 0;
}
