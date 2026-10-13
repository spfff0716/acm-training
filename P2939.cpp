#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
typedef pair<int,long long>pii;
long long dist[N][25];
bool vis[N][25];
vector<pii>g[N];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long t;
		cin>>u>>v>>t;
		g[u].push_back({v,t});
		g[v].push_back({u,t});
	}
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[1][0]=0;
	priority_queue<pair<long long,pii>,vector<pair<long long,pii>>,greater<pair<long long,pii>>>q;
	q.push({0,{1,0}});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		long long time=now.first;
		int u=now.second.first;
		int cnt=now.second.second;
		if(vis[u][cnt])
		continue;
		vis[u][cnt]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			long long w=it.second;
			if(dist[v][cnt]>dist[u][cnt]+w)
			{
				dist[v][cnt]=dist[u][cnt]+w;
				q.push({dist[v][cnt],{v,cnt}});
			}
			if(cnt<k&&dist[v][cnt+1]>dist[u][cnt])
			{
				dist[v][cnt+1]=dist[u][cnt];
				q.push({dist[v][cnt+1],{v,cnt+1}});
			}
		}
	}
	long long ans=INF;
	for(int i=0;i<=k;i++)
	{
		ans=min(ans,dist[n][i]);
	}
	cout<<ans;
	return 0;
 } 
