#include <bits/stdc++.h>
using namespace std;
int dp[1010];
int arr[110][2];
int main()
{
	int t,m;
	cin>>t>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=t;j>=arr[i][0];j--)
		{
			dp[j]=max(dp[j],dp[j-arr[i][0]]+arr[i][1]);
		}
	}
	cout<<dp[t];
	return 0;
}
