#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll>pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=1005;
const int M=1e4+5;
ll dist[N][M];
bool vis[N][M];
vector<pii>g[N];
int main()
{
	int n,p,k;
	cin>>n>>p>>k;
	for(int i=1;i<=p;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w}); 
	}
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[1][0]=0;
	priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>>q;
	q.push({0,{1,0}});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		ll w=now.first;
		int u=now.second.first;
		int cnt=now.second.second;
		if(vis[u][cnt])
		continue;
		vis[u][cnt]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			ll money=it.second;
			if(dist[v][cnt]>max(w,money))
			{
				dist[v][cnt]=max(w,money);
				q.push({dist[v][cnt],{v,cnt}});
			}
			if(cnt<k&&dist[v][cnt+1]>w)
			{
				dist[v][cnt+1]=w;
				q.push({w,{v,cnt+1}});
			}
		}
	}
	ll ans=INF;
	for(int i=0;i<=k;i++)
	{
		ans=min(ans,dist[n][i]);
	}
	if(ans==INF)
	cout<<-1;
	else
	cout<<ans;
	return 0;
	
	
 } 
