#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int brr[N][3],cnt[N];
int n,m;
int main()
{
	cin>>n>>m;
	int l,r;
	cin>>l;
	for(int i=1;i<m;i++)
	{
		cin>>r;
		if(l<r)
		{
			cnt[l]++;
			cnt[r]--;
		}
		else
		{
			cnt[r]++;
			cnt[l]--;
		}
		l=r;
	}
	for(int i=1;i<n;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	for(int i=1;i<n;i++)
	{
		cin>>brr[i][0]>>brr[i][1]>>brr[i][2];
	}
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		long long no=1ll*brr[i][0]*cnt[i];
		long long yes=1ll*brr[i][1]*cnt[i]+brr[i][2];
		ans+=min(no,yes);
	}
	cout<<ans;
	return 0;
 } 
