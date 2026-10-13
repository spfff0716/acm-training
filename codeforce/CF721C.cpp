#include <bits/stdc++.h>
using namespace std;
using ll=int;
using pii=pair<ll,ll>; 
const int N=5050;
const int NINF=0x3f3f3f3f;
vector<pii>g[N];
int indegree[N];
ll dp[N][N];
ll pre[N][N];
int main()
{
	ll n,m,t;
	cin>>n>>m>>t;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		indegree[v]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		q.push(i);
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=NINF;
		}
	}
	dp[1][1]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &it:g[u])
		{
			ll v=it.first;
			ll w=it.second;
			for(int cnt=1;cnt<n;cnt++)
			{
				if(dp[u][cnt]==NINF)
				continue;
				if(dp[v][cnt+1]>dp[u][cnt]+w)
				{
					dp[v][cnt+1]=dp[u][cnt]+w;
					pre[v][cnt+1]=u;
				}
			}
			indegree[v]--;
			if(indegree[v]==0)
			q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[n][i]<=t)
		ans=i;
	}
	int best=ans;
	int u=n;
	vector<int>res;
	while(best>0)
	{
		res.push_back(u);
		int v=pre[u][best];
		best--;
		u=v;
	}
	cout<<ans<<endl;
	for(int i=res.size()-1;i>=0;i--)
	{
		cout<<res[i]<<" ";
	}
	return 0;
 } 
