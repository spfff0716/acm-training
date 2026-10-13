#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,m;
const int N=1e3+10;
vector<pii>g[N];
int dist[N];
bool vis[N];
void dj(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int w=now.first;
		int v=now.second;
		if(vis[v])
		continue;
		vis[v]=true;
		for(int i=0;i<g[v].size();i++)
		{
			int u=g[v][i].first;
			int cost=g[v][i].second;
			if(dist[u]>dist[v]+cost)
			{
				dist[u]=dist[v]+cost;
				q.push({dist[u],u});
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	long res=0;
	dj(1);
	for(int i=2;i<=n;i++)
	{
		res+=dist[i];
	}
	for(int i=2;i<=n;i++)
	{
		dj(i);
		res+=dist[1];
	}
	cout<<res;
	return 0;
 } 
