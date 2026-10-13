#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
const int mod=998244353;
int qpow(int a,int b)
{
	int res=1;
	while(b>0)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int inv(int a)
{
	return qpow(a,mod-2);
}
const int N=2*1e5+10;
vector<pii>g[N];
vector<pii>g1[N];
vector<pii>pre[N];
bool xin[N];
int dist[N];
int indegree[N];
int cnt[N];
int e[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,t;
	cin>>n>>m>>t;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='1')
		xin[i]=true;
		else
		xin[i]=false;
	}
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[v].push_back({u,w});
		g1[u].push_back({v,w});
		indegree[u]++;
	}
	memset(dist,0x3f,sizeof(dist));
	queue<int>q;
	q.push(t);
	dist[t]=0;
	cnt[t]=1;
	e[t]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &it:g[u])
		{
			int v=it.first;
			int w=it.second;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u];
				pre[v].clear();
				pre[v].push_back({u,w});
			}
			else if(dist[v]==dist[u]+w)
			{
				cnt[v]=(cnt[v]+cnt[u])%mod;
				pre[v].push_back({u,w});
			}
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
				if(xin[v])
				{
					int invcnt=inv(cnt[v]);
					for(auto &k:pre[v])
					{
						int j=k.first;
						int val=k.second;
						e[v]=e[v]+(e[j]+val)%mod*cnt[j]%mod*invcnt%mod;
						e[v]=e[v]%mod;
					}
				}
				else
				{
					int num=g1[v].size();
					int invcnt=inv(num);
					for(auto &now:g1[v])
					{
						int j=now.first;
						int val=now.second;
						e[v]=e[v]+(e[j]+val)%mod*invcnt%mod;
						e[v]=e[v]%mod;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<e[i]<<" ";
	}
	return 0;
}
