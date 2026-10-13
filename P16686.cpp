#include <bits/stdc++.h>
using namespace std;
typedef pair<int,long long>pii;
const int N=2*1e4+10;
long long dp[1010][N];
long long cost[1010];
long long ans[1010];
vector<pii>g[1010];
const long long mod=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
		if(cost[i]<=p)
		dp[i][cost[i]]=1;
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	 }
	for(int i=0;i<=p;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[j][i]==0)
			continue;
			for(auto &now:g[j])
			{
				int v=now.first;
				long long w=now.second;
				if(i+w<=p)
				{
					dp[v][i+w]=(dp[v][i+w]+dp[j][i])%mod;
				}
			}
		}
	}
	for(int i=0;i<=p;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[j]=(ans[j]+dp[j][i])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}
