#include <bits/stdc++.h>
using namespace std;
const int mod=1e6+7;
const int N=105;
int dp[105];
int arr[105];
int main()
{
	int n,m;
	cin>>n>>m; 
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>0;j--)
		{
			for(int k=1;k<=j&&k<=arr[i];k++)
			{
				dp[j]=(dp[j]+dp[j-k])%mod;
			}
		}
	}
	cout<<dp[m];
	return 0;
	
 } 
