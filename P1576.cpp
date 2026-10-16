#include <bits/stdc++.h>
using namespace std;
using pii=pair<double,int>;
const int N=2010;
const double INF=1e5+10;
int n,m;
double cost[N];
vector<pair<int,int>>g[N];
bool vis[N];
void dj(int t)
{
	for(int i=1;i<=n;i++)
	{
		cost[i]=INF;
	}
	cost[t]=100.0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({cost[t],t});
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
			int z=it.second;
			if(vis[v])
			continue;
			double w=cost[u]*100/(100-z);
			if(cost[v]>w)
			{
				cost[v]=w;
				q.push({w,v});
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	int s,t;
	cin>>s>>t;
	dj(t);
	printf("%.8f",cost[s]);
	return 0;
}
