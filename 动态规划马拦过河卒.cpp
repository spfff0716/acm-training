#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,hx,hy;
	cin>>n>>m>>hx>>hy;
	vector<vector<int>>block(n+1,vector<int>(m+1,1));
	block[hx][hy]=0;
	int horse[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
	for(int i=0;i<8;i++)
	{
		int dx=hx+horse[i][0];
		int dy=hy+horse[i][1];
		if(dx>=0&&dx<=n&&dy>=0&&dy<=m)
		block[dx][dy]=0;
	}
	vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(block[i][0])
		dp[i][0]=dp[i-1][0];
	}
	for(int i=1;i<=m;i++)
	{
		if(block[0][i])
		dp[0][i]=dp[0][i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(block[i][j])
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n][m];
	return 0;
	
 } 
