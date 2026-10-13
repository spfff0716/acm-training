#include <bits/stdc++.h>
using namespace std;
const int N=4*1e4;
int dp[N];
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>money(m+1);
	vector<int>val(m+1);
	vector<vector<int>>brr(m+1);
	vector<bool>vis(m+1,false);
	for(int i=1;i<=m;i++)
	{
		int v,p,q;
		cin>>v>>p>>q;
		money[i]=v;
		val[i]=p;
		if(q!=0)
		{
			brr[q].push_back(i);
			vis[i]=true;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(vis[i])
		continue;
		for(int j=n;j>=0;j-=10)
		{
			if(brr[i].size()==0)
			{
				if(j>=money[i])
				{
					dp[j]=max(dp[j],dp[j-money[i]]+money[i]*val[i]);
				}
			}
			else if(brr[i].size()==1)
			{
				int x=brr[i][0];
				if(j>=money[i])
				{
					dp[j]=max(dp[j],dp[j-money[i]]+money[i]*val[i]);
				}
				if(j>=money[i]+money[x])
				{
					dp[j]=max(dp[j],dp[j-money[i]-money[x]]+money[i]*val[i]+money[x]*val[x]);
				}
			}
			else
			{
				int x=brr[i][0];
				int y=brr[i][1];
				if(j>=money[i])
				{
					dp[j]=max(dp[j],dp[j-money[i]]+money[i]*val[i]);
				}
				if(j>=money[i]+money[x])
				{
					dp[j]=max(dp[j],dp[j-money[i]-money[x]]+money[i]*val[i]+money[x]*val[x]);
				}
				if(j>=money[i]+money[y])
				{
					dp[j]=max(dp[j],dp[j-money[i]-money[y]]+money[i]*val[i]+money[y]*val[y]);
				}
				if(j>=money[i]+money[x]+money[y])
				{
					dp[j]=max(dp[j],dp[j-money[i]-money[x]-money[y]]+money[i]*val[i]+money[x]*val[x]+money[y]*val[y]);
				}
			}
			
		}
	}
	cout<<dp[n];
	return 0;
 } 
