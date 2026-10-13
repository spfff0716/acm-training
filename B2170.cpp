#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
vector<int>g[N];
int deep[N];
int n;
void dfs(int x,int fa)
{
	for(auto &it:g[x])
	{
		if(it==fa)
		continue;
		deep[it]=deep[x]+1;
		dfs(it,x);
	}
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
	deep[1]=1;
	dfs(1,-1);
	for(int i=1;i<=n;i++)
	{
		cout<<deep[i]<<" ";
	}
	return 0;
 } 
