#include <bits/stdc++.h>
using namespace std;
int dist[210][210];
const int INF=0x3f3f3f3f;
int t[210];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		dist[u][v]=w;
		dist[v][u]=w;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,time;
		cin>>x>>y>>time;
		int now=0;
		while(t[now]<=time&&now<n)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(dist[i][now]!=INF&&dist[now][j]!=INF)
					{
						dist[i][j]=min(dist[i][now]+dist[now][j],dist[i][j]);
					}
				}
			}
			now++;	
		}
		if(dist[x][y]==INF||t[x]>time||t[y]>time)
		cout<<-1<<endl;
		else
		cout<<dist[x][y]<<endl;
	}
	return 0;
}
