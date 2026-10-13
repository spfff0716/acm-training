#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long arr[N];
long long dp[N];
const long long INF=-0x3f3f3f3f3f3f3f3f;

int main()
{
	int n,l,r;
	cin>>n>>l>>r;
	for(int i=0;i<=n+1;i++)
	{
		dp[i]=INF;
	}
	for(int i=0;i<=n;i++)
	{
		cin>>arr[i];
	}
	dp[0]=arr[0];
	deque<int>q;
	for(int i=1;i<=n;i++)
	{
		if(i<l)
		continue;
		while(!q.empty()&&dp[i-l]>=dp[q.back()])
		q.pop_back();
		q.push_back(i-l);
		if(i>r)
		{
			while(!q.empty()&&q.front()<i-r)
			q.pop_front();
		}
		if(dp[q.front()]==INF)
		{
			continue;
		}
		else
		{
			dp[i]=dp[q.front()]+arr[i]; 
		}
	}
	long long ans=dp[n];
	for(int i=n-r+1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
