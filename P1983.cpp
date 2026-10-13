#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int>g[N];
int indegree[N];
int dp[N]; 
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int s;
		cin>>s;
		vector<int>arr(s);
		for(int i=0;i<s;i++)
		{
			cin>>arr[i];
		 }
		int idex=0;
		for(int u=arr[0];u<=arr[s-1];u++)
		{
			if(u==arr[idex])
			{
				idex++;
				continue;
			}
			else
			{
				for(int i=0;i<s;i++)
				{
					g[u].push_back(arr[i]);
					indegree[arr[i]]++;
				}
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			dp[i]=1;
			q.push(i);
		}
	}
	int ans=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto &v:g[u])
		{
			dp[v]=max(dp[v],dp[u]+1);
			ans=max(dp[v],ans);
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
			}
		}
	}
	cout<<ans;
	return 0;
 } 
