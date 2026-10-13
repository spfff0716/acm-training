#include <bits/stdc++.h>
using namespace std;
const int N=2*1e4+5;
int dp[N][2];
int arr[N][2];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	dp[0][0]=arr[0][1]-1+arr[0][1]-arr[0][0];
	dp[0][1]=arr[0][1]-1;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+abs(arr[i-1][0]-arr[i][1]),dp[i-1][1]+abs(arr[i-1][1]-arr[i][1]))+arr[i][1]-arr[i][0]+1;
		dp[i][1]=min(dp[i-1][0]+abs(arr[i-1][0]-arr[i][0]),dp[i-1][1]+abs(arr[i-1][1]-arr[i][0]))+arr[i][1]-arr[i][0]+1;
	}
	int res=min(dp[n-1][0]+abs(n-arr[n-1][0]),dp[n-1][1]+abs(n-arr[n-1][1]));
	cout<<res;
	return 0;
}
