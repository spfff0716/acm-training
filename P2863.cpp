#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>g[N];
int n,m;
int timer;
int dfn[N];
int low[N];
bool instack[N];
stack<int>stk;
int res=0;
void tarjan(int u)
{
	timer++;
	dfn[u]=timer;
	low[u]=timer;
	stk.push(u);
	instack[u]=true;
	for(auto &v:g[u])
	{
		if(dfn[v]==0)
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		int cnt=0;
		while(true)
		{
			int now=stk.top();
			stk.pop();
			cnt++;
			instack[now]=false;
			if(now==u)
			break;
		}
		if(cnt>1)
		res++;
	}
	
}
int main()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==0)
		{
			tarjan(i);
		}
	}
	cout<<res;
	return 0;
}
