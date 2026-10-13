#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long arr[N][2],pre1[N],pre2[N],brr[N][2];
int n,m;
long long s;
long long check(long long mid)
{
	for(int i=1;i<=n;i++)
	{
		long long w=arr[i][0];
		long long v=arr[i][1];
		if(w>=mid)
		{
			pre1[i]=pre1[i-1]+1;
			pre2[i]=pre2[i-1]+v;
		}
		else
		{
			pre1[i]=pre1[i-1];
			pre2[i]=pre2[i-1];
		}
	}
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		int l=brr[i][0];
		int r=brr[i][1];
		sum+=(pre1[r]-pre1[l-1])*(pre2[r]-pre2[l-1]);
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>brr[i][0]>>brr[i][1];
	}
	long long l=0;
	long long r=1e6+10;
	long long ans=0x3f3f3f3f3f3f3f3f;
	while(l<=r)
	{
		long long mid=l+(r-l)/2;
		long long y=check(mid);
		ans=min(ans,abs(y-s));
		if(y==s)
		{
			cout<<0;
			return 0;
		}
		else if(y<s)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
