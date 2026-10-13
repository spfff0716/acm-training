#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=5*1e3+10;
const int INF=-0x3f3f3f3f;
const int mod=80112002;
vector<int>g[N];
int indegree[N];
int outdegree[N];
int dp[N];
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		indegree[v]++;
		outdegree[u]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		if(indegree[i]==0)
		{
			q.push(i);
			dp[i]=1;
		}
	}
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			dp[v]=(dp[v]+dp[u])%mod;
			indegree[v]--;
			if(indegree[v]==0)
			q.push(v);
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(outdegree[i]==0)
		{
			ans=(ans+dp[i])%mod;
		}
	}
	cout<<ans;
	return 0;
 } 
