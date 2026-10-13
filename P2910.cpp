#include <bits/stdc++.h>
using namespace std;
int dist[110][110];

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>arr(m);
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>dist[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<m-1;i++)
	{
		int u=arr[i];
		int v=arr[i+1];
		ans+=dist[u][v];
	}
	cout<<ans;
	return 0;
}
