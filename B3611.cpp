#include <bits/stdc++.h>
using namespace std;
bool dist[110][110];
int main()
{
	memset(dist,false,sizeof(dist));
	int n;
	cin>>n;
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
				dist[i][j]=dist[i][j]||(dist[i][k]&&dist[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dist[i][j])
			cout<<1;
			else
			cout<<0;
			cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
