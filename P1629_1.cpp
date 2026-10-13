#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
using pii=pair<int,int>;
vector<pii>g1[N],g2[N];
int dist1[N],dist2[N];
bool vis1[N],vis2[N];
void dj1()
{
	memset(dist1,0x3f,sizeof(dist1));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist1[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.second;
		if(vis1[u])
		continue;
		vis1[u]=true;
		for(auto &it:g1[u])
		{
			int v=it.first;
			int w=it.second;
			if(vis1[v])
			continue;
			if(dist1[u]+w<dist1[v])
			{
				dist1[v]=dist1[u]+w;
				q.push({dist1[v],v});
			}
		}
	}
}
void dj2()
{
	memset(dist2,0x3f,sizeof(dist2));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist2[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.second;
		if(vis2[u])
		continue;
		vis2[u]=true;
		for(auto &it:g2[u])
		{
			int v=it.first;
			int w=it.second;
			if(vis2[v])
			continue;
			if(dist2[u]+w<dist2[v])
			{
				dist2[v]=dist2[u]+w;
				q.push({dist2[v],v});
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g1[u].push_back({v,w});
		g2[v].push_back({u,w});
	}
	dj1();
	dj2();
	int res=0;
	for(int i=2;i<=n;i++)
	{
		res=res+dist1[i]+dist2[i];
	}
	cout<<res;
	return 0;
}

