#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
int dist[N];
bool vis[N];
vector<pii> g[N];
int n,m;
void dj(int s)
{
	memset(dist,INF,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int d=now.first;
		int u=now.second;
		if(vis[u])
		continue;
		for(auto &it:g[u])
		{
			int w=it.first;
			int v=it.second;
			if(dist[v]>d+w)
			{
				dist[v]=d+w;
				q.push({dist[v],v});
			}
		}
	 } 
}
int main()
{
	int st;
	cin>>n>>m>>st;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
	}
	dj(st);
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	return 0;
 } 
