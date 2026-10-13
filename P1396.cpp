#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e4+10;
int dist[N];
vector<pii>g[N];
bool vis[N];
void dj(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int c=now.first;
		int u=now.second;
		if(vis[u])
		continue;
		vis[u]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			int w=it.second;
			if(dist[v]>max(c,w))
			{
				dist[v]=max(c,w);
				q.push({dist[v],v});
			}
		}
	}
}
int main()
{
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	dj(s);
	cout<<dist[t];
	return 0;
}
