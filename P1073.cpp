#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
int money[N];
vector<int>g1[N];
vector<int>g2[N];
bool vis2[N];
void bfs2()
{
	queue<int>q;
	q.push(n);
	vis2[n]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &v:g2[u])
		{
			if(vis2[v])
			continue;
			vis2[v]=true;
			q.push(v);
		}
	}
}
bool vis[N];
int res=0;
int mi[N];
void dj()
{
	for(int i=1;i<=n;i++)
	{
		mi[i]=110;
	}
	mi[1]=money[1];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({mi[1],1});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int u=now.second;
		if(vis[u])
		continue;
		vis[u]=true;
		for(auto &v:g1[u])
		{
			if(!vis2[v])
			continue;
			res=max(res,money[v]-mi[u]);
			if(mi[v]>mi[u])
			{
				mi[v]=min(money[v],mi[u]);
				q.push({mi[v],v});
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>money[i];
	}
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==1)
		{
			g1[x].push_back(y);
			g2[y].push_back(x);
		}
		else
		{
			g1[x].push_back(y);
			g1[y].push_back(x);
			g2[x].push_back(y);
			g2[y].push_back(x);
		}
	}
	bfs2();
	dj();
	cout<<res;
	return 0;
}
