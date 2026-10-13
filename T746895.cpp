#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
vector<pii>g[1010]; 
long long mod=998244353;
long long cost[1010],sum[1010],cnt[1010];
int n,m,p;
void bfs(int st)
{
	memset(sum,0,sizeof(sum));
	sum[st]=cost[st];
	if(sum[st]>p)
	return;
	cnt[st]=(cnt[st]+1)%mod;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(auto &i:g[now])
		{
			if(sum[now]+i.second>p)
			continue;
			int nx=i.first;
			sum[nx]=sum[now]+i.second;
			cnt[nx]=(cnt[nx]+1)%mod;
			q.push(nx);
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<cnt[i]<<endl;
	}
	return 0;
	
	
}
