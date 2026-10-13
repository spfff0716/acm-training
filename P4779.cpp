#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,m,s;
const int N=1e5+10;
const int INF=1e9;
vector<pii>g[N];
int dist[N];
int vis[N];
void dj(int s)
{
	fill(dist,dist+N,INF);
	memset(vis,false,sizeof(vis));
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>>heap;
	heap.push({0,s});
	while(!heap.empty())
	{
		auto now=heap.top();
		heap.pop();
		int d=now.first;
		int u=now.second;
		if(vis[u])
		continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				heap.push({dist[v],v});
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	dj(s);
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
	
 } 
