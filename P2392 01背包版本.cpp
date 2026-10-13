#include <bits/stdc++.h>
using namespace std;
int res(int n)
{
	
	vector<int>time(n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>time[i];
		sum+=time[i];
	}
	if(n==1)
	return time[0];
	vector<bool>dp(sum,false);
	dp[0]=true;
	for(int i=0;i<n;i++)
	{
		for(int j=sum/2;j>=time[i];j--)
		{
			if(dp[j-time[i]])
			dp[j]=true;
		}
	}
	for(int j=sum/2;j>0;j--)
	{
		if(dp[j])
		return max(j,sum-j);
		}	
	
	
}
int main()
{
	int s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int ans=res(s1)+res(s2)+res(s3)+res(s4);
	cout<<ans;
	return 0;
 } 
