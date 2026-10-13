#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int n,m,k;
const int N=2*1e4+10;
vector<pii> g[N];
int dist[N][15];
bool vis[N][15];
void dj(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>q;
	q.push({0,{s,0}});
	dist[s][0]=0;
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int w=now.first;
		int u=now.second.first;
		int cnt=now.second.second;
		if(vis[u][cnt])
		continue;
		vis[u][cnt]=true;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			int cost=g[u][i].second;
			if(dist[v][cnt]>w+cost)
			{
				dist[v][cnt]=w+cost;
				q.push({w+cost,{v,cnt}});
			}
			if(cnt<k&&dist[v][cnt+1]>w)
			{
				dist[v][cnt+1]=w;
				q.push({w,{v,cnt+1}});
			}
		}
	}
}
int main()
{
	int s,t;
	cin>>n>>m>>k>>s>>t;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dj(s);
	int ans=dist[t][0];
	for(int i=0;i<=k;i++)
	{
		ans=min(ans,dist[t][i]);
	}
	cout<<ans;
	return 0;
	
}
