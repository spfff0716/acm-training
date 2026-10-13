#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod=100003;
int n,m;
vector<int>g[N];
int dist[N];
int cnt[N];
void bfs(int st)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=-1;
	}
	queue<int>q;
	q.push(st);
	dist[st]=0;
	cnt[st]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(auto &i:g[now])
		{
			if(dist[i]==-1)
			{
				cnt[i]=cnt[now];
				dist[i]=dist[now]+1;
				q.push(i);
			}
			else
			{
				if(dist[i]==dist[now]+1)
				{
					cnt[i]=(cnt[i]+cnt[now])%mod;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u==v)
		continue;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1);
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==-1)
		{
			cout<<0;
		}
		else
		{
			cout<<cnt[i];
		}
		cout<<'\n';
	}
	return 0;
}
