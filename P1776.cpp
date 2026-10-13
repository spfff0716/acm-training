#include <bits/stdc++.h>
using namespace std;
const int N=4*1e4+10;
int dp[N];
int main()
{
	int n,sum;
	cin>>n>>sum;
	for(int i=1;i<=n;i++)
	{
		int v,w,m;
		cin>>v>>w>>m;
		int cnt=1;
		while(m>0)
		{
			int s=min(m,cnt);
			int nv=s*v;
			int nw=s*w;
			for(int j=sum;j>=nw;j--)
			{
				dp[j]=max(dp[j],dp[j-nw]+nv);
			}
			m-=cnt;
			cnt*=2;
		}
	}
	cout<<dp[sum];
	return 0;
}
