#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
const int N=5*1e3+10;;
long long cnt[N];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}
	long long ans=0;
	for(int i=1;i<=N-5;i++)
	{
		long long sum=0;
		if(cnt[i]==0)
		continue;
		else
		{
			for(int j=1;j<=i/2;j++)
			{
				if(cnt[j]==0||cnt[i-j]==0)
				continue;
				else
				{
					if(j==i-j)
					{
						sum=cnt[j]*(cnt[j]-1)/2*(cnt[i]*(cnt[i]-1)/2)%mod;
						ans=(ans+sum)%mod;
					}
					else
					{
						sum=cnt[j]*cnt[i-j]*(cnt[i]*(cnt[i]-1)/2)%mod;
						ans=(ans+sum)%mod;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
