#include <bits/stdc++.h>
using namespace std;
int dp[405][405];
int main()
{
	int m,t,n;
	cin>>m>>t>>n;
	for(int i=0;i<n;i++)
	{
		int money,time,v;
		cin>>money>>time>>v;
		for(int j=m;j>=money;j--)
		{
			for(int k=t;k>=time;k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-money][k-time]+v);
			}
		}
	}
	cout<<dp[m][t];
	return 0;
}
