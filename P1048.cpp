#include <bits/stdc++.h>
using namespace std;
int main()
{
	int time,n;
	cin>>time>>n;
	vector<int>dp(time+1,0);
	int t,p;
	for(int i=0;i<n;i++)
	{
		cin>>t>>p;
		for(int j=time;j>=t;j--)
		{
			dp[j]=max(dp[j],dp[j-t]+p);
		}
	}
	cout<<dp[time];
	return 0;
}
