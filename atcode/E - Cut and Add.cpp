#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define int long long
const int N=2*1e5+10;
int n;
int g[N][2];
vector<int>g1[N];
int cnt[N];
int pre[N];
int add[N];
int sum[N];
int dfs(int x,int fa)
{
	cnt[x]=1;
	int flag=1;
	for(auto &it:g1[x])
	{
		if(it==fa)
		continue;
		else
		{
			cnt[x]=cnt[x]+dfs(it,x);
			pre[it]=x;
			flag=0;
		}
	}
	if(flag)
	{
		return cnt[x]=1;
	}
	return cnt[x];
}
void dfs1(int x,int fa)
{
	for(auto &it:g1[x])
	{
		if(it==fa)
		continue;
		sum[it]=sum[x]+add[it];
		dfs1(it,x);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[i][0]=a;
		g[i][1]=b;
		g1[a].push_back(b);
		g1[b].push_back(a);
	}
	pre[1]=-1;
	dfs(1,-1);
	for(int i=1;i<n;i++)
	{
		int u=g[i][0];
		int v=g[i][1];
		if(pre[u]==v)
		{
			if(cnt[u]>n-cnt[u])
			{
				add[u]+=i;
			}
			else
			{
				add[1]+=i;
				add[u]-=i;
			}
		}
		else
		{
			if(cnt[v]>n-cnt[v])
			{
				add[v]+=i;
			}
			else
			{
				add[1]+=i;
				add[v]-=i;
			}
		}
	}
	sum[1]=add[1];
	dfs1(1,-1);
	for(int i=1;i<=n;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
