#include <bits/stdc++.h>
using namespace std;
bool vis[110][110];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		vis[u][v]=true;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				vis[i][j]=vis[i][j]||(vis[i][k]&&vis[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue; 
			if(vis[i][j]||vis[j][i])
			cnt++;
		}
		if(cnt==n-1)
		ans++;
	}
	cout<<ans;
	return 0;
 } 
