#include <bits/stdc++.h>
using namespace std;
bool vis[110];
int bfs(int now,vector<vector<int>> &arr)
{
	memset(vis,false,sizeof(vis));
	queue<int>q;
	q.push(now);
	int cnt=0;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		vis[v]=true;
		for(auto &i:arr[v])
		{
			if(vis[i])
			continue;
			vis[i]=true;
			q.push(i);
			cnt++;
		}
	 }
	 return cnt; 
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>pre(n+1);
	vector<vector<int>>last(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		pre[v].push_back(u);
		last[u].push_back(v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int in=bfs(i,pre);
		int out=bfs(i,last);
		if(in+out==n-1)
		ans++;
	}
	cout<<ans;
	return 0;
 } 
