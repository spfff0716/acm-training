#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=2510;
int dist[N];
bool vis[N];
vector<pii>g[N];
void dj(int s)
{
	memset(dist,sizeof(dist),0x3f);
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.second;
		if(vis[u])
		continue;
		vis[u]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			int w=it.second;
			if(vis[v])
			continue;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	dj(s);
	cout<<dist[t];
}
