#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+10;
int dist1[N],dist2[N];
bool vis1[N],vis2[N];
vector<pii> g1[N],g2[N];
void dj1(int st)
{
	memset(dist1,0x3f,sizeof(dist1));
	dist1[st]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({st,0});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.first;
		int c=now.second;
		if(vis1[u])
		continue;
		vis1[u]=true;
		for(auto &it:g1[u])
		{
			int v=it.first;
			int w=it.second;
			if(dist1[v]>c+w)
			{
				dist1[v]=c+w;
				q.push({c+w,v});
			}
		}
	}
}
void dj2(int st)
{
	memset(dist2,0x3f,sizeof(dist2));
	dist2[st]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({st,0});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.first;
		int c=now.second;
		if(vis2[u])
		continue;
		vis2[u]=true;
		for(auto &it:g2[u])
		{
			int v=it.first;
			int w=it.second;
			if(dist2[v]>c+w)
			{
				dist2[v]=c+w;
				q.push({c+w,v});
			}
		}
	}
}
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g1[u].push_back({v,w});
		g2[v].push_back({u,w});
	}
	dj1(x);
	dj2(x);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dist1[i]+dist2[i]);
	}
	cout<<ans;
	return 0;
}
