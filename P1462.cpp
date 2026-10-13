#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define int long long
const int N=1e4+10;
int n,m,b;
int f[N];
vector<pii>g[N];
int cost[N];
int vis[N];
bool dj(int x)
{
	if(f[1]>x)
	return false;
	memset(cost,0,sizeof(cost));
	memset(vis,false,sizeof(vis));
	cost[1]=f[1];
	priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>>q;
	q.push({0,{1,cost[1]}});
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		int blood=now.first;
		int u=now.second.first;
		if(vis[u])
		continue;
		vis[u]=true;
		for(auto &it:g[u])
		{
			int v=it.first;
			int w=it.second;
			if(vis[v])
			continue;
			if(blood+w>b)
			continue;
			if(f[v]<=x)
			{
				cost[v]=max(cost[v],cost[u]);
				q.push({blood+w,{v,cost[v]}});
			}
		}
	}
	if(vis[n])
	return true;
	return false;
}
signed main()
{
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	int l=0;
	int r=1e9;
	bool flag=1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(dj(mid))
		{
			r=mid;
			flag=0;
		}
		else
		l=mid+1;
	}
	if(flag)
	cout<<"AFK";
	else
	cout<<l;
	return 0;
 } 
