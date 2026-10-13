#include <bits/stdc++.h>
using namespace std;
using ll=int;
const int N=3*1e5+10;
vector<int>g[N];
ll indegree[N];
ll arr[N];
ll dp[N][30];
int main()
{
	ll n,m;
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		arr[i]=c-'a';
		dp[i][arr[i]]=1;
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		indegree[y]++;
	}
	queue<int>q;
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i); 
			cnt++;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			for(int i=0;i<26;i++)
			{
				if(arr[v]==i)
				{
					dp[v][i]=max(dp[v][i],dp[u][i]+1);
				}
				else
				dp[v][i]=max(dp[v][i],dp[u][i]);
			}
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
				cnt++;
			}
		}
	}
	int ans=0;
	if(cnt<n)
	cout<<-1;
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<26;j++)
			{
				ans=max(ans,dp[i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
 } 
