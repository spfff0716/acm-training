#include <bits/stdc++.h>
using namespace std;
int dist[110][110];
int num[110][110];
long long cnt[110][110];
double ans[110];
const int INF=0x3f3f3f3f;
int main()
{
	int n,m;
	cin>>n>>m;
	memset(cnt,0,sizeof(cnt));
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cnt[a][b]=1;
		cnt[b][a]=1;
		dist[a][b]=c;
		dist[b][a]=c;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][k]!=INF&&dist[k][j]!=INF)
				{
					if(dist[i][j]>dist[i][k]+dist[k][j])
					{
						dist[i][j]=dist[i][k]+dist[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dist[i][j]==dist[i][k]+dist[k][j])
					{
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
			}
			
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					if(dist[i][j]==dist[i][k]+dist[k][j])
					ans[k]+=(double)cnt[i][k]*cnt[k][j]/cnt[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%.3f\n",ans[i]);
		
	}
	return 0;
 } 
