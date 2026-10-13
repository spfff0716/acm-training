#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
const int N=341799+5;
long long dp[N];
int up[4][2]={{0,0},{1,0},{0,1},{1,1}};
int down[4][2]={{0,0},{1,0},{0,1},{1,1}};
int main()
{
	dp[1]=26;
	dp[2]=21*5*2+21*21;
	for(int i=3;i<=341799;i++)
	{
		dp[i]=(dp[i-1]*21+dp[i-2]*5*21)%mod;
	}
	long long ans=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int cnt1=341799;
			int cnt2=341799;
			int cnt3=341799;
			long long sum=1;
			if(up[i][0]==0)
			sum*=21%mod;
			else
			{
				sum=sum*5%mod;
				sum=sum*21*21%mod;
				cnt1--;
				cnt2--;
			}
			if(down[j][0]==0)
			sum*=21;
			else
			{
				sum=sum*5%mod;
				sum=sum*21*21%mod;
				cnt1--;
				cnt2--;
			}
			if(up[i][1]==0)
			sum*=21%mod;
			else
			{
				sum=sum*5%mod;
				cnt3--;
				sum=sum*21%mod;
				if(up[i][0]==0)
				{
					cnt2--;
					sum=sum*21%mod; 
				}
			}
			if(down[j][1]==0)
			sum*=21;
			else
			{
				sum=sum*5%mod;
				cnt3--;
				sum=sum*21%mod;
				if(down[j][0]==0)
				{
					cnt2--;
					sum=sum*21%mod; 
				}
			}
			sum=sum*dp[cnt1]%mod;
			sum=sum*dp[cnt2]%mod;
			sum=sum*dp[cnt3]%mod;
			ans=(sum+ans)%mod;
		}
	}
	cout<<ans;
	return 0;
 }
