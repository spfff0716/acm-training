#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>;
const int N=1e4+10;

vector<int>g[N];
vector<int>g1[N];
int n,m;
bool vis1[N];
bool ri[N];
void dfs(int u)
{
	vis1[u]=true;
	for(auto &v:g1[u])
	{
		if(vis1[v])
		continue;
		dfs(v);
	}
}
int dist[N];
bool vis2[N];
void bfs(int s)
{
	memset(dist,0x3f,sizeof(dist));
	queue<int>q;
	dist[s]=0;
	q.push(s);
	vis2[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!ri[u])
		continue;
		for(auto &v:g[u])
		{
			if(vis2[v]||!ri[v])
			continue;
			if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				vis2[v]=true;
				q.push(v);
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g1[y].push_back(x);
	}
	int s,t;
	cin>>s>>t;
	dfs(t);
	memset(ri,true,sizeof(ri));
	for(int i=1;i<=n;i++)
	{
		if(!vis1[i])
		{
			ri[i]=false;
			continue;
		}
		for(auto v:g[i])
		{
			if(!vis1[v])
			{
				ri[i]=false;
				break;
			}
		}
	}
	bfs(s);
	if(!vis2[t])
	cout<<-1;
	else
	cout<<dist[t];
	return 0;
}
