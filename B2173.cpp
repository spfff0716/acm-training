#include <bits/stdc++.h>
using namespace std;
struct node
{
	int w;
	int val;
	int c;
};
int dp[1010];
int main()
{
	int n,v;
	cin>>n>>v;
	vector<node>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].w>>arr[i].val>>arr[i].c;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i].c;j++)
		{
			for(int k=v;k>=arr[i].w;k--)
			{
				dp[k]=max(dp[k],dp[k-arr[i].w]+arr[i].val);
			}
		}
	}
	cout<<dp[v];
	return 0;
 } 
