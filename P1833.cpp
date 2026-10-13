#include <bits/stdc++.h>
using namespace std;
int dp[1010];
int main()
{
	int h1,m1;
	char c;
	
	cin>>h1>>c>>m1;
	int h2,m2;
	cin>>h2>>c>>m2;
	int sum=(h2-h1)*60+(m2-m1);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t,c,p;
		cin>>t>>c>>p;
		if(p==0)
		{
			for(int j=t;j<=sum;j++)
			{
				dp[j]=max(dp[j],dp[j-t]+c);
			}
		}
		else
		{
			int cnt=1;
			while(p>0)
			{
				int s=min(p,cnt);
				int nt=t*s;
				int nc=c*s;
				for(int j=sum;j>=nt;j--)
				{
					dp[j]=max(dp[j],dp[j-nt]+nc);
				}
				p-=cnt;
				cnt*=2;
			}
		}
	}
	cout<<dp[sum];
	return 0;
}
