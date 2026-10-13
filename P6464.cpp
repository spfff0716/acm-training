#include <bits/stdc++.h>
using namespace std;
int dist[110][110];
const int INF=0x3f3f3f3f;
int main()
{
	int n,m;
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)
	{
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		dist[u][v]=w;
		dist[v][u]=w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][k]!=INF&&dist[k][j]!=INF)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); 
			}
		}
	}
	int ans=INF;
	for(int a=1;a<=n;a++)
	{
		for(int b=a+1;b<=n;b++)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int ned=min(dist[i][j],dist[i][a]+dist[b][j]);
					ned=min(ned,dist[i][b]+dist[a][j]);
					sum+=ned;
				}
			}
			ans=min(sum,ans);
		}
	}
	cout<<ans;
	return 0;
 } 
