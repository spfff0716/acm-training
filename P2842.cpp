#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
int dp[N],arr[N]; 
int main()
{
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=arr[i];j<=w;j++)
		{
			if(dp[j-arr[i]]!=INF)
			dp[j]=min(dp[j],dp[j-arr[i]]+1);
		}
	}
	cout<<dp[w];
	return 0;
 } 
