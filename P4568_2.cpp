#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=55;
const int INF=0x3f3f3f3f;
vector<pii>g[N];
int dist[N][N];
bool vis[N][N];
int sum=0;
void dj(int st)
{
	dist[st][0]=0;
	priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>>q;
	q.push({{0,st},0});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int w=now.first.first;
		int u=now.first.second;
		int k=now.second;
		if(vis[u][k])
		continue;
		vis[u][k]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			int w2=it.second;
			if(k<sum)
			{
				if(dist[v][k+1]>w+w2/2)
				{
					dist[v][k+1]=w+w2/2;
					q.push({{w+w2/2,v},k+1});
				}
			}
			if(dist[v][k]>w+w2)
			{
				dist[v][k]=w+w2;
				q.push({{w+w2,v},k});
			}
			
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m>>sum;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dj(1);
	int ans=INF;
	for(int i=0;i<=sum;i++)
	{
		ans=min(ans,dist[n][i]);
	}
	cout<<ans;
	return 0;
}
