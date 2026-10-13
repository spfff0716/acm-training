#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
vector<int>g[N];
int cnt[N];
int n;
int dfs(int x,int fa)
{
	cnt[x]=1;
	for(auto &it:g[x])
	{
		if(it==fa)
		continue;
		cnt[x]+=dfs(it,x);
	}
	return cnt[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
 } 
