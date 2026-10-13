#include <bits/stdc++.h>
using namespace std;
bool d[110][110];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		d[a][b]=true;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				continue;
				d[i][j]=d[i][j]||(d[i][k]&&d[k][j]); 
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
			if(d[i][j]||d[j][i])
			{
				cnt++;
				if(cnt==n-1)
				ans++;
			}
		}
	 } 
	 cout<<ans;
	 return 0;
 } 
