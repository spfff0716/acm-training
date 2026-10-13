#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
vector<int>g[N];
int dp[N];
int indegree[N];
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		indegree[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
			dp[i]=0;
		}
		else
		dp[i]=-1;
	}
	int res=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &v:g[u])
		{
			dp[v]=max(dp[v],dp[u]+1);
			res=max(dp[v],res);
			indegree[v]--;
			if(indegree[v]==0)
			q.push(v);
		}
	}
	cout<<res;
	return 0;
 } 
