#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>arr(m);
		for(int i=0;i<m;i++)
		{
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		if(arr[m-1]>=2*n)
		{
			cout<<0<<endl;
			continue;
		}
		vector<int>dp(n+2);
		vector<int>ndp(n+2);
		dp[0]=1;
		int idex=0;
		for(int i=1;i<=2*n;i++)
		{
			fill(ndp.begin(),ndp.end(),0);
			if(idex<m&&arr[idex]==i)
			{
				idex++;
				for(int j=0;j<=min(i,n);j++)
				{
					ndp[j+1]=(ndp[j+1]+dp[j])%mod;
				}
			}
			else
			{
				for(int j=0;j<=min(i,n);j++)
				{
					ndp[j+1]=(ndp[j+1]+dp[j])%mod;
					if(j>0)
					{
						ndp[j-1]=(ndp[j-1]+dp[j])%mod;
					}
				}
			}
			for(int i=0;i<=n;i++)
			{
				dp[i]=ndp[i];
			 } 
		}
		cout<<dp[0];
		
	}
	return 0;
}
