#include <bits/stdc++.h>
using namespace std;
int n,m;
const int mod=80112002;
const int N=5*1e3+10;
vector<int> g[N];
bool vis[N];
int dp[N];
int dfs(int u)
{
	int ans=0;
	if(dp[u]!=-1)
	return dp[u];
	if(g[u].size()==0)
	return dp[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		ans=(ans+dfs(g[u][i]))%mod;
	}
	return dp[u]=ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		dp[i]=-1;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		vis[v]=true;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			res=(res+dfs(i))%mod;
		}
	}
	cout<<res;
	return 0;
}
